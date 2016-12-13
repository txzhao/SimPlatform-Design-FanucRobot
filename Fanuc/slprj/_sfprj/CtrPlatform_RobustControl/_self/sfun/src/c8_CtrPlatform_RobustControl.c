/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_RobustControl_sfun.h"
#include "c8_CtrPlatform_RobustControl.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_RobustControl_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c8_debug_family_names[6] = { "nargin", "nargout", "z", "r",
  "e", "w" };

/* Function Declarations */
static void initialize_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void initialize_params_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void enable_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void disable_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void set_sim_state_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_st);
static void finalize_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void sf_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void initSimStructsc8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static void c8_emlrt_marshallIn(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c8_w, const char_T *c8_identifier, real_T c8_y
  [6]);
static void c8_b_emlrt_marshallIn(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6]);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[23]);
static real_T c8_norm(SFc8_CtrPlatform_RobustControlInstanceStruct
                      *chartInstance, real_T c8_x[6]);
static void c8_eml_int_forloop_overflow_check
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_d_emlrt_marshallIn
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_e_emlrt_marshallIn
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_b_is_active_c8_CtrPlatform_RobustControl, const char_T *c8_identifier);
static uint8_T c8_f_emlrt_marshallIn
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_CtrPlatform_RobustControl = 0U;
}

static void initialize_params_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void enable_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_y = NULL;
  int32_T c8_i0;
  real_T c8_u[6];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T (*c8_w)[6];
  c8_w = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2), FALSE);
  for (c8_i0 = 0; c8_i0 < 6; c8_i0++) {
    c8_u[c8_i0] = (*c8_w)[c8_i0];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_hoistedGlobal = chartInstance->c8_is_active_c8_CtrPlatform_RobustControl;
  c8_b_u = c8_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y, FALSE);
  return c8_st;
}

