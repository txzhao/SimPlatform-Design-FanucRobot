# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64
!include <ntwin32.mak>

MACHINE     = DynTaskVerify
TARGET      = sfun
CHART_SRCS 	= \
     c1_DynTaskVerify.c\
     c2_DynTaskVerify.c\
     c3_DynTaskVerify.c\
     c4_DynTaskVerify.c\
     c5_DynTaskVerify.c\
     c6_DynTaskVerify.c\
     c7_DynTaskVerify.c\
     c8_DynTaskVerify.c\
     c9_DynTaskVerify.c\
     c10_DynTaskVerify.c\
     c11_DynTaskVerify.c\
     c12_DynTaskVerify.c\
     c13_DynTaskVerify.c\
     c14_DynTaskVerify.c\
     c15_DynTaskVerify.c
MACHINE_SRC	= DynTaskVerify_sfun.c
MACHINE_REG = DynTaskVerify_sfun_registry.c
MEX_WRAPPER =
MAKEFILE    = DynTaskVerify_sfun.mak
MATLAB_ROOT	= c:\mysoftrware\matlab2010
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   = 
AUX_INCLUDES   = 
ML_INCLUDES     = /I "$(MATLAB_ROOT)\extern\include"
SL_INCLUDES     = /I "$(MATLAB_ROOT)\simulink\include"
SF_INCLUDES     = /I "c:\mysoftrware\matlab2010\stateflow\c\mex\include" /I "c:\mysoftrware\matlab2010\stateflow\c\debugger\include"

DSP_INCLUDES    =

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(ML_INCLUDES) $(SL_INCLUDES) $(SF_INCLUDES) $(DSP_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = $(COMPFLAGS) /MD 
LDFLAGS = /nologo /dll /OPT:NOREF /export:mexFunction
AUXLDFLAGS = 

#----------------------------- Source Files -----------------------------------

REQ_SRCS  = $(MACHINE_SRC) $(MACHINE_REG) $(MEX_WRAPPER) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = DynTaskVerify_sfun.mol
SFCLIB = "c:\mysoftrware\matlab2010\stateflow\c\mex\lib\win64\sfc_mex.lib" "c:\mysoftrware\matlab2010\stateflow\c\debugger\lib\win64\sfc_debug.lib"
AUX_LNK_OBJS =
USER_LIBS =
LINK_MACHINE_LIBS =

DSP_LIBS    =
BLAS_LIBS   = "c:\mysoftrware\matlab2010\extern\lib\win64\microsoft\libmwblascompat32.lib"

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

MEXLIB = "C:\MySoftrware\Matlab2010\extern\lib\win64\microsoft\libmx.lib" "C:\MySoftrware\Matlab2010\extern\lib\win64\microsoft\libmex.lib" "C:\MySoftrware\Matlab2010\extern\lib\win64\microsoft\libmat.lib" "C:\MySoftrware\Matlab2010\extern\lib\win64\microsoft\libfixedpoint.lib" "C:\MySoftrware\Matlab2010\extern\lib\win64\microsoft\libut.lib" "C:\MySoftrware\Matlab2010\extern\lib\win64\microsoft\libmwmathutil.lib" "C:\MySoftrware\Matlab2010\extern\lib\win64\microsoft\libemlrt.lib" "c:\mysoftrware\matlab2010\lib\win64\libippmwipt.lib"

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) $(AUXLDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS) $(MEXLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

