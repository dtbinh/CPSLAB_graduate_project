/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fcn_track_ccdp_fast.h
 *
 * Code generation for function 'fcn_track_ccdp_fast'
 *
 */

#ifndef __FCN_TRACK_CCDP_FAST_H__
#define __FCN_TRACK_CCDP_FAST_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "fcn_track_ccdp_fast_types.h"

/* Function Declarations */
extern void fcn_track_ccdp_fast(fcn_track_ccdp_fastStackData *SD, const
  emlrtStack *sp, const real_T pS[3], const emxArray_struct0_T *pEst, real_T H,
  real_T T, const struct1_T *ccdp, real_T threshold_track, const struct3_T
  *costparam, const emxArray_struct4_T *nextstate, real_T *uv_opt, real_T
  *uw_opt, emxArray_real_T *predict_s);

#endif

/* End of code generation (fcn_track_ccdp_fast.h) */
