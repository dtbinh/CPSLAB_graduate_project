//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 2.8
// C/C++ source code generated on  : 21-Jul-2016 17:02:06
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "fcn_track_ccdp_fast.h"
#include "main.h"
#include "fcn_track_ccdp_fast_terminate.h"
#include "fcn_track_ccdp_fast_emxAPI.h"
#include "fcn_track_ccdp_fast_initialize.h"
#include <stdio.h>

// Function Declarations
static emxArray_real_T *argInit_1xUnbounded_real_T();
static emxArray_struct0_T *argInit_1xUnbounded_struct0_T();
static emxArray_struct4_T *argInit_1xUnbounded_struct4_T();
static emxArray_real_T *argInit_2xUnbounded_real_T();
static void argInit_3x1_real_T(double result[3]);
static emxArray_real_T *argInit_Unboundedx1_real_T();
static emxArray_real_T *argInit_Unboundedx2_real_T();
static boolean_T argInit_boolean_T();
static void argInit_d100xd100_boolean_T(boolean_T result_data[], int
  result_size[2]);
static emxArray_real_T *argInit_d200xd200_real_T();
static double argInit_real_T();
static struct0_T argInit_struct0_T();
static void argInit_struct1_T(struct1_T *result);
static struct3_T argInit_struct3_T();
static struct4_T argInit_struct4_T();
static emxArray_real_T *c_argInit_Unboundedx2xUnbounded();
static void main_fcn_track_ccdp_fast();

// Function Definitions

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_1xUnbounded_real_T()
{
  emxArray_real_T *result;
  static int iv7[2] = { 1, 2 };

  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv7[0]);

  // Loop over the array to initialize each element.
  for (b_j1 = 0; b_j1 < result->size[1U]; b_j1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result->data[result->size[0] * b_j1] = argInit_real_T();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : emxArray_struct0_T *
//
static emxArray_struct0_T *argInit_1xUnbounded_struct0_T()
{
  emxArray_struct0_T *result;
  static int iv0[2] = { 1, 2 };

  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_struct0_T(2, *(int (*)[2])&iv0[0]);

  // Loop over the array to initialize each element.
  for (b_j1 = 0; b_j1 < result->size[1U]; b_j1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result->data[result->size[0] * b_j1] = argInit_struct0_T();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : emxArray_struct4_T *
//
static emxArray_struct4_T *argInit_1xUnbounded_struct4_T()
{
  emxArray_struct4_T *result;
  static int iv5[2] = { 1, 2 };

  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_struct4_T(2, *(int (*)[2])&iv5[0]);

  // Loop over the array to initialize each element.
  for (b_j1 = 0; b_j1 < result->size[1U]; b_j1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result->data[result->size[0] * b_j1] = argInit_struct4_T();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_2xUnbounded_real_T()
{
  emxArray_real_T *result;
  static int iv1[2] = { 2, 2 };

  int b_j0;
  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv1[0]);

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < 2; b_j0++) {
    for (b_j1 = 0; b_j1 < result->size[1U]; b_j1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result->data[b_j0 + result->size[0] * b_j1] = argInit_real_T();
    }
  }

  return result;
}

//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_3x1_real_T(double result[3])
{
  int b_j0;

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < 3; b_j0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[b_j0] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_Unboundedx1_real_T()
{
  emxArray_real_T *result;
  static int iv3[1] = { 2 };

  int b_j0;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(1, *(int (*)[1])&iv3[0]);

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < result->size[0U]; b_j0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result->data[b_j0] = argInit_real_T();
  }

  return result;
}

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_Unboundedx2_real_T()
{
  emxArray_real_T *result;
  static int iv6[2] = { 2, 2 };

  int b_j0;
  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv6[0]);

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < result->size[0U]; b_j0++) {
    for (b_j1 = 0; b_j1 < 2; b_j1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result->data[b_j0 + result->size[0] * b_j1] = argInit_real_T();
    }
  }

  return result;
}

//
// Arguments    : void
// Return Type  : boolean_T
//
static boolean_T argInit_boolean_T()
{
  return false;
}

//
// Arguments    : boolean_T result_data[]
//                int result_size[2]
// Return Type  : void
//
static void argInit_d100xd100_boolean_T(boolean_T result_data[], int
  result_size[2])
{
  int b_j0;
  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result_size[0] = 2;
  result_size[1] = 2;

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < 2; b_j0++) {
    for (b_j1 = 0; b_j1 < 2; b_j1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result_data[b_j0 + 2 * b_j1] = argInit_boolean_T();
    }
  }
}

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *argInit_d200xd200_real_T()
{
  emxArray_real_T *result;
  static int iv2[2] = { 2, 2 };

  int b_j0;
  int b_j1;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(2, *(int (*)[2])&iv2[0]);

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < result->size[0U]; b_j0++) {
    for (b_j1 = 0; b_j1 < result->size[1U]; b_j1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result->data[b_j0 + result->size[0] * b_j1] = argInit_real_T();
    }
  }

  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : struct0_T
