/* Include files */

#include "blascompat32.h"
#include "EulerPIDJoint_sfun.h"
#include "c4_EulerPIDJoint.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EulerPIDJoint_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0U)
#define c4_IN_ChechChange              (1U)
#define c4_IN_DealChange               (2U)

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void initialize_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance);
static void initialize_params_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct *
  chartInstance);
static void enable_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance);
static void disable_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance);
static void set_sim_state_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance);
static void finalize_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance);
static void sf_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u);
static const mxArray *c4_c_sf_marshall(void *chartInstanceVoid, void *c4_u);
static real_T c4_emlrt_marshallIn(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *c4_output, const char_T *c4_name);
static uint8_T c4_b_emlrt_marshallIn(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_EulerPIDJoint, const char_T
  *c4_name);
static const mxArray *c4_c_emlrt_marshallIn(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_name);
static void init_test_point_addr_map(SFc4_EulerPIDJointInstanceStruct
  *chartInstance);
static void **get_test_point_address_map(SFc4_EulerPIDJointInstanceStruct
  *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc4_EulerPIDJointInstanceStruct *chartInstance);
static void init_dsm_address_info(SFc4_EulerPIDJointInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance)
{
  real_T *c4_output;
  c4_output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_ChechChange = 0U;
  chartInstance->c4_tp_DealChange = 0U;
  chartInstance->c4_is_active_c4_EulerPIDJoint = 0U;
  chartInstance->c4_is_c4_EulerPIDJoint = 0U;
  chartInstance->c4_counter = 0.0;
  if (!(cdrGetOutputPortReusable(chartInstance->S, 1) != 0)) {
    *c4_output = 0.0;
  }
}

static void initialize_params_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct *
  chartInstance)
{
  real_T c4_d0;
  sf_set_error_prefix_string(
    "Stateflow Runtime Error (chart): Error evaluating data 'Ts' in the parent workspace.\n");
  sf_mex_import("Ts", sf_mex_get_sfun_param(chartInstance->S, 0, 0), &c4_d0, 0,
                0, 0U, 0, 0U, 0);
  chartInstance->c4_Ts = c4_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = sf_debug_get_animation();
  sf_debug_set_animation(0U);
  if ((int16_T)chartInstance->c4_is_active_c4_EulerPIDJoint == 1) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3);
  }

  if (chartInstance->c4_is_c4_EulerPIDJoint == c4_IN_ChechChange) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0);
  }

  if (chartInstance->c4_is_c4_EulerPIDJoint == c4_IN_DealChange) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1);
  }

  sf_debug_set_animation(c4_prevAniVal);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  uint8_T c4_d_hoistedGlobal;
  uint8_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  real_T *c4_output;
  c4_output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(4));
  c4_hoistedGlobal = *c4_output;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_counter;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = chartInstance->c4_is_active_c4_EulerPIDJoint;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_is_c4_EulerPIDJoint;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 3, c4_e_y);
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_output;
  c4_output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_u = sf_mex_dup(c4_st);
  *c4_output = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u,
    0)), "output");
  chartInstance->c4_counter = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "counter");
  chartInstance->c4_is_active_c4_EulerPIDJoint = c4_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
     "is_active_c4_EulerPIDJoint");
  chartInstance->c4_is_c4_EulerPIDJoint = c4_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c4_u, 3)),
    "is_c4_EulerPIDJoint");
  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 4)
    ), "setSimStateSideEffectsInfo"));
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_EulerPIDJoint(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_EulerPIDJoint == c4_IN_ChechChange) {
      chartInstance->c4_tp_ChechChange = 1U;
    } else {
      chartInstance->c4_tp_ChechChange = 0U;
    }

    if (chartInstance->c4_is_c4_EulerPIDJoint == c4_IN_DealChange) {
      chartInstance->c4_tp_DealChange = 1U;
    } else {
      chartInstance->c4_tp_DealChange = 0U;
    }

    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_c4_EulerPIDJoint(SFc4_EulerPIDJointInstanceStruct *chartInstance)
{
  int32_T c4_previousEvent;
  uint8_T *c4_change;
  real_T *c4_output;
  real_T *c4_frq;
  c4_frq = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_change = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_set_sim_state_side_effects_c4_EulerPIDJoint(chartInstance);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3);
  _SFD_DATA_RANGE_CHECK((real_T)*c4_change, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_output, 1U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_counter, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_frq, 3U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c4_Ts, 4U);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3);
  if ((int16_T)chartInstance->c4_is_active_c4_EulerPIDJoint == 0) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3);
    chartInstance->c4_is_active_c4_EulerPIDJoint = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0);
    chartInstance->c4_is_c4_EulerPIDJoint = c4_IN_ChechChange;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0);
    chartInstance->c4_tp_ChechChange = 1U;
    *c4_output = 1.0;
    _SFD_DATA_RANGE_CHECK(*c4_output, 1U);
    chartInstance->c4_counter = 0.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c4_counter, 2U);
  } else {
    switch (chartInstance->c4_is_c4_EulerPIDJoint) {
     case c4_IN_ChechChange:
      CV_CHART_EVAL(3, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1);
      if (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0, (int16_T)
            *c4_change == 1 != 0U)) != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 0);
        chartInstance->c4_tp_ChechChange = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
        chartInstance->c4_is_c4_EulerPIDJoint = c4_IN_DealChange;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1);
        chartInstance->c4_tp_DealChange = 1U;
        *c4_output = 0.0;
        _SFD_DATA_RANGE_CHECK(*c4_output, 1U);
        chartInstance->c4_counter = chartInstance->c4_counter + 1.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_counter, 2U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0);
      break;

     case c4_IN_DealChange:
      CV_CHART_EVAL(3, 0, 2);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2);
      if (CV_TRANSITION_EVAL(2U, (int32_T)_SFD_CCP_CALL(2U, 0,
            chartInstance->c4_counter >= 20.0 / *c4_frq / chartInstance->c4_Ts
            != 0U))
          != 0) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2);
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 1);
        chartInstance->c4_tp_DealChange = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1);
        chartInstance->c4_is_c4_EulerPIDJoint = c4_IN_ChechChange;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0);
        chartInstance->c4_tp_ChechChange = 1U;
        *c4_output = 1.0;
        _SFD_DATA_RANGE_CHECK(*c4_output, 1U);
        chartInstance->c4_counter = 0.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_counter, 2U);
      } else {
        chartInstance->c4_counter = chartInstance->c4_counter + 1.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c4_counter, 2U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1);
      break;

     default:
      CV_CHART_EVAL(3, 0, 0);
      chartInstance->c4_is_c4_EulerPIDJoint = (uint8_T)c4_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_EulerPIDJointMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c4_EulerPIDJoint
  (SFc4_EulerPIDJointInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

const mxArray *sf_c4_EulerPIDJoint_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1));
  return c4_nameCaptureInfo;
}