static void set_sim_state_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv0[6];
  int32_T c8_i1;
  real_T (*c8_w)[6];
  c8_w = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)), "w",
                      c8_dv0);
  for (c8_i1 = 0; c8_i1 < 6; c8_i1++) {
    (*c8_w)[c8_i1] = c8_dv0[c8_i1];
  }

  chartInstance->c8_is_active_c8_CtrPlatform_RobustControl =
    c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
    "is_active_c8_CtrPlatform_RobustControl");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_CtrPlatform_RobustControl(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void sf_c8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  int32_T c8_i2;
  int32_T c8_i3;
  real_T c8_hoistedGlobal;
  real_T c8_b_hoistedGlobal;
  int32_T c8_i4;
  real_T c8_z[6];
  real_T c8_r;
  real_T c8_e;
  uint32_T c8_debug_family_var_map[6];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  real_T c8_w[6];
  int32_T c8_i5;
  real_T c8_b_z[6];
  real_T c8_A;
  int32_T c8_i6;
  real_T c8_c_z[6];
  real_T c8_B;
  real_T c8_x;
  real_T c8_y;
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_c_y;
  real_T c8_a;
  int32_T c8_i7;
  real_T c8_b[6];
  int32_T c8_i8;
  real_T c8_b_A;
  real_T c8_b_B;
  real_T c8_c_x;
  real_T c8_d_y;
  real_T c8_d_x;
  real_T c8_e_y;
  real_T c8_f_y;
  real_T c8_b_a;
  int32_T c8_i9;
  int32_T c8_i10;
  int32_T c8_i11;
  real_T *c8_b_e;
  real_T *c8_b_r;
  real_T (*c8_b_w)[6];
  real_T (*c8_d_z)[6];
  c8_b_e = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c8_b_w = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c8_d_z = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i2 = 0; c8_i2 < 6; c8_i2++) {
    _SFD_DATA_RANGE_CHECK((*c8_d_z)[c8_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c8_b_r, 1U);
  for (c8_i3 = 0; c8_i3 < 6; c8_i3++) {
    _SFD_DATA_RANGE_CHECK((*c8_b_w)[c8_i3], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c8_b_e, 3U);
  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  c8_hoistedGlobal = *c8_b_r;
  c8_b_hoistedGlobal = *c8_b_e;
  for (c8_i4 = 0; c8_i4 < 6; c8_i4++) {
    c8_z[c8_i4] = (*c8_d_z)[c8_i4];
  }

  c8_r = c8_hoistedGlobal;
  c8_e = c8_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c8_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargin, 0U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c8_nargout, 1U, c8_b_sf_marshallOut,
    c8_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c8_z, 2U, c8_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_r, 3U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c8_e, 4U, c8_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c8_w, 5U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 3);
  for (c8_i5 = 0; c8_i5 < 6; c8_i5++) {
    c8_b_z[c8_i5] = c8_z[c8_i5];
  }

  if (CV_EML_IF(0, 1, 0, c8_norm(chartInstance, c8_b_z) >= c8_e)) {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
    c8_A = c8_r;
    for (c8_i6 = 0; c8_i6 < 6; c8_i6++) {
      c8_c_z[c8_i6] = c8_z[c8_i6];
    }

    c8_B = c8_norm(chartInstance, c8_c_z);
    c8_x = c8_A;
    c8_y = c8_B;
    c8_b_x = c8_x;
    c8_b_y = c8_y;
    c8_c_y = c8_b_x / c8_b_y;
    c8_a = c8_c_y;
    for (c8_i7 = 0; c8_i7 < 6; c8_i7++) {
      c8_b[c8_i7] = c8_z[c8_i7];
    }

    for (c8_i8 = 0; c8_i8 < 6; c8_i8++) {
      c8_w[c8_i8] = c8_a * c8_b[c8_i8];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 6);
    c8_b_A = c8_r;
    c8_b_B = c8_e;
    c8_c_x = c8_b_A;
    c8_d_y = c8_b_B;
    c8_d_x = c8_c_x;
    c8_e_y = c8_d_y;
    c8_f_y = c8_d_x / c8_e_y;
    c8_b_a = c8_f_y;
    for (c8_i9 = 0; c8_i9 < 6; c8_i9++) {
      c8_b[c8_i9] = c8_z[c8_i9];
    }

    for (c8_i10 = 0; c8_i10 < 6; c8_i10++) {
      c8_w[c8_i10] = c8_b_a * c8_b[c8_i10];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -6);
  sf_debug_symbol_scope_pop();
  for (c8_i11 = 0; c8_i11 < 6; c8_i11++) {
    (*c8_b_w)[c8_i11] = c8_w[c8_i11];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_RobustControlMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc8_CtrPlatform_RobustControl
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_i12;
  real_T c8_b_inData[6];
  int32_T c8_i13;
  real_T c8_u[6];
  const mxArray *c8_y = NULL;
  SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  for (c8_i12 = 0; c8_i12 < 6; c8_i12++) {
    c8_b_inData[c8_i12] = (*(real_T (*)[6])c8_inData)[c8_i12];
  }

  for (c8_i13 = 0; c8_i13 < 6; c8_i13++) {
    c8_u[c8_i13] = c8_b_inData[c8_i13];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static void c8_emlrt_marshallIn(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c8_w, const char_T *c8_identifier, real_T c8_y
  [6])
{
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_w), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_w);
}

static void c8_b_emlrt_marshallIn(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId,
  real_T c8_y[6])
{
  real_T c8_dv1[6];
  int32_T c8_i14;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), c8_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c8_i14 = 0; c8_i14 < 6; c8_i14++) {
    c8_y[c8_i14] = c8_dv1[c8_i14];
  }

  sf_mex_destroy(&c8_u);
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_w;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y[6];
  int32_T c8_i15;
  SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c8_w = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_w), &c8_thisId, c8_y);
  sf_mex_destroy(&c8_w);
  for (c8_i15 = 0; c8_i15 < 6; c8_i15++) {
    (*(real_T (*)[6])c8_outData)[c8_i15] = c8_y[c8_i15];
  }

  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  real_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(real_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_y;
  real_T c8_d0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_y = c8_d0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_y;
  SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout), &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray *sf_c8_CtrPlatform_RobustControl_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo;
  c8_ResolvedFunctionInfo c8_info[23];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i16;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 23), FALSE);
  for (c8_i16 = 0; c8_i16 < 23; c8_i16++) {
    c8_r0 = &c8_info[c8_i16];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context", "nameCaptureInfo",
                    c8_i16);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name", "nameCaptureInfo", c8_i16);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c8_i16);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved", "nameCaptureInfo",
                    c8_i16);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c8_i16);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c8_i16);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c8_i16);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c8_i16);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c8_nameCaptureInfo);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[23])
{
  c8_info[0].context = "";
  c8_info[0].name = "norm";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[0].fileTimeLo = 1286797226U;
  c8_info[0].fileTimeHi = 0U;
  c8_info[0].mFileTimeLo = 0U;
  c8_info[0].mFileTimeHi = 0U;
  c8_info[1].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c8_info[1].name = "eml_index_class";
  c8_info[1].dominantType = "";
  c8_info[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[1].fileTimeLo = 1286797178U;
  c8_info[1].fileTimeHi = 0U;
  c8_info[1].mFileTimeLo = 0U;
  c8_info[1].mFileTimeHi = 0U;
  c8_info[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c8_info[2].name = "eml_xnrm2";
  c8_info[2].dominantType = "int32";
  c8_info[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c8_info[2].fileTimeLo = 1299051576U;
  c8_info[2].fileTimeHi = 0U;
  c8_info[2].mFileTimeLo = 0U;
  c8_info[2].mFileTimeHi = 0U;
  c8_info[3].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c8_info[3].name = "eml_blas_inline";
  c8_info[3].dominantType = "";
  c8_info[3].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c8_info[3].fileTimeLo = 1299051568U;
  c8_info[3].fileTimeHi = 0U;
  c8_info[3].mFileTimeLo = 0U;
  c8_info[3].mFileTimeHi = 0U;
  c8_info[4].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[4].name = "eml_refblas_xnrm2";
  c8_info[4].dominantType = "int32";
  c8_info[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[4].fileTimeLo = 1299051584U;
  c8_info[4].fileTimeHi = 0U;
  c8_info[4].mFileTimeLo = 0U;
  c8_info[4].mFileTimeHi = 0U;
  c8_info[5].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[5].name = "realmin";
  c8_info[5].dominantType = "char";
  c8_info[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[5].fileTimeLo = 1307629642U;
  c8_info[5].fileTimeHi = 0U;
  c8_info[5].mFileTimeLo = 0U;
  c8_info[5].mFileTimeHi = 0U;
  c8_info[6].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[6].name = "eml_realmin";
  c8_info[6].dominantType = "char";
  c8_info[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c8_info[6].fileTimeLo = 1307629644U;
  c8_info[6].fileTimeHi = 0U;
  c8_info[6].mFileTimeLo = 0U;
  c8_info[6].mFileTimeHi = 0U;
  c8_info[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c8_info[7].name = "eml_float_model";
  c8_info[7].dominantType = "char";
  c8_info[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c8_info[7].fileTimeLo = 1307629642U;
  c8_info[7].fileTimeHi = 0U;
  c8_info[7].mFileTimeLo = 0U;
  c8_info[7].mFileTimeHi = 0U;
  c8_info[8].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[8].name = "eml_index_class";
  c8_info[8].dominantType = "";
  c8_info[8].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[8].fileTimeLo = 1286797178U;
  c8_info[8].fileTimeHi = 0U;
  c8_info[8].mFileTimeLo = 0U;
  c8_info[8].mFileTimeHi = 0U;
  c8_info[9].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[9].name = "eml_index_minus";
  c8_info[9].dominantType = "int32";
  c8_info[9].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[9].fileTimeLo = 1286797178U;
  c8_info[9].fileTimeHi = 0U;
  c8_info[9].mFileTimeLo = 0U;
  c8_info[9].mFileTimeHi = 0U;
  c8_info[10].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[10].name = "eml_index_class";
  c8_info[10].dominantType = "";
  c8_info[10].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[10].fileTimeLo = 1286797178U;
  c8_info[10].fileTimeHi = 0U;
  c8_info[10].mFileTimeLo = 0U;
  c8_info[10].mFileTimeHi = 0U;
  c8_info[11].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[11].name = "eml_index_times";
  c8_info[11].dominantType = "int32";
  c8_info[11].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[11].fileTimeLo = 1286797180U;
  c8_info[11].fileTimeHi = 0U;
  c8_info[11].mFileTimeLo = 0U;
  c8_info[11].mFileTimeHi = 0U;
  c8_info[12].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[12].name = "eml_index_class";
  c8_info[12].dominantType = "";
  c8_info[12].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[12].fileTimeLo = 1286797178U;
  c8_info[12].fileTimeHi = 0U;
  c8_info[12].mFileTimeLo = 0U;
  c8_info[12].mFileTimeHi = 0U;
  c8_info[13].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[13].name = "eml_index_plus";
  c8_info[13].dominantType = "int32";
  c8_info[13].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[13].fileTimeLo = 1286797178U;
  c8_info[13].fileTimeHi = 0U;
  c8_info[13].mFileTimeLo = 0U;
  c8_info[13].mFileTimeHi = 0U;
  c8_info[14].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[14].name = "eml_index_class";
  c8_info[14].dominantType = "";
  c8_info[14].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[14].fileTimeLo = 1286797178U;
  c8_info[14].fileTimeHi = 0U;
  c8_info[14].mFileTimeLo = 0U;
  c8_info[14].mFileTimeHi = 0U;
  c8_info[15].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[15].name = "eml_int_forloop_overflow_check";
  c8_info[15].dominantType = "";
  c8_info[15].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c8_info[15].fileTimeLo = 1311233716U;
  c8_info[15].fileTimeHi = 0U;
  c8_info[15].mFileTimeLo = 0U;
  c8_info[15].mFileTimeHi = 0U;
  c8_info[16].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c8_info[16].name = "intmax";
  c8_info[16].dominantType = "char";
  c8_info[16].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[16].fileTimeLo = 1311233716U;
  c8_info[16].fileTimeHi = 0U;
  c8_info[16].mFileTimeLo = 0U;
  c8_info[16].mFileTimeHi = 0U;
  c8_info[17].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[17].name = "abs";
  c8_info[17].dominantType = "double";
  c8_info[17].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[17].fileTimeLo = 1286797094U;
  c8_info[17].fileTimeHi = 0U;
  c8_info[17].mFileTimeLo = 0U;
  c8_info[17].mFileTimeHi = 0U;
  c8_info[18].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[18].name = "eml_scalar_abs";
  c8_info[18].dominantType = "double";
  c8_info[18].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[18].fileTimeLo = 1286797112U;
  c8_info[18].fileTimeHi = 0U;
  c8_info[18].mFileTimeLo = 0U;
  c8_info[18].mFileTimeHi = 0U;
  c8_info[19].context = "";
  c8_info[19].name = "mrdivide";
  c8_info[19].dominantType = "double";
  c8_info[19].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[19].fileTimeLo = 1325098938U;
  c8_info[19].fileTimeHi = 0U;
  c8_info[19].mFileTimeLo = 1319708366U;
  c8_info[19].mFileTimeHi = 0U;
  c8_info[20].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[20].name = "rdivide";
  c8_info[20].dominantType = "double";
  c8_info[20].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[20].fileTimeLo = 1286797244U;
  c8_info[20].fileTimeHi = 0U;
  c8_info[20].mFileTimeLo = 0U;
  c8_info[20].mFileTimeHi = 0U;
  c8_info[21].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[21].name = "eml_div";
  c8_info[21].dominantType = "double";
  c8_info[21].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[21].fileTimeLo = 1313326210U;
  c8_info[21].fileTimeHi = 0U;
  c8_info[21].mFileTimeLo = 0U;
  c8_info[21].mFileTimeHi = 0U;
  c8_info[22].context = "";
  c8_info[22].name = "mtimes";
  c8_info[22].dominantType = "double";
  c8_info[22].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[22].fileTimeLo = 1289494492U;
  c8_info[22].fileTimeHi = 0U;
  c8_info[22].mFileTimeLo = 0U;
  c8_info[22].mFileTimeHi = 0U;
}

static real_T c8_norm(SFc8_CtrPlatform_RobustControlInstanceStruct
                      *chartInstance, real_T c8_x[6])
{
  real_T c8_y;
  real_T c8_scale;
  int32_T c8_k;
  int32_T c8_b_k;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_absxk;
  real_T c8_t;
  c8_y = 0.0;
  c8_scale = 2.2250738585072014E-308;
  c8_eml_int_forloop_overflow_check(chartInstance);
  for (c8_k = 1; c8_k < 7; c8_k++) {
    c8_b_k = c8_k;
    c8_b_x = c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c8_b_k), 1, 6, 1, 0) - 1];
    c8_c_x = c8_b_x;
    c8_absxk = muDoubleScalarAbs(c8_c_x);
    if (c8_absxk > c8_scale) {
      c8_t = c8_scale / c8_absxk;
      c8_y = 1.0 + c8_y * c8_t * c8_t;
      c8_scale = c8_absxk;
    } else {
      c8_t = c8_absxk / c8_scale;
      c8_y += c8_t * c8_t;
    }
  }

  return c8_scale * muDoubleScalarSqrt(c8_y);
}

static void c8_eml_int_forloop_overflow_check
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData = NULL;
  int32_T c8_u;
  const mxArray *c8_y = NULL;
  SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_u = *(int32_T *)c8_inData;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", &c8_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c8_mxArrayOutData, c8_y, FALSE);
  return c8_mxArrayOutData;
}

static int32_T c8_d_emlrt_marshallIn
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_y;
  int32_T c8_i17;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_i17, 1, 6, 0U, 0, 0U, 0);
  c8_y = c8_i17;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_y;
  SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_e_emlrt_marshallIn
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_b_is_active_c8_CtrPlatform_RobustControl, const char_T *c8_identifier)
{
  uint8_T c8_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_CtrPlatform_RobustControl), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_CtrPlatform_RobustControl);
  return c8_y;
}

