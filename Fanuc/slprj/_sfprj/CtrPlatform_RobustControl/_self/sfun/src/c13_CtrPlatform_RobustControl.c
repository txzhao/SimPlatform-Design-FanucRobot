/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_RobustControl_sfun.h"
#include "c13_CtrPlatform_RobustControl.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_RobustControl_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c13_debug_family_names[10] = { "EndVW", "gd", "EndW",
  "gd_pos", "nargin", "nargout", "Theta", "Omega", "L", "EndVel" };

static const char * c13_b_debug_family_names[64] = { "A1", "A2", "A3", "A4",
  "A5", "L1", "L2", "L3", "L4", "L5", "t2", "t3", "t4", "t5", "t6", "t7", "t8",
  "t9", "t10", "t11", "t12", "t13", "t14", "t15", "t16", "t17", "t18", "t19",
  "t20", "t21", "t22", "t23", "t24", "t25", "t26", "t27", "t28", "t29", "t30",
  "t31", "t32", "t33", "t34", "t35", "t36", "t37", "t38", "t47", "t39", "t40",
  "t41", "t42", "t43", "t44", "t45", "t46", "t48", "t49", "t50", "nargin",
  "nargout", "in1", "in2", "spat_Jacobian" };

static const char * c13_c_debug_family_names[68] = { "A1", "A2", "A3", "A4",
  "A5", "A6", "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "t2", "t3",
  "t4", "t5", "t6", "t7", "t8", "t9", "t10", "t11", "t12", "t13", "t14", "t23",
  "t15", "t16", "t17", "t18", "t19", "t20", "t21", "t22", "t24", "t25", "t26",
  "t27", "t34", "t28", "t29", "t30", "t31", "t32", "t36", "t33", "t35", "t37",
  "t38", "t39", "t40", "t41", "t42", "t43", "t44", "t45", "t47", "t46", "t48",
  "t49", "nargin", "nargout", "in1", "in2", "gst" };

/* Function Declarations */
static void initialize_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void initialize_params_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void enable_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void disable_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void c13_update_debugger_state_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void set_sim_state_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_st);
static void finalize_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void sf_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void c13_chartstep_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void initSimStructsc13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber);
static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_EndVel, const char_T *c13_identifier,
  real_T c13_y[3]);
static void c13_b_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3]);
static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_c_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[9]);
static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static real_T c13_d_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_e_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[16]);
static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_f_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[6]);
static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_g_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[36]);
static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static void c13_h_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[6]);
static void c13_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static void c13_info_helper(c13_ResolvedFunctionInfo c13_info[34]);
static void c13_spat_Jacobian(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, real_T c13_in1[9], real_T c13_in2[6], real_T
  c13_b_spat_Jacobian[36]);
static real_T c13_power(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, real_T c13_a);
static void c13_eml_int_forloop_overflow_check
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void c13_eml_scalar_eg(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance);
static void c13_fwd_kin(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, real_T c13_in1[9], real_T c13_in2[6], real_T c13_gst[16]);
static void c13_b_eml_int_forloop_overflow_check
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static const mxArray *c13_h_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData);
static int32_T c13_i_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void c13_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData);
static uint8_T c13_j_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_b_is_active_c13_CtrPlatform_RobustControl, const char_T *c13_identifier);
static uint8_T c13_k_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_u, const emlrtMsgIdentifier *c13_parentId);
static void init_dsm_address_info(SFc13_CtrPlatform_RobustControlInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  chartInstance->c13_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c13_is_active_c13_CtrPlatform_RobustControl = 0U;
}

static void initialize_params_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  real_T c13_dv0[9];
  int32_T c13_i0;
  sf_set_error_prefix_string(
    "Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import_named("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c13_dv0, 0, 0, 0U, 1, 0U, 2, 1, 9);
  for (c13_i0 = 0; c13_i0 < 9; c13_i0++) {
    chartInstance->c13_L[c13_i0] = c13_dv0[c13_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c13_update_debugger_state_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  const mxArray *c13_st;
  const mxArray *c13_y = NULL;
  int32_T c13_i1;
  real_T c13_u[3];
  const mxArray *c13_b_y = NULL;
  uint8_T c13_hoistedGlobal;
  uint8_T c13_b_u;
  const mxArray *c13_c_y = NULL;
  real_T (*c13_EndVel)[3];
  c13_EndVel = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_st = NULL;
  c13_st = NULL;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_createcellarray(2), FALSE);
  for (c13_i1 = 0; c13_i1 < 3; c13_i1++) {
    c13_u[c13_i1] = (*c13_EndVel)[c13_i1];
  }

  c13_b_y = NULL;
  sf_mex_assign(&c13_b_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c13_y, 0, c13_b_y);
  c13_hoistedGlobal = chartInstance->c13_is_active_c13_CtrPlatform_RobustControl;
  c13_b_u = c13_hoistedGlobal;
  c13_c_y = NULL;
  sf_mex_assign(&c13_c_y, sf_mex_create("y", &c13_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c13_y, 1, c13_c_y);
  sf_mex_assign(&c13_st, c13_y, FALSE);
  return c13_st;
}

static void set_sim_state_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_st)
{
  const mxArray *c13_u;
  real_T c13_dv1[3];
  int32_T c13_i2;
  real_T (*c13_EndVel)[3];
  c13_EndVel = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c13_doneDoubleBufferReInit = TRUE;
  c13_u = sf_mex_dup(c13_st);
  c13_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 0)),
                       "EndVel", c13_dv1);
  for (c13_i2 = 0; c13_i2 < 3; c13_i2++) {
    (*c13_EndVel)[c13_i2] = c13_dv1[c13_i2];
  }

  chartInstance->c13_is_active_c13_CtrPlatform_RobustControl =
    c13_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c13_u, 1)),
    "is_active_c13_CtrPlatform_RobustControl");
  sf_mex_destroy(&c13_u);
  c13_update_debugger_state_c13_CtrPlatform_RobustControl(chartInstance);
  sf_mex_destroy(&c13_st);
}

