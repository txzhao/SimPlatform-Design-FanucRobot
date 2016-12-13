/*
 * _coder_EulerWd_Min_mex.c
 *
 * Code generation for function 'EulerWd_Min'
 *
 */

/* Include files */
#include "mex.h"
#include "_coder_EulerWd_Min_api.h"
#include "EulerWd_Min_initialize.h"
#include "EulerWd_Min_terminate.h"

/* Function Declarations */
static void EulerWd_Min_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "EulerWd_Min", NULL, false, {2045744189U,2170104910U,2743257031U,4284093946U}, NULL };
void *emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void EulerWd_Min_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  const mxArray *outputs[1];
  const mxArray *inputs[5];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  emlrtStack st = { NULL, NULL, NULL };
  /* Module initialization. */
  EulerWd_Min_initialize(&emlrtContextGlobal);
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, mxINT32_CLASS, 5, mxCHAR_CLASS, 11, "EulerWd_Min");
  } else if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, mxCHAR_CLASS, 11, "EulerWd_Min");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = prhs[n];
  }
  /* Call the function. */
  EulerWd_Min_api(inputs, outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  EulerWd_Min_terminate();
}

void EulerWd_Min_atexit_wrapper(void)
{
   EulerWd_Min_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(EulerWd_Min_atexit_wrapper);
  /* Dispatch the entry-point. */
  EulerWd_Min_mexFunction(nlhs, plhs, nrhs, prhs);
}
/* End of code generation (_coder_EulerWd_Min_mex.c) */
