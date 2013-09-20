cmake_minimum_required(VERSION 2.8)
include(FRCDeploy)

project(frc_ascent)
find_package(WPILib)
include-directories(${WPILib_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE_CODE *.cpp)

add_executable(frc_code ${SOURCE_CODE})
target_link_libraries(frc_code ${WPILib_LIBRARY})

add_make_deploy(frc_code 10.5.80.2)