//
static struct0_T argInit_struct0_T()
{
  struct0_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.mean = argInit_2xUnbounded_real_T();
  result.sig = argInit_real_T();
  result.prob = argInit_real_T();
  result.M = argInit_real_T();
  return result;
}

//
// Arguments    : struct1_T *result
// Return Type  : void
//
static void argInit_struct1_T(struct1_T *result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result->xs = argInit_d200xd200_real_T();
  result->ys = argInit_d200xd200_real_T();
  result->glen = argInit_real_T();
  argInit_d100xd100_boolean_T(result->gmap.data, result->gmap.size);
}

//
// Arguments    : void
// Return Type  : struct3_T
//
static struct3_T argInit_struct3_T()
{
  struct3_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.ndir = argInit_real_T();
  result.gnum = argInit_real_T();
  result.glen = argInit_real_T();
  result.cc = argInit_Unboundedx1_real_T();
  result.A = c_argInit_Unboundedx2xUnbounded();
  return result;
}

//
// Arguments    : void
// Return Type  : struct4_T
//
static struct4_T argInit_struct4_T()
{
  struct4_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.sidxs = argInit_Unboundedx2_real_T();
  result.dir = argInit_1xUnbounded_real_T();
  return result;
}

//
// Arguments    : void
// Return Type  : emxArray_real_T *
//
static emxArray_real_T *c_argInit_Unboundedx2xUnbounded()
{
  emxArray_real_T *result;
  static int iv4[3] = { 2, 2, 2 };

  int b_j0;
  int b_j1;
  int j2;

  // Set the size of the array.
  // Change this size to the value that the application requires.
  result = emxCreateND_real_T(3, *(int (*)[3])&iv4[0]);

  // Loop over the array to initialize each element.
  for (b_j0 = 0; b_j0 < result->size[0U]; b_j0++) {
    for (b_j1 = 0; b_j1 < 2; b_j1++) {
      for (j2 = 0; j2 < result->size[2U]; j2++) {
        // Set the value of the array element.
        // Change this value to the value that the application requires.
        result->data[(b_j0 + result->size[0] * b_j1) + result->size[0] *
          result->size[1] * j2] = argInit_real_T();
      }
    }
  }

  return result;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_fcn_track_ccdp_fast()
{
  emxArray_real_T *predict_s;
  double pS[3];
  emxArray_struct0_T *pEst;
  double H;
  double T;
  struct1_T ccdp;
  double threshold_track;
  struct3_T costparam;
  emxArray_struct4_T *nextstate;
  double uw_opt;
  double uv_opt;
  emxInitArray_real_T(&predict_s, 2);

  // Initialize function 'fcn_track_ccdp_fast' input arguments.
  // Initialize function input argument 'pS'.
  argInit_3x1_real_T(pS);

  // Initialize function input argument 'pEst'.
  pEst = argInit_1xUnbounded_struct0_T();
  H = argInit_real_T();
  T = argInit_real_T();

  // Initialize function input argument 'ccdp'.
  argInit_struct1_T(&ccdp);
  threshold_track = argInit_real_T();

  // Initialize function input argument 'costparam'.
  costparam = argInit_struct3_T();

  // Initialize function input argument 'nextstate'.
  nextstate = argInit_1xUnbounded_struct4_T();

  // Call the entry-point 'fcn_track_ccdp_fast'.
  fcn_track_ccdp_fast(pS, pEst, H, T, &ccdp, threshold_track, &costparam,
                      nextstate, &uv_opt, &uw_opt, predict_s);
  emxDestroyArray_real_T(predict_s);
  emxDestroyArray_struct4_T(nextstate);
  emxDestroy_struct3_T(costparam);
  emxDestroy_struct1_T(ccdp);
  emxDestroyArray_struct0_T(pEst);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  fcn_track_ccdp_fast_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_fcn_track_ccdp_fast();

  // Terminate the application.
  // You do not need to do this more than one time.
  fcn_track_ccdp_fast_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
