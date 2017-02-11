//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fcn_track_ccdp_fast.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//
#ifndef __FCN_TRACK_CCDP_FAST_H__
#define __FCN_TRACK_CCDP_FAST_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "fcn_track_ccdp_fast_types.h"

// Function Declarations
extern void fcn_track_ccdp_fast(const double pS[3], const emxArray_struct0_T
  *pEst, double H, double T, const struct1_T *ccdp, double threshold_track,
  const struct3_T *costparam, const emxArray_struct4_T *nextstate, double
  *uv_opt, double *uw_opt, emxArray_real_T *predict_s);

#endif

//
// File trailer for fcn_track_ccdp_fast.h
//
// [EOF]
//
