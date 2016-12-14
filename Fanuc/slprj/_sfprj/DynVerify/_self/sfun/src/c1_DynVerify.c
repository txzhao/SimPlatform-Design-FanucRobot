/* Include files */

#include "blascompat32.h"
#include "DynVerify_sfun.h"
#include "c1_DynVerify.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DynVerify_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c1_debug_family_names[10] = { "V", "g", "Jb", "Adg_inv",
  "nargin", "nargout", "EndVel", "Theta", "L", "Omega" };

static const char *c1_b_debug_family_names[68] = { "A1", "A2", "A3", "A4", "A5",
  "A6", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t2", "t3", "t4",
  "t5", "t6", "t7", "t8", "t9", "t10", "t11", "t12", "t13", "t14", "t23", "t15",
  "t16", "t17", "t18", "t19", "t20", "t21", "t22", "t24", "t25", "t26", "t27",
  "t34", "t28", "t29", "t30", "t31", "t32", "t36", "t33", "t35", "t37", "t38",
  "t39", "t40", "t41", "t42", "t43", "t44", "t45", "t47", "t46", "t48", "t49",
  "nargin", "nargout", "in1", "in2", "gst" };

static const char *c1_c_debug_family_names[49] = { "A2", "A3", "A4", "A5", "A6",
  "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t52", "t53", "t54", "t55",
  "t56", "t57", "t58", "t59", "t60", "t61", "t62", "t63", "t64", "t65", "t66",
  "t67", "t68", "t69", "t70", "t71", "t72", "t73", "t74", "t75", "t76", "t77",
  "t78", "t79", "t80", "t81", "t82", "nargin", "nargout", "in1", "in2",
  "body_Jacobian" };

static const char *c1_d_debug_family_names[4] = { "nargin", "nargout", "w", "wh"
};

static const char *c1_e_debug_family_names[7] = { "RT", "p", "ze", "nargin",
  "nargout", "g", "Adg_inv" };

/* Function Declarations */
static void initialize_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance);
static void initialize_params_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance);
static void enable_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance);
static void disable_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance);
static void set_sim_state_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance, const mxArray *c1_st);
static void finalize_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance);
static void sf_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance);
static void c1_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c1_DynVerify
  (SFc1_DynVerifyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static void c1_fwd_kin(SFc1_DynVerifyInstanceStruct *chartInstance, real_T
  c1_in1[9], real_T c1_in2[6], real_T c1_gst[16]);
static void c1_body_Jacobian(SFc1_DynVerifyInstanceStruct *chartInstance, real_T
  c1_in1[9], real_T c1_in2[6], real_T c1_b_body_Jacobian[36]);
static void c1_AdjointInv(SFc1_DynVerifyInstanceStruct *chartInstance, real_T
  c1_g[16], real_T c1_Adg_inv[36]);
static void c1_eml_scalar_eg(SFc1_DynVerifyInstanceStruct *chartInstance);
static void c1_eps(SFc1_DynVerifyInstanceStruct *chartInstance);
static void c1_eml_matlab_zgetrf(SFc1_DynVerifyInstanceStruct *chartInstance,
  real_T c1_A[36], real_T c1_b_A[36], int32_T c1_ipiv[6], int32_T *c1_info);
static int32_T c1_eml_ixamax(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[36], int32_T c1_ix0);
static int32_T c1_ceval_ixamax(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[36], int32_T c1_ix0, int32_T c1_incx);
static void c1_ceval_xswap(SFc1_DynVerifyInstanceStruct *chartInstance, int32_T
  c1_n, real_T c1_x[36], int32_T c1_ix0, int32_T c1_incx, int32_T c1_iy0,
  int32_T c1_incy, real_T c1_b_x[36]);
static void c1_ceval_xger(SFc1_DynVerifyInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0, int32_T c1_incx, int32_T
  c1_iy0, int32_T c1_incy, real_T c1_A[36], int32_T c1_ia0, int32_T c1_lda,
  real_T c1_b_A[36]);
static void c1_eml_warning(SFc1_DynVerifyInstanceStruct *chartInstance);
static void c1_eml_blas_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[36], int32_T c1_ia0,
  int32_T c1_lda, real_T c1_B[36], int32_T c1_ib0, int32_T c1_ldb, real_T
  c1_b_B[36]);
static void c1_ceval_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[36], int32_T c1_ia0, int32_T
  c1_lda, real_T c1_B[36], int32_T c1_ib0, int32_T c1_ldb, real_T c1_b_B[36]);
static void c1_b_eml_blas_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[36], int32_T c1_ia0,
  int32_T c1_lda, real_T c1_B[36], int32_T c1_ib0, int32_T c1_ldb, real_T
  c1_b_B[36]);
static void c1_b_ceval_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[36], int32_T c1_ia0,
  int32_T c1_lda, real_T c1_B[36], int32_T c1_ib0, int32_T c1_ldb, real_T
  c1_b_B[36]);
static void c1_b_eml_scalar_eg(SFc1_DynVerifyInstanceStruct *chartInstance);
static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u);
static const mxArray *c1_h_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[100]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[100]);
static const mxArray *c1_i_sf_marshall(void *chartInstanceVoid, void *c1_u);
static void c1_emlrt_marshallIn(SFc1_DynVerifyInstanceStruct *chartInstance,
  const mxArray *c1_Omega, const char_T *c1_name, real_T c1_y[6]);
static uint8_T c1_b_emlrt_marshallIn(SFc1_DynVerifyInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_DynVerify, const char_T *c1_name);
static void init_dsm_address_info(SFc1_DynVerifyInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_DynVerify = 0U;
}

