/* Include files */

#include "blascompat32.h"
#include "CtrPlatform_AdaptiveControl1_sfun.h"
#include "c1_CtrPlatform_AdaptiveControl1.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "CtrPlatform_AdaptiveControl1_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[9] = { "gd", "Theta_total",
  "num_total", "nargin", "nargout", "EndPos", "init_Rot", "L", "Theta" };

static const char * c1_b_debug_family_names[6] = { "nargin", "nargout", "x",
  "xmin", "xmax", "isIn" };

static const char * c1_c_debug_family_names[4] = { "nargin", "nargout", "w",
  "wh" };

static const char * c1_d_debug_family_names[6] = { "wh", "nargin", "nargout",
  "w", "theta", "R" };

static const char * c1_e_debug_family_names[9] = { "v", "w", "R", "p", "nargin",
  "nargout", "kx", "theta", "g" };

static const char * c1_f_debug_family_names[18] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "dp2", "theta0", "phi", "p", "q", "d", "nargin", "nargout",
  "kx", "theta", "Nsol" };

static const char * c1_g_debug_family_names[6] = { "nargin", "nargout", "x",
  "xmin", "xmax", "isIn" };

static const char * c1_h_debug_family_names[13] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char * c1_i_debug_family_names[10] = { "A", "vec", "cof", "nargin",
  "nargout", "w1", "w2", "r1", "r2", "r" };

static const char * c1_j_debug_family_names[13] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char * c1_k_debug_family_names[13] = { "velociy", "w", "r", "u",
  "v", "up", "vp", "nargin", "nargout", "kx", "p", "q", "theta" };

static const char * c1_l_debug_family_names[24] = { "velociy1", "w1", "r1",
  "velociy2", "w2", "r2", "r", "u", "v", "alpha", "beta", "ySqu", "y", "z", "c",
  "nargin", "nargout", "kx1", "kx2", "p", "q", "theta1", "theta2", "Nsol" };

static const char * c1_m_debug_family_names[69] = { "Min1", "Max1", "Min2",
  "Max2", "Min3", "Max3", "Min4", "Max4", "Min5", "Max5", "Min6", "Max6", "L1",
  "L2", "L3", "L4", "L5", "L6", "L7", "L8", "L9", "s_origin", "w_x", "w_y",
  "w_z", "w1", "q1", "kx1", "w2", "q2", "kx2", "w3", "q3", "kx3", "pw", "w4",
  "q4", "kx4", "w5", "q5", "kx5", "w6", "q6", "kx6", "q7", "gst0", "g1", "p1",
  "theta_1", "p2", "d", "theta_3", "Num_3", "p3", "theta_2", "g2", "p4",
  "theta_4", "theta_5", "Num_45", "g3", "p5", "theta_6", "nargin", "nargout",
  "gd", "L", "theta", "Num" };

/* Function Declarations */
static void initialize_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void initialize_params_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void enable_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void disable_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void set_sim_state_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void sf_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void initSimStructsc1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *
  chartInstance, const mxArray *c1_Theta, const char_T *c1_identifier, real_T
  c1_y[6]);
static void c1_b_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_e_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_f_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[24]);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_g_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[16]);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_h_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_i_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3]);
static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_j_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_k_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_l_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[2]);
static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_m_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[209]);
static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[209]);
static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[209]);
static void c1_d_info_helper(c1_ResolvedFunctionInfo c1_info[209]);
static void c1_inv_kin(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_gd[16], real_T c1_b_L[9], real_T c1_theta[24],
  real_T *c1_Num);
static void c1_cross(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                     *chartInstance, real_T c1_a[3], real_T c1_b[3], real_T
                     c1_c[3]);
static boolean_T c1_all(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, boolean_T c1_x[2]);
static void c1_mrdivide(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_B[16], real_T c1_y[16]);
static void c1_realmin(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_eps(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                   *chartInstance);
static void c1_eml_matlab_zgetrf(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_b_A[16], int32_T c1_ipiv[4],
  int32_T *c1_info);
static void c1_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static int32_T c1_eml_ixamax(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[16], int32_T c1_ix0);
static void c1_b_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, int32_T c1_b);
static void c1_c_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void c1_d_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, int32_T c1_a,
   int32_T c1_b);
static void c1_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_eml_warning(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_b_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_eml_xtrsm(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_B[16], real_T c1_b_B[16]);
static void c1_below_threshold(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_c_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_e_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);
static void c1_d_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static real_T c1_atan2(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_y, real_T c1_x);
static boolean_T c1_isInRange(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_x, real_T c1_xmin, real_T c1_xmax);
static void c1_expWre(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                      *chartInstance, real_T c1_kx[6], real_T c1_theta, real_T
                      c1_g[16]);
static void c1_eye(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                   *chartInstance, real_T c1_I[9]);
static void c1_expRot(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                      *chartInstance, real_T c1_w[3], real_T c1_theta, real_T
                      c1_R[9]);
static void c1_e_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_f_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_subPro3(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[4], real_T c1_q[4], real_T c1_d[4],
  real_T c1_theta[2], real_T *c1_Nsol);
static void c1_g_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static real_T c1_mpower(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_a);
static real_T c1_norm(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                      *chartInstance, real_T c1_x[3]);
static void c1_eml_error(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static void c1_b_isInRange(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_x[2], real_T c1_xmin, real_T c1_xmax, boolean_T
  c1_isIn[2]);
static boolean_T c1_any(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, boolean_T c1_x[2]);
static real_T c1_subPro1(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[4], real_T c1_q[4]);
static void c1_subPro2(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx1[6], real_T c1_kx2[6], real_T c1_p[4], real_T
  c1_q[4], real_T c1_theta1[2], real_T c1_theta2[2], real_T *c1_Nsol);
static void c1_findCommon(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_w1[3], real_T c1_w2[3], real_T c1_r1[3], real_T
  c1_r2[3], real_T c1_r[3]);
static real_T c1_det(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                     *chartInstance, real_T c1_x[4]);
static void c1_b_eml_matlab_zgetrf
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, real_T c1_A[4],
   real_T c1_b_A[4], int32_T c1_ipiv[2], int32_T *c1_info);
static void c1_eml_xger(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_alpha1, real_T c1_A[4], real_T c1_b_A[4]);
static void c1_b_eml_error(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance);
static real_T c1_b_subPro1(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[4], real_T c1_q[3]);
static real_T c1_c_subPro1(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[3], real_T c1_q[4]);
static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_n_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_o_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_CtrPlatform_AdaptiveControl1, const char_T *c1_identifier);
static uint8_T c1_p_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_eml_matlab_zgetrf
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, real_T c1_A
   [16], int32_T c1_ipiv[4], int32_T *c1_info);
static void c1_b_eml_xtrsm(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_B[16]);
static void c1_d_eml_matlab_zgetrf
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, real_T c1_A[4],
   int32_T c1_ipiv[2], int32_T *c1_info);
static void c1_b_eml_xger(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_alpha1, real_T c1_A[4]);
static void init_dsm_address_info
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_CtrPlatform_AdaptiveControl1 = 0U;
}

static void initialize_params_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  real_T c1_dv0[9];
  int32_T c1_i0;
  real_T c1_dv1[9];
  int32_T c1_i1;
  sf_set_error_prefix_string(
    "Error evaluating data 'init_Rot' in the parent workspace.\n");
  sf_mex_import_named("init_Rot", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c1_dv0, 0, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i0 = 0; c1_i0 < 9; c1_i0++) {
    chartInstance->c1_init_Rot[c1_i0] = c1_dv0[c1_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import_named("L", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c1_dv1,
                      0, 0, 0U, 1, 0U, 2, 1, 9);
  for (c1_i1 = 0; c1_i1 < 9; c1_i1++) {
    chartInstance->c1_L[c1_i1] = c1_dv1[c1_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i2;
  real_T c1_u[6];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_Theta)[6];
  c1_Theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i2 = 0; c1_i2 < 6; c1_i2++) {
    c1_u[c1_i2] = (*c1_Theta)[c1_i2];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal = chartInstance->c1_is_active_c1_CtrPlatform_AdaptiveControl1;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv2[6];
  int32_T c1_i3;
  real_T (*c1_Theta)[6];
  c1_Theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "Theta", c1_dv2);
  for (c1_i3 = 0; c1_i3 < 6; c1_i3++) {
    (*c1_Theta)[c1_i3] = c1_dv2[c1_i3];
  }

  chartInstance->c1_is_active_c1_CtrPlatform_AdaptiveControl1 =
    c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_CtrPlatform_AdaptiveControl1");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_CtrPlatform_AdaptiveControl1(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static void sf_c1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  int32_T c1_i8;
  real_T c1_EndPos[3];
  int32_T c1_i9;
  real_T c1_b_init_Rot[9];
  int32_T c1_i10;
  real_T c1_b_L[9];
  uint32_T c1_debug_family_var_map[9];
  real_T c1_gd[16];
  real_T c1_Theta_total[24];
  real_T c1_num_total;
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_Theta[6];
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_i18;
  static real_T c1_dv3[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c1_i19;
  real_T c1_b_gd[16];
  int32_T c1_i20;
  real_T c1_c_L[9];
  real_T c1_b_num_total;
  real_T c1_b_Theta_total[24];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T (*c1_b_Theta)[6];
  real_T (*c1_b_EndPos)[3];
  c1_b_Theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_EndPos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i4 = 0; c1_i4 < 3; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_EndPos)[c1_i4], 0U);
  }

  for (c1_i5 = 0; c1_i5 < 9; c1_i5++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_init_Rot[c1_i5], 1U);
  }

  for (c1_i6 = 0; c1_i6 < 6; c1_i6++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_Theta)[c1_i6], 2U);
  }

  for (c1_i7 = 0; c1_i7 < 9; c1_i7++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c1_L[c1_i7], 3U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i8 = 0; c1_i8 < 3; c1_i8++) {
    c1_EndPos[c1_i8] = (*c1_b_EndPos)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 9; c1_i9++) {
    c1_b_init_Rot[c1_i9] = chartInstance->c1_init_Rot[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 9; c1_i10++) {
    c1_b_L[c1_i10] = chartInstance->c1_L[c1_i10];
  }

  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_gd, 0U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Theta_total, 1U,
    c1_f_sf_marshallOut, c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_num_total, 2U,
    c1_e_sf_marshallOut, c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 3U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 4U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_EndPos, 5U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_b_init_Rot, 6U,
    c1_c_sf_marshallOut, c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_L, 7U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Theta, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  for (c1_i11 = 0; c1_i11 < 6; c1_i11++) {
    c1_Theta[c1_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_i12 = 0;
  c1_i13 = 0;
  for (c1_i14 = 0; c1_i14 < 3; c1_i14++) {
    for (c1_i15 = 0; c1_i15 < 3; c1_i15++) {
      c1_gd[c1_i15 + c1_i12] = c1_b_init_Rot[c1_i15 + c1_i13];
    }

    c1_i12 += 4;
    c1_i13 += 3;
  }

  for (c1_i16 = 0; c1_i16 < 3; c1_i16++) {
    c1_gd[c1_i16 + 12] = c1_EndPos[c1_i16];
  }

  c1_i17 = 0;
  for (c1_i18 = 0; c1_i18 < 4; c1_i18++) {
    c1_gd[c1_i17 + 3] = c1_dv3[c1_i18];
    c1_i17 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  for (c1_i19 = 0; c1_i19 < 16; c1_i19++) {
    c1_b_gd[c1_i19] = c1_gd[c1_i19];
  }

  for (c1_i20 = 0; c1_i20 < 9; c1_i20++) {
    c1_c_L[c1_i20] = c1_b_L[c1_i20];
  }

  c1_inv_kin(chartInstance, c1_b_gd, c1_c_L, c1_b_Theta_total, &c1_b_num_total);
  for (c1_i21 = 0; c1_i21 < 24; c1_i21++) {
    c1_Theta_total[c1_i21] = c1_b_Theta_total[c1_i21];
  }

  c1_num_total = c1_b_num_total;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i22 = 0; c1_i22 < 6; c1_i22++) {
    c1_Theta[c1_i22] = c1_Theta_total[c1_i22 + 6];
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  for (c1_i23 = 0; c1_i23 < 6; c1_i23++) {
    (*c1_b_Theta)[c1_i23] = c1_Theta[c1_i23];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_CtrPlatform_AdaptiveControl1MachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc1_CtrPlatform_AdaptiveControl1
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 0U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/inv_kin.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 1U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/expWre.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 2U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/expRot.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 3U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/skew.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 4U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/subPro3.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 5U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/subPro1.m"));
  _SFD_SCRIPT_TRANSLATION(c1_chartNumber, 6U, sf_debug_get_script_id(
    "E:/\xd5\xe3\xb4\xf3/\xd7\xd4\xd6\xf7\xca\xb5\xcf\xb0/Dynamics_DaiDan/Fanuc/subPro2.m"));
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i24;
  real_T c1_b_inData[6];
  int32_T c1_i25;
  real_T c1_u[6];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i24 = 0; c1_i24 < 6; c1_i24++) {
    c1_b_inData[c1_i24] = (*(real_T (*)[6])c1_inData)[c1_i24];
  }

  for (c1_i25 = 0; c1_i25 < 6; c1_i25++) {
    c1_u[c1_i25] = c1_b_inData[c1_i25];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *
  chartInstance, const mxArray *c1_Theta, const char_T *c1_identifier, real_T
  c1_y[6])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Theta), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Theta);
}

static void c1_b_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[6])
{
  real_T c1_dv4[6];
  int32_T c1_i26;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c1_i26 = 0; c1_i26 < 6; c1_i26++) {
    c1_y[c1_i26] = c1_dv4[c1_i26];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Theta;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[6];
  int32_T c1_i27;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_Theta = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Theta), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Theta);
  for (c1_i27 = 0; c1_i27 < 6; c1_i27++) {
    (*(real_T (*)[6])c1_outData)[c1_i27] = c1_y[c1_i27];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i28;
  real_T c1_b_inData[9];
  int32_T c1_i29;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i28 = 0; c1_i28 < 9; c1_i28++) {
    c1_b_inData[c1_i28] = (*(real_T (*)[9])c1_inData)[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 9; c1_i29++) {
    c1_u[c1_i29] = c1_b_inData[c1_i29];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 9), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv5[9];
  int32_T c1_i30;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv5, 1, 0, 0U, 1, 0U, 2, 1, 9);
  for (c1_i30 = 0; c1_i30 < 9; c1_i30++) {
    c1_y[c1_i30] = c1_dv5[c1_i30];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_L;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i31;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_b_L = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_L), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_L);
  for (c1_i31 = 0; c1_i31 < 9; c1_i31++) {
    (*(real_T (*)[9])c1_outData)[c1_i31] = c1_y[c1_i31];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i32;
  int32_T c1_i33;
  int32_T c1_i34;
  real_T c1_b_inData[9];
  int32_T c1_i35;
  int32_T c1_i36;
  int32_T c1_i37;
  real_T c1_u[9];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i32 = 0;
  for (c1_i33 = 0; c1_i33 < 3; c1_i33++) {
    for (c1_i34 = 0; c1_i34 < 3; c1_i34++) {
      c1_b_inData[c1_i34 + c1_i32] = (*(real_T (*)[9])c1_inData)[c1_i34 + c1_i32];
    }

    c1_i32 += 3;
  }

  c1_i35 = 0;
  for (c1_i36 = 0; c1_i36 < 3; c1_i36++) {
    for (c1_i37 = 0; c1_i37 < 3; c1_i37++) {
      c1_u[c1_i37 + c1_i35] = c1_b_inData[c1_i37 + c1_i35];
    }

    c1_i35 += 3;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[9])
{
  real_T c1_dv6[9];
  int32_T c1_i38;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv6, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c1_i38 = 0; c1_i38 < 9; c1_i38++) {
    c1_y[c1_i38] = c1_dv6[c1_i38];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_init_Rot;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[9];
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_b_init_Rot = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_init_Rot), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_init_Rot);
  c1_i39 = 0;
  for (c1_i40 = 0; c1_i40 < 3; c1_i40++) {
    for (c1_i41 = 0; c1_i41 < 3; c1_i41++) {
      (*(real_T (*)[9])c1_outData)[c1_i41 + c1_i39] = c1_y[c1_i41 + c1_i39];
    }

    c1_i39 += 3;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i42;
  real_T c1_b_inData[3];
  int32_T c1_i43;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i42 = 0; c1_i42 < 3; c1_i42++) {
    c1_b_inData[c1_i42] = (*(real_T (*)[3])c1_inData)[c1_i42];
  }

  for (c1_i43 = 0; c1_i43 < 3; c1_i43++) {
    c1_u[c1_i43] = c1_b_inData[c1_i43];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_e_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  real_T c1_b_inData[24];
  int32_T c1_i47;
  int32_T c1_i48;
  int32_T c1_i49;
  real_T c1_u[24];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i44 = 0;
  for (c1_i45 = 0; c1_i45 < 4; c1_i45++) {
    for (c1_i46 = 0; c1_i46 < 6; c1_i46++) {
      c1_b_inData[c1_i46 + c1_i44] = (*(real_T (*)[24])c1_inData)[c1_i46 +
        c1_i44];
    }

    c1_i44 += 6;
  }

  c1_i47 = 0;
  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    for (c1_i49 = 0; c1_i49 < 6; c1_i49++) {
      c1_u[c1_i49 + c1_i47] = c1_b_inData[c1_i49 + c1_i47];
    }

    c1_i47 += 6;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 6, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_f_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[24])
{
  real_T c1_dv7[24];
  int32_T c1_i50;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv7, 1, 0, 0U, 1, 0U, 2, 6, 4);
  for (c1_i50 = 0; c1_i50 < 24; c1_i50++) {
    c1_y[c1_i50] = c1_dv7[c1_i50];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Theta_total;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[24];
  int32_T c1_i51;
  int32_T c1_i52;
  int32_T c1_i53;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_Theta_total = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Theta_total), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_Theta_total);
  c1_i51 = 0;
  for (c1_i52 = 0; c1_i52 < 4; c1_i52++) {
    for (c1_i53 = 0; c1_i53 < 6; c1_i53++) {
      (*(real_T (*)[24])c1_outData)[c1_i53 + c1_i51] = c1_y[c1_i53 + c1_i51];
    }

    c1_i51 += 6;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  real_T c1_b_inData[16];
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  real_T c1_u[16];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i54 = 0;
  for (c1_i55 = 0; c1_i55 < 4; c1_i55++) {
    for (c1_i56 = 0; c1_i56 < 4; c1_i56++) {
      c1_b_inData[c1_i56 + c1_i54] = (*(real_T (*)[16])c1_inData)[c1_i56 +
        c1_i54];
    }

    c1_i54 += 4;
  }

  c1_i57 = 0;
  for (c1_i58 = 0; c1_i58 < 4; c1_i58++) {
    for (c1_i59 = 0; c1_i59 < 4; c1_i59++) {
      c1_u[c1_i59 + c1_i57] = c1_b_inData[c1_i59 + c1_i57];
    }

    c1_i57 += 4;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_g_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[16])
{
  real_T c1_dv8[16];
  int32_T c1_i60;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv8, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c1_i60 = 0; c1_i60 < 16; c1_i60++) {
    c1_y[c1_i60] = c1_dv8[c1_i60];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_gd;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[16];
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_gd = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_gd), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_gd);
  c1_i61 = 0;
  for (c1_i62 = 0; c1_i62 < 4; c1_i62++) {
    for (c1_i63 = 0; c1_i63 < 4; c1_i63++) {
      (*(real_T (*)[16])c1_outData)[c1_i63 + c1_i61] = c1_y[c1_i63 + c1_i61];
    }

    c1_i61 += 4;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static boolean_T c1_h_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_isIn;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_isIn = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_isIn), &c1_thisId);
  sf_mex_destroy(&c1_isIn);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_i_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[3])
{
  real_T c1_dv9[3];
  int32_T c1_i64;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv9, 1, 0, 0U, 1, 0U, 1, 3);
  for (c1_i64 = 0; c1_i64 < 3; c1_i64++) {
    c1_y[c1_i64] = c1_dv9[c1_i64];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_w;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[3];
  int32_T c1_i65;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_w = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_w), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_w);
  for (c1_i65 = 0; c1_i65 < 3; c1_i65++) {
    (*(real_T (*)[3])c1_outData)[c1_i65] = c1_y[c1_i65];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i66;
  real_T c1_b_inData[2];
  int32_T c1_i67;
  real_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i66 = 0; c1_i66 < 2; c1_i66++) {
    c1_b_inData[c1_i66] = (*(real_T (*)[2])c1_inData)[c1_i66];
  }

  for (c1_i67 = 0; c1_i67 < 2; c1_i67++) {
    c1_u[c1_i67] = c1_b_inData[c1_i67];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_j_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv10[2];
  int32_T c1_i68;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv10, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i68 = 0; c1_i68 < 2; c1_i68++) {
    c1_y[c1_i68] = c1_dv10[c1_i68];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_theta;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[2];
  int32_T c1_i69;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_theta = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_theta), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_theta);
  for (c1_i69 = 0; c1_i69 < 2; c1_i69++) {
    (*(real_T (*)[2])c1_outData)[c1_i69] = c1_y[c1_i69];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i70;
  real_T c1_b_inData[4];
  int32_T c1_i71;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i70 = 0; c1_i70 < 4; c1_i70++) {
    c1_b_inData[c1_i70] = (*(real_T (*)[4])c1_inData)[c1_i70];
  }

  for (c1_i71 = 0; c1_i71 < 4; c1_i71++) {
    c1_u[c1_i71] = c1_b_inData[c1_i71];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_k_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv11[4];
  int32_T c1_i72;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv11, 1, 0, 0U, 1, 0U, 1, 4);
  for (c1_i72 = 0; c1_i72 < 4; c1_i72++) {
    c1_y[c1_i72] = c1_dv11[c1_i72];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_d;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i73;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_d = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_d), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_d);
  for (c1_i73 = 0; c1_i73 < 4; c1_i73++) {
    (*(real_T (*)[4])c1_outData)[c1_i73] = c1_y[c1_i73];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_k_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i74;
  boolean_T c1_b_inData[2];
  int32_T c1_i75;
  boolean_T c1_u[2];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i74 = 0; c1_i74 < 2; c1_i74++) {
    c1_b_inData[c1_i74] = (*(boolean_T (*)[2])c1_inData)[c1_i74];
  }

  for (c1_i75 = 0; c1_i75 < 2; c1_i75++) {
    c1_u[c1_i75] = c1_b_inData[c1_i75];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 11, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_l_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[2])
{
  boolean_T c1_bv0[2];
  int32_T c1_i76;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv0, 1, 11, 0U, 1, 0U, 1, 2);
  for (c1_i76 = 0; c1_i76 < 2; c1_i76++) {
    c1_y[c1_i76] = c1_bv0[c1_i76];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_isIn;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y[2];
  int32_T c1_i77;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_isIn = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_isIn), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_isIn);
  for (c1_i77 = 0; c1_i77 < 2; c1_i77++) {
    (*(boolean_T (*)[2])c1_outData)[c1_i77] = c1_y[c1_i77];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_l_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i78;
  int32_T c1_i79;
  int32_T c1_i80;
  real_T c1_b_inData[4];
  int32_T c1_i81;
  int32_T c1_i82;
  int32_T c1_i83;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i78 = 0;
  for (c1_i79 = 0; c1_i79 < 2; c1_i79++) {
    for (c1_i80 = 0; c1_i80 < 2; c1_i80++) {
      c1_b_inData[c1_i80 + c1_i78] = (*(real_T (*)[4])c1_inData)[c1_i80 + c1_i78];
    }

    c1_i78 += 2;
  }

  c1_i81 = 0;
  for (c1_i82 = 0; c1_i82 < 2; c1_i82++) {
    for (c1_i83 = 0; c1_i83 < 2; c1_i83++) {
      c1_u[c1_i83 + c1_i81] = c1_b_inData[c1_i83 + c1_i81];
    }

    c1_i81 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_m_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv12[4];
  int32_T c1_i84;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv12, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c1_i84 = 0; c1_i84 < 4; c1_i84++) {
    c1_y[c1_i84] = c1_dv12[c1_i84];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_A;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i85;
  int32_T c1_i86;
  int32_T c1_i87;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_A = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_A), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_A);
  c1_i85 = 0;
  for (c1_i86 = 0; c1_i86 < 2; c1_i86++) {
    for (c1_i87 = 0; c1_i87 < 2; c1_i87++) {
      (*(real_T (*)[4])c1_outData)[c1_i87 + c1_i85] = c1_y[c1_i87 + c1_i85];
    }

    c1_i85 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray
  *sf_c1_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[209];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i88;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  c1_b_info_helper(c1_info);
  c1_c_info_helper(c1_info);
  c1_d_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 209), FALSE);
  for (c1_i88 = 0; c1_i88 < 209; c1_i88++) {
    c1_r0 = &c1_info[c1_i88];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i88);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i88);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[209])
{
  c1_info[0].context = "";
  c1_info[0].name = "inv_kin";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[0].fileTimeLo = 1367251994U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[1].name = "cross";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c1_info[1].fileTimeLo = 1286797242U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c1_info[2].name = "mtimes";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[2].fileTimeLo = 1289494492U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[3].name = "all";
  c1_info[3].dominantType = "logical";
  c1_info[3].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[3].fileTimeLo = 1286797234U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/all.m";
  c1_info[4].name = "eml_all_or_any";
  c1_info[4].dominantType = "char";
  c1_info[4].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[4].fileTimeLo = 1286797094U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[5].name = "isequal";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[5].fileTimeLo = 1286797158U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isequal.m";
  c1_info[6].name = "eml_isequal_core";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c1_info[6].fileTimeLo = 1286797186U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[7].name = "eml_const_nonsingleton_dim";
  c1_info[7].dominantType = "logical";
  c1_info[7].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c1_info[7].fileTimeLo = 1286797096U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[8].name = "mrdivide";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[8].fileTimeLo = 1325098938U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 1319708366U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[9].name = "mldivide";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[9].fileTimeLo = 1325098938U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 1319708366U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[10].name = "eml_lusolve";
  c1_info[10].dominantType = "double";
  c1_info[10].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c1_info[10].fileTimeLo = 1309429596U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c1_info[11].name = "eml_index_class";
  c1_info[11].dominantType = "";
  c1_info[11].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[11].fileTimeLo = 1286797178U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[12].name = "eml_index_class";
  c1_info[12].dominantType = "";
  c1_info[12].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[12].fileTimeLo = 1286797178U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[13].name = "eml_xgetrf";
  c1_info[13].dominantType = "int32";
  c1_info[13].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[13].fileTimeLo = 1286797206U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[14].name = "eml_lapack_xgetrf";
  c1_info[14].dominantType = "int32";
  c1_info[14].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[14].fileTimeLo = 1286797210U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c1_info[15].name = "eml_matlab_zgetrf";
  c1_info[15].dominantType = "int32";
  c1_info[15].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[15].fileTimeLo = 1302667394U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[16].name = "realmin";
  c1_info[16].dominantType = "char";
  c1_info[16].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[16].fileTimeLo = 1307629642U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[17].name = "eml_realmin";
  c1_info[17].dominantType = "char";
  c1_info[17].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[17].fileTimeLo = 1307629644U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_realmin.m";
  c1_info[18].name = "eml_float_model";
  c1_info[18].dominantType = "char";
  c1_info[18].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[18].fileTimeLo = 1307629642U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[19].name = "eps";
  c1_info[19].dominantType = "char";
  c1_info[19].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[19].fileTimeLo = 1307629640U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[20].name = "eml_is_float_class";
  c1_info[20].dominantType = "char";
  c1_info[20].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[20].fileTimeLo = 1286797182U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[21].name = "eml_eps";
  c1_info[21].dominantType = "char";
  c1_info[21].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[21].fileTimeLo = 1307629640U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[22].name = "eml_float_model";
  c1_info[22].dominantType = "char";
  c1_info[22].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[22].fileTimeLo = 1307629642U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[23].name = "min";
  c1_info[23].dominantType = "int32";
  c1_info[23].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[23].fileTimeLo = 1311233718U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[24].name = "eml_min_or_max";
  c1_info[24].dominantType = "int32";
  c1_info[24].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[24].fileTimeLo = 1303124612U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[25].name = "eml_scalar_eg";
  c1_info[25].dominantType = "int32";
  c1_info[25].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[25].fileTimeLo = 1286797196U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
  c1_info[26].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[26].name = "eml_scalexp_alloc";
  c1_info[26].dominantType = "int32";
  c1_info[26].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[26].fileTimeLo = 1286797196U;
  c1_info[26].fileTimeHi = 0U;
  c1_info[26].mFileTimeLo = 0U;
  c1_info[26].mFileTimeHi = 0U;
  c1_info[27].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[27].name = "eml_index_class";
  c1_info[27].dominantType = "";
  c1_info[27].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[27].fileTimeLo = 1286797178U;
  c1_info[27].fileTimeHi = 0U;
  c1_info[27].mFileTimeLo = 0U;
  c1_info[27].mFileTimeHi = 0U;
  c1_info[28].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[28].name = "eml_scalar_eg";
  c1_info[28].dominantType = "int32";
  c1_info[28].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[28].fileTimeLo = 1286797196U;
  c1_info[28].fileTimeHi = 0U;
  c1_info[28].mFileTimeLo = 0U;
  c1_info[28].mFileTimeHi = 0U;
  c1_info[29].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[29].name = "colon";
  c1_info[29].dominantType = "int32";
  c1_info[29].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[29].fileTimeLo = 1311233718U;
  c1_info[29].fileTimeHi = 0U;
  c1_info[29].mFileTimeLo = 0U;
  c1_info[29].mFileTimeHi = 0U;
  c1_info[30].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[30].name = "colon";
  c1_info[30].dominantType = "int32";
  c1_info[30].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[30].fileTimeLo = 1311233718U;
  c1_info[30].fileTimeHi = 0U;
  c1_info[30].mFileTimeLo = 0U;
  c1_info[30].mFileTimeHi = 0U;
  c1_info[31].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m";
  c1_info[31].name = "floor";
  c1_info[31].dominantType = "double";
  c1_info[31].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[31].fileTimeLo = 1286797142U;
  c1_info[31].fileTimeHi = 0U;
  c1_info[31].mFileTimeLo = 0U;
  c1_info[31].mFileTimeHi = 0U;
  c1_info[32].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/floor.m";
  c1_info[32].name = "eml_scalar_floor";
  c1_info[32].dominantType = "double";
  c1_info[32].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[32].fileTimeLo = 1286797126U;
  c1_info[32].fileTimeHi = 0U;
  c1_info[32].mFileTimeLo = 0U;
  c1_info[32].mFileTimeHi = 0U;
  c1_info[33].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[33].name = "intmin";
  c1_info[33].dominantType = "char";
  c1_info[33].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[33].fileTimeLo = 1311233718U;
  c1_info[33].fileTimeHi = 0U;
  c1_info[33].mFileTimeLo = 0U;
  c1_info[33].mFileTimeHi = 0U;
  c1_info[34].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c1_info[34].name = "intmax";
  c1_info[34].dominantType = "char";
  c1_info[34].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[34].fileTimeLo = 1311233716U;
  c1_info[34].fileTimeHi = 0U;
  c1_info[34].mFileTimeLo = 0U;
  c1_info[34].mFileTimeHi = 0U;
  c1_info[35].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[35].name = "intmin";
  c1_info[35].dominantType = "char";
  c1_info[35].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[35].fileTimeLo = 1311233718U;
  c1_info[35].fileTimeHi = 0U;
  c1_info[35].mFileTimeLo = 0U;
  c1_info[35].mFileTimeHi = 0U;
  c1_info[36].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[36].name = "intmax";
  c1_info[36].dominantType = "char";
  c1_info[36].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[36].fileTimeLo = 1311233716U;
  c1_info[36].fileTimeHi = 0U;
  c1_info[36].mFileTimeLo = 0U;
  c1_info[36].mFileTimeHi = 0U;
  c1_info[37].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher";
  c1_info[37].name = "eml_isa_uint";
  c1_info[37].dominantType = "int32";
  c1_info[37].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[37].fileTimeLo = 1286797184U;
  c1_info[37].fileTimeHi = 0U;
  c1_info[37].mFileTimeLo = 0U;
  c1_info[37].mFileTimeHi = 0U;
  c1_info[38].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[38].name = "eml_unsigned_class";
  c1_info[38].dominantType = "char";
  c1_info[38].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c1_info[38].fileTimeLo = 1286797200U;
  c1_info[38].fileTimeHi = 0U;
  c1_info[38].mFileTimeLo = 0U;
  c1_info[38].mFileTimeHi = 0U;
  c1_info[39].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[39].name = "eml_index_class";
  c1_info[39].dominantType = "";
  c1_info[39].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[39].fileTimeLo = 1286797178U;
  c1_info[39].fileTimeHi = 0U;
  c1_info[39].mFileTimeLo = 0U;
  c1_info[39].mFileTimeHi = 0U;
  c1_info[40].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[40].name = "intmax";
  c1_info[40].dominantType = "char";
  c1_info[40].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[40].fileTimeLo = 1311233716U;
  c1_info[40].fileTimeHi = 0U;
  c1_info[40].mFileTimeLo = 0U;
  c1_info[40].mFileTimeHi = 0U;
  c1_info[41].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[41].name = "eml_isa_uint";
  c1_info[41].dominantType = "int32";
  c1_info[41].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_isa_uint.m";
  c1_info[41].fileTimeLo = 1286797184U;
  c1_info[41].fileTimeHi = 0U;
  c1_info[41].mFileTimeLo = 0U;
  c1_info[41].mFileTimeHi = 0U;
  c1_info[42].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd";
  c1_info[42].name = "eml_index_plus";
  c1_info[42].dominantType = "int32";
  c1_info[42].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[42].fileTimeLo = 1286797178U;
  c1_info[42].fileTimeHi = 0U;
  c1_info[42].mFileTimeLo = 0U;
  c1_info[42].mFileTimeHi = 0U;
  c1_info[43].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[43].name = "eml_index_class";
  c1_info[43].dominantType = "";
  c1_info[43].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[43].fileTimeLo = 1286797178U;
  c1_info[43].fileTimeHi = 0U;
  c1_info[43].mFileTimeLo = 0U;
  c1_info[43].mFileTimeHi = 0U;
  c1_info[44].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon";
  c1_info[44].name = "eml_int_forloop_overflow_check";
  c1_info[44].dominantType = "";
  c1_info[44].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[44].fileTimeLo = 1311233716U;
  c1_info[44].fileTimeHi = 0U;
  c1_info[44].mFileTimeLo = 0U;
  c1_info[44].mFileTimeHi = 0U;
  c1_info[45].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[45].name = "intmax";
  c1_info[45].dominantType = "char";
  c1_info[45].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[45].fileTimeLo = 1311233716U;
  c1_info[45].fileTimeHi = 0U;
  c1_info[45].mFileTimeLo = 0U;
  c1_info[45].mFileTimeHi = 0U;
  c1_info[46].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[46].name = "eml_index_class";
  c1_info[46].dominantType = "";
  c1_info[46].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[46].fileTimeLo = 1286797178U;
  c1_info[46].fileTimeHi = 0U;
  c1_info[46].mFileTimeLo = 0U;
  c1_info[46].mFileTimeHi = 0U;
  c1_info[47].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[47].name = "eml_index_plus";
  c1_info[47].dominantType = "int32";
  c1_info[47].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[47].fileTimeLo = 1286797178U;
  c1_info[47].fileTimeHi = 0U;
  c1_info[47].mFileTimeLo = 0U;
  c1_info[47].mFileTimeHi = 0U;
  c1_info[48].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[48].name = "eml_int_forloop_overflow_check";
  c1_info[48].dominantType = "";
  c1_info[48].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[48].fileTimeLo = 1311233716U;
  c1_info[48].fileTimeHi = 0U;
  c1_info[48].mFileTimeLo = 0U;
  c1_info[48].mFileTimeHi = 0U;
  c1_info[49].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[49].name = "eml_index_minus";
  c1_info[49].dominantType = "int32";
  c1_info[49].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[49].fileTimeLo = 1286797178U;
  c1_info[49].fileTimeHi = 0U;
  c1_info[49].mFileTimeLo = 0U;
  c1_info[49].mFileTimeHi = 0U;
  c1_info[50].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[50].name = "eml_index_class";
  c1_info[50].dominantType = "";
  c1_info[50].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[50].fileTimeLo = 1286797178U;
  c1_info[50].fileTimeHi = 0U;
  c1_info[50].mFileTimeLo = 0U;
  c1_info[50].mFileTimeHi = 0U;
  c1_info[51].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[51].name = "eml_index_times";
  c1_info[51].dominantType = "int32";
  c1_info[51].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[51].fileTimeLo = 1286797180U;
  c1_info[51].fileTimeHi = 0U;
  c1_info[51].mFileTimeLo = 0U;
  c1_info[51].mFileTimeHi = 0U;
  c1_info[52].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[52].name = "eml_index_class";
  c1_info[52].dominantType = "";
  c1_info[52].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[52].fileTimeLo = 1286797178U;
  c1_info[52].fileTimeHi = 0U;
  c1_info[52].mFileTimeLo = 0U;
  c1_info[52].mFileTimeHi = 0U;
  c1_info[53].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[53].name = "eml_ixamax";
  c1_info[53].dominantType = "int32";
  c1_info[53].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[53].fileTimeLo = 1299051570U;
  c1_info[53].fileTimeHi = 0U;
  c1_info[53].mFileTimeLo = 0U;
  c1_info[53].mFileTimeHi = 0U;
  c1_info[54].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c1_info[54].name = "eml_blas_inline";
  c1_info[54].dominantType = "";
  c1_info[54].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[54].fileTimeLo = 1299051568U;
  c1_info[54].fileTimeHi = 0U;
  c1_info[54].mFileTimeLo = 0U;
  c1_info[54].mFileTimeHi = 0U;
  c1_info[55].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c1_info[55].name = "length";
  c1_info[55].dominantType = "double";
  c1_info[55].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[55].fileTimeLo = 1303124606U;
  c1_info[55].fileTimeHi = 0U;
  c1_info[55].mFileTimeLo = 0U;
  c1_info[55].mFileTimeHi = 0U;
  c1_info[56].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m!intlength";
  c1_info[56].name = "eml_index_class";
  c1_info[56].dominantType = "";
  c1_info[56].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[56].fileTimeLo = 1286797178U;
  c1_info[56].fileTimeHi = 0U;
  c1_info[56].mFileTimeLo = 0U;
  c1_info[56].mFileTimeHi = 0U;
  c1_info[57].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c1_info[57].name = "eml_refblas_ixamax";
  c1_info[57].dominantType = "int32";
  c1_info[57].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[57].fileTimeLo = 1299051570U;
  c1_info[57].fileTimeHi = 0U;
  c1_info[57].mFileTimeLo = 0U;
  c1_info[57].mFileTimeHi = 0U;
  c1_info[58].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[58].name = "eml_index_class";
  c1_info[58].dominantType = "";
  c1_info[58].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[58].fileTimeLo = 1286797178U;
  c1_info[58].fileTimeHi = 0U;
  c1_info[58].mFileTimeLo = 0U;
  c1_info[58].mFileTimeHi = 0U;
  c1_info[59].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[59].name = "eml_xcabs1";
  c1_info[59].dominantType = "double";
  c1_info[59].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[59].fileTimeLo = 1286797106U;
  c1_info[59].fileTimeHi = 0U;
  c1_info[59].mFileTimeLo = 0U;
  c1_info[59].mFileTimeHi = 0U;
  c1_info[60].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[60].name = "abs";
  c1_info[60].dominantType = "double";
  c1_info[60].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[60].fileTimeLo = 1286797094U;
  c1_info[60].fileTimeHi = 0U;
  c1_info[60].mFileTimeLo = 0U;
  c1_info[60].mFileTimeHi = 0U;
  c1_info[61].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[61].name = "eml_scalar_abs";
  c1_info[61].dominantType = "double";
  c1_info[61].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[61].fileTimeLo = 1286797112U;
  c1_info[61].fileTimeHi = 0U;
  c1_info[61].mFileTimeLo = 0U;
  c1_info[61].mFileTimeHi = 0U;
  c1_info[62].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[62].name = "eml_int_forloop_overflow_check";
  c1_info[62].dominantType = "";
  c1_info[62].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[62].fileTimeLo = 1311233716U;
  c1_info[62].fileTimeHi = 0U;
  c1_info[62].mFileTimeLo = 0U;
  c1_info[62].mFileTimeHi = 0U;
  c1_info[63].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c1_info[63].name = "eml_index_plus";
  c1_info[63].dominantType = "int32";
  c1_info[63].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[63].fileTimeLo = 1286797178U;
  c1_info[63].fileTimeHi = 0U;
  c1_info[63].mFileTimeLo = 0U;
  c1_info[63].mFileTimeHi = 0U;
}

