#ifndef __c17_DynJointVerify_h__
#define __c17_DynJointVerify_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char *context;
  const char *name;
  const char *dominantType;
  const char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c17_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c17_Cen[18];
  real_T c17_Ie1[9];
  real_T c17_Ie2[9];
  real_T c17_Ie3[9];
  real_T c17_Ie4[9];
  real_T c17_Ie5[9];
  real_T c17_Ie6[9];
  real_T c17_L_EU[8];
  real_T c17_Ma[6];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c17_doneDoubleBufferReInit;
  boolean_T c17_isStable;
  uint8_T c17_is_active_c17_DynJointVerify;
  ChartInfoStruct chartInfo;
} SFc17_DynJointVerifyInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_DynJointVerify_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c17_DynJointVerify_get_check_sum(mxArray *plhs[]);
extern void c17_DynJointVerify_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
