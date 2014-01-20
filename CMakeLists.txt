cmake_minimum_required(VERSION 2.8)

set(NAME frc_robot_2014)
set(ROBOT_IP 10.44.13.2)

project(${NAME})

find_package(WPILib)
include_directories(${WPILib_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE_CODE src/*.cpp src/*.h)

add_executable(${NAME}.out ${SOURCE_CODE})
target_link_libraries(${NAME}.out ${WPILib_LIBRARY})

macro(add_make_deploy TGT IP)
	set(DEPLOY_PATH /ni-rt/system/FRC_UserProgram.out)
	add_custom_command(OUTPUT deploy_stamp
		COMMAND wput -u "${TGT}" ftp://anonymous@${IP}${DEPLOY_PATH}
		DEPENDS ${TGT}
	VERBATIM)
	set_source_files_properties(deploy_stamp PROPERTIES SYMBOLIC true)
	add_custom_target(deploy DEPENDS deploy_stamp)
endmacro(add_make_deploy)

macro(add_make_hotreload TGT)
    add_custom_command(OUTPUT hotreload_stamp
        COMMAND echo "HOTRELOADING CODE"
        COMMAND echo "alf_reload" | netconsole_sender
        DEPENDS ${TGT}
        VERBATIM)
    add_custom_target(hotreload DEPENDS hotreload_stamp)
endmacro(add_make_hotreload)

add_make_deploy(${NAME}.out ${ROBOT_IP})
add_make_hotreload(${NAME}.out)