static const mxArray *c4_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  uint8_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_EulerPIDJointInstanceStruct *chartInstance;
  chartInstance = (SFc4_EulerPIDJointInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((uint8_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_b_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  boolean_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_EulerPIDJointInstanceStruct *chartInstance;
  chartInstance = (SFc4_EulerPIDJointInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((boolean_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static const mxArray *c4_c_sf_marshall(void *chartInstanceVoid, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  SFc4_EulerPIDJointInstanceStruct *chartInstance;
  chartInstance = (SFc4_EulerPIDJointInstanceStruct *)chartInstanceVoid;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

static real_T c4_emlrt_marshallIn(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *c4_output, const char_T *c4_name)
{
  real_T c4_y;
  real_T c4_d1;
  sf_mex_import(c4_name, sf_mex_dup(c4_output), &c4_d1, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d1;
  sf_mex_destroy(&c4_output);
  return c4_y;
}

static uint8_T c4_b_emlrt_marshallIn(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_EulerPIDJoint
  , const char_T *c4_name)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_name, sf_mex_dup(c4_b_is_active_c4_EulerPIDJoint), &c4_u0, 1,
                3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_b_is_active_c4_EulerPIDJoint);
  return c4_y;
}

static const mxArray *c4_c_emlrt_marshallIn(SFc4_EulerPIDJointInstanceStruct
  *chartInstance, const mxArray *
  c4_b_setSimStateSideEffectsInfo, const char_T *c4_name)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe
                (&c4_b_setSimStateSideEffectsInfo));
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static void init_test_point_addr_map(SFc4_EulerPIDJointInstanceStruct
  *chartInstance)
{
  chartInstance->c4_testPointAddrMap[0] = &chartInstance->c4_counter;
  chartInstance->c4_testPointAddrMap[1] = &chartInstance->c4_tp_ChechChange;
  chartInstance->c4_testPointAddrMap[2] = &chartInstance->c4_tp_DealChange;
}

static void **get_test_point_address_map(SFc4_EulerPIDJointInstanceStruct
  *chartInstance)
{
  return &chartInstance->c4_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc4_EulerPIDJointInstanceStruct *chartInstance)
{
  return &chartInstance->c4_testPointMappingInfo;
}

static void init_dsm_address_info(SFc4_EulerPIDJointInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static void init_test_point_mapping_info(SimStruct *S);
void sf_c4_EulerPIDJoint_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1840448977U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(181657477U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3377528520U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(146379221U);
}

mxArray *sf_c4_EulerPIDJoint_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1862145832U);
    pr[1] = (double)(2852951991U);
    pr[2] = (double)(1822236602U);
    pr[3] = (double)(3092189972U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c4_EulerPIDJoint(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[7],T\"output\",},{M[3],M[8],T\"counter\",},{M[8],M[0],T\"is_active_c4_EulerPIDJoint\",},{M[9],M[0],T\"is_c4_EulerPIDJoint\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_EulerPIDJoint_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_EulerPIDJointInstanceStruct *chartInstance;
    chartInstance = (SFc4_EulerPIDJointInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_EulerPIDJointMachineNumber_,
           4,
           2,
           3,
           5,
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
          init_script_number_translation(_EulerPIDJointMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_EulerPIDJointMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_EulerPIDJointMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"change");
          _SFD_SET_DATA_PROPS(1,2,0,1,"output");
          _SFD_SET_DATA_PROPS(2,0,0,0,"counter");
          _SFD_SET_DATA_PROPS(3,1,1,0,"frq");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Ts");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(2,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,0,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(1,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 12 };

          _SFD_TRANS_COV_MAPS(1,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_TRANS_COV_WTS(2,0,1,0,0);
        if (chartAlreadyPresent==0) {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 21 };

          _SFD_TRANS_COV_MAPS(2,
                              0,NULL,NULL,
                              1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),
                              0,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshall);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_c_sf_marshall);

        {
          uint8_T *c4_change;
          real_T *c4_output;
          real_T *c4_frq;
          c4_frq = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_output = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_change = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_change);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_output);
          _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c4_counter);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_frq);
          _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c4_Ts);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_EulerPIDJointMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_EulerPIDJoint(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_EulerPIDJointInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*)
    chartInstanceVar);
  initialize_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_EulerPIDJoint(void *chartInstanceVar)
{
  enable_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_EulerPIDJoint(void *chartInstanceVar)
{
  disable_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_EulerPIDJoint(void *chartInstanceVar)
{
  sf_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c4_EulerPIDJoint(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_EulerPIDJoint
    ((SFc4_EulerPIDJointInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c4_EulerPIDJoint();/* state var info */
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

static void sf_internal_set_sim_state_c4_EulerPIDJoint(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_EulerPIDJoint();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c4_EulerPIDJoint(SimStruct* S)
{
  return sf_internal_get_sim_state_c4_EulerPIDJoint(S);
}

static void sf_opaque_set_sim_state_c4_EulerPIDJoint(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c4_EulerPIDJoint(S, st);
}

static void sf_opaque_terminate_c4_EulerPIDJoint(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_EulerPIDJointInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*)
      chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c4_EulerPIDJoint
    ((SFc4_EulerPIDJointInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_EulerPIDJoint(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_EulerPIDJoint((SFc4_EulerPIDJointInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_EulerPIDJoint(SimStruct *S)
{
  /* Actual parameters from chart:
     Ts
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Ts*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EulerPIDJoint","EulerPIDJoint",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EulerPIDJoint","EulerPIDJoint",4,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"EulerPIDJoint",
      "EulerPIDJoint",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EulerPIDJoint","EulerPIDJoint",4,2);
      sf_mark_chart_reusable_outputs(S,"EulerPIDJoint","EulerPIDJoint",4,1);
    }

    sf_set_rtw_dwork_info(S,"EulerPIDJoint","EulerPIDJoint",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4222532184U));
  ssSetChecksum1(S,(1519013199U));
  ssSetChecksum2(S,(2015092932U));
  ssSetChecksum3(S,(707358281U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_EulerPIDJoint(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EulerPIDJoint", "EulerPIDJoint",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_EulerPIDJoint(SimStruct *S)
{
  SFc4_EulerPIDJointInstanceStruct *chartInstance;
  chartInstance = (SFc4_EulerPIDJointInstanceStruct *)malloc(sizeof
    (SFc4_EulerPIDJointInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_EulerPIDJointInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_EulerPIDJoint;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_EulerPIDJoint;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_EulerPIDJoint;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_EulerPIDJoint;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_EulerPIDJoint;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_EulerPIDJoint;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_EulerPIDJoint;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_EulerPIDJoint;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_EulerPIDJoint;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_EulerPIDJoint;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_EulerPIDJoint;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c4_EulerPIDJoint_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_EulerPIDJoint(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_EulerPIDJoint(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_EulerPIDJoint(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_EulerPIDJoint_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "real_T", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/counter", "counter", 0, 0, 0, 0, 0 },

  { 1, 0, "StateflowChart/ChechChange", "ChechChange", 0, 1, 0, 0, 0 },

  { 2, 0, "StateflowChart/DealChange", "DealChange", 0, 1, 0, 0, 0 } };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    3                                  /* Num Block IO signals */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float"
};

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc4_EulerPIDJointInstanceStruct *chartInstance;
  chartInstance = (SFc4_EulerPIDJointInstanceStruct *) ((ChartInfoStruct *)
    (ssGetUserData(S)))->chartInstance;
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
}