static uint8_T c8_f_emlrt_marshallIn
  (SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c8_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_u), &c8_u0, 1, 3, 0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_u);
  return c8_y;
}

static void init_dsm_address_info(SFc8_CtrPlatform_RobustControlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_CtrPlatform_RobustControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2353300066U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2998042771U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3328351772U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(638527426U);
}

mxArray *sf_c8_CtrPlatform_RobustControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YSvRAseDXkZmFb1lvs0WAE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c8_CtrPlatform_RobustControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"w\",},{M[8],M[0],T\"is_active_c8_CtrPlatform_RobustControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_CtrPlatform_RobustControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
    chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_RobustControlMachineNumber_,
           8,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"z");
          _SFD_SET_DATA_PROPS(1,1,1,0,"r");
          _SFD_SET_DATA_PROPS(2,2,0,1,"w");
          _SFD_SET_DATA_PROPS(3,1,1,0,"e");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,95);
        _SFD_CV_INIT_EML_IF(0,1,0,33,46,68,91);
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
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)
            c8_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c8_r;
          real_T *c8_e;
          real_T (*c8_z)[6];
          real_T (*c8_w)[6];
          c8_e = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c8_w = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c8_r = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c8_z = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c8_z);
          _SFD_SET_DATA_VALUE_PTR(1U, c8_r);
          _SFD_SET_DATA_VALUE_PTR(2U, *c8_w);
          _SFD_SET_DATA_VALUE_PTR(3U, c8_e);
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
  return "revwX9PxPZkvXyD6dSrCiH";
}

