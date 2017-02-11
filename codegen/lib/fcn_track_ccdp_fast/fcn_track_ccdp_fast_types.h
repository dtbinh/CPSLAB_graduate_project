//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fcn_track_ccdp_fast_types.h
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//
#ifndef __FCN_TRACK_CCDP_FAST_TYPES_H__
#define __FCN_TRACK_CCDP_FAST_TYPES_H__

// Include Files
#include "rtwtypes.h"

// Type Definitions
#include <stdio.h>
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray__common

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_boolean_T

#ifndef struct_emxArray_boolean_T_100x100
#define struct_emxArray_boolean_T_100x100

struct emxArray_boolean_T_100x100
{
  boolean_T data[10000];
  int size[2];
};

#endif                                 //struct_emxArray_boolean_T_100x100

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_int32_T

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_real_T

typedef struct {
  emxArray_real_T *mean;
  double sig;
  double prob;
  double M;
} struct0_T;

#ifndef struct_emxArray_struct0_T
#define struct_emxArray_struct0_T

struct emxArray_struct0_T
{
  struct0_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_struct0_T

typedef struct {
  emxArray_real_T *sidxs;
  emxArray_real_T *dir;
} struct4_T;

#ifndef struct_emxArray_struct4_T
#define struct_emxArray_struct4_T

struct emxArray_struct4_T
{
  struct4_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 //struct_emxArray_struct4_T

typedef struct {
  emxArray_real_T *xs;
  emxArray_real_T *ys;
  double glen;
  emxArray_boolean_T_100x100 gmap;
} struct1_T;

typedef struct {
  double ndir;
  double gnum;
  double glen;
  emxArray_real_T *cc;
  emxArray_real_T *A;
} struct3_T;

#endif

//
// File trailer for fcn_track_ccdp_fast_types.h
//
// [EOF]
//
