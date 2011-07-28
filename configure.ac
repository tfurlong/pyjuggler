# PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling
# Distributed under the GNU Lesser General Public License 2.1.  (See
# accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

AC_INIT([PyJuggler], [1.3], [vrjuggler-devel@lists.sourceforge.net])
AC_PREREQ([2.53])
AC_COPYRIGHT([PyJuggler is (C) Copyright 2002-2011 by Patrick Hartling])
AC_REVISION([$Revision$])
AC_CONFIG_SRCDIR([src/gadgeteer-wrappers.h])
AC_CONFIG_AUX_DIR([dpp/scripts])
DPP_PREREQ([1.5.1])
DPP_INIT

# -----------------------------------------------------------------------------
# Command-line arguments (--enable-option, --with-pkg=package_name).
# -----------------------------------------------------------------------------

# ------------------------------------------------------ #
# --enable-feature[=arg] and --disable-feature arguments #
# ------------------------------------------------------ #

DPP_STD_CPP([yes])

# -------------------------------------------- #
# --with-pkg[=arg] and --without-pkg arguments #
# -------------------------------------------- #

AC_ARG_WITH([python],
            [  --with-python=<PATH>    Path to Python root             [default=/usr/local]],
            [PYTHON_ROOT="$withval"], [PYTHON_ROOT='/usr/local'])

AC_ARG_WITH([boost-python],
            [  --with-boost-python=<PATH>
                          Path to a Boost.Python V2
                          installation                    [default=/usr/local]],
            [BOOST_PYTHON_DIR="$withval"], [BOOST_PYTHON_DIR='/usr/local'])

AC_ARG_WITH([boost-python-lib],
            [  --with-boost-python-lib=<LIB NAME>
                          The name of the Boost.Python
                          library binary for linking      [default=Auto-detect]],
            [bp_libname="$withval"], [bp_libname=''])

AC_ARG_WITH([boost-version],
            [  --with-boost-version=<VER>
                          Boost version number (for
                          example, 1.32)                  [default=1.32]],
            [BOOST_VERSION="$withval"], [BOOST_VERSION='1.32'])

AC_ARG_WITH([pyste],
            [  --with-pyste=<PATH>     Full path to pyste.py script    [No default]],
            [PYSTE="$withval"], [PYSTE='pyste.py'])

AC_ARG_WITH([osg],
            [  --with-osg=<PATH>       Open Scene Graph installation   [default=$OSGHOME then /usr/local]],
            [osg_base_dir="$withval"], [osg_base_dir=${OSGHOME-/usr/local}])

AC_ARG_WITH([opensg],
            [  --with-opensg=<PATH>    OpenSG installation             [default=$OSGROOT then /usr/local]],
            [opensg_base_dir="$withval"],
            [opensg_base_dir=${OSGROOT-/usr/local}])

# Force the use of GCC as the compiler.
# NOTE: This is not fully implemented yet for any platform, but it is partially
# usable on Windows.
DPP_WITH_GCC(no)

# Define the binary format.
DPP_ABI_SETUP

# -----------------------------------------------------------------------------
# System-dependent stuff.
# -----------------------------------------------------------------------------

# We use AC_CANONICAL SYSTEM so that we can find out information about the
# build, target and host platforms rather than only the host.
AC_CANONICAL_SYSTEM
DPP_SYSTEM_SETUP

# -----------------------------------------------------------------------------
# Checks for programs.
# -----------------------------------------------------------------------------
VJ_COMPILER_SETUP

DPP_CC_PTHREAD_ARG

if test "x$CC_ACCEPTS_PTHREAD" = "xno" ; then
   DPP_CC_PTHREADS_ARG
fi

# Ensure that a version of Perl greater than or equal to 5.004 is available.
DPP_HAVE_PERL5( , , [AC_MSG_ERROR([*** Perl is required ***])])
DPP_HAVE_GNU_MAKE([3.78], ,
    [AC_MSG_ERROR([*** The build system requires GNU make 3.78 or newer ***])])
