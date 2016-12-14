/* Include files */

#include "blascompat32.h"
#include "DynJointVerify_sfun.h"
#include "c6_DynJointVerify.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DynJointVerify_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c6_debug_family_names[6] = { "gd", "nargin", "nargout",
  "Theta", "L", "EndPos" };

static const char *c6_b_debug_family_names[68] = { "A1", "A2", "A3", "A4", "A5",
  "A6", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t2", "t3", "t4",
  "t5", "t6", "t7", "t8", "t9", "t10", "t11", "t12", "t13", "t14", "t23", "t15",
  "t16", "t17", "t18", "t19", "t20", "t21", "t22", "t24", "t25", "t26", "t27",
  "t34", "t28", "t29", "t30", "t31", "t32", "t36", "t33", "t35", "t37", "t38",
  "t39", "t40", "t41", "t42", "t43", "t44", "t45", "t47", "t46", "t48", "t49",
  "nargin", "nargout", "in1", "in2", "gst" };

/* Function Declarations */
static void initialize_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance);
static void initialize_params_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance);
static void enable_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance);
static void disable_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance);
static void set_sim_state_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c6_st);
static void finalize_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance);
static void sf_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static void c6_fwd_kin(SFc6_DynJointVerifyInstanceStruct *chartInstance, real_T
  c6_in1[9], real_T c6_in2[6], real_T c6_gst[16]);
static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_c_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_d_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_e_sf_marshall(void *chartInstanceVoid, void *c6_u);
static const mxArray *c6_f_sf_marshall(void *chartInstanceVoid, void *c6_u);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[39]);
static const mxArray *c6_g_sf_marshall(void *chartInstanceVoid, void *c6_u);
static void c6_emlrt_marshallIn(SFc6_DynJointVerifyInstanceStruct *chartInstance,
  const mxArray *c6_EndPos, const char_T *c6_name, real_T c6_y[3]);
static uint8_T c6_b_emlrt_marshallIn(SFc6_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_DynJointVerify, const char_T *
  c6_name);
static void init_dsm_address_info(SFc6_DynJointVerifyInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c6_is_active_c6_DynJointVerify = 0U;
}

static void initialize_params_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance)
{
  real_T c6_dv0[9];
  int32_T c6_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c6_dv0, 0, 0,
                0U, 1, 0U, 2, 1, 9);
  for (c6_i0 = 0; c6_i0 < 9; c6_i0 = c6_i0 + 1) {
    chartInstance->c6_L[c6_i0] = c6_dv0[c6_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance)
{
  const mxArray *c6_st = NULL;
  const mxArray *c6_y = NULL;
  int32_T c6_i1;
  real_T c6_hoistedGlobal[3];
  int32_T c6_i2;
  real_T c6_u[3];
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T (*c6_EndPos)[3];
  c6_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2));
  for (c6_i1 = 0; c6_i1 < 3; c6_i1 = c6_i1 + 1) {
    c6_hoistedGlobal[c6_i1] = (*c6_EndPos)[c6_i1];
  }

  for (c6_i2 = 0; c6_i2 < 3; c6_i2 = c6_i2 + 1) {
    c6_u[c6_i2] = c6_hoistedGlobal[c6_i2];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = chartInstance->c6_is_active_c6_DynJointVerify;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y);
  return c6_st;
}

static void set_sim_state_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv1[3];
  int32_T c6_i3;
  real_T (*c6_EndPos)[3];
  c6_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
                      "EndPos", c6_dv1);
  for (c6_i3 = 0; c6_i3 < 3; c6_i3 = c6_i3 + 1) {
    (*c6_EndPos)[c6_i3] = c6_dv1[c6_i3];
  }

  chartInstance->c6_is_active_c6_DynJointVerify = c6_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_DynJointVerify");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_DynJointVerify(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