static void c1_b_info_helper(c1_ResolvedFunctionInfo c1_info[209])
{
  c1_info[64].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[64].name = "eml_xswap";
  c1_info[64].dominantType = "int32";
  c1_info[64].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[64].fileTimeLo = 1299051578U;
  c1_info[64].fileTimeHi = 0U;
  c1_info[64].mFileTimeLo = 0U;
  c1_info[64].mFileTimeHi = 0U;
  c1_info[65].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c1_info[65].name = "eml_blas_inline";
  c1_info[65].dominantType = "";
  c1_info[65].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[65].fileTimeLo = 1299051568U;
  c1_info[65].fileTimeHi = 0U;
  c1_info[65].mFileTimeLo = 0U;
  c1_info[65].mFileTimeHi = 0U;
  c1_info[66].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c1_info[66].name = "eml_refblas_xswap";
  c1_info[66].dominantType = "int32";
  c1_info[66].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[66].fileTimeLo = 1299051586U;
  c1_info[66].fileTimeHi = 0U;
  c1_info[66].mFileTimeLo = 0U;
  c1_info[66].mFileTimeHi = 0U;
  c1_info[67].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[67].name = "eml_index_class";
  c1_info[67].dominantType = "";
  c1_info[67].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[67].fileTimeLo = 1286797178U;
  c1_info[67].fileTimeHi = 0U;
  c1_info[67].mFileTimeLo = 0U;
  c1_info[67].mFileTimeHi = 0U;
  c1_info[68].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[68].name = "abs";
  c1_info[68].dominantType = "int32";
  c1_info[68].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[68].fileTimeLo = 1286797094U;
  c1_info[68].fileTimeHi = 0U;
  c1_info[68].mFileTimeLo = 0U;
  c1_info[68].mFileTimeHi = 0U;
  c1_info[69].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[69].name = "eml_scalar_abs";
  c1_info[69].dominantType = "int32";
  c1_info[69].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[69].fileTimeLo = 1286797112U;
  c1_info[69].fileTimeHi = 0U;
  c1_info[69].mFileTimeLo = 0U;
  c1_info[69].mFileTimeHi = 0U;
  c1_info[70].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[70].name = "eml_int_forloop_overflow_check";
  c1_info[70].dominantType = "";
  c1_info[70].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[70].fileTimeLo = 1311233716U;
  c1_info[70].fileTimeHi = 0U;
  c1_info[70].mFileTimeLo = 0U;
  c1_info[70].mFileTimeHi = 0U;
  c1_info[71].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c1_info[71].name = "eml_index_plus";
  c1_info[71].dominantType = "int32";
  c1_info[71].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[71].fileTimeLo = 1286797178U;
  c1_info[71].fileTimeHi = 0U;
  c1_info[71].mFileTimeLo = 0U;
  c1_info[71].mFileTimeHi = 0U;
  c1_info[72].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[72].name = "eml_div";
  c1_info[72].dominantType = "double";
  c1_info[72].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[72].fileTimeLo = 1313326210U;
  c1_info[72].fileTimeHi = 0U;
  c1_info[72].mFileTimeLo = 0U;
  c1_info[72].mFileTimeHi = 0U;
  c1_info[73].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c1_info[73].name = "eml_xgeru";
  c1_info[73].dominantType = "int32";
  c1_info[73].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[73].fileTimeLo = 1299051574U;
  c1_info[73].fileTimeHi = 0U;
  c1_info[73].mFileTimeLo = 0U;
  c1_info[73].mFileTimeHi = 0U;
  c1_info[74].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[74].name = "eml_blas_inline";
  c1_info[74].dominantType = "";
  c1_info[74].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[74].fileTimeLo = 1299051568U;
  c1_info[74].fileTimeHi = 0U;
  c1_info[74].mFileTimeLo = 0U;
  c1_info[74].mFileTimeHi = 0U;
  c1_info[75].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c1_info[75].name = "eml_xger";
  c1_info[75].dominantType = "int32";
  c1_info[75].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[75].fileTimeLo = 1299051574U;
  c1_info[75].fileTimeHi = 0U;
  c1_info[75].mFileTimeLo = 0U;
  c1_info[75].mFileTimeHi = 0U;
  c1_info[76].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c1_info[76].name = "eml_blas_inline";
  c1_info[76].dominantType = "";
  c1_info[76].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[76].fileTimeLo = 1299051568U;
  c1_info[76].fileTimeHi = 0U;
  c1_info[76].mFileTimeLo = 0U;
  c1_info[76].mFileTimeHi = 0U;
  c1_info[77].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[77].name = "intmax";
  c1_info[77].dominantType = "char";
  c1_info[77].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[77].fileTimeLo = 1311233716U;
  c1_info[77].fileTimeHi = 0U;
  c1_info[77].mFileTimeLo = 0U;
  c1_info[77].mFileTimeHi = 0U;
  c1_info[78].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[78].name = "min";
  c1_info[78].dominantType = "double";
  c1_info[78].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[78].fileTimeLo = 1311233718U;
  c1_info[78].fileTimeHi = 0U;
  c1_info[78].mFileTimeLo = 0U;
  c1_info[78].mFileTimeHi = 0U;
  c1_info[79].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[79].name = "eml_min_or_max";
  c1_info[79].dominantType = "char";
  c1_info[79].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c1_info[79].fileTimeLo = 1303124612U;
  c1_info[79].fileTimeHi = 0U;
  c1_info[79].mFileTimeLo = 0U;
  c1_info[79].mFileTimeHi = 0U;
  c1_info[80].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[80].name = "eml_scalar_eg";
  c1_info[80].dominantType = "double";
  c1_info[80].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[80].fileTimeLo = 1286797196U;
  c1_info[80].fileTimeHi = 0U;
  c1_info[80].mFileTimeLo = 0U;
  c1_info[80].mFileTimeHi = 0U;
  c1_info[81].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c1_info[81].name = "eml_scalexp_alloc";
  c1_info[81].dominantType = "double";
  c1_info[81].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[81].fileTimeLo = 1286797196U;
  c1_info[81].fileTimeHi = 0U;
  c1_info[81].mFileTimeLo = 0U;
  c1_info[81].mFileTimeHi = 0U;
  c1_info[82].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c1_info[82].name = "eml_scalar_eg";
  c1_info[82].dominantType = "double";
  c1_info[82].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[82].fileTimeLo = 1286797196U;
  c1_info[82].fileTimeHi = 0U;
  c1_info[82].mFileTimeLo = 0U;
  c1_info[82].mFileTimeHi = 0U;
  c1_info[83].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m!below_threshold";
  c1_info[83].name = "mtimes";
  c1_info[83].dominantType = "double";
  c1_info[83].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[83].fileTimeLo = 1289494492U;
  c1_info[83].fileTimeHi = 0U;
  c1_info[83].mFileTimeLo = 0U;
  c1_info[83].mFileTimeHi = 0U;
  c1_info[84].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c1_info[84].name = "eml_refblas_xger";
  c1_info[84].dominantType = "int32";
  c1_info[84].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[84].fileTimeLo = 1299051576U;
  c1_info[84].fileTimeHi = 0U;
  c1_info[84].mFileTimeLo = 0U;
  c1_info[84].mFileTimeHi = 0U;
  c1_info[85].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c1_info[85].name = "eml_refblas_xgerx";
  c1_info[85].dominantType = "int32";
  c1_info[85].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[85].fileTimeLo = 1299051578U;
  c1_info[85].fileTimeHi = 0U;
  c1_info[85].mFileTimeLo = 0U;
  c1_info[85].mFileTimeHi = 0U;
  c1_info[86].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[86].name = "eml_index_class";
  c1_info[86].dominantType = "";
  c1_info[86].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[86].fileTimeLo = 1286797178U;
  c1_info[86].fileTimeHi = 0U;
  c1_info[86].mFileTimeLo = 0U;
  c1_info[86].mFileTimeHi = 0U;
  c1_info[87].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[87].name = "abs";
  c1_info[87].dominantType = "int32";
  c1_info[87].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[87].fileTimeLo = 1286797094U;
  c1_info[87].fileTimeHi = 0U;
  c1_info[87].mFileTimeLo = 0U;
  c1_info[87].mFileTimeHi = 0U;
  c1_info[88].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[88].name = "eml_index_minus";
  c1_info[88].dominantType = "int32";
  c1_info[88].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[88].fileTimeLo = 1286797178U;
  c1_info[88].fileTimeHi = 0U;
  c1_info[88].mFileTimeLo = 0U;
  c1_info[88].mFileTimeHi = 0U;
  c1_info[89].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[89].name = "eml_int_forloop_overflow_check";
  c1_info[89].dominantType = "";
  c1_info[89].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[89].fileTimeLo = 1311233716U;
  c1_info[89].fileTimeHi = 0U;
  c1_info[89].mFileTimeLo = 0U;
  c1_info[89].mFileTimeHi = 0U;
  c1_info[90].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c1_info[90].name = "eml_index_plus";
  c1_info[90].dominantType = "int32";
  c1_info[90].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[90].fileTimeLo = 1286797178U;
  c1_info[90].fileTimeHi = 0U;
  c1_info[90].mFileTimeLo = 0U;
  c1_info[90].mFileTimeHi = 0U;
  c1_info[91].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c1_info[91].name = "eml_warning";
  c1_info[91].dominantType = "char";
  c1_info[91].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c1_info[91].fileTimeLo = 1286797202U;
  c1_info[91].fileTimeHi = 0U;
  c1_info[91].mFileTimeLo = 0U;
  c1_info[91].mFileTimeHi = 0U;
  c1_info[92].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[92].name = "eml_scalar_eg";
  c1_info[92].dominantType = "double";
  c1_info[92].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[92].fileTimeLo = 1286797196U;
  c1_info[92].fileTimeHi = 0U;
  c1_info[92].mFileTimeLo = 0U;
  c1_info[92].mFileTimeHi = 0U;
  c1_info[93].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[93].name = "eml_int_forloop_overflow_check";
  c1_info[93].dominantType = "";
  c1_info[93].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[93].fileTimeLo = 1311233716U;
  c1_info[93].fileTimeHi = 0U;
  c1_info[93].mFileTimeLo = 0U;
  c1_info[93].mFileTimeHi = 0U;
  c1_info[94].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c1_info[94].name = "eml_xtrsm";
  c1_info[94].dominantType = "int32";
  c1_info[94].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[94].fileTimeLo = 1299051578U;
  c1_info[94].fileTimeHi = 0U;
  c1_info[94].mFileTimeLo = 0U;
  c1_info[94].mFileTimeHi = 0U;
  c1_info[95].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c1_info[95].name = "eml_blas_inline";
  c1_info[95].dominantType = "";
  c1_info[95].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[95].fileTimeLo = 1299051568U;
  c1_info[95].fileTimeHi = 0U;
  c1_info[95].mFileTimeLo = 0U;
  c1_info[95].mFileTimeHi = 0U;
  c1_info[96].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m!below_threshold";
  c1_info[96].name = "mtimes";
  c1_info[96].dominantType = "double";
  c1_info[96].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[96].fileTimeLo = 1289494492U;
  c1_info[96].fileTimeHi = 0U;
  c1_info[96].mFileTimeLo = 0U;
  c1_info[96].mFileTimeHi = 0U;
  c1_info[97].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[97].name = "eml_scalar_eg";
  c1_info[97].dominantType = "double";
  c1_info[97].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[97].fileTimeLo = 1286797196U;
  c1_info[97].fileTimeHi = 0U;
  c1_info[97].mFileTimeLo = 0U;
  c1_info[97].mFileTimeHi = 0U;
  c1_info[98].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c1_info[98].name = "eml_refblas_xtrsm";
  c1_info[98].dominantType = "int32";
  c1_info[98].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[98].fileTimeLo = 1299051586U;
  c1_info[98].fileTimeHi = 0U;
  c1_info[98].mFileTimeLo = 0U;
  c1_info[98].mFileTimeHi = 0U;
  c1_info[99].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[99].name = "eml_scalar_eg";
  c1_info[99].dominantType = "double";
  c1_info[99].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[99].fileTimeLo = 1286797196U;
  c1_info[99].fileTimeHi = 0U;
  c1_info[99].mFileTimeLo = 0U;
  c1_info[99].mFileTimeHi = 0U;
  c1_info[100].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[100].name = "eml_index_minus";
  c1_info[100].dominantType = "int32";
  c1_info[100].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[100].fileTimeLo = 1286797178U;
  c1_info[100].fileTimeHi = 0U;
  c1_info[100].mFileTimeLo = 0U;
  c1_info[100].mFileTimeHi = 0U;
  c1_info[101].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[101].name = "eml_index_class";
  c1_info[101].dominantType = "";
  c1_info[101].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[101].fileTimeLo = 1286797178U;
  c1_info[101].fileTimeHi = 0U;
  c1_info[101].mFileTimeLo = 0U;
  c1_info[101].mFileTimeHi = 0U;
  c1_info[102].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[102].name = "eml_int_forloop_overflow_check";
  c1_info[102].dominantType = "";
  c1_info[102].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[102].fileTimeLo = 1311233716U;
  c1_info[102].fileTimeHi = 0U;
  c1_info[102].mFileTimeLo = 0U;
  c1_info[102].mFileTimeHi = 0U;
  c1_info[103].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[103].name = "eml_index_times";
  c1_info[103].dominantType = "int32";
  c1_info[103].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[103].fileTimeLo = 1286797180U;
  c1_info[103].fileTimeHi = 0U;
  c1_info[103].mFileTimeLo = 0U;
  c1_info[103].mFileTimeHi = 0U;
  c1_info[104].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[104].name = "eml_index_plus";
  c1_info[104].dominantType = "int32";
  c1_info[104].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[104].fileTimeLo = 1286797178U;
  c1_info[104].fileTimeHi = 0U;
  c1_info[104].mFileTimeLo = 0U;
  c1_info[104].mFileTimeHi = 0U;
  c1_info[105].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[105].name = "intmin";
  c1_info[105].dominantType = "char";
  c1_info[105].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmin.m";
  c1_info[105].fileTimeLo = 1311233718U;
  c1_info[105].fileTimeHi = 0U;
  c1_info[105].mFileTimeLo = 0U;
  c1_info[105].mFileTimeHi = 0U;
  c1_info[106].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c1_info[106].name = "eml_div";
  c1_info[106].dominantType = "double";
  c1_info[106].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[106].fileTimeLo = 1313326210U;
  c1_info[106].fileTimeHi = 0U;
  c1_info[106].mFileTimeLo = 0U;
  c1_info[106].mFileTimeHi = 0U;
  c1_info[107].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[107].name = "mtimes";
  c1_info[107].dominantType = "double";
  c1_info[107].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[107].fileTimeLo = 1289494492U;
  c1_info[107].fileTimeHi = 0U;
  c1_info[107].mFileTimeLo = 0U;
  c1_info[107].mFileTimeHi = 0U;
  c1_info[108].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[108].name = "eml_index_class";
  c1_info[108].dominantType = "";
  c1_info[108].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[108].fileTimeLo = 1286797178U;
  c1_info[108].fileTimeHi = 0U;
  c1_info[108].mFileTimeLo = 0U;
  c1_info[108].mFileTimeHi = 0U;
  c1_info[109].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[109].name = "eml_scalar_eg";
  c1_info[109].dominantType = "double";
  c1_info[109].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[109].fileTimeLo = 1286797196U;
  c1_info[109].fileTimeHi = 0U;
  c1_info[109].mFileTimeLo = 0U;
  c1_info[109].mFileTimeHi = 0U;
  c1_info[110].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[110].name = "eml_xgemm";
  c1_info[110].dominantType = "int32";
  c1_info[110].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[110].fileTimeLo = 1299051572U;
  c1_info[110].fileTimeHi = 0U;
  c1_info[110].mFileTimeLo = 0U;
  c1_info[110].mFileTimeHi = 0U;
  c1_info[111].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c1_info[111].name = "eml_blas_inline";
  c1_info[111].dominantType = "";
  c1_info[111].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[111].fileTimeLo = 1299051568U;
  c1_info[111].fileTimeHi = 0U;
  c1_info[111].mFileTimeLo = 0U;
  c1_info[111].mFileTimeHi = 0U;
  c1_info[112].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c1_info[112].name = "mtimes";
  c1_info[112].dominantType = "double";
  c1_info[112].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[112].fileTimeLo = 1289494492U;
  c1_info[112].fileTimeHi = 0U;
  c1_info[112].mFileTimeLo = 0U;
  c1_info[112].mFileTimeHi = 0U;
  c1_info[113].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[113].name = "eml_scalar_eg";
  c1_info[113].dominantType = "double";
  c1_info[113].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[113].fileTimeLo = 1286797196U;
  c1_info[113].fileTimeHi = 0U;
  c1_info[113].mFileTimeLo = 0U;
  c1_info[113].mFileTimeHi = 0U;
  c1_info[114].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c1_info[114].name = "eml_refblas_xgemm";
  c1_info[114].dominantType = "int32";
  c1_info[114].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c1_info[114].fileTimeLo = 1299051574U;
  c1_info[114].fileTimeHi = 0U;
  c1_info[114].mFileTimeLo = 0U;
  c1_info[114].mFileTimeHi = 0U;
  c1_info[115].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[115].name = "atan2";
  c1_info[115].dominantType = "double";
  c1_info[115].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[115].fileTimeLo = 1286797104U;
  c1_info[115].fileTimeHi = 0U;
  c1_info[115].mFileTimeLo = 0U;
  c1_info[115].mFileTimeHi = 0U;
  c1_info[116].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[116].name = "eml_scalar_eg";
  c1_info[116].dominantType = "double";
  c1_info[116].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[116].fileTimeLo = 1286797196U;
  c1_info[116].fileTimeHi = 0U;
  c1_info[116].mFileTimeLo = 0U;
  c1_info[116].mFileTimeHi = 0U;
  c1_info[117].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[117].name = "eml_scalexp_alloc";
  c1_info[117].dominantType = "double";
  c1_info[117].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[117].fileTimeLo = 1286797196U;
  c1_info[117].fileTimeHi = 0U;
  c1_info[117].mFileTimeLo = 0U;
  c1_info[117].mFileTimeHi = 0U;
  c1_info[118].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[118].name = "eml_scalar_atan2";
  c1_info[118].dominantType = "double";
  c1_info[118].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m";
  c1_info[118].fileTimeLo = 1286797120U;
  c1_info[118].fileTimeHi = 0U;
  c1_info[118].mFileTimeLo = 0U;
  c1_info[118].mFileTimeHi = 0U;
  c1_info[119].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m!isInRange";
  c1_info[119].name = "mrdivide";
  c1_info[119].dominantType = "double";
  c1_info[119].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[119].fileTimeLo = 1325098938U;
  c1_info[119].fileTimeHi = 0U;
  c1_info[119].mFileTimeLo = 1319708366U;
  c1_info[119].mFileTimeHi = 0U;
  c1_info[120].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[120].name = "rdivide";
  c1_info[120].dominantType = "double";
  c1_info[120].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[120].fileTimeLo = 1286797244U;
  c1_info[120].fileTimeHi = 0U;
  c1_info[120].mFileTimeLo = 0U;
  c1_info[120].mFileTimeHi = 0U;
  c1_info[121].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[121].name = "eml_div";
  c1_info[121].dominantType = "double";
  c1_info[121].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[121].fileTimeLo = 1313326210U;
  c1_info[121].fileTimeHi = 0U;
  c1_info[121].mFileTimeLo = 0U;
  c1_info[121].mFileTimeHi = 0U;
  c1_info[122].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m!isInRange";
  c1_info[122].name = "mtimes";
  c1_info[122].dominantType = "double";
  c1_info[122].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[122].fileTimeLo = 1289494492U;
  c1_info[122].fileTimeHi = 0U;
  c1_info[122].mFileTimeLo = 0U;
  c1_info[122].mFileTimeHi = 0U;
  c1_info[123].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[123].name = "expWre";
  c1_info[123].dominantType = "double";
  c1_info[123].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expWre.m";
  c1_info[123].fileTimeLo = 1366220274U;
  c1_info[123].fileTimeHi = 0U;
  c1_info[123].mFileTimeLo = 0U;
  c1_info[123].mFileTimeHi = 0U;
  c1_info[124].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expWre.m";
  c1_info[124].name = "length";
  c1_info[124].dominantType = "double";
  c1_info[124].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[124].fileTimeLo = 1303124606U;
  c1_info[124].fileTimeHi = 0U;
  c1_info[124].mFileTimeLo = 0U;
  c1_info[124].mFileTimeHi = 0U;
  c1_info[125].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expWre.m";
  c1_info[125].name = "eye";
  c1_info[125].dominantType = "double";
  c1_info[125].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m";
  c1_info[125].fileTimeLo = 1286797088U;
  c1_info[125].fileTimeHi = 0U;
  c1_info[125].mFileTimeLo = 0U;
  c1_info[125].mFileTimeHi = 0U;
  c1_info[126].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[126].name = "eml_assert_valid_size_arg";
  c1_info[126].dominantType = "double";
  c1_info[126].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[126].fileTimeLo = 1286797094U;
  c1_info[126].fileTimeHi = 0U;
  c1_info[126].mFileTimeLo = 0U;
  c1_info[126].mFileTimeHi = 0U;
  c1_info[127].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c1_info[127].name = "isinf";
  c1_info[127].dominantType = "double";
  c1_info[127].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isinf.m";
  c1_info[127].fileTimeLo = 1286797160U;
  c1_info[127].fileTimeHi = 0U;
  c1_info[127].mFileTimeLo = 0U;
  c1_info[127].mFileTimeHi = 0U;
}

