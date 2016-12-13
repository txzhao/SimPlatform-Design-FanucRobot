#ifndef __c13_CtrPlatform_h__
#define __c13_CtrPlatform_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c13_ResolvedFunctionInfo;

typedef struct {
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_CtrPlatform;
  real_T c13_L[9];
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc13_CtrPlatformInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_CtrPlatform_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_CtrPlatform_get_check_sum(mxArray *plhs[]);
extern void c13_CtrPlatform_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