static void sf_c6_DynJointVerify(SFc6_DynJointVerifyInstanceStruct
  *chartInstance)
{
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_previousEvent;
  int32_T c6_i7;
  real_T c6_hoistedGlobal[6];
  int32_T c6_i8;
  real_T c6_b_hoistedGlobal[9];
  int32_T c6_i9;
  real_T c6_Theta[6];
  int32_T c6_i10;
  real_T c6_b_L[9];
  uint32_T c6_debug_family_var_map[6];
  real_T c6_gd[16];
  real_T c6_nargin = 2.0;
  real_T c6_nargout = 1.0;
  real_T c6_EndPos[3];
  int32_T c6_i11;
  real_T c6_c_L[9];
  int32_T c6_i12;
  real_T c6_b_Theta[6];
  real_T c6_dv2[16];
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  real_T (*c6_b_EndPos)[3];
  real_T (*c6_c_Theta)[6];
  c6_b_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c6_c_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5);
  for (c6_i4 = 0; c6_i4 < 6; c6_i4 = c6_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c6_c_Theta)[c6_i4], 0U);
  }

  for (c6_i5 = 0; c6_i5 < 3; c6_i5 = c6_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c6_b_EndPos)[c6_i5], 1U);
  }

  for (c6_i6 = 0; c6_i6 < 9; c6_i6 = c6_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c6_L[c6_i6], 2U);
  }

  c6_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5);
  for (c6_i7 = 0; c6_i7 < 6; c6_i7 = c6_i7 + 1) {
    c6_hoistedGlobal[c6_i7] = (*c6_c_Theta)[c6_i7];
  }

  for (c6_i8 = 0; c6_i8 < 9; c6_i8 = c6_i8 + 1) {
    c6_b_hoistedGlobal[c6_i8] = chartInstance->c6_L[c6_i8];
  }

  for (c6_i9 = 0; c6_i9 < 6; c6_i9 = c6_i9 + 1) {
    c6_Theta[c6_i9] = c6_hoistedGlobal[c6_i9];
  }

  for (c6_i10 = 0; c6_i10 < 9; c6_i10 = c6_i10 + 1) {
    c6_b_L[c6_i10] = c6_b_hoistedGlobal[c6_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c6_gd, c6_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c6_nargin, c6_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c6_nargout, c6_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c6_Theta, c6_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c6_b_L, c6_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c6_EndPos, c6_sf_marshall, 5U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c6_i11 = 0; c6_i11 < 9; c6_i11 = c6_i11 + 1) {
    c6_c_L[c6_i11] = c6_b_L[c6_i11];
  }

  for (c6_i12 = 0; c6_i12 < 6; c6_i12 = c6_i12 + 1) {
    c6_b_Theta[c6_i12] = c6_Theta[c6_i12];
  }

  c6_fwd_kin(chartInstance, c6_c_L, c6_b_Theta, c6_dv2);
  for (c6_i13 = 0; c6_i13 < 16; c6_i13 = c6_i13 + 1) {
    c6_gd[c6_i13] = c6_dv2[c6_i13];
  }

  _SFD_EML_CALL(0, 4);
  for (c6_i14 = 0; c6_i14 < 3; c6_i14 = c6_i14 + 1) {
    c6_EndPos[c6_i14] = c6_gd[c6_i14 + 12];
  }

  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  for (c6_i15 = 0; c6_i15 < 3; c6_i15 = c6_i15 + 1) {
    (*c6_b_EndPos)[c6_i15] = c6_EndPos[c6_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5);
  _sfEvent_ = c6_previousEvent;
  sf_debug_check_for_state_inconsistency(_DynJointVerifyMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c6_DynJointVerify
  (SFc6_DynJointVerifyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/fwd_kin.m"));
}

static void c6_fwd_kin(SFc6_DynJointVerifyInstanceStruct *chartInstance, real_T
  c6_in1[9], real_T c6_in2[6], real_T c6_gst[16])
{
  uint32_T c6_debug_family_var_map[68];
  real_T c6_A1;
  real_T c6_A2;
  real_T c6_A3;
  real_T c6_A4;
  real_T c6_A5;
  real_T c6_A6;
  real_T c6_L1;
  real_T c6_L2;
  real_T c6_L3;
  real_T c6_L4;
  real_T c6_L5;
  real_T c6_L6;
  real_T c6_L7;
  real_T c6_L8;
  real_T c6_L9;
  real_T c6_t2;
  real_T c6_t3;
  real_T c6_t4;
  real_T c6_t5;
  real_T c6_t6;
  real_T c6_t7;
  real_T c6_t8;
  real_T c6_t9;
  real_T c6_t10;
  real_T c6_t11;
  real_T c6_t12;
  real_T c6_t13;
  real_T c6_t14;
  real_T c6_t23;
  real_T c6_t15;
  real_T c6_t16;
  real_T c6_t17;
  real_T c6_t18;
  real_T c6_t19;
  real_T c6_t20;
  real_T c6_t21;
  real_T c6_t22;
  real_T c6_t24;
  real_T c6_t25;
  real_T c6_t26;
  real_T c6_t27;
  real_T c6_t34;
  real_T c6_t28;
  real_T c6_t29;
  real_T c6_t30;
  real_T c6_t31;
  real_T c6_t32;
  real_T c6_t36;
  real_T c6_t33;
  real_T c6_t35;
  real_T c6_t37;
  real_T c6_t38;
  real_T c6_t39;
  real_T c6_t40;
  real_T c6_t41;
  real_T c6_t42;
  real_T c6_t43;
  real_T c6_t44;
  real_T c6_t45;
  real_T c6_t47;
  real_T c6_t46;
  real_T c6_t48;
  real_T c6_t49;
  real_T c6_nargin = 2.0;
  real_T c6_nargout = 1.0;
  real_T c6_x;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  real_T c6_f_x;
  real_T c6_g_x;
  real_T c6_h_x;
  real_T c6_i_x;
  real_T c6_j_x;
  real_T c6_k_x;
  real_T c6_l_x;
  real_T c6_m_x;
  real_T c6_n_x;
  real_T c6_o_x;
  real_T c6_p_x;
  real_T c6_q_x;
  real_T c6_r_x;
  real_T c6_s_x;
  real_T c6_t_x;
  real_T c6_u_x;
  real_T c6_v_x;
  real_T c6_w_x;
  real_T c6_x_x;
  real_T c6_y_x[16];
  int32_T c6_k;
  int32_T c6_b_k;
  sf_debug_symbol_scope_push_eml(0U, 68U, 68U, c6_b_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_A1, c6_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c6_A2, c6_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c6_A3, c6_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c6_A4, c6_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c6_A5, c6_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c6_A6, c6_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c6_L1, c6_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c6_L2, c6_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c6_L3, c6_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c6_L4, c6_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c6_L5, c6_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c6_L6, c6_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c6_L7, c6_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c6_L8, c6_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c6_L9, c6_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c6_t2, c6_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c6_t3, c6_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c6_t4, c6_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c6_t5, c6_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c6_t6, c6_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c6_t7, c6_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c6_t8, c6_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c6_t9, c6_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c6_t10, c6_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c6_t11, c6_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c6_t12, c6_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c6_t13, c6_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c6_t14, c6_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c6_t23, c6_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c6_t15, c6_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c6_t16, c6_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c6_t17, c6_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c6_t18, c6_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c6_t19, c6_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c6_t20, c6_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c6_t21, c6_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c6_t22, c6_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c6_t24, c6_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c6_t25, c6_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c6_t26, c6_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c6_t27, c6_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c6_t34, c6_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c6_t28, c6_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c6_t29, c6_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c6_t30, c6_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c6_t31, c6_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c6_t32, c6_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c6_t36, c6_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c6_t33, c6_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c6_t35, c6_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c6_t37, c6_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c6_t38, c6_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c6_t39, c6_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c6_t40, c6_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c6_t41, c6_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c6_t42, c6_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c6_t43, c6_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c6_t44, c6_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c6_t45, c6_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c6_t47, c6_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c6_t46, c6_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c6_t48, c6_d_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c6_t49, c6_d_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c6_nargin, c6_d_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c6_nargout, c6_d_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c6_in1, c6_b_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(c6_in2, c6_f_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(c6_gst, c6_e_sf_marshall, 67U);
  CV_SCRIPT_FCN(0, 0);

  /* FWD_KIN */
  /*     GST = FWD_KIN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     24-Apr-2013 12:49:18 */
  _SFD_SCRIPT_CALL(0, 8);
  c6_A1 = c6_in2[0];
  _SFD_SCRIPT_CALL(0, 9);
  c6_A2 = c6_in2[1];
  _SFD_SCRIPT_CALL(0, 10);
  c6_A3 = c6_in2[2];
  _SFD_SCRIPT_CALL(0, 11);
  c6_A4 = c6_in2[3];
  _SFD_SCRIPT_CALL(0, 12);
  c6_A5 = c6_in2[4];
  _SFD_SCRIPT_CALL(0, 13);
  c6_A6 = c6_in2[5];
  _SFD_SCRIPT_CALL(0, 14);
  c6_L1 = c6_in1[0];
  _SFD_SCRIPT_CALL(0, 15);
  c6_L2 = c6_in1[1];
  _SFD_SCRIPT_CALL(0, 16);
  c6_L3 = c6_in1[2];
  _SFD_SCRIPT_CALL(0, 17);
  c6_L4 = c6_in1[3];
  _SFD_SCRIPT_CALL(0, 18);
  c6_L5 = c6_in1[4];
  _SFD_SCRIPT_CALL(0, 19);
  c6_L6 = c6_in1[5];
  _SFD_SCRIPT_CALL(0, 20);
  c6_L7 = c6_in1[6];
  _SFD_SCRIPT_CALL(0, 21);
  c6_L8 = c6_in1[7];
  _SFD_SCRIPT_CALL(0, 22);
  c6_L9 = c6_in1[8];
  _SFD_SCRIPT_CALL(0, 23);
  c6_x = c6_A1;
  c6_t2 = c6_x;
  c6_b_x = c6_t2;
  c6_t2 = c6_b_x;
  c6_t2 = muDoubleScalarCos(c6_t2);
  _SFD_SCRIPT_CALL(0, 24);
  c6_c_x = c6_A2;
  c6_t3 = c6_c_x;
  c6_d_x = c6_t3;
  c6_t3 = c6_d_x;
  c6_t3 = muDoubleScalarCos(c6_t3);
  _SFD_SCRIPT_CALL(0, 25);
  c6_e_x = c6_A3;
  c6_t4 = c6_e_x;
  c6_f_x = c6_t4;
  c6_t4 = c6_f_x;
  c6_t4 = muDoubleScalarSin(c6_t4);
  _SFD_SCRIPT_CALL(0, 26);
  c6_g_x = c6_A3;
  c6_t5 = c6_g_x;
  c6_h_x = c6_t5;
  c6_t5 = c6_h_x;
  c6_t5 = muDoubleScalarCos(c6_t5);
  _SFD_SCRIPT_CALL(0, 27);
  c6_i_x = c6_A2;
  c6_t6 = c6_i_x;
  c6_j_x = c6_t6;
  c6_t6 = c6_j_x;
  c6_t6 = muDoubleScalarSin(c6_t6);
  _SFD_SCRIPT_CALL(0, 28);
  c6_k_x = c6_A4;
  c6_t7 = c6_k_x;
  c6_l_x = c6_t7;
  c6_t7 = c6_l_x;
  c6_t7 = muDoubleScalarSin(c6_t7);
  _SFD_SCRIPT_CALL(0, 29);
  c6_t8 = c6_t2 * c6_t3 * c6_t4;
  _SFD_SCRIPT_CALL(0, 30);
  c6_t9 = c6_t2 * c6_t5 * c6_t6;
  _SFD_SCRIPT_CALL(0, 31);
  c6_t10 = c6_t8 + c6_t9;
  _SFD_SCRIPT_CALL(0, 32);
  c6_m_x = c6_A4;
  c6_t11 = c6_m_x;
  c6_n_x = c6_t11;
  c6_t11 = c6_n_x;
  c6_t11 = muDoubleScalarCos(c6_t11);
  _SFD_SCRIPT_CALL(0, 33);
  c6_o_x = c6_A1;
  c6_t12 = c6_o_x;
  c6_p_x = c6_t12;
  c6_t12 = c6_p_x;
  c6_t12 = muDoubleScalarSin(c6_t12);
  _SFD_SCRIPT_CALL(0, 34);
  c6_q_x = c6_A5;
  c6_t13 = c6_q_x;
  c6_r_x = c6_t13;
  c6_t13 = c6_r_x;
  c6_t13 = muDoubleScalarSin(c6_t13);
  _SFD_SCRIPT_CALL(0, 35);
  c6_t14 = c6_t2 * c6_t3 * c6_t5;
  _SFD_SCRIPT_CALL(0, 36);
  c6_t23 = c6_t2 * c6_t4 * c6_t6;
  _SFD_SCRIPT_CALL(0, 37);
  c6_t15 = c6_t14 - c6_t23;
  _SFD_SCRIPT_CALL(0, 38);
  c6_s_x = c6_A5;
  c6_t16 = c6_s_x;
  c6_t_x = c6_t16;
  c6_t16 = c6_t_x;
  c6_t16 = muDoubleScalarCos(c6_t16);
  _SFD_SCRIPT_CALL(0, 39);
  c6_t17 = c6_t10 * c6_t11;
  _SFD_SCRIPT_CALL(0, 40);
  c6_t18 = c6_t12 * c6_t7;
  _SFD_SCRIPT_CALL(0, 41);
  c6_t19 = c6_t17 + c6_t18;
  _SFD_SCRIPT_CALL(0, 42);
  c6_u_x = c6_A6;
  c6_t20 = c6_u_x;
  c6_v_x = c6_t20;
  c6_t20 = c6_v_x;
  c6_t20 = muDoubleScalarSin(c6_t20);
  _SFD_SCRIPT_CALL(0, 43);
  c6_t21 = c6_t11 * c6_t12;
  _SFD_SCRIPT_CALL(0, 44);
  c6_w_x = c6_A6;
  c6_t22 = c6_w_x;
  c6_x_x = c6_t22;
  c6_t22 = c6_x_x;
  c6_t22 = muDoubleScalarCos(c6_t22);
  _SFD_SCRIPT_CALL(0, 45);
  c6_t24 = c6_t13 * c6_t15;
  _SFD_SCRIPT_CALL(0, 46);
  c6_t25 = c6_t16 * c6_t19;
  _SFD_SCRIPT_CALL(0, 47);
  c6_t26 = c6_t24 + c6_t25;
  _SFD_SCRIPT_CALL(0, 48);
  c6_t27 = c6_t12 * c6_t3 * c6_t5;
  _SFD_SCRIPT_CALL(0, 49);
  c6_t34 = c6_t12 * c6_t4 * c6_t6;
  _SFD_SCRIPT_CALL(0, 50);
  c6_t28 = c6_t27 - c6_t34;
  _SFD_SCRIPT_CALL(0, 51);
  c6_t29 = c6_t12 * c6_t3 * c6_t4;
  _SFD_SCRIPT_CALL(0, 52);
  c6_t30 = c6_t12 * c6_t5 * c6_t6;
  _SFD_SCRIPT_CALL(0, 53);
  c6_t31 = c6_t29 + c6_t30;
  _SFD_SCRIPT_CALL(0, 54);
  c6_t32 = c6_t11 * c6_t31;
  _SFD_SCRIPT_CALL(0, 55);
  c6_t36 = c6_t2 * c6_t7;
  _SFD_SCRIPT_CALL(0, 56);
  c6_t33 = c6_t32 - c6_t36;
  _SFD_SCRIPT_CALL(0, 57);
  c6_t35 = c6_t13 * c6_t28;
  _SFD_SCRIPT_CALL(0, 58);
  c6_t37 = c6_t16 * c6_t33;
  _SFD_SCRIPT_CALL(0, 59);
  c6_t38 = c6_t35 + c6_t37;
  _SFD_SCRIPT_CALL(0, 60);
  c6_t39 = c6_t31 * c6_t7;
  _SFD_SCRIPT_CALL(0, 61);
  c6_t40 = c6_t11 * c6_t2;
  _SFD_SCRIPT_CALL(0, 62);
  c6_t41 = c6_t39 + c6_t40;
  _SFD_SCRIPT_CALL(0, 63);
  c6_t42 = c6_t3 * c6_t4;
  _SFD_SCRIPT_CALL(0, 64);
  c6_t43 = c6_t5 * c6_t6;
  _SFD_SCRIPT_CALL(0, 65);
  c6_t44 = c6_t42 + c6_t43;
  _SFD_SCRIPT_CALL(0, 66);
  c6_t45 = c6_t3 * c6_t5;
  _SFD_SCRIPT_CALL(0, 67);
  c6_t47 = c6_t4 * c6_t6;
  _SFD_SCRIPT_CALL(0, 68);
  c6_t46 = c6_t45 - c6_t47;
  _SFD_SCRIPT_CALL(0, 69);
  c6_t48 = c6_t13 * c6_t44;
  _SFD_SCRIPT_CALL(0, 70);
  c6_t49 = c6_t48 - c6_t11 * c6_t16 * c6_t46;
  _SFD_SCRIPT_CALL(0, 71);
  c6_y_x[0] = c6_t15 * c6_t16 - c6_t13 * c6_t19;
  c6_y_x[1] = c6_t16 * c6_t28 - c6_t13 * c6_t33;
  c6_y_x[2] = (-c6_t16) * c6_t44 - c6_t11 * c6_t13 * c6_t46;
  c6_y_x[3] = 0.0;
  c6_y_x[4] = c6_t20 * c6_t26 - c6_t22 * (c6_t21 - c6_t10 * c6_t7);
  c6_y_x[5] = c6_t20 * c6_t38 + c6_t22 * c6_t41;
  c6_y_x[6] = (-c6_t20) * c6_t49 + c6_t22 * c6_t46 * c6_t7;
  c6_y_x[7] = 0.0;
  c6_y_x[8] = c6_t22 * c6_t26 + c6_t20 * (c6_t21 - c6_t10 * c6_t7);
  c6_y_x[9] = c6_t22 * c6_t38 - c6_t20 * c6_t41;
  c6_y_x[10] = (-c6_t22) * c6_t49 - c6_t20 * c6_t46 * c6_t7;
  c6_y_x[11] = 0.0;
  c6_y_x[12] = ((((((((((((((((((((((((((((((c6_L2 * c6_t2 + c6_L3 * c6_t2 *
    c6_t6) - c6_L8 * c6_t11 * c6_t12 * c6_t22) + c6_L4 *
    c6_t2 * c6_t3 * c6_t4) + c6_L9 * c6_t11 * c6_t12 * c6_t20) + c6_L5 * c6_t2 *
    c6_t3 * c6_t5) - c6_L6 * c6_t12 * c6_t13 * c6_t7) -
    c6_L7 * c6_t12 * c6_t13 * c6_t7) + c6_L4 * c6_t2 * c6_t5 * c6_t6) - c6_L5 *
    c6_t2 * c6_t4 * c6_t6) + c6_L6 * c6_t16 * c6_t2 * c6_t3
    * c6_t5) + c6_L7 * c6_t16 * c6_t2 * c6_t3 * c6_t5) - c6_L6 * c6_t16 * c6_t2 *
    c6_t4 * c6_t6) + c6_L8 * c6_t12 * c6_t16 * c6_t20 *
    c6_t7) - c6_L7 * c6_t16 * c6_t2 * c6_t4 * c6_t6) + c6_L9 * c6_t12 * c6_t16 *
    c6_t22 * c6_t7) - c6_L6 * c6_t11 * c6_t13 * c6_t2 *
    c6_t3 * c6_t4) - c6_L7 * c6_t11 * c6_t13 * c6_t2 * c6_t3 * c6_t4) + c6_L8 *
    c6_t13 * c6_t2 * c6_t20 * c6_t3 * c6_t5) - c6_L6 *
    c6_t11 * c6_t13 * c6_t2 * c6_t5 * c6_t6) - c6_L7 * c6_t11 * c6_t13 * c6_t2 *
    c6_t5 * c6_t6) + c6_L9 * c6_t13 * c6_t2 * c6_t22 *
    c6_t3 * c6_t5) - c6_L8 * c6_t13 * c6_t2 * c6_t20 * c6_t4 * c6_t6) - c6_L9 *
                       c6_t13 * c6_t2 * c6_t22 * c6_t4 * c6_t6) + c6_L8 * c6_t2
                      * c6_t22 * c6_t3 * c6_t4 * c6_t7) - c6_L9 * c6_t2 * c6_t20
                     * c6_t3 * c6_t4 * c6_t7) + c6_L8 * c6_t2 * c6_t22 * c6_t5 *
                    c6_t6 *
                    c6_t7) - c6_L9 * c6_t2 * c6_t20 * c6_t5 * c6_t6 * c6_t7) +
                  c6_L8 * c6_t11 * c6_t16 * c6_t2 * c6_t20 * c6_t3 * c6_t4) +
                 c6_L9 *
                 c6_t11 * c6_t16 * c6_t2 * c6_t22 * c6_t3 * c6_t4) + c6_L8 *
                c6_t11 * c6_t16 * c6_t2 * c6_t20 * c6_t5 * c6_t6) + c6_L9 *
    c6_t11 *
    c6_t16 * c6_t2 * c6_t22 * c6_t5 * c6_t6;
  c6_y_x[13] = ((((((((((((((((((((((((((((((c6_L2 * c6_t12 + c6_L3 * c6_t12 *
    c6_t6) + c6_L4 * c6_t12 * c6_t3 * c6_t4) + c6_L8 *
    c6_t11 * c6_t2 * c6_t22) + c6_L5 * c6_t12 * c6_t3 * c6_t5) - c6_L9 * c6_t11 *
    c6_t2 * c6_t20) + c6_L4 * c6_t12 * c6_t5 * c6_t6) -
    c6_L5 * c6_t12 * c6_t4 * c6_t6) + c6_L6 * c6_t13 * c6_t2 * c6_t7) + c6_L7 *
    c6_t13 * c6_t2 * c6_t7) + c6_L6 * c6_t12 * c6_t16 *
    c6_t3 * c6_t5) + c6_L7 * c6_t12 * c6_t16 * c6_t3 * c6_t5) - c6_L6 * c6_t12 *
    c6_t16 * c6_t4 * c6_t6) - c6_L7 * c6_t12 * c6_t16 *
    c6_t4 * c6_t6) - c6_L8 * c6_t16 * c6_t2 * c6_t20 * c6_t7) - c6_L9 * c6_t16 *
    c6_t2 * c6_t22 * c6_t7) - c6_L6 * c6_t11 * c6_t12 *
    c6_t13 * c6_t3 * c6_t4) - c6_L7 * c6_t11 * c6_t12 * c6_t13 * c6_t3 * c6_t4)
    + c6_L8 * c6_t12 * c6_t13 * c6_t20 * c6_t3 * c6_t5) -
    c6_L6 * c6_t11 * c6_t12 * c6_t13 * c6_t5 * c6_t6) - c6_L7 * c6_t11 * c6_t12 *
    c6_t13 * c6_t5 * c6_t6) + c6_L9 * c6_t12 * c6_t13 *
    c6_t22 * c6_t3 * c6_t5) - c6_L8 * c6_t12 * c6_t13 * c6_t20 * c6_t4 * c6_t6)
                       - c6_L9 * c6_t12 * c6_t13 * c6_t22 * c6_t4 * c6_t6) +
                      c6_L8 * c6_t12 * c6_t22 * c6_t3 * c6_t4 * c6_t7) - c6_L9 *
                     c6_t12 * c6_t20 * c6_t3 * c6_t4 * c6_t7) + c6_L8 * c6_t12 *
                    c6_t22 *
                    c6_t5 * c6_t6 * c6_t7) - c6_L9 * c6_t12 * c6_t20 * c6_t5 *
                   c6_t6 * c6_t7) + c6_L8 * c6_t11 * c6_t12 * c6_t16 * c6_t20 *
                  c6_t3 *
                  c6_t4) + c6_L9 * c6_t11 * c6_t12 * c6_t16 * c6_t22 * c6_t3 *
                 c6_t4) + c6_L8 * c6_t11 * c6_t12 * c6_t16 * c6_t20 * c6_t5 *
                c6_t6) +
    c6_L9 * c6_t11 * c6_t12 * c6_t16 * c6_t22 * c6_t5 * c6_t6;
  c6_y_x[14] = ((((((((((((((((((((((((c6_L1 + c6_L3 * c6_t3) + c6_L4 * c6_t3 *
    c6_t5) - c6_L5 * c6_t3 * c6_t4) - c6_L4 * c6_t4 *
    c6_t6) - c6_L5 * c6_t5 * c6_t6) - c6_L6 * c6_t16 * c6_t3 * c6_t4) - c6_L7 *
    c6_t16 * c6_t3 * c6_t4) - c6_L6 * c6_t16 * c6_t5 * c6_t6
    ) - c6_L7 * c6_t16 * c6_t5 * c6_t6) - c6_L6 * c6_t11 * c6_t13 * c6_t3 *
    c6_t5) - c6_L7 * c6_t11 * c6_t13 * c6_t3 * c6_t5) - c6_L8 *
    c6_t13 * c6_t20 * c6_t3 * c6_t4) + c6_L6 * c6_t11 * c6_t13 * c6_t4 * c6_t6)
    + c6_L7 * c6_t11 * c6_t13 * c6_t4 * c6_t6) - c6_L9 *
    c6_t13 * c6_t22 * c6_t3 * c6_t4) - c6_L8 * c6_t13 * c6_t20 * c6_t5 * c6_t6)
                       - c6_L9 * c6_t13 * c6_t22 * c6_t5 * c6_t6) + c6_L8 *
                      c6_t22 * c6_t3 * c6_t5 * c6_t7) - c6_L9 * c6_t20 * c6_t3 *
                     c6_t5 * c6_t7) - c6_L8 * c6_t22 * c6_t4 * c6_t6 * c6_t7) +
                   c6_L9 * c6_t20
                   * c6_t4 * c6_t6 * c6_t7) + c6_L8 * c6_t11 * c6_t16 * c6_t20 *
                  c6_t3 * c6_t5) + c6_L9 * c6_t11 * c6_t16 * c6_t22 * c6_t3 *
                 c6_t5) -
                c6_L8 * c6_t11 * c6_t16 * c6_t20 * c6_t4 * c6_t6) - c6_L9 *
    c6_t11 * c6_t16 * c6_t22 * c6_t4 * c6_t6;
  c6_y_x[15] = 1.0;
  for (c6_k = 1; c6_k < 17; c6_k = c6_k + 1) {
    c6_b_k = c6_k;
    c6_gst[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 16, 1, 0) - 1] = c6_y_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c6_b_k), 1, 16, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0, -71);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c6_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i16;
  real_T c6_b_u[3];
  int32_T c6_i17;
  real_T c6_c_u[3];
  const mxArray *c6_b_y = NULL;
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  for (c6_i16 = 0; c6_i16 < 3; c6_i16 = c6_i16 + 1) {
    c6_b_u[c6_i16] = (*((real_T (*)[3])c6_u))[c6_i16];
  }

  for (c6_i17 = 0; c6_i17 < 3; c6_i17 = c6_i17 + 1) {
    c6_c_u[c6_i17] = c6_b_u[c6_i17];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_b_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i18;
  real_T c6_b_u[9];
  int32_T c6_i19;
  real_T c6_c_u[9];
  const mxArray *c6_b_y = NULL;
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  for (c6_i18 = 0; c6_i18 < 9; c6_i18 = c6_i18 + 1) {
    c6_b_u[c6_i18] = (*((real_T (*)[9])c6_u))[c6_i18];
  }

  for (c6_i19 = 0; c6_i19 < 9; c6_i19 = c6_i19 + 1) {
    c6_c_u[c6_i19] = c6_b_u[c6_i19];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_c_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i20;
  real_T c6_b_u[6];
  int32_T c6_i21;
  real_T c6_c_u[6];
  const mxArray *c6_b_y = NULL;
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  for (c6_i20 = 0; c6_i20 < 6; c6_i20 = c6_i20 + 1) {
    c6_b_u[c6_i20] = (*((real_T (*)[6])c6_u))[c6_i20];
  }

  for (c6_i21 = 0; c6_i21 < 6; c6_i21 = c6_i21 + 1) {
    c6_c_u[c6_i21] = c6_b_u[c6_i21];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_d_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  real_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_b_u = *((real_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_e_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  real_T c6_b_u[16];
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  real_T c6_c_u[16];
  const mxArray *c6_b_y = NULL;
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_i22 = 0;
  for (c6_i23 = 0; c6_i23 < 4; c6_i23 = c6_i23 + 1) {
    for (c6_i24 = 0; c6_i24 < 4; c6_i24 = c6_i24 + 1) {
      c6_b_u[c6_i24 + c6_i22] = (*((real_T (*)[16])c6_u))[c6_i24 + c6_i22];
    }

    c6_i22 = c6_i22 + 4;
  }

  c6_i25 = 0;
  for (c6_i26 = 0; c6_i26 < 4; c6_i26 = c6_i26 + 1) {
    for (c6_i27 = 0; c6_i27 < 4; c6_i27 = c6_i27 + 1) {
      c6_c_u[c6_i27 + c6_i25] = c6_b_u[c6_i27 + c6_i25];
    }

    c6_i25 = c6_i25 + 4;
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static const mxArray *c6_f_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  int32_T c6_i28;
  real_T c6_b_u[6];
  int32_T c6_i29;
  real_T c6_c_u[6];
  const mxArray *c6_b_y = NULL;
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  for (c6_i28 = 0; c6_i28 < 6; c6_i28 = c6_i28 + 1) {
    c6_b_u[c6_i28] = (*((real_T (*)[6])c6_u))[c6_i28];
  }

  for (c6_i29 = 0; c6_i29 < 6; c6_i29 = c6_i29 + 1) {
    c6_c_u[c6_i29] = c6_b_u[c6_i29];
  }

  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

const mxArray *sf_c6_DynJointVerify_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_ResolvedFunctionInfo c6_info[39];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i30;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 39));
  for (c6_i30 = 0; c6_i30 < 39; c6_i30 = c6_i30 + 1) {
    c6_r0 = &c6_info[c6_i30];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context",
                    "nameCaptureInfo", c6_i30);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name",
                    "nameCaptureInfo", c6_i30);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c6_i30);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c6_i30);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c6_i30);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c6_i30
                    );
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c6_i30
                    );
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[39])
{
  c6_info[0].context = "";
  c6_info[0].name = "ctranspose";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[B]ctranspose";
  c6_info[0].fileLength = 0U;
  c6_info[0].fileTime1 = 0U;
  c6_info[0].fileTime2 = 0U;
  c6_info[1].context = "";
  c6_info[1].name = "fwd_kin";
  c6_info[1].dominantType = "double";
  c6_info[1].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[1].fileLength = 3324U;
  c6_info[1].fileTime1 = 1366778959U;
  c6_info[1].fileTime2 = 0U;
  c6_info[2].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[2].name = "cos";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[2].fileLength = 324U;
  c6_info[2].fileTime1 = 1203422750U;
  c6_info[2].fileTime2 = 0U;
  c6_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[3].name = "nargin";
  c6_info[3].dominantType = "";
  c6_info[3].resolved = "[B]nargin";
  c6_info[3].fileLength = 0U;
  c6_info[3].fileTime1 = 0U;
  c6_info[3].fileTime2 = 0U;
  c6_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[4].name = "gt";
  c6_info[4].dominantType = "double";
  c6_info[4].resolved = "[B]gt";
  c6_info[4].fileLength = 0U;
  c6_info[4].fileTime1 = 0U;
  c6_info[4].fileTime2 = 0U;
  c6_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[5].name = "isa";
  c6_info[5].dominantType = "double";
  c6_info[5].resolved = "[B]isa";
  c6_info[5].fileLength = 0U;
  c6_info[5].fileTime1 = 0U;
  c6_info[5].fileTime2 = 0U;
  c6_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c6_info[6].name = "eml_scalar_cos";
  c6_info[6].dominantType = "double";
  c6_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[6].fileLength = 602U;
  c6_info[6].fileTime1 = 1209309186U;
  c6_info[6].fileTime2 = 0U;
  c6_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c6_info[7].name = "isreal";
  c6_info[7].dominantType = "double";
  c6_info[7].resolved = "[B]isreal";
  c6_info[7].fileLength = 0U;
  c6_info[7].fileTime1 = 0U;
  c6_info[7].fileTime2 = 0U;
  c6_info[8].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[8].name = "sin";
  c6_info[8].dominantType = "double";
  c6_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[8].fileLength = 324U;
  c6_info[8].fileTime1 = 1203422842U;
  c6_info[8].fileTime2 = 0U;
  c6_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c6_info[9].name = "eml_scalar_sin";
  c6_info[9].dominantType = "double";
  c6_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c6_info[9].fileLength = 601U;
  c6_info[9].fileTime1 = 1209309190U;
  c6_info[9].fileTime2 = 0U;
  c6_info[10].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[10].name = "times";
  c6_info[10].dominantType = "double";
  c6_info[10].resolved = "[B]times";
  c6_info[10].fileLength = 0U;
  c6_info[10].fileTime1 = 0U;
  c6_info[10].fileTime2 = 0U;
  c6_info[11].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[11].name = "plus";
  c6_info[11].dominantType = "double";
  c6_info[11].resolved = "[B]plus";
  c6_info[11].fileLength = 0U;
  c6_info[11].fileTime1 = 0U;
  c6_info[11].fileTime2 = 0U;
  c6_info[12].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[12].name = "minus";
  c6_info[12].dominantType = "double";
  c6_info[12].resolved = "[B]minus";
  c6_info[12].fileLength = 0U;
  c6_info[12].fileTime1 = 0U;
  c6_info[12].fileTime2 = 0U;
  c6_info[13].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[13].name = "uminus";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved = "[B]uminus";
  c6_info[13].fileLength = 0U;
  c6_info[13].fileTime1 = 0U;
  c6_info[13].fileTime2 = 0U;
  c6_info[14].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c6_info[14].name = "reshape";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c6_info[14].fileLength = 4857U;
  c6_info[14].fileTime1 = 1242276774U;
  c6_info[14].fileTime2 = 0U;
  c6_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c6_info[15].name = "eml_index_class";
  c6_info[15].dominantType = "";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[15].fileLength = 909U;
  c6_info[15].fileTime1 = 1192445182U;
  c6_info[15].fileTime2 = 0U;
  c6_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c6_info[16].name = "cast";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved = "[B]cast";
  c6_info[16].fileLength = 0U;
  c6_info[16].fileTime1 = 0U;
  c6_info[16].fileTime2 = 0U;
  c6_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c6_info[17].name = "size";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved = "[B]size";
  c6_info[17].fileLength = 0U;
  c6_info[17].fileTime1 = 0U;
  c6_info[17].fileTime2 = 0U;
  c6_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c6_info[18].name = "eq";
  c6_info[18].dominantType = "double";
  c6_info[18].resolved = "[B]eq";
  c6_info[18].fileLength = 0U;
  c6_info[18].fileTime1 = 0U;
  c6_info[18].fileTime2 = 0U;
  c6_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c6_info[19].name = "eml_assert_valid_size_arg";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[19].fileLength = 3315U;
  c6_info[19].fileTime1 = 1256367816U;
  c6_info[19].fileTime2 = 0U;
  c6_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c6_info[20].name = "false";
  c6_info[20].dominantType = "";
  c6_info[20].resolved = "[B]false";
  c6_info[20].fileLength = 0U;
  c6_info[20].fileTime1 = 0U;
  c6_info[20].fileTime2 = 0U;
  c6_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c6_info[21].name = "not";
  c6_info[21].dominantType = "logical";
  c6_info[21].resolved = "[B]not";
  c6_info[21].fileLength = 0U;
  c6_info[21].fileTime1 = 0U;
  c6_info[21].fileTime2 = 0U;
  c6_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[22].name = "isvector";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved = "[B]isvector";
  c6_info[22].fileLength = 0U;
  c6_info[22].fileTime1 = 0U;
  c6_info[22].fileTime2 = 0U;
  c6_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c6_info[23].name = "isinteger";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved = "[B]isinteger";
  c6_info[23].fileLength = 0U;
  c6_info[23].fileTime1 = 0U;
  c6_info[23].fileTime2 = 0U;
  c6_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c6_info[24].name = "ne";
  c6_info[24].dominantType = "double";
  c6_info[24].resolved = "[B]ne";
  c6_info[24].fileLength = 0U;
  c6_info[24].fileTime1 = 0U;
  c6_info[24].fileTime2 = 0U;
  c6_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c6_info[25].name = "isinf";
  c6_info[25].dominantType = "double";
  c6_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c6_info[25].fileLength = 541U;
  c6_info[25].fileTime1 = 1271383988U;
  c6_info[25].fileTime2 = 0U;
  c6_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c6_info[26].name = "true";
  c6_info[26].dominantType = "";
  c6_info[26].resolved = "[B]true";
  c6_info[26].fileLength = 0U;
  c6_info[26].fileTime1 = 0U;
  c6_info[26].fileTime2 = 0U;
  c6_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c6_info[27].name = "le";
  c6_info[27].dominantType = "double";
  c6_info[27].resolved = "[B]le";
  c6_info[27].fileLength = 0U;
  c6_info[27].fileTime1 = 0U;
  c6_info[27].fileTime2 = 0U;
  c6_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c6_info[28].name = "double";
  c6_info[28].dominantType = "double";
  c6_info[28].resolved = "[B]double";
  c6_info[28].fileLength = 0U;
  c6_info[28].fileTime1 = 0U;
  c6_info[28].fileTime2 = 0U;
  c6_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c6_info[29].name = "mtimes";
  c6_info[29].dominantType = "double";
  c6_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[29].fileLength = 3425U;
  c6_info[29].fileTime1 = 1251010272U;
  c6_info[29].fileTime2 = 0U;
  c6_info[30].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[30].name = "isscalar";
  c6_info[30].dominantType = "double";
  c6_info[30].resolved = "[B]isscalar";
  c6_info[30].fileLength = 0U;
  c6_info[30].fileTime1 = 0U;
  c6_info[30].fileTime2 = 0U;
  c6_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[31].name = "strcmp";
  c6_info[31].dominantType = "char";
  c6_info[31].resolved = "[B]strcmp";
  c6_info[31].fileLength = 0U;
  c6_info[31].fileTime1 = 0U;
  c6_info[31].fileTime2 = 0U;
  c6_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[32].name = "class";
  c6_info[32].dominantType = "double";
  c6_info[32].resolved = "[B]class";
  c6_info[32].fileLength = 0U;
  c6_info[32].fileTime1 = 0U;
  c6_info[32].fileTime2 = 0U;
  c6_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c6_info[33].name = "intmax";
  c6_info[33].dominantType = "char";
  c6_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[33].fileLength = 1535U;
  c6_info[33].fileTime1 = 1192445128U;
  c6_info[33].fileTime2 = 0U;
  c6_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[34].name = "ischar";
  c6_info[34].dominantType = "char";
  c6_info[34].resolved = "[B]ischar";
  c6_info[34].fileLength = 0U;
  c6_info[34].fileTime1 = 0U;
  c6_info[34].fileTime2 = 0U;
  c6_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c6_info[35].name = "int32";
  c6_info[35].dominantType = "double";
  c6_info[35].resolved = "[B]int32";
  c6_info[35].fileLength = 0U;
  c6_info[35].fileTime1 = 0U;
  c6_info[35].fileTime2 = 0U;
  c6_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c6_info[36].name = "eml_scalar_eg";
  c6_info[36].dominantType = "double";
  c6_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[36].fileLength = 3068U;
  c6_info[36].fileTime1 = 1240240410U;
  c6_info[36].fileTime2 = 0U;
  c6_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[37].name = "isstruct";
  c6_info[37].dominantType = "double";
  c6_info[37].resolved = "[B]isstruct";
  c6_info[37].fileLength = 0U;
  c6_info[37].fileTime1 = 0U;
  c6_info[37].fileTime2 = 0U;
  c6_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c6_info[38].name = "ones";
  c6_info[38].dominantType = "char";
  c6_info[38].resolved = "[B]ones";
  c6_info[38].fileLength = 0U;
  c6_info[38].fileTime1 = 0U;
  c6_info[38].fileTime2 = 0U;
}

static const mxArray *c6_g_sf_marshall(void *chartInstanceVoid, void *c6_u)
{
  const mxArray *c6_y = NULL;
  boolean_T c6_b_u;
  const mxArray *c6_b_y = NULL;
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c6_y = NULL;
  c6_b_u = *((boolean_T *)c6_u);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c6_y, c6_b_y);
  return c6_y;
}

