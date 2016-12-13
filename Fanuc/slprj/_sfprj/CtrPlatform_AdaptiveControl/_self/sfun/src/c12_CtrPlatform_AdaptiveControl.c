/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_AdaptiveControl_sfun.h"
#include "c12_CtrPlatform_AdaptiveControl.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_AdaptiveControl_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c12_debug_family_names[6] = { "gd", "nargin", "nargout",
  "Theta", "L", "EndPos" };

static const char * c12_b_debug_family_names[68] = { "A1", "A2", "A3", "A4",
  "A5", "A6", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t2", "t3",
  "t4", "t5", "t6", "t7", "t8", "t9", "t10", "t11", "t12", "t13", "t14", "t23",
  "t15", "t16", "t17", "t18", "t19", "t20", "t21", "t22", "t24", "t25", "t26",
  "t27", "t34", "t28", "t29", "t30", "t31", "t32", "t36", "t33", "t35", "t37",
  "t38", "t39", "t40", "t41", "t42", "t43", "t44", "t45", "t47", "t46", "t48",
  "t49", "nargin", "nargout", "in1", "in2", "gst" };

/* Function Declarations */
static void initialize_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void initialize_params_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void enable_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void disable_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void set_sim_state_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_st);
static void finalize_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void sf_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void initSimStructsc12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_emlrt_marshallIn(SFc12_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c12_EndPos, const char_T *c12_identifier,
  real_T c12_y[3]);
static void c12_b_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3]);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_c_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[9]);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_d_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_e_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[16]);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_f_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[6]);
static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static void c12_info_helper(c12_ResolvedFunctionInfo c12_info[16]);
static void c12_fwd_kin(SFc12_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c12_in1[9], real_T c12_in2[6], real_T c12_gst[16]);
static void c12_eml_int_forloop_overflow_check
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);
static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_g_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint8_T c12_h_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_b_is_active_c12_CtrPlatform_AdaptiveControl, const char_T
   *c12_identifier);
static uint8_T c12_i_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c12_is_active_c12_CtrPlatform_AdaptiveControl = 0U;
}

static void initialize_params_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  real_T c12_dv0[9];
  int32_T c12_i0;
  sf_set_error_prefix_string(
    "Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import_named("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c12_dv0, 0, 0, 0U, 1, 0U, 2, 1, 9);
  for (c12_i0 = 0; c12_i0 < 9; c12_i0++) {
    chartInstance->c12_L[c12_i0] = c12_dv0[c12_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c12_update_debugger_state_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  int32_T c12_i1;
  real_T c12_u[3];
  const mxArray *c12_b_y = NULL;
  uint8_T c12_hoistedGlobal;
  uint8_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T (*c12_EndPos)[3];
  c12_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellarray(2), FALSE);
  for (c12_i1 = 0; c12_i1 < 3; c12_i1++) {
    c12_u[c12_i1] = (*c12_EndPos)[c12_i1];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_hoistedGlobal =
    chartInstance->c12_is_active_c12_CtrPlatform_AdaptiveControl;
  c12_b_u = c12_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  sf_mex_assign(&c12_st, c12_y, FALSE);
  return c12_st;
}

static void set_sim_state_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_st)
{
  const mxArray *c12_u;
  real_T c12_dv1[3];
  int32_T c12_i2;
  real_T (*c12_EndPos)[3];
  c12_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c12_doneDoubleBufferReInit = TRUE;
  c12_u = sf_mex_dup(c12_st);
  c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 0)),
                       "EndPos", c12_dv1);
  for (c12_i2 = 0; c12_i2 < 3; c12_i2++) {
    (*c12_EndPos)[c12_i2] = c12_dv1[c12_i2];
  }

  chartInstance->c12_is_active_c12_CtrPlatform_AdaptiveControl =
    c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 1)),
    "is_active_c12_CtrPlatform_AdaptiveControl");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_CtrPlatform_AdaptiveControl(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void sf_c12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
  int32_T c12_i3;
  int32_T c12_i4;
  int32_T c12_i5;
  int32_T c12_i6;
  real_T c12_Theta[6];
  int32_T c12_i7;
  real_T c12_b_L[9];
  uint32_T c12_debug_family_var_map[6];
  real_T c12_gd[16];
  real_T c12_nargin = 2.0;
  real_T c12_nargout = 1.0;
  real_T c12_EndPos[3];
  int32_T c12_i8;
  real_T c12_c_L[9];
  int32_T c12_i9;
  real_T c12_b_Theta[6];
  real_T c12_dv2[16];
  int32_T c12_i10;
  int32_T c12_i11;
  int32_T c12_i12;
  real_T (*c12_b_EndPos)[3];
  real_T (*c12_c_Theta)[6];
  c12_b_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c12_c_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c12_sfEvent);
  for (c12_i3 = 0; c12_i3 < 6; c12_i3++) {
    _SFD_DATA_RANGE_CHECK((*c12_c_Theta)[c12_i3], 0U);
  }

  for (c12_i4 = 0; c12_i4 < 3; c12_i4++) {
    _SFD_DATA_RANGE_CHECK((*c12_b_EndPos)[c12_i4], 1U);
  }

  for (c12_i5 = 0; c12_i5 < 9; c12_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c12_L[c12_i5], 2U);
  }

  chartInstance->c12_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c12_sfEvent);
  for (c12_i6 = 0; c12_i6 < 6; c12_i6++) {
    c12_Theta[c12_i6] = (*c12_c_Theta)[c12_i6];
  }

  for (c12_i7 = 0; c12_i7 < 9; c12_i7++) {
    c12_b_L[c12_i7] = chartInstance->c12_L[c12_i7];
  }

  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c12_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c12_gd, 0U, c12_e_sf_marshallOut,
    c12_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargin, 1U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargout, 2U,
    c12_d_sf_marshallOut, c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c12_Theta, 3U, c12_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c12_b_L, 4U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c12_EndPos, 5U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 3);
  for (c12_i8 = 0; c12_i8 < 9; c12_i8++) {
    c12_c_L[c12_i8] = c12_b_L[c12_i8];
  }

  for (c12_i9 = 0; c12_i9 < 6; c12_i9++) {
    c12_b_Theta[c12_i9] = c12_Theta[c12_i9];
  }

  c12_fwd_kin(chartInstance, c12_c_L, c12_b_Theta, c12_dv2);
  for (c12_i10 = 0; c12_i10 < 16; c12_i10++) {
    c12_gd[c12_i10] = c12_dv2[c12_i10];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  for (c12_i11 = 0; c12_i11 < 3; c12_i11++) {
    c12_EndPos[c12_i11] = c12_gd[c12_i11 + 12];
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c12_i12 = 0; c12_i12 < 3; c12_i12++) {
    (*c12_b_EndPos)[c12_i12] = c12_EndPos[c12_i12];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c12_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_AdaptiveControlMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc12_CtrPlatform_AdaptiveControl
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c12_chartNumber, 0U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/fwd_kin.m"));
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i13;
  real_T c12_b_inData[3];
  int32_T c12_i14;
  real_T c12_u[3];
  const mxArray *c12_y = NULL;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i13 = 0; c12_i13 < 3; c12_i13++) {
    c12_b_inData[c12_i13] = (*(real_T (*)[3])c12_inData)[c12_i13];
  }

  for (c12_i14 = 0; c12_i14 < 3; c12_i14++) {
    c12_u[c12_i14] = c12_b_inData[c12_i14];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_emlrt_marshallIn(SFc12_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, const mxArray *c12_EndPos, const char_T *c12_identifier,
  real_T c12_y[3])
{
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_EndPos), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_EndPos);
}