static void finalize_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void sf_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  int32_T c13_i3;
  int32_T c13_i4;
  int32_T c13_i5;
  int32_T c13_i6;
  real_T (*c13_EndVel)[3];
  real_T (*c13_Omega)[6];
  real_T (*c13_Theta)[6];
  c13_EndVel = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_Omega = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c13_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10U, chartInstance->c13_sfEvent);
  for (c13_i3 = 0; c13_i3 < 6; c13_i3++) {
    _SFD_DATA_RANGE_CHECK((*c13_Theta)[c13_i3], 0U);
  }

  for (c13_i4 = 0; c13_i4 < 6; c13_i4++) {
    _SFD_DATA_RANGE_CHECK((*c13_Omega)[c13_i4], 1U);
  }

  for (c13_i5 = 0; c13_i5 < 3; c13_i5++) {
    _SFD_DATA_RANGE_CHECK((*c13_EndVel)[c13_i5], 2U);
  }

  for (c13_i6 = 0; c13_i6 < 9; c13_i6++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c13_L[c13_i6], 3U);
  }

  chartInstance->c13_sfEvent = CALL_EVENT;
  c13_chartstep_c13_CtrPlatform_RobustControl(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_RobustControlMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c13_chartstep_c13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  int32_T c13_i7;
  real_T c13_Theta[6];
  int32_T c13_i8;
  real_T c13_Omega[6];
  int32_T c13_i9;
  real_T c13_b_L[9];
  uint32_T c13_debug_family_var_map[10];
  real_T c13_EndVW[6];
  real_T c13_gd[16];
  real_T c13_EndW[3];
  real_T c13_gd_pos[3];
  real_T c13_nargin = 3.0;
  real_T c13_nargout = 1.0;
  real_T c13_EndVel[3];
  int32_T c13_i10;
  real_T c13_c_L[9];
  int32_T c13_i11;
  real_T c13_b_Theta[6];
  real_T c13_a[36];
  int32_T c13_i12;
  real_T c13_b[6];
  int32_T c13_i13;
  int32_T c13_i14;
  int32_T c13_i15;
  real_T c13_C[6];
  int32_T c13_i16;
  int32_T c13_i17;
  int32_T c13_i18;
  int32_T c13_i19;
  int32_T c13_i20;
  int32_T c13_i21;
  int32_T c13_i22;
  real_T c13_d_L[9];
  int32_T c13_i23;
  real_T c13_c_Theta[6];
  real_T c13_dv2[16];
  int32_T c13_i24;
  int32_T c13_i25;
  int32_T c13_i26;
  int32_T c13_i27;
  real_T c13_b_a[3];
  int32_T c13_i28;
  real_T c13_b_b[3];
  real_T c13_c_a;
  real_T c13_c_b;
  real_T c13_y;
  real_T c13_d_a;
  real_T c13_d_b;
  real_T c13_b_y;
  real_T c13_c1;
  real_T c13_e_a;
  real_T c13_e_b;
  real_T c13_c_y;
  real_T c13_f_a;
  real_T c13_f_b;
  real_T c13_d_y;
  real_T c13_c2;
  real_T c13_g_a;
  real_T c13_g_b;
  real_T c13_e_y;
  real_T c13_h_a;
  real_T c13_h_b;
  real_T c13_f_y;
  real_T c13_c3;
  int32_T c13_i29;
  real_T (*c13_b_EndVel)[3];
  real_T (*c13_b_Omega)[6];
  real_T (*c13_d_Theta)[6];
  c13_b_EndVel = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c13_b_Omega = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c13_d_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c13_sfEvent);
  for (c13_i7 = 0; c13_i7 < 6; c13_i7++) {
    c13_Theta[c13_i7] = (*c13_d_Theta)[c13_i7];
  }

  for (c13_i8 = 0; c13_i8 < 6; c13_i8++) {
    c13_Omega[c13_i8] = (*c13_b_Omega)[c13_i8];
  }

  for (c13_i9 = 0; c13_i9 < 9; c13_i9++) {
    c13_b_L[c13_i9] = chartInstance->c13_L[c13_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c13_debug_family_names,
    c13_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c13_EndVW, 0U, c13_c_sf_marshallOut,
    c13_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_gd, 1U, c13_e_sf_marshallOut,
    c13_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_EndW, 2U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_gd_pos, 3U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargin, 4U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargout, 5U,
    c13_d_sf_marshallOut, c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c13_Theta, 6U, c13_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c13_Omega, 7U, c13_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c13_b_L, 8U, c13_b_sf_marshallOut,
    c13_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_EndVel, 9U, c13_sf_marshallOut,
    c13_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 5);
  for (c13_i10 = 0; c13_i10 < 9; c13_i10++) {
    c13_c_L[c13_i10] = c13_b_L[c13_i10];
  }

  for (c13_i11 = 0; c13_i11 < 6; c13_i11++) {
    c13_b_Theta[c13_i11] = c13_Theta[c13_i11];
  }

  c13_spat_Jacobian(chartInstance, c13_c_L, c13_b_Theta, c13_a);
  for (c13_i12 = 0; c13_i12 < 6; c13_i12++) {
    c13_b[c13_i12] = c13_Omega[c13_i12];
  }

  c13_eml_scalar_eg(chartInstance);
  c13_eml_scalar_eg(chartInstance);
  for (c13_i13 = 0; c13_i13 < 6; c13_i13++) {
    c13_EndVW[c13_i13] = 0.0;
  }

  for (c13_i14 = 0; c13_i14 < 6; c13_i14++) {
    c13_EndVW[c13_i14] = 0.0;
  }

  for (c13_i15 = 0; c13_i15 < 6; c13_i15++) {
    c13_C[c13_i15] = c13_EndVW[c13_i15];
  }

  for (c13_i16 = 0; c13_i16 < 6; c13_i16++) {
    c13_EndVW[c13_i16] = c13_C[c13_i16];
  }

  for (c13_i17 = 0; c13_i17 < 6; c13_i17++) {
    c13_C[c13_i17] = c13_EndVW[c13_i17];
  }

  for (c13_i18 = 0; c13_i18 < 6; c13_i18++) {
    c13_EndVW[c13_i18] = c13_C[c13_i18];
  }

  for (c13_i19 = 0; c13_i19 < 6; c13_i19++) {
    c13_EndVW[c13_i19] = 0.0;
    c13_i20 = 0;
    for (c13_i21 = 0; c13_i21 < 6; c13_i21++) {
      c13_EndVW[c13_i19] += c13_a[c13_i20 + c13_i19] * c13_b[c13_i21];
      c13_i20 += 6;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 6);
  for (c13_i22 = 0; c13_i22 < 9; c13_i22++) {
    c13_d_L[c13_i22] = c13_b_L[c13_i22];
  }

  for (c13_i23 = 0; c13_i23 < 6; c13_i23++) {
    c13_c_Theta[c13_i23] = c13_Theta[c13_i23];
  }

  c13_fwd_kin(chartInstance, c13_d_L, c13_c_Theta, c13_dv2);
  for (c13_i24 = 0; c13_i24 < 16; c13_i24++) {
    c13_gd[c13_i24] = c13_dv2[c13_i24];
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 7);
  for (c13_i25 = 0; c13_i25 < 3; c13_i25++) {
    c13_EndW[c13_i25] = c13_EndVW[c13_i25 + 3];
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 8);
  for (c13_i26 = 0; c13_i26 < 3; c13_i26++) {
    c13_gd_pos[c13_i26] = c13_gd[c13_i26 + 12];
  }

  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, 9);
  for (c13_i27 = 0; c13_i27 < 3; c13_i27++) {
    c13_b_a[c13_i27] = c13_EndW[c13_i27];
  }

  for (c13_i28 = 0; c13_i28 < 3; c13_i28++) {
    c13_b_b[c13_i28] = c13_gd_pos[c13_i28];
  }

  c13_c_a = c13_b_a[1];
  c13_c_b = c13_b_b[2];
  c13_y = c13_c_a * c13_c_b;
  c13_d_a = c13_b_a[2];
  c13_d_b = c13_b_b[1];
  c13_b_y = c13_d_a * c13_d_b;
  c13_c1 = c13_y - c13_b_y;
  c13_e_a = c13_b_a[2];
  c13_e_b = c13_b_b[0];
  c13_c_y = c13_e_a * c13_e_b;
  c13_f_a = c13_b_a[0];
  c13_f_b = c13_b_b[2];
  c13_d_y = c13_f_a * c13_f_b;
  c13_c2 = c13_c_y - c13_d_y;
  c13_g_a = c13_b_a[0];
  c13_g_b = c13_b_b[1];
  c13_e_y = c13_g_a * c13_g_b;
  c13_h_a = c13_b_a[1];
  c13_h_b = c13_b_b[0];
  c13_f_y = c13_h_a * c13_h_b;
  c13_c3 = c13_e_y - c13_f_y;
  c13_EndVel[0] = c13_c1;
  c13_EndVel[1] = c13_c2;
  c13_EndVel[2] = c13_c3;
  _SFD_EML_CALL(0U, chartInstance->c13_sfEvent, -9);
  sf_debug_symbol_scope_pop();
  for (c13_i29 = 0; c13_i29 < 3; c13_i29++) {
    (*c13_b_EndVel)[c13_i29] = c13_EndVel[c13_i29];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c13_sfEvent);
}

static void initSimStructsc13_CtrPlatform_RobustControl
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c13_machineNumber, uint32_T
  c13_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, 0U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/InternFromZHAOTX/Fanuc/spat_Jacobian.m"));
  _SFD_SCRIPT_TRANSLATION(c13_chartNumber, 1U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/InternFromZHAOTX/Fanuc/fwd_kin.m"));
}

static const mxArray *c13_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i30;
  real_T c13_b_inData[3];
  int32_T c13_i31;
  real_T c13_u[3];
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i30 = 0; c13_i30 < 3; c13_i30++) {
    c13_b_inData[c13_i30] = (*(real_T (*)[3])c13_inData)[c13_i30];
  }

  for (c13_i31 = 0; c13_i31 < 3; c13_i31++) {
    c13_u[c13_i31] = c13_b_inData[c13_i31];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_EndVel, const char_T *c13_identifier,
  real_T c13_y[3])
{
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_EndVel), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_EndVel);
}

