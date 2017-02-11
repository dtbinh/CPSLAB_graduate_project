/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "mean.h"
#include <stdio.h>

/* Function Definitions */
real_T mean(const real_T x[2])
{
  return (x[0] + x[1]) / 2.0;
}

/* End of code generation (mean.c) */
