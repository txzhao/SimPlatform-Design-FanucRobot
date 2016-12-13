/*
 * EulerWd_Min_terminate.c
 *
 * Code generation for function 'EulerWd_Min_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EulerWd_Min.h"
#include "EulerWd_Min_terminate.h"

/* Function Definitions */
void EulerWd_Min_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void EulerWd_Min_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (EulerWd_Min_terminate.c) */