static void c13_b_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[3])
{
  real_T c13_dv3[3];
  int32_T c13_i32;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c13_i32 = 0; c13_i32 < 3; c13_i32++) {
    c13_y[c13_i32] = c13_dv3[c13_i32];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_EndVel;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[3];
  int32_T c13_i33;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_EndVel = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_EndVel), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_EndVel);
  for (c13_i33 = 0; c13_i33 < 3; c13_i33++) {
    (*(real_T (*)[3])c13_outData)[c13_i33] = c13_y[c13_i33];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_b_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i34;
  real_T c13_b_inData[9];
  int32_T c13_i35;
  real_T c13_u[9];
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i34 = 0; c13_i34 < 9; c13_i34++) {
    c13_b_inData[c13_i34] = (*(real_T (*)[9])c13_inData)[c13_i34];
  }

  for (c13_i35 = 0; c13_i35 < 9; c13_i35++) {
    c13_u[c13_i35] = c13_b_inData[c13_i35];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_c_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[9])
{
  real_T c13_dv4[9];
  int32_T c13_i36;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv4, 1, 0, 0U, 1, 0U, 2, 1,
                9);
  for (c13_i36 = 0; c13_i36 < 9; c13_i36++) {
    c13_y[c13_i36] = c13_dv4[c13_i36];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_L;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[9];
  int32_T c13_i37;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_b_L = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_L), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_b_L);
  for (c13_i37 = 0; c13_i37 < 9; c13_i37++) {
    (*(real_T (*)[9])c13_outData)[c13_i37] = c13_y[c13_i37];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_c_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i38;
  real_T c13_b_inData[6];
  int32_T c13_i39;
  real_T c13_u[6];
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i38 = 0; c13_i38 < 6; c13_i38++) {
    c13_b_inData[c13_i38] = (*(real_T (*)[6])c13_inData)[c13_i38];
  }

  for (c13_i39 = 0; c13_i39 < 6; c13_i39++) {
    c13_u[c13_i39] = c13_b_inData[c13_i39];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static const mxArray *c13_d_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  real_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(real_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static real_T c13_d_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  real_T c13_y;
  real_T c13_d0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_d0, 1, 0, 0U, 0, 0U, 0);
  c13_y = c13_d0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_nargout;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_nargout = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_nargout),
    &c13_thisId);
  sf_mex_destroy(&c13_nargout);
  *(real_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_e_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i40;
  int32_T c13_i41;
  int32_T c13_i42;
  real_T c13_b_inData[16];
  int32_T c13_i43;
  int32_T c13_i44;
  int32_T c13_i45;
  real_T c13_u[16];
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_i40 = 0;
  for (c13_i41 = 0; c13_i41 < 4; c13_i41++) {
    for (c13_i42 = 0; c13_i42 < 4; c13_i42++) {
      c13_b_inData[c13_i42 + c13_i40] = (*(real_T (*)[16])c13_inData)[c13_i42 +
        c13_i40];
    }

    c13_i40 += 4;
  }

  c13_i43 = 0;
  for (c13_i44 = 0; c13_i44 < 4; c13_i44++) {
    for (c13_i45 = 0; c13_i45 < 4; c13_i45++) {
      c13_u[c13_i45 + c13_i43] = c13_b_inData[c13_i45 + c13_i43];
    }

    c13_i43 += 4;
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_e_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[16])
{
  real_T c13_dv5[16];
  int32_T c13_i46;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv5, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c13_i46 = 0; c13_i46 < 16; c13_i46++) {
    c13_y[c13_i46] = c13_dv5[c13_i46];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_gd;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[16];
  int32_T c13_i47;
  int32_T c13_i48;
  int32_T c13_i49;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_gd = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_gd), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_gd);
  c13_i47 = 0;
  for (c13_i48 = 0; c13_i48 < 4; c13_i48++) {
    for (c13_i49 = 0; c13_i49 < 4; c13_i49++) {
      (*(real_T (*)[16])c13_outData)[c13_i49 + c13_i47] = c13_y[c13_i49 +
        c13_i47];
    }

    c13_i47 += 4;
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static void c13_f_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[6])
{
  real_T c13_dv6[6];
  int32_T c13_i50;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv6, 1, 0, 0U, 1, 0U, 1, 6);
  for (c13_i50 = 0; c13_i50 < 6; c13_i50++) {
    c13_y[c13_i50] = c13_dv6[c13_i50];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_EndVW;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[6];
  int32_T c13_i51;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_EndVW = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_EndVW), &c13_thisId,
    c13_y);
  sf_mex_destroy(&c13_EndVW);
  for (c13_i51 = 0; c13_i51 < 6; c13_i51++) {
    (*(real_T (*)[6])c13_outData)[c13_i51] = c13_y[c13_i51];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_f_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i52;
  int32_T c13_i53;
  int32_T c13_i54;
  real_T c13_b_inData[36];
  int32_T c13_i55;
  int32_T c13_i56;
  int32_T c13_i57;
  real_T c13_u[36];
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_i52 = 0;
  for (c13_i53 = 0; c13_i53 < 6; c13_i53++) {
    for (c13_i54 = 0; c13_i54 < 6; c13_i54++) {
      c13_b_inData[c13_i54 + c13_i52] = (*(real_T (*)[36])c13_inData)[c13_i54 +
        c13_i52];
    }

    c13_i52 += 6;
  }

  c13_i55 = 0;
  for (c13_i56 = 0; c13_i56 < 6; c13_i56++) {
    for (c13_i57 = 0; c13_i57 < 6; c13_i57++) {
      c13_u[c13_i57 + c13_i55] = c13_b_inData[c13_i57 + c13_i55];
    }

    c13_i55 += 6;
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_g_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[36])
{
  real_T c13_dv7[36];
  int32_T c13_i58;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv7, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c13_i58 = 0; c13_i58 < 36; c13_i58++) {
    c13_y[c13_i58] = c13_dv7[c13_i58];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_spat_Jacobian;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[36];
  int32_T c13_i59;
  int32_T c13_i60;
  int32_T c13_i61;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_b_spat_Jacobian = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_spat_Jacobian),
    &c13_thisId, c13_y);
  sf_mex_destroy(&c13_b_spat_Jacobian);
  c13_i59 = 0;
  for (c13_i60 = 0; c13_i60 < 6; c13_i60++) {
    for (c13_i61 = 0; c13_i61 < 6; c13_i61++) {
      (*(real_T (*)[36])c13_outData)[c13_i61 + c13_i59] = c13_y[c13_i61 +
        c13_i59];
    }

    c13_i59 += 6;
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

static const mxArray *c13_g_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_i62;
  real_T c13_b_inData[6];
  int32_T c13_i63;
  real_T c13_u[6];
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  for (c13_i62 = 0; c13_i62 < 6; c13_i62++) {
    c13_b_inData[c13_i62] = (*(real_T (*)[6])c13_inData)[c13_i62];
  }

  for (c13_i63 = 0; c13_i63 < 6; c13_i63++) {
    c13_u[c13_i63] = c13_b_inData[c13_i63];
  }

  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", c13_u, 0, 0U, 1U, 0U, 2, 1, 6), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static void c13_h_emlrt_marshallIn(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c13_u, const emlrtMsgIdentifier *c13_parentId,
  real_T c13_y[6])
{
  real_T c13_dv8[6];
  int32_T c13_i64;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), c13_dv8, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c13_i64 = 0; c13_i64 < 6; c13_i64++) {
    c13_y[c13_i64] = c13_dv8[c13_i64];
  }

  sf_mex_destroy(&c13_u);
}

static void c13_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_in2;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  real_T c13_y[6];
  int32_T c13_i65;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_in2 = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_in2), &c13_thisId, c13_y);
  sf_mex_destroy(&c13_in2);
  for (c13_i65 = 0; c13_i65 < 6; c13_i65++) {
    (*(real_T (*)[6])c13_outData)[c13_i65] = c13_y[c13_i65];
  }

  sf_mex_destroy(&c13_mxArrayInData);
}

const mxArray *sf_c13_CtrPlatform_RobustControl_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c13_nameCaptureInfo;
  c13_ResolvedFunctionInfo c13_info[34];
  const mxArray *c13_m0 = NULL;
  int32_T c13_i66;
  c13_ResolvedFunctionInfo *c13_r0;
  c13_nameCaptureInfo = NULL;
  c13_nameCaptureInfo = NULL;
  c13_info_helper(c13_info);
  sf_mex_assign(&c13_m0, sf_mex_createstruct("nameCaptureInfo", 1, 34), FALSE);
  for (c13_i66 = 0; c13_i66 < 34; c13_i66++) {
    c13_r0 = &c13_info[c13_i66];
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->context)), "context", "nameCaptureInfo",
                    c13_i66);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c13_r0->name)), "name", "nameCaptureInfo",
                    c13_i66);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      c13_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c13_i66);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", c13_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c13_r0->resolved)), "resolved",
                    "nameCaptureInfo", c13_i66);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c13_i66);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo", &c13_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c13_i66);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c13_i66);
    sf_mex_addfield(c13_m0, sf_mex_create("nameCaptureInfo",
      &c13_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c13_i66);
  }

  sf_mex_assign(&c13_nameCaptureInfo, c13_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c13_nameCaptureInfo);
  return c13_nameCaptureInfo;
}