static void initialize_params_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance)
{
  real_T c1_dv0[9];
  int32_T c1_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c1_dv0, 0, 0,
                0U, 1, 0U, 2, 1, 9);
  for (c1_i0 = 0; c1_i0 < 9; c1_i0 = c1_i0 + 1) {
    chartInstance->c1_L[c1_i0] = c1_dv0[c1_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st = NULL;
  const mxArray *c1_y = NULL;
  int32_T c1_i1;
  real_T c1_hoistedGlobal[6];
  int32_T c1_i2;
  real_T c1_u[6];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_Omega)[6];
  c1_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  for (c1_i1 = 0; c1_i1 < 6; c1_i1 = c1_i1 + 1) {
    c1_hoistedGlobal[c1_i1] = (*c1_Omega)[c1_i1];
  }

  for (c1_i2 = 0; c1_i2 < 6; c1_i2 = c1_i2 + 1) {
    c1_u[c1_i2] = c1_hoistedGlobal[c1_i2];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_DynVerify;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_DynVerify(SFc1_DynVerifyInstanceStruct
  *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv1[6];
  int32_T c1_i3;
  real_T (*c1_Omega)[6];
  c1_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "Omega", c1_dv1);
  for (c1_i3 = 0; c1_i3 < 6; c1_i3 = c1_i3 + 1) {
    (*c1_Omega)[c1_i3] = c1_dv1[c1_i3];
  }

  chartInstance->c1_is_active_c1_DynVerify = c1_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_DynVerify");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_DynVerify(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance)
{
}

static void sf_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance)
{
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_previousEvent;
  real_T (*c1_Theta)[6];
  real_T (*c1_EndVel)[3];
  real_T (*c1_Omega)[6];
  c1_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c1_EndVel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c1_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0);
  for (c1_i4 = 0; c1_i4 < 6; c1_i4 = c1_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_Omega)[c1_i4], 0U);
  }

  for (c1_i5 = 0; c1_i5 < 3; c1_i5 = c1_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_EndVel)[c1_i5], 1U);
  }

  for (c1_i6 = 0; c1_i6 < 6; c1_i6 = c1_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c1_Theta)[c1_i6], 2U);
  }

  for (c1_i7 = 0; c1_i7 < 9; c1_i7 = c1_i7 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_L[c1_i7], 3U);
  }

  c1_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c1_c1_DynVerify(chartInstance);
  _sfEvent_ = c1_previousEvent;
  sf_debug_check_for_state_inconsistency(_DynVerifyMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_c1_DynVerify(SFc1_DynVerifyInstanceStruct *chartInstance)
{
  int32_T c1_i8;
  real_T c1_hoistedGlobal[3];
  int32_T c1_i9;
  real_T c1_b_hoistedGlobal[6];
  int32_T c1_i10;
  real_T c1_c_hoistedGlobal[9];
  int32_T c1_i11;
  real_T c1_EndVel[3];
  int32_T c1_i12;
  real_T c1_Theta[6];
  int32_T c1_i13;
  real_T c1_b_L[9];
  uint32_T c1_debug_family_var_map[10];
  static const char *c1_sv0[10] = { "V", "g", "Jb", "Adg_inv", "nargin",
    "nargout", "EndVel", "Theta", "L", "Omega" };

  real_T c1_V[6];
  real_T c1_g[16];
  real_T c1_Jb[36];
  real_T c1_Adg_inv[36];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_Omega[6];
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  real_T c1_c_L[9];
  int32_T c1_i17;
  real_T c1_b_Theta[6];
  real_T c1_dv2[16];
  int32_T c1_i18;
  int32_T c1_i19;
  real_T c1_d_L[9];
  int32_T c1_i20;
  real_T c1_c_Theta[6];
  real_T c1_dv3[36];
  int32_T c1_i21;
  int32_T c1_i22;
  real_T c1_b_g[16];
  real_T c1_dv4[36];
  int32_T c1_i23;
  int32_T c1_i24;
  real_T c1_A[36];
  int32_T c1_i25;
  real_T c1_B[36];
  int32_T c1_i26;
  real_T c1_b_A[36];
  int32_T c1_i27;
  real_T c1_b_B[36];
  int32_T c1_i28;
  real_T c1_c_A[36];
  int32_T c1_i29;
  real_T c1_c_B[36];
  int32_T c1_i30;
  real_T c1_d_A[36];
  int32_T c1_i31;
  real_T c1_e_A[36];
  int32_T c1_i32;
  real_T c1_f_A[36];
  int32_T c1_i33;
  real_T c1_g_A[36];
  int32_T c1_i34;
  real_T c1_h_A[36];
  int32_T c1_info;
  int32_T c1_ipiv[6];
  real_T c1_i_A[36];
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_b_ipiv[6];
  int32_T c1_b_info;
  int32_T c1_i37;
  int32_T c1_i38;
  int32_T c1_c_ipiv[6];
  int32_T c1_c_info;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_d_ipiv[6];
  int32_T c1_d_info;
  int32_T c1_i41;
  real_T c1_Y[36];
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_ip;
  int32_T c1_j;
  int32_T c1_b_j;
  real_T c1_temp;
  int32_T c1_i42;
  real_T c1_j_A[36];
  int32_T c1_i43;
  real_T c1_d_B[36];
  int32_T c1_i44;
  int32_T c1_i45;
  real_T c1_k_A[36];
  int32_T c1_i46;
  real_T c1_b_Y[36];
  int32_T c1_i47;
  real_T c1_l_A[36];
  int32_T c1_i48;
  real_T c1_e_B[36];
  int32_T c1_i49;
  int32_T c1_i50;
  real_T c1_m_A[36];
  int32_T c1_i51;
  real_T c1_c_Y[36];
  int32_T c1_i52;
  real_T c1_a[36];
  int32_T c1_i53;
  real_T c1_b[6];
  int32_T c1_i54;
  real_T c1_n_A[36];
  int32_T c1_i55;
  real_T c1_f_B[6];
  int32_T c1_i56;
  real_T c1_o_A[36];
  int32_T c1_i57;
  real_T c1_g_B[6];
  int32_T c1_i58;
  real_T c1_p_A[36];
  int32_T c1_i59;
  real_T c1_h_B[6];
  int32_T c1_i60;
  real_T c1_y[6];
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  real_T (*c1_b_Omega)[6];
  real_T (*c1_d_Theta)[6];
  real_T (*c1_b_EndVel)[3];
  c1_d_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_EndVel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  c1_b_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0);
  for (c1_i8 = 0; c1_i8 < 3; c1_i8 = c1_i8 + 1) {
    c1_hoistedGlobal[c1_i8] = (*c1_b_EndVel)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 6; c1_i9 = c1_i9 + 1) {
    c1_b_hoistedGlobal[c1_i9] = (*c1_d_Theta)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 9; c1_i10 = c1_i10 + 1) {
    c1_c_hoistedGlobal[c1_i10] = chartInstance->c1_L[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 3; c1_i11 = c1_i11 + 1) {
    c1_EndVel[c1_i11] = c1_hoistedGlobal[c1_i11];
  }

  for (c1_i12 = 0; c1_i12 < 6; c1_i12 = c1_i12 + 1) {
    c1_Theta[c1_i12] = c1_b_hoistedGlobal[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 9; c1_i13 = c1_i13 + 1) {
    c1_b_L[c1_i13] = c1_c_hoistedGlobal[c1_i13];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c1_sv0, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c1_V, c1_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c1_g, c1_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c1_Jb, c1_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c1_Adg_inv, c1_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c1_EndVel, c1_c_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c1_Theta, c1_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c1_b_L, c1_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c1_Omega, c1_sf_marshall, 9U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  for (c1_i14 = 0; c1_i14 < 6; c1_i14 = c1_i14 + 1) {
    c1_Omega[c1_i14] = 0.0;
  }

  _SFD_EML_CALL(0, 5);
  for (c1_i15 = 0; c1_i15 < 3; c1_i15 = c1_i15 + 1) {
    c1_V[c1_i15] = c1_EndVel[c1_i15];
  }

  c1_V[3] = 0.0;
  c1_V[4] = 0.0;
  c1_V[5] = 0.0;
  _SFD_EML_CALL(0, 6);
  for (c1_i16 = 0; c1_i16 < 9; c1_i16 = c1_i16 + 1) {
    c1_c_L[c1_i16] = c1_b_L[c1_i16];
  }

  for (c1_i17 = 0; c1_i17 < 6; c1_i17 = c1_i17 + 1) {
    c1_b_Theta[c1_i17] = c1_Theta[c1_i17];
  }

  c1_fwd_kin(chartInstance, c1_c_L, c1_b_Theta, c1_dv2);
  for (c1_i18 = 0; c1_i18 < 16; c1_i18 = c1_i18 + 1) {
    c1_g[c1_i18] = c1_dv2[c1_i18];
  }

  _SFD_EML_CALL(0, 7);
  for (c1_i19 = 0; c1_i19 < 9; c1_i19 = c1_i19 + 1) {
    c1_d_L[c1_i19] = c1_b_L[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 6; c1_i20 = c1_i20 + 1) {
    c1_c_Theta[c1_i20] = c1_Theta[c1_i20];
  }

  c1_body_Jacobian(chartInstance, c1_d_L, c1_c_Theta, c1_dv3);
  for (c1_i21 = 0; c1_i21 < 36; c1_i21 = c1_i21 + 1) {
    c1_Jb[c1_i21] = c1_dv3[c1_i21];
  }

  _SFD_EML_CALL(0, 8);
  for (c1_i22 = 0; c1_i22 < 16; c1_i22 = c1_i22 + 1) {
    c1_b_g[c1_i22] = c1_g[c1_i22];
  }

  c1_AdjointInv(chartInstance, c1_b_g, c1_dv4);
  for (c1_i23 = 0; c1_i23 < 36; c1_i23 = c1_i23 + 1) {
    c1_Adg_inv[c1_i23] = c1_dv4[c1_i23];
  }

  _SFD_EML_CALL(0, 9);
  for (c1_i24 = 0; c1_i24 < 36; c1_i24 = c1_i24 + 1) {
    c1_A[c1_i24] = c1_Jb[c1_i24];
  }

  for (c1_i25 = 0; c1_i25 < 36; c1_i25 = c1_i25 + 1) {
    c1_B[c1_i25] = c1_Adg_inv[c1_i25];
  }

  for (c1_i26 = 0; c1_i26 < 36; c1_i26 = c1_i26 + 1) {
    c1_b_A[c1_i26] = c1_A[c1_i26];
  }

  for (c1_i27 = 0; c1_i27 < 36; c1_i27 = c1_i27 + 1) {
    c1_b_B[c1_i27] = c1_B[c1_i27];
  }

  for (c1_i28 = 0; c1_i28 < 36; c1_i28 = c1_i28 + 1) {
    c1_c_A[c1_i28] = c1_b_A[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 36; c1_i29 = c1_i29 + 1) {
    c1_c_B[c1_i29] = c1_b_B[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 36; c1_i30 = c1_i30 + 1) {
    c1_d_A[c1_i30] = c1_c_A[c1_i30];
  }

  for (c1_i31 = 0; c1_i31 < 36; c1_i31 = c1_i31 + 1) {
    c1_e_A[c1_i31] = c1_d_A[c1_i31];
  }

  for (c1_i32 = 0; c1_i32 < 36; c1_i32 = c1_i32 + 1) {
    c1_f_A[c1_i32] = c1_e_A[c1_i32];
  }

  for (c1_i33 = 0; c1_i33 < 36; c1_i33 = c1_i33 + 1) {
    c1_g_A[c1_i33] = c1_f_A[c1_i33];
  }

  for (c1_i34 = 0; c1_i34 < 36; c1_i34 = c1_i34 + 1) {
    c1_h_A[c1_i34] = c1_g_A[c1_i34];
  }

  c1_eml_matlab_zgetrf(chartInstance, c1_h_A, c1_i_A, c1_ipiv, &c1_info);
  for (c1_i35 = 0; c1_i35 < 36; c1_i35 = c1_i35 + 1) {
    c1_g_A[c1_i35] = c1_i_A[c1_i35];
  }

  for (c1_i36 = 0; c1_i36 < 6; c1_i36 = c1_i36 + 1) {
    c1_b_ipiv[c1_i36] = c1_ipiv[c1_i36];
  }

  c1_b_info = c1_info;
  for (c1_i37 = 0; c1_i37 < 36; c1_i37 = c1_i37 + 1) {
    c1_e_A[c1_i37] = c1_g_A[c1_i37];
  }

  for (c1_i38 = 0; c1_i38 < 6; c1_i38 = c1_i38 + 1) {
    c1_c_ipiv[c1_i38] = c1_b_ipiv[c1_i38];
  }

  c1_c_info = c1_b_info;
  for (c1_i39 = 0; c1_i39 < 36; c1_i39 = c1_i39 + 1) {
    c1_c_A[c1_i39] = c1_e_A[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 6; c1_i40 = c1_i40 + 1) {
    c1_d_ipiv[c1_i40] = c1_c_ipiv[c1_i40];
  }

  c1_d_info = c1_c_info;
  if ((real_T)c1_d_info > 0.0) {
    c1_eml_warning(chartInstance);
  }

  for (c1_i41 = 0; c1_i41 < 36; c1_i41 = c1_i41 + 1) {
    c1_Y[c1_i41] = c1_c_B[c1_i41];
  }

  for (c1_i = 1; c1_i < 7; c1_i = c1_i + 1) {
    c1_b_i = c1_i;
    if (c1_d_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_i), 1, 6, 1, 0) - 1] != c1_b_i) {
      c1_ip = c1_d_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 6, 1, 0) - 1];
      for (c1_j = 1; c1_j < 7; c1_j = c1_j + 1) {
        c1_b_j = c1_j;
        c1_temp = c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 6, 1, 0) - 1) + 6 * (
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 6, 2, 0) - 1)];
        c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_b_i), 1, 6, 1, 0) - 1) + 6 * (
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 6, 2, 0) - 1)] = c1_Y[(
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_ip), 1, 6, 1, 0) - 1) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 6, 2, 0) - 1)];
        c1_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c1_ip), 1, 6, 1, 0) - 1) + 6 * (
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 6, 2, 0) - 1)] = c1_temp;
      }
    }
  }

  for (c1_i42 = 0; c1_i42 < 36; c1_i42 = c1_i42 + 1) {
    c1_j_A[c1_i42] = c1_c_A[c1_i42];
  }

  for (c1_i43 = 0; c1_i43 < 36; c1_i43 = c1_i43 + 1) {
    c1_d_B[c1_i43] = c1_Y[c1_i43];
  }

  for (c1_i44 = 0; c1_i44 < 36; c1_i44 = c1_i44 + 1) {
    c1_Y[c1_i44] = c1_d_B[c1_i44];
  }

  for (c1_i45 = 0; c1_i45 < 36; c1_i45 = c1_i45 + 1) {
    c1_k_A[c1_i45] = c1_j_A[c1_i45];
  }

  for (c1_i46 = 0; c1_i46 < 36; c1_i46 = c1_i46 + 1) {
    c1_b_Y[c1_i46] = c1_Y[c1_i46];
  }

  c1_eml_blas_xtrsm(chartInstance, 6, 6, 1.0, c1_k_A, 1, 6, c1_b_Y, 1, 6, c1_Y);
  for (c1_i47 = 0; c1_i47 < 36; c1_i47 = c1_i47 + 1) {
    c1_l_A[c1_i47] = c1_c_A[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 36; c1_i48 = c1_i48 + 1) {
    c1_e_B[c1_i48] = c1_Y[c1_i48];
  }

  for (c1_i49 = 0; c1_i49 < 36; c1_i49 = c1_i49 + 1) {
    c1_Y[c1_i49] = c1_e_B[c1_i49];
  }

  for (c1_i50 = 0; c1_i50 < 36; c1_i50 = c1_i50 + 1) {
    c1_m_A[c1_i50] = c1_l_A[c1_i50];
  }

  for (c1_i51 = 0; c1_i51 < 36; c1_i51 = c1_i51 + 1) {
    c1_c_Y[c1_i51] = c1_Y[c1_i51];
  }

  c1_b_eml_blas_xtrsm(chartInstance, 6, 6, 1.0, c1_m_A, 1, 6, c1_c_Y, 1, 6, c1_Y);
  for (c1_i52 = 0; c1_i52 < 36; c1_i52 = c1_i52 + 1) {
    c1_a[c1_i52] = c1_Y[c1_i52];
  }

  for (c1_i53 = 0; c1_i53 < 6; c1_i53 = c1_i53 + 1) {
    c1_b[c1_i53] = c1_V[c1_i53];
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_b_eml_scalar_eg(chartInstance);
  for (c1_i54 = 0; c1_i54 < 36; c1_i54 = c1_i54 + 1) {
    c1_n_A[c1_i54] = c1_a[c1_i54];
  }

  for (c1_i55 = 0; c1_i55 < 6; c1_i55 = c1_i55 + 1) {
    c1_f_B[c1_i55] = c1_b[c1_i55];
  }

  for (c1_i56 = 0; c1_i56 < 36; c1_i56 = c1_i56 + 1) {
    c1_o_A[c1_i56] = c1_n_A[c1_i56];
  }

  for (c1_i57 = 0; c1_i57 < 6; c1_i57 = c1_i57 + 1) {
    c1_g_B[c1_i57] = c1_f_B[c1_i57];
  }

  for (c1_i58 = 0; c1_i58 < 36; c1_i58 = c1_i58 + 1) {
    c1_p_A[c1_i58] = c1_o_A[c1_i58];
  }

  for (c1_i59 = 0; c1_i59 < 6; c1_i59 = c1_i59 + 1) {
    c1_h_B[c1_i59] = c1_g_B[c1_i59];
  }

  for (c1_i60 = 0; c1_i60 < 6; c1_i60 = c1_i60 + 1) {
    c1_y[c1_i60] = 0.0;
    c1_i61 = 0;
    for (c1_i62 = 0; c1_i62 < 6; c1_i62 = c1_i62 + 1) {
      c1_y[c1_i60] = c1_y[c1_i60] + c1_p_A[c1_i61 + c1_i60] * c1_h_B[c1_i62];
      c1_i61 = c1_i61 + 6;
    }
  }

  for (c1_i63 = 0; c1_i63 < 6; c1_i63 = c1_i63 + 1) {
    c1_Omega[c1_i63] = c1_y[c1_i63];
  }

  _SFD_EML_CALL(0, -9);
  sf_debug_symbol_scope_pop();
  for (c1_i64 = 0; c1_i64 < 6; c1_i64 = c1_i64 + 1) {
    (*c1_b_Omega)[c1_i64] = c1_Omega[c1_i64];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
}

static void compInitSubchartSimstructsFcn_c1_DynVerify
  (SFc1_DynVerifyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/fwd_kin.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 1U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/body_Jacobian.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 2U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/AdjointInv.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 3U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/skew.m"));
}

static void c1_fwd_kin(SFc1_DynVerifyInstanceStruct *chartInstance, real_T
  c1_in1[9], real_T c1_in2[6], real_T c1_gst[16])
{
  uint32_T c1_debug_family_var_map[68];
  real_T c1_A1;
  real_T c1_A2;
  real_T c1_A3;
  real_T c1_A4;
  real_T c1_A5;
  real_T c1_A6;
  real_T c1_L1;
  real_T c1_L2;
  real_T c1_L3;
  real_T c1_L4;
  real_T c1_L5;
  real_T c1_L6;
  real_T c1_L7;
  real_T c1_L8;
  real_T c1_L9;
  real_T c1_t2;
  real_T c1_t3;
  real_T c1_t4;
  real_T c1_t5;
  real_T c1_t6;
  real_T c1_t7;
  real_T c1_t8;
  real_T c1_t9;
  real_T c1_t10;
  real_T c1_t11;
  real_T c1_t12;
  real_T c1_t13;
  real_T c1_t14;
  real_T c1_t23;
  real_T c1_t15;
  real_T c1_t16;
  real_T c1_t17;
  real_T c1_t18;
  real_T c1_t19;
  real_T c1_t20;
  real_T c1_t21;
  real_T c1_t22;
  real_T c1_t24;
  real_T c1_t25;
  real_T c1_t26;
  real_T c1_t27;
  real_T c1_t34;
  real_T c1_t28;
  real_T c1_t29;
  real_T c1_t30;
  real_T c1_t31;
  real_T c1_t32;
  real_T c1_t36;
  real_T c1_t33;
  real_T c1_t35;
  real_T c1_t37;
  real_T c1_t38;
  real_T c1_t39;
  real_T c1_t40;
  real_T c1_t41;
  real_T c1_t42;
  real_T c1_t43;
  real_T c1_t44;
  real_T c1_t45;
  real_T c1_t47;
  real_T c1_t46;
  real_T c1_t48;
  real_T c1_t49;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x;
  real_T c1_v_x;
  real_T c1_w_x;
  real_T c1_x_x;
  real_T c1_y_x[16];
  int32_T c1_k;
  int32_T c1_b_k;
  sf_debug_symbol_scope_push_eml(0U, 68U, 68U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_A1, c1_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_A2, c1_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_A3, c1_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_A4, c1_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_A5, c1_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_A6, c1_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_L1, c1_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_L2, c1_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c1_L3, c1_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c1_L4, c1_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c1_L5, c1_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c1_L6, c1_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c1_L7, c1_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c1_L8, c1_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c1_L9, c1_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c1_t2, c1_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c1_t3, c1_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c1_t4, c1_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c1_t5, c1_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c1_t6, c1_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c1_t7, c1_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c1_t8, c1_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c1_t9, c1_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c1_t10, c1_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c1_t11, c1_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c1_t12, c1_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c1_t13, c1_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c1_t14, c1_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c1_t23, c1_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c1_t15, c1_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c1_t16, c1_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c1_t17, c1_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c1_t18, c1_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c1_t19, c1_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c1_t20, c1_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c1_t21, c1_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c1_t22, c1_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c1_t24, c1_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c1_t25, c1_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c1_t26, c1_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c1_t27, c1_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c1_t34, c1_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c1_t28, c1_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c1_t29, c1_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c1_t30, c1_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c1_t31, c1_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c1_t32, c1_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c1_t36, c1_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c1_t33, c1_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c1_t35, c1_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c1_t37, c1_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c1_t38, c1_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c1_t39, c1_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c1_t40, c1_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c1_t41, c1_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c1_t42, c1_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c1_t43, c1_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c1_t44, c1_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c1_t45, c1_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c1_t47, c1_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c1_t46, c1_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c1_t48, c1_d_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c1_t49, c1_d_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_d_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_d_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c1_in1, c1_b_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(c1_in2, c1_g_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(c1_gst, c1_f_sf_marshall, 67U);
  CV_SCRIPT_FCN(0, 0);

  /* FWD_KIN */
  /*     GST = FWD_KIN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     24-Apr-2013 12:49:18 */
  _SFD_SCRIPT_CALL(0, 8);
  c1_A1 = c1_in2[0];
  _SFD_SCRIPT_CALL(0, 9);
  c1_A2 = c1_in2[1];
  _SFD_SCRIPT_CALL(0, 10);
  c1_A3 = c1_in2[2];
  _SFD_SCRIPT_CALL(0, 11);
  c1_A4 = c1_in2[3];
  _SFD_SCRIPT_CALL(0, 12);
  c1_A5 = c1_in2[4];
  _SFD_SCRIPT_CALL(0, 13);
  c1_A6 = c1_in2[5];
  _SFD_SCRIPT_CALL(0, 14);
  c1_L1 = c1_in1[0];
  _SFD_SCRIPT_CALL(0, 15);
  c1_L2 = c1_in1[1];
  _SFD_SCRIPT_CALL(0, 16);
  c1_L3 = c1_in1[2];
  _SFD_SCRIPT_CALL(0, 17);
  c1_L4 = c1_in1[3];
  _SFD_SCRIPT_CALL(0, 18);
  c1_L5 = c1_in1[4];
  _SFD_SCRIPT_CALL(0, 19);
  c1_L6 = c1_in1[5];
  _SFD_SCRIPT_CALL(0, 20);
  c1_L7 = c1_in1[6];
  _SFD_SCRIPT_CALL(0, 21);
  c1_L8 = c1_in1[7];
  _SFD_SCRIPT_CALL(0, 22);
  c1_L9 = c1_in1[8];
  _SFD_SCRIPT_CALL(0, 23);
  c1_x = c1_A1;
  c1_t2 = c1_x;
  c1_b_x = c1_t2;
  c1_t2 = c1_b_x;
  c1_t2 = muDoubleScalarCos(c1_t2);
  _SFD_SCRIPT_CALL(0, 24);
  c1_c_x = c1_A2;
  c1_t3 = c1_c_x;
  c1_d_x = c1_t3;
  c1_t3 = c1_d_x;
  c1_t3 = muDoubleScalarCos(c1_t3);
  _SFD_SCRIPT_CALL(0, 25);
  c1_e_x = c1_A3;
  c1_t4 = c1_e_x;
  c1_f_x = c1_t4;
  c1_t4 = c1_f_x;
  c1_t4 = muDoubleScalarSin(c1_t4);
  _SFD_SCRIPT_CALL(0, 26);
  c1_g_x = c1_A3;
  c1_t5 = c1_g_x;
  c1_h_x = c1_t5;
  c1_t5 = c1_h_x;
  c1_t5 = muDoubleScalarCos(c1_t5);
  _SFD_SCRIPT_CALL(0, 27);
  c1_i_x = c1_A2;
  c1_t6 = c1_i_x;
  c1_j_x = c1_t6;
  c1_t6 = c1_j_x;
  c1_t6 = muDoubleScalarSin(c1_t6);
  _SFD_SCRIPT_CALL(0, 28);
  c1_k_x = c1_A4;
  c1_t7 = c1_k_x;
  c1_l_x = c1_t7;
  c1_t7 = c1_l_x;
  c1_t7 = muDoubleScalarSin(c1_t7);
  _SFD_SCRIPT_CALL(0, 29);
  c1_t8 = c1_t2 * c1_t3 * c1_t4;
  _SFD_SCRIPT_CALL(0, 30);
  c1_t9 = c1_t2 * c1_t5 * c1_t6;
  _SFD_SCRIPT_CALL(0, 31);
  c1_t10 = c1_t8 + c1_t9;
  _SFD_SCRIPT_CALL(0, 32);
  c1_m_x = c1_A4;
  c1_t11 = c1_m_x;
  c1_n_x = c1_t11;
  c1_t11 = c1_n_x;
  c1_t11 = muDoubleScalarCos(c1_t11);
  _SFD_SCRIPT_CALL(0, 33);
  c1_o_x = c1_A1;
  c1_t12 = c1_o_x;
  c1_p_x = c1_t12;
  c1_t12 = c1_p_x;
  c1_t12 = muDoubleScalarSin(c1_t12);
  _SFD_SCRIPT_CALL(0, 34);
  c1_q_x = c1_A5;
  c1_t13 = c1_q_x;
  c1_r_x = c1_t13;
  c1_t13 = c1_r_x;
  c1_t13 = muDoubleScalarSin(c1_t13);
  _SFD_SCRIPT_CALL(0, 35);
  c1_t14 = c1_t2 * c1_t3 * c1_t5;
  _SFD_SCRIPT_CALL(0, 36);
  c1_t23 = c1_t2 * c1_t4 * c1_t6;
  _SFD_SCRIPT_CALL(0, 37);
  c1_t15 = c1_t14 - c1_t23;
  _SFD_SCRIPT_CALL(0, 38);
  c1_s_x = c1_A5;
  c1_t16 = c1_s_x;
  c1_t_x = c1_t16;
  c1_t16 = c1_t_x;
  c1_t16 = muDoubleScalarCos(c1_t16);
  _SFD_SCRIPT_CALL(0, 39);
  c1_t17 = c1_t10 * c1_t11;
  _SFD_SCRIPT_CALL(0, 40);
  c1_t18 = c1_t12 * c1_t7;
  _SFD_SCRIPT_CALL(0, 41);
  c1_t19 = c1_t17 + c1_t18;
  _SFD_SCRIPT_CALL(0, 42);
  c1_u_x = c1_A6;
  c1_t20 = c1_u_x;
  c1_v_x = c1_t20;
  c1_t20 = c1_v_x;
  c1_t20 = muDoubleScalarSin(c1_t20);
  _SFD_SCRIPT_CALL(0, 43);
  c1_t21 = c1_t11 * c1_t12;
  _SFD_SCRIPT_CALL(0, 44);
  c1_w_x = c1_A6;
  c1_t22 = c1_w_x;
  c1_x_x = c1_t22;
  c1_t22 = c1_x_x;
  c1_t22 = muDoubleScalarCos(c1_t22);
  _SFD_SCRIPT_CALL(0, 45);
  c1_t24 = c1_t13 * c1_t15;
  _SFD_SCRIPT_CALL(0, 46);
  c1_t25 = c1_t16 * c1_t19;
  _SFD_SCRIPT_CALL(0, 47);
  c1_t26 = c1_t24 + c1_t25;
  _SFD_SCRIPT_CALL(0, 48);
  c1_t27 = c1_t12 * c1_t3 * c1_t5;
  _SFD_SCRIPT_CALL(0, 49);
  c1_t34 = c1_t12 * c1_t4 * c1_t6;
  _SFD_SCRIPT_CALL(0, 50);
  c1_t28 = c1_t27 - c1_t34;
  _SFD_SCRIPT_CALL(0, 51);
  c1_t29 = c1_t12 * c1_t3 * c1_t4;
  _SFD_SCRIPT_CALL(0, 52);
  c1_t30 = c1_t12 * c1_t5 * c1_t6;
  _SFD_SCRIPT_CALL(0, 53);
  c1_t31 = c1_t29 + c1_t30;
  _SFD_SCRIPT_CALL(0, 54);
  c1_t32 = c1_t11 * c1_t31;
  _SFD_SCRIPT_CALL(0, 55);
  c1_t36 = c1_t2 * c1_t7;
  _SFD_SCRIPT_CALL(0, 56);
  c1_t33 = c1_t32 - c1_t36;
  _SFD_SCRIPT_CALL(0, 57);
  c1_t35 = c1_t13 * c1_t28;
  _SFD_SCRIPT_CALL(0, 58);
  c1_t37 = c1_t16 * c1_t33;
  _SFD_SCRIPT_CALL(0, 59);
  c1_t38 = c1_t35 + c1_t37;
  _SFD_SCRIPT_CALL(0, 60);
  c1_t39 = c1_t31 * c1_t7;
  _SFD_SCRIPT_CALL(0, 61);
  c1_t40 = c1_t11 * c1_t2;
  _SFD_SCRIPT_CALL(0, 62);
  c1_t41 = c1_t39 + c1_t40;
  _SFD_SCRIPT_CALL(0, 63);
  c1_t42 = c1_t3 * c1_t4;
  _SFD_SCRIPT_CALL(0, 64);
  c1_t43 = c1_t5 * c1_t6;
  _SFD_SCRIPT_CALL(0, 65);
  c1_t44 = c1_t42 + c1_t43;
  _SFD_SCRIPT_CALL(0, 66);
  c1_t45 = c1_t3 * c1_t5;
  _SFD_SCRIPT_CALL(0, 67);
  c1_t47 = c1_t4 * c1_t6;
  _SFD_SCRIPT_CALL(0, 68);
  c1_t46 = c1_t45 - c1_t47;
  _SFD_SCRIPT_CALL(0, 69);
  c1_t48 = c1_t13 * c1_t44;
  _SFD_SCRIPT_CALL(0, 70);
  c1_t49 = c1_t48 - c1_t11 * c1_t16 * c1_t46;
  _SFD_SCRIPT_CALL(0, 71);
  c1_y_x[0] = c1_t15 * c1_t16 - c1_t13 * c1_t19;
  c1_y_x[1] = c1_t16 * c1_t28 - c1_t13 * c1_t33;
  c1_y_x[2] = (-c1_t16) * c1_t44 - c1_t11 * c1_t13 * c1_t46;
  c1_y_x[3] = 0.0;
  c1_y_x[4] = c1_t20 * c1_t26 - c1_t22 * (c1_t21 - c1_t10 * c1_t7);
  c1_y_x[5] = c1_t20 * c1_t38 + c1_t22 * c1_t41;
  c1_y_x[6] = (-c1_t20) * c1_t49 + c1_t22 * c1_t46 * c1_t7;
  c1_y_x[7] = 0.0;
  c1_y_x[8] = c1_t22 * c1_t26 + c1_t20 * (c1_t21 - c1_t10 * c1_t7);
  c1_y_x[9] = c1_t22 * c1_t38 - c1_t20 * c1_t41;
  c1_y_x[10] = (-c1_t22) * c1_t49 - c1_t20 * c1_t46 * c1_t7;
  c1_y_x[11] = 0.0;
  c1_y_x[12] = ((((((((((((((((((((((((((((((c1_L2 * c1_t2 + c1_L3 * c1_t2 *
    c1_t6) - c1_L8 * c1_t11 * c1_t12 * c1_t22) + c1_L4 *
    c1_t2 * c1_t3 * c1_t4) + c1_L9 * c1_t11 * c1_t12 * c1_t20) + c1_L5 * c1_t2 *
    c1_t3 * c1_t5) - c1_L6 * c1_t12 * c1_t13 * c1_t7) -
    c1_L7 * c1_t12 * c1_t13 * c1_t7) + c1_L4 * c1_t2 * c1_t5 * c1_t6) - c1_L5 *
    c1_t2 * c1_t4 * c1_t6) + c1_L6 * c1_t16 * c1_t2 * c1_t3
    * c1_t5) + c1_L7 * c1_t16 * c1_t2 * c1_t3 * c1_t5) - c1_L6 * c1_t16 * c1_t2 *
    c1_t4 * c1_t6) + c1_L8 * c1_t12 * c1_t16 * c1_t20 *
    c1_t7) - c1_L7 * c1_t16 * c1_t2 * c1_t4 * c1_t6) + c1_L9 * c1_t12 * c1_t16 *
    c1_t22 * c1_t7) - c1_L6 * c1_t11 * c1_t13 * c1_t2 *
    c1_t3 * c1_t4) - c1_L7 * c1_t11 * c1_t13 * c1_t2 * c1_t3 * c1_t4) + c1_L8 *
    c1_t13 * c1_t2 * c1_t20 * c1_t3 * c1_t5) - c1_L6 *
    c1_t11 * c1_t13 * c1_t2 * c1_t5 * c1_t6) - c1_L7 * c1_t11 * c1_t13 * c1_t2 *
    c1_t5 * c1_t6) + c1_L9 * c1_t13 * c1_t2 * c1_t22 *
    c1_t3 * c1_t5) - c1_L8 * c1_t13 * c1_t2 * c1_t20 * c1_t4 * c1_t6) - c1_L9 *
                       c1_t13 * c1_t2 * c1_t22 * c1_t4 * c1_t6) + c1_L8 * c1_t2
                      * c1_t22 * c1_t3 * c1_t4 * c1_t7) - c1_L9 * c1_t2 * c1_t20
                     * c1_t3 * c1_t4 * c1_t7) + c1_L8 * c1_t2 * c1_t22 * c1_t5 *
                    c1_t6 *
                    c1_t7) - c1_L9 * c1_t2 * c1_t20 * c1_t5 * c1_t6 * c1_t7) +
                  c1_L8 * c1_t11 * c1_t16 * c1_t2 * c1_t20 * c1_t3 * c1_t4) +
                 c1_L9 *
                 c1_t11 * c1_t16 * c1_t2 * c1_t22 * c1_t3 * c1_t4) + c1_L8 *
                c1_t11 * c1_t16 * c1_t2 * c1_t20 * c1_t5 * c1_t6) + c1_L9 *
    c1_t11 *
    c1_t16 * c1_t2 * c1_t22 * c1_t5 * c1_t6;
  c1_y_x[13] = ((((((((((((((((((((((((((((((c1_L2 * c1_t12 + c1_L3 * c1_t12 *
    c1_t6) + c1_L4 * c1_t12 * c1_t3 * c1_t4) + c1_L8 *
    c1_t11 * c1_t2 * c1_t22) + c1_L5 * c1_t12 * c1_t3 * c1_t5) - c1_L9 * c1_t11 *
    c1_t2 * c1_t20) + c1_L4 * c1_t12 * c1_t5 * c1_t6) -
    c1_L5 * c1_t12 * c1_t4 * c1_t6) + c1_L6 * c1_t13 * c1_t2 * c1_t7) + c1_L7 *
    c1_t13 * c1_t2 * c1_t7) + c1_L6 * c1_t12 * c1_t16 *
    c1_t3 * c1_t5) + c1_L7 * c1_t12 * c1_t16 * c1_t3 * c1_t5) - c1_L6 * c1_t12 *
    c1_t16 * c1_t4 * c1_t6) - c1_L7 * c1_t12 * c1_t16 *
    c1_t4 * c1_t6) - c1_L8 * c1_t16 * c1_t2 * c1_t20 * c1_t7) - c1_L9 * c1_t16 *
    c1_t2 * c1_t22 * c1_t7) - c1_L6 * c1_t11 * c1_t12 *
    c1_t13 * c1_t3 * c1_t4) - c1_L7 * c1_t11 * c1_t12 * c1_t13 * c1_t3 * c1_t4)
    + c1_L8 * c1_t12 * c1_t13 * c1_t20 * c1_t3 * c1_t5) -
    c1_L6 * c1_t11 * c1_t12 * c1_t13 * c1_t5 * c1_t6) - c1_L7 * c1_t11 * c1_t12 *
    c1_t13 * c1_t5 * c1_t6) + c1_L9 * c1_t12 * c1_t13 *
    c1_t22 * c1_t3 * c1_t5) - c1_L8 * c1_t12 * c1_t13 * c1_t20 * c1_t4 * c1_t6)
                       - c1_L9 * c1_t12 * c1_t13 * c1_t22 * c1_t4 * c1_t6) +
                      c1_L8 * c1_t12 * c1_t22 * c1_t3 * c1_t4 * c1_t7) - c1_L9 *
                     c1_t12 * c1_t20 * c1_t3 * c1_t4 * c1_t7) + c1_L8 * c1_t12 *
                    c1_t22 *
                    c1_t5 * c1_t6 * c1_t7) - c1_L9 * c1_t12 * c1_t20 * c1_t5 *
                   c1_t6 * c1_t7) + c1_L8 * c1_t11 * c1_t12 * c1_t16 * c1_t20 *
                  c1_t3 *
                  c1_t4) + c1_L9 * c1_t11 * c1_t12 * c1_t16 * c1_t22 * c1_t3 *
                 c1_t4) + c1_L8 * c1_t11 * c1_t12 * c1_t16 * c1_t20 * c1_t5 *
                c1_t6) +
    c1_L9 * c1_t11 * c1_t12 * c1_t16 * c1_t22 * c1_t5 * c1_t6;
  c1_y_x[14] = ((((((((((((((((((((((((c1_L1 + c1_L3 * c1_t3) + c1_L4 * c1_t3 *
    c1_t5) - c1_L5 * c1_t3 * c1_t4) - c1_L4 * c1_t4 *
    c1_t6) - c1_L5 * c1_t5 * c1_t6) - c1_L6 * c1_t16 * c1_t3 * c1_t4) - c1_L7 *
    c1_t16 * c1_t3 * c1_t4) - c1_L6 * c1_t16 * c1_t5 * c1_t6
    ) - c1_L7 * c1_t16 * c1_t5 * c1_t6) - c1_L6 * c1_t11 * c1_t13 * c1_t3 *
    c1_t5) - c1_L7 * c1_t11 * c1_t13 * c1_t3 * c1_t5) - c1_L8 *
    c1_t13 * c1_t20 * c1_t3 * c1_t4) + c1_L6 * c1_t11 * c1_t13 * c1_t4 * c1_t6)
    + c1_L7 * c1_t11 * c1_t13 * c1_t4 * c1_t6) - c1_L9 *
    c1_t13 * c1_t22 * c1_t3 * c1_t4) - c1_L8 * c1_t13 * c1_t20 * c1_t5 * c1_t6)
                       - c1_L9 * c1_t13 * c1_t22 * c1_t5 * c1_t6) + c1_L8 *
                      c1_t22 * c1_t3 * c1_t5 * c1_t7) - c1_L9 * c1_t20 * c1_t3 *
                     c1_t5 * c1_t7) - c1_L8 * c1_t22 * c1_t4 * c1_t6 * c1_t7) +
                   c1_L9 * c1_t20
                   * c1_t4 * c1_t6 * c1_t7) + c1_L8 * c1_t11 * c1_t16 * c1_t20 *
                  c1_t3 * c1_t5) + c1_L9 * c1_t11 * c1_t16 * c1_t22 * c1_t3 *
                 c1_t5) -
                c1_L8 * c1_t11 * c1_t16 * c1_t20 * c1_t4 * c1_t6) - c1_L9 *
    c1_t11 * c1_t16 * c1_t22 * c1_t4 * c1_t6;
  c1_y_x[15] = 1.0;
  for (c1_k = 1; c1_k < 17; c1_k = c1_k + 1) {
    c1_b_k = c1_k;
    c1_gst[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 16, 1, 0) - 1] = c1_y_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_b_k), 1, 16, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0, -71);
  sf_debug_symbol_scope_pop();
}

static void c1_body_Jacobian(SFc1_DynVerifyInstanceStruct *chartInstance, real_T
  c1_in1[9], real_T c1_in2[6], real_T
  c1_b_body_Jacobian[36])
{
  uint32_T c1_debug_family_var_map[49];
  real_T c1_A2;
  real_T c1_A3;
  real_T c1_A4;
  real_T c1_A5;
  real_T c1_A6;
  real_T c1_L2;
  real_T c1_L3;
  real_T c1_L4;
  real_T c1_L5;
  real_T c1_L6;
  real_T c1_L7;
  real_T c1_L8;
  real_T c1_L9;
  real_T c1_t52;
  real_T c1_t53;
  real_T c1_t54;
  real_T c1_t55;
  real_T c1_t56;
  real_T c1_t57;
  real_T c1_t58;
  real_T c1_t59;
  real_T c1_t60;
  real_T c1_t61;
  real_T c1_t62;
  real_T c1_t63;
  real_T c1_t64;
  real_T c1_t65;
  real_T c1_t66;
  real_T c1_t67;
  real_T c1_t68;
  real_T c1_t69;
  real_T c1_t70;
  real_T c1_t71;
  real_T c1_t72;
  real_T c1_t73;
  real_T c1_t74;
  real_T c1_t75;
  real_T c1_t76;
  real_T c1_t77;
  real_T c1_t78;
  real_T c1_t79;
  real_T c1_t80;
  real_T c1_t81;
  real_T c1_t82;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_l_x;
  real_T c1_m_x;
  real_T c1_n_x;
  real_T c1_o_x;
  real_T c1_p_x;
  real_T c1_q_x;
  real_T c1_r_x;
  real_T c1_s_x;
  real_T c1_t_x;
  real_T c1_u_x[36];
  int32_T c1_k;
  int32_T c1_b_k;
  sf_debug_symbol_scope_push_eml(0U, 49U, 49U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_A2, c1_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_A3, c1_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c1_A4, c1_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_A5, c1_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_A6, c1_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c1_L2, c1_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c1_L3, c1_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c1_L4, c1_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c1_L5, c1_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c1_L6, c1_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c1_L7, c1_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c1_L8, c1_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c1_L9, c1_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c1_t52, c1_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c1_t53, c1_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c1_t54, c1_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c1_t55, c1_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c1_t56, c1_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c1_t57, c1_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c1_t58, c1_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c1_t59, c1_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c1_t60, c1_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c1_t61, c1_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c1_t62, c1_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c1_t63, c1_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c1_t64, c1_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c1_t65, c1_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c1_t66, c1_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c1_t67, c1_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c1_t68, c1_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c1_t69, c1_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c1_t70, c1_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c1_t71, c1_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c1_t72, c1_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c1_t73, c1_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c1_t74, c1_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c1_t75, c1_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c1_t76, c1_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c1_t77, c1_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c1_t78, c1_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c1_t79, c1_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c1_t80, c1_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c1_t81, c1_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c1_t82, c1_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(c1_in1, c1_b_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(c1_in2, c1_g_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(c1_b_body_Jacobian, c1_e_sf_marshall, 48U);
  CV_SCRIPT_FCN(1, 0);

  /* BODY_JACOBIAN */
  /*     BODY_JACOBIAN = BODY_JACOBIAN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     24-Apr-2013 20:43:25 */
  _SFD_SCRIPT_CALL(1, 8);
  c1_A2 = c1_in2[1];
  _SFD_SCRIPT_CALL(1, 9);
  c1_A3 = c1_in2[2];
  _SFD_SCRIPT_CALL(1, 10);
  c1_A4 = c1_in2[3];
  _SFD_SCRIPT_CALL(1, 11);
  c1_A5 = c1_in2[4];
  _SFD_SCRIPT_CALL(1, 12);
  c1_A6 = c1_in2[5];
  _SFD_SCRIPT_CALL(1, 13);
  c1_L2 = c1_in1[1];
  _SFD_SCRIPT_CALL(1, 14);
  c1_L3 = c1_in1[2];
  _SFD_SCRIPT_CALL(1, 15);
  c1_L4 = c1_in1[3];
  _SFD_SCRIPT_CALL(1, 16);
  c1_L5 = c1_in1[4];
  _SFD_SCRIPT_CALL(1, 17);
  c1_L6 = c1_in1[5];
  _SFD_SCRIPT_CALL(1, 18);
  c1_L7 = c1_in1[6];
  _SFD_SCRIPT_CALL(1, 19);
  c1_L8 = c1_in1[7];
  _SFD_SCRIPT_CALL(1, 20);
  c1_L9 = c1_in1[8];
  _SFD_SCRIPT_CALL(1, 21);
  c1_x = c1_A4;
  c1_t52 = c1_x;
  c1_b_x = c1_t52;
  c1_t52 = c1_b_x;
  c1_t52 = muDoubleScalarSin(c1_t52);
  _SFD_SCRIPT_CALL(1, 22);
  c1_c_x = c1_A5;
  c1_t53 = c1_c_x;
  c1_d_x = c1_t53;
  c1_t53 = c1_d_x;
  c1_t53 = muDoubleScalarSin(c1_t53);
  _SFD_SCRIPT_CALL(1, 23);
  c1_e_x = c1_A2;
  c1_t54 = c1_e_x;
  c1_f_x = c1_t54;
  c1_t54 = c1_f_x;
  c1_t54 = muDoubleScalarCos(c1_t54);
  _SFD_SCRIPT_CALL(1, 24);
  c1_g_x = c1_A3;
  c1_t55 = c1_g_x;
  c1_h_x = c1_t55;
  c1_t55 = c1_h_x;
  c1_t55 = muDoubleScalarCos(c1_t55);
  _SFD_SCRIPT_CALL(1, 25);
  c1_i_x = c1_A6;
  c1_t56 = c1_i_x;
  c1_j_x = c1_t56;
  c1_t56 = c1_j_x;
  c1_t56 = muDoubleScalarCos(c1_t56);
  _SFD_SCRIPT_CALL(1, 26);
  c1_k_x = c1_A2;
  c1_t57 = c1_k_x;
  c1_l_x = c1_t57;
  c1_t57 = c1_l_x;
  c1_t57 = muDoubleScalarSin(c1_t57);
  _SFD_SCRIPT_CALL(1, 27);
  c1_m_x = c1_A3;
  c1_t58 = c1_m_x;
  c1_n_x = c1_t58;
  c1_t58 = c1_n_x;
  c1_t58 = muDoubleScalarSin(c1_t58);
  _SFD_SCRIPT_CALL(1, 28);
  c1_o_x = c1_A6;
  c1_t59 = c1_o_x;
  c1_p_x = c1_t59;
  c1_t59 = c1_p_x;
  c1_t59 = muDoubleScalarSin(c1_t59);
  _SFD_SCRIPT_CALL(1, 29);
  c1_q_x = c1_A4;
  c1_t60 = c1_q_x;
  c1_r_x = c1_t60;
  c1_t60 = c1_r_x;
  c1_t60 = muDoubleScalarCos(c1_t60);
  _SFD_SCRIPT_CALL(1, 30);
  c1_s_x = c1_A5;
  c1_t61 = c1_s_x;
  c1_t_x = c1_t61;
  c1_t61 = c1_t_x;
  c1_t61 = muDoubleScalarCos(c1_t61);
  _SFD_SCRIPT_CALL(1, 31);
  c1_t62 = c1_L4 * c1_t61;
  _SFD_SCRIPT_CALL(1, 32);
  c1_t63 = c1_L5 * c1_t53 * c1_t60;
  _SFD_SCRIPT_CALL(1, 33);
  c1_t64 = c1_L8 * c1_t59 * c1_t60;
  _SFD_SCRIPT_CALL(1, 34);
  c1_t65 = c1_L9 * c1_t56 * c1_t60;
  _SFD_SCRIPT_CALL(1, 35);
  c1_t66 = c1_L8 * c1_t52 * c1_t56 * c1_t61;
  _SFD_SCRIPT_CALL(1, 36);
  c1_t67 = c1_L4 * c1_t53 * c1_t59;
  _SFD_SCRIPT_CALL(1, 37);
  c1_t68 = c1_L4 * c1_t53 * c1_t56;
  _SFD_SCRIPT_CALL(1, 38);
  c1_t69 = c1_L5 * c1_t52 * c1_t59;
  _SFD_SCRIPT_CALL(1, 39);
  c1_t70 = c1_L8 * c1_t52 * c1_t53;
  _SFD_SCRIPT_CALL(1, 40);
  c1_t71 = c1_L6 * c1_t52 * c1_t59 * c1_t61;
  _SFD_SCRIPT_CALL(1, 41);
  c1_t72 = c1_L7 * c1_t52 * c1_t59 * c1_t61;
  _SFD_SCRIPT_CALL(1, 42);
  c1_t73 = c1_L6 + c1_L7;
  _SFD_SCRIPT_CALL(1, 43);
  c1_t74 = c1_t52 * c1_t53;
  _SFD_SCRIPT_CALL(1, 44);
  c1_t75 = c1_t52 * c1_t56;
  _SFD_SCRIPT_CALL(1, 45);
  c1_t76 = c1_t59 * c1_t60 * c1_t61;
  _SFD_SCRIPT_CALL(1, 46);
  c1_t77 = c1_t75 + c1_t76;
  _SFD_SCRIPT_CALL(1, 47);
  c1_t78 = c1_t56 * c1_t60;
  _SFD_SCRIPT_CALL(1, 48);
  c1_t79 = c1_t78 - c1_t52 * c1_t59 * c1_t61;
  _SFD_SCRIPT_CALL(1, 49);
  c1_t80 = c1_t52 * c1_t59;
  _SFD_SCRIPT_CALL(1, 50);
  c1_t81 = c1_t80 - c1_t56 * c1_t60 * c1_t61;
  _SFD_SCRIPT_CALL(1, 51);
  c1_t82 = (-c1_t59) * c1_t60 - c1_t52 * c1_t56 * c1_t61;
  _SFD_SCRIPT_CALL(1, 52);
  c1_u_x[0] = ((((((((((((((((c1_L2 * c1_t52 * c1_t53 + c1_L3 * c1_t52 * c1_t53 *
    c1_t57) + c1_L4 * c1_t52 * c1_t53 * c1_t54 * c1_t58)
    + c1_L4 * c1_t52 * c1_t53 * c1_t55 * c1_t57) + c1_L5 * c1_t52 * c1_t53 *
    c1_t54 * c1_t55) - c1_L5 * c1_t52 * c1_t53 * c1_t57 *
    c1_t58) + c1_L8 * c1_t52 * c1_t54 * c1_t55 * c1_t59) + c1_L8 * c1_t53 *
                        c1_t54 * c1_t56 * c1_t58) + c1_L8 * c1_t53 * c1_t55 *
                       c1_t56
                       * c1_t57) - c1_L8 * c1_t52 * c1_t57 * c1_t58 * c1_t59) +
                     c1_L9 * c1_t52 * c1_t54 * c1_t55 * c1_t56) - c1_L9 * c1_t52
                    * c1_t56 *
                    c1_t57 * c1_t58) - c1_L9 * c1_t53 * c1_t54 * c1_t58 * c1_t59)
                  - c1_L9 * c1_t53 * c1_t55 * c1_t57 * c1_t59) - c1_L8 * c1_t54 *
                 c1_t55
                 * c1_t56 * c1_t60 * c1_t61) + c1_L8 * c1_t56 * c1_t57 * c1_t58 *
                c1_t60 * c1_t61) + c1_L9 * c1_t54 * c1_t55 * c1_t59 * c1_t60 *
               c1_t61) - c1_L9 * c1_t57 * c1_t58 * c1_t59 * c1_t60 * c1_t61;
  c1_u_x[1] = ((((((((((((((((((((((((((c1_L2 * c1_t56 * c1_t60 - c1_L2 * c1_t52
    * c1_t59 * c1_t61) + c1_L3 * c1_t56 * c1_t57 * c1_t60
    ) + c1_L9 * c1_t54 * c1_t58 * c1_t61) + c1_L9 * c1_t55 * c1_t57 * c1_t61) -
    c1_L3 * c1_t52 * c1_t57 * c1_t59 * c1_t61) + c1_L4 *
    c1_t54 * c1_t56 * c1_t58 * c1_t60) + c1_L4 * c1_t55 * c1_t56 * c1_t57 *
    c1_t60) + c1_L5 * c1_t54 * c1_t55 * c1_t56 * c1_t60) - c1_L6
    * c1_t52 * c1_t54 * c1_t55 * c1_t59) - c1_L5 * c1_t56 * c1_t57 * c1_t58 *
    c1_t60) - c1_L6 * c1_t53 * c1_t54 * c1_t56 * c1_t58) -
    c1_L6 * c1_t53 * c1_t55 * c1_t56 * c1_t57) + c1_L6 * c1_t52 * c1_t57 *
    c1_t58 * c1_t59) - c1_L7 * c1_t52 * c1_t54 * c1_t55 * c1_t59)
    - c1_L7 * c1_t53 * c1_t54 * c1_t56 * c1_t58) - c1_L7 * c1_t53 * c1_t55 *
    c1_t56 * c1_t57) + c1_L7 * c1_t52 * c1_t57 * c1_t58 *
                        c1_t59) + c1_L9 * c1_t53 * c1_t54 * c1_t55 * c1_t60) -
                      c1_L9 * c1_t53 * c1_t57 * c1_t58 * c1_t60) - c1_L4 *
                     c1_t52 * c1_t54 * c1_t58
                     * c1_t59 * c1_t61) - c1_L4 * c1_t52 * c1_t55 * c1_t57 *
                    c1_t59 * c1_t61) - c1_L5 * c1_t52 * c1_t54 * c1_t55 * c1_t59
                   * c1_t61) +
                  c1_L5 * c1_t52 * c1_t57 * c1_t58 * c1_t59 * c1_t61) + c1_L6 *
                 c1_t54 * c1_t55 * c1_t56 * c1_t60 * c1_t61) - c1_L6 * c1_t56 *
                c1_t57
                * c1_t58 * c1_t60 * c1_t61) + c1_L7 * c1_t54 * c1_t55 * c1_t56 *
               c1_t60 * c1_t61) - c1_L7 * c1_t56 * c1_t57 * c1_t58 * c1_t60 *
    c1_t61;
  c1_u_x[2] = (((((((((((((((((((((((((((-c1_L2) * c1_t59 * c1_t60 - c1_L2 *
    c1_t52 * c1_t56 * c1_t61) - c1_L3 * c1_t57 * c1_t59 *
    c1_t60) - c1_L8 * c1_t54 * c1_t58 * c1_t61) - c1_L8 * c1_t55 * c1_t57 *
    c1_t61) - c1_L3 * c1_t52 * c1_t56 * c1_t57 * c1_t61) - c1_L4
    * c1_t54 * c1_t58 * c1_t59 * c1_t60) - c1_L4 * c1_t55 * c1_t57 * c1_t59 *
    c1_t60) - c1_L6 * c1_t52 * c1_t54 * c1_t55 * c1_t56) -
    c1_L5 * c1_t54 * c1_t55 * c1_t59 * c1_t60) + c1_L6 * c1_t52 * c1_t56 *
    c1_t57 * c1_t58) + c1_L5 * c1_t57 * c1_t58 * c1_t59 * c1_t60)
    + c1_L6 * c1_t53 * c1_t54 * c1_t58 * c1_t59) + c1_L6 * c1_t53 * c1_t55 *
    c1_t57 * c1_t59) - c1_L7 * c1_t52 * c1_t54 * c1_t55 *
    c1_t56) + c1_L7 * c1_t52 * c1_t56 * c1_t57 * c1_t58) + c1_L7 * c1_t53 *
    c1_t54 * c1_t58 * c1_t59) + c1_L7 * c1_t53 * c1_t55 * c1_t57
                        * c1_t59) - c1_L8 * c1_t53 * c1_t54 * c1_t55 * c1_t60) +
                      c1_L8 * c1_t53 * c1_t57 * c1_t58 * c1_t60) - c1_L4 *
                     c1_t52 * c1_t54 *
                     c1_t56 * c1_t58 * c1_t61) - c1_L4 * c1_t52 * c1_t55 *
                    c1_t56 * c1_t57 * c1_t61) - c1_L5 * c1_t52 * c1_t54 * c1_t55
                   * c1_t56 * c1_t61
                   ) + c1_L5 * c1_t52 * c1_t56 * c1_t57 * c1_t58 * c1_t61) -
                 c1_L6 * c1_t54 * c1_t55 * c1_t59 * c1_t60 * c1_t61) + c1_L6 *
                c1_t57 *
                c1_t58 * c1_t59 * c1_t60 * c1_t61) - c1_L7 * c1_t54 * c1_t55 *
               c1_t59 * c1_t60 * c1_t61) + c1_L7 * c1_t57 * c1_t58 * c1_t59 *
    c1_t60
    * c1_t61;
  c1_u_x[3] = (-c1_t54) * (c1_t58 * c1_t61 + c1_t53 * c1_t55 * c1_t60) - c1_t57 *
    (c1_t55 * c1_t61 - c1_t53 * c1_t58 * c1_t60);
  c1_u_x[4] = c1_t54 * (c1_t55 * c1_t77 - c1_t53 * c1_t58 * c1_t59) - c1_t57 *
    (c1_t58 * c1_t77 + c1_t53 * c1_t55 * c1_t59);
  c1_u_x[5] = (-c1_t54) * (c1_t55 * c1_t81 + c1_t53 * c1_t56 * c1_t58) + c1_t57 *
    (c1_t58 * c1_t81 - c1_t53 * c1_t55 * c1_t56);
  c1_u_x[6] = ((((((c1_t62 + c1_t63) + c1_t64) + c1_t65) + c1_t66) + c1_L3 *
                c1_t55 * c1_t61) - c1_L3 * c1_t53 * c1_t58 * c1_t60) -
    c1_L9 * c1_t52 * c1_t59 * c1_t61;
  c1_u_x[7] = (((((((((c1_t67 - c1_L5 * c1_t52 * c1_t56) - c1_L6 * c1_t59 *
                      c1_t60) - c1_L7 * c1_t59 * c1_t60) - c1_L9 * c1_t52 *
                    c1_t53) + c1_L3 * c1_t52 * c1_t56 * c1_t58) + c1_L3 * c1_t53
                  * c1_t55 * c1_t59) - c1_L6 * c1_t52 * c1_t56 * c1_t61) - c1_L5
                * c1_t59
                * c1_t60 * c1_t61) - c1_L7 * c1_t52 * c1_t56 * c1_t61) + c1_L3 *
    c1_t58 * c1_t59 * c1_t60 * c1_t61;
  c1_u_x[8] = (((((((((c1_t68 + c1_t69) + c1_t70) + c1_t71) + c1_t72) - c1_L6 *
                   c1_t56 * c1_t60) - c1_L7 * c1_t56 * c1_t60) + c1_L3 *
                 c1_t53 * c1_t55 * c1_t56) - c1_L3 * c1_t52 * c1_t58 * c1_t59) -
               c1_L5 * c1_t56 * c1_t60 * c1_t61) + c1_L3 * c1_t56 * c1_t58 *
    c1_t60
    * c1_t61;
  c1_u_x[9] = c1_t74;
  c1_u_x[10] = c1_t79;
  c1_u_x[11] = c1_t82;
  c1_u_x[12] = ((((c1_t62 + c1_t63) + c1_t64) + c1_t65) + c1_t66) - c1_L9 *
    c1_t52 * c1_t59 * c1_t61;
  c1_u_x[13] = ((((((c1_t67 - c1_L5 * c1_t52 * c1_t56) - c1_L6 * c1_t59 * c1_t60)
                   - c1_L7 * c1_t59 * c1_t60) - c1_L9 * c1_t52 * c1_t53
                  ) - c1_L6 * c1_t52 * c1_t56 * c1_t61) - c1_L5 * c1_t59 *
                c1_t60 * c1_t61) - c1_L7 * c1_t52 * c1_t56 * c1_t61;
  c1_u_x[14] = ((((((c1_t68 + c1_t69) + c1_t70) + c1_t71) + c1_t72) - c1_L6 *
                 c1_t56 * c1_t60) - c1_L7 * c1_t56 * c1_t60) - c1_L5 *
    c1_t56 * c1_t60 * c1_t61;
  c1_u_x[15] = c1_t74;
  c1_u_x[16] = c1_t79;
  c1_u_x[17] = c1_t82;
  c1_u_x[18] = (-c1_t53) * (c1_L8 * c1_t56 - c1_L9 * c1_t59);
  c1_u_x[19] = ((-c1_L9) * c1_t61 + c1_L6 * c1_t53 * c1_t56) + c1_L7 * c1_t53 *
    c1_t56;
  c1_u_x[20] = (c1_L8 * c1_t61 - c1_L6 * c1_t53 * c1_t59) - c1_L7 * c1_t53 *
    c1_t59;
  c1_u_x[21] = c1_t61;
  c1_u_x[22] = c1_t53 * c1_t59;
  c1_u_x[23] = c1_t53 * c1_t56;
  c1_u_x[24] = c1_L8 * c1_t59 + c1_L9 * c1_t56;
  c1_u_x[25] = (-c1_t59) * c1_t73;
  c1_u_x[26] = (-c1_t56) * c1_t73;
  c1_u_x[27] = 0.0;
  c1_u_x[28] = c1_t56;
  c1_u_x[29] = -c1_t59;
  c1_u_x[30] = 0.0;
  c1_u_x[31] = -c1_L9;
  c1_u_x[32] = c1_L8;
  c1_u_x[33] = 1.0;
  c1_u_x[34] = 0.0;
  c1_u_x[35] = 0.0;
  for (c1_k = 1; c1_k < 37; c1_k = c1_k + 1) {
    c1_b_k = c1_k;
    c1_b_body_Jacobian[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 36, 1, 0) - 1] = c1_u_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c1_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(1, -52);
  sf_debug_symbol_scope_pop();
}

static void c1_AdjointInv(SFc1_DynVerifyInstanceStruct *chartInstance, real_T
  c1_g[16], real_T c1_Adg_inv[36])
{
  uint32_T c1_debug_family_var_map[7];
  static const char *c1_sv1[7] = { "RT", "p", "ze", "nargin", "nargout", "g",
    "Adg_inv" };

  real_T c1_RT[9];
  real_T c1_p[3];
  real_T c1_ze[9];
  real_T c1_nargin = 1.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_y;
  real_T c1_k;
  real_T c1_b_k;
  boolean_T c1_b0;
  int32_T c1_i65;
  int32_T c1_i66;
  int32_T c1_i67;
  int32_T c1_i68;
  int32_T c1_i69;
  int32_T c1_i70;
  int32_T c1_i71;
  real_T c1_w[3];
  uint32_T c1_b_debug_family_var_map[4];
  static const char *c1_sv2[4] = { "nargin", "nargout", "w", "wh" };

  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_wh[9];
  real_T c1_n;
  real_T c1_c_k;
  real_T c1_d_k;
  int32_T c1_i72;
  int32_T c1_i73;
  real_T c1_a[9];
  int32_T c1_i74;
  real_T c1_b[9];
  int32_T c1_i75;
  real_T c1_A[9];
  int32_T c1_i76;
  real_T c1_B[9];
  int32_T c1_i77;
  real_T c1_b_A[9];
  int32_T c1_i78;
  real_T c1_b_B[9];
  int32_T c1_i79;
  real_T c1_c_A[9];
  int32_T c1_i80;
  real_T c1_c_B[9];
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  real_T c1_b_y[9];
  int32_T c1_i84;
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  int32_T c1_i88;
  int32_T c1_i89;
  int32_T c1_i90;
  int32_T c1_i91;
  int32_T c1_i92;
  int32_T c1_i93;
  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  int32_T c1_i97;
  int32_T c1_i98;
  int32_T c1_i99;
  int32_T c1_i100;
  int32_T c1_i101;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c1_sv1, c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c1_RT, c1_h_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c1_p, c1_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c1_ze, c1_h_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c1_nargin, c1_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c1_nargout, c1_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c1_g, c1_f_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c1_Adg_inv, c1_e_sf_marshall, 6U);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2, 3);
  c1_y = FALSE;
  c1_k = 1.0;
 label_1:
  ;
  if (c1_k <= 2.0) {
    c1_b_k = c1_k;
    c1_b0 = TRUE;
    if (!c1_b0) {
      c1_y = TRUE;
    } else {
      c1_k = c1_k + 1.0;
      goto label_1;
    }
  }

  CV_SCRIPT_IF(2, 0, c1_y);
  _SFD_SCRIPT_CALL(2, 7);
  c1_i65 = 0;
  for (c1_i66 = 0; c1_i66 < 3; c1_i66 = c1_i66 + 1) {
    c1_i67 = 0;
    for (c1_i68 = 0; c1_i68 < 3; c1_i68 = c1_i68 + 1) {
      c1_RT[c1_i68 + c1_i65] = c1_g[c1_i67 + c1_i66];
      c1_i67 = c1_i67 + 4;
    }

    c1_i65 = c1_i65 + 3;
  }

  _SFD_SCRIPT_CALL(2, 8);
  for (c1_i69 = 0; c1_i69 < 3; c1_i69 = c1_i69 + 1) {
    c1_p[c1_i69] = c1_g[c1_i69 + 12];
  }

  _SFD_SCRIPT_CALL(2, 9);
  for (c1_i70 = 0; c1_i70 < 9; c1_i70 = c1_i70 + 1) {
    c1_ze[c1_i70] = 0.0;
  }

  _SFD_SCRIPT_CALL(2, 10);
  for (c1_i71 = 0; c1_i71 < 3; c1_i71 = c1_i71 + 1) {
    c1_w[c1_i71] = c1_p[c1_i71];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_sv2, c1_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_b_nargin, c1_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c1_b_nargout, c1_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c1_w, c1_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c1_wh, c1_h_sf_marshall, 3U);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3, 3);
  c1_n = 0.0;
  c1_c_k = 1.0;
 label_2:
  ;
  if (c1_c_k <= 2.0) {
    c1_d_k = c1_c_k;
    if (3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_d_k), 1, 2, 1, 0) - 1) == 0.0) {
      c1_n = 0.0;
    } else {
      if (3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c1_d_k), 1, 2, 1, 0) - 1) > c1_n) {
        c1_n = 3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c1_d_k), 1, 2, 1, 0) - 1);
      }

      c1_c_k = c1_c_k + 1.0;
      goto label_2;
    }
  }

  CV_SCRIPT_IF(3, 0, c1_n != 3.0);

  /* wh = diag(sym('wh',[1,3])); */
  _SFD_SCRIPT_CALL(3, 8);
  for (c1_i72 = 0; c1_i72 < 9; c1_i72 = c1_i72 + 1) {
    c1_wh[c1_i72] = 0.0;
  }

  _SFD_SCRIPT_CALL(3, 9);
  c1_wh[0] = 0.0;
  _SFD_SCRIPT_CALL(3, 10);
  c1_wh[4] = 0.0;
  _SFD_SCRIPT_CALL(3, 11);
  c1_wh[8] = 0.0;
  _SFD_SCRIPT_CALL(3, 14);
  c1_wh[3] = -c1_w[2];
  _SFD_SCRIPT_CALL(3, 15);
  c1_wh[6] = c1_w[1];
  _SFD_SCRIPT_CALL(3, 16);
  c1_wh[1] = c1_w[2];
  _SFD_SCRIPT_CALL(3, 17);
  c1_wh[7] = -c1_w[0];
  _SFD_SCRIPT_CALL(3, 18);
  c1_wh[2] = -c1_w[1];
  _SFD_SCRIPT_CALL(3, 19);
  c1_wh[5] = c1_w[0];
  _SFD_SCRIPT_CALL(3, -19);
  sf_debug_symbol_scope_pop();
  for (c1_i73 = 0; c1_i73 < 9; c1_i73 = c1_i73 + 1) {
    c1_a[c1_i73] = -c1_RT[c1_i73];
  }

  for (c1_i74 = 0; c1_i74 < 9; c1_i74 = c1_i74 + 1) {
    c1_b[c1_i74] = c1_wh[c1_i74];
  }

  c1_eml_scalar_eg(chartInstance);
  c1_eml_scalar_eg(chartInstance);
  for (c1_i75 = 0; c1_i75 < 9; c1_i75 = c1_i75 + 1) {
    c1_A[c1_i75] = c1_a[c1_i75];
  }

  for (c1_i76 = 0; c1_i76 < 9; c1_i76 = c1_i76 + 1) {
    c1_B[c1_i76] = c1_b[c1_i76];
  }

  for (c1_i77 = 0; c1_i77 < 9; c1_i77 = c1_i77 + 1) {
    c1_b_A[c1_i77] = c1_A[c1_i77];
  }

  for (c1_i78 = 0; c1_i78 < 9; c1_i78 = c1_i78 + 1) {
    c1_b_B[c1_i78] = c1_B[c1_i78];
  }

  for (c1_i79 = 0; c1_i79 < 9; c1_i79 = c1_i79 + 1) {
    c1_c_A[c1_i79] = c1_b_A[c1_i79];
  }

  for (c1_i80 = 0; c1_i80 < 9; c1_i80 = c1_i80 + 1) {
    c1_c_B[c1_i80] = c1_b_B[c1_i80];
  }

  for (c1_i81 = 0; c1_i81 < 3; c1_i81 = c1_i81 + 1) {
    c1_i82 = 0;
    for (c1_i83 = 0; c1_i83 < 3; c1_i83 = c1_i83 + 1) {
      c1_b_y[c1_i82 + c1_i81] = 0.0;
      c1_i84 = 0;
      for (c1_i85 = 0; c1_i85 < 3; c1_i85 = c1_i85 + 1) {
        c1_b_y[c1_i82 + c1_i81] = c1_b_y[c1_i82 + c1_i81] + c1_c_A[c1_i84 +
          c1_i81] * c1_c_B[c1_i85 + c1_i82];
        c1_i84 = c1_i84 + 3;
      }

      c1_i82 = c1_i82 + 3;
    }
  }

  c1_i86 = 0;
  c1_i87 = 0;
  for (c1_i88 = 0; c1_i88 < 3; c1_i88 = c1_i88 + 1) {
    for (c1_i89 = 0; c1_i89 < 3; c1_i89 = c1_i89 + 1) {
      c1_Adg_inv[c1_i89 + c1_i86] = c1_RT[c1_i89 + c1_i87];
    }

    c1_i86 = c1_i86 + 6;
    c1_i87 = c1_i87 + 3;
  }

  c1_i90 = 0;
  c1_i91 = 0;
  for (c1_i92 = 0; c1_i92 < 3; c1_i92 = c1_i92 + 1) {
    for (c1_i93 = 0; c1_i93 < 3; c1_i93 = c1_i93 + 1) {
      c1_Adg_inv[(c1_i93 + c1_i90) + 18] = c1_b_y[c1_i93 + c1_i91];
    }

    c1_i90 = c1_i90 + 6;
    c1_i91 = c1_i91 + 3;
  }

  c1_i94 = 0;
  c1_i95 = 0;
  for (c1_i96 = 0; c1_i96 < 3; c1_i96 = c1_i96 + 1) {
    for (c1_i97 = 0; c1_i97 < 3; c1_i97 = c1_i97 + 1) {
      c1_Adg_inv[(c1_i97 + c1_i94) + 3] = c1_ze[c1_i97 + c1_i95];
    }

    c1_i94 = c1_i94 + 6;
    c1_i95 = c1_i95 + 3;
  }

  c1_i98 = 0;
  c1_i99 = 0;
  for (c1_i100 = 0; c1_i100 < 3; c1_i100 = c1_i100 + 1) {
    for (c1_i101 = 0; c1_i101 < 3; c1_i101 = c1_i101 + 1) {
      c1_Adg_inv[(c1_i101 + c1_i98) + 21] = c1_RT[c1_i101 + c1_i99];
    }

    c1_i98 = c1_i98 + 6;
    c1_i99 = c1_i99 + 3;
  }

  /* Adg_inv(4:6,4:6) = RT; */
  _SFD_SCRIPT_CALL(2, -10);
  sf_debug_symbol_scope_pop();
}

