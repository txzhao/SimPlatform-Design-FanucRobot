/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_RobustControl_sfun.h"
#include "c9_CtrPlatform_RobustControl.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_RobustControl_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[5] = { "u", "nargin", "nargout", "B",
  "Bhat" };

/* Function Declarations */
static void initialize_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void initialize_params_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void enable_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void disable_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void set_sim_state_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_st);
static void finalize_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void sf_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void initSimStructsc9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_Bhat, const char_T *c9_identifier, real_T
  c9_y[36]);
static void c9_b_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[36]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_d_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[19]);
static void c9_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_e_emlrt_marshallIn
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_f_emlrt_marshallIn
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_b_is_active_c9_CtrPlatform_RobustControl, const char_T *c9_identifier);
static uint8_T c9_g_emlrt_marshallIn
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_CtrPlatform_RobustControl = 0U;
}

static void initialize_params_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void enable_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[36];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T (*c9_Bhat)[36];
  c9_Bhat = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2), FALSE);
  for (c9_i0 = 0; c9_i0 < 36; c9_i0++) {
    c9_u[c9_i0] = (*c9_Bhat)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_CtrPlatform_RobustControl;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[36];
  int32_T c9_i1;
  real_T (*c9_Bhat)[36];
  c9_Bhat = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)), "Bhat",
                      c9_dv0);
  for (c9_i1 = 0; c9_i1 < 36; c9_i1++) {
    (*c9_Bhat)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_is_active_c9_CtrPlatform_RobustControl =
    c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
    "is_active_c9_CtrPlatform_RobustControl");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_CtrPlatform_RobustControl(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void sf_c9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  real_T c9_B[36];
  uint32_T c9_debug_family_var_map[5];
  real_T c9_u[6];
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_Bhat[36];
  int32_T c9_i5;
  real_T c9_v[36];
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  real_T c9_b_v[6];
  int32_T c9_i9;
  int32_T c9_j;
  int32_T c9_b_j;
  int32_T c9_a;
  int32_T c9_c;
  int32_T c9_i10;
  real_T (*c9_b_Bhat)[36];
  real_T (*c9_b_B)[36];
  c9_b_Bhat = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_B = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 36; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_B)[c9_i2], 0U);
  }

  for (c9_i3 = 0; c9_i3 < 36; c9_i3++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_Bhat)[c9_i3], 1U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  for (c9_i4 = 0; c9_i4 < 36; c9_i4++) {
    c9_B[c9_i4] = (*c9_b_B)[c9_i4];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c9_u, 0U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 2U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c9_B, 3U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c9_Bhat, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  for (c9_i5 = 0; c9_i5 < 36; c9_i5++) {
    c9_v[c9_i5] = c9_B[c9_i5];
  }

  c9_i6 = 0;
  for (c9_i7 = 0; c9_i7 < 6; c9_i7++) {
    c9_u[c9_i7] = c9_v[c9_i6];
    c9_i6 += 7;
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  for (c9_i8 = 0; c9_i8 < 6; c9_i8++) {
    c9_b_v[c9_i8] = c9_u[c9_i8];
  }

  for (c9_i9 = 0; c9_i9 < 36; c9_i9++) {
    c9_Bhat[c9_i9] = 0.0;
  }

  c9_eml_int_forloop_overflow_check(chartInstance);
  for (c9_j = 1; c9_j < 7; c9_j++) {
    c9_b_j = c9_j;
    c9_a = c9_b_j;
    c9_c = c9_a;
    c9_Bhat[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c9_b_j), 1, 6, 1, 0) + 6 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
               "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_c), 1, 6, 2, 0) -
              1)) - 1] = c9_b_v[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c9_b_j), 1, 6, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c9_i10 = 0; c9_i10 < 36; c9_i10++) {
    (*c9_b_Bhat)[c9_i10] = c9_Bhat[c9_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c9_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_RobustControlMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc9_CtrPlatform_RobustControl
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  real_T c9_b_inData[36];
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  real_T c9_u[36];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i11 = 0;
  for (c9_i12 = 0; c9_i12 < 6; c9_i12++) {
    for (c9_i13 = 0; c9_i13 < 6; c9_i13++) {
      c9_b_inData[c9_i13 + c9_i11] = (*(real_T (*)[36])c9_inData)[c9_i13 +
        c9_i11];
    }

    c9_i11 += 6;
  }

  c9_i14 = 0;
  for (c9_i15 = 0; c9_i15 < 6; c9_i15++) {
    for (c9_i16 = 0; c9_i16 < 6; c9_i16++) {
      c9_u[c9_i16 + c9_i14] = c9_b_inData[c9_i16 + c9_i14];
    }

    c9_i14 += 6;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 6, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_Bhat, const char_T *c9_identifier, real_T
  c9_y[36])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Bhat), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Bhat);
}

