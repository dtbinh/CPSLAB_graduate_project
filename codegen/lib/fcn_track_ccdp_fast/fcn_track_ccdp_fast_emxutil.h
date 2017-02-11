//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fcn_track_ccdp_fast_emxutil.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//
#ifndef __FCN_TRACK_CCDP_FAST_EMXUTIL_H__
#define __FCN_TRACK_CCDP_FAST_EMXUTIL_H__

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
extern void b_emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void b_emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void c_emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void d_emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, int
  elementSize);
extern void emxFreeStruct_struct1_T(struct1_T *pStruct);
extern void emxFreeStruct_struct3_T(struct3_T *pStruct);
extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);
extern void emxFree_struct4_T(emxArray_struct4_T **pEmxArray);
extern void emxInitStruct_struct1_T(struct1_T *pStruct);
extern void emxInitStruct_struct3_T(struct3_T *pStruct);
extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray, int numDimensions);
extern void emxInit_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);
extern void emxInit_struct0_T(emxArray_struct0_T **pEmxArray, int numDimensions);
extern void emxInit_struct4_T(emxArray_struct4_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for fcn_track_ccdp_fast_emxutil.h
//
// [EOF]
//
