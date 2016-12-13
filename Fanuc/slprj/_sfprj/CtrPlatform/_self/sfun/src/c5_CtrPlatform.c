/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_sfun.h"
#include "c5_CtrPlatform.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[8] = { "L", "Ma", "nargin", "nargout",
  "EnTheta", "Cen", "Gravity", "N" };

static const char * c5_b_debug_family_names[107] = { "A2", "A3", "A4", "A5",
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
static void initialize_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance);
static void initialize_params_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance);
static void enable_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct *chartInstance);
static void disable_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_CtrPlatform
  (SFc5_CtrPlatformInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_CtrPlatform
  (SFc5_CtrPlatformInstanceStruct *chartInstance);
static void set_sim_state_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance);
static void sf_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct *chartInstance);
static void initSimStructsc5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_N, const char_T *c5_identifier, real_T c5_y[6]);
static void c5_b_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[6]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_d_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[18]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_e_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[6]);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_f_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9]);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_N_d(SFc5_CtrPlatformInstanceStruct *chartInstance, real_T c5_in1
                   [9], real_T c5_in2[6], real_T c5_in3[18], real_T c5_in4[6],
                   real_T c5_g, real_T c5_N_d_[6]);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_g_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_h_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_CtrPlatform, const char_T
  *c5_identifier);
static uint8_T c5_i_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_CtrPlatformInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_CtrPlatform = 0U;
}

