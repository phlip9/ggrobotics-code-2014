GGRobotics Team 4413 Robot code C++
===================================

## Description ##
Robot code for the 2014 FIRST Arial Assist Robotics Competition. Written in C++ and
compiled with the [FRC C++11 cross-compiling toolchain](http://firstforge.wpi.edu/sf/projects/c--11_toochain).


## Dev Environment Setup ##

Detailed instrucitons on the
[toolchain repository wiki](http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/ManualInstall).


## Linux ##

### Binary Install ####

Add the frc-c++11 repository.

    $ echo "deb http://debian.repo.frc.s3.amazonaws.com jessie main" | sudo tee -a /etc/apt/sources.list

Add the maintainer key for the repository.

    $ wget -O - http://debian.repo.frc.s3.amazonaws.com/rbmj.gpg.key | sudo apt-key add -

Install the frc-c++11 packages.

    $ sudo apt-get update
    $ sudo apt-get install cmake gcc-powerpc-wrs-vxworks frc-buildscripts wpilib

Add WIND_BASE to your bash config.

    $ echo "export WIND_BASE=/usr/powerpc-wrs-vxworks/wind_base" >> ~/.bashrc
    $ source ~/.bashrc


### Manual Install (get the latest, bleeding-edge toolchain version) ###

Install the essential build scripts.

    $ sudo apt-get install debhelper devscripts binutils-dev build-essential

`git clone` each of the following repositories.

    $ git clone https://github.com/rbmj/wrs-headers-installer
    $ git clone https://github.com/rbmj/ppc-vxworks-binutils
    $ git clone https://github.com/rbmj/ppc-vxworks-gcc
    $ git clone https://github.com/rbmj/frc-buildscripts
    $ git clone https://github.com/rbmj/wpilib

`cd` into each repository you just `git clone`ed, run the following (in the
order that you cloned them).

    $ cd <repo>
    $ ./debmake
    $ sudo dpkg -i build/*.deb
    $ cd ..

*Note:* Building the toolchain takes a good 30 minutes (compiling GCC takes a while).


## Windows ##
[Windows Installation](http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/BinaryInstall)


## Build and Deploy ##

Building and deploying the code involves first compiling it with the frc-c++11
toolchain, which generates an frc_robot_2014.out file. This file then gets
ftp'd over to the robot, which then gets reloaded on the next reboot.

### Pre-build steps ###

You only need to do this once!

Start in the base repository directory. Create the build directory and build
the CMake build files.

    $ mkdir ./build
    $ cd ./build
    $ frcmake ../

### Building the code ###

Whenever you want to build the robot code, change to the build directory.

    $ cd ./build

Then run make.

    $ make

If there are any new files or you edit CMakeLists.txt, you need to regenerate
the CMake build files.

    $ cd ./build
    $ rm -rf *
    $ frcmake ..

### Deploy to robot ###

Make sure you're connected to the robot with a manually set ip of 10.XX.YY.ZZ

Where XXYY is your team number (0s included), e.g., 4413 would be 10.44.13.ZZ
and 580 would be 10.5.80.ZZ, where ZZ is some number between 10 and 255
(the number should be unique and not shared by any other computers on the network).

Then run the deploy script in the build directory.

    $ make deploy

Next, you need to reboot the robot so it can load the new code (You can do
this from the driver station or with the
[netconsole](http://github.com/phlip9/netconsole)).

    $ echo "reboot" | netconsole_sender

### Debugging

Watch for errors and log statments on the netconsole_receiver.

    $ netconsole_receiver

Send commands over the vxWorks shell with the netconsole_sender.

    $ netconsole_sender
    --> help
    --> reboot

Alternatively, if you need to get down and dirty with gdb, follow this guide:
http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/GDB


## Code Structure

- src/
    + Robot
        - Inherits from Iterative Robot
        - Entry point of the program
        - Controls the lifecycle of the robot (init, disabled, teleop, autonomous)
        - Container for the robot subsystems, hardware mappings, operator
          interfaces, etc...
    + HardwareMap
        - Maps the physical hardware to software objects
        - Contains all the motors, solenoids, gyros, etc...
        - Adds hardware objects the the LiveWindow
    + OI
        - Operator Interface
        - Holds all the joysticks, joystick buttons, and digital input buttons
        - Maps user input to respective commands, e.g., when user releases
          the button, launch the ball.
    + Config
        - Holds all the constants and smart dashboard preferences in a
          centralized location.
        - Should contain all the joystick ports, button numbers, motor
          channels, solenoid inputs, etc...
        - Functions that wrap the Preferences object should go here too.
        - Preferences are constants that are displayed and can be changed in
          the SmartDashboard on the driver station.
    + Logging
        - Pre-processor logging helper macros
        - Each logging macro prints the current level (ERROR, WARN, DEBUG, INFO),
          the current file, line, column, and message.
        - Logging levels can also be disabled by commenting out the defines
          at the top of file (because they are pre-processor macros, they get
          totally removed from the end program and thus have no overhead).
    + Commands/
        - AutonomousDrive
            + Drive forward for m_seconds at m_power
        - BackgroundDrive
            + Runs in the background of the Drive subsystem
            + Polls input from the joystick and passes it to the drive subsystem
        - FrontArmMove
            + Moves the front arm at some power
        - LaunchSolenoids
            + Opens/closes the ball launcher solenoids
        - Shoot
            + Shoots the ball and then resets the launch solenoids
        - WheelMotorSpin
            + Spins the grabber wheels
    + Subsystems/
        - Drive
            + Controls the driving of the robot
            + Runs the BackgroundDrive command when no other commands are running.
        - MotorSubsystem
            + Generic motor controller subsystem
            + Fx. Front arm, wheel motors
            + Takes a speed controller, forward power, and reverse power.
        - ShooterSubsystem
            + Controls the ball shooter