static void c1_eml_scalar_eg(SFc1_DynVerifyInstanceStruct *chartInstance)
{
}

static void c1_eps(SFc1_DynVerifyInstanceStruct *chartInstance)
{
}

static void c1_eml_matlab_zgetrf(SFc1_DynVerifyInstanceStruct *chartInstance,
  real_T c1_A[36], real_T c1_b_A[36], int32_T c1_ipiv[6]
  , int32_T *c1_info)
{
  int32_T c1_i102;
  int32_T c1_i103;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_jm1;
  int32_T c1_b;
  int32_T c1_mmj;
  int32_T c1_b_a;
  int32_T c1_c;
  int32_T c1_b_b;
  int32_T c1_jj;
  int32_T c1_c_a;
  int32_T c1_jp1j;
  int32_T c1_d_a;
  int32_T c1_b_c;
  int32_T c1_i104;
  real_T c1_c_A[36];
  int32_T c1_e_a;
  int32_T c1_jpiv_offset;
  int32_T c1_f_a;
  int32_T c1_c_b;
  int32_T c1_jpiv;
  int32_T c1_g_a;
  int32_T c1_d_b;
  int32_T c1_c_c;
  int32_T c1_e_b;
  int32_T c1_jrow;
  int32_T c1_h_a;
  int32_T c1_f_b;
  int32_T c1_jprow;
  int32_T c1_i105;
  real_T c1_x[36];
  int32_T c1_ix0;
  int32_T c1_iy0;
  int32_T c1_i106;
  int32_T c1_i107;
  real_T c1_b_x[36];
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_i108;
  real_T c1_c_x[36];
  int32_T c1_i109;
  real_T c1_d_x[36];
  real_T c1_e_x[36];
  int32_T c1_i110;
  int32_T c1_i111;
  int32_T c1_b_jp1j;
  int32_T c1_i_a;
  int32_T c1_d_c;
  int32_T c1_j_a;
  int32_T c1_g_b;
  int32_T c1_loop_ub;
  int32_T c1_i;
  int32_T c1_b_i;
  real_T c1_f_x;
  real_T c1_y;
  real_T c1_g_x;
  real_T c1_b_y;
  real_T c1_z;
  int32_T c1_h_b;
  int32_T c1_e_c;
  int32_T c1_k_a;
  int32_T c1_f_c;
  int32_T c1_l_a;
  int32_T c1_g_c;
  int32_T c1_m;
  int32_T c1_n;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_i112;
  real_T c1_d_A[36];
  int32_T c1_ia0;
  int32_T c1_i113;
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_d_ix0;
  int32_T c1_d_iy0;
  int32_T c1_i114;
  real_T c1_e_A[36];
  int32_T c1_b_ia0;
  int32_T c1_i115;
  int32_T c1_c_m;
  int32_T c1_c_n;
  int32_T c1_e_ix0;
  int32_T c1_e_iy0;
  int32_T c1_i116;
  real_T c1_f_A[36];
  int32_T c1_c_ia0;
  int32_T c1_i117;
  int32_T c1_i118;
  real_T c1_g_A[36];
  for (c1_i102 = 0; c1_i102 < 36; c1_i102 = c1_i102 + 1) {
    c1_b_A[c1_i102] = c1_A[c1_i102];
  }

  c1_eps(chartInstance);
  for (c1_i103 = 0; c1_i103 < 6; c1_i103 = c1_i103 + 1) {
    c1_ipiv[c1_i103] = 1 + c1_i103;
  }

  *c1_info = 0;
  for (c1_j = 1; c1_j < 6; c1_j = c1_j + 1) {
    c1_b_j = c1_j;
    c1_a = c1_b_j;
    c1_jm1 = c1_a - 1;
    c1_b = c1_b_j;
    c1_mmj = 6 - c1_b;
    c1_b_a = c1_jm1;
    c1_c = c1_b_a * 7;
    c1_b_b = c1_c;
    c1_jj = 1 + c1_b_b;
    c1_c_a = c1_jj;
    c1_jp1j = c1_c_a + 1;
    c1_d_a = c1_mmj;
    c1_b_c = c1_d_a + 1;
    for (c1_i104 = 0; c1_i104 < 36; c1_i104 = c1_i104 + 1) {
      c1_c_A[c1_i104] = c1_b_A[c1_i104];
    }

    c1_e_a = c1_eml_ixamax(chartInstance, c1_b_c, c1_c_A, c1_jj);
    c1_jpiv_offset = c1_e_a - 1;
    c1_f_a = c1_jj;
    c1_c_b = c1_jpiv_offset;
    c1_jpiv = c1_f_a + c1_c_b;
    if (c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c1_jpiv_offset != 0.0) {
        c1_g_a = c1_b_j;
        c1_d_b = c1_jpiv_offset;
        c1_c_c = c1_g_a + c1_d_b;
        c1_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 6, 1, 0) - 1] = c1_c_c;
        c1_e_b = c1_jm1;
        c1_jrow = 1 + c1_e_b;
        c1_h_a = c1_jrow;
        c1_f_b = c1_jpiv_offset;
        c1_jprow = c1_h_a + c1_f_b;
        for (c1_i105 = 0; c1_i105 < 36; c1_i105 = c1_i105 + 1) {
          c1_x[c1_i105] = c1_b_A[c1_i105];
        }

        c1_ix0 = c1_jrow;
        c1_iy0 = c1_jprow;
        for (c1_i106 = 0; c1_i106 < 36; c1_i106 = c1_i106 + 1) {
          c1_b_A[c1_i106] = c1_x[c1_i106];
        }

        for (c1_i107 = 0; c1_i107 < 36; c1_i107 = c1_i107 + 1) {
          c1_b_x[c1_i107] = c1_b_A[c1_i107];
        }

        c1_b_ix0 = c1_ix0;
        c1_b_iy0 = c1_iy0;
        for (c1_i108 = 0; c1_i108 < 36; c1_i108 = c1_i108 + 1) {
          c1_c_x[c1_i108] = c1_b_x[c1_i108];
        }

        for (c1_i109 = 0; c1_i109 < 36; c1_i109 = c1_i109 + 1) {
          c1_d_x[c1_i109] = c1_c_x[c1_i109];
        }

        c1_ceval_xswap(chartInstance, 6, c1_d_x, c1_b_ix0, 6, c1_b_iy0, 6,
                       c1_e_x);
        for (c1_i110 = 0; c1_i110 < 36; c1_i110 = c1_i110 + 1) {
          c1_c_x[c1_i110] = c1_e_x[c1_i110];
        }

        for (c1_i111 = 0; c1_i111 < 36; c1_i111 = c1_i111 + 1) {
          c1_b_A[c1_i111] = c1_c_x[c1_i111];
        }
      }

      c1_b_jp1j = c1_jp1j;
      c1_i_a = c1_mmj;
      c1_d_c = c1_i_a - 1;
      c1_j_a = c1_jp1j;
      c1_g_b = c1_d_c;
      c1_loop_ub = c1_j_a + c1_g_b;
      for (c1_i = c1_b_jp1j; c1_i <= c1_loop_ub; c1_i = c1_i + 1) {
        c1_b_i = c1_i;
        c1_f_x = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 36, 1, 0) - 1];
        c1_y = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_jj), 1, 36, 1, 0) - 1];
        c1_g_x = c1_f_x;
        c1_b_y = c1_y;
        c1_z = c1_g_x / c1_b_y;
        c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_i), 1, 36, 1, 0) - 1] = c1_z;
      }
    } else {
      *c1_info = c1_b_j;
    }

    c1_h_b = c1_b_j;
    c1_e_c = 6 - c1_h_b;
    c1_k_a = c1_jj;
    c1_f_c = c1_k_a + 6;
    c1_l_a = c1_jj;
    c1_g_c = c1_l_a + 7;
    c1_m = c1_mmj;
    c1_n = c1_e_c;
    c1_c_ix0 = c1_jp1j;
    c1_c_iy0 = c1_f_c;
    for (c1_i112 = 0; c1_i112 < 36; c1_i112 = c1_i112 + 1) {
      c1_d_A[c1_i112] = c1_b_A[c1_i112];
    }

    c1_ia0 = c1_g_c;
    for (c1_i113 = 0; c1_i113 < 36; c1_i113 = c1_i113 + 1) {
      c1_b_A[c1_i113] = c1_d_A[c1_i113];
    }

    c1_b_m = c1_m;
    c1_b_n = c1_n;
    c1_d_ix0 = c1_c_ix0;
    c1_d_iy0 = c1_c_iy0;
    for (c1_i114 = 0; c1_i114 < 36; c1_i114 = c1_i114 + 1) {
      c1_e_A[c1_i114] = c1_b_A[c1_i114];
    }

    c1_b_ia0 = c1_ia0;
    for (c1_i115 = 0; c1_i115 < 36; c1_i115 = c1_i115 + 1) {
      c1_b_A[c1_i115] = c1_e_A[c1_i115];
    }

    c1_c_m = c1_b_m;
    c1_c_n = c1_b_n;
    c1_e_ix0 = c1_d_ix0;
    c1_e_iy0 = c1_d_iy0;
    for (c1_i116 = 0; c1_i116 < 36; c1_i116 = c1_i116 + 1) {
      c1_f_A[c1_i116] = c1_b_A[c1_i116];
    }

    c1_c_ia0 = c1_b_ia0;
    for (c1_i117 = 0; c1_i117 < 36; c1_i117 = c1_i117 + 1) {
      c1_b_A[c1_i117] = c1_f_A[c1_i117];
    }

    if ((real_T)c1_c_m < 1.0) {
    } else if ((real_T)c1_c_n < 1.0) {
    } else {
      for (c1_i118 = 0; c1_i118 < 36; c1_i118 = c1_i118 + 1) {
        c1_g_A[c1_i118] = c1_b_A[c1_i118];
      }

      c1_ceval_xger(chartInstance, c1_c_m, c1_c_n, -1.0, c1_e_ix0, 1, c1_e_iy0,
                    6, c1_g_A, c1_c_ia0, 6, c1_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c1_info == 0.0) {
    if (!(c1_b_A[35] != 0.0)) {
      *c1_info = 6;
      return;
    }
  }
}

