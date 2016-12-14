#ifndef __c16_DynJointVerify_h__
#define __c16_DynJointVerify_h__

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
} c16_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c16_Cen[18];
  real_T c16_Ie1[9];
  real_T c16_Ie2[9];
  real_T c16_Ie3[9];
  real_T c16_Ie4[9];
  real_T c16_Ie5[9];
  real_T c16_Ie6[9];
  real_T c16_L_EU[8];
  real_T c16_Ma[6];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c16_doneDoubleBufferReInit;
  boolean_T c16_isStable;
  uint8_T c16_is_active_c16_DynJointVerify;
  ChartInfoStruct chartInfo;
} SFc16_DynJointVerifyInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c16_DynJointVerify_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_DynJointVerify_get_check_sum(mxArray *plhs[]);
extern void c16_DynJointVerify_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
