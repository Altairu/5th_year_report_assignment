@call "C:\Users\student\AppData\Roaming\MathWorks\MATLAB\R2013a\mexopts.bat"
@echo on
call "C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin\SetEnv.cmd" /x64 /Release 2>1 > nul:
set MATLAB=C:\Programs\MATLAB\R2013a
nmake -f da_conv_count.mk  MAT_FILE=0 SHOW_TIMES=0 DEBUG=0 DEBUG_HEAP=0 OPTS="-DON_TARGET_WAIT_FOR_START=0"