static int32_T c1_eml_ixamax(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[36], int32_T c1_ix0)
{
  int32_T c1_b_n;
  int32_T c1_i119;
  real_T c1_b_x[36];
  int32_T c1_b_ix0;
  int32_T c1_i120;
  real_T c1_c_x[36];
  c1_b_n = c1_n;
  for (c1_i119 = 0; c1_i119 < 36; c1_i119 = c1_i119 + 1) {
    c1_b_x[c1_i119] = c1_x[c1_i119];
  }

  c1_b_ix0 = c1_ix0;
  for (c1_i120 = 0; c1_i120 < 36; c1_i120 = c1_i120 + 1) {
    c1_c_x[c1_i120] = c1_b_x[c1_i120];
  }

  return c1_ceval_ixamax(chartInstance, c1_b_n, c1_c_x, c1_b_ix0, 1);
}

static int32_T c1_ceval_ixamax(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_n, real_T c1_x[36], int32_T c1_ix0, int32_T
  c1_incx)
{
  return idamax32(&c1_n, &c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 36, 1, 0) - 1], &
                  c1_incx);
}

static void c1_ceval_xswap(SFc1_DynVerifyInstanceStruct *chartInstance, int32_T
  c1_n, real_T c1_x[36], int32_T c1_ix0, int32_T
  c1_incx, int32_T c1_iy0, int32_T c1_incy, real_T c1_b_x[36])
{
  int32_T c1_i121;

  /* Empty Loop. */
  for (c1_i121 = 0; c1_i121 < 36; c1_i121 = c1_i121 + 1) {
    c1_b_x[c1_i121] = c1_x[c1_i121];
  }

  dswap32(&c1_n, &c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 36, 1, 0) - 1], &c1_incx
          , &c1_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c1_iy0), 1, 36, 1, 0) - 1], &c1_incy);
}

