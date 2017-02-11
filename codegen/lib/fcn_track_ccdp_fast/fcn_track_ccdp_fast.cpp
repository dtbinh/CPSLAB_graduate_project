//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fcn_track_ccdp_fast.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include "sum.h"
#include "normcdf.h"
#include "bsxfun.h"
#include "conv2.h"
#include "round.h"
#include "atan2.h"
#include "power.h"
#include "abs.h"
#include "norm.h"
#include "fprintf.h"
#include "mean.h"
#include "mod.h"
#include "fcn_track_ccdp_fast_rtwutil.h"
#include <stdio.h>

// Function Declarations
static int div_nzp_s32_floor(int numerator, int denominator);

// Function Definitions

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_nzp_s32_floor(int numerator, int denominator)
{
  int quotient;
  unsigned int absNumerator;
  unsigned int absDenominator;
  boolean_T quotientNeedsNegation;
  unsigned int tempAbsQuotient;
  if (numerator >= 0) {
    absNumerator = (unsigned int)numerator;
  } else {
    absNumerator = (unsigned int)-numerator;
  }

  if (denominator >= 0) {
    absDenominator = (unsigned int)denominator;
  } else {
    absDenominator = (unsigned int)-denominator;
  }

  quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
  tempAbsQuotient = absNumerator / absDenominator;
  if (quotientNeedsNegation) {
    absNumerator %= absDenominator;
    if (absNumerator > 0U) {
      tempAbsQuotient++;
    }
  }

  if (quotientNeedsNegation) {
    quotient = -(int)tempAbsQuotient;
  } else {
    quotient = (int)tempAbsQuotient;
  }

  return quotient;
}

