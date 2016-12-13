/* Include files */

#include "blascompat32.h"
#include "AugPDTask_sfun.h"
#include "c14_AugPDTask.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AugPDTask_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c14_debug_family_names[5] = { "nargin", "nargout", "EnTheta",
  "L", "InvJ" };

static const char *c14_b_debug_family_names[64] = { "A1", "A2", "A3", "A4", "A5",
  "L1", "L2", "L3", "L4", "L5", "t2", "t3", "t4", "t5", "t6", "t7", "t8", "t9",
  "t10", "t11", "t12", "t13", "t14", "t15", "t16", "t17", "t18", "t19", "t20",
  "t21", "t22", "t23", "t24", "t25", "t26", "t27", "t28", "t29", "t30", "t31",
  "t32", "t33", "t34", "t35", "t36", "t37", "t38", "t47", "t39", "t40", "t41",
  "t42", "t43", "t44", "t45", "t46", "t48", "t49", "t50", "nargin", "nargout",
  "in1", "in2", "spat_Jacobian" };

/* Function Declarations */
static void initialize_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct
  *chartInstance);
static void initialize_params_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct
  *chartInstance);
static void enable_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance);
static void disable_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance);
static void c14_update_debugger_state_c14_AugPDTask
  (SFc14_AugPDTaskInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *
  chartInstance);
static void set_sim_state_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct
  *chartInstance, const mxArray *c14_st);
static void finalize_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance);
static void sf_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c14_AugPDTask
  (SFc14_AugPDTaskInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber);
static void c14_spat_Jacobian(SFc14_AugPDTaskInstanceStruct *chartInstance,
  real_T c14_in1[9], real_T c14_in2[6], real_T c14_b_spat_Jacobian[36]);
static real_T c14_power(SFc14_AugPDTaskInstanceStruct *chartInstance, real_T
  c14_a, real_T c14_b);
static void c14_eml_error(SFc14_AugPDTaskInstanceStruct *chartInstance);
static void c14_invNxN(SFc14_AugPDTaskInstanceStruct *chartInstance, real_T
  c14_x[36], real_T c14_y[36]);
static void c14_eps(SFc14_AugPDTaskInstanceStruct *chartInstance);
static void c14_eml_matlab_zgetrf(SFc14_AugPDTaskInstanceStruct *chartInstance,
  real_T c14_A[36], real_T c14_b_A[36], int32_T c14_ipiv[6], int32_T *c14_info);
static int32_T c14_eml_ixamax(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_n, real_T c14_x[36], int32_T c14_ix0);
static int32_T c14_ceval_ixamax(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_n, real_T c14_x[36], int32_T c14_ix0, int32_T c14_incx);
static void c14_ceval_xswap(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_n, real_T c14_x[36], int32_T c14_ix0, int32_T c14_incx, int32_T
  c14_iy0, int32_T c14_incy, real_T c14_b_x[36]);
static void c14_ceval_xger(SFc14_AugPDTaskInstanceStruct *chartInstance, int32_T
  c14_m, int32_T c14_n, real_T c14_alpha1, int32_T c14_ix0, int32_T c14_incx,
  int32_T c14_iy0, int32_T c14_incy, real_T c14_A[36], int32_T c14_ia0, int32_T
  c14_lda, real_T c14_b_A[36]);
static void c14_eml_blas_xtrsm(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_m, int32_T c14_n, real_T c14_alpha1, real_T c14_A[36], int32_T
  c14_ia0, int32_T c14_lda, real_T c14_B[36], int32_T c14_ib0, int32_T c14_ldb,
  real_T c14_b_B[36]);
static void c14_ceval_xtrsm(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_m, int32_T c14_n, real_T c14_alpha1, real_T c14_A[36], int32_T
  c14_ia0, int32_T c14_lda, real_T c14_B[36], int32_T c14_ib0, int32_T c14_ldb,
  real_T c14_b_B[36]);
static real_T c14_norm(SFc14_AugPDTaskInstanceStruct *chartInstance, real_T
  c14_x[36]);
static void c14_eml_warning(SFc14_AugPDTaskInstanceStruct *chartInstance);
static void c14_b_eml_warning(SFc14_AugPDTaskInstanceStruct *chartInstance,
  real_T c14_varargin_3);
static const mxArray *c14_sf_marshall(void *chartInstanceVoid, void *c14_u);
static const mxArray *c14_b_sf_marshall(void *chartInstanceVoid, void *c14_u);
static const mxArray *c14_c_sf_marshall(void *chartInstanceVoid, void *c14_u);
static const mxArray *c14_d_sf_marshall(void *chartInstanceVoid, void *c14_u);
static const mxArray *c14_e_sf_marshall(void *chartInstanceVoid, void *c14_u);
static void c14_info_helper(c14_ResolvedFunctionInfo c14_info[93]);
static void c14_b_info_helper(c14_ResolvedFunctionInfo c14_info[93]);
static const mxArray *c14_f_sf_marshall(void *chartInstanceVoid, void *c14_u);
static void c14_emlrt_marshallIn(SFc14_AugPDTaskInstanceStruct *chartInstance,
  const mxArray *c14_InvJ, const char_T *c14_name, real_T c14_y[36]);
static uint8_T c14_b_emlrt_marshallIn(SFc14_AugPDTaskInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_AugPDTask, const char_T
  *c14_name);
static void init_dsm_address_info(SFc14_AugPDTaskInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c14_is_active_c14_AugPDTask = 0U;
}

static void initialize_params_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct
  *chartInstance)
{
  real_T c14_dv0[9];
  int32_T c14_i0;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c14_dv0, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c14_i0 = 0; c14_i0 < 9; c14_i0 = c14_i0 + 1) {
    chartInstance->c14_L[c14_i0] = c14_dv0[c14_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c14_update_debugger_state_c14_AugPDTask
  (SFc14_AugPDTaskInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *
  chartInstance)
{
  const mxArray *c14_st = NULL;
  const mxArray *c14_y = NULL;
  int32_T c14_i1;
  real_T c14_hoistedGlobal[36];
  int32_T c14_i2;
  real_T c14_u[36];
  const mxArray *c14_b_y = NULL;
  uint8_T c14_b_hoistedGlobal;
  uint8_T c14_b_u;
  const mxArray *c14_c_y = NULL;
  real_T (*c14_InvJ)[36];
  c14_InvJ = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_st = NULL;
  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_createcellarray(2));
  for (c14_i1 = 0; c14_i1 < 36; c14_i1 = c14_i1 + 1) {
    c14_hoistedGlobal[c14_i1] = (*c14_InvJ)[c14_i1];
  }

  for (c14_i2 = 0; c14_i2 < 36; c14_i2 = c14_i2 + 1) {
    c14_u[c14_i2] = c14_hoistedGlobal[c14_i2];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_setcell(c14_y, 0, c14_b_y);
  c14_b_hoistedGlobal = chartInstance->c14_is_active_c14_AugPDTask;
  c14_b_u = c14_b_hoistedGlobal;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c14_y, 1, c14_c_y);
  sf_mex_assign(&c14_st, c14_y);
  return c14_st;
}

static void set_sim_state_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct
  *chartInstance, const mxArray *c14_st)
{
  const mxArray *c14_u;
  real_T c14_dv1[36];
  int32_T c14_i3;
  real_T (*c14_InvJ)[36];
  c14_InvJ = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c14_doneDoubleBufferReInit = TRUE;
  c14_u = sf_mex_dup(c14_st);
  c14_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 0)),
                       "InvJ", c14_dv1);
  for (c14_i3 = 0; c14_i3 < 36; c14_i3 = c14_i3 + 1) {
    (*c14_InvJ)[c14_i3] = c14_dv1[c14_i3];
  }

  chartInstance->c14_is_active_c14_AugPDTask = c14_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c14_u, 1)),
     "is_active_c14_AugPDTask");
  sf_mex_destroy(&c14_u);
  c14_update_debugger_state_c14_AugPDTask(chartInstance);
  sf_mex_destroy(&c14_st);
}

static void finalize_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
}

