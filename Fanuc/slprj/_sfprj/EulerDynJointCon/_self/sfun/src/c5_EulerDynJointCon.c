/* Include files */

#include "blascompat32.h"
#include "EulerDynJointCon_sfun.h"
#include "c5_EulerDynJointCon.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EulerDynJointCon_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c5_debug_family_names[7] = { "L", "Ma", "nargin", "nargout",
  "EnTheta", "Cen", "N" };

static const char *c5_b_debug_family_names[108] = { "A2", "A3", "A4", "A5", "A6",
  "Cx2", "Cx3", "Cx4", "Cx5", "Cx6", "Cy4", "Cy5", "Cy6", "Cz2", "Cz3", "Cz4",
  "Cz5", "Cz6", "L1", "L2", "L3", "L4", "L5", "Ma2", "Ma3", "Ma4", "Ma5", "Ma6",
  "t4855", "t4856", "t4857", "t4858", "t4859", "t4860", "t4861", "t4862",
  "t4869", "t4863", "t4864", "t4865", "t4866", "t4867", "t4868", "t4870",
  "t4871", "t4875", "t4872", "t4873", "t4874", "t4876", "t4877", "t4878",
  "t4879", "t4880", "t4881", "t4882", "t4883", "t4889", "t4884", "t4885",
  "t4886", "t4887", "t4888", "t4890", "t4891", "t4892", "t4893", "t4894",
  "t4895", "t4899", "t4896", "t4897", "t4898", "t4900", "t4901", "t4902",
  "t4912", "t4903", "t4904", "t4905", "t4906", "t4907", "t4908", "t4909",
  "t4910", "t4911", "t4913", "t4914", "t4915", "t4916", "t4917", "t4918",
  "t4920", "t4919", "t4921", "t4922", "t4923", "t4924", "t4925", "t4926",
  "t4927", "nargin", "nargout", "in1", "in2", "in3", "in4", "N_d_" };

/* Function Declarations */
static void initialize_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance);
static void initialize_params_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance);
static void enable_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance);
static void disable_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance);
static void set_sim_state_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance);
static void sf_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static void c5_N_d(SFc5_EulerDynJointConInstanceStruct *chartInstance, real_T
                   c5_in1[9], real_T c5_in2[6], real_T c5_in3[18], real_T
                   c5_in4[6], real_T c5_N_d_[6]);
static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_e_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[21]);
static const mxArray *c5_f_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_emlrt_marshallIn(SFc5_EulerDynJointConInstanceStruct
  *chartInstance, const mxArray *c5_N, const char_T *c5_name, real_T c5_y[6]);
static uint8_T c5_b_emlrt_marshallIn(SFc5_EulerDynJointConInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_EulerDynJointCon, const
  char_T *c5_name);
static void init_dsm_address_info(SFc5_EulerDynJointConInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_EulerDynJointCon = 0U;
}