static void c13_info_helper(c13_ResolvedFunctionInfo c13_info[34])
{
  c13_info[0].context = "";
  c13_info[0].name = "spat_Jacobian";
  c13_info[0].dominantType = "double";
  c13_info[0].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/spat_Jacobian.m";
  c13_info[0].fileTimeLo = 1366807306U;
  c13_info[0].fileTimeHi = 0U;
  c13_info[0].mFileTimeLo = 0U;
  c13_info[0].mFileTimeHi = 0U;
  c13_info[1].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/spat_Jacobian.m";
  c13_info[1].name = "cos";
  c13_info[1].dominantType = "double";
  c13_info[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c13_info[1].fileTimeLo = 1286797106U;
  c13_info[1].fileTimeHi = 0U;
  c13_info[1].mFileTimeLo = 0U;
  c13_info[1].mFileTimeHi = 0U;
  c13_info[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c13_info[2].name = "eml_scalar_cos";
  c13_info[2].dominantType = "double";
  c13_info[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c13_info[2].fileTimeLo = 1286797122U;
  c13_info[2].fileTimeHi = 0U;
  c13_info[2].mFileTimeLo = 0U;
  c13_info[2].mFileTimeHi = 0U;
  c13_info[3].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/spat_Jacobian.m";
  c13_info[3].name = "sin";
  c13_info[3].dominantType = "double";
  c13_info[3].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c13_info[3].fileTimeLo = 1286797150U;
  c13_info[3].fileTimeHi = 0U;
  c13_info[3].mFileTimeLo = 0U;
  c13_info[3].mFileTimeHi = 0U;
  c13_info[4].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c13_info[4].name = "eml_scalar_sin";
  c13_info[4].dominantType = "double";
  c13_info[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c13_info[4].fileTimeLo = 1286797136U;
  c13_info[4].fileTimeHi = 0U;
  c13_info[4].mFileTimeLo = 0U;
  c13_info[4].mFileTimeHi = 0U;
  c13_info[5].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/spat_Jacobian.m";
  c13_info[5].name = "power";
  c13_info[5].dominantType = "double";
  c13_info[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c13_info[5].fileTimeLo = 1307629640U;
  c13_info[5].fileTimeHi = 0U;
  c13_info[5].mFileTimeLo = 0U;
  c13_info[5].mFileTimeHi = 0U;
  c13_info[6].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c13_info[6].name = "eml_scalar_eg";
  c13_info[6].dominantType = "double";
  c13_info[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c13_info[6].fileTimeLo = 1286797196U;
  c13_info[6].fileTimeHi = 0U;
  c13_info[6].mFileTimeLo = 0U;
  c13_info[6].mFileTimeHi = 0U;
  c13_info[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c13_info[7].name = "eml_scalexp_alloc";
  c13_info[7].dominantType = "double";
  c13_info[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c13_info[7].fileTimeLo = 1286797196U;
  c13_info[7].fileTimeHi = 0U;
  c13_info[7].mFileTimeLo = 0U;
  c13_info[7].mFileTimeHi = 0U;
  c13_info[8].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c13_info[8].name = "eml_scalar_floor";
  c13_info[8].dominantType = "double";
  c13_info[8].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c13_info[8].fileTimeLo = 1286797126U;
  c13_info[8].fileTimeHi = 0U;
  c13_info[8].mFileTimeLo = 0U;
  c13_info[8].mFileTimeHi = 0U;
  c13_info[9].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/spat_Jacobian.m";
  c13_info[9].name = "reshape";
  c13_info[9].dominantType = "double";
  c13_info[9].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c13_info[9].fileTimeLo = 1286797168U;
  c13_info[9].fileTimeHi = 0U;
  c13_info[9].mFileTimeLo = 0U;
  c13_info[9].mFileTimeHi = 0U;
  c13_info[10].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c13_info[10].name = "eml_index_class";
  c13_info[10].dominantType = "";
  c13_info[10].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c13_info[10].fileTimeLo = 1286797178U;
  c13_info[10].fileTimeHi = 0U;
  c13_info[10].mFileTimeLo = 0U;
  c13_info[10].mFileTimeHi = 0U;
  c13_info[11].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c13_info[11].name = "eml_index_class";
  c13_info[11].dominantType = "";
  c13_info[11].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c13_info[11].fileTimeLo = 1286797178U;
  c13_info[11].fileTimeHi = 0U;
  c13_info[11].mFileTimeLo = 0U;
  c13_info[11].mFileTimeHi = 0U;
  c13_info[12].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c13_info[12].name = "eml_assert_valid_size_arg";
  c13_info[12].dominantType = "double";
  c13_info[12].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c13_info[12].fileTimeLo = 1286797094U;
  c13_info[12].fileTimeHi = 0U;
  c13_info[12].mFileTimeLo = 0U;
  c13_info[12].mFileTimeHi = 0U;
  c13_info[13].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c13_info[13].name = "isinf";
  c13_info[13].dominantType = "double";
  c13_info[13].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c13_info[13].fileTimeLo = 1286797160U;
  c13_info[13].fileTimeHi = 0U;
  c13_info[13].mFileTimeLo = 0U;
  c13_info[13].mFileTimeHi = 0U;
  c13_info[14].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c13_info[14].name = "mtimes";
  c13_info[14].dominantType = "double";
  c13_info[14].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[14].fileTimeLo = 1289494492U;
  c13_info[14].fileTimeHi = 0U;
  c13_info[14].mFileTimeLo = 0U;
  c13_info[14].mFileTimeHi = 0U;
  c13_info[15].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c13_info[15].name = "eml_index_class";
  c13_info[15].dominantType = "";
  c13_info[15].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c13_info[15].fileTimeLo = 1286797178U;
  c13_info[15].fileTimeHi = 0U;
  c13_info[15].mFileTimeLo = 0U;
  c13_info[15].mFileTimeHi = 0U;
  c13_info[16].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c13_info[16].name = "intmax";
  c13_info[16].dominantType = "char";
  c13_info[16].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c13_info[16].fileTimeLo = 1311233716U;
  c13_info[16].fileTimeHi = 0U;
  c13_info[16].mFileTimeLo = 0U;
  c13_info[16].mFileTimeHi = 0U;
  c13_info[17].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c13_info[17].name = "eml_scalar_eg";
  c13_info[17].dominantType = "double";
  c13_info[17].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c13_info[17].fileTimeLo = 1286797196U;
  c13_info[17].fileTimeHi = 0U;
  c13_info[17].mFileTimeLo = 0U;
  c13_info[17].mFileTimeHi = 0U;
  c13_info[18].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c13_info[18].name = "eml_int_forloop_overflow_check";
  c13_info[18].dominantType = "";
  c13_info[18].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c13_info[18].fileTimeLo = 1311233716U;
  c13_info[18].fileTimeHi = 0U;
  c13_info[18].mFileTimeLo = 0U;
  c13_info[18].mFileTimeHi = 0U;
  c13_info[19].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c13_info[19].name = "intmax";
  c13_info[19].dominantType = "char";
  c13_info[19].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c13_info[19].fileTimeLo = 1311233716U;
  c13_info[19].fileTimeHi = 0U;
  c13_info[19].mFileTimeLo = 0U;
  c13_info[19].mFileTimeHi = 0U;
  c13_info[20].context = "";
  c13_info[20].name = "mtimes";
  c13_info[20].dominantType = "double";
  c13_info[20].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[20].fileTimeLo = 1289494492U;
  c13_info[20].fileTimeHi = 0U;
  c13_info[20].mFileTimeLo = 0U;
  c13_info[20].mFileTimeHi = 0U;
  c13_info[21].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[21].name = "eml_index_class";
  c13_info[21].dominantType = "";
  c13_info[21].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c13_info[21].fileTimeLo = 1286797178U;
  c13_info[21].fileTimeHi = 0U;
  c13_info[21].mFileTimeLo = 0U;
  c13_info[21].mFileTimeHi = 0U;
  c13_info[22].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[22].name = "eml_scalar_eg";
  c13_info[22].dominantType = "double";
  c13_info[22].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c13_info[22].fileTimeLo = 1286797196U;
  c13_info[22].fileTimeHi = 0U;
  c13_info[22].mFileTimeLo = 0U;
  c13_info[22].mFileTimeHi = 0U;
  c13_info[23].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[23].name = "eml_xgemm";
  c13_info[23].dominantType = "int32";
  c13_info[23].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c13_info[23].fileTimeLo = 1299051572U;
  c13_info[23].fileTimeHi = 0U;
  c13_info[23].mFileTimeLo = 0U;
  c13_info[23].mFileTimeHi = 0U;
  c13_info[24].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c13_info[24].name = "eml_blas_inline";
  c13_info[24].dominantType = "";
  c13_info[24].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c13_info[24].fileTimeLo = 1299051568U;
  c13_info[24].fileTimeHi = 0U;
  c13_info[24].mFileTimeLo = 0U;
  c13_info[24].mFileTimeHi = 0U;
  c13_info[25].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c13_info[25].name = "mtimes";
  c13_info[25].dominantType = "double";
  c13_info[25].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[25].fileTimeLo = 1289494492U;
  c13_info[25].fileTimeHi = 0U;
  c13_info[25].mFileTimeLo = 0U;
  c13_info[25].mFileTimeHi = 0U;
  c13_info[26].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c13_info[26].name = "eml_scalar_eg";
  c13_info[26].dominantType = "double";
  c13_info[26].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c13_info[26].fileTimeLo = 1286797196U;
  c13_info[26].fileTimeHi = 0U;
  c13_info[26].mFileTimeLo = 0U;
  c13_info[26].mFileTimeHi = 0U;
  c13_info[27].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c13_info[27].name = "eml_refblas_xgemm";
  c13_info[27].dominantType = "int32";
  c13_info[27].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c13_info[27].fileTimeLo = 1299051574U;
  c13_info[27].fileTimeHi = 0U;
  c13_info[27].mFileTimeLo = 0U;
  c13_info[27].mFileTimeHi = 0U;
  c13_info[28].context = "";
  c13_info[28].name = "fwd_kin";
  c13_info[28].dominantType = "double";
  c13_info[28].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/fwd_kin.m";
  c13_info[28].fileTimeLo = 1366778960U;
  c13_info[28].fileTimeHi = 0U;
  c13_info[28].mFileTimeLo = 0U;
  c13_info[28].mFileTimeHi = 0U;
  c13_info[29].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/fwd_kin.m";
  c13_info[29].name = "cos";
  c13_info[29].dominantType = "double";
  c13_info[29].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c13_info[29].fileTimeLo = 1286797106U;
  c13_info[29].fileTimeHi = 0U;
  c13_info[29].mFileTimeLo = 0U;
  c13_info[29].mFileTimeHi = 0U;
  c13_info[30].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/fwd_kin.m";
  c13_info[30].name = "sin";
  c13_info[30].dominantType = "double";
  c13_info[30].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c13_info[30].fileTimeLo = 1286797150U;
  c13_info[30].fileTimeHi = 0U;
  c13_info[30].mFileTimeLo = 0U;
  c13_info[30].mFileTimeHi = 0U;
  c13_info[31].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/InternFromZHAOTX/Fanuc/fwd_kin.m";
  c13_info[31].name = "reshape";
  c13_info[31].dominantType = "double";
  c13_info[31].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/reshape.m";
  c13_info[31].fileTimeLo = 1286797168U;
  c13_info[31].fileTimeHi = 0U;
  c13_info[31].mFileTimeLo = 0U;
  c13_info[31].mFileTimeHi = 0U;
  c13_info[32].context = "";
  c13_info[32].name = "cross";
  c13_info[32].dominantType = "double";
  c13_info[32].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c13_info[32].fileTimeLo = 1286797242U;
  c13_info[32].fileTimeHi = 0U;
  c13_info[32].mFileTimeLo = 0U;
  c13_info[32].mFileTimeHi = 0U;
  c13_info[33].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c13_info[33].name = "mtimes";
  c13_info[33].dominantType = "double";
  c13_info[33].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c13_info[33].fileTimeLo = 1289494492U;
  c13_info[33].fileTimeHi = 0U;
  c13_info[33].mFileTimeLo = 0U;
  c13_info[33].mFileTimeHi = 0U;
}

static void c13_spat_Jacobian(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, real_T c13_in1[9], real_T c13_in2[6], real_T
  c13_b_spat_Jacobian[36])
{
  uint32_T c13_debug_family_var_map[64];
  real_T c13_A1;
  real_T c13_A2;
  real_T c13_A3;
  real_T c13_A4;
  real_T c13_A5;
  real_T c13_L1;
  real_T c13_L2;
  real_T c13_L3;
  real_T c13_L4;
  real_T c13_L5;
  real_T c13_t2;
  real_T c13_t3;
  real_T c13_t4;
  real_T c13_t5;
  real_T c13_t6;
  real_T c13_t7;
  real_T c13_t8;
  real_T c13_t9;
  real_T c13_t10;
  real_T c13_t11;
  real_T c13_t12;
  real_T c13_t13;
  real_T c13_t14;
  real_T c13_t15;
  real_T c13_t16;
  real_T c13_t17;
  real_T c13_t18;
  real_T c13_t19;
  real_T c13_t20;
  real_T c13_t21;
  real_T c13_t22;
  real_T c13_t23;
  real_T c13_t24;
  real_T c13_t25;
  real_T c13_t26;
  real_T c13_t27;
  real_T c13_t28;
  real_T c13_t29;
  real_T c13_t30;
  real_T c13_t31;
  real_T c13_t32;
  real_T c13_t33;
  real_T c13_t34;
  real_T c13_t35;
  real_T c13_t36;
  real_T c13_t37;
  real_T c13_t38;
  real_T c13_t47;
  real_T c13_t39;
  real_T c13_t40;
  real_T c13_t41;
  real_T c13_t42;
  real_T c13_t43;
  real_T c13_t44;
  real_T c13_t45;
  real_T c13_t46;
  real_T c13_t48;
  real_T c13_t49;
  real_T c13_t50;
  real_T c13_nargin = 2.0;
  real_T c13_nargout = 1.0;
  real_T c13_x;
  real_T c13_b_x;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_e_x;
  real_T c13_f_x;
  real_T c13_g_x;
  real_T c13_h_x;
  real_T c13_i_x;
  real_T c13_j_x;
  real_T c13_k_x;
  real_T c13_l_x;
  real_T c13_m_x;
  real_T c13_n_x;
  real_T c13_o_x;
  real_T c13_p_x;
  real_T c13_q_x;
  real_T c13_r_x;
  real_T c13_s_x;
  real_T c13_t_x;
  real_T c13_u_x;
  real_T c13_v_x;
  real_T c13_w_x;
  real_T c13_x_x;
  real_T c13_d1;
  real_T c13_y_x[36];
  int32_T c13_k;
  int32_T c13_b_k;
  sf_debug_symbol_scope_push_eml(0U, 64U, 64U, c13_b_debug_family_names,
    c13_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c13_A1, 0U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A2, 1U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A3, 2U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A4, 3U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A5, 4U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L1, 5U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L2, 6U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L3, 7U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L4, 8U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L5, 9U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t2, 10U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t3, 11U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t4, 12U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t5, 13U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t6, 14U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t7, 15U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t8, 16U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t9, 17U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t10, 18U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t11, 19U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t12, 20U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t13, 21U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t14, 22U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t15, 23U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t16, 24U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t17, 25U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t18, 26U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t19, 27U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t20, 28U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t21, 29U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t22, 30U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t23, 31U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t24, 32U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t25, 33U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t26, 34U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t27, 35U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t28, 36U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t29, 37U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t30, 38U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t31, 39U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t32, 40U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t33, 41U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t34, 42U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t35, 43U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t36, 44U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t37, 45U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t38, 46U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t47, 47U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t39, 48U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t40, 49U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t41, 50U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t42, 51U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t43, 52U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t44, 53U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t45, 54U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t46, 55U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t48, 56U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t49, 57U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t50, 58U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargin, 59U,
    c13_d_sf_marshallOut, c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargout, 60U,
    c13_d_sf_marshallOut, c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_in1, 61U, c13_b_sf_marshallOut,
    c13_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_in2, 62U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_b_spat_Jacobian, 63U,
    c13_f_sf_marshallOut, c13_f_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 8);
  c13_A1 = c13_in2[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 9);
  c13_A2 = c13_in2[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 10);
  c13_A3 = c13_in2[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 11);
  c13_A4 = c13_in2[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 12);
  c13_A5 = c13_in2[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 13);
  c13_L1 = c13_in1[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 14);
  c13_L2 = c13_in1[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 15);
  c13_L3 = c13_in1[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 16);
  c13_L4 = c13_in1[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 17);
  c13_L5 = c13_in1[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 18);
  c13_x = c13_A1;
  c13_t2 = c13_x;
  c13_b_x = c13_t2;
  c13_t2 = c13_b_x;
  c13_t2 = muDoubleScalarCos(c13_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 19);
  c13_t3 = c13_A2 + c13_A3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 20);
  c13_c_x = c13_A2;
  c13_t4 = c13_c_x;
  c13_d_x = c13_t4;
  c13_t4 = c13_d_x;
  c13_t4 = muDoubleScalarCos(c13_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 21);
  c13_e_x = c13_A3;
  c13_t5 = c13_e_x;
  c13_f_x = c13_t5;
  c13_t5 = c13_f_x;
  c13_t5 = muDoubleScalarCos(c13_t5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 22);
  c13_g_x = c13_A2;
  c13_t6 = c13_g_x;
  c13_h_x = c13_t6;
  c13_t6 = c13_h_x;
  c13_t6 = muDoubleScalarSin(c13_t6);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 23);
  c13_i_x = c13_A3;
  c13_t7 = c13_i_x;
  c13_j_x = c13_t7;
  c13_t7 = c13_j_x;
  c13_t7 = muDoubleScalarSin(c13_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 24);
  c13_t8 = c13_L1 + c13_L3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 25);
  c13_t9 = c13_t5 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 26);
  c13_k_x = c13_A1;
  c13_t10 = c13_k_x;
  c13_l_x = c13_t10;
  c13_t10 = c13_l_x;
  c13_t10 = muDoubleScalarSin(c13_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 27);
  c13_m_x = c13_t3;
  c13_t11 = c13_m_x;
  c13_n_x = c13_t11;
  c13_t11 = c13_n_x;
  c13_t11 = muDoubleScalarSin(c13_t11);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 28);
  c13_o_x = c13_A4;
  c13_t12 = c13_o_x;
  c13_p_x = c13_t12;
  c13_t12 = c13_p_x;
  c13_t12 = muDoubleScalarCos(c13_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 29);
  c13_q_x = c13_t3;
  c13_t13 = c13_q_x;
  c13_r_x = c13_t13;
  c13_t13 = c13_r_x;
  c13_t13 = muDoubleScalarCos(c13_t13);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 30);
  c13_s_x = c13_A4;
  c13_t14 = c13_s_x;
  c13_t_x = c13_t14;
  c13_t14 = c13_t_x;
  c13_t14 = muDoubleScalarSin(c13_t14);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 31);
  c13_t15 = (c13_L1 + c13_L3) + c13_L4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 32);
  c13_t16 = c13_L2 * c13_t11;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 33);
  c13_t17 = c13_L3 * c13_t5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 34);
  c13_t18 = c13_L1 * c13_t13;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 35);
  c13_t19 = c13_t12 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 36);
  c13_u_x = c13_A5;
  c13_t20 = c13_u_x;
  c13_v_x = c13_t20;
  c13_t20 = c13_v_x;
  c13_t20 = muDoubleScalarCos(c13_t20);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 37);
  c13_t21 = c13_L2 + c13_L5;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 38);
  c13_w_x = c13_A5;
  c13_t22 = c13_w_x;
  c13_x_x = c13_t22;
  c13_t22 = c13_x_x;
  c13_t22 = muDoubleScalarSin(c13_t22);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 39);
  c13_t23 = c13_t20 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 40);
  c13_t24 = c13_L2 * c13_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 41);
  c13_t25 = c13_t4 - 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 42);
  c13_t26 = c13_t24 - c13_L1 * c13_t25;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 43);
  c13_t27 = c13_t2 * c13_t26;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 44);
  c13_t28 = c13_L2 * c13_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 45);
  c13_t29 = c13_t2 * c13_t4 * (c13_t28 - c13_t8 * c13_t9);
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 46);
  c13_t30 = c13_t7 * c13_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 47);
  c13_t31 = c13_L2 * c13_t9;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 48);
  c13_t32 = c13_t30 + c13_t31;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 49);
  c13_t33 = c13_t2 * c13_t32 * c13_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 50);
  c13_t34 = (c13_t27 + c13_t29) + c13_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 51);
  c13_t35 = c13_L1 * c13_t11;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 52);
  c13_t36 = c13_L3 * c13_t7;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 53);
  c13_t37 = ((c13_L2 + c13_t35) + c13_t36) - c13_L2 * c13_t13;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 54);
  c13_t38 = c13_t10 * c13_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 55);
  c13_t47 = c13_t11 * c13_t14 * c13_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 56);
  c13_t39 = c13_t38 - c13_t47;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 57);
  c13_t40 = c13_L3 * c13_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 58);
  c13_t41 = c13_L1 + c13_t40;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 59);
  c13_t42 = ((c13_L4 + c13_t16) + c13_t17) + c13_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 60);
  c13_t43 = c13_L3 * c13_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 61);
  c13_t44 = c13_L4 * c13_t11;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 62);
  c13_t45 = c13_L5 * c13_t13;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 63);
  c13_t46 = ((c13_L2 + c13_t43) + c13_t44) + c13_t45;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 64);
  c13_t48 = c13_t10 * c13_t14;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 65);
  c13_t49 = c13_t11 * c13_t12 * c13_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 66);
  c13_t50 = c13_t48 + c13_t49;
  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, 67);
  c13_d1 = c13_power(chartInstance, c13_t14);
  c13_y_x[0] = 0.0;
  c13_y_x[1] = 0.0;
  c13_y_x[2] = 0.0;
  c13_y_x[3] = 0.0;
  c13_y_x[4] = 0.0;
  c13_y_x[5] = 1.0;
  c13_y_x[6] = -c13_L1 * c13_t2;
  c13_y_x[7] = -c13_L1 * c13_t10;
  c13_y_x[8] = c13_L2;
  c13_y_x[9] = -c13_t10;
  c13_y_x[10] = c13_t2;
  c13_y_x[11] = 0.0;
  c13_y_x[12] = -c13_t2 * c13_t41;
  c13_y_x[13] = -c13_t10 * c13_t41;
  c13_y_x[14] = c13_L2 + c13_t43;
  c13_y_x[15] = -c13_t10;
  c13_y_x[16] = c13_t2;
  c13_y_x[17] = 0.0;
  c13_y_x[18] = -c13_t10 * c13_t42;
  c13_y_x[19] = c13_t2 * c13_t42;
  c13_y_x[20] = 0.0;
  c13_y_x[21] = c13_t13 * c13_t2;
  c13_y_x[22] = c13_t10 * c13_t13;
  c13_y_x[23] = -c13_t11;
  c13_y_x[24] = (((-c13_t12 * c13_t34 + c13_t21 * c13_t50) + c13_t13 * c13_t2 *
                  (c13_d1 * c13_t15 + c13_t12 * c13_t15 * c13_t19)) - c13_t13 *
                 c13_t15 * c13_t2) - c13_t10 * c13_t14 * c13_t37;
  c13_y_x[25] = ((((((-c13_L1 * c13_t10 * c13_t12 - c13_L5 * c13_t14 * c13_t2) +
                     c13_L1 * c13_t11 * c13_t14 * c13_t2) - c13_L2 * c13_t13 *
                    c13_t14 * c13_t2) - c13_L4 * c13_t10 * c13_t12 * c13_t13) +
                  c13_L5 * c13_t10 * c13_t11 * c13_t12) - c13_L3 * c13_t10 *
                 c13_t12 * c13_t4) + c13_L3 * c13_t14 * c13_t2 * c13_t7;
  c13_y_x[26] = c13_t12 * c13_t46;
  c13_y_x[27] = -c13_t38 + c13_t47;
  c13_y_x[28] = c13_t12 * c13_t2 + c13_t10 * c13_t11 * c13_t14;
  c13_y_x[29] = c13_t13 * c13_t14;
  c13_y_x[30] = ((-c13_t20 * ((c13_t10 * ((((-c13_L1 - c13_L3) + c13_t16) +
    c13_t17) + c13_t18) - c13_t10 * c13_t15 * c13_t19) + c13_t11 * c13_t14 *
    c13_t15 * c13_t2) - c13_t15 * c13_t39) - c13_t22 * ((c13_t14 * c13_t34 +
    c13_t13 * c13_t2 * (c13_t12 * c13_t14 * c13_t15 - c13_t14 * c13_t15 *
                        c13_t19)) - c13_t10 * c13_t12 * c13_t37)) + c13_t39 *
    (c13_t20 * (c13_t15 * c13_t23 - c13_t21 * c13_t22) + c13_t22 * (c13_t15 *
      c13_t22 + c13_t21 * c13_t23));
  c13_y_x[31] = ((((((((((c13_L4 * c13_t2 * c13_t20 - c13_L1 * c13_t10 * c13_t14
    * c13_t22) + c13_L1 * c13_t13 * c13_t2 * c13_t20) + c13_L2 * c13_t11 *
                        c13_t2 * c13_t20) + c13_L5 * c13_t12 * c13_t2 * c13_t22)
                      + c13_L3 * c13_t2 * c13_t20 * c13_t5) - c13_L1 * c13_t11 *
                     c13_t12 * c13_t2 * c13_t22) + c13_L2 * c13_t12 * c13_t13 *
                    c13_t2 * c13_t22) - c13_L4 * c13_t10 * c13_t13 * c13_t14 *
                   c13_t22) + c13_L5 * c13_t10 * c13_t11 * c13_t14 * c13_t22) -
                 c13_L3 * c13_t10 * c13_t14 * c13_t22 * c13_t4) - c13_L3 *
    c13_t12 * c13_t2 * c13_t22 * c13_t7;
  c13_y_x[32] = c13_t14 * c13_t22 * c13_t46;
  c13_y_x[33] = -c13_t22 * c13_t50 + c13_t13 * c13_t2 * c13_t20;
  c13_y_x[34] = c13_t22 * (c13_t14 * c13_t2 - c13_t10 * c13_t11 * c13_t12) +
    c13_t10 * c13_t13 * c13_t20;
  c13_y_x[35] = -c13_t11 * c13_t20 - c13_t12 * c13_t13 * c13_t22;
  c13_eml_int_forloop_overflow_check(chartInstance);
  for (c13_k = 1; c13_k < 37; c13_k++) {
    c13_b_k = c13_k;
    c13_b_spat_Jacobian[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c13_b_k), 1, 36, 1, 0) - 1] =
      c13_y_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c13_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c13_sfEvent, -67);
  sf_debug_symbol_scope_pop();
}