//
// ---------------------------------------------------------------%
//  Find the optimal control which follows the target
//  without collision and occlusion
//  -- Input -- %
//  current position
//  pEst: estimated position of the target
// Arguments    : const double pS[3]
//                const emxArray_struct0_T *pEst
//                double H
//                double T
//                const struct1_T *ccdp
//                double threshold_track
//                const struct3_T *costparam
//                const emxArray_struct4_T *nextstate
//                double *uv_opt
//                double *uw_opt
//                emxArray_real_T *predict_s
// Return Type  : void
//
void fcn_track_ccdp_fast(const double pS[3], const emxArray_struct0_T *pEst,
  double H, double T, const struct1_T *ccdp, double threshold_track, const
  struct3_T *costparam, const emxArray_struct4_T *nextstate, double *uv_opt,
  double *uw_opt, emxArray_real_T *predict_s)
{
  emxArray_real_T *ccdp_ctrack;
  int clen;
  int rlen;
  double ndir;
  int iy;
  int i0;
  int loop_ub;
  emxArray_real_T *ccdp_cvis;
  emxArray_real_T *ccdp_cavoid;
  emxArray_real_T *ccdp_cconst;
  int tt;
  emxArray_real_T *angle2target;
  emxArray_real_T *cvistmp;
  emxArray_real_T *mindiridx;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *A;
  emxArray_real_T *y;
  emxArray_real_T *b;
  emxArray_real_T *r3;
  emxArray_real_T *r4;
  emxArray_boolean_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *b_ccdp_ctrack;
  emxArray_real_T *b_ccdp_cavoid;
  emxArray_real_T *b_ccdp;
  emxArray_real_T *c_ccdp;
  emxArray_real_T *d_ccdp;
  emxArray_real_T *e_ccdp;
  emxArray_real_T *f_ccdp;
  emxArray_real_T *r7;
  emxArray_real_T *b_A;
  emxArray_real_T *g_ccdp;
  emxArray_real_T *h_ccdp;
  double mtmp;
  int n;
  int br;
  int cindx;
  double minradius[20];
  int ii;
  boolean_T tmp_data[10000];
  static boolean_T b_tmp_data[40000];
  boolean_T c_tmp_data[10000];
  int tmp_size[1];
  static int d_tmp_data[10000];
  int ixstart;
  int k;
  boolean_T exitg4;
  boolean_T e_tmp_data[40000];
  int b_loop_ub;
  int i1;
  double currs_idx[2];
  int i2;
  int ixstop;
  int b_n;
  int itmp;
  boolean_T x_data[40000];
  double lagrng[2];
  unsigned char sz[2];
  boolean_T CompMat_data[40000];
  double lagcoeff;
  int lag_feas;
  int flag_converge;
  int ilagran;
  emxArray_real_T *Optctrl_col;
  emxArray_real_T *Optctrl_dirs;
  emxArray_real_T *Jmin;
  emxArray_real_T *b_currs_idx;
  emxArray_real_T *optidx;
  emxArray_real_T *r8;
  emxArray_int32_T *iindx;
  emxArray_real_T *b_lagcoeff;
  emxArray_real_T *b_lag_feas;
  emxArray_real_T *c_lagcoeff;
  emxArray_real_T *c_lag_feas;
  emxArray_real_T *b_mindiridx;
  emxArray_real_T *b_Optctrl_dirs;
  emxArray_real_T *b_Jmin;
  emxArray_real_T *c_Jmin;
  emxArray_real_T *b_nextstate;
  emxArray_real_T *c_nextstate;
  emxArray_real_T *d_Jmin;
  emxArray_real_T *d_nextstate;
  emxArray_real_T *r9;
  emxArray_real_T *CompMat;
  emxArray_real_T *b_CompMat;
  emxArray_real_T *c_CompMat;
  boolean_T exitg1;
  double b_tt;
  unsigned int outsz[3];
  int c_n;
  boolean_T exitg3;
  int vstride;
  boolean_T exitg2;
  double anew;
  double apnd;
  double ndbl;
  double cdiff;
  double absa;
  double absb;
  double original_rng_r_data[200];
  double original_rng_c_data[200];
  double comp_rng_r_data[200];
  double comp_rng_c_data[200];
  double b_pS[2];
  double const_val;
  double c_ccdp_ctrack[3];
  double i_ccdp;
  boolean_T guard1 = false;
  double movement[3];
  emxInit_real_T(&ccdp_ctrack, 4);

  //  -- Output -- %
  //  ----------------------------------------------------------------%
  //  -- [ settings for visibility cost ] -- %
  //  the number of angles to compute visibility cost
  clen = ccdp->xs->size[1];
  rlen = ccdp->xs->size[0];

  // ccdp.cvis = zeros([rlen,clen,H]); % initialize the visibility cost
  //  -- [ settings for tracking cost ] -- %
  ndir = costparam->ndir;

  // s_dirs = costparam.s_dirs;
  //  -- [ Compute one-step cost ] -- %
  iy = ccdp->xs->size[0];
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[0] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_ctrack, i0, (int)sizeof(double));
  iy = ccdp->xs->size[1];
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[1] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_ctrack, i0, (int)sizeof(double));
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[2] = (int)costparam->ndir;
  emxEnsureCapacity((emxArray__common *)ccdp_ctrack, i0, (int)sizeof(double));
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[3] = (int)(H + 1.0);
  emxEnsureCapacity((emxArray__common *)ccdp_ctrack, i0, (int)sizeof(double));
  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int)costparam->ndir * (int)
    (H + 1.0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_ctrack->data[i0] = 0.0;
  }

  b_emxInit_real_T(&ccdp_cvis, 3);
  iy = ccdp->xs->size[0];
  i0 = ccdp_cvis->size[0] * ccdp_cvis->size[1] * ccdp_cvis->size[2];
  ccdp_cvis->size[0] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_cvis, i0, (int)sizeof(double));
  iy = ccdp->xs->size[1];
  i0 = ccdp_cvis->size[0] * ccdp_cvis->size[1] * ccdp_cvis->size[2];
  ccdp_cvis->size[1] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_cvis, i0, (int)sizeof(double));
  i0 = ccdp_cvis->size[0] * ccdp_cvis->size[1] * ccdp_cvis->size[2];
  ccdp_cvis->size[2] = (int)(H + 1.0);
  emxEnsureCapacity((emxArray__common *)ccdp_cvis, i0, (int)sizeof(double));
  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int)(H + 1.0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_cvis->data[i0] = 0.0;
  }

  b_emxInit_real_T(&ccdp_cavoid, 3);

  // ccdp.ctrack(1).val = zeros(rlen,clen,ndir);
  iy = ccdp->xs->size[0];
  i0 = ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * ccdp_cavoid->size[2];
  ccdp_cavoid->size[0] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_cavoid, i0, (int)sizeof(double));
  iy = ccdp->xs->size[1];
  i0 = ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * ccdp_cavoid->size[2];
  ccdp_cavoid->size[1] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_cavoid, i0, (int)sizeof(double));
  i0 = ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * ccdp_cavoid->size[2];
  ccdp_cavoid->size[2] = (int)(H + 1.0);
  emxEnsureCapacity((emxArray__common *)ccdp_cavoid, i0, (int)sizeof(double));
  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int)(H + 1.0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_cavoid->data[i0] = 0.0;
  }

  emxInit_real_T(&ccdp_cconst, 4);
  iy = ccdp->xs->size[0];
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[0] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_cconst, i0, (int)sizeof(double));
  iy = ccdp->xs->size[1];
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[1] = iy;
  emxEnsureCapacity((emxArray__common *)ccdp_cconst, i0, (int)sizeof(double));
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[2] = (int)costparam->ndir;
  emxEnsureCapacity((emxArray__common *)ccdp_cconst, i0, (int)sizeof(double));
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[3] = (int)(H + 1.0);
  emxEnsureCapacity((emxArray__common *)ccdp_cconst, i0, (int)sizeof(double));
  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int)costparam->ndir * (int)
    (H + 1.0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_cconst->data[i0] = 0.0;
  }

  tt = 0;
  c_emxInit_real_T(&angle2target, 2);
  c_emxInit_real_T(&cvistmp, 2);
  c_emxInit_real_T(&mindiridx, 2);
  b_emxInit_real_T(&r0, 3);
  c_emxInit_real_T(&r1, 2);
  emxInit_int32_T(&r2, 1);
  c_emxInit_real_T(&A, 2);
  c_emxInit_real_T(&y, 2);
  c_emxInit_real_T(&b, 2);
  c_emxInit_real_T(&r3, 2);
  c_emxInit_real_T(&r4, 2);
  emxInit_boolean_T(&r5, 3);
  c_emxInit_real_T(&r6, 2);
  b_emxInit_real_T(&b_ccdp_ctrack, 3);
  c_emxInit_real_T(&b_ccdp_cavoid, 2);
  c_emxInit_real_T(&b_ccdp, 2);
  c_emxInit_real_T(&c_ccdp, 2);
  c_emxInit_real_T(&d_ccdp, 2);
  c_emxInit_real_T(&e_ccdp, 2);
  c_emxInit_real_T(&f_ccdp, 2);
  c_emxInit_real_T(&r7, 2);
  c_emxInit_real_T(&b_A, 2);
  d_emxInit_real_T(&g_ccdp, 1);
  d_emxInit_real_T(&h_ccdp, 1);
  while (tt <= (int)H - 1) {
    //  --- [ Cost: Cvis ]  --- %
    //  distance and angle from the target's prediction to grids
    i0 = f_ccdp->size[0] * f_ccdp->size[1];
    f_ccdp->size[0] = ccdp->xs->size[0];
    f_ccdp->size[1] = ccdp->xs->size[1];
    emxEnsureCapacity((emxArray__common *)f_ccdp, i0, (int)sizeof(double));
    mtmp = pEst->data[tt].mean->data[0];
    loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      f_ccdp->data[i0] = ccdp->xs->data[i0] - mtmp;
    }

    power(f_ccdp, mindiridx);
    i0 = e_ccdp->size[0] * e_ccdp->size[1];
    e_ccdp->size[0] = ccdp->ys->size[0];
    e_ccdp->size[1] = ccdp->ys->size[1];
    emxEnsureCapacity((emxArray__common *)e_ccdp, i0, (int)sizeof(double));
    mtmp = pEst->data[tt].mean->data[1];
    loop_ub = ccdp->ys->size[0] * ccdp->ys->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      e_ccdp->data[i0] = ccdp->ys->data[i0] - mtmp;
    }

    power(e_ccdp, r1);
    i0 = mindiridx->size[0] * mindiridx->size[1];
    emxEnsureCapacity((emxArray__common *)mindiridx, i0, (int)sizeof(double));
    iy = mindiridx->size[0];
    n = mindiridx->size[1];
    loop_ub = iy * n;
    for (i0 = 0; i0 < loop_ub; i0++) {
      mindiridx->data[i0] += r1->data[i0];
    }

    i0 = c_ccdp->size[0] * c_ccdp->size[1];
    c_ccdp->size[0] = ccdp->ys->size[0];
    c_ccdp->size[1] = ccdp->ys->size[1];
    emxEnsureCapacity((emxArray__common *)c_ccdp, i0, (int)sizeof(double));
    mtmp = pEst->data[tt].mean->data[1];
    loop_ub = ccdp->ys->size[0] * ccdp->ys->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_ccdp->data[i0] = ccdp->ys->data[i0] - mtmp;
    }

    i0 = d_ccdp->size[0] * d_ccdp->size[1];
    d_ccdp->size[0] = ccdp->xs->size[0];
    d_ccdp->size[1] = ccdp->xs->size[1];
    emxEnsureCapacity((emxArray__common *)d_ccdp, i0, (int)sizeof(double));
    mtmp = pEst->data[tt].mean->data[0];
    loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_ccdp->data[i0] = ccdp->xs->data[i0] - mtmp;
    }

    b_atan2(c_ccdp, d_ccdp, r1);
    i0 = A->size[0] * A->size[1];
    A->size[0] = r1->size[0];
    A->size[1] = r1->size[1];
    emxEnsureCapacity((emxArray__common *)A, i0, (int)sizeof(double));
    loop_ub = r1->size[0] * r1->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      A->data[i0] = r1->data[i0] + 3.1415926535897931;
    }

    i0 = angle2target->size[0] * angle2target->size[1];
    angle2target->size[0] = A->size[0];
    angle2target->size[1] = A->size[1];
    emxEnsureCapacity((emxArray__common *)angle2target, i0, (int)sizeof(double));
    loop_ub = A->size[0] * A->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      angle2target->data[i0] = A->data[i0] / 2.0 / 3.1415926535897931 * 20.0;
    }

    b_round(angle2target);
    i0 = angle2target->size[0] * angle2target->size[1];
    emxEnsureCapacity((emxArray__common *)angle2target, i0, (int)sizeof(double));
    iy = angle2target->size[0];
    n = angle2target->size[1];
    loop_ub = iy * n;
    for (i0 = 0; i0 < loop_ub; i0++) {
      angle2target->data[i0]++;
    }

    br = angle2target->size[0] * angle2target->size[1] - 1;
    cindx = 0;
    for (n = 0; n <= br; n++) {
      if (angle2target->data[n] == 9.0) {
        cindx++;
      }
    }

    i0 = r2->size[0];
    r2->size[0] = cindx;
    emxEnsureCapacity((emxArray__common *)r2, i0, (int)sizeof(int));
    iy = 0;
    for (n = 0; n <= br; n++) {
      if (angle2target->data[n] == 9.0) {
        r2->data[iy] = n + 1;
        iy++;
      }
    }

    loop_ub = r2->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      angle2target->data[r2->data[i0] - 1] = 1.0;
    }

    memset(&minradius[0], 0, 20U * sizeof(double));

    //  distance between the target and an obstacle in nvis directions
    i0 = cvistmp->size[0] * cvistmp->size[1];
    cvistmp->size[0] = (unsigned char)rlen;
    emxEnsureCapacity((emxArray__common *)cvistmp, i0, (int)sizeof(double));
    i0 = cvistmp->size[0] * cvistmp->size[1];
    cvistmp->size[1] = (unsigned char)clen;
    emxEnsureCapacity((emxArray__common *)cvistmp, i0, (int)sizeof(double));
    loop_ub = (unsigned char)rlen * (unsigned char)clen;
    for (i0 = 0; i0 < loop_ub; i0++) {
      cvistmp->data[i0] = 0.0;
    }

    for (ii = 0; ii < 20; ii++) {
      iy = ccdp->gmap.size[0] * ccdp->gmap.size[1];
      loop_ub = ccdp->gmap.size[0] * ccdp->gmap.size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        tmp_data[i0] = ccdp->gmap.data[i0];
      }

      loop_ub = angle2target->size[0] * angle2target->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_tmp_data[i0] = (angle2target->data[i0] == 1.0 + (double)ii);
      }

      tmp_size[0] = iy;
      for (i0 = 0; i0 < iy; i0++) {
        c_tmp_data[i0] = (tmp_data[i0] && b_tmp_data[i0]);
      }

      if (sum(c_tmp_data, tmp_size) >= 1.0) {
        br = iy - 1;
        cindx = 0;
        for (n = 0; n <= br; n++) {
          if (tmp_data[n] && b_tmp_data[n]) {
            cindx++;
          }
        }

        iy = 0;
        for (n = 0; n <= br; n++) {
          if (tmp_data[n] && b_tmp_data[n]) {
            d_tmp_data[iy] = n + 1;
            iy++;
          }
        }

        ixstart = 1;
        mtmp = mindiridx->data[d_tmp_data[0] - 1];
        if (cindx > 1) {
          if (rtIsNaN(mtmp)) {
            k = 2;
            exitg4 = false;
            while ((!exitg4) && (k <= cindx)) {
              ixstart = k;
              if (!rtIsNaN(mindiridx->data[d_tmp_data[k - 1] - 1])) {
                mtmp = mindiridx->data[d_tmp_data[k - 1] - 1];
                exitg4 = true;
              } else {
                k++;
              }
            }
          }

          if (ixstart < cindx) {
            while (ixstart + 1 <= cindx) {
              if (mindiridx->data[d_tmp_data[ixstart] - 1] < mtmp) {
                mtmp = mindiridx->data[d_tmp_data[ixstart] - 1];
              }

              ixstart++;
            }
          }
        }

        minradius[ii] = mtmp;
        iy = mindiridx->size[0] * mindiridx->size[1];
        loop_ub = mindiridx->size[0] * mindiridx->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_tmp_data[i0] = (mindiridx->data[i0] >= minradius[ii]);
        }

        loop_ub = angle2target->size[0] * angle2target->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          e_tmp_data[i0] = (angle2target->data[i0] == 1.0 + (double)ii);
        }

        br = iy - 1;
        cindx = 0;
        for (n = 0; n <= br; n++) {
          if (b_tmp_data[n] && e_tmp_data[n]) {
            cindx++;
          }
        }

        i0 = r2->size[0];
        r2->size[0] = cindx;
        emxEnsureCapacity((emxArray__common *)r2, i0, (int)sizeof(int));
        iy = 0;
        for (n = 0; n <= br; n++) {
          if (b_tmp_data[n] && e_tmp_data[n]) {
            r2->data[iy] = n + 1;
            iy++;
          }
        }

        loop_ub = r2->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cvistmp->data[r2->data[i0] - 1] = 1.0;
        }
      }

      loop_ub = cvistmp->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_loop_ub = cvistmp->size[0];
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          ccdp_cvis->data[(i1 + ccdp_cvis->size[0] * i0) + ccdp_cvis->size[0] *
            ccdp_cvis->size[1] * ((int)((1.0 + (double)tt) + 1.0) - 1)] =
            cvistmp->data[i1 + cvistmp->size[0] * i0];
        }
      }

      //
    }

    //  -- [ Cost: Ctrack ] -- %
    //  sensing region
    for (ii = 0; ii < (int)ndir; ii++) {
      // ccdp.ctrack(tt+1).val(:,:,ii) = reshape(sum(1-normcdf(bsxfun(@plus,costparam.A(:,:,ii)*[ccdp.xs(:)-pEst(tt).mean(1),ccdp.ys(:)-pEst(tt).mean(2)]',costparam.cc)/pEst(tt).sig),1) > threshold_track,[rlen,clen]);% matrix of normal vectors of sensing region 
      iy = ccdp->xs->size[0] * ccdp->xs->size[1];
      mtmp = pEst->data[tt].mean->data[0];
      n = ccdp->xs->size[0] * ccdp->xs->size[1];
      i0 = g_ccdp->size[0];
      g_ccdp->size[0] = iy;
      emxEnsureCapacity((emxArray__common *)g_ccdp, i0, (int)sizeof(double));
      for (i0 = 0; i0 < iy; i0++) {
        g_ccdp->data[i0] = ccdp->xs->data[i0] - mtmp;
      }

      iy = ccdp->ys->size[0] * ccdp->ys->size[1];
      mtmp = pEst->data[tt].mean->data[1];
      br = ccdp->ys->size[0] * ccdp->ys->size[1];
      i0 = h_ccdp->size[0];
      h_ccdp->size[0] = iy;
      emxEnsureCapacity((emxArray__common *)h_ccdp, i0, (int)sizeof(double));
      for (i0 = 0; i0 < iy; i0++) {
        h_ccdp->data[i0] = ccdp->ys->data[i0] - mtmp;
      }

      i0 = b->size[0] * b->size[1];
      b->size[0] = 2;
      b->size[1] = n;
      emxEnsureCapacity((emxArray__common *)b, i0, (int)sizeof(double));
      for (i0 = 0; i0 < n; i0++) {
        b->data[b->size[0] * i0] = g_ccdp->data[i0];
      }

      for (i0 = 0; i0 < br; i0++) {
        b->data[1 + b->size[0] * i0] = h_ccdp->data[i0];
      }

      i0 = costparam->A->size[0];
      currs_idx[1] = (unsigned int)b->size[1];
      i1 = costparam->A->size[0];
      i2 = y->size[0] * y->size[1];
      y->size[0] = i0;
      emxEnsureCapacity((emxArray__common *)y, i2, (int)sizeof(double));
      i2 = y->size[0] * y->size[1];
      y->size[1] = (int)currs_idx[1];
      emxEnsureCapacity((emxArray__common *)y, i2, (int)sizeof(double));
      loop_ub = i0 * (int)currs_idx[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        y->data[i0] = 0.0;
      }

      i0 = costparam->A->size[0];
      if ((i0 == 0) || (b->size[1] == 0)) {
      } else {
        i0 = costparam->A->size[0];
        cindx = i0 * (b->size[1] - 1);
        n = 0;
        while ((i1 > 0) && (n <= cindx)) {
          i0 = n + i1;
          for (ixstop = n; ixstop + 1 <= i0; ixstop++) {
            y->data[ixstop] = 0.0;
          }

          n += i1;
        }

        br = 0;
        n = 0;
        while ((i1 > 0) && (n <= cindx)) {
          iy = 0;
          for (b_n = br; b_n + 1 <= br + 2; b_n++) {
            if (b->data[b_n] != 0.0) {
              k = iy;
              i0 = n + i1;
              for (ixstop = n; ixstop + 1 <= i0; ixstop++) {
                k++;
                loop_ub = costparam->A->size[0];
                i2 = r3->size[0] * r3->size[1];
                r3->size[0] = loop_ub;
                r3->size[1] = 2;
                emxEnsureCapacity((emxArray__common *)r3, i2, (int)sizeof(double));
                for (i2 = 0; i2 < 2; i2++) {
                  for (itmp = 0; itmp < loop_ub; itmp++) {
                    r3->data[itmp + r3->size[0] * i2] = costparam->A->data[(itmp
                      + costparam->A->size[0] * i2) + costparam->A->size[0] *
                      costparam->A->size[1] * ii];
                  }
                }

                i2 = r3->size[0];
                y->data[ixstop] += b->data[b_n] * r3->data[(k - 1) % r3->size[0]
                  + r3->size[0] * div_nzp_s32_floor(k - 1, i2)];
              }
            }

            iy += i1;
          }

          br += 2;
          n += i1;
        }
      }

      bsxfun(y, costparam->cc, A);
      i0 = b_A->size[0] * b_A->size[1];
      b_A->size[0] = A->size[0];
      b_A->size[1] = A->size[1];
      emxEnsureCapacity((emxArray__common *)b_A, i0, (int)sizeof(double));
      loop_ub = A->size[0] * A->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_A->data[i0] = A->data[i0] / pEst->data[tt].sig;
      }

      normcdf(b_A, A);
      i0 = r7->size[0] * r7->size[1];
      r7->size[0] = A->size[0];
      r7->size[1] = A->size[1];
      emxEnsureCapacity((emxArray__common *)r7, i0, (int)sizeof(double));
      loop_ub = A->size[0] * A->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        r7->data[i0] = 1.0 - A->data[i0];
      }

      b_sum(r7, r6);
      n = r6->size[1];
      loop_ub = r6->size[0] * r6->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        x_data[i0] = (r6->data[i0] > threshold_track);
      }

      lagrng[0] = (unsigned char)rlen;
      lagrng[1] = (unsigned char)clen;
      for (i0 = 0; i0 < 2; i0++) {
        sz[i0] = (unsigned char)lagrng[i0];
      }

      iy = sz[0];
      for (k = 0; k + 1 <= n; k++) {
        CompMat_data[k] = x_data[k];
      }

      loop_ub = sz[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        for (i1 = 0; i1 < iy; i1++) {
          ccdp_ctrack->data[((i1 + ccdp_ctrack->size[0] * i0) +
                             ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ii) +
            ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
            ((int)((1.0 + (double)tt) + 1.0) - 1)] = CompMat_data[i1 + iy * i0];
        }
      }

      //  matrix of normal vectors of sensing region
    }

    //  -- [Cost: Cavoid ] -- %
    //  probability of collision is determined by Rfree
    i0 = b_ccdp->size[0] * b_ccdp->size[1];
    b_ccdp->size[0] = ccdp->gmap.size[0];
    b_ccdp->size[1] = ccdp->gmap.size[1];
    emxEnsureCapacity((emxArray__common *)b_ccdp, i0, (int)sizeof(double));
    loop_ub = ccdp->gmap.size[0] * ccdp->gmap.size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_ccdp->data[i0] = ccdp->gmap.data[i0];
    }

    conv2(b_ccdp, r4);
    i0 = r4->size[0] * r4->size[1];
    emxEnsureCapacity((emxArray__common *)r4, i0, (int)sizeof(double));
    i0 = r4->size[0];
    i1 = r4->size[1];
    loop_ub = i0 * i1;
    for (i0 = 0; i0 < loop_ub; i0++) {
      r4->data[i0] = (r4->data[i0] >= 1.0);
    }

    loop_ub = r4->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_loop_ub = r4->size[0];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        ccdp_cavoid->data[(i1 + ccdp_cavoid->size[0] * i0) + ccdp_cavoid->size[0]
          * ccdp_cavoid->size[1] * ((int)((1.0 + (double)tt) + 1.0) - 1)] =
          r4->data[i1 + r4->size[0] * i0];
      }
    }

    //  -- [ value of constraint ] -- %
    // ccdp.cconst(tt+1).val = bsxfun(@or,ccdp.ctrack(tt+1).val,ccdp.cavoid(:,:,tt+1)); 
    loop_ub = ccdp_ctrack->size[0];
    b_loop_ub = ccdp_ctrack->size[1];
    b_n = ccdp_ctrack->size[2];
    i0 = b_ccdp_ctrack->size[0] * b_ccdp_ctrack->size[1] * b_ccdp_ctrack->size[2];
    b_ccdp_ctrack->size[0] = loop_ub;
    b_ccdp_ctrack->size[1] = b_loop_ub;
    b_ccdp_ctrack->size[2] = b_n;
    emxEnsureCapacity((emxArray__common *)b_ccdp_ctrack, i0, (int)sizeof(double));
    for (i0 = 0; i0 < b_n; i0++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_ccdp_ctrack->data[(i2 + b_ccdp_ctrack->size[0] * i1) +
            b_ccdp_ctrack->size[0] * b_ccdp_ctrack->size[1] * i0] =
            ccdp_ctrack->data[((i2 + ccdp_ctrack->size[0] * i1) +
                               ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * i0)
            + ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2]
            * ((int)((1.0 + (double)tt) + 1.0) - 1)];
        }
      }
    }

    loop_ub = ccdp_cavoid->size[0];
    b_loop_ub = ccdp_cavoid->size[1];
    i0 = b_ccdp_cavoid->size[0] * b_ccdp_cavoid->size[1];
    b_ccdp_cavoid->size[0] = loop_ub;
    b_ccdp_cavoid->size[1] = b_loop_ub;
    emxEnsureCapacity((emxArray__common *)b_ccdp_cavoid, i0, (int)sizeof(double));
    for (i0 = 0; i0 < b_loop_ub; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_ccdp_cavoid->data[i1 + b_ccdp_cavoid->size[0] * i0] =
          ccdp_cavoid->data[(i1 + ccdp_cavoid->size[0] * i0) + ccdp_cavoid->
          size[0] * ccdp_cavoid->size[1] * ((int)((1.0 + (double)tt) + 1.0) - 1)];
      }
    }

    b_bsxfun(b_ccdp_ctrack, b_ccdp_cavoid, r5);
    i0 = r0->size[0] * r0->size[1] * r0->size[2];
    r0->size[0] = r5->size[0];
    r0->size[1] = r5->size[1];
    r0->size[2] = r5->size[2];
    emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
    loop_ub = r5->size[0] * r5->size[1] * r5->size[2];
    for (i0 = 0; i0 < loop_ub; i0++) {
      r0->data[i0] = r5->data[i0];
    }

    loop_ub = r0->size[2];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_loop_ub = r0->size[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_n = r0->size[0];
        for (i2 = 0; i2 < b_n; i2++) {
          ccdp_cconst->data[((i2 + ccdp_cconst->size[0] * i1) +
                             ccdp_cconst->size[0] * ccdp_cconst->size[1] * i0) +
            ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
            ((int)((1.0 + (double)tt) + 1.0) - 1)] = r0->data[(i2 + r0->size[0] *
            i1) + r0->size[0] * r0->size[1] * i0];
        }
      }
    }

    tt++;
  }

  emxFree_real_T(&h_ccdp);
  emxFree_real_T(&g_ccdp);
  emxFree_real_T(&b_A);
  emxFree_real_T(&r7);
  emxFree_real_T(&f_ccdp);
  emxFree_real_T(&e_ccdp);
  emxFree_real_T(&d_ccdp);
  emxFree_real_T(&c_ccdp);
  emxFree_real_T(&b_ccdp);
  emxFree_real_T(&b_ccdp_cavoid);
  emxFree_real_T(&b_ccdp_ctrack);
  emxFree_real_T(&r6);
  emxFree_boolean_T(&r5);
  emxFree_real_T(&r4);
  emxFree_real_T(&r3);
  emxFree_real_T(&b);
  emxFree_real_T(&y);
  emxFree_real_T(&A);
  emxFree_int32_T(&r2);

  //  -- [ Backward recursion ] -- %
  //  find the optimal control when lambda is given
  lagcoeff = 0.0;

  // lagrangian coefficient
  for (i0 = 0; i0 < 2; i0++) {
    lagrng[i0] = i0;
  }

  lag_feas = 1;

  //  use to check the feasibility
  flag_converge = 0;
  ilagran = 1;
  emxInit_real_T(&Optctrl_col, 4);
  emxInit_real_T(&Optctrl_dirs, 4);
  emxInit_real_T(&Jmin, 4);
  c_emxInit_real_T(&b_currs_idx, 2);
  c_emxInit_real_T(&optidx, 2);
  c_emxInit_real_T(&r8, 2);
  b_emxInit_int32_T(&iindx, 2);
  b_emxInit_real_T(&b_lagcoeff, 3);
  c_emxInit_real_T(&b_lag_feas, 2);
  b_emxInit_real_T(&c_lagcoeff, 3);
  c_emxInit_real_T(&c_lag_feas, 2);
  c_emxInit_real_T(&b_mindiridx, 2);
  c_emxInit_real_T(&b_Optctrl_dirs, 2);
  b_emxInit_real_T(&b_Jmin, 3);
  b_emxInit_real_T(&c_Jmin, 3);
  d_emxInit_real_T(&b_nextstate, 1);
  d_emxInit_real_T(&c_nextstate, 1);
  b_emxInit_real_T(&d_Jmin, 3);
  d_emxInit_real_T(&d_nextstate, 1);
  c_emxInit_real_T(&r9, 2);
  c_emxInit_real_T(&CompMat, 2);
  c_emxInit_real_T(&b_CompMat, 2);
  c_emxInit_real_T(&c_CompMat, 2);
  exitg1 = false;
  while ((!exitg1) && (ilagran - 1 < 100)) {
    //  initialize the optimal control: 'col': current column+col,
    //  'row': current row+'row',   dirs: replace current dirs with dirs
    i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
      ccdp_ctrack->size[3];
    ccdp_ctrack->size[0] = rlen;
    ccdp_ctrack->size[1] = clen;
    ccdp_ctrack->size[2] = (int)ndir;
    ccdp_ctrack->size[3] = (int)H;
    emxEnsureCapacity((emxArray__common *)ccdp_ctrack, i0, (int)sizeof(double));
    loop_ub = rlen * clen * (int)ndir * (int)H;
    for (i0 = 0; i0 < loop_ub; i0++) {
      ccdp_ctrack->data[i0] = 0.0;
    }

    i0 = Optctrl_col->size[0] * Optctrl_col->size[1] * Optctrl_col->size[2] *
      Optctrl_col->size[3];
    Optctrl_col->size[0] = rlen;
    Optctrl_col->size[1] = clen;
    Optctrl_col->size[2] = (int)ndir;
    Optctrl_col->size[3] = (int)H;
    emxEnsureCapacity((emxArray__common *)Optctrl_col, i0, (int)sizeof(double));
    loop_ub = rlen * clen * (int)ndir * (int)H;
    for (i0 = 0; i0 < loop_ub; i0++) {
      Optctrl_col->data[i0] = 0.0;
    }

    i0 = Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * Optctrl_dirs->size[2] *
      Optctrl_dirs->size[3];
    Optctrl_dirs->size[0] = rlen;
    Optctrl_dirs->size[1] = clen;
    Optctrl_dirs->size[2] = (int)ndir;
    Optctrl_dirs->size[3] = (int)H;
    emxEnsureCapacity((emxArray__common *)Optctrl_dirs, i0, (int)sizeof(double));
    loop_ub = rlen * clen * (int)ndir * (int)H;
    for (i0 = 0; i0 < loop_ub; i0++) {
      Optctrl_dirs->data[i0] = 0.0;
    }

    i0 = Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * Jmin->size[3];
    Jmin->size[0] = rlen;
    emxEnsureCapacity((emxArray__common *)Jmin, i0, (int)sizeof(double));
    i0 = Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * Jmin->size[3];
    Jmin->size[1] = clen;
    emxEnsureCapacity((emxArray__common *)Jmin, i0, (int)sizeof(double));
    i0 = Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * Jmin->size[3];
    Jmin->size[2] = (int)ndir;
    emxEnsureCapacity((emxArray__common *)Jmin, i0, (int)sizeof(double));
    i0 = Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * Jmin->size[3];
    Jmin->size[3] = (int)(H + 1.0);
    emxEnsureCapacity((emxArray__common *)Jmin, i0, (int)sizeof(double));
    loop_ub = rlen * clen * (int)ndir * (int)(H + 1.0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      Jmin->data[i0] = 100.0;
    }

    loop_ub = ccdp_cconst->size[0];
    b_loop_ub = ccdp_cconst->size[1];
    b_n = ccdp_cconst->size[2];
    i0 = b_lagcoeff->size[0] * b_lagcoeff->size[1] * b_lagcoeff->size[2];
    b_lagcoeff->size[0] = loop_ub;
    b_lagcoeff->size[1] = b_loop_ub;
    b_lagcoeff->size[2] = b_n;
    emxEnsureCapacity((emxArray__common *)b_lagcoeff, i0, (int)sizeof(double));
    for (i0 = 0; i0 < b_n; i0++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_lagcoeff->data[(i2 + b_lagcoeff->size[0] * i1) + b_lagcoeff->size[0]
            * b_lagcoeff->size[1] * i0] = lagcoeff * ccdp_cconst->data[((i2 +
            ccdp_cconst->size[0] * i1) + ccdp_cconst->size[0] *
            ccdp_cconst->size[1] * i0) + ccdp_cconst->size[0] *
            ccdp_cconst->size[1] * ccdp_cconst->size[2] * ((int)(H + 1.0) - 1)];
        }
      }
    }

    loop_ub = ccdp_cvis->size[0];
    b_loop_ub = ccdp_cvis->size[1];
    i0 = b_lag_feas->size[0] * b_lag_feas->size[1];
    b_lag_feas->size[0] = loop_ub;
    b_lag_feas->size[1] = b_loop_ub;
    emxEnsureCapacity((emxArray__common *)b_lag_feas, i0, (int)sizeof(double));
    for (i0 = 0; i0 < b_loop_ub; i0++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_lag_feas->data[i1 + b_lag_feas->size[0] * i0] = (double)lag_feas *
          ccdp_cvis->data[(i1 + ccdp_cvis->size[0] * i0) + ccdp_cvis->size[0] *
          ccdp_cvis->size[1] * ((int)(H + 1.0) - 1)];
      }
    }

    c_bsxfun(b_lagcoeff, b_lag_feas, r0);
    loop_ub = r0->size[2];
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_loop_ub = r0->size[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_n = r0->size[0];
        for (i2 = 0; i2 < b_n; i2++) {
          Jmin->data[((i2 + Jmin->size[0] * i1) + Jmin->size[0] * Jmin->size[1] *
                      i0) + Jmin->size[0] * Jmin->size[1] * Jmin->size[2] *
            ((int)(H + 1.0) - 1)] = r0->data[(i2 + r0->size[0] * i1) + r0->size
            [0] * r0->size[1] * i0];
        }
      }
    }

    // Value: Cvis + lambda * Ctrack
    // Optctrl(1:H)=struct('row',zeros([rlen,clen,ndir]),'col',zeros([rlen,clen,ndir]),'dirs',zeros([rlen,clen,ndir])); 
    // Jmin(1:H+1) = struct('Jmin',100*ones([rlen,clen,ndir]));
    // Jmin(H+1).Jmin = bsxfun(@plus, lagcoeff*ccdp.cconst(H+1).val, lag_feas*ccdp.cvis(:,:,H+1)); %Value: Cvis + lambda * Ctrack 
    for (tt = 0; tt < (int)-(1.0 + (-1.0 - H)); tt++) {
      b_tt = H + -(double)tt;

      //  lagrangian - onestep
      loop_ub = ccdp_cconst->size[0];
      b_loop_ub = ccdp_cconst->size[1];
      b_n = ccdp_cconst->size[2];
      i0 = c_lagcoeff->size[0] * c_lagcoeff->size[1] * c_lagcoeff->size[2];
      c_lagcoeff->size[0] = loop_ub;
      c_lagcoeff->size[1] = b_loop_ub;
      c_lagcoeff->size[2] = b_n;
      emxEnsureCapacity((emxArray__common *)c_lagcoeff, i0, (int)sizeof(double));
      for (i0 = 0; i0 < b_n; i0++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            c_lagcoeff->data[(i2 + c_lagcoeff->size[0] * i1) + c_lagcoeff->size
              [0] * c_lagcoeff->size[1] * i0] = lagcoeff * ccdp_cconst->data
              [((i2 + ccdp_cconst->size[0] * i1) + ccdp_cconst->size[0] *
                ccdp_cconst->size[1] * i0) + ccdp_cconst->size[0] *
              ccdp_cconst->size[1] * ccdp_cconst->size[2] * ((int)b_tt - 1)];
          }
        }
      }

      loop_ub = ccdp_cvis->size[0];
      b_loop_ub = ccdp_cvis->size[1];
      i0 = c_lag_feas->size[0] * c_lag_feas->size[1];
      c_lag_feas->size[0] = loop_ub;
      c_lag_feas->size[1] = b_loop_ub;
      emxEnsureCapacity((emxArray__common *)c_lag_feas, i0, (int)sizeof(double));
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_lag_feas->data[i1 + c_lag_feas->size[0] * i0] = (double)lag_feas *
            ccdp_cvis->data[(i1 + ccdp_cvis->size[0] * i0) + ccdp_cvis->size[0] *
            ccdp_cvis->size[1] * ((int)b_tt - 1)];
        }
      }

      c_bsxfun(c_lagcoeff, c_lag_feas, ccdp_cavoid);

      // Value: Cvis + lambda * Ctrack
      for (ii = 0; ii < (int)ndir; ii++) {
        loop_ub = Jmin->size[0];
        b_loop_ub = Jmin->size[1];
        i0 = c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2];
        c_Jmin->size[0] = loop_ub;
        c_Jmin->size[1] = b_loop_ub;
        c_Jmin->size[2] = nextstate->data[ii].dir->size[1];
        emxEnsureCapacity((emxArray__common *)c_Jmin, i0, (int)sizeof(double));
        b_n = nextstate->data[ii].dir->size[1];
        for (i0 = 0; i0 < b_n; i0++) {
          for (i1 = 0; i1 < b_loop_ub; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              c_Jmin->data[(i2 + c_Jmin->size[0] * i1) + c_Jmin->size[0] *
                c_Jmin->size[1] * i0] = Jmin->data[((i2 + Jmin->size[0] * i1) +
                Jmin->size[0] * Jmin->size[1] * ((int)nextstate->data[ii]
                .dir->data[nextstate->data[ii].dir->size[0] * i0] - 1)) +
                Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * ((int)(b_tt +
                1.0) - 1)];
            }
          }
        }

        for (i0 = 0; i0 < 3; i0++) {
          outsz[i0] = (unsigned int)c_Jmin->size[i0];
        }

        i0 = angle2target->size[0] * angle2target->size[1];
        angle2target->size[0] = (int)outsz[0];
        angle2target->size[1] = (int)outsz[1];
        emxEnsureCapacity((emxArray__common *)angle2target, i0, (int)sizeof
                          (double));
        i0 = iindx->size[0] * iindx->size[1];
        iindx->size[0] = (int)outsz[0];
        emxEnsureCapacity((emxArray__common *)iindx, i0, (int)sizeof(int));
        i0 = iindx->size[0] * iindx->size[1];
        iindx->size[1] = (int)outsz[1];
        emxEnsureCapacity((emxArray__common *)iindx, i0, (int)sizeof(int));
        loop_ub = (int)outsz[0] * (int)outsz[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          iindx->data[i0] = 1;
        }

        i0 = b_nextstate->size[0];
        b_nextstate->size[0] = nextstate->data[ii].dir->size[1];
        emxEnsureCapacity((emxArray__common *)b_nextstate, i0, (int)sizeof
                          (double));
        loop_ub = nextstate->data[ii].dir->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_nextstate->data[i0] = nextstate->data[ii].dir->data[nextstate->
            data[ii].dir->size[0] * i0];
        }

        c_n = b_nextstate->size[0];
        k = 3;
        exitg3 = false;
        while ((!exitg3) && (k > 2)) {
          i0 = c_nextstate->size[0];
          c_nextstate->size[0] = nextstate->data[ii].dir->size[1];
          emxEnsureCapacity((emxArray__common *)c_nextstate, i0, (int)sizeof
                            (double));
          loop_ub = nextstate->data[ii].dir->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            c_nextstate->data[i0] = nextstate->data[ii].dir->data
              [nextstate->data[ii].dir->size[0] * i0];
          }

          if (c_nextstate->size[0] == 1) {
            k = 2;
          } else {
            exitg3 = true;
          }
        }

        if (3 > k) {
          i0 = Jmin->size[0];
          i1 = Jmin->size[1];
          i2 = d_nextstate->size[0];
          d_nextstate->size[0] = nextstate->data[ii].dir->size[1];
          emxEnsureCapacity((emxArray__common *)d_nextstate, i2, (int)sizeof
                            (double));
          loop_ub = nextstate->data[ii].dir->size[1];
          for (i2 = 0; i2 < loop_ub; i2++) {
            d_nextstate->data[i2] = nextstate->data[ii].dir->data
              [nextstate->data[ii].dir->size[0] * i2];
          }

          vstride = i0 * i1 * d_nextstate->size[0];
        } else {
          vstride = 1;
          for (k = 0; k < 2; k++) {
            loop_ub = Jmin->size[0];
            b_loop_ub = Jmin->size[1];
            i0 = d_Jmin->size[0] * d_Jmin->size[1] * d_Jmin->size[2];
            d_Jmin->size[0] = loop_ub;
            d_Jmin->size[1] = b_loop_ub;
            d_Jmin->size[2] = nextstate->data[ii].dir->size[1];
            emxEnsureCapacity((emxArray__common *)d_Jmin, i0, (int)sizeof(double));
            b_n = nextstate->data[ii].dir->size[1];
            for (i0 = 0; i0 < b_n; i0++) {
              for (i1 = 0; i1 < b_loop_ub; i1++) {
                for (i2 = 0; i2 < loop_ub; i2++) {
                  d_Jmin->data[(i2 + d_Jmin->size[0] * i1) + d_Jmin->size[0] *
                    d_Jmin->size[1] * i0] = Jmin->data[((i2 + Jmin->size[0] * i1)
                    + Jmin->size[0] * Jmin->size[1] * ((int)nextstate->data[ii].
                    dir->data[nextstate->data[ii].dir->size[0] * i0] - 1)) +
                    Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * ((int)(b_tt
                    + 1.0) - 1)];
                }
              }
            }

            vstride *= d_Jmin->size[k];
          }
        }

        k = 0;
        iy = -1;
        for (br = 1; br <= vstride; br++) {
          k++;
          ixstart = k;
          ixstop = k + (c_n - 1) * vstride;
          loop_ub = Jmin->size[0];
          b_loop_ub = Jmin->size[1];
          i0 = r0->size[0] * r0->size[1] * r0->size[2];
          r0->size[0] = loop_ub;
          r0->size[1] = b_loop_ub;
          r0->size[2] = nextstate->data[ii].dir->size[1];
          emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
          b_n = nextstate->data[ii].dir->size[1];
          for (i0 = 0; i0 < b_n; i0++) {
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              for (i2 = 0; i2 < loop_ub; i2++) {
                r0->data[(i2 + r0->size[0] * i1) + r0->size[0] * r0->size[1] *
                  i0] = Jmin->data[((i2 + Jmin->size[0] * i1) + Jmin->size[0] *
                                    Jmin->size[1] * ((int)nextstate->data[ii].
                  dir->data[nextstate->data[ii].dir->size[0] * i0] - 1)) +
                  Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * ((int)(b_tt +
                  1.0) - 1)];
              }
            }
          }

          i0 = r0->size[0];
          i1 = i0 * r0->size[1];
          mtmp = r0->data[((k - 1) % r0->size[0] + r0->size[0] *
                           (div_nzp_s32_floor(k - 1, i0) % r0->size[1])) +
            r0->size[0] * r0->size[1] * div_nzp_s32_floor(k - 1, i1)];
          itmp = 1;
          if (c_n > 1) {
            cindx = 1;
            if (rtIsNaN(mtmp)) {
              n = k + vstride;
              exitg2 = false;
              while ((!exitg2) && (((vstride > 0) && (n <= ixstop)) || ((vstride
                        < 0) && (n >= ixstop)))) {
                cindx++;
                ixstart = n;
                loop_ub = Jmin->size[0];
                b_loop_ub = Jmin->size[1];
                i0 = r0->size[0] * r0->size[1] * r0->size[2];
                r0->size[0] = loop_ub;
                r0->size[1] = b_loop_ub;
                r0->size[2] = nextstate->data[ii].dir->size[1];
                emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
                b_n = nextstate->data[ii].dir->size[1];
                for (i0 = 0; i0 < b_n; i0++) {
                  for (i1 = 0; i1 < b_loop_ub; i1++) {
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      r0->data[(i2 + r0->size[0] * i1) + r0->size[0] * r0->size
                        [1] * i0] = Jmin->data[((i2 + Jmin->size[0] * i1) +
                        Jmin->size[0] * Jmin->size[1] * ((int)nextstate->data[ii]
                        .dir->data[nextstate->data[ii].dir->size[0] * i0] - 1))
                        + Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * ((int)
                        (b_tt + 1.0) - 1)];
                    }
                  }
                }

                i0 = r0->size[0];
                i1 = i0 * r0->size[1];
                if (!rtIsNaN(r0->data[((n - 1) % r0->size[0] + r0->size[0] *
                                       (div_nzp_s32_floor(n - 1, i0) % r0->size
                                        [1])) + r0->size[0] * r0->size[1] *
                             div_nzp_s32_floor(n - 1, i1)])) {
                  loop_ub = Jmin->size[0];
                  b_loop_ub = Jmin->size[1];
                  i0 = r0->size[0] * r0->size[1] * r0->size[2];
                  r0->size[0] = loop_ub;
                  r0->size[1] = b_loop_ub;
                  r0->size[2] = nextstate->data[ii].dir->size[1];
                  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof
                                    (double));
                  b_n = nextstate->data[ii].dir->size[1];
                  for (i0 = 0; i0 < b_n; i0++) {
                    for (i1 = 0; i1 < b_loop_ub; i1++) {
                      for (i2 = 0; i2 < loop_ub; i2++) {
                        r0->data[(i2 + r0->size[0] * i1) + r0->size[0] *
                          r0->size[1] * i0] = Jmin->data[((i2 + Jmin->size[0] *
                          i1) + Jmin->size[0] * Jmin->size[1] * ((int)
                          nextstate->data[ii].dir->data[nextstate->data[ii].
                          dir->size[0] * i0] - 1)) + Jmin->size[0] * Jmin->size
                          [1] * Jmin->size[2] * ((int)(b_tt + 1.0) - 1)];
                      }
                    }
                  }

                  i0 = r0->size[0];
                  i1 = i0 * r0->size[1];
                  mtmp = r0->data[((n - 1) % r0->size[0] + r0->size[0] *
                                   (div_nzp_s32_floor(n - 1, i0) % r0->size[1]))
                    + r0->size[0] * r0->size[1] * div_nzp_s32_floor(n - 1, i1)];
                  itmp = cindx;
                  exitg2 = true;
                } else {
                  n += vstride;
                }
              }
            }

            if (ixstart < ixstop) {
              n = ixstart + vstride;
              while (((vstride > 0) && (n <= ixstop)) || ((vstride < 0) && (n >=
                       ixstop))) {
                cindx++;
                loop_ub = Jmin->size[0];
                b_loop_ub = Jmin->size[1];
                i0 = r0->size[0] * r0->size[1] * r0->size[2];
                r0->size[0] = loop_ub;
                r0->size[1] = b_loop_ub;
                r0->size[2] = nextstate->data[ii].dir->size[1];
                emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof(double));
                b_n = nextstate->data[ii].dir->size[1];
                for (i0 = 0; i0 < b_n; i0++) {
                  for (i1 = 0; i1 < b_loop_ub; i1++) {
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      r0->data[(i2 + r0->size[0] * i1) + r0->size[0] * r0->size
                        [1] * i0] = Jmin->data[((i2 + Jmin->size[0] * i1) +
                        Jmin->size[0] * Jmin->size[1] * ((int)nextstate->data[ii]
                        .dir->data[nextstate->data[ii].dir->size[0] * i0] - 1))
                        + Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * ((int)
                        (b_tt + 1.0) - 1)];
                    }
                  }
                }

                i0 = r0->size[0];
                i1 = i0 * r0->size[1];
                if (r0->data[((n - 1) % r0->size[0] + r0->size[0] *
                              (div_nzp_s32_floor(n - 1, i0) % r0->size[1])) +
                    r0->size[0] * r0->size[1] * div_nzp_s32_floor(n - 1, i1)] <
                    mtmp) {
                  loop_ub = Jmin->size[0];
                  b_loop_ub = Jmin->size[1];
                  i0 = r0->size[0] * r0->size[1] * r0->size[2];
                  r0->size[0] = loop_ub;
                  r0->size[1] = b_loop_ub;
                  r0->size[2] = nextstate->data[ii].dir->size[1];
                  emxEnsureCapacity((emxArray__common *)r0, i0, (int)sizeof
                                    (double));
                  b_n = nextstate->data[ii].dir->size[1];
                  for (i0 = 0; i0 < b_n; i0++) {
                    for (i1 = 0; i1 < b_loop_ub; i1++) {
                      for (i2 = 0; i2 < loop_ub; i2++) {
                        r0->data[(i2 + r0->size[0] * i1) + r0->size[0] *
                          r0->size[1] * i0] = Jmin->data[((i2 + Jmin->size[0] *
                          i1) + Jmin->size[0] * Jmin->size[1] * ((int)
                          nextstate->data[ii].dir->data[nextstate->data[ii].
                          dir->size[0] * i0] - 1)) + Jmin->size[0] * Jmin->size
                          [1] * Jmin->size[2] * ((int)(b_tt + 1.0) - 1)];
                      }
                    }
                  }

                  i0 = r0->size[0];
                  i1 = i0 * r0->size[1];
                  mtmp = r0->data[((n - 1) % r0->size[0] + r0->size[0] *
                                   (div_nzp_s32_floor(n - 1, i0) % r0->size[1]))
                    + r0->size[0] * r0->size[1] * div_nzp_s32_floor(n - 1, i1)];
                  itmp = cindx;
                }

                n += vstride;
              }
            }
          }

          iy++;
          angle2target->data[iy] = mtmp;
          iindx->data[iy] = itmp;
        }

        i0 = cvistmp->size[0] * cvistmp->size[1];
        cvistmp->size[0] = iindx->size[0];
        cvistmp->size[1] = iindx->size[1];
        emxEnsureCapacity((emxArray__common *)cvistmp, i0, (int)sizeof(double));
        loop_ub = iindx->size[0] * iindx->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cvistmp->data[i0] = iindx->data[i0];
        }

        i0 = mindiridx->size[0] * mindiridx->size[1];
        mindiridx->size[0] = cvistmp->size[0];
        mindiridx->size[1] = cvistmp->size[1];
        emxEnsureCapacity((emxArray__common *)mindiridx, i0, (int)sizeof(double));
        loop_ub = cvistmp->size[0] * cvistmp->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          mindiridx->data[i0] = nextstate->data[ii].dir->data[(int)cvistmp->
            data[i0] - 1];
        }

        //  find the optimal control-onestep
        for (cindx = 0; cindx < nextstate->data[ii].sidxs->size[0]; cindx++) {
          if ((1.0 >= 1.0 - nextstate->data[ii].sidxs->data[cindx]) || rtIsNaN
              (1.0 - nextstate->data[ii].sidxs->data[cindx])) {
            anew = 1.0;
          } else {
            anew = 1.0 - nextstate->data[ii].sidxs->data[cindx];
          }

          mtmp = (double)rlen - nextstate->data[ii].sidxs->data[cindx];
          if ((rlen <= mtmp) || rtIsNaN(mtmp)) {
            mtmp = rlen;
          }

          if (rtIsNaN(anew) || rtIsNaN(mtmp)) {
            c_n = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else if (mtmp < anew) {
            c_n = -1;
            apnd = mtmp;
          } else if (rtIsInf(anew) || rtIsInf(mtmp)) {
            c_n = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else {
            ndbl = floor((mtmp - anew) + 0.5);
            apnd = anew + ndbl;
            cdiff = apnd - mtmp;
            absa = fabs(anew);
            absb = fabs(mtmp);
            if ((absa >= absb) || rtIsNaN(absb)) {
              absb = absa;
            }

            if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
              ndbl++;
              apnd = mtmp;
            } else if (cdiff > 0.0) {
              apnd = anew + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              c_n = (int)ndbl - 1;
            } else {
              c_n = -1;
            }
          }

          if (c_n + 1 > 0) {
            original_rng_r_data[0] = anew;
            if (c_n + 1 > 1) {
              original_rng_r_data[c_n] = apnd;
              iy = (c_n + (c_n < 0)) >> 1;
              for (k = 1; k < iy; k++) {
                original_rng_r_data[k] = anew + (double)k;
                original_rng_r_data[c_n - k] = apnd - (double)k;
              }

              if (iy << 1 == c_n) {
                original_rng_r_data[iy] = (anew + apnd) / 2.0;
              } else {
                original_rng_r_data[iy] = anew + (double)iy;
                original_rng_r_data[iy + 1] = apnd - (double)iy;
              }
            }
          }

          if ((1.0 >= 1.0 - nextstate->data[ii].sidxs->data[cindx +
               nextstate->data[ii].sidxs->size[0]]) || rtIsNaN(1.0 -
               nextstate->data[ii].sidxs->data[cindx + nextstate->data[ii].
               sidxs->size[0]])) {
            anew = 1.0;
          } else {
            anew = 1.0 - nextstate->data[ii].sidxs->data[cindx + nextstate->
              data[ii].sidxs->size[0]];
          }

          mtmp = (double)clen - nextstate->data[ii].sidxs->data[cindx +
            nextstate->data[ii].sidxs->size[0]];
          if ((clen <= mtmp) || rtIsNaN(mtmp)) {
            mtmp = clen;
          }

          if (rtIsNaN(anew) || rtIsNaN(mtmp)) {
            n = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else if (mtmp < anew) {
            n = -1;
            apnd = mtmp;
          } else if (rtIsInf(anew) || rtIsInf(mtmp)) {
            n = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else {
            ndbl = floor((mtmp - anew) + 0.5);
            apnd = anew + ndbl;
            cdiff = apnd - mtmp;
            absa = fabs(anew);
            absb = fabs(mtmp);
            if ((absa >= absb) || rtIsNaN(absb)) {
              absb = absa;
            }

            if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
              ndbl++;
              apnd = mtmp;
            } else if (cdiff > 0.0) {
              apnd = anew + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              n = (int)ndbl - 1;
            } else {
              n = -1;
            }
          }

          if (n + 1 > 0) {
            original_rng_c_data[0] = anew;
            if (n + 1 > 1) {
              original_rng_c_data[n] = apnd;
              iy = (n + (n < 0)) >> 1;
              for (k = 1; k < iy; k++) {
                original_rng_c_data[k] = anew + (double)k;
                original_rng_c_data[n - k] = apnd - (double)k;
              }

              if (iy << 1 == n) {
                original_rng_c_data[iy] = (anew + apnd) / 2.0;
              } else {
                original_rng_c_data[iy] = anew + (double)iy;
                original_rng_c_data[iy + 1] = apnd - (double)iy;
              }
            }
          }

          if ((1.0 >= 1.0 + nextstate->data[ii].sidxs->data[cindx]) || rtIsNaN
              (1.0 + nextstate->data[ii].sidxs->data[cindx])) {
            anew = 1.0;
          } else {
            anew = 1.0 + nextstate->data[ii].sidxs->data[cindx];
          }

          mtmp = (double)rlen + nextstate->data[ii].sidxs->data[cindx];
          if ((rlen <= mtmp) || rtIsNaN(mtmp)) {
            mtmp = rlen;
          }

          if (rtIsNaN(anew) || rtIsNaN(mtmp)) {
            br = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else if (mtmp < anew) {
            br = -1;
            apnd = mtmp;
          } else if (rtIsInf(anew) || rtIsInf(mtmp)) {
            br = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else {
            ndbl = floor((mtmp - anew) + 0.5);
            apnd = anew + ndbl;
            cdiff = apnd - mtmp;
            absa = fabs(anew);
            absb = fabs(mtmp);
            if ((absa >= absb) || rtIsNaN(absb)) {
              absb = absa;
            }

            if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
              ndbl++;
              apnd = mtmp;
            } else if (cdiff > 0.0) {
              apnd = anew + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              br = (int)ndbl - 1;
            } else {
              br = -1;
            }
          }

          if (br + 1 > 0) {
            comp_rng_r_data[0] = anew;
            if (br + 1 > 1) {
              comp_rng_r_data[br] = apnd;
              iy = (br + (br < 0)) >> 1;
              for (k = 1; k < iy; k++) {
                comp_rng_r_data[k] = anew + (double)k;
                comp_rng_r_data[br - k] = apnd - (double)k;
              }

              if (iy << 1 == br) {
                comp_rng_r_data[iy] = (anew + apnd) / 2.0;
              } else {
                comp_rng_r_data[iy] = anew + (double)iy;
                comp_rng_r_data[iy + 1] = apnd - (double)iy;
              }
            }
          }

          if ((1.0 >= 1.0 + nextstate->data[ii].sidxs->data[cindx +
               nextstate->data[ii].sidxs->size[0]]) || rtIsNaN(1.0 +
               nextstate->data[ii].sidxs->data[cindx + nextstate->data[ii].
               sidxs->size[0]])) {
            anew = 1.0;
          } else {
            anew = 1.0 + nextstate->data[ii].sidxs->data[cindx + nextstate->
              data[ii].sidxs->size[0]];
          }

          mtmp = (double)clen + nextstate->data[ii].sidxs->data[cindx +
            nextstate->data[ii].sidxs->size[0]];
          if ((clen <= mtmp) || rtIsNaN(mtmp)) {
            mtmp = clen;
          }

          if (rtIsNaN(anew) || rtIsNaN(mtmp)) {
            b_n = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else if (mtmp < anew) {
            b_n = -1;
            apnd = mtmp;
          } else if (rtIsInf(anew) || rtIsInf(mtmp)) {
            b_n = 0;
            anew = rtNaN;
            apnd = mtmp;
          } else {
            ndbl = floor((mtmp - anew) + 0.5);
            apnd = anew + ndbl;
            cdiff = apnd - mtmp;
            absa = fabs(anew);
            absb = fabs(mtmp);
            if ((absa >= absb) || rtIsNaN(absb)) {
              absb = absa;
            }

            if (fabs(cdiff) < 4.4408920985006262E-16 * absb) {
              ndbl++;
              apnd = mtmp;
            } else if (cdiff > 0.0) {
              apnd = anew + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            if (ndbl >= 0.0) {
              b_n = (int)ndbl - 1;
            } else {
              b_n = -1;
            }
          }

          if (b_n + 1 > 0) {
            comp_rng_c_data[0] = anew;
            if (b_n + 1 > 1) {
              comp_rng_c_data[b_n] = apnd;
              iy = (b_n + (b_n < 0)) >> 1;
              for (k = 1; k < iy; k++) {
                comp_rng_c_data[k] = anew + (double)k;
                comp_rng_c_data[b_n - k] = apnd - (double)k;
              }

              if (iy << 1 == b_n) {
                comp_rng_c_data[iy] = (anew + apnd) / 2.0;
              } else {
                comp_rng_c_data[iy] = anew + (double)iy;
                comp_rng_c_data[iy + 1] = apnd - (double)iy;
              }
            }
          }

          //  compare two matrix
          i0 = b_Optctrl_dirs->size[0] * b_Optctrl_dirs->size[1];
          b_Optctrl_dirs->size[0] = c_n + 1;
          b_Optctrl_dirs->size[1] = n + 1;
          emxEnsureCapacity((emxArray__common *)b_Optctrl_dirs, i0, (int)sizeof
                            (double));
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = c_n + 1;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              b_Optctrl_dirs->data[i1 + b_Optctrl_dirs->size[0] * i0] =
                Optctrl_dirs->data[((((int)original_rng_r_data[i1] +
                Optctrl_dirs->size[0] * ((int)original_rng_c_data[i0] - 1)) +
                Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * ii) +
                                    Optctrl_dirs->size[0] * Optctrl_dirs->size[1]
                                    * Optctrl_dirs->size[2] * ((int)b_tt - 1)) -
                1];
            }
          }

          b_abs(b_Optctrl_dirs, r1);
          i0 = b_mindiridx->size[0] * b_mindiridx->size[1];
          b_mindiridx->size[0] = br + 1;
          b_mindiridx->size[1] = b_n + 1;
          emxEnsureCapacity((emxArray__common *)b_mindiridx, i0, (int)sizeof
                            (double));
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = br + 1;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              b_mindiridx->data[i1 + b_mindiridx->size[0] * i0] =
                mindiridx->data[((int)comp_rng_r_data[i1] + mindiridx->size[0] *
                                 ((int)comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          b_abs(b_mindiridx, r8);
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = c_n + 1;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              CompMat_data[i1 + (c_n + 1) * i0] = ((Jmin->data[((((int)
                original_rng_r_data[i1] + Jmin->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + Jmin->size[0] * Jmin->size[1] *
                ii) + Jmin->size[0] * Jmin->size[1] * Jmin->size[2] * ((int)b_tt
                - 1)) - 1] > angle2target->data[((int)comp_rng_r_data[i1] +
                angle2target->size[0] * ((int)comp_rng_c_data[i0] - 1)) - 1]) ||
                ((Jmin->data[((((int)original_rng_r_data[i1] + Jmin->size[0] *
                                ((int)original_rng_c_data[i0] - 1)) + Jmin->
                               size[0] * Jmin->size[1] * ii) + Jmin->size[0] *
                              Jmin->size[1] * Jmin->size[2] * ((int)b_tt - 1)) -
                  1] == angle2target->data[((int)comp_rng_r_data[i1] +
                angle2target->size[0] * ((int)comp_rng_c_data[i0] - 1)) - 1]) &&
                 (r1->data[i1 + r1->size[0] * i0] > r8->data[i1 + r8->size[0] *
                  i0])));
            }
          }

          //  update Jmin
          i0 = r9->size[0] * r9->size[1];
          r9->size[0] = c_n + 1;
          r9->size[1] = n + 1;
          emxEnsureCapacity((emxArray__common *)r9, i0, (int)sizeof(double));
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = c_n + 1;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              r9->data[i1 + r9->size[0] * i0] = (1.0 - (double)CompMat_data[i1 +
                (c_n + 1) * i0]) * Jmin->data[((((int)original_rng_r_data[i1] +
                Jmin->size[0] * ((int)original_rng_c_data[i0] - 1)) + Jmin->
                size[0] * Jmin->size[1] * ii) + Jmin->size[0] * Jmin->size[1] *
                Jmin->size[2] * ((int)b_tt - 1)) - 1] + (double)CompMat_data[i1
                + (c_n + 1) * i0] * angle2target->data[((int)comp_rng_r_data[i1]
                + angle2target->size[0] * ((int)comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          loop_ub = r9->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = r9->size[0];
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              Jmin->data[((((int)original_rng_r_data[i1] + Jmin->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + Jmin->size[0] * Jmin->size[1] *
                           ii) + Jmin->size[0] * Jmin->size[1] * Jmin->size[2] *
                          ((int)b_tt - 1)) - 1] = r9->data[i1 + r9->size[0] * i0];
            }
          }

          //  update optimal control
          mtmp = nextstate->data[ii].sidxs->data[cindx];
          i0 = CompMat->size[0] * CompMat->size[1];
          CompMat->size[0] = c_n + 1;
          CompMat->size[1] = n + 1;
          emxEnsureCapacity((emxArray__common *)CompMat, i0, (int)sizeof(double));
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = c_n + 1;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              CompMat->data[i1 + CompMat->size[0] * i0] = (double)
                !CompMat_data[i1 + (c_n + 1) * i0] * ccdp_ctrack->data[((((int)
                original_rng_r_data[i1] + ccdp_ctrack->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + ccdp_ctrack->size[0] *
                ccdp_ctrack->size[1] * ii) + ccdp_ctrack->size[0] *
                ccdp_ctrack->size[1] * ccdp_ctrack->size[2] * ((int)b_tt - 1)) -
                1] + (double)CompMat_data[i1 + (c_n + 1) * i0] * mtmp;
            }
          }

          loop_ub = CompMat->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = CompMat->size[0];
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              ccdp_ctrack->data[((((int)original_rng_r_data[i1] +
                                   ccdp_ctrack->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + ccdp_ctrack->size[0] *
                                  ccdp_ctrack->size[1] * ii) + ccdp_ctrack->
                                 size[0] * ccdp_ctrack->size[1] *
                                 ccdp_ctrack->size[2] * ((int)b_tt - 1)) - 1] =
                CompMat->data[i1 + CompMat->size[0] * i0];
            }
          }

          mtmp = nextstate->data[ii].sidxs->data[cindx + nextstate->data[ii].
            sidxs->size[0]];
          i0 = b_CompMat->size[0] * b_CompMat->size[1];
          b_CompMat->size[0] = c_n + 1;
          b_CompMat->size[1] = n + 1;
          emxEnsureCapacity((emxArray__common *)b_CompMat, i0, (int)sizeof
                            (double));
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = c_n + 1;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              b_CompMat->data[i1 + b_CompMat->size[0] * i0] = (double)
                !CompMat_data[i1 + (c_n + 1) * i0] * Optctrl_col->data[((((int)
                original_rng_r_data[i1] + Optctrl_col->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + Optctrl_col->size[0] *
                Optctrl_col->size[1] * ii) + Optctrl_col->size[0] *
                Optctrl_col->size[1] * Optctrl_col->size[2] * ((int)b_tt - 1)) -
                1] + (double)CompMat_data[i1 + (c_n + 1) * i0] * mtmp;
            }
          }

          loop_ub = b_CompMat->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = b_CompMat->size[0];
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              Optctrl_col->data[((((int)original_rng_r_data[i1] +
                                   Optctrl_col->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + Optctrl_col->size[0] *
                                  Optctrl_col->size[1] * ii) + Optctrl_col->
                                 size[0] * Optctrl_col->size[1] *
                                 Optctrl_col->size[2] * ((int)b_tt - 1)) - 1] =
                b_CompMat->data[i1 + b_CompMat->size[0] * i0];
            }
          }

          i0 = c_CompMat->size[0] * c_CompMat->size[1];
          c_CompMat->size[0] = c_n + 1;
          c_CompMat->size[1] = n + 1;
          emxEnsureCapacity((emxArray__common *)c_CompMat, i0, (int)sizeof
                            (double));
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = c_n + 1;
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              c_CompMat->data[i1 + c_CompMat->size[0] * i0] = (double)
                !CompMat_data[i1 + (c_n + 1) * i0] * Optctrl_dirs->data[((((int)
                original_rng_r_data[i1] + Optctrl_dirs->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + Optctrl_dirs->size[0] *
                Optctrl_dirs->size[1] * ii) + Optctrl_dirs->size[0] *
                Optctrl_dirs->size[1] * Optctrl_dirs->size[2] * ((int)b_tt - 1))
                - 1] + (double)CompMat_data[i1 + (c_n + 1) * i0] *
                mindiridx->data[((int)comp_rng_r_data[i1] + mindiridx->size[0] *
                                 ((int)comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          loop_ub = c_CompMat->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            b_loop_ub = c_CompMat->size[0];
            for (i1 = 0; i1 < b_loop_ub; i1++) {
              Optctrl_dirs->data[((((int)original_rng_r_data[i1] +
                                    Optctrl_dirs->size[0] * ((int)
                original_rng_c_data[i0] - 1)) + Optctrl_dirs->size[0] *
                                   Optctrl_dirs->size[1] * ii) +
                                  Optctrl_dirs->size[0] * Optctrl_dirs->size[1] *
                                  Optctrl_dirs->size[2] * ((int)b_tt - 1)) - 1] =
                c_CompMat->data[i1 + c_CompMat->size[0] * i0];
            }
          }
        }
      }

      // Jmin(tt).Jmin=Jmin(tt).Jmin + Lk;
      n = Jmin->size[0];
      iy = Jmin->size[1];
      br = Jmin->size[2];
      i0 = b_Jmin->size[0] * b_Jmin->size[1] * b_Jmin->size[2];
      b_Jmin->size[0] = n;
      b_Jmin->size[1] = iy;
      b_Jmin->size[2] = br;
      emxEnsureCapacity((emxArray__common *)b_Jmin, i0, (int)sizeof(double));
      for (i0 = 0; i0 < br; i0++) {
        for (i1 = 0; i1 < iy; i1++) {
          for (i2 = 0; i2 < n; i2++) {
            b_Jmin->data[(i2 + b_Jmin->size[0] * i1) + b_Jmin->size[0] *
              b_Jmin->size[1] * i0] = Jmin->data[((i2 + Jmin->size[0] * i1) +
              Jmin->size[0] * Jmin->size[1] * i0) + Jmin->size[0] * Jmin->size[1]
              * Jmin->size[2] * ((int)b_tt - 1)] + ccdp_cavoid->data[(i2 +
              ccdp_cavoid->size[0] * i1) + ccdp_cavoid->size[0] *
              ccdp_cavoid->size[1] * i0];
          }
        }
      }

      loop_ub = b_Jmin->size[2];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_loop_ub = b_Jmin->size[1];
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          b_n = b_Jmin->size[0];
          for (i2 = 0; i2 < b_n; i2++) {
            Jmin->data[((i2 + Jmin->size[0] * i1) + Jmin->size[0] * Jmin->size[1]
                        * i0) + Jmin->size[0] * Jmin->size[1] * Jmin->size[2] *
              ((int)b_tt - 1)] = b_Jmin->data[(i2 + b_Jmin->size[0] * i1) +
              b_Jmin->size[0] * b_Jmin->size[1] * i0];
          }
        }
      }
    }

    //  -- [ Find the optimal control ] -- %
    i0 = b_currs_idx->size[0] * b_currs_idx->size[1];
    b_currs_idx->size[0] = 3;
    b_currs_idx->size[1] = (int)(H + 1.0);
    emxEnsureCapacity((emxArray__common *)b_currs_idx, i0, (int)sizeof(double));
    loop_ub = 3 * (int)(H + 1.0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_currs_idx->data[i0] = 0.0;
    }

    b_pS[0] = pS[1] - ccdp->ys->data[0];
    b_pS[1] = pS[0] - ccdp->xs->data[0];
    for (i0 = 0; i0 < 2; i0++) {
      currs_idx[i0] = b_pS[i0] / ccdp->glen;
    }

    c_round(currs_idx);
    for (i0 = 0; i0 < 2; i0++) {
      b_currs_idx->data[i0] = currs_idx[i0] + 1.0;
    }

    b_currs_idx->data[2] = b_mod(rt_roundd_snf(pS[2] / 2.0 / 3.1415926535897931 *
      ndir), ndir) + 1.0;
    const_val = 0.0;

    //  number of violations of constraints
    i0 = optidx->size[0] * optidx->size[1];
    optidx->size[0] = 3;
    optidx->size[1] = (int)H;
    emxEnsureCapacity((emxArray__common *)optidx, i0, (int)sizeof(double));
    loop_ub = 3 * (int)H;
    for (i0 = 0; i0 < loop_ub; i0++) {
      optidx->data[i0] = 0.0;
    }

    for (tt = 0; tt < (int)H; tt++) {
      c_ccdp_ctrack[0] = ccdp_ctrack->data[((((int)b_currs_idx->data
        [b_currs_idx->size[0] * tt] + ccdp_ctrack->size[0] * ((int)
        b_currs_idx->data[1 + b_currs_idx->size[0] * tt] - 1)) +
        ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ((int)b_currs_idx->data[2
        + b_currs_idx->size[0] * tt] - 1)) + ccdp_ctrack->size[0] *
        ccdp_ctrack->size[1] * ccdp_ctrack->size[2] * tt) - 1];
      c_ccdp_ctrack[1] = Optctrl_col->data[((((int)b_currs_idx->data
        [b_currs_idx->size[0] * tt] + Optctrl_col->size[0] * ((int)
        b_currs_idx->data[1 + b_currs_idx->size[0] * tt] - 1)) +
        Optctrl_col->size[0] * Optctrl_col->size[1] * ((int)b_currs_idx->data[2
        + b_currs_idx->size[0] * tt] - 1)) + Optctrl_col->size[0] *
        Optctrl_col->size[1] * Optctrl_col->size[2] * tt) - 1];
      c_ccdp_ctrack[2] = Optctrl_dirs->data[((((int)b_currs_idx->
        data[b_currs_idx->size[0] * tt] + Optctrl_dirs->size[0] * ((int)
        b_currs_idx->data[1 + b_currs_idx->size[0] * tt] - 1)) +
        Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * ((int)b_currs_idx->data
        [2 + b_currs_idx->size[0] * tt] - 1)) + Optctrl_dirs->size[0] *
        Optctrl_dirs->size[1] * Optctrl_dirs->size[2] * tt) - 1];
      for (i0 = 0; i0 < 3; i0++) {
        optidx->data[i0 + optidx->size[0] * tt] = c_ccdp_ctrack[i0];
      }

      for (i0 = 0; i0 < 2; i0++) {
        currs_idx[i0] = b_currs_idx->data[i0 + b_currs_idx->size[0] * tt] +
          optidx->data[i0 + optidx->size[0] * tt];
      }

      for (i0 = 0; i0 < 2; i0++) {
        b_currs_idx->data[i0 + b_currs_idx->size[0] * ((int)((1.0 + (double)tt)
          + 1.0) - 1)] = currs_idx[i0];
      }

      b_currs_idx->data[2 + b_currs_idx->size[0] * ((int)((1.0 + (double)tt) +
        1.0) - 1)] = optidx->data[2 + optidx->size[0] * tt];
      const_val += ccdp_cconst->data[((((int)b_currs_idx->data[b_currs_idx->
        size[0] * ((int)((1.0 + (double)tt) + 1.0) - 1)] + ccdp_cconst->size[0] *
        ((int)b_currs_idx->data[1 + b_currs_idx->size[0] * ((int)((1.0 + (double)
        tt) + 1.0) - 1)] - 1)) + ccdp_cconst->size[0] * ccdp_cconst->size[1] *
        ((int)b_currs_idx->data[2 + b_currs_idx->size[0] * ((int)((1.0 + (double)
        tt) + 1.0) - 1)] - 1)) + ccdp_cconst->size[0] * ccdp_cconst->size[1] *
        ccdp_cconst->size[2] * ((int)((1.0 + (double)tt) + 1.0) - 1)) - 1];
    }

    i0 = predict_s->size[0] * predict_s->size[1];
    predict_s->size[0] = 3;
    predict_s->size[1] = (int)(H + 1.0);
    emxEnsureCapacity((emxArray__common *)predict_s, i0, (int)sizeof(double));
    loop_ub = 3 * (int)(H + 1.0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      predict_s->data[i0] = 0.0;
    }

    loop_ub = b_currs_idx->size[1] - 1;
    mtmp = ccdp->xs->data[0];
    b_loop_ub = b_currs_idx->size[1] - 1;
    i_ccdp = ccdp->ys->data[0];
    for (i0 = 0; i0 <= loop_ub; i0++) {
      predict_s->data[predict_s->size[0] * i0] = (b_currs_idx->data[1 +
        b_currs_idx->size[0] * i0] - 1.0) * ccdp->glen + mtmp;
    }

    for (i0 = 0; i0 <= b_loop_ub; i0++) {
      predict_s->data[1 + predict_s->size[0] * i0] = (b_currs_idx->
        data[b_currs_idx->size[0] * i0] - 1.0) * ccdp->glen + i_ccdp;
    }

    loop_ub = b_currs_idx->size[1] - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
      predict_s->data[2 + predict_s->size[0] * i0] = (b_currs_idx->data[2 +
        b_currs_idx->size[0] * i0] - 1.0) * 2.0 * 3.1415926535897931 / ndir;
    }

    //  though we doesn't consider constraints, the optimal solution
    //  satisfies constraints
    if ((const_val <= 0.0) && (ilagran == 1)) {
      // fprintf('feasible\n ');
      exitg1 = true;
    } else {
      if (ilagran == 1) {
        lag_feas = 0;
        lagcoeff = 1.0;
      }

      //  check feasibility
      if ((ilagran == 2) && (const_val > 0.0)) {
        b_fprintf();
        i0 = predict_s->size[0] * predict_s->size[1];
        predict_s->size[0] = 3;
        emxEnsureCapacity((emxArray__common *)predict_s, i0, (int)sizeof(double));
        loop_ub = predict_s->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          for (i1 = 0; i1 < 3; i1++) {
            predict_s->data[i1 + predict_s->size[0] * i0] = rtInf;
          }
        }

        exitg1 = true;
      } else {
        if (ilagran == 2) {
          lagcoeff = lagrng[1];
          lag_feas = 1;
        }

        guard1 = false;
        if (ilagran > 2) {
          if (const_val > 0.0) {
            //  violate constraints
            lagrng[0] = lagcoeff;
          } else {
            lagrng[1] = lagcoeff;
          }

          if (flag_converge == 1) {
            exitg1 = true;
          } else {
            if (lagrng[1] - lagrng[0] < 0.01) {
              lagcoeff = lagrng[1];
              flag_converge = 1;
            } else {
              lagcoeff = mean(lagrng);
            }

            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          ilagran++;
        }
      }
    }
  }

  emxFree_real_T(&c_CompMat);
  emxFree_real_T(&b_CompMat);
  emxFree_real_T(&CompMat);
  emxFree_real_T(&r9);
  emxFree_real_T(&d_nextstate);
  emxFree_real_T(&d_Jmin);
  emxFree_real_T(&c_nextstate);
  emxFree_real_T(&b_nextstate);
  emxFree_real_T(&c_Jmin);
  emxFree_real_T(&b_Jmin);
  emxFree_real_T(&b_Optctrl_dirs);
  emxFree_real_T(&b_mindiridx);
  emxFree_real_T(&c_lag_feas);
  emxFree_real_T(&c_lagcoeff);
  emxFree_real_T(&b_lag_feas);
  emxFree_real_T(&b_lagcoeff);
  emxFree_int32_T(&iindx);
  emxFree_real_T(&r8);
  emxFree_real_T(&r1);
  emxFree_real_T(&r0);
  emxFree_real_T(&optidx);
  emxFree_real_T(&b_currs_idx);
  emxFree_real_T(&mindiridx);
  emxFree_real_T(&Jmin);
  emxFree_real_T(&Optctrl_dirs);
  emxFree_real_T(&Optctrl_col);
  emxFree_real_T(&cvistmp);
  emxFree_real_T(&angle2target);
  emxFree_real_T(&ccdp_cconst);
  emxFree_real_T(&ccdp_cavoid);
  emxFree_real_T(&ccdp_cvis);
  emxFree_real_T(&ccdp_ctrack);

  // fprintf('the number of iterations: %d,  coeff: %.3e\n',ilagran,lagcoeff);
  //  wrong, initial state is not same as predict_s(:,1)
  for (i0 = 0; i0 < 3; i0++) {
    movement[i0] = predict_s->data[i0 + predict_s->size[0]] - pS[i0];
  }

  *uv_opt = norm(*(double (*)[2])&movement[0]) / T;
  *uw_opt = movement[2] / T;
}

//
// File trailer for fcn_track_ccdp_fast.cpp
//
// [EOF]
//