static void c1_c_info_helper(c1_ResolvedFunctionInfo c1_info[209])
{
  c1_info[128].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c1_info[128].name = "mtimes";
  c1_info[128].dominantType = "double";
  c1_info[128].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[128].fileTimeLo = 1289494492U;
  c1_info[128].fileTimeHi = 0U;
  c1_info[128].mFileTimeLo = 0U;
  c1_info[128].mFileTimeHi = 0U;
  c1_info[129].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[129].name = "eml_index_class";
  c1_info[129].dominantType = "";
  c1_info[129].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[129].fileTimeLo = 1286797178U;
  c1_info[129].fileTimeHi = 0U;
  c1_info[129].mFileTimeLo = 0U;
  c1_info[129].mFileTimeHi = 0U;
  c1_info[130].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c1_info[130].name = "intmax";
  c1_info[130].dominantType = "char";
  c1_info[130].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[130].fileTimeLo = 1311233716U;
  c1_info[130].fileTimeHi = 0U;
  c1_info[130].mFileTimeLo = 0U;
  c1_info[130].mFileTimeHi = 0U;
  c1_info[131].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[131].name = "eml_is_float_class";
  c1_info[131].dominantType = "char";
  c1_info[131].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[131].fileTimeLo = 1286797182U;
  c1_info[131].fileTimeHi = 0U;
  c1_info[131].mFileTimeLo = 0U;
  c1_info[131].mFileTimeHi = 0U;
  c1_info[132].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[132].name = "min";
  c1_info[132].dominantType = "double";
  c1_info[132].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/datafun/min.m";
  c1_info[132].fileTimeLo = 1311233718U;
  c1_info[132].fileTimeHi = 0U;
  c1_info[132].mFileTimeLo = 0U;
  c1_info[132].mFileTimeHi = 0U;
  c1_info[133].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[133].name = "eml_index_class";
  c1_info[133].dominantType = "";
  c1_info[133].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[133].fileTimeLo = 1286797178U;
  c1_info[133].fileTimeHi = 0U;
  c1_info[133].mFileTimeLo = 0U;
  c1_info[133].mFileTimeHi = 0U;
  c1_info[134].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c1_info[134].name = "eml_int_forloop_overflow_check";
  c1_info[134].dominantType = "";
  c1_info[134].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[134].fileTimeLo = 1311233716U;
  c1_info[134].fileTimeHi = 0U;
  c1_info[134].mFileTimeLo = 0U;
  c1_info[134].mFileTimeHi = 0U;
  c1_info[135].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expWre.m";
  c1_info[135].name = "mtimes";
  c1_info[135].dominantType = "double";
  c1_info[135].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[135].fileTimeLo = 1289494492U;
  c1_info[135].fileTimeHi = 0U;
  c1_info[135].mFileTimeLo = 0U;
  c1_info[135].mFileTimeHi = 0U;
  c1_info[136].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expWre.m";
  c1_info[136].name = "expRot";
  c1_info[136].dominantType = "double";
  c1_info[136].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expRot.m";
  c1_info[136].fileTimeLo = 1366773054U;
  c1_info[136].fileTimeHi = 0U;
  c1_info[136].mFileTimeLo = 0U;
  c1_info[136].mFileTimeHi = 0U;
  c1_info[137].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expRot.m";
  c1_info[137].name = "skew";
  c1_info[137].dominantType = "double";
  c1_info[137].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/skew.m";
  c1_info[137].fileTimeLo = 1399884446U;
  c1_info[137].fileTimeHi = 0U;
  c1_info[137].mFileTimeLo = 0U;
  c1_info[137].mFileTimeHi = 0U;
  c1_info[138].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/skew.m";
  c1_info[138].name = "length";
  c1_info[138].dominantType = "double";
  c1_info[138].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/length.m";
  c1_info[138].fileTimeLo = 1303124606U;
  c1_info[138].fileTimeHi = 0U;
  c1_info[138].mFileTimeLo = 0U;
  c1_info[138].mFileTimeHi = 0U;
  c1_info[139].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expRot.m";
  c1_info[139].name = "eye";
  c1_info[139].dominantType = "double";
  c1_info[139].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/eye.m";
  c1_info[139].fileTimeLo = 1286797088U;
  c1_info[139].fileTimeHi = 0U;
  c1_info[139].mFileTimeLo = 0U;
  c1_info[139].mFileTimeHi = 0U;
  c1_info[140].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expRot.m";
  c1_info[140].name = "sin";
  c1_info[140].dominantType = "double";
  c1_info[140].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[140].fileTimeLo = 1286797150U;
  c1_info[140].fileTimeHi = 0U;
  c1_info[140].mFileTimeLo = 0U;
  c1_info[140].mFileTimeHi = 0U;
  c1_info[141].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sin.m";
  c1_info[141].name = "eml_scalar_sin";
  c1_info[141].dominantType = "double";
  c1_info[141].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c1_info[141].fileTimeLo = 1286797136U;
  c1_info[141].fileTimeHi = 0U;
  c1_info[141].mFileTimeLo = 0U;
  c1_info[141].mFileTimeHi = 0U;
  c1_info[142].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expRot.m";
  c1_info[142].name = "mtimes";
  c1_info[142].dominantType = "double";
  c1_info[142].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[142].fileTimeLo = 1289494492U;
  c1_info[142].fileTimeHi = 0U;
  c1_info[142].mFileTimeLo = 0U;
  c1_info[142].mFileTimeHi = 0U;
  c1_info[143].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expRot.m";
  c1_info[143].name = "cos";
  c1_info[143].dominantType = "double";
  c1_info[143].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[143].fileTimeLo = 1286797106U;
  c1_info[143].fileTimeHi = 0U;
  c1_info[143].mFileTimeLo = 0U;
  c1_info[143].mFileTimeHi = 0U;
  c1_info[144].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/cos.m";
  c1_info[144].name = "eml_scalar_cos";
  c1_info[144].dominantType = "double";
  c1_info[144].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c1_info[144].fileTimeLo = 1286797122U;
  c1_info[144].fileTimeHi = 0U;
  c1_info[144].mFileTimeLo = 0U;
  c1_info[144].mFileTimeHi = 0U;
  c1_info[145].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/expWre.m";
  c1_info[145].name = "cross";
  c1_info[145].dominantType = "double";
  c1_info[145].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c1_info[145].fileTimeLo = 1286797242U;
  c1_info[145].fileTimeHi = 0U;
  c1_info[145].mFileTimeLo = 0U;
  c1_info[145].mFileTimeHi = 0U;
  c1_info[146].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[146].name = "subPro3";
  c1_info[146].dominantType = "double";
  c1_info[146].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[146].fileTimeLo = 1367251938U;
  c1_info[146].fileTimeHi = 0U;
  c1_info[146].mFileTimeLo = 0U;
  c1_info[146].mFileTimeHi = 0U;
  c1_info[147].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[147].name = "cross";
  c1_info[147].dominantType = "double";
  c1_info[147].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c1_info[147].fileTimeLo = 1286797242U;
  c1_info[147].fileTimeHi = 0U;
  c1_info[147].mFileTimeLo = 0U;
  c1_info[147].mFileTimeHi = 0U;
  c1_info[148].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[148].name = "mtimes";
  c1_info[148].dominantType = "double";
  c1_info[148].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[148].fileTimeLo = 1289494492U;
  c1_info[148].fileTimeHi = 0U;
  c1_info[148].mFileTimeLo = 0U;
  c1_info[148].mFileTimeHi = 0U;
  c1_info[149].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[149].name = "eml_xdotu";
  c1_info[149].dominantType = "int32";
  c1_info[149].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[149].fileTimeLo = 1299051572U;
  c1_info[149].fileTimeHi = 0U;
  c1_info[149].mFileTimeLo = 0U;
  c1_info[149].mFileTimeHi = 0U;
  c1_info[150].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[150].name = "eml_blas_inline";
  c1_info[150].dominantType = "";
  c1_info[150].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[150].fileTimeLo = 1299051568U;
  c1_info[150].fileTimeHi = 0U;
  c1_info[150].mFileTimeLo = 0U;
  c1_info[150].mFileTimeHi = 0U;
  c1_info[151].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[151].name = "eml_xdot";
  c1_info[151].dominantType = "int32";
  c1_info[151].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[151].fileTimeLo = 1299051572U;
  c1_info[151].fileTimeHi = 0U;
  c1_info[151].mFileTimeLo = 0U;
  c1_info[151].mFileTimeHi = 0U;
  c1_info[152].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[152].name = "eml_blas_inline";
  c1_info[152].dominantType = "";
  c1_info[152].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[152].fileTimeLo = 1299051568U;
  c1_info[152].fileTimeHi = 0U;
  c1_info[152].mFileTimeLo = 0U;
  c1_info[152].mFileTimeHi = 0U;
  c1_info[153].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[153].name = "eml_refblas_xdot";
  c1_info[153].dominantType = "int32";
  c1_info[153].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[153].fileTimeLo = 1299051572U;
  c1_info[153].fileTimeHi = 0U;
  c1_info[153].mFileTimeLo = 0U;
  c1_info[153].mFileTimeHi = 0U;
  c1_info[154].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[154].name = "eml_refblas_xdotx";
  c1_info[154].dominantType = "int32";
  c1_info[154].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[154].fileTimeLo = 1299051574U;
  c1_info[154].fileTimeHi = 0U;
  c1_info[154].mFileTimeLo = 0U;
  c1_info[154].mFileTimeHi = 0U;
  c1_info[155].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[155].name = "eml_scalar_eg";
  c1_info[155].dominantType = "double";
  c1_info[155].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[155].fileTimeLo = 1286797196U;
  c1_info[155].fileTimeHi = 0U;
  c1_info[155].mFileTimeLo = 0U;
  c1_info[155].mFileTimeHi = 0U;
  c1_info[156].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[156].name = "eml_index_class";
  c1_info[156].dominantType = "";
  c1_info[156].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[156].fileTimeLo = 1286797178U;
  c1_info[156].fileTimeHi = 0U;
  c1_info[156].mFileTimeLo = 0U;
  c1_info[156].mFileTimeHi = 0U;
  c1_info[157].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[157].name = "eml_index_minus";
  c1_info[157].dominantType = "int32";
  c1_info[157].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[157].fileTimeLo = 1286797178U;
  c1_info[157].fileTimeHi = 0U;
  c1_info[157].mFileTimeLo = 0U;
  c1_info[157].mFileTimeHi = 0U;
  c1_info[158].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[158].name = "eml_index_times";
  c1_info[158].dominantType = "int32";
  c1_info[158].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[158].fileTimeLo = 1286797180U;
  c1_info[158].fileTimeHi = 0U;
  c1_info[158].mFileTimeLo = 0U;
  c1_info[158].mFileTimeHi = 0U;
  c1_info[159].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[159].name = "eml_index_plus";
  c1_info[159].dominantType = "int32";
  c1_info[159].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[159].fileTimeLo = 1286797178U;
  c1_info[159].fileTimeHi = 0U;
  c1_info[159].mFileTimeLo = 0U;
  c1_info[159].mFileTimeHi = 0U;
  c1_info[160].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[160].name = "eml_int_forloop_overflow_check";
  c1_info[160].dominantType = "";
  c1_info[160].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[160].fileTimeLo = 1311233716U;
  c1_info[160].fileTimeHi = 0U;
  c1_info[160].mFileTimeLo = 0U;
  c1_info[160].mFileTimeHi = 0U;
  c1_info[161].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[161].name = "mpower";
  c1_info[161].dominantType = "double";
  c1_info[161].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[161].fileTimeLo = 1286797242U;
  c1_info[161].fileTimeHi = 0U;
  c1_info[161].mFileTimeLo = 0U;
  c1_info[161].mFileTimeHi = 0U;
  c1_info[162].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mpower.m";
  c1_info[162].name = "power";
  c1_info[162].dominantType = "double";
  c1_info[162].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[162].fileTimeLo = 1307629640U;
  c1_info[162].fileTimeHi = 0U;
  c1_info[162].mFileTimeLo = 0U;
  c1_info[162].mFileTimeHi = 0U;
  c1_info[163].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[163].name = "eml_scalar_eg";
  c1_info[163].dominantType = "double";
  c1_info[163].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[163].fileTimeLo = 1286797196U;
  c1_info[163].fileTimeHi = 0U;
  c1_info[163].mFileTimeLo = 0U;
  c1_info[163].mFileTimeHi = 0U;
  c1_info[164].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[164].name = "eml_scalexp_alloc";
  c1_info[164].dominantType = "double";
  c1_info[164].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[164].fileTimeLo = 1286797196U;
  c1_info[164].fileTimeHi = 0U;
  c1_info[164].mFileTimeLo = 0U;
  c1_info[164].mFileTimeHi = 0U;
  c1_info[165].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/power.m";
  c1_info[165].name = "eml_scalar_floor";
  c1_info[165].dominantType = "double";
  c1_info[165].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[165].fileTimeLo = 1286797126U;
  c1_info[165].fileTimeHi = 0U;
  c1_info[165].mFileTimeLo = 0U;
  c1_info[165].mFileTimeHi = 0U;
  c1_info[166].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[166].name = "atan2";
  c1_info[166].dominantType = "double";
  c1_info[166].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[166].fileTimeLo = 1286797104U;
  c1_info[166].fileTimeHi = 0U;
  c1_info[166].mFileTimeLo = 0U;
  c1_info[166].mFileTimeHi = 0U;
  c1_info[167].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[167].name = "norm";
  c1_info[167].dominantType = "double";
  c1_info[167].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m";
  c1_info[167].fileTimeLo = 1286797226U;
  c1_info[167].fileTimeHi = 0U;
  c1_info[167].mFileTimeLo = 0U;
  c1_info[167].mFileTimeHi = 0U;
  c1_info[168].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c1_info[168].name = "eml_index_class";
  c1_info[168].dominantType = "";
  c1_info[168].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[168].fileTimeLo = 1286797178U;
  c1_info[168].fileTimeHi = 0U;
  c1_info[168].mFileTimeLo = 0U;
  c1_info[168].mFileTimeHi = 0U;
  c1_info[169].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm";
  c1_info[169].name = "eml_xnrm2";
  c1_info[169].dominantType = "int32";
  c1_info[169].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[169].fileTimeLo = 1299051576U;
  c1_info[169].fileTimeHi = 0U;
  c1_info[169].mFileTimeLo = 0U;
  c1_info[169].mFileTimeHi = 0U;
  c1_info[170].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xnrm2.m";
  c1_info[170].name = "eml_blas_inline";
  c1_info[170].dominantType = "";
  c1_info[170].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[170].fileTimeLo = 1299051568U;
  c1_info[170].fileTimeHi = 0U;
  c1_info[170].mFileTimeLo = 0U;
  c1_info[170].mFileTimeHi = 0U;
  c1_info[171].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xnrm2.m";
  c1_info[171].name = "eml_refblas_xnrm2";
  c1_info[171].dominantType = "int32";
  c1_info[171].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[171].fileTimeLo = 1299051584U;
  c1_info[171].fileTimeHi = 0U;
  c1_info[171].mFileTimeLo = 0U;
  c1_info[171].mFileTimeHi = 0U;
  c1_info[172].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[172].name = "realmin";
  c1_info[172].dominantType = "char";
  c1_info[172].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/realmin.m";
  c1_info[172].fileTimeLo = 1307629642U;
  c1_info[172].fileTimeHi = 0U;
  c1_info[172].mFileTimeLo = 0U;
  c1_info[172].mFileTimeHi = 0U;
  c1_info[173].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[173].name = "eml_index_class";
  c1_info[173].dominantType = "";
  c1_info[173].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[173].fileTimeLo = 1286797178U;
  c1_info[173].fileTimeHi = 0U;
  c1_info[173].mFileTimeLo = 0U;
  c1_info[173].mFileTimeHi = 0U;
  c1_info[174].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[174].name = "eml_index_minus";
  c1_info[174].dominantType = "int32";
  c1_info[174].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[174].fileTimeLo = 1286797178U;
  c1_info[174].fileTimeHi = 0U;
  c1_info[174].mFileTimeLo = 0U;
  c1_info[174].mFileTimeHi = 0U;
  c1_info[175].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[175].name = "eml_index_times";
  c1_info[175].dominantType = "int32";
  c1_info[175].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[175].fileTimeLo = 1286797180U;
  c1_info[175].fileTimeHi = 0U;
  c1_info[175].mFileTimeLo = 0U;
  c1_info[175].mFileTimeHi = 0U;
  c1_info[176].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[176].name = "eml_index_plus";
  c1_info[176].dominantType = "int32";
  c1_info[176].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[176].fileTimeLo = 1286797178U;
  c1_info[176].fileTimeHi = 0U;
  c1_info[176].mFileTimeLo = 0U;
  c1_info[176].mFileTimeHi = 0U;
  c1_info[177].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[177].name = "eml_int_forloop_overflow_check";
  c1_info[177].dominantType = "";
  c1_info[177].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[177].fileTimeLo = 1311233716U;
  c1_info[177].fileTimeHi = 0U;
  c1_info[177].mFileTimeLo = 0U;
  c1_info[177].mFileTimeHi = 0U;
  c1_info[178].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xnrm2.m";
  c1_info[178].name = "abs";
  c1_info[178].dominantType = "double";
  c1_info[178].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/abs.m";
  c1_info[178].fileTimeLo = 1286797094U;
  c1_info[178].fileTimeHi = 0U;
  c1_info[178].mFileTimeLo = 0U;
  c1_info[178].mFileTimeHi = 0U;
  c1_info[179].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[179].name = "mrdivide";
  c1_info[179].dominantType = "double";
  c1_info[179].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[179].fileTimeLo = 1325098938U;
  c1_info[179].fileTimeHi = 0U;
  c1_info[179].mFileTimeLo = 1319708366U;
  c1_info[179].mFileTimeHi = 0U;
  c1_info[180].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro3.m";
  c1_info[180].name = "acos";
  c1_info[180].dominantType = "double";
  c1_info[180].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/acos.m";
  c1_info[180].fileTimeLo = 1286797094U;
  c1_info[180].fileTimeHi = 0U;
  c1_info[180].mFileTimeLo = 0U;
  c1_info[180].mFileTimeHi = 0U;
  c1_info[181].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/acos.m";
  c1_info[181].name = "eml_error";
  c1_info[181].dominantType = "char";
  c1_info[181].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[181].fileTimeLo = 1305296400U;
  c1_info[181].fileTimeHi = 0U;
  c1_info[181].mFileTimeLo = 0U;
  c1_info[181].mFileTimeHi = 0U;
  c1_info[182].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/acos.m";
  c1_info[182].name = "eml_scalar_acos";
  c1_info[182].dominantType = "double";
  c1_info[182].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m";
  c1_info[182].fileTimeLo = 1286797112U;
  c1_info[182].fileTimeHi = 0U;
  c1_info[182].mFileTimeLo = 0U;
  c1_info[182].mFileTimeHi = 0U;
  c1_info[183].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[183].name = "any";
  c1_info[183].dominantType = "logical";
  c1_info[183].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[183].fileTimeLo = 1286797234U;
  c1_info[183].fileTimeHi = 0U;
  c1_info[183].mFileTimeLo = 0U;
  c1_info[183].mFileTimeHi = 0U;
  c1_info[184].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/any.m";
  c1_info[184].name = "eml_all_or_any";
  c1_info[184].dominantType = "char";
  c1_info[184].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[184].fileTimeLo = 1286797094U;
  c1_info[184].fileTimeHi = 0U;
  c1_info[184].mFileTimeLo = 0U;
  c1_info[184].mFileTimeHi = 0U;
  c1_info[185].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c1_info[185].name = "isnan";
  c1_info[185].dominantType = "logical";
  c1_info[185].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elmat/isnan.m";
  c1_info[185].fileTimeLo = 1286797160U;
  c1_info[185].fileTimeHi = 0U;
  c1_info[185].mFileTimeLo = 0U;
  c1_info[185].mFileTimeHi = 0U;
  c1_info[186].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[186].name = "subPro1";
  c1_info[186].dominantType = "double";
  c1_info[186].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro1.m";
  c1_info[186].fileTimeLo = 1336045298U;
  c1_info[186].fileTimeHi = 0U;
  c1_info[186].mFileTimeLo = 0U;
  c1_info[186].mFileTimeHi = 0U;
  c1_info[187].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro1.m";
  c1_info[187].name = "cross";
  c1_info[187].dominantType = "double";
  c1_info[187].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c1_info[187].fileTimeLo = 1286797242U;
  c1_info[187].fileTimeHi = 0U;
  c1_info[187].mFileTimeLo = 0U;
  c1_info[187].mFileTimeHi = 0U;
  c1_info[188].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro1.m";
  c1_info[188].name = "mtimes";
  c1_info[188].dominantType = "double";
  c1_info[188].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[188].fileTimeLo = 1289494492U;
  c1_info[188].fileTimeHi = 0U;
  c1_info[188].mFileTimeLo = 0U;
  c1_info[188].mFileTimeHi = 0U;
  c1_info[189].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro1.m";
  c1_info[189].name = "atan2";
  c1_info[189].dominantType = "double";
  c1_info[189].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/atan2.m";
  c1_info[189].fileTimeLo = 1286797104U;
  c1_info[189].fileTimeHi = 0U;
  c1_info[189].mFileTimeLo = 0U;
  c1_info[189].mFileTimeHi = 0U;
  c1_info[190].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/inv_kin.m";
  c1_info[190].name = "subPro2";
  c1_info[190].dominantType = "double";
  c1_info[190].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m";
  c1_info[190].fileTimeLo = 1367255420U;
  c1_info[190].fileTimeHi = 0U;
  c1_info[190].mFileTimeLo = 0U;
  c1_info[190].mFileTimeHi = 0U;
  c1_info[191].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m";
  c1_info[191].name = "cross";
  c1_info[191].dominantType = "double";
  c1_info[191].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/specfun/cross.m";
  c1_info[191].fileTimeLo = 1286797242U;
  c1_info[191].fileTimeHi = 0U;
  c1_info[191].mFileTimeLo = 0U;
  c1_info[191].mFileTimeHi = 0U;
}

static void c1_d_info_helper(c1_ResolvedFunctionInfo c1_info[209])
{
  c1_info[192].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m!findCommon";
  c1_info[192].name = "det";
  c1_info[192].dominantType = "double";
  c1_info[192].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/det.m";
  c1_info[192].fileTimeLo = 1286797222U;
  c1_info[192].fileTimeHi = 0U;
  c1_info[192].mFileTimeLo = 0U;
  c1_info[192].mFileTimeHi = 0U;
  c1_info[193].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/det.m";
  c1_info[193].name = "eml_index_class";
  c1_info[193].dominantType = "";
  c1_info[193].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[193].fileTimeLo = 1286797178U;
  c1_info[193].fileTimeHi = 0U;
  c1_info[193].mFileTimeLo = 0U;
  c1_info[193].mFileTimeHi = 0U;
  c1_info[194].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/det.m";
  c1_info[194].name = "eml_xgetrf";
  c1_info[194].dominantType = "int32";
  c1_info[194].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c1_info[194].fileTimeLo = 1286797206U;
  c1_info[194].fileTimeHi = 0U;
  c1_info[194].mFileTimeLo = 0U;
  c1_info[194].mFileTimeHi = 0U;
  c1_info[195].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/matfun/det.m";
  c1_info[195].name = "mtimes";
  c1_info[195].dominantType = "double";
  c1_info[195].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[195].fileTimeLo = 1289494492U;
  c1_info[195].fileTimeHi = 0U;
  c1_info[195].mFileTimeLo = 0U;
  c1_info[195].mFileTimeHi = 0U;
  c1_info[196].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m!findCommon";
  c1_info[196].name = "mldivide";
  c1_info[196].dominantType = "double";
  c1_info[196].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mldivide.p";
  c1_info[196].fileTimeLo = 1325098938U;
  c1_info[196].fileTimeHi = 0U;
  c1_info[196].mFileTimeLo = 1319708366U;
  c1_info[196].mFileTimeHi = 0U;
  c1_info[197].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c1_info[197].name = "eml_index_class";
  c1_info[197].dominantType = "";
  c1_info[197].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[197].fileTimeLo = 1286797178U;
  c1_info[197].fileTimeHi = 0U;
  c1_info[197].mFileTimeLo = 0U;
  c1_info[197].mFileTimeHi = 0U;
  c1_info[198].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c1_info[198].name = "eml_xcabs1";
  c1_info[198].dominantType = "double";
  c1_info[198].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c1_info[198].fileTimeLo = 1286797106U;
  c1_info[198].fileTimeHi = 0U;
  c1_info[198].mFileTimeLo = 0U;
  c1_info[198].mFileTimeHi = 0U;
  c1_info[199].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c1_info[199].name = "eml_div";
  c1_info[199].dominantType = "double";
  c1_info[199].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[199].fileTimeLo = 1313326210U;
  c1_info[199].fileTimeHi = 0U;
  c1_info[199].mFileTimeLo = 0U;
  c1_info[199].mFileTimeHi = 0U;
  c1_info[200].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c1_info[200].name = "mtimes";
  c1_info[200].dominantType = "double";
  c1_info[200].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[200].fileTimeLo = 1289494492U;
  c1_info[200].fileTimeHi = 0U;
  c1_info[200].mFileTimeLo = 0U;
  c1_info[200].mFileTimeHi = 0U;
  c1_info[201].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve2x2";
  c1_info[201].name = "eml_scalar_eg";
  c1_info[201].dominantType = "double";
  c1_info[201].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[201].fileTimeLo = 1286797196U;
  c1_info[201].fileTimeHi = 0U;
  c1_info[201].mFileTimeLo = 0U;
  c1_info[201].mFileTimeHi = 0U;
  c1_info[202].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m!findCommon";
  c1_info[202].name = "mtimes";
  c1_info[202].dominantType = "double";
  c1_info[202].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[202].fileTimeLo = 1289494492U;
  c1_info[202].fileTimeHi = 0U;
  c1_info[202].mFileTimeLo = 0U;
  c1_info[202].mFileTimeHi = 0U;
  c1_info[203].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m";
  c1_info[203].name = "mtimes";
  c1_info[203].dominantType = "double";
  c1_info[203].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[203].fileTimeLo = 1289494492U;
  c1_info[203].fileTimeHi = 0U;
  c1_info[203].mFileTimeLo = 0U;
  c1_info[203].mFileTimeHi = 0U;
  c1_info[204].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m";
  c1_info[204].name = "mrdivide";
  c1_info[204].dominantType = "double";
  c1_info[204].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[204].fileTimeLo = 1325098938U;
  c1_info[204].fileTimeHi = 0U;
  c1_info[204].mFileTimeLo = 1319708366U;
  c1_info[204].mFileTimeHi = 0U;
  c1_info[205].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m";
  c1_info[205].name = "sqrt";
  c1_info[205].dominantType = "double";
  c1_info[205].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[205].fileTimeLo = 1286797152U;
  c1_info[205].fileTimeHi = 0U;
  c1_info[205].mFileTimeLo = 0U;
  c1_info[205].mFileTimeHi = 0U;
  c1_info[206].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[206].name = "eml_error";
  c1_info[206].dominantType = "char";
  c1_info[206].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/eml/eml_error.m";
  c1_info[206].fileTimeLo = 1305296400U;
  c1_info[206].fileTimeHi = 0U;
  c1_info[206].mFileTimeLo = 0U;
  c1_info[206].mFileTimeHi = 0U;
  c1_info[207].context =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c1_info[207].name = "eml_scalar_sqrt";
  c1_info[207].dominantType = "double";
  c1_info[207].resolved =
    "[ILXE]D:/MATLAB/R2012a/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c1_info[207].fileTimeLo = 1286797138U;
  c1_info[207].fileTimeHi = 0U;
  c1_info[207].mFileTimeLo = 0U;
  c1_info[207].mFileTimeHi = 0U;
  c1_info[208].context =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro2.m";
  c1_info[208].name = "subPro1";
  c1_info[208].dominantType = "double";
  c1_info[208].resolved =
    "[EW]E:/\\xe6\\xb5\\x99\\xe5\\xa4\\xa7/\\xe8\\x87\\xaa\\xe4\\xb8\\xbb\\xe5\\xae\\x9e\\xe4\\xb9\\xa0/Dynamics_DaiDan/Fanuc/subPro1.m";
  c1_info[208].fileTimeLo = 1336045298U;
  c1_info[208].fileTimeHi = 0U;
  c1_info[208].mFileTimeLo = 0U;
  c1_info[208].mFileTimeHi = 0U;
}

