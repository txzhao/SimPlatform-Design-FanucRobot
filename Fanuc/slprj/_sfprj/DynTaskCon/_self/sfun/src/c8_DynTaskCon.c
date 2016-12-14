/* Include files */

#include "blascompat32.h"
#include "DynTaskCon_sfun.h"
#include "c8_DynTaskCon.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DynTaskCon_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c8_debug_family_names[9] = { "gd", "theta_total", "num_total",
  "nargin", "nargout", "EndPos", "init_Rot", "L", "theta" };

static const char *c8_b_debug_family_names[6] = { "nargin", "nargout", "x",
  "xmin", "xmax", "isIn" };

static const char *c8_c_debug_family_names[4] = { "nargin", "nargout", "w", "wh"
};

static const char *c8_d_debug_family_names[6] = { "wh", "nargin", "nargout", "w",
  "theta", "R" };

static const char *c8_e_debug_family_names[9] = { "v", "w", "R", "p", "nargin",
  "nargout", "kx", "theta", "g" };

static const char *c8_f_debug_family_names[18] = { "velociy", "w", "r", "u", "v",
  "up", "vp", "dp2", "theta0", "phi", "p", "q", "d", "nargin", "nargout", "kx",
  "theta", "Nsol" };

static const char *c8_g_debug_family_names[6] = { "nargin", "nargout", "x",
  "xmin", "xmax", "isIn" };

static const char *c8_h_debug_family_names[13] = { "velociy", "w", "r", "u", "v",
  "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char *c8_i_debug_family_names[10] = { "A", "vec", "cof", "nargin",
  "nargout", "w1", "w2", "r1", "r2", "r" };

static const char *c8_j_debug_family_names[13] = { "velociy", "w", "r", "u", "v",
  "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char *c8_k_debug_family_names[13] = { "velociy", "w", "r", "u", "v",
  "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char *c8_l_debug_family_names[25] = { "velociy1", "w1", "r1",
  "velociy2", "w2", "r2", "r", "u", "v", "alpha", "beta", "ySqu", "i", "y", "z",
  "c", "nargin", "nargout", "kx1", "kx2", "p", "q", "theta1", "theta2", "Nsol" };

static const char *c8_m_debug_family_names[71] = { "Min1", "Max1", "Min2",
  "Max2", "Min3", "Max3", "Min4", "Max4", "Min5", "Max5", "Min6", "Max6", "L1",
  "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "s_origin", "w_x", "w_y",
  "w_z", "w1", "q1", "kx1", "w2", "q2", "kx2", "w3", "q3", "kx3", "pw", "w4",
  "q4", "kx4", "w5", "q5", "kx5", "w6", "q6", "kx6", "q7", "gst0", "g1", "p1",
  "theta_1", "p2", "d", "theta_3", "Num_3", "c3", "p3", "theta_2", "g2", "p4",
  "theta_4", "theta_5", "Num_45", "c45", "g3", "p5", "theta_6", "nargin",
  "nargout", "gd", "L", "theta", "Num" };

/* Function Declarations */
static void initialize_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance);
static void initialize_params_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance);
static void enable_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance);
static void disable_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *
  chartInstance);
static void set_sim_state_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance, const mxArray *c8_st);
static void finalize_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance);
static void sf_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c8_DynTaskCon
  (SFc8_DynTaskConInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber);
static void c8_inv_kin(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_gd[16], real_T c8_b_L[9], real_T c8_theta[24], real_T *c8_Num);
static void c8_cross(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_a[3],
                     real_T c8_b[3], real_T c8_c[3]);
static boolean_T c8_all(SFc8_DynTaskConInstanceStruct *chartInstance, boolean_T
  c8_x[2]);
static void c8_mrdivide(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_A[16], real_T c8_B[16], real_T c8_y[16]);
static real_T c8_power(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_a,
  real_T c8_b);
static void c8_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_eml_error(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_eps(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_eml_matlab_zgetrf(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_A[16], real_T c8_b_A[16], int32_T c8_ipiv[4], int32_T *c8_info);
static int32_T c8_eml_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[16], int32_T c8_ix0);
static int32_T c8_ceval_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[16], int32_T c8_ix0, int32_T c8_incx);
static void c8_ceval_xswap(SFc8_DynTaskConInstanceStruct *chartInstance, int32_T
  c8_n, real_T c8_x[16], int32_T c8_ix0, int32_T c8_incx, int32_T c8_iy0,
  int32_T c8_incy, real_T c8_b_x[16]);
static void c8_ceval_xger(SFc8_DynTaskConInstanceStruct *chartInstance, int32_T
  c8_m, int32_T c8_n, real_T c8_alpha1, int32_T c8_ix0, int32_T c8_incx, int32_T
  c8_iy0, int32_T c8_incy, real_T c8_A[16], int32_T c8_ia0, int32_T c8_lda,
  real_T c8_b_A[16]);
static void c8_eml_warning(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_b_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_eml_xtrsm(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_A[16], real_T c8_B[16], real_T c8_b_B[16]);
static void c8_c_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_eml_blas_xtrsm(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, real_T c8_A[16], int32_T c8_ia0,
  int32_T c8_lda, real_T c8_B[16], int32_T c8_ib0, int32_T c8_ldb, real_T
  c8_b_B[16]);
static void c8_d_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance);
static real_T c8_atan2(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_y,
  real_T c8_x);
static boolean_T c8_isInRange(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_x, real_T c8_xmin, real_T c8_xmax);
static void c8_expWre(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
                      c8_kx[6], real_T c8_theta, real_T c8_g[16]);
static real_T c8_length(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_eye(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_I[9]);
static void c8_expRot(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_w
                      [3], real_T c8_theta, real_T c8_R[9]);
static void c8_e_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_f_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_subPro3(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[4], real_T c8_q[4], real_T c8_d[4], real_T c8_theta[2],
  real_T *c8_Nsol);
static void c8_g_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance);
static real_T c8_ceval_xdot(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[3], int32_T c8_ix0, int32_T c8_incx, real_T c8_y[3],
  int32_T c8_iy0, int32_T c8_incy);
static real_T c8_mpower(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_a);
static real_T c8_norm(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_x
                      [3]);
static real_T c8_ceval_xnrm2(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[3], int32_T c8_ix0, int32_T c8_incx);
static void c8_b_eml_error(SFc8_DynTaskConInstanceStruct *chartInstance);
static void c8_b_isInRange(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_x[2], real_T c8_xmin, real_T c8_xmax, boolean_T c8_isIn[2]);
static boolean_T c8_any(SFc8_DynTaskConInstanceStruct *chartInstance, boolean_T
  c8_x[2]);
static real_T c8_subPro1(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[4], real_T c8_q[4]);
static void c8_subPro2(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx1[6], real_T c8_kx2[6], real_T c8_p[4], real_T c8_q[4], real_T c8_theta1
  [2], real_T c8_theta2[2], real_T *c8_Nsol);
static void c8_findCommon(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_w1[3], real_T c8_w2[3], real_T c8_r1[3], real_T c8_r2[3], real_T c8_r[3]);
static real_T c8_det(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_x[4]);
static void c8_b_eml_matlab_zgetrf(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_A[4], real_T c8_b_A[4], int32_T c8_ipiv[2], int32_T *c8_info);
static int32_T c8_b_eml_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_x[4]);
static int32_T c8_b_ceval_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[4], int32_T c8_ix0, int32_T c8_incx);
static void c8_b_ceval_xswap(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[4], int32_T c8_ix0, int32_T c8_incx, int32_T c8_iy0,
  int32_T c8_incy, real_T c8_b_x[4]);
static void c8_b_ceval_xger(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, int32_T c8_ix0, int32_T c8_incx,
  int32_T c8_iy0, int32_T c8_incy, real_T c8_A[4], int32_T c8_ia0, int32_T
  c8_lda, real_T c8_b_A[4]);
static void c8_c_eml_error(SFc8_DynTaskConInstanceStruct *chartInstance);
static real_T c8_b_subPro1(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[4], real_T c8_q[3]);
static real_T c8_c_subPro1(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[3], real_T c8_q[4]);
static const mxArray *c8_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_b_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_c_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_d_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_e_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_f_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_g_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_h_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_i_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_j_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_k_sf_marshall(void *chartInstanceVoid, void *c8_u);
static const mxArray *c8_l_sf_marshall(void *chartInstanceVoid, void *c8_u);
static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[121]);
static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[121]);
static void c8_emlrt_marshallIn(SFc8_DynTaskConInstanceStruct *chartInstance,
  const mxArray *c8_theta, const char_T *c8_name, real_T c8_y[6]);
static uint8_T c8_b_emlrt_marshallIn(SFc8_DynTaskConInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_DynTaskCon, const char_T
  *c8_name);
static void init_dsm_address_info(SFc8_DynTaskConInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c8_is_active_c8_DynTaskCon = 0U;
}

static void initialize_params_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance)
{
  real_T c8_dv0[9];
  int32_T c8_i0;
  real_T c8_dv1[9];
  int32_T c8_i1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'init_Rot' in the parent workspace.\n");
  sf_mex_import("init_Rot", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                c8_dv0, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c8_i0 = 0; c8_i0 < 9; c8_i0 = c8_i0 + 1) {
    chartInstance->c8_init_Rot[c8_i0] = c8_dv0[c8_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c8_dv1, 0, 0,
                0U, 1, 0U, 2, 1, 9);
  for (c8_i1 = 0; c8_i1 < 9; c8_i1 = c8_i1 + 1) {
    chartInstance->c8_L[c8_i1] = c8_dv1[c8_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c8_update_debugger_state_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *
  chartInstance)
{
  const mxArray *c8_st = NULL;
  const mxArray *c8_y = NULL;
  int32_T c8_i2;
  real_T c8_hoistedGlobal[6];
  int32_T c8_i3;
  real_T c8_u[6];
  const mxArray *c8_b_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  uint8_T c8_b_u;
  const mxArray *c8_c_y = NULL;
  real_T (*c8_theta)[6];
  c8_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_st = NULL;
  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_createcellarray(2));
  for (c8_i2 = 0; c8_i2 < 6; c8_i2 = c8_i2 + 1) {
    c8_hoistedGlobal[c8_i2] = (*c8_theta)[c8_i2];
  }

  for (c8_i3 = 0; c8_i3 < 6; c8_i3 = c8_i3 + 1) {
    c8_u[c8_i3] = c8_hoistedGlobal[c8_i3];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c8_y, 0, c8_b_y);
  c8_b_hoistedGlobal = chartInstance->c8_is_active_c8_DynTaskCon;
  c8_b_u = c8_b_hoistedGlobal;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c8_y, 1, c8_c_y);
  sf_mex_assign(&c8_st, c8_y);
  return c8_st;
}

static void set_sim_state_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct
  *chartInstance, const mxArray *c8_st)
{
  const mxArray *c8_u;
  real_T c8_dv2[6];
  int32_T c8_i4;
  real_T (*c8_theta)[6];
  c8_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c8_doneDoubleBufferReInit = TRUE;
  c8_u = sf_mex_dup(c8_st);
  c8_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 0)),
                      "theta", c8_dv2);
  for (c8_i4 = 0; c8_i4 < 6; c8_i4 = c8_i4 + 1) {
    (*c8_theta)[c8_i4] = c8_dv2[c8_i4];
  }

  chartInstance->c8_is_active_c8_DynTaskCon = c8_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c8_u, 1)),
     "is_active_c8_DynTaskCon");
  sf_mex_destroy(&c8_u);
  c8_update_debugger_state_c8_DynTaskCon(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void sf_c8_DynTaskCon(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  int32_T c8_i5;
  int32_T c8_i6;
  int32_T c8_i7;
  int32_T c8_i8;
  int32_T c8_previousEvent;
  int32_T c8_i9;
  real_T c8_hoistedGlobal[3];
  int32_T c8_i10;
  real_T c8_b_hoistedGlobal[9];
  int32_T c8_i11;
  real_T c8_c_hoistedGlobal[9];
  int32_T c8_i12;
  real_T c8_EndPos[3];
  int32_T c8_i13;
  real_T c8_b_init_Rot[9];
  int32_T c8_i14;
  real_T c8_b_L[9];
  uint32_T c8_debug_family_var_map[9];
  static const char *c8_sv0[9] = { "gd", "theta_total", "num_total", "nargin",
    "nargout", "EndPos", "init_Rot", "L", "theta" };

  real_T c8_gd[16];
  real_T c8_theta_total[24];
  real_T c8_num_total;
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  real_T c8_theta[6];
  int32_T c8_i15;
  int32_T c8_i16;
  int32_T c8_i17;
  int32_T c8_i18;
  int32_T c8_i19;
  int32_T c8_i20;
  int32_T c8_i21;
  int32_T c8_i22;
  static real_T c8_dv3[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c8_i23;
  real_T c8_b_gd[16];
  int32_T c8_i24;
  real_T c8_c_L[9];
  real_T c8_b_num_total;
  real_T c8_b_theta_total[24];
  int32_T c8_i25;
  int32_T c8_i26;
  int32_T c8_i27;
  real_T (*c8_b_theta)[6];
  real_T (*c8_b_EndPos)[3];
  c8_b_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c8_b_EndPos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7);
  for (c8_i5 = 0; c8_i5 < 3; c8_i5 = c8_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_b_EndPos)[c8_i5], 0U);
  }

  for (c8_i6 = 0; c8_i6 < 9; c8_i6 = c8_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_init_Rot[c8_i6], 1U);
  }

  for (c8_i7 = 0; c8_i7 < 6; c8_i7 = c8_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c8_b_theta)[c8_i7], 2U);
  }

  for (c8_i8 = 0; c8_i8 < 9; c8_i8 = c8_i8 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c8_L[c8_i8], 3U);
  }

  c8_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7);
  for (c8_i9 = 0; c8_i9 < 3; c8_i9 = c8_i9 + 1) {
    c8_hoistedGlobal[c8_i9] = (*c8_b_EndPos)[c8_i9];
  }

  for (c8_i10 = 0; c8_i10 < 9; c8_i10 = c8_i10 + 1) {
    c8_b_hoistedGlobal[c8_i10] = chartInstance->c8_init_Rot[c8_i10];
  }

  for (c8_i11 = 0; c8_i11 < 9; c8_i11 = c8_i11 + 1) {
    c8_c_hoistedGlobal[c8_i11] = chartInstance->c8_L[c8_i11];
  }

  for (c8_i12 = 0; c8_i12 < 3; c8_i12 = c8_i12 + 1) {
    c8_EndPos[c8_i12] = c8_hoistedGlobal[c8_i12];
  }

  for (c8_i13 = 0; c8_i13 < 9; c8_i13 = c8_i13 + 1) {
    c8_b_init_Rot[c8_i13] = c8_b_hoistedGlobal[c8_i13];
  }

  for (c8_i14 = 0; c8_i14 < 9; c8_i14 = c8_i14 + 1) {
    c8_b_L[c8_i14] = c8_c_hoistedGlobal[c8_i14];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c8_sv0, c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_gd, c8_g_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_theta_total, c8_f_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c8_num_total, c8_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_EndPos, c8_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_b_init_Rot, c8_c_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c8_b_L, c8_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c8_theta, c8_sf_marshall, 8U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c8_i15 = 0; c8_i15 < 6; c8_i15 = c8_i15 + 1) {
    c8_theta[c8_i15] = 0.0;
  }

  _SFD_EML_CALL(0, 4);
  c8_i16 = 0;
  c8_i17 = 0;
  for (c8_i18 = 0; c8_i18 < 3; c8_i18 = c8_i18 + 1) {
    for (c8_i19 = 0; c8_i19 < 3; c8_i19 = c8_i19 + 1) {
      c8_gd[c8_i19 + c8_i16] = c8_b_init_Rot[c8_i19 + c8_i17];
    }

    c8_i16 = c8_i16 + 4;
    c8_i17 = c8_i17 + 3;
  }

  for (c8_i20 = 0; c8_i20 < 3; c8_i20 = c8_i20 + 1) {
    c8_gd[c8_i20 + 12] = c8_EndPos[c8_i20];
  }

  c8_i21 = 0;
  for (c8_i22 = 0; c8_i22 < 4; c8_i22 = c8_i22 + 1) {
    c8_gd[c8_i21 + 3] = c8_dv3[c8_i22];
    c8_i21 = c8_i21 + 4;
  }

  _SFD_EML_CALL(0, 5);
  for (c8_i23 = 0; c8_i23 < 16; c8_i23 = c8_i23 + 1) {
    c8_b_gd[c8_i23] = c8_gd[c8_i23];
  }

  for (c8_i24 = 0; c8_i24 < 9; c8_i24 = c8_i24 + 1) {
    c8_c_L[c8_i24] = c8_b_L[c8_i24];
  }

  c8_inv_kin(chartInstance, c8_b_gd, c8_c_L, c8_b_theta_total, &c8_b_num_total);
  for (c8_i25 = 0; c8_i25 < 24; c8_i25 = c8_i25 + 1) {
    c8_theta_total[c8_i25] = c8_b_theta_total[c8_i25];
  }

  c8_num_total = c8_b_num_total;
  _SFD_EML_CALL(0, 6);
  for (c8_i26 = 0; c8_i26 < 6; c8_i26 = c8_i26 + 1) {
    c8_theta[c8_i26] = c8_theta_total[c8_i26 + 6];
  }

  _SFD_EML_CALL(0, -6);
  sf_debug_symbol_scope_pop();
  for (c8_i27 = 0; c8_i27 < 6; c8_i27 = c8_i27 + 1) {
    (*c8_b_theta)[c8_i27] = c8_theta[c8_i27];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7);
  _sfEvent_ = c8_previousEvent;
  sf_debug_check_for_state_inconsistency(_DynTaskConMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c8_DynTaskCon
  (SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/inv_kin.m"));
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, 1U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/expWre.m"));
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, 2U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/expRot.m"));
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, 3U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/skew.m"));
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, 4U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/subPro3.m"));
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, 5U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/subPro1.m"));
  _SFD_SCRIPT_TRANSLATION(c8_chartNumber, 6U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/subPro2.m"));
}

static void c8_inv_kin(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_gd[16], real_T c8_b_L[9], real_T c8_theta[24], real_T
  *c8_Num)
{
  uint32_T c8_debug_family_var_map[71];
  static const char *c8_sv1[71] = { "Min1", "Max1", "Min2", "Max2", "Min3",
    "Max3", "Min4", "Max4", "Min5", "Max5", "Min6", "Max6",
    "L1", "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "s_origin", "w_x",
    "w_y", "w_z", "w1", "q1"
    , "kx1", "w2", "q2", "kx2", "w3", "q3", "kx3", "pw", "w4", "q4", "kx4", "w5",
    "q5", "kx5", "w6",
    "q6", "kx6", "q7", "gst0", "g1", "p1", "theta_1", "p2", "d", "theta_3",
    "Num_3", "c3", "p3",
    "theta_2", "g2", "p4", "theta_4", "theta_5", "Num_45", "c45", "g3", "p5",
    "theta_6", "nargin",
    "nargout", "gd", "L", "theta", "Num" };

  real_T c8_Min1;
  real_T c8_Max1;
  real_T c8_Min2;
  real_T c8_Max2;
  real_T c8_Min3;
  real_T c8_Max3;
  real_T c8_Min4;
  real_T c8_Max4;
  real_T c8_Min5;
  real_T c8_Max5;
  real_T c8_Min6;
  real_T c8_Max6;
  real_T c8_L1;
  real_T c8_L2;
  real_T c8_L3;
  real_T c8_L4;
  real_T c8_L5;
  real_T c8_L6;
  real_T c8_L7;
  real_T c8_L8;
  real_T c8_L9;
  real_T c8_s_origin[3];
  real_T c8_w_x[3];
  real_T c8_w_y[3];
  real_T c8_w_z[3];
  real_T c8_w1[3];
  real_T c8_q1[3];
  real_T c8_kx1[6];
  real_T c8_w2[3];
  real_T c8_q2[3];
  real_T c8_kx2[6];
  real_T c8_w3[3];
  real_T c8_q3[3];
  real_T c8_kx3[6];
  real_T c8_pw[3];
  real_T c8_w4[3];
  real_T c8_q4[3];
  real_T c8_kx4[6];
  real_T c8_w5[3];
  real_T c8_q5[3];
  real_T c8_kx5[6];
  real_T c8_w6[3];
  real_T c8_q6[3];
  real_T c8_kx6[6];
  real_T c8_q7[3];
  real_T c8_gst0[16];
  real_T c8_g1[16];
  real_T c8_p1[4];
  real_T c8_theta_1;
  real_T c8_p2[4];
  real_T c8_d[4];
  real_T c8_theta_3[2];
  real_T c8_Num_3;
  real_T c8_c3;
  real_T c8_p3[4];
  real_T c8_theta_2;
  real_T c8_g2[16];
  real_T c8_p4[4];
  real_T c8_theta_4[2];
  real_T c8_theta_5[2];
  real_T c8_Num_45;
  real_T c8_c45;
  real_T c8_g3[16];
  real_T c8_p5[4];
  real_T c8_theta_6;
  real_T c8_b_q1[4];
  real_T c8_b_q2[4];
  real_T c8_b_q3[4];
  real_T c8_b_q4[4];
  real_T c8_b_q5[4];
  real_T c8_b_q6[4];
  real_T c8_b_q7[4];
  real_T c8_b_pw[4];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 2.0;
  int32_T c8_i28;
  int32_T c8_i29;
  int32_T c8_i30;
  static real_T c8_dv4[3] = { 1.0, 0.0, 0.0 };

  int32_T c8_i31;
  static real_T c8_dv5[3] = { 0.0, 1.0, 0.0 };

  int32_T c8_i32;
  static real_T c8_dv6[3] = { 0.0, 0.0, 1.0 };

  int32_T c8_i33;
  int32_T c8_i34;
  int32_T c8_i35;
  static real_T c8_dv7[6] = { -0.0, -0.0, -0.0, 0.0, 0.0, 1.0 };

  int32_T c8_i36;
  int32_T c8_i37;
  real_T c8_dv8[3];
  int32_T c8_i38;
  real_T c8_c_q2[3];
  real_T c8_dv9[3];
  int32_T c8_i39;
  int32_T c8_i40;
  int32_T c8_i41;
  int32_T c8_i42;
  real_T c8_dv10[3];
  int32_T c8_i43;
  real_T c8_c_q3[3];
  real_T c8_dv11[3];
  int32_T c8_i44;
  int32_T c8_i45;
  int32_T c8_i46;
  int32_T c8_i47;
  int32_T c8_i48;
  real_T c8_dv12[3];
  int32_T c8_i49;
  real_T c8_c_q4[3];
  real_T c8_dv13[3];
  int32_T c8_i50;
  int32_T c8_i51;
  int32_T c8_i52;
  int32_T c8_i53;
  int32_T c8_i54;
  real_T c8_dv14[3];
  int32_T c8_i55;
  real_T c8_c_q5[3];
  real_T c8_dv15[3];
  int32_T c8_i56;
  int32_T c8_i57;
  int32_T c8_i58;
  int32_T c8_i59;
  int32_T c8_i60;
  real_T c8_dv16[3];
  int32_T c8_i61;
  real_T c8_c_q6[3];
  real_T c8_dv17[3];
  int32_T c8_i62;
  int32_T c8_i63;
  int32_T c8_i64;
  int32_T c8_i65;
  int32_T c8_i66;
  int32_T c8_i67;
  int32_T c8_i68;
  int32_T c8_i69;
  int32_T c8_i70;
  int32_T c8_i71;
  int32_T c8_i72;
  int32_T c8_i73;
  static real_T c8_dv18[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c8_i74;
  boolean_T c8_bv0[2];
  int32_T c8_i75;
  real_T c8_b_gd[16];
  int32_T c8_i76;
  real_T c8_b_gst0[16];
  real_T c8_dv19[16];
  int32_T c8_i77;
  int32_T c8_i78;
  real_T c8_a[16];
  int32_T c8_i79;
  real_T c8_b[4];
  int32_T c8_i80;
  real_T c8_A[16];
  int32_T c8_i81;
  real_T c8_B[4];
  int32_T c8_i82;
  int32_T c8_i83;
  real_T c8_b_A[16];
  int32_T c8_i84;
  real_T c8_b_B[4];
  int32_T c8_i85;
  real_T c8_c_A[16];
  int32_T c8_i86;
  real_T c8_c_B[4];
  int32_T c8_i87;
  int32_T c8_i88;
  int32_T c8_i89;
  int32_T c8_i90;
  static real_T c8_dv20[6] = { 0.0, 0.0, 0.0, -0.0, -0.0, -1.0 };

  real_T c8_dv21[6];
  real_T c8_b_a[16];
  int32_T c8_i91;
  real_T c8_b_b[4];
  int32_T c8_i92;
  real_T c8_d_A[16];
  int32_T c8_i93;
  real_T c8_d_B[4];
  int32_T c8_i94;
  int32_T c8_i95;
  real_T c8_e_A[16];
  int32_T c8_i96;
  real_T c8_e_B[4];
  int32_T c8_i97;
  real_T c8_f_A[16];
  int32_T c8_i98;
  real_T c8_f_B[4];
  int32_T c8_i99;
  int32_T c8_i100;
  int32_T c8_i101;
  int32_T c8_i102;
  int32_T c8_i103;
  real_T c8_b_kx3[6];
  int32_T c8_i104;
  real_T c8_c_pw[4];
  int32_T c8_i105;
  real_T c8_d_q2[4];
  int32_T c8_i106;
  real_T c8_b_d[4];
  real_T c8_b_Num_3;
  real_T c8_b_theta_3[2];
  int32_T c8_i107;
  int32_T c8_i108;
  real_T c8_c_theta_3[2];
  boolean_T c8_bv1[2];
  int32_T c8_i109;
  boolean_T c8_bv2[2];
  real_T c8_b_c3;
  int32_T c8_i110;
  real_T c8_c_kx3[6];
  real_T c8_c_a[16];
  int32_T c8_i111;
  real_T c8_c_b[4];
  int32_T c8_i112;
  real_T c8_g_A[16];
  int32_T c8_i113;
  real_T c8_g_B[4];
  int32_T c8_i114;
  int32_T c8_i115;
  real_T c8_h_A[16];
  int32_T c8_i116;
  real_T c8_h_B[4];
  int32_T c8_i117;
  real_T c8_i_A[16];
  int32_T c8_i118;
  real_T c8_i_B[4];
  int32_T c8_i119;
  int32_T c8_i120;
  int32_T c8_i121;
  int32_T c8_i122;
  real_T c8_b_kx2[6];
  int32_T c8_i123;
  real_T c8_b_p3[4];
  int32_T c8_i124;
  real_T c8_b_p2[4];
  int32_T c8_i125;
  real_T c8_d_kx3[6];
  real_T c8_d_a[16];
  int32_T c8_i126;
  real_T c8_c_kx2[6];
  real_T c8_d_b[16];
  int32_T c8_i127;
  real_T c8_j_A[16];
  int32_T c8_i128;
  real_T c8_j_B[16];
  int32_T c8_i129;
  real_T c8_k_A[16];
  int32_T c8_i130;
  real_T c8_k_B[16];
  int32_T c8_i131;
  real_T c8_l_A[16];
  int32_T c8_i132;
  real_T c8_l_B[16];
  int32_T c8_i133;
  int32_T c8_i134;
  int32_T c8_i135;
  real_T c8_y[16];
  int32_T c8_i136;
  int32_T c8_i137;
  int32_T c8_i138;
  real_T c8_e_a[16];
  int32_T c8_i139;
  real_T c8_dv22[6];
  real_T c8_e_b[16];
  int32_T c8_i140;
  real_T c8_m_A[16];
  int32_T c8_i141;
  real_T c8_m_B[16];
  int32_T c8_i142;
  real_T c8_n_A[16];
  int32_T c8_i143;
  real_T c8_n_B[16];
  int32_T c8_i144;
  real_T c8_o_A[16];
  int32_T c8_i145;
  real_T c8_o_B[16];
  int32_T c8_i146;
  int32_T c8_i147;
  int32_T c8_i148;
  real_T c8_b_y[16];
  int32_T c8_i149;
  int32_T c8_i150;
  int32_T c8_i151;
  real_T c8_f_a[16];
  int32_T c8_i152;
  real_T c8_f_b[16];
  int32_T c8_i153;
  real_T c8_p_A[16];
  int32_T c8_i154;
  real_T c8_p_B[16];
  int32_T c8_i155;
  int32_T c8_i156;
  real_T c8_q_A[16];
  int32_T c8_i157;
  real_T c8_q_B[16];
  int32_T c8_i158;
  real_T c8_r_A[16];
  int32_T c8_i159;
  real_T c8_r_B[16];
  int32_T c8_i160;
  int32_T c8_i161;
  int32_T c8_i162;
  int32_T c8_i163;
  int32_T c8_i164;
  int32_T c8_i165;
  real_T c8_g_a[16];
  int32_T c8_i166;
  real_T c8_g_b[4];
  int32_T c8_i167;
  real_T c8_s_A[16];
  int32_T c8_i168;
  real_T c8_s_B[4];
  int32_T c8_i169;
  int32_T c8_i170;
  real_T c8_t_A[16];
  int32_T c8_i171;
  real_T c8_t_B[4];
  int32_T c8_i172;
  real_T c8_u_A[16];
  int32_T c8_i173;
  real_T c8_u_B[4];
  int32_T c8_i174;
  int32_T c8_i175;
  int32_T c8_i176;
  int32_T c8_i177;
  real_T c8_b_kx4[6];
  int32_T c8_i178;
  real_T c8_b_kx5[6];
  int32_T c8_i179;
  real_T c8_c_q7[4];
  int32_T c8_i180;
  real_T c8_b_p4[4];
  real_T c8_b_Num_45;
  real_T c8_b_theta_5[2];
  real_T c8_b_theta_4[2];
  int32_T c8_i181;
  int32_T c8_i182;
  int32_T c8_i183;
  real_T c8_c_theta_5[2];
  boolean_T c8_bv3[2];
  int32_T c8_i184;
  boolean_T c8_bv4[2];
  real_T c8_b_c45;
  int32_T c8_i185;
  real_T c8_c_kx5[6];
  real_T c8_h_a[16];
  int32_T c8_i186;
  real_T c8_c_kx4[6];
  real_T c8_h_b[16];
  int32_T c8_i187;
  real_T c8_v_A[16];
  int32_T c8_i188;
  real_T c8_v_B[16];
  int32_T c8_i189;
  real_T c8_w_A[16];
  int32_T c8_i190;
  real_T c8_w_B[16];
  int32_T c8_i191;
  real_T c8_x_A[16];
  int32_T c8_i192;
  real_T c8_x_B[16];
  int32_T c8_i193;
  int32_T c8_i194;
  int32_T c8_i195;
  real_T c8_c_y[16];
  int32_T c8_i196;
  int32_T c8_i197;
  int32_T c8_i198;
  real_T c8_i_a[16];
  int32_T c8_i199;
  real_T c8_i_b[16];
  int32_T c8_i200;
  real_T c8_y_A[16];
  int32_T c8_i201;
  real_T c8_y_B[16];
  int32_T c8_i202;
  int32_T c8_i203;
  real_T c8_ab_A[16];
  int32_T c8_i204;
  real_T c8_ab_B[16];
  int32_T c8_i205;
  real_T c8_bb_A[16];
  int32_T c8_i206;
  real_T c8_bb_B[16];
  int32_T c8_i207;
  int32_T c8_i208;
  int32_T c8_i209;
  int32_T c8_i210;
  int32_T c8_i211;
  int32_T c8_i212;
  real_T c8_j_a[16];
  int32_T c8_i213;
  real_T c8_j_b[4];
  int32_T c8_i214;
  real_T c8_cb_A[16];
  int32_T c8_i215;
  real_T c8_cb_B[4];
  int32_T c8_i216;
  int32_T c8_i217;
  real_T c8_db_A[16];
  int32_T c8_i218;
  real_T c8_db_B[4];
  int32_T c8_i219;
  real_T c8_eb_A[16];
  int32_T c8_i220;
  real_T c8_eb_B[4];
  int32_T c8_i221;
  int32_T c8_i222;
  int32_T c8_i223;
  int32_T c8_i224;
  real_T c8_b_kx6[6];
  int32_T c8_i225;
  real_T c8_d_q3[4];
  int32_T c8_i226;
  real_T c8_b_p5[4];
  int32_T c8_b_Num;
  real_T c8_b_theta_1[6];
  int32_T c8_i227;
  sf_debug_symbol_scope_push_eml(0U, 71U, 79U, c8_sv1, c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c8_Min1, c8_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c8_Max1, c8_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c8_Min2, c8_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c8_Max2, c8_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_Min3, c8_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c8_Max3, c8_e_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c8_Min4, c8_e_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c8_Max4, c8_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c8_Min5, c8_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c8_Max5, c8_e_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c8_Min6, c8_e_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c8_Max6, c8_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c8_L1, c8_e_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c8_L2, c8_e_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c8_L3, c8_e_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c8_L4, c8_e_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c8_L5, c8_e_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c8_L6, c8_e_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c8_L7, c8_e_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c8_L8, c8_e_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c8_L9, c8_e_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(c8_s_origin, c8_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(c8_w_x, c8_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(c8_w_y, c8_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(c8_w_z, c8_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(c8_w1, c8_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(c8_q1, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_kx1, c8_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(c8_w2, c8_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(c8_q2, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_kx2, c8_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(c8_w3, c8_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(c8_q3, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_kx3, c8_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(c8_pw, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_w4, c8_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(c8_q4, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_kx4, c8_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(c8_w5, c8_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(c8_q5, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_kx5, c8_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(c8_w6, c8_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(c8_q6, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_kx6, c8_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(c8_q7, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_gst0, c8_g_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(c8_g1, c8_g_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(c8_p1, c8_j_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c8_theta_1, c8_e_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(c8_p2, c8_j_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(c8_d, c8_j_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(c8_theta_3, c8_i_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c8_Num_3, c8_e_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c8_c3, c8_e_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(c8_p3, c8_j_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c8_theta_2, c8_e_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(c8_g2, c8_g_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(c8_p4, c8_j_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(c8_theta_4, c8_i_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(c8_theta_5, c8_i_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c8_Num_45, c8_e_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c8_c45, c8_e_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(c8_g3, c8_g_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(c8_p5, c8_j_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c8_theta_6, c8_e_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c8_b_q1, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_q2, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_q3, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_q4, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_q5, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_q6, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_q7, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_pw, c8_j_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(c8_gd, c8_g_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(c8_b_L, c8_b_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(c8_theta, c8_f_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(c8_Num, c8_e_sf_marshall, 70U);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0, 2);
  for (c8_i28 = 0; c8_i28 < 24; c8_i28 = c8_i28 + 1) {
    c8_theta[c8_i28] = 0.0;
  }

  /*  at most 4 pairs of solution */
  _SFD_SCRIPT_CALL(0, 3);
  *c8_Num = 0.0;
  _SFD_SCRIPT_CALL(0, 5);
  c8_Min1 = -165.0;
  _SFD_SCRIPT_CALL(0, 5);
  c8_Max1 = 165.0;
  _SFD_SCRIPT_CALL(0, 6);
  c8_Min2 = -150.0;
  _SFD_SCRIPT_CALL(0, 6);
  c8_Max2 = 60.0;
  _SFD_SCRIPT_CALL(0, 7);
  c8_Min3 = -210.0;
  _SFD_SCRIPT_CALL(0, 7);
  c8_Max3 = 90.0;
  _SFD_SCRIPT_CALL(0, 8);
  c8_Min4 = -180.0;
  _SFD_SCRIPT_CALL(0, 8);
  c8_Max4 = 180.0;
  _SFD_SCRIPT_CALL(0, 9);
  c8_Min5 = -140.0;
  _SFD_SCRIPT_CALL(0, 9);
  c8_Max5 = 140.0;
  _SFD_SCRIPT_CALL(0, 10);
  c8_Min6 = -180.0;
  _SFD_SCRIPT_CALL(0, 10);
  c8_Max6 = 180.0;
  _SFD_SCRIPT_CALL(0, 12);
  c8_L1 = c8_b_L[0];
  _SFD_SCRIPT_CALL(0, 13);
  c8_L2 = c8_b_L[1];
  _SFD_SCRIPT_CALL(0, 14);
  c8_L3 = c8_b_L[2];
  _SFD_SCRIPT_CALL(0, 15);
  c8_L4 = c8_b_L[3];
  _SFD_SCRIPT_CALL(0, 16);
  c8_L5 = c8_b_L[4];
  _SFD_SCRIPT_CALL(0, 17);
  c8_L6 = c8_b_L[5];
  _SFD_SCRIPT_CALL(0, 18);
  c8_L7 = c8_b_L[6];
  _SFD_SCRIPT_CALL(0, 19);
  c8_L8 = c8_b_L[7];
  _SFD_SCRIPT_CALL(0, 20);
  c8_L9 = c8_b_L[8];
  _SFD_SCRIPT_CALL(0, 22);
  for (c8_i29 = 0; c8_i29 < 3; c8_i29 = c8_i29 + 1) {
    c8_s_origin[c8_i29] = 0.0;
  }

  _SFD_SCRIPT_CALL(0, 23);
  for (c8_i30 = 0; c8_i30 < 3; c8_i30 = c8_i30 + 1) {
    c8_w_x[c8_i30] = c8_dv4[c8_i30];
  }

  _SFD_SCRIPT_CALL(0, 24);
  for (c8_i31 = 0; c8_i31 < 3; c8_i31 = c8_i31 + 1) {
    c8_w_y[c8_i31] = c8_dv5[c8_i31];
  }

  _SFD_SCRIPT_CALL(0, 25);
  for (c8_i32 = 0; c8_i32 < 3; c8_i32 = c8_i32 + 1) {
    c8_w_z[c8_i32] = c8_dv6[c8_i32];
  }

  _SFD_SCRIPT_CALL(0, 27);
  for (c8_i33 = 0; c8_i33 < 3; c8_i33 = c8_i33 + 1) {
    c8_w1[c8_i33] = c8_dv6[c8_i33];
  }

  _SFD_SCRIPT_CALL(0, 28);
  for (c8_i34 = 0; c8_i34 < 3; c8_i34 = c8_i34 + 1) {
    c8_q1[c8_i34] = 0.0;
  }

  sf_debug_symbol_switch(26U, 26U);
  _SFD_SCRIPT_CALL(0, 29);
  for (c8_i35 = 0; c8_i35 < 6; c8_i35 = c8_i35 + 1) {
    c8_kx1[c8_i35] = c8_dv7[c8_i35];
  }

  _SFD_SCRIPT_CALL(0, 31);
  for (c8_i36 = 0; c8_i36 < 3; c8_i36 = c8_i36 + 1) {
    c8_w2[c8_i36] = c8_dv5[c8_i36];
  }

  _SFD_SCRIPT_CALL(0, 32);
  c8_q2[0] = c8_L2;
  c8_q2[1] = 0.0;
  c8_q2[2] = c8_L1;
  sf_debug_symbol_switch(29U, 29U);
  _SFD_SCRIPT_CALL(0, 33);
  for (c8_i37 = 0; c8_i37 < 3; c8_i37 = c8_i37 + 1) {
    c8_dv8[c8_i37] = c8_dv5[c8_i37];
  }

  for (c8_i38 = 0; c8_i38 < 3; c8_i38 = c8_i38 + 1) {
    c8_c_q2[c8_i38] = c8_q2[c8_i38];
  }

  c8_cross(chartInstance, c8_dv8, c8_c_q2, c8_dv9);
  for (c8_i39 = 0; c8_i39 < 3; c8_i39 = c8_i39 + 1) {
    c8_kx2[c8_i39] = -c8_dv9[c8_i39];
  }

  for (c8_i40 = 0; c8_i40 < 3; c8_i40 = c8_i40 + 1) {
    c8_kx2[c8_i40 + 3] = c8_w2[c8_i40];
  }

  _SFD_SCRIPT_CALL(0, 35);
  for (c8_i41 = 0; c8_i41 < 3; c8_i41 = c8_i41 + 1) {
    c8_w3[c8_i41] = c8_dv5[c8_i41];
  }

  _SFD_SCRIPT_CALL(0, 36);
  c8_q3[0] = c8_L2;
  c8_q3[1] = 0.0;
  c8_q3[2] = c8_L1 + c8_L3;
  sf_debug_symbol_switch(32U, 32U);
  _SFD_SCRIPT_CALL(0, 37);
  for (c8_i42 = 0; c8_i42 < 3; c8_i42 = c8_i42 + 1) {
    c8_dv10[c8_i42] = c8_dv5[c8_i42];
  }

  for (c8_i43 = 0; c8_i43 < 3; c8_i43 = c8_i43 + 1) {
    c8_c_q3[c8_i43] = c8_q3[c8_i43];
  }

  c8_cross(chartInstance, c8_dv10, c8_c_q3, c8_dv11);
  for (c8_i44 = 0; c8_i44 < 3; c8_i44 = c8_i44 + 1) {
    c8_kx3[c8_i44] = -c8_dv11[c8_i44];
  }

  for (c8_i45 = 0; c8_i45 < 3; c8_i45 = c8_i45 + 1) {
    c8_kx3[c8_i45 + 3] = c8_w3[c8_i45];
  }

  _SFD_SCRIPT_CALL(0, 39);
  c8_pw[0] = c8_L2 + c8_L5;
  c8_pw[1] = 0.0;
  c8_pw[2] = (c8_L1 + c8_L3) + c8_L4;
  sf_debug_symbol_switch(34U, 34U);
  _SFD_SCRIPT_CALL(0, 41);
  for (c8_i46 = 0; c8_i46 < 3; c8_i46 = c8_i46 + 1) {
    c8_w4[c8_i46] = c8_dv4[c8_i46];
  }

  _SFD_SCRIPT_CALL(0, 42);
  for (c8_i47 = 0; c8_i47 < 3; c8_i47 = c8_i47 + 1) {
    c8_q4[c8_i47] = c8_pw[c8_i47];
  }

  sf_debug_symbol_switch(36U, 36U);
  _SFD_SCRIPT_CALL(0, 43);
  for (c8_i48 = 0; c8_i48 < 3; c8_i48 = c8_i48 + 1) {
    c8_dv12[c8_i48] = c8_dv4[c8_i48];
  }

  for (c8_i49 = 0; c8_i49 < 3; c8_i49 = c8_i49 + 1) {
    c8_c_q4[c8_i49] = c8_q4[c8_i49];
  }

  c8_cross(chartInstance, c8_dv12, c8_c_q4, c8_dv13);
  for (c8_i50 = 0; c8_i50 < 3; c8_i50 = c8_i50 + 1) {
    c8_kx4[c8_i50] = -c8_dv13[c8_i50];
  }

  for (c8_i51 = 0; c8_i51 < 3; c8_i51 = c8_i51 + 1) {
    c8_kx4[c8_i51 + 3] = c8_w4[c8_i51];
  }

  _SFD_SCRIPT_CALL(0, 45);
  for (c8_i52 = 0; c8_i52 < 3; c8_i52 = c8_i52 + 1) {
    c8_w5[c8_i52] = c8_dv5[c8_i52];
  }

  _SFD_SCRIPT_CALL(0, 46);
  for (c8_i53 = 0; c8_i53 < 3; c8_i53 = c8_i53 + 1) {
    c8_q5[c8_i53] = c8_pw[c8_i53];
  }

  sf_debug_symbol_switch(39U, 39U);
  _SFD_SCRIPT_CALL(0, 47);
  for (c8_i54 = 0; c8_i54 < 3; c8_i54 = c8_i54 + 1) {
    c8_dv14[c8_i54] = c8_dv5[c8_i54];
  }

  for (c8_i55 = 0; c8_i55 < 3; c8_i55 = c8_i55 + 1) {
    c8_c_q5[c8_i55] = c8_q5[c8_i55];
  }

  c8_cross(chartInstance, c8_dv14, c8_c_q5, c8_dv15);
  for (c8_i56 = 0; c8_i56 < 3; c8_i56 = c8_i56 + 1) {
    c8_kx5[c8_i56] = -c8_dv15[c8_i56];
  }

  for (c8_i57 = 0; c8_i57 < 3; c8_i57 = c8_i57 + 1) {
    c8_kx5[c8_i57 + 3] = c8_w5[c8_i57];
  }

  _SFD_SCRIPT_CALL(0, 49);
  for (c8_i58 = 0; c8_i58 < 3; c8_i58 = c8_i58 + 1) {
    c8_w6[c8_i58] = c8_dv4[c8_i58];
  }

  _SFD_SCRIPT_CALL(0, 50);
  for (c8_i59 = 0; c8_i59 < 3; c8_i59 = c8_i59 + 1) {
    c8_q6[c8_i59] = c8_pw[c8_i59];
  }

  sf_debug_symbol_switch(42U, 42U);
  _SFD_SCRIPT_CALL(0, 51);
  for (c8_i60 = 0; c8_i60 < 3; c8_i60 = c8_i60 + 1) {
    c8_dv16[c8_i60] = c8_dv4[c8_i60];
  }

  for (c8_i61 = 0; c8_i61 < 3; c8_i61 = c8_i61 + 1) {
    c8_c_q6[c8_i61] = c8_q6[c8_i61];
  }

  c8_cross(chartInstance, c8_dv16, c8_c_q6, c8_dv17);
  for (c8_i62 = 0; c8_i62 < 3; c8_i62 = c8_i62 + 1) {
    c8_kx6[c8_i62] = -c8_dv17[c8_i62];
  }

  for (c8_i63 = 0; c8_i63 < 3; c8_i63 = c8_i63 + 1) {
    c8_kx6[c8_i63 + 3] = c8_w6[c8_i63];
  }

  _SFD_SCRIPT_CALL(0, 53);
  c8_q7[0] = (c8_L2 + c8_L5) + c8_L6;
  c8_q7[1] = 0.0;
  c8_q7[2] = (c8_L1 + c8_L3) + c8_L4;
  sf_debug_symbol_switch(44U, 44U);
  _SFD_SCRIPT_CALL(0, 55);
  for (c8_i64 = 0; c8_i64 < 3; c8_i64 = c8_i64 + 1) {
    c8_b_q1[c8_i64] = c8_q1[c8_i64];
  }

  c8_b_q1[3] = 1.0;
  sf_debug_symbol_switch(26U, 65U);
  _SFD_SCRIPT_CALL(0, 56);
  for (c8_i65 = 0; c8_i65 < 3; c8_i65 = c8_i65 + 1) {
    c8_b_q2[c8_i65] = c8_q2[c8_i65];
  }

  c8_b_q2[3] = 1.0;
  sf_debug_symbol_switch(29U, 66U);
  _SFD_SCRIPT_CALL(0, 57);
  for (c8_i66 = 0; c8_i66 < 3; c8_i66 = c8_i66 + 1) {
    c8_b_q3[c8_i66] = c8_q3[c8_i66];
  }

  c8_b_q3[3] = 1.0;
  sf_debug_symbol_switch(32U, 67U);
  _SFD_SCRIPT_CALL(0, 58);
  for (c8_i67 = 0; c8_i67 < 3; c8_i67 = c8_i67 + 1) {
    c8_b_q4[c8_i67] = c8_q4[c8_i67];
  }

  c8_b_q4[3] = 1.0;
  sf_debug_symbol_switch(36U, 68U);
  _SFD_SCRIPT_CALL(0, 59);
  for (c8_i68 = 0; c8_i68 < 3; c8_i68 = c8_i68 + 1) {
    c8_b_q5[c8_i68] = c8_q5[c8_i68];
  }

  c8_b_q5[3] = 1.0;
  sf_debug_symbol_switch(39U, 69U);
  _SFD_SCRIPT_CALL(0, 60);
  for (c8_i69 = 0; c8_i69 < 3; c8_i69 = c8_i69 + 1) {
    c8_b_q6[c8_i69] = c8_q6[c8_i69];
  }

  c8_b_q6[3] = 1.0;
  sf_debug_symbol_switch(42U, 70U);
  _SFD_SCRIPT_CALL(0, 61);
  for (c8_i70 = 0; c8_i70 < 3; c8_i70 = c8_i70 + 1) {
    c8_b_q7[c8_i70] = c8_q7[c8_i70];
  }

  c8_b_q7[3] = 1.0;
  sf_debug_symbol_switch(44U, 71U);
  _SFD_SCRIPT_CALL(0, 62);
  for (c8_i71 = 0; c8_i71 < 3; c8_i71 = c8_i71 + 1) {
    c8_b_pw[c8_i71] = c8_pw[c8_i71];
  }

  c8_b_pw[3] = 1.0;
  sf_debug_symbol_switch(34U, 72U);
  _SFD_SCRIPT_CALL(0, 65);
  c8_gst0[0] = 1.0;
  c8_gst0[4] = 0.0;
  c8_gst0[8] = 0.0;
  c8_gst0[12] = ((c8_L2 + c8_L5) + c8_L6) + c8_L7;
  c8_gst0[1] = 0.0;
  c8_gst0[5] = 1.0;
  c8_gst0[9] = 0.0;
  c8_gst0[13] = c8_L8;
  c8_gst0[2] = 0.0;
  c8_gst0[6] = 0.0;
  c8_gst0[10] = 1.0;
  c8_gst0[14] = ((c8_L1 + c8_L3) + c8_L4) + c8_L9;
  c8_i72 = 0;
  for (c8_i73 = 0; c8_i73 < 4; c8_i73 = c8_i73 + 1) {
    c8_gst0[c8_i72 + 3] = c8_dv18[c8_i73];
    c8_i72 = c8_i72 + 4;
  }

  _SFD_SCRIPT_CALL(0, 67);
  for (c8_i74 = 0; c8_i74 < 2; c8_i74 = c8_i74 + 1) {
    c8_bv0[c8_i74] = TRUE;
  }

  CV_SCRIPT_IF(0, 0, c8_all(chartInstance, c8_bv0));
  _SFD_SCRIPT_CALL(0, 68);
  for (c8_i75 = 0; c8_i75 < 16; c8_i75 = c8_i75 + 1) {
    c8_b_gd[c8_i75] = c8_gd[c8_i75];
  }

  for (c8_i76 = 0; c8_i76 < 16; c8_i76 = c8_i76 + 1) {
    c8_b_gst0[c8_i76] = c8_gst0[c8_i76];
  }

  c8_mrdivide(chartInstance, c8_b_gd, c8_b_gst0, c8_dv19);
  for (c8_i77 = 0; c8_i77 < 16; c8_i77 = c8_i77 + 1) {
    c8_g1[c8_i77] = c8_dv19[c8_i77];
  }

  /*  gd*inv(gst0) */
  /*  select pw = [L2+L5;0;L1+L3+L4] */
  _SFD_SCRIPT_CALL(0, 83);
  for (c8_i78 = 0; c8_i78 < 16; c8_i78 = c8_i78 + 1) {
    c8_a[c8_i78] = c8_g1[c8_i78];
  }

  for (c8_i79 = 0; c8_i79 < 4; c8_i79 = c8_i79 + 1) {
    c8_b[c8_i79] = c8_b_pw[c8_i79];
  }

  c8_d_eml_scalar_eg(chartInstance);
  c8_d_eml_scalar_eg(chartInstance);
  for (c8_i80 = 0; c8_i80 < 16; c8_i80 = c8_i80 + 1) {
    c8_A[c8_i80] = c8_a[c8_i80];
  }

  for (c8_i81 = 0; c8_i81 < 4; c8_i81 = c8_i81 + 1) {
    c8_B[c8_i81] = c8_b[c8_i81];
  }

  for (c8_i82 = 0; c8_i82 < 4; c8_i82 = c8_i82 + 1) {
    c8_p1[c8_i82] = 0.0;
  }

  for (c8_i83 = 0; c8_i83 < 16; c8_i83 = c8_i83 + 1) {
    c8_b_A[c8_i83] = c8_A[c8_i83];
  }

  for (c8_i84 = 0; c8_i84 < 4; c8_i84 = c8_i84 + 1) {
    c8_b_B[c8_i84] = c8_B[c8_i84];
  }

  for (c8_i85 = 0; c8_i85 < 16; c8_i85 = c8_i85 + 1) {
    c8_c_A[c8_i85] = c8_b_A[c8_i85];
  }

  for (c8_i86 = 0; c8_i86 < 4; c8_i86 = c8_i86 + 1) {
    c8_c_B[c8_i86] = c8_b_B[c8_i86];
  }

  for (c8_i87 = 0; c8_i87 < 4; c8_i87 = c8_i87 + 1) {
    c8_p1[c8_i87] = 0.0;
    c8_i88 = 0;
    for (c8_i89 = 0; c8_i89 < 4; c8_i89 = c8_i89 + 1) {
      c8_p1[c8_i87] = c8_p1[c8_i87] + c8_c_A[c8_i88 + c8_i87] * c8_c_B[c8_i89];
      c8_i88 = c8_i88 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 84);
  c8_theta_1 = c8_atan2(chartInstance, c8_p1[1], c8_p1[0]);

  /*  only one solution */
  _SFD_SCRIPT_CALL(0, 85);
  if (CV_SCRIPT_IF(0, 2, (real_T)c8_isInRange(chartInstance, c8_theta_1, -165.0,
        165.0) == 0.0)) {
    /* disp('Cannot find appropriate theta_1'); */
  } else {
    /*  select q2 = [L2;0;L1], subproblem3 */
    _SFD_SCRIPT_CALL(0, 91);
    for (c8_i90 = 0; c8_i90 < 6; c8_i90 = c8_i90 + 1) {
      c8_dv21[c8_i90] = c8_dv20[c8_i90];
    }

    c8_expWre(chartInstance, c8_dv21, c8_theta_1, c8_b_a);
    for (c8_i91 = 0; c8_i91 < 4; c8_i91 = c8_i91 + 1) {
      c8_b_b[c8_i91] = c8_p1[c8_i91];
    }

    c8_d_eml_scalar_eg(chartInstance);
    c8_d_eml_scalar_eg(chartInstance);
    for (c8_i92 = 0; c8_i92 < 16; c8_i92 = c8_i92 + 1) {
      c8_d_A[c8_i92] = c8_b_a[c8_i92];
    }

    for (c8_i93 = 0; c8_i93 < 4; c8_i93 = c8_i93 + 1) {
      c8_d_B[c8_i93] = c8_b_b[c8_i93];
    }

    for (c8_i94 = 0; c8_i94 < 4; c8_i94 = c8_i94 + 1) {
      c8_p2[c8_i94] = 0.0;
    }

    for (c8_i95 = 0; c8_i95 < 16; c8_i95 = c8_i95 + 1) {
      c8_e_A[c8_i95] = c8_d_A[c8_i95];
    }

    for (c8_i96 = 0; c8_i96 < 4; c8_i96 = c8_i96 + 1) {
      c8_e_B[c8_i96] = c8_d_B[c8_i96];
    }

    for (c8_i97 = 0; c8_i97 < 16; c8_i97 = c8_i97 + 1) {
      c8_f_A[c8_i97] = c8_e_A[c8_i97];
    }

    for (c8_i98 = 0; c8_i98 < 4; c8_i98 = c8_i98 + 1) {
      c8_f_B[c8_i98] = c8_e_B[c8_i98];
    }

    for (c8_i99 = 0; c8_i99 < 4; c8_i99 = c8_i99 + 1) {
      c8_p2[c8_i99] = 0.0;
      c8_i100 = 0;
      for (c8_i101 = 0; c8_i101 < 4; c8_i101 = c8_i101 + 1) {
        c8_p2[c8_i99] = c8_p2[c8_i99] + c8_f_A[c8_i100 + c8_i99] *
          c8_f_B[c8_i101];
        c8_i100 = c8_i100 + 4;
      }
    }

    _SFD_SCRIPT_CALL(0, 92);
    for (c8_i102 = 0; c8_i102 < 4; c8_i102 = c8_i102 + 1) {
      c8_d[c8_i102] = c8_p2[c8_i102] - c8_b_q2[c8_i102];
    }

    _SFD_SCRIPT_CALL(0, 93);
    for (c8_i103 = 0; c8_i103 < 6; c8_i103 = c8_i103 + 1) {
      c8_b_kx3[c8_i103] = c8_kx3[c8_i103];
    }

    for (c8_i104 = 0; c8_i104 < 4; c8_i104 = c8_i104 + 1) {
      c8_c_pw[c8_i104] = c8_b_pw[c8_i104];
    }

    for (c8_i105 = 0; c8_i105 < 4; c8_i105 = c8_i105 + 1) {
      c8_d_q2[c8_i105] = c8_b_q2[c8_i105];
    }

    for (c8_i106 = 0; c8_i106 < 4; c8_i106 = c8_i106 + 1) {
      c8_b_d[c8_i106] = c8_d[c8_i106];
    }

    c8_subPro3(chartInstance, c8_b_kx3, c8_c_pw, c8_d_q2, c8_b_d, c8_b_theta_3,
               &c8_b_Num_3);
    for (c8_i107 = 0; c8_i107 < 2; c8_i107 = c8_i107 + 1) {
      c8_theta_3[c8_i107] = c8_b_theta_3[c8_i107];
    }

    c8_Num_3 = c8_b_Num_3;

    /*  at most 2 solutions */
    _SFD_SCRIPT_CALL(0, 94);
    for (c8_i108 = 0; c8_i108 < 2; c8_i108 = c8_i108 + 1) {
      c8_c_theta_3[c8_i108] = c8_theta_3[c8_i108];
    }

    c8_b_isInRange(chartInstance, c8_c_theta_3, -210.0, 90.0, c8_bv1);
    for (c8_i109 = 0; c8_i109 < 2; c8_i109 = c8_i109 + 1) {
      c8_bv2[c8_i109] = ((real_T)c8_bv1[c8_i109] == 1.0);
    }

    if (CV_SCRIPT_IF(0, 3, (real_T)c8_any(chartInstance, c8_bv2) == 0.0)) {
      /* disp('Cannot find appropriate theta_3'); */
    } else {
      /*   */
      c8_c3 = 1.0;
      c8_b_c3 = 1.0;
     label_2:
      ;
      if (c8_b_c3 <= c8_Num_3) {
        c8_c3 = c8_b_c3;
        CV_SCRIPT_FOR(0, 0, 1);
        _SFD_SCRIPT_CALL(0, 102);
        if (CV_SCRIPT_IF(0, 4, (real_T)c8_isInRange(chartInstance,
              c8_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_3", (int32_T)
               _SFD_INTEGER_CHECK("c3", c8_c3), 1, 2, 1, 0) - 1], -210.0, 90.0) ==
                         1.0)) {
          _SFD_SCRIPT_CALL(0, 103);
          for (c8_i110 = 0; c8_i110 < 6; c8_i110 = c8_i110 + 1) {
            c8_c_kx3[c8_i110] = c8_kx3[c8_i110];
          }

          c8_expWre(chartInstance, c8_c_kx3,
                    c8_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_3", (int32_T)
                     _SFD_INTEGER_CHECK("c3", c8_c3), 1, 2
                     , 1, 0) - 1], c8_c_a);
          for (c8_i111 = 0; c8_i111 < 4; c8_i111 = c8_i111 + 1) {
            c8_c_b[c8_i111] = c8_b_pw[c8_i111];
          }

          c8_d_eml_scalar_eg(chartInstance);
          c8_d_eml_scalar_eg(chartInstance);
          for (c8_i112 = 0; c8_i112 < 16; c8_i112 = c8_i112 + 1) {
            c8_g_A[c8_i112] = c8_c_a[c8_i112];
          }

          for (c8_i113 = 0; c8_i113 < 4; c8_i113 = c8_i113 + 1) {
            c8_g_B[c8_i113] = c8_c_b[c8_i113];
          }

          for (c8_i114 = 0; c8_i114 < 4; c8_i114 = c8_i114 + 1) {
            c8_p3[c8_i114] = 0.0;
          }

          for (c8_i115 = 0; c8_i115 < 16; c8_i115 = c8_i115 + 1) {
            c8_h_A[c8_i115] = c8_g_A[c8_i115];
          }

          for (c8_i116 = 0; c8_i116 < 4; c8_i116 = c8_i116 + 1) {
            c8_h_B[c8_i116] = c8_g_B[c8_i116];
          }

          for (c8_i117 = 0; c8_i117 < 16; c8_i117 = c8_i117 + 1) {
            c8_i_A[c8_i117] = c8_h_A[c8_i117];
          }

          for (c8_i118 = 0; c8_i118 < 4; c8_i118 = c8_i118 + 1) {
            c8_i_B[c8_i118] = c8_h_B[c8_i118];
          }

          for (c8_i119 = 0; c8_i119 < 4; c8_i119 = c8_i119 + 1) {
            c8_p3[c8_i119] = 0.0;
            c8_i120 = 0;
            for (c8_i121 = 0; c8_i121 < 4; c8_i121 = c8_i121 + 1) {
              c8_p3[c8_i119] = c8_p3[c8_i119] + c8_i_A[c8_i120 + c8_i119] *
                c8_i_B[c8_i121];
              c8_i120 = c8_i120 + 4;
            }
          }

          _SFD_SCRIPT_CALL(0, 104);
          for (c8_i122 = 0; c8_i122 < 6; c8_i122 = c8_i122 + 1) {
            c8_b_kx2[c8_i122] = c8_kx2[c8_i122];
          }

          for (c8_i123 = 0; c8_i123 < 4; c8_i123 = c8_i123 + 1) {
            c8_b_p3[c8_i123] = c8_p3[c8_i123];
          }

          for (c8_i124 = 0; c8_i124 < 4; c8_i124 = c8_i124 + 1) {
            c8_b_p2[c8_i124] = c8_p2[c8_i124];
          }

          c8_theta_2 = c8_subPro1(chartInstance, c8_b_kx2, c8_b_p3, c8_b_p2);

          /*  only one solution */
          _SFD_SCRIPT_CALL(0, 105);
          if (CV_SCRIPT_IF(0, 5, (real_T)c8_isInRange(chartInstance, c8_theta_2,
                -150.0, 60.0) == 0.0)) {
            /* disp('Cannot find appropriate theta_2'); */
            goto label_1;
          } else {
            _SFD_SCRIPT_CALL(0, 110);
            for (c8_i125 = 0; c8_i125 < 6; c8_i125 = c8_i125 + 1) {
              c8_d_kx3[c8_i125] = -c8_kx3[c8_i125];
            }

            c8_expWre(chartInstance, c8_d_kx3,
                      c8_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_3", (int32_T)
                       _SFD_INTEGER_CHECK("c3", c8_c3), 1, 2
                       , 1, 0) - 1], c8_d_a);
            for (c8_i126 = 0; c8_i126 < 6; c8_i126 = c8_i126 + 1) {
              c8_c_kx2[c8_i126] = -c8_kx2[c8_i126];
            }

            c8_expWre(chartInstance, c8_c_kx2, c8_theta_2, c8_d_b);
            c8_b_eml_scalar_eg(chartInstance);
            c8_b_eml_scalar_eg(chartInstance);
            for (c8_i127 = 0; c8_i127 < 16; c8_i127 = c8_i127 + 1) {
              c8_j_A[c8_i127] = c8_d_a[c8_i127];
            }

            for (c8_i128 = 0; c8_i128 < 16; c8_i128 = c8_i128 + 1) {
              c8_j_B[c8_i128] = c8_d_b[c8_i128];
            }

            for (c8_i129 = 0; c8_i129 < 16; c8_i129 = c8_i129 + 1) {
              c8_k_A[c8_i129] = c8_j_A[c8_i129];
            }

            for (c8_i130 = 0; c8_i130 < 16; c8_i130 = c8_i130 + 1) {
              c8_k_B[c8_i130] = c8_j_B[c8_i130];
            }

            for (c8_i131 = 0; c8_i131 < 16; c8_i131 = c8_i131 + 1) {
              c8_l_A[c8_i131] = c8_k_A[c8_i131];
            }

            for (c8_i132 = 0; c8_i132 < 16; c8_i132 = c8_i132 + 1) {
              c8_l_B[c8_i132] = c8_k_B[c8_i132];
            }

            for (c8_i133 = 0; c8_i133 < 4; c8_i133 = c8_i133 + 1) {
              c8_i134 = 0;
              for (c8_i135 = 0; c8_i135 < 4; c8_i135 = c8_i135 + 1) {
                c8_y[c8_i134 + c8_i133] = 0.0;
                c8_i136 = 0;
                for (c8_i137 = 0; c8_i137 < 4; c8_i137 = c8_i137 + 1) {
                  c8_y[c8_i134 + c8_i133] = c8_y[c8_i134 + c8_i133] +
                    c8_l_A[c8_i136 + c8_i133] * c8_l_B[c8_i137 + c8_i134];
                  c8_i136 = c8_i136 + 4;
                }

                c8_i134 = c8_i134 + 4;
              }
            }

            for (c8_i138 = 0; c8_i138 < 16; c8_i138 = c8_i138 + 1) {
              c8_e_a[c8_i138] = c8_y[c8_i138];
            }

            for (c8_i139 = 0; c8_i139 < 6; c8_i139 = c8_i139 + 1) {
              c8_dv22[c8_i139] = c8_dv20[c8_i139];
            }

            c8_expWre(chartInstance, c8_dv22, c8_theta_1, c8_e_b);
            c8_b_eml_scalar_eg(chartInstance);
            c8_b_eml_scalar_eg(chartInstance);
            for (c8_i140 = 0; c8_i140 < 16; c8_i140 = c8_i140 + 1) {
              c8_m_A[c8_i140] = c8_e_a[c8_i140];
            }

            for (c8_i141 = 0; c8_i141 < 16; c8_i141 = c8_i141 + 1) {
              c8_m_B[c8_i141] = c8_e_b[c8_i141];
            }

            for (c8_i142 = 0; c8_i142 < 16; c8_i142 = c8_i142 + 1) {
              c8_n_A[c8_i142] = c8_m_A[c8_i142];
            }

            for (c8_i143 = 0; c8_i143 < 16; c8_i143 = c8_i143 + 1) {
              c8_n_B[c8_i143] = c8_m_B[c8_i143];
            }

            for (c8_i144 = 0; c8_i144 < 16; c8_i144 = c8_i144 + 1) {
              c8_o_A[c8_i144] = c8_n_A[c8_i144];
            }

            for (c8_i145 = 0; c8_i145 < 16; c8_i145 = c8_i145 + 1) {
              c8_o_B[c8_i145] = c8_n_B[c8_i145];
            }

            for (c8_i146 = 0; c8_i146 < 4; c8_i146 = c8_i146 + 1) {
              c8_i147 = 0;
              for (c8_i148 = 0; c8_i148 < 4; c8_i148 = c8_i148 + 1) {
                c8_b_y[c8_i147 + c8_i146] = 0.0;
                c8_i149 = 0;
                for (c8_i150 = 0; c8_i150 < 4; c8_i150 = c8_i150 + 1) {
                  c8_b_y[c8_i147 + c8_i146] = c8_b_y[c8_i147 + c8_i146] +
                    c8_o_A[c8_i149 + c8_i146] * c8_o_B[c8_i150 + c8_i147];
                  c8_i149 = c8_i149 + 4;
                }

                c8_i147 = c8_i147 + 4;
              }
            }

            for (c8_i151 = 0; c8_i151 < 16; c8_i151 = c8_i151 + 1) {
              c8_f_a[c8_i151] = c8_b_y[c8_i151];
            }

            for (c8_i152 = 0; c8_i152 < 16; c8_i152 = c8_i152 + 1) {
              c8_f_b[c8_i152] = c8_g1[c8_i152];
            }

            c8_b_eml_scalar_eg(chartInstance);
            c8_b_eml_scalar_eg(chartInstance);
            for (c8_i153 = 0; c8_i153 < 16; c8_i153 = c8_i153 + 1) {
              c8_p_A[c8_i153] = c8_f_a[c8_i153];
            }

            for (c8_i154 = 0; c8_i154 < 16; c8_i154 = c8_i154 + 1) {
              c8_p_B[c8_i154] = c8_f_b[c8_i154];
            }

            for (c8_i155 = 0; c8_i155 < 16; c8_i155 = c8_i155 + 1) {
              c8_g2[c8_i155] = 0.0;
            }

            for (c8_i156 = 0; c8_i156 < 16; c8_i156 = c8_i156 + 1) {
              c8_q_A[c8_i156] = c8_p_A[c8_i156];
            }

            for (c8_i157 = 0; c8_i157 < 16; c8_i157 = c8_i157 + 1) {
              c8_q_B[c8_i157] = c8_p_B[c8_i157];
            }

            for (c8_i158 = 0; c8_i158 < 16; c8_i158 = c8_i158 + 1) {
              c8_r_A[c8_i158] = c8_q_A[c8_i158];
            }

            for (c8_i159 = 0; c8_i159 < 16; c8_i159 = c8_i159 + 1) {
              c8_r_B[c8_i159] = c8_q_B[c8_i159];
            }

            for (c8_i160 = 0; c8_i160 < 4; c8_i160 = c8_i160 + 1) {
              c8_i161 = 0;
              for (c8_i162 = 0; c8_i162 < 4; c8_i162 = c8_i162 + 1) {
                c8_g2[c8_i161 + c8_i160] = 0.0;
                c8_i163 = 0;
                for (c8_i164 = 0; c8_i164 < 4; c8_i164 = c8_i164 + 1) {
                  c8_g2[c8_i161 + c8_i160] = c8_g2[c8_i161 + c8_i160] +
                    c8_r_A[c8_i163 + c8_i160] * c8_r_B[c8_i164 + c8_i161];
                  c8_i163 = c8_i163 + 4;
                }

                c8_i161 = c8_i161 + 4;
              }
            }

            /* select q7 */
            _SFD_SCRIPT_CALL(0, 113);
            for (c8_i165 = 0; c8_i165 < 16; c8_i165 = c8_i165 + 1) {
              c8_g_a[c8_i165] = c8_g2[c8_i165];
            }

            for (c8_i166 = 0; c8_i166 < 4; c8_i166 = c8_i166 + 1) {
              c8_g_b[c8_i166] = c8_b_q7[c8_i166];
            }

            c8_d_eml_scalar_eg(chartInstance);
            c8_d_eml_scalar_eg(chartInstance);
            for (c8_i167 = 0; c8_i167 < 16; c8_i167 = c8_i167 + 1) {
              c8_s_A[c8_i167] = c8_g_a[c8_i167];
            }

            for (c8_i168 = 0; c8_i168 < 4; c8_i168 = c8_i168 + 1) {
              c8_s_B[c8_i168] = c8_g_b[c8_i168];
            }

            for (c8_i169 = 0; c8_i169 < 4; c8_i169 = c8_i169 + 1) {
              c8_p4[c8_i169] = 0.0;
            }

            for (c8_i170 = 0; c8_i170 < 16; c8_i170 = c8_i170 + 1) {
              c8_t_A[c8_i170] = c8_s_A[c8_i170];
            }

            for (c8_i171 = 0; c8_i171 < 4; c8_i171 = c8_i171 + 1) {
              c8_t_B[c8_i171] = c8_s_B[c8_i171];
            }

            for (c8_i172 = 0; c8_i172 < 16; c8_i172 = c8_i172 + 1) {
              c8_u_A[c8_i172] = c8_t_A[c8_i172];
            }

            for (c8_i173 = 0; c8_i173 < 4; c8_i173 = c8_i173 + 1) {
              c8_u_B[c8_i173] = c8_t_B[c8_i173];
            }

            for (c8_i174 = 0; c8_i174 < 4; c8_i174 = c8_i174 + 1) {
              c8_p4[c8_i174] = 0.0;
              c8_i175 = 0;
              for (c8_i176 = 0; c8_i176 < 4; c8_i176 = c8_i176 + 1) {
                c8_p4[c8_i174] = c8_p4[c8_i174] + c8_u_A[c8_i175 + c8_i174] *
                  c8_u_B[c8_i176];
                c8_i175 = c8_i175 + 4;
              }
            }

            _SFD_SCRIPT_CALL(0, 114);
            for (c8_i177 = 0; c8_i177 < 6; c8_i177 = c8_i177 + 1) {
              c8_b_kx4[c8_i177] = c8_kx4[c8_i177];
            }

            for (c8_i178 = 0; c8_i178 < 6; c8_i178 = c8_i178 + 1) {
              c8_b_kx5[c8_i178] = c8_kx5[c8_i178];
            }

            for (c8_i179 = 0; c8_i179 < 4; c8_i179 = c8_i179 + 1) {
              c8_c_q7[c8_i179] = c8_b_q7[c8_i179];
            }

            for (c8_i180 = 0; c8_i180 < 4; c8_i180 = c8_i180 + 1) {
              c8_b_p4[c8_i180] = c8_p4[c8_i180];
            }

            c8_subPro2(chartInstance, c8_b_kx4, c8_b_kx5, c8_c_q7, c8_b_p4,
                       c8_b_theta_4, c8_b_theta_5, &c8_b_Num_45);
            for (c8_i181 = 0; c8_i181 < 2; c8_i181 = c8_i181 + 1) {
              c8_theta_4[c8_i181] = c8_b_theta_4[c8_i181];
            }

            for (c8_i182 = 0; c8_i182 < 2; c8_i182 = c8_i182 + 1) {
              c8_theta_5[c8_i182] = c8_b_theta_5[c8_i182];
            }

            c8_Num_45 = c8_b_Num_45;

            /*  at most 2 pairs of solution */
            _SFD_SCRIPT_CALL(0, 116);
            for (c8_i183 = 0; c8_i183 < 2; c8_i183 = c8_i183 + 1) {
              c8_c_theta_5[c8_i183] = c8_theta_5[c8_i183];
            }

            c8_b_isInRange(chartInstance, c8_c_theta_5, -140.0, 140.0, c8_bv3);
            for (c8_i184 = 0; c8_i184 < 2; c8_i184 = c8_i184 + 1) {
              c8_bv4[c8_i184] = ((real_T)c8_bv3[c8_i184] == 1.0);
            }

            if (CV_SCRIPT_IF(0, 6, (real_T)c8_any(chartInstance, c8_bv4) == 0.0))
            {
              /* disp('Cannot find appropriate theta_5'); */
              goto label_1;
            } else {
              c8_c45 = 1.0;
              c8_b_c45 = 1.0;
              while (c8_b_c45 <= c8_Num_45) {
                c8_c45 = c8_b_c45;
                CV_SCRIPT_FOR(0, 1, 1);
                _SFD_SCRIPT_CALL(0, 122);
                if (CV_SCRIPT_IF(0, 7, (real_T)c8_isInRange(chartInstance,
                      c8_theta_5[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_5", (int32_T)
                       _SFD_INTEGER_CHECK("c45", c8_c45), 1, 2, 1, 0) - 1],
                      -140.0, 140.0) == 1.0)) {
                  _SFD_SCRIPT_CALL(0, 123);
                  for (c8_i185 = 0; c8_i185 < 6; c8_i185 = c8_i185 + 1) {
                    c8_c_kx5[c8_i185] = -c8_kx5[c8_i185];
                  }

                  c8_expWre(chartInstance, c8_c_kx5,
                            c8_theta_5[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_5",
                             (int32_T)_SFD_INTEGER_CHECK("c45", c8_c45), 1,
                             2, 1, 0) - 1], c8_h_a);
                  for (c8_i186 = 0; c8_i186 < 6; c8_i186 = c8_i186 + 1) {
                    c8_c_kx4[c8_i186] = -c8_kx4[c8_i186];
                  }

                  c8_expWre(chartInstance, c8_c_kx4,
                            c8_theta_4[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_4",
                             (int32_T)_SFD_INTEGER_CHECK("c45", c8_c45), 1,
                             2, 1, 0) - 1], c8_h_b);
                  c8_b_eml_scalar_eg(chartInstance);
                  c8_b_eml_scalar_eg(chartInstance);
                  for (c8_i187 = 0; c8_i187 < 16; c8_i187 = c8_i187 + 1) {
                    c8_v_A[c8_i187] = c8_h_a[c8_i187];
                  }

                  for (c8_i188 = 0; c8_i188 < 16; c8_i188 = c8_i188 + 1) {
                    c8_v_B[c8_i188] = c8_h_b[c8_i188];
                  }

                  for (c8_i189 = 0; c8_i189 < 16; c8_i189 = c8_i189 + 1) {
                    c8_w_A[c8_i189] = c8_v_A[c8_i189];
                  }

                  for (c8_i190 = 0; c8_i190 < 16; c8_i190 = c8_i190 + 1) {
                    c8_w_B[c8_i190] = c8_v_B[c8_i190];
                  }

                  for (c8_i191 = 0; c8_i191 < 16; c8_i191 = c8_i191 + 1) {
                    c8_x_A[c8_i191] = c8_w_A[c8_i191];
                  }

                  for (c8_i192 = 0; c8_i192 < 16; c8_i192 = c8_i192 + 1) {
                    c8_x_B[c8_i192] = c8_w_B[c8_i192];
                  }

                  for (c8_i193 = 0; c8_i193 < 4; c8_i193 = c8_i193 + 1) {
                    c8_i194 = 0;
                    for (c8_i195 = 0; c8_i195 < 4; c8_i195 = c8_i195 + 1) {
                      c8_c_y[c8_i194 + c8_i193] = 0.0;
                      c8_i196 = 0;
                      for (c8_i197 = 0; c8_i197 < 4; c8_i197 = c8_i197 + 1) {
                        c8_c_y[c8_i194 + c8_i193] = c8_c_y[c8_i194 + c8_i193] +
                          c8_x_A[c8_i196 + c8_i193] * c8_x_B[c8_i197 + c8_i194];
                        c8_i196 = c8_i196 + 4;
                      }

                      c8_i194 = c8_i194 + 4;
                    }
                  }

                  for (c8_i198 = 0; c8_i198 < 16; c8_i198 = c8_i198 + 1) {
                    c8_i_a[c8_i198] = c8_c_y[c8_i198];
                  }

                  for (c8_i199 = 0; c8_i199 < 16; c8_i199 = c8_i199 + 1) {
                    c8_i_b[c8_i199] = c8_g2[c8_i199];
                  }

                  c8_b_eml_scalar_eg(chartInstance);
                  c8_b_eml_scalar_eg(chartInstance);
                  for (c8_i200 = 0; c8_i200 < 16; c8_i200 = c8_i200 + 1) {
                    c8_y_A[c8_i200] = c8_i_a[c8_i200];
                  }

                  for (c8_i201 = 0; c8_i201 < 16; c8_i201 = c8_i201 + 1) {
                    c8_y_B[c8_i201] = c8_i_b[c8_i201];
                  }

                  for (c8_i202 = 0; c8_i202 < 16; c8_i202 = c8_i202 + 1) {
                    c8_g3[c8_i202] = 0.0;
                  }

                  for (c8_i203 = 0; c8_i203 < 16; c8_i203 = c8_i203 + 1) {
                    c8_ab_A[c8_i203] = c8_y_A[c8_i203];
                  }

                  for (c8_i204 = 0; c8_i204 < 16; c8_i204 = c8_i204 + 1) {
                    c8_ab_B[c8_i204] = c8_y_B[c8_i204];
                  }

                  for (c8_i205 = 0; c8_i205 < 16; c8_i205 = c8_i205 + 1) {
                    c8_bb_A[c8_i205] = c8_ab_A[c8_i205];
                  }

                  for (c8_i206 = 0; c8_i206 < 16; c8_i206 = c8_i206 + 1) {
                    c8_bb_B[c8_i206] = c8_ab_B[c8_i206];
                  }

                  for (c8_i207 = 0; c8_i207 < 4; c8_i207 = c8_i207 + 1) {
                    c8_i208 = 0;
                    for (c8_i209 = 0; c8_i209 < 4; c8_i209 = c8_i209 + 1) {
                      c8_g3[c8_i208 + c8_i207] = 0.0;
                      c8_i210 = 0;
                      for (c8_i211 = 0; c8_i211 < 4; c8_i211 = c8_i211 + 1) {
                        c8_g3[c8_i208 + c8_i207] = c8_g3[c8_i208 + c8_i207] +
                          c8_bb_A[c8_i210 + c8_i207] * c8_bb_B[c8_i211 + c8_i208];
                        c8_i210 = c8_i210 + 4;
                      }

                      c8_i208 = c8_i208 + 4;
                    }
                  }

                  /* selcet q3 */
                  _SFD_SCRIPT_CALL(0, 125);
                  for (c8_i212 = 0; c8_i212 < 16; c8_i212 = c8_i212 + 1) {
                    c8_j_a[c8_i212] = c8_g3[c8_i212];
                  }

                  for (c8_i213 = 0; c8_i213 < 4; c8_i213 = c8_i213 + 1) {
                    c8_j_b[c8_i213] = c8_b_q3[c8_i213];
                  }

                  c8_d_eml_scalar_eg(chartInstance);
                  c8_d_eml_scalar_eg(chartInstance);
                  for (c8_i214 = 0; c8_i214 < 16; c8_i214 = c8_i214 + 1) {
                    c8_cb_A[c8_i214] = c8_j_a[c8_i214];
                  }

                  for (c8_i215 = 0; c8_i215 < 4; c8_i215 = c8_i215 + 1) {
                    c8_cb_B[c8_i215] = c8_j_b[c8_i215];
                  }

                  for (c8_i216 = 0; c8_i216 < 4; c8_i216 = c8_i216 + 1) {
                    c8_p5[c8_i216] = 0.0;
                  }

                  for (c8_i217 = 0; c8_i217 < 16; c8_i217 = c8_i217 + 1) {
                    c8_db_A[c8_i217] = c8_cb_A[c8_i217];
                  }

                  for (c8_i218 = 0; c8_i218 < 4; c8_i218 = c8_i218 + 1) {
                    c8_db_B[c8_i218] = c8_cb_B[c8_i218];
                  }

                  for (c8_i219 = 0; c8_i219 < 16; c8_i219 = c8_i219 + 1) {
                    c8_eb_A[c8_i219] = c8_db_A[c8_i219];
                  }

                  for (c8_i220 = 0; c8_i220 < 4; c8_i220 = c8_i220 + 1) {
                    c8_eb_B[c8_i220] = c8_db_B[c8_i220];
                  }

                  for (c8_i221 = 0; c8_i221 < 4; c8_i221 = c8_i221 + 1) {
                    c8_p5[c8_i221] = 0.0;
                    c8_i222 = 0;
                    for (c8_i223 = 0; c8_i223 < 4; c8_i223 = c8_i223 + 1) {
                      c8_p5[c8_i221] = c8_p5[c8_i221] + c8_eb_A[c8_i222 +
                        c8_i221] * c8_eb_B[c8_i223];
                      c8_i222 = c8_i222 + 4;
                    }
                  }

                  _SFD_SCRIPT_CALL(0, 126);
                  for (c8_i224 = 0; c8_i224 < 6; c8_i224 = c8_i224 + 1) {
                    c8_b_kx6[c8_i224] = c8_kx6[c8_i224];
                  }

                  for (c8_i225 = 0; c8_i225 < 4; c8_i225 = c8_i225 + 1) {
                    c8_d_q3[c8_i225] = c8_b_q3[c8_i225];
                  }

                  for (c8_i226 = 0; c8_i226 < 4; c8_i226 = c8_i226 + 1) {
                    c8_b_p5[c8_i226] = c8_p5[c8_i226];
                  }

                  c8_theta_6 = c8_subPro1(chartInstance, c8_b_kx6, c8_d_q3,
                    c8_b_p5);

                  /*  only one solution */
                  _SFD_SCRIPT_CALL(0, 128);
                  *c8_Num = *c8_Num + 1.0;
                  _SFD_SCRIPT_CALL(0, 129);
                  c8_b_Num = _SFD_EML_ARRAY_BOUNDS_CHECK("theta", (int32_T)
                    _SFD_INTEGER_CHECK("Num", *c8_Num), 1, 4, 2, 0) - 1;
                  c8_b_theta_1[0] = c8_theta_1;
                  c8_b_theta_1[1] = c8_theta_2;
                  c8_b_theta_1[2] = c8_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "theta_3", (int32_T)_SFD_INTEGER_CHECK("c3", c8_c3), 1, 2, 1,
                    0) - 1];
                  c8_b_theta_1[3] = c8_theta_4[_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "theta_4", (int32_T)_SFD_INTEGER_CHECK("c45", c8_c45), 1, 2,
                    1, 0) - 1];
                  c8_b_theta_1[4] = c8_theta_5[_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "theta_5", (int32_T)_SFD_INTEGER_CHECK("c45", c8_c45), 1, 2,
                    1, 0) - 1];
                  c8_b_theta_1[5] = c8_theta_6;
                  for (c8_i227 = 0; c8_i227 < 6; c8_i227 = c8_i227 + 1) {
                    c8_theta[c8_i227 + 6 * c8_b_Num] = c8_b_theta_1[c8_i227];
                  }
                }

                c8_b_c45 = c8_b_c45 + 1.0;
                sf_mex_listen_for_ctrl_c(chartInstance->S);
              }

              CV_SCRIPT_FOR(0, 1, 0);
            }
          }
        }
      } else {
        CV_SCRIPT_FOR(0, 0, 0);

        /*  check range */
        /* disp(theta*180/pi);   */
        goto label_1;
      }

      c8_b_c3 = c8_b_c3 + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
      goto label_2;
     label_1:
      ;
    }
  }

  _SFD_SCRIPT_CALL(0, -129);
  sf_debug_symbol_scope_pop();
}

static void c8_cross(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_a[3],
                     real_T c8_b[3], real_T c8_c[3])
{
  real_T c8_b_a;
  real_T c8_b_b;
  real_T c8_y;
  real_T c8_c_a;
  real_T c8_c_b;
  real_T c8_b_y;
  real_T c8_c1;
  real_T c8_d_a;
  real_T c8_d_b;
  real_T c8_c_y;
  real_T c8_e_a;
  real_T c8_e_b;
  real_T c8_d_y;
  real_T c8_c2;
  real_T c8_f_a;
  real_T c8_f_b;
  real_T c8_e_y;
  real_T c8_g_a;
  real_T c8_g_b;
  real_T c8_f_y;
  real_T c8_c3;
  c8_b_a = c8_a[1];
  c8_b_b = c8_b[2];
  c8_y = c8_b_a * c8_b_b;
  c8_c_a = c8_a[2];
  c8_c_b = c8_b[1];
  c8_b_y = c8_c_a * c8_c_b;
  c8_c1 = c8_y - c8_b_y;
  c8_d_a = c8_a[2];
  c8_d_b = c8_b[0];
  c8_c_y = c8_d_a * c8_d_b;
  c8_e_a = c8_a[0];
  c8_e_b = c8_b[2];
  c8_d_y = c8_e_a * c8_e_b;
  c8_c2 = c8_c_y - c8_d_y;
  c8_f_a = c8_a[0];
  c8_f_b = c8_b[1];
  c8_e_y = c8_f_a * c8_f_b;
  c8_g_a = c8_a[1];
  c8_g_b = c8_b[0];
  c8_f_y = c8_g_a * c8_g_b;
  c8_c3 = c8_e_y - c8_f_y;
  c8_c[0] = c8_c1;
  c8_c[1] = c8_c2;
  c8_c[2] = c8_c3;
}

static boolean_T c8_all(SFc8_DynTaskConInstanceStruct *chartInstance, boolean_T
  c8_x[2])
{
  boolean_T c8_y;
  int32_T c8_i228;
  boolean_T c8_b_x[2];
  real_T c8_k;
  real_T c8_b_k;
  for (c8_i228 = 0; c8_i228 < 2; c8_i228 = c8_i228 + 1) {
    c8_b_x[c8_i228] = c8_x[c8_i228];
  }

  c8_y = TRUE;
  c8_k = 1.0;
 label_1:
  ;
  if (c8_k <= 2.0) {
    c8_b_k = c8_k;
    if ((real_T)c8_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1] == 0.0) {
      return FALSE;
    } else {
      c8_k = c8_k + 1.0;
      goto label_1;
    }
  }

  return c8_y;
}

static void c8_mrdivide(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_A[16], real_T c8_B[16], real_T c8_y[16])
{
  int32_T c8_i229;
  int32_T c8_i230;
  int32_T c8_i231;
  int32_T c8_i232;
  real_T c8_b_A[16];
  int32_T c8_i233;
  int32_T c8_i234;
  int32_T c8_i235;
  int32_T c8_i236;
  real_T c8_b_B[16];
  int32_T c8_i237;
  real_T c8_c_A[16];
  int32_T c8_i238;
  real_T c8_c_B[16];
  int32_T c8_i239;
  real_T c8_d_A[16];
  int32_T c8_i240;
  real_T c8_d_B[16];
  int32_T c8_i241;
  real_T c8_e_A[16];
  int32_T c8_i242;
  real_T c8_f_A[16];
  int32_T c8_i243;
  real_T c8_g_A[16];
  int32_T c8_i244;
  real_T c8_h_A[16];
  int32_T c8_i245;
  real_T c8_i_A[16];
  int32_T c8_info;
  int32_T c8_ipiv[4];
  real_T c8_j_A[16];
  int32_T c8_i246;
  int32_T c8_i247;
  int32_T c8_b_ipiv[4];
  int32_T c8_b_info;
  int32_T c8_i248;
  int32_T c8_i249;
  int32_T c8_c_ipiv[4];
  int32_T c8_c_info;
  int32_T c8_i250;
  int32_T c8_i251;
  int32_T c8_d_ipiv[4];
  int32_T c8_d_info;
  int32_T c8_i252;
  real_T c8_Y[16];
  int32_T c8_i;
  int32_T c8_b_i;
  int32_T c8_ip;
  int32_T c8_j;
  int32_T c8_b_j;
  real_T c8_temp;
  int32_T c8_i253;
  real_T c8_k_A[16];
  int32_T c8_i254;
  real_T c8_b_Y[16];
  int32_T c8_i255;
  real_T c8_l_A[16];
  int32_T c8_i256;
  real_T c8_e_B[16];
  int32_T c8_i257;
  int32_T c8_i258;
  real_T c8_m_A[16];
  int32_T c8_i259;
  real_T c8_c_Y[16];
  int32_T c8_i260;
  int32_T c8_i261;
  int32_T c8_i262;
  int32_T c8_i263;
  c8_i229 = 0;
  for (c8_i230 = 0; c8_i230 < 4; c8_i230 = c8_i230 + 1) {
    c8_i231 = 0;
    for (c8_i232 = 0; c8_i232 < 4; c8_i232 = c8_i232 + 1) {
      c8_b_A[c8_i232 + c8_i229] = c8_B[c8_i231 + c8_i230];
      c8_i231 = c8_i231 + 4;
    }

    c8_i229 = c8_i229 + 4;
  }

  c8_i233 = 0;
  for (c8_i234 = 0; c8_i234 < 4; c8_i234 = c8_i234 + 1) {
    c8_i235 = 0;
    for (c8_i236 = 0; c8_i236 < 4; c8_i236 = c8_i236 + 1) {
      c8_b_B[c8_i236 + c8_i233] = c8_A[c8_i235 + c8_i234];
      c8_i235 = c8_i235 + 4;
    }

    c8_i233 = c8_i233 + 4;
  }

  for (c8_i237 = 0; c8_i237 < 16; c8_i237 = c8_i237 + 1) {
    c8_c_A[c8_i237] = c8_b_A[c8_i237];
  }

  for (c8_i238 = 0; c8_i238 < 16; c8_i238 = c8_i238 + 1) {
    c8_c_B[c8_i238] = c8_b_B[c8_i238];
  }

  for (c8_i239 = 0; c8_i239 < 16; c8_i239 = c8_i239 + 1) {
    c8_d_A[c8_i239] = c8_c_A[c8_i239];
  }

  for (c8_i240 = 0; c8_i240 < 16; c8_i240 = c8_i240 + 1) {
    c8_d_B[c8_i240] = c8_c_B[c8_i240];
  }

  for (c8_i241 = 0; c8_i241 < 16; c8_i241 = c8_i241 + 1) {
    c8_e_A[c8_i241] = c8_d_A[c8_i241];
  }

  for (c8_i242 = 0; c8_i242 < 16; c8_i242 = c8_i242 + 1) {
    c8_f_A[c8_i242] = c8_e_A[c8_i242];
  }

  for (c8_i243 = 0; c8_i243 < 16; c8_i243 = c8_i243 + 1) {
    c8_g_A[c8_i243] = c8_f_A[c8_i243];
  }

  for (c8_i244 = 0; c8_i244 < 16; c8_i244 = c8_i244 + 1) {
    c8_h_A[c8_i244] = c8_g_A[c8_i244];
  }

  for (c8_i245 = 0; c8_i245 < 16; c8_i245 = c8_i245 + 1) {
    c8_i_A[c8_i245] = c8_h_A[c8_i245];
  }

  c8_eml_matlab_zgetrf(chartInstance, c8_i_A, c8_j_A, c8_ipiv, &c8_info);
  for (c8_i246 = 0; c8_i246 < 16; c8_i246 = c8_i246 + 1) {
    c8_h_A[c8_i246] = c8_j_A[c8_i246];
  }

  for (c8_i247 = 0; c8_i247 < 4; c8_i247 = c8_i247 + 1) {
    c8_b_ipiv[c8_i247] = c8_ipiv[c8_i247];
  }

  c8_b_info = c8_info;
  for (c8_i248 = 0; c8_i248 < 16; c8_i248 = c8_i248 + 1) {
    c8_f_A[c8_i248] = c8_h_A[c8_i248];
  }

  for (c8_i249 = 0; c8_i249 < 4; c8_i249 = c8_i249 + 1) {
    c8_c_ipiv[c8_i249] = c8_b_ipiv[c8_i249];
  }

  c8_c_info = c8_b_info;
  for (c8_i250 = 0; c8_i250 < 16; c8_i250 = c8_i250 + 1) {
    c8_d_A[c8_i250] = c8_f_A[c8_i250];
  }

  for (c8_i251 = 0; c8_i251 < 4; c8_i251 = c8_i251 + 1) {
    c8_d_ipiv[c8_i251] = c8_c_ipiv[c8_i251];
  }

  c8_d_info = c8_c_info;
  if ((real_T)c8_d_info > 0.0) {
    c8_eml_warning(chartInstance);
  }

  c8_b_eml_scalar_eg(chartInstance);
  for (c8_i252 = 0; c8_i252 < 16; c8_i252 = c8_i252 + 1) {
    c8_Y[c8_i252] = c8_d_B[c8_i252];
  }

  for (c8_i = 1; c8_i < 5; c8_i = c8_i + 1) {
    c8_b_i = c8_i;
    if (c8_d_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_i), 1, 4, 1, 0) - 1] != c8_b_i) {
      c8_ip = c8_d_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c8_b_i), 1, 4, 1, 0) - 1];
      for (c8_j = 1; c8_j < 5; c8_j = c8_j + 1) {
        c8_b_j = c8_j;
        c8_temp = c8_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_b_i), 1, 4, 1, 0) - 1) + ((
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_j), 1, 4, 2, 0) - 1) << 2)];
        c8_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_b_i), 1, 4, 1, 0) - 1) + ((
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_j), 1, 4, 2, 0) - 1) << 2)] = c8_Y[(
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_ip), 1, 4, 1, 0) - 1) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(""
          , (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_b_j), 1, 4, 2, 0) - 1) <<
          2)];
        c8_Y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_ip), 1, 4, 1, 0) - 1) + ((
          _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_j), 1, 4, 2, 0) - 1) << 2)] = c8_temp;
      }
    }
  }

  for (c8_i253 = 0; c8_i253 < 16; c8_i253 = c8_i253 + 1) {
    c8_k_A[c8_i253] = c8_d_A[c8_i253];
  }

  for (c8_i254 = 0; c8_i254 < 16; c8_i254 = c8_i254 + 1) {
    c8_b_Y[c8_i254] = c8_Y[c8_i254];
  }

  c8_eml_xtrsm(chartInstance, c8_k_A, c8_b_Y, c8_Y);
  for (c8_i255 = 0; c8_i255 < 16; c8_i255 = c8_i255 + 1) {
    c8_l_A[c8_i255] = c8_d_A[c8_i255];
  }

  for (c8_i256 = 0; c8_i256 < 16; c8_i256 = c8_i256 + 1) {
    c8_e_B[c8_i256] = c8_Y[c8_i256];
  }

  for (c8_i257 = 0; c8_i257 < 16; c8_i257 = c8_i257 + 1) {
    c8_Y[c8_i257] = c8_e_B[c8_i257];
  }

  for (c8_i258 = 0; c8_i258 < 16; c8_i258 = c8_i258 + 1) {
    c8_m_A[c8_i258] = c8_l_A[c8_i258];
  }

  for (c8_i259 = 0; c8_i259 < 16; c8_i259 = c8_i259 + 1) {
    c8_c_Y[c8_i259] = c8_Y[c8_i259];
  }

  c8_eml_blas_xtrsm(chartInstance, 4, 4, 1.0, c8_m_A, 1, 4, c8_c_Y, 1, 4, c8_Y);
  c8_i260 = 0;
  for (c8_i261 = 0; c8_i261 < 4; c8_i261 = c8_i261 + 1) {
    c8_i262 = 0;
    for (c8_i263 = 0; c8_i263 < 4; c8_i263 = c8_i263 + 1) {
      c8_y[c8_i263 + c8_i260] = c8_Y[c8_i262 + c8_i261];
      c8_i262 = c8_i262 + 4;
    }

    c8_i260 = c8_i260 + 4;
  }
}

static real_T c8_power(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_a,
  real_T c8_b)
{
  real_T c8_ak;
  real_T c8_bk;
  real_T c8_x;
  real_T c8_b_x;
  c8_eml_scalar_eg(chartInstance);
  c8_ak = c8_a;
  c8_bk = c8_b;
  if (c8_ak < 0.0) {
    c8_x = c8_bk;
    c8_b_x = c8_x;
    c8_b_x = muDoubleScalarFloor(c8_b_x);
    if (c8_b_x != c8_bk) {
      c8_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c8_ak, c8_bk);
}

static void c8_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void c8_eml_error(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  int32_T c8_i264;
  static char_T c8_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r', ':'
    , 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c8_u[32];
  const mxArray *c8_y = NULL;
  int32_T c8_i265;
  static char_T c8_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ',', ' ', 'm', 'a', 'k', 'e', ' ', 'a', 't', ' ', 'l', 'e', 'a', 's', 't',
    ' ', 'o', 'n', 'e', ' ',
    'i', 'n', 'p', 'u', 't', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ',', ' ',
    'e', '.', 'g', '.', ' ',
    '\'', 'p', 'o', 'w', 'e', 'r', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(',
    'a', ')', ',', 'b', ')',
    '\'', '.' };

  char_T c8_b_u[102];
  const mxArray *c8_b_y = NULL;
  for (c8_i264 = 0; c8_i264 < 32; c8_i264 = c8_i264 + 1) {
    c8_u[c8_i264] = c8_cv0[c8_i264];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c8_i265 = 0; c8_i265 < 102; c8_i265 = c8_i265 + 1) {
    c8_b_u[c8_i265] = c8_cv1[c8_i265];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c8_y, 14, c8_b_y);
}

static void c8_eps(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void c8_eml_matlab_zgetrf(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_A[16], real_T c8_b_A[16], int32_T c8_ipiv[4
  ], int32_T *c8_info)
{
  int32_T c8_i266;
  int32_T c8_i267;
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_a;
  int32_T c8_jm1;
  int32_T c8_b;
  int32_T c8_mmj;
  int32_T c8_b_a;
  int32_T c8_c;
  int32_T c8_b_b;
  int32_T c8_jj;
  int32_T c8_c_a;
  int32_T c8_jp1j;
  int32_T c8_d_a;
  int32_T c8_b_c;
  int32_T c8_i268;
  real_T c8_c_A[16];
  int32_T c8_e_a;
  int32_T c8_jpiv_offset;
  int32_T c8_f_a;
  int32_T c8_c_b;
  int32_T c8_jpiv;
  int32_T c8_g_a;
  int32_T c8_d_b;
  int32_T c8_c_c;
  int32_T c8_e_b;
  int32_T c8_jrow;
  int32_T c8_h_a;
  int32_T c8_f_b;
  int32_T c8_jprow;
  int32_T c8_i269;
  real_T c8_x[16];
  int32_T c8_ix0;
  int32_T c8_iy0;
  int32_T c8_i270;
  int32_T c8_i271;
  real_T c8_b_x[16];
  int32_T c8_b_ix0;
  int32_T c8_b_iy0;
  int32_T c8_i272;
  real_T c8_c_x[16];
  int32_T c8_i273;
  real_T c8_d_x[16];
  real_T c8_e_x[16];
  int32_T c8_i274;
  int32_T c8_i275;
  int32_T c8_b_jp1j;
  int32_T c8_i_a;
  int32_T c8_d_c;
  int32_T c8_j_a;
  int32_T c8_g_b;
  int32_T c8_loop_ub;
  int32_T c8_i;
  int32_T c8_b_i;
  real_T c8_f_x;
  real_T c8_y;
  real_T c8_g_x;
  real_T c8_b_y;
  real_T c8_z;
  int32_T c8_h_b;
  int32_T c8_e_c;
  int32_T c8_k_a;
  int32_T c8_f_c;
  int32_T c8_l_a;
  int32_T c8_g_c;
  int32_T c8_m;
  int32_T c8_n;
  int32_T c8_c_ix0;
  int32_T c8_c_iy0;
  int32_T c8_i276;
  real_T c8_d_A[16];
  int32_T c8_ia0;
  int32_T c8_i277;
  int32_T c8_b_m;
  int32_T c8_b_n;
  int32_T c8_d_ix0;
  int32_T c8_d_iy0;
  int32_T c8_i278;
  real_T c8_e_A[16];
  int32_T c8_b_ia0;
  int32_T c8_i279;
  int32_T c8_c_m;
  int32_T c8_c_n;
  int32_T c8_e_ix0;
  int32_T c8_e_iy0;
  int32_T c8_i280;
  real_T c8_f_A[16];
  int32_T c8_c_ia0;
  int32_T c8_i281;
  int32_T c8_i282;
  real_T c8_g_A[16];
  for (c8_i266 = 0; c8_i266 < 16; c8_i266 = c8_i266 + 1) {
    c8_b_A[c8_i266] = c8_A[c8_i266];
  }

  c8_eps(chartInstance);
  for (c8_i267 = 0; c8_i267 < 4; c8_i267 = c8_i267 + 1) {
    c8_ipiv[c8_i267] = 1 + c8_i267;
  }

  *c8_info = 0;
  for (c8_j = 1; c8_j < 4; c8_j = c8_j + 1) {
    c8_b_j = c8_j;
    c8_a = c8_b_j;
    c8_jm1 = c8_a - 1;
    c8_b = c8_b_j;
    c8_mmj = 4 - c8_b;
    c8_b_a = c8_jm1;
    c8_c = c8_b_a * 5;
    c8_b_b = c8_c;
    c8_jj = 1 + c8_b_b;
    c8_c_a = c8_jj;
    c8_jp1j = c8_c_a + 1;
    c8_d_a = c8_mmj;
    c8_b_c = c8_d_a + 1;
    for (c8_i268 = 0; c8_i268 < 16; c8_i268 = c8_i268 + 1) {
      c8_c_A[c8_i268] = c8_b_A[c8_i268];
    }

    c8_e_a = c8_eml_ixamax(chartInstance, c8_b_c, c8_c_A, c8_jj);
    c8_jpiv_offset = c8_e_a - 1;
    c8_f_a = c8_jj;
    c8_c_b = c8_jpiv_offset;
    c8_jpiv = c8_f_a + c8_c_b;
    if (c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if ((real_T)c8_jpiv_offset != 0.0) {
        c8_g_a = c8_b_j;
        c8_d_b = c8_jpiv_offset;
        c8_c_c = c8_g_a + c8_d_b;
        c8_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_j), 1, 4, 1, 0) - 1] = c8_c_c;
        c8_e_b = c8_jm1;
        c8_jrow = 1 + c8_e_b;
        c8_h_a = c8_jrow;
        c8_f_b = c8_jpiv_offset;
        c8_jprow = c8_h_a + c8_f_b;
        for (c8_i269 = 0; c8_i269 < 16; c8_i269 = c8_i269 + 1) {
          c8_x[c8_i269] = c8_b_A[c8_i269];
        }

        c8_ix0 = c8_jrow;
        c8_iy0 = c8_jprow;
        for (c8_i270 = 0; c8_i270 < 16; c8_i270 = c8_i270 + 1) {
          c8_b_A[c8_i270] = c8_x[c8_i270];
        }

        for (c8_i271 = 0; c8_i271 < 16; c8_i271 = c8_i271 + 1) {
          c8_b_x[c8_i271] = c8_b_A[c8_i271];
        }

        c8_b_ix0 = c8_ix0;
        c8_b_iy0 = c8_iy0;
        for (c8_i272 = 0; c8_i272 < 16; c8_i272 = c8_i272 + 1) {
          c8_c_x[c8_i272] = c8_b_x[c8_i272];
        }

        for (c8_i273 = 0; c8_i273 < 16; c8_i273 = c8_i273 + 1) {
          c8_d_x[c8_i273] = c8_c_x[c8_i273];
        }

        c8_ceval_xswap(chartInstance, 4, c8_d_x, c8_b_ix0, 4, c8_b_iy0, 4,
                       c8_e_x);
        for (c8_i274 = 0; c8_i274 < 16; c8_i274 = c8_i274 + 1) {
          c8_c_x[c8_i274] = c8_e_x[c8_i274];
        }

        for (c8_i275 = 0; c8_i275 < 16; c8_i275 = c8_i275 + 1) {
          c8_b_A[c8_i275] = c8_c_x[c8_i275];
        }
      }

      c8_b_jp1j = c8_jp1j;
      c8_i_a = c8_mmj;
      c8_d_c = c8_i_a - 1;
      c8_j_a = c8_jp1j;
      c8_g_b = c8_d_c;
      c8_loop_ub = c8_j_a + c8_g_b;
      for (c8_i = c8_b_jp1j; c8_i <= c8_loop_ub; c8_i = c8_i + 1) {
        c8_b_i = c8_i;
        c8_f_x = c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_b_i), 1, 16, 1, 0) - 1];
        c8_y = c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_jj), 1, 16, 1, 0) - 1];
        c8_g_x = c8_f_x;
        c8_b_y = c8_y;
        c8_z = c8_g_x / c8_b_y;
        c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c8_b_i), 1, 16, 1, 0) - 1] = c8_z;
      }
    } else {
      *c8_info = c8_b_j;
    }

    c8_h_b = c8_b_j;
    c8_e_c = 4 - c8_h_b;
    c8_k_a = c8_jj;
    c8_f_c = c8_k_a + 4;
    c8_l_a = c8_jj;
    c8_g_c = c8_l_a + 5;
    c8_m = c8_mmj;
    c8_n = c8_e_c;
    c8_c_ix0 = c8_jp1j;
    c8_c_iy0 = c8_f_c;
    for (c8_i276 = 0; c8_i276 < 16; c8_i276 = c8_i276 + 1) {
      c8_d_A[c8_i276] = c8_b_A[c8_i276];
    }

    c8_ia0 = c8_g_c;
    for (c8_i277 = 0; c8_i277 < 16; c8_i277 = c8_i277 + 1) {
      c8_b_A[c8_i277] = c8_d_A[c8_i277];
    }

    c8_b_m = c8_m;
    c8_b_n = c8_n;
    c8_d_ix0 = c8_c_ix0;
    c8_d_iy0 = c8_c_iy0;
    for (c8_i278 = 0; c8_i278 < 16; c8_i278 = c8_i278 + 1) {
      c8_e_A[c8_i278] = c8_b_A[c8_i278];
    }

    c8_b_ia0 = c8_ia0;
    for (c8_i279 = 0; c8_i279 < 16; c8_i279 = c8_i279 + 1) {
      c8_b_A[c8_i279] = c8_e_A[c8_i279];
    }

    c8_c_m = c8_b_m;
    c8_c_n = c8_b_n;
    c8_e_ix0 = c8_d_ix0;
    c8_e_iy0 = c8_d_iy0;
    for (c8_i280 = 0; c8_i280 < 16; c8_i280 = c8_i280 + 1) {
      c8_f_A[c8_i280] = c8_b_A[c8_i280];
    }

    c8_c_ia0 = c8_b_ia0;
    for (c8_i281 = 0; c8_i281 < 16; c8_i281 = c8_i281 + 1) {
      c8_b_A[c8_i281] = c8_f_A[c8_i281];
    }

    if ((real_T)c8_c_m < 1.0) {
    } else if ((real_T)c8_c_n < 1.0) {
    } else {
      for (c8_i282 = 0; c8_i282 < 16; c8_i282 = c8_i282 + 1) {
        c8_g_A[c8_i282] = c8_b_A[c8_i282];
      }

      c8_ceval_xger(chartInstance, c8_c_m, c8_c_n, -1.0, c8_e_ix0, 1, c8_e_iy0,
                    4, c8_g_A, c8_c_ia0, 4, c8_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c8_info == 0.0) {
    if (!(c8_b_A[15] != 0.0)) {
      *c8_info = 4;
      return;
    }
  }
}

static int32_T c8_eml_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[16], int32_T c8_ix0)
{
  int32_T c8_b_n;
  int32_T c8_i283;
  real_T c8_b_x[16];
  int32_T c8_b_ix0;
  int32_T c8_i284;
  real_T c8_c_x[16];
  c8_b_n = c8_n;
  for (c8_i283 = 0; c8_i283 < 16; c8_i283 = c8_i283 + 1) {
    c8_b_x[c8_i283] = c8_x[c8_i283];
  }

  c8_b_ix0 = c8_ix0;
  for (c8_i284 = 0; c8_i284 < 16; c8_i284 = c8_i284 + 1) {
    c8_c_x[c8_i284] = c8_b_x[c8_i284];
  }

  return c8_ceval_ixamax(chartInstance, c8_b_n, c8_c_x, c8_b_ix0, 1);
}

static int32_T c8_ceval_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[16], int32_T c8_ix0, int32_T
  c8_incx)
{
  return idamax32(&c8_n, &c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 16, 1, 0) - 1], &
                  c8_incx);
}

static void c8_ceval_xswap(SFc8_DynTaskConInstanceStruct *chartInstance, int32_T
  c8_n, real_T c8_x[16], int32_T c8_ix0, int32_T
  c8_incx, int32_T c8_iy0, int32_T c8_incy, real_T c8_b_x[16])
{
  int32_T c8_i285;

  /* Empty Loop. */
  for (c8_i285 = 0; c8_i285 < 16; c8_i285 = c8_i285 + 1) {
    c8_b_x[c8_i285] = c8_x[c8_i285];
  }

  dswap32(&c8_n, &c8_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 16, 1, 0) - 1], &c8_incx
          , &c8_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c8_iy0), 1, 16, 1, 0) - 1], &c8_incy);
}

static void c8_ceval_xger(SFc8_DynTaskConInstanceStruct *chartInstance, int32_T
  c8_m, int32_T c8_n, real_T c8_alpha1, int32_T c8_ix0
  , int32_T c8_incx, int32_T c8_iy0, int32_T c8_incy, real_T c8_A[16], int32_T
  c8_ia0, int32_T c8_lda, real_T c8_b_A[16])
{
  int32_T c8_i286;
  for (c8_i286 = 0; c8_i286 < 16; c8_i286 = c8_i286 + 1) {
    c8_b_A[c8_i286] = c8_A[c8_i286];
  }

  dger32(&c8_m, &c8_n, &c8_alpha1, &c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 16, 1,
          0) - 1], &c8_incx, &c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_iy0), 1, 16, 1, 0) - 1], &
         c8_incy, &c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_ia0), 1, 16, 1, 0) - 1], &c8_lda);
}

static void c8_eml_warning(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  int32_T c8_i287;
  static char_T c8_cv2[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x'
  };

  char_T c8_u[21];
  const mxArray *c8_y = NULL;
  int32_T c8_i288;
  static char_T c8_cv3[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't', 'o'
    , ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i', 's',
    'i', 'o', 'n', '.' };

  char_T c8_b_u[40];
  const mxArray *c8_b_y = NULL;
  for (c8_i287 = 0; c8_i287 < 21; c8_i287 = c8_i287 + 1) {
    c8_u[c8_i287] = c8_cv2[c8_i287];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c8_i288 = 0; c8_i288 < 40; c8_i288 = c8_i288 + 1) {
    c8_b_u[c8_i288] = c8_cv3[c8_i288];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c8_y, 14, c8_b_y);
}

static void c8_b_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void c8_eml_xtrsm(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_A[16], real_T c8_B[16], real_T c8_b_B[16])
{
  int32_T c8_i289;
  int32_T c8_i290;
  real_T c8_b_A[16];
  int32_T c8_i291;
  real_T c8_c_B[16];
  int32_T c8_i292;
  int32_T c8_i293;
  real_T c8_c_A[16];
  int32_T c8_i294;
  real_T c8_d_B[16];
  int32_T c8_i295;
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_a;
  int32_T c8_c;
  int32_T c8_b;
  int32_T c8_b_c;
  int32_T c8_b_b;
  int32_T c8_jBcol;
  int32_T c8_k;
  int32_T c8_b_k;
  int32_T c8_b_a;
  int32_T c8_c_c;
  int32_T c8_c_b;
  int32_T c8_d_c;
  int32_T c8_d_b;
  int32_T c8_kAcol;
  int32_T c8_c_a;
  int32_T c8_e_b;
  int32_T c8_e_c;
  int32_T c8_d_a;
  int32_T c8_i296;
  int32_T c8_i;
  int32_T c8_b_i;
  int32_T c8_e_a;
  int32_T c8_f_b;
  int32_T c8_f_c;
  int32_T c8_f_a;
  int32_T c8_g_b;
  int32_T c8_g_c;
  int32_T c8_g_a;
  int32_T c8_h_b;
  int32_T c8_h_c;
  int32_T c8_h_a;
  int32_T c8_i_b;
  int32_T c8_i_c;
  for (c8_i289 = 0; c8_i289 < 16; c8_i289 = c8_i289 + 1) {
    c8_b_B[c8_i289] = c8_B[c8_i289];
  }

  for (c8_i290 = 0; c8_i290 < 16; c8_i290 = c8_i290 + 1) {
    c8_b_A[c8_i290] = c8_A[c8_i290];
  }

  for (c8_i291 = 0; c8_i291 < 16; c8_i291 = c8_i291 + 1) {
    c8_c_B[c8_i291] = c8_b_B[c8_i291];
  }

  for (c8_i292 = 0; c8_i292 < 16; c8_i292 = c8_i292 + 1) {
    c8_b_B[c8_i292] = c8_c_B[c8_i292];
  }

  for (c8_i293 = 0; c8_i293 < 16; c8_i293 = c8_i293 + 1) {
    c8_c_A[c8_i293] = c8_b_A[c8_i293];
  }

  for (c8_i294 = 0; c8_i294 < 16; c8_i294 = c8_i294 + 1) {
    c8_d_B[c8_i294] = c8_b_B[c8_i294];
  }

  for (c8_i295 = 0; c8_i295 < 16; c8_i295 = c8_i295 + 1) {
    c8_b_B[c8_i295] = c8_d_B[c8_i295];
  }

  c8_c_eml_scalar_eg(chartInstance);
  for (c8_j = 1; c8_j <= 4; c8_j = c8_j + 1) {
    c8_b_j = c8_j;
    c8_a = c8_b_j;
    c8_c = c8_a - 1;
    c8_b = c8_c;
    c8_b_c = c8_b << 2;
    c8_b_b = c8_b_c;
    c8_jBcol = c8_b_b;
    for (c8_k = 1; c8_k <= 4; c8_k = c8_k + 1) {
      c8_b_k = c8_k;
      c8_b_a = c8_b_k;
      c8_c_c = c8_b_a - 1;
      c8_c_b = c8_c_c;
      c8_d_c = c8_c_b << 2;
      c8_d_b = c8_d_c;
      c8_kAcol = c8_d_b;
      c8_c_a = c8_b_k;
      c8_e_b = c8_jBcol;
      c8_e_c = c8_c_a + c8_e_b;
      if (c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_e_c), 1, 16, 1, 0) - 1] != 0.0) {
        c8_d_a = c8_b_k;
        c8_i296 = c8_d_a + 1;
        for (c8_i = c8_i296; c8_i <= 4; c8_i = c8_i + 1) {
          c8_b_i = c8_i;
          c8_e_a = c8_b_i;
          c8_f_b = c8_jBcol;
          c8_f_c = c8_e_a + c8_f_b;
          c8_f_a = c8_b_i;
          c8_g_b = c8_jBcol;
          c8_g_c = c8_f_a + c8_g_b;
          c8_g_a = c8_b_k;
          c8_h_b = c8_jBcol;
          c8_h_c = c8_g_a + c8_h_b;
          c8_h_a = c8_b_i;
          c8_i_b = c8_kAcol;
          c8_i_c = c8_h_a + c8_i_b;
          c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_f_c), 1, 16, 1, 0) - 1] = c8_b_B[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_g_c), 1, 16, 1, 0) - 1] - c8_b_B[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_h_c), 1, 16, 1, 0) - 1] * c8_c_A[
            _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_i_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void c8_c_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void c8_eml_blas_xtrsm(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, real_T
  c8_A[16], int32_T c8_ia0, int32_T c8_lda, real_T c8_B[16], int32_T c8_ib0,
  int32_T c8_ldb, real_T c8_b_B[16])
{
  int32_T c8_i297;
  int32_T c8_b_m;
  int32_T c8_b_n;
  real_T c8_b_alpha1;
  int32_T c8_i298;
  real_T c8_b_A[16];
  int32_T c8_b_ia0;
  int32_T c8_b_lda;
  int32_T c8_i299;
  real_T c8_c_B[16];
  int32_T c8_b_ib0;
  int32_T c8_b_ldb;
  int32_T c8_i300;
  boolean_T c8_NON_UNIT_ALPHA;
  int32_T c8_a;
  int32_T c8_Aoffset;
  int32_T c8_b_a;
  int32_T c8_Boffset;
  int32_T c8_loop_ub;
  int32_T c8_j;
  int32_T c8_b_j;
  int32_T c8_c_a;
  int32_T c8_c;
  int32_T c8_d_a;
  int32_T c8_b;
  int32_T c8_b_c;
  int32_T c8_e_a;
  int32_T c8_b_b;
  int32_T c8_jBcol;
  int32_T c8_b_loop_ub;
  int32_T c8_i;
  int32_T c8_b_i;
  int32_T c8_f_a;
  int32_T c8_c_b;
  int32_T c8_c_c;
  int32_T c8_c_loop_ub;
  int32_T c8_c_j;
  int32_T c8_g_a;
  int32_T c8_d_c;
  int32_T c8_h_a;
  int32_T c8_d_b;
  int32_T c8_e_c;
  int32_T c8_i_a;
  int32_T c8_e_b;
  int32_T c8_d_loop_ub;
  int32_T c8_c_i;
  int32_T c8_j_a;
  int32_T c8_f_b;
  int32_T c8_f_c;
  int32_T c8_k_a;
  int32_T c8_g_b;
  int32_T c8_g_c;
  int32_T c8_c_m;
  int32_T c8_k;
  int32_T c8_b_k;
  int32_T c8_l_a;
  int32_T c8_h_c;
  int32_T c8_m_a;
  int32_T c8_h_b;
  int32_T c8_i_c;
  int32_T c8_n_a;
  int32_T c8_i_b;
  int32_T c8_kAcol;
  int32_T c8_o_a;
  int32_T c8_j_b;
  int32_T c8_j_c;
  int32_T c8_p_a;
  int32_T c8_k_b;
  int32_T c8_k_c;
  int32_T c8_q_a;
  int32_T c8_l_b;
  int32_T c8_l_c;
  int32_T c8_r_a;
  int32_T c8_m_b;
  int32_T c8_m_c;
  real_T c8_x;
  real_T c8_y;
  real_T c8_b_x;
  real_T c8_b_y;
  real_T c8_z;
  int32_T c8_s_a;
  int32_T c8_e_loop_ub;
  int32_T c8_d_i;
  int32_T c8_t_a;
  int32_T c8_n_b;
  int32_T c8_n_c;
  int32_T c8_u_a;
  int32_T c8_o_b;
  int32_T c8_o_c;
  int32_T c8_v_a;
  int32_T c8_p_b;
  int32_T c8_p_c;
  int32_T c8_w_a;
  int32_T c8_q_b;
  int32_T c8_q_c;
  for (c8_i297 = 0; c8_i297 < 16; c8_i297 = c8_i297 + 1) {
    c8_b_B[c8_i297] = c8_B[c8_i297];
  }

  c8_b_m = c8_m;
  c8_b_n = c8_n;
  c8_b_alpha1 = c8_alpha1;
  for (c8_i298 = 0; c8_i298 < 16; c8_i298 = c8_i298 + 1) {
    c8_b_A[c8_i298] = c8_A[c8_i298];
  }

  c8_b_ia0 = c8_ia0;
  c8_b_lda = c8_lda;
  for (c8_i299 = 0; c8_i299 < 16; c8_i299 = c8_i299 + 1) {
    c8_c_B[c8_i299] = c8_b_B[c8_i299];
  }

  c8_b_ib0 = c8_ib0;
  c8_b_ldb = c8_ldb;
  for (c8_i300 = 0; c8_i300 < 16; c8_i300 = c8_i300 + 1) {
    c8_b_B[c8_i300] = c8_c_B[c8_i300];
  }

  c8_NON_UNIT_ALPHA = (c8_b_alpha1 != 1.0);
  if ((real_T)c8_b_n == 0.0) {
  } else {
    c8_c_eml_scalar_eg(chartInstance);
    c8_a = c8_b_ia0;
    c8_Aoffset = c8_a - 1;
    c8_b_a = c8_b_ib0;
    c8_Boffset = c8_b_a - 1;
    if (c8_b_alpha1 == 0.0) {
      c8_loop_ub = c8_b_n;
      for (c8_j = 1; c8_j <= c8_loop_ub; c8_j = c8_j + 1) {
        c8_b_j = c8_j;
        c8_c_a = c8_b_j;
        c8_c = c8_c_a - 1;
        c8_d_a = c8_b_ldb;
        c8_b = c8_c;
        c8_b_c = c8_d_a * c8_b;
        c8_e_a = c8_Boffset;
        c8_b_b = c8_b_c;
        c8_jBcol = c8_e_a + c8_b_b;
        c8_b_loop_ub = c8_b_m;
        for (c8_i = 1; c8_i <= c8_b_loop_ub; c8_i = c8_i + 1) {
          c8_b_i = c8_i;
          c8_f_a = c8_b_i;
          c8_c_b = c8_jBcol;
          c8_c_c = c8_f_a + c8_c_b;
          c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_c_c), 1, 16, 1, 0) - 1] = 0.0;
        }
      }
    } else {
      c8_c_loop_ub = c8_b_n;
      for (c8_c_j = 1; c8_c_j <= c8_c_loop_ub; c8_c_j = c8_c_j + 1) {
        c8_b_j = c8_c_j;
        c8_g_a = c8_b_j;
        c8_d_c = c8_g_a - 1;
        c8_h_a = c8_b_ldb;
        c8_d_b = c8_d_c;
        c8_e_c = c8_h_a * c8_d_b;
        c8_i_a = c8_Boffset;
        c8_e_b = c8_e_c;
        c8_jBcol = c8_i_a + c8_e_b;
        if (c8_NON_UNIT_ALPHA) {
          c8_d_loop_ub = c8_b_m;
          for (c8_c_i = 1; c8_c_i <= c8_d_loop_ub; c8_c_i = c8_c_i + 1) {
            c8_b_i = c8_c_i;
            c8_j_a = c8_b_i;
            c8_f_b = c8_jBcol;
            c8_f_c = c8_j_a + c8_f_b;
            c8_k_a = c8_b_i;
            c8_g_b = c8_jBcol;
            c8_g_c = c8_k_a + c8_g_b;
            c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c8_f_c), 1, 16, 1, 0) - 1] = c8_b_alpha1 * c8_b_B[
              _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c8_g_c), 1, 16, 1, 0) - 1];
          }
        }

        c8_c_m = c8_b_m;
        for (c8_k = c8_c_m; c8_k > 0; c8_k = c8_k + -1) {
          c8_b_k = c8_k;
          c8_l_a = c8_b_k;
          c8_h_c = c8_l_a - 1;
          c8_m_a = c8_b_lda;
          c8_h_b = c8_h_c;
          c8_i_c = c8_m_a * c8_h_b;
          c8_n_a = c8_Aoffset;
          c8_i_b = c8_i_c;
          c8_kAcol = c8_n_a + c8_i_b;
          c8_o_a = c8_b_k;
          c8_j_b = c8_jBcol;
          c8_j_c = c8_o_a + c8_j_b;
          if (c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
               ("", (real_T)c8_j_c), 1, 16, 1, 0) - 1] != 0.0) {
            c8_p_a = c8_b_k;
            c8_k_b = c8_jBcol;
            c8_k_c = c8_p_a + c8_k_b;
            c8_q_a = c8_b_k;
            c8_l_b = c8_jBcol;
            c8_l_c = c8_q_a + c8_l_b;
            c8_r_a = c8_b_k;
            c8_m_b = c8_kAcol;
            c8_m_c = c8_r_a + c8_m_b;
            c8_x = c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_l_c), 1, 16, 1, 0) - 1];
            c8_y = c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c8_m_c), 1, 16, 1, 0) - 1];
            c8_b_x = c8_x;
            c8_b_y = c8_y;
            c8_z = c8_b_x / c8_b_y;
            c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
              "", (real_T)c8_k_c), 1, 16, 1, 0) - 1] = c8_z;
            c8_s_a = c8_b_k;
            c8_e_loop_ub = c8_s_a - 1;
            for (c8_d_i = 1; c8_d_i <= c8_e_loop_ub; c8_d_i = c8_d_i + 1) {
              c8_b_i = c8_d_i;
              c8_t_a = c8_b_i;
              c8_n_b = c8_jBcol;
              c8_n_c = c8_t_a + c8_n_b;
              c8_u_a = c8_b_i;
              c8_o_b = c8_jBcol;
              c8_o_c = c8_u_a + c8_o_b;
              c8_v_a = c8_b_k;
              c8_p_b = c8_jBcol;
              c8_p_c = c8_v_a + c8_p_b;
              c8_w_a = c8_b_i;
              c8_q_b = c8_kAcol;
              c8_q_c = c8_w_a + c8_q_b;
              c8_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                ("", (real_T)c8_n_c), 1, 16, 1, 0) - 1] = c8_b_B[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_o_c), 1, 16, 1, 0) - 1] - c8_b_B[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_p_c), 1, 16, 1, 0) - 1] * c8_b_A[
                _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c8_q_c), 1, 16, 1, 0) - 1];
            }
          }
        }
      }
    }
  }
}

static void c8_d_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static real_T c8_atan2(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_y,
  real_T c8_x)
{
  real_T c8_b_y;
  real_T c8_b_x;
  c8_eml_scalar_eg(chartInstance);
  c8_b_y = c8_y;
  c8_b_x = c8_x;
  return muDoubleScalarAtan2(c8_b_y, c8_b_x);
}

static boolean_T c8_isInRange(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_x, real_T c8_xmin, real_T c8_xmax)
{
  boolean_T c8_isIn;
  uint32_T c8_debug_family_var_map[6];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  real_T c8_A;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_d_x;
  real_T c8_y;
  real_T c8_a;
  boolean_T c8_b0;
  boolean_T c8_b1;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c8_b_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c8_x, c8_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c8_xmin, c8_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_xmax, c8_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c8_isIn, c8_h_sf_marshall, 5U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0, 141);
  c8_A = c8_x;
  c8_b_x = c8_A;
  c8_c_x = c8_b_x;
  c8_d_x = c8_c_x;
  c8_y = c8_d_x / 3.1415926535897931;
  c8_a = c8_y;
  c8_x = c8_a * 180.0;
  _SFD_SCRIPT_CALL(0, 142);
  c8_b0 = (c8_x >= c8_xmin);
  c8_b1 = (c8_x <= c8_xmax);
  c8_isIn = (c8_b0 && c8_b1);
  _SFD_SCRIPT_CALL(0, -142);
  sf_debug_symbol_scope_pop();
  return c8_isIn;
}

static void c8_expWre(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
                      c8_kx[6], real_T c8_theta, real_T c8_g[16])
{
  uint32_T c8_debug_family_var_map[9];
  static const char *c8_sv2[9] = { "v", "w", "R", "p", "nargin", "nargout", "kx",
    "theta", "g" };

  real_T c8_v[3];
  real_T c8_w[3];
  real_T c8_R[9];
  real_T c8_p[3];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i301;
  int32_T c8_i302;
  real_T c8_dv23[9];
  int32_T c8_i303;
  int32_T c8_i304;
  real_T c8_a[3];
  real_T c8_b;
  int32_T c8_i305;
  int32_T c8_i306;
  real_T c8_b_w[3];
  real_T c8_dv24[9];
  int32_T c8_i307;
  real_T c8_dv25[9];
  int32_T c8_i308;
  real_T c8_b_a[9];
  int32_T c8_i309;
  real_T c8_c_w[3];
  int32_T c8_i310;
  real_T c8_b_v[3];
  real_T c8_b_b[3];
  int32_T c8_i311;
  real_T c8_A[9];
  int32_T c8_i312;
  real_T c8_B[3];
  int32_T c8_i313;
  real_T c8_b_A[9];
  int32_T c8_i314;
  real_T c8_b_B[3];
  int32_T c8_i315;
  real_T c8_c_A[9];
  int32_T c8_i316;
  real_T c8_c_B[3];
  int32_T c8_i317;
  real_T c8_y[3];
  int32_T c8_i318;
  int32_T c8_i319;
  int32_T c8_i320;
  real_T c8_c_a[3];
  int32_T c8_i321;
  real_T c8_c_b[3];
  int32_T c8_i322;
  int32_T c8_i323;
  int32_T c8_i324;
  real_T c8_b_y[9];
  int32_T c8_i325;
  real_T c8_d_a[9];
  int32_T c8_i326;
  real_T c8_d_b[3];
  int32_T c8_i327;
  real_T c8_d_A[9];
  int32_T c8_i328;
  real_T c8_d_B[3];
  int32_T c8_i329;
  real_T c8_e_A[9];
  int32_T c8_i330;
  real_T c8_e_B[3];
  int32_T c8_i331;
  real_T c8_f_A[9];
  int32_T c8_i332;
  real_T c8_f_B[3];
  int32_T c8_i333;
  real_T c8_c_y[3];
  int32_T c8_i334;
  int32_T c8_i335;
  int32_T c8_i336;
  real_T c8_e_a[3];
  real_T c8_e_b;
  int32_T c8_i337;
  real_T c8_d_y[3];
  int32_T c8_i338;
  int32_T c8_i339;
  int32_T c8_i340;
  int32_T c8_i341;
  int32_T c8_i342;
  int32_T c8_i343;
  int32_T c8_i344;
  int32_T c8_i345;
  static real_T c8_dv26[4] = { 0.0, 0.0, 0.0, 1.0 };

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c8_sv2, c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_v, c8_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_w, c8_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_R, c8_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_p, c8_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_kx, c8_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c8_theta, c8_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c8_g, c8_g_sf_marshall, 8U);
  CV_SCRIPT_FCN(1, 0);

  /*  exponential of the wrench  */
  _SFD_SCRIPT_CALL(1, 5);
  CV_SCRIPT_IF(1, 0, c8_length(chartInstance) != 6.0);
  _SFD_SCRIPT_CALL(1, 9);
  for (c8_i301 = 0; c8_i301 < 3; c8_i301 = c8_i301 + 1) {
    c8_v[c8_i301] = c8_kx[c8_i301];
  }

  _SFD_SCRIPT_CALL(1, 10);
  for (c8_i302 = 0; c8_i302 < 3; c8_i302 = c8_i302 + 1) {
    c8_w[c8_i302] = c8_kx[c8_i302 + 3];
  }

  _SFD_SCRIPT_CALL(1, 12);
  if (CV_SCRIPT_COND(1, 0, c8_w[0] == 0.0)) {
    if (CV_SCRIPT_COND(1, 1, c8_w[1] == 0.0)) {
      if (CV_SCRIPT_COND(1, 2, c8_w[2] == 0.0)) {
        CV_SCRIPT_MCDC(1, 0, TRUE);
        CV_SCRIPT_IF(1, 1, TRUE);
        _SFD_SCRIPT_CALL(1, 13);
        c8_eye(chartInstance, c8_dv23);
        for (c8_i303 = 0; c8_i303 < 9; c8_i303 = c8_i303 + 1) {
          c8_R[c8_i303] = c8_dv23[c8_i303];
        }

        _SFD_SCRIPT_CALL(1, 14);
        for (c8_i304 = 0; c8_i304 < 3; c8_i304 = c8_i304 + 1) {
          c8_a[c8_i304] = c8_v[c8_i304];
        }

        c8_b = c8_theta;
        for (c8_i305 = 0; c8_i305 < 3; c8_i305 = c8_i305 + 1) {
          c8_p[c8_i305] = c8_a[c8_i305] * c8_b;
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
  for (c8_i306 = 0; c8_i306 < 3; c8_i306 = c8_i306 + 1) {
    c8_b_w[c8_i306] = c8_w[c8_i306];
  }

  c8_expRot(chartInstance, c8_b_w, c8_theta, c8_dv24);
  for (c8_i307 = 0; c8_i307 < 9; c8_i307 = c8_i307 + 1) {
    c8_R[c8_i307] = c8_dv24[c8_i307];
  }

  _SFD_SCRIPT_CALL(1, 17);
  c8_eye(chartInstance, c8_dv25);
  for (c8_i308 = 0; c8_i308 < 9; c8_i308 = c8_i308 + 1) {
    c8_b_a[c8_i308] = c8_dv25[c8_i308] - c8_R[c8_i308];
  }

  for (c8_i309 = 0; c8_i309 < 3; c8_i309 = c8_i309 + 1) {
    c8_c_w[c8_i309] = c8_w[c8_i309];
  }

  for (c8_i310 = 0; c8_i310 < 3; c8_i310 = c8_i310 + 1) {
    c8_b_v[c8_i310] = c8_v[c8_i310];
  }

  c8_cross(chartInstance, c8_c_w, c8_b_v, c8_b_b);
  c8_f_eml_scalar_eg(chartInstance);
  c8_f_eml_scalar_eg(chartInstance);
  for (c8_i311 = 0; c8_i311 < 9; c8_i311 = c8_i311 + 1) {
    c8_A[c8_i311] = c8_b_a[c8_i311];
  }

  for (c8_i312 = 0; c8_i312 < 3; c8_i312 = c8_i312 + 1) {
    c8_B[c8_i312] = c8_b_b[c8_i312];
  }

  for (c8_i313 = 0; c8_i313 < 9; c8_i313 = c8_i313 + 1) {
    c8_b_A[c8_i313] = c8_A[c8_i313];
  }

  for (c8_i314 = 0; c8_i314 < 3; c8_i314 = c8_i314 + 1) {
    c8_b_B[c8_i314] = c8_B[c8_i314];
  }

  for (c8_i315 = 0; c8_i315 < 9; c8_i315 = c8_i315 + 1) {
    c8_c_A[c8_i315] = c8_b_A[c8_i315];
  }

  for (c8_i316 = 0; c8_i316 < 3; c8_i316 = c8_i316 + 1) {
    c8_c_B[c8_i316] = c8_b_B[c8_i316];
  }

  for (c8_i317 = 0; c8_i317 < 3; c8_i317 = c8_i317 + 1) {
    c8_y[c8_i317] = 0.0;
    c8_i318 = 0;
    for (c8_i319 = 0; c8_i319 < 3; c8_i319 = c8_i319 + 1) {
      c8_y[c8_i317] = c8_y[c8_i317] + c8_c_A[c8_i318 + c8_i317] * c8_c_B[c8_i319];
      c8_i318 = c8_i318 + 3;
    }
  }

  for (c8_i320 = 0; c8_i320 < 3; c8_i320 = c8_i320 + 1) {
    c8_c_a[c8_i320] = c8_w[c8_i320];
  }

  for (c8_i321 = 0; c8_i321 < 3; c8_i321 = c8_i321 + 1) {
    c8_c_b[c8_i321] = c8_w[c8_i321];
  }

  c8_i322 = 0;
  for (c8_i323 = 0; c8_i323 < 3; c8_i323 = c8_i323 + 1) {
    for (c8_i324 = 0; c8_i324 < 3; c8_i324 = c8_i324 + 1) {
      c8_b_y[c8_i324 + c8_i322] = c8_c_a[c8_i324] * c8_c_b[c8_i323];
    }

    c8_i322 = c8_i322 + 3;
  }

  for (c8_i325 = 0; c8_i325 < 9; c8_i325 = c8_i325 + 1) {
    c8_d_a[c8_i325] = c8_b_y[c8_i325];
  }

  for (c8_i326 = 0; c8_i326 < 3; c8_i326 = c8_i326 + 1) {
    c8_d_b[c8_i326] = c8_v[c8_i326];
  }

  c8_f_eml_scalar_eg(chartInstance);
  c8_f_eml_scalar_eg(chartInstance);
  for (c8_i327 = 0; c8_i327 < 9; c8_i327 = c8_i327 + 1) {
    c8_d_A[c8_i327] = c8_d_a[c8_i327];
  }

  for (c8_i328 = 0; c8_i328 < 3; c8_i328 = c8_i328 + 1) {
    c8_d_B[c8_i328] = c8_d_b[c8_i328];
  }

  for (c8_i329 = 0; c8_i329 < 9; c8_i329 = c8_i329 + 1) {
    c8_e_A[c8_i329] = c8_d_A[c8_i329];
  }

  for (c8_i330 = 0; c8_i330 < 3; c8_i330 = c8_i330 + 1) {
    c8_e_B[c8_i330] = c8_d_B[c8_i330];
  }

  for (c8_i331 = 0; c8_i331 < 9; c8_i331 = c8_i331 + 1) {
    c8_f_A[c8_i331] = c8_e_A[c8_i331];
  }

  for (c8_i332 = 0; c8_i332 < 3; c8_i332 = c8_i332 + 1) {
    c8_f_B[c8_i332] = c8_e_B[c8_i332];
  }

  for (c8_i333 = 0; c8_i333 < 3; c8_i333 = c8_i333 + 1) {
    c8_c_y[c8_i333] = 0.0;
    c8_i334 = 0;
    for (c8_i335 = 0; c8_i335 < 3; c8_i335 = c8_i335 + 1) {
      c8_c_y[c8_i333] = c8_c_y[c8_i333] + c8_f_A[c8_i334 + c8_i333] *
        c8_f_B[c8_i335];
      c8_i334 = c8_i334 + 3;
    }
  }

  for (c8_i336 = 0; c8_i336 < 3; c8_i336 = c8_i336 + 1) {
    c8_e_a[c8_i336] = c8_c_y[c8_i336];
  }

  c8_e_b = c8_theta;
  for (c8_i337 = 0; c8_i337 < 3; c8_i337 = c8_i337 + 1) {
    c8_d_y[c8_i337] = c8_e_a[c8_i337] * c8_e_b;
  }

  for (c8_i338 = 0; c8_i338 < 3; c8_i338 = c8_i338 + 1) {
    c8_p[c8_i338] = c8_y[c8_i338] + c8_d_y[c8_i338];
  }

 label_1:
  ;
  _SFD_SCRIPT_CALL(1, 19);
  c8_i339 = 0;
  c8_i340 = 0;
  for (c8_i341 = 0; c8_i341 < 3; c8_i341 = c8_i341 + 1) {
    for (c8_i342 = 0; c8_i342 < 3; c8_i342 = c8_i342 + 1) {
      c8_g[c8_i342 + c8_i339] = c8_R[c8_i342 + c8_i340];
    }

    c8_i339 = c8_i339 + 4;
    c8_i340 = c8_i340 + 3;
  }

  for (c8_i343 = 0; c8_i343 < 3; c8_i343 = c8_i343 + 1) {
    c8_g[c8_i343 + 12] = c8_p[c8_i343];
  }

  c8_i344 = 0;
  for (c8_i345 = 0; c8_i345 < 4; c8_i345 = c8_i345 + 1) {
    c8_g[c8_i344 + 3] = c8_dv26[c8_i345];
    c8_i344 = c8_i344 + 4;
  }

  _SFD_SCRIPT_CALL(1, -19);
  sf_debug_symbol_scope_pop();
}

static real_T c8_length(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  real_T c8_n;
  real_T c8_k;
  real_T c8_b_k;
  c8_n = 0.0;
  c8_k = 1.0;
 label_1:
  ;
  if (c8_k <= 2.0) {
    c8_b_k = c8_k;
    if (6.0 + -5.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1) == 0.0) {
      return 0.0;
    } else {
      if (6.0 + -5.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1) > c8_n) {
        c8_n = 6.0 + -5.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1);
      }

      c8_k = c8_k + 1.0;
      goto label_1;
    }
  }

  return c8_n;
}

static void c8_eye(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_I[9])
{
  int32_T c8_i346;
  int32_T c8_i;
  int32_T c8_b_i;
  for (c8_i346 = 0; c8_i346 < 9; c8_i346 = c8_i346 + 1) {
    c8_I[c8_i346] = 0.0;
  }

  for (c8_i = 1; c8_i < 4; c8_i = c8_i + 1) {
    c8_b_i = c8_i;
    c8_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_b_i), 1, 3, 1, 0) - 1) + 3 * (
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c8_b_i), 1, 3, 2, 0) - 1)] = 1.0;
  }
}

static void c8_expRot(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_w
                      [3], real_T c8_theta, real_T c8_R[9])
{
  uint32_T c8_debug_family_var_map[6];
  static const char *c8_sv3[6] = { "wh", "nargin", "nargout", "w", "theta", "R"
  };

  real_T c8_wh[9];
  real_T c8_nargin = 2.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i347;
  real_T c8_b_w[3];
  uint32_T c8_b_debug_family_var_map[4];
  static const char *c8_sv4[4] = { "nargin", "nargout", "w", "wh" };

  real_T c8_b_nargin = 1.0;
  real_T c8_b_nargout = 1.0;
  real_T c8_n;
  real_T c8_k;
  real_T c8_b_k;
  int32_T c8_i348;
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  int32_T c8_i349;
  real_T c8_a[9];
  real_T c8_b;
  int32_T c8_i350;
  real_T c8_y[9];
  int32_T c8_i351;
  real_T c8_b_a[9];
  int32_T c8_i352;
  real_T c8_b_b[9];
  int32_T c8_i353;
  real_T c8_A[9];
  int32_T c8_i354;
  real_T c8_B[9];
  int32_T c8_i355;
  real_T c8_b_A[9];
  int32_T c8_i356;
  real_T c8_b_B[9];
  int32_T c8_i357;
  real_T c8_c_A[9];
  int32_T c8_i358;
  real_T c8_c_B[9];
  int32_T c8_i359;
  int32_T c8_i360;
  int32_T c8_i361;
  real_T c8_b_y[9];
  int32_T c8_i362;
  int32_T c8_i363;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_f_x;
  int32_T c8_i364;
  real_T c8_c_a[9];
  real_T c8_c_b;
  int32_T c8_i365;
  real_T c8_c_y[9];
  real_T c8_dv27[9];
  int32_T c8_i366;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c8_sv3, c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_wh, c8_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_w, c8_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_theta, c8_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_R, c8_c_sf_marshall, 5U);
  CV_SCRIPT_FCN(2, 0);

  /*  exponential of the skew matrix */
  /*      if(norm(w)~=1) */
  /*          error('Norm of w must be 1'); */
  /*      end */
  _SFD_SCRIPT_CALL(2, 9);
  for (c8_i347 = 0; c8_i347 < 3; c8_i347 = c8_i347 + 1) {
    c8_b_w[c8_i347] = c8_w[c8_i347];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c8_sv4, c8_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c8_b_nargin, c8_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c8_b_nargout, c8_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_b_w, c8_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_wh, c8_c_sf_marshall, 3U);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3, 3);
  c8_n = 0.0;
  c8_k = 1.0;
 label_1:
  ;
  if (c8_k <= 2.0) {
    c8_b_k = c8_k;
    if (3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1) == 0.0) {
      c8_n = 0.0;
    } else {
      if (3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1) > c8_n) {
        c8_n = 3.0 + -2.0 * (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1);
      }

      c8_k = c8_k + 1.0;
      goto label_1;
    }
  }

  CV_SCRIPT_IF(3, 0, c8_n != 3.0);

  /* wh = diag(sym('wh',[1,3])); */
  _SFD_SCRIPT_CALL(3, 8);
  for (c8_i348 = 0; c8_i348 < 9; c8_i348 = c8_i348 + 1) {
    c8_wh[c8_i348] = 0.0;
  }

  _SFD_SCRIPT_CALL(3, 9);
  c8_wh[0] = 0.0;
  _SFD_SCRIPT_CALL(3, 10);
  c8_wh[4] = 0.0;
  _SFD_SCRIPT_CALL(3, 11);
  c8_wh[8] = 0.0;
  _SFD_SCRIPT_CALL(3, 14);
  c8_wh[3] = -c8_b_w[2];
  _SFD_SCRIPT_CALL(3, 15);
  c8_wh[6] = c8_b_w[1];
  _SFD_SCRIPT_CALL(3, 16);
  c8_wh[1] = c8_b_w[2];
  _SFD_SCRIPT_CALL(3, 17);
  c8_wh[7] = -c8_b_w[0];
  _SFD_SCRIPT_CALL(3, 18);
  c8_wh[2] = -c8_b_w[1];
  _SFD_SCRIPT_CALL(3, 19);
  c8_wh[5] = c8_b_w[0];
  _SFD_SCRIPT_CALL(3, -19);
  sf_debug_symbol_scope_pop();
  _SFD_SCRIPT_CALL(2, 10);
  c8_x = c8_theta;
  c8_b_x = c8_x;
  c8_c_x = c8_b_x;
  c8_b_x = c8_c_x;
  c8_b_x = muDoubleScalarSin(c8_b_x);
  for (c8_i349 = 0; c8_i349 < 9; c8_i349 = c8_i349 + 1) {
    c8_a[c8_i349] = c8_wh[c8_i349];
  }

  c8_b = c8_b_x;
  for (c8_i350 = 0; c8_i350 < 9; c8_i350 = c8_i350 + 1) {
    c8_y[c8_i350] = c8_a[c8_i350] * c8_b;
  }

  for (c8_i351 = 0; c8_i351 < 9; c8_i351 = c8_i351 + 1) {
    c8_b_a[c8_i351] = c8_wh[c8_i351];
  }

  for (c8_i352 = 0; c8_i352 < 9; c8_i352 = c8_i352 + 1) {
    c8_b_b[c8_i352] = c8_wh[c8_i352];
  }

  c8_e_eml_scalar_eg(chartInstance);
  c8_e_eml_scalar_eg(chartInstance);
  for (c8_i353 = 0; c8_i353 < 9; c8_i353 = c8_i353 + 1) {
    c8_A[c8_i353] = c8_b_a[c8_i353];
  }

  for (c8_i354 = 0; c8_i354 < 9; c8_i354 = c8_i354 + 1) {
    c8_B[c8_i354] = c8_b_b[c8_i354];
  }

  for (c8_i355 = 0; c8_i355 < 9; c8_i355 = c8_i355 + 1) {
    c8_b_A[c8_i355] = c8_A[c8_i355];
  }

  for (c8_i356 = 0; c8_i356 < 9; c8_i356 = c8_i356 + 1) {
    c8_b_B[c8_i356] = c8_B[c8_i356];
  }

  for (c8_i357 = 0; c8_i357 < 9; c8_i357 = c8_i357 + 1) {
    c8_c_A[c8_i357] = c8_b_A[c8_i357];
  }

  for (c8_i358 = 0; c8_i358 < 9; c8_i358 = c8_i358 + 1) {
    c8_c_B[c8_i358] = c8_b_B[c8_i358];
  }

  for (c8_i359 = 0; c8_i359 < 3; c8_i359 = c8_i359 + 1) {
    c8_i360 = 0;
    for (c8_i361 = 0; c8_i361 < 3; c8_i361 = c8_i361 + 1) {
      c8_b_y[c8_i360 + c8_i359] = 0.0;
      c8_i362 = 0;
      for (c8_i363 = 0; c8_i363 < 3; c8_i363 = c8_i363 + 1) {
        c8_b_y[c8_i360 + c8_i359] = c8_b_y[c8_i360 + c8_i359] + c8_c_A[c8_i362 +
          c8_i359] * c8_c_B[c8_i363 + c8_i360];
        c8_i362 = c8_i362 + 3;
      }

      c8_i360 = c8_i360 + 3;
    }
  }

  c8_d_x = c8_theta;
  c8_e_x = c8_d_x;
  c8_f_x = c8_e_x;
  c8_e_x = c8_f_x;
  c8_e_x = muDoubleScalarCos(c8_e_x);
  for (c8_i364 = 0; c8_i364 < 9; c8_i364 = c8_i364 + 1) {
    c8_c_a[c8_i364] = c8_b_y[c8_i364];
  }

  c8_c_b = 1.0 - c8_e_x;
  for (c8_i365 = 0; c8_i365 < 9; c8_i365 = c8_i365 + 1) {
    c8_c_y[c8_i365] = c8_c_a[c8_i365] * c8_c_b;
  }

  c8_eye(chartInstance, c8_dv27);
  for (c8_i366 = 0; c8_i366 < 9; c8_i366 = c8_i366 + 1) {
    c8_R[c8_i366] = (c8_dv27[c8_i366] + c8_y[c8_i366]) + c8_c_y[c8_i366];
  }

  _SFD_SCRIPT_CALL(2, -10);
  sf_debug_symbol_scope_pop();
}

static void c8_e_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void c8_f_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static void c8_subPro3(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[4], real_T c8_q[4], real_T c8_d[4]
  , real_T c8_theta[2], real_T *c8_Nsol)
{
  uint32_T c8_debug_family_var_map[18];
  static const char *c8_sv5[18] = { "velociy", "w", "r", "u", "v", "up", "vp",
    "dp2", "theta0", "phi", "p", "q", "d", "nargin",
    "nargout", "kx", "theta", "Nsol" };

  real_T c8_velociy[3];
  real_T c8_w[3];
  real_T c8_r[3];
  real_T c8_u[3];
  real_T c8_v[3];
  real_T c8_up[3];
  real_T c8_vp[3];
  real_T c8_dp2;
  real_T c8_theta0;
  real_T c8_phi;
  real_T c8_b_p[3];
  real_T c8_b_q[3];
  real_T c8_b_d[3];
  real_T c8_nargin = 4.0;
  real_T c8_nargout = 2.0;
  int32_T c8_i367;
  int32_T c8_i368;
  int32_T c8_i369;
  int32_T c8_i370;
  int32_T c8_i371;
  int32_T c8_i372;
  int32_T c8_i373;
  real_T c8_b_velociy[3];
  int32_T c8_i374;
  real_T c8_b_w[3];
  real_T c8_dv28[3];
  int32_T c8_i375;
  int32_T c8_i376;
  int32_T c8_i377;
  int32_T c8_i378;
  real_T c8_a[3];
  int32_T c8_i379;
  real_T c8_b[3];
  int32_T c8_i380;
  real_T c8_x[3];
  int32_T c8_i381;
  real_T c8_y[3];
  int32_T c8_i382;
  real_T c8_b_x[3];
  int32_T c8_i383;
  real_T c8_b_y[3];
  int32_T c8_i384;
  real_T c8_c_x[3];
  int32_T c8_i385;
  real_T c8_c_y[3];
  int32_T c8_i386;
  real_T c8_d_x[3];
  int32_T c8_i387;
  real_T c8_d_y[3];
  real_T c8_e_y;
  int32_T c8_i388;
  real_T c8_b_a[3];
  real_T c8_b_b;
  int32_T c8_i389;
  real_T c8_f_y[3];
  int32_T c8_i390;
  int32_T c8_i391;
  real_T c8_c_a[3];
  int32_T c8_i392;
  real_T c8_c_b[3];
  int32_T c8_i393;
  real_T c8_e_x[3];
  int32_T c8_i394;
  real_T c8_g_y[3];
  int32_T c8_i395;
  real_T c8_f_x[3];
  int32_T c8_i396;
  real_T c8_h_y[3];
  int32_T c8_i397;
  real_T c8_g_x[3];
  int32_T c8_i398;
  real_T c8_i_y[3];
  int32_T c8_i399;
  real_T c8_h_x[3];
  int32_T c8_i400;
  real_T c8_j_y[3];
  real_T c8_k_y;
  int32_T c8_i401;
  real_T c8_d_a[3];
  real_T c8_d_b;
  int32_T c8_i402;
  real_T c8_l_y[3];
  int32_T c8_i403;
  int32_T c8_i404;
  real_T c8_e_a[3];
  int32_T c8_i405;
  real_T c8_e_b[3];
  int32_T c8_i406;
  real_T c8_i_x[3];
  int32_T c8_i407;
  real_T c8_m_y[3];
  int32_T c8_i408;
  real_T c8_j_x[3];
  int32_T c8_i409;
  real_T c8_n_y[3];
  int32_T c8_i410;
  real_T c8_k_x[3];
  int32_T c8_i411;
  real_T c8_o_y[3];
  int32_T c8_i412;
  real_T c8_l_x[3];
  int32_T c8_i413;
  real_T c8_p_y[3];
  real_T c8_q_y;
  int32_T c8_i414;
  real_T c8_f_a[3];
  int32_T c8_i415;
  real_T c8_f_b[3];
  int32_T c8_i416;
  real_T c8_m_x[3];
  int32_T c8_i417;
  real_T c8_r_y[3];
  int32_T c8_i418;
  real_T c8_n_x[3];
  int32_T c8_i419;
  real_T c8_s_y[3];
  int32_T c8_i420;
  real_T c8_o_x[3];
  int32_T c8_i421;
  real_T c8_t_y[3];
  int32_T c8_i422;
  real_T c8_p_x[3];
  int32_T c8_i423;
  real_T c8_u_y[3];
  real_T c8_v_y;
  int32_T c8_i424;
  real_T c8_g_a[3];
  int32_T c8_i425;
  real_T c8_b_up[3];
  int32_T c8_i426;
  real_T c8_b_vp[3];
  real_T c8_g_b[3];
  int32_T c8_i427;
  real_T c8_q_x[3];
  int32_T c8_i428;
  real_T c8_w_y[3];
  int32_T c8_i429;
  real_T c8_r_x[3];
  int32_T c8_i430;
  real_T c8_x_y[3];
  int32_T c8_i431;
  real_T c8_s_x[3];
  int32_T c8_i432;
  real_T c8_y_y[3];
  int32_T c8_i433;
  real_T c8_t_x[3];
  int32_T c8_i434;
  real_T c8_ab_y[3];
  real_T c8_bb_y;
  int32_T c8_i435;
  real_T c8_h_a[3];
  int32_T c8_i436;
  real_T c8_h_b[3];
  int32_T c8_i437;
  real_T c8_u_x[3];
  int32_T c8_i438;
  real_T c8_cb_y[3];
  int32_T c8_i439;
  real_T c8_v_x[3];
  int32_T c8_i440;
  real_T c8_db_y[3];
  int32_T c8_i441;
  real_T c8_w_x[3];
  int32_T c8_i442;
  real_T c8_eb_y[3];
  int32_T c8_i443;
  real_T c8_x_x[3];
  int32_T c8_i444;
  real_T c8_fb_y[3];
  real_T c8_gb_y;
  int32_T c8_i445;
  real_T c8_i_a[3];
  int32_T c8_i446;
  real_T c8_i_b[3];
  int32_T c8_i447;
  real_T c8_y_x[3];
  int32_T c8_i448;
  real_T c8_hb_y[3];
  int32_T c8_i449;
  real_T c8_ab_x[3];
  int32_T c8_i450;
  real_T c8_ib_y[3];
  int32_T c8_i451;
  real_T c8_bb_x[3];
  int32_T c8_i452;
  real_T c8_jb_y[3];
  int32_T c8_i453;
  real_T c8_cb_x[3];
  int32_T c8_i454;
  real_T c8_kb_y[3];
  real_T c8_lb_y;
  int32_T c8_i455;
  real_T c8_j_a[3];
  int32_T c8_i456;
  real_T c8_j_b[3];
  int32_T c8_i457;
  real_T c8_db_x[3];
  int32_T c8_i458;
  real_T c8_mb_y[3];
  int32_T c8_i459;
  real_T c8_eb_x[3];
  int32_T c8_i460;
  real_T c8_nb_y[3];
  int32_T c8_i461;
  real_T c8_fb_x[3];
  int32_T c8_i462;
  real_T c8_ob_y[3];
  int32_T c8_i463;
  real_T c8_gb_x[3];
  int32_T c8_i464;
  real_T c8_pb_y[3];
  real_T c8_qb_y;
  int32_T c8_i465;
  real_T c8_c_up[3];
  real_T c8_k_b;
  real_T c8_rb_y;
  real_T c8_k_a;
  int32_T c8_i466;
  real_T c8_c_vp[3];
  real_T c8_l_b;
  real_T c8_sb_y;
  real_T c8_A;
  real_T c8_B;
  real_T c8_hb_x;
  real_T c8_tb_y;
  real_T c8_ib_x;
  real_T c8_ub_y;
  real_T c8_jb_x;
  real_T c8_vb_y;
  real_T c8_wb_y;
  real_T c8_kb_x;
  real_T c8_lb_x;
  sf_debug_symbol_scope_push_eml(0U, 18U, 21U, c8_sv5, c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_velociy, c8_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_w, c8_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_r, c8_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_u, c8_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c8_v, c8_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_up, c8_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_vp, c8_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c8_dp2, c8_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c8_theta0, c8_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c8_phi, c8_e_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c8_b_p, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_q, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c8_b_d, c8_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(c8_kx, c8_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(c8_p, c8_j_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c8_q, c8_j_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(c8_d, c8_j_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(c8_theta, c8_i_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(c8_Nsol, c8_e_sf_marshall, 17U);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4, 2);
  for (c8_i367 = 0; c8_i367 < 2; c8_i367 = c8_i367 + 1) {
    c8_theta[c8_i367] = 0.0;
  }

  _SFD_SCRIPT_CALL(4, 3);
  for (c8_i368 = 0; c8_i368 < 3; c8_i368 = c8_i368 + 1) {
    c8_b_p[c8_i368] = c8_p[c8_i368];
  }

  sf_debug_symbol_switch(10U, 10U);

  /*  col vector */
  _SFD_SCRIPT_CALL(4, 4);
  for (c8_i369 = 0; c8_i369 < 3; c8_i369 = c8_i369 + 1) {
    c8_b_q[c8_i369] = c8_q[c8_i369];
  }

  sf_debug_symbol_switch(11U, 11U);

  /*  col vector */
  _SFD_SCRIPT_CALL(4, 5);
  for (c8_i370 = 0; c8_i370 < 3; c8_i370 = c8_i370 + 1) {
    c8_b_d[c8_i370] = c8_d[c8_i370];
  }

  sf_debug_symbol_switch(12U, 12U);

  /*  col vector. */
  _SFD_SCRIPT_CALL(4, 7);
  for (c8_i371 = 0; c8_i371 < 3; c8_i371 = c8_i371 + 1) {
    c8_velociy[c8_i371] = c8_kx[c8_i371];
  }

  _SFD_SCRIPT_CALL(4, 8);
  for (c8_i372 = 0; c8_i372 < 3; c8_i372 = c8_i372 + 1) {
    c8_w[c8_i372] = c8_kx[c8_i372 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(4, 9);
  for (c8_i373 = 0; c8_i373 < 3; c8_i373 = c8_i373 + 1) {
    c8_b_velociy[c8_i373] = c8_velociy[c8_i373];
  }

  for (c8_i374 = 0; c8_i374 < 3; c8_i374 = c8_i374 + 1) {
    c8_b_w[c8_i374] = c8_w[c8_i374];
  }

  c8_cross(chartInstance, c8_b_velociy, c8_b_w, c8_dv28);
  for (c8_i375 = 0; c8_i375 < 3; c8_i375 = c8_i375 + 1) {
    c8_r[c8_i375] = -c8_dv28[c8_i375];
  }

  _SFD_SCRIPT_CALL(4, 11);
  for (c8_i376 = 0; c8_i376 < 3; c8_i376 = c8_i376 + 1) {
    c8_u[c8_i376] = c8_b_p[c8_i376] - c8_r[c8_i376];
  }

  _SFD_SCRIPT_CALL(4, 12);
  for (c8_i377 = 0; c8_i377 < 3; c8_i377 = c8_i377 + 1) {
    c8_v[c8_i377] = c8_b_q[c8_i377] - c8_r[c8_i377];
  }

  _SFD_SCRIPT_CALL(4, 14);
  for (c8_i378 = 0; c8_i378 < 3; c8_i378 = c8_i378 + 1) {
    c8_a[c8_i378] = c8_w[c8_i378];
  }

  for (c8_i379 = 0; c8_i379 < 3; c8_i379 = c8_i379 + 1) {
    c8_b[c8_i379] = c8_u[c8_i379];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i380 = 0; c8_i380 < 3; c8_i380 = c8_i380 + 1) {
    c8_x[c8_i380] = c8_a[c8_i380];
  }

  for (c8_i381 = 0; c8_i381 < 3; c8_i381 = c8_i381 + 1) {
    c8_y[c8_i381] = c8_b[c8_i381];
  }

  for (c8_i382 = 0; c8_i382 < 3; c8_i382 = c8_i382 + 1) {
    c8_b_x[c8_i382] = c8_x[c8_i382];
  }

  for (c8_i383 = 0; c8_i383 < 3; c8_i383 = c8_i383 + 1) {
    c8_b_y[c8_i383] = c8_y[c8_i383];
  }

  for (c8_i384 = 0; c8_i384 < 3; c8_i384 = c8_i384 + 1) {
    c8_c_x[c8_i384] = c8_b_x[c8_i384];
  }

  for (c8_i385 = 0; c8_i385 < 3; c8_i385 = c8_i385 + 1) {
    c8_c_y[c8_i385] = c8_b_y[c8_i385];
  }

  for (c8_i386 = 0; c8_i386 < 3; c8_i386 = c8_i386 + 1) {
    c8_d_x[c8_i386] = c8_c_x[c8_i386];
  }

  for (c8_i387 = 0; c8_i387 < 3; c8_i387 = c8_i387 + 1) {
    c8_d_y[c8_i387] = c8_c_y[c8_i387];
  }

  c8_e_y = c8_ceval_xdot(chartInstance, 3, c8_d_x, 1, 1, c8_d_y, 1, 1);
  for (c8_i388 = 0; c8_i388 < 3; c8_i388 = c8_i388 + 1) {
    c8_b_a[c8_i388] = c8_w[c8_i388];
  }

  c8_b_b = c8_e_y;
  for (c8_i389 = 0; c8_i389 < 3; c8_i389 = c8_i389 + 1) {
    c8_f_y[c8_i389] = c8_b_a[c8_i389] * c8_b_b;
  }

  for (c8_i390 = 0; c8_i390 < 3; c8_i390 = c8_i390 + 1) {
    c8_up[c8_i390] = c8_u[c8_i390] - c8_f_y[c8_i390];
  }

  _SFD_SCRIPT_CALL(4, 15);
  for (c8_i391 = 0; c8_i391 < 3; c8_i391 = c8_i391 + 1) {
    c8_c_a[c8_i391] = c8_w[c8_i391];
  }

  for (c8_i392 = 0; c8_i392 < 3; c8_i392 = c8_i392 + 1) {
    c8_c_b[c8_i392] = c8_v[c8_i392];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i393 = 0; c8_i393 < 3; c8_i393 = c8_i393 + 1) {
    c8_e_x[c8_i393] = c8_c_a[c8_i393];
  }

  for (c8_i394 = 0; c8_i394 < 3; c8_i394 = c8_i394 + 1) {
    c8_g_y[c8_i394] = c8_c_b[c8_i394];
  }

  for (c8_i395 = 0; c8_i395 < 3; c8_i395 = c8_i395 + 1) {
    c8_f_x[c8_i395] = c8_e_x[c8_i395];
  }

  for (c8_i396 = 0; c8_i396 < 3; c8_i396 = c8_i396 + 1) {
    c8_h_y[c8_i396] = c8_g_y[c8_i396];
  }

  for (c8_i397 = 0; c8_i397 < 3; c8_i397 = c8_i397 + 1) {
    c8_g_x[c8_i397] = c8_f_x[c8_i397];
  }

  for (c8_i398 = 0; c8_i398 < 3; c8_i398 = c8_i398 + 1) {
    c8_i_y[c8_i398] = c8_h_y[c8_i398];
  }

  for (c8_i399 = 0; c8_i399 < 3; c8_i399 = c8_i399 + 1) {
    c8_h_x[c8_i399] = c8_g_x[c8_i399];
  }

  for (c8_i400 = 0; c8_i400 < 3; c8_i400 = c8_i400 + 1) {
    c8_j_y[c8_i400] = c8_i_y[c8_i400];
  }

  c8_k_y = c8_ceval_xdot(chartInstance, 3, c8_h_x, 1, 1, c8_j_y, 1, 1);
  for (c8_i401 = 0; c8_i401 < 3; c8_i401 = c8_i401 + 1) {
    c8_d_a[c8_i401] = c8_w[c8_i401];
  }

  c8_d_b = c8_k_y;
  for (c8_i402 = 0; c8_i402 < 3; c8_i402 = c8_i402 + 1) {
    c8_l_y[c8_i402] = c8_d_a[c8_i402] * c8_d_b;
  }

  for (c8_i403 = 0; c8_i403 < 3; c8_i403 = c8_i403 + 1) {
    c8_vp[c8_i403] = c8_v[c8_i403] - c8_l_y[c8_i403];
  }

  _SFD_SCRIPT_CALL(4, 17);
  for (c8_i404 = 0; c8_i404 < 3; c8_i404 = c8_i404 + 1) {
    c8_e_a[c8_i404] = c8_b_d[c8_i404];
  }

  for (c8_i405 = 0; c8_i405 < 3; c8_i405 = c8_i405 + 1) {
    c8_e_b[c8_i405] = c8_b_d[c8_i405];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i406 = 0; c8_i406 < 3; c8_i406 = c8_i406 + 1) {
    c8_i_x[c8_i406] = c8_e_a[c8_i406];
  }

  for (c8_i407 = 0; c8_i407 < 3; c8_i407 = c8_i407 + 1) {
    c8_m_y[c8_i407] = c8_e_b[c8_i407];
  }

  for (c8_i408 = 0; c8_i408 < 3; c8_i408 = c8_i408 + 1) {
    c8_j_x[c8_i408] = c8_i_x[c8_i408];
  }

  for (c8_i409 = 0; c8_i409 < 3; c8_i409 = c8_i409 + 1) {
    c8_n_y[c8_i409] = c8_m_y[c8_i409];
  }

  for (c8_i410 = 0; c8_i410 < 3; c8_i410 = c8_i410 + 1) {
    c8_k_x[c8_i410] = c8_j_x[c8_i410];
  }

  for (c8_i411 = 0; c8_i411 < 3; c8_i411 = c8_i411 + 1) {
    c8_o_y[c8_i411] = c8_n_y[c8_i411];
  }

  for (c8_i412 = 0; c8_i412 < 3; c8_i412 = c8_i412 + 1) {
    c8_l_x[c8_i412] = c8_k_x[c8_i412];
  }

  for (c8_i413 = 0; c8_i413 < 3; c8_i413 = c8_i413 + 1) {
    c8_p_y[c8_i413] = c8_o_y[c8_i413];
  }

  c8_q_y = c8_ceval_xdot(chartInstance, 3, c8_l_x, 1, 1, c8_p_y, 1, 1);
  for (c8_i414 = 0; c8_i414 < 3; c8_i414 = c8_i414 + 1) {
    c8_f_a[c8_i414] = c8_w[c8_i414];
  }

  for (c8_i415 = 0; c8_i415 < 3; c8_i415 = c8_i415 + 1) {
    c8_f_b[c8_i415] = c8_b_p[c8_i415] - c8_b_q[c8_i415];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i416 = 0; c8_i416 < 3; c8_i416 = c8_i416 + 1) {
    c8_m_x[c8_i416] = c8_f_a[c8_i416];
  }

  for (c8_i417 = 0; c8_i417 < 3; c8_i417 = c8_i417 + 1) {
    c8_r_y[c8_i417] = c8_f_b[c8_i417];
  }

  for (c8_i418 = 0; c8_i418 < 3; c8_i418 = c8_i418 + 1) {
    c8_n_x[c8_i418] = c8_m_x[c8_i418];
  }

  for (c8_i419 = 0; c8_i419 < 3; c8_i419 = c8_i419 + 1) {
    c8_s_y[c8_i419] = c8_r_y[c8_i419];
  }

  for (c8_i420 = 0; c8_i420 < 3; c8_i420 = c8_i420 + 1) {
    c8_o_x[c8_i420] = c8_n_x[c8_i420];
  }

  for (c8_i421 = 0; c8_i421 < 3; c8_i421 = c8_i421 + 1) {
    c8_t_y[c8_i421] = c8_s_y[c8_i421];
  }

  for (c8_i422 = 0; c8_i422 < 3; c8_i422 = c8_i422 + 1) {
    c8_p_x[c8_i422] = c8_o_x[c8_i422];
  }

  for (c8_i423 = 0; c8_i423 < 3; c8_i423 = c8_i423 + 1) {
    c8_u_y[c8_i423] = c8_t_y[c8_i423];
  }

  c8_v_y = c8_ceval_xdot(chartInstance, 3, c8_p_x, 1, 1, c8_u_y, 1, 1);
  c8_dp2 = c8_q_y - c8_mpower(chartInstance, c8_v_y);
  _SFD_SCRIPT_CALL(4, 19);
  for (c8_i424 = 0; c8_i424 < 3; c8_i424 = c8_i424 + 1) {
    c8_g_a[c8_i424] = c8_w[c8_i424];
  }

  for (c8_i425 = 0; c8_i425 < 3; c8_i425 = c8_i425 + 1) {
    c8_b_up[c8_i425] = c8_up[c8_i425];
  }

  for (c8_i426 = 0; c8_i426 < 3; c8_i426 = c8_i426 + 1) {
    c8_b_vp[c8_i426] = c8_vp[c8_i426];
  }

  c8_cross(chartInstance, c8_b_up, c8_b_vp, c8_g_b);
  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i427 = 0; c8_i427 < 3; c8_i427 = c8_i427 + 1) {
    c8_q_x[c8_i427] = c8_g_a[c8_i427];
  }

  for (c8_i428 = 0; c8_i428 < 3; c8_i428 = c8_i428 + 1) {
    c8_w_y[c8_i428] = c8_g_b[c8_i428];
  }

  for (c8_i429 = 0; c8_i429 < 3; c8_i429 = c8_i429 + 1) {
    c8_r_x[c8_i429] = c8_q_x[c8_i429];
  }

  for (c8_i430 = 0; c8_i430 < 3; c8_i430 = c8_i430 + 1) {
    c8_x_y[c8_i430] = c8_w_y[c8_i430];
  }

  for (c8_i431 = 0; c8_i431 < 3; c8_i431 = c8_i431 + 1) {
    c8_s_x[c8_i431] = c8_r_x[c8_i431];
  }

  for (c8_i432 = 0; c8_i432 < 3; c8_i432 = c8_i432 + 1) {
    c8_y_y[c8_i432] = c8_x_y[c8_i432];
  }

  for (c8_i433 = 0; c8_i433 < 3; c8_i433 = c8_i433 + 1) {
    c8_t_x[c8_i433] = c8_s_x[c8_i433];
  }

  for (c8_i434 = 0; c8_i434 < 3; c8_i434 = c8_i434 + 1) {
    c8_ab_y[c8_i434] = c8_y_y[c8_i434];
  }

  c8_bb_y = c8_ceval_xdot(chartInstance, 3, c8_t_x, 1, 1, c8_ab_y, 1, 1);
  for (c8_i435 = 0; c8_i435 < 3; c8_i435 = c8_i435 + 1) {
    c8_h_a[c8_i435] = c8_up[c8_i435];
  }

  for (c8_i436 = 0; c8_i436 < 3; c8_i436 = c8_i436 + 1) {
    c8_h_b[c8_i436] = c8_vp[c8_i436];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i437 = 0; c8_i437 < 3; c8_i437 = c8_i437 + 1) {
    c8_u_x[c8_i437] = c8_h_a[c8_i437];
  }

  for (c8_i438 = 0; c8_i438 < 3; c8_i438 = c8_i438 + 1) {
    c8_cb_y[c8_i438] = c8_h_b[c8_i438];
  }

  for (c8_i439 = 0; c8_i439 < 3; c8_i439 = c8_i439 + 1) {
    c8_v_x[c8_i439] = c8_u_x[c8_i439];
  }

  for (c8_i440 = 0; c8_i440 < 3; c8_i440 = c8_i440 + 1) {
    c8_db_y[c8_i440] = c8_cb_y[c8_i440];
  }

  for (c8_i441 = 0; c8_i441 < 3; c8_i441 = c8_i441 + 1) {
    c8_w_x[c8_i441] = c8_v_x[c8_i441];
  }

  for (c8_i442 = 0; c8_i442 < 3; c8_i442 = c8_i442 + 1) {
    c8_eb_y[c8_i442] = c8_db_y[c8_i442];
  }

  for (c8_i443 = 0; c8_i443 < 3; c8_i443 = c8_i443 + 1) {
    c8_x_x[c8_i443] = c8_w_x[c8_i443];
  }

  for (c8_i444 = 0; c8_i444 < 3; c8_i444 = c8_i444 + 1) {
    c8_fb_y[c8_i444] = c8_eb_y[c8_i444];
  }

  c8_gb_y = c8_ceval_xdot(chartInstance, 3, c8_x_x, 1, 1, c8_fb_y, 1, 1);
  c8_theta0 = c8_atan2(chartInstance, c8_bb_y, c8_gb_y);
  _SFD_SCRIPT_CALL(4, 21);
  for (c8_i445 = 0; c8_i445 < 3; c8_i445 = c8_i445 + 1) {
    c8_i_a[c8_i445] = c8_up[c8_i445];
  }

  for (c8_i446 = 0; c8_i446 < 3; c8_i446 = c8_i446 + 1) {
    c8_i_b[c8_i446] = c8_up[c8_i446];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i447 = 0; c8_i447 < 3; c8_i447 = c8_i447 + 1) {
    c8_y_x[c8_i447] = c8_i_a[c8_i447];
  }

  for (c8_i448 = 0; c8_i448 < 3; c8_i448 = c8_i448 + 1) {
    c8_hb_y[c8_i448] = c8_i_b[c8_i448];
  }

  for (c8_i449 = 0; c8_i449 < 3; c8_i449 = c8_i449 + 1) {
    c8_ab_x[c8_i449] = c8_y_x[c8_i449];
  }

  for (c8_i450 = 0; c8_i450 < 3; c8_i450 = c8_i450 + 1) {
    c8_ib_y[c8_i450] = c8_hb_y[c8_i450];
  }

  for (c8_i451 = 0; c8_i451 < 3; c8_i451 = c8_i451 + 1) {
    c8_bb_x[c8_i451] = c8_ab_x[c8_i451];
  }

  for (c8_i452 = 0; c8_i452 < 3; c8_i452 = c8_i452 + 1) {
    c8_jb_y[c8_i452] = c8_ib_y[c8_i452];
  }

  for (c8_i453 = 0; c8_i453 < 3; c8_i453 = c8_i453 + 1) {
    c8_cb_x[c8_i453] = c8_bb_x[c8_i453];
  }

  for (c8_i454 = 0; c8_i454 < 3; c8_i454 = c8_i454 + 1) {
    c8_kb_y[c8_i454] = c8_jb_y[c8_i454];
  }

  c8_lb_y = c8_ceval_xdot(chartInstance, 3, c8_cb_x, 1, 1, c8_kb_y, 1, 1);
  for (c8_i455 = 0; c8_i455 < 3; c8_i455 = c8_i455 + 1) {
    c8_j_a[c8_i455] = c8_vp[c8_i455];
  }

  for (c8_i456 = 0; c8_i456 < 3; c8_i456 = c8_i456 + 1) {
    c8_j_b[c8_i456] = c8_vp[c8_i456];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i457 = 0; c8_i457 < 3; c8_i457 = c8_i457 + 1) {
    c8_db_x[c8_i457] = c8_j_a[c8_i457];
  }

  for (c8_i458 = 0; c8_i458 < 3; c8_i458 = c8_i458 + 1) {
    c8_mb_y[c8_i458] = c8_j_b[c8_i458];
  }

  for (c8_i459 = 0; c8_i459 < 3; c8_i459 = c8_i459 + 1) {
    c8_eb_x[c8_i459] = c8_db_x[c8_i459];
  }

  for (c8_i460 = 0; c8_i460 < 3; c8_i460 = c8_i460 + 1) {
    c8_nb_y[c8_i460] = c8_mb_y[c8_i460];
  }

  for (c8_i461 = 0; c8_i461 < 3; c8_i461 = c8_i461 + 1) {
    c8_fb_x[c8_i461] = c8_eb_x[c8_i461];
  }

  for (c8_i462 = 0; c8_i462 < 3; c8_i462 = c8_i462 + 1) {
    c8_ob_y[c8_i462] = c8_nb_y[c8_i462];
  }

  for (c8_i463 = 0; c8_i463 < 3; c8_i463 = c8_i463 + 1) {
    c8_gb_x[c8_i463] = c8_fb_x[c8_i463];
  }

  for (c8_i464 = 0; c8_i464 < 3; c8_i464 = c8_i464 + 1) {
    c8_pb_y[c8_i464] = c8_ob_y[c8_i464];
  }

  c8_qb_y = c8_ceval_xdot(chartInstance, 3, c8_gb_x, 1, 1, c8_pb_y, 1, 1);
  for (c8_i465 = 0; c8_i465 < 3; c8_i465 = c8_i465 + 1) {
    c8_c_up[c8_i465] = c8_up[c8_i465];
  }

  c8_k_b = c8_norm(chartInstance, c8_c_up);
  c8_rb_y = 2.0 * c8_k_b;
  c8_k_a = c8_rb_y;
  for (c8_i466 = 0; c8_i466 < 3; c8_i466 = c8_i466 + 1) {
    c8_c_vp[c8_i466] = c8_vp[c8_i466];
  }

  c8_l_b = c8_norm(chartInstance, c8_c_vp);
  c8_sb_y = c8_k_a * c8_l_b;
  c8_A = (c8_lb_y + c8_qb_y) - c8_dp2;
  c8_B = c8_sb_y;
  c8_hb_x = c8_A;
  c8_tb_y = c8_B;
  c8_ib_x = c8_hb_x;
  c8_ub_y = c8_tb_y;
  c8_jb_x = c8_ib_x;
  c8_vb_y = c8_ub_y;
  c8_wb_y = c8_jb_x / c8_vb_y;
  c8_kb_x = c8_wb_y;
  c8_phi = c8_kb_x;
  if (c8_phi < -1.0) {
  } else if (1.0 < c8_phi) {
  } else {
    goto label_1;
  }

  c8_b_eml_error(chartInstance);
 label_1:
  ;
  c8_lb_x = c8_phi;
  c8_phi = c8_lb_x;
  c8_phi = muDoubleScalarAcos(c8_phi);
  _SFD_SCRIPT_CALL(4, 23);
  c8_theta[0] = c8_theta0 - c8_phi;
  _SFD_SCRIPT_CALL(4, 24);
  c8_theta[1] = c8_theta0 + c8_phi;

  /*      check1 = (sol1 >= -45/180*pi) && (sol1 <= 115/180*pi); */
  /*      check2 = (sol2 >= -45/180*pi) && (sol2 <= 115/180*pi); */
  /*       */
  /*      if check1 && check2 */
  /*           */
  /*          if abs(sol1) > abs(sol2) */
  /*              theta = sol2; */
  /*          else */
  /*              theta = sol1; */
  /*          end */
  /*           */
  /*      elseif check1 */
  /*          theta = sol1; */
  /*      elseif check2 */
  /*          theta = sol2; */
  /*      end  */
  /*      Nsol = check1+check2; */
  _SFD_SCRIPT_CALL(4, 44);
  if (CV_SCRIPT_IF(4, 0, c8_phi != 0.0)) {
    _SFD_SCRIPT_CALL(4, 45);
    *c8_Nsol = 2.0;
  } else {
    /*          theta = theta0; */
    _SFD_SCRIPT_CALL(4, 48);
    *c8_Nsol = 1.0;
  }

  _SFD_SCRIPT_CALL(4, -48);
  sf_debug_symbol_scope_pop();
}

static void c8_g_eml_scalar_eg(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

static real_T c8_ceval_xdot(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[3], int32_T c8_ix0, int32_T
  c8_incx, real_T c8_y[3], int32_T c8_iy0, int32_T c8_incy)
{
  real_T c8_d;
  c8_d = 0.0;
  if ((real_T)c8_n > 0.0) {
    return ddot32(&c8_n, &c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 3, 1, 0) - 1], &
                  c8_incx, &c8_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c8_iy0), 1, 3, 1, 0) - 1], &c8_incy);
  }

  return c8_d;
}

static real_T c8_mpower(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_a)
{
  return c8_power(chartInstance, c8_a, 2.0);
}

static real_T c8_norm(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_x
                      [3])
{
  int32_T c8_i467;
  real_T c8_b_x[3];
  int32_T c8_i468;
  real_T c8_c_x[3];
  int32_T c8_i469;
  real_T c8_d_x[3];
  int32_T c8_i470;
  real_T c8_e_x[3];
  for (c8_i467 = 0; c8_i467 < 3; c8_i467 = c8_i467 + 1) {
    c8_b_x[c8_i467] = c8_x[c8_i467];
  }

  for (c8_i468 = 0; c8_i468 < 3; c8_i468 = c8_i468 + 1) {
    c8_c_x[c8_i468] = c8_b_x[c8_i468];
  }

  for (c8_i469 = 0; c8_i469 < 3; c8_i469 = c8_i469 + 1) {
    c8_d_x[c8_i469] = c8_c_x[c8_i469];
  }

  for (c8_i470 = 0; c8_i470 < 3; c8_i470 = c8_i470 + 1) {
    c8_e_x[c8_i470] = c8_d_x[c8_i470];
  }

  return c8_ceval_xnrm2(chartInstance, 3, c8_e_x, 1, 1);
}

static real_T c8_ceval_xnrm2(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[3], int32_T c8_ix0, int32_T
  c8_incx)
{
  return dnrm232(&c8_n, &c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 3, 1, 0) - 1], &
                 c8_incx);
}

static void c8_b_eml_error(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  int32_T c8_i471;
  static char_T c8_cv4[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 'c', 'o', 's', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c8_u[31];
  const mxArray *c8_y = NULL;
  int32_T c8_i472;
  static char_T c8_cv5[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 'a', 'c',
    'o', 's', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c8_b_u[77];
  const mxArray *c8_b_y = NULL;
  for (c8_i471 = 0; c8_i471 < 31; c8_i471 = c8_i471 + 1) {
    c8_u[c8_i471] = c8_cv4[c8_i471];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c8_i472 = 0; c8_i472 < 77; c8_i472 = c8_i472 + 1) {
    c8_b_u[c8_i472] = c8_cv5[c8_i472];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c8_y, 14, c8_b_y);
}

static void c8_b_isInRange(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_x[2], real_T c8_xmin, real_T c8_xmax, boolean_T
  c8_isIn[2])
{
  uint32_T c8_debug_family_var_map[6];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i473;
  real_T c8_A[2];
  int32_T c8_i474;
  real_T c8_b_x[2];
  int32_T c8_i475;
  real_T c8_c_x[2];
  int32_T c8_i476;
  real_T c8_d_x[2];
  int32_T c8_i477;
  real_T c8_y[2];
  int32_T c8_i478;
  real_T c8_a[2];
  int32_T c8_i479;
  int32_T c8_i480;
  boolean_T c8_bv5[2];
  int32_T c8_i481;
  boolean_T c8_bv6[2];
  int32_T c8_i482;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c8_g_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_x, c8_i_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c8_xmin, c8_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_xmax, c8_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_isIn, c8_k_sf_marshall, 5U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0, 141);
  for (c8_i473 = 0; c8_i473 < 2; c8_i473 = c8_i473 + 1) {
    c8_A[c8_i473] = c8_x[c8_i473];
  }

  for (c8_i474 = 0; c8_i474 < 2; c8_i474 = c8_i474 + 1) {
    c8_b_x[c8_i474] = c8_A[c8_i474];
  }

  for (c8_i475 = 0; c8_i475 < 2; c8_i475 = c8_i475 + 1) {
    c8_c_x[c8_i475] = c8_b_x[c8_i475];
  }

  for (c8_i476 = 0; c8_i476 < 2; c8_i476 = c8_i476 + 1) {
    c8_d_x[c8_i476] = c8_c_x[c8_i476];
  }

  for (c8_i477 = 0; c8_i477 < 2; c8_i477 = c8_i477 + 1) {
    c8_y[c8_i477] = c8_d_x[c8_i477] / 3.1415926535897931;
  }

  for (c8_i478 = 0; c8_i478 < 2; c8_i478 = c8_i478 + 1) {
    c8_a[c8_i478] = c8_y[c8_i478];
  }

  for (c8_i479 = 0; c8_i479 < 2; c8_i479 = c8_i479 + 1) {
    c8_x[c8_i479] = c8_a[c8_i479] * 180.0;
  }

  _SFD_SCRIPT_CALL(0, 142);
  for (c8_i480 = 0; c8_i480 < 2; c8_i480 = c8_i480 + 1) {
    c8_bv5[c8_i480] = (c8_x[c8_i480] >= c8_xmin);
  }

  for (c8_i481 = 0; c8_i481 < 2; c8_i481 = c8_i481 + 1) {
    c8_bv6[c8_i481] = (c8_x[c8_i481] <= c8_xmax);
  }

  for (c8_i482 = 0; c8_i482 < 2; c8_i482 = c8_i482 + 1) {
    c8_isIn[c8_i482] = (c8_bv5[c8_i482] && c8_bv6[c8_i482]);
  }

  _SFD_SCRIPT_CALL(0, -142);
  sf_debug_symbol_scope_pop();
}

static boolean_T c8_any(SFc8_DynTaskConInstanceStruct *chartInstance, boolean_T
  c8_x[2])
{
  boolean_T c8_y;
  int32_T c8_i483;
  boolean_T c8_b_x[2];
  real_T c8_k;
  real_T c8_b_k;
  boolean_T c8_b2;
  for (c8_i483 = 0; c8_i483 < 2; c8_i483 = c8_i483 + 1) {
    c8_b_x[c8_i483] = c8_x[c8_i483];
  }

  c8_y = FALSE;
  c8_k = 1.0;
 label_1:
  ;
  if (c8_k <= 2.0) {
    c8_b_k = c8_k;
    if ((real_T)c8_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c8_b_k), 1, 2, 1, 0) - 1] == 0.0) {
      c8_b2 = TRUE;
    } else {
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c8_b_k), 1, 2, 1, 0);
      c8_b2 = FALSE;
    }

    if (!c8_b2) {
      return TRUE;
    } else {
      c8_k = c8_k + 1.0;
      goto label_1;
    }
  }

  return c8_y;
}

static real_T c8_subPro1(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[4], real_T c8_q[4])
{
  real_T c8_theta;
  uint32_T c8_debug_family_var_map[13];
  real_T c8_velociy[3];
  real_T c8_w[3];
  real_T c8_r[3];
  real_T c8_u[3];
  real_T c8_v[3];
  real_T c8_up[3];
  real_T c8_vp[3];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i484;
  int32_T c8_i485;
  int32_T c8_i486;
  real_T c8_b_velociy[3];
  int32_T c8_i487;
  real_T c8_b_w[3];
  real_T c8_dv29[3];
  int32_T c8_i488;
  int32_T c8_i489;
  int32_T c8_i490;
  int32_T c8_i491;
  real_T c8_a[3];
  int32_T c8_i492;
  real_T c8_b[3];
  int32_T c8_i493;
  real_T c8_x[3];
  int32_T c8_i494;
  real_T c8_y[3];
  int32_T c8_i495;
  real_T c8_b_x[3];
  int32_T c8_i496;
  real_T c8_b_y[3];
  int32_T c8_i497;
  real_T c8_c_x[3];
  int32_T c8_i498;
  real_T c8_c_y[3];
  int32_T c8_i499;
  real_T c8_d_x[3];
  int32_T c8_i500;
  real_T c8_d_y[3];
  real_T c8_e_y;
  int32_T c8_i501;
  real_T c8_b_a[3];
  real_T c8_b_b;
  int32_T c8_i502;
  real_T c8_f_y[3];
  int32_T c8_i503;
  int32_T c8_i504;
  real_T c8_c_a[3];
  int32_T c8_i505;
  real_T c8_c_b[3];
  int32_T c8_i506;
  real_T c8_e_x[3];
  int32_T c8_i507;
  real_T c8_g_y[3];
  int32_T c8_i508;
  real_T c8_f_x[3];
  int32_T c8_i509;
  real_T c8_h_y[3];
  int32_T c8_i510;
  real_T c8_g_x[3];
  int32_T c8_i511;
  real_T c8_i_y[3];
  int32_T c8_i512;
  real_T c8_h_x[3];
  int32_T c8_i513;
  real_T c8_j_y[3];
  real_T c8_k_y;
  int32_T c8_i514;
  real_T c8_d_a[3];
  real_T c8_d_b;
  int32_T c8_i515;
  real_T c8_l_y[3];
  int32_T c8_i516;
  int32_T c8_i517;
  real_T c8_e_a[3];
  int32_T c8_i518;
  real_T c8_b_up[3];
  int32_T c8_i519;
  real_T c8_b_vp[3];
  real_T c8_e_b[3];
  int32_T c8_i520;
  real_T c8_i_x[3];
  int32_T c8_i521;
  real_T c8_m_y[3];
  int32_T c8_i522;
  real_T c8_j_x[3];
  int32_T c8_i523;
  real_T c8_n_y[3];
  int32_T c8_i524;
  real_T c8_k_x[3];
  int32_T c8_i525;
  real_T c8_o_y[3];
  int32_T c8_i526;
  real_T c8_l_x[3];
  int32_T c8_i527;
  real_T c8_p_y[3];
  real_T c8_q_y;
  int32_T c8_i528;
  real_T c8_f_a[3];
  int32_T c8_i529;
  real_T c8_f_b[3];
  int32_T c8_i530;
  real_T c8_m_x[3];
  int32_T c8_i531;
  real_T c8_r_y[3];
  int32_T c8_i532;
  real_T c8_n_x[3];
  int32_T c8_i533;
  real_T c8_s_y[3];
  int32_T c8_i534;
  real_T c8_o_x[3];
  int32_T c8_i535;
  real_T c8_t_y[3];
  int32_T c8_i536;
  real_T c8_p_x[3];
  int32_T c8_i537;
  real_T c8_u_y[3];
  real_T c8_v_y;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c8_h_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_velociy, c8_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_w, c8_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_r, c8_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_u, c8_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c8_v, c8_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_up, c8_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_vp, c8_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c8_kx, c8_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c8_p, c8_j_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c8_q, c8_j_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c8_theta, c8_e_sf_marshall, 12U);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5, 4);
  for (c8_i484 = 0; c8_i484 < 3; c8_i484 = c8_i484 + 1) {
    c8_velociy[c8_i484] = c8_kx[c8_i484];
  }

  _SFD_SCRIPT_CALL(5, 5);
  for (c8_i485 = 0; c8_i485 < 3; c8_i485 = c8_i485 + 1) {
    c8_w[c8_i485] = c8_kx[c8_i485 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(5, 6);
  for (c8_i486 = 0; c8_i486 < 3; c8_i486 = c8_i486 + 1) {
    c8_b_velociy[c8_i486] = c8_velociy[c8_i486];
  }

  for (c8_i487 = 0; c8_i487 < 3; c8_i487 = c8_i487 + 1) {
    c8_b_w[c8_i487] = c8_w[c8_i487];
  }

  c8_cross(chartInstance, c8_b_velociy, c8_b_w, c8_dv29);
  for (c8_i488 = 0; c8_i488 < 3; c8_i488 = c8_i488 + 1) {
    c8_r[c8_i488] = -c8_dv29[c8_i488];
  }

  _SFD_SCRIPT_CALL(5, 8);
  for (c8_i489 = 0; c8_i489 < 3; c8_i489 = c8_i489 + 1) {
    c8_u[c8_i489] = c8_p[c8_i489] - c8_r[c8_i489];
  }

  _SFD_SCRIPT_CALL(5, 9);
  for (c8_i490 = 0; c8_i490 < 3; c8_i490 = c8_i490 + 1) {
    c8_v[c8_i490] = c8_q[c8_i490] - c8_r[c8_i490];
  }

  _SFD_SCRIPT_CALL(5, 12);
  for (c8_i491 = 0; c8_i491 < 3; c8_i491 = c8_i491 + 1) {
    c8_a[c8_i491] = c8_w[c8_i491];
  }

  for (c8_i492 = 0; c8_i492 < 3; c8_i492 = c8_i492 + 1) {
    c8_b[c8_i492] = c8_u[c8_i492];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i493 = 0; c8_i493 < 3; c8_i493 = c8_i493 + 1) {
    c8_x[c8_i493] = c8_a[c8_i493];
  }

  for (c8_i494 = 0; c8_i494 < 3; c8_i494 = c8_i494 + 1) {
    c8_y[c8_i494] = c8_b[c8_i494];
  }

  for (c8_i495 = 0; c8_i495 < 3; c8_i495 = c8_i495 + 1) {
    c8_b_x[c8_i495] = c8_x[c8_i495];
  }

  for (c8_i496 = 0; c8_i496 < 3; c8_i496 = c8_i496 + 1) {
    c8_b_y[c8_i496] = c8_y[c8_i496];
  }

  for (c8_i497 = 0; c8_i497 < 3; c8_i497 = c8_i497 + 1) {
    c8_c_x[c8_i497] = c8_b_x[c8_i497];
  }

  for (c8_i498 = 0; c8_i498 < 3; c8_i498 = c8_i498 + 1) {
    c8_c_y[c8_i498] = c8_b_y[c8_i498];
  }

  for (c8_i499 = 0; c8_i499 < 3; c8_i499 = c8_i499 + 1) {
    c8_d_x[c8_i499] = c8_c_x[c8_i499];
  }

  for (c8_i500 = 0; c8_i500 < 3; c8_i500 = c8_i500 + 1) {
    c8_d_y[c8_i500] = c8_c_y[c8_i500];
  }

  c8_e_y = c8_ceval_xdot(chartInstance, 3, c8_d_x, 1, 1, c8_d_y, 1, 1);
  for (c8_i501 = 0; c8_i501 < 3; c8_i501 = c8_i501 + 1) {
    c8_b_a[c8_i501] = c8_w[c8_i501];
  }

  c8_b_b = c8_e_y;
  for (c8_i502 = 0; c8_i502 < 3; c8_i502 = c8_i502 + 1) {
    c8_f_y[c8_i502] = c8_b_a[c8_i502] * c8_b_b;
  }

  for (c8_i503 = 0; c8_i503 < 3; c8_i503 = c8_i503 + 1) {
    c8_up[c8_i503] = c8_u[c8_i503] - c8_f_y[c8_i503];
  }

  _SFD_SCRIPT_CALL(5, 13);
  for (c8_i504 = 0; c8_i504 < 3; c8_i504 = c8_i504 + 1) {
    c8_c_a[c8_i504] = c8_w[c8_i504];
  }

  for (c8_i505 = 0; c8_i505 < 3; c8_i505 = c8_i505 + 1) {
    c8_c_b[c8_i505] = c8_u[c8_i505];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i506 = 0; c8_i506 < 3; c8_i506 = c8_i506 + 1) {
    c8_e_x[c8_i506] = c8_c_a[c8_i506];
  }

  for (c8_i507 = 0; c8_i507 < 3; c8_i507 = c8_i507 + 1) {
    c8_g_y[c8_i507] = c8_c_b[c8_i507];
  }

  for (c8_i508 = 0; c8_i508 < 3; c8_i508 = c8_i508 + 1) {
    c8_f_x[c8_i508] = c8_e_x[c8_i508];
  }

  for (c8_i509 = 0; c8_i509 < 3; c8_i509 = c8_i509 + 1) {
    c8_h_y[c8_i509] = c8_g_y[c8_i509];
  }

  for (c8_i510 = 0; c8_i510 < 3; c8_i510 = c8_i510 + 1) {
    c8_g_x[c8_i510] = c8_f_x[c8_i510];
  }

  for (c8_i511 = 0; c8_i511 < 3; c8_i511 = c8_i511 + 1) {
    c8_i_y[c8_i511] = c8_h_y[c8_i511];
  }

  for (c8_i512 = 0; c8_i512 < 3; c8_i512 = c8_i512 + 1) {
    c8_h_x[c8_i512] = c8_g_x[c8_i512];
  }

  for (c8_i513 = 0; c8_i513 < 3; c8_i513 = c8_i513 + 1) {
    c8_j_y[c8_i513] = c8_i_y[c8_i513];
  }

  c8_k_y = c8_ceval_xdot(chartInstance, 3, c8_h_x, 1, 1, c8_j_y, 1, 1);
  for (c8_i514 = 0; c8_i514 < 3; c8_i514 = c8_i514 + 1) {
    c8_d_a[c8_i514] = c8_w[c8_i514];
  }

  c8_d_b = c8_k_y;
  for (c8_i515 = 0; c8_i515 < 3; c8_i515 = c8_i515 + 1) {
    c8_l_y[c8_i515] = c8_d_a[c8_i515] * c8_d_b;
  }

  for (c8_i516 = 0; c8_i516 < 3; c8_i516 = c8_i516 + 1) {
    c8_vp[c8_i516] = c8_v[c8_i516] - c8_l_y[c8_i516];
  }

  /*      if norm(up) == 0 */
  /*          error('SubPro1: up = 0, Infinite number of solutions!'); */
  /*      end */
  _SFD_SCRIPT_CALL(5, 19);
  for (c8_i517 = 0; c8_i517 < 3; c8_i517 = c8_i517 + 1) {
    c8_e_a[c8_i517] = c8_w[c8_i517];
  }

  for (c8_i518 = 0; c8_i518 < 3; c8_i518 = c8_i518 + 1) {
    c8_b_up[c8_i518] = c8_up[c8_i518];
  }

  for (c8_i519 = 0; c8_i519 < 3; c8_i519 = c8_i519 + 1) {
    c8_b_vp[c8_i519] = c8_vp[c8_i519];
  }

  c8_cross(chartInstance, c8_b_up, c8_b_vp, c8_e_b);
  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i520 = 0; c8_i520 < 3; c8_i520 = c8_i520 + 1) {
    c8_i_x[c8_i520] = c8_e_a[c8_i520];
  }

  for (c8_i521 = 0; c8_i521 < 3; c8_i521 = c8_i521 + 1) {
    c8_m_y[c8_i521] = c8_e_b[c8_i521];
  }

  for (c8_i522 = 0; c8_i522 < 3; c8_i522 = c8_i522 + 1) {
    c8_j_x[c8_i522] = c8_i_x[c8_i522];
  }

  for (c8_i523 = 0; c8_i523 < 3; c8_i523 = c8_i523 + 1) {
    c8_n_y[c8_i523] = c8_m_y[c8_i523];
  }

  for (c8_i524 = 0; c8_i524 < 3; c8_i524 = c8_i524 + 1) {
    c8_k_x[c8_i524] = c8_j_x[c8_i524];
  }

  for (c8_i525 = 0; c8_i525 < 3; c8_i525 = c8_i525 + 1) {
    c8_o_y[c8_i525] = c8_n_y[c8_i525];
  }

  for (c8_i526 = 0; c8_i526 < 3; c8_i526 = c8_i526 + 1) {
    c8_l_x[c8_i526] = c8_k_x[c8_i526];
  }

  for (c8_i527 = 0; c8_i527 < 3; c8_i527 = c8_i527 + 1) {
    c8_p_y[c8_i527] = c8_o_y[c8_i527];
  }

  c8_q_y = c8_ceval_xdot(chartInstance, 3, c8_l_x, 1, 1, c8_p_y, 1, 1);
  for (c8_i528 = 0; c8_i528 < 3; c8_i528 = c8_i528 + 1) {
    c8_f_a[c8_i528] = c8_up[c8_i528];
  }

  for (c8_i529 = 0; c8_i529 < 3; c8_i529 = c8_i529 + 1) {
    c8_f_b[c8_i529] = c8_vp[c8_i529];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i530 = 0; c8_i530 < 3; c8_i530 = c8_i530 + 1) {
    c8_m_x[c8_i530] = c8_f_a[c8_i530];
  }

  for (c8_i531 = 0; c8_i531 < 3; c8_i531 = c8_i531 + 1) {
    c8_r_y[c8_i531] = c8_f_b[c8_i531];
  }

  for (c8_i532 = 0; c8_i532 < 3; c8_i532 = c8_i532 + 1) {
    c8_n_x[c8_i532] = c8_m_x[c8_i532];
  }

  for (c8_i533 = 0; c8_i533 < 3; c8_i533 = c8_i533 + 1) {
    c8_s_y[c8_i533] = c8_r_y[c8_i533];
  }

  for (c8_i534 = 0; c8_i534 < 3; c8_i534 = c8_i534 + 1) {
    c8_o_x[c8_i534] = c8_n_x[c8_i534];
  }

  for (c8_i535 = 0; c8_i535 < 3; c8_i535 = c8_i535 + 1) {
    c8_t_y[c8_i535] = c8_s_y[c8_i535];
  }

  for (c8_i536 = 0; c8_i536 < 3; c8_i536 = c8_i536 + 1) {
    c8_p_x[c8_i536] = c8_o_x[c8_i536];
  }

  for (c8_i537 = 0; c8_i537 < 3; c8_i537 = c8_i537 + 1) {
    c8_u_y[c8_i537] = c8_t_y[c8_i537];
  }

  c8_v_y = c8_ceval_xdot(chartInstance, 3, c8_p_x, 1, 1, c8_u_y, 1, 1);
  c8_theta = c8_atan2(chartInstance, c8_q_y, c8_v_y);
  _SFD_SCRIPT_CALL(5, -19);
  sf_debug_symbol_scope_pop();
  return c8_theta;
}

static void c8_subPro2(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx1[6], real_T c8_kx2[6], real_T c8_p[4], real_T c8_q
  [4], real_T c8_theta1[2], real_T c8_theta2[2], real_T *c8_Nsol)
{
  uint32_T c8_debug_family_var_map[25];
  static const char *c8_sv6[25] = { "velociy1", "w1", "r1", "velociy2", "w2",
    "r2", "r", "u", "v", "alpha", "beta", "ySqu", "i", "y",
    "z", "c", "nargin", "nargout", "kx1", "kx2", "p", "q", "theta1", "theta2",
    "Nsol" };

  real_T c8_velociy1[3];
  real_T c8_w1[3];
  real_T c8_r1[3];
  real_T c8_velociy2[3];
  real_T c8_w2[3];
  real_T c8_r2[3];
  real_T c8_r[3];
  real_T c8_u[3];
  real_T c8_v[3];
  real_T c8_alpha;
  real_T c8_beta;
  real_T c8_ySqu;
  real_T c8_i;
  real_T c8_y;
  real_T c8_z[3];
  real_T c8_c[3];
  real_T c8_nargin = 4.0;
  real_T c8_nargout = 3.0;
  int32_T c8_i538;
  int32_T c8_i539;
  int32_T c8_i540;
  int32_T c8_i541;
  int32_T c8_i542;
  real_T c8_b_velociy1[3];
  int32_T c8_i543;
  real_T c8_b_w1[3];
  real_T c8_dv30[3];
  int32_T c8_i544;
  int32_T c8_i545;
  int32_T c8_i546;
  int32_T c8_i547;
  real_T c8_b_velociy2[3];
  int32_T c8_i548;
  real_T c8_b_w2[3];
  real_T c8_dv31[3];
  int32_T c8_i549;
  int32_T c8_i550;
  real_T c8_c_w1[3];
  int32_T c8_i551;
  real_T c8_c_w2[3];
  int32_T c8_i552;
  real_T c8_b_r1[3];
  int32_T c8_i553;
  real_T c8_b_r2[3];
  real_T c8_dv32[3];
  int32_T c8_i554;
  int32_T c8_i555;
  int32_T c8_i556;
  int32_T c8_i557;
  real_T c8_a[3];
  int32_T c8_i558;
  real_T c8_b[3];
  int32_T c8_i559;
  real_T c8_x[3];
  int32_T c8_i560;
  real_T c8_b_y[3];
  int32_T c8_i561;
  real_T c8_b_x[3];
  int32_T c8_i562;
  real_T c8_c_y[3];
  int32_T c8_i563;
  real_T c8_c_x[3];
  int32_T c8_i564;
  real_T c8_d_y[3];
  int32_T c8_i565;
  real_T c8_d_x[3];
  int32_T c8_i566;
  real_T c8_e_y[3];
  real_T c8_f_y;
  real_T c8_b_a;
  int32_T c8_i567;
  real_T c8_b_b[3];
  int32_T c8_i568;
  real_T c8_g_y[3];
  int32_T c8_i569;
  real_T c8_c_a[3];
  int32_T c8_i570;
  real_T c8_c_b[3];
  int32_T c8_i571;
  real_T c8_e_x[3];
  int32_T c8_i572;
  real_T c8_h_y[3];
  int32_T c8_i573;
  real_T c8_f_x[3];
  int32_T c8_i574;
  real_T c8_i_y[3];
  int32_T c8_i575;
  real_T c8_g_x[3];
  int32_T c8_i576;
  real_T c8_j_y[3];
  int32_T c8_i577;
  real_T c8_h_x[3];
  int32_T c8_i578;
  real_T c8_k_y[3];
  real_T c8_l_y;
  int32_T c8_i579;
  real_T c8_d_a[3];
  int32_T c8_i580;
  real_T c8_d_b[3];
  int32_T c8_i581;
  real_T c8_i_x[3];
  int32_T c8_i582;
  real_T c8_m_y[3];
  int32_T c8_i583;
  real_T c8_j_x[3];
  int32_T c8_i584;
  real_T c8_n_y[3];
  int32_T c8_i585;
  real_T c8_k_x[3];
  int32_T c8_i586;
  real_T c8_o_y[3];
  int32_T c8_i587;
  real_T c8_l_x[3];
  int32_T c8_i588;
  real_T c8_p_y[3];
  real_T c8_q_y;
  int32_T c8_i589;
  real_T c8_e_a[3];
  int32_T c8_i590;
  real_T c8_e_b[3];
  int32_T c8_i591;
  real_T c8_m_x[3];
  int32_T c8_i592;
  real_T c8_r_y[3];
  int32_T c8_i593;
  real_T c8_n_x[3];
  int32_T c8_i594;
  real_T c8_s_y[3];
  int32_T c8_i595;
  real_T c8_o_x[3];
  int32_T c8_i596;
  real_T c8_t_y[3];
  int32_T c8_i597;
  real_T c8_p_x[3];
  int32_T c8_i598;
  real_T c8_u_y[3];
  real_T c8_v_y;
  int32_T c8_i599;
  real_T c8_f_a[3];
  int32_T c8_i600;
  real_T c8_f_b[3];
  int32_T c8_i601;
  real_T c8_q_x[3];
  int32_T c8_i602;
  real_T c8_w_y[3];
  int32_T c8_i603;
  real_T c8_r_x[3];
  int32_T c8_i604;
  real_T c8_x_y[3];
  int32_T c8_i605;
  real_T c8_s_x[3];
  int32_T c8_i606;
  real_T c8_y_y[3];
  int32_T c8_i607;
  real_T c8_t_x[3];
  int32_T c8_i608;
  real_T c8_ab_y[3];
  real_T c8_bb_y;
  real_T c8_g_a;
  real_T c8_g_b;
  real_T c8_cb_y;
  real_T c8_A;
  real_T c8_B;
  real_T c8_u_x;
  real_T c8_db_y;
  real_T c8_v_x;
  real_T c8_eb_y;
  real_T c8_w_x;
  real_T c8_fb_y;
  int32_T c8_i609;
  real_T c8_h_a[3];
  int32_T c8_i610;
  real_T c8_h_b[3];
  int32_T c8_i611;
  real_T c8_x_x[3];
  int32_T c8_i612;
  real_T c8_gb_y[3];
  int32_T c8_i613;
  real_T c8_y_x[3];
  int32_T c8_i614;
  real_T c8_hb_y[3];
  int32_T c8_i615;
  real_T c8_ab_x[3];
  int32_T c8_i616;
  real_T c8_ib_y[3];
  int32_T c8_i617;
  real_T c8_bb_x[3];
  int32_T c8_i618;
  real_T c8_jb_y[3];
  real_T c8_kb_y;
  real_T c8_i_a;
  int32_T c8_i619;
  real_T c8_i_b[3];
  int32_T c8_i620;
  real_T c8_lb_y[3];
  int32_T c8_i621;
  real_T c8_j_a[3];
  int32_T c8_i622;
  real_T c8_j_b[3];
  int32_T c8_i623;
  real_T c8_cb_x[3];
  int32_T c8_i624;
  real_T c8_mb_y[3];
  int32_T c8_i625;
  real_T c8_db_x[3];
  int32_T c8_i626;
  real_T c8_nb_y[3];
  int32_T c8_i627;
  real_T c8_eb_x[3];
  int32_T c8_i628;
  real_T c8_ob_y[3];
  int32_T c8_i629;
  real_T c8_fb_x[3];
  int32_T c8_i630;
  real_T c8_pb_y[3];
  real_T c8_qb_y;
  int32_T c8_i631;
  real_T c8_k_a[3];
  int32_T c8_i632;
  real_T c8_k_b[3];
  int32_T c8_i633;
  real_T c8_gb_x[3];
  int32_T c8_i634;
  real_T c8_rb_y[3];
  int32_T c8_i635;
  real_T c8_hb_x[3];
  int32_T c8_i636;
  real_T c8_sb_y[3];
  int32_T c8_i637;
  real_T c8_ib_x[3];
  int32_T c8_i638;
  real_T c8_tb_y[3];
  int32_T c8_i639;
  real_T c8_jb_x[3];
  int32_T c8_i640;
  real_T c8_ub_y[3];
  real_T c8_vb_y;
  int32_T c8_i641;
  real_T c8_l_a[3];
  int32_T c8_i642;
  real_T c8_l_b[3];
  int32_T c8_i643;
  real_T c8_kb_x[3];
  int32_T c8_i644;
  real_T c8_wb_y[3];
  int32_T c8_i645;
  real_T c8_lb_x[3];
  int32_T c8_i646;
  real_T c8_xb_y[3];
  int32_T c8_i647;
  real_T c8_mb_x[3];
  int32_T c8_i648;
  real_T c8_yb_y[3];
  int32_T c8_i649;
  real_T c8_nb_x[3];
  int32_T c8_i650;
  real_T c8_ac_y[3];
  real_T c8_bc_y;
  int32_T c8_i651;
  real_T c8_m_a[3];
  int32_T c8_i652;
  real_T c8_m_b[3];
  int32_T c8_i653;
  real_T c8_ob_x[3];
  int32_T c8_i654;
  real_T c8_cc_y[3];
  int32_T c8_i655;
  real_T c8_pb_x[3];
  int32_T c8_i656;
  real_T c8_dc_y[3];
  int32_T c8_i657;
  real_T c8_qb_x[3];
  int32_T c8_i658;
  real_T c8_ec_y[3];
  int32_T c8_i659;
  real_T c8_rb_x[3];
  int32_T c8_i660;
  real_T c8_fc_y[3];
  real_T c8_gc_y;
  real_T c8_n_a;
  real_T c8_n_b;
  real_T c8_hc_y;
  real_T c8_b_A;
  real_T c8_b_B;
  real_T c8_sb_x;
  real_T c8_ic_y;
  real_T c8_tb_x;
  real_T c8_jc_y;
  real_T c8_ub_x;
  real_T c8_kc_y;
  int32_T c8_i661;
  real_T c8_o_a[3];
  int32_T c8_i662;
  real_T c8_o_b[3];
  int32_T c8_i663;
  real_T c8_vb_x[3];
  int32_T c8_i664;
  real_T c8_lc_y[3];
  int32_T c8_i665;
  real_T c8_wb_x[3];
  int32_T c8_i666;
  real_T c8_mc_y[3];
  int32_T c8_i667;
  real_T c8_xb_x[3];
  int32_T c8_i668;
  real_T c8_nc_y[3];
  int32_T c8_i669;
  real_T c8_yb_x[3];
  int32_T c8_i670;
  real_T c8_oc_y[3];
  real_T c8_pc_y;
  real_T c8_p_a;
  real_T c8_p_b;
  real_T c8_qc_y;
  real_T c8_q_a;
  real_T c8_q_b;
  real_T c8_rc_y;
  real_T c8_r_b;
  real_T c8_sc_y;
  real_T c8_r_a;
  real_T c8_s_b;
  real_T c8_tc_y;
  real_T c8_s_a;
  int32_T c8_i671;
  real_T c8_t_b[3];
  int32_T c8_i672;
  real_T c8_uc_y[3];
  int32_T c8_i673;
  real_T c8_t_a[3];
  int32_T c8_i674;
  real_T c8_u_b[3];
  int32_T c8_i675;
  real_T c8_ac_x[3];
  int32_T c8_i676;
  real_T c8_vc_y[3];
  int32_T c8_i677;
  real_T c8_bc_x[3];
  int32_T c8_i678;
  real_T c8_wc_y[3];
  int32_T c8_i679;
  real_T c8_cc_x[3];
  int32_T c8_i680;
  real_T c8_xc_y[3];
  int32_T c8_i681;
  real_T c8_dc_x[3];
  int32_T c8_i682;
  real_T c8_yc_y[3];
  real_T c8_ad_y;
  int32_T c8_i683;
  real_T c8_d_w1[3];
  int32_T c8_i684;
  real_T c8_d_w2[3];
  real_T c8_dv33[3];
  int32_T c8_i685;
  real_T c8_u_a[3];
  int32_T c8_i686;
  real_T c8_e_w1[3];
  int32_T c8_i687;
  real_T c8_e_w2[3];
  real_T c8_v_b[3];
  int32_T c8_i688;
  real_T c8_ec_x[3];
  int32_T c8_i689;
  real_T c8_bd_y[3];
  int32_T c8_i690;
  real_T c8_fc_x[3];
  int32_T c8_i691;
  real_T c8_cd_y[3];
  int32_T c8_i692;
  real_T c8_gc_x[3];
  int32_T c8_i693;
  real_T c8_dd_y[3];
  int32_T c8_i694;
  real_T c8_hc_x[3];
  int32_T c8_i695;
  real_T c8_ed_y[3];
  real_T c8_fd_y;
  real_T c8_c_A;
  real_T c8_c_B;
  real_T c8_ic_x;
  real_T c8_gd_y;
  real_T c8_jc_x;
  real_T c8_hd_y;
  real_T c8_kc_x;
  real_T c8_id_y;
  real_T c8_b_i;
  real_T c8_w_b;
  real_T c8_jd_y;
  real_T c8_lc_x;
  real_T c8_mc_x;
  real_T c8_nc_x;
  real_T c8_v_a;
  real_T c8_x_b;
  real_T c8_w_a;
  int32_T c8_i696;
  real_T c8_y_b[3];
  int32_T c8_i697;
  real_T c8_kd_y[3];
  real_T c8_x_a;
  int32_T c8_i698;
  real_T c8_ab_b[3];
  int32_T c8_i699;
  real_T c8_ld_y[3];
  real_T c8_y_a;
  int32_T c8_i700;
  real_T c8_f_w1[3];
  int32_T c8_i701;
  real_T c8_f_w2[3];
  real_T c8_bb_b[3];
  int32_T c8_i702;
  real_T c8_md_y[3];
  int32_T c8_i703;
  int32_T c8_i704;
  int32_T c8_i705;
  real_T c8_b_kx2[6];
  int32_T c8_i706;
  real_T c8_b_p[4];
  int32_T c8_i707;
  real_T c8_b_c[3];
  int32_T c8_i708;
  real_T c8_b_kx1[6];
  int32_T c8_i709;
  real_T c8_c_c[3];
  int32_T c8_i710;
  real_T c8_b_q[4];
  sf_debug_symbol_scope_push_eml(0U, 25U, 25U, c8_sv6, c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_velociy1, c8_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_w1, c8_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_r1, c8_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_velociy2, c8_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c8_w2, c8_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_r2, c8_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_r, c8_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c8_u, c8_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c8_v, c8_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c8_alpha, c8_e_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c8_beta, c8_e_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c8_ySqu, c8_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c8_i, c8_e_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c8_y, c8_e_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(c8_z, c8_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(c8_c, c8_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(c8_kx1, c8_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(c8_kx2, c8_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(c8_p, c8_j_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(c8_q, c8_j_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(c8_theta1, c8_i_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(c8_theta2, c8_i_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(c8_Nsol, c8_e_sf_marshall, 24U);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6, 3);
  for (c8_i538 = 0; c8_i538 < 2; c8_i538 = c8_i538 + 1) {
    c8_theta1[c8_i538] = 0.0;
  }

  _SFD_SCRIPT_CALL(6, 4);
  for (c8_i539 = 0; c8_i539 < 2; c8_i539 = c8_i539 + 1) {
    c8_theta2[c8_i539] = 0.0;
  }

  /*  ============================================= %     */
  /*  Twist 2 is the one that rotation happens first */
  /*  ============================================= % */
  _SFD_SCRIPT_CALL(6, 9);
  for (c8_i540 = 0; c8_i540 < 3; c8_i540 = c8_i540 + 1) {
    c8_velociy1[c8_i540] = c8_kx1[c8_i540];
  }

  _SFD_SCRIPT_CALL(6, 10);
  for (c8_i541 = 0; c8_i541 < 3; c8_i541 = c8_i541 + 1) {
    c8_w1[c8_i541] = c8_kx1[c8_i541 + 3];
  }

  /*  rotation axis for twist1 */
  _SFD_SCRIPT_CALL(6, 11);
  for (c8_i542 = 0; c8_i542 < 3; c8_i542 = c8_i542 + 1) {
    c8_b_velociy1[c8_i542] = c8_velociy1[c8_i542];
  }

  for (c8_i543 = 0; c8_i543 < 3; c8_i543 = c8_i543 + 1) {
    c8_b_w1[c8_i543] = c8_w1[c8_i543];
  }

  c8_cross(chartInstance, c8_b_velociy1, c8_b_w1, c8_dv30);
  for (c8_i544 = 0; c8_i544 < 3; c8_i544 = c8_i544 + 1) {
    c8_r1[c8_i544] = -c8_dv30[c8_i544];
  }

  /*  one point in w1 axis */
  _SFD_SCRIPT_CALL(6, 13);
  for (c8_i545 = 0; c8_i545 < 3; c8_i545 = c8_i545 + 1) {
    c8_velociy2[c8_i545] = c8_kx2[c8_i545];
  }

  _SFD_SCRIPT_CALL(6, 14);
  for (c8_i546 = 0; c8_i546 < 3; c8_i546 = c8_i546 + 1) {
    c8_w2[c8_i546] = c8_kx2[c8_i546 + 3];
  }

  /*  rotation axis for twist2 */
  _SFD_SCRIPT_CALL(6, 15);
  for (c8_i547 = 0; c8_i547 < 3; c8_i547 = c8_i547 + 1) {
    c8_b_velociy2[c8_i547] = c8_velociy2[c8_i547];
  }

  for (c8_i548 = 0; c8_i548 < 3; c8_i548 = c8_i548 + 1) {
    c8_b_w2[c8_i548] = c8_w2[c8_i548];
  }

  c8_cross(chartInstance, c8_b_velociy2, c8_b_w2, c8_dv31);
  for (c8_i549 = 0; c8_i549 < 3; c8_i549 = c8_i549 + 1) {
    c8_r2[c8_i549] = -c8_dv31[c8_i549];
  }

  /*  one point in w2 axis */
  /* find the common point of two axis */
  _SFD_SCRIPT_CALL(6, 18);
  for (c8_i550 = 0; c8_i550 < 3; c8_i550 = c8_i550 + 1) {
    c8_c_w1[c8_i550] = c8_w1[c8_i550];
  }

  for (c8_i551 = 0; c8_i551 < 3; c8_i551 = c8_i551 + 1) {
    c8_c_w2[c8_i551] = c8_w2[c8_i551];
  }

  for (c8_i552 = 0; c8_i552 < 3; c8_i552 = c8_i552 + 1) {
    c8_b_r1[c8_i552] = c8_r1[c8_i552];
  }

  for (c8_i553 = 0; c8_i553 < 3; c8_i553 = c8_i553 + 1) {
    c8_b_r2[c8_i553] = c8_r2[c8_i553];
  }

  c8_findCommon(chartInstance, c8_c_w1, c8_c_w2, c8_b_r1, c8_b_r2, c8_dv32);
  for (c8_i554 = 0; c8_i554 < 3; c8_i554 = c8_i554 + 1) {
    c8_r[c8_i554] = c8_dv32[c8_i554];
  }

  _SFD_SCRIPT_CALL(6, 20);
  for (c8_i555 = 0; c8_i555 < 3; c8_i555 = c8_i555 + 1) {
    c8_u[c8_i555] = c8_p[c8_i555] - c8_r[c8_i555];
  }

  _SFD_SCRIPT_CALL(6, 21);
  for (c8_i556 = 0; c8_i556 < 3; c8_i556 = c8_i556 + 1) {
    c8_v[c8_i556] = c8_q[c8_i556] - c8_r[c8_i556];
  }

  _SFD_SCRIPT_CALL(6, 23);
  for (c8_i557 = 0; c8_i557 < 3; c8_i557 = c8_i557 + 1) {
    c8_a[c8_i557] = c8_w1[c8_i557];
  }

  for (c8_i558 = 0; c8_i558 < 3; c8_i558 = c8_i558 + 1) {
    c8_b[c8_i558] = c8_w2[c8_i558];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i559 = 0; c8_i559 < 3; c8_i559 = c8_i559 + 1) {
    c8_x[c8_i559] = c8_a[c8_i559];
  }

  for (c8_i560 = 0; c8_i560 < 3; c8_i560 = c8_i560 + 1) {
    c8_b_y[c8_i560] = c8_b[c8_i560];
  }

  for (c8_i561 = 0; c8_i561 < 3; c8_i561 = c8_i561 + 1) {
    c8_b_x[c8_i561] = c8_x[c8_i561];
  }

  for (c8_i562 = 0; c8_i562 < 3; c8_i562 = c8_i562 + 1) {
    c8_c_y[c8_i562] = c8_b_y[c8_i562];
  }

  for (c8_i563 = 0; c8_i563 < 3; c8_i563 = c8_i563 + 1) {
    c8_c_x[c8_i563] = c8_b_x[c8_i563];
  }

  for (c8_i564 = 0; c8_i564 < 3; c8_i564 = c8_i564 + 1) {
    c8_d_y[c8_i564] = c8_c_y[c8_i564];
  }

  for (c8_i565 = 0; c8_i565 < 3; c8_i565 = c8_i565 + 1) {
    c8_d_x[c8_i565] = c8_c_x[c8_i565];
  }

  for (c8_i566 = 0; c8_i566 < 3; c8_i566 = c8_i566 + 1) {
    c8_e_y[c8_i566] = c8_d_y[c8_i566];
  }

  c8_f_y = c8_ceval_xdot(chartInstance, 3, c8_d_x, 1, 1, c8_e_y, 1, 1);
  c8_b_a = c8_f_y;
  for (c8_i567 = 0; c8_i567 < 3; c8_i567 = c8_i567 + 1) {
    c8_b_b[c8_i567] = c8_w2[c8_i567];
  }

  for (c8_i568 = 0; c8_i568 < 3; c8_i568 = c8_i568 + 1) {
    c8_g_y[c8_i568] = c8_b_a * c8_b_b[c8_i568];
  }

  for (c8_i569 = 0; c8_i569 < 3; c8_i569 = c8_i569 + 1) {
    c8_c_a[c8_i569] = c8_g_y[c8_i569];
  }

  for (c8_i570 = 0; c8_i570 < 3; c8_i570 = c8_i570 + 1) {
    c8_c_b[c8_i570] = c8_u[c8_i570];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i571 = 0; c8_i571 < 3; c8_i571 = c8_i571 + 1) {
    c8_e_x[c8_i571] = c8_c_a[c8_i571];
  }

  for (c8_i572 = 0; c8_i572 < 3; c8_i572 = c8_i572 + 1) {
    c8_h_y[c8_i572] = c8_c_b[c8_i572];
  }

  for (c8_i573 = 0; c8_i573 < 3; c8_i573 = c8_i573 + 1) {
    c8_f_x[c8_i573] = c8_e_x[c8_i573];
  }

  for (c8_i574 = 0; c8_i574 < 3; c8_i574 = c8_i574 + 1) {
    c8_i_y[c8_i574] = c8_h_y[c8_i574];
  }

  for (c8_i575 = 0; c8_i575 < 3; c8_i575 = c8_i575 + 1) {
    c8_g_x[c8_i575] = c8_f_x[c8_i575];
  }

  for (c8_i576 = 0; c8_i576 < 3; c8_i576 = c8_i576 + 1) {
    c8_j_y[c8_i576] = c8_i_y[c8_i576];
  }

  for (c8_i577 = 0; c8_i577 < 3; c8_i577 = c8_i577 + 1) {
    c8_h_x[c8_i577] = c8_g_x[c8_i577];
  }

  for (c8_i578 = 0; c8_i578 < 3; c8_i578 = c8_i578 + 1) {
    c8_k_y[c8_i578] = c8_j_y[c8_i578];
  }

  c8_l_y = c8_ceval_xdot(chartInstance, 3, c8_h_x, 1, 1, c8_k_y, 1, 1);
  for (c8_i579 = 0; c8_i579 < 3; c8_i579 = c8_i579 + 1) {
    c8_d_a[c8_i579] = c8_w1[c8_i579];
  }

  for (c8_i580 = 0; c8_i580 < 3; c8_i580 = c8_i580 + 1) {
    c8_d_b[c8_i580] = c8_v[c8_i580];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i581 = 0; c8_i581 < 3; c8_i581 = c8_i581 + 1) {
    c8_i_x[c8_i581] = c8_d_a[c8_i581];
  }

  for (c8_i582 = 0; c8_i582 < 3; c8_i582 = c8_i582 + 1) {
    c8_m_y[c8_i582] = c8_d_b[c8_i582];
  }

  for (c8_i583 = 0; c8_i583 < 3; c8_i583 = c8_i583 + 1) {
    c8_j_x[c8_i583] = c8_i_x[c8_i583];
  }

  for (c8_i584 = 0; c8_i584 < 3; c8_i584 = c8_i584 + 1) {
    c8_n_y[c8_i584] = c8_m_y[c8_i584];
  }

  for (c8_i585 = 0; c8_i585 < 3; c8_i585 = c8_i585 + 1) {
    c8_k_x[c8_i585] = c8_j_x[c8_i585];
  }

  for (c8_i586 = 0; c8_i586 < 3; c8_i586 = c8_i586 + 1) {
    c8_o_y[c8_i586] = c8_n_y[c8_i586];
  }

  for (c8_i587 = 0; c8_i587 < 3; c8_i587 = c8_i587 + 1) {
    c8_l_x[c8_i587] = c8_k_x[c8_i587];
  }

  for (c8_i588 = 0; c8_i588 < 3; c8_i588 = c8_i588 + 1) {
    c8_p_y[c8_i588] = c8_o_y[c8_i588];
  }

  c8_q_y = c8_ceval_xdot(chartInstance, 3, c8_l_x, 1, 1, c8_p_y, 1, 1);
  for (c8_i589 = 0; c8_i589 < 3; c8_i589 = c8_i589 + 1) {
    c8_e_a[c8_i589] = c8_w1[c8_i589];
  }

  for (c8_i590 = 0; c8_i590 < 3; c8_i590 = c8_i590 + 1) {
    c8_e_b[c8_i590] = c8_w2[c8_i590];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i591 = 0; c8_i591 < 3; c8_i591 = c8_i591 + 1) {
    c8_m_x[c8_i591] = c8_e_a[c8_i591];
  }

  for (c8_i592 = 0; c8_i592 < 3; c8_i592 = c8_i592 + 1) {
    c8_r_y[c8_i592] = c8_e_b[c8_i592];
  }

  for (c8_i593 = 0; c8_i593 < 3; c8_i593 = c8_i593 + 1) {
    c8_n_x[c8_i593] = c8_m_x[c8_i593];
  }

  for (c8_i594 = 0; c8_i594 < 3; c8_i594 = c8_i594 + 1) {
    c8_s_y[c8_i594] = c8_r_y[c8_i594];
  }

  for (c8_i595 = 0; c8_i595 < 3; c8_i595 = c8_i595 + 1) {
    c8_o_x[c8_i595] = c8_n_x[c8_i595];
  }

  for (c8_i596 = 0; c8_i596 < 3; c8_i596 = c8_i596 + 1) {
    c8_t_y[c8_i596] = c8_s_y[c8_i596];
  }

  for (c8_i597 = 0; c8_i597 < 3; c8_i597 = c8_i597 + 1) {
    c8_p_x[c8_i597] = c8_o_x[c8_i597];
  }

  for (c8_i598 = 0; c8_i598 < 3; c8_i598 = c8_i598 + 1) {
    c8_u_y[c8_i598] = c8_t_y[c8_i598];
  }

  c8_v_y = c8_ceval_xdot(chartInstance, 3, c8_p_x, 1, 1, c8_u_y, 1, 1);
  for (c8_i599 = 0; c8_i599 < 3; c8_i599 = c8_i599 + 1) {
    c8_f_a[c8_i599] = c8_w1[c8_i599];
  }

  for (c8_i600 = 0; c8_i600 < 3; c8_i600 = c8_i600 + 1) {
    c8_f_b[c8_i600] = c8_w2[c8_i600];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i601 = 0; c8_i601 < 3; c8_i601 = c8_i601 + 1) {
    c8_q_x[c8_i601] = c8_f_a[c8_i601];
  }

  for (c8_i602 = 0; c8_i602 < 3; c8_i602 = c8_i602 + 1) {
    c8_w_y[c8_i602] = c8_f_b[c8_i602];
  }

  for (c8_i603 = 0; c8_i603 < 3; c8_i603 = c8_i603 + 1) {
    c8_r_x[c8_i603] = c8_q_x[c8_i603];
  }

  for (c8_i604 = 0; c8_i604 < 3; c8_i604 = c8_i604 + 1) {
    c8_x_y[c8_i604] = c8_w_y[c8_i604];
  }

  for (c8_i605 = 0; c8_i605 < 3; c8_i605 = c8_i605 + 1) {
    c8_s_x[c8_i605] = c8_r_x[c8_i605];
  }

  for (c8_i606 = 0; c8_i606 < 3; c8_i606 = c8_i606 + 1) {
    c8_y_y[c8_i606] = c8_x_y[c8_i606];
  }

  for (c8_i607 = 0; c8_i607 < 3; c8_i607 = c8_i607 + 1) {
    c8_t_x[c8_i607] = c8_s_x[c8_i607];
  }

  for (c8_i608 = 0; c8_i608 < 3; c8_i608 = c8_i608 + 1) {
    c8_ab_y[c8_i608] = c8_y_y[c8_i608];
  }

  c8_bb_y = c8_ceval_xdot(chartInstance, 3, c8_t_x, 1, 1, c8_ab_y, 1, 1);
  c8_g_a = c8_v_y;
  c8_g_b = c8_bb_y;
  c8_cb_y = c8_g_a * c8_g_b;
  c8_A = c8_l_y - c8_q_y;
  c8_B = c8_cb_y - 1.0;
  c8_u_x = c8_A;
  c8_db_y = c8_B;
  c8_v_x = c8_u_x;
  c8_eb_y = c8_db_y;
  c8_w_x = c8_v_x;
  c8_fb_y = c8_eb_y;
  c8_alpha = c8_w_x / c8_fb_y;
  _SFD_SCRIPT_CALL(6, 24);
  for (c8_i609 = 0; c8_i609 < 3; c8_i609 = c8_i609 + 1) {
    c8_h_a[c8_i609] = c8_w1[c8_i609];
  }

  for (c8_i610 = 0; c8_i610 < 3; c8_i610 = c8_i610 + 1) {
    c8_h_b[c8_i610] = c8_w2[c8_i610];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i611 = 0; c8_i611 < 3; c8_i611 = c8_i611 + 1) {
    c8_x_x[c8_i611] = c8_h_a[c8_i611];
  }

  for (c8_i612 = 0; c8_i612 < 3; c8_i612 = c8_i612 + 1) {
    c8_gb_y[c8_i612] = c8_h_b[c8_i612];
  }

  for (c8_i613 = 0; c8_i613 < 3; c8_i613 = c8_i613 + 1) {
    c8_y_x[c8_i613] = c8_x_x[c8_i613];
  }

  for (c8_i614 = 0; c8_i614 < 3; c8_i614 = c8_i614 + 1) {
    c8_hb_y[c8_i614] = c8_gb_y[c8_i614];
  }

  for (c8_i615 = 0; c8_i615 < 3; c8_i615 = c8_i615 + 1) {
    c8_ab_x[c8_i615] = c8_y_x[c8_i615];
  }

  for (c8_i616 = 0; c8_i616 < 3; c8_i616 = c8_i616 + 1) {
    c8_ib_y[c8_i616] = c8_hb_y[c8_i616];
  }

  for (c8_i617 = 0; c8_i617 < 3; c8_i617 = c8_i617 + 1) {
    c8_bb_x[c8_i617] = c8_ab_x[c8_i617];
  }

  for (c8_i618 = 0; c8_i618 < 3; c8_i618 = c8_i618 + 1) {
    c8_jb_y[c8_i618] = c8_ib_y[c8_i618];
  }

  c8_kb_y = c8_ceval_xdot(chartInstance, 3, c8_bb_x, 1, 1, c8_jb_y, 1, 1);
  c8_i_a = c8_kb_y;
  for (c8_i619 = 0; c8_i619 < 3; c8_i619 = c8_i619 + 1) {
    c8_i_b[c8_i619] = c8_w1[c8_i619];
  }

  for (c8_i620 = 0; c8_i620 < 3; c8_i620 = c8_i620 + 1) {
    c8_lb_y[c8_i620] = c8_i_a * c8_i_b[c8_i620];
  }

  for (c8_i621 = 0; c8_i621 < 3; c8_i621 = c8_i621 + 1) {
    c8_j_a[c8_i621] = c8_lb_y[c8_i621];
  }

  for (c8_i622 = 0; c8_i622 < 3; c8_i622 = c8_i622 + 1) {
    c8_j_b[c8_i622] = c8_v[c8_i622];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i623 = 0; c8_i623 < 3; c8_i623 = c8_i623 + 1) {
    c8_cb_x[c8_i623] = c8_j_a[c8_i623];
  }

  for (c8_i624 = 0; c8_i624 < 3; c8_i624 = c8_i624 + 1) {
    c8_mb_y[c8_i624] = c8_j_b[c8_i624];
  }

  for (c8_i625 = 0; c8_i625 < 3; c8_i625 = c8_i625 + 1) {
    c8_db_x[c8_i625] = c8_cb_x[c8_i625];
  }

  for (c8_i626 = 0; c8_i626 < 3; c8_i626 = c8_i626 + 1) {
    c8_nb_y[c8_i626] = c8_mb_y[c8_i626];
  }

  for (c8_i627 = 0; c8_i627 < 3; c8_i627 = c8_i627 + 1) {
    c8_eb_x[c8_i627] = c8_db_x[c8_i627];
  }

  for (c8_i628 = 0; c8_i628 < 3; c8_i628 = c8_i628 + 1) {
    c8_ob_y[c8_i628] = c8_nb_y[c8_i628];
  }

  for (c8_i629 = 0; c8_i629 < 3; c8_i629 = c8_i629 + 1) {
    c8_fb_x[c8_i629] = c8_eb_x[c8_i629];
  }

  for (c8_i630 = 0; c8_i630 < 3; c8_i630 = c8_i630 + 1) {
    c8_pb_y[c8_i630] = c8_ob_y[c8_i630];
  }

  c8_qb_y = c8_ceval_xdot(chartInstance, 3, c8_fb_x, 1, 1, c8_pb_y, 1, 1);
  for (c8_i631 = 0; c8_i631 < 3; c8_i631 = c8_i631 + 1) {
    c8_k_a[c8_i631] = c8_w2[c8_i631];
  }

  for (c8_i632 = 0; c8_i632 < 3; c8_i632 = c8_i632 + 1) {
    c8_k_b[c8_i632] = c8_u[c8_i632];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i633 = 0; c8_i633 < 3; c8_i633 = c8_i633 + 1) {
    c8_gb_x[c8_i633] = c8_k_a[c8_i633];
  }

  for (c8_i634 = 0; c8_i634 < 3; c8_i634 = c8_i634 + 1) {
    c8_rb_y[c8_i634] = c8_k_b[c8_i634];
  }

  for (c8_i635 = 0; c8_i635 < 3; c8_i635 = c8_i635 + 1) {
    c8_hb_x[c8_i635] = c8_gb_x[c8_i635];
  }

  for (c8_i636 = 0; c8_i636 < 3; c8_i636 = c8_i636 + 1) {
    c8_sb_y[c8_i636] = c8_rb_y[c8_i636];
  }

  for (c8_i637 = 0; c8_i637 < 3; c8_i637 = c8_i637 + 1) {
    c8_ib_x[c8_i637] = c8_hb_x[c8_i637];
  }

  for (c8_i638 = 0; c8_i638 < 3; c8_i638 = c8_i638 + 1) {
    c8_tb_y[c8_i638] = c8_sb_y[c8_i638];
  }

  for (c8_i639 = 0; c8_i639 < 3; c8_i639 = c8_i639 + 1) {
    c8_jb_x[c8_i639] = c8_ib_x[c8_i639];
  }

  for (c8_i640 = 0; c8_i640 < 3; c8_i640 = c8_i640 + 1) {
    c8_ub_y[c8_i640] = c8_tb_y[c8_i640];
  }

  c8_vb_y = c8_ceval_xdot(chartInstance, 3, c8_jb_x, 1, 1, c8_ub_y, 1, 1);
  for (c8_i641 = 0; c8_i641 < 3; c8_i641 = c8_i641 + 1) {
    c8_l_a[c8_i641] = c8_w1[c8_i641];
  }

  for (c8_i642 = 0; c8_i642 < 3; c8_i642 = c8_i642 + 1) {
    c8_l_b[c8_i642] = c8_w2[c8_i642];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i643 = 0; c8_i643 < 3; c8_i643 = c8_i643 + 1) {
    c8_kb_x[c8_i643] = c8_l_a[c8_i643];
  }

  for (c8_i644 = 0; c8_i644 < 3; c8_i644 = c8_i644 + 1) {
    c8_wb_y[c8_i644] = c8_l_b[c8_i644];
  }

  for (c8_i645 = 0; c8_i645 < 3; c8_i645 = c8_i645 + 1) {
    c8_lb_x[c8_i645] = c8_kb_x[c8_i645];
  }

  for (c8_i646 = 0; c8_i646 < 3; c8_i646 = c8_i646 + 1) {
    c8_xb_y[c8_i646] = c8_wb_y[c8_i646];
  }

  for (c8_i647 = 0; c8_i647 < 3; c8_i647 = c8_i647 + 1) {
    c8_mb_x[c8_i647] = c8_lb_x[c8_i647];
  }

  for (c8_i648 = 0; c8_i648 < 3; c8_i648 = c8_i648 + 1) {
    c8_yb_y[c8_i648] = c8_xb_y[c8_i648];
  }

  for (c8_i649 = 0; c8_i649 < 3; c8_i649 = c8_i649 + 1) {
    c8_nb_x[c8_i649] = c8_mb_x[c8_i649];
  }

  for (c8_i650 = 0; c8_i650 < 3; c8_i650 = c8_i650 + 1) {
    c8_ac_y[c8_i650] = c8_yb_y[c8_i650];
  }

  c8_bc_y = c8_ceval_xdot(chartInstance, 3, c8_nb_x, 1, 1, c8_ac_y, 1, 1);
  for (c8_i651 = 0; c8_i651 < 3; c8_i651 = c8_i651 + 1) {
    c8_m_a[c8_i651] = c8_w1[c8_i651];
  }

  for (c8_i652 = 0; c8_i652 < 3; c8_i652 = c8_i652 + 1) {
    c8_m_b[c8_i652] = c8_w2[c8_i652];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i653 = 0; c8_i653 < 3; c8_i653 = c8_i653 + 1) {
    c8_ob_x[c8_i653] = c8_m_a[c8_i653];
  }

  for (c8_i654 = 0; c8_i654 < 3; c8_i654 = c8_i654 + 1) {
    c8_cc_y[c8_i654] = c8_m_b[c8_i654];
  }

  for (c8_i655 = 0; c8_i655 < 3; c8_i655 = c8_i655 + 1) {
    c8_pb_x[c8_i655] = c8_ob_x[c8_i655];
  }

  for (c8_i656 = 0; c8_i656 < 3; c8_i656 = c8_i656 + 1) {
    c8_dc_y[c8_i656] = c8_cc_y[c8_i656];
  }

  for (c8_i657 = 0; c8_i657 < 3; c8_i657 = c8_i657 + 1) {
    c8_qb_x[c8_i657] = c8_pb_x[c8_i657];
  }

  for (c8_i658 = 0; c8_i658 < 3; c8_i658 = c8_i658 + 1) {
    c8_ec_y[c8_i658] = c8_dc_y[c8_i658];
  }

  for (c8_i659 = 0; c8_i659 < 3; c8_i659 = c8_i659 + 1) {
    c8_rb_x[c8_i659] = c8_qb_x[c8_i659];
  }

  for (c8_i660 = 0; c8_i660 < 3; c8_i660 = c8_i660 + 1) {
    c8_fc_y[c8_i660] = c8_ec_y[c8_i660];
  }

  c8_gc_y = c8_ceval_xdot(chartInstance, 3, c8_rb_x, 1, 1, c8_fc_y, 1, 1);
  c8_n_a = c8_bc_y;
  c8_n_b = c8_gc_y;
  c8_hc_y = c8_n_a * c8_n_b;
  c8_b_A = c8_qb_y - c8_vb_y;
  c8_b_B = c8_hc_y - 1.0;
  c8_sb_x = c8_b_A;
  c8_ic_y = c8_b_B;
  c8_tb_x = c8_sb_x;
  c8_jc_y = c8_ic_y;
  c8_ub_x = c8_tb_x;
  c8_kc_y = c8_jc_y;
  c8_beta = c8_ub_x / c8_kc_y;
  _SFD_SCRIPT_CALL(6, 26);
  for (c8_i661 = 0; c8_i661 < 3; c8_i661 = c8_i661 + 1) {
    c8_o_a[c8_i661] = c8_u[c8_i661];
  }

  for (c8_i662 = 0; c8_i662 < 3; c8_i662 = c8_i662 + 1) {
    c8_o_b[c8_i662] = c8_u[c8_i662];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i663 = 0; c8_i663 < 3; c8_i663 = c8_i663 + 1) {
    c8_vb_x[c8_i663] = c8_o_a[c8_i663];
  }

  for (c8_i664 = 0; c8_i664 < 3; c8_i664 = c8_i664 + 1) {
    c8_lc_y[c8_i664] = c8_o_b[c8_i664];
  }

  for (c8_i665 = 0; c8_i665 < 3; c8_i665 = c8_i665 + 1) {
    c8_wb_x[c8_i665] = c8_vb_x[c8_i665];
  }

  for (c8_i666 = 0; c8_i666 < 3; c8_i666 = c8_i666 + 1) {
    c8_mc_y[c8_i666] = c8_lc_y[c8_i666];
  }

  for (c8_i667 = 0; c8_i667 < 3; c8_i667 = c8_i667 + 1) {
    c8_xb_x[c8_i667] = c8_wb_x[c8_i667];
  }

  for (c8_i668 = 0; c8_i668 < 3; c8_i668 = c8_i668 + 1) {
    c8_nc_y[c8_i668] = c8_mc_y[c8_i668];
  }

  for (c8_i669 = 0; c8_i669 < 3; c8_i669 = c8_i669 + 1) {
    c8_yb_x[c8_i669] = c8_xb_x[c8_i669];
  }

  for (c8_i670 = 0; c8_i670 < 3; c8_i670 = c8_i670 + 1) {
    c8_oc_y[c8_i670] = c8_nc_y[c8_i670];
  }

  c8_pc_y = c8_ceval_xdot(chartInstance, 3, c8_yb_x, 1, 1, c8_oc_y, 1, 1);
  c8_p_a = c8_alpha;
  c8_p_b = c8_alpha;
  c8_qc_y = c8_p_a * c8_p_b;
  c8_q_a = c8_beta;
  c8_q_b = c8_beta;
  c8_rc_y = c8_q_a * c8_q_b;
  c8_r_b = c8_beta;
  c8_sc_y = 2.0 * c8_r_b;
  c8_r_a = c8_sc_y;
  c8_s_b = c8_alpha;
  c8_tc_y = c8_r_a * c8_s_b;
  c8_s_a = c8_tc_y;
  for (c8_i671 = 0; c8_i671 < 3; c8_i671 = c8_i671 + 1) {
    c8_t_b[c8_i671] = c8_w1[c8_i671];
  }

  for (c8_i672 = 0; c8_i672 < 3; c8_i672 = c8_i672 + 1) {
    c8_uc_y[c8_i672] = c8_s_a * c8_t_b[c8_i672];
  }

  for (c8_i673 = 0; c8_i673 < 3; c8_i673 = c8_i673 + 1) {
    c8_t_a[c8_i673] = c8_uc_y[c8_i673];
  }

  for (c8_i674 = 0; c8_i674 < 3; c8_i674 = c8_i674 + 1) {
    c8_u_b[c8_i674] = c8_w2[c8_i674];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i675 = 0; c8_i675 < 3; c8_i675 = c8_i675 + 1) {
    c8_ac_x[c8_i675] = c8_t_a[c8_i675];
  }

  for (c8_i676 = 0; c8_i676 < 3; c8_i676 = c8_i676 + 1) {
    c8_vc_y[c8_i676] = c8_u_b[c8_i676];
  }

  for (c8_i677 = 0; c8_i677 < 3; c8_i677 = c8_i677 + 1) {
    c8_bc_x[c8_i677] = c8_ac_x[c8_i677];
  }

  for (c8_i678 = 0; c8_i678 < 3; c8_i678 = c8_i678 + 1) {
    c8_wc_y[c8_i678] = c8_vc_y[c8_i678];
  }

  for (c8_i679 = 0; c8_i679 < 3; c8_i679 = c8_i679 + 1) {
    c8_cc_x[c8_i679] = c8_bc_x[c8_i679];
  }

  for (c8_i680 = 0; c8_i680 < 3; c8_i680 = c8_i680 + 1) {
    c8_xc_y[c8_i680] = c8_wc_y[c8_i680];
  }

  for (c8_i681 = 0; c8_i681 < 3; c8_i681 = c8_i681 + 1) {
    c8_dc_x[c8_i681] = c8_cc_x[c8_i681];
  }

  for (c8_i682 = 0; c8_i682 < 3; c8_i682 = c8_i682 + 1) {
    c8_yc_y[c8_i682] = c8_xc_y[c8_i682];
  }

  c8_ad_y = c8_ceval_xdot(chartInstance, 3, c8_dc_x, 1, 1, c8_yc_y, 1, 1);
  for (c8_i683 = 0; c8_i683 < 3; c8_i683 = c8_i683 + 1) {
    c8_d_w1[c8_i683] = c8_w1[c8_i683];
  }

  for (c8_i684 = 0; c8_i684 < 3; c8_i684 = c8_i684 + 1) {
    c8_d_w2[c8_i684] = c8_w2[c8_i684];
  }

  c8_cross(chartInstance, c8_d_w1, c8_d_w2, c8_dv33);
  for (c8_i685 = 0; c8_i685 < 3; c8_i685 = c8_i685 + 1) {
    c8_u_a[c8_i685] = c8_dv33[c8_i685];
  }

  for (c8_i686 = 0; c8_i686 < 3; c8_i686 = c8_i686 + 1) {
    c8_e_w1[c8_i686] = c8_w1[c8_i686];
  }

  for (c8_i687 = 0; c8_i687 < 3; c8_i687 = c8_i687 + 1) {
    c8_e_w2[c8_i687] = c8_w2[c8_i687];
  }

  c8_cross(chartInstance, c8_e_w1, c8_e_w2, c8_v_b);
  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i688 = 0; c8_i688 < 3; c8_i688 = c8_i688 + 1) {
    c8_ec_x[c8_i688] = c8_u_a[c8_i688];
  }

  for (c8_i689 = 0; c8_i689 < 3; c8_i689 = c8_i689 + 1) {
    c8_bd_y[c8_i689] = c8_v_b[c8_i689];
  }

  for (c8_i690 = 0; c8_i690 < 3; c8_i690 = c8_i690 + 1) {
    c8_fc_x[c8_i690] = c8_ec_x[c8_i690];
  }

  for (c8_i691 = 0; c8_i691 < 3; c8_i691 = c8_i691 + 1) {
    c8_cd_y[c8_i691] = c8_bd_y[c8_i691];
  }

  for (c8_i692 = 0; c8_i692 < 3; c8_i692 = c8_i692 + 1) {
    c8_gc_x[c8_i692] = c8_fc_x[c8_i692];
  }

  for (c8_i693 = 0; c8_i693 < 3; c8_i693 = c8_i693 + 1) {
    c8_dd_y[c8_i693] = c8_cd_y[c8_i693];
  }

  for (c8_i694 = 0; c8_i694 < 3; c8_i694 = c8_i694 + 1) {
    c8_hc_x[c8_i694] = c8_gc_x[c8_i694];
  }

  for (c8_i695 = 0; c8_i695 < 3; c8_i695 = c8_i695 + 1) {
    c8_ed_y[c8_i695] = c8_dd_y[c8_i695];
  }

  c8_fd_y = c8_ceval_xdot(chartInstance, 3, c8_hc_x, 1, 1, c8_ed_y, 1, 1);
  c8_c_A = ((c8_pc_y - c8_qc_y) - c8_rc_y) - c8_ad_y;
  c8_c_B = c8_fd_y;
  c8_ic_x = c8_c_A;
  c8_gd_y = c8_c_B;
  c8_jc_x = c8_ic_x;
  c8_hd_y = c8_gd_y;
  c8_kc_x = c8_jc_x;
  c8_id_y = c8_hd_y;
  c8_ySqu = c8_kc_x / c8_id_y;
  _SFD_SCRIPT_CALL(6, 28);
  if (CV_SCRIPT_IF(6, 0, c8_ySqu > 0.0)) {
    _SFD_SCRIPT_CALL(6, 29);
    *c8_Nsol = 2.0;
  } else {
    _SFD_SCRIPT_CALL(6, 30);
    if (CV_SCRIPT_IF(6, 1, c8_ySqu == 0.0)) {
      _SFD_SCRIPT_CALL(6, 31);
      *c8_Nsol = 1.0;
    } else {
      _SFD_SCRIPT_CALL(6, 33);
      *c8_Nsol = 0.0;
    }
  }

  _SFD_SCRIPT_CALL(6, 36);
  if (CV_SCRIPT_IF(6, 2, c8_ySqu >= 0.0)) {
    c8_i = 1.0;
    c8_b_i = 1.0;
    while (c8_b_i <= 2.0) {
      c8_i = c8_b_i;
      CV_SCRIPT_FOR(6, 0, 1);
      _SFD_SCRIPT_CALL(6, 39);
      c8_w_b = c8_i;
      c8_jd_y = 2.0 * c8_w_b;
      c8_lc_x = c8_ySqu;
      c8_mc_x = c8_lc_x;
      if (c8_mc_x < 0.0) {
        c8_c_eml_error(chartInstance);
      }

      c8_nc_x = c8_mc_x;
      c8_mc_x = c8_nc_x;
      c8_mc_x = muDoubleScalarSqrt(c8_mc_x);
      c8_v_a = c8_jd_y - 3.0;
      c8_x_b = c8_mc_x;
      c8_y = c8_v_a * c8_x_b;

      /*  could have two solutions in this step */
      _SFD_SCRIPT_CALL(6, 41);
      c8_w_a = c8_alpha;
      for (c8_i696 = 0; c8_i696 < 3; c8_i696 = c8_i696 + 1) {
        c8_y_b[c8_i696] = c8_w1[c8_i696];
      }

      for (c8_i697 = 0; c8_i697 < 3; c8_i697 = c8_i697 + 1) {
        c8_kd_y[c8_i697] = c8_w_a * c8_y_b[c8_i697];
      }

      c8_x_a = c8_beta;
      for (c8_i698 = 0; c8_i698 < 3; c8_i698 = c8_i698 + 1) {
        c8_ab_b[c8_i698] = c8_w2[c8_i698];
      }

      for (c8_i699 = 0; c8_i699 < 3; c8_i699 = c8_i699 + 1) {
        c8_ld_y[c8_i699] = c8_x_a * c8_ab_b[c8_i699];
      }

      c8_y_a = c8_y;
      for (c8_i700 = 0; c8_i700 < 3; c8_i700 = c8_i700 + 1) {
        c8_f_w1[c8_i700] = c8_w1[c8_i700];
      }

      for (c8_i701 = 0; c8_i701 < 3; c8_i701 = c8_i701 + 1) {
        c8_f_w2[c8_i701] = c8_w2[c8_i701];
      }

      c8_cross(chartInstance, c8_f_w1, c8_f_w2, c8_bb_b);
      for (c8_i702 = 0; c8_i702 < 3; c8_i702 = c8_i702 + 1) {
        c8_md_y[c8_i702] = c8_y_a * c8_bb_b[c8_i702];
      }

      for (c8_i703 = 0; c8_i703 < 3; c8_i703 = c8_i703 + 1) {
        c8_z[c8_i703] = (c8_kd_y[c8_i703] + c8_ld_y[c8_i703]) - c8_md_y[c8_i703];
      }

      _SFD_SCRIPT_CALL(6, 43);
      for (c8_i704 = 0; c8_i704 < 3; c8_i704 = c8_i704 + 1) {
        c8_c[c8_i704] = c8_z[c8_i704] + c8_r[c8_i704];
      }

      /*  the common point in the rotation if there are solutions */
      _SFD_SCRIPT_CALL(6, 45);
      for (c8_i705 = 0; c8_i705 < 6; c8_i705 = c8_i705 + 1) {
        c8_b_kx2[c8_i705] = c8_kx2[c8_i705];
      }

      for (c8_i706 = 0; c8_i706 < 4; c8_i706 = c8_i706 + 1) {
        c8_b_p[c8_i706] = c8_p[c8_i706];
      }

      for (c8_i707 = 0; c8_i707 < 3; c8_i707 = c8_i707 + 1) {
        c8_b_c[c8_i707] = c8_c[c8_i707];
      }

      c8_theta2[_SFD_EML_ARRAY_BOUNDS_CHECK("theta2", (int32_T)
        _SFD_INTEGER_CHECK("i", c8_i), 1, 2, 1, 0) - 1] = c8_b_subPro1(
        chartInstance, c8_b_kx2, c8_b_p, c8_b_c);
      _SFD_SCRIPT_CALL(6, 46);
      for (c8_i708 = 0; c8_i708 < 6; c8_i708 = c8_i708 + 1) {
        c8_b_kx1[c8_i708] = c8_kx1[c8_i708];
      }

      for (c8_i709 = 0; c8_i709 < 3; c8_i709 = c8_i709 + 1) {
        c8_c_c[c8_i709] = c8_c[c8_i709];
      }

      for (c8_i710 = 0; c8_i710 < 4; c8_i710 = c8_i710 + 1) {
        c8_b_q[c8_i710] = c8_q[c8_i710];
      }

      c8_theta1[_SFD_EML_ARRAY_BOUNDS_CHECK("theta1", (int32_T)
        _SFD_INTEGER_CHECK("i", c8_i), 1, 2, 1, 0) - 1] = c8_c_subPro1(
        chartInstance, c8_b_kx1, c8_c_c, c8_b_q);
      c8_b_i = c8_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_SCRIPT_FOR(6, 0, 0);
  }

  _SFD_SCRIPT_CALL(6, -46);
  sf_debug_symbol_scope_pop();
}

static void c8_findCommon(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_w1[3], real_T c8_w2[3], real_T c8_r1[3], real_T
  c8_r2[3], real_T c8_r[3])
{
  uint32_T c8_debug_family_var_map[10];
  real_T c8_A[4];
  real_T c8_vec[2];
  real_T c8_cof[2];
  real_T c8_nargin = 4.0;
  real_T c8_nargout = 1.0;
  real_T c8_b_r2[2];
  int32_T c8_i711;
  int32_T c8_i712;
  real_T c8_b_A[4];
  real_T c8_c_r2[2];
  int32_T c8_i713;
  int32_T c8_i714;
  real_T c8_c_A[4];
  real_T c8_d_r2[2];
  int32_T c8_i715;
  int32_T c8_i716;
  real_T c8_d_A[4];
  int32_T c8_i717;
  real_T c8_B[2];
  int32_T c8_i718;
  real_T c8_e_A[4];
  int32_T c8_i719;
  real_T c8_b_B[2];
  int32_T c8_i720;
  real_T c8_f_A[4];
  int32_T c8_i721;
  real_T c8_c_B[2];
  real_T c8_x;
  real_T c8_b_x;
  real_T c8_c_x;
  real_T c8_y;
  real_T c8_d_x;
  real_T c8_e_x;
  real_T c8_b_y;
  real_T c8_d;
  real_T c8_f_x;
  real_T c8_g_x;
  real_T c8_h_x;
  real_T c8_c_y;
  real_T c8_i_x;
  real_T c8_j_x;
  real_T c8_d_y;
  real_T c8_b_d;
  int32_T c8_b_r1;
  int32_T c8_e_r2;
  real_T c8_k_x;
  real_T c8_e_y;
  real_T c8_l_x;
  real_T c8_f_y;
  real_T c8_a21;
  real_T c8_a;
  real_T c8_b;
  real_T c8_g_y;
  real_T c8_a22;
  real_T c8_b_a;
  real_T c8_b_b;
  real_T c8_h_y;
  real_T c8_m_x;
  real_T c8_i_y;
  real_T c8_n_x;
  real_T c8_j_y;
  real_T c8_z;
  real_T c8_c_a;
  real_T c8_c_b;
  real_T c8_k_y;
  real_T c8_o_x;
  real_T c8_l_y;
  real_T c8_p_x;
  real_T c8_m_y;
  real_T c8_b_z;
  int32_T c8_i722;
  real_T c8_d_a[3];
  real_T c8_d_b;
  int32_T c8_i723;
  real_T c8_n_y[3];
  int32_T c8_i724;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c8_i_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_A, c8_l_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_vec, c8_i_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_cof, c8_i_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_w1, c8_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_w2, c8_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c8_r1, c8_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c8_r2, c8_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c8_r, c8_d_sf_marshall, 9U);
  CV_SCRIPT_FCN(6, 1);
  _SFD_SCRIPT_CALL(6, 56);
  c8_A[0] = c8_w1[0];
  c8_A[2] = -c8_w2[0];
  c8_A[1] = c8_w1[1];
  c8_A[3] = -c8_w2[1];
  _SFD_SCRIPT_CALL(6, 57);
  c8_b_r2[0] = c8_r2[0] - c8_r1[0];
  c8_b_r2[1] = c8_r2[1] - c8_r1[1];
  for (c8_i711 = 0; c8_i711 < 2; c8_i711 = c8_i711 + 1) {
    c8_vec[c8_i711] = c8_b_r2[c8_i711];
  }

  _SFD_SCRIPT_CALL(6, 59);
  for (c8_i712 = 0; c8_i712 < 4; c8_i712 = c8_i712 + 1) {
    c8_b_A[c8_i712] = c8_A[c8_i712];
  }

  if (CV_SCRIPT_IF(6, 3, c8_det(chartInstance, c8_b_A) == 0.0)) {
    /*  if the first two set of para are parallel */
    _SFD_SCRIPT_CALL(6, 60);
    c8_A[0] = c8_w1[0];
    c8_A[2] = -c8_w2[0];
    c8_A[1] = c8_w1[2];
    c8_A[3] = -c8_w2[2];
    _SFD_SCRIPT_CALL(6, 61);
    c8_c_r2[0] = c8_r2[0] - c8_r1[0];
    c8_c_r2[1] = c8_r2[2] - c8_r1[2];
    for (c8_i713 = 0; c8_i713 < 2; c8_i713 = c8_i713 + 1) {
      c8_vec[c8_i713] = c8_c_r2[c8_i713];
    }
  }

  _SFD_SCRIPT_CALL(6, 64);
  for (c8_i714 = 0; c8_i714 < 4; c8_i714 = c8_i714 + 1) {
    c8_c_A[c8_i714] = c8_A[c8_i714];
  }

  if (CV_SCRIPT_IF(6, 4, c8_det(chartInstance, c8_c_A) == 0.0)) {
    _SFD_SCRIPT_CALL(6, 65);
    c8_A[0] = c8_w1[1];
    c8_A[2] = -c8_w2[1];
    c8_A[1] = c8_w1[2];
    c8_A[3] = -c8_w2[2];
    _SFD_SCRIPT_CALL(6, 66);
    c8_d_r2[0] = c8_r2[1] - c8_r1[1];
    c8_d_r2[1] = c8_r2[2] - c8_r1[2];
    for (c8_i715 = 0; c8_i715 < 2; c8_i715 = c8_i715 + 1) {
      c8_vec[c8_i715] = c8_d_r2[c8_i715];
    }
  }

  _SFD_SCRIPT_CALL(6, 69);
  for (c8_i716 = 0; c8_i716 < 4; c8_i716 = c8_i716 + 1) {
    c8_d_A[c8_i716] = c8_A[c8_i716];
  }

  for (c8_i717 = 0; c8_i717 < 2; c8_i717 = c8_i717 + 1) {
    c8_B[c8_i717] = c8_vec[c8_i717];
  }

  for (c8_i718 = 0; c8_i718 < 4; c8_i718 = c8_i718 + 1) {
    c8_e_A[c8_i718] = c8_d_A[c8_i718];
  }

  for (c8_i719 = 0; c8_i719 < 2; c8_i719 = c8_i719 + 1) {
    c8_b_B[c8_i719] = c8_B[c8_i719];
  }

  for (c8_i720 = 0; c8_i720 < 4; c8_i720 = c8_i720 + 1) {
    c8_f_A[c8_i720] = c8_e_A[c8_i720];
  }

  for (c8_i721 = 0; c8_i721 < 2; c8_i721 = c8_i721 + 1) {
    c8_c_B[c8_i721] = c8_b_B[c8_i721];
  }

  c8_x = c8_f_A[1];
  c8_b_x = c8_x;
  c8_c_x = c8_b_x;
  c8_y = muDoubleScalarAbs(c8_c_x);
  c8_d_x = 0.0;
  c8_e_x = c8_d_x;
  c8_b_y = muDoubleScalarAbs(c8_e_x);
  c8_d = c8_y + c8_b_y;
  c8_f_x = c8_f_A[0];
  c8_g_x = c8_f_x;
  c8_h_x = c8_g_x;
  c8_c_y = muDoubleScalarAbs(c8_h_x);
  c8_i_x = 0.0;
  c8_j_x = c8_i_x;
  c8_d_y = muDoubleScalarAbs(c8_j_x);
  c8_b_d = c8_c_y + c8_d_y;
  if (c8_d > c8_b_d) {
    c8_b_r1 = 2;
    c8_e_r2 = 1;
  } else {
    c8_b_r1 = 1;
    c8_e_r2 = 2;
  }

  c8_k_x = c8_f_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_e_r2), 1, 2, 1, 0) - 1];
  c8_e_y = c8_f_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_b_r1), 1, 2, 1, 0) - 1];
  c8_l_x = c8_k_x;
  c8_f_y = c8_e_y;
  c8_a21 = c8_l_x / c8_f_y;
  c8_a = c8_a21;
  c8_b = c8_f_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_b_r1), 1, 2, 1, 0) + 1];
  c8_g_y = c8_a * c8_b;
  c8_a22 = c8_f_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_e_r2), 1, 2, 1, 0) + 1] - c8_g_y;
  if (c8_a22 == 0.0) {
  } else if (c8_f_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c8_b_r1), 1, 2, 1, 0) - 1] == 0.0) {
  } else {
    goto label_1;
  }

  c8_eml_warning(chartInstance);
 label_1:
  ;
  c8_b_a = c8_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_b_r1), 1, 2, 1, 0) - 1];
  c8_b_b = c8_a21;
  c8_h_y = c8_b_a * c8_b_b;
  c8_m_x = c8_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_e_r2), 1, 2, 1, 0) - 1] - c8_h_y;
  c8_i_y = c8_a22;
  c8_n_x = c8_m_x;
  c8_j_y = c8_i_y;
  c8_z = c8_n_x / c8_j_y;
  c8_cof[1] = c8_z;
  c8_c_a = c8_cof[1];
  c8_c_b = c8_f_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_b_r1), 1, 2, 1, 0) + 1];
  c8_k_y = c8_c_a * c8_c_b;
  c8_o_x = c8_c_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_b_r1), 1, 2, 1, 0) - 1] - c8_k_y;
  c8_l_y = c8_f_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c8_b_r1), 1, 2, 1, 0) - 1];
  c8_p_x = c8_o_x;
  c8_m_y = c8_l_y;
  c8_b_z = c8_p_x / c8_m_y;
  c8_cof[0] = c8_b_z;

  /*  get the inverse */
  _SFD_SCRIPT_CALL(6, 71);
  for (c8_i722 = 0; c8_i722 < 3; c8_i722 = c8_i722 + 1) {
    c8_d_a[c8_i722] = c8_w1[c8_i722];
  }

  c8_d_b = c8_cof[0];
  for (c8_i723 = 0; c8_i723 < 3; c8_i723 = c8_i723 + 1) {
    c8_n_y[c8_i723] = c8_d_a[c8_i723] * c8_d_b;
  }

  for (c8_i724 = 0; c8_i724 < 3; c8_i724 = c8_i724 + 1) {
    c8_r[c8_i724] = c8_r1[c8_i724] + c8_n_y[c8_i724];
  }

  _SFD_SCRIPT_CALL(6, -71);
  sf_debug_symbol_scope_pop();
}

static real_T c8_det(SFc8_DynTaskConInstanceStruct *chartInstance, real_T c8_x[4])
{
  real_T c8_y;
  int32_T c8_i725;
  real_T c8_A[4];
  int32_T c8_i726;
  real_T c8_b_x[4];
  int32_T c8_i727;
  real_T c8_b_A[4];
  int32_T c8_i728;
  real_T c8_c_A[4];
  int32_T c8_i729;
  real_T c8_d_A[4];
  int32_T c8_info;
  int32_T c8_ipiv[2];
  real_T c8_e_A[4];
  int32_T c8_i730;
  int32_T c8_i731;
  int32_T c8_b_ipiv[2];
  int32_T c8_i732;
  int32_T c8_i733;
  int32_T c8_c_ipiv[2];
  int32_T c8_i734;
  int32_T c8_i735;
  int32_T c8_d_ipiv[2];
  real_T c8_a;
  real_T c8_b;
  boolean_T c8_isodd;
  for (c8_i725 = 0; c8_i725 < 4; c8_i725 = c8_i725 + 1) {
    c8_A[c8_i725] = c8_x[c8_i725];
  }

  for (c8_i726 = 0; c8_i726 < 4; c8_i726 = c8_i726 + 1) {
    c8_b_x[c8_i726] = c8_A[c8_i726];
  }

  for (c8_i727 = 0; c8_i727 < 4; c8_i727 = c8_i727 + 1) {
    c8_b_A[c8_i727] = c8_b_x[c8_i727];
  }

  for (c8_i728 = 0; c8_i728 < 4; c8_i728 = c8_i728 + 1) {
    c8_c_A[c8_i728] = c8_b_A[c8_i728];
  }

  for (c8_i729 = 0; c8_i729 < 4; c8_i729 = c8_i729 + 1) {
    c8_d_A[c8_i729] = c8_c_A[c8_i729];
  }

  c8_b_eml_matlab_zgetrf(chartInstance, c8_d_A, c8_e_A, c8_ipiv, &c8_info);
  for (c8_i730 = 0; c8_i730 < 4; c8_i730 = c8_i730 + 1) {
    c8_c_A[c8_i730] = c8_e_A[c8_i730];
  }

  for (c8_i731 = 0; c8_i731 < 2; c8_i731 = c8_i731 + 1) {
    c8_b_ipiv[c8_i731] = c8_ipiv[c8_i731];
  }

  for (c8_i732 = 0; c8_i732 < 4; c8_i732 = c8_i732 + 1) {
    c8_b_x[c8_i732] = c8_c_A[c8_i732];
  }

  for (c8_i733 = 0; c8_i733 < 2; c8_i733 = c8_i733 + 1) {
    c8_c_ipiv[c8_i733] = c8_b_ipiv[c8_i733];
  }

  for (c8_i734 = 0; c8_i734 < 4; c8_i734 = c8_i734 + 1) {
    c8_x[c8_i734] = c8_b_x[c8_i734];
  }

  for (c8_i735 = 0; c8_i735 < 2; c8_i735 = c8_i735 + 1) {
    c8_d_ipiv[c8_i735] = c8_c_ipiv[c8_i735];
  }

  c8_y = c8_x[0];
  c8_a = c8_y;
  c8_b = c8_x[3];
  c8_y = c8_a * c8_b;
  c8_isodd = FALSE;
  if ((real_T)c8_d_ipiv[0] > 1.0) {
    c8_isodd = TRUE;
  }

  if (c8_isodd) {
    return -c8_y;
  }

  return c8_y;
}

static void c8_b_eml_matlab_zgetrf(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_A[4], real_T c8_b_A[4], int32_T c8_ipiv[2
  ], int32_T *c8_info)
{
  int32_T c8_i736;
  int32_T c8_i737;
  int32_T c8_i738;
  real_T c8_c_A[4];
  int32_T c8_a;
  int32_T c8_jpiv_offset;
  int32_T c8_b;
  int32_T c8_jpiv;
  int32_T c8_b_b;
  int32_T c8_c;
  int32_T c8_c_b;
  int32_T c8_jprow;
  int32_T c8_i739;
  real_T c8_x[4];
  int32_T c8_iy0;
  int32_T c8_i740;
  int32_T c8_i741;
  real_T c8_b_x[4];
  int32_T c8_b_iy0;
  int32_T c8_i742;
  real_T c8_c_x[4];
  int32_T c8_i743;
  real_T c8_d_x[4];
  real_T c8_e_x[4];
  int32_T c8_i744;
  int32_T c8_i745;
  real_T c8_f_x;
  real_T c8_y;
  real_T c8_g_x;
  real_T c8_b_y;
  real_T c8_z;
  int32_T c8_i746;
  real_T c8_d_A[4];
  int32_T c8_i747;
  int32_T c8_i748;
  real_T c8_e_A[4];
  int32_T c8_i749;
  int32_T c8_i750;
  real_T c8_f_A[4];
  int32_T c8_i751;
  int32_T c8_i752;
  real_T c8_g_A[4];
  for (c8_i736 = 0; c8_i736 < 4; c8_i736 = c8_i736 + 1) {
    c8_b_A[c8_i736] = c8_A[c8_i736];
  }

  c8_eps(chartInstance);
  for (c8_i737 = 0; c8_i737 < 2; c8_i737 = c8_i737 + 1) {
    c8_ipiv[c8_i737] = 1 + c8_i737;
  }

  *c8_info = 0;
  for (c8_i738 = 0; c8_i738 < 4; c8_i738 = c8_i738 + 1) {
    c8_c_A[c8_i738] = c8_b_A[c8_i738];
  }

  c8_a = c8_b_eml_ixamax(chartInstance, c8_c_A);
  c8_jpiv_offset = c8_a - 1;
  c8_b = c8_jpiv_offset;
  c8_jpiv = 1 + c8_b;
  if (c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c8_jpiv), 1, 4, 1, 0) - 1] != 0.0) {
    if ((real_T)c8_jpiv_offset != 0.0) {
      c8_b_b = c8_jpiv_offset;
      c8_c = 1 + c8_b_b;
      c8_ipiv[0] = c8_c;
      c8_c_b = c8_jpiv_offset;
      c8_jprow = 1 + c8_c_b;
      for (c8_i739 = 0; c8_i739 < 4; c8_i739 = c8_i739 + 1) {
        c8_x[c8_i739] = c8_b_A[c8_i739];
      }

      c8_iy0 = c8_jprow;
      for (c8_i740 = 0; c8_i740 < 4; c8_i740 = c8_i740 + 1) {
        c8_b_A[c8_i740] = c8_x[c8_i740];
      }

      for (c8_i741 = 0; c8_i741 < 4; c8_i741 = c8_i741 + 1) {
        c8_b_x[c8_i741] = c8_b_A[c8_i741];
      }

      c8_b_iy0 = c8_iy0;
      for (c8_i742 = 0; c8_i742 < 4; c8_i742 = c8_i742 + 1) {
        c8_c_x[c8_i742] = c8_b_x[c8_i742];
      }

      for (c8_i743 = 0; c8_i743 < 4; c8_i743 = c8_i743 + 1) {
        c8_d_x[c8_i743] = c8_c_x[c8_i743];
      }

      c8_b_ceval_xswap(chartInstance, 2, c8_d_x, 1, 2, c8_b_iy0, 2, c8_e_x);
      for (c8_i744 = 0; c8_i744 < 4; c8_i744 = c8_i744 + 1) {
        c8_c_x[c8_i744] = c8_e_x[c8_i744];
      }

      for (c8_i745 = 0; c8_i745 < 4; c8_i745 = c8_i745 + 1) {
        c8_b_A[c8_i745] = c8_c_x[c8_i745];
      }
    }

    c8_f_x = c8_b_A[1];
    c8_y = c8_b_A[0];
    c8_g_x = c8_f_x;
    c8_b_y = c8_y;
    c8_z = c8_g_x / c8_b_y;
    c8_b_A[1] = c8_z;
  } else {
    *c8_info = 1;
  }

  for (c8_i746 = 0; c8_i746 < 4; c8_i746 = c8_i746 + 1) {
    c8_d_A[c8_i746] = c8_b_A[c8_i746];
  }

  for (c8_i747 = 0; c8_i747 < 4; c8_i747 = c8_i747 + 1) {
    c8_b_A[c8_i747] = c8_d_A[c8_i747];
  }

  for (c8_i748 = 0; c8_i748 < 4; c8_i748 = c8_i748 + 1) {
    c8_e_A[c8_i748] = c8_b_A[c8_i748];
  }

  for (c8_i749 = 0; c8_i749 < 4; c8_i749 = c8_i749 + 1) {
    c8_b_A[c8_i749] = c8_e_A[c8_i749];
  }

  for (c8_i750 = 0; c8_i750 < 4; c8_i750 = c8_i750 + 1) {
    c8_f_A[c8_i750] = c8_b_A[c8_i750];
  }

  for (c8_i751 = 0; c8_i751 < 4; c8_i751 = c8_i751 + 1) {
    c8_b_A[c8_i751] = c8_f_A[c8_i751];
  }

  for (c8_i752 = 0; c8_i752 < 4; c8_i752 = c8_i752 + 1) {
    c8_g_A[c8_i752] = c8_b_A[c8_i752];
  }

  c8_b_ceval_xger(chartInstance, 1, 1, -1.0, 2, 1, 3, 2, c8_g_A, 4, 2, c8_b_A);
  if ((real_T)*c8_info == 0.0) {
    if (!(c8_b_A[3] != 0.0)) {
      *c8_info = 2;
      return;
    }
  }
}

static int32_T c8_b_eml_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  real_T c8_x[4])
{
  int32_T c8_i753;
  real_T c8_b_x[4];
  int32_T c8_i754;
  real_T c8_c_x[4];
  for (c8_i753 = 0; c8_i753 < 4; c8_i753 = c8_i753 + 1) {
    c8_b_x[c8_i753] = c8_x[c8_i753];
  }

  for (c8_i754 = 0; c8_i754 < 4; c8_i754 = c8_i754 + 1) {
    c8_c_x[c8_i754] = c8_b_x[c8_i754];
  }

  return c8_b_ceval_ixamax(chartInstance, 2, c8_c_x, 1, 1);
}

static int32_T c8_b_ceval_ixamax(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[4], int32_T c8_ix0, int32_T
  c8_incx)
{
  return idamax32(&c8_n, &c8_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 4, 1, 0) - 1], &
                  c8_incx);
}

static void c8_b_ceval_xswap(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_n, real_T c8_x[4], int32_T c8_ix0, int32_T
  c8_incx, int32_T c8_iy0, int32_T c8_incy, real_T c8_b_x[4])
{
  int32_T c8_i755;

  /* Empty Loop. */
  for (c8_i755 = 0; c8_i755 < 4; c8_i755 = c8_i755 + 1) {
    c8_b_x[c8_i755] = c8_x[c8_i755];
  }

  dswap32(&c8_n, &c8_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 4, 1, 0) - 1], &c8_incx,
          &c8_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c8_iy0), 1, 4, 1, 0) - 1], &c8_incy);
}

static void c8_b_ceval_xger(SFc8_DynTaskConInstanceStruct *chartInstance,
  int32_T c8_m, int32_T c8_n, real_T c8_alpha1, int32_T
  c8_ix0, int32_T c8_incx, int32_T c8_iy0, int32_T c8_incy, real_T c8_A[4],
  int32_T c8_ia0, int32_T c8_lda, real_T c8_b_A[4])
{
  int32_T c8_i756;
  for (c8_i756 = 0; c8_i756 < 4; c8_i756 = c8_i756 + 1) {
    c8_b_A[c8_i756] = c8_A[c8_i756];
  }

  dger32(&c8_m, &c8_n, &c8_alpha1, &c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c8_ix0), 1, 4, 1, 0
          ) - 1], &c8_incx, &c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_iy0), 1, 4, 1, 0) - 1], &
         c8_incy, &c8_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c8_ia0), 1, 4, 1, 0) - 1], &c8_lda);
}

static void c8_c_eml_error(SFc8_DynTaskConInstanceStruct *chartInstance)
{
  int32_T c8_i757;
  static char_T c8_cv6[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c8_u[31];
  const mxArray *c8_y = NULL;
  int32_T c8_i758;
  static char_T c8_cv7[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c8_b_u[77];
  const mxArray *c8_b_y = NULL;
  for (c8_i757 = 0; c8_i757 < 31; c8_i757 = c8_i757 + 1) {
    c8_u[c8_i757] = c8_cv6[c8_i757];
  }

  c8_y = NULL;
  sf_mex_assign(&c8_y, sf_mex_create("y", c8_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c8_i758 = 0; c8_i758 < 77; c8_i758 = c8_i758 + 1) {
    c8_b_u[c8_i758] = c8_cv7[c8_i758];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c8_y, 14, c8_b_y);
}

static real_T c8_b_subPro1(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[4], real_T c8_q[3])
{
  real_T c8_theta;
  uint32_T c8_debug_family_var_map[13];
  real_T c8_velociy[3];
  real_T c8_w[3];
  real_T c8_r[3];
  real_T c8_u[3];
  real_T c8_v[3];
  real_T c8_up[3];
  real_T c8_vp[3];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i759;
  int32_T c8_i760;
  int32_T c8_i761;
  real_T c8_b_velociy[3];
  int32_T c8_i762;
  real_T c8_b_w[3];
  real_T c8_dv34[3];
  int32_T c8_i763;
  int32_T c8_i764;
  int32_T c8_i765;
  int32_T c8_i766;
  real_T c8_a[3];
  int32_T c8_i767;
  real_T c8_b[3];
  int32_T c8_i768;
  real_T c8_x[3];
  int32_T c8_i769;
  real_T c8_y[3];
  int32_T c8_i770;
  real_T c8_b_x[3];
  int32_T c8_i771;
  real_T c8_b_y[3];
  int32_T c8_i772;
  real_T c8_c_x[3];
  int32_T c8_i773;
  real_T c8_c_y[3];
  int32_T c8_i774;
  real_T c8_d_x[3];
  int32_T c8_i775;
  real_T c8_d_y[3];
  real_T c8_e_y;
  int32_T c8_i776;
  real_T c8_b_a[3];
  real_T c8_b_b;
  int32_T c8_i777;
  real_T c8_f_y[3];
  int32_T c8_i778;
  int32_T c8_i779;
  real_T c8_c_a[3];
  int32_T c8_i780;
  real_T c8_c_b[3];
  int32_T c8_i781;
  real_T c8_e_x[3];
  int32_T c8_i782;
  real_T c8_g_y[3];
  int32_T c8_i783;
  real_T c8_f_x[3];
  int32_T c8_i784;
  real_T c8_h_y[3];
  int32_T c8_i785;
  real_T c8_g_x[3];
  int32_T c8_i786;
  real_T c8_i_y[3];
  int32_T c8_i787;
  real_T c8_h_x[3];
  int32_T c8_i788;
  real_T c8_j_y[3];
  real_T c8_k_y;
  int32_T c8_i789;
  real_T c8_d_a[3];
  real_T c8_d_b;
  int32_T c8_i790;
  real_T c8_l_y[3];
  int32_T c8_i791;
  int32_T c8_i792;
  real_T c8_e_a[3];
  int32_T c8_i793;
  real_T c8_b_up[3];
  int32_T c8_i794;
  real_T c8_b_vp[3];
  real_T c8_e_b[3];
  int32_T c8_i795;
  real_T c8_i_x[3];
  int32_T c8_i796;
  real_T c8_m_y[3];
  int32_T c8_i797;
  real_T c8_j_x[3];
  int32_T c8_i798;
  real_T c8_n_y[3];
  int32_T c8_i799;
  real_T c8_k_x[3];
  int32_T c8_i800;
  real_T c8_o_y[3];
  int32_T c8_i801;
  real_T c8_l_x[3];
  int32_T c8_i802;
  real_T c8_p_y[3];
  real_T c8_q_y;
  int32_T c8_i803;
  real_T c8_f_a[3];
  int32_T c8_i804;
  real_T c8_f_b[3];
  int32_T c8_i805;
  real_T c8_m_x[3];
  int32_T c8_i806;
  real_T c8_r_y[3];
  int32_T c8_i807;
  real_T c8_n_x[3];
  int32_T c8_i808;
  real_T c8_s_y[3];
  int32_T c8_i809;
  real_T c8_o_x[3];
  int32_T c8_i810;
  real_T c8_t_y[3];
  int32_T c8_i811;
  real_T c8_p_x[3];
  int32_T c8_i812;
  real_T c8_u_y[3];
  real_T c8_v_y;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c8_j_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_velociy, c8_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_w, c8_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_r, c8_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_u, c8_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c8_v, c8_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_up, c8_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_vp, c8_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c8_kx, c8_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c8_p, c8_j_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c8_q, c8_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c8_theta, c8_e_sf_marshall, 12U);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5, 4);
  for (c8_i759 = 0; c8_i759 < 3; c8_i759 = c8_i759 + 1) {
    c8_velociy[c8_i759] = c8_kx[c8_i759];
  }

  _SFD_SCRIPT_CALL(5, 5);
  for (c8_i760 = 0; c8_i760 < 3; c8_i760 = c8_i760 + 1) {
    c8_w[c8_i760] = c8_kx[c8_i760 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(5, 6);
  for (c8_i761 = 0; c8_i761 < 3; c8_i761 = c8_i761 + 1) {
    c8_b_velociy[c8_i761] = c8_velociy[c8_i761];
  }

  for (c8_i762 = 0; c8_i762 < 3; c8_i762 = c8_i762 + 1) {
    c8_b_w[c8_i762] = c8_w[c8_i762];
  }

  c8_cross(chartInstance, c8_b_velociy, c8_b_w, c8_dv34);
  for (c8_i763 = 0; c8_i763 < 3; c8_i763 = c8_i763 + 1) {
    c8_r[c8_i763] = -c8_dv34[c8_i763];
  }

  _SFD_SCRIPT_CALL(5, 8);
  for (c8_i764 = 0; c8_i764 < 3; c8_i764 = c8_i764 + 1) {
    c8_u[c8_i764] = c8_p[c8_i764] - c8_r[c8_i764];
  }

  _SFD_SCRIPT_CALL(5, 9);
  for (c8_i765 = 0; c8_i765 < 3; c8_i765 = c8_i765 + 1) {
    c8_v[c8_i765] = c8_q[c8_i765] - c8_r[c8_i765];
  }

  _SFD_SCRIPT_CALL(5, 12);
  for (c8_i766 = 0; c8_i766 < 3; c8_i766 = c8_i766 + 1) {
    c8_a[c8_i766] = c8_w[c8_i766];
  }

  for (c8_i767 = 0; c8_i767 < 3; c8_i767 = c8_i767 + 1) {
    c8_b[c8_i767] = c8_u[c8_i767];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i768 = 0; c8_i768 < 3; c8_i768 = c8_i768 + 1) {
    c8_x[c8_i768] = c8_a[c8_i768];
  }

  for (c8_i769 = 0; c8_i769 < 3; c8_i769 = c8_i769 + 1) {
    c8_y[c8_i769] = c8_b[c8_i769];
  }

  for (c8_i770 = 0; c8_i770 < 3; c8_i770 = c8_i770 + 1) {
    c8_b_x[c8_i770] = c8_x[c8_i770];
  }

  for (c8_i771 = 0; c8_i771 < 3; c8_i771 = c8_i771 + 1) {
    c8_b_y[c8_i771] = c8_y[c8_i771];
  }

  for (c8_i772 = 0; c8_i772 < 3; c8_i772 = c8_i772 + 1) {
    c8_c_x[c8_i772] = c8_b_x[c8_i772];
  }

  for (c8_i773 = 0; c8_i773 < 3; c8_i773 = c8_i773 + 1) {
    c8_c_y[c8_i773] = c8_b_y[c8_i773];
  }

  for (c8_i774 = 0; c8_i774 < 3; c8_i774 = c8_i774 + 1) {
    c8_d_x[c8_i774] = c8_c_x[c8_i774];
  }

  for (c8_i775 = 0; c8_i775 < 3; c8_i775 = c8_i775 + 1) {
    c8_d_y[c8_i775] = c8_c_y[c8_i775];
  }

  c8_e_y = c8_ceval_xdot(chartInstance, 3, c8_d_x, 1, 1, c8_d_y, 1, 1);
  for (c8_i776 = 0; c8_i776 < 3; c8_i776 = c8_i776 + 1) {
    c8_b_a[c8_i776] = c8_w[c8_i776];
  }

  c8_b_b = c8_e_y;
  for (c8_i777 = 0; c8_i777 < 3; c8_i777 = c8_i777 + 1) {
    c8_f_y[c8_i777] = c8_b_a[c8_i777] * c8_b_b;
  }

  for (c8_i778 = 0; c8_i778 < 3; c8_i778 = c8_i778 + 1) {
    c8_up[c8_i778] = c8_u[c8_i778] - c8_f_y[c8_i778];
  }

  _SFD_SCRIPT_CALL(5, 13);
  for (c8_i779 = 0; c8_i779 < 3; c8_i779 = c8_i779 + 1) {
    c8_c_a[c8_i779] = c8_w[c8_i779];
  }

  for (c8_i780 = 0; c8_i780 < 3; c8_i780 = c8_i780 + 1) {
    c8_c_b[c8_i780] = c8_u[c8_i780];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i781 = 0; c8_i781 < 3; c8_i781 = c8_i781 + 1) {
    c8_e_x[c8_i781] = c8_c_a[c8_i781];
  }

  for (c8_i782 = 0; c8_i782 < 3; c8_i782 = c8_i782 + 1) {
    c8_g_y[c8_i782] = c8_c_b[c8_i782];
  }

  for (c8_i783 = 0; c8_i783 < 3; c8_i783 = c8_i783 + 1) {
    c8_f_x[c8_i783] = c8_e_x[c8_i783];
  }

  for (c8_i784 = 0; c8_i784 < 3; c8_i784 = c8_i784 + 1) {
    c8_h_y[c8_i784] = c8_g_y[c8_i784];
  }

  for (c8_i785 = 0; c8_i785 < 3; c8_i785 = c8_i785 + 1) {
    c8_g_x[c8_i785] = c8_f_x[c8_i785];
  }

  for (c8_i786 = 0; c8_i786 < 3; c8_i786 = c8_i786 + 1) {
    c8_i_y[c8_i786] = c8_h_y[c8_i786];
  }

  for (c8_i787 = 0; c8_i787 < 3; c8_i787 = c8_i787 + 1) {
    c8_h_x[c8_i787] = c8_g_x[c8_i787];
  }

  for (c8_i788 = 0; c8_i788 < 3; c8_i788 = c8_i788 + 1) {
    c8_j_y[c8_i788] = c8_i_y[c8_i788];
  }

  c8_k_y = c8_ceval_xdot(chartInstance, 3, c8_h_x, 1, 1, c8_j_y, 1, 1);
  for (c8_i789 = 0; c8_i789 < 3; c8_i789 = c8_i789 + 1) {
    c8_d_a[c8_i789] = c8_w[c8_i789];
  }

  c8_d_b = c8_k_y;
  for (c8_i790 = 0; c8_i790 < 3; c8_i790 = c8_i790 + 1) {
    c8_l_y[c8_i790] = c8_d_a[c8_i790] * c8_d_b;
  }

  for (c8_i791 = 0; c8_i791 < 3; c8_i791 = c8_i791 + 1) {
    c8_vp[c8_i791] = c8_v[c8_i791] - c8_l_y[c8_i791];
  }

  /*      if norm(up) == 0 */
  /*          error('SubPro1: up = 0, Infinite number of solutions!'); */
  /*      end */
  _SFD_SCRIPT_CALL(5, 19);
  for (c8_i792 = 0; c8_i792 < 3; c8_i792 = c8_i792 + 1) {
    c8_e_a[c8_i792] = c8_w[c8_i792];
  }

  for (c8_i793 = 0; c8_i793 < 3; c8_i793 = c8_i793 + 1) {
    c8_b_up[c8_i793] = c8_up[c8_i793];
  }

  for (c8_i794 = 0; c8_i794 < 3; c8_i794 = c8_i794 + 1) {
    c8_b_vp[c8_i794] = c8_vp[c8_i794];
  }

  c8_cross(chartInstance, c8_b_up, c8_b_vp, c8_e_b);
  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i795 = 0; c8_i795 < 3; c8_i795 = c8_i795 + 1) {
    c8_i_x[c8_i795] = c8_e_a[c8_i795];
  }

  for (c8_i796 = 0; c8_i796 < 3; c8_i796 = c8_i796 + 1) {
    c8_m_y[c8_i796] = c8_e_b[c8_i796];
  }

  for (c8_i797 = 0; c8_i797 < 3; c8_i797 = c8_i797 + 1) {
    c8_j_x[c8_i797] = c8_i_x[c8_i797];
  }

  for (c8_i798 = 0; c8_i798 < 3; c8_i798 = c8_i798 + 1) {
    c8_n_y[c8_i798] = c8_m_y[c8_i798];
  }

  for (c8_i799 = 0; c8_i799 < 3; c8_i799 = c8_i799 + 1) {
    c8_k_x[c8_i799] = c8_j_x[c8_i799];
  }

  for (c8_i800 = 0; c8_i800 < 3; c8_i800 = c8_i800 + 1) {
    c8_o_y[c8_i800] = c8_n_y[c8_i800];
  }

  for (c8_i801 = 0; c8_i801 < 3; c8_i801 = c8_i801 + 1) {
    c8_l_x[c8_i801] = c8_k_x[c8_i801];
  }

  for (c8_i802 = 0; c8_i802 < 3; c8_i802 = c8_i802 + 1) {
    c8_p_y[c8_i802] = c8_o_y[c8_i802];
  }

  c8_q_y = c8_ceval_xdot(chartInstance, 3, c8_l_x, 1, 1, c8_p_y, 1, 1);
  for (c8_i803 = 0; c8_i803 < 3; c8_i803 = c8_i803 + 1) {
    c8_f_a[c8_i803] = c8_up[c8_i803];
  }

  for (c8_i804 = 0; c8_i804 < 3; c8_i804 = c8_i804 + 1) {
    c8_f_b[c8_i804] = c8_vp[c8_i804];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i805 = 0; c8_i805 < 3; c8_i805 = c8_i805 + 1) {
    c8_m_x[c8_i805] = c8_f_a[c8_i805];
  }

  for (c8_i806 = 0; c8_i806 < 3; c8_i806 = c8_i806 + 1) {
    c8_r_y[c8_i806] = c8_f_b[c8_i806];
  }

  for (c8_i807 = 0; c8_i807 < 3; c8_i807 = c8_i807 + 1) {
    c8_n_x[c8_i807] = c8_m_x[c8_i807];
  }

  for (c8_i808 = 0; c8_i808 < 3; c8_i808 = c8_i808 + 1) {
    c8_s_y[c8_i808] = c8_r_y[c8_i808];
  }

  for (c8_i809 = 0; c8_i809 < 3; c8_i809 = c8_i809 + 1) {
    c8_o_x[c8_i809] = c8_n_x[c8_i809];
  }

  for (c8_i810 = 0; c8_i810 < 3; c8_i810 = c8_i810 + 1) {
    c8_t_y[c8_i810] = c8_s_y[c8_i810];
  }

  for (c8_i811 = 0; c8_i811 < 3; c8_i811 = c8_i811 + 1) {
    c8_p_x[c8_i811] = c8_o_x[c8_i811];
  }

  for (c8_i812 = 0; c8_i812 < 3; c8_i812 = c8_i812 + 1) {
    c8_u_y[c8_i812] = c8_t_y[c8_i812];
  }

  c8_v_y = c8_ceval_xdot(chartInstance, 3, c8_p_x, 1, 1, c8_u_y, 1, 1);
  c8_theta = c8_atan2(chartInstance, c8_q_y, c8_v_y);
  _SFD_SCRIPT_CALL(5, -19);
  sf_debug_symbol_scope_pop();
  return c8_theta;
}

static real_T c8_c_subPro1(SFc8_DynTaskConInstanceStruct *chartInstance, real_T
  c8_kx[6], real_T c8_p[3], real_T c8_q[4])
{
  real_T c8_theta;
  uint32_T c8_debug_family_var_map[13];
  real_T c8_velociy[3];
  real_T c8_w[3];
  real_T c8_r[3];
  real_T c8_u[3];
  real_T c8_v[3];
  real_T c8_up[3];
  real_T c8_vp[3];
  real_T c8_nargin = 3.0;
  real_T c8_nargout = 1.0;
  int32_T c8_i813;
  int32_T c8_i814;
  int32_T c8_i815;
  real_T c8_b_velociy[3];
  int32_T c8_i816;
  real_T c8_b_w[3];
  real_T c8_dv35[3];
  int32_T c8_i817;
  int32_T c8_i818;
  int32_T c8_i819;
  int32_T c8_i820;
  real_T c8_a[3];
  int32_T c8_i821;
  real_T c8_b[3];
  int32_T c8_i822;
  real_T c8_x[3];
  int32_T c8_i823;
  real_T c8_y[3];
  int32_T c8_i824;
  real_T c8_b_x[3];
  int32_T c8_i825;
  real_T c8_b_y[3];
  int32_T c8_i826;
  real_T c8_c_x[3];
  int32_T c8_i827;
  real_T c8_c_y[3];
  int32_T c8_i828;
  real_T c8_d_x[3];
  int32_T c8_i829;
  real_T c8_d_y[3];
  real_T c8_e_y;
  int32_T c8_i830;
  real_T c8_b_a[3];
  real_T c8_b_b;
  int32_T c8_i831;
  real_T c8_f_y[3];
  int32_T c8_i832;
  int32_T c8_i833;
  real_T c8_c_a[3];
  int32_T c8_i834;
  real_T c8_c_b[3];
  int32_T c8_i835;
  real_T c8_e_x[3];
  int32_T c8_i836;
  real_T c8_g_y[3];
  int32_T c8_i837;
  real_T c8_f_x[3];
  int32_T c8_i838;
  real_T c8_h_y[3];
  int32_T c8_i839;
  real_T c8_g_x[3];
  int32_T c8_i840;
  real_T c8_i_y[3];
  int32_T c8_i841;
  real_T c8_h_x[3];
  int32_T c8_i842;
  real_T c8_j_y[3];
  real_T c8_k_y;
  int32_T c8_i843;
  real_T c8_d_a[3];
  real_T c8_d_b;
  int32_T c8_i844;
  real_T c8_l_y[3];
  int32_T c8_i845;
  int32_T c8_i846;
  real_T c8_e_a[3];
  int32_T c8_i847;
  real_T c8_b_up[3];
  int32_T c8_i848;
  real_T c8_b_vp[3];
  real_T c8_e_b[3];
  int32_T c8_i849;
  real_T c8_i_x[3];
  int32_T c8_i850;
  real_T c8_m_y[3];
  int32_T c8_i851;
  real_T c8_j_x[3];
  int32_T c8_i852;
  real_T c8_n_y[3];
  int32_T c8_i853;
  real_T c8_k_x[3];
  int32_T c8_i854;
  real_T c8_o_y[3];
  int32_T c8_i855;
  real_T c8_l_x[3];
  int32_T c8_i856;
  real_T c8_p_y[3];
  real_T c8_q_y;
  int32_T c8_i857;
  real_T c8_f_a[3];
  int32_T c8_i858;
  real_T c8_f_b[3];
  int32_T c8_i859;
  real_T c8_m_x[3];
  int32_T c8_i860;
  real_T c8_r_y[3];
  int32_T c8_i861;
  real_T c8_n_x[3];
  int32_T c8_i862;
  real_T c8_s_y[3];
  int32_T c8_i863;
  real_T c8_o_x[3];
  int32_T c8_i864;
  real_T c8_t_y[3];
  int32_T c8_i865;
  real_T c8_p_x[3];
  int32_T c8_i866;
  real_T c8_u_y[3];
  real_T c8_v_y;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c8_k_debug_family_names,
    c8_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c8_velociy, c8_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c8_w, c8_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c8_r, c8_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c8_u, c8_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c8_v, c8_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c8_up, c8_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c8_vp, c8_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c8_nargin, c8_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c8_nargout, c8_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c8_kx, c8_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c8_p, c8_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c8_q, c8_j_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c8_theta, c8_e_sf_marshall, 12U);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5, 4);
  for (c8_i813 = 0; c8_i813 < 3; c8_i813 = c8_i813 + 1) {
    c8_velociy[c8_i813] = c8_kx[c8_i813];
  }

  _SFD_SCRIPT_CALL(5, 5);
  for (c8_i814 = 0; c8_i814 < 3; c8_i814 = c8_i814 + 1) {
    c8_w[c8_i814] = c8_kx[c8_i814 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(5, 6);
  for (c8_i815 = 0; c8_i815 < 3; c8_i815 = c8_i815 + 1) {
    c8_b_velociy[c8_i815] = c8_velociy[c8_i815];
  }

  for (c8_i816 = 0; c8_i816 < 3; c8_i816 = c8_i816 + 1) {
    c8_b_w[c8_i816] = c8_w[c8_i816];
  }

  c8_cross(chartInstance, c8_b_velociy, c8_b_w, c8_dv35);
  for (c8_i817 = 0; c8_i817 < 3; c8_i817 = c8_i817 + 1) {
    c8_r[c8_i817] = -c8_dv35[c8_i817];
  }

  _SFD_SCRIPT_CALL(5, 8);
  for (c8_i818 = 0; c8_i818 < 3; c8_i818 = c8_i818 + 1) {
    c8_u[c8_i818] = c8_p[c8_i818] - c8_r[c8_i818];
  }

  _SFD_SCRIPT_CALL(5, 9);
  for (c8_i819 = 0; c8_i819 < 3; c8_i819 = c8_i819 + 1) {
    c8_v[c8_i819] = c8_q[c8_i819] - c8_r[c8_i819];
  }

  _SFD_SCRIPT_CALL(5, 12);
  for (c8_i820 = 0; c8_i820 < 3; c8_i820 = c8_i820 + 1) {
    c8_a[c8_i820] = c8_w[c8_i820];
  }

  for (c8_i821 = 0; c8_i821 < 3; c8_i821 = c8_i821 + 1) {
    c8_b[c8_i821] = c8_u[c8_i821];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i822 = 0; c8_i822 < 3; c8_i822 = c8_i822 + 1) {
    c8_x[c8_i822] = c8_a[c8_i822];
  }

  for (c8_i823 = 0; c8_i823 < 3; c8_i823 = c8_i823 + 1) {
    c8_y[c8_i823] = c8_b[c8_i823];
  }

  for (c8_i824 = 0; c8_i824 < 3; c8_i824 = c8_i824 + 1) {
    c8_b_x[c8_i824] = c8_x[c8_i824];
  }

  for (c8_i825 = 0; c8_i825 < 3; c8_i825 = c8_i825 + 1) {
    c8_b_y[c8_i825] = c8_y[c8_i825];
  }

  for (c8_i826 = 0; c8_i826 < 3; c8_i826 = c8_i826 + 1) {
    c8_c_x[c8_i826] = c8_b_x[c8_i826];
  }

  for (c8_i827 = 0; c8_i827 < 3; c8_i827 = c8_i827 + 1) {
    c8_c_y[c8_i827] = c8_b_y[c8_i827];
  }

  for (c8_i828 = 0; c8_i828 < 3; c8_i828 = c8_i828 + 1) {
    c8_d_x[c8_i828] = c8_c_x[c8_i828];
  }

  for (c8_i829 = 0; c8_i829 < 3; c8_i829 = c8_i829 + 1) {
    c8_d_y[c8_i829] = c8_c_y[c8_i829];
  }

  c8_e_y = c8_ceval_xdot(chartInstance, 3, c8_d_x, 1, 1, c8_d_y, 1, 1);
  for (c8_i830 = 0; c8_i830 < 3; c8_i830 = c8_i830 + 1) {
    c8_b_a[c8_i830] = c8_w[c8_i830];
  }

  c8_b_b = c8_e_y;
  for (c8_i831 = 0; c8_i831 < 3; c8_i831 = c8_i831 + 1) {
    c8_f_y[c8_i831] = c8_b_a[c8_i831] * c8_b_b;
  }

  for (c8_i832 = 0; c8_i832 < 3; c8_i832 = c8_i832 + 1) {
    c8_up[c8_i832] = c8_u[c8_i832] - c8_f_y[c8_i832];
  }

  _SFD_SCRIPT_CALL(5, 13);
  for (c8_i833 = 0; c8_i833 < 3; c8_i833 = c8_i833 + 1) {
    c8_c_a[c8_i833] = c8_w[c8_i833];
  }

  for (c8_i834 = 0; c8_i834 < 3; c8_i834 = c8_i834 + 1) {
    c8_c_b[c8_i834] = c8_u[c8_i834];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i835 = 0; c8_i835 < 3; c8_i835 = c8_i835 + 1) {
    c8_e_x[c8_i835] = c8_c_a[c8_i835];
  }

  for (c8_i836 = 0; c8_i836 < 3; c8_i836 = c8_i836 + 1) {
    c8_g_y[c8_i836] = c8_c_b[c8_i836];
  }

  for (c8_i837 = 0; c8_i837 < 3; c8_i837 = c8_i837 + 1) {
    c8_f_x[c8_i837] = c8_e_x[c8_i837];
  }

  for (c8_i838 = 0; c8_i838 < 3; c8_i838 = c8_i838 + 1) {
    c8_h_y[c8_i838] = c8_g_y[c8_i838];
  }

  for (c8_i839 = 0; c8_i839 < 3; c8_i839 = c8_i839 + 1) {
    c8_g_x[c8_i839] = c8_f_x[c8_i839];
  }

  for (c8_i840 = 0; c8_i840 < 3; c8_i840 = c8_i840 + 1) {
    c8_i_y[c8_i840] = c8_h_y[c8_i840];
  }

  for (c8_i841 = 0; c8_i841 < 3; c8_i841 = c8_i841 + 1) {
    c8_h_x[c8_i841] = c8_g_x[c8_i841];
  }

  for (c8_i842 = 0; c8_i842 < 3; c8_i842 = c8_i842 + 1) {
    c8_j_y[c8_i842] = c8_i_y[c8_i842];
  }

  c8_k_y = c8_ceval_xdot(chartInstance, 3, c8_h_x, 1, 1, c8_j_y, 1, 1);
  for (c8_i843 = 0; c8_i843 < 3; c8_i843 = c8_i843 + 1) {
    c8_d_a[c8_i843] = c8_w[c8_i843];
  }

  c8_d_b = c8_k_y;
  for (c8_i844 = 0; c8_i844 < 3; c8_i844 = c8_i844 + 1) {
    c8_l_y[c8_i844] = c8_d_a[c8_i844] * c8_d_b;
  }

  for (c8_i845 = 0; c8_i845 < 3; c8_i845 = c8_i845 + 1) {
    c8_vp[c8_i845] = c8_v[c8_i845] - c8_l_y[c8_i845];
  }

  /*      if norm(up) == 0 */
  /*          error('SubPro1: up = 0, Infinite number of solutions!'); */
  /*      end */
  _SFD_SCRIPT_CALL(5, 19);
  for (c8_i846 = 0; c8_i846 < 3; c8_i846 = c8_i846 + 1) {
    c8_e_a[c8_i846] = c8_w[c8_i846];
  }

  for (c8_i847 = 0; c8_i847 < 3; c8_i847 = c8_i847 + 1) {
    c8_b_up[c8_i847] = c8_up[c8_i847];
  }

  for (c8_i848 = 0; c8_i848 < 3; c8_i848 = c8_i848 + 1) {
    c8_b_vp[c8_i848] = c8_vp[c8_i848];
  }

  c8_cross(chartInstance, c8_b_up, c8_b_vp, c8_e_b);
  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i849 = 0; c8_i849 < 3; c8_i849 = c8_i849 + 1) {
    c8_i_x[c8_i849] = c8_e_a[c8_i849];
  }

  for (c8_i850 = 0; c8_i850 < 3; c8_i850 = c8_i850 + 1) {
    c8_m_y[c8_i850] = c8_e_b[c8_i850];
  }

  for (c8_i851 = 0; c8_i851 < 3; c8_i851 = c8_i851 + 1) {
    c8_j_x[c8_i851] = c8_i_x[c8_i851];
  }

  for (c8_i852 = 0; c8_i852 < 3; c8_i852 = c8_i852 + 1) {
    c8_n_y[c8_i852] = c8_m_y[c8_i852];
  }

  for (c8_i853 = 0; c8_i853 < 3; c8_i853 = c8_i853 + 1) {
    c8_k_x[c8_i853] = c8_j_x[c8_i853];
  }

  for (c8_i854 = 0; c8_i854 < 3; c8_i854 = c8_i854 + 1) {
    c8_o_y[c8_i854] = c8_n_y[c8_i854];
  }

  for (c8_i855 = 0; c8_i855 < 3; c8_i855 = c8_i855 + 1) {
    c8_l_x[c8_i855] = c8_k_x[c8_i855];
  }

  for (c8_i856 = 0; c8_i856 < 3; c8_i856 = c8_i856 + 1) {
    c8_p_y[c8_i856] = c8_o_y[c8_i856];
  }

  c8_q_y = c8_ceval_xdot(chartInstance, 3, c8_l_x, 1, 1, c8_p_y, 1, 1);
  for (c8_i857 = 0; c8_i857 < 3; c8_i857 = c8_i857 + 1) {
    c8_f_a[c8_i857] = c8_up[c8_i857];
  }

  for (c8_i858 = 0; c8_i858 < 3; c8_i858 = c8_i858 + 1) {
    c8_f_b[c8_i858] = c8_vp[c8_i858];
  }

  c8_g_eml_scalar_eg(chartInstance);
  for (c8_i859 = 0; c8_i859 < 3; c8_i859 = c8_i859 + 1) {
    c8_m_x[c8_i859] = c8_f_a[c8_i859];
  }

  for (c8_i860 = 0; c8_i860 < 3; c8_i860 = c8_i860 + 1) {
    c8_r_y[c8_i860] = c8_f_b[c8_i860];
  }

  for (c8_i861 = 0; c8_i861 < 3; c8_i861 = c8_i861 + 1) {
    c8_n_x[c8_i861] = c8_m_x[c8_i861];
  }

  for (c8_i862 = 0; c8_i862 < 3; c8_i862 = c8_i862 + 1) {
    c8_s_y[c8_i862] = c8_r_y[c8_i862];
  }

  for (c8_i863 = 0; c8_i863 < 3; c8_i863 = c8_i863 + 1) {
    c8_o_x[c8_i863] = c8_n_x[c8_i863];
  }

  for (c8_i864 = 0; c8_i864 < 3; c8_i864 = c8_i864 + 1) {
    c8_t_y[c8_i864] = c8_s_y[c8_i864];
  }

  for (c8_i865 = 0; c8_i865 < 3; c8_i865 = c8_i865 + 1) {
    c8_p_x[c8_i865] = c8_o_x[c8_i865];
  }

  for (c8_i866 = 0; c8_i866 < 3; c8_i866 = c8_i866 + 1) {
    c8_u_y[c8_i866] = c8_t_y[c8_i866];
  }

  c8_v_y = c8_ceval_xdot(chartInstance, 3, c8_p_x, 1, 1, c8_u_y, 1, 1);
  c8_theta = c8_atan2(chartInstance, c8_q_y, c8_v_y);
  _SFD_SCRIPT_CALL(5, -19);
  sf_debug_symbol_scope_pop();
  return c8_theta;
}

static const mxArray *c8_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i867;
  real_T c8_b_u[6];
  int32_T c8_i868;
  real_T c8_c_u[6];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  for (c8_i867 = 0; c8_i867 < 6; c8_i867 = c8_i867 + 1) {
    c8_b_u[c8_i867] = (*((real_T (*)[6])c8_u))[c8_i867];
  }

  for (c8_i868 = 0; c8_i868 < 6; c8_i868 = c8_i868 + 1) {
    c8_c_u[c8_i868] = c8_b_u[c8_i868];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_b_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i869;
  real_T c8_b_u[9];
  int32_T c8_i870;
  real_T c8_c_u[9];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  for (c8_i869 = 0; c8_i869 < 9; c8_i869 = c8_i869 + 1) {
    c8_b_u[c8_i869] = (*((real_T (*)[9])c8_u))[c8_i869];
  }

  for (c8_i870 = 0; c8_i870 < 9; c8_i870 = c8_i870 + 1) {
    c8_c_u[c8_i870] = c8_b_u[c8_i870];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_c_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i871;
  int32_T c8_i872;
  int32_T c8_i873;
  real_T c8_b_u[9];
  int32_T c8_i874;
  int32_T c8_i875;
  int32_T c8_i876;
  real_T c8_c_u[9];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_i871 = 0;
  for (c8_i872 = 0; c8_i872 < 3; c8_i872 = c8_i872 + 1) {
    for (c8_i873 = 0; c8_i873 < 3; c8_i873 = c8_i873 + 1) {
      c8_b_u[c8_i873 + c8_i871] = (*((real_T (*)[9])c8_u))[c8_i873 + c8_i871];
    }

    c8_i871 = c8_i871 + 3;
  }

  c8_i874 = 0;
  for (c8_i875 = 0; c8_i875 < 3; c8_i875 = c8_i875 + 1) {
    for (c8_i876 = 0; c8_i876 < 3; c8_i876 = c8_i876 + 1) {
      c8_c_u[c8_i876 + c8_i874] = c8_b_u[c8_i876 + c8_i874];
    }

    c8_i874 = c8_i874 + 3;
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_d_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i877;
  real_T c8_b_u[3];
  int32_T c8_i878;
  real_T c8_c_u[3];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  for (c8_i877 = 0; c8_i877 < 3; c8_i877 = c8_i877 + 1) {
    c8_b_u[c8_i877] = (*((real_T (*)[3])c8_u))[c8_i877];
  }

  for (c8_i878 = 0; c8_i878 < 3; c8_i878 = c8_i878 + 1) {
    c8_c_u[c8_i878] = c8_b_u[c8_i878];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_e_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  real_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_b_u = *((real_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_f_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i879;
  int32_T c8_i880;
  int32_T c8_i881;
  real_T c8_b_u[24];
  int32_T c8_i882;
  int32_T c8_i883;
  int32_T c8_i884;
  real_T c8_c_u[24];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_i879 = 0;
  for (c8_i880 = 0; c8_i880 < 4; c8_i880 = c8_i880 + 1) {
    for (c8_i881 = 0; c8_i881 < 6; c8_i881 = c8_i881 + 1) {
      c8_b_u[c8_i881 + c8_i879] = (*((real_T (*)[24])c8_u))[c8_i881 + c8_i879];
    }

    c8_i879 = c8_i879 + 6;
  }

  c8_i882 = 0;
  for (c8_i883 = 0; c8_i883 < 4; c8_i883 = c8_i883 + 1) {
    for (c8_i884 = 0; c8_i884 < 6; c8_i884 = c8_i884 + 1) {
      c8_c_u[c8_i884 + c8_i882] = c8_b_u[c8_i884 + c8_i882];
    }

    c8_i882 = c8_i882 + 6;
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_g_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i885;
  int32_T c8_i886;
  int32_T c8_i887;
  real_T c8_b_u[16];
  int32_T c8_i888;
  int32_T c8_i889;
  int32_T c8_i890;
  real_T c8_c_u[16];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_i885 = 0;
  for (c8_i886 = 0; c8_i886 < 4; c8_i886 = c8_i886 + 1) {
    for (c8_i887 = 0; c8_i887 < 4; c8_i887 = c8_i887 + 1) {
      c8_b_u[c8_i887 + c8_i885] = (*((real_T (*)[16])c8_u))[c8_i887 + c8_i885];
    }

    c8_i885 = c8_i885 + 4;
  }

  c8_i888 = 0;
  for (c8_i889 = 0; c8_i889 < 4; c8_i889 = c8_i889 + 1) {
    for (c8_i890 = 0; c8_i890 < 4; c8_i890 = c8_i890 + 1) {
      c8_c_u[c8_i890 + c8_i888] = c8_b_u[c8_i890 + c8_i888];
    }

    c8_i888 = c8_i888 + 4;
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_h_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  boolean_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_b_u = *((boolean_T *)c8_u);
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_i_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i891;
  real_T c8_b_u[2];
  int32_T c8_i892;
  real_T c8_c_u[2];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  for (c8_i891 = 0; c8_i891 < 2; c8_i891 = c8_i891 + 1) {
    c8_b_u[c8_i891] = (*((real_T (*)[2])c8_u))[c8_i891];
  }

  for (c8_i892 = 0; c8_i892 < 2; c8_i892 = c8_i892 + 1) {
    c8_c_u[c8_i892] = c8_b_u[c8_i892];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_j_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i893;
  real_T c8_b_u[4];
  int32_T c8_i894;
  real_T c8_c_u[4];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  for (c8_i893 = 0; c8_i893 < 4; c8_i893 = c8_i893 + 1) {
    c8_b_u[c8_i893] = (*((real_T (*)[4])c8_u))[c8_i893];
  }

  for (c8_i894 = 0; c8_i894 < 4; c8_i894 = c8_i894 + 1) {
    c8_c_u[c8_i894] = c8_b_u[c8_i894];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_k_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i895;
  boolean_T c8_b_u[2];
  int32_T c8_i896;
  boolean_T c8_c_u[2];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  for (c8_i895 = 0; c8_i895 < 2; c8_i895 = c8_i895 + 1) {
    c8_b_u[c8_i895] = (*((boolean_T (*)[2])c8_u))[c8_i895];
  }

  for (c8_i896 = 0; c8_i896 < 2; c8_i896 = c8_i896 + 1) {
    c8_c_u[c8_i896] = c8_b_u[c8_i896];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 11, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

static const mxArray *c8_l_sf_marshall(void *chartInstanceVoid, void *c8_u)
{
  const mxArray *c8_y = NULL;
  int32_T c8_i897;
  int32_T c8_i898;
  int32_T c8_i899;
  real_T c8_b_u[4];
  int32_T c8_i900;
  int32_T c8_i901;
  int32_T c8_i902;
  real_T c8_c_u[4];
  const mxArray *c8_b_y = NULL;
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)chartInstanceVoid;
  c8_y = NULL;
  c8_i897 = 0;
  for (c8_i898 = 0; c8_i898 < 2; c8_i898 = c8_i898 + 1) {
    for (c8_i899 = 0; c8_i899 < 2; c8_i899 = c8_i899 + 1) {
      c8_b_u[c8_i899 + c8_i897] = (*((real_T (*)[4])c8_u))[c8_i899 + c8_i897];
    }

    c8_i897 = c8_i897 + 2;
  }

  c8_i900 = 0;
  for (c8_i901 = 0; c8_i901 < 2; c8_i901 = c8_i901 + 1) {
    for (c8_i902 = 0; c8_i902 < 2; c8_i902 = c8_i902 + 1) {
      c8_c_u[c8_i902 + c8_i900] = c8_b_u[c8_i902 + c8_i900];
    }

    c8_i900 = c8_i900 + 2;
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_c_u, 0, 0U, 1U, 0U, 2, 2, 2));
  sf_mex_assign(&c8_y, c8_b_y);
  return c8_y;
}

const mxArray *sf_c8_DynTaskCon_get_eml_resolved_functions_info(void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_ResolvedFunctionInfo c8_info[121];
  const mxArray *c8_m0 = NULL;
  int32_T c8_i903;
  c8_ResolvedFunctionInfo *c8_r0;
  c8_nameCaptureInfo = NULL;
  c8_info_helper(c8_info);
  c8_b_info_helper(c8_info);
  sf_mex_assign(&c8_m0, sf_mex_createstruct("nameCaptureInfo", 1, 121));
  for (c8_i903 = 0; c8_i903 < 121; c8_i903 = c8_i903 + 1) {
    c8_r0 = &c8_info[c8_i903];
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->context)), "context",
                    "nameCaptureInfo", c8_i903);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c8_r0->name)), "name",
                    "nameCaptureInfo", c8_i903);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c8_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c8_i903);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", c8_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c8_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c8_i903);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c8_i903);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c8_i903);
    sf_mex_addfield(c8_m0, sf_mex_create("nameCaptureInfo", &c8_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c8_i903);
  }

  sf_mex_assign(&c8_nameCaptureInfo, c8_m0);
  return c8_nameCaptureInfo;
}

static void c8_info_helper(c8_ResolvedFunctionInfo c8_info[121])
{
  c8_info[0].context = "";
  c8_info[0].name = "inv_kin";
  c8_info[0].dominantType = "double";
  c8_info[0].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[0].fileLength = 2977U;
  c8_info[0].fileTime1 = 1367251992U;
  c8_info[0].fileTime2 = 0U;
  c8_info[1].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[1].name = "zeros";
  c8_info[1].dominantType = "double";
  c8_info[1].resolved = "[B]zeros";
  c8_info[1].fileLength = 0U;
  c8_info[1].fileTime1 = 0U;
  c8_info[1].fileTime2 = 0U;
  c8_info[2].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[2].name = "uminus";
  c8_info[2].dominantType = "double";
  c8_info[2].resolved = "[B]uminus";
  c8_info[2].fileLength = 0U;
  c8_info[2].fileTime1 = 0U;
  c8_info[2].fileTime2 = 0U;
  c8_info[3].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[3].name = "cross";
  c8_info[3].dominantType = "double";
  c8_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[3].fileLength = 3157U;
  c8_info[3].fileTime1 = 1240240462U;
  c8_info[3].fileTime2 = 0U;
  c8_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[4].name = "nargin";
  c8_info[4].dominantType = "";
  c8_info[4].resolved = "[B]nargin";
  c8_info[4].fileLength = 0U;
  c8_info[4].fileTime1 = 0U;
  c8_info[4].fileTime2 = 0U;
  c8_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[5].name = "gt";
  c8_info[5].dominantType = "double";
  c8_info[5].resolved = "[B]gt";
  c8_info[5].fileLength = 0U;
  c8_info[5].fileTime1 = 0U;
  c8_info[5].fileTime2 = 0U;
  c8_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[6].name = "eq";
  c8_info[6].dominantType = "double";
  c8_info[6].resolved = "[B]eq";
  c8_info[6].fileLength = 0U;
  c8_info[6].fileTime1 = 0U;
  c8_info[6].fileTime2 = 0U;
  c8_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[7].name = "isa";
  c8_info[7].dominantType = "double";
  c8_info[7].resolved = "[B]isa";
  c8_info[7].fileLength = 0U;
  c8_info[7].fileTime1 = 0U;
  c8_info[7].fileTime2 = 0U;
  c8_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[8].name = "isvector";
  c8_info[8].dominantType = "double";
  c8_info[8].resolved = "[B]isvector";
  c8_info[8].fileLength = 0U;
  c8_info[8].fileTime1 = 0U;
  c8_info[8].fileTime2 = 0U;
  c8_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[9].name = "mtimes";
  c8_info[9].dominantType = "double";
  c8_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[9].fileLength = 3425U;
  c8_info[9].fileTime1 = 1251010272U;
  c8_info[9].fileTime2 = 0U;
  c8_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[10].name = "isinteger";
  c8_info[10].dominantType = "double";
  c8_info[10].resolved = "[B]isinteger";
  c8_info[10].fileLength = 0U;
  c8_info[10].fileTime1 = 0U;
  c8_info[10].fileTime2 = 0U;
  c8_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[11].name = "isscalar";
  c8_info[11].dominantType = "double";
  c8_info[11].resolved = "[B]isscalar";
  c8_info[11].fileLength = 0U;
  c8_info[11].fileTime1 = 0U;
  c8_info[11].fileTime2 = 0U;
  c8_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[12].name = "strcmp";
  c8_info[12].dominantType = "char";
  c8_info[12].resolved = "[B]strcmp";
  c8_info[12].fileLength = 0U;
  c8_info[12].fileTime1 = 0U;
  c8_info[12].fileTime2 = 0U;
  c8_info[13].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[13].name = "size";
  c8_info[13].dominantType = "double";
  c8_info[13].resolved = "[B]size";
  c8_info[13].fileLength = 0U;
  c8_info[13].fileTime1 = 0U;
  c8_info[13].fileTime2 = 0U;
  c8_info[14].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[14].name = "class";
  c8_info[14].dominantType = "double";
  c8_info[14].resolved = "[B]class";
  c8_info[14].fileLength = 0U;
  c8_info[14].fileTime1 = 0U;
  c8_info[14].fileTime2 = 0U;
  c8_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[15].name = "not";
  c8_info[15].dominantType = "logical";
  c8_info[15].resolved = "[B]not";
  c8_info[15].fileLength = 0U;
  c8_info[15].fileTime1 = 0U;
  c8_info[15].fileTime2 = 0U;
  c8_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c8_info[16].name = "minus";
  c8_info[16].dominantType = "double";
  c8_info[16].resolved = "[B]minus";
  c8_info[16].fileLength = 0U;
  c8_info[16].fileTime1 = 0U;
  c8_info[16].fileTime2 = 0U;
  c8_info[17].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[17].name = "plus";
  c8_info[17].dominantType = "double";
  c8_info[17].resolved = "[B]plus";
  c8_info[17].fileLength = 0U;
  c8_info[17].fileTime1 = 0U;
  c8_info[17].fileTime2 = 0U;
  c8_info[18].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[18].name = "all";
  c8_info[18].dominantType = "logical";
  c8_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c8_info[18].fileLength = 427U;
  c8_info[18].fileTime1 = 1221245538U;
  c8_info[18].fileTime2 = 0U;
  c8_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c8_info[19].name = "ischar";
  c8_info[19].dominantType = "logical";
  c8_info[19].resolved = "[B]ischar";
  c8_info[19].fileLength = 0U;
  c8_info[19].fileTime1 = 0U;
  c8_info[19].fileTime2 = 0U;
  c8_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c8_info[20].name = "islogical";
  c8_info[20].dominantType = "logical";
  c8_info[20].resolved = "[B]islogical";
  c8_info[20].fileLength = 0U;
  c8_info[20].fileTime1 = 0U;
  c8_info[20].fileTime2 = 0U;
  c8_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c8_info[21].name = "lt";
  c8_info[21].dominantType = "double";
  c8_info[21].resolved = "[B]lt";
  c8_info[21].fileLength = 0U;
  c8_info[21].fileTime1 = 0U;
  c8_info[21].fileTime2 = 0U;
  c8_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c8_info[22].name = "eml_all_or_any";
  c8_info[22].dominantType = "char";
  c8_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c8_info[22].fileLength = 3914U;
  c8_info[22].fileTime1 = 1271383994U;
  c8_info[22].fileTime2 = 0U;
  c8_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c8_info[23].name = "isequal";
  c8_info[23].dominantType = "double";
  c8_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[23].fileLength = 180U;
  c8_info[23].fileTime1 = 1226552070U;
  c8_info[23].fileTime2 = 0U;
  c8_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[24].name = "false";
  c8_info[24].dominantType = "";
  c8_info[24].resolved = "[B]false";
  c8_info[24].fileLength = 0U;
  c8_info[24].fileTime1 = 0U;
  c8_info[24].fileTime2 = 0U;
  c8_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c8_info[25].name = "eml_isequal_core";
  c8_info[25].dominantType = "double";
  c8_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[25].fileLength = 4192U;
  c8_info[25].fileTime1 = 1258039010U;
  c8_info[25].fileTime2 = 0U;
  c8_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[26].name = "ge";
  c8_info[26].dominantType = "double";
  c8_info[26].resolved = "[B]ge";
  c8_info[26].fileLength = 0U;
  c8_info[26].fileTime1 = 0U;
  c8_info[26].fileTime2 = 0U;
  c8_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c8_info[27].name = "isnumeric";
  c8_info[27].dominantType = "logical";
  c8_info[27].resolved = "[B]isnumeric";
  c8_info[27].fileLength = 0U;
  c8_info[27].fileTime1 = 0U;
  c8_info[27].fileTime2 = 0U;
  c8_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c8_info[28].name = "ndims";
  c8_info[28].dominantType = "logical";
  c8_info[28].resolved = "[B]ndims";
  c8_info[28].fileLength = 0U;
  c8_info[28].fileTime1 = 0U;
  c8_info[28].fileTime2 = 0U;
  c8_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c8_info[29].name = "ne";
  c8_info[29].dominantType = "double";
  c8_info[29].resolved = "[B]ne";
  c8_info[29].fileLength = 0U;
  c8_info[29].fileTime1 = 0U;
  c8_info[29].fileTime2 = 0U;
  c8_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c8_info[30].name = "true";
  c8_info[30].dominantType = "";
  c8_info[30].resolved = "[B]true";
  c8_info[30].fileLength = 0U;
  c8_info[30].fileTime1 = 0U;
  c8_info[30].fileTime2 = 0U;
  c8_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c8_info[31].name = "eml_const_nonsingleton_dim";
  c8_info[31].dominantType = "logical";
  c8_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c8_info[31].fileLength = 1473U;
  c8_info[31].fileTime1 = 1240240402U;
  c8_info[31].fileTime2 = 0U;
  c8_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c8_info[32].name = "isempty";
  c8_info[32].dominantType = "logical";
  c8_info[32].resolved = "[B]isempty";
  c8_info[32].fileLength = 0U;
  c8_info[32].fileTime1 = 0U;
  c8_info[32].fileTime2 = 0U;
  c8_info[33].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[33].name = "mrdivide";
  c8_info[33].dominantType = "double";
  c8_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[33].fileLength = 432U;
  c8_info[33].fileTime1 = 1277726622U;
  c8_info[33].fileTime2 = 0U;
  c8_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[34].name = "ctranspose";
  c8_info[34].dominantType = "double";
  c8_info[34].resolved = "[B]ctranspose";
  c8_info[34].fileLength = 0U;
  c8_info[34].fileTime1 = 0U;
  c8_info[34].fileTime2 = 0U;
  c8_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[35].name = "mldivide";
  c8_info[35].dominantType = "double";
  c8_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c8_info[35].fileLength = 494U;
  c8_info[35].fileTime1 = 1277726622U;
  c8_info[35].fileTime2 = 0U;
  c8_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c8_info[36].name = "eml_lusolve";
  c8_info[36].dominantType = "double";
  c8_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[36].fileLength = 5239U;
  c8_info[36].fileTime1 = 1264408552U;
  c8_info[36].fileTime2 = 0U;
  c8_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[37].name = "eml_index_class";
  c8_info[37].dominantType = "";
  c8_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c8_info[37].fileLength = 909U;
  c8_info[37].fileTime1 = 1192445182U;
  c8_info[37].fileTime2 = 0U;
  c8_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[38].name = "cast";
  c8_info[38].dominantType = "double";
  c8_info[38].resolved = "[B]cast";
  c8_info[38].fileLength = 0U;
  c8_info[38].fileTime1 = 0U;
  c8_info[38].fileTime2 = 0U;
  c8_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c8_info[39].name = "nargout";
  c8_info[39].dominantType = "";
  c8_info[39].resolved = "[B]nargout";
  c8_info[39].fileLength = 0U;
  c8_info[39].fileTime1 = 0U;
  c8_info[39].fileTime2 = 0U;
  c8_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c8_info[40].name = "ones";
  c8_info[40].dominantType = "char";
  c8_info[40].resolved = "[B]ones";
  c8_info[40].fileLength = 0U;
  c8_info[40].fileTime1 = 0U;
  c8_info[40].fileTime2 = 0U;
  c8_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c8_info[41].name = "eml_xgetrf";
  c8_info[41].dominantType = "int32";
  c8_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c8_info[41].fileLength = 204U;
  c8_info[41].fileTime1 = 1271383994U;
  c8_info[41].fileTime2 = 0U;
  c8_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c8_info[42].name = "eml_lapack_xgetrf";
  c8_info[42].dominantType = "int32";
  c8_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c8_info[42].fileLength = 211U;
  c8_info[42].fileTime1 = 1271383994U;
  c8_info[42].fileTime2 = 0U;
  c8_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c8_info[43].name = "eml_matlab_zgetrf";
  c8_info[43].dominantType = "int32";
  c8_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[43].fileLength = 2193U;
  c8_info[43].fileTime1 = 1271383998U;
  c8_info[43].fileTime2 = 0U;
  c8_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[44].name = "realmin";
  c8_info[44].dominantType = "char";
  c8_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[44].fileLength = 749U;
  c8_info[44].fileTime1 = 1226552078U;
  c8_info[44].fileTime2 = 0U;
  c8_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c8_info[45].name = "mpower";
  c8_info[45].dominantType = "double";
  c8_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[45].fileLength = 3710U;
  c8_info[45].fileTime1 = 1238412688U;
  c8_info[45].fileTime2 = 0U;
  c8_info[46].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c8_info[46].name = "power";
  c8_info[46].dominantType = "double";
  c8_info[46].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[46].fileLength = 5380U;
  c8_info[46].fileTime1 = 1228068698U;
  c8_info[46].fileTime2 = 0U;
  c8_info[47].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[47].name = "eml_scalar_eg";
  c8_info[47].dominantType = "double";
  c8_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[47].fileLength = 3068U;
  c8_info[47].fileTime1 = 1240240410U;
  c8_info[47].fileTime2 = 0U;
  c8_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c8_info[48].name = "isstruct";
  c8_info[48].dominantType = "double";
  c8_info[48].resolved = "[B]isstruct";
  c8_info[48].fileLength = 0U;
  c8_info[48].fileTime1 = 0U;
  c8_info[48].fileTime2 = 0U;
  c8_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!allreal";
  c8_info[49].name = "isreal";
  c8_info[49].dominantType = "double";
  c8_info[49].resolved = "[B]isreal";
  c8_info[49].fileLength = 0U;
  c8_info[49].fileTime1 = 0U;
  c8_info[49].fileTime2 = 0U;
  c8_info[50].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[50].name = "eml_scalexp_alloc";
  c8_info[50].dominantType = "double";
  c8_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c8_info[50].fileLength = 932U;
  c8_info[50].fileTime1 = 1261926670U;
  c8_info[50].fileTime2 = 0U;
  c8_info[51].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[51].name = "eml_scalar_floor";
  c8_info[51].dominantType = "double";
  c8_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c8_info[51].fileLength = 260U;
  c8_info[51].fileTime1 = 1209309190U;
  c8_info[51].fileTime2 = 0U;
  c8_info[52].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c8_info[52].name = "eml_error";
  c8_info[52].dominantType = "char";
  c8_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c8_info[52].fileLength = 315U;
  c8_info[52].fileTime1 = 1213905144U;
  c8_info[52].fileTime2 = 0U;
  c8_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[53].name = "eps";
  c8_info[53].dominantType = "char";
  c8_info[53].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[53].fileLength = 1331U;
  c8_info[53].fileTime1 = 1246588112U;
  c8_info[53].fileTime2 = 0U;
  c8_info[54].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c8_info[54].name = "eml_is_float_class";
  c8_info[54].dominantType = "char";
  c8_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c8_info[54].fileLength = 226U;
  c8_info[54].fileTime1 = 1197825240U;
  c8_info[54].fileTime2 = 0U;
  c8_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[55].name = "min";
  c8_info[55].dominantType = "int32";
  c8_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[55].fileLength = 362U;
  c8_info[55].fileTime1 = 1245080764U;
  c8_info[55].fileTime2 = 0U;
  c8_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[56].name = "le";
  c8_info[56].dominantType = "double";
  c8_info[56].resolved = "[B]le";
  c8_info[56].fileLength = 0U;
  c8_info[56].fileTime1 = 0U;
  c8_info[56].fileTime2 = 0U;
  c8_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c8_info[57].name = "eml_min_or_max";
  c8_info[57].dominantType = "int32";
  c8_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c8_info[57].fileLength = 9967U;
  c8_info[57].fileTime1 = 1261926670U;
  c8_info[57].fileTime2 = 0U;
  c8_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[58].name = "colon";
  c8_info[58].dominantType = "int32";
  c8_info[58].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[58].fileLength = 8633U;
  c8_info[58].fileTime1 = 1273822662U;
  c8_info[58].fileTime2 = 0U;
  c8_info[59].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c8_info[59].name = "floor";
  c8_info[59].dominantType = "double";
  c8_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c8_info[59].fileLength = 332U;
  c8_info[59].fileTime1 = 1203422822U;
  c8_info[59].fileTime2 = 0U;
  c8_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c8_info[60].name = "intmin";
  c8_info[60].dominantType = "char";
  c8_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[60].fileLength = 1505U;
  c8_info[60].fileTime1 = 1192445128U;
  c8_info[60].fileTime2 = 0U;
  c8_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c8_info[61].name = "int32";
  c8_info[61].dominantType = "double";
  c8_info[61].resolved = "[B]int32";
  c8_info[61].fileLength = 0U;
  c8_info[61].fileTime1 = 0U;
  c8_info[61].fileTime2 = 0U;
  c8_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c8_info[62].name = "intmax";
  c8_info[62].dominantType = "char";
  c8_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c8_info[62].fileLength = 1535U;
  c8_info[62].fileTime1 = 1192445128U;
  c8_info[62].fileTime2 = 0U;
  c8_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c8_info[63].name = "double";
  c8_info[63].dominantType = "int32";
  c8_info[63].resolved = "[B]double";
  c8_info[63].fileLength = 0U;
  c8_info[63].fileTime1 = 0U;
  c8_info[63].fileTime2 = 0U;
}

static void c8_b_info_helper(c8_ResolvedFunctionInfo c8_info[121])
{
  c8_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c8_info[64].name = "rdivide";
  c8_info[64].dominantType = "double";
  c8_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[64].fileLength = 403U;
  c8_info[64].fileTime1 = 1245080820U;
  c8_info[64].fileTime2 = 0U;
  c8_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c8_info[65].name = "eml_div";
  c8_info[65].dominantType = "double";
  c8_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c8_info[65].fileLength = 4918U;
  c8_info[65].fileTime1 = 1267038210U;
  c8_info[65].fileTime2 = 0U;
  c8_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c8_info[66].name = "transpose";
  c8_info[66].dominantType = "int32";
  c8_info[66].resolved = "[B]transpose";
  c8_info[66].fileLength = 0U;
  c8_info[66].fileTime1 = 0U;
  c8_info[66].fileTime2 = 0U;
  c8_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[67].name = "eml_index_plus";
  c8_info[67].dominantType = "int32";
  c8_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c8_info[67].fileLength = 272U;
  c8_info[67].fileTime1 = 1192445184U;
  c8_info[67].fileTime2 = 0U;
  c8_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[68].name = "eml_index_minus";
  c8_info[68].dominantType = "int32";
  c8_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c8_info[68].fileLength = 277U;
  c8_info[68].fileTime1 = 1192445184U;
  c8_info[68].fileTime2 = 0U;
  c8_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[69].name = "eml_index_times";
  c8_info[69].dominantType = "int32";
  c8_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c8_info[69].fileLength = 280U;
  c8_info[69].fileTime1 = 1192445186U;
  c8_info[69].fileTime2 = 0U;
  c8_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[70].name = "eml_ixamax";
  c8_info[70].dominantType = "int32";
  c8_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c8_info[70].fileLength = 731U;
  c8_info[70].fileTime1 = 1209309244U;
  c8_info[70].fileTime2 = 0U;
  c8_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c8_info[71].name = "eml_refblas_ixamax";
  c8_info[71].dominantType = "int32";
  c8_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[71].fileLength = 740U;
  c8_info[71].fileTime1 = 1192445266U;
  c8_info[71].fileTime2 = 0U;
  c8_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c8_info[72].name = "eml_xcabs1";
  c8_info[72].dominantType = "double";
  c8_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[72].fileLength = 419U;
  c8_info[72].fileTime1 = 1209309246U;
  c8_info[72].fileTime2 = 0U;
  c8_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[73].name = "real";
  c8_info[73].dominantType = "double";
  c8_info[73].resolved = "[B]real";
  c8_info[73].fileLength = 0U;
  c8_info[73].fileTime1 = 0U;
  c8_info[73].fileTime2 = 0U;
  c8_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[74].name = "abs";
  c8_info[74].dominantType = "double";
  c8_info[74].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[74].fileLength = 566U;
  c8_info[74].fileTime1 = 1221245532U;
  c8_info[74].fileTime2 = 0U;
  c8_info[75].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c8_info[75].name = "eml_scalar_abs";
  c8_info[75].dominantType = "double";
  c8_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c8_info[75].fileLength = 461U;
  c8_info[75].fileTime1 = 1203422760U;
  c8_info[75].fileTime2 = 0U;
  c8_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c8_info[76].name = "imag";
  c8_info[76].dominantType = "double";
  c8_info[76].resolved = "[B]imag";
  c8_info[76].fileLength = 0U;
  c8_info[76].fileTime1 = 0U;
  c8_info[76].fileTime2 = 0U;
  c8_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[77].name = "eml_xswap";
  c8_info[77].dominantType = "int32";
  c8_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c8_info[77].fileLength = 1330U;
  c8_info[77].fileTime1 = 1209309260U;
  c8_info[77].fileTime2 = 0U;
  c8_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c8_info[78].name = "eml_refblas_xswap";
  c8_info[78].dominantType = "int32";
  c8_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c8_info[78].fileLength = 905U;
  c8_info[78].fileTime1 = 1238412670U;
  c8_info[78].fileTime2 = 0U;
  c8_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c8_info[79].name = "eml_xgeru";
  c8_info[79].dominantType = "int32";
  c8_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[79].fileLength = 2462U;
  c8_info[79].fileTime1 = 1209309256U;
  c8_info[79].fileTime2 = 0U;
  c8_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c8_info[80].name = "eml_xger";
  c8_info[80].dominantType = "int32";
  c8_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c8_info[80].fileLength = 2168U;
  c8_info[80].fileTime1 = 1209309254U;
  c8_info[80].fileTime2 = 0U;
  c8_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c8_info[81].name = "eml_refblas_xger";
  c8_info[81].dominantType = "int32";
  c8_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c8_info[81].fileLength = 411U;
  c8_info[81].fileTime1 = 1211194448U;
  c8_info[81].fileTime2 = 0U;
  c8_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c8_info[82].name = "eml_refblas_xgerx";
  c8_info[82].dominantType = "int32";
  c8_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[82].fileLength = 2231U;
  c8_info[82].fileTime1 = 1238412668U;
  c8_info[82].fileTime2 = 0U;
  c8_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c8_info[83].name = "times";
  c8_info[83].dominantType = "double";
  c8_info[83].resolved = "[B]times";
  c8_info[83].fileLength = 0U;
  c8_info[83].fileTime1 = 0U;
  c8_info[83].fileTime2 = 0U;
  c8_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c8_info[84].name = "eml_warning";
  c8_info[84].dominantType = "char";
  c8_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c8_info[84].fileLength = 262U;
  c8_info[84].fileTime1 = 1236232078U;
  c8_info[84].fileTime2 = 0U;
  c8_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c8_info[85].name = "eml_xtrsm";
  c8_info[85].dominantType = "int32";
  c8_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c8_info[85].fileLength = 2383U;
  c8_info[85].fileTime1 = 1209309262U;
  c8_info[85].fileTime2 = 0U;
  c8_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!itcount";
  c8_info[86].name = "length";
  c8_info[86].dominantType = "double";
  c8_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c8_info[86].fileLength = 326U;
  c8_info[86].fileTime1 = 1226552074U;
  c8_info[86].fileTime2 = 0U;
  c8_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c8_info[87].name = "eml_refblas_xtrsm";
  c8_info[87].dominantType = "int32";
  c8_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c8_info[87].fileLength = 13101U;
  c8_info[87].fileTime1 = 1252487206U;
  c8_info[87].fileTime2 = 0U;
  c8_info[88].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[88].name = "eml_xgemm";
  c8_info[88].dominantType = "int32";
  c8_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c8_info[88].fileLength = 3184U;
  c8_info[88].fileTime1 = 1209309252U;
  c8_info[88].fileTime2 = 0U;
  c8_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c8_info[89].name = "eml_refblas_xgemm";
  c8_info[89].dominantType = "int32";
  c8_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c8_info[89].fileLength = 5748U;
  c8_info[89].fileTime1 = 1228068672U;
  c8_info[89].fileTime2 = 0U;
  c8_info[90].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[90].name = "atan2";
  c8_info[90].dominantType = "double";
  c8_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c8_info[90].fileLength = 605U;
  c8_info[90].fileTime1 = 1236232054U;
  c8_info[90].fileTime2 = 0U;
  c8_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c8_info[91].name = "eml_scalar_atan2";
  c8_info[91].dominantType = "double";
  c8_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c8_info[91].fileLength = 964U;
  c8_info[91].fileTime1 = 1209309186U;
  c8_info[91].fileTime2 = 0U;
  c8_info[92].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m!isInRange";
  c8_info[92].name = "pi";
  c8_info[92].dominantType = "";
  c8_info[92].resolved = "[B]pi";
  c8_info[92].fileLength = 0U;
  c8_info[92].fileTime1 = 0U;
  c8_info[92].fileTime2 = 0U;
  c8_info[93].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m!isInRange";
  c8_info[93].name = "and";
  c8_info[93].dominantType = "logical";
  c8_info[93].resolved = "[B]and";
  c8_info[93].fileLength = 0U;
  c8_info[93].fileTime1 = 0U;
  c8_info[93].fileTime2 = 0U;
  c8_info[94].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[94].name = "expWre";
  c8_info[94].dominantType = "double";
  c8_info[94].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/expWre.m";
  c8_info[94].fileLength = 413U;
  c8_info[94].fileTime1 = 1366220272U;
  c8_info[94].fileTime2 = 0U;
  c8_info[95].context = "[E]D:/Learn/MatlabProgram/Fanuc/expWre.m";
  c8_info[95].name = "eye";
  c8_info[95].dominantType = "double";
  c8_info[95].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c8_info[95].fileLength = 1765U;
  c8_info[95].fileTime1 = 1219731288U;
  c8_info[95].fileTime2 = 0U;
  c8_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c8_info[96].name = "eml_assert_valid_size_arg";
  c8_info[96].dominantType = "double";
  c8_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c8_info[96].fileLength = 3315U;
  c8_info[96].fileTime1 = 1256367816U;
  c8_info[96].fileTime2 = 0U;
  c8_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c8_info[97].name = "isinf";
  c8_info[97].dominantType = "double";
  c8_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c8_info[97].fileLength = 541U;
  c8_info[97].fileTime1 = 1271383988U;
  c8_info[97].fileTime2 = 0U;
  c8_info[98].context = "[E]D:/Learn/MatlabProgram/Fanuc/expWre.m";
  c8_info[98].name = "expRot";
  c8_info[98].dominantType = "double";
  c8_info[98].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c8_info[98].fileLength = 236U;
  c8_info[98].fileTime1 = 1366773052U;
  c8_info[98].fileTime2 = 0U;
  c8_info[99].context = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c8_info[99].name = "skew";
  c8_info[99].dominantType = "double";
  c8_info[99].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/skew.m";
  c8_info[99].fileLength = 336U;
  c8_info[99].fileTime1 = 1368990691U;
  c8_info[99].fileTime2 = 0U;
  c8_info[100].context = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c8_info[100].name = "sin";
  c8_info[100].dominantType = "double";
  c8_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[100].fileLength = 324U;
  c8_info[100].fileTime1 = 1203422842U;
  c8_info[100].fileTime2 = 0U;
  c8_info[101].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c8_info[101].name = "eml_scalar_sin";
  c8_info[101].dominantType = "double";
  c8_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c8_info[101].fileLength = 601U;
  c8_info[101].fileTime1 = 1209309190U;
  c8_info[101].fileTime2 = 0U;
  c8_info[102].context = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c8_info[102].name = "cos";
  c8_info[102].dominantType = "double";
  c8_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[102].fileLength = 324U;
  c8_info[102].fileTime1 = 1203422750U;
  c8_info[102].fileTime2 = 0U;
  c8_info[103].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c8_info[103].name = "eml_scalar_cos";
  c8_info[103].dominantType = "double";
  c8_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c8_info[103].fileLength = 602U;
  c8_info[103].fileTime1 = 1209309186U;
  c8_info[103].fileTime2 = 0U;
  c8_info[104].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[104].name = "subPro3";
  c8_info[104].dominantType = "double";
  c8_info[104].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/subPro3.m";
  c8_info[104].fileLength = 1099U;
  c8_info[104].fileTime1 = 1367251936U;
  c8_info[104].fileTime2 = 0U;
  c8_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c8_info[105].name = "eml_xdotu";
  c8_info[105].dominantType = "int32";
  c8_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c8_info[105].fileLength = 1453U;
  c8_info[105].fileTime1 = 1209309250U;
  c8_info[105].fileTime2 = 0U;
  c8_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c8_info[106].name = "eml_xdot";
  c8_info[106].dominantType = "int32";
  c8_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c8_info[106].fileLength = 1330U;
  c8_info[106].fileTime1 = 1209309248U;
  c8_info[106].fileTime2 = 0U;
  c8_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c8_info[107].name = "eml_refblas_xdot";
  c8_info[107].dominantType = "int32";
  c8_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[107].fileLength = 343U;
  c8_info[107].fileTime1 = 1211194442U;
  c8_info[107].fileTime2 = 0U;
  c8_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c8_info[108].name = "eml_refblas_xdotx";
  c8_info[108].dominantType = "int32";
  c8_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c8_info[108].fileLength = 1605U;
  c8_info[108].fileTime1 = 1236232078U;
  c8_info[108].fileTime2 = 0U;
  c8_info[109].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro3.m";
  c8_info[109].name = "norm";
  c8_info[109].dominantType = "double";
  c8_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c8_info[109].fileLength = 5453U;
  c8_info[109].fileTime1 = 1271384008U;
  c8_info[109].fileTime2 = 0U;
  c8_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c8_info[110].name = "eml_xnrm2";
  c8_info[110].dominantType = "int32";
  c8_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c8_info[110].fileLength = 718U;
  c8_info[110].fileTime1 = 1209309256U;
  c8_info[110].fileTime2 = 0U;
  c8_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c8_info[111].name = "eml_refblas_xnrm2";
  c8_info[111].dominantType = "int32";
  c8_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c8_info[111].fileLength = 1433U;
  c8_info[111].fileTime1 = 1240240442U;
  c8_info[111].fileTime2 = 0U;
  c8_info[112].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro3.m";
  c8_info[112].name = "acos";
  c8_info[112].dominantType = "double";
  c8_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c8_info[112].fileLength = 585U;
  c8_info[112].fileTime1 = 1203422730U;
  c8_info[112].fileTime2 = 0U;
  c8_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c8_info[113].name = "eml_scalar_acos";
  c8_info[113].dominantType = "double";
  c8_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  c8_info[113].fileLength = 553U;
  c8_info[113].fileTime1 = 1203422760U;
  c8_info[113].fileTime2 = 0U;
  c8_info[114].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[114].name = "any";
  c8_info[114].dominantType = "logical";
  c8_info[114].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c8_info[114].fileLength = 427U;
  c8_info[114].fileTime1 = 1221245538U;
  c8_info[114].fileTime2 = 0U;
  c8_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c8_info[115].name = "isnan";
  c8_info[115].dominantType = "logical";
  c8_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c8_info[115].fileLength = 541U;
  c8_info[115].fileTime1 = 1271383988U;
  c8_info[115].fileTime2 = 0U;
  c8_info[116].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[116].name = "subPro1";
  c8_info[116].dominantType = "double";
  c8_info[116].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/subPro1.m";
  c8_info[116].fileLength = 393U;
  c8_info[116].fileTime1 = 1336045298U;
  c8_info[116].fileTime2 = 0U;
  c8_info[117].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c8_info[117].name = "subPro2";
  c8_info[117].dominantType = "double";
  c8_info[117].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/subPro2.m";
  c8_info[117].fileLength = 1886U;
  c8_info[117].fileTime1 = 1367255418U;
  c8_info[117].fileTime2 = 0U;
  c8_info[118].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro2.m!findCommon";
  c8_info[118].name = "det";
  c8_info[118].dominantType = "double";
  c8_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c8_info[118].fileLength = 755U;
  c8_info[118].fileTime1 = 1228068678U;
  c8_info[118].fileTime2 = 0U;
  c8_info[119].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro2.m";
  c8_info[119].name = "sqrt";
  c8_info[119].dominantType = "double";
  c8_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[119].fileLength = 572U;
  c8_info[119].fileTime1 = 1203422844U;
  c8_info[119].fileTime2 = 0U;
  c8_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c8_info[120].name = "eml_scalar_sqrt";
  c8_info[120].dominantType = "double";
  c8_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c8_info[120].fileLength = 664U;
  c8_info[120].fileTime1 = 1209309194U;
  c8_info[120].fileTime2 = 0U;
}

static void c8_emlrt_marshallIn(SFc8_DynTaskConInstanceStruct *chartInstance,
  const mxArray *c8_theta, const char_T *c8_name, real_T
  c8_y[6])
{
  real_T c8_dv36[6];
  int32_T c8_i904;
  sf_mex_import(c8_name, sf_mex_dup(c8_theta), c8_dv36, 1, 0, 0U, 1, 0U, 1, 6);
  for (c8_i904 = 0; c8_i904 < 6; c8_i904 = c8_i904 + 1) {
    c8_y[c8_i904] = c8_dv36[c8_i904];
  }

  sf_mex_destroy(&c8_theta);
}

static uint8_T c8_b_emlrt_marshallIn(SFc8_DynTaskConInstanceStruct
  *chartInstance, const mxArray *c8_b_is_active_c8_DynTaskCon,
  const char_T *c8_name)
{
  uint8_T c8_y;
  uint8_T c8_u0;
  sf_mex_import(c8_name, sf_mex_dup(c8_b_is_active_c8_DynTaskCon), &c8_u0, 1, 3,
                0U, 0, 0U, 0);
  c8_y = c8_u0;
  sf_mex_destroy(&c8_b_is_active_c8_DynTaskCon);
  return c8_y;
}

static void init_dsm_address_info(SFc8_DynTaskConInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c8_DynTaskCon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(26272930U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1779455369U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2790961819U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1307763216U);
}

mxArray *sf_c8_DynTaskCon_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3601552445U);
    pr[1] = (double)(3899762000U);
    pr[2] = (double)(2837095841U);
    pr[3] = (double)(1261358445U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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

static mxArray *sf_get_sim_state_info_c8_DynTaskCon(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"theta\",},{M[8],M[0],T\"is_active_c8_DynTaskCon\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_DynTaskCon_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_DynTaskConInstanceStruct *chartInstance;
    chartInstance = (SFc8_DynTaskConInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_DynTaskConMachineNumber_,
           8,
           1,
           1,
           4,
           0,
           0,
           0,
           0,
           7,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_DynTaskConMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_DynTaskConMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_DynTaskConMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EndPos");
          _SFD_SET_DATA_PROPS(1,10,0,0,"init_Rot");
          _SFD_SET_DATA_PROPS(2,2,0,1,"theta");
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

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,173);
        _SFD_CV_INIT_SCRIPT(0,2,8,0,0,2,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"inv_kin",0,-1,2879);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"isInRange",2881,-1,2974);
        _SFD_CV_INIT_SCRIPT_IF(0,0,939,964,1003,1032);
        _SFD_CV_INIT_SCRIPT_IF(0,1,1003,1032,-1,1032);
        _SFD_CV_INIT_SCRIPT_IF(0,2,1348,1382,1597,1701);
        _SFD_CV_INIT_SCRIPT_IF(0,3,1597,1639,-1,-2);
        _SFD_CV_INIT_SCRIPT_IF(0,4,1727,1765,-1,2831);
        _SFD_CV_INIT_SCRIPT_IF(0,5,1889,1923,2249,2377);
        _SFD_CV_INIT_SCRIPT_IF(0,6,2249,2291,-1,-2);
        _SFD_CV_INIT_SCRIPT_IF(0,7,2424,2463,-1,2811);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,1707,1723,2836);
        _SFD_CV_INIT_SCRIPT_FOR(0,1,2395,2412,2823);
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
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"skew",0,-1,336);
        _SFD_CV_INIT_SCRIPT_IF(3,0,27,44,-1,92);
        _SFD_CV_INIT_SCRIPT(4,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"subPro3",0,-1,1098);
        _SFD_CV_INIT_SCRIPT_IF(4,0,995,1006,1029,1085);
        _SFD_CV_INIT_SCRIPT(5,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"subPro1",0,-1,373);
        _SFD_CV_INIT_SCRIPT(6,2,5,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(6,0,"subPro2",0,-1,1337);
        _SFD_CV_INIT_SCRIPT_FCN(6,1,"findCommon",1340,-1,1814);
        _SFD_CV_INIT_SCRIPT_IF(6,0,887,898,921,990);
        _SFD_CV_INIT_SCRIPT_IF(6,1,921,937,960,990);
        _SFD_CV_INIT_SCRIPT_IF(6,2,996,1006,-1,1323);
        _SFD_CV_INIT_SCRIPT_IF(6,3,1468,1482,-1,1619);
        _SFD_CV_INIT_SCRIPT_IF(6,4,1629,1643,-1,1736);
        _SFD_CV_INIT_SCRIPT_FOR(6,0,1011,1022,1315);
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
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_d_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshall);
        }

        {
          real_T (*c8_EndPos)[3];
          real_T (*c8_theta)[6];
          c8_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c8_EndPos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c8_EndPos);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c8_init_Rot);
          _SFD_SET_DATA_VALUE_PTR(2U, *c8_theta);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c8_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_DynTaskConMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c8_DynTaskCon(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc8_DynTaskConInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*)
    chartInstanceVar);
  initialize_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_DynTaskCon(void *chartInstanceVar)
{
  enable_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_DynTaskCon(void *chartInstanceVar)
{
  disable_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_DynTaskCon(void *chartInstanceVar)
{
  sf_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c8_DynTaskCon(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c8_DynTaskCon
    ((SFc8_DynTaskConInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c8_DynTaskCon();/* state var info */
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

static void sf_internal_set_sim_state_c8_DynTaskCon(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c8_DynTaskCon();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c8_DynTaskCon(SimStruct* S)
{
  return sf_internal_get_sim_state_c8_DynTaskCon(S);
}

static void sf_opaque_set_sim_state_c8_DynTaskCon(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c8_DynTaskCon(S, st);
}

static void sf_opaque_terminate_c8_DynTaskCon(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_DynTaskConInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_DynTaskCon(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_DynTaskCon((SFc8_DynTaskConInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c8_DynTaskCon(SimStruct *S)
{
  /* Actual parameters from chart:
     L init_Rot
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for init_Rot*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"DynTaskCon","DynTaskCon",8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DynTaskCon","DynTaskCon",8,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DynTaskCon",
      "DynTaskCon",8,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DynTaskCon","DynTaskCon",8,1);
      sf_mark_chart_reusable_outputs(S,"DynTaskCon","DynTaskCon",8,1);
    }

    sf_set_rtw_dwork_info(S,"DynTaskCon","DynTaskCon",8);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2908238117U));
  ssSetChecksum1(S,(4289096075U));
  ssSetChecksum2(S,(3274942781U));
  ssSetChecksum3(S,(1820885531U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c8_DynTaskCon(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DynTaskCon", "DynTaskCon",8);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_DynTaskCon(SimStruct *S)
{
  SFc8_DynTaskConInstanceStruct *chartInstance;
  chartInstance = (SFc8_DynTaskConInstanceStruct *)malloc(sizeof
    (SFc8_DynTaskConInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc8_DynTaskConInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c8_DynTaskCon;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c8_DynTaskCon;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c8_DynTaskCon;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c8_DynTaskCon;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c8_DynTaskCon;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c8_DynTaskCon;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c8_DynTaskCon;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c8_DynTaskCon;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c8_DynTaskCon;
  chartInstance->chartInfo.mdlStart = mdlStart_c8_DynTaskCon;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c8_DynTaskCon;
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

void c8_DynTaskCon_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_DynTaskCon(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_DynTaskCon(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_DynTaskCon(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_DynTaskCon_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
