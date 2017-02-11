/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_fcn_track_ccdp_fast_api.h
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jul-2016 17:02:06
 */

#ifndef ___CODER_FCN_TRACK_CCDP_FAST_API_H__
#define ___CODER_FCN_TRACK_CCDP_FAST_API_H__

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_fcn_track_ccdp_fast_api.h"

/* Type Definitions */
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

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void fcn_track_ccdp_fast(real_T pS[3], emxArray_struct0_T *pEst, real_T H,
  real_T T, struct1_T *ccdp, real_T threshold_track, struct3_T *costparam,
  emxArray_struct4_T *nextstate, real_T *uv_opt, real_T *uw_opt, emxArray_real_T
  *predict_s);
extern void fcn_track_ccdp_fast_api(const mxArray *prhs[8], const mxArray *plhs
  [3]);
extern void fcn_track_ccdp_fast_atexit(void);
extern void fcn_track_ccdp_fast_initialize(void);
extern void fcn_track_ccdp_fast_terminate(void);
extern void fcn_track_ccdp_fast_xil_terminate(void);

#endif

/*
 * File trailer for _coder_fcn_track_ccdp_fast_api.h
 *
 * [EOF]
 */
