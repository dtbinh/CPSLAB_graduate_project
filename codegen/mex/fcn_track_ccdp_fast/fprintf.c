/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "fprintf.h"
#include "fcn_track_ccdp_fast_mexutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = { 35, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtMCInfo emlrtMCI = { 69, 14, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

static emlrtRSInfo kc_emlrtRSI = { 69, "fprintf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\iofun\\fprintf.m"
};

/* Function Declarations */
static real_T c_fprintf(const emlrtStack *sp);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);

/* Function Definitions */
static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i39;
  static const char_T cv1[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv11[2] = { 1, 7 };

  const mxArray *m0;
  static const char_T formatSpec[12] = { 'i', 'n', 'f', 'e', 'a', 's', 'i', 'b',
    'l', 'e', '\\', 'n' };

  char_T b_u[12];
  const mxArray *b_y;
  static const int32_T iv12[2] = { 1, 12 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i39 = 0; i39 < 7; i39++) {
    u[i39] = cv1[i39];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv11);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  for (i39 = 0; i39 < 12; i39++) {
    b_u[i39] = formatSpec[i39];
  }

  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv12);
  emlrtInitCharArrayR2013a(sp, 12, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  st.site = &kc_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, emlrt_marshallOut(1.0), b_y,
    &emlrtMCI), "feval");
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m3;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m3, 3, pArrays, "feval", true, location);
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jc_emlrtRSI;
  c_fprintf(&st);
}

/* End of code generation (fprintf.c) */
