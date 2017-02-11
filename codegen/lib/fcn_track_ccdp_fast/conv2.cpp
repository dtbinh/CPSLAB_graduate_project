//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: conv2.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "conv2.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const emxArray_real_T *arg1
//                emxArray_real_T *c
// Return Type  : void
//
void conv2(const emxArray_real_T *arg1, emxArray_real_T *c)
{
  signed char unnamed_idx_0;
  signed char unnamed_idx_1;
  int firstRowA;
  int aidx;
  boolean_T b0;
  int ma;
  int na;
  int firstColB;
  int lastColB;
  int firstRowB;
  int lastRowB;
  int lastColA;
  int k;
  int b_firstColB;
  int iC;
  int b_c;
  int i;
  int b_i;
  int a_length;
  int r;
  unnamed_idx_0 = (signed char)arg1->size[0];
  unnamed_idx_1 = (signed char)arg1->size[1];
  firstRowA = c->size[0] * c->size[1];
  c->size[0] = unnamed_idx_0;
  emxEnsureCapacity((emxArray__common *)c, firstRowA, (int)sizeof(double));
  firstRowA = c->size[0] * c->size[1];
  c->size[1] = unnamed_idx_1;
  emxEnsureCapacity((emxArray__common *)c, firstRowA, (int)sizeof(double));
  aidx = unnamed_idx_0 * unnamed_idx_1;
  for (firstRowA = 0; firstRowA < aidx; firstRowA++) {
    c->data[firstRowA] = 0.0;
  }

  if ((arg1->size[0] == 0) || (arg1->size[1] == 0) || ((unnamed_idx_0 == 0) ||
       (unnamed_idx_1 == 0))) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    ma = arg1->size[0];
    na = arg1->size[1];
    if (arg1->size[1] < 2) {
      firstColB = 3 - arg1->size[1];
    } else {
      firstColB = 0;
    }

    if (5 <= unnamed_idx_1 + 1) {
      lastColB = 4;
    } else {
      lastColB = unnamed_idx_1 + 1;
    }

    if (arg1->size[0] < 2) {
      firstRowB = 3 - arg1->size[0];
    } else {
      firstRowB = 0;
    }

    if (5 <= unnamed_idx_0 + 1) {
      lastRowB = 4;
    } else {
      lastRowB = unnamed_idx_0 + 1;
    }

    while (firstColB <= lastColB) {
      if ((firstColB + na) - 1 < unnamed_idx_1 + 1) {
        lastColA = na - 1;
      } else {
        lastColA = (unnamed_idx_1 - firstColB) + 1;
      }

      if (firstColB < 2) {
        k = 2 - firstColB;
      } else {
        k = 0;
      }

      while (k <= lastColA) {
        if (firstColB + k > 2) {
          b_firstColB = (firstColB + k) - 2;
        } else {
          b_firstColB = 0;
        }

        iC = b_firstColB * unnamed_idx_0;
        b_c = k * ma;
        for (i = firstRowB; i <= lastRowB; i++) {
          if (i < 2) {
            firstRowA = 2 - i;
          } else {
            firstRowA = 0;
          }

          if (i + ma <= unnamed_idx_0 + 1) {
            b_i = ma;
          } else {
            b_i = (unnamed_idx_0 - i) + 2;
          }

          a_length = b_i - firstRowA;
          aidx = b_c + firstRowA;
          firstRowA = iC;
          for (r = 1; r <= a_length; r++) {
            c->data[firstRowA] += arg1->data[aidx];
            aidx++;
            firstRowA++;
          }

          if (i >= 2) {
            iC++;
          }
        }

        k++;
      }

      firstColB++;
    }
  }
}

//
// File trailer for conv2.cpp
//
// [EOF]
//