static void c1_inv_kin(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_gd[16], real_T c1_b_L[9], real_T c1_theta[24],
  real_T *c1_Num)
{
  uint32_T c1_debug_family_var_map[69];
  real_T c1_Min1;
  real_T c1_Max1;
  real_T c1_Min2;
  real_T c1_Max2;
  real_T c1_Min3;
  real_T c1_Max3;
  real_T c1_Min4;
  real_T c1_Max4;
  real_T c1_Min5;
  real_T c1_Max5;
  real_T c1_Min6;
  real_T c1_Max6;
  real_T c1_L1;
  real_T c1_L2;
  real_T c1_L3;
  real_T c1_L4;
  real_T c1_L5;
  real_T c1_L6;
  real_T c1_L7;
  real_T c1_L8;
  real_T c1_L9;
  real_T c1_s_origin[3];
  real_T c1_w_x[3];
  real_T c1_w_y[3];
  real_T c1_w_z[3];
  real_T c1_w1[3];
  real_T c1_q1[3];
  real_T c1_kx1[6];
  real_T c1_w2[3];
  real_T c1_q2[3];
  real_T c1_kx2[6];
  real_T c1_w3[3];
  real_T c1_q3[3];
  real_T c1_kx3[6];
  real_T c1_pw[3];
  real_T c1_w4[3];
  real_T c1_q4[3];
  real_T c1_kx4[6];
  real_T c1_w5[3];
  real_T c1_q5[3];
  real_T c1_kx5[6];
  real_T c1_w6[3];
  real_T c1_q6[3];
  real_T c1_kx6[6];
  real_T c1_q7[3];
  real_T c1_gst0[16];
  real_T c1_g1[16];
  real_T c1_p1[4];
  real_T c1_theta_1;
  real_T c1_p2[4];
  real_T c1_d[4];
  real_T c1_theta_3[2];
  real_T c1_Num_3;
  real_T c1_p3[4];
  real_T c1_theta_2;
  real_T c1_g2[16];
  real_T c1_p4[4];
  real_T c1_theta_4[2];
  real_T c1_theta_5[2];
  real_T c1_Num_45;
  real_T c1_g3[16];
  real_T c1_p5[4];
  real_T c1_theta_6;
  real_T c1_b_q1[4];
  real_T c1_b_q2[4];
  real_T c1_b_q3[4];
  real_T c1_b_q4[4];
  real_T c1_b_q5[4];
  real_T c1_b_q6[4];
  real_T c1_b_q7[4];
  real_T c1_b_pw[4];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 2.0;
  int32_T c1_i89;
  int32_T c1_i90;
  int32_T c1_i91;
  static real_T c1_dv13[3] = { 1.0, 0.0, 0.0 };

  int32_T c1_i92;
  static real_T c1_dv14[3] = { 0.0, 1.0, 0.0 };

  int32_T c1_i93;
  static real_T c1_dv15[3] = { 0.0, 0.0, 1.0 };

  int32_T c1_i94;
  int32_T c1_i95;
  int32_T c1_i96;
  static real_T c1_dv16[6] = { -0.0, -0.0, -0.0, 0.0, 0.0, 1.0 };

  int32_T c1_i97;
  int32_T c1_i98;
  real_T c1_dv17[3];
  int32_T c1_i99;
  real_T c1_c_q2[3];
  real_T c1_dv18[3];
  int32_T c1_i100;
  int32_T c1_i101;
  int32_T c1_i102;
  int32_T c1_i103;
  real_T c1_dv19[3];
  int32_T c1_i104;
  real_T c1_c_q3[3];
  int32_T c1_i105;
  int32_T c1_i106;
  int32_T c1_i107;
  int32_T c1_i108;
  int32_T c1_i109;
  real_T c1_dv20[3];
  int32_T c1_i110;
  real_T c1_c_q4[3];
  int32_T c1_i111;
  int32_T c1_i112;
  int32_T c1_i113;
  int32_T c1_i114;
  int32_T c1_i115;
  real_T c1_dv21[3];
  int32_T c1_i116;
  real_T c1_c_q5[3];
  int32_T c1_i117;
  int32_T c1_i118;
  int32_T c1_i119;
  int32_T c1_i120;
  int32_T c1_i121;
  real_T c1_dv22[3];
  int32_T c1_i122;
  real_T c1_c_q6[3];
  int32_T c1_i123;
  int32_T c1_i124;
  int32_T c1_i125;
  int32_T c1_i126;
  int32_T c1_i127;
  int32_T c1_i128;
  int32_T c1_i129;
  int32_T c1_i130;
  int32_T c1_i131;
  int32_T c1_i132;
  int32_T c1_i133;
  int32_T c1_i134;
  static real_T c1_dv23[4] = { 0.0, 0.0, 0.0, 1.0 };

  int32_T c1_i135;
  boolean_T c1_bv1[2];
  int32_T c1_i136;
  real_T c1_b_gd[16];
  int32_T c1_i137;
  real_T c1_b_gst0[16];
  real_T c1_dv24[16];
  int32_T c1_i138;
  int32_T c1_i139;
  real_T c1_a[16];
  int32_T c1_i140;
  real_T c1_b[4];
  int32_T c1_i141;
  int32_T c1_i142;
  int32_T c1_i143;
  real_T c1_C[4];
  int32_T c1_i144;
  int32_T c1_i145;
  int32_T c1_i146;
  int32_T c1_i147;
  int32_T c1_i148;
  int32_T c1_i149;
  int32_T c1_i150;
  static real_T c1_dv25[6] = { 0.0, 0.0, 0.0, -0.0, -0.0, -1.0 };

  real_T c1_dv26[6];
  int32_T c1_i151;
  int32_T c1_i152;
  int32_T c1_i153;
  int32_T c1_i154;
  int32_T c1_i155;
  int32_T c1_i156;
  int32_T c1_i157;
  int32_T c1_i158;
  int32_T c1_i159;
  int32_T c1_i160;
  int32_T c1_i161;
  int32_T c1_i162;
  real_T c1_b_kx3[6];
  int32_T c1_i163;
  real_T c1_c_pw[4];
  int32_T c1_i164;
  real_T c1_d_q2[4];
  int32_T c1_i165;
  real_T c1_b_d[4];
  real_T c1_b_Num_3;
  real_T c1_b_theta_3[2];
  int32_T c1_i166;
  int32_T c1_i167;
  real_T c1_c_theta_3[2];
  boolean_T c1_bv2[2];
  int32_T c1_i168;
  boolean_T c1_bv3[2];
  int32_T c1_i169;
  int32_T c1_loop_ub;
  int32_T c1_c3;
  real_T c1_b_c3;
  int32_T c1_i170;
  real_T c1_c_kx3[6];
  int32_T c1_i171;
  int32_T c1_i172;
  int32_T c1_i173;
  int32_T c1_i174;
  int32_T c1_i175;
  int32_T c1_i176;
  int32_T c1_i177;
  int32_T c1_i178;
  int32_T c1_i179;
  int32_T c1_i180;
  int32_T c1_i181;
  real_T c1_b_kx2[6];
  int32_T c1_i182;
  real_T c1_b_p3[4];
  int32_T c1_i183;
  real_T c1_b_p2[4];
  int32_T c1_i184;
  real_T c1_d_kx3[6];
  int32_T c1_i185;
  real_T c1_c_kx2[6];
  real_T c1_b_b[16];
  int32_T c1_i186;
  int32_T c1_i187;
  int32_T c1_i188;
  real_T c1_y[16];
  int32_T c1_i189;
  int32_T c1_i190;
  int32_T c1_i191;
  real_T c1_dv27[6];
  int32_T c1_i192;
  int32_T c1_i193;
  int32_T c1_i194;
  int32_T c1_i195;
  int32_T c1_i196;
  int32_T c1_i197;
  int32_T c1_i198;
  int32_T c1_i199;
  int32_T c1_i200;
  real_T c1_b_C[16];
  int32_T c1_i201;
  int32_T c1_i202;
  int32_T c1_i203;
  int32_T c1_i204;
  int32_T c1_i205;
  int32_T c1_i206;
  int32_T c1_i207;
  int32_T c1_i208;
  int32_T c1_i209;
  int32_T c1_i210;
  int32_T c1_i211;
  int32_T c1_i212;
  int32_T c1_i213;
  int32_T c1_i214;
  int32_T c1_i215;
  int32_T c1_i216;
  int32_T c1_i217;
  int32_T c1_i218;
  int32_T c1_i219;
  int32_T c1_i220;
  real_T c1_b_kx4[6];
  int32_T c1_i221;
  real_T c1_b_kx5[6];
  int32_T c1_i222;
  real_T c1_c_q7[4];
  int32_T c1_i223;
  real_T c1_b_p4[4];
  real_T c1_b_Num_45;
  real_T c1_b_theta_5[2];
  int32_T c1_i224;
  int32_T c1_i225;
  int32_T c1_i226;
  real_T c1_c_theta_5[2];
  int32_T c1_i227;
  boolean_T c1_bv4[2];
  int32_T c1_i228;
  int32_T c1_b_loop_ub;
  int32_T c1_c45;
  real_T c1_b_c45;
  int32_T c1_i229;
  real_T c1_c_kx5[6];
  int32_T c1_i230;
  real_T c1_c_kx4[6];
  int32_T c1_i231;
  int32_T c1_i232;
  int32_T c1_i233;
  int32_T c1_i234;
  int32_T c1_i235;
  int32_T c1_i236;
  int32_T c1_i237;
  int32_T c1_i238;
  int32_T c1_i239;
  int32_T c1_i240;
  int32_T c1_i241;
  int32_T c1_i242;
  int32_T c1_i243;
  int32_T c1_i244;
  int32_T c1_i245;
  int32_T c1_i246;
  int32_T c1_i247;
  int32_T c1_i248;
  int32_T c1_i249;
  int32_T c1_i250;
  int32_T c1_i251;
  int32_T c1_i252;
  int32_T c1_i253;
  int32_T c1_i254;
  int32_T c1_i255;
  int32_T c1_i256;
  int32_T c1_i257;
  int32_T c1_i258;
  int32_T c1_i259;
  real_T c1_b_kx6[6];
  int32_T c1_i260;
  real_T c1_d_q3[4];
  int32_T c1_i261;
  real_T c1_b_p5[4];
  int32_T c1_b_Num;
  real_T c1_b_theta_1[6];
  int32_T c1_i262;
  int32_T exitg1;
  boolean_T guard1 = FALSE;
  sf_debug_symbol_scope_push_eml(0U, 69U, 77U, c1_m_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_Min1, 0U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Max1, 1U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Min2, 2U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Max2, 3U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Min3, 4U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Max3, 5U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_Min4, 6U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Max4, 7U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_Min5, 8U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_Max5, 9U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_Min6, 10U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Max6, 11U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L1, 12U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L2, 13U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L3, 14U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L4, 15U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L5, 16U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L6, 17U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L7, 18U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L8, 19U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_L9, 20U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_s_origin, 21U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_w_x, 22U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_w_y, 23U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_w_z, 24U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_w1, 25U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_q1, MAX_uint32_T, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_kx1, 27U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_w2, 28U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_q2, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx2, 30U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_w3, 31U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_q3, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx3, 33U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_pw, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_w4, 35U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_q4, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx4, 37U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_w5, 38U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_q5, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx5, 40U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_w6, 41U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_q6, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx6, 43U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_q7, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_gst0, 45U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_g1, 46U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p1, 47U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta_1, 48U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p2, 49U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_d, 50U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_theta_3, 51U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Num_3, 52U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p3, 53U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta_2, 54U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_g2, 55U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p4, 56U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_theta_4, 57U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_theta_5, 58U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_Num_45, 59U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_g3, 60U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p5, 61U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta_6, 62U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q1, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q2, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q3, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q4, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q5, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q6, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q7, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_pw, MAX_uint32_T,
    c1_j_sf_marshallOut, c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 63U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 64U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_gd, 65U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_L, 66U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_theta, 67U, c1_f_sf_marshallOut,
    c1_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Num, 68U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 2);
  for (c1_i89 = 0; c1_i89 < 24; c1_i89++) {
    c1_theta[c1_i89] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 3);
  *c1_Num = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_Min1 = -165.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_Max1 = 165.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_Min2 = -150.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_Max2 = 60.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_Min3 = -210.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 7);
  c1_Max3 = 90.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_Min4 = -180.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 8);
  c1_Max4 = 180.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_Min5 = -140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_Max5 = 140.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_Min6 = -180.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 10);
  c1_Max6 = 180.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_L1 = c1_b_L[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_L2 = c1_b_L[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 14);
  c1_L3 = c1_b_L[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 15);
  c1_L4 = c1_b_L[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_L5 = c1_b_L[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_L6 = c1_b_L[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 18);
  c1_L7 = c1_b_L[6];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 19);
  c1_L8 = c1_b_L[7];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 20);
  c1_L9 = c1_b_L[8];
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 22);
  for (c1_i90 = 0; c1_i90 < 3; c1_i90++) {
    c1_s_origin[c1_i90] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 23);
  for (c1_i91 = 0; c1_i91 < 3; c1_i91++) {
    c1_w_x[c1_i91] = c1_dv13[c1_i91];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 24);
  for (c1_i92 = 0; c1_i92 < 3; c1_i92++) {
    c1_w_y[c1_i92] = c1_dv14[c1_i92];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 25);
  for (c1_i93 = 0; c1_i93 < 3; c1_i93++) {
    c1_w_z[c1_i93] = c1_dv15[c1_i93];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 27);
  for (c1_i94 = 0; c1_i94 < 3; c1_i94++) {
    c1_w1[c1_i94] = c1_dv15[c1_i94];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 28);
  for (c1_i95 = 0; c1_i95 < 3; c1_i95++) {
    c1_q1[c1_i95] = 0.0;
  }

  sf_debug_symbol_switch(26U, 26U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 29);
  for (c1_i96 = 0; c1_i96 < 6; c1_i96++) {
    c1_kx1[c1_i96] = c1_dv16[c1_i96];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 31);
  for (c1_i97 = 0; c1_i97 < 3; c1_i97++) {
    c1_w2[c1_i97] = c1_dv14[c1_i97];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 32);
  c1_q2[0] = c1_L2;
  c1_q2[1] = 0.0;
  c1_q2[2] = c1_L1;
  sf_debug_symbol_switch(29U, 29U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 33);
  for (c1_i98 = 0; c1_i98 < 3; c1_i98++) {
    c1_dv17[c1_i98] = c1_dv14[c1_i98];
  }

  for (c1_i99 = 0; c1_i99 < 3; c1_i99++) {
    c1_c_q2[c1_i99] = c1_q2[c1_i99];
  }

  c1_cross(chartInstance, c1_dv17, c1_c_q2, c1_dv18);
  for (c1_i100 = 0; c1_i100 < 3; c1_i100++) {
    c1_kx2[c1_i100] = -c1_dv18[c1_i100];
  }

  for (c1_i101 = 0; c1_i101 < 3; c1_i101++) {
    c1_kx2[c1_i101 + 3] = c1_w2[c1_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 35);
  for (c1_i102 = 0; c1_i102 < 3; c1_i102++) {
    c1_w3[c1_i102] = c1_dv14[c1_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 36);
  c1_q3[0] = c1_L2;
  c1_q3[1] = 0.0;
  c1_q3[2] = c1_L1 + c1_L3;
  sf_debug_symbol_switch(32U, 32U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 37);
  for (c1_i103 = 0; c1_i103 < 3; c1_i103++) {
    c1_dv19[c1_i103] = c1_dv14[c1_i103];
  }

  for (c1_i104 = 0; c1_i104 < 3; c1_i104++) {
    c1_c_q3[c1_i104] = c1_q3[c1_i104];
  }

  c1_cross(chartInstance, c1_dv19, c1_c_q3, c1_dv18);
  for (c1_i105 = 0; c1_i105 < 3; c1_i105++) {
    c1_kx3[c1_i105] = -c1_dv18[c1_i105];
  }

  for (c1_i106 = 0; c1_i106 < 3; c1_i106++) {
    c1_kx3[c1_i106 + 3] = c1_w3[c1_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 39);
  c1_pw[0] = c1_L2 + c1_L5;
  c1_pw[1] = 0.0;
  c1_pw[2] = (c1_L1 + c1_L3) + c1_L4;
  sf_debug_symbol_switch(34U, 34U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 41);
  for (c1_i107 = 0; c1_i107 < 3; c1_i107++) {
    c1_w4[c1_i107] = c1_dv13[c1_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 42);
  for (c1_i108 = 0; c1_i108 < 3; c1_i108++) {
    c1_q4[c1_i108] = c1_pw[c1_i108];
  }

  sf_debug_symbol_switch(36U, 36U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 43);
  for (c1_i109 = 0; c1_i109 < 3; c1_i109++) {
    c1_dv20[c1_i109] = c1_dv13[c1_i109];
  }

  for (c1_i110 = 0; c1_i110 < 3; c1_i110++) {
    c1_c_q4[c1_i110] = c1_q4[c1_i110];
  }

  c1_cross(chartInstance, c1_dv20, c1_c_q4, c1_dv18);
  for (c1_i111 = 0; c1_i111 < 3; c1_i111++) {
    c1_kx4[c1_i111] = -c1_dv18[c1_i111];
  }

  for (c1_i112 = 0; c1_i112 < 3; c1_i112++) {
    c1_kx4[c1_i112 + 3] = c1_w4[c1_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 45);
  for (c1_i113 = 0; c1_i113 < 3; c1_i113++) {
    c1_w5[c1_i113] = c1_dv14[c1_i113];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 46);
  for (c1_i114 = 0; c1_i114 < 3; c1_i114++) {
    c1_q5[c1_i114] = c1_pw[c1_i114];
  }

  sf_debug_symbol_switch(39U, 39U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 47);
  for (c1_i115 = 0; c1_i115 < 3; c1_i115++) {
    c1_dv21[c1_i115] = c1_dv14[c1_i115];
  }

  for (c1_i116 = 0; c1_i116 < 3; c1_i116++) {
    c1_c_q5[c1_i116] = c1_q5[c1_i116];
  }

  c1_cross(chartInstance, c1_dv21, c1_c_q5, c1_dv18);
  for (c1_i117 = 0; c1_i117 < 3; c1_i117++) {
    c1_kx5[c1_i117] = -c1_dv18[c1_i117];
  }

  for (c1_i118 = 0; c1_i118 < 3; c1_i118++) {
    c1_kx5[c1_i118 + 3] = c1_w5[c1_i118];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 49);
  for (c1_i119 = 0; c1_i119 < 3; c1_i119++) {
    c1_w6[c1_i119] = c1_dv13[c1_i119];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 50);
  for (c1_i120 = 0; c1_i120 < 3; c1_i120++) {
    c1_q6[c1_i120] = c1_pw[c1_i120];
  }

  sf_debug_symbol_switch(42U, 42U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 51);
  for (c1_i121 = 0; c1_i121 < 3; c1_i121++) {
    c1_dv22[c1_i121] = c1_dv13[c1_i121];
  }

  for (c1_i122 = 0; c1_i122 < 3; c1_i122++) {
    c1_c_q6[c1_i122] = c1_q6[c1_i122];
  }

  c1_cross(chartInstance, c1_dv22, c1_c_q6, c1_dv18);
  for (c1_i123 = 0; c1_i123 < 3; c1_i123++) {
    c1_kx6[c1_i123] = -c1_dv18[c1_i123];
  }

  for (c1_i124 = 0; c1_i124 < 3; c1_i124++) {
    c1_kx6[c1_i124 + 3] = c1_w6[c1_i124];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 53);
  c1_q7[0] = (c1_L2 + c1_L5) + c1_L6;
  c1_q7[1] = 0.0;
  c1_q7[2] = (c1_L1 + c1_L3) + c1_L4;
  sf_debug_symbol_switch(44U, 44U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 55);
  for (c1_i125 = 0; c1_i125 < 3; c1_i125++) {
    c1_b_q1[c1_i125] = c1_q1[c1_i125];
  }

  c1_b_q1[3] = 1.0;
  sf_debug_symbol_switch(26U, 63U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 56);
  for (c1_i126 = 0; c1_i126 < 3; c1_i126++) {
    c1_b_q2[c1_i126] = c1_q2[c1_i126];
  }

  c1_b_q2[3] = 1.0;
  sf_debug_symbol_switch(29U, 64U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 57);
  for (c1_i127 = 0; c1_i127 < 3; c1_i127++) {
    c1_b_q3[c1_i127] = c1_q3[c1_i127];
  }

  c1_b_q3[3] = 1.0;
  sf_debug_symbol_switch(32U, 65U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 58);
  for (c1_i128 = 0; c1_i128 < 3; c1_i128++) {
    c1_b_q4[c1_i128] = c1_q4[c1_i128];
  }

  c1_b_q4[3] = 1.0;
  sf_debug_symbol_switch(36U, 66U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 59);
  for (c1_i129 = 0; c1_i129 < 3; c1_i129++) {
    c1_b_q5[c1_i129] = c1_q5[c1_i129];
  }

  c1_b_q5[3] = 1.0;
  sf_debug_symbol_switch(39U, 67U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 60);
  for (c1_i130 = 0; c1_i130 < 3; c1_i130++) {
    c1_b_q6[c1_i130] = c1_q6[c1_i130];
  }

  c1_b_q6[3] = 1.0;
  sf_debug_symbol_switch(42U, 68U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 61);
  for (c1_i131 = 0; c1_i131 < 3; c1_i131++) {
    c1_b_q7[c1_i131] = c1_q7[c1_i131];
  }

  c1_b_q7[3] = 1.0;
  sf_debug_symbol_switch(44U, 69U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 62);
  for (c1_i132 = 0; c1_i132 < 3; c1_i132++) {
    c1_b_pw[c1_i132] = c1_pw[c1_i132];
  }

  c1_b_pw[3] = 1.0;
  sf_debug_symbol_switch(34U, 70U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 65);
  c1_gst0[0] = 1.0;
  c1_gst0[4] = 0.0;
  c1_gst0[8] = 0.0;
  c1_gst0[12] = ((c1_L2 + c1_L5) + c1_L6) + c1_L7;
  c1_gst0[1] = 0.0;
  c1_gst0[5] = 1.0;
  c1_gst0[9] = 0.0;
  c1_gst0[13] = c1_L8;
  c1_gst0[2] = 0.0;
  c1_gst0[6] = 0.0;
  c1_gst0[10] = 1.0;
  c1_gst0[14] = ((c1_L1 + c1_L3) + c1_L4) + c1_L9;
  c1_i133 = 0;
  for (c1_i134 = 0; c1_i134 < 4; c1_i134++) {
    c1_gst0[c1_i133 + 3] = c1_dv23[c1_i134];
    c1_i133 += 4;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 67);
  for (c1_i135 = 0; c1_i135 < 2; c1_i135++) {
    c1_bv1[c1_i135] = TRUE;
  }

  CV_SCRIPT_IF(0, 0, c1_all(chartInstance, c1_bv1));
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 68);
  for (c1_i136 = 0; c1_i136 < 16; c1_i136++) {
    c1_b_gd[c1_i136] = c1_gd[c1_i136];
  }

  for (c1_i137 = 0; c1_i137 < 16; c1_i137++) {
    c1_b_gst0[c1_i137] = c1_gst0[c1_i137];
  }

  c1_mrdivide(chartInstance, c1_b_gd, c1_b_gst0, c1_dv24);
  for (c1_i138 = 0; c1_i138 < 16; c1_i138++) {
    c1_g1[c1_i138] = c1_dv24[c1_i138];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 83);
  for (c1_i139 = 0; c1_i139 < 16; c1_i139++) {
    c1_a[c1_i139] = c1_g1[c1_i139];
  }

  for (c1_i140 = 0; c1_i140 < 4; c1_i140++) {
    c1_b[c1_i140] = c1_b_pw[c1_i140];
  }

  c1_d_eml_scalar_eg(chartInstance);
  c1_d_eml_scalar_eg(chartInstance);
  for (c1_i141 = 0; c1_i141 < 4; c1_i141++) {
    c1_p1[c1_i141] = 0.0;
  }

  for (c1_i142 = 0; c1_i142 < 4; c1_i142++) {
    c1_p1[c1_i142] = 0.0;
  }

  for (c1_i143 = 0; c1_i143 < 4; c1_i143++) {
    c1_C[c1_i143] = c1_p1[c1_i143];
  }

  for (c1_i144 = 0; c1_i144 < 4; c1_i144++) {
    c1_p1[c1_i144] = c1_C[c1_i144];
  }

  for (c1_i145 = 0; c1_i145 < 4; c1_i145++) {
    c1_C[c1_i145] = c1_p1[c1_i145];
  }

  for (c1_i146 = 0; c1_i146 < 4; c1_i146++) {
    c1_p1[c1_i146] = c1_C[c1_i146];
  }

  for (c1_i147 = 0; c1_i147 < 4; c1_i147++) {
    c1_p1[c1_i147] = 0.0;
    c1_i148 = 0;
    for (c1_i149 = 0; c1_i149 < 4; c1_i149++) {
      c1_p1[c1_i147] += c1_a[c1_i148 + c1_i147] * c1_b[c1_i149];
      c1_i148 += 4;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 84);
  c1_theta_1 = c1_atan2(chartInstance, c1_p1[1], c1_p1[0]);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 85);
  if (CV_SCRIPT_IF(0, 2, (real_T)c1_isInRange(chartInstance, c1_theta_1, -165.0,
        165.0) == 0.0)) {
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 91);
    for (c1_i150 = 0; c1_i150 < 6; c1_i150++) {
      c1_dv26[c1_i150] = c1_dv25[c1_i150];
    }

    c1_expWre(chartInstance, c1_dv26, c1_theta_1, c1_a);
    for (c1_i151 = 0; c1_i151 < 4; c1_i151++) {
      c1_b[c1_i151] = c1_p1[c1_i151];
    }

    c1_d_eml_scalar_eg(chartInstance);
    c1_d_eml_scalar_eg(chartInstance);
    for (c1_i152 = 0; c1_i152 < 4; c1_i152++) {
      c1_p2[c1_i152] = 0.0;
    }

    for (c1_i153 = 0; c1_i153 < 4; c1_i153++) {
      c1_p2[c1_i153] = 0.0;
    }

    for (c1_i154 = 0; c1_i154 < 4; c1_i154++) {
      c1_C[c1_i154] = c1_p2[c1_i154];
    }

    for (c1_i155 = 0; c1_i155 < 4; c1_i155++) {
      c1_p2[c1_i155] = c1_C[c1_i155];
    }

    for (c1_i156 = 0; c1_i156 < 4; c1_i156++) {
      c1_C[c1_i156] = c1_p2[c1_i156];
    }

    for (c1_i157 = 0; c1_i157 < 4; c1_i157++) {
      c1_p2[c1_i157] = c1_C[c1_i157];
    }

    for (c1_i158 = 0; c1_i158 < 4; c1_i158++) {
      c1_p2[c1_i158] = 0.0;
      c1_i159 = 0;
      for (c1_i160 = 0; c1_i160 < 4; c1_i160++) {
        c1_p2[c1_i158] += c1_a[c1_i159 + c1_i158] * c1_b[c1_i160];
        c1_i159 += 4;
      }
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 92);
    for (c1_i161 = 0; c1_i161 < 4; c1_i161++) {
      c1_d[c1_i161] = c1_p2[c1_i161] - c1_b_q2[c1_i161];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 93);
    for (c1_i162 = 0; c1_i162 < 6; c1_i162++) {
      c1_b_kx3[c1_i162] = c1_kx3[c1_i162];
    }

    for (c1_i163 = 0; c1_i163 < 4; c1_i163++) {
      c1_c_pw[c1_i163] = c1_b_pw[c1_i163];
    }

    for (c1_i164 = 0; c1_i164 < 4; c1_i164++) {
      c1_d_q2[c1_i164] = c1_b_q2[c1_i164];
    }

    for (c1_i165 = 0; c1_i165 < 4; c1_i165++) {
      c1_b_d[c1_i165] = c1_d[c1_i165];
    }

    c1_subPro3(chartInstance, c1_b_kx3, c1_c_pw, c1_d_q2, c1_b_d, c1_b_theta_3,
               &c1_b_Num_3);
    for (c1_i166 = 0; c1_i166 < 2; c1_i166++) {
      c1_theta_3[c1_i166] = c1_b_theta_3[c1_i166];
    }

    c1_Num_3 = c1_b_Num_3;
    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 94);
    for (c1_i167 = 0; c1_i167 < 2; c1_i167++) {
      c1_c_theta_3[c1_i167] = c1_theta_3[c1_i167];
    }

    c1_b_isInRange(chartInstance, c1_c_theta_3, -210.0, 90.0, c1_bv2);
    for (c1_i168 = 0; c1_i168 < 2; c1_i168++) {
      c1_bv3[c1_i168] = ((real_T)c1_bv2[c1_i168] == 1.0);
    }

    if (CV_SCRIPT_IF(0, 3, (real_T)c1_any(chartInstance, c1_bv3) == 0.0)) {
    } else {
      c1_i169 = (int32_T)c1_Num_3;
      sf_debug_for_loop_vector_check(1.0, 1.0, c1_Num_3, mxDOUBLE_CLASS, c1_i169);
      c1_loop_ub = c1_i169;
      c1_c3 = 0;
      do {
        exitg1 = 0;
        if (c1_c3 <= c1_loop_ub - 1) {
          c1_b_c3 = 1.0 + (real_T)c1_c3;
          CV_SCRIPT_FOR(0, 0, 1);
          _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 102);
          guard1 = FALSE;
          if (CV_SCRIPT_IF(0, 4, (real_T)c1_isInRange(chartInstance,
                c1_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_3", (int32_T)
                 _SFD_INTEGER_CHECK("c3", c1_b_c3), 1, 2, 1, 0) - 1], -210.0,
                90.0) == 1.0)) {
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 103);
            for (c1_i170 = 0; c1_i170 < 6; c1_i170++) {
              c1_c_kx3[c1_i170] = c1_kx3[c1_i170];
            }

            c1_expWre(chartInstance, c1_c_kx3,
                      c1_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_3", (int32_T)
                       _SFD_INTEGER_CHECK("c3", c1_b_c3), 1, 2, 1, 0) - 1], c1_a);
            for (c1_i171 = 0; c1_i171 < 4; c1_i171++) {
              c1_b[c1_i171] = c1_b_pw[c1_i171];
            }

            c1_d_eml_scalar_eg(chartInstance);
            c1_d_eml_scalar_eg(chartInstance);
            for (c1_i172 = 0; c1_i172 < 4; c1_i172++) {
              c1_p3[c1_i172] = 0.0;
            }

            for (c1_i173 = 0; c1_i173 < 4; c1_i173++) {
              c1_p3[c1_i173] = 0.0;
            }

            for (c1_i174 = 0; c1_i174 < 4; c1_i174++) {
              c1_C[c1_i174] = c1_p3[c1_i174];
            }

            for (c1_i175 = 0; c1_i175 < 4; c1_i175++) {
              c1_p3[c1_i175] = c1_C[c1_i175];
            }

            for (c1_i176 = 0; c1_i176 < 4; c1_i176++) {
              c1_C[c1_i176] = c1_p3[c1_i176];
            }

            for (c1_i177 = 0; c1_i177 < 4; c1_i177++) {
              c1_p3[c1_i177] = c1_C[c1_i177];
            }

            for (c1_i178 = 0; c1_i178 < 4; c1_i178++) {
              c1_p3[c1_i178] = 0.0;
              c1_i179 = 0;
              for (c1_i180 = 0; c1_i180 < 4; c1_i180++) {
                c1_p3[c1_i178] += c1_a[c1_i179 + c1_i178] * c1_b[c1_i180];
                c1_i179 += 4;
              }
            }

            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 104);
            for (c1_i181 = 0; c1_i181 < 6; c1_i181++) {
              c1_b_kx2[c1_i181] = c1_kx2[c1_i181];
            }

            for (c1_i182 = 0; c1_i182 < 4; c1_i182++) {
              c1_b_p3[c1_i182] = c1_p3[c1_i182];
            }

            for (c1_i183 = 0; c1_i183 < 4; c1_i183++) {
              c1_b_p2[c1_i183] = c1_p2[c1_i183];
            }

            c1_theta_2 = c1_subPro1(chartInstance, c1_b_kx2, c1_b_p3, c1_b_p2);
            _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 105);
            if (CV_SCRIPT_IF(0, 5, (real_T)c1_isInRange(chartInstance,
                  c1_theta_2, -150.0, 60.0) == 0.0)) {
              exitg1 = 1;
            } else {
              _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 110);
              for (c1_i184 = 0; c1_i184 < 6; c1_i184++) {
                c1_d_kx3[c1_i184] = -c1_kx3[c1_i184];
              }

              c1_expWre(chartInstance, c1_d_kx3,
                        c1_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_3",
                         (int32_T)_SFD_INTEGER_CHECK("c3", c1_b_c3), 1, 2, 1, 0)
                        - 1], c1_a);
              for (c1_i185 = 0; c1_i185 < 6; c1_i185++) {
                c1_c_kx2[c1_i185] = -c1_kx2[c1_i185];
              }

              c1_expWre(chartInstance, c1_c_kx2, c1_theta_2, c1_b_b);
              c1_b_eml_scalar_eg(chartInstance);
              c1_b_eml_scalar_eg(chartInstance);
              for (c1_i186 = 0; c1_i186 < 4; c1_i186++) {
                c1_i187 = 0;
                for (c1_i188 = 0; c1_i188 < 4; c1_i188++) {
                  c1_y[c1_i187 + c1_i186] = 0.0;
                  c1_i189 = 0;
                  for (c1_i190 = 0; c1_i190 < 4; c1_i190++) {
                    c1_y[c1_i187 + c1_i186] += c1_a[c1_i189 + c1_i186] *
                      c1_b_b[c1_i190 + c1_i187];
                    c1_i189 += 4;
                  }

                  c1_i187 += 4;
                }
              }

              for (c1_i191 = 0; c1_i191 < 6; c1_i191++) {
                c1_dv27[c1_i191] = c1_dv25[c1_i191];
              }

              c1_expWre(chartInstance, c1_dv27, c1_theta_1, c1_b_b);
              c1_b_eml_scalar_eg(chartInstance);
              c1_b_eml_scalar_eg(chartInstance);
              for (c1_i192 = 0; c1_i192 < 4; c1_i192++) {
                c1_i193 = 0;
                for (c1_i194 = 0; c1_i194 < 4; c1_i194++) {
                  c1_a[c1_i193 + c1_i192] = 0.0;
                  c1_i195 = 0;
                  for (c1_i196 = 0; c1_i196 < 4; c1_i196++) {
                    c1_a[c1_i193 + c1_i192] += c1_y[c1_i195 + c1_i192] *
                      c1_b_b[c1_i196 + c1_i193];
                    c1_i195 += 4;
                  }

                  c1_i193 += 4;
                }
              }

              for (c1_i197 = 0; c1_i197 < 16; c1_i197++) {
                c1_b_b[c1_i197] = c1_g1[c1_i197];
              }

              c1_b_eml_scalar_eg(chartInstance);
              c1_b_eml_scalar_eg(chartInstance);
              for (c1_i198 = 0; c1_i198 < 16; c1_i198++) {
                c1_g2[c1_i198] = 0.0;
              }

              for (c1_i199 = 0; c1_i199 < 16; c1_i199++) {
                c1_g2[c1_i199] = 0.0;
              }

              for (c1_i200 = 0; c1_i200 < 16; c1_i200++) {
                c1_b_C[c1_i200] = c1_g2[c1_i200];
              }

              for (c1_i201 = 0; c1_i201 < 16; c1_i201++) {
                c1_g2[c1_i201] = c1_b_C[c1_i201];
              }

              for (c1_i202 = 0; c1_i202 < 16; c1_i202++) {
                c1_b_C[c1_i202] = c1_g2[c1_i202];
              }

              for (c1_i203 = 0; c1_i203 < 16; c1_i203++) {
                c1_g2[c1_i203] = c1_b_C[c1_i203];
              }

              for (c1_i204 = 0; c1_i204 < 4; c1_i204++) {
                c1_i205 = 0;
                for (c1_i206 = 0; c1_i206 < 4; c1_i206++) {
                  c1_g2[c1_i205 + c1_i204] = 0.0;
                  c1_i207 = 0;
                  for (c1_i208 = 0; c1_i208 < 4; c1_i208++) {
                    c1_g2[c1_i205 + c1_i204] += c1_a[c1_i207 + c1_i204] *
                      c1_b_b[c1_i208 + c1_i205];
                    c1_i207 += 4;
                  }

                  c1_i205 += 4;
                }
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 113);
              for (c1_i209 = 0; c1_i209 < 16; c1_i209++) {
                c1_a[c1_i209] = c1_g2[c1_i209];
              }

              for (c1_i210 = 0; c1_i210 < 4; c1_i210++) {
                c1_b[c1_i210] = c1_b_q7[c1_i210];
              }

              c1_d_eml_scalar_eg(chartInstance);
              c1_d_eml_scalar_eg(chartInstance);
              for (c1_i211 = 0; c1_i211 < 4; c1_i211++) {
                c1_p4[c1_i211] = 0.0;
              }

              for (c1_i212 = 0; c1_i212 < 4; c1_i212++) {
                c1_p4[c1_i212] = 0.0;
              }

              for (c1_i213 = 0; c1_i213 < 4; c1_i213++) {
                c1_C[c1_i213] = c1_p4[c1_i213];
              }

              for (c1_i214 = 0; c1_i214 < 4; c1_i214++) {
                c1_p4[c1_i214] = c1_C[c1_i214];
              }

              for (c1_i215 = 0; c1_i215 < 4; c1_i215++) {
                c1_C[c1_i215] = c1_p4[c1_i215];
              }

              for (c1_i216 = 0; c1_i216 < 4; c1_i216++) {
                c1_p4[c1_i216] = c1_C[c1_i216];
              }

              for (c1_i217 = 0; c1_i217 < 4; c1_i217++) {
                c1_p4[c1_i217] = 0.0;
                c1_i218 = 0;
                for (c1_i219 = 0; c1_i219 < 4; c1_i219++) {
                  c1_p4[c1_i217] += c1_a[c1_i218 + c1_i217] * c1_b[c1_i219];
                  c1_i218 += 4;
                }
              }

              _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 114);
              for (c1_i220 = 0; c1_i220 < 6; c1_i220++) {
                c1_b_kx4[c1_i220] = c1_kx4[c1_i220];
              }

              for (c1_i221 = 0; c1_i221 < 6; c1_i221++) {
                c1_b_kx5[c1_i221] = c1_kx5[c1_i221];
              }

              for (c1_i222 = 0; c1_i222 < 4; c1_i222++) {
                c1_c_q7[c1_i222] = c1_b_q7[c1_i222];
              }

              for (c1_i223 = 0; c1_i223 < 4; c1_i223++) {
                c1_b_p4[c1_i223] = c1_p4[c1_i223];
              }

              c1_subPro2(chartInstance, c1_b_kx4, c1_b_kx5, c1_c_q7, c1_b_p4,
                         c1_b_theta_3, c1_b_theta_5, &c1_b_Num_45);
              for (c1_i224 = 0; c1_i224 < 2; c1_i224++) {
                c1_theta_4[c1_i224] = c1_b_theta_3[c1_i224];
              }

              for (c1_i225 = 0; c1_i225 < 2; c1_i225++) {
                c1_theta_5[c1_i225] = c1_b_theta_5[c1_i225];
              }

              c1_Num_45 = c1_b_Num_45;
              _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 116);
              for (c1_i226 = 0; c1_i226 < 2; c1_i226++) {
                c1_c_theta_5[c1_i226] = c1_theta_5[c1_i226];
              }

              c1_b_isInRange(chartInstance, c1_c_theta_5, -140.0, 140.0, c1_bv2);
              for (c1_i227 = 0; c1_i227 < 2; c1_i227++) {
                c1_bv4[c1_i227] = ((real_T)c1_bv2[c1_i227] == 1.0);
              }

              if (CV_SCRIPT_IF(0, 6, (real_T)c1_any(chartInstance, c1_bv4) ==
                               0.0)) {
                exitg1 = 1;
              } else {
                c1_i228 = (int32_T)c1_Num_45;
                sf_debug_for_loop_vector_check(1.0, 1.0, c1_Num_45,
                  mxDOUBLE_CLASS, c1_i228);
                c1_b_loop_ub = c1_i228;
                c1_c45 = 0;
                while (c1_c45 <= c1_b_loop_ub - 1) {
                  c1_b_c45 = 1.0 + (real_T)c1_c45;
                  CV_SCRIPT_FOR(0, 1, 1);
                  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 122);
                  if (CV_SCRIPT_IF(0, 7, (real_T)c1_isInRange(chartInstance,
                        c1_theta_5[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_5",
                         (int32_T)_SFD_INTEGER_CHECK("c45", c1_b_c45), 1, 2, 1,
                         0) - 1], -140.0, 140.0) == 1.0)) {
                    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 123);
                    for (c1_i229 = 0; c1_i229 < 6; c1_i229++) {
                      c1_c_kx5[c1_i229] = -c1_kx5[c1_i229];
                    }

                    c1_expWre(chartInstance, c1_c_kx5,
                              c1_theta_5[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_5",
                               (int32_T)_SFD_INTEGER_CHECK("c45", c1_b_c45), 1,
                               2, 1, 0) - 1], c1_a);
                    for (c1_i230 = 0; c1_i230 < 6; c1_i230++) {
                      c1_c_kx4[c1_i230] = -c1_kx4[c1_i230];
                    }

                    c1_expWre(chartInstance, c1_c_kx4,
                              c1_theta_4[_SFD_EML_ARRAY_BOUNDS_CHECK("theta_4",
                               (int32_T)_SFD_INTEGER_CHECK("c45", c1_b_c45), 1,
                               2, 1, 0) - 1], c1_b_b);
                    c1_b_eml_scalar_eg(chartInstance);
                    c1_b_eml_scalar_eg(chartInstance);
                    for (c1_i231 = 0; c1_i231 < 4; c1_i231++) {
                      c1_i232 = 0;
                      for (c1_i233 = 0; c1_i233 < 4; c1_i233++) {
                        c1_y[c1_i232 + c1_i231] = 0.0;
                        c1_i234 = 0;
                        for (c1_i235 = 0; c1_i235 < 4; c1_i235++) {
                          c1_y[c1_i232 + c1_i231] += c1_a[c1_i234 + c1_i231] *
                            c1_b_b[c1_i235 + c1_i232];
                          c1_i234 += 4;
                        }

                        c1_i232 += 4;
                      }
                    }

                    for (c1_i236 = 0; c1_i236 < 16; c1_i236++) {
                      c1_b_b[c1_i236] = c1_g2[c1_i236];
                    }

                    c1_b_eml_scalar_eg(chartInstance);
                    c1_b_eml_scalar_eg(chartInstance);
                    for (c1_i237 = 0; c1_i237 < 16; c1_i237++) {
                      c1_g3[c1_i237] = 0.0;
                    }

                    for (c1_i238 = 0; c1_i238 < 16; c1_i238++) {
                      c1_g3[c1_i238] = 0.0;
                    }

                    for (c1_i239 = 0; c1_i239 < 16; c1_i239++) {
                      c1_b_C[c1_i239] = c1_g3[c1_i239];
                    }

                    for (c1_i240 = 0; c1_i240 < 16; c1_i240++) {
                      c1_g3[c1_i240] = c1_b_C[c1_i240];
                    }

                    for (c1_i241 = 0; c1_i241 < 16; c1_i241++) {
                      c1_b_C[c1_i241] = c1_g3[c1_i241];
                    }

                    for (c1_i242 = 0; c1_i242 < 16; c1_i242++) {
                      c1_g3[c1_i242] = c1_b_C[c1_i242];
                    }

                    for (c1_i243 = 0; c1_i243 < 4; c1_i243++) {
                      c1_i244 = 0;
                      for (c1_i245 = 0; c1_i245 < 4; c1_i245++) {
                        c1_g3[c1_i244 + c1_i243] = 0.0;
                        c1_i246 = 0;
                        for (c1_i247 = 0; c1_i247 < 4; c1_i247++) {
                          c1_g3[c1_i244 + c1_i243] += c1_y[c1_i246 + c1_i243] *
                            c1_b_b[c1_i247 + c1_i244];
                          c1_i246 += 4;
                        }

                        c1_i244 += 4;
                      }
                    }

                    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 125);
                    for (c1_i248 = 0; c1_i248 < 16; c1_i248++) {
                      c1_a[c1_i248] = c1_g3[c1_i248];
                    }

                    for (c1_i249 = 0; c1_i249 < 4; c1_i249++) {
                      c1_b[c1_i249] = c1_b_q3[c1_i249];
                    }

                    c1_d_eml_scalar_eg(chartInstance);
                    c1_d_eml_scalar_eg(chartInstance);
                    for (c1_i250 = 0; c1_i250 < 4; c1_i250++) {
                      c1_p5[c1_i250] = 0.0;
                    }

                    for (c1_i251 = 0; c1_i251 < 4; c1_i251++) {
                      c1_p5[c1_i251] = 0.0;
                    }

                    for (c1_i252 = 0; c1_i252 < 4; c1_i252++) {
                      c1_C[c1_i252] = c1_p5[c1_i252];
                    }

                    for (c1_i253 = 0; c1_i253 < 4; c1_i253++) {
                      c1_p5[c1_i253] = c1_C[c1_i253];
                    }

                    for (c1_i254 = 0; c1_i254 < 4; c1_i254++) {
                      c1_C[c1_i254] = c1_p5[c1_i254];
                    }

                    for (c1_i255 = 0; c1_i255 < 4; c1_i255++) {
                      c1_p5[c1_i255] = c1_C[c1_i255];
                    }

                    for (c1_i256 = 0; c1_i256 < 4; c1_i256++) {
                      c1_p5[c1_i256] = 0.0;
                      c1_i257 = 0;
                      for (c1_i258 = 0; c1_i258 < 4; c1_i258++) {
                        c1_p5[c1_i256] += c1_a[c1_i257 + c1_i256] * c1_b[c1_i258];
                        c1_i257 += 4;
                      }
                    }

                    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 126);
                    for (c1_i259 = 0; c1_i259 < 6; c1_i259++) {
                      c1_b_kx6[c1_i259] = c1_kx6[c1_i259];
                    }

                    for (c1_i260 = 0; c1_i260 < 4; c1_i260++) {
                      c1_d_q3[c1_i260] = c1_b_q3[c1_i260];
                    }

                    for (c1_i261 = 0; c1_i261 < 4; c1_i261++) {
                      c1_b_p5[c1_i261] = c1_p5[c1_i261];
                    }

                    c1_theta_6 = c1_subPro1(chartInstance, c1_b_kx6, c1_d_q3,
                      c1_b_p5);
                    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 128U);
                    (*c1_Num)++;
                    _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 129U);
                    c1_b_Num = _SFD_EML_ARRAY_BOUNDS_CHECK("theta", (int32_T)
                      _SFD_INTEGER_CHECK("Num", *c1_Num), 1, 4, 2, 0) - 1;
                    c1_b_theta_1[0] = c1_theta_1;
                    c1_b_theta_1[1] = c1_theta_2;
                    c1_b_theta_1[2] = c1_theta_3[_SFD_EML_ARRAY_BOUNDS_CHECK(
                      "theta_3", (int32_T)_SFD_INTEGER_CHECK("c3", c1_b_c3), 1,
                      2, 1, 0) - 1];
                    c1_b_theta_1[3] = c1_theta_4[_SFD_EML_ARRAY_BOUNDS_CHECK(
                      "theta_4", (int32_T)_SFD_INTEGER_CHECK("c45", c1_b_c45), 1,
                      2, 1, 0) - 1];
                    c1_b_theta_1[4] = c1_theta_5[_SFD_EML_ARRAY_BOUNDS_CHECK(
                      "theta_5", (int32_T)_SFD_INTEGER_CHECK("c45", c1_b_c45), 1,
                      2, 1, 0) - 1];
                    c1_b_theta_1[5] = c1_theta_6;
                    for (c1_i262 = 0; c1_i262 < 6; c1_i262++) {
                      c1_theta[c1_i262 + 6 * c1_b_Num] = c1_b_theta_1[c1_i262];
                    }
                  }

                  c1_c45++;
                  sf_mex_listen_for_ctrl_c(chartInstance->S);
                }

                CV_SCRIPT_FOR(0, 1, 0);
                guard1 = TRUE;
              }
            }
          } else {
            guard1 = TRUE;
          }

          if (guard1 == TRUE) {
            c1_c3++;
            sf_mex_listen_for_ctrl_c(chartInstance->S);
          }
        } else {
          CV_SCRIPT_FOR(0, 0, 0);
          exitg1 = 1;
        }
      } while (exitg1 == 0U);
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -129);
  sf_debug_symbol_scope_pop();
}

