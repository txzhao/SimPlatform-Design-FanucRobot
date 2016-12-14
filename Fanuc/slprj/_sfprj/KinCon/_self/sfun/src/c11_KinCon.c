/* Include files */

#include "blascompat32.h"
#include "KinCon_sfun.h"
#include "c11_KinCon.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "KinCon_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c11_debug_family_names[10] = { "gd", "theta_total",
  "num_total", "idx", "nargin", "nargout", "EndPos", "init_Rot", "L", "theta" };

static const char *c11_b_debug_family_names[6] = { "nargin", "nargout", "x",
  "xmin", "xmax", "isIn" };

static const char *c11_c_debug_family_names[4] = { "nargin", "nargout", "w",
  "wh" };

static const char *c11_d_debug_family_names[6] = { "wh", "nargin", "nargout",
  "w", "theta", "R" };

static const char *c11_e_debug_family_names[9] = { "v", "w", "R", "p", "nargin",
  "nargout", "kx", "theta", "g" };

static const char *c11_f_debug_family_names[18] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "dp2", "theta0", "phi", "p", "q", "d", "nargin", "nargout",
  "kx", "theta", "Nsol" };

static const char *c11_g_debug_family_names[6] = { "nargin", "nargout", "x",
  "xmin", "xmax", "isIn" };

static const char *c11_h_debug_family_names[13] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char *c11_i_debug_family_names[10] = { "A", "vec", "cof", "nargin",
  "nargout", "w1", "w2", "r1", "r2", "r" };

static const char *c11_j_debug_family_names[13] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char *c11_k_debug_family_names[13] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char *c11_l_debug_family_names[25] = { "velociy1", "w1", "r1",
  "velociy2", "w2", "r2", "r", "u", "v", "alpha", "beta", "ySqu", "i", "y", "z",
  "c", "nargin", "nargout", "kx1", "kx2", "p", "q", "theta1", "theta2", "Nsol" };

static const char *c11_m_debug_family_names[71] = { "Min1", "Max1", "Min2",
  "Max2", "Min3", "Max3", "Min4", "Max4", "Min5", "Max5", "Min6", "Max6", "L1",
  "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "s_origin", "w_x", "w_y",
  "w_z", "w1", "q1", "kx1", "w2", "q2", "kx2", "w3", "q3", "kx3", "pw", "w4",
  "q4", "kx4", "w5", "q5", "kx5", "w6", "q6", "kx6", "q7", "gst0", "g1", "p1",
  "theta_1", "p2", "d", "theta_3", "Num_3", "c3", "p3", "theta_2", "g2", "p4",
  "theta_4", "theta_5", "Num_45", "c45", "g3", "p5", "theta_6", "nargin",
  "nargout", "gd", "L", "theta", "Num" };

/* Function Declarations */
static void initialize_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance);
static void initialize_params_c11_KinCon(SFc11_KinConInstanceStruct
  *chartInstance);
static void enable_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance);
static void disable_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_KinCon(SFc11_KinConInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c11_KinCon(SFc11_KinConInstanceStruct
  *chartInstance);
static void set_sim_state_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance,
  const mxArray *c11_st);
static void finalize_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance);
static void sf_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance);
static void compInitSubchartSimstructsFcn_c11_KinCon(SFc11_KinConInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static void c11_inv_kin(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_gd[16], real_T c11_b_L[9], real_T c11_theta[24], real_T *c11_Num);
static void c11_cross(SFc11_KinConInstanceStruct *chartInstance, real_T c11_a[3],
                      real_T c11_b[3], real_T c11_c[3]);
static boolean_T c11_all(SFc11_KinConInstanceStruct *chartInstance, boolean_T
  c11_x[2]);
static void c11_mrdivide(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_A[16], real_T c11_B[16], real_T c11_y[16]);
static real_T c11_power(SFc11_KinConInstanceStruct *chartInstance, real_T c11_a,
  real_T c11_b);
static void c11_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance);
static void c11_eps(SFc11_KinConInstanceStruct *chartInstance);
static void c11_eml_matlab_zgetrf(SFc11_KinConInstanceStruct *chartInstance,
  real_T c11_A[16], real_T c11_b_A[16], int32_T c11_ipiv[4], int32_T *c11_info);
static int32_T c11_eml_ixamax(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[16], int32_T c11_ix0);
static int32_T c11_ceval_ixamax(SFc11_KinConInstanceStruct *chartInstance,
  int32_T c11_n, real_T c11_x[16], int32_T c11_ix0, int32_T c11_incx);
static void c11_ceval_xswap(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[16], int32_T c11_ix0, int32_T c11_incx, int32_T c11_iy0,
  int32_T c11_incy, real_T c11_b_x[16]);
static void c11_ceval_xger(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_m, int32_T c11_n, real_T c11_alpha1, int32_T c11_ix0, int32_T c11_incx,
  int32_T c11_iy0, int32_T c11_incy, real_T c11_A[16], int32_T c11_ia0, int32_T
  c11_lda, real_T c11_b_A[16]);
static void c11_eml_warning(SFc11_KinConInstanceStruct *chartInstance);
static void c11_b_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance);
static void c11_c_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance);
static void c11_eml_xtrsm(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_A[16], real_T c11_B[16], real_T c11_b_B[16]);
static void c11_d_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance);
static real_T c11_atan2(SFc11_KinConInstanceStruct *chartInstance, real_T c11_y,
  real_T c11_x);
static boolean_T c11_isInRange(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_x, real_T c11_xmin, real_T c11_xmax);
static void c11_expWre(SFc11_KinConInstanceStruct *chartInstance, real_T c11_kx
  [6], real_T c11_theta, real_T c11_g[16]);
static real_T c11_length(SFc11_KinConInstanceStruct *chartInstance);
static void c11_eye(SFc11_KinConInstanceStruct *chartInstance, real_T c11_I[9]);
static void c11_expRot(SFc11_KinConInstanceStruct *chartInstance, real_T c11_w[3],
  real_T c11_theta, real_T c11_R[9]);
static void c11_e_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance);
static void c11_f_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance);
static void c11_subPro3(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[4], real_T c11_q[4], real_T c11_d[4], real_T
  c11_theta[2], real_T *c11_Nsol);
static void c11_g_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance);
static real_T c11_ceval_xdot(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[3], int32_T c11_ix0, int32_T c11_incx, real_T c11_y[3],
  int32_T c11_iy0, int32_T c11_incy);
static real_T c11_mpower(SFc11_KinConInstanceStruct *chartInstance, real_T c11_a);
static real_T c11_norm(SFc11_KinConInstanceStruct *chartInstance, real_T c11_x[3]);
static real_T c11_ceval_xnrm2(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[3], int32_T c11_ix0, int32_T c11_incx);
static void c11_eml_error(SFc11_KinConInstanceStruct *chartInstance);
static void c11_b_isInRange(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_x[2], real_T c11_xmin, real_T c11_xmax, boolean_T c11_isIn[2]);
static boolean_T c11_any(SFc11_KinConInstanceStruct *chartInstance, boolean_T
  c11_x[2]);
static real_T c11_subPro1(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[4], real_T c11_q[4]);
static void c11_subPro2(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx1[6], real_T c11_kx2[6], real_T c11_p[4], real_T c11_q[4], real_T
  c11_theta1[2], real_T c11_theta2[2], real_T *c11_Nsol);
static void c11_findCommon(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_w1[3], real_T c11_w2[3], real_T c11_r1[3], real_T c11_r2[3], real_T c11_r
  [3]);
static real_T c11_det(SFc11_KinConInstanceStruct *chartInstance, real_T c11_x[4]);
static void c11_b_eml_matlab_zgetrf(SFc11_KinConInstanceStruct *chartInstance,
  real_T c11_A[4], real_T c11_b_A[4], int32_T c11_ipiv[2], int32_T *c11_info);
static int32_T c11_b_eml_ixamax(SFc11_KinConInstanceStruct *chartInstance,
  real_T c11_x[4]);
static int32_T c11_b_ceval_ixamax(SFc11_KinConInstanceStruct *chartInstance,
  int32_T c11_n, real_T c11_x[4], int32_T c11_ix0, int32_T c11_incx);
static void c11_b_ceval_xswap(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[4], int32_T c11_ix0, int32_T c11_incx, int32_T c11_iy0,
  int32_T c11_incy, real_T c11_b_x[4]);
static void c11_b_ceval_xger(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_m, int32_T c11_n, real_T c11_alpha1, int32_T c11_ix0, int32_T c11_incx,
  int32_T c11_iy0, int32_T c11_incy, real_T c11_A[4], int32_T c11_ia0, int32_T
  c11_lda, real_T c11_b_A[4]);
static real_T c11_b_subPro1(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[4], real_T c11_q[3]);
static real_T c11_c_subPro1(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[3], real_T c11_q[4]);
static const mxArray *c11_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_b_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_c_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_d_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_e_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_f_sf_marshall(void *chartInstanceVoid, real_T
  c11_u_data[4], int32_T c11_u_sizes[2]);
static const mxArray *c11_g_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_h_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_i_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_j_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_k_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_l_sf_marshall(void *chartInstanceVoid, void *c11_u);
static const mxArray *c11_m_sf_marshall(void *chartInstanceVoid, void *c11_u);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[123]);
static void c11_b_info_helper(c11_ResolvedFunctionInfo c11_info[123]);
static void c11_emlrt_marshallIn(SFc11_KinConInstanceStruct *chartInstance,
  const mxArray *c11_theta, const char_T *c11_name, real_T c11_y[6]);
static uint8_T c11_b_emlrt_marshallIn(SFc11_KinConInstanceStruct *chartInstance,
  const mxArray *c11_b_is_active_c11_KinCon, const char_T *c11_name);
static void init_dsm_address_info(SFc11_KinConInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_is_active_c11_KinCon = 0U;
}

static void initialize_params_c11_KinCon(SFc11_KinConInstanceStruct
  *chartInstance)
{
  real_T c11_dv0[9];
  int32_T c11_i0;
  real_T c11_dv1[9];
  int32_T c11_i1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'init_Rot' in the parent workspace.\n");
  sf_mex_import("init_Rot", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                c11_dv0, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c11_i0 = 0; c11_i0 < 9; c11_i0 = c11_i0 + 1) {
    chartInstance->c11_init_Rot[c11_i0] = c11_dv0[c11_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c11_dv1, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c11_i1 = 0; c11_i1 < 9; c11_i1 = c11_i1 + 1) {
    chartInstance->c11_L[c11_i1] = c11_dv1[c11_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_KinCon(SFc11_KinConInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c11_KinCon(SFc11_KinConInstanceStruct
  *chartInstance)
{
  const mxArray *c11_st = NULL;
  const mxArray *c11_y = NULL;
  int32_T c11_i2;
  real_T c11_hoistedGlobal[6];
  int32_T c11_i3;
  real_T c11_u[6];
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T (*c11_theta)[6];
  c11_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2));
  for (c11_i2 = 0; c11_i2 < 6; c11_i2 = c11_i2 + 1) {
    c11_hoistedGlobal[c11_i2] = (*c11_theta)[c11_i2];
  }

  for (c11_i3 = 0; c11_i3 < 6; c11_i3 = c11_i3 + 1) {
    c11_u[c11_i3] = c11_hoistedGlobal[c11_i3];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = chartInstance->c11_is_active_c11_KinCon;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y);
  return c11_st;
}

static void set_sim_state_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance,
  const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv2[6];
  int32_T c11_i4;
  real_T (*c11_theta)[6];
  c11_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
                       "theta", c11_dv2);
  for (c11_i4 = 0; c11_i4 < 6; c11_i4 = c11_i4 + 1) {
    (*c11_theta)[c11_i4] = c11_dv2[c11_i4];
  }

  chartInstance->c11_is_active_c11_KinCon = c11_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "is_active_c11_KinCon");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_KinCon(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance)
{
}

static void sf_c11_KinCon(SFc11_KinConInstanceStruct *chartInstance)
{
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_previousEvent;
  int32_T c11_i9;
  real_T c11_hoistedGlobal[3];
  int32_T c11_i10;
  real_T c11_b_hoistedGlobal[9];
  int32_T c11_i11;
  real_T c11_c_hoistedGlobal[9];
  int32_T c11_i12;
  real_T c11_EndPos[3];
  int32_T c11_i13;
  real_T c11_b_init_Rot[9];
  int32_T c11_i14;
  real_T c11_b_L[9];
  uint32_T c11_debug_family_var_map[10];
  static const char *c11_sv0[10] = { "gd", "theta_total", "num_total", "idx",
    "nargin", "nargout", "EndPos", "init_Rot", "L", "theta"
  };

  real_T c11_gd[16];
  real_T c11_theta_total[24];
  real_T c11_num_total;
  int32_T c11_idx_sizes[2];
  real_T c11_idx_data[4];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  real_T c11_theta[6];
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  int32_T c11_i19;
  int32_T c11_i20;
  int32_T c11_i21;
  int32_T c11_i22;
  static real_T c11_dv3[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c11_i23;
  real_T c11_b_gd[16];
  int32_T c11_i24;
  real_T c11_c_L[9];
  real_T c11_b_num_total;
  real_T c11_b_theta_total[24];
  int32_T c11_i25;
  int32_T c11_i26;
  int32_T c11_i27;
  boolean_T c11_x[4];
  real_T c11_idx;
  int32_T c11_i28;
  real_T c11_ii;
  real_T c11_b_ii;
  boolean_T c11_b0;
  boolean_T c11_b1;
  boolean_T c11_b2;
  int32_T c11_i29;
  int32_T c11_tmp_sizes;
  int32_T c11_loop_ub;
  int32_T c11_i30;
  int32_T c11_tmp_data[4];
  int32_T c11_iv0[2];
  int32_T c11_b_idx_sizes[2];
  int32_T c11_b_loop_ub;
  int32_T c11_i31;
  int32_T c11_c_loop_ub;
  int32_T c11_i32;
  real_T c11_b_idx_data[4];
  int32_T c11_d_loop_ub;
  int32_T c11_i33;
  int32_T c11_x_sizes[2];
  int32_T c11_b_x;
  int32_T c11_c_x;
  int32_T c11_e_loop_ub;
  int32_T c11_i34;
  real_T c11_x_data[4];
  int32_T c11_i35;
  real_T c11_s[2];
  real_T c11_n;
  real_T c11_k;
  real_T c11_b_k;
  int32_T c11_i36;
  int32_T c11_b_idx[1];
  int32_T c11_c_idx;
  int32_T c11_i37;
  int32_T c11_i38;
  real_T (*c11_b_theta)[6];
  real_T (*c11_b_EndPos)[3];
  c11_b_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_EndPos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 10);
  for (c11_i5 = 0; c11_i5 < 3; c11_i5 = c11_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_b_EndPos)[c11_i5], 0U);
  }

  for (c11_i6 = 0; c11_i6 < 9; c11_i6 = c11_i6 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_init_Rot[c11_i6], 1U);
  }

  for (c11_i7 = 0; c11_i7 < 6; c11_i7 = c11_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c11_b_theta)[c11_i7], 2U);
  }

  for (c11_i8 = 0; c11_i8 < 9; c11_i8 = c11_i8 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c11_L[c11_i8], 3U);
  }

  c11_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 10);
  for (c11_i9 = 0; c11_i9 < 3; c11_i9 = c11_i9 + 1) {
    c11_hoistedGlobal[c11_i9] = (*c11_b_EndPos)[c11_i9];
  }

  for (c11_i10 = 0; c11_i10 < 9; c11_i10 = c11_i10 + 1) {
    c11_b_hoistedGlobal[c11_i10] = chartInstance->c11_init_Rot[c11_i10];
  }

  for (c11_i11 = 0; c11_i11 < 9; c11_i11 = c11_i11 + 1) {
    c11_c_hoistedGlobal[c11_i11] = chartInstance->c11_L[c11_i11];
  }

  for (c11_i12 = 0; c11_i12 < 3; c11_i12 = c11_i12 + 1) {
    c11_EndPos[c11_i12] = c11_hoistedGlobal[c11_i12];
  }

  for (c11_i13 = 0; c11_i13 < 9; c11_i13 = c11_i13 + 1) {
    c11_b_init_Rot[c11_i13] = c11_b_hoistedGlobal[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 9; c11_i14 = c11_i14 + 1) {
    c11_b_L[c11_i14] = c11_c_hoistedGlobal[c11_i14];
  }

  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c11_sv0, c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_gd, c11_h_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_theta_total, c11_g_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c11_num_total, c11_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml_dyn(c11_idx_data, (const int32_T *)
    &c11_idx_sizes, NULL, 0, (void *)c11_f_sf_marshall, 3);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_EndPos, c11_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c11_b_init_Rot, c11_c_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c11_b_L, c11_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c11_theta, c11_sf_marshall, 9U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c11_i15 = 0; c11_i15 < 6; c11_i15 = c11_i15 + 1) {
    c11_theta[c11_i15] = 0.0;
  }

  _SFD_EML_CALL(0, 4);
  c11_i16 = 0;
  c11_i17 = 0;
  for (c11_i18 = 0; c11_i18 < 3; c11_i18 = c11_i18 + 1) {
    for (c11_i19 = 0; c11_i19 < 3; c11_i19 = c11_i19 + 1) {
      c11_gd[c11_i19 + c11_i16] = c11_b_init_Rot[c11_i19 + c11_i17];
    }

    c11_i16 = c11_i16 + 4;
    c11_i17 = c11_i17 + 3;
  }

  for (c11_i20 = 0; c11_i20 < 3; c11_i20 = c11_i20 + 1) {
    c11_gd[c11_i20 + 12] = c11_EndPos[c11_i20];
  }

  c11_i21 = 0;
  for (c11_i22 = 0; c11_i22 < 4; c11_i22 = c11_i22 + 1) {
    c11_gd[c11_i21 + 3] = c11_dv3[c11_i22];
    c11_i21 = c11_i21 + 4;
  }

  _SFD_EML_CALL(0, 5);
  for (c11_i23 = 0; c11_i23 < 16; c11_i23 = c11_i23 + 1) {
    c11_b_gd[c11_i23] = c11_gd[c11_i23];
  }

  for (c11_i24 = 0; c11_i24 < 9; c11_i24 = c11_i24 + 1) {
    c11_c_L[c11_i24] = c11_b_L[c11_i24];
  }

  c11_inv_kin(chartInstance, c11_b_gd, c11_c_L, c11_b_theta_total,
              &c11_b_num_total);
  for (c11_i25 = 0; c11_i25 < 24; c11_i25 = c11_i25 + 1) {
    c11_theta_total[c11_i25] = c11_b_theta_total[c11_i25];
  }

  c11_num_total = c11_b_num_total;

  /* theta = theta_total(:,2); */
  _SFD_EML_CALL(0, 7);
  c11_i26 = 0;
  for (c11_i27 = 0; c11_i27 < 4; c11_i27 = c11_i27 + 1) {
    c11_x[c11_i27] = (c11_theta_total[c11_i26 + 4] != 0.0);
    c11_i26 = c11_i26 + 6;
  }

  c11_idx = 0.0;
  for (c11_i28 = 0; c11_i28 < 2; c11_i28 = c11_i28 + 1) {
    c11_idx_sizes[c11_i28] = 1 + 3 * c11_i28;
  }

  c11_ii = 1.0;
 label_2:
  ;
  if (c11_ii <= 4.0) {
    c11_b_ii = c11_ii;
    if (c11_x[(int32_T)c11_b_ii - 1]) {
      c11_idx = c11_idx + 1.0;
      c11_idx_data[(int32_T)c11_idx - 1] = c11_b_ii;
      if (c11_idx >= 4.0) {
        goto label_1;
      }
    }
  } else {
    goto label_1;
  }

  c11_ii = c11_ii + 1.0;
  goto label_2;
 label_1:
  ;
  c11_b0 = (1.0 > c11_idx);
  c11_b1 = c11_b0;
  c11_b2 = c11_b1;
  if (c11_b2) {
    c11_i29 = 0;
  } else {
    c11_i29 = _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)c11_idx, 1, 4, 0, 0);
  }

  c11_tmp_sizes = c11_i29;
  c11_loop_ub = c11_i29 - 1;
  for (c11_i30 = 0; c11_i30 <= c11_loop_ub; c11_i30 = c11_i30 + 1) {
    c11_tmp_data[c11_i30] = 1 + c11_i30;
  }

  c11_iv0[0] = 1;
  c11_iv0[1] = c11_tmp_sizes;
  c11_b_idx_sizes[0] = c11_iv0[0];
  c11_b_idx_sizes[1] = c11_iv0[1];
  c11_b_loop_ub = c11_iv0[1] - 1;
  for (c11_i31 = 0; c11_i31 <= c11_b_loop_ub; c11_i31 = c11_i31 + 1) {
    c11_c_loop_ub = c11_iv0[0] - 1;
    for (c11_i32 = 0; c11_i32 <= c11_c_loop_ub; c11_i32 = c11_i32 + 1) {
      c11_b_idx_data[c11_i32 + c11_b_idx_sizes[0] * c11_i31] =
        c11_idx_data[c11_tmp_data[c11_i32 + c11_iv0[0] * c11_i31] - 1];
    }
  }

  c11_idx_sizes[0] = 1;
  c11_idx_sizes[1] = c11_b_idx_sizes[1];
  c11_d_loop_ub = c11_b_idx_sizes[1] - 1;
  for (c11_i33 = 0; c11_i33 <= c11_d_loop_ub; c11_i33 = c11_i33 + 1) {
    c11_idx_data[c11_idx_sizes[0] * c11_i33] = c11_b_idx_data[c11_b_idx_sizes[0]
      * c11_i33];
  }

  _SFD_EML_CALL(0, 8);
  c11_x_sizes[0] = 1;
  c11_x_sizes[1] = c11_idx_sizes[1];
  c11_b_x = c11_x_sizes[0];
  c11_c_x = c11_x_sizes[1];
  c11_e_loop_ub = c11_idx_sizes[0] * c11_idx_sizes[1] - 1;
  for (c11_i34 = 0; c11_i34 <= c11_e_loop_ub; c11_i34 = c11_i34 + 1) {
    c11_x_data[c11_i34] = c11_idx_data[c11_i34];
  }

  for (c11_i35 = 0; c11_i35 < 2; c11_i35 = c11_i35 + 1) {
    c11_s[c11_i35] = (real_T)c11_x_sizes[c11_i35];
  }

  c11_n = 0.0;
  c11_k = 1.0;
 label_3:
  ;
  if (c11_k <= 2.0) {
    c11_b_k = c11_k;
    if (c11_s[(int32_T)c11_b_k - 1] == 0.0) {
      c11_n = 0.0;
    } else {
      if (c11_s[(int32_T)c11_b_k - 1] > c11_n) {
        c11_n = c11_s[(int32_T)c11_b_k - 1];
      }

      c11_k = c11_k + 1.0;
      goto label_3;
    }
  }

  if (CV_EML_IF(0, 0, c11_n == 0.0)) {
    _SFD_EML_CALL(0, 9);
    for (c11_i36 = 0; c11_i36 < 6; c11_i36 = c11_i36 + 1) {
      c11_theta[c11_i36] = c11_theta_total[c11_i36];
    }
  } else {
    _SFD_EML_CALL(0, 12);
    (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("idx", 1, 1, c11_idx_sizes[1], 1, 0);
    c11_b_idx[0] = c11_idx_sizes[1];
    c11_c_idx = (int32_T)c11_idx_data[0] - 1;
    for (c11_i37 = 0; c11_i37 < 6; c11_i37 = c11_i37 + 1) {
      c11_theta[c11_i37] = c11_theta_total[c11_i37 + 6 * c11_c_idx];
    }
  }

  _SFD_EML_CALL(0, -12);
  sf_debug_symbol_scope_pop();
  for (c11_i38 = 0; c11_i38 < 6; c11_i38 = c11_i38 + 1) {
    (*c11_b_theta)[c11_i38] = c11_theta[c11_i38];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10);
  _sfEvent_ = c11_previousEvent;
  sf_debug_check_for_state_inconsistency(_KinConMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c11_KinCon(SFc11_KinConInstanceStruct *
  chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/inv_kin.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 1U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/expWre.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 2U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/expRot.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 3U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/skew.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 4U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/subPro3.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 5U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/subPro1.m"));
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, 6U, sf_debug_get_script_id(
    "D:/Learn/MatlabProgram/Fanuc/subPro2.m"));
}

static void c11_inv_kin(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_gd[16], real_T c11_b_L[9], real_T c11_theta[24],
  real_T *c11_Num)
{
  uint32_T c11_debug_family_var_map[71];
  static const char *c11_sv1[71] = { "Min1", "Max1", "Min2", "Max2", "Min3",
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

  real_T c11_Min1;
  real_T c11_Max1;
  real_T c11_Min2;
  real_T c11_Max2;
  real_T c11_Min3;
  real_T c11_Max3;
  real_T c11_Min4;
  real_T c11_Max4;
  real_T c11_Min5;
  real_T c11_Max5;
  real_T c11_Min6;
  real_T c11_Max6;
  real_T c11_L1;
  real_T c11_L2;
  real_T c11_L3;
  real_T c11_L4;
  real_T c11_L5;
  real_T c11_L6;
  real_T c11_L7;
  real_T c11_L8;
  real_T c11_L9;
  real_T c11_s_origin[3];
  real_T c11_w_x[3];
  real_T c11_w_y[3];
  real_T c11_w_z[3];
  real_T c11_w1[3];
  real_T c11_q1[3];
  real_T c11_kx1[6];
  real_T c11_w2[3];
  real_T c11_q2[3];
  real_T c11_kx2[6];
  real_T c11_w3[3];
  real_T c11_q3[3];
  real_T c11_kx3[6];
  real_T c11_pw[3];
  real_T c11_w4[3];
  real_T c11_q4[3];
  real_T c11_kx4[6];
  real_T c11_w5[3];
  real_T c11_q5[3];
  real_T c11_kx5[6];
  real_T c11_w6[3];
  real_T c11_q6[3];
  real_T c11_kx6[6];
  real_T c11_q7[3];
  real_T c11_gst0[16];
  real_T c11_g1[16];
  real_T c11_p1[4];
  real_T c11_theta_1;
  real_T c11_p2[4];
  real_T c11_d[4];
  real_T c11_theta_3[2];
  real_T c11_Num_3;
  real_T c11_c3;
  real_T c11_p3[4];
  real_T c11_theta_2;
  real_T c11_g2[16];
  real_T c11_p4[4];
  real_T c11_theta_4[2];
  real_T c11_theta_5[2];
  real_T c11_Num_45;
  real_T c11_c45;
  real_T c11_g3[16];
  real_T c11_p5[4];
  real_T c11_theta_6;
  real_T c11_b_q1[4];
  real_T c11_b_q2[4];
  real_T c11_b_q3[4];
  real_T c11_b_q4[4];
  real_T c11_b_q5[4];
  real_T c11_b_q6[4];
  real_T c11_b_q7[4];
  real_T c11_b_pw[4];
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 2.0;
  int32_T c11_i39;
  int32_T c11_i40;
  int32_T c11_i41;
  static real_T c11_dv4[3] = { 1.0, 0.0, 0.0 };

  int32_T c11_i42;
  static real_T c11_dv5[3] = { 0.0, 1.0, 0.0 };

  int32_T c11_i43;
  static real_T c11_dv6[3] = { 0.0, 0.0, 1.0 };

  int32_T c11_i44;
  int32_T c11_i45;
  int32_T c11_i46;
  static real_T c11_dv7[6] = { -0.0, -0.0, -0.0, 0.0, 0.0, 1.0 };

  int32_T c11_i47;
  int32_T c11_i48;
  real_T c11_dv8[3];
  int32_T c11_i49;
  real_T c11_c_q2[3];
  real_T c11_dv9[3];
  int32_T c11_i50;
  int32_T c11_i51;
  int32_T c11_i52;
  int32_T c11_i53;
  real_T c11_dv10[3];
  int32_T c11_i54;
  real_T c11_c_q3[3];
  real_T c11_dv11[3];
  int32_T c11_i55;
  int32_T c11_i56;
  int32_T c11_i57;
  int32_T c11_i58;
  int32_T c11_i59;
  real_T c11_dv12[3];
  int32_T c11_i60;
  real_T c11_c_q4[3];
  real_T c11_dv13[3];
  int32_T c11_i61;
  int32_T c11_i62;
  int32_T c11_i63;
  int32_T c11_i64;
  int32_T c11_i65;
  real_T c11_dv14[3];
  int32_T c11_i66;
  real_T c11_c_q5[3];
  real_T c11_dv15[3];
  int32_T c11_i67;
  int32_T c11_i68;
  int32_T c11_i69;
  int32_T c11_i70;
  int32_T c11_i71;
  real_T c11_dv16[3];
  int32_T c11_i72;
  real_T c11_c_q6[3];
  real_T c11_dv17[3];
  int32_T c11_i73;
  int32_T c11_i74;
  int32_T c11_i75;
  int32_T c11_i76;
  int32_T c11_i77;
  int32_T c11_i78;
  int32_T c11_i79;
  int32_T c11_i80;
  int32_T c11_i81;
  int32_T c11_i82;
  int32_T c11_i83;
  int32_T c11_i84;
  static real_T c11_dv18[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c11_i85;
  boolean_T c11_bv0[2];
  int32_T c11_i86;
  real_T c11_b_gd[16];
  int32_T c11_i87;
  real_T c11_b_gst0[16];
  real_T c11_dv19[16];
  int32_T c11_i88;
  int32_T c11_i89;
  real_T c11_a[16];
  int32_T c11_i90;
  real_T c11_b[4];
  int32_T c11_i91;
  real_T c11_A[16];
  int32_T c11_i92;
  real_T c11_B[4];
  int32_T c11_i93;
  int32_T c11_i94;
  real_T c11_b_A[16];
  int32_T c11_i95;
  real_T c11_b_B[4];
  int32_T c11_i96;
  real_T c11_c_A[16];
  int32_T c11_i97;
  real_T c11_c_B[4];
  int32_T c11_i98;
  int32_T c11_i99;
  int32_T c11_i100;
  int32_T c11_i101;
  static real_T c11_dv20[6] = { 0.0, 0.0, 0.0, -0.0, -0.0, -1.0 };

  real_T c11_dv21[6];
  real_T c11_b_a[16];
  int32_T c11_i102;
  real_T c11_b_b[4];
  int32_T c11_i103;
  real_T c11_d_A[16];
  int32_T c11_i104;
  real_T c11_d_B[4];
  int32_T c11_i105;
  int32_T c11_i106;
  real_T c11_e_A[16];
  int32_T c11_i107;
  real_T c11_e_B[4];
  int32_T c11_i108;
  real_T c11_f_A[16];
  int32_T c11_i109;
  real_T c11_f_B[4];
  int32_T c11_i110;
  int32_T c11_i111;
  int32_T c11_i112;
  int32_T c11_i113;
  int32_T c11_i114;
  real_T c11_b_kx3[6];
  int32_T c11_i115;
  real_T c11_c_pw[4];
  int32_T c11_i116;
  real_T c11_d_q2[4];
  int32_T c11_i117;
  real_T c11_b_d[4];
  real_T c11_b_Num_3;
  real_T c11_b_theta_3[2];
  int32_T c11_i118;
  int32_T c11_i119;
  real_T c11_c_theta_3[2];
  boolean_T c11_bv1[2];
  int32_T c11_i120;
  boolean_T c11_bv2[2];
  real_T c11_b_c3;
  int32_T c11_i121;
  real_T c11_c_kx3[6];
  real_T c11_c_a[16];
  int32_T c11_i122;
  real_T c11_c_b[4];
  int32_T c11_i123;
  real_T c11_g_A[16];
  int32_T c11_i124;
  real_T c11_g_B[4];
  int32_T c11_i125;
  int32_T c11_i126;
  real_T c11_h_A[16];
  int32_T c11_i127;
  real_T c11_h_B[4];
  int32_T c11_i128;
  real_T c11_i_A[16];
  int32_T c11_i129;
  real_T c11_i_B[4];
  int32_T c11_i130;
  int32_T c11_i131;
  int32_T c11_i132;
  int32_T c11_i133;
  real_T c11_b_kx2[6];
  int32_T c11_i134;
  real_T c11_b_p3[4];
  int32_T c11_i135;
  real_T c11_b_p2[4];
  int32_T c11_i136;
  real_T c11_d_kx3[6];
  real_T c11_d_a[16];
  int32_T c11_i137;
  real_T c11_c_kx2[6];
  real_T c11_d_b[16];
  int32_T c11_i138;
  real_T c11_j_A[16];
  int32_T c11_i139;
  real_T c11_j_B[16];
  int32_T c11_i140;
  real_T c11_k_A[16];
  int32_T c11_i141;
  real_T c11_k_B[16];
  int32_T c11_i142;
  real_T c11_l_A[16];
  int32_T c11_i143;
  real_T c11_l_B[16];
  int32_T c11_i144;
  int32_T c11_i145;
  int32_T c11_i146;
  real_T c11_y[16];
  int32_T c11_i147;
  int32_T c11_i148;
  int32_T c11_i149;
  real_T c11_e_a[16];
  int32_T c11_i150;
  real_T c11_dv22[6];
  real_T c11_e_b[16];
  int32_T c11_i151;
  real_T c11_m_A[16];
  int32_T c11_i152;
  real_T c11_m_B[16];
  int32_T c11_i153;
  real_T c11_n_A[16];
  int32_T c11_i154;
  real_T c11_n_B[16];
  int32_T c11_i155;
  real_T c11_o_A[16];
  int32_T c11_i156;
  real_T c11_o_B[16];
  int32_T c11_i157;
  int32_T c11_i158;
  int32_T c11_i159;
  real_T c11_b_y[16];
  int32_T c11_i160;
  int32_T c11_i161;
  int32_T c11_i162;
  real_T c11_f_a[16];
  int32_T c11_i163;
  real_T c11_f_b[16];
  int32_T c11_i164;
  real_T c11_p_A[16];
  int32_T c11_i165;
  real_T c11_p_B[16];
  int32_T c11_i166;
  int32_T c11_i167;
  real_T c11_q_A[16];
  int32_T c11_i168;
  real_T c11_q_B[16];
  int32_T c11_i169;
  real_T c11_r_A[16];
  int32_T c11_i170;
  real_T c11_r_B[16];
  int32_T c11_i171;
  int32_T c11_i172;
  int32_T c11_i173;
  int32_T c11_i174;
  int32_T c11_i175;
  int32_T c11_i176;
  real_T c11_g_a[16];
  int32_T c11_i177;
  real_T c11_g_b[4];
  int32_T c11_i178;
  real_T c11_s_A[16];
  int32_T c11_i179;
  real_T c11_s_B[4];
  int32_T c11_i180;
  int32_T c11_i181;
  real_T c11_t_A[16];
  int32_T c11_i182;
  real_T c11_t_B[4];
  int32_T c11_i183;
  real_T c11_u_A[16];
  int32_T c11_i184;
  real_T c11_u_B[4];
  int32_T c11_i185;
  int32_T c11_i186;
  int32_T c11_i187;
  int32_T c11_i188;
  real_T c11_b_kx4[6];
  int32_T c11_i189;
  real_T c11_b_kx5[6];
  int32_T c11_i190;
  real_T c11_c_q7[4];
  int32_T c11_i191;
  real_T c11_b_p4[4];
  real_T c11_b_Num_45;
  real_T c11_b_theta_5[2];
  real_T c11_b_theta_4[2];
  int32_T c11_i192;
  int32_T c11_i193;
  int32_T c11_i194;
  real_T c11_c_theta_5[2];
  boolean_T c11_bv3[2];
  int32_T c11_i195;
  boolean_T c11_bv4[2];
  real_T c11_b_c45;
  int32_T c11_i196;
  real_T c11_c_kx5[6];
  real_T c11_h_a[16];
  int32_T c11_i197;
  real_T c11_c_kx4[6];
  real_T c11_h_b[16];
  int32_T c11_i198;
  real_T c11_v_A[16];
  int32_T c11_i199;
  real_T c11_v_B[16];
  int32_T c11_i200;
  real_T c11_w_A[16];
  int32_T c11_i201;
  real_T c11_w_B[16];
  int32_T c11_i202;
  real_T c11_x_A[16];
  int32_T c11_i203;
  real_T c11_x_B[16];
  int32_T c11_i204;
  int32_T c11_i205;
  int32_T c11_i206;
  real_T c11_c_y[16];
  int32_T c11_i207;
  int32_T c11_i208;
  int32_T c11_i209;
  real_T c11_i_a[16];
  int32_T c11_i210;
  real_T c11_i_b[16];
  int32_T c11_i211;
  real_T c11_y_A[16];
  int32_T c11_i212;
  real_T c11_y_B[16];
  int32_T c11_i213;
  int32_T c11_i214;
  real_T c11_ab_A[16];
  int32_T c11_i215;
  real_T c11_ab_B[16];
  int32_T c11_i216;
  real_T c11_bb_A[16];
  int32_T c11_i217;
  real_T c11_bb_B[16];
  int32_T c11_i218;
  int32_T c11_i219;
  int32_T c11_i220;
  int32_T c11_i221;
  int32_T c11_i222;
  int32_T c11_i223;
  real_T c11_j_a[16];
  int32_T c11_i224;
  real_T c11_j_b[4];
  int32_T c11_i225;
  real_T c11_cb_A[16];
  int32_T c11_i226;
  real_T c11_cb_B[4];
  int32_T c11_i227;
  int32_T c11_i228;
  real_T c11_db_A[16];
  int32_T c11_i229;
  real_T c11_db_B[4];
  int32_T c11_i230;
  real_T c11_eb_A[16];
  int32_T c11_i231;
  real_T c11_eb_B[4];
  int32_T c11_i232;
  int32_T c11_i233;
  int32_T c11_i234;
  int32_T c11_i235;
  real_T c11_b_kx6[6];
  int32_T c11_i236;
  real_T c11_d_q3[4];
  int32_T c11_i237;
  real_T c11_b_p5[4];
  int32_T c11_b_Num;
  real_T c11_b_theta_1[6];
  int32_T c11_i238;
  sf_debug_symbol_scope_push_eml(0U, 71U, 79U, c11_sv1, c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c11_Min1, c11_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c11_Max1, c11_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c11_Min2, c11_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c11_Max2, c11_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_Min3, c11_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c11_Max3, c11_e_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c11_Min4, c11_e_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_Max4, c11_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c11_Min5, c11_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c11_Max5, c11_e_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c11_Min6, c11_e_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c11_Max6, c11_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c11_L1, c11_e_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c11_L2, c11_e_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c11_L3, c11_e_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c11_L4, c11_e_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c11_L5, c11_e_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c11_L6, c11_e_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c11_L7, c11_e_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c11_L8, c11_e_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c11_L9, c11_e_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(c11_s_origin, c11_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(c11_w_x, c11_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(c11_w_y, c11_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(c11_w_z, c11_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(c11_w1, c11_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(c11_q1, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_kx1, c11_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(c11_w2, c11_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(c11_q2, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_kx2, c11_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(c11_w3, c11_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(c11_q3, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_kx3, c11_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(c11_pw, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_w4, c11_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(c11_q4, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_kx4, c11_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(c11_w5, c11_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(c11_q5, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_kx5, c11_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(c11_w6, c11_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(c11_q6, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_kx6, c11_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(c11_q7, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_gst0, c11_h_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(c11_g1, c11_h_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(c11_p1, c11_k_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c11_theta_1, c11_e_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(c11_p2, c11_k_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(c11_d, c11_k_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(c11_theta_3, c11_j_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c11_Num_3, c11_e_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c11_c3, c11_e_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(c11_p3, c11_k_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c11_theta_2, c11_e_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(c11_g2, c11_h_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(c11_p4, c11_k_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(c11_theta_4, c11_j_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(c11_theta_5, c11_j_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c11_Num_45, c11_e_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c11_c45, c11_e_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(c11_g3, c11_h_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(c11_p5, c11_k_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c11_theta_6, c11_e_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c11_b_q1, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_q2, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_q3, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_q4, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_q5, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_q6, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_q7, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_pw, c11_k_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(c11_gd, c11_h_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(c11_b_L, c11_b_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(c11_theta, c11_g_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(c11_Num, c11_e_sf_marshall, 70U);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0, 2);
  for (c11_i39 = 0; c11_i39 < 24; c11_i39 = c11_i39 + 1) {
    c11_theta[c11_i39] = 0.0;
  }

  /*  at most 4 pairs of solution */
  _SFD_SCRIPT_CALL(0, 3);
  *c11_Num = 0.0;
  _SFD_SCRIPT_CALL(0, 5);
  c11_Min1 = -165.0;
  _SFD_SCRIPT_CALL(0, 5);
  c11_Max1 = 165.0;
  _SFD_SCRIPT_CALL(0, 6);
  c11_Min2 = -150.0;
  _SFD_SCRIPT_CALL(0, 6);
  c11_Max2 = 60.0;
  _SFD_SCRIPT_CALL(0, 7);
  c11_Min3 = -210.0;
  _SFD_SCRIPT_CALL(0, 7);
  c11_Max3 = 90.0;
  _SFD_SCRIPT_CALL(0, 8);
  c11_Min4 = -180.0;
  _SFD_SCRIPT_CALL(0, 8);
  c11_Max4 = 180.0;
  _SFD_SCRIPT_CALL(0, 9);
  c11_Min5 = -140.0;
  _SFD_SCRIPT_CALL(0, 9);
  c11_Max5 = 140.0;
  _SFD_SCRIPT_CALL(0, 10);
  c11_Min6 = -180.0;
  _SFD_SCRIPT_CALL(0, 10);
  c11_Max6 = 180.0;
  _SFD_SCRIPT_CALL(0, 12);
  c11_L1 = c11_b_L[0];
  _SFD_SCRIPT_CALL(0, 13);
  c11_L2 = c11_b_L[1];
  _SFD_SCRIPT_CALL(0, 14);
  c11_L3 = c11_b_L[2];
  _SFD_SCRIPT_CALL(0, 15);
  c11_L4 = c11_b_L[3];
  _SFD_SCRIPT_CALL(0, 16);
  c11_L5 = c11_b_L[4];
  _SFD_SCRIPT_CALL(0, 17);
  c11_L6 = c11_b_L[5];
  _SFD_SCRIPT_CALL(0, 18);
  c11_L7 = c11_b_L[6];
  _SFD_SCRIPT_CALL(0, 19);
  c11_L8 = c11_b_L[7];
  _SFD_SCRIPT_CALL(0, 20);
  c11_L9 = c11_b_L[8];
  _SFD_SCRIPT_CALL(0, 22);
  for (c11_i40 = 0; c11_i40 < 3; c11_i40 = c11_i40 + 1) {
    c11_s_origin[c11_i40] = 0.0;
  }

  _SFD_SCRIPT_CALL(0, 23);
  for (c11_i41 = 0; c11_i41 < 3; c11_i41 = c11_i41 + 1) {
    c11_w_x[c11_i41] = c11_dv4[c11_i41];
  }

  _SFD_SCRIPT_CALL(0, 24);
  for (c11_i42 = 0; c11_i42 < 3; c11_i42 = c11_i42 + 1) {
    c11_w_y[c11_i42] = c11_dv5[c11_i42];
  }

  _SFD_SCRIPT_CALL(0, 25);
  for (c11_i43 = 0; c11_i43 < 3; c11_i43 = c11_i43 + 1) {
    c11_w_z[c11_i43] = c11_dv6[c11_i43];
  }

  _SFD_SCRIPT_CALL(0, 27);
  for (c11_i44 = 0; c11_i44 < 3; c11_i44 = c11_i44 + 1) {
    c11_w1[c11_i44] = c11_dv6[c11_i44];
  }

  _SFD_SCRIPT_CALL(0, 28);
  for (c11_i45 = 0; c11_i45 < 3; c11_i45 = c11_i45 + 1) {
    c11_q1[c11_i45] = 0.0;
  }

  sf_debug_symbol_switch(26U, 26U);
  _SFD_SCRIPT_CALL(0, 29);
  for (c11_i46 = 0; c11_i46 < 6; c11_i46 = c11_i46 + 1) {
    c11_kx1[c11_i46] = c11_dv7[c11_i46];
  }

  _SFD_SCRIPT_CALL(0, 31);
  for (c11_i47 = 0; c11_i47 < 3; c11_i47 = c11_i47 + 1) {
    c11_w2[c11_i47] = c11_dv5[c11_i47];
  }

  _SFD_SCRIPT_CALL(0, 32);
  c11_q2[0] = c11_L2;
  c11_q2[1] = 0.0;
  c11_q2[2] = c11_L1;
  sf_debug_symbol_switch(29U, 29U);
  _SFD_SCRIPT_CALL(0, 33);
  for (c11_i48 = 0; c11_i48 < 3; c11_i48 = c11_i48 + 1) {
    c11_dv8[c11_i48] = c11_dv5[c11_i48];
  }

  for (c11_i49 = 0; c11_i49 < 3; c11_i49 = c11_i49 + 1) {
    c11_c_q2[c11_i49] = c11_q2[c11_i49];
  }

  c11_cross(chartInstance, c11_dv8, c11_c_q2, c11_dv9);
  for (c11_i50 = 0; c11_i50 < 3; c11_i50 = c11_i50 + 1) {
    c11_kx2[c11_i50] = -c11_dv9[c11_i50];
  }

  for (c11_i51 = 0; c11_i51 < 3; c11_i51 = c11_i51 + 1) {
    c11_kx2[c11_i51 + 3] = c11_w2[c11_i51];
  }

  _SFD_SCRIPT_CALL(0, 35);
  for (c11_i52 = 0; c11_i52 < 3; c11_i52 = c11_i52 + 1) {
    c11_w3[c11_i52] = c11_dv5[c11_i52];
  }

  _SFD_SCRIPT_CALL(0, 36);
  c11_q3[0] = c11_L2;
  c11_q3[1] = 0.0;
  c11_q3[2] = c11_L1 + c11_L3;
  sf_debug_symbol_switch(32U, 32U);
  _SFD_SCRIPT_CALL(0, 37);
  for (c11_i53 = 0; c11_i53 < 3; c11_i53 = c11_i53 + 1) {
    c11_dv10[c11_i53] = c11_dv5[c11_i53];
  }

  for (c11_i54 = 0; c11_i54 < 3; c11_i54 = c11_i54 + 1) {
    c11_c_q3[c11_i54] = c11_q3[c11_i54];
  }

  c11_cross(chartInstance, c11_dv10, c11_c_q3, c11_dv11);
  for (c11_i55 = 0; c11_i55 < 3; c11_i55 = c11_i55 + 1) {
    c11_kx3[c11_i55] = -c11_dv11[c11_i55];
  }

  for (c11_i56 = 0; c11_i56 < 3; c11_i56 = c11_i56 + 1) {
    c11_kx3[c11_i56 + 3] = c11_w3[c11_i56];
  }

  _SFD_SCRIPT_CALL(0, 39);
  c11_pw[0] = c11_L2 + c11_L5;
  c11_pw[1] = 0.0;
  c11_pw[2] = (c11_L1 + c11_L3) + c11_L4;
  sf_debug_symbol_switch(34U, 34U);
  _SFD_SCRIPT_CALL(0, 41);
  for (c11_i57 = 0; c11_i57 < 3; c11_i57 = c11_i57 + 1) {
    c11_w4[c11_i57] = c11_dv4[c11_i57];
  }

  _SFD_SCRIPT_CALL(0, 42);
  for (c11_i58 = 0; c11_i58 < 3; c11_i58 = c11_i58 + 1) {
    c11_q4[c11_i58] = c11_pw[c11_i58];
  }

  sf_debug_symbol_switch(36U, 36U);
  _SFD_SCRIPT_CALL(0, 43);
  for (c11_i59 = 0; c11_i59 < 3; c11_i59 = c11_i59 + 1) {
    c11_dv12[c11_i59] = c11_dv4[c11_i59];
  }

  for (c11_i60 = 0; c11_i60 < 3; c11_i60 = c11_i60 + 1) {
    c11_c_q4[c11_i60] = c11_q4[c11_i60];
  }

  c11_cross(chartInstance, c11_dv12, c11_c_q4, c11_dv13);
  for (c11_i61 = 0; c11_i61 < 3; c11_i61 = c11_i61 + 1) {
    c11_kx4[c11_i61] = -c11_dv13[c11_i61];
  }

  for (c11_i62 = 0; c11_i62 < 3; c11_i62 = c11_i62 + 1) {
    c11_kx4[c11_i62 + 3] = c11_w4[c11_i62];
  }

  _SFD_SCRIPT_CALL(0, 45);
  for (c11_i63 = 0; c11_i63 < 3; c11_i63 = c11_i63 + 1) {
    c11_w5[c11_i63] = c11_dv5[c11_i63];
  }

  _SFD_SCRIPT_CALL(0, 46);
  for (c11_i64 = 0; c11_i64 < 3; c11_i64 = c11_i64 + 1) {
    c11_q5[c11_i64] = c11_pw[c11_i64];
  }

  sf_debug_symbol_switch(39U, 39U);
  _SFD_SCRIPT_CALL(0, 47);
  for (c11_i65 = 0; c11_i65 < 3; c11_i65 = c11_i65 + 1) {
    c11_dv14[c11_i65] = c11_dv5[c11_i65];
  }

  for (c11_i66 = 0; c11_i66 < 3; c11_i66 = c11_i66 + 1) {
    c11_c_q5[c11_i66] = c11_q5[c11_i66];
  }

  c11_cross(chartInstance, c11_dv14, c11_c_q5, c11_dv15);
  for (c11_i67 = 0; c11_i67 < 3; c11_i67 = c11_i67 + 1) {
    c11_kx5[c11_i67] = -c11_dv15[c11_i67];
  }

  for (c11_i68 = 0; c11_i68 < 3; c11_i68 = c11_i68 + 1) {
    c11_kx5[c11_i68 + 3] = c11_w5[c11_i68];
  }

  _SFD_SCRIPT_CALL(0, 49);
  for (c11_i69 = 0; c11_i69 < 3; c11_i69 = c11_i69 + 1) {
    c11_w6[c11_i69] = c11_dv4[c11_i69];
  }

  _SFD_SCRIPT_CALL(0, 50);
  for (c11_i70 = 0; c11_i70 < 3; c11_i70 = c11_i70 + 1) {
    c11_q6[c11_i70] = c11_pw[c11_i70];
  }

  sf_debug_symbol_switch(42U, 42U);
  _SFD_SCRIPT_CALL(0, 51);
  for (c11_i71 = 0; c11_i71 < 3; c11_i71 = c11_i71 + 1) {
    c11_dv16[c11_i71] = c11_dv4[c11_i71];
  }

  for (c11_i72 = 0; c11_i72 < 3; c11_i72 = c11_i72 + 1) {
    c11_c_q6[c11_i72] = c11_q6[c11_i72];
  }

  c11_cross(chartInstance, c11_dv16, c11_c_q6, c11_dv17);
  for (c11_i73 = 0; c11_i73 < 3; c11_i73 = c11_i73 + 1) {
    c11_kx6[c11_i73] = -c11_dv17[c11_i73];
  }

  for (c11_i74 = 0; c11_i74 < 3; c11_i74 = c11_i74 + 1) {
    c11_kx6[c11_i74 + 3] = c11_w6[c11_i74];
  }

  _SFD_SCRIPT_CALL(0, 53);
  c11_q7[0] = (c11_L2 + c11_L5) + c11_L6;
  c11_q7[1] = 0.0;
  c11_q7[2] = (c11_L1 + c11_L3) + c11_L4;
  sf_debug_symbol_switch(44U, 44U);
  _SFD_SCRIPT_CALL(0, 55);
  for (c11_i75 = 0; c11_i75 < 3; c11_i75 = c11_i75 + 1) {
    c11_b_q1[c11_i75] = c11_q1[c11_i75];
  }

  c11_b_q1[3] = 1.0;
  sf_debug_symbol_switch(26U, 65U);
  _SFD_SCRIPT_CALL(0, 56);
  for (c11_i76 = 0; c11_i76 < 3; c11_i76 = c11_i76 + 1) {
    c11_b_q2[c11_i76] = c11_q2[c11_i76];
  }

  c11_b_q2[3] = 1.0;
  sf_debug_symbol_switch(29U, 66U);
  _SFD_SCRIPT_CALL(0, 57);
  for (c11_i77 = 0; c11_i77 < 3; c11_i77 = c11_i77 + 1) {
    c11_b_q3[c11_i77] = c11_q3[c11_i77];
  }

  c11_b_q3[3] = 1.0;
  sf_debug_symbol_switch(32U, 67U);
  _SFD_SCRIPT_CALL(0, 58);
  for (c11_i78 = 0; c11_i78 < 3; c11_i78 = c11_i78 + 1) {
    c11_b_q4[c11_i78] = c11_q4[c11_i78];
  }

  c11_b_q4[3] = 1.0;
  sf_debug_symbol_switch(36U, 68U);
  _SFD_SCRIPT_CALL(0, 59);
  for (c11_i79 = 0; c11_i79 < 3; c11_i79 = c11_i79 + 1) {
    c11_b_q5[c11_i79] = c11_q5[c11_i79];
  }

  c11_b_q5[3] = 1.0;
  sf_debug_symbol_switch(39U, 69U);
  _SFD_SCRIPT_CALL(0, 60);
  for (c11_i80 = 0; c11_i80 < 3; c11_i80 = c11_i80 + 1) {
    c11_b_q6[c11_i80] = c11_q6[c11_i80];
  }

  c11_b_q6[3] = 1.0;
  sf_debug_symbol_switch(42U, 70U);
  _SFD_SCRIPT_CALL(0, 61);
  for (c11_i81 = 0; c11_i81 < 3; c11_i81 = c11_i81 + 1) {
    c11_b_q7[c11_i81] = c11_q7[c11_i81];
  }

  c11_b_q7[3] = 1.0;
  sf_debug_symbol_switch(44U, 71U);
  _SFD_SCRIPT_CALL(0, 62);
  for (c11_i82 = 0; c11_i82 < 3; c11_i82 = c11_i82 + 1) {
    c11_b_pw[c11_i82] = c11_pw[c11_i82];
  }

  c11_b_pw[3] = 1.0;
  sf_debug_symbol_switch(34U, 72U);
  _SFD_SCRIPT_CALL(0, 65);
  c11_gst0[0] = 1.0;
  c11_gst0[4] = 0.0;
  c11_gst0[8] = 0.0;
  c11_gst0[12] = ((c11_L2 + c11_L5) + c11_L6) + c11_L7;
  c11_gst0[1] = 0.0;
  c11_gst0[5] = 1.0;
  c11_gst0[9] = 0.0;
  c11_gst0[13] = c11_L8;
  c11_gst0[2] = 0.0;
  c11_gst0[6] = 0.0;
  c11_gst0[10] = 1.0;
  c11_gst0[14] = ((c11_L1 + c11_L3) + c11_L4) + c11_L9;
  c11_i83 = 0;
  for (c11_i84 = 0; c11_i84 < 4; c11_i84 = c11_i84 + 1) {
    c11_gst0[c11_i83 + 3] = c11_dv18[c11_i84];
    c11_i83 = c11_i83 + 4;
  }

  _SFD_SCRIPT_CALL(0, 67);
  for (c11_i85 = 0; c11_i85 < 2; c11_i85 = c11_i85 + 1) {
    c11_bv0[c11_i85] = TRUE;
  }

  CV_SCRIPT_IF(0, 0, c11_all(chartInstance, c11_bv0));
  _SFD_SCRIPT_CALL(0, 68);
  for (c11_i86 = 0; c11_i86 < 16; c11_i86 = c11_i86 + 1) {
    c11_b_gd[c11_i86] = c11_gd[c11_i86];
  }

  for (c11_i87 = 0; c11_i87 < 16; c11_i87 = c11_i87 + 1) {
    c11_b_gst0[c11_i87] = c11_gst0[c11_i87];
  }

  c11_mrdivide(chartInstance, c11_b_gd, c11_b_gst0, c11_dv19);
  for (c11_i88 = 0; c11_i88 < 16; c11_i88 = c11_i88 + 1) {
    c11_g1[c11_i88] = c11_dv19[c11_i88];
  }

  /*  gd*inv(gst0) */
  /*  select pw = [L2+L5;0;L1+L3+L4] */
  _SFD_SCRIPT_CALL(0, 83);
  for (c11_i89 = 0; c11_i89 < 16; c11_i89 = c11_i89 + 1) {
    c11_a[c11_i89] = c11_g1[c11_i89];
  }

  for (c11_i90 = 0; c11_i90 < 4; c11_i90 = c11_i90 + 1) {
    c11_b[c11_i90] = c11_b_pw[c11_i90];
  }

  c11_d_eml_scalar_eg(chartInstance);
  c11_d_eml_scalar_eg(chartInstance);
  for (c11_i91 = 0; c11_i91 < 16; c11_i91 = c11_i91 + 1) {
    c11_A[c11_i91] = c11_a[c11_i91];
  }

  for (c11_i92 = 0; c11_i92 < 4; c11_i92 = c11_i92 + 1) {
    c11_B[c11_i92] = c11_b[c11_i92];
  }

  for (c11_i93 = 0; c11_i93 < 4; c11_i93 = c11_i93 + 1) {
    c11_p1[c11_i93] = 0.0;
  }

  for (c11_i94 = 0; c11_i94 < 16; c11_i94 = c11_i94 + 1) {
    c11_b_A[c11_i94] = c11_A[c11_i94];
  }

  for (c11_i95 = 0; c11_i95 < 4; c11_i95 = c11_i95 + 1) {
    c11_b_B[c11_i95] = c11_B[c11_i95];
  }

  for (c11_i96 = 0; c11_i96 < 16; c11_i96 = c11_i96 + 1) {
    c11_c_A[c11_i96] = c11_b_A[c11_i96];
  }

  for (c11_i97 = 0; c11_i97 < 4; c11_i97 = c11_i97 + 1) {
    c11_c_B[c11_i97] = c11_b_B[c11_i97];
  }

  for (c11_i98 = 0; c11_i98 < 4; c11_i98 = c11_i98 + 1) {
    c11_p1[c11_i98] = 0.0;
    c11_i99 = 0;
    for (c11_i100 = 0; c11_i100 < 4; c11_i100 = c11_i100 + 1) {
      c11_p1[c11_i98] = c11_p1[c11_i98] + c11_c_A[c11_i99 + c11_i98] *
        c11_c_B[c11_i100];
      c11_i99 = c11_i99 + 4;
    }
  }

  _SFD_SCRIPT_CALL(0, 84);
  c11_theta_1 = c11_atan2(chartInstance, c11_p1[1], c11_p1[0]);

  /*  only one solution */
  _SFD_SCRIPT_CALL(0, 85);
  if (CV_SCRIPT_IF(0, 2, (real_T)c11_isInRange(chartInstance, c11_theta_1,
        -165.0, 165.0) == 0.0)) {
    /* disp('Cannot find appropriate theta_1'); */
  } else {
    /*  select q2 = [L2;0;L1], subproblem3 */
    _SFD_SCRIPT_CALL(0, 91);
    for (c11_i101 = 0; c11_i101 < 6; c11_i101 = c11_i101 + 1) {
      c11_dv21[c11_i101] = c11_dv20[c11_i101];
    }

    c11_expWre(chartInstance, c11_dv21, c11_theta_1, c11_b_a);
    for (c11_i102 = 0; c11_i102 < 4; c11_i102 = c11_i102 + 1) {
      c11_b_b[c11_i102] = c11_p1[c11_i102];
    }

    c11_d_eml_scalar_eg(chartInstance);
    c11_d_eml_scalar_eg(chartInstance);
    for (c11_i103 = 0; c11_i103 < 16; c11_i103 = c11_i103 + 1) {
      c11_d_A[c11_i103] = c11_b_a[c11_i103];
    }

    for (c11_i104 = 0; c11_i104 < 4; c11_i104 = c11_i104 + 1) {
      c11_d_B[c11_i104] = c11_b_b[c11_i104];
    }

    for (c11_i105 = 0; c11_i105 < 4; c11_i105 = c11_i105 + 1) {
      c11_p2[c11_i105] = 0.0;
    }

    for (c11_i106 = 0; c11_i106 < 16; c11_i106 = c11_i106 + 1) {
      c11_e_A[c11_i106] = c11_d_A[c11_i106];
    }

    for (c11_i107 = 0; c11_i107 < 4; c11_i107 = c11_i107 + 1) {
      c11_e_B[c11_i107] = c11_d_B[c11_i107];
    }

    for (c11_i108 = 0; c11_i108 < 16; c11_i108 = c11_i108 + 1) {
      c11_f_A[c11_i108] = c11_e_A[c11_i108];
    }

    for (c11_i109 = 0; c11_i109 < 4; c11_i109 = c11_i109 + 1) {
      c11_f_B[c11_i109] = c11_e_B[c11_i109];
    }

    for (c11_i110 = 0; c11_i110 < 4; c11_i110 = c11_i110 + 1) {
      c11_p2[c11_i110] = 0.0;
      c11_i111 = 0;
      for (c11_i112 = 0; c11_i112 < 4; c11_i112 = c11_i112 + 1) {
        c11_p2[c11_i110] = c11_p2[c11_i110] + c11_f_A[c11_i111 + c11_i110] *
          c11_f_B[c11_i112];
        c11_i111 = c11_i111 + 4;
      }
    }

    _SFD_SCRIPT_CALL(0, 92);
    for (c11_i113 = 0; c11_i113 < 4; c11_i113 = c11_i113 + 1) {
      c11_d[c11_i113] = c11_p2[c11_i113] - c11_b_q2[c11_i113];
    }

    _SFD_SCRIPT_CALL(0, 93);
    for (c11_i114 = 0; c11_i114 < 6; c11_i114 = c11_i114 + 1) {
      c11_b_kx3[c11_i114] = c11_kx3[c11_i114];
    }

    for (c11_i115 = 0; c11_i115 < 4; c11_i115 = c11_i115 + 1) {
      c11_c_pw[c11_i115] = c11_b_pw[c11_i115];
    }

    for (c11_i116 = 0; c11_i116 < 4; c11_i116 = c11_i116 + 1) {
      c11_d_q2[c11_i116] = c11_b_q2[c11_i116];
    }

    for (c11_i117 = 0; c11_i117 < 4; c11_i117 = c11_i117 + 1) {
      c11_b_d[c11_i117] = c11_d[c11_i117];
    }

    c11_subPro3(chartInstance, c11_b_kx3, c11_c_pw, c11_d_q2, c11_b_d,
                c11_b_theta_3, &c11_b_Num_3);
    for (c11_i118 = 0; c11_i118 < 2; c11_i118 = c11_i118 + 1) {
      c11_theta_3[c11_i118] = c11_b_theta_3[c11_i118];
    }

    c11_Num_3 = c11_b_Num_3;

    /*  at most 2 solutions */
    _SFD_SCRIPT_CALL(0, 94);
    for (c11_i119 = 0; c11_i119 < 2; c11_i119 = c11_i119 + 1) {
      c11_c_theta_3[c11_i119] = c11_theta_3[c11_i119];
    }

    c11_b_isInRange(chartInstance, c11_c_theta_3, -210.0, 90.0, c11_bv1);
    for (c11_i120 = 0; c11_i120 < 2; c11_i120 = c11_i120 + 1) {
      c11_bv2[c11_i120] = ((real_T)c11_bv1[c11_i120] == 1.0);
    }

    if (CV_SCRIPT_IF(0, 3, (real_T)c11_any(chartInstance, c11_bv2) == 0.0)) {
      /* disp('Cannot find appropriate theta_3'); */
    } else {
      /*   */
      c11_c3 = 1.0;
      c11_b_c3 = 1.0;
     label_2:
      ;
      if (c11_b_c3 <= c11_Num_3) {
        c11_c3 = c11_b_c3;
        CV_SCRIPT_FOR(0, 0, 1);
        _SFD_SCRIPT_CALL(0, 102);
        if (CV_SCRIPT_IF(0, 4, (real_T)c11_isInRange(chartInstance, c11_theta_3
              [(int32_T)c11_c3 - 1], -210.0, 90.0) == 1.0)) {
          _SFD_SCRIPT_CALL(0, 103);
          for (c11_i121 = 0; c11_i121 < 6; c11_i121 = c11_i121 + 1) {
            c11_c_kx3[c11_i121] = c11_kx3[c11_i121];
          }

          c11_expWre(chartInstance, c11_c_kx3, c11_theta_3[(int32_T)c11_c3 - 1],
                     c11_c_a);
          for (c11_i122 = 0; c11_i122 < 4; c11_i122 = c11_i122 + 1) {
            c11_c_b[c11_i122] = c11_b_pw[c11_i122];
          }

          c11_d_eml_scalar_eg(chartInstance);
          c11_d_eml_scalar_eg(chartInstance);
          for (c11_i123 = 0; c11_i123 < 16; c11_i123 = c11_i123 + 1) {
            c11_g_A[c11_i123] = c11_c_a[c11_i123];
          }

          for (c11_i124 = 0; c11_i124 < 4; c11_i124 = c11_i124 + 1) {
            c11_g_B[c11_i124] = c11_c_b[c11_i124];
          }

          for (c11_i125 = 0; c11_i125 < 4; c11_i125 = c11_i125 + 1) {
            c11_p3[c11_i125] = 0.0;
          }

          for (c11_i126 = 0; c11_i126 < 16; c11_i126 = c11_i126 + 1) {
            c11_h_A[c11_i126] = c11_g_A[c11_i126];
          }

          for (c11_i127 = 0; c11_i127 < 4; c11_i127 = c11_i127 + 1) {
            c11_h_B[c11_i127] = c11_g_B[c11_i127];
          }

          for (c11_i128 = 0; c11_i128 < 16; c11_i128 = c11_i128 + 1) {
            c11_i_A[c11_i128] = c11_h_A[c11_i128];
          }

          for (c11_i129 = 0; c11_i129 < 4; c11_i129 = c11_i129 + 1) {
            c11_i_B[c11_i129] = c11_h_B[c11_i129];
          }

          for (c11_i130 = 0; c11_i130 < 4; c11_i130 = c11_i130 + 1) {
            c11_p3[c11_i130] = 0.0;
            c11_i131 = 0;
            for (c11_i132 = 0; c11_i132 < 4; c11_i132 = c11_i132 + 1) {
              c11_p3[c11_i130] = c11_p3[c11_i130] + c11_i_A[c11_i131 + c11_i130]
                * c11_i_B[c11_i132];
              c11_i131 = c11_i131 + 4;
            }
          }

          _SFD_SCRIPT_CALL(0, 104);
          for (c11_i133 = 0; c11_i133 < 6; c11_i133 = c11_i133 + 1) {
            c11_b_kx2[c11_i133] = c11_kx2[c11_i133];
          }

          for (c11_i134 = 0; c11_i134 < 4; c11_i134 = c11_i134 + 1) {
            c11_b_p3[c11_i134] = c11_p3[c11_i134];
          }

          for (c11_i135 = 0; c11_i135 < 4; c11_i135 = c11_i135 + 1) {
            c11_b_p2[c11_i135] = c11_p2[c11_i135];
          }

          c11_theta_2 = c11_subPro1(chartInstance, c11_b_kx2, c11_b_p3, c11_b_p2);

          /*  only one solution */
          _SFD_SCRIPT_CALL(0, 105);
          if (CV_SCRIPT_IF(0, 5, (real_T)c11_isInRange(chartInstance,
                c11_theta_2, -150.0, 60.0) == 0.0)) {
            /* disp('Cannot find appropriate theta_2'); */
            goto label_1;
          } else {
            _SFD_SCRIPT_CALL(0, 110);
            for (c11_i136 = 0; c11_i136 < 6; c11_i136 = c11_i136 + 1) {
              c11_d_kx3[c11_i136] = -c11_kx3[c11_i136];
            }

            c11_expWre(chartInstance, c11_d_kx3, c11_theta_3[(int32_T)c11_c3 - 1],
                       c11_d_a);
            for (c11_i137 = 0; c11_i137 < 6; c11_i137 = c11_i137 + 1) {
              c11_c_kx2[c11_i137] = -c11_kx2[c11_i137];
            }

            c11_expWre(chartInstance, c11_c_kx2, c11_theta_2, c11_d_b);
            c11_b_eml_scalar_eg(chartInstance);
            c11_b_eml_scalar_eg(chartInstance);
            for (c11_i138 = 0; c11_i138 < 16; c11_i138 = c11_i138 + 1) {
              c11_j_A[c11_i138] = c11_d_a[c11_i138];
            }

            for (c11_i139 = 0; c11_i139 < 16; c11_i139 = c11_i139 + 1) {
              c11_j_B[c11_i139] = c11_d_b[c11_i139];
            }

            for (c11_i140 = 0; c11_i140 < 16; c11_i140 = c11_i140 + 1) {
              c11_k_A[c11_i140] = c11_j_A[c11_i140];
            }

            for (c11_i141 = 0; c11_i141 < 16; c11_i141 = c11_i141 + 1) {
              c11_k_B[c11_i141] = c11_j_B[c11_i141];
            }

            for (c11_i142 = 0; c11_i142 < 16; c11_i142 = c11_i142 + 1) {
              c11_l_A[c11_i142] = c11_k_A[c11_i142];
            }

            for (c11_i143 = 0; c11_i143 < 16; c11_i143 = c11_i143 + 1) {
              c11_l_B[c11_i143] = c11_k_B[c11_i143];
            }

            for (c11_i144 = 0; c11_i144 < 4; c11_i144 = c11_i144 + 1) {
              c11_i145 = 0;
              for (c11_i146 = 0; c11_i146 < 4; c11_i146 = c11_i146 + 1) {
                c11_y[c11_i145 + c11_i144] = 0.0;
                c11_i147 = 0;
                for (c11_i148 = 0; c11_i148 < 4; c11_i148 = c11_i148 + 1) {
                  c11_y[c11_i145 + c11_i144] = c11_y[c11_i145 + c11_i144] +
                    c11_l_A[c11_i147 + c11_i144] * c11_l_B[c11_i148 + c11_i145];
                  c11_i147 = c11_i147 + 4;
                }

                c11_i145 = c11_i145 + 4;
              }
            }

            for (c11_i149 = 0; c11_i149 < 16; c11_i149 = c11_i149 + 1) {
              c11_e_a[c11_i149] = c11_y[c11_i149];
            }

            for (c11_i150 = 0; c11_i150 < 6; c11_i150 = c11_i150 + 1) {
              c11_dv22[c11_i150] = c11_dv20[c11_i150];
            }

            c11_expWre(chartInstance, c11_dv22, c11_theta_1, c11_e_b);
            c11_b_eml_scalar_eg(chartInstance);
            c11_b_eml_scalar_eg(chartInstance);
            for (c11_i151 = 0; c11_i151 < 16; c11_i151 = c11_i151 + 1) {
              c11_m_A[c11_i151] = c11_e_a[c11_i151];
            }

            for (c11_i152 = 0; c11_i152 < 16; c11_i152 = c11_i152 + 1) {
              c11_m_B[c11_i152] = c11_e_b[c11_i152];
            }

            for (c11_i153 = 0; c11_i153 < 16; c11_i153 = c11_i153 + 1) {
              c11_n_A[c11_i153] = c11_m_A[c11_i153];
            }

            for (c11_i154 = 0; c11_i154 < 16; c11_i154 = c11_i154 + 1) {
              c11_n_B[c11_i154] = c11_m_B[c11_i154];
            }

            for (c11_i155 = 0; c11_i155 < 16; c11_i155 = c11_i155 + 1) {
              c11_o_A[c11_i155] = c11_n_A[c11_i155];
            }

            for (c11_i156 = 0; c11_i156 < 16; c11_i156 = c11_i156 + 1) {
              c11_o_B[c11_i156] = c11_n_B[c11_i156];
            }

            for (c11_i157 = 0; c11_i157 < 4; c11_i157 = c11_i157 + 1) {
              c11_i158 = 0;
              for (c11_i159 = 0; c11_i159 < 4; c11_i159 = c11_i159 + 1) {
                c11_b_y[c11_i158 + c11_i157] = 0.0;
                c11_i160 = 0;
                for (c11_i161 = 0; c11_i161 < 4; c11_i161 = c11_i161 + 1) {
                  c11_b_y[c11_i158 + c11_i157] = c11_b_y[c11_i158 + c11_i157] +
                    c11_o_A[c11_i160 + c11_i157] * c11_o_B[c11_i161 + c11_i158];
                  c11_i160 = c11_i160 + 4;
                }

                c11_i158 = c11_i158 + 4;
              }
            }

            for (c11_i162 = 0; c11_i162 < 16; c11_i162 = c11_i162 + 1) {
              c11_f_a[c11_i162] = c11_b_y[c11_i162];
            }

            for (c11_i163 = 0; c11_i163 < 16; c11_i163 = c11_i163 + 1) {
              c11_f_b[c11_i163] = c11_g1[c11_i163];
            }

            c11_b_eml_scalar_eg(chartInstance);
            c11_b_eml_scalar_eg(chartInstance);
            for (c11_i164 = 0; c11_i164 < 16; c11_i164 = c11_i164 + 1) {
              c11_p_A[c11_i164] = c11_f_a[c11_i164];
            }

            for (c11_i165 = 0; c11_i165 < 16; c11_i165 = c11_i165 + 1) {
              c11_p_B[c11_i165] = c11_f_b[c11_i165];
            }

            for (c11_i166 = 0; c11_i166 < 16; c11_i166 = c11_i166 + 1) {
              c11_g2[c11_i166] = 0.0;
            }

            for (c11_i167 = 0; c11_i167 < 16; c11_i167 = c11_i167 + 1) {
              c11_q_A[c11_i167] = c11_p_A[c11_i167];
            }

            for (c11_i168 = 0; c11_i168 < 16; c11_i168 = c11_i168 + 1) {
              c11_q_B[c11_i168] = c11_p_B[c11_i168];
            }

            for (c11_i169 = 0; c11_i169 < 16; c11_i169 = c11_i169 + 1) {
              c11_r_A[c11_i169] = c11_q_A[c11_i169];
            }

            for (c11_i170 = 0; c11_i170 < 16; c11_i170 = c11_i170 + 1) {
              c11_r_B[c11_i170] = c11_q_B[c11_i170];
            }

            for (c11_i171 = 0; c11_i171 < 4; c11_i171 = c11_i171 + 1) {
              c11_i172 = 0;
              for (c11_i173 = 0; c11_i173 < 4; c11_i173 = c11_i173 + 1) {
                c11_g2[c11_i172 + c11_i171] = 0.0;
                c11_i174 = 0;
                for (c11_i175 = 0; c11_i175 < 4; c11_i175 = c11_i175 + 1) {
                  c11_g2[c11_i172 + c11_i171] = c11_g2[c11_i172 + c11_i171] +
                    c11_r_A[c11_i174 + c11_i171] * c11_r_B[c11_i175 + c11_i172];
                  c11_i174 = c11_i174 + 4;
                }

                c11_i172 = c11_i172 + 4;
              }
            }

            /* select q7 */
            _SFD_SCRIPT_CALL(0, 113);
            for (c11_i176 = 0; c11_i176 < 16; c11_i176 = c11_i176 + 1) {
              c11_g_a[c11_i176] = c11_g2[c11_i176];
            }

            for (c11_i177 = 0; c11_i177 < 4; c11_i177 = c11_i177 + 1) {
              c11_g_b[c11_i177] = c11_b_q7[c11_i177];
            }

            c11_d_eml_scalar_eg(chartInstance);
            c11_d_eml_scalar_eg(chartInstance);
            for (c11_i178 = 0; c11_i178 < 16; c11_i178 = c11_i178 + 1) {
              c11_s_A[c11_i178] = c11_g_a[c11_i178];
            }

            for (c11_i179 = 0; c11_i179 < 4; c11_i179 = c11_i179 + 1) {
              c11_s_B[c11_i179] = c11_g_b[c11_i179];
            }

            for (c11_i180 = 0; c11_i180 < 4; c11_i180 = c11_i180 + 1) {
              c11_p4[c11_i180] = 0.0;
            }

            for (c11_i181 = 0; c11_i181 < 16; c11_i181 = c11_i181 + 1) {
              c11_t_A[c11_i181] = c11_s_A[c11_i181];
            }

            for (c11_i182 = 0; c11_i182 < 4; c11_i182 = c11_i182 + 1) {
              c11_t_B[c11_i182] = c11_s_B[c11_i182];
            }

            for (c11_i183 = 0; c11_i183 < 16; c11_i183 = c11_i183 + 1) {
              c11_u_A[c11_i183] = c11_t_A[c11_i183];
            }

            for (c11_i184 = 0; c11_i184 < 4; c11_i184 = c11_i184 + 1) {
              c11_u_B[c11_i184] = c11_t_B[c11_i184];
            }

            for (c11_i185 = 0; c11_i185 < 4; c11_i185 = c11_i185 + 1) {
              c11_p4[c11_i185] = 0.0;
              c11_i186 = 0;
              for (c11_i187 = 0; c11_i187 < 4; c11_i187 = c11_i187 + 1) {
                c11_p4[c11_i185] = c11_p4[c11_i185] + c11_u_A[c11_i186 +
                  c11_i185] * c11_u_B[c11_i187];
                c11_i186 = c11_i186 + 4;
              }
            }

            _SFD_SCRIPT_CALL(0, 114);
            for (c11_i188 = 0; c11_i188 < 6; c11_i188 = c11_i188 + 1) {
              c11_b_kx4[c11_i188] = c11_kx4[c11_i188];
            }

            for (c11_i189 = 0; c11_i189 < 6; c11_i189 = c11_i189 + 1) {
              c11_b_kx5[c11_i189] = c11_kx5[c11_i189];
            }

            for (c11_i190 = 0; c11_i190 < 4; c11_i190 = c11_i190 + 1) {
              c11_c_q7[c11_i190] = c11_b_q7[c11_i190];
            }

            for (c11_i191 = 0; c11_i191 < 4; c11_i191 = c11_i191 + 1) {
              c11_b_p4[c11_i191] = c11_p4[c11_i191];
            }

            c11_subPro2(chartInstance, c11_b_kx4, c11_b_kx5, c11_c_q7, c11_b_p4,
                        c11_b_theta_4, c11_b_theta_5, &c11_b_Num_45);
            for (c11_i192 = 0; c11_i192 < 2; c11_i192 = c11_i192 + 1) {
              c11_theta_4[c11_i192] = c11_b_theta_4[c11_i192];
            }

            for (c11_i193 = 0; c11_i193 < 2; c11_i193 = c11_i193 + 1) {
              c11_theta_5[c11_i193] = c11_b_theta_5[c11_i193];
            }

            c11_Num_45 = c11_b_Num_45;

            /*  at most 2 pairs of solution */
            _SFD_SCRIPT_CALL(0, 116);
            for (c11_i194 = 0; c11_i194 < 2; c11_i194 = c11_i194 + 1) {
              c11_c_theta_5[c11_i194] = c11_theta_5[c11_i194];
            }

            c11_b_isInRange(chartInstance, c11_c_theta_5, -140.0, 140.0, c11_bv3);
            for (c11_i195 = 0; c11_i195 < 2; c11_i195 = c11_i195 + 1) {
              c11_bv4[c11_i195] = ((real_T)c11_bv3[c11_i195] == 1.0);
            }

            if (CV_SCRIPT_IF(0, 6, (real_T)c11_any(chartInstance, c11_bv4) ==
                             0.0)) {
              /* disp('Cannot find appropriate theta_5'); */
              goto label_1;
            } else {
              c11_c45 = 1.0;
              c11_b_c45 = 1.0;
              while (c11_b_c45 <= c11_Num_45) {
                c11_c45 = c11_b_c45;
                CV_SCRIPT_FOR(0, 1, 1);
                _SFD_SCRIPT_CALL(0, 122);
                if (CV_SCRIPT_IF(0, 7, (real_T)c11_isInRange(chartInstance,
                      c11_theta_5[(int32_T)c11_c45 - 1], -140.0, 140.0) == 1.0))
                {
                  _SFD_SCRIPT_CALL(0, 123);
                  for (c11_i196 = 0; c11_i196 < 6; c11_i196 = c11_i196 + 1) {
                    c11_c_kx5[c11_i196] = -c11_kx5[c11_i196];
                  }

                  c11_expWre(chartInstance, c11_c_kx5, c11_theta_5[(int32_T)
                             c11_c45 - 1], c11_h_a);
                  for (c11_i197 = 0; c11_i197 < 6; c11_i197 = c11_i197 + 1) {
                    c11_c_kx4[c11_i197] = -c11_kx4[c11_i197];
                  }

                  c11_expWre(chartInstance, c11_c_kx4, c11_theta_4[(int32_T)
                             c11_c45 - 1], c11_h_b);
                  c11_b_eml_scalar_eg(chartInstance);
                  c11_b_eml_scalar_eg(chartInstance);
                  for (c11_i198 = 0; c11_i198 < 16; c11_i198 = c11_i198 + 1) {
                    c11_v_A[c11_i198] = c11_h_a[c11_i198];
                  }

                  for (c11_i199 = 0; c11_i199 < 16; c11_i199 = c11_i199 + 1) {
                    c11_v_B[c11_i199] = c11_h_b[c11_i199];
                  }

                  for (c11_i200 = 0; c11_i200 < 16; c11_i200 = c11_i200 + 1) {
                    c11_w_A[c11_i200] = c11_v_A[c11_i200];
                  }

                  for (c11_i201 = 0; c11_i201 < 16; c11_i201 = c11_i201 + 1) {
                    c11_w_B[c11_i201] = c11_v_B[c11_i201];
                  }

                  for (c11_i202 = 0; c11_i202 < 16; c11_i202 = c11_i202 + 1) {
                    c11_x_A[c11_i202] = c11_w_A[c11_i202];
                  }

                  for (c11_i203 = 0; c11_i203 < 16; c11_i203 = c11_i203 + 1) {
                    c11_x_B[c11_i203] = c11_w_B[c11_i203];
                  }

                  for (c11_i204 = 0; c11_i204 < 4; c11_i204 = c11_i204 + 1) {
                    c11_i205 = 0;
                    for (c11_i206 = 0; c11_i206 < 4; c11_i206 = c11_i206 + 1) {
                      c11_c_y[c11_i205 + c11_i204] = 0.0;
                      c11_i207 = 0;
                      for (c11_i208 = 0; c11_i208 < 4; c11_i208 = c11_i208 + 1)
                      {
                        c11_c_y[c11_i205 + c11_i204] = c11_c_y[c11_i205 +
                          c11_i204] + c11_x_A[c11_i207 + c11_i204] *
                          c11_x_B[c11_i208 + c11_i205];
                        c11_i207 = c11_i207 + 4;
                      }

                      c11_i205 = c11_i205 + 4;
                    }
                  }

                  for (c11_i209 = 0; c11_i209 < 16; c11_i209 = c11_i209 + 1) {
                    c11_i_a[c11_i209] = c11_c_y[c11_i209];
                  }

                  for (c11_i210 = 0; c11_i210 < 16; c11_i210 = c11_i210 + 1) {
                    c11_i_b[c11_i210] = c11_g2[c11_i210];
                  }

                  c11_b_eml_scalar_eg(chartInstance);
                  c11_b_eml_scalar_eg(chartInstance);
                  for (c11_i211 = 0; c11_i211 < 16; c11_i211 = c11_i211 + 1) {
                    c11_y_A[c11_i211] = c11_i_a[c11_i211];
                  }

                  for (c11_i212 = 0; c11_i212 < 16; c11_i212 = c11_i212 + 1) {
                    c11_y_B[c11_i212] = c11_i_b[c11_i212];
                  }

                  for (c11_i213 = 0; c11_i213 < 16; c11_i213 = c11_i213 + 1) {
                    c11_g3[c11_i213] = 0.0;
                  }

                  for (c11_i214 = 0; c11_i214 < 16; c11_i214 = c11_i214 + 1) {
                    c11_ab_A[c11_i214] = c11_y_A[c11_i214];
                  }

                  for (c11_i215 = 0; c11_i215 < 16; c11_i215 = c11_i215 + 1) {
                    c11_ab_B[c11_i215] = c11_y_B[c11_i215];
                  }

                  for (c11_i216 = 0; c11_i216 < 16; c11_i216 = c11_i216 + 1) {
                    c11_bb_A[c11_i216] = c11_ab_A[c11_i216];
                  }

                  for (c11_i217 = 0; c11_i217 < 16; c11_i217 = c11_i217 + 1) {
                    c11_bb_B[c11_i217] = c11_ab_B[c11_i217];
                  }

                  for (c11_i218 = 0; c11_i218 < 4; c11_i218 = c11_i218 + 1) {
                    c11_i219 = 0;
                    for (c11_i220 = 0; c11_i220 < 4; c11_i220 = c11_i220 + 1) {
                      c11_g3[c11_i219 + c11_i218] = 0.0;
                      c11_i221 = 0;
                      for (c11_i222 = 0; c11_i222 < 4; c11_i222 = c11_i222 + 1)
                      {
                        c11_g3[c11_i219 + c11_i218] = c11_g3[c11_i219 + c11_i218]
                          + c11_bb_A[c11_i221 + c11_i218] * c11_bb_B[c11_i222 +
                          c11_i219];
                        c11_i221 = c11_i221 + 4;
                      }

                      c11_i219 = c11_i219 + 4;
                    }
                  }

                  /* selcet q3 */
                  _SFD_SCRIPT_CALL(0, 125);
                  for (c11_i223 = 0; c11_i223 < 16; c11_i223 = c11_i223 + 1) {
                    c11_j_a[c11_i223] = c11_g3[c11_i223];
                  }

                  for (c11_i224 = 0; c11_i224 < 4; c11_i224 = c11_i224 + 1) {
                    c11_j_b[c11_i224] = c11_b_q3[c11_i224];
                  }

                  c11_d_eml_scalar_eg(chartInstance);
                  c11_d_eml_scalar_eg(chartInstance);
                  for (c11_i225 = 0; c11_i225 < 16; c11_i225 = c11_i225 + 1) {
                    c11_cb_A[c11_i225] = c11_j_a[c11_i225];
                  }

                  for (c11_i226 = 0; c11_i226 < 4; c11_i226 = c11_i226 + 1) {
                    c11_cb_B[c11_i226] = c11_j_b[c11_i226];
                  }

                  for (c11_i227 = 0; c11_i227 < 4; c11_i227 = c11_i227 + 1) {
                    c11_p5[c11_i227] = 0.0;
                  }

                  for (c11_i228 = 0; c11_i228 < 16; c11_i228 = c11_i228 + 1) {
                    c11_db_A[c11_i228] = c11_cb_A[c11_i228];
                  }

                  for (c11_i229 = 0; c11_i229 < 4; c11_i229 = c11_i229 + 1) {
                    c11_db_B[c11_i229] = c11_cb_B[c11_i229];
                  }

                  for (c11_i230 = 0; c11_i230 < 16; c11_i230 = c11_i230 + 1) {
                    c11_eb_A[c11_i230] = c11_db_A[c11_i230];
                  }

                  for (c11_i231 = 0; c11_i231 < 4; c11_i231 = c11_i231 + 1) {
                    c11_eb_B[c11_i231] = c11_db_B[c11_i231];
                  }

                  for (c11_i232 = 0; c11_i232 < 4; c11_i232 = c11_i232 + 1) {
                    c11_p5[c11_i232] = 0.0;
                    c11_i233 = 0;
                    for (c11_i234 = 0; c11_i234 < 4; c11_i234 = c11_i234 + 1) {
                      c11_p5[c11_i232] = c11_p5[c11_i232] + c11_eb_A[c11_i233 +
                        c11_i232] * c11_eb_B[c11_i234];
                      c11_i233 = c11_i233 + 4;
                    }
                  }

                  _SFD_SCRIPT_CALL(0, 126);
                  for (c11_i235 = 0; c11_i235 < 6; c11_i235 = c11_i235 + 1) {
                    c11_b_kx6[c11_i235] = c11_kx6[c11_i235];
                  }

                  for (c11_i236 = 0; c11_i236 < 4; c11_i236 = c11_i236 + 1) {
                    c11_d_q3[c11_i236] = c11_b_q3[c11_i236];
                  }

                  for (c11_i237 = 0; c11_i237 < 4; c11_i237 = c11_i237 + 1) {
                    c11_b_p5[c11_i237] = c11_p5[c11_i237];
                  }

                  c11_theta_6 = c11_subPro1(chartInstance, c11_b_kx6, c11_d_q3,
                    c11_b_p5);

                  /*  only one solution */
                  _SFD_SCRIPT_CALL(0, 128);
                  *c11_Num = *c11_Num + 1.0;
                  _SFD_SCRIPT_CALL(0, 129);
                  c11_b_Num = _SFD_EML_ARRAY_BOUNDS_CHECK("theta", (int32_T)
                    *c11_Num, 1, 4, 2, 0) - 1;
                  c11_b_theta_1[0] = c11_theta_1;
                  c11_b_theta_1[1] = c11_theta_2;
                  c11_b_theta_1[2] = c11_theta_3[(int32_T)c11_c3 - 1];
                  c11_b_theta_1[3] = c11_theta_4[(int32_T)c11_c45 - 1];
                  c11_b_theta_1[4] = c11_theta_5[(int32_T)c11_c45 - 1];
                  c11_b_theta_1[5] = c11_theta_6;
                  for (c11_i238 = 0; c11_i238 < 6; c11_i238 = c11_i238 + 1) {
                    c11_theta[c11_i238 + 6 * c11_b_Num] = c11_b_theta_1[c11_i238];
                  }
                }

                c11_b_c45 = c11_b_c45 + 1.0;
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

      c11_b_c3 = c11_b_c3 + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
      goto label_2;
     label_1:
      ;
    }
  }

  _SFD_SCRIPT_CALL(0, -129);
  sf_debug_symbol_scope_pop();
}

static void c11_cross(SFc11_KinConInstanceStruct *chartInstance, real_T c11_a[3],
                      real_T c11_b[3], real_T c11_c[3])
{
  real_T c11_b_a;
  real_T c11_b_b;
  real_T c11_y;
  real_T c11_c_a;
  real_T c11_c_b;
  real_T c11_b_y;
  real_T c11_c1;
  real_T c11_d_a;
  real_T c11_d_b;
  real_T c11_c_y;
  real_T c11_e_a;
  real_T c11_e_b;
  real_T c11_d_y;
  real_T c11_c2;
  real_T c11_f_a;
  real_T c11_f_b;
  real_T c11_e_y;
  real_T c11_g_a;
  real_T c11_g_b;
  real_T c11_f_y;
  real_T c11_c3;
  c11_b_a = c11_a[1];
  c11_b_b = c11_b[2];
  c11_y = c11_b_a * c11_b_b;
  c11_c_a = c11_a[2];
  c11_c_b = c11_b[1];
  c11_b_y = c11_c_a * c11_c_b;
  c11_c1 = c11_y - c11_b_y;
  c11_d_a = c11_a[2];
  c11_d_b = c11_b[0];
  c11_c_y = c11_d_a * c11_d_b;
  c11_e_a = c11_a[0];
  c11_e_b = c11_b[2];
  c11_d_y = c11_e_a * c11_e_b;
  c11_c2 = c11_c_y - c11_d_y;
  c11_f_a = c11_a[0];
  c11_f_b = c11_b[1];
  c11_e_y = c11_f_a * c11_f_b;
  c11_g_a = c11_a[1];
  c11_g_b = c11_b[0];
  c11_f_y = c11_g_a * c11_g_b;
  c11_c3 = c11_e_y - c11_f_y;
  c11_c[0] = c11_c1;
  c11_c[1] = c11_c2;
  c11_c[2] = c11_c3;
}

static boolean_T c11_all(SFc11_KinConInstanceStruct *chartInstance, boolean_T
  c11_x[2])
{
  return TRUE;
}

static void c11_mrdivide(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_A[16], real_T c11_B[16], real_T c11_y[16])
{
  int32_T c11_i239;
  int32_T c11_i240;
  int32_T c11_i241;
  int32_T c11_i242;
  real_T c11_b_A[16];
  int32_T c11_i243;
  int32_T c11_i244;
  int32_T c11_i245;
  int32_T c11_i246;
  real_T c11_b_B[16];
  int32_T c11_i247;
  real_T c11_c_A[16];
  int32_T c11_i248;
  real_T c11_c_B[16];
  int32_T c11_i249;
  real_T c11_d_A[16];
  int32_T c11_i250;
  real_T c11_d_B[16];
  int32_T c11_i251;
  real_T c11_e_A[16];
  int32_T c11_i252;
  real_T c11_f_A[16];
  int32_T c11_i253;
  real_T c11_g_A[16];
  int32_T c11_i254;
  real_T c11_h_A[16];
  int32_T c11_i255;
  real_T c11_i_A[16];
  int32_T c11_info;
  int32_T c11_ipiv[4];
  real_T c11_j_A[16];
  int32_T c11_i256;
  int32_T c11_i257;
  int32_T c11_b_ipiv[4];
  int32_T c11_b_info;
  int32_T c11_i258;
  int32_T c11_i259;
  int32_T c11_c_ipiv[4];
  int32_T c11_c_info;
  int32_T c11_i260;
  int32_T c11_i261;
  int32_T c11_d_ipiv[4];
  int32_T c11_d_info;
  int32_T c11_i262;
  real_T c11_Y[16];
  int32_T c11_i;
  int32_T c11_b_i;
  int32_T c11_ip;
  int32_T c11_j;
  int32_T c11_b_j;
  real_T c11_temp;
  int32_T c11_i263;
  real_T c11_k_A[16];
  int32_T c11_i264;
  real_T c11_e_B[16];
  int32_T c11_i265;
  int32_T c11_i266;
  real_T c11_l_A[16];
  int32_T c11_i267;
  real_T c11_f_B[16];
  int32_T c11_i268;
  int32_T c11_i269;
  real_T c11_m_A[16];
  int32_T c11_i270;
  real_T c11_g_B[16];
  int32_T c11_i271;
  int32_T c11_c_j;
  int32_T c11_d_j;
  int32_T c11_a;
  int32_T c11_c;
  int32_T c11_b;
  int32_T c11_b_c;
  int32_T c11_b_b;
  int32_T c11_jBcol;
  int32_T c11_k;
  int32_T c11_b_k;
  int32_T c11_b_a;
  int32_T c11_c_c;
  int32_T c11_c_b;
  int32_T c11_d_c;
  int32_T c11_d_b;
  int32_T c11_kAcol;
  int32_T c11_c_a;
  int32_T c11_e_b;
  int32_T c11_e_c;
  int32_T c11_d_a;
  int32_T c11_i272;
  int32_T c11_c_i;
  int32_T c11_d_i;
  int32_T c11_e_a;
  int32_T c11_f_b;
  int32_T c11_f_c;
  int32_T c11_f_a;
  int32_T c11_g_b;
  int32_T c11_g_c;
  int32_T c11_g_a;
  int32_T c11_h_b;
  int32_T c11_h_c;
  int32_T c11_h_a;
  int32_T c11_i_b;
  int32_T c11_i_c;
  int32_T c11_i273;
  real_T c11_n_A[16];
  int32_T c11_i274;
  real_T c11_b_Y[16];
  int32_T c11_i275;
  int32_T c11_i276;
  int32_T c11_i277;
  int32_T c11_i278;
  c11_i239 = 0;
  for (c11_i240 = 0; c11_i240 < 4; c11_i240 = c11_i240 + 1) {
    c11_i241 = 0;
    for (c11_i242 = 0; c11_i242 < 4; c11_i242 = c11_i242 + 1) {
      c11_b_A[c11_i242 + c11_i239] = c11_B[c11_i241 + c11_i240];
      c11_i241 = c11_i241 + 4;
    }

    c11_i239 = c11_i239 + 4;
  }

  c11_i243 = 0;
  for (c11_i244 = 0; c11_i244 < 4; c11_i244 = c11_i244 + 1) {
    c11_i245 = 0;
    for (c11_i246 = 0; c11_i246 < 4; c11_i246 = c11_i246 + 1) {
      c11_b_B[c11_i246 + c11_i243] = c11_A[c11_i245 + c11_i244];
      c11_i245 = c11_i245 + 4;
    }

    c11_i243 = c11_i243 + 4;
  }

  for (c11_i247 = 0; c11_i247 < 16; c11_i247 = c11_i247 + 1) {
    c11_c_A[c11_i247] = c11_b_A[c11_i247];
  }

  for (c11_i248 = 0; c11_i248 < 16; c11_i248 = c11_i248 + 1) {
    c11_c_B[c11_i248] = c11_b_B[c11_i248];
  }

  for (c11_i249 = 0; c11_i249 < 16; c11_i249 = c11_i249 + 1) {
    c11_d_A[c11_i249] = c11_c_A[c11_i249];
  }

  for (c11_i250 = 0; c11_i250 < 16; c11_i250 = c11_i250 + 1) {
    c11_d_B[c11_i250] = c11_c_B[c11_i250];
  }

  for (c11_i251 = 0; c11_i251 < 16; c11_i251 = c11_i251 + 1) {
    c11_e_A[c11_i251] = c11_d_A[c11_i251];
  }

  for (c11_i252 = 0; c11_i252 < 16; c11_i252 = c11_i252 + 1) {
    c11_f_A[c11_i252] = c11_e_A[c11_i252];
  }

  for (c11_i253 = 0; c11_i253 < 16; c11_i253 = c11_i253 + 1) {
    c11_g_A[c11_i253] = c11_f_A[c11_i253];
  }

  for (c11_i254 = 0; c11_i254 < 16; c11_i254 = c11_i254 + 1) {
    c11_h_A[c11_i254] = c11_g_A[c11_i254];
  }

  for (c11_i255 = 0; c11_i255 < 16; c11_i255 = c11_i255 + 1) {
    c11_i_A[c11_i255] = c11_h_A[c11_i255];
  }

  c11_eml_matlab_zgetrf(chartInstance, c11_i_A, c11_j_A, c11_ipiv, &c11_info);
  for (c11_i256 = 0; c11_i256 < 16; c11_i256 = c11_i256 + 1) {
    c11_h_A[c11_i256] = c11_j_A[c11_i256];
  }

  for (c11_i257 = 0; c11_i257 < 4; c11_i257 = c11_i257 + 1) {
    c11_b_ipiv[c11_i257] = c11_ipiv[c11_i257];
  }

  c11_b_info = c11_info;
  for (c11_i258 = 0; c11_i258 < 16; c11_i258 = c11_i258 + 1) {
    c11_f_A[c11_i258] = c11_h_A[c11_i258];
  }

  for (c11_i259 = 0; c11_i259 < 4; c11_i259 = c11_i259 + 1) {
    c11_c_ipiv[c11_i259] = c11_b_ipiv[c11_i259];
  }

  c11_c_info = c11_b_info;
  for (c11_i260 = 0; c11_i260 < 16; c11_i260 = c11_i260 + 1) {
    c11_d_A[c11_i260] = c11_f_A[c11_i260];
  }

  for (c11_i261 = 0; c11_i261 < 4; c11_i261 = c11_i261 + 1) {
    c11_d_ipiv[c11_i261] = c11_c_ipiv[c11_i261];
  }

  c11_d_info = c11_c_info;
  if ((real_T)c11_d_info > 0.0) {
    c11_eml_warning(chartInstance);
  }

  c11_b_eml_scalar_eg(chartInstance);
  for (c11_i262 = 0; c11_i262 < 16; c11_i262 = c11_i262 + 1) {
    c11_Y[c11_i262] = c11_d_B[c11_i262];
  }

  for (c11_i = 1; c11_i < 5; c11_i = c11_i + 1) {
    c11_b_i = c11_i;
    if (c11_d_ipiv[c11_b_i - 1] != c11_b_i) {
      c11_ip = c11_d_ipiv[c11_b_i - 1];
      for (c11_j = 1; c11_j < 5; c11_j = c11_j + 1) {
        c11_b_j = c11_j;
        c11_temp = c11_Y[(c11_b_i - 1) + ((c11_b_j - 1) << 2)];
        c11_Y[(c11_b_i - 1) + ((c11_b_j - 1) << 2)] = c11_Y
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_ip, 1, 4, 1, 0) - 1) + ((c11_b_j
          - 1) << 2)
          ];
        c11_Y[(c11_ip - 1) + ((c11_b_j - 1) << 2)] = c11_temp;
      }
    }
  }

  for (c11_i263 = 0; c11_i263 < 16; c11_i263 = c11_i263 + 1) {
    c11_k_A[c11_i263] = c11_d_A[c11_i263];
  }

  for (c11_i264 = 0; c11_i264 < 16; c11_i264 = c11_i264 + 1) {
    c11_e_B[c11_i264] = c11_Y[c11_i264];
  }

  for (c11_i265 = 0; c11_i265 < 16; c11_i265 = c11_i265 + 1) {
    c11_Y[c11_i265] = c11_e_B[c11_i265];
  }

  for (c11_i266 = 0; c11_i266 < 16; c11_i266 = c11_i266 + 1) {
    c11_l_A[c11_i266] = c11_k_A[c11_i266];
  }

  for (c11_i267 = 0; c11_i267 < 16; c11_i267 = c11_i267 + 1) {
    c11_f_B[c11_i267] = c11_Y[c11_i267];
  }

  for (c11_i268 = 0; c11_i268 < 16; c11_i268 = c11_i268 + 1) {
    c11_Y[c11_i268] = c11_f_B[c11_i268];
  }

  for (c11_i269 = 0; c11_i269 < 16; c11_i269 = c11_i269 + 1) {
    c11_m_A[c11_i269] = c11_l_A[c11_i269];
  }

  for (c11_i270 = 0; c11_i270 < 16; c11_i270 = c11_i270 + 1) {
    c11_g_B[c11_i270] = c11_Y[c11_i270];
  }

  for (c11_i271 = 0; c11_i271 < 16; c11_i271 = c11_i271 + 1) {
    c11_Y[c11_i271] = c11_g_B[c11_i271];
  }

  c11_c_eml_scalar_eg(chartInstance);
  for (c11_c_j = 1; c11_c_j <= 4; c11_c_j = c11_c_j + 1) {
    c11_d_j = c11_c_j;
    c11_a = c11_d_j;
    c11_c = c11_a - 1;
    c11_b = c11_c;
    c11_b_c = c11_b << 2;
    c11_b_b = c11_b_c;
    c11_jBcol = c11_b_b;
    for (c11_k = 1; c11_k <= 4; c11_k = c11_k + 1) {
      c11_b_k = c11_k;
      c11_b_a = c11_b_k;
      c11_c_c = c11_b_a - 1;
      c11_c_b = c11_c_c;
      c11_d_c = c11_c_b << 2;
      c11_d_b = c11_d_c;
      c11_kAcol = c11_d_b;
      c11_c_a = c11_b_k;
      c11_e_b = c11_jBcol;
      c11_e_c = c11_c_a + c11_e_b;
      if (c11_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_e_c, 1, 16, 1, 0) - 1] !=
          0.0) {
        c11_d_a = c11_b_k;
        c11_i272 = c11_d_a + 1;
        for (c11_c_i = c11_i272; c11_c_i <= 4; c11_c_i = c11_c_i + 1) {
          c11_d_i = c11_c_i;
          c11_e_a = c11_d_i;
          c11_f_b = c11_jBcol;
          c11_f_c = c11_e_a + c11_f_b;
          c11_f_a = c11_d_i;
          c11_g_b = c11_jBcol;
          c11_g_c = c11_f_a + c11_g_b;
          c11_g_a = c11_b_k;
          c11_h_b = c11_jBcol;
          c11_h_c = c11_g_a + c11_h_b;
          c11_h_a = c11_d_i;
          c11_i_b = c11_kAcol;
          c11_i_c = c11_h_a + c11_i_b;
          c11_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_f_c, 1, 16, 1, 0) - 1] =
            c11_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_g_c, 1, 16, 1, 0) - 1]
            - c11_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_h_c, 1, 16, 1, 0) - 1] *
            c11_m_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_i_c, 1, 16, 1, 0)
            - 1];
        }
      }
    }
  }

  for (c11_i273 = 0; c11_i273 < 16; c11_i273 = c11_i273 + 1) {
    c11_n_A[c11_i273] = c11_d_A[c11_i273];
  }

  for (c11_i274 = 0; c11_i274 < 16; c11_i274 = c11_i274 + 1) {
    c11_b_Y[c11_i274] = c11_Y[c11_i274];
  }

  c11_eml_xtrsm(chartInstance, c11_n_A, c11_b_Y, c11_Y);
  c11_i275 = 0;
  for (c11_i276 = 0; c11_i276 < 4; c11_i276 = c11_i276 + 1) {
    c11_i277 = 0;
    for (c11_i278 = 0; c11_i278 < 4; c11_i278 = c11_i278 + 1) {
      c11_y[c11_i278 + c11_i275] = c11_Y[c11_i277 + c11_i276];
      c11_i277 = c11_i277 + 4;
    }

    c11_i275 = c11_i275 + 4;
  }
}

static real_T c11_power(SFc11_KinConInstanceStruct *chartInstance, real_T c11_a,
  real_T c11_b)
{
  real_T c11_ak;
  c11_eml_scalar_eg(chartInstance);
  c11_ak = c11_a;
  return muDoubleScalarPower(c11_ak, 2.0);
}

static void c11_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance)
{
}

static void c11_eps(SFc11_KinConInstanceStruct *chartInstance)
{
}

static void c11_eml_matlab_zgetrf(SFc11_KinConInstanceStruct *chartInstance,
  real_T c11_A[16], real_T c11_b_A[16], int32_T c11_ipiv[
  4], int32_T *c11_info)
{
  int32_T c11_i279;
  int32_T c11_i280;
  int32_T c11_j;
  int32_T c11_b_j;
  int32_T c11_a;
  int32_T c11_jm1;
  int32_T c11_b;
  int32_T c11_mmj;
  int32_T c11_b_a;
  int32_T c11_c;
  int32_T c11_b_b;
  int32_T c11_jj;
  int32_T c11_c_a;
  int32_T c11_jp1j;
  int32_T c11_d_a;
  int32_T c11_b_c;
  int32_T c11_i281;
  real_T c11_c_A[16];
  int32_T c11_e_a;
  int32_T c11_jpiv_offset;
  int32_T c11_f_a;
  int32_T c11_c_b;
  int32_T c11_jpiv;
  int32_T c11_g_a;
  int32_T c11_d_b;
  int32_T c11_c_c;
  int32_T c11_e_b;
  int32_T c11_jrow;
  int32_T c11_h_a;
  int32_T c11_f_b;
  int32_T c11_jprow;
  int32_T c11_i282;
  real_T c11_x[16];
  int32_T c11_ix0;
  int32_T c11_iy0;
  int32_T c11_i283;
  int32_T c11_i284;
  real_T c11_b_x[16];
  int32_T c11_b_ix0;
  int32_T c11_b_iy0;
  int32_T c11_i285;
  real_T c11_c_x[16];
  int32_T c11_i286;
  real_T c11_d_x[16];
  real_T c11_e_x[16];
  int32_T c11_i287;
  int32_T c11_i288;
  int32_T c11_b_jp1j;
  int32_T c11_i_a;
  int32_T c11_d_c;
  int32_T c11_j_a;
  int32_T c11_g_b;
  int32_T c11_loop_ub;
  int32_T c11_i;
  int32_T c11_b_i;
  real_T c11_f_x;
  real_T c11_y;
  real_T c11_g_x;
  real_T c11_b_y;
  real_T c11_z;
  int32_T c11_h_b;
  int32_T c11_e_c;
  int32_T c11_k_a;
  int32_T c11_f_c;
  int32_T c11_l_a;
  int32_T c11_g_c;
  int32_T c11_m;
  int32_T c11_n;
  int32_T c11_c_ix0;
  int32_T c11_c_iy0;
  int32_T c11_i289;
  real_T c11_d_A[16];
  int32_T c11_ia0;
  int32_T c11_i290;
  int32_T c11_b_m;
  int32_T c11_b_n;
  int32_T c11_d_ix0;
  int32_T c11_d_iy0;
  int32_T c11_i291;
  real_T c11_e_A[16];
  int32_T c11_b_ia0;
  int32_T c11_i292;
  int32_T c11_c_m;
  int32_T c11_c_n;
  int32_T c11_e_ix0;
  int32_T c11_e_iy0;
  int32_T c11_i293;
  real_T c11_f_A[16];
  int32_T c11_c_ia0;
  int32_T c11_i294;
  int32_T c11_i295;
  real_T c11_g_A[16];
  for (c11_i279 = 0; c11_i279 < 16; c11_i279 = c11_i279 + 1) {
    c11_b_A[c11_i279] = c11_A[c11_i279];
  }

  c11_eps(chartInstance);
  for (c11_i280 = 0; c11_i280 < 4; c11_i280 = c11_i280 + 1) {
    c11_ipiv[c11_i280] = 1 + c11_i280;
  }

  *c11_info = 0;
  for (c11_j = 1; c11_j < 4; c11_j = c11_j + 1) {
    c11_b_j = c11_j;
    c11_a = c11_b_j;
    c11_jm1 = c11_a - 1;
    c11_b = c11_b_j;
    c11_mmj = 4 - c11_b;
    c11_b_a = c11_jm1;
    c11_c = c11_b_a * 5;
    c11_b_b = c11_c;
    c11_jj = 1 + c11_b_b;
    c11_c_a = c11_jj;
    c11_jp1j = c11_c_a + 1;
    c11_d_a = c11_mmj;
    c11_b_c = c11_d_a + 1;
    for (c11_i281 = 0; c11_i281 < 16; c11_i281 = c11_i281 + 1) {
      c11_c_A[c11_i281] = c11_b_A[c11_i281];
    }

    c11_e_a = c11_eml_ixamax(chartInstance, c11_b_c, c11_c_A, c11_jj);
    c11_jpiv_offset = c11_e_a - 1;
    c11_f_a = c11_jj;
    c11_c_b = c11_jpiv_offset;
    c11_jpiv = c11_f_a + c11_c_b;
    if (c11_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_jpiv, 1, 16, 1, 0) - 1] !=
        0.0) {
      if ((real_T)c11_jpiv_offset != 0.0) {
        c11_g_a = c11_b_j;
        c11_d_b = c11_jpiv_offset;
        c11_c_c = c11_g_a + c11_d_b;
        c11_ipiv[c11_b_j - 1] = c11_c_c;
        c11_e_b = c11_jm1;
        c11_jrow = 1 + c11_e_b;
        c11_h_a = c11_jrow;
        c11_f_b = c11_jpiv_offset;
        c11_jprow = c11_h_a + c11_f_b;
        for (c11_i282 = 0; c11_i282 < 16; c11_i282 = c11_i282 + 1) {
          c11_x[c11_i282] = c11_b_A[c11_i282];
        }

        c11_ix0 = c11_jrow;
        c11_iy0 = c11_jprow;
        for (c11_i283 = 0; c11_i283 < 16; c11_i283 = c11_i283 + 1) {
          c11_b_A[c11_i283] = c11_x[c11_i283];
        }

        for (c11_i284 = 0; c11_i284 < 16; c11_i284 = c11_i284 + 1) {
          c11_b_x[c11_i284] = c11_b_A[c11_i284];
        }

        c11_b_ix0 = c11_ix0;
        c11_b_iy0 = c11_iy0;
        for (c11_i285 = 0; c11_i285 < 16; c11_i285 = c11_i285 + 1) {
          c11_c_x[c11_i285] = c11_b_x[c11_i285];
        }

        for (c11_i286 = 0; c11_i286 < 16; c11_i286 = c11_i286 + 1) {
          c11_d_x[c11_i286] = c11_c_x[c11_i286];
        }

        c11_ceval_xswap(chartInstance, 4, c11_d_x, c11_b_ix0, 4, c11_b_iy0, 4,
                        c11_e_x);
        for (c11_i287 = 0; c11_i287 < 16; c11_i287 = c11_i287 + 1) {
          c11_c_x[c11_i287] = c11_e_x[c11_i287];
        }

        for (c11_i288 = 0; c11_i288 < 16; c11_i288 = c11_i288 + 1) {
          c11_b_A[c11_i288] = c11_c_x[c11_i288];
        }
      }

      c11_b_jp1j = c11_jp1j;
      c11_i_a = c11_mmj;
      c11_d_c = c11_i_a - 1;
      c11_j_a = c11_jp1j;
      c11_g_b = c11_d_c;
      c11_loop_ub = c11_j_a + c11_g_b;
      for (c11_i = c11_b_jp1j; c11_i <= c11_loop_ub; c11_i = c11_i + 1) {
        c11_b_i = c11_i;
        c11_f_x = c11_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_b_i, 1, 16, 1, 0)
          - 1];
        c11_y = c11_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_jj, 1, 16, 1, 0) - 1];
        c11_g_x = c11_f_x;
        c11_b_y = c11_y;
        c11_z = c11_g_x / c11_b_y;
        c11_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_b_i, 1, 16, 1, 0) - 1] =
          c11_z;
      }
    } else {
      *c11_info = c11_b_j;
    }

    c11_h_b = c11_b_j;
    c11_e_c = 4 - c11_h_b;
    c11_k_a = c11_jj;
    c11_f_c = c11_k_a + 4;
    c11_l_a = c11_jj;
    c11_g_c = c11_l_a + 5;
    c11_m = c11_mmj;
    c11_n = c11_e_c;
    c11_c_ix0 = c11_jp1j;
    c11_c_iy0 = c11_f_c;
    for (c11_i289 = 0; c11_i289 < 16; c11_i289 = c11_i289 + 1) {
      c11_d_A[c11_i289] = c11_b_A[c11_i289];
    }

    c11_ia0 = c11_g_c;
    for (c11_i290 = 0; c11_i290 < 16; c11_i290 = c11_i290 + 1) {
      c11_b_A[c11_i290] = c11_d_A[c11_i290];
    }

    c11_b_m = c11_m;
    c11_b_n = c11_n;
    c11_d_ix0 = c11_c_ix0;
    c11_d_iy0 = c11_c_iy0;
    for (c11_i291 = 0; c11_i291 < 16; c11_i291 = c11_i291 + 1) {
      c11_e_A[c11_i291] = c11_b_A[c11_i291];
    }

    c11_b_ia0 = c11_ia0;
    for (c11_i292 = 0; c11_i292 < 16; c11_i292 = c11_i292 + 1) {
      c11_b_A[c11_i292] = c11_e_A[c11_i292];
    }

    c11_c_m = c11_b_m;
    c11_c_n = c11_b_n;
    c11_e_ix0 = c11_d_ix0;
    c11_e_iy0 = c11_d_iy0;
    for (c11_i293 = 0; c11_i293 < 16; c11_i293 = c11_i293 + 1) {
      c11_f_A[c11_i293] = c11_b_A[c11_i293];
    }

    c11_c_ia0 = c11_b_ia0;
    for (c11_i294 = 0; c11_i294 < 16; c11_i294 = c11_i294 + 1) {
      c11_b_A[c11_i294] = c11_f_A[c11_i294];
    }

    if ((real_T)c11_c_m < 1.0) {
    } else if ((real_T)c11_c_n < 1.0) {
    } else {
      for (c11_i295 = 0; c11_i295 < 16; c11_i295 = c11_i295 + 1) {
        c11_g_A[c11_i295] = c11_b_A[c11_i295];
      }

      c11_ceval_xger(chartInstance, c11_c_m, c11_c_n, -1.0, c11_e_ix0, 1,
                     c11_e_iy0, 4, c11_g_A, c11_c_ia0, 4, c11_b_A);
      goto label_1;
    }

   label_1:
    ;
  }

  if ((real_T)*c11_info == 0.0) {
    if (!(c11_b_A[15] != 0.0)) {
      *c11_info = 4;
      return;
    }
  }
}

static int32_T c11_eml_ixamax(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[16], int32_T c11_ix0)
{
  int32_T c11_b_n;
  int32_T c11_i296;
  real_T c11_b_x[16];
  int32_T c11_b_ix0;
  int32_T c11_i297;
  real_T c11_c_x[16];
  c11_b_n = c11_n;
  for (c11_i296 = 0; c11_i296 < 16; c11_i296 = c11_i296 + 1) {
    c11_b_x[c11_i296] = c11_x[c11_i296];
  }

  c11_b_ix0 = c11_ix0;
  for (c11_i297 = 0; c11_i297 < 16; c11_i297 = c11_i297 + 1) {
    c11_c_x[c11_i297] = c11_b_x[c11_i297];
  }

  return c11_ceval_ixamax(chartInstance, c11_b_n, c11_c_x, c11_b_ix0, 1);
}

static int32_T c11_ceval_ixamax(SFc11_KinConInstanceStruct *chartInstance,
  int32_T c11_n, real_T c11_x[16], int32_T c11_ix0, int32_T
  c11_incx)
{
  return idamax32(&c11_n, &c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_ix0, 1, 16,
    1, 0) - 1], &c11_incx);
}

static void c11_ceval_xswap(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[16], int32_T c11_ix0, int32_T
  c11_incx, int32_T c11_iy0, int32_T c11_incy, real_T c11_b_x[16])
{
  int32_T c11_i298;

  /* Empty Loop. */
  for (c11_i298 = 0; c11_i298 < 16; c11_i298 = c11_i298 + 1) {
    c11_b_x[c11_i298] = c11_x[c11_i298];
  }

  dswap32(&c11_n, &c11_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_ix0, 1, 16, 1, 0)
          - 1], &c11_incx, &c11_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", c11_iy0, 1, 16, 1, 0) - 1], &c11_incy);
}

static void c11_ceval_xger(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_m, int32_T c11_n, real_T c11_alpha1, int32_T
  c11_ix0, int32_T c11_incx, int32_T c11_iy0, int32_T c11_incy, real_T c11_A[16],
  int32_T c11_ia0, int32_T c11_lda, real_T c11_b_A[16]
  )
{
  int32_T c11_i299;
  for (c11_i299 = 0; c11_i299 < 16; c11_i299 = c11_i299 + 1) {
    c11_b_A[c11_i299] = c11_A[c11_i299];
  }

  dger32(&c11_m, &c11_n, &c11_alpha1, &c11_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          c11_ix0, 1, 16, 1, 0) - 1], &c11_incx, &c11_b_A[
         _SFD_EML_ARRAY_BOUNDS_CHECK("", c11_iy0, 1, 16, 1, 0) - 1], &c11_incy,
         &c11_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_ia0, 1, 16, 1, 0
          ) - 1], &c11_lda);
}

static void c11_eml_warning(SFc11_KinConInstanceStruct *chartInstance)
{
  int32_T c11_i300;
  static char_T c11_cv0[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i', 'n',
    'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i',
    'x' };

  char_T c11_u[21];
  const mxArray *c11_y = NULL;
  int32_T c11_i301;
  static char_T c11_cv1[40] = { 'M', 'a', 't', 'r', 'i', 'x', ' ', 'i', 's', ' ',
    's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', ' ', 't',
    'o', ' ', 'w', 'o', 'r', 'k', 'i', 'n', 'g', ' ', 'p', 'r', 'e', 'c', 'i',
    's', 'i', 'o', 'n', '.' };

  char_T c11_b_u[40];
  const mxArray *c11_b_y = NULL;
  for (c11_i300 = 0; c11_i300 < 21; c11_i300 = c11_i300 + 1) {
    c11_u[c11_i300] = c11_cv0[c11_i300];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 21));
  for (c11_i301 = 0; c11_i301 < 40; c11_i301 = c11_i301 + 1) {
    c11_b_u[c11_i301] = c11_cv1[c11_i301];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1, 40));
  sf_mex_call_debug("warning", 0U, 2U, 14, c11_y, 14, c11_b_y);
}

static void c11_b_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance)
{
}

static void c11_c_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance)
{
}

static void c11_eml_xtrsm(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_A[16], real_T c11_B[16], real_T c11_b_B[16])
{
  int32_T c11_i302;
  int32_T c11_i303;
  real_T c11_b_A[16];
  int32_T c11_i304;
  real_T c11_c_B[16];
  int32_T c11_i305;
  int32_T c11_i306;
  real_T c11_c_A[16];
  int32_T c11_i307;
  real_T c11_d_B[16];
  int32_T c11_i308;
  int32_T c11_j;
  int32_T c11_b_j;
  int32_T c11_a;
  int32_T c11_c;
  int32_T c11_b;
  int32_T c11_b_c;
  int32_T c11_b_b;
  int32_T c11_jBcol;
  int32_T c11_k;
  int32_T c11_b_k;
  int32_T c11_b_a;
  int32_T c11_c_c;
  int32_T c11_c_b;
  int32_T c11_d_c;
  int32_T c11_d_b;
  int32_T c11_kAcol;
  int32_T c11_c_a;
  int32_T c11_e_b;
  int32_T c11_e_c;
  int32_T c11_d_a;
  int32_T c11_f_b;
  int32_T c11_f_c;
  int32_T c11_e_a;
  int32_T c11_g_b;
  int32_T c11_g_c;
  int32_T c11_f_a;
  int32_T c11_h_b;
  int32_T c11_h_c;
  real_T c11_x;
  real_T c11_y;
  real_T c11_b_x;
  real_T c11_b_y;
  real_T c11_z;
  int32_T c11_g_a;
  int32_T c11_loop_ub;
  int32_T c11_i;
  int32_T c11_b_i;
  int32_T c11_h_a;
  int32_T c11_i_b;
  int32_T c11_i_c;
  int32_T c11_i_a;
  int32_T c11_j_b;
  int32_T c11_j_c;
  int32_T c11_j_a;
  int32_T c11_k_b;
  int32_T c11_k_c;
  int32_T c11_k_a;
  int32_T c11_l_b;
  int32_T c11_l_c;
  for (c11_i302 = 0; c11_i302 < 16; c11_i302 = c11_i302 + 1) {
    c11_b_B[c11_i302] = c11_B[c11_i302];
  }

  for (c11_i303 = 0; c11_i303 < 16; c11_i303 = c11_i303 + 1) {
    c11_b_A[c11_i303] = c11_A[c11_i303];
  }

  for (c11_i304 = 0; c11_i304 < 16; c11_i304 = c11_i304 + 1) {
    c11_c_B[c11_i304] = c11_b_B[c11_i304];
  }

  for (c11_i305 = 0; c11_i305 < 16; c11_i305 = c11_i305 + 1) {
    c11_b_B[c11_i305] = c11_c_B[c11_i305];
  }

  for (c11_i306 = 0; c11_i306 < 16; c11_i306 = c11_i306 + 1) {
    c11_c_A[c11_i306] = c11_b_A[c11_i306];
  }

  for (c11_i307 = 0; c11_i307 < 16; c11_i307 = c11_i307 + 1) {
    c11_d_B[c11_i307] = c11_b_B[c11_i307];
  }

  for (c11_i308 = 0; c11_i308 < 16; c11_i308 = c11_i308 + 1) {
    c11_b_B[c11_i308] = c11_d_B[c11_i308];
  }

  c11_c_eml_scalar_eg(chartInstance);
  for (c11_j = 1; c11_j <= 4; c11_j = c11_j + 1) {
    c11_b_j = c11_j;
    c11_a = c11_b_j;
    c11_c = c11_a - 1;
    c11_b = c11_c;
    c11_b_c = c11_b << 2;
    c11_b_b = c11_b_c;
    c11_jBcol = c11_b_b;
    for (c11_k = 4; c11_k > 0; c11_k = c11_k + -1) {
      c11_b_k = c11_k;
      c11_b_a = c11_b_k;
      c11_c_c = c11_b_a - 1;
      c11_c_b = c11_c_c;
      c11_d_c = c11_c_b << 2;
      c11_d_b = c11_d_c;
      c11_kAcol = c11_d_b;
      c11_c_a = c11_b_k;
      c11_e_b = c11_jBcol;
      c11_e_c = c11_c_a + c11_e_b;
      if (c11_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_e_c, 1, 16, 1, 0) - 1] !=
          0.0) {
        c11_d_a = c11_b_k;
        c11_f_b = c11_jBcol;
        c11_f_c = c11_d_a + c11_f_b;
        c11_e_a = c11_b_k;
        c11_g_b = c11_jBcol;
        c11_g_c = c11_e_a + c11_g_b;
        c11_f_a = c11_b_k;
        c11_h_b = c11_kAcol;
        c11_h_c = c11_f_a + c11_h_b;
        c11_x = c11_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_g_c, 1, 16, 1, 0) -
          1];
        c11_y = c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_h_c, 1, 16, 1, 0) -
          1];
        c11_b_x = c11_x;
        c11_b_y = c11_y;
        c11_z = c11_b_x / c11_b_y;
        c11_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_f_c, 1, 16, 1, 0) - 1] =
          c11_z;
        c11_g_a = c11_b_k;
        c11_loop_ub = c11_g_a - 1;
        for (c11_i = 1; c11_i <= c11_loop_ub; c11_i = c11_i + 1) {
          c11_b_i = c11_i;
          c11_h_a = c11_b_i;
          c11_i_b = c11_jBcol;
          c11_i_c = c11_h_a + c11_i_b;
          c11_i_a = c11_b_i;
          c11_j_b = c11_jBcol;
          c11_j_c = c11_i_a + c11_j_b;
          c11_j_a = c11_b_k;
          c11_k_b = c11_jBcol;
          c11_k_c = c11_j_a + c11_k_b;
          c11_k_a = c11_b_i;
          c11_l_b = c11_kAcol;
          c11_l_c = c11_k_a + c11_l_b;
          c11_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_i_c, 1, 16, 1, 0) - 1] =
            c11_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_j_c, 1, 16, 1, 0)
            - 1] - c11_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_k_c, 1, 16, 1, 0)
            - 1] * c11_c_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_l_c, 1, 16
            , 1, 0) - 1];
        }
      }
    }
  }
}

static void c11_d_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance)
{
}

static real_T c11_atan2(SFc11_KinConInstanceStruct *chartInstance, real_T c11_y,
  real_T c11_x)
{
  real_T c11_b_y;
  real_T c11_b_x;
  c11_eml_scalar_eg(chartInstance);
  c11_b_y = c11_y;
  c11_b_x = c11_x;
  return muDoubleScalarAtan2(c11_b_y, c11_b_x);
}

static boolean_T c11_isInRange(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_x, real_T c11_xmin, real_T c11_xmax)
{
  boolean_T c11_isIn;
  uint32_T c11_debug_family_var_map[6];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  real_T c11_A;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_y;
  real_T c11_a;
  boolean_T c11_b3;
  boolean_T c11_b4;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c11_b_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c11_x, c11_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c11_xmin, c11_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_xmax, c11_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c11_isIn, c11_i_sf_marshall, 5U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0, 141);
  c11_A = c11_x;
  c11_b_x = c11_A;
  c11_c_x = c11_b_x;
  c11_d_x = c11_c_x;
  c11_y = c11_d_x / 3.1415926535897931;
  c11_a = c11_y;
  c11_x = c11_a * 180.0;
  _SFD_SCRIPT_CALL(0, 142);
  c11_b3 = (c11_x >= c11_xmin);
  c11_b4 = (c11_x <= c11_xmax);
  c11_isIn = (c11_b3 && c11_b4);
  _SFD_SCRIPT_CALL(0, -142);
  sf_debug_symbol_scope_pop();
  return c11_isIn;
}

static void c11_expWre(SFc11_KinConInstanceStruct *chartInstance, real_T c11_kx
  [6], real_T c11_theta, real_T c11_g[16])
{
  uint32_T c11_debug_family_var_map[9];
  static const char *c11_sv2[9] = { "v", "w", "R", "p", "nargin", "nargout",
    "kx", "theta", "g" };

  real_T c11_v[3];
  real_T c11_w[3];
  real_T c11_R[9];
  real_T c11_p[3];
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i309;
  int32_T c11_i310;
  real_T c11_dv23[9];
  int32_T c11_i311;
  int32_T c11_i312;
  real_T c11_a[3];
  real_T c11_b;
  int32_T c11_i313;
  int32_T c11_i314;
  real_T c11_b_w[3];
  real_T c11_dv24[9];
  int32_T c11_i315;
  real_T c11_dv25[9];
  int32_T c11_i316;
  real_T c11_b_a[9];
  int32_T c11_i317;
  real_T c11_c_w[3];
  int32_T c11_i318;
  real_T c11_b_v[3];
  real_T c11_b_b[3];
  int32_T c11_i319;
  real_T c11_A[9];
  int32_T c11_i320;
  real_T c11_B[3];
  int32_T c11_i321;
  real_T c11_b_A[9];
  int32_T c11_i322;
  real_T c11_b_B[3];
  int32_T c11_i323;
  real_T c11_c_A[9];
  int32_T c11_i324;
  real_T c11_c_B[3];
  int32_T c11_i325;
  real_T c11_y[3];
  int32_T c11_i326;
  int32_T c11_i327;
  int32_T c11_i328;
  real_T c11_c_a[3];
  int32_T c11_i329;
  real_T c11_c_b[3];
  int32_T c11_i330;
  int32_T c11_i331;
  int32_T c11_i332;
  real_T c11_b_y[9];
  int32_T c11_i333;
  real_T c11_d_a[9];
  int32_T c11_i334;
  real_T c11_d_b[3];
  int32_T c11_i335;
  real_T c11_d_A[9];
  int32_T c11_i336;
  real_T c11_d_B[3];
  int32_T c11_i337;
  real_T c11_e_A[9];
  int32_T c11_i338;
  real_T c11_e_B[3];
  int32_T c11_i339;
  real_T c11_f_A[9];
  int32_T c11_i340;
  real_T c11_f_B[3];
  int32_T c11_i341;
  real_T c11_c_y[3];
  int32_T c11_i342;
  int32_T c11_i343;
  int32_T c11_i344;
  real_T c11_e_a[3];
  real_T c11_e_b;
  int32_T c11_i345;
  real_T c11_d_y[3];
  int32_T c11_i346;
  int32_T c11_i347;
  int32_T c11_i348;
  int32_T c11_i349;
  int32_T c11_i350;
  int32_T c11_i351;
  int32_T c11_i352;
  int32_T c11_i353;
  static real_T c11_dv26[4] = { 0.0, 0.0, 0.0, 1.0 };

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c11_sv2, c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_v, c11_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_w, c11_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_R, c11_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_p, c11_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_kx, c11_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_theta, c11_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c11_g, c11_h_sf_marshall, 8U);
  CV_SCRIPT_FCN(1, 0);

  /*  exponential of the wrench  */
  _SFD_SCRIPT_CALL(1, 5);
  CV_SCRIPT_IF(1, 0, c11_length(chartInstance) != 6.0);
  _SFD_SCRIPT_CALL(1, 9);
  for (c11_i309 = 0; c11_i309 < 3; c11_i309 = c11_i309 + 1) {
    c11_v[c11_i309] = c11_kx[c11_i309];
  }

  _SFD_SCRIPT_CALL(1, 10);
  for (c11_i310 = 0; c11_i310 < 3; c11_i310 = c11_i310 + 1) {
    c11_w[c11_i310] = c11_kx[c11_i310 + 3];
  }

  _SFD_SCRIPT_CALL(1, 12);
  if (CV_SCRIPT_COND(1, 0, c11_w[0] == 0.0)) {
    if (CV_SCRIPT_COND(1, 1, c11_w[1] == 0.0)) {
      if (CV_SCRIPT_COND(1, 2, c11_w[2] == 0.0)) {
        CV_SCRIPT_MCDC(1, 0, TRUE);
        CV_SCRIPT_IF(1, 1, TRUE);
        _SFD_SCRIPT_CALL(1, 13);
        c11_eye(chartInstance, c11_dv23);
        for (c11_i311 = 0; c11_i311 < 9; c11_i311 = c11_i311 + 1) {
          c11_R[c11_i311] = c11_dv23[c11_i311];
        }

        _SFD_SCRIPT_CALL(1, 14);
        for (c11_i312 = 0; c11_i312 < 3; c11_i312 = c11_i312 + 1) {
          c11_a[c11_i312] = c11_v[c11_i312];
        }

        c11_b = c11_theta;
        for (c11_i313 = 0; c11_i313 < 3; c11_i313 = c11_i313 + 1) {
          c11_p[c11_i313] = c11_a[c11_i313] * c11_b;
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
  for (c11_i314 = 0; c11_i314 < 3; c11_i314 = c11_i314 + 1) {
    c11_b_w[c11_i314] = c11_w[c11_i314];
  }

  c11_expRot(chartInstance, c11_b_w, c11_theta, c11_dv24);
  for (c11_i315 = 0; c11_i315 < 9; c11_i315 = c11_i315 + 1) {
    c11_R[c11_i315] = c11_dv24[c11_i315];
  }

  _SFD_SCRIPT_CALL(1, 17);
  c11_eye(chartInstance, c11_dv25);
  for (c11_i316 = 0; c11_i316 < 9; c11_i316 = c11_i316 + 1) {
    c11_b_a[c11_i316] = c11_dv25[c11_i316] - c11_R[c11_i316];
  }

  for (c11_i317 = 0; c11_i317 < 3; c11_i317 = c11_i317 + 1) {
    c11_c_w[c11_i317] = c11_w[c11_i317];
  }

  for (c11_i318 = 0; c11_i318 < 3; c11_i318 = c11_i318 + 1) {
    c11_b_v[c11_i318] = c11_v[c11_i318];
  }

  c11_cross(chartInstance, c11_c_w, c11_b_v, c11_b_b);
  c11_f_eml_scalar_eg(chartInstance);
  c11_f_eml_scalar_eg(chartInstance);
  for (c11_i319 = 0; c11_i319 < 9; c11_i319 = c11_i319 + 1) {
    c11_A[c11_i319] = c11_b_a[c11_i319];
  }

  for (c11_i320 = 0; c11_i320 < 3; c11_i320 = c11_i320 + 1) {
    c11_B[c11_i320] = c11_b_b[c11_i320];
  }

  for (c11_i321 = 0; c11_i321 < 9; c11_i321 = c11_i321 + 1) {
    c11_b_A[c11_i321] = c11_A[c11_i321];
  }

  for (c11_i322 = 0; c11_i322 < 3; c11_i322 = c11_i322 + 1) {
    c11_b_B[c11_i322] = c11_B[c11_i322];
  }

  for (c11_i323 = 0; c11_i323 < 9; c11_i323 = c11_i323 + 1) {
    c11_c_A[c11_i323] = c11_b_A[c11_i323];
  }

  for (c11_i324 = 0; c11_i324 < 3; c11_i324 = c11_i324 + 1) {
    c11_c_B[c11_i324] = c11_b_B[c11_i324];
  }

  for (c11_i325 = 0; c11_i325 < 3; c11_i325 = c11_i325 + 1) {
    c11_y[c11_i325] = 0.0;
    c11_i326 = 0;
    for (c11_i327 = 0; c11_i327 < 3; c11_i327 = c11_i327 + 1) {
      c11_y[c11_i325] = c11_y[c11_i325] + c11_c_A[c11_i326 + c11_i325] *
        c11_c_B[c11_i327];
      c11_i326 = c11_i326 + 3;
    }
  }

  for (c11_i328 = 0; c11_i328 < 3; c11_i328 = c11_i328 + 1) {
    c11_c_a[c11_i328] = c11_w[c11_i328];
  }

  for (c11_i329 = 0; c11_i329 < 3; c11_i329 = c11_i329 + 1) {
    c11_c_b[c11_i329] = c11_w[c11_i329];
  }

  c11_i330 = 0;
  for (c11_i331 = 0; c11_i331 < 3; c11_i331 = c11_i331 + 1) {
    for (c11_i332 = 0; c11_i332 < 3; c11_i332 = c11_i332 + 1) {
      c11_b_y[c11_i332 + c11_i330] = c11_c_a[c11_i332] * c11_c_b[c11_i331];
    }

    c11_i330 = c11_i330 + 3;
  }

  for (c11_i333 = 0; c11_i333 < 9; c11_i333 = c11_i333 + 1) {
    c11_d_a[c11_i333] = c11_b_y[c11_i333];
  }

  for (c11_i334 = 0; c11_i334 < 3; c11_i334 = c11_i334 + 1) {
    c11_d_b[c11_i334] = c11_v[c11_i334];
  }

  c11_f_eml_scalar_eg(chartInstance);
  c11_f_eml_scalar_eg(chartInstance);
  for (c11_i335 = 0; c11_i335 < 9; c11_i335 = c11_i335 + 1) {
    c11_d_A[c11_i335] = c11_d_a[c11_i335];
  }

  for (c11_i336 = 0; c11_i336 < 3; c11_i336 = c11_i336 + 1) {
    c11_d_B[c11_i336] = c11_d_b[c11_i336];
  }

  for (c11_i337 = 0; c11_i337 < 9; c11_i337 = c11_i337 + 1) {
    c11_e_A[c11_i337] = c11_d_A[c11_i337];
  }

  for (c11_i338 = 0; c11_i338 < 3; c11_i338 = c11_i338 + 1) {
    c11_e_B[c11_i338] = c11_d_B[c11_i338];
  }

  for (c11_i339 = 0; c11_i339 < 9; c11_i339 = c11_i339 + 1) {
    c11_f_A[c11_i339] = c11_e_A[c11_i339];
  }

  for (c11_i340 = 0; c11_i340 < 3; c11_i340 = c11_i340 + 1) {
    c11_f_B[c11_i340] = c11_e_B[c11_i340];
  }

  for (c11_i341 = 0; c11_i341 < 3; c11_i341 = c11_i341 + 1) {
    c11_c_y[c11_i341] = 0.0;
    c11_i342 = 0;
    for (c11_i343 = 0; c11_i343 < 3; c11_i343 = c11_i343 + 1) {
      c11_c_y[c11_i341] = c11_c_y[c11_i341] + c11_f_A[c11_i342 + c11_i341] *
        c11_f_B[c11_i343];
      c11_i342 = c11_i342 + 3;
    }
  }

  for (c11_i344 = 0; c11_i344 < 3; c11_i344 = c11_i344 + 1) {
    c11_e_a[c11_i344] = c11_c_y[c11_i344];
  }

  c11_e_b = c11_theta;
  for (c11_i345 = 0; c11_i345 < 3; c11_i345 = c11_i345 + 1) {
    c11_d_y[c11_i345] = c11_e_a[c11_i345] * c11_e_b;
  }

  for (c11_i346 = 0; c11_i346 < 3; c11_i346 = c11_i346 + 1) {
    c11_p[c11_i346] = c11_y[c11_i346] + c11_d_y[c11_i346];
  }

 label_1:
  ;
  _SFD_SCRIPT_CALL(1, 19);
  c11_i347 = 0;
  c11_i348 = 0;
  for (c11_i349 = 0; c11_i349 < 3; c11_i349 = c11_i349 + 1) {
    for (c11_i350 = 0; c11_i350 < 3; c11_i350 = c11_i350 + 1) {
      c11_g[c11_i350 + c11_i347] = c11_R[c11_i350 + c11_i348];
    }

    c11_i347 = c11_i347 + 4;
    c11_i348 = c11_i348 + 3;
  }

  for (c11_i351 = 0; c11_i351 < 3; c11_i351 = c11_i351 + 1) {
    c11_g[c11_i351 + 12] = c11_p[c11_i351];
  }

  c11_i352 = 0;
  for (c11_i353 = 0; c11_i353 < 4; c11_i353 = c11_i353 + 1) {
    c11_g[c11_i352 + 3] = c11_dv26[c11_i353];
    c11_i352 = c11_i352 + 4;
  }

  _SFD_SCRIPT_CALL(1, -19);
  sf_debug_symbol_scope_pop();
}

static real_T c11_length(SFc11_KinConInstanceStruct *chartInstance)
{
  real_T c11_n;
  real_T c11_k;
  real_T c11_b_k;
  c11_n = 0.0;
  for (c11_k = 1.0; c11_k <= 2.0; c11_k = c11_k + 1.0) {
    c11_b_k = c11_k;
    if (6.0 + -5.0 * (real_T)((int32_T)c11_b_k - 1) > c11_n) {
      c11_n = 6.0 + -5.0 * (real_T)((int32_T)c11_b_k - 1);
    }
  }

  return c11_n;
}

static void c11_eye(SFc11_KinConInstanceStruct *chartInstance, real_T c11_I[9])
{
  int32_T c11_i354;
  int32_T c11_i;
  int32_T c11_b_i;
  for (c11_i354 = 0; c11_i354 < 9; c11_i354 = c11_i354 + 1) {
    c11_I[c11_i354] = 0.0;
  }

  for (c11_i = 1; c11_i < 4; c11_i = c11_i + 1) {
    c11_b_i = c11_i;
    c11_I[(c11_b_i - 1) + 3 * (c11_b_i - 1)] = 1.0;
  }
}

static void c11_expRot(SFc11_KinConInstanceStruct *chartInstance, real_T c11_w[3],
  real_T c11_theta, real_T c11_R[9])
{
  uint32_T c11_debug_family_var_map[6];
  static const char *c11_sv3[6] = { "wh", "nargin", "nargout", "w", "theta", "R"
  };

  real_T c11_wh[9];
  real_T c11_nargin = 2.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i355;
  real_T c11_b_w[3];
  uint32_T c11_b_debug_family_var_map[4];
  static const char *c11_sv4[4] = { "nargin", "nargout", "w", "wh" };

  real_T c11_b_nargin = 1.0;
  real_T c11_b_nargout = 1.0;
  real_T c11_n;
  real_T c11_k;
  real_T c11_b_k;
  int32_T c11_i356;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  int32_T c11_i357;
  real_T c11_a[9];
  real_T c11_b;
  int32_T c11_i358;
  real_T c11_y[9];
  int32_T c11_i359;
  real_T c11_b_a[9];
  int32_T c11_i360;
  real_T c11_b_b[9];
  int32_T c11_i361;
  real_T c11_A[9];
  int32_T c11_i362;
  real_T c11_B[9];
  int32_T c11_i363;
  real_T c11_b_A[9];
  int32_T c11_i364;
  real_T c11_b_B[9];
  int32_T c11_i365;
  real_T c11_c_A[9];
  int32_T c11_i366;
  real_T c11_c_B[9];
  int32_T c11_i367;
  int32_T c11_i368;
  int32_T c11_i369;
  real_T c11_b_y[9];
  int32_T c11_i370;
  int32_T c11_i371;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_x;
  int32_T c11_i372;
  real_T c11_c_a[9];
  real_T c11_c_b;
  int32_T c11_i373;
  real_T c11_c_y[9];
  real_T c11_dv27[9];
  int32_T c11_i374;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c11_sv3, c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_wh, c11_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_w, c11_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_theta, c11_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_R, c11_c_sf_marshall, 5U);
  CV_SCRIPT_FCN(2, 0);

  /*  exponential of the skew matrix */
  /*      if(norm(w)~=1) */
  /*          error('Norm of w must be 1'); */
  /*      end */
  _SFD_SCRIPT_CALL(2, 9);
  for (c11_i355 = 0; c11_i355 < 3; c11_i355 = c11_i355 + 1) {
    c11_b_w[c11_i355] = c11_w[c11_i355];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c11_sv4, c11_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c11_b_nargin, c11_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c11_b_nargout, c11_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_b_w, c11_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_wh, c11_c_sf_marshall, 3U);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3, 3);
  c11_n = 0.0;
  for (c11_k = 1.0; c11_k <= 2.0; c11_k = c11_k + 1.0) {
    c11_b_k = c11_k;
    if (3.0 + -2.0 * (real_T)((int32_T)c11_b_k - 1) > c11_n) {
      c11_n = 3.0 + -2.0 * (real_T)((int32_T)c11_b_k - 1);
    }
  }

  CV_SCRIPT_IF(3, 0, c11_n != 3.0);

  /* wh = diag(sym('wh',[1,3])); */
  _SFD_SCRIPT_CALL(3, 8);
  for (c11_i356 = 0; c11_i356 < 9; c11_i356 = c11_i356 + 1) {
    c11_wh[c11_i356] = 0.0;
  }

  _SFD_SCRIPT_CALL(3, 9);
  c11_wh[0] = 0.0;
  _SFD_SCRIPT_CALL(3, 10);
  c11_wh[4] = 0.0;
  _SFD_SCRIPT_CALL(3, 11);
  c11_wh[8] = 0.0;
  _SFD_SCRIPT_CALL(3, 14);
  c11_wh[3] = -c11_b_w[2];
  _SFD_SCRIPT_CALL(3, 15);
  c11_wh[6] = c11_b_w[1];
  _SFD_SCRIPT_CALL(3, 16);
  c11_wh[1] = c11_b_w[2];
  _SFD_SCRIPT_CALL(3, 17);
  c11_wh[7] = -c11_b_w[0];
  _SFD_SCRIPT_CALL(3, 18);
  c11_wh[2] = -c11_b_w[1];
  _SFD_SCRIPT_CALL(3, 19);
  c11_wh[5] = c11_b_w[0];
  _SFD_SCRIPT_CALL(3, -19);
  sf_debug_symbol_scope_pop();
  _SFD_SCRIPT_CALL(2, 10);
  c11_x = c11_theta;
  c11_b_x = c11_x;
  c11_c_x = c11_b_x;
  c11_b_x = c11_c_x;
  c11_b_x = muDoubleScalarSin(c11_b_x);
  for (c11_i357 = 0; c11_i357 < 9; c11_i357 = c11_i357 + 1) {
    c11_a[c11_i357] = c11_wh[c11_i357];
  }

  c11_b = c11_b_x;
  for (c11_i358 = 0; c11_i358 < 9; c11_i358 = c11_i358 + 1) {
    c11_y[c11_i358] = c11_a[c11_i358] * c11_b;
  }

  for (c11_i359 = 0; c11_i359 < 9; c11_i359 = c11_i359 + 1) {
    c11_b_a[c11_i359] = c11_wh[c11_i359];
  }

  for (c11_i360 = 0; c11_i360 < 9; c11_i360 = c11_i360 + 1) {
    c11_b_b[c11_i360] = c11_wh[c11_i360];
  }

  c11_e_eml_scalar_eg(chartInstance);
  c11_e_eml_scalar_eg(chartInstance);
  for (c11_i361 = 0; c11_i361 < 9; c11_i361 = c11_i361 + 1) {
    c11_A[c11_i361] = c11_b_a[c11_i361];
  }

  for (c11_i362 = 0; c11_i362 < 9; c11_i362 = c11_i362 + 1) {
    c11_B[c11_i362] = c11_b_b[c11_i362];
  }

  for (c11_i363 = 0; c11_i363 < 9; c11_i363 = c11_i363 + 1) {
    c11_b_A[c11_i363] = c11_A[c11_i363];
  }

  for (c11_i364 = 0; c11_i364 < 9; c11_i364 = c11_i364 + 1) {
    c11_b_B[c11_i364] = c11_B[c11_i364];
  }

  for (c11_i365 = 0; c11_i365 < 9; c11_i365 = c11_i365 + 1) {
    c11_c_A[c11_i365] = c11_b_A[c11_i365];
  }

  for (c11_i366 = 0; c11_i366 < 9; c11_i366 = c11_i366 + 1) {
    c11_c_B[c11_i366] = c11_b_B[c11_i366];
  }

  for (c11_i367 = 0; c11_i367 < 3; c11_i367 = c11_i367 + 1) {
    c11_i368 = 0;
    for (c11_i369 = 0; c11_i369 < 3; c11_i369 = c11_i369 + 1) {
      c11_b_y[c11_i368 + c11_i367] = 0.0;
      c11_i370 = 0;
      for (c11_i371 = 0; c11_i371 < 3; c11_i371 = c11_i371 + 1) {
        c11_b_y[c11_i368 + c11_i367] = c11_b_y[c11_i368 + c11_i367] +
          c11_c_A[c11_i370 + c11_i367] * c11_c_B[c11_i371 + c11_i368];
        c11_i370 = c11_i370 + 3;
      }

      c11_i368 = c11_i368 + 3;
    }
  }

  c11_d_x = c11_theta;
  c11_e_x = c11_d_x;
  c11_f_x = c11_e_x;
  c11_e_x = c11_f_x;
  c11_e_x = muDoubleScalarCos(c11_e_x);
  for (c11_i372 = 0; c11_i372 < 9; c11_i372 = c11_i372 + 1) {
    c11_c_a[c11_i372] = c11_b_y[c11_i372];
  }

  c11_c_b = 1.0 - c11_e_x;
  for (c11_i373 = 0; c11_i373 < 9; c11_i373 = c11_i373 + 1) {
    c11_c_y[c11_i373] = c11_c_a[c11_i373] * c11_c_b;
  }

  c11_eye(chartInstance, c11_dv27);
  for (c11_i374 = 0; c11_i374 < 9; c11_i374 = c11_i374 + 1) {
    c11_R[c11_i374] = (c11_dv27[c11_i374] + c11_y[c11_i374]) + c11_c_y[c11_i374];
  }

  _SFD_SCRIPT_CALL(2, -10);
  sf_debug_symbol_scope_pop();
}

static void c11_e_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance)
{
}

static void c11_f_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance)
{
}

static void c11_subPro3(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[4], real_T c11_q[4], real_T c11_d[
  4], real_T c11_theta[2], real_T *c11_Nsol)
{
  uint32_T c11_debug_family_var_map[18];
  static const char *c11_sv5[18] = { "velociy", "w", "r", "u", "v", "up", "vp",
    "dp2", "theta0", "phi", "p", "q", "d", "nargin",
    "nargout", "kx", "theta", "Nsol" };

  real_T c11_velociy[3];
  real_T c11_w[3];
  real_T c11_r[3];
  real_T c11_u[3];
  real_T c11_v[3];
  real_T c11_up[3];
  real_T c11_vp[3];
  real_T c11_dp2;
  real_T c11_theta0;
  real_T c11_phi;
  real_T c11_b_p[3];
  real_T c11_b_q[3];
  real_T c11_b_d[3];
  real_T c11_nargin = 4.0;
  real_T c11_nargout = 2.0;
  int32_T c11_i375;
  int32_T c11_i376;
  int32_T c11_i377;
  int32_T c11_i378;
  int32_T c11_i379;
  int32_T c11_i380;
  int32_T c11_i381;
  real_T c11_b_velociy[3];
  int32_T c11_i382;
  real_T c11_b_w[3];
  real_T c11_dv28[3];
  int32_T c11_i383;
  int32_T c11_i384;
  int32_T c11_i385;
  int32_T c11_i386;
  real_T c11_a[3];
  int32_T c11_i387;
  real_T c11_b[3];
  int32_T c11_i388;
  real_T c11_x[3];
  int32_T c11_i389;
  real_T c11_y[3];
  int32_T c11_i390;
  real_T c11_b_x[3];
  int32_T c11_i391;
  real_T c11_b_y[3];
  int32_T c11_i392;
  real_T c11_c_x[3];
  int32_T c11_i393;
  real_T c11_c_y[3];
  int32_T c11_i394;
  real_T c11_d_x[3];
  int32_T c11_i395;
  real_T c11_d_y[3];
  real_T c11_e_y;
  int32_T c11_i396;
  real_T c11_b_a[3];
  real_T c11_b_b;
  int32_T c11_i397;
  real_T c11_f_y[3];
  int32_T c11_i398;
  int32_T c11_i399;
  real_T c11_c_a[3];
  int32_T c11_i400;
  real_T c11_c_b[3];
  int32_T c11_i401;
  real_T c11_e_x[3];
  int32_T c11_i402;
  real_T c11_g_y[3];
  int32_T c11_i403;
  real_T c11_f_x[3];
  int32_T c11_i404;
  real_T c11_h_y[3];
  int32_T c11_i405;
  real_T c11_g_x[3];
  int32_T c11_i406;
  real_T c11_i_y[3];
  int32_T c11_i407;
  real_T c11_h_x[3];
  int32_T c11_i408;
  real_T c11_j_y[3];
  real_T c11_k_y;
  int32_T c11_i409;
  real_T c11_d_a[3];
  real_T c11_d_b;
  int32_T c11_i410;
  real_T c11_l_y[3];
  int32_T c11_i411;
  int32_T c11_i412;
  real_T c11_e_a[3];
  int32_T c11_i413;
  real_T c11_e_b[3];
  int32_T c11_i414;
  real_T c11_i_x[3];
  int32_T c11_i415;
  real_T c11_m_y[3];
  int32_T c11_i416;
  real_T c11_j_x[3];
  int32_T c11_i417;
  real_T c11_n_y[3];
  int32_T c11_i418;
  real_T c11_k_x[3];
  int32_T c11_i419;
  real_T c11_o_y[3];
  int32_T c11_i420;
  real_T c11_l_x[3];
  int32_T c11_i421;
  real_T c11_p_y[3];
  real_T c11_q_y;
  int32_T c11_i422;
  real_T c11_f_a[3];
  int32_T c11_i423;
  real_T c11_f_b[3];
  int32_T c11_i424;
  real_T c11_m_x[3];
  int32_T c11_i425;
  real_T c11_r_y[3];
  int32_T c11_i426;
  real_T c11_n_x[3];
  int32_T c11_i427;
  real_T c11_s_y[3];
  int32_T c11_i428;
  real_T c11_o_x[3];
  int32_T c11_i429;
  real_T c11_t_y[3];
  int32_T c11_i430;
  real_T c11_p_x[3];
  int32_T c11_i431;
  real_T c11_u_y[3];
  real_T c11_v_y;
  int32_T c11_i432;
  real_T c11_g_a[3];
  int32_T c11_i433;
  real_T c11_b_up[3];
  int32_T c11_i434;
  real_T c11_b_vp[3];
  real_T c11_g_b[3];
  int32_T c11_i435;
  real_T c11_q_x[3];
  int32_T c11_i436;
  real_T c11_w_y[3];
  int32_T c11_i437;
  real_T c11_r_x[3];
  int32_T c11_i438;
  real_T c11_x_y[3];
  int32_T c11_i439;
  real_T c11_s_x[3];
  int32_T c11_i440;
  real_T c11_y_y[3];
  int32_T c11_i441;
  real_T c11_t_x[3];
  int32_T c11_i442;
  real_T c11_ab_y[3];
  real_T c11_bb_y;
  int32_T c11_i443;
  real_T c11_h_a[3];
  int32_T c11_i444;
  real_T c11_h_b[3];
  int32_T c11_i445;
  real_T c11_u_x[3];
  int32_T c11_i446;
  real_T c11_cb_y[3];
  int32_T c11_i447;
  real_T c11_v_x[3];
  int32_T c11_i448;
  real_T c11_db_y[3];
  int32_T c11_i449;
  real_T c11_w_x[3];
  int32_T c11_i450;
  real_T c11_eb_y[3];
  int32_T c11_i451;
  real_T c11_x_x[3];
  int32_T c11_i452;
  real_T c11_fb_y[3];
  real_T c11_gb_y;
  int32_T c11_i453;
  real_T c11_i_a[3];
  int32_T c11_i454;
  real_T c11_i_b[3];
  int32_T c11_i455;
  real_T c11_y_x[3];
  int32_T c11_i456;
  real_T c11_hb_y[3];
  int32_T c11_i457;
  real_T c11_ab_x[3];
  int32_T c11_i458;
  real_T c11_ib_y[3];
  int32_T c11_i459;
  real_T c11_bb_x[3];
  int32_T c11_i460;
  real_T c11_jb_y[3];
  int32_T c11_i461;
  real_T c11_cb_x[3];
  int32_T c11_i462;
  real_T c11_kb_y[3];
  real_T c11_lb_y;
  int32_T c11_i463;
  real_T c11_j_a[3];
  int32_T c11_i464;
  real_T c11_j_b[3];
  int32_T c11_i465;
  real_T c11_db_x[3];
  int32_T c11_i466;
  real_T c11_mb_y[3];
  int32_T c11_i467;
  real_T c11_eb_x[3];
  int32_T c11_i468;
  real_T c11_nb_y[3];
  int32_T c11_i469;
  real_T c11_fb_x[3];
  int32_T c11_i470;
  real_T c11_ob_y[3];
  int32_T c11_i471;
  real_T c11_gb_x[3];
  int32_T c11_i472;
  real_T c11_pb_y[3];
  real_T c11_qb_y;
  int32_T c11_i473;
  real_T c11_c_up[3];
  real_T c11_k_b;
  real_T c11_rb_y;
  real_T c11_k_a;
  int32_T c11_i474;
  real_T c11_c_vp[3];
  real_T c11_l_b;
  real_T c11_sb_y;
  real_T c11_A;
  real_T c11_B;
  real_T c11_hb_x;
  real_T c11_tb_y;
  real_T c11_ib_x;
  real_T c11_ub_y;
  real_T c11_jb_x;
  real_T c11_vb_y;
  real_T c11_wb_y;
  real_T c11_kb_x;
  real_T c11_lb_x;
  sf_debug_symbol_scope_push_eml(0U, 18U, 21U, c11_sv5, c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_velociy, c11_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_w, c11_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_r, c11_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_u, c11_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c11_v, c11_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_up, c11_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_vp, c11_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_dp2, c11_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c11_theta0, c11_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c11_phi, c11_e_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c11_b_p, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_q, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(c11_b_d, c11_d_sf_marshall, MAX_uint32_T);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(c11_kx, c11_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(c11_p, c11_k_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c11_q, c11_k_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(c11_d, c11_k_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(c11_theta, c11_j_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(c11_Nsol, c11_e_sf_marshall, 17U);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4, 2);
  for (c11_i375 = 0; c11_i375 < 2; c11_i375 = c11_i375 + 1) {
    c11_theta[c11_i375] = 0.0;
  }

  _SFD_SCRIPT_CALL(4, 3);
  for (c11_i376 = 0; c11_i376 < 3; c11_i376 = c11_i376 + 1) {
    c11_b_p[c11_i376] = c11_p[c11_i376];
  }

  sf_debug_symbol_switch(10U, 10U);

  /*  col vector */
  _SFD_SCRIPT_CALL(4, 4);
  for (c11_i377 = 0; c11_i377 < 3; c11_i377 = c11_i377 + 1) {
    c11_b_q[c11_i377] = c11_q[c11_i377];
  }

  sf_debug_symbol_switch(11U, 11U);

  /*  col vector */
  _SFD_SCRIPT_CALL(4, 5);
  for (c11_i378 = 0; c11_i378 < 3; c11_i378 = c11_i378 + 1) {
    c11_b_d[c11_i378] = c11_d[c11_i378];
  }

  sf_debug_symbol_switch(12U, 12U);

  /*  col vector. */
  _SFD_SCRIPT_CALL(4, 7);
  for (c11_i379 = 0; c11_i379 < 3; c11_i379 = c11_i379 + 1) {
    c11_velociy[c11_i379] = c11_kx[c11_i379];
  }

  _SFD_SCRIPT_CALL(4, 8);
  for (c11_i380 = 0; c11_i380 < 3; c11_i380 = c11_i380 + 1) {
    c11_w[c11_i380] = c11_kx[c11_i380 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(4, 9);
  for (c11_i381 = 0; c11_i381 < 3; c11_i381 = c11_i381 + 1) {
    c11_b_velociy[c11_i381] = c11_velociy[c11_i381];
  }

  for (c11_i382 = 0; c11_i382 < 3; c11_i382 = c11_i382 + 1) {
    c11_b_w[c11_i382] = c11_w[c11_i382];
  }

  c11_cross(chartInstance, c11_b_velociy, c11_b_w, c11_dv28);
  for (c11_i383 = 0; c11_i383 < 3; c11_i383 = c11_i383 + 1) {
    c11_r[c11_i383] = -c11_dv28[c11_i383];
  }

  _SFD_SCRIPT_CALL(4, 11);
  for (c11_i384 = 0; c11_i384 < 3; c11_i384 = c11_i384 + 1) {
    c11_u[c11_i384] = c11_b_p[c11_i384] - c11_r[c11_i384];
  }

  _SFD_SCRIPT_CALL(4, 12);
  for (c11_i385 = 0; c11_i385 < 3; c11_i385 = c11_i385 + 1) {
    c11_v[c11_i385] = c11_b_q[c11_i385] - c11_r[c11_i385];
  }

  _SFD_SCRIPT_CALL(4, 14);
  for (c11_i386 = 0; c11_i386 < 3; c11_i386 = c11_i386 + 1) {
    c11_a[c11_i386] = c11_w[c11_i386];
  }

  for (c11_i387 = 0; c11_i387 < 3; c11_i387 = c11_i387 + 1) {
    c11_b[c11_i387] = c11_u[c11_i387];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i388 = 0; c11_i388 < 3; c11_i388 = c11_i388 + 1) {
    c11_x[c11_i388] = c11_a[c11_i388];
  }

  for (c11_i389 = 0; c11_i389 < 3; c11_i389 = c11_i389 + 1) {
    c11_y[c11_i389] = c11_b[c11_i389];
  }

  for (c11_i390 = 0; c11_i390 < 3; c11_i390 = c11_i390 + 1) {
    c11_b_x[c11_i390] = c11_x[c11_i390];
  }

  for (c11_i391 = 0; c11_i391 < 3; c11_i391 = c11_i391 + 1) {
    c11_b_y[c11_i391] = c11_y[c11_i391];
  }

  for (c11_i392 = 0; c11_i392 < 3; c11_i392 = c11_i392 + 1) {
    c11_c_x[c11_i392] = c11_b_x[c11_i392];
  }

  for (c11_i393 = 0; c11_i393 < 3; c11_i393 = c11_i393 + 1) {
    c11_c_y[c11_i393] = c11_b_y[c11_i393];
  }

  for (c11_i394 = 0; c11_i394 < 3; c11_i394 = c11_i394 + 1) {
    c11_d_x[c11_i394] = c11_c_x[c11_i394];
  }

  for (c11_i395 = 0; c11_i395 < 3; c11_i395 = c11_i395 + 1) {
    c11_d_y[c11_i395] = c11_c_y[c11_i395];
  }

  c11_e_y = c11_ceval_xdot(chartInstance, 3, c11_d_x, 1, 1, c11_d_y, 1, 1);
  for (c11_i396 = 0; c11_i396 < 3; c11_i396 = c11_i396 + 1) {
    c11_b_a[c11_i396] = c11_w[c11_i396];
  }

  c11_b_b = c11_e_y;
  for (c11_i397 = 0; c11_i397 < 3; c11_i397 = c11_i397 + 1) {
    c11_f_y[c11_i397] = c11_b_a[c11_i397] * c11_b_b;
  }

  for (c11_i398 = 0; c11_i398 < 3; c11_i398 = c11_i398 + 1) {
    c11_up[c11_i398] = c11_u[c11_i398] - c11_f_y[c11_i398];
  }

  _SFD_SCRIPT_CALL(4, 15);
  for (c11_i399 = 0; c11_i399 < 3; c11_i399 = c11_i399 + 1) {
    c11_c_a[c11_i399] = c11_w[c11_i399];
  }

  for (c11_i400 = 0; c11_i400 < 3; c11_i400 = c11_i400 + 1) {
    c11_c_b[c11_i400] = c11_v[c11_i400];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i401 = 0; c11_i401 < 3; c11_i401 = c11_i401 + 1) {
    c11_e_x[c11_i401] = c11_c_a[c11_i401];
  }

  for (c11_i402 = 0; c11_i402 < 3; c11_i402 = c11_i402 + 1) {
    c11_g_y[c11_i402] = c11_c_b[c11_i402];
  }

  for (c11_i403 = 0; c11_i403 < 3; c11_i403 = c11_i403 + 1) {
    c11_f_x[c11_i403] = c11_e_x[c11_i403];
  }

  for (c11_i404 = 0; c11_i404 < 3; c11_i404 = c11_i404 + 1) {
    c11_h_y[c11_i404] = c11_g_y[c11_i404];
  }

  for (c11_i405 = 0; c11_i405 < 3; c11_i405 = c11_i405 + 1) {
    c11_g_x[c11_i405] = c11_f_x[c11_i405];
  }

  for (c11_i406 = 0; c11_i406 < 3; c11_i406 = c11_i406 + 1) {
    c11_i_y[c11_i406] = c11_h_y[c11_i406];
  }

  for (c11_i407 = 0; c11_i407 < 3; c11_i407 = c11_i407 + 1) {
    c11_h_x[c11_i407] = c11_g_x[c11_i407];
  }

  for (c11_i408 = 0; c11_i408 < 3; c11_i408 = c11_i408 + 1) {
    c11_j_y[c11_i408] = c11_i_y[c11_i408];
  }

  c11_k_y = c11_ceval_xdot(chartInstance, 3, c11_h_x, 1, 1, c11_j_y, 1, 1);
  for (c11_i409 = 0; c11_i409 < 3; c11_i409 = c11_i409 + 1) {
    c11_d_a[c11_i409] = c11_w[c11_i409];
  }

  c11_d_b = c11_k_y;
  for (c11_i410 = 0; c11_i410 < 3; c11_i410 = c11_i410 + 1) {
    c11_l_y[c11_i410] = c11_d_a[c11_i410] * c11_d_b;
  }

  for (c11_i411 = 0; c11_i411 < 3; c11_i411 = c11_i411 + 1) {
    c11_vp[c11_i411] = c11_v[c11_i411] - c11_l_y[c11_i411];
  }

  _SFD_SCRIPT_CALL(4, 17);
  for (c11_i412 = 0; c11_i412 < 3; c11_i412 = c11_i412 + 1) {
    c11_e_a[c11_i412] = c11_b_d[c11_i412];
  }

  for (c11_i413 = 0; c11_i413 < 3; c11_i413 = c11_i413 + 1) {
    c11_e_b[c11_i413] = c11_b_d[c11_i413];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i414 = 0; c11_i414 < 3; c11_i414 = c11_i414 + 1) {
    c11_i_x[c11_i414] = c11_e_a[c11_i414];
  }

  for (c11_i415 = 0; c11_i415 < 3; c11_i415 = c11_i415 + 1) {
    c11_m_y[c11_i415] = c11_e_b[c11_i415];
  }

  for (c11_i416 = 0; c11_i416 < 3; c11_i416 = c11_i416 + 1) {
    c11_j_x[c11_i416] = c11_i_x[c11_i416];
  }

  for (c11_i417 = 0; c11_i417 < 3; c11_i417 = c11_i417 + 1) {
    c11_n_y[c11_i417] = c11_m_y[c11_i417];
  }

  for (c11_i418 = 0; c11_i418 < 3; c11_i418 = c11_i418 + 1) {
    c11_k_x[c11_i418] = c11_j_x[c11_i418];
  }

  for (c11_i419 = 0; c11_i419 < 3; c11_i419 = c11_i419 + 1) {
    c11_o_y[c11_i419] = c11_n_y[c11_i419];
  }

  for (c11_i420 = 0; c11_i420 < 3; c11_i420 = c11_i420 + 1) {
    c11_l_x[c11_i420] = c11_k_x[c11_i420];
  }

  for (c11_i421 = 0; c11_i421 < 3; c11_i421 = c11_i421 + 1) {
    c11_p_y[c11_i421] = c11_o_y[c11_i421];
  }

  c11_q_y = c11_ceval_xdot(chartInstance, 3, c11_l_x, 1, 1, c11_p_y, 1, 1);
  for (c11_i422 = 0; c11_i422 < 3; c11_i422 = c11_i422 + 1) {
    c11_f_a[c11_i422] = c11_w[c11_i422];
  }

  for (c11_i423 = 0; c11_i423 < 3; c11_i423 = c11_i423 + 1) {
    c11_f_b[c11_i423] = c11_b_p[c11_i423] - c11_b_q[c11_i423];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i424 = 0; c11_i424 < 3; c11_i424 = c11_i424 + 1) {
    c11_m_x[c11_i424] = c11_f_a[c11_i424];
  }

  for (c11_i425 = 0; c11_i425 < 3; c11_i425 = c11_i425 + 1) {
    c11_r_y[c11_i425] = c11_f_b[c11_i425];
  }

  for (c11_i426 = 0; c11_i426 < 3; c11_i426 = c11_i426 + 1) {
    c11_n_x[c11_i426] = c11_m_x[c11_i426];
  }

  for (c11_i427 = 0; c11_i427 < 3; c11_i427 = c11_i427 + 1) {
    c11_s_y[c11_i427] = c11_r_y[c11_i427];
  }

  for (c11_i428 = 0; c11_i428 < 3; c11_i428 = c11_i428 + 1) {
    c11_o_x[c11_i428] = c11_n_x[c11_i428];
  }

  for (c11_i429 = 0; c11_i429 < 3; c11_i429 = c11_i429 + 1) {
    c11_t_y[c11_i429] = c11_s_y[c11_i429];
  }

  for (c11_i430 = 0; c11_i430 < 3; c11_i430 = c11_i430 + 1) {
    c11_p_x[c11_i430] = c11_o_x[c11_i430];
  }

  for (c11_i431 = 0; c11_i431 < 3; c11_i431 = c11_i431 + 1) {
    c11_u_y[c11_i431] = c11_t_y[c11_i431];
  }

  c11_v_y = c11_ceval_xdot(chartInstance, 3, c11_p_x, 1, 1, c11_u_y, 1, 1);
  c11_dp2 = c11_q_y - c11_mpower(chartInstance, c11_v_y);
  _SFD_SCRIPT_CALL(4, 19);
  for (c11_i432 = 0; c11_i432 < 3; c11_i432 = c11_i432 + 1) {
    c11_g_a[c11_i432] = c11_w[c11_i432];
  }

  for (c11_i433 = 0; c11_i433 < 3; c11_i433 = c11_i433 + 1) {
    c11_b_up[c11_i433] = c11_up[c11_i433];
  }

  for (c11_i434 = 0; c11_i434 < 3; c11_i434 = c11_i434 + 1) {
    c11_b_vp[c11_i434] = c11_vp[c11_i434];
  }

  c11_cross(chartInstance, c11_b_up, c11_b_vp, c11_g_b);
  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i435 = 0; c11_i435 < 3; c11_i435 = c11_i435 + 1) {
    c11_q_x[c11_i435] = c11_g_a[c11_i435];
  }

  for (c11_i436 = 0; c11_i436 < 3; c11_i436 = c11_i436 + 1) {
    c11_w_y[c11_i436] = c11_g_b[c11_i436];
  }

  for (c11_i437 = 0; c11_i437 < 3; c11_i437 = c11_i437 + 1) {
    c11_r_x[c11_i437] = c11_q_x[c11_i437];
  }

  for (c11_i438 = 0; c11_i438 < 3; c11_i438 = c11_i438 + 1) {
    c11_x_y[c11_i438] = c11_w_y[c11_i438];
  }

  for (c11_i439 = 0; c11_i439 < 3; c11_i439 = c11_i439 + 1) {
    c11_s_x[c11_i439] = c11_r_x[c11_i439];
  }

  for (c11_i440 = 0; c11_i440 < 3; c11_i440 = c11_i440 + 1) {
    c11_y_y[c11_i440] = c11_x_y[c11_i440];
  }

  for (c11_i441 = 0; c11_i441 < 3; c11_i441 = c11_i441 + 1) {
    c11_t_x[c11_i441] = c11_s_x[c11_i441];
  }

  for (c11_i442 = 0; c11_i442 < 3; c11_i442 = c11_i442 + 1) {
    c11_ab_y[c11_i442] = c11_y_y[c11_i442];
  }

  c11_bb_y = c11_ceval_xdot(chartInstance, 3, c11_t_x, 1, 1, c11_ab_y, 1, 1);
  for (c11_i443 = 0; c11_i443 < 3; c11_i443 = c11_i443 + 1) {
    c11_h_a[c11_i443] = c11_up[c11_i443];
  }

  for (c11_i444 = 0; c11_i444 < 3; c11_i444 = c11_i444 + 1) {
    c11_h_b[c11_i444] = c11_vp[c11_i444];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i445 = 0; c11_i445 < 3; c11_i445 = c11_i445 + 1) {
    c11_u_x[c11_i445] = c11_h_a[c11_i445];
  }

  for (c11_i446 = 0; c11_i446 < 3; c11_i446 = c11_i446 + 1) {
    c11_cb_y[c11_i446] = c11_h_b[c11_i446];
  }

  for (c11_i447 = 0; c11_i447 < 3; c11_i447 = c11_i447 + 1) {
    c11_v_x[c11_i447] = c11_u_x[c11_i447];
  }

  for (c11_i448 = 0; c11_i448 < 3; c11_i448 = c11_i448 + 1) {
    c11_db_y[c11_i448] = c11_cb_y[c11_i448];
  }

  for (c11_i449 = 0; c11_i449 < 3; c11_i449 = c11_i449 + 1) {
    c11_w_x[c11_i449] = c11_v_x[c11_i449];
  }

  for (c11_i450 = 0; c11_i450 < 3; c11_i450 = c11_i450 + 1) {
    c11_eb_y[c11_i450] = c11_db_y[c11_i450];
  }

  for (c11_i451 = 0; c11_i451 < 3; c11_i451 = c11_i451 + 1) {
    c11_x_x[c11_i451] = c11_w_x[c11_i451];
  }

  for (c11_i452 = 0; c11_i452 < 3; c11_i452 = c11_i452 + 1) {
    c11_fb_y[c11_i452] = c11_eb_y[c11_i452];
  }

  c11_gb_y = c11_ceval_xdot(chartInstance, 3, c11_x_x, 1, 1, c11_fb_y, 1, 1);
  c11_theta0 = c11_atan2(chartInstance, c11_bb_y, c11_gb_y);
  _SFD_SCRIPT_CALL(4, 21);
  for (c11_i453 = 0; c11_i453 < 3; c11_i453 = c11_i453 + 1) {
    c11_i_a[c11_i453] = c11_up[c11_i453];
  }

  for (c11_i454 = 0; c11_i454 < 3; c11_i454 = c11_i454 + 1) {
    c11_i_b[c11_i454] = c11_up[c11_i454];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i455 = 0; c11_i455 < 3; c11_i455 = c11_i455 + 1) {
    c11_y_x[c11_i455] = c11_i_a[c11_i455];
  }

  for (c11_i456 = 0; c11_i456 < 3; c11_i456 = c11_i456 + 1) {
    c11_hb_y[c11_i456] = c11_i_b[c11_i456];
  }

  for (c11_i457 = 0; c11_i457 < 3; c11_i457 = c11_i457 + 1) {
    c11_ab_x[c11_i457] = c11_y_x[c11_i457];
  }

  for (c11_i458 = 0; c11_i458 < 3; c11_i458 = c11_i458 + 1) {
    c11_ib_y[c11_i458] = c11_hb_y[c11_i458];
  }

  for (c11_i459 = 0; c11_i459 < 3; c11_i459 = c11_i459 + 1) {
    c11_bb_x[c11_i459] = c11_ab_x[c11_i459];
  }

  for (c11_i460 = 0; c11_i460 < 3; c11_i460 = c11_i460 + 1) {
    c11_jb_y[c11_i460] = c11_ib_y[c11_i460];
  }

  for (c11_i461 = 0; c11_i461 < 3; c11_i461 = c11_i461 + 1) {
    c11_cb_x[c11_i461] = c11_bb_x[c11_i461];
  }

  for (c11_i462 = 0; c11_i462 < 3; c11_i462 = c11_i462 + 1) {
    c11_kb_y[c11_i462] = c11_jb_y[c11_i462];
  }

  c11_lb_y = c11_ceval_xdot(chartInstance, 3, c11_cb_x, 1, 1, c11_kb_y, 1, 1);
  for (c11_i463 = 0; c11_i463 < 3; c11_i463 = c11_i463 + 1) {
    c11_j_a[c11_i463] = c11_vp[c11_i463];
  }

  for (c11_i464 = 0; c11_i464 < 3; c11_i464 = c11_i464 + 1) {
    c11_j_b[c11_i464] = c11_vp[c11_i464];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i465 = 0; c11_i465 < 3; c11_i465 = c11_i465 + 1) {
    c11_db_x[c11_i465] = c11_j_a[c11_i465];
  }

  for (c11_i466 = 0; c11_i466 < 3; c11_i466 = c11_i466 + 1) {
    c11_mb_y[c11_i466] = c11_j_b[c11_i466];
  }

  for (c11_i467 = 0; c11_i467 < 3; c11_i467 = c11_i467 + 1) {
    c11_eb_x[c11_i467] = c11_db_x[c11_i467];
  }

  for (c11_i468 = 0; c11_i468 < 3; c11_i468 = c11_i468 + 1) {
    c11_nb_y[c11_i468] = c11_mb_y[c11_i468];
  }

  for (c11_i469 = 0; c11_i469 < 3; c11_i469 = c11_i469 + 1) {
    c11_fb_x[c11_i469] = c11_eb_x[c11_i469];
  }

  for (c11_i470 = 0; c11_i470 < 3; c11_i470 = c11_i470 + 1) {
    c11_ob_y[c11_i470] = c11_nb_y[c11_i470];
  }

  for (c11_i471 = 0; c11_i471 < 3; c11_i471 = c11_i471 + 1) {
    c11_gb_x[c11_i471] = c11_fb_x[c11_i471];
  }

  for (c11_i472 = 0; c11_i472 < 3; c11_i472 = c11_i472 + 1) {
    c11_pb_y[c11_i472] = c11_ob_y[c11_i472];
  }

  c11_qb_y = c11_ceval_xdot(chartInstance, 3, c11_gb_x, 1, 1, c11_pb_y, 1, 1);
  for (c11_i473 = 0; c11_i473 < 3; c11_i473 = c11_i473 + 1) {
    c11_c_up[c11_i473] = c11_up[c11_i473];
  }

  c11_k_b = c11_norm(chartInstance, c11_c_up);
  c11_rb_y = 2.0 * c11_k_b;
  c11_k_a = c11_rb_y;
  for (c11_i474 = 0; c11_i474 < 3; c11_i474 = c11_i474 + 1) {
    c11_c_vp[c11_i474] = c11_vp[c11_i474];
  }

  c11_l_b = c11_norm(chartInstance, c11_c_vp);
  c11_sb_y = c11_k_a * c11_l_b;
  c11_A = (c11_lb_y + c11_qb_y) - c11_dp2;
  c11_B = c11_sb_y;
  c11_hb_x = c11_A;
  c11_tb_y = c11_B;
  c11_ib_x = c11_hb_x;
  c11_ub_y = c11_tb_y;
  c11_jb_x = c11_ib_x;
  c11_vb_y = c11_ub_y;
  c11_wb_y = c11_jb_x / c11_vb_y;
  c11_kb_x = c11_wb_y;
  c11_phi = c11_kb_x;
  if (c11_phi < -1.0) {
  } else if (1.0 < c11_phi) {
  } else {
    goto label_1;
  }

  c11_eml_error(chartInstance);
 label_1:
  ;
  c11_lb_x = c11_phi;
  c11_phi = c11_lb_x;
  c11_phi = muDoubleScalarAcos(c11_phi);
  _SFD_SCRIPT_CALL(4, 23);
  c11_theta[0] = c11_theta0 - c11_phi;
  _SFD_SCRIPT_CALL(4, 24);
  c11_theta[1] = c11_theta0 + c11_phi;

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
  if (CV_SCRIPT_IF(4, 0, c11_phi != 0.0)) {
    _SFD_SCRIPT_CALL(4, 45);
    *c11_Nsol = 2.0;
  } else {
    /*          theta = theta0; */
    _SFD_SCRIPT_CALL(4, 48);
    *c11_Nsol = 1.0;
  }

  _SFD_SCRIPT_CALL(4, -48);
  sf_debug_symbol_scope_pop();
}

static void c11_g_eml_scalar_eg(SFc11_KinConInstanceStruct *chartInstance)
{
}

static real_T c11_ceval_xdot(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[3], int32_T c11_ix0, int32_T
  c11_incx, real_T c11_y[3], int32_T c11_iy0, int32_T c11_incy)
{
  return ddot32(&c11_n, &c11_x[0], &c11_incx, &c11_y[0], &c11_incy);
}

static real_T c11_mpower(SFc11_KinConInstanceStruct *chartInstance, real_T c11_a)
{
  return c11_power(chartInstance, c11_a, 2.0);
}

static real_T c11_norm(SFc11_KinConInstanceStruct *chartInstance, real_T c11_x[3])
{
  int32_T c11_i475;
  real_T c11_b_x[3];
  int32_T c11_i476;
  real_T c11_c_x[3];
  int32_T c11_i477;
  real_T c11_d_x[3];
  int32_T c11_i478;
  real_T c11_e_x[3];
  for (c11_i475 = 0; c11_i475 < 3; c11_i475 = c11_i475 + 1) {
    c11_b_x[c11_i475] = c11_x[c11_i475];
  }

  for (c11_i476 = 0; c11_i476 < 3; c11_i476 = c11_i476 + 1) {
    c11_c_x[c11_i476] = c11_b_x[c11_i476];
  }

  for (c11_i477 = 0; c11_i477 < 3; c11_i477 = c11_i477 + 1) {
    c11_d_x[c11_i477] = c11_c_x[c11_i477];
  }

  for (c11_i478 = 0; c11_i478 < 3; c11_i478 = c11_i478 + 1) {
    c11_e_x[c11_i478] = c11_d_x[c11_i478];
  }

  return c11_ceval_xnrm2(chartInstance, 3, c11_e_x, 1, 1);
}

static real_T c11_ceval_xnrm2(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[3], int32_T c11_ix0, int32_T
  c11_incx)
{
  return dnrm232(&c11_n, &c11_x[0], &c11_incx);
}

static void c11_eml_error(SFc11_KinConInstanceStruct *chartInstance)
{
  int32_T c11_i479;
  static char_T c11_cv2[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'a', 'c', 'o', 's', ':',
    'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c11_u[31];
  const mxArray *c11_y = NULL;
  int32_T c11_i480;
  static char_T c11_cv3[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm',
    'p', 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e',
    's', 'u', 'l', 't', 's',
    ' ', 'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u',
    's', 'e', ' ', '\'', 'a',
    'c', 'o', 's', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')',
    '\'', '.' };

  char_T c11_b_u[77];
  const mxArray *c11_b_y = NULL;
  for (c11_i479 = 0; c11_i479 < 31; c11_i479 = c11_i479 + 1) {
    c11_u[c11_i479] = c11_cv2[c11_i479];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 31));
  for (c11_i480 = 0; c11_i480 < 77; c11_i480 = c11_i480 + 1) {
    c11_b_u[c11_i480] = c11_cv3[c11_i480];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1, 77));
  sf_mex_call_debug("error", 0U, 2U, 14, c11_y, 14, c11_b_y);
}

static void c11_b_isInRange(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_x[2], real_T c11_xmin, real_T c11_xmax, boolean_T
  c11_isIn[2])
{
  uint32_T c11_debug_family_var_map[6];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i481;
  real_T c11_A[2];
  int32_T c11_i482;
  real_T c11_b_x[2];
  int32_T c11_i483;
  real_T c11_c_x[2];
  int32_T c11_i484;
  real_T c11_d_x[2];
  int32_T c11_i485;
  real_T c11_y[2];
  int32_T c11_i486;
  real_T c11_a[2];
  int32_T c11_i487;
  int32_T c11_i488;
  boolean_T c11_bv5[2];
  int32_T c11_i489;
  boolean_T c11_bv6[2];
  int32_T c11_i490;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c11_g_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_x, c11_j_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c11_xmin, c11_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_xmax, c11_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_isIn, c11_l_sf_marshall, 5U);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0, 141);
  for (c11_i481 = 0; c11_i481 < 2; c11_i481 = c11_i481 + 1) {
    c11_A[c11_i481] = c11_x[c11_i481];
  }

  for (c11_i482 = 0; c11_i482 < 2; c11_i482 = c11_i482 + 1) {
    c11_b_x[c11_i482] = c11_A[c11_i482];
  }

  for (c11_i483 = 0; c11_i483 < 2; c11_i483 = c11_i483 + 1) {
    c11_c_x[c11_i483] = c11_b_x[c11_i483];
  }

  for (c11_i484 = 0; c11_i484 < 2; c11_i484 = c11_i484 + 1) {
    c11_d_x[c11_i484] = c11_c_x[c11_i484];
  }

  for (c11_i485 = 0; c11_i485 < 2; c11_i485 = c11_i485 + 1) {
    c11_y[c11_i485] = c11_d_x[c11_i485] / 3.1415926535897931;
  }

  for (c11_i486 = 0; c11_i486 < 2; c11_i486 = c11_i486 + 1) {
    c11_a[c11_i486] = c11_y[c11_i486];
  }

  for (c11_i487 = 0; c11_i487 < 2; c11_i487 = c11_i487 + 1) {
    c11_x[c11_i487] = c11_a[c11_i487] * 180.0;
  }

  _SFD_SCRIPT_CALL(0, 142);
  for (c11_i488 = 0; c11_i488 < 2; c11_i488 = c11_i488 + 1) {
    c11_bv5[c11_i488] = (c11_x[c11_i488] >= c11_xmin);
  }

  for (c11_i489 = 0; c11_i489 < 2; c11_i489 = c11_i489 + 1) {
    c11_bv6[c11_i489] = (c11_x[c11_i489] <= c11_xmax);
  }

  for (c11_i490 = 0; c11_i490 < 2; c11_i490 = c11_i490 + 1) {
    c11_isIn[c11_i490] = (c11_bv5[c11_i490] && c11_bv6[c11_i490]);
  }

  _SFD_SCRIPT_CALL(0, -142);
  sf_debug_symbol_scope_pop();
}

static boolean_T c11_any(SFc11_KinConInstanceStruct *chartInstance, boolean_T
  c11_x[2])
{
  boolean_T c11_y;
  int32_T c11_i491;
  boolean_T c11_b_x[2];
  real_T c11_k;
  real_T c11_b_k;
  boolean_T c11_b5;
  for (c11_i491 = 0; c11_i491 < 2; c11_i491 = c11_i491 + 1) {
    c11_b_x[c11_i491] = c11_x[c11_i491];
  }

  c11_y = FALSE;
  c11_k = 1.0;
 label_1:
  ;
  if (c11_k <= 2.0) {
    c11_b_k = c11_k;
    if ((real_T)c11_b_x[(int32_T)c11_b_k - 1] == 0.0) {
      c11_b5 = TRUE;
    } else {
      c11_b5 = FALSE;
    }

    if (!c11_b5) {
      return TRUE;
    } else {
      c11_k = c11_k + 1.0;
      goto label_1;
    }
  }

  return c11_y;
}

static real_T c11_subPro1(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[4], real_T c11_q[4])
{
  real_T c11_theta;
  uint32_T c11_debug_family_var_map[13];
  real_T c11_velociy[3];
  real_T c11_w[3];
  real_T c11_r[3];
  real_T c11_u[3];
  real_T c11_v[3];
  real_T c11_up[3];
  real_T c11_vp[3];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i492;
  int32_T c11_i493;
  int32_T c11_i494;
  real_T c11_b_velociy[3];
  int32_T c11_i495;
  real_T c11_b_w[3];
  real_T c11_dv29[3];
  int32_T c11_i496;
  int32_T c11_i497;
  int32_T c11_i498;
  int32_T c11_i499;
  real_T c11_a[3];
  int32_T c11_i500;
  real_T c11_b[3];
  int32_T c11_i501;
  real_T c11_x[3];
  int32_T c11_i502;
  real_T c11_y[3];
  int32_T c11_i503;
  real_T c11_b_x[3];
  int32_T c11_i504;
  real_T c11_b_y[3];
  int32_T c11_i505;
  real_T c11_c_x[3];
  int32_T c11_i506;
  real_T c11_c_y[3];
  int32_T c11_i507;
  real_T c11_d_x[3];
  int32_T c11_i508;
  real_T c11_d_y[3];
  real_T c11_e_y;
  int32_T c11_i509;
  real_T c11_b_a[3];
  real_T c11_b_b;
  int32_T c11_i510;
  real_T c11_f_y[3];
  int32_T c11_i511;
  int32_T c11_i512;
  real_T c11_c_a[3];
  int32_T c11_i513;
  real_T c11_c_b[3];
  int32_T c11_i514;
  real_T c11_e_x[3];
  int32_T c11_i515;
  real_T c11_g_y[3];
  int32_T c11_i516;
  real_T c11_f_x[3];
  int32_T c11_i517;
  real_T c11_h_y[3];
  int32_T c11_i518;
  real_T c11_g_x[3];
  int32_T c11_i519;
  real_T c11_i_y[3];
  int32_T c11_i520;
  real_T c11_h_x[3];
  int32_T c11_i521;
  real_T c11_j_y[3];
  real_T c11_k_y;
  int32_T c11_i522;
  real_T c11_d_a[3];
  real_T c11_d_b;
  int32_T c11_i523;
  real_T c11_l_y[3];
  int32_T c11_i524;
  int32_T c11_i525;
  real_T c11_e_a[3];
  int32_T c11_i526;
  real_T c11_b_up[3];
  int32_T c11_i527;
  real_T c11_b_vp[3];
  real_T c11_e_b[3];
  int32_T c11_i528;
  real_T c11_i_x[3];
  int32_T c11_i529;
  real_T c11_m_y[3];
  int32_T c11_i530;
  real_T c11_j_x[3];
  int32_T c11_i531;
  real_T c11_n_y[3];
  int32_T c11_i532;
  real_T c11_k_x[3];
  int32_T c11_i533;
  real_T c11_o_y[3];
  int32_T c11_i534;
  real_T c11_l_x[3];
  int32_T c11_i535;
  real_T c11_p_y[3];
  real_T c11_q_y;
  int32_T c11_i536;
  real_T c11_f_a[3];
  int32_T c11_i537;
  real_T c11_f_b[3];
  int32_T c11_i538;
  real_T c11_m_x[3];
  int32_T c11_i539;
  real_T c11_r_y[3];
  int32_T c11_i540;
  real_T c11_n_x[3];
  int32_T c11_i541;
  real_T c11_s_y[3];
  int32_T c11_i542;
  real_T c11_o_x[3];
  int32_T c11_i543;
  real_T c11_t_y[3];
  int32_T c11_i544;
  real_T c11_p_x[3];
  int32_T c11_i545;
  real_T c11_u_y[3];
  real_T c11_v_y;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c11_h_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_velociy, c11_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_w, c11_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_r, c11_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_u, c11_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c11_v, c11_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_up, c11_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_vp, c11_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c11_kx, c11_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c11_p, c11_k_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c11_q, c11_k_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c11_theta, c11_e_sf_marshall, 12U);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5, 4);
  for (c11_i492 = 0; c11_i492 < 3; c11_i492 = c11_i492 + 1) {
    c11_velociy[c11_i492] = c11_kx[c11_i492];
  }

  _SFD_SCRIPT_CALL(5, 5);
  for (c11_i493 = 0; c11_i493 < 3; c11_i493 = c11_i493 + 1) {
    c11_w[c11_i493] = c11_kx[c11_i493 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(5, 6);
  for (c11_i494 = 0; c11_i494 < 3; c11_i494 = c11_i494 + 1) {
    c11_b_velociy[c11_i494] = c11_velociy[c11_i494];
  }

  for (c11_i495 = 0; c11_i495 < 3; c11_i495 = c11_i495 + 1) {
    c11_b_w[c11_i495] = c11_w[c11_i495];
  }

  c11_cross(chartInstance, c11_b_velociy, c11_b_w, c11_dv29);
  for (c11_i496 = 0; c11_i496 < 3; c11_i496 = c11_i496 + 1) {
    c11_r[c11_i496] = -c11_dv29[c11_i496];
  }

  _SFD_SCRIPT_CALL(5, 8);
  for (c11_i497 = 0; c11_i497 < 3; c11_i497 = c11_i497 + 1) {
    c11_u[c11_i497] = c11_p[c11_i497] - c11_r[c11_i497];
  }

  _SFD_SCRIPT_CALL(5, 9);
  for (c11_i498 = 0; c11_i498 < 3; c11_i498 = c11_i498 + 1) {
    c11_v[c11_i498] = c11_q[c11_i498] - c11_r[c11_i498];
  }

  _SFD_SCRIPT_CALL(5, 12);
  for (c11_i499 = 0; c11_i499 < 3; c11_i499 = c11_i499 + 1) {
    c11_a[c11_i499] = c11_w[c11_i499];
  }

  for (c11_i500 = 0; c11_i500 < 3; c11_i500 = c11_i500 + 1) {
    c11_b[c11_i500] = c11_u[c11_i500];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i501 = 0; c11_i501 < 3; c11_i501 = c11_i501 + 1) {
    c11_x[c11_i501] = c11_a[c11_i501];
  }

  for (c11_i502 = 0; c11_i502 < 3; c11_i502 = c11_i502 + 1) {
    c11_y[c11_i502] = c11_b[c11_i502];
  }

  for (c11_i503 = 0; c11_i503 < 3; c11_i503 = c11_i503 + 1) {
    c11_b_x[c11_i503] = c11_x[c11_i503];
  }

  for (c11_i504 = 0; c11_i504 < 3; c11_i504 = c11_i504 + 1) {
    c11_b_y[c11_i504] = c11_y[c11_i504];
  }

  for (c11_i505 = 0; c11_i505 < 3; c11_i505 = c11_i505 + 1) {
    c11_c_x[c11_i505] = c11_b_x[c11_i505];
  }

  for (c11_i506 = 0; c11_i506 < 3; c11_i506 = c11_i506 + 1) {
    c11_c_y[c11_i506] = c11_b_y[c11_i506];
  }

  for (c11_i507 = 0; c11_i507 < 3; c11_i507 = c11_i507 + 1) {
    c11_d_x[c11_i507] = c11_c_x[c11_i507];
  }

  for (c11_i508 = 0; c11_i508 < 3; c11_i508 = c11_i508 + 1) {
    c11_d_y[c11_i508] = c11_c_y[c11_i508];
  }

  c11_e_y = c11_ceval_xdot(chartInstance, 3, c11_d_x, 1, 1, c11_d_y, 1, 1);
  for (c11_i509 = 0; c11_i509 < 3; c11_i509 = c11_i509 + 1) {
    c11_b_a[c11_i509] = c11_w[c11_i509];
  }

  c11_b_b = c11_e_y;
  for (c11_i510 = 0; c11_i510 < 3; c11_i510 = c11_i510 + 1) {
    c11_f_y[c11_i510] = c11_b_a[c11_i510] * c11_b_b;
  }

  for (c11_i511 = 0; c11_i511 < 3; c11_i511 = c11_i511 + 1) {
    c11_up[c11_i511] = c11_u[c11_i511] - c11_f_y[c11_i511];
  }

  _SFD_SCRIPT_CALL(5, 13);
  for (c11_i512 = 0; c11_i512 < 3; c11_i512 = c11_i512 + 1) {
    c11_c_a[c11_i512] = c11_w[c11_i512];
  }

  for (c11_i513 = 0; c11_i513 < 3; c11_i513 = c11_i513 + 1) {
    c11_c_b[c11_i513] = c11_u[c11_i513];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i514 = 0; c11_i514 < 3; c11_i514 = c11_i514 + 1) {
    c11_e_x[c11_i514] = c11_c_a[c11_i514];
  }

  for (c11_i515 = 0; c11_i515 < 3; c11_i515 = c11_i515 + 1) {
    c11_g_y[c11_i515] = c11_c_b[c11_i515];
  }

  for (c11_i516 = 0; c11_i516 < 3; c11_i516 = c11_i516 + 1) {
    c11_f_x[c11_i516] = c11_e_x[c11_i516];
  }

  for (c11_i517 = 0; c11_i517 < 3; c11_i517 = c11_i517 + 1) {
    c11_h_y[c11_i517] = c11_g_y[c11_i517];
  }

  for (c11_i518 = 0; c11_i518 < 3; c11_i518 = c11_i518 + 1) {
    c11_g_x[c11_i518] = c11_f_x[c11_i518];
  }

  for (c11_i519 = 0; c11_i519 < 3; c11_i519 = c11_i519 + 1) {
    c11_i_y[c11_i519] = c11_h_y[c11_i519];
  }

  for (c11_i520 = 0; c11_i520 < 3; c11_i520 = c11_i520 + 1) {
    c11_h_x[c11_i520] = c11_g_x[c11_i520];
  }

  for (c11_i521 = 0; c11_i521 < 3; c11_i521 = c11_i521 + 1) {
    c11_j_y[c11_i521] = c11_i_y[c11_i521];
  }

  c11_k_y = c11_ceval_xdot(chartInstance, 3, c11_h_x, 1, 1, c11_j_y, 1, 1);
  for (c11_i522 = 0; c11_i522 < 3; c11_i522 = c11_i522 + 1) {
    c11_d_a[c11_i522] = c11_w[c11_i522];
  }

  c11_d_b = c11_k_y;
  for (c11_i523 = 0; c11_i523 < 3; c11_i523 = c11_i523 + 1) {
    c11_l_y[c11_i523] = c11_d_a[c11_i523] * c11_d_b;
  }

  for (c11_i524 = 0; c11_i524 < 3; c11_i524 = c11_i524 + 1) {
    c11_vp[c11_i524] = c11_v[c11_i524] - c11_l_y[c11_i524];
  }

  /*      if norm(up) == 0 */
  /*          error('SubPro1: up = 0, Infinite number of solutions!'); */
  /*      end */
  _SFD_SCRIPT_CALL(5, 19);
  for (c11_i525 = 0; c11_i525 < 3; c11_i525 = c11_i525 + 1) {
    c11_e_a[c11_i525] = c11_w[c11_i525];
  }

  for (c11_i526 = 0; c11_i526 < 3; c11_i526 = c11_i526 + 1) {
    c11_b_up[c11_i526] = c11_up[c11_i526];
  }

  for (c11_i527 = 0; c11_i527 < 3; c11_i527 = c11_i527 + 1) {
    c11_b_vp[c11_i527] = c11_vp[c11_i527];
  }

  c11_cross(chartInstance, c11_b_up, c11_b_vp, c11_e_b);
  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i528 = 0; c11_i528 < 3; c11_i528 = c11_i528 + 1) {
    c11_i_x[c11_i528] = c11_e_a[c11_i528];
  }

  for (c11_i529 = 0; c11_i529 < 3; c11_i529 = c11_i529 + 1) {
    c11_m_y[c11_i529] = c11_e_b[c11_i529];
  }

  for (c11_i530 = 0; c11_i530 < 3; c11_i530 = c11_i530 + 1) {
    c11_j_x[c11_i530] = c11_i_x[c11_i530];
  }

  for (c11_i531 = 0; c11_i531 < 3; c11_i531 = c11_i531 + 1) {
    c11_n_y[c11_i531] = c11_m_y[c11_i531];
  }

  for (c11_i532 = 0; c11_i532 < 3; c11_i532 = c11_i532 + 1) {
    c11_k_x[c11_i532] = c11_j_x[c11_i532];
  }

  for (c11_i533 = 0; c11_i533 < 3; c11_i533 = c11_i533 + 1) {
    c11_o_y[c11_i533] = c11_n_y[c11_i533];
  }

  for (c11_i534 = 0; c11_i534 < 3; c11_i534 = c11_i534 + 1) {
    c11_l_x[c11_i534] = c11_k_x[c11_i534];
  }

  for (c11_i535 = 0; c11_i535 < 3; c11_i535 = c11_i535 + 1) {
    c11_p_y[c11_i535] = c11_o_y[c11_i535];
  }

  c11_q_y = c11_ceval_xdot(chartInstance, 3, c11_l_x, 1, 1, c11_p_y, 1, 1);
  for (c11_i536 = 0; c11_i536 < 3; c11_i536 = c11_i536 + 1) {
    c11_f_a[c11_i536] = c11_up[c11_i536];
  }

  for (c11_i537 = 0; c11_i537 < 3; c11_i537 = c11_i537 + 1) {
    c11_f_b[c11_i537] = c11_vp[c11_i537];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i538 = 0; c11_i538 < 3; c11_i538 = c11_i538 + 1) {
    c11_m_x[c11_i538] = c11_f_a[c11_i538];
  }

  for (c11_i539 = 0; c11_i539 < 3; c11_i539 = c11_i539 + 1) {
    c11_r_y[c11_i539] = c11_f_b[c11_i539];
  }

  for (c11_i540 = 0; c11_i540 < 3; c11_i540 = c11_i540 + 1) {
    c11_n_x[c11_i540] = c11_m_x[c11_i540];
  }

  for (c11_i541 = 0; c11_i541 < 3; c11_i541 = c11_i541 + 1) {
    c11_s_y[c11_i541] = c11_r_y[c11_i541];
  }

  for (c11_i542 = 0; c11_i542 < 3; c11_i542 = c11_i542 + 1) {
    c11_o_x[c11_i542] = c11_n_x[c11_i542];
  }

  for (c11_i543 = 0; c11_i543 < 3; c11_i543 = c11_i543 + 1) {
    c11_t_y[c11_i543] = c11_s_y[c11_i543];
  }

  for (c11_i544 = 0; c11_i544 < 3; c11_i544 = c11_i544 + 1) {
    c11_p_x[c11_i544] = c11_o_x[c11_i544];
  }

  for (c11_i545 = 0; c11_i545 < 3; c11_i545 = c11_i545 + 1) {
    c11_u_y[c11_i545] = c11_t_y[c11_i545];
  }

  c11_v_y = c11_ceval_xdot(chartInstance, 3, c11_p_x, 1, 1, c11_u_y, 1, 1);
  c11_theta = c11_atan2(chartInstance, c11_q_y, c11_v_y);
  _SFD_SCRIPT_CALL(5, -19);
  sf_debug_symbol_scope_pop();
  return c11_theta;
}

static void c11_subPro2(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx1[6], real_T c11_kx2[6], real_T c11_p[4], real_T
  c11_q[4], real_T c11_theta1[2], real_T c11_theta2[2], real_T *c11_Nsol)
{
  uint32_T c11_debug_family_var_map[25];
  static const char *c11_sv6[25] = { "velociy1", "w1", "r1", "velociy2", "w2",
    "r2", "r", "u", "v", "alpha", "beta", "ySqu", "i", "y"
    , "z", "c", "nargin", "nargout", "kx1", "kx2", "p", "q", "theta1", "theta2",
    "Nsol" };

  real_T c11_velociy1[3];
  real_T c11_w1[3];
  real_T c11_r1[3];
  real_T c11_velociy2[3];
  real_T c11_w2[3];
  real_T c11_r2[3];
  real_T c11_r[3];
  real_T c11_u[3];
  real_T c11_v[3];
  real_T c11_alpha;
  real_T c11_beta;
  real_T c11_ySqu;
  real_T c11_i;
  real_T c11_y;
  real_T c11_z[3];
  real_T c11_c[3];
  real_T c11_nargin = 4.0;
  real_T c11_nargout = 3.0;
  int32_T c11_i546;
  int32_T c11_i547;
  int32_T c11_i548;
  int32_T c11_i549;
  int32_T c11_i550;
  real_T c11_b_velociy1[3];
  int32_T c11_i551;
  real_T c11_b_w1[3];
  real_T c11_dv30[3];
  int32_T c11_i552;
  int32_T c11_i553;
  int32_T c11_i554;
  int32_T c11_i555;
  real_T c11_b_velociy2[3];
  int32_T c11_i556;
  real_T c11_b_w2[3];
  real_T c11_dv31[3];
  int32_T c11_i557;
  int32_T c11_i558;
  real_T c11_c_w1[3];
  int32_T c11_i559;
  real_T c11_c_w2[3];
  int32_T c11_i560;
  real_T c11_b_r1[3];
  int32_T c11_i561;
  real_T c11_b_r2[3];
  real_T c11_dv32[3];
  int32_T c11_i562;
  int32_T c11_i563;
  int32_T c11_i564;
  int32_T c11_i565;
  real_T c11_a[3];
  int32_T c11_i566;
  real_T c11_b[3];
  int32_T c11_i567;
  real_T c11_x[3];
  int32_T c11_i568;
  real_T c11_b_y[3];
  int32_T c11_i569;
  real_T c11_b_x[3];
  int32_T c11_i570;
  real_T c11_c_y[3];
  int32_T c11_i571;
  real_T c11_c_x[3];
  int32_T c11_i572;
  real_T c11_d_y[3];
  int32_T c11_i573;
  real_T c11_d_x[3];
  int32_T c11_i574;
  real_T c11_e_y[3];
  real_T c11_f_y;
  real_T c11_b_a;
  int32_T c11_i575;
  real_T c11_b_b[3];
  int32_T c11_i576;
  real_T c11_g_y[3];
  int32_T c11_i577;
  real_T c11_c_a[3];
  int32_T c11_i578;
  real_T c11_c_b[3];
  int32_T c11_i579;
  real_T c11_e_x[3];
  int32_T c11_i580;
  real_T c11_h_y[3];
  int32_T c11_i581;
  real_T c11_f_x[3];
  int32_T c11_i582;
  real_T c11_i_y[3];
  int32_T c11_i583;
  real_T c11_g_x[3];
  int32_T c11_i584;
  real_T c11_j_y[3];
  int32_T c11_i585;
  real_T c11_h_x[3];
  int32_T c11_i586;
  real_T c11_k_y[3];
  real_T c11_l_y;
  int32_T c11_i587;
  real_T c11_d_a[3];
  int32_T c11_i588;
  real_T c11_d_b[3];
  int32_T c11_i589;
  real_T c11_i_x[3];
  int32_T c11_i590;
  real_T c11_m_y[3];
  int32_T c11_i591;
  real_T c11_j_x[3];
  int32_T c11_i592;
  real_T c11_n_y[3];
  int32_T c11_i593;
  real_T c11_k_x[3];
  int32_T c11_i594;
  real_T c11_o_y[3];
  int32_T c11_i595;
  real_T c11_l_x[3];
  int32_T c11_i596;
  real_T c11_p_y[3];
  real_T c11_q_y;
  int32_T c11_i597;
  real_T c11_e_a[3];
  int32_T c11_i598;
  real_T c11_e_b[3];
  int32_T c11_i599;
  real_T c11_m_x[3];
  int32_T c11_i600;
  real_T c11_r_y[3];
  int32_T c11_i601;
  real_T c11_n_x[3];
  int32_T c11_i602;
  real_T c11_s_y[3];
  int32_T c11_i603;
  real_T c11_o_x[3];
  int32_T c11_i604;
  real_T c11_t_y[3];
  int32_T c11_i605;
  real_T c11_p_x[3];
  int32_T c11_i606;
  real_T c11_u_y[3];
  real_T c11_v_y;
  int32_T c11_i607;
  real_T c11_f_a[3];
  int32_T c11_i608;
  real_T c11_f_b[3];
  int32_T c11_i609;
  real_T c11_q_x[3];
  int32_T c11_i610;
  real_T c11_w_y[3];
  int32_T c11_i611;
  real_T c11_r_x[3];
  int32_T c11_i612;
  real_T c11_x_y[3];
  int32_T c11_i613;
  real_T c11_s_x[3];
  int32_T c11_i614;
  real_T c11_y_y[3];
  int32_T c11_i615;
  real_T c11_t_x[3];
  int32_T c11_i616;
  real_T c11_ab_y[3];
  real_T c11_bb_y;
  real_T c11_g_a;
  real_T c11_g_b;
  real_T c11_cb_y;
  real_T c11_A;
  real_T c11_B;
  real_T c11_u_x;
  real_T c11_db_y;
  real_T c11_v_x;
  real_T c11_eb_y;
  real_T c11_w_x;
  real_T c11_fb_y;
  int32_T c11_i617;
  real_T c11_h_a[3];
  int32_T c11_i618;
  real_T c11_h_b[3];
  int32_T c11_i619;
  real_T c11_x_x[3];
  int32_T c11_i620;
  real_T c11_gb_y[3];
  int32_T c11_i621;
  real_T c11_y_x[3];
  int32_T c11_i622;
  real_T c11_hb_y[3];
  int32_T c11_i623;
  real_T c11_ab_x[3];
  int32_T c11_i624;
  real_T c11_ib_y[3];
  int32_T c11_i625;
  real_T c11_bb_x[3];
  int32_T c11_i626;
  real_T c11_jb_y[3];
  real_T c11_kb_y;
  real_T c11_i_a;
  int32_T c11_i627;
  real_T c11_i_b[3];
  int32_T c11_i628;
  real_T c11_lb_y[3];
  int32_T c11_i629;
  real_T c11_j_a[3];
  int32_T c11_i630;
  real_T c11_j_b[3];
  int32_T c11_i631;
  real_T c11_cb_x[3];
  int32_T c11_i632;
  real_T c11_mb_y[3];
  int32_T c11_i633;
  real_T c11_db_x[3];
  int32_T c11_i634;
  real_T c11_nb_y[3];
  int32_T c11_i635;
  real_T c11_eb_x[3];
  int32_T c11_i636;
  real_T c11_ob_y[3];
  int32_T c11_i637;
  real_T c11_fb_x[3];
  int32_T c11_i638;
  real_T c11_pb_y[3];
  real_T c11_qb_y;
  int32_T c11_i639;
  real_T c11_k_a[3];
  int32_T c11_i640;
  real_T c11_k_b[3];
  int32_T c11_i641;
  real_T c11_gb_x[3];
  int32_T c11_i642;
  real_T c11_rb_y[3];
  int32_T c11_i643;
  real_T c11_hb_x[3];
  int32_T c11_i644;
  real_T c11_sb_y[3];
  int32_T c11_i645;
  real_T c11_ib_x[3];
  int32_T c11_i646;
  real_T c11_tb_y[3];
  int32_T c11_i647;
  real_T c11_jb_x[3];
  int32_T c11_i648;
  real_T c11_ub_y[3];
  real_T c11_vb_y;
  int32_T c11_i649;
  real_T c11_l_a[3];
  int32_T c11_i650;
  real_T c11_l_b[3];
  int32_T c11_i651;
  real_T c11_kb_x[3];
  int32_T c11_i652;
  real_T c11_wb_y[3];
  int32_T c11_i653;
  real_T c11_lb_x[3];
  int32_T c11_i654;
  real_T c11_xb_y[3];
  int32_T c11_i655;
  real_T c11_mb_x[3];
  int32_T c11_i656;
  real_T c11_yb_y[3];
  int32_T c11_i657;
  real_T c11_nb_x[3];
  int32_T c11_i658;
  real_T c11_ac_y[3];
  real_T c11_bc_y;
  int32_T c11_i659;
  real_T c11_m_a[3];
  int32_T c11_i660;
  real_T c11_m_b[3];
  int32_T c11_i661;
  real_T c11_ob_x[3];
  int32_T c11_i662;
  real_T c11_cc_y[3];
  int32_T c11_i663;
  real_T c11_pb_x[3];
  int32_T c11_i664;
  real_T c11_dc_y[3];
  int32_T c11_i665;
  real_T c11_qb_x[3];
  int32_T c11_i666;
  real_T c11_ec_y[3];
  int32_T c11_i667;
  real_T c11_rb_x[3];
  int32_T c11_i668;
  real_T c11_fc_y[3];
  real_T c11_gc_y;
  real_T c11_n_a;
  real_T c11_n_b;
  real_T c11_hc_y;
  real_T c11_b_A;
  real_T c11_b_B;
  real_T c11_sb_x;
  real_T c11_ic_y;
  real_T c11_tb_x;
  real_T c11_jc_y;
  real_T c11_ub_x;
  real_T c11_kc_y;
  int32_T c11_i669;
  real_T c11_o_a[3];
  int32_T c11_i670;
  real_T c11_o_b[3];
  int32_T c11_i671;
  real_T c11_vb_x[3];
  int32_T c11_i672;
  real_T c11_lc_y[3];
  int32_T c11_i673;
  real_T c11_wb_x[3];
  int32_T c11_i674;
  real_T c11_mc_y[3];
  int32_T c11_i675;
  real_T c11_xb_x[3];
  int32_T c11_i676;
  real_T c11_nc_y[3];
  int32_T c11_i677;
  real_T c11_yb_x[3];
  int32_T c11_i678;
  real_T c11_oc_y[3];
  real_T c11_pc_y;
  real_T c11_p_a;
  real_T c11_p_b;
  real_T c11_qc_y;
  real_T c11_q_a;
  real_T c11_q_b;
  real_T c11_rc_y;
  real_T c11_r_b;
  real_T c11_sc_y;
  real_T c11_r_a;
  real_T c11_s_b;
  real_T c11_tc_y;
  real_T c11_s_a;
  int32_T c11_i679;
  real_T c11_t_b[3];
  int32_T c11_i680;
  real_T c11_uc_y[3];
  int32_T c11_i681;
  real_T c11_t_a[3];
  int32_T c11_i682;
  real_T c11_u_b[3];
  int32_T c11_i683;
  real_T c11_ac_x[3];
  int32_T c11_i684;
  real_T c11_vc_y[3];
  int32_T c11_i685;
  real_T c11_bc_x[3];
  int32_T c11_i686;
  real_T c11_wc_y[3];
  int32_T c11_i687;
  real_T c11_cc_x[3];
  int32_T c11_i688;
  real_T c11_xc_y[3];
  int32_T c11_i689;
  real_T c11_dc_x[3];
  int32_T c11_i690;
  real_T c11_yc_y[3];
  real_T c11_ad_y;
  int32_T c11_i691;
  real_T c11_d_w1[3];
  int32_T c11_i692;
  real_T c11_d_w2[3];
  real_T c11_dv33[3];
  int32_T c11_i693;
  real_T c11_u_a[3];
  int32_T c11_i694;
  real_T c11_e_w1[3];
  int32_T c11_i695;
  real_T c11_e_w2[3];
  real_T c11_v_b[3];
  int32_T c11_i696;
  real_T c11_ec_x[3];
  int32_T c11_i697;
  real_T c11_bd_y[3];
  int32_T c11_i698;
  real_T c11_fc_x[3];
  int32_T c11_i699;
  real_T c11_cd_y[3];
  int32_T c11_i700;
  real_T c11_gc_x[3];
  int32_T c11_i701;
  real_T c11_dd_y[3];
  int32_T c11_i702;
  real_T c11_hc_x[3];
  int32_T c11_i703;
  real_T c11_ed_y[3];
  real_T c11_fd_y;
  real_T c11_c_A;
  real_T c11_c_B;
  real_T c11_ic_x;
  real_T c11_gd_y;
  real_T c11_jc_x;
  real_T c11_hd_y;
  real_T c11_kc_x;
  real_T c11_id_y;
  real_T c11_b_i;
  real_T c11_w_b;
  real_T c11_jd_y;
  real_T c11_lc_x;
  real_T c11_mc_x;
  real_T c11_nc_x;
  real_T c11_v_a;
  real_T c11_x_b;
  real_T c11_w_a;
  int32_T c11_i704;
  real_T c11_y_b[3];
  int32_T c11_i705;
  real_T c11_kd_y[3];
  real_T c11_x_a;
  int32_T c11_i706;
  real_T c11_ab_b[3];
  int32_T c11_i707;
  real_T c11_ld_y[3];
  real_T c11_y_a;
  int32_T c11_i708;
  real_T c11_f_w1[3];
  int32_T c11_i709;
  real_T c11_f_w2[3];
  real_T c11_bb_b[3];
  int32_T c11_i710;
  real_T c11_md_y[3];
  int32_T c11_i711;
  int32_T c11_i712;
  int32_T c11_i713;
  real_T c11_b_kx2[6];
  int32_T c11_i714;
  real_T c11_b_p[4];
  int32_T c11_i715;
  real_T c11_b_c[3];
  int32_T c11_i716;
  real_T c11_b_kx1[6];
  int32_T c11_i717;
  real_T c11_c_c[3];
  int32_T c11_i718;
  real_T c11_b_q[4];
  sf_debug_symbol_scope_push_eml(0U, 25U, 25U, c11_sv6, c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_velociy1, c11_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_w1, c11_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_r1, c11_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_velociy2, c11_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c11_w2, c11_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_r2, c11_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_r, c11_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c11_u, c11_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c11_v, c11_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c11_alpha, c11_e_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c11_beta, c11_e_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c11_ySqu, c11_e_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c11_i, c11_e_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c11_y, c11_e_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(c11_z, c11_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(c11_c, c11_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(c11_kx1, c11_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(c11_kx2, c11_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(c11_p, c11_k_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(c11_q, c11_k_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(c11_theta1, c11_j_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(c11_theta2, c11_j_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(c11_Nsol, c11_e_sf_marshall, 24U);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6, 3);
  for (c11_i546 = 0; c11_i546 < 2; c11_i546 = c11_i546 + 1) {
    c11_theta1[c11_i546] = 0.0;
  }

  _SFD_SCRIPT_CALL(6, 4);
  for (c11_i547 = 0; c11_i547 < 2; c11_i547 = c11_i547 + 1) {
    c11_theta2[c11_i547] = 0.0;
  }

  /*  ============================================= %     */
  /*  Twist 2 is the one that rotation happens first */
  /*  ============================================= % */
  _SFD_SCRIPT_CALL(6, 9);
  for (c11_i548 = 0; c11_i548 < 3; c11_i548 = c11_i548 + 1) {
    c11_velociy1[c11_i548] = c11_kx1[c11_i548];
  }

  _SFD_SCRIPT_CALL(6, 10);
  for (c11_i549 = 0; c11_i549 < 3; c11_i549 = c11_i549 + 1) {
    c11_w1[c11_i549] = c11_kx1[c11_i549 + 3];
  }

  /*  rotation axis for twist1 */
  _SFD_SCRIPT_CALL(6, 11);
  for (c11_i550 = 0; c11_i550 < 3; c11_i550 = c11_i550 + 1) {
    c11_b_velociy1[c11_i550] = c11_velociy1[c11_i550];
  }

  for (c11_i551 = 0; c11_i551 < 3; c11_i551 = c11_i551 + 1) {
    c11_b_w1[c11_i551] = c11_w1[c11_i551];
  }

  c11_cross(chartInstance, c11_b_velociy1, c11_b_w1, c11_dv30);
  for (c11_i552 = 0; c11_i552 < 3; c11_i552 = c11_i552 + 1) {
    c11_r1[c11_i552] = -c11_dv30[c11_i552];
  }

  /*  one point in w1 axis */
  _SFD_SCRIPT_CALL(6, 13);
  for (c11_i553 = 0; c11_i553 < 3; c11_i553 = c11_i553 + 1) {
    c11_velociy2[c11_i553] = c11_kx2[c11_i553];
  }

  _SFD_SCRIPT_CALL(6, 14);
  for (c11_i554 = 0; c11_i554 < 3; c11_i554 = c11_i554 + 1) {
    c11_w2[c11_i554] = c11_kx2[c11_i554 + 3];
  }

  /*  rotation axis for twist2 */
  _SFD_SCRIPT_CALL(6, 15);
  for (c11_i555 = 0; c11_i555 < 3; c11_i555 = c11_i555 + 1) {
    c11_b_velociy2[c11_i555] = c11_velociy2[c11_i555];
  }

  for (c11_i556 = 0; c11_i556 < 3; c11_i556 = c11_i556 + 1) {
    c11_b_w2[c11_i556] = c11_w2[c11_i556];
  }

  c11_cross(chartInstance, c11_b_velociy2, c11_b_w2, c11_dv31);
  for (c11_i557 = 0; c11_i557 < 3; c11_i557 = c11_i557 + 1) {
    c11_r2[c11_i557] = -c11_dv31[c11_i557];
  }

  /*  one point in w2 axis */
  /* find the common point of two axis */
  _SFD_SCRIPT_CALL(6, 18);
  for (c11_i558 = 0; c11_i558 < 3; c11_i558 = c11_i558 + 1) {
    c11_c_w1[c11_i558] = c11_w1[c11_i558];
  }

  for (c11_i559 = 0; c11_i559 < 3; c11_i559 = c11_i559 + 1) {
    c11_c_w2[c11_i559] = c11_w2[c11_i559];
  }

  for (c11_i560 = 0; c11_i560 < 3; c11_i560 = c11_i560 + 1) {
    c11_b_r1[c11_i560] = c11_r1[c11_i560];
  }

  for (c11_i561 = 0; c11_i561 < 3; c11_i561 = c11_i561 + 1) {
    c11_b_r2[c11_i561] = c11_r2[c11_i561];
  }

  c11_findCommon(chartInstance, c11_c_w1, c11_c_w2, c11_b_r1, c11_b_r2, c11_dv32);
  for (c11_i562 = 0; c11_i562 < 3; c11_i562 = c11_i562 + 1) {
    c11_r[c11_i562] = c11_dv32[c11_i562];
  }

  _SFD_SCRIPT_CALL(6, 20);
  for (c11_i563 = 0; c11_i563 < 3; c11_i563 = c11_i563 + 1) {
    c11_u[c11_i563] = c11_p[c11_i563] - c11_r[c11_i563];
  }

  _SFD_SCRIPT_CALL(6, 21);
  for (c11_i564 = 0; c11_i564 < 3; c11_i564 = c11_i564 + 1) {
    c11_v[c11_i564] = c11_q[c11_i564] - c11_r[c11_i564];
  }

  _SFD_SCRIPT_CALL(6, 23);
  for (c11_i565 = 0; c11_i565 < 3; c11_i565 = c11_i565 + 1) {
    c11_a[c11_i565] = c11_w1[c11_i565];
  }

  for (c11_i566 = 0; c11_i566 < 3; c11_i566 = c11_i566 + 1) {
    c11_b[c11_i566] = c11_w2[c11_i566];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i567 = 0; c11_i567 < 3; c11_i567 = c11_i567 + 1) {
    c11_x[c11_i567] = c11_a[c11_i567];
  }

  for (c11_i568 = 0; c11_i568 < 3; c11_i568 = c11_i568 + 1) {
    c11_b_y[c11_i568] = c11_b[c11_i568];
  }

  for (c11_i569 = 0; c11_i569 < 3; c11_i569 = c11_i569 + 1) {
    c11_b_x[c11_i569] = c11_x[c11_i569];
  }

  for (c11_i570 = 0; c11_i570 < 3; c11_i570 = c11_i570 + 1) {
    c11_c_y[c11_i570] = c11_b_y[c11_i570];
  }

  for (c11_i571 = 0; c11_i571 < 3; c11_i571 = c11_i571 + 1) {
    c11_c_x[c11_i571] = c11_b_x[c11_i571];
  }

  for (c11_i572 = 0; c11_i572 < 3; c11_i572 = c11_i572 + 1) {
    c11_d_y[c11_i572] = c11_c_y[c11_i572];
  }

  for (c11_i573 = 0; c11_i573 < 3; c11_i573 = c11_i573 + 1) {
    c11_d_x[c11_i573] = c11_c_x[c11_i573];
  }

  for (c11_i574 = 0; c11_i574 < 3; c11_i574 = c11_i574 + 1) {
    c11_e_y[c11_i574] = c11_d_y[c11_i574];
  }

  c11_f_y = c11_ceval_xdot(chartInstance, 3, c11_d_x, 1, 1, c11_e_y, 1, 1);
  c11_b_a = c11_f_y;
  for (c11_i575 = 0; c11_i575 < 3; c11_i575 = c11_i575 + 1) {
    c11_b_b[c11_i575] = c11_w2[c11_i575];
  }

  for (c11_i576 = 0; c11_i576 < 3; c11_i576 = c11_i576 + 1) {
    c11_g_y[c11_i576] = c11_b_a * c11_b_b[c11_i576];
  }

  for (c11_i577 = 0; c11_i577 < 3; c11_i577 = c11_i577 + 1) {
    c11_c_a[c11_i577] = c11_g_y[c11_i577];
  }

  for (c11_i578 = 0; c11_i578 < 3; c11_i578 = c11_i578 + 1) {
    c11_c_b[c11_i578] = c11_u[c11_i578];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i579 = 0; c11_i579 < 3; c11_i579 = c11_i579 + 1) {
    c11_e_x[c11_i579] = c11_c_a[c11_i579];
  }

  for (c11_i580 = 0; c11_i580 < 3; c11_i580 = c11_i580 + 1) {
    c11_h_y[c11_i580] = c11_c_b[c11_i580];
  }

  for (c11_i581 = 0; c11_i581 < 3; c11_i581 = c11_i581 + 1) {
    c11_f_x[c11_i581] = c11_e_x[c11_i581];
  }

  for (c11_i582 = 0; c11_i582 < 3; c11_i582 = c11_i582 + 1) {
    c11_i_y[c11_i582] = c11_h_y[c11_i582];
  }

  for (c11_i583 = 0; c11_i583 < 3; c11_i583 = c11_i583 + 1) {
    c11_g_x[c11_i583] = c11_f_x[c11_i583];
  }

  for (c11_i584 = 0; c11_i584 < 3; c11_i584 = c11_i584 + 1) {
    c11_j_y[c11_i584] = c11_i_y[c11_i584];
  }

  for (c11_i585 = 0; c11_i585 < 3; c11_i585 = c11_i585 + 1) {
    c11_h_x[c11_i585] = c11_g_x[c11_i585];
  }

  for (c11_i586 = 0; c11_i586 < 3; c11_i586 = c11_i586 + 1) {
    c11_k_y[c11_i586] = c11_j_y[c11_i586];
  }

  c11_l_y = c11_ceval_xdot(chartInstance, 3, c11_h_x, 1, 1, c11_k_y, 1, 1);
  for (c11_i587 = 0; c11_i587 < 3; c11_i587 = c11_i587 + 1) {
    c11_d_a[c11_i587] = c11_w1[c11_i587];
  }

  for (c11_i588 = 0; c11_i588 < 3; c11_i588 = c11_i588 + 1) {
    c11_d_b[c11_i588] = c11_v[c11_i588];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i589 = 0; c11_i589 < 3; c11_i589 = c11_i589 + 1) {
    c11_i_x[c11_i589] = c11_d_a[c11_i589];
  }

  for (c11_i590 = 0; c11_i590 < 3; c11_i590 = c11_i590 + 1) {
    c11_m_y[c11_i590] = c11_d_b[c11_i590];
  }

  for (c11_i591 = 0; c11_i591 < 3; c11_i591 = c11_i591 + 1) {
    c11_j_x[c11_i591] = c11_i_x[c11_i591];
  }

  for (c11_i592 = 0; c11_i592 < 3; c11_i592 = c11_i592 + 1) {
    c11_n_y[c11_i592] = c11_m_y[c11_i592];
  }

  for (c11_i593 = 0; c11_i593 < 3; c11_i593 = c11_i593 + 1) {
    c11_k_x[c11_i593] = c11_j_x[c11_i593];
  }

  for (c11_i594 = 0; c11_i594 < 3; c11_i594 = c11_i594 + 1) {
    c11_o_y[c11_i594] = c11_n_y[c11_i594];
  }

  for (c11_i595 = 0; c11_i595 < 3; c11_i595 = c11_i595 + 1) {
    c11_l_x[c11_i595] = c11_k_x[c11_i595];
  }

  for (c11_i596 = 0; c11_i596 < 3; c11_i596 = c11_i596 + 1) {
    c11_p_y[c11_i596] = c11_o_y[c11_i596];
  }

  c11_q_y = c11_ceval_xdot(chartInstance, 3, c11_l_x, 1, 1, c11_p_y, 1, 1);
  for (c11_i597 = 0; c11_i597 < 3; c11_i597 = c11_i597 + 1) {
    c11_e_a[c11_i597] = c11_w1[c11_i597];
  }

  for (c11_i598 = 0; c11_i598 < 3; c11_i598 = c11_i598 + 1) {
    c11_e_b[c11_i598] = c11_w2[c11_i598];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i599 = 0; c11_i599 < 3; c11_i599 = c11_i599 + 1) {
    c11_m_x[c11_i599] = c11_e_a[c11_i599];
  }

  for (c11_i600 = 0; c11_i600 < 3; c11_i600 = c11_i600 + 1) {
    c11_r_y[c11_i600] = c11_e_b[c11_i600];
  }

  for (c11_i601 = 0; c11_i601 < 3; c11_i601 = c11_i601 + 1) {
    c11_n_x[c11_i601] = c11_m_x[c11_i601];
  }

  for (c11_i602 = 0; c11_i602 < 3; c11_i602 = c11_i602 + 1) {
    c11_s_y[c11_i602] = c11_r_y[c11_i602];
  }

  for (c11_i603 = 0; c11_i603 < 3; c11_i603 = c11_i603 + 1) {
    c11_o_x[c11_i603] = c11_n_x[c11_i603];
  }

  for (c11_i604 = 0; c11_i604 < 3; c11_i604 = c11_i604 + 1) {
    c11_t_y[c11_i604] = c11_s_y[c11_i604];
  }

  for (c11_i605 = 0; c11_i605 < 3; c11_i605 = c11_i605 + 1) {
    c11_p_x[c11_i605] = c11_o_x[c11_i605];
  }

  for (c11_i606 = 0; c11_i606 < 3; c11_i606 = c11_i606 + 1) {
    c11_u_y[c11_i606] = c11_t_y[c11_i606];
  }

  c11_v_y = c11_ceval_xdot(chartInstance, 3, c11_p_x, 1, 1, c11_u_y, 1, 1);
  for (c11_i607 = 0; c11_i607 < 3; c11_i607 = c11_i607 + 1) {
    c11_f_a[c11_i607] = c11_w1[c11_i607];
  }

  for (c11_i608 = 0; c11_i608 < 3; c11_i608 = c11_i608 + 1) {
    c11_f_b[c11_i608] = c11_w2[c11_i608];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i609 = 0; c11_i609 < 3; c11_i609 = c11_i609 + 1) {
    c11_q_x[c11_i609] = c11_f_a[c11_i609];
  }

  for (c11_i610 = 0; c11_i610 < 3; c11_i610 = c11_i610 + 1) {
    c11_w_y[c11_i610] = c11_f_b[c11_i610];
  }

  for (c11_i611 = 0; c11_i611 < 3; c11_i611 = c11_i611 + 1) {
    c11_r_x[c11_i611] = c11_q_x[c11_i611];
  }

  for (c11_i612 = 0; c11_i612 < 3; c11_i612 = c11_i612 + 1) {
    c11_x_y[c11_i612] = c11_w_y[c11_i612];
  }

  for (c11_i613 = 0; c11_i613 < 3; c11_i613 = c11_i613 + 1) {
    c11_s_x[c11_i613] = c11_r_x[c11_i613];
  }

  for (c11_i614 = 0; c11_i614 < 3; c11_i614 = c11_i614 + 1) {
    c11_y_y[c11_i614] = c11_x_y[c11_i614];
  }

  for (c11_i615 = 0; c11_i615 < 3; c11_i615 = c11_i615 + 1) {
    c11_t_x[c11_i615] = c11_s_x[c11_i615];
  }

  for (c11_i616 = 0; c11_i616 < 3; c11_i616 = c11_i616 + 1) {
    c11_ab_y[c11_i616] = c11_y_y[c11_i616];
  }

  c11_bb_y = c11_ceval_xdot(chartInstance, 3, c11_t_x, 1, 1, c11_ab_y, 1, 1);
  c11_g_a = c11_v_y;
  c11_g_b = c11_bb_y;
  c11_cb_y = c11_g_a * c11_g_b;
  c11_A = c11_l_y - c11_q_y;
  c11_B = c11_cb_y - 1.0;
  c11_u_x = c11_A;
  c11_db_y = c11_B;
  c11_v_x = c11_u_x;
  c11_eb_y = c11_db_y;
  c11_w_x = c11_v_x;
  c11_fb_y = c11_eb_y;
  c11_alpha = c11_w_x / c11_fb_y;
  _SFD_SCRIPT_CALL(6, 24);
  for (c11_i617 = 0; c11_i617 < 3; c11_i617 = c11_i617 + 1) {
    c11_h_a[c11_i617] = c11_w1[c11_i617];
  }

  for (c11_i618 = 0; c11_i618 < 3; c11_i618 = c11_i618 + 1) {
    c11_h_b[c11_i618] = c11_w2[c11_i618];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i619 = 0; c11_i619 < 3; c11_i619 = c11_i619 + 1) {
    c11_x_x[c11_i619] = c11_h_a[c11_i619];
  }

  for (c11_i620 = 0; c11_i620 < 3; c11_i620 = c11_i620 + 1) {
    c11_gb_y[c11_i620] = c11_h_b[c11_i620];
  }

  for (c11_i621 = 0; c11_i621 < 3; c11_i621 = c11_i621 + 1) {
    c11_y_x[c11_i621] = c11_x_x[c11_i621];
  }

  for (c11_i622 = 0; c11_i622 < 3; c11_i622 = c11_i622 + 1) {
    c11_hb_y[c11_i622] = c11_gb_y[c11_i622];
  }

  for (c11_i623 = 0; c11_i623 < 3; c11_i623 = c11_i623 + 1) {
    c11_ab_x[c11_i623] = c11_y_x[c11_i623];
  }

  for (c11_i624 = 0; c11_i624 < 3; c11_i624 = c11_i624 + 1) {
    c11_ib_y[c11_i624] = c11_hb_y[c11_i624];
  }

  for (c11_i625 = 0; c11_i625 < 3; c11_i625 = c11_i625 + 1) {
    c11_bb_x[c11_i625] = c11_ab_x[c11_i625];
  }

  for (c11_i626 = 0; c11_i626 < 3; c11_i626 = c11_i626 + 1) {
    c11_jb_y[c11_i626] = c11_ib_y[c11_i626];
  }

  c11_kb_y = c11_ceval_xdot(chartInstance, 3, c11_bb_x, 1, 1, c11_jb_y, 1, 1);
  c11_i_a = c11_kb_y;
  for (c11_i627 = 0; c11_i627 < 3; c11_i627 = c11_i627 + 1) {
    c11_i_b[c11_i627] = c11_w1[c11_i627];
  }

  for (c11_i628 = 0; c11_i628 < 3; c11_i628 = c11_i628 + 1) {
    c11_lb_y[c11_i628] = c11_i_a * c11_i_b[c11_i628];
  }

  for (c11_i629 = 0; c11_i629 < 3; c11_i629 = c11_i629 + 1) {
    c11_j_a[c11_i629] = c11_lb_y[c11_i629];
  }

  for (c11_i630 = 0; c11_i630 < 3; c11_i630 = c11_i630 + 1) {
    c11_j_b[c11_i630] = c11_v[c11_i630];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i631 = 0; c11_i631 < 3; c11_i631 = c11_i631 + 1) {
    c11_cb_x[c11_i631] = c11_j_a[c11_i631];
  }

  for (c11_i632 = 0; c11_i632 < 3; c11_i632 = c11_i632 + 1) {
    c11_mb_y[c11_i632] = c11_j_b[c11_i632];
  }

  for (c11_i633 = 0; c11_i633 < 3; c11_i633 = c11_i633 + 1) {
    c11_db_x[c11_i633] = c11_cb_x[c11_i633];
  }

  for (c11_i634 = 0; c11_i634 < 3; c11_i634 = c11_i634 + 1) {
    c11_nb_y[c11_i634] = c11_mb_y[c11_i634];
  }

  for (c11_i635 = 0; c11_i635 < 3; c11_i635 = c11_i635 + 1) {
    c11_eb_x[c11_i635] = c11_db_x[c11_i635];
  }

  for (c11_i636 = 0; c11_i636 < 3; c11_i636 = c11_i636 + 1) {
    c11_ob_y[c11_i636] = c11_nb_y[c11_i636];
  }

  for (c11_i637 = 0; c11_i637 < 3; c11_i637 = c11_i637 + 1) {
    c11_fb_x[c11_i637] = c11_eb_x[c11_i637];
  }

  for (c11_i638 = 0; c11_i638 < 3; c11_i638 = c11_i638 + 1) {
    c11_pb_y[c11_i638] = c11_ob_y[c11_i638];
  }

  c11_qb_y = c11_ceval_xdot(chartInstance, 3, c11_fb_x, 1, 1, c11_pb_y, 1, 1);
  for (c11_i639 = 0; c11_i639 < 3; c11_i639 = c11_i639 + 1) {
    c11_k_a[c11_i639] = c11_w2[c11_i639];
  }

  for (c11_i640 = 0; c11_i640 < 3; c11_i640 = c11_i640 + 1) {
    c11_k_b[c11_i640] = c11_u[c11_i640];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i641 = 0; c11_i641 < 3; c11_i641 = c11_i641 + 1) {
    c11_gb_x[c11_i641] = c11_k_a[c11_i641];
  }

  for (c11_i642 = 0; c11_i642 < 3; c11_i642 = c11_i642 + 1) {
    c11_rb_y[c11_i642] = c11_k_b[c11_i642];
  }

  for (c11_i643 = 0; c11_i643 < 3; c11_i643 = c11_i643 + 1) {
    c11_hb_x[c11_i643] = c11_gb_x[c11_i643];
  }

  for (c11_i644 = 0; c11_i644 < 3; c11_i644 = c11_i644 + 1) {
    c11_sb_y[c11_i644] = c11_rb_y[c11_i644];
  }

  for (c11_i645 = 0; c11_i645 < 3; c11_i645 = c11_i645 + 1) {
    c11_ib_x[c11_i645] = c11_hb_x[c11_i645];
  }

  for (c11_i646 = 0; c11_i646 < 3; c11_i646 = c11_i646 + 1) {
    c11_tb_y[c11_i646] = c11_sb_y[c11_i646];
  }

  for (c11_i647 = 0; c11_i647 < 3; c11_i647 = c11_i647 + 1) {
    c11_jb_x[c11_i647] = c11_ib_x[c11_i647];
  }

  for (c11_i648 = 0; c11_i648 < 3; c11_i648 = c11_i648 + 1) {
    c11_ub_y[c11_i648] = c11_tb_y[c11_i648];
  }

  c11_vb_y = c11_ceval_xdot(chartInstance, 3, c11_jb_x, 1, 1, c11_ub_y, 1, 1);
  for (c11_i649 = 0; c11_i649 < 3; c11_i649 = c11_i649 + 1) {
    c11_l_a[c11_i649] = c11_w1[c11_i649];
  }

  for (c11_i650 = 0; c11_i650 < 3; c11_i650 = c11_i650 + 1) {
    c11_l_b[c11_i650] = c11_w2[c11_i650];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i651 = 0; c11_i651 < 3; c11_i651 = c11_i651 + 1) {
    c11_kb_x[c11_i651] = c11_l_a[c11_i651];
  }

  for (c11_i652 = 0; c11_i652 < 3; c11_i652 = c11_i652 + 1) {
    c11_wb_y[c11_i652] = c11_l_b[c11_i652];
  }

  for (c11_i653 = 0; c11_i653 < 3; c11_i653 = c11_i653 + 1) {
    c11_lb_x[c11_i653] = c11_kb_x[c11_i653];
  }

  for (c11_i654 = 0; c11_i654 < 3; c11_i654 = c11_i654 + 1) {
    c11_xb_y[c11_i654] = c11_wb_y[c11_i654];
  }

  for (c11_i655 = 0; c11_i655 < 3; c11_i655 = c11_i655 + 1) {
    c11_mb_x[c11_i655] = c11_lb_x[c11_i655];
  }

  for (c11_i656 = 0; c11_i656 < 3; c11_i656 = c11_i656 + 1) {
    c11_yb_y[c11_i656] = c11_xb_y[c11_i656];
  }

  for (c11_i657 = 0; c11_i657 < 3; c11_i657 = c11_i657 + 1) {
    c11_nb_x[c11_i657] = c11_mb_x[c11_i657];
  }

  for (c11_i658 = 0; c11_i658 < 3; c11_i658 = c11_i658 + 1) {
    c11_ac_y[c11_i658] = c11_yb_y[c11_i658];
  }

  c11_bc_y = c11_ceval_xdot(chartInstance, 3, c11_nb_x, 1, 1, c11_ac_y, 1, 1);
  for (c11_i659 = 0; c11_i659 < 3; c11_i659 = c11_i659 + 1) {
    c11_m_a[c11_i659] = c11_w1[c11_i659];
  }

  for (c11_i660 = 0; c11_i660 < 3; c11_i660 = c11_i660 + 1) {
    c11_m_b[c11_i660] = c11_w2[c11_i660];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i661 = 0; c11_i661 < 3; c11_i661 = c11_i661 + 1) {
    c11_ob_x[c11_i661] = c11_m_a[c11_i661];
  }

  for (c11_i662 = 0; c11_i662 < 3; c11_i662 = c11_i662 + 1) {
    c11_cc_y[c11_i662] = c11_m_b[c11_i662];
  }

  for (c11_i663 = 0; c11_i663 < 3; c11_i663 = c11_i663 + 1) {
    c11_pb_x[c11_i663] = c11_ob_x[c11_i663];
  }

  for (c11_i664 = 0; c11_i664 < 3; c11_i664 = c11_i664 + 1) {
    c11_dc_y[c11_i664] = c11_cc_y[c11_i664];
  }

  for (c11_i665 = 0; c11_i665 < 3; c11_i665 = c11_i665 + 1) {
    c11_qb_x[c11_i665] = c11_pb_x[c11_i665];
  }

  for (c11_i666 = 0; c11_i666 < 3; c11_i666 = c11_i666 + 1) {
    c11_ec_y[c11_i666] = c11_dc_y[c11_i666];
  }

  for (c11_i667 = 0; c11_i667 < 3; c11_i667 = c11_i667 + 1) {
    c11_rb_x[c11_i667] = c11_qb_x[c11_i667];
  }

  for (c11_i668 = 0; c11_i668 < 3; c11_i668 = c11_i668 + 1) {
    c11_fc_y[c11_i668] = c11_ec_y[c11_i668];
  }

  c11_gc_y = c11_ceval_xdot(chartInstance, 3, c11_rb_x, 1, 1, c11_fc_y, 1, 1);
  c11_n_a = c11_bc_y;
  c11_n_b = c11_gc_y;
  c11_hc_y = c11_n_a * c11_n_b;
  c11_b_A = c11_qb_y - c11_vb_y;
  c11_b_B = c11_hc_y - 1.0;
  c11_sb_x = c11_b_A;
  c11_ic_y = c11_b_B;
  c11_tb_x = c11_sb_x;
  c11_jc_y = c11_ic_y;
  c11_ub_x = c11_tb_x;
  c11_kc_y = c11_jc_y;
  c11_beta = c11_ub_x / c11_kc_y;
  _SFD_SCRIPT_CALL(6, 26);
  for (c11_i669 = 0; c11_i669 < 3; c11_i669 = c11_i669 + 1) {
    c11_o_a[c11_i669] = c11_u[c11_i669];
  }

  for (c11_i670 = 0; c11_i670 < 3; c11_i670 = c11_i670 + 1) {
    c11_o_b[c11_i670] = c11_u[c11_i670];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i671 = 0; c11_i671 < 3; c11_i671 = c11_i671 + 1) {
    c11_vb_x[c11_i671] = c11_o_a[c11_i671];
  }

  for (c11_i672 = 0; c11_i672 < 3; c11_i672 = c11_i672 + 1) {
    c11_lc_y[c11_i672] = c11_o_b[c11_i672];
  }

  for (c11_i673 = 0; c11_i673 < 3; c11_i673 = c11_i673 + 1) {
    c11_wb_x[c11_i673] = c11_vb_x[c11_i673];
  }

  for (c11_i674 = 0; c11_i674 < 3; c11_i674 = c11_i674 + 1) {
    c11_mc_y[c11_i674] = c11_lc_y[c11_i674];
  }

  for (c11_i675 = 0; c11_i675 < 3; c11_i675 = c11_i675 + 1) {
    c11_xb_x[c11_i675] = c11_wb_x[c11_i675];
  }

  for (c11_i676 = 0; c11_i676 < 3; c11_i676 = c11_i676 + 1) {
    c11_nc_y[c11_i676] = c11_mc_y[c11_i676];
  }

  for (c11_i677 = 0; c11_i677 < 3; c11_i677 = c11_i677 + 1) {
    c11_yb_x[c11_i677] = c11_xb_x[c11_i677];
  }

  for (c11_i678 = 0; c11_i678 < 3; c11_i678 = c11_i678 + 1) {
    c11_oc_y[c11_i678] = c11_nc_y[c11_i678];
  }

  c11_pc_y = c11_ceval_xdot(chartInstance, 3, c11_yb_x, 1, 1, c11_oc_y, 1, 1);
  c11_p_a = c11_alpha;
  c11_p_b = c11_alpha;
  c11_qc_y = c11_p_a * c11_p_b;
  c11_q_a = c11_beta;
  c11_q_b = c11_beta;
  c11_rc_y = c11_q_a * c11_q_b;
  c11_r_b = c11_beta;
  c11_sc_y = 2.0 * c11_r_b;
  c11_r_a = c11_sc_y;
  c11_s_b = c11_alpha;
  c11_tc_y = c11_r_a * c11_s_b;
  c11_s_a = c11_tc_y;
  for (c11_i679 = 0; c11_i679 < 3; c11_i679 = c11_i679 + 1) {
    c11_t_b[c11_i679] = c11_w1[c11_i679];
  }

  for (c11_i680 = 0; c11_i680 < 3; c11_i680 = c11_i680 + 1) {
    c11_uc_y[c11_i680] = c11_s_a * c11_t_b[c11_i680];
  }

  for (c11_i681 = 0; c11_i681 < 3; c11_i681 = c11_i681 + 1) {
    c11_t_a[c11_i681] = c11_uc_y[c11_i681];
  }

  for (c11_i682 = 0; c11_i682 < 3; c11_i682 = c11_i682 + 1) {
    c11_u_b[c11_i682] = c11_w2[c11_i682];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i683 = 0; c11_i683 < 3; c11_i683 = c11_i683 + 1) {
    c11_ac_x[c11_i683] = c11_t_a[c11_i683];
  }

  for (c11_i684 = 0; c11_i684 < 3; c11_i684 = c11_i684 + 1) {
    c11_vc_y[c11_i684] = c11_u_b[c11_i684];
  }

  for (c11_i685 = 0; c11_i685 < 3; c11_i685 = c11_i685 + 1) {
    c11_bc_x[c11_i685] = c11_ac_x[c11_i685];
  }

  for (c11_i686 = 0; c11_i686 < 3; c11_i686 = c11_i686 + 1) {
    c11_wc_y[c11_i686] = c11_vc_y[c11_i686];
  }

  for (c11_i687 = 0; c11_i687 < 3; c11_i687 = c11_i687 + 1) {
    c11_cc_x[c11_i687] = c11_bc_x[c11_i687];
  }

  for (c11_i688 = 0; c11_i688 < 3; c11_i688 = c11_i688 + 1) {
    c11_xc_y[c11_i688] = c11_wc_y[c11_i688];
  }

  for (c11_i689 = 0; c11_i689 < 3; c11_i689 = c11_i689 + 1) {
    c11_dc_x[c11_i689] = c11_cc_x[c11_i689];
  }

  for (c11_i690 = 0; c11_i690 < 3; c11_i690 = c11_i690 + 1) {
    c11_yc_y[c11_i690] = c11_xc_y[c11_i690];
  }

  c11_ad_y = c11_ceval_xdot(chartInstance, 3, c11_dc_x, 1, 1, c11_yc_y, 1, 1);
  for (c11_i691 = 0; c11_i691 < 3; c11_i691 = c11_i691 + 1) {
    c11_d_w1[c11_i691] = c11_w1[c11_i691];
  }

  for (c11_i692 = 0; c11_i692 < 3; c11_i692 = c11_i692 + 1) {
    c11_d_w2[c11_i692] = c11_w2[c11_i692];
  }

  c11_cross(chartInstance, c11_d_w1, c11_d_w2, c11_dv33);
  for (c11_i693 = 0; c11_i693 < 3; c11_i693 = c11_i693 + 1) {
    c11_u_a[c11_i693] = c11_dv33[c11_i693];
  }

  for (c11_i694 = 0; c11_i694 < 3; c11_i694 = c11_i694 + 1) {
    c11_e_w1[c11_i694] = c11_w1[c11_i694];
  }

  for (c11_i695 = 0; c11_i695 < 3; c11_i695 = c11_i695 + 1) {
    c11_e_w2[c11_i695] = c11_w2[c11_i695];
  }

  c11_cross(chartInstance, c11_e_w1, c11_e_w2, c11_v_b);
  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i696 = 0; c11_i696 < 3; c11_i696 = c11_i696 + 1) {
    c11_ec_x[c11_i696] = c11_u_a[c11_i696];
  }

  for (c11_i697 = 0; c11_i697 < 3; c11_i697 = c11_i697 + 1) {
    c11_bd_y[c11_i697] = c11_v_b[c11_i697];
  }

  for (c11_i698 = 0; c11_i698 < 3; c11_i698 = c11_i698 + 1) {
    c11_fc_x[c11_i698] = c11_ec_x[c11_i698];
  }

  for (c11_i699 = 0; c11_i699 < 3; c11_i699 = c11_i699 + 1) {
    c11_cd_y[c11_i699] = c11_bd_y[c11_i699];
  }

  for (c11_i700 = 0; c11_i700 < 3; c11_i700 = c11_i700 + 1) {
    c11_gc_x[c11_i700] = c11_fc_x[c11_i700];
  }

  for (c11_i701 = 0; c11_i701 < 3; c11_i701 = c11_i701 + 1) {
    c11_dd_y[c11_i701] = c11_cd_y[c11_i701];
  }

  for (c11_i702 = 0; c11_i702 < 3; c11_i702 = c11_i702 + 1) {
    c11_hc_x[c11_i702] = c11_gc_x[c11_i702];
  }

  for (c11_i703 = 0; c11_i703 < 3; c11_i703 = c11_i703 + 1) {
    c11_ed_y[c11_i703] = c11_dd_y[c11_i703];
  }

  c11_fd_y = c11_ceval_xdot(chartInstance, 3, c11_hc_x, 1, 1, c11_ed_y, 1, 1);
  c11_c_A = ((c11_pc_y - c11_qc_y) - c11_rc_y) - c11_ad_y;
  c11_c_B = c11_fd_y;
  c11_ic_x = c11_c_A;
  c11_gd_y = c11_c_B;
  c11_jc_x = c11_ic_x;
  c11_hd_y = c11_gd_y;
  c11_kc_x = c11_jc_x;
  c11_id_y = c11_hd_y;
  c11_ySqu = c11_kc_x / c11_id_y;
  _SFD_SCRIPT_CALL(6, 28);
  if (CV_SCRIPT_IF(6, 0, c11_ySqu > 0.0)) {
    _SFD_SCRIPT_CALL(6, 29);
    *c11_Nsol = 2.0;
  } else {
    _SFD_SCRIPT_CALL(6, 30);
    if (CV_SCRIPT_IF(6, 1, c11_ySqu == 0.0)) {
      _SFD_SCRIPT_CALL(6, 31);
      *c11_Nsol = 1.0;
    } else {
      _SFD_SCRIPT_CALL(6, 33);
      *c11_Nsol = 0.0;
    }
  }

  _SFD_SCRIPT_CALL(6, 36);
  if (CV_SCRIPT_IF(6, 2, c11_ySqu >= 0.0)) {
    c11_i = 1.0;
    c11_b_i = 1.0;
    while (c11_b_i <= 2.0) {
      c11_i = c11_b_i;
      CV_SCRIPT_FOR(6, 0, 1);
      _SFD_SCRIPT_CALL(6, 39);
      c11_w_b = c11_i;
      c11_jd_y = 2.0 * c11_w_b;
      c11_lc_x = c11_ySqu;
      c11_mc_x = c11_lc_x;
      c11_nc_x = c11_mc_x;
      c11_mc_x = c11_nc_x;
      c11_mc_x = muDoubleScalarSqrt(c11_mc_x);
      c11_v_a = c11_jd_y - 3.0;
      c11_x_b = c11_mc_x;
      c11_y = c11_v_a * c11_x_b;

      /*  could have two solutions in this step */
      _SFD_SCRIPT_CALL(6, 41);
      c11_w_a = c11_alpha;
      for (c11_i704 = 0; c11_i704 < 3; c11_i704 = c11_i704 + 1) {
        c11_y_b[c11_i704] = c11_w1[c11_i704];
      }

      for (c11_i705 = 0; c11_i705 < 3; c11_i705 = c11_i705 + 1) {
        c11_kd_y[c11_i705] = c11_w_a * c11_y_b[c11_i705];
      }

      c11_x_a = c11_beta;
      for (c11_i706 = 0; c11_i706 < 3; c11_i706 = c11_i706 + 1) {
        c11_ab_b[c11_i706] = c11_w2[c11_i706];
      }

      for (c11_i707 = 0; c11_i707 < 3; c11_i707 = c11_i707 + 1) {
        c11_ld_y[c11_i707] = c11_x_a * c11_ab_b[c11_i707];
      }

      c11_y_a = c11_y;
      for (c11_i708 = 0; c11_i708 < 3; c11_i708 = c11_i708 + 1) {
        c11_f_w1[c11_i708] = c11_w1[c11_i708];
      }

      for (c11_i709 = 0; c11_i709 < 3; c11_i709 = c11_i709 + 1) {
        c11_f_w2[c11_i709] = c11_w2[c11_i709];
      }

      c11_cross(chartInstance, c11_f_w1, c11_f_w2, c11_bb_b);
      for (c11_i710 = 0; c11_i710 < 3; c11_i710 = c11_i710 + 1) {
        c11_md_y[c11_i710] = c11_y_a * c11_bb_b[c11_i710];
      }

      for (c11_i711 = 0; c11_i711 < 3; c11_i711 = c11_i711 + 1) {
        c11_z[c11_i711] = (c11_kd_y[c11_i711] + c11_ld_y[c11_i711]) -
          c11_md_y[c11_i711];
      }

      _SFD_SCRIPT_CALL(6, 43);
      for (c11_i712 = 0; c11_i712 < 3; c11_i712 = c11_i712 + 1) {
        c11_c[c11_i712] = c11_z[c11_i712] + c11_r[c11_i712];
      }

      /*  the common point in the rotation if there are solutions */
      _SFD_SCRIPT_CALL(6, 45);
      for (c11_i713 = 0; c11_i713 < 6; c11_i713 = c11_i713 + 1) {
        c11_b_kx2[c11_i713] = c11_kx2[c11_i713];
      }

      for (c11_i714 = 0; c11_i714 < 4; c11_i714 = c11_i714 + 1) {
        c11_b_p[c11_i714] = c11_p[c11_i714];
      }

      for (c11_i715 = 0; c11_i715 < 3; c11_i715 = c11_i715 + 1) {
        c11_b_c[c11_i715] = c11_c[c11_i715];
      }

      c11_theta2[(int32_T)c11_i - 1] = c11_b_subPro1(chartInstance, c11_b_kx2,
        c11_b_p, c11_b_c);
      _SFD_SCRIPT_CALL(6, 46);
      for (c11_i716 = 0; c11_i716 < 6; c11_i716 = c11_i716 + 1) {
        c11_b_kx1[c11_i716] = c11_kx1[c11_i716];
      }

      for (c11_i717 = 0; c11_i717 < 3; c11_i717 = c11_i717 + 1) {
        c11_c_c[c11_i717] = c11_c[c11_i717];
      }

      for (c11_i718 = 0; c11_i718 < 4; c11_i718 = c11_i718 + 1) {
        c11_b_q[c11_i718] = c11_q[c11_i718];
      }

      c11_theta1[(int32_T)c11_i - 1] = c11_c_subPro1(chartInstance, c11_b_kx1,
        c11_c_c, c11_b_q);
      c11_b_i = c11_b_i + 1.0;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_SCRIPT_FOR(6, 0, 0);
  }

  _SFD_SCRIPT_CALL(6, -46);
  sf_debug_symbol_scope_pop();
}

static void c11_findCommon(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_w1[3], real_T c11_w2[3], real_T c11_r1[3], real_T
  c11_r2[3], real_T c11_r[3])
{
  uint32_T c11_debug_family_var_map[10];
  real_T c11_A[4];
  real_T c11_vec[2];
  real_T c11_cof[2];
  real_T c11_nargin = 4.0;
  real_T c11_nargout = 1.0;
  real_T c11_b_r2[2];
  int32_T c11_i719;
  int32_T c11_i720;
  real_T c11_b_A[4];
  real_T c11_c_r2[2];
  int32_T c11_i721;
  int32_T c11_i722;
  real_T c11_c_A[4];
  real_T c11_d_r2[2];
  int32_T c11_i723;
  int32_T c11_i724;
  real_T c11_d_A[4];
  int32_T c11_i725;
  real_T c11_B[2];
  int32_T c11_i726;
  real_T c11_e_A[4];
  int32_T c11_i727;
  real_T c11_b_B[2];
  int32_T c11_i728;
  real_T c11_f_A[4];
  int32_T c11_i729;
  real_T c11_c_B[2];
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_y;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_b_y;
  real_T c11_d;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_c_y;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_d_y;
  real_T c11_b_d;
  int32_T c11_b_r1;
  int32_T c11_e_r2;
  real_T c11_k_x;
  real_T c11_e_y;
  real_T c11_l_x;
  real_T c11_f_y;
  real_T c11_a21;
  real_T c11_a;
  real_T c11_b;
  real_T c11_g_y;
  real_T c11_a22;
  real_T c11_b_a;
  real_T c11_b_b;
  real_T c11_h_y;
  real_T c11_m_x;
  real_T c11_i_y;
  real_T c11_n_x;
  real_T c11_j_y;
  real_T c11_z;
  real_T c11_c_a;
  real_T c11_c_b;
  real_T c11_k_y;
  real_T c11_o_x;
  real_T c11_l_y;
  real_T c11_p_x;
  real_T c11_m_y;
  real_T c11_b_z;
  int32_T c11_i730;
  real_T c11_d_a[3];
  real_T c11_d_b;
  int32_T c11_i731;
  real_T c11_n_y[3];
  int32_T c11_i732;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c11_i_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_A, c11_m_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_vec, c11_j_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_cof, c11_j_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_w1, c11_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_w2, c11_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c11_r1, c11_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c11_r2, c11_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c11_r, c11_d_sf_marshall, 9U);
  CV_SCRIPT_FCN(6, 1);
  _SFD_SCRIPT_CALL(6, 56);
  c11_A[0] = c11_w1[0];
  c11_A[2] = -c11_w2[0];
  c11_A[1] = c11_w1[1];
  c11_A[3] = -c11_w2[1];
  _SFD_SCRIPT_CALL(6, 57);
  c11_b_r2[0] = c11_r2[0] - c11_r1[0];
  c11_b_r2[1] = c11_r2[1] - c11_r1[1];
  for (c11_i719 = 0; c11_i719 < 2; c11_i719 = c11_i719 + 1) {
    c11_vec[c11_i719] = c11_b_r2[c11_i719];
  }

  _SFD_SCRIPT_CALL(6, 59);
  for (c11_i720 = 0; c11_i720 < 4; c11_i720 = c11_i720 + 1) {
    c11_b_A[c11_i720] = c11_A[c11_i720];
  }

  if (CV_SCRIPT_IF(6, 3, c11_det(chartInstance, c11_b_A) == 0.0)) {
    /*  if the first two set of para are parallel */
    _SFD_SCRIPT_CALL(6, 60);
    c11_A[0] = c11_w1[0];
    c11_A[2] = -c11_w2[0];
    c11_A[1] = c11_w1[2];
    c11_A[3] = -c11_w2[2];
    _SFD_SCRIPT_CALL(6, 61);
    c11_c_r2[0] = c11_r2[0] - c11_r1[0];
    c11_c_r2[1] = c11_r2[2] - c11_r1[2];
    for (c11_i721 = 0; c11_i721 < 2; c11_i721 = c11_i721 + 1) {
      c11_vec[c11_i721] = c11_c_r2[c11_i721];
    }
  }

  _SFD_SCRIPT_CALL(6, 64);
  for (c11_i722 = 0; c11_i722 < 4; c11_i722 = c11_i722 + 1) {
    c11_c_A[c11_i722] = c11_A[c11_i722];
  }

  if (CV_SCRIPT_IF(6, 4, c11_det(chartInstance, c11_c_A) == 0.0)) {
    _SFD_SCRIPT_CALL(6, 65);
    c11_A[0] = c11_w1[1];
    c11_A[2] = -c11_w2[1];
    c11_A[1] = c11_w1[2];
    c11_A[3] = -c11_w2[2];
    _SFD_SCRIPT_CALL(6, 66);
    c11_d_r2[0] = c11_r2[1] - c11_r1[1];
    c11_d_r2[1] = c11_r2[2] - c11_r1[2];
    for (c11_i723 = 0; c11_i723 < 2; c11_i723 = c11_i723 + 1) {
      c11_vec[c11_i723] = c11_d_r2[c11_i723];
    }
  }

  _SFD_SCRIPT_CALL(6, 69);
  for (c11_i724 = 0; c11_i724 < 4; c11_i724 = c11_i724 + 1) {
    c11_d_A[c11_i724] = c11_A[c11_i724];
  }

  for (c11_i725 = 0; c11_i725 < 2; c11_i725 = c11_i725 + 1) {
    c11_B[c11_i725] = c11_vec[c11_i725];
  }

  for (c11_i726 = 0; c11_i726 < 4; c11_i726 = c11_i726 + 1) {
    c11_e_A[c11_i726] = c11_d_A[c11_i726];
  }

  for (c11_i727 = 0; c11_i727 < 2; c11_i727 = c11_i727 + 1) {
    c11_b_B[c11_i727] = c11_B[c11_i727];
  }

  for (c11_i728 = 0; c11_i728 < 4; c11_i728 = c11_i728 + 1) {
    c11_f_A[c11_i728] = c11_e_A[c11_i728];
  }

  for (c11_i729 = 0; c11_i729 < 2; c11_i729 = c11_i729 + 1) {
    c11_c_B[c11_i729] = c11_b_B[c11_i729];
  }

  c11_x = c11_f_A[1];
  c11_b_x = c11_x;
  c11_c_x = c11_b_x;
  c11_y = muDoubleScalarAbs(c11_c_x);
  c11_d_x = 0.0;
  c11_e_x = c11_d_x;
  c11_b_y = muDoubleScalarAbs(c11_e_x);
  c11_d = c11_y + c11_b_y;
  c11_f_x = c11_f_A[0];
  c11_g_x = c11_f_x;
  c11_h_x = c11_g_x;
  c11_c_y = muDoubleScalarAbs(c11_h_x);
  c11_i_x = 0.0;
  c11_j_x = c11_i_x;
  c11_d_y = muDoubleScalarAbs(c11_j_x);
  c11_b_d = c11_c_y + c11_d_y;
  if (c11_d > c11_b_d) {
    c11_b_r1 = 2;
    c11_e_r2 = 1;
  } else {
    c11_b_r1 = 1;
    c11_e_r2 = 2;
  }

  c11_k_x = c11_f_A[c11_e_r2 - 1];
  c11_e_y = c11_f_A[c11_b_r1 - 1];
  c11_l_x = c11_k_x;
  c11_f_y = c11_e_y;
  c11_a21 = c11_l_x / c11_f_y;
  c11_a = c11_a21;
  c11_b = c11_f_A[c11_b_r1 + 1];
  c11_g_y = c11_a * c11_b;
  c11_a22 = c11_f_A[c11_e_r2 + 1] - c11_g_y;
  if (c11_a22 == 0.0) {
  } else if (c11_f_A[c11_b_r1 - 1] == 0.0) {
  } else {
    goto label_1;
  }

  c11_eml_warning(chartInstance);
 label_1:
  ;
  c11_b_a = c11_c_B[c11_b_r1 - 1];
  c11_b_b = c11_a21;
  c11_h_y = c11_b_a * c11_b_b;
  c11_m_x = c11_c_B[c11_e_r2 - 1] - c11_h_y;
  c11_i_y = c11_a22;
  c11_n_x = c11_m_x;
  c11_j_y = c11_i_y;
  c11_z = c11_n_x / c11_j_y;
  c11_cof[1] = c11_z;
  c11_c_a = c11_cof[1];
  c11_c_b = c11_f_A[c11_b_r1 + 1];
  c11_k_y = c11_c_a * c11_c_b;
  c11_o_x = c11_c_B[c11_b_r1 - 1] - c11_k_y;
  c11_l_y = c11_f_A[c11_b_r1 - 1];
  c11_p_x = c11_o_x;
  c11_m_y = c11_l_y;
  c11_b_z = c11_p_x / c11_m_y;
  c11_cof[0] = c11_b_z;

  /*  get the inverse */
  _SFD_SCRIPT_CALL(6, 71);
  for (c11_i730 = 0; c11_i730 < 3; c11_i730 = c11_i730 + 1) {
    c11_d_a[c11_i730] = c11_w1[c11_i730];
  }

  c11_d_b = c11_cof[0];
  for (c11_i731 = 0; c11_i731 < 3; c11_i731 = c11_i731 + 1) {
    c11_n_y[c11_i731] = c11_d_a[c11_i731] * c11_d_b;
  }

  for (c11_i732 = 0; c11_i732 < 3; c11_i732 = c11_i732 + 1) {
    c11_r[c11_i732] = c11_r1[c11_i732] + c11_n_y[c11_i732];
  }

  _SFD_SCRIPT_CALL(6, -71);
  sf_debug_symbol_scope_pop();
}

static real_T c11_det(SFc11_KinConInstanceStruct *chartInstance, real_T c11_x[4])
{
  real_T c11_y;
  int32_T c11_i733;
  real_T c11_A[4];
  int32_T c11_i734;
  real_T c11_b_x[4];
  int32_T c11_i735;
  real_T c11_b_A[4];
  int32_T c11_i736;
  real_T c11_c_A[4];
  int32_T c11_i737;
  real_T c11_d_A[4];
  int32_T c11_info;
  int32_T c11_ipiv[2];
  real_T c11_e_A[4];
  int32_T c11_i738;
  int32_T c11_i739;
  int32_T c11_b_ipiv[2];
  int32_T c11_i740;
  int32_T c11_i741;
  int32_T c11_c_ipiv[2];
  int32_T c11_i742;
  int32_T c11_i743;
  int32_T c11_d_ipiv[2];
  real_T c11_a;
  real_T c11_b;
  boolean_T c11_isodd;
  for (c11_i733 = 0; c11_i733 < 4; c11_i733 = c11_i733 + 1) {
    c11_A[c11_i733] = c11_x[c11_i733];
  }

  for (c11_i734 = 0; c11_i734 < 4; c11_i734 = c11_i734 + 1) {
    c11_b_x[c11_i734] = c11_A[c11_i734];
  }

  for (c11_i735 = 0; c11_i735 < 4; c11_i735 = c11_i735 + 1) {
    c11_b_A[c11_i735] = c11_b_x[c11_i735];
  }

  for (c11_i736 = 0; c11_i736 < 4; c11_i736 = c11_i736 + 1) {
    c11_c_A[c11_i736] = c11_b_A[c11_i736];
  }

  for (c11_i737 = 0; c11_i737 < 4; c11_i737 = c11_i737 + 1) {
    c11_d_A[c11_i737] = c11_c_A[c11_i737];
  }

  c11_b_eml_matlab_zgetrf(chartInstance, c11_d_A, c11_e_A, c11_ipiv, &c11_info);
  for (c11_i738 = 0; c11_i738 < 4; c11_i738 = c11_i738 + 1) {
    c11_c_A[c11_i738] = c11_e_A[c11_i738];
  }

  for (c11_i739 = 0; c11_i739 < 2; c11_i739 = c11_i739 + 1) {
    c11_b_ipiv[c11_i739] = c11_ipiv[c11_i739];
  }

  for (c11_i740 = 0; c11_i740 < 4; c11_i740 = c11_i740 + 1) {
    c11_b_x[c11_i740] = c11_c_A[c11_i740];
  }

  for (c11_i741 = 0; c11_i741 < 2; c11_i741 = c11_i741 + 1) {
    c11_c_ipiv[c11_i741] = c11_b_ipiv[c11_i741];
  }

  for (c11_i742 = 0; c11_i742 < 4; c11_i742 = c11_i742 + 1) {
    c11_x[c11_i742] = c11_b_x[c11_i742];
  }

  for (c11_i743 = 0; c11_i743 < 2; c11_i743 = c11_i743 + 1) {
    c11_d_ipiv[c11_i743] = c11_c_ipiv[c11_i743];
  }

  c11_y = c11_x[0];
  c11_a = c11_y;
  c11_b = c11_x[3];
  c11_y = c11_a * c11_b;
  c11_isodd = FALSE;
  if ((real_T)c11_d_ipiv[0] > 1.0) {
    c11_isodd = TRUE;
  }

  if (c11_isodd) {
    return -c11_y;
  }

  return c11_y;
}

static void c11_b_eml_matlab_zgetrf(SFc11_KinConInstanceStruct *chartInstance,
  real_T c11_A[4], real_T c11_b_A[4], int32_T c11_ipiv[
  2], int32_T *c11_info)
{
  int32_T c11_i744;
  int32_T c11_i745;
  int32_T c11_i746;
  real_T c11_c_A[4];
  int32_T c11_a;
  int32_T c11_jpiv_offset;
  int32_T c11_b;
  int32_T c11_jpiv;
  int32_T c11_b_b;
  int32_T c11_c;
  int32_T c11_c_b;
  int32_T c11_jprow;
  int32_T c11_i747;
  real_T c11_x[4];
  int32_T c11_iy0;
  int32_T c11_i748;
  int32_T c11_i749;
  real_T c11_b_x[4];
  int32_T c11_b_iy0;
  int32_T c11_i750;
  real_T c11_c_x[4];
  int32_T c11_i751;
  real_T c11_d_x[4];
  real_T c11_e_x[4];
  int32_T c11_i752;
  int32_T c11_i753;
  real_T c11_f_x;
  real_T c11_y;
  real_T c11_g_x;
  real_T c11_b_y;
  real_T c11_z;
  int32_T c11_i754;
  real_T c11_d_A[4];
  int32_T c11_i755;
  int32_T c11_i756;
  real_T c11_e_A[4];
  int32_T c11_i757;
  int32_T c11_i758;
  real_T c11_f_A[4];
  int32_T c11_i759;
  int32_T c11_i760;
  real_T c11_g_A[4];
  for (c11_i744 = 0; c11_i744 < 4; c11_i744 = c11_i744 + 1) {
    c11_b_A[c11_i744] = c11_A[c11_i744];
  }

  c11_eps(chartInstance);
  for (c11_i745 = 0; c11_i745 < 2; c11_i745 = c11_i745 + 1) {
    c11_ipiv[c11_i745] = 1 + c11_i745;
  }

  *c11_info = 0;
  for (c11_i746 = 0; c11_i746 < 4; c11_i746 = c11_i746 + 1) {
    c11_c_A[c11_i746] = c11_b_A[c11_i746];
  }

  c11_a = c11_b_eml_ixamax(chartInstance, c11_c_A);
  c11_jpiv_offset = c11_a - 1;
  c11_b = c11_jpiv_offset;
  c11_jpiv = 1 + c11_b;
  if (c11_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c11_jpiv, 1, 4, 1, 0) - 1] != 0.0)
  {
    if ((real_T)c11_jpiv_offset != 0.0) {
      c11_b_b = c11_jpiv_offset;
      c11_c = 1 + c11_b_b;
      c11_ipiv[0] = c11_c;
      c11_c_b = c11_jpiv_offset;
      c11_jprow = 1 + c11_c_b;
      for (c11_i747 = 0; c11_i747 < 4; c11_i747 = c11_i747 + 1) {
        c11_x[c11_i747] = c11_b_A[c11_i747];
      }

      c11_iy0 = c11_jprow;
      for (c11_i748 = 0; c11_i748 < 4; c11_i748 = c11_i748 + 1) {
        c11_b_A[c11_i748] = c11_x[c11_i748];
      }

      for (c11_i749 = 0; c11_i749 < 4; c11_i749 = c11_i749 + 1) {
        c11_b_x[c11_i749] = c11_b_A[c11_i749];
      }

      c11_b_iy0 = c11_iy0;
      for (c11_i750 = 0; c11_i750 < 4; c11_i750 = c11_i750 + 1) {
        c11_c_x[c11_i750] = c11_b_x[c11_i750];
      }

      for (c11_i751 = 0; c11_i751 < 4; c11_i751 = c11_i751 + 1) {
        c11_d_x[c11_i751] = c11_c_x[c11_i751];
      }

      c11_b_ceval_xswap(chartInstance, 2, c11_d_x, 1, 2, c11_b_iy0, 2, c11_e_x);
      for (c11_i752 = 0; c11_i752 < 4; c11_i752 = c11_i752 + 1) {
        c11_c_x[c11_i752] = c11_e_x[c11_i752];
      }

      for (c11_i753 = 0; c11_i753 < 4; c11_i753 = c11_i753 + 1) {
        c11_b_A[c11_i753] = c11_c_x[c11_i753];
      }
    }

    c11_f_x = c11_b_A[1];
    c11_y = c11_b_A[0];
    c11_g_x = c11_f_x;
    c11_b_y = c11_y;
    c11_z = c11_g_x / c11_b_y;
    c11_b_A[1] = c11_z;
  } else {
    *c11_info = 1;
  }

  for (c11_i754 = 0; c11_i754 < 4; c11_i754 = c11_i754 + 1) {
    c11_d_A[c11_i754] = c11_b_A[c11_i754];
  }

  for (c11_i755 = 0; c11_i755 < 4; c11_i755 = c11_i755 + 1) {
    c11_b_A[c11_i755] = c11_d_A[c11_i755];
  }

  for (c11_i756 = 0; c11_i756 < 4; c11_i756 = c11_i756 + 1) {
    c11_e_A[c11_i756] = c11_b_A[c11_i756];
  }

  for (c11_i757 = 0; c11_i757 < 4; c11_i757 = c11_i757 + 1) {
    c11_b_A[c11_i757] = c11_e_A[c11_i757];
  }

  for (c11_i758 = 0; c11_i758 < 4; c11_i758 = c11_i758 + 1) {
    c11_f_A[c11_i758] = c11_b_A[c11_i758];
  }

  for (c11_i759 = 0; c11_i759 < 4; c11_i759 = c11_i759 + 1) {
    c11_b_A[c11_i759] = c11_f_A[c11_i759];
  }

  for (c11_i760 = 0; c11_i760 < 4; c11_i760 = c11_i760 + 1) {
    c11_g_A[c11_i760] = c11_b_A[c11_i760];
  }

  c11_b_ceval_xger(chartInstance, 1, 1, -1.0, 2, 1, 3, 2, c11_g_A, 4, 2, c11_b_A);
  if ((real_T)*c11_info == 0.0) {
    if (!(c11_b_A[3] != 0.0)) {
      *c11_info = 2;
      return;
    }
  }
}

static int32_T c11_b_eml_ixamax(SFc11_KinConInstanceStruct *chartInstance,
  real_T c11_x[4])
{
  int32_T c11_i761;
  real_T c11_b_x[4];
  int32_T c11_i762;
  real_T c11_c_x[4];
  for (c11_i761 = 0; c11_i761 < 4; c11_i761 = c11_i761 + 1) {
    c11_b_x[c11_i761] = c11_x[c11_i761];
  }

  for (c11_i762 = 0; c11_i762 < 4; c11_i762 = c11_i762 + 1) {
    c11_c_x[c11_i762] = c11_b_x[c11_i762];
  }

  return c11_b_ceval_ixamax(chartInstance, 2, c11_c_x, 1, 1);
}

static int32_T c11_b_ceval_ixamax(SFc11_KinConInstanceStruct *chartInstance,
  int32_T c11_n, real_T c11_x[4], int32_T c11_ix0,
  int32_T c11_incx)
{
  return idamax32(&c11_n, &c11_x[0], &c11_incx);
}

static void c11_b_ceval_xswap(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_n, real_T c11_x[4], int32_T c11_ix0, int32_T
  c11_incx, int32_T c11_iy0, int32_T c11_incy, real_T c11_b_x[4])
{
  int32_T c11_i763;

  /* Empty Loop. */
  for (c11_i763 = 0; c11_i763 < 4; c11_i763 = c11_i763 + 1) {
    c11_b_x[c11_i763] = c11_x[c11_i763];
  }

  dswap32(&c11_n, &c11_b_x[0], &c11_incx, &c11_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK(
           "", c11_iy0, 1, 4, 1, 0) - 1], &c11_incy);
}

static void c11_b_ceval_xger(SFc11_KinConInstanceStruct *chartInstance, int32_T
  c11_m, int32_T c11_n, real_T c11_alpha1, int32_T
  c11_ix0, int32_T c11_incx, int32_T c11_iy0, int32_T c11_incy, real_T c11_A[4],
  int32_T c11_ia0, int32_T c11_lda, real_T c11_b_A[4])
{
  int32_T c11_i764;
  for (c11_i764 = 0; c11_i764 < 4; c11_i764 = c11_i764 + 1) {
    c11_b_A[c11_i764] = c11_A[c11_i764];
  }

  dger32(&c11_m, &c11_n, &c11_alpha1, &c11_b_A[1], &c11_incx, &c11_b_A[2],
         &c11_incy, &c11_b_A[3], &c11_lda);
}

static real_T c11_b_subPro1(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[4], real_T c11_q[3])
{
  real_T c11_theta;
  uint32_T c11_debug_family_var_map[13];
  real_T c11_velociy[3];
  real_T c11_w[3];
  real_T c11_r[3];
  real_T c11_u[3];
  real_T c11_v[3];
  real_T c11_up[3];
  real_T c11_vp[3];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i765;
  int32_T c11_i766;
  int32_T c11_i767;
  real_T c11_b_velociy[3];
  int32_T c11_i768;
  real_T c11_b_w[3];
  real_T c11_dv34[3];
  int32_T c11_i769;
  int32_T c11_i770;
  int32_T c11_i771;
  int32_T c11_i772;
  real_T c11_a[3];
  int32_T c11_i773;
  real_T c11_b[3];
  int32_T c11_i774;
  real_T c11_x[3];
  int32_T c11_i775;
  real_T c11_y[3];
  int32_T c11_i776;
  real_T c11_b_x[3];
  int32_T c11_i777;
  real_T c11_b_y[3];
  int32_T c11_i778;
  real_T c11_c_x[3];
  int32_T c11_i779;
  real_T c11_c_y[3];
  int32_T c11_i780;
  real_T c11_d_x[3];
  int32_T c11_i781;
  real_T c11_d_y[3];
  real_T c11_e_y;
  int32_T c11_i782;
  real_T c11_b_a[3];
  real_T c11_b_b;
  int32_T c11_i783;
  real_T c11_f_y[3];
  int32_T c11_i784;
  int32_T c11_i785;
  real_T c11_c_a[3];
  int32_T c11_i786;
  real_T c11_c_b[3];
  int32_T c11_i787;
  real_T c11_e_x[3];
  int32_T c11_i788;
  real_T c11_g_y[3];
  int32_T c11_i789;
  real_T c11_f_x[3];
  int32_T c11_i790;
  real_T c11_h_y[3];
  int32_T c11_i791;
  real_T c11_g_x[3];
  int32_T c11_i792;
  real_T c11_i_y[3];
  int32_T c11_i793;
  real_T c11_h_x[3];
  int32_T c11_i794;
  real_T c11_j_y[3];
  real_T c11_k_y;
  int32_T c11_i795;
  real_T c11_d_a[3];
  real_T c11_d_b;
  int32_T c11_i796;
  real_T c11_l_y[3];
  int32_T c11_i797;
  int32_T c11_i798;
  real_T c11_e_a[3];
  int32_T c11_i799;
  real_T c11_b_up[3];
  int32_T c11_i800;
  real_T c11_b_vp[3];
  real_T c11_e_b[3];
  int32_T c11_i801;
  real_T c11_i_x[3];
  int32_T c11_i802;
  real_T c11_m_y[3];
  int32_T c11_i803;
  real_T c11_j_x[3];
  int32_T c11_i804;
  real_T c11_n_y[3];
  int32_T c11_i805;
  real_T c11_k_x[3];
  int32_T c11_i806;
  real_T c11_o_y[3];
  int32_T c11_i807;
  real_T c11_l_x[3];
  int32_T c11_i808;
  real_T c11_p_y[3];
  real_T c11_q_y;
  int32_T c11_i809;
  real_T c11_f_a[3];
  int32_T c11_i810;
  real_T c11_f_b[3];
  int32_T c11_i811;
  real_T c11_m_x[3];
  int32_T c11_i812;
  real_T c11_r_y[3];
  int32_T c11_i813;
  real_T c11_n_x[3];
  int32_T c11_i814;
  real_T c11_s_y[3];
  int32_T c11_i815;
  real_T c11_o_x[3];
  int32_T c11_i816;
  real_T c11_t_y[3];
  int32_T c11_i817;
  real_T c11_p_x[3];
  int32_T c11_i818;
  real_T c11_u_y[3];
  real_T c11_v_y;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c11_j_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_velociy, c11_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_w, c11_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_r, c11_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_u, c11_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c11_v, c11_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_up, c11_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_vp, c11_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c11_kx, c11_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c11_p, c11_k_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c11_q, c11_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c11_theta, c11_e_sf_marshall, 12U);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5, 4);
  for (c11_i765 = 0; c11_i765 < 3; c11_i765 = c11_i765 + 1) {
    c11_velociy[c11_i765] = c11_kx[c11_i765];
  }

  _SFD_SCRIPT_CALL(5, 5);
  for (c11_i766 = 0; c11_i766 < 3; c11_i766 = c11_i766 + 1) {
    c11_w[c11_i766] = c11_kx[c11_i766 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(5, 6);
  for (c11_i767 = 0; c11_i767 < 3; c11_i767 = c11_i767 + 1) {
    c11_b_velociy[c11_i767] = c11_velociy[c11_i767];
  }

  for (c11_i768 = 0; c11_i768 < 3; c11_i768 = c11_i768 + 1) {
    c11_b_w[c11_i768] = c11_w[c11_i768];
  }

  c11_cross(chartInstance, c11_b_velociy, c11_b_w, c11_dv34);
  for (c11_i769 = 0; c11_i769 < 3; c11_i769 = c11_i769 + 1) {
    c11_r[c11_i769] = -c11_dv34[c11_i769];
  }

  _SFD_SCRIPT_CALL(5, 8);
  for (c11_i770 = 0; c11_i770 < 3; c11_i770 = c11_i770 + 1) {
    c11_u[c11_i770] = c11_p[c11_i770] - c11_r[c11_i770];
  }

  _SFD_SCRIPT_CALL(5, 9);
  for (c11_i771 = 0; c11_i771 < 3; c11_i771 = c11_i771 + 1) {
    c11_v[c11_i771] = c11_q[c11_i771] - c11_r[c11_i771];
  }

  _SFD_SCRIPT_CALL(5, 12);
  for (c11_i772 = 0; c11_i772 < 3; c11_i772 = c11_i772 + 1) {
    c11_a[c11_i772] = c11_w[c11_i772];
  }

  for (c11_i773 = 0; c11_i773 < 3; c11_i773 = c11_i773 + 1) {
    c11_b[c11_i773] = c11_u[c11_i773];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i774 = 0; c11_i774 < 3; c11_i774 = c11_i774 + 1) {
    c11_x[c11_i774] = c11_a[c11_i774];
  }

  for (c11_i775 = 0; c11_i775 < 3; c11_i775 = c11_i775 + 1) {
    c11_y[c11_i775] = c11_b[c11_i775];
  }

  for (c11_i776 = 0; c11_i776 < 3; c11_i776 = c11_i776 + 1) {
    c11_b_x[c11_i776] = c11_x[c11_i776];
  }

  for (c11_i777 = 0; c11_i777 < 3; c11_i777 = c11_i777 + 1) {
    c11_b_y[c11_i777] = c11_y[c11_i777];
  }

  for (c11_i778 = 0; c11_i778 < 3; c11_i778 = c11_i778 + 1) {
    c11_c_x[c11_i778] = c11_b_x[c11_i778];
  }

  for (c11_i779 = 0; c11_i779 < 3; c11_i779 = c11_i779 + 1) {
    c11_c_y[c11_i779] = c11_b_y[c11_i779];
  }

  for (c11_i780 = 0; c11_i780 < 3; c11_i780 = c11_i780 + 1) {
    c11_d_x[c11_i780] = c11_c_x[c11_i780];
  }

  for (c11_i781 = 0; c11_i781 < 3; c11_i781 = c11_i781 + 1) {
    c11_d_y[c11_i781] = c11_c_y[c11_i781];
  }

  c11_e_y = c11_ceval_xdot(chartInstance, 3, c11_d_x, 1, 1, c11_d_y, 1, 1);
  for (c11_i782 = 0; c11_i782 < 3; c11_i782 = c11_i782 + 1) {
    c11_b_a[c11_i782] = c11_w[c11_i782];
  }

  c11_b_b = c11_e_y;
  for (c11_i783 = 0; c11_i783 < 3; c11_i783 = c11_i783 + 1) {
    c11_f_y[c11_i783] = c11_b_a[c11_i783] * c11_b_b;
  }

  for (c11_i784 = 0; c11_i784 < 3; c11_i784 = c11_i784 + 1) {
    c11_up[c11_i784] = c11_u[c11_i784] - c11_f_y[c11_i784];
  }

  _SFD_SCRIPT_CALL(5, 13);
  for (c11_i785 = 0; c11_i785 < 3; c11_i785 = c11_i785 + 1) {
    c11_c_a[c11_i785] = c11_w[c11_i785];
  }

  for (c11_i786 = 0; c11_i786 < 3; c11_i786 = c11_i786 + 1) {
    c11_c_b[c11_i786] = c11_u[c11_i786];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i787 = 0; c11_i787 < 3; c11_i787 = c11_i787 + 1) {
    c11_e_x[c11_i787] = c11_c_a[c11_i787];
  }

  for (c11_i788 = 0; c11_i788 < 3; c11_i788 = c11_i788 + 1) {
    c11_g_y[c11_i788] = c11_c_b[c11_i788];
  }

  for (c11_i789 = 0; c11_i789 < 3; c11_i789 = c11_i789 + 1) {
    c11_f_x[c11_i789] = c11_e_x[c11_i789];
  }

  for (c11_i790 = 0; c11_i790 < 3; c11_i790 = c11_i790 + 1) {
    c11_h_y[c11_i790] = c11_g_y[c11_i790];
  }

  for (c11_i791 = 0; c11_i791 < 3; c11_i791 = c11_i791 + 1) {
    c11_g_x[c11_i791] = c11_f_x[c11_i791];
  }

  for (c11_i792 = 0; c11_i792 < 3; c11_i792 = c11_i792 + 1) {
    c11_i_y[c11_i792] = c11_h_y[c11_i792];
  }

  for (c11_i793 = 0; c11_i793 < 3; c11_i793 = c11_i793 + 1) {
    c11_h_x[c11_i793] = c11_g_x[c11_i793];
  }

  for (c11_i794 = 0; c11_i794 < 3; c11_i794 = c11_i794 + 1) {
    c11_j_y[c11_i794] = c11_i_y[c11_i794];
  }

  c11_k_y = c11_ceval_xdot(chartInstance, 3, c11_h_x, 1, 1, c11_j_y, 1, 1);
  for (c11_i795 = 0; c11_i795 < 3; c11_i795 = c11_i795 + 1) {
    c11_d_a[c11_i795] = c11_w[c11_i795];
  }

  c11_d_b = c11_k_y;
  for (c11_i796 = 0; c11_i796 < 3; c11_i796 = c11_i796 + 1) {
    c11_l_y[c11_i796] = c11_d_a[c11_i796] * c11_d_b;
  }

  for (c11_i797 = 0; c11_i797 < 3; c11_i797 = c11_i797 + 1) {
    c11_vp[c11_i797] = c11_v[c11_i797] - c11_l_y[c11_i797];
  }

  /*      if norm(up) == 0 */
  /*          error('SubPro1: up = 0, Infinite number of solutions!'); */
  /*      end */
  _SFD_SCRIPT_CALL(5, 19);
  for (c11_i798 = 0; c11_i798 < 3; c11_i798 = c11_i798 + 1) {
    c11_e_a[c11_i798] = c11_w[c11_i798];
  }

  for (c11_i799 = 0; c11_i799 < 3; c11_i799 = c11_i799 + 1) {
    c11_b_up[c11_i799] = c11_up[c11_i799];
  }

  for (c11_i800 = 0; c11_i800 < 3; c11_i800 = c11_i800 + 1) {
    c11_b_vp[c11_i800] = c11_vp[c11_i800];
  }

  c11_cross(chartInstance, c11_b_up, c11_b_vp, c11_e_b);
  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i801 = 0; c11_i801 < 3; c11_i801 = c11_i801 + 1) {
    c11_i_x[c11_i801] = c11_e_a[c11_i801];
  }

  for (c11_i802 = 0; c11_i802 < 3; c11_i802 = c11_i802 + 1) {
    c11_m_y[c11_i802] = c11_e_b[c11_i802];
  }

  for (c11_i803 = 0; c11_i803 < 3; c11_i803 = c11_i803 + 1) {
    c11_j_x[c11_i803] = c11_i_x[c11_i803];
  }

  for (c11_i804 = 0; c11_i804 < 3; c11_i804 = c11_i804 + 1) {
    c11_n_y[c11_i804] = c11_m_y[c11_i804];
  }

  for (c11_i805 = 0; c11_i805 < 3; c11_i805 = c11_i805 + 1) {
    c11_k_x[c11_i805] = c11_j_x[c11_i805];
  }

  for (c11_i806 = 0; c11_i806 < 3; c11_i806 = c11_i806 + 1) {
    c11_o_y[c11_i806] = c11_n_y[c11_i806];
  }

  for (c11_i807 = 0; c11_i807 < 3; c11_i807 = c11_i807 + 1) {
    c11_l_x[c11_i807] = c11_k_x[c11_i807];
  }

  for (c11_i808 = 0; c11_i808 < 3; c11_i808 = c11_i808 + 1) {
    c11_p_y[c11_i808] = c11_o_y[c11_i808];
  }

  c11_q_y = c11_ceval_xdot(chartInstance, 3, c11_l_x, 1, 1, c11_p_y, 1, 1);
  for (c11_i809 = 0; c11_i809 < 3; c11_i809 = c11_i809 + 1) {
    c11_f_a[c11_i809] = c11_up[c11_i809];
  }

  for (c11_i810 = 0; c11_i810 < 3; c11_i810 = c11_i810 + 1) {
    c11_f_b[c11_i810] = c11_vp[c11_i810];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i811 = 0; c11_i811 < 3; c11_i811 = c11_i811 + 1) {
    c11_m_x[c11_i811] = c11_f_a[c11_i811];
  }

  for (c11_i812 = 0; c11_i812 < 3; c11_i812 = c11_i812 + 1) {
    c11_r_y[c11_i812] = c11_f_b[c11_i812];
  }

  for (c11_i813 = 0; c11_i813 < 3; c11_i813 = c11_i813 + 1) {
    c11_n_x[c11_i813] = c11_m_x[c11_i813];
  }

  for (c11_i814 = 0; c11_i814 < 3; c11_i814 = c11_i814 + 1) {
    c11_s_y[c11_i814] = c11_r_y[c11_i814];
  }

  for (c11_i815 = 0; c11_i815 < 3; c11_i815 = c11_i815 + 1) {
    c11_o_x[c11_i815] = c11_n_x[c11_i815];
  }

  for (c11_i816 = 0; c11_i816 < 3; c11_i816 = c11_i816 + 1) {
    c11_t_y[c11_i816] = c11_s_y[c11_i816];
  }

  for (c11_i817 = 0; c11_i817 < 3; c11_i817 = c11_i817 + 1) {
    c11_p_x[c11_i817] = c11_o_x[c11_i817];
  }

  for (c11_i818 = 0; c11_i818 < 3; c11_i818 = c11_i818 + 1) {
    c11_u_y[c11_i818] = c11_t_y[c11_i818];
  }

  c11_v_y = c11_ceval_xdot(chartInstance, 3, c11_p_x, 1, 1, c11_u_y, 1, 1);
  c11_theta = c11_atan2(chartInstance, c11_q_y, c11_v_y);
  _SFD_SCRIPT_CALL(5, -19);
  sf_debug_symbol_scope_pop();
  return c11_theta;
}

static real_T c11_c_subPro1(SFc11_KinConInstanceStruct *chartInstance, real_T
  c11_kx[6], real_T c11_p[3], real_T c11_q[4])
{
  real_T c11_theta;
  uint32_T c11_debug_family_var_map[13];
  real_T c11_velociy[3];
  real_T c11_w[3];
  real_T c11_r[3];
  real_T c11_u[3];
  real_T c11_v[3];
  real_T c11_up[3];
  real_T c11_vp[3];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i819;
  int32_T c11_i820;
  int32_T c11_i821;
  real_T c11_b_velociy[3];
  int32_T c11_i822;
  real_T c11_b_w[3];
  real_T c11_dv35[3];
  int32_T c11_i823;
  int32_T c11_i824;
  int32_T c11_i825;
  int32_T c11_i826;
  real_T c11_a[3];
  int32_T c11_i827;
  real_T c11_b[3];
  int32_T c11_i828;
  real_T c11_x[3];
  int32_T c11_i829;
  real_T c11_y[3];
  int32_T c11_i830;
  real_T c11_b_x[3];
  int32_T c11_i831;
  real_T c11_b_y[3];
  int32_T c11_i832;
  real_T c11_c_x[3];
  int32_T c11_i833;
  real_T c11_c_y[3];
  int32_T c11_i834;
  real_T c11_d_x[3];
  int32_T c11_i835;
  real_T c11_d_y[3];
  real_T c11_e_y;
  int32_T c11_i836;
  real_T c11_b_a[3];
  real_T c11_b_b;
  int32_T c11_i837;
  real_T c11_f_y[3];
  int32_T c11_i838;
  int32_T c11_i839;
  real_T c11_c_a[3];
  int32_T c11_i840;
  real_T c11_c_b[3];
  int32_T c11_i841;
  real_T c11_e_x[3];
  int32_T c11_i842;
  real_T c11_g_y[3];
  int32_T c11_i843;
  real_T c11_f_x[3];
  int32_T c11_i844;
  real_T c11_h_y[3];
  int32_T c11_i845;
  real_T c11_g_x[3];
  int32_T c11_i846;
  real_T c11_i_y[3];
  int32_T c11_i847;
  real_T c11_h_x[3];
  int32_T c11_i848;
  real_T c11_j_y[3];
  real_T c11_k_y;
  int32_T c11_i849;
  real_T c11_d_a[3];
  real_T c11_d_b;
  int32_T c11_i850;
  real_T c11_l_y[3];
  int32_T c11_i851;
  int32_T c11_i852;
  real_T c11_e_a[3];
  int32_T c11_i853;
  real_T c11_b_up[3];
  int32_T c11_i854;
  real_T c11_b_vp[3];
  real_T c11_e_b[3];
  int32_T c11_i855;
  real_T c11_i_x[3];
  int32_T c11_i856;
  real_T c11_m_y[3];
  int32_T c11_i857;
  real_T c11_j_x[3];
  int32_T c11_i858;
  real_T c11_n_y[3];
  int32_T c11_i859;
  real_T c11_k_x[3];
  int32_T c11_i860;
  real_T c11_o_y[3];
  int32_T c11_i861;
  real_T c11_l_x[3];
  int32_T c11_i862;
  real_T c11_p_y[3];
  real_T c11_q_y;
  int32_T c11_i863;
  real_T c11_f_a[3];
  int32_T c11_i864;
  real_T c11_f_b[3];
  int32_T c11_i865;
  real_T c11_m_x[3];
  int32_T c11_i866;
  real_T c11_r_y[3];
  int32_T c11_i867;
  real_T c11_n_x[3];
  int32_T c11_i868;
  real_T c11_s_y[3];
  int32_T c11_i869;
  real_T c11_o_x[3];
  int32_T c11_i870;
  real_T c11_t_y[3];
  int32_T c11_i871;
  real_T c11_p_x[3];
  int32_T c11_i872;
  real_T c11_u_y[3];
  real_T c11_v_y;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c11_k_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c11_velociy, c11_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c11_w, c11_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c11_r, c11_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c11_u, c11_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c11_v, c11_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c11_up, c11_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c11_vp, c11_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c11_nargin, c11_e_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c11_nargout, c11_e_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c11_kx, c11_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c11_p, c11_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c11_q, c11_k_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c11_theta, c11_e_sf_marshall, 12U);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5, 4);
  for (c11_i819 = 0; c11_i819 < 3; c11_i819 = c11_i819 + 1) {
    c11_velociy[c11_i819] = c11_kx[c11_i819];
  }

  _SFD_SCRIPT_CALL(5, 5);
  for (c11_i820 = 0; c11_i820 < 3; c11_i820 = c11_i820 + 1) {
    c11_w[c11_i820] = c11_kx[c11_i820 + 3];
  }

  /*  rotation axis */
  _SFD_SCRIPT_CALL(5, 6);
  for (c11_i821 = 0; c11_i821 < 3; c11_i821 = c11_i821 + 1) {
    c11_b_velociy[c11_i821] = c11_velociy[c11_i821];
  }

  for (c11_i822 = 0; c11_i822 < 3; c11_i822 = c11_i822 + 1) {
    c11_b_w[c11_i822] = c11_w[c11_i822];
  }

  c11_cross(chartInstance, c11_b_velociy, c11_b_w, c11_dv35);
  for (c11_i823 = 0; c11_i823 < 3; c11_i823 = c11_i823 + 1) {
    c11_r[c11_i823] = -c11_dv35[c11_i823];
  }

  _SFD_SCRIPT_CALL(5, 8);
  for (c11_i824 = 0; c11_i824 < 3; c11_i824 = c11_i824 + 1) {
    c11_u[c11_i824] = c11_p[c11_i824] - c11_r[c11_i824];
  }

  _SFD_SCRIPT_CALL(5, 9);
  for (c11_i825 = 0; c11_i825 < 3; c11_i825 = c11_i825 + 1) {
    c11_v[c11_i825] = c11_q[c11_i825] - c11_r[c11_i825];
  }

  _SFD_SCRIPT_CALL(5, 12);
  for (c11_i826 = 0; c11_i826 < 3; c11_i826 = c11_i826 + 1) {
    c11_a[c11_i826] = c11_w[c11_i826];
  }

  for (c11_i827 = 0; c11_i827 < 3; c11_i827 = c11_i827 + 1) {
    c11_b[c11_i827] = c11_u[c11_i827];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i828 = 0; c11_i828 < 3; c11_i828 = c11_i828 + 1) {
    c11_x[c11_i828] = c11_a[c11_i828];
  }

  for (c11_i829 = 0; c11_i829 < 3; c11_i829 = c11_i829 + 1) {
    c11_y[c11_i829] = c11_b[c11_i829];
  }

  for (c11_i830 = 0; c11_i830 < 3; c11_i830 = c11_i830 + 1) {
    c11_b_x[c11_i830] = c11_x[c11_i830];
  }

  for (c11_i831 = 0; c11_i831 < 3; c11_i831 = c11_i831 + 1) {
    c11_b_y[c11_i831] = c11_y[c11_i831];
  }

  for (c11_i832 = 0; c11_i832 < 3; c11_i832 = c11_i832 + 1) {
    c11_c_x[c11_i832] = c11_b_x[c11_i832];
  }

  for (c11_i833 = 0; c11_i833 < 3; c11_i833 = c11_i833 + 1) {
    c11_c_y[c11_i833] = c11_b_y[c11_i833];
  }

  for (c11_i834 = 0; c11_i834 < 3; c11_i834 = c11_i834 + 1) {
    c11_d_x[c11_i834] = c11_c_x[c11_i834];
  }

  for (c11_i835 = 0; c11_i835 < 3; c11_i835 = c11_i835 + 1) {
    c11_d_y[c11_i835] = c11_c_y[c11_i835];
  }

  c11_e_y = c11_ceval_xdot(chartInstance, 3, c11_d_x, 1, 1, c11_d_y, 1, 1);
  for (c11_i836 = 0; c11_i836 < 3; c11_i836 = c11_i836 + 1) {
    c11_b_a[c11_i836] = c11_w[c11_i836];
  }

  c11_b_b = c11_e_y;
  for (c11_i837 = 0; c11_i837 < 3; c11_i837 = c11_i837 + 1) {
    c11_f_y[c11_i837] = c11_b_a[c11_i837] * c11_b_b;
  }

  for (c11_i838 = 0; c11_i838 < 3; c11_i838 = c11_i838 + 1) {
    c11_up[c11_i838] = c11_u[c11_i838] - c11_f_y[c11_i838];
  }

  _SFD_SCRIPT_CALL(5, 13);
  for (c11_i839 = 0; c11_i839 < 3; c11_i839 = c11_i839 + 1) {
    c11_c_a[c11_i839] = c11_w[c11_i839];
  }

  for (c11_i840 = 0; c11_i840 < 3; c11_i840 = c11_i840 + 1) {
    c11_c_b[c11_i840] = c11_u[c11_i840];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i841 = 0; c11_i841 < 3; c11_i841 = c11_i841 + 1) {
    c11_e_x[c11_i841] = c11_c_a[c11_i841];
  }

  for (c11_i842 = 0; c11_i842 < 3; c11_i842 = c11_i842 + 1) {
    c11_g_y[c11_i842] = c11_c_b[c11_i842];
  }

  for (c11_i843 = 0; c11_i843 < 3; c11_i843 = c11_i843 + 1) {
    c11_f_x[c11_i843] = c11_e_x[c11_i843];
  }

  for (c11_i844 = 0; c11_i844 < 3; c11_i844 = c11_i844 + 1) {
    c11_h_y[c11_i844] = c11_g_y[c11_i844];
  }

  for (c11_i845 = 0; c11_i845 < 3; c11_i845 = c11_i845 + 1) {
    c11_g_x[c11_i845] = c11_f_x[c11_i845];
  }

  for (c11_i846 = 0; c11_i846 < 3; c11_i846 = c11_i846 + 1) {
    c11_i_y[c11_i846] = c11_h_y[c11_i846];
  }

  for (c11_i847 = 0; c11_i847 < 3; c11_i847 = c11_i847 + 1) {
    c11_h_x[c11_i847] = c11_g_x[c11_i847];
  }

  for (c11_i848 = 0; c11_i848 < 3; c11_i848 = c11_i848 + 1) {
    c11_j_y[c11_i848] = c11_i_y[c11_i848];
  }

  c11_k_y = c11_ceval_xdot(chartInstance, 3, c11_h_x, 1, 1, c11_j_y, 1, 1);
  for (c11_i849 = 0; c11_i849 < 3; c11_i849 = c11_i849 + 1) {
    c11_d_a[c11_i849] = c11_w[c11_i849];
  }

  c11_d_b = c11_k_y;
  for (c11_i850 = 0; c11_i850 < 3; c11_i850 = c11_i850 + 1) {
    c11_l_y[c11_i850] = c11_d_a[c11_i850] * c11_d_b;
  }

  for (c11_i851 = 0; c11_i851 < 3; c11_i851 = c11_i851 + 1) {
    c11_vp[c11_i851] = c11_v[c11_i851] - c11_l_y[c11_i851];
  }

  /*      if norm(up) == 0 */
  /*          error('SubPro1: up = 0, Infinite number of solutions!'); */
  /*      end */
  _SFD_SCRIPT_CALL(5, 19);
  for (c11_i852 = 0; c11_i852 < 3; c11_i852 = c11_i852 + 1) {
    c11_e_a[c11_i852] = c11_w[c11_i852];
  }

  for (c11_i853 = 0; c11_i853 < 3; c11_i853 = c11_i853 + 1) {
    c11_b_up[c11_i853] = c11_up[c11_i853];
  }

  for (c11_i854 = 0; c11_i854 < 3; c11_i854 = c11_i854 + 1) {
    c11_b_vp[c11_i854] = c11_vp[c11_i854];
  }

  c11_cross(chartInstance, c11_b_up, c11_b_vp, c11_e_b);
  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i855 = 0; c11_i855 < 3; c11_i855 = c11_i855 + 1) {
    c11_i_x[c11_i855] = c11_e_a[c11_i855];
  }

  for (c11_i856 = 0; c11_i856 < 3; c11_i856 = c11_i856 + 1) {
    c11_m_y[c11_i856] = c11_e_b[c11_i856];
  }

  for (c11_i857 = 0; c11_i857 < 3; c11_i857 = c11_i857 + 1) {
    c11_j_x[c11_i857] = c11_i_x[c11_i857];
  }

  for (c11_i858 = 0; c11_i858 < 3; c11_i858 = c11_i858 + 1) {
    c11_n_y[c11_i858] = c11_m_y[c11_i858];
  }

  for (c11_i859 = 0; c11_i859 < 3; c11_i859 = c11_i859 + 1) {
    c11_k_x[c11_i859] = c11_j_x[c11_i859];
  }

  for (c11_i860 = 0; c11_i860 < 3; c11_i860 = c11_i860 + 1) {
    c11_o_y[c11_i860] = c11_n_y[c11_i860];
  }

  for (c11_i861 = 0; c11_i861 < 3; c11_i861 = c11_i861 + 1) {
    c11_l_x[c11_i861] = c11_k_x[c11_i861];
  }

  for (c11_i862 = 0; c11_i862 < 3; c11_i862 = c11_i862 + 1) {
    c11_p_y[c11_i862] = c11_o_y[c11_i862];
  }

  c11_q_y = c11_ceval_xdot(chartInstance, 3, c11_l_x, 1, 1, c11_p_y, 1, 1);
  for (c11_i863 = 0; c11_i863 < 3; c11_i863 = c11_i863 + 1) {
    c11_f_a[c11_i863] = c11_up[c11_i863];
  }

  for (c11_i864 = 0; c11_i864 < 3; c11_i864 = c11_i864 + 1) {
    c11_f_b[c11_i864] = c11_vp[c11_i864];
  }

  c11_g_eml_scalar_eg(chartInstance);
  for (c11_i865 = 0; c11_i865 < 3; c11_i865 = c11_i865 + 1) {
    c11_m_x[c11_i865] = c11_f_a[c11_i865];
  }

  for (c11_i866 = 0; c11_i866 < 3; c11_i866 = c11_i866 + 1) {
    c11_r_y[c11_i866] = c11_f_b[c11_i866];
  }

  for (c11_i867 = 0; c11_i867 < 3; c11_i867 = c11_i867 + 1) {
    c11_n_x[c11_i867] = c11_m_x[c11_i867];
  }

  for (c11_i868 = 0; c11_i868 < 3; c11_i868 = c11_i868 + 1) {
    c11_s_y[c11_i868] = c11_r_y[c11_i868];
  }

  for (c11_i869 = 0; c11_i869 < 3; c11_i869 = c11_i869 + 1) {
    c11_o_x[c11_i869] = c11_n_x[c11_i869];
  }

  for (c11_i870 = 0; c11_i870 < 3; c11_i870 = c11_i870 + 1) {
    c11_t_y[c11_i870] = c11_s_y[c11_i870];
  }

  for (c11_i871 = 0; c11_i871 < 3; c11_i871 = c11_i871 + 1) {
    c11_p_x[c11_i871] = c11_o_x[c11_i871];
  }

  for (c11_i872 = 0; c11_i872 < 3; c11_i872 = c11_i872 + 1) {
    c11_u_y[c11_i872] = c11_t_y[c11_i872];
  }

  c11_v_y = c11_ceval_xdot(chartInstance, 3, c11_p_x, 1, 1, c11_u_y, 1, 1);
  c11_theta = c11_atan2(chartInstance, c11_q_y, c11_v_y);
  _SFD_SCRIPT_CALL(5, -19);
  sf_debug_symbol_scope_pop();
  return c11_theta;
}

static const mxArray *c11_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i873;
  real_T c11_b_u[6];
  int32_T c11_i874;
  real_T c11_c_u[6];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i873 = 0; c11_i873 < 6; c11_i873 = c11_i873 + 1) {
    c11_b_u[c11_i873] = (*((real_T (*)[6])c11_u))[c11_i873];
  }

  for (c11_i874 = 0; c11_i874 < 6; c11_i874 = c11_i874 + 1) {
    c11_c_u[c11_i874] = c11_b_u[c11_i874];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_b_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i875;
  real_T c11_b_u[9];
  int32_T c11_i876;
  real_T c11_c_u[9];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i875 = 0; c11_i875 < 9; c11_i875 = c11_i875 + 1) {
    c11_b_u[c11_i875] = (*((real_T (*)[9])c11_u))[c11_i875];
  }

  for (c11_i876 = 0; c11_i876 < 9; c11_i876 = c11_i876 + 1) {
    c11_c_u[c11_i876] = c11_b_u[c11_i876];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_c_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i877;
  int32_T c11_i878;
  int32_T c11_i879;
  real_T c11_b_u[9];
  int32_T c11_i880;
  int32_T c11_i881;
  int32_T c11_i882;
  real_T c11_c_u[9];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_i877 = 0;
  for (c11_i878 = 0; c11_i878 < 3; c11_i878 = c11_i878 + 1) {
    for (c11_i879 = 0; c11_i879 < 3; c11_i879 = c11_i879 + 1) {
      c11_b_u[c11_i879 + c11_i877] = (*((real_T (*)[9])c11_u))[c11_i879 +
        c11_i877];
    }

    c11_i877 = c11_i877 + 3;
  }

  c11_i880 = 0;
  for (c11_i881 = 0; c11_i881 < 3; c11_i881 = c11_i881 + 1) {
    for (c11_i882 = 0; c11_i882 < 3; c11_i882 = c11_i882 + 1) {
      c11_c_u[c11_i882 + c11_i880] = c11_b_u[c11_i882 + c11_i880];
    }

    c11_i880 = c11_i880 + 3;
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 3, 3));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_d_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i883;
  real_T c11_b_u[3];
  int32_T c11_i884;
  real_T c11_c_u[3];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i883 = 0; c11_i883 < 3; c11_i883 = c11_i883 + 1) {
    c11_b_u[c11_i883] = (*((real_T (*)[3])c11_u))[c11_i883];
  }

  for (c11_i884 = 0; c11_i884 < 3; c11_i884 = c11_i884 + 1) {
    c11_c_u[c11_i884] = c11_b_u[c11_i884];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 1, 3));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_e_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_b_u = *((real_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_f_sf_marshall(void *chartInstanceVoid, real_T
  c11_u_data[4], int32_T c11_u_sizes[2])
{
  const mxArray *c11_y = NULL;
  int32_T c11_b_u_sizes[2];
  int32_T c11_loop_ub;
  int32_T c11_i885;
  real_T c11_b_u_data[4];
  int32_T c11_c_u_sizes[2];
  int32_T c11_b_loop_ub;
  int32_T c11_i886;
  real_T c11_c_u_data[4];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_b_u_sizes[0] = 1;
  c11_b_u_sizes[1] = c11_u_sizes[1];
  c11_loop_ub = c11_u_sizes[1] - 1;
  for (c11_i885 = 0; c11_i885 <= c11_loop_ub; c11_i885 = c11_i885 + 1) {
    c11_b_u_data[c11_b_u_sizes[0] * c11_i885] = c11_u_data[c11_u_sizes[0] *
      c11_i885];
  }

  c11_c_u_sizes[0] = 1;
  c11_c_u_sizes[1] = c11_b_u_sizes[1];
  c11_b_loop_ub = c11_b_u_sizes[1] - 1;
  for (c11_i886 = 0; c11_i886 <= c11_b_loop_ub; c11_i886 = c11_i886 + 1) {
    c11_c_u_data[c11_c_u_sizes[0] * c11_i886] = c11_b_u_data[c11_b_u_sizes[0] *
      c11_i886];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u_data, 0, 0U, 1U, 0U, 2,
    c11_c_u_sizes[0], c11_c_u_sizes[1]));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_g_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i887;
  int32_T c11_i888;
  int32_T c11_i889;
  real_T c11_b_u[24];
  int32_T c11_i890;
  int32_T c11_i891;
  int32_T c11_i892;
  real_T c11_c_u[24];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_i887 = 0;
  for (c11_i888 = 0; c11_i888 < 4; c11_i888 = c11_i888 + 1) {
    for (c11_i889 = 0; c11_i889 < 6; c11_i889 = c11_i889 + 1) {
      c11_b_u[c11_i889 + c11_i887] = (*((real_T (*)[24])c11_u))[c11_i889 +
        c11_i887];
    }

    c11_i887 = c11_i887 + 6;
  }

  c11_i890 = 0;
  for (c11_i891 = 0; c11_i891 < 4; c11_i891 = c11_i891 + 1) {
    for (c11_i892 = 0; c11_i892 < 6; c11_i892 = c11_i892 + 1) {
      c11_c_u[c11_i892 + c11_i890] = c11_b_u[c11_i892 + c11_i890];
    }

    c11_i890 = c11_i890 + 6;
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 6, 4));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_h_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i893;
  int32_T c11_i894;
  int32_T c11_i895;
  real_T c11_b_u[16];
  int32_T c11_i896;
  int32_T c11_i897;
  int32_T c11_i898;
  real_T c11_c_u[16];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_i893 = 0;
  for (c11_i894 = 0; c11_i894 < 4; c11_i894 = c11_i894 + 1) {
    for (c11_i895 = 0; c11_i895 < 4; c11_i895 = c11_i895 + 1) {
      c11_b_u[c11_i895 + c11_i893] = (*((real_T (*)[16])c11_u))[c11_i895 +
        c11_i893];
    }

    c11_i893 = c11_i893 + 4;
  }

  c11_i896 = 0;
  for (c11_i897 = 0; c11_i897 < 4; c11_i897 = c11_i897 + 1) {
    for (c11_i898 = 0; c11_i898 < 4; c11_i898 = c11_i898 + 1) {
      c11_c_u[c11_i898 + c11_i896] = c11_b_u[c11_i898 + c11_i896];
    }

    c11_i896 = c11_i896 + 4;
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 4, 4));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_i_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  boolean_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_b_u = *((boolean_T *)c11_u);
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_j_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i899;
  real_T c11_b_u[2];
  int32_T c11_i900;
  real_T c11_c_u[2];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i899 = 0; c11_i899 < 2; c11_i899 = c11_i899 + 1) {
    c11_b_u[c11_i899] = (*((real_T (*)[2])c11_u))[c11_i899];
  }

  for (c11_i900 = 0; c11_i900 < 2; c11_i900 = c11_i900 + 1) {
    c11_c_u[c11_i900] = c11_b_u[c11_i900];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_k_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i901;
  real_T c11_b_u[4];
  int32_T c11_i902;
  real_T c11_c_u[4];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i901 = 0; c11_i901 < 4; c11_i901 = c11_i901 + 1) {
    c11_b_u[c11_i901] = (*((real_T (*)[4])c11_u))[c11_i901];
  }

  for (c11_i902 = 0; c11_i902 < 4; c11_i902 = c11_i902 + 1) {
    c11_c_u[c11_i902] = c11_b_u[c11_i902];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 1, 4));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_l_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i903;
  boolean_T c11_b_u[2];
  int32_T c11_i904;
  boolean_T c11_c_u[2];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  for (c11_i903 = 0; c11_i903 < 2; c11_i903 = c11_i903 + 1) {
    c11_b_u[c11_i903] = (*((boolean_T (*)[2])c11_u))[c11_i903];
  }

  for (c11_i904 = 0; c11_i904 < 2; c11_i904 = c11_i904 + 1) {
    c11_c_u[c11_i904] = c11_b_u[c11_i904];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 11, 0U, 1U, 0U, 1, 2));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

static const mxArray *c11_m_sf_marshall(void *chartInstanceVoid, void *c11_u)
{
  const mxArray *c11_y = NULL;
  int32_T c11_i905;
  int32_T c11_i906;
  int32_T c11_i907;
  real_T c11_b_u[4];
  int32_T c11_i908;
  int32_T c11_i909;
  int32_T c11_i910;
  real_T c11_c_u[4];
  const mxArray *c11_b_y = NULL;
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)chartInstanceVoid;
  c11_y = NULL;
  c11_i905 = 0;
  for (c11_i906 = 0; c11_i906 < 2; c11_i906 = c11_i906 + 1) {
    for (c11_i907 = 0; c11_i907 < 2; c11_i907 = c11_i907 + 1) {
      c11_b_u[c11_i907 + c11_i905] = (*((real_T (*)[4])c11_u))[c11_i907 +
        c11_i905];
    }

    c11_i905 = c11_i905 + 2;
  }

  c11_i908 = 0;
  for (c11_i909 = 0; c11_i909 < 2; c11_i909 = c11_i909 + 1) {
    for (c11_i910 = 0; c11_i910 < 2; c11_i910 = c11_i910 + 1) {
      c11_c_u[c11_i910 + c11_i908] = c11_b_u[c11_i910 + c11_i908];
    }

    c11_i908 = c11_i908 + 2;
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_c_u, 0, 0U, 1U, 0U, 2, 2, 2));
  sf_mex_assign(&c11_y, c11_b_y);
  return c11_y;
}

const mxArray *sf_c11_KinCon_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_ResolvedFunctionInfo c11_info[123];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i911;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  c11_b_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 123));
  for (c11_i911 = 0; c11_i911 < 123; c11_i911 = c11_i911 + 1) {
    c11_r0 = &c11_info[c11_i911];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context"
                    , "nameCaptureInfo", c11_i911);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name",
                    "nameCaptureInfo", c11_i911);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i911);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)),
                    "resolved", "nameCaptureInfo", c11_i911);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c11_i911);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c11_i911);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c11_i911);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[123])
{
  c11_info[0].context = "";
  c11_info[0].name = "inv_kin";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[0].fileLength = 2977U;
  c11_info[0].fileTime1 = 1367251992U;
  c11_info[0].fileTime2 = 0U;
  c11_info[1].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[1].name = "zeros";
  c11_info[1].dominantType = "double";
  c11_info[1].resolved = "[B]zeros";
  c11_info[1].fileLength = 0U;
  c11_info[1].fileTime1 = 0U;
  c11_info[1].fileTime2 = 0U;
  c11_info[2].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[2].name = "uminus";
  c11_info[2].dominantType = "double";
  c11_info[2].resolved = "[B]uminus";
  c11_info[2].fileLength = 0U;
  c11_info[2].fileTime1 = 0U;
  c11_info[2].fileTime2 = 0U;
  c11_info[3].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[3].name = "cross";
  c11_info[3].dominantType = "double";
  c11_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[3].fileLength = 3157U;
  c11_info[3].fileTime1 = 1240240462U;
  c11_info[3].fileTime2 = 0U;
  c11_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[4].name = "nargin";
  c11_info[4].dominantType = "";
  c11_info[4].resolved = "[B]nargin";
  c11_info[4].fileLength = 0U;
  c11_info[4].fileTime1 = 0U;
  c11_info[4].fileTime2 = 0U;
  c11_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[5].name = "gt";
  c11_info[5].dominantType = "double";
  c11_info[5].resolved = "[B]gt";
  c11_info[5].fileLength = 0U;
  c11_info[5].fileTime1 = 0U;
  c11_info[5].fileTime2 = 0U;
  c11_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[6].name = "eq";
  c11_info[6].dominantType = "double";
  c11_info[6].resolved = "[B]eq";
  c11_info[6].fileLength = 0U;
  c11_info[6].fileTime1 = 0U;
  c11_info[6].fileTime2 = 0U;
  c11_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[7].name = "isa";
  c11_info[7].dominantType = "double";
  c11_info[7].resolved = "[B]isa";
  c11_info[7].fileLength = 0U;
  c11_info[7].fileTime1 = 0U;
  c11_info[7].fileTime2 = 0U;
  c11_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[8].name = "isvector";
  c11_info[8].dominantType = "double";
  c11_info[8].resolved = "[B]isvector";
  c11_info[8].fileLength = 0U;
  c11_info[8].fileTime1 = 0U;
  c11_info[8].fileTime2 = 0U;
  c11_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[9].name = "mtimes";
  c11_info[9].dominantType = "double";
  c11_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[9].fileLength = 3425U;
  c11_info[9].fileTime1 = 1251010272U;
  c11_info[9].fileTime2 = 0U;
  c11_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[10].name = "isinteger";
  c11_info[10].dominantType = "double";
  c11_info[10].resolved = "[B]isinteger";
  c11_info[10].fileLength = 0U;
  c11_info[10].fileTime1 = 0U;
  c11_info[10].fileTime2 = 0U;
  c11_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[11].name = "isscalar";
  c11_info[11].dominantType = "double";
  c11_info[11].resolved = "[B]isscalar";
  c11_info[11].fileLength = 0U;
  c11_info[11].fileTime1 = 0U;
  c11_info[11].fileTime2 = 0U;
  c11_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[12].name = "strcmp";
  c11_info[12].dominantType = "char";
  c11_info[12].resolved = "[B]strcmp";
  c11_info[12].fileLength = 0U;
  c11_info[12].fileTime1 = 0U;
  c11_info[12].fileTime2 = 0U;
  c11_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[13].name = "size";
  c11_info[13].dominantType = "double";
  c11_info[13].resolved = "[B]size";
  c11_info[13].fileLength = 0U;
  c11_info[13].fileTime1 = 0U;
  c11_info[13].fileTime2 = 0U;
  c11_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[14].name = "class";
  c11_info[14].dominantType = "double";
  c11_info[14].resolved = "[B]class";
  c11_info[14].fileLength = 0U;
  c11_info[14].fileTime1 = 0U;
  c11_info[14].fileTime2 = 0U;
  c11_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[15].name = "not";
  c11_info[15].dominantType = "logical";
  c11_info[15].resolved = "[B]not";
  c11_info[15].fileLength = 0U;
  c11_info[15].fileTime1 = 0U;
  c11_info[15].fileTime2 = 0U;
  c11_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/cross.m";
  c11_info[16].name = "minus";
  c11_info[16].dominantType = "double";
  c11_info[16].resolved = "[B]minus";
  c11_info[16].fileLength = 0U;
  c11_info[16].fileTime1 = 0U;
  c11_info[16].fileTime2 = 0U;
  c11_info[17].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[17].name = "plus";
  c11_info[17].dominantType = "double";
  c11_info[17].resolved = "[B]plus";
  c11_info[17].fileLength = 0U;
  c11_info[17].fileTime1 = 0U;
  c11_info[17].fileTime2 = 0U;
  c11_info[18].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[18].name = "all";
  c11_info[18].dominantType = "logical";
  c11_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c11_info[18].fileLength = 427U;
  c11_info[18].fileTime1 = 1221245538U;
  c11_info[18].fileTime2 = 0U;
  c11_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c11_info[19].name = "ischar";
  c11_info[19].dominantType = "logical";
  c11_info[19].resolved = "[B]ischar";
  c11_info[19].fileLength = 0U;
  c11_info[19].fileTime1 = 0U;
  c11_info[19].fileTime2 = 0U;
  c11_info[20].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c11_info[20].name = "islogical";
  c11_info[20].dominantType = "logical";
  c11_info[20].resolved = "[B]islogical";
  c11_info[20].fileLength = 0U;
  c11_info[20].fileTime1 = 0U;
  c11_info[20].fileTime2 = 0U;
  c11_info[21].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c11_info[21].name = "lt";
  c11_info[21].dominantType = "double";
  c11_info[21].resolved = "[B]lt";
  c11_info[21].fileLength = 0U;
  c11_info[21].fileTime1 = 0U;
  c11_info[21].fileTime2 = 0U;
  c11_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c11_info[22].name = "eml_all_or_any";
  c11_info[22].dominantType = "char";
  c11_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c11_info[22].fileLength = 3914U;
  c11_info[22].fileTime1 = 1271383994U;
  c11_info[22].fileTime2 = 0U;
  c11_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c11_info[23].name = "isequal";
  c11_info[23].dominantType = "double";
  c11_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c11_info[23].fileLength = 180U;
  c11_info[23].fileTime1 = 1226552070U;
  c11_info[23].fileTime2 = 0U;
  c11_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c11_info[24].name = "false";
  c11_info[24].dominantType = "";
  c11_info[24].resolved = "[B]false";
  c11_info[24].fileLength = 0U;
  c11_info[24].fileTime1 = 0U;
  c11_info[24].fileTime2 = 0U;
  c11_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c11_info[25].name = "eml_isequal_core";
  c11_info[25].dominantType = "double";
  c11_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c11_info[25].fileLength = 4192U;
  c11_info[25].fileTime1 = 1258039010U;
  c11_info[25].fileTime2 = 0U;
  c11_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c11_info[26].name = "ge";
  c11_info[26].dominantType = "double";
  c11_info[26].resolved = "[B]ge";
  c11_info[26].fileLength = 0U;
  c11_info[26].fileTime1 = 0U;
  c11_info[26].fileTime2 = 0U;
  c11_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c11_info[27].name = "isnumeric";
  c11_info[27].dominantType = "logical";
  c11_info[27].resolved = "[B]isnumeric";
  c11_info[27].fileLength = 0U;
  c11_info[27].fileTime1 = 0U;
  c11_info[27].fileTime2 = 0U;
  c11_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c11_info[28].name = "ndims";
  c11_info[28].dominantType = "logical";
  c11_info[28].resolved = "[B]ndims";
  c11_info[28].fileLength = 0U;
  c11_info[28].fileTime1 = 0U;
  c11_info[28].fileTime2 = 0U;
  c11_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c11_info[29].name = "ne";
  c11_info[29].dominantType = "double";
  c11_info[29].resolved = "[B]ne";
  c11_info[29].fileLength = 0U;
  c11_info[29].fileTime1 = 0U;
  c11_info[29].fileTime2 = 0U;
  c11_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!same_size";
  c11_info[30].name = "true";
  c11_info[30].dominantType = "";
  c11_info[30].resolved = "[B]true";
  c11_info[30].fileLength = 0U;
  c11_info[30].fileTime1 = 0U;
  c11_info[30].fileTime2 = 0U;
  c11_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c11_info[31].name = "eml_const_nonsingleton_dim";
  c11_info[31].dominantType = "logical";
  c11_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c11_info[31].fileLength = 1473U;
  c11_info[31].fileTime1 = 1240240402U;
  c11_info[31].fileTime2 = 0U;
  c11_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c11_info[32].name = "isempty";
  c11_info[32].dominantType = "logical";
  c11_info[32].resolved = "[B]isempty";
  c11_info[32].fileLength = 0U;
  c11_info[32].fileTime1 = 0U;
  c11_info[32].fileTime2 = 0U;
  c11_info[33].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[33].name = "mrdivide";
  c11_info[33].dominantType = "double";
  c11_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c11_info[33].fileLength = 432U;
  c11_info[33].fileTime1 = 1277726622U;
  c11_info[33].fileTime2 = 0U;
  c11_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c11_info[34].name = "ctranspose";
  c11_info[34].dominantType = "double";
  c11_info[34].resolved = "[B]ctranspose";
  c11_info[34].fileLength = 0U;
  c11_info[34].fileTime1 = 0U;
  c11_info[34].fileTime2 = 0U;
  c11_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c11_info[35].name = "mldivide";
  c11_info[35].dominantType = "double";
  c11_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c11_info[35].fileLength = 494U;
  c11_info[35].fileTime1 = 1277726622U;
  c11_info[35].fileTime2 = 0U;
  c11_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c11_info[36].name = "eml_lusolve";
  c11_info[36].dominantType = "double";
  c11_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c11_info[36].fileLength = 5239U;
  c11_info[36].fileTime1 = 1264408552U;
  c11_info[36].fileTime2 = 0U;
  c11_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c11_info[37].name = "eml_index_class";
  c11_info[37].dominantType = "";
  c11_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[37].fileLength = 909U;
  c11_info[37].fileTime1 = 1192445182U;
  c11_info[37].fileTime2 = 0U;
  c11_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c11_info[38].name = "cast";
  c11_info[38].dominantType = "double";
  c11_info[38].resolved = "[B]cast";
  c11_info[38].fileLength = 0U;
  c11_info[38].fileTime1 = 0U;
  c11_info[38].fileTime2 = 0U;
  c11_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c11_info[39].name = "nargout";
  c11_info[39].dominantType = "";
  c11_info[39].resolved = "[B]nargout";
  c11_info[39].fileLength = 0U;
  c11_info[39].fileTime1 = 0U;
  c11_info[39].fileTime2 = 0U;
  c11_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c11_info[40].name = "ones";
  c11_info[40].dominantType = "char";
  c11_info[40].resolved = "[B]ones";
  c11_info[40].fileLength = 0U;
  c11_info[40].fileTime1 = 0U;
  c11_info[40].fileTime2 = 0U;
  c11_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c11_info[41].name = "eml_xgetrf";
  c11_info[41].dominantType = "int32";
  c11_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c11_info[41].fileLength = 204U;
  c11_info[41].fileTime1 = 1271383994U;
  c11_info[41].fileTime2 = 0U;
  c11_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c11_info[42].name = "eml_lapack_xgetrf";
  c11_info[42].dominantType = "int32";
  c11_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c11_info[42].fileLength = 211U;
  c11_info[42].fileTime1 = 1271383994U;
  c11_info[42].fileTime2 = 0U;
  c11_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c11_info[43].name = "eml_matlab_zgetrf";
  c11_info[43].dominantType = "int32";
  c11_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[43].fileLength = 2193U;
  c11_info[43].fileTime1 = 1271383998U;
  c11_info[43].fileTime2 = 0U;
  c11_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[44].name = "realmin";
  c11_info[44].dominantType = "char";
  c11_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c11_info[44].fileLength = 749U;
  c11_info[44].fileTime1 = 1226552078U;
  c11_info[44].fileTime2 = 0U;
  c11_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c11_info[45].name = "mpower";
  c11_info[45].dominantType = "double";
  c11_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c11_info[45].fileLength = 3710U;
  c11_info[45].fileTime1 = 1238412688U;
  c11_info[45].fileTime2 = 0U;
  c11_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c11_info[46].name = "power";
  c11_info[46].dominantType = "double";
  c11_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[46].fileLength = 5380U;
  c11_info[46].fileTime1 = 1228068698U;
  c11_info[46].fileTime2 = 0U;
  c11_info[47].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[47].name = "eml_scalar_eg";
  c11_info[47].dominantType = "double";
  c11_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[47].fileLength = 3068U;
  c11_info[47].fileTime1 = 1240240410U;
  c11_info[47].fileTime2 = 0U;
  c11_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[48].name = "isstruct";
  c11_info[48].dominantType = "double";
  c11_info[48].resolved = "[B]isstruct";
  c11_info[48].fileLength = 0U;
  c11_info[48].fileTime1 = 0U;
  c11_info[48].fileTime2 = 0U;
  c11_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!allreal";
  c11_info[49].name = "isreal";
  c11_info[49].dominantType = "double";
  c11_info[49].resolved = "[B]isreal";
  c11_info[49].fileLength = 0U;
  c11_info[49].fileTime1 = 0U;
  c11_info[49].fileTime2 = 0U;
  c11_info[50].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[50].name = "eml_scalexp_alloc";
  c11_info[50].dominantType = "double";
  c11_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c11_info[50].fileLength = 932U;
  c11_info[50].fileTime1 = 1261926670U;
  c11_info[50].fileTime2 = 0U;
  c11_info[51].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[51].name = "eml_scalar_floor";
  c11_info[51].dominantType = "double";
  c11_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c11_info[51].fileLength = 260U;
  c11_info[51].fileTime1 = 1209309190U;
  c11_info[51].fileTime2 = 0U;
  c11_info[52].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c11_info[52].name = "eml_error";
  c11_info[52].dominantType = "char";
  c11_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c11_info[52].fileLength = 315U;
  c11_info[52].fileTime1 = 1213905144U;
  c11_info[52].fileTime2 = 0U;
  c11_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[53].name = "eps";
  c11_info[53].dominantType = "char";
  c11_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c11_info[53].fileLength = 1331U;
  c11_info[53].fileTime1 = 1246588112U;
  c11_info[53].fileTime2 = 0U;
  c11_info[54].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c11_info[54].name = "eml_is_float_class";
  c11_info[54].dominantType = "char";
  c11_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c11_info[54].fileLength = 226U;
  c11_info[54].fileTime1 = 1197825240U;
  c11_info[54].fileTime2 = 0U;
  c11_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[55].name = "min";
  c11_info[55].dominantType = "int32";
  c11_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c11_info[55].fileLength = 362U;
  c11_info[55].fileTime1 = 1245080764U;
  c11_info[55].fileTime2 = 0U;
  c11_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c11_info[56].name = "le";
  c11_info[56].dominantType = "double";
  c11_info[56].resolved = "[B]le";
  c11_info[56].fileLength = 0U;
  c11_info[56].fileTime1 = 0U;
  c11_info[56].fileTime2 = 0U;
  c11_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c11_info[57].name = "eml_min_or_max";
  c11_info[57].dominantType = "int32";
  c11_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c11_info[57].fileLength = 9967U;
  c11_info[57].fileTime1 = 1261926670U;
  c11_info[57].fileTime2 = 0U;
  c11_info[58].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[58].name = "colon";
  c11_info[58].dominantType = "int32";
  c11_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c11_info[58].fileLength = 8633U;
  c11_info[58].fileTime1 = 1273822662U;
  c11_info[58].fileTime2 = 0U;
  c11_info[59].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c11_info[59].name = "floor";
  c11_info[59].dominantType = "double";
  c11_info[59].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c11_info[59].fileLength = 332U;
  c11_info[59].fileTime1 = 1203422822U;
  c11_info[59].fileTime2 = 0U;
  c11_info[60].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c11_info[60].name = "intmin";
  c11_info[60].dominantType = "char";
  c11_info[60].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c11_info[60].fileLength = 1505U;
  c11_info[60].fileTime1 = 1192445128U;
  c11_info[60].fileTime2 = 0U;
  c11_info[61].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c11_info[61].name = "int32";
  c11_info[61].dominantType = "double";
  c11_info[61].resolved = "[B]int32";
  c11_info[61].fileLength = 0U;
  c11_info[61].fileTime1 = 0U;
  c11_info[61].fileTime2 = 0U;
  c11_info[62].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c11_info[62].name = "intmax";
  c11_info[62].dominantType = "char";
  c11_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c11_info[62].fileLength = 1535U;
  c11_info[62].fileTime1 = 1192445128U;
  c11_info[62].fileTime2 = 0U;
  c11_info[63].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c11_info[63].name = "double";
  c11_info[63].dominantType = "int32";
  c11_info[63].resolved = "[B]double";
  c11_info[63].fileLength = 0U;
  c11_info[63].fileTime1 = 0U;
  c11_info[63].fileTime2 = 0U;
}

static void c11_b_info_helper(c11_ResolvedFunctionInfo c11_info[123])
{
  c11_info[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c11_info[64].name = "rdivide";
  c11_info[64].dominantType = "double";
  c11_info[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[64].fileLength = 403U;
  c11_info[64].fileTime1 = 1245080820U;
  c11_info[64].fileTime2 = 0U;
  c11_info[65].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c11_info[65].name = "eml_div";
  c11_info[65].dominantType = "double";
  c11_info[65].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[65].fileLength = 4918U;
  c11_info[65].fileTime1 = 1267038210U;
  c11_info[65].fileTime2 = 0U;
  c11_info[66].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon";
  c11_info[66].name = "transpose";
  c11_info[66].dominantType = "int32";
  c11_info[66].resolved = "[B]transpose";
  c11_info[66].fileLength = 0U;
  c11_info[66].fileTime1 = 0U;
  c11_info[66].fileTime2 = 0U;
  c11_info[67].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[67].name = "eml_index_plus";
  c11_info[67].dominantType = "int32";
  c11_info[67].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c11_info[67].fileLength = 272U;
  c11_info[67].fileTime1 = 1192445184U;
  c11_info[67].fileTime2 = 0U;
  c11_info[68].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[68].name = "eml_index_minus";
  c11_info[68].dominantType = "int32";
  c11_info[68].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c11_info[68].fileLength = 277U;
  c11_info[68].fileTime1 = 1192445184U;
  c11_info[68].fileTime2 = 0U;
  c11_info[69].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[69].name = "eml_index_times";
  c11_info[69].dominantType = "int32";
  c11_info[69].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c11_info[69].fileLength = 280U;
  c11_info[69].fileTime1 = 1192445186U;
  c11_info[69].fileTime2 = 0U;
  c11_info[70].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[70].name = "eml_ixamax";
  c11_info[70].dominantType = "int32";
  c11_info[70].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c11_info[70].fileLength = 731U;
  c11_info[70].fileTime1 = 1209309244U;
  c11_info[70].fileTime2 = 0U;
  c11_info[71].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c11_info[71].name = "eml_refblas_ixamax";
  c11_info[71].dominantType = "int32";
  c11_info[71].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c11_info[71].fileLength = 740U;
  c11_info[71].fileTime1 = 1192445266U;
  c11_info[71].fileTime2 = 0U;
  c11_info[72].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c11_info[72].name = "eml_xcabs1";
  c11_info[72].dominantType = "double";
  c11_info[72].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c11_info[72].fileLength = 419U;
  c11_info[72].fileTime1 = 1209309246U;
  c11_info[72].fileTime2 = 0U;
  c11_info[73].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c11_info[73].name = "real";
  c11_info[73].dominantType = "double";
  c11_info[73].resolved = "[B]real";
  c11_info[73].fileLength = 0U;
  c11_info[73].fileTime1 = 0U;
  c11_info[73].fileTime2 = 0U;
  c11_info[74].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c11_info[74].name = "abs";
  c11_info[74].dominantType = "double";
  c11_info[74].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[74].fileLength = 566U;
  c11_info[74].fileTime1 = 1221245532U;
  c11_info[74].fileTime2 = 0U;
  c11_info[75].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[75].name = "eml_scalar_abs";
  c11_info[75].dominantType = "double";
  c11_info[75].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c11_info[75].fileLength = 461U;
  c11_info[75].fileTime1 = 1203422760U;
  c11_info[75].fileTime2 = 0U;
  c11_info[76].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c11_info[76].name = "imag";
  c11_info[76].dominantType = "double";
  c11_info[76].resolved = "[B]imag";
  c11_info[76].fileLength = 0U;
  c11_info[76].fileTime1 = 0U;
  c11_info[76].fileTime2 = 0U;
  c11_info[77].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[77].name = "eml_xswap";
  c11_info[77].dominantType = "int32";
  c11_info[77].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c11_info[77].fileLength = 1330U;
  c11_info[77].fileTime1 = 1209309260U;
  c11_info[77].fileTime2 = 0U;
  c11_info[78].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c11_info[78].name = "eml_refblas_xswap";
  c11_info[78].dominantType = "int32";
  c11_info[78].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c11_info[78].fileLength = 905U;
  c11_info[78].fileTime1 = 1238412670U;
  c11_info[78].fileTime2 = 0U;
  c11_info[79].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c11_info[79].name = "eml_xgeru";
  c11_info[79].dominantType = "int32";
  c11_info[79].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c11_info[79].fileLength = 2462U;
  c11_info[79].fileTime1 = 1209309256U;
  c11_info[79].fileTime2 = 0U;
  c11_info[80].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c11_info[80].name = "eml_xger";
  c11_info[80].dominantType = "int32";
  c11_info[80].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c11_info[80].fileLength = 2168U;
  c11_info[80].fileTime1 = 1209309254U;
  c11_info[80].fileTime2 = 0U;
  c11_info[81].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c11_info[81].name = "eml_refblas_xger";
  c11_info[81].dominantType = "int32";
  c11_info[81].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c11_info[81].fileLength = 411U;
  c11_info[81].fileTime1 = 1211194448U;
  c11_info[81].fileTime2 = 0U;
  c11_info[82].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c11_info[82].name = "eml_refblas_xgerx";
  c11_info[82].dominantType = "int32";
  c11_info[82].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c11_info[82].fileLength = 2231U;
  c11_info[82].fileTime1 = 1238412668U;
  c11_info[82].fileTime2 = 0U;
  c11_info[83].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c11_info[83].name = "times";
  c11_info[83].dominantType = "double";
  c11_info[83].resolved = "[B]times";
  c11_info[83].fileLength = 0U;
  c11_info[83].fileTime1 = 0U;
  c11_info[83].fileTime2 = 0U;
  c11_info[84].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c11_info[84].name = "eml_warning";
  c11_info[84].dominantType = "char";
  c11_info[84].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c11_info[84].fileLength = 262U;
  c11_info[84].fileTime1 = 1236232078U;
  c11_info[84].fileTime2 = 0U;
  c11_info[85].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c11_info[85].name = "eml_xtrsm";
  c11_info[85].dominantType = "int32";
  c11_info[85].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c11_info[85].fileLength = 2383U;
  c11_info[85].fileTime1 = 1209309262U;
  c11_info[85].fileTime2 = 0U;
  c11_info[86].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!itcount";
  c11_info[86].name = "length";
  c11_info[86].dominantType = "double";
  c11_info[86].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c11_info[86].fileLength = 326U;
  c11_info[86].fileTime1 = 1226552074U;
  c11_info[86].fileTime2 = 0U;
  c11_info[87].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c11_info[87].name = "eml_refblas_xtrsm";
  c11_info[87].dominantType = "int32";
  c11_info[87].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c11_info[87].fileLength = 13101U;
  c11_info[87].fileTime1 = 1252487206U;
  c11_info[87].fileTime2 = 0U;
  c11_info[88].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[88].name = "eml_xgemm";
  c11_info[88].dominantType = "int32";
  c11_info[88].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[88].fileLength = 3184U;
  c11_info[88].fileTime1 = 1209309252U;
  c11_info[88].fileTime2 = 0U;
  c11_info[89].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[89].name = "eml_refblas_xgemm";
  c11_info[89].dominantType = "int32";
  c11_info[89].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[89].fileLength = 5748U;
  c11_info[89].fileTime1 = 1228068672U;
  c11_info[89].fileTime2 = 0U;
  c11_info[90].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[90].name = "atan2";
  c11_info[90].dominantType = "double";
  c11_info[90].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c11_info[90].fileLength = 605U;
  c11_info[90].fileTime1 = 1236232054U;
  c11_info[90].fileTime2 = 0U;
  c11_info[91].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m";
  c11_info[91].name = "eml_scalar_atan2";
  c11_info[91].dominantType = "double";
  c11_info[91].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c11_info[91].fileLength = 964U;
  c11_info[91].fileTime1 = 1209309186U;
  c11_info[91].fileTime2 = 0U;
  c11_info[92].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m!isInRange";
  c11_info[92].name = "pi";
  c11_info[92].dominantType = "";
  c11_info[92].resolved = "[B]pi";
  c11_info[92].fileLength = 0U;
  c11_info[92].fileTime1 = 0U;
  c11_info[92].fileTime2 = 0U;
  c11_info[93].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m!isInRange";
  c11_info[93].name = "and";
  c11_info[93].dominantType = "logical";
  c11_info[93].resolved = "[B]and";
  c11_info[93].fileLength = 0U;
  c11_info[93].fileTime1 = 0U;
  c11_info[93].fileTime2 = 0U;
  c11_info[94].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[94].name = "expWre";
  c11_info[94].dominantType = "double";
  c11_info[94].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/expWre.m";
  c11_info[94].fileLength = 413U;
  c11_info[94].fileTime1 = 1366220272U;
  c11_info[94].fileTime2 = 0U;
  c11_info[95].context = "[E]D:/Learn/MatlabProgram/Fanuc/expWre.m";
  c11_info[95].name = "eye";
  c11_info[95].dominantType = "double";
  c11_info[95].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c11_info[95].fileLength = 1765U;
  c11_info[95].fileTime1 = 1219731288U;
  c11_info[95].fileTime2 = 0U;
  c11_info[96].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c11_info[96].name = "eml_assert_valid_size_arg";
  c11_info[96].dominantType = "double";
  c11_info[96].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c11_info[96].fileLength = 3315U;
  c11_info[96].fileTime1 = 1256367816U;
  c11_info[96].fileTime2 = 0U;
  c11_info[97].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c11_info[97].name = "isinf";
  c11_info[97].dominantType = "double";
  c11_info[97].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c11_info[97].fileLength = 541U;
  c11_info[97].fileTime1 = 1271383988U;
  c11_info[97].fileTime2 = 0U;
  c11_info[98].context = "[E]D:/Learn/MatlabProgram/Fanuc/expWre.m";
  c11_info[98].name = "expRot";
  c11_info[98].dominantType = "double";
  c11_info[98].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c11_info[98].fileLength = 236U;
  c11_info[98].fileTime1 = 1366773052U;
  c11_info[98].fileTime2 = 0U;
  c11_info[99].context = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c11_info[99].name = "skew";
  c11_info[99].dominantType = "double";
  c11_info[99].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/skew.m";
  c11_info[99].fileLength = 336U;
  c11_info[99].fileTime1 = 1368990691U;
  c11_info[99].fileTime2 = 0U;
  c11_info[100].context = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c11_info[100].name = "sin";
  c11_info[100].dominantType = "double";
  c11_info[100].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[100].fileLength = 324U;
  c11_info[100].fileTime1 = 1203422842U;
  c11_info[100].fileTime2 = 0U;
  c11_info[101].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c11_info[101].name = "eml_scalar_sin";
  c11_info[101].dominantType = "double";
  c11_info[101].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c11_info[101].fileLength = 601U;
  c11_info[101].fileTime1 = 1209309190U;
  c11_info[101].fileTime2 = 0U;
  c11_info[102].context = "[E]D:/Learn/MatlabProgram/Fanuc/expRot.m";
  c11_info[102].name = "cos";
  c11_info[102].dominantType = "double";
  c11_info[102].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[102].fileLength = 324U;
  c11_info[102].fileTime1 = 1203422750U;
  c11_info[102].fileTime2 = 0U;
  c11_info[103].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c11_info[103].name = "eml_scalar_cos";
  c11_info[103].dominantType = "double";
  c11_info[103].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c11_info[103].fileLength = 602U;
  c11_info[103].fileTime1 = 1209309186U;
  c11_info[103].fileTime2 = 0U;
  c11_info[104].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[104].name = "subPro3";
  c11_info[104].dominantType = "double";
  c11_info[104].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/subPro3.m";
  c11_info[104].fileLength = 1099U;
  c11_info[104].fileTime1 = 1367251936U;
  c11_info[104].fileTime2 = 0U;
  c11_info[105].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[105].name = "eml_xdotu";
  c11_info[105].dominantType = "int32";
  c11_info[105].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c11_info[105].fileLength = 1453U;
  c11_info[105].fileTime1 = 1209309250U;
  c11_info[105].fileTime2 = 0U;
  c11_info[106].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c11_info[106].name = "eml_xdot";
  c11_info[106].dominantType = "int32";
  c11_info[106].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c11_info[106].fileLength = 1330U;
  c11_info[106].fileTime1 = 1209309248U;
  c11_info[106].fileTime2 = 0U;
  c11_info[107].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c11_info[107].name = "eml_refblas_xdot";
  c11_info[107].dominantType = "int32";
  c11_info[107].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c11_info[107].fileLength = 343U;
  c11_info[107].fileTime1 = 1211194442U;
  c11_info[107].fileTime2 = 0U;
  c11_info[108].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c11_info[108].name = "eml_refblas_xdotx";
  c11_info[108].dominantType = "int32";
  c11_info[108].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c11_info[108].fileLength = 1605U;
  c11_info[108].fileTime1 = 1236232078U;
  c11_info[108].fileTime2 = 0U;
  c11_info[109].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro3.m";
  c11_info[109].name = "norm";
  c11_info[109].dominantType = "double";
  c11_info[109].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c11_info[109].fileLength = 5453U;
  c11_info[109].fileTime1 = 1271384008U;
  c11_info[109].fileTime2 = 0U;
  c11_info[110].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c11_info[110].name = "eml_xnrm2";
  c11_info[110].dominantType = "int32";
  c11_info[110].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c11_info[110].fileLength = 718U;
  c11_info[110].fileTime1 = 1209309256U;
  c11_info[110].fileTime2 = 0U;
  c11_info[111].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c11_info[111].name = "eml_refblas_xnrm2";
  c11_info[111].dominantType = "int32";
  c11_info[111].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c11_info[111].fileLength = 1433U;
  c11_info[111].fileTime1 = 1240240442U;
  c11_info[111].fileTime2 = 0U;
  c11_info[112].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro3.m";
  c11_info[112].name = "acos";
  c11_info[112].dominantType = "double";
  c11_info[112].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c11_info[112].fileLength = 585U;
  c11_info[112].fileTime1 = 1203422730U;
  c11_info[112].fileTime2 = 0U;
  c11_info[113].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m";
  c11_info[113].name = "eml_scalar_acos";
  c11_info[113].dominantType = "double";
  c11_info[113].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  c11_info[113].fileLength = 553U;
  c11_info[113].fileTime1 = 1203422760U;
  c11_info[113].fileTime2 = 0U;
  c11_info[114].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[114].name = "any";
  c11_info[114].dominantType = "logical";
  c11_info[114].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m";
  c11_info[114].fileLength = 427U;
  c11_info[114].fileTime1 = 1221245538U;
  c11_info[114].fileTime2 = 0U;
  c11_info[115].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c11_info[115].name = "isnan";
  c11_info[115].dominantType = "logical";
  c11_info[115].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c11_info[115].fileLength = 541U;
  c11_info[115].fileTime1 = 1271383988U;
  c11_info[115].fileTime2 = 0U;
  c11_info[116].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[116].name = "subPro1";
  c11_info[116].dominantType = "double";
  c11_info[116].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/subPro1.m";
  c11_info[116].fileLength = 393U;
  c11_info[116].fileTime1 = 1336045298U;
  c11_info[116].fileTime2 = 0U;
  c11_info[117].context = "[E]D:/Learn/MatlabProgram/Fanuc/inv_kin.m";
  c11_info[117].name = "subPro2";
  c11_info[117].dominantType = "double";
  c11_info[117].resolved = "[E]D:/Learn/MatlabProgram/Fanuc/subPro2.m";
  c11_info[117].fileLength = 1886U;
  c11_info[117].fileTime1 = 1367255418U;
  c11_info[117].fileTime2 = 0U;
  c11_info[118].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro2.m!findCommon";
  c11_info[118].name = "det";
  c11_info[118].dominantType = "double";
  c11_info[118].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/det.m";
  c11_info[118].fileLength = 755U;
  c11_info[118].fileTime1 = 1228068678U;
  c11_info[118].fileTime2 = 0U;
  c11_info[119].context = "[E]D:/Learn/MatlabProgram/Fanuc/subPro2.m";
  c11_info[119].name = "sqrt";
  c11_info[119].dominantType = "double";
  c11_info[119].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c11_info[119].fileLength = 572U;
  c11_info[119].fileTime1 = 1203422844U;
  c11_info[119].fileTime2 = 0U;
  c11_info[120].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c11_info[120].name = "eml_scalar_sqrt";
  c11_info[120].dominantType = "double";
  c11_info[120].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c11_info[120].fileLength = 664U;
  c11_info[120].fileTime1 = 1209309194U;
  c11_info[120].fileTime2 = 0U;
  c11_info[121].context = "";
  c11_info[121].name = "find";
  c11_info[121].dominantType = "logical";
  c11_info[121].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c11_info[121].fileLength = 7812U;
  c11_info[121].fileTime1 = 1258601796U;
  c11_info[121].fileTime2 = 0U;
  c11_info[122].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/find.m";
  c11_info[122].name = "assert";
  c11_info[122].dominantType = "logical";
  c11_info[122].resolved = "[B]assert";
  c11_info[122].fileLength = 0U;
  c11_info[122].fileTime1 = 0U;
  c11_info[122].fileTime2 = 0U;
}

static void c11_emlrt_marshallIn(SFc11_KinConInstanceStruct *chartInstance,
  const mxArray *c11_theta, const char_T *c11_name, real_T
  c11_y[6])
{
  real_T c11_dv36[6];
  int32_T c11_i912;
  sf_mex_import(c11_name, sf_mex_dup(c11_theta), c11_dv36, 1, 0, 0U, 1, 0U, 1, 6);
  for (c11_i912 = 0; c11_i912 < 6; c11_i912 = c11_i912 + 1) {
    c11_y[c11_i912] = c11_dv36[c11_i912];
  }

  sf_mex_destroy(&c11_theta);
}

static uint8_T c11_b_emlrt_marshallIn(SFc11_KinConInstanceStruct *chartInstance,
  const mxArray *c11_b_is_active_c11_KinCon, const
  char_T *c11_name)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_name, sf_mex_dup(c11_b_is_active_c11_KinCon), &c11_u0, 1, 3,
                0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_b_is_active_c11_KinCon);
  return c11_y;
}

static void init_dsm_address_info(SFc11_KinConInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c11_KinCon_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(726007309U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(604882510U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1049498011U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1091066525U);
}

mxArray *sf_c11_KinCon_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1369463522U);
    pr[1] = (double)(3795517018U);
    pr[2] = (double)(745604350U);
    pr[3] = (double)(1010822884U);
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

static mxArray *sf_get_sim_state_info_c11_KinCon(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"theta\",},{M[8],M[0],T\"is_active_c11_KinCon\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_KinCon_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_KinConInstanceStruct *chartInstance;
    chartInstance = (SFc11_KinConInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart(_KinConMachineNumber_,
          11,
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
          init_script_number_translation(_KinConMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting(_KinConMachineNumber_,
            chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_KinConMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,302);
        _SFD_CV_INIT_EML_IF(0,0,207,224,255,302);
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
            1.0,0,0,(MexFcnForType)c11_d_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshall);
        }

        {
          real_T (*c11_EndPos)[3];
          real_T (*c11_theta)[6];
          c11_theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c11_EndPos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c11_EndPos);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c11_init_Rot);
          _SFD_SET_DATA_VALUE_PTR(2U, *c11_theta);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_KinConMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c11_KinCon(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_KinConInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c11_KinCon((SFc11_KinConInstanceStruct*) chartInstanceVar);
  initialize_c11_KinCon((SFc11_KinConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_KinCon(void *chartInstanceVar)
{
  enable_c11_KinCon((SFc11_KinConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_KinCon(void *chartInstanceVar)
{
  disable_c11_KinCon((SFc11_KinConInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_KinCon(void *chartInstanceVar)
{
  sf_c11_KinCon((SFc11_KinConInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c11_KinCon(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_KinCon((SFc11_KinConInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c11_KinCon();/* state var info */
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

static void sf_internal_set_sim_state_c11_KinCon(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_KinCon();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_KinCon((SFc11_KinConInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c11_KinCon(SimStruct* S)
{
  return sf_internal_get_sim_state_c11_KinCon(S);
}

static void sf_opaque_set_sim_state_c11_KinCon(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c11_KinCon(S, st);
}

static void sf_opaque_terminate_c11_KinCon(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_KinConInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c11_KinCon((SFc11_KinConInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c11_KinCon((SFc11_KinConInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_KinCon(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_KinCon((SFc11_KinConInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_KinCon(SimStruct *S)
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
      (int_T)sf_is_chart_inlinable(S,"KinCon","KinCon",11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"KinCon","KinCon",11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"KinCon","KinCon",11,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"KinCon","KinCon",11,1);
      sf_mark_chart_reusable_outputs(S,"KinCon","KinCon",11,1);
    }

    sf_set_rtw_dwork_info(S,"KinCon","KinCon",11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4196986251U));
  ssSetChecksum1(S,(1335293210U));
  ssSetChecksum2(S,(253746836U));
  ssSetChecksum3(S,(2855431896U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c11_KinCon(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "KinCon", "KinCon",11);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_KinCon(SimStruct *S)
{
  SFc11_KinConInstanceStruct *chartInstance;
  chartInstance = (SFc11_KinConInstanceStruct *)malloc(sizeof
    (SFc11_KinConInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_KinConInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c11_KinCon;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c11_KinCon;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c11_KinCon;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_KinCon;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_KinCon;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c11_KinCon;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c11_KinCon;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c11_KinCon;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_KinCon;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_KinCon;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_KinCon;
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

void c11_KinCon_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_KinCon(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_KinCon(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_KinCon(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_KinCon_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
