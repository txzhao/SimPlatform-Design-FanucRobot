#ifndef __c1_EulerPIDJoint_h__
#define __c1_EulerPIDJoint_h__

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
} c1_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c1_L[9];
  real_T c1_init_Rot[9];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c1_doneDoubleBufferReInit;
  boolean_T c1_isStable;
  uint8_T c1_is_active_c1_EulerPIDJoint;
  ChartInfoStruct chartInfo;
} SFc1_EulerPIDJointInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_EulerPIDJoint_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_EulerPIDJoint_get_check_sum(mxArray *plhs[]);
extern void c1_EulerPIDJoint_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
