/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fcn_track_ccdp_fast.c
 *
 * Code generation for function 'fcn_track_ccdp_fast'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "fcn_track_ccdp_fast_emxutil.h"
#include "abs.h"
#include "eml_error.h"
#include "sum.h"
#include "normcdf.h"
#include "bsxfun.h"
#include "conv2.h"
#include "round.h"
#include "atan2.h"
#include "power.h"
#include "eml_int_forloop_overflow_check.h"
#include "norm.h"
#include "fprintf.h"
#include "mean.h"
#include "mod.h"
#include "fcn_track_ccdp_fast_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 34, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo b_emlrtRSI = { 35, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo c_emlrtRSI = { 42, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo d_emlrtRSI = { 43, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo e_emlrtRSI = { 57, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo f_emlrtRSI = { 62, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo g_emlrtRSI = { 66, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo h_emlrtRSI = { 91, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo i_emlrtRSI = { 98, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo j_emlrtRSI = { 100, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo k_emlrtRSI = { 107, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo l_emlrtRSI = { 108, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo m_emlrtRSI = { 109, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo n_emlrtRSI = { 110, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo o_emlrtRSI = { 162, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRSInfo x_emlrtRSI = { 16, "min",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo y_emlrtRSI = { 18, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ab_emlrtRSI = { 96, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo bb_emlrtRSI = { 229, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo cb_emlrtRSI = { 202, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo db_emlrtRSI = { 68, "eml_mtimes_helper",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"
};

static emlrtRSInfo eb_emlrtRSI = { 54, "eml_xgemm",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\blas\\eml_xgemm.m"
};

static emlrtRSInfo fb_emlrtRSI = { 1, "xgemm",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\coder\\coder\\+coder\\+internal\\+blas\\xgemm.p"
};

