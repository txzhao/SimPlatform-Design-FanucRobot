/* Include files */

#include "blascompat32.h"
#include "EulerPIDTunning_sfun.h"
#include "c5_EulerPIDTunning.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EulerPIDTunning_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c5_debug_family_names[21] = { "Ts", "ii", "lowfrq", "medfrq",
  "highfrq", "FrqSeries", "FrqLength", "AmpSeries", "sloptime", "PeriodSeries",
  "PeriodTime", "nargin", "nargout", "mytime", "TureAmp", "CounterIn", "Frq",
  "Amp", "PeriodFlag", "CounterOut", "Ramp" };

/* Function Declarations */
static void initialize_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance);
static void initialize_params_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance);
static void enable_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance);
static void disable_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance);
static void c5_update_debugger_state_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance);
static void set_sim_state_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct *
  chartInstance, const mxArray *c5_st);
static void finalize_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance);
static void sf_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance);
static void c5_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static void c5_logspace(SFc5_EulerPIDTunningInstanceStruct *chartInstance,
  real_T c5_d1, real_T c5_d2, real_T c5_y[50]);
static void c5_eml_warning(SFc5_EulerPIDTunningInstanceStruct *chartInstance);
static void c5_eml_scalar_eg(SFc5_EulerPIDTunningInstanceStruct *chartInstance);
static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u);
static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[72]);
static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u);
static real_T c5_emlrt_marshallIn(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance, const mxArray *c5_Amp, const char_T *c5_name);
static uint8_T c5_b_emlrt_marshallIn(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_EulerPIDTunning, const char_T
  *c5_name);
static void init_dsm_address_info(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_EulerPIDTunning = 0U;
}

static void initialize_params_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance)
{
}

static void enable_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance)
{
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_d_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_e_hoistedGlobal;
  real_T c5_e_u;
  const mxArray *c5_f_y = NULL;
  uint8_T c5_f_hoistedGlobal;
  uint8_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  real_T *c5_Amp;
  real_T *c5_CounterOut;
  real_T *c5_Frq;
  real_T *c5_PeriodFlag;
  real_T *c5_Ramp;
  c5_Ramp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_CounterOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_PeriodFlag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_Amp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_Frq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(6));
  c5_hoistedGlobal = *c5_Amp;
  c5_u = c5_hoistedGlobal;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_hoistedGlobal = *c5_CounterOut;
  c5_b_u = c5_b_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_hoistedGlobal = *c5_Frq;
  c5_c_u = c5_c_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 2, c5_d_y);
  c5_d_hoistedGlobal = *c5_PeriodFlag;
  c5_d_u = c5_d_hoistedGlobal;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 3, c5_e_y);
  c5_e_hoistedGlobal = *c5_Ramp;
  c5_e_u = c5_e_hoistedGlobal;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 4, c5_f_y);
  c5_f_hoistedGlobal = chartInstance->c5_is_active_c5_EulerPIDTunning;
  c5_f_u = c5_f_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 5, c5_g_y);
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct *
  chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_Amp;
  real_T *c5_CounterOut;
  real_T *c5_Frq;
  real_T *c5_PeriodFlag;
  real_T *c5_Ramp;
  c5_Ramp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_CounterOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_PeriodFlag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_Amp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_Frq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  *c5_Amp = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
    "Amp");
  *c5_CounterOut = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 1)), "CounterOut");
  *c5_Frq = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
    "Frq");
  *c5_PeriodFlag = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c5_u, 3)), "PeriodFlag");
  *c5_Ramp = c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u,
    4)), "Ramp");
  chartInstance->c5_is_active_c5_EulerPIDTunning = c5_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 5)),
     "is_active_c5_EulerPIDTunning");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_EulerPIDTunning(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance)
{
}

