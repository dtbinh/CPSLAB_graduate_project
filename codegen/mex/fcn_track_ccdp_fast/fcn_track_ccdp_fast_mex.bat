@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=fcn_track_ccdp_fast_mex
set MEX_NAME=fcn_track_ccdp_fast_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for fcn_track_ccdp_fast > fcn_track_ccdp_fast_mex.mki
echo COMPILER=%COMPILER%>> fcn_track_ccdp_fast_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> fcn_track_ccdp_fast_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> fcn_track_ccdp_fast_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> fcn_track_ccdp_fast_mex.mki
echo LINKER=%LINKER%>> fcn_track_ccdp_fast_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> fcn_track_ccdp_fast_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> fcn_track_ccdp_fast_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> fcn_track_ccdp_fast_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> fcn_track_ccdp_fast_mex.mki
echo BORLAND=%BORLAND%>> fcn_track_ccdp_fast_mex.mki
echo OMPFLAGS= >> fcn_track_ccdp_fast_mex.mki
echo OMPLINKFLAGS= >> fcn_track_ccdp_fast_mex.mki
echo EMC_COMPILER=msvc120>> fcn_track_ccdp_fast_mex.mki
echo EMC_CONFIG=optim>> fcn_track_ccdp_fast_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f fcn_track_ccdp_fast_mex.mk
