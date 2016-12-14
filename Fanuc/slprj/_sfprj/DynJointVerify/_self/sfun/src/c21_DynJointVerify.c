/* Include files */

#include "blascompat32.h"
#include "DynJointVerify_sfun.h"
#include "c21_DynJointVerify.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DynJointVerify_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c21_debug_family_names[7] = { "L", "nargin", "nargout",
  "EnTheta", "EnOmega", "Cen", "Vel" };

static const char *c21_b_debug_family_names[6] = { "Cx1", "Cy1", "nargin",
  "nargout", "in3", "body_Jacobian_d1_" };

static const char *c21_c_debug_family_names[20] = { "A2", "Cx2", "Cy2", "Cz2",
  "L1", "L2", "t352", "t353", "t354", "t355", "t356", "t357", "t358", "t359",
  "nargin", "nargout", "in1", "in2", "in3", "body_Jacobian_d2_" };

static const char *c21_d_debug_family_names[46] = { "A2", "A3", "Cx3", "Cy3",
  "Cz3", "L1", "L2", "L3", "t319", "t320", "t321", "t322", "t323", "t324",
  "t325", "t326", "t327", "t328", "t329", "t338", "t330", "t331", "t336", "t332",
  "t333", "t334", "t335", "t337", "t339", "t340", "t341", "t342", "t343", "t344",
  "t345", "t346", "t350", "t347", "t348", "t349", "nargin", "nargout", "in1",
  "in2", "in3", "body_Jacobian_d3_" };

static const char *c21_e_debug_family_names[69] = { "A2", "A3", "A4", "Cx4",
  "Cy4", "Cz4", "L1", "L2", "L3", "L4", "t265", "t266", "t267", "t268", "t269",
  "t270", "t271", "t272", "t273", "t274", "t275", "t276", "t277", "t278", "t279",
  "t280", "t281", "t298", "t282", "t283", "t295", "t296", "t284", "t285", "t286",
  "t287", "t288", "t289", "t290", "t291", "t292", "t293", "t294", "t297", "t309",
  "t299", "t300", "t301", "t302", "t303", "t304", "t305", "t306", "t307", "t311",
  "t308", "t310", "t312", "t313", "t314", "t315", "t316", "t317", "nargin",
  "nargout", "in1", "in2", "in3", "body_Jacobian_d4_" };

static const char *c21_f_debug_family_names[121] = { "A2", "A3", "A4", "A5",
  "Cx5", "Cy5", "Cz5", "L1", "L2", "L3", "L4", "L5", "t161", "t162", "t163",
  "t164", "t165", "t166", "t167", "t168", "t169", "t170", "t205", "t171", "t172",
  "t173", "t174", "t175", "t206", "t176", "t177", "t178", "t179", "t180", "t181",
  "t216", "t217", "t182", "t215", "t183", "t184", "t185", "t186", "t187", "t188",
  "t189", "t190", "t191", "t199", "t192", "t193", "t194", "t195", "t196", "t197",
  "t227", "t198", "t200", "t207", "t201", "t202", "t203", "t204", "t208", "t253",
  "t209", "t210", "t211", "t212", "t213", "t214", "t218", "t219", "t220", "t221",
  "t236", "t222", "t224", "t225", "t223", "t226", "t251", "t228", "t229", "t230",
  "t231", "t232", "t233", "t234", "t235", "t237", "t238", "t239", "t240", "t241",
  "t242", "t243", "t244", "t245", "t246", "t252", "t247", "t248", "t249", "t250",
  "t254", "t255", "t256", "t257", "t258", "t259", "t260", "t261", "t262", "t263",
  "nargin", "nargout", "in1", "in2", "in3", "body_Jacobian_d5_" };

static const char *c21_g_debug_family_names[177] = { "A2", "A3", "A4", "A5",
  "A6", "Cx6", "Cy6", "Cz6", "L1", "L2", "L3", "L4", "L5", "t2", "t3", "t4",
  "t5", "t6", "t7", "t8", "t9", "t10", "t11", "t27", "t12", "t13", "t14", "t15",
  "t16", "t55", "t17", "t18", "t19", "t20", "t21", "t22", "t23", "t24", "t56",
  "t57", "t25", "t26", "t28", "t29", "t30", "t31", "t67", "t68", "t32", "t66",
  "t33", "t34", "t35", "t36", "t37", "t38", "t39", "t40", "t41", "t49", "t42",
  "t43", "t44", "t45", "t46", "t47", "t95", "t48", "t50", "t58", "t51", "t52",
  "t53", "t54", "t59", "t112", "t113", "t60", "t61", "t62", "t63", "t64", "t65",
  "t69", "t70", "t71", "t72", "t73", "t94", "t74", "t75", "t76", "t77", "t78",
  "t104", "t79", "t80", "t81", "t82", "t105", "t83", "t84", "t85", "t86", "t87",
  "t88", "t89", "t90", "t91", "t92", "t93", "t96", "t97", "t98", "t99", "t100",
  "t101", "t102", "t148", "t103", "t106", "t107", "t108", "t109", "t111", "t110",
  "t114", "t115", "t116", "t117", "t118", "t119", "t127", "t120", "t121", "t122",
  "t123", "t124", "t138", "t125", "t126", "t128", "t129", "t139", "t130", "t131",
  "t132", "t133", "t134", "t135", "t136", "t151", "t152", "t137", "t140", "t142",
  "t141", "t143", "t144", "t145", "t146", "t149", "t147", "t150", "t153", "t154",
  "t155", "t156", "t157", "t158", "t159", "nargin", "nargout", "in1", "in2",
  "in3", "body_Jacobian_d6_" };

/* Function Declarations */
static void initialize_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);
static void initialize_params_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance);
static void enable_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);
static void disable_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);
static void c21_update_debugger_state_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance);
static void set_sim_state_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct *
  chartInstance, const mxArray *c21_st);
static void finalize_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);
static void sf_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);
static void c21_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber);
static void c21_body_Jacobian_d1(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in3[18], real_T c21_body_Jacobian_d1_[36]);
static void c21_eml_scalar_eg(SFc21_DynJointVerifyInstanceStruct *chartInstance);
static void c21_b_eml_scalar_eg(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);
static void c21_body_Jacobian_d2(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T c21_in3[18],
  real_T c21_body_Jacobian_d2_[36]);
static void c21_body_Jacobian_d3(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T c21_in3[18],
  real_T c21_body_Jacobian_d3_[36]);
static void c21_body_Jacobian_d4(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T c21_in3[18],
  real_T c21_body_Jacobian_d4_[36]);
static real_T c21_power(SFc21_DynJointVerifyInstanceStruct *chartInstance,
  real_T c21_a, real_T c21_b);
static void c21_eml_error(SFc21_DynJointVerifyInstanceStruct *chartInstance);
static void c21_body_Jacobian_d5(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T c21_in3[18],
  real_T c21_body_Jacobian_d5_[36]);
static void c21_body_Jacobian_d6(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T c21_in3[18],
  real_T c21_body_Jacobian_d6_[36]);
static const mxArray *c21_sf_marshall(void *chartInstanceVoid, void *c21_u);
static const mxArray *c21_b_sf_marshall(void *chartInstanceVoid, void *c21_u);
static const mxArray *c21_c_sf_marshall(void *chartInstanceVoid, void *c21_u);
static const mxArray *c21_d_sf_marshall(void *chartInstanceVoid, void *c21_u);
static const mxArray *c21_e_sf_marshall(void *chartInstanceVoid, void *c21_u);
static const mxArray *c21_f_sf_marshall(void *chartInstanceVoid, void *c21_u);
static const mxArray *c21_g_sf_marshall(void *chartInstanceVoid, void *c21_u);
static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[67]);
static const mxArray *c21_h_sf_marshall(void *chartInstanceVoid, void *c21_u);
static void c21_emlrt_marshallIn(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c21_Vel, const char_T *c21_name, real_T c21_y
  [36]);
static uint8_T c21_b_emlrt_marshallIn(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_DynJointVerify, const
  char_T *c21_name);
static void init_dsm_address_info(SFc21_DynJointVerifyInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c21_is_active_c21_DynJointVerify = 0U;
}

static void initialize_params_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance)
{
  real_T c21_dv0[9];
  int32_T c21_i0;
  real_T c21_dv1[18];
  int32_T c21_i1;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L' in the parent workspace.\n");
  sf_mex_import("L", sf_mex_get_sfun_param(chartInstance->S, 1, 0), c21_dv0, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c21_i0 = 0; c21_i0 < 9; c21_i0 = c21_i0 + 1) {
    chartInstance->c21_L[c21_i0] = c21_dv0[c21_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Cen' in the parent workspace.\n");
  sf_mex_import("Cen", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c21_dv1, 0,
                0, 0U, 1, 0U, 2, 1, 18);
  for (c21_i1 = 0; c21_i1 < 18; c21_i1 = c21_i1 + 1) {
    chartInstance->c21_Cen[c21_i1] = c21_dv1[c21_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c21_update_debugger_state_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance)
{
  const mxArray *c21_st = NULL;
  const mxArray *c21_y = NULL;
  int32_T c21_i2;
  real_T c21_hoistedGlobal[36];
  int32_T c21_i3;
  real_T c21_u[36];
  const mxArray *c21_b_y = NULL;
  uint8_T c21_b_hoistedGlobal;
  uint8_T c21_b_u;
  const mxArray *c21_c_y = NULL;
  real_T (*c21_Vel)[36];
  c21_Vel = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellarray(2));
  for (c21_i2 = 0; c21_i2 < 36; c21_i2 = c21_i2 + 1) {
    c21_hoistedGlobal[c21_i2] = (*c21_Vel)[c21_i2];
  }

  for (c21_i3 = 0; c21_i3 < 36; c21_i3 = c21_i3 + 1) {
    c21_u[c21_i3] = c21_hoistedGlobal[c21_i3];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 36));
  sf_mex_setcell(c21_y, 0, c21_b_y);
  c21_b_hoistedGlobal = chartInstance->c21_is_active_c21_DynJointVerify;
  c21_b_u = c21_b_hoistedGlobal;
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", &c21_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c21_y, 1, c21_c_y);
  sf_mex_assign(&c21_st, c21_y);
  return c21_st;
}

static void set_sim_state_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct *
  chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T c21_dv2[36];
  int32_T c21_i4;
  real_T (*c21_Vel)[36];
  c21_Vel = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c21_doneDoubleBufferReInit = TRUE;
  c21_u = sf_mex_dup(c21_st);
  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 0)),
                       "Vel", c21_dv2);
  for (c21_i4 = 0; c21_i4 < 36; c21_i4 = c21_i4 + 1) {
    (*c21_Vel)[c21_i4] = c21_dv2[c21_i4];
  }

  chartInstance->c21_is_active_c21_DynJointVerify = c21_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 1)),
     "is_active_c21_DynJointVerify");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_DynJointVerify(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

static void sf_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
  int32_T c21_i5;
  int32_T c21_i6;
  int32_T c21_i7;
  int32_T c21_i8;
  int32_T c21_i9;
  int32_T c21_previousEvent;
  real_T (*c21_Vel)[36];
  real_T (*c21_EnOmega)[6];
  real_T (*c21_EnTheta)[6];
  c21_Vel = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_EnOmega = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c21_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 20);
  for (c21_i5 = 0; c21_i5 < 6; c21_i5 = c21_i5 + 1) {
    _SFD_DATA_RANGE_CHECK((*c21_EnTheta)[c21_i5], 0U);
  }

  for (c21_i6 = 0; c21_i6 < 6; c21_i6 = c21_i6 + 1) {
    _SFD_DATA_RANGE_CHECK((*c21_EnOmega)[c21_i6], 1U);
  }

  for (c21_i7 = 0; c21_i7 < 36; c21_i7 = c21_i7 + 1) {
    _SFD_DATA_RANGE_CHECK((*c21_Vel)[c21_i7], 2U);
  }

  for (c21_i8 = 0; c21_i8 < 9; c21_i8 = c21_i8 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c21_L[c21_i8], 3U);
  }

  for (c21_i9 = 0; c21_i9 < 18; c21_i9 = c21_i9 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c21_Cen[c21_i9], 4U);
  }

  c21_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  c21_c21_DynJointVerify(chartInstance);
  _sfEvent_ = c21_previousEvent;
  sf_debug_check_for_state_inconsistency(_DynJointVerifyMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c21_c21_DynJointVerify(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
  int32_T c21_i10;
  real_T c21_hoistedGlobal[6];
  int32_T c21_i11;
  real_T c21_b_hoistedGlobal[6];
  int32_T c21_i12;
  real_T c21_c_hoistedGlobal[18];
  int32_T c21_i13;
  real_T c21_EnTheta[6];
  int32_T c21_i14;
  real_T c21_EnOmega[6];
  int32_T c21_i15;
  real_T c21_b_Cen[18];
  uint32_T c21_debug_family_var_map[7];
  static const char *c21_sv0[7] = { "L", "nargin", "nargout", "EnTheta",
    "EnOmega", "Cen", "Vel" };

  real_T c21_b_L[9] = { 566.0, 150.0, 870.0, 170.0, 1016.0, 154.0, 20.0, 0.0,
    0.0 };

  real_T c21_nargin = 4.0;
  real_T c21_nargout = 1.0;
  real_T c21_Vel[36];
  int32_T c21_i16;
  int32_T c21_i17;
  static real_T c21_dv3[9] = { 0.566, 0.15, 0.87, 0.17, 1.016, 0.154, 0.02, 0.0,
    0.0 };

  int32_T c21_i18;
  real_T c21_c_Cen[18];
  real_T c21_a[36];
  int32_T c21_i19;
  real_T c21_b[6];
  int32_T c21_i20;
  real_T c21_A[36];
  int32_T c21_i21;
  real_T c21_B[6];
  int32_T c21_i22;
  real_T c21_b_A[36];
  int32_T c21_i23;
  real_T c21_b_B[6];
  int32_T c21_i24;
  real_T c21_c_A[36];
  int32_T c21_i25;
  real_T c21_c_B[6];
  int32_T c21_i26;
  real_T c21_y[6];
  int32_T c21_i27;
  int32_T c21_i28;
  int32_T c21_i29;
  int32_T c21_i30;
  real_T c21_dv4[9];
  int32_T c21_i31;
  real_T c21_b_EnTheta[6];
  int32_T c21_i32;
  real_T c21_d_Cen[18];
  real_T c21_b_a[36];
  int32_T c21_i33;
  real_T c21_b_b[6];
  int32_T c21_i34;
  real_T c21_d_A[36];
  int32_T c21_i35;
  real_T c21_d_B[6];
  int32_T c21_i36;
  real_T c21_e_A[36];
  int32_T c21_i37;
  real_T c21_e_B[6];
  int32_T c21_i38;
  real_T c21_f_A[36];
  int32_T c21_i39;
  real_T c21_f_B[6];
  int32_T c21_i40;
  real_T c21_b_y[6];
  int32_T c21_i41;
  int32_T c21_i42;
  int32_T c21_i43;
  int32_T c21_i44;
  real_T c21_dv5[9];
  int32_T c21_i45;
  real_T c21_c_EnTheta[6];
  int32_T c21_i46;
  real_T c21_e_Cen[18];
  real_T c21_c_a[36];
  int32_T c21_i47;
  real_T c21_c_b[6];
  int32_T c21_i48;
  real_T c21_g_A[36];
  int32_T c21_i49;
  real_T c21_g_B[6];
  int32_T c21_i50;
  real_T c21_h_A[36];
  int32_T c21_i51;
  real_T c21_h_B[6];
  int32_T c21_i52;
  real_T c21_i_A[36];
  int32_T c21_i53;
  real_T c21_i_B[6];
  int32_T c21_i54;
  real_T c21_c_y[6];
  int32_T c21_i55;
  int32_T c21_i56;
  int32_T c21_i57;
  int32_T c21_i58;
  real_T c21_dv6[9];
  int32_T c21_i59;
  real_T c21_d_EnTheta[6];
  int32_T c21_i60;
  real_T c21_f_Cen[18];
  real_T c21_d_a[36];
  int32_T c21_i61;
  real_T c21_d_b[6];
  int32_T c21_i62;
  real_T c21_j_A[36];
  int32_T c21_i63;
  real_T c21_j_B[6];
  int32_T c21_i64;
  real_T c21_k_A[36];
  int32_T c21_i65;
  real_T c21_k_B[6];
  int32_T c21_i66;
  real_T c21_l_A[36];
  int32_T c21_i67;
  real_T c21_l_B[6];
  int32_T c21_i68;
  real_T c21_d_y[6];
  int32_T c21_i69;
  int32_T c21_i70;
  int32_T c21_i71;
  int32_T c21_i72;
  real_T c21_dv7[9];
  int32_T c21_i73;
  real_T c21_e_EnTheta[6];
  int32_T c21_i74;
  real_T c21_g_Cen[18];
  real_T c21_e_a[36];
  int32_T c21_i75;
  real_T c21_e_b[6];
  int32_T c21_i76;
  real_T c21_m_A[36];
  int32_T c21_i77;
  real_T c21_m_B[6];
  int32_T c21_i78;
  real_T c21_n_A[36];
  int32_T c21_i79;
  real_T c21_n_B[6];
  int32_T c21_i80;
  real_T c21_o_A[36];
  int32_T c21_i81;
  real_T c21_o_B[6];
  int32_T c21_i82;
  real_T c21_e_y[6];
  int32_T c21_i83;
  int32_T c21_i84;
  int32_T c21_i85;
  int32_T c21_i86;
  real_T c21_dv8[9];
  int32_T c21_i87;
  real_T c21_f_EnTheta[6];
  int32_T c21_i88;
  real_T c21_h_Cen[18];
  real_T c21_f_a[36];
  int32_T c21_i89;
  real_T c21_f_b[6];
  int32_T c21_i90;
  real_T c21_p_A[36];
  int32_T c21_i91;
  real_T c21_p_B[6];
  int32_T c21_i92;
  real_T c21_q_A[36];
  int32_T c21_i93;
  real_T c21_q_B[6];
  int32_T c21_i94;
  real_T c21_r_A[36];
  int32_T c21_i95;
  real_T c21_r_B[6];
  int32_T c21_i96;
  real_T c21_f_y[6];
  int32_T c21_i97;
  int32_T c21_i98;
  int32_T c21_i99;
  int32_T c21_i100;
  real_T (*c21_b_Vel)[36];
  real_T (*c21_b_EnOmega)[6];
  real_T (*c21_g_EnTheta)[6];
  c21_b_Vel = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
  c21_b_EnOmega = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c21_g_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 20);
  for (c21_i10 = 0; c21_i10 < 6; c21_i10 = c21_i10 + 1) {
    c21_hoistedGlobal[c21_i10] = (*c21_g_EnTheta)[c21_i10];
  }

  for (c21_i11 = 0; c21_i11 < 6; c21_i11 = c21_i11 + 1) {
    c21_b_hoistedGlobal[c21_i11] = (*c21_b_EnOmega)[c21_i11];
  }

  for (c21_i12 = 0; c21_i12 < 18; c21_i12 = c21_i12 + 1) {
    c21_c_hoistedGlobal[c21_i12] = chartInstance->c21_Cen[c21_i12];
  }

  for (c21_i13 = 0; c21_i13 < 6; c21_i13 = c21_i13 + 1) {
    c21_EnTheta[c21_i13] = c21_hoistedGlobal[c21_i13];
  }

  for (c21_i14 = 0; c21_i14 < 6; c21_i14 = c21_i14 + 1) {
    c21_EnOmega[c21_i14] = c21_b_hoistedGlobal[c21_i14];
  }

  for (c21_i15 = 0; c21_i15 < 18; c21_i15 = c21_i15 + 1) {
    c21_b_Cen[c21_i15] = c21_c_hoistedGlobal[c21_i15];
  }

  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c21_sv0, c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c21_b_L, c21_e_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c21_nargin, c21_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c21_nargout, c21_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(c21_EnTheta, c21_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c21_EnOmega, c21_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c21_b_Cen, c21_b_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c21_Vel, c21_sf_marshall, 6U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 3);
  for (c21_i16 = 0; c21_i16 < 36; c21_i16 = c21_i16 + 1) {
    c21_Vel[c21_i16] = 0.0;
  }

  _SFD_EML_CALL(0, 4);
  for (c21_i17 = 0; c21_i17 < 9; c21_i17 = c21_i17 + 1) {
    c21_b_L[c21_i17] = c21_dv3[c21_i17];
  }

  _SFD_EML_CALL(0, 6);
  for (c21_i18 = 0; c21_i18 < 18; c21_i18 = c21_i18 + 1) {
    c21_c_Cen[c21_i18] = c21_b_Cen[c21_i18];
  }

  c21_body_Jacobian_d1(chartInstance, c21_c_Cen, c21_a);
  for (c21_i19 = 0; c21_i19 < 6; c21_i19 = c21_i19 + 1) {
    c21_b[c21_i19] = c21_EnOmega[c21_i19];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i20 = 0; c21_i20 < 36; c21_i20 = c21_i20 + 1) {
    c21_A[c21_i20] = c21_a[c21_i20];
  }

  for (c21_i21 = 0; c21_i21 < 6; c21_i21 = c21_i21 + 1) {
    c21_B[c21_i21] = c21_b[c21_i21];
  }

  for (c21_i22 = 0; c21_i22 < 36; c21_i22 = c21_i22 + 1) {
    c21_b_A[c21_i22] = c21_A[c21_i22];
  }

  for (c21_i23 = 0; c21_i23 < 6; c21_i23 = c21_i23 + 1) {
    c21_b_B[c21_i23] = c21_B[c21_i23];
  }

  for (c21_i24 = 0; c21_i24 < 36; c21_i24 = c21_i24 + 1) {
    c21_c_A[c21_i24] = c21_b_A[c21_i24];
  }

  for (c21_i25 = 0; c21_i25 < 6; c21_i25 = c21_i25 + 1) {
    c21_c_B[c21_i25] = c21_b_B[c21_i25];
  }

  for (c21_i26 = 0; c21_i26 < 6; c21_i26 = c21_i26 + 1) {
    c21_y[c21_i26] = 0.0;
    c21_i27 = 0;
    for (c21_i28 = 0; c21_i28 < 6; c21_i28 = c21_i28 + 1) {
      c21_y[c21_i26] = c21_y[c21_i26] + c21_c_A[c21_i27 + c21_i26] *
        c21_c_B[c21_i28];
      c21_i27 = c21_i27 + 6;
    }
  }

  for (c21_i29 = 0; c21_i29 < 6; c21_i29 = c21_i29 + 1) {
    c21_Vel[c21_i29] = c21_y[c21_i29];
  }

  _SFD_EML_CALL(0, 7);
  for (c21_i30 = 0; c21_i30 < 9; c21_i30 = c21_i30 + 1) {
    c21_dv4[c21_i30] = c21_dv3[c21_i30];
  }

  for (c21_i31 = 0; c21_i31 < 6; c21_i31 = c21_i31 + 1) {
    c21_b_EnTheta[c21_i31] = c21_EnTheta[c21_i31];
  }

  for (c21_i32 = 0; c21_i32 < 18; c21_i32 = c21_i32 + 1) {
    c21_d_Cen[c21_i32] = c21_b_Cen[c21_i32];
  }

  c21_body_Jacobian_d2(chartInstance, c21_dv4, c21_b_EnTheta, c21_d_Cen, c21_b_a);
  for (c21_i33 = 0; c21_i33 < 6; c21_i33 = c21_i33 + 1) {
    c21_b_b[c21_i33] = c21_EnOmega[c21_i33];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i34 = 0; c21_i34 < 36; c21_i34 = c21_i34 + 1) {
    c21_d_A[c21_i34] = c21_b_a[c21_i34];
  }

  for (c21_i35 = 0; c21_i35 < 6; c21_i35 = c21_i35 + 1) {
    c21_d_B[c21_i35] = c21_b_b[c21_i35];
  }

  for (c21_i36 = 0; c21_i36 < 36; c21_i36 = c21_i36 + 1) {
    c21_e_A[c21_i36] = c21_d_A[c21_i36];
  }

  for (c21_i37 = 0; c21_i37 < 6; c21_i37 = c21_i37 + 1) {
    c21_e_B[c21_i37] = c21_d_B[c21_i37];
  }

  for (c21_i38 = 0; c21_i38 < 36; c21_i38 = c21_i38 + 1) {
    c21_f_A[c21_i38] = c21_e_A[c21_i38];
  }

  for (c21_i39 = 0; c21_i39 < 6; c21_i39 = c21_i39 + 1) {
    c21_f_B[c21_i39] = c21_e_B[c21_i39];
  }

  for (c21_i40 = 0; c21_i40 < 6; c21_i40 = c21_i40 + 1) {
    c21_b_y[c21_i40] = 0.0;
    c21_i41 = 0;
    for (c21_i42 = 0; c21_i42 < 6; c21_i42 = c21_i42 + 1) {
      c21_b_y[c21_i40] = c21_b_y[c21_i40] + c21_f_A[c21_i41 + c21_i40] *
        c21_f_B[c21_i42];
      c21_i41 = c21_i41 + 6;
    }
  }

  for (c21_i43 = 0; c21_i43 < 6; c21_i43 = c21_i43 + 1) {
    c21_Vel[c21_i43 + 6] = c21_b_y[c21_i43];
  }

  _SFD_EML_CALL(0, 8);
  for (c21_i44 = 0; c21_i44 < 9; c21_i44 = c21_i44 + 1) {
    c21_dv5[c21_i44] = c21_dv3[c21_i44];
  }

  for (c21_i45 = 0; c21_i45 < 6; c21_i45 = c21_i45 + 1) {
    c21_c_EnTheta[c21_i45] = c21_EnTheta[c21_i45];
  }

  for (c21_i46 = 0; c21_i46 < 18; c21_i46 = c21_i46 + 1) {
    c21_e_Cen[c21_i46] = c21_b_Cen[c21_i46];
  }

  c21_body_Jacobian_d3(chartInstance, c21_dv5, c21_c_EnTheta, c21_e_Cen, c21_c_a);
  for (c21_i47 = 0; c21_i47 < 6; c21_i47 = c21_i47 + 1) {
    c21_c_b[c21_i47] = c21_EnOmega[c21_i47];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i48 = 0; c21_i48 < 36; c21_i48 = c21_i48 + 1) {
    c21_g_A[c21_i48] = c21_c_a[c21_i48];
  }

  for (c21_i49 = 0; c21_i49 < 6; c21_i49 = c21_i49 + 1) {
    c21_g_B[c21_i49] = c21_c_b[c21_i49];
  }

  for (c21_i50 = 0; c21_i50 < 36; c21_i50 = c21_i50 + 1) {
    c21_h_A[c21_i50] = c21_g_A[c21_i50];
  }

  for (c21_i51 = 0; c21_i51 < 6; c21_i51 = c21_i51 + 1) {
    c21_h_B[c21_i51] = c21_g_B[c21_i51];
  }

  for (c21_i52 = 0; c21_i52 < 36; c21_i52 = c21_i52 + 1) {
    c21_i_A[c21_i52] = c21_h_A[c21_i52];
  }

  for (c21_i53 = 0; c21_i53 < 6; c21_i53 = c21_i53 + 1) {
    c21_i_B[c21_i53] = c21_h_B[c21_i53];
  }

  for (c21_i54 = 0; c21_i54 < 6; c21_i54 = c21_i54 + 1) {
    c21_c_y[c21_i54] = 0.0;
    c21_i55 = 0;
    for (c21_i56 = 0; c21_i56 < 6; c21_i56 = c21_i56 + 1) {
      c21_c_y[c21_i54] = c21_c_y[c21_i54] + c21_i_A[c21_i55 + c21_i54] *
        c21_i_B[c21_i56];
      c21_i55 = c21_i55 + 6;
    }
  }

  for (c21_i57 = 0; c21_i57 < 6; c21_i57 = c21_i57 + 1) {
    c21_Vel[c21_i57 + 12] = c21_c_y[c21_i57];
  }

  _SFD_EML_CALL(0, 9);
  for (c21_i58 = 0; c21_i58 < 9; c21_i58 = c21_i58 + 1) {
    c21_dv6[c21_i58] = c21_dv3[c21_i58];
  }

  for (c21_i59 = 0; c21_i59 < 6; c21_i59 = c21_i59 + 1) {
    c21_d_EnTheta[c21_i59] = c21_EnTheta[c21_i59];
  }

  for (c21_i60 = 0; c21_i60 < 18; c21_i60 = c21_i60 + 1) {
    c21_f_Cen[c21_i60] = c21_b_Cen[c21_i60];
  }

  c21_body_Jacobian_d4(chartInstance, c21_dv6, c21_d_EnTheta, c21_f_Cen, c21_d_a);
  for (c21_i61 = 0; c21_i61 < 6; c21_i61 = c21_i61 + 1) {
    c21_d_b[c21_i61] = c21_EnOmega[c21_i61];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i62 = 0; c21_i62 < 36; c21_i62 = c21_i62 + 1) {
    c21_j_A[c21_i62] = c21_d_a[c21_i62];
  }

  for (c21_i63 = 0; c21_i63 < 6; c21_i63 = c21_i63 + 1) {
    c21_j_B[c21_i63] = c21_d_b[c21_i63];
  }

  for (c21_i64 = 0; c21_i64 < 36; c21_i64 = c21_i64 + 1) {
    c21_k_A[c21_i64] = c21_j_A[c21_i64];
  }

  for (c21_i65 = 0; c21_i65 < 6; c21_i65 = c21_i65 + 1) {
    c21_k_B[c21_i65] = c21_j_B[c21_i65];
  }

  for (c21_i66 = 0; c21_i66 < 36; c21_i66 = c21_i66 + 1) {
    c21_l_A[c21_i66] = c21_k_A[c21_i66];
  }

  for (c21_i67 = 0; c21_i67 < 6; c21_i67 = c21_i67 + 1) {
    c21_l_B[c21_i67] = c21_k_B[c21_i67];
  }

  for (c21_i68 = 0; c21_i68 < 6; c21_i68 = c21_i68 + 1) {
    c21_d_y[c21_i68] = 0.0;
    c21_i69 = 0;
    for (c21_i70 = 0; c21_i70 < 6; c21_i70 = c21_i70 + 1) {
      c21_d_y[c21_i68] = c21_d_y[c21_i68] + c21_l_A[c21_i69 + c21_i68] *
        c21_l_B[c21_i70];
      c21_i69 = c21_i69 + 6;
    }
  }

  for (c21_i71 = 0; c21_i71 < 6; c21_i71 = c21_i71 + 1) {
    c21_Vel[c21_i71 + 18] = c21_d_y[c21_i71];
  }

  _SFD_EML_CALL(0, 10);
  for (c21_i72 = 0; c21_i72 < 9; c21_i72 = c21_i72 + 1) {
    c21_dv7[c21_i72] = c21_dv3[c21_i72];
  }

  for (c21_i73 = 0; c21_i73 < 6; c21_i73 = c21_i73 + 1) {
    c21_e_EnTheta[c21_i73] = c21_EnTheta[c21_i73];
  }

  for (c21_i74 = 0; c21_i74 < 18; c21_i74 = c21_i74 + 1) {
    c21_g_Cen[c21_i74] = c21_b_Cen[c21_i74];
  }

  c21_body_Jacobian_d5(chartInstance, c21_dv7, c21_e_EnTheta, c21_g_Cen, c21_e_a);
  for (c21_i75 = 0; c21_i75 < 6; c21_i75 = c21_i75 + 1) {
    c21_e_b[c21_i75] = c21_EnOmega[c21_i75];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i76 = 0; c21_i76 < 36; c21_i76 = c21_i76 + 1) {
    c21_m_A[c21_i76] = c21_e_a[c21_i76];
  }

  for (c21_i77 = 0; c21_i77 < 6; c21_i77 = c21_i77 + 1) {
    c21_m_B[c21_i77] = c21_e_b[c21_i77];
  }

  for (c21_i78 = 0; c21_i78 < 36; c21_i78 = c21_i78 + 1) {
    c21_n_A[c21_i78] = c21_m_A[c21_i78];
  }

  for (c21_i79 = 0; c21_i79 < 6; c21_i79 = c21_i79 + 1) {
    c21_n_B[c21_i79] = c21_m_B[c21_i79];
  }

  for (c21_i80 = 0; c21_i80 < 36; c21_i80 = c21_i80 + 1) {
    c21_o_A[c21_i80] = c21_n_A[c21_i80];
  }

  for (c21_i81 = 0; c21_i81 < 6; c21_i81 = c21_i81 + 1) {
    c21_o_B[c21_i81] = c21_n_B[c21_i81];
  }

  for (c21_i82 = 0; c21_i82 < 6; c21_i82 = c21_i82 + 1) {
    c21_e_y[c21_i82] = 0.0;
    c21_i83 = 0;
    for (c21_i84 = 0; c21_i84 < 6; c21_i84 = c21_i84 + 1) {
      c21_e_y[c21_i82] = c21_e_y[c21_i82] + c21_o_A[c21_i83 + c21_i82] *
        c21_o_B[c21_i84];
      c21_i83 = c21_i83 + 6;
    }
  }

  for (c21_i85 = 0; c21_i85 < 6; c21_i85 = c21_i85 + 1) {
    c21_Vel[c21_i85 + 24] = c21_e_y[c21_i85];
  }

  _SFD_EML_CALL(0, 11);
  for (c21_i86 = 0; c21_i86 < 9; c21_i86 = c21_i86 + 1) {
    c21_dv8[c21_i86] = c21_dv3[c21_i86];
  }

  for (c21_i87 = 0; c21_i87 < 6; c21_i87 = c21_i87 + 1) {
    c21_f_EnTheta[c21_i87] = c21_EnTheta[c21_i87];
  }

  for (c21_i88 = 0; c21_i88 < 18; c21_i88 = c21_i88 + 1) {
    c21_h_Cen[c21_i88] = c21_b_Cen[c21_i88];
  }

  c21_body_Jacobian_d6(chartInstance, c21_dv8, c21_f_EnTheta, c21_h_Cen, c21_f_a);
  for (c21_i89 = 0; c21_i89 < 6; c21_i89 = c21_i89 + 1) {
    c21_f_b[c21_i89] = c21_EnOmega[c21_i89];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i90 = 0; c21_i90 < 36; c21_i90 = c21_i90 + 1) {
    c21_p_A[c21_i90] = c21_f_a[c21_i90];
  }

  for (c21_i91 = 0; c21_i91 < 6; c21_i91 = c21_i91 + 1) {
    c21_p_B[c21_i91] = c21_f_b[c21_i91];
  }

  for (c21_i92 = 0; c21_i92 < 36; c21_i92 = c21_i92 + 1) {
    c21_q_A[c21_i92] = c21_p_A[c21_i92];
  }

  for (c21_i93 = 0; c21_i93 < 6; c21_i93 = c21_i93 + 1) {
    c21_q_B[c21_i93] = c21_p_B[c21_i93];
  }

  for (c21_i94 = 0; c21_i94 < 36; c21_i94 = c21_i94 + 1) {
    c21_r_A[c21_i94] = c21_q_A[c21_i94];
  }

  for (c21_i95 = 0; c21_i95 < 6; c21_i95 = c21_i95 + 1) {
    c21_r_B[c21_i95] = c21_q_B[c21_i95];
  }

  for (c21_i96 = 0; c21_i96 < 6; c21_i96 = c21_i96 + 1) {
    c21_f_y[c21_i96] = 0.0;
    c21_i97 = 0;
    for (c21_i98 = 0; c21_i98 < 6; c21_i98 = c21_i98 + 1) {
      c21_f_y[c21_i96] = c21_f_y[c21_i96] + c21_r_A[c21_i97 + c21_i96] *
        c21_r_B[c21_i98];
      c21_i97 = c21_i97 + 6;
    }
  }

  for (c21_i99 = 0; c21_i99 < 6; c21_i99 = c21_i99 + 1) {
    c21_Vel[c21_i99 + 30] = c21_f_y[c21_i99];
  }

  _SFD_EML_CALL(0, -11);
  sf_debug_symbol_scope_pop();
  for (c21_i100 = 0; c21_i100 < 36; c21_i100 = c21_i100 + 1) {
    (*c21_b_Vel)[c21_i100] = c21_Vel[c21_i100];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20);
}