static void sf_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance)
{
  int32_T c5_previousEvent;
  real_T *c5_Frq;
  real_T *c5_Amp;
  real_T *c5_mytime;
  real_T *c5_PeriodFlag;
  real_T *c5_TureAmp;
  real_T *c5_CounterOut;
  real_T *c5_CounterIn;
  real_T *c5_Ramp;
  c5_Ramp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_CounterIn = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_CounterOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_TureAmp = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_PeriodFlag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_mytime = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_Amp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_Frq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3);
  _SFD_DATA_RANGE_CHECK(*c5_Frq, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_Amp, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_mytime, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_PeriodFlag, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_TureAmp, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_CounterOut, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_CounterIn, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_Ramp, 7U);
  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c5_c5_EulerPIDTunning(chartInstance);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_EulerPIDTunningMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_c5_EulerPIDTunning(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance)
{
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_mytime;
  real_T c5_TureAmp;
  real_T c5_CounterIn;
  uint32_T c5_debug_family_var_map[21];
  static const char *c5_sv0[21] = { "Ts", "ii", "lowfrq", "medfrq", "highfrq",
    "FrqSeries", "FrqLength", "AmpSeries", "sloptime",
    "PeriodSeries", "PeriodTime", "nargin", "nargout", "mytime", "TureAmp",
    "CounterIn", "Frq", "Amp"
    , "PeriodFlag", "CounterOut", "Ramp" };

  real_T c5_Ts;
  real_T c5_ii;
  real_T c5_lowfrq[50];
  real_T c5_medfrq[50];
  real_T c5_highfrq[20];
  real_T c5_FrqSeries[20];
  real_T c5_FrqLength;
  real_T c5_AmpSeries[20];
  real_T c5_sloptime;
  real_T c5_PeriodSeries[20];
  real_T c5_PeriodTime[20];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 5.0;
  real_T c5_Frq;
  real_T c5_Amp;
  real_T c5_PeriodFlag;
  real_T c5_CounterOut;
  real_T c5_Ramp;
  real_T c5_dv0[50];
  int32_T c5_i0;
  real_T c5_dv1[50];
  int32_T c5_i1;
  int32_T c5_i2;
  static real_T c5_dv2[20] = { 1000.0, 1037.1550444461916, 1075.6905862201827,
    1115.6579177615433, 1157.1102372827202,
    1200.102719578103, 1244.692589464024, 1290.9391979474051, 1338.9041012244718,
    1388.6511426146567,
    1440.2465375387587, 1493.7589616544865, 1549.2596422666556,
    1606.8224531337657, 1666.5240127970894,
    1728.4437865632108, 1792.6641922757124, 1859.2707100168125,
    1928.3519958849913, 2000.0000000000002 };

  int32_T c5_i3;
  real_T c5_mtmp;
  int32_T c5_ix;
  int32_T c5_k;
  int32_T c5_a;
  real_T c5_b_mtmp;
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  static real_T c5_dv3[20] = { 0.024, 0.02314022395061989, 0.022311248520201745,
    0.021511970307308545, 0.020741325438758527,
    0.01999828815356507, 0.019281869437605167, 0.018591115707199866,
    0.017925107539853834,
    0.0172829584504651, 0.016663813711375878, 0.016066849214693656,
    0.015491270375368859,
    0.014936311073568272, 0.014401232634937233, 0.013885322847392641,
    0.013387895013138518,
    0.012908287034642191, 0.012445860533354296, 0.011999999999999999 };

  real_T c5_b_a;
  real_T c5_b;
  real_T c5_y;
  real_T c5_A;
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_b_y;
  real_T c5_c_a;
  real_T *c5_b_Ramp;
  real_T *c5_b_CounterOut;
  real_T *c5_b_PeriodFlag;
  real_T *c5_b_Amp;
  real_T *c5_b_Frq;
  real_T *c5_b_CounterIn;
  real_T *c5_b_TureAmp;
  real_T *c5_b_mytime;
  c5_b_Ramp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c5_b_CounterIn = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_CounterOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c5_b_TureAmp = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_PeriodFlag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c5_b_mytime = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c5_b_Amp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_Frq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3);
  c5_hoistedGlobal = *c5_b_mytime;
  c5_b_hoistedGlobal = *c5_b_TureAmp;
  c5_c_hoistedGlobal = *c5_b_CounterIn;
  c5_mytime = c5_hoistedGlobal;
  c5_TureAmp = c5_b_hoistedGlobal;
  c5_CounterIn = c5_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 21U, 21U, c5_sv0, c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_Ts, c5_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c5_ii, c5_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c5_lowfrq, c5_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c5_medfrq, c5_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c5_highfrq, c5_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c5_FrqSeries, c5_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c5_FrqLength, c5_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c5_AmpSeries, c5_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c5_sloptime, c5_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c5_PeriodSeries, c5_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c5_PeriodTime, c5_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c5_nargin, c5_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c5_nargout, c5_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c5_mytime, c5_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c5_TureAmp, c5_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c5_CounterIn, c5_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c5_Frq, c5_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c5_Amp, c5_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c5_PeriodFlag, c5_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c5_CounterOut, c5_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c5_Ramp, c5_sf_marshall, 20U);
  CV_EML_FCN(0, 0);

  /*  This block supports an embeddable subset of the MATLAB language. */
  /*  See the help menu for details.  */
  _SFD_EML_CALL(0, 4);
  c5_Ts = 0.000125;
  _SFD_EML_CALL(0, 5);
  c5_ii = c5_CounterIn;

  /*  FrqSeries=[10:10:90 100:50:1950 2000:100:5000]; */
  _SFD_EML_CALL(0, 7);
  c5_logspace(chartInstance, 1.0, 2.0, c5_dv0);
  for (c5_i0 = 0; c5_i0 < 50; c5_i0 = c5_i0 + 1) {
    c5_lowfrq[c5_i0] = c5_dv0[c5_i0];
  }

  _SFD_EML_CALL(0, 8);
  c5_logspace(chartInstance, 2.0, 3.0, c5_dv1);
  for (c5_i1 = 0; c5_i1 < 50; c5_i1 = c5_i1 + 1) {
    c5_medfrq[c5_i1] = c5_dv1[c5_i1];
  }

  _SFD_EML_CALL(0, 9);
  for (c5_i2 = 0; c5_i2 < 20; c5_i2 = c5_i2 + 1) {
    c5_highfrq[c5_i2] = c5_dv2[c5_i2];
  }

  /*  FrqSeries=[lowfrq,medfrq(2:end),highfrq(2:end)]; */
  /*   FrqSeries=[medfrq highfrq(2:end)]; */
  /*   FrqSeries=lowfrq(10:50); */
  _SFD_EML_CALL(0, 13);
  for (c5_i3 = 0; c5_i3 < 20; c5_i3 = c5_i3 + 1) {
    c5_FrqSeries[c5_i3] = c5_dv2[c5_i3];
  }

  /*  AmpSeries = [0.8 2.5 5 5 repmat(5,[1 74])]; */
  _SFD_EML_CALL(0, 16);
  c5_mtmp = 1.0;
  c5_ix = 1;
  for (c5_k = 2; c5_k < 3; c5_k = c5_k + 1) {
    c5_a = c5_ix;
    c5_ix = c5_a + 1;
    if (1.0 + 19.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c5_ix), 1, 2, 1, 0) - 1) > c5_mtmp) {
      c5_mtmp = 1.0 + 19.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c5_ix), 1, 2, 1, 0) - 1);
    }
  }

  c5_b_mtmp = c5_mtmp;
  c5_FrqLength = c5_b_mtmp;
  _SFD_EML_CALL(0, 17);
  for (c5_i4 = 0; c5_i4 < 20; c5_i4 = c5_i4 + 1) {
    c5_AmpSeries[c5_i4] = 5.0;
  }

  /*  AmpSeries = [repmat(0.8,size(lowfrq)),repmat(5,size(medfrq(2:end))),repmat(5,size(highfrq(2:end)))]; */
  _SFD_EML_CALL(0, 20);
  c5_sloptime = 4.0;

  /* period */
  /*
     PeriodSeries=[repmat(20,size(lowfrq)),repmat(20,size(medfrq(2:end))),repmat(20,size(highfrq(2:end)))]+sloptime; % add 2 acc or dec period; */
  _SFD_EML_CALL(0, 22);
  for (c5_i5 = 0; c5_i5 < 20; c5_i5 = c5_i5 + 1) {
    c5_PeriodSeries[c5_i5] = 24.0;
  }

  _SFD_EML_CALL(0, 23);
  for (c5_i6 = 0; c5_i6 < 20; c5_i6 = c5_i6 + 1) {
    c5_PeriodTime[c5_i6] = c5_dv3[c5_i6];
  }

  _SFD_EML_CALL(0, 25);
  c5_PeriodFlag = 1.0;

  /*  chech whether the periodn of one frequence finish  */
  _SFD_EML_CALL(0, 26);
  c5_Frq = c5_FrqSeries[_SFD_EML_ARRAY_BOUNDS_CHECK("FrqSeries", (int32_T)
    _SFD_INTEGER_CHECK("ii", c5_ii), 1, 20, 1, 0) - 1];
  _SFD_EML_CALL(0, 27);
  c5_Amp = c5_AmpSeries[_SFD_EML_ARRAY_BOUNDS_CHECK("AmpSeries", (int32_T)
    _SFD_INTEGER_CHECK("ii", c5_ii), 1, 20, 1, 0) - 1];
  _SFD_EML_CALL(0, 28);
  c5_b_a = c5_Amp;
  c5_b = c5_Frq;
  c5_y = c5_b_a * c5_b;
  c5_A = c5_y;
  c5_x = c5_A;
  c5_b_x = c5_x;
  c5_c_x = c5_b_x;
  c5_b_y = c5_c_x / 4.0;
  c5_c_a = c5_b_y;
  c5_Ramp = c5_c_a * 0.000125;

  /*  calculate the ramp of Amp;  */
  _SFD_EML_CALL(0, 30);
  if (CV_EML_COND(0, 0, c5_mytime >= c5_PeriodTime[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "PeriodTime", (int32_T)_SFD_INTEGER_CHECK("ii", c5_ii),
        1, 20, 1, 0) - 1])) {
  } else if (CV_EML_COND(0, 1, c5_ii == c5_FrqLength)) {
  } else {
    CV_EML_MCDC(0, 0, FALSE);
    CV_EML_IF(0, 0, FALSE);
    _SFD_EML_CALL(0, 41);
    c5_PeriodFlag = 1.0;
    goto label_1;
  }

  CV_EML_MCDC(0, 0, TRUE);
  CV_EML_IF(0, 0, TRUE);
  _SFD_EML_CALL(0, 31);
  c5_Amp = 0.0;
  _SFD_EML_CALL(0, 32);
  if (CV_EML_IF(0, 1, c5_TureAmp <= 0.0)) {
    _SFD_EML_CALL(0, 33);
    c5_ii = c5_ii + 1.0;
    _SFD_EML_CALL(0, 34);
    if (CV_EML_IF(0, 2, c5_ii >= c5_FrqLength)) {
      _SFD_EML_CALL(0, 35);
      c5_ii = c5_FrqLength;
      _SFD_EML_CALL(0, 36);
      c5_Amp = 0.0;
    }

    _SFD_EML_CALL(0, 38);
    c5_PeriodFlag = 0.0;
  }

 label_1:
  ;
  _SFD_EML_CALL(0, 44);
  c5_CounterOut = c5_ii;
  _SFD_EML_CALL(0, -44);
  sf_debug_symbol_scope_pop();
  *c5_b_Frq = c5_Frq;
  *c5_b_Amp = c5_Amp;
  *c5_b_PeriodFlag = c5_PeriodFlag;
  *c5_b_CounterOut = c5_CounterOut;
  *c5_b_Ramp = c5_Ramp;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3);
}

