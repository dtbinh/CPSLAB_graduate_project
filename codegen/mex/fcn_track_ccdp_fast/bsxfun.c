/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bsxfun.c
 *
 * Code generation for function 'bsxfun'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "bsxfun.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "fcn_track_ccdp_fast_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = { 97, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRSInfo hb_emlrtRSI = { 91, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRSInfo ib_emlrtRSI = { 87, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRSInfo jb_emlrtRSI = { 85, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo o_emlrtRTEI = { 1, 14, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo p_emlrtRTEI = { 75, 1, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 76, 1, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo r_emlrtRTEI = { 95, 5, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo kb_emlrtRTEI = { 19, 23, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

static emlrtRTEInfo lb_emlrtRTEI = { 21, 23, "bsxfun",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m"
};

/* Function Definitions */
void b_bsxfun(const emlrtStack *sp, const emxArray_real_T *a, const
              emxArray_real_T *b, emxArray_boolean_T *c)
{
  int32_T na1;
  int32_T nb1;
  boolean_T overflow;
  int32_T b_c;
  int32_T c_c;
  int32_T i36;
  int32_T k;
  int32_T bPageBack_idx_1;
  uint8_T unnamed_idx_0;
  real_T av_data[200];
  real_T bv_data[200];
  int32_T asub[2];
  int32_T bsub[2];
  int32_T ak;
  int32_T bk;
  int32_T ck;
  boolean_T cv_data[200];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  na1 = a->size[0];
  nb1 = b->size[0];
  if ((a->size[0] != 1) && (b->size[0] != 1) && (a->size[0] != b->size[0])) {
    overflow = false;
  } else if ((a->size[1] != 1) && (b->size[1] != 1) && (a->size[1] != b->size[1]))
  {
    overflow = false;
  } else {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &kb_emlrtRTEI,
      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }

  if (a->size[0] != b->size[0]) {
    overflow = false;
  } else if (a->size[1] != b->size[1]) {
    overflow = false;
  } else {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &lb_emlrtRTEI,
      "Coder:toolbox:bsxfun_dynamicExpansion", 0);
  }

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

  i36 = c->size[0] * c->size[1] * c->size[2];
  c->size[0] = b_c;
  c->size[1] = c_c;
  c->size[2] = a->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)c, i36, (int32_T)sizeof(boolean_T),
                    &o_emlrtRTEI);
  k = a->size[2];
  if ((b_c == 0) || (c_c == 0) || (k == 0)) {
  } else {
    bPageBack_idx_1 = b->size[0] * b->size[1] - b->size[0];
    unnamed_idx_0 = (uint8_T)a->size[0];
    for (k = 0; k < 2; k++) {
      asub[k] = 1;
      bsub[k] = 1;
    }

    ak = 0;
    bk = 0;
    k = a->size[2];
    c_c = b_c * c_c * k - b_c;
    st.site = &jb_emlrtRSI;
    if ((b_c == 0) || (0 > c_c)) {
      overflow = false;
    } else {
      overflow = (c_c > MAX_int32_T - b_c);
    }

    if (overflow) {
      b_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    ck = 0;
    while ((b_c > 0) && (ck <= c_c)) {
      st.site = &ib_emlrtRSI;
      for (k = 0; k + 1 <= na1; k++) {
        av_data[k] = a->data[ak + k];
      }

      st.site = &hb_emlrtRSI;
      for (k = 0; k + 1 <= nb1; k++) {
        bv_data[k] = b->data[bk + k];
      }

      k = unnamed_idx_0;
      for (i36 = 0; i36 < k; i36++) {
        cv_data[i36] = ((av_data[i36] != 0.0) || (bv_data[i36] != 0.0));
      }

      st.site = &gb_emlrtRSI;
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

void bsxfun(const emlrtStack *sp, const emxArray_real_T *a, const
            emxArray_real_T *b, emxArray_real_T *c)
{
  int32_T na1;
  int32_T nb1;
  boolean_T overflow;
  int32_T b_c;
  int32_T i33;
  int32_T k;
  emxArray_real_T *av;
  emxArray_real_T *bv;
  int32_T asub;
  int32_T ak;
  int32_T b_b;
  int32_T ck;
  emxArray_real_T *cv;
  boolean_T b0;
  boolean_T b1;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  na1 = a->size[0];
  nb1 = b->size[0];
  if ((a->size[0] != 1) && (b->size[0] != 1) && (a->size[0] != b->size[0])) {
    overflow = false;
  } else {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &kb_emlrtRTEI,
      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }

  overflow = !(a->size[0] != b->size[0]);
  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &lb_emlrtRTEI,
      "Coder:toolbox:bsxfun_dynamicExpansion", 0);
  }

  if (a->size[0] <= b->size[0]) {
    b_c = a->size[0];
  } else {
    b_c = b->size[0];
  }

  i33 = c->size[0] * c->size[1];
  c->size[0] = b_c;
  c->size[1] = a->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)c, i33, (int32_T)sizeof(real_T),
                    &o_emlrtRTEI);
  k = a->size[1];
  if ((b_c == 0) || (k == 0)) {
  } else {
    d_emxInit_real_T(sp, &av, 1, &p_emlrtRTEI, true);
    d_emxInit_real_T(sp, &bv, 1, &q_emlrtRTEI, true);
    k = a->size[0];
    i33 = av->size[0];
    av->size[0] = k;
    emxEnsureCapacity(sp, (emxArray__common *)av, i33, (int32_T)sizeof(real_T),
                      &o_emlrtRTEI);
    k = b->size[0];
    i33 = bv->size[0];
    bv->size[0] = k;
    emxEnsureCapacity(sp, (emxArray__common *)bv, i33, (int32_T)sizeof(real_T),
                      &o_emlrtRTEI);
    asub = 1;
    ak = 0;
    k = a->size[1];
    b_b = b_c * k - b_c;
    st.site = &jb_emlrtRSI;
    if ((b_c == 0) || (0 > b_b)) {
      overflow = false;
    } else {
      overflow = (b_b > MAX_int32_T - b_c);
    }

    if (overflow) {
      b_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    ck = 0;
    d_emxInit_real_T(sp, &cv, 1, &r_emlrtRTEI, true);
    while ((b_c > 0) && (ck <= b_b)) {
      st.site = &ib_emlrtRSI;
      if (1 > na1) {
        b0 = false;
      } else {
        b0 = (na1 > 2147483646);
      }

      if (b0) {
        b_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (k = 0; k + 1 <= na1; k++) {
        av->data[k] = a->data[ak + k];
      }

      st.site = &hb_emlrtRSI;
      if (1 > nb1) {
        b1 = false;
      } else {
        b1 = (nb1 > 2147483646);
      }

      if (b1) {
        b_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (k = 0; k + 1 <= nb1; k++) {
        bv->data[k] = b->data[k];
      }

      i33 = cv->size[0];
      cv->size[0] = av->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)cv, i33, (int32_T)sizeof(real_T),
                        &o_emlrtRTEI);
      k = av->size[0];
      for (i33 = 0; i33 < k; i33++) {
        cv->data[i33] = av->data[i33] + bv->data[i33];
      }

      st.site = &gb_emlrtRSI;
      if (b_c > 2147483646) {
        b_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&b_st);
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

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_bsxfun(const emlrtStack *sp, const emxArray_real_T *a, const
              emxArray_real_T *b, emxArray_real_T *c)
{
  int32_T na1;
  int32_T nb1;
  boolean_T overflow;
  int32_T b_c;
  int32_T c_c;
  int32_T i37;
  int32_T k;
  int32_T bPageBack_idx_1;
  uint8_T unnamed_idx_0;
  real_T av_data[200];
  real_T bv_data[200];
  int32_T asub[2];
  int32_T bsub[2];
  int32_T ak;
  int32_T bk;
  int32_T ck;
  real_T cv_data[200];
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  na1 = a->size[0];
  nb1 = b->size[0];
  if ((a->size[0] != 1) && (b->size[0] != 1) && (a->size[0] != b->size[0])) {
    overflow = false;
  } else if ((a->size[1] != 1) && (b->size[1] != 1) && (a->size[1] != b->size[1]))
  {
    overflow = false;
  } else {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &kb_emlrtRTEI,
      "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }

  if (a->size[0] != b->size[0]) {
    overflow = false;
  } else if (a->size[1] != b->size[1]) {
    overflow = false;
  } else {
    overflow = true;
  }

  if (overflow) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &lb_emlrtRTEI,
      "Coder:toolbox:bsxfun_dynamicExpansion", 0);
  }

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

  i37 = c->size[0] * c->size[1] * c->size[2];
  c->size[0] = b_c;
  c->size[1] = c_c;
  c->size[2] = a->size[2];
  emxEnsureCapacity(sp, (emxArray__common *)c, i37, (int32_T)sizeof(real_T),
                    &o_emlrtRTEI);
  k = a->size[2];
  if ((b_c == 0) || (c_c == 0) || (k == 0)) {
  } else {
    bPageBack_idx_1 = b->size[0] * b->size[1] - b->size[0];
    unnamed_idx_0 = (uint8_T)a->size[0];
    for (k = 0; k < 2; k++) {
      asub[k] = 1;
      bsub[k] = 1;
    }

    ak = 0;
    bk = 0;
    k = a->size[2];
    c_c = b_c * c_c * k - b_c;
    st.site = &jb_emlrtRSI;
    if ((b_c == 0) || (0 > c_c)) {
      overflow = false;
    } else {
      overflow = (c_c > MAX_int32_T - b_c);
    }

    if (overflow) {
      b_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }

    ck = 0;
    while ((b_c > 0) && (ck <= c_c)) {
      st.site = &ib_emlrtRSI;
      for (k = 0; k + 1 <= na1; k++) {
        av_data[k] = a->data[ak + k];
      }

      st.site = &hb_emlrtRSI;
      for (k = 0; k + 1 <= nb1; k++) {
        bv_data[k] = b->data[bk + k];
      }

      k = unnamed_idx_0;
      for (i37 = 0; i37 < k; i37++) {
        cv_data[i37] = av_data[i37] + bv_data[i37];
      }

      st.site = &gb_emlrtRSI;
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

/* End of code generation (bsxfun.c) */
