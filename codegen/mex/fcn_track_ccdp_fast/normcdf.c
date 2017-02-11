/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * normcdf.c
 *
 * Code generation for function 'normcdf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "normcdf.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include "scalexpAlloc.h"
#include "fcn_track_ccdp_fast_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo kb_emlrtRSI = { 42, "normcdf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\stats\\eml\\normcdf.m" };

static emlrtRSInfo lb_emlrtRSI = { 49, "sxalloc",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\sxalloc.m"
};

static emlrtBCInfo ag_emlrtBCI = { -1, -1, 48, 10, "", "normcdf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\stats\\eml\\normcdf.m", 0 };

static emlrtBCInfo bg_emlrtBCI = { -1, -1, 78, 9, "", "normcdf",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\stats\\eml\\normcdf.m", 0 };

/* Function Definitions */
void normcdf(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *p)
{
  uint32_T uv1[2];
  int32_T i34;
  uint32_T u0;
  uint32_T u1;
  int32_T k;
  int32_T exponent;
  int32_T i35;
  real_T y;
  real_T absx;
  real_T s;
  real_T S;
  real_T R;
  int32_T eint;
  int32_T b_k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &r_emlrtRSI;
  for (i34 = 0; i34 < 2; i34++) {
    uv1[i34] = (uint32_T)x->size[i34];
  }

  u0 = uv1[0];
  u1 = uv1[1];
  i34 = p->size[0] * p->size[1];
  p->size[0] = (int32_T)u0;
  p->size[1] = (int32_T)u1;
  emxEnsureCapacity(&c_st, (emxArray__common *)p, i34, (int32_T)sizeof(real_T),
                    &n_emlrtRTEI);
  if (c_dimagree(p, x)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &n_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  i34 = (int32_T)uv1[0] * (int32_T)u1;
  for (k = 0; k < i34; k++) {
    exponent = x->size[0] * x->size[1];
    i35 = k + 1;
    emlrtDynamicBoundsCheckR2012b(i35, 1, exponent, &ag_emlrtBCI, sp);
    y = -x->data[k] / 1.4142135623730951;

    /* ========================== COPYRIGHT NOTICE ============================ */
    /*  The algorithms for calculating ERF(X) and ERFC(X) are derived           */
    /*  from FDLIBM, which has the following notice:                            */
    /*                                                                          */
    /*  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.       */
    /*                                                                          */
    /*  Developed at SunSoft, a Sun Microsystems, Inc. business.                */
    /*  Permission to use, copy, modify, and distribute this                    */
    /*  software is freely granted, provided that this notice                   */
    /*  is preserved.                                                           */
    /* =============================    END    ================================ */
    absx = muDoubleScalarAbs(y);
    if (muDoubleScalarIsNaN(y)) {
      s = y;
    } else if (muDoubleScalarIsInf(y)) {
      if (y < 0.0) {
        s = 2.0;
      } else {
        s = 0.0;
      }
    } else if (absx < 0.84375) {
      if (absx < 1.3877787807814457E-17) {
        s = 1.0 - y;
      } else {
        s = y * y;
        s = (0.12837916709551256 + s * (-0.3250421072470015 + s *
              (-0.02848174957559851 + s * (-0.0057702702964894416 + s *
                -2.3763016656650163E-5)))) / (1.0 + s * (0.39791722395915535 + s
          * (0.0650222499887673 + s * (0.0050813062818757656 + s *
          (0.00013249473800432164 + s * -3.9602282787753681E-6)))));
        if (y < 0.25) {
          s = 1.0 - (y + y * s);
        } else {
          s = 0.5 - (y * s + (y - 0.5));
        }
      }
    } else if (absx < 1.25) {
      S = -0.0023621185607526594 + (absx - 1.0) * (0.41485611868374833 + (absx -
        1.0) * (-0.37220787603570132 + (absx - 1.0) * (0.31834661990116175 +
        (absx - 1.0) * (-0.11089469428239668 + (absx - 1.0) *
                        (0.035478304325618236 + (absx - 1.0) *
                         -0.0021663755948687908)))));
      s = 1.0 + (absx - 1.0) * (0.10642088040084423 + (absx - 1.0) *
        (0.540397917702171 + (absx - 1.0) * (0.071828654414196266 + (absx - 1.0)
        * (0.12617121980876164 + (absx - 1.0) * (0.013637083912029051 + (absx -
        1.0) * 0.011984499846799107)))));
      if (y >= 0.0) {
        s = 0.15493708848953247 - S / s;
      } else {
        s = 1.0 + (0.84506291151046753 + S / s);
      }
    } else if (y < -6.0) {
      s = 2.0;
    } else if (y >= 28.0) {
      s = 0.0;
    } else {
      s = 1.0 / (absx * absx);
      if (absx < 2.8571414947509766) {
        R = -0.0098649440348471482 + s * (-0.69385857270718176 + s *
          (-10.558626225323291 + s * (-62.375332450326006 + s *
          (-162.39666946257347 + s * (-184.60509290671104 + s *
          (-81.2874355063066 + s * -9.8143293441691455))))));
        S = 1.0 + s * (19.651271667439257 + s * (137.65775414351904 + s *
          (434.56587747522923 + s * (645.38727173326788 + s *
          (429.00814002756783 + s * (108.63500554177944 + s *
          (6.5702497703192817 + s * -0.0604244152148581)))))));
      } else {
        R = -0.0098649429247001 + s * (-0.799283237680523 + s *
          (-17.757954917754752 + s * (-160.63638485582192 + s *
          (-637.56644336838963 + s * (-1025.0951316110772 + s *
          -483.5191916086514)))));
        S = 1.0 + s * (30.338060743482458 + s * (325.79251299657392 + s *
          (1536.729586084437 + s * (3199.8582195085955 + s * (2553.0504064331644
          + s * (474.52854120695537 + s * -22.440952446585818))))));
      }

      if ((!muDoubleScalarIsInf(absx)) && (!muDoubleScalarIsNaN(absx))) {
        s = frexp(absx, &eint);
        exponent = eint;
      } else {
        s = absx;
        exponent = 0;
      }

      s = muDoubleScalarFloor(s * 2.097152E+6) / 2.097152E+6 *
        muDoubleScalarPower(2.0, exponent);
      s = muDoubleScalarExp(-s * s - 0.5625) * muDoubleScalarExp((s - absx) * (s
        + absx) + R / S) / absx;
      if (y < 0.0) {
        s = 2.0 - s;
      }
    }

    exponent = p->size[0] * p->size[1];
    if ((k + 1 >= 1) && (k + 1 < exponent)) {
      b_k = k + 1;
    } else {
      b_k = emlrtDynamicBoundsCheckR2012b(k + 1, 1, exponent, &bg_emlrtBCI, sp);
    }

    p->data[b_k - 1] = 0.5 * s;
  }
}

/* End of code generation (normcdf.c) */
