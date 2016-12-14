/* Include files */

#include "blascompat32.h"
#include "EurlerDynJointVerifyIdn_sfun.h"
#include "c20_EurlerDynJointVerifyIdn.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "EurlerDynJointVerifyIdn_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c20_debug_family_names[9] = { "nargin", "nargout", "Pos",
  "Vel", "Acc", "DH_Min", "Param_Min", "Ft_Min", "Torque" };

static const char *c20_b_debug_family_names[4] = { "nargin", "nargout", "w",
  "wh" };

static const char *c20_c_debug_family_names[6] = { "wh", "nargin", "nargout",
  "w", "theta", "R" };

static const char *c20_d_debug_family_names[9] = { "v", "w", "R", "p", "nargin",
  "nargout", "kx", "theta", "g" };

static const char *c20_e_debug_family_names[4] = { "nargin", "nargout", "w", "W"
};

static const char *c20_f_debug_family_names[6] = { "n", "nargin", "nargout", "w",
  "theta", "R" };

static const char *c20_g_debug_family_names[10] = { "v", "w", "n", "R", "P",
  "nargin", "nargout", "xi", "theta", "g" };

static const char *c20_h_debug_family_names[7] = { "R", "P", "P_hat", "nargin",
  "nargout", "g", "Adg" };

static const char *c20_i_debug_family_names[6] = { "w", "v", "nargin", "nargout",
  "xi", "adx" };

static const char *c20_j_debug_family_names[68] = { "w_o", "w_z", "kxi1", "kxi2",
  "kxi3", "kxi4", "kxi5", "kxi6", "ez", "ex", "eo", "g01_0", "g12_0", "g23_0",
  "g34_0", "g45_0", "g56_0", "g67_0", "M1", "M2", "M3", "M4", "M5", "M6", "V0",
  "dV0", "g01", "Adinvg01", "V1", "dV1", "g12", "Adinvg12", "V2", "dV2", "g23",
  "Adinvg23", "V3", "dV3", "g34", "Adinvg34", "V4", "dV4", "g45", "Adinvg45",
  "V5", "dV5", "g56", "Adinvg56", "V6", "dV6", "Tau", "F7", "Adinvg67", "F6",
  "F5", "F4", "F3", "F2", "F1", "nargin", "nargout", "DH", "Param", "Ft", "Pos",
  "Vel", "Acc", "Torque" };

/* Function Declarations */
static void initialize_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void initialize_params_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void enable_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void disable_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void set_sim_state_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance, const mxArray
   *c20_st);
static void finalize_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void sf_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber);
static void c20_DynEulerCal_Min(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_DH[28], real_T c20_Param[60], real_T c20_Ft[6],
  real_T c20_Pos[6], real_T c20_Vel[6], real_T c20_Acc[6], real_T c20_Torque[6]);
static void c20_expWre(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_kx[6], real_T c20_theta, real_T c20_g[16]);
static real_T c20_length(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_isVariableSizing(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_eye(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                    real_T c20_I[9]);
static void c20_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_expRot(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_w[3], real_T c20_theta, real_T c20_R[9]);
static void c20_b_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_cross(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                      real_T c20_a[3], real_T c20_b[3], real_T c20_c[3]);
static void c20_c_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_d_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_expg(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                     real_T c20_xi[6], real_T c20_theta, real_T c20_g[16]);
static real_T c20_norm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_x[3]);
static real_T c20_ceval_xnrm2(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[3], int32_T c20_ix0, int32_T
  c20_incx);
static void c20_eps(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void c20_expr(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                     real_T c20_w[3], real_T c20_theta, real_T c20_R[9]);
static void c20_hat(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                    real_T c20_w[3], real_T c20_W[9]);
static void c20_matrix_to_integer_power
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance, real_T c20_a[9],
   real_T c20_b, real_T c20_c[9]);
static void c20_e_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_inv3x3(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_x[9], real_T c20_y[9]);
static real_T c20_b_norm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_x[9]);
static void c20_eml_warning(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_b_eps(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance);
static void c20_b_eml_warning(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_varargin_3);
static real_T c20_power(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_a, real_T c20_b);
static void c20_eml_error(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_mldivide(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[16], real_T c20_B[16], real_T c20_Y[16]);
static void c20_eml_matlab_zgetrf(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[16], real_T c20_b_A[16], int32_T c20_ipiv[4],
  int32_T *c20_info);
static int32_T c20_eml_ixamax(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[16], int32_T c20_ix0);
static int32_T c20_ceval_ixamax(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[16], int32_T c20_ix0, int32_T
  c20_incx);
static void c20_ceval_xswap(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[16], int32_T c20_ix0, int32_T
  c20_incx, int32_T c20_iy0, int32_T c20_incy, real_T c20_b_x[16]);
static void c20_ceval_xger(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_m, int32_T c20_n, real_T c20_alpha1, int32_T
  c20_ix0, int32_T c20_incx, int32_T c20_iy0, int32_T c20_incy, real_T c20_A[16],
  int32_T c20_ia0, int32_T c20_lda, real_T c20_b_A[16]);
static void c20_eml_xtrsm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[16], real_T c20_B[16], real_T c20_b_B[16]);
static void c20_f_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_eml_blas_xtrsm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_m, int32_T c20_n, real_T c20_alpha1, real_T c20_A
  [16], int32_T c20_ia0, int32_T c20_lda, real_T c20_B[16], int32_T c20_ib0,
  int32_T c20_ldb, real_T c20_b_B[16]);
static void c20_Adj(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                    real_T c20_g[16], real_T c20_Adg[36]);
static void c20_g_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_eml_xgemm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[36], real_T c20_B[6], real_T c20_C[6], real_T
  c20_b_C[6]);
static void c20_ad(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                   real_T c20_xi[6], real_T c20_adx[36]);
static void c20_h_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static void c20_ceval_xgemm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_m, int32_T c20_n, int32_T c20_k, real_T c20_alpha1,
  real_T c20_A[36], int32_T c20_ia0, int32_T c20_lda, real_T c20_B[36], int32_T
  c20_ib0, int32_T c20_ldb, real_T c20_beta1, real_T c20_C[36], int32_T c20_ic0,
  int32_T c20_ldc, real_T c20_b_C[36]);
static void c20_i_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);
static real_T c20_ceval_xdot(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[6], int32_T c20_ix0, int32_T
  c20_incx, real_T c20_y[6], int32_T c20_iy0, int32_T c20_incy);
static const mxArray *c20_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_b_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_c_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_d_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_e_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_f_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_g_sf_marshall(void *chartInstanceVoid, void *c20_u);
static const mxArray *c20_h_sf_marshall(void *chartInstanceVoid, void *c20_u);
static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[113]);
static void c20_b_info_helper(c20_ResolvedFunctionInfo c20_info[113]);
static const mxArray *c20_i_sf_marshall(void *chartInstanceVoid, void *c20_u);
static void c20_emlrt_marshallIn(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, const mxArray *c20_Torque, const char_T *c20_name, real_T
  c20_y[6]);
static uint8_T c20_b_emlrt_marshallIn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance, const mxArray
   *c20_b_is_active_c20_EurlerDynJointVerifyIdn, const char_T *c20_name);
static void init_dsm_address_info(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c20_is_active_c20_EurlerDynJointVerifyIdn = 0U;
}

static void initialize_params_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
  real_T c20_dv0[28];
  int32_T c20_i0;
  real_T c20_dv1[60];
  int32_T c20_i1;
  real_T c20_dv2[6];
  int32_T c20_i2;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'DH_Min' in the parent workspace.\n");
  sf_mex_import("DH_Min", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c20_dv0,
                0, 0, 0U, 1, 0U, 2, 4, 7);
  for (c20_i0 = 0; c20_i0 < 28; c20_i0 = c20_i0 + 1) {
    chartInstance->c20_DH_Min[c20_i0] = c20_dv0[c20_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Param_Min' in the parent workspace.\n");
  sf_mex_import("Param_Min", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                c20_dv1, 0, 0, 0U, 1, 0U, 1, 60);
  for (c20_i1 = 0; c20_i1 < 60; c20_i1 = c20_i1 + 1) {
    chartInstance->c20_Param_Min[c20_i1] = c20_dv1[c20_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ft_Min' in the parent workspace.\n");
  sf_mex_import("Ft_Min", sf_mex_get_sfun_param(chartInstance->S, 1, 0), c20_dv2,
                0, 0, 0U, 1, 0U, 1, 6);
  for (c20_i2 = 0; c20_i2 < 6; c20_i2 = c20_i2 + 1) {
    chartInstance->c20_Ft_Min[c20_i2] = c20_dv2[c20_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c20_update_debugger_state_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
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
  real_T (*c20_Torque)[6];
  c20_Torque = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellarray(2));
  for (c20_i3 = 0; c20_i3 < 6; c20_i3 = c20_i3 + 1) {
    c20_hoistedGlobal[c20_i3] = (*c20_Torque)[c20_i3];
  }

  for (c20_i4 = 0; c20_i4 < 6; c20_i4 = c20_i4 + 1) {
    c20_u[c20_i4] = c20_hoistedGlobal[c20_i4];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = chartInstance->c20_is_active_c20_EurlerDynJointVerifyIdn;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c20_y, 1, c20_c_y);
  sf_mex_assign(&c20_st, c20_y);
  return c20_st;
}

static void set_sim_state_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance, const mxArray *
   c20_st)
{
  const mxArray *c20_u;
  real_T c20_dv3[6];
  int32_T c20_i5;
  real_T (*c20_Torque)[6];
  c20_Torque = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c20_doneDoubleBufferReInit = TRUE;
  c20_u = sf_mex_dup(c20_st);
  c20_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 0)),
                       "Torque", c20_dv3);
  for (c20_i5 = 0; c20_i5 < 6; c20_i5 = c20_i5 + 1) {
    (*c20_Torque)[c20_i5] = c20_dv3[c20_i5];
  }

  chartInstance->c20_is_active_c20_EurlerDynJointVerifyIdn =
    c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 1)
    ), "is_active_c20_EurlerDynJointVerifyIdn");
  sf_mex_destroy(&c20_u);
  c20_update_debugger_state_c20_EurlerDynJointVerifyIdn(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void finalize_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
}

static void sf_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
  int32_T c20_i6;
  int32_T c20_i7;
  int32_T c20_i8;
  int32_T c20_i9;
  int32_T c20_i10;
  int32_T c20_i11;
  int32_T c20_i12;
  int32_T c20_previousEvent;
  int32_T c20_i13;
  real_T c20_hoistedGlobal[6];
  int32_T c20_i14;
  real_T c20_b_hoistedGlobal[6];
  int32_T c20_i15;
  real_T c20_c_hoistedGlobal[6];
  int32_T c20_i16;
  real_T c20_d_hoistedGlobal[28];
  int32_T c20_i17;
  real_T c20_e_hoistedGlobal[60];
  int32_T c20_i18;
  real_T c20_f_hoistedGlobal[6];
  int32_T c20_i19;
  real_T c20_Pos[6];
  int32_T c20_i20;
  real_T c20_Vel[6];
  int32_T c20_i21;
  real_T c20_Acc[6];
  int32_T c20_i22;
  real_T c20_b_DH_Min[28];
  int32_T c20_i23;
  real_T c20_b_Param_Min[60];
  int32_T c20_i24;
  real_T c20_b_Ft_Min[6];
  uint32_T c20_debug_family_var_map[9];
  real_T c20_nargin = 6.0;
  real_T c20_nargout = 1.0;
  real_T c20_Torque[6];
  int32_T c20_i25;
  int32_T c20_i26;
  real_T c20_c_DH_Min[28];
  int32_T c20_i27;
  real_T c20_c_Param_Min[60];
  int32_T c20_i28;
  real_T c20_c_Ft_Min[6];
  int32_T c20_i29;
  real_T c20_b_Pos[6];
  int32_T c20_i30;
  real_T c20_b_Vel[6];
  int32_T c20_i31;
  real_T c20_b_Acc[6];
  real_T c20_dv4[6];
  int32_T c20_i32;
  int32_T c20_i33;
  real_T (*c20_b_Torque)[6];
  real_T (*c20_c_Acc)[6];
  real_T (*c20_c_Vel)[6];
  real_T (*c20_c_Pos)[6];
  c20_c_Acc = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c20_c_Vel = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c20_b_Torque = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c20_c_Pos = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19);
  for (c20_i6 = 0; c20_i6 < 6; c20_i6 = c20_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_c_Pos)[c20_i6], 0U);
  }

  for (c20_i7 = 0; c20_i7 < 6; c20_i7 = c20_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_b_Torque)[c20_i7], 1U);
  }

  for (c20_i8 = 0; c20_i8 < 6; c20_i8 = c20_i8 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_c_Vel)[c20_i8], 2U);
  }

  for (c20_i9 = 0; c20_i9 < 6; c20_i9 = c20_i9 + 1) {
    _SFD_DATA_RANGE_CHECK((*c20_c_Acc)[c20_i9], 3U);
  }

  for (c20_i10 = 0; c20_i10 < 28; c20_i10 = c20_i10 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_DH_Min[c20_i10], 4U);
  }

  for (c20_i11 = 0; c20_i11 < 60; c20_i11 = c20_i11 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_Param_Min[c20_i11], 5U);
  }

  for (c20_i12 = 0; c20_i12 < 6; c20_i12 = c20_i12 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c20_Ft_Min[c20_i12], 6U);
  }

  c20_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19);
  for (c20_i13 = 0; c20_i13 < 6; c20_i13 = c20_i13 + 1) {
    c20_hoistedGlobal[c20_i13] = (*c20_c_Pos)[c20_i13];
  }

  for (c20_i14 = 0; c20_i14 < 6; c20_i14 = c20_i14 + 1) {
    c20_b_hoistedGlobal[c20_i14] = (*c20_c_Vel)[c20_i14];
  }

  for (c20_i15 = 0; c20_i15 < 6; c20_i15 = c20_i15 + 1) {
    c20_c_hoistedGlobal[c20_i15] = (*c20_c_Acc)[c20_i15];
  }

  for (c20_i16 = 0; c20_i16 < 28; c20_i16 = c20_i16 + 1) {
    c20_d_hoistedGlobal[c20_i16] = chartInstance->c20_DH_Min[c20_i16];
  }

  for (c20_i17 = 0; c20_i17 < 60; c20_i17 = c20_i17 + 1) {
    c20_e_hoistedGlobal[c20_i17] = chartInstance->c20_Param_Min[c20_i17];
  }

  for (c20_i18 = 0; c20_i18 < 6; c20_i18 = c20_i18 + 1) {
    c20_f_hoistedGlobal[c20_i18] = chartInstance->c20_Ft_Min[c20_i18];
  }

  for (c20_i19 = 0; c20_i19 < 6; c20_i19 = c20_i19 + 1) {
    c20_Pos[c20_i19] = c20_hoistedGlobal[c20_i19];
  }

  for (c20_i20 = 0; c20_i20 < 6; c20_i20 = c20_i20 + 1) {
    c20_Vel[c20_i20] = c20_b_hoistedGlobal[c20_i20];
  }

  for (c20_i21 = 0; c20_i21 < 6; c20_i21 = c20_i21 + 1) {
    c20_Acc[c20_i21] = c20_c_hoistedGlobal[c20_i21];
  }

  for (c20_i22 = 0; c20_i22 < 28; c20_i22 = c20_i22 + 1) {
    c20_b_DH_Min[c20_i22] = c20_d_hoistedGlobal[c20_i22];
  }

  for (c20_i23 = 0; c20_i23 < 60; c20_i23 = c20_i23 + 1) {
    c20_b_Param_Min[c20_i23] = c20_e_hoistedGlobal[c20_i23];
  }

  for (c20_i24 = 0; c20_i24 < 6; c20_i24 = c20_i24 + 1) {
    c20_b_Ft_Min[c20_i24] = c20_f_hoistedGlobal[c20_i24];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c20_debug_family_names,
    c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_Pos, c20_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_Vel, c20_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c20_Acc, c20_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c20_b_DH_Min, c20_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c20_b_Param_Min, c20_b_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c20_b_Ft_Min, c20_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c20_Torque, c20_sf_marshall, 8U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c20_i25 = 0; c20_i25 < 6; c20_i25 = c20_i25 + 1) {
    c20_Torque[c20_i25] = 0.0;
  }

  _SFD_EML_CALL(0, 4);
  for (c20_i26 = 0; c20_i26 < 28; c20_i26 = c20_i26 + 1) {
    c20_c_DH_Min[c20_i26] = c20_b_DH_Min[c20_i26];
  }

  for (c20_i27 = 0; c20_i27 < 60; c20_i27 = c20_i27 + 1) {
    c20_c_Param_Min[c20_i27] = c20_b_Param_Min[c20_i27];
  }

  for (c20_i28 = 0; c20_i28 < 6; c20_i28 = c20_i28 + 1) {
    c20_c_Ft_Min[c20_i28] = c20_b_Ft_Min[c20_i28];
  }

  for (c20_i29 = 0; c20_i29 < 6; c20_i29 = c20_i29 + 1) {
    c20_b_Pos[c20_i29] = c20_Pos[c20_i29];
  }

  for (c20_i30 = 0; c20_i30 < 6; c20_i30 = c20_i30 + 1) {
    c20_b_Vel[c20_i30] = c20_Vel[c20_i30];
  }

  for (c20_i31 = 0; c20_i31 < 6; c20_i31 = c20_i31 + 1) {
    c20_b_Acc[c20_i31] = c20_Acc[c20_i31];
  }

  c20_DynEulerCal_Min(chartInstance, c20_c_DH_Min, c20_c_Param_Min, c20_c_Ft_Min,
                      c20_b_Pos, c20_b_Vel, c20_b_Acc, c20_dv4);
  for (c20_i32 = 0; c20_i32 < 6; c20_i32 = c20_i32 + 1) {
    c20_Torque[c20_i32] = c20_dv4[c20_i32];
  }

  _SFD_EML_CALL(0, -4);
  sf_debug_symbol_scope_pop();
  for (c20_i33 = 0; c20_i33 < 6; c20_i33 = c20_i33 + 1) {
    (*c20_b_Torque)[c20_i33] = c20_Torque[c20_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19);
  _sfEvent_ = c20_previousEvent;
  sf_debug_check_for_state_inconsistency(_EurlerDynJointVerifyIdnMachineNumber_,
    chartInstance->chartNumber, chartInstance->
    instanceNumber);
}

static void compInitSubchartSimstructsFcn_c20_EurlerDynJointVerifyIdn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/DynEulerCal_Min.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 1U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/expWre.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 2U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/expRot.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 3U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/skew.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 4U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expg.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 5U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expr.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 6U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/GoogolTraj/basicfunction/hat.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 7U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/basicfunction/Adj.m"));
  _SFD_SCRIPT_TRANSLATION(c20_chartNumber, 8U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/GoogolTraj/basicfunction/ad.m"));
}

static void c20_DynEulerCal_Min(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_DH[28], real_T c20_Param[60]
  , real_T c20_Ft[6], real_T c20_Pos[6], real_T c20_Vel[6], real_T c20_Acc[6],
  real_T c20_Torque[6])
{
  uint32_T c20_debug_family_var_map[68];
  static const char *c20_sv0[68] = { "w_o", "w_z", "kxi1", "kxi2", "kxi3",
    "kxi4", "kxi5", "kxi6", "ez", "ex", "eo", "g01_0", "g12_0"
    , "g23_0", "g34_0", "g45_0", "g56_0", "g67_0", "M1", "M2", "M3", "M4", "M5",
    "M6", "V0", "dV0",
    "g01", "Adinvg01", "V1", "dV1", "g12", "Adinvg12", "V2", "dV2", "g23",
    "Adinvg23", "V3", "dV3",
    "g34", "Adinvg34", "V4", "dV4", "g45", "Adinvg45", "V5", "dV5", "g56",
    "Adinvg56", "V6", "dV6",
    "Tau", "F7", "Adinvg67", "F6", "F5", "F4", "F3", "F2", "F1", "nargin",
    "nargout", "DH", "Param",
    "Ft", "Pos", "Vel", "Acc", "Torque" };

  real_T c20_w_o[3];
  real_T c20_w_z[3];
  real_T c20_kxi1[6];
  real_T c20_kxi2[6];
  real_T c20_kxi3[6];
  real_T c20_kxi4[6];
  real_T c20_kxi5[6];
  real_T c20_kxi6[6];
  real_T c20_ez[3];
  real_T c20_ex[3];
  real_T c20_eo[3];
  real_T c20_g01_0[16];
  real_T c20_g12_0[16];
  real_T c20_g23_0[16];
  real_T c20_g34_0[16];
  real_T c20_g45_0[16];
  real_T c20_g56_0[16];
  real_T c20_g67_0[16];
  real_T c20_M1[36];
  real_T c20_M2[36];
  real_T c20_M3[36];
  real_T c20_M4[36];
  real_T c20_M5[36];
  real_T c20_M6[36];
  real_T c20_V0[6];
  real_T c20_dV0[6];
  real_T c20_g01[16];
  real_T c20_Adinvg01[36];
  real_T c20_V1[6];
  real_T c20_dV1[6];
  real_T c20_g12[16];
  real_T c20_Adinvg12[36];
  real_T c20_V2[6];
  real_T c20_dV2[6];
  real_T c20_g23[16];
  real_T c20_Adinvg23[36];
  real_T c20_V3[6];
  real_T c20_dV3[6];
  real_T c20_g34[16];
  real_T c20_Adinvg34[36];
  real_T c20_V4[6];
  real_T c20_dV4[6];
  real_T c20_g45[16];
  real_T c20_Adinvg45[36];
  real_T c20_V5[6];
  real_T c20_dV5[6];
  real_T c20_g56[16];
  real_T c20_Adinvg56[36];
  real_T c20_V6[6];
  real_T c20_dV6[6];
  real_T c20_Tau[6];
  real_T c20_F7[6];
  real_T c20_Adinvg67[36];
  real_T c20_F6[6];
  real_T c20_F5[6];
  real_T c20_F4[6];
  real_T c20_F3[6];
  real_T c20_F2[6];
  real_T c20_F1[6];
  real_T c20_nargin = 6.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i34;
  int32_T c20_i35;
  static real_T c20_dv5[3] = { 0.0, 0.0, 1.0 };

  int32_T c20_i36;
  static real_T c20_dv6[6] = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c20_i37;
  int32_T c20_i38;
  int32_T c20_i39;
  int32_T c20_i40;
  int32_T c20_i41;
  int32_T c20_i42;
  int32_T c20_i43;
  static real_T c20_dv7[3] = { 1.0, 0.0, 0.0 };

  int32_T c20_i44;
  int32_T c20_i45;
  static real_T c20_dv8[6] = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  real_T c20_dv9[6];
  real_T c20_a[16];
  int32_T c20_i46;
  static real_T c20_dv10[6] = { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };

  real_T c20_dv11[6];
  real_T c20_b[16];
  int32_T c20_i47;
  real_T c20_A[16];
  int32_T c20_i48;
  real_T c20_B[16];
  int32_T c20_i49;
  real_T c20_b_A[16];
  int32_T c20_i50;
  real_T c20_b_B[16];
  int32_T c20_i51;
  real_T c20_c_A[16];
  int32_T c20_i52;
  real_T c20_c_B[16];
  int32_T c20_i53;
  int32_T c20_i54;
  int32_T c20_i55;
  real_T c20_y[16];
  int32_T c20_i56;
  int32_T c20_i57;
  int32_T c20_i58;
  real_T c20_b_a[16];
  int32_T c20_i59;
  static real_T c20_dv12[6] = { 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 };

  real_T c20_dv13[6];
  real_T c20_b_b[16];
  int32_T c20_i60;
  real_T c20_d_A[16];
  int32_T c20_i61;
  real_T c20_d_B[16];
  int32_T c20_i62;
  real_T c20_e_A[16];
  int32_T c20_i63;
  real_T c20_e_B[16];
  int32_T c20_i64;
  real_T c20_f_A[16];
  int32_T c20_i65;
  real_T c20_f_B[16];
  int32_T c20_i66;
  int32_T c20_i67;
  int32_T c20_i68;
  real_T c20_b_y[16];
  int32_T c20_i69;
  int32_T c20_i70;
  int32_T c20_i71;
  real_T c20_c_a[16];
  int32_T c20_i72;
  real_T c20_dv14[6];
  real_T c20_c_b[16];
  int32_T c20_i73;
  real_T c20_g_A[16];
  int32_T c20_i74;
  real_T c20_g_B[16];
  int32_T c20_i75;
  int32_T c20_i76;
  real_T c20_h_A[16];
  int32_T c20_i77;
  real_T c20_h_B[16];
  int32_T c20_i78;
  real_T c20_i_A[16];
  int32_T c20_i79;
  real_T c20_i_B[16];
  int32_T c20_i80;
  int32_T c20_i81;
  int32_T c20_i82;
  int32_T c20_i83;
  int32_T c20_i84;
  int32_T c20_i85;
  real_T c20_dv15[6];
  real_T c20_d_a[16];
  int32_T c20_i86;
  real_T c20_dv16[6];
  real_T c20_d_b[16];
  int32_T c20_i87;
  real_T c20_j_A[16];
  int32_T c20_i88;
  real_T c20_j_B[16];
  int32_T c20_i89;
  real_T c20_k_A[16];
  int32_T c20_i90;
  real_T c20_k_B[16];
  int32_T c20_i91;
  real_T c20_l_A[16];
  int32_T c20_i92;
  real_T c20_l_B[16];
  int32_T c20_i93;
  int32_T c20_i94;
  int32_T c20_i95;
  real_T c20_c_y[16];
  int32_T c20_i96;
  int32_T c20_i97;
  int32_T c20_i98;
  real_T c20_e_a[16];
  int32_T c20_i99;
  real_T c20_dv17[6];
  real_T c20_e_b[16];
  int32_T c20_i100;
  real_T c20_m_A[16];
  int32_T c20_i101;
  real_T c20_m_B[16];
  int32_T c20_i102;
  real_T c20_n_A[16];
  int32_T c20_i103;
  real_T c20_n_B[16];
  int32_T c20_i104;
  real_T c20_o_A[16];
  int32_T c20_i105;
  real_T c20_o_B[16];
  int32_T c20_i106;
  int32_T c20_i107;
  int32_T c20_i108;
  real_T c20_d_y[16];
  int32_T c20_i109;
  int32_T c20_i110;
  int32_T c20_i111;
  real_T c20_f_a[16];
  int32_T c20_i112;
  real_T c20_dv18[6];
  real_T c20_f_b[16];
  int32_T c20_i113;
  real_T c20_p_A[16];
  int32_T c20_i114;
  real_T c20_p_B[16];
  int32_T c20_i115;
  int32_T c20_i116;
  real_T c20_q_A[16];
  int32_T c20_i117;
  real_T c20_q_B[16];
  int32_T c20_i118;
  real_T c20_r_A[16];
  int32_T c20_i119;
  real_T c20_r_B[16];
  int32_T c20_i120;
  int32_T c20_i121;
  int32_T c20_i122;
  int32_T c20_i123;
  int32_T c20_i124;
  int32_T c20_i125;
  real_T c20_dv19[6];
  real_T c20_g_a[16];
  int32_T c20_i126;
  real_T c20_dv20[6];
  real_T c20_g_b[16];
  int32_T c20_i127;
  real_T c20_s_A[16];
  int32_T c20_i128;
  real_T c20_s_B[16];
  int32_T c20_i129;
  real_T c20_t_A[16];
  int32_T c20_i130;
  real_T c20_t_B[16];
  int32_T c20_i131;
  real_T c20_u_A[16];
  int32_T c20_i132;
  real_T c20_u_B[16];
  int32_T c20_i133;
  int32_T c20_i134;
  int32_T c20_i135;
  real_T c20_e_y[16];
  int32_T c20_i136;
  int32_T c20_i137;
  int32_T c20_i138;
  real_T c20_h_a[16];
  int32_T c20_i139;
  real_T c20_dv21[6];
  real_T c20_h_b[16];
  int32_T c20_i140;
  real_T c20_v_A[16];
  int32_T c20_i141;
  real_T c20_v_B[16];
  int32_T c20_i142;
  real_T c20_w_A[16];
  int32_T c20_i143;
  real_T c20_w_B[16];
  int32_T c20_i144;
  real_T c20_x_A[16];
  int32_T c20_i145;
  real_T c20_x_B[16];
  int32_T c20_i146;
  int32_T c20_i147;
  int32_T c20_i148;
  real_T c20_f_y[16];
  int32_T c20_i149;
  int32_T c20_i150;
  int32_T c20_i151;
  real_T c20_i_a[16];
  int32_T c20_i152;
  real_T c20_dv22[6];
  real_T c20_i_b[16];
  int32_T c20_i153;
  real_T c20_y_A[16];
  int32_T c20_i154;
  real_T c20_y_B[16];
  int32_T c20_i155;
  int32_T c20_i156;
  real_T c20_ab_A[16];
  int32_T c20_i157;
  real_T c20_ab_B[16];
  int32_T c20_i158;
  real_T c20_bb_A[16];
  int32_T c20_i159;
  real_T c20_bb_B[16];
  int32_T c20_i160;
  int32_T c20_i161;
  int32_T c20_i162;
  int32_T c20_i163;
  int32_T c20_i164;
  int32_T c20_i165;
  real_T c20_dv23[6];
  real_T c20_j_a[16];
  int32_T c20_i166;
  real_T c20_dv24[6];
  real_T c20_j_b[16];
  int32_T c20_i167;
  real_T c20_cb_A[16];
  int32_T c20_i168;
  real_T c20_cb_B[16];
  int32_T c20_i169;
  real_T c20_db_A[16];
  int32_T c20_i170;
  real_T c20_db_B[16];
  int32_T c20_i171;
  real_T c20_eb_A[16];
  int32_T c20_i172;
  real_T c20_eb_B[16];
  int32_T c20_i173;
  int32_T c20_i174;
  int32_T c20_i175;
  real_T c20_g_y[16];
  int32_T c20_i176;
  int32_T c20_i177;
  int32_T c20_i178;
  real_T c20_k_a[16];
  int32_T c20_i179;
  real_T c20_dv25[6];
  real_T c20_k_b[16];
  int32_T c20_i180;
  real_T c20_fb_A[16];
  int32_T c20_i181;
  real_T c20_fb_B[16];
  int32_T c20_i182;
  real_T c20_gb_A[16];
  int32_T c20_i183;
  real_T c20_gb_B[16];
  int32_T c20_i184;
  real_T c20_hb_A[16];
  int32_T c20_i185;
  real_T c20_hb_B[16];
  int32_T c20_i186;
  int32_T c20_i187;
  int32_T c20_i188;
  real_T c20_h_y[16];
  int32_T c20_i189;
  int32_T c20_i190;
  int32_T c20_i191;
  real_T c20_l_a[16];
  int32_T c20_i192;
  real_T c20_dv26[6];
  real_T c20_l_b[16];
  int32_T c20_i193;
  real_T c20_ib_A[16];
  int32_T c20_i194;
  real_T c20_ib_B[16];
  int32_T c20_i195;
  int32_T c20_i196;
  real_T c20_jb_A[16];
  int32_T c20_i197;
  real_T c20_jb_B[16];
  int32_T c20_i198;
  real_T c20_kb_A[16];
  int32_T c20_i199;
  real_T c20_kb_B[16];
  int32_T c20_i200;
  int32_T c20_i201;
  int32_T c20_i202;
  int32_T c20_i203;
  int32_T c20_i204;
  int32_T c20_i205;
  real_T c20_dv27[6];
  real_T c20_m_a[16];
  int32_T c20_i206;
  real_T c20_dv28[6];
  real_T c20_m_b[16];
  int32_T c20_i207;
  real_T c20_lb_A[16];
  int32_T c20_i208;
  real_T c20_lb_B[16];
  int32_T c20_i209;
  real_T c20_mb_A[16];
  int32_T c20_i210;
  real_T c20_mb_B[16];
  int32_T c20_i211;
  real_T c20_nb_A[16];
  int32_T c20_i212;
  real_T c20_nb_B[16];
  int32_T c20_i213;
  int32_T c20_i214;
  int32_T c20_i215;
  real_T c20_i_y[16];
  int32_T c20_i216;
  int32_T c20_i217;
  int32_T c20_i218;
  real_T c20_n_a[16];
  int32_T c20_i219;
  real_T c20_dv29[6];
  real_T c20_n_b[16];
  int32_T c20_i220;
  real_T c20_ob_A[16];
  int32_T c20_i221;
  real_T c20_ob_B[16];
  int32_T c20_i222;
  real_T c20_pb_A[16];
  int32_T c20_i223;
  real_T c20_pb_B[16];
  int32_T c20_i224;
  real_T c20_qb_A[16];
  int32_T c20_i225;
  real_T c20_qb_B[16];
  int32_T c20_i226;
  int32_T c20_i227;
  int32_T c20_i228;
  real_T c20_j_y[16];
  int32_T c20_i229;
  int32_T c20_i230;
  int32_T c20_i231;
  real_T c20_o_a[16];
  int32_T c20_i232;
  real_T c20_dv30[6];
  real_T c20_o_b[16];
  int32_T c20_i233;
  real_T c20_rb_A[16];
  int32_T c20_i234;
  real_T c20_rb_B[16];
  int32_T c20_i235;
  int32_T c20_i236;
  real_T c20_sb_A[16];
  int32_T c20_i237;
  real_T c20_sb_B[16];
  int32_T c20_i238;
  real_T c20_tb_A[16];
  int32_T c20_i239;
  real_T c20_tb_B[16];
  int32_T c20_i240;
  int32_T c20_i241;
  int32_T c20_i242;
  int32_T c20_i243;
  int32_T c20_i244;
  int32_T c20_i245;
  real_T c20_dv31[6];
  real_T c20_p_a[16];
  int32_T c20_i246;
  real_T c20_dv32[6];
  real_T c20_p_b[16];
  int32_T c20_i247;
  real_T c20_ub_A[16];
  int32_T c20_i248;
  real_T c20_ub_B[16];
  int32_T c20_i249;
  real_T c20_vb_A[16];
  int32_T c20_i250;
  real_T c20_vb_B[16];
  int32_T c20_i251;
  real_T c20_wb_A[16];
  int32_T c20_i252;
  real_T c20_wb_B[16];
  int32_T c20_i253;
  int32_T c20_i254;
  int32_T c20_i255;
  real_T c20_k_y[16];
  int32_T c20_i256;
  int32_T c20_i257;
  int32_T c20_i258;
  real_T c20_q_a[16];
  int32_T c20_i259;
  real_T c20_dv33[6];
  real_T c20_q_b[16];
  int32_T c20_i260;
  real_T c20_xb_A[16];
  int32_T c20_i261;
  real_T c20_xb_B[16];
  int32_T c20_i262;
  real_T c20_yb_A[16];
  int32_T c20_i263;
  real_T c20_yb_B[16];
  int32_T c20_i264;
  real_T c20_ac_A[16];
  int32_T c20_i265;
  real_T c20_ac_B[16];
  int32_T c20_i266;
  int32_T c20_i267;
  int32_T c20_i268;
  real_T c20_l_y[16];
  int32_T c20_i269;
  int32_T c20_i270;
  int32_T c20_i271;
  real_T c20_r_a[16];
  int32_T c20_i272;
  real_T c20_dv34[6];
  real_T c20_r_b[16];
  int32_T c20_i273;
  real_T c20_bc_A[16];
  int32_T c20_i274;
  real_T c20_bc_B[16];
  int32_T c20_i275;
  int32_T c20_i276;
  real_T c20_cc_A[16];
  int32_T c20_i277;
  real_T c20_cc_B[16];
  int32_T c20_i278;
  real_T c20_dc_A[16];
  int32_T c20_i279;
  real_T c20_dc_B[16];
  int32_T c20_i280;
  int32_T c20_i281;
  int32_T c20_i282;
  int32_T c20_i283;
  int32_T c20_i284;
  int32_T c20_i285;
  real_T c20_dv35[6];
  real_T c20_s_a[16];
  int32_T c20_i286;
  real_T c20_dv36[6];
  real_T c20_s_b[16];
  int32_T c20_i287;
  real_T c20_ec_A[16];
  int32_T c20_i288;
  real_T c20_ec_B[16];
  int32_T c20_i289;
  real_T c20_fc_A[16];
  int32_T c20_i290;
  real_T c20_fc_B[16];
  int32_T c20_i291;
  real_T c20_gc_A[16];
  int32_T c20_i292;
  real_T c20_gc_B[16];
  int32_T c20_i293;
  int32_T c20_i294;
  int32_T c20_i295;
  real_T c20_m_y[16];
  int32_T c20_i296;
  int32_T c20_i297;
  int32_T c20_i298;
  real_T c20_t_a[16];
  int32_T c20_i299;
  real_T c20_dv37[6];
  real_T c20_t_b[16];
  int32_T c20_i300;
  real_T c20_hc_A[16];
  int32_T c20_i301;
  real_T c20_hc_B[16];
  int32_T c20_i302;
  real_T c20_ic_A[16];
  int32_T c20_i303;
  real_T c20_ic_B[16];
  int32_T c20_i304;
  real_T c20_jc_A[16];
  int32_T c20_i305;
  real_T c20_jc_B[16];
  int32_T c20_i306;
  int32_T c20_i307;
  int32_T c20_i308;
  real_T c20_n_y[16];
  int32_T c20_i309;
  int32_T c20_i310;
  int32_T c20_i311;
  real_T c20_u_a[16];
  int32_T c20_i312;
  real_T c20_dv38[6];
  real_T c20_u_b[16];
  int32_T c20_i313;
  real_T c20_kc_A[16];
  int32_T c20_i314;
  real_T c20_kc_B[16];
  int32_T c20_i315;
  int32_T c20_i316;
  real_T c20_lc_A[16];
  int32_T c20_i317;
  real_T c20_lc_B[16];
  int32_T c20_i318;
  real_T c20_mc_A[16];
  int32_T c20_i319;
  real_T c20_mc_B[16];
  int32_T c20_i320;
  int32_T c20_i321;
  int32_T c20_i322;
  int32_T c20_i323;
  int32_T c20_i324;
  int32_T c20_i325;
  int32_T c20_i326;
  static real_T c20_dv39[6] = { 0.0, 0.0, 9.8, 0.0, 0.0, 0.0 };

  int32_T c20_i327;
  real_T c20_v_a[16];
  int32_T c20_i328;
  real_T c20_dv40[6];
  real_T c20_v_b[16];
  int32_T c20_i329;
  real_T c20_nc_A[16];
  int32_T c20_i330;
  real_T c20_nc_B[16];
  int32_T c20_i331;
  int32_T c20_i332;
  real_T c20_oc_A[16];
  int32_T c20_i333;
  real_T c20_oc_B[16];
  int32_T c20_i334;
  real_T c20_pc_A[16];
  int32_T c20_i335;
  real_T c20_pc_B[16];
  int32_T c20_i336;
  int32_T c20_i337;
  int32_T c20_i338;
  int32_T c20_i339;
  int32_T c20_i340;
  int32_T c20_i341;
  real_T c20_b_g01[16];
  int32_T c20_i342;
  static real_T c20_dv41[16] = { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  real_T c20_dv42[16];
  real_T c20_dv43[16];
  int32_T c20_i343;
  real_T c20_dv44[16];
  real_T c20_dv45[36];
  int32_T c20_i344;
  int32_T c20_i345;
  real_T c20_w_a[36];
  int32_T c20_i346;
  real_T c20_x_a[36];
  int32_T c20_i347;
  real_T c20_dv46[6];
  int32_T c20_i348;
  real_T c20_dv47[6];
  real_T c20_o_y[6];
  real_T c20_w_b;
  int32_T c20_i349;
  real_T c20_p_y[6];
  int32_T c20_i350;
  real_T c20_x_b;
  int32_T c20_i351;
  real_T c20_q_y[6];
  int32_T c20_i352;
  real_T c20_y_a[36];
  int32_T c20_i353;
  real_T c20_ab_a[36];
  int32_T c20_i354;
  real_T c20_dv48[6];
  int32_T c20_i355;
  real_T c20_dv49[6];
  real_T c20_r_y[6];
  real_T c20_y_b;
  int32_T c20_i356;
  real_T c20_s_y[6];
  int32_T c20_i357;
  real_T c20_bb_a[36];
  int32_T c20_i358;
  real_T c20_cb_a[36];
  int32_T c20_i359;
  real_T c20_dv50[6];
  int32_T c20_i360;
  real_T c20_dv51[6];
  real_T c20_t_y[6];
  int32_T c20_i361;
  real_T c20_u_y[6];
  real_T c20_db_a[36];
  int32_T c20_i362;
  real_T c20_ab_b[6];
  int32_T c20_i363;
  real_T c20_eb_a[36];
  int32_T c20_i364;
  real_T c20_bb_b[6];
  int32_T c20_i365;
  real_T c20_dv52[6];
  real_T c20_v_y[6];
  int32_T c20_i366;
  int32_T c20_i367;
  real_T c20_fb_a[16];
  int32_T c20_i368;
  real_T c20_dv53[6];
  real_T c20_cb_b[16];
  int32_T c20_i369;
  real_T c20_qc_A[16];
  int32_T c20_i370;
  real_T c20_qc_B[16];
  int32_T c20_i371;
  int32_T c20_i372;
  real_T c20_rc_A[16];
  int32_T c20_i373;
  real_T c20_rc_B[16];
  int32_T c20_i374;
  real_T c20_sc_A[16];
  int32_T c20_i375;
  real_T c20_sc_B[16];
  int32_T c20_i376;
  int32_T c20_i377;
  int32_T c20_i378;
  int32_T c20_i379;
  int32_T c20_i380;
  int32_T c20_i381;
  real_T c20_b_g12[16];
  int32_T c20_i382;
  real_T c20_dv54[16];
  real_T c20_dv55[16];
  int32_T c20_i383;
  real_T c20_dv56[16];
  real_T c20_dv57[36];
  int32_T c20_i384;
  int32_T c20_i385;
  real_T c20_gb_a[36];
  int32_T c20_i386;
  real_T c20_db_b[6];
  int32_T c20_i387;
  real_T c20_hb_a[36];
  int32_T c20_i388;
  real_T c20_eb_b[6];
  int32_T c20_i389;
  real_T c20_dv58[6];
  real_T c20_w_y[6];
  real_T c20_fb_b;
  int32_T c20_i390;
  real_T c20_x_y[6];
  int32_T c20_i391;
  real_T c20_gb_b;
  int32_T c20_i392;
  real_T c20_y_y[6];
  int32_T c20_i393;
  real_T c20_ib_a[36];
  int32_T c20_i394;
  real_T c20_hb_b[6];
  int32_T c20_i395;
  real_T c20_jb_a[36];
  int32_T c20_i396;
  real_T c20_ib_b[6];
  int32_T c20_i397;
  real_T c20_dv59[6];
  real_T c20_ab_y[6];
  real_T c20_jb_b;
  int32_T c20_i398;
  real_T c20_bb_y[6];
  int32_T c20_i399;
  real_T c20_kb_a[36];
  int32_T c20_i400;
  real_T c20_kb_b[6];
  int32_T c20_i401;
  real_T c20_lb_a[36];
  int32_T c20_i402;
  real_T c20_lb_b[6];
  int32_T c20_i403;
  real_T c20_dv60[6];
  real_T c20_cb_y[6];
  int32_T c20_i404;
  real_T c20_db_y[6];
  real_T c20_mb_a[36];
  int32_T c20_i405;
  real_T c20_mb_b[6];
  int32_T c20_i406;
  real_T c20_nb_a[36];
  int32_T c20_i407;
  real_T c20_nb_b[6];
  int32_T c20_i408;
  real_T c20_dv61[6];
  real_T c20_eb_y[6];
  int32_T c20_i409;
  int32_T c20_i410;
  real_T c20_ob_a[16];
  int32_T c20_i411;
  real_T c20_dv62[6];
  real_T c20_ob_b[16];
  int32_T c20_i412;
  real_T c20_tc_A[16];
  int32_T c20_i413;
  real_T c20_tc_B[16];
  int32_T c20_i414;
  int32_T c20_i415;
  real_T c20_uc_A[16];
  int32_T c20_i416;
  real_T c20_uc_B[16];
  int32_T c20_i417;
  real_T c20_vc_A[16];
  int32_T c20_i418;
  real_T c20_vc_B[16];
  int32_T c20_i419;
  int32_T c20_i420;
  int32_T c20_i421;
  int32_T c20_i422;
  int32_T c20_i423;
  int32_T c20_i424;
  real_T c20_b_g23[16];
  int32_T c20_i425;
  real_T c20_dv63[16];
  real_T c20_dv64[16];
  int32_T c20_i426;
  real_T c20_dv65[16];
  real_T c20_dv66[36];
  int32_T c20_i427;
  int32_T c20_i428;
  real_T c20_pb_a[36];
  int32_T c20_i429;
  real_T c20_pb_b[6];
  int32_T c20_i430;
  real_T c20_qb_a[36];
  int32_T c20_i431;
  real_T c20_qb_b[6];
  int32_T c20_i432;
  real_T c20_dv67[6];
  real_T c20_fb_y[6];
  real_T c20_rb_b;
  int32_T c20_i433;
  real_T c20_gb_y[6];
  int32_T c20_i434;
  real_T c20_sb_b;
  int32_T c20_i435;
  real_T c20_hb_y[6];
  int32_T c20_i436;
  real_T c20_rb_a[36];
  int32_T c20_i437;
  real_T c20_tb_b[6];
  int32_T c20_i438;
  real_T c20_sb_a[36];
  int32_T c20_i439;
  real_T c20_ub_b[6];
  int32_T c20_i440;
  real_T c20_dv68[6];
  real_T c20_ib_y[6];
  real_T c20_vb_b;
  int32_T c20_i441;
  real_T c20_jb_y[6];
  int32_T c20_i442;
  real_T c20_tb_a[36];
  int32_T c20_i443;
  real_T c20_wb_b[6];
  int32_T c20_i444;
  real_T c20_ub_a[36];
  int32_T c20_i445;
  real_T c20_xb_b[6];
  int32_T c20_i446;
  real_T c20_dv69[6];
  real_T c20_kb_y[6];
  int32_T c20_i447;
  real_T c20_lb_y[6];
  real_T c20_vb_a[36];
  int32_T c20_i448;
  real_T c20_yb_b[6];
  int32_T c20_i449;
  real_T c20_wb_a[36];
  int32_T c20_i450;
  real_T c20_ac_b[6];
  int32_T c20_i451;
  real_T c20_dv70[6];
  real_T c20_mb_y[6];
  int32_T c20_i452;
  int32_T c20_i453;
  real_T c20_xb_a[16];
  int32_T c20_i454;
  real_T c20_dv71[6];
  real_T c20_bc_b[16];
  int32_T c20_i455;
  real_T c20_wc_A[16];
  int32_T c20_i456;
  real_T c20_wc_B[16];
  int32_T c20_i457;
  int32_T c20_i458;
  real_T c20_xc_A[16];
  int32_T c20_i459;
  real_T c20_xc_B[16];
  int32_T c20_i460;
  real_T c20_yc_A[16];
  int32_T c20_i461;
  real_T c20_yc_B[16];
  int32_T c20_i462;
  int32_T c20_i463;
  int32_T c20_i464;
  int32_T c20_i465;
  int32_T c20_i466;
  int32_T c20_i467;
  real_T c20_b_g34[16];
  int32_T c20_i468;
  real_T c20_dv72[16];
  real_T c20_dv73[16];
  int32_T c20_i469;
  real_T c20_dv74[16];
  real_T c20_dv75[36];
  int32_T c20_i470;
  int32_T c20_i471;
  real_T c20_yb_a[36];
  int32_T c20_i472;
  real_T c20_cc_b[6];
  int32_T c20_i473;
  real_T c20_ac_a[36];
  int32_T c20_i474;
  real_T c20_dc_b[6];
  int32_T c20_i475;
  real_T c20_dv76[6];
  real_T c20_nb_y[6];
  real_T c20_ec_b;
  int32_T c20_i476;
  real_T c20_ob_y[6];
  int32_T c20_i477;
  real_T c20_fc_b;
  int32_T c20_i478;
  real_T c20_pb_y[6];
  int32_T c20_i479;
  real_T c20_bc_a[36];
  int32_T c20_i480;
  real_T c20_gc_b[6];
  int32_T c20_i481;
  real_T c20_cc_a[36];
  int32_T c20_i482;
  real_T c20_hc_b[6];
  int32_T c20_i483;
  real_T c20_dv77[6];
  real_T c20_qb_y[6];
  real_T c20_ic_b;
  int32_T c20_i484;
  real_T c20_rb_y[6];
  int32_T c20_i485;
  real_T c20_dc_a[36];
  int32_T c20_i486;
  real_T c20_jc_b[6];
  int32_T c20_i487;
  real_T c20_ec_a[36];
  int32_T c20_i488;
  real_T c20_kc_b[6];
  int32_T c20_i489;
  real_T c20_dv78[6];
  real_T c20_sb_y[6];
  int32_T c20_i490;
  real_T c20_tb_y[6];
  real_T c20_fc_a[36];
  int32_T c20_i491;
  real_T c20_lc_b[6];
  int32_T c20_i492;
  real_T c20_gc_a[36];
  int32_T c20_i493;
  real_T c20_mc_b[6];
  int32_T c20_i494;
  real_T c20_dv79[6];
  real_T c20_ub_y[6];
  int32_T c20_i495;
  int32_T c20_i496;
  real_T c20_hc_a[16];
  int32_T c20_i497;
  real_T c20_dv80[6];
  real_T c20_nc_b[16];
  int32_T c20_i498;
  real_T c20_ad_A[16];
  int32_T c20_i499;
  real_T c20_ad_B[16];
  int32_T c20_i500;
  int32_T c20_i501;
  real_T c20_bd_A[16];
  int32_T c20_i502;
  real_T c20_bd_B[16];
  int32_T c20_i503;
  real_T c20_cd_A[16];
  int32_T c20_i504;
  real_T c20_cd_B[16];
  int32_T c20_i505;
  int32_T c20_i506;
  int32_T c20_i507;
  int32_T c20_i508;
  int32_T c20_i509;
  int32_T c20_i510;
  real_T c20_b_g45[16];
  int32_T c20_i511;
  real_T c20_dv81[16];
  real_T c20_dv82[16];
  int32_T c20_i512;
  real_T c20_dv83[16];
  real_T c20_dv84[36];
  int32_T c20_i513;
  int32_T c20_i514;
  real_T c20_ic_a[36];
  int32_T c20_i515;
  real_T c20_oc_b[6];
  int32_T c20_i516;
  real_T c20_jc_a[36];
  int32_T c20_i517;
  real_T c20_pc_b[6];
  int32_T c20_i518;
  real_T c20_dv85[6];
  real_T c20_vb_y[6];
  real_T c20_qc_b;
  int32_T c20_i519;
  real_T c20_wb_y[6];
  int32_T c20_i520;
  real_T c20_rc_b;
  int32_T c20_i521;
  real_T c20_xb_y[6];
  int32_T c20_i522;
  real_T c20_kc_a[36];
  int32_T c20_i523;
  real_T c20_sc_b[6];
  int32_T c20_i524;
  real_T c20_lc_a[36];
  int32_T c20_i525;
  real_T c20_tc_b[6];
  int32_T c20_i526;
  real_T c20_dv86[6];
  real_T c20_yb_y[6];
  real_T c20_uc_b;
  int32_T c20_i527;
  real_T c20_ac_y[6];
  int32_T c20_i528;
  real_T c20_mc_a[36];
  int32_T c20_i529;
  real_T c20_vc_b[6];
  int32_T c20_i530;
  real_T c20_nc_a[36];
  int32_T c20_i531;
  real_T c20_wc_b[6];
  int32_T c20_i532;
  real_T c20_dv87[6];
  real_T c20_bc_y[6];
  int32_T c20_i533;
  real_T c20_cc_y[6];
  real_T c20_oc_a[36];
  int32_T c20_i534;
  real_T c20_xc_b[6];
  int32_T c20_i535;
  real_T c20_pc_a[36];
  int32_T c20_i536;
  real_T c20_yc_b[6];
  int32_T c20_i537;
  real_T c20_dv88[6];
  real_T c20_dc_y[6];
  int32_T c20_i538;
  int32_T c20_i539;
  real_T c20_qc_a[16];
  int32_T c20_i540;
  real_T c20_dv89[6];
  real_T c20_ad_b[16];
  int32_T c20_i541;
  real_T c20_dd_A[16];
  int32_T c20_i542;
  real_T c20_dd_B[16];
  int32_T c20_i543;
  int32_T c20_i544;
  real_T c20_ed_A[16];
  int32_T c20_i545;
  real_T c20_ed_B[16];
  int32_T c20_i546;
  real_T c20_fd_A[16];
  int32_T c20_i547;
  real_T c20_fd_B[16];
  int32_T c20_i548;
  int32_T c20_i549;
  int32_T c20_i550;
  int32_T c20_i551;
  int32_T c20_i552;
  int32_T c20_i553;
  real_T c20_b_g56[16];
  int32_T c20_i554;
  real_T c20_dv90[16];
  real_T c20_dv91[16];
  int32_T c20_i555;
  real_T c20_dv92[16];
  real_T c20_dv93[36];
  int32_T c20_i556;
  int32_T c20_i557;
  real_T c20_rc_a[36];
  int32_T c20_i558;
  real_T c20_bd_b[6];
  int32_T c20_i559;
  real_T c20_sc_a[36];
  int32_T c20_i560;
  real_T c20_cd_b[6];
  int32_T c20_i561;
  real_T c20_dv94[6];
  real_T c20_ec_y[6];
  real_T c20_dd_b;
  int32_T c20_i562;
  real_T c20_fc_y[6];
  int32_T c20_i563;
  real_T c20_ed_b;
  int32_T c20_i564;
  real_T c20_gc_y[6];
  int32_T c20_i565;
  real_T c20_tc_a[36];
  int32_T c20_i566;
  real_T c20_fd_b[6];
  int32_T c20_i567;
  real_T c20_uc_a[36];
  int32_T c20_i568;
  real_T c20_gd_b[6];
  int32_T c20_i569;
  real_T c20_dv95[6];
  real_T c20_hc_y[6];
  real_T c20_hd_b;
  int32_T c20_i570;
  real_T c20_ic_y[6];
  int32_T c20_i571;
  real_T c20_vc_a[36];
  int32_T c20_i572;
  real_T c20_id_b[6];
  int32_T c20_i573;
  real_T c20_wc_a[36];
  int32_T c20_i574;
  real_T c20_jd_b[6];
  int32_T c20_i575;
  real_T c20_dv96[6];
  real_T c20_jc_y[6];
  int32_T c20_i576;
  real_T c20_kc_y[6];
  real_T c20_xc_a[36];
  int32_T c20_i577;
  real_T c20_kd_b[6];
  int32_T c20_i578;
  real_T c20_yc_a[36];
  int32_T c20_i579;
  real_T c20_ld_b[6];
  int32_T c20_i580;
  real_T c20_dv97[6];
  real_T c20_lc_y[6];
  int32_T c20_i581;
  int32_T c20_i582;
  int32_T c20_i583;
  int32_T c20_i584;
  real_T c20_b_g67_0[16];
  int32_T c20_i585;
  real_T c20_dv98[16];
  real_T c20_dv99[16];
  int32_T c20_i586;
  real_T c20_dv100[16];
  real_T c20_dv101[36];
  int32_T c20_i587;
  int32_T c20_i588;
  int32_T c20_i589;
  int32_T c20_i590;
  int32_T c20_i591;
  real_T c20_ad_a[36];
  int32_T c20_i592;
  real_T c20_md_b[6];
  int32_T c20_i593;
  real_T c20_bd_a[36];
  int32_T c20_i594;
  real_T c20_nd_b[6];
  int32_T c20_i595;
  real_T c20_dv102[6];
  real_T c20_mc_y[6];
  int32_T c20_i596;
  real_T c20_cd_a[36];
  int32_T c20_i597;
  real_T c20_od_b[6];
  int32_T c20_i598;
  real_T c20_dd_a[36];
  int32_T c20_i599;
  real_T c20_pd_b[6];
  int32_T c20_i600;
  real_T c20_dv103[6];
  real_T c20_nc_y[6];
  int32_T c20_i601;
  real_T c20_b_V6[6];
  real_T c20_dv104[36];
  int32_T c20_i602;
  int32_T c20_i603;
  int32_T c20_i604;
  int32_T c20_i605;
  real_T c20_ed_a[36];
  int32_T c20_i606;
  real_T c20_qd_b[36];
  int32_T c20_i607;
  real_T c20_gd_A[36];
  int32_T c20_i608;
  real_T c20_gd_B[36];
  int32_T c20_i609;
  real_T c20_hd_A[36];
  int32_T c20_i610;
  real_T c20_hd_B[36];
  int32_T c20_i611;
  real_T c20_id_A[36];
  int32_T c20_i612;
  real_T c20_id_B[36];
  int32_T c20_i613;
  real_T c20_dv105[36];
  real_T c20_oc_y[36];
  int32_T c20_i614;
  real_T c20_fd_a[36];
  int32_T c20_i615;
  real_T c20_rd_b[6];
  int32_T c20_i616;
  real_T c20_gd_a[36];
  int32_T c20_i617;
  real_T c20_sd_b[6];
  int32_T c20_i618;
  real_T c20_dv106[6];
  real_T c20_pc_y[6];
  int32_T c20_i619;
  int32_T c20_i620;
  real_T c20_td_b[6];
  int32_T c20_i621;
  real_T c20_qc_y[6];
  int32_T c20_i622;
  real_T c20_rc_y[6];
  int32_T c20_i623;
  real_T c20_sc_y[6];
  int32_T c20_i624;
  real_T c20_dv107[6];
  int32_T c20_i625;
  real_T c20_tc_y[6];
  real_T c20_uc_y;
  int32_T c20_i626;
  int32_T c20_i627;
  int32_T c20_i628;
  int32_T c20_i629;
  real_T c20_hd_a[36];
  int32_T c20_i630;
  real_T c20_ud_b[6];
  int32_T c20_i631;
  real_T c20_id_a[36];
  int32_T c20_i632;
  real_T c20_vd_b[6];
  int32_T c20_i633;
  real_T c20_dv108[6];
  real_T c20_vc_y[6];
  int32_T c20_i634;
  real_T c20_jd_a[36];
  int32_T c20_i635;
  real_T c20_wd_b[6];
  int32_T c20_i636;
  real_T c20_kd_a[36];
  int32_T c20_i637;
  real_T c20_xd_b[6];
  int32_T c20_i638;
  real_T c20_dv109[6];
  real_T c20_wc_y[6];
  int32_T c20_i639;
  real_T c20_b_V5[6];
  real_T c20_dv110[36];
  int32_T c20_i640;
  int32_T c20_i641;
  int32_T c20_i642;
  int32_T c20_i643;
  real_T c20_ld_a[36];
  int32_T c20_i644;
  real_T c20_yd_b[36];
  int32_T c20_i645;
  real_T c20_jd_A[36];
  int32_T c20_i646;
  real_T c20_jd_B[36];
  int32_T c20_i647;
  real_T c20_kd_A[36];
  int32_T c20_i648;
  real_T c20_kd_B[36];
  int32_T c20_i649;
  real_T c20_ld_A[36];
  int32_T c20_i650;
  real_T c20_ld_B[36];
  int32_T c20_i651;
  real_T c20_dv111[36];
  real_T c20_xc_y[36];
  int32_T c20_i652;
  real_T c20_md_a[36];
  int32_T c20_i653;
  real_T c20_ae_b[6];
  int32_T c20_i654;
  real_T c20_nd_a[36];
  int32_T c20_i655;
  real_T c20_be_b[6];
  int32_T c20_i656;
  real_T c20_dv112[6];
  real_T c20_yc_y[6];
  int32_T c20_i657;
  int32_T c20_i658;
  real_T c20_ce_b[6];
  int32_T c20_i659;
  real_T c20_ad_y[6];
  int32_T c20_i660;
  real_T c20_bd_y[6];
  int32_T c20_i661;
  real_T c20_cd_y[6];
  int32_T c20_i662;
  real_T c20_dv113[6];
  int32_T c20_i663;
  real_T c20_dd_y[6];
  real_T c20_ed_y;
  int32_T c20_i664;
  int32_T c20_i665;
  int32_T c20_i666;
  int32_T c20_i667;
  real_T c20_od_a[36];
  int32_T c20_i668;
  real_T c20_de_b[6];
  int32_T c20_i669;
  real_T c20_pd_a[36];
  int32_T c20_i670;
  real_T c20_ee_b[6];
  int32_T c20_i671;
  real_T c20_dv114[6];
  real_T c20_fd_y[6];
  int32_T c20_i672;
  real_T c20_qd_a[36];
  int32_T c20_i673;
  real_T c20_fe_b[6];
  int32_T c20_i674;
  real_T c20_rd_a[36];
  int32_T c20_i675;
  real_T c20_ge_b[6];
  int32_T c20_i676;
  real_T c20_dv115[6];
  real_T c20_gd_y[6];
  int32_T c20_i677;
  real_T c20_b_V4[6];
  real_T c20_dv116[36];
  int32_T c20_i678;
  int32_T c20_i679;
  int32_T c20_i680;
  int32_T c20_i681;
  real_T c20_sd_a[36];
  int32_T c20_i682;
  real_T c20_he_b[36];
  int32_T c20_i683;
  real_T c20_md_A[36];
  int32_T c20_i684;
  real_T c20_md_B[36];
  int32_T c20_i685;
  real_T c20_nd_A[36];
  int32_T c20_i686;
  real_T c20_nd_B[36];
  int32_T c20_i687;
  real_T c20_od_A[36];
  int32_T c20_i688;
  real_T c20_od_B[36];
  int32_T c20_i689;
  real_T c20_dv117[36];
  real_T c20_hd_y[36];
  int32_T c20_i690;
  real_T c20_td_a[36];
  int32_T c20_i691;
  real_T c20_ie_b[6];
  int32_T c20_i692;
  real_T c20_ud_a[36];
  int32_T c20_i693;
  real_T c20_je_b[6];
  int32_T c20_i694;
  real_T c20_dv118[6];
  real_T c20_id_y[6];
  int32_T c20_i695;
  int32_T c20_i696;
  real_T c20_ke_b[6];
  int32_T c20_i697;
  real_T c20_jd_y[6];
  int32_T c20_i698;
  real_T c20_kd_y[6];
  int32_T c20_i699;
  real_T c20_ld_y[6];
  int32_T c20_i700;
  real_T c20_dv119[6];
  int32_T c20_i701;
  real_T c20_md_y[6];
  real_T c20_nd_y;
  int32_T c20_i702;
  int32_T c20_i703;
  int32_T c20_i704;
  int32_T c20_i705;
  real_T c20_vd_a[36];
  int32_T c20_i706;
  real_T c20_le_b[6];
  int32_T c20_i707;
  real_T c20_wd_a[36];
  int32_T c20_i708;
  real_T c20_me_b[6];
  int32_T c20_i709;
  real_T c20_dv120[6];
  real_T c20_od_y[6];
  int32_T c20_i710;
  real_T c20_xd_a[36];
  int32_T c20_i711;
  real_T c20_ne_b[6];
  int32_T c20_i712;
  real_T c20_yd_a[36];
  int32_T c20_i713;
  real_T c20_oe_b[6];
  int32_T c20_i714;
  real_T c20_dv121[6];
  real_T c20_pd_y[6];
  int32_T c20_i715;
  real_T c20_b_V3[6];
  real_T c20_dv122[36];
  int32_T c20_i716;
  int32_T c20_i717;
  int32_T c20_i718;
  int32_T c20_i719;
  real_T c20_ae_a[36];
  int32_T c20_i720;
  real_T c20_pe_b[36];
  int32_T c20_i721;
  real_T c20_pd_A[36];
  int32_T c20_i722;
  real_T c20_pd_B[36];
  int32_T c20_i723;
  real_T c20_qd_A[36];
  int32_T c20_i724;
  real_T c20_qd_B[36];
  int32_T c20_i725;
  real_T c20_rd_A[36];
  int32_T c20_i726;
  real_T c20_rd_B[36];
  int32_T c20_i727;
  real_T c20_dv123[36];
  real_T c20_qd_y[36];
  int32_T c20_i728;
  real_T c20_be_a[36];
  int32_T c20_i729;
  real_T c20_qe_b[6];
  int32_T c20_i730;
  real_T c20_ce_a[36];
  int32_T c20_i731;
  real_T c20_re_b[6];
  int32_T c20_i732;
  real_T c20_dv124[6];
  real_T c20_rd_y[6];
  int32_T c20_i733;
  int32_T c20_i734;
  real_T c20_se_b[6];
  int32_T c20_i735;
  real_T c20_sd_y[6];
  int32_T c20_i736;
  real_T c20_td_y[6];
  int32_T c20_i737;
  real_T c20_ud_y[6];
  int32_T c20_i738;
  real_T c20_dv125[6];
  int32_T c20_i739;
  real_T c20_vd_y[6];
  real_T c20_wd_y;
  int32_T c20_i740;
  int32_T c20_i741;
  int32_T c20_i742;
  int32_T c20_i743;
  real_T c20_de_a[36];
  int32_T c20_i744;
  real_T c20_te_b[6];
  int32_T c20_i745;
  real_T c20_ee_a[36];
  int32_T c20_i746;
  real_T c20_ue_b[6];
  int32_T c20_i747;
  real_T c20_dv126[6];
  real_T c20_xd_y[6];
  int32_T c20_i748;
  real_T c20_fe_a[36];
  int32_T c20_i749;
  real_T c20_ve_b[6];
  int32_T c20_i750;
  real_T c20_ge_a[36];
  int32_T c20_i751;
  real_T c20_we_b[6];
  int32_T c20_i752;
  real_T c20_dv127[6];
  real_T c20_yd_y[6];
  int32_T c20_i753;
  real_T c20_b_V2[6];
  real_T c20_dv128[36];
  int32_T c20_i754;
  int32_T c20_i755;
  int32_T c20_i756;
  int32_T c20_i757;
  real_T c20_he_a[36];
  int32_T c20_i758;
  real_T c20_xe_b[36];
  int32_T c20_i759;
  real_T c20_sd_A[36];
  int32_T c20_i760;
  real_T c20_sd_B[36];
  int32_T c20_i761;
  real_T c20_td_A[36];
  int32_T c20_i762;
  real_T c20_td_B[36];
  int32_T c20_i763;
  real_T c20_ud_A[36];
  int32_T c20_i764;
  real_T c20_ud_B[36];
  int32_T c20_i765;
  real_T c20_dv129[36];
  real_T c20_ae_y[36];
  int32_T c20_i766;
  real_T c20_ie_a[36];
  int32_T c20_i767;
  real_T c20_ye_b[6];
  int32_T c20_i768;
  real_T c20_je_a[36];
  int32_T c20_i769;
  real_T c20_af_b[6];
  int32_T c20_i770;
  real_T c20_dv130[6];
  real_T c20_be_y[6];
  int32_T c20_i771;
  int32_T c20_i772;
  real_T c20_bf_b[6];
  int32_T c20_i773;
  real_T c20_ce_y[6];
  int32_T c20_i774;
  real_T c20_de_y[6];
  int32_T c20_i775;
  real_T c20_ee_y[6];
  int32_T c20_i776;
  real_T c20_dv131[6];
  int32_T c20_i777;
  real_T c20_fe_y[6];
  real_T c20_ge_y;
  int32_T c20_i778;
  int32_T c20_i779;
  int32_T c20_i780;
  int32_T c20_i781;
  real_T c20_ke_a[36];
  int32_T c20_i782;
  real_T c20_cf_b[6];
  int32_T c20_i783;
  real_T c20_le_a[36];
  int32_T c20_i784;
  real_T c20_df_b[6];
  int32_T c20_i785;
  real_T c20_dv132[6];
  real_T c20_he_y[6];
  int32_T c20_i786;
  real_T c20_me_a[36];
  int32_T c20_i787;
  real_T c20_ef_b[6];
  int32_T c20_i788;
  real_T c20_ne_a[36];
  int32_T c20_i789;
  real_T c20_ff_b[6];
  int32_T c20_i790;
  real_T c20_dv133[6];
  real_T c20_ie_y[6];
  int32_T c20_i791;
  real_T c20_b_V1[6];
  real_T c20_dv134[36];
  int32_T c20_i792;
  int32_T c20_i793;
  int32_T c20_i794;
  int32_T c20_i795;
  real_T c20_oe_a[36];
  int32_T c20_i796;
  real_T c20_gf_b[36];
  int32_T c20_i797;
  real_T c20_vd_A[36];
  int32_T c20_i798;
  real_T c20_vd_B[36];
  int32_T c20_i799;
  real_T c20_wd_A[36];
  int32_T c20_i800;
  real_T c20_wd_B[36];
  int32_T c20_i801;
  real_T c20_xd_A[36];
  int32_T c20_i802;
  real_T c20_xd_B[36];
  int32_T c20_i803;
  real_T c20_dv135[36];
  real_T c20_je_y[36];
  int32_T c20_i804;
  real_T c20_pe_a[36];
  int32_T c20_i805;
  real_T c20_hf_b[6];
  int32_T c20_i806;
  real_T c20_qe_a[36];
  int32_T c20_i807;
  real_T c20_if_b[6];
  int32_T c20_i808;
  real_T c20_dv136[6];
  real_T c20_ke_y[6];
  int32_T c20_i809;
  int32_T c20_i810;
  real_T c20_jf_b[6];
  int32_T c20_i811;
  real_T c20_le_y[6];
  int32_T c20_i812;
  real_T c20_me_y[6];
  int32_T c20_i813;
  real_T c20_ne_y[6];
  int32_T c20_i814;
  real_T c20_dv137[6];
  int32_T c20_i815;
  real_T c20_oe_y[6];
  real_T c20_pe_y;
  int32_T c20_i816;
  sf_debug_symbol_scope_push_eml(0U, 68U, 68U, c20_sv0, c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c20_w_o, c20_f_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c20_w_z, c20_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_kxi1, c20_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_kxi2, c20_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c20_kxi3, c20_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c20_kxi4, c20_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c20_kxi5, c20_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c20_kxi6, c20_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c20_ez, c20_f_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c20_ex, c20_f_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c20_eo, c20_f_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c20_g01_0, c20_g_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(c20_g12_0, c20_g_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(c20_g23_0, c20_g_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(c20_g34_0, c20_g_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(c20_g45_0, c20_g_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(c20_g56_0, c20_g_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(c20_g67_0, c20_g_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(c20_M1, c20_h_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(c20_M2, c20_h_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(c20_M3, c20_h_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(c20_M4, c20_h_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(c20_M5, c20_h_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(c20_M6, c20_h_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(c20_V0, c20_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(c20_dV0, c20_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(c20_g01, c20_g_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(c20_Adinvg01, c20_h_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(c20_V1, c20_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(c20_dV1, c20_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(c20_g12, c20_g_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(c20_Adinvg12, c20_h_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(c20_V2, c20_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(c20_dV2, c20_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(c20_g23, c20_g_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(c20_Adinvg23, c20_h_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(c20_V3, c20_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(c20_dV3, c20_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(c20_g34, c20_g_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(c20_Adinvg34, c20_h_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(c20_V4, c20_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(c20_dV4, c20_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(c20_g45, c20_g_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(c20_Adinvg45, c20_h_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(c20_V5, c20_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(c20_dV5, c20_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(c20_g56, c20_g_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(c20_Adinvg56, c20_h_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(c20_V6, c20_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(c20_dV6, c20_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(c20_Tau, c20_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(c20_F7, c20_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(c20_Adinvg67, c20_h_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(c20_F6, c20_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(c20_F5, c20_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(c20_F4, c20_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(c20_F3, c20_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(c20_F2, c20_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(c20_F1, c20_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(c20_DH, c20_c_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(c20_Param, c20_b_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(c20_Ft, c20_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(c20_Pos, c20_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c20_Vel, c20_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(c20_Acc, c20_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(c20_Torque, c20_sf_marshall, 67U);
  CV_SCRIPT_FCN(0, 0);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /* @Copyright(c),Googol Shenzhen Tech. Ltd */
  /* @File Name: DynEulerCal_Min.m */
  /* @Author: Dai Dan */
  /* @Version: 1.0 */
  /* @Date: 14/5/2014 */
  /*  */
  /* @Function: DynEulerCal_Min */
  /* @Description: Implementing Newton-Euler Recursion Algorithm(Parameters Type) to get computed torque */
  /* Instead of accurate Ma,Cen,Ie, it only need equivalent dynmaic parameters set which may obtained from */
  /* standard identification process.  */
  /* @Input: */
  /* DH: DH parameters */
  /* Param: [m1 mr1 mr2 mr3 Ixx1 Iyy1 Izz1 Ixy1 Ixz1 Iyz1....] */
  /* Ft: generalized force exerted on endeffetor  */
  /* Pos: joint angle */
  /* Vel: joint velocity */
  /* Acc: joint acceleration */
  /* @Output: */
  /* Tau: Torque */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  %% Calculate kxi in corresponding joint frame, different from in base frame */
  _SFD_SCRIPT_CALL(0, 25);
  for (c20_i34 = 0; c20_i34 < 3; c20_i34 = c20_i34 + 1) {
    c20_w_o[c20_i34] = 0.0;
  }

  _SFD_SCRIPT_CALL(0, 26);
  for (c20_i35 = 0; c20_i35 < 3; c20_i35 = c20_i35 + 1) {
    c20_w_z[c20_i35] = c20_dv5[c20_i35];
  }

  _SFD_SCRIPT_CALL(0, 28);
  for (c20_i36 = 0; c20_i36 < 6; c20_i36 = c20_i36 + 1) {
    c20_kxi1[c20_i36] = c20_dv6[c20_i36];
  }

  _SFD_SCRIPT_CALL(0, 29);
  for (c20_i37 = 0; c20_i37 < 6; c20_i37 = c20_i37 + 1) {
    c20_kxi2[c20_i37] = c20_dv6[c20_i37];
  }

  _SFD_SCRIPT_CALL(0, 30);
  for (c20_i38 = 0; c20_i38 < 6; c20_i38 = c20_i38 + 1) {
    c20_kxi3[c20_i38] = c20_dv6[c20_i38];
  }

  _SFD_SCRIPT_CALL(0, 31);
  for (c20_i39 = 0; c20_i39 < 6; c20_i39 = c20_i39 + 1) {
    c20_kxi4[c20_i39] = c20_dv6[c20_i39];
  }

  _SFD_SCRIPT_CALL(0, 32);
  for (c20_i40 = 0; c20_i40 < 6; c20_i40 = c20_i40 + 1) {
    c20_kxi5[c20_i40] = c20_dv6[c20_i40];
  }

  _SFD_SCRIPT_CALL(0, 33);
  for (c20_i41 = 0; c20_i41 < 6; c20_i41 = c20_i41 + 1) {
    c20_kxi6[c20_i41] = c20_dv6[c20_i41];
  }

  /*  %% Calculate initial configuration matrix g_{i-1,i} */
  /*  0: means base frame; */
  /*  1,2,3,4,5,6: means i-th joint frame, Ci */
  /*  7: means endeffector frame */
  /*  DH=[266     300     0       0       1016     0      174; */
  /*      0       0       -pi/2   0       pi      pi       0; */
  /*      0       150     870     170     0       0        0; */
  /*      0       -pi/2   0       -pi/2   -pi/2    -pi/2   0;]; */
  _SFD_SCRIPT_CALL(0, 44);
  for (c20_i42 = 0; c20_i42 < 3; c20_i42 = c20_i42 + 1) {
    c20_ez[c20_i42] = c20_dv5[c20_i42];
  }

  _SFD_SCRIPT_CALL(0, 45);
  for (c20_i43 = 0; c20_i43 < 3; c20_i43 = c20_i43 + 1) {
    c20_ex[c20_i43] = c20_dv7[c20_i43];
  }

  _SFD_SCRIPT_CALL(0, 46);
  for (c20_i44 = 0; c20_i44 < 3; c20_i44 = c20_i44 + 1) {
    c20_eo[c20_i44] = 0.0;
  }

  _SFD_SCRIPT_CALL(0, 48);
  for (c20_i45 = 0; c20_i45 < 6; c20_i45 = c20_i45 + 1) {
    c20_dv9[c20_i45] = c20_dv8[c20_i45];
  }

  c20_expWre(chartInstance, c20_dv9, c20_DH[1], c20_a);
  for (c20_i46 = 0; c20_i46 < 6; c20_i46 = c20_i46 + 1) {
    c20_dv11[c20_i46] = c20_dv10[c20_i46];
  }

  c20_expWre(chartInstance, c20_dv11, c20_DH[0], c20_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i47 = 0; c20_i47 < 16; c20_i47 = c20_i47 + 1) {
    c20_A[c20_i47] = c20_a[c20_i47];
  }

  for (c20_i48 = 0; c20_i48 < 16; c20_i48 = c20_i48 + 1) {
    c20_B[c20_i48] = c20_b[c20_i48];
  }

  for (c20_i49 = 0; c20_i49 < 16; c20_i49 = c20_i49 + 1) {
    c20_b_A[c20_i49] = c20_A[c20_i49];
  }

  for (c20_i50 = 0; c20_i50 < 16; c20_i50 = c20_i50 + 1) {
    c20_b_B[c20_i50] = c20_B[c20_i50];
  }

  for (c20_i51 = 0; c20_i51 < 16; c20_i51 = c20_i51 + 1) {
    c20_c_A[c20_i51] = c20_b_A[c20_i51];
  }

  for (c20_i52 = 0; c20_i52 < 16; c20_i52 = c20_i52 + 1) {
    c20_c_B[c20_i52] = c20_b_B[c20_i52];
  }

  for (c20_i53 = 0; c20_i53 < 4; c20_i53 = c20_i53 + 1) {
    c20_i54 = 0;
    for (c20_i55 = 0; c20_i55 < 4; c20_i55 = c20_i55 + 1) {
      c20_y[c20_i54 + c20_i53] = 0.0;
      c20_i56 = 0;
      for (c20_i57 = 0; c20_i57 < 4; c20_i57 = c20_i57 + 1) {
        c20_y[c20_i54 + c20_i53] = c20_y[c20_i54 + c20_i53] + c20_c_A[c20_i56 +
          c20_i53] * c20_c_B[c20_i57 + c20_i54];
        c20_i56 = c20_i56 + 4;
      }

      c20_i54 = c20_i54 + 4;
    }
  }

  for (c20_i58 = 0; c20_i58 < 16; c20_i58 = c20_i58 + 1) {
    c20_b_a[c20_i58] = c20_y[c20_i58];
  }

  for (c20_i59 = 0; c20_i59 < 6; c20_i59 = c20_i59 + 1) {
    c20_dv13[c20_i59] = c20_dv12[c20_i59];
  }

  c20_expWre(chartInstance, c20_dv13, c20_DH[3], c20_b_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i60 = 0; c20_i60 < 16; c20_i60 = c20_i60 + 1) {
    c20_d_A[c20_i60] = c20_b_a[c20_i60];
  }

  for (c20_i61 = 0; c20_i61 < 16; c20_i61 = c20_i61 + 1) {
    c20_d_B[c20_i61] = c20_b_b[c20_i61];
  }

  for (c20_i62 = 0; c20_i62 < 16; c20_i62 = c20_i62 + 1) {
    c20_e_A[c20_i62] = c20_d_A[c20_i62];
  }

  for (c20_i63 = 0; c20_i63 < 16; c20_i63 = c20_i63 + 1) {
    c20_e_B[c20_i63] = c20_d_B[c20_i63];
  }

  for (c20_i64 = 0; c20_i64 < 16; c20_i64 = c20_i64 + 1) {
    c20_f_A[c20_i64] = c20_e_A[c20_i64];
  }

  for (c20_i65 = 0; c20_i65 < 16; c20_i65 = c20_i65 + 1) {
    c20_f_B[c20_i65] = c20_e_B[c20_i65];
  }

  for (c20_i66 = 0; c20_i66 < 4; c20_i66 = c20_i66 + 1) {
    c20_i67 = 0;
    for (c20_i68 = 0; c20_i68 < 4; c20_i68 = c20_i68 + 1) {
      c20_b_y[c20_i67 + c20_i66] = 0.0;
      c20_i69 = 0;
      for (c20_i70 = 0; c20_i70 < 4; c20_i70 = c20_i70 + 1) {
        c20_b_y[c20_i67 + c20_i66] = c20_b_y[c20_i67 + c20_i66] +
          c20_f_A[c20_i69 + c20_i66] * c20_f_B[c20_i70 + c20_i67];
        c20_i69 = c20_i69 + 4;
      }

      c20_i67 = c20_i67 + 4;
    }
  }

  for (c20_i71 = 0; c20_i71 < 16; c20_i71 = c20_i71 + 1) {
    c20_c_a[c20_i71] = c20_b_y[c20_i71];
  }

  for (c20_i72 = 0; c20_i72 < 6; c20_i72 = c20_i72 + 1) {
    c20_dv14[c20_i72] = c20_dv6[c20_i72];
  }

  c20_expWre(chartInstance, c20_dv14, c20_DH[2], c20_c_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i73 = 0; c20_i73 < 16; c20_i73 = c20_i73 + 1) {
    c20_g_A[c20_i73] = c20_c_a[c20_i73];
  }

  for (c20_i74 = 0; c20_i74 < 16; c20_i74 = c20_i74 + 1) {
    c20_g_B[c20_i74] = c20_c_b[c20_i74];
  }

  for (c20_i75 = 0; c20_i75 < 16; c20_i75 = c20_i75 + 1) {
    c20_g01_0[c20_i75] = 0.0;
  }

  for (c20_i76 = 0; c20_i76 < 16; c20_i76 = c20_i76 + 1) {
    c20_h_A[c20_i76] = c20_g_A[c20_i76];
  }

  for (c20_i77 = 0; c20_i77 < 16; c20_i77 = c20_i77 + 1) {
    c20_h_B[c20_i77] = c20_g_B[c20_i77];
  }

  for (c20_i78 = 0; c20_i78 < 16; c20_i78 = c20_i78 + 1) {
    c20_i_A[c20_i78] = c20_h_A[c20_i78];
  }

  for (c20_i79 = 0; c20_i79 < 16; c20_i79 = c20_i79 + 1) {
    c20_i_B[c20_i79] = c20_h_B[c20_i79];
  }

  for (c20_i80 = 0; c20_i80 < 4; c20_i80 = c20_i80 + 1) {
    c20_i81 = 0;
    for (c20_i82 = 0; c20_i82 < 4; c20_i82 = c20_i82 + 1) {
      c20_g01_0[c20_i81 + c20_i80] = 0.0;
      c20_i83 = 0;
      for (c20_i84 = 0; c20_i84 < 4; c20_i84 = c20_i84 + 1) {
        c20_g01_0[c20_i81 + c20_i80] = c20_g01_0[c20_i81 + c20_i80] +
          c20_i_A[c20_i83 + c20_i80] * c20_i_B[c20_i84 + c20_i81];
        c20_i83 = c20_i83 + 4;
      }

      c20_i81 = c20_i81 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 49);
  for (c20_i85 = 0; c20_i85 < 6; c20_i85 = c20_i85 + 1) {
    c20_dv15[c20_i85] = c20_dv8[c20_i85];
  }

  c20_expWre(chartInstance, c20_dv15, c20_DH[5], c20_d_a);
  for (c20_i86 = 0; c20_i86 < 6; c20_i86 = c20_i86 + 1) {
    c20_dv16[c20_i86] = c20_dv10[c20_i86];
  }

  c20_expWre(chartInstance, c20_dv16, c20_DH[4], c20_d_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i87 = 0; c20_i87 < 16; c20_i87 = c20_i87 + 1) {
    c20_j_A[c20_i87] = c20_d_a[c20_i87];
  }

  for (c20_i88 = 0; c20_i88 < 16; c20_i88 = c20_i88 + 1) {
    c20_j_B[c20_i88] = c20_d_b[c20_i88];
  }

  for (c20_i89 = 0; c20_i89 < 16; c20_i89 = c20_i89 + 1) {
    c20_k_A[c20_i89] = c20_j_A[c20_i89];
  }

  for (c20_i90 = 0; c20_i90 < 16; c20_i90 = c20_i90 + 1) {
    c20_k_B[c20_i90] = c20_j_B[c20_i90];
  }

  for (c20_i91 = 0; c20_i91 < 16; c20_i91 = c20_i91 + 1) {
    c20_l_A[c20_i91] = c20_k_A[c20_i91];
  }

  for (c20_i92 = 0; c20_i92 < 16; c20_i92 = c20_i92 + 1) {
    c20_l_B[c20_i92] = c20_k_B[c20_i92];
  }

  for (c20_i93 = 0; c20_i93 < 4; c20_i93 = c20_i93 + 1) {
    c20_i94 = 0;
    for (c20_i95 = 0; c20_i95 < 4; c20_i95 = c20_i95 + 1) {
      c20_c_y[c20_i94 + c20_i93] = 0.0;
      c20_i96 = 0;
      for (c20_i97 = 0; c20_i97 < 4; c20_i97 = c20_i97 + 1) {
        c20_c_y[c20_i94 + c20_i93] = c20_c_y[c20_i94 + c20_i93] +
          c20_l_A[c20_i96 + c20_i93] * c20_l_B[c20_i97 + c20_i94];
        c20_i96 = c20_i96 + 4;
      }

      c20_i94 = c20_i94 + 4;
    }
  }

  for (c20_i98 = 0; c20_i98 < 16; c20_i98 = c20_i98 + 1) {
    c20_e_a[c20_i98] = c20_c_y[c20_i98];
  }

  for (c20_i99 = 0; c20_i99 < 6; c20_i99 = c20_i99 + 1) {
    c20_dv17[c20_i99] = c20_dv12[c20_i99];
  }

  c20_expWre(chartInstance, c20_dv17, c20_DH[7], c20_e_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i100 = 0; c20_i100 < 16; c20_i100 = c20_i100 + 1) {
    c20_m_A[c20_i100] = c20_e_a[c20_i100];
  }

  for (c20_i101 = 0; c20_i101 < 16; c20_i101 = c20_i101 + 1) {
    c20_m_B[c20_i101] = c20_e_b[c20_i101];
  }

  for (c20_i102 = 0; c20_i102 < 16; c20_i102 = c20_i102 + 1) {
    c20_n_A[c20_i102] = c20_m_A[c20_i102];
  }

  for (c20_i103 = 0; c20_i103 < 16; c20_i103 = c20_i103 + 1) {
    c20_n_B[c20_i103] = c20_m_B[c20_i103];
  }

  for (c20_i104 = 0; c20_i104 < 16; c20_i104 = c20_i104 + 1) {
    c20_o_A[c20_i104] = c20_n_A[c20_i104];
  }

  for (c20_i105 = 0; c20_i105 < 16; c20_i105 = c20_i105 + 1) {
    c20_o_B[c20_i105] = c20_n_B[c20_i105];
  }

  for (c20_i106 = 0; c20_i106 < 4; c20_i106 = c20_i106 + 1) {
    c20_i107 = 0;
    for (c20_i108 = 0; c20_i108 < 4; c20_i108 = c20_i108 + 1) {
      c20_d_y[c20_i107 + c20_i106] = 0.0;
      c20_i109 = 0;
      for (c20_i110 = 0; c20_i110 < 4; c20_i110 = c20_i110 + 1) {
        c20_d_y[c20_i107 + c20_i106] = c20_d_y[c20_i107 + c20_i106] +
          c20_o_A[c20_i109 + c20_i106] * c20_o_B[c20_i110 + c20_i107];
        c20_i109 = c20_i109 + 4;
      }

      c20_i107 = c20_i107 + 4;
    }
  }

  for (c20_i111 = 0; c20_i111 < 16; c20_i111 = c20_i111 + 1) {
    c20_f_a[c20_i111] = c20_d_y[c20_i111];
  }

  for (c20_i112 = 0; c20_i112 < 6; c20_i112 = c20_i112 + 1) {
    c20_dv18[c20_i112] = c20_dv6[c20_i112];
  }

  c20_expWre(chartInstance, c20_dv18, c20_DH[6], c20_f_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i113 = 0; c20_i113 < 16; c20_i113 = c20_i113 + 1) {
    c20_p_A[c20_i113] = c20_f_a[c20_i113];
  }

  for (c20_i114 = 0; c20_i114 < 16; c20_i114 = c20_i114 + 1) {
    c20_p_B[c20_i114] = c20_f_b[c20_i114];
  }

  for (c20_i115 = 0; c20_i115 < 16; c20_i115 = c20_i115 + 1) {
    c20_g12_0[c20_i115] = 0.0;
  }

  for (c20_i116 = 0; c20_i116 < 16; c20_i116 = c20_i116 + 1) {
    c20_q_A[c20_i116] = c20_p_A[c20_i116];
  }

  for (c20_i117 = 0; c20_i117 < 16; c20_i117 = c20_i117 + 1) {
    c20_q_B[c20_i117] = c20_p_B[c20_i117];
  }

  for (c20_i118 = 0; c20_i118 < 16; c20_i118 = c20_i118 + 1) {
    c20_r_A[c20_i118] = c20_q_A[c20_i118];
  }

  for (c20_i119 = 0; c20_i119 < 16; c20_i119 = c20_i119 + 1) {
    c20_r_B[c20_i119] = c20_q_B[c20_i119];
  }

  for (c20_i120 = 0; c20_i120 < 4; c20_i120 = c20_i120 + 1) {
    c20_i121 = 0;
    for (c20_i122 = 0; c20_i122 < 4; c20_i122 = c20_i122 + 1) {
      c20_g12_0[c20_i121 + c20_i120] = 0.0;
      c20_i123 = 0;
      for (c20_i124 = 0; c20_i124 < 4; c20_i124 = c20_i124 + 1) {
        c20_g12_0[c20_i121 + c20_i120] = c20_g12_0[c20_i121 + c20_i120] +
          c20_r_A[c20_i123 + c20_i120] * c20_r_B[c20_i124 + c20_i121];
        c20_i123 = c20_i123 + 4;
      }

      c20_i121 = c20_i121 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 50);
  for (c20_i125 = 0; c20_i125 < 6; c20_i125 = c20_i125 + 1) {
    c20_dv19[c20_i125] = c20_dv8[c20_i125];
  }

  c20_expWre(chartInstance, c20_dv19, c20_DH[9], c20_g_a);
  for (c20_i126 = 0; c20_i126 < 6; c20_i126 = c20_i126 + 1) {
    c20_dv20[c20_i126] = c20_dv10[c20_i126];
  }

  c20_expWre(chartInstance, c20_dv20, c20_DH[8], c20_g_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i127 = 0; c20_i127 < 16; c20_i127 = c20_i127 + 1) {
    c20_s_A[c20_i127] = c20_g_a[c20_i127];
  }

  for (c20_i128 = 0; c20_i128 < 16; c20_i128 = c20_i128 + 1) {
    c20_s_B[c20_i128] = c20_g_b[c20_i128];
  }

  for (c20_i129 = 0; c20_i129 < 16; c20_i129 = c20_i129 + 1) {
    c20_t_A[c20_i129] = c20_s_A[c20_i129];
  }

  for (c20_i130 = 0; c20_i130 < 16; c20_i130 = c20_i130 + 1) {
    c20_t_B[c20_i130] = c20_s_B[c20_i130];
  }

  for (c20_i131 = 0; c20_i131 < 16; c20_i131 = c20_i131 + 1) {
    c20_u_A[c20_i131] = c20_t_A[c20_i131];
  }

  for (c20_i132 = 0; c20_i132 < 16; c20_i132 = c20_i132 + 1) {
    c20_u_B[c20_i132] = c20_t_B[c20_i132];
  }

  for (c20_i133 = 0; c20_i133 < 4; c20_i133 = c20_i133 + 1) {
    c20_i134 = 0;
    for (c20_i135 = 0; c20_i135 < 4; c20_i135 = c20_i135 + 1) {
      c20_e_y[c20_i134 + c20_i133] = 0.0;
      c20_i136 = 0;
      for (c20_i137 = 0; c20_i137 < 4; c20_i137 = c20_i137 + 1) {
        c20_e_y[c20_i134 + c20_i133] = c20_e_y[c20_i134 + c20_i133] +
          c20_u_A[c20_i136 + c20_i133] * c20_u_B[c20_i137 + c20_i134];
        c20_i136 = c20_i136 + 4;
      }

      c20_i134 = c20_i134 + 4;
    }
  }

  for (c20_i138 = 0; c20_i138 < 16; c20_i138 = c20_i138 + 1) {
    c20_h_a[c20_i138] = c20_e_y[c20_i138];
  }

  for (c20_i139 = 0; c20_i139 < 6; c20_i139 = c20_i139 + 1) {
    c20_dv21[c20_i139] = c20_dv12[c20_i139];
  }

  c20_expWre(chartInstance, c20_dv21, c20_DH[11], c20_h_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i140 = 0; c20_i140 < 16; c20_i140 = c20_i140 + 1) {
    c20_v_A[c20_i140] = c20_h_a[c20_i140];
  }

  for (c20_i141 = 0; c20_i141 < 16; c20_i141 = c20_i141 + 1) {
    c20_v_B[c20_i141] = c20_h_b[c20_i141];
  }

  for (c20_i142 = 0; c20_i142 < 16; c20_i142 = c20_i142 + 1) {
    c20_w_A[c20_i142] = c20_v_A[c20_i142];
  }

  for (c20_i143 = 0; c20_i143 < 16; c20_i143 = c20_i143 + 1) {
    c20_w_B[c20_i143] = c20_v_B[c20_i143];
  }

  for (c20_i144 = 0; c20_i144 < 16; c20_i144 = c20_i144 + 1) {
    c20_x_A[c20_i144] = c20_w_A[c20_i144];
  }

  for (c20_i145 = 0; c20_i145 < 16; c20_i145 = c20_i145 + 1) {
    c20_x_B[c20_i145] = c20_w_B[c20_i145];
  }

  for (c20_i146 = 0; c20_i146 < 4; c20_i146 = c20_i146 + 1) {
    c20_i147 = 0;
    for (c20_i148 = 0; c20_i148 < 4; c20_i148 = c20_i148 + 1) {
      c20_f_y[c20_i147 + c20_i146] = 0.0;
      c20_i149 = 0;
      for (c20_i150 = 0; c20_i150 < 4; c20_i150 = c20_i150 + 1) {
        c20_f_y[c20_i147 + c20_i146] = c20_f_y[c20_i147 + c20_i146] +
          c20_x_A[c20_i149 + c20_i146] * c20_x_B[c20_i150 + c20_i147];
        c20_i149 = c20_i149 + 4;
      }

      c20_i147 = c20_i147 + 4;
    }
  }

  for (c20_i151 = 0; c20_i151 < 16; c20_i151 = c20_i151 + 1) {
    c20_i_a[c20_i151] = c20_f_y[c20_i151];
  }

  for (c20_i152 = 0; c20_i152 < 6; c20_i152 = c20_i152 + 1) {
    c20_dv22[c20_i152] = c20_dv6[c20_i152];
  }

  c20_expWre(chartInstance, c20_dv22, c20_DH[10], c20_i_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i153 = 0; c20_i153 < 16; c20_i153 = c20_i153 + 1) {
    c20_y_A[c20_i153] = c20_i_a[c20_i153];
  }

  for (c20_i154 = 0; c20_i154 < 16; c20_i154 = c20_i154 + 1) {
    c20_y_B[c20_i154] = c20_i_b[c20_i154];
  }

  for (c20_i155 = 0; c20_i155 < 16; c20_i155 = c20_i155 + 1) {
    c20_g23_0[c20_i155] = 0.0;
  }

  for (c20_i156 = 0; c20_i156 < 16; c20_i156 = c20_i156 + 1) {
    c20_ab_A[c20_i156] = c20_y_A[c20_i156];
  }

  for (c20_i157 = 0; c20_i157 < 16; c20_i157 = c20_i157 + 1) {
    c20_ab_B[c20_i157] = c20_y_B[c20_i157];
  }

  for (c20_i158 = 0; c20_i158 < 16; c20_i158 = c20_i158 + 1) {
    c20_bb_A[c20_i158] = c20_ab_A[c20_i158];
  }

  for (c20_i159 = 0; c20_i159 < 16; c20_i159 = c20_i159 + 1) {
    c20_bb_B[c20_i159] = c20_ab_B[c20_i159];
  }

  for (c20_i160 = 0; c20_i160 < 4; c20_i160 = c20_i160 + 1) {
    c20_i161 = 0;
    for (c20_i162 = 0; c20_i162 < 4; c20_i162 = c20_i162 + 1) {
      c20_g23_0[c20_i161 + c20_i160] = 0.0;
      c20_i163 = 0;
      for (c20_i164 = 0; c20_i164 < 4; c20_i164 = c20_i164 + 1) {
        c20_g23_0[c20_i161 + c20_i160] = c20_g23_0[c20_i161 + c20_i160] +
          c20_bb_A[c20_i163 + c20_i160] * c20_bb_B[c20_i164 + c20_i161];
        c20_i163 = c20_i163 + 4;
      }

      c20_i161 = c20_i161 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 51);
  for (c20_i165 = 0; c20_i165 < 6; c20_i165 = c20_i165 + 1) {
    c20_dv23[c20_i165] = c20_dv8[c20_i165];
  }

  c20_expWre(chartInstance, c20_dv23, c20_DH[13], c20_j_a);
  for (c20_i166 = 0; c20_i166 < 6; c20_i166 = c20_i166 + 1) {
    c20_dv24[c20_i166] = c20_dv10[c20_i166];
  }

  c20_expWre(chartInstance, c20_dv24, c20_DH[12], c20_j_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i167 = 0; c20_i167 < 16; c20_i167 = c20_i167 + 1) {
    c20_cb_A[c20_i167] = c20_j_a[c20_i167];
  }

  for (c20_i168 = 0; c20_i168 < 16; c20_i168 = c20_i168 + 1) {
    c20_cb_B[c20_i168] = c20_j_b[c20_i168];
  }

  for (c20_i169 = 0; c20_i169 < 16; c20_i169 = c20_i169 + 1) {
    c20_db_A[c20_i169] = c20_cb_A[c20_i169];
  }

  for (c20_i170 = 0; c20_i170 < 16; c20_i170 = c20_i170 + 1) {
    c20_db_B[c20_i170] = c20_cb_B[c20_i170];
  }

  for (c20_i171 = 0; c20_i171 < 16; c20_i171 = c20_i171 + 1) {
    c20_eb_A[c20_i171] = c20_db_A[c20_i171];
  }

  for (c20_i172 = 0; c20_i172 < 16; c20_i172 = c20_i172 + 1) {
    c20_eb_B[c20_i172] = c20_db_B[c20_i172];
  }

  for (c20_i173 = 0; c20_i173 < 4; c20_i173 = c20_i173 + 1) {
    c20_i174 = 0;
    for (c20_i175 = 0; c20_i175 < 4; c20_i175 = c20_i175 + 1) {
      c20_g_y[c20_i174 + c20_i173] = 0.0;
      c20_i176 = 0;
      for (c20_i177 = 0; c20_i177 < 4; c20_i177 = c20_i177 + 1) {
        c20_g_y[c20_i174 + c20_i173] = c20_g_y[c20_i174 + c20_i173] +
          c20_eb_A[c20_i176 + c20_i173] * c20_eb_B[c20_i177 + c20_i174];
        c20_i176 = c20_i176 + 4;
      }

      c20_i174 = c20_i174 + 4;
    }
  }

  for (c20_i178 = 0; c20_i178 < 16; c20_i178 = c20_i178 + 1) {
    c20_k_a[c20_i178] = c20_g_y[c20_i178];
  }

  for (c20_i179 = 0; c20_i179 < 6; c20_i179 = c20_i179 + 1) {
    c20_dv25[c20_i179] = c20_dv12[c20_i179];
  }

  c20_expWre(chartInstance, c20_dv25, c20_DH[15], c20_k_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i180 = 0; c20_i180 < 16; c20_i180 = c20_i180 + 1) {
    c20_fb_A[c20_i180] = c20_k_a[c20_i180];
  }

  for (c20_i181 = 0; c20_i181 < 16; c20_i181 = c20_i181 + 1) {
    c20_fb_B[c20_i181] = c20_k_b[c20_i181];
  }

  for (c20_i182 = 0; c20_i182 < 16; c20_i182 = c20_i182 + 1) {
    c20_gb_A[c20_i182] = c20_fb_A[c20_i182];
  }

  for (c20_i183 = 0; c20_i183 < 16; c20_i183 = c20_i183 + 1) {
    c20_gb_B[c20_i183] = c20_fb_B[c20_i183];
  }

  for (c20_i184 = 0; c20_i184 < 16; c20_i184 = c20_i184 + 1) {
    c20_hb_A[c20_i184] = c20_gb_A[c20_i184];
  }

  for (c20_i185 = 0; c20_i185 < 16; c20_i185 = c20_i185 + 1) {
    c20_hb_B[c20_i185] = c20_gb_B[c20_i185];
  }

  for (c20_i186 = 0; c20_i186 < 4; c20_i186 = c20_i186 + 1) {
    c20_i187 = 0;
    for (c20_i188 = 0; c20_i188 < 4; c20_i188 = c20_i188 + 1) {
      c20_h_y[c20_i187 + c20_i186] = 0.0;
      c20_i189 = 0;
      for (c20_i190 = 0; c20_i190 < 4; c20_i190 = c20_i190 + 1) {
        c20_h_y[c20_i187 + c20_i186] = c20_h_y[c20_i187 + c20_i186] +
          c20_hb_A[c20_i189 + c20_i186] * c20_hb_B[c20_i190 + c20_i187];
        c20_i189 = c20_i189 + 4;
      }

      c20_i187 = c20_i187 + 4;
    }
  }

  for (c20_i191 = 0; c20_i191 < 16; c20_i191 = c20_i191 + 1) {
    c20_l_a[c20_i191] = c20_h_y[c20_i191];
  }

  for (c20_i192 = 0; c20_i192 < 6; c20_i192 = c20_i192 + 1) {
    c20_dv26[c20_i192] = c20_dv6[c20_i192];
  }

  c20_expWre(chartInstance, c20_dv26, c20_DH[14], c20_l_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i193 = 0; c20_i193 < 16; c20_i193 = c20_i193 + 1) {
    c20_ib_A[c20_i193] = c20_l_a[c20_i193];
  }

  for (c20_i194 = 0; c20_i194 < 16; c20_i194 = c20_i194 + 1) {
    c20_ib_B[c20_i194] = c20_l_b[c20_i194];
  }

  for (c20_i195 = 0; c20_i195 < 16; c20_i195 = c20_i195 + 1) {
    c20_g34_0[c20_i195] = 0.0;
  }

  for (c20_i196 = 0; c20_i196 < 16; c20_i196 = c20_i196 + 1) {
    c20_jb_A[c20_i196] = c20_ib_A[c20_i196];
  }

  for (c20_i197 = 0; c20_i197 < 16; c20_i197 = c20_i197 + 1) {
    c20_jb_B[c20_i197] = c20_ib_B[c20_i197];
  }

  for (c20_i198 = 0; c20_i198 < 16; c20_i198 = c20_i198 + 1) {
    c20_kb_A[c20_i198] = c20_jb_A[c20_i198];
  }

  for (c20_i199 = 0; c20_i199 < 16; c20_i199 = c20_i199 + 1) {
    c20_kb_B[c20_i199] = c20_jb_B[c20_i199];
  }

  for (c20_i200 = 0; c20_i200 < 4; c20_i200 = c20_i200 + 1) {
    c20_i201 = 0;
    for (c20_i202 = 0; c20_i202 < 4; c20_i202 = c20_i202 + 1) {
      c20_g34_0[c20_i201 + c20_i200] = 0.0;
      c20_i203 = 0;
      for (c20_i204 = 0; c20_i204 < 4; c20_i204 = c20_i204 + 1) {
        c20_g34_0[c20_i201 + c20_i200] = c20_g34_0[c20_i201 + c20_i200] +
          c20_kb_A[c20_i203 + c20_i200] * c20_kb_B[c20_i204 + c20_i201];
        c20_i203 = c20_i203 + 4;
      }

      c20_i201 = c20_i201 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 52);
  for (c20_i205 = 0; c20_i205 < 6; c20_i205 = c20_i205 + 1) {
    c20_dv27[c20_i205] = c20_dv8[c20_i205];
  }

  c20_expWre(chartInstance, c20_dv27, c20_DH[17], c20_m_a);
  for (c20_i206 = 0; c20_i206 < 6; c20_i206 = c20_i206 + 1) {
    c20_dv28[c20_i206] = c20_dv10[c20_i206];
  }

  c20_expWre(chartInstance, c20_dv28, c20_DH[16], c20_m_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i207 = 0; c20_i207 < 16; c20_i207 = c20_i207 + 1) {
    c20_lb_A[c20_i207] = c20_m_a[c20_i207];
  }

  for (c20_i208 = 0; c20_i208 < 16; c20_i208 = c20_i208 + 1) {
    c20_lb_B[c20_i208] = c20_m_b[c20_i208];
  }

  for (c20_i209 = 0; c20_i209 < 16; c20_i209 = c20_i209 + 1) {
    c20_mb_A[c20_i209] = c20_lb_A[c20_i209];
  }

  for (c20_i210 = 0; c20_i210 < 16; c20_i210 = c20_i210 + 1) {
    c20_mb_B[c20_i210] = c20_lb_B[c20_i210];
  }

  for (c20_i211 = 0; c20_i211 < 16; c20_i211 = c20_i211 + 1) {
    c20_nb_A[c20_i211] = c20_mb_A[c20_i211];
  }

  for (c20_i212 = 0; c20_i212 < 16; c20_i212 = c20_i212 + 1) {
    c20_nb_B[c20_i212] = c20_mb_B[c20_i212];
  }

  for (c20_i213 = 0; c20_i213 < 4; c20_i213 = c20_i213 + 1) {
    c20_i214 = 0;
    for (c20_i215 = 0; c20_i215 < 4; c20_i215 = c20_i215 + 1) {
      c20_i_y[c20_i214 + c20_i213] = 0.0;
      c20_i216 = 0;
      for (c20_i217 = 0; c20_i217 < 4; c20_i217 = c20_i217 + 1) {
        c20_i_y[c20_i214 + c20_i213] = c20_i_y[c20_i214 + c20_i213] +
          c20_nb_A[c20_i216 + c20_i213] * c20_nb_B[c20_i217 + c20_i214];
        c20_i216 = c20_i216 + 4;
      }

      c20_i214 = c20_i214 + 4;
    }
  }

  for (c20_i218 = 0; c20_i218 < 16; c20_i218 = c20_i218 + 1) {
    c20_n_a[c20_i218] = c20_i_y[c20_i218];
  }

  for (c20_i219 = 0; c20_i219 < 6; c20_i219 = c20_i219 + 1) {
    c20_dv29[c20_i219] = c20_dv12[c20_i219];
  }

  c20_expWre(chartInstance, c20_dv29, c20_DH[19], c20_n_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i220 = 0; c20_i220 < 16; c20_i220 = c20_i220 + 1) {
    c20_ob_A[c20_i220] = c20_n_a[c20_i220];
  }

  for (c20_i221 = 0; c20_i221 < 16; c20_i221 = c20_i221 + 1) {
    c20_ob_B[c20_i221] = c20_n_b[c20_i221];
  }

  for (c20_i222 = 0; c20_i222 < 16; c20_i222 = c20_i222 + 1) {
    c20_pb_A[c20_i222] = c20_ob_A[c20_i222];
  }

  for (c20_i223 = 0; c20_i223 < 16; c20_i223 = c20_i223 + 1) {
    c20_pb_B[c20_i223] = c20_ob_B[c20_i223];
  }

  for (c20_i224 = 0; c20_i224 < 16; c20_i224 = c20_i224 + 1) {
    c20_qb_A[c20_i224] = c20_pb_A[c20_i224];
  }

  for (c20_i225 = 0; c20_i225 < 16; c20_i225 = c20_i225 + 1) {
    c20_qb_B[c20_i225] = c20_pb_B[c20_i225];
  }

  for (c20_i226 = 0; c20_i226 < 4; c20_i226 = c20_i226 + 1) {
    c20_i227 = 0;
    for (c20_i228 = 0; c20_i228 < 4; c20_i228 = c20_i228 + 1) {
      c20_j_y[c20_i227 + c20_i226] = 0.0;
      c20_i229 = 0;
      for (c20_i230 = 0; c20_i230 < 4; c20_i230 = c20_i230 + 1) {
        c20_j_y[c20_i227 + c20_i226] = c20_j_y[c20_i227 + c20_i226] +
          c20_qb_A[c20_i229 + c20_i226] * c20_qb_B[c20_i230 + c20_i227];
        c20_i229 = c20_i229 + 4;
      }

      c20_i227 = c20_i227 + 4;
    }
  }

  for (c20_i231 = 0; c20_i231 < 16; c20_i231 = c20_i231 + 1) {
    c20_o_a[c20_i231] = c20_j_y[c20_i231];
  }

  for (c20_i232 = 0; c20_i232 < 6; c20_i232 = c20_i232 + 1) {
    c20_dv30[c20_i232] = c20_dv6[c20_i232];
  }

  c20_expWre(chartInstance, c20_dv30, c20_DH[18], c20_o_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i233 = 0; c20_i233 < 16; c20_i233 = c20_i233 + 1) {
    c20_rb_A[c20_i233] = c20_o_a[c20_i233];
  }

  for (c20_i234 = 0; c20_i234 < 16; c20_i234 = c20_i234 + 1) {
    c20_rb_B[c20_i234] = c20_o_b[c20_i234];
  }

  for (c20_i235 = 0; c20_i235 < 16; c20_i235 = c20_i235 + 1) {
    c20_g45_0[c20_i235] = 0.0;
  }

  for (c20_i236 = 0; c20_i236 < 16; c20_i236 = c20_i236 + 1) {
    c20_sb_A[c20_i236] = c20_rb_A[c20_i236];
  }

  for (c20_i237 = 0; c20_i237 < 16; c20_i237 = c20_i237 + 1) {
    c20_sb_B[c20_i237] = c20_rb_B[c20_i237];
  }

  for (c20_i238 = 0; c20_i238 < 16; c20_i238 = c20_i238 + 1) {
    c20_tb_A[c20_i238] = c20_sb_A[c20_i238];
  }

  for (c20_i239 = 0; c20_i239 < 16; c20_i239 = c20_i239 + 1) {
    c20_tb_B[c20_i239] = c20_sb_B[c20_i239];
  }

  for (c20_i240 = 0; c20_i240 < 4; c20_i240 = c20_i240 + 1) {
    c20_i241 = 0;
    for (c20_i242 = 0; c20_i242 < 4; c20_i242 = c20_i242 + 1) {
      c20_g45_0[c20_i241 + c20_i240] = 0.0;
      c20_i243 = 0;
      for (c20_i244 = 0; c20_i244 < 4; c20_i244 = c20_i244 + 1) {
        c20_g45_0[c20_i241 + c20_i240] = c20_g45_0[c20_i241 + c20_i240] +
          c20_tb_A[c20_i243 + c20_i240] * c20_tb_B[c20_i244 + c20_i241];
        c20_i243 = c20_i243 + 4;
      }

      c20_i241 = c20_i241 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 53);
  for (c20_i245 = 0; c20_i245 < 6; c20_i245 = c20_i245 + 1) {
    c20_dv31[c20_i245] = c20_dv8[c20_i245];
  }

  c20_expWre(chartInstance, c20_dv31, c20_DH[21], c20_p_a);
  for (c20_i246 = 0; c20_i246 < 6; c20_i246 = c20_i246 + 1) {
    c20_dv32[c20_i246] = c20_dv10[c20_i246];
  }

  c20_expWre(chartInstance, c20_dv32, c20_DH[20], c20_p_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i247 = 0; c20_i247 < 16; c20_i247 = c20_i247 + 1) {
    c20_ub_A[c20_i247] = c20_p_a[c20_i247];
  }

  for (c20_i248 = 0; c20_i248 < 16; c20_i248 = c20_i248 + 1) {
    c20_ub_B[c20_i248] = c20_p_b[c20_i248];
  }

  for (c20_i249 = 0; c20_i249 < 16; c20_i249 = c20_i249 + 1) {
    c20_vb_A[c20_i249] = c20_ub_A[c20_i249];
  }

  for (c20_i250 = 0; c20_i250 < 16; c20_i250 = c20_i250 + 1) {
    c20_vb_B[c20_i250] = c20_ub_B[c20_i250];
  }

  for (c20_i251 = 0; c20_i251 < 16; c20_i251 = c20_i251 + 1) {
    c20_wb_A[c20_i251] = c20_vb_A[c20_i251];
  }

  for (c20_i252 = 0; c20_i252 < 16; c20_i252 = c20_i252 + 1) {
    c20_wb_B[c20_i252] = c20_vb_B[c20_i252];
  }

  for (c20_i253 = 0; c20_i253 < 4; c20_i253 = c20_i253 + 1) {
    c20_i254 = 0;
    for (c20_i255 = 0; c20_i255 < 4; c20_i255 = c20_i255 + 1) {
      c20_k_y[c20_i254 + c20_i253] = 0.0;
      c20_i256 = 0;
      for (c20_i257 = 0; c20_i257 < 4; c20_i257 = c20_i257 + 1) {
        c20_k_y[c20_i254 + c20_i253] = c20_k_y[c20_i254 + c20_i253] +
          c20_wb_A[c20_i256 + c20_i253] * c20_wb_B[c20_i257 + c20_i254];
        c20_i256 = c20_i256 + 4;
      }

      c20_i254 = c20_i254 + 4;
    }
  }

  for (c20_i258 = 0; c20_i258 < 16; c20_i258 = c20_i258 + 1) {
    c20_q_a[c20_i258] = c20_k_y[c20_i258];
  }

  for (c20_i259 = 0; c20_i259 < 6; c20_i259 = c20_i259 + 1) {
    c20_dv33[c20_i259] = c20_dv12[c20_i259];
  }

  c20_expWre(chartInstance, c20_dv33, c20_DH[23], c20_q_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i260 = 0; c20_i260 < 16; c20_i260 = c20_i260 + 1) {
    c20_xb_A[c20_i260] = c20_q_a[c20_i260];
  }

  for (c20_i261 = 0; c20_i261 < 16; c20_i261 = c20_i261 + 1) {
    c20_xb_B[c20_i261] = c20_q_b[c20_i261];
  }

  for (c20_i262 = 0; c20_i262 < 16; c20_i262 = c20_i262 + 1) {
    c20_yb_A[c20_i262] = c20_xb_A[c20_i262];
  }

  for (c20_i263 = 0; c20_i263 < 16; c20_i263 = c20_i263 + 1) {
    c20_yb_B[c20_i263] = c20_xb_B[c20_i263];
  }

  for (c20_i264 = 0; c20_i264 < 16; c20_i264 = c20_i264 + 1) {
    c20_ac_A[c20_i264] = c20_yb_A[c20_i264];
  }

  for (c20_i265 = 0; c20_i265 < 16; c20_i265 = c20_i265 + 1) {
    c20_ac_B[c20_i265] = c20_yb_B[c20_i265];
  }

  for (c20_i266 = 0; c20_i266 < 4; c20_i266 = c20_i266 + 1) {
    c20_i267 = 0;
    for (c20_i268 = 0; c20_i268 < 4; c20_i268 = c20_i268 + 1) {
      c20_l_y[c20_i267 + c20_i266] = 0.0;
      c20_i269 = 0;
      for (c20_i270 = 0; c20_i270 < 4; c20_i270 = c20_i270 + 1) {
        c20_l_y[c20_i267 + c20_i266] = c20_l_y[c20_i267 + c20_i266] +
          c20_ac_A[c20_i269 + c20_i266] * c20_ac_B[c20_i270 + c20_i267];
        c20_i269 = c20_i269 + 4;
      }

      c20_i267 = c20_i267 + 4;
    }
  }

  for (c20_i271 = 0; c20_i271 < 16; c20_i271 = c20_i271 + 1) {
    c20_r_a[c20_i271] = c20_l_y[c20_i271];
  }

  for (c20_i272 = 0; c20_i272 < 6; c20_i272 = c20_i272 + 1) {
    c20_dv34[c20_i272] = c20_dv6[c20_i272];
  }

  c20_expWre(chartInstance, c20_dv34, c20_DH[22], c20_r_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i273 = 0; c20_i273 < 16; c20_i273 = c20_i273 + 1) {
    c20_bc_A[c20_i273] = c20_r_a[c20_i273];
  }

  for (c20_i274 = 0; c20_i274 < 16; c20_i274 = c20_i274 + 1) {
    c20_bc_B[c20_i274] = c20_r_b[c20_i274];
  }

  for (c20_i275 = 0; c20_i275 < 16; c20_i275 = c20_i275 + 1) {
    c20_g56_0[c20_i275] = 0.0;
  }

  for (c20_i276 = 0; c20_i276 < 16; c20_i276 = c20_i276 + 1) {
    c20_cc_A[c20_i276] = c20_bc_A[c20_i276];
  }

  for (c20_i277 = 0; c20_i277 < 16; c20_i277 = c20_i277 + 1) {
    c20_cc_B[c20_i277] = c20_bc_B[c20_i277];
  }

  for (c20_i278 = 0; c20_i278 < 16; c20_i278 = c20_i278 + 1) {
    c20_dc_A[c20_i278] = c20_cc_A[c20_i278];
  }

  for (c20_i279 = 0; c20_i279 < 16; c20_i279 = c20_i279 + 1) {
    c20_dc_B[c20_i279] = c20_cc_B[c20_i279];
  }

  for (c20_i280 = 0; c20_i280 < 4; c20_i280 = c20_i280 + 1) {
    c20_i281 = 0;
    for (c20_i282 = 0; c20_i282 < 4; c20_i282 = c20_i282 + 1) {
      c20_g56_0[c20_i281 + c20_i280] = 0.0;
      c20_i283 = 0;
      for (c20_i284 = 0; c20_i284 < 4; c20_i284 = c20_i284 + 1) {
        c20_g56_0[c20_i281 + c20_i280] = c20_g56_0[c20_i281 + c20_i280] +
          c20_dc_A[c20_i283 + c20_i280] * c20_dc_B[c20_i284 + c20_i281];
        c20_i283 = c20_i283 + 4;
      }

      c20_i281 = c20_i281 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 54);
  for (c20_i285 = 0; c20_i285 < 6; c20_i285 = c20_i285 + 1) {
    c20_dv35[c20_i285] = c20_dv8[c20_i285];
  }

  c20_expWre(chartInstance, c20_dv35, c20_DH[25], c20_s_a);
  for (c20_i286 = 0; c20_i286 < 6; c20_i286 = c20_i286 + 1) {
    c20_dv36[c20_i286] = c20_dv10[c20_i286];
  }

  c20_expWre(chartInstance, c20_dv36, c20_DH[24], c20_s_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i287 = 0; c20_i287 < 16; c20_i287 = c20_i287 + 1) {
    c20_ec_A[c20_i287] = c20_s_a[c20_i287];
  }

  for (c20_i288 = 0; c20_i288 < 16; c20_i288 = c20_i288 + 1) {
    c20_ec_B[c20_i288] = c20_s_b[c20_i288];
  }

  for (c20_i289 = 0; c20_i289 < 16; c20_i289 = c20_i289 + 1) {
    c20_fc_A[c20_i289] = c20_ec_A[c20_i289];
  }

  for (c20_i290 = 0; c20_i290 < 16; c20_i290 = c20_i290 + 1) {
    c20_fc_B[c20_i290] = c20_ec_B[c20_i290];
  }

  for (c20_i291 = 0; c20_i291 < 16; c20_i291 = c20_i291 + 1) {
    c20_gc_A[c20_i291] = c20_fc_A[c20_i291];
  }

  for (c20_i292 = 0; c20_i292 < 16; c20_i292 = c20_i292 + 1) {
    c20_gc_B[c20_i292] = c20_fc_B[c20_i292];
  }

  for (c20_i293 = 0; c20_i293 < 4; c20_i293 = c20_i293 + 1) {
    c20_i294 = 0;
    for (c20_i295 = 0; c20_i295 < 4; c20_i295 = c20_i295 + 1) {
      c20_m_y[c20_i294 + c20_i293] = 0.0;
      c20_i296 = 0;
      for (c20_i297 = 0; c20_i297 < 4; c20_i297 = c20_i297 + 1) {
        c20_m_y[c20_i294 + c20_i293] = c20_m_y[c20_i294 + c20_i293] +
          c20_gc_A[c20_i296 + c20_i293] * c20_gc_B[c20_i297 + c20_i294];
        c20_i296 = c20_i296 + 4;
      }

      c20_i294 = c20_i294 + 4;
    }
  }

  for (c20_i298 = 0; c20_i298 < 16; c20_i298 = c20_i298 + 1) {
    c20_t_a[c20_i298] = c20_m_y[c20_i298];
  }

  for (c20_i299 = 0; c20_i299 < 6; c20_i299 = c20_i299 + 1) {
    c20_dv37[c20_i299] = c20_dv12[c20_i299];
  }

  c20_expWre(chartInstance, c20_dv37, c20_DH[27], c20_t_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i300 = 0; c20_i300 < 16; c20_i300 = c20_i300 + 1) {
    c20_hc_A[c20_i300] = c20_t_a[c20_i300];
  }

  for (c20_i301 = 0; c20_i301 < 16; c20_i301 = c20_i301 + 1) {
    c20_hc_B[c20_i301] = c20_t_b[c20_i301];
  }

  for (c20_i302 = 0; c20_i302 < 16; c20_i302 = c20_i302 + 1) {
    c20_ic_A[c20_i302] = c20_hc_A[c20_i302];
  }

  for (c20_i303 = 0; c20_i303 < 16; c20_i303 = c20_i303 + 1) {
    c20_ic_B[c20_i303] = c20_hc_B[c20_i303];
  }

  for (c20_i304 = 0; c20_i304 < 16; c20_i304 = c20_i304 + 1) {
    c20_jc_A[c20_i304] = c20_ic_A[c20_i304];
  }

  for (c20_i305 = 0; c20_i305 < 16; c20_i305 = c20_i305 + 1) {
    c20_jc_B[c20_i305] = c20_ic_B[c20_i305];
  }

  for (c20_i306 = 0; c20_i306 < 4; c20_i306 = c20_i306 + 1) {
    c20_i307 = 0;
    for (c20_i308 = 0; c20_i308 < 4; c20_i308 = c20_i308 + 1) {
      c20_n_y[c20_i307 + c20_i306] = 0.0;
      c20_i309 = 0;
      for (c20_i310 = 0; c20_i310 < 4; c20_i310 = c20_i310 + 1) {
        c20_n_y[c20_i307 + c20_i306] = c20_n_y[c20_i307 + c20_i306] +
          c20_jc_A[c20_i309 + c20_i306] * c20_jc_B[c20_i310 + c20_i307];
        c20_i309 = c20_i309 + 4;
      }

      c20_i307 = c20_i307 + 4;
    }
  }

  for (c20_i311 = 0; c20_i311 < 16; c20_i311 = c20_i311 + 1) {
    c20_u_a[c20_i311] = c20_n_y[c20_i311];
  }

  for (c20_i312 = 0; c20_i312 < 6; c20_i312 = c20_i312 + 1) {
    c20_dv38[c20_i312] = c20_dv6[c20_i312];
  }

  c20_expWre(chartInstance, c20_dv38, c20_DH[26], c20_u_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i313 = 0; c20_i313 < 16; c20_i313 = c20_i313 + 1) {
    c20_kc_A[c20_i313] = c20_u_a[c20_i313];
  }

  for (c20_i314 = 0; c20_i314 < 16; c20_i314 = c20_i314 + 1) {
    c20_kc_B[c20_i314] = c20_u_b[c20_i314];
  }

  for (c20_i315 = 0; c20_i315 < 16; c20_i315 = c20_i315 + 1) {
    c20_g67_0[c20_i315] = 0.0;
  }

  for (c20_i316 = 0; c20_i316 < 16; c20_i316 = c20_i316 + 1) {
    c20_lc_A[c20_i316] = c20_kc_A[c20_i316];
  }

  for (c20_i317 = 0; c20_i317 < 16; c20_i317 = c20_i317 + 1) {
    c20_lc_B[c20_i317] = c20_kc_B[c20_i317];
  }

  for (c20_i318 = 0; c20_i318 < 16; c20_i318 = c20_i318 + 1) {
    c20_mc_A[c20_i318] = c20_lc_A[c20_i318];
  }

  for (c20_i319 = 0; c20_i319 < 16; c20_i319 = c20_i319 + 1) {
    c20_mc_B[c20_i319] = c20_lc_B[c20_i319];
  }

  for (c20_i320 = 0; c20_i320 < 4; c20_i320 = c20_i320 + 1) {
    c20_i321 = 0;
    for (c20_i322 = 0; c20_i322 < 4; c20_i322 = c20_i322 + 1) {
      c20_g67_0[c20_i321 + c20_i320] = 0.0;
      c20_i323 = 0;
      for (c20_i324 = 0; c20_i324 < 4; c20_i324 = c20_i324 + 1) {
        c20_g67_0[c20_i321 + c20_i320] = c20_g67_0[c20_i321 + c20_i320] +
          c20_mc_A[c20_i323 + c20_i320] * c20_mc_B[c20_i324 + c20_i321];
        c20_i323 = c20_i323 + 4;
      }

      c20_i321 = c20_i321 + 4;
    }
  }

  /*  %% Equivalent Dynamic Parameters %%%%%%%%% */
  _SFD_SCRIPT_CALL(0, 57);
  c20_M1[0] = c20_Param[0];
  c20_M1[6] = 0.0;
  c20_M1[12] = 0.0;
  c20_M1[18] = 0.0;
  c20_M1[24] = c20_Param[3];
  c20_M1[30] = -c20_Param[2];
  c20_M1[1] = 0.0;
  c20_M1[7] = c20_Param[0];
  c20_M1[13] = 0.0;
  c20_M1[19] = -c20_Param[3];
  c20_M1[25] = 0.0;
  c20_M1[31] = c20_Param[1];
  c20_M1[2] = 0.0;
  c20_M1[8] = 0.0;
  c20_M1[14] = c20_Param[0];
  c20_M1[20] = c20_Param[2];
  c20_M1[26] = -c20_Param[1];
  c20_M1[32] = 0.0;
  c20_M1[3] = 0.0;
  c20_M1[9] = -c20_Param[3];
  c20_M1[15] = c20_Param[2];
  c20_M1[21] = c20_Param[4];
  c20_M1[27] = c20_Param[7];
  c20_M1[33] = c20_Param[8];
  c20_M1[4] = c20_Param[3];
  c20_M1[10] = 0.0;
  c20_M1[16] = -c20_Param[1];
  c20_M1[22] = c20_Param[7];
  c20_M1[28] = c20_Param[5];
  c20_M1[34] = c20_Param[9];
  c20_M1[5] = -c20_Param[2];
  c20_M1[11] = c20_Param[1];
  c20_M1[17] = 0.0;
  c20_M1[23] = c20_Param[8];
  c20_M1[29] = c20_Param[9];
  c20_M1[35] = c20_Param[6];
  _SFD_SCRIPT_CALL(0, 64);
  c20_M2[0] = c20_Param[10];
  c20_M2[6] = 0.0;
  c20_M2[12] = 0.0;
  c20_M2[18] = 0.0;
  c20_M2[24] = c20_Param[13];
  c20_M2[30] = -c20_Param[12];
  c20_M2[1] = 0.0;
  c20_M2[7] = c20_Param[10];
  c20_M2[13] = 0.0;
  c20_M2[19] = -c20_Param[13];
  c20_M2[25] = 0.0;
  c20_M2[31] = c20_Param[11];
  c20_M2[2] = 0.0;
  c20_M2[8] = 0.0;
  c20_M2[14] = c20_Param[10];
  c20_M2[20] = c20_Param[12];
  c20_M2[26] = -c20_Param[11];
  c20_M2[32] = 0.0;
  c20_M2[3] = 0.0;
  c20_M2[9] = -c20_Param[13];
  c20_M2[15] = c20_Param[12];
  c20_M2[21] = c20_Param[14];
  c20_M2[27] = c20_Param[17];
  c20_M2[33] = c20_Param[18];
  c20_M2[4] = c20_Param[13];
  c20_M2[10] = 0.0;
  c20_M2[16] = -c20_Param[11];
  c20_M2[22] = c20_Param[17];
  c20_M2[28] = c20_Param[15];
  c20_M2[34] = c20_Param[19];
  c20_M2[5] = -c20_Param[12];
  c20_M2[11] = c20_Param[11];
  c20_M2[17] = 0.0;
  c20_M2[23] = c20_Param[18];
  c20_M2[29] = c20_Param[19];
  c20_M2[35] = c20_Param[16];
  _SFD_SCRIPT_CALL(0, 71);
  c20_M3[0] = c20_Param[20];
  c20_M3[6] = 0.0;
  c20_M3[12] = 0.0;
  c20_M3[18] = 0.0;
  c20_M3[24] = c20_Param[23];
  c20_M3[30] = -c20_Param[22];
  c20_M3[1] = 0.0;
  c20_M3[7] = c20_Param[20];
  c20_M3[13] = 0.0;
  c20_M3[19] = -c20_Param[23];
  c20_M3[25] = 0.0;
  c20_M3[31] = c20_Param[21];
  c20_M3[2] = 0.0;
  c20_M3[8] = 0.0;
  c20_M3[14] = c20_Param[20];
  c20_M3[20] = c20_Param[22];
  c20_M3[26] = -c20_Param[21];
  c20_M3[32] = 0.0;
  c20_M3[3] = 0.0;
  c20_M3[9] = -c20_Param[23];
  c20_M3[15] = c20_Param[22];
  c20_M3[21] = c20_Param[24];
  c20_M3[27] = c20_Param[27];
  c20_M3[33] = c20_Param[28];
  c20_M3[4] = c20_Param[23];
  c20_M3[10] = 0.0;
  c20_M3[16] = -c20_Param[21];
  c20_M3[22] = c20_Param[27];
  c20_M3[28] = c20_Param[25];
  c20_M3[34] = c20_Param[29];
  c20_M3[5] = -c20_Param[22];
  c20_M3[11] = c20_Param[21];
  c20_M3[17] = 0.0;
  c20_M3[23] = c20_Param[28];
  c20_M3[29] = c20_Param[29];
  c20_M3[35] = c20_Param[26];
  _SFD_SCRIPT_CALL(0, 78);
  c20_M4[0] = c20_Param[30];
  c20_M4[6] = 0.0;
  c20_M4[12] = 0.0;
  c20_M4[18] = 0.0;
  c20_M4[24] = c20_Param[33];
  c20_M4[30] = -c20_Param[32];
  c20_M4[1] = 0.0;
  c20_M4[7] = c20_Param[30];
  c20_M4[13] = 0.0;
  c20_M4[19] = -c20_Param[33];
  c20_M4[25] = 0.0;
  c20_M4[31] = c20_Param[31];
  c20_M4[2] = 0.0;
  c20_M4[8] = 0.0;
  c20_M4[14] = c20_Param[30];
  c20_M4[20] = c20_Param[32];
  c20_M4[26] = -c20_Param[31];
  c20_M4[32] = 0.0;
  c20_M4[3] = 0.0;
  c20_M4[9] = -c20_Param[33];
  c20_M4[15] = c20_Param[32];
  c20_M4[21] = c20_Param[34];
  c20_M4[27] = c20_Param[37];
  c20_M4[33] = c20_Param[38];
  c20_M4[4] = c20_Param[33];
  c20_M4[10] = 0.0;
  c20_M4[16] = -c20_Param[31];
  c20_M4[22] = c20_Param[37];
  c20_M4[28] = c20_Param[35];
  c20_M4[34] = c20_Param[39];
  c20_M4[5] = -c20_Param[32];
  c20_M4[11] = c20_Param[31];
  c20_M4[17] = 0.0;
  c20_M4[23] = c20_Param[38];
  c20_M4[29] = c20_Param[39];
  c20_M4[35] = c20_Param[36];
  _SFD_SCRIPT_CALL(0, 85);
  c20_M5[0] = c20_Param[40];
  c20_M5[6] = 0.0;
  c20_M5[12] = 0.0;
  c20_M5[18] = 0.0;
  c20_M5[24] = c20_Param[43];
  c20_M5[30] = -c20_Param[42];
  c20_M5[1] = 0.0;
  c20_M5[7] = c20_Param[40];
  c20_M5[13] = 0.0;
  c20_M5[19] = -c20_Param[43];
  c20_M5[25] = 0.0;
  c20_M5[31] = c20_Param[41];
  c20_M5[2] = 0.0;
  c20_M5[8] = 0.0;
  c20_M5[14] = c20_Param[40];
  c20_M5[20] = c20_Param[42];
  c20_M5[26] = -c20_Param[41];
  c20_M5[32] = 0.0;
  c20_M5[3] = 0.0;
  c20_M5[9] = -c20_Param[43];
  c20_M5[15] = c20_Param[42];
  c20_M5[21] = c20_Param[44];
  c20_M5[27] = c20_Param[47];
  c20_M5[33] = c20_Param[48];
  c20_M5[4] = c20_Param[43];
  c20_M5[10] = 0.0;
  c20_M5[16] = -c20_Param[41];
  c20_M5[22] = c20_Param[47];
  c20_M5[28] = c20_Param[45];
  c20_M5[34] = c20_Param[49];
  c20_M5[5] = -c20_Param[42];
  c20_M5[11] = c20_Param[41];
  c20_M5[17] = 0.0;
  c20_M5[23] = c20_Param[48];
  c20_M5[29] = c20_Param[49];
  c20_M5[35] = c20_Param[46];
  _SFD_SCRIPT_CALL(0, 92);
  c20_M6[0] = c20_Param[50];
  c20_M6[6] = 0.0;
  c20_M6[12] = 0.0;
  c20_M6[18] = 0.0;
  c20_M6[24] = c20_Param[53];
  c20_M6[30] = -c20_Param[52];
  c20_M6[1] = 0.0;
  c20_M6[7] = c20_Param[50];
  c20_M6[13] = 0.0;
  c20_M6[19] = -c20_Param[53];
  c20_M6[25] = 0.0;
  c20_M6[31] = c20_Param[51];
  c20_M6[2] = 0.0;
  c20_M6[8] = 0.0;
  c20_M6[14] = c20_Param[50];
  c20_M6[20] = c20_Param[52];
  c20_M6[26] = -c20_Param[51];
  c20_M6[32] = 0.0;
  c20_M6[3] = 0.0;
  c20_M6[9] = -c20_Param[53];
  c20_M6[15] = c20_Param[52];
  c20_M6[21] = c20_Param[54];
  c20_M6[27] = c20_Param[57];
  c20_M6[33] = c20_Param[58];
  c20_M6[4] = c20_Param[53];
  c20_M6[10] = 0.0;
  c20_M6[16] = -c20_Param[51];
  c20_M6[22] = c20_Param[57];
  c20_M6[28] = c20_Param[55];
  c20_M6[34] = c20_Param[59];
  c20_M6[5] = -c20_Param[52];
  c20_M6[11] = c20_Param[51];
  c20_M6[17] = 0.0;
  c20_M6[23] = c20_Param[58];
  c20_M6[29] = c20_Param[59];
  c20_M6[35] = c20_Param[56];

  /*  %% Forward Recursion (kinematic) */
  /*  Initial State */
  _SFD_SCRIPT_CALL(0, 101);
  for (c20_i325 = 0; c20_i325 < 6; c20_i325 = c20_i325 + 1) {
    c20_V0[c20_i325] = 0.0;
  }

  _SFD_SCRIPT_CALL(0, 102);
  for (c20_i326 = 0; c20_i326 < 6; c20_i326 = c20_i326 + 1) {
    c20_dV0[c20_i326] = c20_dv39[c20_i326];
  }

  /*  Joint 1: */
  _SFD_SCRIPT_CALL(0, 105);
  for (c20_i327 = 0; c20_i327 < 16; c20_i327 = c20_i327 + 1) {
    c20_v_a[c20_i327] = c20_g01_0[c20_i327];
  }

  for (c20_i328 = 0; c20_i328 < 6; c20_i328 = c20_i328 + 1) {
    c20_dv40[c20_i328] = c20_dv6[c20_i328];
  }

  c20_expg(chartInstance, c20_dv40, c20_Pos[0], c20_v_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i329 = 0; c20_i329 < 16; c20_i329 = c20_i329 + 1) {
    c20_nc_A[c20_i329] = c20_v_a[c20_i329];
  }

  for (c20_i330 = 0; c20_i330 < 16; c20_i330 = c20_i330 + 1) {
    c20_nc_B[c20_i330] = c20_v_b[c20_i330];
  }

  for (c20_i331 = 0; c20_i331 < 16; c20_i331 = c20_i331 + 1) {
    c20_g01[c20_i331] = 0.0;
  }

  for (c20_i332 = 0; c20_i332 < 16; c20_i332 = c20_i332 + 1) {
    c20_oc_A[c20_i332] = c20_nc_A[c20_i332];
  }

  for (c20_i333 = 0; c20_i333 < 16; c20_i333 = c20_i333 + 1) {
    c20_oc_B[c20_i333] = c20_nc_B[c20_i333];
  }

  for (c20_i334 = 0; c20_i334 < 16; c20_i334 = c20_i334 + 1) {
    c20_pc_A[c20_i334] = c20_oc_A[c20_i334];
  }

  for (c20_i335 = 0; c20_i335 < 16; c20_i335 = c20_i335 + 1) {
    c20_pc_B[c20_i335] = c20_oc_B[c20_i335];
  }

  for (c20_i336 = 0; c20_i336 < 4; c20_i336 = c20_i336 + 1) {
    c20_i337 = 0;
    for (c20_i338 = 0; c20_i338 < 4; c20_i338 = c20_i338 + 1) {
      c20_g01[c20_i337 + c20_i336] = 0.0;
      c20_i339 = 0;
      for (c20_i340 = 0; c20_i340 < 4; c20_i340 = c20_i340 + 1) {
        c20_g01[c20_i337 + c20_i336] = c20_g01[c20_i337 + c20_i336] +
          c20_pc_A[c20_i339 + c20_i336] * c20_pc_B[c20_i340 + c20_i337];
        c20_i339 = c20_i339 + 4;
      }

      c20_i337 = c20_i337 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 106);
  for (c20_i341 = 0; c20_i341 < 16; c20_i341 = c20_i341 + 1) {
    c20_b_g01[c20_i341] = c20_g01[c20_i341];
  }

  for (c20_i342 = 0; c20_i342 < 16; c20_i342 = c20_i342 + 1) {
    c20_dv42[c20_i342] = c20_dv41[c20_i342];
  }

  c20_mldivide(chartInstance, c20_b_g01, c20_dv42, c20_dv43);
  for (c20_i343 = 0; c20_i343 < 16; c20_i343 = c20_i343 + 1) {
    c20_dv44[c20_i343] = c20_dv43[c20_i343];
  }

  c20_Adj(chartInstance, c20_dv44, c20_dv45);
  for (c20_i344 = 0; c20_i344 < 36; c20_i344 = c20_i344 + 1) {
    c20_Adinvg01[c20_i344] = c20_dv45[c20_i344];
  }

  _SFD_SCRIPT_CALL(0, 107);
  for (c20_i345 = 0; c20_i345 < 36; c20_i345 = c20_i345 + 1) {
    c20_w_a[c20_i345] = c20_Adinvg01[c20_i345];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i346 = 0; c20_i346 < 36; c20_i346 = c20_i346 + 1) {
    c20_x_a[c20_i346] = c20_w_a[c20_i346];
  }

  for (c20_i347 = 0; c20_i347 < 6; c20_i347 = c20_i347 + 1) {
    c20_dv46[c20_i347] = 0.0;
  }

  for (c20_i348 = 0; c20_i348 < 6; c20_i348 = c20_i348 + 1) {
    c20_dv47[c20_i348] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_x_a, c20_dv46, c20_dv47, c20_o_y);
  c20_w_b = c20_Vel[0];
  for (c20_i349 = 0; c20_i349 < 6; c20_i349 = c20_i349 + 1) {
    c20_p_y[c20_i349] = c20_dv6[c20_i349] * c20_w_b;
  }

  for (c20_i350 = 0; c20_i350 < 6; c20_i350 = c20_i350 + 1) {
    c20_V1[c20_i350] = c20_o_y[c20_i350] + c20_p_y[c20_i350];
  }

  _SFD_SCRIPT_CALL(0, 108);
  c20_x_b = c20_Acc[0];
  for (c20_i351 = 0; c20_i351 < 6; c20_i351 = c20_i351 + 1) {
    c20_q_y[c20_i351] = c20_dv6[c20_i351] * c20_x_b;
  }

  for (c20_i352 = 0; c20_i352 < 36; c20_i352 = c20_i352 + 1) {
    c20_y_a[c20_i352] = c20_Adinvg01[c20_i352];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i353 = 0; c20_i353 < 36; c20_i353 = c20_i353 + 1) {
    c20_ab_a[c20_i353] = c20_y_a[c20_i353];
  }

  for (c20_i354 = 0; c20_i354 < 6; c20_i354 = c20_i354 + 1) {
    c20_dv48[c20_i354] = c20_dv39[c20_i354];
  }

  for (c20_i355 = 0; c20_i355 < 6; c20_i355 = c20_i355 + 1) {
    c20_dv49[c20_i355] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ab_a, c20_dv48, c20_dv49, c20_r_y);
  c20_y_b = c20_Vel[0];
  for (c20_i356 = 0; c20_i356 < 6; c20_i356 = c20_i356 + 1) {
    c20_s_y[c20_i356] = c20_dv6[c20_i356] * c20_y_b;
  }

  for (c20_i357 = 0; c20_i357 < 36; c20_i357 = c20_i357 + 1) {
    c20_bb_a[c20_i357] = c20_Adinvg01[c20_i357];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i358 = 0; c20_i358 < 36; c20_i358 = c20_i358 + 1) {
    c20_cb_a[c20_i358] = c20_bb_a[c20_i358];
  }

  for (c20_i359 = 0; c20_i359 < 6; c20_i359 = c20_i359 + 1) {
    c20_dv50[c20_i359] = 0.0;
  }

  for (c20_i360 = 0; c20_i360 < 6; c20_i360 = c20_i360 + 1) {
    c20_dv51[c20_i360] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_cb_a, c20_dv50, c20_dv51, c20_t_y);
  for (c20_i361 = 0; c20_i361 < 6; c20_i361 = c20_i361 + 1) {
    c20_u_y[c20_i361] = c20_s_y[c20_i361];
  }

  c20_ad(chartInstance, c20_u_y, c20_db_a);
  for (c20_i362 = 0; c20_i362 < 6; c20_i362 = c20_i362 + 1) {
    c20_ab_b[c20_i362] = c20_t_y[c20_i362];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i363 = 0; c20_i363 < 36; c20_i363 = c20_i363 + 1) {
    c20_eb_a[c20_i363] = c20_db_a[c20_i363];
  }

  for (c20_i364 = 0; c20_i364 < 6; c20_i364 = c20_i364 + 1) {
    c20_bb_b[c20_i364] = c20_ab_b[c20_i364];
  }

  for (c20_i365 = 0; c20_i365 < 6; c20_i365 = c20_i365 + 1) {
    c20_dv52[c20_i365] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_eb_a, c20_bb_b, c20_dv52, c20_v_y);
  for (c20_i366 = 0; c20_i366 < 6; c20_i366 = c20_i366 + 1) {
    c20_dV1[c20_i366] = (c20_q_y[c20_i366] + c20_r_y[c20_i366]) -
      c20_v_y[c20_i366];
  }

  /*  Joint 2: */
  _SFD_SCRIPT_CALL(0, 111);
  for (c20_i367 = 0; c20_i367 < 16; c20_i367 = c20_i367 + 1) {
    c20_fb_a[c20_i367] = c20_g12_0[c20_i367];
  }

  for (c20_i368 = 0; c20_i368 < 6; c20_i368 = c20_i368 + 1) {
    c20_dv53[c20_i368] = c20_dv6[c20_i368];
  }

  c20_expg(chartInstance, c20_dv53, c20_Pos[1], c20_cb_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i369 = 0; c20_i369 < 16; c20_i369 = c20_i369 + 1) {
    c20_qc_A[c20_i369] = c20_fb_a[c20_i369];
  }

  for (c20_i370 = 0; c20_i370 < 16; c20_i370 = c20_i370 + 1) {
    c20_qc_B[c20_i370] = c20_cb_b[c20_i370];
  }

  for (c20_i371 = 0; c20_i371 < 16; c20_i371 = c20_i371 + 1) {
    c20_g12[c20_i371] = 0.0;
  }

  for (c20_i372 = 0; c20_i372 < 16; c20_i372 = c20_i372 + 1) {
    c20_rc_A[c20_i372] = c20_qc_A[c20_i372];
  }

  for (c20_i373 = 0; c20_i373 < 16; c20_i373 = c20_i373 + 1) {
    c20_rc_B[c20_i373] = c20_qc_B[c20_i373];
  }

  for (c20_i374 = 0; c20_i374 < 16; c20_i374 = c20_i374 + 1) {
    c20_sc_A[c20_i374] = c20_rc_A[c20_i374];
  }

  for (c20_i375 = 0; c20_i375 < 16; c20_i375 = c20_i375 + 1) {
    c20_sc_B[c20_i375] = c20_rc_B[c20_i375];
  }

  for (c20_i376 = 0; c20_i376 < 4; c20_i376 = c20_i376 + 1) {
    c20_i377 = 0;
    for (c20_i378 = 0; c20_i378 < 4; c20_i378 = c20_i378 + 1) {
      c20_g12[c20_i377 + c20_i376] = 0.0;
      c20_i379 = 0;
      for (c20_i380 = 0; c20_i380 < 4; c20_i380 = c20_i380 + 1) {
        c20_g12[c20_i377 + c20_i376] = c20_g12[c20_i377 + c20_i376] +
          c20_sc_A[c20_i379 + c20_i376] * c20_sc_B[c20_i380 + c20_i377];
        c20_i379 = c20_i379 + 4;
      }

      c20_i377 = c20_i377 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 112);
  for (c20_i381 = 0; c20_i381 < 16; c20_i381 = c20_i381 + 1) {
    c20_b_g12[c20_i381] = c20_g12[c20_i381];
  }

  for (c20_i382 = 0; c20_i382 < 16; c20_i382 = c20_i382 + 1) {
    c20_dv54[c20_i382] = c20_dv41[c20_i382];
  }

  c20_mldivide(chartInstance, c20_b_g12, c20_dv54, c20_dv55);
  for (c20_i383 = 0; c20_i383 < 16; c20_i383 = c20_i383 + 1) {
    c20_dv56[c20_i383] = c20_dv55[c20_i383];
  }

  c20_Adj(chartInstance, c20_dv56, c20_dv57);
  for (c20_i384 = 0; c20_i384 < 36; c20_i384 = c20_i384 + 1) {
    c20_Adinvg12[c20_i384] = c20_dv57[c20_i384];
  }

  _SFD_SCRIPT_CALL(0, 113);
  for (c20_i385 = 0; c20_i385 < 36; c20_i385 = c20_i385 + 1) {
    c20_gb_a[c20_i385] = c20_Adinvg12[c20_i385];
  }

  for (c20_i386 = 0; c20_i386 < 6; c20_i386 = c20_i386 + 1) {
    c20_db_b[c20_i386] = c20_V1[c20_i386];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i387 = 0; c20_i387 < 36; c20_i387 = c20_i387 + 1) {
    c20_hb_a[c20_i387] = c20_gb_a[c20_i387];
  }

  for (c20_i388 = 0; c20_i388 < 6; c20_i388 = c20_i388 + 1) {
    c20_eb_b[c20_i388] = c20_db_b[c20_i388];
  }

  for (c20_i389 = 0; c20_i389 < 6; c20_i389 = c20_i389 + 1) {
    c20_dv58[c20_i389] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_hb_a, c20_eb_b, c20_dv58, c20_w_y);
  c20_fb_b = c20_Vel[1];
  for (c20_i390 = 0; c20_i390 < 6; c20_i390 = c20_i390 + 1) {
    c20_x_y[c20_i390] = c20_dv6[c20_i390] * c20_fb_b;
  }

  for (c20_i391 = 0; c20_i391 < 6; c20_i391 = c20_i391 + 1) {
    c20_V2[c20_i391] = c20_w_y[c20_i391] + c20_x_y[c20_i391];
  }

  _SFD_SCRIPT_CALL(0, 114);
  c20_gb_b = c20_Acc[1];
  for (c20_i392 = 0; c20_i392 < 6; c20_i392 = c20_i392 + 1) {
    c20_y_y[c20_i392] = c20_dv6[c20_i392] * c20_gb_b;
  }

  for (c20_i393 = 0; c20_i393 < 36; c20_i393 = c20_i393 + 1) {
    c20_ib_a[c20_i393] = c20_Adinvg12[c20_i393];
  }

  for (c20_i394 = 0; c20_i394 < 6; c20_i394 = c20_i394 + 1) {
    c20_hb_b[c20_i394] = c20_dV1[c20_i394];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i395 = 0; c20_i395 < 36; c20_i395 = c20_i395 + 1) {
    c20_jb_a[c20_i395] = c20_ib_a[c20_i395];
  }

  for (c20_i396 = 0; c20_i396 < 6; c20_i396 = c20_i396 + 1) {
    c20_ib_b[c20_i396] = c20_hb_b[c20_i396];
  }

  for (c20_i397 = 0; c20_i397 < 6; c20_i397 = c20_i397 + 1) {
    c20_dv59[c20_i397] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_jb_a, c20_ib_b, c20_dv59, c20_ab_y);
  c20_jb_b = c20_Vel[1];
  for (c20_i398 = 0; c20_i398 < 6; c20_i398 = c20_i398 + 1) {
    c20_bb_y[c20_i398] = c20_dv6[c20_i398] * c20_jb_b;
  }

  for (c20_i399 = 0; c20_i399 < 36; c20_i399 = c20_i399 + 1) {
    c20_kb_a[c20_i399] = c20_Adinvg12[c20_i399];
  }

  for (c20_i400 = 0; c20_i400 < 6; c20_i400 = c20_i400 + 1) {
    c20_kb_b[c20_i400] = c20_V1[c20_i400];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i401 = 0; c20_i401 < 36; c20_i401 = c20_i401 + 1) {
    c20_lb_a[c20_i401] = c20_kb_a[c20_i401];
  }

  for (c20_i402 = 0; c20_i402 < 6; c20_i402 = c20_i402 + 1) {
    c20_lb_b[c20_i402] = c20_kb_b[c20_i402];
  }

  for (c20_i403 = 0; c20_i403 < 6; c20_i403 = c20_i403 + 1) {
    c20_dv60[c20_i403] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_lb_a, c20_lb_b, c20_dv60, c20_cb_y);
  for (c20_i404 = 0; c20_i404 < 6; c20_i404 = c20_i404 + 1) {
    c20_db_y[c20_i404] = c20_bb_y[c20_i404];
  }

  c20_ad(chartInstance, c20_db_y, c20_mb_a);
  for (c20_i405 = 0; c20_i405 < 6; c20_i405 = c20_i405 + 1) {
    c20_mb_b[c20_i405] = c20_cb_y[c20_i405];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i406 = 0; c20_i406 < 36; c20_i406 = c20_i406 + 1) {
    c20_nb_a[c20_i406] = c20_mb_a[c20_i406];
  }

  for (c20_i407 = 0; c20_i407 < 6; c20_i407 = c20_i407 + 1) {
    c20_nb_b[c20_i407] = c20_mb_b[c20_i407];
  }

  for (c20_i408 = 0; c20_i408 < 6; c20_i408 = c20_i408 + 1) {
    c20_dv61[c20_i408] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_nb_a, c20_nb_b, c20_dv61, c20_eb_y);
  for (c20_i409 = 0; c20_i409 < 6; c20_i409 = c20_i409 + 1) {
    c20_dV2[c20_i409] = (c20_y_y[c20_i409] + c20_ab_y[c20_i409]) -
      c20_eb_y[c20_i409];
  }

  /*  Joint 3: */
  _SFD_SCRIPT_CALL(0, 117);
  for (c20_i410 = 0; c20_i410 < 16; c20_i410 = c20_i410 + 1) {
    c20_ob_a[c20_i410] = c20_g23_0[c20_i410];
  }

  for (c20_i411 = 0; c20_i411 < 6; c20_i411 = c20_i411 + 1) {
    c20_dv62[c20_i411] = c20_dv6[c20_i411];
  }

  c20_expg(chartInstance, c20_dv62, c20_Pos[2], c20_ob_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i412 = 0; c20_i412 < 16; c20_i412 = c20_i412 + 1) {
    c20_tc_A[c20_i412] = c20_ob_a[c20_i412];
  }

  for (c20_i413 = 0; c20_i413 < 16; c20_i413 = c20_i413 + 1) {
    c20_tc_B[c20_i413] = c20_ob_b[c20_i413];
  }

  for (c20_i414 = 0; c20_i414 < 16; c20_i414 = c20_i414 + 1) {
    c20_g23[c20_i414] = 0.0;
  }

  for (c20_i415 = 0; c20_i415 < 16; c20_i415 = c20_i415 + 1) {
    c20_uc_A[c20_i415] = c20_tc_A[c20_i415];
  }

  for (c20_i416 = 0; c20_i416 < 16; c20_i416 = c20_i416 + 1) {
    c20_uc_B[c20_i416] = c20_tc_B[c20_i416];
  }

  for (c20_i417 = 0; c20_i417 < 16; c20_i417 = c20_i417 + 1) {
    c20_vc_A[c20_i417] = c20_uc_A[c20_i417];
  }

  for (c20_i418 = 0; c20_i418 < 16; c20_i418 = c20_i418 + 1) {
    c20_vc_B[c20_i418] = c20_uc_B[c20_i418];
  }

  for (c20_i419 = 0; c20_i419 < 4; c20_i419 = c20_i419 + 1) {
    c20_i420 = 0;
    for (c20_i421 = 0; c20_i421 < 4; c20_i421 = c20_i421 + 1) {
      c20_g23[c20_i420 + c20_i419] = 0.0;
      c20_i422 = 0;
      for (c20_i423 = 0; c20_i423 < 4; c20_i423 = c20_i423 + 1) {
        c20_g23[c20_i420 + c20_i419] = c20_g23[c20_i420 + c20_i419] +
          c20_vc_A[c20_i422 + c20_i419] * c20_vc_B[c20_i423 + c20_i420];
        c20_i422 = c20_i422 + 4;
      }

      c20_i420 = c20_i420 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 118);
  for (c20_i424 = 0; c20_i424 < 16; c20_i424 = c20_i424 + 1) {
    c20_b_g23[c20_i424] = c20_g23[c20_i424];
  }

  for (c20_i425 = 0; c20_i425 < 16; c20_i425 = c20_i425 + 1) {
    c20_dv63[c20_i425] = c20_dv41[c20_i425];
  }

  c20_mldivide(chartInstance, c20_b_g23, c20_dv63, c20_dv64);
  for (c20_i426 = 0; c20_i426 < 16; c20_i426 = c20_i426 + 1) {
    c20_dv65[c20_i426] = c20_dv64[c20_i426];
  }

  c20_Adj(chartInstance, c20_dv65, c20_dv66);
  for (c20_i427 = 0; c20_i427 < 36; c20_i427 = c20_i427 + 1) {
    c20_Adinvg23[c20_i427] = c20_dv66[c20_i427];
  }

  _SFD_SCRIPT_CALL(0, 119);
  for (c20_i428 = 0; c20_i428 < 36; c20_i428 = c20_i428 + 1) {
    c20_pb_a[c20_i428] = c20_Adinvg23[c20_i428];
  }

  for (c20_i429 = 0; c20_i429 < 6; c20_i429 = c20_i429 + 1) {
    c20_pb_b[c20_i429] = c20_V2[c20_i429];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i430 = 0; c20_i430 < 36; c20_i430 = c20_i430 + 1) {
    c20_qb_a[c20_i430] = c20_pb_a[c20_i430];
  }

  for (c20_i431 = 0; c20_i431 < 6; c20_i431 = c20_i431 + 1) {
    c20_qb_b[c20_i431] = c20_pb_b[c20_i431];
  }

  for (c20_i432 = 0; c20_i432 < 6; c20_i432 = c20_i432 + 1) {
    c20_dv67[c20_i432] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_qb_a, c20_qb_b, c20_dv67, c20_fb_y);
  c20_rb_b = c20_Vel[2];
  for (c20_i433 = 0; c20_i433 < 6; c20_i433 = c20_i433 + 1) {
    c20_gb_y[c20_i433] = c20_dv6[c20_i433] * c20_rb_b;
  }

  for (c20_i434 = 0; c20_i434 < 6; c20_i434 = c20_i434 + 1) {
    c20_V3[c20_i434] = c20_fb_y[c20_i434] + c20_gb_y[c20_i434];
  }

  _SFD_SCRIPT_CALL(0, 120);
  c20_sb_b = c20_Acc[2];
  for (c20_i435 = 0; c20_i435 < 6; c20_i435 = c20_i435 + 1) {
    c20_hb_y[c20_i435] = c20_dv6[c20_i435] * c20_sb_b;
  }

  for (c20_i436 = 0; c20_i436 < 36; c20_i436 = c20_i436 + 1) {
    c20_rb_a[c20_i436] = c20_Adinvg23[c20_i436];
  }

  for (c20_i437 = 0; c20_i437 < 6; c20_i437 = c20_i437 + 1) {
    c20_tb_b[c20_i437] = c20_dV2[c20_i437];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i438 = 0; c20_i438 < 36; c20_i438 = c20_i438 + 1) {
    c20_sb_a[c20_i438] = c20_rb_a[c20_i438];
  }

  for (c20_i439 = 0; c20_i439 < 6; c20_i439 = c20_i439 + 1) {
    c20_ub_b[c20_i439] = c20_tb_b[c20_i439];
  }

  for (c20_i440 = 0; c20_i440 < 6; c20_i440 = c20_i440 + 1) {
    c20_dv68[c20_i440] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_sb_a, c20_ub_b, c20_dv68, c20_ib_y);
  c20_vb_b = c20_Vel[2];
  for (c20_i441 = 0; c20_i441 < 6; c20_i441 = c20_i441 + 1) {
    c20_jb_y[c20_i441] = c20_dv6[c20_i441] * c20_vb_b;
  }

  for (c20_i442 = 0; c20_i442 < 36; c20_i442 = c20_i442 + 1) {
    c20_tb_a[c20_i442] = c20_Adinvg23[c20_i442];
  }

  for (c20_i443 = 0; c20_i443 < 6; c20_i443 = c20_i443 + 1) {
    c20_wb_b[c20_i443] = c20_V2[c20_i443];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i444 = 0; c20_i444 < 36; c20_i444 = c20_i444 + 1) {
    c20_ub_a[c20_i444] = c20_tb_a[c20_i444];
  }

  for (c20_i445 = 0; c20_i445 < 6; c20_i445 = c20_i445 + 1) {
    c20_xb_b[c20_i445] = c20_wb_b[c20_i445];
  }

  for (c20_i446 = 0; c20_i446 < 6; c20_i446 = c20_i446 + 1) {
    c20_dv69[c20_i446] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ub_a, c20_xb_b, c20_dv69, c20_kb_y);
  for (c20_i447 = 0; c20_i447 < 6; c20_i447 = c20_i447 + 1) {
    c20_lb_y[c20_i447] = c20_jb_y[c20_i447];
  }

  c20_ad(chartInstance, c20_lb_y, c20_vb_a);
  for (c20_i448 = 0; c20_i448 < 6; c20_i448 = c20_i448 + 1) {
    c20_yb_b[c20_i448] = c20_kb_y[c20_i448];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i449 = 0; c20_i449 < 36; c20_i449 = c20_i449 + 1) {
    c20_wb_a[c20_i449] = c20_vb_a[c20_i449];
  }

  for (c20_i450 = 0; c20_i450 < 6; c20_i450 = c20_i450 + 1) {
    c20_ac_b[c20_i450] = c20_yb_b[c20_i450];
  }

  for (c20_i451 = 0; c20_i451 < 6; c20_i451 = c20_i451 + 1) {
    c20_dv70[c20_i451] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_wb_a, c20_ac_b, c20_dv70, c20_mb_y);
  for (c20_i452 = 0; c20_i452 < 6; c20_i452 = c20_i452 + 1) {
    c20_dV3[c20_i452] = (c20_hb_y[c20_i452] + c20_ib_y[c20_i452]) -
      c20_mb_y[c20_i452];
  }

  /*  Joint 4: */
  _SFD_SCRIPT_CALL(0, 123);
  for (c20_i453 = 0; c20_i453 < 16; c20_i453 = c20_i453 + 1) {
    c20_xb_a[c20_i453] = c20_g34_0[c20_i453];
  }

  for (c20_i454 = 0; c20_i454 < 6; c20_i454 = c20_i454 + 1) {
    c20_dv71[c20_i454] = c20_dv6[c20_i454];
  }

  c20_expg(chartInstance, c20_dv71, c20_Pos[3], c20_bc_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i455 = 0; c20_i455 < 16; c20_i455 = c20_i455 + 1) {
    c20_wc_A[c20_i455] = c20_xb_a[c20_i455];
  }

  for (c20_i456 = 0; c20_i456 < 16; c20_i456 = c20_i456 + 1) {
    c20_wc_B[c20_i456] = c20_bc_b[c20_i456];
  }

  for (c20_i457 = 0; c20_i457 < 16; c20_i457 = c20_i457 + 1) {
    c20_g34[c20_i457] = 0.0;
  }

  for (c20_i458 = 0; c20_i458 < 16; c20_i458 = c20_i458 + 1) {
    c20_xc_A[c20_i458] = c20_wc_A[c20_i458];
  }

  for (c20_i459 = 0; c20_i459 < 16; c20_i459 = c20_i459 + 1) {
    c20_xc_B[c20_i459] = c20_wc_B[c20_i459];
  }

  for (c20_i460 = 0; c20_i460 < 16; c20_i460 = c20_i460 + 1) {
    c20_yc_A[c20_i460] = c20_xc_A[c20_i460];
  }

  for (c20_i461 = 0; c20_i461 < 16; c20_i461 = c20_i461 + 1) {
    c20_yc_B[c20_i461] = c20_xc_B[c20_i461];
  }

  for (c20_i462 = 0; c20_i462 < 4; c20_i462 = c20_i462 + 1) {
    c20_i463 = 0;
    for (c20_i464 = 0; c20_i464 < 4; c20_i464 = c20_i464 + 1) {
      c20_g34[c20_i463 + c20_i462] = 0.0;
      c20_i465 = 0;
      for (c20_i466 = 0; c20_i466 < 4; c20_i466 = c20_i466 + 1) {
        c20_g34[c20_i463 + c20_i462] = c20_g34[c20_i463 + c20_i462] +
          c20_yc_A[c20_i465 + c20_i462] * c20_yc_B[c20_i466 + c20_i463];
        c20_i465 = c20_i465 + 4;
      }

      c20_i463 = c20_i463 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 124);
  for (c20_i467 = 0; c20_i467 < 16; c20_i467 = c20_i467 + 1) {
    c20_b_g34[c20_i467] = c20_g34[c20_i467];
  }

  for (c20_i468 = 0; c20_i468 < 16; c20_i468 = c20_i468 + 1) {
    c20_dv72[c20_i468] = c20_dv41[c20_i468];
  }

  c20_mldivide(chartInstance, c20_b_g34, c20_dv72, c20_dv73);
  for (c20_i469 = 0; c20_i469 < 16; c20_i469 = c20_i469 + 1) {
    c20_dv74[c20_i469] = c20_dv73[c20_i469];
  }

  c20_Adj(chartInstance, c20_dv74, c20_dv75);
  for (c20_i470 = 0; c20_i470 < 36; c20_i470 = c20_i470 + 1) {
    c20_Adinvg34[c20_i470] = c20_dv75[c20_i470];
  }

  _SFD_SCRIPT_CALL(0, 125);
  for (c20_i471 = 0; c20_i471 < 36; c20_i471 = c20_i471 + 1) {
    c20_yb_a[c20_i471] = c20_Adinvg34[c20_i471];
  }

  for (c20_i472 = 0; c20_i472 < 6; c20_i472 = c20_i472 + 1) {
    c20_cc_b[c20_i472] = c20_V3[c20_i472];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i473 = 0; c20_i473 < 36; c20_i473 = c20_i473 + 1) {
    c20_ac_a[c20_i473] = c20_yb_a[c20_i473];
  }

  for (c20_i474 = 0; c20_i474 < 6; c20_i474 = c20_i474 + 1) {
    c20_dc_b[c20_i474] = c20_cc_b[c20_i474];
  }

  for (c20_i475 = 0; c20_i475 < 6; c20_i475 = c20_i475 + 1) {
    c20_dv76[c20_i475] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ac_a, c20_dc_b, c20_dv76, c20_nb_y);
  c20_ec_b = c20_Vel[3];
  for (c20_i476 = 0; c20_i476 < 6; c20_i476 = c20_i476 + 1) {
    c20_ob_y[c20_i476] = c20_dv6[c20_i476] * c20_ec_b;
  }

  for (c20_i477 = 0; c20_i477 < 6; c20_i477 = c20_i477 + 1) {
    c20_V4[c20_i477] = c20_nb_y[c20_i477] + c20_ob_y[c20_i477];
  }

  _SFD_SCRIPT_CALL(0, 126);
  c20_fc_b = c20_Acc[3];
  for (c20_i478 = 0; c20_i478 < 6; c20_i478 = c20_i478 + 1) {
    c20_pb_y[c20_i478] = c20_dv6[c20_i478] * c20_fc_b;
  }

  for (c20_i479 = 0; c20_i479 < 36; c20_i479 = c20_i479 + 1) {
    c20_bc_a[c20_i479] = c20_Adinvg34[c20_i479];
  }

  for (c20_i480 = 0; c20_i480 < 6; c20_i480 = c20_i480 + 1) {
    c20_gc_b[c20_i480] = c20_dV3[c20_i480];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i481 = 0; c20_i481 < 36; c20_i481 = c20_i481 + 1) {
    c20_cc_a[c20_i481] = c20_bc_a[c20_i481];
  }

  for (c20_i482 = 0; c20_i482 < 6; c20_i482 = c20_i482 + 1) {
    c20_hc_b[c20_i482] = c20_gc_b[c20_i482];
  }

  for (c20_i483 = 0; c20_i483 < 6; c20_i483 = c20_i483 + 1) {
    c20_dv77[c20_i483] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_cc_a, c20_hc_b, c20_dv77, c20_qb_y);
  c20_ic_b = c20_Vel[3];
  for (c20_i484 = 0; c20_i484 < 6; c20_i484 = c20_i484 + 1) {
    c20_rb_y[c20_i484] = c20_dv6[c20_i484] * c20_ic_b;
  }

  for (c20_i485 = 0; c20_i485 < 36; c20_i485 = c20_i485 + 1) {
    c20_dc_a[c20_i485] = c20_Adinvg34[c20_i485];
  }

  for (c20_i486 = 0; c20_i486 < 6; c20_i486 = c20_i486 + 1) {
    c20_jc_b[c20_i486] = c20_V3[c20_i486];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i487 = 0; c20_i487 < 36; c20_i487 = c20_i487 + 1) {
    c20_ec_a[c20_i487] = c20_dc_a[c20_i487];
  }

  for (c20_i488 = 0; c20_i488 < 6; c20_i488 = c20_i488 + 1) {
    c20_kc_b[c20_i488] = c20_jc_b[c20_i488];
  }

  for (c20_i489 = 0; c20_i489 < 6; c20_i489 = c20_i489 + 1) {
    c20_dv78[c20_i489] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ec_a, c20_kc_b, c20_dv78, c20_sb_y);
  for (c20_i490 = 0; c20_i490 < 6; c20_i490 = c20_i490 + 1) {
    c20_tb_y[c20_i490] = c20_rb_y[c20_i490];
  }

  c20_ad(chartInstance, c20_tb_y, c20_fc_a);
  for (c20_i491 = 0; c20_i491 < 6; c20_i491 = c20_i491 + 1) {
    c20_lc_b[c20_i491] = c20_sb_y[c20_i491];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i492 = 0; c20_i492 < 36; c20_i492 = c20_i492 + 1) {
    c20_gc_a[c20_i492] = c20_fc_a[c20_i492];
  }

  for (c20_i493 = 0; c20_i493 < 6; c20_i493 = c20_i493 + 1) {
    c20_mc_b[c20_i493] = c20_lc_b[c20_i493];
  }

  for (c20_i494 = 0; c20_i494 < 6; c20_i494 = c20_i494 + 1) {
    c20_dv79[c20_i494] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_gc_a, c20_mc_b, c20_dv79, c20_ub_y);
  for (c20_i495 = 0; c20_i495 < 6; c20_i495 = c20_i495 + 1) {
    c20_dV4[c20_i495] = (c20_pb_y[c20_i495] + c20_qb_y[c20_i495]) -
      c20_ub_y[c20_i495];
  }

  /*  Joint 5: */
  _SFD_SCRIPT_CALL(0, 129);
  for (c20_i496 = 0; c20_i496 < 16; c20_i496 = c20_i496 + 1) {
    c20_hc_a[c20_i496] = c20_g45_0[c20_i496];
  }

  for (c20_i497 = 0; c20_i497 < 6; c20_i497 = c20_i497 + 1) {
    c20_dv80[c20_i497] = c20_dv6[c20_i497];
  }

  c20_expg(chartInstance, c20_dv80, c20_Pos[4], c20_nc_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i498 = 0; c20_i498 < 16; c20_i498 = c20_i498 + 1) {
    c20_ad_A[c20_i498] = c20_hc_a[c20_i498];
  }

  for (c20_i499 = 0; c20_i499 < 16; c20_i499 = c20_i499 + 1) {
    c20_ad_B[c20_i499] = c20_nc_b[c20_i499];
  }

  for (c20_i500 = 0; c20_i500 < 16; c20_i500 = c20_i500 + 1) {
    c20_g45[c20_i500] = 0.0;
  }

  for (c20_i501 = 0; c20_i501 < 16; c20_i501 = c20_i501 + 1) {
    c20_bd_A[c20_i501] = c20_ad_A[c20_i501];
  }

  for (c20_i502 = 0; c20_i502 < 16; c20_i502 = c20_i502 + 1) {
    c20_bd_B[c20_i502] = c20_ad_B[c20_i502];
  }

  for (c20_i503 = 0; c20_i503 < 16; c20_i503 = c20_i503 + 1) {
    c20_cd_A[c20_i503] = c20_bd_A[c20_i503];
  }

  for (c20_i504 = 0; c20_i504 < 16; c20_i504 = c20_i504 + 1) {
    c20_cd_B[c20_i504] = c20_bd_B[c20_i504];
  }

  for (c20_i505 = 0; c20_i505 < 4; c20_i505 = c20_i505 + 1) {
    c20_i506 = 0;
    for (c20_i507 = 0; c20_i507 < 4; c20_i507 = c20_i507 + 1) {
      c20_g45[c20_i506 + c20_i505] = 0.0;
      c20_i508 = 0;
      for (c20_i509 = 0; c20_i509 < 4; c20_i509 = c20_i509 + 1) {
        c20_g45[c20_i506 + c20_i505] = c20_g45[c20_i506 + c20_i505] +
          c20_cd_A[c20_i508 + c20_i505] * c20_cd_B[c20_i509 + c20_i506];
        c20_i508 = c20_i508 + 4;
      }

      c20_i506 = c20_i506 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 130);
  for (c20_i510 = 0; c20_i510 < 16; c20_i510 = c20_i510 + 1) {
    c20_b_g45[c20_i510] = c20_g45[c20_i510];
  }

  for (c20_i511 = 0; c20_i511 < 16; c20_i511 = c20_i511 + 1) {
    c20_dv81[c20_i511] = c20_dv41[c20_i511];
  }

  c20_mldivide(chartInstance, c20_b_g45, c20_dv81, c20_dv82);
  for (c20_i512 = 0; c20_i512 < 16; c20_i512 = c20_i512 + 1) {
    c20_dv83[c20_i512] = c20_dv82[c20_i512];
  }

  c20_Adj(chartInstance, c20_dv83, c20_dv84);
  for (c20_i513 = 0; c20_i513 < 36; c20_i513 = c20_i513 + 1) {
    c20_Adinvg45[c20_i513] = c20_dv84[c20_i513];
  }

  _SFD_SCRIPT_CALL(0, 131);
  for (c20_i514 = 0; c20_i514 < 36; c20_i514 = c20_i514 + 1) {
    c20_ic_a[c20_i514] = c20_Adinvg45[c20_i514];
  }

  for (c20_i515 = 0; c20_i515 < 6; c20_i515 = c20_i515 + 1) {
    c20_oc_b[c20_i515] = c20_V4[c20_i515];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i516 = 0; c20_i516 < 36; c20_i516 = c20_i516 + 1) {
    c20_jc_a[c20_i516] = c20_ic_a[c20_i516];
  }

  for (c20_i517 = 0; c20_i517 < 6; c20_i517 = c20_i517 + 1) {
    c20_pc_b[c20_i517] = c20_oc_b[c20_i517];
  }

  for (c20_i518 = 0; c20_i518 < 6; c20_i518 = c20_i518 + 1) {
    c20_dv85[c20_i518] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_jc_a, c20_pc_b, c20_dv85, c20_vb_y);
  c20_qc_b = c20_Vel[4];
  for (c20_i519 = 0; c20_i519 < 6; c20_i519 = c20_i519 + 1) {
    c20_wb_y[c20_i519] = c20_dv6[c20_i519] * c20_qc_b;
  }

  for (c20_i520 = 0; c20_i520 < 6; c20_i520 = c20_i520 + 1) {
    c20_V5[c20_i520] = c20_vb_y[c20_i520] + c20_wb_y[c20_i520];
  }

  _SFD_SCRIPT_CALL(0, 132);
  c20_rc_b = c20_Acc[4];
  for (c20_i521 = 0; c20_i521 < 6; c20_i521 = c20_i521 + 1) {
    c20_xb_y[c20_i521] = c20_dv6[c20_i521] * c20_rc_b;
  }

  for (c20_i522 = 0; c20_i522 < 36; c20_i522 = c20_i522 + 1) {
    c20_kc_a[c20_i522] = c20_Adinvg45[c20_i522];
  }

  for (c20_i523 = 0; c20_i523 < 6; c20_i523 = c20_i523 + 1) {
    c20_sc_b[c20_i523] = c20_dV4[c20_i523];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i524 = 0; c20_i524 < 36; c20_i524 = c20_i524 + 1) {
    c20_lc_a[c20_i524] = c20_kc_a[c20_i524];
  }

  for (c20_i525 = 0; c20_i525 < 6; c20_i525 = c20_i525 + 1) {
    c20_tc_b[c20_i525] = c20_sc_b[c20_i525];
  }

  for (c20_i526 = 0; c20_i526 < 6; c20_i526 = c20_i526 + 1) {
    c20_dv86[c20_i526] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_lc_a, c20_tc_b, c20_dv86, c20_yb_y);
  c20_uc_b = c20_Vel[4];
  for (c20_i527 = 0; c20_i527 < 6; c20_i527 = c20_i527 + 1) {
    c20_ac_y[c20_i527] = c20_dv6[c20_i527] * c20_uc_b;
  }

  for (c20_i528 = 0; c20_i528 < 36; c20_i528 = c20_i528 + 1) {
    c20_mc_a[c20_i528] = c20_Adinvg45[c20_i528];
  }

  for (c20_i529 = 0; c20_i529 < 6; c20_i529 = c20_i529 + 1) {
    c20_vc_b[c20_i529] = c20_V4[c20_i529];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i530 = 0; c20_i530 < 36; c20_i530 = c20_i530 + 1) {
    c20_nc_a[c20_i530] = c20_mc_a[c20_i530];
  }

  for (c20_i531 = 0; c20_i531 < 6; c20_i531 = c20_i531 + 1) {
    c20_wc_b[c20_i531] = c20_vc_b[c20_i531];
  }

  for (c20_i532 = 0; c20_i532 < 6; c20_i532 = c20_i532 + 1) {
    c20_dv87[c20_i532] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_nc_a, c20_wc_b, c20_dv87, c20_bc_y);
  for (c20_i533 = 0; c20_i533 < 6; c20_i533 = c20_i533 + 1) {
    c20_cc_y[c20_i533] = c20_ac_y[c20_i533];
  }

  c20_ad(chartInstance, c20_cc_y, c20_oc_a);
  for (c20_i534 = 0; c20_i534 < 6; c20_i534 = c20_i534 + 1) {
    c20_xc_b[c20_i534] = c20_bc_y[c20_i534];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i535 = 0; c20_i535 < 36; c20_i535 = c20_i535 + 1) {
    c20_pc_a[c20_i535] = c20_oc_a[c20_i535];
  }

  for (c20_i536 = 0; c20_i536 < 6; c20_i536 = c20_i536 + 1) {
    c20_yc_b[c20_i536] = c20_xc_b[c20_i536];
  }

  for (c20_i537 = 0; c20_i537 < 6; c20_i537 = c20_i537 + 1) {
    c20_dv88[c20_i537] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_pc_a, c20_yc_b, c20_dv88, c20_dc_y);
  for (c20_i538 = 0; c20_i538 < 6; c20_i538 = c20_i538 + 1) {
    c20_dV5[c20_i538] = (c20_xb_y[c20_i538] + c20_yb_y[c20_i538]) -
      c20_dc_y[c20_i538];
  }

  /*  Joint 6: */
  _SFD_SCRIPT_CALL(0, 135);
  for (c20_i539 = 0; c20_i539 < 16; c20_i539 = c20_i539 + 1) {
    c20_qc_a[c20_i539] = c20_g56_0[c20_i539];
  }

  for (c20_i540 = 0; c20_i540 < 6; c20_i540 = c20_i540 + 1) {
    c20_dv89[c20_i540] = c20_dv6[c20_i540];
  }

  c20_expg(chartInstance, c20_dv89, c20_Pos[5], c20_ad_b);
  c20_d_eml_scalar_eg(chartInstance);
  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i541 = 0; c20_i541 < 16; c20_i541 = c20_i541 + 1) {
    c20_dd_A[c20_i541] = c20_qc_a[c20_i541];
  }

  for (c20_i542 = 0; c20_i542 < 16; c20_i542 = c20_i542 + 1) {
    c20_dd_B[c20_i542] = c20_ad_b[c20_i542];
  }

  for (c20_i543 = 0; c20_i543 < 16; c20_i543 = c20_i543 + 1) {
    c20_g56[c20_i543] = 0.0;
  }

  for (c20_i544 = 0; c20_i544 < 16; c20_i544 = c20_i544 + 1) {
    c20_ed_A[c20_i544] = c20_dd_A[c20_i544];
  }

  for (c20_i545 = 0; c20_i545 < 16; c20_i545 = c20_i545 + 1) {
    c20_ed_B[c20_i545] = c20_dd_B[c20_i545];
  }

  for (c20_i546 = 0; c20_i546 < 16; c20_i546 = c20_i546 + 1) {
    c20_fd_A[c20_i546] = c20_ed_A[c20_i546];
  }

  for (c20_i547 = 0; c20_i547 < 16; c20_i547 = c20_i547 + 1) {
    c20_fd_B[c20_i547] = c20_ed_B[c20_i547];
  }

  for (c20_i548 = 0; c20_i548 < 4; c20_i548 = c20_i548 + 1) {
    c20_i549 = 0;
    for (c20_i550 = 0; c20_i550 < 4; c20_i550 = c20_i550 + 1) {
      c20_g56[c20_i549 + c20_i548] = 0.0;
      c20_i551 = 0;
      for (c20_i552 = 0; c20_i552 < 4; c20_i552 = c20_i552 + 1) {
        c20_g56[c20_i549 + c20_i548] = c20_g56[c20_i549 + c20_i548] +
          c20_fd_A[c20_i551 + c20_i548] * c20_fd_B[c20_i552 + c20_i549];
        c20_i551 = c20_i551 + 4;
      }

      c20_i549 = c20_i549 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 136);
  for (c20_i553 = 0; c20_i553 < 16; c20_i553 = c20_i553 + 1) {
    c20_b_g56[c20_i553] = c20_g56[c20_i553];
  }

  for (c20_i554 = 0; c20_i554 < 16; c20_i554 = c20_i554 + 1) {
    c20_dv90[c20_i554] = c20_dv41[c20_i554];
  }

  c20_mldivide(chartInstance, c20_b_g56, c20_dv90, c20_dv91);
  for (c20_i555 = 0; c20_i555 < 16; c20_i555 = c20_i555 + 1) {
    c20_dv92[c20_i555] = c20_dv91[c20_i555];
  }

  c20_Adj(chartInstance, c20_dv92, c20_dv93);
  for (c20_i556 = 0; c20_i556 < 36; c20_i556 = c20_i556 + 1) {
    c20_Adinvg56[c20_i556] = c20_dv93[c20_i556];
  }

  _SFD_SCRIPT_CALL(0, 137);
  for (c20_i557 = 0; c20_i557 < 36; c20_i557 = c20_i557 + 1) {
    c20_rc_a[c20_i557] = c20_Adinvg56[c20_i557];
  }

  for (c20_i558 = 0; c20_i558 < 6; c20_i558 = c20_i558 + 1) {
    c20_bd_b[c20_i558] = c20_V5[c20_i558];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i559 = 0; c20_i559 < 36; c20_i559 = c20_i559 + 1) {
    c20_sc_a[c20_i559] = c20_rc_a[c20_i559];
  }

  for (c20_i560 = 0; c20_i560 < 6; c20_i560 = c20_i560 + 1) {
    c20_cd_b[c20_i560] = c20_bd_b[c20_i560];
  }

  for (c20_i561 = 0; c20_i561 < 6; c20_i561 = c20_i561 + 1) {
    c20_dv94[c20_i561] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_sc_a, c20_cd_b, c20_dv94, c20_ec_y);
  c20_dd_b = c20_Vel[5];
  for (c20_i562 = 0; c20_i562 < 6; c20_i562 = c20_i562 + 1) {
    c20_fc_y[c20_i562] = c20_dv6[c20_i562] * c20_dd_b;
  }

  for (c20_i563 = 0; c20_i563 < 6; c20_i563 = c20_i563 + 1) {
    c20_V6[c20_i563] = c20_ec_y[c20_i563] + c20_fc_y[c20_i563];
  }

  _SFD_SCRIPT_CALL(0, 138);
  c20_ed_b = c20_Acc[5];
  for (c20_i564 = 0; c20_i564 < 6; c20_i564 = c20_i564 + 1) {
    c20_gc_y[c20_i564] = c20_dv6[c20_i564] * c20_ed_b;
  }

  for (c20_i565 = 0; c20_i565 < 36; c20_i565 = c20_i565 + 1) {
    c20_tc_a[c20_i565] = c20_Adinvg56[c20_i565];
  }

  for (c20_i566 = 0; c20_i566 < 6; c20_i566 = c20_i566 + 1) {
    c20_fd_b[c20_i566] = c20_dV5[c20_i566];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i567 = 0; c20_i567 < 36; c20_i567 = c20_i567 + 1) {
    c20_uc_a[c20_i567] = c20_tc_a[c20_i567];
  }

  for (c20_i568 = 0; c20_i568 < 6; c20_i568 = c20_i568 + 1) {
    c20_gd_b[c20_i568] = c20_fd_b[c20_i568];
  }

  for (c20_i569 = 0; c20_i569 < 6; c20_i569 = c20_i569 + 1) {
    c20_dv95[c20_i569] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_uc_a, c20_gd_b, c20_dv95, c20_hc_y);
  c20_hd_b = c20_Vel[5];
  for (c20_i570 = 0; c20_i570 < 6; c20_i570 = c20_i570 + 1) {
    c20_ic_y[c20_i570] = c20_dv6[c20_i570] * c20_hd_b;
  }

  for (c20_i571 = 0; c20_i571 < 36; c20_i571 = c20_i571 + 1) {
    c20_vc_a[c20_i571] = c20_Adinvg56[c20_i571];
  }

  for (c20_i572 = 0; c20_i572 < 6; c20_i572 = c20_i572 + 1) {
    c20_id_b[c20_i572] = c20_V5[c20_i572];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i573 = 0; c20_i573 < 36; c20_i573 = c20_i573 + 1) {
    c20_wc_a[c20_i573] = c20_vc_a[c20_i573];
  }

  for (c20_i574 = 0; c20_i574 < 6; c20_i574 = c20_i574 + 1) {
    c20_jd_b[c20_i574] = c20_id_b[c20_i574];
  }

  for (c20_i575 = 0; c20_i575 < 6; c20_i575 = c20_i575 + 1) {
    c20_dv96[c20_i575] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_wc_a, c20_jd_b, c20_dv96, c20_jc_y);
  for (c20_i576 = 0; c20_i576 < 6; c20_i576 = c20_i576 + 1) {
    c20_kc_y[c20_i576] = c20_ic_y[c20_i576];
  }

  c20_ad(chartInstance, c20_kc_y, c20_xc_a);
  for (c20_i577 = 0; c20_i577 < 6; c20_i577 = c20_i577 + 1) {
    c20_kd_b[c20_i577] = c20_jc_y[c20_i577];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i578 = 0; c20_i578 < 36; c20_i578 = c20_i578 + 1) {
    c20_yc_a[c20_i578] = c20_xc_a[c20_i578];
  }

  for (c20_i579 = 0; c20_i579 < 6; c20_i579 = c20_i579 + 1) {
    c20_ld_b[c20_i579] = c20_kd_b[c20_i579];
  }

  for (c20_i580 = 0; c20_i580 < 6; c20_i580 = c20_i580 + 1) {
    c20_dv97[c20_i580] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_yc_a, c20_ld_b, c20_dv97, c20_lc_y);
  for (c20_i581 = 0; c20_i581 < 6; c20_i581 = c20_i581 + 1) {
    c20_dV6[c20_i581] = (c20_gc_y[c20_i581] + c20_hc_y[c20_i581]) -
      c20_lc_y[c20_i581];
  }

  /*  %% Backward Recursion (inverse dynamic) */
  /*  Initial State */
  _SFD_SCRIPT_CALL(0, 142);
  for (c20_i582 = 0; c20_i582 < 6; c20_i582 = c20_i582 + 1) {
    c20_Tau[c20_i582] = 0.0;
  }

  _SFD_SCRIPT_CALL(0, 143);
  for (c20_i583 = 0; c20_i583 < 6; c20_i583 = c20_i583 + 1) {
    c20_F7[c20_i583] = c20_Ft[c20_i583];
  }

  _SFD_SCRIPT_CALL(0, 144);
  for (c20_i584 = 0; c20_i584 < 16; c20_i584 = c20_i584 + 1) {
    c20_b_g67_0[c20_i584] = c20_g67_0[c20_i584];
  }

  for (c20_i585 = 0; c20_i585 < 16; c20_i585 = c20_i585 + 1) {
    c20_dv98[c20_i585] = c20_dv41[c20_i585];
  }

  c20_mldivide(chartInstance, c20_b_g67_0, c20_dv98, c20_dv99);
  for (c20_i586 = 0; c20_i586 < 16; c20_i586 = c20_i586 + 1) {
    c20_dv100[c20_i586] = c20_dv99[c20_i586];
  }

  c20_Adj(chartInstance, c20_dv100, c20_dv101);
  for (c20_i587 = 0; c20_i587 < 36; c20_i587 = c20_i587 + 1) {
    c20_Adinvg67[c20_i587] = c20_dv101[c20_i587];
  }

  /*  Joint 6 */
  _SFD_SCRIPT_CALL(0, 147);
  c20_i588 = 0;
  for (c20_i589 = 0; c20_i589 < 6; c20_i589 = c20_i589 + 1) {
    c20_i590 = 0;
    for (c20_i591 = 0; c20_i591 < 6; c20_i591 = c20_i591 + 1) {
      c20_ad_a[c20_i591 + c20_i588] = c20_Adinvg67[c20_i590 + c20_i589];
      c20_i590 = c20_i590 + 6;
    }

    c20_i588 = c20_i588 + 6;
  }

  for (c20_i592 = 0; c20_i592 < 6; c20_i592 = c20_i592 + 1) {
    c20_md_b[c20_i592] = c20_F7[c20_i592];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i593 = 0; c20_i593 < 36; c20_i593 = c20_i593 + 1) {
    c20_bd_a[c20_i593] = c20_ad_a[c20_i593];
  }

  for (c20_i594 = 0; c20_i594 < 6; c20_i594 = c20_i594 + 1) {
    c20_nd_b[c20_i594] = c20_md_b[c20_i594];
  }

  for (c20_i595 = 0; c20_i595 < 6; c20_i595 = c20_i595 + 1) {
    c20_dv102[c20_i595] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_bd_a, c20_nd_b, c20_dv102, c20_mc_y);
  for (c20_i596 = 0; c20_i596 < 36; c20_i596 = c20_i596 + 1) {
    c20_cd_a[c20_i596] = c20_M6[c20_i596];
  }

  for (c20_i597 = 0; c20_i597 < 6; c20_i597 = c20_i597 + 1) {
    c20_od_b[c20_i597] = c20_dV6[c20_i597];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i598 = 0; c20_i598 < 36; c20_i598 = c20_i598 + 1) {
    c20_dd_a[c20_i598] = c20_cd_a[c20_i598];
  }

  for (c20_i599 = 0; c20_i599 < 6; c20_i599 = c20_i599 + 1) {
    c20_pd_b[c20_i599] = c20_od_b[c20_i599];
  }

  for (c20_i600 = 0; c20_i600 < 6; c20_i600 = c20_i600 + 1) {
    c20_dv103[c20_i600] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_dd_a, c20_pd_b, c20_dv103, c20_nc_y);
  for (c20_i601 = 0; c20_i601 < 6; c20_i601 = c20_i601 + 1) {
    c20_b_V6[c20_i601] = c20_V6[c20_i601];
  }

  c20_ad(chartInstance, c20_b_V6, c20_dv104);
  c20_i602 = 0;
  for (c20_i603 = 0; c20_i603 < 6; c20_i603 = c20_i603 + 1) {
    c20_i604 = 0;
    for (c20_i605 = 0; c20_i605 < 6; c20_i605 = c20_i605 + 1) {
      c20_ed_a[c20_i605 + c20_i602] = c20_dv104[c20_i604 + c20_i603];
      c20_i604 = c20_i604 + 6;
    }

    c20_i602 = c20_i602 + 6;
  }

  for (c20_i606 = 0; c20_i606 < 36; c20_i606 = c20_i606 + 1) {
    c20_qd_b[c20_i606] = c20_M6[c20_i606];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i607 = 0; c20_i607 < 36; c20_i607 = c20_i607 + 1) {
    c20_gd_A[c20_i607] = c20_ed_a[c20_i607];
  }

  for (c20_i608 = 0; c20_i608 < 36; c20_i608 = c20_i608 + 1) {
    c20_gd_B[c20_i608] = c20_qd_b[c20_i608];
  }

  for (c20_i609 = 0; c20_i609 < 36; c20_i609 = c20_i609 + 1) {
    c20_hd_A[c20_i609] = c20_gd_A[c20_i609];
  }

  for (c20_i610 = 0; c20_i610 < 36; c20_i610 = c20_i610 + 1) {
    c20_hd_B[c20_i610] = c20_gd_B[c20_i610];
  }

  for (c20_i611 = 0; c20_i611 < 36; c20_i611 = c20_i611 + 1) {
    c20_id_A[c20_i611] = c20_hd_A[c20_i611];
  }

  for (c20_i612 = 0; c20_i612 < 36; c20_i612 = c20_i612 + 1) {
    c20_id_B[c20_i612] = c20_hd_B[c20_i612];
  }

  for (c20_i613 = 0; c20_i613 < 36; c20_i613 = c20_i613 + 1) {
    c20_dv105[c20_i613] = 0.0;
  }

  c20_ceval_xgemm(chartInstance, 6, 6, 6, 1.0, c20_id_A, 1, 6, c20_id_B, 1, 6,
                  0.0, c20_dv105, 1, 6, c20_oc_y);
  for (c20_i614 = 0; c20_i614 < 36; c20_i614 = c20_i614 + 1) {
    c20_fd_a[c20_i614] = c20_oc_y[c20_i614];
  }

  for (c20_i615 = 0; c20_i615 < 6; c20_i615 = c20_i615 + 1) {
    c20_rd_b[c20_i615] = c20_V6[c20_i615];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i616 = 0; c20_i616 < 36; c20_i616 = c20_i616 + 1) {
    c20_gd_a[c20_i616] = c20_fd_a[c20_i616];
  }

  for (c20_i617 = 0; c20_i617 < 6; c20_i617 = c20_i617 + 1) {
    c20_sd_b[c20_i617] = c20_rd_b[c20_i617];
  }

  for (c20_i618 = 0; c20_i618 < 6; c20_i618 = c20_i618 + 1) {
    c20_dv106[c20_i618] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_gd_a, c20_sd_b, c20_dv106, c20_pc_y);
  for (c20_i619 = 0; c20_i619 < 6; c20_i619 = c20_i619 + 1) {
    c20_F6[c20_i619] = (c20_mc_y[c20_i619] + c20_nc_y[c20_i619]) -
      c20_pc_y[c20_i619];
  }

  _SFD_SCRIPT_CALL(0, 148);
  for (c20_i620 = 0; c20_i620 < 6; c20_i620 = c20_i620 + 1) {
    c20_td_b[c20_i620] = c20_F6[c20_i620];
  }

  c20_i_eml_scalar_eg(chartInstance);
  for (c20_i621 = 0; c20_i621 < 6; c20_i621 = c20_i621 + 1) {
    c20_qc_y[c20_i621] = c20_td_b[c20_i621];
  }

  for (c20_i622 = 0; c20_i622 < 6; c20_i622 = c20_i622 + 1) {
    c20_rc_y[c20_i622] = c20_qc_y[c20_i622];
  }

  for (c20_i623 = 0; c20_i623 < 6; c20_i623 = c20_i623 + 1) {
    c20_sc_y[c20_i623] = c20_rc_y[c20_i623];
  }

  for (c20_i624 = 0; c20_i624 < 6; c20_i624 = c20_i624 + 1) {
    c20_dv107[c20_i624] = c20_dv6[c20_i624];
  }

  for (c20_i625 = 0; c20_i625 < 6; c20_i625 = c20_i625 + 1) {
    c20_tc_y[c20_i625] = c20_sc_y[c20_i625];
  }

  c20_uc_y = c20_ceval_xdot(chartInstance, 6, c20_dv107, 1, 1, c20_tc_y, 1, 1);
  c20_Tau[5] = c20_uc_y;

  /*  Joint 5 */
  _SFD_SCRIPT_CALL(0, 151);
  c20_i626 = 0;
  for (c20_i627 = 0; c20_i627 < 6; c20_i627 = c20_i627 + 1) {
    c20_i628 = 0;
    for (c20_i629 = 0; c20_i629 < 6; c20_i629 = c20_i629 + 1) {
      c20_hd_a[c20_i629 + c20_i626] = c20_Adinvg56[c20_i628 + c20_i627];
      c20_i628 = c20_i628 + 6;
    }

    c20_i626 = c20_i626 + 6;
  }

  for (c20_i630 = 0; c20_i630 < 6; c20_i630 = c20_i630 + 1) {
    c20_ud_b[c20_i630] = c20_F6[c20_i630];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i631 = 0; c20_i631 < 36; c20_i631 = c20_i631 + 1) {
    c20_id_a[c20_i631] = c20_hd_a[c20_i631];
  }

  for (c20_i632 = 0; c20_i632 < 6; c20_i632 = c20_i632 + 1) {
    c20_vd_b[c20_i632] = c20_ud_b[c20_i632];
  }

  for (c20_i633 = 0; c20_i633 < 6; c20_i633 = c20_i633 + 1) {
    c20_dv108[c20_i633] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_id_a, c20_vd_b, c20_dv108, c20_vc_y);
  for (c20_i634 = 0; c20_i634 < 36; c20_i634 = c20_i634 + 1) {
    c20_jd_a[c20_i634] = c20_M5[c20_i634];
  }

  for (c20_i635 = 0; c20_i635 < 6; c20_i635 = c20_i635 + 1) {
    c20_wd_b[c20_i635] = c20_dV5[c20_i635];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i636 = 0; c20_i636 < 36; c20_i636 = c20_i636 + 1) {
    c20_kd_a[c20_i636] = c20_jd_a[c20_i636];
  }

  for (c20_i637 = 0; c20_i637 < 6; c20_i637 = c20_i637 + 1) {
    c20_xd_b[c20_i637] = c20_wd_b[c20_i637];
  }

  for (c20_i638 = 0; c20_i638 < 6; c20_i638 = c20_i638 + 1) {
    c20_dv109[c20_i638] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_kd_a, c20_xd_b, c20_dv109, c20_wc_y);
  for (c20_i639 = 0; c20_i639 < 6; c20_i639 = c20_i639 + 1) {
    c20_b_V5[c20_i639] = c20_V5[c20_i639];
  }

  c20_ad(chartInstance, c20_b_V5, c20_dv110);
  c20_i640 = 0;
  for (c20_i641 = 0; c20_i641 < 6; c20_i641 = c20_i641 + 1) {
    c20_i642 = 0;
    for (c20_i643 = 0; c20_i643 < 6; c20_i643 = c20_i643 + 1) {
      c20_ld_a[c20_i643 + c20_i640] = c20_dv110[c20_i642 + c20_i641];
      c20_i642 = c20_i642 + 6;
    }

    c20_i640 = c20_i640 + 6;
  }

  for (c20_i644 = 0; c20_i644 < 36; c20_i644 = c20_i644 + 1) {
    c20_yd_b[c20_i644] = c20_M5[c20_i644];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i645 = 0; c20_i645 < 36; c20_i645 = c20_i645 + 1) {
    c20_jd_A[c20_i645] = c20_ld_a[c20_i645];
  }

  for (c20_i646 = 0; c20_i646 < 36; c20_i646 = c20_i646 + 1) {
    c20_jd_B[c20_i646] = c20_yd_b[c20_i646];
  }

  for (c20_i647 = 0; c20_i647 < 36; c20_i647 = c20_i647 + 1) {
    c20_kd_A[c20_i647] = c20_jd_A[c20_i647];
  }

  for (c20_i648 = 0; c20_i648 < 36; c20_i648 = c20_i648 + 1) {
    c20_kd_B[c20_i648] = c20_jd_B[c20_i648];
  }

  for (c20_i649 = 0; c20_i649 < 36; c20_i649 = c20_i649 + 1) {
    c20_ld_A[c20_i649] = c20_kd_A[c20_i649];
  }

  for (c20_i650 = 0; c20_i650 < 36; c20_i650 = c20_i650 + 1) {
    c20_ld_B[c20_i650] = c20_kd_B[c20_i650];
  }

  for (c20_i651 = 0; c20_i651 < 36; c20_i651 = c20_i651 + 1) {
    c20_dv111[c20_i651] = 0.0;
  }

  c20_ceval_xgemm(chartInstance, 6, 6, 6, 1.0, c20_ld_A, 1, 6, c20_ld_B, 1, 6,
                  0.0, c20_dv111, 1, 6, c20_xc_y);
  for (c20_i652 = 0; c20_i652 < 36; c20_i652 = c20_i652 + 1) {
    c20_md_a[c20_i652] = c20_xc_y[c20_i652];
  }

  for (c20_i653 = 0; c20_i653 < 6; c20_i653 = c20_i653 + 1) {
    c20_ae_b[c20_i653] = c20_V5[c20_i653];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i654 = 0; c20_i654 < 36; c20_i654 = c20_i654 + 1) {
    c20_nd_a[c20_i654] = c20_md_a[c20_i654];
  }

  for (c20_i655 = 0; c20_i655 < 6; c20_i655 = c20_i655 + 1) {
    c20_be_b[c20_i655] = c20_ae_b[c20_i655];
  }

  for (c20_i656 = 0; c20_i656 < 6; c20_i656 = c20_i656 + 1) {
    c20_dv112[c20_i656] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_nd_a, c20_be_b, c20_dv112, c20_yc_y);
  for (c20_i657 = 0; c20_i657 < 6; c20_i657 = c20_i657 + 1) {
    c20_F5[c20_i657] = (c20_vc_y[c20_i657] + c20_wc_y[c20_i657]) -
      c20_yc_y[c20_i657];
  }

  _SFD_SCRIPT_CALL(0, 152);
  for (c20_i658 = 0; c20_i658 < 6; c20_i658 = c20_i658 + 1) {
    c20_ce_b[c20_i658] = c20_F5[c20_i658];
  }

  c20_i_eml_scalar_eg(chartInstance);
  for (c20_i659 = 0; c20_i659 < 6; c20_i659 = c20_i659 + 1) {
    c20_ad_y[c20_i659] = c20_ce_b[c20_i659];
  }

  for (c20_i660 = 0; c20_i660 < 6; c20_i660 = c20_i660 + 1) {
    c20_bd_y[c20_i660] = c20_ad_y[c20_i660];
  }

  for (c20_i661 = 0; c20_i661 < 6; c20_i661 = c20_i661 + 1) {
    c20_cd_y[c20_i661] = c20_bd_y[c20_i661];
  }

  for (c20_i662 = 0; c20_i662 < 6; c20_i662 = c20_i662 + 1) {
    c20_dv113[c20_i662] = c20_dv6[c20_i662];
  }

  for (c20_i663 = 0; c20_i663 < 6; c20_i663 = c20_i663 + 1) {
    c20_dd_y[c20_i663] = c20_cd_y[c20_i663];
  }

  c20_ed_y = c20_ceval_xdot(chartInstance, 6, c20_dv113, 1, 1, c20_dd_y, 1, 1);
  c20_Tau[4] = c20_ed_y;

  /*  Joint 4 */
  _SFD_SCRIPT_CALL(0, 155);
  c20_i664 = 0;
  for (c20_i665 = 0; c20_i665 < 6; c20_i665 = c20_i665 + 1) {
    c20_i666 = 0;
    for (c20_i667 = 0; c20_i667 < 6; c20_i667 = c20_i667 + 1) {
      c20_od_a[c20_i667 + c20_i664] = c20_Adinvg45[c20_i666 + c20_i665];
      c20_i666 = c20_i666 + 6;
    }

    c20_i664 = c20_i664 + 6;
  }

  for (c20_i668 = 0; c20_i668 < 6; c20_i668 = c20_i668 + 1) {
    c20_de_b[c20_i668] = c20_F5[c20_i668];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i669 = 0; c20_i669 < 36; c20_i669 = c20_i669 + 1) {
    c20_pd_a[c20_i669] = c20_od_a[c20_i669];
  }

  for (c20_i670 = 0; c20_i670 < 6; c20_i670 = c20_i670 + 1) {
    c20_ee_b[c20_i670] = c20_de_b[c20_i670];
  }

  for (c20_i671 = 0; c20_i671 < 6; c20_i671 = c20_i671 + 1) {
    c20_dv114[c20_i671] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_pd_a, c20_ee_b, c20_dv114, c20_fd_y);
  for (c20_i672 = 0; c20_i672 < 36; c20_i672 = c20_i672 + 1) {
    c20_qd_a[c20_i672] = c20_M4[c20_i672];
  }

  for (c20_i673 = 0; c20_i673 < 6; c20_i673 = c20_i673 + 1) {
    c20_fe_b[c20_i673] = c20_dV4[c20_i673];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i674 = 0; c20_i674 < 36; c20_i674 = c20_i674 + 1) {
    c20_rd_a[c20_i674] = c20_qd_a[c20_i674];
  }

  for (c20_i675 = 0; c20_i675 < 6; c20_i675 = c20_i675 + 1) {
    c20_ge_b[c20_i675] = c20_fe_b[c20_i675];
  }

  for (c20_i676 = 0; c20_i676 < 6; c20_i676 = c20_i676 + 1) {
    c20_dv115[c20_i676] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_rd_a, c20_ge_b, c20_dv115, c20_gd_y);
  for (c20_i677 = 0; c20_i677 < 6; c20_i677 = c20_i677 + 1) {
    c20_b_V4[c20_i677] = c20_V4[c20_i677];
  }

  c20_ad(chartInstance, c20_b_V4, c20_dv116);
  c20_i678 = 0;
  for (c20_i679 = 0; c20_i679 < 6; c20_i679 = c20_i679 + 1) {
    c20_i680 = 0;
    for (c20_i681 = 0; c20_i681 < 6; c20_i681 = c20_i681 + 1) {
      c20_sd_a[c20_i681 + c20_i678] = c20_dv116[c20_i680 + c20_i679];
      c20_i680 = c20_i680 + 6;
    }

    c20_i678 = c20_i678 + 6;
  }

  for (c20_i682 = 0; c20_i682 < 36; c20_i682 = c20_i682 + 1) {
    c20_he_b[c20_i682] = c20_M4[c20_i682];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i683 = 0; c20_i683 < 36; c20_i683 = c20_i683 + 1) {
    c20_md_A[c20_i683] = c20_sd_a[c20_i683];
  }

  for (c20_i684 = 0; c20_i684 < 36; c20_i684 = c20_i684 + 1) {
    c20_md_B[c20_i684] = c20_he_b[c20_i684];
  }

  for (c20_i685 = 0; c20_i685 < 36; c20_i685 = c20_i685 + 1) {
    c20_nd_A[c20_i685] = c20_md_A[c20_i685];
  }

  for (c20_i686 = 0; c20_i686 < 36; c20_i686 = c20_i686 + 1) {
    c20_nd_B[c20_i686] = c20_md_B[c20_i686];
  }

  for (c20_i687 = 0; c20_i687 < 36; c20_i687 = c20_i687 + 1) {
    c20_od_A[c20_i687] = c20_nd_A[c20_i687];
  }

  for (c20_i688 = 0; c20_i688 < 36; c20_i688 = c20_i688 + 1) {
    c20_od_B[c20_i688] = c20_nd_B[c20_i688];
  }

  for (c20_i689 = 0; c20_i689 < 36; c20_i689 = c20_i689 + 1) {
    c20_dv117[c20_i689] = 0.0;
  }

  c20_ceval_xgemm(chartInstance, 6, 6, 6, 1.0, c20_od_A, 1, 6, c20_od_B, 1, 6,
                  0.0, c20_dv117, 1, 6, c20_hd_y);
  for (c20_i690 = 0; c20_i690 < 36; c20_i690 = c20_i690 + 1) {
    c20_td_a[c20_i690] = c20_hd_y[c20_i690];
  }

  for (c20_i691 = 0; c20_i691 < 6; c20_i691 = c20_i691 + 1) {
    c20_ie_b[c20_i691] = c20_V4[c20_i691];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i692 = 0; c20_i692 < 36; c20_i692 = c20_i692 + 1) {
    c20_ud_a[c20_i692] = c20_td_a[c20_i692];
  }

  for (c20_i693 = 0; c20_i693 < 6; c20_i693 = c20_i693 + 1) {
    c20_je_b[c20_i693] = c20_ie_b[c20_i693];
  }

  for (c20_i694 = 0; c20_i694 < 6; c20_i694 = c20_i694 + 1) {
    c20_dv118[c20_i694] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ud_a, c20_je_b, c20_dv118, c20_id_y);
  for (c20_i695 = 0; c20_i695 < 6; c20_i695 = c20_i695 + 1) {
    c20_F4[c20_i695] = (c20_fd_y[c20_i695] + c20_gd_y[c20_i695]) -
      c20_id_y[c20_i695];
  }

  _SFD_SCRIPT_CALL(0, 156);
  for (c20_i696 = 0; c20_i696 < 6; c20_i696 = c20_i696 + 1) {
    c20_ke_b[c20_i696] = c20_F4[c20_i696];
  }

  c20_i_eml_scalar_eg(chartInstance);
  for (c20_i697 = 0; c20_i697 < 6; c20_i697 = c20_i697 + 1) {
    c20_jd_y[c20_i697] = c20_ke_b[c20_i697];
  }

  for (c20_i698 = 0; c20_i698 < 6; c20_i698 = c20_i698 + 1) {
    c20_kd_y[c20_i698] = c20_jd_y[c20_i698];
  }

  for (c20_i699 = 0; c20_i699 < 6; c20_i699 = c20_i699 + 1) {
    c20_ld_y[c20_i699] = c20_kd_y[c20_i699];
  }

  for (c20_i700 = 0; c20_i700 < 6; c20_i700 = c20_i700 + 1) {
    c20_dv119[c20_i700] = c20_dv6[c20_i700];
  }

  for (c20_i701 = 0; c20_i701 < 6; c20_i701 = c20_i701 + 1) {
    c20_md_y[c20_i701] = c20_ld_y[c20_i701];
  }

  c20_nd_y = c20_ceval_xdot(chartInstance, 6, c20_dv119, 1, 1, c20_md_y, 1, 1);
  c20_Tau[3] = c20_nd_y;

  /*  Joint 3 */
  _SFD_SCRIPT_CALL(0, 159);
  c20_i702 = 0;
  for (c20_i703 = 0; c20_i703 < 6; c20_i703 = c20_i703 + 1) {
    c20_i704 = 0;
    for (c20_i705 = 0; c20_i705 < 6; c20_i705 = c20_i705 + 1) {
      c20_vd_a[c20_i705 + c20_i702] = c20_Adinvg34[c20_i704 + c20_i703];
      c20_i704 = c20_i704 + 6;
    }

    c20_i702 = c20_i702 + 6;
  }

  for (c20_i706 = 0; c20_i706 < 6; c20_i706 = c20_i706 + 1) {
    c20_le_b[c20_i706] = c20_F4[c20_i706];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i707 = 0; c20_i707 < 36; c20_i707 = c20_i707 + 1) {
    c20_wd_a[c20_i707] = c20_vd_a[c20_i707];
  }

  for (c20_i708 = 0; c20_i708 < 6; c20_i708 = c20_i708 + 1) {
    c20_me_b[c20_i708] = c20_le_b[c20_i708];
  }

  for (c20_i709 = 0; c20_i709 < 6; c20_i709 = c20_i709 + 1) {
    c20_dv120[c20_i709] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_wd_a, c20_me_b, c20_dv120, c20_od_y);
  for (c20_i710 = 0; c20_i710 < 36; c20_i710 = c20_i710 + 1) {
    c20_xd_a[c20_i710] = c20_M3[c20_i710];
  }

  for (c20_i711 = 0; c20_i711 < 6; c20_i711 = c20_i711 + 1) {
    c20_ne_b[c20_i711] = c20_dV3[c20_i711];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i712 = 0; c20_i712 < 36; c20_i712 = c20_i712 + 1) {
    c20_yd_a[c20_i712] = c20_xd_a[c20_i712];
  }

  for (c20_i713 = 0; c20_i713 < 6; c20_i713 = c20_i713 + 1) {
    c20_oe_b[c20_i713] = c20_ne_b[c20_i713];
  }

  for (c20_i714 = 0; c20_i714 < 6; c20_i714 = c20_i714 + 1) {
    c20_dv121[c20_i714] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_yd_a, c20_oe_b, c20_dv121, c20_pd_y);
  for (c20_i715 = 0; c20_i715 < 6; c20_i715 = c20_i715 + 1) {
    c20_b_V3[c20_i715] = c20_V3[c20_i715];
  }

  c20_ad(chartInstance, c20_b_V3, c20_dv122);
  c20_i716 = 0;
  for (c20_i717 = 0; c20_i717 < 6; c20_i717 = c20_i717 + 1) {
    c20_i718 = 0;
    for (c20_i719 = 0; c20_i719 < 6; c20_i719 = c20_i719 + 1) {
      c20_ae_a[c20_i719 + c20_i716] = c20_dv122[c20_i718 + c20_i717];
      c20_i718 = c20_i718 + 6;
    }

    c20_i716 = c20_i716 + 6;
  }

  for (c20_i720 = 0; c20_i720 < 36; c20_i720 = c20_i720 + 1) {
    c20_pe_b[c20_i720] = c20_M3[c20_i720];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i721 = 0; c20_i721 < 36; c20_i721 = c20_i721 + 1) {
    c20_pd_A[c20_i721] = c20_ae_a[c20_i721];
  }

  for (c20_i722 = 0; c20_i722 < 36; c20_i722 = c20_i722 + 1) {
    c20_pd_B[c20_i722] = c20_pe_b[c20_i722];
  }

  for (c20_i723 = 0; c20_i723 < 36; c20_i723 = c20_i723 + 1) {
    c20_qd_A[c20_i723] = c20_pd_A[c20_i723];
  }

  for (c20_i724 = 0; c20_i724 < 36; c20_i724 = c20_i724 + 1) {
    c20_qd_B[c20_i724] = c20_pd_B[c20_i724];
  }

  for (c20_i725 = 0; c20_i725 < 36; c20_i725 = c20_i725 + 1) {
    c20_rd_A[c20_i725] = c20_qd_A[c20_i725];
  }

  for (c20_i726 = 0; c20_i726 < 36; c20_i726 = c20_i726 + 1) {
    c20_rd_B[c20_i726] = c20_qd_B[c20_i726];
  }

  for (c20_i727 = 0; c20_i727 < 36; c20_i727 = c20_i727 + 1) {
    c20_dv123[c20_i727] = 0.0;
  }

  c20_ceval_xgemm(chartInstance, 6, 6, 6, 1.0, c20_rd_A, 1, 6, c20_rd_B, 1, 6,
                  0.0, c20_dv123, 1, 6, c20_qd_y);
  for (c20_i728 = 0; c20_i728 < 36; c20_i728 = c20_i728 + 1) {
    c20_be_a[c20_i728] = c20_qd_y[c20_i728];
  }

  for (c20_i729 = 0; c20_i729 < 6; c20_i729 = c20_i729 + 1) {
    c20_qe_b[c20_i729] = c20_V3[c20_i729];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i730 = 0; c20_i730 < 36; c20_i730 = c20_i730 + 1) {
    c20_ce_a[c20_i730] = c20_be_a[c20_i730];
  }

  for (c20_i731 = 0; c20_i731 < 6; c20_i731 = c20_i731 + 1) {
    c20_re_b[c20_i731] = c20_qe_b[c20_i731];
  }

  for (c20_i732 = 0; c20_i732 < 6; c20_i732 = c20_i732 + 1) {
    c20_dv124[c20_i732] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ce_a, c20_re_b, c20_dv124, c20_rd_y);
  for (c20_i733 = 0; c20_i733 < 6; c20_i733 = c20_i733 + 1) {
    c20_F3[c20_i733] = (c20_od_y[c20_i733] + c20_pd_y[c20_i733]) -
      c20_rd_y[c20_i733];
  }

  _SFD_SCRIPT_CALL(0, 160);
  for (c20_i734 = 0; c20_i734 < 6; c20_i734 = c20_i734 + 1) {
    c20_se_b[c20_i734] = c20_F3[c20_i734];
  }

  c20_i_eml_scalar_eg(chartInstance);
  for (c20_i735 = 0; c20_i735 < 6; c20_i735 = c20_i735 + 1) {
    c20_sd_y[c20_i735] = c20_se_b[c20_i735];
  }

  for (c20_i736 = 0; c20_i736 < 6; c20_i736 = c20_i736 + 1) {
    c20_td_y[c20_i736] = c20_sd_y[c20_i736];
  }

  for (c20_i737 = 0; c20_i737 < 6; c20_i737 = c20_i737 + 1) {
    c20_ud_y[c20_i737] = c20_td_y[c20_i737];
  }

  for (c20_i738 = 0; c20_i738 < 6; c20_i738 = c20_i738 + 1) {
    c20_dv125[c20_i738] = c20_dv6[c20_i738];
  }

  for (c20_i739 = 0; c20_i739 < 6; c20_i739 = c20_i739 + 1) {
    c20_vd_y[c20_i739] = c20_ud_y[c20_i739];
  }

  c20_wd_y = c20_ceval_xdot(chartInstance, 6, c20_dv125, 1, 1, c20_vd_y, 1, 1);
  c20_Tau[2] = c20_wd_y;

  /*  Joint 2 */
  _SFD_SCRIPT_CALL(0, 163);
  c20_i740 = 0;
  for (c20_i741 = 0; c20_i741 < 6; c20_i741 = c20_i741 + 1) {
    c20_i742 = 0;
    for (c20_i743 = 0; c20_i743 < 6; c20_i743 = c20_i743 + 1) {
      c20_de_a[c20_i743 + c20_i740] = c20_Adinvg23[c20_i742 + c20_i741];
      c20_i742 = c20_i742 + 6;
    }

    c20_i740 = c20_i740 + 6;
  }

  for (c20_i744 = 0; c20_i744 < 6; c20_i744 = c20_i744 + 1) {
    c20_te_b[c20_i744] = c20_F3[c20_i744];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i745 = 0; c20_i745 < 36; c20_i745 = c20_i745 + 1) {
    c20_ee_a[c20_i745] = c20_de_a[c20_i745];
  }

  for (c20_i746 = 0; c20_i746 < 6; c20_i746 = c20_i746 + 1) {
    c20_ue_b[c20_i746] = c20_te_b[c20_i746];
  }

  for (c20_i747 = 0; c20_i747 < 6; c20_i747 = c20_i747 + 1) {
    c20_dv126[c20_i747] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ee_a, c20_ue_b, c20_dv126, c20_xd_y);
  for (c20_i748 = 0; c20_i748 < 36; c20_i748 = c20_i748 + 1) {
    c20_fe_a[c20_i748] = c20_M2[c20_i748];
  }

  for (c20_i749 = 0; c20_i749 < 6; c20_i749 = c20_i749 + 1) {
    c20_ve_b[c20_i749] = c20_dV2[c20_i749];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i750 = 0; c20_i750 < 36; c20_i750 = c20_i750 + 1) {
    c20_ge_a[c20_i750] = c20_fe_a[c20_i750];
  }

  for (c20_i751 = 0; c20_i751 < 6; c20_i751 = c20_i751 + 1) {
    c20_we_b[c20_i751] = c20_ve_b[c20_i751];
  }

  for (c20_i752 = 0; c20_i752 < 6; c20_i752 = c20_i752 + 1) {
    c20_dv127[c20_i752] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ge_a, c20_we_b, c20_dv127, c20_yd_y);
  for (c20_i753 = 0; c20_i753 < 6; c20_i753 = c20_i753 + 1) {
    c20_b_V2[c20_i753] = c20_V2[c20_i753];
  }

  c20_ad(chartInstance, c20_b_V2, c20_dv128);
  c20_i754 = 0;
  for (c20_i755 = 0; c20_i755 < 6; c20_i755 = c20_i755 + 1) {
    c20_i756 = 0;
    for (c20_i757 = 0; c20_i757 < 6; c20_i757 = c20_i757 + 1) {
      c20_he_a[c20_i757 + c20_i754] = c20_dv128[c20_i756 + c20_i755];
      c20_i756 = c20_i756 + 6;
    }

    c20_i754 = c20_i754 + 6;
  }

  for (c20_i758 = 0; c20_i758 < 36; c20_i758 = c20_i758 + 1) {
    c20_xe_b[c20_i758] = c20_M2[c20_i758];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i759 = 0; c20_i759 < 36; c20_i759 = c20_i759 + 1) {
    c20_sd_A[c20_i759] = c20_he_a[c20_i759];
  }

  for (c20_i760 = 0; c20_i760 < 36; c20_i760 = c20_i760 + 1) {
    c20_sd_B[c20_i760] = c20_xe_b[c20_i760];
  }

  for (c20_i761 = 0; c20_i761 < 36; c20_i761 = c20_i761 + 1) {
    c20_td_A[c20_i761] = c20_sd_A[c20_i761];
  }

  for (c20_i762 = 0; c20_i762 < 36; c20_i762 = c20_i762 + 1) {
    c20_td_B[c20_i762] = c20_sd_B[c20_i762];
  }

  for (c20_i763 = 0; c20_i763 < 36; c20_i763 = c20_i763 + 1) {
    c20_ud_A[c20_i763] = c20_td_A[c20_i763];
  }

  for (c20_i764 = 0; c20_i764 < 36; c20_i764 = c20_i764 + 1) {
    c20_ud_B[c20_i764] = c20_td_B[c20_i764];
  }

  for (c20_i765 = 0; c20_i765 < 36; c20_i765 = c20_i765 + 1) {
    c20_dv129[c20_i765] = 0.0;
  }

  c20_ceval_xgemm(chartInstance, 6, 6, 6, 1.0, c20_ud_A, 1, 6, c20_ud_B, 1, 6,
                  0.0, c20_dv129, 1, 6, c20_ae_y);
  for (c20_i766 = 0; c20_i766 < 36; c20_i766 = c20_i766 + 1) {
    c20_ie_a[c20_i766] = c20_ae_y[c20_i766];
  }

  for (c20_i767 = 0; c20_i767 < 6; c20_i767 = c20_i767 + 1) {
    c20_ye_b[c20_i767] = c20_V2[c20_i767];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i768 = 0; c20_i768 < 36; c20_i768 = c20_i768 + 1) {
    c20_je_a[c20_i768] = c20_ie_a[c20_i768];
  }

  for (c20_i769 = 0; c20_i769 < 6; c20_i769 = c20_i769 + 1) {
    c20_af_b[c20_i769] = c20_ye_b[c20_i769];
  }

  for (c20_i770 = 0; c20_i770 < 6; c20_i770 = c20_i770 + 1) {
    c20_dv130[c20_i770] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_je_a, c20_af_b, c20_dv130, c20_be_y);
  for (c20_i771 = 0; c20_i771 < 6; c20_i771 = c20_i771 + 1) {
    c20_F2[c20_i771] = (c20_xd_y[c20_i771] + c20_yd_y[c20_i771]) -
      c20_be_y[c20_i771];
  }

  _SFD_SCRIPT_CALL(0, 164);
  for (c20_i772 = 0; c20_i772 < 6; c20_i772 = c20_i772 + 1) {
    c20_bf_b[c20_i772] = c20_F2[c20_i772];
  }

  c20_i_eml_scalar_eg(chartInstance);
  for (c20_i773 = 0; c20_i773 < 6; c20_i773 = c20_i773 + 1) {
    c20_ce_y[c20_i773] = c20_bf_b[c20_i773];
  }

  for (c20_i774 = 0; c20_i774 < 6; c20_i774 = c20_i774 + 1) {
    c20_de_y[c20_i774] = c20_ce_y[c20_i774];
  }

  for (c20_i775 = 0; c20_i775 < 6; c20_i775 = c20_i775 + 1) {
    c20_ee_y[c20_i775] = c20_de_y[c20_i775];
  }

  for (c20_i776 = 0; c20_i776 < 6; c20_i776 = c20_i776 + 1) {
    c20_dv131[c20_i776] = c20_dv6[c20_i776];
  }

  for (c20_i777 = 0; c20_i777 < 6; c20_i777 = c20_i777 + 1) {
    c20_fe_y[c20_i777] = c20_ee_y[c20_i777];
  }

  c20_ge_y = c20_ceval_xdot(chartInstance, 6, c20_dv131, 1, 1, c20_fe_y, 1, 1);
  c20_Tau[1] = c20_ge_y;

  /*  Joint 1 */
  _SFD_SCRIPT_CALL(0, 167);
  c20_i778 = 0;
  for (c20_i779 = 0; c20_i779 < 6; c20_i779 = c20_i779 + 1) {
    c20_i780 = 0;
    for (c20_i781 = 0; c20_i781 < 6; c20_i781 = c20_i781 + 1) {
      c20_ke_a[c20_i781 + c20_i778] = c20_Adinvg12[c20_i780 + c20_i779];
      c20_i780 = c20_i780 + 6;
    }

    c20_i778 = c20_i778 + 6;
  }

  for (c20_i782 = 0; c20_i782 < 6; c20_i782 = c20_i782 + 1) {
    c20_cf_b[c20_i782] = c20_F2[c20_i782];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i783 = 0; c20_i783 < 36; c20_i783 = c20_i783 + 1) {
    c20_le_a[c20_i783] = c20_ke_a[c20_i783];
  }

  for (c20_i784 = 0; c20_i784 < 6; c20_i784 = c20_i784 + 1) {
    c20_df_b[c20_i784] = c20_cf_b[c20_i784];
  }

  for (c20_i785 = 0; c20_i785 < 6; c20_i785 = c20_i785 + 1) {
    c20_dv132[c20_i785] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_le_a, c20_df_b, c20_dv132, c20_he_y);
  for (c20_i786 = 0; c20_i786 < 36; c20_i786 = c20_i786 + 1) {
    c20_me_a[c20_i786] = c20_M1[c20_i786];
  }

  for (c20_i787 = 0; c20_i787 < 6; c20_i787 = c20_i787 + 1) {
    c20_ef_b[c20_i787] = c20_dV1[c20_i787];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i788 = 0; c20_i788 < 36; c20_i788 = c20_i788 + 1) {
    c20_ne_a[c20_i788] = c20_me_a[c20_i788];
  }

  for (c20_i789 = 0; c20_i789 < 6; c20_i789 = c20_i789 + 1) {
    c20_ff_b[c20_i789] = c20_ef_b[c20_i789];
  }

  for (c20_i790 = 0; c20_i790 < 6; c20_i790 = c20_i790 + 1) {
    c20_dv133[c20_i790] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_ne_a, c20_ff_b, c20_dv133, c20_ie_y);
  for (c20_i791 = 0; c20_i791 < 6; c20_i791 = c20_i791 + 1) {
    c20_b_V1[c20_i791] = c20_V1[c20_i791];
  }

  c20_ad(chartInstance, c20_b_V1, c20_dv134);
  c20_i792 = 0;
  for (c20_i793 = 0; c20_i793 < 6; c20_i793 = c20_i793 + 1) {
    c20_i794 = 0;
    for (c20_i795 = 0; c20_i795 < 6; c20_i795 = c20_i795 + 1) {
      c20_oe_a[c20_i795 + c20_i792] = c20_dv134[c20_i794 + c20_i793];
      c20_i794 = c20_i794 + 6;
    }

    c20_i792 = c20_i792 + 6;
  }

  for (c20_i796 = 0; c20_i796 < 36; c20_i796 = c20_i796 + 1) {
    c20_gf_b[c20_i796] = c20_M1[c20_i796];
  }

  c20_h_eml_scalar_eg(chartInstance);
  c20_h_eml_scalar_eg(chartInstance);
  for (c20_i797 = 0; c20_i797 < 36; c20_i797 = c20_i797 + 1) {
    c20_vd_A[c20_i797] = c20_oe_a[c20_i797];
  }

  for (c20_i798 = 0; c20_i798 < 36; c20_i798 = c20_i798 + 1) {
    c20_vd_B[c20_i798] = c20_gf_b[c20_i798];
  }

  for (c20_i799 = 0; c20_i799 < 36; c20_i799 = c20_i799 + 1) {
    c20_wd_A[c20_i799] = c20_vd_A[c20_i799];
  }

  for (c20_i800 = 0; c20_i800 < 36; c20_i800 = c20_i800 + 1) {
    c20_wd_B[c20_i800] = c20_vd_B[c20_i800];
  }

  for (c20_i801 = 0; c20_i801 < 36; c20_i801 = c20_i801 + 1) {
    c20_xd_A[c20_i801] = c20_wd_A[c20_i801];
  }

  for (c20_i802 = 0; c20_i802 < 36; c20_i802 = c20_i802 + 1) {
    c20_xd_B[c20_i802] = c20_wd_B[c20_i802];
  }

  for (c20_i803 = 0; c20_i803 < 36; c20_i803 = c20_i803 + 1) {
    c20_dv135[c20_i803] = 0.0;
  }

  c20_ceval_xgemm(chartInstance, 6, 6, 6, 1.0, c20_xd_A, 1, 6, c20_xd_B, 1, 6,
                  0.0, c20_dv135, 1, 6, c20_je_y);
  for (c20_i804 = 0; c20_i804 < 36; c20_i804 = c20_i804 + 1) {
    c20_pe_a[c20_i804] = c20_je_y[c20_i804];
  }

  for (c20_i805 = 0; c20_i805 < 6; c20_i805 = c20_i805 + 1) {
    c20_hf_b[c20_i805] = c20_V1[c20_i805];
  }

  c20_g_eml_scalar_eg(chartInstance);
  c20_g_eml_scalar_eg(chartInstance);
  for (c20_i806 = 0; c20_i806 < 36; c20_i806 = c20_i806 + 1) {
    c20_qe_a[c20_i806] = c20_pe_a[c20_i806];
  }

  for (c20_i807 = 0; c20_i807 < 6; c20_i807 = c20_i807 + 1) {
    c20_if_b[c20_i807] = c20_hf_b[c20_i807];
  }

  for (c20_i808 = 0; c20_i808 < 6; c20_i808 = c20_i808 + 1) {
    c20_dv136[c20_i808] = 0.0;
  }

  c20_eml_xgemm(chartInstance, c20_qe_a, c20_if_b, c20_dv136, c20_ke_y);
  for (c20_i809 = 0; c20_i809 < 6; c20_i809 = c20_i809 + 1) {
    c20_F1[c20_i809] = (c20_he_y[c20_i809] + c20_ie_y[c20_i809]) -
      c20_ke_y[c20_i809];
  }

  _SFD_SCRIPT_CALL(0, 168);
  for (c20_i810 = 0; c20_i810 < 6; c20_i810 = c20_i810 + 1) {
    c20_jf_b[c20_i810] = c20_F1[c20_i810];
  }

  c20_i_eml_scalar_eg(chartInstance);
  for (c20_i811 = 0; c20_i811 < 6; c20_i811 = c20_i811 + 1) {
    c20_le_y[c20_i811] = c20_jf_b[c20_i811];
  }

  for (c20_i812 = 0; c20_i812 < 6; c20_i812 = c20_i812 + 1) {
    c20_me_y[c20_i812] = c20_le_y[c20_i812];
  }

  for (c20_i813 = 0; c20_i813 < 6; c20_i813 = c20_i813 + 1) {
    c20_ne_y[c20_i813] = c20_me_y[c20_i813];
  }

  for (c20_i814 = 0; c20_i814 < 6; c20_i814 = c20_i814 + 1) {
    c20_dv137[c20_i814] = c20_dv6[c20_i814];
  }

  for (c20_i815 = 0; c20_i815 < 6; c20_i815 = c20_i815 + 1) {
    c20_oe_y[c20_i815] = c20_ne_y[c20_i815];
  }

  c20_pe_y = c20_ceval_xdot(chartInstance, 6, c20_dv137, 1, 1, c20_oe_y, 1, 1);
  c20_Tau[0] = c20_pe_y;
  _SFD_SCRIPT_CALL(0, 170);
  for (c20_i816 = 0; c20_i816 < 6; c20_i816 = c20_i816 + 1) {
    c20_Torque[c20_i816] = c20_Tau[c20_i816];
  }

  _SFD_SCRIPT_CALL(0, -170);
  sf_debug_symbol_scope_pop();
}

static void c20_expWre(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_kx[6], real_T c20_theta, real_T c20_g[
  16])
{
  uint32_T c20_debug_family_var_map[9];
  static const char *c20_sv1[9] = { "v", "w", "R", "p", "nargin", "nargout",
    "kx", "theta", "g" };

  real_T c20_v[3];
  real_T c20_w[3];
  real_T c20_R[9];
  real_T c20_p[3];
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i817;
  int32_T c20_i818;
  real_T c20_dv138[9];
  int32_T c20_i819;
  int32_T c20_i820;
  real_T c20_a[3];
  real_T c20_b;
  int32_T c20_i821;
  int32_T c20_i822;
  real_T c20_b_w[3];
  real_T c20_dv139[9];
  int32_T c20_i823;
  real_T c20_dv140[9];
  int32_T c20_i824;
  real_T c20_b_a[9];
  int32_T c20_i825;
  real_T c20_c_w[3];
  int32_T c20_i826;
  real_T c20_b_v[3];
  real_T c20_b_b[3];
  int32_T c20_i827;
  real_T c20_A[9];
  int32_T c20_i828;
  real_T c20_B[3];
  int32_T c20_i829;
  real_T c20_b_A[9];
  int32_T c20_i830;
  real_T c20_b_B[3];
  int32_T c20_i831;
  real_T c20_c_A[9];
  int32_T c20_i832;
  real_T c20_c_B[3];
  int32_T c20_i833;
  real_T c20_y[3];
  int32_T c20_i834;
  int32_T c20_i835;
  int32_T c20_i836;
  real_T c20_c_a[3];
  int32_T c20_i837;
  real_T c20_c_b[3];
  int32_T c20_i838;
  int32_T c20_i839;
  int32_T c20_i840;
  real_T c20_b_y[9];
  int32_T c20_i841;
  real_T c20_d_a[9];
  int32_T c20_i842;
  real_T c20_d_b[3];
  int32_T c20_i843;
  real_T c20_d_A[9];
  int32_T c20_i844;
  real_T c20_d_B[3];
  int32_T c20_i845;
  real_T c20_e_A[9];
  int32_T c20_i846;
  real_T c20_e_B[3];
  int32_T c20_i847;
  real_T c20_f_A[9];
  int32_T c20_i848;
  real_T c20_f_B[3];
  int32_T c20_i849;
  real_T c20_c_y[3];
  int32_T c20_i850;
  int32_T c20_i851;
  int32_T c20_i852;
  real_T c20_e_a[3];
  real_T c20_e_b;
  int32_T c20_i853;
  real_T c20_d_y[3];
  int32_T c20_i854;
  int32_T c20_i855;
  int32_T c20_i856;
  int32_T c20_i857;
  int32_T c20_i858;
  int32_T c20_i859;
  int32_T c20_i860;
  int32_T c20_i861;
  static real_T c20_dv141[4] = { 0.0, 0.0, 0.0, 1.0 };

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c20_sv1, c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c20_v, c20_f_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c20_w, c20_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_R, c20_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_p, c20_f_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c20_kx, c20_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c20_theta, c20_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c20_g, c20_g_sf_marshall, 8U);
  CV_SCRIPT_FCN(1, 0);

  /*  exponential of the wrench  */
  _SFD_SCRIPT_CALL(1, 5);
  CV_SCRIPT_IF(1, 0, c20_length(chartInstance) != 6.0);
  _SFD_SCRIPT_CALL(1, 9);
  for (c20_i817 = 0; c20_i817 < 3; c20_i817 = c20_i817 + 1) {
    c20_v[c20_i817] = c20_kx[c20_i817];
  }

  _SFD_SCRIPT_CALL(1, 10);
  for (c20_i818 = 0; c20_i818 < 3; c20_i818 = c20_i818 + 1) {
    c20_w[c20_i818] = c20_kx[c20_i818 + 3];
  }

  _SFD_SCRIPT_CALL(1, 12);
  if (CV_SCRIPT_COND(1, 0, c20_w[0] == 0.0)) {
    if (CV_SCRIPT_COND(1, 1, c20_w[1] == 0.0)) {
      if (CV_SCRIPT_COND(1, 2, c20_w[2] == 0.0)) {
        CV_SCRIPT_MCDC(1, 0, TRUE);
        CV_SCRIPT_IF(1, 1, TRUE);
        _SFD_SCRIPT_CALL(1, 13);
        c20_eye(chartInstance, c20_dv138);
        for (c20_i819 = 0; c20_i819 < 9; c20_i819 = c20_i819 + 1) {
          c20_R[c20_i819] = c20_dv138[c20_i819];
        }

        _SFD_SCRIPT_CALL(1, 14);
        for (c20_i820 = 0; c20_i820 < 3; c20_i820 = c20_i820 + 1) {
          c20_a[c20_i820] = c20_v[c20_i820];
        }

        c20_b = c20_theta;
        for (c20_i821 = 0; c20_i821 < 3; c20_i821 = c20_i821 + 1) {
          c20_p[c20_i821] = c20_a[c20_i821] * c20_b;
        }

        goto label_1;
      } else {
        goto label_2;
      }
    }
  }

 label_2:
  ;
  CV_SCRIPT_MCDC(1, 0, FALSE);
  CV_SCRIPT_IF(1, 1, FALSE);
  _SFD_SCRIPT_CALL(1, 16);
  for (c20_i822 = 0; c20_i822 < 3; c20_i822 = c20_i822 + 1) {
    c20_b_w[c20_i822] = c20_w[c20_i822];
  }

  c20_expRot(chartInstance, c20_b_w, c20_theta, c20_dv139);
  for (c20_i823 = 0; c20_i823 < 9; c20_i823 = c20_i823 + 1) {
    c20_R[c20_i823] = c20_dv139[c20_i823];
  }

  _SFD_SCRIPT_CALL(1, 17);
  c20_eye(chartInstance, c20_dv140);
  for (c20_i824 = 0; c20_i824 < 9; c20_i824 = c20_i824 + 1) {
    c20_b_a[c20_i824] = c20_dv140[c20_i824] - c20_R[c20_i824];
  }

  for (c20_i825 = 0; c20_i825 < 3; c20_i825 = c20_i825 + 1) {
    c20_c_w[c20_i825] = c20_w[c20_i825];
  }

  for (c20_i826 = 0; c20_i826 < 3; c20_i826 = c20_i826 + 1) {
    c20_b_v[c20_i826] = c20_v[c20_i826];
  }

  c20_cross(chartInstance, c20_c_w, c20_b_v, c20_b_b);
  c20_c_eml_scalar_eg(chartInstance);
  c20_c_eml_scalar_eg(chartInstance);
  for (c20_i827 = 0; c20_i827 < 9; c20_i827 = c20_i827 + 1) {
    c20_A[c20_i827] = c20_b_a[c20_i827];
  }

  for (c20_i828 = 0; c20_i828 < 3; c20_i828 = c20_i828 + 1) {
    c20_B[c20_i828] = c20_b_b[c20_i828];
  }

  for (c20_i829 = 0; c20_i829 < 9; c20_i829 = c20_i829 + 1) {
    c20_b_A[c20_i829] = c20_A[c20_i829];
  }

  for (c20_i830 = 0; c20_i830 < 3; c20_i830 = c20_i830 + 1) {
    c20_b_B[c20_i830] = c20_B[c20_i830];
  }

  for (c20_i831 = 0; c20_i831 < 9; c20_i831 = c20_i831 + 1) {
    c20_c_A[c20_i831] = c20_b_A[c20_i831];
  }

  for (c20_i832 = 0; c20_i832 < 3; c20_i832 = c20_i832 + 1) {
    c20_c_B[c20_i832] = c20_b_B[c20_i832];
  }

  for (c20_i833 = 0; c20_i833 < 3; c20_i833 = c20_i833 + 1) {
    c20_y[c20_i833] = 0.0;
    c20_i834 = 0;
    for (c20_i835 = 0; c20_i835 < 3; c20_i835 = c20_i835 + 1) {
      c20_y[c20_i833] = c20_y[c20_i833] + c20_c_A[c20_i834 + c20_i833] *
        c20_c_B[c20_i835];
      c20_i834 = c20_i834 + 3;
    }
  }

  for (c20_i836 = 0; c20_i836 < 3; c20_i836 = c20_i836 + 1) {
    c20_c_a[c20_i836] = c20_w[c20_i836];
  }

  for (c20_i837 = 0; c20_i837 < 3; c20_i837 = c20_i837 + 1) {
    c20_c_b[c20_i837] = c20_w[c20_i837];
  }

  c20_i838 = 0;
  for (c20_i839 = 0; c20_i839 < 3; c20_i839 = c20_i839 + 1) {
    for (c20_i840 = 0; c20_i840 < 3; c20_i840 = c20_i840 + 1) {
      c20_b_y[c20_i840 + c20_i838] = c20_c_a[c20_i840] * c20_c_b[c20_i839];
    }

    c20_i838 = c20_i838 + 3;
  }

  for (c20_i841 = 0; c20_i841 < 9; c20_i841 = c20_i841 + 1) {
    c20_d_a[c20_i841] = c20_b_y[c20_i841];
  }

  for (c20_i842 = 0; c20_i842 < 3; c20_i842 = c20_i842 + 1) {
    c20_d_b[c20_i842] = c20_v[c20_i842];
  }

  c20_c_eml_scalar_eg(chartInstance);
  c20_c_eml_scalar_eg(chartInstance);
  for (c20_i843 = 0; c20_i843 < 9; c20_i843 = c20_i843 + 1) {
    c20_d_A[c20_i843] = c20_d_a[c20_i843];
  }

  for (c20_i844 = 0; c20_i844 < 3; c20_i844 = c20_i844 + 1) {
    c20_d_B[c20_i844] = c20_d_b[c20_i844];
  }

  for (c20_i845 = 0; c20_i845 < 9; c20_i845 = c20_i845 + 1) {
    c20_e_A[c20_i845] = c20_d_A[c20_i845];
  }

  for (c20_i846 = 0; c20_i846 < 3; c20_i846 = c20_i846 + 1) {
    c20_e_B[c20_i846] = c20_d_B[c20_i846];
  }

  for (c20_i847 = 0; c20_i847 < 9; c20_i847 = c20_i847 + 1) {
    c20_f_A[c20_i847] = c20_e_A[c20_i847];
  }

  for (c20_i848 = 0; c20_i848 < 3; c20_i848 = c20_i848 + 1) {
    c20_f_B[c20_i848] = c20_e_B[c20_i848];
  }

  for (c20_i849 = 0; c20_i849 < 3; c20_i849 = c20_i849 + 1) {
    c20_c_y[c20_i849] = 0.0;
    c20_i850 = 0;
    for (c20_i851 = 0; c20_i851 < 3; c20_i851 = c20_i851 + 1) {
      c20_c_y[c20_i849] = c20_c_y[c20_i849] + c20_f_A[c20_i850 + c20_i849] *
        c20_f_B[c20_i851];
      c20_i850 = c20_i850 + 3;
    }
  }

  for (c20_i852 = 0; c20_i852 < 3; c20_i852 = c20_i852 + 1) {
    c20_e_a[c20_i852] = c20_c_y[c20_i852];
  }

  c20_e_b = c20_theta;
  for (c20_i853 = 0; c20_i853 < 3; c20_i853 = c20_i853 + 1) {
    c20_d_y[c20_i853] = c20_e_a[c20_i853] * c20_e_b;
  }

  for (c20_i854 = 0; c20_i854 < 3; c20_i854 = c20_i854 + 1) {
    c20_p[c20_i854] = c20_y[c20_i854] + c20_d_y[c20_i854];
  }

 label_1:
  ;
  _SFD_SCRIPT_CALL(1, 19);
  c20_i855 = 0;
  c20_i856 = 0;
  for (c20_i857 = 0; c20_i857 < 3; c20_i857 = c20_i857 + 1) {
    for (c20_i858 = 0; c20_i858 < 3; c20_i858 = c20_i858 + 1) {
      c20_g[c20_i858 + c20_i855] = c20_R[c20_i858 + c20_i856];
    }

    c20_i855 = c20_i855 + 4;
    c20_i856 = c20_i856 + 3;
  }

  for (c20_i859 = 0; c20_i859 < 3; c20_i859 = c20_i859 + 1) {
    c20_g[c20_i859 + 12] = c20_p[c20_i859];
  }

  c20_i860 = 0;
  for (c20_i861 = 0; c20_i861 < 4; c20_i861 = c20_i861 + 1) {
    c20_g[c20_i860 + 3] = c20_dv141[c20_i861];
    c20_i860 = c20_i860 + 4;
  }

  _SFD_SCRIPT_CALL(1, -19);
  sf_debug_symbol_scope_pop();
}

static real_T c20_length(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
  real_T c20_n;
  real_T c20_k;
  real_T c20_b_k;
  c20_n = 0.0;
  c20_k = 1.0;
 label_1:
  ;
  if (c20_k <= 2.0) {
    c20_b_k = c20_k;
    if (6.0 + -5.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c20_b_k), 1, 2, 1, 0) - 1) == 0.0) {
      return 0.0;
    } else {
      if (6.0 + -5.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c20_b_k), 1, 2, 1, 0) - 1) > c20_n) {
        c20_n = 6.0 + -5.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c20_b_k), 1, 2, 1, 0) - 1);
      }

      c20_k = c20_k + 1.0;
      goto label_1;
    }
  }

  return c20_n;
}

static void c20_isVariableSizing(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_eye(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                    real_T c20_I[9])
{
  int32_T c20_i862;
  int32_T c20_i;
  int32_T c20_b_i;
  c20_isVariableSizing(chartInstance);
  for (c20_i862 = 0; c20_i862 < 9; c20_i862 = c20_i862 + 1) {
    c20_I[c20_i862] = 0.0;
  }

  for (c20_i = 1; c20_i < 4; c20_i = c20_i + 1) {
    c20_b_i = c20_i;
    c20_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c20_b_i), 1, 3, 1, 0) - 1) + 3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c20_b_i), 1, 3, 2, 0) - 1)] = 1.0;
  }
}

static void c20_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_expRot(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_w[3], real_T c20_theta, real_T c20_R[9
  ])
{
  uint32_T c20_debug_family_var_map[6];
  real_T c20_wh[9];
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i863;
  real_T c20_b_w[3];
  uint32_T c20_b_debug_family_var_map[4];
  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_n;
  real_T c20_k;
  real_T c20_b_k;
  real_T c20_x;
  real_T c20_b_x;
  real_T c20_c_x;
  int32_T c20_i864;
  real_T c20_a[9];
  real_T c20_b;
  int32_T c20_i865;
  real_T c20_y[9];
  int32_T c20_i866;
  real_T c20_b_a[9];
  int32_T c20_i867;
  real_T c20_b_b[9];
  int32_T c20_i868;
  real_T c20_A[9];
  int32_T c20_i869;
  real_T c20_B[9];
  int32_T c20_i870;
  real_T c20_b_A[9];
  int32_T c20_i871;
  real_T c20_b_B[9];
  int32_T c20_i872;
  real_T c20_c_A[9];
  int32_T c20_i873;
  real_T c20_c_B[9];
  int32_T c20_i874;
  int32_T c20_i875;
  int32_T c20_i876;
  real_T c20_b_y[9];
  int32_T c20_i877;
  int32_T c20_i878;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_f_x;
  int32_T c20_i879;
  real_T c20_c_a[9];
  real_T c20_c_b;
  int32_T c20_i880;
  real_T c20_c_y[9];
  real_T c20_dv142[9];
  int32_T c20_i881;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c20_c_debug_family_names,
    c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c20_wh, c20_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_w, c20_f_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c20_theta, c20_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c20_R, c20_e_sf_marshall, 5U);
  CV_SCRIPT_FCN(2, 0);

  /*  exponential of the skew matrix */
  /*      if(norm(w)~=1) */
  /*          error('Norm of w must be 1'); */
  /*      end */
  _SFD_SCRIPT_CALL(2, 9);
  for (c20_i863 = 0; c20_i863 < 3; c20_i863 = c20_i863 + 1) {
    c20_b_w[c20_i863] = c20_w[c20_i863];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_b_debug_family_names,
    c20_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_b_nargin, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_b_nargout, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_b_w, c20_f_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_wh, c20_e_sf_marshall, 3U);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3, 3);
  c20_n = 0.0;
  c20_k = 1.0;
 label_1:
  ;
  if (c20_k <= 2.0) {
    c20_b_k = c20_k;
    if (3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c20_b_k), 1, 2, 1, 0) - 1) == 0.0) {
      c20_n = 0.0;
    } else {
      if (3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c20_b_k), 1, 2, 1, 0) - 1) > c20_n) {
        c20_n = 3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c20_b_k), 1, 2, 1, 0) - 1);
      }

      c20_k = c20_k + 1.0;
      goto label_1;
    }
  }

  CV_SCRIPT_IF(3, 0, c20_n != 3.0);

  /*      wh = diag(sym('wh',[1,3])); */
  /*      %wh=zeros(3); */
  /*      wh(1,1) = 0; */
  /*      wh(2,2) = 0; */
  /*      wh(3,3) = 0; */
  /*       */
  /*      wh(1,2) = -w(3); */
  /*      wh(1,3) = w(2); */
  /*      wh(2,1) = w(3); */
  /*      wh(2,3) = -w(1); */
  /*      wh(3,1) = -w(2); */
  /*      wh(3,2) = w(1); */
  _SFD_SCRIPT_CALL(3, 20);
  c20_wh[0] = 0.0;
  c20_wh[3] = -c20_b_w[2];
  c20_wh[6] = c20_b_w[1];
  c20_wh[1] = c20_b_w[2];
  c20_wh[4] = 0.0;
  c20_wh[7] = -c20_b_w[0];
  c20_wh[2] = -c20_b_w[1];
  c20_wh[5] = c20_b_w[0];
  c20_wh[8] = 0.0;
  _SFD_SCRIPT_CALL(3, -20);
  sf_debug_symbol_scope_pop();
  _SFD_SCRIPT_CALL(2, 10);
  c20_x = c20_theta;
  c20_b_x = c20_x;
  c20_c_x = c20_b_x;
  c20_b_x = c20_c_x;
  c20_b_x = muDoubleScalarSin(c20_b_x);
  for (c20_i864 = 0; c20_i864 < 9; c20_i864 = c20_i864 + 1) {
    c20_a[c20_i864] = c20_wh[c20_i864];
  }

  c20_b = c20_b_x;
  for (c20_i865 = 0; c20_i865 < 9; c20_i865 = c20_i865 + 1) {
    c20_y[c20_i865] = c20_a[c20_i865] * c20_b;
  }

  for (c20_i866 = 0; c20_i866 < 9; c20_i866 = c20_i866 + 1) {
    c20_b_a[c20_i866] = c20_wh[c20_i866];
  }

  for (c20_i867 = 0; c20_i867 < 9; c20_i867 = c20_i867 + 1) {
    c20_b_b[c20_i867] = c20_wh[c20_i867];
  }

  c20_b_eml_scalar_eg(chartInstance);
  c20_b_eml_scalar_eg(chartInstance);
  for (c20_i868 = 0; c20_i868 < 9; c20_i868 = c20_i868 + 1) {
    c20_A[c20_i868] = c20_b_a[c20_i868];
  }

  for (c20_i869 = 0; c20_i869 < 9; c20_i869 = c20_i869 + 1) {
    c20_B[c20_i869] = c20_b_b[c20_i869];
  }

  for (c20_i870 = 0; c20_i870 < 9; c20_i870 = c20_i870 + 1) {
    c20_b_A[c20_i870] = c20_A[c20_i870];
  }

  for (c20_i871 = 0; c20_i871 < 9; c20_i871 = c20_i871 + 1) {
    c20_b_B[c20_i871] = c20_B[c20_i871];
  }

  for (c20_i872 = 0; c20_i872 < 9; c20_i872 = c20_i872 + 1) {
    c20_c_A[c20_i872] = c20_b_A[c20_i872];
  }

  for (c20_i873 = 0; c20_i873 < 9; c20_i873 = c20_i873 + 1) {
    c20_c_B[c20_i873] = c20_b_B[c20_i873];
  }

  for (c20_i874 = 0; c20_i874 < 3; c20_i874 = c20_i874 + 1) {
    c20_i875 = 0;
    for (c20_i876 = 0; c20_i876 < 3; c20_i876 = c20_i876 + 1) {
      c20_b_y[c20_i875 + c20_i874] = 0.0;
      c20_i877 = 0;
      for (c20_i878 = 0; c20_i878 < 3; c20_i878 = c20_i878 + 1) {
        c20_b_y[c20_i875 + c20_i874] = c20_b_y[c20_i875 + c20_i874] +
          c20_c_A[c20_i877 + c20_i874] * c20_c_B[c20_i878 + c20_i875];
        c20_i877 = c20_i877 + 3;
      }

      c20_i875 = c20_i875 + 3;
    }
  }

  c20_d_x = c20_theta;
  c20_e_x = c20_d_x;
  c20_f_x = c20_e_x;
  c20_e_x = c20_f_x;
  c20_e_x = muDoubleScalarCos(c20_e_x);
  for (c20_i879 = 0; c20_i879 < 9; c20_i879 = c20_i879 + 1) {
    c20_c_a[c20_i879] = c20_b_y[c20_i879];
  }

  c20_c_b = 1.0 - c20_e_x;
  for (c20_i880 = 0; c20_i880 < 9; c20_i880 = c20_i880 + 1) {
    c20_c_y[c20_i880] = c20_c_a[c20_i880] * c20_c_b;
  }

  c20_eye(chartInstance, c20_dv142);
  for (c20_i881 = 0; c20_i881 < 9; c20_i881 = c20_i881 + 1) {
    c20_R[c20_i881] = (c20_dv142[c20_i881] + c20_y[c20_i881]) + c20_c_y[c20_i881];
  }

  _SFD_SCRIPT_CALL(2, -10);
  sf_debug_symbol_scope_pop();
}

static void c20_b_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_cross(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                      real_T c20_a[3], real_T c20_b[3], real_T c20_c[3])
{
  real_T c20_b_a;
  real_T c20_b_b;
  real_T c20_y;
  real_T c20_c_a;
  real_T c20_c_b;
  real_T c20_b_y;
  real_T c20_c1;
  real_T c20_d_a;
  real_T c20_d_b;
  real_T c20_c_y;
  real_T c20_e_a;
  real_T c20_e_b;
  real_T c20_d_y;
  real_T c20_c2;
  real_T c20_f_a;
  real_T c20_f_b;
  real_T c20_e_y;
  real_T c20_g_a;
  real_T c20_g_b;
  real_T c20_f_y;
  real_T c20_c3;
  c20_b_a = c20_a[1];
  c20_b_b = c20_b[2];
  c20_y = c20_b_a * c20_b_b;
  c20_c_a = c20_a[2];
  c20_c_b = c20_b[1];
  c20_b_y = c20_c_a * c20_c_b;
  c20_c1 = c20_y - c20_b_y;
  c20_d_a = c20_a[2];
  c20_d_b = c20_b[0];
  c20_c_y = c20_d_a * c20_d_b;
  c20_e_a = c20_a[0];
  c20_e_b = c20_b[2];
  c20_d_y = c20_e_a * c20_e_b;
  c20_c2 = c20_c_y - c20_d_y;
  c20_f_a = c20_a[0];
  c20_f_b = c20_b[1];
  c20_e_y = c20_f_a * c20_f_b;
  c20_g_a = c20_a[1];
  c20_g_b = c20_b[0];
  c20_f_y = c20_g_a * c20_g_b;
  c20_c3 = c20_e_y - c20_f_y;
  c20_c[0] = c20_c1;
  c20_c[1] = c20_c2;
  c20_c[2] = c20_c3;
}

static void c20_c_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_d_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_expg(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                     real_T c20_xi[6], real_T c20_theta, real_T c20_g[16
                     ])
{
  uint32_T c20_debug_family_var_map[10];
  static const char *c20_sv2[10] = { "v", "w", "n", "R", "P", "nargin",
    "nargout", "xi", "theta", "g" };

  real_T c20_v[3];
  real_T c20_w[3];
  real_T c20_n;
  real_T c20_R[9];
  real_T c20_P[3];
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i882;
  int32_T c20_i883;
  int32_T c20_i884;
  real_T c20_b_w[3];
  real_T c20_dv143[9];
  int32_T c20_i885;
  int32_T c20_i886;
  real_T c20_a[3];
  real_T c20_b;
  int32_T c20_i887;
  real_T c20_b_a;
  real_T c20_b_b;
  int32_T c20_i888;
  real_T c20_A[3];
  real_T c20_B;
  int32_T c20_i889;
  real_T c20_x[3];
  real_T c20_y;
  int32_T c20_i890;
  real_T c20_b_x[3];
  real_T c20_b_y;
  int32_T c20_i891;
  real_T c20_c_x[3];
  real_T c20_c_y;
  int32_T c20_i892;
  int32_T c20_i893;
  real_T c20_b_A[3];
  real_T c20_b_B;
  int32_T c20_i894;
  real_T c20_d_x[3];
  real_T c20_d_y;
  int32_T c20_i895;
  real_T c20_e_x[3];
  real_T c20_e_y;
  int32_T c20_i896;
  real_T c20_f_x[3];
  real_T c20_f_y;
  int32_T c20_i897;
  int32_T c20_i898;
  real_T c20_c_w[3];
  real_T c20_dv144[9];
  int32_T c20_i899;
  real_T c20_dv145[9];
  int32_T c20_i900;
  real_T c20_c_a[9];
  int32_T c20_i901;
  real_T c20_d_w[3];
  real_T c20_c_b[9];
  int32_T c20_i902;
  real_T c20_c_A[9];
  int32_T c20_i903;
  real_T c20_c_B[9];
  int32_T c20_i904;
  real_T c20_d_A[9];
  int32_T c20_i905;
  real_T c20_d_B[9];
  int32_T c20_i906;
  real_T c20_e_A[9];
  int32_T c20_i907;
  real_T c20_e_B[9];
  int32_T c20_i908;
  int32_T c20_i909;
  int32_T c20_i910;
  real_T c20_g_y[9];
  int32_T c20_i911;
  int32_T c20_i912;
  int32_T c20_i913;
  real_T c20_d_a[9];
  int32_T c20_i914;
  real_T c20_d_b[3];
  int32_T c20_i915;
  real_T c20_f_A[9];
  int32_T c20_i916;
  real_T c20_f_B[3];
  int32_T c20_i917;
  real_T c20_g_A[9];
  int32_T c20_i918;
  real_T c20_g_B[3];
  int32_T c20_i919;
  real_T c20_h_A[9];
  int32_T c20_i920;
  real_T c20_h_B[3];
  int32_T c20_i921;
  real_T c20_h_y[3];
  int32_T c20_i922;
  int32_T c20_i923;
  int32_T c20_i924;
  real_T c20_e_a[3];
  int32_T c20_i925;
  real_T c20_e_b[3];
  int32_T c20_i926;
  int32_T c20_i927;
  int32_T c20_i928;
  real_T c20_i_y[9];
  int32_T c20_i929;
  real_T c20_f_a[9];
  real_T c20_f_b;
  int32_T c20_i930;
  real_T c20_j_y[9];
  int32_T c20_i931;
  real_T c20_g_a[9];
  int32_T c20_i932;
  real_T c20_g_b[3];
  int32_T c20_i933;
  real_T c20_i_A[9];
  int32_T c20_i934;
  real_T c20_i_B[3];
  int32_T c20_i935;
  real_T c20_j_A[9];
  int32_T c20_i936;
  real_T c20_j_B[3];
  int32_T c20_i937;
  real_T c20_k_A[9];
  int32_T c20_i938;
  real_T c20_k_B[3];
  int32_T c20_i939;
  real_T c20_k_y[3];
  int32_T c20_i940;
  int32_T c20_i941;
  int32_T c20_i942;
  int32_T c20_i943;
  int32_T c20_i944;
  int32_T c20_i945;
  int32_T c20_i946;
  int32_T c20_i947;
  int32_T c20_i948;
  int32_T c20_i949;
  static real_T c20_dv146[4] = { 0.0, 0.0, 0.0, 1.0 };

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c20_sv2, c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c20_v, c20_f_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c20_w, c20_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c20_n, c20_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_R, c20_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c20_P, c20_f_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c20_xi, c20_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c20_theta, c20_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c20_g, c20_g_sf_marshall, 9U);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4, 2);
  for (c20_i882 = 0; c20_i882 < 3; c20_i882 = c20_i882 + 1) {
    c20_v[c20_i882] = c20_xi[c20_i882];
  }

  _SFD_SCRIPT_CALL(4, 3);
  for (c20_i883 = 0; c20_i883 < 3; c20_i883 = c20_i883 + 1) {
    c20_w[c20_i883] = c20_xi[c20_i883 + 3];
  }

  _SFD_SCRIPT_CALL(4, 4);
  for (c20_i884 = 0; c20_i884 < 3; c20_i884 = c20_i884 + 1) {
    c20_b_w[c20_i884] = c20_w[c20_i884];
  }

  c20_n = c20_norm(chartInstance, c20_b_w);
  _SFD_SCRIPT_CALL(4, 6);
  c20_eps(chartInstance);
  if (CV_SCRIPT_IF(4, 0, c20_n < 2.2204460492503131E-16)) {
    _SFD_SCRIPT_CALL(4, 7);
    c20_eye(chartInstance, c20_dv143);
    for (c20_i885 = 0; c20_i885 < 9; c20_i885 = c20_i885 + 1) {
      c20_R[c20_i885] = c20_dv143[c20_i885];
    }

    _SFD_SCRIPT_CALL(4, 8);
    for (c20_i886 = 0; c20_i886 < 3; c20_i886 = c20_i886 + 1) {
      c20_a[c20_i886] = c20_v[c20_i886];
    }

    c20_b = c20_theta;
    for (c20_i887 = 0; c20_i887 < 3; c20_i887 = c20_i887 + 1) {
      c20_P[c20_i887] = c20_a[c20_i887] * c20_b;
    }
  } else {
    _SFD_SCRIPT_CALL(4, 10);
    c20_b_a = c20_theta;
    c20_b_b = c20_n;
    c20_theta = c20_b_a * c20_b_b;
    _SFD_SCRIPT_CALL(4, 11);
    for (c20_i888 = 0; c20_i888 < 3; c20_i888 = c20_i888 + 1) {
      c20_A[c20_i888] = c20_w[c20_i888];
    }

    c20_B = c20_n;
    for (c20_i889 = 0; c20_i889 < 3; c20_i889 = c20_i889 + 1) {
      c20_x[c20_i889] = c20_A[c20_i889];
    }

    c20_y = c20_B;
    for (c20_i890 = 0; c20_i890 < 3; c20_i890 = c20_i890 + 1) {
      c20_b_x[c20_i890] = c20_x[c20_i890];
    }

    c20_b_y = c20_y;
    for (c20_i891 = 0; c20_i891 < 3; c20_i891 = c20_i891 + 1) {
      c20_c_x[c20_i891] = c20_b_x[c20_i891];
    }

    c20_c_y = c20_b_y;
    for (c20_i892 = 0; c20_i892 < 3; c20_i892 = c20_i892 + 1) {
      c20_w[c20_i892] = c20_c_x[c20_i892] / c20_c_y;
    }

    _SFD_SCRIPT_CALL(4, 12);
    for (c20_i893 = 0; c20_i893 < 3; c20_i893 = c20_i893 + 1) {
      c20_b_A[c20_i893] = c20_v[c20_i893];
    }

    c20_b_B = c20_n;
    for (c20_i894 = 0; c20_i894 < 3; c20_i894 = c20_i894 + 1) {
      c20_d_x[c20_i894] = c20_b_A[c20_i894];
    }

    c20_d_y = c20_b_B;
    for (c20_i895 = 0; c20_i895 < 3; c20_i895 = c20_i895 + 1) {
      c20_e_x[c20_i895] = c20_d_x[c20_i895];
    }

    c20_e_y = c20_d_y;
    for (c20_i896 = 0; c20_i896 < 3; c20_i896 = c20_i896 + 1) {
      c20_f_x[c20_i896] = c20_e_x[c20_i896];
    }

    c20_f_y = c20_e_y;
    for (c20_i897 = 0; c20_i897 < 3; c20_i897 = c20_i897 + 1) {
      c20_v[c20_i897] = c20_f_x[c20_i897] / c20_f_y;
    }

    _SFD_SCRIPT_CALL(4, 13);
    for (c20_i898 = 0; c20_i898 < 3; c20_i898 = c20_i898 + 1) {
      c20_c_w[c20_i898] = c20_w[c20_i898];
    }

    c20_expr(chartInstance, c20_c_w, c20_theta, c20_dv144);
    for (c20_i899 = 0; c20_i899 < 9; c20_i899 = c20_i899 + 1) {
      c20_R[c20_i899] = c20_dv144[c20_i899];
    }

    _SFD_SCRIPT_CALL(4, 14);
    c20_eye(chartInstance, c20_dv145);
    for (c20_i900 = 0; c20_i900 < 9; c20_i900 = c20_i900 + 1) {
      c20_c_a[c20_i900] = c20_dv145[c20_i900] - c20_R[c20_i900];
    }

    for (c20_i901 = 0; c20_i901 < 3; c20_i901 = c20_i901 + 1) {
      c20_d_w[c20_i901] = c20_w[c20_i901];
    }

    c20_hat(chartInstance, c20_d_w, c20_c_b);
    c20_b_eml_scalar_eg(chartInstance);
    c20_b_eml_scalar_eg(chartInstance);
    for (c20_i902 = 0; c20_i902 < 9; c20_i902 = c20_i902 + 1) {
      c20_c_A[c20_i902] = c20_c_a[c20_i902];
    }

    for (c20_i903 = 0; c20_i903 < 9; c20_i903 = c20_i903 + 1) {
      c20_c_B[c20_i903] = c20_c_b[c20_i903];
    }

    for (c20_i904 = 0; c20_i904 < 9; c20_i904 = c20_i904 + 1) {
      c20_d_A[c20_i904] = c20_c_A[c20_i904];
    }

    for (c20_i905 = 0; c20_i905 < 9; c20_i905 = c20_i905 + 1) {
      c20_d_B[c20_i905] = c20_c_B[c20_i905];
    }

    for (c20_i906 = 0; c20_i906 < 9; c20_i906 = c20_i906 + 1) {
      c20_e_A[c20_i906] = c20_d_A[c20_i906];
    }

    for (c20_i907 = 0; c20_i907 < 9; c20_i907 = c20_i907 + 1) {
      c20_e_B[c20_i907] = c20_d_B[c20_i907];
    }

    for (c20_i908 = 0; c20_i908 < 3; c20_i908 = c20_i908 + 1) {
      c20_i909 = 0;
      for (c20_i910 = 0; c20_i910 < 3; c20_i910 = c20_i910 + 1) {
        c20_g_y[c20_i909 + c20_i908] = 0.0;
        c20_i911 = 0;
        for (c20_i912 = 0; c20_i912 < 3; c20_i912 = c20_i912 + 1) {
          c20_g_y[c20_i909 + c20_i908] = c20_g_y[c20_i909 + c20_i908] +
            c20_e_A[c20_i911 + c20_i908] * c20_e_B[c20_i912 + c20_i909];
          c20_i911 = c20_i911 + 3;
        }

        c20_i909 = c20_i909 + 3;
      }
    }

    for (c20_i913 = 0; c20_i913 < 9; c20_i913 = c20_i913 + 1) {
      c20_d_a[c20_i913] = c20_g_y[c20_i913];
    }

    for (c20_i914 = 0; c20_i914 < 3; c20_i914 = c20_i914 + 1) {
      c20_d_b[c20_i914] = c20_v[c20_i914];
    }

    c20_c_eml_scalar_eg(chartInstance);
    c20_c_eml_scalar_eg(chartInstance);
    for (c20_i915 = 0; c20_i915 < 9; c20_i915 = c20_i915 + 1) {
      c20_f_A[c20_i915] = c20_d_a[c20_i915];
    }

    for (c20_i916 = 0; c20_i916 < 3; c20_i916 = c20_i916 + 1) {
      c20_f_B[c20_i916] = c20_d_b[c20_i916];
    }

    for (c20_i917 = 0; c20_i917 < 9; c20_i917 = c20_i917 + 1) {
      c20_g_A[c20_i917] = c20_f_A[c20_i917];
    }

    for (c20_i918 = 0; c20_i918 < 3; c20_i918 = c20_i918 + 1) {
      c20_g_B[c20_i918] = c20_f_B[c20_i918];
    }

    for (c20_i919 = 0; c20_i919 < 9; c20_i919 = c20_i919 + 1) {
      c20_h_A[c20_i919] = c20_g_A[c20_i919];
    }

    for (c20_i920 = 0; c20_i920 < 3; c20_i920 = c20_i920 + 1) {
      c20_h_B[c20_i920] = c20_g_B[c20_i920];
    }

    for (c20_i921 = 0; c20_i921 < 3; c20_i921 = c20_i921 + 1) {
      c20_h_y[c20_i921] = 0.0;
      c20_i922 = 0;
      for (c20_i923 = 0; c20_i923 < 3; c20_i923 = c20_i923 + 1) {
        c20_h_y[c20_i921] = c20_h_y[c20_i921] + c20_h_A[c20_i922 + c20_i921] *
          c20_h_B[c20_i923];
        c20_i922 = c20_i922 + 3;
      }
    }

    for (c20_i924 = 0; c20_i924 < 3; c20_i924 = c20_i924 + 1) {
      c20_e_a[c20_i924] = c20_w[c20_i924];
    }

    for (c20_i925 = 0; c20_i925 < 3; c20_i925 = c20_i925 + 1) {
      c20_e_b[c20_i925] = c20_w[c20_i925];
    }

    c20_i926 = 0;
    for (c20_i927 = 0; c20_i927 < 3; c20_i927 = c20_i927 + 1) {
      for (c20_i928 = 0; c20_i928 < 3; c20_i928 = c20_i928 + 1) {
        c20_i_y[c20_i928 + c20_i926] = c20_e_a[c20_i928] * c20_e_b[c20_i927];
      }

      c20_i926 = c20_i926 + 3;
    }

    for (c20_i929 = 0; c20_i929 < 9; c20_i929 = c20_i929 + 1) {
      c20_f_a[c20_i929] = c20_i_y[c20_i929];
    }

    c20_f_b = c20_theta;
    for (c20_i930 = 0; c20_i930 < 9; c20_i930 = c20_i930 + 1) {
      c20_j_y[c20_i930] = c20_f_a[c20_i930] * c20_f_b;
    }

    for (c20_i931 = 0; c20_i931 < 9; c20_i931 = c20_i931 + 1) {
      c20_g_a[c20_i931] = c20_j_y[c20_i931];
    }

    for (c20_i932 = 0; c20_i932 < 3; c20_i932 = c20_i932 + 1) {
      c20_g_b[c20_i932] = c20_v[c20_i932];
    }

    c20_c_eml_scalar_eg(chartInstance);
    c20_c_eml_scalar_eg(chartInstance);
    for (c20_i933 = 0; c20_i933 < 9; c20_i933 = c20_i933 + 1) {
      c20_i_A[c20_i933] = c20_g_a[c20_i933];
    }

    for (c20_i934 = 0; c20_i934 < 3; c20_i934 = c20_i934 + 1) {
      c20_i_B[c20_i934] = c20_g_b[c20_i934];
    }

    for (c20_i935 = 0; c20_i935 < 9; c20_i935 = c20_i935 + 1) {
      c20_j_A[c20_i935] = c20_i_A[c20_i935];
    }

    for (c20_i936 = 0; c20_i936 < 3; c20_i936 = c20_i936 + 1) {
      c20_j_B[c20_i936] = c20_i_B[c20_i936];
    }

    for (c20_i937 = 0; c20_i937 < 9; c20_i937 = c20_i937 + 1) {
      c20_k_A[c20_i937] = c20_j_A[c20_i937];
    }

    for (c20_i938 = 0; c20_i938 < 3; c20_i938 = c20_i938 + 1) {
      c20_k_B[c20_i938] = c20_j_B[c20_i938];
    }

    for (c20_i939 = 0; c20_i939 < 3; c20_i939 = c20_i939 + 1) {
      c20_k_y[c20_i939] = 0.0;
      c20_i940 = 0;
      for (c20_i941 = 0; c20_i941 < 3; c20_i941 = c20_i941 + 1) {
        c20_k_y[c20_i939] = c20_k_y[c20_i939] + c20_k_A[c20_i940 + c20_i939] *
          c20_k_B[c20_i941];
        c20_i940 = c20_i940 + 3;
      }
    }

    for (c20_i942 = 0; c20_i942 < 3; c20_i942 = c20_i942 + 1) {
      c20_P[c20_i942] = c20_h_y[c20_i942] + c20_k_y[c20_i942];
    }
  }

  _SFD_SCRIPT_CALL(4, 17);
  c20_i943 = 0;
  c20_i944 = 0;
  for (c20_i945 = 0; c20_i945 < 3; c20_i945 = c20_i945 + 1) {
    for (c20_i946 = 0; c20_i946 < 3; c20_i946 = c20_i946 + 1) {
      c20_g[c20_i946 + c20_i943] = c20_R[c20_i946 + c20_i944];
    }

    c20_i943 = c20_i943 + 4;
    c20_i944 = c20_i944 + 3;
  }

  for (c20_i947 = 0; c20_i947 < 3; c20_i947 = c20_i947 + 1) {
    c20_g[c20_i947 + 12] = c20_P[c20_i947];
  }

  c20_i948 = 0;
  for (c20_i949 = 0; c20_i949 < 4; c20_i949 = c20_i949 + 1) {
    c20_g[c20_i948 + 3] = c20_dv146[c20_i949];
    c20_i948 = c20_i948 + 4;
  }

  _SFD_SCRIPT_CALL(4, -17);
  sf_debug_symbol_scope_pop();
}

static real_T c20_norm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_x[3])
{
  int32_T c20_i950;
  real_T c20_b_x[3];
  int32_T c20_i951;
  real_T c20_c_x[3];
  int32_T c20_i952;
  real_T c20_d_x[3];
  int32_T c20_i953;
  real_T c20_e_x[3];
  for (c20_i950 = 0; c20_i950 < 3; c20_i950 = c20_i950 + 1) {
    c20_b_x[c20_i950] = c20_x[c20_i950];
  }

  for (c20_i951 = 0; c20_i951 < 3; c20_i951 = c20_i951 + 1) {
    c20_c_x[c20_i951] = c20_b_x[c20_i951];
  }

  for (c20_i952 = 0; c20_i952 < 3; c20_i952 = c20_i952 + 1) {
    c20_d_x[c20_i952] = c20_c_x[c20_i952];
  }

  for (c20_i953 = 0; c20_i953 < 3; c20_i953 = c20_i953 + 1) {
    c20_e_x[c20_i953] = c20_d_x[c20_i953];
  }

  return c20_ceval_xnrm2(chartInstance, 3, c20_e_x, 1, 1);
}

static real_T c20_ceval_xnrm2(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[3], int32_T
  c20_ix0, int32_T c20_incx)
{
  return dnrm232(&c20_n, &c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c20_ix0), 1, 3, 1, 0) - 1], &
                 c20_incx);
}

static void c20_eps(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
}

static void c20_expr(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                     real_T c20_w[3], real_T c20_theta, real_T c20_R[9])
{
  uint32_T c20_debug_family_var_map[6];
  real_T c20_n;
  real_T c20_nargin = 2.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i954;
  real_T c20_b_w[3];
  real_T c20_dv147[9];
  int32_T c20_i955;
  int32_T c20_i956;
  real_T c20_c_w[3];
  uint32_T c20_b_debug_family_var_map[4];
  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_W[9];
  int32_T c20_i957;
  real_T c20_A[9];
  real_T c20_B;
  int32_T c20_i958;
  real_T c20_x[9];
  real_T c20_y;
  int32_T c20_i959;
  real_T c20_b_x[9];
  real_T c20_b_y;
  int32_T c20_i960;
  real_T c20_c_x[9];
  real_T c20_c_y;
  int32_T c20_i961;
  real_T c20_d_y[9];
  real_T c20_a;
  real_T c20_b;
  real_T c20_e_y;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_f_x;
  int32_T c20_i962;
  real_T c20_b_a[9];
  real_T c20_b_b;
  int32_T c20_i963;
  real_T c20_f_y[9];
  int32_T c20_i964;
  real_T c20_d_w[3];
  uint32_T c20_c_debug_family_var_map[4];
  real_T c20_c_nargin = 1.0;
  real_T c20_c_nargout = 1.0;
  real_T c20_b_W[9];
  int32_T c20_i965;
  real_T c20_c_a[9];
  int32_T c20_i966;
  real_T c20_d_a[9];
  real_T c20_c[9];
  real_T c20_e_a;
  real_T c20_b_c;
  int32_T c20_i967;
  real_T c20_b_A[9];
  real_T c20_b_B;
  int32_T c20_i968;
  real_T c20_g_x[9];
  real_T c20_g_y;
  int32_T c20_i969;
  real_T c20_h_x[9];
  real_T c20_h_y;
  int32_T c20_i970;
  real_T c20_i_x[9];
  real_T c20_i_y;
  int32_T c20_i971;
  real_T c20_j_y[9];
  real_T c20_f_a;
  real_T c20_c_b;
  real_T c20_k_y;
  real_T c20_j_x;
  real_T c20_k_x;
  real_T c20_l_x;
  int32_T c20_i972;
  real_T c20_g_a[9];
  real_T c20_d_b;
  int32_T c20_i973;
  real_T c20_l_y[9];
  real_T c20_dv148[9];
  int32_T c20_i974;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c20_f_debug_family_names,
    c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_n, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_w, c20_f_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c20_theta, c20_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c20_R, c20_e_sf_marshall, 5U);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5, 2);
  for (c20_i954 = 0; c20_i954 < 3; c20_i954 = c20_i954 + 1) {
    c20_b_w[c20_i954] = c20_w[c20_i954];
  }

  c20_n = c20_norm(chartInstance, c20_b_w);
  _SFD_SCRIPT_CALL(5, 4);
  if (CV_SCRIPT_IF(5, 0, c20_n < 2.2204460492503131E-16)) {
    _SFD_SCRIPT_CALL(5, 5);
    c20_eye(chartInstance, c20_dv147);
    for (c20_i955 = 0; c20_i955 < 9; c20_i955 = c20_i955 + 1) {
      c20_R[c20_i955] = c20_dv147[c20_i955];
    }
  } else {
    /* theta = theta*n; */
    /* w = w/n; */
    _SFD_SCRIPT_CALL(5, 9);
    for (c20_i956 = 0; c20_i956 < 3; c20_i956 = c20_i956 + 1) {
      c20_c_w[c20_i956] = c20_w[c20_i956];
    }

    sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_e_debug_family_names,
      c20_b_debug_family_var_map);
    sf_debug_symbol_scope_add_eml(&c20_b_nargin, c20_d_sf_marshall, 0U);
    sf_debug_symbol_scope_add_eml(&c20_b_nargout, c20_d_sf_marshall, 1U);
    sf_debug_symbol_scope_add_eml(c20_c_w, c20_f_sf_marshall, 2U);
    sf_debug_symbol_scope_add_eml(c20_W, c20_e_sf_marshall, 3U);
    CV_SCRIPT_FCN(6, 0);
    _SFD_SCRIPT_CALL(6, 2);
    c20_W[0] = 0.0;
    c20_W[3] = -c20_c_w[2];
    c20_W[6] = c20_c_w[1];
    c20_W[1] = c20_c_w[2];
    c20_W[4] = 0.0;
    c20_W[7] = -c20_c_w[0];
    c20_W[2] = -c20_c_w[1];
    c20_W[5] = c20_c_w[0];
    c20_W[8] = 0.0;
    _SFD_SCRIPT_CALL(6, -2);
    sf_debug_symbol_scope_pop();
    for (c20_i957 = 0; c20_i957 < 9; c20_i957 = c20_i957 + 1) {
      c20_A[c20_i957] = c20_W[c20_i957];
    }

    c20_B = c20_n;
    for (c20_i958 = 0; c20_i958 < 9; c20_i958 = c20_i958 + 1) {
      c20_x[c20_i958] = c20_A[c20_i958];
    }

    c20_y = c20_B;
    for (c20_i959 = 0; c20_i959 < 9; c20_i959 = c20_i959 + 1) {
      c20_b_x[c20_i959] = c20_x[c20_i959];
    }

    c20_b_y = c20_y;
    for (c20_i960 = 0; c20_i960 < 9; c20_i960 = c20_i960 + 1) {
      c20_c_x[c20_i960] = c20_b_x[c20_i960];
    }

    c20_c_y = c20_b_y;
    for (c20_i961 = 0; c20_i961 < 9; c20_i961 = c20_i961 + 1) {
      c20_d_y[c20_i961] = c20_c_x[c20_i961] / c20_c_y;
    }

    c20_a = c20_n;
    c20_b = c20_theta;
    c20_e_y = c20_a * c20_b;
    c20_d_x = c20_e_y;
    c20_e_x = c20_d_x;
    c20_f_x = c20_e_x;
    c20_e_x = c20_f_x;
    c20_e_x = muDoubleScalarSin(c20_e_x);
    for (c20_i962 = 0; c20_i962 < 9; c20_i962 = c20_i962 + 1) {
      c20_b_a[c20_i962] = c20_d_y[c20_i962];
    }

    c20_b_b = c20_e_x;
    for (c20_i963 = 0; c20_i963 < 9; c20_i963 = c20_i963 + 1) {
      c20_f_y[c20_i963] = c20_b_a[c20_i963] * c20_b_b;
    }

    for (c20_i964 = 0; c20_i964 < 3; c20_i964 = c20_i964 + 1) {
      c20_d_w[c20_i964] = c20_w[c20_i964];
    }

    sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_e_debug_family_names,
      c20_c_debug_family_var_map);
    sf_debug_symbol_scope_add_eml(&c20_c_nargin, c20_d_sf_marshall, 0U);
    sf_debug_symbol_scope_add_eml(&c20_c_nargout, c20_d_sf_marshall, 1U);
    sf_debug_symbol_scope_add_eml(c20_d_w, c20_f_sf_marshall, 2U);
    sf_debug_symbol_scope_add_eml(c20_b_W, c20_e_sf_marshall, 3U);
    CV_SCRIPT_FCN(6, 0);
    _SFD_SCRIPT_CALL(6, 2);
    c20_b_W[0] = 0.0;
    c20_b_W[3] = -c20_d_w[2];
    c20_b_W[6] = c20_d_w[1];
    c20_b_W[1] = c20_d_w[2];
    c20_b_W[4] = 0.0;
    c20_b_W[7] = -c20_d_w[0];
    c20_b_W[2] = -c20_d_w[1];
    c20_b_W[5] = c20_d_w[0];
    c20_b_W[8] = 0.0;
    _SFD_SCRIPT_CALL(6, -2);
    sf_debug_symbol_scope_pop();
    for (c20_i965 = 0; c20_i965 < 9; c20_i965 = c20_i965 + 1) {
      c20_c_a[c20_i965] = c20_b_W[c20_i965];
    }

    for (c20_i966 = 0; c20_i966 < 9; c20_i966 = c20_i966 + 1) {
      c20_d_a[c20_i966] = c20_c_a[c20_i966];
    }

    c20_matrix_to_integer_power(chartInstance, c20_d_a, 2.0, c20_c);
    c20_e_a = c20_n;
    c20_b_c = c20_power(chartInstance, c20_e_a, 2.0);
    for (c20_i967 = 0; c20_i967 < 9; c20_i967 = c20_i967 + 1) {
      c20_b_A[c20_i967] = c20_c[c20_i967];
    }

    c20_b_B = c20_b_c;
    for (c20_i968 = 0; c20_i968 < 9; c20_i968 = c20_i968 + 1) {
      c20_g_x[c20_i968] = c20_b_A[c20_i968];
    }

    c20_g_y = c20_b_B;
    for (c20_i969 = 0; c20_i969 < 9; c20_i969 = c20_i969 + 1) {
      c20_h_x[c20_i969] = c20_g_x[c20_i969];
    }

    c20_h_y = c20_g_y;
    for (c20_i970 = 0; c20_i970 < 9; c20_i970 = c20_i970 + 1) {
      c20_i_x[c20_i970] = c20_h_x[c20_i970];
    }

    c20_i_y = c20_h_y;
    for (c20_i971 = 0; c20_i971 < 9; c20_i971 = c20_i971 + 1) {
      c20_j_y[c20_i971] = c20_i_x[c20_i971] / c20_i_y;
    }

    c20_f_a = c20_n;
    c20_c_b = c20_theta;
    c20_k_y = c20_f_a * c20_c_b;
    c20_j_x = c20_k_y;
    c20_k_x = c20_j_x;
    c20_l_x = c20_k_x;
    c20_k_x = c20_l_x;
    c20_k_x = muDoubleScalarCos(c20_k_x);
    for (c20_i972 = 0; c20_i972 < 9; c20_i972 = c20_i972 + 1) {
      c20_g_a[c20_i972] = c20_j_y[c20_i972];
    }

    c20_d_b = 1.0 - c20_k_x;
    for (c20_i973 = 0; c20_i973 < 9; c20_i973 = c20_i973 + 1) {
      c20_l_y[c20_i973] = c20_g_a[c20_i973] * c20_d_b;
    }

    c20_eye(chartInstance, c20_dv148);
    for (c20_i974 = 0; c20_i974 < 9; c20_i974 = c20_i974 + 1) {
      c20_R[c20_i974] = (c20_dv148[c20_i974] + c20_f_y[c20_i974]) +
        c20_l_y[c20_i974];
    }
  }

  _SFD_SCRIPT_CALL(5, -9);
  sf_debug_symbol_scope_pop();
}

static void c20_hat(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                    real_T c20_w[3], real_T c20_W[9])
{
  uint32_T c20_debug_family_var_map[4];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_e_debug_family_names,
    c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_w, c20_f_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_W, c20_e_sf_marshall, 3U);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6, 2);
  c20_W[0] = 0.0;
  c20_W[3] = -c20_w[2];
  c20_W[6] = c20_w[1];
  c20_W[1] = c20_w[2];
  c20_W[4] = 0.0;
  c20_W[7] = -c20_w[0];
  c20_W[2] = -c20_w[1];
  c20_W[5] = c20_w[0];
  c20_W[8] = 0.0;
  _SFD_SCRIPT_CALL(6, -2);
  sf_debug_symbol_scope_pop();
}

static void c20_matrix_to_integer_power
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance, real_T c20_a[9],
   real_T c20_b,
   real_T c20_c[9])
{
  real_T c20_x;
  real_T c20_e;
  boolean_T c20_firstmult;
  real_T c20_b_x;
  real_T c20_ed2;
  real_T c20_b_b;
  real_T c20_y;
  int32_T c20_i975;
  int32_T c20_i976;
  real_T c20_b_a[9];
  int32_T c20_i977;
  real_T c20_c_b[9];
  int32_T c20_i978;
  real_T c20_A[9];
  int32_T c20_i979;
  real_T c20_B[9];
  int32_T c20_i980;
  real_T c20_b_A[9];
  int32_T c20_i981;
  real_T c20_b_B[9];
  int32_T c20_i982;
  real_T c20_c_A[9];
  int32_T c20_i983;
  real_T c20_c_B[9];
  int32_T c20_i984;
  int32_T c20_i985;
  int32_T c20_i986;
  int32_T c20_i987;
  int32_T c20_i988;
  int32_T c20_i989;
  real_T c20_c_x[9];
  int32_T c20_i990;
  real_T c20_d_x[9];
  int32_T c20_i991;
  real_T c20_e_x[9];
  int32_T c20_i992;
  real_T c20_xinv[9];
  int32_T c20_i993;
  real_T c20_f_x[9];
  real_T c20_n1x;
  int32_T c20_i994;
  real_T c20_b_xinv[9];
  real_T c20_n1xinv;
  real_T c20_c_a;
  real_T c20_d_b;
  real_T c20_b_y;
  real_T c20_rc;
  real_T c20_g_x;
  boolean_T c20_e_b;
  int32_T c20_i995;
  real_T c20_d_a[9];
  int32_T c20_i996;
  real_T c20_f_b[9];
  int32_T c20_i997;
  real_T c20_d_A[9];
  int32_T c20_i998;
  real_T c20_d_B[9];
  int32_T c20_i999;
  real_T c20_e_A[9];
  int32_T c20_i1000;
  real_T c20_e_B[9];
  int32_T c20_i1001;
  real_T c20_f_A[9];
  int32_T c20_i1002;
  real_T c20_f_B[9];
  int32_T c20_i1003;
  int32_T c20_i1004;
  int32_T c20_i1005;
  int32_T c20_i1006;
  int32_T c20_i1007;
  int32_T c20_i1008;
  int32_T c20_k;
  int32_T c20_b_k;
  c20_e_eml_scalar_eg(chartInstance);
  c20_x = c20_b;
  c20_e = muDoubleScalarAbs(c20_x);
  if (c20_e > 0.0) {
    c20_firstmult = TRUE;
   label_1:
    ;
    c20_b_x = c20_e / 2.0;
    c20_ed2 = c20_b_x;
    c20_ed2 = muDoubleScalarFloor(c20_ed2);
    c20_b_b = c20_ed2;
    c20_y = 2.0 * c20_b_b;
    if (c20_y != c20_e) {
      if (c20_firstmult) {
        for (c20_i975 = 0; c20_i975 < 9; c20_i975 = c20_i975 + 1) {
          c20_c[c20_i975] = c20_a[c20_i975];
        }

        c20_firstmult = FALSE;
      } else {
        for (c20_i976 = 0; c20_i976 < 9; c20_i976 = c20_i976 + 1) {
          c20_b_a[c20_i976] = c20_c[c20_i976];
        }

        for (c20_i977 = 0; c20_i977 < 9; c20_i977 = c20_i977 + 1) {
          c20_c_b[c20_i977] = c20_a[c20_i977];
        }

        c20_b_eml_scalar_eg(chartInstance);
        c20_b_eml_scalar_eg(chartInstance);
        for (c20_i978 = 0; c20_i978 < 9; c20_i978 = c20_i978 + 1) {
          c20_A[c20_i978] = c20_b_a[c20_i978];
        }

        for (c20_i979 = 0; c20_i979 < 9; c20_i979 = c20_i979 + 1) {
          c20_B[c20_i979] = c20_c_b[c20_i979];
        }

        for (c20_i980 = 0; c20_i980 < 9; c20_i980 = c20_i980 + 1) {
          c20_b_A[c20_i980] = c20_A[c20_i980];
        }

        for (c20_i981 = 0; c20_i981 < 9; c20_i981 = c20_i981 + 1) {
          c20_b_B[c20_i981] = c20_B[c20_i981];
        }

        for (c20_i982 = 0; c20_i982 < 9; c20_i982 = c20_i982 + 1) {
          c20_c_A[c20_i982] = c20_b_A[c20_i982];
        }

        for (c20_i983 = 0; c20_i983 < 9; c20_i983 = c20_i983 + 1) {
          c20_c_B[c20_i983] = c20_b_B[c20_i983];
        }

        for (c20_i984 = 0; c20_i984 < 3; c20_i984 = c20_i984 + 1) {
          c20_i985 = 0;
          for (c20_i986 = 0; c20_i986 < 3; c20_i986 = c20_i986 + 1) {
            c20_c[c20_i985 + c20_i984] = 0.0;
            c20_i987 = 0;
            for (c20_i988 = 0; c20_i988 < 3; c20_i988 = c20_i988 + 1) {
              c20_c[c20_i985 + c20_i984] = c20_c[c20_i985 + c20_i984] +
                c20_c_A[c20_i987 + c20_i984] * c20_c_B[c20_i988 + c20_i985];
              c20_i987 = c20_i987 + 3;
            }

            c20_i985 = c20_i985 + 3;
          }
        }
      }
    }

    if (c20_ed2 == 0.0) {
    } else {
      c20_e = c20_ed2;
      for (c20_i995 = 0; c20_i995 < 9; c20_i995 = c20_i995 + 1) {
        c20_d_a[c20_i995] = c20_a[c20_i995];
      }

      for (c20_i996 = 0; c20_i996 < 9; c20_i996 = c20_i996 + 1) {
        c20_f_b[c20_i996] = c20_a[c20_i996];
      }

      c20_b_eml_scalar_eg(chartInstance);
      c20_b_eml_scalar_eg(chartInstance);
      for (c20_i997 = 0; c20_i997 < 9; c20_i997 = c20_i997 + 1) {
        c20_d_A[c20_i997] = c20_d_a[c20_i997];
      }

      for (c20_i998 = 0; c20_i998 < 9; c20_i998 = c20_i998 + 1) {
        c20_d_B[c20_i998] = c20_f_b[c20_i998];
      }

      for (c20_i999 = 0; c20_i999 < 9; c20_i999 = c20_i999 + 1) {
        c20_e_A[c20_i999] = c20_d_A[c20_i999];
      }

      for (c20_i1000 = 0; c20_i1000 < 9; c20_i1000 = c20_i1000 + 1) {
        c20_e_B[c20_i1000] = c20_d_B[c20_i1000];
      }

      for (c20_i1001 = 0; c20_i1001 < 9; c20_i1001 = c20_i1001 + 1) {
        c20_f_A[c20_i1001] = c20_e_A[c20_i1001];
      }

      for (c20_i1002 = 0; c20_i1002 < 9; c20_i1002 = c20_i1002 + 1) {
        c20_f_B[c20_i1002] = c20_e_B[c20_i1002];
      }

      for (c20_i1003 = 0; c20_i1003 < 3; c20_i1003 = c20_i1003 + 1) {
        c20_i1004 = 0;
        for (c20_i1005 = 0; c20_i1005 < 3; c20_i1005 = c20_i1005 + 1) {
          c20_a[c20_i1004 + c20_i1003] = 0.0;
          c20_i1006 = 0;
          for (c20_i1007 = 0; c20_i1007 < 3; c20_i1007 = c20_i1007 + 1) {
            c20_a[c20_i1004 + c20_i1003] = c20_a[c20_i1004 + c20_i1003] +
              c20_f_A[c20_i1006 + c20_i1003] * c20_f_B[c20_i1007 + c20_i1004];
            c20_i1006 = c20_i1006 + 3;
          }

          c20_i1004 = c20_i1004 + 3;
        }
      }

      goto label_1;
    }

    if (c20_b < 0.0) {
      for (c20_i989 = 0; c20_i989 < 9; c20_i989 = c20_i989 + 1) {
        c20_c_x[c20_i989] = c20_c[c20_i989];
      }

      for (c20_i990 = 0; c20_i990 < 9; c20_i990 = c20_i990 + 1) {
        c20_d_x[c20_i990] = c20_c_x[c20_i990];
      }

      c20_inv3x3(chartInstance, c20_d_x, c20_c);
      for (c20_i991 = 0; c20_i991 < 9; c20_i991 = c20_i991 + 1) {
        c20_e_x[c20_i991] = c20_c_x[c20_i991];
      }

      for (c20_i992 = 0; c20_i992 < 9; c20_i992 = c20_i992 + 1) {
        c20_xinv[c20_i992] = c20_c[c20_i992];
      }

      for (c20_i993 = 0; c20_i993 < 9; c20_i993 = c20_i993 + 1) {
        c20_f_x[c20_i993] = c20_e_x[c20_i993];
      }

      c20_n1x = c20_b_norm(chartInstance, c20_f_x);
      for (c20_i994 = 0; c20_i994 < 9; c20_i994 = c20_i994 + 1) {
        c20_b_xinv[c20_i994] = c20_xinv[c20_i994];
      }

      c20_n1xinv = c20_b_norm(chartInstance, c20_b_xinv);
      c20_c_a = c20_n1x;
      c20_d_b = c20_n1xinv;
      c20_b_y = c20_c_a * c20_d_b;
      c20_rc = 1.0 / c20_b_y;
      if (c20_n1x == 0.0) {
      } else if (c20_n1xinv == 0.0) {
      } else if (c20_rc == 0.0) {
        goto label_2;
      } else {
        c20_g_x = c20_rc;
        c20_e_b = muDoubleScalarIsNaN(c20_g_x);
        if (c20_e_b) {
        } else if (c20_rc < 2.2204460492503131E-16) {
        } else {
          return;
        }

        c20_b_eml_warning(chartInstance, c20_rc);
        return;
      }

     label_2:
      ;
      c20_eml_warning(chartInstance);
    }
  } else {
    for (c20_i1008 = 0; c20_i1008 < 9; c20_i1008 = c20_i1008 + 1) {
      c20_c[c20_i1008] = 0.0;
    }

    for (c20_k = 1; c20_k < 4; c20_k = c20_k + 1) {
      c20_b_k = c20_k;
      c20_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c20_b_k), 1, 3, 1, 0) - 1) + 3 * (
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
        c20_b_k), 1, 3, 2, 0) - 1)] = 1.0;
    }
  }
}

static void c20_e_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_inv3x3(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_x[9], real_T c20_y[9])
{
  int32_T c20_p1;
  int32_T c20_p2;
  int32_T c20_p3;
  real_T c20_b_x;
  real_T c20_c_x;
  real_T c20_absx11;
  real_T c20_d_x;
  real_T c20_e_x;
  real_T c20_absx21;
  real_T c20_f_x;
  real_T c20_g_x;
  real_T c20_absx31;
  real_T c20_t1;
  real_T c20_h_x;
  real_T c20_b_y;
  real_T c20_i_x;
  real_T c20_c_y;
  real_T c20_z;
  real_T c20_j_x;
  real_T c20_d_y;
  real_T c20_k_x;
  real_T c20_e_y;
  real_T c20_b_z;
  real_T c20_a;
  real_T c20_b;
  real_T c20_f_y;
  real_T c20_b_a;
  real_T c20_b_b;
  real_T c20_g_y;
  real_T c20_c_a;
  real_T c20_c_b;
  real_T c20_h_y;
  real_T c20_d_a;
  real_T c20_d_b;
  real_T c20_i_y;
  real_T c20_l_x;
  real_T c20_m_x;
  real_T c20_j_y;
  real_T c20_n_x;
  real_T c20_o_x;
  real_T c20_k_y;
  int32_T c20_itmp;
  real_T c20_p_x;
  real_T c20_l_y;
  real_T c20_q_x;
  real_T c20_m_y;
  real_T c20_c_z;
  real_T c20_e_a;
  real_T c20_e_b;
  real_T c20_n_y;
  real_T c20_f_a;
  real_T c20_f_b;
  real_T c20_o_y;
  real_T c20_r_x;
  real_T c20_p_y;
  real_T c20_s_x;
  real_T c20_q_y;
  real_T c20_t3;
  real_T c20_g_a;
  real_T c20_g_b;
  real_T c20_r_y;
  real_T c20_t_x;
  real_T c20_s_y;
  real_T c20_u_x;
  real_T c20_t_y;
  real_T c20_t2;
  int32_T c20_h_a;
  int32_T c20_c;
  real_T c20_i_a;
  real_T c20_h_b;
  real_T c20_u_y;
  real_T c20_j_a;
  real_T c20_i_b;
  real_T c20_v_y;
  real_T c20_v_x;
  real_T c20_w_y;
  real_T c20_w_x;
  real_T c20_x_y;
  real_T c20_d_z;
  int32_T c20_k_a;
  int32_T c20_b_c;
  int32_T c20_l_a;
  int32_T c20_c_c;
  real_T c20_x_x;
  real_T c20_y_y;
  real_T c20_y_x;
  real_T c20_ab_y;
  real_T c20_m_a;
  real_T c20_j_b;
  real_T c20_bb_y;
  real_T c20_ab_x;
  real_T c20_cb_y;
  real_T c20_bb_x;
  real_T c20_db_y;
  int32_T c20_n_a;
  int32_T c20_d_c;
  real_T c20_o_a;
  real_T c20_k_b;
  real_T c20_eb_y;
  real_T c20_p_a;
  real_T c20_l_b;
  real_T c20_fb_y;
  real_T c20_cb_x;
  real_T c20_gb_y;
  real_T c20_db_x;
  real_T c20_hb_y;
  real_T c20_e_z;
  int32_T c20_q_a;
  int32_T c20_e_c;
  int32_T c20_r_a;
  int32_T c20_f_c;
  real_T c20_ib_y;
  real_T c20_jb_y;
  real_T c20_s_a;
  real_T c20_m_b;
  real_T c20_kb_y;
  real_T c20_eb_x;
  real_T c20_lb_y;
  real_T c20_fb_x;
  real_T c20_mb_y;
  int32_T c20_t_a;
  int32_T c20_g_c;
  real_T c20_u_a;
  real_T c20_n_b;
  real_T c20_nb_y;
  real_T c20_v_a;
  real_T c20_o_b;
  real_T c20_ob_y;
  real_T c20_gb_x;
  real_T c20_pb_y;
  real_T c20_hb_x;
  real_T c20_qb_y;
  real_T c20_f_z;
  int32_T c20_w_a;
  int32_T c20_h_c;
  int32_T c20_x_a;
  int32_T c20_i_c;
  c20_p1 = 0;
  c20_p2 = 3;
  c20_p3 = 6;
  c20_b_x = c20_x[0];
  c20_c_x = c20_b_x;
  c20_absx11 = muDoubleScalarAbs(c20_c_x);
  c20_d_x = c20_x[1];
  c20_e_x = c20_d_x;
  c20_absx21 = muDoubleScalarAbs(c20_e_x);
  c20_f_x = c20_x[2];
  c20_g_x = c20_f_x;
  c20_absx31 = muDoubleScalarAbs(c20_g_x);
  if (c20_absx21 > c20_absx11) {
    if (c20_absx21 > c20_absx31) {
      c20_p1 = 3;
      c20_p2 = 0;
      c20_t1 = c20_x[0];
      c20_x[0] = c20_x[1];
      c20_x[1] = c20_t1;
      c20_t1 = c20_x[3];
      c20_x[3] = c20_x[4];
      c20_x[4] = c20_t1;
      c20_t1 = c20_x[6];
      c20_x[6] = c20_x[7];
      c20_x[7] = c20_t1;
      goto label_1;
    }
  }

  if (c20_absx31 > c20_absx11) {
    c20_p1 = 6;
    c20_p3 = 0;
    c20_t1 = c20_x[0];
    c20_x[0] = c20_x[2];
    c20_x[2] = c20_t1;
    c20_t1 = c20_x[3];
    c20_x[3] = c20_x[5];
    c20_x[5] = c20_t1;
    c20_t1 = c20_x[6];
    c20_x[6] = c20_x[8];
    c20_x[8] = c20_t1;
  }

 label_1:
  ;
  c20_h_x = c20_x[1];
  c20_b_y = c20_x[0];
  c20_i_x = c20_h_x;
  c20_c_y = c20_b_y;
  c20_z = c20_i_x / c20_c_y;
  c20_x[1] = c20_z;
  c20_j_x = c20_x[2];
  c20_d_y = c20_x[0];
  c20_k_x = c20_j_x;
  c20_e_y = c20_d_y;
  c20_b_z = c20_k_x / c20_e_y;
  c20_x[2] = c20_b_z;
  c20_a = c20_x[1];
  c20_b = c20_x[3];
  c20_f_y = c20_a * c20_b;
  c20_x[4] = c20_x[4] - c20_f_y;
  c20_b_a = c20_x[2];
  c20_b_b = c20_x[3];
  c20_g_y = c20_b_a * c20_b_b;
  c20_x[5] = c20_x[5] - c20_g_y;
  c20_c_a = c20_x[1];
  c20_c_b = c20_x[6];
  c20_h_y = c20_c_a * c20_c_b;
  c20_x[7] = c20_x[7] - c20_h_y;
  c20_d_a = c20_x[2];
  c20_d_b = c20_x[6];
  c20_i_y = c20_d_a * c20_d_b;
  c20_x[8] = c20_x[8] - c20_i_y;
  c20_l_x = c20_x[5];
  c20_m_x = c20_l_x;
  c20_j_y = muDoubleScalarAbs(c20_m_x);
  c20_n_x = c20_x[4];
  c20_o_x = c20_n_x;
  c20_k_y = muDoubleScalarAbs(c20_o_x);
  if (c20_j_y > c20_k_y) {
    c20_itmp = c20_p2;
    c20_p2 = c20_p3;
    c20_p3 = c20_itmp;
    c20_t1 = c20_x[1];
    c20_x[1] = c20_x[2];
    c20_x[2] = c20_t1;
    c20_t1 = c20_x[4];
    c20_x[4] = c20_x[5];
    c20_x[5] = c20_t1;
    c20_t1 = c20_x[7];
    c20_x[7] = c20_x[8];
    c20_x[8] = c20_t1;
  }

  c20_p_x = c20_x[5];
  c20_l_y = c20_x[4];
  c20_q_x = c20_p_x;
  c20_m_y = c20_l_y;
  c20_c_z = c20_q_x / c20_m_y;
  c20_x[5] = c20_c_z;
  c20_e_a = c20_x[5];
  c20_e_b = c20_x[7];
  c20_n_y = c20_e_a * c20_e_b;
  c20_x[8] = c20_x[8] - c20_n_y;
  c20_f_a = c20_x[5];
  c20_f_b = c20_x[1];
  c20_o_y = c20_f_a * c20_f_b;
  c20_r_x = c20_o_y - c20_x[2];
  c20_p_y = c20_x[8];
  c20_s_x = c20_r_x;
  c20_q_y = c20_p_y;
  c20_t3 = c20_s_x / c20_q_y;
  c20_g_a = c20_x[7];
  c20_g_b = c20_t3;
  c20_r_y = c20_g_a * c20_g_b;
  c20_t_x = -(c20_x[1] + c20_r_y);
  c20_s_y = c20_x[4];
  c20_u_x = c20_t_x;
  c20_t_y = c20_s_y;
  c20_t2 = c20_u_x / c20_t_y;
  c20_h_a = c20_p1;
  c20_c = c20_h_a + 1;
  c20_i_a = c20_x[3];
  c20_h_b = c20_t2;
  c20_u_y = c20_i_a * c20_h_b;
  c20_j_a = c20_x[6];
  c20_i_b = c20_t3;
  c20_v_y = c20_j_a * c20_i_b;
  c20_v_x = (1.0 - c20_u_y) - c20_v_y;
  c20_w_y = c20_x[0];
  c20_w_x = c20_v_x;
  c20_x_y = c20_w_y;
  c20_d_z = c20_w_x / c20_x_y;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_c), 1, 9, 1, 0) - 1] = c20_d_z;
  c20_k_a = c20_p1;
  c20_b_c = c20_k_a + 2;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_b_c), 1, 9, 1, 0) - 1] = c20_t2;
  c20_l_a = c20_p1;
  c20_c_c = c20_l_a + 3;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_c_c), 1, 9, 1, 0) - 1] = c20_t3;
  c20_x_x = -c20_x[5];
  c20_y_y = c20_x[8];
  c20_y_x = c20_x_x;
  c20_ab_y = c20_y_y;
  c20_t3 = c20_y_x / c20_ab_y;
  c20_m_a = c20_x[7];
  c20_j_b = c20_t3;
  c20_bb_y = c20_m_a * c20_j_b;
  c20_ab_x = 1.0 - c20_bb_y;
  c20_cb_y = c20_x[4];
  c20_bb_x = c20_ab_x;
  c20_db_y = c20_cb_y;
  c20_t2 = c20_bb_x / c20_db_y;
  c20_n_a = c20_p2;
  c20_d_c = c20_n_a + 1;
  c20_o_a = c20_x[3];
  c20_k_b = c20_t2;
  c20_eb_y = c20_o_a * c20_k_b;
  c20_p_a = c20_x[6];
  c20_l_b = c20_t3;
  c20_fb_y = c20_p_a * c20_l_b;
  c20_cb_x = -(c20_eb_y + c20_fb_y);
  c20_gb_y = c20_x[0];
  c20_db_x = c20_cb_x;
  c20_hb_y = c20_gb_y;
  c20_e_z = c20_db_x / c20_hb_y;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_d_c), 1, 9, 1, 0) - 1] = c20_e_z;
  c20_q_a = c20_p2;
  c20_e_c = c20_q_a + 2;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_e_c), 1, 9, 1, 0) - 1] = c20_t2;
  c20_r_a = c20_p2;
  c20_f_c = c20_r_a + 3;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_f_c), 1, 9, 1, 0) - 1] = c20_t3;
  c20_ib_y = c20_x[8];
  c20_jb_y = c20_ib_y;
  c20_t3 = 1.0 / c20_jb_y;
  c20_s_a = -c20_x[7];
  c20_m_b = c20_t3;
  c20_kb_y = c20_s_a * c20_m_b;
  c20_eb_x = c20_kb_y;
  c20_lb_y = c20_x[4];
  c20_fb_x = c20_eb_x;
  c20_mb_y = c20_lb_y;
  c20_t2 = c20_fb_x / c20_mb_y;
  c20_t_a = c20_p3;
  c20_g_c = c20_t_a + 1;
  c20_u_a = c20_x[3];
  c20_n_b = c20_t2;
  c20_nb_y = c20_u_a * c20_n_b;
  c20_v_a = c20_x[6];
  c20_o_b = c20_t3;
  c20_ob_y = c20_v_a * c20_o_b;
  c20_gb_x = -(c20_nb_y + c20_ob_y);
  c20_pb_y = c20_x[0];
  c20_hb_x = c20_gb_x;
  c20_qb_y = c20_pb_y;
  c20_f_z = c20_hb_x / c20_qb_y;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_g_c), 1, 9, 1, 0) - 1] = c20_f_z;
  c20_w_a = c20_p3;
  c20_h_c = c20_w_a + 2;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_h_c), 1, 9, 1, 0) - 1] = c20_t2;
  c20_x_a = c20_p3;
  c20_i_c = c20_x_a + 3;
  c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c20_i_c), 1, 9, 1, 0) - 1] = c20_t3;
}

static real_T c20_b_norm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_x[9])
{
  real_T c20_y;
  int32_T c20_i1009;
  real_T c20_b_x[9];
  real_T c20_j;
  real_T c20_b_j;
  real_T c20_s;
  real_T c20_i;
  real_T c20_b_i;
  real_T c20_c_x;
  real_T c20_d_x;
  real_T c20_b_y;
  real_T c20_e_x;
  boolean_T c20_b;
  for (c20_i1009 = 0; c20_i1009 < 9; c20_i1009 = c20_i1009 + 1) {
    c20_b_x[c20_i1009] = c20_x[c20_i1009];
  }

  c20_y = 0.0;
  c20_j = 1.0;
 label_1:
  ;
  if (c20_j <= 3.0) {
    c20_b_j = c20_j;
    c20_s = 0.0;
    for (c20_i = 1.0; c20_i <= 3.0; c20_i = c20_i + 1.0) {
      c20_b_i = c20_i;
      c20_c_x = c20_b_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c20_b_i), 1, 3, 1, 0) - 1) + 3 * (
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c20_b_j),
        1, 3, 2, 0) - 1)];
      c20_d_x = c20_c_x;
      c20_b_y = muDoubleScalarAbs(c20_d_x);
      c20_s = c20_s + c20_b_y;
    }

    c20_e_x = c20_s;
    c20_b = muDoubleScalarIsNaN(c20_e_x);
    if (c20_b) {
      return rtNaN;
    } else {
      if (c20_s > c20_y) {
        c20_y = c20_s;
      }

      c20_j = c20_j + 1.0;
      goto label_1;
    }
  }

  return c20_y;
}

static void c20_eml_warning(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
  int32_T c20_i1010;
  static char_T c20_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i',
    'x' };

  char_T c20_u[21];
  const mxArray *c20_y = NULL;
  int32_T c20_i1011;
  static char_T c20_cv1[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't',
    'o', ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i',
    's', 'i', 'o', 'n', '.' };

  char_T c20_b_u[40];
  const mxArray *c20_b_y = NULL;
  for (c20_i1010 = 0; c20_i1010 < 21; c20_i1010 = c20_i1010 + 1) {
    c20_u[c20_i1010] = c20_cv0[c20_i1010];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c20_i1011 = 0; c20_i1011 < 40; c20_i1011 = c20_i1011 + 1) {
    c20_b_u[c20_i1011] = c20_cv1[c20_i1011];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c20_y, 14, c20_b_y);
}

static void c20_b_eps(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance)
{
}

static void c20_b_eml_warning(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_varargin_3)
{
  int32_T c20_i1012;
  static char_T c20_cv2[27] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'i', 'l', 'l',
    'C', 'o', 'n', 'd', 'i', 't', 'i', 'o', 'n', 'e',
    'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c20_u[27];
  const mxArray *c20_y = NULL;
  int32_T c20_i1013;
  static char_T c20_cv3[103] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's',
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

  char_T c20_b_u[103];
  const mxArray *c20_b_y = NULL;
  real_T c20_c_u;
  const mxArray *c20_c_y = NULL;
  for (c20_i1012 = 0; c20_i1012 < 27; c20_i1012 = c20_i1012 + 1) {
    c20_u[c20_i1012] = c20_cv2[c20_i1012];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 27));
  for (c20_i1013 = 0; c20_i1013 < 103; c20_i1013 = c20_i1013 + 1) {
    c20_b_u[c20_i1013] = c20_cv3[c20_i1013];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 103));
  c20_c_u = c20_varargin_3;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_call_debug("warning", 0U, 3U, 14, c20_y, 14, c20_b_y, 14, c20_c_y);
}

static real_T c20_power(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_a, real_T c20_b)
{
  real_T c20_ak;
  real_T c20_bk;
  real_T c20_x;
  real_T c20_b_x;
  c20_eml_scalar_eg(chartInstance);
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

static void c20_eml_error(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
  int32_T c20_i1014;
  static char_T c20_cv4[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c20_u[32];
  const mxArray *c20_y = NULL;
  int32_T c20_i1015;
  static char_T c20_cv5[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
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
  for (c20_i1014 = 0; c20_i1014 < 32; c20_i1014 = c20_i1014 + 1) {
    c20_u[c20_i1014] = c20_cv4[c20_i1014];
  }

  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", c20_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c20_i1015 = 0; c20_i1015 < 102; c20_i1015 = c20_i1015 + 1) {
    c20_b_u[c20_i1015] = c20_cv5[c20_i1015];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c20_y, 14, c20_b_y);
}

static void c20_mldivide(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[16], real_T c20_B[16], real_T
  c20_Y[16])
{
  int32_T c20_i1016;
  real_T c20_b_A[16];
  int32_T c20_i1017;
  real_T c20_b_B[16];
  int32_T c20_i1018;
  real_T c20_c_A[16];
  int32_T c20_i1019;
  real_T c20_c_B[16];
  int32_T c20_i1020;
  real_T c20_d_A[16];
  int32_T c20_i1021;
  real_T c20_e_A[16];
  int32_T c20_i1022;
  real_T c20_f_A[16];
  int32_T c20_i1023;
  real_T c20_g_A[16];
  int32_T c20_i1024;
  real_T c20_h_A[16];
  int32_T c20_info;
  int32_T c20_ipiv[4];
  real_T c20_i_A[16];
  int32_T c20_i1025;
  int32_T c20_i1026;
  int32_T c20_b_ipiv[4];
  int32_T c20_b_info;
  int32_T c20_i1027;
  int32_T c20_i1028;
  int32_T c20_c_ipiv[4];
  int32_T c20_c_info;
  int32_T c20_i1029;
  int32_T c20_i1030;
  int32_T c20_d_ipiv[4];
  int32_T c20_d_info;
  int32_T c20_i1031;
  int32_T c20_i;
  int32_T c20_b_i;
  int32_T c20_ip;
  int32_T c20_j;
  int32_T c20_b_j;
  real_T c20_temp;
  int32_T c20_i1032;
  real_T c20_j_A[16];
  int32_T c20_i1033;
  real_T c20_b_Y[16];
  int32_T c20_i1034;
  real_T c20_k_A[16];
  int32_T c20_i1035;
  real_T c20_d_B[16];
  int32_T c20_i1036;
  int32_T c20_i1037;
  real_T c20_l_A[16];
  int32_T c20_i1038;
  real_T c20_c_Y[16];
  for (c20_i1016 = 0; c20_i1016 < 16; c20_i1016 = c20_i1016 + 1) {
    c20_b_A[c20_i1016] = c20_A[c20_i1016];
  }

  for (c20_i1017 = 0; c20_i1017 < 16; c20_i1017 = c20_i1017 + 1) {
    c20_b_B[c20_i1017] = c20_B[c20_i1017];
  }

  for (c20_i1018 = 0; c20_i1018 < 16; c20_i1018 = c20_i1018 + 1) {
    c20_c_A[c20_i1018] = c20_b_A[c20_i1018];
  }

  for (c20_i1019 = 0; c20_i1019 < 16; c20_i1019 = c20_i1019 + 1) {
    c20_c_B[c20_i1019] = c20_b_B[c20_i1019];
  }

  for (c20_i1020 = 0; c20_i1020 < 16; c20_i1020 = c20_i1020 + 1) {
    c20_d_A[c20_i1020] = c20_c_A[c20_i1020];
  }

  for (c20_i1021 = 0; c20_i1021 < 16; c20_i1021 = c20_i1021 + 1) {
    c20_e_A[c20_i1021] = c20_d_A[c20_i1021];
  }

  for (c20_i1022 = 0; c20_i1022 < 16; c20_i1022 = c20_i1022 + 1) {
    c20_f_A[c20_i1022] = c20_e_A[c20_i1022];
  }

  for (c20_i1023 = 0; c20_i1023 < 16; c20_i1023 = c20_i1023 + 1) {
    c20_g_A[c20_i1023] = c20_f_A[c20_i1023];
  }

  for (c20_i1024 = 0; c20_i1024 < 16; c20_i1024 = c20_i1024 + 1) {
    c20_h_A[c20_i1024] = c20_g_A[c20_i1024];
  }

  c20_eml_matlab_zgetrf(chartInstance, c20_h_A, c20_i_A, c20_ipiv, &c20_info);
  for (c20_i1025 = 0; c20_i1025 < 16; c20_i1025 = c20_i1025 + 1) {
    c20_g_A[c20_i1025] = c20_i_A[c20_i1025];
  }

  for (c20_i1026 = 0; c20_i1026 < 4; c20_i1026 = c20_i1026 + 1) {
    c20_b_ipiv[c20_i1026] = c20_ipiv[c20_i1026];
  }

  c20_b_info = c20_info;
  for (c20_i1027 = 0; c20_i1027 < 16; c20_i1027 = c20_i1027 + 1) {
    c20_e_A[c20_i1027] = c20_g_A[c20_i1027];
  }

  for (c20_i1028 = 0; c20_i1028 < 4; c20_i1028 = c20_i1028 + 1) {
    c20_c_ipiv[c20_i1028] = c20_b_ipiv[c20_i1028];
  }

  c20_c_info = c20_b_info;
  for (c20_i1029 = 0; c20_i1029 < 16; c20_i1029 = c20_i1029 + 1) {
    c20_c_A[c20_i1029] = c20_e_A[c20_i1029];
  }

  for (c20_i1030 = 0; c20_i1030 < 4; c20_i1030 = c20_i1030 + 1) {
    c20_d_ipiv[c20_i1030] = c20_c_ipiv[c20_i1030];
  }

  c20_d_info = c20_c_info;
  if ((real_T)c20_d_info > 0.0) {
    c20_eml_warning(chartInstance);
  }

  c20_d_eml_scalar_eg(chartInstance);
  for (c20_i1031 = 0; c20_i1031 < 16; c20_i1031 = c20_i1031 + 1) {
    c20_Y[c20_i1031] = c20_c_B[c20_i1031];
  }

  for (c20_i = 1; c20_i < 5; c20_i = c20_i + 1) {
    c20_b_i = c20_i;
    if (c20_d_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c20_b_i), 1, 4, 1, 0) - 1] != c20_b_i) {
      c20_ip = c20_d_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c20_b_i), 1, 4, 1, 0) - 1];
      for (c20_j = 1; c20_j < 5; c20_j = c20_j + 1) {
        c20_b_j = c20_j;
        c20_temp = c20_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_i), 1, 4, 1, 0) - 1) + ((
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_j), 1, 4, 2, 0) - 1) << 2)];
        c20_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_b_i), 1, 4, 1, 0) - 1) + ((
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_j), 1, 4, 2, 0) - 1) << 2)] = c20_Y[(
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_ip), 1, 4, 1, 0) - 1) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(""
          , (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_b_j), 1, 4, 2, 0) - 1) <<
          2)];
        c20_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                 (real_T)c20_ip), 1, 4, 1, 0) - 1) + ((
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_j), 1, 4, 2, 0) - 1) << 2)] = c20_temp;
      }
    }
  }

  for (c20_i1032 = 0; c20_i1032 < 16; c20_i1032 = c20_i1032 + 1) {
    c20_j_A[c20_i1032] = c20_c_A[c20_i1032];
  }

  for (c20_i1033 = 0; c20_i1033 < 16; c20_i1033 = c20_i1033 + 1) {
    c20_b_Y[c20_i1033] = c20_Y[c20_i1033];
  }

  c20_eml_xtrsm(chartInstance, c20_j_A, c20_b_Y, c20_Y);
  for (c20_i1034 = 0; c20_i1034 < 16; c20_i1034 = c20_i1034 + 1) {
    c20_k_A[c20_i1034] = c20_c_A[c20_i1034];
  }

  for (c20_i1035 = 0; c20_i1035 < 16; c20_i1035 = c20_i1035 + 1) {
    c20_d_B[c20_i1035] = c20_Y[c20_i1035];
  }

  for (c20_i1036 = 0; c20_i1036 < 16; c20_i1036 = c20_i1036 + 1) {
    c20_Y[c20_i1036] = c20_d_B[c20_i1036];
  }

  for (c20_i1037 = 0; c20_i1037 < 16; c20_i1037 = c20_i1037 + 1) {
    c20_l_A[c20_i1037] = c20_k_A[c20_i1037];
  }

  for (c20_i1038 = 0; c20_i1038 < 16; c20_i1038 = c20_i1038 + 1) {
    c20_c_Y[c20_i1038] = c20_Y[c20_i1038];
  }

  c20_eml_blas_xtrsm(chartInstance, 4, 4, 1.0, c20_l_A, 1, 4, c20_c_Y, 1, 4,
                     c20_Y);
}

static void c20_eml_matlab_zgetrf(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[16], real_T c20_b_A[16],
  int32_T c20_ipiv[4], int32_T *c20_info)
{
  int32_T c20_i1039;
  int32_T c20_i1040;
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_a;
  int32_T c20_jm1;
  int32_T c20_b;
  int32_T c20_mmj;
  int32_T c20_b_a;
  int32_T c20_c;
  int32_T c20_b_b;
  int32_T c20_jj;
  int32_T c20_c_a;
  int32_T c20_jp1j;
  int32_T c20_d_a;
  int32_T c20_b_c;
  int32_T c20_i1041;
  real_T c20_c_A[16];
  int32_T c20_e_a;
  int32_T c20_jpiv_offset;
  int32_T c20_f_a;
  int32_T c20_c_b;
  int32_T c20_jpiv;
  int32_T c20_g_a;
  int32_T c20_d_b;
  int32_T c20_c_c;
  int32_T c20_e_b;
  int32_T c20_jrow;
  int32_T c20_h_a;
  int32_T c20_f_b;
  int32_T c20_jprow;
  int32_T c20_i1042;
  real_T c20_x[16];
  int32_T c20_ix0;
  int32_T c20_iy0;
  int32_T c20_i1043;
  int32_T c20_i1044;
  real_T c20_b_x[16];
  int32_T c20_b_ix0;
  int32_T c20_b_iy0;
  int32_T c20_i1045;
  real_T c20_c_x[16];
  int32_T c20_i1046;
  real_T c20_d_x[16];
  real_T c20_e_x[16];
  int32_T c20_i1047;
  int32_T c20_i1048;
  int32_T c20_b_jp1j;
  int32_T c20_i_a;
  int32_T c20_d_c;
  int32_T c20_j_a;
  int32_T c20_g_b;
  int32_T c20_loop_ub;
  int32_T c20_i;
  int32_T c20_b_i;
  real_T c20_f_x;
  real_T c20_y;
  real_T c20_g_x;
  real_T c20_b_y;
  real_T c20_z;
  int32_T c20_h_b;
  int32_T c20_e_c;
  int32_T c20_k_a;
  int32_T c20_f_c;
  int32_T c20_l_a;
  int32_T c20_g_c;
  int32_T c20_m;
  int32_T c20_n;
  int32_T c20_c_ix0;
  int32_T c20_c_iy0;
  int32_T c20_i1049;
  real_T c20_d_A[16];
  int32_T c20_ia0;
  int32_T c20_i1050;
  int32_T c20_b_m;
  int32_T c20_b_n;
  int32_T c20_d_ix0;
  int32_T c20_d_iy0;
  int32_T c20_i1051;
  real_T c20_e_A[16];
  int32_T c20_b_ia0;
  int32_T c20_i1052;
  int32_T c20_c_m;
  int32_T c20_c_n;
  int32_T c20_e_ix0;
  int32_T c20_e_iy0;
  int32_T c20_i1053;
  real_T c20_f_A[16];
  int32_T c20_c_ia0;
  int32_T c20_i1054;
  int32_T c20_i1055;
  real_T c20_g_A[16];
  for (c20_i1039 = 0; c20_i1039 < 16; c20_i1039 = c20_i1039 + 1) {
    c20_b_A[c20_i1039] = c20_A[c20_i1039];
  }

  c20_b_eps(chartInstance);
  for (c20_i1040 = 0; c20_i1040 < 4; c20_i1040 = c20_i1040 + 1) {
    c20_ipiv[c20_i1040] = 1 + c20_i1040;
  }

  *c20_info = 0;
  for (c20_j = 1; c20_j < 4; c20_j = c20_j + 1) {
    c20_b_j = c20_j;
    c20_a = c20_b_j;
    c20_jm1 = c20_a - 1;
    c20_b = c20_b_j;
    c20_mmj = 4 - c20_b;
    c20_b_a = c20_jm1;
    c20_c = c20_b_a * 5;
    c20_b_b = c20_c;
    c20_jj = 1 + c20_b_b;
    c20_c_a = c20_jj;
    c20_jp1j = c20_c_a + 1;
    c20_d_a = c20_mmj;
    c20_b_c = c20_d_a + 1;
    for (c20_i1041 = 0; c20_i1041 < 16; c20_i1041 = c20_i1041 + 1) {
      c20_c_A[c20_i1041] = c20_b_A[c20_i1041];
    }

    c20_e_a = c20_eml_ixamax(chartInstance, c20_b_c, c20_c_A, c20_jj);
    c20_jpiv_offset = c20_e_a - 1;
    c20_f_a = c20_jj;
    c20_c_b = c20_jpiv_offset;
    c20_jpiv = c20_f_a + c20_c_b;
    if (c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if ((real_T)c20_jpiv_offset != 0.0) {
        c20_g_a = c20_b_j;
        c20_d_b = c20_jpiv_offset;
        c20_c_c = c20_g_a + c20_d_b;
        c20_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_j), 1, 4, 1, 0) - 1] = c20_c_c;
        c20_e_b = c20_jm1;
        c20_jrow = 1 + c20_e_b;
        c20_h_a = c20_jrow;
        c20_f_b = c20_jpiv_offset;
        c20_jprow = c20_h_a + c20_f_b;
        for (c20_i1042 = 0; c20_i1042 < 16; c20_i1042 = c20_i1042 + 1) {
          c20_x[c20_i1042] = c20_b_A[c20_i1042];
        }

        c20_ix0 = c20_jrow;
        c20_iy0 = c20_jprow;
        for (c20_i1043 = 0; c20_i1043 < 16; c20_i1043 = c20_i1043 + 1) {
          c20_b_A[c20_i1043] = c20_x[c20_i1043];
        }

        for (c20_i1044 = 0; c20_i1044 < 16; c20_i1044 = c20_i1044 + 1) {
          c20_b_x[c20_i1044] = c20_b_A[c20_i1044];
        }

        c20_b_ix0 = c20_ix0;
        c20_b_iy0 = c20_iy0;
        for (c20_i1045 = 0; c20_i1045 < 16; c20_i1045 = c20_i1045 + 1) {
          c20_c_x[c20_i1045] = c20_b_x[c20_i1045];
        }

        for (c20_i1046 = 0; c20_i1046 < 16; c20_i1046 = c20_i1046 + 1) {
          c20_d_x[c20_i1046] = c20_c_x[c20_i1046];
        }

        c20_ceval_xswap(chartInstance, 4, c20_d_x, c20_b_ix0, 4, c20_b_iy0, 4,
                        c20_e_x);
        for (c20_i1047 = 0; c20_i1047 < 16; c20_i1047 = c20_i1047 + 1) {
          c20_c_x[c20_i1047] = c20_e_x[c20_i1047];
        }

        for (c20_i1048 = 0; c20_i1048 < 16; c20_i1048 = c20_i1048 + 1) {
          c20_b_A[c20_i1048] = c20_c_x[c20_i1048];
        }
      }

      c20_b_jp1j = c20_jp1j;
      c20_i_a = c20_mmj;
      c20_d_c = c20_i_a - 1;
      c20_j_a = c20_jp1j;
      c20_g_b = c20_d_c;
      c20_loop_ub = c20_j_a + c20_g_b;
      for (c20_i = c20_b_jp1j; c20_i <= c20_loop_ub; c20_i = c20_i + 1) {
        c20_b_i = c20_i;
        c20_f_x = c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_b_i), 1, 16, 1, 0) - 1];
        c20_y = c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_jj), 1, 16, 1, 0) - 1];
        c20_g_x = c20_f_x;
        c20_b_y = c20_y;
        c20_z = c20_g_x / c20_b_y;
        c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c20_b_i), 1, 16, 1, 0) - 1] = c20_z;
      }
    } else {
      *c20_info = c20_b_j;
    }

    c20_h_b = c20_b_j;
    c20_e_c = 4 - c20_h_b;
    c20_k_a = c20_jj;
    c20_f_c = c20_k_a + 4;
    c20_l_a = c20_jj;
    c20_g_c = c20_l_a + 5;
    c20_m = c20_mmj;
    c20_n = c20_e_c;
    c20_c_ix0 = c20_jp1j;
    c20_c_iy0 = c20_f_c;
    for (c20_i1049 = 0; c20_i1049 < 16; c20_i1049 = c20_i1049 + 1) {
      c20_d_A[c20_i1049] = c20_b_A[c20_i1049];
    }

    c20_ia0 = c20_g_c;
    for (c20_i1050 = 0; c20_i1050 < 16; c20_i1050 = c20_i1050 + 1) {
      c20_b_A[c20_i1050] = c20_d_A[c20_i1050];
    }

    c20_b_m = c20_m;
    c20_b_n = c20_n;
    c20_d_ix0 = c20_c_ix0;
    c20_d_iy0 = c20_c_iy0;
    for (c20_i1051 = 0; c20_i1051 < 16; c20_i1051 = c20_i1051 + 1) {
      c20_e_A[c20_i1051] = c20_b_A[c20_i1051];
    }

    c20_b_ia0 = c20_ia0;
    for (c20_i1052 = 0; c20_i1052 < 16; c20_i1052 = c20_i1052 + 1) {
      c20_b_A[c20_i1052] = c20_e_A[c20_i1052];
    }

    c20_c_m = c20_b_m;
    c20_c_n = c20_b_n;
    c20_e_ix0 = c20_d_ix0;
    c20_e_iy0 = c20_d_iy0;
    for (c20_i1053 = 0; c20_i1053 < 16; c20_i1053 = c20_i1053 + 1) {
      c20_f_A[c20_i1053] = c20_b_A[c20_i1053];
    }

    c20_c_ia0 = c20_b_ia0;
    for (c20_i1054 = 0; c20_i1054 < 16; c20_i1054 = c20_i1054 + 1) {
      c20_b_A[c20_i1054] = c20_f_A[c20_i1054];
    }

    if ((real_T)c20_c_m < 1.0) {
    } else if ((real_T)c20_c_n < 1.0) {
    } else {
      for (c20_i1055 = 0; c20_i1055 < 16; c20_i1055 = c20_i1055 + 1) {
        c20_g_A[c20_i1055] = c20_b_A[c20_i1055];
      }

      c20_ceval_xger(chartInstance, c20_c_m, c20_c_n, -1.0, c20_e_ix0, 1,
                     c20_e_iy0, 4, c20_g_A, c20_c_ia0, 4, c20_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c20_info == 0.0) {
    if (!(c20_b_A[15] != 0.0)) {
      *c20_info = 4;
      return;
    }
  }
}

static int32_T c20_eml_ixamax(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[16], int32_T
  c20_ix0)
{
  int32_T c20_b_n;
  int32_T c20_i1056;
  real_T c20_b_x[16];
  int32_T c20_b_ix0;
  int32_T c20_i1057;
  real_T c20_c_x[16];
  c20_b_n = c20_n;
  for (c20_i1056 = 0; c20_i1056 < 16; c20_i1056 = c20_i1056 + 1) {
    c20_b_x[c20_i1056] = c20_x[c20_i1056];
  }

  c20_b_ix0 = c20_ix0;
  for (c20_i1057 = 0; c20_i1057 < 16; c20_i1057 = c20_i1057 + 1) {
    c20_c_x[c20_i1057] = c20_b_x[c20_i1057];
  }

  return c20_ceval_ixamax(chartInstance, c20_b_n, c20_c_x, c20_b_ix0, 1);
}

static int32_T c20_ceval_ixamax(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[16], int32_T
  c20_ix0, int32_T c20_incx)
{
  return idamax32(&c20_n, &c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c20_ix0), 1, 16, 1, 0) - 1],
                  &c20_incx);
}

static void c20_ceval_xswap(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[16], int32_T
  c20_ix0, int32_T c20_incx, int32_T c20_iy0, int32_T c20_incy, real_T c20_b_x
  [16])
{
  int32_T c20_i1058;

  /* Empty Loop. */
  for (c20_i1058 = 0; c20_i1058 < 16; c20_i1058 = c20_i1058 + 1) {
    c20_b_x[c20_i1058] = c20_x[c20_i1058];
  }

  dswap32(&c20_n, &c20_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c20_ix0), 1, 16, 1, 0) - 1], &
          c20_incx, &c20_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c20_iy0), 1, 16, 1, 0) - 1], &c20_incy);
}

static void c20_ceval_xger(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_m, int32_T c20_n, real_T
  c20_alpha1, int32_T c20_ix0, int32_T c20_incx, int32_T c20_iy0, int32_T
  c20_incy, real_T c20_A[16], int32_T c20_ia0, int32_T c20_lda
  , real_T c20_b_A[16])
{
  int32_T c20_i1059;
  for (c20_i1059 = 0; c20_i1059 < 16; c20_i1059 = c20_i1059 + 1) {
    c20_b_A[c20_i1059] = c20_A[c20_i1059];
  }

  dger32(&c20_m, &c20_n, &c20_alpha1, &c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_ix0), 1, 16
          , 1, 0) - 1], &c20_incx, &c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c20_iy0), 1, 16, 1, 0) - 1
         ], &c20_incy, &c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c20_ia0), 1, 16, 1, 0) - 1], &c20_lda
         );
}

static void c20_eml_xtrsm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[16], real_T c20_B[16], real_T
  c20_b_B[16])
{
  int32_T c20_i1060;
  int32_T c20_i1061;
  real_T c20_b_A[16];
  int32_T c20_i1062;
  real_T c20_c_B[16];
  int32_T c20_i1063;
  int32_T c20_i1064;
  real_T c20_c_A[16];
  int32_T c20_i1065;
  real_T c20_d_B[16];
  int32_T c20_i1066;
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_a;
  int32_T c20_c;
  int32_T c20_b;
  int32_T c20_b_c;
  int32_T c20_b_b;
  int32_T c20_jBcol;
  int32_T c20_k;
  int32_T c20_b_k;
  int32_T c20_b_a;
  int32_T c20_c_c;
  int32_T c20_c_b;
  int32_T c20_d_c;
  int32_T c20_d_b;
  int32_T c20_kAcol;
  int32_T c20_c_a;
  int32_T c20_e_b;
  int32_T c20_e_c;
  int32_T c20_d_a;
  int32_T c20_i1067;
  int32_T c20_i;
  int32_T c20_b_i;
  int32_T c20_e_a;
  int32_T c20_f_b;
  int32_T c20_f_c;
  int32_T c20_f_a;
  int32_T c20_g_b;
  int32_T c20_g_c;
  int32_T c20_g_a;
  int32_T c20_h_b;
  int32_T c20_h_c;
  int32_T c20_h_a;
  int32_T c20_i_b;
  int32_T c20_i_c;
  for (c20_i1060 = 0; c20_i1060 < 16; c20_i1060 = c20_i1060 + 1) {
    c20_b_B[c20_i1060] = c20_B[c20_i1060];
  }

  for (c20_i1061 = 0; c20_i1061 < 16; c20_i1061 = c20_i1061 + 1) {
    c20_b_A[c20_i1061] = c20_A[c20_i1061];
  }

  for (c20_i1062 = 0; c20_i1062 < 16; c20_i1062 = c20_i1062 + 1) {
    c20_c_B[c20_i1062] = c20_b_B[c20_i1062];
  }

  for (c20_i1063 = 0; c20_i1063 < 16; c20_i1063 = c20_i1063 + 1) {
    c20_b_B[c20_i1063] = c20_c_B[c20_i1063];
  }

  for (c20_i1064 = 0; c20_i1064 < 16; c20_i1064 = c20_i1064 + 1) {
    c20_c_A[c20_i1064] = c20_b_A[c20_i1064];
  }

  for (c20_i1065 = 0; c20_i1065 < 16; c20_i1065 = c20_i1065 + 1) {
    c20_d_B[c20_i1065] = c20_b_B[c20_i1065];
  }

  for (c20_i1066 = 0; c20_i1066 < 16; c20_i1066 = c20_i1066 + 1) {
    c20_b_B[c20_i1066] = c20_d_B[c20_i1066];
  }

  c20_f_eml_scalar_eg(chartInstance);
  for (c20_j = 1; c20_j <= 4; c20_j = c20_j + 1) {
    c20_b_j = c20_j;
    c20_a = c20_b_j;
    c20_c = c20_a - 1;
    c20_b = c20_c;
    c20_b_c = c20_b << 2;
    c20_b_b = c20_b_c;
    c20_jBcol = c20_b_b;
    for (c20_k = 1; c20_k <= 4; c20_k = c20_k + 1) {
      c20_b_k = c20_k;
      c20_b_a = c20_b_k;
      c20_c_c = c20_b_a - 1;
      c20_c_b = c20_c_c;
      c20_d_c = c20_c_b << 2;
      c20_d_b = c20_d_c;
      c20_kAcol = c20_d_b;
      c20_c_a = c20_b_k;
      c20_e_b = c20_jBcol;
      c20_e_c = c20_c_a + c20_e_b;
      if (c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_e_c), 1, 16, 1, 0) - 1] != 0.0) {
        c20_d_a = c20_b_k;
        c20_i1067 = c20_d_a + 1;
        for (c20_i = c20_i1067; c20_i <= 4; c20_i = c20_i + 1) {
          c20_b_i = c20_i;
          c20_e_a = c20_b_i;
          c20_f_b = c20_jBcol;
          c20_f_c = c20_e_a + c20_f_b;
          c20_f_a = c20_b_i;
          c20_g_b = c20_jBcol;
          c20_g_c = c20_f_a + c20_g_b;
          c20_g_a = c20_b_k;
          c20_h_b = c20_jBcol;
          c20_h_c = c20_g_a + c20_h_b;
          c20_h_a = c20_b_i;
          c20_i_b = c20_kAcol;
          c20_i_c = c20_h_a + c20_i_b;
          c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_f_c), 1, 16, 1, 0) - 1] = c20_b_B[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_g_c), 1, 16, 1, 0) - 1] - c20_b_B[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_h_c), 1, 16, 1, 0) - 1] * c20_c_A[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_i_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void c20_f_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_eml_blas_xtrsm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_m, int32_T c20_n, real_T
  c20_alpha1, real_T c20_A[16], int32_T c20_ia0, int32_T c20_lda, real_T c20_B
  [16], int32_T c20_ib0, int32_T c20_ldb, real_T c20_b_B[
  16])
{
  int32_T c20_i1068;
  int32_T c20_b_m;
  int32_T c20_b_n;
  real_T c20_b_alpha1;
  int32_T c20_i1069;
  real_T c20_b_A[16];
  int32_T c20_b_ia0;
  int32_T c20_b_lda;
  int32_T c20_i1070;
  real_T c20_c_B[16];
  int32_T c20_b_ib0;
  int32_T c20_b_ldb;
  int32_T c20_i1071;
  boolean_T c20_NON_UNIT_ALPHA;
  int32_T c20_a;
  int32_T c20_Aoffset;
  int32_T c20_b_a;
  int32_T c20_Boffset;
  int32_T c20_loop_ub;
  int32_T c20_j;
  int32_T c20_b_j;
  int32_T c20_c_a;
  int32_T c20_c;
  int32_T c20_d_a;
  int32_T c20_b;
  int32_T c20_b_c;
  int32_T c20_e_a;
  int32_T c20_b_b;
  int32_T c20_jBcol;
  int32_T c20_b_loop_ub;
  int32_T c20_i;
  int32_T c20_b_i;
  int32_T c20_f_a;
  int32_T c20_c_b;
  int32_T c20_c_c;
  int32_T c20_c_loop_ub;
  int32_T c20_c_j;
  int32_T c20_g_a;
  int32_T c20_d_c;
  int32_T c20_h_a;
  int32_T c20_d_b;
  int32_T c20_e_c;
  int32_T c20_i_a;
  int32_T c20_e_b;
  int32_T c20_d_loop_ub;
  int32_T c20_c_i;
  int32_T c20_j_a;
  int32_T c20_f_b;
  int32_T c20_f_c;
  int32_T c20_k_a;
  int32_T c20_g_b;
  int32_T c20_g_c;
  int32_T c20_c_m;
  int32_T c20_k;
  int32_T c20_b_k;
  int32_T c20_l_a;
  int32_T c20_h_c;
  int32_T c20_m_a;
  int32_T c20_h_b;
  int32_T c20_i_c;
  int32_T c20_n_a;
  int32_T c20_i_b;
  int32_T c20_kAcol;
  int32_T c20_o_a;
  int32_T c20_j_b;
  int32_T c20_j_c;
  int32_T c20_p_a;
  int32_T c20_k_b;
  int32_T c20_k_c;
  int32_T c20_q_a;
  int32_T c20_l_b;
  int32_T c20_l_c;
  int32_T c20_r_a;
  int32_T c20_m_b;
  int32_T c20_m_c;
  real_T c20_x;
  real_T c20_y;
  real_T c20_b_x;
  real_T c20_b_y;
  real_T c20_z;
  int32_T c20_s_a;
  int32_T c20_e_loop_ub;
  int32_T c20_d_i;
  int32_T c20_t_a;
  int32_T c20_n_b;
  int32_T c20_n_c;
  int32_T c20_u_a;
  int32_T c20_o_b;
  int32_T c20_o_c;
  int32_T c20_v_a;
  int32_T c20_p_b;
  int32_T c20_p_c;
  int32_T c20_w_a;
  int32_T c20_q_b;
  int32_T c20_q_c;
  for (c20_i1068 = 0; c20_i1068 < 16; c20_i1068 = c20_i1068 + 1) {
    c20_b_B[c20_i1068] = c20_B[c20_i1068];
  }

  c20_b_m = c20_m;
  c20_b_n = c20_n;
  c20_b_alpha1 = c20_alpha1;
  for (c20_i1069 = 0; c20_i1069 < 16; c20_i1069 = c20_i1069 + 1) {
    c20_b_A[c20_i1069] = c20_A[c20_i1069];
  }

  c20_b_ia0 = c20_ia0;
  c20_b_lda = c20_lda;
  for (c20_i1070 = 0; c20_i1070 < 16; c20_i1070 = c20_i1070 + 1) {
    c20_c_B[c20_i1070] = c20_b_B[c20_i1070];
  }

  c20_b_ib0 = c20_ib0;
  c20_b_ldb = c20_ldb;
  for (c20_i1071 = 0; c20_i1071 < 16; c20_i1071 = c20_i1071 + 1) {
    c20_b_B[c20_i1071] = c20_c_B[c20_i1071];
  }

  c20_NON_UNIT_ALPHA = (c20_b_alpha1 != 1.0);
  if ((real_T)c20_b_n == 0.0) {
  } else {
    c20_f_eml_scalar_eg(chartInstance);
    c20_a = c20_b_ia0;
    c20_Aoffset = c20_a - 1;
    c20_b_a = c20_b_ib0;
    c20_Boffset = c20_b_a - 1;
    if (c20_b_alpha1 == 0.0) {
      c20_loop_ub = c20_b_n;
      for (c20_j = 1; c20_j <= c20_loop_ub; c20_j = c20_j + 1) {
        c20_b_j = c20_j;
        c20_c_a = c20_b_j;
        c20_c = c20_c_a - 1;
        c20_d_a = c20_b_ldb;
        c20_b = c20_c;
        c20_b_c = c20_d_a * c20_b;
        c20_e_a = c20_Boffset;
        c20_b_b = c20_b_c;
        c20_jBcol = c20_e_a + c20_b_b;
        c20_b_loop_ub = c20_b_m;
        for (c20_i = 1; c20_i <= c20_b_loop_ub; c20_i = c20_i + 1) {
          c20_b_i = c20_i;
          c20_f_a = c20_b_i;
          c20_c_b = c20_jBcol;
          c20_c_c = c20_f_a + c20_c_b;
          c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c20_c_c), 1, 16, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c20_c_loop_ub = c20_b_n;
      for (c20_c_j = 1; c20_c_j <= c20_c_loop_ub; c20_c_j = c20_c_j + 1) {
        c20_b_j = c20_c_j;
        c20_g_a = c20_b_j;
        c20_d_c = c20_g_a - 1;
        c20_h_a = c20_b_ldb;
        c20_d_b = c20_d_c;
        c20_e_c = c20_h_a * c20_d_b;
        c20_i_a = c20_Boffset;
        c20_e_b = c20_e_c;
        c20_jBcol = c20_i_a + c20_e_b;
        if (c20_NON_UNIT_ALPHA) {
          c20_d_loop_ub = c20_b_m;
          for (c20_c_i = 1; c20_c_i <= c20_d_loop_ub; c20_c_i = c20_c_i + 1) {
            c20_b_i = c20_c_i;
            c20_j_a = c20_b_i;
            c20_f_b = c20_jBcol;
            c20_f_c = c20_j_a + c20_f_b;
            c20_k_a = c20_b_i;
            c20_g_b = c20_jBcol;
            c20_g_c = c20_k_a + c20_g_b;
            c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c20_f_c), 1, 16, 1, 0) - 1] = c20_b_alpha1 * c20_b_B
              [_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c20_g_c), 1, 16, 1, 0) - 1];
          }
        }

        c20_c_m = c20_b_m;
        for (c20_k = c20_c_m; c20_k > 0; c20_k = c20_k + -1) {
          c20_b_k = c20_k;
          c20_l_a = c20_b_k;
          c20_h_c = c20_l_a - 1;
          c20_m_a = c20_b_lda;
          c20_h_b = c20_h_c;
          c20_i_c = c20_m_a * c20_h_b;
          c20_n_a = c20_Aoffset;
          c20_i_b = c20_i_c;
          c20_kAcol = c20_n_a + c20_i_b;
          c20_o_a = c20_b_k;
          c20_j_b = c20_jBcol;
          c20_j_c = c20_o_a + c20_j_b;
          if (c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
               _SFD_INTEGER_CHECK("", (real_T)c20_j_c), 1, 16, 1, 0) - 1] != 0.0)
          {
            c20_p_a = c20_b_k;
            c20_k_b = c20_jBcol;
            c20_k_c = c20_p_a + c20_k_b;
            c20_q_a = c20_b_k;
            c20_l_b = c20_jBcol;
            c20_l_c = c20_q_a + c20_l_b;
            c20_r_a = c20_b_k;
            c20_m_b = c20_kAcol;
            c20_m_c = c20_r_a + c20_m_b;
            c20_x = c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_l_c), 1, 16, 1, 0) - 1];
            c20_y = c20_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c20_m_c), 1, 16, 1, 0) - 1];
            c20_b_x = c20_x;
            c20_b_y = c20_y;
            c20_z = c20_b_x / c20_b_y;
            c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c20_k_c), 1, 16, 1, 0) - 1] = c20_z;
            c20_s_a = c20_b_k;
            c20_e_loop_ub = c20_s_a - 1;
            for (c20_d_i = 1; c20_d_i <= c20_e_loop_ub; c20_d_i = c20_d_i + 1) {
              c20_b_i = c20_d_i;
              c20_t_a = c20_b_i;
              c20_n_b = c20_jBcol;
              c20_n_c = c20_t_a + c20_n_b;
              c20_u_a = c20_b_i;
              c20_o_b = c20_jBcol;
              c20_o_c = c20_u_a + c20_o_b;
              c20_v_a = c20_b_k;
              c20_p_b = c20_jBcol;
              c20_p_c = c20_v_a + c20_p_b;
              c20_w_a = c20_b_i;
              c20_q_b = c20_kAcol;
              c20_q_c = c20_w_a + c20_q_b;
              c20_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c20_n_c), 1, 16, 1, 0) - 1] =
                c20_b_B[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c20_o_c), 1, 16, 1, 0) - 1] - c20_b_B[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c20_p_c), 1, 16, 1, 0) - 1] * c20_b_A[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c20_q_c), 1, 16, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static void c20_Adj(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                    real_T c20_g[16], real_T c20_Adg[36])
{
  uint32_T c20_debug_family_var_map[7];
  static const char *c20_sv3[7] = { "R", "P", "P_hat", "nargin", "nargout", "g",
    "Adg" };

  real_T c20_R[9];
  real_T c20_P[3];
  real_T c20_P_hat[9];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i1072;
  int32_T c20_i1073;
  int32_T c20_i1074;
  int32_T c20_i1075;
  int32_T c20_i1076;
  int32_T c20_i1077;
  real_T c20_w[3];
  uint32_T c20_b_debug_family_var_map[4];
  static const char *c20_sv4[4] = { "nargin", "nargout", "w", "W" };

  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  int32_T c20_i1078;
  real_T c20_a[9];
  int32_T c20_i1079;
  real_T c20_b[9];
  int32_T c20_i1080;
  real_T c20_A[9];
  int32_T c20_i1081;
  real_T c20_B[9];
  int32_T c20_i1082;
  real_T c20_b_A[9];
  int32_T c20_i1083;
  real_T c20_b_B[9];
  int32_T c20_i1084;
  real_T c20_c_A[9];
  int32_T c20_i1085;
  real_T c20_c_B[9];
  int32_T c20_i1086;
  int32_T c20_i1087;
  int32_T c20_i1088;
  real_T c20_y[9];
  int32_T c20_i1089;
  int32_T c20_i1090;
  int32_T c20_i1091;
  int32_T c20_i1092;
  int32_T c20_i1093;
  int32_T c20_i1094;
  int32_T c20_i1095;
  int32_T c20_i1096;
  int32_T c20_i1097;
  int32_T c20_i1098;
  int32_T c20_i1099;
  int32_T c20_i1100;
  int32_T c20_i1101;
  int32_T c20_i1102;
  int32_T c20_i1103;
  int32_T c20_i1104;
  int32_T c20_i1105;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c20_sv3, c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c20_R, c20_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c20_P, c20_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_P_hat, c20_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c20_g, c20_g_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c20_Adg, c20_h_sf_marshall, 6U);
  CV_SCRIPT_FCN(7, 0);

  /*  Adjoint transformation matrix Adg of transform g */
  _SFD_SCRIPT_CALL(7, 3);
  c20_i1072 = 0;
  c20_i1073 = 0;
  for (c20_i1074 = 0; c20_i1074 < 3; c20_i1074 = c20_i1074 + 1) {
    for (c20_i1075 = 0; c20_i1075 < 3; c20_i1075 = c20_i1075 + 1) {
      c20_R[c20_i1075 + c20_i1072] = c20_g[c20_i1075 + c20_i1073];
    }

    c20_i1072 = c20_i1072 + 3;
    c20_i1073 = c20_i1073 + 4;
  }

  _SFD_SCRIPT_CALL(7, 4);
  for (c20_i1076 = 0; c20_i1076 < 3; c20_i1076 = c20_i1076 + 1) {
    c20_P[c20_i1076] = c20_g[c20_i1076 + 12];
  }

  _SFD_SCRIPT_CALL(7, 5);
  for (c20_i1077 = 0; c20_i1077 < 3; c20_i1077 = c20_i1077 + 1) {
    c20_w[c20_i1077] = c20_P[c20_i1077];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_sv4, c20_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_b_nargin, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_b_nargout, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_w, c20_f_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_P_hat, c20_e_sf_marshall, 3U);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6, 2);
  c20_P_hat[0] = 0.0;
  c20_P_hat[3] = -c20_w[2];
  c20_P_hat[6] = c20_w[1];
  c20_P_hat[1] = c20_w[2];
  c20_P_hat[4] = 0.0;
  c20_P_hat[7] = -c20_w[0];
  c20_P_hat[2] = -c20_w[1];
  c20_P_hat[5] = c20_w[0];
  c20_P_hat[8] = 0.0;
  _SFD_SCRIPT_CALL(6, -2);
  sf_debug_symbol_scope_pop();
  _SFD_SCRIPT_CALL(7, 7);
  for (c20_i1078 = 0; c20_i1078 < 9; c20_i1078 = c20_i1078 + 1) {
    c20_a[c20_i1078] = c20_P_hat[c20_i1078];
  }

  for (c20_i1079 = 0; c20_i1079 < 9; c20_i1079 = c20_i1079 + 1) {
    c20_b[c20_i1079] = c20_R[c20_i1079];
  }

  c20_b_eml_scalar_eg(chartInstance);
  c20_b_eml_scalar_eg(chartInstance);
  for (c20_i1080 = 0; c20_i1080 < 9; c20_i1080 = c20_i1080 + 1) {
    c20_A[c20_i1080] = c20_a[c20_i1080];
  }

  for (c20_i1081 = 0; c20_i1081 < 9; c20_i1081 = c20_i1081 + 1) {
    c20_B[c20_i1081] = c20_b[c20_i1081];
  }

  for (c20_i1082 = 0; c20_i1082 < 9; c20_i1082 = c20_i1082 + 1) {
    c20_b_A[c20_i1082] = c20_A[c20_i1082];
  }

  for (c20_i1083 = 0; c20_i1083 < 9; c20_i1083 = c20_i1083 + 1) {
    c20_b_B[c20_i1083] = c20_B[c20_i1083];
  }

  for (c20_i1084 = 0; c20_i1084 < 9; c20_i1084 = c20_i1084 + 1) {
    c20_c_A[c20_i1084] = c20_b_A[c20_i1084];
  }

  for (c20_i1085 = 0; c20_i1085 < 9; c20_i1085 = c20_i1085 + 1) {
    c20_c_B[c20_i1085] = c20_b_B[c20_i1085];
  }

  for (c20_i1086 = 0; c20_i1086 < 3; c20_i1086 = c20_i1086 + 1) {
    c20_i1087 = 0;
    for (c20_i1088 = 0; c20_i1088 < 3; c20_i1088 = c20_i1088 + 1) {
      c20_y[c20_i1087 + c20_i1086] = 0.0;
      c20_i1089 = 0;
      for (c20_i1090 = 0; c20_i1090 < 3; c20_i1090 = c20_i1090 + 1) {
        c20_y[c20_i1087 + c20_i1086] = c20_y[c20_i1087 + c20_i1086] +
          c20_c_A[c20_i1089 + c20_i1086] * c20_c_B[c20_i1090 + c20_i1087];
        c20_i1089 = c20_i1089 + 3;
      }

      c20_i1087 = c20_i1087 + 3;
    }
  }

  c20_i1091 = 0;
  c20_i1092 = 0;
  for (c20_i1093 = 0; c20_i1093 < 3; c20_i1093 = c20_i1093 + 1) {
    for (c20_i1094 = 0; c20_i1094 < 3; c20_i1094 = c20_i1094 + 1) {
      c20_Adg[c20_i1094 + c20_i1091] = c20_R[c20_i1094 + c20_i1092];
    }

    c20_i1091 = c20_i1091 + 6;
    c20_i1092 = c20_i1092 + 3;
  }

  c20_i1095 = 0;
  c20_i1096 = 0;
  for (c20_i1097 = 0; c20_i1097 < 3; c20_i1097 = c20_i1097 + 1) {
    for (c20_i1098 = 0; c20_i1098 < 3; c20_i1098 = c20_i1098 + 1) {
      c20_Adg[(c20_i1098 + c20_i1095) + 18] = c20_y[c20_i1098 + c20_i1096];
    }

    c20_i1095 = c20_i1095 + 6;
    c20_i1096 = c20_i1096 + 3;
  }

  c20_i1099 = 0;
  for (c20_i1100 = 0; c20_i1100 < 3; c20_i1100 = c20_i1100 + 1) {
    for (c20_i1101 = 0; c20_i1101 < 3; c20_i1101 = c20_i1101 + 1) {
      c20_Adg[(c20_i1101 + c20_i1099) + 3] = 0.0;
    }

    c20_i1099 = c20_i1099 + 6;
  }

  c20_i1102 = 0;
  c20_i1103 = 0;
  for (c20_i1104 = 0; c20_i1104 < 3; c20_i1104 = c20_i1104 + 1) {
    for (c20_i1105 = 0; c20_i1105 < 3; c20_i1105 = c20_i1105 + 1) {
      c20_Adg[(c20_i1105 + c20_i1102) + 21] = c20_R[c20_i1105 + c20_i1103];
    }

    c20_i1102 = c20_i1102 + 6;
    c20_i1103 = c20_i1103 + 3;
  }

  _SFD_SCRIPT_CALL(7, -7);
  sf_debug_symbol_scope_pop();
}

static void c20_g_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_eml_xgemm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, real_T c20_A[36], real_T c20_B[6], real_T
  c20_C[6], real_T c20_b_C[6])
{
  int32_T c20_i1106;
  real_T c20_b_A[36];
  int32_T c20_i1107;
  real_T c20_b_B[6];
  int32_T c20_i1108;
  real_T c20_c_A[36];
  int32_T c20_i1109;
  real_T c20_c_B[6];
  int32_T c20_i1110;
  int32_T c20_i1111;
  int32_T c20_i1112;
  for (c20_i1106 = 0; c20_i1106 < 36; c20_i1106 = c20_i1106 + 1) {
    c20_b_A[c20_i1106] = c20_A[c20_i1106];
  }

  for (c20_i1107 = 0; c20_i1107 < 6; c20_i1107 = c20_i1107 + 1) {
    c20_b_B[c20_i1107] = c20_B[c20_i1107];
  }

  for (c20_i1108 = 0; c20_i1108 < 36; c20_i1108 = c20_i1108 + 1) {
    c20_c_A[c20_i1108] = c20_b_A[c20_i1108];
  }

  for (c20_i1109 = 0; c20_i1109 < 6; c20_i1109 = c20_i1109 + 1) {
    c20_c_B[c20_i1109] = c20_b_B[c20_i1109];
  }

  for (c20_i1110 = 0; c20_i1110 < 6; c20_i1110 = c20_i1110 + 1) {
    c20_b_C[c20_i1110] = 0.0;
    c20_i1111 = 0;
    for (c20_i1112 = 0; c20_i1112 < 6; c20_i1112 = c20_i1112 + 1) {
      c20_b_C[c20_i1110] = c20_b_C[c20_i1110] + c20_c_A[c20_i1111 + c20_i1110] *
        c20_c_B[c20_i1112];
      c20_i1111 = c20_i1111 + 6;
    }
  }
}

static void c20_ad(SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance,
                   real_T c20_xi[6], real_T c20_adx[36])
{
  uint32_T c20_debug_family_var_map[6];
  static const char *c20_sv5[6] = { "w", "v", "nargin", "nargout", "xi", "adx" };

  real_T c20_w[3];
  real_T c20_v[3];
  real_T c20_nargin = 1.0;
  real_T c20_nargout = 1.0;
  int32_T c20_i1113;
  int32_T c20_i1114;
  int32_T c20_i1115;
  real_T c20_b_w[3];
  uint32_T c20_b_debug_family_var_map[4];
  static const char *c20_sv6[4] = { "nargin", "nargout", "w", "W" };

  real_T c20_b_nargin = 1.0;
  real_T c20_b_nargout = 1.0;
  real_T c20_W[9];
  int32_T c20_i1116;
  real_T c20_c_w[3];
  uint32_T c20_c_debug_family_var_map[4];
  real_T c20_c_nargin = 1.0;
  real_T c20_c_nargout = 1.0;
  real_T c20_b_W[9];
  int32_T c20_i1117;
  real_T c20_d_w[3];
  uint32_T c20_d_debug_family_var_map[4];
  real_T c20_d_nargin = 1.0;
  real_T c20_d_nargout = 1.0;
  real_T c20_c_W[9];
  int32_T c20_i1118;
  int32_T c20_i1119;
  int32_T c20_i1120;
  int32_T c20_i1121;
  int32_T c20_i1122;
  int32_T c20_i1123;
  int32_T c20_i1124;
  int32_T c20_i1125;
  int32_T c20_i1126;
  int32_T c20_i1127;
  int32_T c20_i1128;
  int32_T c20_i1129;
  int32_T c20_i1130;
  int32_T c20_i1131;
  int32_T c20_i1132;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c20_sv5, c20_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c20_w, c20_f_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c20_v, c20_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c20_nargin, c20_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c20_nargout, c20_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c20_xi, c20_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c20_adx, c20_h_sf_marshall, 5U);
  CV_SCRIPT_FCN(8, 0);
  _SFD_SCRIPT_CALL(8, 2);
  for (c20_i1113 = 0; c20_i1113 < 3; c20_i1113 = c20_i1113 + 1) {
    c20_w[c20_i1113] = c20_xi[c20_i1113 + 3];
  }

  _SFD_SCRIPT_CALL(8, 3);
  for (c20_i1114 = 0; c20_i1114 < 3; c20_i1114 = c20_i1114 + 1) {
    c20_v[c20_i1114] = c20_xi[c20_i1114];
  }

  _SFD_SCRIPT_CALL(8, 5);
  for (c20_i1115 = 0; c20_i1115 < 3; c20_i1115 = c20_i1115 + 1) {
    c20_b_w[c20_i1115] = c20_w[c20_i1115];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_sv6, c20_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_b_nargin, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_b_nargout, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_b_w, c20_f_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_W, c20_e_sf_marshall, 3U);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6, 2);
  c20_W[0] = 0.0;
  c20_W[3] = -c20_b_w[2];
  c20_W[6] = c20_b_w[1];
  c20_W[1] = c20_b_w[2];
  c20_W[4] = 0.0;
  c20_W[7] = -c20_b_w[0];
  c20_W[2] = -c20_b_w[1];
  c20_W[5] = c20_b_w[0];
  c20_W[8] = 0.0;
  _SFD_SCRIPT_CALL(6, -2);
  sf_debug_symbol_scope_pop();
  for (c20_i1116 = 0; c20_i1116 < 3; c20_i1116 = c20_i1116 + 1) {
    c20_c_w[c20_i1116] = c20_v[c20_i1116];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_sv6, c20_c_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_c_nargin, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_c_nargout, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_c_w, c20_f_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_b_W, c20_e_sf_marshall, 3U);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6, 2);
  c20_b_W[0] = 0.0;
  c20_b_W[3] = -c20_c_w[2];
  c20_b_W[6] = c20_c_w[1];
  c20_b_W[1] = c20_c_w[2];
  c20_b_W[4] = 0.0;
  c20_b_W[7] = -c20_c_w[0];
  c20_b_W[2] = -c20_c_w[1];
  c20_b_W[5] = c20_c_w[0];
  c20_b_W[8] = 0.0;
  _SFD_SCRIPT_CALL(6, -2);
  sf_debug_symbol_scope_pop();
  for (c20_i1117 = 0; c20_i1117 < 3; c20_i1117 = c20_i1117 + 1) {
    c20_d_w[c20_i1117] = c20_w[c20_i1117];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c20_sv6, c20_d_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c20_d_nargin, c20_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c20_d_nargout, c20_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c20_d_w, c20_f_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c20_c_W, c20_e_sf_marshall, 3U);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6, 2);
  c20_c_W[0] = 0.0;
  c20_c_W[3] = -c20_d_w[2];
  c20_c_W[6] = c20_d_w[1];
  c20_c_W[1] = c20_d_w[2];
  c20_c_W[4] = 0.0;
  c20_c_W[7] = -c20_d_w[0];
  c20_c_W[2] = -c20_d_w[1];
  c20_c_W[5] = c20_d_w[0];
  c20_c_W[8] = 0.0;
  _SFD_SCRIPT_CALL(6, -2);
  sf_debug_symbol_scope_pop();
  c20_i1118 = 0;
  c20_i1119 = 0;
  for (c20_i1120 = 0; c20_i1120 < 3; c20_i1120 = c20_i1120 + 1) {
    for (c20_i1121 = 0; c20_i1121 < 3; c20_i1121 = c20_i1121 + 1) {
      c20_adx[c20_i1121 + c20_i1118] = c20_W[c20_i1121 + c20_i1119];
    }

    c20_i1118 = c20_i1118 + 6;
    c20_i1119 = c20_i1119 + 3;
  }

  c20_i1122 = 0;
  c20_i1123 = 0;
  for (c20_i1124 = 0; c20_i1124 < 3; c20_i1124 = c20_i1124 + 1) {
    for (c20_i1125 = 0; c20_i1125 < 3; c20_i1125 = c20_i1125 + 1) {
      c20_adx[(c20_i1125 + c20_i1122) + 18] = c20_b_W[c20_i1125 + c20_i1123];
    }

    c20_i1122 = c20_i1122 + 6;
    c20_i1123 = c20_i1123 + 3;
  }

  c20_i1126 = 0;
  for (c20_i1127 = 0; c20_i1127 < 3; c20_i1127 = c20_i1127 + 1) {
    for (c20_i1128 = 0; c20_i1128 < 3; c20_i1128 = c20_i1128 + 1) {
      c20_adx[(c20_i1128 + c20_i1126) + 3] = 0.0;
    }

    c20_i1126 = c20_i1126 + 6;
  }

  c20_i1129 = 0;
  c20_i1130 = 0;
  for (c20_i1131 = 0; c20_i1131 < 3; c20_i1131 = c20_i1131 + 1) {
    for (c20_i1132 = 0; c20_i1132 < 3; c20_i1132 = c20_i1132 + 1) {
      c20_adx[(c20_i1132 + c20_i1129) + 21] = c20_c_W[c20_i1132 + c20_i1130];
    }

    c20_i1129 = c20_i1129 + 6;
    c20_i1130 = c20_i1130 + 3;
  }

  _SFD_SCRIPT_CALL(8, -5);
  sf_debug_symbol_scope_pop();
}

static void c20_h_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static void c20_ceval_xgemm(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_m, int32_T c20_n, int32_T c20_k
  , real_T c20_alpha1, real_T c20_A[36], int32_T c20_ia0, int32_T c20_lda,
  real_T c20_B[36], int32_T c20_ib0, int32_T c20_ldb, real_T
  c20_beta1, real_T c20_C[36], int32_T c20_ic0, int32_T c20_ldc, real_T c20_b_C
  [36])
{
  char_T c20_TRANSA;
  char_T c20_TRANSB;
  int32_T c20_i1133;
  c20_TRANSA = 'N';
  c20_TRANSB = 'N';
  for (c20_i1133 = 0; c20_i1133 < 36; c20_i1133 = c20_i1133 + 1) {
    c20_b_C[c20_i1133] = c20_C[c20_i1133];
  }

  dgemm32(&c20_TRANSA, &c20_TRANSB, &c20_m, &c20_n, &c20_k, &c20_alpha1,
          &c20_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c20_ia0), 1, 36, 1, 0) - 1], &c20_lda,
          &c20_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c20_ib0), 1, 36, 1, 0) - 1], &c20_ldb,
          &c20_beta1, &c20_b_C[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c20_ic0), 1, 36, 1, 0) - 1], &c20_ldc);
}

static void c20_i_eml_scalar_eg(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

static real_T c20_ceval_xdot(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, int32_T c20_n, real_T c20_x[6], int32_T
  c20_ix0, int32_T c20_incx, real_T c20_y[6], int32_T c20_iy0, int32_T c20_incy)
{
  real_T c20_d;
  c20_d = 0.0;
  if ((real_T)c20_n > 0.0) {
    return ddot32(&c20_n, &c20_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c20_ix0), 1, 6, 1, 0) - 1], &
                  c20_incx, &c20_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c20_iy0), 1, 6, 1, 0) - 1], &c20_incy);
  }

  return c20_d;
}

static const mxArray *c20_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i1134;
  real_T c20_b_u[6];
  int32_T c20_i1135;
  real_T c20_c_u[6];
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  for (c20_i1134 = 0; c20_i1134 < 6; c20_i1134 = c20_i1134 + 1) {
    c20_b_u[c20_i1134] = (*((real_T (*)[6])c20_u))[c20_i1134];
  }

  for (c20_i1135 = 0; c20_i1135 < 6; c20_i1135 = c20_i1135 + 1) {
    c20_c_u[c20_i1135] = c20_b_u[c20_i1135];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_b_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i1136;
  real_T c20_b_u[60];
  int32_T c20_i1137;
  real_T c20_c_u[60];
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  for (c20_i1136 = 0; c20_i1136 < 60; c20_i1136 = c20_i1136 + 1) {
    c20_b_u[c20_i1136] = (*((real_T (*)[60])c20_u))[c20_i1136];
  }

  for (c20_i1137 = 0; c20_i1137 < 60; c20_i1137 = c20_i1137 + 1) {
    c20_c_u[c20_i1137] = c20_b_u[c20_i1137];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 1, 60));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_c_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i1138;
  int32_T c20_i1139;
  int32_T c20_i1140;
  real_T c20_b_u[28];
  int32_T c20_i1141;
  int32_T c20_i1142;
  int32_T c20_i1143;
  real_T c20_c_u[28];
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  c20_i1138 = 0;
  for (c20_i1139 = 0; c20_i1139 < 7; c20_i1139 = c20_i1139 + 1) {
    for (c20_i1140 = 0; c20_i1140 < 4; c20_i1140 = c20_i1140 + 1) {
      c20_b_u[c20_i1140 + c20_i1138] = (*((real_T (*)[28])c20_u))[c20_i1140 +
        c20_i1138];
    }

    c20_i1138 = c20_i1138 + 4;
  }

  c20_i1141 = 0;
  for (c20_i1142 = 0; c20_i1142 < 7; c20_i1142 = c20_i1142 + 1) {
    for (c20_i1143 = 0; c20_i1143 < 4; c20_i1143 = c20_i1143 + 1) {
      c20_c_u[c20_i1143 + c20_i1141] = c20_b_u[c20_i1143 + c20_i1141];
    }

    c20_i1141 = c20_i1141 + 4;
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 4, 7));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_d_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  real_T c20_b_u;
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  c20_b_u = *((real_T *)c20_u);
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_e_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i1144;
  int32_T c20_i1145;
  int32_T c20_i1146;
  real_T c20_b_u[9];
  int32_T c20_i1147;
  int32_T c20_i1148;
  int32_T c20_i1149;
  real_T c20_c_u[9];
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  c20_i1144 = 0;
  for (c20_i1145 = 0; c20_i1145 < 3; c20_i1145 = c20_i1145 + 1) {
    for (c20_i1146 = 0; c20_i1146 < 3; c20_i1146 = c20_i1146 + 1) {
      c20_b_u[c20_i1146 + c20_i1144] = (*((real_T (*)[9])c20_u))[c20_i1146 +
        c20_i1144];
    }

    c20_i1144 = c20_i1144 + 3;
  }

  c20_i1147 = 0;
  for (c20_i1148 = 0; c20_i1148 < 3; c20_i1148 = c20_i1148 + 1) {
    for (c20_i1149 = 0; c20_i1149 < 3; c20_i1149 = c20_i1149 + 1) {
      c20_c_u[c20_i1149 + c20_i1147] = c20_b_u[c20_i1149 + c20_i1147];
    }

    c20_i1147 = c20_i1147 + 3;
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_f_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i1150;
  real_T c20_b_u[3];
  int32_T c20_i1151;
  real_T c20_c_u[3];
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  for (c20_i1150 = 0; c20_i1150 < 3; c20_i1150 = c20_i1150 + 1) {
    c20_b_u[c20_i1150] = (*((real_T (*)[3])c20_u))[c20_i1150];
  }

  for (c20_i1151 = 0; c20_i1151 < 3; c20_i1151 = c20_i1151 + 1) {
    c20_c_u[c20_i1151] = c20_b_u[c20_i1151];
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_g_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i1152;
  int32_T c20_i1153;
  int32_T c20_i1154;
  real_T c20_b_u[16];
  int32_T c20_i1155;
  int32_T c20_i1156;
  int32_T c20_i1157;
  real_T c20_c_u[16];
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  c20_i1152 = 0;
  for (c20_i1153 = 0; c20_i1153 < 4; c20_i1153 = c20_i1153 + 1) {
    for (c20_i1154 = 0; c20_i1154 < 4; c20_i1154 = c20_i1154 + 1) {
      c20_b_u[c20_i1154 + c20_i1152] = (*((real_T (*)[16])c20_u))[c20_i1154 +
        c20_i1152];
    }

    c20_i1152 = c20_i1152 + 4;
  }

  c20_i1155 = 0;
  for (c20_i1156 = 0; c20_i1156 < 4; c20_i1156 = c20_i1156 + 1) {
    for (c20_i1157 = 0; c20_i1157 < 4; c20_i1157 = c20_i1157 + 1) {
      c20_c_u[c20_i1157 + c20_i1155] = c20_b_u[c20_i1157 + c20_i1155];
    }

    c20_i1155 = c20_i1155 + 4;
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static const mxArray *c20_h_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  int32_T c20_i1158;
  int32_T c20_i1159;
  int32_T c20_i1160;
  real_T c20_b_u[36];
  int32_T c20_i1161;
  int32_T c20_i1162;
  int32_T c20_i1163;
  real_T c20_c_u[36];
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  c20_i1158 = 0;
  for (c20_i1159 = 0; c20_i1159 < 6; c20_i1159 = c20_i1159 + 1) {
    for (c20_i1160 = 0; c20_i1160 < 6; c20_i1160 = c20_i1160 + 1) {
      c20_b_u[c20_i1160 + c20_i1158] = (*((real_T (*)[36])c20_u))[c20_i1160 +
        c20_i1158];
    }

    c20_i1158 = c20_i1158 + 6;
  }

  c20_i1161 = 0;
  for (c20_i1162 = 0; c20_i1162 < 6; c20_i1162 = c20_i1162 + 1) {
    for (c20_i1163 = 0; c20_i1163 < 6; c20_i1163 = c20_i1163 + 1) {
      c20_c_u[c20_i1163 + c20_i1161] = c20_b_u[c20_i1163 + c20_i1161];
    }

    c20_i1161 = c20_i1161 + 6;
  }

  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", c20_c_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

const mxArray *sf_c20_EurlerDynJointVerifyIdn_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_ResolvedFunctionInfo c20_info[113];
  const mxArray *c20_m0 = NULL;
  int32_T c20_i1164;
  c20_ResolvedFunctionInfo *c20_r0;
  c20_nameCaptureInfo = NULL;
  c20_info_helper(c20_info);
  c20_b_info_helper(c20_info);
  sf_mex_assign(&c20_m0, sf_mex_createstruct("nameCaptureInfo", 1, 113));
  for (c20_i1164 = 0; c20_i1164 < 113; c20_i1164 = c20_i1164 + 1) {
    c20_r0 = &c20_info[c20_i1164];
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->context)), "context"
                    , "nameCaptureInfo", c20_i1164);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c20_r0->name)), "name",
                    "nameCaptureInfo", c20_i1164);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo",
      c20_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c20_i1164);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", c20_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c20_r0->resolved)),
                    "resolved", "nameCaptureInfo", c20_i1164);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c20_i1164);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c20_i1164);
    sf_mex_addfield(c20_m0, sf_mex_create("nameCaptureInfo", &c20_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c20_i1164);
  }

  sf_mex_assign(&c20_nameCaptureInfo, c20_m0);
  return c20_nameCaptureInfo;
}

static void c20_info_helper(c20_ResolvedFunctionInfo c20_info[113])
{
  c20_info[0].context = "";
  c20_info[0].name = "DynEulerCal_Min";
  c20_info[0].dominantType = "double";
  c20_info[0].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/DynEulerCal_Min.m";
  c20_info[0].fileLength = 7070U;
  c20_info[0].fileTime1 = 1424935777U;
  c20_info[0].fileTime2 = 0U;
  c20_info[1].context = "[E]D:/Learn/Project_Matlab/Fanuc/DynEulerCal_Min.m";
  c20_info[1].name = "expWre";
  c20_info[1].dominantType = "double";
  c20_info[1].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/expWre.m";
  c20_info[1].fileLength = 413U;
  c20_info[1].fileTime1 = 1366220272U;
  c20_info[1].fileTime2 = 0U;
  c20_info[2].context = "[E]D:/Learn/Project_Matlab/Fanuc/expWre.m";
  c20_info[2].name = "length";
  c20_info[2].dominantType = "double";
  c20_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[2].fileLength = 326U;
  c20_info[2].fileTime1 = 1226552074U;
  c20_info[2].fileTime2 = 0U;
  c20_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[3].name = "nargin";
  c20_info[3].dominantType = "";
  c20_info[3].resolved = "[B]nargin";
  c20_info[3].fileLength = 0U;
  c20_info[3].fileTime1 = 0U;
  c20_info[3].fileTime2 = 0U;
  c20_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[4].name = "eq";
  c20_info[4].dominantType = "double";
  c20_info[4].resolved = "[B]eq";
  c20_info[4].fileLength = 0U;
  c20_info[4].fileTime1 = 0U;
  c20_info[4].fileTime2 = 0U;
  c20_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[5].name = "size";
  c20_info[5].dominantType = "double";
  c20_info[5].resolved = "[B]size";
  c20_info[5].fileLength = 0U;
  c20_info[5].fileTime1 = 0U;
  c20_info[5].fileTime2 = 0U;
  c20_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c20_info[6].name = "gt";
  c20_info[6].dominantType = "double";
  c20_info[6].resolved = "[B]gt";
  c20_info[6].fileLength = 0U;
  c20_info[6].fileTime1 = 0U;
  c20_info[6].fileTime2 = 0U;
  c20_info[7].context = "[E]D:/Learn/Project_Matlab/Fanuc/expWre.m";
  c20_info[7].name = "ne";
  c20_info[7].dominantType = "double";
  c20_info[7].resolved = "[B]ne";
  c20_info[7].fileLength = 0U;
  c20_info[7].fileTime1 = 0U;
  c20_info[7].fileTime2 = 0U;
  c20_info[8].context = "[E]D:/Learn/Project_Matlab/Fanuc/expWre.m";
  c20_info[8].name = "eye";
  c20_info[8].dominantType = "double";
  c20_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c20_info[8].fileLength = 1765U;
  c20_info[8].fileTime1 = 1219731288U;
  c20_info[8].fileTime2 = 0U;
  c20_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c20_info[9].name = "ischar";
  c20_info[9].dominantType = "double";
  c20_info[9].resolved = "[B]ischar";
  c20_info[9].fileLength = 0U;
  c20_info[9].fileTime1 = 0U;
  c20_info[9].fileTime2 = 0U;
  c20_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c20_info[10].name = "isscalar";
  c20_info[10].dominantType = "double";
  c20_info[10].resolved = "[B]isscalar";
  c20_info[10].fileLength = 0U;
  c20_info[10].fileTime1 = 0U;
  c20_info[10].fileTime2 = 0U;
  c20_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[11].name = "eml_assert_valid_size_arg";
  c20_info[11].dominantType = "double";
  c20_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[11].fileLength = 3315U;
  c20_info[11].fileTime1 = 1256367816U;
  c20_info[11].fileTime2 = 0U;
  c20_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c20_info[12].name = "false";
  c20_info[12].dominantType = "";
  c20_info[12].resolved = "[B]false";
  c20_info[12].fileLength = 0U;
  c20_info[12].fileTime1 = 0U;
  c20_info[12].fileTime2 = 0U;
  c20_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c20_info[13].name = "not";
  c20_info[13].dominantType = "logical";
  c20_info[13].resolved = "[B]not";
  c20_info[13].fileLength = 0U;
  c20_info[13].fileTime1 = 0U;
  c20_info[13].fileTime2 = 0U;
  c20_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[14].name = "isa";
  c20_info[14].dominantType = "double";
  c20_info[14].resolved = "[B]isa";
  c20_info[14].fileLength = 0U;
  c20_info[14].fileTime1 = 0U;
  c20_info[14].fileTime2 = 0U;
  c20_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[15].name = "isreal";
  c20_info[15].dominantType = "double";
  c20_info[15].resolved = "[B]isreal";
  c20_info[15].fileLength = 0U;
  c20_info[15].fileTime1 = 0U;
  c20_info[15].fileTime2 = 0U;
  c20_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c20_info[16].name = "isinteger";
  c20_info[16].dominantType = "double";
  c20_info[16].resolved = "[B]isinteger";
  c20_info[16].fileLength = 0U;
  c20_info[16].fileTime1 = 0U;
  c20_info[16].fileTime2 = 0U;
  c20_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c20_info[17].name = "isinf";
  c20_info[17].dominantType = "double";
  c20_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c20_info[17].fileLength = 541U;
  c20_info[17].fileTime1 = 1271383988U;
  c20_info[17].fileTime2 = 0U;
  c20_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c20_info[18].name = "true";
  c20_info[18].dominantType = "";
  c20_info[18].resolved = "[B]true";
  c20_info[18].fileLength = 0U;
  c20_info[18].fileTime1 = 0U;
  c20_info[18].fileTime2 = 0U;
  c20_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c20_info[19].name = "le";
  c20_info[19].dominantType = "double";
  c20_info[19].resolved = "[B]le";
  c20_info[19].fileLength = 0U;
  c20_info[19].fileTime1 = 0U;
  c20_info[19].fileTime2 = 0U;
  c20_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c20_info[20].name = "double";
  c20_info[20].dominantType = "double";
  c20_info[20].resolved = "[B]double";
  c20_info[20].fileLength = 0U;
  c20_info[20].fileTime1 = 0U;
  c20_info[20].fileTime2 = 0U;
  c20_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c20_info[21].name = "mtimes";
  c20_info[21].dominantType = "double";
  c20_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[21].fileLength = 3425U;
  c20_info[21].fileTime1 = 1251010272U;
  c20_info[21].fileTime2 = 0U;
  c20_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[22].name = "strcmp";
  c20_info[22].dominantType = "char";
  c20_info[22].resolved = "[B]strcmp";
  c20_info[22].fileLength = 0U;
  c20_info[22].fileTime1 = 0U;
  c20_info[22].fileTime2 = 0U;
  c20_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[23].name = "class";
  c20_info[23].dominantType = "double";
  c20_info[23].resolved = "[B]class";
  c20_info[23].fileLength = 0U;
  c20_info[23].fileTime1 = 0U;
  c20_info[23].fileTime2 = 0U;
  c20_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[24].name = "eml_index_class";
  c20_info[24].dominantType = "";
  c20_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c20_info[24].fileLength = 909U;
  c20_info[24].fileTime1 = 1192445182U;
  c20_info[24].fileTime2 = 0U;
  c20_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c20_info[25].name = "intmax";
  c20_info[25].dominantType = "char";
  c20_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[25].fileLength = 1535U;
  c20_info[25].fileTime1 = 1192445128U;
  c20_info[25].fileTime2 = 0U;
  c20_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c20_info[26].name = "int32";
  c20_info[26].dominantType = "double";
  c20_info[26].resolved = "[B]int32";
  c20_info[26].fileLength = 0U;
  c20_info[26].fileTime1 = 0U;
  c20_info[26].fileTime2 = 0U;
  c20_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[27].name = "eml_is_float_class";
  c20_info[27].dominantType = "char";
  c20_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c20_info[27].fileLength = 226U;
  c20_info[27].fileTime1 = 1197825240U;
  c20_info[27].fileTime2 = 0U;
  c20_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[28].name = "zeros";
  c20_info[28].dominantType = "double";
  c20_info[28].resolved = "[B]zeros";
  c20_info[28].fileLength = 0U;
  c20_info[28].fileTime1 = 0U;
  c20_info[28].fileTime2 = 0U;
  c20_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[29].name = "real";
  c20_info[29].dominantType = "double";
  c20_info[29].resolved = "[B]real";
  c20_info[29].fileLength = 0U;
  c20_info[29].fileTime1 = 0U;
  c20_info[29].fileTime2 = 0U;
  c20_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c20_info[30].name = "min";
  c20_info[30].dominantType = "double";
  c20_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[30].fileLength = 362U;
  c20_info[30].fileTime1 = 1245080764U;
  c20_info[30].fileTime2 = 0U;
  c20_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[31].name = "nargout";
  c20_info[31].dominantType = "";
  c20_info[31].resolved = "[B]nargout";
  c20_info[31].fileLength = 0U;
  c20_info[31].fileTime1 = 0U;
  c20_info[31].fileTime2 = 0U;
  c20_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c20_info[32].name = "eml_min_or_max";
  c20_info[32].dominantType = "char";
  c20_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c20_info[32].fileLength = 9967U;
  c20_info[32].fileTime1 = 1261926670U;
  c20_info[32].fileTime2 = 0U;
  c20_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c20_info[33].name = "isnumeric";
  c20_info[33].dominantType = "double";
  c20_info[33].resolved = "[B]isnumeric";
  c20_info[33].fileLength = 0U;
  c20_info[33].fileTime1 = 0U;
  c20_info[33].fileTime2 = 0U;
  c20_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[34].name = "islogical";
  c20_info[34].dominantType = "double";
  c20_info[34].resolved = "[B]islogical";
  c20_info[34].fileLength = 0U;
  c20_info[34].fileTime1 = 0U;
  c20_info[34].fileTime2 = 0U;
  c20_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[35].name = "eml_scalar_eg";
  c20_info[35].dominantType = "double";
  c20_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[35].fileLength = 3068U;
  c20_info[35].fileTime1 = 1240240410U;
  c20_info[35].fileTime2 = 0U;
  c20_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c20_info[36].name = "isstruct";
  c20_info[36].dominantType = "double";
  c20_info[36].resolved = "[B]isstruct";
  c20_info[36].fileLength = 0U;
  c20_info[36].fileTime1 = 0U;
  c20_info[36].fileTime2 = 0U;
  c20_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c20_info[37].name = "cast";
  c20_info[37].dominantType = "double";
  c20_info[37].resolved = "[B]cast";
  c20_info[37].fileLength = 0U;
  c20_info[37].fileTime1 = 0U;
  c20_info[37].fileTime2 = 0U;
  c20_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c20_info[38].name = "plus";
  c20_info[38].dominantType = "double";
  c20_info[38].resolved = "[B]plus";
  c20_info[38].fileLength = 0U;
  c20_info[38].fileTime1 = 0U;
  c20_info[38].fileTime2 = 0U;
  c20_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[39].name = "eml_scalexp_alloc";
  c20_info[39].dominantType = "double";
  c20_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[39].fileLength = 932U;
  c20_info[39].fileTime1 = 1261926670U;
  c20_info[39].fileTime2 = 0U;
  c20_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c20_info[40].name = "minus";
  c20_info[40].dominantType = "double";
  c20_info[40].resolved = "[B]minus";
  c20_info[40].fileLength = 0U;
  c20_info[40].fileTime1 = 0U;
  c20_info[40].fileTime2 = 0U;
  c20_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c20_info[41].name = "ones";
  c20_info[41].dominantType = "char";
  c20_info[41].resolved = "[B]ones";
  c20_info[41].fileLength = 0U;
  c20_info[41].fileTime1 = 0U;
  c20_info[41].fileTime2 = 0U;
  c20_info[42].context = "[E]D:/Learn/Project_Matlab/Fanuc/expWre.m";
  c20_info[42].name = "expRot";
  c20_info[42].dominantType = "double";
  c20_info[42].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/expRot.m";
  c20_info[42].fileLength = 236U;
  c20_info[42].fileTime1 = 1366773052U;
  c20_info[42].fileTime2 = 0U;
  c20_info[43].context = "[E]D:/Learn/Project_Matlab/Fanuc/expRot.m";
  c20_info[43].name = "skew";
  c20_info[43].dominantType = "double";
  c20_info[43].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/skew.m";
  c20_info[43].fileLength = 450U;
  c20_info[43].fileTime1 = 1399884445U;
  c20_info[43].fileTime2 = 0U;
  c20_info[44].context = "[E]D:/Learn/Project_Matlab/Fanuc/skew.m";
  c20_info[44].name = "uminus";
  c20_info[44].dominantType = "double";
  c20_info[44].resolved = "[B]uminus";
  c20_info[44].fileLength = 0U;
  c20_info[44].fileTime1 = 0U;
  c20_info[44].fileTime2 = 0U;
  c20_info[45].context = "[E]D:/Learn/Project_Matlab/Fanuc/expRot.m";
  c20_info[45].name = "sin";
  c20_info[45].dominantType = "double";
  c20_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[45].fileLength = 324U;
  c20_info[45].fileTime1 = 1203422842U;
  c20_info[45].fileTime2 = 0U;
  c20_info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c20_info[46].name = "eml_scalar_sin";
  c20_info[46].dominantType = "double";
  c20_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c20_info[46].fileLength = 601U;
  c20_info[46].fileTime1 = 1209309190U;
  c20_info[46].fileTime2 = 0U;
  c20_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[47].name = "ndims";
  c20_info[47].dominantType = "double";
  c20_info[47].resolved = "[B]ndims";
  c20_info[47].fileLength = 0U;
  c20_info[47].fileTime1 = 0U;
  c20_info[47].fileTime2 = 0U;
  c20_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[48].name = "isempty";
  c20_info[48].dominantType = "double";
  c20_info[48].resolved = "[B]isempty";
  c20_info[48].fileLength = 0U;
  c20_info[48].fileTime1 = 0U;
  c20_info[48].fileTime2 = 0U;
  c20_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[49].name = "eml_xgemm";
  c20_info[49].dominantType = "int32";
  c20_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c20_info[49].fileLength = 3184U;
  c20_info[49].fileTime1 = 1209309252U;
  c20_info[49].fileTime2 = 0U;
  c20_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c20_info[50].name = "lt";
  c20_info[50].dominantType = "int32";
  c20_info[50].resolved = "[B]lt";
  c20_info[50].fileLength = 0U;
  c20_info[50].fileTime1 = 0U;
  c20_info[50].fileTime2 = 0U;
  c20_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c20_info[51].name = "eml_refblas_xgemm";
  c20_info[51].dominantType = "int32";
  c20_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[51].fileLength = 5748U;
  c20_info[51].fileTime1 = 1228068672U;
  c20_info[51].fileTime2 = 0U;
  c20_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[52].name = "eml_index_minus";
  c20_info[52].dominantType = "int32";
  c20_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c20_info[52].fileLength = 277U;
  c20_info[52].fileTime1 = 1192445184U;
  c20_info[52].fileTime2 = 0U;
  c20_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[53].name = "eml_index_times";
  c20_info[53].dominantType = "int32";
  c20_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c20_info[53].fileLength = 280U;
  c20_info[53].fileTime1 = 1192445186U;
  c20_info[53].fileTime2 = 0U;
  c20_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c20_info[54].name = "eml_index_plus";
  c20_info[54].dominantType = "int32";
  c20_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c20_info[54].fileLength = 272U;
  c20_info[54].fileTime1 = 1192445184U;
  c20_info[54].fileTime2 = 0U;
  c20_info[55].context = "[E]D:/Learn/Project_Matlab/Fanuc/expRot.m";
  c20_info[55].name = "cos";
  c20_info[55].dominantType = "double";
  c20_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c20_info[55].fileLength = 324U;
  c20_info[55].fileTime1 = 1203422750U;
  c20_info[55].fileTime2 = 0U;
  c20_info[56].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c20_info[56].name = "eml_scalar_cos";
  c20_info[56].dominantType = "double";
  c20_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c20_info[56].fileLength = 602U;
  c20_info[56].fileTime1 = 1209309186U;
  c20_info[56].fileTime2 = 0U;
  c20_info[57].context = "[E]D:/Learn/Project_Matlab/Fanuc/expWre.m";
  c20_info[57].name = "cross";
  c20_info[57].dominantType = "double";
  c20_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c20_info[57].fileLength = 3157U;
  c20_info[57].fileTime1 = 1240240462U;
  c20_info[57].fileTime2 = 0U;
  c20_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c20_info[58].name = "isvector";
  c20_info[58].dominantType = "double";
  c20_info[58].resolved = "[B]isvector";
  c20_info[58].fileLength = 0U;
  c20_info[58].fileTime1 = 0U;
  c20_info[58].fileTime2 = 0U;
  c20_info[59].context = "[E]D:/Learn/Project_Matlab/Fanuc/expWre.m";
  c20_info[59].name = "ctranspose";
  c20_info[59].dominantType = "double";
  c20_info[59].resolved = "[B]ctranspose";
  c20_info[59].fileLength = 0U;
  c20_info[59].fileTime1 = 0U;
  c20_info[59].fileTime2 = 0U;
  c20_info[60].context = "[E]D:/Learn/Project_Matlab/Fanuc/DynEulerCal_Min.m";
  c20_info[60].name = "expg";
  c20_info[60].dominantType = "double";
  c20_info[60].resolved =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expg.m";
  c20_info[60].fileLength = 297U;
  c20_info[60].fileTime1 = 1365051648U;
  c20_info[60].fileTime2 = 0U;
  c20_info[61].context =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expg.m";
  c20_info[61].name = "norm";
  c20_info[61].dominantType = "double";
  c20_info[61].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c20_info[61].fileLength = 5453U;
  c20_info[61].fileTime1 = 1271384008U;
  c20_info[61].fileTime2 = 0U;
  c20_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c20_info[62].name = "eml_xnrm2";
  c20_info[62].dominantType = "int32";
  c20_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c20_info[62].fileLength = 718U;
  c20_info[62].fileTime1 = 1209309256U;
  c20_info[62].fileTime2 = 0U;
  c20_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c20_info[63].name = "eml_refblas_xnrm2";
  c20_info[63].dominantType = "int32";
  c20_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[63].fileLength = 1433U;
  c20_info[63].fileTime1 = 1240240442U;
  c20_info[63].fileTime2 = 0U;
}

static void c20_b_info_helper(c20_ResolvedFunctionInfo c20_info[113])
{
  c20_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[64].name = "abs";
  c20_info[64].dominantType = "double";
  c20_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[64].fileLength = 566U;
  c20_info[64].fileTime1 = 1221245532U;
  c20_info[64].fileTime2 = 0U;
  c20_info[65].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c20_info[65].name = "eml_scalar_abs";
  c20_info[65].dominantType = "double";
  c20_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c20_info[65].fileLength = 461U;
  c20_info[65].fileTime1 = 1203422760U;
  c20_info[65].fileTime2 = 0U;
  c20_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[66].name = "times";
  c20_info[66].dominantType = "double";
  c20_info[66].resolved = "[B]times";
  c20_info[66].fileLength = 0U;
  c20_info[66].fileTime1 = 0U;
  c20_info[66].fileTime2 = 0U;
  c20_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c20_info[67].name = "imag";
  c20_info[67].dominantType = "double";
  c20_info[67].resolved = "[B]imag";
  c20_info[67].fileLength = 0U;
  c20_info[67].fileTime1 = 0U;
  c20_info[67].fileTime2 = 0U;
  c20_info[68].context =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expg.m";
  c20_info[68].name = "eps";
  c20_info[68].dominantType = "";
  c20_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c20_info[68].fileLength = 1331U;
  c20_info[68].fileTime1 = 1246588112U;
  c20_info[68].fileTime2 = 0U;
  c20_info[69].context =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expg.m";
  c20_info[69].name = "mrdivide";
  c20_info[69].dominantType = "double";
  c20_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c20_info[69].fileLength = 432U;
  c20_info[69].fileTime1 = 1277726622U;
  c20_info[69].fileTime2 = 0U;
  c20_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c20_info[70].name = "ge";
  c20_info[70].dominantType = "double";
  c20_info[70].resolved = "[B]ge";
  c20_info[70].fileLength = 0U;
  c20_info[70].fileTime1 = 0U;
  c20_info[70].fileTime2 = 0U;
  c20_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c20_info[71].name = "rdivide";
  c20_info[71].dominantType = "double";
  c20_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[71].fileLength = 403U;
  c20_info[71].fileTime1 = 1245080820U;
  c20_info[71].fileTime2 = 0U;
  c20_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c20_info[72].name = "eml_div";
  c20_info[72].dominantType = "double";
  c20_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c20_info[72].fileLength = 4918U;
  c20_info[72].fileTime1 = 1267038210U;
  c20_info[72].fileTime2 = 0U;
  c20_info[73].context =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expg.m";
  c20_info[73].name = "expr";
  c20_info[73].dominantType = "double";
  c20_info[73].resolved =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expr.m";
  c20_info[73].fileLength = 191U;
  c20_info[73].fileTime1 = 1386474448U;
  c20_info[73].fileTime2 = 0U;
  c20_info[74].context =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expr.m";
  c20_info[74].name = "hat";
  c20_info[74].dominantType = "double";
  c20_info[74].resolved =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/hat.m";
  c20_info[74].fileLength = 88U;
  c20_info[74].fileTime1 = 1346208402U;
  c20_info[74].fileTime2 = 0U;
  c20_info[75].context =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/expr.m";
  c20_info[75].name = "mpower";
  c20_info[75].dominantType = "double";
  c20_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[75].fileLength = 3710U;
  c20_info[75].fileTime1 = 1238412688U;
  c20_info[75].fileTime2 = 0U;
  c20_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[76].name = "eml_scalar_floor";
  c20_info[76].dominantType = "double";
  c20_info[76].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c20_info[76].fileLength = 260U;
  c20_info[76].fileTime1 = 1209309190U;
  c20_info[76].fileTime2 = 0U;
  c20_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c20_info[77].name = "inv";
  c20_info[77].dominantType = "double";
  c20_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c20_info[77].fileLength = 4757U;
  c20_info[77].fileTime1 = 1252487208U;
  c20_info[77].fileTime2 = 0U;
  c20_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c20_info[78].name = "isnan";
  c20_info[78].dominantType = "double";
  c20_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c20_info[78].fileLength = 541U;
  c20_info[78].fileTime1 = 1271383988U;
  c20_info[78].fileTime2 = 0U;
  c20_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c20_info[79].name = "eml_guarded_nan";
  c20_info[79].dominantType = "char";
  c20_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c20_info[79].fileLength = 485U;
  c20_info[79].fileTime1 = 1192445180U;
  c20_info[79].fileTime2 = 0U;
  c20_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c20_info[80].name = "nan";
  c20_info[80].dominantType = "char";
  c20_info[80].resolved = "[B]nan";
  c20_info[80].fileLength = 0U;
  c20_info[80].fileTime1 = 0U;
  c20_info[80].fileTime2 = 0U;
  c20_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c20_info[81].name = "eml_warning";
  c20_info[81].dominantType = "char";
  c20_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c20_info[81].fileLength = 262U;
  c20_info[81].fileTime1 = 1236232078U;
  c20_info[81].fileTime2 = 0U;
  c20_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c20_info[82].name = "power";
  c20_info[82].dominantType = "double";
  c20_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[82].fileLength = 5380U;
  c20_info[82].fileTime1 = 1228068698U;
  c20_info[82].fileTime2 = 0U;
  c20_info[83].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c20_info[83].name = "eml_error";
  c20_info[83].dominantType = "char";
  c20_info[83].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c20_info[83].fileLength = 315U;
  c20_info[83].fileTime1 = 1213905144U;
  c20_info[83].fileTime2 = 0U;
  c20_info[84].context = "[E]D:/Learn/Project_Matlab/Fanuc/DynEulerCal_Min.m";
  c20_info[84].name = "mldivide";
  c20_info[84].dominantType = "double";
  c20_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c20_info[84].fileLength = 494U;
  c20_info[84].fileTime1 = 1277726622U;
  c20_info[84].fileTime2 = 0U;
  c20_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c20_info[85].name = "eml_lusolve";
  c20_info[85].dominantType = "double";
  c20_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c20_info[85].fileLength = 5239U;
  c20_info[85].fileTime1 = 1264408552U;
  c20_info[85].fileTime2 = 0U;
  c20_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c20_info[86].name = "eml_xgetrf";
  c20_info[86].dominantType = "int32";
  c20_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c20_info[86].fileLength = 204U;
  c20_info[86].fileTime1 = 1271383994U;
  c20_info[86].fileTime2 = 0U;
  c20_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c20_info[87].name = "eml_lapack_xgetrf";
  c20_info[87].dominantType = "int32";
  c20_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c20_info[87].fileLength = 211U;
  c20_info[87].fileTime1 = 1271383994U;
  c20_info[87].fileTime2 = 0U;
  c20_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c20_info[88].name = "eml_matlab_zgetrf";
  c20_info[88].dominantType = "int32";
  c20_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[88].fileLength = 2193U;
  c20_info[88].fileTime1 = 1271383998U;
  c20_info[88].fileTime2 = 0U;
  c20_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[89].name = "realmin";
  c20_info[89].dominantType = "char";
  c20_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c20_info[89].fileLength = 749U;
  c20_info[89].fileTime1 = 1226552078U;
  c20_info[89].fileTime2 = 0U;
  c20_info[90].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[90].name = "colon";
  c20_info[90].dominantType = "int32";
  c20_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c20_info[90].fileLength = 8633U;
  c20_info[90].fileTime1 = 1273822662U;
  c20_info[90].fileTime2 = 0U;
  c20_info[91].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c20_info[91].name = "floor";
  c20_info[91].dominantType = "double";
  c20_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c20_info[91].fileLength = 332U;
  c20_info[91].fileTime1 = 1203422822U;
  c20_info[91].fileTime2 = 0U;
  c20_info[92].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c20_info[92].name = "intmin";
  c20_info[92].dominantType = "char";
  c20_info[92].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c20_info[92].fileLength = 1505U;
  c20_info[92].fileTime1 = 1192445128U;
  c20_info[92].fileTime2 = 0U;
  c20_info[93].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c20_info[93].name = "transpose";
  c20_info[93].dominantType = "int32";
  c20_info[93].resolved = "[B]transpose";
  c20_info[93].fileLength = 0U;
  c20_info[93].fileTime1 = 0U;
  c20_info[93].fileTime2 = 0U;
  c20_info[94].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[94].name = "eml_ixamax";
  c20_info[94].dominantType = "int32";
  c20_info[94].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c20_info[94].fileLength = 731U;
  c20_info[94].fileTime1 = 1209309244U;
  c20_info[94].fileTime2 = 0U;
  c20_info[95].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c20_info[95].name = "eml_refblas_ixamax";
  c20_info[95].dominantType = "int32";
  c20_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c20_info[95].fileLength = 740U;
  c20_info[95].fileTime1 = 1192445266U;
  c20_info[95].fileTime2 = 0U;
  c20_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c20_info[96].name = "eml_xcabs1";
  c20_info[96].dominantType = "double";
  c20_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c20_info[96].fileLength = 419U;
  c20_info[96].fileTime1 = 1209309246U;
  c20_info[96].fileTime2 = 0U;
  c20_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[97].name = "eml_xswap";
  c20_info[97].dominantType = "int32";
  c20_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c20_info[97].fileLength = 1330U;
  c20_info[97].fileTime1 = 1209309260U;
  c20_info[97].fileTime2 = 0U;
  c20_info[98].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c20_info[98].name = "eml_refblas_xswap";
  c20_info[98].dominantType = "int32";
  c20_info[98].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c20_info[98].fileLength = 905U;
  c20_info[98].fileTime1 = 1238412670U;
  c20_info[98].fileTime2 = 0U;
  c20_info[99].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c20_info[99].name = "eml_xgeru";
  c20_info[99].dominantType = "int32";
  c20_info[99].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c20_info[99].fileLength = 2462U;
  c20_info[99].fileTime1 = 1209309256U;
  c20_info[99].fileTime2 = 0U;
  c20_info[100].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c20_info[100].name = "eml_xger";
  c20_info[100].dominantType = "int32";
  c20_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c20_info[100].fileLength = 2168U;
  c20_info[100].fileTime1 = 1209309254U;
  c20_info[100].fileTime2 = 0U;
  c20_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c20_info[101].name = "eml_refblas_xger";
  c20_info[101].dominantType = "int32";
  c20_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c20_info[101].fileLength = 411U;
  c20_info[101].fileTime1 = 1211194448U;
  c20_info[101].fileTime2 = 0U;
  c20_info[102].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c20_info[102].name = "eml_refblas_xgerx";
  c20_info[102].dominantType = "int32";
  c20_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c20_info[102].fileLength = 2231U;
  c20_info[102].fileTime1 = 1238412668U;
  c20_info[102].fileTime2 = 0U;
  c20_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c20_info[103].name = "eml_xtrsm";
  c20_info[103].dominantType = "int32";
  c20_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c20_info[103].fileLength = 2383U;
  c20_info[103].fileTime1 = 1209309262U;
  c20_info[103].fileTime2 = 0U;
  c20_info[104].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c20_info[104].name = "eml_refblas_xtrsm";
  c20_info[104].dominantType = "int32";
  c20_info[104].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c20_info[104].fileLength = 13101U;
  c20_info[104].fileTime1 = 1252487206U;
  c20_info[104].fileTime2 = 0U;
  c20_info[105].context = "[E]D:/Learn/Project_Matlab/Fanuc/DynEulerCal_Min.m";
  c20_info[105].name = "Adj";
  c20_info[105].dominantType = "double";
  c20_info[105].resolved =
    "[E]D:/Learn/Project_Matlab/Fanuc/basicfunction/Adj.m";
  c20_info[105].fileLength = 187U;
  c20_info[105].fileTime1 = 1399862722U;
  c20_info[105].fileTime2 = 0U;
  c20_info[106].context = "[E]D:/Learn/Project_Matlab/Fanuc/DynEulerCal_Min.m";
  c20_info[106].name = "ad";
  c20_info[106].dominantType = "double";
  c20_info[106].resolved =
    "[E]D:/Learn/Project_Matlab/GoogolTraj/basicfunction/ad.m";
  c20_info[106].fileLength = 112U;
  c20_info[106].fileTime1 = 1365307014U;
  c20_info[106].fileTime2 = 0U;
  c20_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c20_info[107].name = "eml_xdotu";
  c20_info[107].dominantType = "int32";
  c20_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c20_info[107].fileLength = 1453U;
  c20_info[107].fileTime1 = 1209309250U;
  c20_info[107].fileTime2 = 0U;
  c20_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c20_info[108].name = "eml_xdot";
  c20_info[108].dominantType = "int32";
  c20_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c20_info[108].fileLength = 1330U;
  c20_info[108].fileTime1 = 1209309248U;
  c20_info[108].fileTime2 = 0U;
  c20_info[109].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c20_info[109].name = "eml_refblas_xdot";
  c20_info[109].dominantType = "int32";
  c20_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c20_info[109].fileLength = 343U;
  c20_info[109].fileTime1 = 1211194442U;
  c20_info[109].fileTime2 = 0U;
  c20_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c20_info[110].name = "eml_refblas_xdotx";
  c20_info[110].dominantType = "int32";
  c20_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c20_info[110].fileLength = 1605U;
  c20_info[110].fileTime1 = 1236232078U;
  c20_info[110].fileTime2 = 0U;
  c20_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c20_info[111].name = "isequal";
  c20_info[111].dominantType = "char";
  c20_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c20_info[111].fileLength = 180U;
  c20_info[111].fileTime1 = 1226552070U;
  c20_info[111].fileTime2 = 0U;
  c20_info[112].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c20_info[112].name = "eml_isequal_core";
  c20_info[112].dominantType = "char";
  c20_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c20_info[112].fileLength = 4192U;
  c20_info[112].fileTime1 = 1258039010U;
  c20_info[112].fileTime2 = 0U;
}

static const mxArray *c20_i_sf_marshall(void *chartInstanceVoid, void *c20_u)
{
  const mxArray *c20_y = NULL;
  boolean_T c20_b_u;
  const mxArray *c20_b_y = NULL;
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
    chartInstanceVoid;
  c20_y = NULL;
  c20_b_u = *((boolean_T *)c20_u);
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c20_y, c20_b_y);
  return c20_y;
}

static void c20_emlrt_marshallIn(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance, const mxArray *c20_Torque, const char_T
  *c20_name, real_T c20_y[6])
{
  real_T c20_dv149[6];
  int32_T c20_i1165;
  sf_mex_import(c20_name, sf_mex_dup(c20_Torque), c20_dv149, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c20_i1165 = 0; c20_i1165 < 6; c20_i1165 = c20_i1165 + 1) {
    c20_y[c20_i1165] = c20_dv149[c20_i1165];
  }

  sf_mex_destroy(&c20_Torque);
}

static uint8_T c20_b_emlrt_marshallIn
  (SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance, const mxArray *
   c20_b_is_active_c20_EurlerDynJointVerifyIdn, const char_T *c20_name)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  sf_mex_import(c20_name, sf_mex_dup(c20_b_is_active_c20_EurlerDynJointVerifyIdn),
                &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_b_is_active_c20_EurlerDynJointVerifyIdn);
  return c20_y;
}

static void init_dsm_address_info(SFc20_EurlerDynJointVerifyIdnInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c20_EurlerDynJointVerifyIdn_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1255293770U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(407931333U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3091869184U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3358068775U);
}

mxArray *sf_c20_EurlerDynJointVerifyIdn_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1421190023U);
    pr[1] = (double)(4111168486U);
    pr[2] = (double)(2948173304U);
    pr[3] = (double)(821768731U);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(7);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(60);
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

static mxArray *sf_get_sim_state_info_c20_EurlerDynJointVerifyIdn(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Torque\",},{M[8],M[0],T\"is_active_c20_EurlerDynJointVerifyIdn\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_EurlerDynJointVerifyIdn_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
    chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_EurlerDynJointVerifyIdnMachineNumber_,
           20,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           9,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_EurlerDynJointVerifyIdnMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_EurlerDynJointVerifyIdnMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_EurlerDynJointVerifyIdnMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Pos");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Torque");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Vel");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Acc");
          _SFD_SET_DATA_PROPS(4,10,0,0,"DH_Min");
          _SFD_SET_DATA_PROPS(5,10,0,0,"Param_Min");
          _SFD_SET_DATA_PROPS(6,10,0,0,"Ft_Min");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,153);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"DynEulerCal_Min",687,-1,6901);
        _SFD_CV_INIT_SCRIPT(1,1,2,0,0,0,0,3,1);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"expWre",30,-1,391);
        _SFD_CV_INIT_SCRIPT_IF(1,0,67,85,-1,135);
        _SFD_CV_INIT_SCRIPT_IF(1,1,188,221,267,358);

        {
          static int condStart[] = { 191, 202, 213 };

          static int condEnd[] = { 198, 209, 220 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,0,191,220,3,0,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"expRot",34,-1,217);
        _SFD_CV_INIT_SCRIPT(3,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"skew",0,-1,450);
        _SFD_CV_INIT_SCRIPT_IF(3,0,27,44,-1,92);
        _SFD_CV_INIT_SCRIPT(4,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"expg",0,-1,280);
        _SFD_CV_INIT_SCRIPT_IF(4,0,68,76,110,232);
        _SFD_CV_INIT_SCRIPT(5,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"expr",0,-1,182);
        _SFD_CV_INIT_SCRIPT_IF(5,0,41,49,66,182);
        _SFD_CV_INIT_SCRIPT(6,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(6,0,"hat",0,-1,85);
        _SFD_CV_INIT_SCRIPT(7,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(7,0,"Adj",0,-1,180);
        _SFD_CV_INIT_SCRIPT(8,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(8,0,"ad",0,-1,106);
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
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 60;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_b_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c20_sf_marshall);
        }

        {
          real_T (*c20_Pos)[6];
          real_T (*c20_Torque)[6];
          real_T (*c20_Vel)[6];
          real_T (*c20_Acc)[6];
          c20_Acc = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c20_Vel = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c20_Torque = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c20_Pos = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c20_Pos);
          _SFD_SET_DATA_VALUE_PTR(1U, *c20_Torque);
          _SFD_SET_DATA_VALUE_PTR(2U, *c20_Vel);
          _SFD_SET_DATA_VALUE_PTR(3U, *c20_Acc);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c20_DH_Min);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c20_Param_Min);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c20_Ft_Min);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_EurlerDynJointVerifyIdnMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c20_EurlerDynJointVerifyIdn(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc20_EurlerDynJointVerifyIdnInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_EurlerDynJointVerifyIdn
    ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*) chartInstanceVar);
  initialize_c20_EurlerDynJointVerifyIdn
    ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c20_EurlerDynJointVerifyIdn(void *chartInstanceVar)
{
  enable_c20_EurlerDynJointVerifyIdn
    ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c20_EurlerDynJointVerifyIdn(void *chartInstanceVar)
{
  disable_c20_EurlerDynJointVerifyIdn
    ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c20_EurlerDynJointVerifyIdn(void *chartInstanceVar)
{
  sf_c20_EurlerDynJointVerifyIdn((SFc20_EurlerDynJointVerifyIdnInstanceStruct*)
    chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c20_EurlerDynJointVerifyIdn(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c20_EurlerDynJointVerifyIdn
    ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c20_EurlerDynJointVerifyIdn();/* state var info */
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

static void sf_internal_set_sim_state_c20_EurlerDynJointVerifyIdn(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c20_EurlerDynJointVerifyIdn();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c20_EurlerDynJointVerifyIdn
    ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c20_EurlerDynJointVerifyIdn(SimStruct* S)
{
  return sf_internal_get_sim_state_c20_EurlerDynJointVerifyIdn(S);
}

static void sf_opaque_set_sim_state_c20_EurlerDynJointVerifyIdn(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c20_EurlerDynJointVerifyIdn(S, st);
}

static void sf_opaque_terminate_c20_EurlerDynJointVerifyIdn(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c20_EurlerDynJointVerifyIdn
      ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c20_EurlerDynJointVerifyIdn
    ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_EurlerDynJointVerifyIdn(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c20_EurlerDynJointVerifyIdn
      ((SFc20_EurlerDynJointVerifyIdnInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c20_EurlerDynJointVerifyIdn(SimStruct *S)
{
  /* Actual parameters from chart:
     DH_Min Ft_Min Param_Min
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for DH_Min*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Ft_Min*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for Param_Min*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"EurlerDynJointVerifyIdn",
      "EurlerDynJointVerifyIdn",20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"EurlerDynJointVerifyIdn",
                "EurlerDynJointVerifyIdn",20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      "EurlerDynJointVerifyIdn","EurlerDynJointVerifyIdn",20,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"EurlerDynJointVerifyIdn",
        "EurlerDynJointVerifyIdn",20,3);
      sf_mark_chart_reusable_outputs(S,"EurlerDynJointVerifyIdn",
        "EurlerDynJointVerifyIdn",20,1);
    }

    sf_set_rtw_dwork_info(S,"EurlerDynJointVerifyIdn","EurlerDynJointVerifyIdn",
                          20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3535856832U));
  ssSetChecksum1(S,(3250192671U));
  ssSetChecksum2(S,(1949070059U));
  ssSetChecksum3(S,(3893095308U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c20_EurlerDynJointVerifyIdn(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "EurlerDynJointVerifyIdn",
      "EurlerDynJointVerifyIdn",20);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c20_EurlerDynJointVerifyIdn(SimStruct *S)
{
  SFc20_EurlerDynJointVerifyIdnInstanceStruct *chartInstance;
  chartInstance = (SFc20_EurlerDynJointVerifyIdnInstanceStruct *)malloc(sizeof
    (SFc20_EurlerDynJointVerifyIdnInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_EurlerDynJointVerifyIdnInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_EurlerDynJointVerifyIdn;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_EurlerDynJointVerifyIdn;
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

void c20_EurlerDynJointVerifyIdn_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_EurlerDynJointVerifyIdn(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_EurlerDynJointVerifyIdn(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_EurlerDynJointVerifyIdn(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_EurlerDynJointVerifyIdn_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