static void sf_c14_AugPDTask(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
  int32_T c14_i4;
  int32_T c14_i5;
  int32_T c14_i6;
  int32_T c14_previousEvent;
  int32_T c14_i7;
  real_T c14_hoistedGlobal[6];
  int32_T c14_i8;
  real_T c14_b_hoistedGlobal[9];
  int32_T c14_i9;
  real_T c14_EnTheta[6];
  int32_T c14_i10;
  real_T c14_b_L[9];
  uint32_T c14_debug_family_var_map[5];
  real_T c14_nargin = 2.0;
  real_T c14_nargout = 1.0;
  real_T c14_InvJ[36];
  int32_T c14_i11;
  real_T c14_A[9];
  int32_T c14_i12;
  real_T c14_x[9];
  int32_T c14_i13;
  real_T c14_b_x[9];
  int32_T c14_i14;
  real_T c14_c_x[9];
  int32_T c14_i15;
  real_T c14_y[9];
  int32_T c14_i16;
  real_T c14_b_y[9];
  int32_T c14_i17;
  real_T c14_b_EnTheta[6];
  real_T c14_d_x[36];
  int32_T c14_i18;
  real_T c14_e_x[36];
  real_T c14_dv2[36];
  int32_T c14_i19;
  int32_T c14_i20;
  real_T c14_f_x[36];
  int32_T c14_i21;
  real_T c14_xinv[36];
  int32_T c14_i22;
  real_T c14_g_x[36];
  real_T c14_n1x;
  int32_T c14_i23;
  real_T c14_b_xinv[36];
  real_T c14_n1xinv;
  real_T c14_a;
  real_T c14_b;
  real_T c14_c_y;
  real_T c14_rc;
  real_T c14_h_x;
  boolean_T c14_b_b;
  int32_T c14_i24;
  real_T (*c14_b_InvJ)[36];
  real_T (*c14_c_EnTheta)[6];
  c14_b_InvJ = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c14_c_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9);
  for (c14_i4 = 0; c14_i4 < 6; c14_i4 = c14_i4 + 1) {
    _SFD_DATA_RANGE_CHECK((*c14_c_EnTheta)[c14_i4], 0U);
  }

  for (c14_i5 = 0; c14_i5 < 36; c14_i5 = c14_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c14_b_InvJ)[c14_i5], 1U);
  }

  for (c14_i6 = 0; c14_i6 < 9; c14_i6 = c14_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c14_L[c14_i6], 2U);
  }

  c14_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9);
  for (c14_i7 = 0; c14_i7 < 6; c14_i7 = c14_i7 + 1) {
    c14_hoistedGlobal[c14_i7] = (*c14_c_EnTheta)[c14_i7];
  }

  for (c14_i8 = 0; c14_i8 < 9; c14_i8 = c14_i8 + 1) {
    c14_b_hoistedGlobal[c14_i8] = chartInstance->c14_L[c14_i8];
  }

  for (c14_i9 = 0; c14_i9 < 6; c14_i9 = c14_i9 + 1) {
    c14_EnTheta[c14_i9] = c14_hoistedGlobal[c14_i9];
  }

  for (c14_i10 = 0; c14_i10 < 9; c14_i10 = c14_i10 + 1) {
    c14_b_L[c14_i10] = c14_b_hoistedGlobal[c14_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c14_debug_family_names,
    c14_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c14_nargin, c14_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c14_nargout, c14_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c14_EnTheta, c14_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c14_b_L, c14_b_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c14_InvJ, c14_sf_marshall, 4U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  for (c14_i11 = 0; c14_i11 < 9; c14_i11 = c14_i11 + 1) {
    c14_A[c14_i11] = c14_b_L[c14_i11];
  }

  for (c14_i12 = 0; c14_i12 < 9; c14_i12 = c14_i12 + 1) {
    c14_x[c14_i12] = c14_A[c14_i12];
  }

  for (c14_i13 = 0; c14_i13 < 9; c14_i13 = c14_i13 + 1) {
    c14_b_x[c14_i13] = c14_x[c14_i13];
  }

  for (c14_i14 = 0; c14_i14 < 9; c14_i14 = c14_i14 + 1) {
    c14_c_x[c14_i14] = c14_b_x[c14_i14];
  }

  for (c14_i15 = 0; c14_i15 < 9; c14_i15 = c14_i15 + 1) {
    c14_y[c14_i15] = c14_c_x[c14_i15] / 1000.0;
  }

  for (c14_i16 = 0; c14_i16 < 9; c14_i16 = c14_i16 + 1) {
    c14_b_y[c14_i16] = c14_y[c14_i16];
  }

  for (c14_i17 = 0; c14_i17 < 6; c14_i17 = c14_i17 + 1) {
    c14_b_EnTheta[c14_i17] = c14_EnTheta[c14_i17];
  }

  c14_spat_Jacobian(chartInstance, c14_b_y, c14_b_EnTheta, c14_d_x);
  for (c14_i18 = 0; c14_i18 < 36; c14_i18 = c14_i18 + 1) {
    c14_e_x[c14_i18] = c14_d_x[c14_i18];
  }

  c14_invNxN(chartInstance, c14_e_x, c14_dv2);
  for (c14_i19 = 0; c14_i19 < 36; c14_i19 = c14_i19 + 1) {
    c14_InvJ[c14_i19] = c14_dv2[c14_i19];
  }

  for (c14_i20 = 0; c14_i20 < 36; c14_i20 = c14_i20 + 1) {
    c14_f_x[c14_i20] = c14_d_x[c14_i20];
  }

  for (c14_i21 = 0; c14_i21 < 36; c14_i21 = c14_i21 + 1) {
    c14_xinv[c14_i21] = c14_InvJ[c14_i21];
  }

  for (c14_i22 = 0; c14_i22 < 36; c14_i22 = c14_i22 + 1) {
    c14_g_x[c14_i22] = c14_f_x[c14_i22];
  }

  c14_n1x = c14_norm(chartInstance, c14_g_x);
  for (c14_i23 = 0; c14_i23 < 36; c14_i23 = c14_i23 + 1) {
    c14_b_xinv[c14_i23] = c14_xinv[c14_i23];
  }

  c14_n1xinv = c14_norm(chartInstance, c14_b_xinv);
  c14_a = c14_n1x;
  c14_b = c14_n1xinv;
  c14_c_y = c14_a * c14_b;
  c14_rc = 1.0 / c14_c_y;
  if (c14_n1x == 0.0) {
  } else if (c14_n1xinv == 0.0) {
  } else if (c14_rc == 0.0) {
    goto label_1;
  } else {
    c14_h_x = c14_rc;
    c14_b_b = muDoubleScalarIsNaN(c14_h_x);
    if (c14_b_b) {
    } else if (c14_rc < 2.2204460492503131E-16) {
    } else {
      goto label_2;
    }

    c14_b_eml_warning(chartInstance, c14_rc);
   label_2:
    ;
    goto label_3;
  }

 label_1:
  ;
  c14_eml_warning(chartInstance);
 label_3:
  ;
  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  for (c14_i24 = 0; c14_i24 < 36; c14_i24 = c14_i24 + 1) {
    (*c14_b_InvJ)[c14_i24] = c14_InvJ[c14_i24];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9);
  _sfEvent_ = c14_previousEvent;
  sf_debug_check_for_state_inconsistency(_AugPDTaskMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c14_AugPDTask
  (SFc14_AugPDTaskInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c14_machineNumber, uint32_T
  c14_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c14_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m"));
}

static void c14_spat_Jacobian(SFc14_AugPDTaskInstanceStruct *chartInstance,
  real_T c14_in1[9], real_T c14_in2[6], real_T
  c14_b_spat_Jacobian[36])
{
  uint32_T c14_debug_family_var_map[64];
  real_T c14_A1;
  real_T c14_A2;
  real_T c14_A3;
  real_T c14_A4;
  real_T c14_A5;
  real_T c14_L1;
  real_T c14_L2;
  real_T c14_L3;
  real_T c14_L4;
  real_T c14_L5;
  real_T c14_t2;
  real_T c14_t3;
  real_T c14_t4;
  real_T c14_t5;
  real_T c14_t6;
  real_T c14_t7;
  real_T c14_t8;
  real_T c14_t9;
  real_T c14_t10;
  real_T c14_t11;
  real_T c14_t12;
  real_T c14_t13;
  real_T c14_t14;
  real_T c14_t15;
  real_T c14_t16;
  real_T c14_t17;
  real_T c14_t18;
  real_T c14_t19;
  real_T c14_t20;
  real_T c14_t21;
  real_T c14_t22;
  real_T c14_t23;
  real_T c14_t24;
  real_T c14_t25;
  real_T c14_t26;
  real_T c14_t27;
  real_T c14_t28;
  real_T c14_t29;
  real_T c14_t30;
  real_T c14_t31;
  real_T c14_t32;
  real_T c14_t33;
  real_T c14_t34;
  real_T c14_t35;
  real_T c14_t36;
  real_T c14_t37;
  real_T c14_t38;
  real_T c14_t47;
  real_T c14_t39;
  real_T c14_t40;
  real_T c14_t41;
  real_T c14_t42;
  real_T c14_t43;
  real_T c14_t44;
  real_T c14_t45;
  real_T c14_t46;
  real_T c14_t48;
  real_T c14_t49;
  real_T c14_t50;
  real_T c14_nargin = 2.0;
  real_T c14_nargout = 1.0;
  real_T c14_x;
  real_T c14_b_x;
  real_T c14_c_x;
  real_T c14_d_x;
  real_T c14_e_x;
  real_T c14_f_x;
  real_T c14_g_x;
  real_T c14_h_x;
  real_T c14_i_x;
  real_T c14_j_x;
  real_T c14_k_x;
  real_T c14_l_x;
  real_T c14_m_x;
  real_T c14_n_x;
  real_T c14_o_x;
  real_T c14_p_x;
  real_T c14_q_x;
  real_T c14_r_x;
  real_T c14_s_x;
  real_T c14_t_x;
  real_T c14_u_x;
  real_T c14_v_x;
  real_T c14_w_x;
  real_T c14_x_x;
  real_T c14_d0;
  real_T c14_y_x[36];
  int32_T c14_k;
  int32_T c14_b_k;
  sf_debug_symbol_scope_push_eml(0U, 64U, 64U, c14_b_debug_family_names,
    c14_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c14_A1, c14_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c14_A2, c14_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c14_A3, c14_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c14_A4, c14_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c14_A5, c14_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c14_L1, c14_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c14_L2, c14_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c14_L3, c14_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c14_L4, c14_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c14_L5, c14_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c14_t2, c14_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c14_t3, c14_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c14_t4, c14_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c14_t5, c14_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c14_t6, c14_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c14_t7, c14_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c14_t8, c14_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c14_t9, c14_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c14_t10, c14_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c14_t11, c14_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c14_t12, c14_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c14_t13, c14_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c14_t14, c14_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c14_t15, c14_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c14_t16, c14_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c14_t17, c14_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c14_t18, c14_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c14_t19, c14_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c14_t20, c14_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c14_t21, c14_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c14_t22, c14_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c14_t23, c14_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c14_t24, c14_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c14_t25, c14_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c14_t26, c14_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c14_t27, c14_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c14_t28, c14_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c14_t29, c14_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c14_t30, c14_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c14_t31, c14_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c14_t32, c14_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c14_t33, c14_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c14_t34, c14_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c14_t35, c14_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c14_t36, c14_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c14_t37, c14_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c14_t38, c14_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c14_t47, c14_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c14_t39, c14_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c14_t40, c14_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c14_t41, c14_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c14_t42, c14_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c14_t43, c14_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c14_t44, c14_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c14_t45, c14_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c14_t46, c14_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c14_t48, c14_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c14_t49, c14_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c14_t50, c14_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c14_nargin, c14_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c14_nargout, c14_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(c14_in1, c14_b_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(c14_in2, c14_e_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(c14_b_spat_Jacobian, c14_sf_marshall, 63U);
  CV_SCRIPT_FCN(0, 0);

  /* SPAT_JACOBIAN */
  /*     SPAT_JACOBIAN = SPAT_JACOBIAN(IN1,IN2) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     24-Apr-2013 20:41:43 */
  _SFD_SCRIPT_CALL(0, 8);
  c14_A1 = c14_in2[0];
  _SFD_SCRIPT_CALL(0, 9);
  c14_A2 = c14_in2[1];
  _SFD_SCRIPT_CALL(0, 10);
  c14_A3 = c14_in2[2];
  _SFD_SCRIPT_CALL(0, 11);
  c14_A4 = c14_in2[3];
  _SFD_SCRIPT_CALL(0, 12);
  c14_A5 = c14_in2[4];
  _SFD_SCRIPT_CALL(0, 13);
  c14_L1 = c14_in1[0];
  _SFD_SCRIPT_CALL(0, 14);
  c14_L2 = c14_in1[1];
  _SFD_SCRIPT_CALL(0, 15);
  c14_L3 = c14_in1[2];
  _SFD_SCRIPT_CALL(0, 16);
  c14_L4 = c14_in1[3];
  _SFD_SCRIPT_CALL(0, 17);
  c14_L5 = c14_in1[4];
  _SFD_SCRIPT_CALL(0, 18);
  c14_x = c14_A1;
  c14_t2 = c14_x;
  c14_b_x = c14_t2;
  c14_t2 = c14_b_x;
  c14_t2 = muDoubleScalarCos(c14_t2);
  _SFD_SCRIPT_CALL(0, 19);
  c14_t3 = c14_A2 + c14_A3;
  _SFD_SCRIPT_CALL(0, 20);
  c14_c_x = c14_A2;
  c14_t4 = c14_c_x;
  c14_d_x = c14_t4;
  c14_t4 = c14_d_x;
  c14_t4 = muDoubleScalarCos(c14_t4);
  _SFD_SCRIPT_CALL(0, 21);
  c14_e_x = c14_A3;
  c14_t5 = c14_e_x;
  c14_f_x = c14_t5;
  c14_t5 = c14_f_x;
  c14_t5 = muDoubleScalarCos(c14_t5);
  _SFD_SCRIPT_CALL(0, 22);
  c14_g_x = c14_A2;
  c14_t6 = c14_g_x;
  c14_h_x = c14_t6;
  c14_t6 = c14_h_x;
  c14_t6 = muDoubleScalarSin(c14_t6);
  _SFD_SCRIPT_CALL(0, 23);
  c14_i_x = c14_A3;
  c14_t7 = c14_i_x;
  c14_j_x = c14_t7;
  c14_t7 = c14_j_x;
  c14_t7 = muDoubleScalarSin(c14_t7);
  _SFD_SCRIPT_CALL(0, 24);
  c14_t8 = c14_L1 + c14_L3;
  _SFD_SCRIPT_CALL(0, 25);
  c14_t9 = c14_t5 - 1.0;
  _SFD_SCRIPT_CALL(0, 26);
  c14_k_x = c14_A1;
  c14_t10 = c14_k_x;
  c14_l_x = c14_t10;
  c14_t10 = c14_l_x;
  c14_t10 = muDoubleScalarSin(c14_t10);
  _SFD_SCRIPT_CALL(0, 27);
  c14_m_x = c14_t3;
  c14_t11 = c14_m_x;
  c14_n_x = c14_t11;
  c14_t11 = c14_n_x;
  c14_t11 = muDoubleScalarSin(c14_t11);
  _SFD_SCRIPT_CALL(0, 28);
  c14_o_x = c14_A4;
  c14_t12 = c14_o_x;
  c14_p_x = c14_t12;
  c14_t12 = c14_p_x;
  c14_t12 = muDoubleScalarCos(c14_t12);
  _SFD_SCRIPT_CALL(0, 29);
  c14_q_x = c14_t3;
  c14_t13 = c14_q_x;
  c14_r_x = c14_t13;
  c14_t13 = c14_r_x;
  c14_t13 = muDoubleScalarCos(c14_t13);
  _SFD_SCRIPT_CALL(0, 30);
  c14_s_x = c14_A4;
  c14_t14 = c14_s_x;
  c14_t_x = c14_t14;
  c14_t14 = c14_t_x;
  c14_t14 = muDoubleScalarSin(c14_t14);
  _SFD_SCRIPT_CALL(0, 31);
  c14_t15 = (c14_L1 + c14_L3) + c14_L4;
  _SFD_SCRIPT_CALL(0, 32);
  c14_t16 = c14_L2 * c14_t11;
  _SFD_SCRIPT_CALL(0, 33);
  c14_t17 = c14_L3 * c14_t5;
  _SFD_SCRIPT_CALL(0, 34);
  c14_t18 = c14_L1 * c14_t13;
  _SFD_SCRIPT_CALL(0, 35);
  c14_t19 = c14_t12 - 1.0;
  _SFD_SCRIPT_CALL(0, 36);
  c14_u_x = c14_A5;
  c14_t20 = c14_u_x;
  c14_v_x = c14_t20;
  c14_t20 = c14_v_x;
  c14_t20 = muDoubleScalarCos(c14_t20);
  _SFD_SCRIPT_CALL(0, 37);
  c14_t21 = c14_L2 + c14_L5;
  _SFD_SCRIPT_CALL(0, 38);
  c14_w_x = c14_A5;
  c14_t22 = c14_w_x;
  c14_x_x = c14_t22;
  c14_t22 = c14_x_x;
  c14_t22 = muDoubleScalarSin(c14_t22);
  _SFD_SCRIPT_CALL(0, 39);
  c14_t23 = c14_t20 - 1.0;
  _SFD_SCRIPT_CALL(0, 40);
  c14_t24 = c14_L2 * c14_t6;
  _SFD_SCRIPT_CALL(0, 41);
  c14_t25 = c14_t4 - 1.0;
  _SFD_SCRIPT_CALL(0, 42);
  c14_t26 = c14_t24 - c14_L1 * c14_t25;
  _SFD_SCRIPT_CALL(0, 43);
  c14_t27 = c14_t2 * c14_t26;
  _SFD_SCRIPT_CALL(0, 44);
  c14_t28 = c14_L2 * c14_t7;
  _SFD_SCRIPT_CALL(0, 45);
  c14_t29 = c14_t2 * c14_t4 * (c14_t28 - c14_t8 * c14_t9);
  _SFD_SCRIPT_CALL(0, 46);
  c14_t30 = c14_t7 * c14_t8;
  _SFD_SCRIPT_CALL(0, 47);
  c14_t31 = c14_L2 * c14_t9;
  _SFD_SCRIPT_CALL(0, 48);
  c14_t32 = c14_t30 + c14_t31;
  _SFD_SCRIPT_CALL(0, 49);
  c14_t33 = c14_t2 * c14_t32 * c14_t6;
  _SFD_SCRIPT_CALL(0, 50);
  c14_t34 = (c14_t27 + c14_t29) + c14_t33;
  _SFD_SCRIPT_CALL(0, 51);
  c14_t35 = c14_L1 * c14_t11;
  _SFD_SCRIPT_CALL(0, 52);
  c14_t36 = c14_L3 * c14_t7;
  _SFD_SCRIPT_CALL(0, 53);
  c14_t37 = ((c14_L2 + c14_t35) + c14_t36) - c14_L2 * c14_t13;
  _SFD_SCRIPT_CALL(0, 54);
  c14_t38 = c14_t10 * c14_t12;
  _SFD_SCRIPT_CALL(0, 55);
  c14_t47 = c14_t11 * c14_t14 * c14_t2;
  _SFD_SCRIPT_CALL(0, 56);
  c14_t39 = c14_t38 - c14_t47;
  _SFD_SCRIPT_CALL(0, 57);
  c14_t40 = c14_L3 * c14_t4;
  _SFD_SCRIPT_CALL(0, 58);
  c14_t41 = c14_L1 + c14_t40;
  _SFD_SCRIPT_CALL(0, 59);
  c14_t42 = ((c14_L4 + c14_t16) + c14_t17) + c14_t18;
  _SFD_SCRIPT_CALL(0, 60);
  c14_t43 = c14_L3 * c14_t6;
  _SFD_SCRIPT_CALL(0, 61);
  c14_t44 = c14_L4 * c14_t11;
  _SFD_SCRIPT_CALL(0, 62);
  c14_t45 = c14_L5 * c14_t13;
  _SFD_SCRIPT_CALL(0, 63);
  c14_t46 = ((c14_L2 + c14_t43) + c14_t44) + c14_t45;
  _SFD_SCRIPT_CALL(0, 64);
  c14_t48 = c14_t10 * c14_t14;
  _SFD_SCRIPT_CALL(0, 65);
  c14_t49 = c14_t11 * c14_t12 * c14_t2;
  _SFD_SCRIPT_CALL(0, 66);
  c14_t50 = c14_t48 + c14_t49;
  _SFD_SCRIPT_CALL(0, 67);
  c14_d0 = c14_power(chartInstance, c14_t14, 2.0);
  c14_y_x[0] = 0.0;
  c14_y_x[1] = 0.0;
  c14_y_x[2] = 0.0;
  c14_y_x[3] = 0.0;
  c14_y_x[4] = 0.0;
  c14_y_x[5] = 1.0;
  c14_y_x[6] = (-c14_L1) * c14_t2;
  c14_y_x[7] = (-c14_L1) * c14_t10;
  c14_y_x[8] = c14_L2;
  c14_y_x[9] = -c14_t10;
  c14_y_x[10] = c14_t2;
  c14_y_x[11] = 0.0;
  c14_y_x[12] = (-c14_t2) * c14_t41;
  c14_y_x[13] = (-c14_t10) * c14_t41;
  c14_y_x[14] = c14_L2 + c14_t43;
  c14_y_x[15] = -c14_t10;
  c14_y_x[16] = c14_t2;
  c14_y_x[17] = 0.0;
  c14_y_x[18] = (-c14_t10) * c14_t42;
  c14_y_x[19] = c14_t2 * c14_t42;
  c14_y_x[20] = 0.0;
  c14_y_x[21] = c14_t13 * c14_t2;
  c14_y_x[22] = c14_t10 * c14_t13;
  c14_y_x[23] = -c14_t11;
  c14_y_x[24] = ((((-c14_t12) * c14_t34 + c14_t21 * c14_t50) + c14_t13 * c14_t2 *
                  (c14_d0 * c14_t15 + c14_t12 * c14_t15 * c14_t19)) -
                 c14_t13 * c14_t15 * c14_t2) - c14_t10 * c14_t14 * c14_t37;
  c14_y_x[25] = (((((((-c14_L1) * c14_t10 * c14_t12 - c14_L5 * c14_t14 * c14_t2)
                     + c14_L1 * c14_t11 * c14_t14 * c14_t2) - c14_L2 *
                    c14_t13 * c14_t14 * c14_t2) - c14_L4 * c14_t10 * c14_t12 *
                   c14_t13) + c14_L5 * c14_t10 * c14_t11 * c14_t12) - c14_L3 *
                 c14_t10 *
                 c14_t12 * c14_t4) + c14_L3 * c14_t14 * c14_t2 * c14_t7;
  c14_y_x[26] = c14_t12 * c14_t46;
  c14_y_x[27] = (-c14_t38) + c14_t47;
  c14_y_x[28] = c14_t12 * c14_t2 + c14_t10 * c14_t11 * c14_t14;
  c14_y_x[29] = c14_t13 * c14_t14;
  c14_y_x[30] = (((-c14_t20) * ((c14_t10 * (((((-c14_L1) - c14_L3) + c14_t16) +
    c14_t17) + c14_t18) - c14_t10 * c14_t15 * c14_t19) +
    c14_t11 * c14_t14 * c14_t15 * c14_t2) - c14_t15 * c14_t39) - c14_t22 *
                 ((c14_t14 * c14_t34 + c14_t13 * c14_t2 * (c14_t12 * c14_t14
    * c14_t15 - c14_t14 * c14_t15 * c14_t19)) - c14_t10 * c14_t12 * c14_t37)) +
    c14_t39 * (c14_t20 * (c14_t15 * c14_t23 - c14_t21 *
    c14_t22) + c14_t22 * (c14_t15 * c14_t22 + c14_t21 * c14_t23));
  c14_y_x[31] = ((((((((((c14_L4 * c14_t2 * c14_t20 - c14_L1 * c14_t10 * c14_t14
    * c14_t22) + c14_L1 * c14_t13 * c14_t2 * c14_t20) +
                        c14_L2 * c14_t11 * c14_t2 * c14_t20) + c14_L5 * c14_t12 *
                       c14_t2 * c14_t22) + c14_L3 * c14_t2 * c14_t20 * c14_t5) -
                     c14_L1 * c14_t11
                     * c14_t12 * c14_t2 * c14_t22) + c14_L2 * c14_t12 * c14_t13 *
                    c14_t2 * c14_t22) - c14_L4 * c14_t10 * c14_t13 * c14_t14 *
                   c14_t22) +
                  c14_L5 * c14_t10 * c14_t11 * c14_t14 * c14_t22) - c14_L3 *
                 c14_t10 * c14_t14 * c14_t22 * c14_t4) - c14_L3 * c14_t12 *
    c14_t2 *
    c14_t22 * c14_t7;
  c14_y_x[32] = c14_t14 * c14_t22 * c14_t46;
  c14_y_x[33] = (-c14_t22) * c14_t50 + c14_t13 * c14_t2 * c14_t20;
  c14_y_x[34] = c14_t22 * (c14_t14 * c14_t2 - c14_t10 * c14_t11 * c14_t12) +
    c14_t10 * c14_t13 * c14_t20;
  c14_y_x[35] = (-c14_t11) * c14_t20 - c14_t12 * c14_t13 * c14_t22;
  for (c14_k = 1; c14_k < 37; c14_k = c14_k + 1) {
    c14_b_k = c14_k;
    c14_b_spat_Jacobian[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c14_b_k), 1, 36, 1, 0) - 1] = c14_y_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c14_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0, -67);
  sf_debug_symbol_scope_pop();
}

static real_T c14_power(SFc14_AugPDTaskInstanceStruct *chartInstance, real_T
  c14_a, real_T c14_b)
{
  real_T c14_ak;
  real_T c14_bk;
  real_T c14_x;
  real_T c14_b_x;
  c14_ak = c14_a;
  c14_bk = c14_b;
  if (c14_ak < 0.0) {
    c14_x = c14_bk;
    c14_b_x = c14_x;
    c14_b_x = muDoubleScalarFloor(c14_b_x);
    if (c14_b_x != c14_bk) {
      c14_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c14_ak, c14_bk);
}

static void c14_eml_error(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
  int32_T c14_i25;
  static char_T c14_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c14_u[32];
  const mxArray *c14_y = NULL;
  int32_T c14_i26;
  static char_T c14_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
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

  char_T c14_b_u[102];
  const mxArray *c14_b_y = NULL;
  for (c14_i25 = 0; c14_i25 < 32; c14_i25 = c14_i25 + 1) {
    c14_u[c14_i25] = c14_cv0[c14_i25];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c14_i26 = 0; c14_i26 < 102; c14_i26 = c14_i26 + 1) {
    c14_b_u[c14_i26] = c14_cv1[c14_i26];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c14_y, 14, c14_b_y);
}

static void c14_invNxN(SFc14_AugPDTaskInstanceStruct *chartInstance, real_T
  c14_x[36], real_T c14_y[36])
{
  int32_T c14_i27;
  int32_T c14_i28;
  real_T c14_A[36];
  int32_T c14_i29;
  real_T c14_b_x[36];
  int32_T c14_i30;
  real_T c14_b_A[36];
  int32_T c14_i31;
  real_T c14_c_A[36];
  int32_T c14_i32;
  real_T c14_d_A[36];
  int32_T c14_info;
  int32_T c14_ipiv[6];
  real_T c14_e_A[36];
  int32_T c14_i33;
  int32_T c14_i34;
  int32_T c14_b_ipiv[6];
  int32_T c14_i35;
  int32_T c14_i36;
  int32_T c14_c_ipiv[6];
  int32_T c14_i37;
  int32_T c14_i38;
  int32_T c14_d_ipiv[6];
  int32_T c14_i39;
  int32_T c14_e_ipiv[6];
  int32_T c14_i40;
  int32_T c14_p[6];
  real_T c14_k;
  real_T c14_b_k;
  int32_T c14_ipk;
  int32_T c14_pipk;
  int32_T c14_c_k;
  int32_T c14_d_k;
  int32_T c14_c;
  int32_T c14_e_k;
  int32_T c14_j;
  int32_T c14_b_j;
  int32_T c14_a;
  int32_T c14_i41;
  int32_T c14_i;
  int32_T c14_b_i;
  real_T c14_b_a;
  real_T c14_b;
  real_T c14_b_y;
  int32_T c14_i42;
  real_T c14_f_A[36];
  int32_T c14_i43;
  real_T c14_B[36];
  int32_T c14_i44;
  int32_T c14_i45;
  real_T c14_g_A[36];
  int32_T c14_i46;
  real_T c14_c_y[36];
  for (c14_i27 = 0; c14_i27 < 36; c14_i27 = c14_i27 + 1) {
    c14_y[c14_i27] = 0.0;
  }

  for (c14_i28 = 0; c14_i28 < 36; c14_i28 = c14_i28 + 1) {
    c14_A[c14_i28] = c14_x[c14_i28];
  }

  for (c14_i29 = 0; c14_i29 < 36; c14_i29 = c14_i29 + 1) {
    c14_b_x[c14_i29] = c14_A[c14_i29];
  }

  for (c14_i30 = 0; c14_i30 < 36; c14_i30 = c14_i30 + 1) {
    c14_b_A[c14_i30] = c14_b_x[c14_i30];
  }

  for (c14_i31 = 0; c14_i31 < 36; c14_i31 = c14_i31 + 1) {
    c14_c_A[c14_i31] = c14_b_A[c14_i31];
  }

  for (c14_i32 = 0; c14_i32 < 36; c14_i32 = c14_i32 + 1) {
    c14_d_A[c14_i32] = c14_c_A[c14_i32];
  }

  c14_eml_matlab_zgetrf(chartInstance, c14_d_A, c14_e_A, c14_ipiv, &c14_info);
  for (c14_i33 = 0; c14_i33 < 36; c14_i33 = c14_i33 + 1) {
    c14_c_A[c14_i33] = c14_e_A[c14_i33];
  }

  for (c14_i34 = 0; c14_i34 < 6; c14_i34 = c14_i34 + 1) {
    c14_b_ipiv[c14_i34] = c14_ipiv[c14_i34];
  }

  for (c14_i35 = 0; c14_i35 < 36; c14_i35 = c14_i35 + 1) {
    c14_b_x[c14_i35] = c14_c_A[c14_i35];
  }

  for (c14_i36 = 0; c14_i36 < 6; c14_i36 = c14_i36 + 1) {
    c14_c_ipiv[c14_i36] = c14_b_ipiv[c14_i36];
  }

  for (c14_i37 = 0; c14_i37 < 36; c14_i37 = c14_i37 + 1) {
    c14_x[c14_i37] = c14_b_x[c14_i37];
  }

  for (c14_i38 = 0; c14_i38 < 6; c14_i38 = c14_i38 + 1) {
    c14_d_ipiv[c14_i38] = c14_c_ipiv[c14_i38];
  }

  for (c14_i39 = 0; c14_i39 < 6; c14_i39 = c14_i39 + 1) {
    c14_e_ipiv[c14_i39] = c14_d_ipiv[c14_i39];
  }

  for (c14_i40 = 0; c14_i40 < 6; c14_i40 = c14_i40 + 1) {
    c14_p[c14_i40] = 1 + c14_i40;
  }

  for (c14_k = 1.0; c14_k <= 5.0; c14_k = c14_k + 1.0) {
    c14_b_k = c14_k;
    c14_ipk = c14_e_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c14_b_k), 1, 6, 1, 0) - 1];
    if ((real_T)c14_ipk > c14_b_k) {
      c14_pipk = c14_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c14_ipk), 1, 6, 1, 0) - 1];
      c14_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c14_ipk), 1, 6, 1, 0) - 1] = c14_p[
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c14_b_k),
        1, 6, 1, 0) - 1];
      c14_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c14_b_k), 1, 6, 1, 0) - 1] = c14_pipk;
    }
  }

  for (c14_c_k = 1; c14_c_k < 7; c14_c_k = c14_c_k + 1) {
    c14_d_k = c14_c_k;
    c14_c = c14_p[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c14_d_k), 1, 6, 1, 0) - 1];
    c14_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c14_d_k), 1, 6, 1, 0) - 1) + 6 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c14_c), 1, 6, 2, 0) - 1)] = 1.0;
    c14_e_k = c14_d_k;
    for (c14_j = c14_e_k; c14_j < 7; c14_j = c14_j + 1) {
      c14_b_j = c14_j;
      if (c14_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c14_b_j), 1, 6, 1, 0) - 1) + 6 * (
           _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c14_c), 1, 6, 2, 0) - 1)] != 0.0) {
        c14_a = c14_b_j;
        c14_i41 = c14_a + 1;
        for (c14_i = c14_i41; c14_i < 7; c14_i = c14_i + 1) {
          c14_b_i = c14_i;
          c14_b_a = c14_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c14_b_j), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c14_c), 1, 6, 2, 0) - 1)];
          c14_b = c14_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c14_b_i), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c14_b_j), 1, 6, 2, 0) - 1)];
          c14_b_y = c14_b_a * c14_b;
          c14_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c14_b_i), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c14_c), 1, 6, 2, 0) - 1)] = c14_y[(
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c14_b_i), 1, 6, 1, 0) - 1) + 6 * (
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c14_c), 1, 6, 2, 0) - 1)] - c14_b_y;
        }
      }
    }
  }

  for (c14_i42 = 0; c14_i42 < 36; c14_i42 = c14_i42 + 1) {
    c14_f_A[c14_i42] = c14_x[c14_i42];
  }

  for (c14_i43 = 0; c14_i43 < 36; c14_i43 = c14_i43 + 1) {
    c14_B[c14_i43] = c14_y[c14_i43];
  }

  for (c14_i44 = 0; c14_i44 < 36; c14_i44 = c14_i44 + 1) {
    c14_y[c14_i44] = c14_B[c14_i44];
  }

  for (c14_i45 = 0; c14_i45 < 36; c14_i45 = c14_i45 + 1) {
    c14_g_A[c14_i45] = c14_f_A[c14_i45];
  }

  for (c14_i46 = 0; c14_i46 < 36; c14_i46 = c14_i46 + 1) {
    c14_c_y[c14_i46] = c14_y[c14_i46];
  }

  c14_eml_blas_xtrsm(chartInstance, 6, 6, 1.0, c14_g_A, 1, 6, c14_c_y, 1, 6,
                     c14_y);
}

