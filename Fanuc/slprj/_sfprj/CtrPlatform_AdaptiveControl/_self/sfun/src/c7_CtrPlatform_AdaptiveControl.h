#ifndef __c7_CtrPlatform_AdaptiveControl_h__
#define __c7_CtrPlatform_AdaptiveControl_h__

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
} c7_ResolvedFunctionInfo;

typedef struct {
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_CtrPlatform_AdaptiveControl;
  real_T c7_L[9];
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc7_CtrPlatform_AdaptiveControlInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_CtrPlatform_AdaptiveControl_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_CtrPlatform_AdaptiveControl_get_check_sum(mxArray *plhs[]);
extern void c7_CtrPlatform_AdaptiveControl_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif