//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fcn_track_ccdp_fast_emxAPI.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//
#ifndef __FCN_TRACK_CCDP_FAST_EMXAPI_H__
#define __FCN_TRACK_CCDP_FAST_EMXAPI_H__

// Include Files
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "fcn_track_ccdp_fast_types.h"

// Function Declarations
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size);
extern emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions, int *size);
extern emxArray_struct4_T *emxCreateND_struct4_T(int numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapperND_real_T(double *data, int
  numDimensions, int *size);
extern emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data, int
  numDimensions, int *size);
extern emxArray_struct4_T *emxCreateWrapperND_struct4_T(struct4_T *data, int
  numDimensions, int *size);
extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols);
extern emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows,
  int cols);
extern emxArray_struct4_T *emxCreateWrapper_struct4_T(struct4_T *data, int rows,
  int cols);
extern emxArray_real_T *emxCreate_real_T(int rows, int cols);
extern emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols);
extern emxArray_struct4_T *emxCreate_struct4_T(int rows, int cols);
extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);
extern void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray);
extern void emxDestroyArray_struct4_T(emxArray_struct4_T *emxArray);
extern void emxDestroy_struct1_T(struct1_T emxArray);
extern void emxDestroy_struct3_T(struct3_T emxArray);
extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray, int
  numDimensions);
extern void emxInitArray_struct4_T(emxArray_struct4_T **pEmxArray, int
  numDimensions);
extern void emxInit_struct1_T(struct1_T *pStruct);
extern void emxInit_struct3_T(struct3_T *pStruct);

#endif

//
// File trailer for fcn_track_ccdp_fast_emxAPI.h
//
// [EOF]
//