static real_T c13_power(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, real_T c13_a)
{
  real_T c13_ak;
  c13_ak = c13_a;
  return muDoubleScalarPower(c13_ak, 2.0);
}

static void c13_eml_int_forloop_overflow_check
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void c13_eml_scalar_eg(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance)
{
}

static void c13_fwd_kin(SFc13_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, real_T c13_in1[9], real_T c13_in2[6], real_T c13_gst[16])
{
  uint32_T c13_debug_family_var_map[68];
  real_T c13_A1;
  real_T c13_A2;
  real_T c13_A3;
  real_T c13_A4;
  real_T c13_A5;
  real_T c13_A6;
  real_T c13_L1;
  real_T c13_L2;
  real_T c13_L3;
  real_T c13_L4;
  real_T c13_L5;
  real_T c13_L6;
  real_T c13_L7;
  real_T c13_L8;
  real_T c13_L9;
  real_T c13_t2;
  real_T c13_t3;
  real_T c13_t4;
  real_T c13_t5;
  real_T c13_t6;
  real_T c13_t7;
  real_T c13_t8;
  real_T c13_t9;
  real_T c13_t10;
  real_T c13_t11;
  real_T c13_t12;
  real_T c13_t13;
  real_T c13_t14;
  real_T c13_t23;
  real_T c13_t15;
  real_T c13_t16;
  real_T c13_t17;
  real_T c13_t18;
  real_T c13_t19;
  real_T c13_t20;
  real_T c13_t21;
  real_T c13_t22;
  real_T c13_t24;
  real_T c13_t25;
  real_T c13_t26;
  real_T c13_t27;
  real_T c13_t34;
  real_T c13_t28;
  real_T c13_t29;
  real_T c13_t30;
  real_T c13_t31;
  real_T c13_t32;
  real_T c13_t36;
  real_T c13_t33;
  real_T c13_t35;
  real_T c13_t37;
  real_T c13_t38;
  real_T c13_t39;
  real_T c13_t40;
  real_T c13_t41;
  real_T c13_t42;
  real_T c13_t43;
  real_T c13_t44;
  real_T c13_t45;
  real_T c13_t47;
  real_T c13_t46;
  real_T c13_t48;
  real_T c13_t49;
  real_T c13_nargin = 2.0;
  real_T c13_nargout = 1.0;
  real_T c13_x;
  real_T c13_b_x;
  real_T c13_c_x;
  real_T c13_d_x;
  real_T c13_e_x;
  real_T c13_f_x;
  real_T c13_g_x;
  real_T c13_h_x;
  real_T c13_i_x;
  real_T c13_j_x;
  real_T c13_k_x;
  real_T c13_l_x;
  real_T c13_m_x;
  real_T c13_n_x;
  real_T c13_o_x;
  real_T c13_p_x;
  real_T c13_q_x;
  real_T c13_r_x;
  real_T c13_s_x;
  real_T c13_t_x;
  real_T c13_u_x;
  real_T c13_v_x;
  real_T c13_w_x;
  real_T c13_x_x;
  real_T c13_y_x[16];
  int32_T c13_k;
  int32_T c13_b_k;
  sf_debug_symbol_scope_push_eml(0U, 68U, 68U, c13_c_debug_family_names,
    c13_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c13_A1, 0U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A2, 1U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A3, 2U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A4, 3U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A5, 4U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_A6, 5U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L1, 6U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L2, 7U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L3, 8U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L4, 9U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L5, 10U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L6, 11U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L7, 12U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L8, 13U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_L9, 14U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t2, 15U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t3, 16U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t4, 17U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t5, 18U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t6, 19U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t7, 20U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t8, 21U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t9, 22U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t10, 23U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t11, 24U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t12, 25U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t13, 26U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t14, 27U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t23, 28U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t15, 29U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t16, 30U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t17, 31U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t18, 32U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t19, 33U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t20, 34U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t21, 35U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t22, 36U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t24, 37U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t25, 38U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t26, 39U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t27, 40U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t34, 41U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t28, 42U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t29, 43U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t30, 44U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t31, 45U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t32, 46U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t36, 47U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t33, 48U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t35, 49U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t37, 50U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t38, 51U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t39, 52U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t40, 53U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t41, 54U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t42, 55U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t43, 56U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t44, 57U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t45, 58U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t47, 59U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t46, 60U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t48, 61U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_t49, 62U, c13_d_sf_marshallOut,
    c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargin, 63U,
    c13_d_sf_marshallOut, c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c13_nargout, 64U,
    c13_d_sf_marshallOut, c13_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_in1, 65U, c13_b_sf_marshallOut,
    c13_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_in2, 66U, c13_g_sf_marshallOut,
    c13_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c13_gst, 67U, c13_e_sf_marshallOut,
    c13_d_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 8);
  c13_A1 = c13_in2[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 9);
  c13_A2 = c13_in2[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 10);
  c13_A3 = c13_in2[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 11);
  c13_A4 = c13_in2[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 12);
  c13_A5 = c13_in2[4];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 13);
  c13_A6 = c13_in2[5];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 14);
  c13_L1 = c13_in1[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 15);
  c13_L2 = c13_in1[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 16);
  c13_L3 = c13_in1[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 17);
  c13_L4 = c13_in1[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 18);
  c13_L5 = c13_in1[4];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 19);
  c13_L6 = c13_in1[5];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 20);
  c13_L7 = c13_in1[6];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 21);
  c13_L8 = c13_in1[7];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 22);
  c13_L9 = c13_in1[8];
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 23);
  c13_x = c13_A1;
  c13_t2 = c13_x;
  c13_b_x = c13_t2;
  c13_t2 = c13_b_x;
  c13_t2 = muDoubleScalarCos(c13_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 24);
  c13_c_x = c13_A2;
  c13_t3 = c13_c_x;
  c13_d_x = c13_t3;
  c13_t3 = c13_d_x;
  c13_t3 = muDoubleScalarCos(c13_t3);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 25);
  c13_e_x = c13_A3;
  c13_t4 = c13_e_x;
  c13_f_x = c13_t4;
  c13_t4 = c13_f_x;
  c13_t4 = muDoubleScalarSin(c13_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 26);
  c13_g_x = c13_A3;
  c13_t5 = c13_g_x;
  c13_h_x = c13_t5;
  c13_t5 = c13_h_x;
  c13_t5 = muDoubleScalarCos(c13_t5);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 27);
  c13_i_x = c13_A2;
  c13_t6 = c13_i_x;
  c13_j_x = c13_t6;
  c13_t6 = c13_j_x;
  c13_t6 = muDoubleScalarSin(c13_t6);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 28);
  c13_k_x = c13_A4;
  c13_t7 = c13_k_x;
  c13_l_x = c13_t7;
  c13_t7 = c13_l_x;
  c13_t7 = muDoubleScalarSin(c13_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 29);
  c13_t8 = c13_t2 * c13_t3 * c13_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 30);
  c13_t9 = c13_t2 * c13_t5 * c13_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 31);
  c13_t10 = c13_t8 + c13_t9;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 32);
  c13_m_x = c13_A4;
  c13_t11 = c13_m_x;
  c13_n_x = c13_t11;
  c13_t11 = c13_n_x;
  c13_t11 = muDoubleScalarCos(c13_t11);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 33);
  c13_o_x = c13_A1;
  c13_t12 = c13_o_x;
  c13_p_x = c13_t12;
  c13_t12 = c13_p_x;
  c13_t12 = muDoubleScalarSin(c13_t12);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 34);
  c13_q_x = c13_A5;
  c13_t13 = c13_q_x;
  c13_r_x = c13_t13;
  c13_t13 = c13_r_x;
  c13_t13 = muDoubleScalarSin(c13_t13);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 35);
  c13_t14 = c13_t2 * c13_t3 * c13_t5;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 36);
  c13_t23 = c13_t2 * c13_t4 * c13_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 37);
  c13_t15 = c13_t14 - c13_t23;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 38);
  c13_s_x = c13_A5;
  c13_t16 = c13_s_x;
  c13_t_x = c13_t16;
  c13_t16 = c13_t_x;
  c13_t16 = muDoubleScalarCos(c13_t16);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 39);
  c13_t17 = c13_t10 * c13_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 40);
  c13_t18 = c13_t12 * c13_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 41);
  c13_t19 = c13_t17 + c13_t18;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 42);
  c13_u_x = c13_A6;
  c13_t20 = c13_u_x;
  c13_v_x = c13_t20;
  c13_t20 = c13_v_x;
  c13_t20 = muDoubleScalarSin(c13_t20);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 43);
  c13_t21 = c13_t11 * c13_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 44);
  c13_w_x = c13_A6;
  c13_t22 = c13_w_x;
  c13_x_x = c13_t22;
  c13_t22 = c13_x_x;
  c13_t22 = muDoubleScalarCos(c13_t22);
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 45);
  c13_t24 = c13_t13 * c13_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 46);
  c13_t25 = c13_t16 * c13_t19;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 47);
  c13_t26 = c13_t24 + c13_t25;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 48);
  c13_t27 = c13_t12 * c13_t3 * c13_t5;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 49);
  c13_t34 = c13_t12 * c13_t4 * c13_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 50);
  c13_t28 = c13_t27 - c13_t34;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 51);
  c13_t29 = c13_t12 * c13_t3 * c13_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 52);
  c13_t30 = c13_t12 * c13_t5 * c13_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 53);
  c13_t31 = c13_t29 + c13_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 54);
  c13_t32 = c13_t11 * c13_t31;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 55);
  c13_t36 = c13_t2 * c13_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 56);
  c13_t33 = c13_t32 - c13_t36;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 57);
  c13_t35 = c13_t13 * c13_t28;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 58);
  c13_t37 = c13_t16 * c13_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 59);
  c13_t38 = c13_t35 + c13_t37;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 60);
  c13_t39 = c13_t31 * c13_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 61);
  c13_t40 = c13_t11 * c13_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 62);
  c13_t41 = c13_t39 + c13_t40;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 63);
  c13_t42 = c13_t3 * c13_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 64);
  c13_t43 = c13_t5 * c13_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 65);
  c13_t44 = c13_t42 + c13_t43;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 66);
  c13_t45 = c13_t3 * c13_t5;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 67);
  c13_t47 = c13_t4 * c13_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 68);
  c13_t46 = c13_t45 - c13_t47;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 69);
  c13_t48 = c13_t13 * c13_t44;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 70);
  c13_t49 = c13_t48 - c13_t11 * c13_t16 * c13_t46;
  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, 71);
  c13_y_x[0] = c13_t15 * c13_t16 - c13_t13 * c13_t19;
  c13_y_x[1] = c13_t16 * c13_t28 - c13_t13 * c13_t33;
  c13_y_x[2] = -c13_t16 * c13_t44 - c13_t11 * c13_t13 * c13_t46;
  c13_y_x[3] = 0.0;
  c13_y_x[4] = c13_t20 * c13_t26 - c13_t22 * (c13_t21 - c13_t10 * c13_t7);
  c13_y_x[5] = c13_t20 * c13_t38 + c13_t22 * c13_t41;
  c13_y_x[6] = -c13_t20 * c13_t49 + c13_t22 * c13_t46 * c13_t7;
  c13_y_x[7] = 0.0;
  c13_y_x[8] = c13_t22 * c13_t26 + c13_t20 * (c13_t21 - c13_t10 * c13_t7);
  c13_y_x[9] = c13_t22 * c13_t38 - c13_t20 * c13_t41;
  c13_y_x[10] = -c13_t22 * c13_t49 - c13_t20 * c13_t46 * c13_t7;
  c13_y_x[11] = 0.0;
  c13_y_x[12] = ((((((((((((((((((((((((((((((c13_L2 * c13_t2 + c13_L3 * c13_t2 *
    c13_t6) - c13_L8 * c13_t11 * c13_t12 * c13_t22) + c13_L4 * c13_t2 * c13_t3 *
    c13_t4) + c13_L9 * c13_t11 * c13_t12 * c13_t20) + c13_L5 * c13_t2 * c13_t3 *
    c13_t5) - c13_L6 * c13_t12 * c13_t13 * c13_t7) - c13_L7 * c13_t12 * c13_t13 *
    c13_t7) + c13_L4 * c13_t2 * c13_t5 * c13_t6) - c13_L5 * c13_t2 * c13_t4 *
    c13_t6) + c13_L6 * c13_t16 * c13_t2 * c13_t3 * c13_t5) + c13_L7 * c13_t16 *
    c13_t2 * c13_t3 * c13_t5) - c13_L6 * c13_t16 * c13_t2 * c13_t4 * c13_t6) +
    c13_L8 * c13_t12 * c13_t16 * c13_t20 * c13_t7) - c13_L7 * c13_t16 * c13_t2 *
    c13_t4 * c13_t6) + c13_L9 * c13_t12 * c13_t16 * c13_t22 * c13_t7) - c13_L6 *
    c13_t11 * c13_t13 * c13_t2 * c13_t3 * c13_t4) - c13_L7 * c13_t11 * c13_t13 *
    c13_t2 * c13_t3 * c13_t4) + c13_L8 * c13_t13 * c13_t2 * c13_t20 * c13_t3 *
    c13_t5) - c13_L6 * c13_t11 * c13_t13 * c13_t2 * c13_t5 * c13_t6) - c13_L7 *
    c13_t11 * c13_t13 * c13_t2 * c13_t5 * c13_t6) + c13_L9 * c13_t13 * c13_t2 *
    c13_t22 * c13_t3 * c13_t5) - c13_L8 * c13_t13 * c13_t2 * c13_t20 * c13_t4 *
    c13_t6) - c13_L9 * c13_t13 * c13_t2 * c13_t22 * c13_t4 * c13_t6) + c13_L8 *
                       c13_t2 * c13_t22 * c13_t3 * c13_t4 * c13_t7) - c13_L9 *
                      c13_t2 * c13_t20 * c13_t3 * c13_t4 * c13_t7) + c13_L8 *
                     c13_t2 * c13_t22 * c13_t5 * c13_t6 * c13_t7) - c13_L9 *
                    c13_t2 * c13_t20 * c13_t5 * c13_t6 * c13_t7) + c13_L8 *
                   c13_t11 * c13_t16 * c13_t2 * c13_t20 * c13_t3 * c13_t4) +
                  c13_L9 * c13_t11 * c13_t16 * c13_t2 * c13_t22 * c13_t3 *
                  c13_t4) + c13_L8 * c13_t11 * c13_t16 * c13_t2 * c13_t20 *
                 c13_t5 * c13_t6) + c13_L9 * c13_t11 * c13_t16 * c13_t2 *
    c13_t22 * c13_t5 * c13_t6;
  c13_y_x[13] = ((((((((((((((((((((((((((((((c13_L2 * c13_t12 + c13_L3 *
    c13_t12 * c13_t6) + c13_L4 * c13_t12 * c13_t3 * c13_t4) + c13_L8 * c13_t11 *
    c13_t2 * c13_t22) + c13_L5 * c13_t12 * c13_t3 * c13_t5) - c13_L9 * c13_t11 *
    c13_t2 * c13_t20) + c13_L4 * c13_t12 * c13_t5 * c13_t6) - c13_L5 * c13_t12 *
    c13_t4 * c13_t6) + c13_L6 * c13_t13 * c13_t2 * c13_t7) + c13_L7 * c13_t13 *
    c13_t2 * c13_t7) + c13_L6 * c13_t12 * c13_t16 * c13_t3 * c13_t5) + c13_L7 *
    c13_t12 * c13_t16 * c13_t3 * c13_t5) - c13_L6 * c13_t12 * c13_t16 * c13_t4 *
    c13_t6) - c13_L7 * c13_t12 * c13_t16 * c13_t4 * c13_t6) - c13_L8 * c13_t16 *
    c13_t2 * c13_t20 * c13_t7) - c13_L9 * c13_t16 * c13_t2 * c13_t22 * c13_t7) -
    c13_L6 * c13_t11 * c13_t12 * c13_t13 * c13_t3 * c13_t4) - c13_L7 * c13_t11 *
    c13_t12 * c13_t13 * c13_t3 * c13_t4) + c13_L8 * c13_t12 * c13_t13 * c13_t20 *
    c13_t3 * c13_t5) - c13_L6 * c13_t11 * c13_t12 * c13_t13 * c13_t5 * c13_t6) -
    c13_L7 * c13_t11 * c13_t12 * c13_t13 * c13_t5 * c13_t6) + c13_L9 * c13_t12 *
    c13_t13 * c13_t22 * c13_t3 * c13_t5) - c13_L8 * c13_t12 * c13_t13 * c13_t20 *
    c13_t4 * c13_t6) - c13_L9 * c13_t12 * c13_t13 * c13_t22 * c13_t4 * c13_t6) +
                       c13_L8 * c13_t12 * c13_t22 * c13_t3 * c13_t4 * c13_t7) -
                      c13_L9 * c13_t12 * c13_t20 * c13_t3 * c13_t4 * c13_t7) +
                     c13_L8 * c13_t12 * c13_t22 * c13_t5 * c13_t6 * c13_t7) -
                    c13_L9 * c13_t12 * c13_t20 * c13_t5 * c13_t6 * c13_t7) +
                   c13_L8 * c13_t11 * c13_t12 * c13_t16 * c13_t20 * c13_t3 *
                   c13_t4) + c13_L9 * c13_t11 * c13_t12 * c13_t16 * c13_t22 *
                  c13_t3 * c13_t4) + c13_L8 * c13_t11 * c13_t12 * c13_t16 *
                 c13_t20 * c13_t5 * c13_t6) + c13_L9 * c13_t11 * c13_t12 *
    c13_t16 * c13_t22 * c13_t5 * c13_t6;
  c13_y_x[14] = ((((((((((((((((((((((((c13_L1 + c13_L3 * c13_t3) + c13_L4 *
    c13_t3 * c13_t5) - c13_L5 * c13_t3 * c13_t4) - c13_L4 * c13_t4 * c13_t6) -
    c13_L5 * c13_t5 * c13_t6) - c13_L6 * c13_t16 * c13_t3 * c13_t4) - c13_L7 *
    c13_t16 * c13_t3 * c13_t4) - c13_L6 * c13_t16 * c13_t5 * c13_t6) - c13_L7 *
    c13_t16 * c13_t5 * c13_t6) - c13_L6 * c13_t11 * c13_t13 * c13_t3 * c13_t5) -
    c13_L7 * c13_t11 * c13_t13 * c13_t3 * c13_t5) - c13_L8 * c13_t13 * c13_t20 *
    c13_t3 * c13_t4) + c13_L6 * c13_t11 * c13_t13 * c13_t4 * c13_t6) + c13_L7 *
    c13_t11 * c13_t13 * c13_t4 * c13_t6) - c13_L9 * c13_t13 * c13_t22 * c13_t3 *
    c13_t4) - c13_L8 * c13_t13 * c13_t20 * c13_t5 * c13_t6) - c13_L9 * c13_t13 *
                        c13_t22 * c13_t5 * c13_t6) + c13_L8 * c13_t22 * c13_t3 *
                       c13_t5 * c13_t7) - c13_L9 * c13_t20 * c13_t3 * c13_t5 *
                      c13_t7) - c13_L8 * c13_t22 * c13_t4 * c13_t6 * c13_t7) +
                    c13_L9 * c13_t20 * c13_t4 * c13_t6 * c13_t7) + c13_L8 *
                   c13_t11 * c13_t16 * c13_t20 * c13_t3 * c13_t5) + c13_L9 *
                  c13_t11 * c13_t16 * c13_t22 * c13_t3 * c13_t5) - c13_L8 *
                 c13_t11 * c13_t16 * c13_t20 * c13_t4 * c13_t6) - c13_L9 *
    c13_t11 * c13_t16 * c13_t22 * c13_t4 * c13_t6;
  c13_y_x[15] = 1.0;
  c13_b_eml_int_forloop_overflow_check(chartInstance);
  for (c13_k = 1; c13_k < 17; c13_k++) {
    c13_b_k = c13_k;
    c13_gst[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c13_b_k), 1, 16, 1, 0) - 1] = c13_y_x[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c13_b_k), 1, 16, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c13_sfEvent, -71);
  sf_debug_symbol_scope_pop();
}

