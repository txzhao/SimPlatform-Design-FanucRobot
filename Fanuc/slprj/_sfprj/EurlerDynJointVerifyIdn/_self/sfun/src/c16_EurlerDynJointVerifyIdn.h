#ifndef __c16_EurlerDynJointVerifyIdn_h__
#define __c16_EurlerDynJointVerifyIdn_h__

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
  real_T c16_L[9];
  real_T c16_init_Rot[9];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c16_doneDoubleBufferReInit;
  boolean_T c16_isStable;
  uint8_T c16_is_active_c16_EurlerDynJointVerifyIdn;
  ChartInfoStruct chartInfo;
} SFc16_EurlerDynJointVerifyIdnInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c16_EurlerDynJointVerifyIdn_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c16_EurlerDynJointVerifyIdn_get_check_sum(mxArray *plhs[]);
extern void c16_EurlerDynJointVerifyIdn_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
