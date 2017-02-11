/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "power.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include "scalexpAlloc.h"
#include "fcn_track_ccdp_fast_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo p_emlrtRSI = { 42, "power",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

static emlrtRSInfo q_emlrtRSI = { 51, "power",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\power.m" };

/* Function Declarations */
static void eml_scalexp_alloc(const emlrtStack *sp, const emxArray_real_T
  *varargin_1, emxArray_real_T *z);

/* Function Definitions */
static void eml_scalexp_alloc(const emlrtStack *sp, const emxArray_real_T
  *varargin_1, emxArray_real_T *z)
{
  uint8_T uv0[2];
  int32_T i30;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
  for (i30 = 0; i30 < 2; i30++) {
    uv0[i30] = (uint8_T)varargin_1->size[i30];
  }

  i30 = z->size[0] * z->size[1];
  z->size[0] = uv0[0];
  z->size[1] = uv0[1];
  emxEnsureCapacity(&st, (emxArray__common *)z, i30, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  if (dimagree(z, varargin_1)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &n_emlrtRTEI, "MATLAB:dimagree", 0);
  }
}

void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  int32_T i29;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &q_emlrtRSI;
  eml_scalexp_alloc(&b_st, a, y);
  i29 = y->size[0] * y->size[1];
  for (k = 0; k < i29; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }
}

/* End of code generation (power.c) */
