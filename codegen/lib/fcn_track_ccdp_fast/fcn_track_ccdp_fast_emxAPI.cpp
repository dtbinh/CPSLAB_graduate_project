//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fcn_track_ccdp_fast_emxAPI.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "fcn_track_ccdp_fast_emxAPI.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreateND_real_T(int numDimensions, int *size)
{
  emxArray_real_T *emx;
  int numEl;
  int i;
  c_emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_struct0_T *
//
emxArray_struct0_T *emxCreateND_struct0_T(int numDimensions, int *size)
{
  emxArray_struct0_T *emx;
  int numEl;
  int i;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (struct0_T *)calloc((unsigned int)numEl, sizeof(struct0_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_struct4_T *
//
emxArray_struct4_T *emxCreateND_struct4_T(int numDimensions, int *size)
{
  emxArray_struct4_T *emx;
  int numEl;
  int i;
  emxInit_struct4_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (struct4_T *)calloc((unsigned int)numEl, sizeof(struct4_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : double *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreateWrapperND_real_T(double *data, int numDimensions, int *
  size)
{
  emxArray_real_T *emx;
  int numEl;
  int i;
  c_emxInit_real_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : struct0_T *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_struct0_T *
//
emxArray_struct0_T *emxCreateWrapperND_struct0_T(struct0_T *data, int
  numDimensions, int *size)
{
  emxArray_struct0_T *emx;
  int numEl;
  int i;
  emxInit_struct0_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : struct4_T *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_struct4_T *
//
emxArray_struct4_T *emxCreateWrapperND_struct4_T(struct4_T *data, int
  numDimensions, int *size)
{
  emxArray_struct4_T *emx;
  int numEl;
  int i;
  emxInit_struct4_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : double *data
//                int rows
//                int cols
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows, int cols)
{
  emxArray_real_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  c_emxInit_real_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : struct0_T *data
//                int rows
//                int cols
// Return Type  : emxArray_struct0_T *
//
emxArray_struct0_T *emxCreateWrapper_struct0_T(struct0_T *data, int rows, int
  cols)
{
  emxArray_struct0_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_struct0_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : struct4_T *data
//                int rows
//                int cols
// Return Type  : emxArray_struct4_T *
//
emxArray_struct4_T *emxCreateWrapper_struct4_T(struct4_T *data, int rows, int
  cols)
{
  emxArray_struct4_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_struct4_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_real_T *
//
emxArray_real_T *emxCreate_real_T(int rows, int cols)
{
  emxArray_real_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  c_emxInit_real_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (double *)calloc((unsigned int)numEl, sizeof(double));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_struct0_T *
//
emxArray_struct0_T *emxCreate_struct0_T(int rows, int cols)
{
  emxArray_struct0_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_struct0_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (struct0_T *)calloc((unsigned int)numEl, sizeof(struct0_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_struct4_T *
//
emxArray_struct4_T *emxCreate_struct4_T(int rows, int cols)
{
  emxArray_struct4_T *emx;
  int size[2];
  int numEl;
  int i;
  size[0] = rows;
  size[1] = cols;
  emxInit_struct4_T(&emx, 2);
  numEl = 1;
  for (i = 0; i < 2; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (struct4_T *)calloc((unsigned int)numEl, sizeof(struct4_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : emxArray_real_T *emxArray
// Return Type  : void
//
void emxDestroyArray_real_T(emxArray_real_T *emxArray)
{
  emxFree_real_T(&emxArray);
}

//
// Arguments    : emxArray_struct0_T *emxArray
// Return Type  : void
//
void emxDestroyArray_struct0_T(emxArray_struct0_T *emxArray)
{
  emxFree_struct0_T(&emxArray);
}

//
// Arguments    : emxArray_struct4_T *emxArray
// Return Type  : void
//
void emxDestroyArray_struct4_T(emxArray_struct4_T *emxArray)
{
  emxFree_struct4_T(&emxArray);
}

//
// Arguments    : struct1_T emxArray
// Return Type  : void
//
void emxDestroy_struct1_T(struct1_T emxArray)
{
  emxFreeStruct_struct1_T(&emxArray);
}

//
// Arguments    : struct3_T emxArray
// Return Type  : void
//
void emxDestroy_struct3_T(struct3_T emxArray)
{
  emxFreeStruct_struct3_T(&emxArray);
}

//
// Arguments    : emxArray_real_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions)
{
  c_emxInit_real_T(pEmxArray, numDimensions);
}

//
// Arguments    : emxArray_struct0_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_struct0_T(emxArray_struct0_T **pEmxArray, int numDimensions)
{
  emxInit_struct0_T(pEmxArray, numDimensions);
}

//
// Arguments    : emxArray_struct4_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInitArray_struct4_T(emxArray_struct4_T **pEmxArray, int numDimensions)
{
  emxInit_struct4_T(pEmxArray, numDimensions);
}

//
// Arguments    : struct1_T *pStruct
// Return Type  : void
//
void emxInit_struct1_T(struct1_T *pStruct)
{
  emxInitStruct_struct1_T(pStruct);
}

//
// Arguments    : struct3_T *pStruct
// Return Type  : void
//
void emxInit_struct3_T(struct3_T *pStruct)
{
  emxInitStruct_struct3_T(pStruct);
}

//
// File trailer for fcn_track_ccdp_fast_emxAPI.cpp
//
// [EOF]
//
