@echo off
set MATLAB=C:\MYSOFT~1\MATLAB~3
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\MySoftrware\Matlab2014\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=EulerBasis_mex
set MEX_NAME=EulerBasis_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for EulerBasis > EulerBasis_mex.mki
echo COMPILER=%COMPILER%>> EulerBasis_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> EulerBasis_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> EulerBasis_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> EulerBasis_mex.mki
echo LINKER=%LINKER%>> EulerBasis_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> EulerBasis_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> EulerBasis_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> EulerBasis_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> EulerBasis_mex.mki
echo BORLAND=%BORLAND%>> EulerBasis_mex.mki
echo OMPFLAGS= >> EulerBasis_mex.mki
echo OMPLINKFLAGS= >> EulerBasis_mex.mki
echo EMC_COMPILER=msvc90>> EulerBasis_mex.mki
echo EMC_CONFIG=optim>> EulerBasis_mex.mki
"C:\MySoftrware\Matlab2014\bin\win64\gmake" -B -f EulerBasis_mex.mk