static void compInitSubchartSimstructsFcn_c5_EulerPIDTunning
  (SFc5_EulerPIDTunningInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static void c5_logspace(SFc5_EulerPIDTunningInstanceStruct *chartInstance,
  real_T c5_d1, real_T c5_d2, real_T c5_y[50])
{
  real_T c5_x;
  real_T c5_b_x;
  real_T c5_b_y;
  real_T c5_b_d1;
  real_T c5_b_d2;
  real_T c5_c_y[50];
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_z;
  real_T c5_b;
  int32_T c5_i7;
  real_T c5_d_y[49];
  int32_T c5_i8;
  int32_T c5_i9;
  real_T c5_b_b[50];
  real_T c5_k;
  real_T c5_b_k;
  real_T c5_bk;
  c5_x = c5_d2 - 3.1415926535897931;
  c5_b_x = c5_x;
  c5_b_y = muDoubleScalarAbs(c5_b_x);
  if (c5_b_y < 8.8817841970012523E-16) {
    c5_eml_warning(chartInstance);
  }

  c5_b_d1 = c5_d1;
  c5_b_d2 = c5_d2;
  c5_eml_scalar_eg(chartInstance);
  c5_c_y[49] = c5_b_d2;
  c5_c_x = c5_b_d2 - c5_b_d1;
  c5_d_x = c5_c_x;
  c5_z = c5_d_x / 49.0;
  c5_b = c5_z;
  for (c5_i7 = 0; c5_i7 < 49; c5_i7 = c5_i7 + 1) {
    c5_d_y[c5_i7] = (real_T)c5_i7 * c5_b;
  }

  for (c5_i8 = 0; c5_i8 < 49; c5_i8 = c5_i8 + 1) {
    c5_c_y[c5_i8] = c5_b_d1 + c5_d_y[c5_i8];
  }

  for (c5_i9 = 0; c5_i9 < 50; c5_i9 = c5_i9 + 1) {
    c5_b_b[c5_i9] = c5_c_y[c5_i9];
  }

  for (c5_k = 1.0; c5_k <= 50.0; c5_k = c5_k + 1.0) {
    c5_b_k = c5_k;
    c5_bk = c5_b_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c5_b_k), 1, 50, 1, 0) - 1];
    c5_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c5_b_k),
      1, 50, 1, 0) - 1] = muDoubleScalarPower(10.0, c5_bk);
  }
}