static void c1_cross(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                     *chartInstance, real_T c1_a[3], real_T c1_b[3], real_T
                     c1_c[3])
{
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_y;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_b_y;
  real_T c1_c1;
  real_T c1_d_a;
  real_T c1_d_b;
  real_T c1_c_y;
  real_T c1_e_a;
  real_T c1_e_b;
  real_T c1_d_y;
  real_T c1_c2;
  real_T c1_f_a;
  real_T c1_f_b;
  real_T c1_e_y;
  real_T c1_g_a;
  real_T c1_g_b;
  real_T c1_f_y;
  real_T c1_c3;
  c1_b_a = c1_a[1];
  c1_b_b = c1_b[2];
  c1_y = c1_b_a * c1_b_b;
  c1_c_a = c1_a[2];
  c1_c_b = c1_b[1];
  c1_b_y = c1_c_a * c1_c_b;
  c1_c1 = c1_y - c1_b_y;
  c1_d_a = c1_a[2];
  c1_d_b = c1_b[0];
  c1_c_y = c1_d_a * c1_d_b;
  c1_e_a = c1_a[0];
  c1_e_b = c1_b[2];
  c1_d_y = c1_e_a * c1_e_b;
  c1_c2 = c1_c_y - c1_d_y;
  c1_f_a = c1_a[0];
  c1_f_b = c1_b[1];
  c1_e_y = c1_f_a * c1_f_b;
  c1_g_a = c1_a[1];
  c1_g_b = c1_b[0];
  c1_f_y = c1_g_a * c1_g_b;
  c1_c3 = c1_e_y - c1_f_y;
  c1_c[0] = c1_c1;
  c1_c[1] = c1_c2;
  c1_c[2] = c1_c3;
}

static boolean_T c1_all(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, boolean_T c1_x[2])
{
  boolean_T c1_y;
  int32_T c1_k;
  real_T c1_b_k;
  boolean_T exitg1;
  c1_y = TRUE;
  c1_k = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (c1_k < 2)) {
    c1_b_k = 1.0 + (real_T)c1_k;
    if ((real_T)c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
         ("", c1_b_k), 1, 2, 1, 0) - 1] == 0.0) {
      c1_y = FALSE;
      exitg1 = TRUE;
    } else {
      c1_k++;
    }
  }

  return c1_y;
}

static void c1_mrdivide(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_B[16], real_T c1_y[16])
{
  int32_T c1_i263;
  int32_T c1_i264;
  int32_T c1_i265;
  int32_T c1_i266;
  real_T c1_b_A[16];
  int32_T c1_i267;
  int32_T c1_i268;
  int32_T c1_i269;
  int32_T c1_i270;
  real_T c1_b_B[16];
  int32_T c1_info;
  int32_T c1_ipiv[4];
  int32_T c1_b_info;
  int32_T c1_c_info;
  int32_T c1_d_info;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_ip;
  int32_T c1_j;
  int32_T c1_b_j;
  real_T c1_temp;
  int32_T c1_i271;
  real_T c1_c_A[16];
  int32_T c1_c_j;
  int32_T c1_d_j;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_b;
  int32_T c1_jBcol;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_b_a;
  int32_T c1_c_c;
  int32_T c1_c_b;
  int32_T c1_d_c;
  int32_T c1_d_b;
  int32_T c1_kAcol;
  int32_T c1_c_a;
  int32_T c1_e_b;
  int32_T c1_e_c;
  int32_T c1_d_a;
  int32_T c1_f_b;
  int32_T c1_f_c;
  int32_T c1_e_a;
  int32_T c1_g_b;
  int32_T c1_g_c;
  int32_T c1_f_a;
  int32_T c1_h_b;
  int32_T c1_h_c;
  real_T c1_x;
  real_T c1_b_y;
  real_T c1_z;
  int32_T c1_g_a;
  int32_T c1_i272;
  int32_T c1_c_i;
  int32_T c1_d_i;
  int32_T c1_h_a;
  int32_T c1_i_b;
  int32_T c1_i_c;
  int32_T c1_i_a;
  int32_T c1_j_b;
  int32_T c1_j_c;
  int32_T c1_j_a;
  int32_T c1_k_b;
  int32_T c1_k_c;
  int32_T c1_k_a;
  int32_T c1_l_b;
  int32_T c1_l_c;
  int32_T c1_i273;
  int32_T c1_i274;
  int32_T c1_i275;
  int32_T c1_i276;
  c1_i263 = 0;
  for (c1_i264 = 0; c1_i264 < 4; c1_i264++) {
    c1_i265 = 0;
    for (c1_i266 = 0; c1_i266 < 4; c1_i266++) {
      c1_b_A[c1_i266 + c1_i263] = c1_B[c1_i265 + c1_i264];
      c1_i265 += 4;
    }

    c1_i263 += 4;
  }

  c1_i267 = 0;
  for (c1_i268 = 0; c1_i268 < 4; c1_i268++) {
    c1_i269 = 0;
    for (c1_i270 = 0; c1_i270 < 4; c1_i270++) {
      c1_b_B[c1_i270 + c1_i267] = c1_A[c1_i269 + c1_i268];
      c1_i269 += 4;
    }

    c1_i267 += 4;
  }

  c1_c_eml_matlab_zgetrf(chartInstance, c1_b_A, c1_ipiv, &c1_info);
  c1_b_info = c1_info;
  c1_c_info = c1_b_info;
  c1_d_info = c1_c_info;
  if ((real_T)c1_d_info > 0.0) {
    c1_eml_warning(chartInstance);
  }

  c1_b_eml_scalar_eg(chartInstance);
  c1_c_eml_int_forloop_overflow_check(chartInstance);
  for (c1_i = 1; c1_i < 5; c1_i++) {
    c1_b_i = c1_i;
    if (c1_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_i), 1, 4, 1, 0) - 1] != c1_b_i) {
      c1_ip = c1_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) - 1];
      c1_c_eml_int_forloop_overflow_check(chartInstance);
      for (c1_j = 1; c1_j < 5; c1_j++) {
        c1_b_j = c1_j;
        c1_temp = c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 4, 1, 0) +
                          ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
        c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c1_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                   "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 2,
                   0) - 1) << 2)) - 1] = c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ip), 1, 4, 1, 0) +
          ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
        c1_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                  (real_T)c1_ip), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                   (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_j), 1, 4, 2, 0)
                  - 1) << 2)) - 1] = c1_temp;
      }
    }
  }

  for (c1_i271 = 0; c1_i271 < 16; c1_i271++) {
    c1_c_A[c1_i271] = c1_b_A[c1_i271];
  }

  c1_b_eml_xtrsm(chartInstance, c1_c_A, c1_b_B);
  c1_below_threshold(chartInstance);
  c1_c_eml_scalar_eg(chartInstance);
  c1_c_eml_int_forloop_overflow_check(chartInstance);
  for (c1_c_j = 1; c1_c_j < 5; c1_c_j++) {
    c1_d_j = c1_c_j;
    c1_a = c1_d_j;
    c1_c = c1_a;
    c1_b = c1_c - 1;
    c1_b_c = c1_b << 2;
    c1_b_b = c1_b_c;
    c1_jBcol = c1_b_b;
    c1_e_eml_int_forloop_overflow_check(chartInstance);
    for (c1_k = 4; c1_k > 0; c1_k--) {
      c1_b_k = c1_k;
      c1_b_a = c1_b_k;
      c1_c_c = c1_b_a;
      c1_c_b = c1_c_c - 1;
      c1_d_c = c1_c_b << 2;
      c1_d_b = c1_d_c;
      c1_kAcol = c1_d_b;
      c1_c_a = c1_b_k;
      c1_e_b = c1_jBcol;
      c1_e_c = c1_c_a + c1_e_b;
      if (c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_e_c), 1, 16, 1, 0) - 1] != 0.0) {
        c1_d_a = c1_b_k;
        c1_f_b = c1_jBcol;
        c1_f_c = c1_d_a + c1_f_b;
        c1_e_a = c1_b_k;
        c1_g_b = c1_jBcol;
        c1_g_c = c1_e_a + c1_g_b;
        c1_f_a = c1_b_k;
        c1_h_b = c1_kAcol;
        c1_h_c = c1_f_a + c1_h_b;
        c1_x = c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_g_c), 1, 16, 1, 0) - 1];
        c1_b_y = c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_h_c), 1, 16, 1, 0) - 1];
        c1_z = c1_x / c1_b_y;
        c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_f_c), 1, 16, 1, 0) - 1] = c1_z;
        c1_g_a = c1_b_k - 1;
        c1_i272 = c1_g_a;
        c1_d_eml_int_forloop_overflow_check(chartInstance, 1, c1_i272);
        for (c1_c_i = 1; c1_c_i <= c1_i272; c1_c_i++) {
          c1_d_i = c1_c_i;
          c1_h_a = c1_d_i;
          c1_i_b = c1_jBcol;
          c1_i_c = c1_h_a + c1_i_b;
          c1_i_a = c1_d_i;
          c1_j_b = c1_jBcol;
          c1_j_c = c1_i_a + c1_j_b;
          c1_j_a = c1_b_k;
          c1_k_b = c1_jBcol;
          c1_k_c = c1_j_a + c1_k_b;
          c1_k_a = c1_d_i;
          c1_l_b = c1_kAcol;
          c1_l_c = c1_k_a + c1_l_b;
          c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_i_c), 1, 16, 1, 0) - 1] =
            c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c1_j_c), 1, 16, 1, 0) - 1] -
            c1_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c1_k_c), 1, 16, 1, 0) - 1] *
            c1_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c1_l_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }

  c1_i273 = 0;
  for (c1_i274 = 0; c1_i274 < 4; c1_i274++) {
    c1_i275 = 0;
    for (c1_i276 = 0; c1_i276 < 4; c1_i276++) {
      c1_y[c1_i276 + c1_i273] = c1_b_B[c1_i275 + c1_i274];
      c1_i275 += 4;
    }

    c1_i273 += 4;
  }
}

static void c1_realmin(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static void c1_eps(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                   *chartInstance)
{
}

static void c1_eml_matlab_zgetrf(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_b_A[16], int32_T c1_ipiv[4],
  int32_T *c1_info)
{
  int32_T c1_i277;
  for (c1_i277 = 0; c1_i277 < 16; c1_i277++) {
    c1_b_A[c1_i277] = c1_A[c1_i277];
  }

  c1_c_eml_matlab_zgetrf(chartInstance, c1_b_A, c1_ipiv, c1_info);
}

static void c1_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static int32_T c1_eml_ixamax(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, int32_T c1_n, real_T c1_x[16], int32_T c1_ix0)
{
  int32_T c1_idxmax;
  int32_T c1_b_n;
  int32_T c1_b_ix0;
  int32_T c1_c_n;
  int32_T c1_c_ix0;
  int32_T c1_ix;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_y;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_b_y;
  real_T c1_smax;
  int32_T c1_loop_ub;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_a;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_c_y;
  real_T c1_j_x;
  real_T c1_k_x;
  real_T c1_d_y;
  real_T c1_s;
  c1_b_n = c1_n;
  c1_b_ix0 = c1_ix0;
  c1_c_n = c1_b_n;
  c1_c_ix0 = c1_b_ix0;
  if ((real_T)c1_c_n < 1.0) {
    c1_idxmax = 0;
  } else {
    c1_idxmax = 1;
    if ((real_T)c1_c_n > 1.0) {
      c1_ix = c1_c_ix0;
      c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c1_ix), 1, 16, 1, 0) - 1];
      c1_c_x = c1_b_x;
      c1_d_x = c1_c_x;
      c1_y = muDoubleScalarAbs(c1_d_x);
      c1_e_x = 0.0;
      c1_f_x = c1_e_x;
      c1_b_y = muDoubleScalarAbs(c1_f_x);
      c1_smax = c1_y + c1_b_y;
      c1_b_eml_int_forloop_overflow_check(chartInstance, c1_c_n);
      c1_loop_ub = c1_c_n;
      for (c1_k = 2; c1_k <= c1_loop_ub; c1_k++) {
        c1_b_k = c1_k;
        c1_a = c1_ix + 1;
        c1_ix = c1_a;
        c1_g_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1];
        c1_h_x = c1_g_x;
        c1_i_x = c1_h_x;
        c1_c_y = muDoubleScalarAbs(c1_i_x);
        c1_j_x = 0.0;
        c1_k_x = c1_j_x;
        c1_d_y = muDoubleScalarAbs(c1_k_x);
        c1_s = c1_c_y + c1_d_y;
        if (c1_s > c1_smax) {
          c1_idxmax = c1_b_k;
          c1_smax = c1_s;
        }
      }
    }
  }

  return c1_idxmax;
}

static void c1_b_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, int32_T c1_b)
{
  int32_T c1_b_b;
  boolean_T c1_overflow;
  boolean_T c1_safe;
  int32_T c1_i278;
  static char_T c1_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i279;
  static char_T c1_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  c1_b_b = c1_b;
  if (2 > c1_b_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  c1_safe = !c1_overflow;
  if (c1_safe) {
  } else {
    for (c1_i278 = 0; c1_i278 < 34; c1_i278++) {
      c1_u[c1_i278] = c1_cv0[c1_i278];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c1_i279 = 0; c1_i279 < 5; c1_i279++) {
      c1_b_u[c1_i279] = c1_cv1[c1_i279];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c1_y, 14, c1_b_y));
  }
}

static void c1_c_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static void c1_d_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, int32_T c1_a,
   int32_T c1_b)
{
  int32_T c1_b_a;
  int32_T c1_b_b;
  boolean_T c1_overflow;
  boolean_T c1_safe;
  int32_T c1_i280;
  static char_T c1_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i281;
  static char_T c1_cv3[5] = { 'i', 'n', 't', '3', '2' };

  char_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  c1_b_a = c1_a;
  c1_b_b = c1_b;
  if (c1_b_a > c1_b_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_b_b > 2147483646);
  }

  c1_safe = !c1_overflow;
  if (c1_safe) {
  } else {
    for (c1_i280 = 0; c1_i280 < 34; c1_i280++) {
      c1_u[c1_i280] = c1_cv2[c1_i280];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c1_i281 = 0; c1_i281 < 5; c1_i281++) {
      c1_b_u[c1_i281] = c1_cv3[c1_i281];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c1_y, 14, c1_b_y));
  }
}

static void c1_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static void c1_eml_warning(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
  int32_T c1_i282;
  static char_T c1_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c1_u[27];
  const mxArray *c1_y = NULL;
  for (c1_i282 = 0; c1_i282 < 27; c1_i282++) {
    c1_u[c1_i282] = c1_varargin_1[c1_i282];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c1_y));
}

static void c1_b_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static void c1_eml_xtrsm(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_B[16], real_T c1_b_B[16])
{
  int32_T c1_i283;
  int32_T c1_i284;
  real_T c1_b_A[16];
  for (c1_i283 = 0; c1_i283 < 16; c1_i283++) {
    c1_b_B[c1_i283] = c1_B[c1_i283];
  }

  for (c1_i284 = 0; c1_i284 < 16; c1_i284++) {
    c1_b_A[c1_i284] = c1_A[c1_i284];
  }

  c1_b_eml_xtrsm(chartInstance, c1_b_A, c1_b_B);
}

static void c1_below_threshold(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static void c1_c_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static void c1_e_eml_int_forloop_overflow_check
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

static void c1_d_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static real_T c1_atan2(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_y, real_T c1_x)
{
  real_T c1_b_y;
  real_T c1_b_x;
  c1_eml_scalar_eg(chartInstance);
  c1_b_y = c1_y;
  c1_b_x = c1_x;
  return muDoubleScalarAtan2(c1_b_y, c1_b_x);
}

static boolean_T c1_isInRange(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_x, real_T c1_xmin, real_T c1_xmax)
{
  boolean_T c1_isIn;
  uint32_T c1_debug_family_var_map[6];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  real_T c1_A;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_a;
  boolean_T c1_b1;
  boolean_T c1_b2;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c1_b_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_x, 2U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_xmin, 3U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_xmax, 4U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_isIn, 5U, c1_h_sf_marshallOut,
    c1_g_sf_marshallIn);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 141U);
  c1_A = c1_x;
  c1_b_x = c1_A;
  c1_c_x = c1_b_x;
  c1_y = c1_c_x / 3.1415926535897931;
  c1_a = c1_y;
  c1_x = c1_a * 180.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 142U);
  c1_b1 = (c1_x >= c1_xmin);
  c1_b2 = (c1_x <= c1_xmax);
  c1_isIn = (c1_b1 && c1_b2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -142);
  sf_debug_symbol_scope_pop();
  return c1_isIn;
}

static void c1_expWre(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                      *chartInstance, real_T c1_kx[6], real_T c1_theta, real_T
                      c1_g[16])
{
  uint32_T c1_debug_family_var_map[9];
  real_T c1_v[3];
  real_T c1_w[3];
  real_T c1_R[9];
  real_T c1_p[3];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i285;
  int32_T c1_i286;
  real_T c1_dv28[9];
  int32_T c1_i287;
  int32_T c1_i288;
  real_T c1_b[3];
  real_T c1_b_b;
  int32_T c1_i289;
  int32_T c1_i290;
  real_T c1_b_w[3];
  real_T c1_dv29[9];
  int32_T c1_i291;
  real_T c1_a[9];
  int32_T c1_i292;
  int32_T c1_i293;
  real_T c1_c_w[3];
  int32_T c1_i294;
  real_T c1_b_v[3];
  int32_T c1_i295;
  real_T c1_y[3];
  int32_T c1_i296;
  int32_T c1_i297;
  int32_T c1_i298;
  int32_T c1_i299;
  real_T c1_c_b[3];
  int32_T c1_i300;
  int32_T c1_i301;
  int32_T c1_i302;
  int32_T c1_i303;
  int32_T c1_i304;
  real_T c1_b_y[3];
  int32_T c1_i305;
  int32_T c1_i306;
  real_T c1_d_b;
  int32_T c1_i307;
  int32_T c1_i308;
  int32_T c1_i309;
  int32_T c1_i310;
  int32_T c1_i311;
  int32_T c1_i312;
  int32_T c1_i313;
  int32_T c1_i314;
  int32_T c1_i315;
  static real_T c1_dv30[4] = { 0.0, 0.0, 0.0, 1.0 };

  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c1_e_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_v, 0U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 1U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_R, 2U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p, 3U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 4U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 5U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 7U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_g, 8U, c1_g_sf_marshallOut,
    c1_f_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 5);
  CV_SCRIPT_IF(1, 0, FALSE);
  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 9);
  for (c1_i285 = 0; c1_i285 < 3; c1_i285++) {
    c1_v[c1_i285] = c1_kx[c1_i285];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 10);
  for (c1_i286 = 0; c1_i286 < 3; c1_i286++) {
    c1_w[c1_i286] = c1_kx[c1_i286 + 3];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 12);
  guard1 = FALSE;
  guard2 = FALSE;
  if (CV_SCRIPT_COND(1, 0, c1_w[0] == 0.0)) {
    if (CV_SCRIPT_COND(1, 1, c1_w[1] == 0.0)) {
      if (CV_SCRIPT_COND(1, 2, c1_w[2] == 0.0)) {
        CV_SCRIPT_MCDC(1, 0, TRUE);
        CV_SCRIPT_IF(1, 1, TRUE);
        _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 13);
        c1_eye(chartInstance, c1_dv28);
        for (c1_i287 = 0; c1_i287 < 9; c1_i287++) {
          c1_R[c1_i287] = c1_dv28[c1_i287];
        }

        _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 14);
        for (c1_i288 = 0; c1_i288 < 3; c1_i288++) {
          c1_b[c1_i288] = c1_v[c1_i288];
        }

        c1_b_b = c1_theta;
        for (c1_i289 = 0; c1_i289 < 3; c1_i289++) {
          c1_p[c1_i289] = c1_b[c1_i289] * c1_b_b;
        }
      } else {
        guard1 = TRUE;
      }
    } else {
      guard2 = TRUE;
    }
  } else {
    guard2 = TRUE;
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_SCRIPT_MCDC(1, 0, FALSE);
    CV_SCRIPT_IF(1, 1, FALSE);
    _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 16);
    for (c1_i290 = 0; c1_i290 < 3; c1_i290++) {
      c1_b_w[c1_i290] = c1_w[c1_i290];
    }

    c1_expRot(chartInstance, c1_b_w, c1_theta, c1_dv29);
    for (c1_i291 = 0; c1_i291 < 9; c1_i291++) {
      c1_R[c1_i291] = c1_dv29[c1_i291];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 17);
    c1_eye(chartInstance, c1_a);
    for (c1_i292 = 0; c1_i292 < 9; c1_i292++) {
      c1_a[c1_i292] -= c1_R[c1_i292];
    }

    for (c1_i293 = 0; c1_i293 < 3; c1_i293++) {
      c1_c_w[c1_i293] = c1_w[c1_i293];
    }

    for (c1_i294 = 0; c1_i294 < 3; c1_i294++) {
      c1_b_v[c1_i294] = c1_v[c1_i294];
    }

    c1_cross(chartInstance, c1_c_w, c1_b_v, c1_b);
    c1_f_eml_scalar_eg(chartInstance);
    c1_f_eml_scalar_eg(chartInstance);
    for (c1_i295 = 0; c1_i295 < 3; c1_i295++) {
      c1_y[c1_i295] = 0.0;
      c1_i296 = 0;
      for (c1_i297 = 0; c1_i297 < 3; c1_i297++) {
        c1_y[c1_i295] += c1_a[c1_i296 + c1_i295] * c1_b[c1_i297];
        c1_i296 += 3;
      }
    }

    for (c1_i298 = 0; c1_i298 < 3; c1_i298++) {
      c1_b[c1_i298] = c1_w[c1_i298];
    }

    for (c1_i299 = 0; c1_i299 < 3; c1_i299++) {
      c1_c_b[c1_i299] = c1_w[c1_i299];
    }

    c1_i300 = 0;
    for (c1_i301 = 0; c1_i301 < 3; c1_i301++) {
      for (c1_i302 = 0; c1_i302 < 3; c1_i302++) {
        c1_a[c1_i302 + c1_i300] = c1_b[c1_i302] * c1_c_b[c1_i301];
      }

      c1_i300 += 3;
    }

    for (c1_i303 = 0; c1_i303 < 3; c1_i303++) {
      c1_b[c1_i303] = c1_v[c1_i303];
    }

    c1_f_eml_scalar_eg(chartInstance);
    c1_f_eml_scalar_eg(chartInstance);
    for (c1_i304 = 0; c1_i304 < 3; c1_i304++) {
      c1_b_y[c1_i304] = 0.0;
      c1_i305 = 0;
      for (c1_i306 = 0; c1_i306 < 3; c1_i306++) {
        c1_b_y[c1_i304] += c1_a[c1_i305 + c1_i304] * c1_b[c1_i306];
        c1_i305 += 3;
      }
    }

    c1_d_b = c1_theta;
    for (c1_i307 = 0; c1_i307 < 3; c1_i307++) {
      c1_b_y[c1_i307] *= c1_d_b;
    }

    for (c1_i308 = 0; c1_i308 < 3; c1_i308++) {
      c1_p[c1_i308] = c1_y[c1_i308] + c1_b_y[c1_i308];
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, 19);
  c1_i309 = 0;
  c1_i310 = 0;
  for (c1_i311 = 0; c1_i311 < 3; c1_i311++) {
    for (c1_i312 = 0; c1_i312 < 3; c1_i312++) {
      c1_g[c1_i312 + c1_i309] = c1_R[c1_i312 + c1_i310];
    }

    c1_i309 += 4;
    c1_i310 += 3;
  }

  for (c1_i313 = 0; c1_i313 < 3; c1_i313++) {
    c1_g[c1_i313 + 12] = c1_p[c1_i313];
  }

  c1_i314 = 0;
  for (c1_i315 = 0; c1_i315 < 4; c1_i315++) {
    c1_g[c1_i314 + 3] = c1_dv30[c1_i315];
    c1_i314 += 4;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c1_sfEvent, -19);
  sf_debug_symbol_scope_pop();
}

