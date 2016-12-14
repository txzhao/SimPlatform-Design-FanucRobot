#ifndef __c5_DynTaskCon_h__
#define __c5_DynTaskCon_h__

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
} c5_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c5_Cen[18];
  real_T c5_Ie1[9];
  real_T c5_Ie2[9];
  real_T c5_Ie3[9];
  real_T c5_Ie4[9];
  real_T c5_Ie5[9];
  real_T c5_Ie6[9];
  real_T c5_L[9];
  real_T c5_Ma[6];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_doneDoubleBufferReInit;
  boolean_T c5_isStable;
  uint8_T c5_is_active_c5_DynTaskCon;
  ChartInfoStruct chartInfo;
} SFc5_DynTaskConInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_DynTaskCon_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_DynTaskCon_get_check_sum(mxArray *plhs[]);
extern void c5_DynTaskCon_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
