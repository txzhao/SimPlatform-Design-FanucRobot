/* 
 * File: _coder_EulerWd_Min_api.h 
 *  
 * MATLAB Coder version            : 2.6 
 * C/C++ source code generated on  : 01-May-2015 14:16:50 
 */

#ifndef ___CODER_EULERWD_MIN_API_H__
#define ___CODER_EULERWD_MIN_API_H__
/* Include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Function Declarations */
extern void EulerWd_Min_initialize(emlrtContext *aContext);
extern void EulerWd_Min_terminate(void);
extern void EulerWd_Min_atexit(void);
extern void EulerWd_Min_api(const mxArray *prhs[5], const mxArray *plhs[1]);
extern void EulerWd_Min(double in1[5], double in2[6], double in3[6], double in4[6], double gr, double Wd_[360]);
extern void EulerWd_Min_xil_terminate(void);

#endif
/* 
 * File trailer for _coder_EulerWd_Min_api.h 
 *  
 * [EOF] 
 */
