GGRobotics Team 4413 Robot code C++
===================================

## Description ##
Robot code for the 2013 FRC Ascent robotics competition. Written in C++ and
compiled with the [FRC C++11 cross-compiling toolchain](http://firstforge.wpi.edu/sf/projects/c--11_toochain).

## Dev Environment Setup ##

### Linux ###

Add the frc-c++11 repository.

        sudo echo 'deb http://debian.repo.frc.s3.amazonaws.com wheezy main' >> /etc/apt/sources.list

Add the maintainer key for the repository.

        wget -O - http://debian.repo.frc.s3.amazonaws.com/rbmj.gpg.key | sudo apt-key add -

Install the frc-c++11 packages.

        sudo apt-get update
        sudo apt-get install cmake gcc-powerpc-wrs-vxworks frc-buildscripts wpilib

Add WIND_BASE to your bash config.

        echo 'export WIND_BASE=/usr/powerpc-wrs-vxworks/wind_base' >> ~/.bashrc
        source ~/.bashrc


### Windows ###
[Windows Installation](http://firstforge.wpi.edu/sf/wiki/do/viewPage/projects.c--11_toochain/wiki/BinaryInstall)


## Build ##

### Pre-build steps ###

You only need to do this once!

Start in the base repository directory. Create the build directory and build
the CMake build files.

        mkdir ./build
        cd ./build
        frcmake ../

### Building the code ###

Whenever you want to build the robot code, change to the build directory.

        cd ./build

Then run make.

        make

### Deploy to robot ###

Make sure you're connected to the robot with a manually set ip of 10.44.13.XXX
where XXX is some number between 10 and 255 (the number should be unique).

Then run the deploy script in the build directory.

        make deploy
