/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_fcn_track_ccdp_fast_api.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Jul-2016 17:02:06
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_fcn_track_ccdp_fast_api.h"

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

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL,
  "fcn_track_ccdp_fast", NULL, false, { 2045744189U, 2170104910U, 2743257031U,
    4284093946U }, NULL };

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void b_emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, boolean_T ret_data[], int32_T ret_size[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pEst, const
  char_T *identifier, emxArray_struct0_T *y);
static void c_emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *pS, const
  char_T *identifier))[3];
static const mxArray *emlrt_marshallOut(const real_T u);
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize);
static void emxEnsureCapacity_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  *emxArray, int32_T oldNumel);
static void emxEnsureCapacity_struct4_T(const emlrtStack *sp, emxArray_struct4_T
  *emxArray, int32_T oldNumel);
static void emxExpand_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  *emxArray, int32_T fromIndex, int32_T toIndex);
static void emxExpand_struct4_T(const emlrtStack *sp, emxArray_struct4_T
  *emxArray, int32_T fromIndex, int32_T toIndex);
static void emxFreeStruct_struct0_T(struct0_T *pStruct);
static void emxFreeStruct_struct1_T(struct1_T *pStruct);
static void emxFreeStruct_struct3_T(struct3_T *pStruct);
static void emxFreeStruct_struct4_T(struct4_T *pStruct);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxFree_struct0_T(emxArray_struct0_T **pEmxArray);
static void emxFree_struct4_T(emxArray_struct4_T **pEmxArray);
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct,
  boolean_T doPush);
static void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
  boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxInit_struct4_T(const emlrtStack *sp, emxArray_struct4_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush);
static void emxTrim_struct0_T(emxArray_struct0_T *emxArray, int32_T fromIndex,
  int32_T toIndex);
static void emxTrim_struct4_T(emxArray_struct4_T *emxArray, int32_T fromIndex,
  int32_T toIndex);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *H, const
  char_T *identifier);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ccdp, const
  char_T *identifier, struct1_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, boolean_T y_data[], int32_T y_size[2]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *costparam,
  const char_T *identifier, struct3_T *y);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nextstate,
  const char_T *identifier, emxArray_struct4_T *y);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct4_T *y);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : void
 */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  int32_T iv8[2];
  int32_T i;
  for (i = 0; i < 2; i++) {
    iv8[i] = 0;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv8);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = v_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
  static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv2[2] = { 0, 0 };

  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)u->data);
  emlrtSetDimensions((mxArray *)m1, u->size, 2);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void b_emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                boolean_T ret_data[]
 *                int32_T ret_size[2]
 * Return Type  : void
 */
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, boolean_T ret_data[], int32_T ret_size[2])
{
  int32_T iv9[2];
  int32_T i;
  int32_T iv10[2];
  boolean_T bv4[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv9[i] = 100;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "logical", false, 2U, iv9, &bv4[0],
    iv10);
  ret_size[0] = iv10[0];
  ret_size[1] = iv10[1];
  emlrtImportArrayR2011b(src, (void *)ret_data, 1, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *pEst
 *                const char_T *identifier
 *                emxArray_struct0_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pEst, const
  char_T *identifier, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  d_emlrt_marshallIn(sp, emlrtAlias(pEst), &thisId, y);
  emlrtDestroyArray(&pEst);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void c_emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv11[1];
  boolean_T bv5[1] = { true };

  static const int32_T iv12[1] = { -1 };

  int32_T i3;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv12, &bv5[0],
    iv11);
  i3 = ret->size[0];
  ret->size[0] = iv11[0];
  emxEnsureCapacity((emxArray__common *)ret, i3, (int32_T)sizeof(real_T));
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_struct0_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv0[2];
  int32_T i0;
  int32_T sizes[2];
  boolean_T bv0[2] = { false, true };

  static const char * fieldNames[4] = { "mean", "sig", "prob", "M" };

  int32_T n;
  thisId.fParent = parentId;
  for (i0 = 0; i0 < 2; i0++) {
    iv0[i0] = 1 + -2 * i0;
  }

  emlrtCheckVsStructR2012b(sp, parentId, u, 4, fieldNames, 2U, iv0, &bv0[0],
    sizes);
  i0 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct0_T(sp, y, i0);
  n = y->size[1];
  for (i0 = 0; i0 < n; i0++) {
    thisId.fIdentifier = "mean";
    e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, i0, "mean")),
                       &thisId, y->data[i0].mean);
    thisId.fIdentifier = "sig";
    y->data[i0].sig = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
      u, i0, "sig")), &thisId);
    thisId.fIdentifier = "prob";
    y->data[i0].prob = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
      u, i0, "prob")), &thisId);
    thisId.fIdentifier = "M";
    y->data[i0].M = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
      i0, "M")), &thisId);
  }

  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv13[3];
  boolean_T bv6[3] = { true, false, true };

  static const int32_T iv14[3] = { -1, 2, -1 };

  int32_T i4;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv14, &bv6[0],
    iv13);
  i4 = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv13[0];
  ret->size[1] = iv13[1];
  ret->size[2] = iv13[2];
  emxEnsureCapacity((emxArray__common *)ret, i4, (int32_T)sizeof(real_T));
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv15[2];
  int32_T i5;
  int32_T iv16[2];
  boolean_T bv7[2] = { true, false };

  for (i5 = 0; i5 < 2; i5++) {
    iv15[i5] = 3 * i5 - 1;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv15, &bv7[0],
    iv16);
  i5 = ret->size[0] * ret->size[1];
  ret->size[0] = iv16[0];
  ret->size[1] = iv16[1];
  emxEnsureCapacity((emxArray__common *)ret, i5, (int32_T)sizeof(real_T));
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *pS
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *pS, const
  char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(pS), &thisId);
  emlrtDestroyArray(&pS);
  return y;
}
/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
  static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : emxArray__common *emxArray
 *                int32_T oldNumel
 *                int32_T elementSize
 * Return Type  : void
 */
