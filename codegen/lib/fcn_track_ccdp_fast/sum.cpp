//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "sum.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *y
// Return Type  : void
//
void b_sum(const emxArray_real_T *x, emxArray_real_T *y)
{
  unsigned int sz[2];
  int ixstart;
  int k;
  int ix;
  int iy;
  int i;
  double s;
  for (ixstart = 0; ixstart < 2; ixstart++) {
    sz[ixstart] = (unsigned int)x->size[ixstart];
  }

  ixstart = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (int)sz[1];
  emxEnsureCapacity((emxArray__common *)y, ixstart, (int)sizeof(double));
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    ixstart = y->size[0] * y->size[1];
    y->size[0] = 1;
    emxEnsureCapacity((emxArray__common *)y, ixstart, (int)sizeof(double));
    ixstart = y->size[0] * y->size[1];
    y->size[1] = (int)sz[1];
    emxEnsureCapacity((emxArray__common *)y, ixstart, (int)sizeof(double));
    k = (int)sz[1];
    for (ixstart = 0; ixstart < k; ixstart++) {
      y->data[ixstart] = 0.0;
    }
  } else {
    ix = -1;
    iy = -1;
    for (i = 1; i <= x->size[1]; i++) {
      ixstart = ix + 1;
      ix++;
      s = x->data[ixstart];
      for (k = 2; k <= x->size[0]; k++) {
        ix++;
        s += x->data[ix];
      }

      iy++;
      y->data[iy] = s;
    }
  }
}

//
// Arguments    : const boolean_T x_data[]
//                const int x_size[1]
// Return Type  : double
//
double sum(const boolean_T x_data[], const int x_size[1])
{
  double y;
  int k;
  if (x_size[0] == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size[0]; k++) {
      y += (double)x_data[k - 1];
    }
  }

  return y;
}

//
// File trailer for sum.cpp
//
// [EOF]
//