static void c9_b_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[36])
{
  real_T c9_dv1[36];
  int32_T c9_i17;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 2, 6, 6);
  for (c9_i17 = 0; c9_i17 < 36; c9_i17++) {
    c9_y[c9_i17] = c9_dv1[c9_i17];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_Bhat;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[36];
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T c9_i20;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c9_Bhat = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_Bhat), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_Bhat);
  c9_i18 = 0;
  for (c9_i19 = 0; c9_i19 < 6; c9_i19++) {
    for (c9_i20 = 0; c9_i20 < 6; c9_i20++) {
      (*(real_T (*)[36])c9_outData)[c9_i20 + c9_i18] = c9_y[c9_i20 + c9_i18];
    }

    c9_i18 += 6;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i21;
  real_T c9_b_inData[6];
  int32_T c9_i22;
  real_T c9_u[6];
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
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

static void c9_d_emlrt_marshallIn(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6])
{
  real_T c9_dv2[6];
  int32_T c9_i23;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv2, 1, 0, 0U, 1, 0U, 1, 6);
  for (c9_i23 = 0; c9_i23 < 6; c9_i23++) {
    c9_y[c9_i23] = c9_dv2[c9_i23];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_u;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[6];
  int32_T c9_i24;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c9_u = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_u), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_u);
  for (c9_i24 = 0; c9_i24 < 6; c9_i24++) {
    (*(real_T (*)[6])c9_outData)[c9_i24] = c9_y[c9_i24];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_CtrPlatform_RobustControl_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[19];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i25;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 19), FALSE);
  for (c9_i25 = 0; c9_i25 < 19; c9_i25++) {
    c9_r0 = &c9_info[c9_i25];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i25);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i25);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i25);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i25);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i25);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i25);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i25);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i25);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[19])
{
  c9_info[0].context = "";
  c9_info[0].name = "diag";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[0].fileTimeLo = 1286797086U;
  c9_info[0].fileTimeHi = 0U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[1].name = "eml_index_class";
  c9_info[1].dominantType = "";
  c9_info[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[1].fileTimeLo = 1286797178U;
  c9_info[1].fileTimeHi = 0U;
  c9_info[1].mFileTimeLo = 0U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[2].name = "eml_index_plus";
  c9_info[2].dominantType = "int32";
  c9_info[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[2].fileTimeLo = 1286797178U;
  c9_info[2].fileTimeHi = 0U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[3].name = "eml_index_class";
  c9_info[3].dominantType = "";
  c9_info[3].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[3].fileTimeLo = 1286797178U;
  c9_info[3].fileTimeHi = 0U;
  c9_info[3].mFileTimeLo = 0U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[4].name = "eml_index_times";
  c9_info[4].dominantType = "int32";
  c9_info[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[4].fileTimeLo = 1286797180U;
  c9_info[4].fileTimeHi = 0U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[5].name = "eml_index_class";
  c9_info[5].dominantType = "";
  c9_info[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[5].fileTimeLo = 1286797178U;
  c9_info[5].fileTimeHi = 0U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[6].name = "eml_index_minus";
  c9_info[6].dominantType = "int32";
  c9_info[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[6].fileTimeLo = 1286797178U;
  c9_info[6].fileTimeHi = 0U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[7].name = "eml_index_class";
  c9_info[7].dominantType = "";
  c9_info[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[7].fileTimeLo = 1286797178U;
  c9_info[7].fileTimeHi = 0U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[8].name = "min";
  c9_info[8].dominantType = "int32";
  c9_info[8].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[8].fileTimeLo = 1311233718U;
  c9_info[8].fileTimeHi = 0U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[9].name = "eml_min_or_max";
  c9_info[9].dominantType = "int32";
  c9_info[9].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[9].fileTimeLo = 1303124612U;
  c9_info[9].fileTimeHi = 0U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[10].name = "eml_scalar_eg";
  c9_info[10].dominantType = "int32";
  c9_info[10].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[10].fileTimeLo = 1286797196U;
  c9_info[10].fileTimeHi = 0U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[11].name = "eml_scalexp_alloc";
  c9_info[11].dominantType = "int32";
  c9_info[11].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[11].fileTimeLo = 1286797196U;
  c9_info[11].fileTimeHi = 0U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[12].name = "eml_index_class";
  c9_info[12].dominantType = "";
  c9_info[12].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[12].fileTimeLo = 1286797178U;
  c9_info[12].fileTimeHi = 0U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
  c9_info[13].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c9_info[13].name = "eml_scalar_eg";
  c9_info[13].dominantType = "int32";
  c9_info[13].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[13].fileTimeLo = 1286797196U;
  c9_info[13].fileTimeHi = 0U;
  c9_info[13].mFileTimeLo = 0U;
  c9_info[13].mFileTimeHi = 0U;
  c9_info[14].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[14].name = "floor";
  c9_info[14].dominantType = "double";
  c9_info[14].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c9_info[14].fileTimeLo = 1286797142U;
  c9_info[14].fileTimeHi = 0U;
  c9_info[14].mFileTimeLo = 0U;
  c9_info[14].mFileTimeHi = 0U;
  c9_info[15].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c9_info[15].name = "eml_scalar_floor";
  c9_info[15].dominantType = "double";
  c9_info[15].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c9_info[15].fileTimeLo = 1286797126U;
  c9_info[15].fileTimeHi = 0U;
  c9_info[15].mFileTimeLo = 0U;
  c9_info[15].mFileTimeHi = 0U;
  c9_info[16].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[16].name = "eml_scalar_eg";
  c9_info[16].dominantType = "double";
  c9_info[16].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[16].fileTimeLo = 1286797196U;
  c9_info[16].fileTimeHi = 0U;
  c9_info[16].mFileTimeLo = 0U;
  c9_info[16].mFileTimeHi = 0U;
  c9_info[17].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/diag.m";
  c9_info[17].name = "eml_int_forloop_overflow_check";
  c9_info[17].dominantType = "";
  c9_info[17].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c9_info[17].fileTimeLo = 1311233716U;
  c9_info[17].fileTimeHi = 0U;
  c9_info[17].mFileTimeLo = 0U;
  c9_info[17].mFileTimeHi = 0U;
  c9_info[18].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c9_info[18].name = "intmax";
  c9_info[18].dominantType = "char";
  c9_info[18].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c9_info[18].fileTimeLo = 1311233716U;
  c9_info[18].fileTimeHi = 0U;
  c9_info[18].mFileTimeLo = 0U;
  c9_info[18].mFileTimeHi = 0U;
}

static void c9_eml_int_forloop_overflow_check
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance)
{
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_e_emlrt_marshallIn
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i26;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i26, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i26;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
    chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_f_emlrt_marshallIn
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_b_is_active_c9_CtrPlatform_RobustControl, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_CtrPlatform_RobustControl), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_CtrPlatform_RobustControl);
  return c9_y;
}

static uint8_T c9_g_emlrt_marshallIn
  (SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance, const mxArray
   *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_CtrPlatform_RobustControlInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c9_CtrPlatform_RobustControl_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3279301026U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3291130911U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(134976438U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(91648066U);
}

mxArray *sf_c9_CtrPlatform_RobustControl_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xr4EK7k6VJCMxI7zSbnoyC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c9_CtrPlatform_RobustControl(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Bhat\",},{M[8],M[0],T\"is_active_c9_CtrPlatform_RobustControl\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_CtrPlatform_RobustControl_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
    chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_RobustControlMachineNumber_,
           9,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"B");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Bhat");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,63);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          real_T (*c9_B)[36];
          real_T (*c9_Bhat)[36];
          c9_Bhat = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
          c9_B = (real_T (*)[36])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_B);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_Bhat);
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
  return "x3oNZy5EFH5fzuvIvpnwbB";
}

static void sf_opaque_initialize_c9_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_CtrPlatform_RobustControlInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_CtrPlatform_RobustControl
    ((SFc9_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
  initialize_c9_CtrPlatform_RobustControl
    ((SFc9_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_CtrPlatform_RobustControl(void *chartInstanceVar)
{
  enable_c9_CtrPlatform_RobustControl
    ((SFc9_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  disable_c9_CtrPlatform_RobustControl
    ((SFc9_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  sf_c9_CtrPlatform_RobustControl((SFc9_CtrPlatform_RobustControlInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_CtrPlatform_RobustControl
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_CtrPlatform_RobustControl
    ((SFc9_CtrPlatform_RobustControlInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CtrPlatform_RobustControl();/* state var info */
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

extern void sf_internal_set_sim_state_c9_CtrPlatform_RobustControl(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_CtrPlatform_RobustControl();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_CtrPlatform_RobustControl
    ((SFc9_CtrPlatform_RobustControlInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_CtrPlatform_RobustControl
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c9_CtrPlatform_RobustControl(S);
}

static void sf_opaque_set_sim_state_c9_CtrPlatform_RobustControl(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c9_CtrPlatform_RobustControl(S, st);
}

static void sf_opaque_terminate_c9_CtrPlatform_RobustControl(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_CtrPlatform_RobustControlInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_CtrPlatform_RobustControl
      ((SFc9_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_RobustControl_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_CtrPlatform_RobustControl
    ((SFc9_CtrPlatform_RobustControlInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_CtrPlatform_RobustControl(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_CtrPlatform_RobustControl
      ((SFc9_CtrPlatform_RobustControlInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_CtrPlatform_RobustControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_CtrPlatform_RobustControl_optimization_info();
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
  ssSetChecksum0(S,(1941714080U));
  ssSetChecksum1(S,(1601661659U));
  ssSetChecksum2(S,(2674794229U));
  ssSetChecksum3(S,(2489018648U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_CtrPlatform_RobustControl(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_CtrPlatform_RobustControl(SimStruct *S)
{
  SFc9_CtrPlatform_RobustControlInstanceStruct *chartInstance;
  chartInstance = (SFc9_CtrPlatform_RobustControlInstanceStruct *)malloc(sizeof
    (SFc9_CtrPlatform_RobustControlInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_CtrPlatform_RobustControlInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_CtrPlatform_RobustControl;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_CtrPlatform_RobustControl;
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

void c9_CtrPlatform_RobustControl_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_CtrPlatform_RobustControl(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_CtrPlatform_RobustControl(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_CtrPlatform_RobustControl(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_CtrPlatform_RobustControl_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
