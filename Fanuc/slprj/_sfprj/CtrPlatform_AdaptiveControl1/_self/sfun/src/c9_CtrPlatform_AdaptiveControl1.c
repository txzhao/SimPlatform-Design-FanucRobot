/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_AdaptiveControl1_sfun.h"
#include "c9_CtrPlatform_AdaptiveControl1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_AdaptiveControl1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[8] = { "L", "Ma", "nargin", "nargout",
  "EnTheta", "Cen", "Gravity", "N" };

static const char * c9_b_debug_family_names[107] = { "A2", "A3", "A4", "A5",
  "A6", "Cx2", "Cx3", "Cx4", "Cx5", "Cx6", "Cy4", "Cy5", "Cy6", "Cz2", "Cz3",
  "Cz4", "Cz5", "Cz6", "L1", "L2", "L3", "L4", "L5", "Ma2", "Ma3", "Ma4", "Ma5",
  "Ma6", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9", "t16", "t10", "t11",
  "t12", "t13", "t14", "t15", "t17", "t18", "t19", "t20", "t21", "t22", "t23",
  "t24", "t25", "t26", "t27", "t28", "t29", "t30", "t36", "t31", "t32", "t33",
  "t34", "t35", "t37", "t38", "t39", "t40", "t41", "t45", "t42", "t43", "t46",
  "t47", "t44", "t48", "t49", "t50", "t57", "t51", "t52", "t53", "t54", "t55",
  "t56", "t58", "t59", "t60", "t61", "t62", "t63", "t72", "t64", "t65", "t66",
  "t67", "t68", "t69", "t70", "t71", "nargin", "nargout", "in1", "in2", "in3",
  "in4", "g", "N_d_" };

/* Function Declarations */
static void initialize_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void initialize_params_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void enable_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void disable_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void set_sim_state_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_st);
static void finalize_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void sf_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void initSimStructsc9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *
  chartInstance, const mxArray *c9_N, const char_T *c9_identifier, real_T c9_y[6]);
static void c9_b_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[6]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[18]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[6]);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_f_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9]);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_N_d(SFc9_CtrPlatform_AdaptiveControl1InstanceStruct
                   *chartInstance, real_T c9_in1[9], real_T c9_in2[6], real_T
                   c9_in3[18], real_T c9_in4[6], real_T c9_g, real_T c9_N_d_[6]);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_g_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_h_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_b_is_active_c9_CtrPlatform_AdaptiveControl1, const char_T *c9_identifier);
static uint8_T c9_i_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_CtrPlatform_AdaptiveControl1 = 0U;
}