static void c1_eye(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                   *chartInstance, real_T c1_I[9])
{
  int32_T c1_i316;
  int32_T c1_i;
  int32_T c1_b_i;
  for (c1_i316 = 0; c1_i316 < 9; c1_i316++) {
    c1_I[c1_i316] = 0.0;
  }

  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_i = 1; c1_i < 4; c1_i++) {
    c1_b_i = c1_i;
    c1_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_i), 1, 3, 2, 0) - 1)) -
      1] = 1.0;
  }
}

static void c1_expRot(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                      *chartInstance, real_T c1_w[3], real_T c1_theta, real_T
                      c1_R[9])
{
  uint32_T c1_debug_family_var_map[6];
  real_T c1_wh[9];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i317;
  real_T c1_b_w[3];
  uint32_T c1_b_debug_family_var_map[4];
  real_T c1_b_nargin = 1.0;
  real_T c1_b_nargout = 1.0;
  real_T c1_x;
  real_T c1_b_x;
  int32_T c1_i318;
  real_T c1_a[9];
  real_T c1_b;
  int32_T c1_i319;
  int32_T c1_i320;
  real_T c1_b_a[9];
  int32_T c1_i321;
  real_T c1_b_b[9];
  int32_T c1_i322;
  int32_T c1_i323;
  int32_T c1_i324;
  real_T c1_y[9];
  int32_T c1_i325;
  int32_T c1_i326;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_c_b;
  int32_T c1_i327;
  int32_T c1_i328;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c1_d_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_wh, 0U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 1U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 2U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 3U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 4U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_R, 5U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 9);
  for (c1_i317 = 0; c1_i317 < 3; c1_i317++) {
    c1_b_w[c1_i317] = c1_w[c1_i317];
  }

  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c1_c_debug_family_names,
    c1_b_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargin, 0U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_b_nargout, 1U,
    c1_e_sf_marshallOut, c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_w, 2U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_wh, 3U, c1_c_sf_marshallOut,
    c1_c_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 3);
  CV_SCRIPT_IF(3, 0, FALSE);
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, 20);
  c1_wh[0] = 0.0;
  c1_wh[3] = -c1_b_w[2];
  c1_wh[6] = c1_b_w[1];
  c1_wh[1] = c1_b_w[2];
  c1_wh[4] = 0.0;
  c1_wh[7] = -c1_b_w[0];
  c1_wh[2] = -c1_b_w[1];
  c1_wh[5] = c1_b_w[0];
  c1_wh[8] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c1_sfEvent, -20);
  sf_debug_symbol_scope_pop();
  _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, 10);
  c1_x = c1_theta;
  c1_b_x = c1_x;
  c1_b_x = muDoubleScalarSin(c1_b_x);
  for (c1_i318 = 0; c1_i318 < 9; c1_i318++) {
    c1_a[c1_i318] = c1_wh[c1_i318];
  }

  c1_b = c1_b_x;
  for (c1_i319 = 0; c1_i319 < 9; c1_i319++) {
    c1_a[c1_i319] *= c1_b;
  }

  for (c1_i320 = 0; c1_i320 < 9; c1_i320++) {
    c1_b_a[c1_i320] = c1_wh[c1_i320];
  }

  for (c1_i321 = 0; c1_i321 < 9; c1_i321++) {
    c1_b_b[c1_i321] = c1_wh[c1_i321];
  }

  c1_e_eml_scalar_eg(chartInstance);
  c1_e_eml_scalar_eg(chartInstance);
  for (c1_i322 = 0; c1_i322 < 3; c1_i322++) {
    c1_i323 = 0;
    for (c1_i324 = 0; c1_i324 < 3; c1_i324++) {
      c1_y[c1_i323 + c1_i322] = 0.0;
      c1_i325 = 0;
      for (c1_i326 = 0; c1_i326 < 3; c1_i326++) {
        c1_y[c1_i323 + c1_i322] += c1_b_a[c1_i325 + c1_i322] * c1_b_b[c1_i326 +
          c1_i323];
        c1_i325 += 3;
      }

      c1_i323 += 3;
    }
  }

  c1_c_x = c1_theta;
  c1_d_x = c1_c_x;
  c1_d_x = muDoubleScalarCos(c1_d_x);
  c1_c_b = 1.0 - c1_d_x;
  for (c1_i327 = 0; c1_i327 < 9; c1_i327++) {
    c1_y[c1_i327] *= c1_c_b;
  }

  c1_eye(chartInstance, c1_b_a);
  for (c1_i328 = 0; c1_i328 < 9; c1_i328++) {
    c1_R[c1_i328] = (c1_b_a[c1_i328] + c1_a[c1_i328]) + c1_y[c1_i328];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c1_sfEvent, -10);
  sf_debug_symbol_scope_pop();
}

static void c1_e_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static void c1_f_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static void c1_subPro3(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[4], real_T c1_q[4], real_T c1_d[4],
  real_T c1_theta[2], real_T *c1_Nsol)
{
  uint32_T c1_debug_family_var_map[18];
  real_T c1_velociy[3];
  real_T c1_w[3];
  real_T c1_r[3];
  real_T c1_u[3];
  real_T c1_v[3];
  real_T c1_up[3];
  real_T c1_vp[3];
  real_T c1_dp2;
  real_T c1_theta0;
  real_T c1_phi;
  real_T c1_b_p[3];
  real_T c1_b_q[3];
  real_T c1_b_d[3];
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 2.0;
  int32_T c1_i329;
  int32_T c1_i330;
  int32_T c1_i331;
  int32_T c1_i332;
  int32_T c1_i333;
  int32_T c1_i334;
  int32_T c1_i335;
  real_T c1_b_velociy[3];
  int32_T c1_i336;
  real_T c1_b_w[3];
  real_T c1_b[3];
  int32_T c1_i337;
  int32_T c1_i338;
  int32_T c1_i339;
  int32_T c1_i340;
  real_T c1_a[3];
  int32_T c1_i341;
  real_T c1_y;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i342;
  real_T c1_b_b;
  int32_T c1_i343;
  int32_T c1_i344;
  int32_T c1_i345;
  int32_T c1_i346;
  real_T c1_b_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_i347;
  real_T c1_c_b;
  int32_T c1_i348;
  int32_T c1_i349;
  int32_T c1_i350;
  int32_T c1_i351;
  real_T c1_c_y;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_i352;
  int32_T c1_i353;
  real_T c1_d_y;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i354;
  int32_T c1_i355;
  real_T c1_b_up[3];
  int32_T c1_i356;
  real_T c1_b_vp[3];
  real_T c1_e_y;
  int32_T c1_i_k;
  int32_T c1_j_k;
  int32_T c1_i357;
  int32_T c1_i358;
  real_T c1_f_y;
  int32_T c1_k_k;
  int32_T c1_l_k;
  int32_T c1_i359;
  int32_T c1_i360;
  real_T c1_g_y;
  int32_T c1_m_k;
  int32_T c1_n_k;
  int32_T c1_i361;
  int32_T c1_i362;
  real_T c1_h_y;
  int32_T c1_o_k;
  int32_T c1_p_k;
  int32_T c1_i363;
  real_T c1_c_up[3];
  real_T c1_d_b;
  real_T c1_i_y;
  real_T c1_b_a;
  int32_T c1_i364;
  real_T c1_c_vp[3];
  real_T c1_e_b;
  real_T c1_j_y;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_k_y;
  real_T c1_b_x;
  real_T c1_l_y;
  real_T c1_m_y;
  real_T c1_c_x;
  real_T c1_d_x;
  boolean_T guard1 = FALSE;
  sf_debug_symbol_scope_push_eml(0U, 18U, 21U, c1_f_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_velociy, 0U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 1U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r, 2U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_u, 3U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_v, 4U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_up, 5U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_vp, 6U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_dp2, 7U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta0, 8U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_phi, 9U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_p, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_q, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_b_d, MAX_uint32_T,
    c1_d_sf_marshallOut, c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 13U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 14U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p, 10U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_q, 11U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_d, 12U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_theta, 16U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Nsol, 17U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 2);
  for (c1_i329 = 0; c1_i329 < 2; c1_i329++) {
    c1_theta[c1_i329] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 3);
  for (c1_i330 = 0; c1_i330 < 3; c1_i330++) {
    c1_b_p[c1_i330] = c1_p[c1_i330];
  }

  sf_debug_symbol_switch(10U, 10U);
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 4);
  for (c1_i331 = 0; c1_i331 < 3; c1_i331++) {
    c1_b_q[c1_i331] = c1_q[c1_i331];
  }

  sf_debug_symbol_switch(11U, 11U);
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 5);
  for (c1_i332 = 0; c1_i332 < 3; c1_i332++) {
    c1_b_d[c1_i332] = c1_d[c1_i332];
  }

  sf_debug_symbol_switch(12U, 12U);
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 7);
  for (c1_i333 = 0; c1_i333 < 3; c1_i333++) {
    c1_velociy[c1_i333] = c1_kx[c1_i333];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 8);
  for (c1_i334 = 0; c1_i334 < 3; c1_i334++) {
    c1_w[c1_i334] = c1_kx[c1_i334 + 3];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 9);
  for (c1_i335 = 0; c1_i335 < 3; c1_i335++) {
    c1_b_velociy[c1_i335] = c1_velociy[c1_i335];
  }

  for (c1_i336 = 0; c1_i336 < 3; c1_i336++) {
    c1_b_w[c1_i336] = c1_w[c1_i336];
  }

  c1_cross(chartInstance, c1_b_velociy, c1_b_w, c1_b);
  for (c1_i337 = 0; c1_i337 < 3; c1_i337++) {
    c1_r[c1_i337] = -c1_b[c1_i337];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 11);
  for (c1_i338 = 0; c1_i338 < 3; c1_i338++) {
    c1_u[c1_i338] = c1_b_p[c1_i338] - c1_r[c1_i338];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 12);
  for (c1_i339 = 0; c1_i339 < 3; c1_i339++) {
    c1_v[c1_i339] = c1_b_q[c1_i339] - c1_r[c1_i339];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 14);
  for (c1_i340 = 0; c1_i340 < 3; c1_i340++) {
    c1_a[c1_i340] = c1_w[c1_i340];
  }

  for (c1_i341 = 0; c1_i341 < 3; c1_i341++) {
    c1_b[c1_i341] = c1_u[c1_i341];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i342 = 0; c1_i342 < 3; c1_i342++) {
    c1_b[c1_i342] = c1_w[c1_i342];
  }

  c1_b_b = c1_y;
  for (c1_i343 = 0; c1_i343 < 3; c1_i343++) {
    c1_b[c1_i343] *= c1_b_b;
  }

  for (c1_i344 = 0; c1_i344 < 3; c1_i344++) {
    c1_up[c1_i344] = c1_u[c1_i344] - c1_b[c1_i344];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 15);
  for (c1_i345 = 0; c1_i345 < 3; c1_i345++) {
    c1_a[c1_i345] = c1_w[c1_i345];
  }

  for (c1_i346 = 0; c1_i346 < 3; c1_i346++) {
    c1_b[c1_i346] = c1_v[c1_i346];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_b_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_c_k = 1; c1_c_k < 4; c1_c_k++) {
    c1_d_k = c1_c_k;
    c1_b_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_d_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i347 = 0; c1_i347 < 3; c1_i347++) {
    c1_b[c1_i347] = c1_w[c1_i347];
  }

  c1_c_b = c1_b_y;
  for (c1_i348 = 0; c1_i348 < 3; c1_i348++) {
    c1_b[c1_i348] *= c1_c_b;
  }

  for (c1_i349 = 0; c1_i349 < 3; c1_i349++) {
    c1_vp[c1_i349] = c1_v[c1_i349] - c1_b[c1_i349];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 17);
  for (c1_i350 = 0; c1_i350 < 3; c1_i350++) {
    c1_a[c1_i350] = c1_b_d[c1_i350];
  }

  for (c1_i351 = 0; c1_i351 < 3; c1_i351++) {
    c1_b[c1_i351] = c1_b_d[c1_i351];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_c_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_e_k = 1; c1_e_k < 4; c1_e_k++) {
    c1_f_k = c1_e_k;
    c1_c_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_f_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_f_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i352 = 0; c1_i352 < 3; c1_i352++) {
    c1_a[c1_i352] = c1_w[c1_i352];
  }

  for (c1_i353 = 0; c1_i353 < 3; c1_i353++) {
    c1_b[c1_i353] = c1_b_p[c1_i353] - c1_b_q[c1_i353];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_d_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_g_k = 1; c1_g_k < 4; c1_g_k++) {
    c1_h_k = c1_g_k;
    c1_d_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_h_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_h_k), 1, 3, 1, 0) - 1];
  }

  c1_dp2 = c1_c_y - c1_mpower(chartInstance, c1_d_y);
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 19);
  for (c1_i354 = 0; c1_i354 < 3; c1_i354++) {
    c1_a[c1_i354] = c1_w[c1_i354];
  }

  for (c1_i355 = 0; c1_i355 < 3; c1_i355++) {
    c1_b_up[c1_i355] = c1_up[c1_i355];
  }

  for (c1_i356 = 0; c1_i356 < 3; c1_i356++) {
    c1_b_vp[c1_i356] = c1_vp[c1_i356];
  }

  c1_cross(chartInstance, c1_b_up, c1_b_vp, c1_b);
  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_e_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_i_k = 1; c1_i_k < 4; c1_i_k++) {
    c1_j_k = c1_i_k;
    c1_e_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_j_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_j_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i357 = 0; c1_i357 < 3; c1_i357++) {
    c1_a[c1_i357] = c1_up[c1_i357];
  }

  for (c1_i358 = 0; c1_i358 < 3; c1_i358++) {
    c1_b[c1_i358] = c1_vp[c1_i358];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_f_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k_k = 1; c1_k_k < 4; c1_k_k++) {
    c1_l_k = c1_k_k;
    c1_f_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_l_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_l_k), 1, 3, 1, 0) - 1];
  }

  c1_theta0 = c1_atan2(chartInstance, c1_e_y, c1_f_y);
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 21);
  for (c1_i359 = 0; c1_i359 < 3; c1_i359++) {
    c1_a[c1_i359] = c1_up[c1_i359];
  }

  for (c1_i360 = 0; c1_i360 < 3; c1_i360++) {
    c1_b[c1_i360] = c1_up[c1_i360];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_g_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_m_k = 1; c1_m_k < 4; c1_m_k++) {
    c1_n_k = c1_m_k;
    c1_g_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_n_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_n_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i361 = 0; c1_i361 < 3; c1_i361++) {
    c1_a[c1_i361] = c1_vp[c1_i361];
  }

  for (c1_i362 = 0; c1_i362 < 3; c1_i362++) {
    c1_b[c1_i362] = c1_vp[c1_i362];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_h_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_o_k = 1; c1_o_k < 4; c1_o_k++) {
    c1_p_k = c1_o_k;
    c1_h_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_p_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_p_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i363 = 0; c1_i363 < 3; c1_i363++) {
    c1_c_up[c1_i363] = c1_up[c1_i363];
  }

  c1_d_b = c1_norm(chartInstance, c1_c_up);
  c1_i_y = 2.0 * c1_d_b;
  c1_b_a = c1_i_y;
  for (c1_i364 = 0; c1_i364 < 3; c1_i364++) {
    c1_c_vp[c1_i364] = c1_vp[c1_i364];
  }

  c1_e_b = c1_norm(chartInstance, c1_c_vp);
  c1_j_y = c1_b_a * c1_e_b;
  c1_A = (c1_g_y + c1_h_y) - c1_dp2;
  c1_B = c1_j_y;
  c1_x = c1_A;
  c1_k_y = c1_B;
  c1_b_x = c1_x;
  c1_l_y = c1_k_y;
  c1_m_y = c1_b_x / c1_l_y;
  c1_c_x = c1_m_y;
  c1_phi = c1_c_x;
  guard1 = FALSE;
  if (c1_phi < -1.0) {
    guard1 = TRUE;
  } else {
    if (1.0 < c1_phi) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c1_eml_error(chartInstance);
  }

  c1_d_x = c1_phi;
  c1_phi = c1_d_x;
  c1_phi = muDoubleScalarAcos(c1_phi);
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 23);
  c1_theta[0] = c1_theta0 - c1_phi;
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 24);
  c1_theta[1] = c1_theta0 + c1_phi;
  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 44);
  if (CV_SCRIPT_IF(4, 0, c1_phi != 0.0)) {
    _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 45);
    *c1_Nsol = 2.0;
  } else {
    _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, 48);
    *c1_Nsol = 1.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c1_sfEvent, -48);
  sf_debug_symbol_scope_pop();
}

static void c1_g_eml_scalar_eg(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
}

static real_T c1_mpower(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_a)
{
  real_T c1_b_a;
  real_T c1_ak;
  c1_b_a = c1_a;
  c1_eml_scalar_eg(chartInstance);
  c1_ak = c1_b_a;
  return muDoubleScalarPower(c1_ak, 2.0);
}

static real_T c1_norm(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                      *chartInstance, real_T c1_x[3])
{
  real_T c1_y;
  real_T c1_scale;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_absxk;
  real_T c1_t;
  c1_y = 0.0;
  c1_realmin(chartInstance);
  c1_scale = 2.2250738585072014E-308;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 3, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_absxk = muDoubleScalarAbs(c1_c_x);
    if (c1_absxk > c1_scale) {
      c1_t = c1_scale / c1_absxk;
      c1_y = 1.0 + c1_y * c1_t * c1_t;
      c1_scale = c1_absxk;
    } else {
      c1_t = c1_absxk / c1_scale;
      c1_y += c1_t * c1_t;
    }
  }

  return c1_scale * muDoubleScalarSqrt(c1_y);
}

static void c1_eml_error(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
  int32_T c1_i365;
  static char_T c1_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 'a', 'c', 'o', 's', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  for (c1_i365 = 0; c1_i365 < 30; c1_i365++) {
    c1_u[c1_i365] = c1_varargin_1[c1_i365];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static void c1_b_isInRange(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_x[2], real_T c1_xmin, real_T c1_xmax, boolean_T
  c1_isIn[2])
{
  uint32_T c1_debug_family_var_map[6];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i366;
  real_T c1_A[2];
  int32_T c1_i367;
  int32_T c1_i368;
  int32_T c1_i369;
  boolean_T c1_bv5[2];
  int32_T c1_i370;
  boolean_T c1_bv6[2];
  int32_T c1_i371;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c1_g_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_x, 2U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_xmin, 3U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_xmax, 4U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_isIn, 5U, c1_k_sf_marshallOut,
    c1_k_sf_marshallIn);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 141U);
  for (c1_i366 = 0; c1_i366 < 2; c1_i366++) {
    c1_A[c1_i366] = c1_x[c1_i366];
  }

  for (c1_i367 = 0; c1_i367 < 2; c1_i367++) {
    c1_A[c1_i367] /= 3.1415926535897931;
  }

  for (c1_i368 = 0; c1_i368 < 2; c1_i368++) {
    c1_x[c1_i368] = c1_A[c1_i368] * 180.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, 142U);
  for (c1_i369 = 0; c1_i369 < 2; c1_i369++) {
    c1_bv5[c1_i369] = (c1_x[c1_i369] >= c1_xmin);
  }

  for (c1_i370 = 0; c1_i370 < 2; c1_i370++) {
    c1_bv6[c1_i370] = (c1_x[c1_i370] <= c1_xmax);
  }

  for (c1_i371 = 0; c1_i371 < 2; c1_i371++) {
    c1_isIn[c1_i371] = (c1_bv5[c1_i371] && c1_bv6[c1_i371]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c1_sfEvent, -142);
  sf_debug_symbol_scope_pop();
}

static boolean_T c1_any(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, boolean_T c1_x[2])
{
  boolean_T c1_y;
  int32_T c1_k;
  real_T c1_b_k;
  boolean_T c1_b3;
  boolean_T exitg1;
  c1_y = FALSE;
  c1_k = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (c1_k < 2)) {
    c1_b_k = 1.0 + (real_T)c1_k;
    if ((real_T)c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
         ("", c1_b_k), 1, 2, 1, 0) - 1] == 0.0) {
      c1_b3 = TRUE;
    } else {
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c1_b_k), 1, 2, 1, 0);
      c1_b3 = FALSE;
    }

    if (!c1_b3) {
      c1_y = TRUE;
      exitg1 = TRUE;
    } else {
      c1_k++;
    }
  }

  return c1_y;
}

static real_T c1_subPro1(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[4], real_T c1_q[4])
{
  real_T c1_theta;
  uint32_T c1_debug_family_var_map[13];
  real_T c1_velociy[3];
  real_T c1_w[3];
  real_T c1_r[3];
  real_T c1_u[3];
  real_T c1_v[3];
  real_T c1_up[3];
  real_T c1_vp[3];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i372;
  int32_T c1_i373;
  int32_T c1_i374;
  real_T c1_b_velociy[3];
  int32_T c1_i375;
  real_T c1_b_w[3];
  real_T c1_b[3];
  int32_T c1_i376;
  int32_T c1_i377;
  int32_T c1_i378;
  int32_T c1_i379;
  real_T c1_a[3];
  int32_T c1_i380;
  real_T c1_y;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i381;
  real_T c1_b_b;
  int32_T c1_i382;
  int32_T c1_i383;
  int32_T c1_i384;
  int32_T c1_i385;
  real_T c1_b_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_i386;
  real_T c1_c_b;
  int32_T c1_i387;
  int32_T c1_i388;
  int32_T c1_i389;
  int32_T c1_i390;
  real_T c1_b_up[3];
  int32_T c1_i391;
  real_T c1_b_vp[3];
  real_T c1_c_y;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_i392;
  int32_T c1_i393;
  real_T c1_d_y;
  int32_T c1_g_k;
  int32_T c1_h_k;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c1_h_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_velociy, 0U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 1U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r, 2U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_u, 3U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_v, 4U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_up, 5U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_vp, 6U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 7U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 8U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p, 10U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_q, 11U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 12U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 4);
  for (c1_i372 = 0; c1_i372 < 3; c1_i372++) {
    c1_velociy[c1_i372] = c1_kx[c1_i372];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 5);
  for (c1_i373 = 0; c1_i373 < 3; c1_i373++) {
    c1_w[c1_i373] = c1_kx[c1_i373 + 3];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 6);
  for (c1_i374 = 0; c1_i374 < 3; c1_i374++) {
    c1_b_velociy[c1_i374] = c1_velociy[c1_i374];
  }

  for (c1_i375 = 0; c1_i375 < 3; c1_i375++) {
    c1_b_w[c1_i375] = c1_w[c1_i375];
  }

  c1_cross(chartInstance, c1_b_velociy, c1_b_w, c1_b);
  for (c1_i376 = 0; c1_i376 < 3; c1_i376++) {
    c1_r[c1_i376] = -c1_b[c1_i376];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 8);
  for (c1_i377 = 0; c1_i377 < 3; c1_i377++) {
    c1_u[c1_i377] = c1_p[c1_i377] - c1_r[c1_i377];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 9);
  for (c1_i378 = 0; c1_i378 < 3; c1_i378++) {
    c1_v[c1_i378] = c1_q[c1_i378] - c1_r[c1_i378];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 12);
  for (c1_i379 = 0; c1_i379 < 3; c1_i379++) {
    c1_a[c1_i379] = c1_w[c1_i379];
  }

  for (c1_i380 = 0; c1_i380 < 3; c1_i380++) {
    c1_b[c1_i380] = c1_u[c1_i380];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i381 = 0; c1_i381 < 3; c1_i381++) {
    c1_b[c1_i381] = c1_w[c1_i381];
  }

  c1_b_b = c1_y;
  for (c1_i382 = 0; c1_i382 < 3; c1_i382++) {
    c1_b[c1_i382] *= c1_b_b;
  }

  for (c1_i383 = 0; c1_i383 < 3; c1_i383++) {
    c1_up[c1_i383] = c1_u[c1_i383] - c1_b[c1_i383];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 13);
  for (c1_i384 = 0; c1_i384 < 3; c1_i384++) {
    c1_a[c1_i384] = c1_w[c1_i384];
  }

  for (c1_i385 = 0; c1_i385 < 3; c1_i385++) {
    c1_b[c1_i385] = c1_u[c1_i385];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_b_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_c_k = 1; c1_c_k < 4; c1_c_k++) {
    c1_d_k = c1_c_k;
    c1_b_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_d_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i386 = 0; c1_i386 < 3; c1_i386++) {
    c1_b[c1_i386] = c1_w[c1_i386];
  }

  c1_c_b = c1_b_y;
  for (c1_i387 = 0; c1_i387 < 3; c1_i387++) {
    c1_b[c1_i387] *= c1_c_b;
  }

  for (c1_i388 = 0; c1_i388 < 3; c1_i388++) {
    c1_vp[c1_i388] = c1_v[c1_i388] - c1_b[c1_i388];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 19);
  for (c1_i389 = 0; c1_i389 < 3; c1_i389++) {
    c1_a[c1_i389] = c1_w[c1_i389];
  }

  for (c1_i390 = 0; c1_i390 < 3; c1_i390++) {
    c1_b_up[c1_i390] = c1_up[c1_i390];
  }

  for (c1_i391 = 0; c1_i391 < 3; c1_i391++) {
    c1_b_vp[c1_i391] = c1_vp[c1_i391];
  }

  c1_cross(chartInstance, c1_b_up, c1_b_vp, c1_b);
  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_c_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_e_k = 1; c1_e_k < 4; c1_e_k++) {
    c1_f_k = c1_e_k;
    c1_c_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_f_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_f_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i392 = 0; c1_i392 < 3; c1_i392++) {
    c1_a[c1_i392] = c1_up[c1_i392];
  }

  for (c1_i393 = 0; c1_i393 < 3; c1_i393++) {
    c1_b[c1_i393] = c1_vp[c1_i393];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_d_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_g_k = 1; c1_g_k < 4; c1_g_k++) {
    c1_h_k = c1_g_k;
    c1_d_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_h_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_h_k), 1, 3, 1, 0) - 1];
  }

  c1_theta = c1_atan2(chartInstance, c1_c_y, c1_d_y);
  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, -19);
  sf_debug_symbol_scope_pop();
  return c1_theta;
}

