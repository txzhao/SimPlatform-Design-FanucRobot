/* 
 * File: _coder_EuleriBBt_api.h 
 *  
 * MATLAB Coder version            : 2.6 
 * C/C++ source code generated on  : 01-May-2015 16:00:02 
 */

#ifndef ___CODER_EULERIBBT_API_H__
#define ___CODER_EULERIBBT_API_H__
/* Include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Function Declarations */
extern void EuleriBBt_initialize(emlrtContext *aContext);
extern void EuleriBBt_terminate(void);
extern void EuleriBBt_atexit(void);
extern void EuleriBBt_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void EuleriBBt(double in1[5], double iBBt[1296]);
extern void EuleriBBt_xil_terminate(void);

#endif
/* 
 * File trailer for _coder_EuleriBBt_api.h 
 *  
 * [EOF] 
 */