static void c5_eml_warning(SFc5_EulerPIDTunningInstanceStruct *chartInstance)
{
  int32_T c5_i10;
  static char_T c5_cv0[33] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'i', 'S', 'p', 'e', 'c'
    , 'i', 'a', 'l', 'S', 'u', 'p', 'p', 'o', 'r', 't', 'e', 'd' };

  char_T c5_u[33];
  const mxArray *c5_y = NULL;
  int32_T c5_i11;
  static char_T c5_cv1[77] = { 'S', 'p', 'e', 'c', 'i', 'a', 'l', ' ', 'c', 'a',
    's', 'e', ' ', 'f', 'o', 'r', ' ', 'p', 'i', ' ', 'i'
    , 's', ' ', 'n', 'o', 't', ' ', 's', 'u', 'p', 'p', 'o', 'r', 't', 'e', 'd',
    '.', ' ', 'U', 's', 'e',
    ' ', 'l', 'o', 'g', 's', 'p', 'a', 'c', 'e', '(', 'a', ',', 'l', 'o', 'g',
    '1', '0', '(', 'p', 'i', ')'
    , ',', 'n', ')', ' ', 'i', 'f', ' ', 'd', 'e', 's', 'i', 'r', 'e', 'd', '.'
  };

  char_T c5_b_u[77];
  const mxArray *c5_b_y = NULL;
  for (c5_i10 = 0; c5_i10 < 33; c5_i10 = c5_i10 + 1) {
    c5_u[c5_i10] = c5_cv0[c5_i10];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 33));
  for (c5_i11 = 0; c5_i11 < 77; c5_i11 = c5_i11 + 1) {
    c5_b_u[c5_i11] = c5_cv1[c5_i11];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("warning", 0U, 2U, 14, c5_y, 14, c5_b_y);
}

static void c5_eml_scalar_eg(SFc5_EulerPIDTunningInstanceStruct *chartInstance)
{
}

