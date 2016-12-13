/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_AdaptiveControl_sfun.h"
#include "c2_CtrPlatform_AdaptiveControl.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_AdaptiveControl_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[10] = { "V", "g", "Jb", "Adg_inv",
  "nargin", "nargout", "Theta", "EndVel", "L", "Omega" };

static const char * c2_b_debug_family_names[68] = { "A1", "A2", "A3", "A4", "A5",
  "A6", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t2", "t3", "t4",
  "t5", "t6", "t7", "t8", "t9", "t10", "t11", "t12", "t13", "t14", "t23", "t15",
  "t16", "t17", "t18", "t19", "t20", "t21", "t22", "t24", "t25", "t26", "t27",
  "t34", "t28", "t29", "t30", "t31", "t32", "t36", "t33", "t35", "t37", "t38",
  "t39", "t40", "t41", "t42", "t43", "t44", "t45", "t47", "t46", "t48", "t49",
  "nargin", "nargout", "in1", "in2", "gst" };

static const char * c2_c_debug_family_names[49] = { "A2", "A3", "A4", "A5", "A6",
  "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t52", "t53", "t54", "t55",
  "t56", "t57", "t58", "t59", "t60", "t61", "t62", "t63", "t64", "t65", "t66",
  "t67", "t68", "t69", "t70", "t71", "t72", "t73", "t74", "t75", "t76", "t77",
  "t78", "t79", "t80", "t81", "t82", "nargin", "nargout", "in1", "in2",
  "body_Jacobian" };

static const char * c2_d_debug_family_names[4] = { "nargin", "nargout", "w",
  "wh" };

static const char * c2_e_debug_family_names[7] = { "RT", "p", "ze", "nargin",
  "nargout", "g", "Adg_inv" };

/* Function Declarations */
static void initialize_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void initialize_params_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void enable_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void disable_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void set_sim_state_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_st);
static void finalize_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void sf_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c2_chartstep_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void initSimStructsc2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_Omega, const char_T *c2_identifier, real_T
  c2_y[6]);
static void c2_b_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_d_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[36]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_f_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_g_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_i_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[135]);
static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[135]);
static void c2_c_info_helper(c2_ResolvedFunctionInfo c2_info[135]);
static void c2_fwd_kin(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_in1[9], real_T c2_in2[6], real_T c2_gst[16]);
static void c2_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c2_body_Jacobian(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_in1[9], real_T c2_in2[6], real_T c2_b_body_Jacobian
  [36]);
