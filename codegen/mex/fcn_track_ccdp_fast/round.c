/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * round.c
 *
 * Code generation for function 'round'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "round.h"
#include <stdio.h>

/* Function Definitions */
void b_round(emxArray_real_T *x)
{
  int32_T i47;
  int32_T k;
  i47 = x->size[0] * x->size[1];
  for (k = 0; k < i47; k++) {
    x->data[k] = muDoubleScalarRound(x->data[k]);
  }
}

void c_round(real_T x[2])
{
  int32_T k;
  for (k = 0; k < 2; k++) {
    x[k] = muDoubleScalarRound(x[k]);
  }
}

/* End of code generation (round.c) */
