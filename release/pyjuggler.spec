# Spec file for PyJuggler.
%define name pyjuggler
%define version 1.1.13
%define release 3%{?dist}

%define vpr_version 1.1.20
%define jccl_version 1.1.11
%define sonix_version 1.1
%define gadgeteer_version 1.1.20
%define vrjuggler_version 2.1.12

%{?!python:%define python python}
%{?!pybasever:%{expand:%%define pybasever %(%{__python} -c "import sys ; print sys.version[:3]")}}

%define have_osg %(if [ -e /usr/include/osg/Version ] ; then echo 1; else echo 0; fi)
%define have_opensg %(if [ -e /usr/include/OpenSG/OSGNode.h ] ; then echo 1; else echo 0; fi)

Name: pyjuggler
Summary: PyJuggler provides Python language bindings for VR Juggler
Version: %{version}
Release: %{release}
Source: PyJuggler-%{version}-src.tar.bz2
URL: http://www.vrjuggler.org/pyjuggler/
Group: Development/Python
BuildRoot: %{_tmppath}/%{name}-%{version}-buildroot
License: LGPL
Requires: pyjutil = %{version}
Requires: vpr >= %{vpr_version}
Requires: jccl-c++ >= %{jccl_version}
Requires: sonix >= %{sonix_version}
Requires: gadgeteer >= %{gadgeteer_version}
Requires: vrjuggler >= %{vrjuggler_version}
Requires: python >= %{pybasever}
Requires: pygmtl
BuildRequires: glibc-devel
BuildRequires: e2fsprogs-devel
BuildRequires: vpr-devel >= %{vpr_version}
BuildRequires: jccl-c++-devel >= %{jccl_version}
BuildRequires: sonix-devel >= %{sonix_version}
BuildRequires: gadgeteer-devel >= %{gadgeteer_version}
BuildRequires: vrjuggler-devel >= %{vrjuggler_version}
BuildRequires: vrjuggler-opengl-devel >= %{vrjuggler_version}
Provides: PyJuggler = %{version}-%{release}

%description
PyJuggler is a Python module that allows VR Juggler application objects to be
written in Python. It makes use of the Boost.Python library. VR Juggler
application objects written in Python are loaded into the VR Juggler kernel
(written in C++) and executed as though they were "normal" C++ application
objects. The result is that highly portable VR Juggler applications can be
written quickly and easily in Python.

%package docs
Summary: PyJuggler documentation and API reference
Group: Development/Python
URL: http://www.vrjuggler.org/pyjuggler/

%description docs
PyJuggler prose documentation and the API reference.

%package -n pyjutil
Summary: PyJuggler's pyjutil library
Group: Development/C++
URL: http://www.vrjuggler.org/pyjuggler/
Requires: vpr >= %{vpr_version}
Requires: python >= %{pybasever}

%description -n pyjutil
A utility library used by PyJuggler. This provides a thread-specific,
guard-based mechasnim for accessing the Python global interpreter lock (GIL).
The intention is to make it easy for code using Boost.Python and the VR
Juggler Portable Runtime (VPR) to access the Python interpreter in a
multi-threaded context.

%package -n pyjutil-devel
Summary: Headers for using PyJuggler's pyjutil library
Group: Development/C++
URL: http://www.vrjuggler.org/pyjuggler/
Requires: vpr-devel >= %{vpr_version}
Requires: pyjutil = %{version}
Requires: python-devel >= %{pybasever}
Requires: boost-devel >= 1.32

%description -n pyjutil-devel
The headers needed to use the functionality provided by PyJuggler's pyjutil
library.

%if %have_osg
%package -n pyjuggler-osg
Summary: Provides Python bindings for the VR Juggler C++ class vrj::OsgApp
URL: http://www.vrjuggler.org/pyjuggler/
Group: Development/Python
Requires: vpr >= %{vpr_version}
Requires: jccl-c++ >= %{jccl_version}
Requires: sonix >= %{sonix_version}
Requires: gadgeteer >= %{gadgeteer_version}
Requires: vrjuggler >= %{vrjuggler_version}
Requires: openscenegraph >= 1.0
Requires: pyjuggler = %{version}
Requires: pygmtl
Requires: pyosg
BuildRequires: glibc-devel
BuildRequires: e2fsprogs-devel
BuildRequires: cppdom-devel >= 0.3.3
BuildRequires: boost-devel >= 1.32
BuildRequires: vpr-devel >= %{vpr_version}
BuildRequires: jccl-c++-devel >= %{jccl_version}
BuildRequires: sonix-devel >= %{sonix_version}
BuildRequires: gadgeteer-devel >= %{gadgeteer_version}
BuildRequires: vrjuggler-devel >= %{vrjuggler_version}
BuildRequires: vrjuggler-opengl-devel >= %{vrjuggler_version}
BuildRequires: openscenegraph-devel >= 1.0
Provides: PyJuggler-OSG = %{version}-%{release}
Provides: PyJuggler-OpenSsceneGraph = %{version}-%{release}