static const mxArray *c5_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_EulerPIDTunningInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerPIDTunningInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_b_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i12;
  real_T c5_b_u[20];
  int32_T c5_i13;
  real_T c5_c_u[20];
  const mxArray *c5_b_y = NULL;
  SFc5_EulerPIDTunningInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerPIDTunningInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i12 = 0; c5_i12 < 20; c5_i12 = c5_i12 + 1) {
    c5_b_u[c5_i12] = (*((real_T (*)[20])c5_u))[c5_i12];
  }

  for (c5_i13 = 0; c5_i13 < 20; c5_i13 = c5_i13 + 1) {
    c5_c_u[c5_i13] = c5_b_u[c5_i13];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 1, 20));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static const mxArray *c5_c_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  int32_T c5_i14;
  real_T c5_b_u[50];
  int32_T c5_i15;
  real_T c5_c_u[50];
  const mxArray *c5_b_y = NULL;
  SFc5_EulerPIDTunningInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerPIDTunningInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  for (c5_i14 = 0; c5_i14 < 50; c5_i14 = c5_i14 + 1) {
    c5_b_u[c5_i14] = (*((real_T (*)[50])c5_u))[c5_i14];
  }

  for (c5_i15 = 0; c5_i15 < 50; c5_i15 = c5_i15 + 1) {
    c5_c_u[c5_i15] = c5_b_u[c5_i15];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 1, 50));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_EulerPIDTunning_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[72];
  c5_ResolvedFunctionInfo (*c5_b_info)[72];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i16;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  c5_b_info = (c5_ResolvedFunctionInfo (*)[72])c5_info;
  (*c5_b_info)[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c5_b_info)[64].name = "eml_index_class";
  (*c5_b_info)[64].dominantType = "";
  (*c5_b_info)[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c5_b_info)[64].fileLength = 909U;
  (*c5_b_info)[64].fileTime1 = 1192445182U;
  (*c5_b_info)[64].fileTime2 = 0U;
  (*c5_b_info)[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c5_b_info)[65].name = "isempty";
  (*c5_b_info)[65].dominantType = "double";
  (*c5_b_info)[65].resolved = "[B]isempty";
  (*c5_b_info)[65].fileLength = 0U;
  (*c5_b_info)[65].fileTime1 = 0U;
  (*c5_b_info)[65].fileTime2 = 0U;
  (*c5_b_info)[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c5_b_info)[66].name = "true";
  (*c5_b_info)[66].dominantType = "";
  (*c5_b_info)[66].resolved = "[B]true";
  (*c5_b_info)[66].fileLength = 0U;
  (*c5_b_info)[66].fileTime1 = 0U;
  (*c5_b_info)[66].fileTime2 = 0U;
  (*c5_b_info)[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub";
  (*c5_b_info)[67].name = "eml_index_plus";
  (*c5_b_info)[67].dominantType = "int32";
  (*c5_b_info)[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c5_b_info)[67].fileLength = 272U;
  (*c5_b_info)[67].fileTime1 = 1192445184U;
  (*c5_b_info)[67].fileTime2 = 0U;
  (*c5_b_info)[68].context = "";
  (*c5_b_info)[68].name = "repmat";
  (*c5_b_info)[68].dominantType = "double";
  (*c5_b_info)[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  (*c5_b_info)[68].fileLength = 3637U;
  (*c5_b_info)[68].fileTime1 = 1245080790U;
  (*c5_b_info)[68].fileTime2 = 0U;
  (*c5_b_info)[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  (*c5_b_info)[69].name = "eml_assert_valid_size_arg";
  (*c5_b_info)[69].dominantType = "double";
  (*c5_b_info)[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  (*c5_b_info)[69].fileLength = 3315U;
  (*c5_b_info)[69].fileTime1 = 1256367816U;
  (*c5_b_info)[69].fileTime2 = 0U;
  (*c5_b_info)[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  (*c5_b_info)[70].name = "isvector";
  (*c5_b_info)[70].dominantType = "double";
  (*c5_b_info)[70].resolved = "[B]isvector";
  (*c5_b_info)[70].fileLength = 0U;
  (*c5_b_info)[70].fileTime1 = 0U;
  (*c5_b_info)[70].fileTime2 = 0U;
  (*c5_b_info)[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m";
  (*c5_b_info)[71].name = "times";
  (*c5_b_info)[71].dominantType = "double";
  (*c5_b_info)[71].resolved = "[B]times";
  (*c5_b_info)[71].fileLength = 0U;
  (*c5_b_info)[71].fileTime1 = 0U;
  (*c5_b_info)[71].fileTime2 = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 72));
  for (c5_i16 = 0; c5_i16 < 72; c5_i16 = c5_i16 + 1) {
    c5_r0 = &c5_info[c5_i16];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c5_i16);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i16
                    );
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i16
                    );
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[72])
{
  c5_info[0].context = "";
  c5_info[0].name = "mrdivide";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[0].fileLength = 432U;
  c5_info[0].fileTime1 = 1277726622U;
  c5_info[0].fileTime2 = 0U;
  c5_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[1].name = "nargin";
  c5_info[1].dominantType = "";
  c5_info[1].resolved = "[B]nargin";
  c5_info[1].fileLength = 0U;
  c5_info[1].fileTime1 = 0U;
  c5_info[1].fileTime2 = 0U;
  c5_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[2].name = "ge";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved = "[B]ge";
  c5_info[2].fileLength = 0U;
  c5_info[2].fileTime1 = 0U;
  c5_info[2].fileTime2 = 0U;
  c5_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[3].name = "isscalar";
  c5_info[3].dominantType = "double";
  c5_info[3].resolved = "[B]isscalar";
  c5_info[3].fileLength = 0U;
  c5_info[3].fileTime1 = 0U;
  c5_info[3].fileTime2 = 0U;
  c5_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[4].name = "rdivide";
  c5_info[4].dominantType = "double";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[4].fileLength = 403U;
  c5_info[4].fileTime1 = 1245080820U;
  c5_info[4].fileTime2 = 0U;
  c5_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[5].name = "gt";
  c5_info[5].dominantType = "double";
  c5_info[5].resolved = "[B]gt";
  c5_info[5].fileLength = 0U;
  c5_info[5].fileTime1 = 0U;
  c5_info[5].fileTime2 = 0U;
  c5_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[6].name = "isa";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[B]isa";
  c5_info[6].fileLength = 0U;
  c5_info[6].fileTime1 = 0U;
  c5_info[6].fileTime2 = 0U;
  c5_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[7].name = "eml_div";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[7].fileLength = 4918U;
  c5_info[7].fileTime1 = 1267038210U;
  c5_info[7].fileTime2 = 0U;
  c5_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[8].name = "isinteger";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved = "[B]isinteger";
  c5_info[8].fileLength = 0U;
  c5_info[8].fileTime1 = 0U;
  c5_info[8].fileTime2 = 0U;
  c5_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c5_info[9].name = "isreal";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[B]isreal";
  c5_info[9].fileLength = 0U;
  c5_info[9].fileTime1 = 0U;
  c5_info[9].fileTime2 = 0U;
  c5_info[10].context = "";
  c5_info[10].name = "logspace";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[10].fileLength = 1073U;
  c5_info[10].fileTime1 = 1219731296U;
  c5_info[10].fileTime2 = 0U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[11].name = "lt";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[B]lt";
  c5_info[11].fileLength = 0U;
  c5_info[11].fileTime1 = 0U;
  c5_info[11].fileTime2 = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[12].name = "eml_scalar_floor";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[12].fileLength = 260U;
  c5_info[12].fileTime1 = 1209309190U;
  c5_info[12].fileTime2 = 0U;
  c5_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[13].name = "eq";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved = "[B]eq";
  c5_info[13].fileLength = 0U;
  c5_info[13].fileTime1 = 0U;
  c5_info[13].fileTime2 = 0U;
  c5_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[14].name = "pi";
  c5_info[14].dominantType = "";
  c5_info[14].resolved = "[B]pi";
  c5_info[14].fileLength = 0U;
  c5_info[14].fileTime1 = 0U;
  c5_info[14].fileTime2 = 0U;
  c5_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[15].name = "class";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved = "[B]class";
  c5_info[15].fileLength = 0U;
  c5_info[15].fileTime1 = 0U;
  c5_info[15].fileTime2 = 0U;
  c5_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[16].name = "cast";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved = "[B]cast";
  c5_info[16].fileLength = 0U;
  c5_info[16].fileTime1 = 0U;
  c5_info[16].fileTime2 = 0U;
  c5_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[17].name = "minus";
  c5_info[17].dominantType = "double";
  c5_info[17].resolved = "[B]minus";
  c5_info[17].fileLength = 0U;
  c5_info[17].fileTime1 = 0U;
  c5_info[17].fileTime2 = 0U;
  c5_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[18].name = "abs";
  c5_info[18].dominantType = "double";
  c5_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[18].fileLength = 566U;
  c5_info[18].fileTime1 = 1221245532U;
  c5_info[18].fileTime2 = 0U;
  c5_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[19].name = "ischar";
  c5_info[19].dominantType = "double";
  c5_info[19].resolved = "[B]ischar";
  c5_info[19].fileLength = 0U;
  c5_info[19].fileTime1 = 0U;
  c5_info[19].fileTime2 = 0U;
  c5_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[20].name = "islogical";
  c5_info[20].dominantType = "double";
  c5_info[20].resolved = "[B]islogical";
  c5_info[20].fileLength = 0U;
  c5_info[20].fileTime1 = 0U;
  c5_info[20].fileTime2 = 0U;
  c5_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[21].name = "size";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved = "[B]size";
  c5_info[21].fileLength = 0U;
  c5_info[21].fileTime1 = 0U;
  c5_info[21].fileTime2 = 0U;
  c5_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[22].name = "zeros";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved = "[B]zeros";
  c5_info[22].fileLength = 0U;
  c5_info[22].fileTime1 = 0U;
  c5_info[22].fileTime2 = 0U;
  c5_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[23].name = "eml_scalar_abs";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[23].fileLength = 461U;
  c5_info[23].fileTime1 = 1203422760U;
  c5_info[23].fileTime2 = 0U;
  c5_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[24].name = "eps";
  c5_info[24].dominantType = "char";
  c5_info[24].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[24].fileLength = 1331U;
  c5_info[24].fileTime1 = 1246588112U;
  c5_info[24].fileTime2 = 0U;
  c5_info[25].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[25].name = "eml_is_float_class";
  c5_info[25].dominantType = "char";
  c5_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[25].fileLength = 226U;
  c5_info[25].fileTime1 = 1197825240U;
  c5_info[25].fileTime2 = 0U;
  c5_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[26].name = "strcmp";
  c5_info[26].dominantType = "char";
  c5_info[26].resolved = "[B]strcmp";
  c5_info[26].fileLength = 0U;
  c5_info[26].fileTime1 = 0U;
  c5_info[26].fileTime2 = 0U;
  c5_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[27].name = "uminus";
  c5_info[27].dominantType = "double";
  c5_info[27].resolved = "[B]uminus";
  c5_info[27].fileLength = 0U;
  c5_info[27].fileTime1 = 0U;
  c5_info[27].fileTime2 = 0U;
  c5_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[28].name = "mtimes";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[28].fileLength = 3425U;
  c5_info[28].fileTime1 = 1251010272U;
  c5_info[28].fileTime2 = 0U;
  c5_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[29].name = "not";
  c5_info[29].dominantType = "logical";
  c5_info[29].resolved = "[B]not";
  c5_info[29].fileLength = 0U;
  c5_info[29].fileTime1 = 0U;
  c5_info[29].fileTime2 = 0U;
  c5_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[30].name = "eml_warning";
  c5_info[30].dominantType = "char";
  c5_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c5_info[30].fileLength = 262U;
  c5_info[30].fileTime1 = 1236232078U;
  c5_info[30].fileTime2 = 0U;
  c5_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/logspace.m";
  c5_info[31].name = "linspace";
  c5_info[31].dominantType = "double";
  c5_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c5_info[31].fileLength = 1040U;
  c5_info[31].fileTime1 = 1228068610U;
  c5_info[31].fileTime2 = 0U;
  c5_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c5_info[32].name = "eml_scalar_eg";
  c5_info[32].dominantType = "double";
  c5_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[32].fileLength = 3068U;
  c5_info[32].fileTime1 = 1240240410U;
  c5_info[32].fileTime2 = 0U;
  c5_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c5_info[33].name = "false";
  c5_info[33].dominantType = "";
  c5_info[33].resolved = "[B]false";
  c5_info[33].fileLength = 0U;
  c5_info[33].fileTime1 = 0U;
  c5_info[33].fileTime2 = 0U;
  c5_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[34].name = "isstruct";
  c5_info[34].dominantType = "double";
  c5_info[34].resolved = "[B]isstruct";
  c5_info[34].fileLength = 0U;
  c5_info[34].fileTime1 = 0U;
  c5_info[34].fileTime2 = 0U;
  c5_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c5_info[35].name = "plus";
  c5_info[35].dominantType = "double";
  c5_info[35].resolved = "[B]plus";
  c5_info[35].fileLength = 0U;
  c5_info[35].fileTime1 = 0U;
  c5_info[35].fileTime2 = 0U;
  c5_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/linspace.m";
  c5_info[36].name = "colon";
  c5_info[36].dominantType = "double";
  c5_info[36].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c5_info[36].fileLength = 8633U;
  c5_info[36].fileTime1 = 1273822662U;
  c5_info[36].fileTime2 = 0U;
  c5_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c5_info[37].name = "isfinite";
  c5_info[37].dominantType = "double";
  c5_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[37].fileLength = 364U;
  c5_info[37].fileTime1 = 1226552072U;
  c5_info[37].fileTime2 = 0U;
  c5_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[38].name = "isinf";
  c5_info[38].dominantType = "double";
  c5_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c5_info[38].fileLength = 541U;
  c5_info[38].fileTime1 = 1271383988U;
  c5_info[38].fileTime2 = 0U;
  c5_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[39].name = "isnan";
  c5_info[39].dominantType = "double";
  c5_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[39].fileLength = 541U;
  c5_info[39].fileTime1 = 1271383988U;
  c5_info[39].fileTime2 = 0U;
  c5_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m";
  c5_info[40].name = "and";
  c5_info[40].dominantType = "logical";
  c5_info[40].resolved = "[B]and";
  c5_info[40].fileLength = 0U;
  c5_info[40].fileTime1 = 0U;
  c5_info[40].fileTime2 = 0U;
  c5_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon";
  c5_info[41].name = "floor";
  c5_info[41].dominantType = "double";
  c5_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c5_info[41].fileLength = 332U;
  c5_info[41].fileTime1 = 1203422822U;
  c5_info[41].fileTime2 = 0U;
  c5_info[42].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[42].name = "real";
  c5_info[42].dominantType = "double";
  c5_info[42].resolved = "[B]real";
  c5_info[42].fileLength = 0U;
  c5_info[42].fileTime1 = 0U;
  c5_info[42].fileTime2 = 0U;
  c5_info[43].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[43].name = "int32";
  c5_info[43].dominantType = "double";
  c5_info[43].resolved = "[B]int32";
  c5_info[43].fileLength = 0U;
  c5_info[43].fileTime1 = 0U;
  c5_info[43].fileTime2 = 0U;
  c5_info[44].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[44].name = "realmin";
  c5_info[44].dominantType = "";
  c5_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c5_info[44].fileLength = 749U;
  c5_info[44].fileTime1 = 1226552078U;
  c5_info[44].fileTime2 = 0U;
  c5_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c5_info[45].name = "mpower";
  c5_info[45].dominantType = "double";
  c5_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[45].fileLength = 3710U;
  c5_info[45].fileTime1 = 1238412688U;
  c5_info[45].fileTime2 = 0U;
  c5_info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[46].name = "ndims";
  c5_info[46].dominantType = "double";
  c5_info[46].resolved = "[B]ndims";
  c5_info[46].fileLength = 0U;
  c5_info[46].fileTime1 = 0U;
  c5_info[46].fileTime2 = 0U;
  c5_info[47].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[47].name = "power";
  c5_info[47].dominantType = "double";
  c5_info[47].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[47].fileLength = 5380U;
  c5_info[47].fileTime1 = 1228068698U;
  c5_info[47].fileTime2 = 0U;
  c5_info[48].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[48].name = "eml_scalexp_alloc";
  c5_info[48].dominantType = "double";
  c5_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[48].fileLength = 932U;
  c5_info[48].fileTime1 = 1261926670U;
  c5_info[48].fileTime2 = 0U;
  c5_info[49].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[49].name = "ne";
  c5_info[49].dominantType = "double";
  c5_info[49].resolved = "[B]ne";
  c5_info[49].fileLength = 0U;
  c5_info[49].fileTime1 = 0U;
  c5_info[49].fileTime2 = 0U;
  c5_info[50].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c5_info[50].name = "eml_error";
  c5_info[50].dominantType = "char";
  c5_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c5_info[50].fileLength = 315U;
  c5_info[50].fileTime1 = 1213905144U;
  c5_info[50].fileTime2 = 0U;
  c5_info[51].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[51].name = "le";
  c5_info[51].dominantType = "double";
  c5_info[51].resolved = "[B]le";
  c5_info[51].fileLength = 0U;
  c5_info[51].fileTime1 = 0U;
  c5_info[51].fileTime2 = 0U;
  c5_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c5_info[52].name = "realmax";
  c5_info[52].dominantType = "char";
  c5_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m";
  c5_info[52].fileLength = 771U;
  c5_info[52].fileTime1 = 1226552076U;
  c5_info[52].fileTime2 = 0U;
  c5_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c5_info[53].name = "double";
  c5_info[53].dominantType = "double";
  c5_info[53].resolved = "[B]double";
  c5_info[53].fileLength = 0U;
  c5_info[53].fileTime1 = 0U;
  c5_info[53].fileTime2 = 0U;
  c5_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c5_info[54].name = "intmax";
  c5_info[54].dominantType = "";
  c5_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[54].fileLength = 1535U;
  c5_info[54].fileTime1 = 1192445128U;
  c5_info[54].fileTime2 = 0U;
  c5_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c5_info[55].name = "transpose";
  c5_info[55].dominantType = "double";
  c5_info[55].resolved = "[B]transpose";
  c5_info[55].fileLength = 0U;
  c5_info[55].fileTime1 = 0U;
  c5_info[55].fileTime2 = 0U;
  c5_info[56].context = "";
  c5_info[56].name = "log10";
  c5_info[56].dominantType = "double";
  c5_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m";
  c5_info[56].fileLength = 575U;
  c5_info[56].fileTime1 = 1203422826U;
  c5_info[56].fileTime2 = 0U;
  c5_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/log10.m";
  c5_info[57].name = "eml_scalar_log10";
  c5_info[57].dominantType = "double";
  c5_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log10.m";
  c5_info[57].fileLength = 587U;
  c5_info[57].fileTime1 = 1203422796U;
  c5_info[57].fileTime2 = 0U;
  c5_info[58].context = "";
  c5_info[58].name = "max";
  c5_info[58].dominantType = "double";
  c5_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c5_info[58].fileLength = 362U;
  c5_info[58].fileTime1 = 1245080760U;
  c5_info[58].fileTime2 = 0U;
  c5_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c5_info[59].name = "nargout";
  c5_info[59].dominantType = "";
  c5_info[59].resolved = "[B]nargout";
  c5_info[59].fileLength = 0U;
  c5_info[59].fileTime1 = 0U;
  c5_info[59].fileTime2 = 0U;
  c5_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c5_info[60].name = "eml_min_or_max";
  c5_info[60].dominantType = "char";
  c5_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[60].fileLength = 9967U;
  c5_info[60].fileTime1 = 1261926670U;
  c5_info[60].fileTime2 = 0U;
  c5_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[61].name = "isnumeric";
  c5_info[61].dominantType = "double";
  c5_info[61].resolved = "[B]isnumeric";
  c5_info[61].fileLength = 0U;
  c5_info[61].fileTime1 = 0U;
  c5_info[61].fileTime2 = 0U;
  c5_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[62].name = "eml_const_nonsingleton_dim";
  c5_info[62].dominantType = "double";
  c5_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c5_info[62].fileLength = 1473U;
  c5_info[62].fileTime1 = 1240240402U;
  c5_info[62].fileTime2 = 0U;
  c5_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[63].name = "ones";
  c5_info[63].dominantType = "double";
  c5_info[63].resolved = "[B]ones";
  c5_info[63].fileLength = 0U;
  c5_info[63].fileTime1 = 0U;
  c5_info[63].fileTime2 = 0U;
}

static const mxArray *c5_d_sf_marshall(void *chartInstanceVoid, void *c5_u)
{
  const mxArray *c5_y = NULL;
  boolean_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_EulerPIDTunningInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerPIDTunningInstanceStruct *)chartInstanceVoid;
  c5_y = NULL;
  c5_b_u = *((boolean_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

static real_T c5_emlrt_marshallIn(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance, const mxArray *c5_Amp, const char_T *c5_name)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_name, sf_mex_dup(c5_Amp), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_Amp);
  return c5_y;
}

static uint8_T c5_b_emlrt_marshallIn(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance, const mxArray *
  c5_b_is_active_c5_EulerPIDTunning, const char_T *c5_name)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_name, sf_mex_dup(c5_b_is_active_c5_EulerPIDTunning), &c5_u0,
                1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_b_is_active_c5_EulerPIDTunning);
  return c5_y;
}

