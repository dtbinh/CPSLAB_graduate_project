/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_fcn_track_ccdp_fast_mex.cpp
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jul-2016 17:02:06
 */

/* Include Files */
#include "_coder_fcn_track_ccdp_fast_api.h"
#include "_coder_fcn_track_ccdp_fast_mex.h"
#include <stdio.h>

/* Function Declarations */
static void fcn_track_ccdp_fast_mexFunction(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[8]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[8]
 * Return Type  : void
 */
static void fcn_track_ccdp_fast_mexFunction(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[8])
{
  int32_T n;
  const mxArray *inputs[8];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        19, "fcn_track_ccdp_fast");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "fcn_track_ccdp_fast");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  fcn_track_ccdp_fast_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  fcn_track_ccdp_fast_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(fcn_track_ccdp_fast_atexit);

  /* Module initialization. */
  fcn_track_ccdp_fast_initialize();

  /* Dispatch the entry-point. */
  fcn_track_ccdp_fast_mexFunction(nlhs, plhs, nrhs, prhs);
}

/*
 * File trailer for _coder_fcn_track_ccdp_fast_mex.cpp
 *
 * [EOF]
 */