static void c1_ceval_xger(SFc1_DynVerifyInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, int32_T c1_ix0
  , int32_T c1_incx, int32_T c1_iy0, int32_T c1_incy, real_T c1_A[36], int32_T
  c1_ia0, int32_T c1_lda, real_T c1_b_A[36])
{
  int32_T c1_i122;
  for (c1_i122 = 0; c1_i122 < 36; c1_i122 = c1_i122 + 1) {
    c1_b_A[c1_i122] = c1_A[c1_i122];
  }

  dger32(&c1_m, &c1_n, &c1_alpha1, &c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ix0), 1, 36, 1,
          0) - 1], &c1_incx, &c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_iy0), 1, 36, 1, 0) - 1], &
         c1_incy, &c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ia0), 1, 36, 1, 0) - 1], &c1_lda);
}

static void c1_eml_warning(SFc1_DynVerifyInstanceStruct *chartInstance)
{
  int32_T c1_i123;
  static char_T c1_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c1_u[21];
  const mxArray *c1_y = NULL;
  int32_T c1_i124;
  static char_T c1_cv1[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c1_b_u[40];
  const mxArray *c1_b_y = NULL;
  for (c1_i123 = 0; c1_i123 < 21; c1_i123 = c1_i123 + 1) {
    c1_u[c1_i123] = c1_cv0[c1_i123];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c1_i124 = 0; c1_i124 < 40; c1_i124 = c1_i124 + 1) {
    c1_b_u[c1_i124] = c1_cv1[c1_i124];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c1_y, 14, c1_b_y);
}

static void c1_eml_blas_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A
  [36], int32_T c1_ia0, int32_T c1_lda, real_T c1_B[36], int32_T c1_ib0, int32_T
  c1_ldb, real_T c1_b_B[36])
{
  int32_T c1_i125;
  int32_T c1_i126;
  real_T c1_b_A[36];
  int32_T c1_i127;
  real_T c1_c_B[36];
  for (c1_i125 = 0; c1_i125 < 36; c1_i125 = c1_i125 + 1) {
    c1_b_B[c1_i125] = c1_B[c1_i125];
  }

  for (c1_i126 = 0; c1_i126 < 36; c1_i126 = c1_i126 + 1) {
    c1_b_A[c1_i126] = c1_A[c1_i126];
  }

  for (c1_i127 = 0; c1_i127 < 36; c1_i127 = c1_i127 + 1) {
    c1_c_B[c1_i127] = c1_b_B[c1_i127];
  }

  c1_ceval_xtrsm(chartInstance, c1_m, c1_n, c1_alpha1, c1_b_A, c1_ia0, c1_lda,
                 c1_c_B, c1_ib0, c1_ldb, c1_b_B);
}