DPP_BASIC_PROGS([$PLATFORM], [$OS_TYPE])
DPP_PROG_INSTALL

python_path="$PYTHON_ROOT/bin:$PATH"

USE_OBJCOPY='no'
if test "x$GXX" = "xyes" ; then
   AC_PATH_PROG(OBJCOPY, objcopy, no)

   if test "x$OBJCOPY" != "xno" ; then
      USE_OBJCOPY='yes'
   fi
fi

AC_PATH_PROG(PYTHON, python, no, [$python_path])

if test "x$PYTHON" = "xno" ; then
   AC_MSG_ERROR([*** Python is required for building PyJuggler ***])
fi

# Determine if the detected Python installation directory matches the input
# from --with-python.  If not, use the detected installation directory.
found_python_root=`$PYTHON -c "import distutils.sysconfig; print distutils.sysconfig.get_config_var('prefix')"`

if test "x$PYTHON_ROOT" != "x$found_python_root" ; then
   PYTHON_ROOT="$found_python_root"
fi

AC_CHECK_FILE([$PYSTE], , [AC_MSG_WARN([*** pyste.py does not exist ***])])

AC_MSG_CHECKING([for Python version])
changequote(<<, >>)
PYTHON_VERSION=`$PYTHON -c "import sys; print sys.version[:3]"`
changequote([, ])
AC_MSG_RESULT([$PYTHON_VERSION])

AC_MSG_CHECKING([for suffix of Python extension modules])
changequote(<<, >>)

PYMOD_EXT=`$PYTHON -c "import distutils.sysconfig; print distutils.sysconfig.get_config_var('SO')"`

# This is a fallback in case Python fails to tell us the file extension it
# prefers.
if test "x" = "x$PYMOD_EXT"; then
   PYMOD_EXT=".$DYNAMICLIB_EXT"
fi

changequote([, ])
AC_MSG_RESULT([$PYMOD_EXT])

# -----------------------------------------------------------------------------
# Checks for libraries.
# -----------------------------------------------------------------------------

DPP_GET_PTHREAD_LIB

# We do this first so that we can pass the $DL_LOAD_LIB in as a dependency of
# Python.
_pyj_save_LIBS="$LIBS"
AC_CHECK_FUNC([dlopen], [DL_LOAD_LIB=''],
    [AC_CHECK_LIB([dl], [dlopen], [DL_LOAD_LIB='-ldl'])])
LIBS="${_pyj_save_LIBS}"

_pyj_save_LIBS="$LIBS"
AC_CHECK_FUNC([openpty], [UTIL_LIB=''],
    [AC_CHECK_LIB([util], [openpty], [UTIL_LIB='-lutil'])])
LIBS="${_pyj_save_LIBS}"

python_incdir=`$PYTHON -c "import distutils.sysconfig; print distutils.sysconfig.get_config_var('INCLUDEDIR')"`
PYTHON_INCLUDES="-I$python_incdir/python$PYTHON_VERSION"

if test "x$PLATFORM" = "xDarwin" ; then
   PYTHON_LDFLAGS=''
   PYTHON_LIB=''
else
   PYTHON_LDFLAGS="-L$PYTHON_ROOT/lib/python$PYTHON_VERSION/config"
   PYTHON_LIB="python$PYTHON_VERSION"
fi

_pyj_save_CPPFLAGS="$CPPFLAGS"
_pyj_save_LIBS="$LIBS"
_pyj_save_LDFLAGS="$LDFLAGS"

CPPFLAGS="$CPPFLAGS $PYTHON_INCLUDES"
PYTHON_LIB_DEPS="$PTHREAD_ARG $DL_LOAD_LIB $PTHREAD_LIB"

if test "x$OS_TYPE" = "xUNIX" ; then
   PYTHON_LIB_DEPS="$PYTHON_LIB_DEPS -lm"
fi

LDFLAGS="$LDFLAGS $PYTHON_LDFLAGS"

DPP_LANG_SAVE
DPP_LANG_C