static void c2_b_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c2_AdjointInv(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_g[16], real_T c2_Adg_inv[36]);
static void c2_eml_scalar_eg(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c2_mldivide(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_A[36], real_T c2_B[36], real_T c2_Y[36]);
static void c2_realmin(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c2_eps(SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c2_eml_matlab_zgetrf(SFc2_CtrPlatform_AdaptiveControlInstanceStruct *
  chartInstance, real_T c2_A[36], real_T c2_b_A[36], int32_T c2_ipiv[6], int32_T
  *c2_info);
static void c2_c_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static int32_T c2_eml_ixamax(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[36], int32_T c2_ix0);
static void c2_d_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c2_b);
static void c2_e_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c2_f_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c2_a,
   int32_T c2_b);
static void c2_eml_warning(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c2_eml_xtrsm(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_A[36], real_T c2_B[36], real_T c2_b_B[36]);
static void c2_below_threshold(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c2_b_eml_scalar_eg(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static void c2_g_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c2_c_eml_scalar_eg(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_j_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_k_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_b_is_active_c2_CtrPlatform_AdaptiveControl, const char_T *c2_identifier);
static uint8_T c2_l_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_eml_matlab_zgetrf
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, real_T c2_A[36],
   int32_T c2_ipiv[6], int32_T *c2_info);
static void c2_b_eml_xtrsm(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_A[36], real_T c2_B[36]);
static void init_dsm_address_info(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_CtrPlatform_AdaptiveControl = 0U;
}

static void initialize_params_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  real_T c2_dv0[9];
  int32_T c2_i0;
  sf_set_error_prefix_string(
    "Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import_named("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c2_dv0,
                      0, 0, 0U, 1, 0U, 2, 1, 9);
  for (c2_i0 = 0; c2_i0 < 9; c2_i0++) {
    chartInstance->c2_L[c2_i0] = c2_dv0[c2_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i1;
  real_T c2_u[6];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T (*c2_Omega)[6];
  c2_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    c2_u[c2_i1] = (*c2_Omega)[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_CtrPlatform_AdaptiveControl;
  c2_b_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv1[6];
  int32_T c2_i2;
  real_T (*c2_Omega)[6];
  c2_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
                      "Omega", c2_dv1);
  for (c2_i2 = 0; c2_i2 < 6; c2_i2++) {
    (*c2_Omega)[c2_i2] = c2_dv1[c2_i2];
  }

  chartInstance->c2_is_active_c2_CtrPlatform_AdaptiveControl =
    c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
    "is_active_c2_CtrPlatform_AdaptiveControl");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_CtrPlatform_AdaptiveControl(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void sf_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  real_T (*c2_EndVel)[3];
  real_T (*c2_Omega)[6];
  real_T (*c2_Theta)[6];
  c2_EndVel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c2_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i3 = 0; c2_i3 < 6; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_Theta)[c2_i3], 0U);
  }

  for (c2_i4 = 0; c2_i4 < 6; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_Omega)[c2_i4], 1U);
  }

  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_EndVel)[c2_i5], 2U);
  }

  for (c2_i6 = 0; c2_i6 < 9; c2_i6++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_L[c2_i6], 3U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_CtrPlatform_AdaptiveControl(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_AdaptiveControlMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  int32_T c2_i7;
  real_T c2_Theta[6];
  int32_T c2_i8;
  real_T c2_EndVel[3];
  int32_T c2_i9;
  real_T c2_b_L[9];
  uint32_T c2_debug_family_var_map[10];
  real_T c2_V[6];
  real_T c2_g[16];
  real_T c2_Jb[36];
  real_T c2_Adg_inv[36];
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 1.0;
  real_T c2_Omega[6];
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  real_T c2_c_L[9];
  int32_T c2_i13;
  real_T c2_b_Theta[6];
  real_T c2_dv2[16];
  int32_T c2_i14;
  int32_T c2_i15;
  real_T c2_d_L[9];
  int32_T c2_i16;
  real_T c2_c_Theta[6];
  real_T c2_dv3[36];
  int32_T c2_i17;
  int32_T c2_i18;
  real_T c2_b_g[16];
  real_T c2_dv4[36];
  int32_T c2_i19;
  int32_T c2_i20;
  real_T c2_b_Jb[36];
  int32_T c2_i21;
  real_T c2_b_Adg_inv[36];
  real_T c2_a[36];
  int32_T c2_i22;
  real_T c2_b[6];
  int32_T c2_i23;
  real_T c2_y[6];
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  real_T (*c2_b_Omega)[6];
  real_T (*c2_b_EndVel)[3];
  real_T (*c2_d_Theta)[6];
  c2_b_EndVel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c2_d_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i7 = 0; c2_i7 < 6; c2_i7++) {
    c2_Theta[c2_i7] = (*c2_d_Theta)[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_EndVel[c2_i8] = (*c2_b_EndVel)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 9; c2_i9++) {
    c2_b_L[c2_i9] = chartInstance->c2_L[c2_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_V, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_g, 1U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Jb, 2U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Adg_inv, 3U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 4U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 5U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_Theta, 6U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_EndVel, 7U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c2_b_L, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Omega, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i10 = 0; c2_i10 < 6; c2_i10++) {
    c2_Omega[c2_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
    c2_V[c2_i11] = c2_EndVel[c2_i11];
  }

  c2_V[3] = 0.0;
  c2_V[4] = 0.0;
  c2_V[5] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 6);
  for (c2_i12 = 0; c2_i12 < 9; c2_i12++) {
    c2_c_L[c2_i12] = c2_b_L[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 6; c2_i13++) {
    c2_b_Theta[c2_i13] = c2_Theta[c2_i13];
  }

  c2_fwd_kin(chartInstance, c2_c_L, c2_b_Theta, c2_dv2);
  for (c2_i14 = 0; c2_i14 < 16; c2_i14++) {
    c2_g[c2_i14] = c2_dv2[c2_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 7);
  for (c2_i15 = 0; c2_i15 < 9; c2_i15++) {
    c2_d_L[c2_i15] = c2_b_L[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 6; c2_i16++) {
    c2_c_Theta[c2_i16] = c2_Theta[c2_i16];
  }

  c2_body_Jacobian(chartInstance, c2_d_L, c2_c_Theta, c2_dv3);
  for (c2_i17 = 0; c2_i17 < 36; c2_i17++) {
    c2_Jb[c2_i17] = c2_dv3[c2_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i18 = 0; c2_i18 < 16; c2_i18++) {
    c2_b_g[c2_i18] = c2_g[c2_i18];
  }

  c2_AdjointInv(chartInstance, c2_b_g, c2_dv4);
  for (c2_i19 = 0; c2_i19 < 36; c2_i19++) {
    c2_Adg_inv[c2_i19] = c2_dv4[c2_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  for (c2_i20 = 0; c2_i20 < 36; c2_i20++) {
    c2_b_Jb[c2_i20] = c2_Jb[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 36; c2_i21++) {
    c2_b_Adg_inv[c2_i21] = c2_Adg_inv[c2_i21];
  }

  c2_mldivide(chartInstance, c2_b_Jb, c2_b_Adg_inv, c2_a);
  for (c2_i22 = 0; c2_i22 < 6; c2_i22++) {
    c2_b[c2_i22] = c2_V[c2_i22];
  }

  c2_c_eml_scalar_eg(chartInstance);
  c2_c_eml_scalar_eg(chartInstance);
  for (c2_i23 = 0; c2_i23 < 6; c2_i23++) {
    c2_y[c2_i23] = 0.0;
    c2_i24 = 0;
    for (c2_i25 = 0; c2_i25 < 6; c2_i25++) {
      c2_y[c2_i23] += c2_a[c2_i24 + c2_i23] * c2_b[c2_i25];
      c2_i24 += 6;
    }
  }

  for (c2_i26 = 0; c2_i26 < 6; c2_i26++) {
    c2_Omega[c2_i26] = c2_y[c2_i26];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  for (c2_i27 = 0; c2_i27 < 6; c2_i27++) {
    (*c2_b_Omega)[c2_i27] = c2_Omega[c2_i27];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_CtrPlatform_AdaptiveControl
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 0U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/fwd_kin.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 1U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/body_Jacobian.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 2U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/AdjointInv.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, 3U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/skew.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i28;
  real_T c2_b_inData[6];
  int32_T c2_i29;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i28 = 0; c2_i28 < 6; c2_i28++) {
    c2_b_inData[c2_i28] = (*(real_T (*)[6])c2_inData)[c2_i28];
  }

  for (c2_i29 = 0; c2_i29 < 6; c2_i29++) {
    c2_u[c2_i29] = c2_b_inData[c2_i29];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_Omega, const char_T *c2_identifier, real_T
  c2_y[6])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Omega), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Omega);
}

static void c2_b_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6])
{
  real_T c2_dv5[6];
  int32_T c2_i30;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv5, 1, 0, 0U, 1, 0U, 1, 6);
  for (c2_i30 = 0; c2_i30 < 6; c2_i30++) {
    c2_y[c2_i30] = c2_dv5[c2_i30];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Omega;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i31;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_Omega = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Omega), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Omega);
  for (c2_i31 = 0; c2_i31 < 6; c2_i31++) {
    (*(real_T (*)[6])c2_outData)[c2_i31] = c2_y[c2_i31];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i32;
  real_T c2_b_inData[9];
  int32_T c2_i33;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i32 = 0; c2_i32 < 9; c2_i32++) {
    c2_b_inData[c2_i32] = (*(real_T (*)[9])c2_inData)[c2_i32];
  }

  for (c2_i33 = 0; c2_i33 < 9; c2_i33++) {
    c2_u[c2_i33] = c2_b_inData[c2_i33];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9])
{
  real_T c2_dv6[9];
  int32_T c2_i34;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv6, 1, 0, 0U, 1, 0U, 2, 1, 9);
  for (c2_i34 = 0; c2_i34 < 9; c2_i34++) {
    c2_y[c2_i34] = c2_dv6[c2_i34];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_L;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i35;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_b_L = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_L), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_L);
  for (c2_i35 = 0; c2_i35 < 9; c2_i35++) {
    (*(real_T (*)[9])c2_outData)[c2_i35] = c2_y[c2_i35];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i36;
  real_T c2_b_inData[3];
  int32_T c2_i37;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i36 = 0; c2_i36 < 3; c2_i36++) {
    c2_b_inData[c2_i36] = (*(real_T (*)[3])c2_inData)[c2_i36];
  }

  for (c2_i37 = 0; c2_i37 < 3; c2_i37++) {
    c2_u[c2_i37] = c2_b_inData[c2_i37];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_d_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_nargout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_nargout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_nargout), &c2_thisId);
  sf_mex_destroy(&c2_nargout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  real_T c2_b_inData[36];
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  real_T c2_u[36];
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i38 = 0;
  for (c2_i39 = 0; c2_i39 < 6; c2_i39++) {
    for (c2_i40 = 0; c2_i40 < 6; c2_i40++) {
      c2_b_inData[c2_i40 + c2_i38] = (*(real_T (*)[36])c2_inData)[c2_i40 +
        c2_i38];
    }

    c2_i38 += 6;
  }

  c2_i41 = 0;
  for (c2_i42 = 0; c2_i42 < 6; c2_i42++) {
    for (c2_i43 = 0; c2_i43 < 6; c2_i43++) {
      c2_u[c2_i43 + c2_i41] = c2_b_inData[c2_i43 + c2_i41];
    }

    c2_i41 += 6;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[36])
{
  real_T c2_dv7[36];
  int32_T c2_i44;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv7, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c2_i44 = 0; c2_i44 < 36; c2_i44++) {
    c2_y[c2_i44] = c2_dv7[c2_i44];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Adg_inv;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[36];
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_Adg_inv = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Adg_inv), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Adg_inv);
  c2_i45 = 0;
  for (c2_i46 = 0; c2_i46 < 6; c2_i46++) {
    for (c2_i47 = 0; c2_i47 < 6; c2_i47++) {
      (*(real_T (*)[36])c2_outData)[c2_i47 + c2_i45] = c2_y[c2_i47 + c2_i45];
    }

    c2_i45 += 6;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_b_inData[16];
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  real_T c2_u[16];
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i48 = 0;
  for (c2_i49 = 0; c2_i49 < 4; c2_i49++) {
    for (c2_i50 = 0; c2_i50 < 4; c2_i50++) {
      c2_b_inData[c2_i50 + c2_i48] = (*(real_T (*)[16])c2_inData)[c2_i50 +
        c2_i48];
    }

    c2_i48 += 4;
  }

  c2_i51 = 0;
  for (c2_i52 = 0; c2_i52 < 4; c2_i52++) {
    for (c2_i53 = 0; c2_i53 < 4; c2_i53++) {
      c2_u[c2_i53 + c2_i51] = c2_b_inData[c2_i53 + c2_i51];
    }

    c2_i51 += 4;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_f_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_dv8[16];
  int32_T c2_i54;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv8, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c2_i54 = 0; c2_i54 < 16; c2_i54++) {
    c2_y[c2_i54] = c2_dv8[c2_i54];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_g;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_g = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_g), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_g);
  c2_i55 = 0;
  for (c2_i56 = 0; c2_i56 < 4; c2_i56++) {
    for (c2_i57 = 0; c2_i57 < 4; c2_i57++) {
      (*(real_T (*)[16])c2_outData)[c2_i57 + c2_i55] = c2_y[c2_i57 + c2_i55];
    }

    c2_i55 += 4;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i58;
  real_T c2_b_inData[6];
  int32_T c2_i59;
  real_T c2_u[6];
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i58 = 0; c2_i58 < 6; c2_i58++) {
    c2_b_inData[c2_i58] = (*(real_T (*)[6])c2_inData)[c2_i58];
  }

  for (c2_i59 = 0; c2_i59 < 6; c2_i59++) {
    c2_u[c2_i59] = c2_b_inData[c2_i59];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_g_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[6])
{
  real_T c2_dv9[6];
  int32_T c2_i60;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv9, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c2_i60 = 0; c2_i60 < 6; c2_i60++) {
    c2_y[c2_i60] = c2_dv9[c2_i60];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_in2;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[6];
  int32_T c2_i61;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_in2 = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_in2), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_in2);
  for (c2_i61 = 0; c2_i61 < 6; c2_i61++) {
    (*(real_T (*)[6])c2_outData)[c2_i61] = c2_y[c2_i61];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  real_T c2_b_inData[9];
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  real_T c2_u[9];
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i62 = 0;
  for (c2_i63 = 0; c2_i63 < 3; c2_i63++) {
    for (c2_i64 = 0; c2_i64 < 3; c2_i64++) {
      c2_b_inData[c2_i64 + c2_i62] = (*(real_T (*)[9])c2_inData)[c2_i64 + c2_i62];
    }

    c2_i62 += 3;
  }

  c2_i65 = 0;
  for (c2_i66 = 0; c2_i66 < 3; c2_i66++) {
    for (c2_i67 = 0; c2_i67 < 3; c2_i67++) {
      c2_u[c2_i67 + c2_i65] = c2_b_inData[c2_i67 + c2_i65];
    }

    c2_i65 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[9])
{
  real_T c2_dv10[9];
  int32_T c2_i68;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv10, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c2_i68 = 0; c2_i68 < 9; c2_i68++) {
    c2_y[c2_i68] = c2_dv10[c2_i68];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_wh;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[9];
  int32_T c2_i69;
  int32_T c2_i70;
  int32_T c2_i71;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_wh = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_wh), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_wh);
  c2_i69 = 0;
  for (c2_i70 = 0; c2_i70 < 3; c2_i70++) {
    for (c2_i71 = 0; c2_i71 < 3; c2_i71++) {
      (*(real_T (*)[9])c2_outData)[c2_i71 + c2_i69] = c2_y[c2_i71 + c2_i69];
    }

    c2_i69 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_i_emlrt_marshallIn(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv11[3];
  int32_T c2_i72;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv11, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i72 = 0; c2_i72 < 3; c2_i72++) {
    c2_y[c2_i72] = c2_dv11[c2_i72];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_w;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i73;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_w = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_w), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_w);
  for (c2_i73 = 0; c2_i73 < 3; c2_i73++) {
    (*(real_T (*)[3])c2_outData)[c2_i73] = c2_y[c2_i73];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_CtrPlatform_AdaptiveControl_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[135];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i74;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  c2_b_info_helper(c2_info);
  c2_c_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 135), FALSE);
  for (c2_i74 = 0; c2_i74 < 135; c2_i74++) {
    c2_r0 = &c2_info[c2_i74];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i74);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i74);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i74);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i74);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i74);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i74);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i74);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i74);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[135])
{
  c2_info[0].context = "";
  c2_info[0].name = "fwd_kin";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c2_info[0].fileTimeLo = 1366778960U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c2_info[1].name = "cos";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[1].fileTimeLo = 1286797106U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[2].name = "eml_scalar_cos";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c2_info[2].fileTimeLo = 1286797122U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c2_info[3].name = "sin";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[3].fileTimeLo = 1286797150U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[4].name = "eml_scalar_sin";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c2_info[4].fileTimeLo = 1286797136U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c2_info[5].name = "reshape";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c2_info[5].fileTimeLo = 1286797168U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c2_info[6].name = "eml_index_class";
  c2_info[6].dominantType = "";
  c2_info[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[6].fileTimeLo = 1286797178U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c2_info[7].name = "eml_index_class";
  c2_info[7].dominantType = "";
  c2_info[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[7].fileTimeLo = 1286797178U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c2_info[8].name = "eml_assert_valid_size_arg";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[8].fileTimeLo = 1286797094U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c2_info[9].name = "isinf";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c2_info[9].fileTimeLo = 1286797160U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c2_info[10].name = "mtimes";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].fileTimeLo = 1289494492U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[11].name = "eml_index_class";
  c2_info[11].dominantType = "";
  c2_info[11].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[11].fileTimeLo = 1286797178U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c2_info[12].name = "intmax";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[12].fileTimeLo = 1311233716U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c2_info[13].name = "eml_scalar_eg";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[13].fileTimeLo = 1286797196U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c2_info[14].name = "eml_int_forloop_overflow_check";
  c2_info[14].dominantType = "";
  c2_info[14].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[14].fileTimeLo = 1311233716U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[15].name = "intmax";
  c2_info[15].dominantType = "char";
  c2_info[15].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[15].fileTimeLo = 1311233716U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context = "";
  c2_info[16].name = "body_Jacobian";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/body_Jacobian.m";
  c2_info[16].fileTimeLo = 1366807406U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/body_Jacobian.m";
  c2_info[17].name = "sin";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c2_info[17].fileTimeLo = 1286797150U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/body_Jacobian.m";
  c2_info[18].name = "cos";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c2_info[18].fileTimeLo = 1286797106U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/body_Jacobian.m";
  c2_info[19].name = "reshape";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c2_info[19].fileTimeLo = 1286797168U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context = "";
  c2_info[20].name = "AdjointInv";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/AdjointInv.m";
  c2_info[20].fileTimeLo = 1435137994U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/AdjointInv.m";
  c2_info[21].name = "any";
  c2_info[21].dominantType = "logical";
  c2_info[21].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/any.m";
  c2_info[21].fileTimeLo = 1286797234U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/any.m";
  c2_info[22].name = "eml_all_or_any";
  c2_info[22].dominantType = "char";
  c2_info[22].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[22].fileTimeLo = 1286797094U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[23].name = "isequal";
  c2_info[23].dominantType = "double";
  c2_info[23].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[23].fileTimeLo = 1286797158U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[24].name = "eml_isequal_core";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[24].fileTimeLo = 1286797186U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[25].name = "eml_const_nonsingleton_dim";
  c2_info[25].dominantType = "logical";
  c2_info[25].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[25].fileTimeLo = 1286797096U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c2_info[26].name = "isnan";
  c2_info[26].dominantType = "logical";
  c2_info[26].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[26].fileTimeLo = 1286797160U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/AdjointInv.m";
  c2_info[27].name = "skew";
  c2_info[27].dominantType = "double";
  c2_info[27].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/skew.m";
  c2_info[27].fileTimeLo = 1399884446U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/skew.m";
  c2_info[28].name = "length";
  c2_info[28].dominantType = "double";
  c2_info[28].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[28].fileTimeLo = 1303124606U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/AdjointInv.m";
  c2_info[29].name = "mtimes";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[29].fileTimeLo = 1289494492U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[30].name = "eml_index_class";
  c2_info[30].dominantType = "";
  c2_info[30].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[30].fileTimeLo = 1286797178U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[31].name = "eml_scalar_eg";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[31].fileTimeLo = 1286797196U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[32].name = "eml_xgemm";
  c2_info[32].dominantType = "int32";
  c2_info[32].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[32].fileTimeLo = 1299051572U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c2_info[33].name = "eml_blas_inline";
  c2_info[33].dominantType = "";
  c2_info[33].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[33].fileTimeLo = 1299051568U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c2_info[34].name = "mtimes";
  c2_info[34].dominantType = "double";
  c2_info[34].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[34].fileTimeLo = 1289494492U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[35].name = "eml_scalar_eg";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[35].fileTimeLo = 1286797196U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c2_info[36].name = "eml_refblas_xgemm";
  c2_info[36].dominantType = "int32";
  c2_info[36].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c2_info[36].fileTimeLo = 1299051574U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context = "";
  c2_info[37].name = "mldivide";
  c2_info[37].dominantType = "double";
  c2_info[37].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[37].fileTimeLo = 1325098938U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 1319708366U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mldivide.p";
  c2_info[38].name = "eml_lusolve";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[38].fileTimeLo = 1309429596U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c2_info[39].name = "eml_index_class";
  c2_info[39].dominantType = "";
  c2_info[39].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[39].fileTimeLo = 1286797178U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[40].name = "eml_index_class";
  c2_info[40].dominantType = "";
  c2_info[40].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[40].fileTimeLo = 1286797178U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[41].name = "eml_xgetrf";
  c2_info[41].dominantType = "int32";
  c2_info[41].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c2_info[41].fileTimeLo = 1286797206U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c2_info[42].name = "eml_lapack_xgetrf";
  c2_info[42].dominantType = "int32";
  c2_info[42].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c2_info[42].fileTimeLo = 1286797210U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c2_info[43].name = "eml_matlab_zgetrf";
  c2_info[43].dominantType = "int32";
  c2_info[43].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[43].fileTimeLo = 1302667394U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[44].name = "realmin";
  c2_info[44].dominantType = "char";
  c2_info[44].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[44].fileTimeLo = 1307629642U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c2_info[45].name = "eml_realmin";
  c2_info[45].dominantType = "char";
  c2_info[45].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c2_info[45].fileTimeLo = 1307629644U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c2_info[46].name = "eml_float_model";
  c2_info[46].dominantType = "char";
  c2_info[46].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[46].fileTimeLo = 1307629642U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
  c2_info[47].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[47].name = "eps";
  c2_info[47].dominantType = "char";
  c2_info[47].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[47].fileTimeLo = 1307629640U;
  c2_info[47].fileTimeHi = 0U;
  c2_info[47].mFileTimeLo = 0U;
  c2_info[47].mFileTimeHi = 0U;
  c2_info[48].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[48].name = "eml_is_float_class";
  c2_info[48].dominantType = "char";
  c2_info[48].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[48].fileTimeLo = 1286797182U;
  c2_info[48].fileTimeHi = 0U;
  c2_info[48].mFileTimeLo = 0U;
  c2_info[48].mFileTimeHi = 0U;
  c2_info[49].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[49].name = "eml_eps";
  c2_info[49].dominantType = "char";
  c2_info[49].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[49].fileTimeLo = 1307629640U;
  c2_info[49].fileTimeHi = 0U;
  c2_info[49].mFileTimeLo = 0U;
  c2_info[49].mFileTimeHi = 0U;
  c2_info[50].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[50].name = "eml_float_model";
  c2_info[50].dominantType = "char";
  c2_info[50].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[50].fileTimeLo = 1307629642U;
  c2_info[50].fileTimeHi = 0U;
  c2_info[50].mFileTimeLo = 0U;
  c2_info[50].mFileTimeHi = 0U;
  c2_info[51].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[51].name = "min";
  c2_info[51].dominantType = "int32";
  c2_info[51].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[51].fileTimeLo = 1311233718U;
  c2_info[51].fileTimeHi = 0U;
  c2_info[51].mFileTimeLo = 0U;
  c2_info[51].mFileTimeHi = 0U;
  c2_info[52].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[52].name = "eml_min_or_max";
  c2_info[52].dominantType = "int32";
  c2_info[52].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[52].fileTimeLo = 1303124612U;
  c2_info[52].fileTimeHi = 0U;
  c2_info[52].mFileTimeLo = 0U;
  c2_info[52].mFileTimeHi = 0U;
  c2_info[53].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[53].name = "eml_scalar_eg";
  c2_info[53].dominantType = "int32";
  c2_info[53].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[53].fileTimeLo = 1286797196U;
  c2_info[53].fileTimeHi = 0U;
  c2_info[53].mFileTimeLo = 0U;
  c2_info[53].mFileTimeHi = 0U;
  c2_info[54].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[54].name = "eml_scalexp_alloc";
  c2_info[54].dominantType = "int32";
  c2_info[54].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[54].fileTimeLo = 1286797196U;
  c2_info[54].fileTimeHi = 0U;
  c2_info[54].mFileTimeLo = 0U;
  c2_info[54].mFileTimeHi = 0U;
  c2_info[55].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[55].name = "eml_index_class";
  c2_info[55].dominantType = "";
  c2_info[55].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[55].fileTimeLo = 1286797178U;
  c2_info[55].fileTimeHi = 0U;
  c2_info[55].mFileTimeLo = 0U;
  c2_info[55].mFileTimeHi = 0U;
  c2_info[56].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[56].name = "eml_scalar_eg";
  c2_info[56].dominantType = "int32";
  c2_info[56].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[56].fileTimeLo = 1286797196U;
  c2_info[56].fileTimeHi = 0U;
  c2_info[56].mFileTimeLo = 0U;
  c2_info[56].mFileTimeHi = 0U;
  c2_info[57].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[57].name = "colon";
  c2_info[57].dominantType = "int32";
  c2_info[57].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[57].fileTimeLo = 1311233718U;
  c2_info[57].fileTimeHi = 0U;
  c2_info[57].mFileTimeLo = 0U;
  c2_info[57].mFileTimeHi = 0U;
  c2_info[58].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[58].name = "colon";
  c2_info[58].dominantType = "int32";
  c2_info[58].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[58].fileTimeLo = 1311233718U;
  c2_info[58].fileTimeHi = 0U;
  c2_info[58].mFileTimeLo = 0U;
  c2_info[58].mFileTimeHi = 0U;
  c2_info[59].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c2_info[59].name = "floor";
  c2_info[59].dominantType = "double";
  c2_info[59].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[59].fileTimeLo = 1286797142U;
  c2_info[59].fileTimeHi = 0U;
  c2_info[59].mFileTimeLo = 0U;
  c2_info[59].mFileTimeHi = 0U;
  c2_info[60].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[60].name = "eml_scalar_floor";
  c2_info[60].dominantType = "double";
  c2_info[60].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[60].fileTimeLo = 1286797126U;
  c2_info[60].fileTimeHi = 0U;
  c2_info[60].mFileTimeLo = 0U;
  c2_info[60].mFileTimeHi = 0U;
  c2_info[61].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[61].name = "intmin";
  c2_info[61].dominantType = "char";
  c2_info[61].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[61].fileTimeLo = 1311233718U;
  c2_info[61].fileTimeHi = 0U;
  c2_info[61].mFileTimeLo = 0U;
  c2_info[61].mFileTimeHi = 0U;
  c2_info[62].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c2_info[62].name = "intmax";
  c2_info[62].dominantType = "char";
  c2_info[62].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[62].fileTimeLo = 1311233716U;
  c2_info[62].fileTimeHi = 0U;
  c2_info[62].mFileTimeLo = 0U;
  c2_info[62].mFileTimeHi = 0U;
  c2_info[63].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[63].name = "intmin";
  c2_info[63].dominantType = "char";
  c2_info[63].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[63].fileTimeLo = 1311233718U;
  c2_info[63].fileTimeHi = 0U;
  c2_info[63].mFileTimeLo = 0U;
  c2_info[63].mFileTimeHi = 0U;
}

static void c2_b_info_helper(c2_ResolvedFunctionInfo c2_info[135])
{
  c2_info[64].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[64].name = "intmax";
  c2_info[64].dominantType = "char";
  c2_info[64].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[64].fileTimeLo = 1311233716U;
  c2_info[64].fileTimeHi = 0U;
  c2_info[64].mFileTimeLo = 0U;
  c2_info[64].mFileTimeHi = 0U;
  c2_info[65].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c2_info[65].name = "eml_isa_uint";
  c2_info[65].dominantType = "int32";
  c2_info[65].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[65].fileTimeLo = 1286797184U;
  c2_info[65].fileTimeHi = 0U;
  c2_info[65].mFileTimeLo = 0U;
  c2_info[65].mFileTimeHi = 0U;
  c2_info[66].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[66].name = "eml_unsigned_class";
  c2_info[66].dominantType = "char";
  c2_info[66].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[66].fileTimeLo = 1286797200U;
  c2_info[66].fileTimeHi = 0U;
  c2_info[66].mFileTimeLo = 0U;
  c2_info[66].mFileTimeHi = 0U;
  c2_info[67].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[67].name = "eml_index_class";
  c2_info[67].dominantType = "";
  c2_info[67].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[67].fileTimeLo = 1286797178U;
  c2_info[67].fileTimeHi = 0U;
  c2_info[67].mFileTimeLo = 0U;
  c2_info[67].mFileTimeHi = 0U;
  c2_info[68].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[68].name = "intmax";
  c2_info[68].dominantType = "char";
  c2_info[68].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[68].fileTimeLo = 1311233716U;
  c2_info[68].fileTimeHi = 0U;
  c2_info[68].mFileTimeLo = 0U;
  c2_info[68].mFileTimeHi = 0U;
  c2_info[69].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[69].name = "eml_isa_uint";
  c2_info[69].dominantType = "int32";
  c2_info[69].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c2_info[69].fileTimeLo = 1286797184U;
  c2_info[69].fileTimeHi = 0U;
  c2_info[69].mFileTimeLo = 0U;
  c2_info[69].mFileTimeHi = 0U;
  c2_info[70].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c2_info[70].name = "eml_index_plus";
  c2_info[70].dominantType = "int32";
  c2_info[70].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[70].fileTimeLo = 1286797178U;
  c2_info[70].fileTimeHi = 0U;
  c2_info[70].mFileTimeLo = 0U;
  c2_info[70].mFileTimeHi = 0U;
  c2_info[71].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[71].name = "eml_index_class";
  c2_info[71].dominantType = "";
  c2_info[71].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[71].fileTimeLo = 1286797178U;
  c2_info[71].fileTimeHi = 0U;
  c2_info[71].mFileTimeLo = 0U;
  c2_info[71].mFileTimeHi = 0U;
  c2_info[72].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c2_info[72].name = "eml_int_forloop_overflow_check";
  c2_info[72].dominantType = "";
  c2_info[72].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[72].fileTimeLo = 1311233716U;
  c2_info[72].fileTimeHi = 0U;
  c2_info[72].mFileTimeLo = 0U;
  c2_info[72].mFileTimeHi = 0U;
  c2_info[73].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[73].name = "eml_index_class";
  c2_info[73].dominantType = "";
  c2_info[73].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[73].fileTimeLo = 1286797178U;
  c2_info[73].fileTimeHi = 0U;
  c2_info[73].mFileTimeLo = 0U;
  c2_info[73].mFileTimeHi = 0U;
  c2_info[74].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[74].name = "eml_index_plus";
  c2_info[74].dominantType = "int32";
  c2_info[74].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[74].fileTimeLo = 1286797178U;
  c2_info[74].fileTimeHi = 0U;
  c2_info[74].mFileTimeLo = 0U;
  c2_info[74].mFileTimeHi = 0U;
  c2_info[75].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[75].name = "eml_int_forloop_overflow_check";
  c2_info[75].dominantType = "";
  c2_info[75].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[75].fileTimeLo = 1311233716U;
  c2_info[75].fileTimeHi = 0U;
  c2_info[75].mFileTimeLo = 0U;
  c2_info[75].mFileTimeHi = 0U;
  c2_info[76].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[76].name = "eml_index_minus";
  c2_info[76].dominantType = "int32";
  c2_info[76].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[76].fileTimeLo = 1286797178U;
  c2_info[76].fileTimeHi = 0U;
  c2_info[76].mFileTimeLo = 0U;
  c2_info[76].mFileTimeHi = 0U;
  c2_info[77].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[77].name = "eml_index_class";
  c2_info[77].dominantType = "";
  c2_info[77].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[77].fileTimeLo = 1286797178U;
  c2_info[77].fileTimeHi = 0U;
  c2_info[77].mFileTimeLo = 0U;
  c2_info[77].mFileTimeHi = 0U;
  c2_info[78].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[78].name = "eml_index_times";
  c2_info[78].dominantType = "int32";
  c2_info[78].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[78].fileTimeLo = 1286797180U;
  c2_info[78].fileTimeHi = 0U;
  c2_info[78].mFileTimeLo = 0U;
  c2_info[78].mFileTimeHi = 0U;
  c2_info[79].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[79].name = "eml_index_class";
  c2_info[79].dominantType = "";
  c2_info[79].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[79].fileTimeLo = 1286797178U;
  c2_info[79].fileTimeHi = 0U;
  c2_info[79].mFileTimeLo = 0U;
  c2_info[79].mFileTimeHi = 0U;
  c2_info[80].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[80].name = "eml_ixamax";
  c2_info[80].dominantType = "int32";
  c2_info[80].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[80].fileTimeLo = 1299051570U;
  c2_info[80].fileTimeHi = 0U;
  c2_info[80].mFileTimeLo = 0U;
  c2_info[80].mFileTimeHi = 0U;
  c2_info[81].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c2_info[81].name = "eml_blas_inline";
  c2_info[81].dominantType = "";
  c2_info[81].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[81].fileTimeLo = 1299051568U;
  c2_info[81].fileTimeHi = 0U;
  c2_info[81].mFileTimeLo = 0U;
  c2_info[81].mFileTimeHi = 0U;
  c2_info[82].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c2_info[82].name = "length";
  c2_info[82].dominantType = "double";
  c2_info[82].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m";
  c2_info[82].fileTimeLo = 1303124606U;
  c2_info[82].fileTimeHi = 0U;
  c2_info[82].mFileTimeLo = 0U;
  c2_info[82].mFileTimeHi = 0U;
  c2_info[83].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c2_info[83].name = "eml_index_class";
  c2_info[83].dominantType = "";
  c2_info[83].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[83].fileTimeLo = 1286797178U;
  c2_info[83].fileTimeHi = 0U;
  c2_info[83].mFileTimeLo = 0U;
  c2_info[83].mFileTimeHi = 0U;
  c2_info[84].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c2_info[84].name = "eml_refblas_ixamax";
  c2_info[84].dominantType = "int32";
  c2_info[84].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[84].fileTimeLo = 1299051570U;
  c2_info[84].fileTimeHi = 0U;
  c2_info[84].mFileTimeLo = 0U;
  c2_info[84].mFileTimeHi = 0U;
  c2_info[85].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[85].name = "eml_index_class";
  c2_info[85].dominantType = "";
  c2_info[85].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[85].fileTimeLo = 1286797178U;
  c2_info[85].fileTimeHi = 0U;
  c2_info[85].mFileTimeLo = 0U;
  c2_info[85].mFileTimeHi = 0U;
  c2_info[86].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[86].name = "eml_xcabs1";
  c2_info[86].dominantType = "double";
  c2_info[86].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[86].fileTimeLo = 1286797106U;
  c2_info[86].fileTimeHi = 0U;
  c2_info[86].mFileTimeLo = 0U;
  c2_info[86].mFileTimeHi = 0U;
  c2_info[87].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c2_info[87].name = "abs";
  c2_info[87].dominantType = "double";
  c2_info[87].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[87].fileTimeLo = 1286797094U;
  c2_info[87].fileTimeHi = 0U;
  c2_info[87].mFileTimeLo = 0U;
  c2_info[87].mFileTimeHi = 0U;
  c2_info[88].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[88].name = "eml_scalar_abs";
  c2_info[88].dominantType = "double";
  c2_info[88].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[88].fileTimeLo = 1286797112U;
  c2_info[88].fileTimeHi = 0U;
  c2_info[88].mFileTimeLo = 0U;
  c2_info[88].mFileTimeHi = 0U;
  c2_info[89].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[89].name = "eml_int_forloop_overflow_check";
  c2_info[89].dominantType = "";
  c2_info[89].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[89].fileTimeLo = 1311233716U;
  c2_info[89].fileTimeHi = 0U;
  c2_info[89].mFileTimeLo = 0U;
  c2_info[89].mFileTimeHi = 0U;
  c2_info[90].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c2_info[90].name = "eml_index_plus";
  c2_info[90].dominantType = "int32";
  c2_info[90].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[90].fileTimeLo = 1286797178U;
  c2_info[90].fileTimeHi = 0U;
  c2_info[90].mFileTimeLo = 0U;
  c2_info[90].mFileTimeHi = 0U;
  c2_info[91].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[91].name = "eml_xswap";
  c2_info[91].dominantType = "int32";
  c2_info[91].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[91].fileTimeLo = 1299051578U;
  c2_info[91].fileTimeHi = 0U;
  c2_info[91].mFileTimeLo = 0U;
  c2_info[91].mFileTimeHi = 0U;
  c2_info[92].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c2_info[92].name = "eml_blas_inline";
  c2_info[92].dominantType = "";
  c2_info[92].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[92].fileTimeLo = 1299051568U;
  c2_info[92].fileTimeHi = 0U;
  c2_info[92].mFileTimeLo = 0U;
  c2_info[92].mFileTimeHi = 0U;
  c2_info[93].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c2_info[93].name = "eml_refblas_xswap";
  c2_info[93].dominantType = "int32";
  c2_info[93].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[93].fileTimeLo = 1299051586U;
  c2_info[93].fileTimeHi = 0U;
  c2_info[93].mFileTimeLo = 0U;
  c2_info[93].mFileTimeHi = 0U;
  c2_info[94].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[94].name = "eml_index_class";
  c2_info[94].dominantType = "";
  c2_info[94].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[94].fileTimeLo = 1286797178U;
  c2_info[94].fileTimeHi = 0U;
  c2_info[94].mFileTimeLo = 0U;
  c2_info[94].mFileTimeHi = 0U;
  c2_info[95].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[95].name = "abs";
  c2_info[95].dominantType = "int32";
  c2_info[95].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[95].fileTimeLo = 1286797094U;
  c2_info[95].fileTimeHi = 0U;
  c2_info[95].mFileTimeLo = 0U;
  c2_info[95].mFileTimeHi = 0U;
  c2_info[96].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[96].name = "eml_scalar_abs";
  c2_info[96].dominantType = "int32";
  c2_info[96].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c2_info[96].fileTimeLo = 1286797112U;
  c2_info[96].fileTimeHi = 0U;
  c2_info[96].mFileTimeLo = 0U;
  c2_info[96].mFileTimeHi = 0U;
  c2_info[97].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[97].name = "eml_int_forloop_overflow_check";
  c2_info[97].dominantType = "";
  c2_info[97].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[97].fileTimeLo = 1311233716U;
  c2_info[97].fileTimeHi = 0U;
  c2_info[97].mFileTimeLo = 0U;
  c2_info[97].mFileTimeHi = 0U;
  c2_info[98].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c2_info[98].name = "eml_index_plus";
  c2_info[98].dominantType = "int32";
  c2_info[98].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[98].fileTimeLo = 1286797178U;
  c2_info[98].fileTimeHi = 0U;
  c2_info[98].mFileTimeLo = 0U;
  c2_info[98].mFileTimeHi = 0U;
  c2_info[99].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[99].name = "eml_div";
  c2_info[99].dominantType = "double";
  c2_info[99].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[99].fileTimeLo = 1313326210U;
  c2_info[99].fileTimeHi = 0U;
  c2_info[99].mFileTimeLo = 0U;
  c2_info[99].mFileTimeHi = 0U;
  c2_info[100].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c2_info[100].name = "eml_xgeru";
  c2_info[100].dominantType = "int32";
  c2_info[100].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[100].fileTimeLo = 1299051574U;
  c2_info[100].fileTimeHi = 0U;
  c2_info[100].mFileTimeLo = 0U;
  c2_info[100].mFileTimeHi = 0U;
  c2_info[101].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[101].name = "eml_blas_inline";
  c2_info[101].dominantType = "";
  c2_info[101].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[101].fileTimeLo = 1299051568U;
  c2_info[101].fileTimeHi = 0U;
  c2_info[101].mFileTimeLo = 0U;
  c2_info[101].mFileTimeHi = 0U;
  c2_info[102].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c2_info[102].name = "eml_xger";
  c2_info[102].dominantType = "int32";
  c2_info[102].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[102].fileTimeLo = 1299051574U;
  c2_info[102].fileTimeHi = 0U;
  c2_info[102].mFileTimeLo = 0U;
  c2_info[102].mFileTimeHi = 0U;
  c2_info[103].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c2_info[103].name = "eml_blas_inline";
  c2_info[103].dominantType = "";
  c2_info[103].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[103].fileTimeLo = 1299051568U;
  c2_info[103].fileTimeHi = 0U;
  c2_info[103].mFileTimeLo = 0U;
  c2_info[103].mFileTimeHi = 0U;
  c2_info[104].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c2_info[104].name = "intmax";
  c2_info[104].dominantType = "char";
  c2_info[104].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[104].fileTimeLo = 1311233716U;
  c2_info[104].fileTimeHi = 0U;
  c2_info[104].mFileTimeLo = 0U;
  c2_info[104].mFileTimeHi = 0U;
  c2_info[105].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c2_info[105].name = "min";
  c2_info[105].dominantType = "double";
  c2_info[105].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[105].fileTimeLo = 1311233718U;
  c2_info[105].fileTimeHi = 0U;
  c2_info[105].mFileTimeLo = 0U;
  c2_info[105].mFileTimeHi = 0U;
  c2_info[106].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c2_info[106].name = "eml_min_or_max";
  c2_info[106].dominantType = "char";
  c2_info[106].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c2_info[106].fileTimeLo = 1303124612U;
  c2_info[106].fileTimeHi = 0U;
  c2_info[106].mFileTimeLo = 0U;
  c2_info[106].mFileTimeHi = 0U;
  c2_info[107].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[107].name = "eml_scalar_eg";
  c2_info[107].dominantType = "double";
  c2_info[107].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[107].fileTimeLo = 1286797196U;
  c2_info[107].fileTimeHi = 0U;
  c2_info[107].mFileTimeLo = 0U;
  c2_info[107].mFileTimeHi = 0U;
  c2_info[108].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c2_info[108].name = "eml_scalexp_alloc";
  c2_info[108].dominantType = "double";
  c2_info[108].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[108].fileTimeLo = 1286797196U;
  c2_info[108].fileTimeHi = 0U;
  c2_info[108].mFileTimeLo = 0U;
  c2_info[108].mFileTimeHi = 0U;
  c2_info[109].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c2_info[109].name = "eml_scalar_eg";
  c2_info[109].dominantType = "double";
  c2_info[109].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[109].fileTimeLo = 1286797196U;
  c2_info[109].fileTimeHi = 0U;
  c2_info[109].mFileTimeLo = 0U;
  c2_info[109].mFileTimeHi = 0U;
  c2_info[110].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c2_info[110].name = "mtimes";
  c2_info[110].dominantType = "double";
  c2_info[110].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[110].fileTimeLo = 1289494492U;
  c2_info[110].fileTimeHi = 0U;
  c2_info[110].mFileTimeLo = 0U;
  c2_info[110].mFileTimeHi = 0U;
  c2_info[111].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c2_info[111].name = "eml_refblas_xger";
  c2_info[111].dominantType = "int32";
  c2_info[111].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[111].fileTimeLo = 1299051576U;
  c2_info[111].fileTimeHi = 0U;
  c2_info[111].mFileTimeLo = 0U;
  c2_info[111].mFileTimeHi = 0U;
  c2_info[112].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c2_info[112].name = "eml_refblas_xgerx";
  c2_info[112].dominantType = "int32";
  c2_info[112].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[112].fileTimeLo = 1299051578U;
  c2_info[112].fileTimeHi = 0U;
  c2_info[112].mFileTimeLo = 0U;
  c2_info[112].mFileTimeHi = 0U;
  c2_info[113].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[113].name = "eml_index_class";
  c2_info[113].dominantType = "";
  c2_info[113].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[113].fileTimeLo = 1286797178U;
  c2_info[113].fileTimeHi = 0U;
  c2_info[113].mFileTimeLo = 0U;
  c2_info[113].mFileTimeHi = 0U;
  c2_info[114].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[114].name = "abs";
  c2_info[114].dominantType = "int32";
  c2_info[114].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c2_info[114].fileTimeLo = 1286797094U;
  c2_info[114].fileTimeHi = 0U;
  c2_info[114].mFileTimeLo = 0U;
  c2_info[114].mFileTimeHi = 0U;
  c2_info[115].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[115].name = "eml_index_minus";
  c2_info[115].dominantType = "int32";
  c2_info[115].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[115].fileTimeLo = 1286797178U;
  c2_info[115].fileTimeHi = 0U;
  c2_info[115].mFileTimeLo = 0U;
  c2_info[115].mFileTimeHi = 0U;
  c2_info[116].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[116].name = "eml_int_forloop_overflow_check";
  c2_info[116].dominantType = "";
  c2_info[116].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[116].fileTimeLo = 1311233716U;
  c2_info[116].fileTimeHi = 0U;
  c2_info[116].mFileTimeLo = 0U;
  c2_info[116].mFileTimeHi = 0U;
  c2_info[117].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c2_info[117].name = "eml_index_plus";
  c2_info[117].dominantType = "int32";
  c2_info[117].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[117].fileTimeLo = 1286797178U;
  c2_info[117].fileTimeHi = 0U;
  c2_info[117].mFileTimeLo = 0U;
  c2_info[117].mFileTimeHi = 0U;
  c2_info[118].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c2_info[118].name = "eml_warning";
  c2_info[118].dominantType = "char";
  c2_info[118].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[118].fileTimeLo = 1286797202U;
  c2_info[118].fileTimeHi = 0U;
  c2_info[118].mFileTimeLo = 0U;
  c2_info[118].mFileTimeHi = 0U;
  c2_info[119].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[119].name = "eml_scalar_eg";
  c2_info[119].dominantType = "double";
  c2_info[119].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[119].fileTimeLo = 1286797196U;
  c2_info[119].fileTimeHi = 0U;
  c2_info[119].mFileTimeLo = 0U;
  c2_info[119].mFileTimeHi = 0U;
  c2_info[120].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[120].name = "eml_int_forloop_overflow_check";
  c2_info[120].dominantType = "";
  c2_info[120].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[120].fileTimeLo = 1311233716U;
  c2_info[120].fileTimeHi = 0U;
  c2_info[120].mFileTimeLo = 0U;
  c2_info[120].mFileTimeHi = 0U;
  c2_info[121].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c2_info[121].name = "eml_xtrsm";
  c2_info[121].dominantType = "int32";
  c2_info[121].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c2_info[121].fileTimeLo = 1299051578U;
  c2_info[121].fileTimeHi = 0U;
  c2_info[121].mFileTimeLo = 0U;
  c2_info[121].mFileTimeHi = 0U;
  c2_info[122].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c2_info[122].name = "eml_blas_inline";
  c2_info[122].dominantType = "";
  c2_info[122].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[122].fileTimeLo = 1299051568U;
  c2_info[122].fileTimeHi = 0U;
  c2_info[122].mFileTimeLo = 0U;
  c2_info[122].mFileTimeHi = 0U;
  c2_info[123].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c2_info[123].name = "mtimes";
  c2_info[123].dominantType = "double";
  c2_info[123].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[123].fileTimeLo = 1289494492U;
  c2_info[123].fileTimeHi = 0U;
  c2_info[123].mFileTimeLo = 0U;
  c2_info[123].mFileTimeHi = 0U;
  c2_info[124].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c2_info[124].name = "eml_scalar_eg";
  c2_info[124].dominantType = "double";
  c2_info[124].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[124].fileTimeLo = 1286797196U;
  c2_info[124].fileTimeHi = 0U;
  c2_info[124].mFileTimeLo = 0U;
  c2_info[124].mFileTimeHi = 0U;
  c2_info[125].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c2_info[125].name = "eml_refblas_xtrsm";
  c2_info[125].dominantType = "int32";
  c2_info[125].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[125].fileTimeLo = 1299051586U;
  c2_info[125].fileTimeHi = 0U;
  c2_info[125].mFileTimeLo = 0U;
  c2_info[125].mFileTimeHi = 0U;
  c2_info[126].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[126].name = "eml_scalar_eg";
  c2_info[126].dominantType = "double";
  c2_info[126].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[126].fileTimeLo = 1286797196U;
  c2_info[126].fileTimeHi = 0U;
  c2_info[126].mFileTimeLo = 0U;
  c2_info[126].mFileTimeHi = 0U;
  c2_info[127].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[127].name = "eml_index_minus";
  c2_info[127].dominantType = "int32";
  c2_info[127].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[127].fileTimeLo = 1286797178U;
  c2_info[127].fileTimeHi = 0U;
  c2_info[127].mFileTimeLo = 0U;
  c2_info[127].mFileTimeHi = 0U;
}

static void c2_c_info_helper(c2_ResolvedFunctionInfo c2_info[135])
{
  c2_info[128].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[128].name = "eml_index_class";
  c2_info[128].dominantType = "";
  c2_info[128].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[128].fileTimeLo = 1286797178U;
  c2_info[128].fileTimeHi = 0U;
  c2_info[128].mFileTimeLo = 0U;
  c2_info[128].mFileTimeHi = 0U;
  c2_info[129].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[129].name = "eml_int_forloop_overflow_check";
  c2_info[129].dominantType = "";
  c2_info[129].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[129].fileTimeLo = 1311233716U;
  c2_info[129].fileTimeHi = 0U;
  c2_info[129].mFileTimeLo = 0U;
  c2_info[129].mFileTimeHi = 0U;
  c2_info[130].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[130].name = "eml_index_times";
  c2_info[130].dominantType = "int32";
  c2_info[130].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[130].fileTimeLo = 1286797180U;
  c2_info[130].fileTimeHi = 0U;
  c2_info[130].mFileTimeLo = 0U;
  c2_info[130].mFileTimeHi = 0U;
  c2_info[131].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[131].name = "eml_index_plus";
  c2_info[131].dominantType = "int32";
  c2_info[131].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[131].fileTimeLo = 1286797178U;
  c2_info[131].fileTimeHi = 0U;
  c2_info[131].mFileTimeLo = 0U;
  c2_info[131].mFileTimeHi = 0U;
  c2_info[132].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[132].name = "intmin";
  c2_info[132].dominantType = "char";
  c2_info[132].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c2_info[132].fileTimeLo = 1311233718U;
  c2_info[132].fileTimeHi = 0U;
  c2_info[132].mFileTimeLo = 0U;
  c2_info[132].mFileTimeHi = 0U;
  c2_info[133].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c2_info[133].name = "eml_div";
  c2_info[133].dominantType = "double";
  c2_info[133].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[133].fileTimeLo = 1313326210U;
  c2_info[133].fileTimeHi = 0U;
  c2_info[133].mFileTimeLo = 0U;
  c2_info[133].mFileTimeHi = 0U;
  c2_info[134].context = "";
  c2_info[134].name = "mtimes";
  c2_info[134].dominantType = "double";
  c2_info[134].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[134].fileTimeLo = 1289494492U;
  c2_info[134].fileTimeHi = 0U;
  c2_info[134].mFileTimeLo = 0U;
  c2_info[134].mFileTimeHi = 0U;
}

static void c2_fwd_kin(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_in1[9], real_T c2_in2[6], real_T c2_gst[16])
{
  uint32_T c2_debug_family_var_map[68];
  real_T c2_A1;
  real_T c2_A2;
  real_T c2_A3;
  real_T c2_A4;
  real_T c2_A5;
  real_T c2_A6;
  real_T c2_L1;
  real_T c2_L2;
  real_T c2_L3;
  real_T c2_L4;
  real_T c2_L5;
  real_T c2_L6;
  real_T c2_L7;
  real_T c2_L8;
  real_T c2_L9;
  real_T c2_t2;
  real_T c2_t3;
  real_T c2_t4;
  real_T c2_t5;
  real_T c2_t6;
  real_T c2_t7;
  real_T c2_t8;
  real_T c2_t9;
  real_T c2_t10;
  real_T c2_t11;
  real_T c2_t12;
  real_T c2_t13;
  real_T c2_t14;
  real_T c2_t23;
  real_T c2_t15;
  real_T c2_t16;
  real_T c2_t17;
  real_T c2_t18;
  real_T c2_t19;
  real_T c2_t20;
  real_T c2_t21;
  real_T c2_t22;
  real_T c2_t24;
  real_T c2_t25;
  real_T c2_t26;
  real_T c2_t27;
  real_T c2_t34;
  real_T c2_t28;
  real_T c2_t29;
  real_T c2_t30;
  real_T c2_t31;
  real_T c2_t32;
  real_T c2_t36;
  real_T c2_t33;
  real_T c2_t35;
  real_T c2_t37;
  real_T c2_t38;
  real_T c2_t39;
  real_T c2_t40;
  real_T c2_t41;
  real_T c2_t42;
  real_T c2_t43;
  real_T c2_t44;
  real_T c2_t45;
  real_T c2_t47;
  real_T c2_t46;
  real_T c2_t48;
  real_T c2_t49;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x[16];
  int32_T c2_k;
  int32_T c2_b_k;
  sf_debug_symbol_scope_push_eml(0U, 68U, 68U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_A1, 0U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A2, 1U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A3, 2U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A4, 3U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A5, 4U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A6, 5U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L1, 6U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L2, 7U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L3, 8U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L4, 9U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L5, 10U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L6, 11U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L7, 12U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L8, 13U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L9, 14U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t2, 15U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t3, 16U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t4, 17U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t5, 18U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t6, 19U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t7, 20U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t8, 21U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t9, 22U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t10, 23U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t11, 24U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t12, 25U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t13, 26U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t14, 27U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t23, 28U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t15, 29U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t16, 30U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t17, 31U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t18, 32U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t19, 33U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t20, 34U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t21, 35U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t22, 36U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t24, 37U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t25, 38U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t26, 39U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t27, 40U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t34, 41U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t28, 42U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t29, 43U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t30, 44U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t31, 45U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t32, 46U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t36, 47U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t33, 48U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t35, 49U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t37, 50U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t38, 51U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t39, 52U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t40, 53U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t41, 54U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t42, 55U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t43, 56U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t44, 57U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t45, 58U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t47, 59U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t46, 60U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t48, 61U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t49, 62U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 63U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 64U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_in1, 65U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_in2, 66U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_gst, 67U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  c2_A1 = c2_in2[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_A2 = c2_in2[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_A3 = c2_in2[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_A4 = c2_in2[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_A5 = c2_in2[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_A6 = c2_in2[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_L1 = c2_in1[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_L2 = c2_in1[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_L3 = c2_in1[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_L4 = c2_in1[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_L5 = c2_in1[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_L6 = c2_in1[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_L7 = c2_in1[6];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_L8 = c2_in1[7];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_L9 = c2_in1[8];
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_x = c2_A1;
  c2_t2 = c2_x;
  c2_b_x = c2_t2;
  c2_t2 = c2_b_x;
  c2_t2 = muDoubleScalarCos(c2_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_c_x = c2_A2;
  c2_t3 = c2_c_x;
  c2_d_x = c2_t3;
  c2_t3 = c2_d_x;
  c2_t3 = muDoubleScalarCos(c2_t3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_e_x = c2_A3;
  c2_t4 = c2_e_x;
  c2_f_x = c2_t4;
  c2_t4 = c2_f_x;
  c2_t4 = muDoubleScalarSin(c2_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_g_x = c2_A3;
  c2_t5 = c2_g_x;
  c2_h_x = c2_t5;
  c2_t5 = c2_h_x;
  c2_t5 = muDoubleScalarCos(c2_t5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_i_x = c2_A2;
  c2_t6 = c2_i_x;
  c2_j_x = c2_t6;
  c2_t6 = c2_j_x;
  c2_t6 = muDoubleScalarSin(c2_t6);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_k_x = c2_A4;
  c2_t7 = c2_k_x;
  c2_l_x = c2_t7;
  c2_t7 = c2_l_x;
  c2_t7 = muDoubleScalarSin(c2_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_t8 = c2_t2 * c2_t3 * c2_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 30);
  c2_t9 = c2_t2 * c2_t5 * c2_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 31);
  c2_t10 = c2_t8 + c2_t9;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 32);
  c2_m_x = c2_A4;
  c2_t11 = c2_m_x;
  c2_n_x = c2_t11;
  c2_t11 = c2_n_x;
  c2_t11 = muDoubleScalarCos(c2_t11);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 33);
  c2_o_x = c2_A1;
  c2_t12 = c2_o_x;
  c2_p_x = c2_t12;
  c2_t12 = c2_p_x;
  c2_t12 = muDoubleScalarSin(c2_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 34);
  c2_q_x = c2_A5;
  c2_t13 = c2_q_x;
  c2_r_x = c2_t13;
  c2_t13 = c2_r_x;
  c2_t13 = muDoubleScalarSin(c2_t13);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 35);
  c2_t14 = c2_t2 * c2_t3 * c2_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 36);
  c2_t23 = c2_t2 * c2_t4 * c2_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 37);
  c2_t15 = c2_t14 - c2_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 38);
  c2_s_x = c2_A5;
  c2_t16 = c2_s_x;
  c2_t_x = c2_t16;
  c2_t16 = c2_t_x;
  c2_t16 = muDoubleScalarCos(c2_t16);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 39);
  c2_t17 = c2_t10 * c2_t11;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 40);
  c2_t18 = c2_t12 * c2_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 41);
  c2_t19 = c2_t17 + c2_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 42);
  c2_u_x = c2_A6;
  c2_t20 = c2_u_x;
  c2_v_x = c2_t20;
  c2_t20 = c2_v_x;
  c2_t20 = muDoubleScalarSin(c2_t20);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 43);
  c2_t21 = c2_t11 * c2_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 44);
  c2_w_x = c2_A6;
  c2_t22 = c2_w_x;
  c2_x_x = c2_t22;
  c2_t22 = c2_x_x;
  c2_t22 = muDoubleScalarCos(c2_t22);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 45);
  c2_t24 = c2_t13 * c2_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 46);
  c2_t25 = c2_t16 * c2_t19;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 47);
  c2_t26 = c2_t24 + c2_t25;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 48);
  c2_t27 = c2_t12 * c2_t3 * c2_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 49);
  c2_t34 = c2_t12 * c2_t4 * c2_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 50);
  c2_t28 = c2_t27 - c2_t34;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 51);
  c2_t29 = c2_t12 * c2_t3 * c2_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 52);
  c2_t30 = c2_t12 * c2_t5 * c2_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 53);
  c2_t31 = c2_t29 + c2_t30;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 54);
  c2_t32 = c2_t11 * c2_t31;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 55);
  c2_t36 = c2_t2 * c2_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 56);
  c2_t33 = c2_t32 - c2_t36;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 57);
  c2_t35 = c2_t13 * c2_t28;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 58);
  c2_t37 = c2_t16 * c2_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 59);
  c2_t38 = c2_t35 + c2_t37;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 60);
  c2_t39 = c2_t31 * c2_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 61);
  c2_t40 = c2_t11 * c2_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 62);
  c2_t41 = c2_t39 + c2_t40;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 63);
  c2_t42 = c2_t3 * c2_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 64);
  c2_t43 = c2_t5 * c2_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 65);
  c2_t44 = c2_t42 + c2_t43;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 66);
  c2_t45 = c2_t3 * c2_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 67);
  c2_t47 = c2_t4 * c2_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 68);
  c2_t46 = c2_t45 - c2_t47;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 69);
  c2_t48 = c2_t13 * c2_t44;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 70);
  c2_t49 = c2_t48 - c2_t11 * c2_t16 * c2_t46;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 71);
  c2_y_x[0] = c2_t15 * c2_t16 - c2_t13 * c2_t19;
  c2_y_x[1] = c2_t16 * c2_t28 - c2_t13 * c2_t33;
  c2_y_x[2] = -c2_t16 * c2_t44 - c2_t11 * c2_t13 * c2_t46;
  c2_y_x[3] = 0.0;
  c2_y_x[4] = c2_t20 * c2_t26 - c2_t22 * (c2_t21 - c2_t10 * c2_t7);
  c2_y_x[5] = c2_t20 * c2_t38 + c2_t22 * c2_t41;
  c2_y_x[6] = -c2_t20 * c2_t49 + c2_t22 * c2_t46 * c2_t7;
  c2_y_x[7] = 0.0;
  c2_y_x[8] = c2_t22 * c2_t26 + c2_t20 * (c2_t21 - c2_t10 * c2_t7);
  c2_y_x[9] = c2_t22 * c2_t38 - c2_t20 * c2_t41;
  c2_y_x[10] = -c2_t22 * c2_t49 - c2_t20 * c2_t46 * c2_t7;
  c2_y_x[11] = 0.0;
  c2_y_x[12] = ((((((((((((((((((((((((((((((c2_L2 * c2_t2 + c2_L3 * c2_t2 *
    c2_t6) - c2_L8 * c2_t11 * c2_t12 * c2_t22) + c2_L4 * c2_t2 * c2_t3 * c2_t4)
    + c2_L9 * c2_t11 * c2_t12 * c2_t20) + c2_L5 * c2_t2 * c2_t3 * c2_t5) - c2_L6
    * c2_t12 * c2_t13 * c2_t7) - c2_L7 * c2_t12 * c2_t13 * c2_t7) + c2_L4 *
    c2_t2 * c2_t5 * c2_t6) - c2_L5 * c2_t2 * c2_t4 * c2_t6) + c2_L6 * c2_t16 *
    c2_t2 * c2_t3 * c2_t5) + c2_L7 * c2_t16 * c2_t2 * c2_t3 * c2_t5) - c2_L6 *
    c2_t16 * c2_t2 * c2_t4 * c2_t6) + c2_L8 * c2_t12 * c2_t16 * c2_t20 * c2_t7)
    - c2_L7 * c2_t16 * c2_t2 * c2_t4 * c2_t6) + c2_L9 * c2_t12 * c2_t16 * c2_t22
    * c2_t7) - c2_L6 * c2_t11 * c2_t13 * c2_t2 * c2_t3 * c2_t4) - c2_L7 * c2_t11
    * c2_t13 * c2_t2 * c2_t3 * c2_t4) + c2_L8 * c2_t13 * c2_t2 * c2_t20 * c2_t3 *
    c2_t5) - c2_L6 * c2_t11 * c2_t13 * c2_t2 * c2_t5 * c2_t6) - c2_L7 * c2_t11 *
    c2_t13 * c2_t2 * c2_t5 * c2_t6) + c2_L9 * c2_t13 * c2_t2 * c2_t22 * c2_t3 *
    c2_t5) - c2_L8 * c2_t13 * c2_t2 * c2_t20 * c2_t4 * c2_t6) - c2_L9 * c2_t13 *
                       c2_t2 * c2_t22 * c2_t4 * c2_t6) + c2_L8 * c2_t2 * c2_t22 *
                      c2_t3 * c2_t4 * c2_t7) - c2_L9 * c2_t2 * c2_t20 * c2_t3 *
                     c2_t4 * c2_t7) + c2_L8 * c2_t2 * c2_t22 * c2_t5 * c2_t6 *
                    c2_t7) - c2_L9 * c2_t2 * c2_t20 * c2_t5 * c2_t6 * c2_t7) +
                  c2_L8 * c2_t11 * c2_t16 * c2_t2 * c2_t20 * c2_t3 * c2_t4) +
                 c2_L9 * c2_t11 * c2_t16 * c2_t2 * c2_t22 * c2_t3 * c2_t4) +
                c2_L8 * c2_t11 * c2_t16 * c2_t2 * c2_t20 * c2_t5 * c2_t6) +
    c2_L9 * c2_t11 * c2_t16 * c2_t2 * c2_t22 * c2_t5 * c2_t6;
  c2_y_x[13] = ((((((((((((((((((((((((((((((c2_L2 * c2_t12 + c2_L3 * c2_t12 *
    c2_t6) + c2_L4 * c2_t12 * c2_t3 * c2_t4) + c2_L8 * c2_t11 * c2_t2 * c2_t22)
    + c2_L5 * c2_t12 * c2_t3 * c2_t5) - c2_L9 * c2_t11 * c2_t2 * c2_t20) + c2_L4
    * c2_t12 * c2_t5 * c2_t6) - c2_L5 * c2_t12 * c2_t4 * c2_t6) + c2_L6 * c2_t13
    * c2_t2 * c2_t7) + c2_L7 * c2_t13 * c2_t2 * c2_t7) + c2_L6 * c2_t12 * c2_t16
    * c2_t3 * c2_t5) + c2_L7 * c2_t12 * c2_t16 * c2_t3 * c2_t5) - c2_L6 * c2_t12
    * c2_t16 * c2_t4 * c2_t6) - c2_L7 * c2_t12 * c2_t16 * c2_t4 * c2_t6) - c2_L8
    * c2_t16 * c2_t2 * c2_t20 * c2_t7) - c2_L9 * c2_t16 * c2_t2 * c2_t22 * c2_t7)
    - c2_L6 * c2_t11 * c2_t12 * c2_t13 * c2_t3 * c2_t4) - c2_L7 * c2_t11 *
    c2_t12 * c2_t13 * c2_t3 * c2_t4) + c2_L8 * c2_t12 * c2_t13 * c2_t20 * c2_t3 *
    c2_t5) - c2_L6 * c2_t11 * c2_t12 * c2_t13 * c2_t5 * c2_t6) - c2_L7 * c2_t11 *
    c2_t12 * c2_t13 * c2_t5 * c2_t6) + c2_L9 * c2_t12 * c2_t13 * c2_t22 * c2_t3 *
    c2_t5) - c2_L8 * c2_t12 * c2_t13 * c2_t20 * c2_t4 * c2_t6) - c2_L9 * c2_t12 *
                       c2_t13 * c2_t22 * c2_t4 * c2_t6) + c2_L8 * c2_t12 *
                      c2_t22 * c2_t3 * c2_t4 * c2_t7) - c2_L9 * c2_t12 * c2_t20 *
                     c2_t3 * c2_t4 * c2_t7) + c2_L8 * c2_t12 * c2_t22 * c2_t5 *
                    c2_t6 * c2_t7) - c2_L9 * c2_t12 * c2_t20 * c2_t5 * c2_t6 *
                   c2_t7) + c2_L8 * c2_t11 * c2_t12 * c2_t16 * c2_t20 * c2_t3 *
                  c2_t4) + c2_L9 * c2_t11 * c2_t12 * c2_t16 * c2_t22 * c2_t3 *
                 c2_t4) + c2_L8 * c2_t11 * c2_t12 * c2_t16 * c2_t20 * c2_t5 *
                c2_t6) + c2_L9 * c2_t11 * c2_t12 * c2_t16 * c2_t22 * c2_t5 *
    c2_t6;
  c2_y_x[14] = ((((((((((((((((((((((((c2_L1 + c2_L3 * c2_t3) + c2_L4 * c2_t3 *
    c2_t5) - c2_L5 * c2_t3 * c2_t4) - c2_L4 * c2_t4 * c2_t6) - c2_L5 * c2_t5 *
    c2_t6) - c2_L6 * c2_t16 * c2_t3 * c2_t4) - c2_L7 * c2_t16 * c2_t3 * c2_t4) -
    c2_L6 * c2_t16 * c2_t5 * c2_t6) - c2_L7 * c2_t16 * c2_t5 * c2_t6) - c2_L6 *
    c2_t11 * c2_t13 * c2_t3 * c2_t5) - c2_L7 * c2_t11 * c2_t13 * c2_t3 * c2_t5)
    - c2_L8 * c2_t13 * c2_t20 * c2_t3 * c2_t4) + c2_L6 * c2_t11 * c2_t13 * c2_t4
    * c2_t6) + c2_L7 * c2_t11 * c2_t13 * c2_t4 * c2_t6) - c2_L9 * c2_t13 *
    c2_t22 * c2_t3 * c2_t4) - c2_L8 * c2_t13 * c2_t20 * c2_t5 * c2_t6) - c2_L9 *
                       c2_t13 * c2_t22 * c2_t5 * c2_t6) + c2_L8 * c2_t22 * c2_t3
                      * c2_t5 * c2_t7) - c2_L9 * c2_t20 * c2_t3 * c2_t5 * c2_t7)
                    - c2_L8 * c2_t22 * c2_t4 * c2_t6 * c2_t7) + c2_L9 * c2_t20 *
                   c2_t4 * c2_t6 * c2_t7) + c2_L8 * c2_t11 * c2_t16 * c2_t20 *
                  c2_t3 * c2_t5) + c2_L9 * c2_t11 * c2_t16 * c2_t22 * c2_t3 *
                 c2_t5) - c2_L8 * c2_t11 * c2_t16 * c2_t20 * c2_t4 * c2_t6) -
    c2_L9 * c2_t11 * c2_t16 * c2_t22 * c2_t4 * c2_t6;
  c2_y_x[15] = 1.0;
  c2_eml_int_forloop_overflow_check(chartInstance);
  for (c2_k = 1; c2_k < 17; c2_k++) {
    c2_b_k = c2_k;
    c2_gst[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 16, 1, 0) - 1] = c2_y_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -71);
  sf_debug_symbol_scope_pop();
}