static void compInitSubchartSimstructsFcn_c21_DynJointVerify
  (SFc21_DynJointVerifyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c21_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d1.m"));
  _SFD_SCRIPT_TRANSLATION(c21_chartNumber, 1U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d2.m"));
  _SFD_SCRIPT_TRANSLATION(c21_chartNumber, 2U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d3.m"));
  _SFD_SCRIPT_TRANSLATION(c21_chartNumber, 3U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d4.m"));
  _SFD_SCRIPT_TRANSLATION(c21_chartNumber, 4U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d5.m"));
  _SFD_SCRIPT_TRANSLATION(c21_chartNumber, 5U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d6.m"));
}

static void c21_body_Jacobian_d1(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in3[18], real_T c21_body_Jacobian_d1_
  [36])
{
  uint32_T c21_debug_family_var_map[6];
  real_T c21_Cx1;
  real_T c21_Cy1;
  real_T c21_nargin = 3.0;
  real_T c21_nargout = 1.0;
  real_T c21_x[36];
  int32_T c21_k;
  int32_T c21_b_k;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c21_b_debug_family_names,
    c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c21_Cx1, c21_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c21_Cy1, c21_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c21_nargin, c21_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c21_nargout, c21_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(c21_in3, c21_b_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c21_body_Jacobian_d1_, c21_f_sf_marshall, 5U);
  CV_SCRIPT_FCN(0, 0);

  /* BODY_JACOBIAN_D1 */
  /*     BODY_JACOBIAN_D1_ = BODY_JACOBIAN_D1(IN1,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 15:39:36 */
  _SFD_SCRIPT_CALL(0, 8);
  c21_Cx1 = c21_in3[0];
  _SFD_SCRIPT_CALL(0, 9);
  c21_Cy1 = c21_in3[6];
  _SFD_SCRIPT_CALL(0, 10);
  c21_x[0] = -c21_Cy1;
  c21_x[1] = c21_Cx1;
  c21_x[2] = 0.0;
  c21_x[3] = 0.0;
  c21_x[4] = 0.0;
  c21_x[5] = 1.0;
  c21_x[6] = 0.0;
  c21_x[7] = 0.0;
  c21_x[8] = 0.0;
  c21_x[9] = 0.0;
  c21_x[10] = 0.0;
  c21_x[11] = 0.0;
  c21_x[12] = 0.0;
  c21_x[13] = 0.0;
  c21_x[14] = 0.0;
  c21_x[15] = 0.0;
  c21_x[16] = 0.0;
  c21_x[17] = 0.0;
  c21_x[18] = 0.0;
  c21_x[19] = 0.0;
  c21_x[20] = 0.0;
  c21_x[21] = 0.0;
  c21_x[22] = 0.0;
  c21_x[23] = 0.0;
  c21_x[24] = 0.0;
  c21_x[25] = 0.0;
  c21_x[26] = 0.0;
  c21_x[27] = 0.0;
  c21_x[28] = 0.0;
  c21_x[29] = 0.0;
  c21_x[30] = 0.0;
  c21_x[31] = 0.0;
  c21_x[32] = 0.0;
  c21_x[33] = 0.0;
  c21_x[34] = 0.0;
  c21_x[35] = 0.0;
  for (c21_k = 1; c21_k < 37; c21_k = c21_k + 1) {
    c21_b_k = c21_k;
    c21_body_Jacobian_d1_[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c21_b_k), 1, 36, 1, 0) - 1] = c21_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c21_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0, -10);
  sf_debug_symbol_scope_pop();
}

static void c21_eml_scalar_eg(SFc21_DynJointVerifyInstanceStruct *chartInstance)
{
}

static void c21_b_eml_scalar_eg(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

static void c21_body_Jacobian_d2(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T
  c21_in3[18], real_T c21_body_Jacobian_d2_[36])
{
  uint32_T c21_debug_family_var_map[20];
  real_T c21_A2;
  real_T c21_Cx2;
  real_T c21_Cy2;
  real_T c21_Cz2;
  real_T c21_L1;
  real_T c21_L2;
  real_T c21_t352;
  real_T c21_t353;
  real_T c21_t354;
  real_T c21_t355;
  real_T c21_t356;
  real_T c21_t357;
  real_T c21_t358;
  real_T c21_t359;
  real_T c21_nargin = 3.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x[36];
  int32_T c21_k;
  int32_T c21_b_k;
  sf_debug_symbol_scope_push_eml(0U, 20U, 20U, c21_c_debug_family_names,
    c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c21_A2, c21_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c21_Cx2, c21_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c21_Cy2, c21_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c21_Cz2, c21_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c21_L1, c21_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c21_L2, c21_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c21_t352, c21_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c21_t353, c21_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c21_t354, c21_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c21_t355, c21_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c21_t356, c21_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c21_t357, c21_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c21_t358, c21_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c21_t359, c21_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c21_nargin, c21_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c21_nargout, c21_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(c21_in1, c21_e_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(c21_in2, c21_g_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(c21_in3, c21_b_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(c21_body_Jacobian_d2_, c21_f_sf_marshall, 19U);
  CV_SCRIPT_FCN(1, 0);

  /* BODY_JACOBIAN_D2 */
  /*     BODY_JACOBIAN_D2_ = BODY_JACOBIAN_D2(IN1,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 15:39:36 */
  _SFD_SCRIPT_CALL(1, 8);
  c21_A2 = c21_in2[1];
  _SFD_SCRIPT_CALL(1, 9);
  c21_Cx2 = c21_in3[1];
  _SFD_SCRIPT_CALL(1, 10);
  c21_Cy2 = c21_in3[7];
  _SFD_SCRIPT_CALL(1, 11);
  c21_Cz2 = c21_in3[13];
  _SFD_SCRIPT_CALL(1, 12);
  c21_L1 = c21_in1[0];
  _SFD_SCRIPT_CALL(1, 13);
  c21_L2 = c21_in1[1];
  _SFD_SCRIPT_CALL(1, 14);
  c21_x = c21_A2;
  c21_t352 = c21_x;
  c21_b_x = c21_t352;
  c21_t352 = c21_b_x;
  c21_t352 = muDoubleScalarCos(c21_t352);
  _SFD_SCRIPT_CALL(1, 15);
  c21_c_x = c21_A2;
  c21_t353 = c21_c_x;
  c21_d_x = c21_t353;
  c21_t353 = c21_d_x;
  c21_t353 = muDoubleScalarSin(c21_t353);
  _SFD_SCRIPT_CALL(1, 16);
  c21_t354 = c21_t352 - 1.0;
  _SFD_SCRIPT_CALL(1, 17);
  c21_t355 = c21_L1 * c21_t353;
  _SFD_SCRIPT_CALL(1, 18);
  c21_t356 = c21_L2 * c21_t354;
  _SFD_SCRIPT_CALL(1, 19);
  c21_t357 = c21_t355 + c21_t356;
  _SFD_SCRIPT_CALL(1, 20);
  c21_t358 = c21_L1 * c21_t354;
  _SFD_SCRIPT_CALL(1, 21);
  c21_t359 = c21_t358 - c21_L2 * c21_t353;
  _SFD_SCRIPT_CALL(1, 22);
  c21_e_x[0] = (-c21_Cy2) * c21_t352;
  c21_e_x[1] = (((-c21_t355) - c21_t356) + c21_Cx2 * c21_t352) + c21_Cz2 *
    c21_t353;
  c21_e_x[2] = (-c21_Cy2) * c21_t353;
  c21_e_x[3] = -c21_t353;
  c21_e_x[4] = 0.0;
  c21_e_x[5] = c21_t352;
  c21_e_x[6] = (((c21_Cz2 - c21_L1 * c21_t352) - c21_L2 * c21_t353) - c21_t353 *
                c21_t357) - c21_t352 * c21_t359;
  c21_e_x[7] = 0.0;
  c21_e_x[8] = ((((-c21_Cx2) - c21_t355) + c21_L2 * c21_t352) + c21_t352 *
                c21_t357) - c21_t353 * c21_t359;
  c21_e_x[9] = 0.0;
  c21_e_x[10] = 1.0;
  c21_e_x[11] = 0.0;
  c21_e_x[12] = 0.0;
  c21_e_x[13] = 0.0;
  c21_e_x[14] = 0.0;
  c21_e_x[15] = 0.0;
  c21_e_x[16] = 0.0;
  c21_e_x[17] = 0.0;
  c21_e_x[18] = 0.0;
  c21_e_x[19] = 0.0;
  c21_e_x[20] = 0.0;
  c21_e_x[21] = 0.0;
  c21_e_x[22] = 0.0;
  c21_e_x[23] = 0.0;
  c21_e_x[24] = 0.0;
  c21_e_x[25] = 0.0;
  c21_e_x[26] = 0.0;
  c21_e_x[27] = 0.0;
  c21_e_x[28] = 0.0;
  c21_e_x[29] = 0.0;
  c21_e_x[30] = 0.0;
  c21_e_x[31] = 0.0;
  c21_e_x[32] = 0.0;
  c21_e_x[33] = 0.0;
  c21_e_x[34] = 0.0;
  c21_e_x[35] = 0.0;
  for (c21_k = 1; c21_k < 37; c21_k = c21_k + 1) {
    c21_b_k = c21_k;
    c21_body_Jacobian_d2_[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c21_b_k), 1, 36, 1, 0) - 1] = c21_e_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c21_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(1, -22);
  sf_debug_symbol_scope_pop();
}

static void c21_body_Jacobian_d3(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T
  c21_in3[18], real_T c21_body_Jacobian_d3_[36])
{
  uint32_T c21_debug_family_var_map[46];
  real_T c21_A2;
  real_T c21_A3;
  real_T c21_Cx3;
  real_T c21_Cy3;
  real_T c21_Cz3;
  real_T c21_L1;
  real_T c21_L2;
  real_T c21_L3;
  real_T c21_t319;
  real_T c21_t320;
  real_T c21_t321;
  real_T c21_t322;
  real_T c21_t323;
  real_T c21_t324;
  real_T c21_t325;
  real_T c21_t326;
  real_T c21_t327;
  real_T c21_t328;
  real_T c21_t329;
  real_T c21_t338;
  real_T c21_t330;
  real_T c21_t331;
  real_T c21_t336;
  real_T c21_t332;
  real_T c21_t333;
  real_T c21_t334;
  real_T c21_t335;
  real_T c21_t337;
  real_T c21_t339;
  real_T c21_t340;
  real_T c21_t341;
  real_T c21_t342;
  real_T c21_t343;
  real_T c21_t344;
  real_T c21_t345;
  real_T c21_t346;
  real_T c21_t350;
  real_T c21_t347;
  real_T c21_t348;
  real_T c21_t349;
  real_T c21_nargin = 3.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  real_T c21_i_x[36];
  int32_T c21_k;
  int32_T c21_b_k;
  sf_debug_symbol_scope_push_eml(0U, 46U, 46U, c21_d_debug_family_names,
    c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c21_A2, c21_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c21_A3, c21_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c21_Cx3, c21_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c21_Cy3, c21_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c21_Cz3, c21_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c21_L1, c21_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c21_L2, c21_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c21_L3, c21_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c21_t319, c21_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c21_t320, c21_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c21_t321, c21_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c21_t322, c21_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c21_t323, c21_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c21_t324, c21_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c21_t325, c21_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c21_t326, c21_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c21_t327, c21_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c21_t328, c21_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c21_t329, c21_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c21_t338, c21_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c21_t330, c21_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c21_t331, c21_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c21_t336, c21_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c21_t332, c21_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c21_t333, c21_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c21_t334, c21_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c21_t335, c21_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c21_t337, c21_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c21_t339, c21_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c21_t340, c21_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c21_t341, c21_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c21_t342, c21_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c21_t343, c21_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c21_t344, c21_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c21_t345, c21_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c21_t346, c21_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c21_t350, c21_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c21_t347, c21_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c21_t348, c21_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c21_t349, c21_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c21_nargin, c21_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c21_nargout, c21_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(c21_in1, c21_e_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(c21_in2, c21_g_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(c21_in3, c21_b_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(c21_body_Jacobian_d3_, c21_f_sf_marshall, 45U);
  CV_SCRIPT_FCN(2, 0);

  /* BODY_JACOBIAN_D3 */
  /*     BODY_JACOBIAN_D3_ = BODY_JACOBIAN_D3(IN1,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 15:39:35 */
  _SFD_SCRIPT_CALL(2, 8);
  c21_A2 = c21_in2[1];
  _SFD_SCRIPT_CALL(2, 9);
  c21_A3 = c21_in2[2];
  _SFD_SCRIPT_CALL(2, 10);
  c21_Cx3 = c21_in3[2];
  _SFD_SCRIPT_CALL(2, 11);
  c21_Cy3 = c21_in3[8];
  _SFD_SCRIPT_CALL(2, 12);
  c21_Cz3 = c21_in3[14];
  _SFD_SCRIPT_CALL(2, 13);
  c21_L1 = c21_in1[0];
  _SFD_SCRIPT_CALL(2, 14);
  c21_L2 = c21_in1[1];
  _SFD_SCRIPT_CALL(2, 15);
  c21_L3 = c21_in1[2];
  _SFD_SCRIPT_CALL(2, 16);
  c21_x = c21_A3;
  c21_t319 = c21_x;
  c21_b_x = c21_t319;
  c21_t319 = c21_b_x;
  c21_t319 = muDoubleScalarCos(c21_t319);
  _SFD_SCRIPT_CALL(2, 17);
  c21_c_x = c21_A3;
  c21_t320 = c21_c_x;
  c21_d_x = c21_t320;
  c21_t320 = c21_d_x;
  c21_t320 = muDoubleScalarSin(c21_t320);
  _SFD_SCRIPT_CALL(2, 18);
  c21_t321 = c21_L1 + c21_L3;
  _SFD_SCRIPT_CALL(2, 19);
  c21_t322 = c21_t319 - 1.0;
  _SFD_SCRIPT_CALL(2, 20);
  c21_e_x = c21_A2;
  c21_t323 = c21_e_x;
  c21_f_x = c21_t323;
  c21_t323 = c21_f_x;
  c21_t323 = muDoubleScalarCos(c21_t323);
  _SFD_SCRIPT_CALL(2, 21);
  c21_g_x = c21_A2;
  c21_t324 = c21_g_x;
  c21_h_x = c21_t324;
  c21_t324 = c21_h_x;
  c21_t324 = muDoubleScalarSin(c21_t324);
  _SFD_SCRIPT_CALL(2, 22);
  c21_t325 = c21_t323 - 1.0;
  _SFD_SCRIPT_CALL(2, 23);
  c21_t326 = c21_L1 * c21_t324;
  _SFD_SCRIPT_CALL(2, 24);
  c21_t327 = c21_L2 * c21_t325;
  _SFD_SCRIPT_CALL(2, 25);
  c21_t328 = c21_t326 + c21_t327;
  _SFD_SCRIPT_CALL(2, 26);
  c21_t329 = c21_L1 * c21_t325;
  _SFD_SCRIPT_CALL(2, 27);
  c21_t338 = c21_L2 * c21_t324;
  _SFD_SCRIPT_CALL(2, 28);
  c21_t330 = c21_t329 - c21_t338;
  _SFD_SCRIPT_CALL(2, 29);
  c21_t331 = c21_L2 * c21_t320;
  _SFD_SCRIPT_CALL(2, 30);
  c21_t336 = c21_t321 * c21_t322;
  _SFD_SCRIPT_CALL(2, 31);
  c21_t332 = c21_t319 * (c21_t331 - c21_t336);
  _SFD_SCRIPT_CALL(2, 32);
  c21_t333 = c21_t320 * c21_t321;
  _SFD_SCRIPT_CALL(2, 33);
  c21_t334 = c21_L2 * c21_t322;
  _SFD_SCRIPT_CALL(2, 34);
  c21_t335 = c21_t333 + c21_t334;
  _SFD_SCRIPT_CALL(2, 35);
  c21_t337 = c21_t323 * c21_t328;
  _SFD_SCRIPT_CALL(2, 36);
  c21_t339 = c21_t337 - c21_t324 * c21_t330;
  _SFD_SCRIPT_CALL(2, 37);
  c21_t340 = c21_t323 * c21_t330;
  _SFD_SCRIPT_CALL(2, 38);
  c21_t341 = c21_t324 * c21_t328;
  _SFD_SCRIPT_CALL(2, 39);
  c21_t342 = c21_t340 + c21_t341;
  _SFD_SCRIPT_CALL(2, 40);
  c21_t343 = c21_t320 * c21_t323;
  _SFD_SCRIPT_CALL(2, 41);
  c21_t344 = c21_t319 * c21_t324;
  _SFD_SCRIPT_CALL(2, 42);
  c21_t345 = c21_t343 + c21_t344;
  _SFD_SCRIPT_CALL(2, 43);
  c21_t346 = c21_t319 * c21_t323;
  _SFD_SCRIPT_CALL(2, 44);
  c21_t350 = c21_t320 * c21_t324;
  _SFD_SCRIPT_CALL(2, 45);
  c21_t347 = c21_t346 - c21_t350;
  _SFD_SCRIPT_CALL(2, 46);
  c21_t348 = c21_t319 * c21_t335;
  _SFD_SCRIPT_CALL(2, 47);
  c21_t349 = c21_t320 * (c21_t331 - c21_t336);
  _SFD_SCRIPT_CALL(2, 48);
  c21_i_x[0] = (-c21_Cy3) * c21_t319 * c21_t323 + c21_Cy3 * c21_t320 * c21_t324;
  c21_i_x[1] = (((-c21_t326) - c21_t327) - c21_t323 * (((c21_t333 + c21_t334) -
    c21_Cx3 * c21_t319) - c21_Cz3 * c21_t320)) + c21_t324
    * (((c21_t331 - c21_t336) - c21_Cx3 * c21_t320) + c21_Cz3 * c21_t319);
  c21_i_x[2] = (-c21_Cy3) * c21_t319 * c21_t324 - c21_Cy3 * c21_t320 * c21_t323;
  c21_i_x[3] = (-c21_t343) - c21_t344;
  c21_i_x[4] = 0.0;
  c21_i_x[5] = c21_t347;
  c21_i_x[6] = (((((c21_Cz3 + c21_t332) - c21_L1 * c21_t347) - c21_L2 * c21_t345)
                 - c21_t320 * c21_t335) - c21_t320 * c21_t339) -
    c21_t319 * c21_t342;
  c21_i_x[7] = 0.0;
  c21_i_x[8] = ((((((-c21_Cx3) + c21_t348) + c21_t349) - c21_L1 * c21_t345) +
                 c21_L2 * c21_t347) + c21_t319 * c21_t339) - c21_t320 *
    c21_t342;
  c21_i_x[9] = 0.0;
  c21_i_x[10] = 1.0;
  c21_i_x[11] = 0.0;
  c21_i_x[12] = (((c21_Cz3 - c21_t331) + c21_t332) - c21_t319 * c21_t321) -
    c21_t320 * c21_t335;
  c21_i_x[13] = 0.0;
  c21_i_x[14] = ((((-c21_Cx3) - c21_t333) + c21_t348) + c21_t349) + c21_L2 *
    c21_t319;
  c21_i_x[15] = 0.0;
  c21_i_x[16] = 1.0;
  c21_i_x[17] = 0.0;
  c21_i_x[18] = 0.0;
  c21_i_x[19] = 0.0;
  c21_i_x[20] = 0.0;
  c21_i_x[21] = 0.0;
  c21_i_x[22] = 0.0;
  c21_i_x[23] = 0.0;
  c21_i_x[24] = 0.0;
  c21_i_x[25] = 0.0;
  c21_i_x[26] = 0.0;
  c21_i_x[27] = 0.0;
  c21_i_x[28] = 0.0;
  c21_i_x[29] = 0.0;
  c21_i_x[30] = 0.0;
  c21_i_x[31] = 0.0;
  c21_i_x[32] = 0.0;
  c21_i_x[33] = 0.0;
  c21_i_x[34] = 0.0;
  c21_i_x[35] = 0.0;
  for (c21_k = 1; c21_k < 37; c21_k = c21_k + 1) {
    c21_b_k = c21_k;
    c21_body_Jacobian_d3_[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c21_b_k), 1, 36, 1, 0) - 1] = c21_i_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c21_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(2, -48);
  sf_debug_symbol_scope_pop();
}

static void c21_body_Jacobian_d4(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T
  c21_in3[18], real_T c21_body_Jacobian_d4_[36])
{
  uint32_T c21_debug_family_var_map[69];
  real_T c21_A2;
  real_T c21_A3;
  real_T c21_A4;
  real_T c21_Cx4;
  real_T c21_Cy4;
  real_T c21_Cz4;
  real_T c21_L1;
  real_T c21_L2;
  real_T c21_L3;
  real_T c21_L4;
  real_T c21_t265;
  real_T c21_t266;
  real_T c21_t267;
  real_T c21_t268;
  real_T c21_t269;
  real_T c21_t270;
  real_T c21_t271;
  real_T c21_t272;
  real_T c21_t273;
  real_T c21_t274;
  real_T c21_t275;
  real_T c21_t276;
  real_T c21_t277;
  real_T c21_t278;
  real_T c21_t279;
  real_T c21_t280;
  real_T c21_t281;
  real_T c21_t298;
  real_T c21_t282;
  real_T c21_t283;
  real_T c21_t295;
  real_T c21_t296;
  real_T c21_t284;
  real_T c21_t285;
  real_T c21_t286;
  real_T c21_t287;
  real_T c21_t288;
  real_T c21_t289;
  real_T c21_t290;
  real_T c21_t291;
  real_T c21_t292;
  real_T c21_t293;
  real_T c21_t294;
  real_T c21_t297;
  real_T c21_t309;
  real_T c21_t299;
  real_T c21_t300;
  real_T c21_t301;
  real_T c21_t302;
  real_T c21_t303;
  real_T c21_t304;
  real_T c21_t305;
  real_T c21_t306;
  real_T c21_t307;
  real_T c21_t311;
  real_T c21_t308;
  real_T c21_t310;
  real_T c21_t312;
  real_T c21_t313;
  real_T c21_t314;
  real_T c21_t315;
  real_T c21_t316;
  real_T c21_t317;
  real_T c21_nargin = 3.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  real_T c21_i_x;
  real_T c21_j_x;
  real_T c21_k_x;
  real_T c21_l_x;
  real_T c21_m_x[36];
  int32_T c21_k;
  int32_T c21_b_k;
  sf_debug_symbol_scope_push_eml(0U, 69U, 69U, c21_e_debug_family_names,
    c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c21_A2, c21_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c21_A3, c21_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c21_A4, c21_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c21_Cx4, c21_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c21_Cy4, c21_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c21_Cz4, c21_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c21_L1, c21_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c21_L2, c21_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c21_L3, c21_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c21_L4, c21_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c21_t265, c21_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c21_t266, c21_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c21_t267, c21_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c21_t268, c21_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c21_t269, c21_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c21_t270, c21_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c21_t271, c21_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c21_t272, c21_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c21_t273, c21_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c21_t274, c21_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c21_t275, c21_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c21_t276, c21_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c21_t277, c21_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c21_t278, c21_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c21_t279, c21_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c21_t280, c21_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c21_t281, c21_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c21_t298, c21_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c21_t282, c21_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c21_t283, c21_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c21_t295, c21_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c21_t296, c21_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c21_t284, c21_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c21_t285, c21_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c21_t286, c21_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c21_t287, c21_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c21_t288, c21_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c21_t289, c21_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c21_t290, c21_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c21_t291, c21_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c21_t292, c21_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c21_t293, c21_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c21_t294, c21_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c21_t297, c21_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c21_t309, c21_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c21_t299, c21_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c21_t300, c21_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c21_t301, c21_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c21_t302, c21_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c21_t303, c21_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c21_t304, c21_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c21_t305, c21_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c21_t306, c21_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c21_t307, c21_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c21_t311, c21_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c21_t308, c21_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c21_t310, c21_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c21_t312, c21_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c21_t313, c21_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c21_t314, c21_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c21_t315, c21_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c21_t316, c21_d_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c21_t317, c21_d_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c21_nargin, c21_d_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c21_nargout, c21_d_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(c21_in1, c21_e_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(c21_in2, c21_g_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(c21_in3, c21_b_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(c21_body_Jacobian_d4_, c21_f_sf_marshall, 68U);
  CV_SCRIPT_FCN(3, 0);

  /* BODY_JACOBIAN_D4 */
  /*     BODY_JACOBIAN_D4_ = BODY_JACOBIAN_D4(IN1,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 15:39:35 */
  _SFD_SCRIPT_CALL(3, 8);
  c21_A2 = c21_in2[1];
  _SFD_SCRIPT_CALL(3, 9);
  c21_A3 = c21_in2[2];
  _SFD_SCRIPT_CALL(3, 10);
  c21_A4 = c21_in2[3];
  _SFD_SCRIPT_CALL(3, 11);
  c21_Cx4 = c21_in3[3];
  _SFD_SCRIPT_CALL(3, 12);
  c21_Cy4 = c21_in3[9];
  _SFD_SCRIPT_CALL(3, 13);
  c21_Cz4 = c21_in3[15];
  _SFD_SCRIPT_CALL(3, 14);
  c21_L1 = c21_in1[0];
  _SFD_SCRIPT_CALL(3, 15);
  c21_L2 = c21_in1[1];
  _SFD_SCRIPT_CALL(3, 16);
  c21_L3 = c21_in1[2];
  _SFD_SCRIPT_CALL(3, 17);
  c21_L4 = c21_in1[3];
  _SFD_SCRIPT_CALL(3, 18);
  c21_x = c21_A4;
  c21_t265 = c21_x;
  c21_b_x = c21_t265;
  c21_t265 = c21_b_x;
  c21_t265 = muDoubleScalarSin(c21_t265);
  _SFD_SCRIPT_CALL(3, 19);
  c21_c_x = c21_A4;
  c21_t266 = c21_c_x;
  c21_d_x = c21_t266;
  c21_t266 = c21_d_x;
  c21_t266 = muDoubleScalarCos(c21_t266);
  _SFD_SCRIPT_CALL(3, 20);
  c21_t267 = c21_Cy4 * c21_t266;
  _SFD_SCRIPT_CALL(3, 21);
  c21_t268 = (c21_L1 + c21_L3) + c21_L4;
  _SFD_SCRIPT_CALL(3, 22);
  c21_t269 = c21_t265 * c21_t268;
  _SFD_SCRIPT_CALL(3, 23);
  c21_t270 = (c21_t267 + c21_t269) - c21_Cz4 * c21_t265;
  _SFD_SCRIPT_CALL(3, 24);
  c21_e_x = c21_A3;
  c21_t271 = c21_e_x;
  c21_f_x = c21_t271;
  c21_t271 = c21_f_x;
  c21_t271 = muDoubleScalarCos(c21_t271);
  _SFD_SCRIPT_CALL(3, 25);
  c21_g_x = c21_A3;
  c21_t272 = c21_g_x;
  c21_h_x = c21_t272;
  c21_t272 = c21_h_x;
  c21_t272 = muDoubleScalarSin(c21_t272);
  _SFD_SCRIPT_CALL(3, 26);
  c21_t273 = c21_L1 + c21_L3;
  _SFD_SCRIPT_CALL(3, 27);
  c21_t274 = c21_t271 - 1.0;
  _SFD_SCRIPT_CALL(3, 28);
  c21_i_x = c21_A2;
  c21_t275 = c21_i_x;
  c21_j_x = c21_t275;
  c21_t275 = c21_j_x;
  c21_t275 = muDoubleScalarCos(c21_t275);
  _SFD_SCRIPT_CALL(3, 29);
  c21_k_x = c21_A2;
  c21_t276 = c21_k_x;
  c21_l_x = c21_t276;
  c21_t276 = c21_l_x;
  c21_t276 = muDoubleScalarSin(c21_t276);
  _SFD_SCRIPT_CALL(3, 30);
  c21_t277 = c21_t275 - 1.0;
  _SFD_SCRIPT_CALL(3, 31);
  c21_t278 = c21_L1 * c21_t276;
  _SFD_SCRIPT_CALL(3, 32);
  c21_t279 = c21_L2 * c21_t277;
  _SFD_SCRIPT_CALL(3, 33);
  c21_t280 = c21_t278 + c21_t279;
  _SFD_SCRIPT_CALL(3, 34);
  c21_t281 = c21_L1 * c21_t277;
  _SFD_SCRIPT_CALL(3, 35);
  c21_t298 = c21_L2 * c21_t276;
  _SFD_SCRIPT_CALL(3, 36);
  c21_t282 = c21_t281 - c21_t298;
  _SFD_SCRIPT_CALL(3, 37);
  c21_t283 = c21_L2 * c21_t272;
  _SFD_SCRIPT_CALL(3, 38);
  c21_t295 = c21_t273 * c21_t274;
  _SFD_SCRIPT_CALL(3, 39);
  c21_t296 = c21_t283 - c21_t295;
  _SFD_SCRIPT_CALL(3, 40);
  c21_t284 = c21_t271 * c21_t296;
  _SFD_SCRIPT_CALL(3, 41);
  c21_t285 = c21_t272 * c21_t273;
  _SFD_SCRIPT_CALL(3, 42);
  c21_t286 = c21_L2 * c21_t274;
  _SFD_SCRIPT_CALL(3, 43);
  c21_t287 = c21_t285 + c21_t286;
  _SFD_SCRIPT_CALL(3, 44);
  c21_t288 = c21_Cz4 * c21_t266;
  _SFD_SCRIPT_CALL(3, 45);
  c21_t289 = c21_Cy4 * c21_t265;
  _SFD_SCRIPT_CALL(3, 46);
  c21_t290 = c21_t266 - 1.0;
  _SFD_SCRIPT_CALL(3, 47);
  c21_t291 = c21_power(chartInstance, c21_t265, 2.0);
  _SFD_SCRIPT_CALL(3, 48);
  c21_t292 = c21_t268 * c21_t291;
  _SFD_SCRIPT_CALL(3, 49);
  c21_t293 = c21_t266 * c21_t268 * c21_t290;
  _SFD_SCRIPT_CALL(3, 50);
  c21_t294 = ((-c21_Cz4) + c21_t292) + c21_t293;
  _SFD_SCRIPT_CALL(3, 51);
  c21_t297 = c21_t275 * c21_t280;
  _SFD_SCRIPT_CALL(3, 52);
  c21_t309 = c21_t276 * c21_t282;
  _SFD_SCRIPT_CALL(3, 53);
  c21_t299 = c21_t297 - c21_t309;
  _SFD_SCRIPT_CALL(3, 54);
  c21_t300 = c21_t275 * c21_t282;
  _SFD_SCRIPT_CALL(3, 55);
  c21_t301 = c21_t276 * c21_t280;
  _SFD_SCRIPT_CALL(3, 56);
  c21_t302 = c21_t300 + c21_t301;
  _SFD_SCRIPT_CALL(3, 57);
  c21_t303 = c21_t271 * c21_t287;
  _SFD_SCRIPT_CALL(3, 58);
  c21_t304 = c21_t272 * (c21_t283 - c21_t295);
  _SFD_SCRIPT_CALL(3, 59);
  c21_t305 = c21_t303 + c21_t304;
  _SFD_SCRIPT_CALL(3, 60);
  c21_t306 = c21_t265 * c21_t305;
  _SFD_SCRIPT_CALL(3, 61);
  c21_t307 = c21_t265 * c21_t266 * c21_t268;
  _SFD_SCRIPT_CALL(3, 62);
  c21_t311 = c21_t265 * c21_t268 * c21_t290;
  _SFD_SCRIPT_CALL(3, 63);
  c21_t308 = (c21_Cy4 + c21_t307) - c21_t311;
  _SFD_SCRIPT_CALL(3, 64);
  c21_t310 = c21_t266 * c21_t305;
  _SFD_SCRIPT_CALL(3, 65);
  c21_t312 = c21_t272 * c21_t275;
  _SFD_SCRIPT_CALL(3, 66);
  c21_t313 = c21_t271 * c21_t276;
  _SFD_SCRIPT_CALL(3, 67);
  c21_t314 = c21_t265 * c21_t271 * c21_t275;
  _SFD_SCRIPT_CALL(3, 68);
  c21_t315 = c21_t314 - c21_t265 * c21_t272 * c21_t276;
  _SFD_SCRIPT_CALL(3, 69);
  c21_t316 = c21_t266 * c21_t271 * c21_t275;
  _SFD_SCRIPT_CALL(3, 70);
  c21_t317 = c21_t316 - c21_t266 * c21_t272 * c21_t276;
  _SFD_SCRIPT_CALL(3, 71);
  c21_m_x[0] = (-c21_t270) * c21_t271 * c21_t275 + c21_t270 * c21_t272 *
    c21_t276;
  c21_m_x[1] = ((-c21_t266) * c21_t280 - c21_t275 * ((c21_t266 * c21_t287 +
    c21_t272 * c21_t294) - c21_Cx4 * c21_t266 * c21_t271)) -
    c21_t276 * (((-c21_t266) * c21_t296 + c21_t271 * c21_t294) + c21_Cx4 *
                c21_t266 * c21_t272);
  c21_m_x[2] = (c21_t265 * c21_t280 - c21_t275 * (((-c21_t265) * c21_t287 +
    c21_t272 * c21_t308) + c21_Cx4 * c21_t265 * c21_t271)) -
    c21_t276 * ((c21_t265 * c21_t296 + c21_t271 * c21_t308) - c21_Cx4 * c21_t265
                * c21_t272);
  c21_m_x[3] = (-c21_t312) - c21_t313;
  c21_m_x[4] = c21_t315;
  c21_m_x[5] = c21_t317;
  c21_m_x[6] = (((((((c21_t284 + c21_t288) + c21_t289) - c21_t268 * c21_t290) -
                   c21_t272 * c21_t287) - c21_t272 * c21_t299) - c21_t271
                 * c21_t302) - c21_L1 * (c21_t271 * c21_t275 - c21_t272 *
    c21_t276)) - c21_L2 * (c21_t312 + c21_t313);
  c21_m_x[7] = ((((c21_t306 - c21_Cx4 * c21_t265) + c21_L2 * c21_t315) - c21_L1 *
                 (c21_t265 * c21_t271 * c21_t276 + c21_t265 *
                  c21_t272 * c21_t275)) + c21_t265 * c21_t271 * c21_t299) -
    c21_t265 * c21_t272 * c21_t302;
  c21_m_x[8] = ((((c21_t310 - c21_Cx4 * c21_t266) + c21_L2 * c21_t317) - c21_L1 *
                 (c21_t266 * c21_t271 * c21_t276 + c21_t266 *
                  c21_t272 * c21_t275)) + c21_t266 * c21_t271 * c21_t299) -
    c21_t266 * c21_t272 * c21_t302;
  c21_m_x[9] = 0.0;
  c21_m_x[10] = c21_t266;
  c21_m_x[11] = -c21_t265;
  c21_m_x[12] = ((((((-c21_t283) + c21_t284) + c21_t288) + c21_t289) - c21_t271 *
                  c21_t273) - c21_t268 * c21_t290) - c21_t272 *
    c21_t287;
  c21_m_x[13] = ((c21_t306 - c21_Cx4 * c21_t265) + c21_L2 * c21_t265 * c21_t271)
    - c21_t265 * c21_t272 * c21_t273;
  c21_m_x[14] = ((c21_t310 - c21_Cx4 * c21_t266) + c21_L2 * c21_t266 * c21_t271)
    - c21_t266 * c21_t272 * c21_t273;
  c21_m_x[15] = 0.0;
  c21_m_x[16] = c21_t266;
  c21_m_x[17] = -c21_t265;
  c21_m_x[18] = 0.0;
  c21_m_x[19] = (((-c21_Cz4) + c21_t292) + c21_t293) + c21_t266 * c21_t268;
  c21_m_x[20] = ((c21_Cy4 - c21_t269) + c21_t307) - c21_t311;
  c21_m_x[21] = 1.0;
  c21_m_x[22] = 0.0;
  c21_m_x[23] = 0.0;
  c21_m_x[24] = 0.0;
  c21_m_x[25] = 0.0;
  c21_m_x[26] = 0.0;
  c21_m_x[27] = 0.0;
  c21_m_x[28] = 0.0;
  c21_m_x[29] = 0.0;
  c21_m_x[30] = 0.0;
  c21_m_x[31] = 0.0;
  c21_m_x[32] = 0.0;
  c21_m_x[33] = 0.0;
  c21_m_x[34] = 0.0;
  c21_m_x[35] = 0.0;
  for (c21_k = 1; c21_k < 37; c21_k = c21_k + 1) {
    c21_b_k = c21_k;
    c21_body_Jacobian_d4_[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c21_b_k), 1, 36, 1, 0) - 1] = c21_m_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c21_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(3, -71);
  sf_debug_symbol_scope_pop();
}

static real_T c21_power(SFc21_DynJointVerifyInstanceStruct *chartInstance,
  real_T c21_a, real_T c21_b)
{
  real_T c21_ak;
  real_T c21_bk;
  real_T c21_x;
  real_T c21_b_x;
  c21_b_eml_scalar_eg(chartInstance);
  c21_ak = c21_a;
  c21_bk = c21_b;
  if (c21_ak < 0.0) {
    c21_x = c21_bk;
    c21_b_x = c21_x;
    c21_b_x = muDoubleScalarFloor(c21_b_x);
    if (c21_b_x != c21_bk) {
      c21_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c21_ak, c21_bk);
}

static void c21_eml_error(SFc21_DynJointVerifyInstanceStruct *chartInstance)
{
  int32_T c21_i101;
  static char_T c21_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c21_u[32];
  const mxArray *c21_y = NULL;
  int32_T c21_i102;
  static char_T c21_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
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

  char_T c21_b_u[102];
  const mxArray *c21_b_y = NULL;
  for (c21_i101 = 0; c21_i101 < 32; c21_i101 = c21_i101 + 1) {
    c21_u[c21_i101] = c21_cv0[c21_i101];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c21_i102 = 0; c21_i102 < 102; c21_i102 = c21_i102 + 1) {
    c21_b_u[c21_i102] = c21_cv1[c21_i102];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c21_y, 14, c21_b_y);
}

static void c21_body_Jacobian_d5(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T
  c21_in3[18], real_T c21_body_Jacobian_d5_[36])
{
  uint32_T c21_debug_family_var_map[121];
  real_T c21_A2;
  real_T c21_A3;
  real_T c21_A4;
  real_T c21_A5;
  real_T c21_Cx5;
  real_T c21_Cy5;
  real_T c21_Cz5;
  real_T c21_L1;
  real_T c21_L2;
  real_T c21_L3;
  real_T c21_L4;
  real_T c21_L5;
  real_T c21_t161;
  real_T c21_t162;
  real_T c21_t163;
  real_T c21_t164;
  real_T c21_t165;
  real_T c21_t166;
  real_T c21_t167;
  real_T c21_t168;
  real_T c21_t169;
  real_T c21_t170;
  real_T c21_t205;
  real_T c21_t171;
  real_T c21_t172;
  real_T c21_t173;
  real_T c21_t174;
  real_T c21_t175;
  real_T c21_t206;
  real_T c21_t176;
  real_T c21_t177;
  real_T c21_t178;
  real_T c21_t179;
  real_T c21_t180;
  real_T c21_t181;
  real_T c21_t216;
  real_T c21_t217;
  real_T c21_t182;
  real_T c21_t215;
  real_T c21_t183;
  real_T c21_t184;
  real_T c21_t185;
  real_T c21_t186;
  real_T c21_t187;
  real_T c21_t188;
  real_T c21_t189;
  real_T c21_t190;
  real_T c21_t191;
  real_T c21_t199;
  real_T c21_t192;
  real_T c21_t193;
  real_T c21_t194;
  real_T c21_t195;
  real_T c21_t196;
  real_T c21_t197;
  real_T c21_t227;
  real_T c21_t198;
  real_T c21_t200;
  real_T c21_t207;
  real_T c21_t201;
  real_T c21_t202;
  real_T c21_t203;
  real_T c21_t204;
  real_T c21_t208;
  real_T c21_t253;
  real_T c21_t209;
  real_T c21_t210;
  real_T c21_t211;
  real_T c21_t212;
  real_T c21_t213;
  real_T c21_t214;
  real_T c21_t218;
  real_T c21_t219;
  real_T c21_t220;
  real_T c21_t221;
  real_T c21_t236;
  real_T c21_t222;
  real_T c21_t224;
  real_T c21_t225;
  real_T c21_t223;
  real_T c21_t226;
  real_T c21_t251;
  real_T c21_t228;
  real_T c21_t229;
  real_T c21_t230;
  real_T c21_t231;
  real_T c21_t232;
  real_T c21_t233;
  real_T c21_t234;
  real_T c21_t235;
  real_T c21_t237;
  real_T c21_t238;
  real_T c21_t239;
  real_T c21_t240;
  real_T c21_t241;
  real_T c21_t242;
  real_T c21_t243;
  real_T c21_t244;
  real_T c21_t245;
  real_T c21_t246;
  real_T c21_t252;
  real_T c21_t247;
  real_T c21_t248;
  real_T c21_t249;
  real_T c21_t250;
  real_T c21_t254;
  real_T c21_t255;
  real_T c21_t256;
  real_T c21_t257;
  real_T c21_t258;
  real_T c21_t259;
  real_T c21_t260;
  real_T c21_t261;
  real_T c21_t262;
  real_T c21_t263;
  real_T c21_nargin = 3.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  real_T c21_i_x;
  real_T c21_j_x;
  real_T c21_k_x;
  real_T c21_l_x;
  real_T c21_m_x;
  real_T c21_n_x;
  real_T c21_o_x;
  real_T c21_p_x;
  real_T c21_q_x[36];
  int32_T c21_k;
  int32_T c21_b_k;
  sf_debug_symbol_scope_push_eml(0U, 121U, 121U, c21_f_debug_family_names,
    c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c21_A2, c21_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c21_A3, c21_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c21_A4, c21_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c21_A5, c21_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c21_Cx5, c21_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c21_Cy5, c21_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c21_Cz5, c21_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c21_L1, c21_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c21_L2, c21_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c21_L3, c21_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c21_L4, c21_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c21_L5, c21_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c21_t161, c21_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c21_t162, c21_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c21_t163, c21_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c21_t164, c21_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c21_t165, c21_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c21_t166, c21_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c21_t167, c21_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c21_t168, c21_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c21_t169, c21_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c21_t170, c21_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c21_t205, c21_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c21_t171, c21_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c21_t172, c21_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c21_t173, c21_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c21_t174, c21_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c21_t175, c21_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c21_t206, c21_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c21_t176, c21_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c21_t177, c21_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c21_t178, c21_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c21_t179, c21_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c21_t180, c21_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c21_t181, c21_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c21_t216, c21_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c21_t217, c21_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c21_t182, c21_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c21_t215, c21_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c21_t183, c21_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c21_t184, c21_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c21_t185, c21_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c21_t186, c21_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c21_t187, c21_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c21_t188, c21_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c21_t189, c21_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c21_t190, c21_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c21_t191, c21_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c21_t199, c21_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c21_t192, c21_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c21_t193, c21_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c21_t194, c21_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c21_t195, c21_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c21_t196, c21_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c21_t197, c21_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c21_t227, c21_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c21_t198, c21_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c21_t200, c21_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c21_t207, c21_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c21_t201, c21_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c21_t202, c21_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c21_t203, c21_d_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c21_t204, c21_d_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c21_t208, c21_d_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c21_t253, c21_d_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(&c21_t209, c21_d_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c21_t210, c21_d_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(&c21_t211, c21_d_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(&c21_t212, c21_d_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(&c21_t213, c21_d_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(&c21_t214, c21_d_sf_marshall, 70U);
  sf_debug_symbol_scope_add_eml(&c21_t218, c21_d_sf_marshall, 71U);
  sf_debug_symbol_scope_add_eml(&c21_t219, c21_d_sf_marshall, 72U);
  sf_debug_symbol_scope_add_eml(&c21_t220, c21_d_sf_marshall, 73U);
  sf_debug_symbol_scope_add_eml(&c21_t221, c21_d_sf_marshall, 74U);
  sf_debug_symbol_scope_add_eml(&c21_t236, c21_d_sf_marshall, 75U);
  sf_debug_symbol_scope_add_eml(&c21_t222, c21_d_sf_marshall, 76U);
  sf_debug_symbol_scope_add_eml(&c21_t224, c21_d_sf_marshall, 77U);
  sf_debug_symbol_scope_add_eml(&c21_t225, c21_d_sf_marshall, 78U);
  sf_debug_symbol_scope_add_eml(&c21_t223, c21_d_sf_marshall, 79U);
  sf_debug_symbol_scope_add_eml(&c21_t226, c21_d_sf_marshall, 80U);
  sf_debug_symbol_scope_add_eml(&c21_t251, c21_d_sf_marshall, 81U);
  sf_debug_symbol_scope_add_eml(&c21_t228, c21_d_sf_marshall, 82U);
  sf_debug_symbol_scope_add_eml(&c21_t229, c21_d_sf_marshall, 83U);
  sf_debug_symbol_scope_add_eml(&c21_t230, c21_d_sf_marshall, 84U);
  sf_debug_symbol_scope_add_eml(&c21_t231, c21_d_sf_marshall, 85U);
  sf_debug_symbol_scope_add_eml(&c21_t232, c21_d_sf_marshall, 86U);
  sf_debug_symbol_scope_add_eml(&c21_t233, c21_d_sf_marshall, 87U);
  sf_debug_symbol_scope_add_eml(&c21_t234, c21_d_sf_marshall, 88U);
  sf_debug_symbol_scope_add_eml(&c21_t235, c21_d_sf_marshall, 89U);
  sf_debug_symbol_scope_add_eml(&c21_t237, c21_d_sf_marshall, 90U);
  sf_debug_symbol_scope_add_eml(&c21_t238, c21_d_sf_marshall, 91U);
  sf_debug_symbol_scope_add_eml(&c21_t239, c21_d_sf_marshall, 92U);
  sf_debug_symbol_scope_add_eml(&c21_t240, c21_d_sf_marshall, 93U);
  sf_debug_symbol_scope_add_eml(&c21_t241, c21_d_sf_marshall, 94U);
  sf_debug_symbol_scope_add_eml(&c21_t242, c21_d_sf_marshall, 95U);
  sf_debug_symbol_scope_add_eml(&c21_t243, c21_d_sf_marshall, 96U);
  sf_debug_symbol_scope_add_eml(&c21_t244, c21_d_sf_marshall, 97U);
  sf_debug_symbol_scope_add_eml(&c21_t245, c21_d_sf_marshall, 98U);
  sf_debug_symbol_scope_add_eml(&c21_t246, c21_d_sf_marshall, 99U);
  sf_debug_symbol_scope_add_eml(&c21_t252, c21_d_sf_marshall, 100U);
  sf_debug_symbol_scope_add_eml(&c21_t247, c21_d_sf_marshall, 101U);
  sf_debug_symbol_scope_add_eml(&c21_t248, c21_d_sf_marshall, 102U);
  sf_debug_symbol_scope_add_eml(&c21_t249, c21_d_sf_marshall, 103U);
  sf_debug_symbol_scope_add_eml(&c21_t250, c21_d_sf_marshall, 104U);
  sf_debug_symbol_scope_add_eml(&c21_t254, c21_d_sf_marshall, 105U);
  sf_debug_symbol_scope_add_eml(&c21_t255, c21_d_sf_marshall, 106U);
  sf_debug_symbol_scope_add_eml(&c21_t256, c21_d_sf_marshall, 107U);
  sf_debug_symbol_scope_add_eml(&c21_t257, c21_d_sf_marshall, 108U);
  sf_debug_symbol_scope_add_eml(&c21_t258, c21_d_sf_marshall, 109U);
  sf_debug_symbol_scope_add_eml(&c21_t259, c21_d_sf_marshall, 110U);
  sf_debug_symbol_scope_add_eml(&c21_t260, c21_d_sf_marshall, 111U);
  sf_debug_symbol_scope_add_eml(&c21_t261, c21_d_sf_marshall, 112U);
  sf_debug_symbol_scope_add_eml(&c21_t262, c21_d_sf_marshall, 113U);
  sf_debug_symbol_scope_add_eml(&c21_t263, c21_d_sf_marshall, 114U);
  sf_debug_symbol_scope_add_eml(&c21_nargin, c21_d_sf_marshall, 115U);
  sf_debug_symbol_scope_add_eml(&c21_nargout, c21_d_sf_marshall, 116U);
  sf_debug_symbol_scope_add_eml(c21_in1, c21_e_sf_marshall, 117U);
  sf_debug_symbol_scope_add_eml(c21_in2, c21_g_sf_marshall, 118U);
  sf_debug_symbol_scope_add_eml(c21_in3, c21_b_sf_marshall, 119U);
  sf_debug_symbol_scope_add_eml(c21_body_Jacobian_d5_, c21_f_sf_marshall, 120U);
  CV_SCRIPT_FCN(4, 0);

  /* BODY_JACOBIAN_D5 */
  /*     BODY_JACOBIAN_D5_ = BODY_JACOBIAN_D5(IN1,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 15:39:33 */
  _SFD_SCRIPT_CALL(4, 8);
  c21_A2 = c21_in2[1];
  _SFD_SCRIPT_CALL(4, 9);
  c21_A3 = c21_in2[2];
  _SFD_SCRIPT_CALL(4, 10);
  c21_A4 = c21_in2[3];
  _SFD_SCRIPT_CALL(4, 11);
  c21_A5 = c21_in2[4];
  _SFD_SCRIPT_CALL(4, 12);
  c21_Cx5 = c21_in3[4];
  _SFD_SCRIPT_CALL(4, 13);
  c21_Cy5 = c21_in3[10];
  _SFD_SCRIPT_CALL(4, 14);
  c21_Cz5 = c21_in3[16];
  _SFD_SCRIPT_CALL(4, 15);
  c21_L1 = c21_in1[0];
  _SFD_SCRIPT_CALL(4, 16);
  c21_L2 = c21_in1[1];
  _SFD_SCRIPT_CALL(4, 17);
  c21_L3 = c21_in1[2];
  _SFD_SCRIPT_CALL(4, 18);
  c21_L4 = c21_in1[3];
  _SFD_SCRIPT_CALL(4, 19);
  c21_L5 = c21_in1[4];
  _SFD_SCRIPT_CALL(4, 20);
  c21_x = c21_A5;
  c21_t161 = c21_x;
  c21_b_x = c21_t161;
  c21_t161 = c21_b_x;
  c21_t161 = muDoubleScalarCos(c21_t161);
  _SFD_SCRIPT_CALL(4, 21);
  c21_c_x = c21_A5;
  c21_t162 = c21_c_x;
  c21_d_x = c21_t162;
  c21_t162 = c21_d_x;
  c21_t162 = muDoubleScalarSin(c21_t162);
  _SFD_SCRIPT_CALL(4, 22);
  c21_t163 = (c21_L1 + c21_L3) + c21_L4;
  _SFD_SCRIPT_CALL(4, 23);
  c21_t164 = c21_t161 - 1.0;
  _SFD_SCRIPT_CALL(4, 24);
  c21_t165 = c21_L2 + c21_L5;
  _SFD_SCRIPT_CALL(4, 25);
  c21_e_x = c21_A4;
  c21_t166 = c21_e_x;
  c21_f_x = c21_t166;
  c21_t166 = c21_f_x;
  c21_t166 = muDoubleScalarSin(c21_t166);
  _SFD_SCRIPT_CALL(4, 26);
  c21_g_x = c21_A4;
  c21_t167 = c21_g_x;
  c21_h_x = c21_t167;
  c21_t167 = c21_h_x;
  c21_t167 = muDoubleScalarCos(c21_t167);
  _SFD_SCRIPT_CALL(4, 27);
  c21_i_x = c21_A3;
  c21_t168 = c21_i_x;
  c21_j_x = c21_t168;
  c21_t168 = c21_j_x;
  c21_t168 = muDoubleScalarSin(c21_t168);
  _SFD_SCRIPT_CALL(4, 28);
  c21_k_x = c21_A3;
  c21_t169 = c21_k_x;
  c21_l_x = c21_t169;
  c21_t169 = c21_l_x;
  c21_t169 = muDoubleScalarCos(c21_t169);
  _SFD_SCRIPT_CALL(4, 29);
  c21_t170 = c21_t162 * c21_t165;
  _SFD_SCRIPT_CALL(4, 30);
  c21_t205 = c21_t163 * c21_t164;
  _SFD_SCRIPT_CALL(4, 31);
  c21_t171 = c21_t170 - c21_t205;
  _SFD_SCRIPT_CALL(4, 32);
  c21_t172 = c21_t161 * c21_t171;
  _SFD_SCRIPT_CALL(4, 33);
  c21_t173 = c21_t162 * c21_t163;
  _SFD_SCRIPT_CALL(4, 34);
  c21_t174 = c21_t164 * c21_t165;
  _SFD_SCRIPT_CALL(4, 35);
  c21_t175 = c21_t173 + c21_t174;
  _SFD_SCRIPT_CALL(4, 36);
  c21_t206 = c21_t162 * c21_t175;
  _SFD_SCRIPT_CALL(4, 37);
  c21_t176 = (c21_Cz5 + c21_t172) - c21_t206;
  _SFD_SCRIPT_CALL(4, 38);
  c21_t177 = c21_Cy5 * c21_t161 * c21_t167;
  _SFD_SCRIPT_CALL(4, 39);
  c21_t178 = c21_t161 * c21_t163 * c21_t166;
  _SFD_SCRIPT_CALL(4, 40);
  c21_t179 = (c21_t177 + c21_t178) - c21_t166 * c21_t176;
  _SFD_SCRIPT_CALL(4, 41);
  c21_t180 = c21_t167 - 1.0;
  _SFD_SCRIPT_CALL(4, 42);
  c21_t181 = c21_t163 * c21_t166 * c21_t167;
  _SFD_SCRIPT_CALL(4, 43);
  c21_t216 = c21_t163 * c21_t166 * c21_t180;
  _SFD_SCRIPT_CALL(4, 44);
  c21_t217 = c21_t181 - c21_t216;
  _SFD_SCRIPT_CALL(4, 45);
  c21_t182 = c21_t162 * c21_t217;
  _SFD_SCRIPT_CALL(4, 46);
  c21_t215 = c21_Cy5 * c21_t162;
  _SFD_SCRIPT_CALL(4, 47);
  c21_t183 = c21_t182 + c21_t215;
  _SFD_SCRIPT_CALL(4, 48);
  c21_t184 = c21_t169 - 1.0;
  _SFD_SCRIPT_CALL(4, 49);
  c21_t185 = c21_L1 + c21_L3;
  _SFD_SCRIPT_CALL(4, 50);
  c21_m_x = c21_A2;
  c21_t186 = c21_m_x;
  c21_n_x = c21_t186;
  c21_t186 = c21_n_x;
  c21_t186 = muDoubleScalarSin(c21_t186);
  _SFD_SCRIPT_CALL(4, 51);
  c21_o_x = c21_A2;
  c21_t187 = c21_o_x;
  c21_p_x = c21_t187;
  c21_t187 = c21_p_x;
  c21_t187 = muDoubleScalarCos(c21_t187);
  _SFD_SCRIPT_CALL(4, 52);
  c21_t188 = c21_t161 * c21_t168;
  _SFD_SCRIPT_CALL(4, 53);
  c21_t189 = c21_t162 * c21_t167 * c21_t169;
  _SFD_SCRIPT_CALL(4, 54);
  c21_t190 = c21_t188 + c21_t189;
  _SFD_SCRIPT_CALL(4, 55);
  c21_t191 = c21_t161 * c21_t169;
  _SFD_SCRIPT_CALL(4, 56);
  c21_t199 = c21_t162 * c21_t167 * c21_t168;
  _SFD_SCRIPT_CALL(4, 57);
  c21_t192 = c21_t191 - c21_t199;
  _SFD_SCRIPT_CALL(4, 58);
  c21_t193 = c21_L1 * c21_t186;
  _SFD_SCRIPT_CALL(4, 59);
  c21_t194 = c21_t187 - 1.0;
  _SFD_SCRIPT_CALL(4, 60);
  c21_t195 = c21_L2 * c21_t194;
  _SFD_SCRIPT_CALL(4, 61);
  c21_t196 = c21_t193 + c21_t195;
  _SFD_SCRIPT_CALL(4, 62);
  c21_t197 = c21_L1 * c21_t194;
  _SFD_SCRIPT_CALL(4, 63);
  c21_t227 = c21_L2 * c21_t186;
  _SFD_SCRIPT_CALL(4, 64);
  c21_t198 = c21_t197 - c21_t227;
  _SFD_SCRIPT_CALL(4, 65);
  c21_t200 = c21_L2 * c21_t168;
  _SFD_SCRIPT_CALL(4, 66);
  c21_t207 = c21_t184 * c21_t185;
  _SFD_SCRIPT_CALL(4, 67);
  c21_t201 = c21_t200 - c21_t207;
  _SFD_SCRIPT_CALL(4, 68);
  c21_t202 = c21_t168 * c21_t185;
  _SFD_SCRIPT_CALL(4, 69);
  c21_t203 = c21_L2 * c21_t184;
  _SFD_SCRIPT_CALL(4, 70);
  c21_t204 = c21_t202 + c21_t203;
  _SFD_SCRIPT_CALL(4, 71);
  c21_t208 = c21_t169 * c21_t201;
  _SFD_SCRIPT_CALL(4, 72);
  c21_t253 = c21_t168 * c21_t204;
  _SFD_SCRIPT_CALL(4, 73);
  c21_t209 = c21_t161 * (c21_t208 - c21_t253);
  _SFD_SCRIPT_CALL(4, 74);
  c21_t210 = c21_t167 * c21_t176;
  _SFD_SCRIPT_CALL(4, 75);
  c21_t211 = c21_t169 * c21_t204;
  _SFD_SCRIPT_CALL(4, 76);
  c21_t212 = c21_t168 * c21_t201;
  _SFD_SCRIPT_CALL(4, 77);
  c21_t213 = c21_t211 + c21_t212;
  _SFD_SCRIPT_CALL(4, 78);
  c21_t214 = c21_Cy5 * c21_t161 * c21_t166;
  _SFD_SCRIPT_CALL(4, 79);
  c21_t218 = c21_Cx5 * c21_t162;
  _SFD_SCRIPT_CALL(4, 80);
  c21_t219 = c21_power(chartInstance, c21_t166, 2.0);
  _SFD_SCRIPT_CALL(4, 81);
  c21_t220 = c21_t163 * c21_t219;
  _SFD_SCRIPT_CALL(4, 82);
  c21_t221 = c21_t163 * c21_t167 * c21_t180;
  _SFD_SCRIPT_CALL(4, 83);
  c21_t236 = c21_Cz5 * c21_t161;
  _SFD_SCRIPT_CALL(4, 84);
  c21_t222 = (((((-c21_t170) + c21_t205) + c21_t218) + c21_t220) + c21_t221) -
    c21_t236;
  _SFD_SCRIPT_CALL(4, 85);
  c21_t224 = c21_Cx5 * c21_t161;
  _SFD_SCRIPT_CALL(4, 86);
  c21_t225 = c21_Cz5 * c21_t162;
  _SFD_SCRIPT_CALL(4, 87);
  c21_t223 = ((c21_t173 + c21_t174) - c21_t224) - c21_t225;
  _SFD_SCRIPT_CALL(4, 88);
  c21_t226 = c21_t187 * c21_t196;
  _SFD_SCRIPT_CALL(4, 89);
  c21_t251 = c21_t186 * c21_t198;
  _SFD_SCRIPT_CALL(4, 90);
  c21_t228 = c21_t226 - c21_t251;
  _SFD_SCRIPT_CALL(4, 91);
  c21_t229 = c21_t187 * c21_t198;
  _SFD_SCRIPT_CALL(4, 92);
  c21_t230 = c21_t186 * c21_t196;
  _SFD_SCRIPT_CALL(4, 93);
  c21_t231 = c21_t229 + c21_t230;
  _SFD_SCRIPT_CALL(4, 94);
  c21_t232 = c21_t168 * (c21_t200 - c21_t207);
  _SFD_SCRIPT_CALL(4, 95);
  c21_t233 = c21_t211 + c21_t232;
  _SFD_SCRIPT_CALL(4, 96);
  c21_t234 = c21_t166 * c21_t233;
  _SFD_SCRIPT_CALL(4, 97);
  c21_t235 = c21_t166 * (((c21_t173 + c21_t174) - c21_t224) - c21_t225);
  _SFD_SCRIPT_CALL(4, 98);
  c21_t237 = c21_t162 * c21_t163 * c21_t166;
  _SFD_SCRIPT_CALL(4, 99);
  c21_t238 = c21_Cy5 * c21_t161;
  _SFD_SCRIPT_CALL(4, 100);
  c21_t239 = c21_t161 * c21_t217;
  _SFD_SCRIPT_CALL(4, 101);
  c21_t240 = c21_t238 + c21_t239;
  _SFD_SCRIPT_CALL(4, 102);
  c21_t241 = c21_t161 * c21_t175;
  _SFD_SCRIPT_CALL(4, 103);
  c21_t242 = c21_t162 * c21_t171;
  _SFD_SCRIPT_CALL(4, 104);
  c21_t243 = ((-c21_Cx5) + c21_t241) + c21_t242;
  _SFD_SCRIPT_CALL(4, 105);
  c21_t244 = c21_Cy5 * c21_t162 * c21_t167;
  _SFD_SCRIPT_CALL(4, 106);
  c21_t245 = (c21_t237 + c21_t244) - c21_t166 * c21_t243;
  _SFD_SCRIPT_CALL(4, 107);
  c21_t246 = c21_t162 * c21_t168;
  _SFD_SCRIPT_CALL(4, 108);
  c21_t252 = c21_t161 * c21_t167 * c21_t169;
  _SFD_SCRIPT_CALL(4, 109);
  c21_t247 = c21_t246 - c21_t252;
  _SFD_SCRIPT_CALL(4, 110);
  c21_t248 = c21_t162 * c21_t169;
  _SFD_SCRIPT_CALL(4, 111);
  c21_t249 = c21_t161 * c21_t167 * c21_t168;
  _SFD_SCRIPT_CALL(4, 112);
  c21_t250 = c21_t248 + c21_t249;
  _SFD_SCRIPT_CALL(4, 113);
  c21_t254 = c21_t167 * c21_t243;
  _SFD_SCRIPT_CALL(4, 114);
  c21_t255 = c21_t162 * (c21_t208 - c21_t253);
  _SFD_SCRIPT_CALL(4, 115);
  c21_t256 = c21_Cy5 * c21_t162 * c21_t166;
  _SFD_SCRIPT_CALL(4, 116);
  c21_t257 = c21_t161 * c21_t167 * c21_t233;
  _SFD_SCRIPT_CALL(4, 117);
  c21_t258 = c21_t187 * c21_t190;
  _SFD_SCRIPT_CALL(4, 118);
  c21_t259 = c21_t186 * c21_t192;
  _SFD_SCRIPT_CALL(4, 119);
  c21_t260 = c21_t162 * c21_t166;
  _SFD_SCRIPT_CALL(4, 120);
  c21_t261 = c21_t166 * c21_t168 * c21_t186;
  _SFD_SCRIPT_CALL(4, 121);
  c21_t262 = c21_t187 * c21_t247;
  _SFD_SCRIPT_CALL(4, 122);
  c21_t263 = c21_t186 * c21_t250;
  _SFD_SCRIPT_CALL(4, 123);
  c21_q_x[0] = (c21_t186 * ((c21_t168 * c21_t179 + c21_t169 * c21_t183) +
    c21_t162 * c21_t166 * c21_t201) - c21_t187 * ((c21_t169 *
    c21_t179 - c21_t168 * c21_t183) + c21_t162 * c21_t166 * c21_t204)) -
    c21_t162 * c21_t166 * c21_t196;
  c21_q_x[1] = ((-c21_t167) * c21_t196 + c21_t186 * ((c21_t167 * c21_t201 -
    c21_t169 * c21_t222) + c21_t167 * c21_t168 * c21_t223)) -
    c21_t187 * ((c21_t167 * c21_t204 + c21_t168 * c21_t222) + c21_t167 *
                c21_t169 * c21_t223);
  c21_q_x[2] = ((-c21_t186) * ((c21_t169 * c21_t240 - c21_t168 * c21_t245) +
    c21_t161 * c21_t166 * c21_t201) - c21_t187 * ((c21_t168
    * c21_t240 + c21_t169 * c21_t245) - c21_t161 * c21_t166 * c21_t204)) +
    c21_t161 * c21_t166 * c21_t196;
  c21_q_x[3] = (-c21_t258) - c21_t259;
  c21_q_x[4] = (-c21_t261) + c21_t166 * c21_t169 * c21_t187;
  c21_q_x[5] = (-c21_t262) - c21_t263;
  c21_q_x[6] = (((((((c21_t209 + c21_t210) + c21_t214) - c21_t190 * c21_t228) -
                   c21_t192 * c21_t231) + c21_L1 * (c21_t186 * c21_t190
    - c21_t187 * c21_t192)) - c21_L2 * (c21_t258 + c21_t259)) - c21_t161 *
                c21_t163 * c21_t180) - c21_t162 * c21_t167 * c21_t213;
  c21_q_x[7] = ((((c21_t234 + c21_t235) - c21_L2 * (c21_t261 - c21_t166 *
    c21_t169 * c21_t187)) - c21_L1 * (c21_t166 * c21_t168 *
    c21_t187 + c21_t166 * c21_t169 * c21_t186)) + c21_t166 * c21_t169 * c21_t228)
    - c21_t166 * c21_t168 * c21_t231;
  c21_q_x[8] = (((((((c21_t254 + c21_t255) + c21_t256) + c21_t257) - c21_t228 *
                   c21_t247) - c21_t231 * c21_t250) + c21_L1 * (c21_t186
    * c21_t247 - c21_t187 * c21_t250)) - c21_L2 * (c21_t262 + c21_t263)) -
    c21_t162 * c21_t163 * c21_t180;
  c21_q_x[9] = c21_t260;
  c21_q_x[10] = c21_t167;
  c21_q_x[11] = (-c21_t161) * c21_t166;
  c21_q_x[12] = (((((c21_t209 + c21_t210) + c21_t214) - c21_L2 * c21_t190) -
                  c21_t185 * c21_t192) - c21_t161 * c21_t163 * c21_t180) -
    c21_t162 * c21_t167 * c21_t213;
  c21_q_x[13] = ((c21_t234 + c21_t235) + c21_L2 * c21_t166 * c21_t169) -
    c21_t166 * c21_t168 * c21_t185;
  c21_q_x[14] = (((((c21_t254 + c21_t255) + c21_t256) + c21_t257) - c21_L2 *
                  c21_t247) - c21_t185 * c21_t250) - c21_t162 * c21_t163 *
    c21_t180;
  c21_q_x[15] = c21_t260;
  c21_q_x[16] = c21_t167;
  c21_q_x[17] = (-c21_t161) * c21_t166;
  c21_q_x[18] = ((-c21_t182) - c21_t215) + c21_t237;
  c21_q_x[19] = ((((((-c21_t170) + c21_t205) + c21_t218) + c21_t220) + c21_t221)
                 - c21_t236) + c21_t163 * c21_t167;
  c21_q_x[20] = ((-c21_t178) + c21_t238) + c21_t161 * (c21_t181 - c21_t216);
  c21_q_x[21] = c21_t161;
  c21_q_x[22] = 0.0;
  c21_q_x[23] = c21_t162;
  c21_q_x[24] = (((c21_Cz5 - c21_t170) + c21_t172) - c21_t206) - c21_t161 *
    c21_t163;
  c21_q_x[25] = 0.0;
  c21_q_x[26] = ((((-c21_Cx5) - c21_t173) + c21_t241) + c21_t242) + c21_t161 *
    c21_t165;
  c21_q_x[27] = 0.0;
  c21_q_x[28] = 1.0;
  c21_q_x[29] = 0.0;
  c21_q_x[30] = 0.0;
  c21_q_x[31] = 0.0;
  c21_q_x[32] = 0.0;
  c21_q_x[33] = 0.0;
  c21_q_x[34] = 0.0;
  c21_q_x[35] = 0.0;
  for (c21_k = 1; c21_k < 37; c21_k = c21_k + 1) {
    c21_b_k = c21_k;
    c21_body_Jacobian_d5_[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c21_b_k), 1, 36, 1, 0) - 1] = c21_q_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c21_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(4, -123);
  sf_debug_symbol_scope_pop();
}

static void c21_body_Jacobian_d6(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, real_T c21_in1[9], real_T c21_in2[6], real_T
  c21_in3[18], real_T c21_body_Jacobian_d6_[36])
{
  uint32_T c21_debug_family_var_map[177];
  real_T c21_A2;
  real_T c21_A3;
  real_T c21_A4;
  real_T c21_A5;
  real_T c21_A6;
  real_T c21_Cx6;
  real_T c21_Cy6;
  real_T c21_Cz6;
  real_T c21_L1;
  real_T c21_L2;
  real_T c21_L3;
  real_T c21_L4;
  real_T c21_L5;
  real_T c21_t2;
  real_T c21_t3;
  real_T c21_t4;
  real_T c21_t5;
  real_T c21_t6;
  real_T c21_t7;
  real_T c21_t8;
  real_T c21_t9;
  real_T c21_t10;
  real_T c21_t11;
  real_T c21_t27;
  real_T c21_t12;
  real_T c21_t13;
  real_T c21_t14;
  real_T c21_t15;
  real_T c21_t16;
  real_T c21_t55;
  real_T c21_t17;
  real_T c21_t18;
  real_T c21_t19;
  real_T c21_t20;
  real_T c21_t21;
  real_T c21_t22;
  real_T c21_t23;
  real_T c21_t24;
  real_T c21_t56;
  real_T c21_t57;
  real_T c21_t25;
  real_T c21_t26;
  real_T c21_t28;
  real_T c21_t29;
  real_T c21_t30;
  real_T c21_t31;
  real_T c21_t67;
  real_T c21_t68;
  real_T c21_t32;
  real_T c21_t66;
  real_T c21_t33;
  real_T c21_t34;
  real_T c21_t35;
  real_T c21_t36;
  real_T c21_t37;
  real_T c21_t38;
  real_T c21_t39;
  real_T c21_t40;
  real_T c21_t41;
  real_T c21_t49;
  real_T c21_t42;
  real_T c21_t43;
  real_T c21_t44;
  real_T c21_t45;
  real_T c21_t46;
  real_T c21_t47;
  real_T c21_t95;
  real_T c21_t48;
  real_T c21_t50;
  real_T c21_t58;
  real_T c21_t51;
  real_T c21_t52;
  real_T c21_t53;
  real_T c21_t54;
  real_T c21_t59;
  real_T c21_t112;
  real_T c21_t113;
  real_T c21_t60;
  real_T c21_t61;
  real_T c21_t62;
  real_T c21_t63;
  real_T c21_t64;
  real_T c21_t65;
  real_T c21_t69;
  real_T c21_t70;
  real_T c21_t71;
  real_T c21_t72;
  real_T c21_t73;
  real_T c21_t94;
  real_T c21_t74;
  real_T c21_t75;
  real_T c21_t76;
  real_T c21_t77;
  real_T c21_t78;
  real_T c21_t104;
  real_T c21_t79;
  real_T c21_t80;
  real_T c21_t81;
  real_T c21_t82;
  real_T c21_t105;
  real_T c21_t83;
  real_T c21_t84;
  real_T c21_t85;
  real_T c21_t86;
  real_T c21_t87;
  real_T c21_t88;
  real_T c21_t89;
  real_T c21_t90;
  real_T c21_t91;
  real_T c21_t92;
  real_T c21_t93;
  real_T c21_t96;
  real_T c21_t97;
  real_T c21_t98;
  real_T c21_t99;
  real_T c21_t100;
  real_T c21_t101;
  real_T c21_t102;
  real_T c21_t148;
  real_T c21_t103;
  real_T c21_t106;
  real_T c21_t107;
  real_T c21_t108;
  real_T c21_t109;
  real_T c21_t111;
  real_T c21_t110;
  real_T c21_t114;
  real_T c21_t115;
  real_T c21_t116;
  real_T c21_t117;
  real_T c21_t118;
  real_T c21_t119;
  real_T c21_t127;
  real_T c21_t120;
  real_T c21_t121;
  real_T c21_t122;
  real_T c21_t123;
  real_T c21_t124;
  real_T c21_t138;
  real_T c21_t125;
  real_T c21_t126;
  real_T c21_t128;
  real_T c21_t129;
  real_T c21_t139;
  real_T c21_t130;
  real_T c21_t131;
  real_T c21_t132;
  real_T c21_t133;
  real_T c21_t134;
  real_T c21_t135;
  real_T c21_t136;
  real_T c21_t151;
  real_T c21_t152;
  real_T c21_t137;
  real_T c21_t140;
  real_T c21_t142;
  real_T c21_t141;
  real_T c21_t143;
  real_T c21_t144;
  real_T c21_t145;
  real_T c21_t146;
  real_T c21_t149;
  real_T c21_t147;
  real_T c21_t150;
  real_T c21_t153;
  real_T c21_t154;
  real_T c21_t155;
  real_T c21_t156;
  real_T c21_t157;
  real_T c21_t158;
  real_T c21_t159;
  real_T c21_nargin = 3.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  real_T c21_i_x;
  real_T c21_j_x;
  real_T c21_k_x;
  real_T c21_l_x;
  real_T c21_m_x;
  real_T c21_n_x;
  real_T c21_o_x;
  real_T c21_p_x;
  real_T c21_q_x;
  real_T c21_r_x;
  real_T c21_s_x;
  real_T c21_t_x;
  real_T c21_u_x[36];
  int32_T c21_k;
  int32_T c21_b_k;
  sf_debug_symbol_scope_push_eml(0U, 177U, 177U, c21_g_debug_family_names,
    c21_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c21_A2, c21_d_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c21_A3, c21_d_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c21_A4, c21_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c21_A5, c21_d_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c21_A6, c21_d_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c21_Cx6, c21_d_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c21_Cy6, c21_d_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c21_Cz6, c21_d_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c21_L1, c21_d_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c21_L2, c21_d_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c21_L3, c21_d_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c21_L4, c21_d_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c21_L5, c21_d_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c21_t2, c21_d_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c21_t3, c21_d_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c21_t4, c21_d_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c21_t5, c21_d_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c21_t6, c21_d_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c21_t7, c21_d_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c21_t8, c21_d_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c21_t9, c21_d_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c21_t10, c21_d_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c21_t11, c21_d_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c21_t27, c21_d_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c21_t12, c21_d_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c21_t13, c21_d_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c21_t14, c21_d_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c21_t15, c21_d_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c21_t16, c21_d_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c21_t55, c21_d_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c21_t17, c21_d_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c21_t18, c21_d_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c21_t19, c21_d_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c21_t20, c21_d_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c21_t21, c21_d_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c21_t22, c21_d_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c21_t23, c21_d_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c21_t24, c21_d_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c21_t56, c21_d_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c21_t57, c21_d_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c21_t25, c21_d_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c21_t26, c21_d_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c21_t28, c21_d_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c21_t29, c21_d_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c21_t30, c21_d_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c21_t31, c21_d_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c21_t67, c21_d_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c21_t68, c21_d_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c21_t32, c21_d_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c21_t66, c21_d_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c21_t33, c21_d_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c21_t34, c21_d_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c21_t35, c21_d_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c21_t36, c21_d_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c21_t37, c21_d_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c21_t38, c21_d_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c21_t39, c21_d_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c21_t40, c21_d_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c21_t41, c21_d_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c21_t49, c21_d_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c21_t42, c21_d_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c21_t43, c21_d_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c21_t44, c21_d_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c21_t45, c21_d_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c21_t46, c21_d_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(&c21_t47, c21_d_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c21_t95, c21_d_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(&c21_t48, c21_d_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(&c21_t50, c21_d_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(&c21_t58, c21_d_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(&c21_t51, c21_d_sf_marshall, 70U);
  sf_debug_symbol_scope_add_eml(&c21_t52, c21_d_sf_marshall, 71U);
  sf_debug_symbol_scope_add_eml(&c21_t53, c21_d_sf_marshall, 72U);
  sf_debug_symbol_scope_add_eml(&c21_t54, c21_d_sf_marshall, 73U);
  sf_debug_symbol_scope_add_eml(&c21_t59, c21_d_sf_marshall, 74U);
  sf_debug_symbol_scope_add_eml(&c21_t112, c21_d_sf_marshall, 75U);
  sf_debug_symbol_scope_add_eml(&c21_t113, c21_d_sf_marshall, 76U);
  sf_debug_symbol_scope_add_eml(&c21_t60, c21_d_sf_marshall, 77U);
  sf_debug_symbol_scope_add_eml(&c21_t61, c21_d_sf_marshall, 78U);
  sf_debug_symbol_scope_add_eml(&c21_t62, c21_d_sf_marshall, 79U);
  sf_debug_symbol_scope_add_eml(&c21_t63, c21_d_sf_marshall, 80U);
  sf_debug_symbol_scope_add_eml(&c21_t64, c21_d_sf_marshall, 81U);
  sf_debug_symbol_scope_add_eml(&c21_t65, c21_d_sf_marshall, 82U);
  sf_debug_symbol_scope_add_eml(&c21_t69, c21_d_sf_marshall, 83U);
  sf_debug_symbol_scope_add_eml(&c21_t70, c21_d_sf_marshall, 84U);
  sf_debug_symbol_scope_add_eml(&c21_t71, c21_d_sf_marshall, 85U);
  sf_debug_symbol_scope_add_eml(&c21_t72, c21_d_sf_marshall, 86U);
  sf_debug_symbol_scope_add_eml(&c21_t73, c21_d_sf_marshall, 87U);
  sf_debug_symbol_scope_add_eml(&c21_t94, c21_d_sf_marshall, 88U);
  sf_debug_symbol_scope_add_eml(&c21_t74, c21_d_sf_marshall, 89U);
  sf_debug_symbol_scope_add_eml(&c21_t75, c21_d_sf_marshall, 90U);
  sf_debug_symbol_scope_add_eml(&c21_t76, c21_d_sf_marshall, 91U);
  sf_debug_symbol_scope_add_eml(&c21_t77, c21_d_sf_marshall, 92U);
  sf_debug_symbol_scope_add_eml(&c21_t78, c21_d_sf_marshall, 93U);
  sf_debug_symbol_scope_add_eml(&c21_t104, c21_d_sf_marshall, 94U);
  sf_debug_symbol_scope_add_eml(&c21_t79, c21_d_sf_marshall, 95U);
  sf_debug_symbol_scope_add_eml(&c21_t80, c21_d_sf_marshall, 96U);
  sf_debug_symbol_scope_add_eml(&c21_t81, c21_d_sf_marshall, 97U);
  sf_debug_symbol_scope_add_eml(&c21_t82, c21_d_sf_marshall, 98U);
  sf_debug_symbol_scope_add_eml(&c21_t105, c21_d_sf_marshall, 99U);
  sf_debug_symbol_scope_add_eml(&c21_t83, c21_d_sf_marshall, 100U);
  sf_debug_symbol_scope_add_eml(&c21_t84, c21_d_sf_marshall, 101U);
  sf_debug_symbol_scope_add_eml(&c21_t85, c21_d_sf_marshall, 102U);
  sf_debug_symbol_scope_add_eml(&c21_t86, c21_d_sf_marshall, 103U);
  sf_debug_symbol_scope_add_eml(&c21_t87, c21_d_sf_marshall, 104U);
  sf_debug_symbol_scope_add_eml(&c21_t88, c21_d_sf_marshall, 105U);
  sf_debug_symbol_scope_add_eml(&c21_t89, c21_d_sf_marshall, 106U);
  sf_debug_symbol_scope_add_eml(&c21_t90, c21_d_sf_marshall, 107U);
  sf_debug_symbol_scope_add_eml(&c21_t91, c21_d_sf_marshall, 108U);
  sf_debug_symbol_scope_add_eml(&c21_t92, c21_d_sf_marshall, 109U);
  sf_debug_symbol_scope_add_eml(&c21_t93, c21_d_sf_marshall, 110U);
  sf_debug_symbol_scope_add_eml(&c21_t96, c21_d_sf_marshall, 111U);
  sf_debug_symbol_scope_add_eml(&c21_t97, c21_d_sf_marshall, 112U);
  sf_debug_symbol_scope_add_eml(&c21_t98, c21_d_sf_marshall, 113U);
  sf_debug_symbol_scope_add_eml(&c21_t99, c21_d_sf_marshall, 114U);
  sf_debug_symbol_scope_add_eml(&c21_t100, c21_d_sf_marshall, 115U);
  sf_debug_symbol_scope_add_eml(&c21_t101, c21_d_sf_marshall, 116U);
  sf_debug_symbol_scope_add_eml(&c21_t102, c21_d_sf_marshall, 117U);
  sf_debug_symbol_scope_add_eml(&c21_t148, c21_d_sf_marshall, 118U);
  sf_debug_symbol_scope_add_eml(&c21_t103, c21_d_sf_marshall, 119U);
  sf_debug_symbol_scope_add_eml(&c21_t106, c21_d_sf_marshall, 120U);
  sf_debug_symbol_scope_add_eml(&c21_t107, c21_d_sf_marshall, 121U);
  sf_debug_symbol_scope_add_eml(&c21_t108, c21_d_sf_marshall, 122U);
  sf_debug_symbol_scope_add_eml(&c21_t109, c21_d_sf_marshall, 123U);
  sf_debug_symbol_scope_add_eml(&c21_t111, c21_d_sf_marshall, 124U);
  sf_debug_symbol_scope_add_eml(&c21_t110, c21_d_sf_marshall, 125U);
  sf_debug_symbol_scope_add_eml(&c21_t114, c21_d_sf_marshall, 126U);
  sf_debug_symbol_scope_add_eml(&c21_t115, c21_d_sf_marshall, 127U);
  sf_debug_symbol_scope_add_eml(&c21_t116, c21_d_sf_marshall, 128U);
  sf_debug_symbol_scope_add_eml(&c21_t117, c21_d_sf_marshall, 129U);
  sf_debug_symbol_scope_add_eml(&c21_t118, c21_d_sf_marshall, 130U);
  sf_debug_symbol_scope_add_eml(&c21_t119, c21_d_sf_marshall, 131U);
  sf_debug_symbol_scope_add_eml(&c21_t127, c21_d_sf_marshall, 132U);
  sf_debug_symbol_scope_add_eml(&c21_t120, c21_d_sf_marshall, 133U);
  sf_debug_symbol_scope_add_eml(&c21_t121, c21_d_sf_marshall, 134U);
  sf_debug_symbol_scope_add_eml(&c21_t122, c21_d_sf_marshall, 135U);
  sf_debug_symbol_scope_add_eml(&c21_t123, c21_d_sf_marshall, 136U);
  sf_debug_symbol_scope_add_eml(&c21_t124, c21_d_sf_marshall, 137U);
  sf_debug_symbol_scope_add_eml(&c21_t138, c21_d_sf_marshall, 138U);
  sf_debug_symbol_scope_add_eml(&c21_t125, c21_d_sf_marshall, 139U);
  sf_debug_symbol_scope_add_eml(&c21_t126, c21_d_sf_marshall, 140U);
  sf_debug_symbol_scope_add_eml(&c21_t128, c21_d_sf_marshall, 141U);
  sf_debug_symbol_scope_add_eml(&c21_t129, c21_d_sf_marshall, 142U);
  sf_debug_symbol_scope_add_eml(&c21_t139, c21_d_sf_marshall, 143U);
  sf_debug_symbol_scope_add_eml(&c21_t130, c21_d_sf_marshall, 144U);
  sf_debug_symbol_scope_add_eml(&c21_t131, c21_d_sf_marshall, 145U);
  sf_debug_symbol_scope_add_eml(&c21_t132, c21_d_sf_marshall, 146U);
  sf_debug_symbol_scope_add_eml(&c21_t133, c21_d_sf_marshall, 147U);
  sf_debug_symbol_scope_add_eml(&c21_t134, c21_d_sf_marshall, 148U);
  sf_debug_symbol_scope_add_eml(&c21_t135, c21_d_sf_marshall, 149U);
  sf_debug_symbol_scope_add_eml(&c21_t136, c21_d_sf_marshall, 150U);
  sf_debug_symbol_scope_add_eml(&c21_t151, c21_d_sf_marshall, 151U);
  sf_debug_symbol_scope_add_eml(&c21_t152, c21_d_sf_marshall, 152U);
  sf_debug_symbol_scope_add_eml(&c21_t137, c21_d_sf_marshall, 153U);
  sf_debug_symbol_scope_add_eml(&c21_t140, c21_d_sf_marshall, 154U);
  sf_debug_symbol_scope_add_eml(&c21_t142, c21_d_sf_marshall, 155U);
  sf_debug_symbol_scope_add_eml(&c21_t141, c21_d_sf_marshall, 156U);
  sf_debug_symbol_scope_add_eml(&c21_t143, c21_d_sf_marshall, 157U);
  sf_debug_symbol_scope_add_eml(&c21_t144, c21_d_sf_marshall, 158U);
  sf_debug_symbol_scope_add_eml(&c21_t145, c21_d_sf_marshall, 159U);
  sf_debug_symbol_scope_add_eml(&c21_t146, c21_d_sf_marshall, 160U);
  sf_debug_symbol_scope_add_eml(&c21_t149, c21_d_sf_marshall, 161U);
  sf_debug_symbol_scope_add_eml(&c21_t147, c21_d_sf_marshall, 162U);
  sf_debug_symbol_scope_add_eml(&c21_t150, c21_d_sf_marshall, 163U);
  sf_debug_symbol_scope_add_eml(&c21_t153, c21_d_sf_marshall, 164U);
  sf_debug_symbol_scope_add_eml(&c21_t154, c21_d_sf_marshall, 165U);
  sf_debug_symbol_scope_add_eml(&c21_t155, c21_d_sf_marshall, 166U);
  sf_debug_symbol_scope_add_eml(&c21_t156, c21_d_sf_marshall, 167U);
  sf_debug_symbol_scope_add_eml(&c21_t157, c21_d_sf_marshall, 168U);
  sf_debug_symbol_scope_add_eml(&c21_t158, c21_d_sf_marshall, 169U);
  sf_debug_symbol_scope_add_eml(&c21_t159, c21_d_sf_marshall, 170U);
  sf_debug_symbol_scope_add_eml(&c21_nargin, c21_d_sf_marshall, 171U);
  sf_debug_symbol_scope_add_eml(&c21_nargout, c21_d_sf_marshall, 172U);
  sf_debug_symbol_scope_add_eml(c21_in1, c21_e_sf_marshall, 173U);
  sf_debug_symbol_scope_add_eml(c21_in2, c21_g_sf_marshall, 174U);
  sf_debug_symbol_scope_add_eml(c21_in3, c21_b_sf_marshall, 175U);
  sf_debug_symbol_scope_add_eml(c21_body_Jacobian_d6_, c21_f_sf_marshall, 176U);
  CV_SCRIPT_FCN(5, 0);

  /* BODY_JACOBIAN_D6 */
  /*     BODY_JACOBIAN_D6_ = BODY_JACOBIAN_D6(IN1,IN2,IN3) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 15:39:31 */
  _SFD_SCRIPT_CALL(5, 8);
  c21_A2 = c21_in2[1];
  _SFD_SCRIPT_CALL(5, 9);
  c21_A3 = c21_in2[2];
  _SFD_SCRIPT_CALL(5, 10);
  c21_A4 = c21_in2[3];
  _SFD_SCRIPT_CALL(5, 11);
  c21_A5 = c21_in2[4];
  _SFD_SCRIPT_CALL(5, 12);
  c21_A6 = c21_in2[5];
  _SFD_SCRIPT_CALL(5, 13);
  c21_Cx6 = c21_in3[5];
  _SFD_SCRIPT_CALL(5, 14);
  c21_Cy6 = c21_in3[11];
  _SFD_SCRIPT_CALL(5, 15);
  c21_Cz6 = c21_in3[17];
  _SFD_SCRIPT_CALL(5, 16);
  c21_L1 = c21_in1[0];
  _SFD_SCRIPT_CALL(5, 17);
  c21_L2 = c21_in1[1];
  _SFD_SCRIPT_CALL(5, 18);
  c21_L3 = c21_in1[2];
  _SFD_SCRIPT_CALL(5, 19);
  c21_L4 = c21_in1[3];
  _SFD_SCRIPT_CALL(5, 20);
  c21_L5 = c21_in1[4];
  _SFD_SCRIPT_CALL(5, 21);
  c21_x = c21_A5;
  c21_t2 = c21_x;
  c21_b_x = c21_t2;
  c21_t2 = c21_b_x;
  c21_t2 = muDoubleScalarCos(c21_t2);
  _SFD_SCRIPT_CALL(5, 22);
  c21_c_x = c21_A5;
  c21_t3 = c21_c_x;
  c21_d_x = c21_t3;
  c21_t3 = c21_d_x;
  c21_t3 = muDoubleScalarSin(c21_t3);
  _SFD_SCRIPT_CALL(5, 23);
  c21_t4 = (c21_L1 + c21_L3) + c21_L4;
  _SFD_SCRIPT_CALL(5, 24);
  c21_t5 = c21_t2 - 1.0;
  _SFD_SCRIPT_CALL(5, 25);
  c21_t6 = c21_L2 + c21_L5;
  _SFD_SCRIPT_CALL(5, 26);
  c21_e_x = c21_A6;
  c21_t7 = c21_e_x;
  c21_f_x = c21_t7;
  c21_t7 = c21_f_x;
  c21_t7 = muDoubleScalarCos(c21_t7);
  _SFD_SCRIPT_CALL(5, 27);
  c21_g_x = c21_A4;
  c21_t8 = c21_g_x;
  c21_h_x = c21_t8;
  c21_t8 = c21_h_x;
  c21_t8 = muDoubleScalarSin(c21_t8);
  _SFD_SCRIPT_CALL(5, 28);
  c21_i_x = c21_A6;
  c21_t9 = c21_i_x;
  c21_j_x = c21_t9;
  c21_t9 = c21_j_x;
  c21_t9 = muDoubleScalarSin(c21_t9);
  _SFD_SCRIPT_CALL(5, 29);
  c21_t10 = c21_Cy6 * c21_t7;
  _SFD_SCRIPT_CALL(5, 30);
  c21_t11 = c21_t4 * c21_t9;
  _SFD_SCRIPT_CALL(5, 31);
  c21_t27 = c21_Cz6 * c21_t9;
  _SFD_SCRIPT_CALL(5, 32);
  c21_t12 = (c21_t10 + c21_t11) - c21_t27;
  _SFD_SCRIPT_CALL(5, 33);
  c21_k_x = c21_A4;
  c21_t13 = c21_k_x;
  c21_l_x = c21_t13;
  c21_t13 = c21_l_x;
  c21_t13 = muDoubleScalarCos(c21_t13);
  _SFD_SCRIPT_CALL(5, 34);
  c21_m_x = c21_A3;
  c21_t14 = c21_m_x;
  c21_n_x = c21_t14;
  c21_t14 = c21_n_x;
  c21_t14 = muDoubleScalarSin(c21_t14);
  _SFD_SCRIPT_CALL(5, 35);
  c21_o_x = c21_A3;
  c21_t15 = c21_o_x;
  c21_p_x = c21_t15;
  c21_t15 = c21_p_x;
  c21_t15 = muDoubleScalarCos(c21_t15);
  _SFD_SCRIPT_CALL(5, 36);
  c21_t16 = c21_t3 * c21_t6;
  _SFD_SCRIPT_CALL(5, 37);
  c21_t55 = c21_t4 * c21_t5;
  _SFD_SCRIPT_CALL(5, 38);
  c21_t17 = c21_t16 - c21_t55;
  _SFD_SCRIPT_CALL(5, 39);
  c21_t18 = c21_t17 * c21_t2;
  _SFD_SCRIPT_CALL(5, 40);
  c21_t19 = c21_t3 * c21_t4;
  _SFD_SCRIPT_CALL(5, 41);
  c21_t20 = c21_t5 * c21_t6;
  _SFD_SCRIPT_CALL(5, 42);
  c21_t21 = c21_t19 + c21_t20;
  _SFD_SCRIPT_CALL(5, 43);
  c21_t22 = c21_Cz6 * c21_t7;
  _SFD_SCRIPT_CALL(5, 44);
  c21_t23 = c21_Cy6 * c21_t9;
  _SFD_SCRIPT_CALL(5, 45);
  c21_t24 = c21_t7 - 1.0;
  _SFD_SCRIPT_CALL(5, 46);
  c21_t56 = c21_t21 * c21_t3;
  _SFD_SCRIPT_CALL(5, 47);
  c21_t57 = c21_t24 * c21_t4;
  _SFD_SCRIPT_CALL(5, 48);
  c21_t25 = (((c21_t18 + c21_t22) + c21_t23) - c21_t56) - c21_t57;
  _SFD_SCRIPT_CALL(5, 49);
  c21_t26 = c21_t2 * c21_t4 * c21_t8;
  _SFD_SCRIPT_CALL(5, 50);
  c21_t28 = c21_t12 * c21_t13 * c21_t2;
  _SFD_SCRIPT_CALL(5, 51);
  c21_t29 = (c21_t26 + c21_t28) - c21_t25 * c21_t8;
  _SFD_SCRIPT_CALL(5, 52);
  c21_t30 = c21_t13 - 1.0;
  _SFD_SCRIPT_CALL(5, 53);
  c21_t31 = c21_t13 * c21_t4 * c21_t8;
  _SFD_SCRIPT_CALL(5, 54);
  c21_t67 = c21_t30 * c21_t4 * c21_t8;
  _SFD_SCRIPT_CALL(5, 55);
  c21_t68 = c21_t31 - c21_t67;
  _SFD_SCRIPT_CALL(5, 56);
  c21_t32 = c21_t3 * c21_t68;
  _SFD_SCRIPT_CALL(5, 57);
  c21_t66 = c21_t12 * c21_t3;
  _SFD_SCRIPT_CALL(5, 58);
  c21_t33 = c21_t32 + c21_t66;
  _SFD_SCRIPT_CALL(5, 59);
  c21_t34 = c21_t15 - 1.0;
  _SFD_SCRIPT_CALL(5, 60);
  c21_t35 = c21_L1 + c21_L3;
  _SFD_SCRIPT_CALL(5, 61);
  c21_q_x = c21_A2;
  c21_t36 = c21_q_x;
  c21_r_x = c21_t36;
  c21_t36 = c21_r_x;
  c21_t36 = muDoubleScalarSin(c21_t36);
  _SFD_SCRIPT_CALL(5, 62);
  c21_s_x = c21_A2;
  c21_t37 = c21_s_x;
  c21_t_x = c21_t37;
  c21_t37 = c21_t_x;
  c21_t37 = muDoubleScalarCos(c21_t37);
  _SFD_SCRIPT_CALL(5, 63);
  c21_t38 = c21_t14 * c21_t2;
  _SFD_SCRIPT_CALL(5, 64);
  c21_t39 = c21_t13 * c21_t15 * c21_t3;
  _SFD_SCRIPT_CALL(5, 65);
  c21_t40 = c21_t38 + c21_t39;
  _SFD_SCRIPT_CALL(5, 66);
  c21_t41 = c21_t15 * c21_t2;
  _SFD_SCRIPT_CALL(5, 67);
  c21_t49 = c21_t13 * c21_t14 * c21_t3;
  _SFD_SCRIPT_CALL(5, 68);
  c21_t42 = c21_t41 - c21_t49;
  _SFD_SCRIPT_CALL(5, 69);
  c21_t43 = c21_L1 * c21_t36;
  _SFD_SCRIPT_CALL(5, 70);
  c21_t44 = c21_t37 - 1.0;
  _SFD_SCRIPT_CALL(5, 71);
  c21_t45 = c21_L2 * c21_t44;
  _SFD_SCRIPT_CALL(5, 72);
  c21_t46 = c21_t43 + c21_t45;
  _SFD_SCRIPT_CALL(5, 73);
  c21_t47 = c21_L1 * c21_t44;
  _SFD_SCRIPT_CALL(5, 74);
  c21_t95 = c21_L2 * c21_t36;
  _SFD_SCRIPT_CALL(5, 75);
  c21_t48 = c21_t47 - c21_t95;
  _SFD_SCRIPT_CALL(5, 76);
  c21_t50 = c21_L2 * c21_t14;
  _SFD_SCRIPT_CALL(5, 77);
  c21_t58 = c21_t34 * c21_t35;
  _SFD_SCRIPT_CALL(5, 78);
  c21_t51 = c21_t50 - c21_t58;
  _SFD_SCRIPT_CALL(5, 79);
  c21_t52 = c21_t14 * c21_t35;
  _SFD_SCRIPT_CALL(5, 80);
  c21_t53 = c21_L2 * c21_t34;
  _SFD_SCRIPT_CALL(5, 81);
  c21_t54 = c21_t52 + c21_t53;
  _SFD_SCRIPT_CALL(5, 82);
  c21_t59 = c21_t15 * c21_t51;
  _SFD_SCRIPT_CALL(5, 83);
  c21_t112 = c21_t14 * c21_t54;
  _SFD_SCRIPT_CALL(5, 84);
  c21_t113 = c21_t112 - c21_t59;
  _SFD_SCRIPT_CALL(5, 85);
  c21_t60 = (-c21_t113) * c21_t2;
  _SFD_SCRIPT_CALL(5, 86);
  c21_t61 = c21_t13 * c21_t25;
  _SFD_SCRIPT_CALL(5, 87);
  c21_t62 = c21_t12 * c21_t2 * c21_t8;
  _SFD_SCRIPT_CALL(5, 88);
  c21_t63 = c21_t15 * c21_t54;
  _SFD_SCRIPT_CALL(5, 89);
  c21_t64 = c21_t14 * c21_t51;
  _SFD_SCRIPT_CALL(5, 90);
  c21_t65 = c21_t63 + c21_t64;
  _SFD_SCRIPT_CALL(5, 91);
  c21_t69 = c21_power(chartInstance, c21_t9, 2.0);
  _SFD_SCRIPT_CALL(5, 92);
  c21_t70 = c21_t4 * c21_t69;
  _SFD_SCRIPT_CALL(5, 93);
  c21_t71 = c21_t24 * c21_t4 * c21_t7;
  _SFD_SCRIPT_CALL(5, 94);
  c21_t72 = ((-c21_Cz6) + c21_t70) + c21_t71;
  _SFD_SCRIPT_CALL(5, 95);
  c21_t73 = c21_t13 * c21_t7;
  _SFD_SCRIPT_CALL(5, 96);
  c21_t94 = c21_t2 * c21_t8 * c21_t9;
  _SFD_SCRIPT_CALL(5, 97);
  c21_t74 = c21_t73 - c21_t94;
  _SFD_SCRIPT_CALL(5, 98);
  c21_t75 = c21_Cx6 * c21_t9;
  _SFD_SCRIPT_CALL(5, 99);
  c21_t76 = c21_t2 * c21_t21;
  _SFD_SCRIPT_CALL(5, 100);
  c21_t77 = c21_t17 * c21_t3;
  _SFD_SCRIPT_CALL(5, 101);
  c21_t78 = c21_t76 + c21_t77;
  _SFD_SCRIPT_CALL(5, 102);
  c21_t104 = c21_t78 * c21_t9;
  _SFD_SCRIPT_CALL(5, 103);
  c21_t79 = (-c21_t104) + c21_t75;
  _SFD_SCRIPT_CALL(5, 104);
  c21_t80 = c21_t79 * c21_t8;
  _SFD_SCRIPT_CALL(5, 105);
  c21_t81 = c21_t21 * c21_t7;
  _SFD_SCRIPT_CALL(5, 106);
  c21_t82 = c21_t3 * c21_t72;
  _SFD_SCRIPT_CALL(5, 107);
  c21_t105 = c21_Cx6 * c21_t2 * c21_t7;
  _SFD_SCRIPT_CALL(5, 108);
  c21_t83 = ((-c21_t105) + c21_t81) + c21_t82;
  _SFD_SCRIPT_CALL(5, 109);
  c21_t84 = c21_t13 * c21_t83;
  _SFD_SCRIPT_CALL(5, 110);
  c21_t85 = c21_t3 * c21_t4 * c21_t8 * c21_t9;
  _SFD_SCRIPT_CALL(5, 111);
  c21_t86 = (c21_t80 + c21_t84) + c21_t85;
  _SFD_SCRIPT_CALL(5, 112);
  c21_t87 = c21_t2 * c21_t72;
  _SFD_SCRIPT_CALL(5, 113);
  c21_t88 = c21_power(chartInstance, c21_t8, 2.0);
  _SFD_SCRIPT_CALL(5, 114);
  c21_t89 = c21_t4 * c21_t88;
  _SFD_SCRIPT_CALL(5, 115);
  c21_t90 = c21_t13 * c21_t30 * c21_t4;
  _SFD_SCRIPT_CALL(5, 116);
  c21_t91 = c21_t89 + c21_t90;
  _SFD_SCRIPT_CALL(5, 117);
  c21_t92 = c21_t7 * c21_t91;
  _SFD_SCRIPT_CALL(5, 118);
  c21_t93 = c21_Cx6 * c21_t3 * c21_t7;
  _SFD_SCRIPT_CALL(5, 119);
  c21_t96 = c21_t37 * c21_t48;
  _SFD_SCRIPT_CALL(5, 120);
  c21_t97 = c21_t36 * c21_t46;
  _SFD_SCRIPT_CALL(5, 121);
  c21_t98 = c21_t96 + c21_t97;
  _SFD_SCRIPT_CALL(5, 122);
  c21_t99 = c21_t7 * c21_t8;
  _SFD_SCRIPT_CALL(5, 123);
  c21_t100 = c21_t13 * c21_t2 * c21_t9;
  _SFD_SCRIPT_CALL(5, 124);
  c21_t101 = c21_t100 + c21_t99;
  _SFD_SCRIPT_CALL(5, 125);
  c21_t102 = c21_t37 * c21_t46;
  _SFD_SCRIPT_CALL(5, 126);
  c21_t148 = c21_t36 * c21_t48;
  _SFD_SCRIPT_CALL(5, 127);
  c21_t103 = c21_t102 - c21_t148;
  _SFD_SCRIPT_CALL(5, 128);
  c21_t106 = c21_t101 * c21_t14;
  _SFD_SCRIPT_CALL(5, 129);
  c21_t107 = c21_t15 * c21_t3 * c21_t9;
  _SFD_SCRIPT_CALL(5, 130);
  c21_t108 = c21_t106 + c21_t107;
  _SFD_SCRIPT_CALL(5, 131);
  c21_t109 = c21_t101 * c21_t15;
  _SFD_SCRIPT_CALL(5, 132);
  c21_t111 = c21_t14 * c21_t3 * c21_t9;
  _SFD_SCRIPT_CALL(5, 133);
  c21_t110 = c21_t109 - c21_t111;
  _SFD_SCRIPT_CALL(5, 134);
  c21_t114 = c21_t14 * (c21_t50 - c21_t58);
  _SFD_SCRIPT_CALL(5, 135);
  c21_t115 = c21_t114 + c21_t63;
  _SFD_SCRIPT_CALL(5, 136);
  c21_t116 = c21_t101 * c21_t115;
  _SFD_SCRIPT_CALL(5, 137);
  c21_t117 = c21_t8 * c21_t83;
  _SFD_SCRIPT_CALL(5, 138);
  c21_t118 = c21_t2 * c21_t9 * (c21_t31 - c21_t67);
  _SFD_SCRIPT_CALL(5, 139);
  c21_t119 = c21_t4 * c21_t7 * c21_t9;
  _SFD_SCRIPT_CALL(5, 140);
  c21_t127 = c21_t24 * c21_t4 * c21_t9;
  _SFD_SCRIPT_CALL(5, 141);
  c21_t120 = (c21_Cy6 + c21_t119) - c21_t127;
  _SFD_SCRIPT_CALL(5, 142);
  c21_t121 = c21_t13 * c21_t9;
  _SFD_SCRIPT_CALL(5, 143);
  c21_t122 = c21_t2 * c21_t7 * c21_t8;
  _SFD_SCRIPT_CALL(5, 144);
  c21_t123 = c21_t121 + c21_t122;
  _SFD_SCRIPT_CALL(5, 145);
  c21_t124 = c21_Cx6 * c21_t7;
  _SFD_SCRIPT_CALL(5, 146);
  c21_t138 = c21_t7 * c21_t78;
  _SFD_SCRIPT_CALL(5, 147);
  c21_t125 = c21_t124 - c21_t138;
  _SFD_SCRIPT_CALL(5, 148);
  c21_t126 = c21_t125 * c21_t8;
  _SFD_SCRIPT_CALL(5, 149);
  c21_t128 = c21_t120 * c21_t3;
  _SFD_SCRIPT_CALL(5, 150);
  c21_t129 = c21_Cx6 * c21_t2 * c21_t9;
  _SFD_SCRIPT_CALL(5, 151);
  c21_t139 = c21_t21 * c21_t9;
  _SFD_SCRIPT_CALL(5, 152);
  c21_t130 = (c21_t128 + c21_t129) - c21_t139;
  _SFD_SCRIPT_CALL(5, 153);
  c21_t131 = c21_t13 * c21_t130;
  _SFD_SCRIPT_CALL(5, 154);
  c21_t132 = c21_t3 * c21_t4 * c21_t7 * c21_t8;
  _SFD_SCRIPT_CALL(5, 155);
  c21_t133 = (c21_t126 + c21_t131) + c21_t132;
  _SFD_SCRIPT_CALL(5, 156);
  c21_t134 = c21_t17 * c21_t9;
  _SFD_SCRIPT_CALL(5, 157);
  c21_t135 = c21_t120 * c21_t2;
  _SFD_SCRIPT_CALL(5, 158);
  c21_t136 = c21_t2 * c21_t68 * c21_t7;
  _SFD_SCRIPT_CALL(5, 159);
  c21_t151 = c21_t9 * c21_t91;
  _SFD_SCRIPT_CALL(5, 160);
  c21_t152 = c21_Cx6 * c21_t3 * c21_t9;
  _SFD_SCRIPT_CALL(5, 161);
  c21_t137 = (((c21_t134 + c21_t135) + c21_t136) - c21_t151) - c21_t152;
  _SFD_SCRIPT_CALL(5, 162);
  c21_t140 = c21_t8 * c21_t9;
  _SFD_SCRIPT_CALL(5, 163);
  c21_t142 = c21_t13 * c21_t2 * c21_t7;
  _SFD_SCRIPT_CALL(5, 164);
  c21_t141 = c21_t140 - c21_t142;
  _SFD_SCRIPT_CALL(5, 165);
  c21_t143 = c21_t141 * c21_t15;
  _SFD_SCRIPT_CALL(5, 166);
  c21_t144 = c21_t14 * c21_t3 * c21_t7;
  _SFD_SCRIPT_CALL(5, 167);
  c21_t145 = c21_t143 + c21_t144;
  _SFD_SCRIPT_CALL(5, 168);
  c21_t146 = c21_t14 * c21_t141;
  _SFD_SCRIPT_CALL(5, 169);
  c21_t149 = c21_t15 * c21_t3 * c21_t7;
  _SFD_SCRIPT_CALL(5, 170);
  c21_t147 = c21_t146 - c21_t149;
  _SFD_SCRIPT_CALL(5, 171);
  c21_t150 = c21_t130 * c21_t8;
  _SFD_SCRIPT_CALL(5, 172);
  c21_t153 = c21_t37 * c21_t40;
  _SFD_SCRIPT_CALL(5, 173);
  c21_t154 = c21_t36 * c21_t42;
  _SFD_SCRIPT_CALL(5, 174);
  c21_t155 = c21_t3 * c21_t8;
  _SFD_SCRIPT_CALL(5, 175);
  c21_t156 = c21_t108 * c21_t36;
  _SFD_SCRIPT_CALL(5, 176);
  c21_t157 = c21_t147 * c21_t36;
  _SFD_SCRIPT_CALL(5, 177);
  c21_t158 = c21_t157 - c21_t145 * c21_t37;
  _SFD_SCRIPT_CALL(5, 178);
  c21_t159 = (-c21_t121) - c21_t122;
  _SFD_SCRIPT_CALL(5, 179);
  c21_u_x[0] = (c21_t36 * ((c21_t14 * c21_t29 + c21_t15 * c21_t33) + c21_t3 *
    c21_t51 * c21_t8) - c21_t37 * ((c21_t15 * c21_t29 -
    c21_t14 * c21_t33) + c21_t3 * c21_t54 * c21_t8)) - c21_t3 * c21_t46 * c21_t8;
  c21_u_x[1] = (c21_t36 * ((c21_t14 * c21_t86 + c21_t51 * c21_t74) - c21_t15 *
                 ((((c21_t118 + c21_t87) + c21_t92) + c21_t93) - c21_t17
                  * c21_t7)) - c21_t46 * c21_t74) - c21_t37 * ((c21_t15 *
    c21_t86 + c21_t54 * c21_t74) + c21_t14 * ((((c21_t87 + c21_t92) + c21_t93)
    - c21_t17 * c21_t7) + c21_t2 * c21_t68 * c21_t9));
  c21_u_x[2] = ((-c21_t36) * (((-c21_t133) * c21_t14 + c21_t137 * c21_t15) +
    c21_t123 * c21_t51) - c21_t37 * ((c21_t137 * c21_t14 +
    c21_t133 * c21_t15) - c21_t123 * c21_t54)) + c21_t123 * c21_t46;
  c21_u_x[3] = (-c21_t153) - c21_t154;
  c21_u_x[4] = (-c21_t156) + c21_t110 * c21_t37;
  c21_u_x[5] = c21_t158;
  c21_u_x[6] = (((((((c21_t60 + c21_t61) + c21_t62) - c21_t103 * c21_t40) -
                   c21_t42 * c21_t98) + c21_L1 * (c21_t36 * c21_t40 - c21_t37
    * c21_t42)) - c21_L2 * (c21_t153 + c21_t154)) - c21_t2 * c21_t30 * c21_t4) -
    c21_t13 * c21_t3 * c21_t65;
  c21_u_x[7] = (((((((c21_t116 + c21_t117) + c21_t103 * c21_t110) - c21_t13 *
                    c21_t79) - c21_t108 * c21_t98) - c21_L1 * (c21_t110 *
    c21_t36 + c21_t108 * c21_t37)) - c21_L2 * (c21_t156 - c21_t110 * c21_t37)) -
                c21_t113 * c21_t3 * c21_t9) - c21_t3 * c21_t30 * c21_t4
    * c21_t9;
  c21_u_x[8] = (((((((c21_t150 + c21_t147 * (c21_t96 + c21_t97)) + c21_L2 *
                     c21_t158) - c21_t103 * c21_t145) - c21_t125 * c21_t13) -
                  c21_t115 * c21_t141) + c21_L1 * (c21_t145 * c21_t36 + c21_t147
    * c21_t37)) - c21_t113 * c21_t3 * c21_t7) - c21_t3 * c21_t30 * c21_t4
    * c21_t7;
  c21_u_x[9] = c21_t155;
  c21_u_x[10] = c21_t74;
  c21_u_x[11] = c21_t159;
  c21_u_x[12] = (((((c21_t60 + c21_t61) + c21_t62) - c21_L2 * c21_t40) - c21_t35
                  * c21_t42) - c21_t2 * c21_t30 * c21_t4) - c21_t13 *
    c21_t3 * c21_t65;
  c21_u_x[13] = (((((c21_t116 + c21_t117) + c21_L2 * c21_t110) - c21_t108 *
                   c21_t35) - c21_t13 * c21_t79) - c21_t113 * c21_t3 * c21_t9
                 ) - c21_t3 * c21_t30 * c21_t4 * c21_t9;
  c21_u_x[14] = (((((c21_t150 - c21_L2 * c21_t145) - c21_t125 * c21_t13) -
                   c21_t115 * c21_t141) + c21_t147 * c21_t35) - c21_t113 *
                 c21_t3 * c21_t7) - c21_t3 * c21_t30 * c21_t4 * c21_t7;
  c21_u_x[15] = c21_t155;
  c21_u_x[16] = c21_t74;
  c21_u_x[17] = c21_t159;
  c21_u_x[18] = ((-c21_t32) - c21_t66) + c21_t3 * c21_t4 * c21_t8;
  c21_u_x[19] = ((((c21_t118 + c21_t87) + c21_t92) + c21_t93) - c21_t17 * c21_t7)
    + c21_t4 * c21_t74;
  c21_u_x[20] = ((((c21_t134 + c21_t135) - c21_t151) - c21_t152) - c21_t123 *
                 c21_t4) + c21_t2 * c21_t7 * (c21_t31 - c21_t67);
  c21_u_x[21] = c21_t2;
  c21_u_x[22] = c21_t3 * c21_t9;
  c21_u_x[23] = c21_t3 * c21_t7;
  c21_u_x[24] = ((((((-c21_t16) + c21_t18) + c21_t22) + c21_t23) - c21_t56) -
                 c21_t57) - c21_t2 * c21_t4;
  c21_u_x[25] = ((c21_t104 - c21_t75) - c21_t3 * c21_t4 * c21_t9) + c21_t2 *
    c21_t6 * c21_t9;
  c21_u_x[26] = (((-c21_t124) + c21_t138) - c21_t3 * c21_t4 * c21_t7) + c21_t2 *
    c21_t6 * c21_t7;
  c21_u_x[27] = 0.0;
  c21_u_x[28] = c21_t7;
  c21_u_x[29] = -c21_t9;
  c21_u_x[30] = 0.0;
  c21_u_x[31] = (((-c21_Cz6) + c21_t70) + c21_t71) + c21_t4 * c21_t7;
  c21_u_x[32] = ((c21_Cy6 - c21_t11) + c21_t119) - c21_t127;
  c21_u_x[33] = 1.0;
  c21_u_x[34] = 0.0;
  c21_u_x[35] = 0.0;
  for (c21_k = 1; c21_k < 37; c21_k = c21_k + 1) {
    c21_b_k = c21_k;
    c21_body_Jacobian_d6_[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c21_b_k), 1, 36, 1, 0) - 1] = c21_u_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c21_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(5, -179);
  sf_debug_symbol_scope_pop();
}

static const mxArray *c21_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  int32_T c21_i103;
  real_T c21_b_u[36];
  int32_T c21_i104;
  real_T c21_c_u[36];
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  for (c21_i103 = 0; c21_i103 < 36; c21_i103 = c21_i103 + 1) {
    c21_b_u[c21_i103] = (*((real_T (*)[36])c21_u))[c21_i103];
  }

  for (c21_i104 = 0; c21_i104 < 36; c21_i104 = c21_i104 + 1) {
    c21_c_u[c21_i104] = c21_b_u[c21_i104];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_c_u, 0, 0U, 1U, 0U, 1, 36));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static const mxArray *c21_b_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  int32_T c21_i105;
  real_T c21_b_u[18];
  int32_T c21_i106;
  real_T c21_c_u[18];
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  for (c21_i105 = 0; c21_i105 < 18; c21_i105 = c21_i105 + 1) {
    c21_b_u[c21_i105] = (*((real_T (*)[18])c21_u))[c21_i105];
  }

  for (c21_i106 = 0; c21_i106 < 18; c21_i106 = c21_i106 + 1) {
    c21_c_u[c21_i106] = c21_b_u[c21_i106];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_c_u, 0, 0U, 1U, 0U, 2, 1, 18));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static const mxArray *c21_c_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  int32_T c21_i107;
  real_T c21_b_u[6];
  int32_T c21_i108;
  real_T c21_c_u[6];
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  for (c21_i107 = 0; c21_i107 < 6; c21_i107 = c21_i107 + 1) {
    c21_b_u[c21_i107] = (*((real_T (*)[6])c21_u))[c21_i107];
  }

  for (c21_i108 = 0; c21_i108 < 6; c21_i108 = c21_i108 + 1) {
    c21_c_u[c21_i108] = c21_b_u[c21_i108];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static const mxArray *c21_d_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  real_T c21_b_u;
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  c21_b_u = *((real_T *)c21_u);
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static const mxArray *c21_e_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  int32_T c21_i109;
  real_T c21_b_u[9];
  int32_T c21_i110;
  real_T c21_c_u[9];
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  for (c21_i109 = 0; c21_i109 < 9; c21_i109 = c21_i109 + 1) {
    c21_b_u[c21_i109] = (*((real_T (*)[9])c21_u))[c21_i109];
  }

  for (c21_i110 = 0; c21_i110 < 9; c21_i110 = c21_i110 + 1) {
    c21_c_u[c21_i110] = c21_b_u[c21_i110];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static const mxArray *c21_f_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  int32_T c21_i111;
  int32_T c21_i112;
  int32_T c21_i113;
  real_T c21_b_u[36];
  int32_T c21_i114;
  int32_T c21_i115;
  int32_T c21_i116;
  real_T c21_c_u[36];
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  c21_i111 = 0;
  for (c21_i112 = 0; c21_i112 < 6; c21_i112 = c21_i112 + 1) {
    for (c21_i113 = 0; c21_i113 < 6; c21_i113 = c21_i113 + 1) {
      c21_b_u[c21_i113 + c21_i111] = (*((real_T (*)[36])c21_u))[c21_i113 +
        c21_i111];
    }

    c21_i111 = c21_i111 + 6;
  }

  c21_i114 = 0;
  for (c21_i115 = 0; c21_i115 < 6; c21_i115 = c21_i115 + 1) {
    for (c21_i116 = 0; c21_i116 < 6; c21_i116 = c21_i116 + 1) {
      c21_c_u[c21_i116 + c21_i114] = c21_b_u[c21_i116 + c21_i114];
    }

    c21_i114 = c21_i114 + 6;
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_c_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static const mxArray *c21_g_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  int32_T c21_i117;
  real_T c21_b_u[6];
  int32_T c21_i118;
  real_T c21_c_u[6];
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  for (c21_i117 = 0; c21_i117 < 6; c21_i117 = c21_i117 + 1) {
    c21_b_u[c21_i117] = (*((real_T (*)[6])c21_u))[c21_i117];
  }

  for (c21_i118 = 0; c21_i118 < 6; c21_i118 = c21_i118 + 1) {
    c21_c_u[c21_i118] = c21_b_u[c21_i118];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

const mxArray *sf_c21_DynJointVerify_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_ResolvedFunctionInfo c21_info[67];
  c21_ResolvedFunctionInfo (*c21_b_info)[67];
  const mxArray *c21_m0 = NULL;
  int32_T c21_i119;
  c21_ResolvedFunctionInfo *c21_r0;
  c21_nameCaptureInfo = NULL;
  c21_info_helper(c21_info);
  c21_b_info = (c21_ResolvedFunctionInfo (*)[67])c21_info;
  (*c21_b_info)[64].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  (*c21_b_info)[64].name = "eml_error";
  (*c21_b_info)[64].dominantType = "char";
  (*c21_b_info)[64].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c21_b_info)[64].fileLength = 315U;
  (*c21_b_info)[64].fileTime1 = 1213905144U;
  (*c21_b_info)[64].fileTime2 = 0U;
  (*c21_b_info)[65].context = "";
  (*c21_b_info)[65].name = "body_Jacobian_d5";
  (*c21_b_info)[65].dominantType = "double";
  (*c21_b_info)[65].resolved =
    "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d5.m";
  (*c21_b_info)[65].fileLength = 3755U;
  (*c21_b_info)[65].fileTime1 = 1408088374U;
  (*c21_b_info)[65].fileTime2 = 0U;
  (*c21_b_info)[66].context = "";
  (*c21_b_info)[66].name = "body_Jacobian_d6";
  (*c21_b_info)[66].dominantType = "double";
  (*c21_b_info)[66].resolved =
    "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d6.m";
  (*c21_b_info)[66].fileLength = 4493U;
  (*c21_b_info)[66].fileTime1 = 1408088372U;
  (*c21_b_info)[66].fileTime2 = 0U;
  sf_mex_assign(&c21_m0, sf_mex_createstruct("nameCaptureInfo", 1, 67));
  for (c21_i119 = 0; c21_i119 < 67; c21_i119 = c21_i119 + 1) {
    c21_r0 = &c21_info[c21_i119];
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->context)), "context"
                    , "nameCaptureInfo", c21_i119);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c21_r0->name)), "name",
                    "nameCaptureInfo", c21_i119);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo",
      c21_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c21_i119);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", c21_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c21_r0->resolved)),
                    "resolved", "nameCaptureInfo", c21_i119);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c21_i119);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c21_i119);
    sf_mex_addfield(c21_m0, sf_mex_create("nameCaptureInfo", &c21_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c21_i119);
  }

  sf_mex_assign(&c21_nameCaptureInfo, c21_m0);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(c21_ResolvedFunctionInfo c21_info[67])
{
  c21_info[0].context = "";
  c21_info[0].name = "zeros";
  c21_info[0].dominantType = "double";
  c21_info[0].resolved = "[B]zeros";
  c21_info[0].fileLength = 0U;
  c21_info[0].fileTime1 = 0U;
  c21_info[0].fileTime2 = 0U;
  c21_info[1].context = "";
  c21_info[1].name = "mrdivide";
  c21_info[1].dominantType = "double";
  c21_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c21_info[1].fileLength = 432U;
  c21_info[1].fileTime1 = 1277726622U;
  c21_info[1].fileTime2 = 0U;
  c21_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c21_info[2].name = "nargin";
  c21_info[2].dominantType = "";
  c21_info[2].resolved = "[B]nargin";
  c21_info[2].fileLength = 0U;
  c21_info[2].fileTime1 = 0U;
  c21_info[2].fileTime2 = 0U;
  c21_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c21_info[3].name = "ge";
  c21_info[3].dominantType = "double";
  c21_info[3].resolved = "[B]ge";
  c21_info[3].fileLength = 0U;
  c21_info[3].fileTime1 = 0U;
  c21_info[3].fileTime2 = 0U;
  c21_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c21_info[4].name = "isscalar";
  c21_info[4].dominantType = "double";
  c21_info[4].resolved = "[B]isscalar";
  c21_info[4].fileLength = 0U;
  c21_info[4].fileTime1 = 0U;
  c21_info[4].fileTime2 = 0U;
  c21_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c21_info[5].name = "rdivide";
  c21_info[5].dominantType = "double";
  c21_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[5].fileLength = 403U;
  c21_info[5].fileTime1 = 1245080820U;
  c21_info[5].fileTime2 = 0U;
  c21_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[6].name = "gt";
  c21_info[6].dominantType = "double";
  c21_info[6].resolved = "[B]gt";
  c21_info[6].fileLength = 0U;
  c21_info[6].fileTime1 = 0U;
  c21_info[6].fileTime2 = 0U;
  c21_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[7].name = "isa";
  c21_info[7].dominantType = "double";
  c21_info[7].resolved = "[B]isa";
  c21_info[7].fileLength = 0U;
  c21_info[7].fileTime1 = 0U;
  c21_info[7].fileTime2 = 0U;
  c21_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c21_info[8].name = "eml_div";
  c21_info[8].dominantType = "double";
  c21_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c21_info[8].fileLength = 4918U;
  c21_info[8].fileTime1 = 1267038210U;
  c21_info[8].fileTime2 = 0U;
  c21_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c21_info[9].name = "isinteger";
  c21_info[9].dominantType = "double";
  c21_info[9].resolved = "[B]isinteger";
  c21_info[9].fileLength = 0U;
  c21_info[9].fileTime1 = 0U;
  c21_info[9].fileTime2 = 0U;
  c21_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m!eml_fldiv";
  c21_info[10].name = "isreal";
  c21_info[10].dominantType = "double";
  c21_info[10].resolved = "[B]isreal";
  c21_info[10].fileLength = 0U;
  c21_info[10].fileTime1 = 0U;
  c21_info[10].fileTime2 = 0U;
  c21_info[11].context = "";
  c21_info[11].name = "ctranspose";
  c21_info[11].dominantType = "double";
  c21_info[11].resolved = "[B]ctranspose";
  c21_info[11].fileLength = 0U;
  c21_info[11].fileTime1 = 0U;
  c21_info[11].fileTime2 = 0U;
  c21_info[12].context = "";
  c21_info[12].name = "body_Jacobian_d1";
  c21_info[12].dominantType = "double";
  c21_info[12].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d1.m";
  c21_info[12].fileLength = 461U;
  c21_info[12].fileTime1 = 1408088376U;
  c21_info[12].fileTime2 = 0U;
  c21_info[13].context = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d1.m";
  c21_info[13].name = "uminus";
  c21_info[13].dominantType = "double";
  c21_info[13].resolved = "[B]uminus";
  c21_info[13].fileLength = 0U;
  c21_info[13].fileTime1 = 0U;
  c21_info[13].fileTime2 = 0U;
  c21_info[14].context = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d1.m";
  c21_info[14].name = "reshape";
  c21_info[14].dominantType = "double";
  c21_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c21_info[14].fileLength = 4857U;
  c21_info[14].fileTime1 = 1242276774U;
  c21_info[14].fileTime2 = 0U;
  c21_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c21_info[15].name = "eml_index_class";
  c21_info[15].dominantType = "";
  c21_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c21_info[15].fileLength = 909U;
  c21_info[15].fileTime1 = 1192445182U;
  c21_info[15].fileTime2 = 0U;
  c21_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c21_info[16].name = "cast";
  c21_info[16].dominantType = "double";
  c21_info[16].resolved = "[B]cast";
  c21_info[16].fileLength = 0U;
  c21_info[16].fileTime1 = 0U;
  c21_info[16].fileTime2 = 0U;
  c21_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c21_info[17].name = "size";
  c21_info[17].dominantType = "double";
  c21_info[17].resolved = "[B]size";
  c21_info[17].fileLength = 0U;
  c21_info[17].fileTime1 = 0U;
  c21_info[17].fileTime2 = 0U;
  c21_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c21_info[18].name = "eq";
  c21_info[18].dominantType = "double";
  c21_info[18].resolved = "[B]eq";
  c21_info[18].fileLength = 0U;
  c21_info[18].fileTime1 = 0U;
  c21_info[18].fileTime2 = 0U;
  c21_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c21_info[19].name = "eml_assert_valid_size_arg";
  c21_info[19].dominantType = "double";
  c21_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c21_info[19].fileLength = 3315U;
  c21_info[19].fileTime1 = 1256367816U;
  c21_info[19].fileTime2 = 0U;
  c21_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c21_info[20].name = "false";
  c21_info[20].dominantType = "";
  c21_info[20].resolved = "[B]false";
  c21_info[20].fileLength = 0U;
  c21_info[20].fileTime1 = 0U;
  c21_info[20].fileTime2 = 0U;
  c21_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isVariableSizing";
  c21_info[21].name = "not";
  c21_info[21].dominantType = "logical";
  c21_info[21].resolved = "[B]not";
  c21_info[21].fileLength = 0U;
  c21_info[21].fileTime1 = 0U;
  c21_info[21].fileTime2 = 0U;
  c21_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c21_info[22].name = "isvector";
  c21_info[22].dominantType = "double";
  c21_info[22].resolved = "[B]isvector";
  c21_info[22].fileLength = 0U;
  c21_info[22].fileTime1 = 0U;
  c21_info[22].fileTime2 = 0U;
  c21_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c21_info[23].name = "ne";
  c21_info[23].dominantType = "double";
  c21_info[23].resolved = "[B]ne";
  c21_info[23].fileLength = 0U;
  c21_info[23].fileTime1 = 0U;
  c21_info[23].fileTime2 = 0U;
  c21_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c21_info[24].name = "isinf";
  c21_info[24].dominantType = "double";
  c21_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c21_info[24].fileLength = 541U;
  c21_info[24].fileTime1 = 1271383988U;
  c21_info[24].fileTime2 = 0U;
  c21_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c21_info[25].name = "true";
  c21_info[25].dominantType = "";
  c21_info[25].resolved = "[B]true";
  c21_info[25].fileLength = 0U;
  c21_info[25].fileTime1 = 0U;
  c21_info[25].fileTime2 = 0U;
  c21_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c21_info[26].name = "le";
  c21_info[26].dominantType = "double";
  c21_info[26].resolved = "[B]le";
  c21_info[26].fileLength = 0U;
  c21_info[26].fileTime1 = 0U;
  c21_info[26].fileTime2 = 0U;
  c21_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c21_info[27].name = "double";
  c21_info[27].dominantType = "double";
  c21_info[27].resolved = "[B]double";
  c21_info[27].fileLength = 0U;
  c21_info[27].fileTime1 = 0U;
  c21_info[27].fileTime2 = 0U;
  c21_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c21_info[28].name = "mtimes";
  c21_info[28].dominantType = "double";
  c21_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[28].fileLength = 3425U;
  c21_info[28].fileTime1 = 1251010272U;
  c21_info[28].fileTime2 = 0U;
  c21_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[29].name = "strcmp";
  c21_info[29].dominantType = "char";
  c21_info[29].resolved = "[B]strcmp";
  c21_info[29].fileLength = 0U;
  c21_info[29].fileTime1 = 0U;
  c21_info[29].fileTime2 = 0U;
  c21_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[30].name = "class";
  c21_info[30].dominantType = "double";
  c21_info[30].resolved = "[B]class";
  c21_info[30].fileLength = 0U;
  c21_info[30].fileTime1 = 0U;
  c21_info[30].fileTime2 = 0U;
  c21_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c21_info[31].name = "intmax";
  c21_info[31].dominantType = "char";
  c21_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[31].fileLength = 1535U;
  c21_info[31].fileTime1 = 1192445128U;
  c21_info[31].fileTime2 = 0U;
  c21_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[32].name = "ischar";
  c21_info[32].dominantType = "char";
  c21_info[32].resolved = "[B]ischar";
  c21_info[32].fileLength = 0U;
  c21_info[32].fileTime1 = 0U;
  c21_info[32].fileTime2 = 0U;
  c21_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c21_info[33].name = "int32";
  c21_info[33].dominantType = "double";
  c21_info[33].resolved = "[B]int32";
  c21_info[33].fileLength = 0U;
  c21_info[33].fileTime1 = 0U;
  c21_info[33].fileTime2 = 0U;
  c21_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c21_info[34].name = "eml_scalar_eg";
  c21_info[34].dominantType = "double";
  c21_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[34].fileLength = 3068U;
  c21_info[34].fileTime1 = 1240240410U;
  c21_info[34].fileTime2 = 0U;
  c21_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c21_info[35].name = "isstruct";
  c21_info[35].dominantType = "double";
  c21_info[35].resolved = "[B]isstruct";
  c21_info[35].fileLength = 0U;
  c21_info[35].fileTime1 = 0U;
  c21_info[35].fileTime2 = 0U;
  c21_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c21_info[36].name = "ones";
  c21_info[36].dominantType = "char";
  c21_info[36].resolved = "[B]ones";
  c21_info[36].fileLength = 0U;
  c21_info[36].fileTime1 = 0U;
  c21_info[36].fileTime2 = 0U;
  c21_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[37].name = "ndims";
  c21_info[37].dominantType = "double";
  c21_info[37].resolved = "[B]ndims";
  c21_info[37].fileLength = 0U;
  c21_info[37].fileTime1 = 0U;
  c21_info[37].fileTime2 = 0U;
  c21_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c21_info[38].name = "plus";
  c21_info[38].dominantType = "double";
  c21_info[38].resolved = "[B]plus";
  c21_info[38].fileLength = 0U;
  c21_info[38].fileTime1 = 0U;
  c21_info[38].fileTime2 = 0U;
  c21_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[39].name = "isempty";
  c21_info[39].dominantType = "double";
  c21_info[39].resolved = "[B]isempty";
  c21_info[39].fileLength = 0U;
  c21_info[39].fileTime1 = 0U;
  c21_info[39].fileTime2 = 0U;
  c21_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c21_info[40].name = "eml_xgemm";
  c21_info[40].dominantType = "int32";
  c21_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c21_info[40].fileLength = 3184U;
  c21_info[40].fileTime1 = 1209309252U;
  c21_info[40].fileTime2 = 0U;
  c21_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c21_info[41].name = "lt";
  c21_info[41].dominantType = "int32";
  c21_info[41].resolved = "[B]lt";
  c21_info[41].fileLength = 0U;
  c21_info[41].fileTime1 = 0U;
  c21_info[41].fileTime2 = 0U;
  c21_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c21_info[42].name = "length";
  c21_info[42].dominantType = "double";
  c21_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c21_info[42].fileLength = 326U;
  c21_info[42].fileTime1 = 1226552074U;
  c21_info[42].fileTime2 = 0U;
  c21_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c21_info[43].name = "min";
  c21_info[43].dominantType = "double";
  c21_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c21_info[43].fileLength = 362U;
  c21_info[43].fileTime1 = 1245080764U;
  c21_info[43].fileTime2 = 0U;
  c21_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c21_info[44].name = "nargout";
  c21_info[44].dominantType = "";
  c21_info[44].resolved = "[B]nargout";
  c21_info[44].fileLength = 0U;
  c21_info[44].fileTime1 = 0U;
  c21_info[44].fileTime2 = 0U;
  c21_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c21_info[45].name = "eml_min_or_max";
  c21_info[45].dominantType = "char";
  c21_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c21_info[45].fileLength = 9967U;
  c21_info[45].fileTime1 = 1261926670U;
  c21_info[45].fileTime2 = 0U;
  c21_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c21_info[46].name = "isnumeric";
  c21_info[46].dominantType = "double";
  c21_info[46].resolved = "[B]isnumeric";
  c21_info[46].fileLength = 0U;
  c21_info[46].fileTime1 = 0U;
  c21_info[46].fileTime2 = 0U;
  c21_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c21_info[47].name = "islogical";
  c21_info[47].dominantType = "double";
  c21_info[47].resolved = "[B]islogical";
  c21_info[47].fileLength = 0U;
  c21_info[47].fileTime1 = 0U;
  c21_info[47].fileTime2 = 0U;
  c21_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c21_info[48].name = "eml_scalexp_alloc";
  c21_info[48].dominantType = "double";
  c21_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c21_info[48].fileLength = 932U;
  c21_info[48].fileTime1 = 1261926670U;
  c21_info[48].fileTime2 = 0U;
  c21_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c21_info[49].name = "minus";
  c21_info[49].dominantType = "double";
  c21_info[49].resolved = "[B]minus";
  c21_info[49].fileLength = 0U;
  c21_info[49].fileTime1 = 0U;
  c21_info[49].fileTime2 = 0U;
  c21_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c21_info[50].name = "eml_refblas_xgemm";
  c21_info[50].dominantType = "int32";
  c21_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c21_info[50].fileLength = 5748U;
  c21_info[50].fileTime1 = 1228068672U;
  c21_info[50].fileTime2 = 0U;
  c21_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c21_info[51].name = "eml_index_minus";
  c21_info[51].dominantType = "int32";
  c21_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c21_info[51].fileLength = 277U;
  c21_info[51].fileTime1 = 1192445184U;
  c21_info[51].fileTime2 = 0U;
  c21_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c21_info[52].name = "eml_index_times";
  c21_info[52].dominantType = "int32";
  c21_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c21_info[52].fileLength = 280U;
  c21_info[52].fileTime1 = 1192445186U;
  c21_info[52].fileTime2 = 0U;
  c21_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c21_info[53].name = "eml_index_plus";
  c21_info[53].dominantType = "int32";
  c21_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c21_info[53].fileLength = 272U;
  c21_info[53].fileTime1 = 1192445184U;
  c21_info[53].fileTime2 = 0U;
  c21_info[54].context = "";
  c21_info[54].name = "body_Jacobian_d2";
  c21_info[54].dominantType = "double";
  c21_info[54].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d2.m";
  c21_info[54].fileLength = 795U;
  c21_info[54].fileTime1 = 1408088376U;
  c21_info[54].fileTime2 = 0U;
  c21_info[55].context = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d2.m";
  c21_info[55].name = "cos";
  c21_info[55].dominantType = "double";
  c21_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c21_info[55].fileLength = 324U;
  c21_info[55].fileTime1 = 1203422750U;
  c21_info[55].fileTime2 = 0U;
  c21_info[56].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c21_info[56].name = "eml_scalar_cos";
  c21_info[56].dominantType = "double";
  c21_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c21_info[56].fileLength = 602U;
  c21_info[56].fileTime1 = 1209309186U;
  c21_info[56].fileTime2 = 0U;
  c21_info[57].context = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d2.m";
  c21_info[57].name = "sin";
  c21_info[57].dominantType = "double";
  c21_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c21_info[57].fileLength = 324U;
  c21_info[57].fileTime1 = 1203422842U;
  c21_info[57].fileTime2 = 0U;
  c21_info[58].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c21_info[58].name = "eml_scalar_sin";
  c21_info[58].dominantType = "double";
  c21_info[58].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c21_info[58].fileLength = 601U;
  c21_info[58].fileTime1 = 1209309190U;
  c21_info[58].fileTime2 = 0U;
  c21_info[59].context = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d2.m";
  c21_info[59].name = "times";
  c21_info[59].dominantType = "double";
  c21_info[59].resolved = "[B]times";
  c21_info[59].fileLength = 0U;
  c21_info[59].fileTime1 = 0U;
  c21_info[59].fileTime2 = 0U;
  c21_info[60].context = "";
  c21_info[60].name = "body_Jacobian_d3";
  c21_info[60].dominantType = "double";
  c21_info[60].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d3.m";
  c21_info[60].fileLength = 1491U;
  c21_info[60].fileTime1 = 1408088376U;
  c21_info[60].fileTime2 = 0U;
  c21_info[61].context = "";
  c21_info[61].name = "body_Jacobian_d4";
  c21_info[61].dominantType = "double";
  c21_info[61].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d4.m";
  c21_info[61].fileLength = 2377U;
  c21_info[61].fileTime1 = 1408088375U;
  c21_info[61].fileTime2 = 0U;
  c21_info[62].context = "[E]D:/Learn/Project_Matlab/Fanuc/body_Jacobian_d4.m";
  c21_info[62].name = "power";
  c21_info[62].dominantType = "double";
  c21_info[62].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c21_info[62].fileLength = 5380U;
  c21_info[62].fileTime1 = 1228068698U;
  c21_info[62].fileTime2 = 0U;
  c21_info[63].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c21_info[63].name = "eml_scalar_floor";
  c21_info[63].dominantType = "double";
  c21_info[63].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c21_info[63].fileLength = 260U;
  c21_info[63].fileTime1 = 1209309190U;
  c21_info[63].fileTime2 = 0U;
}

static const mxArray *c21_h_sf_marshall(void *chartInstanceVoid, void *c21_u)
{
  const mxArray *c21_y = NULL;
  boolean_T c21_b_u;
  const mxArray *c21_b_y = NULL;
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c21_y = NULL;
  c21_b_u = *((boolean_T *)c21_u);
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c21_y, c21_b_y);
  return c21_y;
}

static void c21_emlrt_marshallIn(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c21_Vel, const char_T *c21_name,
  real_T c21_y[36])
{
  real_T c21_dv9[36];
  int32_T c21_i120;
  sf_mex_import(c21_name, sf_mex_dup(c21_Vel), c21_dv9, 1, 0, 0U, 1, 0U, 1, 36);
  for (c21_i120 = 0; c21_i120 < 36; c21_i120 = c21_i120 + 1) {
    c21_y[c21_i120] = c21_dv9[c21_i120];
  }

  sf_mex_destroy(&c21_Vel);
}

static uint8_T c21_b_emlrt_marshallIn(SFc21_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *
  c21_b_is_active_c21_DynJointVerify, const char_T *c21_name)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  sf_mex_import(c21_name, sf_mex_dup(c21_b_is_active_c21_DynJointVerify),
                &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_b_is_active_c21_DynJointVerify);
  return c21_y;
}

static void init_dsm_address_info(SFc21_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c21_DynJointVerify_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(347484482U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3948015243U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3034463901U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4006199134U);
}

mxArray *sf_c21_DynJointVerify_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3250839071U);
    pr[1] = (double)(3235507328U);
    pr[2] = (double)(4280032137U);
    pr[3] = (double)(3369751855U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
      pr[1] = (double)(9);
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
      pr[0] = (double)(36);
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

static mxArray *sf_get_sim_state_info_c21_DynJointVerify(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"Vel\",},{M[8],M[0],T\"is_active_c21_DynJointVerify\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_DynJointVerify_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_DynJointVerifyInstanceStruct *chartInstance;
    chartInstance = (SFc21_DynJointVerifyInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_DynJointVerifyMachineNumber_,
           21,
           1,
           1,
           5,
           0,
           0,
           0,
           0,
           6,
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
          _SFD_SET_DATA_PROPS(1,1,1,0,"EnOmega");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Vel");
          _SFD_SET_DATA_PROPS(3,10,0,0,"L");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Cen");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,405);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"body_Jacobian_d1",0,-1,451);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"body_Jacobian_d2",0,-1,773);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"body_Jacobian_d3",0,-1,1443);
        _SFD_CV_INIT_SCRIPT(3,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"body_Jacobian_d4",0,-1,2306);
        _SFD_CV_INIT_SCRIPT(4,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"body_Jacobian_d5",0,-1,3632);
        _SFD_CV_INIT_SCRIPT(5,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"body_Jacobian_d6",0,-1,4314);
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
            1.0,0,0,(MexFcnForType)c21_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 36;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_e_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshall);
        }

        {
          real_T (*c21_EnTheta)[6];
          real_T (*c21_EnOmega)[6];
          real_T (*c21_Vel)[36];
          c21_Vel = (real_T (*)[36])ssGetOutputPortSignal(chartInstance->S, 1);
          c21_EnOmega = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c21_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c21_EnTheta);
          _SFD_SET_DATA_VALUE_PTR(1U, *c21_EnOmega);
          _SFD_SET_DATA_VALUE_PTR(2U, *c21_Vel);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c21_L);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c21_Cen);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_DynJointVerifyMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c21_DynJointVerify(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_DynJointVerifyInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
  initialize_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_DynJointVerify(void *chartInstanceVar)
{
  enable_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c21_DynJointVerify(void *chartInstanceVar)
{
  disable_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c21_DynJointVerify(void *chartInstanceVar)
{
  sf_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c21_DynJointVerify(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c21_DynJointVerify
    ((SFc21_DynJointVerifyInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c21_DynJointVerify();/* state var info */
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

static void sf_internal_set_sim_state_c21_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c21_DynJointVerify();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c21_DynJointVerify(SimStruct* S)
{
  return sf_internal_get_sim_state_c21_DynJointVerify(S);
}

static void sf_opaque_set_sim_state_c21_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c21_DynJointVerify(S, st);
}

static void sf_opaque_terminate_c21_DynJointVerify(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_DynJointVerifyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c21_DynJointVerify
    ((SFc21_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_DynJointVerify(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_DynJointVerify((SFc21_DynJointVerifyInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_DynJointVerify(SimStruct *S)
{
  /* Actual parameters from chart:
     Cen L
   */
  const char_T *rtParamNames[] = { "p1", "p2" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Cen*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for L*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"DynJointVerify","DynJointVerify",21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DynJointVerify","DynJointVerify",21,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DynJointVerify",
      "DynJointVerify",21,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DynJointVerify","DynJointVerify",21,
        2);
      sf_mark_chart_reusable_outputs(S,"DynJointVerify","DynJointVerify",21,1);
    }

    sf_set_rtw_dwork_info(S,"DynJointVerify","DynJointVerify",21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3973642529U));
  ssSetChecksum1(S,(818676939U));
  ssSetChecksum2(S,(1198148814U));
  ssSetChecksum3(S,(1600303087U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c21_DynJointVerify(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DynJointVerify", "DynJointVerify",21);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_DynJointVerify(SimStruct *S)
{
  SFc21_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc21_DynJointVerifyInstanceStruct *)malloc(sizeof
    (SFc21_DynJointVerifyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_DynJointVerifyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_DynJointVerify;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_DynJointVerify;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_DynJointVerify;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_DynJointVerify;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_DynJointVerify;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_DynJointVerify;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_DynJointVerify;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_DynJointVerify;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_DynJointVerify;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_DynJointVerify;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_DynJointVerify;
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

void c21_DynJointVerify_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_DynJointVerify(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_DynJointVerify(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_DynJointVerify(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_DynJointVerify_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
