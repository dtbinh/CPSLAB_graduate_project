//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mean.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "mean.h"
#include <stdio.h>

// Function Definitions

//
// Arguments    : const double x[2]
// Return Type  : double
//
double mean(const double x[2])
{
  return (x[0] + x[1]) / 2.0;
}

//
// File trailer for mean.cpp
//
// [EOF]
//