static void c12_b_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[3])
{
  real_T c12_dv3[3];
  int32_T c12_i15;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c12_i15 = 0; c12_i15 < 3; c12_i15++) {
    c12_y[c12_i15] = c12_dv3[c12_i15];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_EndPos;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[3];
  int32_T c12_i16;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_EndPos = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_EndPos), &c12_thisId,
    c12_y);
  sf_mex_destroy(&c12_EndPos);
  for (c12_i16 = 0; c12_i16 < 3; c12_i16++) {
    (*(real_T (*)[3])c12_outData)[c12_i16] = c12_y[c12_i16];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i17;
  real_T c12_b_inData[9];
  int32_T c12_i18;
  real_T c12_u[9];
  const mxArray *c12_y = NULL;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i17 = 0; c12_i17 < 9; c12_i17++) {
    c12_b_inData[c12_i17] = (*(real_T (*)[9])c12_inData)[c12_i17];
  }

  for (c12_i18 = 0; c12_i18 < 9; c12_i18++) {
    c12_u[c12_i18] = c12_b_inData[c12_i18];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_c_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[9])
{
  real_T c12_dv4[9];
  int32_T c12_i19;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv4, 1, 0, 0U, 1, 0U, 2, 1,
                9);
  for (c12_i19 = 0; c12_i19 < 9; c12_i19++) {
    c12_y[c12_i19] = c12_dv4[c12_i19];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_L;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[9];
  int32_T c12_i20;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_b_L = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_L), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_b_L);
  for (c12_i20 = 0; c12_i20 < 9; c12_i20++) {
    (*(real_T (*)[9])c12_outData)[c12_i20] = c12_y[c12_i20];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i21;
  real_T c12_b_inData[6];
  int32_T c12_i22;
  real_T c12_u[6];
  const mxArray *c12_y = NULL;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i21 = 0; c12_i21 < 6; c12_i21++) {
    c12_b_inData[c12_i21] = (*(real_T (*)[6])c12_inData)[c12_i21];
  }

  for (c12_i22 = 0; c12_i22 < 6; c12_i22++) {
    c12_u[c12_i22] = c12_b_inData[c12_i22];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static real_T c12_d_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i23;
  int32_T c12_i24;
  int32_T c12_i25;
  real_T c12_b_inData[16];
  int32_T c12_i26;
  int32_T c12_i27;
  int32_T c12_i28;
  real_T c12_u[16];
  const mxArray *c12_y = NULL;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_i23 = 0;
  for (c12_i24 = 0; c12_i24 < 4; c12_i24++) {
    for (c12_i25 = 0; c12_i25 < 4; c12_i25++) {
      c12_b_inData[c12_i25 + c12_i23] = (*(real_T (*)[16])c12_inData)[c12_i25 +
        c12_i23];
    }

    c12_i23 += 4;
  }

  c12_i26 = 0;
  for (c12_i27 = 0; c12_i27 < 4; c12_i27++) {
    for (c12_i28 = 0; c12_i28 < 4; c12_i28++) {
      c12_u[c12_i28 + c12_i26] = c12_b_inData[c12_i28 + c12_i26];
    }

    c12_i26 += 4;
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_e_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[16])
{
  real_T c12_dv5[16];
  int32_T c12_i29;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv5, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c12_i29 = 0; c12_i29 < 16; c12_i29++) {
    c12_y[c12_i29] = c12_dv5[c12_i29];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_gd;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[16];
  int32_T c12_i30;
  int32_T c12_i31;
  int32_T c12_i32;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_gd = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_gd), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_gd);
  c12_i30 = 0;
  for (c12_i31 = 0; c12_i31 < 4; c12_i31++) {
    for (c12_i32 = 0; c12_i32 < 4; c12_i32++) {
      (*(real_T (*)[16])c12_outData)[c12_i32 + c12_i30] = c12_y[c12_i32 +
        c12_i30];
    }

    c12_i30 += 4;
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i33;
  real_T c12_b_inData[6];
  int32_T c12_i34;
  real_T c12_u[6];
  const mxArray *c12_y = NULL;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i33 = 0; c12_i33 < 6; c12_i33++) {
    c12_b_inData[c12_i33] = (*(real_T (*)[6])c12_inData)[c12_i33];
  }

  for (c12_i34 = 0; c12_i34 < 6; c12_i34++) {
    c12_u[c12_i34] = c12_b_inData[c12_i34];
  }

  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static void c12_f_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId, real_T c12_y[6])
{
  real_T c12_dv6[6];
  int32_T c12_i35;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), c12_dv6, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c12_i35 = 0; c12_i35 < 6; c12_i35++) {
    c12_y[c12_i35] = c12_dv6[c12_i35];
  }

  sf_mex_destroy(&c12_u);
}

