//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: atan2.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "atan2.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Declarations
static void b_eml_scalexp_alloc(const emxArray_real_T *varargin_1, const
  emxArray_real_T *varargin_2, emxArray_real_T *z);
static double rt_atan2d_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : const emxArray_real_T *varargin_1
//                const emxArray_real_T *varargin_2
//                emxArray_real_T *z
// Return Type  : void
//
static void b_eml_scalexp_alloc(const emxArray_real_T *varargin_1, const
  emxArray_real_T *varargin_2, emxArray_real_T *z)
{
  int c;
  int b_c;
  int i6;
  if (varargin_1->size[0] <= varargin_2->size[0]) {
    c = varargin_1->size[0];
  } else {
    c = varargin_2->size[0];
  }

  if (varargin_1->size[1] <= varargin_2->size[1]) {
    b_c = varargin_1->size[1];
  } else {
    b_c = varargin_2->size[1];
  }

  i6 = z->size[0] * z->size[1];
  z->size[0] = c;
  z->size[1] = b_c;
  emxEnsureCapacity((emxArray__common *)z, i6, (int)sizeof(double));
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2((double)b_u0, (double)b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(double)(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

//
// Arguments    : const emxArray_real_T *y
//                const emxArray_real_T *x
//                emxArray_real_T *r
// Return Type  : void
//
void b_atan2(const emxArray_real_T *y, const emxArray_real_T *x, emxArray_real_T
             *r)
{
  int i5;
  int k;
  b_eml_scalexp_alloc(y, x, r);
  i5 = r->size[0] * r->size[1];
  for (k = 0; k < i5; k++) {
    r->data[k] = rt_atan2d_snf(y->data[k], x->data[k]);
  }
}

//
// File trailer for atan2.cpp
//
// [EOF]
//
