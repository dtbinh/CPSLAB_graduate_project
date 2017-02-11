/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fcn_track_ccdp_fast_mex.c
 *
 * Code generation for function '_coder_fcn_track_ccdp_fast_mex'
 *
 */

/* Include files */
#include "fcn_track_ccdp_fast.h"
#include "_coder_fcn_track_ccdp_fast_mex.h"
#include "fcn_track_ccdp_fast_terminate.h"
#include "_coder_fcn_track_ccdp_fast_api.h"
#include "fcn_track_ccdp_fast_initialize.h"
#include "fcn_track_ccdp_fast_data.h"
#include <stdio.h>

/* Variable Definitions */
static fcn_track_ccdp_fastStackData *c_fcn_track_ccdp_fastStackDataG = NULL;

/* Function Declarations */
static void fcn_track_ccdp_fast_mexFunction(fcn_track_ccdp_fastStackData *SD,
  int32_T nlhs, mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[8]);

/* Function Definitions */
static void fcn_track_ccdp_fast_mexFunction(fcn_track_ccdp_fastStackData *SD,
  int32_T nlhs, mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[8])
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
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  fcn_track_ccdp_fast_api(SD, inputs, outputs);

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

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  c_fcn_track_ccdp_fastStackDataG = (fcn_track_ccdp_fastStackData *)mxCalloc(1,
    sizeof(fcn_track_ccdp_fastStackData));

  /* Initialize the memory manager. */
  mexAtExit(fcn_track_ccdp_fast_atexit);

  /* Module initialization. */
  fcn_track_ccdp_fast_initialize();

  /* Dispatch the entry-point. */
  fcn_track_ccdp_fast_mexFunction(c_fcn_track_ccdp_fastStackDataG, nlhs, plhs,
    nrhs, prhs);
  mxFree(c_fcn_track_ccdp_fastStackDataG);
}

/* End of code generation (_coder_fcn_track_ccdp_fast_mex.c) */