static void emxEnsureCapacity(emxArray__common *emxArray, int32_T oldNumel,
  int32_T elementSize)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      i <<= 1;
    }

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct0_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  *emxArray, int32_T oldNumel)
{
  int32_T elementSize;
  int32_T newNumel;
  int32_T i;
  void *newData;
  elementSize = (int32_T)sizeof(struct0_T);
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      i <<= 1;
    }

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex((void *)emxArray->data);
      }
    }

    emxArray->data = (struct0_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct0_T(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct0_T(sp, emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct4_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_struct4_T(const emlrtStack *sp, emxArray_struct4_T
  *emxArray, int32_T oldNumel)
{
  int32_T elementSize;
  int32_T newNumel;
  int32_T i;
  void *newData;
  elementSize = (int32_T)sizeof(struct4_T);
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      i <<= 1;
    }

    newData = emlrtCallocMex((uint32_T)i, (uint32_T)elementSize);
    if (emxArray->data != NULL) {
      memcpy(newData, (void *)emxArray->data, (uint32_T)(elementSize * oldNumel));
      if (emxArray->canFreeData) {
        emlrtFreeMex((void *)emxArray->data);
      }
    }

    emxArray->data = (struct4_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }

  if (oldNumel > newNumel) {
    emxTrim_struct4_T(emxArray, newNumel, oldNumel);
  } else {
    if (oldNumel < newNumel) {
      emxExpand_struct4_T(sp, emxArray, oldNumel, newNumel);
    }
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct0_T *emxArray
 *                int32_T fromIndex
 *                int32_T toIndex
 * Return Type  : void
 */
static void emxExpand_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  *emxArray, int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct0_T(sp, &emxArray->data[i], false);
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct4_T *emxArray
 *                int32_T fromIndex
 *                int32_T toIndex
 * Return Type  : void
 */
static void emxExpand_struct4_T(const emlrtStack *sp, emxArray_struct4_T
  *emxArray, int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_struct4_T(sp, &emxArray->data[i], false);
  }
}

/*
 * Arguments    : struct0_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct0_T(struct0_T *pStruct)
{
  emxFree_real_T(&pStruct->mean);
}

/*
 * Arguments    : struct1_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct1_T(struct1_T *pStruct)
{
  emxFree_real_T(&pStruct->xs);
  emxFree_real_T(&pStruct->ys);
}

/*
 * Arguments    : struct3_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct3_T(struct3_T *pStruct)
{
  emxFree_real_T(&pStruct->cc);
  emxFree_real_T(&pStruct->A);
}

/*
 * Arguments    : struct4_T *pStruct
 * Return Type  : void
 */
static void emxFreeStruct_struct4_T(struct4_T *pStruct)
{
  emxFree_real_T(&pStruct->sidxs);
  emxFree_real_T(&pStruct->dir);
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_struct0_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_struct0_T(emxArray_struct0_T **pEmxArray)
{
  int32_T numEl;
  int32_T i;
  if (*pEmxArray != (emxArray_struct0_T *)NULL) {
    if ((*pEmxArray)->data != (struct0_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct0_T(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((void *)(*pEmxArray)->data);
      }
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_struct0_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_struct4_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_struct4_T(emxArray_struct4_T **pEmxArray)
{
  int32_T numEl;
  int32_T i;
  if (*pEmxArray != (emxArray_struct4_T *)NULL) {
    if ((*pEmxArray)->data != (struct4_T *)NULL) {
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }

      for (i = 0; i < numEl; i++) {
        emxFreeStruct_struct4_T(&(*pEmxArray)->data[i]);
      }

      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((void *)(*pEmxArray)->data);
      }
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_struct4_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct0_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->mean, 2, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct1_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct1_T(const emlrtStack *sp, struct1_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->xs, 2, doPush);
  emxInit_real_T(sp, &pStruct->ys, 2, doPush);
  pStruct->gmap.size[0] = 0;
  pStruct->gmap.size[1] = 0;
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct3_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct3_T(const emlrtStack *sp, struct3_T *pStruct,
  boolean_T doPush)
{
  b_emxInit_real_T(sp, &pStruct->cc, 1, doPush);
  c_emxInit_real_T(sp, &pStruct->A, 3, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                struct4_T *pStruct
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInitStruct_struct4_T(const emlrtStack *sp, struct4_T *pStruct,
  boolean_T doPush)
{
  emxInit_real_T(sp, &pStruct->sidxs, 2, doPush);
  emxInit_real_T(sp, &pStruct->dir, 2, doPush);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct0_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_struct0_T(const emlrtStack *sp, emxArray_struct0_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_struct0_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_struct0_T *)emlrtMallocMex(sizeof(emxArray_struct0_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_struct0_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (struct0_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_struct4_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_struct4_T(const emlrtStack *sp, emxArray_struct4_T
  **pEmxArray, int32_T numDimensions, boolean_T doPush)
{
  emxArray_struct4_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_struct4_T *)emlrtMallocMex(sizeof(emxArray_struct4_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_struct4_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (struct4_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_struct0_T *emxArray
 *                int32_T fromIndex
 *                int32_T toIndex
 * Return Type  : void
 */
static void emxTrim_struct0_T(emxArray_struct0_T *emxArray, int32_T fromIndex,
  int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct0_T(&emxArray->data[i]);
  }
}

/*
 * Arguments    : emxArray_struct4_T *emxArray
 *                int32_T fromIndex
 *                int32_T toIndex
 * Return Type  : void
 */
static void emxTrim_struct4_T(emxArray_struct4_T *emxArray, int32_T fromIndex,
  int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_struct4_T(&emxArray->data[i]);
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv17[2];
  int32_T i6;
  int32_T iv18[2];
  boolean_T bv8[2] = { false, true };

  for (i6 = 0; i6 < 2; i6++) {
    iv17[i6] = 1 + -2 * i6;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv17, &bv8[0],
    iv18);
  i6 = ret->size[0] * ret->size[1];
  ret->size[0] = iv18[0];
  ret->size[1] = iv18[1];
  emxEnsureCapacity((emxArray__common *)ret, i6, (int32_T)sizeof(real_T));
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *H
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *H, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(sp, emlrtAlias(H), &thisId);
  emlrtDestroyArray(&H);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *ccdp
 *                const char_T *identifier
 *                struct1_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ccdp, const
  char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  i_emlrt_marshallIn(sp, emlrtAlias(ccdp), &thisId, y);
  emlrtDestroyArray(&ccdp);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct1_T *y
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[9] = { "xs", "ys", "omap", "cvis", "ctrack",
    "cavoid", "cconst", "glen", "gmap" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 9, fieldNames, 0U, 0);
  thisId.fIdentifier = "xs";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "xs")),
                     &thisId, y->xs);
  thisId.fIdentifier = "ys";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "ys")),
                     &thisId, y->ys);
  thisId.fIdentifier = "omap";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "omap")),
                     &thisId);
  thisId.fIdentifier = "cvis";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "cvis")),
                     &thisId);
  thisId.fIdentifier = "ctrack";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "ctrack")),
                     &thisId);
  thisId.fIdentifier = "cavoid";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "cavoid")),
                     &thisId);
  thisId.fIdentifier = "cconst";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "cconst")),
                     &thisId);
  thisId.fIdentifier = "glen";
  y->glen = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glen")), &thisId);
  thisId.fIdentifier = "gmap";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "gmap")),
                     &thisId, y->gmap.data, y->gmap.size);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[1] = { "val" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 1, fieldNames, 0U, 0);
  thisId.fIdentifier = "val";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "val")),
                     &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                boolean_T y_data[]
 *                int32_T y_size[2]
 * Return Type  : void
 */
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, boolean_T y_data[], int32_T y_size[2])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *costparam
 *                const char_T *identifier
 *                struct3_T *y
 * Return Type  : void
 */
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *costparam,
  const char_T *identifier, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  o_emlrt_marshallIn(sp, emlrtAlias(costparam), &thisId, y);
  emlrtDestroyArray(&costparam);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct3_T *y
 * Return Type  : void
 */
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[5] = { "ndir", "gnum", "glen", "cc", "A" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, 0);
  thisId.fIdentifier = "ndir";
  y->ndir = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "ndir")), &thisId);
  thisId.fIdentifier = "gnum";
  y->gnum = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "gnum")), &thisId);
  thisId.fIdentifier = "glen";
  y->glen = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glen")), &thisId);
  thisId.fIdentifier = "cc";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "cc")),
                     &thisId, y->cc);
  thisId.fIdentifier = "A";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "A")), &thisId,
                     y->A);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *nextstate
 *                const char_T *identifier
 *                emxArray_struct4_T *y
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nextstate,
  const char_T *identifier, emxArray_struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  s_emlrt_marshallIn(sp, emlrtAlias(nextstate), &thisId, y);
  emlrtDestroyArray(&nextstate);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_struct4_T *y
 * Return Type  : void
 */
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv1[2];
  int32_T i1;
  int32_T sizes[2];
  boolean_T bv1[2] = { false, true };

  static const char * fieldNames[2] = { "sidxs", "dir" };

  int32_T n;
  thisId.fParent = parentId;
  for (i1 = 0; i1 < 2; i1++) {
    iv1[i1] = 1 + -2 * i1;
  }

  emlrtCheckVsStructR2012b(sp, parentId, u, 2, fieldNames, 2U, iv1, &bv1[0],
    sizes);
  i1 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct4_T(sp, y, i1);
  n = y->size[1];
  for (i1 = 0; i1 < n; i1++) {
    thisId.fIdentifier = "sidxs";
    t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, i1, "sidxs")),
                       &thisId, y->data[i1].sidxs);
    thisId.fIdentifier = "dir";
    u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, i1, "dir")),
                       &thisId, y->data[i1].dir);
  }

  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