%description -n pyjuggler-osg
Python bindings for the VR Juggler C++ class vrj::OsgApp. This Python extension
module allows creation of Python application objects using Open Scene Graph
(http://www.openscenegra.org/). PyOSG is required.
%endif

%if %have_opensg
%package -n pyjuggler-opensg
Summary: Provides Python bindings for the VR Juggler C++ class vrj::OpenSGApp
URL: http://www.vrjuggler.org/pyjuggler/
Group: Development/Python
Requires: vpr >= %{vpr_version}
Requires: jccl-c++ >= %{jccl_version}
Requires: sonix >= %{sonix_version}
Requires: gadgeteer >= %{gadgeteer_version}
Requires: vrjuggler >= %{vrjuggler_version}
Requires: OpenSG >= 1.6.0
Requires: pyjuggler = %{version}
Requires: pygmtl
Requires: pyopensg
BuildRequires: glibc-devel
BuildRequires: e2fsprogs-devel
BuildRequires: cppdom-devel >= 0.3.3
BuildRequires: boost-devel >= 1.32
BuildRequires: vpr-devel >= %{vpr_version}
BuildRequires: jccl-c++-devel >= %{jccl_version}
BuildRequires: sonix-devel >= %{sonix_version}
BuildRequires: gadgeteer-devel >= %{gadgeteer_version}
BuildRequires: vrjuggler-devel >= %{vrjuggler_version}
BuildRequires: vrjuggler-opengl-devel >= %{vrjuggler_version}
BuildRequires: OpenSG-devel >= 1.6.0
Provides: PyJuggler-OpenSG = %{version}-%{release}

%description -n pyjuggler-opensg
Python bindings for the VR Juggler C++ class vrj::OpenSGApp. This Python
extension module allows creation of Python application objects using OpenSG
(http://opensg.vrsource.org/). pyOpenSG is required.
%endif

%if %have_osg
%define osg_opt --with-osg=/usr
%endif

%if %have_opensg
%define opensg_opt --with-opensg=/usr
%endif

%prep
rm -rf %{buildroot}
# For now don't keep unpacking
%setup -q -n PyJuggler-%{version}-src
#%setup -DT -q -n PyJuggler-%{version}-src
./configure --with-boost-python=/usr --prefix=%{_prefix}        \
   --with-boost-python-lib=boost_python                         \
   %{?osg_opt}                                                  \
   %{?opensg_opt}

%build
make %{?_smp_mflags} optim
LD_LIBRARY_PATH=lib make docs
make -C doc/getting.started.guide docs

%install
instdir=%{buildroot}%{_prefix}
docdir=$instdir/share/pyjuggler/doc
make prefix=$instdir install
make prefix=$instdir install-docs
mkdir -p $docdir/python.progammer.reference
mv $docdir/*.html $docdir/python.progammer.reference
make -C doc/getting.started.guide prefix=$docdir/getting.started.guide  \
   install-docs
# Just in case... stupid scons
find $instdir -name .sconsign -exec rm {} \;

if test "%{_libdir}" != "/usr/lib" ; then
   mv %{buildroot}%{_prefix}/lib %{buildroot}%{_libdir}
fi

%clean
rm -rf %{buildroot}

%post
/sbin/ldconfig

%postun
/sbin/ldconfig

%files
%defattr(-, root, root)
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/*.py*
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/vpr.so
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/jccl.so
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/snx.so
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/gadget.so
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/cluster.so
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/__vrj.so
%{_prefix}/share/pyjuggler/examples
%doc COPYING.txt INSTALL.txt ChangeLog

%files docs
%defattr(-, root, root)
%{_prefix}/share/pyjuggler/doc

%files -n pyjutil
%defattr(-, root, root)
%{_libdir}/libpyjutil.so

%files -n pyjutil-devel
%defattr(-, root, root)
%{_includedir}/pyjutil

%if %have_osg
%files -n pyjuggler-osg
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/__osgapp.so
%endif

%if %have_opensg
%files -n pyjuggler-opensg
%{_libdir}/python%{pybasever}/site-packages/PyJuggler/__opensgapp.so
%endif

%changelog
* Wed Jan 10 2007 Patrick Hartling <patrick@infiscape.com> 1.1.13-3
- Fixed Fedora Core 6 packaging.

* Tue Jan 09 2007 Patrick Hartling <patrick@infiscape.com> 1.1.13-2
- Fixed x86_64 case.

* Mon Jan 08 2007 Patrick Hartling <patrick@infiscape.com> 1.1.13-1
- Initial version.
