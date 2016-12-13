/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_AdaptiveControl_sfun.h"
#include "c9_CtrPlatform_AdaptiveControl.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_AdaptiveControl_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[6] = { "nargin", "nargout", "Y",
  "sigma", "Kpi", "py1" };

/* Function Declarations */
static void initialize_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void initialize_params_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void enable_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void disable_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void set_sim_state_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_st);
static void finalize_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void sf_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c9_chartstep_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void initSimStructsc9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_py1, const char_T *c9_identifier, real_T
  c9_y[60]);
static void c9_b_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[60]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[122]);
static void c9_b_info_helper(c9_ResolvedFunctionInfo c9_info[122]);
static void c9_invNxN(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
                      *chartInstance, real_T c9_x[3600], real_T c9_y[3600]);
static void c9_eps(SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c9_eml_matlab_zgetrf(SFc9_CtrPlatform_AdaptiveControlInstanceStruct *
  chartInstance, real_T c9_A[3600], real_T c9_b_A[3600], int32_T c9_ipiv[60],
  int32_T *c9_info);
static void c9_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static boolean_T c9_eml_use_refblas
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c9_b_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c9_b);
static void c9_eml_xswap(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_x[3600], int32_T c9_ix0, int32_T c9_iy0, real_T
  c9_b_x[3600]);
static void c9_below_threshold(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c9_c_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c9_d_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c9_a,
   int32_T c9_b);
static void c9_eml_xger(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c9_m, int32_T c9_n, real_T c9_alpha1, int32_T c9_ix0,
  int32_T c9_iy0, real_T c9_A[3600], int32_T c9_ia0, real_T c9_b_A[3600]);
static void c9_eml_ipiv2perm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c9_ipiv[60], int32_T c9_perm[60]);
static void c9_eml_scalar_eg(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c9_eml_xtrsm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[3600], real_T c9_b_B[3600]);
static real_T c9_norm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
                      *chartInstance, real_T c9_x[3600]);
static void c9_eml_warning(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c9_b_eml_warning(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, char_T c9_varargin_2[14]);
static void c9_b_eml_scalar_eg(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c9_eml_xgemm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[360], real_T c9_C[360], real_T
  c9_b_C[360]);
static void c9_c_eml_scalar_eg(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c9_d_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_sprintf, const char_T *c9_identifier, char_T
  c9_y[14]);
static void c9_e_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[14]);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_f_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_g_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_b_is_active_c9_CtrPlatform_AdaptiveControl, const char_T *c9_identifier);
static uint8_T c9_h_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_eml_matlab_zgetrf
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, real_T c9_A
   [3600], int32_T c9_ipiv[60], int32_T *c9_info);
static void c9_b_eml_xswap(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_x[3600], int32_T c9_ix0, int32_T c9_iy0);
static void c9_b_eml_xger(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c9_m, int32_T c9_n, real_T c9_alpha1, int32_T c9_ix0,
  int32_T c9_iy0, real_T c9_A[3600], int32_T c9_ia0);
static void c9_b_eml_xtrsm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[3600]);
static void c9_b_eml_xgemm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[360], real_T c9_C[360]);
static void init_dsm_address_info(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_CtrPlatform_AdaptiveControl = 0U;
}

static void initialize_params_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void enable_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[60];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T (*c9_py1)[60];
  c9_py1 = (real_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2), FALSE);
  for (c9_i0 = 0; c9_i0 < 60; c9_i0++) {
    c9_u[c9_i0] = (*c9_py1)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 60), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_CtrPlatform_AdaptiveControl;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[60];
  int32_T c9_i1;
  real_T (*c9_py1)[60];
  c9_py1 = (real_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "py1",
                      c9_dv0);
  for (c9_i1 = 0; c9_i1 < 60; c9_i1++) {
    (*c9_py1)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_is_active_c9_CtrPlatform_AdaptiveControl =
    c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "is_active_c9_CtrPlatform_AdaptiveControl");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_CtrPlatform_AdaptiveControl(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void sf_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  int32_T c9_i5;
  real_T (*c9_py1)[60];
  real_T (*c9_Kpi)[3600];
  real_T (*c9_sigma)[6];
  real_T (*c9_Y)[360];
  c9_py1 = (real_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_Kpi = (real_T (*)[3600])ssGetInputPortSignal(chartInstance->S, 2);
  c9_sigma = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c9_Y = (real_T (*)[360])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 360; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*c9_Y)[c9_i2], 0U);
  }

  for (c9_i3 = 0; c9_i3 < 6; c9_i3++) {
    _SFD_DATA_RANGE_CHECK((*c9_sigma)[c9_i3], 1U);
  }

  for (c9_i4 = 0; c9_i4 < 3600; c9_i4++) {
    _SFD_DATA_RANGE_CHECK((*c9_Kpi)[c9_i4], 2U);
  }

  for (c9_i5 = 0; c9_i5 < 60; c9_i5++) {
    _SFD_DATA_RANGE_CHECK((*c9_py1)[c9_i5], 3U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_CtrPlatform_AdaptiveControl(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_AdaptiveControlMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c9_chartstep_c9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  int32_T c9_i6;
  real_T c9_Y[360];
  int32_T c9_i7;
  real_T c9_sigma[6];
  int32_T c9_i8;
  static real_T c9_Kpi[3600];
  uint32_T c9_debug_family_var_map[6];
  real_T c9_nargin = 3.0;
  real_T c9_nargout = 1.0;
  real_T c9_py1[60];
  int32_T c9_i9;
  static real_T c9_x[3600];
  int32_T c9_i10;
  real_T c9_b_x[3600];
  real_T c9_y[3600];
  int32_T c9_i11;
  real_T c9_c_x[3600];
  real_T c9_n1x;
  int32_T c9_i12;
  real_T c9_b_y[3600];
  real_T c9_n1xinv;
  real_T c9_a;
  real_T c9_b;
  real_T c9_c_y;
  real_T c9_rc;
  real_T c9_d_x;
  boolean_T c9_b_b;
  real_T c9_e_x;
  int32_T c9_i13;
  static char_T c9_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c9_u[8];
  const mxArray *c9_d_y = NULL;
  real_T c9_b_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_c_u;
  const mxArray *c9_f_y = NULL;
  real_T c9_d_u;
  const mxArray *c9_g_y = NULL;
  char_T c9_str[14];
  int32_T c9_i14;
  char_T c9_b_str[14];
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  real_T c9_c_b[360];
  int32_T c9_i19;
  real_T c9_h_y[360];
  int32_T c9_i20;
  real_T c9_i_y[3600];
  int32_T c9_i21;
  real_T c9_d_b[360];
  int32_T c9_i22;
  real_T c9_e_b[6];
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i25;
  real_T c9_C[60];
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  real_T (*c9_b_py1)[60];
  real_T (*c9_b_Kpi)[3600];
  real_T (*c9_b_sigma)[6];
  real_T (*c9_b_Y)[360];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c9_b_py1 = (real_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_Kpi = (real_T (*)[3600])ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_sigma = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_Y = (real_T (*)[360])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i6 = 0; c9_i6 < 360; c9_i6++) {
    c9_Y[c9_i6] = (*c9_b_Y)[c9_i6];
  }

  for (c9_i7 = 0; c9_i7 < 6; c9_i7++) {
    c9_sigma[c9_i7] = (*c9_b_sigma)[c9_i7];
  }

  for (c9_i8 = 0; c9_i8 < 3600; c9_i8++) {
    c9_Kpi[c9_i8] = (*c9_b_Kpi)[c9_i8];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 0U, c9_e_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 1U, c9_e_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c9_Y, 2U, c9_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_sigma, 3U, c9_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_Kpi, 4U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c9_py1, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  for (c9_i9 = 0; c9_i9 < 3600; c9_i9++) {
    c9_x[c9_i9] = c9_Kpi[c9_i9];
  }

  for (c9_i10 = 0; c9_i10 < 3600; c9_i10++) {
    c9_b_x[c9_i10] = c9_x[c9_i10];
  }

  c9_invNxN(chartInstance, c9_b_x, c9_y);
  for (c9_i11 = 0; c9_i11 < 3600; c9_i11++) {
    c9_c_x[c9_i11] = c9_x[c9_i11];
  }

  c9_n1x = c9_norm(chartInstance, c9_c_x);
  for (c9_i12 = 0; c9_i12 < 3600; c9_i12++) {
    c9_b_y[c9_i12] = c9_y[c9_i12];
  }

  c9_n1xinv = c9_norm(chartInstance, c9_b_y);
  c9_a = c9_n1x;
  c9_b = c9_n1xinv;
  c9_c_y = c9_a * c9_b;
  c9_rc = 1.0 / c9_c_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c9_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c9_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c9_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c9_d_x = c9_rc;
    c9_b_b = muDoubleScalarIsNaN(c9_d_x);
    guard3 = FALSE;
    if (c9_b_b) {
      guard3 = TRUE;
    } else {
      c9_eps(chartInstance);
      if (c9_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c9_e_x = c9_rc;
      for (c9_i13 = 0; c9_i13 < 8; c9_i13++) {
        c9_u[c9_i13] = c9_cv0[c9_i13];
      }

      c9_d_y = NULL;
      sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c9_b_u = 14.0;
      c9_e_y = NULL;
      sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c9_c_u = 6.0;
      c9_f_y = NULL;
      sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c9_d_u = c9_e_x;
      c9_g_y = NULL;
      sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c9_d_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c9_d_y, 14, c9_e_y, 14,
        c9_f_y), 14, c9_g_y), "sprintf", c9_str);
      for (c9_i14 = 0; c9_i14 < 14; c9_i14++) {
        c9_b_str[c9_i14] = c9_str[c9_i14];
      }

      c9_b_eml_warning(chartInstance, c9_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c9_eml_warning(chartInstance);
  }

  c9_i15 = 0;
  for (c9_i16 = 0; c9_i16 < 6; c9_i16++) {
    c9_i17 = 0;
    for (c9_i18 = 0; c9_i18 < 60; c9_i18++) {
      c9_c_b[c9_i18 + c9_i15] = c9_Y[c9_i17 + c9_i16];
      c9_i17 += 6;
    }

    c9_i15 += 60;
  }

  c9_b_eml_scalar_eg(chartInstance);
  c9_b_eml_scalar_eg(chartInstance);
  for (c9_i19 = 0; c9_i19 < 360; c9_i19++) {
    c9_h_y[c9_i19] = 0.0;
  }

  for (c9_i20 = 0; c9_i20 < 3600; c9_i20++) {
    c9_i_y[c9_i20] = c9_y[c9_i20];
  }

  for (c9_i21 = 0; c9_i21 < 360; c9_i21++) {
    c9_d_b[c9_i21] = c9_c_b[c9_i21];
  }

  c9_b_eml_xgemm(chartInstance, c9_i_y, c9_d_b, c9_h_y);
  for (c9_i22 = 0; c9_i22 < 6; c9_i22++) {
    c9_e_b[c9_i22] = c9_sigma[c9_i22];
  }

  c9_c_eml_scalar_eg(chartInstance);
  c9_c_eml_scalar_eg(chartInstance);
  for (c9_i23 = 0; c9_i23 < 60; c9_i23++) {
    c9_py1[c9_i23] = 0.0;
  }

  for (c9_i24 = 0; c9_i24 < 60; c9_i24++) {
    c9_py1[c9_i24] = 0.0;
  }

  for (c9_i25 = 0; c9_i25 < 60; c9_i25++) {
    c9_C[c9_i25] = c9_py1[c9_i25];
  }

  for (c9_i26 = 0; c9_i26 < 60; c9_i26++) {
    c9_py1[c9_i26] = c9_C[c9_i26];
  }

  for (c9_i27 = 0; c9_i27 < 60; c9_i27++) {
    c9_C[c9_i27] = c9_py1[c9_i27];
  }

  for (c9_i28 = 0; c9_i28 < 60; c9_i28++) {
    c9_py1[c9_i28] = c9_C[c9_i28];
  }

  for (c9_i29 = 0; c9_i29 < 60; c9_i29++) {
    c9_py1[c9_i29] = 0.0;
    c9_i30 = 0;
    for (c9_i31 = 0; c9_i31 < 6; c9_i31++) {
      c9_py1[c9_i29] += c9_h_y[c9_i30 + c9_i29] * c9_e_b[c9_i31];
      c9_i30 += 60;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -3);
  sf_debug_symbol_scope_pop();
  for (c9_i32 = 0; c9_i32 < 60; c9_i32++) {
    (*c9_b_py1)[c9_i32] = c9_py1[c9_i32];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
}

static void initSimStructsc9_CtrPlatform_AdaptiveControl
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i33;
  real_T c9_b_inData[60];
  int32_T c9_i34;
  real_T c9_u[60];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i33 = 0; c9_i33 < 60; c9_i33++) {
    c9_b_inData[c9_i33] = (*(real_T (*)[60])c9_inData)[c9_i33];
  }

  for (c9_i34 = 0; c9_i34 < 60; c9_i34++) {
    c9_u[c9_i34] = c9_b_inData[c9_i34];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 60), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_py1, const char_T *c9_identifier, real_T
  c9_y[60])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_py1), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_py1);
}