static real_T (*v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  int32_T iv3[1];
  iv3[0] = 3;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv3);
  ret = (real_T (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
  static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv4[2];
  int32_T i2;
  int32_T iv5[2];
  boolean_T bv2[2] = { false, true };

  for (i2 = 0; i2 < 2; i2++) {
    iv4[i2] = 2 + -3 * i2;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv4, &bv2[0],
    iv5);
  i2 = ret->size[0] * ret->size[1];
  ret->size[0] = iv5[0];
  ret->size[1] = iv5[1];
  emxEnsureCapacity((emxArray__common *)ret, i2, (int32_T)sizeof(real_T));
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv6[2];
  int32_T i;
  int32_T iv7[2];
  boolean_T bv3[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv6[i] = 200;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv6, &bv3[0],
    iv7);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv7[0];
  ret->size[1] = iv7[1];
  emxEnsureCapacity((emxArray__common *)ret, i, (int32_T)sizeof(real_T));
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const mxArray *prhs[8]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void fcn_track_ccdp_fast_api(const mxArray *prhs[8], const mxArray *plhs[3])
{
  emxArray_struct0_T *pEst;
  struct1_T ccdp;
  struct3_T costparam;
  emxArray_struct4_T *nextstate;
  emxArray_real_T *predict_s;
  real_T (*pS)[3];
  real_T H;
  real_T T;
  real_T threshold_track;
  real_T uw_opt;
  real_T uv_opt;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_struct0_T(&st, &pEst, 2, true);
  emxInitStruct_struct1_T(&st, &ccdp, true);
  emxInitStruct_struct3_T(&st, &costparam, true);
  emxInit_struct4_T(&st, &nextstate, 2, true);
  emxInit_real_T(&st, &predict_s, 2, true);
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, false, -1);

  /* Marshall function inputs */
  pS = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "pS");
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "pEst", pEst);
  H = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "H");
  T = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "T");
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "ccdp", &ccdp);
  threshold_track = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]),
    "threshold_track");
  n_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "costparam", &costparam);
  r_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "nextstate", nextstate);

  /* Invoke the target function */
  fcn_track_ccdp_fast(*pS, pEst, H, T, &ccdp, threshold_track, &costparam,
                      nextstate, &uv_opt, &uw_opt, predict_s);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(uv_opt);
  plhs[1] = emlrt_marshallOut(uw_opt);
  plhs[2] = b_emlrt_marshallOut(predict_s);
  predict_s->canFreeData = false;
  emxFree_real_T(&predict_s);
  emxFree_struct4_T(&nextstate);
  emxFreeStruct_struct3_T(&costparam);
  emxFreeStruct_struct1_T(&ccdp);
  emxFree_struct0_T(&pEst);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void fcn_track_ccdp_fast_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  fcn_track_ccdp_fast_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void fcn_track_ccdp_fast_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void fcn_track_ccdp_fast_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_fcn_track_ccdp_fast_api.c
 *
 * [EOF]
 */