if test "x$PLATFORM" = "xDarwin" ; then
   LDFLAGS="$LDFLAGS -framework Python"

   AC_CACHE_CHECK([for Py_Initialize in Python framework],
      [pyj_cv_have_python_framework],
      [AC_TRY_LINK([#include <Python.h>],
                   [Py_Initialize();],
                   [pyj_cv_have_python_framework='yes'],
                   [pyj_cv_have_python_framework='no'])])

   if test "x$pyj_cv_have_python_framework" = "xno" ; then
      AC_MSG_ERROR([*** Python is required for PyJuggler ***])
   fi
else
   AC_CHECK_LIB([$PYTHON_LIB], [Py_Initialize],
      [AC_CHECK_HEADER([Python.h], ,
         [AC_MSG_ERROR([*** Python is required for PyJuggler ***])])],
      [AC_MSG_ERROR([*** Python is required for PyJuggler ***])],
      [$UTIL_LIB $PYTHON_LIB_DEPS])
fi

DPP_LANG_RESTORE

# Convert the string given to AC_CHECK_LIB() as a library to something that
# the linker can use later on.
if test "x$PLATFORM" = "xDarwin" ; then
   PYTHON_LIB="-framework Python"
   PYTHON_LIB_OPT="$PYTHON_LIB"
   PYTHON_LIB_DBG="$PYTHON_LIB_OPT"
else
   PYTHON_LIB="-l$PYTHON_LIB"
   PYTHON_LIB_OPT="$PYTHON_LIB"
   PYTHON_LIB_DBG="$PYTHON_LIB_OPT"
fi

boost_ver_exp=`echo $BOOST_VERSION | sed -e 's/\./ /g'`
boost_major_ver=`echo $boost_ver_exp | awk '{ print $1 }' -`
boost_minor_ver=`echo $boost_ver_exp | awk '{ print $2 }' -`

if test "x$bp_libname" = "x" ; then
   if test $boost_minor_ver -ge 31; then
      boost_debug_suffix='-d'
   else
      boost_debug_suffix='_debug'
   fi
fi

boost_ver_str=`echo $BOOST_VERSION | sed -e 's/\./_/g'`

DPP_LANG_SAVE
DPP_LANG_CPLUSPLUS

_pyj_save_CPPFLAGS="$CPPFLAGS"

bp_inc_opt="-I$BOOST_PYTHON_DIR/include"
CPPFLAGS="$bp_inc_opt $CPPFLAGS"

AC_CHECK_HEADER([boost/python.hpp],
                [BOOST_PYTHON_HEADER_DIR="$BOOST_PYTHON_DIR/include"],
                [CPPFLAGS="$CPPFLAGS $bp_inc_opt/boost-$boost_ver_str"
                 AC_CHECK_HEADER([boost-$boost_ver_str/boost/python.hpp],
                                 [BOOST_PYTHON_HEADER_DIR="$BOOST_PYTHON_DIR/include/boost-$boost_ver_str"],
                                 [AC_MSG_ERROR([*** Boost.Python v2 is required for PyJuggler ***])])
                ])

BOOST_PYTHON_INCLUDE_OPTS="-I$BOOST_PYTHON_HEADER_DIR"

CPPFLAGS="${_pyj_save_CPPFLAGS}"

DPP_LANG_RESTORE

boost_version_hpp="$BOOST_PYTHON_HEADER_DIR/boost/version.hpp"

# Determine the version number of the Boost installation we found and ensure
# that it is recent enough.
changequote(<<, >>)
boost_version_num=`grep 'define BOOST_VERSION ' "$boost_version_hpp" | sed -e 's/^[^0-9]*\([0-9][0-9]*\)[^0-9]*$/\1/'`
changequote([, ])
pyj_boost_patch=`expr $boost_version_num % 100`
pyj_boost_minor=`expr $boost_version_num / 100 % 1000`
pyj_boost_major=`expr $boost_version_num / 100000`
pyj_boost_version="$pyj_boost_major.$pyj_boost_minor.$pyj_boost_patch"

req_boost_version='1.32.0'
DPP_VERSION_CHECK_MSG_NO_CACHE([Boost], [$pyj_boost_version],
                               [$req_boost_version], ,
                               [AC_MSG_ERROR([*** Boost $req_boost_version is required for PyJuggler ***])])

if test "x$GCC" = "xyes" ; then
   split_gcc_ver=`$CXX -dumpversion | sed -e 's/\./ /g'`
   pyj_gcc_major=`echo $split_gcc_ver | awk '{ print $[1] }' -`
   pyj_gcc_minor=`echo $split_gcc_ver | awk '{ print $[2] }' -`
fi

if test "x$bp_libname" = "x" ; then
   if test $boost_minor_ver -ge 31; then
      case $CC in
         gcc)
            toolset='-gcc'
            ;;
         cygcl|msvccc|cl*|CL*)
            toolset="-${BOOST_TOOL:='vc7'}"
            ;;
         cc)
            if test "x$GCC" = "xyes" ; then
               if test $pyj_boost_minor -ge 34 ; then
                  toolset="-gcc$pyj_gcc_major$pyj_gcc_minor"
               else
                  toolset='-gcc'
               fi
            else
               case $PLATFORM in
                  IRIX)
                     toolset='-mp'
                     ;;
                  Solaris)
                     toolset='-sw'
                     ;;
               esac
            fi
            ;;
      esac

      if test "x$PLATFORM" = "xDarwin" ; then
         if test $pyj_boost_minor -ge 37 ; then
            toolset="-xgcc$pyj_gcc_major$pyj_gcc_minor"
            threading='-mt'
         else
            toolset=''
            threading=''
         fi
      else
         threading='-mt'
      fi

      BASE_BP_LIBNAME="boost_python$toolset$threading"
      BPL_VER_SUFFIX="-$boost_ver_str"
      BOOST_PYTHON_LIB="$BASE_BP_LIBNAME$BPL_VER_SUFFIX"
   else
      BASE_BP_LIBNAME="boost_python"
      BPL_VER_SUFFIX=""
      BOOST_PYTHON_LIB="$BASE_BP_LIBNAME"
   fi