static void c13_b_eml_int_forloop_overflow_check
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static const mxArray *c13_h_sf_marshallOut(void *chartInstanceVoid, void
  *c13_inData)
{
  const mxArray *c13_mxArrayOutData = NULL;
  int32_T c13_u;
  const mxArray *c13_y = NULL;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_mxArrayOutData = NULL;
  c13_u = *(int32_T *)c13_inData;
  c13_y = NULL;
  sf_mex_assign(&c13_y, sf_mex_create("y", &c13_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c13_mxArrayOutData, c13_y, FALSE);
  return c13_mxArrayOutData;
}

static int32_T c13_i_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  int32_T c13_y;
  int32_T c13_i67;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_i67, 1, 6, 0U, 0, 0U, 0);
  c13_y = c13_i67;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void c13_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c13_mxArrayInData, const char_T *c13_varName, void *c13_outData)
{
  const mxArray *c13_b_sfEvent;
  const char_T *c13_identifier;
  emlrtMsgIdentifier c13_thisId;
  int32_T c13_y;
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c13_b_sfEvent = sf_mex_dup(c13_mxArrayInData);
  c13_identifier = c13_varName;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c13_b_sfEvent),
    &c13_thisId);
  sf_mex_destroy(&c13_b_sfEvent);
  *(int32_T *)c13_outData = c13_y;
  sf_mex_destroy(&c13_mxArrayInData);
}

