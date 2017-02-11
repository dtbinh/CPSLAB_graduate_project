//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bsxfun.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "bsxfun.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const emxArray_real_T *a
//                const emxArray_real_T *b
//                emxArray_boolean_T *c
// Return Type  : void
//
void b_bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
              emxArray_boolean_T *c)
{
  int na1;
  int nb1;
  int b_c;
  int c_c;
  int i9;
  int k;
  int bPageBack_idx_1;
  unsigned char unnamed_idx_0;
  double av_data[200];
  double bv_data[200];
  int asub[2];
  int bsub[2];
  int ak;
  int bk;
  int ck;
  boolean_T cv_data[200];
  na1 = a->size[0];
  nb1 = b->size[0];
  if (a->size[0] <= b->size[0]) {
    b_c = a->size[0];
  } else {
    b_c = b->size[0];
  }

  if (a->size[1] <= b->size[1]) {
    c_c = a->size[1];
  } else {
    c_c = b->size[1];
  }

  i9 = c->size[0] * c->size[1] * c->size[2];
  c->size[0] = b_c;
  c->size[1] = c_c;
  c->size[2] = a->size[2];
  emxEnsureCapacity((emxArray__common *)c, i9, (int)sizeof(boolean_T));
  k = a->size[2];
  if ((b_c == 0) || (c_c == 0) || (k == 0)) {
  } else {
    bPageBack_idx_1 = b->size[0] * b->size[1] - b->size[0];
    unnamed_idx_0 = (unsigned char)a->size[0];
    for (k = 0; k < 2; k++) {
      asub[k] = 1;
      bsub[k] = 1;
    }

    ak = 0;
    bk = 0;
    k = a->size[2];
    i9 = b_c * c_c * k - b_c;
    ck = 0;
    while ((b_c > 0) && (ck <= i9)) {
      for (k = 0; k + 1 <= na1; k++) {
        av_data[k] = a->data[ak + k];
      }

      for (k = 0; k + 1 <= nb1; k++) {
        bv_data[k] = b->data[bk + k];
      }

      k = unnamed_idx_0;
      for (c_c = 0; c_c < k; c_c++) {
        cv_data[c_c] = ((av_data[c_c] != 0.0) || (bv_data[c_c] != 0.0));
      }

      for (k = 0; k + 1 <= b_c; k++) {
        c->data[ck + k] = cv_data[k];
      }

      if (asub[0] < a->size[1]) {
        ak += na1;
        bk += nb1;
        bsub[0]++;
        asub[0]++;
      } else if (bsub[0] < b->size[1]) {
        bk += nb1;
        bsub[0]++;
      } else {
        asub[0] = 1;
        bsub[0] = 1;
        if (asub[1] < a->size[2]) {
          ak += na1;
          bk -= bPageBack_idx_1;
          asub[1]++;
        } else {
          asub[1] = 1;
        }
      }

      ck += b_c;
    }
  }
}

