@echo off
setlocal

REM Set the PATH variable to include any directories with custom libraries that
REM you're using.
set PATH=%PATH%;D:\libs\boost_1_55_0\lib64-msvc-12.0;D:\libs\vrjuggler\bin;D:\libs\xml-cppdom\bin;D:\libs\freealut\bin;D:\libs\openal\bin;D:\programs\Python27\DLLs;D:\pythonlibs\PyJuggler

REM Set the PYTHONPATH variable to point to where you have installed any custom
REM python modules such as PyJuggler itself.
set PYTHONPATH=D:\pythonlibs;D:\libs\boost_1_55_0\lib64-msvc-12.0;D:\libs\vrjuggler\bin;D:\libs\xml-cppdom\bin;D:\programs\Python27\DLLs

REM Run your application with an argument pointing to the VRJuggler config
REM file you would like to use.
python  simpleGL.py S:\tools\vrjuggler-config\desktop\desktop-cavesim.jconf

endlocal
