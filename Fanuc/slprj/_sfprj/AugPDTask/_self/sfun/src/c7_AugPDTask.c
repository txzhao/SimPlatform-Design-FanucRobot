/* Include files */

#include "blascompat32.h"
#include "AugPDTask_sfun.h"
#include "c7_AugPDTask.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AugPDTask_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c7_debug_family_names[5] = { "nargin", "nargout", "EnTheta",
  "L", "T_J" };

static const char *c7_b_debug_family_names[64] = { "A1", "A2", "A3", "A4", "A5",
  "L1", "L2", "L3", "L4", "L5", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9",
  "t10", "t11", "t12", "t13", "t14", "t15", "t16", "t17", "t18", "t19", "t20",
  "t21", "t22", "t23", "t24", "t25", "t26", "t27", "t28", "t29", "t30", "t31",
  "t32", "t33", "t34", "t35", "t36", "t37", "t38", "t47", "t39", "t40", "t41",
  "t42", "t43", "t44", "t45", "t46", "t48", "t49", "t50", "nargin", "nargout",
  "in1", "in2", "spat_Jacobian" };

/* Function Declarations */
static void initialize_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance);
static void initialize_params_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance);
static void enable_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance);
static void disable_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance);
static void set_sim_state_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void finalize_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance);
static void sf_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c7_AugPDTask
  (SFc7_AugPDTaskInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static void c7_spat_Jacobian(SFc7_AugPDTaskInstanceStruct *chartInstance, real_T
  c7_in1[9], real_T c7_in2[6], real_T c7_b_spat_Jacobian[36]);
static const mxArray *c7_sf_marshall(void *chartInstanceVoid, void *c7_u);
static const mxArray *c7_b_sf_marshall(void *chartInstanceVoid, void *c7_u);
static const mxArray *c7_c_sf_marshall(void *chartInstanceVoid, void *c7_u);
static const mxArray *c7_d_sf_marshall(void *chartInstanceVoid, void *c7_u);
static const mxArray *c7_e_sf_marshall(void *chartInstanceVoid, void *c7_u);
static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[48]);
static const mxArray *c7_f_sf_marshall(void *chartInstanceVoid, void *c7_u);
static void c7_emlrt_marshallIn(SFc7_AugPDTaskInstanceStruct *chartInstance,
  const mxArray *c7_T_J, const char_T *c7_name, real_T c7_y[36]);
static uint8_T c7_b_emlrt_marshallIn(SFc7_AugPDTaskInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_AugPDTask, const char_T *c7_name);
static void init_dsm_address_info(SFc7_AugPDTaskInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c7_is_active_c7_AugPDTask = 0U;
}

static void initialize_params_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance)
{
  real_T c7_dv0[9];
  int32_T c7_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c7_dv0, 0, 0,
                0U, 1, 0U, 2, 1, 9);
  for (c7_i0 = 0; c7_i0 < 9; c7_i0 = c7_i0 + 1) {
    chartInstance->c7_L[c7_i0] = c7_dv0[c7_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance)
{
  const mxArray *c7_st = NULL;
  const mxArray *c7_y = NULL;
  int32_T c7_i1;
  real_T c7_hoistedGlobal[36];
  int32_T c7_i2;
  real_T c7_u[36];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_b_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  real_T (*c7_T_J)[36];
  c7_T_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2));
  for (c7_i1 = 0; c7_i1 < 36; c7_i1 = c7_i1 + 1) {
    c7_hoistedGlobal[c7_i1] = (*c7_T_J)[c7_i1];
  }

  for (c7_i2 = 0; c7_i2 < 36; c7_i2 = c7_i2 + 1) {
    c7_u[c7_i2] = c7_hoistedGlobal[c7_i2];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = chartInstance->c7_is_active_c7_AugPDTask;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y);
  return c7_st;
}

static void set_sim_state_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T c7_dv1[36];
  int32_T c7_i3;
  real_T (*c7_T_J)[36];
  c7_T_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "T_J",
                      c7_dv1);
  for (c7_i3 = 0; c7_i3 < 36; c7_i3 = c7_i3 + 1) {
    (*c7_T_J)[c7_i3] = c7_dv1[c7_i3];
  }

  chartInstance->c7_is_active_c7_AugPDTask = c7_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 1)),
    "is_active_c7_AugPDTask");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_AugPDTask(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance)
{
}