else
   BASE_BP_LIBNAME="$bp_libname"
   BPL_VER_SUFFIX=""
   BOOST_PYTHON_LIB="$bp_libname"
fi

CPPFLAGS="${_pyj_save_CPPFLAGS}"
LIBS="${_pyj_save_LIBS}"
LDFLAGS="${_pyj_save_LDFLAGS}"

DPP_LANG_SAVE
DPP_LANG_CPLUSPLUS

bpl_link_option="-l$BOOST_PYTHON_LIB"

_pyj_save_CPPFLAGS="$CPPFLAGS"
_pyj_save_LIBS="$LIBS"
_pyj_save_LDFLAGS="$LDFLAGS"

CPPFLAGS="$CPPFLAGS $PYTHON_INCLUDES $BOOST_PYTHON_INCLUDE_OPTS"

if test "x$PLATFORM" = "xIRIX" -a "x$USE_GCC" != "xyes" ; then
   CPPFLAGS="$CPPFLAGS -I$BOOST_PYTHON_HEADER_DIR/compatibility/cpp_c_headers"
fi

if test "lib$LIBBITSUF" != "lib" ; then
   libdirs="lib$LIBBITSUF lib"
else
   libdirs='lib'
fi

LIBS="$LIBS $bpl_link_option $PYTHON_LIB $UTIL_LIB $PYTHON_LIB_DEPS"

for l in $libdirs ; do
   cur_bp_libdir="$BOOST_PYTHON_DIR/$l"
   LDFLAGS="-L$cur_bp_libdir $PYTHON_LDFLAGS ${_pyj_save_LDFLAGS}"

   AC_MSG_CHECKING([for boost::python::handle<> in $bpl_link_option in $cur_bp_libdir])
   AC_TRY_LINK([
#include <boost/python.hpp>
using namespace boost::python;],
               [handle<> main_module(borrowed(PyImport_AddModule("__main__")));],
               [pyj_have_bp='yes'
                rm -rf ./ii_files],
               [pyj_have_bp='no'])
   AC_MSG_RESULT([$pyj_have_bp])

   if test "x$pyj_have_bp" = "xyes" ; then
      BPL_LIBDIR="$cur_bp_libdir"
      break
   fi
