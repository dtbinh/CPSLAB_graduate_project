/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fcn_track_ccdp_fast_types.h
 *
 * Code generation for function 'fcn_track_ccdp_fast'
 *
 */

#ifndef __FCN_TRACK_CCDP_FAST_TYPES_H__
#define __FCN_TRACK_CCDP_FAST_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_boolean_T_100x100
#define struct_emxArray_boolean_T_100x100

struct emxArray_boolean_T_100x100
{
  boolean_T data[10000];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_boolean_T_100x100*/

#ifndef typedef_emxArray_boolean_T_100x100
#define typedef_emxArray_boolean_T_100x100

typedef struct emxArray_boolean_T_100x100 emxArray_boolean_T_100x100;

#endif                                 /*typedef_emxArray_boolean_T_100x100*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  emxArray_real_T *mean;
  real_T sig;
  real_T prob;
  real_T M;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef struct_emxArray_struct0_T
#define struct_emxArray_struct0_T

struct emxArray_struct0_T
{
  struct0_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_struct0_T*/

#ifndef typedef_emxArray_struct0_T
#define typedef_emxArray_struct0_T

typedef struct emxArray_struct0_T emxArray_struct0_T;

#endif                                 /*typedef_emxArray_struct0_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  emxArray_real_T *sidxs;
  emxArray_real_T *dir;
} struct4_T;

#endif                                 /*typedef_struct4_T*/

#ifndef struct_emxArray_struct4_T
#define struct_emxArray_struct4_T

struct emxArray_struct4_T
{
  struct4_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_struct4_T*/

#ifndef typedef_emxArray_struct4_T
#define typedef_emxArray_struct4_T

typedef struct emxArray_struct4_T emxArray_struct4_T;

#endif                                 /*typedef_emxArray_struct4_T*/

#ifndef typedef_fcn_track_ccdp_fastStackData
#define typedef_fcn_track_ccdp_fastStackData

typedef struct {
  struct {
    boolean_T tmp_data[40000];
    int32_T b_tmp_data[10000];
    boolean_T c_tmp_data[40000];
    boolean_T x_data[40000];
  } f0;
} fcn_track_ccdp_fastStackData;

#endif                                 /*typedef_fcn_track_ccdp_fastStackData*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  emxArray_real_T *xs;
  emxArray_real_T *ys;
  real_T glen;
  emxArray_boolean_T_100x100 gmap;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T ndir;
  real_T gnum;
  real_T glen;
  emxArray_real_T *cc;
  emxArray_real_T *A;
} struct3_T;

#endif                                 /*typedef_struct3_T*/
#endif

/* End of code generation (fcn_track_ccdp_fast_types.h) */
