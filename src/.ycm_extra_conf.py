import os
import ycm_core

def get_wind_base():
    wind_base = os.getenv('WIND_BASE')
    if wind_base:
        return wind_base
    return "/usr/powerpc-wrs-vxworks"

WIND_BASE = get_wind_base()

# These are the compilation flags that will be used in case there's no
# compilation database set (by default, one is not set).
# CHANGE THIS LIST OF FLAGS. YES, THIS IS THE DROID YOU HAVE BEEN LOOKING FOR.
FLAGS = [
    '-mstrict-align',
    '-nostdlib',
    '-Wall',
    '-Wextra',
    '-Werror',
    '-fexceptions',
    '-DCPU=PPC603',
    '-DTOOL_FAMILY=gnu',
    '-DTOOL=gnu',
    '-D_WRS_KERNEL',
    '-DNDEBUG',
    '-DUSE_CLANG_COMPLETER',
    # THIS IS IMPORTANT! Without a "-std=<something>" flag, clang won't know
    # which language to use when compiling headers. So it will guess. Badly. So
    # C++ headers will be compiled as C headers. You don't want that so ALWAYS
    # specify a "-std=<something>".
    # For a C project, you would set this to something like 'c99' instead of
    # 'c++11'.
    '-std=c++11',
    # ...and the same thing goes for the magic -x option which specifies the
    # language that the files to be compiled are written in. This is mostly
    # relevant for c++ headers.
    # For a C project, you would set this to 'c' instead of 'c++'.
    '-x',
    'c++',
    # System includes
    '-isystem',
    WIND_BASE + '/target/h',
    '-isystem',
    WIND_BASE + '/target/h/wrn/coreip',
    # Source includes
    ## WPILib headers
    '-I',
    WIND_BASE + '/target/h/wrn/coreip/WPILib/',
    ## Project headers
    '-I',
    '.'
]

def script_dir():
    """Returns the absolute path of the script directory."""
    return os.path.dirname(os.path.abspath(__file__))


def make_flags_absolute(flags, working_directory):
    """Makes relative path names in the compile flags absolute paths."""
    if not working_directory:
        return list(flags)

    new_flags = []
    make_next_absolute = False
    path_flags = ['-isystem', '-I', '-iquote', '--sysroot=']

    for flag in flags:
        new_flag = flag

        if make_next_absolute:
            make_next_absolute = False
            if not flag.startswith('/'):
                new_flag = os.path.join(working_directory, flag)

        for path_flag in path_flags:
            if flag == path_flag:
                make_next_absolute = True
                break

            if flag.startswith(path_flag):
                path = flag[ len(path_flag):]
                new_flag = path_flag + os.path.join(working_directory, path)
                break

        if new_flag:
            new_flags.append(new_flag)

    return new_flags


def FlagsForFile(filename):
    relative_to = script_dir()
    final_flags = make_flags_absolute(FLAGS, relative_to)

    return {
        'flags': final_flags,
        'do_cache': True
    }
