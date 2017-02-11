/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * atan2.c
 *
 * Code generation for function 'atan2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "atan2.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include "scalexpAlloc.h"
#include "fcn_track_ccdp_fast_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo s_emlrtRSI = { 17, "atan2",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elfun\\atan2.m"
};

/* Function Declarations */
static void b_eml_scalexp_alloc(const emlrtStack *sp, const emxArray_real_T
  *varargin_1, const emxArray_real_T *varargin_2, emxArray_real_T *z);

/* Function Definitions */
static void b_eml_scalexp_alloc(const emlrtStack *sp, const emxArray_real_T
  *varargin_1, const emxArray_real_T *varargin_2, emxArray_real_T *z)
{
  int32_T c;
  int32_T b_c;
  int32_T i32;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &r_emlrtRSI;
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

  i32 = z->size[0] * z->size[1];
  z->size[0] = c;
  z->size[1] = b_c;
  emxEnsureCapacity(&st, (emxArray__common *)z, i32, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  if (b_dimagree(z, varargin_1, varargin_2)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &n_emlrtRTEI, "MATLAB:dimagree", 0);
  }
}

void b_atan2(const emlrtStack *sp, const emxArray_real_T *y, const
             emxArray_real_T *x, emxArray_real_T *r)
{
  int32_T i31;
  int32_T k;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  b_eml_scalexp_alloc(&st, y, x, r);
  i31 = r->size[0] * r->size[1];
  for (k = 0; k < i31; k++) {
    r->data[k] = muDoubleScalarAtan2(y->data[k], x->data[k]);
  }
}

/* End of code generation (atan2.c) */