static void c2_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void c2_body_Jacobian(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_in1[9], real_T c2_in2[6], real_T c2_b_body_Jacobian
  [36])
{
  uint32_T c2_debug_family_var_map[49];
  real_T c2_A2;
  real_T c2_A3;
  real_T c2_A4;
  real_T c2_A5;
  real_T c2_A6;
  real_T c2_L2;
  real_T c2_L3;
  real_T c2_L4;
  real_T c2_L5;
  real_T c2_L6;
  real_T c2_L7;
  real_T c2_L8;
  real_T c2_L9;
  real_T c2_t52;
  real_T c2_t53;
  real_T c2_t54;
  real_T c2_t55;
  real_T c2_t56;
  real_T c2_t57;
  real_T c2_t58;
  real_T c2_t59;
  real_T c2_t60;
  real_T c2_t61;
  real_T c2_t62;
  real_T c2_t63;
  real_T c2_t64;
  real_T c2_t65;
  real_T c2_t66;
  real_T c2_t67;
  real_T c2_t68;
  real_T c2_t69;
  real_T c2_t70;
  real_T c2_t71;
  real_T c2_t72;
  real_T c2_t73;
  real_T c2_t74;
  real_T c2_t75;
  real_T c2_t76;
  real_T c2_t77;
  real_T c2_t78;
  real_T c2_t79;
  real_T c2_t80;
  real_T c2_t81;
  real_T c2_t82;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  real_T c2_x;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x[36];
  int32_T c2_k;
  int32_T c2_b_k;
  sf_debug_symbol_scope_push_eml(0U, 49U, 49U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_A2, 0U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A3, 1U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A4, 2U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A5, 3U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_A6, 4U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L2, 5U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L3, 6U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L4, 7U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L5, 8U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L6, 9U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L7, 10U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L8, 11U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_L9, 12U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t52, 13U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t53, 14U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t54, 15U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t55, 16U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t56, 17U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t57, 18U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t58, 19U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t59, 20U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t60, 21U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t61, 22U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t62, 23U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t63, 24U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t64, 25U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t65, 26U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t66, 27U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t67, 28U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t68, 29U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t69, 30U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t70, 31U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t71, 32U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t72, 33U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t73, 34U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t74, 35U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t75, 36U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t76, 37U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t77, 38U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t78, 39U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t79, 40U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t80, 41U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t81, 42U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_t82, 43U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 44U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 45U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_in1, 46U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_in2, 47U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_b_body_Jacobian, 48U,
    c2_e_sf_marshallOut, c2_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 8);
  c2_A2 = c2_in2[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 9);
  c2_A3 = c2_in2[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 10);
  c2_A4 = c2_in2[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 11);
  c2_A5 = c2_in2[4];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 12);
  c2_A6 = c2_in2[5];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 13);
  c2_L2 = c2_in1[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 14);
  c2_L3 = c2_in1[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 15);
  c2_L4 = c2_in1[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 16);
  c2_L5 = c2_in1[4];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 17);
  c2_L6 = c2_in1[5];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 18);
  c2_L7 = c2_in1[6];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 19);
  c2_L8 = c2_in1[7];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 20);
  c2_L9 = c2_in1[8];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 21);
  c2_x = c2_A4;
  c2_t52 = c2_x;
  c2_b_x = c2_t52;
  c2_t52 = c2_b_x;
  c2_t52 = muDoubleScalarSin(c2_t52);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 22);
  c2_c_x = c2_A5;
  c2_t53 = c2_c_x;
  c2_d_x = c2_t53;
  c2_t53 = c2_d_x;
  c2_t53 = muDoubleScalarSin(c2_t53);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 23);
  c2_e_x = c2_A2;
  c2_t54 = c2_e_x;
  c2_f_x = c2_t54;
  c2_t54 = c2_f_x;
  c2_t54 = muDoubleScalarCos(c2_t54);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 24);
  c2_g_x = c2_A3;
  c2_t55 = c2_g_x;
  c2_h_x = c2_t55;
  c2_t55 = c2_h_x;
  c2_t55 = muDoubleScalarCos(c2_t55);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 25);
  c2_i_x = c2_A6;
  c2_t56 = c2_i_x;
  c2_j_x = c2_t56;
  c2_t56 = c2_j_x;
  c2_t56 = muDoubleScalarCos(c2_t56);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 26);
  c2_k_x = c2_A2;
  c2_t57 = c2_k_x;
  c2_l_x = c2_t57;
  c2_t57 = c2_l_x;
  c2_t57 = muDoubleScalarSin(c2_t57);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 27);
  c2_m_x = c2_A3;
  c2_t58 = c2_m_x;
  c2_n_x = c2_t58;
  c2_t58 = c2_n_x;
  c2_t58 = muDoubleScalarSin(c2_t58);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 28);
  c2_o_x = c2_A6;
  c2_t59 = c2_o_x;
  c2_p_x = c2_t59;
  c2_t59 = c2_p_x;
  c2_t59 = muDoubleScalarSin(c2_t59);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 29);
  c2_q_x = c2_A4;
  c2_t60 = c2_q_x;
  c2_r_x = c2_t60;
  c2_t60 = c2_r_x;
  c2_t60 = muDoubleScalarCos(c2_t60);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 30);
  c2_s_x = c2_A5;
  c2_t61 = c2_s_x;
  c2_t_x = c2_t61;
  c2_t61 = c2_t_x;
  c2_t61 = muDoubleScalarCos(c2_t61);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 31);
  c2_t62 = c2_L4 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 32);
  c2_t63 = c2_L5 * c2_t53 * c2_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 33);
  c2_t64 = c2_L8 * c2_t59 * c2_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 34);
  c2_t65 = c2_L9 * c2_t56 * c2_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 35);
  c2_t66 = c2_L8 * c2_t52 * c2_t56 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 36);
  c2_t67 = c2_L4 * c2_t53 * c2_t59;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 37);
  c2_t68 = c2_L4 * c2_t53 * c2_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 38);
  c2_t69 = c2_L5 * c2_t52 * c2_t59;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 39);
  c2_t70 = c2_L8 * c2_t52 * c2_t53;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 40);
  c2_t71 = c2_L6 * c2_t52 * c2_t59 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 41);
  c2_t72 = c2_L7 * c2_t52 * c2_t59 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 42);
  c2_t73 = c2_L6 + c2_L7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 43);
  c2_t74 = c2_t52 * c2_t53;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 44);
  c2_t75 = c2_t52 * c2_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 45);
  c2_t76 = c2_t59 * c2_t60 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 46);
  c2_t77 = c2_t75 + c2_t76;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 47);
  c2_t78 = c2_t56 * c2_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 48);
  c2_t79 = c2_t78 - c2_t52 * c2_t59 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 49);
  c2_t80 = c2_t52 * c2_t59;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 50);
  c2_t81 = c2_t80 - c2_t56 * c2_t60 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 51);
  c2_t82 = -c2_t59 * c2_t60 - c2_t52 * c2_t56 * c2_t61;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 52);
  c2_u_x[0] = ((((((((((((((((c2_L2 * c2_t52 * c2_t53 + c2_L3 * c2_t52 * c2_t53 *
    c2_t57) + c2_L4 * c2_t52 * c2_t53 * c2_t54 * c2_t58) + c2_L4 * c2_t52 *
    c2_t53 * c2_t55 * c2_t57) + c2_L5 * c2_t52 * c2_t53 * c2_t54 * c2_t55) -
    c2_L5 * c2_t52 * c2_t53 * c2_t57 * c2_t58) + c2_L8 * c2_t52 * c2_t54 *
    c2_t55 * c2_t59) + c2_L8 * c2_t53 * c2_t54 * c2_t56 * c2_t58) + c2_L8 *
                       c2_t53 * c2_t55 * c2_t56 * c2_t57) - c2_L8 * c2_t52 *
                      c2_t57 * c2_t58 * c2_t59) + c2_L9 * c2_t52 * c2_t54 *
                     c2_t55 * c2_t56) - c2_L9 * c2_t52 * c2_t56 * c2_t57 *
                    c2_t58) - c2_L9 * c2_t53 * c2_t54 * c2_t58 * c2_t59) - c2_L9
                  * c2_t53 * c2_t55 * c2_t57 * c2_t59) - c2_L8 * c2_t54 * c2_t55
                 * c2_t56 * c2_t60 * c2_t61) + c2_L8 * c2_t56 * c2_t57 * c2_t58 *
                c2_t60 * c2_t61) + c2_L9 * c2_t54 * c2_t55 * c2_t59 * c2_t60 *
               c2_t61) - c2_L9 * c2_t57 * c2_t58 * c2_t59 * c2_t60 * c2_t61;
  c2_u_x[1] = ((((((((((((((((((((((((((c2_L2 * c2_t56 * c2_t60 - c2_L2 * c2_t52
    * c2_t59 * c2_t61) + c2_L3 * c2_t56 * c2_t57 * c2_t60) + c2_L9 * c2_t54 *
    c2_t58 * c2_t61) + c2_L9 * c2_t55 * c2_t57 * c2_t61) - c2_L3 * c2_t52 *
    c2_t57 * c2_t59 * c2_t61) + c2_L4 * c2_t54 * c2_t56 * c2_t58 * c2_t60) +
    c2_L4 * c2_t55 * c2_t56 * c2_t57 * c2_t60) + c2_L5 * c2_t54 * c2_t55 *
    c2_t56 * c2_t60) - c2_L6 * c2_t52 * c2_t54 * c2_t55 * c2_t59) - c2_L5 *
    c2_t56 * c2_t57 * c2_t58 * c2_t60) - c2_L6 * c2_t53 * c2_t54 * c2_t56 *
    c2_t58) - c2_L6 * c2_t53 * c2_t55 * c2_t56 * c2_t57) + c2_L6 * c2_t52 *
    c2_t57 * c2_t58 * c2_t59) - c2_L7 * c2_t52 * c2_t54 * c2_t55 * c2_t59) -
    c2_L7 * c2_t53 * c2_t54 * c2_t56 * c2_t58) - c2_L7 * c2_t53 * c2_t55 *
    c2_t56 * c2_t57) + c2_L7 * c2_t52 * c2_t57 * c2_t58 * c2_t59) + c2_L9 *
                       c2_t53 * c2_t54 * c2_t55 * c2_t60) - c2_L9 * c2_t53 *
                      c2_t57 * c2_t58 * c2_t60) - c2_L4 * c2_t52 * c2_t54 *
                     c2_t58 * c2_t59 * c2_t61) - c2_L4 * c2_t52 * c2_t55 *
                    c2_t57 * c2_t59 * c2_t61) - c2_L5 * c2_t52 * c2_t54 * c2_t55
                   * c2_t59 * c2_t61) + c2_L5 * c2_t52 * c2_t57 * c2_t58 *
                  c2_t59 * c2_t61) + c2_L6 * c2_t54 * c2_t55 * c2_t56 * c2_t60 *
                 c2_t61) - c2_L6 * c2_t56 * c2_t57 * c2_t58 * c2_t60 * c2_t61) +
               c2_L7 * c2_t54 * c2_t55 * c2_t56 * c2_t60 * c2_t61) - c2_L7 *
    c2_t56 * c2_t57 * c2_t58 * c2_t60 * c2_t61;
  c2_u_x[2] = ((((((((((((((((((((((((((-c2_L2 * c2_t59 * c2_t60 - c2_L2 *
    c2_t52 * c2_t56 * c2_t61) - c2_L3 * c2_t57 * c2_t59 * c2_t60) - c2_L8 *
    c2_t54 * c2_t58 * c2_t61) - c2_L8 * c2_t55 * c2_t57 * c2_t61) - c2_L3 *
    c2_t52 * c2_t56 * c2_t57 * c2_t61) - c2_L4 * c2_t54 * c2_t58 * c2_t59 *
    c2_t60) - c2_L4 * c2_t55 * c2_t57 * c2_t59 * c2_t60) - c2_L6 * c2_t52 *
    c2_t54 * c2_t55 * c2_t56) - c2_L5 * c2_t54 * c2_t55 * c2_t59 * c2_t60) +
    c2_L6 * c2_t52 * c2_t56 * c2_t57 * c2_t58) + c2_L5 * c2_t57 * c2_t58 *
    c2_t59 * c2_t60) + c2_L6 * c2_t53 * c2_t54 * c2_t58 * c2_t59) + c2_L6 *
    c2_t53 * c2_t55 * c2_t57 * c2_t59) - c2_L7 * c2_t52 * c2_t54 * c2_t55 *
    c2_t56) + c2_L7 * c2_t52 * c2_t56 * c2_t57 * c2_t58) + c2_L7 * c2_t53 *
    c2_t54 * c2_t58 * c2_t59) + c2_L7 * c2_t53 * c2_t55 * c2_t57 * c2_t59) -
                       c2_L8 * c2_t53 * c2_t54 * c2_t55 * c2_t60) + c2_L8 *
                      c2_t53 * c2_t57 * c2_t58 * c2_t60) - c2_L4 * c2_t52 *
                     c2_t54 * c2_t56 * c2_t58 * c2_t61) - c2_L4 * c2_t52 *
                    c2_t55 * c2_t56 * c2_t57 * c2_t61) - c2_L5 * c2_t52 * c2_t54
                   * c2_t55 * c2_t56 * c2_t61) + c2_L5 * c2_t52 * c2_t56 *
                  c2_t57 * c2_t58 * c2_t61) - c2_L6 * c2_t54 * c2_t55 * c2_t59 *
                 c2_t60 * c2_t61) + c2_L6 * c2_t57 * c2_t58 * c2_t59 * c2_t60 *
                c2_t61) - c2_L7 * c2_t54 * c2_t55 * c2_t59 * c2_t60 * c2_t61) +
    c2_L7 * c2_t57 * c2_t58 * c2_t59 * c2_t60 * c2_t61;
  c2_u_x[3] = -c2_t54 * (c2_t58 * c2_t61 + c2_t53 * c2_t55 * c2_t60) - c2_t57 *
    (c2_t55 * c2_t61 - c2_t53 * c2_t58 * c2_t60);
  c2_u_x[4] = c2_t54 * (c2_t55 * c2_t77 - c2_t53 * c2_t58 * c2_t59) - c2_t57 *
    (c2_t58 * c2_t77 + c2_t53 * c2_t55 * c2_t59);
  c2_u_x[5] = -c2_t54 * (c2_t55 * c2_t81 + c2_t53 * c2_t56 * c2_t58) + c2_t57 *
    (c2_t58 * c2_t81 - c2_t53 * c2_t55 * c2_t56);
  c2_u_x[6] = ((((((c2_t62 + c2_t63) + c2_t64) + c2_t65) + c2_t66) + c2_L3 *
                c2_t55 * c2_t61) - c2_L3 * c2_t53 * c2_t58 * c2_t60) - c2_L9 *
    c2_t52 * c2_t59 * c2_t61;
  c2_u_x[7] = (((((((((c2_t67 - c2_L5 * c2_t52 * c2_t56) - c2_L6 * c2_t59 *
                      c2_t60) - c2_L7 * c2_t59 * c2_t60) - c2_L9 * c2_t52 *
                    c2_t53) + c2_L3 * c2_t52 * c2_t56 * c2_t58) + c2_L3 * c2_t53
                  * c2_t55 * c2_t59) - c2_L6 * c2_t52 * c2_t56 * c2_t61) - c2_L5
                * c2_t59 * c2_t60 * c2_t61) - c2_L7 * c2_t52 * c2_t56 * c2_t61)
    + c2_L3 * c2_t58 * c2_t59 * c2_t60 * c2_t61;
  c2_u_x[8] = (((((((((c2_t68 + c2_t69) + c2_t70) + c2_t71) + c2_t72) - c2_L6 *
                   c2_t56 * c2_t60) - c2_L7 * c2_t56 * c2_t60) + c2_L3 * c2_t53 *
                 c2_t55 * c2_t56) - c2_L3 * c2_t52 * c2_t58 * c2_t59) - c2_L5 *
               c2_t56 * c2_t60 * c2_t61) + c2_L3 * c2_t56 * c2_t58 * c2_t60 *
    c2_t61;
  c2_u_x[9] = c2_t74;
  c2_u_x[10] = c2_t79;
  c2_u_x[11] = c2_t82;
  c2_u_x[12] = ((((c2_t62 + c2_t63) + c2_t64) + c2_t65) + c2_t66) - c2_L9 *
    c2_t52 * c2_t59 * c2_t61;
  c2_u_x[13] = ((((((c2_t67 - c2_L5 * c2_t52 * c2_t56) - c2_L6 * c2_t59 * c2_t60)
                   - c2_L7 * c2_t59 * c2_t60) - c2_L9 * c2_t52 * c2_t53) - c2_L6
                 * c2_t52 * c2_t56 * c2_t61) - c2_L5 * c2_t59 * c2_t60 * c2_t61)
    - c2_L7 * c2_t52 * c2_t56 * c2_t61;
  c2_u_x[14] = ((((((c2_t68 + c2_t69) + c2_t70) + c2_t71) + c2_t72) - c2_L6 *
                 c2_t56 * c2_t60) - c2_L7 * c2_t56 * c2_t60) - c2_L5 * c2_t56 *
    c2_t60 * c2_t61;
  c2_u_x[15] = c2_t74;
  c2_u_x[16] = c2_t79;
  c2_u_x[17] = c2_t82;
  c2_u_x[18] = -c2_t53 * (c2_L8 * c2_t56 - c2_L9 * c2_t59);
  c2_u_x[19] = (-c2_L9 * c2_t61 + c2_L6 * c2_t53 * c2_t56) + c2_L7 * c2_t53 *
    c2_t56;
  c2_u_x[20] = (c2_L8 * c2_t61 - c2_L6 * c2_t53 * c2_t59) - c2_L7 * c2_t53 *
    c2_t59;
  c2_u_x[21] = c2_t61;
  c2_u_x[22] = c2_t53 * c2_t59;
  c2_u_x[23] = c2_t53 * c2_t56;
  c2_u_x[24] = c2_L8 * c2_t59 + c2_L9 * c2_t56;
  c2_u_x[25] = -c2_t59 * c2_t73;
  c2_u_x[26] = -c2_t56 * c2_t73;
  c2_u_x[27] = 0.0;
  c2_u_x[28] = c2_t56;
  c2_u_x[29] = -c2_t59;
  c2_u_x[30] = 0.0;
  c2_u_x[31] = -c2_L9;
  c2_u_x[32] = c2_L8;
  c2_u_x[33] = 1.0;
  c2_u_x[34] = 0.0;
  c2_u_x[35] = 0.0;
  c2_b_eml_int_forloop_overflow_check(chartInstance);
  for (c2_k = 1; c2_k < 37; c2_k++) {
    c2_b_k = c2_k;
    c2_b_body_Jacobian[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 36, 1, 0) - 1] =
      c2_u_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, -52);
  sf_debug_symbol_scope_pop();
}

