/* Include files */

#include "blascompat32.h"
#include "DynJointCon_sfun.h"
#include "c10_DynJointCon.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DynJointCon_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c10_debug_family_names[6] = { "gd", "nargin", "nargout",
  "Theta", "L", "EndPos" };

static const char *c10_b_debug_family_names[68] = { "A1", "A2", "A3", "A4", "A5",
  "A6", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t2", "t3", "t4",
  "t5", "t6", "t7", "t8", "t9", "t10", "t11", "t12", "t13", "t14", "t23", "t15",
  "t16", "t17", "t18", "t19", "t20", "t21", "t22", "t24", "t25", "t26", "t27",
  "t34", "t28", "t29", "t30", "t31", "t32", "t36", "t33", "t35", "t37", "t38",
  "t39", "t40", "t41", "t42", "t43", "t44", "t45", "t47", "t46", "t48", "t49",
  "nargin", "nargout", "in1", "in2", "gst" };

/* Function Declarations */
static void initialize_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance);
static void initialize_params_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance);
static void enable_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance);
static void disable_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance);
static void c10_update_debugger_state_c10_DynJointCon
  (SFc10_DynJointConInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_DynJointCon
  (SFc10_DynJointConInstanceStruct *chartInstance);
static void set_sim_state_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance, const mxArray *c10_st);
static void finalize_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance);
static void sf_c10_DynJointCon(SFc10_DynJointConInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c10_DynJointCon
  (SFc10_DynJointConInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static void c10_fwd_kin(SFc10_DynJointConInstanceStruct *chartInstance, real_T
  c10_in1[9], real_T c10_in2[6], real_T c10_gst[16]);
static const mxArray *c10_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_b_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_c_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_d_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_e_sf_marshall(void *chartInstanceVoid, void *c10_u);
static const mxArray *c10_f_sf_marshall(void *chartInstanceVoid, void *c10_u);
static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[39]);
static const mxArray *c10_g_sf_marshall(void *chartInstanceVoid, void *c10_u);
static void c10_emlrt_marshallIn(SFc10_DynJointConInstanceStruct *chartInstance,
  const mxArray *c10_EndPos, const char_T *c10_name, real_T c10_y[3]);
static uint8_T c10_b_emlrt_marshallIn(SFc10_DynJointConInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_DynJointCon, const char_T
  *c10_name);
static void init_dsm_address_info(SFc10_DynJointConInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_DynJointCon = 0U;
}

static void initialize_params_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance)
{
  real_T c10_dv0[9];
  int32_T c10_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c10_dv0, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c10_i0 = 0; c10_i0 < 9; c10_i0 = c10_i0 + 1) {
    chartInstance->c10_L[c10_i0] = c10_dv0[c10_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_DynJointCon
  (SFc10_DynJointConInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c10_DynJointCon
  (SFc10_DynJointConInstanceStruct *chartInstance)
{
  const mxArray *c10_st = NULL;
  const mxArray *c10_y = NULL;
  int32_T c10_i1;
  real_T c10_hoistedGlobal[3];
  int32_T c10_i2;
  real_T c10_u[3];
  const mxArray *c10_b_y = NULL;
  uint8_T c10_b_hoistedGlobal;
  uint8_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T (*c10_EndPos)[3];
  c10_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(2));
  for (c10_i1 = 0; c10_i1 < 3; c10_i1 = c10_i1 + 1) {
    c10_hoistedGlobal[c10_i1] = (*c10_EndPos)[c10_i1];
  }

  for (c10_i2 = 0; c10_i2 < 3; c10_i2 = c10_i2 + 1) {
    c10_u[c10_i2] = c10_hoistedGlobal[c10_i2];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = chartInstance->c10_is_active_c10_DynJointCon;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c10_y, 1, c10_c_y);
  sf_mex_assign(&c10_st, c10_y);
  return c10_st;
}

static void set_sim_state_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T c10_dv1[3];
  int32_T c10_i3;
  real_T (*c10_EndPos)[3];
  c10_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 0)),
                       "EndPos", c10_dv1);
  for (c10_i3 = 0; c10_i3 < 3; c10_i3 = c10_i3 + 1) {
    (*c10_EndPos)[c10_i3] = c10_dv1[c10_i3];
  }

  chartInstance->c10_is_active_c10_DynJointCon = c10_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 1)),
     "is_active_c10_DynJointCon");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_DynJointCon(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_DynJointCon(SFc10_DynJointConInstanceStruct
  *chartInstance)
{
}

static void sf_c10_DynJointCon(SFc10_DynJointConInstanceStruct *chartInstance)
{
  int32_T c10_i4;
  int32_T c10_i5;
  int32_T c10_i6;
  int32_T c10_previousEvent;
  int32_T c10_i7;
  real_T c10_hoistedGlobal[6];
  int32_T c10_i8;
  real_T c10_b_hoistedGlobal[9];
  int32_T c10_i9;
  real_T c10_Theta[6];
  int32_T c10_i10;
  real_T c10_b_L[9];
  uint32_T c10_debug_family_var_map[6];
  real_T c10_gd[16];
  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  real_T c10_EndPos[3];
  int32_T c10_i11;
  real_T c10_c_L[9];
  int32_T c10_i12;
  real_T c10_b_Theta[6];
  real_T c10_dv2[16];
  int32_T c10_i13;
  int32_T c10_i14;
  int32_T c10_i15;
  real_T (*c10_b_EndPos)[3];
  real_T (*c10_c_Theta)[6];
  c10_b_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c10_c_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9);
  for (c10_i4 = 0; c10_i4 < 6; c10_i4 = c10_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_c_Theta)[c10_i4], 0U);
  }

  for (c10_i5 = 0; c10_i5 < 3; c10_i5 = c10_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c10_b_EndPos)[c10_i5], 1U);
  }

  for (c10_i6 = 0; c10_i6 < 9; c10_i6 = c10_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c10_L[c10_i6], 2U);
  }

  c10_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9);
  for (c10_i7 = 0; c10_i7 < 6; c10_i7 = c10_i7 + 1) {
    c10_hoistedGlobal[c10_i7] = (*c10_c_Theta)[c10_i7];
  }

  for (c10_i8 = 0; c10_i8 < 9; c10_i8 = c10_i8 + 1) {
    c10_b_hoistedGlobal[c10_i8] = chartInstance->c10_L[c10_i8];
  }

  for (c10_i9 = 0; c10_i9 < 6; c10_i9 = c10_i9 + 1) {
    c10_Theta[c10_i9] = c10_hoistedGlobal[c10_i9];
  }

  for (c10_i10 = 0; c10_i10 < 9; c10_i10 = c10_i10 + 1) {
    c10_b_L[c10_i10] = c10_b_hoistedGlobal[c10_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c10_debug_family_names,
    c10_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c10_gd, c10_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c10_nargin, c10_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c10_nargout, c10_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c10_Theta, c10_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c10_b_L, c10_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c10_EndPos, c10_sf_marshall, 5U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c10_i11 = 0; c10_i11 < 9; c10_i11 = c10_i11 + 1) {
    c10_c_L[c10_i11] = c10_b_L[c10_i11];
  }

  for (c10_i12 = 0; c10_i12 < 6; c10_i12 = c10_i12 + 1) {
    c10_b_Theta[c10_i12] = c10_Theta[c10_i12];
  }

  c10_fwd_kin(chartInstance, c10_c_L, c10_b_Theta, c10_dv2);
  for (c10_i13 = 0; c10_i13 < 16; c10_i13 = c10_i13 + 1) {
    c10_gd[c10_i13] = c10_dv2[c10_i13];
  }

  _SFD_EML_CALL(0, 4);
  for (c10_i14 = 0; c10_i14 < 3; c10_i14 = c10_i14 + 1) {
    c10_EndPos[c10_i14] = c10_gd[c10_i14 + 12];
  }

  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  for (c10_i15 = 0; c10_i15 < 3; c10_i15 = c10_i15 + 1) {
    (*c10_b_EndPos)[c10_i15] = c10_EndPos[c10_i15];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9);
  _sfEvent_ = c10_previousEvent;
  sf_debug_check_for_state_inconsistency(_DynJointConMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c10_DynJointCon
  (SFc10_DynJointConInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c10_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/fwd_kin.m"));
}

static void c10_fwd_kin(SFc10_DynJointConInstanceStruct *chartInstance, real_T
  c10_in1[9], real_T c10_in2[6], real_T c10_gst[16])
{
  uint32_T c10_debug_family_var_map[68];
  real_T c10_A1;
  real_T c10_A2;
  real_T c10_A3;
  real_T c10_A4;
  real_T c10_A5;
  real_T c10_A6;
  real_T c10_L1;
  real_T c10_L2;
  real_T c10_L3;
  real_T c10_L4;
  real_T c10_L5;
  real_T c10_L6;
  real_T c10_L7;
  real_T c10_L8;
  real_T c10_L9;
  real_T c10_t2;
  real_T c10_t3;
  real_T c10_t4;
  real_T c10_t5;
  real_T c10_t6;
  real_T c10_t7;
  real_T c10_t8;
  real_T c10_t9;
  real_T c10_t10;
  real_T c10_t11;
  real_T c10_t12;
  real_T c10_t13;
  real_T c10_t14;
  real_T c10_t23;
  real_T c10_t15;
  real_T c10_t16;
  real_T c10_t17;
  real_T c10_t18;
  real_T c10_t19;
  real_T c10_t20;
  real_T c10_t21;
  real_T c10_t22;
  real_T c10_t24;
  real_T c10_t25;
  real_T c10_t26;
  real_T c10_t27;
  real_T c10_t34;
  real_T c10_t28;
  real_T c10_t29;
  real_T c10_t30;
  real_T c10_t31;
  real_T c10_t32;
  real_T c10_t36;
  real_T c10_t33;
  real_T c10_t35;
  real_T c10_t37;
  real_T c10_t38;
  real_T c10_t39;
  real_T c10_t40;
  real_T c10_t41;
  real_T c10_t42;
  real_T c10_t43;
  real_T c10_t44;
  real_T c10_t45;
  real_T c10_t47;
  real_T c10_t46;
  real_T c10_t48;
  real_T c10_t49;
  real_T c10_nargin = 2.0;
  real_T c10_nargout = 1.0;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_x;
  real_T c10_f_x;
  real_T c10_g_x;
  real_T c10_h_x;
  real_T c10_i_x;
  real_T c10_j_x;
  real_T c10_k_x;
  real_T c10_l_x;
  real_T c10_m_x;
  real_T c10_n_x;
  real_T c10_o_x;
  real_T c10_p_x;
  real_T c10_q_x;
  real_T c10_r_x;
  real_T c10_s_x;
  real_T c10_t_x;
  real_T c10_u_x;
  real_T c10_v_x;
  real_T c10_w_x;
  real_T c10_x_x;
  real_T c10_y_x[16];
  int32_T c10_k;
  int32_T c10_b_k;
  sf_debug_symbol_scope_push_eml(0U, 68U, 68U, c10_b_debug_family_names,
    c10_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c10_A1, c10_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c10_A2, c10_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c10_A3, c10_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c10_A4, c10_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c10_A5, c10_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c10_A6, c10_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c10_L1, c10_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c10_L2, c10_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c10_L3, c10_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c10_L4, c10_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c10_L5, c10_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c10_L6, c10_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c10_L7, c10_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c10_L8, c10_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c10_L9, c10_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c10_t2, c10_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c10_t3, c10_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c10_t4, c10_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c10_t5, c10_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c10_t6, c10_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c10_t7, c10_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c10_t8, c10_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c10_t9, c10_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c10_t10, c10_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c10_t11, c10_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c10_t12, c10_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c10_t13, c10_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c10_t14, c10_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c10_t23, c10_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c10_t15, c10_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c10_t16, c10_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c10_t17, c10_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c10_t18, c10_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c10_t19, c10_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c10_t20, c10_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c10_t21, c10_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c10_t22, c10_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c10_t24, c10_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c10_t25, c10_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c10_t26, c10_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c10_t27, c10_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c10_t34, c10_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c10_t28, c10_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c10_t29, c10_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c10_t30, c10_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c10_t31, c10_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c10_t32, c10_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c10_t36, c10_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c10_t33, c10_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c10_t35, c10_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c10_t37, c10_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c10_t38, c10_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c10_t39, c10_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c10_t40, c10_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c10_t41, c10_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c10_t42, c10_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c10_t43, c10_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c10_t44, c10_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c10_t45, c10_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c10_t47, c10_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c10_t46, c10_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c10_t48, c10_d_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c10_t49, c10_d_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c10_nargin, c10_d_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c10_nargout, c10_d_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c10_in1, c10_b_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(c10_in2, c10_f_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(c10_gst, c10_e_sf_marshall, 67U);
  CV_SCRIPT_FCN(0, 0);

  /* FWD_KIN */
  /*     GST = FWD_KIN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     24-Apr-2013 12:49:18 */
  _SFD_SCRIPT_CALL(0, 8);
  c10_A1 = c10_in2[0];
  _SFD_SCRIPT_CALL(0, 9);
  c10_A2 = c10_in2[1];
  _SFD_SCRIPT_CALL(0, 10);
  c10_A3 = c10_in2[2];
  _SFD_SCRIPT_CALL(0, 11);
  c10_A4 = c10_in2[3];
  _SFD_SCRIPT_CALL(0, 12);
  c10_A5 = c10_in2[4];
  _SFD_SCRIPT_CALL(0, 13);
  c10_A6 = c10_in2[5];
  _SFD_SCRIPT_CALL(0, 14);
  c10_L1 = c10_in1[0];
  _SFD_SCRIPT_CALL(0, 15);
  c10_L2 = c10_in1[1];
  _SFD_SCRIPT_CALL(0, 16);
  c10_L3 = c10_in1[2];
  _SFD_SCRIPT_CALL(0, 17);
  c10_L4 = c10_in1[3];
  _SFD_SCRIPT_CALL(0, 18);
  c10_L5 = c10_in1[4];
  _SFD_SCRIPT_CALL(0, 19);
  c10_L6 = c10_in1[5];
  _SFD_SCRIPT_CALL(0, 20);
  c10_L7 = c10_in1[6];
  _SFD_SCRIPT_CALL(0, 21);
  c10_L8 = c10_in1[7];
  _SFD_SCRIPT_CALL(0, 22);
  c10_L9 = c10_in1[8];
  _SFD_SCRIPT_CALL(0, 23);
  c10_x = c10_A1;
  c10_t2 = c10_x;
  c10_b_x = c10_t2;
  c10_t2 = c10_b_x;
  c10_t2 = muDoubleScalarCos(c10_t2);
  _SFD_SCRIPT_CALL(0, 24);
  c10_c_x = c10_A2;
  c10_t3 = c10_c_x;
  c10_d_x = c10_t3;
  c10_t3 = c10_d_x;
  c10_t3 = muDoubleScalarCos(c10_t3);
  _SFD_SCRIPT_CALL(0, 25);
  c10_e_x = c10_A3;
  c10_t4 = c10_e_x;
  c10_f_x = c10_t4;
  c10_t4 = c10_f_x;
  c10_t4 = muDoubleScalarSin(c10_t4);
  _SFD_SCRIPT_CALL(0, 26);
  c10_g_x = c10_A3;
  c10_t5 = c10_g_x;
  c10_h_x = c10_t5;
  c10_t5 = c10_h_x;
  c10_t5 = muDoubleScalarCos(c10_t5);
  _SFD_SCRIPT_CALL(0, 27);
  c10_i_x = c10_A2;
  c10_t6 = c10_i_x;
  c10_j_x = c10_t6;
  c10_t6 = c10_j_x;
  c10_t6 = muDoubleScalarSin(c10_t6);
  _SFD_SCRIPT_CALL(0, 28);
  c10_k_x = c10_A4;
  c10_t7 = c10_k_x;
  c10_l_x = c10_t7;
  c10_t7 = c10_l_x;
  c10_t7 = muDoubleScalarSin(c10_t7);
  _SFD_SCRIPT_CALL(0, 29);
  c10_t8 = c10_t2 * c10_t3 * c10_t4;
  _SFD_SCRIPT_CALL(0, 30);
  c10_t9 = c10_t2 * c10_t5 * c10_t6;
  _SFD_SCRIPT_CALL(0, 31);
  c10_t10 = c10_t8 + c10_t9;
  _SFD_SCRIPT_CALL(0, 32);
  c10_m_x = c10_A4;
  c10_t11 = c10_m_x;
  c10_n_x = c10_t11;
  c10_t11 = c10_n_x;
  c10_t11 = muDoubleScalarCos(c10_t11);
  _SFD_SCRIPT_CALL(0, 33);
  c10_o_x = c10_A1;
  c10_t12 = c10_o_x;
  c10_p_x = c10_t12;
  c10_t12 = c10_p_x;
  c10_t12 = muDoubleScalarSin(c10_t12);
  _SFD_SCRIPT_CALL(0, 34);
  c10_q_x = c10_A5;
  c10_t13 = c10_q_x;
  c10_r_x = c10_t13;
  c10_t13 = c10_r_x;
  c10_t13 = muDoubleScalarSin(c10_t13);
  _SFD_SCRIPT_CALL(0, 35);
  c10_t14 = c10_t2 * c10_t3 * c10_t5;
  _SFD_SCRIPT_CALL(0, 36);
  c10_t23 = c10_t2 * c10_t4 * c10_t6;
  _SFD_SCRIPT_CALL(0, 37);
  c10_t15 = c10_t14 - c10_t23;
  _SFD_SCRIPT_CALL(0, 38);
  c10_s_x = c10_A5;
  c10_t16 = c10_s_x;
  c10_t_x = c10_t16;
  c10_t16 = c10_t_x;
  c10_t16 = muDoubleScalarCos(c10_t16);
  _SFD_SCRIPT_CALL(0, 39);
  c10_t17 = c10_t10 * c10_t11;
  _SFD_SCRIPT_CALL(0, 40);
  c10_t18 = c10_t12 * c10_t7;
  _SFD_SCRIPT_CALL(0, 41);
  c10_t19 = c10_t17 + c10_t18;
  _SFD_SCRIPT_CALL(0, 42);
  c10_u_x = c10_A6;
  c10_t20 = c10_u_x;
  c10_v_x = c10_t20;
  c10_t20 = c10_v_x;
  c10_t20 = muDoubleScalarSin(c10_t20);
  _SFD_SCRIPT_CALL(0, 43);
  c10_t21 = c10_t11 * c10_t12;
  _SFD_SCRIPT_CALL(0, 44);
  c10_w_x = c10_A6;
  c10_t22 = c10_w_x;
  c10_x_x = c10_t22;
  c10_t22 = c10_x_x;
  c10_t22 = muDoubleScalarCos(c10_t22);
  _SFD_SCRIPT_CALL(0, 45);
  c10_t24 = c10_t13 * c10_t15;
  _SFD_SCRIPT_CALL(0, 46);
  c10_t25 = c10_t16 * c10_t19;
  _SFD_SCRIPT_CALL(0, 47);
  c10_t26 = c10_t24 + c10_t25;
  _SFD_SCRIPT_CALL(0, 48);
  c10_t27 = c10_t12 * c10_t3 * c10_t5;
  _SFD_SCRIPT_CALL(0, 49);
  c10_t34 = c10_t12 * c10_t4 * c10_t6;
  _SFD_SCRIPT_CALL(0, 50);
  c10_t28 = c10_t27 - c10_t34;
  _SFD_SCRIPT_CALL(0, 51);
  c10_t29 = c10_t12 * c10_t3 * c10_t4;
  _SFD_SCRIPT_CALL(0, 52);
  c10_t30 = c10_t12 * c10_t5 * c10_t6;
  _SFD_SCRIPT_CALL(0, 53);
  c10_t31 = c10_t29 + c10_t30;
  _SFD_SCRIPT_CALL(0, 54);
  c10_t32 = c10_t11 * c10_t31;
  _SFD_SCRIPT_CALL(0, 55);
  c10_t36 = c10_t2 * c10_t7;
  _SFD_SCRIPT_CALL(0, 56);
  c10_t33 = c10_t32 - c10_t36;
  _SFD_SCRIPT_CALL(0, 57);
  c10_t35 = c10_t13 * c10_t28;
  _SFD_SCRIPT_CALL(0, 58);
  c10_t37 = c10_t16 * c10_t33;
  _SFD_SCRIPT_CALL(0, 59);
  c10_t38 = c10_t35 + c10_t37;
  _SFD_SCRIPT_CALL(0, 60);
  c10_t39 = c10_t31 * c10_t7;
  _SFD_SCRIPT_CALL(0, 61);
  c10_t40 = c10_t11 * c10_t2;
  _SFD_SCRIPT_CALL(0, 62);
  c10_t41 = c10_t39 + c10_t40;
  _SFD_SCRIPT_CALL(0, 63);
  c10_t42 = c10_t3 * c10_t4;
  _SFD_SCRIPT_CALL(0, 64);
  c10_t43 = c10_t5 * c10_t6;
  _SFD_SCRIPT_CALL(0, 65);
  c10_t44 = c10_t42 + c10_t43;
  _SFD_SCRIPT_CALL(0, 66);
  c10_t45 = c10_t3 * c10_t5;
  _SFD_SCRIPT_CALL(0, 67);
  c10_t47 = c10_t4 * c10_t6;
  _SFD_SCRIPT_CALL(0, 68);
  c10_t46 = c10_t45 - c10_t47;
  _SFD_SCRIPT_CALL(0, 69);
  c10_t48 = c10_t13 * c10_t44;
  _SFD_SCRIPT_CALL(0, 70);
  c10_t49 = c10_t48 - c10_t11 * c10_t16 * c10_t46;
  _SFD_SCRIPT_CALL(0, 71);
  c10_y_x[0] = c10_t15 * c10_t16 - c10_t13 * c10_t19;
  c10_y_x[1] = c10_t16 * c10_t28 - c10_t13 * c10_t33;
  c10_y_x[2] = (-c10_t16) * c10_t44 - c10_t11 * c10_t13 * c10_t46;
  c10_y_x[3] = 0.0;
  c10_y_x[4] = c10_t20 * c10_t26 - c10_t22 * (c10_t21 - c10_t10 * c10_t7);
  c10_y_x[5] = c10_t20 * c10_t38 + c10_t22 * c10_t41;
  c10_y_x[6] = (-c10_t20) * c10_t49 + c10_t22 * c10_t46 * c10_t7;
  c10_y_x[7] = 0.0;
  c10_y_x[8] = c10_t22 * c10_t26 + c10_t20 * (c10_t21 - c10_t10 * c10_t7);
  c10_y_x[9] = c10_t22 * c10_t38 - c10_t20 * c10_t41;
  c10_y_x[10] = (-c10_t22) * c10_t49 - c10_t20 * c10_t46 * c10_t7;
  c10_y_x[11] = 0.0;
  c10_y_x[12] = ((((((((((((((((((((((((((((((c10_L2 * c10_t2 + c10_L3 * c10_t2 *
    c10_t6) - c10_L8 * c10_t11 * c10_t12 * c10_t22) +
    c10_L4 * c10_t2 * c10_t3 * c10_t4) + c10_L9 * c10_t11 * c10_t12 * c10_t20) +
    c10_L5 * c10_t2 * c10_t3 * c10_t5) - c10_L6 * c10_t12
    * c10_t13 * c10_t7) - c10_L7 * c10_t12 * c10_t13 * c10_t7) + c10_L4 * c10_t2
    * c10_t5 * c10_t6) - c10_L5 * c10_t2 * c10_t4 * c10_t6
    ) + c10_L6 * c10_t16 * c10_t2 * c10_t3 * c10_t5) + c10_L7 * c10_t16 * c10_t2
    * c10_t3 * c10_t5) - c10_L6 * c10_t16 * c10_t2 * c10_t4
    * c10_t6) + c10_L8 * c10_t12 * c10_t16 * c10_t20 * c10_t7) - c10_L7 *
    c10_t16 * c10_t2 * c10_t4 * c10_t6) + c10_L9 * c10_t12 *
    c10_t16 * c10_t22 * c10_t7) - c10_L6 * c10_t11 * c10_t13 * c10_t2 * c10_t3 *
    c10_t4) - c10_L7 * c10_t11 * c10_t13 * c10_t2 * c10_t3
    * c10_t4) + c10_L8 * c10_t13 * c10_t2 * c10_t20 * c10_t3 * c10_t5) - c10_L6 *
    c10_t11 * c10_t13 * c10_t2 * c10_t5 * c10_t6) -
    c10_L7 * c10_t11 * c10_t13 * c10_t2 * c10_t5 * c10_t6) + c10_L9 * c10_t13 *
    c10_t2 * c10_t22 * c10_t3 * c10_t5) - c10_L8 * c10_t13
    * c10_t2 * c10_t20 * c10_t4 * c10_t6) - c10_L9 * c10_t13 * c10_t2 * c10_t22 *
                        c10_t4 * c10_t6) + c10_L8 * c10_t2 * c10_t22 * c10_t3
                       * c10_t4 * c10_t7) - c10_L9 * c10_t2 * c10_t20 * c10_t3 *
                      c10_t4 * c10_t7) + c10_L8 * c10_t2 * c10_t22 * c10_t5 *
                     c10_t6 * c10_t7)
                    - c10_L9 * c10_t2 * c10_t20 * c10_t5 * c10_t6 * c10_t7) +
                   c10_L8 * c10_t11 * c10_t16 * c10_t2 * c10_t20 * c10_t3 *
                   c10_t4) + c10_L9
                  * c10_t11 * c10_t16 * c10_t2 * c10_t22 * c10_t3 * c10_t4) +
                 c10_L8 * c10_t11 * c10_t16 * c10_t2 * c10_t20 * c10_t5 * c10_t6)
    +
    c10_L9 * c10_t11 * c10_t16 * c10_t2 * c10_t22 * c10_t5 * c10_t6;
  c10_y_x[13] = ((((((((((((((((((((((((((((((c10_L2 * c10_t12 + c10_L3 *
    c10_t12 * c10_t6) + c10_L4 * c10_t12 * c10_t3 * c10_t4) +
    c10_L8 * c10_t11 * c10_t2 * c10_t22) + c10_L5 * c10_t12 * c10_t3 * c10_t5) -
    c10_L9 * c10_t11 * c10_t2 * c10_t20) + c10_L4 * c10_t12
    * c10_t5 * c10_t6) - c10_L5 * c10_t12 * c10_t4 * c10_t6) + c10_L6 * c10_t13 *
    c10_t2 * c10_t7) + c10_L7 * c10_t13 * c10_t2 * c10_t7
    ) + c10_L6 * c10_t12 * c10_t16 * c10_t3 * c10_t5) + c10_L7 * c10_t12 *
    c10_t16 * c10_t3 * c10_t5) - c10_L6 * c10_t12 * c10_t16 *
    c10_t4 * c10_t6) - c10_L7 * c10_t12 * c10_t16 * c10_t4 * c10_t6) - c10_L8 *
    c10_t16 * c10_t2 * c10_t20 * c10_t7) - c10_L9 * c10_t16
    * c10_t2 * c10_t22 * c10_t7) - c10_L6 * c10_t11 * c10_t12 * c10_t13 * c10_t3
    * c10_t4) - c10_L7 * c10_t11 * c10_t12 * c10_t13 *
    c10_t3 * c10_t4) + c10_L8 * c10_t12 * c10_t13 * c10_t20 * c10_t3 * c10_t5) -
    c10_L6 * c10_t11 * c10_t12 * c10_t13 * c10_t5 * c10_t6)
    - c10_L7 * c10_t11 * c10_t12 * c10_t13 * c10_t5 * c10_t6) + c10_L9 * c10_t12
    * c10_t13 * c10_t22 * c10_t3 * c10_t5) - c10_L8 *
    c10_t12 * c10_t13 * c10_t20 * c10_t4 * c10_t6) - c10_L9 * c10_t12 * c10_t13 *
                        c10_t22 * c10_t4 * c10_t6) + c10_L8 * c10_t12 *
                       c10_t22 * c10_t3 * c10_t4 * c10_t7) - c10_L9 * c10_t12 *
                      c10_t20 * c10_t3 * c10_t4 * c10_t7) + c10_L8 * c10_t12 *
                     c10_t22 * c10_t5
                     * c10_t6 * c10_t7) - c10_L9 * c10_t12 * c10_t20 * c10_t5 *
                    c10_t6 * c10_t7) + c10_L8 * c10_t11 * c10_t12 * c10_t16 *
                   c10_t20 *
                   c10_t3 * c10_t4) + c10_L9 * c10_t11 * c10_t12 * c10_t16 *
                  c10_t22 * c10_t3 * c10_t4) + c10_L8 * c10_t11 * c10_t12 *
                 c10_t16 *
                 c10_t20 * c10_t5 * c10_t6) + c10_L9 * c10_t11 * c10_t12 *
    c10_t16 * c10_t22 * c10_t5 * c10_t6;
  c10_y_x[14] = ((((((((((((((((((((((((c10_L1 + c10_L3 * c10_t3) + c10_L4 *
    c10_t3 * c10_t5) - c10_L5 * c10_t3 * c10_t4) - c10_L4 *
    c10_t4 * c10_t6) - c10_L5 * c10_t5 * c10_t6) - c10_L6 * c10_t16 * c10_t3 *
    c10_t4) - c10_L7 * c10_t16 * c10_t3 * c10_t4) - c10_L6 *
    c10_t16 * c10_t5 * c10_t6) - c10_L7 * c10_t16 * c10_t5 * c10_t6) - c10_L6 *
    c10_t11 * c10_t13 * c10_t3 * c10_t5) - c10_L7 * c10_t11
    * c10_t13 * c10_t3 * c10_t5) - c10_L8 * c10_t13 * c10_t20 * c10_t3 * c10_t4)
    + c10_L6 * c10_t11 * c10_t13 * c10_t4 * c10_t6) +
    c10_L7 * c10_t11 * c10_t13 * c10_t4 * c10_t6) - c10_L9 * c10_t13 * c10_t22 *
    c10_t3 * c10_t4) - c10_L8 * c10_t13 * c10_t20 * c10_t5
    * c10_t6) - c10_L9 * c10_t13 * c10_t22 * c10_t5 * c10_t6) + c10_L8 * c10_t22
                       * c10_t3 * c10_t5 * c10_t7) - c10_L9 * c10_t20 *
                      c10_t3 * c10_t5 * c10_t7) - c10_L8 * c10_t22 * c10_t4 *
                     c10_t6 * c10_t7) + c10_L9 * c10_t20 * c10_t4 * c10_t6 *
                    c10_t7) + c10_L8 *
                   c10_t11 * c10_t16 * c10_t20 * c10_t3 * c10_t5) + c10_L9 *
                  c10_t11 * c10_t16 * c10_t22 * c10_t3 * c10_t5) - c10_L8 *
                 c10_t11 *
                 c10_t16 * c10_t20 * c10_t4 * c10_t6) - c10_L9 * c10_t11 *
    c10_t16 * c10_t22 * c10_t4 * c10_t6;
  c10_y_x[15] = 1.0;
  for (c10_k = 1; c10_k < 17; c10_k = c10_k + 1) {
    c10_b_k = c10_k;
    c10_gst[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c10_b_k), 1, 16, 1, 0) - 1] = c10_y_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c10_b_k), 1, 16, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0, -71);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c10_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i16;
  real_T c10_b_u[3];
  int32_T c10_i17;
  real_T c10_c_u[3];
  const mxArray *c10_b_y = NULL;
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  for (c10_i16 = 0; c10_i16 < 3; c10_i16 = c10_i16 + 1) {
    c10_b_u[c10_i16] = (*((real_T (*)[3])c10_u))[c10_i16];
  }

  for (c10_i17 = 0; c10_i17 < 3; c10_i17 = c10_i17 + 1) {
    c10_c_u[c10_i17] = c10_b_u[c10_i17];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_b_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i18;
  real_T c10_b_u[9];
  int32_T c10_i19;
  real_T c10_c_u[9];
  const mxArray *c10_b_y = NULL;
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  for (c10_i18 = 0; c10_i18 < 9; c10_i18 = c10_i18 + 1) {
    c10_b_u[c10_i18] = (*((real_T (*)[9])c10_u))[c10_i18];
  }

  for (c10_i19 = 0; c10_i19 < 9; c10_i19 = c10_i19 + 1) {
    c10_c_u[c10_i19] = c10_b_u[c10_i19];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_c_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i20;
  real_T c10_b_u[6];
  int32_T c10_i21;
  real_T c10_c_u[6];
  const mxArray *c10_b_y = NULL;
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  for (c10_i20 = 0; c10_i20 < 6; c10_i20 = c10_i20 + 1) {
    c10_b_u[c10_i20] = (*((real_T (*)[6])c10_u))[c10_i20];
  }

  for (c10_i21 = 0; c10_i21 < 6; c10_i21 = c10_i21 + 1) {
    c10_c_u[c10_i21] = c10_b_u[c10_i21];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_d_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  real_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  c10_b_u = *((real_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_e_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i22;
  int32_T c10_i23;
  int32_T c10_i24;
  real_T c10_b_u[16];
  int32_T c10_i25;
  int32_T c10_i26;
  int32_T c10_i27;
  real_T c10_c_u[16];
  const mxArray *c10_b_y = NULL;
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  c10_i22 = 0;
  for (c10_i23 = 0; c10_i23 < 4; c10_i23 = c10_i23 + 1) {
    for (c10_i24 = 0; c10_i24 < 4; c10_i24 = c10_i24 + 1) {
      c10_b_u[c10_i24 + c10_i22] = (*((real_T (*)[16])c10_u))[c10_i24 + c10_i22];
    }

    c10_i22 = c10_i22 + 4;
  }

  c10_i25 = 0;
  for (c10_i26 = 0; c10_i26 < 4; c10_i26 = c10_i26 + 1) {
    for (c10_i27 = 0; c10_i27 < 4; c10_i27 = c10_i27 + 1) {
      c10_c_u[c10_i27 + c10_i25] = c10_b_u[c10_i27 + c10_i25];
    }

    c10_i25 = c10_i25 + 4;
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static const mxArray *c10_f_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  int32_T c10_i28;
  real_T c10_b_u[6];
  int32_T c10_i29;
  real_T c10_c_u[6];
  const mxArray *c10_b_y = NULL;
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  for (c10_i28 = 0; c10_i28 < 6; c10_i28 = c10_i28 + 1) {
    c10_b_u[c10_i28] = (*((real_T (*)[6])c10_u))[c10_i28];
  }

  for (c10_i29 = 0; c10_i29 < 6; c10_i29 = c10_i29 + 1) {
    c10_c_u[c10_i29] = c10_b_u[c10_i29];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

const mxArray *sf_c10_DynJointCon_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo = NULL;
  c10_ResolvedFunctionInfo c10_info[39];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i30;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_info_helper(c10_info);
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 39));
  for (c10_i30 = 0; c10_i30 < 39; c10_i30 = c10_i30 + 1) {
    c10_r0 = &c10_info[c10_i30];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context"
                    , "nameCaptureInfo", c10_i30);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name",
                    "nameCaptureInfo", c10_i30);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i30);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)),
                    "resolved", "nameCaptureInfo", c10_i30);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c10_i30);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c10_i30);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c10_i30);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0);
  return c10_nameCaptureInfo;
}