static emlrtRSInfo ob_emlrtRSI = { 25, "reshape",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo pb_emlrtRSI = { 50, "reshape",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo qb_emlrtRSI = { 97, "reshape",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRSInfo ac_emlrtRSI = { 18, "min",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m"
};

static emlrtRSInfo bc_emlrtRSI = { 15, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo cc_emlrtRSI = { 105, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo dc_emlrtRSI = { 106, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo ec_emlrtRSI = { 108, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRSInfo fc_emlrtRSI = { 21, "colon",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo gc_emlrtRSI = { 79, "colon",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo hc_emlrtRSI = { 283, "colon",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRSInfo ic_emlrtRSI = { 291, "colon",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 42, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo b_emlrtRTEI = { 26, 1, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo c_emlrtRTEI = { 27, 1, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo d_emlrtRTEI = { 29, 1, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo e_emlrtRTEI = { 30, 1, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo f_emlrtRTEI = { 35, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo g_emlrtRTEI = { 39, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo h_emlrtRTEI = { 86, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo i_emlrtRTEI = { 87, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo j_emlrtRTEI = { 90, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo k_emlrtRTEI = { 100, 23, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo l_emlrtRTEI = { 134, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo m_emlrtRTEI = { 138, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtRTEInfo u_emlrtRTEI = { 23, 28, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo x_emlrtRTEI = { 81, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo y_emlrtRTEI = { 38, 19, "eml_min_or_max",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_min_or_max.m"
};

static emlrtRTEInfo ab_emlrtRTEI = { 60, 23, "reshape",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\elmat\\reshape.m"
};

static emlrtRTEInfo bb_emlrtRTEI = { 404, 15, "colon",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" };

static emlrtBCInfo emlrtBCI = { -1, -1, 192, 22, "predict_s",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo emlrtECI = { -1, 149, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo b_emlrtECI = { -1, 148, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo c_emlrtECI = { 2, 148, 24, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 148, 94, "ccdp.ys",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 148, 54, "ccdp.xs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 143, 23, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 143, 60, "optidx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 140, 18, "optidx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 143, 45, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtRTEInfo cb_emlrtRTEI = { 139, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 135, 53, "ccdp.xs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 135, 36, "ccdp.ys",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo d_emlrtECI = { -1, 129, 9, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 129, 20, "Jmin", "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo e_emlrtECI = { 3, 129, 24, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 129, 35, "Jmin", "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo f_emlrtECI = { -1, 121, 17, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 121, 63, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 121, 60, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo g_emlrtECI = { 2, 121, 70, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo h_emlrtECI = { 2, 121, 134, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 121, 128, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 121, 125, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo i_emlrtECI = { -1, 120, 17, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 120, 62, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 120, 59, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo j_emlrtECI = { 2, 120, 69, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 120, 141, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 120, 126, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 120, 123, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo k_emlrtECI = { -1, 119, 17, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 119, 62, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 119, 59, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo l_emlrtECI = { 2, 119, 69, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 119, 141, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 119, 126, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo y_emlrtBCI = { -1, -1, 119, 123, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo m_emlrtECI = { -1, 116, 18, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 116, 56, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 116, 53, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo n_emlrtECI = { 2, 116, 63, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo o_emlrtECI = { 2, 116, 120, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 116, 114, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo db_emlrtBCI = { -1, -1, 116, 111, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo p_emlrtECI = { 2, 113, 28, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo q_emlrtECI = { 2, 114, 23, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo r_emlrtECI = { 2, 114, 100, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 114, 150, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 114, 147, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 114, 61, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo hb_emlrtBCI = { -1, -1, 114, 58, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo s_emlrtECI = { 2, 113, 29, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo ib_emlrtBCI = { -1, -1, 113, 67, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo jb_emlrtBCI = { -1, -1, 113, 64, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo kb_emlrtBCI = { -1, -1, 110, 99, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo lb_emlrtBCI = { -1, -1, 110, 79, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo mb_emlrtBCI = { -1, -1, 110, 58, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo nb_emlrtBCI = { -1, -1, 110, 38, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ob_emlrtBCI = { -1, -1, 109, 99, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo pb_emlrtBCI = { -1, -1, 109, 79, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo qb_emlrtBCI = { -1, -1, 109, 58, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo rb_emlrtBCI = { -1, -1, 109, 38, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo sb_emlrtBCI = { -1, -1, 108, 103, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo tb_emlrtBCI = { -1, -1, 108, 83, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ub_emlrtBCI = { -1, -1, 108, 62, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo vb_emlrtBCI = { -1, -1, 108, 42, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo wb_emlrtBCI = { -1, -1, 107, 103, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo xb_emlrtBCI = { -1, -1, 107, 83, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo yb_emlrtBCI = { -1, -1, 107, 62, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ac_emlrtBCI = { -1, -1, 107, 42, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo bc_emlrtBCI = { -1, -1, 106, 28, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo t_emlrtECI = { -1, 101, 25, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo cc_emlrtBCI = { -1, -1, 101, 25, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo dc_emlrtBCI = { -1, -1, 100, 67, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo u_emlrtECI = { -1, 91, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo ec_emlrtBCI = { -1, -1, 91, 16, "Jmin", "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtRTEInfo db_emlrtRTEI = { 99, 9, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo fc_emlrtBCI = { -1, -1, 98, 83, "ccdp_cvis",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo gc_emlrtBCI = { -1, -1, 98, 55, "ccdp_cconst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtRTEInfo eb_emlrtRTEI = { 95, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo hc_emlrtBCI = { -1, -1, 91, 94, "ccdp_cvis",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo v_emlrtECI = { -1, 49, 9, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo ic_emlrtBCI = { -1, -1, 49, 23, "ccdp_cvis",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo jc_emlrtBCI = { -1, -1, 91, 65, "ccdp_cconst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo w_emlrtECI = { -1, 66, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo kc_emlrtBCI = { -1, -1, 66, 23, "ccdp_cconst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo lc_emlrtBCI = { -1, -1, 66, 81, "ccdp_cavoid",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo x_emlrtECI = { -1, 62, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo mc_emlrtBCI = { -1, -1, 62, 21, "ccdp_cavoid",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo nc_emlrtBCI = { -1, -1, 66, 59, "ccdp_ctrack",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo y_emlrtECI = { -1, 57, 9, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo oc_emlrtBCI = { -1, -1, 57, 28, "ccdp_ctrack",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo pc_emlrtBCI = { -1, -1, 57, 25, "ccdp_ctrack",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo qc_emlrtBCI = { -1, -1, 57, 165, "pEst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo ab_emlrtECI = { 1, 57, 92, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo rc_emlrtBCI = { -1, -1, 57, 132, "pEst(tt).mean",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo sc_emlrtBCI = { -1, -1, 57, 132, "pEst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo tc_emlrtBCI = { -1, -1, 57, 104, "pEst(tt).mean",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo uc_emlrtBCI = { -1, -1, 57, 104, "pEst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo vc_emlrtBCI = { -1, -1, 57, 88, "costparam.A",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtRTEInfo fb_emlrtRTEI = { 55, 5, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo bb_emlrtECI = { -1, 45, 21, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo cb_emlrtECI = { -1, 43, 33, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtECInfo db_emlrtECI = { -1, 41, 18, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo wc_emlrtBCI = { -1, -1, 35, 66, "pEst(tt).mean",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo xc_emlrtBCI = { -1, -1, 35, 66, "pEst", "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo yc_emlrtBCI = { -1, -1, 35, 41, "pEst(tt).mean",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ad_emlrtBCI = { -1, -1, 35, 41, "pEst", "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtECInfo eb_emlrtECI = { 2, 34, 19, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtBCInfo bd_emlrtBCI = { -1, -1, 34, 59, "pEst(tt).mean",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo cd_emlrtBCI = { -1, -1, 34, 59, "pEst", "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo dd_emlrtBCI = { -1, -1, 34, 28, "pEst(tt).mean",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ed_emlrtBCI = { -1, -1, 34, 28, "pEst", "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtRTEInfo gb_emlrtRTEI = { 31, 1, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m" };

static emlrtDCInfo emlrtDCI = { 85, 40, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtDCInfo b_emlrtDCI = { 85, 40, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 4 };

static emlrtDCInfo c_emlrtDCI = { 26, 31, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtDCInfo d_emlrtDCI = { 26, 31, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 4 };

static emlrtDCInfo e_emlrtDCI = { 26, 36, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtDCInfo f_emlrtDCI = { 26, 36, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 4 };

static emlrtDCInfo g_emlrtDCI = { 27, 29, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtDCInfo h_emlrtDCI = { 27, 29, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 4 };

static emlrtDCInfo i_emlrtDCI = { 29, 31, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtDCInfo j_emlrtDCI = { 29, 31, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 4 };

static emlrtDCInfo k_emlrtDCI = { 30, 35, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtDCInfo l_emlrtDCI = { 30, 35, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 4 };

static emlrtBCInfo fd_emlrtBCI = { -1, -1, 140, 37, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo m_emlrtDCI = { 140, 37, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo gd_emlrtBCI = { -1, -1, 140, 49, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo hd_emlrtBCI = { -1, -1, 140, 53, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo n_emlrtDCI = { 140, 53, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo id_emlrtBCI = { -1, -1, 140, 65, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo jd_emlrtBCI = { -1, -1, 140, 69, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo o_emlrtDCI = { 140, 69, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo kd_emlrtBCI = { -1, -1, 140, 81, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ld_emlrtBCI = { -1, -1, 140, 85, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo md_emlrtBCI = { -1, -1, 141, 25, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo p_emlrtDCI = { 141, 25, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo nd_emlrtBCI = { -1, -1, 141, 37, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo od_emlrtBCI = { -1, -1, 141, 41, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo q_emlrtDCI = { 141, 41, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo pd_emlrtBCI = { -1, -1, 141, 53, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo qd_emlrtBCI = { -1, -1, 141, 57, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo r_emlrtDCI = { 141, 57, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo rd_emlrtBCI = { -1, -1, 141, 69, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo sd_emlrtBCI = { -1, -1, 141, 73, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo td_emlrtBCI = { -1, -1, 142, 26, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo s_emlrtDCI = { 142, 26, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo ud_emlrtBCI = { -1, -1, 142, 38, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo vd_emlrtBCI = { -1, -1, 142, 42, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo t_emlrtDCI = { 142, 42, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo wd_emlrtBCI = { -1, -1, 142, 54, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo xd_emlrtBCI = { -1, -1, 142, 58, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo u_emlrtDCI = { 142, 58, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo yd_emlrtBCI = { -1, -1, 142, 70, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ae_emlrtBCI = { -1, -1, 142, 74, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo be_emlrtBCI = { -1, -1, 144, 21, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ce_emlrtBCI = { -1, -1, 144, 38, "optidx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo de_emlrtBCI = { -1, -1, 145, 45, "ccdp_cconst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo v_emlrtDCI = { 145, 45, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo ee_emlrtBCI = { -1, -1, 145, 57, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo fe_emlrtBCI = { -1, -1, 145, 63, "ccdp_cconst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo w_emlrtDCI = { 145, 63, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo ge_emlrtBCI = { -1, -1, 145, 75, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo he_emlrtBCI = { -1, -1, 145, 81, "ccdp_cconst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo x_emlrtDCI = { 145, 81, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo ie_emlrtBCI = { -1, -1, 145, 93, "currs_idx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo je_emlrtBCI = { -1, -1, 145, 99, "ccdp_cconst",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ke_emlrtBCI = { -1, -1, 100, 49, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo y_emlrtDCI = { 100, 49, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo le_emlrtBCI = { -1, -1, 101, 25, "nextstate(ii).dir",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo me_emlrtBCI = { -1, -1, 113, 34, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo ab_emlrtDCI = { 113, 34, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo ne_emlrtBCI = { -1, -1, 113, 49, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo bb_emlrtDCI = { 113, 49, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo oe_emlrtBCI = { -1, -1, 113, 84, "Jmin_dir",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo cb_emlrtDCI = { 113, 84, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo pe_emlrtBCI = { -1, -1, 113, 95, "Jmin_dir",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtDCInfo db_emlrtDCI = { 113, 95, "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 1 };

static emlrtBCInfo qe_emlrtBCI = { -1, -1, 114, 28, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo re_emlrtBCI = { -1, -1, 114, 43, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo se_emlrtBCI = { -1, -1, 114, 75, "Jmin_dir",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo te_emlrtBCI = { -1, -1, 114, 86, "Jmin_dir",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ue_emlrtBCI = { -1, -1, 114, 117, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ve_emlrtBCI = { -1, -1, 114, 132, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo we_emlrtBCI = { -1, -1, 114, 169, "mindiridx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo xe_emlrtBCI = { -1, -1, 114, 180, "mindiridx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ye_emlrtBCI = { -1, -1, 116, 81, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo af_emlrtBCI = { -1, -1, 116, 96, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo bf_emlrtBCI = { -1, -1, 116, 139, "Jmin_dir",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo cf_emlrtBCI = { -1, -1, 116, 150, "Jmin_dir",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo df_emlrtBCI = { -1, -1, 116, 23, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ef_emlrtBCI = { -1, -1, 116, 38, "Jmin",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo ff_emlrtBCI = { -1, -1, 119, 93, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo gf_emlrtBCI = { -1, -1, 119, 108, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo hf_emlrtBCI = { -1, -1, 119, 161, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo if_emlrtBCI = { -1, -1, 119, 29, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo jf_emlrtBCI = { -1, -1, 119, 44, "Optctrl_row",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo kf_emlrtBCI = { -1, -1, 120, 93, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo lf_emlrtBCI = { -1, -1, 120, 108, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo mf_emlrtBCI = { -1, -1, 120, 161, "nextstate(ii).sidxs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo nf_emlrtBCI = { -1, -1, 120, 29, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo of_emlrtBCI = { -1, -1, 120, 44, "Optctrl_col",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo pf_emlrtBCI = { -1, -1, 121, 95, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo qf_emlrtBCI = { -1, -1, 121, 110, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo rf_emlrtBCI = { -1, -1, 121, 153, "mindiridx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo sf_emlrtBCI = { -1, -1, 121, 164, "mindiridx",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo tf_emlrtBCI = { -1, -1, 121, 30, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo uf_emlrtBCI = { -1, -1, 121, 45, "Optctrl_dirs",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo vf_emlrtBCI = { -1, -1, 36, 5, "angle2target",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo wf_emlrtBCI = { -1, -1, 43, 33, "dist2target",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo xf_emlrtBCI = { -1, -1, 45, 13, "cvistmp",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtBCInfo yf_emlrtBCI = { -1, -1, 100, 49, "nextstate",
  "fcn_track_ccdp_fast",
  "E:\\Research\\CCMH_extended.ver2\\fcn_track_ccdp_fast.m", 0 };

static emlrtRTEInfo mb_emlrtRTEI = { 41, 19, "eml_assert_valid_size_arg",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_assert_valid_size_arg.m"
};

static emlrtRTEInfo nb_emlrtRTEI = { 56, 15, "eml_assert_valid_size_arg",
  "C:\\Program Files\\MATLAB\\R2015a\\toolbox\\eml\\lib\\matlab\\eml\\eml_assert_valid_size_arg.m"
};

/* Function Declarations */
static void eml_assert_valid_size_arg(const emlrtStack *sp, const real_T
  varargin_1[2]);
static void eml_extremum(const emlrtStack *sp, const emxArray_real_T *x,
  emxArray_real_T *extremum, emxArray_int32_T *indx);

/* Function Definitions */
static void eml_assert_valid_size_arg(const emlrtStack *sp, const real_T
  varargin_1[2])
{
  int32_T k;
  int32_T exitg2;
  boolean_T p;
  boolean_T guard1 = false;
  int32_T exitg1;
  real_T n;
  k = 0;
  do {
    exitg2 = 0;
    if (k < 2) {
      if ((varargin_1[k] != varargin_1[k]) || muDoubleScalarIsInf(varargin_1[k]))
      {
        p = false;
        exitg2 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg2 = 1;
    }
  } while (exitg2 == 0);

  guard1 = false;
  if (p) {
    k = 0;
    do {
      exitg1 = 0;
      if (k < 2) {
        if (2.147483647E+9 < varargin_1[k]) {
          p = false;
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        p = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    if (p) {
      p = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = false;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &mb_emlrtRTEI,
      "Coder:toolbox:eml_assert_valid_size_arg_invalidSizeVector", 4, 12,
      MIN_int32_T, 12, MAX_int32_T);
  }

  n = 1.0;
  for (k = 0; k < 2; k++) {
    if (varargin_1[k] <= 0.0) {
      n = 0.0;
    } else {
      n *= varargin_1[k];
    }
  }

  if (2.147483647E+9 >= n) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &nb_emlrtRTEI, "Coder:MATLAB:pmaxsize", 0);
  }
}

static void eml_extremum(const emlrtStack *sp, const emxArray_real_T *x,
  emxArray_real_T *extremum, emxArray_int32_T *indx)
{
  uint32_T outsz[3];
  int32_T k;
  int32_T ix;
  int32_T n;
  int32_T vstride;
  boolean_T b4;
  int32_T j;
  int32_T ixstart;
  int32_T ixstop;
  real_T mtmp;
  int32_T itmp;
  int32_T cindx;
  int32_T b_ix;
  boolean_T overflow;
  boolean_T exitg1;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (x->size[2] > 0) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &x_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  for (k = 0; k < 3; k++) {
    outsz[k] = (uint32_T)x->size[k];
  }

  k = extremum->size[0] * extremum->size[1];
  extremum->size[0] = (int32_T)outsz[0];
  extremum->size[1] = (int32_T)outsz[1];
  emxEnsureCapacity(sp, (emxArray__common *)extremum, k, (int32_T)sizeof(real_T),
                    &u_emlrtRTEI);
  k = indx->size[0] * indx->size[1];
  indx->size[0] = (uint8_T)outsz[0];
  emxEnsureCapacity(sp, (emxArray__common *)indx, k, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  k = indx->size[0] * indx->size[1];
  indx->size[1] = (uint8_T)outsz[1];
  emxEnsureCapacity(sp, (emxArray__common *)indx, k, (int32_T)sizeof(int32_T),
                    &u_emlrtRTEI);
  ix = (uint8_T)outsz[0] * (uint8_T)outsz[1];
  for (k = 0; k < ix; k++) {
    indx->data[k] = 1;
  }

  n = x->size[2];
  k = 3;
  while ((k > 2) && (x->size[2] == 1)) {
    k = 2;
  }

  if (3 > k) {
    vstride = x->size[0] * x->size[1] * x->size[2];
  } else {
    vstride = 1;
    for (k = 0; k < 2; k++) {
      vstride *= x->size[k];
    }
  }

  ix = 0;
  k = -1;
  st.site = &cc_emlrtRSI;
  st.site = &dc_emlrtRSI;
  if (1 > vstride) {
    b4 = false;
  } else {
    b4 = (vstride > 2147483646);
  }

  if (b4) {
    b_st.site = &w_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (j = 1; j <= vstride; j++) {
    ix++;
    st.site = &ec_emlrtRSI;
    ixstart = ix;
    ixstop = ix + (n - 1) * vstride;
    mtmp = x->data[ix - 1];
    itmp = 1;
    if (n > 1) {
      cindx = 1;
      if (muDoubleScalarIsNaN(x->data[ix - 1])) {
        b_ix = ix + vstride;
        b_st.site = &cb_emlrtRSI;
        if ((vstride == 0) || ((vstride > 0) && (b_ix > ixstop)) || ((vstride <
              0) && (b_ix < ixstop))) {
          overflow = false;
        } else if (vstride > 0) {
          overflow = (ixstop > MAX_int32_T - vstride);
        } else {
          overflow = (ixstop < MIN_int32_T - vstride);
        }

        if (overflow) {
          c_st.site = &w_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        exitg1 = false;
        while ((!exitg1) && (((vstride > 0) && (b_ix <= ixstop)) || ((vstride <
                  0) && (b_ix >= ixstop)))) {
          cindx++;
          ixstart = b_ix;
          if (!muDoubleScalarIsNaN(x->data[b_ix - 1])) {
            mtmp = x->data[b_ix - 1];
            itmp = cindx;
            exitg1 = true;
          } else {
            b_ix += vstride;
          }
        }
      }

      if (ixstart < ixstop) {
        b_ix = ixstart + vstride;
        b_st.site = &bb_emlrtRSI;
        if ((vstride == 0) || ((vstride > 0) && (b_ix > ixstop)) || ((vstride <
              0) && (b_ix < ixstop))) {
          overflow = false;
        } else if (vstride > 0) {
          overflow = (ixstop > MAX_int32_T - vstride);
        } else {
          overflow = (ixstop < MIN_int32_T - vstride);
        }

        if (overflow) {
          c_st.site = &w_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        while (((vstride > 0) && (b_ix <= ixstop)) || ((vstride < 0) && (b_ix >=
                 ixstop))) {
          cindx++;
          if (x->data[b_ix - 1] < mtmp) {
            mtmp = x->data[b_ix - 1];
            itmp = cindx;
          }

          b_ix += vstride;
        }
      }
    }

    k++;
    extremum->data[k] = mtmp;
    indx->data[k] = itmp;
  }
}

void fcn_track_ccdp_fast(fcn_track_ccdp_fastStackData *SD, const emlrtStack *sp,
  const real_T pS[3], const emxArray_struct0_T *pEst, real_T H, real_T T, const
  struct1_T *ccdp, real_T threshold_track, const struct3_T *costparam, const
  emxArray_struct4_T *nextstate, real_T *uv_opt, real_T *uw_opt, emxArray_real_T
  *predict_s)
{
  emxArray_real_T *ccdp_ctrack;
  int32_T clen;
  int32_T rlen;
  real_T ndir;
  int32_T ixstart;
  real_T b_ccdp;
  int32_T i0;
  real_T mtmp;
  real_T c_ccdp;
  real_T b_mtmp;
  int32_T loop_ub;
  emxArray_real_T *ccdp_cvis;
  real_T d_ccdp;
  emxArray_real_T *ccdp_cavoid;
  real_T e_ccdp;
  emxArray_real_T *ccdp_cconst;
  real_T f_ccdp;
  int32_T tt;
  emxArray_real_T *angle2target;
  emxArray_real_T *cvistmp;
  emxArray_real_T *mindiridx;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  emxArray_int32_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *r4;
  emxArray_int32_T *r5;
  emxArray_real_T *C;
  emxArray_real_T *A;
  emxArray_real_T *a;
  emxArray_real_T *b;
  emxArray_real_T *r6;
  emxArray_boolean_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *b_ccdp_ctrack;
  emxArray_real_T *b_ccdp_cavoid;
  emxArray_real_T *g_ccdp;
  emxArray_real_T *h_ccdp;
  emxArray_real_T *i_ccdp;
  emxArray_real_T *j_ccdp;
  emxArray_real_T *k_ccdp;
  emxArray_real_T *r9;
  emxArray_real_T *b_A;
  int32_T i1;
  int32_T b_angle2target[2];
  int32_T iv0[2];
  int32_T nm1d2;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i2;
  int32_T i3;
  real_T minradius[20];
  int32_T ii;
  boolean_T tmp_data[10000];
  boolean_T b_tmp_data[10000];
  int32_T tmp_size[1];
  int32_T trueCount[1];
  boolean_T n_too_large;
  boolean_T exitg2;
  int32_T i4;
  int32_T c_tmp_data[200];
  int32_T d_loop_ub;
  int32_T d_tmp_data[200];
  int32_T iv1[2];
  real_T currs_idx[2];
  char_T TRANSB;
  char_T TRANSA;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  int32_T CompMat[2];
  real_T lagrng[2];
  uint8_T sz[2];
  boolean_T y_data[40000];
  int32_T iv2[2];
  int32_T Jmin[2];
  int32_T i5;
  int32_T b_Jmin[3];
  real_T lagcoeff;
  int32_T lag_feas;
  int32_T flag_converge;
  int32_T ilagran;
  emxArray_real_T *Optctrl_col;
  emxArray_real_T *Optctrl_dirs;
  emxArray_real_T *c_Jmin;
  emxArray_real_T *b_currs_idx;
  emxArray_real_T *optidx;
  emxArray_real_T *r10;
  emxArray_real_T *r11;
  emxArray_real_T *r12;
  emxArray_real_T *r13;
  emxArray_int32_T *iindx;
  emxArray_real_T *b_lagcoeff;
  emxArray_real_T *b_lag_feas;
  emxArray_real_T *c_lagcoeff;
  emxArray_real_T *c_lag_feas;
  emxArray_real_T *d_Jmin;
  emxArray_real_T *b_mindiridx;
  emxArray_real_T *b_Optctrl_dirs;
  emxArray_real_T *e_Jmin;
  emxArray_real_T *f_Jmin;
  emxArray_real_T *g_Jmin;
  emxArray_real_T *h_Jmin;
  emxArray_real_T *c_angle2target;
  emxArray_real_T *i_Jmin;
  emxArray_real_T *d_angle2target;
  emxArray_real_T *j_Jmin;
  emxArray_real_T *e_angle2target;
  emxArray_real_T *c_ccdp_ctrack;
  emxArray_real_T *b_Optctrl_col;
  emxArray_real_T *c_Optctrl_dirs;
  emxArray_int32_T *b_cvistmp;
  boolean_T exitg1;
  real_T l_ccdp;
  int32_T iv3[3];
  real_T b_tt;
  int32_T b_ii;
  int32_T c_ii;
  int32_T d_ii;
  int32_T i6;
  int32_T jj;
  int32_T n;
  real_T anew;
  real_T apnd;
  real_T ndbl;
  real_T cdiff;
  real_T absb;
  real_T original_rng_r_data[200];
  int32_T b_n;
  real_T original_rng_c_data[200];
  int32_T c_n;
  real_T comp_rng_r_data[200];
  int32_T d_n;
  real_T comp_rng_c_data[200];
  int32_T i7;
  int32_T e_loop_ub;
  int32_T i8;
  int32_T f_loop_ub;
  int32_T y_size[2];
  int32_T b_tmp_size[2];
  boolean_T e_tmp_data[40000];
  int32_T CompMat_size[2];
  boolean_T CompMat_data[40000];
  int32_T i9;
  int32_T i10;
  int32_T iv4[2];
  int32_T i11;
  int32_T i12;
  int32_T i13;
  int32_T iv5[2];
  int32_T i14;
  int32_T i15;
  int32_T i16;
  int32_T iv6[2];
  int32_T i17;
  int32_T i18;
  int32_T iv7[2];
  int32_T c_ccdp_cavoid[3];
  int32_T iv8[3];
  real_T b_pS[2];
  real_T const_val;
  int32_T c_tt;
  int32_T d_tt;
  int32_T e_tt;
  int32_T i19;
  int32_T i20;
  int32_T g_loop_ub;
  int32_T f_tt;
  real_T d_ccdp_ctrack[3];
  int32_T g_tt;
  int32_T h_tt;
  int32_T i_tt;
  int32_T i21;
  int32_T i22;
  int32_T h_loop_ub;
  int32_T j_tt;
  int32_T k_tt;
  int32_T l_tt;
  int32_T m_tt;
  int32_T i23;
  int32_T i24;
  int32_T i_loop_ub;
  int32_T n_tt;
  int32_T i25;
  int32_T o_tt;
  int32_T i26;
  int32_T j_loop_ub;
  int32_T b_nm1d2;
  int32_T i27;
  int32_T i28;
  int32_T k_loop_ub;
  int32_T b_ixstart;
  int32_T iv9[2];
  int32_T iv10[2];
  boolean_T guard1 = false;
  real_T movement[3];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &ccdp_ctrack, 4, &b_emlrtRTEI, true);

  /*  ---------------------------------------------------------------% */
  /*  Find the optimal control which follows the target  */
  /*  without collision and occlusion */
  /*  -- Input -- % */
  /*  current position */
  /*  pEst: estimated position of the target */
  /*  -- Output -- % */
  /*  ----------------------------------------------------------------% */
  /*  -- [ settings for visibility cost ] -- % */
  /*  the number of angles to compute visibility cost */
  clen = ccdp->xs->size[1];
  rlen = ccdp->xs->size[0];

  /* ccdp.cvis = zeros([rlen,clen,H]); % initialize the visibility cost */
  /*  -- [ settings for tracking cost ] -- % */
  ndir = costparam->ndir;

  /* s_dirs = costparam.s_dirs; */
  /*  -- [ Compute one-step cost ] -- % */
  ixstart = ccdp->xs->size[0];
  b_ccdp = costparam->ndir;
  if (b_ccdp >= 0.0) {
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(b_ccdp, &d_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &c_emlrtDCI, sp);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &f_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &e_emlrtDCI, sp);
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_ctrack, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstart = ccdp->xs->size[1];
  b_ccdp = costparam->ndir;
  if (b_ccdp >= 0.0) {
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(b_ccdp, &d_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &c_emlrtDCI, sp);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &f_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &e_emlrtDCI, sp);
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_ctrack, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  b_ccdp = costparam->ndir;
  if (b_ccdp >= 0.0) {
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(b_ccdp, &d_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &c_emlrtDCI, sp);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &f_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &e_emlrtDCI, sp);
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[2] = (int32_T)costparam->ndir;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_ctrack, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  b_ccdp = costparam->ndir;
  if (b_ccdp >= 0.0) {
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(b_ccdp, &d_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &c_emlrtDCI, sp);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &f_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &e_emlrtDCI, sp);
  i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
    ccdp_ctrack->size[3];
  ccdp_ctrack->size[3] = (int32_T)(H + 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_ctrack, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  b_ccdp = costparam->ndir;
  if (b_ccdp >= 0.0) {
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(b_ccdp, &d_emlrtDCI, sp);
  }

  if (H + 1.0 >= 0.0) {
    mtmp = H + 1.0;
  } else {
    mtmp = emlrtNonNegativeCheckR2012b(H + 1.0, &f_emlrtDCI, sp);
  }

  if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
    c_ccdp = b_ccdp;
  } else {
    c_ccdp = emlrtIntegerCheckR2012b(b_ccdp, &c_emlrtDCI, sp);
  }

  if (mtmp == (int32_T)muDoubleScalarFloor(mtmp)) {
    b_mtmp = mtmp;
  } else {
    b_mtmp = emlrtIntegerCheckR2012b(mtmp, &e_emlrtDCI, sp);
  }

  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int32_T)c_ccdp * (int32_T)
    b_mtmp;
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_ctrack->data[i0] = 0.0;
  }

  b_emxInit_real_T(sp, &ccdp_cvis, 3, &c_emlrtRTEI, true);
  ixstart = ccdp->xs->size[0];
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &h_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &g_emlrtDCI, sp);
  i0 = ccdp_cvis->size[0] * ccdp_cvis->size[1] * ccdp_cvis->size[2];
  ccdp_cvis->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cvis, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstart = ccdp->xs->size[1];
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &h_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &g_emlrtDCI, sp);
  i0 = ccdp_cvis->size[0] * ccdp_cvis->size[1] * ccdp_cvis->size[2];
  ccdp_cvis->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cvis, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &h_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &g_emlrtDCI, sp);
  i0 = ccdp_cvis->size[0] * ccdp_cvis->size[1] * ccdp_cvis->size[2];
  ccdp_cvis->size[2] = (int32_T)(H + 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cvis, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &h_emlrtDCI, sp);
  }

  if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
    d_ccdp = b_ccdp;
  } else {
    d_ccdp = emlrtIntegerCheckR2012b(b_ccdp, &g_emlrtDCI, sp);
  }

  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int32_T)d_ccdp;
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_cvis->data[i0] = 0.0;
  }

  b_emxInit_real_T(sp, &ccdp_cavoid, 3, &d_emlrtRTEI, true);

  /* ccdp.ctrack(1).val = zeros(rlen,clen,ndir); */
  ixstart = ccdp->xs->size[0];
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &j_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &i_emlrtDCI, sp);
  i0 = ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * ccdp_cavoid->size[2];
  ccdp_cavoid->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cavoid, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstart = ccdp->xs->size[1];
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &j_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &i_emlrtDCI, sp);
  i0 = ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * ccdp_cavoid->size[2];
  ccdp_cavoid->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cavoid, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &j_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &i_emlrtDCI, sp);
  i0 = ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * ccdp_cavoid->size[2];
  ccdp_cavoid->size[2] = (int32_T)(H + 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cavoid, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &j_emlrtDCI, sp);
  }

  if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
    e_ccdp = b_ccdp;
  } else {
    e_ccdp = emlrtIntegerCheckR2012b(b_ccdp, &i_emlrtDCI, sp);
  }

  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int32_T)e_ccdp;
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_cavoid->data[i0] = 0.0;
  }

  emxInit_real_T(sp, &ccdp_cconst, 4, &e_emlrtRTEI, true);
  ixstart = ccdp->xs->size[0];
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &l_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &k_emlrtDCI, sp);
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[0] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cconst, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  ixstart = ccdp->xs->size[1];
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &l_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &k_emlrtDCI, sp);
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[1] = ixstart;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cconst, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &l_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &k_emlrtDCI, sp);
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[2] = (int32_T)costparam->ndir;
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cconst, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &l_emlrtDCI, sp);
  }

  emlrtIntegerCheckR2012b(b_ccdp, &k_emlrtDCI, sp);
  i0 = ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
    ccdp_cconst->size[3];
  ccdp_cconst->size[3] = (int32_T)(H + 1.0);
  emxEnsureCapacity(sp, (emxArray__common *)ccdp_cconst, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  if (H + 1.0 >= 0.0) {
    b_ccdp = H + 1.0;
  } else {
    b_ccdp = emlrtNonNegativeCheckR2012b(H + 1.0, &l_emlrtDCI, sp);
  }

  if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
    f_ccdp = b_ccdp;
  } else {
    f_ccdp = emlrtIntegerCheckR2012b(b_ccdp, &k_emlrtDCI, sp);
  }

  loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1] * (int32_T)costparam->ndir *
    (int32_T)f_ccdp;
  for (i0 = 0; i0 < loop_ub; i0++) {
    ccdp_cconst->data[i0] = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, H, mxDOUBLE_CLASS, (int32_T)H,
    &gb_emlrtRTEI, sp);
  tt = 0;
  c_emxInit_real_T(sp, &angle2target, 2, &f_emlrtRTEI, true);
  c_emxInit_real_T(sp, &cvistmp, 2, &g_emlrtRTEI, true);
  c_emxInit_real_T(sp, &mindiridx, 2, &k_emlrtRTEI, true);
  c_emxInit_real_T(sp, &r0, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r1, 2, &emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 1, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &r3, 3, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r4, 2, &emlrtRTEI, true);
  emxInit_int32_T(sp, &r5, 1, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &C, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &A, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &a, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &b, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r6, 2, &emlrtRTEI, true);
  emxInit_boolean_T(sp, &r7, 3, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r8, 2, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_ccdp_ctrack, 3, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_ccdp_cavoid, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &g_ccdp, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &h_ccdp, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &i_ccdp, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &j_ccdp, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &k_ccdp, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r9, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_A, 2, &emlrtRTEI, true);
  while (tt <= (int32_T)H - 1) {
    /*  --- [ Cost: Cvis ]  --- % */
    /*  distance and angle from the target's prediction to grids */
    i0 = pEst->size[1];
    i1 = tt + 1;
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ed_emlrtBCI, sp);
    i0 = pEst->size[1];
    i1 = tt + 1;
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &cd_emlrtBCI, sp);
    i0 = pEst->data[tt].mean->size[1] << 1;
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &dd_emlrtBCI, sp);
    i0 = k_ccdp->size[0] * k_ccdp->size[1];
    k_ccdp->size[0] = ccdp->xs->size[0];
    k_ccdp->size[1] = ccdp->xs->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)k_ccdp, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    mtmp = pEst->data[tt].mean->data[0];
    loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      k_ccdp->data[i0] = ccdp->xs->data[i0] - mtmp;
    }

    st.site = &emlrtRSI;
    power(&st, k_ccdp, mindiridx);
    i0 = pEst->data[tt].mean->size[1] << 1;
    emlrtDynamicBoundsCheckR2012b(2, 1, i0, &bd_emlrtBCI, sp);
    i0 = j_ccdp->size[0] * j_ccdp->size[1];
    j_ccdp->size[0] = ccdp->ys->size[0];
    j_ccdp->size[1] = ccdp->ys->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)j_ccdp, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    mtmp = pEst->data[tt].mean->data[1];
    loop_ub = ccdp->ys->size[0] * ccdp->ys->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      j_ccdp->data[i0] = ccdp->ys->data[i0] - mtmp;
    }

    st.site = &emlrtRSI;
    power(&st, j_ccdp, r4);
    for (i0 = 0; i0 < 2; i0++) {
      b_angle2target[i0] = mindiridx->size[i0];
    }

    for (i0 = 0; i0 < 2; i0++) {
      iv0[i0] = r4->size[i0];
    }

    if ((b_angle2target[0] != iv0[0]) || (b_angle2target[1] != iv0[1])) {
      emlrtSizeEqCheckNDR2012b(b_angle2target, iv0, &eb_emlrtECI, sp);
    }

    i0 = mindiridx->size[0] * mindiridx->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)mindiridx, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    ixstart = mindiridx->size[0];
    nm1d2 = mindiridx->size[1];
    loop_ub = ixstart * nm1d2;
    for (i0 = 0; i0 < loop_ub; i0++) {
      mindiridx->data[i0] += r4->data[i0];
    }

    i0 = pEst->size[1];
    i1 = tt + 1;
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ad_emlrtBCI, sp);
    i0 = pEst->size[1];
    i1 = tt + 1;
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &xc_emlrtBCI, sp);
    i0 = pEst->data[tt].mean->size[1] << 1;
    emlrtDynamicBoundsCheckR2012b(2, 1, i0, &yc_emlrtBCI, sp);
    i0 = pEst->data[tt].mean->size[1] << 1;
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &wc_emlrtBCI, sp);
    i0 = h_ccdp->size[0] * h_ccdp->size[1];
    h_ccdp->size[0] = ccdp->ys->size[0];
    h_ccdp->size[1] = ccdp->ys->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)h_ccdp, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    mtmp = pEst->data[tt].mean->data[1];
    loop_ub = ccdp->ys->size[0] * ccdp->ys->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      h_ccdp->data[i0] = ccdp->ys->data[i0] - mtmp;
    }

    i0 = i_ccdp->size[0] * i_ccdp->size[1];
    i_ccdp->size[0] = ccdp->xs->size[0];
    i_ccdp->size[1] = ccdp->xs->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)i_ccdp, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    mtmp = pEst->data[tt].mean->data[0];
    loop_ub = ccdp->xs->size[0] * ccdp->xs->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i_ccdp->data[i0] = ccdp->xs->data[i0] - mtmp;
    }

    st.site = &b_emlrtRSI;
    b_atan2(&st, h_ccdp, i_ccdp, r4);
    i0 = A->size[0] * A->size[1];
    A->size[0] = r4->size[0];
    A->size[1] = r4->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)A, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = r4->size[0] * r4->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      A->data[i0] = r4->data[i0] + 3.1415926535897931;
    }

    i0 = angle2target->size[0] * angle2target->size[1];
    angle2target->size[0] = A->size[0];
    angle2target->size[1] = A->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)angle2target, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = A->size[0] * A->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      angle2target->data[i0] = A->data[i0] / 2.0 / 3.1415926535897931 * 20.0;
    }

    b_round(angle2target);
    i0 = angle2target->size[0] * angle2target->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)angle2target, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    nm1d2 = angle2target->size[0];
    ixstart = angle2target->size[1];
    loop_ub = nm1d2 * ixstart;
    for (i0 = 0; i0 < loop_ub; i0++) {
      angle2target->data[i0]++;
    }

    ixstart = angle2target->size[0] * angle2target->size[1] - 1;
    b_loop_ub = 0;
    for (c_loop_ub = 0; c_loop_ub <= ixstart; c_loop_ub++) {
      if (angle2target->data[c_loop_ub] == 9.0) {
        b_loop_ub++;
      }
    }

    i0 = r5->size[0];
    r5->size[0] = b_loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r5, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    nm1d2 = 0;
    for (c_loop_ub = 0; c_loop_ub <= ixstart; c_loop_ub++) {
      if (angle2target->data[c_loop_ub] == 9.0) {
        r5->data[nm1d2] = c_loop_ub + 1;
        nm1d2++;
      }
    }

    nm1d2 = angle2target->size[0];
    ixstart = angle2target->size[1];
    loop_ub = r5->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i1 = nm1d2 * ixstart;
      i2 = r5->data[i0];
      if ((i2 >= 1) && (i2 < i1)) {
        i3 = i2;
      } else {
        i3 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &vf_emlrtBCI, sp);
      }

      angle2target->data[i3 - 1] = 1.0;
    }

    memset(&minradius[0], 0, 20U * sizeof(real_T));

    /*  distance between the target and an obstacle in nvis directions */
    i0 = cvistmp->size[0] * cvistmp->size[1];
    cvistmp->size[0] = (uint8_T)rlen;
    emxEnsureCapacity(sp, (emxArray__common *)cvistmp, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    i0 = cvistmp->size[0] * cvistmp->size[1];
    cvistmp->size[1] = (uint8_T)clen;
    emxEnsureCapacity(sp, (emxArray__common *)cvistmp, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = (uint8_T)rlen * (uint8_T)clen;
    for (i0 = 0; i0 < loop_ub; i0++) {
      cvistmp->data[i0] = 0.0;
    }

    ii = 0;
    while (ii < 20) {
      ixstart = ccdp->gmap.size[0] * ccdp->gmap.size[1];
      loop_ub = ccdp->gmap.size[0] * ccdp->gmap.size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        tmp_data[i0] = ccdp->gmap.data[i0];
      }

      nm1d2 = angle2target->size[0] * angle2target->size[1];
      loop_ub = angle2target->size[0] * angle2target->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        SD->f0.tmp_data[i0] = (angle2target->data[i0] == 1.0 + (real_T)ii);
      }

      if (ixstart != nm1d2) {
        emlrtSizeEqCheck1DR2012b(ixstart, nm1d2, &db_emlrtECI, sp);
      }

      tmp_size[0] = ixstart;
      for (i0 = 0; i0 < ixstart; i0++) {
        b_tmp_data[i0] = (tmp_data[i0] && SD->f0.tmp_data[i0]);
      }

      st.site = &c_emlrtRSI;
      if (sum(&st, b_tmp_data, tmp_size) >= 1.0) {
        b_loop_ub = 0;
        for (c_loop_ub = 0; c_loop_ub < ixstart; c_loop_ub++) {
          if (tmp_data[c_loop_ub] && SD->f0.tmp_data[c_loop_ub]) {
            b_loop_ub++;
          }
        }

        trueCount[0] = b_loop_ub;
        emlrtMatrixMatrixIndexCheckR2012b(*(int32_T (*)[2])mindiridx->size, 2,
          trueCount, 1, &cb_emlrtECI, sp);
        ixstart--;
        b_loop_ub = 0;
        for (c_loop_ub = 0; c_loop_ub <= ixstart; c_loop_ub++) {
          if (tmp_data[c_loop_ub] && SD->f0.tmp_data[c_loop_ub]) {
            b_loop_ub++;
          }
        }

        nm1d2 = 0;
        for (c_loop_ub = 0; c_loop_ub <= ixstart; c_loop_ub++) {
          if (tmp_data[c_loop_ub] && SD->f0.tmp_data[c_loop_ub]) {
            SD->f0.b_tmp_data[nm1d2] = c_loop_ub + 1;
            nm1d2++;
          }
        }

        st.site = &d_emlrtRSI;
        for (i0 = 0; i0 < b_loop_ub; i0++) {
          i1 = mindiridx->size[0] * mindiridx->size[1];
          emlrtDynamicBoundsCheckR2012b(SD->f0.b_tmp_data[i0], 1, i1,
            &wf_emlrtBCI, &st);
        }

        b_st.site = &x_emlrtRSI;
        c_st.site = &y_emlrtRSI;
        if ((b_loop_ub == 1) || (b_loop_ub != 1)) {
          n_too_large = true;
        } else {
          n_too_large = false;
        }

        if (n_too_large) {
        } else {
          emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
            "Coder:toolbox:autoDimIncompatibility", 0);
        }

        if (b_loop_ub > 0) {
        } else {
          emlrtErrorWithMessageIdR2012b(&c_st, &x_emlrtRTEI,
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }

        d_st.site = &ab_emlrtRSI;
        ixstart = 1;
        mtmp = mindiridx->data[SD->f0.b_tmp_data[0] - 1];
        if (b_loop_ub > 1) {
          if (muDoubleScalarIsNaN(mtmp)) {
            nm1d2 = 2;
            exitg2 = false;
            while ((!exitg2) && (nm1d2 <= b_loop_ub)) {
              ixstart = nm1d2;
              if (!muDoubleScalarIsNaN(mindiridx->data[SD->f0.b_tmp_data[nm1d2 -
                   1] - 1])) {
                mtmp = mindiridx->data[SD->f0.b_tmp_data[nm1d2 - 1] - 1];
                exitg2 = true;
              } else {
                nm1d2++;
              }
            }
          }

          if (ixstart < b_loop_ub) {
            while (ixstart + 1 <= b_loop_ub) {
              if (mindiridx->data[SD->f0.b_tmp_data[ixstart] - 1] < mtmp) {
                mtmp = mindiridx->data[SD->f0.b_tmp_data[ixstart] - 1];
              }

              ixstart++;
            }
          }
        }

        minradius[ii] = mtmp;
        nm1d2 = mindiridx->size[0] * mindiridx->size[1];
        loop_ub = mindiridx->size[0] * mindiridx->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          SD->f0.tmp_data[i0] = (mindiridx->data[i0] >= minradius[ii]);
        }

        ixstart = angle2target->size[0] * angle2target->size[1];
        loop_ub = angle2target->size[0] * angle2target->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          SD->f0.c_tmp_data[i0] = (angle2target->data[i0] == 1.0 + (real_T)ii);
        }

        if (nm1d2 != ixstart) {
          emlrtSizeEqCheck1DR2012b(nm1d2, ixstart, &bb_emlrtECI, sp);
        }

        ixstart = nm1d2 - 1;
        b_loop_ub = 0;
        for (c_loop_ub = 0; c_loop_ub <= ixstart; c_loop_ub++) {
          if (SD->f0.tmp_data[c_loop_ub] && SD->f0.c_tmp_data[c_loop_ub]) {
            b_loop_ub++;
          }
        }

        i0 = r5->size[0];
        r5->size[0] = b_loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)r5, i0, (int32_T)sizeof
                          (int32_T), &emlrtRTEI);
        nm1d2 = 0;
        for (c_loop_ub = 0; c_loop_ub <= ixstart; c_loop_ub++) {
          if (SD->f0.tmp_data[c_loop_ub] && SD->f0.c_tmp_data[c_loop_ub]) {
            r5->data[nm1d2] = c_loop_ub + 1;
            nm1d2++;
          }
        }

        nm1d2 = cvistmp->size[0];
        ixstart = cvistmp->size[1];
        loop_ub = r5->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          i1 = nm1d2 * ixstart;
          i2 = r5->data[i0];
          if ((i2 >= 1) && (i2 < i1)) {
            i4 = i2;
          } else {
            i4 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &xf_emlrtBCI, sp);
          }

          cvistmp->data[i4 - 1] = 1.0;
        }
      }

      loop_ub = ccdp_cvis->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_tmp_data[i0] = i0;
      }

      d_loop_ub = ccdp_cvis->size[1];
      for (i0 = 0; i0 < d_loop_ub; i0++) {
        d_tmp_data[i0] = i0;
      }

      i0 = ccdp_cvis->size[2];
      i1 = (int32_T)((1.0 + (real_T)tt) + 1.0);
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ic_emlrtBCI, sp);
      iv1[0] = loop_ub;
      iv1[1] = d_loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv1, 2, *(int32_T (*)[2])cvistmp->size, 2,
        &v_emlrtECI, sp);
      loop_ub = cvistmp->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        d_loop_ub = cvistmp->size[0];
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          ccdp_cvis->data[(c_tmp_data[i1] + ccdp_cvis->size[0] * d_tmp_data[i0])
            + ccdp_cvis->size[0] * ccdp_cvis->size[1] * ((int32_T)((1.0 +
            (real_T)tt) + 1.0) - 1)] = cvistmp->data[i1 + cvistmp->size[0] * i0];
        }
      }

      /*   */
      ii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  -- [ Cost: Ctrack ] -- % */
    /*  sensing region */
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, ndir, mxDOUBLE_CLASS, (int32_T)ndir,
      &fb_emlrtRTEI, sp);
    ii = 0;
    while (ii <= (int32_T)ndir - 1) {
      /* ccdp.ctrack(tt+1).val(:,:,ii) = reshape(sum(1-normcdf(bsxfun(@plus,costparam.A(:,:,ii)*[ccdp.xs(:)-pEst(tt).mean(1),ccdp.ys(:)-pEst(tt).mean(2)]',costparam.cc)/pEst(tt).sig),1) > threshold_track,[rlen,clen]);% matrix of normal vectors of sensing region */
      i0 = pEst->size[1];
      i1 = tt + 1;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &uc_emlrtBCI, sp);
      i0 = pEst->size[1];
      i1 = tt + 1;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &sc_emlrtBCI, sp);
      i0 = pEst->data[tt].mean->size[1] << 1;
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &tc_emlrtBCI, sp);
      ixstart = ccdp->xs->size[0] * ccdp->xs->size[1];
      i0 = r0->size[0] * r0->size[1];
      r0->size[0] = ixstart;
      r0->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)r0, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ixstart = ccdp->xs->size[0] * ccdp->xs->size[1];
      mtmp = pEst->data[tt].mean->data[0];
      for (i0 = 0; i0 < ixstart; i0++) {
        r0->data[i0] = ccdp->xs->data[i0] - mtmp;
      }

      i0 = pEst->data[tt].mean->size[1] << 1;
      emlrtDynamicBoundsCheckR2012b(2, 1, i0, &rc_emlrtBCI, sp);
      ixstart = ccdp->ys->size[0] * ccdp->ys->size[1];
      i0 = r1->size[0] * r1->size[1];
      r1->size[0] = ixstart;
      r1->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)r1, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      ixstart = ccdp->ys->size[0] * ccdp->ys->size[1];
      mtmp = pEst->data[tt].mean->data[1];
      for (i0 = 0; i0 < ixstart; i0++) {
        r1->data[i0] = ccdp->ys->data[i0] - mtmp;
      }

      i0 = r0->size[0];
      i1 = r1->size[0];
      if (i0 != i1) {
        emlrtDimSizeEqCheckR2012b(i0, i1, &ab_emlrtECI, sp);
      }

      loop_ub = ccdp_ctrack->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_tmp_data[i0] = i0;
      }

      d_loop_ub = ccdp_ctrack->size[1];
      for (i0 = 0; i0 < d_loop_ub; i0++) {
        d_tmp_data[i0] = i0;
      }

      i0 = ccdp_ctrack->size[2];
      i1 = ii + 1;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &pc_emlrtBCI, sp);
      i0 = ccdp_ctrack->size[3];
      i1 = (int32_T)((1.0 + (real_T)tt) + 1.0);
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &oc_emlrtBCI, sp);
      st.site = &e_emlrtRSI;
      b_loop_ub = costparam->A->size[0];
      i0 = costparam->A->size[2];
      if ((ii + 1 >= 1) && (ii + 1 < i0)) {
        nm1d2 = ii + 1;
      } else {
        nm1d2 = emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i0, &vc_emlrtBCI, &st);
      }

      i0 = a->size[0] * a->size[1];
      a->size[0] = b_loop_ub;
      a->size[1] = 2;
      emxEnsureCapacity(&st, (emxArray__common *)a, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < 2; i0++) {
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          a->data[i1 + a->size[0] * i0] = costparam->A->data[(i1 + costparam->
            A->size[0] * i0) + costparam->A->size[0] * costparam->A->size[1] *
            (nm1d2 - 1)];
        }
      }

      i0 = b->size[0] * b->size[1];
      b->size[0] = 2;
      b->size[1] = r0->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)b, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      b_loop_ub = r0->size[0];
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        b->data[b->size[0] * i0] = r0->data[i0];
      }

      b_loop_ub = r1->size[0];
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        b->data[1 + b->size[0] * i0] = r1->data[i0];
      }

      i0 = costparam->A->size[0];
      currs_idx[1] = (uint32_T)b->size[1];
      i1 = A->size[0] * A->size[1];
      A->size[0] = i0;
      emxEnsureCapacity(&st, (emxArray__common *)A, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      i1 = A->size[0] * A->size[1];
      A->size[1] = (int32_T)currs_idx[1];
      emxEnsureCapacity(&st, (emxArray__common *)A, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      b_loop_ub = i0 * (int32_T)currs_idx[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        A->data[i1] = 0.0;
      }

      b_st.site = &db_emlrtRSI;
      c_st.site = &eb_emlrtRSI;
      i1 = C->size[0] * C->size[1];
      C->size[0] = i0;
      emxEnsureCapacity(&c_st, (emxArray__common *)C, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      i1 = C->size[0] * C->size[1];
      C->size[1] = (int32_T)currs_idx[1];
      emxEnsureCapacity(&c_st, (emxArray__common *)C, i1, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      b_loop_ub = i0 * (int32_T)currs_idx[1];
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        C->data[i0] = 0.0;
      }

      i0 = costparam->A->size[0];
      if ((i0 < 1) || (b->size[1] < 1)) {
      } else {
        d_st.site = &fb_emlrtRSI;
        mtmp = 1.0;
        b_ccdp = 0.0;
        TRANSB = 'N';
        TRANSA = 'N';
        i0 = costparam->A->size[0];
        m_t = (ptrdiff_t)i0;
        n_t = (ptrdiff_t)b->size[1];
        k_t = (ptrdiff_t)2;
        i0 = costparam->A->size[0];
        lda_t = (ptrdiff_t)i0;
        ldb_t = (ptrdiff_t)2;
        i0 = costparam->A->size[0];
        ldc_t = (ptrdiff_t)i0;
        dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &mtmp, &a->data[0], &lda_t,
              &b->data[0], &ldb_t, &b_ccdp, &C->data[0], &ldc_t);
      }

      st.site = &e_emlrtRSI;
      bsxfun(&st, C, costparam->cc, A);
      i0 = pEst->size[1];
      i1 = tt + 1;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &qc_emlrtBCI, sp);
      st.site = &e_emlrtRSI;
      i0 = b_A->size[0] * b_A->size[1];
      b_A->size[0] = A->size[0];
      b_A->size[1] = A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)b_A, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      b_loop_ub = A->size[0] * A->size[1];
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        b_A->data[i0] = A->data[i0] / pEst->data[tt].sig;
      }

      b_st.site = &e_emlrtRSI;
      normcdf(&b_st, b_A, A);
      i0 = r9->size[0] * r9->size[1];
      r9->size[0] = A->size[0];
      r9->size[1] = A->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)r9, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      b_loop_ub = A->size[0] * A->size[1];
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        r9->data[i0] = 1.0 - A->data[i0];
      }

      b_st.site = &e_emlrtRSI;
      b_sum(&b_st, r9, r8);
      CompMat[0] = 1;
      CompMat[1] = r8->size[1];
      b_loop_ub = r8->size[0] * r8->size[1];
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        SD->f0.x_data[i0] = (r8->data[i0] > threshold_track);
      }

      lagrng[0] = (uint8_T)rlen;
      lagrng[1] = (uint8_T)clen;
      b_st.site = &ob_emlrtRSI;
      eml_assert_valid_size_arg(&b_st, lagrng);
      for (i0 = 0; i0 < 2; i0++) {
        sz[i0] = (uint8_T)lagrng[i0];
        lagrng[i0] = CompMat[i0];
      }

      ixstart = 1;
      if ((uint16_T)lagrng[1] > 1) {
        ixstart = (uint16_T)lagrng[1];
      }

      if (CompMat[1] < ixstart) {
        nm1d2 = ixstart;
      } else {
        nm1d2 = CompMat[1];
      }

      if (sz[0] > nm1d2) {
        b_st.site = &pb_emlrtRSI;
        eml_error(&b_st);
      }

      if (sz[1] > nm1d2) {
        b_st.site = &pb_emlrtRSI;
        eml_error(&b_st);
      }

      if (CompMat[1] == sz[0] * sz[1]) {
      } else {
        emlrtErrorWithMessageIdR2012b(&st, &ab_emlrtRTEI,
          "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
      }

      b_st.site = &qb_emlrtRSI;
      for (ixstart = 0; ixstart + 1 <= CompMat[1]; ixstart++) {
        y_data[ixstart] = SD->f0.x_data[ixstart];
      }

      i0 = r4->size[0] * r4->size[1];
      r4->size[0] = sz[0];
      r4->size[1] = sz[1];
      emxEnsureCapacity(sp, (emxArray__common *)r4, i0, (int32_T)sizeof(real_T),
                        &emlrtRTEI);
      b_loop_ub = sz[0] * sz[1];
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        r4->data[i0] = y_data[i0];
      }

      iv2[0] = loop_ub;
      iv2[1] = d_loop_ub;
      emlrtSubAssignSizeCheckR2012b(iv2, 2, *(int32_T (*)[2])r4->size, 2,
        &y_emlrtECI, sp);
      loop_ub = r4->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        d_loop_ub = r4->size[0];
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          ccdp_ctrack->data[((c_tmp_data[i1] + ccdp_ctrack->size[0] *
                              d_tmp_data[i0]) + ccdp_ctrack->size[0] *
                             ccdp_ctrack->size[1] * ii) + ccdp_ctrack->size[0] *
            ccdp_ctrack->size[1] * ccdp_ctrack->size[2] * ((int32_T)((1.0 +
            (real_T)tt) + 1.0) - 1)] = r4->data[i1 + r4->size[0] * i0];
        }
      }

      /*  matrix of normal vectors of sensing region */
      ii++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  -- [Cost: Cavoid ] -- % */
    /*  probability of collision is determined by Rfree */
    loop_ub = ccdp_cavoid->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_tmp_data[i0] = i0;
    }

    d_loop_ub = ccdp_cavoid->size[1];
    for (i0 = 0; i0 < d_loop_ub; i0++) {
      d_tmp_data[i0] = i0;
    }

    i0 = ccdp_cavoid->size[2];
    i1 = (int32_T)((1.0 + (real_T)tt) + 1.0);
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &mc_emlrtBCI, sp);
    i0 = g_ccdp->size[0] * g_ccdp->size[1];
    g_ccdp->size[0] = ccdp->gmap.size[0];
    g_ccdp->size[1] = ccdp->gmap.size[1];
    emxEnsureCapacity(sp, (emxArray__common *)g_ccdp, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    b_loop_ub = ccdp->gmap.size[0] * ccdp->gmap.size[1];
    for (i0 = 0; i0 < b_loop_ub; i0++) {
      g_ccdp->data[i0] = ccdp->gmap.data[i0];
    }

    st.site = &f_emlrtRSI;
    conv2(&st, g_ccdp, r6);
    i0 = r6->size[0] * r6->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r6, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = r6->size[0];
    i1 = r6->size[1];
    b_loop_ub = i0 * i1;
    for (i0 = 0; i0 < b_loop_ub; i0++) {
      r6->data[i0] = (r6->data[i0] >= 1.0);
    }

    Jmin[0] = loop_ub;
    Jmin[1] = d_loop_ub;
    emlrtSubAssignSizeCheckR2012b(Jmin, 2, *(int32_T (*)[2])r6->size, 2,
      &x_emlrtECI, sp);
    loop_ub = r6->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_loop_ub = r6->size[0];
      for (i1 = 0; i1 < d_loop_ub; i1++) {
        ccdp_cavoid->data[(c_tmp_data[i1] + ccdp_cavoid->size[0] * d_tmp_data[i0])
          + ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * ((int32_T)((1.0 +
          (real_T)tt) + 1.0) - 1)] = r6->data[i1 + r6->size[0] * i0];
      }
    }

    /*  -- [ value of constraint ] -- % */
    /* ccdp.cconst(tt+1).val = bsxfun(@or,ccdp.ctrack(tt+1).val,ccdp.cavoid(:,:,tt+1)); */
    loop_ub = ccdp_cconst->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_tmp_data[i0] = i0;
    }

    d_loop_ub = ccdp_cconst->size[1];
    for (i0 = 0; i0 < d_loop_ub; i0++) {
      d_tmp_data[i0] = i0;
    }

    b_loop_ub = ccdp_cconst->size[2];
    i0 = r2->size[0];
    r2->size[0] = b_loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < b_loop_ub; i0++) {
      r2->data[i0] = i0;
    }

    i0 = ccdp_cconst->size[3];
    i1 = (int32_T)((1.0 + (real_T)tt) + 1.0);
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &kc_emlrtBCI, sp);
    b_loop_ub = ccdp_ctrack->size[0];
    ixstart = ccdp_ctrack->size[1];
    c_loop_ub = ccdp_ctrack->size[2];
    i0 = ccdp_ctrack->size[3];
    i1 = (int32_T)((1.0 + (real_T)tt) + 1.0);
    if ((i1 >= 1) && (i1 < i0)) {
      i0 = i1;
    } else {
      i0 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &nc_emlrtBCI, sp);
    }

    i1 = b_ccdp_ctrack->size[0] * b_ccdp_ctrack->size[1] * b_ccdp_ctrack->size[2];
    b_ccdp_ctrack->size[0] = b_loop_ub;
    b_ccdp_ctrack->size[1] = ixstart;
    b_ccdp_ctrack->size[2] = c_loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_ccdp_ctrack, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      for (i2 = 0; i2 < ixstart; i2++) {
        for (i5 = 0; i5 < b_loop_ub; i5++) {
          b_ccdp_ctrack->data[(i5 + b_ccdp_ctrack->size[0] * i2) +
            b_ccdp_ctrack->size[0] * b_ccdp_ctrack->size[1] * i1] =
            ccdp_ctrack->data[((i5 + ccdp_ctrack->size[0] * i2) +
                               ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * i1)
            + ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2]
            * (i0 - 1)];
        }
      }
    }

    b_loop_ub = ccdp_cavoid->size[0];
    ixstart = ccdp_cavoid->size[1];
    i0 = ccdp_cavoid->size[2];
    i1 = (int32_T)((1.0 + (real_T)tt) + 1.0);
    if ((i1 >= 1) && (i1 < i0)) {
      i0 = i1;
    } else {
      i0 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &lc_emlrtBCI, sp);
    }

    i1 = b_ccdp_cavoid->size[0] * b_ccdp_cavoid->size[1];
    b_ccdp_cavoid->size[0] = b_loop_ub;
    b_ccdp_cavoid->size[1] = ixstart;
    emxEnsureCapacity(sp, (emxArray__common *)b_ccdp_cavoid, i1, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (i1 = 0; i1 < ixstart; i1++) {
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        b_ccdp_cavoid->data[i2 + b_ccdp_cavoid->size[0] * i1] =
          ccdp_cavoid->data[(i2 + ccdp_cavoid->size[0] * i1) + ccdp_cavoid->
          size[0] * ccdp_cavoid->size[1] * (i0 - 1)];
      }
    }

    st.site = &g_emlrtRSI;
    b_bsxfun(&st, b_ccdp_ctrack, b_ccdp_cavoid, r7);
    i0 = r3->size[0] * r3->size[1] * r3->size[2];
    r3->size[0] = r7->size[0];
    r3->size[1] = r7->size[1];
    r3->size[2] = r7->size[2];
    emxEnsureCapacity(sp, (emxArray__common *)r3, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    b_loop_ub = r7->size[0] * r7->size[1] * r7->size[2];
    for (i0 = 0; i0 < b_loop_ub; i0++) {
      r3->data[i0] = r7->data[i0];
    }

    b_Jmin[0] = loop_ub;
    b_Jmin[1] = d_loop_ub;
    b_Jmin[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(b_Jmin, 3, *(int32_T (*)[3])r3->size, 3,
      &w_emlrtECI, sp);
    loop_ub = r3->size[2];
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_loop_ub = r3->size[1];
      for (i1 = 0; i1 < d_loop_ub; i1++) {
        b_loop_ub = r3->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          ccdp_cconst->data[((c_tmp_data[i2] + ccdp_cconst->size[0] *
                              d_tmp_data[i1]) + ccdp_cconst->size[0] *
                             ccdp_cconst->size[1] * r2->data[i0]) +
            ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
            ((int32_T)((1.0 + (real_T)tt) + 1.0) - 1)] = r3->data[(i2 + r3->
            size[0] * i1) + r3->size[0] * r3->size[1] * i0];
        }
      }
    }

    tt++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_A);
  emxFree_real_T(&r9);
  emxFree_real_T(&k_ccdp);
  emxFree_real_T(&j_ccdp);
  emxFree_real_T(&i_ccdp);
  emxFree_real_T(&h_ccdp);
  emxFree_real_T(&g_ccdp);
  emxFree_real_T(&b_ccdp_cavoid);
  emxFree_real_T(&b_ccdp_ctrack);
  emxFree_real_T(&r8);
  emxFree_boolean_T(&r7);
  emxFree_real_T(&r6);
  emxFree_real_T(&b);
  emxFree_real_T(&a);
  emxFree_real_T(&A);
  emxFree_real_T(&C);
  emxFree_int32_T(&r5);
  emxFree_real_T(&r1);
  emxFree_real_T(&r0);

  /*  -- [ Backward recursion ] -- % */
  /*  find the optimal control when lambda is given */
  lagcoeff = 0.0;

  /* lagrangian coefficient */
  for (i0 = 0; i0 < 2; i0++) {
    lagrng[i0] = i0;
  }

  lag_feas = 1;

  /*  use to check the feasibility */
  flag_converge = 0;
  ilagran = 1;
  emxInit_real_T(sp, &Optctrl_col, 4, &h_emlrtRTEI, true);
  emxInit_real_T(sp, &Optctrl_dirs, 4, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &c_Jmin, 4, &j_emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_currs_idx, 2, &l_emlrtRTEI, true);
  c_emxInit_real_T(sp, &optidx, 2, &m_emlrtRTEI, true);
  c_emxInit_real_T(sp, &r10, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r11, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r12, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &r13, 2, &emlrtRTEI, true);
  b_emxInit_int32_T(sp, &iindx, 2, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &b_lagcoeff, 3, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_lag_feas, 2, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &c_lagcoeff, 3, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &c_lag_feas, 2, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &d_Jmin, 3, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_mindiridx, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_Optctrl_dirs, 2, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &e_Jmin, 3, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &f_Jmin, 3, &emlrtRTEI, true);
  b_emxInit_real_T(sp, &g_Jmin, 3, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &h_Jmin, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &c_angle2target, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &i_Jmin, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &d_angle2target, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &j_Jmin, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &e_angle2target, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &c_ccdp_ctrack, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &b_Optctrl_col, 2, &emlrtRTEI, true);
  c_emxInit_real_T(sp, &c_Optctrl_dirs, 2, &emlrtRTEI, true);
  b_emxInit_int32_T(sp, &b_cvistmp, 2, &emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (ilagran - 1 < 100)) {
    /*  initialize the optimal control: 'col': current column+col, */
    /*  'row': current row+'row',   dirs: replace current dirs with dirs */
    i0 = ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
      ccdp_ctrack->size[3];
    ccdp_ctrack->size[0] = rlen;
    ccdp_ctrack->size[1] = clen;
    ccdp_ctrack->size[2] = (int32_T)ndir;
    if (H >= 0.0) {
      b_ccdp = H;
    } else {
      b_ccdp = emlrtNonNegativeCheckR2012b(H, &b_emlrtDCI, sp);
    }

    if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
      ccdp_ctrack->size[3] = (int32_T)b_ccdp;
    } else {
      ccdp_ctrack->size[3] = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &emlrtDCI,
        sp);
    }

    emxEnsureCapacity(sp, (emxArray__common *)ccdp_ctrack, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    if (H >= 0.0) {
      b_ccdp = H;
    } else {
      b_ccdp = emlrtNonNegativeCheckR2012b(H, &b_emlrtDCI, sp);
    }

    if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
      l_ccdp = b_ccdp;
    } else {
      l_ccdp = emlrtIntegerCheckR2012b(b_ccdp, &emlrtDCI, sp);
    }

    loop_ub = rlen * clen * (int32_T)ndir * (int32_T)l_ccdp;
    for (i0 = 0; i0 < loop_ub; i0++) {
      ccdp_ctrack->data[i0] = 0.0;
    }

    i0 = Optctrl_col->size[0] * Optctrl_col->size[1] * Optctrl_col->size[2] *
      Optctrl_col->size[3];
    Optctrl_col->size[0] = rlen;
    Optctrl_col->size[1] = clen;
    Optctrl_col->size[2] = (int32_T)ndir;
    Optctrl_col->size[3] = (int32_T)H;
    emxEnsureCapacity(sp, (emxArray__common *)Optctrl_col, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = rlen * clen * (int32_T)ndir * (int32_T)H;
    for (i0 = 0; i0 < loop_ub; i0++) {
      Optctrl_col->data[i0] = 0.0;
    }

    i0 = Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * Optctrl_dirs->size[2] *
      Optctrl_dirs->size[3];
    Optctrl_dirs->size[0] = rlen;
    Optctrl_dirs->size[1] = clen;
    Optctrl_dirs->size[2] = (int32_T)ndir;
    Optctrl_dirs->size[3] = (int32_T)H;
    emxEnsureCapacity(sp, (emxArray__common *)Optctrl_dirs, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = rlen * clen * (int32_T)ndir * (int32_T)H;
    for (i0 = 0; i0 < loop_ub; i0++) {
      Optctrl_dirs->data[i0] = 0.0;
    }

    i0 = c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] * c_Jmin->size[3];
    c_Jmin->size[0] = rlen;
    emxEnsureCapacity(sp, (emxArray__common *)c_Jmin, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] * c_Jmin->size[3];
    c_Jmin->size[1] = clen;
    emxEnsureCapacity(sp, (emxArray__common *)c_Jmin, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] * c_Jmin->size[3];
    c_Jmin->size[2] = (int32_T)ndir;
    emxEnsureCapacity(sp, (emxArray__common *)c_Jmin, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    i0 = c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] * c_Jmin->size[3];
    c_Jmin->size[3] = (int32_T)(H + 1.0);
    emxEnsureCapacity(sp, (emxArray__common *)c_Jmin, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = rlen * clen * (int32_T)ndir * (int32_T)(H + 1.0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_Jmin->data[i0] = 100.0;
    }

    loop_ub = c_Jmin->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      c_tmp_data[i0] = i0;
    }

    d_loop_ub = c_Jmin->size[1];
    for (i0 = 0; i0 < d_loop_ub; i0++) {
      d_tmp_data[i0] = i0;
    }

    b_loop_ub = c_Jmin->size[2];
    i0 = r2->size[0];
    r2->size[0] = b_loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < b_loop_ub; i0++) {
      r2->data[i0] = i0;
    }

    i0 = c_Jmin->size[3];
    i1 = (int32_T)(H + 1.0);
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ec_emlrtBCI, sp);
    i0 = ccdp_cconst->size[3];
    i1 = (int32_T)(H + 1.0);
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &jc_emlrtBCI, sp);
    i0 = ccdp_cvis->size[2];
    i1 = (int32_T)(H + 1.0);
    emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &hc_emlrtBCI, sp);
    b_loop_ub = ccdp_cconst->size[0];
    ixstart = ccdp_cconst->size[1];
    c_loop_ub = ccdp_cconst->size[2];
    i0 = b_lagcoeff->size[0] * b_lagcoeff->size[1] * b_lagcoeff->size[2];
    b_lagcoeff->size[0] = b_loop_ub;
    b_lagcoeff->size[1] = ixstart;
    b_lagcoeff->size[2] = c_loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_lagcoeff, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (i0 = 0; i0 < c_loop_ub; i0++) {
      for (i1 = 0; i1 < ixstart; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_lagcoeff->data[(i2 + b_lagcoeff->size[0] * i1) + b_lagcoeff->size[0]
            * b_lagcoeff->size[1] * i0] = lagcoeff * ccdp_cconst->data[((i2 +
            ccdp_cconst->size[0] * i1) + ccdp_cconst->size[0] *
            ccdp_cconst->size[1] * i0) + ccdp_cconst->size[0] *
            ccdp_cconst->size[1] * ccdp_cconst->size[2] * ((int32_T)(H + 1.0) -
            1)];
        }
      }
    }

    b_loop_ub = ccdp_cvis->size[0];
    ixstart = ccdp_cvis->size[1];
    i0 = b_lag_feas->size[0] * b_lag_feas->size[1];
    b_lag_feas->size[0] = b_loop_ub;
    b_lag_feas->size[1] = ixstart;
    emxEnsureCapacity(sp, (emxArray__common *)b_lag_feas, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    for (i0 = 0; i0 < ixstart; i0++) {
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        b_lag_feas->data[i1 + b_lag_feas->size[0] * i0] = (real_T)lag_feas *
          ccdp_cvis->data[(i1 + ccdp_cvis->size[0] * i0) + ccdp_cvis->size[0] *
          ccdp_cvis->size[1] * ((int32_T)(H + 1.0) - 1)];
      }
    }

    st.site = &h_emlrtRSI;
    c_bsxfun(&st, b_lagcoeff, b_lag_feas, r3);
    iv3[0] = loop_ub;
    iv3[1] = d_loop_ub;
    iv3[2] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv3, 3, *(int32_T (*)[3])r3->size, 3,
      &u_emlrtECI, sp);
    loop_ub = r3->size[2];
    for (i0 = 0; i0 < loop_ub; i0++) {
      d_loop_ub = r3->size[1];
      for (i1 = 0; i1 < d_loop_ub; i1++) {
        b_loop_ub = r3->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          c_Jmin->data[((c_tmp_data[i2] + c_Jmin->size[0] * d_tmp_data[i1]) +
                        c_Jmin->size[0] * c_Jmin->size[1] * r2->data[i0]) +
            c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] * ((int32_T)(H +
            1.0) - 1)] = r3->data[(i2 + r3->size[0] * i1) + r3->size[0] *
            r3->size[1] * i0];
        }
      }
    }

    /* Value: Cvis + lambda * Ctrack */
    /* Optctrl(1:H)=struct('row',zeros([rlen,clen,ndir]),'col',zeros([rlen,clen,ndir]),'dirs',zeros([rlen,clen,ndir])); */
    /* Jmin(1:H+1) = struct('Jmin',100*ones([rlen,clen,ndir])); */
    /* Jmin(H+1).Jmin = bsxfun(@plus, lagcoeff*ccdp.cconst(H+1).val, lag_feas*ccdp.cvis(:,:,H+1)); %Value: Cvis + lambda * Ctrack */
    emlrtForLoopVectorCheckR2012b(H, -1.0, 1.0, mxDOUBLE_CLASS, (int32_T)-(1.0 +
      (-1.0 - H)), &eb_emlrtRTEI, sp);
    tt = 0;
    while (tt <= (int32_T)-(1.0 + (-1.0 - H)) - 1) {
      b_tt = H + -(real_T)tt;

      /*  lagrangian - onestep */
      i0 = ccdp_cconst->size[3];
      i1 = (int32_T)b_tt;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &gc_emlrtBCI, sp);
      i0 = ccdp_cvis->size[2];
      i1 = (int32_T)b_tt;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &fc_emlrtBCI, sp);
      loop_ub = ccdp_cconst->size[0];
      d_loop_ub = ccdp_cconst->size[1];
      b_loop_ub = ccdp_cconst->size[2];
      i0 = c_lagcoeff->size[0] * c_lagcoeff->size[1] * c_lagcoeff->size[2];
      c_lagcoeff->size[0] = loop_ub;
      c_lagcoeff->size[1] = d_loop_ub;
      c_lagcoeff->size[2] = b_loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)c_lagcoeff, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            c_lagcoeff->data[(i2 + c_lagcoeff->size[0] * i1) + c_lagcoeff->size
              [0] * c_lagcoeff->size[1] * i0] = lagcoeff * ccdp_cconst->data
              [((i2 + ccdp_cconst->size[0] * i1) + ccdp_cconst->size[0] *
                ccdp_cconst->size[1] * i0) + ccdp_cconst->size[0] *
              ccdp_cconst->size[1] * ccdp_cconst->size[2] * ((int32_T)b_tt - 1)];
          }
        }
      }

      loop_ub = ccdp_cvis->size[0];
      d_loop_ub = ccdp_cvis->size[1];
      i0 = c_lag_feas->size[0] * c_lag_feas->size[1];
      c_lag_feas->size[0] = loop_ub;
      c_lag_feas->size[1] = d_loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)c_lag_feas, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < d_loop_ub; i0++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          c_lag_feas->data[i1 + c_lag_feas->size[0] * i0] = (real_T)lag_feas *
            ccdp_cvis->data[(i1 + ccdp_cvis->size[0] * i0) + ccdp_cvis->size[0] *
            ccdp_cvis->size[1] * ((int32_T)b_tt - 1)];
        }
      }

      st.site = &i_emlrtRSI;
      c_bsxfun(&st, c_lagcoeff, c_lag_feas, ccdp_cavoid);

      /* Value: Cvis + lambda * Ctrack */
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, ndir, mxDOUBLE_CLASS, (int32_T)
        ndir, &db_emlrtRTEI, sp);
      ii = 0;
      while (ii <= (int32_T)ndir - 1) {
        st.site = &j_emlrtRSI;
        i0 = nextstate->size[1];
        i1 = nextstate->size[1];
        if ((ii + 1 >= 1) && (ii + 1 < i0)) {
          b_ii = ii + 1;
        } else {
          b_ii = emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i0, &yf_emlrtBCI, &st);
        }

        if ((ii + 1 >= 1) && (ii + 1 < i1)) {
          c_ii = ii + 1;
        } else {
          c_ii = emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i1, &yf_emlrtBCI, &st);
        }

        loop_ub = nextstate->data[b_ii - 1].dir->size[0] * nextstate->data[c_ii
          - 1].dir->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          i1 = c_Jmin->size[2];
          i2 = nextstate->size[1];
          if ((ii + 1 >= 1) && (ii + 1 < i2)) {
            d_ii = ii + 1;
          } else {
            d_ii = emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i2, &yf_emlrtBCI,
              &st);
          }

          b_ccdp = nextstate->data[d_ii - 1].dir->data[i0];
          if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
            i2 = (int32_T)b_ccdp;
          } else {
            i2 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &y_emlrtDCI, &st);
          }

          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ke_emlrtBCI, &st);
        }

        i0 = c_Jmin->size[3];
        i1 = (int32_T)(b_tt + 1.0);
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &dc_emlrtBCI, &st);
        b_st.site = &ac_emlrtRSI;
        loop_ub = c_Jmin->size[0];
        d_loop_ub = c_Jmin->size[1];
        i0 = d_Jmin->size[0] * d_Jmin->size[1] * d_Jmin->size[2];
        d_Jmin->size[0] = loop_ub;
        d_Jmin->size[1] = d_loop_ub;
        d_Jmin->size[2] = nextstate->data[ii].dir->size[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)d_Jmin, i0, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        b_loop_ub = nextstate->data[ii].dir->size[1];
        for (i0 = 0; i0 < b_loop_ub; i0++) {
          for (i1 = 0; i1 < d_loop_ub; i1++) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              d_Jmin->data[(i2 + d_Jmin->size[0] * i1) + d_Jmin->size[0] *
                d_Jmin->size[1] * i0] = c_Jmin->data[((i2 + c_Jmin->size[0] * i1)
                + c_Jmin->size[0] * c_Jmin->size[1] * ((int32_T)nextstate->
                data[ii].dir->data[nextstate->data[ii].dir->size[0] * i0] - 1))
                + c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] *
                ((int32_T)(b_tt + 1.0) - 1)];
            }
          }
        }

        c_st.site = &bc_emlrtRSI;
        eml_extremum(&c_st, d_Jmin, angle2target, iindx);
        i0 = cvistmp->size[0] * cvistmp->size[1];
        cvistmp->size[0] = iindx->size[0];
        cvistmp->size[1] = iindx->size[1];
        emxEnsureCapacity(&b_st, (emxArray__common *)cvistmp, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        loop_ub = iindx->size[0] * iindx->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          cvistmp->data[i0] = iindx->data[i0];
        }

        i0 = nextstate->size[1];
        i1 = ii + 1;
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &cc_emlrtBCI, sp);
        emlrtMatrixMatrixIndexCheckR2012b(*(int32_T (*)[2])nextstate->data[ii].
          dir->size, 2, *(int32_T (*)[2])cvistmp->size, 2, &t_emlrtECI, sp);
        i0 = mindiridx->size[0] * mindiridx->size[1];
        mindiridx->size[0] = cvistmp->size[0];
        mindiridx->size[1] = cvistmp->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)mindiridx, i0, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
        loop_ub = cvistmp->size[0] * cvistmp->size[1];
        for (i0 = 0; i0 < loop_ub; i0++) {
          i1 = nextstate->data[ii].dir->size[1];
          i2 = (int32_T)cvistmp->data[i0];
          if ((i2 >= 1) && (i2 < i1)) {
            i6 = i2;
          } else {
            i6 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &le_emlrtBCI, sp);
          }

          mindiridx->data[i0] = nextstate->data[ii].dir->data[i6 - 1];
        }

        /*  find the optimal control-onestep */
        i0 = nextstate->size[1];
        i1 = ii + 1;
        emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &bc_emlrtBCI, sp);
        jj = 0;
        while (jj <= nextstate->data[ii].sidxs->size[0] - 1) {
          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ac_emlrtBCI, sp);
          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &xb_emlrtBCI, sp);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &yb_emlrtBCI, sp);
          mtmp = muDoubleScalarMax(1.0, 1.0 - nextstate->data[ii].sidxs->data[jj]);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &wb_emlrtBCI, sp);
          b_ccdp = muDoubleScalarMin(rlen, (real_T)rlen - nextstate->data[ii].
            sidxs->data[jj]);
          st.site = &k_emlrtRSI;
          b_st.site = &fc_emlrtRSI;
          c_st.site = &gc_emlrtRSI;
          if (muDoubleScalarIsNaN(mtmp) || muDoubleScalarIsNaN(b_ccdp)) {
            n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (b_ccdp < mtmp) {
            n = -1;
            anew = mtmp;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (muDoubleScalarIsInf(mtmp) || muDoubleScalarIsInf(b_ccdp)) {
            n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = !(mtmp == b_ccdp);
          } else {
            anew = mtmp;
            ndbl = muDoubleScalarFloor((b_ccdp - mtmp) + 0.5);
            apnd = mtmp + ndbl;
            cdiff = apnd - b_ccdp;
            absb = muDoubleScalarAbs(b_ccdp);
            if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                muDoubleScalarMax(mtmp, absb)) {
              ndbl++;
              apnd = b_ccdp;
            } else if (cdiff > 0.0) {
              apnd = mtmp + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            n_too_large = false;
            if (ndbl >= 0.0) {
              n = (int32_T)ndbl - 1;
            } else {
              n = -1;
            }
          }

          d_st.site = &hc_emlrtRSI;
          if (!n_too_large) {
          } else {
            emlrtErrorWithMessageIdR2012b(&d_st, &bb_emlrtRTEI,
              "Coder:MATLAB:pmaxsize", 0);
          }

          if (n + 1 > 0) {
            original_rng_r_data[0] = anew;
            if (n + 1 > 1) {
              original_rng_r_data[n] = apnd;
              i0 = n + (n < 0);
              if (i0 >= 0) {
                nm1d2 = (int32_T)((uint32_T)i0 >> 1);
              } else {
                nm1d2 = (int32_T)~(~(uint32_T)i0 >> 1);
              }

              d_st.site = &ic_emlrtRSI;
              for (ixstart = 1; ixstart < nm1d2; ixstart++) {
                original_rng_r_data[ixstart] = anew + (real_T)ixstart;
                original_rng_r_data[n - ixstart] = apnd - (real_T)ixstart;
              }

              if (nm1d2 << 1 == n) {
                original_rng_r_data[nm1d2] = (anew + apnd) / 2.0;
              } else {
                original_rng_r_data[nm1d2] = anew + (real_T)nm1d2;
                original_rng_r_data[nm1d2 + 1] = apnd - (real_T)nm1d2;
              }
            }
          }

          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &vb_emlrtBCI, sp);
          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &tb_emlrtBCI, sp);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ub_emlrtBCI, sp);
          mtmp = muDoubleScalarMax(1.0, 1.0 - nextstate->data[ii].sidxs->data[jj
            + nextstate->data[ii].sidxs->size[0]]);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &sb_emlrtBCI, sp);
          b_ccdp = muDoubleScalarMin(clen, (real_T)clen - nextstate->data[ii].
            sidxs->data[jj + nextstate->data[ii].sidxs->size[0]]);
          st.site = &l_emlrtRSI;
          b_st.site = &fc_emlrtRSI;
          c_st.site = &gc_emlrtRSI;
          if (muDoubleScalarIsNaN(mtmp) || muDoubleScalarIsNaN(b_ccdp)) {
            b_n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (b_ccdp < mtmp) {
            b_n = -1;
            anew = mtmp;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (muDoubleScalarIsInf(mtmp) || muDoubleScalarIsInf(b_ccdp)) {
            b_n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = !(mtmp == b_ccdp);
          } else {
            anew = mtmp;
            ndbl = muDoubleScalarFloor((b_ccdp - mtmp) + 0.5);
            apnd = mtmp + ndbl;
            cdiff = apnd - b_ccdp;
            absb = muDoubleScalarAbs(b_ccdp);
            if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                muDoubleScalarMax(mtmp, absb)) {
              ndbl++;
              apnd = b_ccdp;
            } else if (cdiff > 0.0) {
              apnd = mtmp + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            n_too_large = false;
            if (ndbl >= 0.0) {
              b_n = (int32_T)ndbl - 1;
            } else {
              b_n = -1;
            }
          }

          d_st.site = &hc_emlrtRSI;
          if (!n_too_large) {
          } else {
            emlrtErrorWithMessageIdR2012b(&d_st, &bb_emlrtRTEI,
              "Coder:MATLAB:pmaxsize", 0);
          }

          if (b_n + 1 > 0) {
            original_rng_c_data[0] = anew;
            if (b_n + 1 > 1) {
              original_rng_c_data[b_n] = apnd;
              i0 = b_n + (b_n < 0);
              if (i0 >= 0) {
                nm1d2 = (int32_T)((uint32_T)i0 >> 1);
              } else {
                nm1d2 = (int32_T)~(~(uint32_T)i0 >> 1);
              }

              d_st.site = &ic_emlrtRSI;
              for (ixstart = 1; ixstart < nm1d2; ixstart++) {
                original_rng_c_data[ixstart] = anew + (real_T)ixstart;
                original_rng_c_data[b_n - ixstart] = apnd - (real_T)ixstart;
              }

              if (nm1d2 << 1 == b_n) {
                original_rng_c_data[nm1d2] = (anew + apnd) / 2.0;
              } else {
                original_rng_c_data[nm1d2] = anew + (real_T)nm1d2;
                original_rng_c_data[nm1d2 + 1] = apnd - (real_T)nm1d2;
              }
            }
          }

          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &rb_emlrtBCI, sp);
          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &pb_emlrtBCI, sp);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &qb_emlrtBCI, sp);
          mtmp = muDoubleScalarMax(1.0, 1.0 + nextstate->data[ii].sidxs->data[jj]);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ob_emlrtBCI, sp);
          b_ccdp = muDoubleScalarMin(rlen, (real_T)rlen + nextstate->data[ii].
            sidxs->data[jj]);
          st.site = &m_emlrtRSI;
          b_st.site = &fc_emlrtRSI;
          c_st.site = &gc_emlrtRSI;
          if (muDoubleScalarIsNaN(mtmp) || muDoubleScalarIsNaN(b_ccdp)) {
            c_n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (b_ccdp < mtmp) {
            c_n = -1;
            anew = mtmp;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (muDoubleScalarIsInf(mtmp) || muDoubleScalarIsInf(b_ccdp)) {
            c_n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = !(mtmp == b_ccdp);
          } else {
            anew = mtmp;
            ndbl = muDoubleScalarFloor((b_ccdp - mtmp) + 0.5);
            apnd = mtmp + ndbl;
            cdiff = apnd - b_ccdp;
            absb = muDoubleScalarAbs(b_ccdp);
            if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                muDoubleScalarMax(mtmp, absb)) {
              ndbl++;
              apnd = b_ccdp;
            } else if (cdiff > 0.0) {
              apnd = mtmp + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            n_too_large = false;
            if (ndbl >= 0.0) {
              c_n = (int32_T)ndbl - 1;
            } else {
              c_n = -1;
            }
          }

          d_st.site = &hc_emlrtRSI;
          if (!n_too_large) {
          } else {
            emlrtErrorWithMessageIdR2012b(&d_st, &bb_emlrtRTEI,
              "Coder:MATLAB:pmaxsize", 0);
          }

          if (c_n + 1 > 0) {
            comp_rng_r_data[0] = anew;
            if (c_n + 1 > 1) {
              comp_rng_r_data[c_n] = apnd;
              i0 = c_n + (c_n < 0);
              if (i0 >= 0) {
                nm1d2 = (int32_T)((uint32_T)i0 >> 1);
              } else {
                nm1d2 = (int32_T)~(~(uint32_T)i0 >> 1);
              }

              d_st.site = &ic_emlrtRSI;
              for (ixstart = 1; ixstart < nm1d2; ixstart++) {
                comp_rng_r_data[ixstart] = anew + (real_T)ixstart;
                comp_rng_r_data[c_n - ixstart] = apnd - (real_T)ixstart;
              }

              if (nm1d2 << 1 == c_n) {
                comp_rng_r_data[nm1d2] = (anew + apnd) / 2.0;
              } else {
                comp_rng_r_data[nm1d2] = anew + (real_T)nm1d2;
                comp_rng_r_data[nm1d2 + 1] = apnd - (real_T)nm1d2;
              }
            }
          }

          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &nb_emlrtBCI, sp);
          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &lb_emlrtBCI, sp);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &mb_emlrtBCI, sp);
          mtmp = muDoubleScalarMax(1.0, 1.0 + nextstate->data[ii].sidxs->data[jj
            + nextstate->data[ii].sidxs->size[0]]);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = jj + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &kb_emlrtBCI, sp);
          b_ccdp = muDoubleScalarMin(clen, (real_T)clen + nextstate->data[ii].
            sidxs->data[jj + nextstate->data[ii].sidxs->size[0]]);
          st.site = &n_emlrtRSI;
          b_st.site = &fc_emlrtRSI;
          c_st.site = &gc_emlrtRSI;
          if (muDoubleScalarIsNaN(mtmp) || muDoubleScalarIsNaN(b_ccdp)) {
            d_n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (b_ccdp < mtmp) {
            d_n = -1;
            anew = mtmp;
            apnd = b_ccdp;
            n_too_large = false;
          } else if (muDoubleScalarIsInf(mtmp) || muDoubleScalarIsInf(b_ccdp)) {
            d_n = 0;
            anew = rtNaN;
            apnd = b_ccdp;
            n_too_large = !(mtmp == b_ccdp);
          } else {
            anew = mtmp;
            ndbl = muDoubleScalarFloor((b_ccdp - mtmp) + 0.5);
            apnd = mtmp + ndbl;
            cdiff = apnd - b_ccdp;
            absb = muDoubleScalarAbs(b_ccdp);
            if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 *
                muDoubleScalarMax(mtmp, absb)) {
              ndbl++;
              apnd = b_ccdp;
            } else if (cdiff > 0.0) {
              apnd = mtmp + (ndbl - 1.0);
            } else {
              ndbl++;
            }

            n_too_large = false;
            if (ndbl >= 0.0) {
              d_n = (int32_T)ndbl - 1;
            } else {
              d_n = -1;
            }
          }

          d_st.site = &hc_emlrtRSI;
          if (!n_too_large) {
          } else {
            emlrtErrorWithMessageIdR2012b(&d_st, &bb_emlrtRTEI,
              "Coder:MATLAB:pmaxsize", 0);
          }

          if (d_n + 1 > 0) {
            comp_rng_c_data[0] = anew;
            if (d_n + 1 > 1) {
              comp_rng_c_data[d_n] = apnd;
              i0 = d_n + (d_n < 0);
              if (i0 >= 0) {
                nm1d2 = (int32_T)((uint32_T)i0 >> 1);
              } else {
                nm1d2 = (int32_T)~(~(uint32_T)i0 >> 1);
              }

              d_st.site = &ic_emlrtRSI;
              for (ixstart = 1; ixstart < nm1d2; ixstart++) {
                comp_rng_c_data[ixstart] = anew + (real_T)ixstart;
                comp_rng_c_data[d_n - ixstart] = apnd - (real_T)ixstart;
              }

              if (nm1d2 << 1 == d_n) {
                comp_rng_c_data[nm1d2] = (anew + apnd) / 2.0;
              } else {
                comp_rng_c_data[nm1d2] = anew + (real_T)nm1d2;
                comp_rng_c_data[nm1d2 + 1] = apnd - (real_T)nm1d2;
              }
            }
          }

          /*  compare two matrix */
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[0];
            if (original_rng_r_data[i0] == (int32_T)muDoubleScalarFloor
                (original_rng_r_data[i0])) {
              i2 = (int32_T)original_rng_r_data[i0];
            } else {
              i2 = (int32_T)emlrtIntegerCheckR2012b(original_rng_r_data[i0],
                &ab_emlrtDCI, sp);
            }

            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &me_emlrtBCI, sp);
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[1];
            if (original_rng_c_data[i0] == (int32_T)muDoubleScalarFloor
                (original_rng_c_data[i0])) {
              i2 = (int32_T)original_rng_c_data[i0];
            } else {
              i2 = (int32_T)emlrtIntegerCheckR2012b(original_rng_c_data[i0],
                &bb_emlrtDCI, sp);
            }

            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ne_emlrtBCI, sp);
          }

          i0 = c_Jmin->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &jb_emlrtBCI, sp);
          i0 = c_Jmin->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ib_emlrtBCI, sp);
          loop_ub = c_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = angle2target->size[0];
            if (comp_rng_r_data[i0] == (int32_T)muDoubleScalarFloor
                (comp_rng_r_data[i0])) {
              i2 = (int32_T)comp_rng_r_data[i0];
            } else {
              i2 = (int32_T)emlrtIntegerCheckR2012b(comp_rng_r_data[i0],
                &cb_emlrtDCI, sp);
            }

            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &oe_emlrtBCI, sp);
          }

          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = angle2target->size[1];
            if (comp_rng_c_data[i0] == (int32_T)muDoubleScalarFloor
                (comp_rng_c_data[i0])) {
              i2 = (int32_T)comp_rng_c_data[i0];
            } else {
              i2 = (int32_T)emlrtIntegerCheckR2012b(comp_rng_c_data[i0],
                &db_emlrtDCI, sp);
            }

            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &pe_emlrtBCI, sp);
          }

          i0 = h_Jmin->size[0] * h_Jmin->size[1];
          h_Jmin->size[0] = n + 1;
          h_Jmin->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)h_Jmin, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              h_Jmin->data[i1 + h_Jmin->size[0] * i0] = c_Jmin->data[((((int32_T)
                original_rng_r_data[i1] + c_Jmin->size[0] * ((int32_T)
                original_rng_c_data[i0] - 1)) + c_Jmin->size[0] * c_Jmin->size[1]
                * ii) + c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] *
                ((int32_T)b_tt - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = h_Jmin->size[i0];
          }

          i0 = c_angle2target->size[0] * c_angle2target->size[1];
          c_angle2target->size[0] = c_n + 1;
          c_angle2target->size[1] = d_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)c_angle2target, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = c_n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              c_angle2target->data[i1 + c_angle2target->size[0] * i0] =
                angle2target->data[((int32_T)comp_rng_r_data[i1] +
                                    angle2target->size[0] * ((int32_T)
                comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            b_angle2target[i0] = c_angle2target->size[i0];
          }

          if ((Jmin[0] != b_angle2target[0]) || (Jmin[1] != b_angle2target[1]))
          {
            emlrtSizeEqCheckNDR2012b(Jmin, b_angle2target, &s_emlrtECI, sp);
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &qe_emlrtBCI, sp);
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &re_emlrtBCI, sp);
          }

          i0 = c_Jmin->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &hb_emlrtBCI, sp);
          i0 = c_Jmin->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &gb_emlrtBCI, sp);
          loop_ub = c_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = angle2target->size[0];
            i2 = (int32_T)comp_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &se_emlrtBCI, sp);
          }

          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = angle2target->size[1];
            i2 = (int32_T)comp_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &te_emlrtBCI, sp);
          }

          i0 = i_Jmin->size[0] * i_Jmin->size[1];
          i_Jmin->size[0] = n + 1;
          i_Jmin->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)i_Jmin, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              i_Jmin->data[i1 + i_Jmin->size[0] * i0] = c_Jmin->data[((((int32_T)
                original_rng_r_data[i1] + c_Jmin->size[0] * ((int32_T)
                original_rng_c_data[i0] - 1)) + c_Jmin->size[0] * c_Jmin->size[1]
                * ii) + c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] *
                ((int32_T)b_tt - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = i_Jmin->size[i0];
          }

          i0 = d_angle2target->size[0] * d_angle2target->size[1];
          d_angle2target->size[0] = c_n + 1;
          d_angle2target->size[1] = d_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)d_angle2target, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = c_n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              d_angle2target->data[i1 + d_angle2target->size[0] * i0] =
                angle2target->data[((int32_T)comp_rng_r_data[i1] +
                                    angle2target->size[0] * ((int32_T)
                comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            b_angle2target[i0] = d_angle2target->size[i0];
          }

          if ((Jmin[0] != b_angle2target[0]) || (Jmin[1] != b_angle2target[1]))
          {
            emlrtSizeEqCheckNDR2012b(Jmin, b_angle2target, &q_emlrtECI, sp);
          }

          i0 = Optctrl_dirs->size[3];
          i1 = (int32_T)b_tt;
          if ((i1 >= 1) && (i1 < i0)) {
            ixstart = i1;
          } else {
            ixstart = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &eb_emlrtBCI, sp);
          }

          i0 = Optctrl_dirs->size[2];
          if ((ii + 1 >= 1) && (ii + 1 < i0)) {
            nm1d2 = ii + 1;
          } else {
            nm1d2 = emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i0, &fb_emlrtBCI,
              sp);
          }

          i0 = b_Optctrl_dirs->size[0] * b_Optctrl_dirs->size[1];
          b_Optctrl_dirs->size[0] = n + 1;
          b_Optctrl_dirs->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_Optctrl_dirs, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              i2 = Optctrl_dirs->size[0];
              i5 = (int32_T)original_rng_r_data[i1];
              c_loop_ub = Optctrl_dirs->size[1];
              b_loop_ub = (int32_T)original_rng_c_data[i0];
              if ((i5 >= 1) && (i5 < i2)) {
                i7 = i5;
              } else {
                i7 = emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &ue_emlrtBCI, sp);
              }

              if ((b_loop_ub >= 1) && (b_loop_ub < c_loop_ub)) {
                e_loop_ub = b_loop_ub;
              } else {
                e_loop_ub = emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1,
                  c_loop_ub, &ve_emlrtBCI, sp);
              }

              b_Optctrl_dirs->data[i1 + b_Optctrl_dirs->size[0] * i0] =
                Optctrl_dirs->data[(((i7 + Optctrl_dirs->size[0] * (e_loop_ub -
                1)) + Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * (nm1d2 - 1))
                                    + Optctrl_dirs->size[0] * Optctrl_dirs->
                                    size[1] * Optctrl_dirs->size[2] * (ixstart -
                1)) - 1];
            }
          }

          b_abs(sp, b_Optctrl_dirs, r4);
          i0 = b_mindiridx->size[0] * b_mindiridx->size[1];
          b_mindiridx->size[0] = c_n + 1;
          b_mindiridx->size[1] = d_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_mindiridx, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = c_n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              i2 = cvistmp->size[0];
              i5 = (int32_T)comp_rng_r_data[i1];
              c_loop_ub = cvistmp->size[1];
              b_loop_ub = (int32_T)comp_rng_c_data[i0];
              if ((i5 >= 1) && (i5 < i2)) {
                i8 = i5;
              } else {
                i8 = emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &we_emlrtBCI, sp);
              }

              if ((b_loop_ub >= 1) && (b_loop_ub < c_loop_ub)) {
                f_loop_ub = b_loop_ub;
              } else {
                f_loop_ub = emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1,
                  c_loop_ub, &xe_emlrtBCI, sp);
              }

              b_mindiridx->data[i1 + b_mindiridx->size[0] * i0] =
                mindiridx->data[(i8 + mindiridx->size[0] * (f_loop_ub - 1)) - 1];
            }
          }

          b_abs(sp, b_mindiridx, r10);
          for (i0 = 0; i0 < 2; i0++) {
            iv0[i0] = r4->size[i0];
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = r10->size[i0];
          }

          if ((iv0[0] != Jmin[0]) || (iv0[1] != Jmin[1])) {
            emlrtSizeEqCheckNDR2012b(iv0, Jmin, &r_emlrtECI, sp);
          }

          y_size[0] = n + 1;
          y_size[1] = b_n + 1;
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              y_data[i1 + (n + 1) * i0] = (c_Jmin->data[((((int32_T)
                original_rng_r_data[i1] + c_Jmin->size[0] * ((int32_T)
                original_rng_c_data[i0] - 1)) + c_Jmin->size[0] * c_Jmin->size[1]
                * ii) + c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] *
                ((int32_T)b_tt - 1)) - 1] == angle2target->data[((int32_T)
                comp_rng_r_data[i1] + angle2target->size[0] * ((int32_T)
                comp_rng_c_data[i0] - 1)) - 1]);
            }
          }

          b_tmp_size[0] = r4->size[0];
          b_tmp_size[1] = r4->size[1];
          loop_ub = r4->size[0] * r4->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            e_tmp_data[i0] = (r4->data[i0] > r10->data[i0]);
          }

          for (i0 = 0; i0 < 2; i0++) {
            b_angle2target[i0] = y_size[i0];
            iv0[i0] = b_tmp_size[i0];
          }

          if ((b_angle2target[0] != iv0[0]) || (b_angle2target[1] != iv0[1])) {
            emlrtSizeEqCheckNDR2012b(b_angle2target, iv0, &q_emlrtECI, sp);
          }

          CompMat_size[0] = n + 1;
          CompMat_size[1] = b_n + 1;
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              CompMat_data[i1 + (n + 1) * i0] = (c_Jmin->data[((((int32_T)
                original_rng_r_data[i1] + c_Jmin->size[0] * ((int32_T)
                original_rng_c_data[i0] - 1)) + c_Jmin->size[0] * c_Jmin->size[1]
                * ii) + c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] *
                ((int32_T)b_tt - 1)) - 1] > angle2target->data[((int32_T)
                comp_rng_r_data[i1] + angle2target->size[0] * ((int32_T)
                comp_rng_c_data[i0] - 1)) - 1]);
            }
          }

          loop_ub = (n + 1) * (b_n + 1);
          for (i0 = 0; i0 < loop_ub; i0++) {
            y_data[i0] = (y_data[i0] && e_tmp_data[i0]);
          }

          for (i0 = 0; i0 < 2; i0++) {
            CompMat[i0] = CompMat_size[i0];
            b_angle2target[i0] = y_size[i0];
          }

          if ((CompMat[0] != b_angle2target[0]) || (CompMat[1] !=
               b_angle2target[1])) {
            emlrtSizeEqCheckNDR2012b(CompMat, b_angle2target, &p_emlrtECI, sp);
          }

          loop_ub = (n + 1) * (b_n + 1);
          for (i0 = 0; i0 < loop_ub; i0++) {
            CompMat_data[i0] = (CompMat_data[i0] || y_data[i0]);
          }

          /*  update Jmin */
          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ye_emlrtBCI, sp);
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &af_emlrtBCI, sp);
          }

          i0 = c_Jmin->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &db_emlrtBCI, sp);
          i0 = c_Jmin->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &cb_emlrtBCI, sp);
          for (i0 = 0; i0 < 2; i0++) {
            CompMat[i0] = CompMat_size[i0];
          }

          i0 = j_Jmin->size[0] * j_Jmin->size[1];
          j_Jmin->size[0] = n + 1;
          j_Jmin->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)j_Jmin, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              j_Jmin->data[i1 + j_Jmin->size[0] * i0] = c_Jmin->data[((((int32_T)
                original_rng_r_data[i1] + c_Jmin->size[0] * ((int32_T)
                original_rng_c_data[i0] - 1)) + c_Jmin->size[0] * c_Jmin->size[1]
                * ii) + c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] *
                ((int32_T)b_tt - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = j_Jmin->size[i0];
          }

          if ((CompMat[0] != Jmin[0]) || (CompMat[1] != Jmin[1])) {
            emlrtSizeEqCheckNDR2012b(CompMat, Jmin, &n_emlrtECI, sp);
          }

          loop_ub = c_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = angle2target->size[0];
            i2 = (int32_T)comp_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &bf_emlrtBCI, sp);
          }

          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = angle2target->size[1];
            i2 = (int32_T)comp_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &cf_emlrtBCI, sp);
          }

          for (i0 = 0; i0 < 2; i0++) {
            CompMat[i0] = CompMat_size[i0];
          }

          i0 = e_angle2target->size[0] * e_angle2target->size[1];
          e_angle2target->size[0] = c_n + 1;
          e_angle2target->size[1] = d_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)e_angle2target, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = c_n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              e_angle2target->data[i1 + e_angle2target->size[0] * i0] =
                angle2target->data[((int32_T)comp_rng_r_data[i1] +
                                    angle2target->size[0] * ((int32_T)
                comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            b_angle2target[i0] = e_angle2target->size[i0];
          }

          if ((CompMat[0] != b_angle2target[0]) || (CompMat[1] !=
               b_angle2target[1])) {
            emlrtSizeEqCheckNDR2012b(CompMat, b_angle2target, &o_emlrtECI, sp);
          }

          i0 = r4->size[0] * r4->size[1];
          r4->size[0] = n + 1;
          r4->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r4, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              r4->data[i1 + r4->size[0] * i0] = (1.0 - (real_T)CompMat_data[i1 +
                (n + 1) * i0]) * c_Jmin->data[((((int32_T)original_rng_r_data[i1]
                + c_Jmin->size[0] * ((int32_T)original_rng_c_data[i0] - 1)) +
                c_Jmin->size[0] * c_Jmin->size[1] * ii) + c_Jmin->size[0] *
                c_Jmin->size[1] * c_Jmin->size[2] * ((int32_T)b_tt - 1)) - 1];
            }
          }

          i0 = r10->size[0] * r10->size[1];
          r10->size[0] = n + 1;
          r10->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r10, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              r10->data[i1 + r10->size[0] * i0] = (real_T)CompMat_data[i1 + (n +
                1) * i0] * angle2target->data[((int32_T)comp_rng_r_data[i1] +
                angle2target->size[0] * ((int32_T)comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            iv0[i0] = r4->size[i0];
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = r10->size[i0];
          }

          if ((iv0[0] != Jmin[0]) || (iv0[1] != Jmin[1])) {
            emlrtSizeEqCheckNDR2012b(iv0, Jmin, &n_emlrtECI, sp);
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i9 = i2;
            } else {
              i9 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &df_emlrtBCI, sp);
            }

            c_tmp_data[i0] = i9 - 1;
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = c_Jmin->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i10 = i2;
            } else {
              i10 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ef_emlrtBCI, sp);
            }

            d_tmp_data[i0] = i10 - 1;
          }

          i0 = c_Jmin->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &bb_emlrtBCI, sp);
          i0 = c_Jmin->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &ab_emlrtBCI, sp);
          iv4[0] = n + 1;
          iv4[1] = b_n + 1;
          emlrtSubAssignSizeCheckR2012b(iv4, 2, *(int32_T (*)[2])r4->size, 2,
            &m_emlrtECI, sp);
          loop_ub = r4->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = r4->size[0];
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              c_Jmin->data[((c_tmp_data[i1] + c_Jmin->size[0] * d_tmp_data[i0])
                            + c_Jmin->size[0] * c_Jmin->size[1] * ii) +
                c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] * ((int32_T)
                b_tt - 1)] = r4->data[i1 + r4->size[0] * i0] + r10->data[i1 +
                r10->size[0] * i0];
            }
          }

          /*  update optimal control */
          y_size[0] = n + 1;
          y_size[1] = b_n + 1;
          loop_ub = (n + 1) * (b_n + 1);
          for (i0 = 0; i0 < loop_ub; i0++) {
            y_data[i0] = !CompMat_data[i0];
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = ccdp_ctrack->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ff_emlrtBCI, sp);
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = ccdp_ctrack->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &gf_emlrtBCI, sp);
          }

          i0 = ccdp_ctrack->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &y_emlrtBCI, sp);
          i0 = ccdp_ctrack->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &x_emlrtBCI, sp);
          for (i0 = 0; i0 < 2; i0++) {
            b_angle2target[i0] = y_size[i0];
          }

          i0 = c_ccdp_ctrack->size[0] * c_ccdp_ctrack->size[1];
          c_ccdp_ctrack->size[0] = n + 1;
          c_ccdp_ctrack->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)c_ccdp_ctrack, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              c_ccdp_ctrack->data[i1 + c_ccdp_ctrack->size[0] * i0] =
                ccdp_ctrack->data[((((int32_T)original_rng_r_data[i1] +
                ccdp_ctrack->size[0] * ((int32_T)original_rng_c_data[i0] - 1)) +
                                    ccdp_ctrack->size[0] * ccdp_ctrack->size[1] *
                                    ii) + ccdp_ctrack->size[0] *
                                   ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
                                   ((int32_T)b_tt - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = c_ccdp_ctrack->size[i0];
          }

          if ((b_angle2target[0] != Jmin[0]) || (b_angle2target[1] != Jmin[1]))
          {
            emlrtSizeEqCheckNDR2012b(b_angle2target, Jmin, &l_emlrtECI, sp);
          }

          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &w_emlrtBCI, sp);
          i0 = r4->size[0] * r4->size[1];
          r4->size[0] = n + 1;
          r4->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r4, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              r4->data[i1 + r4->size[0] * i0] = (real_T)y_data[i1 + (n + 1) * i0]
                * ccdp_ctrack->data[((((int32_T)original_rng_r_data[i1] +
                ccdp_ctrack->size[0] * ((int32_T)original_rng_c_data[i0] - 1)) +
                ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ii) +
                ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size
                [2] * ((int32_T)b_tt - 1)) - 1];
            }
          }

          i0 = r10->size[0] * r10->size[1];
          r10->size[0] = n + 1;
          r10->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r10, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = 1 + jj;
          if ((i1 >= 1) && (i1 < i0)) {
            i11 = i1;
          } else {
            i11 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &hf_emlrtBCI, sp);
          }

          mtmp = nextstate->data[ii].sidxs->data[i11 - 1];
          loop_ub = (n + 1) * (b_n + 1);
          for (i0 = 0; i0 < loop_ub; i0++) {
            r10->data[i0] = (real_T)CompMat_data[i0] * mtmp;
          }

          for (i0 = 0; i0 < 2; i0++) {
            iv0[i0] = r4->size[i0];
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = r10->size[i0];
          }

          if ((iv0[0] != Jmin[0]) || (iv0[1] != Jmin[1])) {
            emlrtSizeEqCheckNDR2012b(iv0, Jmin, &l_emlrtECI, sp);
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = ccdp_ctrack->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i12 = i2;
            } else {
              i12 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &if_emlrtBCI, sp);
            }

            c_tmp_data[i0] = i12 - 1;
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = ccdp_ctrack->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i13 = i2;
            } else {
              i13 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &jf_emlrtBCI, sp);
            }

            d_tmp_data[i0] = i13 - 1;
          }

          i0 = ccdp_ctrack->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &v_emlrtBCI, sp);
          i0 = ccdp_ctrack->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &u_emlrtBCI, sp);
          iv5[0] = n + 1;
          iv5[1] = b_n + 1;
          emlrtSubAssignSizeCheckR2012b(iv5, 2, *(int32_T (*)[2])r4->size, 2,
            &k_emlrtECI, sp);
          loop_ub = r4->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = r4->size[0];
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              ccdp_ctrack->data[((c_tmp_data[i1] + ccdp_ctrack->size[0] *
                                  d_tmp_data[i0]) + ccdp_ctrack->size[0] *
                                 ccdp_ctrack->size[1] * ii) + ccdp_ctrack->size
                [0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] * ((int32_T)
                b_tt - 1)] = r4->data[i1 + r4->size[0] * i0] + r10->data[i1 +
                r10->size[0] * i0];
            }
          }

          y_size[0] = n + 1;
          y_size[1] = b_n + 1;
          loop_ub = (n + 1) * (b_n + 1);
          for (i0 = 0; i0 < loop_ub; i0++) {
            y_data[i0] = !CompMat_data[i0];
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_col->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &kf_emlrtBCI, sp);
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_col->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &lf_emlrtBCI, sp);
          }

          i0 = Optctrl_col->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &t_emlrtBCI, sp);
          i0 = Optctrl_col->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &s_emlrtBCI, sp);
          for (i0 = 0; i0 < 2; i0++) {
            b_angle2target[i0] = y_size[i0];
          }

          i0 = b_Optctrl_col->size[0] * b_Optctrl_col->size[1];
          b_Optctrl_col->size[0] = n + 1;
          b_Optctrl_col->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_Optctrl_col, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              b_Optctrl_col->data[i1 + b_Optctrl_col->size[0] * i0] =
                Optctrl_col->data[((((int32_T)original_rng_r_data[i1] +
                Optctrl_col->size[0] * ((int32_T)original_rng_c_data[i0] - 1)) +
                                    Optctrl_col->size[0] * Optctrl_col->size[1] *
                                    ii) + Optctrl_col->size[0] *
                                   Optctrl_col->size[1] * Optctrl_col->size[2] *
                                   ((int32_T)b_tt - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = b_Optctrl_col->size[i0];
          }

          if ((b_angle2target[0] != Jmin[0]) || (b_angle2target[1] != Jmin[1]))
          {
            emlrtSizeEqCheckNDR2012b(b_angle2target, Jmin, &j_emlrtECI, sp);
          }

          i0 = nextstate->size[1];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &r_emlrtBCI, sp);
          i0 = r4->size[0] * r4->size[1];
          r4->size[0] = n + 1;
          r4->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r4, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              r4->data[i1 + r4->size[0] * i0] = (real_T)y_data[i1 + (n + 1) * i0]
                * Optctrl_col->data[((((int32_T)original_rng_r_data[i1] +
                Optctrl_col->size[0] * ((int32_T)original_rng_c_data[i0] - 1)) +
                Optctrl_col->size[0] * Optctrl_col->size[1] * ii) +
                Optctrl_col->size[0] * Optctrl_col->size[1] * Optctrl_col->size
                [2] * ((int32_T)b_tt - 1)) - 1];
            }
          }

          i0 = r10->size[0] * r10->size[1];
          r10->size[0] = n + 1;
          r10->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r10, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          i0 = nextstate->data[ii].sidxs->size[0];
          i1 = 1 + jj;
          if ((i1 >= 1) && (i1 < i0)) {
            i14 = i1;
          } else {
            i14 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &mf_emlrtBCI, sp);
          }

          mtmp = nextstate->data[ii].sidxs->data[(i14 + nextstate->data[ii].
            sidxs->size[0]) - 1];
          loop_ub = (n + 1) * (b_n + 1);
          for (i0 = 0; i0 < loop_ub; i0++) {
            r10->data[i0] = (real_T)CompMat_data[i0] * mtmp;
          }

          for (i0 = 0; i0 < 2; i0++) {
            iv0[i0] = r4->size[i0];
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = r10->size[i0];
          }

          if ((iv0[0] != Jmin[0]) || (iv0[1] != Jmin[1])) {
            emlrtSizeEqCheckNDR2012b(iv0, Jmin, &j_emlrtECI, sp);
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_col->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i15 = i2;
            } else {
              i15 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &nf_emlrtBCI, sp);
            }

            c_tmp_data[i0] = i15 - 1;
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_col->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i16 = i2;
            } else {
              i16 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &of_emlrtBCI, sp);
            }

            d_tmp_data[i0] = i16 - 1;
          }

          i0 = Optctrl_col->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &q_emlrtBCI, sp);
          i0 = Optctrl_col->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &p_emlrtBCI, sp);
          iv6[0] = n + 1;
          iv6[1] = b_n + 1;
          emlrtSubAssignSizeCheckR2012b(iv6, 2, *(int32_T (*)[2])r4->size, 2,
            &i_emlrtECI, sp);
          loop_ub = r4->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = r4->size[0];
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              Optctrl_col->data[((c_tmp_data[i1] + Optctrl_col->size[0] *
                                  d_tmp_data[i0]) + Optctrl_col->size[0] *
                                 Optctrl_col->size[1] * ii) + Optctrl_col->size
                [0] * Optctrl_col->size[1] * Optctrl_col->size[2] * ((int32_T)
                b_tt - 1)] = r4->data[i1 + r4->size[0] * i0] + r10->data[i1 +
                r10->size[0] * i0];
            }
          }

          y_size[0] = n + 1;
          y_size[1] = b_n + 1;
          loop_ub = (n + 1) * (b_n + 1);
          for (i0 = 0; i0 < loop_ub; i0++) {
            y_data[i0] = !CompMat_data[i0];
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_dirs->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &pf_emlrtBCI, sp);
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_dirs->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &qf_emlrtBCI, sp);
          }

          i0 = Optctrl_dirs->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &o_emlrtBCI, sp);
          i0 = Optctrl_dirs->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &n_emlrtBCI, sp);
          for (i0 = 0; i0 < 2; i0++) {
            b_angle2target[i0] = y_size[i0];
          }

          i0 = c_Optctrl_dirs->size[0] * c_Optctrl_dirs->size[1];
          c_Optctrl_dirs->size[0] = n + 1;
          c_Optctrl_dirs->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)c_Optctrl_dirs, i0, (int32_T)
                            sizeof(real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              c_Optctrl_dirs->data[i1 + c_Optctrl_dirs->size[0] * i0] =
                Optctrl_dirs->data[((((int32_T)original_rng_r_data[i1] +
                Optctrl_dirs->size[0] * ((int32_T)original_rng_c_data[i0] - 1))
                + Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * ii) +
                                    Optctrl_dirs->size[0] * Optctrl_dirs->size[1]
                                    * Optctrl_dirs->size[2] * ((int32_T)b_tt - 1))
                - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = c_Optctrl_dirs->size[i0];
          }

          if ((b_angle2target[0] != Jmin[0]) || (b_angle2target[1] != Jmin[1]))
          {
            emlrtSizeEqCheckNDR2012b(b_angle2target, Jmin, &g_emlrtECI, sp);
          }

          loop_ub = c_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = cvistmp->size[0];
            i2 = (int32_T)comp_rng_r_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &rf_emlrtBCI, sp);
          }

          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = cvistmp->size[1];
            i2 = (int32_T)comp_rng_c_data[i0];
            emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &sf_emlrtBCI, sp);
          }

          for (i0 = 0; i0 < 2; i0++) {
            CompMat[i0] = CompMat_size[i0];
          }

          i0 = b_cvistmp->size[0] * b_cvistmp->size[1];
          b_cvistmp->size[0] = c_n + 1;
          b_cvistmp->size[1] = d_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)b_cvistmp, i0, (int32_T)
                            sizeof(int32_T), &emlrtRTEI);
          loop_ub = d_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = c_n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              b_cvistmp->data[i1 + b_cvistmp->size[0] * i0] = (int32_T)
                cvistmp->data[((int32_T)comp_rng_r_data[i1] + cvistmp->size[0] *
                               ((int32_T)comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = b_cvistmp->size[i0];
          }

          if ((CompMat[0] != Jmin[0]) || (CompMat[1] != Jmin[1])) {
            emlrtSizeEqCheckNDR2012b(CompMat, Jmin, &h_emlrtECI, sp);
          }

          i0 = r4->size[0] * r4->size[1];
          r4->size[0] = n + 1;
          r4->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r4, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              r4->data[i1 + r4->size[0] * i0] = (real_T)y_data[i1 + (n + 1) * i0]
                * Optctrl_dirs->data[((((int32_T)original_rng_r_data[i1] +
                Optctrl_dirs->size[0] * ((int32_T)original_rng_c_data[i0] - 1))
                + Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * ii) +
                Optctrl_dirs->size[0] * Optctrl_dirs->size[1] *
                Optctrl_dirs->size[2] * ((int32_T)b_tt - 1)) - 1];
            }
          }

          i0 = r10->size[0] * r10->size[1];
          r10->size[0] = n + 1;
          r10->size[1] = b_n + 1;
          emxEnsureCapacity(sp, (emxArray__common *)r10, i0, (int32_T)sizeof
                            (real_T), &emlrtRTEI);
          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = n + 1;
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              r10->data[i1 + r10->size[0] * i0] = (real_T)CompMat_data[i1 + (n +
                1) * i0] * mindiridx->data[((int32_T)comp_rng_r_data[i1] +
                mindiridx->size[0] * ((int32_T)comp_rng_c_data[i0] - 1)) - 1];
            }
          }

          for (i0 = 0; i0 < 2; i0++) {
            iv0[i0] = r4->size[i0];
          }

          for (i0 = 0; i0 < 2; i0++) {
            Jmin[i0] = r10->size[i0];
          }

          if ((iv0[0] != Jmin[0]) || (iv0[1] != Jmin[1])) {
            emlrtSizeEqCheckNDR2012b(iv0, Jmin, &g_emlrtECI, sp);
          }

          loop_ub = n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_dirs->size[0];
            i2 = (int32_T)original_rng_r_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i17 = i2;
            } else {
              i17 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &tf_emlrtBCI, sp);
            }

            c_tmp_data[i0] = i17 - 1;
          }

          loop_ub = b_n + 1;
          for (i0 = 0; i0 < loop_ub; i0++) {
            i1 = Optctrl_dirs->size[1];
            i2 = (int32_T)original_rng_c_data[i0];
            if ((i2 >= 1) && (i2 < i1)) {
              i18 = i2;
            } else {
              i18 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &uf_emlrtBCI, sp);
            }

            d_tmp_data[i0] = i18 - 1;
          }

          i0 = Optctrl_dirs->size[2];
          i1 = ii + 1;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &m_emlrtBCI, sp);
          i0 = Optctrl_dirs->size[3];
          i1 = (int32_T)b_tt;
          emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &l_emlrtBCI, sp);
          iv7[0] = n + 1;
          iv7[1] = b_n + 1;
          emlrtSubAssignSizeCheckR2012b(iv7, 2, *(int32_T (*)[2])r4->size, 2,
            &f_emlrtECI, sp);
          loop_ub = r4->size[1];
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_loop_ub = r4->size[0];
            for (i1 = 0; i1 < d_loop_ub; i1++) {
              Optctrl_dirs->data[((c_tmp_data[i1] + Optctrl_dirs->size[0] *
                                   d_tmp_data[i0]) + Optctrl_dirs->size[0] *
                                  Optctrl_dirs->size[1] * ii) +
                Optctrl_dirs->size[0] * Optctrl_dirs->size[1] *
                Optctrl_dirs->size[2] * ((int32_T)b_tt - 1)] = r4->data[i1 +
                r4->size[0] * i0] + r10->data[i1 + r10->size[0] * i0];
            }
          }

          jj++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }

        ii++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      /* Jmin(tt).Jmin=Jmin(tt).Jmin + Lk; */
      i0 = c_Jmin->size[3];
      i1 = (int32_T)b_tt;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &k_emlrtBCI, sp);
      loop_ub = c_Jmin->size[0];
      d_loop_ub = c_Jmin->size[1];
      b_loop_ub = c_Jmin->size[2];
      i0 = e_Jmin->size[0] * e_Jmin->size[1] * e_Jmin->size[2];
      e_Jmin->size[0] = loop_ub;
      e_Jmin->size[1] = d_loop_ub;
      e_Jmin->size[2] = b_loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)e_Jmin, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            e_Jmin->data[(i2 + e_Jmin->size[0] * i1) + e_Jmin->size[0] *
              e_Jmin->size[1] * i0] = c_Jmin->data[((i2 + c_Jmin->size[0] * i1)
              + c_Jmin->size[0] * c_Jmin->size[1] * i0) + c_Jmin->size[0] *
              c_Jmin->size[1] * c_Jmin->size[2] * ((int32_T)b_tt - 1)];
          }
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_Jmin[i0] = e_Jmin->size[i0];
      }

      for (i0 = 0; i0 < 3; i0++) {
        c_ccdp_cavoid[i0] = ccdp_cavoid->size[i0];
      }

      emlrtSizeEqCheckNDR2012b(b_Jmin, c_ccdp_cavoid, &e_emlrtECI, sp);
      loop_ub = c_Jmin->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        c_tmp_data[i0] = i0;
      }

      d_loop_ub = c_Jmin->size[1];
      for (i0 = 0; i0 < d_loop_ub; i0++) {
        d_tmp_data[i0] = i0;
      }

      b_loop_ub = c_Jmin->size[2];
      i0 = r2->size[0];
      r2->size[0] = b_loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)r2, i0, (int32_T)sizeof(int32_T),
                        &emlrtRTEI);
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        r2->data[i0] = i0;
      }

      i0 = c_Jmin->size[3];
      i1 = (int32_T)b_tt;
      emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &j_emlrtBCI, sp);
      iv8[0] = loop_ub;
      iv8[1] = d_loop_ub;
      iv8[2] = r2->size[0];
      loop_ub = c_Jmin->size[0];
      d_loop_ub = c_Jmin->size[1];
      b_loop_ub = c_Jmin->size[2];
      i0 = f_Jmin->size[0] * f_Jmin->size[1] * f_Jmin->size[2];
      f_Jmin->size[0] = loop_ub;
      f_Jmin->size[1] = d_loop_ub;
      f_Jmin->size[2] = b_loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)f_Jmin, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < b_loop_ub; i0++) {
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          for (i2 = 0; i2 < loop_ub; i2++) {
            f_Jmin->data[(i2 + f_Jmin->size[0] * i1) + f_Jmin->size[0] *
              f_Jmin->size[1] * i0] = c_Jmin->data[((i2 + c_Jmin->size[0] * i1)
              + c_Jmin->size[0] * c_Jmin->size[1] * i0) + c_Jmin->size[0] *
              c_Jmin->size[1] * c_Jmin->size[2] * ((int32_T)b_tt - 1)];
          }
        }
      }

      for (i0 = 0; i0 < 3; i0++) {
        b_Jmin[i0] = f_Jmin->size[i0];
      }

      emlrtSubAssignSizeCheckR2012b(iv8, 3, b_Jmin, 3, &d_emlrtECI, sp);
      nm1d2 = c_Jmin->size[0];
      ixstart = c_Jmin->size[1];
      c_loop_ub = c_Jmin->size[2];
      i0 = g_Jmin->size[0] * g_Jmin->size[1] * g_Jmin->size[2];
      g_Jmin->size[0] = nm1d2;
      g_Jmin->size[1] = ixstart;
      g_Jmin->size[2] = c_loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)g_Jmin, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < c_loop_ub; i0++) {
        for (i1 = 0; i1 < ixstart; i1++) {
          for (i2 = 0; i2 < nm1d2; i2++) {
            g_Jmin->data[(i2 + g_Jmin->size[0] * i1) + g_Jmin->size[0] *
              g_Jmin->size[1] * i0] = c_Jmin->data[((i2 + c_Jmin->size[0] * i1)
              + c_Jmin->size[0] * c_Jmin->size[1] * i0) + c_Jmin->size[0] *
              c_Jmin->size[1] * c_Jmin->size[2] * ((int32_T)b_tt - 1)] +
              ccdp_cavoid->data[(i2 + ccdp_cavoid->size[0] * i1) +
              ccdp_cavoid->size[0] * ccdp_cavoid->size[1] * i0];
          }
        }
      }

      loop_ub = g_Jmin->size[2];
      for (i0 = 0; i0 < loop_ub; i0++) {
        d_loop_ub = g_Jmin->size[1];
        for (i1 = 0; i1 < d_loop_ub; i1++) {
          b_loop_ub = g_Jmin->size[0];
          for (i2 = 0; i2 < b_loop_ub; i2++) {
            c_Jmin->data[((c_tmp_data[i2] + c_Jmin->size[0] * d_tmp_data[i1]) +
                          c_Jmin->size[0] * c_Jmin->size[1] * r2->data[i0]) +
              c_Jmin->size[0] * c_Jmin->size[1] * c_Jmin->size[2] * ((int32_T)
              b_tt - 1)] = g_Jmin->data[(i2 + g_Jmin->size[0] * i1) +
              g_Jmin->size[0] * g_Jmin->size[1] * i0];
          }
        }
      }

      tt++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    /*  -- [ Find the optimal control ] -- % */
    i0 = b_currs_idx->size[0] * b_currs_idx->size[1];
    b_currs_idx->size[0] = 3;
    b_currs_idx->size[1] = (int32_T)(H + 1.0);
    emxEnsureCapacity(sp, (emxArray__common *)b_currs_idx, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = 3 * (int32_T)(H + 1.0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_currs_idx->data[i0] = 0.0;
    }

    i0 = ccdp->ys->size[0] * ccdp->ys->size[1];
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &i_emlrtBCI, sp);
    i0 = ccdp->xs->size[0] * ccdp->xs->size[1];
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &h_emlrtBCI, sp);
    b_pS[0] = pS[1] - ccdp->ys->data[0];
    b_pS[1] = pS[0] - ccdp->xs->data[0];
    for (i0 = 0; i0 < 2; i0++) {
      currs_idx[i0] = b_pS[i0] / ccdp->glen;
    }

    c_round(currs_idx);
    for (i0 = 0; i0 < 2; i0++) {
      b_currs_idx->data[i0] = currs_idx[i0] + 1.0;
    }

    b_currs_idx->data[2] = b_mod(muDoubleScalarRound(pS[2] / 2.0 /
      3.1415926535897931 * ndir), ndir) + 1.0;
    const_val = 0.0;

    /*  number of violations of constraints */
    i0 = optidx->size[0] * optidx->size[1];
    optidx->size[0] = 3;
    optidx->size[1] = (int32_T)H;
    emxEnsureCapacity(sp, (emxArray__common *)optidx, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = 3 * (int32_T)H;
    for (i0 = 0; i0 < loop_ub; i0++) {
      optidx->data[i0] = 0.0;
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, H, mxDOUBLE_CLASS, (int32_T)H,
      &cb_emlrtRTEI, sp);
    tt = 1;
    while (tt - 1 <= (int32_T)H - 1) {
      nm1d2 = optidx->size[1];
      emlrtDynamicBoundsCheckR2012b(tt, 1, nm1d2, &f_emlrtBCI, sp);
      i0 = ccdp_ctrack->size[0];
      i1 = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < i1)) {
        c_tt = tt;
      } else {
        c_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, i1, &gd_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[b_currs_idx->size[0] * (c_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i1 = (int32_T)b_ccdp;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &m_emlrtDCI, sp);
      }

      i2 = ccdp_ctrack->size[1];
      i5 = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < i5)) {
        d_tt = tt;
      } else {
        d_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, i5, &id_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[1 + b_currs_idx->size[0] * (d_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i5 = (int32_T)b_ccdp;
      } else {
        i5 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &n_emlrtDCI, sp);
      }

      c_loop_ub = ccdp_ctrack->size[2];
      b_loop_ub = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < b_loop_ub)) {
        e_tt = tt;
      } else {
        e_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, b_loop_ub, &kd_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[2 + b_currs_idx->size[0] * (e_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        b_loop_ub = (int32_T)b_ccdp;
      } else {
        b_loop_ub = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &o_emlrtDCI, sp);
      }

      nm1d2 = ccdp_ctrack->size[3];
      if ((i1 >= 1) && (i1 < i0)) {
        i19 = i1;
      } else {
        i19 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &fd_emlrtBCI, sp);
      }

      if ((i5 >= 1) && (i5 < i2)) {
        i20 = i5;
      } else {
        i20 = emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &hd_emlrtBCI, sp);
      }

      if ((b_loop_ub >= 1) && (b_loop_ub < c_loop_ub)) {
        g_loop_ub = b_loop_ub;
      } else {
        g_loop_ub = emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, c_loop_ub,
          &jd_emlrtBCI, sp);
      }

      if ((tt >= 1) && (tt < nm1d2)) {
        f_tt = tt;
      } else {
        f_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, nm1d2, &ld_emlrtBCI, sp);
      }

      d_ccdp_ctrack[0] = ccdp_ctrack->data[(((i19 + ccdp_ctrack->size[0] * (i20
        - 1)) + ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * (g_loop_ub - 1)) +
        ccdp_ctrack->size[0] * ccdp_ctrack->size[1] * ccdp_ctrack->size[2] *
        (f_tt - 1)) - 1];
      i0 = Optctrl_col->size[0];
      i1 = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < i1)) {
        g_tt = tt;
      } else {
        g_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, i1, &nd_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[b_currs_idx->size[0] * (g_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i1 = (int32_T)b_ccdp;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &p_emlrtDCI, sp);
      }

      i2 = Optctrl_col->size[1];
      i5 = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < i5)) {
        h_tt = tt;
      } else {
        h_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, i5, &pd_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[1 + b_currs_idx->size[0] * (h_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i5 = (int32_T)b_ccdp;
      } else {
        i5 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &q_emlrtDCI, sp);
      }

      c_loop_ub = Optctrl_col->size[2];
      b_loop_ub = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < b_loop_ub)) {
        i_tt = tt;
      } else {
        i_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, b_loop_ub, &rd_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[2 + b_currs_idx->size[0] * (i_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        b_loop_ub = (int32_T)b_ccdp;
      } else {
        b_loop_ub = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &r_emlrtDCI, sp);
      }

      nm1d2 = Optctrl_col->size[3];
      if ((i1 >= 1) && (i1 < i0)) {
        i21 = i1;
      } else {
        i21 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &md_emlrtBCI, sp);
      }

      if ((i5 >= 1) && (i5 < i2)) {
        i22 = i5;
      } else {
        i22 = emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &od_emlrtBCI, sp);
      }

      if ((b_loop_ub >= 1) && (b_loop_ub < c_loop_ub)) {
        h_loop_ub = b_loop_ub;
      } else {
        h_loop_ub = emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, c_loop_ub,
          &qd_emlrtBCI, sp);
      }

      if ((tt >= 1) && (tt < nm1d2)) {
        j_tt = tt;
      } else {
        j_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, nm1d2, &sd_emlrtBCI, sp);
      }

      d_ccdp_ctrack[1] = Optctrl_col->data[(((i21 + Optctrl_col->size[0] * (i22
        - 1)) + Optctrl_col->size[0] * Optctrl_col->size[1] * (h_loop_ub - 1)) +
        Optctrl_col->size[0] * Optctrl_col->size[1] * Optctrl_col->size[2] *
        (j_tt - 1)) - 1];
      i0 = Optctrl_dirs->size[0];
      i1 = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < i1)) {
        k_tt = tt;
      } else {
        k_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, i1, &ud_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[b_currs_idx->size[0] * (k_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i1 = (int32_T)b_ccdp;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &s_emlrtDCI, sp);
      }

      i2 = Optctrl_dirs->size[1];
      i5 = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < i5)) {
        l_tt = tt;
      } else {
        l_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, i5, &wd_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[1 + b_currs_idx->size[0] * (l_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i5 = (int32_T)b_ccdp;
      } else {
        i5 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &t_emlrtDCI, sp);
      }

      c_loop_ub = Optctrl_dirs->size[2];
      b_loop_ub = b_currs_idx->size[1];
      if ((tt >= 1) && (tt < b_loop_ub)) {
        m_tt = tt;
      } else {
        m_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, b_loop_ub, &yd_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[2 + b_currs_idx->size[0] * (m_tt - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        b_loop_ub = (int32_T)b_ccdp;
      } else {
        b_loop_ub = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &u_emlrtDCI, sp);
      }

      nm1d2 = Optctrl_dirs->size[3];
      if ((i1 >= 1) && (i1 < i0)) {
        i23 = i1;
      } else {
        i23 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &td_emlrtBCI, sp);
      }

      if ((i5 >= 1) && (i5 < i2)) {
        i24 = i5;
      } else {
        i24 = emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &vd_emlrtBCI, sp);
      }

      if ((b_loop_ub >= 1) && (b_loop_ub < c_loop_ub)) {
        i_loop_ub = b_loop_ub;
      } else {
        i_loop_ub = emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, c_loop_ub,
          &xd_emlrtBCI, sp);
      }

      if ((tt >= 1) && (tt < nm1d2)) {
        n_tt = tt;
      } else {
        n_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, nm1d2, &ae_emlrtBCI, sp);
      }

      d_ccdp_ctrack[2] = Optctrl_dirs->data[(((i23 + Optctrl_dirs->size[0] *
        (i24 - 1)) + Optctrl_dirs->size[0] * Optctrl_dirs->size[1] * (i_loop_ub
        - 1)) + Optctrl_dirs->size[0] * Optctrl_dirs->size[1] *
        Optctrl_dirs->size[2] * (n_tt - 1)) - 1];
      for (i0 = 0; i0 < 3; i0++) {
        optidx->data[i0 + optidx->size[0] * (tt - 1)] = d_ccdp_ctrack[i0];
      }

      nm1d2 = b_currs_idx->size[1];
      i0 = (int32_T)((1.0 + (real_T)(tt - 1)) + 1.0);
      emlrtDynamicBoundsCheckR2012b(i0, 1, nm1d2, &d_emlrtBCI, sp);
      nm1d2 = b_currs_idx->size[1];
      emlrtDynamicBoundsCheckR2012b(tt, 1, nm1d2, &g_emlrtBCI, sp);
      i0 = optidx->size[1];
      if ((tt >= 1) && (tt < i0)) {
        ixstart = tt;
      } else {
        ixstart = emlrtDynamicBoundsCheckR2012b(tt, 1, i0, &e_emlrtBCI, sp);
      }

      for (i0 = 0; i0 < 2; i0++) {
        currs_idx[i0] = b_currs_idx->data[i0 + b_currs_idx->size[0] * (tt - 1)]
          + optidx->data[i0 + optidx->size[0] * (ixstart - 1)];
      }

      for (i0 = 0; i0 < 2; i0++) {
        b_currs_idx->data[i0 + b_currs_idx->size[0] * ((int32_T)((1.0 + (real_T)
          (tt - 1)) + 1.0) - 1)] = currs_idx[i0];
      }

      i0 = b_currs_idx->size[1];
      i1 = (int32_T)((1.0 + (real_T)(tt - 1)) + 1.0);
      i2 = optidx->size[1];
      if ((i1 >= 1) && (i1 < i0)) {
        i25 = i1;
      } else {
        i25 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &be_emlrtBCI, sp);
      }

      if ((tt >= 1) && (tt < i2)) {
        o_tt = tt;
      } else {
        o_tt = emlrtDynamicBoundsCheckR2012b(tt, 1, i2, &ce_emlrtBCI, sp);
      }

      b_currs_idx->data[2 + b_currs_idx->size[0] * (i25 - 1)] = optidx->data[2 +
        optidx->size[0] * (o_tt - 1)];
      i0 = ccdp_cconst->size[0];
      i1 = b_currs_idx->size[1];
      i2 = (int32_T)((1.0 + (real_T)(tt - 1)) + 1.0);
      if ((i2 >= 1) && (i2 < i1)) {
        i26 = i2;
      } else {
        i26 = emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ee_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[b_currs_idx->size[0] * (i26 - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i1 = (int32_T)b_ccdp;
      } else {
        i1 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &v_emlrtDCI, sp);
      }

      i2 = ccdp_cconst->size[1];
      i5 = b_currs_idx->size[1];
      c_loop_ub = (int32_T)((1.0 + (real_T)(tt - 1)) + 1.0);
      if ((c_loop_ub >= 1) && (c_loop_ub < i5)) {
        j_loop_ub = c_loop_ub;
      } else {
        j_loop_ub = emlrtDynamicBoundsCheckR2012b(c_loop_ub, 1, i5, &ge_emlrtBCI,
          sp);
      }

      b_ccdp = b_currs_idx->data[1 + b_currs_idx->size[0] * (j_loop_ub - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        i5 = (int32_T)b_ccdp;
      } else {
        i5 = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &w_emlrtDCI, sp);
      }

      c_loop_ub = ccdp_cconst->size[2];
      b_loop_ub = b_currs_idx->size[1];
      nm1d2 = (int32_T)((1.0 + (real_T)(tt - 1)) + 1.0);
      if ((nm1d2 >= 1) && (nm1d2 < b_loop_ub)) {
        b_nm1d2 = nm1d2;
      } else {
        b_nm1d2 = emlrtDynamicBoundsCheckR2012b(nm1d2, 1, b_loop_ub,
          &ie_emlrtBCI, sp);
      }

      b_ccdp = b_currs_idx->data[2 + b_currs_idx->size[0] * (b_nm1d2 - 1)];
      if (b_ccdp == (int32_T)muDoubleScalarFloor(b_ccdp)) {
        b_loop_ub = (int32_T)b_ccdp;
      } else {
        b_loop_ub = (int32_T)emlrtIntegerCheckR2012b(b_ccdp, &x_emlrtDCI, sp);
      }

      nm1d2 = ccdp_cconst->size[3];
      ixstart = (int32_T)((1.0 + (real_T)(tt - 1)) + 1.0);
      if ((i1 >= 1) && (i1 < i0)) {
        i27 = i1;
      } else {
        i27 = emlrtDynamicBoundsCheckR2012b(i1, 1, i0, &de_emlrtBCI, sp);
      }

      if ((i5 >= 1) && (i5 < i2)) {
        i28 = i5;
      } else {
        i28 = emlrtDynamicBoundsCheckR2012b(i5, 1, i2, &fe_emlrtBCI, sp);
      }

      if ((b_loop_ub >= 1) && (b_loop_ub < c_loop_ub)) {
        k_loop_ub = b_loop_ub;
      } else {
        k_loop_ub = emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, c_loop_ub,
          &he_emlrtBCI, sp);
      }

      if ((ixstart >= 1) && (ixstart < nm1d2)) {
        b_ixstart = ixstart;
      } else {
        b_ixstart = emlrtDynamicBoundsCheckR2012b(ixstart, 1, nm1d2,
          &je_emlrtBCI, sp);
      }

      const_val += ccdp_cconst->data[(((i27 + ccdp_cconst->size[0] * (i28 - 1))
        + ccdp_cconst->size[0] * ccdp_cconst->size[1] * (k_loop_ub - 1)) +
        ccdp_cconst->size[0] * ccdp_cconst->size[1] * ccdp_cconst->size[2] *
        (b_ixstart - 1)) - 1];
      tt++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i0 = predict_s->size[0] * predict_s->size[1];
    predict_s->size[0] = 3;
    predict_s->size[1] = (int32_T)(H + 1.0);
    emxEnsureCapacity(sp, (emxArray__common *)predict_s, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = 3 * (int32_T)(H + 1.0);
    for (i0 = 0; i0 < loop_ub; i0++) {
      predict_s->data[i0] = 0.0;
    }

    loop_ub = b_currs_idx->size[1];
    i0 = r11->size[0] * r11->size[1];
    r11->size[0] = 1;
    r11->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r11, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r11->data[r11->size[0] * i0] = (b_currs_idx->data[1 + b_currs_idx->size[0]
        * i0] - 1.0) * ccdp->glen;
    }

    loop_ub = b_currs_idx->size[1];
    i0 = r12->size[0] * r12->size[1];
    r12->size[0] = 1;
    r12->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r12, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r12->data[r12->size[0] * i0] = (b_currs_idx->data[b_currs_idx->size[0] *
        i0] - 1.0) * ccdp->glen;
    }

    i0 = r11->size[1];
    i1 = r12->size[1];
    if (i0 != i1) {
      emlrtDimSizeEqCheckR2012b(i0, i1, &c_emlrtECI, sp);
    }

    loop_ub = (int32_T)(H + 1.0);
    i0 = r2->size[0];
    r2->size[0] = (int32_T)(H + 1.0);
    emxEnsureCapacity(sp, (emxArray__common *)r2, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r2->data[i0] = i0;
    }

    i0 = ccdp->xs->size[0] * ccdp->xs->size[1];
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &c_emlrtBCI, sp);
    i0 = ccdp->ys->size[0] * ccdp->ys->size[1];
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, &b_emlrtBCI, sp);
    mtmp = ccdp->xs->data[0];
    b_ccdp = ccdp->ys->data[0];
    i0 = r13->size[0] * r13->size[1];
    r13->size[0] = 2;
    r13->size[1] = r11->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r13, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = r11->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      r13->data[r13->size[0] * i0] = r11->data[r11->size[0] * i0] + mtmp;
    }

    loop_ub = r12->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      r13->data[1 + r13->size[0] * i0] = r12->data[r12->size[0] * i0] + b_ccdp;
    }

    iv9[0] = 2;
    iv9[1] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv9, 2, *(int32_T (*)[2])r13->size, 2,
      &b_emlrtECI, sp);
    loop_ub = r13->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      for (i1 = 0; i1 < 2; i1++) {
        predict_s->data[i1 + predict_s->size[0] * r2->data[i0]] = r13->data[i1 +
          r13->size[0] * i0];
      }
    }

    loop_ub = predict_s->size[1];
    i0 = r2->size[0];
    r2->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r2, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r2->data[i0] = i0;
    }

    loop_ub = b_currs_idx->size[1];
    i0 = r11->size[0] * r11->size[1];
    r11->size[0] = 1;
    r11->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r11, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r11->data[r11->size[0] * i0] = (b_currs_idx->data[2 + b_currs_idx->size[0]
        * i0] - 1.0) * 2.0 * 3.1415926535897931 / ndir;
    }

    iv10[0] = 1;
    iv10[1] = r2->size[0];
    emlrtSubAssignSizeCheckR2012b(iv10, 2, *(int32_T (*)[2])r11->size, 2,
      &emlrtECI, sp);
    loop_ub = r11->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      predict_s->data[2 + predict_s->size[0] * r2->data[i0]] = r11->data
        [r11->size[0] * i0];
    }

    /*  though we doesn't consider constraints, the optimal solution */
    /*  satisfies constraints */
    if ((const_val <= 0.0) && (ilagran == 1)) {
      /* fprintf('feasible\n '); */
      exitg1 = true;
    } else {
      if (ilagran == 1) {
        lag_feas = 0;
        lagcoeff = 1.0;
      }

      /*  check feasibility */
      if ((ilagran == 2) && (const_val > 0.0)) {
        st.site = &o_emlrtRSI;
        b_fprintf(&st);
        i0 = predict_s->size[0] * predict_s->size[1];
        predict_s->size[0] = 3;
        emxEnsureCapacity(sp, (emxArray__common *)predict_s, i0, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
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
            /*  violate constraints */
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
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(sp);
          }
        }
      }
    }
  }

  emxFree_int32_T(&b_cvistmp);
  emxFree_real_T(&c_Optctrl_dirs);
  emxFree_real_T(&b_Optctrl_col);
  emxFree_real_T(&c_ccdp_ctrack);
  emxFree_real_T(&e_angle2target);
  emxFree_real_T(&j_Jmin);
  emxFree_real_T(&d_angle2target);
  emxFree_real_T(&i_Jmin);
  emxFree_real_T(&c_angle2target);
  emxFree_real_T(&h_Jmin);
  emxFree_real_T(&g_Jmin);
  emxFree_real_T(&f_Jmin);
  emxFree_real_T(&e_Jmin);
  emxFree_real_T(&b_Optctrl_dirs);
  emxFree_real_T(&b_mindiridx);
  emxFree_real_T(&d_Jmin);
  emxFree_real_T(&c_lag_feas);
  emxFree_real_T(&c_lagcoeff);
  emxFree_real_T(&b_lag_feas);
  emxFree_real_T(&b_lagcoeff);
  emxFree_int32_T(&iindx);
  emxFree_real_T(&r13);
  emxFree_real_T(&r12);
  emxFree_real_T(&r11);
  emxFree_real_T(&r10);
  emxFree_real_T(&r4);
  emxFree_real_T(&r3);
  emxFree_int32_T(&r2);
  emxFree_real_T(&optidx);
  emxFree_real_T(&b_currs_idx);
  emxFree_real_T(&mindiridx);
  emxFree_real_T(&c_Jmin);
  emxFree_real_T(&Optctrl_dirs);
  emxFree_real_T(&Optctrl_col);
  emxFree_real_T(&cvistmp);
  emxFree_real_T(&angle2target);
  emxFree_real_T(&ccdp_cconst);
  emxFree_real_T(&ccdp_cavoid);
  emxFree_real_T(&ccdp_cvis);
  emxFree_real_T(&ccdp_ctrack);

  /* fprintf('the number of iterations: %d,  coeff: %.3e\n',ilagran,lagcoeff); */
  /*  wrong, initial state is not same as predict_s(:,1) */
  i0 = predict_s->size[1];
  emlrtDynamicBoundsCheckR2012b(2, 1, i0, &emlrtBCI, sp);
  for (i0 = 0; i0 < 3; i0++) {
    movement[i0] = predict_s->data[i0 + predict_s->size[0]] - pS[i0];
  }

  *uv_opt = norm(*(real_T (*)[2])&movement[0]) / T;
  *uw_opt = movement[2] / T;
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (fcn_track_ccdp_fast.c) */
