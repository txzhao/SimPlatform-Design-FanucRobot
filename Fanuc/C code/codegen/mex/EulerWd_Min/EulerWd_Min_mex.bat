@echo off
set MATLAB=C:\MYSOFT~1\MATLAB~3
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\MySoftrware\Matlab2014\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=EulerWd_Min_mex
set MEX_NAME=EulerWd_Min_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for EulerWd_Min > EulerWd_Min_mex.mki
echo COMPILER=%COMPILER%>> EulerWd_Min_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> EulerWd_Min_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> EulerWd_Min_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> EulerWd_Min_mex.mki
echo LINKER=%LINKER%>> EulerWd_Min_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> EulerWd_Min_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> EulerWd_Min_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> EulerWd_Min_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> EulerWd_Min_mex.mki
echo BORLAND=%BORLAND%>> EulerWd_Min_mex.mki
echo OMPFLAGS= >> EulerWd_Min_mex.mki
echo OMPLINKFLAGS= >> EulerWd_Min_mex.mki
echo EMC_COMPILER=msvc90>> EulerWd_Min_mex.mki
echo EMC_CONFIG=optim>> EulerWd_Min_mex.mki
"C:\MySoftrware\Matlab2014\bin\win64\gmake" -B -f EulerWd_Min_mex.mk