static void c14_eps(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
}

static void c14_eml_matlab_zgetrf(SFc14_AugPDTaskInstanceStruct *chartInstance,
  real_T c14_A[36], real_T c14_b_A[36], int32_T
  c14_ipiv[6], int32_T *c14_info)
{
  int32_T c14_i47;
  int32_T c14_i48;
  int32_T c14_j;
  int32_T c14_b_j;
  int32_T c14_a;
  int32_T c14_jm1;
  int32_T c14_b;
  int32_T c14_mmj;
  int32_T c14_b_a;
  int32_T c14_c;
  int32_T c14_b_b;
  int32_T c14_jj;
  int32_T c14_c_a;
  int32_T c14_jp1j;
  int32_T c14_d_a;
  int32_T c14_b_c;
  int32_T c14_i49;
  real_T c14_c_A[36];
  int32_T c14_e_a;
  int32_T c14_jpiv_offset;
  int32_T c14_f_a;
  int32_T c14_c_b;
  int32_T c14_jpiv;
  int32_T c14_g_a;
  int32_T c14_d_b;
  int32_T c14_c_c;
  int32_T c14_e_b;
  int32_T c14_jrow;
  int32_T c14_h_a;
  int32_T c14_f_b;
  int32_T c14_jprow;
  int32_T c14_i50;
  real_T c14_x[36];
  int32_T c14_ix0;
  int32_T c14_iy0;
  int32_T c14_i51;
  int32_T c14_i52;
  real_T c14_b_x[36];
  int32_T c14_b_ix0;
  int32_T c14_b_iy0;
  int32_T c14_i53;
  real_T c14_c_x[36];
  int32_T c14_i54;
  real_T c14_d_x[36];
  real_T c14_e_x[36];
  int32_T c14_i55;
  int32_T c14_i56;
  int32_T c14_b_jp1j;
  int32_T c14_i_a;
  int32_T c14_d_c;
  int32_T c14_j_a;
  int32_T c14_g_b;
  int32_T c14_loop_ub;
  int32_T c14_i;
  int32_T c14_b_i;
  real_T c14_f_x;
  real_T c14_y;
  real_T c14_g_x;
  real_T c14_b_y;
  real_T c14_z;
  int32_T c14_h_b;
  int32_T c14_e_c;
  int32_T c14_k_a;
  int32_T c14_f_c;
  int32_T c14_l_a;
  int32_T c14_g_c;
  int32_T c14_m;
  int32_T c14_n;
  int32_T c14_c_ix0;
  int32_T c14_c_iy0;
  int32_T c14_i57;
  real_T c14_d_A[36];
  int32_T c14_ia0;
  int32_T c14_i58;
  int32_T c14_b_m;
  int32_T c14_b_n;
  int32_T c14_d_ix0;
  int32_T c14_d_iy0;
  int32_T c14_i59;
  real_T c14_e_A[36];
  int32_T c14_b_ia0;
  int32_T c14_i60;
  int32_T c14_c_m;
  int32_T c14_c_n;
  int32_T c14_e_ix0;
  int32_T c14_e_iy0;
  int32_T c14_i61;
  real_T c14_f_A[36];
  int32_T c14_c_ia0;
  int32_T c14_i62;
  int32_T c14_i63;
  real_T c14_g_A[36];
  for (c14_i47 = 0; c14_i47 < 36; c14_i47 = c14_i47 + 1) {
    c14_b_A[c14_i47] = c14_A[c14_i47];
  }

  c14_eps(chartInstance);
  for (c14_i48 = 0; c14_i48 < 6; c14_i48 = c14_i48 + 1) {
    c14_ipiv[c14_i48] = 1 + c14_i48;
  }

  *c14_info = 0;
  for (c14_j = 1; c14_j < 6; c14_j = c14_j + 1) {
    c14_b_j = c14_j;
    c14_a = c14_b_j;
    c14_jm1 = c14_a - 1;
    c14_b = c14_b_j;
    c14_mmj = 6 - c14_b;
    c14_b_a = c14_jm1;
    c14_c = c14_b_a * 7;
    c14_b_b = c14_c;
    c14_jj = 1 + c14_b_b;
    c14_c_a = c14_jj;
    c14_jp1j = c14_c_a + 1;
    c14_d_a = c14_mmj;
    c14_b_c = c14_d_a + 1;
    for (c14_i49 = 0; c14_i49 < 36; c14_i49 = c14_i49 + 1) {
      c14_c_A[c14_i49] = c14_b_A[c14_i49];
    }

    c14_e_a = c14_eml_ixamax(chartInstance, c14_b_c, c14_c_A, c14_jj);
    c14_jpiv_offset = c14_e_a - 1;
    c14_f_a = c14_jj;
    c14_c_b = c14_jpiv_offset;
    c14_jpiv = c14_f_a + c14_c_b;
    if (c14_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c14_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if ((real_T)c14_jpiv_offset != 0.0) {
        c14_g_a = c14_b_j;
        c14_d_b = c14_jpiv_offset;
        c14_c_c = c14_g_a + c14_d_b;
        c14_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c14_b_j), 1, 6, 1, 0) - 1] = c14_c_c;
        c14_e_b = c14_jm1;
        c14_jrow = 1 + c14_e_b;
        c14_h_a = c14_jrow;
        c14_f_b = c14_jpiv_offset;
        c14_jprow = c14_h_a + c14_f_b;
        for (c14_i50 = 0; c14_i50 < 36; c14_i50 = c14_i50 + 1) {
          c14_x[c14_i50] = c14_b_A[c14_i50];
        }

        c14_ix0 = c14_jrow;
        c14_iy0 = c14_jprow;
        for (c14_i51 = 0; c14_i51 < 36; c14_i51 = c14_i51 + 1) {
          c14_b_A[c14_i51] = c14_x[c14_i51];
        }

        for (c14_i52 = 0; c14_i52 < 36; c14_i52 = c14_i52 + 1) {
          c14_b_x[c14_i52] = c14_b_A[c14_i52];
        }

        c14_b_ix0 = c14_ix0;
        c14_b_iy0 = c14_iy0;
        for (c14_i53 = 0; c14_i53 < 36; c14_i53 = c14_i53 + 1) {
          c14_c_x[c14_i53] = c14_b_x[c14_i53];
        }

        for (c14_i54 = 0; c14_i54 < 36; c14_i54 = c14_i54 + 1) {
          c14_d_x[c14_i54] = c14_c_x[c14_i54];
        }

        c14_ceval_xswap(chartInstance, 6, c14_d_x, c14_b_ix0, 6, c14_b_iy0, 6,
                        c14_e_x);
        for (c14_i55 = 0; c14_i55 < 36; c14_i55 = c14_i55 + 1) {
          c14_c_x[c14_i55] = c14_e_x[c14_i55];
        }

        for (c14_i56 = 0; c14_i56 < 36; c14_i56 = c14_i56 + 1) {
          c14_b_A[c14_i56] = c14_c_x[c14_i56];
        }
      }

      c14_b_jp1j = c14_jp1j;
      c14_i_a = c14_mmj;
      c14_d_c = c14_i_a - 1;
      c14_j_a = c14_jp1j;
      c14_g_b = c14_d_c;
      c14_loop_ub = c14_j_a + c14_g_b;
      for (c14_i = c14_b_jp1j; c14_i <= c14_loop_ub; c14_i = c14_i + 1) {
        c14_b_i = c14_i;
        c14_f_x = c14_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c14_b_i), 1, 36, 1, 0) - 1];
        c14_y = c14_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c14_jj), 1, 36, 1, 0) - 1];
        c14_g_x = c14_f_x;
        c14_b_y = c14_y;
        c14_z = c14_g_x / c14_b_y;
        c14_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c14_b_i), 1, 36, 1, 0) - 1] = c14_z;
      }
    } else {
      *c14_info = c14_b_j;
    }

    c14_h_b = c14_b_j;
    c14_e_c = 6 - c14_h_b;
    c14_k_a = c14_jj;
    c14_f_c = c14_k_a + 6;
    c14_l_a = c14_jj;
    c14_g_c = c14_l_a + 7;
    c14_m = c14_mmj;
    c14_n = c14_e_c;
    c14_c_ix0 = c14_jp1j;
    c14_c_iy0 = c14_f_c;
    for (c14_i57 = 0; c14_i57 < 36; c14_i57 = c14_i57 + 1) {
      c14_d_A[c14_i57] = c14_b_A[c14_i57];
    }

    c14_ia0 = c14_g_c;
    for (c14_i58 = 0; c14_i58 < 36; c14_i58 = c14_i58 + 1) {
      c14_b_A[c14_i58] = c14_d_A[c14_i58];
    }

    c14_b_m = c14_m;
    c14_b_n = c14_n;
    c14_d_ix0 = c14_c_ix0;
    c14_d_iy0 = c14_c_iy0;
    for (c14_i59 = 0; c14_i59 < 36; c14_i59 = c14_i59 + 1) {
      c14_e_A[c14_i59] = c14_b_A[c14_i59];
    }

    c14_b_ia0 = c14_ia0;
    for (c14_i60 = 0; c14_i60 < 36; c14_i60 = c14_i60 + 1) {
      c14_b_A[c14_i60] = c14_e_A[c14_i60];
    }

    c14_c_m = c14_b_m;
    c14_c_n = c14_b_n;
    c14_e_ix0 = c14_d_ix0;
    c14_e_iy0 = c14_d_iy0;
    for (c14_i61 = 0; c14_i61 < 36; c14_i61 = c14_i61 + 1) {
      c14_f_A[c14_i61] = c14_b_A[c14_i61];
    }

    c14_c_ia0 = c14_b_ia0;
    for (c14_i62 = 0; c14_i62 < 36; c14_i62 = c14_i62 + 1) {
      c14_b_A[c14_i62] = c14_f_A[c14_i62];
    }

    if ((real_T)c14_c_m < 1.0) {
    } else if ((real_T)c14_c_n < 1.0) {
    } else {
      for (c14_i63 = 0; c14_i63 < 36; c14_i63 = c14_i63 + 1) {
        c14_g_A[c14_i63] = c14_b_A[c14_i63];
      }

      c14_ceval_xger(chartInstance, c14_c_m, c14_c_n, -1.0, c14_e_ix0, 1,
                     c14_e_iy0, 6, c14_g_A, c14_c_ia0, 6, c14_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c14_info == 0.0) {
    if (!(c14_b_A[35] != 0.0)) {
      *c14_info = 6;
      return;
    }
  }
}