static void c10_info_helper(c10_ResolvedFunctionInfo c10_info[39])
{
  c10_info[0].context = "";
  c10_info[0].name = "ctranspose";
  c10_info[0].dominantType = "double";
  c10_info[0].resolved = "[B]ctranspose";
  c10_info[0].fileLength = 0U;
  c10_info[0].fileTime1 = 0U;
  c10_info[0].fileTime2 = 0U;
  c10_info[1].context = "";
  c10_info[1].name = "fwd_kin";
  c10_info[1].dominantType = "double";
  c10_info[1].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[1].fileLength = 3324U;
  c10_info[1].fileTime1 = 1366778959U;
  c10_info[1].fileTime2 = 0U;
  c10_info[2].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[2].name = "cos";
  c10_info[2].dominantType = "double";
  c10_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[2].fileLength = 324U;
  c10_info[2].fileTime1 = 1203422750U;
  c10_info[2].fileTime2 = 0U;
  c10_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[3].name = "nargin";
  c10_info[3].dominantType = "";
  c10_info[3].resolved = "[B]nargin";
  c10_info[3].fileLength = 0U;
  c10_info[3].fileTime1 = 0U;
  c10_info[3].fileTime2 = 0U;
  c10_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[4].name = "gt";
  c10_info[4].dominantType = "double";
  c10_info[4].resolved = "[B]gt";
  c10_info[4].fileLength = 0U;
  c10_info[4].fileTime1 = 0U;
  c10_info[4].fileTime2 = 0U;
  c10_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[5].name = "isa";
  c10_info[5].dominantType = "double";
  c10_info[5].resolved = "[B]isa";
  c10_info[5].fileLength = 0U;
  c10_info[5].fileTime1 = 0U;
  c10_info[5].fileTime2 = 0U;
  c10_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c10_info[6].name = "eml_scalar_cos";
  c10_info[6].dominantType = "double";
  c10_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c10_info[6].fileLength = 602U;
  c10_info[6].fileTime1 = 1209309186U;
  c10_info[6].fileTime2 = 0U;
  c10_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c10_info[7].name = "isreal";
  c10_info[7].dominantType = "double";
  c10_info[7].resolved = "[B]isreal";
  c10_info[7].fileLength = 0U;
  c10_info[7].fileTime1 = 0U;
  c10_info[7].fileTime2 = 0U;
  c10_info[8].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[8].name = "sin";
  c10_info[8].dominantType = "double";
  c10_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c10_info[8].fileLength = 324U;
  c10_info[8].fileTime1 = 1203422842U;
  c10_info[8].fileTime2 = 0U;
  c10_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c10_info[9].name = "eml_scalar_sin";
  c10_info[9].dominantType = "double";
  c10_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c10_info[9].fileLength = 601U;
  c10_info[9].fileTime1 = 1209309190U;
  c10_info[9].fileTime2 = 0U;
  c10_info[10].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[10].name = "times";
  c10_info[10].dominantType = "double";
  c10_info[10].resolved = "[B]times";
  c10_info[10].fileLength = 0U;
  c10_info[10].fileTime1 = 0U;
  c10_info[10].fileTime2 = 0U;
  c10_info[11].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[11].name = "plus";
  c10_info[11].dominantType = "double";
  c10_info[11].resolved = "[B]plus";
  c10_info[11].fileLength = 0U;
  c10_info[11].fileTime1 = 0U;
  c10_info[11].fileTime2 = 0U;
  c10_info[12].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[12].name = "minus";
  c10_info[12].dominantType = "double";
  c10_info[12].resolved = "[B]minus";
  c10_info[12].fileLength = 0U;
  c10_info[12].fileTime1 = 0U;
  c10_info[12].fileTime2 = 0U;
  c10_info[13].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[13].name = "uminus";
  c10_info[13].dominantType = "double";
  c10_info[13].resolved = "[B]uminus";
  c10_info[13].fileLength = 0U;
  c10_info[13].fileTime1 = 0U;
  c10_info[13].fileTime2 = 0U;
  c10_info[14].context = "[E]D:/Learn/Project_Matlab/Fanuc/fwd_kin.m";
  c10_info[14].name = "reshape";
  c10_info[14].dominantType = "double";
  c10_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c10_info[14].fileLength = 4857U;
  c10_info[14].fileTime1 = 1242276774U;
  c10_info[14].fileTime2 = 0U;
  c10_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c10_info[15].name = "eml_index_class";
  c10_info[15].dominantType = "";
  c10_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c10_info[15].fileLength = 909U;
  c10_info[15].fileTime1 = 1192445182U;
  c10_info[15].fileTime2 = 0U;
  c10_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c10_info[16].name = "cast";
  c10_info[16].dominantType = "double";
  c10_info[16].resolved = "[B]cast";
  c10_info[16].fileLength = 0U;
  c10_info[16].fileTime1 = 0U;
  c10_info[16].fileTime2 = 0U;
  c10_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c10_info[17].name = "size";
  c10_info[17].dominantType = "double";
  c10_info[17].resolved = "[B]size";
  c10_info[17].fileLength = 0U;
  c10_info[17].fileTime1 = 0U;
  c10_info[17].fileTime2 = 0U;
  c10_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c10_info[18].name = "eq";
  c10_info[18].dominantType = "double";
  c10_info[18].resolved = "[B]eq";
  c10_info[18].fileLength = 0U;
  c10_info[18].fileTime1 = 0U;
  c10_info[18].fileTime2 = 0U;
  c10_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c10_info[19].name = "eml_assert_valid_size_arg";
  c10_info[19].dominantType = "double";
  c10_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c10_info[19].fileLength = 3315U;
  c10_info[19].fileTime1 = 1256367816U;
  c10_info[19].fileTime2 = 0U;
  c10_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c10_info[20].name = "false";
  c10_info[20].dominantType = "";
  c10_info[20].resolved = "[B]false";
  c10_info[20].fileLength = 0U;
  c10_info[20].fileTime1 = 0U;
  c10_info[20].fileTime2 = 0U;
  c10_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c10_info[21].name = "not";
  c10_info[21].dominantType = "logical";
  c10_info[21].resolved = "[B]not";
  c10_info[21].fileLength = 0U;
  c10_info[21].fileTime1 = 0U;
  c10_info[21].fileTime2 = 0U;
  c10_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c10_info[22].name = "isvector";
  c10_info[22].dominantType = "double";
  c10_info[22].resolved = "[B]isvector";
  c10_info[22].fileLength = 0U;
  c10_info[22].fileTime1 = 0U;
  c10_info[22].fileTime2 = 0U;
  c10_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c10_info[23].name = "isinteger";
  c10_info[23].dominantType = "double";
  c10_info[23].resolved = "[B]isinteger";
  c10_info[23].fileLength = 0U;
  c10_info[23].fileTime1 = 0U;
  c10_info[23].fileTime2 = 0U;
  c10_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c10_info[24].name = "ne";
  c10_info[24].dominantType = "double";
  c10_info[24].resolved = "[B]ne";
  c10_info[24].fileLength = 0U;
  c10_info[24].fileTime1 = 0U;
  c10_info[24].fileTime2 = 0U;
  c10_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c10_info[25].name = "isinf";
  c10_info[25].dominantType = "double";
  c10_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c10_info[25].fileLength = 541U;
  c10_info[25].fileTime1 = 1271383988U;
  c10_info[25].fileTime2 = 0U;
  c10_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c10_info[26].name = "true";
  c10_info[26].dominantType = "";
  c10_info[26].resolved = "[B]true";
  c10_info[26].fileLength = 0U;
  c10_info[26].fileTime1 = 0U;
  c10_info[26].fileTime2 = 0U;
  c10_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c10_info[27].name = "le";
  c10_info[27].dominantType = "double";
  c10_info[27].resolved = "[B]le";
  c10_info[27].fileLength = 0U;
  c10_info[27].fileTime1 = 0U;
  c10_info[27].fileTime2 = 0U;
  c10_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c10_info[28].name = "double";
  c10_info[28].dominantType = "double";
  c10_info[28].resolved = "[B]double";
  c10_info[28].fileLength = 0U;
  c10_info[28].fileTime1 = 0U;
  c10_info[28].fileTime2 = 0U;
  c10_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c10_info[29].name = "mtimes";
  c10_info[29].dominantType = "double";
  c10_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[29].fileLength = 3425U;
  c10_info[29].fileTime1 = 1251010272U;
  c10_info[29].fileTime2 = 0U;
  c10_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[30].name = "isscalar";
  c10_info[30].dominantType = "double";
  c10_info[30].resolved = "[B]isscalar";
  c10_info[30].fileLength = 0U;
  c10_info[30].fileTime1 = 0U;
  c10_info[30].fileTime2 = 0U;
  c10_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[31].name = "strcmp";
  c10_info[31].dominantType = "char";
  c10_info[31].resolved = "[B]strcmp";
  c10_info[31].fileLength = 0U;
  c10_info[31].fileTime1 = 0U;
  c10_info[31].fileTime2 = 0U;
  c10_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c10_info[32].name = "class";
  c10_info[32].dominantType = "double";
  c10_info[32].resolved = "[B]class";
  c10_info[32].fileLength = 0U;
  c10_info[32].fileTime1 = 0U;
  c10_info[32].fileTime2 = 0U;
  c10_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c10_info[33].name = "intmax";
  c10_info[33].dominantType = "char";
  c10_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c10_info[33].fileLength = 1535U;
  c10_info[33].fileTime1 = 1192445128U;
  c10_info[33].fileTime2 = 0U;
  c10_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c10_info[34].name = "ischar";
  c10_info[34].dominantType = "char";
  c10_info[34].resolved = "[B]ischar";
  c10_info[34].fileLength = 0U;
  c10_info[34].fileTime1 = 0U;
  c10_info[34].fileTime2 = 0U;
  c10_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c10_info[35].name = "int32";
  c10_info[35].dominantType = "double";
  c10_info[35].resolved = "[B]int32";
  c10_info[35].fileLength = 0U;
  c10_info[35].fileTime1 = 0U;
  c10_info[35].fileTime2 = 0U;
  c10_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c10_info[36].name = "eml_scalar_eg";
  c10_info[36].dominantType = "double";
  c10_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[36].fileLength = 3068U;
  c10_info[36].fileTime1 = 1240240410U;
  c10_info[36].fileTime2 = 0U;
  c10_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c10_info[37].name = "isstruct";
  c10_info[37].dominantType = "double";
  c10_info[37].resolved = "[B]isstruct";
  c10_info[37].fileLength = 0U;
  c10_info[37].fileTime1 = 0U;
  c10_info[37].fileTime2 = 0U;
  c10_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c10_info[38].name = "ones";
  c10_info[38].dominantType = "char";
  c10_info[38].resolved = "[B]ones";
  c10_info[38].fileLength = 0U;
  c10_info[38].fileTime1 = 0U;
  c10_info[38].fileTime2 = 0U;
}