static void sf_c7_AugPDTask(SFc7_AugPDTaskInstanceStruct *chartInstance)
{
  int32_T c7_i4;
  int32_T c7_i5;
  int32_T c7_i6;
  int32_T c7_previousEvent;
  int32_T c7_i7;
  real_T c7_hoistedGlobal[6];
  int32_T c7_i8;
  real_T c7_b_hoistedGlobal[9];
  int32_T c7_i9;
  real_T c7_EnTheta[6];
  int32_T c7_i10;
  real_T c7_b_L[9];
  uint32_T c7_debug_family_var_map[5];
  real_T c7_nargin = 2.0;
  real_T c7_nargout = 1.0;
  real_T c7_T_J[36];
  int32_T c7_i11;
  real_T c7_A[9];
  int32_T c7_i12;
  real_T c7_x[9];
  int32_T c7_i13;
  real_T c7_b_x[9];
  int32_T c7_i14;
  real_T c7_c_x[9];
  int32_T c7_i15;
  real_T c7_y[9];
  int32_T c7_i16;
  real_T c7_b_y[9];
  int32_T c7_i17;
  real_T c7_b_EnTheta[6];
  real_T c7_dv2[36];
  int32_T c7_i18;
  int32_T c7_i19;
  int32_T c7_i20;
  int32_T c7_i21;
  int32_T c7_i22;
  real_T (*c7_b_T_J)[36];
  real_T (*c7_c_EnTheta)[6];
  c7_b_T_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_c_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6);
  for (c7_i4 = 0; c7_i4 < 6; c7_i4 = c7_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_c_EnTheta)[c7_i4], 0U);
  }

  for (c7_i5 = 0; c7_i5 < 36; c7_i5 = c7_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c7_b_T_J)[c7_i5], 1U);
  }

  for (c7_i6 = 0; c7_i6 < 9; c7_i6 = c7_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c7_L[c7_i6], 2U);
  }

  c7_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6);
  for (c7_i7 = 0; c7_i7 < 6; c7_i7 = c7_i7 + 1) {
    c7_hoistedGlobal[c7_i7] = (*c7_c_EnTheta)[c7_i7];
  }

  for (c7_i8 = 0; c7_i8 < 9; c7_i8 = c7_i8 + 1) {
    c7_b_hoistedGlobal[c7_i8] = chartInstance->c7_L[c7_i8];
  }

  for (c7_i9 = 0; c7_i9 < 6; c7_i9 = c7_i9 + 1) {
    c7_EnTheta[c7_i9] = c7_hoistedGlobal[c7_i9];
  }

  for (c7_i10 = 0; c7_i10 < 9; c7_i10 = c7_i10 + 1) {
    c7_b_L[c7_i10] = c7_b_hoistedGlobal[c7_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c7_nargin, c7_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c7_nargout, c7_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c7_EnTheta, c7_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c7_b_L, c7_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c7_T_J, c7_sf_marshall, 4U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  for (c7_i11 = 0; c7_i11 < 9; c7_i11 = c7_i11 + 1) {
    c7_A[c7_i11] = c7_b_L[c7_i11];
  }

  for (c7_i12 = 0; c7_i12 < 9; c7_i12 = c7_i12 + 1) {
    c7_x[c7_i12] = c7_A[c7_i12];
  }

  for (c7_i13 = 0; c7_i13 < 9; c7_i13 = c7_i13 + 1) {
    c7_b_x[c7_i13] = c7_x[c7_i13];
  }

  for (c7_i14 = 0; c7_i14 < 9; c7_i14 = c7_i14 + 1) {
    c7_c_x[c7_i14] = c7_b_x[c7_i14];
  }

  for (c7_i15 = 0; c7_i15 < 9; c7_i15 = c7_i15 + 1) {
    c7_y[c7_i15] = c7_c_x[c7_i15] / 1000.0;
  }

  for (c7_i16 = 0; c7_i16 < 9; c7_i16 = c7_i16 + 1) {
    c7_b_y[c7_i16] = c7_y[c7_i16];
  }

  for (c7_i17 = 0; c7_i17 < 6; c7_i17 = c7_i17 + 1) {
    c7_b_EnTheta[c7_i17] = c7_EnTheta[c7_i17];
  }

  c7_spat_Jacobian(chartInstance, c7_b_y, c7_b_EnTheta, c7_dv2);
  c7_i18 = 0;
  for (c7_i19 = 0; c7_i19 < 6; c7_i19 = c7_i19 + 1) {
    c7_i20 = 0;
    for (c7_i21 = 0; c7_i21 < 6; c7_i21 = c7_i21 + 1) {
      c7_T_J[c7_i21 + c7_i18] = c7_dv2[c7_i20 + c7_i19];
      c7_i20 = c7_i20 + 6;
    }

    c7_i18 = c7_i18 + 6;
  }

  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  for (c7_i22 = 0; c7_i22 < 36; c7_i22 = c7_i22 + 1) {
    (*c7_b_T_J)[c7_i22] = c7_T_J[c7_i22];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6);
  _sfEvent_ = c7_previousEvent;
  sf_debug_check_for_state_inconsistency(_AugPDTaskMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c7_AugPDTask
  (SFc7_AugPDTaskInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c7_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m"));
}

static void c7_spat_Jacobian(SFc7_AugPDTaskInstanceStruct *chartInstance, real_T
  c7_in1[9], real_T c7_in2[6], real_T
  c7_b_spat_Jacobian[36])
{
  uint32_T c7_debug_family_var_map[64];
  real_T c7_A1;
  real_T c7_A2;
  real_T c7_A3;
  real_T c7_A4;
  real_T c7_A5;
  real_T c7_L1;
  real_T c7_L2;
  real_T c7_L3;
  real_T c7_L4;
  real_T c7_L5;
  real_T c7_t2;
  real_T c7_t3;
  real_T c7_t4;
  real_T c7_t5;
  real_T c7_t6;
  real_T c7_t7;
  real_T c7_t8;
  real_T c7_t9;
  real_T c7_t10;
  real_T c7_t11;
  real_T c7_t12;
  real_T c7_t13;
  real_T c7_t14;
  real_T c7_t15;
  real_T c7_t16;
  real_T c7_t17;
  real_T c7_t18;
  real_T c7_t19;
  real_T c7_t20;
  real_T c7_t21;
  real_T c7_t22;
  real_T c7_t23;
  real_T c7_t24;
  real_T c7_t25;
  real_T c7_t26;
  real_T c7_t27;
  real_T c7_t28;
  real_T c7_t29;
  real_T c7_t30;
  real_T c7_t31;
  real_T c7_t32;
  real_T c7_t33;
  real_T c7_t34;
  real_T c7_t35;
  real_T c7_t36;
  real_T c7_t37;
  real_T c7_t38;
  real_T c7_t47;
  real_T c7_t39;
  real_T c7_t40;
  real_T c7_t41;
  real_T c7_t42;
  real_T c7_t43;
  real_T c7_t44;
  real_T c7_t45;
  real_T c7_t46;
  real_T c7_t48;
  real_T c7_t49;
  real_T c7_t50;
  real_T c7_nargin = 2.0;
  real_T c7_nargout = 1.0;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_c_x;
  real_T c7_d_x;
  real_T c7_e_x;
  real_T c7_f_x;
  real_T c7_g_x;
  real_T c7_h_x;
  real_T c7_i_x;
  real_T c7_j_x;
  real_T c7_k_x;
  real_T c7_l_x;
  real_T c7_m_x;
  real_T c7_n_x;
  real_T c7_o_x;
  real_T c7_p_x;
  real_T c7_q_x;
  real_T c7_r_x;
  real_T c7_s_x;
  real_T c7_t_x;
  real_T c7_u_x;
  real_T c7_v_x;
  real_T c7_w_x;
  real_T c7_x_x;
  real_T c7_a;
  real_T c7_ak;
  real_T c7_y;
  real_T c7_y_x[36];
  int32_T c7_k;
  int32_T c7_b_k;
  sf_debug_symbol_scope_push_eml(0U, 64U, 64U, c7_b_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c7_A1, c7_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c7_A2, c7_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c7_A3, c7_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c7_A4, c7_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c7_A5, c7_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c7_L1, c7_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c7_L2, c7_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c7_L3, c7_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c7_L4, c7_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c7_L5, c7_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c7_t2, c7_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c7_t3, c7_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c7_t4, c7_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c7_t5, c7_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c7_t6, c7_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c7_t7, c7_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c7_t8, c7_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c7_t9, c7_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c7_t10, c7_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c7_t11, c7_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c7_t12, c7_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c7_t13, c7_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c7_t14, c7_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c7_t15, c7_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c7_t16, c7_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c7_t17, c7_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c7_t18, c7_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c7_t19, c7_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c7_t20, c7_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c7_t21, c7_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c7_t22, c7_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c7_t23, c7_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c7_t24, c7_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c7_t25, c7_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c7_t26, c7_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c7_t27, c7_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c7_t28, c7_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c7_t29, c7_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c7_t30, c7_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c7_t31, c7_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c7_t32, c7_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c7_t33, c7_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c7_t34, c7_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c7_t35, c7_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c7_t36, c7_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c7_t37, c7_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c7_t38, c7_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c7_t47, c7_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c7_t39, c7_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c7_t40, c7_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c7_t41, c7_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c7_t42, c7_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c7_t43, c7_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c7_t44, c7_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c7_t45, c7_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c7_t46, c7_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c7_t48, c7_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c7_t49, c7_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c7_t50, c7_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c7_nargin, c7_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c7_nargout, c7_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(c7_in1, c7_b_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(c7_in2, c7_e_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(c7_b_spat_Jacobian, c7_sf_marshall, 63U);
  CV_SCRIPT_FCN(0, 0);

  /* SPAT_JACOBIAN */
  /*     SPAT_JACOBIAN = SPAT_JACOBIAN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     24-Apr-2013 20:41:43 */
  _SFD_SCRIPT_CALL(0, 8);
  c7_A1 = c7_in2[0];
  _SFD_SCRIPT_CALL(0, 9);
  c7_A2 = c7_in2[1];
  _SFD_SCRIPT_CALL(0, 10);
  c7_A3 = c7_in2[2];
  _SFD_SCRIPT_CALL(0, 11);
  c7_A4 = c7_in2[3];
  _SFD_SCRIPT_CALL(0, 12);
  c7_A5 = c7_in2[4];
  _SFD_SCRIPT_CALL(0, 13);
  c7_L1 = c7_in1[0];
  _SFD_SCRIPT_CALL(0, 14);
  c7_L2 = c7_in1[1];
  _SFD_SCRIPT_CALL(0, 15);
  c7_L3 = c7_in1[2];
  _SFD_SCRIPT_CALL(0, 16);
  c7_L4 = c7_in1[3];
  _SFD_SCRIPT_CALL(0, 17);
  c7_L5 = c7_in1[4];
  _SFD_SCRIPT_CALL(0, 18);
  c7_x = c7_A1;
  c7_t2 = c7_x;
  c7_b_x = c7_t2;
  c7_t2 = c7_b_x;
  c7_t2 = muDoubleScalarCos(c7_t2);
  _SFD_SCRIPT_CALL(0, 19);
  c7_t3 = c7_A2 + c7_A3;
  _SFD_SCRIPT_CALL(0, 20);
  c7_c_x = c7_A2;
  c7_t4 = c7_c_x;
  c7_d_x = c7_t4;
  c7_t4 = c7_d_x;
  c7_t4 = muDoubleScalarCos(c7_t4);
  _SFD_SCRIPT_CALL(0, 21);
  c7_e_x = c7_A3;
  c7_t5 = c7_e_x;
  c7_f_x = c7_t5;
  c7_t5 = c7_f_x;
  c7_t5 = muDoubleScalarCos(c7_t5);
  _SFD_SCRIPT_CALL(0, 22);
  c7_g_x = c7_A2;
  c7_t6 = c7_g_x;
  c7_h_x = c7_t6;
  c7_t6 = c7_h_x;
  c7_t6 = muDoubleScalarSin(c7_t6);
  _SFD_SCRIPT_CALL(0, 23);
  c7_i_x = c7_A3;
  c7_t7 = c7_i_x;
  c7_j_x = c7_t7;
  c7_t7 = c7_j_x;
  c7_t7 = muDoubleScalarSin(c7_t7);
  _SFD_SCRIPT_CALL(0, 24);
  c7_t8 = c7_L1 + c7_L3;
  _SFD_SCRIPT_CALL(0, 25);
  c7_t9 = c7_t5 - 1.0;
  _SFD_SCRIPT_CALL(0, 26);
  c7_k_x = c7_A1;
  c7_t10 = c7_k_x;
  c7_l_x = c7_t10;
  c7_t10 = c7_l_x;
  c7_t10 = muDoubleScalarSin(c7_t10);
  _SFD_SCRIPT_CALL(0, 27);
  c7_m_x = c7_t3;
  c7_t11 = c7_m_x;
  c7_n_x = c7_t11;
  c7_t11 = c7_n_x;
  c7_t11 = muDoubleScalarSin(c7_t11);
  _SFD_SCRIPT_CALL(0, 28);
  c7_o_x = c7_A4;
  c7_t12 = c7_o_x;
  c7_p_x = c7_t12;
  c7_t12 = c7_p_x;
  c7_t12 = muDoubleScalarCos(c7_t12);
  _SFD_SCRIPT_CALL(0, 29);
  c7_q_x = c7_t3;
  c7_t13 = c7_q_x;
  c7_r_x = c7_t13;
  c7_t13 = c7_r_x;
  c7_t13 = muDoubleScalarCos(c7_t13);
  _SFD_SCRIPT_CALL(0, 30);
  c7_s_x = c7_A4;
  c7_t14 = c7_s_x;
  c7_t_x = c7_t14;
  c7_t14 = c7_t_x;
  c7_t14 = muDoubleScalarSin(c7_t14);
  _SFD_SCRIPT_CALL(0, 31);
  c7_t15 = (c7_L1 + c7_L3) + c7_L4;
  _SFD_SCRIPT_CALL(0, 32);
  c7_t16 = c7_L2 * c7_t11;
  _SFD_SCRIPT_CALL(0, 33);
  c7_t17 = c7_L3 * c7_t5;
  _SFD_SCRIPT_CALL(0, 34);
  c7_t18 = c7_L1 * c7_t13;
  _SFD_SCRIPT_CALL(0, 35);
  c7_t19 = c7_t12 - 1.0;
  _SFD_SCRIPT_CALL(0, 36);
  c7_u_x = c7_A5;
  c7_t20 = c7_u_x;
  c7_v_x = c7_t20;
  c7_t20 = c7_v_x;
  c7_t20 = muDoubleScalarCos(c7_t20);
  _SFD_SCRIPT_CALL(0, 37);
  c7_t21 = c7_L2 + c7_L5;
  _SFD_SCRIPT_CALL(0, 38);
  c7_w_x = c7_A5;
  c7_t22 = c7_w_x;
  c7_x_x = c7_t22;
  c7_t22 = c7_x_x;
  c7_t22 = muDoubleScalarSin(c7_t22);
  _SFD_SCRIPT_CALL(0, 39);
  c7_t23 = c7_t20 - 1.0;
  _SFD_SCRIPT_CALL(0, 40);
  c7_t24 = c7_L2 * c7_t6;
  _SFD_SCRIPT_CALL(0, 41);
  c7_t25 = c7_t4 - 1.0;
  _SFD_SCRIPT_CALL(0, 42);
  c7_t26 = c7_t24 - c7_L1 * c7_t25;
  _SFD_SCRIPT_CALL(0, 43);
  c7_t27 = c7_t2 * c7_t26;
  _SFD_SCRIPT_CALL(0, 44);
  c7_t28 = c7_L2 * c7_t7;
  _SFD_SCRIPT_CALL(0, 45);
  c7_t29 = c7_t2 * c7_t4 * (c7_t28 - c7_t8 * c7_t9);
  _SFD_SCRIPT_CALL(0, 46);
  c7_t30 = c7_t7 * c7_t8;
  _SFD_SCRIPT_CALL(0, 47);
  c7_t31 = c7_L2 * c7_t9;
  _SFD_SCRIPT_CALL(0, 48);
  c7_t32 = c7_t30 + c7_t31;
  _SFD_SCRIPT_CALL(0, 49);
  c7_t33 = c7_t2 * c7_t32 * c7_t6;
  _SFD_SCRIPT_CALL(0, 50);
  c7_t34 = (c7_t27 + c7_t29) + c7_t33;
  _SFD_SCRIPT_CALL(0, 51);
  c7_t35 = c7_L1 * c7_t11;
  _SFD_SCRIPT_CALL(0, 52);
  c7_t36 = c7_L3 * c7_t7;
  _SFD_SCRIPT_CALL(0, 53);
  c7_t37 = ((c7_L2 + c7_t35) + c7_t36) - c7_L2 * c7_t13;
  _SFD_SCRIPT_CALL(0, 54);
  c7_t38 = c7_t10 * c7_t12;
  _SFD_SCRIPT_CALL(0, 55);
  c7_t47 = c7_t11 * c7_t14 * c7_t2;
  _SFD_SCRIPT_CALL(0, 56);
  c7_t39 = c7_t38 - c7_t47;
  _SFD_SCRIPT_CALL(0, 57);
  c7_t40 = c7_L3 * c7_t4;
  _SFD_SCRIPT_CALL(0, 58);
  c7_t41 = c7_L1 + c7_t40;
  _SFD_SCRIPT_CALL(0, 59);
  c7_t42 = ((c7_L4 + c7_t16) + c7_t17) + c7_t18;
  _SFD_SCRIPT_CALL(0, 60);
  c7_t43 = c7_L3 * c7_t6;
  _SFD_SCRIPT_CALL(0, 61);
  c7_t44 = c7_L4 * c7_t11;
  _SFD_SCRIPT_CALL(0, 62);
  c7_t45 = c7_L5 * c7_t13;
  _SFD_SCRIPT_CALL(0, 63);
  c7_t46 = ((c7_L2 + c7_t43) + c7_t44) + c7_t45;
  _SFD_SCRIPT_CALL(0, 64);
  c7_t48 = c7_t10 * c7_t14;
  _SFD_SCRIPT_CALL(0, 65);
  c7_t49 = c7_t11 * c7_t12 * c7_t2;
  _SFD_SCRIPT_CALL(0, 66);
  c7_t50 = c7_t48 + c7_t49;
  _SFD_SCRIPT_CALL(0, 67);
  c7_a = c7_t14;
  c7_ak = c7_a;
  c7_y = muDoubleScalarPower(c7_ak, 2.0);
  c7_y_x[0] = 0.0;
  c7_y_x[1] = 0.0;
  c7_y_x[2] = 0.0;
  c7_y_x[3] = 0.0;
  c7_y_x[4] = 0.0;
  c7_y_x[5] = 1.0;
  c7_y_x[6] = (-c7_L1) * c7_t2;
  c7_y_x[7] = (-c7_L1) * c7_t10;
  c7_y_x[8] = c7_L2;
  c7_y_x[9] = -c7_t10;
  c7_y_x[10] = c7_t2;
  c7_y_x[11] = 0.0;
  c7_y_x[12] = (-c7_t2) * c7_t41;
  c7_y_x[13] = (-c7_t10) * c7_t41;
  c7_y_x[14] = c7_L2 + c7_t43;
  c7_y_x[15] = -c7_t10;
  c7_y_x[16] = c7_t2;
  c7_y_x[17] = 0.0;
  c7_y_x[18] = (-c7_t10) * c7_t42;
  c7_y_x[19] = c7_t2 * c7_t42;
  c7_y_x[20] = 0.0;
  c7_y_x[21] = c7_t13 * c7_t2;
  c7_y_x[22] = c7_t10 * c7_t13;
  c7_y_x[23] = -c7_t11;
  c7_y_x[24] = ((((-c7_t12) * c7_t34 + c7_t21 * c7_t50) + c7_t13 * c7_t2 * (c7_y
    * c7_t15 + c7_t12 * c7_t15 * c7_t19)) - c7_t13 *
                c7_t15 * c7_t2) - c7_t10 * c7_t14 * c7_t37;
  c7_y_x[25] = (((((((-c7_L1) * c7_t10 * c7_t12 - c7_L5 * c7_t14 * c7_t2) +
                    c7_L1 * c7_t11 * c7_t14 * c7_t2) - c7_L2 * c7_t13 * c7_t14
                   * c7_t2) - c7_L4 * c7_t10 * c7_t12 * c7_t13) + c7_L5 * c7_t10
                 * c7_t11 * c7_t12) - c7_L3 * c7_t10 * c7_t12 * c7_t4) + c7_L3 *
    c7_t14 * c7_t2 * c7_t7;
  c7_y_x[26] = c7_t12 * c7_t46;
  c7_y_x[27] = (-c7_t38) + c7_t47;
  c7_y_x[28] = c7_t12 * c7_t2 + c7_t10 * c7_t11 * c7_t14;
  c7_y_x[29] = c7_t13 * c7_t14;
  c7_y_x[30] = (((-c7_t20) * ((c7_t10 * (((((-c7_L1) - c7_L3) + c7_t16) + c7_t17)
    + c7_t18) - c7_t10 * c7_t15 * c7_t19) + c7_t11 *
    c7_t14 * c7_t15 * c7_t2) - c7_t15 * c7_t39) - c7_t22 * ((c7_t14 * c7_t34 +
    c7_t13 * c7_t2 * (c7_t12 * c7_t14 * c7_t15 - c7_t14 *
                      c7_t15 * c7_t19)) - c7_t10 * c7_t12 * c7_t37)) + c7_t39 *
    (c7_t20 * (c7_t15 * c7_t23 - c7_t21 * c7_t22) + c7_t22 * (c7_t15 * c7_t22
      + c7_t21 * c7_t23));
  c7_y_x[31] = ((((((((((c7_L4 * c7_t2 * c7_t20 - c7_L1 * c7_t10 * c7_t14 *
    c7_t22) + c7_L1 * c7_t13 * c7_t2 * c7_t20) + c7_L2 *
                       c7_t11 * c7_t2 * c7_t20) + c7_L5 * c7_t12 * c7_t2 *
                      c7_t22) + c7_L3 * c7_t2 * c7_t20 * c7_t5) - c7_L1 * c7_t11
                    * c7_t12 * c7_t2 *
                    c7_t22) + c7_L2 * c7_t12 * c7_t13 * c7_t2 * c7_t22) - c7_L4 *
                  c7_t10 * c7_t13 * c7_t14 * c7_t22) + c7_L5 * c7_t10 * c7_t11 *
                 c7_t14
                 * c7_t22) - c7_L3 * c7_t10 * c7_t14 * c7_t22 * c7_t4) - c7_L3 *
    c7_t12 * c7_t2 * c7_t22 * c7_t7;
  c7_y_x[32] = c7_t14 * c7_t22 * c7_t46;
  c7_y_x[33] = (-c7_t22) * c7_t50 + c7_t13 * c7_t2 * c7_t20;
  c7_y_x[34] = c7_t22 * (c7_t14 * c7_t2 - c7_t10 * c7_t11 * c7_t12) + c7_t10 *
    c7_t13 * c7_t20;
  c7_y_x[35] = (-c7_t11) * c7_t20 - c7_t12 * c7_t13 * c7_t22;
  for (c7_k = 1; c7_k < 37; c7_k = c7_k + 1) {
    c7_b_k = c7_k;
    c7_b_spat_Jacobian[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c7_b_k), 1, 36, 1, 0) - 1] = c7_y_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c7_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0, -67);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c7_sf_marshall(void *chartInstanceVoid, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i23;
  int32_T c7_i24;
  int32_T c7_i25;
  real_T c7_b_u[36];
  int32_T c7_i26;
  int32_T c7_i27;
  int32_T c7_i28;
  real_T c7_c_u[36];
  const mxArray *c7_b_y = NULL;
  SFc7_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc7_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c7_y = NULL;
  c7_i23 = 0;
  for (c7_i24 = 0; c7_i24 < 6; c7_i24 = c7_i24 + 1) {
    for (c7_i25 = 0; c7_i25 < 6; c7_i25 = c7_i25 + 1) {
      c7_b_u[c7_i25 + c7_i23] = (*((real_T (*)[36])c7_u))[c7_i25 + c7_i23];
    }

    c7_i23 = c7_i23 + 6;
  }

  c7_i26 = 0;
  for (c7_i27 = 0; c7_i27 < 6; c7_i27 = c7_i27 + 1) {
    for (c7_i28 = 0; c7_i28 < 6; c7_i28 = c7_i28 + 1) {
      c7_c_u[c7_i28 + c7_i26] = c7_b_u[c7_i28 + c7_i26];
    }

    c7_i26 = c7_i26 + 6;
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_b_sf_marshall(void *chartInstanceVoid, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i29;
  real_T c7_b_u[9];
  int32_T c7_i30;
  real_T c7_c_u[9];
  const mxArray *c7_b_y = NULL;
  SFc7_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc7_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c7_y = NULL;
  for (c7_i29 = 0; c7_i29 < 9; c7_i29 = c7_i29 + 1) {
    c7_b_u[c7_i29] = (*((real_T (*)[9])c7_u))[c7_i29];
  }

  for (c7_i30 = 0; c7_i30 < 9; c7_i30 = c7_i30 + 1) {
    c7_c_u[c7_i30] = c7_b_u[c7_i30];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_c_sf_marshall(void *chartInstanceVoid, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i31;
  real_T c7_b_u[6];
  int32_T c7_i32;
  real_T c7_c_u[6];
  const mxArray *c7_b_y = NULL;
  SFc7_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc7_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c7_y = NULL;
  for (c7_i31 = 0; c7_i31 < 6; c7_i31 = c7_i31 + 1) {
    c7_b_u[c7_i31] = (*((real_T (*)[6])c7_u))[c7_i31];
  }

  for (c7_i32 = 0; c7_i32 < 6; c7_i32 = c7_i32 + 1) {
    c7_c_u[c7_i32] = c7_b_u[c7_i32];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_d_sf_marshall(void *chartInstanceVoid, void *c7_u)
{
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  SFc7_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc7_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c7_y = NULL;
  c7_b_u = *((real_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static const mxArray *c7_e_sf_marshall(void *chartInstanceVoid, void *c7_u)
{
  const mxArray *c7_y = NULL;
  int32_T c7_i33;
  real_T c7_b_u[6];
  int32_T c7_i34;
  real_T c7_c_u[6];
  const mxArray *c7_b_y = NULL;
  SFc7_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc7_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c7_y = NULL;
  for (c7_i33 = 0; c7_i33 < 6; c7_i33 = c7_i33 + 1) {
    c7_b_u[c7_i33] = (*((real_T (*)[6])c7_u))[c7_i33];
  }

  for (c7_i34 = 0; c7_i34 < 6; c7_i34 = c7_i34 + 1) {
    c7_c_u[c7_i34] = c7_b_u[c7_i34];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

const mxArray *sf_c7_AugPDTask_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_ResolvedFunctionInfo c7_info[48];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i35;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_info_helper(c7_info);
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 48));
  for (c7_i35 = 0; c7_i35 < 48; c7_i35 = c7_i35 + 1) {
    c7_r0 = &c7_info[c7_i35];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context",
                    "nameCaptureInfo", c7_i35);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name",
                    "nameCaptureInfo", c7_i35);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c7_i35);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c7_i35);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c7_i35);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c7_i35
                    );
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c7_i35
                    );
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0);
  return c7_nameCaptureInfo;
}

static void c7_info_helper(c7_ResolvedFunctionInfo c7_info[48])
{
  c7_info[0].context = "";
  c7_info[0].name = "mrdivide";
  c7_info[0].dominantType = "double";
  c7_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[0].fileLength = 432U;
  c7_info[0].fileTime1 = 1277726622U;
  c7_info[0].fileTime2 = 0U;
  c7_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[1].name = "nargin";
  c7_info[1].dominantType = "";
  c7_info[1].resolved = "[B]nargin";
  c7_info[1].fileLength = 0U;
  c7_info[1].fileTime1 = 0U;
  c7_info[1].fileTime2 = 0U;
  c7_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[2].name = "ge";
  c7_info[2].dominantType = "double";
  c7_info[2].resolved = "[B]ge";
  c7_info[2].fileLength = 0U;
  c7_info[2].fileTime1 = 0U;
  c7_info[2].fileTime2 = 0U;
  c7_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[3].name = "isscalar";
  c7_info[3].dominantType = "double";
  c7_info[3].resolved = "[B]isscalar";
  c7_info[3].fileLength = 0U;
  c7_info[3].fileTime1 = 0U;
  c7_info[3].fileTime2 = 0U;
  c7_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c7_info[4].name = "rdivide";
  c7_info[4].dominantType = "double";
  c7_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[4].fileLength = 403U;
  c7_info[4].fileTime1 = 1245080820U;
  c7_info[4].fileTime2 = 0U;
  c7_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[5].name = "gt";
  c7_info[5].dominantType = "double";
  c7_info[5].resolved = "[B]gt";
  c7_info[5].fileLength = 0U;
  c7_info[5].fileTime1 = 0U;
  c7_info[5].fileTime2 = 0U;
  c7_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[6].name = "isa";
  c7_info[6].dominantType = "double";
  c7_info[6].resolved = "[B]isa";
  c7_info[6].fileLength = 0U;
  c7_info[6].fileTime1 = 0U;
  c7_info[6].fileTime2 = 0U;
  c7_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c7_info[7].name = "eml_div";
  c7_info[7].dominantType = "double";
  c7_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[7].fileLength = 4918U;
  c7_info[7].fileTime1 = 1267038210U;
  c7_info[7].fileTime2 = 0U;
  c7_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c7_info[8].name = "isinteger";
  c7_info[8].dominantType = "double";
  c7_info[8].resolved = "[B]isinteger";
  c7_info[8].fileLength = 0U;
  c7_info[8].fileTime1 = 0U;
  c7_info[8].fileTime2 = 0U;
  c7_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c7_info[9].name = "isreal";
  c7_info[9].dominantType = "double";
  c7_info[9].resolved = "[B]isreal";
  c7_info[9].fileLength = 0U;
  c7_info[9].fileTime1 = 0U;
  c7_info[9].fileTime2 = 0U;
  c7_info[10].context = "";
  c7_info[10].name = "ctranspose";
  c7_info[10].dominantType = "double";
  c7_info[10].resolved = "[B]ctranspose";
  c7_info[10].fileLength = 0U;
  c7_info[10].fileTime1 = 0U;
  c7_info[10].fileTime2 = 0U;
  c7_info[11].context = "";
  c7_info[11].name = "spat_Jacobian";
  c7_info[11].dominantType = "double";
  c7_info[11].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[11].fileLength = 2169U;
  c7_info[11].fileTime1 = 1366807304U;
  c7_info[11].fileTime2 = 0U;
  c7_info[12].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[12].name = "cos";
  c7_info[12].dominantType = "double";
  c7_info[12].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[12].fileLength = 324U;
  c7_info[12].fileTime1 = 1203422750U;
  c7_info[12].fileTime2 = 0U;
  c7_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c7_info[13].name = "eml_scalar_cos";
  c7_info[13].dominantType = "double";
  c7_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c7_info[13].fileLength = 602U;
  c7_info[13].fileTime1 = 1209309186U;
  c7_info[13].fileTime2 = 0U;
  c7_info[14].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[14].name = "plus";
  c7_info[14].dominantType = "double";
  c7_info[14].resolved = "[B]plus";
  c7_info[14].fileLength = 0U;
  c7_info[14].fileTime1 = 0U;
  c7_info[14].fileTime2 = 0U;
  c7_info[15].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[15].name = "sin";
  c7_info[15].dominantType = "double";
  c7_info[15].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[15].fileLength = 324U;
  c7_info[15].fileTime1 = 1203422842U;
  c7_info[15].fileTime2 = 0U;
  c7_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c7_info[16].name = "eml_scalar_sin";
  c7_info[16].dominantType = "double";
  c7_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c7_info[16].fileLength = 601U;
  c7_info[16].fileTime1 = 1209309190U;
  c7_info[16].fileTime2 = 0U;
  c7_info[17].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[17].name = "minus";
  c7_info[17].dominantType = "double";
  c7_info[17].resolved = "[B]minus";
  c7_info[17].fileLength = 0U;
  c7_info[17].fileTime1 = 0U;
  c7_info[17].fileTime2 = 0U;
  c7_info[18].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[18].name = "times";
  c7_info[18].dominantType = "double";
  c7_info[18].resolved = "[B]times";
  c7_info[18].fileLength = 0U;
  c7_info[18].fileTime1 = 0U;
  c7_info[18].fileTime2 = 0U;
  c7_info[19].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[19].name = "uminus";
  c7_info[19].dominantType = "double";
  c7_info[19].resolved = "[B]uminus";
  c7_info[19].fileLength = 0U;
  c7_info[19].fileTime1 = 0U;
  c7_info[19].fileTime2 = 0U;
  c7_info[20].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[20].name = "power";
  c7_info[20].dominantType = "double";
  c7_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[20].fileLength = 5380U;
  c7_info[20].fileTime1 = 1228068698U;
  c7_info[20].fileTime2 = 0U;
  c7_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[21].name = "eml_scalar_eg";
  c7_info[21].dominantType = "double";
  c7_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[21].fileLength = 3068U;
  c7_info[21].fileTime1 = 1240240410U;
  c7_info[21].fileTime2 = 0U;
  c7_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c7_info[22].name = "false";
  c7_info[22].dominantType = "";
  c7_info[22].resolved = "[B]false";
  c7_info[22].fileLength = 0U;
  c7_info[22].fileTime1 = 0U;
  c7_info[22].fileTime2 = 0U;
  c7_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c7_info[23].name = "isstruct";
  c7_info[23].dominantType = "double";
  c7_info[23].resolved = "[B]isstruct";
  c7_info[23].fileLength = 0U;
  c7_info[23].fileTime1 = 0U;
  c7_info[23].fileTime2 = 0U;
  c7_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c7_info[24].name = "eq";
  c7_info[24].dominantType = "double";
  c7_info[24].resolved = "[B]eq";
  c7_info[24].fileLength = 0U;
  c7_info[24].fileTime1 = 0U;
  c7_info[24].fileTime2 = 0U;
  c7_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c7_info[25].name = "class";
  c7_info[25].dominantType = "double";
  c7_info[25].resolved = "[B]class";
  c7_info[25].fileLength = 0U;
  c7_info[25].fileTime1 = 0U;
  c7_info[25].fileTime2 = 0U;
  c7_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c7_info[26].name = "cast";
  c7_info[26].dominantType = "double";
  c7_info[26].resolved = "[B]cast";
  c7_info[26].fileLength = 0U;
  c7_info[26].fileTime1 = 0U;
  c7_info[26].fileTime2 = 0U;
  c7_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[27].name = "eml_scalexp_alloc";
  c7_info[27].dominantType = "double";
  c7_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[27].fileLength = 932U;
  c7_info[27].fileTime1 = 1261926670U;
  c7_info[27].fileTime2 = 0U;
  c7_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c7_info[28].name = "not";
  c7_info[28].dominantType = "logical";
  c7_info[28].resolved = "[B]not";
  c7_info[28].fileLength = 0U;
  c7_info[28].fileTime1 = 0U;
  c7_info[28].fileTime2 = 0U;
  c7_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[29].name = "lt";
  c7_info[29].dominantType = "double";
  c7_info[29].resolved = "[B]lt";
  c7_info[29].fileLength = 0U;
  c7_info[29].fileTime1 = 0U;
  c7_info[29].fileTime2 = 0U;
  c7_info[30].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[30].name = "eml_scalar_floor";
  c7_info[30].dominantType = "double";
  c7_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c7_info[30].fileLength = 260U;
  c7_info[30].fileTime1 = 1209309190U;
  c7_info[30].fileTime2 = 0U;
  c7_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[31].name = "ne";
  c7_info[31].dominantType = "double";
  c7_info[31].resolved = "[B]ne";
  c7_info[31].fileLength = 0U;
  c7_info[31].fileTime1 = 0U;
  c7_info[31].fileTime2 = 0U;
  c7_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c7_info[32].name = "eml_error";
  c7_info[32].dominantType = "char";
  c7_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[32].fileLength = 315U;
  c7_info[32].fileTime1 = 1213905144U;
  c7_info[32].fileTime2 = 0U;
  c7_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c7_info[33].name = "strcmp";
  c7_info[33].dominantType = "char";
  c7_info[33].resolved = "[B]strcmp";
  c7_info[33].fileLength = 0U;
  c7_info[33].fileTime1 = 0U;
  c7_info[33].fileTime2 = 0U;
  c7_info[34].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c7_info[34].name = "reshape";
  c7_info[34].dominantType = "double";
  c7_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c7_info[34].fileLength = 4857U;
  c7_info[34].fileTime1 = 1242276774U;
  c7_info[34].fileTime2 = 0U;
  c7_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c7_info[35].name = "eml_index_class";
  c7_info[35].dominantType = "";
  c7_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c7_info[35].fileLength = 909U;
  c7_info[35].fileTime1 = 1192445182U;
  c7_info[35].fileTime2 = 0U;
  c7_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c7_info[36].name = "size";
  c7_info[36].dominantType = "double";
  c7_info[36].resolved = "[B]size";
  c7_info[36].fileLength = 0U;
  c7_info[36].fileTime1 = 0U;
  c7_info[36].fileTime2 = 0U;
  c7_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c7_info[37].name = "eml_assert_valid_size_arg";
  c7_info[37].dominantType = "double";
  c7_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c7_info[37].fileLength = 3315U;
  c7_info[37].fileTime1 = 1256367816U;
  c7_info[37].fileTime2 = 0U;
  c7_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c7_info[38].name = "isvector";
  c7_info[38].dominantType = "double";
  c7_info[38].resolved = "[B]isvector";
  c7_info[38].fileLength = 0U;
  c7_info[38].fileTime1 = 0U;
  c7_info[38].fileTime2 = 0U;
  c7_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c7_info[39].name = "isinf";
  c7_info[39].dominantType = "double";
  c7_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c7_info[39].fileLength = 541U;
  c7_info[39].fileTime1 = 1271383988U;
  c7_info[39].fileTime2 = 0U;
  c7_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c7_info[40].name = "true";
  c7_info[40].dominantType = "";
  c7_info[40].resolved = "[B]true";
  c7_info[40].fileLength = 0U;
  c7_info[40].fileTime1 = 0U;
  c7_info[40].fileTime2 = 0U;
  c7_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c7_info[41].name = "le";
  c7_info[41].dominantType = "double";
  c7_info[41].resolved = "[B]le";
  c7_info[41].fileLength = 0U;
  c7_info[41].fileTime1 = 0U;
  c7_info[41].fileTime2 = 0U;
  c7_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c7_info[42].name = "double";
  c7_info[42].dominantType = "double";
  c7_info[42].resolved = "[B]double";
  c7_info[42].fileLength = 0U;
  c7_info[42].fileTime1 = 0U;
  c7_info[42].fileTime2 = 0U;
  c7_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c7_info[43].name = "mtimes";
  c7_info[43].dominantType = "double";
  c7_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c7_info[43].fileLength = 3425U;
  c7_info[43].fileTime1 = 1251010272U;
  c7_info[43].fileTime2 = 0U;
  c7_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c7_info[44].name = "intmax";
  c7_info[44].dominantType = "char";
  c7_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c7_info[44].fileLength = 1535U;
  c7_info[44].fileTime1 = 1192445128U;
  c7_info[44].fileTime2 = 0U;
  c7_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c7_info[45].name = "ischar";
  c7_info[45].dominantType = "char";
  c7_info[45].resolved = "[B]ischar";
  c7_info[45].fileLength = 0U;
  c7_info[45].fileTime1 = 0U;
  c7_info[45].fileTime2 = 0U;
  c7_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c7_info[46].name = "int32";
  c7_info[46].dominantType = "double";
  c7_info[46].resolved = "[B]int32";
  c7_info[46].fileLength = 0U;
  c7_info[46].fileTime1 = 0U;
  c7_info[46].fileTime2 = 0U;
  c7_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c7_info[47].name = "ones";
  c7_info[47].dominantType = "char";
  c7_info[47].resolved = "[B]ones";
  c7_info[47].fileLength = 0U;
  c7_info[47].fileTime1 = 0U;
  c7_info[47].fileTime2 = 0U;
}

static const mxArray *c7_f_sf_marshall(void *chartInstanceVoid, void *c7_u)
{
  const mxArray *c7_y = NULL;
  boolean_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  SFc7_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc7_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c7_y = NULL;
  c7_b_u = *((boolean_T *)c7_u);
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c7_y, c7_b_y);
  return c7_y;
}

static void c7_emlrt_marshallIn(SFc7_AugPDTaskInstanceStruct *chartInstance,
  const mxArray *c7_T_J, const char_T *c7_name, real_T
  c7_y[36])
{
  real_T c7_dv3[36];
  int32_T c7_i36;
  sf_mex_import(c7_name, sf_mex_dup(c7_T_J), c7_dv3, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c7_i36 = 0; c7_i36 < 36; c7_i36 = c7_i36 + 1) {
    c7_y[c7_i36] = c7_dv3[c7_i36];
  }

  sf_mex_destroy(&c7_T_J);
}

static uint8_T c7_b_emlrt_marshallIn(SFc7_AugPDTaskInstanceStruct *chartInstance,
  const mxArray *c7_b_is_active_c7_AugPDTask, const
  char_T *c7_name)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_name, sf_mex_dup(c7_b_is_active_c7_AugPDTask), &c7_u0, 1, 3,
                0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_b_is_active_c7_AugPDTask);
  return c7_y;
}

static void init_dsm_address_info(SFc7_AugPDTaskInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c7_AugPDTask_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3827024137U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2574186019U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3544156139U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1427814606U);
}

mxArray *sf_c7_AugPDTask_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3062212476U);
    pr[1] = (double)(1056439422U);
    pr[2] = (double)(3657367852U);
    pr[3] = (double)(3818590367U);
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
      pr[0] = (double)(6);
      pr[1] = (double)(6);
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

static mxArray *sf_get_sim_state_info_c7_AugPDTask(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"T_J\",},{M[8],M[0],T\"is_active_c7_AugPDTask\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_AugPDTask_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_AugPDTaskInstanceStruct *chartInstance;
    chartInstance = (SFc7_AugPDTaskInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_AugPDTaskMachineNumber_,
          7,
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
          init_script_number_translation(_AugPDTaskMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_AugPDTaskMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_AugPDTaskMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EnTheta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"T_J");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,75);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"spat_Jacobian",0,-1,2102);
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
            1.0,0,0,(MexFcnForType)c7_c_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_b_sf_marshall);
        }

        {
          real_T (*c7_EnTheta)[6];
          real_T (*c7_T_J)[36];
          c7_T_J = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
          c7_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_EnTheta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_T_J);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c7_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_AugPDTaskMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c7_AugPDTask(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_AugPDTaskInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*)
    chartInstanceVar);
  initialize_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_AugPDTask(void *chartInstanceVar)
{
  enable_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_AugPDTask(void *chartInstanceVar)
{
  disable_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_AugPDTask(void *chartInstanceVar)
{
  sf_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c7_AugPDTask(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c7_AugPDTask();/* state var info */
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

static void sf_internal_set_sim_state_c7_AugPDTask(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_AugPDTask();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c7_AugPDTask(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_AugPDTask(S);
}

static void sf_opaque_set_sim_state_c7_AugPDTask(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c7_AugPDTask(S, st);
}

static void sf_opaque_terminate_c7_AugPDTask(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_AugPDTaskInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_AugPDTask(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_AugPDTask((SFc7_AugPDTaskInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_AugPDTask(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(S,"AugPDTask","AugPDTask",7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"AugPDTask","AugPDTask",7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"AugPDTask","AugPDTask",
      7,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"AugPDTask","AugPDTask",7,1);
      sf_mark_chart_reusable_outputs(S,"AugPDTask","AugPDTask",7,1);
    }

    sf_set_rtw_dwork_info(S,"AugPDTask","AugPDTask",7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4139398657U));
  ssSetChecksum1(S,(1485247008U));
  ssSetChecksum2(S,(1205878746U));
  ssSetChecksum3(S,(2198766292U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_AugPDTask(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "AugPDTask", "AugPDTask",7);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_AugPDTask(SimStruct *S)
{
  SFc7_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc7_AugPDTaskInstanceStruct *)malloc(sizeof
    (SFc7_AugPDTaskInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_AugPDTaskInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c7_AugPDTask;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c7_AugPDTask;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c7_AugPDTask;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_AugPDTask;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_AugPDTask;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c7_AugPDTask;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c7_AugPDTask;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c7_AugPDTask;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_AugPDTask;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_AugPDTask;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_AugPDTask;
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

void c7_AugPDTask_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_AugPDTask(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_AugPDTask(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_AugPDTask(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_AugPDTask_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
