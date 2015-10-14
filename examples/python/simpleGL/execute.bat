@echo off
setlocal

set PATH=%PATH%;D:\libs\boost_1_55_0\lib64-msvc-12.0;D:\libs\vrjuggler\bin;D:\libs\xml-cppdom\bin;D:\libs\freealut\bin;D:\libs\openal\bin;D:\programs\Python27\DLLs;D:\pythonlibs\PyJuggler
set PYTHONPATH=D:\pythonlibs;D:\libs\boost_1_55_0\lib64-msvc-12.0;D:\libs\vrjuggler\bin;D:\libs\xml-cppdom\bin;D:\programs\Python27\DLLs
python  simpleGL.py S:\tools\vrjuggler-config\desktop\desktop-cavesim.jconf

endlocal