static const mxArray *c10_g_sf_marshall(void *chartInstanceVoid, void *c10_u)
{
  const mxArray *c10_y = NULL;
  boolean_T c10_b_u;
  const mxArray *c10_b_y = NULL;
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)chartInstanceVoid;
  c10_y = NULL;
  c10_b_u = *((boolean_T *)c10_u);
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c10_y, c10_b_y);
  return c10_y;
}

static void c10_emlrt_marshallIn(SFc10_DynJointConInstanceStruct *chartInstance,
  const mxArray *c10_EndPos, const char_T *c10_name,
  real_T c10_y[3])
{
  real_T c10_dv3[3];
  int32_T c10_i31;
  sf_mex_import(c10_name, sf_mex_dup(c10_EndPos), c10_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c10_i31 = 0; c10_i31 < 3; c10_i31 = c10_i31 + 1) {
    c10_y[c10_i31] = c10_dv3[c10_i31];
  }

  sf_mex_destroy(&c10_EndPos);
}

static uint8_T c10_b_emlrt_marshallIn(SFc10_DynJointConInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_DynJointCon
  , const char_T *c10_name)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_name, sf_mex_dup(c10_b_is_active_c10_DynJointCon), &c10_u0,
                1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_b_is_active_c10_DynJointCon);
  return c10_y;
}