static void c1_ceval_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance, int32_T
  c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[36
  ], int32_T c1_ia0, int32_T c1_lda, real_T c1_B[36], int32_T c1_ib0, int32_T
  c1_ldb, real_T c1_b_B[36])
{
  char_T c1_SIDE;
  char_T c1_UPLO;
  char_T c1_TRANSA;
  char_T c1_DIAGA;
  int32_T c1_i128;
  c1_SIDE = 'L';
  c1_UPLO = 'L';
  c1_TRANSA = 'N';
  c1_DIAGA = 'U';
  for (c1_i128 = 0; c1_i128 < 36; c1_i128 = c1_i128 + 1) {
    c1_b_B[c1_i128] = c1_B[c1_i128];
  }

  dtrsm32(&c1_SIDE, &c1_UPLO, &c1_TRANSA, &c1_DIAGA, &c1_m, &c1_n, &c1_alpha1,
          &c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ia0), 1, 36, 1, 0) - 1], &c1_lda,
          &c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ib0), 1, 36, 1, 0) - 1], &c1_ldb);
}

static void c1_b_eml_blas_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T
  c1_A[36], int32_T c1_ia0, int32_T c1_lda, real_T c1_B[36], int32_T c1_ib0,
  int32_T c1_ldb, real_T c1_b_B[36])
{
  int32_T c1_i129;
  int32_T c1_i130;
  real_T c1_b_A[36];
  int32_T c1_i131;
  real_T c1_c_B[36];
  for (c1_i129 = 0; c1_i129 < 36; c1_i129 = c1_i129 + 1) {
    c1_b_B[c1_i129] = c1_B[c1_i129];
  }

  for (c1_i130 = 0; c1_i130 < 36; c1_i130 = c1_i130 + 1) {
    c1_b_A[c1_i130] = c1_A[c1_i130];
  }

  for (c1_i131 = 0; c1_i131 < 36; c1_i131 = c1_i131 + 1) {
    c1_c_B[c1_i131] = c1_b_B[c1_i131];
  }

  c1_b_ceval_xtrsm(chartInstance, c1_m, c1_n, c1_alpha1, c1_b_A, c1_ia0, c1_lda,
                   c1_c_B, c1_ib0, c1_ldb, c1_b_B);
}

static void c1_b_ceval_xtrsm(SFc1_DynVerifyInstanceStruct *chartInstance,
  int32_T c1_m, int32_T c1_n, real_T c1_alpha1, real_T c1_A[
  36], int32_T c1_ia0, int32_T c1_lda, real_T c1_B[36], int32_T c1_ib0, int32_T
  c1_ldb, real_T c1_b_B[36])
{
  char_T c1_SIDE;
  char_T c1_UPLO;
  char_T c1_TRANSA;
  char_T c1_DIAGA;
  int32_T c1_i132;
  c1_SIDE = 'L';
  c1_UPLO = 'U';
  c1_TRANSA = 'N';
  c1_DIAGA = 'N';
  for (c1_i132 = 0; c1_i132 < 36; c1_i132 = c1_i132 + 1) {
    c1_b_B[c1_i132] = c1_B[c1_i132];
  }

  dtrsm32(&c1_SIDE, &c1_UPLO, &c1_TRANSA, &c1_DIAGA, &c1_m, &c1_n, &c1_alpha1,
          &c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ia0), 1, 36, 1, 0) - 1], &c1_lda,
          &c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c1_ib0), 1, 36, 1, 0) - 1], &c1_ldb);
}

static void c1_b_eml_scalar_eg(SFc1_DynVerifyInstanceStruct *chartInstance)
{
}