static void c2_b_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void c2_AdjointInv(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_g[16], real_T c2_Adg_inv[36])
{
  uint32_T c2_debug_family_var_map[7];
  real_T c2_RT[9];
  real_T c2_p[3];
  real_T c2_ze[9];
  real_T c2_nargin = 1.0;
  real_T c2_nargout = 1.0;
  boolean_T c2_y;
  int32_T c2_k;
  real_T c2_b_k;
  boolean_T c2_b0;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  int32_T c2_i78;
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  real_T c2_w[3];
  uint32_T c2_b_debug_family_var_map[4];
  real_T c2_b_nargin = 1.0;
  real_T c2_b_nargout = 1.0;
  real_T c2_wh[9];
  int32_T c2_i82;
  real_T c2_a[9];
  int32_T c2_i83;
  real_T c2_b[9];
  int32_T c2_i84;
  int32_T c2_i85;
  int32_T c2_i86;
  real_T c2_b_y[9];
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  int32_T c2_i98;
  int32_T c2_i99;
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  int32_T c2_i103;
  int32_T c2_i104;
  boolean_T exitg1;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c2_e_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c2_RT, 0U, c2_h_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_p, 1U, c2_c_sf_marshallOut,
    c2_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_ze, 2U, c2_h_sf_marshallOut,
    c2_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 3U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 4U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_g, 5U, c2_f_sf_marshallOut,
    c2_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Adg_inv, 6U, c2_e_sf_marshallOut,
    c2_d_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 3);
  c2_y = FALSE;
  c2_k = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (c2_k < 2)) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_b0 = TRUE;
    if (!c2_b0) {
      c2_y = TRUE;
      exitg1 = TRUE;
    } else {
      c2_k++;
    }
  }

  CV_SCRIPT_IF(2, 0, c2_y);
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 7);
  c2_i75 = 0;
  for (c2_i76 = 0; c2_i76 < 3; c2_i76++) {
    c2_i77 = 0;
    for (c2_i78 = 0; c2_i78 < 3; c2_i78++) {
      c2_RT[c2_i78 + c2_i75] = c2_g[c2_i77 + c2_i76];
      c2_i77 += 4;
    }

    c2_i75 += 3;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 8);
  for (c2_i79 = 0; c2_i79 < 3; c2_i79++) {
    c2_p[c2_i79] = c2_g[c2_i79 + 12];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 9);
  for (c2_i80 = 0; c2_i80 < 9; c2_i80++) {
    c2_ze[c2_i80] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 10);
  for (c2_i81 = 0; c2_i81 < 3; c2_i81++) {
    c2_w[c2_i81] = c2_p[c2_i81];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c2_d_debug_family_names,
    c2_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargin, 0U, c2_d_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_b_nargout, 1U,
    c2_d_sf_marshallOut, c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_w, 2U, c2_c_sf_marshallOut,
    c2_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_wh, 3U, c2_h_sf_marshallOut,
    c2_g_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 3);
  CV_SCRIPT_IF(3, 0, FALSE);
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, 20);
  c2_wh[0] = 0.0;
  c2_wh[3] = -c2_w[2];
  c2_wh[6] = c2_w[1];
  c2_wh[1] = c2_w[2];
  c2_wh[4] = 0.0;
  c2_wh[7] = -c2_w[0];
  c2_wh[2] = -c2_w[1];
  c2_wh[5] = c2_w[0];
  c2_wh[8] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c2_sfEvent, -20);
  sf_debug_symbol_scope_pop();
  for (c2_i82 = 0; c2_i82 < 9; c2_i82++) {
    c2_a[c2_i82] = -c2_RT[c2_i82];
  }

  for (c2_i83 = 0; c2_i83 < 9; c2_i83++) {
    c2_b[c2_i83] = c2_wh[c2_i83];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  for (c2_i84 = 0; c2_i84 < 3; c2_i84++) {
    c2_i85 = 0;
    for (c2_i86 = 0; c2_i86 < 3; c2_i86++) {
      c2_b_y[c2_i85 + c2_i84] = 0.0;
      c2_i87 = 0;
      for (c2_i88 = 0; c2_i88 < 3; c2_i88++) {
        c2_b_y[c2_i85 + c2_i84] += c2_a[c2_i87 + c2_i84] * c2_b[c2_i88 + c2_i85];
        c2_i87 += 3;
      }

      c2_i85 += 3;
    }
  }

  c2_i89 = 0;
  c2_i90 = 0;
  for (c2_i91 = 0; c2_i91 < 3; c2_i91++) {
    for (c2_i92 = 0; c2_i92 < 3; c2_i92++) {
      c2_Adg_inv[c2_i92 + c2_i89] = c2_RT[c2_i92 + c2_i90];
    }

    c2_i89 += 6;
    c2_i90 += 3;
  }

  c2_i93 = 0;
  c2_i94 = 0;
  for (c2_i95 = 0; c2_i95 < 3; c2_i95++) {
    for (c2_i96 = 0; c2_i96 < 3; c2_i96++) {
      c2_Adg_inv[(c2_i96 + c2_i93) + 18] = c2_b_y[c2_i96 + c2_i94];
    }

    c2_i93 += 6;
    c2_i94 += 3;
  }

  c2_i97 = 0;
  c2_i98 = 0;
  for (c2_i99 = 0; c2_i99 < 3; c2_i99++) {
    for (c2_i100 = 0; c2_i100 < 3; c2_i100++) {
      c2_Adg_inv[(c2_i100 + c2_i97) + 3] = c2_ze[c2_i100 + c2_i98];
    }

    c2_i97 += 6;
    c2_i98 += 3;
  }

  c2_i101 = 0;
  c2_i102 = 0;
  for (c2_i103 = 0; c2_i103 < 3; c2_i103++) {
    for (c2_i104 = 0; c2_i104 < 3; c2_i104++) {
      c2_Adg_inv[(c2_i104 + c2_i101) + 21] = c2_RT[c2_i104 + c2_i102];
    }

    c2_i101 += 6;
    c2_i102 += 3;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, -10);
  sf_debug_symbol_scope_pop();
}