static void sf_opaque_initialize_c8_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_CtrPlatform_RobustControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c8_CtrPlatform_RobustControl
    ((SFc8_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
  initialize_c8_CtrPlatform_RobustControl
    ((SFc8_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_CtrPlatform_RobustControl(void *chartInstanceVar)
{
  enable_c8_CtrPlatform_RobustControl
    ((SFc8_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  disable_c8_CtrPlatform_RobustControl
    ((SFc8_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  sf_c8_CtrPlatform_RobustControl((SFc8_CtrPlatform_RobustControlInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c8_CtrPlatform_RobustControl
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_CtrPlatform_RobustControl
    ((SFc8_CtrPlatform_RobustControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_CtrPlatform_RobustControl();/* state var info */
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

extern void sf_internal_set_sim_state_c8_CtrPlatform_RobustControl(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_CtrPlatform_RobustControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_CtrPlatform_RobustControl
    ((SFc8_CtrPlatform_RobustControlInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c8_CtrPlatform_RobustControl
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c8_CtrPlatform_RobustControl(S);
}

static void sf_opaque_set_sim_state_c8_CtrPlatform_RobustControl(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c8_CtrPlatform_RobustControl(S, st);
}

static void sf_opaque_terminate_c8_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_CtrPlatform_RobustControlInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_CtrPlatform_RobustControl
      ((SFc8_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_RobustControl_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_CtrPlatform_RobustControl
    ((SFc8_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_CtrPlatform_RobustControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_CtrPlatform_RobustControl
      ((SFc8_CtrPlatform_RobustControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_CtrPlatform_RobustControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CtrPlatform_RobustControl_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,8,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1307997304U));
  ssSetChecksum1(S,(2495908571U));
  ssSetChecksum2(S,(2287358076U));
  ssSetChecksum3(S,(4273872653U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_CtrPlatform_RobustControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_CtrPlatform_RobustControl(SimStruct *S)
{
  SFc8_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc8_CtrPlatform_RobustControlInstanceStruct *)malloc(sizeof
    (SFc8_CtrPlatform_RobustControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_CtrPlatform_RobustControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_CtrPlatform_RobustControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_CtrPlatform_RobustControl;
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

void c8_CtrPlatform_RobustControl_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_CtrPlatform_RobustControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_CtrPlatform_RobustControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_CtrPlatform_RobustControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_CtrPlatform_RobustControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
