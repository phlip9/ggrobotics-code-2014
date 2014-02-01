GGRobotics Team 4413 Robot code C++
===================================

## Description ##
Robot code for the 2013 FRC Ascent robotics competition. Written in C++ and
compiled with the [FRC C++11 cross-compiling toolchain](http://firstforge.wpi.edu/sf/projects/c--11_toochain).


## Dev Environment Setup ##

Detailed instrucitons on the
[toolchain repository wiki](http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/ManualInstall).


## Linux ##

### Binary Install ####

Add the frc-c++11 repository.

        $ sudo echo 'deb http://debian.repo.frc.s3.amazonaws.com jessie main' >> /etc/apt/sources.list

Add the maintainer key for the repository.

        $ wget -O - http://debian.repo.frc.s3.amazonaws.com/rbmj.gpg.key | sudo apt-key add -

Install the frc-c++11 packages.

        $ sudo apt-get update
        $ sudo apt-get install cmake gcc-powerpc-wrs-vxworks frc-buildscripts wpilib

Add WIND_BASE to your bash config.

        $ echo 'export WIND_BASE=/usr/powerpc-wrs-vxworks/wind_base' >> ~/.bashrc
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

*Note:* Building the toolchain takes a good 30 minutes (compiling GCC takes
for ever...).


## Windows ##
[Windows Installation](http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/BinaryInstall)


## Build ##

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

If there are any new or you edit CMakeLists.txt, you need to regeenerate the
cmake build files.

        $ cd ./build
        $ rm -rf *
        $ frcmake ..

### Deploy to robot ###

Make sure you're connected to the robot with a manually set ip of 10.44.13.XXX
where XXX is some number between 10 and 255 (the number should be unique).

Then run the deploy script in the build directory.

        $ make deploy

Next, you need to reboot the robot so it can load the new code.

        $ echo "reboot" | netconsole_sender