static void initialize_params_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance)
{
  real_T c5_dv0[9];
  int32_T c5_i0;
  real_T c5_dv1[18];
  int32_T c5_i1;
  real_T c5_dv2[6];
  int32_T c5_i2;
  real_T c5_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import_named("L", sf_mex_get_sfun_param(chartInstance->S, 2, 0), c5_dv0,
                      0, 0, 0U, 1, 0U, 2, 1, 9);
  for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
    chartInstance->c5_L[c5_i0] = c5_dv0[c5_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Cen' in the parent workspace.\n");
  sf_mex_import_named("Cen", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c5_dv1, 0, 0, 0U, 1, 0U, 2, 1, 18);
  for (c5_i1 = 0; c5_i1 < 18; c5_i1++) {
    chartInstance->c5_Cen[c5_i1] = c5_dv1[c5_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Ma' in the parent workspace.\n");
  sf_mex_import_named("Ma", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      c5_dv2, 0, 0, 0U, 1, 0U, 2, 1, 6);
  for (c5_i2 = 0; c5_i2 < 6; c5_i2++) {
    chartInstance->c5_Ma[c5_i2] = c5_dv2[c5_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'Gravity' in the parent workspace.\n");
  sf_mex_import_named("Gravity", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      &c5_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c5_Gravity = c5_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_CtrPlatform
  (SFc5_CtrPlatformInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_CtrPlatform
  (SFc5_CtrPlatformInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i3;
  real_T c5_u[6];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_N)[6];
  c5_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2), FALSE);
  for (c5_i3 = 0; c5_i3 < 6; c5_i3++) {
    c5_u[c5_i3] = (*c5_N)[c5_i3];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_CtrPlatform;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv3[6];
  int32_T c5_i4;
  real_T (*c5_N)[6];
  c5_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "N",
                      c5_dv3);
  for (c5_i4 = 0; c5_i4 < 6; c5_i4++) {
    (*c5_N)[c5_i4] = c5_dv3[c5_i4];
  }

  chartInstance->c5_is_active_c5_CtrPlatform = c5_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_CtrPlatform");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_CtrPlatform(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance)
{
}

static void sf_c5_CtrPlatform(SFc5_CtrPlatformInstanceStruct *chartInstance)
{
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_hoistedGlobal;
  int32_T c5_i10;
  real_T c5_EnTheta[6];
  int32_T c5_i11;
  real_T c5_b_Cen[18];
  real_T c5_b_Gravity;
  uint32_T c5_debug_family_var_map[8];
  real_T c5_c_L[9];
  real_T c5_c_Ma[6];
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 1.0;
  real_T c5_N[6];
  int32_T c5_i12;
  static real_T c5_d_Ma[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  int32_T c5_i13;
  static real_T c5_d_L[9] = { 566.0, 150.0, 870.0, 170.0, 1016.0, 154.0, 20.0,
    0.0, 0.0 };

  int32_T c5_i14;
  int32_T c5_i15;
  static real_T c5_dv4[9] = { 0.566, 0.15, 0.87, 0.17, 1.016, 0.154, 0.02, 0.0,
    0.0 };

  real_T c5_dv5[9];
  int32_T c5_i16;
  real_T c5_b_EnTheta[6];
  int32_T c5_i17;
  real_T c5_c_Cen[18];
  int32_T c5_i18;
  real_T c5_e_Ma[6];
  real_T c5_dv6[6];
  int32_T c5_i19;
  int32_T c5_i20;
  real_T (*c5_b_N)[6];
  real_T (*c5_c_EnTheta)[6];
  c5_b_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_c_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  for (c5_i5 = 0; c5_i5 < 6; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*c5_c_EnTheta)[c5_i5], 0U);
  }

  for (c5_i6 = 0; c5_i6 < 6; c5_i6++) {
    _SFD_DATA_RANGE_CHECK((*c5_b_N)[c5_i6], 1U);
  }

  for (c5_i7 = 0; c5_i7 < 9; c5_i7++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_L[c5_i7], 2U);
  }

  for (c5_i8 = 0; c5_i8 < 18; c5_i8++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_Cen[c5_i8], 3U);
  }

  for (c5_i9 = 0; c5_i9 < 6; c5_i9++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_Ma[c5_i9], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c5_Gravity, 5U);
  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = chartInstance->c5_Gravity;
  for (c5_i10 = 0; c5_i10 < 6; c5_i10++) {
    c5_EnTheta[c5_i10] = (*c5_c_EnTheta)[c5_i10];
  }

  for (c5_i11 = 0; c5_i11 < 18; c5_i11++) {
    c5_b_Cen[c5_i11] = chartInstance->c5_Cen[c5_i11];
  }

  c5_b_Gravity = c5_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c5_c_L, 0U, c5_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_c_Ma, 1U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c5_EnTheta, 4U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_b_Cen, 5U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_b_Gravity, 6U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_N, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  for (c5_i12 = 0; c5_i12 < 6; c5_i12++) {
    c5_c_Ma[c5_i12] = c5_d_Ma[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 9; c5_i13++) {
    c5_c_L[c5_i13] = c5_d_L[c5_i13];
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 3);
  for (c5_i14 = 0; c5_i14 < 6; c5_i14++) {
    c5_N[c5_i14] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 4);
  for (c5_i15 = 0; c5_i15 < 9; c5_i15++) {
    c5_dv5[c5_i15] = c5_dv4[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 6; c5_i16++) {
    c5_b_EnTheta[c5_i16] = c5_EnTheta[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 18; c5_i17++) {
    c5_c_Cen[c5_i17] = c5_b_Cen[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 6; c5_i18++) {
    c5_e_Ma[c5_i18] = c5_d_Ma[c5_i18];
  }

  c5_N_d(chartInstance, c5_dv5, c5_b_EnTheta, c5_c_Cen, c5_e_Ma, c5_b_Gravity,
         c5_dv6);
  for (c5_i19 = 0; c5_i19 < 6; c5_i19++) {
    c5_N[c5_i19] = c5_dv6[c5_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c5_i20 = 0; c5_i20 < 6; c5_i20++) {
    (*c5_b_N)[c5_i20] = c5_N[c5_i20];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c5_sfEvent);
  sf_debug_check_for_state_inconsistency(_CtrPlatformMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc5_CtrPlatform(SFc5_CtrPlatformInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, 0U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/InternFromZHAOTX/Fanuc/N_d.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i21;
  real_T c5_b_inData[6];
  int32_T c5_i22;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i21 = 0; c5_i21 < 6; c5_i21++) {
    c5_b_inData[c5_i21] = (*(real_T (*)[6])c5_inData)[c5_i21];
  }

  for (c5_i22 = 0; c5_i22 < 6; c5_i22++) {
    c5_u[c5_i22] = c5_b_inData[c5_i22];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_N, const char_T *c5_identifier, real_T c5_y[6])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_N), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_N);
}

static void c5_b_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[6])
{
  real_T c5_dv7[6];
  int32_T c5_i23;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv7, 1, 0, 0U, 1, 0U, 1, 6);
  for (c5_i23 = 0; c5_i23 < 6; c5_i23++) {
    c5_y[c5_i23] = c5_dv7[c5_i23];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_N;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[6];
  int32_T c5_i24;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_N = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_N), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_N);
  for (c5_i24 = 0; c5_i24 < 6; c5_i24++) {
    (*(real_T (*)[6])c5_outData)[c5_i24] = c5_y[c5_i24];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d1;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d1, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d1;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_Gravity;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_b_Gravity = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_Gravity),
    &c5_thisId);
  sf_mex_destroy(&c5_b_Gravity);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i25;
  real_T c5_b_inData[18];
  int32_T c5_i26;
  real_T c5_u[18];
  const mxArray *c5_y = NULL;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i25 = 0; c5_i25 < 18; c5_i25++) {
    c5_b_inData[c5_i25] = (*(real_T (*)[18])c5_inData)[c5_i25];
  }

  for (c5_i26 = 0; c5_i26 < 18; c5_i26++) {
    c5_u[c5_i26] = c5_b_inData[c5_i26];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 18), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_d_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[18])
{
  real_T c5_dv8[18];
  int32_T c5_i27;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv8, 1, 0, 0U, 1, 0U, 2, 1, 18);
  for (c5_i27 = 0; c5_i27 < 18; c5_i27++) {
    c5_y[c5_i27] = c5_dv8[c5_i27];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_Cen;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[18];
  int32_T c5_i28;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_b_Cen = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_Cen), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_b_Cen);
  for (c5_i28 = 0; c5_i28 < 18; c5_i28++) {
    (*(real_T (*)[18])c5_outData)[c5_i28] = c5_y[c5_i28];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i29;
  real_T c5_b_inData[6];
  int32_T c5_i30;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i29 = 0; c5_i29 < 6; c5_i29++) {
    c5_b_inData[c5_i29] = (*(real_T (*)[6])c5_inData)[c5_i29];
  }

  for (c5_i30 = 0; c5_i30 < 6; c5_i30++) {
    c5_u[c5_i30] = c5_b_inData[c5_i30];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i31;
  real_T c5_b_inData[9];
  int32_T c5_i32;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i31 = 0; c5_i31 < 9; c5_i31++) {
    c5_b_inData[c5_i31] = (*(real_T (*)[9])c5_inData)[c5_i31];
  }

  for (c5_i32 = 0; c5_i32 < 9; c5_i32++) {
    c5_u[c5_i32] = c5_b_inData[c5_i32];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_e_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[6])
{
  real_T c5_dv9[6];
  int32_T c5_i33;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv9, 1, 0, 0U, 1, 0U, 2, 1, 6);
  for (c5_i33 = 0; c5_i33 < 6; c5_i33++) {
    c5_y[c5_i33] = c5_dv9[c5_i33];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_in4;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[6];
  int32_T c5_i34;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_in4 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_in4), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_in4);
  for (c5_i34 = 0; c5_i34 < 6; c5_i34++) {
    (*(real_T (*)[6])c5_outData)[c5_i34] = c5_y[c5_i34];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_f_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct *chartInstance,
  const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_y[9])
{
  real_T c5_dv10[9];
  int32_T c5_i35;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv10, 1, 0, 0U, 1, 0U, 2, 1, 9);
  for (c5_i35 = 0; c5_i35 < 9; c5_i35++) {
    c5_y[c5_i35] = c5_dv10[c5_i35];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_in1;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[9];
  int32_T c5_i36;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_in1 = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_in1), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_in1);
  for (c5_i36 = 0; c5_i36 < 9; c5_i36++) {
    (*(real_T (*)[9])c5_outData)[c5_i36] = c5_y[c5_i36];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_CtrPlatform_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[8];
  c5_ResolvedFunctionInfo (*c5_b_info)[8];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i37;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[8])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "mrdivide";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c5_b_info)[0].fileTimeLo = 1325098938U;
  (*c5_b_info)[0].fileTimeHi = 0U;
  (*c5_b_info)[0].mFileTimeLo = 1319708366U;
  (*c5_b_info)[0].mFileTimeHi = 0U;
  (*c5_b_info)[1].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c5_b_info)[1].name = "rdivide";
  (*c5_b_info)[1].dominantType = "double";
  (*c5_b_info)[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c5_b_info)[1].fileTimeLo = 1286797244U;
  (*c5_b_info)[1].fileTimeHi = 0U;
  (*c5_b_info)[1].mFileTimeLo = 0U;
  (*c5_b_info)[1].mFileTimeHi = 0U;
  (*c5_b_info)[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c5_b_info)[2].name = "eml_div";
  (*c5_b_info)[2].dominantType = "double";
  (*c5_b_info)[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c5_b_info)[2].fileTimeLo = 1313326210U;
  (*c5_b_info)[2].fileTimeHi = 0U;
  (*c5_b_info)[2].mFileTimeLo = 0U;
  (*c5_b_info)[2].mFileTimeHi = 0U;
  (*c5_b_info)[3].context = "";
  (*c5_b_info)[3].name = "N_d";
  (*c5_b_info)[3].dominantType = "double";
  (*c5_b_info)[3].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/N_d.m";
  (*c5_b_info)[3].fileTimeLo = 1407925122U;
  (*c5_b_info)[3].fileTimeHi = 0U;
  (*c5_b_info)[3].mFileTimeLo = 0U;
  (*c5_b_info)[3].mFileTimeHi = 0U;
  (*c5_b_info)[4].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/N_d.m";
  (*c5_b_info)[4].name = "cos";
  (*c5_b_info)[4].dominantType = "double";
  (*c5_b_info)[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[4].fileTimeLo = 1286797106U;
  (*c5_b_info)[4].fileTimeHi = 0U;
  (*c5_b_info)[4].mFileTimeLo = 0U;
  (*c5_b_info)[4].mFileTimeHi = 0U;
  (*c5_b_info)[5].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c5_b_info)[5].name = "eml_scalar_cos";
  (*c5_b_info)[5].dominantType = "double";
  (*c5_b_info)[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c5_b_info)[5].fileTimeLo = 1286797122U;
  (*c5_b_info)[5].fileTimeHi = 0U;
  (*c5_b_info)[5].mFileTimeLo = 0U;
  (*c5_b_info)[5].mFileTimeHi = 0U;
  (*c5_b_info)[6].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/N_d.m";
  (*c5_b_info)[6].name = "sin";
  (*c5_b_info)[6].dominantType = "double";
  (*c5_b_info)[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[6].fileTimeLo = 1286797150U;
  (*c5_b_info)[6].fileTimeHi = 0U;
  (*c5_b_info)[6].mFileTimeLo = 0U;
  (*c5_b_info)[6].mFileTimeHi = 0U;
  (*c5_b_info)[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c5_b_info)[7].name = "eml_scalar_sin";
  (*c5_b_info)[7].dominantType = "double";
  (*c5_b_info)[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c5_b_info)[7].fileTimeLo = 1286797136U;
  (*c5_b_info)[7].fileTimeHi = 0U;
  (*c5_b_info)[7].mFileTimeLo = 0U;
  (*c5_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c5_i37 = 0; c5_i37 < 8; c5_i37++) {
    c5_r0 = &c5_info[c5_i37];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i37);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i37);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i37);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i37);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i37);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i37);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i37);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i37);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_N_d(SFc5_CtrPlatformInstanceStruct *chartInstance, real_T c5_in1
                   [9], real_T c5_in2[6], real_T c5_in3[18], real_T c5_in4[6],
                   real_T c5_g, real_T c5_N_d_[6])
{
  uint32_T c5_debug_family_var_map[107];
  real_T c5_A2;
  real_T c5_A3;
  real_T c5_A4;
  real_T c5_A5;
  real_T c5_A6;
  real_T c5_Cx2;
  real_T c5_Cx3;
  real_T c5_Cx4;
  real_T c5_Cx5;
  real_T c5_Cx6;
  real_T c5_Cy4;
  real_T c5_Cy5;
  real_T c5_Cy6;
  real_T c5_Cz2;
  real_T c5_Cz3;
  real_T c5_Cz4;
  real_T c5_Cz5;
  real_T c5_Cz6;
  real_T c5_L1;
  real_T c5_L2;
  real_T c5_L3;
  real_T c5_L4;
  real_T c5_L5;
  real_T c5_Ma2;
  real_T c5_Ma3;
  real_T c5_Ma4;
  real_T c5_Ma5;
  real_T c5_Ma6;
  real_T c5_t2;
  real_T c5_t3;
  real_T c5_t4;
  real_T c5_t5;
  real_T c5_t6;
  real_T c5_t7;
  real_T c5_t8;
  real_T c5_t9;
  real_T c5_t16;
  real_T c5_t10;
  real_T c5_t11;
  real_T c5_t12;
  real_T c5_t13;
  real_T c5_t14;
  real_T c5_t15;
  real_T c5_t17;
  real_T c5_t18;
  real_T c5_t19;
  real_T c5_t20;
  real_T c5_t21;
  real_T c5_t22;
  real_T c5_t23;
  real_T c5_t24;
  real_T c5_t25;
  real_T c5_t26;
  real_T c5_t27;
  real_T c5_t28;
  real_T c5_t29;
  real_T c5_t30;
  real_T c5_t36;
  real_T c5_t31;
  real_T c5_t32;
  real_T c5_t33;
  real_T c5_t34;
  real_T c5_t35;
  real_T c5_t37;
  real_T c5_t38;
  real_T c5_t39;
  real_T c5_t40;
  real_T c5_t41;
  real_T c5_t45;
  real_T c5_t42;
  real_T c5_t43;
  real_T c5_t46;
  real_T c5_t47;
  real_T c5_t44;
  real_T c5_t48;
  real_T c5_t49;
  real_T c5_t50;
  real_T c5_t57;
  real_T c5_t51;
  real_T c5_t52;
  real_T c5_t53;
  real_T c5_t54;
  real_T c5_t55;
  real_T c5_t56;
  real_T c5_t58;
  real_T c5_t59;
  real_T c5_t60;
  real_T c5_t61;
  real_T c5_t62;
  real_T c5_t63;
  real_T c5_t72;
  real_T c5_t64;
  real_T c5_t65;
  real_T c5_t66;
  real_T c5_t67;
  real_T c5_t68;
  real_T c5_t69;
  real_T c5_t70;
  real_T c5_t71;
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 1.0;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_m_x;
  real_T c5_n_x;
  real_T c5_o_x;
  real_T c5_p_x;
  real_T c5_q_x;
  real_T c5_r_x;
  real_T c5_s_x;
  real_T c5_t_x;
  sf_debug_symbol_scope_push_eml(0U, 107U, 107U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c5_A2, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A3, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A4, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A5, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_A6, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cx2, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cx3, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cx4, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cx5, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cx6, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cy4, 10U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cy5, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cy6, 12U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cz2, 13U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cz3, 14U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cz4, 15U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cz5, 16U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Cz6, 17U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_L1, 18U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_L2, 19U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_L3, 20U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_L4, 21U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_L5, 22U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Ma2, 23U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Ma3, 24U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Ma4, 25U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Ma5, 26U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_Ma6, 27U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t2, 28U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t3, 29U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t4, 30U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t5, 31U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t6, 32U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t7, 33U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t8, 34U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t9, 35U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t16, 36U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t10, 37U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t11, 38U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t12, 39U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t13, 40U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t14, 41U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t15, 42U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t17, 43U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t18, 44U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t19, 45U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t20, 46U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t21, 47U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t22, 48U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t23, 49U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t24, 50U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t25, 51U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t26, 52U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t27, 53U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t28, 54U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t29, 55U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t30, 56U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t36, 57U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t31, 58U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t32, 59U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t33, 60U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t34, 61U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t35, 62U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t37, 63U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t38, 64U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t39, 65U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t40, 66U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t41, 67U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t45, 68U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t42, 69U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t43, 70U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t46, 71U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t47, 72U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t44, 73U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t48, 74U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t49, 75U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t50, 76U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t57, 77U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t51, 78U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t52, 79U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t53, 80U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t54, 81U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t55, 82U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t56, 83U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t58, 84U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t59, 85U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t60, 86U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t61, 87U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t62, 88U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t63, 89U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t72, 90U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t64, 91U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t65, 92U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t66, 93U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t67, 94U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t68, 95U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t69, 96U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t70, 97U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_t71, 98U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 99U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 100U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_in1, 101U, c5_e_sf_marshallOut,
    c5_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_in2, 102U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_in3, 103U, c5_c_sf_marshallOut,
    c5_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_in4, 104U, c5_d_sf_marshallOut,
    c5_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_g, 105U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_N_d_, 106U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 8);
  c5_A2 = c5_in2[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  c5_A3 = c5_in2[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_A4 = c5_in2[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 11);
  c5_A5 = c5_in2[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 12);
  c5_A6 = c5_in2[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 13);
  c5_Cx2 = c5_in3[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_Cx3 = c5_in3[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_Cx4 = c5_in3[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_Cx5 = c5_in3[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_Cx6 = c5_in3[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 18);
  c5_Cy4 = c5_in3[9];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_Cy5 = c5_in3[10];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 20);
  c5_Cy6 = c5_in3[11];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 21);
  c5_Cz2 = c5_in3[13];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 22);
  c5_Cz3 = c5_in3[14];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 23);
  c5_Cz4 = c5_in3[15];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 24);
  c5_Cz5 = c5_in3[16];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 25);
  c5_Cz6 = c5_in3[17];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 26);
  c5_L1 = c5_in1[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 27);
  c5_L2 = c5_in1[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 28);
  c5_L3 = c5_in1[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 29);
  c5_L4 = c5_in1[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 30);
  c5_L5 = c5_in1[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 31);
  c5_Ma2 = c5_in4[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 32);
  c5_Ma3 = c5_in4[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 33);
  c5_Ma4 = c5_in4[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 34);
  c5_Ma5 = c5_in4[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 35);
  c5_Ma6 = c5_in4[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 36);
  c5_x = c5_A3;
  c5_t2 = c5_x;
  c5_b_x = c5_t2;
  c5_t2 = c5_b_x;
  c5_t2 = muDoubleScalarCos(c5_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 37);
  c5_t3 = c5_t2 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 38);
  c5_t4 = c5_L1 + c5_L3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 39);
  c5_c_x = c5_A3;
  c5_t5 = c5_c_x;
  c5_d_x = c5_t5;
  c5_t5 = c5_d_x;
  c5_t5 = muDoubleScalarSin(c5_t5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 40);
  c5_e_x = c5_A2;
  c5_t6 = c5_e_x;
  c5_f_x = c5_t6;
  c5_t6 = c5_f_x;
  c5_t6 = muDoubleScalarCos(c5_t6);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 41);
  c5_g_x = c5_A2;
  c5_t7 = c5_g_x;
  c5_h_x = c5_t7;
  c5_t7 = c5_h_x;
  c5_t7 = muDoubleScalarSin(c5_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 42);
  c5_i_x = c5_A5;
  c5_t8 = c5_i_x;
  c5_j_x = c5_t8;
  c5_t8 = c5_j_x;
  c5_t8 = muDoubleScalarSin(c5_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 43);
  c5_t9 = c5_t2 * c5_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 44);
  c5_t16 = c5_t5 * c5_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 45);
  c5_t10 = -c5_t16 + c5_t9;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 46);
  c5_k_x = c5_A5;
  c5_t11 = c5_k_x;
  c5_l_x = c5_t11;
  c5_t11 = c5_l_x;
  c5_t11 = muDoubleScalarCos(c5_t11);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 47);
  c5_t12 = c5_t5 * c5_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 48);
  c5_t13 = c5_t2 * c5_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 49);
  c5_t14 = c5_t12 + c5_t13;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 50);
  c5_m_x = c5_A6;
  c5_t15 = c5_m_x;
  c5_n_x = c5_t15;
  c5_t15 = c5_n_x;
  c5_t15 = muDoubleScalarCos(c5_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 51);
  c5_t17 = c5_t10 * c5_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 52);
  c5_o_x = c5_A4;
  c5_t18 = c5_o_x;
  c5_p_x = c5_t18;
  c5_t18 = c5_p_x;
  c5_t18 = muDoubleScalarCos(c5_t18);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 53);
  c5_t19 = c5_t11 * c5_t14 * c5_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 54);
  c5_t20 = c5_t17 + c5_t19;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 55);
  c5_q_x = c5_A4;
  c5_t21 = c5_q_x;
  c5_r_x = c5_t21;
  c5_t21 = c5_r_x;
  c5_t21 = muDoubleScalarSin(c5_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 56);
  c5_s_x = c5_A6;
  c5_t22 = c5_s_x;
  c5_t_x = c5_t22;
  c5_t22 = c5_t_x;
  c5_t22 = muDoubleScalarSin(c5_t22);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 57);
  c5_t23 = (c5_L1 + c5_L3) + c5_L4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 58);
  c5_t24 = c5_L2 + c5_L5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 59);
  c5_t25 = c5_t11 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 60);
  c5_t26 = c5_t4 * c5_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 61);
  c5_t27 = c5_L2 * c5_t3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 62);
  c5_t28 = c5_t26 + c5_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 63);
  c5_t29 = c5_t28 * c5_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 64);
  c5_t30 = c5_L2 * c5_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 65);
  c5_t36 = c5_t3 * c5_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 66);
  c5_t31 = c5_t30 - c5_t36;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 67);
  c5_t32 = c5_L2 * c5_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 68);
  c5_t33 = c5_L1 * c5_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 69);
  c5_t34 = c5_t18 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 70);
  c5_t35 = c5_t14 * c5_t23 * c5_t34;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 71);
  c5_t37 = c5_t23 * c5_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 72);
  c5_t38 = c5_t24 * c5_t25;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 73);
  c5_t39 = c5_t37 + c5_t38;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 74);
  c5_t40 = c5_t10 * c5_t39;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 75);
  c5_t41 = c5_t10 * c5_t11;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 76);
  c5_t45 = c5_t14 * c5_t18 * c5_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 77);
  c5_t42 = c5_t41 - c5_t45;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 78);
  c5_t43 = c5_t23 * c5_t25;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 79);
  c5_t46 = c5_t24 * c5_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 80);
  c5_t47 = c5_t43 - c5_t46;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 81);
  c5_t44 = c5_t14 * c5_t18 * c5_t47;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 82);
  c5_t48 = c5_L2 * c5_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 83);
  c5_t49 = c5_t26 + c5_t48;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 84);
  c5_t50 = c5_t49 * c5_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 85);
  c5_t57 = c5_t2 * c5_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 86);
  c5_t51 = c5_t30 - c5_t57;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 87);
  c5_t52 = c5_t20 * c5_t22;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 88);
  c5_t53 = c5_t14 * c5_t15 * c5_t21;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 89);
  c5_t54 = c5_t52 + c5_t53;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 90);
  c5_t55 = c5_t15 * c5_t20;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 91);
  c5_t56 = c5_t55 - c5_t14 * c5_t21 * c5_t22;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 92);
  c5_t58 = c5_t51 * c5_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 93);
  c5_t59 = c5_t15 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 94);
  c5_t60 = c5_t20 * c5_t23 * c5_t59;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 95);
  c5_t61 = c5_t10 * c5_t21 * c5_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 96);
  c5_t62 = c5_t10 * c5_t21 * (c5_t43 - c5_t46);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 97);
  c5_t63 = c5_t14 * c5_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 98);
  c5_t72 = c5_t10 * c5_t11 * c5_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 99);
  c5_t64 = c5_t63 - c5_t72;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 100);
  c5_t65 = c5_t46 - c5_t11 * c5_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 101);
  c5_t66 = c5_t14 * c5_t65;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 102);
  c5_t67 = c5_t11 * c5_t14;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 103);
  c5_t68 = c5_t10 * c5_t18 * c5_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 104);
  c5_t69 = c5_t67 + c5_t68;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 105);
  c5_t70 = c5_t11 * c5_t24;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 106);
  c5_t71 = c5_t37 + c5_t70;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 107);
  c5_N_d_[0] = 0.0;
  c5_N_d_[1] = c5_g * ((((c5_Ma2 * (((c5_t32 + c5_t33) - c5_Cx2 * c5_t6) -
    c5_Cz2 * c5_t7) + c5_Ma4 * (((((((c5_t29 + c5_t32) + c5_t33) + c5_t35) -
    c5_Cx4 * c5_t10) - c5_t31 * c5_t7) - c5_Cy4 * c5_t14 * c5_t21) - c5_Cz4 *
    c5_t14 * c5_t18)) + c5_Ma5 * (((((((((c5_t29 + c5_t32) + c5_t33) + c5_t35) +
    c5_t40) + c5_t44) - c5_Cz5 * c5_t20) - c5_Cx5 * c5_t42) - c5_t31 * c5_t7) -
    c5_Cy5 * c5_t14 * c5_t21)) + c5_Ma3 * (((((c5_t29 + c5_t32) + c5_t33) -
    c5_Cx3 * c5_t10) - c5_Cz3 * c5_t14) - c5_t31 * c5_t7)) + c5_Ma6 *
                       (((((((((((c5_t29 + c5_t32) + c5_t33) + c5_t35) + c5_t40)
    + c5_t44) + c5_t60) - c5_Cx6 * c5_t42) - c5_Cy6 * c5_t54) - c5_Cz6 * c5_t56)
    - c5_t31 * c5_t7) - c5_t14 * c5_t21 * c5_t22 * c5_t23));
  c5_N_d_[2] = -c5_g * (((c5_Ma4 * (((((-c5_t35 - c5_t50) + c5_t58) + c5_Cx4 *
    c5_t10) + c5_Cy4 * c5_t14 * c5_t21) + c5_Cz4 * c5_t14 * c5_t18) - c5_Ma5 *
                          (((((((c5_t35 + c5_t40) + c5_t44) + c5_t50) - c5_t58)
    - c5_Cz5 * c5_t20) - c5_Cx5 * c5_t42) - c5_Cy5 * c5_t14 * c5_t21)) + c5_Ma3 *
                         (((-c5_t50 + c5_t58) + c5_Cx3 * c5_t10) + c5_Cz3 *
    c5_t14)) - c5_Ma6 * (((((((((c5_t35 + c5_t40) + c5_t44) + c5_t50) - c5_t58)
    + c5_t60) - c5_Cx6 * c5_t42) - c5_Cy6 * c5_t54) - c5_Cz6 * c5_t56) - c5_t14 *
    c5_t21 * c5_t22 * c5_t23));
  c5_N_d_[3] = c5_g * ((c5_Ma5 * ((((c5_t61 + c5_t62) + c5_Cy5 * c5_t10 * c5_t18)
    - c5_Cz5 * c5_t10 * c5_t11 * c5_t21) + c5_Cx5 * c5_t10 * c5_t21 * c5_t8) +
                        c5_Ma4 * ((c5_t61 + c5_Cy4 * c5_t10 * c5_t18) - c5_Cz4 *
    c5_t10 * c5_t21)) + c5_Ma6 * ((((((c5_t61 + c5_t62) + c5_Cy6 * (c5_t10 *
    c5_t15 * c5_t18 - c5_t10 * c5_t11 * c5_t21 * c5_t22)) - c5_Cz6 * (c5_t10 *
    c5_t18 * c5_t22 + c5_t10 * c5_t11 * c5_t15 * c5_t21)) + c5_t10 * c5_t18 *
    c5_t22 * c5_t23) + c5_Cx6 * c5_t10 * c5_t21 * c5_t8) + c5_t10 * c5_t11 *
    c5_t21 * c5_t23 * c5_t59));
  c5_N_d_[4] = -c5_g * (c5_Ma6 * (((((c5_t66 - c5_Cx6 * c5_t64) + c5_Cy6 *
    c5_t22 * c5_t69) + c5_Cz6 * c5_t15 * c5_t69) - c5_t10 * c5_t18 * c5_t71) -
    c5_t23 * c5_t59 * c5_t69) + c5_Ma5 * (((c5_t66 - c5_Cx5 * c5_t64) + c5_Cz5 *
    c5_t69) - c5_t10 * c5_t18 * c5_t71));
  c5_N_d_[5] = -c5_Ma6 * c5_g * (((c5_Cy6 * (c5_t15 * c5_t64 + c5_t10 * c5_t21 *
    c5_t22) - c5_Cz6 * (c5_t22 * c5_t64 - c5_t10 * c5_t15 * c5_t21)) + c5_t22 *
    c5_t23 * c5_t64) - c5_t10 * c5_t15 * c5_t21 * c5_t23);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -107);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_g_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i38;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i38, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i38;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_h_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_CtrPlatform, const char_T
  *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_CtrPlatform), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_CtrPlatform);
  return c5_y;
}

