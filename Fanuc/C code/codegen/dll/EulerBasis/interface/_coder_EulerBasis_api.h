/* 
 * File: _coder_EulerBasis_api.h 
 *  
 * MATLAB Coder version            : 2.6 
 * C/C++ source code generated on  : 01-May-2015 14:43:34 
 */

#ifndef ___CODER_EULERBASIS_API_H__
#define ___CODER_EULERBASIS_API_H__
/* Include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Function Declarations */
extern void EulerBasis_initialize(emlrtContext *aContext);
extern void EulerBasis_terminate(void);
extern void EulerBasis_atexit(void);
extern void EulerBasis_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void EulerBasis(double in1[5], double B[2160]);
extern void EulerBasis_xil_terminate(void);

#endif
/* 
 * File trailer for _coder_EulerBasis_api.h 
 *  
 * [EOF] 
 */
