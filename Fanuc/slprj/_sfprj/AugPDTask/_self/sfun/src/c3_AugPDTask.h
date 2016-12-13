#ifndef __c3_AugPDTask_h__
#define __c3_AugPDTask_h__

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
  real_T c3_Cen[18];
  real_T c3_Ie1[9];
  real_T c3_Ie2[9];
  real_T c3_Ie3[9];
  real_T c3_Ie4[9];
  real_T c3_Ie5[9];
  real_T c3_Ie6[9];
  real_T c3_L[9];
  real_T c3_Ma[6];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c3_doneDoubleBufferReInit;
  boolean_T c3_isStable;
  uint8_T c3_is_active_c3_AugPDTask;
  ChartInfoStruct chartInfo;
} SFc3_AugPDTaskInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_AugPDTask_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_AugPDTask_get_check_sum(mxArray *plhs[]);
extern void c3_AugPDTask_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
