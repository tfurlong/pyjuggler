@echo off
setlocal

set APP_EXEC=C:\Python27-x86_64\python.exe
set APP_ARGS=D:\tools\pythonlibs\simpleGL\simpleGL.py --vrjslave --listen_port=27765
set APP_WORKDIR=D:\tools\pythonlibs\simpleGL
SET LOG_NAME=runlog-%NODE_NAME%.txt

rem set dependency DLL paths
set PATH=D:\tools\boost_1_55_0\lib64-msvc-12.0;%PATH%
set PATH=D:\tools\freealut\bin;%PATH%
set PATH=D:\tools\openal\bin;%PATH%
set PATH=D:\tools\vrjuggler\bin;%PATH%
set PATH=D:\tools\xml-cppdom\bin;%PATH%
set PATH=D:\tools\pythonlibs\PyJuggler;%PATH%
set PATH=C:\Python27-x86_64\DLLs;%PATH%

rem set python module search path
set PYTHONPATH=D:\tools\pythonlibs

rem vrjuggler paths
set VJ_BASE_DIR=D:\tools\vrjuggler
set JCCL_CFG_PATH=%VJ_BASE_DIR%\share\vrjuggler\data\configFiles
set JCCL_DEFINITION_PATH=%VJ_BASE_DIR%\share\vrjuggler\data\definitions
set VPR_DEBUG_NFY_LEVEL=31

pushd %APP_WORKDIR%
if EXIST %LOG_NAME% (
	echo "removing log file %LOG_NAME%"
	del /F %LOG_NAME%
)
%APP_EXEC% %APP_ARGS% >%LOG_NAME% 2>&1
popd
