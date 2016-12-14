#ifndef __c21_DynJointVerify_h__
#define __c21_DynJointVerify_h__

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
} c21_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c21_Cen[18];
  real_T c21_L[9];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c21_doneDoubleBufferReInit;
  boolean_T c21_isStable;
  uint8_T c21_is_active_c21_DynJointVerify;
  ChartInfoStruct chartInfo;
} SFc21_DynJointVerifyInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_DynJointVerify_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_DynJointVerify_get_check_sum(mxArray *plhs[]);
extern void c21_DynJointVerify_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