static int32_T c14_eml_ixamax(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_n, real_T c14_x[36], int32_T c14_ix0)
{
  int32_T c14_b_n;
  int32_T c14_i64;
  real_T c14_b_x[36];
  int32_T c14_b_ix0;
  int32_T c14_i65;
  real_T c14_c_x[36];
  c14_b_n = c14_n;
  for (c14_i64 = 0; c14_i64 < 36; c14_i64 = c14_i64 + 1) {
    c14_b_x[c14_i64] = c14_x[c14_i64];
  }

  c14_b_ix0 = c14_ix0;
  for (c14_i65 = 0; c14_i65 < 36; c14_i65 = c14_i65 + 1) {
    c14_c_x[c14_i65] = c14_b_x[c14_i65];
  }

  return c14_ceval_ixamax(chartInstance, c14_b_n, c14_c_x, c14_b_ix0, 1);
}

static int32_T c14_ceval_ixamax(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_n, real_T c14_x[36], int32_T c14_ix0,
  int32_T c14_incx)
{
  return idamax32(&c14_n, &c14_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c14_ix0), 1, 36, 1, 0) - 1],
                  &c14_incx);
}

static void c14_ceval_xswap(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_n, real_T c14_x[36], int32_T c14_ix0, int32_T
  c14_incx, int32_T c14_iy0, int32_T c14_incy, real_T c14_b_x[36])
{
  int32_T c14_i66;

  /* Empty Loop. */
  for (c14_i66 = 0; c14_i66 < 36; c14_i66 = c14_i66 + 1) {
    c14_b_x[c14_i66] = c14_x[c14_i66];
  }

  dswap32(&c14_n, &c14_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c14_ix0), 1, 36, 1, 0) - 1], &
          c14_incx, &c14_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c14_iy0), 1, 36, 1, 0) - 1], &c14_incy);
}