static const mxArray *c1_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i133;
  real_T c1_b_u[6];
  int32_T c1_i134;
  real_T c1_c_u[6];
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i133 = 0; c1_i133 < 6; c1_i133 = c1_i133 + 1) {
    c1_b_u[c1_i133] = (*((real_T (*)[6])c1_u))[c1_i133];
  }

  for (c1_i134 = 0; c1_i134 < 6; c1_i134 = c1_i134 + 1) {
    c1_c_u[c1_i134] = c1_b_u[c1_i134];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_b_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i135;
  real_T c1_b_u[9];
  int32_T c1_i136;
  real_T c1_c_u[9];
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i135 = 0; c1_i135 < 9; c1_i135 = c1_i135 + 1) {
    c1_b_u[c1_i135] = (*((real_T (*)[9])c1_u))[c1_i135];
  }

  for (c1_i136 = 0; c1_i136 < 9; c1_i136 = c1_i136 + 1) {
    c1_c_u[c1_i136] = c1_b_u[c1_i136];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_c_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i137;
  real_T c1_b_u[3];
  int32_T c1_i138;
  real_T c1_c_u[3];
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i137 = 0; c1_i137 < 3; c1_i137 = c1_i137 + 1) {
    c1_b_u[c1_i137] = (*((real_T (*)[3])c1_u))[c1_i137];
  }

  for (c1_i138 = 0; c1_i138 < 3; c1_i138 = c1_i138 + 1) {
    c1_c_u[c1_i138] = c1_b_u[c1_i138];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_d_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((real_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_e_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i139;
  int32_T c1_i140;
  int32_T c1_i141;
  real_T c1_b_u[36];
  int32_T c1_i142;
  int32_T c1_i143;
  int32_T c1_i144;
  real_T c1_c_u[36];
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i139 = 0;
  for (c1_i140 = 0; c1_i140 < 6; c1_i140 = c1_i140 + 1) {
    for (c1_i141 = 0; c1_i141 < 6; c1_i141 = c1_i141 + 1) {
      c1_b_u[c1_i141 + c1_i139] = (*((real_T (*)[36])c1_u))[c1_i141 + c1_i139];
    }

    c1_i139 = c1_i139 + 6;
  }

  c1_i142 = 0;
  for (c1_i143 = 0; c1_i143 < 6; c1_i143 = c1_i143 + 1) {
    for (c1_i144 = 0; c1_i144 < 6; c1_i144 = c1_i144 + 1) {
      c1_c_u[c1_i144 + c1_i142] = c1_b_u[c1_i144 + c1_i142];
    }

    c1_i142 = c1_i142 + 6;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_f_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i145;
  int32_T c1_i146;
  int32_T c1_i147;
  real_T c1_b_u[16];
  int32_T c1_i148;
  int32_T c1_i149;
  int32_T c1_i150;
  real_T c1_c_u[16];
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i145 = 0;
  for (c1_i146 = 0; c1_i146 < 4; c1_i146 = c1_i146 + 1) {
    for (c1_i147 = 0; c1_i147 < 4; c1_i147 = c1_i147 + 1) {
      c1_b_u[c1_i147 + c1_i145] = (*((real_T (*)[16])c1_u))[c1_i147 + c1_i145];
    }

    c1_i145 = c1_i145 + 4;
  }

  c1_i148 = 0;
  for (c1_i149 = 0; c1_i149 < 4; c1_i149 = c1_i149 + 1) {
    for (c1_i150 = 0; c1_i150 < 4; c1_i150 = c1_i150 + 1) {
      c1_c_u[c1_i150 + c1_i148] = c1_b_u[c1_i150 + c1_i148];
    }

    c1_i148 = c1_i148 + 4;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_g_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i151;
  real_T c1_b_u[6];
  int32_T c1_i152;
  real_T c1_c_u[6];
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  for (c1_i151 = 0; c1_i151 < 6; c1_i151 = c1_i151 + 1) {
    c1_b_u[c1_i151] = (*((real_T (*)[6])c1_u))[c1_i151];
  }

  for (c1_i152 = 0; c1_i152 < 6; c1_i152 = c1_i152 + 1) {
    c1_c_u[c1_i152] = c1_b_u[c1_i152];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static const mxArray *c1_h_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  int32_T c1_i153;
  int32_T c1_i154;
  int32_T c1_i155;
  real_T c1_b_u[9];
  int32_T c1_i156;
  int32_T c1_i157;
  int32_T c1_i158;
  real_T c1_c_u[9];
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_i153 = 0;
  for (c1_i154 = 0; c1_i154 < 3; c1_i154 = c1_i154 + 1) {
    for (c1_i155 = 0; c1_i155 < 3; c1_i155 = c1_i155 + 1) {
      c1_b_u[c1_i155 + c1_i153] = (*((real_T (*)[9])c1_u))[c1_i155 + c1_i153];
    }

    c1_i153 = c1_i153 + 3;
  }

  c1_i156 = 0;
  for (c1_i157 = 0; c1_i157 < 3; c1_i157 = c1_i157 + 1) {
    for (c1_i158 = 0; c1_i158 < 3; c1_i158 = c1_i158 + 1) {
      c1_c_u[c1_i158 + c1_i156] = c1_b_u[c1_i158 + c1_i156];
    }

    c1_i156 = c1_i156 + 3;
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_c_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

const mxArray *sf_c1_DynVerify_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_ResolvedFunctionInfo c1_info[100];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i159;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 100));
  for (c1_i159 = 0; c1_i159 < 100; c1_i159 = c1_i159 + 1) {
    c1_r0 = &c1_info[c1_i159];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context",
                    "nameCaptureInfo", c1_i159);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name",
                    "nameCaptureInfo", c1_i159);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c1_i159);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c1_i159);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c1_i159);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c1_i159);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c1_i159);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[100])
{
  c1_info[0].context = "";
  c1_info[0].name = "zeros";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[B]zeros";
  c1_info[0].fileLength = 0U;
  c1_info[0].fileTime1 = 0U;
  c1_info[0].fileTime2 = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "ctranspose";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved = "[B]ctranspose";
  c1_info[1].fileLength = 0U;
  c1_info[1].fileTime1 = 0U;
  c1_info[1].fileTime2 = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "fwd_kin";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[2].fileLength = 3324U;
  c1_info[2].fileTime1 = 1366778959U;
  c1_info[2].fileTime2 = 0U;
  c1_info[3].context = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[3].name = "cos";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[3].fileLength = 324U;
  c1_info[3].fileTime1 = 1203422750U;
  c1_info[3].fileTime2 = 0U;
  c1_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[4].name = "nargin";
  c1_info[4].dominantType = "";
  c1_info[4].resolved = "[B]nargin";
  c1_info[4].fileLength = 0U;
  c1_info[4].fileTime1 = 0U;
  c1_info[4].fileTime2 = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[5].name = "gt";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved = "[B]gt";
  c1_info[5].fileLength = 0U;
  c1_info[5].fileTime1 = 0U;
  c1_info[5].fileTime2 = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[6].name = "isa";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved = "[B]isa";
  c1_info[6].fileLength = 0U;
  c1_info[6].fileTime1 = 0U;
  c1_info[6].fileTime2 = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[7].name = "eml_scalar_cos";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[7].fileLength = 602U;
  c1_info[7].fileTime1 = 1209309186U;
  c1_info[7].fileTime2 = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[8].name = "isreal";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved = "[B]isreal";
  c1_info[8].fileLength = 0U;
  c1_info[8].fileTime1 = 0U;
  c1_info[8].fileTime2 = 0U;
  c1_info[9].context = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[9].name = "sin";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[9].fileLength = 324U;
  c1_info[9].fileTime1 = 1203422842U;
  c1_info[9].fileTime2 = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[10].name = "eml_scalar_sin";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[10].fileLength = 601U;
  c1_info[10].fileTime1 = 1209309190U;
  c1_info[10].fileTime2 = 0U;
  c1_info[11].context = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[11].name = "times";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved = "[B]times";
  c1_info[11].fileLength = 0U;
  c1_info[11].fileTime1 = 0U;
  c1_info[11].fileTime2 = 0U;
  c1_info[12].context = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[12].name = "plus";
  c1_info[12].dominantType = "double";
  c1_info[12].resolved = "[B]plus";
  c1_info[12].fileLength = 0U;
  c1_info[12].fileTime1 = 0U;
  c1_info[12].fileTime2 = 0U;
  c1_info[13].context = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[13].name = "minus";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved = "[B]minus";
  c1_info[13].fileLength = 0U;
  c1_info[13].fileTime1 = 0U;
  c1_info[13].fileTime2 = 0U;
  c1_info[14].context = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[14].name = "uminus";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved = "[B]uminus";
  c1_info[14].fileLength = 0U;
  c1_info[14].fileTime1 = 0U;
  c1_info[14].fileTime2 = 0U;
  c1_info[15].context = "[E]D:/Learn/MatlabProgram/Fanuc/fwd_kin.m";
  c1_info[15].name = "reshape";
  c1_info[15].dominantType = "double";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[15].fileLength = 4857U;
  c1_info[15].fileTime1 = 1242276774U;
  c1_info[15].fileTime2 = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[16].name = "eml_index_class";
  c1_info[16].dominantType = "";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[16].fileLength = 909U;
  c1_info[16].fileTime1 = 1192445182U;
  c1_info[16].fileTime2 = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[17].name = "cast";
  c1_info[17].dominantType = "double";
  c1_info[17].resolved = "[B]cast";
  c1_info[17].fileLength = 0U;
  c1_info[17].fileTime1 = 0U;
  c1_info[17].fileTime2 = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[18].name = "size";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved = "[B]size";
  c1_info[18].fileLength = 0U;
  c1_info[18].fileTime1 = 0U;
  c1_info[18].fileTime2 = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c1_info[19].name = "eq";
  c1_info[19].dominantType = "double";
  c1_info[19].resolved = "[B]eq";
  c1_info[19].fileLength = 0U;
  c1_info[19].fileTime1 = 0U;
  c1_info[19].fileTime2 = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c1_info[20].name = "eml_assert_valid_size_arg";
  c1_info[20].dominantType = "double";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[20].fileLength = 3315U;
  c1_info[20].fileTime1 = 1256367816U;
  c1_info[20].fileTime2 = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c1_info[21].name = "false";
  c1_info[21].dominantType = "";
  c1_info[21].resolved = "[B]false";
  c1_info[21].fileLength = 0U;
  c1_info[21].fileTime1 = 0U;
  c1_info[21].fileTime2 = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c1_info[22].name = "not";
  c1_info[22].dominantType = "logical";
  c1_info[22].resolved = "[B]not";
  c1_info[22].fileLength = 0U;
  c1_info[22].fileTime1 = 0U;
  c1_info[22].fileTime2 = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[23].name = "isvector";
  c1_info[23].dominantType = "double";
  c1_info[23].resolved = "[B]isvector";
  c1_info[23].fileLength = 0U;
  c1_info[23].fileTime1 = 0U;
  c1_info[23].fileTime2 = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c1_info[24].name = "isinteger";
  c1_info[24].dominantType = "double";
  c1_info[24].resolved = "[B]isinteger";
  c1_info[24].fileLength = 0U;
  c1_info[24].fileTime1 = 0U;
  c1_info[24].fileTime2 = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c1_info[25].name = "ne";
  c1_info[25].dominantType = "double";
  c1_info[25].resolved = "[B]ne";
  c1_info[25].fileLength = 0U;
  c1_info[25].fileTime1 = 0U;
  c1_info[25].fileTime2 = 0U;
  c1_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c1_info[26].name = "isinf";
  c1_info[26].dominantType = "double";
  c1_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[26].fileLength = 541U;
  c1_info[26].fileTime1 = 1271383988U;
  c1_info[26].fileTime2 = 0U;
  c1_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c1_info[27].name = "true";
  c1_info[27].dominantType = "";
  c1_info[27].resolved = "[B]true";
  c1_info[27].fileLength = 0U;
  c1_info[27].fileTime1 = 0U;
  c1_info[27].fileTime2 = 0U;
  c1_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c1_info[28].name = "le";
  c1_info[28].dominantType = "double";
  c1_info[28].resolved = "[B]le";
  c1_info[28].fileLength = 0U;
  c1_info[28].fileTime1 = 0U;
  c1_info[28].fileTime2 = 0U;
  c1_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c1_info[29].name = "double";
  c1_info[29].dominantType = "double";
  c1_info[29].resolved = "[B]double";
  c1_info[29].fileLength = 0U;
  c1_info[29].fileTime1 = 0U;
  c1_info[29].fileTime2 = 0U;
  c1_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c1_info[30].name = "mtimes";
  c1_info[30].dominantType = "double";
  c1_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[30].fileLength = 3425U;
  c1_info[30].fileTime1 = 1251010272U;
  c1_info[30].fileTime2 = 0U;
  c1_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[31].name = "isscalar";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved = "[B]isscalar";
  c1_info[31].fileLength = 0U;
  c1_info[31].fileTime1 = 0U;
  c1_info[31].fileTime2 = 0U;
  c1_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[32].name = "strcmp";
  c1_info[32].dominantType = "char";
  c1_info[32].resolved = "[B]strcmp";
  c1_info[32].fileLength = 0U;
  c1_info[32].fileTime1 = 0U;
  c1_info[32].fileTime2 = 0U;
  c1_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[33].name = "class";
  c1_info[33].dominantType = "double";
  c1_info[33].resolved = "[B]class";
  c1_info[33].fileLength = 0U;
  c1_info[33].fileTime1 = 0U;
  c1_info[33].fileTime2 = 0U;
  c1_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[34].name = "intmax";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[34].fileLength = 1535U;
  c1_info[34].fileTime1 = 1192445128U;
  c1_info[34].fileTime2 = 0U;
  c1_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[35].name = "ischar";
  c1_info[35].dominantType = "char";
  c1_info[35].resolved = "[B]ischar";
  c1_info[35].fileLength = 0U;
  c1_info[35].fileTime1 = 0U;
  c1_info[35].fileTime2 = 0U;
  c1_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[36].name = "int32";
  c1_info[36].dominantType = "double";
  c1_info[36].resolved = "[B]int32";
  c1_info[36].fileLength = 0U;
  c1_info[36].fileTime1 = 0U;
  c1_info[36].fileTime2 = 0U;
  c1_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[37].name = "eml_scalar_eg";
  c1_info[37].dominantType = "double";
  c1_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[37].fileLength = 3068U;
  c1_info[37].fileTime1 = 1240240410U;
  c1_info[37].fileTime2 = 0U;
  c1_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[38].name = "isstruct";
  c1_info[38].dominantType = "double";
  c1_info[38].resolved = "[B]isstruct";
  c1_info[38].fileLength = 0U;
  c1_info[38].fileTime1 = 0U;
  c1_info[38].fileTime2 = 0U;
  c1_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c1_info[39].name = "ones";
  c1_info[39].dominantType = "char";
  c1_info[39].resolved = "[B]ones";
  c1_info[39].fileLength = 0U;
  c1_info[39].fileTime1 = 0U;
  c1_info[39].fileTime2 = 0U;
  c1_info[40].context = "";
  c1_info[40].name = "body_Jacobian";
  c1_info[40].dominantType = "double";
  c1_info[40].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/body_Jacobian.m";
  c1_info[40].fileLength = 3760U;
  c1_info[40].fileTime1 = 1366807405U;
  c1_info[40].fileTime2 = 0U;
  c1_info[41].context = "";
  c1_info[41].name = "AdjointInv";
  c1_info[41].dominantType = "double";
  c1_info[41].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/AdjointInv.m";
  c1_info[41].fileLength = 289U;
  c1_info[41].fileTime1 = 1367252826U;
  c1_info[41].fileTime2 = 0U;
  c1_info[42].context = "[E]D:/Learn/MatlabProgram/Fanuc/AdjointInv.m";
  c1_info[42].name = "any";
  c1_info[42].dominantType = "logical";
  c1_info[42].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[42].fileLength = 427U;
  c1_info[42].fileTime1 = 1221245538U;
  c1_info[42].fileTime2 = 0U;
  c1_info[43].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[43].name = "islogical";
  c1_info[43].dominantType = "logical";
  c1_info[43].resolved = "[B]islogical";
  c1_info[43].fileLength = 0U;
  c1_info[43].fileTime1 = 0U;
  c1_info[43].fileTime2 = 0U;
  c1_info[44].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[44].name = "lt";
  c1_info[44].dominantType = "double";
  c1_info[44].resolved = "[B]lt";
  c1_info[44].fileLength = 0U;
  c1_info[44].fileTime1 = 0U;
  c1_info[44].fileTime2 = 0U;
  c1_info[45].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[45].name = "eml_all_or_any";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[45].fileLength = 3914U;
  c1_info[45].fileTime1 = 1271383994U;
  c1_info[45].fileTime2 = 0U;
  c1_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[46].name = "isequal";
  c1_info[46].dominantType = "double";
  c1_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[46].fileLength = 180U;
  c1_info[46].fileTime1 = 1226552070U;
  c1_info[46].fileTime2 = 0U;
  c1_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[47].name = "eml_isequal_core";
  c1_info[47].dominantType = "double";
  c1_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[47].fileLength = 4192U;
  c1_info[47].fileTime1 = 1258039010U;
  c1_info[47].fileTime2 = 0U;
  c1_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[48].name = "ge";
  c1_info[48].dominantType = "double";
  c1_info[48].resolved = "[B]ge";
  c1_info[48].fileLength = 0U;
  c1_info[48].fileTime1 = 0U;
  c1_info[48].fileTime2 = 0U;
  c1_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[49].name = "isnumeric";
  c1_info[49].dominantType = "logical";
  c1_info[49].resolved = "[B]isnumeric";
  c1_info[49].fileLength = 0U;
  c1_info[49].fileTime1 = 0U;
  c1_info[49].fileTime2 = 0U;
  c1_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c1_info[50].name = "ndims";
  c1_info[50].dominantType = "logical";
  c1_info[50].resolved = "[B]ndims";
  c1_info[50].fileLength = 0U;
  c1_info[50].fileTime1 = 0U;
  c1_info[50].fileTime2 = 0U;
  c1_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[51].name = "eml_const_nonsingleton_dim";
  c1_info[51].dominantType = "logical";
  c1_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[51].fileLength = 1473U;
  c1_info[51].fileTime1 = 1240240402U;
  c1_info[51].fileTime2 = 0U;
  c1_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[52].name = "isempty";
  c1_info[52].dominantType = "logical";
  c1_info[52].resolved = "[B]isempty";
  c1_info[52].fileLength = 0U;
  c1_info[52].fileTime1 = 0U;
  c1_info[52].fileTime2 = 0U;
  c1_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[53].name = "isnan";
  c1_info[53].dominantType = "logical";
  c1_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[53].fileLength = 541U;
  c1_info[53].fileTime1 = 1271383988U;
  c1_info[53].fileTime2 = 0U;
  c1_info[54].context = "[E]D:/Learn/MatlabProgram/Fanuc/AdjointInv.m";
  c1_info[54].name = "transpose";
  c1_info[54].dominantType = "double";
  c1_info[54].resolved = "[B]transpose";
  c1_info[54].fileLength = 0U;
  c1_info[54].fileTime1 = 0U;
  c1_info[54].fileTime2 = 0U;
  c1_info[55].context = "[E]D:/Learn/MatlabProgram/Fanuc/AdjointInv.m";
  c1_info[55].name = "skew";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/skew.m";
  c1_info[55].fileLength = 336U;
  c1_info[55].fileTime1 = 1368548988U;
  c1_info[55].fileTime2 = 0U;
  c1_info[56].context = "[E]D:/Learn/MatlabProgram/Fanuc/skew.m";
  c1_info[56].name = "length";
  c1_info[56].dominantType = "double";
  c1_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[56].fileLength = 326U;
  c1_info[56].fileTime1 = 1226552074U;
  c1_info[56].fileTime2 = 0U;
  c1_info[57].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[57].name = "eml_xgemm";
  c1_info[57].dominantType = "int32";
  c1_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[57].fileLength = 3184U;
  c1_info[57].fileTime1 = 1209309252U;
  c1_info[57].fileTime2 = 0U;
  c1_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c1_info[58].name = "min";
  c1_info[58].dominantType = "double";
  c1_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[58].fileLength = 362U;
  c1_info[58].fileTime1 = 1245080764U;
  c1_info[58].fileTime2 = 0U;
  c1_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[59].name = "nargout";
  c1_info[59].dominantType = "";
  c1_info[59].resolved = "[B]nargout";
  c1_info[59].fileLength = 0U;
  c1_info[59].fileTime1 = 0U;
  c1_info[59].fileTime2 = 0U;
  c1_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[60].name = "eml_min_or_max";
  c1_info[60].dominantType = "char";
  c1_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[60].fileLength = 9967U;
  c1_info[60].fileTime1 = 1261926670U;
  c1_info[60].fileTime2 = 0U;
  c1_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[61].name = "eml_scalexp_alloc";
  c1_info[61].dominantType = "double";
  c1_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[61].fileLength = 932U;
  c1_info[61].fileTime1 = 1261926670U;
  c1_info[61].fileTime2 = 0U;
  c1_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[62].name = "eml_refblas_xgemm";
  c1_info[62].dominantType = "int32";
  c1_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[62].fileLength = 5748U;
  c1_info[62].fileTime1 = 1228068672U;
  c1_info[62].fileTime2 = 0U;
  c1_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[63].name = "eml_index_minus";
  c1_info[63].dominantType = "int32";
  c1_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[63].fileLength = 277U;
  c1_info[63].fileTime1 = 1192445184U;
  c1_info[63].fileTime2 = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[100])
{
  c1_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[64].name = "eml_index_times";
  c1_info[64].dominantType = "int32";
  c1_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[64].fileLength = 280U;
  c1_info[64].fileTime1 = 1192445186U;
  c1_info[64].fileTime2 = 0U;
  c1_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[65].name = "eml_index_plus";
  c1_info[65].dominantType = "int32";
  c1_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[65].fileLength = 272U;
  c1_info[65].fileTime1 = 1192445184U;
  c1_info[65].fileTime2 = 0U;
  c1_info[66].context = "";
  c1_info[66].name = "mldivide";
  c1_info[66].dominantType = "double";
  c1_info[66].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[66].fileLength = 494U;
  c1_info[66].fileTime1 = 1277726622U;
  c1_info[66].fileTime2 = 0U;
  c1_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[67].name = "eml_lusolve";
  c1_info[67].dominantType = "double";
  c1_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c1_info[67].fileLength = 5239U;
  c1_info[67].fileTime1 = 1264408552U;
  c1_info[67].fileTime2 = 0U;
  c1_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[68].name = "eml_xgetrf";
  c1_info[68].dominantType = "int32";
  c1_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[68].fileLength = 204U;
  c1_info[68].fileTime1 = 1271383994U;
  c1_info[68].fileTime2 = 0U;
  c1_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[69].name = "eml_lapack_xgetrf";
  c1_info[69].dominantType = "int32";
  c1_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[69].fileLength = 211U;
  c1_info[69].fileTime1 = 1271383994U;
  c1_info[69].fileTime2 = 0U;
  c1_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[70].name = "eml_matlab_zgetrf";
  c1_info[70].dominantType = "int32";
  c1_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[70].fileLength = 2193U;
  c1_info[70].fileTime1 = 1271383998U;
  c1_info[70].fileTime2 = 0U;
  c1_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[71].name = "realmin";
  c1_info[71].dominantType = "char";
  c1_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[71].fileLength = 749U;
  c1_info[71].fileTime1 = 1226552078U;
  c1_info[71].fileTime2 = 0U;
  c1_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[72].name = "mpower";
  c1_info[72].dominantType = "double";
  c1_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[72].fileLength = 3710U;
  c1_info[72].fileTime1 = 1238412688U;
  c1_info[72].fileTime2 = 0U;
  c1_info[73].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[73].name = "power";
  c1_info[73].dominantType = "double";
  c1_info[73].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[73].fileLength = 5380U;
  c1_info[73].fileTime1 = 1228068698U;
  c1_info[73].fileTime2 = 0U;
  c1_info[74].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[74].name = "eml_scalar_floor";
  c1_info[74].dominantType = "double";
  c1_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[74].fileLength = 260U;
  c1_info[74].fileTime1 = 1209309190U;
  c1_info[74].fileTime2 = 0U;
  c1_info[75].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[75].name = "eml_error";
  c1_info[75].dominantType = "char";
  c1_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[75].fileLength = 315U;
  c1_info[75].fileTime1 = 1213905144U;
  c1_info[75].fileTime2 = 0U;
  c1_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[76].name = "eps";
  c1_info[76].dominantType = "char";
  c1_info[76].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[76].fileLength = 1331U;
  c1_info[76].fileTime1 = 1246588112U;
  c1_info[76].fileTime2 = 0U;
  c1_info[77].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[77].name = "eml_is_float_class";
  c1_info[77].dominantType = "char";
  c1_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[77].fileLength = 226U;
  c1_info[77].fileTime1 = 1197825240U;
  c1_info[77].fileTime2 = 0U;
  c1_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[78].name = "colon";
  c1_info[78].dominantType = "int32";
  c1_info[78].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[78].fileLength = 8633U;
  c1_info[78].fileTime1 = 1273822662U;
  c1_info[78].fileTime2 = 0U;
  c1_info[79].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[79].name = "floor";
  c1_info[79].dominantType = "double";
  c1_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[79].fileLength = 332U;
  c1_info[79].fileTime1 = 1203422822U;
  c1_info[79].fileTime2 = 0U;
  c1_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[80].name = "intmin";
  c1_info[80].dominantType = "char";
  c1_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[80].fileLength = 1505U;
  c1_info[80].fileTime1 = 1192445128U;
  c1_info[80].fileTime2 = 0U;
  c1_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c1_info[81].name = "mrdivide";
  c1_info[81].dominantType = "double";
  c1_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[81].fileLength = 432U;
  c1_info[81].fileTime1 = 1277726622U;
  c1_info[81].fileTime2 = 0U;
  c1_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[82].name = "rdivide";
  c1_info[82].dominantType = "double";
  c1_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[82].fileLength = 403U;
  c1_info[82].fileTime1 = 1245080820U;
  c1_info[82].fileTime2 = 0U;
  c1_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[83].name = "eml_div";
  c1_info[83].dominantType = "double";
  c1_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[83].fileLength = 4918U;
  c1_info[83].fileTime1 = 1267038210U;
  c1_info[83].fileTime2 = 0U;
  c1_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[84].name = "eml_ixamax";
  c1_info[84].dominantType = "int32";
  c1_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[84].fileLength = 731U;
  c1_info[84].fileTime1 = 1209309244U;
  c1_info[84].fileTime2 = 0U;
  c1_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[85].name = "eml_refblas_ixamax";
  c1_info[85].dominantType = "int32";
  c1_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[85].fileLength = 740U;
  c1_info[85].fileTime1 = 1192445266U;
  c1_info[85].fileTime2 = 0U;
  c1_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[86].name = "eml_xcabs1";
  c1_info[86].dominantType = "double";
  c1_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[86].fileLength = 419U;
  c1_info[86].fileTime1 = 1209309246U;
  c1_info[86].fileTime2 = 0U;
  c1_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[87].name = "real";
  c1_info[87].dominantType = "double";
  c1_info[87].resolved = "[B]real";
  c1_info[87].fileLength = 0U;
  c1_info[87].fileTime1 = 0U;
  c1_info[87].fileTime2 = 0U;
  c1_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[88].name = "abs";
  c1_info[88].dominantType = "double";
  c1_info[88].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[88].fileLength = 566U;
  c1_info[88].fileTime1 = 1221245532U;
  c1_info[88].fileTime2 = 0U;
  c1_info[89].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[89].name = "eml_scalar_abs";
  c1_info[89].dominantType = "double";
  c1_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[89].fileLength = 461U;
  c1_info[89].fileTime1 = 1203422760U;
  c1_info[89].fileTime2 = 0U;
  c1_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[90].name = "imag";
  c1_info[90].dominantType = "double";
  c1_info[90].resolved = "[B]imag";
  c1_info[90].fileLength = 0U;
  c1_info[90].fileTime1 = 0U;
  c1_info[90].fileTime2 = 0U;
  c1_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[91].name = "eml_xswap";
  c1_info[91].dominantType = "int32";
  c1_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[91].fileLength = 1330U;
  c1_info[91].fileTime1 = 1209309260U;
  c1_info[91].fileTime2 = 0U;
  c1_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[92].name = "eml_refblas_xswap";
  c1_info[92].dominantType = "int32";
  c1_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[92].fileLength = 905U;
  c1_info[92].fileTime1 = 1238412670U;
  c1_info[92].fileTime2 = 0U;
  c1_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[93].name = "eml_xgeru";
  c1_info[93].dominantType = "int32";
  c1_info[93].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[93].fileLength = 2462U;
  c1_info[93].fileTime1 = 1209309256U;
  c1_info[93].fileTime2 = 0U;
  c1_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[94].name = "eml_xger";
  c1_info[94].dominantType = "int32";
  c1_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[94].fileLength = 2168U;
  c1_info[94].fileTime1 = 1209309254U;
  c1_info[94].fileTime2 = 0U;
  c1_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[95].name = "eml_refblas_xger";
  c1_info[95].dominantType = "int32";
  c1_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[95].fileLength = 411U;
  c1_info[95].fileTime1 = 1211194448U;
  c1_info[95].fileTime2 = 0U;
  c1_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[96].name = "eml_refblas_xgerx";
  c1_info[96].dominantType = "int32";
  c1_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[96].fileLength = 2231U;
  c1_info[96].fileTime1 = 1238412668U;
  c1_info[96].fileTime2 = 0U;
  c1_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c1_info[97].name = "eml_warning";
  c1_info[97].dominantType = "char";
  c1_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[97].fileLength = 262U;
  c1_info[97].fileTime1 = 1236232078U;
  c1_info[97].fileTime2 = 0U;
  c1_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[98].name = "eml_xtrsm";
  c1_info[98].dominantType = "int32";
  c1_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[98].fileLength = 2383U;
  c1_info[98].fileTime1 = 1209309262U;
  c1_info[98].fileTime2 = 0U;
  c1_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[99].name = "eml_refblas_xtrsm";
  c1_info[99].dominantType = "int32";
  c1_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[99].fileLength = 13101U;
  c1_info[99].fileTime1 = 1252487206U;
  c1_info[99].fileTime2 = 0U;
}