static void c9_b_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[60])
{
  real_T c9_dv1[60];
  int32_T c9_i35;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 1, 60);
  for (c9_i35 = 0; c9_i35 < 60; c9_i35++) {
    c9_y[c9_i35] = c9_dv1[c9_i35];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_py1;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[60];
  int32_T c9_i36;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_py1 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_py1), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_py1);
  for (c9_i36 = 0; c9_i36 < 60; c9_i36++) {
    (*(real_T (*)[60])c9_outData)[c9_i36] = c9_y[c9_i36];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  real_T c9_b_inData[3600];
  int32_T c9_i40;
  int32_T c9_i41;
  int32_T c9_i42;
  real_T c9_u[3600];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i37 = 0;
  for (c9_i38 = 0; c9_i38 < 60; c9_i38++) {
    for (c9_i39 = 0; c9_i39 < 60; c9_i39++) {
      c9_b_inData[c9_i39 + c9_i37] = (*(real_T (*)[3600])c9_inData)[c9_i39 +
        c9_i37];
    }

    c9_i37 += 60;
  }

  c9_i40 = 0;
  for (c9_i41 = 0; c9_i41 < 60; c9_i41++) {
    for (c9_i42 = 0; c9_i42 < 60; c9_i42++) {
      c9_u[c9_i42 + c9_i40] = c9_b_inData[c9_i42 + c9_i40];
    }

    c9_i40 += 60;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 60, 60), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i43;
  real_T c9_b_inData[6];
  int32_T c9_i44;
  real_T c9_u[6];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i43 = 0; c9_i43 < 6; c9_i43++) {
    c9_b_inData[c9_i43] = (*(real_T (*)[6])c9_inData)[c9_i43];
  }

  for (c9_i44 = 0; c9_i44 < 6; c9_i44++) {
    c9_u[c9_i44] = c9_b_inData[c9_i44];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i45;
  int32_T c9_i46;
  int32_T c9_i47;
  real_T c9_b_inData[360];
  int32_T c9_i48;
  int32_T c9_i49;
  int32_T c9_i50;
  real_T c9_u[360];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i45 = 0;
  for (c9_i46 = 0; c9_i46 < 60; c9_i46++) {
    for (c9_i47 = 0; c9_i47 < 6; c9_i47++) {
      c9_b_inData[c9_i47 + c9_i45] = (*(real_T (*)[360])c9_inData)[c9_i47 +
        c9_i45];
    }

    c9_i45 += 6;
  }

  c9_i48 = 0;
  for (c9_i49 = 0; c9_i49 < 60; c9_i49++) {
    for (c9_i50 = 0; c9_i50 < 6; c9_i50++) {
      c9_u[c9_i50 + c9_i48] = c9_b_inData[c9_i50 + c9_i48];
    }

    c9_i48 += 6;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 6, 60), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_CtrPlatform_AdaptiveControl_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[122];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i51;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  c9_b_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 122), FALSE);
  for (c9_i51 = 0; c9_i51 < 122; c9_i51++) {
    c9_r0 = &c9_info[c9_i51];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i51);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i51);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i51);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i51);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i51);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i51);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i51);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i51);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[122])
{
  c9_info[0].context = "";
  c9_info[0].name = "inv";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m";
  c9_info[0].fileTimeLo = 1305296400U;
  c9_info[0].fileTimeHi = 0U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[1].name = "eml_index_class";
  c9_info[1].dominantType = "";
  c9_info[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[1].fileTimeLo = 1286797178U;
  c9_info[1].fileTimeHi = 0U;
  c9_info[1].mFileTimeLo = 0U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[2].name = "eml_xgetrf";
  c9_info[2].dominantType = "int32";
  c9_info[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c9_info[2].fileTimeLo = 1286797206U;
  c9_info[2].fileTimeHi = 0U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c9_info[3].name = "eml_lapack_xgetrf";
  c9_info[3].dominantType = "int32";
  c9_info[3].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c9_info[3].fileTimeLo = 1286797210U;
  c9_info[3].fileTimeHi = 0U;
  c9_info[3].mFileTimeLo = 0U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c9_info[4].name = "eml_matlab_zgetrf";
  c9_info[4].dominantType = "int32";
  c9_info[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[4].fileTimeLo = 1302667394U;
  c9_info[4].fileTimeHi = 0U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[5].name = "realmin";
  c9_info[5].dominantType = "char";
  c9_info[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c9_info[5].fileTimeLo = 1307629642U;
  c9_info[5].fileTimeHi = 0U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c9_info[6].name = "eml_realmin";
  c9_info[6].dominantType = "char";
  c9_info[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c9_info[6].fileTimeLo = 1307629644U;
  c9_info[6].fileTimeHi = 0U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c9_info[7].name = "eml_float_model";
  c9_info[7].dominantType = "char";
  c9_info[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c9_info[7].fileTimeLo = 1307629642U;
  c9_info[7].fileTimeHi = 0U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[8].name = "eps";
  c9_info[8].dominantType = "char";
  c9_info[8].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c9_info[8].fileTimeLo = 1307629640U;
  c9_info[8].fileTimeHi = 0U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c9_info[9].name = "eml_is_float_class";
  c9_info[9].dominantType = "char";
  c9_info[9].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c9_info[9].fileTimeLo = 1286797182U;
  c9_info[9].fileTimeHi = 0U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c9_info[10].name = "eml_eps";
  c9_info[10].dominantType = "char";
  c9_info[10].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c9_info[10].fileTimeLo = 1307629640U;
  c9_info[10].fileTimeHi = 0U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c9_info[11].name = "eml_float_model";
  c9_info[11].dominantType = "char";
  c9_info[11].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c9_info[11].fileTimeLo = 1307629642U;
  c9_info[11].fileTimeHi = 0U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[12].name = "min";
  c9_info[12].dominantType = "int32";
  c9_info[12].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[12].fileTimeLo = 1311233718U;
  c9_info[12].fileTimeHi = 0U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
  c9_info[13].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[13].name = "eml_min_or_max";
  c9_info[13].dominantType = "int32";
  c9_info[13].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[13].fileTimeLo = 1303124612U;
  c9_info[13].fileTimeHi = 0U;
  c9_info[13].mFileTimeLo = 0U;
  c9_info[13].mFileTimeHi = 0U;
  c9_info[14].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[14].name = "eml_scalar_eg";
  c9_info[14].dominantType = "int32";
  c9_info[14].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[14].fileTimeLo = 1286797196U;
  c9_info[14].fileTimeHi = 0U;
  c9_info[14].mFileTimeLo = 0U;
  c9_info[14].mFileTimeHi = 0U;
  c9_info[15].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[15].name = "eml_scalexp_alloc";
  c9_info[15].dominantType = "int32";
  c9_info[15].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[15].fileTimeLo = 1286797196U;
  c9_info[15].fileTimeHi = 0U;
  c9_info[15].mFileTimeLo = 0U;
  c9_info[15].mFileTimeHi = 0U;
  c9_info[16].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[16].name = "eml_index_class";
  c9_info[16].dominantType = "";
  c9_info[16].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[16].fileTimeLo = 1286797178U;
  c9_info[16].fileTimeHi = 0U;
  c9_info[16].mFileTimeLo = 0U;
  c9_info[16].mFileTimeHi = 0U;
  c9_info[17].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c9_info[17].name = "eml_scalar_eg";
  c9_info[17].dominantType = "int32";
  c9_info[17].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[17].fileTimeLo = 1286797196U;
  c9_info[17].fileTimeHi = 0U;
  c9_info[17].mFileTimeLo = 0U;
  c9_info[17].mFileTimeHi = 0U;
  c9_info[18].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[18].name = "colon";
  c9_info[18].dominantType = "int32";
  c9_info[18].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c9_info[18].fileTimeLo = 1311233718U;
  c9_info[18].fileTimeHi = 0U;
  c9_info[18].mFileTimeLo = 0U;
  c9_info[18].mFileTimeHi = 0U;
  c9_info[19].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c9_info[19].name = "colon";
  c9_info[19].dominantType = "int32";
  c9_info[19].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c9_info[19].fileTimeLo = 1311233718U;
  c9_info[19].fileTimeHi = 0U;
  c9_info[19].mFileTimeLo = 0U;
  c9_info[19].mFileTimeHi = 0U;
  c9_info[20].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c9_info[20].name = "floor";
  c9_info[20].dominantType = "double";
  c9_info[20].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c9_info[20].fileTimeLo = 1286797142U;
  c9_info[20].fileTimeHi = 0U;
  c9_info[20].mFileTimeLo = 0U;
  c9_info[20].mFileTimeHi = 0U;
  c9_info[21].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c9_info[21].name = "eml_scalar_floor";
  c9_info[21].dominantType = "double";
  c9_info[21].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c9_info[21].fileTimeLo = 1286797126U;
  c9_info[21].fileTimeHi = 0U;
  c9_info[21].mFileTimeLo = 0U;
  c9_info[21].mFileTimeHi = 0U;
  c9_info[22].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c9_info[22].name = "intmin";
  c9_info[22].dominantType = "char";
  c9_info[22].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c9_info[22].fileTimeLo = 1311233718U;
  c9_info[22].fileTimeHi = 0U;
  c9_info[22].mFileTimeLo = 0U;
  c9_info[22].mFileTimeHi = 0U;
  c9_info[23].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c9_info[23].name = "intmax";
  c9_info[23].dominantType = "char";
  c9_info[23].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[23].fileTimeLo = 1311233716U;
  c9_info[23].fileTimeHi = 0U;
  c9_info[23].mFileTimeLo = 0U;
  c9_info[23].mFileTimeHi = 0U;
  c9_info[24].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c9_info[24].name = "intmin";
  c9_info[24].dominantType = "char";
  c9_info[24].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c9_info[24].fileTimeLo = 1311233718U;
  c9_info[24].fileTimeHi = 0U;
  c9_info[24].mFileTimeLo = 0U;
  c9_info[24].mFileTimeHi = 0U;
  c9_info[25].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c9_info[25].name = "intmax";
  c9_info[25].dominantType = "char";
  c9_info[25].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[25].fileTimeLo = 1311233716U;
  c9_info[25].fileTimeHi = 0U;
  c9_info[25].mFileTimeLo = 0U;
  c9_info[25].mFileTimeHi = 0U;
  c9_info[26].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c9_info[26].name = "eml_isa_uint";
  c9_info[26].dominantType = "int32";
  c9_info[26].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c9_info[26].fileTimeLo = 1286797184U;
  c9_info[26].fileTimeHi = 0U;
  c9_info[26].mFileTimeLo = 0U;
  c9_info[26].mFileTimeHi = 0U;
  c9_info[27].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c9_info[27].name = "eml_unsigned_class";
  c9_info[27].dominantType = "char";
  c9_info[27].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c9_info[27].fileTimeLo = 1286797200U;
  c9_info[27].fileTimeHi = 0U;
  c9_info[27].mFileTimeLo = 0U;
  c9_info[27].mFileTimeHi = 0U;
  c9_info[28].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c9_info[28].name = "eml_index_class";
  c9_info[28].dominantType = "";
  c9_info[28].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[28].fileTimeLo = 1286797178U;
  c9_info[28].fileTimeHi = 0U;
  c9_info[28].mFileTimeLo = 0U;
  c9_info[28].mFileTimeHi = 0U;
  c9_info[29].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c9_info[29].name = "intmax";
  c9_info[29].dominantType = "char";
  c9_info[29].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[29].fileTimeLo = 1311233716U;
  c9_info[29].fileTimeHi = 0U;
  c9_info[29].mFileTimeLo = 0U;
  c9_info[29].mFileTimeHi = 0U;
  c9_info[30].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c9_info[30].name = "eml_isa_uint";
  c9_info[30].dominantType = "int32";
  c9_info[30].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c9_info[30].fileTimeLo = 1286797184U;
  c9_info[30].fileTimeHi = 0U;
  c9_info[30].mFileTimeLo = 0U;
  c9_info[30].mFileTimeHi = 0U;
  c9_info[31].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c9_info[31].name = "eml_index_plus";
  c9_info[31].dominantType = "int32";
  c9_info[31].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[31].fileTimeLo = 1286797178U;
  c9_info[31].fileTimeHi = 0U;
  c9_info[31].mFileTimeLo = 0U;
  c9_info[31].mFileTimeHi = 0U;
  c9_info[32].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[32].name = "eml_index_class";
  c9_info[32].dominantType = "";
  c9_info[32].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[32].fileTimeLo = 1286797178U;
  c9_info[32].fileTimeHi = 0U;
  c9_info[32].mFileTimeLo = 0U;
  c9_info[32].mFileTimeHi = 0U;
  c9_info[33].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c9_info[33].name = "eml_int_forloop_overflow_check";
  c9_info[33].dominantType = "";
  c9_info[33].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[33].fileTimeLo = 1311233716U;
  c9_info[33].fileTimeHi = 0U;
  c9_info[33].mFileTimeLo = 0U;
  c9_info[33].mFileTimeHi = 0U;
  c9_info[34].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c9_info[34].name = "intmax";
  c9_info[34].dominantType = "char";
  c9_info[34].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[34].fileTimeLo = 1311233716U;
  c9_info[34].fileTimeHi = 0U;
  c9_info[34].mFileTimeLo = 0U;
  c9_info[34].mFileTimeHi = 0U;
  c9_info[35].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[35].name = "eml_index_class";
  c9_info[35].dominantType = "";
  c9_info[35].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[35].fileTimeLo = 1286797178U;
  c9_info[35].fileTimeHi = 0U;
  c9_info[35].mFileTimeLo = 0U;
  c9_info[35].mFileTimeHi = 0U;
  c9_info[36].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[36].name = "eml_index_plus";
  c9_info[36].dominantType = "int32";
  c9_info[36].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[36].fileTimeLo = 1286797178U;
  c9_info[36].fileTimeHi = 0U;
  c9_info[36].mFileTimeLo = 0U;
  c9_info[36].mFileTimeHi = 0U;
  c9_info[37].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[37].name = "eml_int_forloop_overflow_check";
  c9_info[37].dominantType = "";
  c9_info[37].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[37].fileTimeLo = 1311233716U;
  c9_info[37].fileTimeHi = 0U;
  c9_info[37].mFileTimeLo = 0U;
  c9_info[37].mFileTimeHi = 0U;
  c9_info[38].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[38].name = "eml_index_minus";
  c9_info[38].dominantType = "int32";
  c9_info[38].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[38].fileTimeLo = 1286797178U;
  c9_info[38].fileTimeHi = 0U;
  c9_info[38].mFileTimeLo = 0U;
  c9_info[38].mFileTimeHi = 0U;
  c9_info[39].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[39].name = "eml_index_class";
  c9_info[39].dominantType = "";
  c9_info[39].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[39].fileTimeLo = 1286797178U;
  c9_info[39].fileTimeHi = 0U;
  c9_info[39].mFileTimeLo = 0U;
  c9_info[39].mFileTimeHi = 0U;
  c9_info[40].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[40].name = "eml_index_times";
  c9_info[40].dominantType = "int32";
  c9_info[40].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[40].fileTimeLo = 1286797180U;
  c9_info[40].fileTimeHi = 0U;
  c9_info[40].mFileTimeLo = 0U;
  c9_info[40].mFileTimeHi = 0U;
  c9_info[41].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[41].name = "eml_index_class";
  c9_info[41].dominantType = "";
  c9_info[41].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[41].fileTimeLo = 1286797178U;
  c9_info[41].fileTimeHi = 0U;
  c9_info[41].mFileTimeLo = 0U;
  c9_info[41].mFileTimeHi = 0U;
  c9_info[42].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[42].name = "eml_ixamax";
  c9_info[42].dominantType = "int32";
  c9_info[42].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c9_info[42].fileTimeLo = 1299051570U;
  c9_info[42].fileTimeHi = 0U;
  c9_info[42].mFileTimeLo = 0U;
  c9_info[42].mFileTimeHi = 0U;
  c9_info[43].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c9_info[43].name = "eml_blas_inline";
  c9_info[43].dominantType = "";
  c9_info[43].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[43].fileTimeLo = 1299051568U;
  c9_info[43].fileTimeHi = 0U;
  c9_info[43].mFileTimeLo = 0U;
  c9_info[43].mFileTimeHi = 0U;
  c9_info[44].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c9_info[44].name = "length";
  c9_info[44].dominantType = "double";
  c9_info[44].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m";
  c9_info[44].fileTimeLo = 1303124606U;
  c9_info[44].fileTimeHi = 0U;
  c9_info[44].mFileTimeLo = 0U;
  c9_info[44].mFileTimeHi = 0U;
  c9_info[45].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c9_info[45].name = "eml_index_class";
  c9_info[45].dominantType = "";
  c9_info[45].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[45].fileTimeLo = 1286797178U;
  c9_info[45].fileTimeHi = 0U;
  c9_info[45].mFileTimeLo = 0U;
  c9_info[45].mFileTimeHi = 0U;
  c9_info[46].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c9_info[46].name = "eml_refblas_ixamax";
  c9_info[46].dominantType = "int32";
  c9_info[46].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c9_info[46].fileTimeLo = 1299051570U;
  c9_info[46].fileTimeHi = 0U;
  c9_info[46].mFileTimeLo = 0U;
  c9_info[46].mFileTimeHi = 0U;
  c9_info[47].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c9_info[47].name = "eml_index_class";
  c9_info[47].dominantType = "";
  c9_info[47].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[47].fileTimeLo = 1286797178U;
  c9_info[47].fileTimeHi = 0U;
  c9_info[47].mFileTimeLo = 0U;
  c9_info[47].mFileTimeHi = 0U;
  c9_info[48].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c9_info[48].name = "eml_xcabs1";
  c9_info[48].dominantType = "double";
  c9_info[48].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c9_info[48].fileTimeLo = 1286797106U;
  c9_info[48].fileTimeHi = 0U;
  c9_info[48].mFileTimeLo = 0U;
  c9_info[48].mFileTimeHi = 0U;
  c9_info[49].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c9_info[49].name = "abs";
  c9_info[49].dominantType = "double";
  c9_info[49].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[49].fileTimeLo = 1286797094U;
  c9_info[49].fileTimeHi = 0U;
  c9_info[49].mFileTimeLo = 0U;
  c9_info[49].mFileTimeHi = 0U;
  c9_info[50].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[50].name = "eml_scalar_abs";
  c9_info[50].dominantType = "double";
  c9_info[50].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[50].fileTimeLo = 1286797112U;
  c9_info[50].fileTimeHi = 0U;
  c9_info[50].mFileTimeLo = 0U;
  c9_info[50].mFileTimeHi = 0U;
  c9_info[51].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c9_info[51].name = "eml_int_forloop_overflow_check";
  c9_info[51].dominantType = "";
  c9_info[51].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[51].fileTimeLo = 1311233716U;
  c9_info[51].fileTimeHi = 0U;
  c9_info[51].mFileTimeLo = 0U;
  c9_info[51].mFileTimeHi = 0U;
  c9_info[52].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c9_info[52].name = "eml_index_plus";
  c9_info[52].dominantType = "int32";
  c9_info[52].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[52].fileTimeLo = 1286797178U;
  c9_info[52].fileTimeHi = 0U;
  c9_info[52].mFileTimeLo = 0U;
  c9_info[52].mFileTimeHi = 0U;
  c9_info[53].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[53].name = "eml_xswap";
  c9_info[53].dominantType = "int32";
  c9_info[53].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c9_info[53].fileTimeLo = 1299051578U;
  c9_info[53].fileTimeHi = 0U;
  c9_info[53].mFileTimeLo = 0U;
  c9_info[53].mFileTimeHi = 0U;
  c9_info[54].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c9_info[54].name = "eml_blas_inline";
  c9_info[54].dominantType = "";
  c9_info[54].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[54].fileTimeLo = 1299051568U;
  c9_info[54].fileTimeHi = 0U;
  c9_info[54].mFileTimeLo = 0U;
  c9_info[54].mFileTimeHi = 0U;
  c9_info[55].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c9_info[55].name = "eml_refblas_xswap";
  c9_info[55].dominantType = "int32";
  c9_info[55].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c9_info[55].fileTimeLo = 1299051586U;
  c9_info[55].fileTimeHi = 0U;
  c9_info[55].mFileTimeLo = 0U;
  c9_info[55].mFileTimeHi = 0U;
  c9_info[56].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c9_info[56].name = "eml_index_class";
  c9_info[56].dominantType = "";
  c9_info[56].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[56].fileTimeLo = 1286797178U;
  c9_info[56].fileTimeHi = 0U;
  c9_info[56].mFileTimeLo = 0U;
  c9_info[56].mFileTimeHi = 0U;
  c9_info[57].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c9_info[57].name = "abs";
  c9_info[57].dominantType = "int32";
  c9_info[57].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[57].fileTimeLo = 1286797094U;
  c9_info[57].fileTimeHi = 0U;
  c9_info[57].mFileTimeLo = 0U;
  c9_info[57].mFileTimeHi = 0U;
  c9_info[58].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[58].name = "eml_scalar_abs";
  c9_info[58].dominantType = "int32";
  c9_info[58].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c9_info[58].fileTimeLo = 1286797112U;
  c9_info[58].fileTimeHi = 0U;
  c9_info[58].mFileTimeLo = 0U;
  c9_info[58].mFileTimeHi = 0U;
  c9_info[59].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c9_info[59].name = "eml_int_forloop_overflow_check";
  c9_info[59].dominantType = "";
  c9_info[59].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[59].fileTimeLo = 1311233716U;
  c9_info[59].fileTimeHi = 0U;
  c9_info[59].mFileTimeLo = 0U;
  c9_info[59].mFileTimeHi = 0U;
  c9_info[60].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c9_info[60].name = "eml_index_plus";
  c9_info[60].dominantType = "int32";
  c9_info[60].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[60].fileTimeLo = 1286797178U;
  c9_info[60].fileTimeHi = 0U;
  c9_info[60].mFileTimeLo = 0U;
  c9_info[60].mFileTimeHi = 0U;
  c9_info[61].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[61].name = "eml_div";
  c9_info[61].dominantType = "double";
  c9_info[61].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[61].fileTimeLo = 1313326210U;
  c9_info[61].fileTimeHi = 0U;
  c9_info[61].mFileTimeLo = 0U;
  c9_info[61].mFileTimeHi = 0U;
  c9_info[62].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c9_info[62].name = "eml_xgeru";
  c9_info[62].dominantType = "int32";
  c9_info[62].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c9_info[62].fileTimeLo = 1299051574U;
  c9_info[62].fileTimeHi = 0U;
  c9_info[62].mFileTimeLo = 0U;
  c9_info[62].mFileTimeHi = 0U;
  c9_info[63].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c9_info[63].name = "eml_blas_inline";
  c9_info[63].dominantType = "";
  c9_info[63].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[63].fileTimeLo = 1299051568U;
  c9_info[63].fileTimeHi = 0U;
  c9_info[63].mFileTimeLo = 0U;
  c9_info[63].mFileTimeHi = 0U;
}

static void c9_b_info_helper(c9_ResolvedFunctionInfo c9_info[122])
{
  c9_info[64].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c9_info[64].name = "eml_xger";
  c9_info[64].dominantType = "int32";
  c9_info[64].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c9_info[64].fileTimeLo = 1299051574U;
  c9_info[64].fileTimeHi = 0U;
  c9_info[64].mFileTimeLo = 0U;
  c9_info[64].mFileTimeHi = 0U;
  c9_info[65].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c9_info[65].name = "eml_blas_inline";
  c9_info[65].dominantType = "";
  c9_info[65].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[65].fileTimeLo = 1299051568U;
  c9_info[65].fileTimeHi = 0U;
  c9_info[65].mFileTimeLo = 0U;
  c9_info[65].mFileTimeHi = 0U;
  c9_info[66].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c9_info[66].name = "intmax";
  c9_info[66].dominantType = "char";
  c9_info[66].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[66].fileTimeLo = 1311233716U;
  c9_info[66].fileTimeHi = 0U;
  c9_info[66].mFileTimeLo = 0U;
  c9_info[66].mFileTimeHi = 0U;
  c9_info[67].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c9_info[67].name = "min";
  c9_info[67].dominantType = "double";
  c9_info[67].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[67].fileTimeLo = 1311233718U;
  c9_info[67].fileTimeHi = 0U;
  c9_info[67].mFileTimeLo = 0U;
  c9_info[67].mFileTimeHi = 0U;
  c9_info[68].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[68].name = "eml_min_or_max";
  c9_info[68].dominantType = "char";
  c9_info[68].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[68].fileTimeLo = 1303124612U;
  c9_info[68].fileTimeHi = 0U;
  c9_info[68].mFileTimeLo = 0U;
  c9_info[68].mFileTimeHi = 0U;
  c9_info[69].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[69].name = "eml_scalar_eg";
  c9_info[69].dominantType = "double";
  c9_info[69].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[69].fileTimeLo = 1286797196U;
  c9_info[69].fileTimeHi = 0U;
  c9_info[69].mFileTimeLo = 0U;
  c9_info[69].mFileTimeHi = 0U;
  c9_info[70].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[70].name = "eml_scalexp_alloc";
  c9_info[70].dominantType = "double";
  c9_info[70].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[70].fileTimeLo = 1286797196U;
  c9_info[70].fileTimeHi = 0U;
  c9_info[70].mFileTimeLo = 0U;
  c9_info[70].mFileTimeHi = 0U;
  c9_info[71].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c9_info[71].name = "eml_scalar_eg";
  c9_info[71].dominantType = "double";
  c9_info[71].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[71].fileTimeLo = 1286797196U;
  c9_info[71].fileTimeHi = 0U;
  c9_info[71].mFileTimeLo = 0U;
  c9_info[71].mFileTimeHi = 0U;
  c9_info[72].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c9_info[72].name = "mtimes";
  c9_info[72].dominantType = "double";
  c9_info[72].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[72].fileTimeLo = 1289494492U;
  c9_info[72].fileTimeHi = 0U;
  c9_info[72].mFileTimeLo = 0U;
  c9_info[72].mFileTimeHi = 0U;
  c9_info[73].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c9_info[73].name = "eml_refblas_xger";
  c9_info[73].dominantType = "int32";
  c9_info[73].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c9_info[73].fileTimeLo = 1299051576U;
  c9_info[73].fileTimeHi = 0U;
  c9_info[73].mFileTimeLo = 0U;
  c9_info[73].mFileTimeHi = 0U;
  c9_info[74].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c9_info[74].name = "eml_refblas_xgerx";
  c9_info[74].dominantType = "int32";
  c9_info[74].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[74].fileTimeLo = 1299051578U;
  c9_info[74].fileTimeHi = 0U;
  c9_info[74].mFileTimeLo = 0U;
  c9_info[74].mFileTimeHi = 0U;
  c9_info[75].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[75].name = "eml_index_class";
  c9_info[75].dominantType = "";
  c9_info[75].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[75].fileTimeLo = 1286797178U;
  c9_info[75].fileTimeHi = 0U;
  c9_info[75].mFileTimeLo = 0U;
  c9_info[75].mFileTimeHi = 0U;
  c9_info[76].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[76].name = "abs";
  c9_info[76].dominantType = "int32";
  c9_info[76].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[76].fileTimeLo = 1286797094U;
  c9_info[76].fileTimeHi = 0U;
  c9_info[76].mFileTimeLo = 0U;
  c9_info[76].mFileTimeHi = 0U;
  c9_info[77].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[77].name = "eml_index_minus";
  c9_info[77].dominantType = "int32";
  c9_info[77].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[77].fileTimeLo = 1286797178U;
  c9_info[77].fileTimeHi = 0U;
  c9_info[77].mFileTimeLo = 0U;
  c9_info[77].mFileTimeHi = 0U;
  c9_info[78].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[78].name = "eml_int_forloop_overflow_check";
  c9_info[78].dominantType = "";
  c9_info[78].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[78].fileTimeLo = 1311233716U;
  c9_info[78].fileTimeHi = 0U;
  c9_info[78].mFileTimeLo = 0U;
  c9_info[78].mFileTimeHi = 0U;
  c9_info[79].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c9_info[79].name = "eml_index_plus";
  c9_info[79].dominantType = "int32";
  c9_info[79].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[79].fileTimeLo = 1286797178U;
  c9_info[79].fileTimeHi = 0U;
  c9_info[79].mFileTimeLo = 0U;
  c9_info[79].mFileTimeHi = 0U;
  c9_info[80].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c9_info[80].name = "eml_index_class";
  c9_info[80].dominantType = "";
  c9_info[80].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[80].fileTimeLo = 1286797178U;
  c9_info[80].fileTimeHi = 0U;
  c9_info[80].mFileTimeLo = 0U;
  c9_info[80].mFileTimeHi = 0U;
  c9_info[81].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[81].name = "eml_ipiv2perm";
  c9_info[81].dominantType = "int32";
  c9_info[81].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c9_info[81].fileTimeLo = 1286797182U;
  c9_info[81].fileTimeHi = 0U;
  c9_info[81].mFileTimeLo = 0U;
  c9_info[81].mFileTimeHi = 0U;
  c9_info[82].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c9_info[82].name = "colon";
  c9_info[82].dominantType = "int32";
  c9_info[82].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c9_info[82].fileTimeLo = 1311233718U;
  c9_info[82].fileTimeHi = 0U;
  c9_info[82].mFileTimeLo = 0U;
  c9_info[82].mFileTimeHi = 0U;
  c9_info[83].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c9_info[83].name = "eml_index_class";
  c9_info[83].dominantType = "";
  c9_info[83].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[83].fileTimeLo = 1286797178U;
  c9_info[83].fileTimeHi = 0U;
  c9_info[83].mFileTimeLo = 0U;
  c9_info[83].mFileTimeHi = 0U;
  c9_info[84].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[84].name = "eml_int_forloop_overflow_check";
  c9_info[84].dominantType = "";
  c9_info[84].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[84].fileTimeLo = 1311233716U;
  c9_info[84].fileTimeHi = 0U;
  c9_info[84].mFileTimeLo = 0U;
  c9_info[84].mFileTimeHi = 0U;
  c9_info[85].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[85].name = "eml_index_plus";
  c9_info[85].dominantType = "int32";
  c9_info[85].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[85].fileTimeLo = 1286797178U;
  c9_info[85].fileTimeHi = 0U;
  c9_info[85].mFileTimeLo = 0U;
  c9_info[85].mFileTimeHi = 0U;
  c9_info[86].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[86].name = "mtimes";
  c9_info[86].dominantType = "double";
  c9_info[86].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[86].fileTimeLo = 1289494492U;
  c9_info[86].fileTimeHi = 0U;
  c9_info[86].mFileTimeLo = 0U;
  c9_info[86].mFileTimeHi = 0U;
  c9_info[87].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[87].name = "eml_scalar_eg";
  c9_info[87].dominantType = "double";
  c9_info[87].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[87].fileTimeLo = 1286797196U;
  c9_info[87].fileTimeHi = 0U;
  c9_info[87].mFileTimeLo = 0U;
  c9_info[87].mFileTimeHi = 0U;
  c9_info[88].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c9_info[88].name = "eml_xtrsm";
  c9_info[88].dominantType = "int32";
  c9_info[88].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c9_info[88].fileTimeLo = 1299051578U;
  c9_info[88].fileTimeHi = 0U;
  c9_info[88].mFileTimeLo = 0U;
  c9_info[88].mFileTimeHi = 0U;
  c9_info[89].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c9_info[89].name = "eml_blas_inline";
  c9_info[89].dominantType = "";
  c9_info[89].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[89].fileTimeLo = 1299051568U;
  c9_info[89].fileTimeHi = 0U;
  c9_info[89].mFileTimeLo = 0U;
  c9_info[89].mFileTimeHi = 0U;
  c9_info[90].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c9_info[90].name = "mtimes";
  c9_info[90].dominantType = "double";
  c9_info[90].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[90].fileTimeLo = 1289494492U;
  c9_info[90].fileTimeHi = 0U;
  c9_info[90].mFileTimeLo = 0U;
  c9_info[90].mFileTimeHi = 0U;
  c9_info[91].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c9_info[91].name = "eml_scalar_eg";
  c9_info[91].dominantType = "double";
  c9_info[91].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[91].fileTimeLo = 1286797196U;
  c9_info[91].fileTimeHi = 0U;
  c9_info[91].mFileTimeLo = 0U;
  c9_info[91].mFileTimeHi = 0U;
  c9_info[92].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c9_info[92].name = "eml_refblas_xtrsm";
  c9_info[92].dominantType = "int32";
  c9_info[92].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[92].fileTimeLo = 1299051586U;
  c9_info[92].fileTimeHi = 0U;
  c9_info[92].mFileTimeLo = 0U;
  c9_info[92].mFileTimeHi = 0U;
  c9_info[93].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[93].name = "eml_scalar_eg";
  c9_info[93].dominantType = "double";
  c9_info[93].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[93].fileTimeLo = 1286797196U;
  c9_info[93].fileTimeHi = 0U;
  c9_info[93].mFileTimeLo = 0U;
  c9_info[93].mFileTimeHi = 0U;
  c9_info[94].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[94].name = "eml_index_minus";
  c9_info[94].dominantType = "int32";
  c9_info[94].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[94].fileTimeLo = 1286797178U;
  c9_info[94].fileTimeHi = 0U;
  c9_info[94].mFileTimeLo = 0U;
  c9_info[94].mFileTimeHi = 0U;
  c9_info[95].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[95].name = "eml_index_class";
  c9_info[95].dominantType = "";
  c9_info[95].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[95].fileTimeLo = 1286797178U;
  c9_info[95].fileTimeHi = 0U;
  c9_info[95].mFileTimeLo = 0U;
  c9_info[95].mFileTimeHi = 0U;
  c9_info[96].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[96].name = "eml_int_forloop_overflow_check";
  c9_info[96].dominantType = "";
  c9_info[96].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[96].fileTimeLo = 1311233716U;
  c9_info[96].fileTimeHi = 0U;
  c9_info[96].mFileTimeLo = 0U;
  c9_info[96].mFileTimeHi = 0U;
  c9_info[97].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[97].name = "eml_index_times";
  c9_info[97].dominantType = "int32";
  c9_info[97].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[97].fileTimeLo = 1286797180U;
  c9_info[97].fileTimeHi = 0U;
  c9_info[97].mFileTimeLo = 0U;
  c9_info[97].mFileTimeHi = 0U;
  c9_info[98].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[98].name = "eml_index_plus";
  c9_info[98].dominantType = "int32";
  c9_info[98].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[98].fileTimeLo = 1286797178U;
  c9_info[98].fileTimeHi = 0U;
  c9_info[98].mFileTimeLo = 0U;
  c9_info[98].mFileTimeHi = 0U;
  c9_info[99].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c9_info[99].name = "intmin";
  c9_info[99].dominantType = "char";
  c9_info[99].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c9_info[99].fileTimeLo = 1311233718U;
  c9_info[99].fileTimeHi = 0U;
  c9_info[99].mFileTimeLo = 0U;
  c9_info[99].mFileTimeHi = 0U;
  c9_info[100].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c9_info[100].name = "eml_div";
  c9_info[100].dominantType = "double";
  c9_info[100].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[100].fileTimeLo = 1313326210U;
  c9_info[100].fileTimeHi = 0U;
  c9_info[100].mFileTimeLo = 0U;
  c9_info[100].mFileTimeHi = 0U;
  c9_info[101].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c9_info[101].name = "eml_index_class";
  c9_info[101].dominantType = "";
  c9_info[101].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[101].fileTimeLo = 1286797178U;
  c9_info[101].fileTimeHi = 0U;
  c9_info[101].mFileTimeLo = 0U;
  c9_info[101].mFileTimeHi = 0U;
  c9_info[102].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c9_info[102].name = "norm";
  c9_info[102].dominantType = "double";
  c9_info[102].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m";
  c9_info[102].fileTimeLo = 1286797226U;
  c9_info[102].fileTimeHi = 0U;
  c9_info[102].mFileTimeLo = 0U;
  c9_info[102].mFileTimeHi = 0U;
  c9_info[103].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c9_info[103].name = "abs";
  c9_info[103].dominantType = "double";
  c9_info[103].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c9_info[103].fileTimeLo = 1286797094U;
  c9_info[103].fileTimeHi = 0U;
  c9_info[103].mFileTimeLo = 0U;
  c9_info[103].mFileTimeHi = 0U;
  c9_info[104].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c9_info[104].name = "isnan";
  c9_info[104].dominantType = "double";
  c9_info[104].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c9_info[104].fileTimeLo = 1286797160U;
  c9_info[104].fileTimeHi = 0U;
  c9_info[104].mFileTimeLo = 0U;
  c9_info[104].mFileTimeHi = 0U;
  c9_info[105].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c9_info[105].name = "eml_guarded_nan";
  c9_info[105].dominantType = "char";
  c9_info[105].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c9_info[105].fileTimeLo = 1286797176U;
  c9_info[105].fileTimeHi = 0U;
  c9_info[105].mFileTimeLo = 0U;
  c9_info[105].mFileTimeHi = 0U;
  c9_info[106].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c9_info[106].name = "eml_is_float_class";
  c9_info[106].dominantType = "char";
  c9_info[106].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c9_info[106].fileTimeLo = 1286797182U;
  c9_info[106].fileTimeHi = 0U;
  c9_info[106].mFileTimeLo = 0U;
  c9_info[106].mFileTimeHi = 0U;
  c9_info[107].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c9_info[107].name = "mtimes";
  c9_info[107].dominantType = "double";
  c9_info[107].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[107].fileTimeLo = 1289494492U;
  c9_info[107].fileTimeHi = 0U;
  c9_info[107].mFileTimeLo = 0U;
  c9_info[107].mFileTimeHi = 0U;
  c9_info[108].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c9_info[108].name = "eml_warning";
  c9_info[108].dominantType = "char";
  c9_info[108].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c9_info[108].fileTimeLo = 1286797202U;
  c9_info[108].fileTimeHi = 0U;
  c9_info[108].mFileTimeLo = 0U;
  c9_info[108].mFileTimeHi = 0U;
  c9_info[109].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c9_info[109].name = "isnan";
  c9_info[109].dominantType = "double";
  c9_info[109].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c9_info[109].fileTimeLo = 1286797160U;
  c9_info[109].fileTimeHi = 0U;
  c9_info[109].mFileTimeLo = 0U;
  c9_info[109].mFileTimeHi = 0U;
  c9_info[110].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c9_info[110].name = "eps";
  c9_info[110].dominantType = "char";
  c9_info[110].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c9_info[110].fileTimeLo = 1307629640U;
  c9_info[110].fileTimeHi = 0U;
  c9_info[110].mFileTimeLo = 0U;
  c9_info[110].mFileTimeHi = 0U;
  c9_info[111].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c9_info[111].name = "eml_flt2str";
  c9_info[111].dominantType = "double";
  c9_info[111].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c9_info[111].fileTimeLo = 1309429596U;
  c9_info[111].fileTimeHi = 0U;
  c9_info[111].mFileTimeLo = 0U;
  c9_info[111].mFileTimeHi = 0U;
  c9_info[112].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c9_info[112].name = "char";
  c9_info[112].dominantType = "double";
  c9_info[112].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/strfun/char.m";
  c9_info[112].fileTimeLo = 1319708368U;
  c9_info[112].fileTimeHi = 0U;
  c9_info[112].mFileTimeLo = 0U;
  c9_info[112].mFileTimeHi = 0U;
  c9_info[113].context = "";
  c9_info[113].name = "mtimes";
  c9_info[113].dominantType = "double";
  c9_info[113].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[113].fileTimeLo = 1289494492U;
  c9_info[113].fileTimeHi = 0U;
  c9_info[113].mFileTimeLo = 0U;
  c9_info[113].mFileTimeHi = 0U;
  c9_info[114].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[114].name = "eml_index_class";
  c9_info[114].dominantType = "";
  c9_info[114].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[114].fileTimeLo = 1286797178U;
  c9_info[114].fileTimeHi = 0U;
  c9_info[114].mFileTimeLo = 0U;
  c9_info[114].mFileTimeHi = 0U;
  c9_info[115].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[115].name = "eml_scalar_eg";
  c9_info[115].dominantType = "double";
  c9_info[115].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[115].fileTimeLo = 1286797196U;
  c9_info[115].fileTimeHi = 0U;
  c9_info[115].mFileTimeLo = 0U;
  c9_info[115].mFileTimeHi = 0U;
  c9_info[116].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[116].name = "eml_xgemm";
  c9_info[116].dominantType = "int32";
  c9_info[116].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[116].fileTimeLo = 1299051572U;
  c9_info[116].fileTimeHi = 0U;
  c9_info[116].mFileTimeLo = 0U;
  c9_info[116].mFileTimeHi = 0U;
  c9_info[117].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[117].name = "eml_blas_inline";
  c9_info[117].dominantType = "";
  c9_info[117].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[117].fileTimeLo = 1299051568U;
  c9_info[117].fileTimeHi = 0U;
  c9_info[117].mFileTimeLo = 0U;
  c9_info[117].mFileTimeHi = 0U;
  c9_info[118].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c9_info[118].name = "mtimes";
  c9_info[118].dominantType = "double";
  c9_info[118].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[118].fileTimeLo = 1289494492U;
  c9_info[118].fileTimeHi = 0U;
  c9_info[118].mFileTimeLo = 0U;
  c9_info[118].mFileTimeHi = 0U;
  c9_info[119].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[119].name = "eml_scalar_eg";
  c9_info[119].dominantType = "double";
  c9_info[119].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[119].fileTimeLo = 1286797196U;
  c9_info[119].fileTimeHi = 0U;
  c9_info[119].mFileTimeLo = 0U;
  c9_info[119].mFileTimeHi = 0U;
  c9_info[120].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[120].name = "eml_refblas_xgemm";
  c9_info[120].dominantType = "int32";
  c9_info[120].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[120].fileTimeLo = 1299051574U;
  c9_info[120].fileTimeHi = 0U;
  c9_info[120].mFileTimeLo = 0U;
  c9_info[120].mFileTimeHi = 0U;
  c9_info[121].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[121].name = "eml_index_class";
  c9_info[121].dominantType = "";
  c9_info[121].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[121].fileTimeLo = 1286797178U;
  c9_info[121].fileTimeHi = 0U;
  c9_info[121].mFileTimeLo = 0U;
  c9_info[121].mFileTimeHi = 0U;
}

static void c9_invNxN(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
                      *chartInstance, real_T c9_x[3600], real_T c9_y[3600])
{
  int32_T c9_i52;
  int32_T c9_info;
  int32_T c9_ipiv[60];
  int32_T c9_i53;
  int32_T c9_b_ipiv[60];
  int32_T c9_k;
  int32_T c9_b_k;
  int32_T c9_c;
  int32_T c9_c_k;
  int32_T c9_j;
  int32_T c9_b_j;
  int32_T c9_a;
  int32_T c9_i54;
  int32_T c9_i;
  int32_T c9_b_i;
  real_T c9_b_a;
  real_T c9_b;
  real_T c9_b_y;
  int32_T c9_i55;
  real_T c9_b_x[3600];
  for (c9_i52 = 0; c9_i52 < 3600; c9_i52++) {
    c9_y[c9_i52] = 0.0;
  }

  c9_b_eml_matlab_zgetrf(chartInstance, c9_x, c9_ipiv, &c9_info);
  for (c9_i53 = 0; c9_i53 < 60; c9_i53++) {
    c9_b_ipiv[c9_i53] = c9_ipiv[c9_i53];
  }

  c9_eml_ipiv2perm(chartInstance, c9_b_ipiv, c9_ipiv);
  c9_c_eml_int_forloop_overflow_check(chartInstance);
  for (c9_k = 1; c9_k < 61; c9_k++) {
    c9_b_k = c9_k;
    c9_c = c9_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c9_b_k), 1, 60, 1, 0) - 1];
    c9_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c9_b_k), 1, 60, 1, 0) + 60 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_c), 1, 60, 2, 0) - 1)) -
      1] = 1.0;
    c9_c_k = c9_b_k;
    c9_d_eml_int_forloop_overflow_check(chartInstance, c9_c_k, 60);
    for (c9_j = c9_c_k; c9_j < 61; c9_j++) {
      c9_b_j = c9_j;
      if (c9_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c9_b_j), 1, 60, 1, 0) + 60 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
             "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_c), 1, 60, 2, 0) - 1))
          - 1] != 0.0) {
        c9_a = c9_b_j + 1;
        c9_i54 = c9_a;
        c9_d_eml_int_forloop_overflow_check(chartInstance, c9_i54, 60);
        for (c9_i = c9_i54; c9_i < 61; c9_i++) {
          c9_b_i = c9_i;
          c9_b_a = c9_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c9_b_j), 1, 60, 1, 0) + 60 *
                         (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c9_c), 1, 60, 2, 0) - 1)) - 1];
          c9_b = c9_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c9_b_i), 1, 60, 1, 0) + 60 *
                       (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c9_b_j), 1, 60, 2, 0) - 1)) - 1];
          c9_b_y = c9_b_a * c9_b;
          c9_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c9_b_i), 1, 60, 1, 0) + 60 *
                (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c9_c), 1, 60, 2, 0) - 1)) - 1] = c9_y
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c9_b_i), 1, 60, 1, 0) + 60 *
              (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c9_c), 1, 60, 2, 0) - 1)) - 1] - c9_b_y;
        }
      }
    }
  }

  c9_eml_scalar_eg(chartInstance);
  for (c9_i55 = 0; c9_i55 < 3600; c9_i55++) {
    c9_b_x[c9_i55] = c9_x[c9_i55];
  }

  c9_b_eml_xtrsm(chartInstance, c9_b_x, c9_y);
}

