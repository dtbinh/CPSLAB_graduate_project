/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * conv2.c
 *
 * Code generation for function 'conv2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "conv2.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 15, "conv2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m"
};

static emlrtRSInfo sb_emlrtRSI = { 116, "conv2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m"
};

static emlrtRSInfo tb_emlrtRSI = { 128, "conv2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m"
};

static emlrtRTEInfo t_emlrtRTEI = { 1, 14, "conv2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\conv2.m"
};

/* Function Definitions */
void conv2(const emlrtStack *sp, const emxArray_real_T *arg1, emxArray_real_T *c)
{
  int8_T unnamed_idx_0;
  int8_T unnamed_idx_1;
  int32_T firstRowA;
  int32_T aidx;
  boolean_T b3;
  int32_T ma;
  int32_T na;
  int32_T firstColB;
  int32_T lastColB;
  int32_T firstRowB;
  int32_T lastRowB;
  int32_T lastColA;
  int32_T k;
  int32_T b_firstColB;
  int32_T iC;
  int32_T b_c;
  int32_T i;
  int32_T b_i;
  int32_T a_length;
  int32_T r;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &sb_emlrtRSI;
  unnamed_idx_0 = (int8_T)arg1->size[0];
  unnamed_idx_1 = (int8_T)arg1->size[1];
  c_st.site = &tb_emlrtRSI;
  firstRowA = c->size[0] * c->size[1];
  c->size[0] = unnamed_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)c, firstRowA, (int32_T)sizeof
                    (real_T), &t_emlrtRTEI);
  firstRowA = c->size[0] * c->size[1];
  c->size[1] = unnamed_idx_1;
  emxEnsureCapacity(&c_st, (emxArray__common *)c, firstRowA, (int32_T)sizeof
                    (real_T), &t_emlrtRTEI);
  aidx = unnamed_idx_0 * unnamed_idx_1;
  for (firstRowA = 0; firstRowA < aidx; firstRowA++) {
    c->data[firstRowA] = 0.0;
  }

  if ((arg1->size[0] == 0) || (arg1->size[1] == 0) || ((unnamed_idx_0 == 0) ||
       (unnamed_idx_1 == 0))) {
    b3 = true;
  } else {
    b3 = false;
  }

  if (!b3) {
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

/* End of code generation (conv2.c) */