done

DPP_LANG_RESTORE

CPPFLAGS="${_pyj_save_CPPFLAGS}"
LIBS="${_pyj_save_LIBS}"
LDFLAGS="${_pyj_save_LDFLAGS}"

if test "x$pyj_have_bp" = "xyes" ; then
   if test "x$GXX" = "xyes" ; then
      BOOST_PYTHON_CXXFLAGS="-ftemplate-depth-256"
   fi

   if test "x$PLATFORM" = "xDarwin" ; then
      BOOST_PYTHON_CXXFLAGS="$BOOST_PYTHON_CXXFLAGS -no-cpp-precomp"

      #  GCC 4.0 in Darwin removed -fcoalesce-templates.
      if test $pyj_gcc_major -lt 4 ; then
         BOOST_PYTHON_CXXFLAGS="$BOOST_PYTHON_CXXFLAGS -fcoalesce-templates"
      fi

      # Do not use -Wno-long-double with GCC 4.2.
      if test $pyj_gcc_minor -lt 2 ; then
         BOOST_PYTHON_CXXFLAGS="$BOOST_PYTHON_CXXFLAGS -Wno-long-double"
      fi
   fi

   BOOST_PYTHON_INCLUDES="$BOOST_PYTHON_INCLUDE_OPTS"

   if test "x$PLATFORM" = "xIRIX" -a "x$USE_GCC" != "xyes" ; then
      BOOST_PYTHON_INCLUDES="$BOOST_PYTHON_INCLUDES -I$BOOST_PYTHON_HEADER_DIR/compatibility/cpp_c_headers"
   fi

   bpl_ldflags="-L$BPL_LIBDIR"
   BOOST_PYTHON_LDFLAGS_OPT="$bpl_ldflags -l$BOOST_PYTHON_LIB"
   BOOST_PYTHON_LDFLAGS_DBG="$bpl_ldflags -l$BASE_BP_LIBNAME$boost_debug_suffix$BPL_VER_SUFFIX"
else
   AC_MSG_ERROR([*** Boost.Python v2 is required for PyJuggler ***])
fi

VPR_PATH([1.1.43], , [AC_MSG_ERROR([*** VPR is required for PyJuggler ***])])
JCCL_PATH_CXX([1.1.11], ,
              [AC_MSG_ERROR([*** JCCL is required for PyJuggler ***])])
SNX_PATH([1.3.6], , [AC_MSG_ERROR([*** Sonix is required for PyJuggler ***])])
GADGETEER_PATH([2.1.11], ,
               [AC_MSG_ERROR([*** Gadgeteer is required for PyJuggler ***])])
VRJUGGLER_PATH([2.3.20], ,
               [AC_MSG_ERROR([*** VR Juggler is required for PyJuggler ***])])

HAVE_OSG='N'