static void c9_eps(SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void c9_eml_matlab_zgetrf(SFc9_CtrPlatform_AdaptiveControlInstanceStruct *
  chartInstance, real_T c9_A[3600], real_T c9_b_A[3600], int32_T c9_ipiv[60],
  int32_T *c9_info)
{
  int32_T c9_i56;
  for (c9_i56 = 0; c9_i56 < 3600; c9_i56++) {
    c9_b_A[c9_i56] = c9_A[c9_i56];
  }

  c9_b_eml_matlab_zgetrf(chartInstance, c9_b_A, c9_ipiv, c9_info);
}

static void c9_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static boolean_T c9_eml_use_refblas
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  return FALSE;
}

static void c9_b_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c9_b)
{
  int32_T c9_b_b;
  boolean_T c9_overflow;
  boolean_T c9_safe;
  int32_T c9_i57;
  static char_T c9_cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c9_u[34];
  const mxArray *c9_y = NULL;
  int32_T c9_i58;
  static char_T c9_cv2[5] = { 'i', 'n', 't', '3', '2' };

  char_T c9_b_u[5];
  const mxArray *c9_b_y = NULL;
  c9_b_b = c9_b;
  if (2 > c9_b_b) {
    c9_overflow = FALSE;
  } else {
    c9_overflow = (c9_b_b > 2147483646);
  }

  c9_safe = !c9_overflow;
  if (c9_safe) {
  } else {
    for (c9_i57 = 0; c9_i57 < 34; c9_i57++) {
      c9_u[c9_i57] = c9_cv1[c9_i57];
    }

    c9_y = NULL;
    sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c9_i58 = 0; c9_i58 < 5; c9_i58++) {
      c9_b_u[c9_i58] = c9_cv2[c9_i58];
    }

    c9_b_y = NULL;
    sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c9_y, 14, c9_b_y));
  }
}