static void initialize_params_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance)
{
  real_T c5_dv0[9];
  int32_T c5_i0;
  real_T c5_dv1[18];
  int32_T c5_i1;
  real_T c5_dv2[6];
  int32_T c5_i2;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 1, 0), c5_dv0, 0, 0,
                0U, 1, 0U, 2, 1, 9);
  for (c5_i0 = 0; c5_i0 < 9; c5_i0 = c5_i0 + 1) {
    chartInstance->c5_L[c5_i0] = c5_dv0[c5_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Cen' in the parent workspace.\n");
  sf_mex_import("Cen", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c5_dv1, 0,
                0, 0U, 1, 0U, 2, 1, 18);
  for (c5_i1 = 0; c5_i1 < 18; c5_i1 = c5_i1 + 1) {
    chartInstance->c5_Cen[c5_i1] = c5_dv1[c5_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ma' in the parent workspace.\n");
  sf_mex_import("Ma", sf_mex_get_sfun_param(chartInstance->S, 2, 0), c5_dv2, 0,
                0, 0U, 1, 0U, 2, 1, 6);
  for (c5_i2 = 0; c5_i2 < 6; c5_i2 = c5_i2 + 1) {
    chartInstance->c5_Ma[c5_i2] = c5_dv2[c5_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance)
{
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  int32_T c5_i3;
  real_T c5_hoistedGlobal[6];
  int32_T c5_i4;
  real_T c5_u[6];
  const mxArray *c5_b_y = NULL;
  uint8_T c5_b_hoistedGlobal;
  uint8_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T (*c5_N)[6];
  c5_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(2));
  for (c5_i3 = 0; c5_i3 < 6; c5_i3 = c5_i3 + 1) {
    c5_hoistedGlobal[c5_i3] = (*c5_N)[c5_i3];
  }

  for (c5_i4 = 0; c5_i4 < 6; c5_i4 = c5_i4 + 1) {
    c5_u[c5_i4] = c5_hoistedGlobal[c5_i4];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = chartInstance->c5_is_active_c5_EulerDynJointCon;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv3[6];
  int32_T c5_i5;
  real_T (*c5_N)[6];
  c5_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)), "N",
                      c5_dv3);
  for (c5_i5 = 0; c5_i5 < 6; c5_i5 = c5_i5 + 1) {
    (*c5_N)[c5_i5] = c5_dv3[c5_i5];
  }

  chartInstance->c5_is_active_c5_EulerDynJointCon = c5_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
     "is_active_c5_EulerDynJointCon");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_EulerDynJointCon(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance)
{
}

static void sf_c5_EulerDynJointCon(SFc5_EulerDynJointConInstanceStruct
  *chartInstance)
{
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_previousEvent;
  int32_T c5_i11;
  real_T c5_hoistedGlobal[6];
  int32_T c5_i12;
  real_T c5_b_hoistedGlobal[18];
  int32_T c5_i13;
  real_T c5_EnTheta[6];
  int32_T c5_i14;
  real_T c5_b_Cen[18];
  uint32_T c5_debug_family_var_map[7];
  static const char *c5_sv0[7] = { "L", "Ma", "nargin", "nargout", "EnTheta",
    "Cen", "N" };

  real_T c5_b_L[9] = { 566.0, 150.0, 870.0, 170.0, 1016.0, 154.0, 20.0, 0.0, 0.0
  };

  real_T c5_b_Ma[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  real_T c5_nargin = 4.0;
  real_T c5_nargout = 1.0;
  real_T c5_N[6];
  int32_T c5_i15;
  int32_T c5_i16;
  static real_T c5_dv4[9] = { 0.566, 0.15, 0.87, 0.17, 1.016, 0.154, 0.02, 0.0,
    0.0 };

  real_T c5_dv5[9];
  int32_T c5_i17;
  real_T c5_b_EnTheta[6];
  int32_T c5_i18;
  real_T c5_c_Cen[18];
  int32_T c5_i19;
  static real_T c5_dv6[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  real_T c5_dv7[6];
  real_T c5_dv8[6];
  int32_T c5_i20;
  int32_T c5_i21;
  real_T (*c5_b_N)[6];
  real_T (*c5_c_EnTheta)[6];
  c5_b_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_c_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4);
  for (c5_i6 = 0; c5_i6 < 6; c5_i6 = c5_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_c_EnTheta)[c5_i6], 0U);
  }

  for (c5_i7 = 0; c5_i7 < 6; c5_i7 = c5_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c5_b_N)[c5_i7], 1U);
  }

  for (c5_i8 = 0; c5_i8 < 9; c5_i8 = c5_i8 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_L[c5_i8], 2U);
  }

  for (c5_i9 = 0; c5_i9 < 18; c5_i9 = c5_i9 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_Cen[c5_i9], 3U);
  }

  for (c5_i10 = 0; c5_i10 < 6; c5_i10 = c5_i10 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c5_Ma[c5_i10], 4U);
  }

  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4);
  for (c5_i11 = 0; c5_i11 < 6; c5_i11 = c5_i11 + 1) {
    c5_hoistedGlobal[c5_i11] = (*c5_c_EnTheta)[c5_i11];
  }

  for (c5_i12 = 0; c5_i12 < 18; c5_i12 = c5_i12 + 1) {
    c5_b_hoistedGlobal[c5_i12] = chartInstance->c5_Cen[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 6; c5_i13 = c5_i13 + 1) {
    c5_EnTheta[c5_i13] = c5_hoistedGlobal[c5_i13];
  }

  for (c5_i14 = 0; c5_i14 < 18; c5_i14 = c5_i14 + 1) {
    c5_b_Cen[c5_i14] = c5_b_hoistedGlobal[c5_i14];
  }

  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c5_sv0, c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c5_b_L, c5_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c5_b_Ma, c5_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c5_nargin, c5_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c5_nargout, c5_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c5_EnTheta, c5_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c5_b_Cen, c5_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c5_N, c5_sf_marshall, 6U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c5_i15 = 0; c5_i15 < 6; c5_i15 = c5_i15 + 1) {
    c5_N[c5_i15] = 0.0;
  }

  _SFD_EML_CALL(0, 4);
  for (c5_i16 = 0; c5_i16 < 9; c5_i16 = c5_i16 + 1) {
    c5_dv5[c5_i16] = c5_dv4[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 6; c5_i17 = c5_i17 + 1) {
    c5_b_EnTheta[c5_i17] = c5_EnTheta[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 18; c5_i18 = c5_i18 + 1) {
    c5_c_Cen[c5_i18] = c5_b_Cen[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 6; c5_i19 = c5_i19 + 1) {
    c5_dv7[c5_i19] = c5_dv6[c5_i19];
  }

  c5_N_d(chartInstance, c5_dv5, c5_b_EnTheta, c5_c_Cen, c5_dv7, c5_dv8);
  for (c5_i20 = 0; c5_i20 < 6; c5_i20 = c5_i20 + 1) {
    c5_N[c5_i20] = c5_dv8[c5_i20];
  }

  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  for (c5_i21 = 0; c5_i21 < 6; c5_i21 = c5_i21 + 1) {
    (*c5_b_N)[c5_i21] = c5_N[c5_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_EulerDynJointConMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c5_EulerDynJointCon
  (SFc5_EulerDynJointConInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/N_d.m"));
}

static void c5_N_d(SFc5_EulerDynJointConInstanceStruct *chartInstance, real_T
                   c5_in1[9], real_T c5_in2[6], real_T c5_in3[18], real_T
                   c5_in4[6], real_T c5_N_d_[6])
{
  uint32_T c5_debug_family_var_map[108];
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
  real_T c5_t4855;
  real_T c5_t4856;
  real_T c5_t4857;
  real_T c5_t4858;
  real_T c5_t4859;
  real_T c5_t4860;
  real_T c5_t4861;
  real_T c5_t4862;
  real_T c5_t4869;
  real_T c5_t4863;
  real_T c5_t4864;
  real_T c5_t4865;
  real_T c5_t4866;
  real_T c5_t4867;
  real_T c5_t4868;
  real_T c5_t4870;
  real_T c5_t4871;
  real_T c5_t4875;
  real_T c5_t4872;
  real_T c5_t4873;
  real_T c5_t4874;
  real_T c5_t4876;
  real_T c5_t4877;
  real_T c5_t4878;
  real_T c5_t4879;
  real_T c5_t4880;
  real_T c5_t4881;
  real_T c5_t4882;
  real_T c5_t4883;
  real_T c5_t4889;
  real_T c5_t4884;
  real_T c5_t4885;
  real_T c5_t4886;
  real_T c5_t4887;
  real_T c5_t4888;
  real_T c5_t4890;
  real_T c5_t4891;
  real_T c5_t4892;
  real_T c5_t4893;
  real_T c5_t4894;
  real_T c5_t4895;
  real_T c5_t4899;
  real_T c5_t4896;
  real_T c5_t4897;
  real_T c5_t4898;
  real_T c5_t4900;
  real_T c5_t4901;
  real_T c5_t4902;
  real_T c5_t4912;
  real_T c5_t4903;
  real_T c5_t4904;
  real_T c5_t4905;
  real_T c5_t4906;
  real_T c5_t4907;
  real_T c5_t4908;
  real_T c5_t4909;
  real_T c5_t4910;
  real_T c5_t4911;
  real_T c5_t4913;
  real_T c5_t4914;
  real_T c5_t4915;
  real_T c5_t4916;
  real_T c5_t4917;
  real_T c5_t4918;
  real_T c5_t4920;
  real_T c5_t4919;
  real_T c5_t4921;
  real_T c5_t4922;
  real_T c5_t4923;
  real_T c5_t4924;
  real_T c5_t4925;
  real_T c5_t4926;
  real_T c5_t4927;
  real_T c5_nargin = 4.0;
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
  sf_debug_symbol_scope_push_eml(0U, 108U, 108U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_A2, c5_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c5_A3, c5_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c5_A4, c5_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c5_A5, c5_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c5_A6, c5_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c5_Cx2, c5_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c5_Cx3, c5_c_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c5_Cx4, c5_c_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c5_Cx5, c5_c_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c5_Cx6, c5_c_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c5_Cy4, c5_c_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c5_Cy5, c5_c_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c5_Cy6, c5_c_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c5_Cz2, c5_c_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c5_Cz3, c5_c_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c5_Cz4, c5_c_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c5_Cz5, c5_c_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c5_Cz6, c5_c_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c5_L1, c5_c_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c5_L2, c5_c_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c5_L3, c5_c_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c5_L4, c5_c_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c5_L5, c5_c_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c5_Ma2, c5_c_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c5_Ma3, c5_c_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c5_Ma4, c5_c_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c5_Ma5, c5_c_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c5_Ma6, c5_c_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c5_t4855, c5_c_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c5_t4856, c5_c_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c5_t4857, c5_c_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c5_t4858, c5_c_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c5_t4859, c5_c_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c5_t4860, c5_c_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c5_t4861, c5_c_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c5_t4862, c5_c_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c5_t4869, c5_c_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c5_t4863, c5_c_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c5_t4864, c5_c_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c5_t4865, c5_c_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c5_t4866, c5_c_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c5_t4867, c5_c_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c5_t4868, c5_c_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c5_t4870, c5_c_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c5_t4871, c5_c_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c5_t4875, c5_c_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c5_t4872, c5_c_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c5_t4873, c5_c_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c5_t4874, c5_c_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c5_t4876, c5_c_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c5_t4877, c5_c_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c5_t4878, c5_c_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c5_t4879, c5_c_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c5_t4880, c5_c_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c5_t4881, c5_c_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c5_t4882, c5_c_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c5_t4883, c5_c_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c5_t4889, c5_c_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c5_t4884, c5_c_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c5_t4885, c5_c_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c5_t4886, c5_c_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c5_t4887, c5_c_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c5_t4888, c5_c_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c5_t4890, c5_c_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c5_t4891, c5_c_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(&c5_t4892, c5_c_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c5_t4893, c5_c_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(&c5_t4894, c5_c_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(&c5_t4895, c5_c_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(&c5_t4899, c5_c_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(&c5_t4896, c5_c_sf_marshall, 70U);
  sf_debug_symbol_scope_add_eml(&c5_t4897, c5_c_sf_marshall, 71U);
  sf_debug_symbol_scope_add_eml(&c5_t4898, c5_c_sf_marshall, 72U);
  sf_debug_symbol_scope_add_eml(&c5_t4900, c5_c_sf_marshall, 73U);
  sf_debug_symbol_scope_add_eml(&c5_t4901, c5_c_sf_marshall, 74U);
  sf_debug_symbol_scope_add_eml(&c5_t4902, c5_c_sf_marshall, 75U);
  sf_debug_symbol_scope_add_eml(&c5_t4912, c5_c_sf_marshall, 76U);
  sf_debug_symbol_scope_add_eml(&c5_t4903, c5_c_sf_marshall, 77U);
  sf_debug_symbol_scope_add_eml(&c5_t4904, c5_c_sf_marshall, 78U);
  sf_debug_symbol_scope_add_eml(&c5_t4905, c5_c_sf_marshall, 79U);
  sf_debug_symbol_scope_add_eml(&c5_t4906, c5_c_sf_marshall, 80U);
  sf_debug_symbol_scope_add_eml(&c5_t4907, c5_c_sf_marshall, 81U);
  sf_debug_symbol_scope_add_eml(&c5_t4908, c5_c_sf_marshall, 82U);
  sf_debug_symbol_scope_add_eml(&c5_t4909, c5_c_sf_marshall, 83U);
  sf_debug_symbol_scope_add_eml(&c5_t4910, c5_c_sf_marshall, 84U);
  sf_debug_symbol_scope_add_eml(&c5_t4911, c5_c_sf_marshall, 85U);
  sf_debug_symbol_scope_add_eml(&c5_t4913, c5_c_sf_marshall, 86U);
  sf_debug_symbol_scope_add_eml(&c5_t4914, c5_c_sf_marshall, 87U);
  sf_debug_symbol_scope_add_eml(&c5_t4915, c5_c_sf_marshall, 88U);
  sf_debug_symbol_scope_add_eml(&c5_t4916, c5_c_sf_marshall, 89U);
  sf_debug_symbol_scope_add_eml(&c5_t4917, c5_c_sf_marshall, 90U);
  sf_debug_symbol_scope_add_eml(&c5_t4918, c5_c_sf_marshall, 91U);
  sf_debug_symbol_scope_add_eml(&c5_t4920, c5_c_sf_marshall, 92U);
  sf_debug_symbol_scope_add_eml(&c5_t4919, c5_c_sf_marshall, 93U);
  sf_debug_symbol_scope_add_eml(&c5_t4921, c5_c_sf_marshall, 94U);
  sf_debug_symbol_scope_add_eml(&c5_t4922, c5_c_sf_marshall, 95U);
  sf_debug_symbol_scope_add_eml(&c5_t4923, c5_c_sf_marshall, 96U);
  sf_debug_symbol_scope_add_eml(&c5_t4924, c5_c_sf_marshall, 97U);
  sf_debug_symbol_scope_add_eml(&c5_t4925, c5_c_sf_marshall, 98U);
  sf_debug_symbol_scope_add_eml(&c5_t4926, c5_c_sf_marshall, 99U);
  sf_debug_symbol_scope_add_eml(&c5_t4927, c5_c_sf_marshall, 100U);
  sf_debug_symbol_scope_add_eml(&c5_nargin, c5_c_sf_marshall, 101U);
  sf_debug_symbol_scope_add_eml(&c5_nargout, c5_c_sf_marshall, 102U);
  sf_debug_symbol_scope_add_eml(c5_in1, c5_e_sf_marshall, 103U);
  sf_debug_symbol_scope_add_eml(c5_in2, c5_d_sf_marshall, 104U);
  sf_debug_symbol_scope_add_eml(c5_in3, c5_b_sf_marshall, 105U);
  sf_debug_symbol_scope_add_eml(c5_in4, c5_d_sf_marshall, 106U);
  sf_debug_symbol_scope_add_eml(c5_N_d_, c5_sf_marshall, 107U);
  CV_SCRIPT_FCN(0, 0);

  /* N_D */
  /*     N_D_ = N_D(IN1,IN2,IN3,IN4) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-May-2013 00:27:25 */
  _SFD_SCRIPT_CALL(0, 8);
  c5_A2 = c5_in2[1];
  _SFD_SCRIPT_CALL(0, 9);
  c5_A3 = c5_in2[2];
  _SFD_SCRIPT_CALL(0, 10);
  c5_A4 = c5_in2[3];
  _SFD_SCRIPT_CALL(0, 11);
  c5_A5 = c5_in2[4];
  _SFD_SCRIPT_CALL(0, 12);
  c5_A6 = c5_in2[5];
  _SFD_SCRIPT_CALL(0, 13);
  c5_Cx2 = c5_in3[1];
  _SFD_SCRIPT_CALL(0, 14);
  c5_Cx3 = c5_in3[2];
  _SFD_SCRIPT_CALL(0, 15);
  c5_Cx4 = c5_in3[3];
  _SFD_SCRIPT_CALL(0, 16);
  c5_Cx5 = c5_in3[4];
  _SFD_SCRIPT_CALL(0, 17);
  c5_Cx6 = c5_in3[5];
  _SFD_SCRIPT_CALL(0, 18);
  c5_Cy4 = c5_in3[9];
  _SFD_SCRIPT_CALL(0, 19);
  c5_Cy5 = c5_in3[10];
  _SFD_SCRIPT_CALL(0, 20);
  c5_Cy6 = c5_in3[11];
  _SFD_SCRIPT_CALL(0, 21);
  c5_Cz2 = c5_in3[13];
  _SFD_SCRIPT_CALL(0, 22);
  c5_Cz3 = c5_in3[14];
  _SFD_SCRIPT_CALL(0, 23);
  c5_Cz4 = c5_in3[15];
  _SFD_SCRIPT_CALL(0, 24);
  c5_Cz5 = c5_in3[16];
  _SFD_SCRIPT_CALL(0, 25);
  c5_Cz6 = c5_in3[17];
  _SFD_SCRIPT_CALL(0, 26);
  c5_L1 = c5_in1[0];
  _SFD_SCRIPT_CALL(0, 27);
  c5_L2 = c5_in1[1];
  _SFD_SCRIPT_CALL(0, 28);
  c5_L3 = c5_in1[2];
  _SFD_SCRIPT_CALL(0, 29);
  c5_L4 = c5_in1[3];
  _SFD_SCRIPT_CALL(0, 30);
  c5_L5 = c5_in1[4];
  _SFD_SCRIPT_CALL(0, 31);
  c5_Ma2 = c5_in4[1];
  _SFD_SCRIPT_CALL(0, 32);
  c5_Ma3 = c5_in4[2];
  _SFD_SCRIPT_CALL(0, 33);
  c5_Ma4 = c5_in4[3];
  _SFD_SCRIPT_CALL(0, 34);
  c5_Ma5 = c5_in4[4];
  _SFD_SCRIPT_CALL(0, 35);
  c5_Ma6 = c5_in4[5];
  _SFD_SCRIPT_CALL(0, 36);
  c5_x = c5_A3;
  c5_t4855 = c5_x;
  c5_b_x = c5_t4855;
  c5_t4855 = c5_b_x;
  c5_t4855 = muDoubleScalarCos(c5_t4855);
  _SFD_SCRIPT_CALL(0, 37);
  c5_t4856 = c5_t4855 - 1.0;
  _SFD_SCRIPT_CALL(0, 38);
  c5_t4857 = c5_L1 + c5_L3;
  _SFD_SCRIPT_CALL(0, 39);
  c5_c_x = c5_A3;
  c5_t4858 = c5_c_x;
  c5_d_x = c5_t4858;
  c5_t4858 = c5_d_x;
  c5_t4858 = muDoubleScalarSin(c5_t4858);
  _SFD_SCRIPT_CALL(0, 40);
  c5_e_x = c5_A2;
  c5_t4859 = c5_e_x;
  c5_f_x = c5_t4859;
  c5_t4859 = c5_f_x;
  c5_t4859 = muDoubleScalarCos(c5_t4859);
  _SFD_SCRIPT_CALL(0, 41);
  c5_g_x = c5_A2;
  c5_t4860 = c5_g_x;
  c5_h_x = c5_t4860;
  c5_t4860 = c5_h_x;
  c5_t4860 = muDoubleScalarSin(c5_t4860);
  _SFD_SCRIPT_CALL(0, 42);
  c5_i_x = c5_A5;
  c5_t4861 = c5_i_x;
  c5_j_x = c5_t4861;
  c5_t4861 = c5_j_x;
  c5_t4861 = muDoubleScalarSin(c5_t4861);
  _SFD_SCRIPT_CALL(0, 43);
  c5_t4862 = c5_t4860 * c5_t4858;
  _SFD_SCRIPT_CALL(0, 44);
  c5_t4869 = c5_t4855 * c5_t4859;
  _SFD_SCRIPT_CALL(0, 45);
  c5_t4863 = c5_t4862 - c5_t4869;
  _SFD_SCRIPT_CALL(0, 46);
  c5_k_x = c5_A5;
  c5_t4864 = c5_k_x;
  c5_l_x = c5_t4864;
  c5_t4864 = c5_l_x;
  c5_t4864 = muDoubleScalarCos(c5_t4864);
  _SFD_SCRIPT_CALL(0, 47);
  c5_t4865 = c5_t4858 * c5_t4859;
  _SFD_SCRIPT_CALL(0, 48);
  c5_t4866 = c5_t4860 * c5_t4855;
  _SFD_SCRIPT_CALL(0, 49);
  c5_t4867 = c5_t4865 + c5_t4866;
  _SFD_SCRIPT_CALL(0, 50);
  c5_m_x = c5_A6;
  c5_t4868 = c5_m_x;
  c5_n_x = c5_t4868;
  c5_t4868 = c5_n_x;
  c5_t4868 = muDoubleScalarCos(c5_t4868);
  _SFD_SCRIPT_CALL(0, 51);
  c5_t4870 = c5_t4861 * c5_t4863;
  _SFD_SCRIPT_CALL(0, 52);
  c5_o_x = c5_A4;
  c5_t4871 = c5_o_x;
  c5_p_x = c5_t4871;
  c5_t4871 = c5_p_x;
  c5_t4871 = muDoubleScalarCos(c5_t4871);
  _SFD_SCRIPT_CALL(0, 53);
  c5_t4875 = c5_t4871 * c5_t4864 * c5_t4867;
  _SFD_SCRIPT_CALL(0, 54);
  c5_t4872 = c5_t4870 - c5_t4875;
  _SFD_SCRIPT_CALL(0, 55);
  c5_q_x = c5_A4;
  c5_t4873 = c5_q_x;
  c5_r_x = c5_t4873;
  c5_t4873 = c5_r_x;
  c5_t4873 = muDoubleScalarSin(c5_t4873);
  _SFD_SCRIPT_CALL(0, 56);
  c5_s_x = c5_A6;
  c5_t4874 = c5_s_x;
  c5_t_x = c5_t4874;
  c5_t4874 = c5_t_x;
  c5_t4874 = muDoubleScalarSin(c5_t4874);
  _SFD_SCRIPT_CALL(0, 57);
  c5_t4876 = (c5_L1 + c5_L3) + c5_L4;
  _SFD_SCRIPT_CALL(0, 58);
  c5_t4877 = c5_L2 + c5_L5;
  _SFD_SCRIPT_CALL(0, 59);
  c5_t4878 = c5_t4864 - 1.0;
  _SFD_SCRIPT_CALL(0, 60);
  c5_t4879 = c5_t4857 * c5_t4858;
  _SFD_SCRIPT_CALL(0, 61);
  c5_t4880 = c5_L2 * c5_t4856;
  _SFD_SCRIPT_CALL(0, 62);
  c5_t4881 = c5_t4880 + c5_t4879;
  _SFD_SCRIPT_CALL(0, 63);
  c5_t4882 = c5_t4881 * c5_t4859;
  _SFD_SCRIPT_CALL(0, 64);
  c5_t4883 = c5_L2 * c5_t4858;
  _SFD_SCRIPT_CALL(0, 65);
  c5_t4889 = c5_t4856 * c5_t4857;
  _SFD_SCRIPT_CALL(0, 66);
  c5_t4884 = c5_t4883 - c5_t4889;
  _SFD_SCRIPT_CALL(0, 67);
  c5_t4885 = c5_L2 * c5_t4859;
  _SFD_SCRIPT_CALL(0, 68);
  c5_t4886 = c5_L1 * c5_t4860;
  _SFD_SCRIPT_CALL(0, 69);
  c5_t4887 = c5_t4871 - 1.0;
  _SFD_SCRIPT_CALL(0, 70);
  c5_t4888 = c5_t4867 * c5_t4876 * c5_t4887;
  _SFD_SCRIPT_CALL(0, 71);
  c5_t4890 = c5_t4861 * c5_t4876;
  _SFD_SCRIPT_CALL(0, 72);
  c5_t4891 = c5_t4877 * c5_t4878;
  _SFD_SCRIPT_CALL(0, 73);
  c5_t4892 = c5_t4890 + c5_t4891;
  _SFD_SCRIPT_CALL(0, 74);
  c5_t4893 = c5_t4863 * c5_t4864;
  _SFD_SCRIPT_CALL(0, 75);
  c5_t4894 = c5_t4861 * c5_t4871 * c5_t4867;
  _SFD_SCRIPT_CALL(0, 76);
  c5_t4895 = c5_t4861 * c5_t4877;
  _SFD_SCRIPT_CALL(0, 77);
  c5_t4899 = c5_t4876 * c5_t4878;
  _SFD_SCRIPT_CALL(0, 78);
  c5_t4896 = c5_t4895 - c5_t4899;
  _SFD_SCRIPT_CALL(0, 79);
  c5_t4897 = c5_t4893 + c5_t4894;
  _SFD_SCRIPT_CALL(0, 80);
  c5_t4898 = c5_Cx5 * c5_t4897;
  _SFD_SCRIPT_CALL(0, 81);
  c5_t4900 = c5_L2 * c5_t4855;
  _SFD_SCRIPT_CALL(0, 82);
  c5_t4901 = c5_t4879 + c5_t4900;
  _SFD_SCRIPT_CALL(0, 83);
  c5_t4902 = c5_t4859 * c5_t4901;
  _SFD_SCRIPT_CALL(0, 84);
  c5_t4912 = c5_t4855 * c5_t4857;
  _SFD_SCRIPT_CALL(0, 85);
  c5_t4903 = c5_t4883 - c5_t4912;
  _SFD_SCRIPT_CALL(0, 86);
  c5_t4904 = c5_t4872 * c5_t4874;
  _SFD_SCRIPT_CALL(0, 87);
  c5_t4905 = c5_t4904 - c5_t4873 * c5_t4867 * c5_t4868;
  _SFD_SCRIPT_CALL(0, 88);
  c5_t4906 = c5_Cy6 * c5_t4905;
  _SFD_SCRIPT_CALL(0, 89);
  c5_t4907 = c5_t4872 * c5_t4868;
  _SFD_SCRIPT_CALL(0, 90);
  c5_t4908 = c5_t4873 * c5_t4874 * c5_t4867;
  _SFD_SCRIPT_CALL(0, 91);
  c5_t4909 = c5_t4907 + c5_t4908;
  _SFD_SCRIPT_CALL(0, 92);
  c5_t4910 = c5_Cz6 * c5_t4909;
  _SFD_SCRIPT_CALL(0, 93);
  c5_t4911 = c5_Cx6 * c5_t4897;
  _SFD_SCRIPT_CALL(0, 94);
  c5_t4913 = c5_t4868 - 1.0;
  _SFD_SCRIPT_CALL(0, 95);
  c5_t4914 = c5_t4863 * c5_t4873 * c5_t4876;
  _SFD_SCRIPT_CALL(0, 96);
  c5_t4915 = c5_t4861 * c5_t4867;
  _SFD_SCRIPT_CALL(0, 97);
  c5_t4916 = c5_t4895 - c5_t4864 * c5_t4876;
  _SFD_SCRIPT_CALL(0, 98);
  c5_t4917 = c5_t4867 * c5_t4916;
  _SFD_SCRIPT_CALL(0, 99);
  c5_t4918 = c5_t4864 * c5_t4867;
  _SFD_SCRIPT_CALL(0, 100);
  c5_t4920 = c5_t4861 * c5_t4871 * c5_t4863;
  _SFD_SCRIPT_CALL(0, 101);
  c5_t4919 = (-c5_t4920) + c5_t4918;
  _SFD_SCRIPT_CALL(0, 102);
  c5_t4921 = c5_t4864 * c5_t4877;
  _SFD_SCRIPT_CALL(0, 103);
  c5_t4922 = c5_t4890 + c5_t4921;
  _SFD_SCRIPT_CALL(0, 104);
  c5_t4923 = c5_t4871 * c5_t4863 * c5_t4922;
  _SFD_SCRIPT_CALL(0, 105);
  c5_t4924 = c5_t4871 * c5_t4863 * c5_t4864;
  _SFD_SCRIPT_CALL(0, 106);
  c5_t4925 = c5_t4915 + c5_t4924;
  _SFD_SCRIPT_CALL(0, 107);
  c5_t4926 = c5_t4871 * c5_t4864 * (c5_t4862 - c5_t4869);
  _SFD_SCRIPT_CALL(0, 108);
  c5_t4927 = c5_t4915 + c5_t4926;
  _SFD_SCRIPT_CALL(0, 109);
  c5_N_d_[0] = 0.0;
  c5_N_d_[1] = (((c5_Ma3 * (((((c5_t4882 + c5_t4885) + c5_t4886) - c5_Cz3 *
    c5_t4867) - c5_t4860 * c5_t4884) + c5_Cx3 * (c5_t4862 -
    c5_t4869)) * 9.8 + c5_Ma2 * (((c5_t4885 + c5_t4886) - c5_Cx2 * c5_t4859) -
    c5_Cz2 * c5_t4860) * 9.8) + c5_Ma6 * (((((((((((c5_t4882
    + c5_t4885) + c5_t4886) + c5_t4888) + c5_t4910) + c5_t4911) + c5_t4906) -
    c5_t4860 * c5_t4884) - c5_t4863 * c5_t4892) - c5_t4871 *
    c5_t4867 * c5_t4896) - c5_t4872 * c5_t4876 * c5_t4913) - c5_t4873 * c5_t4874
    * c5_t4867 * c5_t4876) * 9.8) + c5_Ma5 * (((((((((
    c5_t4882 + c5_t4885) + c5_t4886) + c5_t4888) + c5_t4898) - c5_t4860 *
    c5_t4884) - c5_t4863 * c5_t4892) + c5_Cz5 * (c5_t4870 -
    c5_t4875)) - c5_Cy5 * c5_t4873 * c5_t4867) - c5_t4871 * c5_t4867 * c5_t4896)
                * 9.8) + c5_Ma4 * (((((((c5_t4882 + c5_t4885) +
    c5_t4886) + c5_t4888) - c5_t4860 * c5_t4884) + c5_Cx4 * (c5_t4862 - c5_t4869))
    - c5_Cy4 * c5_t4873 * c5_t4867) - c5_Cz4 * c5_t4871
    * c5_t4867) * 9.8;
  c5_N_d_[2] = ((c5_Ma4 * (((((c5_t4888 + c5_t4902) + c5_Cx4 * c5_t4863) -
    c5_t4860 * c5_t4903) - c5_Cy4 * c5_t4873 * c5_t4867) -
    c5_Cz4 * c5_t4871 * c5_t4867) * 9.8 + c5_Ma5 * (((((((c5_t4888 + c5_t4898) +
    c5_t4902) + c5_Cz5 * c5_t4872) - c5_t4860 * c5_t4903)
    - c5_t4892 * (c5_t4862 - c5_t4869)) - c5_Cy5 * c5_t4873 * c5_t4867) -
    c5_t4871 * c5_t4867 * c5_t4896) * 9.8) + c5_Ma6 * (((((((((
    c5_t4888 + c5_t4910) + c5_t4902) + c5_t4911) + c5_t4906) - c5_t4860 *
    c5_t4903) - c5_t4892 * (c5_t4862 - c5_t4869)) - c5_t4871 *
    c5_t4867 * c5_t4896) - c5_t4876 * c5_t4913 * (c5_t4870 - c5_t4875)) -
    c5_t4873 * c5_t4874 * c5_t4867 * c5_t4876) * 9.8) + c5_Ma3 * (
    ((c5_t4902 + c5_Cx3 * c5_t4863) - c5_Cz3 * c5_t4867) - c5_t4860 * c5_t4903) *
    9.8;
  c5_N_d_[3] = (c5_Ma4 * ((c5_t4914 + c5_Cy4 * c5_t4871 * c5_t4863) - c5_Cz4 *
    c5_t4863 * c5_t4873) * -9.8 - c5_Ma5 * ((((c5_t4914 +
    c5_Cy5 * c5_t4871 * c5_t4863) - c5_t4863 * c5_t4873 * c5_t4896) + c5_Cx5 *
    c5_t4861 * c5_t4863 * c5_t4873) - c5_Cz5 * c5_t4863 *
    c5_t4864 * c5_t4873) * 9.8) - c5_Ma6 * ((((((c5_t4914 + c5_Cy6 * (c5_t4871 *
    c5_t4863 * c5_t4868 - c5_t4863 * c5_t4864 * c5_t4873 *
    c5_t4874)) - c5_Cz6 * (c5_t4871 * c5_t4863 * c5_t4874 + c5_t4863 * c5_t4864 *
    c5_t4873 * c5_t4868)) - c5_t4863 * c5_t4873 * c5_t4896
    ) + c5_t4871 * c5_t4863 * c5_t4874 * c5_t4876) + c5_Cx6 * c5_t4861 *
    c5_t4863 * c5_t4873) + c5_t4863 * c5_t4864 * c5_t4873 *
    c5_t4876 * c5_t4913) * 9.8;
  c5_N_d_[4] = c5_Ma5 * (((c5_t4923 + c5_t4917) - c5_Cx5 * c5_t4925) + c5_Cz5 *
    c5_t4919) * -9.8 - c5_Ma6 * (((((c5_t4923 + c5_t4917)
    - c5_Cx6 * c5_t4925) + c5_Cy6 * c5_t4874 * c5_t4919) + c5_Cz6 * c5_t4868 *
    c5_t4919) - c5_t4876 * c5_t4913 * c5_t4919) * 9.8;
  c5_N_d_[5] = c5_Ma6 * (((c5_Cy6 * (c5_t4868 * c5_t4927 - c5_t4863 * c5_t4873 *
    c5_t4874) - c5_Cz6 * (c5_t4874 * c5_t4927 + c5_t4863
    * c5_t4873 * c5_t4868)) + c5_t4874 * c5_t4876 * c5_t4927) + c5_t4863 *
    c5_t4873 * c5_t4876 * c5_t4868) * -9.8;
  _SFD_SCRIPT_CALL(0, -109);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i22;
  real_T c5_b_u[6];
  int32_T c5_i23;
  real_T c5_c_u[6];
  const mxArray *c5_b_y = NULL;
  SFc5_EulerDynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerDynJointConInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i22 = 0; c5_i22 < 6; c5_i22 = c5_i22 + 1) {
    c5_b_u[c5_i22] = (*((real_T (*)[6])c5_u))[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 6; c5_i23 = c5_i23 + 1) {
    c5_c_u[c5_i23] = c5_b_u[c5_i23];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i24;
  real_T c5_b_u[18];
  int32_T c5_i25;
  real_T c5_c_u[18];
  const mxArray *c5_b_y = NULL;
  SFc5_EulerDynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerDynJointConInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i24 = 0; c5_i24 < 18; c5_i24 = c5_i24 + 1) {
    c5_b_u[c5_i24] = (*((real_T (*)[18])c5_u))[c5_i24];
  }

  for (c5_i25 = 0; c5_i25 < 18; c5_i25 = c5_i25 + 1) {
    c5_c_u[c5_i25] = c5_b_u[c5_i25];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 1, 18));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_EulerDynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerDynJointConInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i26;
  real_T c5_b_u[6];
  int32_T c5_i27;
  real_T c5_c_u[6];
  const mxArray *c5_b_y = NULL;
  SFc5_EulerDynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerDynJointConInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i26 = 0; c5_i26 < 6; c5_i26 = c5_i26 + 1) {
    c5_b_u[c5_i26] = (*((real_T (*)[6])c5_u))[c5_i26];
  }

  for (c5_i27 = 0; c5_i27 < 6; c5_i27 = c5_i27 + 1) {
    c5_c_u[c5_i27] = c5_b_u[c5_i27];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_e_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i28;
  real_T c5_b_u[9];
  int32_T c5_i29;
  real_T c5_c_u[9];
  const mxArray *c5_b_y = NULL;
  SFc5_EulerDynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerDynJointConInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i28 = 0; c5_i28 < 9; c5_i28 = c5_i28 + 1) {
    c5_b_u[c5_i28] = (*((real_T (*)[9])c5_u))[c5_i28];
  }

  for (c5_i29 = 0; c5_i29 < 9; c5_i29 = c5_i29 + 1) {
    c5_c_u[c5_i29] = c5_b_u[c5_i29];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_EulerDynJointCon_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[21];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i30;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 21));
  for (c5_i30 = 0; c5_i30 < 21; c5_i30 = c5_i30 + 1) {
    c5_r0 = &c5_info[c5_i30];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i30);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i30);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i30);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c5_i30);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c5_i30);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i30
                    );
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i30
                    );
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[21])
{
  c5_info[0].context = "";
  c5_info[0].name = "zeros";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[B]zeros";
  c5_info[0].fileLength = 0U;
  c5_info[0].fileTime1 = 0U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context = "";
  c5_info[1].name = "mrdivide";
  c5_info[1].dominantType = "double";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[1].fileLength = 432U;
  c5_info[1].fileTime1 = 1277726622U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[2].name = "nargin";
  c5_info[2].dominantType = "";
  c5_info[2].resolved = "[B]nargin";
  c5_info[2].fileLength = 0U;
  c5_info[2].fileTime1 = 0U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[3].name = "ge";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[B]ge";
  c5_info[3].fileLength = 0U;
  c5_info[3].fileTime1 = 0U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[4].name = "isscalar";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved = "[B]isscalar";
  c5_info[4].fileLength = 0U;
  c5_info[4].fileTime1 = 0U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[5].name = "rdivide";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[5].fileLength = 403U;
  c5_info[5].fileTime1 = 1245080820U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[6].name = "gt";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[B]gt";
  c5_info[6].fileLength = 0U;
  c5_info[6].fileTime1 = 0U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[7].name = "isa";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved = "[B]isa";
  c5_info[7].fileLength = 0U;
  c5_info[7].fileTime1 = 0U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[8].name = "eml_div";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[8].fileLength = 4918U;
  c5_info[8].fileTime1 = 1267038210U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[9].name = "isinteger";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[B]isinteger";
  c5_info[9].fileLength = 0U;
  c5_info[9].fileTime1 = 0U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c5_info[10].name = "isreal";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved = "[B]isreal";
  c5_info[10].fileLength = 0U;
  c5_info[10].fileTime1 = 0U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context = "";
  c5_info[11].name = "ctranspose";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[B]ctranspose";
  c5_info[11].fileLength = 0U;
  c5_info[11].fileTime1 = 0U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context = "";
  c5_info[12].name = "N_d";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/N_d.m";
  c5_info[12].fileLength = 4028U;
  c5_info[12].fileTime1 = 1368548845U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context = "[E]D:/Learn/Project_Matlab/Fanuc/N_d.m";
  c5_info[13].name = "cos";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[13].fileLength = 324U;
  c5_info[13].fileTime1 = 1203422750U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c5_info[14].name = "eml_scalar_cos";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c5_info[14].fileLength = 602U;
  c5_info[14].fileTime1 = 1209309186U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context = "[E]D:/Learn/Project_Matlab/Fanuc/N_d.m";
  c5_info[15].name = "minus";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved = "[B]minus";
  c5_info[15].fileLength = 0U;
  c5_info[15].fileTime1 = 0U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context = "[E]D:/Learn/Project_Matlab/Fanuc/N_d.m";
  c5_info[16].name = "plus";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved = "[B]plus";
  c5_info[16].fileLength = 0U;
  c5_info[16].fileTime1 = 0U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context = "[E]D:/Learn/Project_Matlab/Fanuc/N_d.m";
  c5_info[17].name = "sin";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[17].fileLength = 324U;
  c5_info[17].fileTime1 = 1203422842U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c5_info[18].name = "eml_scalar_sin";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c5_info[18].fileLength = 601U;
  c5_info[18].fileTime1 = 1209309190U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context = "[E]D:/Learn/Project_Matlab/Fanuc/N_d.m";
  c5_info[19].name = "times";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved = "[B]times";
  c5_info[19].fileLength = 0U;
  c5_info[19].fileTime1 = 0U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context = "[E]D:/Learn/Project_Matlab/Fanuc/N_d.m";
  c5_info[20].name = "uminus";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved = "[B]uminus";
  c5_info[20].fileLength = 0U;
  c5_info[20].fileTime1 = 0U;
  c5_info[20].fileTime2 = 0U;
}

static const mxArray *c5_f_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  boolean_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_EulerDynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerDynJointConInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((boolean_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static void c5_emlrt_marshallIn(SFc5_EulerDynJointConInstanceStruct
  *chartInstance, const mxArray *c5_N, const char_T *c5_name,
  real_T c5_y[6])
{
  real_T c5_dv9[6];
  int32_T c5_i31;
  sf_mex_import(c5_name, sf_mex_dup(c5_N), c5_dv9, 1, 0, 0U, 1, 0U, 1, 6);
  for (c5_i31 = 0; c5_i31 < 6; c5_i31 = c5_i31 + 1) {
    c5_y[c5_i31] = c5_dv9[c5_i31];
  }

  sf_mex_destroy(&c5_N);
}

static uint8_T c5_b_emlrt_marshallIn(SFc5_EulerDynJointConInstanceStruct
  *chartInstance, const mxArray *
  c5_b_is_active_c5_EulerDynJointCon, const char_T *c5_name)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_name, sf_mex_dup(c5_b_is_active_c5_EulerDynJointCon), &c5_u0,
                1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_b_is_active_c5_EulerDynJointCon);
  return c5_y;
}

static void init_dsm_address_info(SFc5_EulerDynJointConInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_EulerDynJointCon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(799476181U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4211079029U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1231543382U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(528346270U);
}

mxArray *sf_c5_EulerDynJointCon_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2618954196U);
    pr[1] = (double)(1156146008U);
    pr[2] = (double)(2164767407U);
    pr[3] = (double)(2797001480U);
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[1] = (double)(9);
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
      pr[1] = (double)(6);
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

static mxArray *sf_get_sim_state_info_c5_EulerDynJointCon(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"N\",},{M[8],M[0],T\"is_active_c5_EulerDynJointCon\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_EulerDynJointCon_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_EulerDynJointConInstanceStruct *chartInstance;
    chartInstance = (SFc5_EulerDynJointConInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_EulerDynJointConMachineNumber_,
           5,
           1,
           1,
           5,
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
          init_script_number_translation(_EulerDynJointConMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_EulerDynJointConMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_EulerDynJointConMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EnTheta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"N");
          _SFD_SET_DATA_PROPS(2,10,0,0,"L");
          _SFD_SET_DATA_PROPS(3,10,0,0,"Cen");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Ma");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,86);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"N_d",0,-1,3919);
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
            1.0,0,0,(MexFcnForType)c5_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_d_sf_marshall);
        }

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
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_EulerDynJointConMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_EulerDynJointCon(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_EulerDynJointConInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*)
    chartInstanceVar);
  initialize_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_EulerDynJointCon(void *chartInstanceVar)
{
  enable_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_EulerDynJointCon(void *chartInstanceVar)
{
  disable_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_EulerDynJointCon(void *chartInstanceVar)
{
  sf_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c5_EulerDynJointCon(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_EulerDynJointCon
    ((SFc5_EulerDynJointConInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c5_EulerDynJointCon();/* state var info */
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

static void sf_internal_set_sim_state_c5_EulerDynJointCon(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_EulerDynJointCon();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c5_EulerDynJointCon(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_EulerDynJointCon(S);
}

static void sf_opaque_set_sim_state_c5_EulerDynJointCon(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_EulerDynJointCon(S, st);
}

static void sf_opaque_terminate_c5_EulerDynJointCon(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_EulerDynJointConInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c5_EulerDynJointCon
    ((SFc5_EulerDynJointConInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_EulerDynJointCon(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_EulerDynJointCon((SFc5_EulerDynJointConInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_EulerDynJointCon(SimStruct *S)
{
  /* Actual parameters from chart:
     Cen L Ma
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Cen*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for Ma*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EulerDynJointCon","EulerDynJointCon",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EulerDynJointCon","EulerDynJointCon",5,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"EulerDynJointCon",
      "EulerDynJointCon",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EulerDynJointCon",
        "EulerDynJointCon",5,1);
      sf_mark_chart_reusable_outputs(S,"EulerDynJointCon","EulerDynJointCon",5,1);
    }

    sf_set_rtw_dwork_info(S,"EulerDynJointCon","EulerDynJointCon",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1781063280U));
  ssSetChecksum1(S,(1604820547U));
  ssSetChecksum2(S,(3197153058U));
  ssSetChecksum3(S,(4035705320U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_EulerDynJointCon(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EulerDynJointCon", "EulerDynJointCon",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_EulerDynJointCon(SimStruct *S)
{
  SFc5_EulerDynJointConInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerDynJointConInstanceStruct *)malloc(sizeof
    (SFc5_EulerDynJointConInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_EulerDynJointConInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_EulerDynJointCon;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_EulerDynJointCon;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_EulerDynJointCon;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_EulerDynJointCon;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_EulerDynJointCon;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_EulerDynJointCon;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_EulerDynJointCon;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_EulerDynJointCon;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_EulerDynJointCon;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_EulerDynJointCon;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_EulerDynJointCon;
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

void c5_EulerDynJointCon_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_EulerDynJointCon(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_EulerDynJointCon(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_EulerDynJointCon(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_EulerDynJointCon_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
