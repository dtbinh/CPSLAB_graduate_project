//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: round.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "round.h"
#include "fcn_track_ccdp_fast_rtwutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : emxArray_real_T *x
// Return Type  : void
//
void b_round(emxArray_real_T *x)
{
  int i12;
  int k;
  i12 = x->size[0] * x->size[1];
  for (k = 0; k < i12; k++) {
    x->data[k] = rt_roundd_snf(x->data[k]);
  }
}

//
// Arguments    : double x[2]
// Return Type  : void
//
void c_round(double x[2])
{
  int k;
  for (k = 0; k < 2; k++) {
    x[k] = rt_roundd_snf(x[k]);
  }
}

//
// File trailer for round.cpp
//
// [EOF]
//