static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_in2;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y[6];
  int32_T c12_i36;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_in2 = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_in2), &c12_thisId, c12_y);
  sf_mex_destroy(&c12_in2);
  for (c12_i36 = 0; c12_i36 < 6; c12_i36++) {
    (*(real_T (*)[6])c12_outData)[c12_i36] = c12_y[c12_i36];
  }

  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray
  *sf_c12_CtrPlatform_AdaptiveControl_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo;
  c12_ResolvedFunctionInfo c12_info[16];
  const mxArray *c12_m0 = NULL;
  int32_T c12_i37;
  c12_ResolvedFunctionInfo *c12_r0;
  c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  c12_info_helper(c12_info);
  sf_mex_assign(&c12_m0, sf_mex_createstruct("nameCaptureInfo", 1, 16), FALSE);
  for (c12_i37 = 0; c12_i37 < 16; c12_i37++) {
    c12_r0 = &c12_info[c12_i37];
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->context)), "context", "nameCaptureInfo",
                    c12_i37);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c12_r0->name)), "name", "nameCaptureInfo",
                    c12_i37);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      c12_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c12_i37);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", c12_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c12_r0->resolved)), "resolved",
                    "nameCaptureInfo", c12_i37);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c12_i37);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo", &c12_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c12_i37);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c12_i37);
    sf_mex_addfield(c12_m0, sf_mex_create("nameCaptureInfo",
      &c12_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c12_i37);
  }

  sf_mex_assign(&c12_nameCaptureInfo, c12_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static void c12_info_helper(c12_ResolvedFunctionInfo c12_info[16])
{
  c12_info[0].context = "";
  c12_info[0].name = "fwd_kin";
  c12_info[0].dominantType = "double";
  c12_info[0].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c12_info[0].fileTimeLo = 1366778960U;
  c12_info[0].fileTimeHi = 0U;
  c12_info[0].mFileTimeLo = 0U;
  c12_info[0].mFileTimeHi = 0U;
  c12_info[1].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c12_info[1].name = "cos";
  c12_info[1].dominantType = "double";
  c12_info[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c12_info[1].fileTimeLo = 1286797106U;
  c12_info[1].fileTimeHi = 0U;
  c12_info[1].mFileTimeLo = 0U;
  c12_info[1].mFileTimeHi = 0U;
  c12_info[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c12_info[2].name = "eml_scalar_cos";
  c12_info[2].dominantType = "double";
  c12_info[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c12_info[2].fileTimeLo = 1286797122U;
  c12_info[2].fileTimeHi = 0U;
  c12_info[2].mFileTimeLo = 0U;
  c12_info[2].mFileTimeHi = 0U;
  c12_info[3].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c12_info[3].name = "sin";
  c12_info[3].dominantType = "double";
  c12_info[3].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c12_info[3].fileTimeLo = 1286797150U;
  c12_info[3].fileTimeHi = 0U;
  c12_info[3].mFileTimeLo = 0U;
  c12_info[3].mFileTimeHi = 0U;
  c12_info[4].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c12_info[4].name = "eml_scalar_sin";
  c12_info[4].dominantType = "double";
  c12_info[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c12_info[4].fileTimeLo = 1286797136U;
  c12_info[4].fileTimeHi = 0U;
  c12_info[4].mFileTimeLo = 0U;
  c12_info[4].mFileTimeHi = 0U;
  c12_info[5].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/fwd_kin.m";
  c12_info[5].name = "reshape";
  c12_info[5].dominantType = "double";
  c12_info[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c12_info[5].fileTimeLo = 1286797168U;
  c12_info[5].fileTimeHi = 0U;
  c12_info[5].mFileTimeLo = 0U;
  c12_info[5].mFileTimeHi = 0U;
  c12_info[6].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c12_info[6].name = "eml_index_class";
  c12_info[6].dominantType = "";
  c12_info[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c12_info[6].fileTimeLo = 1286797178U;
  c12_info[6].fileTimeHi = 0U;
  c12_info[6].mFileTimeLo = 0U;
  c12_info[6].mFileTimeHi = 0U;
  c12_info[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c12_info[7].name = "eml_index_class";
  c12_info[7].dominantType = "";
  c12_info[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c12_info[7].fileTimeLo = 1286797178U;
  c12_info[7].fileTimeHi = 0U;
  c12_info[7].mFileTimeLo = 0U;
  c12_info[7].mFileTimeHi = 0U;
  c12_info[8].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c12_info[8].name = "eml_assert_valid_size_arg";
  c12_info[8].dominantType = "double";
  c12_info[8].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c12_info[8].fileTimeLo = 1286797094U;
  c12_info[8].fileTimeHi = 0U;
  c12_info[8].mFileTimeLo = 0U;
  c12_info[8].mFileTimeHi = 0U;
  c12_info[9].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c12_info[9].name = "isinf";
  c12_info[9].dominantType = "double";
  c12_info[9].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c12_info[9].fileTimeLo = 1286797160U;
  c12_info[9].fileTimeHi = 0U;
  c12_info[9].mFileTimeLo = 0U;
  c12_info[9].mFileTimeHi = 0U;
  c12_info[10].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c12_info[10].name = "mtimes";
  c12_info[10].dominantType = "double";
  c12_info[10].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c12_info[10].fileTimeLo = 1289494492U;
  c12_info[10].fileTimeHi = 0U;
  c12_info[10].mFileTimeLo = 0U;
  c12_info[10].mFileTimeHi = 0U;
  c12_info[11].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c12_info[11].name = "eml_index_class";
  c12_info[11].dominantType = "";
  c12_info[11].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c12_info[11].fileTimeLo = 1286797178U;
  c12_info[11].fileTimeHi = 0U;
  c12_info[11].mFileTimeLo = 0U;
  c12_info[11].mFileTimeHi = 0U;
  c12_info[12].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c12_info[12].name = "intmax";
  c12_info[12].dominantType = "char";
  c12_info[12].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c12_info[12].fileTimeLo = 1311233716U;
  c12_info[12].fileTimeHi = 0U;
  c12_info[12].mFileTimeLo = 0U;
  c12_info[12].mFileTimeHi = 0U;
  c12_info[13].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c12_info[13].name = "eml_scalar_eg";
  c12_info[13].dominantType = "double";
  c12_info[13].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c12_info[13].fileTimeLo = 1286797196U;
  c12_info[13].fileTimeHi = 0U;
  c12_info[13].mFileTimeLo = 0U;
  c12_info[13].mFileTimeHi = 0U;
  c12_info[14].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c12_info[14].name = "eml_int_forloop_overflow_check";
  c12_info[14].dominantType = "";
  c12_info[14].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c12_info[14].fileTimeLo = 1311233716U;
  c12_info[14].fileTimeHi = 0U;
  c12_info[14].mFileTimeLo = 0U;
  c12_info[14].mFileTimeHi = 0U;
  c12_info[15].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c12_info[15].name = "intmax";
  c12_info[15].dominantType = "char";
  c12_info[15].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c12_info[15].fileTimeLo = 1311233716U;
  c12_info[15].fileTimeHi = 0U;
  c12_info[15].mFileTimeLo = 0U;
  c12_info[15].mFileTimeHi = 0U;
}

static void c12_fwd_kin(SFc12_CtrPlatform_AdaptiveControlInstanceStruct
  *chartInstance, real_T c12_in1[9], real_T c12_in2[6], real_T c12_gst[16])
{
  uint32_T c12_debug_family_var_map[68];
  real_T c12_A1;
  real_T c12_A2;
  real_T c12_A3;
  real_T c12_A4;
  real_T c12_A5;
  real_T c12_A6;
  real_T c12_L1;
  real_T c12_L2;
  real_T c12_L3;
  real_T c12_L4;
  real_T c12_L5;
  real_T c12_L6;
  real_T c12_L7;
  real_T c12_L8;
  real_T c12_L9;
  real_T c12_t2;
  real_T c12_t3;
  real_T c12_t4;
  real_T c12_t5;
  real_T c12_t6;
  real_T c12_t7;
  real_T c12_t8;
  real_T c12_t9;
  real_T c12_t10;
  real_T c12_t11;
  real_T c12_t12;
  real_T c12_t13;
  real_T c12_t14;
  real_T c12_t23;
  real_T c12_t15;
  real_T c12_t16;
  real_T c12_t17;
  real_T c12_t18;
  real_T c12_t19;
  real_T c12_t20;
  real_T c12_t21;
  real_T c12_t22;
  real_T c12_t24;
  real_T c12_t25;
  real_T c12_t26;
  real_T c12_t27;
  real_T c12_t34;
  real_T c12_t28;
  real_T c12_t29;
  real_T c12_t30;
  real_T c12_t31;
  real_T c12_t32;
  real_T c12_t36;
  real_T c12_t33;
  real_T c12_t35;
  real_T c12_t37;
  real_T c12_t38;
  real_T c12_t39;
  real_T c12_t40;
  real_T c12_t41;
  real_T c12_t42;
  real_T c12_t43;
  real_T c12_t44;
  real_T c12_t45;
  real_T c12_t47;
  real_T c12_t46;
  real_T c12_t48;
  real_T c12_t49;
  real_T c12_nargin = 2.0;
  real_T c12_nargout = 1.0;
  real_T c12_x;
  real_T c12_b_x;
  real_T c12_c_x;
  real_T c12_d_x;
  real_T c12_e_x;
  real_T c12_f_x;
  real_T c12_g_x;
  real_T c12_h_x;
  real_T c12_i_x;
  real_T c12_j_x;
  real_T c12_k_x;
  real_T c12_l_x;
  real_T c12_m_x;
  real_T c12_n_x;
  real_T c12_o_x;
  real_T c12_p_x;
  real_T c12_q_x;
  real_T c12_r_x;
  real_T c12_s_x;
  real_T c12_t_x;
  real_T c12_u_x;
  real_T c12_v_x;
  real_T c12_w_x;
  real_T c12_x_x;
  real_T c12_y_x[16];
  int32_T c12_k;
  int32_T c12_b_k;
  sf_debug_symbol_scope_push_eml(0U, 68U, 68U, c12_b_debug_family_names,
    c12_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c12_A1, 0U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_A2, 1U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_A3, 2U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_A4, 3U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_A5, 4U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_A6, 5U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L1, 6U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L2, 7U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L3, 8U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L4, 9U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L5, 10U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L6, 11U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L7, 12U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L8, 13U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_L9, 14U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t2, 15U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t3, 16U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t4, 17U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t5, 18U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t6, 19U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t7, 20U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t8, 21U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t9, 22U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t10, 23U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t11, 24U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t12, 25U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t13, 26U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t14, 27U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t23, 28U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t15, 29U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t16, 30U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t17, 31U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t18, 32U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t19, 33U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t20, 34U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t21, 35U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t22, 36U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t24, 37U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t25, 38U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t26, 39U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t27, 40U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t34, 41U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t28, 42U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t29, 43U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t30, 44U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t31, 45U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t32, 46U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t36, 47U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t33, 48U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t35, 49U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t37, 50U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t38, 51U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t39, 52U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t40, 53U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t41, 54U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t42, 55U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t43, 56U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t44, 57U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t45, 58U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t47, 59U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t46, 60U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t48, 61U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_t49, 62U, c12_d_sf_marshallOut,
    c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargin, 63U,
    c12_d_sf_marshallOut, c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c12_nargout, 64U,
    c12_d_sf_marshallOut, c12_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c12_in1, 65U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c12_in2, 66U, c12_f_sf_marshallOut,
    c12_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c12_gst, 67U, c12_e_sf_marshallOut,
    c12_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 8);
  c12_A1 = c12_in2[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 9);
  c12_A2 = c12_in2[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 10);
  c12_A3 = c12_in2[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 11);
  c12_A4 = c12_in2[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 12);
  c12_A5 = c12_in2[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 13);
  c12_A6 = c12_in2[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 14);
  c12_L1 = c12_in1[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 15);
  c12_L2 = c12_in1[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 16);
  c12_L3 = c12_in1[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 17);
  c12_L4 = c12_in1[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 18);
  c12_L5 = c12_in1[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 19);
  c12_L6 = c12_in1[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 20);
  c12_L7 = c12_in1[6];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 21);
  c12_L8 = c12_in1[7];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 22);
  c12_L9 = c12_in1[8];
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 23);
  c12_x = c12_A1;
  c12_t2 = c12_x;
  c12_b_x = c12_t2;
  c12_t2 = c12_b_x;
  c12_t2 = muDoubleScalarCos(c12_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 24);
  c12_c_x = c12_A2;
  c12_t3 = c12_c_x;
  c12_d_x = c12_t3;
  c12_t3 = c12_d_x;
  c12_t3 = muDoubleScalarCos(c12_t3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 25);
  c12_e_x = c12_A3;
  c12_t4 = c12_e_x;
  c12_f_x = c12_t4;
  c12_t4 = c12_f_x;
  c12_t4 = muDoubleScalarSin(c12_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 26);
  c12_g_x = c12_A3;
  c12_t5 = c12_g_x;
  c12_h_x = c12_t5;
  c12_t5 = c12_h_x;
  c12_t5 = muDoubleScalarCos(c12_t5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 27);
  c12_i_x = c12_A2;
  c12_t6 = c12_i_x;
  c12_j_x = c12_t6;
  c12_t6 = c12_j_x;
  c12_t6 = muDoubleScalarSin(c12_t6);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 28);
  c12_k_x = c12_A4;
  c12_t7 = c12_k_x;
  c12_l_x = c12_t7;
  c12_t7 = c12_l_x;
  c12_t7 = muDoubleScalarSin(c12_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 29);
  c12_t8 = c12_t2 * c12_t3 * c12_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 30);
  c12_t9 = c12_t2 * c12_t5 * c12_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 31);
  c12_t10 = c12_t8 + c12_t9;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 32);
  c12_m_x = c12_A4;
  c12_t11 = c12_m_x;
  c12_n_x = c12_t11;
  c12_t11 = c12_n_x;
  c12_t11 = muDoubleScalarCos(c12_t11);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 33);
  c12_o_x = c12_A1;
  c12_t12 = c12_o_x;
  c12_p_x = c12_t12;
  c12_t12 = c12_p_x;
  c12_t12 = muDoubleScalarSin(c12_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 34);
  c12_q_x = c12_A5;
  c12_t13 = c12_q_x;
  c12_r_x = c12_t13;
  c12_t13 = c12_r_x;
  c12_t13 = muDoubleScalarSin(c12_t13);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 35);
  c12_t14 = c12_t2 * c12_t3 * c12_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 36);
  c12_t23 = c12_t2 * c12_t4 * c12_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 37);
  c12_t15 = c12_t14 - c12_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 38);
  c12_s_x = c12_A5;
  c12_t16 = c12_s_x;
  c12_t_x = c12_t16;
  c12_t16 = c12_t_x;
  c12_t16 = muDoubleScalarCos(c12_t16);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 39);
  c12_t17 = c12_t10 * c12_t11;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 40);
  c12_t18 = c12_t12 * c12_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 41);
  c12_t19 = c12_t17 + c12_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 42);
  c12_u_x = c12_A6;
  c12_t20 = c12_u_x;
  c12_v_x = c12_t20;
  c12_t20 = c12_v_x;
  c12_t20 = muDoubleScalarSin(c12_t20);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 43);
  c12_t21 = c12_t11 * c12_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 44);
  c12_w_x = c12_A6;
  c12_t22 = c12_w_x;
  c12_x_x = c12_t22;
  c12_t22 = c12_x_x;
  c12_t22 = muDoubleScalarCos(c12_t22);
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 45);
  c12_t24 = c12_t13 * c12_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 46);
  c12_t25 = c12_t16 * c12_t19;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 47);
  c12_t26 = c12_t24 + c12_t25;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 48);
  c12_t27 = c12_t12 * c12_t3 * c12_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 49);
  c12_t34 = c12_t12 * c12_t4 * c12_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 50);
  c12_t28 = c12_t27 - c12_t34;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 51);
  c12_t29 = c12_t12 * c12_t3 * c12_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 52);
  c12_t30 = c12_t12 * c12_t5 * c12_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 53);
  c12_t31 = c12_t29 + c12_t30;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 54);
  c12_t32 = c12_t11 * c12_t31;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 55);
  c12_t36 = c12_t2 * c12_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 56);
  c12_t33 = c12_t32 - c12_t36;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 57);
  c12_t35 = c12_t13 * c12_t28;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 58);
  c12_t37 = c12_t16 * c12_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 59);
  c12_t38 = c12_t35 + c12_t37;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 60);
  c12_t39 = c12_t31 * c12_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 61);
  c12_t40 = c12_t11 * c12_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 62);
  c12_t41 = c12_t39 + c12_t40;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 63);
  c12_t42 = c12_t3 * c12_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 64);
  c12_t43 = c12_t5 * c12_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 65);
  c12_t44 = c12_t42 + c12_t43;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 66);
  c12_t45 = c12_t3 * c12_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 67);
  c12_t47 = c12_t4 * c12_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 68);
  c12_t46 = c12_t45 - c12_t47;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 69);
  c12_t48 = c12_t13 * c12_t44;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 70);
  c12_t49 = c12_t48 - c12_t11 * c12_t16 * c12_t46;
  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, 71);
  c12_y_x[0] = c12_t15 * c12_t16 - c12_t13 * c12_t19;
  c12_y_x[1] = c12_t16 * c12_t28 - c12_t13 * c12_t33;
  c12_y_x[2] = -c12_t16 * c12_t44 - c12_t11 * c12_t13 * c12_t46;
  c12_y_x[3] = 0.0;
  c12_y_x[4] = c12_t20 * c12_t26 - c12_t22 * (c12_t21 - c12_t10 * c12_t7);
  c12_y_x[5] = c12_t20 * c12_t38 + c12_t22 * c12_t41;
  c12_y_x[6] = -c12_t20 * c12_t49 + c12_t22 * c12_t46 * c12_t7;
  c12_y_x[7] = 0.0;
  c12_y_x[8] = c12_t22 * c12_t26 + c12_t20 * (c12_t21 - c12_t10 * c12_t7);
  c12_y_x[9] = c12_t22 * c12_t38 - c12_t20 * c12_t41;
  c12_y_x[10] = -c12_t22 * c12_t49 - c12_t20 * c12_t46 * c12_t7;
  c12_y_x[11] = 0.0;
  c12_y_x[12] = ((((((((((((((((((((((((((((((c12_L2 * c12_t2 + c12_L3 * c12_t2 *
    c12_t6) - c12_L8 * c12_t11 * c12_t12 * c12_t22) + c12_L4 * c12_t2 * c12_t3 *
    c12_t4) + c12_L9 * c12_t11 * c12_t12 * c12_t20) + c12_L5 * c12_t2 * c12_t3 *
    c12_t5) - c12_L6 * c12_t12 * c12_t13 * c12_t7) - c12_L7 * c12_t12 * c12_t13 *
    c12_t7) + c12_L4 * c12_t2 * c12_t5 * c12_t6) - c12_L5 * c12_t2 * c12_t4 *
    c12_t6) + c12_L6 * c12_t16 * c12_t2 * c12_t3 * c12_t5) + c12_L7 * c12_t16 *
    c12_t2 * c12_t3 * c12_t5) - c12_L6 * c12_t16 * c12_t2 * c12_t4 * c12_t6) +
    c12_L8 * c12_t12 * c12_t16 * c12_t20 * c12_t7) - c12_L7 * c12_t16 * c12_t2 *
    c12_t4 * c12_t6) + c12_L9 * c12_t12 * c12_t16 * c12_t22 * c12_t7) - c12_L6 *
    c12_t11 * c12_t13 * c12_t2 * c12_t3 * c12_t4) - c12_L7 * c12_t11 * c12_t13 *
    c12_t2 * c12_t3 * c12_t4) + c12_L8 * c12_t13 * c12_t2 * c12_t20 * c12_t3 *
    c12_t5) - c12_L6 * c12_t11 * c12_t13 * c12_t2 * c12_t5 * c12_t6) - c12_L7 *
    c12_t11 * c12_t13 * c12_t2 * c12_t5 * c12_t6) + c12_L9 * c12_t13 * c12_t2 *
    c12_t22 * c12_t3 * c12_t5) - c12_L8 * c12_t13 * c12_t2 * c12_t20 * c12_t4 *
    c12_t6) - c12_L9 * c12_t13 * c12_t2 * c12_t22 * c12_t4 * c12_t6) + c12_L8 *
                       c12_t2 * c12_t22 * c12_t3 * c12_t4 * c12_t7) - c12_L9 *
                      c12_t2 * c12_t20 * c12_t3 * c12_t4 * c12_t7) + c12_L8 *
                     c12_t2 * c12_t22 * c12_t5 * c12_t6 * c12_t7) - c12_L9 *
                    c12_t2 * c12_t20 * c12_t5 * c12_t6 * c12_t7) + c12_L8 *
                   c12_t11 * c12_t16 * c12_t2 * c12_t20 * c12_t3 * c12_t4) +
                  c12_L9 * c12_t11 * c12_t16 * c12_t2 * c12_t22 * c12_t3 *
                  c12_t4) + c12_L8 * c12_t11 * c12_t16 * c12_t2 * c12_t20 *
                 c12_t5 * c12_t6) + c12_L9 * c12_t11 * c12_t16 * c12_t2 *
    c12_t22 * c12_t5 * c12_t6;
  c12_y_x[13] = ((((((((((((((((((((((((((((((c12_L2 * c12_t12 + c12_L3 *
    c12_t12 * c12_t6) + c12_L4 * c12_t12 * c12_t3 * c12_t4) + c12_L8 * c12_t11 *
    c12_t2 * c12_t22) + c12_L5 * c12_t12 * c12_t3 * c12_t5) - c12_L9 * c12_t11 *
    c12_t2 * c12_t20) + c12_L4 * c12_t12 * c12_t5 * c12_t6) - c12_L5 * c12_t12 *
    c12_t4 * c12_t6) + c12_L6 * c12_t13 * c12_t2 * c12_t7) + c12_L7 * c12_t13 *
    c12_t2 * c12_t7) + c12_L6 * c12_t12 * c12_t16 * c12_t3 * c12_t5) + c12_L7 *
    c12_t12 * c12_t16 * c12_t3 * c12_t5) - c12_L6 * c12_t12 * c12_t16 * c12_t4 *
    c12_t6) - c12_L7 * c12_t12 * c12_t16 * c12_t4 * c12_t6) - c12_L8 * c12_t16 *
    c12_t2 * c12_t20 * c12_t7) - c12_L9 * c12_t16 * c12_t2 * c12_t22 * c12_t7) -
    c12_L6 * c12_t11 * c12_t12 * c12_t13 * c12_t3 * c12_t4) - c12_L7 * c12_t11 *
    c12_t12 * c12_t13 * c12_t3 * c12_t4) + c12_L8 * c12_t12 * c12_t13 * c12_t20 *
    c12_t3 * c12_t5) - c12_L6 * c12_t11 * c12_t12 * c12_t13 * c12_t5 * c12_t6) -
    c12_L7 * c12_t11 * c12_t12 * c12_t13 * c12_t5 * c12_t6) + c12_L9 * c12_t12 *
    c12_t13 * c12_t22 * c12_t3 * c12_t5) - c12_L8 * c12_t12 * c12_t13 * c12_t20 *
    c12_t4 * c12_t6) - c12_L9 * c12_t12 * c12_t13 * c12_t22 * c12_t4 * c12_t6) +
                       c12_L8 * c12_t12 * c12_t22 * c12_t3 * c12_t4 * c12_t7) -
                      c12_L9 * c12_t12 * c12_t20 * c12_t3 * c12_t4 * c12_t7) +
                     c12_L8 * c12_t12 * c12_t22 * c12_t5 * c12_t6 * c12_t7) -
                    c12_L9 * c12_t12 * c12_t20 * c12_t5 * c12_t6 * c12_t7) +
                   c12_L8 * c12_t11 * c12_t12 * c12_t16 * c12_t20 * c12_t3 *
                   c12_t4) + c12_L9 * c12_t11 * c12_t12 * c12_t16 * c12_t22 *
                  c12_t3 * c12_t4) + c12_L8 * c12_t11 * c12_t12 * c12_t16 *
                 c12_t20 * c12_t5 * c12_t6) + c12_L9 * c12_t11 * c12_t12 *
    c12_t16 * c12_t22 * c12_t5 * c12_t6;
  c12_y_x[14] = ((((((((((((((((((((((((c12_L1 + c12_L3 * c12_t3) + c12_L4 *
    c12_t3 * c12_t5) - c12_L5 * c12_t3 * c12_t4) - c12_L4 * c12_t4 * c12_t6) -
    c12_L5 * c12_t5 * c12_t6) - c12_L6 * c12_t16 * c12_t3 * c12_t4) - c12_L7 *
    c12_t16 * c12_t3 * c12_t4) - c12_L6 * c12_t16 * c12_t5 * c12_t6) - c12_L7 *
    c12_t16 * c12_t5 * c12_t6) - c12_L6 * c12_t11 * c12_t13 * c12_t3 * c12_t5) -
    c12_L7 * c12_t11 * c12_t13 * c12_t3 * c12_t5) - c12_L8 * c12_t13 * c12_t20 *
    c12_t3 * c12_t4) + c12_L6 * c12_t11 * c12_t13 * c12_t4 * c12_t6) + c12_L7 *
    c12_t11 * c12_t13 * c12_t4 * c12_t6) - c12_L9 * c12_t13 * c12_t22 * c12_t3 *
    c12_t4) - c12_L8 * c12_t13 * c12_t20 * c12_t5 * c12_t6) - c12_L9 * c12_t13 *
                        c12_t22 * c12_t5 * c12_t6) + c12_L8 * c12_t22 * c12_t3 *
                       c12_t5 * c12_t7) - c12_L9 * c12_t20 * c12_t3 * c12_t5 *
                      c12_t7) - c12_L8 * c12_t22 * c12_t4 * c12_t6 * c12_t7) +
                    c12_L9 * c12_t20 * c12_t4 * c12_t6 * c12_t7) + c12_L8 *
                   c12_t11 * c12_t16 * c12_t20 * c12_t3 * c12_t5) + c12_L9 *
                  c12_t11 * c12_t16 * c12_t22 * c12_t3 * c12_t5) - c12_L8 *
                 c12_t11 * c12_t16 * c12_t20 * c12_t4 * c12_t6) - c12_L9 *
    c12_t11 * c12_t16 * c12_t22 * c12_t4 * c12_t6;
  c12_y_x[15] = 1.0;
  c12_eml_int_forloop_overflow_check(chartInstance);
  for (c12_k = 1; c12_k < 17; c12_k++) {
    c12_b_k = c12_k;
    c12_gst[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c12_b_k), 1, 16, 1, 0) - 1] = c12_y_x[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c12_b_k), 1, 16, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c12_sfEvent, -71);
  sf_debug_symbol_scope_pop();
}

