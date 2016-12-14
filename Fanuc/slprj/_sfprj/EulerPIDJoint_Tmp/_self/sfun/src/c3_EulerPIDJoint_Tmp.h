#ifndef __c3_EulerPIDJoint_Tmp_h__
#define __c3_EulerPIDJoint_Tmp_h__

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
} c3_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c3_Cen_EU[18];
  real_T c3_DH_EU[28];
  real_T c3_Ft_EU[6];
  real_T c3_Ie_EU[54];
  real_T c3_Ma_EU[6];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_doneDoubleBufferReInit;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_EulerPIDJoint_Tmp;
  ChartInfoStruct chartInfo;
} SFc3_EulerPIDJoint_TmpInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_EulerPIDJoint_Tmp_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c3_EulerPIDJoint_Tmp_get_check_sum(mxArray *plhs[]);
extern void c3_EulerPIDJoint_Tmp_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