static void c9_eml_xswap(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_x[3600], int32_T c9_ix0, int32_T c9_iy0, real_T
  c9_b_x[3600])
{
  int32_T c9_i59;
  for (c9_i59 = 0; c9_i59 < 3600; c9_i59++) {
    c9_b_x[c9_i59] = c9_x[c9_i59];
  }

  c9_b_eml_xswap(chartInstance, c9_b_x, c9_ix0, c9_iy0);
}

static void c9_below_threshold(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c9_c_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void c9_d_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c9_a,
   int32_T c9_b)
{
  int32_T c9_b_a;
  int32_T c9_b_b;
  boolean_T c9_overflow;
  boolean_T c9_safe;
  int32_T c9_i60;
  static char_T c9_cv3[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c9_u[34];
  const mxArray *c9_y = NULL;
  int32_T c9_i61;
  static char_T c9_cv4[5] = { 'i', 'n', 't', '3', '2' };

  char_T c9_b_u[5];
  const mxArray *c9_b_y = NULL;
  c9_b_a = c9_a;
  c9_b_b = c9_b;
  if (c9_b_a > c9_b_b) {
    c9_overflow = FALSE;
  } else {
    c9_overflow = (c9_b_b > 2147483646);
  }

  c9_safe = !c9_overflow;
  if (c9_safe) {
  } else {
    for (c9_i60 = 0; c9_i60 < 34; c9_i60++) {
      c9_u[c9_i60] = c9_cv3[c9_i60];
    }

    c9_y = NULL;
    sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c9_i61 = 0; c9_i61 < 5; c9_i61++) {
      c9_b_u[c9_i61] = c9_cv4[c9_i61];
    }

    c9_b_y = NULL;
    sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c9_y, 14, c9_b_y));
  }
}

