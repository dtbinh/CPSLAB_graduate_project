//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normcdf.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "normcdf.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include <stdio.h>

// Function Declarations
static double rt_powd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  double d0;
  double d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = rtNaN;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : const emxArray_real_T *x
//                emxArray_real_T *p
// Return Type  : void
//
void normcdf(const emxArray_real_T *x, emxArray_real_T *p)
{
  unsigned int uv1[2];
  int i8;
  unsigned int u0;
  unsigned int u1;
  int k;
  double y;
  double absx;
  double s;
  double S;
  double R;
  int eint;
  int exponent;
  for (i8 = 0; i8 < 2; i8++) {
    uv1[i8] = (unsigned int)x->size[i8];
  }

  u0 = uv1[0];
  u1 = uv1[1];
  i8 = p->size[0] * p->size[1];
  p->size[0] = (int)u0;
  p->size[1] = (int)u1;
  emxEnsureCapacity((emxArray__common *)p, i8, (int)sizeof(double));
  i8 = (int)uv1[0] * (int)u1;
  for (k = 0; k < i8; k++) {
    y = -x->data[k] / 1.4142135623730951;

    // ========================== COPYRIGHT NOTICE ============================
    //  The algorithms for calculating ERF(X) and ERFC(X) are derived
    //  from FDLIBM, which has the following notice:
    //
    //  Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
    //
    //  Developed at SunSoft, a Sun Microsystems, Inc. business.
    //  Permission to use, copy, modify, and distribute this
    //  software is freely granted, provided that this notice
    //  is preserved.
    // =============================    END    ================================
    absx = fabs(y);
    if (rtIsNaN(y)) {
      s = y;
    } else if (rtIsInf(y)) {
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

      if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
        s = frexp(absx, &eint);
        exponent = eint;
      } else {
        s = absx;
        exponent = 0;
      }

      s = floor(s * 2.097152E+6) / 2.097152E+6 * rt_powd_snf(2.0, (double)
        exponent);
      s = exp(-s * s - 0.5625) * exp((s - absx) * (s + absx) + R / S) / absx;
      if (y < 0.0) {
        s = 2.0 - s;
      }
    }

    p->data[k] = 0.5 * s;
  }
}

//
// File trailer for normcdf.cpp
//
// [EOF]
//
