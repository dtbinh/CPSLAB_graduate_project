/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fcn_track_ccdp_fast_api.c
 *
 * Code generation for function '_coder_fcn_track_ccdp_fast_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "_coder_fcn_track_ccdp_fast_api.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include "fprintf.h"
#include "fcn_track_ccdp_fast_mexutil.h"
#include "fcn_track_ccdp_fast_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRTEInfo w_emlrtRTEI = { 1, 1, "_coder_fcn_track_ccdp_fast_api", "" };

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, boolean_T ret_data[], int32_T ret_size[2]);
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pS,
  const char_T *identifier))[3];
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pEst, const
  char_T *identifier, emxArray_struct0_T *y);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
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
static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  int32_T iv21[2];
  int32_T i;
  for (i = 0; i < 2; i++) {
    iv21[i] = 0;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv21);
  emlrtDestroyArray(&src);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  static const int32_T iv15[2] = { 0, 0 };

  const mxArray *m2;
  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv15, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)u->data);
  emlrtSetDimensions((mxArray *)m2, u->size, 2);
  emlrtAssign(&y, m2);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, boolean_T ret_data[], int32_T ret_size[2])
{
  int32_T iv22[2];
  int32_T i;
  int32_T iv23[2];
  boolean_T bv4[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv22[i] = 100;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "logical", false, 2U, iv22, &bv4[0],
    iv23);
  ret_size[0] = iv23[0];
  ret_size[1] = iv23[1];
  emlrtImportArrayR2011b(src, (void *)ret_data, 1, false);
  emlrtDestroyArray(&src);
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pS,
  const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(pS), &thisId);
  emlrtDestroyArray(&pS);
  return y;
}
  static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv24[1];
  boolean_T bv5[1] = { true };

  static const int32_T iv25[1] = { -1 };

  int32_T i43;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv25, &bv5[0],
    iv24);
  i43 = ret->size[0];
  ret->size[0] = iv24[0];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i43, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv26[3];
  boolean_T bv6[3] = { true, false, true };

  static const int32_T iv27[3] = { -1, 2, -1 };

  int32_T i44;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 3U, iv27, &bv6[0],
    iv26);
  i44 = ret->size[0] * ret->size[1] * ret->size[2];
  ret->size[0] = iv26[0];
  ret->size[1] = iv26[1];
  ret->size[2] = iv26[2];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i44, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *pEst, const
  char_T *identifier, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  f_emlrt_marshallIn(sp, emlrtAlias(pEst), &thisId, y);
  emlrtDestroyArray(&pEst);
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv28[2];
  int32_T i45;
  int32_T iv29[2];
  boolean_T bv7[2] = { true, false };

  for (i45 = 0; i45 < 2; i45++) {
    iv28[i45] = 3 * i45 - 1;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv28, &bv7[0],
    iv29);
  i45 = ret->size[0] * ret->size[1];
  ret->size[0] = iv29[0];
  ret->size[1] = iv29[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i45, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv13[2];
  int32_T i40;
  int32_T sizes[2];
  boolean_T bv0[2] = { false, true };

  static const char * fieldNames[4] = { "mean", "sig", "prob", "M" };

  int32_T n;
  thisId.fParent = parentId;
  for (i40 = 0; i40 < 2; i40++) {
    iv13[i40] = 1 + -2 * i40;
  }

  emlrtCheckVsStructR2012b(sp, parentId, u, 4, fieldNames, 2U, iv13, &bv0[0],
    sizes);
  i40 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct0_T(sp, y, i40, (emlrtRTEInfo *)NULL);
  n = y->size[1];
  for (i40 = 0; i40 < n; i40++) {
    thisId.fIdentifier = "mean";
    g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, i40, "mean")),
                       &thisId, y->data[i40].mean);
    thisId.fIdentifier = "sig";
    y->data[i40].sig = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
      u, i40, "sig")), &thisId);
    thisId.fIdentifier = "prob";
    y->data[i40].prob = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp,
      u, i40, "prob")), &thisId);
    thisId.fIdentifier = "M";
    y->data[i40].M = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u,
      i40, "M")), &thisId);
  }

  emlrtDestroyArray(&u);
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv30[2];
  int32_T i46;
  int32_T iv31[2];
  boolean_T bv8[2] = { false, true };

  for (i46 = 0; i46 < 2; i46++) {
    iv30[i46] = 1 + -2 * i46;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv30, &bv8[0],
    iv31);
  i46 = ret->size[0] * ret->size[1];
  ret->size[0] = iv31[0];
  ret->size[1] = iv31[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i46, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ccdp, const
  char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  i_emlrt_marshallIn(sp, emlrtAlias(ccdp), &thisId, y);
  emlrtDestroyArray(&ccdp);
}

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
  y->glen = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glen")), &thisId);
  thisId.fIdentifier = "gmap";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "gmap")),
                     &thisId, y->gmap.data, y->gmap.size);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

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

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, boolean_T y_data[], int32_T y_size[2])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *costparam,
  const char_T *identifier, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  o_emlrt_marshallIn(sp, emlrtAlias(costparam), &thisId, y);
  emlrtDestroyArray(&costparam);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[5] = { "ndir", "gnum", "glen", "cc", "A" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, 0);
  thisId.fIdentifier = "ndir";
  y->ndir = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "ndir")), &thisId);
  thisId.fIdentifier = "gnum";
  y->gnum = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "gnum")), &thisId);
  thisId.fIdentifier = "glen";
  y->glen = b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "glen")), &thisId);
  thisId.fIdentifier = "cc";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "cc")),
                     &thisId, y->cc);
  thisId.fIdentifier = "A";
  q_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "A")), &thisId,
                     y->A);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nextstate,
  const char_T *identifier, emxArray_struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  s_emlrt_marshallIn(sp, emlrtAlias(nextstate), &thisId, y);
  emlrtDestroyArray(&nextstate);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_struct4_T *y)
{
  emlrtMsgIdentifier thisId;
  int32_T iv14[2];
  int32_T i41;
  int32_T sizes[2];
  boolean_T bv1[2] = { false, true };

  static const char * fieldNames[2] = { "sidxs", "dir" };

  int32_T n;
  thisId.fParent = parentId;
  for (i41 = 0; i41 < 2; i41++) {
    iv14[i41] = 1 + -2 * i41;
  }

  emlrtCheckVsStructR2012b(sp, parentId, u, 2, fieldNames, 2U, iv14, &bv1[0],
    sizes);
  i41 = y->size[0] * y->size[1];
  y->size[0] = sizes[0];
  y->size[1] = sizes[1];
  emxEnsureCapacity_struct4_T(sp, y, i41, (emlrtRTEInfo *)NULL);
  n = y->size[1];
  for (i41 = 0; i41 < n; i41++) {
    thisId.fIdentifier = "sidxs";
    t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, i41, "sidxs")),
                       &thisId, y->data[i41].sidxs);
    thisId.fIdentifier = "dir";
    u_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, i41, "dir")),
                       &thisId, y->data[i41].dir);
  }

  emlrtDestroyArray(&u);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  int32_T iv16[1];
  iv16[0] = 3;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, iv16);
  ret = (real_T (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv17[2];
  int32_T i42;
  int32_T iv18[2];
  boolean_T bv2[2] = { false, true };

  for (i42 = 0; i42 < 2; i42++) {
    iv17[i42] = 2 + -3 * i42;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv17, &bv2[0],
    iv18);
  i42 = ret->size[0] * ret->size[1];
  ret->size[0] = iv18[0];
  ret->size[1] = iv18[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i42, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  int32_T iv19[2];
  int32_T i;
  int32_T iv20[2];
  boolean_T bv3[2] = { true, true };

  for (i = 0; i < 2; i++) {
    iv19[i] = 200;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, iv19, &bv3[0],
    iv20);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv20[0];
  ret->size[1] = iv20[1];
  emxEnsureCapacity(sp, (emxArray__common *)ret, i, (int32_T)sizeof(real_T),
                    (emlrtRTEInfo *)NULL);
  emlrtImportArrayR2011b(src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

void fcn_track_ccdp_fast_api(fcn_track_ccdp_fastStackData *SD, const mxArray *
  const prhs[8], const mxArray *plhs[3])
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
  emxInit_struct0_T(&st, &pEst, 2, &w_emlrtRTEI, true);
  emxInitStruct_struct1_T(&st, &ccdp, &w_emlrtRTEI, true);
  emxInitStruct_struct3_T(&st, &costparam, &w_emlrtRTEI, true);
  emxInit_struct4_T(&st, &nextstate, 2, &w_emlrtRTEI, true);
  c_emxInit_real_T(&st, &predict_s, 2, &w_emlrtRTEI, true);

  /* Marshall function inputs */
  pS = c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "pS");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "pEst", pEst);
  H = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "H");
  T = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "T");
  h_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "ccdp", &ccdp);
  threshold_track = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]),
    "threshold_track");
  n_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "costparam", &costparam);
  r_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "nextstate", nextstate);

  /* Invoke the target function */
  fcn_track_ccdp_fast(SD, &st, *pS, pEst, H, T, &ccdp, threshold_track,
                      &costparam, nextstate, &uv_opt, &uw_opt, predict_s);

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

/* End of code generation (_coder_fcn_track_ccdp_fast_api.c) */