static void c2_eml_scalar_eg(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c2_mldivide(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_A[36], real_T c2_B[36], real_T c2_Y[36])
{
  int32_T c2_i105;
  real_T c2_b_A[36];
  int32_T c2_info;
  int32_T c2_ipiv[6];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_i106;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_ip;
  int32_T c2_j;
  int32_T c2_b_j;
  real_T c2_temp;
  int32_T c2_i107;
  real_T c2_c_A[36];
  int32_T c2_c_j;
  int32_T c2_d_j;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_b_b;
  int32_T c2_jBcol;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_b_a;
  int32_T c2_c_c;
  int32_T c2_c_b;
  int32_T c2_d_c;
  int32_T c2_d_b;
  int32_T c2_kAcol;
  int32_T c2_c_a;
  int32_T c2_e_b;
  int32_T c2_e_c;
  int32_T c2_d_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_e_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_f_a;
  int32_T c2_h_b;
  int32_T c2_h_c;
  real_T c2_x;
  real_T c2_y;
  real_T c2_z;
  int32_T c2_g_a;
  int32_T c2_i108;
  int32_T c2_c_i;
  int32_T c2_d_i;
  int32_T c2_h_a;
  int32_T c2_i_b;
  int32_T c2_i_c;
  int32_T c2_i_a;
  int32_T c2_j_b;
  int32_T c2_j_c;
  int32_T c2_j_a;
  int32_T c2_k_b;
  int32_T c2_k_c;
  int32_T c2_k_a;
  int32_T c2_l_b;
  int32_T c2_l_c;
  for (c2_i105 = 0; c2_i105 < 36; c2_i105++) {
    c2_b_A[c2_i105] = c2_A[c2_i105];
  }

  c2_b_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, &c2_info);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if ((real_T)c2_d_info > 0.0) {
    c2_eml_warning(chartInstance);
  }

  for (c2_i106 = 0; c2_i106 < 36; c2_i106++) {
    c2_Y[c2_i106] = c2_B[c2_i106];
  }

  c2_e_eml_int_forloop_overflow_check(chartInstance);
  for (c2_i = 1; c2_i < 7; c2_i++) {
    c2_b_i = c2_i;
    if (c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 6, 1, 0) - 1] != c2_b_i) {
      c2_ip = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 6, 1, 0) - 1];
      c2_e_eml_int_forloop_overflow_check(chartInstance);
      for (c2_j = 1; c2_j < 7; c2_j++) {
        c2_b_j = c2_j;
        c2_temp = c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 6, 1, 0) + 6 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 6, 2, 0) - 1)) - 1];
        c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_i), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 6, 2, 0)
               - 1)) - 1] = c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ip), 1, 6, 1, 0) + 6 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 6, 2, 0) - 1)) - 1];
        c2_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_ip), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
                "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_j), 1, 6, 2, 0)
               - 1)) - 1] = c2_temp;
      }
    }
  }

  for (c2_i107 = 0; c2_i107 < 36; c2_i107++) {
    c2_c_A[c2_i107] = c2_b_A[c2_i107];
  }

  c2_b_eml_xtrsm(chartInstance, c2_c_A, c2_Y);
  c2_below_threshold(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  c2_e_eml_int_forloop_overflow_check(chartInstance);
  for (c2_c_j = 1; c2_c_j < 7; c2_c_j++) {
    c2_d_j = c2_c_j;
    c2_a = c2_d_j;
    c2_c = c2_a;
    c2_b = c2_c - 1;
    c2_b_c = 6 * c2_b;
    c2_b_b = c2_b_c;
    c2_jBcol = c2_b_b;
    c2_g_eml_int_forloop_overflow_check(chartInstance);
    for (c2_k = 6; c2_k > 0; c2_k--) {
      c2_b_k = c2_k;
      c2_b_a = c2_b_k;
      c2_c_c = c2_b_a;
      c2_c_b = c2_c_c - 1;
      c2_d_c = 6 * c2_c_b;
      c2_d_b = c2_d_c;
      c2_kAcol = c2_d_b;
      c2_c_a = c2_b_k;
      c2_e_b = c2_jBcol;
      c2_e_c = c2_c_a + c2_e_b;
      if (c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_e_c), 1, 36, 1, 0) - 1] != 0.0) {
        c2_d_a = c2_b_k;
        c2_f_b = c2_jBcol;
        c2_f_c = c2_d_a + c2_f_b;
        c2_e_a = c2_b_k;
        c2_g_b = c2_jBcol;
        c2_g_c = c2_e_a + c2_g_b;
        c2_f_a = c2_b_k;
        c2_h_b = c2_kAcol;
        c2_h_c = c2_f_a + c2_h_b;
        c2_x = c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_g_c), 1, 36, 1, 0) - 1];
        c2_y = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_h_c), 1, 36, 1, 0) - 1];
        c2_z = c2_x / c2_y;
        c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_f_c), 1, 36, 1, 0) - 1] = c2_z;
        c2_g_a = c2_b_k - 1;
        c2_i108 = c2_g_a;
        c2_f_eml_int_forloop_overflow_check(chartInstance, 1, c2_i108);
        for (c2_c_i = 1; c2_c_i <= c2_i108; c2_c_i++) {
          c2_d_i = c2_c_i;
          c2_h_a = c2_d_i;
          c2_i_b = c2_jBcol;
          c2_i_c = c2_h_a + c2_i_b;
          c2_i_a = c2_d_i;
          c2_j_b = c2_jBcol;
          c2_j_c = c2_i_a + c2_j_b;
          c2_j_a = c2_b_k;
          c2_k_b = c2_jBcol;
          c2_k_c = c2_j_a + c2_k_b;
          c2_k_a = c2_d_i;
          c2_l_b = c2_kAcol;
          c2_l_c = c2_k_a + c2_l_b;
          c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_i_c), 1, 36, 1, 0) - 1] =
            c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_j_c), 1, 36, 1, 0) - 1] -
            c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_k_c), 1, 36, 1, 0) - 1] *
            c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c2_l_c), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void c2_realmin(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c2_eps(SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void c2_eml_matlab_zgetrf(SFc2_CtrPlatform_AdaptiveControlInstanceStruct *
  chartInstance, real_T c2_A[36], real_T c2_b_A[36], int32_T c2_ipiv[6], int32_T
  *c2_info)
{
  int32_T c2_i109;
  for (c2_i109 = 0; c2_i109 < 36; c2_i109++) {
    c2_b_A[c2_i109] = c2_A[c2_i109];
  }

  c2_b_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, c2_info);
}

static void c2_c_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static int32_T c2_eml_ixamax(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, int32_T c2_n, real_T c2_x[36], int32_T c2_ix0)
{
  int32_T c2_idxmax;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_ix;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_smax;
  int32_T c2_loop_ub;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_a;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_c_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_d_y;
  real_T c2_s;
  c2_b_n = c2_n;
  c2_b_ix0 = c2_ix0;
  c2_c_n = c2_b_n;
  c2_c_ix0 = c2_b_ix0;
  if ((real_T)c2_c_n < 1.0) {
    c2_idxmax = 0;
  } else {
    c2_idxmax = 1;
    if ((real_T)c2_c_n > 1.0) {
      c2_ix = c2_c_ix0;
      c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_ix), 1, 36, 1, 0) - 1];
      c2_c_x = c2_b_x;
      c2_d_x = c2_c_x;
      c2_y = muDoubleScalarAbs(c2_d_x);
      c2_e_x = 0.0;
      c2_f_x = c2_e_x;
      c2_b_y = muDoubleScalarAbs(c2_f_x);
      c2_smax = c2_y + c2_b_y;
      c2_d_eml_int_forloop_overflow_check(chartInstance, c2_c_n);
      c2_loop_ub = c2_c_n;
      for (c2_k = 2; c2_k <= c2_loop_ub; c2_k++) {
        c2_b_k = c2_k;
        c2_a = c2_ix + 1;
        c2_ix = c2_a;
        c2_g_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 36, 1, 0) - 1];
        c2_h_x = c2_g_x;
        c2_i_x = c2_h_x;
        c2_c_y = muDoubleScalarAbs(c2_i_x);
        c2_j_x = 0.0;
        c2_k_x = c2_j_x;
        c2_d_y = muDoubleScalarAbs(c2_k_x);
        c2_s = c2_c_y + c2_d_y;
        if (c2_s > c2_smax) {
          c2_idxmax = c2_b_k;
          c2_smax = c2_s;
        }
      }
    }
  }

  return c2_idxmax;
}