static void init_dsm_address_info(SFc10_DynJointConInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c10_DynJointCon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3049321950U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(987706000U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2834568350U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(132016629U);
}

mxArray *sf_c10_DynJointCon_get_autoinheritance_info(void)
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

static mxArray *sf_get_sim_state_info_c10_DynJointCon(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"EndPos\",},{M[8],M[0],T\"is_active_c10_DynJointCon\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_DynJointCon_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_DynJointConInstanceStruct *chartInstance;
    chartInstance = (SFc10_DynJointConInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_DynJointConMachineNumber_,
           10,
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
          init_script_number_translation(_DynJointConMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_DynJointConMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_DynJointConMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c10_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c10_b_sf_marshall);
        }

        {
          real_T (*c10_Theta)[6];
          real_T (*c10_EndPos)[3];
          c10_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c10_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c10_Theta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c10_EndPos);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c10_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_DynJointConMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c10_DynJointCon(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_DynJointConInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_DynJointCon((SFc10_DynJointConInstanceStruct*)
    chartInstanceVar);
  initialize_c10_DynJointCon((SFc10_DynJointConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c10_DynJointCon(void *chartInstanceVar)
{
  enable_c10_DynJointCon((SFc10_DynJointConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c10_DynJointCon(void *chartInstanceVar)
{
  disable_c10_DynJointCon((SFc10_DynJointConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c10_DynJointCon(void *chartInstanceVar)
{
  sf_c10_DynJointCon((SFc10_DynJointConInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c10_DynJointCon(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_DynJointCon
    ((SFc10_DynJointConInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c10_DynJointCon();/* state var info */
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

static void sf_internal_set_sim_state_c10_DynJointCon(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_DynJointCon();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_DynJointCon((SFc10_DynJointConInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c10_DynJointCon(SimStruct* S)
{
  return sf_internal_get_sim_state_c10_DynJointCon(S);
}

static void sf_opaque_set_sim_state_c10_DynJointCon(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c10_DynJointCon(S, st);
}

static void sf_opaque_terminate_c10_DynJointCon(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_DynJointConInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c10_DynJointCon((SFc10_DynJointConInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c10_DynJointCon((SFc10_DynJointConInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_DynJointCon(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_DynJointCon((SFc10_DynJointConInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_DynJointCon(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(S,"DynJointCon","DynJointCon",10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DynJointCon","DynJointCon",10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DynJointCon",
      "DynJointCon",10,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DynJointCon","DynJointCon",10,1);
      sf_mark_chart_reusable_outputs(S,"DynJointCon","DynJointCon",10,1);
    }

    sf_set_rtw_dwork_info(S,"DynJointCon","DynJointCon",10);
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

static void mdlRTW_c10_DynJointCon(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DynJointCon", "DynJointCon",10);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_DynJointCon(SimStruct *S)
{
  SFc10_DynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc10_DynJointConInstanceStruct *)malloc(sizeof
    (SFc10_DynJointConInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_DynJointConInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c10_DynJointCon;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_DynJointCon;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c10_DynJointCon;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_DynJointCon;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c10_DynJointCon;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c10_DynJointCon;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c10_DynJointCon;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_DynJointCon;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_DynJointCon;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_DynJointCon;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c10_DynJointCon;
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

void c10_DynJointCon_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_DynJointCon(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_DynJointCon(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_DynJointCon(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_DynJointCon_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
