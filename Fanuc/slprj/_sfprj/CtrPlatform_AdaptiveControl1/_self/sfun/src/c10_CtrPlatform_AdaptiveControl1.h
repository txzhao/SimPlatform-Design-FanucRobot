#ifndef __c10_CtrPlatform_AdaptiveControl1_h__
#define __c10_CtrPlatform_AdaptiveControl1_h__

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
} c10_ResolvedFunctionInfo;

typedef struct {
  int32_T c10_sfEvent;
  boolean_T c10_isStable;
  boolean_T c10_doneDoubleBufferReInit;
  uint8_T c10_is_active_c10_CtrPlatform_AdaptiveControl1;
  real_T c10_L[9];
  real_T c10_Cen[18];
  real_T c10_Ma[6];
  real_T c10_Ie1[9];
  real_T c10_Ie2[9];
  real_T c10_Ie3[9];
  real_T c10_Ie4[9];
  real_T c10_Ie5[9];
  real_T c10_Ie6[9];
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc10_CtrPlatform_AdaptiveControl1InstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c10_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c10_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray *plhs[]);
extern void c10_CtrPlatform_AdaptiveControl1_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