static void c14_ceval_xger(SFc14_AugPDTaskInstanceStruct *chartInstance, int32_T
  c14_m, int32_T c14_n, real_T c14_alpha1, int32_T
  c14_ix0, int32_T c14_incx, int32_T c14_iy0, int32_T c14_incy, real_T c14_A[36],
  int32_T c14_ia0, int32_T c14_lda, real_T c14_b_A[36]
  )
{
  int32_T c14_i67;
  for (c14_i67 = 0; c14_i67 < 36; c14_i67 = c14_i67 + 1) {
    c14_b_A[c14_i67] = c14_A[c14_i67];
  }

  dger32(&c14_m, &c14_n, &c14_alpha1, &c14_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c14_ix0), 1, 36
          , 1, 0) - 1], &c14_incx, &c14_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c14_iy0), 1, 36, 1, 0) - 1
         ], &c14_incy, &c14_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c14_ia0), 1, 36, 1, 0) - 1], &c14_lda
         );
}

static void c14_eml_blas_xtrsm(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_m, int32_T c14_n, real_T c14_alpha1, real_T
  c14_A[36], int32_T c14_ia0, int32_T c14_lda, real_T c14_B[36], int32_T c14_ib0,
  int32_T c14_ldb, real_T c14_b_B[36])
{
  int32_T c14_i68;
  int32_T c14_i69;
  real_T c14_b_A[36];
  int32_T c14_i70;
  real_T c14_c_B[36];
  for (c14_i68 = 0; c14_i68 < 36; c14_i68 = c14_i68 + 1) {
    c14_b_B[c14_i68] = c14_B[c14_i68];
  }

  for (c14_i69 = 0; c14_i69 < 36; c14_i69 = c14_i69 + 1) {
    c14_b_A[c14_i69] = c14_A[c14_i69];
  }

  for (c14_i70 = 0; c14_i70 < 36; c14_i70 = c14_i70 + 1) {
    c14_c_B[c14_i70] = c14_b_B[c14_i70];
  }

  c14_ceval_xtrsm(chartInstance, c14_m, c14_n, c14_alpha1, c14_b_A, c14_ia0,
                  c14_lda, c14_c_B, c14_ib0, c14_ldb, c14_b_B);
}

static void c14_ceval_xtrsm(SFc14_AugPDTaskInstanceStruct *chartInstance,
  int32_T c14_m, int32_T c14_n, real_T c14_alpha1, real_T
  c14_A[36], int32_T c14_ia0, int32_T c14_lda, real_T c14_B[36], int32_T c14_ib0,
  int32_T c14_ldb, real_T c14_b_B[36])
{
  char_T c14_SIDE;
  char_T c14_UPLO;
  char_T c14_TRANSA;
  char_T c14_DIAGA;
  int32_T c14_i71;
  c14_SIDE = 'L';
  c14_UPLO = 'U';
  c14_TRANSA = 'N';
  c14_DIAGA = 'N';
  for (c14_i71 = 0; c14_i71 < 36; c14_i71 = c14_i71 + 1) {
    c14_b_B[c14_i71] = c14_B[c14_i71];
  }

  dtrsm32(&c14_SIDE, &c14_UPLO, &c14_TRANSA, &c14_DIAGA, &c14_m, &c14_n,
          &c14_alpha1, &c14_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c14_ia0), 1, 36, 1, 0) - 1], &c14_lda,
          &c14_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c14_ib0), 1, 36, 1, 0) - 1], &c14_ldb);
}

static real_T c14_norm(SFc14_AugPDTaskInstanceStruct *chartInstance, real_T
  c14_x[36])
{
  real_T c14_y;
  int32_T c14_i72;
  real_T c14_b_x[36];
  real_T c14_j;
  real_T c14_b_j;
  real_T c14_s;
  real_T c14_i;
  real_T c14_b_i;
  real_T c14_c_x;
  real_T c14_d_x;
  real_T c14_b_y;
  real_T c14_e_x;
  boolean_T c14_b;
  for (c14_i72 = 0; c14_i72 < 36; c14_i72 = c14_i72 + 1) {
    c14_b_x[c14_i72] = c14_x[c14_i72];
  }

  c14_y = 0.0;
  c14_j = 1.0;
 label_1:
  ;
  if (c14_j <= 6.0) {
    c14_b_j = c14_j;
    c14_s = 0.0;
    for (c14_i = 1.0; c14_i <= 6.0; c14_i = c14_i + 1.0) {
      c14_b_i = c14_i;
      c14_c_x = c14_b_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c14_b_i), 1, 6, 1, 0) - 1) + 6 * (
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c14_b_j),
        1, 6, 2, 0) - 1)];
      c14_d_x = c14_c_x;
      c14_b_y = muDoubleScalarAbs(c14_d_x);
      c14_s = c14_s + c14_b_y;
    }

    c14_e_x = c14_s;
    c14_b = muDoubleScalarIsNaN(c14_e_x);
    if (c14_b) {
      return rtNaN;
    } else {
      if (c14_s > c14_y) {
        c14_y = c14_s;
      }

      c14_j = c14_j + 1.0;
      goto label_1;
    }
  }

  return c14_y;
}

static void c14_eml_warning(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
  int32_T c14_i73;
  static char_T c14_cv2[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i',
    'x' };

  char_T c14_u[21];
  const mxArray *c14_y = NULL;
  int32_T c14_i74;
  static char_T c14_cv3[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't',
    'o', ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i',
    's', 'i', 'o', 'n', '.' };

  char_T c14_b_u[40];
  const mxArray *c14_b_y = NULL;
  for (c14_i73 = 0; c14_i73 < 21; c14_i73 = c14_i73 + 1) {
    c14_u[c14_i73] = c14_cv2[c14_i73];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c14_i74 = 0; c14_i74 < 40; c14_i74 = c14_i74 + 1) {
    c14_b_u[c14_i74] = c14_cv3[c14_i74];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c14_y, 14, c14_b_y);
}