static void initialize_params_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  real_T c9_dv0[9];
  int32_T c9_i0;
  real_T c9_dv1[18];
  int32_T c9_i1;
  real_T c9_dv2[6];
  int32_T c9_i2;
  real_T c9_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import_named("L", sf_mex_get_sfun_param(chartInstance->S, 2, 0), c9_dv0,
                      0, 0, 0U, 1, 0U, 2, 1, 9);
  for (c9_i0 = 0; c9_i0 < 9; c9_i0++) {
    chartInstance->c9_L[c9_i0] = c9_dv0[c9_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Cen' in the parent workspace.\n");
  sf_mex_import_named("Cen", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c9_dv1, 0, 0, 0U, 1, 0U, 2, 1, 18);
  for (c9_i1 = 0; c9_i1 < 18; c9_i1++) {
    chartInstance->c9_Cen[c9_i1] = c9_dv1[c9_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Ma' in the parent workspace.\n");
  sf_mex_import_named("Ma", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      c9_dv2, 0, 0, 0U, 1, 0U, 2, 1, 6);
  for (c9_i2 = 0; c9_i2 < 6; c9_i2++) {
    chartInstance->c9_Ma[c9_i2] = c9_dv2[c9_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Gravity' in the parent workspace.\n");
  sf_mex_import_named("Gravity", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c9_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c9_Gravity = c9_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i3;
  real_T c9_u[6];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T (*c9_N)[6];
  c9_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2), FALSE);
  for (c9_i3 = 0; c9_i3 < 6; c9_i3++) {
    c9_u[c9_i3] = (*c9_N)[c9_i3];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_CtrPlatform_AdaptiveControl1;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv3[6];
  int32_T c9_i4;
  real_T (*c9_N)[6];
  c9_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "N",
                      c9_dv3);
  for (c9_i4 = 0; c9_i4 < 6; c9_i4++) {
    (*c9_N)[c9_i4] = c9_dv3[c9_i4];
  }

  chartInstance->c9_is_active_c9_CtrPlatform_AdaptiveControl1 =
    c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "is_active_c9_CtrPlatform_AdaptiveControl1");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_CtrPlatform_AdaptiveControl1(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static void sf_c9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  real_T c9_hoistedGlobal;
  int32_T c9_i10;
  real_T c9_EnTheta[6];
  int32_T c9_i11;
  real_T c9_b_Cen[18];
  real_T c9_b_Gravity;
  uint32_T c9_debug_family_var_map[8];
  real_T c9_c_L[9];
  real_T c9_c_Ma[6];
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 1.0;
  real_T c9_N[6];
  int32_T c9_i12;
  static real_T c9_d_Ma[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  int32_T c9_i13;
  static real_T c9_d_L[9] = { 566.0, 150.0, 870.0, 170.0, 1016.0, 154.0, 20.0,
    0.0, 0.0 };

  int32_T c9_i14;
  int32_T c9_i15;
  static real_T c9_dv4[9] = { 0.566, 0.15, 0.87, 0.17, 1.016, 0.154, 0.02, 0.0,
    0.0 };

  real_T c9_dv5[9];
  int32_T c9_i16;
  real_T c9_b_EnTheta[6];
  int32_T c9_i17;
  real_T c9_c_Cen[18];
  int32_T c9_i18;
  real_T c9_e_Ma[6];
  real_T c9_dv6[6];
  int32_T c9_i19;
  int32_T c9_i20;
  real_T (*c9_b_N)[6];
  real_T (*c9_c_EnTheta)[6];
  c9_b_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_c_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i5 = 0; c9_i5 < 6; c9_i5++) {
    _SFD_DATA_RANGE_CHECK((*c9_c_EnTheta)[c9_i5], 0U);
  }

  for (c9_i6 = 0; c9_i6 < 6; c9_i6++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_N)[c9_i6], 1U);
  }

  for (c9_i7 = 0; c9_i7 < 9; c9_i7++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_L[c9_i7], 2U);
  }

  for (c9_i8 = 0; c9_i8 < 18; c9_i8++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_Cen[c9_i8], 3U);
  }

  for (c9_i9 = 0; c9_i9 < 6; c9_i9++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c9_Ma[c9_i9], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c9_Gravity, 5U);
  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  c9_hoistedGlobal = chartInstance->c9_Gravity;
  for (c9_i10 = 0; c9_i10 < 6; c9_i10++) {
    c9_EnTheta[c9_i10] = (*c9_c_EnTheta)[c9_i10];
  }

  for (c9_i11 = 0; c9_i11 < 18; c9_i11++) {
    c9_b_Cen[c9_i11] = chartInstance->c9_Cen[c9_i11];
  }

  c9_b_Gravity = c9_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c9_c_L, 0U, c9_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_c_Ma, 1U, c9_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c9_EnTheta, 4U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c9_b_Cen, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_b_Gravity, 6U,
    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_N, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  for (c9_i12 = 0; c9_i12 < 6; c9_i12++) {
    c9_c_Ma[c9_i12] = c9_d_Ma[c9_i12];
  }

  for (c9_i13 = 0; c9_i13 < 9; c9_i13++) {
    c9_c_L[c9_i13] = c9_d_L[c9_i13];
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  for (c9_i14 = 0; c9_i14 < 6; c9_i14++) {
    c9_N[c9_i14] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  for (c9_i15 = 0; c9_i15 < 9; c9_i15++) {
    c9_dv5[c9_i15] = c9_dv4[c9_i15];
  }

  for (c9_i16 = 0; c9_i16 < 6; c9_i16++) {
    c9_b_EnTheta[c9_i16] = c9_EnTheta[c9_i16];
  }

  for (c9_i17 = 0; c9_i17 < 18; c9_i17++) {
    c9_c_Cen[c9_i17] = c9_b_Cen[c9_i17];
  }

  for (c9_i18 = 0; c9_i18 < 6; c9_i18++) {
    c9_e_Ma[c9_i18] = c9_d_Ma[c9_i18];
  }

  c9_N_d(chartInstance, c9_dv5, c9_b_EnTheta, c9_c_Cen, c9_e_Ma, c9_b_Gravity,
         c9_dv6);
  for (c9_i19 = 0; c9_i19 < 6; c9_i19++) {
    c9_N[c9_i19] = c9_dv6[c9_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c9_i20 = 0; c9_i20 < 6; c9_i20++) {
    (*c9_b_N)[c9_i20] = c9_N[c9_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_AdaptiveControl1MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc9_CtrPlatform_AdaptiveControl1
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, 0U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/N_d.m"));
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i21;
  real_T c9_b_inData[6];
  int32_T c9_i22;
  real_T c9_u[6];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i21 = 0; c9_i21 < 6; c9_i21++) {
    c9_b_inData[c9_i21] = (*(real_T (*)[6])c9_inData)[c9_i21];
  }

  for (c9_i22 = 0; c9_i22 < 6; c9_i22++) {
    c9_u[c9_i22] = c9_b_inData[c9_i22];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *
  chartInstance, const mxArray *c9_N, const char_T *c9_identifier, real_T c9_y[6])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_N), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_N);
}

static void c9_b_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[6])
{
  real_T c9_dv7[6];
  int32_T c9_i23;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv7, 1, 0, 0U, 1, 0U, 1, 6);
  for (c9_i23 = 0; c9_i23 < 6; c9_i23++) {
    c9_y[c9_i23] = c9_dv7[c9_i23];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_N;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[6];
  int32_T c9_i24;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_N = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_N), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_N);
  for (c9_i24 = 0; c9_i24 < 6; c9_i24++) {
    (*(real_T (*)[6])c9_outData)[c9_i24] = c9_y[c9_i24];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d1;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d1, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_Gravity;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_b_Gravity = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_Gravity),
    &c9_thisId);
  sf_mex_destroy(&c9_b_Gravity);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i25;
  real_T c9_b_inData[18];
  int32_T c9_i26;
  real_T c9_u[18];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i25 = 0; c9_i25 < 18; c9_i25++) {
    c9_b_inData[c9_i25] = (*(real_T (*)[18])c9_inData)[c9_i25];
  }

  for (c9_i26 = 0; c9_i26 < 18; c9_i26++) {
    c9_u[c9_i26] = c9_b_inData[c9_i26];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 18), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_d_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[18])
{
  real_T c9_dv8[18];
  int32_T c9_i27;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv8, 1, 0, 0U, 1, 0U, 2, 1, 18);
  for (c9_i27 = 0; c9_i27 < 18; c9_i27++) {
    c9_y[c9_i27] = c9_dv8[c9_i27];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_Cen;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[18];
  int32_T c9_i28;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_b_Cen = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_Cen), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_Cen);
  for (c9_i28 = 0; c9_i28 < 18; c9_i28++) {
    (*(real_T (*)[18])c9_outData)[c9_i28] = c9_y[c9_i28];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i29;
  real_T c9_b_inData[6];
  int32_T c9_i30;
  real_T c9_u[6];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i29 = 0; c9_i29 < 6; c9_i29++) {
    c9_b_inData[c9_i29] = (*(real_T (*)[6])c9_inData)[c9_i29];
  }

  for (c9_i30 = 0; c9_i30 < 6; c9_i30++) {
    c9_u[c9_i30] = c9_b_inData[c9_i30];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i31;
  real_T c9_b_inData[9];
  int32_T c9_i32;
  real_T c9_u[9];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i31 = 0; c9_i31 < 9; c9_i31++) {
    c9_b_inData[c9_i31] = (*(real_T (*)[9])c9_inData)[c9_i31];
  }

  for (c9_i32 = 0; c9_i32 < 9; c9_i32++) {
    c9_u[c9_i32] = c9_b_inData[c9_i32];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[6])
{
  real_T c9_dv9[6];
  int32_T c9_i33;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv9, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c9_i33 = 0; c9_i33 < 6; c9_i33++) {
    c9_y[c9_i33] = c9_dv9[c9_i33];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_in4;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[6];
  int32_T c9_i34;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_in4 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_in4), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_in4);
  for (c9_i34 = 0; c9_i34 < 6; c9_i34++) {
    (*(real_T (*)[6])c9_outData)[c9_i34] = c9_y[c9_i34];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_f_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9])
{
  real_T c9_dv10[9];
  int32_T c9_i35;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv10, 1, 0, 0U, 1, 0U, 2, 1, 9);
  for (c9_i35 = 0; c9_i35 < 9; c9_i35++) {
    c9_y[c9_i35] = c9_dv10[c9_i35];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_in1;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i36;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_in1 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_in1), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_in1);
  for (c9_i36 = 0; c9_i36 < 9; c9_i36++) {
    (*(real_T (*)[9])c9_outData)[c9_i36] = c9_y[c9_i36];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray
  *sf_c9_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[8];
  c9_ResolvedFunctionInfo (*c9_b_info)[8];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i37;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_b_info = (c9_ResolvedFunctionInfo (*)[8])c9_info;
  (*c9_b_info)[0].context = "";
  (*c9_b_info)[0].name = "mrdivide";
  (*c9_b_info)[0].dominantType = "double";
  (*c9_b_info)[0].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c9_b_info)[0].fileTimeLo = 1325098938U;
  (*c9_b_info)[0].fileTimeHi = 0U;
  (*c9_b_info)[0].mFileTimeLo = 1319708366U;
  (*c9_b_info)[0].mFileTimeHi = 0U;
  (*c9_b_info)[1].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c9_b_info)[1].name = "rdivide";
  (*c9_b_info)[1].dominantType = "double";
  (*c9_b_info)[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c9_b_info)[1].fileTimeLo = 1286797244U;
  (*c9_b_info)[1].fileTimeHi = 0U;
  (*c9_b_info)[1].mFileTimeLo = 0U;
  (*c9_b_info)[1].mFileTimeHi = 0U;
  (*c9_b_info)[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c9_b_info)[2].name = "eml_div";
  (*c9_b_info)[2].dominantType = "double";
  (*c9_b_info)[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c9_b_info)[2].fileTimeLo = 1313326210U;
  (*c9_b_info)[2].fileTimeHi = 0U;
  (*c9_b_info)[2].mFileTimeLo = 0U;
  (*c9_b_info)[2].mFileTimeHi = 0U;
  (*c9_b_info)[3].context = "";
  (*c9_b_info)[3].name = "N_d";
  (*c9_b_info)[3].dominantType = "double";
  (*c9_b_info)[3].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/N_d.m";
  (*c9_b_info)[3].fileTimeLo = 1407925122U;
  (*c9_b_info)[3].fileTimeHi = 0U;
  (*c9_b_info)[3].mFileTimeLo = 0U;
  (*c9_b_info)[3].mFileTimeHi = 0U;
  (*c9_b_info)[4].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/N_d.m";
  (*c9_b_info)[4].name = "cos";
  (*c9_b_info)[4].dominantType = "double";
  (*c9_b_info)[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c9_b_info)[4].fileTimeLo = 1286797106U;
  (*c9_b_info)[4].fileTimeHi = 0U;
  (*c9_b_info)[4].mFileTimeLo = 0U;
  (*c9_b_info)[4].mFileTimeHi = 0U;
  (*c9_b_info)[5].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c9_b_info)[5].name = "eml_scalar_cos";
  (*c9_b_info)[5].dominantType = "double";
  (*c9_b_info)[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c9_b_info)[5].fileTimeLo = 1286797122U;
  (*c9_b_info)[5].fileTimeHi = 0U;
  (*c9_b_info)[5].mFileTimeLo = 0U;
  (*c9_b_info)[5].mFileTimeHi = 0U;
  (*c9_b_info)[6].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/N_d.m";
  (*c9_b_info)[6].name = "sin";
  (*c9_b_info)[6].dominantType = "double";
  (*c9_b_info)[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c9_b_info)[6].fileTimeLo = 1286797150U;
  (*c9_b_info)[6].fileTimeHi = 0U;
  (*c9_b_info)[6].mFileTimeLo = 0U;
  (*c9_b_info)[6].mFileTimeHi = 0U;
  (*c9_b_info)[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c9_b_info)[7].name = "eml_scalar_sin";
  (*c9_b_info)[7].dominantType = "double";
  (*c9_b_info)[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c9_b_info)[7].fileTimeLo = 1286797136U;
  (*c9_b_info)[7].fileTimeHi = 0U;
  (*c9_b_info)[7].mFileTimeLo = 0U;
  (*c9_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c9_i37 = 0; c9_i37 < 8; c9_i37++) {
    c9_r0 = &c9_info[c9_i37];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i37);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i37);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i37);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i37);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i37);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i37);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i37);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i37);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_N_d(SFc9_CtrPlatform_AdaptiveControl1InstanceStruct
                   *chartInstance, real_T c9_in1[9], real_T c9_in2[6], real_T
                   c9_in3[18], real_T c9_in4[6], real_T c9_g, real_T c9_N_d_[6])
{
  uint32_T c9_debug_family_var_map[107];
  real_T c9_A2;
  real_T c9_A3;
  real_T c9_A4;
  real_T c9_A5;
  real_T c9_A6;
  real_T c9_Cx2;
  real_T c9_Cx3;
  real_T c9_Cx4;
  real_T c9_Cx5;
  real_T c9_Cx6;
  real_T c9_Cy4;
  real_T c9_Cy5;
  real_T c9_Cy6;
  real_T c9_Cz2;
  real_T c9_Cz3;
  real_T c9_Cz4;
  real_T c9_Cz5;
  real_T c9_Cz6;
  real_T c9_L1;
  real_T c9_L2;
  real_T c9_L3;
  real_T c9_L4;
  real_T c9_L5;
  real_T c9_Ma2;
  real_T c9_Ma3;
  real_T c9_Ma4;
  real_T c9_Ma5;
  real_T c9_Ma6;
  real_T c9_t2;
  real_T c9_t3;
  real_T c9_t4;
  real_T c9_t5;
  real_T c9_t6;
  real_T c9_t7;
  real_T c9_t8;
  real_T c9_t9;
  real_T c9_t16;
  real_T c9_t10;
  real_T c9_t11;
  real_T c9_t12;
  real_T c9_t13;
  real_T c9_t14;
  real_T c9_t15;
  real_T c9_t17;
  real_T c9_t18;
  real_T c9_t19;
  real_T c9_t20;
  real_T c9_t21;
  real_T c9_t22;
  real_T c9_t23;
  real_T c9_t24;
  real_T c9_t25;
  real_T c9_t26;
  real_T c9_t27;
  real_T c9_t28;
  real_T c9_t29;
  real_T c9_t30;
  real_T c9_t36;
  real_T c9_t31;
  real_T c9_t32;
  real_T c9_t33;
  real_T c9_t34;
  real_T c9_t35;
  real_T c9_t37;
  real_T c9_t38;
  real_T c9_t39;
  real_T c9_t40;
  real_T c9_t41;
  real_T c9_t45;
  real_T c9_t42;
  real_T c9_t43;
  real_T c9_t46;
  real_T c9_t47;
  real_T c9_t44;
  real_T c9_t48;
  real_T c9_t49;
  real_T c9_t50;
  real_T c9_t57;
  real_T c9_t51;
  real_T c9_t52;
  real_T c9_t53;
  real_T c9_t54;
  real_T c9_t55;
  real_T c9_t56;
  real_T c9_t58;
  real_T c9_t59;
  real_T c9_t60;
  real_T c9_t61;
  real_T c9_t62;
  real_T c9_t63;
  real_T c9_t72;
  real_T c9_t64;
  real_T c9_t65;
  real_T c9_t66;
  real_T c9_t67;
  real_T c9_t68;
  real_T c9_t69;
  real_T c9_t70;
  real_T c9_t71;
  real_T c9_nargin = 5.0;
  real_T c9_nargout = 1.0;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_n_x;
  real_T c9_o_x;
  real_T c9_p_x;
  real_T c9_q_x;
  real_T c9_r_x;
  real_T c9_s_x;
  real_T c9_t_x;
  sf_debug_symbol_scope_push_eml(0U, 107U, 107U, c9_b_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c9_A2, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_A3, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_A4, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_A5, 3U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_A6, 4U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cx2, 5U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cx3, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cx4, 7U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cx5, 8U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cx6, 9U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cy4, 10U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cy5, 11U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cy6, 12U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cz2, 13U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cz3, 14U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cz4, 15U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cz5, 16U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Cz6, 17U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_L1, 18U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_L2, 19U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_L3, 20U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_L4, 21U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_L5, 22U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Ma2, 23U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Ma3, 24U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Ma4, 25U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Ma5, 26U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_Ma6, 27U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t2, 28U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t3, 29U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t4, 30U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t5, 31U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t6, 32U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t7, 33U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t8, 34U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t9, 35U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t16, 36U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t10, 37U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t11, 38U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t12, 39U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t13, 40U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t14, 41U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t15, 42U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t17, 43U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t18, 44U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t19, 45U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t20, 46U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t21, 47U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t22, 48U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t23, 49U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t24, 50U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t25, 51U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t26, 52U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t27, 53U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t28, 54U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t29, 55U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t30, 56U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t36, 57U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t31, 58U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t32, 59U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t33, 60U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t34, 61U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t35, 62U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t37, 63U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t38, 64U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t39, 65U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t40, 66U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t41, 67U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t45, 68U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t42, 69U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t43, 70U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t46, 71U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t47, 72U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t44, 73U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t48, 74U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t49, 75U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t50, 76U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t57, 77U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t51, 78U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t52, 79U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t53, 80U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t54, 81U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t55, 82U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t56, 83U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t58, 84U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t59, 85U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t60, 86U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t61, 87U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t62, 88U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t63, 89U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t72, 90U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t64, 91U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t65, 92U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t66, 93U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t67, 94U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t68, 95U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t69, 96U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t70, 97U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_t71, 98U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 99U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 100U,
    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_in1, 101U, c9_e_sf_marshallOut,
    c9_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_in2, 102U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_in3, 103U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_in4, 104U, c9_d_sf_marshallOut,
    c9_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_g, 105U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_N_d_, 106U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  c9_A2 = c9_in2[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 9);
  c9_A3 = c9_in2[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 10);
  c9_A4 = c9_in2[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  c9_A5 = c9_in2[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_A6 = c9_in2[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 13);
  c9_Cx2 = c9_in3[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 14);
  c9_Cx3 = c9_in3[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 15);
  c9_Cx4 = c9_in3[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 16);
  c9_Cx5 = c9_in3[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 17);
  c9_Cx6 = c9_in3[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 18);
  c9_Cy4 = c9_in3[9];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 19);
  c9_Cy5 = c9_in3[10];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 20);
  c9_Cy6 = c9_in3[11];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 21);
  c9_Cz2 = c9_in3[13];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 22);
  c9_Cz3 = c9_in3[14];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 23);
  c9_Cz4 = c9_in3[15];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 24);
  c9_Cz5 = c9_in3[16];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 25);
  c9_Cz6 = c9_in3[17];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 26);
  c9_L1 = c9_in1[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 27);
  c9_L2 = c9_in1[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 28);
  c9_L3 = c9_in1[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 29);
  c9_L4 = c9_in1[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 30);
  c9_L5 = c9_in1[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 31);
  c9_Ma2 = c9_in4[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 32);
  c9_Ma3 = c9_in4[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 33);
  c9_Ma4 = c9_in4[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 34);
  c9_Ma5 = c9_in4[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 35);
  c9_Ma6 = c9_in4[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 36);
  c9_x = c9_A3;
  c9_t2 = c9_x;
  c9_b_x = c9_t2;
  c9_t2 = c9_b_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 37);
  c9_t3 = c9_t2 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 38);
  c9_t4 = c9_L1 + c9_L3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 39);
  c9_c_x = c9_A3;
  c9_t5 = c9_c_x;
  c9_d_x = c9_t5;
  c9_t5 = c9_d_x;
  c9_t5 = muDoubleScalarSin(c9_t5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 40);
  c9_e_x = c9_A2;
  c9_t6 = c9_e_x;
  c9_f_x = c9_t6;
  c9_t6 = c9_f_x;
  c9_t6 = muDoubleScalarCos(c9_t6);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 41);
  c9_g_x = c9_A2;
  c9_t7 = c9_g_x;
  c9_h_x = c9_t7;
  c9_t7 = c9_h_x;
  c9_t7 = muDoubleScalarSin(c9_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 42);
  c9_i_x = c9_A5;
  c9_t8 = c9_i_x;
  c9_j_x = c9_t8;
  c9_t8 = c9_j_x;
  c9_t8 = muDoubleScalarSin(c9_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 43);
  c9_t9 = c9_t2 * c9_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 44);
  c9_t16 = c9_t5 * c9_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 45);
  c9_t10 = -c9_t16 + c9_t9;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 46);
  c9_k_x = c9_A5;
  c9_t11 = c9_k_x;
  c9_l_x = c9_t11;
  c9_t11 = c9_l_x;
  c9_t11 = muDoubleScalarCos(c9_t11);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 47);
  c9_t12 = c9_t5 * c9_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 48);
  c9_t13 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 49);
  c9_t14 = c9_t12 + c9_t13;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 50);
  c9_m_x = c9_A6;
  c9_t15 = c9_m_x;
  c9_n_x = c9_t15;
  c9_t15 = c9_n_x;
  c9_t15 = muDoubleScalarCos(c9_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 51);
  c9_t17 = c9_t10 * c9_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 52);
  c9_o_x = c9_A4;
  c9_t18 = c9_o_x;
  c9_p_x = c9_t18;
  c9_t18 = c9_p_x;
  c9_t18 = muDoubleScalarCos(c9_t18);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 53);
  c9_t19 = c9_t11 * c9_t14 * c9_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 54);
  c9_t20 = c9_t17 + c9_t19;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 55);
  c9_q_x = c9_A4;
  c9_t21 = c9_q_x;
  c9_r_x = c9_t21;
  c9_t21 = c9_r_x;
  c9_t21 = muDoubleScalarSin(c9_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 56);
  c9_s_x = c9_A6;
  c9_t22 = c9_s_x;
  c9_t_x = c9_t22;
  c9_t22 = c9_t_x;
  c9_t22 = muDoubleScalarSin(c9_t22);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 57);
  c9_t23 = (c9_L1 + c9_L3) + c9_L4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 58);
  c9_t24 = c9_L2 + c9_L5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 59);
  c9_t25 = c9_t11 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 60);
  c9_t26 = c9_t4 * c9_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 61);
  c9_t27 = c9_L2 * c9_t3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 62);
  c9_t28 = c9_t26 + c9_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 63);
  c9_t29 = c9_t28 * c9_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 64);
  c9_t30 = c9_L2 * c9_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 65);
  c9_t36 = c9_t3 * c9_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 66);
  c9_t31 = c9_t30 - c9_t36;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 67);
  c9_t32 = c9_L2 * c9_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 68);
  c9_t33 = c9_L1 * c9_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 69);
  c9_t34 = c9_t18 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 70);
  c9_t35 = c9_t14 * c9_t23 * c9_t34;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 71);
  c9_t37 = c9_t23 * c9_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 72);
  c9_t38 = c9_t24 * c9_t25;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 73);
  c9_t39 = c9_t37 + c9_t38;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 74);
  c9_t40 = c9_t10 * c9_t39;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 75);
  c9_t41 = c9_t10 * c9_t11;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 76);
  c9_t45 = c9_t14 * c9_t18 * c9_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 77);
  c9_t42 = c9_t41 - c9_t45;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 78);
  c9_t43 = c9_t23 * c9_t25;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 79);
  c9_t46 = c9_t24 * c9_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 80);
  c9_t47 = c9_t43 - c9_t46;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 81);
  c9_t44 = c9_t14 * c9_t18 * c9_t47;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 82);
  c9_t48 = c9_L2 * c9_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 83);
  c9_t49 = c9_t26 + c9_t48;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 84);
  c9_t50 = c9_t49 * c9_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 85);
  c9_t57 = c9_t2 * c9_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 86);
  c9_t51 = c9_t30 - c9_t57;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 87);
  c9_t52 = c9_t20 * c9_t22;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 88);
  c9_t53 = c9_t14 * c9_t15 * c9_t21;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 89);
  c9_t54 = c9_t52 + c9_t53;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 90);
  c9_t55 = c9_t15 * c9_t20;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 91);
  c9_t56 = c9_t55 - c9_t14 * c9_t21 * c9_t22;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 92);
  c9_t58 = c9_t51 * c9_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 93);
  c9_t59 = c9_t15 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 94);
  c9_t60 = c9_t20 * c9_t23 * c9_t59;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 95);
  c9_t61 = c9_t10 * c9_t21 * c9_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 96);
  c9_t62 = c9_t10 * c9_t21 * (c9_t43 - c9_t46);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 97);
  c9_t63 = c9_t14 * c9_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 98);
  c9_t72 = c9_t10 * c9_t11 * c9_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 99);
  c9_t64 = c9_t63 - c9_t72;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 100);
  c9_t65 = c9_t46 - c9_t11 * c9_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 101);
  c9_t66 = c9_t14 * c9_t65;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 102);
  c9_t67 = c9_t11 * c9_t14;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 103);
  c9_t68 = c9_t10 * c9_t18 * c9_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 104);
  c9_t69 = c9_t67 + c9_t68;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 105);
  c9_t70 = c9_t11 * c9_t24;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 106);
  c9_t71 = c9_t37 + c9_t70;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 107);
  c9_N_d_[0] = 0.0;
  c9_N_d_[1] = c9_g * ((((c9_Ma2 * (((c9_t32 + c9_t33) - c9_Cx2 * c9_t6) -
    c9_Cz2 * c9_t7) + c9_Ma4 * (((((((c9_t29 + c9_t32) + c9_t33) + c9_t35) -
    c9_Cx4 * c9_t10) - c9_t31 * c9_t7) - c9_Cy4 * c9_t14 * c9_t21) - c9_Cz4 *
    c9_t14 * c9_t18)) + c9_Ma5 * (((((((((c9_t29 + c9_t32) + c9_t33) + c9_t35) +
    c9_t40) + c9_t44) - c9_Cz5 * c9_t20) - c9_Cx5 * c9_t42) - c9_t31 * c9_t7) -
    c9_Cy5 * c9_t14 * c9_t21)) + c9_Ma3 * (((((c9_t29 + c9_t32) + c9_t33) -
    c9_Cx3 * c9_t10) - c9_Cz3 * c9_t14) - c9_t31 * c9_t7)) + c9_Ma6 *
                       (((((((((((c9_t29 + c9_t32) + c9_t33) + c9_t35) + c9_t40)
    + c9_t44) + c9_t60) - c9_Cx6 * c9_t42) - c9_Cy6 * c9_t54) - c9_Cz6 * c9_t56)
    - c9_t31 * c9_t7) - c9_t14 * c9_t21 * c9_t22 * c9_t23));
  c9_N_d_[2] = -c9_g * (((c9_Ma4 * (((((-c9_t35 - c9_t50) + c9_t58) + c9_Cx4 *
    c9_t10) + c9_Cy4 * c9_t14 * c9_t21) + c9_Cz4 * c9_t14 * c9_t18) - c9_Ma5 *
                          (((((((c9_t35 + c9_t40) + c9_t44) + c9_t50) - c9_t58)
    - c9_Cz5 * c9_t20) - c9_Cx5 * c9_t42) - c9_Cy5 * c9_t14 * c9_t21)) + c9_Ma3 *
                         (((-c9_t50 + c9_t58) + c9_Cx3 * c9_t10) + c9_Cz3 *
    c9_t14)) - c9_Ma6 * (((((((((c9_t35 + c9_t40) + c9_t44) + c9_t50) - c9_t58)
    + c9_t60) - c9_Cx6 * c9_t42) - c9_Cy6 * c9_t54) - c9_Cz6 * c9_t56) - c9_t14 *
    c9_t21 * c9_t22 * c9_t23));
  c9_N_d_[3] = c9_g * ((c9_Ma5 * ((((c9_t61 + c9_t62) + c9_Cy5 * c9_t10 * c9_t18)
    - c9_Cz5 * c9_t10 * c9_t11 * c9_t21) + c9_Cx5 * c9_t10 * c9_t21 * c9_t8) +
                        c9_Ma4 * ((c9_t61 + c9_Cy4 * c9_t10 * c9_t18) - c9_Cz4 *
    c9_t10 * c9_t21)) + c9_Ma6 * ((((((c9_t61 + c9_t62) + c9_Cy6 * (c9_t10 *
    c9_t15 * c9_t18 - c9_t10 * c9_t11 * c9_t21 * c9_t22)) - c9_Cz6 * (c9_t10 *
    c9_t18 * c9_t22 + c9_t10 * c9_t11 * c9_t15 * c9_t21)) + c9_t10 * c9_t18 *
    c9_t22 * c9_t23) + c9_Cx6 * c9_t10 * c9_t21 * c9_t8) + c9_t10 * c9_t11 *
    c9_t21 * c9_t23 * c9_t59));
  c9_N_d_[4] = -c9_g * (c9_Ma6 * (((((c9_t66 - c9_Cx6 * c9_t64) + c9_Cy6 *
    c9_t22 * c9_t69) + c9_Cz6 * c9_t15 * c9_t69) - c9_t10 * c9_t18 * c9_t71) -
    c9_t23 * c9_t59 * c9_t69) + c9_Ma5 * (((c9_t66 - c9_Cx5 * c9_t64) + c9_Cz5 *
    c9_t69) - c9_t10 * c9_t18 * c9_t71));
  c9_N_d_[5] = -c9_Ma6 * c9_g * (((c9_Cy6 * (c9_t15 * c9_t64 + c9_t10 * c9_t21 *
    c9_t22) - c9_Cz6 * (c9_t22 * c9_t64 - c9_t10 * c9_t15 * c9_t21)) + c9_t22 *
    c9_t23 * c9_t64) - c9_t10 * c9_t15 * c9_t21 * c9_t23);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -107);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_g_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i38;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i38, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i38;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_h_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_b_is_active_c9_CtrPlatform_AdaptiveControl1, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_CtrPlatform_AdaptiveControl1), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_CtrPlatform_AdaptiveControl1);
  return c9_y;
}