static void c9_eml_xger(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c9_m, int32_T c9_n, real_T c9_alpha1, int32_T c9_ix0,
  int32_T c9_iy0, real_T c9_A[3600], int32_T c9_ia0, real_T c9_b_A[3600])
{
  int32_T c9_i62;
  for (c9_i62 = 0; c9_i62 < 3600; c9_i62++) {
    c9_b_A[c9_i62] = c9_A[c9_i62];
  }

  c9_b_eml_xger(chartInstance, c9_m, c9_n, c9_alpha1, c9_ix0, c9_iy0, c9_b_A,
                c9_ia0);
}

static void c9_eml_ipiv2perm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c9_ipiv[60], int32_T c9_perm[60])
{
  int32_T c9_i63;
  int32_T c9_k;
  real_T c9_b_k;
  int32_T c9_ipk;
  int32_T c9_pipk;
  for (c9_i63 = 0; c9_i63 < 60; c9_i63++) {
    c9_perm[c9_i63] = 1 + c9_i63;
  }

  for (c9_k = 0; c9_k < 59; c9_k++) {
    c9_b_k = 1.0 + (real_T)c9_k;
    c9_ipk = c9_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", c9_b_k), 1, 60, 1, 0) - 1];
    if ((real_T)c9_ipk > c9_b_k) {
      c9_pipk = c9_perm[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c9_ipk), 1, 60, 1, 0) - 1];
      c9_perm[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c9_ipk), 1, 60, 1, 0) - 1] = c9_perm[_SFD_EML_ARRAY_BOUNDS_CHECK
        ("", (int32_T)_SFD_INTEGER_CHECK("", c9_b_k), 1, 60, 1, 0) - 1];
      c9_perm[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c9_b_k), 1, 60, 1, 0) - 1] = c9_pipk;
    }
  }
}