static void c14_b_eml_warning(SFc14_AugPDTaskInstanceStruct *chartInstance,
  real_T c14_varargin_3)
{
  int32_T c14_i75;
  static char_T c14_cv4[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'l', 'l',
    'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e',
    'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c14_u[27];
  const mxArray *c14_y = NULL;
  int32_T c14_i76;
  static char_T c14_cv5[103] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's',
    ' ', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ',', ' ',
    'c', 'l', 'o', 's', 'e', ' ', 't', 'o', ' ', 's', 'i', 'n', 'g', 'u', 'l',
    'a', 'r', ' ', 'o', 'r',
    ' ', 'b', 'a', 'd', 'l', 'y', ' ', 's', 'c', 'a', 'l', 'e', 'd', '.', '\\',
    'n', ' ', ' ', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', 'R', 'e', 's', 'u', 'l', 't', 's', ' ', 'm', 'a',
    'y', ' ', 'b', 'e', ' ',
    'i', 'n', 'a', 'c', 'c', 'u', 'r', 'a', 't', 'e', '.', ' ', 'R', 'C', 'O',
    'N', 'D', ' ', '=', ' ',
    '%', 'e', '.' };

  char_T c14_b_u[103];
  const mxArray *c14_b_y = NULL;
  real_T c14_c_u;
  const mxArray *c14_c_y = NULL;
  for (c14_i75 = 0; c14_i75 < 27; c14_i75 = c14_i75 + 1) {
    c14_u[c14_i75] = c14_cv4[c14_i75];
  }

  c14_y = NULL;
  sf_mex_assign(&c14_y, sf_mex_create("y", c14_u, 10, 0U, 1U, 0U, 2, 1, 27));
  for (c14_i76 = 0; c14_i76 < 103; c14_i76 = c14_i76 + 1) {
    c14_b_u[c14_i76] = c14_cv5[c14_i76];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_b_u, 10, 0U, 1U, 0U, 2, 1, 103));
  c14_c_u = c14_varargin_3;
  c14_c_y = NULL;
  sf_mex_assign(&c14_c_y, sf_mex_create("y", &c14_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("warning", 0U, 3U, 14, c14_y, 14, c14_b_y, 14, c14_c_y);
}

static const mxArray *c14_sf_marshall(void *chartInstanceVoid, void *c14_u)
{
  const mxArray *c14_y = NULL;
  int32_T c14_i77;
  int32_T c14_i78;
  int32_T c14_i79;
  real_T c14_b_u[36];
  int32_T c14_i80;
  int32_T c14_i81;
  int32_T c14_i82;
  real_T c14_c_u[36];
  const mxArray *c14_b_y = NULL;
  SFc14_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc14_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c14_y = NULL;
  c14_i77 = 0;
  for (c14_i78 = 0; c14_i78 < 6; c14_i78 = c14_i78 + 1) {
    for (c14_i79 = 0; c14_i79 < 6; c14_i79 = c14_i79 + 1) {
      c14_b_u[c14_i79 + c14_i77] = (*((real_T (*)[36])c14_u))[c14_i79 + c14_i77];
    }

    c14_i77 = c14_i77 + 6;
  }

  c14_i80 = 0;
  for (c14_i81 = 0; c14_i81 < 6; c14_i81 = c14_i81 + 1) {
    for (c14_i82 = 0; c14_i82 < 6; c14_i82 = c14_i82 + 1) {
      c14_c_u[c14_i82 + c14_i80] = c14_b_u[c14_i82 + c14_i80];
    }

    c14_i80 = c14_i80 + 6;
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_c_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

static const mxArray *c14_b_sf_marshall(void *chartInstanceVoid, void *c14_u)
{
  const mxArray *c14_y = NULL;
  int32_T c14_i83;
  real_T c14_b_u[9];
  int32_T c14_i84;
  real_T c14_c_u[9];
  const mxArray *c14_b_y = NULL;
  SFc14_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc14_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c14_y = NULL;
  for (c14_i83 = 0; c14_i83 < 9; c14_i83 = c14_i83 + 1) {
    c14_b_u[c14_i83] = (*((real_T (*)[9])c14_u))[c14_i83];
  }

  for (c14_i84 = 0; c14_i84 < 9; c14_i84 = c14_i84 + 1) {
    c14_c_u[c14_i84] = c14_b_u[c14_i84];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

static const mxArray *c14_c_sf_marshall(void *chartInstanceVoid, void *c14_u)
{
  const mxArray *c14_y = NULL;
  int32_T c14_i85;
  real_T c14_b_u[6];
  int32_T c14_i86;
  real_T c14_c_u[6];
  const mxArray *c14_b_y = NULL;
  SFc14_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc14_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c14_y = NULL;
  for (c14_i85 = 0; c14_i85 < 6; c14_i85 = c14_i85 + 1) {
    c14_b_u[c14_i85] = (*((real_T (*)[6])c14_u))[c14_i85];
  }

  for (c14_i86 = 0; c14_i86 < 6; c14_i86 = c14_i86 + 1) {
    c14_c_u[c14_i86] = c14_b_u[c14_i86];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

static const mxArray *c14_d_sf_marshall(void *chartInstanceVoid, void *c14_u)
{
  const mxArray *c14_y = NULL;
  real_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  SFc14_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc14_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c14_y = NULL;
  c14_b_u = *((real_T *)c14_u);
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

static const mxArray *c14_e_sf_marshall(void *chartInstanceVoid, void *c14_u)
{
  const mxArray *c14_y = NULL;
  int32_T c14_i87;
  real_T c14_b_u[6];
  int32_T c14_i88;
  real_T c14_c_u[6];
  const mxArray *c14_b_y = NULL;
  SFc14_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc14_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c14_y = NULL;
  for (c14_i87 = 0; c14_i87 < 6; c14_i87 = c14_i87 + 1) {
    c14_b_u[c14_i87] = (*((real_T (*)[6])c14_u))[c14_i87];
  }

  for (c14_i88 = 0; c14_i88 < 6; c14_i88 = c14_i88 + 1) {
    c14_c_u[c14_i88] = c14_b_u[c14_i88];
  }

  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", c14_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

const mxArray *sf_c14_AugPDTask_get_eml_resolved_functions_info(void)
{
  const mxArray *c14_nameCaptureInfo = NULL;
  c14_ResolvedFunctionInfo c14_info[93];
  const mxArray *c14_m0 = NULL;
  int32_T c14_i89;
  c14_ResolvedFunctionInfo *c14_r0;
  c14_nameCaptureInfo = NULL;
  c14_info_helper(c14_info);
  c14_b_info_helper(c14_info);
  sf_mex_assign(&c14_m0, sf_mex_createstruct("nameCaptureInfo", 1, 93));
  for (c14_i89 = 0; c14_i89 < 93; c14_i89 = c14_i89 + 1) {
    c14_r0 = &c14_info[c14_i89];
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->context)), "context"
                    , "nameCaptureInfo", c14_i89);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c14_r0->name)), "name",
                    "nameCaptureInfo", c14_i89);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo",
      c14_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c14_i89);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", c14_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c14_r0->resolved)),
                    "resolved", "nameCaptureInfo", c14_i89);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c14_i89);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c14_i89);
    sf_mex_addfield(c14_m0, sf_mex_create("nameCaptureInfo", &c14_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c14_i89);
  }

  sf_mex_assign(&c14_nameCaptureInfo, c14_m0);
  return c14_nameCaptureInfo;
}