static void c12_eml_int_forloop_overflow_check
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, FALSE);
  return c12_mxArrayOutData;
}

static int32_T c12_g_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i38;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i38, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i38;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
    chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint8_T c12_h_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_b_is_active_c12_CtrPlatform_AdaptiveControl, const char_T
   *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_CtrPlatform_AdaptiveControl), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_CtrPlatform_AdaptiveControl);
  return c12_y;
}

static uint8_T c12_i_emlrt_marshallIn
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance, const mxArray
   *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u0;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void init_dsm_address_info
  (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c12_CtrPlatform_AdaptiveControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2963941133U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3380848050U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(282833133U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2076306625U);
}

mxArray *sf_c12_CtrPlatform_AdaptiveControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vbrrXpunyQmJEzoNDHbAOH");
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

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c12_CtrPlatform_AdaptiveControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"EndPos\",},{M[8],M[0],T\"is_active_c12_CtrPlatform_AdaptiveControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_CtrPlatform_AdaptiveControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
    chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_AdaptiveControlMachineNumber_,
           12,
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

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
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
            1.0,0,0,(MexFcnForType)c12_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)
            c12_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
            c12_b_sf_marshallIn);
        }

        {
          real_T (*c12_Theta)[6];
          real_T (*c12_EndPos)[3];
          c12_EndPos = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c12_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c12_Theta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c12_EndPos);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c12_L);
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
  return "MSCXFadpWMHrbgpnzrtXUF";
}

