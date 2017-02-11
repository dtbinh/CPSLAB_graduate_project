/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * scalexpAlloc.h
 *
 * Code generation for function 'scalexpAlloc'
 *
 */

#ifndef __SCALEXPALLOC_H__
#define __SCALEXPALLOC_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "fcn_track_ccdp_fast_types.h"

/* Function Declarations */
extern boolean_T b_dimagree(const emxArray_real_T *z, const emxArray_real_T
  *varargin_1, const emxArray_real_T *varargin_2);
extern boolean_T c_dimagree(const emxArray_real_T *z, const emxArray_real_T
  *varargin_1);
extern boolean_T dimagree(const emxArray_real_T *z, const emxArray_real_T
  *varargin_1);

#endif

/* End of code generation (scalexpAlloc.h) */
