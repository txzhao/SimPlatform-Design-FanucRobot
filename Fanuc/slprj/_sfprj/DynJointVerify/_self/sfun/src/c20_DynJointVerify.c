/* Include files */

#include "blascompat32.h"
#include "DynJointVerify_sfun.h"
#include "c20_DynJointVerify.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DynJointVerify_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c20_debug_family_names[8] = { "L_EU", "Ma", "nargin",
  "nargout", "EnTheta", "Cen", "Gravity", "N" };

static const char *c20_b_debug_family_names[132] = { "Cx2", "Cx3", "Cx4", "Cx5",
  "Cx6", "Cy4", "Cy5", "Cy6", "Cz2", "Cz3", "Cz4", "Cz5", "Cz6", "Ld1", "Ld2",
  "Ld3", "Ld4", "Ld5", "Ld6", "Ld7", "Ma2", "Ma3", "Ma4", "Ma5", "Ma6", "pos2",
  "pos3", "pos4", "pos5", "pos6", "t457", "t458", "t459", "t460", "t461", "t462",
  "t463", "t464", "t465", "t466", "t467", "t468", "t469", "t470", "t471", "t472",
  "t473", "t474", "t475", "t476", "t477", "t478", "t479", "t482", "t480", "t481",
  "t483", "t484", "t485", "t500", "t486", "t487", "t488", "t489", "t490", "t491",
  "t492", "t493", "t494", "t495", "t496", "t503", "t497", "t498", "t504", "t499",
  "t501", "t502", "t505", "t506", "t507", "t508", "t509", "t510", "t511", "t512",
  "t513", "t514", "t515", "t516", "t517", "t518", "t519", "t520", "t521", "t526",
  "t522", "t527", "t523", "t524", "t531", "t525", "t528", "t529", "t530", "t532",
  "t533", "t534", "t538", "t535", "t536", "t537", "t539", "t540", "t541", "t542",
  "t543", "t544", "t545", "t546", "t547", "t548", "t549", "t550", "nargin",
  "nargout", "in1", "in2", "in3", "in4", "gr", "EulerNd_" };

/* Function Declarations */
static void initialize_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance);
static void initialize_params_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance);
static void enable_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance);
static void disable_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance);
static void c20_update_debugger_state_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance);
static void set_sim_state_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct *
  chartInstance, const mxArray *c20_st);
static void finalize_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance);
static void sf_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static void c20_EulerNd(SFc20_DynJointVerifyInstanceStruct *chartInstance,
  real_T c20_in1[8], real_T c20_in2[6], real_T c20_in3[18], real_T c20_in4[6],
  real_T c20_gr, real_T c20_EulerNd_[6]);
static real_T c20_power(SFc20_DynJointVerifyInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_b);
static void c20_eml_error(SFc20_DynJointVerifyInstanceStruct *chartInstance);
static const mxArray *c20_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_b_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_c_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_d_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_e_sf_marshall(void *chartInstanceVoid, void *c20_u);
static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[31]);
static const mxArray *c20_f_sf_marshall(void *chartInstanceVoid, void *c20_u);
static void c20_emlrt_marshallIn(SFc20_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c20_N, const char_T *c20_name, real_T c20_y[6]);
static uint8_T c20_b_emlrt_marshallIn(SFc20_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c20_b_is_active_c20_DynJointVerify, const
  char_T *c20_name);
static void init_dsm_address_info(SFc20_DynJointVerifyInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_DynJointVerify = 0U;
}