static void sf_opaque_initialize_c12_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
  initialize_c12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  enable_c12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  disable_c12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  sf_c12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_CtrPlatform_AdaptiveControl
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_CtrPlatform_AdaptiveControl();/* state var info */
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

extern void sf_internal_set_sim_state_c12_CtrPlatform_AdaptiveControl(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_CtrPlatform_AdaptiveControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_CtrPlatform_AdaptiveControl
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c12_CtrPlatform_AdaptiveControl(S);
}

static void sf_opaque_set_sim_state_c12_CtrPlatform_AdaptiveControl(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c12_CtrPlatform_AdaptiveControl(S, st);
}

static void sf_opaque_terminate_c12_CtrPlatform_AdaptiveControl(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c12_CtrPlatform_AdaptiveControl
      ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_AdaptiveControl_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_CtrPlatform_AdaptiveControl
    ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c12_CtrPlatform_AdaptiveControl
      ((SFc12_CtrPlatform_AdaptiveControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_CtrPlatform_AdaptiveControl(SimStruct *S)
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
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,12,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2918210596U));
  ssSetChecksum1(S,(561669251U));
  ssSetChecksum2(S,(513099197U));
  ssSetChecksum3(S,(1963934751U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c12_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_CtrPlatform_AdaptiveControl(SimStruct *S)
{
  SFc12_CtrPlatform_AdaptiveControlInstanceStruct *chartInstance;
  chartInstance = (SFc12_CtrPlatform_AdaptiveControlInstanceStruct *)malloc
    (sizeof(SFc12_CtrPlatform_AdaptiveControlInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc12_CtrPlatform_AdaptiveControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_CtrPlatform_AdaptiveControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c12_CtrPlatform_AdaptiveControl;
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

void c12_CtrPlatform_AdaptiveControl_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_CtrPlatform_AdaptiveControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_CtrPlatform_AdaptiveControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_CtrPlatform_AdaptiveControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_CtrPlatform_AdaptiveControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