static uint8_T c9_i_emlrt_marshallIn
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info
  (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3914493208U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1642157977U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3894249283U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1015676195U);
}

mxArray *sf_c9_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("O5G5Vq8ctoyPmxehF46mJ");
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(18);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(9);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"N\",},{M[8],M[0],T\"is_active_c9_CtrPlatform_AdaptiveControl1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_CtrPlatform_AdaptiveControl1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
    chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_AdaptiveControl1MachineNumber_,
           9,
           1,
           1,
           6,
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
          init_script_number_translation
            (_CtrPlatform_AdaptiveControl1MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_CtrPlatform_AdaptiveControl1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_CtrPlatform_AdaptiveControl1MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EnTheta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"N");
          _SFD_SET_DATA_PROPS(2,10,0,0,"L");
          _SFD_SET_DATA_PROPS(3,10,0,0,"Cen");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Ma");
          _SFD_SET_DATA_PROPS(5,10,0,0,"Gravity");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,102);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"N_d",0,-1,2808);
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
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_e_sf_marshallOut,(MexInFcnForType)
            c9_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)
            c9_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)
            c9_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          real_T (*c9_EnTheta)[6];
          real_T (*c9_N)[6];
          c9_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c9_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_EnTheta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_N);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_L);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_Cen);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_Ma);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c9_Gravity);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_CtrPlatform_AdaptiveControl1MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "YGtedQocc3fZJipyg4zjpB";
}

