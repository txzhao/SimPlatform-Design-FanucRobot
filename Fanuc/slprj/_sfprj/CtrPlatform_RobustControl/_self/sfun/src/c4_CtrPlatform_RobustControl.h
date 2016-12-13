#ifndef __c4_CtrPlatform_RobustControl_h__
#define __c4_CtrPlatform_RobustControl_h__

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
} c4_ResolvedFunctionInfo;

typedef struct {
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_CtrPlatform_RobustControl;
  real_T c4_L[9];
  real_T c4_Cen[18];
  real_T c4_Ma[6];
  real_T c4_Ie1[9];
  real_T c4_Ie2[9];
  real_T c4_Ie3[9];
  real_T c4_Ie4[9];
  real_T c4_Ie5[9];
  real_T c4_Ie6[9];
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
} SFc4_CtrPlatform_RobustControlInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c4_CtrPlatform_RobustControl_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_CtrPlatform_RobustControl_get_check_sum(mxArray *plhs[]);
extern void c4_CtrPlatform_RobustControl_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
