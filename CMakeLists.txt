cmake_minimum_required(VERSION 2.8)
project(frc_ascent)

include(FRCDeploy.cmake)

find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(frc_code ${SOURCE_CODE})
target_link_libraries(frc_code ${WPILib_LIBRARY})

add_make_deploy(frc_code 10.44.13.2)
