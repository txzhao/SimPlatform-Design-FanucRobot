/*
 * EulerBasis_terminate.c
 *
 * Code generation for function 'EulerBasis_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "EulerBasis.h"
#include "EulerBasis_terminate.h"

/* Function Definitions */
void EulerBasis_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void EulerBasis_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (EulerBasis_terminate.c) */