static void c2_d_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c2_b)
{
  int32_T c2_b_b;
  boolean_T c2_overflow;
  boolean_T c2_safe;
  int32_T c2_i110;
  static char_T c2_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i111;
  static char_T c2_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_b_b = c2_b;
  if (2 > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  c2_safe = !c2_overflow;
  if (c2_safe) {
  } else {
    for (c2_i110 = 0; c2_i110 < 34; c2_i110++) {
      c2_u[c2_i110] = c2_cv0[c2_i110];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i111 = 0; c2_i111 < 5; c2_i111++) {
      c2_b_u[c2_i111] = c2_cv1[c2_i111];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_e_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void c2_f_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, int32_T c2_a,
   int32_T c2_b)
{
  int32_T c2_b_a;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  boolean_T c2_safe;
  int32_T c2_i112;
  static char_T c2_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i113;
  static char_T c2_cv3[5] = { 'i', 'n', 't', '3', '2' };

  char_T c2_b_u[5];
  const mxArray *c2_b_y = NULL;
  c2_b_a = c2_a;
  c2_b_b = c2_b;
  if (c2_b_a > c2_b_b) {
    c2_overflow = FALSE;
  } else {
    c2_overflow = (c2_b_b > 2147483646);
  }

  c2_safe = !c2_overflow;
  if (c2_safe) {
  } else {
    for (c2_i112 = 0; c2_i112 < 34; c2_i112++) {
      c2_u[c2_i112] = c2_cv2[c2_i112];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c2_i113 = 0; c2_i113 < 5; c2_i113++) {
      c2_b_u[c2_i113] = c2_cv3[c2_i113];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c2_y, 14, c2_b_y));
  }
}

static void c2_eml_warning(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
  int32_T c2_i114;
  static char_T c2_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c2_u[27];
  const mxArray *c2_y = NULL;
  for (c2_i114 = 0; c2_i114 < 27; c2_i114++) {
    c2_u[c2_i114] = c2_varargin_1[c2_i114];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c2_y));
}

static void c2_eml_xtrsm(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_A[36], real_T c2_B[36], real_T c2_b_B[36])
{
  int32_T c2_i115;
  int32_T c2_i116;
  real_T c2_b_A[36];
  for (c2_i115 = 0; c2_i115 < 36; c2_i115++) {
    c2_b_B[c2_i115] = c2_B[c2_i115];
  }

  for (c2_i116 = 0; c2_i116 < 36; c2_i116++) {
    c2_b_A[c2_i116] = c2_A[c2_i116];
  }

  c2_b_eml_xtrsm(chartInstance, c2_b_A, c2_b_B);
}

static void c2_below_threshold(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c2_b_eml_scalar_eg(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static void c2_g_eml_int_forloop_overflow_check
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void c2_c_eml_scalar_eg(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_j_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i117;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i117, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i117;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_k_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_b_is_active_c2_CtrPlatform_AdaptiveControl, const char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_CtrPlatform_AdaptiveControl), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_CtrPlatform_AdaptiveControl);
  return c2_y;
}

static uint8_T c2_l_emlrt_marshallIn
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray *
   c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_eml_matlab_zgetrf
  (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, real_T c2_A[36],
   int32_T c2_ipiv[6], int32_T *c2_info)
{
  int32_T c2_i118;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_jm1;
  int32_T c2_b;
  int32_T c2_mmj;
  int32_T c2_b_a;
  int32_T c2_c;
  int32_T c2_b_b;
  int32_T c2_jj;
  int32_T c2_c_a;
  int32_T c2_jp1j;
  int32_T c2_d_a;
  int32_T c2_b_c;
  int32_T c2_i119;
  int32_T c2_i120;
  int32_T c2_i121;
  real_T c2_b_A[36];
  int32_T c2_e_a;
  int32_T c2_jpiv_offset;
  int32_T c2_f_a;
  int32_T c2_c_b;
  int32_T c2_jpiv;
  int32_T c2_g_a;
  int32_T c2_d_b;
  int32_T c2_c_c;
  int32_T c2_e_b;
  int32_T c2_jrow;
  int32_T c2_h_a;
  int32_T c2_f_b;
  int32_T c2_jprow;
  int32_T c2_ix0;
  int32_T c2_iy0;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  real_T c2_temp;
  int32_T c2_i_a;
  int32_T c2_j_a;
  int32_T c2_b_jp1j;
  int32_T c2_k_a;
  int32_T c2_d_c;
  int32_T c2_l_a;
  int32_T c2_g_b;
  int32_T c2_i122;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_x;
  real_T c2_y;
  real_T c2_z;
  int32_T c2_h_b;
  int32_T c2_e_c;
  int32_T c2_m_a;
  int32_T c2_f_c;
  int32_T c2_n_a;
  int32_T c2_g_c;
  int32_T c2_m;
  int32_T c2_n;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_ia0;
  int32_T c2_b_m;
  int32_T c2_b_n;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_b_ia0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  int32_T c2_f_ix0;
  int32_T c2_f_iy0;
  int32_T c2_c_ia0;
  int32_T c2_d_m;
  int32_T c2_d_n;
  int32_T c2_g_ix0;
  int32_T c2_g_iy0;
  int32_T c2_d_ia0;
  int32_T c2_e_m;
  int32_T c2_e_n;
  int32_T c2_h_ix0;
  int32_T c2_h_iy0;
  int32_T c2_e_ia0;
  int32_T c2_ixstart;
  int32_T c2_o_a;
  int32_T c2_jA;
  int32_T c2_jy;
  int32_T c2_loop_ub;
  int32_T c2_c_j;
  real_T c2_yjy;
  real_T c2_b_temp;
  int32_T c2_b_ix;
  int32_T c2_i_b;
  int32_T c2_i123;
  int32_T c2_p_a;
  int32_T c2_j_b;
  int32_T c2_i124;
  int32_T c2_ijA;
  int32_T c2_b_ijA;
  int32_T c2_q_a;
  int32_T c2_r_a;
  int32_T c2_s_a;
  c2_realmin(chartInstance);
  c2_eps(chartInstance);
  for (c2_i118 = 0; c2_i118 < 6; c2_i118++) {
    c2_ipiv[c2_i118] = 1 + c2_i118;
  }

  *c2_info = 0;
  c2_c_eml_int_forloop_overflow_check(chartInstance);
  for (c2_j = 1; c2_j < 6; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j - 1;
    c2_jm1 = c2_a;
    c2_b = c2_b_j;
    c2_mmj = 6 - c2_b;
    c2_b_a = c2_jm1;
    c2_c = c2_b_a * 7;
    c2_b_b = c2_c + 1;
    c2_jj = c2_b_b;
    c2_c_a = c2_jj + 1;
    c2_jp1j = c2_c_a;
    c2_d_a = c2_mmj;
    c2_b_c = c2_d_a;
    c2_i119 = 0;
    for (c2_i120 = 0; c2_i120 < 6; c2_i120++) {
      for (c2_i121 = 0; c2_i121 < 6; c2_i121++) {
        c2_b_A[c2_i121 + c2_i119] = c2_A[c2_i121 + c2_i119];
      }

      c2_i119 += 6;
    }

    c2_e_a = c2_eml_ixamax(chartInstance, c2_b_c + 1, c2_b_A, c2_jj) - 1;
    c2_jpiv_offset = c2_e_a;
    c2_f_a = c2_jj;
    c2_c_b = c2_jpiv_offset;
    c2_jpiv = c2_f_a + c2_c_b;
    if (c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c2_jpiv_offset != 0.0) {
        c2_g_a = c2_b_j;
        c2_d_b = c2_jpiv_offset;
        c2_c_c = c2_g_a + c2_d_b;
        c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 6, 1, 0) - 1] = c2_c_c;
        c2_e_b = c2_jm1 + 1;
        c2_jrow = c2_e_b;
        c2_h_a = c2_jrow;
        c2_f_b = c2_jpiv_offset;
        c2_jprow = c2_h_a + c2_f_b;
        c2_ix0 = c2_jrow;
        c2_iy0 = c2_jprow;
        c2_b_ix0 = c2_ix0;
        c2_b_iy0 = c2_iy0;
        c2_c_ix0 = c2_b_ix0;
        c2_c_iy0 = c2_b_iy0;
        c2_ix = c2_c_ix0;
        c2_iy = c2_c_iy0;
        c2_e_eml_int_forloop_overflow_check(chartInstance);
        for (c2_k = 1; c2_k < 7; c2_k++) {
          c2_temp = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 36, 1, 0) - 1];
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_ix), 1, 36, 1, 0) - 1] = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK
            ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_iy), 1, 36, 1, 0) -
            1];
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy), 1, 36, 1, 0) - 1] = c2_temp;
          c2_i_a = c2_ix + 6;
          c2_ix = c2_i_a;
          c2_j_a = c2_iy + 6;
          c2_iy = c2_j_a;
        }
      }

      c2_b_jp1j = c2_jp1j;
      c2_k_a = c2_mmj;
      c2_d_c = c2_k_a;
      c2_l_a = c2_jp1j;
      c2_g_b = c2_d_c - 1;
      c2_i122 = c2_l_a + c2_g_b;
      c2_f_eml_int_forloop_overflow_check(chartInstance, c2_b_jp1j, c2_i122);
      for (c2_i = c2_b_jp1j; c2_i <= c2_i122; c2_i++) {
        c2_b_i = c2_i;
        c2_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_b_i), 1, 36, 1, 0) - 1];
        c2_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c2_jj), 1, 36, 1, 0) - 1];
        c2_z = c2_x / c2_y;
        c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 36, 1, 0) - 1] = c2_z;
      }
    } else {
      *c2_info = c2_b_j;
    }

    c2_h_b = c2_b_j;
    c2_e_c = 6 - c2_h_b;
    c2_m_a = c2_jj;
    c2_f_c = c2_m_a;
    c2_n_a = c2_jj;
    c2_g_c = c2_n_a;
    c2_m = c2_mmj;
    c2_n = c2_e_c;
    c2_d_ix0 = c2_jp1j;
    c2_d_iy0 = c2_f_c + 6;
    c2_ia0 = c2_g_c + 7;
    c2_b_m = c2_m;
    c2_b_n = c2_n;
    c2_e_ix0 = c2_d_ix0;
    c2_e_iy0 = c2_d_iy0;
    c2_b_ia0 = c2_ia0;
    c2_c_m = c2_b_m;
    c2_c_n = c2_b_n;
    c2_f_ix0 = c2_e_ix0;
    c2_f_iy0 = c2_e_iy0;
    c2_c_ia0 = c2_b_ia0;
    c2_d_m = c2_c_m;
    c2_d_n = c2_c_n;
    c2_g_ix0 = c2_f_ix0;
    c2_g_iy0 = c2_f_iy0;
    c2_d_ia0 = c2_c_ia0;
    c2_e_m = c2_d_m;
    c2_e_n = c2_d_n;
    c2_h_ix0 = c2_g_ix0;
    c2_h_iy0 = c2_g_iy0;
    c2_e_ia0 = c2_d_ia0;
    c2_ixstart = c2_h_ix0;
    c2_o_a = c2_e_ia0 - 1;
    c2_jA = c2_o_a;
    c2_jy = c2_h_iy0;
    c2_f_eml_int_forloop_overflow_check(chartInstance, 1, c2_e_n);
    c2_loop_ub = c2_e_n;
    for (c2_c_j = 1; c2_c_j <= c2_loop_ub; c2_c_j++) {
      c2_yjy = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_jy), 1, 36, 1, 0) - 1];
      if (c2_yjy != 0.0) {
        c2_b_temp = -c2_yjy;
        c2_b_ix = c2_ixstart;
        c2_i_b = c2_jA + 1;
        c2_i123 = c2_i_b;
        c2_p_a = c2_e_m;
        c2_j_b = c2_jA;
        c2_i124 = c2_p_a + c2_j_b;
        c2_f_eml_int_forloop_overflow_check(chartInstance, c2_i123, c2_i124);
        for (c2_ijA = c2_i123; c2_ijA <= c2_i124; c2_ijA++) {
          c2_b_ijA = c2_ijA;
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 36, 1, 0) - 1] =
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 36, 1, 0) - 1] +
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ix), 1, 36, 1, 0) - 1] * c2_b_temp;
          c2_q_a = c2_b_ix + 1;
          c2_b_ix = c2_q_a;
        }
      }

      c2_r_a = c2_jy + 6;
      c2_jy = c2_r_a;
      c2_s_a = c2_jA + 6;
      c2_jA = c2_s_a;
    }
  }

  if ((real_T)*c2_info == 0.0) {
    if (!(c2_A[35] != 0.0)) {
      *c2_info = 6;
    }
  }
}