static void init_dsm_address_info(SFc5_EulerPIDTunningInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_EulerPIDTunning_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4150053801U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2850520063U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(655005997U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3104348621U);
}

mxArray *sf_c5_EulerPIDTunning_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1392563160U);
    pr[1] = (double)(3346581682U);
    pr[2] = (double)(4123502345U);
    pr[3] = (double)(3269171438U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[1] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[1] = (double)(1);
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
      pr[1] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c5_EulerPIDTunning(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[5],T\"Amp\",},{M[1],M[9],T\"CounterOut\",},{M[1],M[4],T\"Frq\",},{M[1],M[7],T\"PeriodFlag\",},{M[1],M[11],T\"Ramp\",},{M[8],M[0],T\"is_active_c5_EulerPIDTunning\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_EulerPIDTunning_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_EulerPIDTunningInstanceStruct *chartInstance;
    chartInstance = (SFc5_EulerPIDTunningInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_EulerPIDTunningMachineNumber_,
           5,
           1,
           1,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_EulerPIDTunningMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_EulerPIDTunningMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_EulerPIDTunningMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,2,0,1,"Frq");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Amp");
          _SFD_SET_DATA_PROPS(2,1,1,0,"mytime");
          _SFD_SET_DATA_PROPS(3,2,0,1,"PeriodFlag");
          _SFD_SET_DATA_PROPS(4,1,1,0,"TureAmp");
          _SFD_SET_DATA_PROPS(5,2,0,1,"CounterOut");
          _SFD_SET_DATA_PROPS(6,1,1,0,"CounterIn");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Ramp");
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1411);
        _SFD_CV_INIT_EML_IF(0,0,1146,1191,1365,1393);
        _SFD_CV_INIT_EML_IF(0,1,1209,1223,-1,1364);
        _SFD_CV_INIT_EML_IF(0,2,1252,1270,-1,1332);

        {
          static int condStart[] = { 1149, 1176 };

          static int condEnd[] = { 1172, 1191 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,0,1149,1191,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_sf_marshall);

        {
          real_T *c5_Frq;
          real_T *c5_Amp;
          real_T *c5_mytime;
          real_T *c5_PeriodFlag;
          real_T *c5_TureAmp;
          real_T *c5_CounterOut;
          real_T *c5_CounterIn;
          real_T *c5_Ramp;
          c5_Ramp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c5_CounterIn = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c5_CounterOut = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c5_TureAmp = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c5_PeriodFlag = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c5_mytime = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c5_Amp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c5_Frq = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_Frq);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_Amp);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_mytime);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_PeriodFlag);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_TureAmp);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_CounterOut);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_CounterIn);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_Ramp);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_EulerPIDTunningMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_EulerPIDTunning(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_EulerPIDTunningInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*)
    chartInstanceVar);
  initialize_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_EulerPIDTunning(void *chartInstanceVar)
{
  enable_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_EulerPIDTunning(void *chartInstanceVar)
{
  disable_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_EulerPIDTunning(void *chartInstanceVar)
{
  sf_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c5_EulerPIDTunning(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_EulerPIDTunning
    ((SFc5_EulerPIDTunningInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c5_EulerPIDTunning();/* state var info */
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

static void sf_internal_set_sim_state_c5_EulerPIDTunning(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_EulerPIDTunning();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c5_EulerPIDTunning(SimStruct* S)
{
  return sf_internal_get_sim_state_c5_EulerPIDTunning(S);
}

static void sf_opaque_set_sim_state_c5_EulerPIDTunning(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_EulerPIDTunning(S, st);
}

static void sf_opaque_terminate_c5_EulerPIDTunning(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_EulerPIDTunningInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c5_EulerPIDTunning
    ((SFc5_EulerPIDTunningInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_EulerPIDTunning(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_EulerPIDTunning((SFc5_EulerPIDTunningInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_EulerPIDTunning(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EulerPIDTunning","EulerPIDTunning",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EulerPIDTunning","EulerPIDTunning",5,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"EulerPIDTunning",
      "EulerPIDTunning",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EulerPIDTunning","EulerPIDTunning",
        5,3);
      sf_mark_chart_reusable_outputs(S,"EulerPIDTunning","EulerPIDTunning",5,5);
    }

    sf_set_rtw_dwork_info(S,"EulerPIDTunning","EulerPIDTunning",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(137390625U));
  ssSetChecksum1(S,(2423329501U));
  ssSetChecksum2(S,(2793012521U));
  ssSetChecksum3(S,(3989477237U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_EulerPIDTunning(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EulerPIDTunning", "EulerPIDTunning",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_EulerPIDTunning(SimStruct *S)
{
  SFc5_EulerPIDTunningInstanceStruct *chartInstance;
  chartInstance = (SFc5_EulerPIDTunningInstanceStruct *)malloc(sizeof
    (SFc5_EulerPIDTunningInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_EulerPIDTunningInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_EulerPIDTunning;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_EulerPIDTunning;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_EulerPIDTunning;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_EulerPIDTunning;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_EulerPIDTunning;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_EulerPIDTunning;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_EulerPIDTunning;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_EulerPIDTunning;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_EulerPIDTunning;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_EulerPIDTunning;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_EulerPIDTunning;
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

void c5_EulerPIDTunning_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_EulerPIDTunning(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_EulerPIDTunning(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_EulerPIDTunning(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_EulerPIDTunning_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