static void sf_opaque_initialize_c9_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
  initialize_c9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  enable_c9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  disable_c9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  sf_c9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_CtrPlatform_AdaptiveControl1
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl1();/* state var info */
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

extern void sf_internal_set_sim_state_c9_CtrPlatform_AdaptiveControl1(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_CtrPlatform_AdaptiveControl1
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c9_CtrPlatform_AdaptiveControl1(S);
}

static void sf_opaque_set_sim_state_c9_CtrPlatform_AdaptiveControl1(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c9_CtrPlatform_AdaptiveControl1(S, st);
}

static void sf_opaque_terminate_c9_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_CtrPlatform_AdaptiveControl1
      ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_AdaptiveControl1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_CtrPlatform_AdaptiveControl1
    ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_CtrPlatform_AdaptiveControl1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_CtrPlatform_AdaptiveControl1
      ((SFc9_CtrPlatform_AdaptiveControl1InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_CtrPlatform_AdaptiveControl1(SimStruct *S)
{
  /* Actual parameters from chart:
     Cen Gravity L Ma
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Cen*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Gravity*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for Ma*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CtrPlatform_AdaptiveControl1_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1438597089U));
  ssSetChecksum1(S,(464066716U));
  ssSetChecksum2(S,(1119848644U));
  ssSetChecksum3(S,(763039441U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_CtrPlatform_AdaptiveControl1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_CtrPlatform_AdaptiveControl1(SimStruct *S)
{
  SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct *)malloc
    (sizeof(SFc9_CtrPlatform_AdaptiveControl1InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc9_CtrPlatform_AdaptiveControl1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_CtrPlatform_AdaptiveControl1;
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

void c9_CtrPlatform_AdaptiveControl1_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_CtrPlatform_AdaptiveControl1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_CtrPlatform_AdaptiveControl1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_CtrPlatform_AdaptiveControl1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_CtrPlatform_AdaptiveControl1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