static void c2_b_eml_xtrsm(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c2_A[36], real_T c2_B[36])
{
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_c;
  int32_T c2_b;
  int32_T c2_b_c;
  int32_T c2_b_b;
  int32_T c2_jBcol;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_b_a;
  int32_T c2_c_c;
  int32_T c2_c_b;
  int32_T c2_d_c;
  int32_T c2_d_b;
  int32_T c2_kAcol;
  int32_T c2_c_a;
  int32_T c2_e_b;
  int32_T c2_e_c;
  int32_T c2_d_a;
  int32_T c2_i125;
  int32_T c2_i;
  int32_T c2_b_i;
  int32_T c2_e_a;
  int32_T c2_f_b;
  int32_T c2_f_c;
  int32_T c2_f_a;
  int32_T c2_g_b;
  int32_T c2_g_c;
  int32_T c2_g_a;
  int32_T c2_h_b;
  int32_T c2_h_c;
  int32_T c2_h_a;
  int32_T c2_i_b;
  int32_T c2_i_c;
  c2_below_threshold(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  c2_e_eml_int_forloop_overflow_check(chartInstance);
  for (c2_j = 1; c2_j < 7; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j;
    c2_c = c2_a;
    c2_b = c2_c - 1;
    c2_b_c = 6 * c2_b;
    c2_b_b = c2_b_c;
    c2_jBcol = c2_b_b;
    c2_e_eml_int_forloop_overflow_check(chartInstance);
    for (c2_k = 1; c2_k < 7; c2_k++) {
      c2_b_k = c2_k;
      c2_b_a = c2_b_k;
      c2_c_c = c2_b_a;
      c2_c_b = c2_c_c - 1;
      c2_d_c = 6 * c2_c_b;
      c2_d_b = c2_d_c;
      c2_kAcol = c2_d_b;
      c2_c_a = c2_b_k;
      c2_e_b = c2_jBcol;
      c2_e_c = c2_c_a + c2_e_b;
      if (c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_e_c), 1, 36, 1, 0) - 1] != 0.0) {
        c2_d_a = c2_b_k + 1;
        c2_i125 = c2_d_a;
        c2_f_eml_int_forloop_overflow_check(chartInstance, c2_i125, 6);
        for (c2_i = c2_i125; c2_i < 7; c2_i++) {
          c2_b_i = c2_i;
          c2_e_a = c2_b_i;
          c2_f_b = c2_jBcol;
          c2_f_c = c2_e_a + c2_f_b;
          c2_f_a = c2_b_i;
          c2_g_b = c2_jBcol;
          c2_g_c = c2_f_a + c2_g_b;
          c2_g_a = c2_b_k;
          c2_h_b = c2_jBcol;
          c2_h_c = c2_g_a + c2_h_b;
          c2_h_a = c2_b_i;
          c2_i_b = c2_kAcol;
          c2_i_c = c2_h_a + c2_i_b;
          c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_f_c), 1, 36, 1, 0) - 1] =
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_g_c), 1, 36, 1, 0) - 1] -
            c2_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_h_c), 1, 36, 1, 0) - 1] *
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_i_c), 1, 36, 1, 0) - 1];
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc2_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_CtrPlatform_AdaptiveControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2091929870U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1764869398U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2069981143U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3684087203U);
}