//
// Arguments    : const emxArray_real_T *a
//                const emxArray_real_T *b
//                emxArray_real_T *c
// Return Type  : void
//
void bsxfun(const emxArray_real_T *a, const emxArray_real_T *b, emxArray_real_T *
            c)
{
  int na1;
  int b_c;
  int i7;
  int k;
  emxArray_real_T *av;
  emxArray_real_T *bv;
  int asub;
  int ak;
  int ck;
  emxArray_real_T *cv;
  int loop_ub;
  na1 = a->size[0];
  if (a->size[0] <= b->size[0]) {
    b_c = a->size[0];
  } else {
    b_c = b->size[0];
  }

  i7 = c->size[0] * c->size[1];
  c->size[0] = b_c;
  c->size[1] = a->size[1];
  emxEnsureCapacity((emxArray__common *)c, i7, (int)sizeof(double));
  k = a->size[1];
  if ((b_c == 0) || (k == 0)) {
  } else {
    d_emxInit_real_T(&av, 1);
    d_emxInit_real_T(&bv, 1);
    k = a->size[0];
    i7 = av->size[0];
    av->size[0] = k;
    emxEnsureCapacity((emxArray__common *)av, i7, (int)sizeof(double));
    k = b->size[0];
    i7 = bv->size[0];
    bv->size[0] = k;
    emxEnsureCapacity((emxArray__common *)bv, i7, (int)sizeof(double));
    asub = 1;
    ak = 0;
    k = a->size[1];
    i7 = b_c * k - b_c;
    ck = 0;
    d_emxInit_real_T(&cv, 1);
    while ((b_c > 0) && (ck <= i7)) {
      for (k = 0; k + 1 <= na1; k++) {
        av->data[k] = a->data[ak + k];
      }

      for (k = 0; k + 1 <= b->size[0]; k++) {
        bv->data[k] = b->data[k];
      }

      k = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity((emxArray__common *)cv, k, (int)sizeof(double));
      loop_ub = av->size[0];
      for (k = 0; k < loop_ub; k++) {
        cv->data[k] = av->data[k] + bv->data[k];
      }

      for (k = 0; k + 1 <= b_c; k++) {
        c->data[ck + k] = cv->data[k];
      }

      if (asub < a->size[1]) {
        ak += na1;
        asub++;
      } else {
        asub = 1;
      }

      ck += b_c;
    }

    emxFree_real_T(&cv);
    emxFree_real_T(&bv);
    emxFree_real_T(&av);
  }
}

//
// Arguments    : const emxArray_real_T *a
//                const emxArray_real_T *b
//                emxArray_real_T *c
// Return Type  : void
//
void c_bsxfun(const emxArray_real_T *a, const emxArray_real_T *b,
              emxArray_real_T *c)
{
  int na1;
  int nb1;
  int b_c;
  int c_c;
  int i10;
  int k;
  int bPageBack_idx_1;
  unsigned char unnamed_idx_0;
  double av_data[200];
  double bv_data[200];
  int asub[2];
  int bsub[2];
  int ak;
  int bk;
  int ck;
  double cv_data[200];
  na1 = a->size[0];
  nb1 = b->size[0];
  if (a->size[0] <= b->size[0]) {
    b_c = a->size[0];
  } else {
    b_c = b->size[0];
  }

  if (a->size[1] <= b->size[1]) {
    c_c = a->size[1];
  } else {
    c_c = b->size[1];
  }

  i10 = c->size[0] * c->size[1] * c->size[2];
  c->size[0] = b_c;
  c->size[1] = c_c;
  c->size[2] = a->size[2];
  emxEnsureCapacity((emxArray__common *)c, i10, (int)sizeof(double));
  k = a->size[2];
  if ((b_c == 0) || (c_c == 0) || (k == 0)) {
  } else {
    bPageBack_idx_1 = b->size[0] * b->size[1] - b->size[0];
    unnamed_idx_0 = (unsigned char)a->size[0];
    for (k = 0; k < 2; k++) {
      asub[k] = 1;
      bsub[k] = 1;
    }

    ak = 0;
    bk = 0;
    k = a->size[2];
    i10 = b_c * c_c * k - b_c;
    ck = 0;
    while ((b_c > 0) && (ck <= i10)) {
      for (k = 0; k + 1 <= na1; k++) {
        av_data[k] = a->data[ak + k];
      }

      for (k = 0; k + 1 <= nb1; k++) {
        bv_data[k] = b->data[bk + k];
      }

      k = unnamed_idx_0;
      for (c_c = 0; c_c < k; c_c++) {
        cv_data[c_c] = av_data[c_c] + bv_data[c_c];
      }

      for (k = 0; k + 1 <= b_c; k++) {
        c->data[ck + k] = cv_data[k];
      }

      if (asub[0] < a->size[1]) {
        ak += na1;
        bk += nb1;
        bsub[0]++;
        asub[0]++;
      } else if (bsub[0] < b->size[1]) {
        bk += nb1;
        bsub[0]++;
      } else {
        asub[0] = 1;
        bsub[0] = 1;
        if (asub[1] < a->size[2]) {
          ak += na1;
          bk -= bPageBack_idx_1;
          asub[1]++;
        } else {
          asub[1] = 1;
        }
      }

      ck += b_c;
    }
  }
}

//
// File trailer for bsxfun.cpp
//
// [EOF]
//