static void c9_eml_scalar_eg(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c9_eml_xtrsm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[3600], real_T c9_b_B[3600])
{
  int32_T c9_i64;
  int32_T c9_i65;
  real_T c9_b_A[3600];
  for (c9_i64 = 0; c9_i64 < 3600; c9_i64++) {
    c9_b_B[c9_i64] = c9_B[c9_i64];
  }

  for (c9_i65 = 0; c9_i65 < 3600; c9_i65++) {
    c9_b_A[c9_i65] = c9_A[c9_i65];
  }

  c9_b_eml_xtrsm(chartInstance, c9_b_A, c9_b_B);
}

static real_T c9_norm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
                      *chartInstance, real_T c9_x[3600])
{
  real_T c9_y;
  int32_T c9_j;
  real_T c9_b_j;
  real_T c9_s;
  int32_T c9_i;
  real_T c9_b_i;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_b_y;
  real_T c9_d_x;
  boolean_T c9_b;
  boolean_T exitg1;
  c9_y = 0.0;
  c9_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (c9_j < 60)) {
    c9_b_j = 1.0 + (real_T)c9_j;
    c9_s = 0.0;
    for (c9_i = 0; c9_i < 60; c9_i++) {
      c9_b_i = 1.0 + (real_T)c9_i;
      c9_b_x = c9_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c9_b_i), 1, 60, 1, 0) + 60 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c9_b_j), 1, 60, 2, 0) - 1)) - 1];
      c9_c_x = c9_b_x;
      c9_b_y = muDoubleScalarAbs(c9_c_x);
      c9_s += c9_b_y;
    }

    c9_d_x = c9_s;
    c9_b = muDoubleScalarIsNaN(c9_d_x);
    if (c9_b) {
      c9_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c9_s > c9_y) {
        c9_y = c9_s;
      }

      c9_j++;
    }
  }

  return c9_y;
}

