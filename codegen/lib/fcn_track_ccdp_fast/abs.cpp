//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: abs.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "abs.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *y
// Return Type  : void
//
void b_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  unsigned char uv2[2];
  int i11;
  int k;
  for (i11 = 0; i11 < 2; i11++) {
    uv2[i11] = (unsigned char)x->size[i11];
  }

  i11 = y->size[0] * y->size[1];
  y->size[0] = uv2[0];
  y->size[1] = uv2[1];
  emxEnsureCapacity((emxArray__common *)y, i11, (int)sizeof(double));
  i11 = x->size[0] * x->size[1];
  for (k = 0; k < i11; k++) {
    y->data[k] = fabs(x->data[k]);
  }
}

//
// File trailer for abs.cpp
//
// [EOF]
//
