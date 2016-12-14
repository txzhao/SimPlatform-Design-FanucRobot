#ifndef __c20_EurlerDynJointVerify_h__
#define __c20_EurlerDynJointVerify_h__

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
} c20_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c20_Cen_Min[18];
  real_T c20_DH_Min[28];
  real_T c20_Ft_Min[6];
  real_T c20_Ie_Min[54];
  real_T c20_Ma_Min[6];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c20_doneDoubleBufferReInit;
  boolean_T c20_isStable;
  uint8_T c20_is_active_c20_EurlerDynJointVerify;
  ChartInfoStruct chartInfo;
} SFc20_EurlerDynJointVerifyInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c20_EurlerDynJointVerify_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c20_EurlerDynJointVerify_get_check_sum(mxArray *plhs[]);
extern void c20_EurlerDynJointVerify_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