static void c9_eml_warning(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
  int32_T c9_i66;
  static char_T c9_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c9_u[27];
  const mxArray *c9_y = NULL;
  for (c9_i66 = 0; c9_i66 < 27; c9_i66++) {
    c9_u[c9_i66] = c9_varargin_1[c9_i66];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c9_y));
}

static void c9_b_eml_warning(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, char_T c9_varargin_2[14])
{
  int32_T c9_i67;
  static char_T c9_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c9_u[33];
  const mxArray *c9_y = NULL;
  int32_T c9_i68;
  char_T c9_b_u[14];
  const mxArray *c9_b_y = NULL;
  for (c9_i67 = 0; c9_i67 < 33; c9_i67++) {
    c9_u[c9_i67] = c9_varargin_1[c9_i67];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c9_i68 = 0; c9_i68 < 14; c9_i68++) {
    c9_b_u[c9_i68] = c9_varargin_2[c9_i68];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c9_y, 14, c9_b_y));
}

static void c9_b_eml_scalar_eg(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c9_eml_xgemm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[360], real_T c9_C[360], real_T
  c9_b_C[360])
{
  int32_T c9_i69;
  int32_T c9_i70;
  real_T c9_b_A[3600];
  int32_T c9_i71;
  real_T c9_b_B[360];
  for (c9_i69 = 0; c9_i69 < 360; c9_i69++) {
    c9_b_C[c9_i69] = c9_C[c9_i69];
  }

  for (c9_i70 = 0; c9_i70 < 3600; c9_i70++) {
    c9_b_A[c9_i70] = c9_A[c9_i70];
  }

  for (c9_i71 = 0; c9_i71 < 360; c9_i71++) {
    c9_b_B[c9_i71] = c9_B[c9_i71];
  }

  c9_b_eml_xgemm(chartInstance, c9_b_A, c9_b_B, c9_b_C);
}

static void c9_c_eml_scalar_eg(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c9_d_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_sprintf, const char_T *c9_identifier, char_T
  c9_y[14])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_sprintf), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_sprintf);
}

static void c9_e_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  char_T c9_y[14])
{
  char_T c9_cv5[14];
  int32_T c9_i72;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_cv5, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c9_i72 = 0; c9_i72 < 14; c9_i72++) {
    c9_y[c9_i72] = c9_cv5[c9_i72];
  }

  sf_mex_destroy(&c9_u);
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_f_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i73;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i73, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i73;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_g_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_b_is_active_c9_CtrPlatform_AdaptiveControl, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_CtrPlatform_AdaptiveControl), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_CtrPlatform_AdaptiveControl);
  return c9_y;
}

static uint8_T c9_h_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_eml_matlab_zgetrf
  (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, real_T c9_A
   [3600], int32_T c9_ipiv[60], int32_T *c9_info)
{
  int32_T c9_i74;
  int32_T c9_j;
  int32_T c9_b_j;
  int32_T c9_a;
  int32_T c9_jm1;
  int32_T c9_b;
  int32_T c9_mmj;
  int32_T c9_b_a;
  int32_T c9_c;
  int32_T c9_b_b;
  int32_T c9_jj;
  int32_T c9_c_a;
  int32_T c9_jp1j;
  int32_T c9_d_a;
  int32_T c9_b_c;
  int32_T c9_n;
  int32_T c9_ix0;
  int32_T c9_b_n;
  int32_T c9_b_ix0;
  int32_T c9_c_n;
  int32_T c9_c_ix0;
  int32_T c9_idxmax;
  int32_T c9_ix;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_y;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_b_y;
  real_T c9_smax;
  int32_T c9_loop_ub;
  int32_T c9_k;
  int32_T c9_b_k;
  int32_T c9_e_a;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_c_y;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_d_y;
  real_T c9_s;
  int32_T c9_f_a;
  int32_T c9_jpiv_offset;
  int32_T c9_g_a;
  int32_T c9_c_b;
  int32_T c9_jpiv;
  int32_T c9_h_a;
  int32_T c9_d_b;
  int32_T c9_c_c;
  int32_T c9_e_b;
  int32_T c9_jrow;
  int32_T c9_i_a;
  int32_T c9_f_b;
  int32_T c9_jprow;
  int32_T c9_b_jp1j;
  int32_T c9_j_a;
  int32_T c9_d_c;
  int32_T c9_k_a;
  int32_T c9_g_b;
  int32_T c9_i75;
  int32_T c9_i;
  int32_T c9_b_i;
  real_T c9_k_x;
  real_T c9_e_y;
  real_T c9_z;
  int32_T c9_h_b;
  int32_T c9_e_c;
  int32_T c9_l_a;
  int32_T c9_f_c;
  int32_T c9_m_a;
  int32_T c9_g_c;
  int32_T c9_m;
  int32_T c9_d_n;
  int32_T c9_d_ix0;
  int32_T c9_iy0;
  int32_T c9_ia0;
  real_T c9_d1;
  c9_eps(chartInstance);
  for (c9_i74 = 0; c9_i74 < 60; c9_i74++) {
    c9_ipiv[c9_i74] = 1 + c9_i74;
  }

  *c9_info = 0;
  c9_eml_int_forloop_overflow_check(chartInstance);
  for (c9_j = 1; c9_j < 60; c9_j++) {
    c9_b_j = c9_j;
    c9_a = c9_b_j - 1;
    c9_jm1 = c9_a;
    c9_b = c9_b_j;
    c9_mmj = 60 - c9_b;
    c9_b_a = c9_jm1;
    c9_c = c9_b_a * 61;
    c9_b_b = c9_c + 1;
    c9_jj = c9_b_b;
    c9_c_a = c9_jj + 1;
    c9_jp1j = c9_c_a;
    c9_d_a = c9_mmj;
    c9_b_c = c9_d_a;
    c9_n = c9_b_c + 1;
    c9_ix0 = c9_jj;
    c9_b_n = c9_n;
    c9_b_ix0 = c9_ix0;
    c9_c_n = c9_b_n;
    c9_c_ix0 = c9_b_ix0;
    if ((real_T)c9_c_n < 1.0) {
      c9_idxmax = 0;
    } else {
      c9_idxmax = 1;
      if ((real_T)c9_c_n > 1.0) {
        c9_ix = c9_c_ix0;
        c9_x = c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c9_ix), 1, 3600, 1, 0) - 1];
        c9_b_x = c9_x;
        c9_c_x = c9_b_x;
        c9_y = muDoubleScalarAbs(c9_c_x);
        c9_d_x = 0.0;
        c9_e_x = c9_d_x;
        c9_b_y = muDoubleScalarAbs(c9_e_x);
        c9_smax = c9_y + c9_b_y;
        c9_b_eml_int_forloop_overflow_check(chartInstance, c9_c_n);
        c9_loop_ub = c9_c_n;
        for (c9_k = 2; c9_k <= c9_loop_ub; c9_k++) {
          c9_b_k = c9_k;
          c9_e_a = c9_ix + 1;
          c9_ix = c9_e_a;
          c9_f_x = c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c9_ix), 1, 3600, 1, 0) - 1];
          c9_g_x = c9_f_x;
          c9_h_x = c9_g_x;
          c9_c_y = muDoubleScalarAbs(c9_h_x);
          c9_i_x = 0.0;
          c9_j_x = c9_i_x;
          c9_d_y = muDoubleScalarAbs(c9_j_x);
          c9_s = c9_c_y + c9_d_y;
          if (c9_s > c9_smax) {
            c9_idxmax = c9_b_k;
            c9_smax = c9_s;
          }
        }
      }
    }

    c9_f_a = c9_idxmax - 1;
    c9_jpiv_offset = c9_f_a;
    c9_g_a = c9_jj;
    c9_c_b = c9_jpiv_offset;
    c9_jpiv = c9_g_a + c9_c_b;
    if (c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c9_jpiv), 1, 3600, 1, 0) - 1] != 0.0) {
      if ((real_T)c9_jpiv_offset != 0.0) {
        c9_h_a = c9_b_j;
        c9_d_b = c9_jpiv_offset;
        c9_c_c = c9_h_a + c9_d_b;
        c9_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c9_b_j), 1, 60, 1, 0) - 1] = c9_c_c;
        c9_e_b = c9_jm1 + 1;
        c9_jrow = c9_e_b;
        c9_i_a = c9_jrow;
        c9_f_b = c9_jpiv_offset;
        c9_jprow = c9_i_a + c9_f_b;
        c9_b_eml_xswap(chartInstance, c9_A, c9_jrow, c9_jprow);
      }

      c9_b_jp1j = c9_jp1j;
      c9_j_a = c9_mmj;
      c9_d_c = c9_j_a;
      c9_k_a = c9_jp1j;
      c9_g_b = c9_d_c - 1;
      c9_i75 = c9_k_a + c9_g_b;
      c9_d_eml_int_forloop_overflow_check(chartInstance, c9_b_jp1j, c9_i75);
      for (c9_i = c9_b_jp1j; c9_i <= c9_i75; c9_i++) {
        c9_b_i = c9_i;
        c9_k_x = c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_b_i), 1, 3600, 1, 0) - 1];
        c9_e_y = c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c9_jj), 1, 3600, 1, 0) - 1];
        c9_z = c9_k_x / c9_e_y;
        c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c9_b_i), 1, 3600, 1, 0) - 1] = c9_z;
      }
    } else {
      *c9_info = c9_b_j;
    }

    c9_h_b = c9_b_j;
    c9_e_c = 60 - c9_h_b;
    c9_l_a = c9_jj;
    c9_f_c = c9_l_a;
    c9_m_a = c9_jj;
    c9_g_c = c9_m_a;
    c9_m = c9_mmj;
    c9_d_n = c9_e_c;
    c9_d_ix0 = c9_jp1j;
    c9_iy0 = c9_f_c + 60;
    c9_ia0 = c9_g_c + 61;
    c9_d1 = -1.0;
    c9_b_eml_xger(chartInstance, c9_m, c9_d_n, c9_d1, c9_d_ix0, c9_iy0, c9_A,
                  c9_ia0);
  }

  if ((real_T)*c9_info == 0.0) {
    if (!(c9_A[3599] != 0.0)) {
      *c9_info = 60;
    }
  }
}