static void c14_info_helper(c14_ResolvedFunctionInfo c14_info[93])
{
  c14_info[0].context = "";
  c14_info[0].name = "mrdivide";
  c14_info[0].dominantType = "double";
  c14_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c14_info[0].fileLength = 432U;
  c14_info[0].fileTime1 = 1277726622U;
  c14_info[0].fileTime2 = 0U;
  c14_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c14_info[1].name = "nargin";
  c14_info[1].dominantType = "";
  c14_info[1].resolved = "[B]nargin";
  c14_info[1].fileLength = 0U;
  c14_info[1].fileTime1 = 0U;
  c14_info[1].fileTime2 = 0U;
  c14_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c14_info[2].name = "ge";
  c14_info[2].dominantType = "double";
  c14_info[2].resolved = "[B]ge";
  c14_info[2].fileLength = 0U;
  c14_info[2].fileTime1 = 0U;
  c14_info[2].fileTime2 = 0U;
  c14_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c14_info[3].name = "isscalar";
  c14_info[3].dominantType = "double";
  c14_info[3].resolved = "[B]isscalar";
  c14_info[3].fileLength = 0U;
  c14_info[3].fileTime1 = 0U;
  c14_info[3].fileTime2 = 0U;
  c14_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c14_info[4].name = "rdivide";
  c14_info[4].dominantType = "double";
  c14_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[4].fileLength = 403U;
  c14_info[4].fileTime1 = 1245080820U;
  c14_info[4].fileTime2 = 0U;
  c14_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[5].name = "gt";
  c14_info[5].dominantType = "double";
  c14_info[5].resolved = "[B]gt";
  c14_info[5].fileLength = 0U;
  c14_info[5].fileTime1 = 0U;
  c14_info[5].fileTime2 = 0U;
  c14_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[6].name = "isa";
  c14_info[6].dominantType = "double";
  c14_info[6].resolved = "[B]isa";
  c14_info[6].fileLength = 0U;
  c14_info[6].fileTime1 = 0U;
  c14_info[6].fileTime2 = 0U;
  c14_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c14_info[7].name = "eml_div";
  c14_info[7].dominantType = "double";
  c14_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c14_info[7].fileLength = 4918U;
  c14_info[7].fileTime1 = 1267038210U;
  c14_info[7].fileTime2 = 0U;
  c14_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c14_info[8].name = "isinteger";
  c14_info[8].dominantType = "double";
  c14_info[8].resolved = "[B]isinteger";
  c14_info[8].fileLength = 0U;
  c14_info[8].fileTime1 = 0U;
  c14_info[8].fileTime2 = 0U;
  c14_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c14_info[9].name = "isreal";
  c14_info[9].dominantType = "double";
  c14_info[9].resolved = "[B]isreal";
  c14_info[9].fileLength = 0U;
  c14_info[9].fileTime1 = 0U;
  c14_info[9].fileTime2 = 0U;
  c14_info[10].context = "";
  c14_info[10].name = "ctranspose";
  c14_info[10].dominantType = "double";
  c14_info[10].resolved = "[B]ctranspose";
  c14_info[10].fileLength = 0U;
  c14_info[10].fileTime1 = 0U;
  c14_info[10].fileTime2 = 0U;
  c14_info[11].context = "";
  c14_info[11].name = "spat_Jacobian";
  c14_info[11].dominantType = "double";
  c14_info[11].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[11].fileLength = 2169U;
  c14_info[11].fileTime1 = 1366807304U;
  c14_info[11].fileTime2 = 0U;
  c14_info[12].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[12].name = "cos";
  c14_info[12].dominantType = "double";
  c14_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c14_info[12].fileLength = 324U;
  c14_info[12].fileTime1 = 1203422750U;
  c14_info[12].fileTime2 = 0U;
  c14_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c14_info[13].name = "eml_scalar_cos";
  c14_info[13].dominantType = "double";
  c14_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c14_info[13].fileLength = 602U;
  c14_info[13].fileTime1 = 1209309186U;
  c14_info[13].fileTime2 = 0U;
  c14_info[14].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[14].name = "plus";
  c14_info[14].dominantType = "double";
  c14_info[14].resolved = "[B]plus";
  c14_info[14].fileLength = 0U;
  c14_info[14].fileTime1 = 0U;
  c14_info[14].fileTime2 = 0U;
  c14_info[15].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[15].name = "sin";
  c14_info[15].dominantType = "double";
  c14_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c14_info[15].fileLength = 324U;
  c14_info[15].fileTime1 = 1203422842U;
  c14_info[15].fileTime2 = 0U;
  c14_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c14_info[16].name = "eml_scalar_sin";
  c14_info[16].dominantType = "double";
  c14_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c14_info[16].fileLength = 601U;
  c14_info[16].fileTime1 = 1209309190U;
  c14_info[16].fileTime2 = 0U;
  c14_info[17].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[17].name = "minus";
  c14_info[17].dominantType = "double";
  c14_info[17].resolved = "[B]minus";
  c14_info[17].fileLength = 0U;
  c14_info[17].fileTime1 = 0U;
  c14_info[17].fileTime2 = 0U;
  c14_info[18].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[18].name = "times";
  c14_info[18].dominantType = "double";
  c14_info[18].resolved = "[B]times";
  c14_info[18].fileLength = 0U;
  c14_info[18].fileTime1 = 0U;
  c14_info[18].fileTime2 = 0U;
  c14_info[19].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[19].name = "uminus";
  c14_info[19].dominantType = "double";
  c14_info[19].resolved = "[B]uminus";
  c14_info[19].fileLength = 0U;
  c14_info[19].fileTime1 = 0U;
  c14_info[19].fileTime2 = 0U;
  c14_info[20].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[20].name = "power";
  c14_info[20].dominantType = "double";
  c14_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c14_info[20].fileLength = 5380U;
  c14_info[20].fileTime1 = 1228068698U;
  c14_info[20].fileTime2 = 0U;
  c14_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c14_info[21].name = "eml_scalar_eg";
  c14_info[21].dominantType = "double";
  c14_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c14_info[21].fileLength = 3068U;
  c14_info[21].fileTime1 = 1240240410U;
  c14_info[21].fileTime2 = 0U;
  c14_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c14_info[22].name = "false";
  c14_info[22].dominantType = "";
  c14_info[22].resolved = "[B]false";
  c14_info[22].fileLength = 0U;
  c14_info[22].fileTime1 = 0U;
  c14_info[22].fileTime2 = 0U;
  c14_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c14_info[23].name = "isstruct";
  c14_info[23].dominantType = "double";
  c14_info[23].resolved = "[B]isstruct";
  c14_info[23].fileLength = 0U;
  c14_info[23].fileTime1 = 0U;
  c14_info[23].fileTime2 = 0U;
  c14_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c14_info[24].name = "eq";
  c14_info[24].dominantType = "double";
  c14_info[24].resolved = "[B]eq";
  c14_info[24].fileLength = 0U;
  c14_info[24].fileTime1 = 0U;
  c14_info[24].fileTime2 = 0U;
  c14_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c14_info[25].name = "class";
  c14_info[25].dominantType = "double";
  c14_info[25].resolved = "[B]class";
  c14_info[25].fileLength = 0U;
  c14_info[25].fileTime1 = 0U;
  c14_info[25].fileTime2 = 0U;
  c14_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c14_info[26].name = "cast";
  c14_info[26].dominantType = "double";
  c14_info[26].resolved = "[B]cast";
  c14_info[26].fileLength = 0U;
  c14_info[26].fileTime1 = 0U;
  c14_info[26].fileTime2 = 0U;
  c14_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c14_info[27].name = "eml_scalexp_alloc";
  c14_info[27].dominantType = "double";
  c14_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c14_info[27].fileLength = 932U;
  c14_info[27].fileTime1 = 1261926670U;
  c14_info[27].fileTime2 = 0U;
  c14_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c14_info[28].name = "not";
  c14_info[28].dominantType = "logical";
  c14_info[28].resolved = "[B]not";
  c14_info[28].fileLength = 0U;
  c14_info[28].fileTime1 = 0U;
  c14_info[28].fileTime2 = 0U;
  c14_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c14_info[29].name = "lt";
  c14_info[29].dominantType = "double";
  c14_info[29].resolved = "[B]lt";
  c14_info[29].fileLength = 0U;
  c14_info[29].fileTime1 = 0U;
  c14_info[29].fileTime2 = 0U;
  c14_info[30].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c14_info[30].name = "eml_scalar_floor";
  c14_info[30].dominantType = "double";
  c14_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c14_info[30].fileLength = 260U;
  c14_info[30].fileTime1 = 1209309190U;
  c14_info[30].fileTime2 = 0U;
  c14_info[31].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c14_info[31].name = "ne";
  c14_info[31].dominantType = "double";
  c14_info[31].resolved = "[B]ne";
  c14_info[31].fileLength = 0U;
  c14_info[31].fileTime1 = 0U;
  c14_info[31].fileTime2 = 0U;
  c14_info[32].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c14_info[32].name = "eml_error";
  c14_info[32].dominantType = "char";
  c14_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c14_info[32].fileLength = 315U;
  c14_info[32].fileTime1 = 1213905144U;
  c14_info[32].fileTime2 = 0U;
  c14_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c14_info[33].name = "strcmp";
  c14_info[33].dominantType = "char";
  c14_info[33].resolved = "[B]strcmp";
  c14_info[33].fileLength = 0U;
  c14_info[33].fileTime1 = 0U;
  c14_info[33].fileTime2 = 0U;
  c14_info[34].context = "[E]D:/Learn/MatlabProgram/Fanuc/spat_Jacobian.m";
  c14_info[34].name = "reshape";
  c14_info[34].dominantType = "double";
  c14_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c14_info[34].fileLength = 4857U;
  c14_info[34].fileTime1 = 1242276774U;
  c14_info[34].fileTime2 = 0U;
  c14_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c14_info[35].name = "eml_index_class";
  c14_info[35].dominantType = "";
  c14_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c14_info[35].fileLength = 909U;
  c14_info[35].fileTime1 = 1192445182U;
  c14_info[35].fileTime2 = 0U;
  c14_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c14_info[36].name = "size";
  c14_info[36].dominantType = "double";
  c14_info[36].resolved = "[B]size";
  c14_info[36].fileLength = 0U;
  c14_info[36].fileTime1 = 0U;
  c14_info[36].fileTime2 = 0U;
  c14_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c14_info[37].name = "eml_assert_valid_size_arg";
  c14_info[37].dominantType = "double";
  c14_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c14_info[37].fileLength = 3315U;
  c14_info[37].fileTime1 = 1256367816U;
  c14_info[37].fileTime2 = 0U;
  c14_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c14_info[38].name = "isvector";
  c14_info[38].dominantType = "double";
  c14_info[38].resolved = "[B]isvector";
  c14_info[38].fileLength = 0U;
  c14_info[38].fileTime1 = 0U;
  c14_info[38].fileTime2 = 0U;
  c14_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c14_info[39].name = "isinf";
  c14_info[39].dominantType = "double";
  c14_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c14_info[39].fileLength = 541U;
  c14_info[39].fileTime1 = 1271383988U;
  c14_info[39].fileTime2 = 0U;
  c14_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c14_info[40].name = "true";
  c14_info[40].dominantType = "";
  c14_info[40].resolved = "[B]true";
  c14_info[40].fileLength = 0U;
  c14_info[40].fileTime1 = 0U;
  c14_info[40].fileTime2 = 0U;
  c14_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c14_info[41].name = "le";
  c14_info[41].dominantType = "double";
  c14_info[41].resolved = "[B]le";
  c14_info[41].fileLength = 0U;
  c14_info[41].fileTime1 = 0U;
  c14_info[41].fileTime2 = 0U;
  c14_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c14_info[42].name = "double";
  c14_info[42].dominantType = "double";
  c14_info[42].resolved = "[B]double";
  c14_info[42].fileLength = 0U;
  c14_info[42].fileTime1 = 0U;
  c14_info[42].fileTime2 = 0U;
  c14_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c14_info[43].name = "mtimes";
  c14_info[43].dominantType = "double";
  c14_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c14_info[43].fileLength = 3425U;
  c14_info[43].fileTime1 = 1251010272U;
  c14_info[43].fileTime2 = 0U;
  c14_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c14_info[44].name = "intmax";
  c14_info[44].dominantType = "char";
  c14_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c14_info[44].fileLength = 1535U;
  c14_info[44].fileTime1 = 1192445128U;
  c14_info[44].fileTime2 = 0U;
  c14_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c14_info[45].name = "ischar";
  c14_info[45].dominantType = "char";
  c14_info[45].resolved = "[B]ischar";
  c14_info[45].fileLength = 0U;
  c14_info[45].fileTime1 = 0U;
  c14_info[45].fileTime2 = 0U;
  c14_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c14_info[46].name = "int32";
  c14_info[46].dominantType = "double";
  c14_info[46].resolved = "[B]int32";
  c14_info[46].fileLength = 0U;
  c14_info[46].fileTime1 = 0U;
  c14_info[46].fileTime2 = 0U;
  c14_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c14_info[47].name = "ones";
  c14_info[47].dominantType = "char";
  c14_info[47].resolved = "[B]ones";
  c14_info[47].fileLength = 0U;
  c14_info[47].fileTime1 = 0U;
  c14_info[47].fileTime2 = 0U;
  c14_info[48].context = "";
  c14_info[48].name = "inv";
  c14_info[48].dominantType = "double";
  c14_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c14_info[48].fileLength = 4757U;
  c14_info[48].fileTime1 = 1252487208U;
  c14_info[48].fileTime2 = 0U;
  c14_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c14_info[49].name = "ndims";
  c14_info[49].dominantType = "double";
  c14_info[49].resolved = "[B]ndims";
  c14_info[49].fileLength = 0U;
  c14_info[49].fileTime1 = 0U;
  c14_info[49].fileTime2 = 0U;
  c14_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c14_info[50].name = "eml_xgetrf";
  c14_info[50].dominantType = "int32";
  c14_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c14_info[50].fileLength = 204U;
  c14_info[50].fileTime1 = 1271383994U;
  c14_info[50].fileTime2 = 0U;
  c14_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c14_info[51].name = "eml_lapack_xgetrf";
  c14_info[51].dominantType = "int32";
  c14_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c14_info[51].fileLength = 211U;
  c14_info[51].fileTime1 = 1271383994U;
  c14_info[51].fileTime2 = 0U;
  c14_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c14_info[52].name = "eml_matlab_zgetrf";
  c14_info[52].dominantType = "int32";
  c14_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[52].fileLength = 2193U;
  c14_info[52].fileTime1 = 1271383998U;
  c14_info[52].fileTime2 = 0U;
  c14_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[53].name = "realmin";
  c14_info[53].dominantType = "char";
  c14_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c14_info[53].fileLength = 749U;
  c14_info[53].fileTime1 = 1226552078U;
  c14_info[53].fileTime2 = 0U;
  c14_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c14_info[54].name = "mpower";
  c14_info[54].dominantType = "double";
  c14_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c14_info[54].fileLength = 3710U;
  c14_info[54].fileTime1 = 1238412688U;
  c14_info[54].fileTime2 = 0U;
  c14_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[55].name = "eps";
  c14_info[55].dominantType = "char";
  c14_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c14_info[55].fileLength = 1331U;
  c14_info[55].fileTime1 = 1246588112U;
  c14_info[55].fileTime2 = 0U;
  c14_info[56].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c14_info[56].name = "eml_is_float_class";
  c14_info[56].dominantType = "char";
  c14_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c14_info[56].fileLength = 226U;
  c14_info[56].fileTime1 = 1197825240U;
  c14_info[56].fileTime2 = 0U;
  c14_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[57].name = "min";
  c14_info[57].dominantType = "int32";
  c14_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c14_info[57].fileLength = 362U;
  c14_info[57].fileTime1 = 1245080764U;
  c14_info[57].fileTime2 = 0U;
  c14_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c14_info[58].name = "nargout";
  c14_info[58].dominantType = "";
  c14_info[58].resolved = "[B]nargout";
  c14_info[58].fileLength = 0U;
  c14_info[58].fileTime1 = 0U;
  c14_info[58].fileTime2 = 0U;
  c14_info[59].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c14_info[59].name = "eml_min_or_max";
  c14_info[59].dominantType = "int32";
  c14_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c14_info[59].fileLength = 9967U;
  c14_info[59].fileTime1 = 1261926670U;
  c14_info[59].fileTime2 = 0U;
  c14_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c14_info[60].name = "isnumeric";
  c14_info[60].dominantType = "int32";
  c14_info[60].resolved = "[B]isnumeric";
  c14_info[60].fileLength = 0U;
  c14_info[60].fileTime1 = 0U;
  c14_info[60].fileTime2 = 0U;
  c14_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c14_info[61].name = "islogical";
  c14_info[61].dominantType = "int32";
  c14_info[61].resolved = "[B]islogical";
  c14_info[61].fileLength = 0U;
  c14_info[61].fileTime1 = 0U;
  c14_info[61].fileTime2 = 0U;
  c14_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[62].name = "colon";
  c14_info[62].dominantType = "int32";
  c14_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c14_info[62].fileLength = 8633U;
  c14_info[62].fileTime1 = 1273822662U;
  c14_info[62].fileTime2 = 0U;
  c14_info[63].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c14_info[63].name = "floor";
  c14_info[63].dominantType = "double";
  c14_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c14_info[63].fileLength = 332U;
  c14_info[63].fileTime1 = 1203422822U;
  c14_info[63].fileTime2 = 0U;
}