static void initialize_params_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance)
{
  real_T c20_dv0[8];
  int32_T c20_i0;
  real_T c20_dv1[18];
  int32_T c20_i1;
  real_T c20_dv2[6];
  int32_T c20_i2;
  real_T c20_d0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L_EU' in the parent workspace.\n");
  sf_mex_import("L_EU", sf_mex_get_sfun_param(chartInstance->S, 2, 0), c20_dv0,
                0, 0, 0U, 1, 0U, 2, 1, 8);
  for (c20_i0 = 0; c20_i0 < 8; c20_i0 = c20_i0 + 1) {
    chartInstance->c20_L_EU[c20_i0] = c20_dv0[c20_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Cen' in the parent workspace.\n");
  sf_mex_import("Cen", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c20_dv1, 0,
                0, 0U, 1, 0U, 2, 1, 18);
  for (c20_i1 = 0; c20_i1 < 18; c20_i1 = c20_i1 + 1) {
    chartInstance->c20_Cen[c20_i1] = c20_dv1[c20_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ma' in the parent workspace.\n");
  sf_mex_import("Ma", sf_mex_get_sfun_param(chartInstance->S, 3, 0), c20_dv2, 0,
                0, 0U, 1, 0U, 2, 1, 6);
  for (c20_i2 = 0; c20_i2 < 6; c20_i2 = c20_i2 + 1) {
    chartInstance->c20_Ma[c20_i2] = c20_dv2[c20_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Gravity' in the parent workspace.\n");
  sf_mex_import("Gravity", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                &c20_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c20_Gravity = c20_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c20_update_debugger_state_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance)
{
  const mxArray *c20_st = NULL;
  const mxArray *c20_y = NULL;
  int32_T c20_i3;
  real_T c20_hoistedGlobal[6];
  int32_T c20_i4;
  real_T c20_u[6];
  const mxArray *c20_b_y = NULL;
  uint8_T c20_b_hoistedGlobal;
  uint8_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T (*c20_N)[6];
  c20_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(2));
  for (c20_i3 = 0; c20_i3 < 6; c20_i3 = c20_i3 + 1) {
    c20_hoistedGlobal[c20_i3] = (*c20_N)[c20_i3];
  }

  for (c20_i4 = 0; c20_i4 < 6; c20_i4 = c20_i4 + 1) {
    c20_u[c20_i4] = c20_hoistedGlobal[c20_i4];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = chartInstance->c20_is_active_c20_DynJointVerify;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y);
  return c20_st;
}

static void set_sim_state_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct *
  chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv3[6];
  int32_T c20_i5;
  real_T (*c20_N)[6];
  c20_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = TRUE;
  c20_u = sf_mex_dup(c20_st);
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)), "N",
                       c20_dv3);
  for (c20_i5 = 0; c20_i5 < 6; c20_i5 = c20_i5 + 1) {
    (*c20_N)[c20_i5] = c20_dv3[c20_i5];
  }

  chartInstance->c20_is_active_c20_DynJointVerify = c20_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)),
     "is_active_c20_DynJointVerify");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_DynJointVerify(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

static void sf_c20_DynJointVerify(SFc20_DynJointVerifyInstanceStruct
  *chartInstance)
{
  int32_T c20_i6;
  int32_T c20_i7;
  int32_T c20_i8;
  int32_T c20_i9;
  int32_T c20_i10;
  int32_T c20_previousEvent;
  int32_T c20_i11;
  real_T c20_hoistedGlobal[6];
  int32_T c20_i12;
  real_T c20_b_hoistedGlobal[18];
  real_T c20_c_hoistedGlobal;
  int32_T c20_i13;
  real_T c20_EnTheta[6];
  int32_T c20_i14;
  real_T c20_b_Cen[18];
  real_T c20_b_Gravity;
  uint32_T c20_debug_family_var_map[8];
  static const char *c20_sv0[8] = { "L_EU", "Ma", "nargin", "nargout", "EnTheta",
    "Cen", "Gravity", "N" };

  real_T c20_b_L_EU[8] = { 0.266, 0.3, 0.15, 0.87, 0.0, 0.17, 1.016, 0.174 };

  real_T c20_b_Ma[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  real_T c20_nargin = 5.0;
  real_T c20_nargout = 1.0;
  real_T c20_N[6];
  int32_T c20_i15;
  int32_T c20_i16;
  static real_T c20_dv4[8] = { 0.266, 0.3, 0.15, 0.87, 0.0, 0.17, 1.016, 0.174 };

  real_T c20_dv5[8];
  int32_T c20_i17;
  static real_T c20_dv6[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  real_T c20_dv7[6];
  int32_T c20_i18;
  real_T c20_c_Cen[18];
  int32_T c20_i19;
  real_T c20_b_EnTheta[6];
  real_T c20_dv8[6];
  int32_T c20_i20;
  int32_T c20_i21;
  real_T (*c20_b_N)[6];
  real_T (*c20_c_EnTheta)[6];
  c20_b_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_c_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19);
  for (c20_i6 = 0; c20_i6 < 6; c20_i6 = c20_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_c_EnTheta)[c20_i6], 0U);
  }

  for (c20_i7 = 0; c20_i7 < 6; c20_i7 = c20_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_b_N)[c20_i7], 1U);
  }

  for (c20_i8 = 0; c20_i8 < 8; c20_i8 = c20_i8 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_L_EU[c20_i8], 2U);
  }

  for (c20_i9 = 0; c20_i9 < 18; c20_i9 = c20_i9 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_Cen[c20_i9], 3U);
  }

  for (c20_i10 = 0; c20_i10 < 6; c20_i10 = c20_i10 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_Ma[c20_i10], 4U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c20_Gravity, 5U);
  c20_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19);
  for (c20_i11 = 0; c20_i11 < 6; c20_i11 = c20_i11 + 1) {
    c20_hoistedGlobal[c20_i11] = (*c20_c_EnTheta)[c20_i11];
  }

  for (c20_i12 = 0; c20_i12 < 18; c20_i12 = c20_i12 + 1) {
    c20_b_hoistedGlobal[c20_i12] = chartInstance->c20_Cen[c20_i12];
  }

  c20_c_hoistedGlobal = chartInstance->c20_Gravity;
  for (c20_i13 = 0; c20_i13 < 6; c20_i13 = c20_i13 + 1) {
    c20_EnTheta[c20_i13] = c20_hoistedGlobal[c20_i13];
  }

  for (c20_i14 = 0; c20_i14 < 18; c20_i14 = c20_i14 + 1) {
    c20_b_Cen[c20_i14] = c20_b_hoistedGlobal[c20_i14];
  }

  c20_b_Gravity = c20_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 8U, 8U, c20_sv0, c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c20_b_L_EU, c20_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c20_b_Ma, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c20_EnTheta, c20_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c20_b_Cen, c20_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c20_b_Gravity, c20_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c20_N, c20_sf_marshall, 7U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c20_i15 = 0; c20_i15 < 6; c20_i15 = c20_i15 + 1) {
    c20_N[c20_i15] = 0.0;
  }

  _SFD_EML_CALL(0, 4);
  for (c20_i16 = 0; c20_i16 < 8; c20_i16 = c20_i16 + 1) {
    c20_dv5[c20_i16] = c20_dv4[c20_i16];
  }

  for (c20_i17 = 0; c20_i17 < 6; c20_i17 = c20_i17 + 1) {
    c20_dv7[c20_i17] = c20_dv6[c20_i17];
  }

  for (c20_i18 = 0; c20_i18 < 18; c20_i18 = c20_i18 + 1) {
    c20_c_Cen[c20_i18] = c20_b_Cen[c20_i18];
  }

  for (c20_i19 = 0; c20_i19 < 6; c20_i19 = c20_i19 + 1) {
    c20_b_EnTheta[c20_i19] = c20_EnTheta[c20_i19];
  }

  c20_EulerNd(chartInstance, c20_dv5, c20_dv7, c20_c_Cen, c20_b_EnTheta,
              c20_b_Gravity, c20_dv8);
  for (c20_i20 = 0; c20_i20 < 6; c20_i20 = c20_i20 + 1) {
    c20_N[c20_i20] = c20_dv8[c20_i20];
  }

  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  for (c20_i21 = 0; c20_i21 < 6; c20_i21 = c20_i21 + 1) {
    (*c20_b_N)[c20_i21] = c20_N[c20_i21];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19);
  _sfEvent_ = c20_previousEvent;
  sf_debug_check_for_state_inconsistency(_DynJointVerifyMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c20_DynJointVerify
  (SFc20_DynJointVerifyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/EulerNd.m"));
}

static void c20_EulerNd(SFc20_DynJointVerifyInstanceStruct *chartInstance,
  real_T c20_in1[8], real_T c20_in2[6], real_T c20_in3[18]
  , real_T c20_in4[6], real_T c20_gr, real_T c20_EulerNd_[6])
{
  uint32_T c20_debug_family_var_map[132];
  real_T c20_Cx2;
  real_T c20_Cx3;
  real_T c20_Cx4;
  real_T c20_Cx5;
  real_T c20_Cx6;
  real_T c20_Cy4;
  real_T c20_Cy5;
  real_T c20_Cy6;
  real_T c20_Cz2;
  real_T c20_Cz3;
  real_T c20_Cz4;
  real_T c20_Cz5;
  real_T c20_Cz6;
  real_T c20_Ld1;
  real_T c20_Ld2;
  real_T c20_Ld3;
  real_T c20_Ld4;
  real_T c20_Ld5;
  real_T c20_Ld6;
  real_T c20_Ld7;
  real_T c20_Ma2;
  real_T c20_Ma3;
  real_T c20_Ma4;
  real_T c20_Ma5;
  real_T c20_Ma6;
  real_T c20_pos2;
  real_T c20_pos3;
  real_T c20_pos4;
  real_T c20_pos5;
  real_T c20_pos6;
  real_T c20_t457;
  real_T c20_t458;
  real_T c20_t459;
  real_T c20_t460;
  real_T c20_t461;
  real_T c20_t462;
  real_T c20_t463;
  real_T c20_t464;
  real_T c20_t465;
  real_T c20_t466;
  real_T c20_t467;
  real_T c20_t468;
  real_T c20_t469;
  real_T c20_t470;
  real_T c20_t471;
  real_T c20_t472;
  real_T c20_t473;
  real_T c20_t474;
  real_T c20_t475;
  real_T c20_t476;
  real_T c20_t477;
  real_T c20_t478;
  real_T c20_t479;
  real_T c20_t482;
  real_T c20_t480;
  real_T c20_t481;
  real_T c20_t483;
  real_T c20_t484;
  real_T c20_t485;
  real_T c20_t500;
  real_T c20_t486;
  real_T c20_t487;
  real_T c20_t488;
  real_T c20_t489;
  real_T c20_t490;
  real_T c20_t491;
  real_T c20_t492;
  real_T c20_t493;
  real_T c20_t494;
  real_T c20_t495;
  real_T c20_t496;
  real_T c20_t503;
  real_T c20_t497;
  real_T c20_t498;
  real_T c20_t504;
  real_T c20_t499;
  real_T c20_t501;
  real_T c20_t502;
  real_T c20_t505;
  real_T c20_t506;
  real_T c20_t507;
  real_T c20_t508;
  real_T c20_t509;
  real_T c20_t510;
  real_T c20_t511;
  real_T c20_t512;
  real_T c20_t513;
  real_T c20_t514;
  real_T c20_t515;
  real_T c20_t516;
  real_T c20_t517;
  real_T c20_t518;
  real_T c20_t519;
  real_T c20_t520;
  real_T c20_t521;
  real_T c20_t526;
  real_T c20_t522;
  real_T c20_t527;
  real_T c20_t523;
  real_T c20_t524;
  real_T c20_t531;
  real_T c20_t525;
  real_T c20_t528;
  real_T c20_t529;
  real_T c20_t530;
  real_T c20_t532;
  real_T c20_t533;
  real_T c20_t534;
  real_T c20_t538;
  real_T c20_t535;
  real_T c20_t536;
  real_T c20_t537;
  real_T c20_t539;
  real_T c20_t540;
  real_T c20_t541;
  real_T c20_t542;
  real_T c20_t543;
  real_T c20_t544;
  real_T c20_t545;
  real_T c20_t546;
  real_T c20_t547;
  real_T c20_t548;
  real_T c20_t549;
  real_T c20_t550;
  real_T c20_nargin = 5.0;
  real_T c20_nargout = 1.0;
  real_T c20_x;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_f_x;
  real_T c20_g_x;
  real_T c20_h_x;
  real_T c20_i_x;
  real_T c20_j_x;
  real_T c20_k_x;
  real_T c20_l_x;
  real_T c20_m_x;
  real_T c20_n_x;
  real_T c20_o_x;
  real_T c20_p_x;
  real_T c20_q_x;
  real_T c20_r_x;
  real_T c20_s_x;
  real_T c20_t_x;
  real_T c20_u_x;
  real_T c20_v_x;
  real_T c20_w_x;
  real_T c20_x_x;
  real_T c20_y_x;
  real_T c20_d1;
  real_T c20_d2;
  sf_debug_symbol_scope_push_eml(0U, 132U, 132U, c20_b_debug_family_names,
    c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_Cx2, c20_b_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_Cx3, c20_b_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c20_Cx4, c20_b_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c20_Cx5, c20_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c20_Cx6, c20_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c20_Cy4, c20_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c20_Cy5, c20_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c20_Cy6, c20_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c20_Cz2, c20_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c20_Cz3, c20_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c20_Cz4, c20_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c20_Cz5, c20_b_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c20_Cz6, c20_b_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c20_Ld1, c20_b_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c20_Ld2, c20_b_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c20_Ld3, c20_b_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c20_Ld4, c20_b_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c20_Ld5, c20_b_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c20_Ld6, c20_b_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c20_Ld7, c20_b_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c20_Ma2, c20_b_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c20_Ma3, c20_b_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c20_Ma4, c20_b_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c20_Ma5, c20_b_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c20_Ma6, c20_b_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c20_pos2, c20_b_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c20_pos3, c20_b_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c20_pos4, c20_b_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c20_pos5, c20_b_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c20_pos6, c20_b_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c20_t457, c20_b_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c20_t458, c20_b_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c20_t459, c20_b_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c20_t460, c20_b_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c20_t461, c20_b_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c20_t462, c20_b_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c20_t463, c20_b_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c20_t464, c20_b_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c20_t465, c20_b_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c20_t466, c20_b_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c20_t467, c20_b_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c20_t468, c20_b_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c20_t469, c20_b_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c20_t470, c20_b_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c20_t471, c20_b_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c20_t472, c20_b_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c20_t473, c20_b_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c20_t474, c20_b_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c20_t475, c20_b_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c20_t476, c20_b_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c20_t477, c20_b_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c20_t478, c20_b_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c20_t479, c20_b_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c20_t482, c20_b_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c20_t480, c20_b_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c20_t481, c20_b_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c20_t483, c20_b_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c20_t484, c20_b_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c20_t485, c20_b_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c20_t500, c20_b_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c20_t486, c20_b_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c20_t487, c20_b_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c20_t488, c20_b_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c20_t489, c20_b_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c20_t490, c20_b_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(&c20_t491, c20_b_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c20_t492, c20_b_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(&c20_t493, c20_b_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(&c20_t494, c20_b_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(&c20_t495, c20_b_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(&c20_t496, c20_b_sf_marshall, 70U);
  sf_debug_symbol_scope_add_eml(&c20_t503, c20_b_sf_marshall, 71U);
  sf_debug_symbol_scope_add_eml(&c20_t497, c20_b_sf_marshall, 72U);
  sf_debug_symbol_scope_add_eml(&c20_t498, c20_b_sf_marshall, 73U);
  sf_debug_symbol_scope_add_eml(&c20_t504, c20_b_sf_marshall, 74U);
  sf_debug_symbol_scope_add_eml(&c20_t499, c20_b_sf_marshall, 75U);
  sf_debug_symbol_scope_add_eml(&c20_t501, c20_b_sf_marshall, 76U);
  sf_debug_symbol_scope_add_eml(&c20_t502, c20_b_sf_marshall, 77U);
  sf_debug_symbol_scope_add_eml(&c20_t505, c20_b_sf_marshall, 78U);
  sf_debug_symbol_scope_add_eml(&c20_t506, c20_b_sf_marshall, 79U);
  sf_debug_symbol_scope_add_eml(&c20_t507, c20_b_sf_marshall, 80U);
  sf_debug_symbol_scope_add_eml(&c20_t508, c20_b_sf_marshall, 81U);
  sf_debug_symbol_scope_add_eml(&c20_t509, c20_b_sf_marshall, 82U);
  sf_debug_symbol_scope_add_eml(&c20_t510, c20_b_sf_marshall, 83U);
  sf_debug_symbol_scope_add_eml(&c20_t511, c20_b_sf_marshall, 84U);
  sf_debug_symbol_scope_add_eml(&c20_t512, c20_b_sf_marshall, 85U);
  sf_debug_symbol_scope_add_eml(&c20_t513, c20_b_sf_marshall, 86U);
  sf_debug_symbol_scope_add_eml(&c20_t514, c20_b_sf_marshall, 87U);
  sf_debug_symbol_scope_add_eml(&c20_t515, c20_b_sf_marshall, 88U);
  sf_debug_symbol_scope_add_eml(&c20_t516, c20_b_sf_marshall, 89U);
  sf_debug_symbol_scope_add_eml(&c20_t517, c20_b_sf_marshall, 90U);
  sf_debug_symbol_scope_add_eml(&c20_t518, c20_b_sf_marshall, 91U);
  sf_debug_symbol_scope_add_eml(&c20_t519, c20_b_sf_marshall, 92U);
  sf_debug_symbol_scope_add_eml(&c20_t520, c20_b_sf_marshall, 93U);
  sf_debug_symbol_scope_add_eml(&c20_t521, c20_b_sf_marshall, 94U);
  sf_debug_symbol_scope_add_eml(&c20_t526, c20_b_sf_marshall, 95U);
  sf_debug_symbol_scope_add_eml(&c20_t522, c20_b_sf_marshall, 96U);
  sf_debug_symbol_scope_add_eml(&c20_t527, c20_b_sf_marshall, 97U);
  sf_debug_symbol_scope_add_eml(&c20_t523, c20_b_sf_marshall, 98U);
  sf_debug_symbol_scope_add_eml(&c20_t524, c20_b_sf_marshall, 99U);
  sf_debug_symbol_scope_add_eml(&c20_t531, c20_b_sf_marshall, 100U);
  sf_debug_symbol_scope_add_eml(&c20_t525, c20_b_sf_marshall, 101U);
  sf_debug_symbol_scope_add_eml(&c20_t528, c20_b_sf_marshall, 102U);
  sf_debug_symbol_scope_add_eml(&c20_t529, c20_b_sf_marshall, 103U);
  sf_debug_symbol_scope_add_eml(&c20_t530, c20_b_sf_marshall, 104U);
  sf_debug_symbol_scope_add_eml(&c20_t532, c20_b_sf_marshall, 105U);
  sf_debug_symbol_scope_add_eml(&c20_t533, c20_b_sf_marshall, 106U);
  sf_debug_symbol_scope_add_eml(&c20_t534, c20_b_sf_marshall, 107U);
  sf_debug_symbol_scope_add_eml(&c20_t538, c20_b_sf_marshall, 108U);
  sf_debug_symbol_scope_add_eml(&c20_t535, c20_b_sf_marshall, 109U);
  sf_debug_symbol_scope_add_eml(&c20_t536, c20_b_sf_marshall, 110U);
  sf_debug_symbol_scope_add_eml(&c20_t537, c20_b_sf_marshall, 111U);
  sf_debug_symbol_scope_add_eml(&c20_t539, c20_b_sf_marshall, 112U);
  sf_debug_symbol_scope_add_eml(&c20_t540, c20_b_sf_marshall, 113U);
  sf_debug_symbol_scope_add_eml(&c20_t541, c20_b_sf_marshall, 114U);
  sf_debug_symbol_scope_add_eml(&c20_t542, c20_b_sf_marshall, 115U);
  sf_debug_symbol_scope_add_eml(&c20_t543, c20_b_sf_marshall, 116U);
  sf_debug_symbol_scope_add_eml(&c20_t544, c20_b_sf_marshall, 117U);
  sf_debug_symbol_scope_add_eml(&c20_t545, c20_b_sf_marshall, 118U);
  sf_debug_symbol_scope_add_eml(&c20_t546, c20_b_sf_marshall, 119U);
  sf_debug_symbol_scope_add_eml(&c20_t547, c20_b_sf_marshall, 120U);
  sf_debug_symbol_scope_add_eml(&c20_t548, c20_b_sf_marshall, 121U);
  sf_debug_symbol_scope_add_eml(&c20_t549, c20_b_sf_marshall, 122U);
  sf_debug_symbol_scope_add_eml(&c20_t550, c20_b_sf_marshall, 123U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_b_sf_marshall, 124U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_b_sf_marshall, 125U);
  sf_debug_symbol_scope_add_eml(c20_in1, c20_e_sf_marshall, 126U);
  sf_debug_symbol_scope_add_eml(c20_in2, c20_d_sf_marshall, 127U);
  sf_debug_symbol_scope_add_eml(c20_in3, c20_c_sf_marshall, 128U);
  sf_debug_symbol_scope_add_eml(c20_in4, c20_d_sf_marshall, 129U);
  sf_debug_symbol_scope_add_eml(&c20_gr, c20_b_sf_marshall, 130U);
  sf_debug_symbol_scope_add_eml(c20_EulerNd_, c20_sf_marshall, 131U);
  CV_SCRIPT_FCN(0, 0);

  /* EULERND */
  /*     EULERND_ = EULERND(IN1,IN2,IN3,IN4,GR) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 16:04:09 */
  _SFD_SCRIPT_CALL(0, 8);
  c20_Cx2 = c20_in3[1];
  _SFD_SCRIPT_CALL(0, 9);
  c20_Cx3 = c20_in3[2];
  _SFD_SCRIPT_CALL(0, 10);
  c20_Cx4 = c20_in3[3];
  _SFD_SCRIPT_CALL(0, 11);
  c20_Cx5 = c20_in3[4];
  _SFD_SCRIPT_CALL(0, 12);
  c20_Cx6 = c20_in3[5];
  _SFD_SCRIPT_CALL(0, 13);
  c20_Cy4 = c20_in3[9];
  _SFD_SCRIPT_CALL(0, 14);
  c20_Cy5 = c20_in3[10];
  _SFD_SCRIPT_CALL(0, 15);
  c20_Cy6 = c20_in3[11];
  _SFD_SCRIPT_CALL(0, 16);
  c20_Cz2 = c20_in3[13];
  _SFD_SCRIPT_CALL(0, 17);
  c20_Cz3 = c20_in3[14];
  _SFD_SCRIPT_CALL(0, 18);
  c20_Cz4 = c20_in3[15];
  _SFD_SCRIPT_CALL(0, 19);
  c20_Cz5 = c20_in3[16];
  _SFD_SCRIPT_CALL(0, 20);
  c20_Cz6 = c20_in3[17];
  _SFD_SCRIPT_CALL(0, 21);
  c20_Ld1 = c20_in1[0];
  _SFD_SCRIPT_CALL(0, 22);
  c20_Ld2 = c20_in1[1];
  _SFD_SCRIPT_CALL(0, 23);
  c20_Ld3 = c20_in1[2];
  _SFD_SCRIPT_CALL(0, 24);
  c20_Ld4 = c20_in1[3];
  _SFD_SCRIPT_CALL(0, 25);
  c20_Ld5 = c20_in1[4];
  _SFD_SCRIPT_CALL(0, 26);
  c20_Ld6 = c20_in1[5];
  _SFD_SCRIPT_CALL(0, 27);
  c20_Ld7 = c20_in1[6];
  _SFD_SCRIPT_CALL(0, 28);
  c20_Ma2 = c20_in2[1];
  _SFD_SCRIPT_CALL(0, 29);
  c20_Ma3 = c20_in2[2];
  _SFD_SCRIPT_CALL(0, 30);
  c20_Ma4 = c20_in2[3];
  _SFD_SCRIPT_CALL(0, 31);
  c20_Ma5 = c20_in2[4];
  _SFD_SCRIPT_CALL(0, 32);
  c20_Ma6 = c20_in2[5];
  _SFD_SCRIPT_CALL(0, 33);
  c20_pos2 = c20_in4[1];
  _SFD_SCRIPT_CALL(0, 34);
  c20_pos3 = c20_in4[2];
  _SFD_SCRIPT_CALL(0, 35);
  c20_pos4 = c20_in4[3];
  _SFD_SCRIPT_CALL(0, 36);
  c20_pos5 = c20_in4[4];
  _SFD_SCRIPT_CALL(0, 37);
  c20_pos6 = c20_in4[5];
  _SFD_SCRIPT_CALL(0, 38);
  c20_t457 = c20_pos2 + c20_pos3;
  _SFD_SCRIPT_CALL(0, 39);
  c20_x = c20_pos5;
  c20_t458 = c20_x;
  c20_b_x = c20_t458;
  c20_t458 = c20_b_x;
  c20_t458 = muDoubleScalarSin(c20_t458);
  _SFD_SCRIPT_CALL(0, 40);
  c20_c_x = c20_t457;
  c20_t459 = c20_c_x;
  c20_d_x = c20_t459;
  c20_t459 = c20_d_x;
  c20_t459 = muDoubleScalarSin(c20_t459);
  _SFD_SCRIPT_CALL(0, 41);
  c20_e_x = c20_pos4;
  c20_t460 = c20_e_x;
  c20_f_x = c20_t460;
  c20_t460 = c20_f_x;
  c20_t460 = muDoubleScalarCos(c20_t460);
  _SFD_SCRIPT_CALL(0, 42);
  c20_g_x = c20_pos4;
  c20_t461 = c20_g_x;
  c20_h_x = c20_t461;
  c20_t461 = c20_h_x;
  c20_t461 = muDoubleScalarSin(c20_t461);
  _SFD_SCRIPT_CALL(0, 43);
  c20_i_x = c20_t457;
  c20_t462 = c20_i_x;
  c20_j_x = c20_t462;
  c20_t462 = c20_j_x;
  c20_t462 = muDoubleScalarCos(c20_t462);
  _SFD_SCRIPT_CALL(0, 44);
  c20_k_x = c20_pos5;
  c20_t463 = c20_k_x;
  c20_l_x = c20_t463;
  c20_t463 = c20_l_x;
  c20_t463 = muDoubleScalarCos(c20_t463);
  _SFD_SCRIPT_CALL(0, 45);
  c20_t464 = c20_t459 * c20_t463;
  _SFD_SCRIPT_CALL(0, 46);
  c20_t465 = c20_t458 * c20_t460 * c20_t462;
  _SFD_SCRIPT_CALL(0, 47);
  c20_t466 = c20_t464 + c20_t465;
  _SFD_SCRIPT_CALL(0, 48);
  c20_m_x = c20_pos2;
  c20_t467 = c20_m_x;
  c20_n_x = c20_t467;
  c20_t467 = c20_n_x;
  c20_t467 = muDoubleScalarSin(c20_t467);
  _SFD_SCRIPT_CALL(0, 49);
  c20_t468 = c20_Ld4 * c20_t467;
  _SFD_SCRIPT_CALL(0, 50);
  c20_t469 = c20_Ld3 + c20_t468;
  _SFD_SCRIPT_CALL(0, 51);
  c20_t470 = c20_t461 * c20_t469;
  _SFD_SCRIPT_CALL(0, 52);
  c20_t471 = c20_Ld5 * c20_t460;
  _SFD_SCRIPT_CALL(0, 53);
  c20_t472 = c20_Ld6 * c20_t461;
  _SFD_SCRIPT_CALL(0, 54);
  c20_t473 = c20_t471 + c20_t472;
  _SFD_SCRIPT_CALL(0, 55);
  c20_t474 = c20_t459 * c20_t473;
  _SFD_SCRIPT_CALL(0, 56);
  c20_t475 = c20_t470 + c20_t474;
  _SFD_SCRIPT_CALL(0, 57);
  c20_t476 = c20_t458 * c20_t475;
  _SFD_SCRIPT_CALL(0, 58);
  c20_t477 = c20_Ld7 * c20_t458 * c20_t461 * c20_t462;
  _SFD_SCRIPT_CALL(0, 59);
  c20_t478 = (c20_t476 + c20_t477) - c20_Ld5 * c20_t462 * c20_t463;
  _SFD_SCRIPT_CALL(0, 60);
  c20_t479 = c20_t458 * c20_t459;
  _SFD_SCRIPT_CALL(0, 61);
  c20_t482 = c20_t460 * c20_t462 * c20_t463;
  _SFD_SCRIPT_CALL(0, 62);
  c20_t480 = c20_t479 - c20_t482;
  _SFD_SCRIPT_CALL(0, 63);
  c20_o_x = c20_pos6;
  c20_t481 = c20_o_x;
  c20_p_x = c20_t481;
  c20_t481 = c20_p_x;
  c20_t481 = muDoubleScalarCos(c20_t481);
  _SFD_SCRIPT_CALL(0, 64);
  c20_q_x = c20_pos6;
  c20_t483 = c20_q_x;
  c20_r_x = c20_t483;
  c20_t483 = c20_r_x;
  c20_t483 = muDoubleScalarSin(c20_t483);
  _SFD_SCRIPT_CALL(0, 65);
  c20_t484 = c20_Cy5 - c20_Ld5;
  _SFD_SCRIPT_CALL(0, 66);
  c20_t485 = c20_t480 * c20_t483;
  _SFD_SCRIPT_CALL(0, 67);
  c20_t500 = c20_t461 * c20_t462 * c20_t481;
  _SFD_SCRIPT_CALL(0, 68);
  c20_t486 = c20_t485 - c20_t500;
  _SFD_SCRIPT_CALL(0, 69);
  c20_t487 = c20_t463 * c20_t475;
  _SFD_SCRIPT_CALL(0, 70);
  c20_t488 = c20_Ld5 * c20_t458 * c20_t462;
  _SFD_SCRIPT_CALL(0, 71);
  c20_t489 = c20_Ld7 * c20_t461 * c20_t462 * c20_t463;
  _SFD_SCRIPT_CALL(0, 72);
  c20_t490 = (c20_t487 + c20_t488) + c20_t489;
  _SFD_SCRIPT_CALL(0, 73);
  c20_t491 = c20_t480 * c20_t481;
  _SFD_SCRIPT_CALL(0, 74);
  c20_t492 = c20_t461 * c20_t462 * c20_t483;
  _SFD_SCRIPT_CALL(0, 75);
  c20_t493 = c20_t491 + c20_t492;
  _SFD_SCRIPT_CALL(0, 76);
  c20_t494 = ((((-c20_Cz6) + c20_Ld1) + c20_Ld2) + c20_Ld4) + c20_Ld6;
  _SFD_SCRIPT_CALL(0, 77);
  c20_t495 = c20_t460 * c20_t469;
  _SFD_SCRIPT_CALL(0, 78);
  c20_t496 = c20_Ld5 * c20_t461;
  _SFD_SCRIPT_CALL(0, 79);
  c20_t503 = c20_Ld6 * c20_t460;
  _SFD_SCRIPT_CALL(0, 80);
  c20_t497 = c20_t496 - c20_t503;
  _SFD_SCRIPT_CALL(0, 81);
  c20_t498 = c20_Ld7 * c20_t460 * c20_t462;
  _SFD_SCRIPT_CALL(0, 82);
  c20_t504 = c20_t459 * c20_t497;
  _SFD_SCRIPT_CALL(0, 83);
  c20_t499 = (c20_t495 + c20_t498) - c20_t504;
  _SFD_SCRIPT_CALL(0, 84);
  c20_t501 = ((-c20_Cx6) + c20_Ld3) + c20_Ld7;
  _SFD_SCRIPT_CALL(0, 85);
  c20_t502 = c20_Cy6 - c20_Ld5;
  _SFD_SCRIPT_CALL(0, 86);
  c20_t505 = ((((-c20_Cz4) + c20_Ld1) + c20_Ld2) + c20_Ld4) + c20_Ld6;
  _SFD_SCRIPT_CALL(0, 87);
  c20_t506 = c20_Cy4 - c20_Ld5;
  _SFD_SCRIPT_CALL(0, 88);
  c20_t507 = c20_Cx4 - c20_Ld3;
  _SFD_SCRIPT_CALL(0, 89);
  c20_t508 = ((-c20_Cx5) + c20_Ld3) + c20_Ld7;
  _SFD_SCRIPT_CALL(0, 90);
  c20_t509 = ((((-c20_Cz5) + c20_Ld1) + c20_Ld2) + c20_Ld4) + c20_Ld6;
  _SFD_SCRIPT_CALL(0, 91);
  c20_s_x = c20_pos3;
  c20_t510 = c20_s_x;
  c20_t_x = c20_t510;
  c20_t510 = c20_t_x;
  c20_t510 = muDoubleScalarSin(c20_t510);
  _SFD_SCRIPT_CALL(0, 92);
  c20_u_x = c20_pos3;
  c20_t511 = c20_u_x;
  c20_v_x = c20_t511;
  c20_t511 = c20_v_x;
  c20_t511 = muDoubleScalarCos(c20_t511);
  _SFD_SCRIPT_CALL(0, 93);
  c20_t512 = c20_Ld4 * c20_t511;
  _SFD_SCRIPT_CALL(0, 94);
  c20_t513 = c20_Ld6 + c20_t512;
  _SFD_SCRIPT_CALL(0, 95);
  c20_t514 = c20_t463 * c20_t513;
  _SFD_SCRIPT_CALL(0, 96);
  c20_t515 = c20_Ld7 * c20_t458 * c20_t460;
  _SFD_SCRIPT_CALL(0, 97);
  c20_t516 = (c20_t514 + c20_t515) - c20_Ld4 * c20_t458 * c20_t460 * c20_t510;
  _SFD_SCRIPT_CALL(0, 98);
  c20_t517 = c20_t460 * c20_t483;
  _SFD_SCRIPT_CALL(0, 99);
  c20_t518 = c20_t461 * c20_t463 * c20_t481;
  _SFD_SCRIPT_CALL(0, 100);
  c20_t519 = c20_t517 + c20_t518;
  _SFD_SCRIPT_CALL(0, 101);
  c20_t520 = c20_t458 * c20_t513;
  _SFD_SCRIPT_CALL(0, 102);
  c20_t521 = c20_Ld4 * c20_t460 * c20_t463 * c20_t510;
  _SFD_SCRIPT_CALL(0, 103);
  c20_t526 = c20_Ld7 * c20_t460 * c20_t463;
  _SFD_SCRIPT_CALL(0, 104);
  c20_t522 = (c20_t520 + c20_t521) - c20_t526;
  _SFD_SCRIPT_CALL(0, 105);
  c20_t527 = c20_Ld4 * c20_t510;
  _SFD_SCRIPT_CALL(0, 106);
  c20_t523 = c20_Ld7 - c20_t527;
  _SFD_SCRIPT_CALL(0, 107);
  c20_t524 = c20_t460 * c20_t481;
  _SFD_SCRIPT_CALL(0, 108);
  c20_t531 = c20_t461 * c20_t463 * c20_t483;
  _SFD_SCRIPT_CALL(0, 109);
  c20_t525 = c20_t524 - c20_t531;
  _SFD_SCRIPT_CALL(0, 110);
  c20_t528 = c20_Ma5 * c20_t461 * c20_t463 * c20_t484;
  _SFD_SCRIPT_CALL(0, 111);
  c20_t529 = c20_Ld6 * c20_t463;
  _SFD_SCRIPT_CALL(0, 112);
  c20_t530 = c20_t515 + c20_t529;
  _SFD_SCRIPT_CALL(0, 113);
  c20_t532 = c20_Ma6 * c20_t502 * c20_t519;
  _SFD_SCRIPT_CALL(0, 114);
  c20_t533 = c20_Ma6 * c20_t501 * c20_t519;
  _SFD_SCRIPT_CALL(0, 115);
  c20_t534 = c20_Ma6 * c20_t458 * c20_t461 * c20_t494;
  _SFD_SCRIPT_CALL(0, 116);
  c20_t538 = c20_Ld6 * c20_t458;
  _SFD_SCRIPT_CALL(0, 117);
  c20_t535 = c20_t526 - c20_t538;
  _SFD_SCRIPT_CALL(0, 118);
  c20_t536 = c20_Ma6 * c20_t501 * c20_t525;
  _SFD_SCRIPT_CALL(0, 119);
  c20_t537 = c20_Ma6 * c20_t458 * c20_t461 * c20_t502;
  _SFD_SCRIPT_CALL(0, 120);
  c20_t539 = c20_Ma5 * c20_t460 * c20_t508;
  _SFD_SCRIPT_CALL(0, 121);
  c20_t540 = c20_Ma5 * c20_t458 * c20_t461 * c20_t484;
  _SFD_SCRIPT_CALL(0, 122);
  c20_t541 = c20_Ma4 * c20_t461 * c20_t506;
  _SFD_SCRIPT_CALL(0, 123);
  c20_t542 = (((-c20_Cz3) + c20_Ld1) + c20_Ld2) + c20_Ld4;
  _SFD_SCRIPT_CALL(0, 124);
  c20_t543 = c20_Cx3 - c20_Ld3;
  _SFD_SCRIPT_CALL(0, 125);
  c20_t544 = c20_Ma5 * c20_t458 * c20_t461 * c20_t509;
  _SFD_SCRIPT_CALL(0, 126);
  c20_t545 = c20_Ma5 * c20_t461 * c20_t463 * c20_t508;
  _SFD_SCRIPT_CALL(0, 127);
  c20_t546 = c20_Ma4 * c20_t461 * c20_t462 * c20_t505;
  _SFD_SCRIPT_CALL(0, 128);
  c20_t547 = c20_Ma4 * c20_t460 * c20_t462 * c20_t506;
  _SFD_SCRIPT_CALL(0, 129);
  c20_t548 = c20_Ma5 * c20_t480 * c20_t508;
  _SFD_SCRIPT_CALL(0, 130);
  c20_t549 = c20_Ma6 * c20_t486 * c20_t494;
  _SFD_SCRIPT_CALL(0, 131);
  c20_t550 = c20_Ma6 * c20_t493 * c20_t502;
  _SFD_SCRIPT_CALL(0, 132);
  c20_w_x = c20_pos2;
  c20_x_x = c20_w_x;
  c20_y_x = c20_x_x;
  c20_x_x = c20_y_x;
  c20_x_x = muDoubleScalarCos(c20_x_x);
  c20_d1 = c20_power(chartInstance, c20_t460, 2.0);
  c20_d2 = c20_power(chartInstance, c20_t461, 2.0);
  c20_EulerNd_[0] = c20_gr * (((((((((-c20_t466) * ((c20_t549 + c20_t550) +
    c20_Ma6 * c20_t478) + c20_t459 * ((c20_t546 + c20_t547) +
    c20_Ld5 * c20_Ma4 * c20_t462)) - c20_t466 * ((c20_Ma5 * c20_t478 + c20_Ma5 *
    c20_t480 * c20_t484) - c20_Ma5 * c20_t461 * c20_t462 *
    c20_t509)) + c20_t480 * ((c20_Ma5 * c20_t490 + c20_Ma5 * c20_t466 * c20_t484)
    - c20_Ma5 * c20_t461 * c20_t462 * c20_t508)) +
    c20_t486 * ((c20_Ma6 * (c20_t483 * c20_t490 - c20_t481 * c20_t499) + c20_Ma6
                 * c20_t466 * c20_t494) - c20_Ma6 * c20_t493 * c20_t501)
    ) + c20_t493 * ((c20_Ma6 * (c20_t481 * c20_t490 + c20_t483 * c20_t499) +
                     c20_Ma6 * c20_t466 * c20_t502) + c20_Ma6 * c20_t486 *
                    c20_t501)) - c20_t460 * c20_t462 * ((c20_Ma4 * c20_t475 +
    c20_Ma4 * c20_t459 * c20_t506) + c20_Ma4 * c20_t461 * c20_t462 * c20_t507)
    ) + c20_t461 * c20_t462 * ((c20_Ma4 * (c20_t495 - c20_t504) - c20_Ma4 *
    c20_t459 * c20_t505) + c20_Ma4 * c20_t460 * c20_t462 *
    c20_t507)) + c20_t461 * c20_t462 * ((c20_t548 + c20_Ma5 * c20_t499) -
    c20_Ma5 * c20_t466 * c20_t509));
  c20_EulerNd_[1] = (-c20_gr) * ((((((((((((c20_t486 * ((c20_t533 + c20_t534) +
    c20_Ma6 * (c20_t483 * c20_t522 - c20_t461 * c20_t481
               * c20_t523)) + c20_t493 * ((c20_t536 + c20_t537) + c20_Ma6 *
    (c20_t481 * c20_t522 + c20_t461 * c20_t483 * c20_t523))) + c20_t480 *
    ((c20_t539 + c20_t540) + c20_Ma5 * c20_t522)) + c20_t459 * ((c20_t541 +
    c20_Ma4 * c20_t513) - c20_Ma4 * c20_t460 * c20_t505)) +
    c20_t466 * ((c20_t528 + c20_Ma5 * c20_t516) - c20_Ma5 * c20_t460 * c20_t509))
    + c20_t466 * ((c20_t532 + c20_Ma6 * c20_t516) -
                  c20_Ma6 * c20_t494 * c20_t525)) - c20_t459 * (c20_Ma3 *
    c20_t542 - c20_Ld4 * c20_Ma3 * c20_t511)) + c20_t462 * (c20_Ma3 * c20_t543
    - c20_Ld4 * c20_Ma3 * c20_t510)) + c20_t460 * c20_t462 * (c20_Ma4 * c20_t460
    * c20_t507 - c20_Ld4 * c20_Ma4 * c20_t460 * c20_t510))
    + c20_t461 * c20_t462 * (c20_Ma4 * c20_t461 * c20_t507 - c20_Ld4 * c20_Ma4 *
    c20_t461 * c20_t510)) - c20_t461 * c20_t462 * ((
    c20_t544 + c20_t545) - c20_Ma5 * c20_t461 * c20_t523)) - c20_Ma2 * c20_t467 *
                                  (((-c20_Cz2) + c20_Ld1) + c20_Ld2)) + c20_Ma2 *
    c20_x_x * (c20_Cx2 - c20_Ld3));
  c20_EulerNd_[2] = (-c20_gr) * ((((((((((c20_t486 * ((c20_t533 + c20_t534) -
    c20_Ma6 * (c20_t483 * c20_t535 + c20_Ld7 * c20_t461 *
               c20_t481)) + c20_t493 * ((c20_t536 + c20_t537) - c20_Ma6 *
    (c20_t481 * c20_t535 - c20_Ld7 * c20_t461 * c20_t483))) + c20_t459 * ((
    c20_t541 + c20_Ld6 * c20_Ma4) - c20_Ma4 * c20_t460 * c20_t505)) + c20_t480 *
                                        ((c20_t539 + c20_t540) - c20_Ma5 *
    c20_t535)) +
    c20_t466 * ((c20_t528 + c20_Ma5 * c20_t530) - c20_Ma5 * c20_t460 * c20_t509))
    + c20_t466 * ((c20_t532 + c20_Ma6 * c20_t530) -
                  c20_Ma6 * c20_t494 * c20_t525)) - c20_Ma3 * c20_t459 *
    c20_t542) + c20_Ma3 * c20_t462 * c20_t543) - c20_t461 * c20_t462 *
    ((c20_t544
      + c20_t545) - c20_Ld7 * c20_Ma5 * c20_t461)) + c20_Ma4 * c20_d1 * c20_t462
    * c20_t507) + c20_Ma4 * c20_d2 * c20_t462 * c20_t507);
  c20_EulerNd_[3] = c20_gr * (((((((c20_t546 + c20_t547) + c20_t466 * (c20_Ma6 *
    c20_t458 * c20_t483 * c20_t494 + c20_Ma6 * c20_t458
    * c20_t481 * c20_t502)) - c20_t486 * (c20_Ma6 * c20_t463 * c20_t494 -
    c20_Ma6 * c20_t458 * c20_t481 * c20_t501)) - c20_t493 * (
    c20_Ma6 * c20_t463 * c20_t502 + c20_Ma6 * c20_t458 * c20_t483 * c20_t501)) -
    c20_t461 * c20_t462 * (c20_Ma5 * c20_t458 * c20_t508 -
    c20_Ma5 * c20_t463 * c20_t509)) + c20_Ma5 * c20_t458 * c20_t466 * c20_t484)
    - c20_Ma5 * c20_t463 * c20_t480 * c20_t484);
  c20_EulerNd_[4] = (-c20_gr) * ((((c20_t548 - c20_t466 * (c20_Ma6 * c20_t481 *
    c20_t494 - c20_Ma6 * c20_t483 * c20_t502)) - c20_Ma5
    * c20_t466 * c20_t509) + c20_Ma6 * c20_t483 * c20_t486 * c20_t501) + c20_Ma6
    * c20_t481 * c20_t493 * c20_t501);
  c20_EulerNd_[5] = (-c20_gr) * (c20_t549 + c20_t550);
  _SFD_SCRIPT_CALL(0, -132);
  sf_debug_symbol_scope_pop();
}

static real_T c20_power(SFc20_DynJointVerifyInstanceStruct *chartInstance,
  real_T c20_a, real_T c20_b)
{
  real_T c20_ak;
  real_T c20_bk;
  real_T c20_x;
  real_T c20_b_x;
  c20_ak = c20_a;
  c20_bk = c20_b;
  if (c20_ak < 0.0) {
    c20_x = c20_bk;
    c20_b_x = c20_x;
    c20_b_x = muDoubleScalarFloor(c20_b_x);
    if (c20_b_x != c20_bk) {
      c20_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c20_ak, c20_bk);
}

static void c20_eml_error(SFc20_DynJointVerifyInstanceStruct *chartInstance)
{
  int32_T c20_i22;
  static char_T c20_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c20_u[32];
  const mxArray *c20_y = NULL;
  int32_T c20_i23;
  static char_T c20_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
    'r', 'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c20_b_u[102];
  const mxArray *c20_b_y = NULL;
  for (c20_i22 = 0; c20_i22 < 32; c20_i22 = c20_i22 + 1) {
    c20_u[c20_i22] = c20_cv0[c20_i22];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c20_i23 = 0; c20_i23 < 102; c20_i23 = c20_i23 + 1) {
    c20_b_u[c20_i23] = c20_cv1[c20_i23];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c20_y, 14, c20_b_y);
}

static const mxArray *c20_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i24;
  real_T c20_b_u[6];
  int32_T c20_i25;
  real_T c20_c_u[6];
  const mxArray *c20_b_y = NULL;
  SFc20_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc20_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c20_y = NULL;
  for (c20_i24 = 0; c20_i24 < 6; c20_i24 = c20_i24 + 1) {
    c20_b_u[c20_i24] = (*((real_T (*)[6])c20_u))[c20_i24];
  }

  for (c20_i25 = 0; c20_i25 < 6; c20_i25 = c20_i25 + 1) {
    c20_c_u[c20_i25] = c20_b_u[c20_i25];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_b_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  real_T c20_b_u;
  const mxArray *c20_b_y = NULL;
  SFc20_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc20_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c20_y = NULL;
  c20_b_u = *((real_T *)c20_u);
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_c_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i26;
  real_T c20_b_u[18];
  int32_T c20_i27;
  real_T c20_c_u[18];
  const mxArray *c20_b_y = NULL;
  SFc20_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc20_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c20_y = NULL;
  for (c20_i26 = 0; c20_i26 < 18; c20_i26 = c20_i26 + 1) {
    c20_b_u[c20_i26] = (*((real_T (*)[18])c20_u))[c20_i26];
  }

  for (c20_i27 = 0; c20_i27 < 18; c20_i27 = c20_i27 + 1) {
    c20_c_u[c20_i27] = c20_b_u[c20_i27];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 1, 18));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_d_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i28;
  real_T c20_b_u[6];
  int32_T c20_i29;
  real_T c20_c_u[6];
  const mxArray *c20_b_y = NULL;
  SFc20_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc20_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c20_y = NULL;
  for (c20_i28 = 0; c20_i28 < 6; c20_i28 = c20_i28 + 1) {
    c20_b_u[c20_i28] = (*((real_T (*)[6])c20_u))[c20_i28];
  }

  for (c20_i29 = 0; c20_i29 < 6; c20_i29 = c20_i29 + 1) {
    c20_c_u[c20_i29] = c20_b_u[c20_i29];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_e_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i30;
  real_T c20_b_u[8];
  int32_T c20_i31;
  real_T c20_c_u[8];
  const mxArray *c20_b_y = NULL;
  SFc20_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc20_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c20_y = NULL;
  for (c20_i30 = 0; c20_i30 < 8; c20_i30 = c20_i30 + 1) {
    c20_b_u[c20_i30] = (*((real_T (*)[8])c20_u))[c20_i30];
  }

  for (c20_i31 = 0; c20_i31 < 8; c20_i31 = c20_i31 + 1) {
    c20_c_u[c20_i31] = c20_b_u[c20_i31];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 1, 8));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

const mxArray *sf_c20_DynJointVerify_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_ResolvedFunctionInfo c20_info[31];
  const mxArray *c20_m0 = NULL;
  int32_T c20_i32;
  c20_ResolvedFunctionInfo *c20_r0;
  c20_nameCaptureInfo = NULL;
  c20_info_helper(c20_info);
  sf_mex_assign(&c20_m0, sf_mex_createstruct("nameCaptureInfo", 1, 31));
  for (c20_i32 = 0; c20_i32 < 31; c20_i32 = c20_i32 + 1) {
    c20_r0 = &c20_info[c20_i32];
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->context)), "context"
                    , "nameCaptureInfo", c20_i32);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->name)), "name",
                    "nameCaptureInfo", c20_i32);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      c20_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c20_i32);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->resolved)),
                    "resolved", "nameCaptureInfo", c20_i32);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c20_i32);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c20_i32);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c20_i32);
  }

  sf_mex_assign(&c20_nameCaptureInfo, c20_m0);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[31])
{
  c20_info[0].context = "";
  c20_info[0].name = "zeros";
  c20_info[0].dominantType = "double";
  c20_info[0].resolved = "[B]zeros";
  c20_info[0].fileLength = 0U;
  c20_info[0].fileTime1 = 0U;
  c20_info[0].fileTime2 = 0U;
  c20_info[1].context = "";
  c20_info[1].name = "ctranspose";
  c20_info[1].dominantType = "double";
  c20_info[1].resolved = "[B]ctranspose";
  c20_info[1].fileLength = 0U;
  c20_info[1].fileTime1 = 0U;
  c20_info[1].fileTime2 = 0U;
  c20_info[2].context = "";
  c20_info[2].name = "EulerNd";
  c20_info[2].dominantType = "double";
  c20_info[2].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[2].fileLength = 4648U;
  c20_info[2].fileTime1 = 1408089850U;
  c20_info[2].fileTime2 = 0U;
  c20_info[3].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[3].name = "plus";
  c20_info[3].dominantType = "double";
  c20_info[3].resolved = "[B]plus";
  c20_info[3].fileLength = 0U;
  c20_info[3].fileTime1 = 0U;
  c20_info[3].fileTime2 = 0U;
  c20_info[4].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[4].name = "sin";
  c20_info[4].dominantType = "double";
  c20_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[4].fileLength = 324U;
  c20_info[4].fileTime1 = 1203422842U;
  c20_info[4].fileTime2 = 0U;
  c20_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[5].name = "nargin";
  c20_info[5].dominantType = "";
  c20_info[5].resolved = "[B]nargin";
  c20_info[5].fileLength = 0U;
  c20_info[5].fileTime1 = 0U;
  c20_info[5].fileTime2 = 0U;
  c20_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[6].name = "gt";
  c20_info[6].dominantType = "double";
  c20_info[6].resolved = "[B]gt";
  c20_info[6].fileLength = 0U;
  c20_info[6].fileTime1 = 0U;
  c20_info[6].fileTime2 = 0U;
  c20_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[7].name = "isa";
  c20_info[7].dominantType = "double";
  c20_info[7].resolved = "[B]isa";
  c20_info[7].fileLength = 0U;
  c20_info[7].fileTime1 = 0U;
  c20_info[7].fileTime2 = 0U;
  c20_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[8].name = "eml_scalar_sin";
  c20_info[8].dominantType = "double";
  c20_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c20_info[8].fileLength = 601U;
  c20_info[8].fileTime1 = 1209309190U;
  c20_info[8].fileTime2 = 0U;
  c20_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c20_info[9].name = "isreal";
  c20_info[9].dominantType = "double";
  c20_info[9].resolved = "[B]isreal";
  c20_info[9].fileLength = 0U;
  c20_info[9].fileTime1 = 0U;
  c20_info[9].fileTime2 = 0U;
  c20_info[10].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[10].name = "cos";
  c20_info[10].dominantType = "double";
  c20_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c20_info[10].fileLength = 324U;
  c20_info[10].fileTime1 = 1203422750U;
  c20_info[10].fileTime2 = 0U;
  c20_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c20_info[11].name = "eml_scalar_cos";
  c20_info[11].dominantType = "double";
  c20_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c20_info[11].fileLength = 602U;
  c20_info[11].fileTime1 = 1209309186U;
  c20_info[11].fileTime2 = 0U;
  c20_info[12].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[12].name = "times";
  c20_info[12].dominantType = "double";
  c20_info[12].resolved = "[B]times";
  c20_info[12].fileLength = 0U;
  c20_info[12].fileTime1 = 0U;
  c20_info[12].fileTime2 = 0U;
  c20_info[13].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[13].name = "minus";
  c20_info[13].dominantType = "double";
  c20_info[13].resolved = "[B]minus";
  c20_info[13].fileLength = 0U;
  c20_info[13].fileTime1 = 0U;
  c20_info[13].fileTime2 = 0U;
  c20_info[14].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[14].name = "uminus";
  c20_info[14].dominantType = "double";
  c20_info[14].resolved = "[B]uminus";
  c20_info[14].fileLength = 0U;
  c20_info[14].fileTime1 = 0U;
  c20_info[14].fileTime2 = 0U;
  c20_info[15].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerNd.m";
  c20_info[15].name = "power";
  c20_info[15].dominantType = "double";
  c20_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[15].fileLength = 5380U;
  c20_info[15].fileTime1 = 1228068698U;
  c20_info[15].fileTime2 = 0U;
  c20_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[16].name = "isinteger";
  c20_info[16].dominantType = "double";
  c20_info[16].resolved = "[B]isinteger";
  c20_info[16].fileLength = 0U;
  c20_info[16].fileTime1 = 0U;
  c20_info[16].fileTime2 = 0U;
  c20_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[17].name = "eml_scalar_eg";
  c20_info[17].dominantType = "double";
  c20_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[17].fileLength = 3068U;
  c20_info[17].fileTime1 = 1240240410U;
  c20_info[17].fileTime2 = 0U;
  c20_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c20_info[18].name = "false";
  c20_info[18].dominantType = "";
  c20_info[18].resolved = "[B]false";
  c20_info[18].fileLength = 0U;
  c20_info[18].fileTime1 = 0U;
  c20_info[18].fileTime2 = 0U;
  c20_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[19].name = "isstruct";
  c20_info[19].dominantType = "double";
  c20_info[19].resolved = "[B]isstruct";
  c20_info[19].fileLength = 0U;
  c20_info[19].fileTime1 = 0U;
  c20_info[19].fileTime2 = 0U;
  c20_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c20_info[20].name = "eq";
  c20_info[20].dominantType = "double";
  c20_info[20].resolved = "[B]eq";
  c20_info[20].fileLength = 0U;
  c20_info[20].fileTime1 = 0U;
  c20_info[20].fileTime2 = 0U;
  c20_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c20_info[21].name = "class";
  c20_info[21].dominantType = "double";
  c20_info[21].resolved = "[B]class";
  c20_info[21].fileLength = 0U;
  c20_info[21].fileTime1 = 0U;
  c20_info[21].fileTime2 = 0U;
  c20_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c20_info[22].name = "cast";
  c20_info[22].dominantType = "double";
  c20_info[22].resolved = "[B]cast";
  c20_info[22].fileLength = 0U;
  c20_info[22].fileTime1 = 0U;
  c20_info[22].fileTime2 = 0U;
  c20_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[23].name = "eml_scalexp_alloc";
  c20_info[23].dominantType = "double";
  c20_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[23].fileLength = 932U;
  c20_info[23].fileTime1 = 1261926670U;
  c20_info[23].fileTime2 = 0U;
  c20_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[24].name = "isscalar";
  c20_info[24].dominantType = "double";
  c20_info[24].resolved = "[B]isscalar";
  c20_info[24].fileLength = 0U;
  c20_info[24].fileTime1 = 0U;
  c20_info[24].fileTime2 = 0U;
  c20_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[25].name = "not";
  c20_info[25].dominantType = "logical";
  c20_info[25].resolved = "[B]not";
  c20_info[25].fileLength = 0U;
  c20_info[25].fileTime1 = 0U;
  c20_info[25].fileTime2 = 0U;
  c20_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[26].name = "lt";
  c20_info[26].dominantType = "double";
  c20_info[26].resolved = "[B]lt";
  c20_info[26].fileLength = 0U;
  c20_info[26].fileTime1 = 0U;
  c20_info[26].fileTime2 = 0U;
  c20_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[27].name = "eml_scalar_floor";
  c20_info[27].dominantType = "double";
  c20_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c20_info[27].fileLength = 260U;
  c20_info[27].fileTime1 = 1209309190U;
  c20_info[27].fileTime2 = 0U;
  c20_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[28].name = "ne";
  c20_info[28].dominantType = "double";
  c20_info[28].resolved = "[B]ne";
  c20_info[28].fileLength = 0U;
  c20_info[28].fileTime1 = 0U;
  c20_info[28].fileTime2 = 0U;
  c20_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[29].name = "eml_error";
  c20_info[29].dominantType = "char";
  c20_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[29].fileLength = 315U;
  c20_info[29].fileTime1 = 1213905144U;
  c20_info[29].fileTime2 = 0U;
  c20_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[30].name = "strcmp";
  c20_info[30].dominantType = "char";
  c20_info[30].resolved = "[B]strcmp";
  c20_info[30].fileLength = 0U;
  c20_info[30].fileTime1 = 0U;
  c20_info[30].fileTime2 = 0U;
}