static void c9_b_eml_xswap(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_x[3600], int32_T c9_ix0, int32_T c9_iy0)
{
  int32_T c9_b_ix0;
  int32_T c9_b_iy0;
  int32_T c9_c_ix0;
  int32_T c9_c_iy0;
  int32_T c9_ix;
  int32_T c9_iy;
  int32_T c9_k;
  real_T c9_temp;
  int32_T c9_a;
  int32_T c9_b_a;
  c9_b_ix0 = c9_ix0;
  c9_b_iy0 = c9_iy0;
  if (c9_eml_use_refblas(chartInstance)) {
  } else {
    c9_below_threshold(chartInstance);
  }

  c9_c_ix0 = c9_b_ix0;
  c9_c_iy0 = c9_b_iy0;
  c9_ix = c9_c_ix0;
  c9_iy = c9_c_iy0;
  c9_c_eml_int_forloop_overflow_check(chartInstance);
  for (c9_k = 1; c9_k < 61; c9_k++) {
    c9_temp = c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c9_ix), 1, 3600, 1, 0) - 1];
    c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c9_ix), 1, 3600, 1, 0) - 1] = c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_iy), 1, 3600, 1, 0) - 1];
    c9_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c9_iy), 1, 3600, 1, 0) - 1] = c9_temp;
    c9_a = c9_ix + 60;
    c9_ix = c9_a;
    c9_b_a = c9_iy + 60;
    c9_iy = c9_b_a;
  }
}

static void c9_b_eml_xger(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c9_m, int32_T c9_n, real_T c9_alpha1, int32_T c9_ix0,
  int32_T c9_iy0, real_T c9_A[3600], int32_T c9_ia0)
{
  int32_T c9_b_m;
  int32_T c9_b_n;
  real_T c9_b_alpha1;
  int32_T c9_b_ix0;
  int32_T c9_b_iy0;
  int32_T c9_b_ia0;
  int32_T c9_c_m;
  int32_T c9_c_n;
  real_T c9_c_alpha1;
  int32_T c9_c_ix0;
  int32_T c9_incx;
  int32_T c9_c_iy0;
  int32_T c9_incy;
  int32_T c9_c_ia0;
  int32_T c9_lda;
  c9_b_m = c9_m;
  c9_b_n = c9_n;
  c9_b_alpha1 = c9_alpha1;
  c9_b_ix0 = c9_ix0;
  c9_b_iy0 = c9_iy0;
  c9_b_ia0 = c9_ia0;
  if (c9_b_m < 1) {
  } else if (c9_b_n < 1) {
  } else {
    c9_c_m = c9_b_m;
    c9_c_n = c9_b_n;
    c9_c_alpha1 = c9_b_alpha1;
    c9_c_ix0 = c9_b_ix0;
    c9_incx = 1;
    c9_c_iy0 = c9_b_iy0;
    c9_incy = 60;
    c9_c_ia0 = c9_b_ia0;
    c9_lda = 60;
    dger32(&c9_c_m, &c9_c_n, &c9_c_alpha1, &c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_c_ix0), 1, 3600, 1, 0) -
           1], &c9_incx, &c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c9_c_iy0), 1, 3600, 1, 0) - 1],
           &c9_incy, &c9_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c9_c_ia0), 1, 3600, 1, 0) - 1],
           &c9_lda);
  }
}

static void c9_b_eml_xtrsm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[3600])
{
  int32_T c9_m;
  int32_T c9_n;
  real_T c9_alpha1;
  int32_T c9_lda;
  int32_T c9_ldb;
  char_T c9_SIDE;
  char_T c9_UPLO;
  char_T c9_TRANSA;
  char_T c9_DIAGA;
  c9_m = 60;
  c9_n = 60;
  c9_alpha1 = 1.0;
  c9_lda = 60;
  c9_ldb = 60;
  c9_SIDE = 'L';
  c9_UPLO = 'U';
  c9_TRANSA = 'N';
  c9_DIAGA = 'N';
  dtrsm32(&c9_SIDE, &c9_UPLO, &c9_TRANSA, &c9_DIAGA, &c9_m, &c9_n, &c9_alpha1,
          &c9_A[0], &c9_lda, &c9_B[0], &c9_ldb);
}

static void c9_b_eml_xgemm(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c9_A[3600], real_T c9_B[360], real_T c9_C[360])
{
  int32_T c9_m;
  int32_T c9_n;
  int32_T c9_k;
  real_T c9_alpha1;
  int32_T c9_lda;
  int32_T c9_ldb;
  real_T c9_beta1;
  int32_T c9_ldc;
  char_T c9_TRANSA;
  char_T c9_TRANSB;
  c9_m = 60;
  c9_n = 6;
  c9_k = 60;
  c9_alpha1 = 1.0;
  c9_lda = 60;
  c9_ldb = 60;
  c9_beta1 = 0.0;
  c9_ldc = 60;
  c9_TRANSA = 'N';
  c9_TRANSB = 'N';
  dgemm32(&c9_TRANSA, &c9_TRANSB, &c9_m, &c9_n, &c9_k, &c9_alpha1, &c9_A[0],
          &c9_lda, &c9_B[0], &c9_ldb, &c9_beta1, &c9_C[0], &c9_ldc);
}

static void init_dsm_address_info(SFc9_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_CtrPlatform_AdaptiveControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3046604881U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3933261076U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2888040539U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1017098659U);
}

mxArray *sf_c9_CtrPlatform_AdaptiveControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("KD5PEBU6qMWW0pwUd7MH1G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(60);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(60);
      pr[1] = (double)(60);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(60);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[10],T\"py1\",},{M[8],M[0],T\"is_active_c9_CtrPlatform_AdaptiveControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_CtrPlatform_AdaptiveControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
    chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_AdaptiveControlMachineNumber_,
           9,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_CtrPlatform_AdaptiveControlMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_CtrPlatform_AdaptiveControlMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_CtrPlatform_AdaptiveControlMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Y");
          _SFD_SET_DATA_PROPS(1,1,1,0,"sigma");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Kpi");
          _SFD_SET_DATA_PROPS(3,2,0,1,"py1");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,68);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 60;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 60;
          dimVector[1]= 60;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 60;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          real_T (*c9_Y)[360];
          real_T (*c9_sigma)[6];
          real_T (*c9_Kpi)[3600];
          real_T (*c9_py1)[60];
          c9_py1 = (real_T (*)[60])ssGetOutputPortSignal(chartInstance->S, 1);
          c9_Kpi = (real_T (*)[3600])ssGetInputPortSignal(chartInstance->S, 2);
          c9_sigma = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c9_Y = (real_T (*)[360])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_Y);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_sigma);
          _SFD_SET_DATA_VALUE_PTR(2U, *c9_Kpi);
          _SFD_SET_DATA_VALUE_PTR(3U, *c9_py1);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_CtrPlatform_AdaptiveControlMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "PZyTcuRFtFN9zrks1XfPlG";
}

static void sf_opaque_initialize_c9_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
  initialize_c9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  enable_c9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  disable_c9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  sf_c9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_CtrPlatform_AdaptiveControl
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c9_CtrPlatform_AdaptiveControl(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_CtrPlatform_AdaptiveControl
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c9_CtrPlatform_AdaptiveControl(S);
}

static void sf_opaque_set_sim_state_c9_CtrPlatform_AdaptiveControl(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c9_CtrPlatform_AdaptiveControl(S, st);
}

static void sf_opaque_terminate_c9_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_CtrPlatform_AdaptiveControl
      ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_AdaptiveControl_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_CtrPlatform_AdaptiveControl
    ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_CtrPlatform_AdaptiveControl
      ((SFc9_CtrPlatform_AdaptiveControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CtrPlatform_AdaptiveControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1678922591U));
  ssSetChecksum1(S,(2711875916U));
  ssSetChecksum2(S,(1940957245U));
  ssSetChecksum3(S,(1136910428U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  SFc9_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControlInstanceStruct *)malloc
    (sizeof(SFc9_CtrPlatform_AdaptiveControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_CtrPlatform_AdaptiveControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c9_CtrPlatform_AdaptiveControl_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_CtrPlatform_AdaptiveControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_CtrPlatform_AdaptiveControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_CtrPlatform_AdaptiveControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_CtrPlatform_AdaptiveControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
