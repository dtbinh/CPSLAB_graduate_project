/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "abs.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo v_emlrtRTEI = { 1, 14, "abs",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" };

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  uint8_T uv2[2];
  int32_T i38;
  int32_T k;
  for (i38 = 0; i38 < 2; i38++) {
    uv2[i38] = (uint8_T)x->size[i38];
  }

  i38 = y->size[0] * y->size[1];
  y->size[0] = uv2[0];
  y->size[1] = uv2[1];
  emxEnsureCapacity(sp, (emxArray__common *)y, i38, (int32_T)sizeof(real_T),
                    &v_emlrtRTEI);
  i38 = x->size[0] * x->size[1];
  for (k = 0; k < i38; k++) {
    y->data[k] = muDoubleScalarAbs(x->data[k]);
  }
}

/* End of code generation (abs.c) */