if test "x$osg_base_dir" != "xno" ; then
   pyjsave_CFLAGS="$CFLAGS"
   pyjsave_CPPFLAGS="$CPPFLAGS"
   pyjsave_LDFLAGS="$LDFLAGS"
   pyjsave_LIBS="$LIBS"

   # Ensure that /usr/include and /usr/lib are not included multiple times
   # if $OSGROOT is "/usr".
   if test "x$osg_base_dir" != "x/usr" ; then
      OSG_INCLUDES="-I$osg_base_dir/include"
   fi

   OSG_LIBS='-losg -losgProducer -losgUtil -losgDB -losgText -losgGA -lProducer -lOpenThreads'

   AC_PATH_X

   if test "x$x_libraries" != "xNONE" -a "x$x_libraries" != "x" ; then
      X_LDFLAGS="-L$x_libraries"
   fi

   if test "lib$LIBBITSUF" != "lib" ; then
      libdirs="lib$LIBBITSUF lib"
   else
      libdirs="lib"
   fi

   CFLAGS="$CFLAGS ${_EXTRA_FLAGS}"
   CPPFLAGS="$CPPFLAGS $OSG_INCLUDES $STDFLAGS"

   DPP_LANG_SAVE
   DPP_LANG_CPLUSPLUS

   LIBS="-lOpenThreads $LIBS"

   for l in $libdirs ; do
      cur_ot_libdir="$osg_base_dir/$l"
      LDFLAGS="-L$cur_ot_libdir $pyjsave_LDFLAGS"

      AC_MSG_CHECKING([for OpenThreads::Thread::GetConcurrency() in -lOpenThreads in $cur_ot_libdir])
      AC_TRY_LINK([#include <OpenThreads/Thread>],
                  [OpenThreads::Thread::GetConcurrency();],
                  [pyj_have_ot='yes'], [pyj_have_ot='no'])
      AC_MSG_RESULT([$pyj_have_ot])
      rm -rf ./ii_files

      if test "x$pyj_have_ot" = "xyes" ; then
         OT_LDFLAGS="-L$cur_ot_libdir"
         break
      fi
   done

   # We already have -lOpenThreads in $LIBS, so now prepend -lProducer.
   LIBS="-lProducer $LIBS"

   for l in $libdirs ; do
      cur_producer_libdir="$osg_base_dir/$l"
      LDFLAGS="-L$cur_producer_libdir $pyjsave_LDFLAGS"

      AC_MSG_CHECKING([for Producer::Timer::instance() in -lProducer in $cur_producer_libdir])
      AC_TRY_LINK([#include <Producer/Timer>], [Producer::Timer::instance();],
                  [pyj_have_producer='yes'], [pyj_have_producer='no'])
      AC_MSG_RESULT([$pyj_have_producer])
      rm -rf ./ii_files

      if test "x$pyj_have_producer" = "xyes" ; then
         PRODUCER_LDFLAGS="-L$cur_producer_libdir"
         if test "x$OT_LDFLAGS" = "x$PRODUCER_LDFLAGS" ; then
            OT_LDFLAGS=''
         fi
         break
      fi
   done

   LIBS="$pyjsave_LIBS"

   HAVE_OSG='N'

   if test "x$pyj_have_ot" = "xyes" -a "x$pyj_have_producer" = "xyes" ; then
      LIBS="$PRODUCER_LDFLAGS $OSG_LIBS $X_LDFLAGS $OT_LDFLAGS -lOpenThreads -lX11 -lXext"

      for l in $libdirs ; do
         cur_osg_libdir="$osg_base_dir/$l"
         LDFLAGS="-L$cur_osg_libdir $pyjsave_LDFLAGS"

         AC_MSG_CHECKING([for osgGetVersion in -losg in $cur_osg_libdir])
         AC_TRY_LINK([#include <osg/Version>], [osgGetVersion();],
                     [pyj_have_osg='yes'], [pyj_have_osg='no'])
         AC_MSG_RESULT([$pyj_have_osg])
         rm -rf ./ii_files

         if test "x$pyj_have_osg" = "xyes" ; then
            OSG_LDFLAGS="-L$cur_osg_libdir"
            if test "x$OSG_LDFLAGS" = "x$PRODUCER_LDFLAGS" ; then
               PRODUCER_LDFLAGS=''
            fi
            if test "x$OSG_LDFLAGS" = "x$OT_LDFLAGS" ; then
               OT_LDFLAGS=''
            fi
            break
         fi
      done

      if test "x$pyj_have_osg" = "xyes" ; then
         HAVE_OSG='Y'
      fi
   fi

   DPP_LANG_RESTORE

   CFLAGS="$pyjsave_CFLAGS"
   CPPFLAGS="$pyjsave_CPPFLAGS"
   LDFLAGS="$pyjsave_LDFLAGS"
   LIBS="$pyjsave_LIBS"
fi

HAVE_OPENSG='N'

if test "x$opensg_base_dir" != "xno" ; then
   AC_PATH_PROG(OPENSG_CONFIG, osg-config, no, [$opensg_base_dir/bin:$PATH])

   if test "x$OPENSG_CONFIG" != "xno" ; then
      opensg_pkgs='Base System'
      OPENSG_INCLUDES=`$OPENSG_CONFIG --opt --cflags $opensg_pkgs`
      OPENSG_LDFLAGS=`$OPENSG_CONFIG --opt --lflags $opensg_pkgs`
      OPENSG_LIBS=`$OPENSG_CONFIG --opt --libs $opensg_pkgs`
      HAVE_OPENSG='Y'
   fi
fi

# -----------------------------------------------------------------------------
# Miscellaneous checks.
# -----------------------------------------------------------------------------
DPP_INSTALLER(, 0644, 0755, 0755)

# -----------------------------------------------------------------------------
# Finalize substitution settings.
# -----------------------------------------------------------------------------

# Compiler-specific settings when GCC is not being used.
if test "x$USE_GCC" != "xyes" ; then
   if test "x$PLATFORM" = "xIRIX" ; then
      EXTRA_LINK_FLAGS="$EXTRA_LINK_FLAGS -J4 -all"
   fi
fi

PYJUTIL_LDFLAGS_OPT='-L$(topdir)/lib -lpyjutil'
PYJUTIL_LDFLAGS_DBG="$PYJUTIL_LDFLAGS_OPT"

DPP_PTHREAD_FINISH

# -----------------------------------------------------------------------------
# Do Makefile substitutions.
# -----------------------------------------------------------------------------

DPP_SUBST

AC_SUBST(USE_OBJCOPY)
AC_SUBST(EXTRA_LINK_FLAGS)
AC_SUBST(PYJUTIL_LDFLAGS_DBG)
AC_SUBST(PYJUTIL_LDFLAGS_OPT)

AC_SUBST(HAVE_OSG)
AC_SUBST(OSG_INCLUDES)
AC_SUBST(OT_LDFLAGS)
AC_SUBST(PRODUCER_LDFLAGS)
AC_SUBST(OSG_LDFLAGS)
AC_SUBST(OSG_LIBS)

AC_SUBST(HAVE_OPENSG)
AC_SUBST(OPENSG_INCLUDES)
AC_SUBST(OPENSG_LDFLAGS)
AC_SUBST(OPENSG_LIBS)

AC_SUBST(PYTHON_ROOT)
AC_SUBST(PYTHON_INCLUDES)
AC_SUBST(PYTHON_LIB_OPT)
AC_SUBST(PYTHON_LIB_DBG)
AC_SUBST(PYMOD_EXT)
AC_SUBST(UTIL_LIB)
AC_SUBST(PYTHON_LIB_DEPS)
AC_SUBST(PYTHON_LDFLAGS)
AC_SUBST(PYTHON_VERSION)

AC_SUBST(PYSTE)

AC_SUBST(BOOST_PYTHON_CXXFLAGS)
AC_SUBST(BOOST_PYTHON_INCLUDES)
AC_SUBST(BOOST_PYTHON_LDFLAGS_OPT)
AC_SUBST(BOOST_PYTHON_LDFLAGS_DBG)

# -----------------------------------------------------------------------------
# Finish up.
# -----------------------------------------------------------------------------

AC_CONFIG_FILES([Makefile
                 VARS.pl
                 pyjutil/Makefile
                 src/Makefile
                 src/common.mk
                 src/common-targets.mk
                 src/cluster/Makefile
                 src/gadget/Makefile
                 src/jccl/Makefile
                 src/opengl/Makefile
                 src/opensg/Makefile
                 src/osg/Makefile
                 src/snx/Makefile
                 src/vpr/Makefile
                 src/vrj/Makefile
                 examples/Makefile
                 examples/cxx/Makefile
                 examples/cxx/PyAppLoader/Makefile
                 examples/cxx/PyExtApp/Makefile])

AC_OUTPUT