static const mxArray *c20_f_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  boolean_T c20_b_u;
  const mxArray *c20_b_y = NULL;
  SFc20_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc20_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c20_y = NULL;
  c20_b_u = *((boolean_T *)c20_u);
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static void c20_emlrt_marshallIn(SFc20_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c20_N, const char_T *c20_name,
  real_T c20_y[6])
{
  real_T c20_dv9[6];
  int32_T c20_i33;
  sf_mex_import(c20_name, sf_mex_dup(c20_N), c20_dv9, 1, 0, 0U, 1, 0U, 1, 6);
  for (c20_i33 = 0; c20_i33 < 6; c20_i33 = c20_i33 + 1) {
    c20_y[c20_i33] = c20_dv9[c20_i33];
  }

  sf_mex_destroy(&c20_N);
}

static uint8_T c20_b_emlrt_marshallIn(SFc20_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *
  c20_b_is_active_c20_DynJointVerify, const char_T *c20_name)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_name, sf_mex_dup(c20_b_is_active_c20_DynJointVerify),
                &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_b_is_active_c20_DynJointVerify);
  return c20_y;
}

static void init_dsm_address_info(SFc20_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c20_DynJointVerify_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1286719816U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3988846919U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(380000395U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1406471948U);
}

mxArray *sf_c20_DynJointVerify_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1744064622U);
    pr[1] = (double)(3927777049U);
    pr[2] = (double)(1474800011U);
    pr[3] = (double)(419924469U);
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
      pr[1] = (double)(8);
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

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c20_DynJointVerify(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"N\",},{M[8],M[0],T\"is_active_c20_DynJointVerify\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_DynJointVerify_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_DynJointVerifyInstanceStruct *chartInstance;
    chartInstance = (SFc20_DynJointVerifyInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_DynJointVerifyMachineNumber_,
           20,
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
          init_script_number_translation(_DynJointVerifyMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_DynJointVerifyMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_DynJointVerifyMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EnTheta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"N");
          _SFD_SET_DATA_PROPS(2,10,0,0,"L_EU");
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

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,107);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"EulerNd",0,-1,4516);
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
            1.0,0,0,(MexFcnForType)c20_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_e_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_c_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_d_sf_marshall);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshall);

        {
          real_T (*c20_EnTheta)[6];
          real_T (*c20_N)[6];
          c20_N = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c20_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c20_EnTheta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c20_N);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c20_L_EU);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c20_Cen);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c20_Ma);
          _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c20_Gravity);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_DynJointVerifyMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c20_DynJointVerify(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_DynJointVerifyInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
  initialize_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_DynJointVerify(void *chartInstanceVar)
{
  enable_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_DynJointVerify(void *chartInstanceVar)
{
  disable_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_DynJointVerify(void *chartInstanceVar)
{
  sf_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c20_DynJointVerify(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_DynJointVerify
    ((SFc20_DynJointVerifyInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c20_DynJointVerify();/* state var info */
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

static void sf_internal_set_sim_state_c20_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_DynJointVerify();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c20_DynJointVerify(SimStruct* S)
{
  return sf_internal_get_sim_state_c20_DynJointVerify(S);
}

static void sf_opaque_set_sim_state_c20_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c20_DynJointVerify(S, st);
}

static void sf_opaque_terminate_c20_DynJointVerify(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_DynJointVerifyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c20_DynJointVerify
    ((SFc20_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_DynJointVerify(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_DynJointVerify((SFc20_DynJointVerifyInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_DynJointVerify(SimStruct *S)
{
  /* Actual parameters from chart:
     Cen Gravity L_EU Ma
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Cen*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Gravity*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for L_EU*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for Ma*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"DynJointVerify","DynJointVerify",20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DynJointVerify","DynJointVerify",20,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DynJointVerify",
      "DynJointVerify",20,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DynJointVerify","DynJointVerify",20,
        1);
      sf_mark_chart_reusable_outputs(S,"DynJointVerify","DynJointVerify",20,1);
    }

    sf_set_rtw_dwork_info(S,"DynJointVerify","DynJointVerify",20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(157214331U));
  ssSetChecksum1(S,(756794425U));
  ssSetChecksum2(S,(667667050U));
  ssSetChecksum3(S,(3959535215U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c20_DynJointVerify(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DynJointVerify", "DynJointVerify",20);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_DynJointVerify(SimStruct *S)
{
  SFc20_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc20_DynJointVerifyInstanceStruct *)malloc(sizeof
    (SFc20_DynJointVerifyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_DynJointVerifyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_DynJointVerify;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_DynJointVerify;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_DynJointVerify;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c20_DynJointVerify;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c20_DynJointVerify;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_DynJointVerify;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_DynJointVerify;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_DynJointVerify;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_DynJointVerify;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_DynJointVerify;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_DynJointVerify;
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

void c20_DynJointVerify_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_DynJointVerify(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_DynJointVerify(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_DynJointVerify(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_DynJointVerify_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