static uint8_T c5_i_emlrt_marshallIn(SFc5_CtrPlatformInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_CtrPlatformInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_CtrPlatform_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3914493208U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1642157977U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3894249283U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1015676195U);
}

mxArray *sf_c5_CtrPlatform_get_autoinheritance_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_CtrPlatform(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"N\",},{M[8],M[0],T\"is_active_c5_CtrPlatform\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_CtrPlatform_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_CtrPlatformInstanceStruct *chartInstance;
    chartInstance = (SFc5_CtrPlatformInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatformMachineNumber_,
           5,
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
          init_script_number_translation(_CtrPlatformMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_CtrPlatformMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_CtrPlatformMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)
            c5_e_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)
            c5_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)
            c5_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);

        {
          real_T (*c5_EnTheta)[6];
          real_T (*c5_N)[6];
          c5_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c5_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_EnTheta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_N);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c5_L);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c5_Cen);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c5_Ma);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c5_Gravity);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_CtrPlatformMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "YGtedQocc3fZJipyg4zjpB";
}

static void sf_opaque_initialize_c5_CtrPlatform(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_CtrPlatformInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*)
    chartInstanceVar);
  initialize_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_CtrPlatform(void *chartInstanceVar)
{
  enable_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_CtrPlatform(void *chartInstanceVar)
{
  disable_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_CtrPlatform(void *chartInstanceVar)
{
  sf_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_CtrPlatform(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_CtrPlatform
    ((SFc5_CtrPlatformInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_CtrPlatform();/* state var info */
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

extern void sf_internal_set_sim_state_c5_CtrPlatform(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_CtrPlatform();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_CtrPlatform(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_CtrPlatform(S);
}

static void sf_opaque_set_sim_state_c5_CtrPlatform(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c5_CtrPlatform(S, st);
}

static void sf_opaque_terminate_c5_CtrPlatform(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_CtrPlatformInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_CtrPlatform(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_CtrPlatform((SFc5_CtrPlatformInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_CtrPlatform(SimStruct *S)
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
    mxArray *infoStruct = load_CtrPlatform_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2766868511U));
  ssSetChecksum1(S,(1297632383U));
  ssSetChecksum2(S,(3447208091U));
  ssSetChecksum3(S,(2526061792U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_CtrPlatform(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_CtrPlatform(SimStruct *S)
{
  SFc5_CtrPlatformInstanceStruct *chartInstance;
  chartInstance = (SFc5_CtrPlatformInstanceStruct *)malloc(sizeof
    (SFc5_CtrPlatformInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_CtrPlatformInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_CtrPlatform;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_CtrPlatform;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_CtrPlatform;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_CtrPlatform;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_CtrPlatform;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_CtrPlatform;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_CtrPlatform;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_CtrPlatform;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_CtrPlatform;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_CtrPlatform;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_CtrPlatform;
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

void c5_CtrPlatform_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_CtrPlatform(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_CtrPlatform(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_CtrPlatform(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_CtrPlatform_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