static void c1_subPro2(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx1[6], real_T c1_kx2[6], real_T c1_p[4], real_T
  c1_q[4], real_T c1_theta1[2], real_T c1_theta2[2], real_T *c1_Nsol)
{
  uint32_T c1_debug_family_var_map[24];
  real_T c1_velociy1[3];
  real_T c1_w1[3];
  real_T c1_r1[3];
  real_T c1_velociy2[3];
  real_T c1_w2[3];
  real_T c1_r2[3];
  real_T c1_r[3];
  real_T c1_u[3];
  real_T c1_v[3];
  real_T c1_alpha;
  real_T c1_beta;
  real_T c1_ySqu;
  real_T c1_y;
  real_T c1_z[3];
  real_T c1_c[3];
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 3.0;
  int32_T c1_i394;
  int32_T c1_i395;
  int32_T c1_i396;
  int32_T c1_i397;
  int32_T c1_i398;
  real_T c1_b_velociy1[3];
  int32_T c1_i399;
  real_T c1_b_w1[3];
  real_T c1_b[3];
  int32_T c1_i400;
  int32_T c1_i401;
  int32_T c1_i402;
  int32_T c1_i403;
  real_T c1_b_velociy2[3];
  int32_T c1_i404;
  real_T c1_b_w2[3];
  int32_T c1_i405;
  int32_T c1_i406;
  real_T c1_c_w1[3];
  int32_T c1_i407;
  real_T c1_c_w2[3];
  int32_T c1_i408;
  real_T c1_b_r1[3];
  int32_T c1_i409;
  real_T c1_b_r2[3];
  real_T c1_dv31[3];
  int32_T c1_i410;
  int32_T c1_i411;
  int32_T c1_i412;
  int32_T c1_i413;
  real_T c1_a[3];
  int32_T c1_i414;
  real_T c1_b_y;
  int32_T c1_k;
  int32_T c1_b_k;
  real_T c1_b_a;
  int32_T c1_i415;
  int32_T c1_i416;
  int32_T c1_i417;
  real_T c1_c_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_i418;
  int32_T c1_i419;
  real_T c1_d_y;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_i420;
  int32_T c1_i421;
  real_T c1_e_y;
  int32_T c1_g_k;
  int32_T c1_h_k;
  int32_T c1_i422;
  int32_T c1_i423;
  real_T c1_f_y;
  int32_T c1_i_k;
  int32_T c1_j_k;
  real_T c1_c_a;
  real_T c1_b_b;
  real_T c1_g_y;
  real_T c1_A;
  real_T c1_B;
  real_T c1_x;
  real_T c1_h_y;
  real_T c1_b_x;
  real_T c1_i_y;
  int32_T c1_i424;
  int32_T c1_i425;
  real_T c1_j_y;
  int32_T c1_k_k;
  int32_T c1_l_k;
  real_T c1_d_a;
  int32_T c1_i426;
  int32_T c1_i427;
  int32_T c1_i428;
  real_T c1_k_y;
  int32_T c1_m_k;
  int32_T c1_n_k;
  int32_T c1_i429;
  int32_T c1_i430;
  real_T c1_l_y;
  int32_T c1_o_k;
  int32_T c1_p_k;
  int32_T c1_i431;
  int32_T c1_i432;
  real_T c1_m_y;
  int32_T c1_q_k;
  int32_T c1_r_k;
  int32_T c1_i433;
  int32_T c1_i434;
  real_T c1_n_y;
  int32_T c1_s_k;
  int32_T c1_t_k;
  real_T c1_e_a;
  real_T c1_c_b;
  real_T c1_o_y;
  real_T c1_b_A;
  real_T c1_b_B;
  real_T c1_c_x;
  real_T c1_p_y;
  real_T c1_d_x;
  real_T c1_q_y;
  int32_T c1_i435;
  int32_T c1_i436;
  real_T c1_r_y;
  int32_T c1_u_k;
  int32_T c1_v_k;
  real_T c1_f_a;
  real_T c1_d_b;
  real_T c1_s_y;
  real_T c1_g_a;
  real_T c1_e_b;
  real_T c1_t_y;
  real_T c1_f_b;
  real_T c1_u_y;
  real_T c1_h_a;
  real_T c1_g_b;
  real_T c1_v_y;
  real_T c1_i_a;
  int32_T c1_i437;
  int32_T c1_i438;
  int32_T c1_i439;
  real_T c1_w_y;
  int32_T c1_w_k;
  int32_T c1_x_k;
  int32_T c1_i440;
  real_T c1_d_w1[3];
  int32_T c1_i441;
  real_T c1_d_w2[3];
  int32_T c1_i442;
  int32_T c1_i443;
  real_T c1_e_w1[3];
  int32_T c1_i444;
  real_T c1_e_w2[3];
  real_T c1_x_y;
  int32_T c1_y_k;
  int32_T c1_ab_k;
  real_T c1_c_A;
  real_T c1_c_B;
  real_T c1_e_x;
  real_T c1_y_y;
  real_T c1_f_x;
  real_T c1_ab_y;
  int32_T c1_i;
  real_T c1_b_i;
  real_T c1_h_b;
  real_T c1_bb_y;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_j_a;
  real_T c1_i_b;
  real_T c1_k_a;
  int32_T c1_i445;
  int32_T c1_i446;
  real_T c1_l_a;
  int32_T c1_i447;
  real_T c1_j_b[3];
  int32_T c1_i448;
  real_T c1_m_a;
  int32_T c1_i449;
  real_T c1_f_w1[3];
  int32_T c1_i450;
  real_T c1_f_w2[3];
  real_T c1_k_b[3];
  int32_T c1_i451;
  int32_T c1_i452;
  int32_T c1_i453;
  int32_T c1_i454;
  real_T c1_b_kx2[6];
  int32_T c1_i455;
  real_T c1_b_p[4];
  int32_T c1_i456;
  real_T c1_b_c[3];
  int32_T c1_i457;
  real_T c1_b_kx1[6];
  int32_T c1_i458;
  real_T c1_c_c[3];
  int32_T c1_i459;
  real_T c1_b_q[4];
  sf_debug_symbol_scope_push_eml(0U, 24U, 24U, c1_l_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_velociy1, 0U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w1, 1U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r1, 2U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_velociy2, 3U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w2, 4U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r2, 5U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r, 6U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_u, 7U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_v, 8U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_alpha, 9U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_beta, 10U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_ySqu, 11U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_y, 12U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_z, 13U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_c, 14U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 15U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 16U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx1, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx2, 18U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p, 19U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_q, 20U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_theta1, 21U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_theta2, 22U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Nsol, 23U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 3);
  for (c1_i394 = 0; c1_i394 < 2; c1_i394++) {
    c1_theta1[c1_i394] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 4);
  for (c1_i395 = 0; c1_i395 < 2; c1_i395++) {
    c1_theta2[c1_i395] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 9);
  for (c1_i396 = 0; c1_i396 < 3; c1_i396++) {
    c1_velociy1[c1_i396] = c1_kx1[c1_i396];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 10);
  for (c1_i397 = 0; c1_i397 < 3; c1_i397++) {
    c1_w1[c1_i397] = c1_kx1[c1_i397 + 3];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 11);
  for (c1_i398 = 0; c1_i398 < 3; c1_i398++) {
    c1_b_velociy1[c1_i398] = c1_velociy1[c1_i398];
  }

  for (c1_i399 = 0; c1_i399 < 3; c1_i399++) {
    c1_b_w1[c1_i399] = c1_w1[c1_i399];
  }

  c1_cross(chartInstance, c1_b_velociy1, c1_b_w1, c1_b);
  for (c1_i400 = 0; c1_i400 < 3; c1_i400++) {
    c1_r1[c1_i400] = -c1_b[c1_i400];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 13);
  for (c1_i401 = 0; c1_i401 < 3; c1_i401++) {
    c1_velociy2[c1_i401] = c1_kx2[c1_i401];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 14);
  for (c1_i402 = 0; c1_i402 < 3; c1_i402++) {
    c1_w2[c1_i402] = c1_kx2[c1_i402 + 3];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 15);
  for (c1_i403 = 0; c1_i403 < 3; c1_i403++) {
    c1_b_velociy2[c1_i403] = c1_velociy2[c1_i403];
  }

  for (c1_i404 = 0; c1_i404 < 3; c1_i404++) {
    c1_b_w2[c1_i404] = c1_w2[c1_i404];
  }

  c1_cross(chartInstance, c1_b_velociy2, c1_b_w2, c1_b);
  for (c1_i405 = 0; c1_i405 < 3; c1_i405++) {
    c1_r2[c1_i405] = -c1_b[c1_i405];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 18);
  for (c1_i406 = 0; c1_i406 < 3; c1_i406++) {
    c1_c_w1[c1_i406] = c1_w1[c1_i406];
  }

  for (c1_i407 = 0; c1_i407 < 3; c1_i407++) {
    c1_c_w2[c1_i407] = c1_w2[c1_i407];
  }

  for (c1_i408 = 0; c1_i408 < 3; c1_i408++) {
    c1_b_r1[c1_i408] = c1_r1[c1_i408];
  }

  for (c1_i409 = 0; c1_i409 < 3; c1_i409++) {
    c1_b_r2[c1_i409] = c1_r2[c1_i409];
  }

  c1_findCommon(chartInstance, c1_c_w1, c1_c_w2, c1_b_r1, c1_b_r2, c1_dv31);
  for (c1_i410 = 0; c1_i410 < 3; c1_i410++) {
    c1_r[c1_i410] = c1_dv31[c1_i410];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 20);
  for (c1_i411 = 0; c1_i411 < 3; c1_i411++) {
    c1_u[c1_i411] = c1_p[c1_i411] - c1_r[c1_i411];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 21);
  for (c1_i412 = 0; c1_i412 < 3; c1_i412++) {
    c1_v[c1_i412] = c1_q[c1_i412] - c1_r[c1_i412];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 23);
  for (c1_i413 = 0; c1_i413 < 3; c1_i413++) {
    c1_a[c1_i413] = c1_w1[c1_i413];
  }

  for (c1_i414 = 0; c1_i414 < 3; c1_i414++) {
    c1_b[c1_i414] = c1_w2[c1_i414];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_b_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_b_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_b_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
  }

  c1_b_a = c1_b_y;
  for (c1_i415 = 0; c1_i415 < 3; c1_i415++) {
    c1_a[c1_i415] = c1_w2[c1_i415];
  }

  for (c1_i416 = 0; c1_i416 < 3; c1_i416++) {
    c1_a[c1_i416] *= c1_b_a;
  }

  for (c1_i417 = 0; c1_i417 < 3; c1_i417++) {
    c1_b[c1_i417] = c1_u[c1_i417];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_c_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_c_k = 1; c1_c_k < 4; c1_c_k++) {
    c1_d_k = c1_c_k;
    c1_c_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_d_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i418 = 0; c1_i418 < 3; c1_i418++) {
    c1_a[c1_i418] = c1_w1[c1_i418];
  }

  for (c1_i419 = 0; c1_i419 < 3; c1_i419++) {
    c1_b[c1_i419] = c1_v[c1_i419];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_d_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_e_k = 1; c1_e_k < 4; c1_e_k++) {
    c1_f_k = c1_e_k;
    c1_d_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_f_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_f_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i420 = 0; c1_i420 < 3; c1_i420++) {
    c1_a[c1_i420] = c1_w1[c1_i420];
  }

  for (c1_i421 = 0; c1_i421 < 3; c1_i421++) {
    c1_b[c1_i421] = c1_w2[c1_i421];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_e_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_g_k = 1; c1_g_k < 4; c1_g_k++) {
    c1_h_k = c1_g_k;
    c1_e_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_h_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_h_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i422 = 0; c1_i422 < 3; c1_i422++) {
    c1_a[c1_i422] = c1_w1[c1_i422];
  }

  for (c1_i423 = 0; c1_i423 < 3; c1_i423++) {
    c1_b[c1_i423] = c1_w2[c1_i423];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_f_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_i_k = 1; c1_i_k < 4; c1_i_k++) {
    c1_j_k = c1_i_k;
    c1_f_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_j_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_j_k), 1, 3, 1, 0) - 1];
  }

  c1_c_a = c1_e_y;
  c1_b_b = c1_f_y;
  c1_g_y = c1_c_a * c1_b_b;
  c1_A = c1_c_y - c1_d_y;
  c1_B = c1_g_y - 1.0;
  c1_x = c1_A;
  c1_h_y = c1_B;
  c1_b_x = c1_x;
  c1_i_y = c1_h_y;
  c1_alpha = c1_b_x / c1_i_y;
  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 24);
  for (c1_i424 = 0; c1_i424 < 3; c1_i424++) {
    c1_a[c1_i424] = c1_w1[c1_i424];
  }

  for (c1_i425 = 0; c1_i425 < 3; c1_i425++) {
    c1_b[c1_i425] = c1_w2[c1_i425];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_j_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k_k = 1; c1_k_k < 4; c1_k_k++) {
    c1_l_k = c1_k_k;
    c1_j_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_l_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_l_k), 1, 3, 1, 0) - 1];
  }

  c1_d_a = c1_j_y;
  for (c1_i426 = 0; c1_i426 < 3; c1_i426++) {
    c1_a[c1_i426] = c1_w1[c1_i426];
  }

  for (c1_i427 = 0; c1_i427 < 3; c1_i427++) {
    c1_a[c1_i427] *= c1_d_a;
  }

  for (c1_i428 = 0; c1_i428 < 3; c1_i428++) {
    c1_b[c1_i428] = c1_v[c1_i428];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_k_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_m_k = 1; c1_m_k < 4; c1_m_k++) {
    c1_n_k = c1_m_k;
    c1_k_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_n_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_n_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i429 = 0; c1_i429 < 3; c1_i429++) {
    c1_a[c1_i429] = c1_w2[c1_i429];
  }

  for (c1_i430 = 0; c1_i430 < 3; c1_i430++) {
    c1_b[c1_i430] = c1_u[c1_i430];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_l_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_o_k = 1; c1_o_k < 4; c1_o_k++) {
    c1_p_k = c1_o_k;
    c1_l_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_p_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_p_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i431 = 0; c1_i431 < 3; c1_i431++) {
    c1_a[c1_i431] = c1_w1[c1_i431];
  }

  for (c1_i432 = 0; c1_i432 < 3; c1_i432++) {
    c1_b[c1_i432] = c1_w2[c1_i432];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_m_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_q_k = 1; c1_q_k < 4; c1_q_k++) {
    c1_r_k = c1_q_k;
    c1_m_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_r_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_r_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i433 = 0; c1_i433 < 3; c1_i433++) {
    c1_a[c1_i433] = c1_w1[c1_i433];
  }

  for (c1_i434 = 0; c1_i434 < 3; c1_i434++) {
    c1_b[c1_i434] = c1_w2[c1_i434];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_n_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_s_k = 1; c1_s_k < 4; c1_s_k++) {
    c1_t_k = c1_s_k;
    c1_n_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_t_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_t_k), 1, 3, 1, 0) - 1];
  }

  c1_e_a = c1_m_y;
  c1_c_b = c1_n_y;
  c1_o_y = c1_e_a * c1_c_b;
  c1_b_A = c1_k_y - c1_l_y;
  c1_b_B = c1_o_y - 1.0;
  c1_c_x = c1_b_A;
  c1_p_y = c1_b_B;
  c1_d_x = c1_c_x;
  c1_q_y = c1_p_y;
  c1_beta = c1_d_x / c1_q_y;
  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 26);
  for (c1_i435 = 0; c1_i435 < 3; c1_i435++) {
    c1_a[c1_i435] = c1_u[c1_i435];
  }

  for (c1_i436 = 0; c1_i436 < 3; c1_i436++) {
    c1_b[c1_i436] = c1_u[c1_i436];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_r_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_u_k = 1; c1_u_k < 4; c1_u_k++) {
    c1_v_k = c1_u_k;
    c1_r_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_v_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_v_k), 1, 3, 1, 0) - 1];
  }

  c1_f_a = c1_alpha;
  c1_d_b = c1_alpha;
  c1_s_y = c1_f_a * c1_d_b;
  c1_g_a = c1_beta;
  c1_e_b = c1_beta;
  c1_t_y = c1_g_a * c1_e_b;
  c1_f_b = c1_beta;
  c1_u_y = 2.0 * c1_f_b;
  c1_h_a = c1_u_y;
  c1_g_b = c1_alpha;
  c1_v_y = c1_h_a * c1_g_b;
  c1_i_a = c1_v_y;
  for (c1_i437 = 0; c1_i437 < 3; c1_i437++) {
    c1_a[c1_i437] = c1_w1[c1_i437];
  }

  for (c1_i438 = 0; c1_i438 < 3; c1_i438++) {
    c1_a[c1_i438] *= c1_i_a;
  }

  for (c1_i439 = 0; c1_i439 < 3; c1_i439++) {
    c1_b[c1_i439] = c1_w2[c1_i439];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_w_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_w_k = 1; c1_w_k < 4; c1_w_k++) {
    c1_x_k = c1_w_k;
    c1_w_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_x_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_x_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i440 = 0; c1_i440 < 3; c1_i440++) {
    c1_d_w1[c1_i440] = c1_w1[c1_i440];
  }

  for (c1_i441 = 0; c1_i441 < 3; c1_i441++) {
    c1_d_w2[c1_i441] = c1_w2[c1_i441];
  }

  c1_cross(chartInstance, c1_d_w1, c1_d_w2, c1_b);
  for (c1_i442 = 0; c1_i442 < 3; c1_i442++) {
    c1_a[c1_i442] = c1_b[c1_i442];
  }

  for (c1_i443 = 0; c1_i443 < 3; c1_i443++) {
    c1_e_w1[c1_i443] = c1_w1[c1_i443];
  }

  for (c1_i444 = 0; c1_i444 < 3; c1_i444++) {
    c1_e_w2[c1_i444] = c1_w2[c1_i444];
  }

  c1_cross(chartInstance, c1_e_w1, c1_e_w2, c1_b);
  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_x_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_y_k = 1; c1_y_k < 4; c1_y_k++) {
    c1_ab_k = c1_y_k;
    c1_x_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_ab_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_ab_k), 1, 3, 1, 0) - 1];
  }

  c1_c_A = ((c1_r_y - c1_s_y) - c1_t_y) - c1_w_y;
  c1_c_B = c1_x_y;
  c1_e_x = c1_c_A;
  c1_y_y = c1_c_B;
  c1_f_x = c1_e_x;
  c1_ab_y = c1_y_y;
  c1_ySqu = c1_f_x / c1_ab_y;
  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 28);
  if (CV_SCRIPT_IF(6, 0, c1_ySqu > 0.0)) {
    _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 29);
    *c1_Nsol = 2.0;
  } else {
    _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 30);
    if (CV_SCRIPT_IF(6, 1, c1_ySqu == 0.0)) {
      _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 31);
      *c1_Nsol = 1.0;
    } else {
      _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 33);
      *c1_Nsol = 0.0;
    }
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 36);
  if (CV_SCRIPT_IF(6, 2, c1_ySqu >= 0.0)) {
    c1_i = 0;
    while (c1_i < 2) {
      c1_b_i = 1.0 + (real_T)c1_i;
      CV_SCRIPT_FOR(6, 0, 1);
      _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 39);
      c1_h_b = c1_b_i;
      c1_bb_y = 2.0 * c1_h_b;
      c1_g_x = c1_ySqu;
      c1_h_x = c1_g_x;
      if (c1_h_x < 0.0) {
        c1_b_eml_error(chartInstance);
      }

      c1_h_x = muDoubleScalarSqrt(c1_h_x);
      c1_j_a = c1_bb_y - 3.0;
      c1_i_b = c1_h_x;
      c1_y = c1_j_a * c1_i_b;
      _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 41);
      c1_k_a = c1_alpha;
      for (c1_i445 = 0; c1_i445 < 3; c1_i445++) {
        c1_b[c1_i445] = c1_w1[c1_i445];
      }

      for (c1_i446 = 0; c1_i446 < 3; c1_i446++) {
        c1_b[c1_i446] *= c1_k_a;
      }

      c1_l_a = c1_beta;
      for (c1_i447 = 0; c1_i447 < 3; c1_i447++) {
        c1_j_b[c1_i447] = c1_w2[c1_i447];
      }

      for (c1_i448 = 0; c1_i448 < 3; c1_i448++) {
        c1_j_b[c1_i448] *= c1_l_a;
      }

      c1_m_a = c1_y;
      for (c1_i449 = 0; c1_i449 < 3; c1_i449++) {
        c1_f_w1[c1_i449] = c1_w1[c1_i449];
      }

      for (c1_i450 = 0; c1_i450 < 3; c1_i450++) {
        c1_f_w2[c1_i450] = c1_w2[c1_i450];
      }

      c1_cross(chartInstance, c1_f_w1, c1_f_w2, c1_k_b);
      for (c1_i451 = 0; c1_i451 < 3; c1_i451++) {
        c1_k_b[c1_i451] *= c1_m_a;
      }

      for (c1_i452 = 0; c1_i452 < 3; c1_i452++) {
        c1_z[c1_i452] = (c1_b[c1_i452] + c1_j_b[c1_i452]) - c1_k_b[c1_i452];
      }

      _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 43);
      for (c1_i453 = 0; c1_i453 < 3; c1_i453++) {
        c1_c[c1_i453] = c1_z[c1_i453] + c1_r[c1_i453];
      }

      _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 45);
      for (c1_i454 = 0; c1_i454 < 6; c1_i454++) {
        c1_b_kx2[c1_i454] = c1_kx2[c1_i454];
      }

      for (c1_i455 = 0; c1_i455 < 4; c1_i455++) {
        c1_b_p[c1_i455] = c1_p[c1_i455];
      }

      for (c1_i456 = 0; c1_i456 < 3; c1_i456++) {
        c1_b_c[c1_i456] = c1_c[c1_i456];
      }

      c1_theta2[_SFD_EML_ARRAY_BOUNDS_CHECK("theta2", (int32_T)
        _SFD_INTEGER_CHECK("i", c1_b_i), 1, 2, 1, 0) - 1] = c1_b_subPro1
        (chartInstance, c1_b_kx2, c1_b_p, c1_b_c);
      _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 46);
      for (c1_i457 = 0; c1_i457 < 6; c1_i457++) {
        c1_b_kx1[c1_i457] = c1_kx1[c1_i457];
      }

      for (c1_i458 = 0; c1_i458 < 3; c1_i458++) {
        c1_c_c[c1_i458] = c1_c[c1_i458];
      }

      for (c1_i459 = 0; c1_i459 < 4; c1_i459++) {
        c1_b_q[c1_i459] = c1_q[c1_i459];
      }

      c1_theta1[_SFD_EML_ARRAY_BOUNDS_CHECK("theta1", (int32_T)
        _SFD_INTEGER_CHECK("i", c1_b_i), 1, 2, 1, 0) - 1] = c1_c_subPro1
        (chartInstance, c1_b_kx1, c1_c_c, c1_b_q);
      c1_i++;
      sf_mex_listen_for_ctrl_c(chartInstance->S);
    }

    CV_SCRIPT_FOR(6, 0, 0);
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, -46);
  sf_debug_symbol_scope_pop();
}

static void c1_findCommon(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_w1[3], real_T c1_w2[3], real_T c1_r1[3], real_T
  c1_r2[3], real_T c1_r[3])
{
  uint32_T c1_debug_family_var_map[10];
  real_T c1_A[4];
  real_T c1_vec[2];
  real_T c1_cof[2];
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 1.0;
  real_T c1_b_r2[2];
  int32_T c1_i460;
  int32_T c1_i461;
  real_T c1_b_A[4];
  real_T c1_c_r2[2];
  int32_T c1_i462;
  int32_T c1_i463;
  real_T c1_c_A[4];
  real_T c1_d_r2[2];
  int32_T c1_i464;
  int32_T c1_i465;
  real_T c1_d_A[4];
  int32_T c1_i466;
  real_T c1_B[2];
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_b_y;
  real_T c1_d;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_c_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_d_y;
  real_T c1_b_d;
  int32_T c1_b_r1;
  int32_T c1_e_r2;
  real_T c1_k_x;
  real_T c1_e_y;
  real_T c1_a21;
  real_T c1_a;
  real_T c1_b;
  real_T c1_f_y;
  real_T c1_a22;
  real_T c1_b_a;
  real_T c1_b_b;
  real_T c1_g_y;
  real_T c1_l_x;
  real_T c1_h_y;
  real_T c1_z;
  real_T c1_c_a;
  real_T c1_c_b;
  real_T c1_i_y;
  real_T c1_m_x;
  real_T c1_j_y;
  real_T c1_b_z;
  int32_T c1_i467;
  real_T c1_d_a[3];
  real_T c1_d_b;
  int32_T c1_i468;
  int32_T c1_i469;
  boolean_T guard1 = FALSE;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c1_i_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_A, 0U, c1_l_sf_marshallOut,
    c1_l_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_vec, 1U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_cof, 2U, c1_i_sf_marshallOut,
    c1_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 3U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 4U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w1, 5U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w2, 6U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r1, 7U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r2, 8U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r, 9U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  CV_SCRIPT_FCN(6, 1);
  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 56);
  c1_A[0] = c1_w1[0];
  c1_A[2] = -c1_w2[0];
  c1_A[1] = c1_w1[1];
  c1_A[3] = -c1_w2[1];
  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 57);
  c1_b_r2[0] = c1_r2[0] - c1_r1[0];
  c1_b_r2[1] = c1_r2[1] - c1_r1[1];
  for (c1_i460 = 0; c1_i460 < 2; c1_i460++) {
    c1_vec[c1_i460] = c1_b_r2[c1_i460];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 59);
  for (c1_i461 = 0; c1_i461 < 4; c1_i461++) {
    c1_b_A[c1_i461] = c1_A[c1_i461];
  }

  if (CV_SCRIPT_IF(6, 3, c1_det(chartInstance, c1_b_A) == 0.0)) {
    _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 60);
    c1_A[0] = c1_w1[0];
    c1_A[2] = -c1_w2[0];
    c1_A[1] = c1_w1[2];
    c1_A[3] = -c1_w2[2];
    _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 61);
    c1_c_r2[0] = c1_r2[0] - c1_r1[0];
    c1_c_r2[1] = c1_r2[2] - c1_r1[2];
    for (c1_i462 = 0; c1_i462 < 2; c1_i462++) {
      c1_vec[c1_i462] = c1_c_r2[c1_i462];
    }
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 64);
  for (c1_i463 = 0; c1_i463 < 4; c1_i463++) {
    c1_c_A[c1_i463] = c1_A[c1_i463];
  }

  if (CV_SCRIPT_IF(6, 4, c1_det(chartInstance, c1_c_A) == 0.0)) {
    _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 65);
    c1_A[0] = c1_w1[1];
    c1_A[2] = -c1_w2[1];
    c1_A[1] = c1_w1[2];
    c1_A[3] = -c1_w2[2];
    _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 66);
    c1_d_r2[0] = c1_r2[1] - c1_r1[1];
    c1_d_r2[1] = c1_r2[2] - c1_r1[2];
    for (c1_i464 = 0; c1_i464 < 2; c1_i464++) {
      c1_vec[c1_i464] = c1_d_r2[c1_i464];
    }
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 69);
  for (c1_i465 = 0; c1_i465 < 4; c1_i465++) {
    c1_d_A[c1_i465] = c1_A[c1_i465];
  }

  for (c1_i466 = 0; c1_i466 < 2; c1_i466++) {
    c1_B[c1_i466] = c1_vec[c1_i466];
  }

  c1_x = c1_d_A[1];
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_y = muDoubleScalarAbs(c1_c_x);
  c1_d_x = 0.0;
  c1_e_x = c1_d_x;
  c1_b_y = muDoubleScalarAbs(c1_e_x);
  c1_d = c1_y + c1_b_y;
  c1_f_x = c1_d_A[0];
  c1_g_x = c1_f_x;
  c1_h_x = c1_g_x;
  c1_c_y = muDoubleScalarAbs(c1_h_x);
  c1_i_x = 0.0;
  c1_j_x = c1_i_x;
  c1_d_y = muDoubleScalarAbs(c1_j_x);
  c1_b_d = c1_c_y + c1_d_y;
  if (c1_d > c1_b_d) {
    c1_b_r1 = 2;
    c1_e_r2 = 1;
  } else {
    c1_b_r1 = 1;
    c1_e_r2 = 2;
  }

  c1_k_x = c1_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_e_r2), 1, 2, 1, 0) - 1];
  c1_e_y = c1_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_b_r1), 1, 2, 1, 0) - 1];
  c1_a21 = c1_k_x / c1_e_y;
  c1_a = c1_a21;
  c1_b = c1_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_b_r1), 1, 2, 1, 0) + 1];
  c1_f_y = c1_a * c1_b;
  c1_a22 = c1_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_e_r2), 1, 2, 1, 0) + 1] - c1_f_y;
  guard1 = FALSE;
  if (c1_a22 == 0.0) {
    guard1 = TRUE;
  } else {
    if (c1_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_r1), 1, 2, 1, 0) - 1] == 0.0) {
      guard1 = TRUE;
    }
  }

  if (guard1 == TRUE) {
    c1_eml_warning(chartInstance);
  }

  c1_b_a = c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_b_r1), 1, 2, 1, 0) - 1];
  c1_b_b = c1_a21;
  c1_g_y = c1_b_a * c1_b_b;
  c1_l_x = c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_e_r2), 1, 2, 1, 0) - 1] - c1_g_y;
  c1_h_y = c1_a22;
  c1_z = c1_l_x / c1_h_y;
  c1_cof[1] = c1_z;
  c1_c_a = c1_cof[1];
  c1_c_b = c1_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_b_r1), 1, 2, 1, 0) + 1];
  c1_i_y = c1_c_a * c1_c_b;
  c1_m_x = c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_b_r1), 1, 2, 1, 0) - 1] - c1_i_y;
  c1_j_y = c1_d_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c1_b_r1), 1, 2, 1, 0) - 1];
  c1_b_z = c1_m_x / c1_j_y;
  c1_cof[0] = c1_b_z;
  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, 71);
  for (c1_i467 = 0; c1_i467 < 3; c1_i467++) {
    c1_d_a[c1_i467] = c1_w1[c1_i467];
  }

  c1_d_b = c1_cof[0];
  for (c1_i468 = 0; c1_i468 < 3; c1_i468++) {
    c1_d_a[c1_i468] *= c1_d_b;
  }

  for (c1_i469 = 0; c1_i469 < 3; c1_i469++) {
    c1_r[c1_i469] = c1_r1[c1_i469] + c1_d_a[c1_i469];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c1_sfEvent, -71);
  sf_debug_symbol_scope_pop();
}

static real_T c1_det(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
                     *chartInstance, real_T c1_x[4])
{
  real_T c1_y;
  int32_T c1_info;
  int32_T c1_ipiv[2];
  real_T c1_a;
  real_T c1_b;
  boolean_T c1_isodd;
  c1_d_eml_matlab_zgetrf(chartInstance, c1_x, c1_ipiv, &c1_info);
  c1_y = c1_x[0];
  c1_a = c1_y;
  c1_b = c1_x[3];
  c1_y = c1_a * c1_b;
  c1_isodd = FALSE;
  if ((real_T)c1_ipiv[0] > 1.0) {
    c1_isodd = TRUE;
  }

  if (c1_isodd) {
    c1_y = -c1_y;
  }

  return c1_y;
}

static void c1_b_eml_matlab_zgetrf
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, real_T c1_A[4],
   real_T c1_b_A[4], int32_T c1_ipiv[2], int32_T *c1_info)
{
  int32_T c1_i470;
  for (c1_i470 = 0; c1_i470 < 4; c1_i470++) {
    c1_b_A[c1_i470] = c1_A[c1_i470];
  }

  c1_d_eml_matlab_zgetrf(chartInstance, c1_b_A, c1_ipiv, c1_info);
}

static void c1_eml_xger(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_alpha1, real_T c1_A[4], real_T c1_b_A[4])
{
  int32_T c1_i471;
  for (c1_i471 = 0; c1_i471 < 4; c1_i471++) {
    c1_b_A[c1_i471] = c1_A[c1_i471];
  }

  c1_b_eml_xger(chartInstance, c1_alpha1, c1_b_A);
}

static void c1_b_eml_error(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance)
{
  int32_T c1_i472;
  static char_T c1_varargin_1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o',
    'o', 'l', 'b', 'o', 'x', ':', 's', 'q', 'r', 't', '_', 'd', 'o', 'm', 'a',
    'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c1_u[30];
  const mxArray *c1_y = NULL;
  for (c1_i472 = 0; c1_i472 < 30; c1_i472++) {
    c1_u[c1_i472] = c1_varargin_1[c1_i472];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c1_y));
}