static void c6_emlrt_marshallIn(SFc6_DynJointVerifyInstanceStruct *chartInstance,
  const mxArray *c6_EndPos, const char_T *c6_name,
  real_T c6_y[3])
{
  real_T c6_dv3[3];
  int32_T c6_i31;
  sf_mex_import(c6_name, sf_mex_dup(c6_EndPos), c6_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i31 = 0; c6_i31 < 3; c6_i31 = c6_i31 + 1) {
    c6_y[c6_i31] = c6_dv3[c6_i31];
  }

  sf_mex_destroy(&c6_EndPos);
}

static uint8_T c6_b_emlrt_marshallIn(SFc6_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *
  c6_b_is_active_c6_DynJointVerify, const char_T *c6_name)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_name, sf_mex_dup(c6_b_is_active_c6_DynJointVerify), &c6_u0, 1,
                3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_b_is_active_c6_DynJointVerify);
  return c6_y;
}

static void init_dsm_address_info(SFc6_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c6_DynJointVerify_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3049321950U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(987706000U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2834568350U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(132016629U);
}

mxArray *sf_c6_DynJointVerify_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3643355045U);
    pr[1] = (double)(2359329077U);
    pr[2] = (double)(1004228172U);
    pr[3] = (double)(3890115386U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c6_DynJointVerify(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"EndPos\",},{M[8],M[0],T\"is_active_c6_DynJointVerify\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_DynJointVerify_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_DynJointVerifyInstanceStruct *chartInstance;
    chartInstance = (SFc6_DynJointVerifyInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_DynJointVerifyMachineNumber_,
           6,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           1,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_DynJointVerifyMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_DynJointVerifyMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_DynJointVerifyMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"EndPos");
          _SFD_SET_DATA_PROPS(2,10,0,0,"L");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,80);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"fwd_kin",0,-1,3253);
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
            1.0,0,0,(MexFcnForType)c6_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshall);
        }

        {
          real_T (*c6_Theta)[6];
          real_T (*c6_EndPos)[3];
          c6_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c6_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_Theta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c6_EndPos);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c6_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_DynJointVerifyMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c6_DynJointVerify(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_DynJointVerifyInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
  initialize_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_DynJointVerify(void *chartInstanceVar)
{
  enable_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_DynJointVerify(void *chartInstanceVar)
{
  disable_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_DynJointVerify(void *chartInstanceVar)
{
  sf_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c6_DynJointVerify(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_DynJointVerify
    ((SFc6_DynJointVerifyInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c6_DynJointVerify();/* state var info */
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

static void sf_internal_set_sim_state_c6_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_DynJointVerify();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c6_DynJointVerify(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_DynJointVerify(S);
}

static void sf_opaque_set_sim_state_c6_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c6_DynJointVerify(S, st);
}

static void sf_opaque_terminate_c6_DynJointVerify(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_DynJointVerifyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c6_DynJointVerify
    ((SFc6_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_DynJointVerify(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_DynJointVerify((SFc6_DynJointVerifyInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_DynJointVerify(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(S,"DynJointVerify","DynJointVerify",6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DynJointVerify","DynJointVerify",6,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DynJointVerify",
      "DynJointVerify",6,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DynJointVerify","DynJointVerify",6,
        1);
      sf_mark_chart_reusable_outputs(S,"DynJointVerify","DynJointVerify",6,1);
    }

    sf_set_rtw_dwork_info(S,"DynJointVerify","DynJointVerify",6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1395287209U));
  ssSetChecksum1(S,(539437333U));
  ssSetChecksum2(S,(3228308264U));
  ssSetChecksum3(S,(4151799812U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_DynJointVerify(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DynJointVerify", "DynJointVerify",6);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_DynJointVerify(SimStruct *S)
{
  SFc6_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc6_DynJointVerifyInstanceStruct *)malloc(sizeof
    (SFc6_DynJointVerifyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_DynJointVerifyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_DynJointVerify;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_DynJointVerify;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_DynJointVerify;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_DynJointVerify;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_DynJointVerify;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_DynJointVerify;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_DynJointVerify;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_DynJointVerify;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_DynJointVerify;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_DynJointVerify;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_DynJointVerify;
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

void c6_DynJointVerify_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_DynJointVerify(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_DynJointVerify(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_DynJointVerify(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_DynJointVerify_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
