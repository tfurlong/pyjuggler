@echo off
setlocal

set PATH=D:\libs\boost_1_55_0\lib64-msvc-12.0;D:\libs\vrjuggler\bin;D:\libs\xml-cppdom\bin;D:\programs\Python27\DLLs;%PATH%
D:\programs\dependency-walker\depends.exe D:\pythonlibs\pyjuggler\vrj\__vrj.pyd

endlocal