mxArray *sf_c2_CtrPlatform_AdaptiveControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ot4U1nCk49DNl7WZ9fJkKB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(9);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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

static const mxArray *sf_get_sim_state_info_c2_CtrPlatform_AdaptiveControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Omega\",},{M[8],M[0],T\"is_active_c2_CtrPlatform_AdaptiveControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_CtrPlatform_AdaptiveControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
    chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_AdaptiveControlMachineNumber_,
           2,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Omega");
          _SFD_SET_DATA_PROPS(2,1,1,0,"EndVel");
          _SFD_SET_DATA_PROPS(3,10,0,0,"L");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,212);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"fwd_kin",0,-1,3253);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"body_Jacobian",0,-1,3708);
        _SFD_CV_INIT_SCRIPT(2,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"AdjointInv",0,-1,276);
        _SFD_CV_INIT_SCRIPT_IF(2,0,38,63,-1,117);
        _SFD_CV_INIT_SCRIPT(3,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"skew",0,-1,450);
        _SFD_CV_INIT_SCRIPT_IF(3,0,27,44,-1,92);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          real_T (*c2_Theta)[6];
          real_T (*c2_Omega)[6];
          real_T (*c2_EndVel)[3];
          c2_EndVel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c2_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c2_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_Theta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c2_Omega);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_EndVel);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c2_L);
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
  return "odm2FrxfgXtUVCWTM2WOeG";
}

static void sf_opaque_initialize_c2_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
  initialize_c2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  enable_c2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  disable_c2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  sf_c2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_CtrPlatform_AdaptiveControl
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CtrPlatform_AdaptiveControl();/* state var info */
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

extern void sf_internal_set_sim_state_c2_CtrPlatform_AdaptiveControl(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_CtrPlatform_AdaptiveControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_CtrPlatform_AdaptiveControl
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_CtrPlatform_AdaptiveControl(S);
}

static void sf_opaque_set_sim_state_c2_CtrPlatform_AdaptiveControl(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c2_CtrPlatform_AdaptiveControl(S, st);
}

static void sf_opaque_terminate_c2_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_CtrPlatform_AdaptiveControl
      ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_AdaptiveControl_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_CtrPlatform_AdaptiveControl
    ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_CtrPlatform_AdaptiveControl
      ((SFc2_CtrPlatform_AdaptiveControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  /* Actual parameters from chart:
     L
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CtrPlatform_AdaptiveControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(574731732U));
  ssSetChecksum1(S,(149918134U));
  ssSetChecksum2(S,(3508213015U));
  ssSetChecksum3(S,(3960592933U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  SFc2_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc2_CtrPlatform_AdaptiveControlInstanceStruct *)malloc
    (sizeof(SFc2_CtrPlatform_AdaptiveControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_CtrPlatform_AdaptiveControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_CtrPlatform_AdaptiveControl;
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

void c2_CtrPlatform_AdaptiveControl_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_CtrPlatform_AdaptiveControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_CtrPlatform_AdaptiveControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_CtrPlatform_AdaptiveControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_CtrPlatform_AdaptiveControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