static real_T c1_b_subPro1(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[4], real_T c1_q[3])
{
  real_T c1_theta;
  uint32_T c1_debug_family_var_map[13];
  real_T c1_velociy[3];
  real_T c1_w[3];
  real_T c1_r[3];
  real_T c1_u[3];
  real_T c1_v[3];
  real_T c1_up[3];
  real_T c1_vp[3];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i473;
  int32_T c1_i474;
  int32_T c1_i475;
  real_T c1_b_velociy[3];
  int32_T c1_i476;
  real_T c1_b_w[3];
  real_T c1_b[3];
  int32_T c1_i477;
  int32_T c1_i478;
  int32_T c1_i479;
  int32_T c1_i480;
  real_T c1_a[3];
  int32_T c1_i481;
  real_T c1_y;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i482;
  real_T c1_b_b;
  int32_T c1_i483;
  int32_T c1_i484;
  int32_T c1_i485;
  int32_T c1_i486;
  real_T c1_b_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_i487;
  real_T c1_c_b;
  int32_T c1_i488;
  int32_T c1_i489;
  int32_T c1_i490;
  int32_T c1_i491;
  real_T c1_b_up[3];
  int32_T c1_i492;
  real_T c1_b_vp[3];
  real_T c1_c_y;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_i493;
  int32_T c1_i494;
  real_T c1_d_y;
  int32_T c1_g_k;
  int32_T c1_h_k;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c1_j_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_velociy, 0U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 1U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r, 2U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_u, 3U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_v, 4U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_up, 5U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_vp, 6U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 7U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 8U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p, 10U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_q, 11U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 12U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 4);
  for (c1_i473 = 0; c1_i473 < 3; c1_i473++) {
    c1_velociy[c1_i473] = c1_kx[c1_i473];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 5);
  for (c1_i474 = 0; c1_i474 < 3; c1_i474++) {
    c1_w[c1_i474] = c1_kx[c1_i474 + 3];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 6);
  for (c1_i475 = 0; c1_i475 < 3; c1_i475++) {
    c1_b_velociy[c1_i475] = c1_velociy[c1_i475];
  }

  for (c1_i476 = 0; c1_i476 < 3; c1_i476++) {
    c1_b_w[c1_i476] = c1_w[c1_i476];
  }

  c1_cross(chartInstance, c1_b_velociy, c1_b_w, c1_b);
  for (c1_i477 = 0; c1_i477 < 3; c1_i477++) {
    c1_r[c1_i477] = -c1_b[c1_i477];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 8);
  for (c1_i478 = 0; c1_i478 < 3; c1_i478++) {
    c1_u[c1_i478] = c1_p[c1_i478] - c1_r[c1_i478];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 9);
  for (c1_i479 = 0; c1_i479 < 3; c1_i479++) {
    c1_v[c1_i479] = c1_q[c1_i479] - c1_r[c1_i479];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 12);
  for (c1_i480 = 0; c1_i480 < 3; c1_i480++) {
    c1_a[c1_i480] = c1_w[c1_i480];
  }

  for (c1_i481 = 0; c1_i481 < 3; c1_i481++) {
    c1_b[c1_i481] = c1_u[c1_i481];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i482 = 0; c1_i482 < 3; c1_i482++) {
    c1_b[c1_i482] = c1_w[c1_i482];
  }

  c1_b_b = c1_y;
  for (c1_i483 = 0; c1_i483 < 3; c1_i483++) {
    c1_b[c1_i483] *= c1_b_b;
  }

  for (c1_i484 = 0; c1_i484 < 3; c1_i484++) {
    c1_up[c1_i484] = c1_u[c1_i484] - c1_b[c1_i484];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 13);
  for (c1_i485 = 0; c1_i485 < 3; c1_i485++) {
    c1_a[c1_i485] = c1_w[c1_i485];
  }

  for (c1_i486 = 0; c1_i486 < 3; c1_i486++) {
    c1_b[c1_i486] = c1_u[c1_i486];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_b_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_c_k = 1; c1_c_k < 4; c1_c_k++) {
    c1_d_k = c1_c_k;
    c1_b_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_d_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i487 = 0; c1_i487 < 3; c1_i487++) {
    c1_b[c1_i487] = c1_w[c1_i487];
  }

  c1_c_b = c1_b_y;
  for (c1_i488 = 0; c1_i488 < 3; c1_i488++) {
    c1_b[c1_i488] *= c1_c_b;
  }

  for (c1_i489 = 0; c1_i489 < 3; c1_i489++) {
    c1_vp[c1_i489] = c1_v[c1_i489] - c1_b[c1_i489];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 19);
  for (c1_i490 = 0; c1_i490 < 3; c1_i490++) {
    c1_a[c1_i490] = c1_w[c1_i490];
  }

  for (c1_i491 = 0; c1_i491 < 3; c1_i491++) {
    c1_b_up[c1_i491] = c1_up[c1_i491];
  }

  for (c1_i492 = 0; c1_i492 < 3; c1_i492++) {
    c1_b_vp[c1_i492] = c1_vp[c1_i492];
  }

  c1_cross(chartInstance, c1_b_up, c1_b_vp, c1_b);
  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_c_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_e_k = 1; c1_e_k < 4; c1_e_k++) {
    c1_f_k = c1_e_k;
    c1_c_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_f_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_f_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i493 = 0; c1_i493 < 3; c1_i493++) {
    c1_a[c1_i493] = c1_up[c1_i493];
  }

  for (c1_i494 = 0; c1_i494 < 3; c1_i494++) {
    c1_b[c1_i494] = c1_vp[c1_i494];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_d_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_g_k = 1; c1_g_k < 4; c1_g_k++) {
    c1_h_k = c1_g_k;
    c1_d_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_h_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_h_k), 1, 3, 1, 0) - 1];
  }

  c1_theta = c1_atan2(chartInstance, c1_c_y, c1_d_y);
  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, -19);
  sf_debug_symbol_scope_pop();
  return c1_theta;
}

static real_T c1_c_subPro1(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_kx[6], real_T c1_p[3], real_T c1_q[4])
{
  real_T c1_theta;
  uint32_T c1_debug_family_var_map[13];
  real_T c1_velociy[3];
  real_T c1_w[3];
  real_T c1_r[3];
  real_T c1_u[3];
  real_T c1_v[3];
  real_T c1_up[3];
  real_T c1_vp[3];
  real_T c1_nargin = 3.0;
  real_T c1_nargout = 1.0;
  int32_T c1_i495;
  int32_T c1_i496;
  int32_T c1_i497;
  real_T c1_b_velociy[3];
  int32_T c1_i498;
  real_T c1_b_w[3];
  real_T c1_b[3];
  int32_T c1_i499;
  int32_T c1_i500;
  int32_T c1_i501;
  int32_T c1_i502;
  real_T c1_a[3];
  int32_T c1_i503;
  real_T c1_y;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i504;
  real_T c1_b_b;
  int32_T c1_i505;
  int32_T c1_i506;
  int32_T c1_i507;
  int32_T c1_i508;
  real_T c1_b_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_i509;
  real_T c1_c_b;
  int32_T c1_i510;
  int32_T c1_i511;
  int32_T c1_i512;
  int32_T c1_i513;
  real_T c1_b_up[3];
  int32_T c1_i514;
  real_T c1_b_vp[3];
  real_T c1_c_y;
  int32_T c1_e_k;
  int32_T c1_f_k;
  int32_T c1_i515;
  int32_T c1_i516;
  real_T c1_d_y;
  int32_T c1_g_k;
  int32_T c1_h_k;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c1_k_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c1_velociy, 0U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_w, 1U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_r, 2U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_u, 3U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_v, 4U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_up, 5U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_vp, 6U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 7U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 8U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_kx, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_p, 10U, c1_d_sf_marshallOut,
    c1_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_q, 11U, c1_j_sf_marshallOut,
    c1_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_theta, 12U, c1_e_sf_marshallOut,
    c1_d_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 4);
  for (c1_i495 = 0; c1_i495 < 3; c1_i495++) {
    c1_velociy[c1_i495] = c1_kx[c1_i495];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 5);
  for (c1_i496 = 0; c1_i496 < 3; c1_i496++) {
    c1_w[c1_i496] = c1_kx[c1_i496 + 3];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 6);
  for (c1_i497 = 0; c1_i497 < 3; c1_i497++) {
    c1_b_velociy[c1_i497] = c1_velociy[c1_i497];
  }

  for (c1_i498 = 0; c1_i498 < 3; c1_i498++) {
    c1_b_w[c1_i498] = c1_w[c1_i498];
  }

  c1_cross(chartInstance, c1_b_velociy, c1_b_w, c1_b);
  for (c1_i499 = 0; c1_i499 < 3; c1_i499++) {
    c1_r[c1_i499] = -c1_b[c1_i499];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 8);
  for (c1_i500 = 0; c1_i500 < 3; c1_i500++) {
    c1_u[c1_i500] = c1_p[c1_i500] - c1_r[c1_i500];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 9);
  for (c1_i501 = 0; c1_i501 < 3; c1_i501++) {
    c1_v[c1_i501] = c1_q[c1_i501] - c1_r[c1_i501];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 12);
  for (c1_i502 = 0; c1_i502 < 3; c1_i502++) {
    c1_a[c1_i502] = c1_w[c1_i502];
  }

  for (c1_i503 = 0; c1_i503 < 3; c1_i503++) {
    c1_b[c1_i503] = c1_u[c1_i503];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_k = 1; c1_k < 4; c1_k++) {
    c1_b_k = c1_k;
    c1_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c1_b_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i504 = 0; c1_i504 < 3; c1_i504++) {
    c1_b[c1_i504] = c1_w[c1_i504];
  }

  c1_b_b = c1_y;
  for (c1_i505 = 0; c1_i505 < 3; c1_i505++) {
    c1_b[c1_i505] *= c1_b_b;
  }

  for (c1_i506 = 0; c1_i506 < 3; c1_i506++) {
    c1_up[c1_i506] = c1_u[c1_i506] - c1_b[c1_i506];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 13);
  for (c1_i507 = 0; c1_i507 < 3; c1_i507++) {
    c1_a[c1_i507] = c1_w[c1_i507];
  }

  for (c1_i508 = 0; c1_i508 < 3; c1_i508++) {
    c1_b[c1_i508] = c1_u[c1_i508];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_b_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_c_k = 1; c1_c_k < 4; c1_c_k++) {
    c1_d_k = c1_c_k;
    c1_b_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_d_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i509 = 0; c1_i509 < 3; c1_i509++) {
    c1_b[c1_i509] = c1_w[c1_i509];
  }

  c1_c_b = c1_b_y;
  for (c1_i510 = 0; c1_i510 < 3; c1_i510++) {
    c1_b[c1_i510] *= c1_c_b;
  }

  for (c1_i511 = 0; c1_i511 < 3; c1_i511++) {
    c1_vp[c1_i511] = c1_v[c1_i511] - c1_b[c1_i511];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, 19);
  for (c1_i512 = 0; c1_i512 < 3; c1_i512++) {
    c1_a[c1_i512] = c1_w[c1_i512];
  }

  for (c1_i513 = 0; c1_i513 < 3; c1_i513++) {
    c1_b_up[c1_i513] = c1_up[c1_i513];
  }

  for (c1_i514 = 0; c1_i514 < 3; c1_i514++) {
    c1_b_vp[c1_i514] = c1_vp[c1_i514];
  }

  c1_cross(chartInstance, c1_b_up, c1_b_vp, c1_b);
  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_c_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_e_k = 1; c1_e_k < 4; c1_e_k++) {
    c1_f_k = c1_e_k;
    c1_c_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_f_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_f_k), 1, 3, 1, 0) - 1];
  }

  for (c1_i515 = 0; c1_i515 < 3; c1_i515++) {
    c1_a[c1_i515] = c1_up[c1_i515];
  }

  for (c1_i516 = 0; c1_i516 < 3; c1_i516++) {
    c1_b[c1_i516] = c1_vp[c1_i516];
  }

  c1_g_eml_scalar_eg(chartInstance);
  c1_g_eml_scalar_eg(chartInstance);
  c1_d_y = 0.0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_g_k = 1; c1_g_k < 4; c1_g_k++) {
    c1_h_k = c1_g_k;
    c1_d_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c1_h_k), 1, 3, 1, 0) - 1] * c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_h_k), 1, 3, 1, 0) - 1];
  }

  c1_theta = c1_atan2(chartInstance, c1_c_y, c1_d_y);
  _SFD_SCRIPT_CALL(5U, chartInstance->c1_sfEvent, -19);
  sf_debug_symbol_scope_pop();
  return c1_theta;
}

static const mxArray *c1_m_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_n_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i517;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i517, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i517;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_o_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_b_is_active_c1_CtrPlatform_AdaptiveControl1, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_CtrPlatform_AdaptiveControl1), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_CtrPlatform_AdaptiveControl1);
  return c1_y;
}

static uint8_T c1_p_emlrt_marshallIn
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, const mxArray
   *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_eml_matlab_zgetrf
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, real_T c1_A
   [16], int32_T c1_ipiv[4], int32_T *c1_info)
{
  int32_T c1_i518;
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_jm1;
  int32_T c1_b;
  int32_T c1_mmj;
  int32_T c1_b_a;
  int32_T c1_c;
  int32_T c1_b_b;
  int32_T c1_jj;
  int32_T c1_c_a;
  int32_T c1_jp1j;
  int32_T c1_d_a;
  int32_T c1_b_c;
  int32_T c1_i519;
  int32_T c1_i520;
  int32_T c1_i521;
  real_T c1_b_A[16];
  int32_T c1_e_a;
  int32_T c1_jpiv_offset;
  int32_T c1_f_a;
  int32_T c1_c_b;
  int32_T c1_jpiv;
  int32_T c1_g_a;
  int32_T c1_d_b;
  int32_T c1_c_c;
  int32_T c1_e_b;
  int32_T c1_jrow;
  int32_T c1_h_a;
  int32_T c1_f_b;
  int32_T c1_jprow;
  int32_T c1_ix0;
  int32_T c1_iy0;
  int32_T c1_b_ix0;
  int32_T c1_b_iy0;
  int32_T c1_c_ix0;
  int32_T c1_c_iy0;
  int32_T c1_ix;
  int32_T c1_iy;
  int32_T c1_k;
  real_T c1_temp;
  int32_T c1_i_a;
  int32_T c1_j_a;
  int32_T c1_b_jp1j;
  int32_T c1_k_a;
  int32_T c1_d_c;
  int32_T c1_l_a;
  int32_T c1_g_b;
  int32_T c1_i522;
  int32_T c1_i;
  int32_T c1_b_i;
  real_T c1_x;
  real_T c1_y;
  real_T c1_z;
  int32_T c1_h_b;
  int32_T c1_e_c;
  int32_T c1_m_a;
  int32_T c1_f_c;
  int32_T c1_n_a;
  int32_T c1_g_c;
  int32_T c1_m;
  int32_T c1_n;
  int32_T c1_d_ix0;
  int32_T c1_d_iy0;
  int32_T c1_ia0;
  int32_T c1_b_m;
  int32_T c1_b_n;
  int32_T c1_e_ix0;
  int32_T c1_e_iy0;
  int32_T c1_b_ia0;
  int32_T c1_c_m;
  int32_T c1_c_n;
  int32_T c1_f_ix0;
  int32_T c1_f_iy0;
  int32_T c1_c_ia0;
  int32_T c1_d_m;
  int32_T c1_d_n;
  int32_T c1_g_ix0;
  int32_T c1_g_iy0;
  int32_T c1_d_ia0;
  int32_T c1_e_m;
  int32_T c1_e_n;
  int32_T c1_h_ix0;
  int32_T c1_h_iy0;
  int32_T c1_e_ia0;
  int32_T c1_ixstart;
  int32_T c1_o_a;
  int32_T c1_jA;
  int32_T c1_jy;
  int32_T c1_loop_ub;
  int32_T c1_c_j;
  real_T c1_yjy;
  real_T c1_b_temp;
  int32_T c1_b_ix;
  int32_T c1_i_b;
  int32_T c1_i523;
  int32_T c1_p_a;
  int32_T c1_j_b;
  int32_T c1_i524;
  int32_T c1_ijA;
  int32_T c1_b_ijA;
  int32_T c1_q_a;
  int32_T c1_r_a;
  int32_T c1_s_a;
  c1_realmin(chartInstance);
  c1_eps(chartInstance);
  for (c1_i518 = 0; c1_i518 < 4; c1_i518++) {
    c1_ipiv[c1_i518] = 1 + c1_i518;
  }

  *c1_info = 0;
  c1_eml_int_forloop_overflow_check(chartInstance);
  for (c1_j = 1; c1_j < 4; c1_j++) {
    c1_b_j = c1_j;
    c1_a = c1_b_j - 1;
    c1_jm1 = c1_a;
    c1_b = c1_b_j;
    c1_mmj = 4 - c1_b;
    c1_b_a = c1_jm1;
    c1_c = c1_b_a * 5;
    c1_b_b = c1_c + 1;
    c1_jj = c1_b_b;
    c1_c_a = c1_jj + 1;
    c1_jp1j = c1_c_a;
    c1_d_a = c1_mmj;
    c1_b_c = c1_d_a;
    c1_i519 = 0;
    for (c1_i520 = 0; c1_i520 < 4; c1_i520++) {
      for (c1_i521 = 0; c1_i521 < 4; c1_i521++) {
        c1_b_A[c1_i521 + c1_i519] = c1_A[c1_i521 + c1_i519];
      }

      c1_i519 += 4;
    }

    c1_e_a = c1_eml_ixamax(chartInstance, c1_b_c + 1, c1_b_A, c1_jj) - 1;
    c1_jpiv_offset = c1_e_a;
    c1_f_a = c1_jj;
    c1_c_b = c1_jpiv_offset;
    c1_jpiv = c1_f_a + c1_c_b;
    if (c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if ((real_T)c1_jpiv_offset != 0.0) {
        c1_g_a = c1_b_j;
        c1_d_b = c1_jpiv_offset;
        c1_c_c = c1_g_a + c1_d_b;
        c1_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_j), 1, 4, 1, 0) - 1] = c1_c_c;
        c1_e_b = c1_jm1 + 1;
        c1_jrow = c1_e_b;
        c1_h_a = c1_jrow;
        c1_f_b = c1_jpiv_offset;
        c1_jprow = c1_h_a + c1_f_b;
        c1_ix0 = c1_jrow;
        c1_iy0 = c1_jprow;
        c1_b_ix0 = c1_ix0;
        c1_b_iy0 = c1_iy0;
        c1_c_ix0 = c1_b_ix0;
        c1_c_iy0 = c1_b_iy0;
        c1_ix = c1_c_ix0;
        c1_iy = c1_c_iy0;
        c1_c_eml_int_forloop_overflow_check(chartInstance);
        for (c1_k = 1; c1_k < 5; c1_k++) {
          c1_temp = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 16, 1, 0) - 1];
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_ix), 1, 16, 1, 0) - 1] = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK
            ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_iy), 1, 16, 1, 0) -
            1];
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_iy), 1, 16, 1, 0) - 1] = c1_temp;
          c1_i_a = c1_ix + 4;
          c1_ix = c1_i_a;
          c1_j_a = c1_iy + 4;
          c1_iy = c1_j_a;
        }
      }

      c1_b_jp1j = c1_jp1j;
      c1_k_a = c1_mmj;
      c1_d_c = c1_k_a;
      c1_l_a = c1_jp1j;
      c1_g_b = c1_d_c - 1;
      c1_i522 = c1_l_a + c1_g_b;
      c1_d_eml_int_forloop_overflow_check(chartInstance, c1_b_jp1j, c1_i522);
      for (c1_i = c1_b_jp1j; c1_i <= c1_i522; c1_i++) {
        c1_b_i = c1_i;
        c1_x = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c1_b_i), 1, 16, 1, 0) - 1];
        c1_y = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c1_jj), 1, 16, 1, 0) - 1];
        c1_z = c1_x / c1_y;
        c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_i), 1, 16, 1, 0) - 1] = c1_z;
      }
    } else {
      *c1_info = c1_b_j;
    }

    c1_h_b = c1_b_j;
    c1_e_c = 4 - c1_h_b;
    c1_m_a = c1_jj;
    c1_f_c = c1_m_a;
    c1_n_a = c1_jj;
    c1_g_c = c1_n_a;
    c1_m = c1_mmj;
    c1_n = c1_e_c;
    c1_d_ix0 = c1_jp1j;
    c1_d_iy0 = c1_f_c + 4;
    c1_ia0 = c1_g_c + 5;
    c1_b_m = c1_m;
    c1_b_n = c1_n;
    c1_e_ix0 = c1_d_ix0;
    c1_e_iy0 = c1_d_iy0;
    c1_b_ia0 = c1_ia0;
    c1_c_m = c1_b_m;
    c1_c_n = c1_b_n;
    c1_f_ix0 = c1_e_ix0;
    c1_f_iy0 = c1_e_iy0;
    c1_c_ia0 = c1_b_ia0;
    c1_d_m = c1_c_m;
    c1_d_n = c1_c_n;
    c1_g_ix0 = c1_f_ix0;
    c1_g_iy0 = c1_f_iy0;
    c1_d_ia0 = c1_c_ia0;
    c1_e_m = c1_d_m;
    c1_e_n = c1_d_n;
    c1_h_ix0 = c1_g_ix0;
    c1_h_iy0 = c1_g_iy0;
    c1_e_ia0 = c1_d_ia0;
    c1_ixstart = c1_h_ix0;
    c1_o_a = c1_e_ia0 - 1;
    c1_jA = c1_o_a;
    c1_jy = c1_h_iy0;
    c1_d_eml_int_forloop_overflow_check(chartInstance, 1, c1_e_n);
    c1_loop_ub = c1_e_n;
    for (c1_c_j = 1; c1_c_j <= c1_loop_ub; c1_c_j++) {
      c1_yjy = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c1_jy), 1, 16, 1, 0) - 1];
      if (c1_yjy != 0.0) {
        c1_b_temp = -c1_yjy;
        c1_b_ix = c1_ixstart;
        c1_i_b = c1_jA + 1;
        c1_i523 = c1_i_b;
        c1_p_a = c1_e_m;
        c1_j_b = c1_jA;
        c1_i524 = c1_p_a + c1_j_b;
        c1_d_eml_int_forloop_overflow_check(chartInstance, c1_i523, c1_i524);
        for (c1_ijA = c1_i523; c1_ijA <= c1_i524; c1_ijA++) {
          c1_b_ijA = c1_ijA;
          c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ijA), 1, 16, 1, 0) - 1] =
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ijA), 1, 16, 1, 0) - 1] +
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_ix), 1, 16, 1, 0) - 1] * c1_b_temp;
          c1_q_a = c1_b_ix + 1;
          c1_b_ix = c1_q_a;
        }
      }

      c1_r_a = c1_jy + 4;
      c1_jy = c1_r_a;
      c1_s_a = c1_jA + 4;
      c1_jA = c1_s_a;
    }
  }

  if ((real_T)*c1_info == 0.0) {
    if (!(c1_A[15] != 0.0)) {
      *c1_info = 4;
    }
  }
}

static void c1_b_eml_xtrsm(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_A[16], real_T c1_B[16])
{
  int32_T c1_j;
  int32_T c1_b_j;
  int32_T c1_a;
  int32_T c1_c;
  int32_T c1_b;
  int32_T c1_b_c;
  int32_T c1_b_b;
  int32_T c1_jBcol;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_b_a;
  int32_T c1_c_c;
  int32_T c1_c_b;
  int32_T c1_d_c;
  int32_T c1_d_b;
  int32_T c1_kAcol;
  int32_T c1_c_a;
  int32_T c1_e_b;
  int32_T c1_e_c;
  int32_T c1_d_a;
  int32_T c1_i525;
  int32_T c1_i;
  int32_T c1_b_i;
  int32_T c1_e_a;
  int32_T c1_f_b;
  int32_T c1_f_c;
  int32_T c1_f_a;
  int32_T c1_g_b;
  int32_T c1_g_c;
  int32_T c1_g_a;
  int32_T c1_h_b;
  int32_T c1_h_c;
  int32_T c1_h_a;
  int32_T c1_i_b;
  int32_T c1_i_c;
  c1_below_threshold(chartInstance);
  c1_c_eml_scalar_eg(chartInstance);
  c1_c_eml_int_forloop_overflow_check(chartInstance);
  for (c1_j = 1; c1_j < 5; c1_j++) {
    c1_b_j = c1_j;
    c1_a = c1_b_j;
    c1_c = c1_a;
    c1_b = c1_c - 1;
    c1_b_c = c1_b << 2;
    c1_b_b = c1_b_c;
    c1_jBcol = c1_b_b;
    c1_c_eml_int_forloop_overflow_check(chartInstance);
    for (c1_k = 1; c1_k < 5; c1_k++) {
      c1_b_k = c1_k;
      c1_b_a = c1_b_k;
      c1_c_c = c1_b_a;
      c1_c_b = c1_c_c - 1;
      c1_d_c = c1_c_b << 2;
      c1_d_b = c1_d_c;
      c1_kAcol = c1_d_b;
      c1_c_a = c1_b_k;
      c1_e_b = c1_jBcol;
      c1_e_c = c1_c_a + c1_e_b;
      if (c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_e_c), 1, 16, 1, 0) - 1] != 0.0) {
        c1_d_a = c1_b_k + 1;
        c1_i525 = c1_d_a;
        c1_d_eml_int_forloop_overflow_check(chartInstance, c1_i525, 4);
        for (c1_i = c1_i525; c1_i < 5; c1_i++) {
          c1_b_i = c1_i;
          c1_e_a = c1_b_i;
          c1_f_b = c1_jBcol;
          c1_f_c = c1_e_a + c1_f_b;
          c1_f_a = c1_b_i;
          c1_g_b = c1_jBcol;
          c1_g_c = c1_f_a + c1_g_b;
          c1_g_a = c1_b_k;
          c1_h_b = c1_jBcol;
          c1_h_c = c1_g_a + c1_h_b;
          c1_h_a = c1_b_i;
          c1_i_b = c1_kAcol;
          c1_i_c = c1_h_a + c1_i_b;
          c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_f_c), 1, 16, 1, 0) - 1] =
            c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_g_c), 1, 16, 1, 0) - 1] -
            c1_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_h_c), 1, 16, 1, 0) - 1] *
            c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_i_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void c1_d_eml_matlab_zgetrf
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance, real_T c1_A[4],
   int32_T c1_ipiv[2], int32_T *c1_info)
{
  int32_T c1_i526;
  int32_T c1_idxmax;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_y;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_b_y;
  real_T c1_smax;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_c_y;
  real_T c1_i_x;
  real_T c1_j_x;
  real_T c1_d_y;
  real_T c1_s;
  int32_T c1_a;
  int32_T c1_jpiv_offset;
  int32_T c1_b;
  int32_T c1_jpiv;
  int32_T c1_b_b;
  int32_T c1_c;
  int32_T c1_c_b;
  int32_T c1_jprow;
  int32_T c1_iy0;
  int32_T c1_b_iy0;
  int32_T c1_c_iy0;
  int32_T c1_ix;
  int32_T c1_iy;
  int32_T c1_k;
  real_T c1_temp;
  int32_T c1_b_a;
  int32_T c1_c_a;
  real_T c1_k_x;
  real_T c1_e_y;
  real_T c1_z;
  real_T c1_d1;
  c1_realmin(chartInstance);
  c1_eps(chartInstance);
  for (c1_i526 = 0; c1_i526 < 2; c1_i526++) {
    c1_ipiv[c1_i526] = 1 + c1_i526;
  }

  *c1_info = 0;
  c1_idxmax = 1;
  c1_x = c1_A[0];
  c1_b_x = c1_x;
  c1_c_x = c1_b_x;
  c1_y = muDoubleScalarAbs(c1_c_x);
  c1_d_x = 0.0;
  c1_e_x = c1_d_x;
  c1_b_y = muDoubleScalarAbs(c1_e_x);
  c1_smax = c1_y + c1_b_y;
  c1_f_x = c1_A[1];
  c1_g_x = c1_f_x;
  c1_h_x = c1_g_x;
  c1_c_y = muDoubleScalarAbs(c1_h_x);
  c1_i_x = 0.0;
  c1_j_x = c1_i_x;
  c1_d_y = muDoubleScalarAbs(c1_j_x);
  c1_s = c1_c_y + c1_d_y;
  if (c1_s > c1_smax) {
    c1_idxmax = 2;
  }

  c1_a = c1_idxmax - 1;
  c1_jpiv_offset = c1_a;
  c1_b = c1_jpiv_offset;
  c1_jpiv = c1_b;
  if (c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c1_jpiv + 1)), 1, 4, 1, 0) - 1] != 0.0) {
    if ((real_T)c1_jpiv_offset != 0.0) {
      c1_b_b = c1_jpiv_offset;
      c1_c = c1_b_b;
      c1_ipiv[0] = c1_c + 1;
      c1_c_b = c1_jpiv_offset;
      c1_jprow = c1_c_b;
      c1_iy0 = c1_jprow + 1;
      c1_b_iy0 = c1_iy0;
      c1_c_iy0 = c1_b_iy0;
      c1_ix = 1;
      c1_iy = c1_c_iy0;
      c1_d_eml_int_forloop_overflow_check(chartInstance, 1, 2);
      for (c1_k = 1; c1_k < 3; c1_k++) {
        c1_temp = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_ix), 1, 4, 1, 0) - 1];
        c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_ix), 1, 4, 1, 0) - 1] = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_iy), 1, 4, 1, 0) - 1];
        c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_iy), 1, 4, 1, 0) - 1] = c1_temp;
        c1_b_a = c1_ix + 2;
        c1_ix = c1_b_a;
        c1_c_a = c1_iy + 2;
        c1_iy = c1_c_a;
      }
    }

    c1_k_x = c1_A[1];
    c1_e_y = c1_A[0];
    c1_z = c1_k_x / c1_e_y;
    c1_A[1] = c1_z;
  } else {
    *c1_info = 1;
  }

  c1_d1 = -1.0;
  c1_b_eml_xger(chartInstance, c1_d1, c1_A);
  if ((real_T)*c1_info == 0.0) {
    if (!(c1_A[3] != 0.0)) {
      *c1_info = 2;
    }
  }
}

static void c1_b_eml_xger(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct
  *chartInstance, real_T c1_alpha1, real_T c1_A[4])
{
  real_T c1_b_alpha1;
  real_T c1_c_alpha1;
  real_T c1_d_alpha1;
  real_T c1_yjy;
  real_T c1_temp;
  int32_T c1_ix;
  int32_T c1_ijA;
  int32_T c1_b_ijA;
  int32_T c1_a;
  c1_b_alpha1 = c1_alpha1;
  c1_c_alpha1 = c1_b_alpha1;
  c1_d_alpha1 = c1_c_alpha1;
  if (c1_d_alpha1 == 0.0) {
  } else {
    c1_yjy = c1_A[2];
    if (c1_yjy != 0.0) {
      c1_temp = c1_yjy * c1_d_alpha1;
      c1_ix = 2;
      c1_d_eml_int_forloop_overflow_check(chartInstance, 4, 4);
      for (c1_ijA = 4; c1_ijA < 5; c1_ijA++) {
        c1_b_ijA = c1_ijA;
        c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_b_ijA), 1, 4, 1, 0) - 1] = c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c1_b_ijA), 1, 4, 1, 0) -
          1] + c1_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c1_ix), 1, 4, 1, 0) - 1] * c1_temp;
        c1_a = c1_ix + 1;
        c1_ix = c1_a;
      }
    }
  }
}

static void init_dsm_address_info
  (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1213463906U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3692121198U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2895268780U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2840819788U);
}

mxArray *sf_c1_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Fr9gPROTYEiqXEjKtPaUOG");
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

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_CtrPlatform_AdaptiveControl1(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Theta\",},{M[8],M[0],T\"is_active_c1_CtrPlatform_AdaptiveControl1\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_CtrPlatform_AdaptiveControl1_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
    chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_CtrPlatform_AdaptiveControl1MachineNumber_,
           1,
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
          init_script_number_translation
            (_CtrPlatform_AdaptiveControl1MachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_CtrPlatform_AdaptiveControl1MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_CtrPlatform_AdaptiveControl1MachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"EndPos");
          _SFD_SET_DATA_PROPS(1,10,0,0,"init_Rot");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Theta");
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

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,214);
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
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"skew",0,-1,450);
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
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)
            c1_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)
            c1_b_sf_marshallIn);
        }

        {
          real_T (*c1_EndPos)[3];
          real_T (*c1_Theta)[6];
          c1_Theta = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_EndPos = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_EndPos);
          _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c1_init_Rot);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_Theta);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c1_L);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_CtrPlatform_AdaptiveControl1MachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization()
{
  return "AXRtAzFOHvSSasxEXz6Bg";
}

static void sf_opaque_initialize_c1_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
  initialize_c1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  enable_c1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  disable_c1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  sf_c1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_CtrPlatform_AdaptiveControl1
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CtrPlatform_AdaptiveControl1();/* state var info */
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

extern void sf_internal_set_sim_state_c1_CtrPlatform_AdaptiveControl1(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_CtrPlatform_AdaptiveControl1();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_CtrPlatform_AdaptiveControl1
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_CtrPlatform_AdaptiveControl1(S);
}

static void sf_opaque_set_sim_state_c1_CtrPlatform_AdaptiveControl1(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_CtrPlatform_AdaptiveControl1(S, st);
}

static void sf_opaque_terminate_c1_CtrPlatform_AdaptiveControl1(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_CtrPlatform_AdaptiveControl1
      ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_CtrPlatform_AdaptiveControl1_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_CtrPlatform_AdaptiveControl1
    ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_CtrPlatform_AdaptiveControl1(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_CtrPlatform_AdaptiveControl1
      ((SFc1_CtrPlatform_AdaptiveControl1InstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_CtrPlatform_AdaptiveControl1(SimStruct *S)
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
    mxArray *infoStruct = load_CtrPlatform_AdaptiveControl1_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1606085203U));
  ssSetChecksum1(S,(1643182354U));
  ssSetChecksum2(S,(1545550399U));
  ssSetChecksum3(S,(793392500U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_CtrPlatform_AdaptiveControl1(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_CtrPlatform_AdaptiveControl1(SimStruct *S)
{
  SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *chartInstance;
  chartInstance = (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct *)malloc
    (sizeof(SFc1_CtrPlatform_AdaptiveControl1InstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_CtrPlatform_AdaptiveControl1InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_CtrPlatform_AdaptiveControl1;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_CtrPlatform_AdaptiveControl1;
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

void c1_CtrPlatform_AdaptiveControl1_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_CtrPlatform_AdaptiveControl1(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_CtrPlatform_AdaptiveControl1(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_CtrPlatform_AdaptiveControl1(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_CtrPlatform_AdaptiveControl1_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
