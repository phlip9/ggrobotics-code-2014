""" The extra configuration file for YouCompleteMe. Holds the compile flags
the clang auto-completition engine."""

import os
import os.path as path
import ycm_core

def get_wind_base():
    """$WIND_BASE environment variable.
    If $WIND_BASE isn't set, return a default of
    /usr/powerpc-wrs-vxworks/wind_base"""

    wind_base = os.getenv('WIND_BASE')
    if wind_base:
        return path.abspath(wind_base)
    return path.abspath(path.join('/usr', 'powerpc-wrs-vxworks', 'wind_base'))

WIND_BASE = get_wind_base()
SYS_INCLUDE_DIR = path.join(WIND_BASE, 'target', 'h')

# Current directory of the script (.ycm_extra_conf.py)
SCRIPT_DIR = path.dirname(path.abspath(__file__))

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
    SYS_INCLUDE_DIR,
    '-isystem',
    path.join(SYS_INCLUDE_DIR, 'wrn', 'coreip'),
    # Source includes
    ## WPILib headers
    '-I',
    path.join(SYS_INCLUDE_DIR, 'wrn', 'coreip', 'WPILib'),
    ## Project headers
    '-I',
    SCRIPT_DIR
]

def FlagsForFile(filename):
    """Return the compile flags for the current file.
    Used by the YouCompleteMe autocompletion engine's clang completer."""
    return {
        'flags': FLAGS,
        'do_cache': True
    }