static void c14_b_info_helper(c14_ResolvedFunctionInfo c14_info[93])
{
  c14_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c14_info[64].name = "intmin";
  c14_info[64].dominantType = "char";
  c14_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c14_info[64].fileLength = 1505U;
  c14_info[64].fileTime1 = 1192445128U;
  c14_info[64].fileTime2 = 0U;
  c14_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c14_info[65].name = "zeros";
  c14_info[65].dominantType = "double";
  c14_info[65].resolved = "[B]zeros";
  c14_info[65].fileLength = 0U;
  c14_info[65].fileTime1 = 0U;
  c14_info[65].fileTime2 = 0U;
  c14_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c14_info[66].name = "transpose";
  c14_info[66].dominantType = "int32";
  c14_info[66].resolved = "[B]transpose";
  c14_info[66].fileLength = 0U;
  c14_info[66].fileTime1 = 0U;
  c14_info[66].fileTime2 = 0U;
  c14_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[67].name = "eml_index_plus";
  c14_info[67].dominantType = "int32";
  c14_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c14_info[67].fileLength = 272U;
  c14_info[67].fileTime1 = 1192445184U;
  c14_info[67].fileTime2 = 0U;
  c14_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[68].name = "eml_index_minus";
  c14_info[68].dominantType = "int32";
  c14_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c14_info[68].fileLength = 277U;
  c14_info[68].fileTime1 = 1192445184U;
  c14_info[68].fileTime2 = 0U;
  c14_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[69].name = "eml_index_times";
  c14_info[69].dominantType = "int32";
  c14_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c14_info[69].fileLength = 280U;
  c14_info[69].fileTime1 = 1192445186U;
  c14_info[69].fileTime2 = 0U;
  c14_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[70].name = "eml_ixamax";
  c14_info[70].dominantType = "int32";
  c14_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c14_info[70].fileLength = 731U;
  c14_info[70].fileTime1 = 1209309244U;
  c14_info[70].fileTime2 = 0U;
  c14_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c14_info[71].name = "eml_refblas_ixamax";
  c14_info[71].dominantType = "int32";
  c14_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c14_info[71].fileLength = 740U;
  c14_info[71].fileTime1 = 1192445266U;
  c14_info[71].fileTime2 = 0U;
  c14_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c14_info[72].name = "eml_xcabs1";
  c14_info[72].dominantType = "double";
  c14_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c14_info[72].fileLength = 419U;
  c14_info[72].fileTime1 = 1209309246U;
  c14_info[72].fileTime2 = 0U;
  c14_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c14_info[73].name = "real";
  c14_info[73].dominantType = "double";
  c14_info[73].resolved = "[B]real";
  c14_info[73].fileLength = 0U;
  c14_info[73].fileTime1 = 0U;
  c14_info[73].fileTime2 = 0U;
  c14_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c14_info[74].name = "abs";
  c14_info[74].dominantType = "double";
  c14_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[74].fileLength = 566U;
  c14_info[74].fileTime1 = 1221245532U;
  c14_info[74].fileTime2 = 0U;
  c14_info[75].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c14_info[75].name = "eml_scalar_abs";
  c14_info[75].dominantType = "double";
  c14_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c14_info[75].fileLength = 461U;
  c14_info[75].fileTime1 = 1203422760U;
  c14_info[75].fileTime2 = 0U;
  c14_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c14_info[76].name = "imag";
  c14_info[76].dominantType = "double";
  c14_info[76].resolved = "[B]imag";
  c14_info[76].fileLength = 0U;
  c14_info[76].fileTime1 = 0U;
  c14_info[76].fileTime2 = 0U;
  c14_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[77].name = "eml_xswap";
  c14_info[77].dominantType = "int32";
  c14_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c14_info[77].fileLength = 1330U;
  c14_info[77].fileTime1 = 1209309260U;
  c14_info[77].fileTime2 = 0U;
  c14_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c14_info[78].name = "eml_refblas_xswap";
  c14_info[78].dominantType = "int32";
  c14_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c14_info[78].fileLength = 905U;
  c14_info[78].fileTime1 = 1238412670U;
  c14_info[78].fileTime2 = 0U;
  c14_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c14_info[79].name = "isempty";
  c14_info[79].dominantType = "double";
  c14_info[79].resolved = "[B]isempty";
  c14_info[79].fileLength = 0U;
  c14_info[79].fileTime1 = 0U;
  c14_info[79].fileTime2 = 0U;
  c14_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c14_info[80].name = "eml_xgeru";
  c14_info[80].dominantType = "int32";
  c14_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c14_info[80].fileLength = 2462U;
  c14_info[80].fileTime1 = 1209309256U;
  c14_info[80].fileTime2 = 0U;
  c14_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c14_info[81].name = "eml_xger";
  c14_info[81].dominantType = "int32";
  c14_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c14_info[81].fileLength = 2168U;
  c14_info[81].fileTime1 = 1209309254U;
  c14_info[81].fileTime2 = 0U;
  c14_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c14_info[82].name = "eml_refblas_xger";
  c14_info[82].dominantType = "int32";
  c14_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c14_info[82].fileLength = 411U;
  c14_info[82].fileTime1 = 1211194448U;
  c14_info[82].fileTime2 = 0U;
  c14_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c14_info[83].name = "eml_refblas_xgerx";
  c14_info[83].dominantType = "int32";
  c14_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c14_info[83].fileLength = 2231U;
  c14_info[83].fileTime1 = 1238412668U;
  c14_info[83].fileTime2 = 0U;
  c14_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c14_info[84].name = "eml_ipiv2perm";
  c14_info[84].dominantType = "int32";
  c14_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_ipiv2perm.m";
  c14_info[84].fileLength = 673U;
  c14_info[84].fileTime1 = 1246588112U;
  c14_info[84].fileTime2 = 0U;
  c14_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!invNxN";
  c14_info[85].name = "eml_xtrsm";
  c14_info[85].dominantType = "int32";
  c14_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c14_info[85].fileLength = 2383U;
  c14_info[85].fileTime1 = 1209309262U;
  c14_info[85].fileTime2 = 0U;
  c14_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!itcount";
  c14_info[86].name = "length";
  c14_info[86].dominantType = "double";
  c14_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c14_info[86].fileLength = 326U;
  c14_info[86].fileTime1 = 1226552074U;
  c14_info[86].fileTime2 = 0U;
  c14_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c14_info[87].name = "eml_refblas_xtrsm";
  c14_info[87].dominantType = "int32";
  c14_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c14_info[87].fileLength = 13101U;
  c14_info[87].fileTime1 = 1252487206U;
  c14_info[87].fileTime2 = 0U;
  c14_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c14_info[88].name = "norm";
  c14_info[88].dominantType = "double";
  c14_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c14_info[88].fileLength = 5453U;
  c14_info[88].fileTime1 = 1271384008U;
  c14_info[88].fileTime2 = 0U;
  c14_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c14_info[89].name = "isnan";
  c14_info[89].dominantType = "double";
  c14_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c14_info[89].fileLength = 541U;
  c14_info[89].fileTime1 = 1271383988U;
  c14_info[89].fileTime2 = 0U;
  c14_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c14_info[90].name = "eml_guarded_nan";
  c14_info[90].dominantType = "char";
  c14_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c14_info[90].fileLength = 485U;
  c14_info[90].fileTime1 = 1192445180U;
  c14_info[90].fileTime2 = 0U;
  c14_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c14_info[91].name = "nan";
  c14_info[91].dominantType = "char";
  c14_info[91].resolved = "[B]nan";
  c14_info[91].fileLength = 0U;
  c14_info[91].fileTime1 = 0U;
  c14_info[91].fileTime2 = 0U;
  c14_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c14_info[92].name = "eml_warning";
  c14_info[92].dominantType = "char";
  c14_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c14_info[92].fileLength = 262U;
  c14_info[92].fileTime1 = 1236232078U;
  c14_info[92].fileTime2 = 0U;
}

static const mxArray *c14_f_sf_marshall(void *chartInstanceVoid, void *c14_u)
{
  const mxArray *c14_y = NULL;
  boolean_T c14_b_u;
  const mxArray *c14_b_y = NULL;
  SFc14_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc14_AugPDTaskInstanceStruct *)chartInstanceVoid;
  c14_y = NULL;
  c14_b_u = *((boolean_T *)c14_u);
  c14_b_y = NULL;
  sf_mex_assign(&c14_b_y, sf_mex_create("y", &c14_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c14_y, c14_b_y);
  return c14_y;
}

static void c14_emlrt_marshallIn(SFc14_AugPDTaskInstanceStruct *chartInstance,
  const mxArray *c14_InvJ, const char_T *c14_name,
  real_T c14_y[36])
{
  real_T c14_dv3[36];
  int32_T c14_i90;
  sf_mex_import(c14_name, sf_mex_dup(c14_InvJ), c14_dv3, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c14_i90 = 0; c14_i90 < 36; c14_i90 = c14_i90 + 1) {
    c14_y[c14_i90] = c14_dv3[c14_i90];
  }

  sf_mex_destroy(&c14_InvJ);
}

static uint8_T c14_b_emlrt_marshallIn(SFc14_AugPDTaskInstanceStruct
  *chartInstance, const mxArray *c14_b_is_active_c14_AugPDTask,
  const char_T *c14_name)
{
  uint8_T c14_y;
  uint8_T c14_u0;
  sf_mex_import(c14_name, sf_mex_dup(c14_b_is_active_c14_AugPDTask), &c14_u0, 1,
                3, 0U, 0, 0U, 0);
  c14_y = c14_u0;
  sf_mex_destroy(&c14_b_is_active_c14_AugPDTask);
  return c14_y;
}

static void init_dsm_address_info(SFc14_AugPDTaskInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c14_AugPDTask_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(538320292U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2769561808U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1328769592U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2848607883U);
}

mxArray *sf_c14_AugPDTask_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(4053018492U);
    pr[1] = (double)(269114894U);
    pr[2] = (double)(1221051442U);
    pr[3] = (double)(1612965173U);
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

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c14_AugPDTask(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"InvJ\",},{M[8],M[0],T\"is_active_c14_AugPDTask\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c14_AugPDTask_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc14_AugPDTaskInstanceStruct *chartInstance;
    chartInstance = (SFc14_AugPDTaskInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_AugPDTaskMachineNumber_,
          14,
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
          init_script_number_translation(_AugPDTaskMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_AugPDTaskMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_AugPDTaskMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EnTheta");
          _SFD_SET_DATA_PROPS(1,2,0,1,"InvJ");
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

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,81);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"spat_Jacobian",0,-1,2102);
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
            1.0,0,0,(MexFcnForType)c14_c_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 6;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c14_b_sf_marshall);
        }

        {
          real_T (*c14_EnTheta)[6];
          real_T (*c14_InvJ)[36];
          c14_InvJ = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
          c14_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c14_EnTheta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c14_InvJ);
          _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c14_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_AugPDTaskMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c14_AugPDTask(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc14_AugPDTaskInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*)
    chartInstanceVar);
  initialize_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c14_AugPDTask(void *chartInstanceVar)
{
  enable_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c14_AugPDTask(void *chartInstanceVar)
{
  disable_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c14_AugPDTask(void *chartInstanceVar)
{
  sf_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c14_AugPDTask(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c14_AugPDTask
    ((SFc14_AugPDTaskInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c14_AugPDTask();/* state var info */
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

static void sf_internal_set_sim_state_c14_AugPDTask(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c14_AugPDTask();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c14_AugPDTask(SimStruct* S)
{
  return sf_internal_get_sim_state_c14_AugPDTask(S);
}

static void sf_opaque_set_sim_state_c14_AugPDTask(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c14_AugPDTask(S, st);
}

static void sf_opaque_terminate_c14_AugPDTask(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc14_AugPDTaskInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c14_AugPDTask(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c14_AugPDTask((SFc14_AugPDTaskInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c14_AugPDTask(SimStruct *S)
{
  /* Actual parameters from chart:
     L
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"AugPDTask","AugPDTask",14);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"AugPDTask","AugPDTask",14,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"AugPDTask","AugPDTask",
      14,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"AugPDTask","AugPDTask",14,1);
      sf_mark_chart_reusable_outputs(S,"AugPDTask","AugPDTask",14,1);
    }

    sf_set_rtw_dwork_info(S,"AugPDTask","AugPDTask",14);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3425514672U));
  ssSetChecksum1(S,(3310747041U));
  ssSetChecksum2(S,(4258507281U));
  ssSetChecksum3(S,(429586589U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c14_AugPDTask(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "AugPDTask", "AugPDTask",14);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c14_AugPDTask(SimStruct *S)
{
  SFc14_AugPDTaskInstanceStruct *chartInstance;
  chartInstance = (SFc14_AugPDTaskInstanceStruct *)malloc(sizeof
    (SFc14_AugPDTaskInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc14_AugPDTaskInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c14_AugPDTask;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c14_AugPDTask;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c14_AugPDTask;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c14_AugPDTask;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c14_AugPDTask;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c14_AugPDTask;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c14_AugPDTask;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c14_AugPDTask;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c14_AugPDTask;
  chartInstance->chartInfo.mdlStart = mdlStart_c14_AugPDTask;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c14_AugPDTask;
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

void c14_AugPDTask_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c14_AugPDTask(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c14_AugPDTask(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c14_AugPDTask(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c14_AugPDTask_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