static uint8_T c13_j_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_b_is_active_c13_CtrPlatform_RobustControl, const char_T *c13_identifier)
{
  uint8_T c13_y;
  emlrtMsgIdentifier c13_thisId;
  c13_thisId.fIdentifier = c13_identifier;
  c13_thisId.fParent = NULL;
  c13_y = c13_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c13_b_is_active_c13_CtrPlatform_RobustControl), &c13_thisId);
  sf_mex_destroy(&c13_b_is_active_c13_CtrPlatform_RobustControl);
  return c13_y;
}

static uint8_T c13_k_emlrt_marshallIn
  (SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c13_u, const emlrtMsgIdentifier *c13_parentId)
{
  uint8_T c13_y;
  uint8_T c13_u0;
  sf_mex_import(c13_parentId, sf_mex_dup(c13_u), &c13_u0, 1, 3, 0U, 0, 0U, 0);
  c13_y = c13_u0;
  sf_mex_destroy(&c13_u);
  return c13_y;
}

static void init_dsm_address_info(SFc13_CtrPlatform_RobustControlInstanceStruct *
  chartInstance)
{
}

/* SFunction Glue Code */
void sf_c13_CtrPlatform_RobustControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1623359201U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4172782709U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2733254886U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2349113814U);
}

mxArray *sf_c13_CtrPlatform_RobustControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("H4TB6i7X12dUdqLTZuJJLD");
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

