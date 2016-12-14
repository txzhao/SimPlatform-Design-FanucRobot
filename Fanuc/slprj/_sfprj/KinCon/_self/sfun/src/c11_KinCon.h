#ifndef __c11_KinCon_h__
#define __c11_KinCon_h__

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
} c11_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  real_T c11_L[9];
  real_T c11_init_Rot[9];
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c11_doneDoubleBufferReInit;
  boolean_T c11_isStable;
  uint8_T c11_is_active_c11_KinCon;
  ChartInfoStruct chartInfo;
} SFc11_KinConInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_KinCon_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_KinCon_get_check_sum(mxArray *plhs[]);
extern void c11_KinCon_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
