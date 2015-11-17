@echo off
setlocal

REM Set the PATH variable to include any directories with custom libraries that
REM you're using.
set PATH=%PATH%;D:\tools\boost_1_55_0\lib64-msvc-12.0;D:\tools\vrjuggler\bin;D:\tools\xml-cppdom\bin;D:\tools\freealut\bin;D:\tools\openal\bin;C:\Python27-x86_64\DLLs;D:\tools\pythonlibs\PyJuggler

REM Set the PYTHONPATH variable to point to where you have installed any custom
REM python modules such as PyJuggler itself.
set PYTHONPATH=D:\tools\pythonlibs

REM Run your application with an argument pointing to the VRJuggler config
REM file you would like to use.
C:\Python27-x86_64\python simpleGL.py D:\tools\vrjuggler-config\desktop\desktop-cavesim.jconf

endlocal