static const mxArray *sf_get_sim_state_info_c13_CtrPlatform_RobustControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"EndVel\",},{M[8],M[0],T\"is_active_c13_CtrPlatform_RobustControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c13_CtrPlatform_RobustControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
    chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_RobustControlMachineNumber_,
           13,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           2,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_CtrPlatform_RobustControlMachineNumber_,chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_CtrPlatform_RobustControlMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_CtrPlatform_RobustControlMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Theta");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Omega");
          _SFD_SET_DATA_PROPS(2,2,0,1,"EndVel");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,176);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"spat_Jacobian",0,-1,2102);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"fwd_kin",0,-1,3253);
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
            1.0,0,0,(MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_sf_marshallOut,(MexInFcnForType)
            c13_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c13_b_sf_marshallOut,(MexInFcnForType)
            c13_b_sf_marshallIn);
        }

        {
          real_T (*c13_Theta)[6];
          real_T (*c13_Omega)[6];
          real_T (*c13_EndVel)[3];
          c13_EndVel = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
          c13_Omega = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c13_Theta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c13_Theta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c13_Omega);
          _SFD_SET_DATA_VALUE_PTR(2U, *c13_EndVel);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c13_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_CtrPlatform_RobustControlMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "ukBCCahs2ri3FUbXSa8vh";
}

static void sf_opaque_initialize_c13_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc13_CtrPlatform_RobustControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
  initialize_c13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c13_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  enable_c13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c13_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  disable_c13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c13_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  sf_c13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c13_CtrPlatform_RobustControl
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_CtrPlatform_RobustControl();/* state var info */
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

extern void sf_internal_set_sim_state_c13_CtrPlatform_RobustControl(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c13_CtrPlatform_RobustControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c13_CtrPlatform_RobustControl
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c13_CtrPlatform_RobustControl(S);
}

static void sf_opaque_set_sim_state_c13_CtrPlatform_RobustControl(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c13_CtrPlatform_RobustControl(S, st);
}

static void sf_opaque_terminate_c13_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc13_CtrPlatform_RobustControlInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c13_CtrPlatform_RobustControl
      ((SFc13_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_RobustControl_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc13_CtrPlatform_RobustControl
    ((SFc13_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c13_CtrPlatform_RobustControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c13_CtrPlatform_RobustControl
      ((SFc13_CtrPlatform_RobustControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c13_CtrPlatform_RobustControl(SimStruct *S)
{
  /* Actual parameters from chart:
     L
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CtrPlatform_RobustControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      13);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,13,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,13,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,13,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,13,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,13);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3097484994U));
  ssSetChecksum1(S,(731180150U));
  ssSetChecksum2(S,(3151137063U));
  ssSetChecksum3(S,(2459141611U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c13_CtrPlatform_RobustControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c13_CtrPlatform_RobustControl(SimStruct *S)
{
  SFc13_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc13_CtrPlatform_RobustControlInstanceStruct *)malloc(sizeof
    (SFc13_CtrPlatform_RobustControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc13_CtrPlatform_RobustControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c13_CtrPlatform_RobustControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c13_CtrPlatform_RobustControl;
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

void c13_CtrPlatform_RobustControl_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c13_CtrPlatform_RobustControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c13_CtrPlatform_RobustControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c13_CtrPlatform_RobustControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c13_CtrPlatform_RobustControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
