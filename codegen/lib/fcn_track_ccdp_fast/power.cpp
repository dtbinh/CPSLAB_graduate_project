//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "power.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Declarations
static void eml_scalexp_alloc(const emxArray_real_T *varargin_1, emxArray_real_T
  *z);

// Function Definitions

//
// Arguments    : const emxArray_real_T *varargin_1
//                emxArray_real_T *z
// Return Type  : void
//
static void eml_scalexp_alloc(const emxArray_real_T *varargin_1, emxArray_real_T
  *z)
{
  unsigned char uv0[2];
  int i4;
  for (i4 = 0; i4 < 2; i4++) {
    uv0[i4] = (unsigned char)varargin_1->size[i4];
  }

  i4 = z->size[0] * z->size[1];
  z->size[0] = uv0[0];
  z->size[1] = uv0[1];
  emxEnsureCapacity((emxArray__common *)z, i4, (int)sizeof(double));
}

//
// Arguments    : const emxArray_real_T *a
//                emxArray_real_T *y
// Return Type  : void
//
void power(const emxArray_real_T *a, emxArray_real_T *y)
{
  int i3;
  int k;
  eml_scalexp_alloc(a, y);
  i3 = y->size[0] * y->size[1];
  for (k = 0; k < i3; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

//
// File trailer for power.cpp
//
// [EOF]
//