static const mxArray *c1_i_sf_marshall(void *chartInstanceVoid, void *c1_u)
{
  const mxArray *c1_y = NULL;
  boolean_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)chartInstanceVoid;
  c1_y = NULL;
  c1_b_u = *((boolean_T *)c1_u);
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_y, c1_b_y);
  return c1_y;
}

static void c1_emlrt_marshallIn(SFc1_DynVerifyInstanceStruct *chartInstance,
  const mxArray *c1_Omega, const char_T *c1_name, real_T
  c1_y[6])
{
  real_T c1_dv5[6];
  int32_T c1_i160;
  sf_mex_import(c1_name, sf_mex_dup(c1_Omega), c1_dv5, 1, 0, 0U, 1, 0U, 1, 6);
  for (c1_i160 = 0; c1_i160 < 6; c1_i160 = c1_i160 + 1) {
    c1_y[c1_i160] = c1_dv5[c1_i160];
  }

  sf_mex_destroy(&c1_Omega);
}

static uint8_T c1_b_emlrt_marshallIn(SFc1_DynVerifyInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_DynVerify, const
  char_T *c1_name)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_name, sf_mex_dup(c1_b_is_active_c1_DynVerify), &c1_u0, 1, 3,
                0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_b_is_active_c1_DynVerify);
  return c1_y;
}

static void init_dsm_address_info(SFc1_DynVerifyInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_DynVerify_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3264936554U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4204476236U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2895192816U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2335952397U);
}

mxArray *sf_c1_DynVerify_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3682126905U);
    pr[1] = (double)(4253938541U);
    pr[2] = (double)(3292813776U);
    pr[3] = (double)(3893654209U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c1_DynVerify(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Omega\",},{M[8],M[0],T\"is_active_c1_DynVerify\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DynVerify_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DynVerifyInstanceStruct *chartInstance;
    chartInstance = (SFc1_DynVerifyInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_DynVerifyMachineNumber_,
          1,
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
          init_script_number_translation(_DynVerifyMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_DynVerifyMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_DynVerifyMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"Omega");
          _SFD_SET_DATA_PROPS(1,1,1,0,"EndVel");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Theta");
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

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,212);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"fwd_kin",0,-1,3253);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"body_Jacobian",0,-1,3708);
        _SFD_CV_INIT_SCRIPT(2,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"AdjointInv",0,-1,276);
        _SFD_CV_INIT_SCRIPT_IF(2,0,38,63,-1,117);
        _SFD_CV_INIT_SCRIPT(3,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"skew",0,-1,336);
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
            1.0,0,0,(MexFcnForType)c1_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshall);
        }

        {
          real_T (*c1_Omega)[6];
          real_T (*c1_EndVel)[3];
          real_T (*c1_Theta)[6];
          c1_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c1_EndVel = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          c1_Omega = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_Omega);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_EndVel);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_Theta);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c1_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_DynVerifyMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_DynVerify(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DynVerifyInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c1_DynVerify((SFc1_DynVerifyInstanceStruct*)
    chartInstanceVar);
  initialize_c1_DynVerify((SFc1_DynVerifyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_DynVerify(void *chartInstanceVar)
{
  enable_c1_DynVerify((SFc1_DynVerifyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_DynVerify(void *chartInstanceVar)
{
  disable_c1_DynVerify((SFc1_DynVerifyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_DynVerify(void *chartInstanceVar)
{
  sf_c1_DynVerify((SFc1_DynVerifyInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c1_DynVerify(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_DynVerify((SFc1_DynVerifyInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c1_DynVerify();/* state var info */
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

static void sf_internal_set_sim_state_c1_DynVerify(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DynVerify();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_DynVerify((SFc1_DynVerifyInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c1_DynVerify(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_DynVerify(S);
}

static void sf_opaque_set_sim_state_c1_DynVerify(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_DynVerify(S, st);
}

static void sf_opaque_terminate_c1_DynVerify(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DynVerifyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_DynVerify((SFc1_DynVerifyInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c1_DynVerify((SFc1_DynVerifyInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DynVerify(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DynVerify((SFc1_DynVerifyInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_DynVerify(SimStruct *S)
{
  /* Actual parameters from chart:
     L
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"DynVerify","DynVerify",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DynVerify","DynVerify",1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DynVerify","DynVerify",
      1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DynVerify","DynVerify",1,2);
      sf_mark_chart_reusable_outputs(S,"DynVerify","DynVerify",1,1);
    }

    sf_set_rtw_dwork_info(S,"DynVerify","DynVerify",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2677365991U));
  ssSetChecksum1(S,(3963650690U));
  ssSetChecksum2(S,(1320293430U));
  ssSetChecksum3(S,(2296717905U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_DynVerify(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DynVerify", "DynVerify",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_DynVerify(SimStruct *S)
{
  SFc1_DynVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc1_DynVerifyInstanceStruct *)malloc(sizeof
    (SFc1_DynVerifyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_DynVerifyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_DynVerify;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_DynVerify;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_DynVerify;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_DynVerify;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_DynVerify;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_DynVerify;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_DynVerify;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_DynVerify;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DynVerify;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DynVerify;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_DynVerify;
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

void c1_DynVerify_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DynVerify(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DynVerify(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DynVerify(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DynVerify_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
