/* Include files */

#include "blascompat32.h"
#include "DynJointVerify_sfun.h"
#include "c17_DynJointVerify.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DynJointVerify_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char *c17_debug_family_names[14] = { "L_EU", "Cen", "Ma", "nargin",
  "nargout", "RefAcc", "EnTheta", "Ie1", "Ie2", "Ie3", "Ie4", "Ie5", "Ie6",
  "M_Acc" };

static const char *c17_b_debug_family_names[548] = { "Cx1", "Cx2", "Cx3", "Cx4",
  "Cx5", "Cx6", "Cy1", "Cy2", "Cy3", "Cy4", "Cy5", "Cy6", "Cz2", "Cz3", "Cz4",
  "Cz5", "Cz6", "I1_33", "I2_11", "I2_12", "I2_21", "I2_13", "I2_22", "I2_31",
  "I2_23", "I2_32", "I2_33", "I3_11", "I3_12", "I3_21", "I3_13", "I3_22",
  "I3_31", "I3_23", "I3_32", "I3_33", "I4_11", "I4_12", "I4_21", "I4_13",
  "I4_22", "I4_31", "I4_23", "I4_32", "I4_33", "I5_11", "I5_12", "I5_21",
  "I5_13", "I5_22", "I5_31", "I5_23", "I5_32", "I5_33", "I6_11", "I6_12",
  "I6_21", "I6_13", "I6_22", "I6_31", "I6_23", "I6_32", "I6_33", "Ld1", "Ld2",
  "Ld3", "Ld4", "Ld5", "Ld6", "Ld7", "Ma1", "Ma2", "Ma3", "Ma4", "Ma5", "Ma6",
  "pos2", "pos3", "pos4", "pos5", "pos6", "t2", "t3", "t4", "t5", "t6", "t7",
  "t8", "t22", "t9", "t10", "t11", "t12", "t13", "t14", "t15", "t16", "t17",
  "t18", "t19", "t20", "t21", "t23", "t24", "t25", "t26", "t27", "t28", "t29",
  "t30", "t31", "t32", "t33", "t41", "t34", "t35", "t42", "t36", "t37", "t38",
  "t39", "t40", "t43", "t44", "t45", "t47", "t46", "t48", "t49", "t51", "t50",
  "t52", "t53", "t54", "t55", "t56", "t57", "t58", "t59", "t60", "t61", "t62",
  "t63", "t64", "t65", "t66", "t67", "t68", "t69", "t70", "t71", "t72", "t73",
  "t74", "t75", "t76", "t77", "t78", "t79", "t80", "t81", "t82", "t83", "t84",
  "t85", "t86", "t87", "t88", "t89", "t90", "t91", "t92", "t93", "t94", "t95",
  "t96", "t97", "t98", "t99", "t100", "t101", "t102", "t103", "t104", "t105",
  "t106", "t107", "t108", "t202", "t109", "t110", "t111", "t112", "t113", "t114",
  "t201", "t115", "t116", "t117", "t118", "t119", "t120", "t121", "t122", "t123",
  "t124", "t125", "t126", "t190", "t127", "t128", "t129", "t130", "t131", "t215",
  "t132", "t133", "t134", "t135", "t136", "t137", "t138", "t216", "t139", "t140",
  "t141", "t142", "t243", "t143", "t144", "t145", "t146", "t147", "t148", "t149",
  "t150", "t151", "t152", "t153", "t154", "t221", "t155", "t156", "t157", "t220",
  "t158", "t159", "t160", "t218", "t161", "t162", "t163", "t165", "t164", "t171",
  "t166", "t167", "t168", "t169", "t170", "t172", "t173", "t224", "t174", "t184",
  "t175", "t176", "t177", "t178", "t179", "t180", "t225", "t226", "t181", "t182",
  "t183", "t185", "t186", "t187", "t188", "t189", "t191", "t192", "t193", "t194",
  "t195", "t196", "t197", "t198", "t199", "t200", "t203", "t242", "t204", "t205",
  "t206", "t207", "t208", "t209", "t210", "t211", "t212", "t240", "t213", "t214",
  "t217", "t222", "t219", "t241", "t223", "t227", "t228", "t236", "t229", "t230",
  "t231", "t232", "t233", "t234", "t235", "t237", "t238", "t239", "t244", "t245",
  "t246", "t247", "t248", "t250", "t249", "t251", "t252", "t253", "t254", "t319",
  "t255", "t256", "t257", "t258", "t320", "t321", "t259", "t260", "t261", "t331",
  "t262", "t263", "t264", "t265", "t266", "t267", "t268", "t269", "t270", "t271",
  "t272", "t273", "t326", "t327", "t274", "t275", "t276", "t277", "t278", "t279",
  "t280", "t281", "t282", "t283", "t334", "t335", "t284", "t285", "t286", "t332",
  "t287", "t288", "t289", "t290", "t291", "t337", "t292", "t293", "t294", "t295",
  "t296", "t297", "t298", "t299", "t300", "t301", "t302", "t338", "t303", "t304",
  "t305", "t342", "t306", "t307", "t308", "t309", "t340", "t341", "t310", "t311",
  "t312", "t313", "t343", "t344", "t314", "t315", "t316", "t317", "t318", "t322",
  "t323", "t324", "t325", "t328", "t329", "t349", "t330", "t350", "t333", "t336",
  "t339", "t345", "t346", "t347", "t348", "t351", "t352", "t353", "t354", "t381",
  "t355", "t356", "t357", "t358", "t359", "t360", "t361", "t362", "t363", "t364",
  "t365", "t366", "t367", "t368", "t369", "t370", "t371", "t372", "t373", "t374",
  "t375", "t386", "t376", "t387", "t377", "t378", "t379", "t380", "t382", "t383",
  "t384", "t385", "t395", "t388", "t389", "t390", "t391", "t400", "t392", "t393",
  "t394", "t396", "t397", "t398", "t399", "t401", "t402", "t403", "t404", "t405",
  "t406", "t407", "t408", "t409", "t410", "t411", "t412", "t413", "t414", "t415",
  "t435", "t416", "t417", "t418", "t419", "t420", "t421", "t422", "t423", "t424",
  "t425", "t426", "t427", "t428", "t429", "t430", "t438", "t431", "t432", "t433",
  "t434", "t436", "t437", "t439", "t440", "t446", "t441", "t442", "t447", "t443",
  "t444", "t452", "t453", "t445", "t451", "t454", "t448", "t449", "t450", "t455",
  "nargin", "nargout", "in1", "in2", "in3", "in4", "in5", "in6", "in7", "in8",
  "in9", "in10", "EulerMd_" };

/* Function Declarations */
static void initialize_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance);
static void initialize_params_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance);
static void enable_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance);
static void disable_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance);
static void c17_update_debugger_state_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance);
static void set_sim_state_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct *
  chartInstance, const mxArray *c17_st);
static void finalize_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance);
static void sf_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance);
static void compInitSubchartSimstructsFcn_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber);
static void c17_EulerMd(SFc17_DynJointVerifyInstanceStruct *chartInstance,
  real_T c17_in1[8], real_T c17_in2[6], real_T c17_in3[18], real_T c17_in4[9],
  real_T c17_in5[9], real_T c17_in6[9], real_T c17_in7[9], real_T c17_in8[9],
  real_T c17_in9[9], real_T c17_in10[6], real_T c17_EulerMd_[36]);
static real_T c17_power(SFc17_DynJointVerifyInstanceStruct *chartInstance,
  real_T c17_a, real_T c17_b);
static void c17_eml_scalar_eg(SFc17_DynJointVerifyInstanceStruct *chartInstance);
static void c17_eml_error(SFc17_DynJointVerifyInstanceStruct *chartInstance);
static void c17_b_eml_scalar_eg(SFc17_DynJointVerifyInstanceStruct
  *chartInstance);
static const mxArray *c17_sf_marshall(void *chartInstanceVoid, void *c17_u);
static const mxArray *c17_b_sf_marshall(void *chartInstanceVoid, void *c17_u);
static const mxArray *c17_c_sf_marshall(void *chartInstanceVoid, void *c17_u);
static const mxArray *c17_d_sf_marshall(void *chartInstanceVoid, void *c17_u);
static const mxArray *c17_e_sf_marshall(void *chartInstanceVoid, void *c17_u);
static const mxArray *c17_f_sf_marshall(void *chartInstanceVoid, void *c17_u);
static const mxArray *c17_g_sf_marshall(void *chartInstanceVoid, void *c17_u);
static void c17_info_helper(c17_ResolvedFunctionInfo c17_info[58]);
static const mxArray *c17_h_sf_marshall(void *chartInstanceVoid, void *c17_u);
static void c17_emlrt_marshallIn(SFc17_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c17_M_Acc, const char_T *c17_name, real_T
  c17_y[6]);
static uint8_T c17_b_emlrt_marshallIn(SFc17_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c17_b_is_active_c17_DynJointVerify, const
  char_T *c17_name);
static void init_dsm_address_info(SFc17_DynJointVerifyInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c17_is_active_c17_DynJointVerify = 0U;
}

static void initialize_params_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance)
{
  real_T c17_dv0[8];
  int32_T c17_i0;
  real_T c17_dv1[18];
  int32_T c17_i1;
  real_T c17_dv2[6];
  int32_T c17_i2;
  real_T c17_dv3[9];
  int32_T c17_i3;
  real_T c17_dv4[9];
  int32_T c17_i4;
  real_T c17_dv5[9];
  int32_T c17_i5;
  real_T c17_dv6[9];
  int32_T c17_i6;
  real_T c17_dv7[9];
  int32_T c17_i7;
  real_T c17_dv8[9];
  int32_T c17_i8;
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'L_EU' in the parent workspace.\n");
  sf_mex_import("L_EU", sf_mex_get_sfun_param(chartInstance->S, 7, 0), c17_dv0,
                0, 0, 0U, 1, 0U, 2, 1, 8);
  for (c17_i0 = 0; c17_i0 < 8; c17_i0 = c17_i0 + 1) {
    chartInstance->c17_L_EU[c17_i0] = c17_dv0[c17_i0];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Cen' in the parent workspace.\n");
  sf_mex_import("Cen", sf_mex_get_sfun_param(chartInstance->S, 0, 0), c17_dv1, 0,
                0, 0U, 1, 0U, 2, 1, 18);
  for (c17_i1 = 0; c17_i1 < 18; c17_i1 = c17_i1 + 1) {
    chartInstance->c17_Cen[c17_i1] = c17_dv1[c17_i1];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ma' in the parent workspace.\n");
  sf_mex_import("Ma", sf_mex_get_sfun_param(chartInstance->S, 8, 0), c17_dv2, 0,
                0, 0U, 1, 0U, 2, 1, 6);
  for (c17_i2 = 0; c17_i2 < 6; c17_i2 = c17_i2 + 1) {
    chartInstance->c17_Ma[c17_i2] = c17_dv2[c17_i2];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ie1' in the parent workspace.\n");
  sf_mex_import("Ie1", sf_mex_get_sfun_param(chartInstance->S, 1, 0), c17_dv3, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c17_i3 = 0; c17_i3 < 9; c17_i3 = c17_i3 + 1) {
    chartInstance->c17_Ie1[c17_i3] = c17_dv3[c17_i3];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ie2' in the parent workspace.\n");
  sf_mex_import("Ie2", sf_mex_get_sfun_param(chartInstance->S, 2, 0), c17_dv4, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c17_i4 = 0; c17_i4 < 9; c17_i4 = c17_i4 + 1) {
    chartInstance->c17_Ie2[c17_i4] = c17_dv4[c17_i4];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ie3' in the parent workspace.\n");
  sf_mex_import("Ie3", sf_mex_get_sfun_param(chartInstance->S, 3, 0), c17_dv5, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c17_i5 = 0; c17_i5 < 9; c17_i5 = c17_i5 + 1) {
    chartInstance->c17_Ie3[c17_i5] = c17_dv5[c17_i5];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ie4' in the parent workspace.\n");
  sf_mex_import("Ie4", sf_mex_get_sfun_param(chartInstance->S, 4, 0), c17_dv6, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c17_i6 = 0; c17_i6 < 9; c17_i6 = c17_i6 + 1) {
    chartInstance->c17_Ie4[c17_i6] = c17_dv6[c17_i6];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ie5' in the parent workspace.\n");
  sf_mex_import("Ie5", sf_mex_get_sfun_param(chartInstance->S, 5, 0), c17_dv7, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c17_i7 = 0; c17_i7 < 9; c17_i7 = c17_i7 + 1) {
    chartInstance->c17_Ie5[c17_i7] = c17_dv7[c17_i7];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
  sf_set_error_prefix_string(
    "Embedded MATLAB Runtime Error (chart): Error evaluating data 'Ie6' in the parent workspace.\n");
  sf_mex_import("Ie6", sf_mex_get_sfun_param(chartInstance->S, 6, 0), c17_dv8, 0,
                0, 0U, 1, 0U, 2, 1, 9);
  for (c17_i8 = 0; c17_i8 < 9; c17_i8 = c17_i8 + 1) {
    chartInstance->c17_Ie6[c17_i8] = c17_dv8[c17_i8];
  }

  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c17_update_debugger_state_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance)
{
  const mxArray *c17_st = NULL;
  const mxArray *c17_y = NULL;
  int32_T c17_i9;
  real_T c17_hoistedGlobal[6];
  int32_T c17_i10;
  real_T c17_u[6];
  const mxArray *c17_b_y = NULL;
  uint8_T c17_b_hoistedGlobal;
  uint8_T c17_b_u;
  const mxArray *c17_c_y = NULL;
  real_T (*c17_M_Acc)[6];
  c17_M_Acc = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_st = NULL;
  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_createcellarray(2));
  for (c17_i9 = 0; c17_i9 < 6; c17_i9 = c17_i9 + 1) {
    c17_hoistedGlobal[c17_i9] = (*c17_M_Acc)[c17_i9];
  }

  for (c17_i10 = 0; c17_i10 < 6; c17_i10 = c17_i10 + 1) {
    c17_u[c17_i10] = c17_hoistedGlobal[c17_i10];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_setcell(c17_y, 0, c17_b_y);
  c17_b_hoistedGlobal = chartInstance->c17_is_active_c17_DynJointVerify;
  c17_b_u = c17_b_hoistedGlobal;
  c17_c_y = NULL;
  sf_mex_assign(&c17_c_y, sf_mex_create("y", &c17_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c17_y, 1, c17_c_y);
  sf_mex_assign(&c17_st, c17_y);
  return c17_st;
}

static void set_sim_state_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct *
  chartInstance, const mxArray *c17_st)
{
  const mxArray *c17_u;
  real_T c17_dv9[6];
  int32_T c17_i11;
  real_T (*c17_M_Acc)[6];
  c17_M_Acc = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c17_doneDoubleBufferReInit = TRUE;
  c17_u = sf_mex_dup(c17_st);
  c17_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 0)),
                       "M_Acc", c17_dv9);
  for (c17_i11 = 0; c17_i11 < 6; c17_i11 = c17_i11 + 1) {
    (*c17_M_Acc)[c17_i11] = c17_dv9[c17_i11];
  }

  chartInstance->c17_is_active_c17_DynJointVerify = c17_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c17_u, 1)),
     "is_active_c17_DynJointVerify");
  sf_mex_destroy(&c17_u);
  c17_update_debugger_state_c17_DynJointVerify(chartInstance);
  sf_mex_destroy(&c17_st);
}

static void finalize_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

static void sf_c17_DynJointVerify(SFc17_DynJointVerifyInstanceStruct
  *chartInstance)
{
  int32_T c17_i12;
  int32_T c17_i13;
  int32_T c17_i14;
  int32_T c17_i15;
  int32_T c17_i16;
  int32_T c17_i17;
  int32_T c17_i18;
  int32_T c17_i19;
  int32_T c17_i20;
  int32_T c17_i21;
  int32_T c17_i22;
  int32_T c17_i23;
  int32_T c17_previousEvent;
  int32_T c17_i24;
  real_T c17_hoistedGlobal[6];
  int32_T c17_i25;
  real_T c17_b_hoistedGlobal[6];
  int32_T c17_i26;
  real_T c17_c_hoistedGlobal[9];
  int32_T c17_i27;
  real_T c17_d_hoistedGlobal[9];
  int32_T c17_i28;
  real_T c17_e_hoistedGlobal[9];
  int32_T c17_i29;
  real_T c17_f_hoistedGlobal[9];
  int32_T c17_i30;
  real_T c17_g_hoistedGlobal[9];
  int32_T c17_i31;
  real_T c17_h_hoistedGlobal[9];
  int32_T c17_i32;
  real_T c17_RefAcc[6];
  int32_T c17_i33;
  real_T c17_EnTheta[6];
  int32_T c17_i34;
  real_T c17_b_Ie1[9];
  int32_T c17_i35;
  real_T c17_b_Ie2[9];
  int32_T c17_i36;
  real_T c17_b_Ie3[9];
  int32_T c17_i37;
  real_T c17_b_Ie4[9];
  int32_T c17_i38;
  real_T c17_b_Ie5[9];
  int32_T c17_i39;
  real_T c17_b_Ie6[9];
  uint32_T c17_debug_family_var_map[14];
  static const char *c17_sv0[14] = { "L_EU", "Cen", "Ma", "nargin", "nargout",
    "RefAcc", "EnTheta", "Ie1", "Ie2", "Ie3", "Ie4", "Ie5"
    , "Ie6", "M_Acc" };

  real_T c17_b_L_EU[8] = { 0.266, 0.3, 0.15, 0.87, 0.0, 0.17, 1.016, 0.174 };

  real_T c17_b_Cen[18] = { 0.0407, 0.151, 0.1568, 0.8245, 1.2407, 1.33, -0.0528,
    0.1746, -0.0318, -0.011, 0.018, 0.0, 0.4702, 0.9687,
    1.5191, 1.606, 1.606, 1.606 };

  real_T c17_b_Ma[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  real_T c17_nargin = 11.0;
  real_T c17_nargout = 1.0;
  real_T c17_M_Acc[6];
  int32_T c17_i40;
  int32_T c17_i41;
  static real_T c17_dv10[8] = { 0.266, 0.3, 0.15, 0.87, 0.0, 0.17, 1.016, 0.174
  };

  real_T c17_dv11[8];
  int32_T c17_i42;
  static real_T c17_dv12[6] = { 170.31, 63.74, 98.98, 24.46, 5.24, 0.6 };

  real_T c17_dv13[6];
  int32_T c17_i43;
  static real_T c17_dv14[18] = { 0.0407, 0.151, 0.1568, 0.8245, 1.2407, 1.33,
    -0.0528, 0.1746, -0.0318, -0.011, 0.018, 0.0, 0.4702,
    0.9687, 1.5191, 1.606, 1.606, 1.606 };

  real_T c17_dv15[18];
  int32_T c17_i44;
  real_T c17_c_Ie1[9];
  int32_T c17_i45;
  real_T c17_c_Ie2[9];
  int32_T c17_i46;
  real_T c17_c_Ie3[9];
  int32_T c17_i47;
  real_T c17_c_Ie4[9];
  int32_T c17_i48;
  real_T c17_c_Ie5[9];
  int32_T c17_i49;
  real_T c17_c_Ie6[9];
  int32_T c17_i50;
  real_T c17_b_EnTheta[6];
  real_T c17_a[36];
  int32_T c17_i51;
  real_T c17_b[6];
  int32_T c17_i52;
  real_T c17_A[36];
  int32_T c17_i53;
  real_T c17_B[6];
  int32_T c17_i54;
  int32_T c17_i55;
  real_T c17_b_A[36];
  int32_T c17_i56;
  real_T c17_b_B[6];
  int32_T c17_i57;
  real_T c17_c_A[36];
  int32_T c17_i58;
  real_T c17_c_B[6];
  int32_T c17_i59;
  int32_T c17_i60;
  int32_T c17_i61;
  int32_T c17_i62;
  real_T (*c17_b_M_Acc)[6];
  real_T (*c17_c_EnTheta)[6];
  real_T (*c17_b_RefAcc)[6];
  c17_b_M_Acc = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
  c17_c_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c17_b_RefAcc = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16);
  for (c17_i12 = 0; c17_i12 < 6; c17_i12 = c17_i12 + 1) {
    _SFD_DATA_RANGE_CHECK((*c17_b_RefAcc)[c17_i12], 0U);
  }

  for (c17_i13 = 0; c17_i13 < 6; c17_i13 = c17_i13 + 1) {
    _SFD_DATA_RANGE_CHECK((*c17_c_EnTheta)[c17_i13], 1U);
  }

  for (c17_i14 = 0; c17_i14 < 6; c17_i14 = c17_i14 + 1) {
    _SFD_DATA_RANGE_CHECK((*c17_b_M_Acc)[c17_i14], 2U);
  }

  for (c17_i15 = 0; c17_i15 < 8; c17_i15 = c17_i15 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_L_EU[c17_i15], 3U);
  }

  for (c17_i16 = 0; c17_i16 < 18; c17_i16 = c17_i16 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Cen[c17_i16], 4U);
  }

  for (c17_i17 = 0; c17_i17 < 6; c17_i17 = c17_i17 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Ma[c17_i17], 5U);
  }

  for (c17_i18 = 0; c17_i18 < 9; c17_i18 = c17_i18 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Ie1[c17_i18], 6U);
  }

  for (c17_i19 = 0; c17_i19 < 9; c17_i19 = c17_i19 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Ie2[c17_i19], 7U);
  }

  for (c17_i20 = 0; c17_i20 < 9; c17_i20 = c17_i20 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Ie3[c17_i20], 8U);
  }

  for (c17_i21 = 0; c17_i21 < 9; c17_i21 = c17_i21 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Ie4[c17_i21], 9U);
  }

  for (c17_i22 = 0; c17_i22 < 9; c17_i22 = c17_i22 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Ie5[c17_i22], 10U);
  }

  for (c17_i23 = 0; c17_i23 < 9; c17_i23 = c17_i23 + 1) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c17_Ie6[c17_i23], 11U);
  }

  c17_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16);
  for (c17_i24 = 0; c17_i24 < 6; c17_i24 = c17_i24 + 1) {
    c17_hoistedGlobal[c17_i24] = (*c17_b_RefAcc)[c17_i24];
  }

  for (c17_i25 = 0; c17_i25 < 6; c17_i25 = c17_i25 + 1) {
    c17_b_hoistedGlobal[c17_i25] = (*c17_c_EnTheta)[c17_i25];
  }

  for (c17_i26 = 0; c17_i26 < 9; c17_i26 = c17_i26 + 1) {
    c17_c_hoistedGlobal[c17_i26] = chartInstance->c17_Ie1[c17_i26];
  }

  for (c17_i27 = 0; c17_i27 < 9; c17_i27 = c17_i27 + 1) {
    c17_d_hoistedGlobal[c17_i27] = chartInstance->c17_Ie2[c17_i27];
  }

  for (c17_i28 = 0; c17_i28 < 9; c17_i28 = c17_i28 + 1) {
    c17_e_hoistedGlobal[c17_i28] = chartInstance->c17_Ie3[c17_i28];
  }

  for (c17_i29 = 0; c17_i29 < 9; c17_i29 = c17_i29 + 1) {
    c17_f_hoistedGlobal[c17_i29] = chartInstance->c17_Ie4[c17_i29];
  }

  for (c17_i30 = 0; c17_i30 < 9; c17_i30 = c17_i30 + 1) {
    c17_g_hoistedGlobal[c17_i30] = chartInstance->c17_Ie5[c17_i30];
  }

  for (c17_i31 = 0; c17_i31 < 9; c17_i31 = c17_i31 + 1) {
    c17_h_hoistedGlobal[c17_i31] = chartInstance->c17_Ie6[c17_i31];
  }

  for (c17_i32 = 0; c17_i32 < 6; c17_i32 = c17_i32 + 1) {
    c17_RefAcc[c17_i32] = c17_hoistedGlobal[c17_i32];
  }

  for (c17_i33 = 0; c17_i33 < 6; c17_i33 = c17_i33 + 1) {
    c17_EnTheta[c17_i33] = c17_b_hoistedGlobal[c17_i33];
  }

  for (c17_i34 = 0; c17_i34 < 9; c17_i34 = c17_i34 + 1) {
    c17_b_Ie1[c17_i34] = c17_c_hoistedGlobal[c17_i34];
  }

  for (c17_i35 = 0; c17_i35 < 9; c17_i35 = c17_i35 + 1) {
    c17_b_Ie2[c17_i35] = c17_d_hoistedGlobal[c17_i35];
  }

  for (c17_i36 = 0; c17_i36 < 9; c17_i36 = c17_i36 + 1) {
    c17_b_Ie3[c17_i36] = c17_e_hoistedGlobal[c17_i36];
  }

  for (c17_i37 = 0; c17_i37 < 9; c17_i37 = c17_i37 + 1) {
    c17_b_Ie4[c17_i37] = c17_f_hoistedGlobal[c17_i37];
  }

  for (c17_i38 = 0; c17_i38 < 9; c17_i38 = c17_i38 + 1) {
    c17_b_Ie5[c17_i38] = c17_g_hoistedGlobal[c17_i38];
  }

  for (c17_i39 = 0; c17_i39 < 9; c17_i39 = c17_i39 + 1) {
    c17_b_Ie6[c17_i39] = c17_h_hoistedGlobal[c17_i39];
  }

  sf_debug_symbol_scope_push_eml(0U, 14U, 14U, c17_sv0, c17_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(c17_b_L_EU, c17_f_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(c17_b_Cen, c17_e_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(c17_b_Ma, c17_d_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c17_nargin, c17_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c17_nargout, c17_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(c17_RefAcc, c17_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(c17_EnTheta, c17_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(c17_b_Ie1, c17_b_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(c17_b_Ie2, c17_b_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(c17_b_Ie3, c17_b_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(c17_b_Ie4, c17_b_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(c17_b_Ie5, c17_b_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(c17_b_Ie6, c17_b_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(c17_M_Acc, c17_sf_marshall, 13U);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0, 4);
  for (c17_i40 = 0; c17_i40 < 6; c17_i40 = c17_i40 + 1) {
    c17_M_Acc[c17_i40] = 0.0;
  }

  _SFD_EML_CALL(0, 5);
  for (c17_i41 = 0; c17_i41 < 8; c17_i41 = c17_i41 + 1) {
    c17_dv11[c17_i41] = c17_dv10[c17_i41];
  }

  for (c17_i42 = 0; c17_i42 < 6; c17_i42 = c17_i42 + 1) {
    c17_dv13[c17_i42] = c17_dv12[c17_i42];
  }

  for (c17_i43 = 0; c17_i43 < 18; c17_i43 = c17_i43 + 1) {
    c17_dv15[c17_i43] = c17_dv14[c17_i43];
  }

  for (c17_i44 = 0; c17_i44 < 9; c17_i44 = c17_i44 + 1) {
    c17_c_Ie1[c17_i44] = c17_b_Ie1[c17_i44];
  }

  for (c17_i45 = 0; c17_i45 < 9; c17_i45 = c17_i45 + 1) {
    c17_c_Ie2[c17_i45] = c17_b_Ie2[c17_i45];
  }

  for (c17_i46 = 0; c17_i46 < 9; c17_i46 = c17_i46 + 1) {
    c17_c_Ie3[c17_i46] = c17_b_Ie3[c17_i46];
  }

  for (c17_i47 = 0; c17_i47 < 9; c17_i47 = c17_i47 + 1) {
    c17_c_Ie4[c17_i47] = c17_b_Ie4[c17_i47];
  }

  for (c17_i48 = 0; c17_i48 < 9; c17_i48 = c17_i48 + 1) {
    c17_c_Ie5[c17_i48] = c17_b_Ie5[c17_i48];
  }

  for (c17_i49 = 0; c17_i49 < 9; c17_i49 = c17_i49 + 1) {
    c17_c_Ie6[c17_i49] = c17_b_Ie6[c17_i49];
  }

  for (c17_i50 = 0; c17_i50 < 6; c17_i50 = c17_i50 + 1) {
    c17_b_EnTheta[c17_i50] = c17_EnTheta[c17_i50];
  }

  c17_EulerMd(chartInstance, c17_dv11, c17_dv13, c17_dv15, c17_c_Ie1, c17_c_Ie2,
              c17_c_Ie3, c17_c_Ie4, c17_c_Ie5, c17_c_Ie6,
              c17_b_EnTheta, c17_a);
  for (c17_i51 = 0; c17_i51 < 6; c17_i51 = c17_i51 + 1) {
    c17_b[c17_i51] = c17_RefAcc[c17_i51];
  }

  c17_b_eml_scalar_eg(chartInstance);
  c17_b_eml_scalar_eg(chartInstance);
  for (c17_i52 = 0; c17_i52 < 36; c17_i52 = c17_i52 + 1) {
    c17_A[c17_i52] = c17_a[c17_i52];
  }

  for (c17_i53 = 0; c17_i53 < 6; c17_i53 = c17_i53 + 1) {
    c17_B[c17_i53] = c17_b[c17_i53];
  }

  for (c17_i54 = 0; c17_i54 < 6; c17_i54 = c17_i54 + 1) {
    c17_M_Acc[c17_i54] = 0.0;
  }

  for (c17_i55 = 0; c17_i55 < 36; c17_i55 = c17_i55 + 1) {
    c17_b_A[c17_i55] = c17_A[c17_i55];
  }

  for (c17_i56 = 0; c17_i56 < 6; c17_i56 = c17_i56 + 1) {
    c17_b_B[c17_i56] = c17_B[c17_i56];
  }

  for (c17_i57 = 0; c17_i57 < 36; c17_i57 = c17_i57 + 1) {
    c17_c_A[c17_i57] = c17_b_A[c17_i57];
  }

  for (c17_i58 = 0; c17_i58 < 6; c17_i58 = c17_i58 + 1) {
    c17_c_B[c17_i58] = c17_b_B[c17_i58];
  }

  for (c17_i59 = 0; c17_i59 < 6; c17_i59 = c17_i59 + 1) {
    c17_M_Acc[c17_i59] = 0.0;
    c17_i60 = 0;
    for (c17_i61 = 0; c17_i61 < 6; c17_i61 = c17_i61 + 1) {
      c17_M_Acc[c17_i59] = c17_M_Acc[c17_i59] + c17_c_A[c17_i60 + c17_i59] *
        c17_c_B[c17_i61];
      c17_i60 = c17_i60 + 6;
    }
  }

  _SFD_EML_CALL(0, -5);
  sf_debug_symbol_scope_pop();
  for (c17_i62 = 0; c17_i62 < 6; c17_i62 = c17_i62 + 1) {
    (*c17_b_M_Acc)[c17_i62] = c17_M_Acc[c17_i62];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16);
  _sfEvent_ = c17_previousEvent;
  sf_debug_check_for_state_inconsistency(_DynJointVerifyMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void compInitSubchartSimstructsFcn_c17_DynJointVerify
  (SFc17_DynJointVerifyInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c17_machineNumber, uint32_T
  c17_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c17_chartNumber, 0U, sf_debug_get_script_id(
    "D:/Learn/Project_Matlab/Fanuc/EulerMd.m"));
}

static void c17_EulerMd(SFc17_DynJointVerifyInstanceStruct *chartInstance,
  real_T c17_in1[8], real_T c17_in2[6], real_T c17_in3[18]
  , real_T c17_in4[9], real_T c17_in5[9], real_T c17_in6[9], real_T c17_in7[9],
  real_T c17_in8[9], real_T c17_in9[9], real_T c17_in10[
  6], real_T c17_EulerMd_[36])
{
  uint32_T c17_debug_family_var_map[548];
  real_T c17_Cx1;
  real_T c17_Cx2;
  real_T c17_Cx3;
  real_T c17_Cx4;
  real_T c17_Cx5;
  real_T c17_Cx6;
  real_T c17_Cy1;
  real_T c17_Cy2;
  real_T c17_Cy3;
  real_T c17_Cy4;
  real_T c17_Cy5;
  real_T c17_Cy6;
  real_T c17_Cz2;
  real_T c17_Cz3;
  real_T c17_Cz4;
  real_T c17_Cz5;
  real_T c17_Cz6;
  real_T c17_I1_33;
  real_T c17_I2_11;
  real_T c17_I2_12;
  real_T c17_I2_21;
  real_T c17_I2_13;
  real_T c17_I2_22;
  real_T c17_I2_31;
  real_T c17_I2_23;
  real_T c17_I2_32;
  real_T c17_I2_33;
  real_T c17_I3_11;
  real_T c17_I3_12;
  real_T c17_I3_21;
  real_T c17_I3_13;
  real_T c17_I3_22;
  real_T c17_I3_31;
  real_T c17_I3_23;
  real_T c17_I3_32;
  real_T c17_I3_33;
  real_T c17_I4_11;
  real_T c17_I4_12;
  real_T c17_I4_21;
  real_T c17_I4_13;
  real_T c17_I4_22;
  real_T c17_I4_31;
  real_T c17_I4_23;
  real_T c17_I4_32;
  real_T c17_I4_33;
  real_T c17_I5_11;
  real_T c17_I5_12;
  real_T c17_I5_21;
  real_T c17_I5_13;
  real_T c17_I5_22;
  real_T c17_I5_31;
  real_T c17_I5_23;
  real_T c17_I5_32;
  real_T c17_I5_33;
  real_T c17_I6_11;
  real_T c17_I6_12;
  real_T c17_I6_21;
  real_T c17_I6_13;
  real_T c17_I6_22;
  real_T c17_I6_31;
  real_T c17_I6_23;
  real_T c17_I6_32;
  real_T c17_I6_33;
  real_T c17_Ld1;
  real_T c17_Ld2;
  real_T c17_Ld3;
  real_T c17_Ld4;
  real_T c17_Ld5;
  real_T c17_Ld6;
  real_T c17_Ld7;
  real_T c17_Ma1;
  real_T c17_Ma2;
  real_T c17_Ma3;
  real_T c17_Ma4;
  real_T c17_Ma5;
  real_T c17_Ma6;
  real_T c17_pos2;
  real_T c17_pos3;
  real_T c17_pos4;
  real_T c17_pos5;
  real_T c17_pos6;
  real_T c17_t2;
  real_T c17_t3;
  real_T c17_t4;
  real_T c17_t5;
  real_T c17_t6;
  real_T c17_t7;
  real_T c17_t8;
  real_T c17_t22;
  real_T c17_t9;
  real_T c17_t10;
  real_T c17_t11;
  real_T c17_t12;
  real_T c17_t13;
  real_T c17_t14;
  real_T c17_t15;
  real_T c17_t16;
  real_T c17_t17;
  real_T c17_t18;
  real_T c17_t19;
  real_T c17_t20;
  real_T c17_t21;
  real_T c17_t23;
  real_T c17_t24;
  real_T c17_t25;
  real_T c17_t26;
  real_T c17_t27;
  real_T c17_t28;
  real_T c17_t29;
  real_T c17_t30;
  real_T c17_t31;
  real_T c17_t32;
  real_T c17_t33;
  real_T c17_t41;
  real_T c17_t34;
  real_T c17_t35;
  real_T c17_t42;
  real_T c17_t36;
  real_T c17_t37;
  real_T c17_t38;
  real_T c17_t39;
  real_T c17_t40;
  real_T c17_t43;
  real_T c17_t44;
  real_T c17_t45;
  real_T c17_t47;
  real_T c17_t46;
  real_T c17_t48;
  real_T c17_t49;
  real_T c17_t51;
  real_T c17_t50;
  real_T c17_t52;
  real_T c17_t53;
  real_T c17_t54;
  real_T c17_t55;
  real_T c17_t56;
  real_T c17_t57;
  real_T c17_t58;
  real_T c17_t59;
  real_T c17_t60;
  real_T c17_t61;
  real_T c17_t62;
  real_T c17_t63;
  real_T c17_t64;
  real_T c17_t65;
  real_T c17_t66;
  real_T c17_t67;
  real_T c17_t68;
  real_T c17_t69;
  real_T c17_t70;
  real_T c17_t71;
  real_T c17_t72;
  real_T c17_t73;
  real_T c17_t74;
  real_T c17_t75;
  real_T c17_t76;
  real_T c17_t77;
  real_T c17_t78;
  real_T c17_t79;
  real_T c17_t80;
  real_T c17_t81;
  real_T c17_t82;
  real_T c17_t83;
  real_T c17_t84;
  real_T c17_t85;
  real_T c17_t86;
  real_T c17_t87;
  real_T c17_t88;
  real_T c17_t89;
  real_T c17_t90;
  real_T c17_t91;
  real_T c17_t92;
  real_T c17_t93;
  real_T c17_t94;
  real_T c17_t95;
  real_T c17_t96;
  real_T c17_t97;
  real_T c17_t98;
  real_T c17_t99;
  real_T c17_t100;
  real_T c17_t101;
  real_T c17_t102;
  real_T c17_t103;
  real_T c17_t104;
  real_T c17_t105;
  real_T c17_t106;
  real_T c17_t107;
  real_T c17_t108;
  real_T c17_t202;
  real_T c17_t109;
  real_T c17_t110;
  real_T c17_t111;
  real_T c17_t112;
  real_T c17_t113;
  real_T c17_t114;
  real_T c17_t201;
  real_T c17_t115;
  real_T c17_t116;
  real_T c17_t117;
  real_T c17_t118;
  real_T c17_t119;
  real_T c17_t120;
  real_T c17_t121;
  real_T c17_t122;
  real_T c17_t123;
  real_T c17_t124;
  real_T c17_t125;
  real_T c17_t126;
  real_T c17_t190;
  real_T c17_t127;
  real_T c17_t128;
  real_T c17_t129;
  real_T c17_t130;
  real_T c17_t131;
  real_T c17_t215;
  real_T c17_t132;
  real_T c17_t133;
  real_T c17_t134;
  real_T c17_t135;
  real_T c17_t136;
  real_T c17_t137;
  real_T c17_t138;
  real_T c17_t216;
  real_T c17_t139;
  real_T c17_t140;
  real_T c17_t141;
  real_T c17_t142;
  real_T c17_t243;
  real_T c17_t143;
  real_T c17_t144;
  real_T c17_t145;
  real_T c17_t146;
  real_T c17_t147;
  real_T c17_t148;
  real_T c17_t149;
  real_T c17_t150;
  real_T c17_t151;
  real_T c17_t152;
  real_T c17_t153;
  real_T c17_t154;
  real_T c17_t221;
  real_T c17_t155;
  real_T c17_t156;
  real_T c17_t157;
  real_T c17_t220;
  real_T c17_t158;
  real_T c17_t159;
  real_T c17_t160;
  real_T c17_t218;
  real_T c17_t161;
  real_T c17_t162;
  real_T c17_t163;
  real_T c17_t165;
  real_T c17_t164;
  real_T c17_t171;
  real_T c17_t166;
  real_T c17_t167;
  real_T c17_t168;
  real_T c17_t169;
  real_T c17_t170;
  real_T c17_t172;
  real_T c17_t173;
  real_T c17_t224;
  real_T c17_t174;
  real_T c17_t184;
  real_T c17_t175;
  real_T c17_t176;
  real_T c17_t177;
  real_T c17_t178;
  real_T c17_t179;
  real_T c17_t180;
  real_T c17_t225;
  real_T c17_t226;
  real_T c17_t181;
  real_T c17_t182;
  real_T c17_t183;
  real_T c17_t185;
  real_T c17_t186;
  real_T c17_t187;
  real_T c17_t188;
  real_T c17_t189;
  real_T c17_t191;
  real_T c17_t192;
  real_T c17_t193;
  real_T c17_t194;
  real_T c17_t195;
  real_T c17_t196;
  real_T c17_t197;
  real_T c17_t198;
  real_T c17_t199;
  real_T c17_t200;
  real_T c17_t203;
  real_T c17_t242;
  real_T c17_t204;
  real_T c17_t205;
  real_T c17_t206;
  real_T c17_t207;
  real_T c17_t208;
  real_T c17_t209;
  real_T c17_t210;
  real_T c17_t211;
  real_T c17_t212;
  real_T c17_t240;
  real_T c17_t213;
  real_T c17_t214;
  real_T c17_t217;
  real_T c17_t222;
  real_T c17_t219;
  real_T c17_t241;
  real_T c17_t223;
  real_T c17_t227;
  real_T c17_t228;
  real_T c17_t236;
  real_T c17_t229;
  real_T c17_t230;
  real_T c17_t231;
  real_T c17_t232;
  real_T c17_t233;
  real_T c17_t234;
  real_T c17_t235;
  real_T c17_t237;
  real_T c17_t238;
  real_T c17_t239;
  real_T c17_t244;
  real_T c17_t245;
  real_T c17_t246;
  real_T c17_t247;
  real_T c17_t248;
  real_T c17_t250;
  real_T c17_t249;
  real_T c17_t251;
  real_T c17_t252;
  real_T c17_t253;
  real_T c17_t254;
  real_T c17_t319;
  real_T c17_t255;
  real_T c17_t256;
  real_T c17_t257;
  real_T c17_t258;
  real_T c17_t320;
  real_T c17_t321;
  real_T c17_t259;
  real_T c17_t260;
  real_T c17_t261;
  real_T c17_t331;
  real_T c17_t262;
  real_T c17_t263;
  real_T c17_t264;
  real_T c17_t265;
  real_T c17_t266;
  real_T c17_t267;
  real_T c17_t268;
  real_T c17_t269;
  real_T c17_t270;
  real_T c17_t271;
  real_T c17_t272;
  real_T c17_t273;
  real_T c17_t326;
  real_T c17_t327;
  real_T c17_t274;
  real_T c17_t275;
  real_T c17_t276;
  real_T c17_t277;
  real_T c17_t278;
  real_T c17_t279;
  real_T c17_t280;
  real_T c17_t281;
  real_T c17_t282;
  real_T c17_t283;
  real_T c17_t334;
  real_T c17_t335;
  real_T c17_t284;
  real_T c17_t285;
  real_T c17_t286;
  real_T c17_t332;
  real_T c17_t287;
  real_T c17_t288;
  real_T c17_t289;
  real_T c17_t290;
  real_T c17_t291;
  real_T c17_t337;
  real_T c17_t292;
  real_T c17_t293;
  real_T c17_t294;
  real_T c17_t295;
  real_T c17_t296;
  real_T c17_t297;
  real_T c17_t298;
  real_T c17_t299;
  real_T c17_t300;
  real_T c17_t301;
  real_T c17_t302;
  real_T c17_t338;
  real_T c17_t303;
  real_T c17_t304;
  real_T c17_t305;
  real_T c17_t342;
  real_T c17_t306;
  real_T c17_t307;
  real_T c17_t308;
  real_T c17_t309;
  real_T c17_t340;
  real_T c17_t341;
  real_T c17_t310;
  real_T c17_t311;
  real_T c17_t312;
  real_T c17_t313;
  real_T c17_t343;
  real_T c17_t344;
  real_T c17_t314;
  real_T c17_t315;
  real_T c17_t316;
  real_T c17_t317;
  real_T c17_t318;
  real_T c17_t322;
  real_T c17_t323;
  real_T c17_t324;
  real_T c17_t325;
  real_T c17_t328;
  real_T c17_t329;
  real_T c17_t349;
  real_T c17_t330;
  real_T c17_t350;
  real_T c17_t333;
  real_T c17_t336;
  real_T c17_t339;
  real_T c17_t345;
  real_T c17_t346;
  real_T c17_t347;
  real_T c17_t348;
  real_T c17_t351;
  real_T c17_t352;
  real_T c17_t353;
  real_T c17_t354;
  real_T c17_t381;
  real_T c17_t355;
  real_T c17_t356;
  real_T c17_t357;
  real_T c17_t358;
  real_T c17_t359;
  real_T c17_t360;
  real_T c17_t361;
  real_T c17_t362;
  real_T c17_t363;
  real_T c17_t364;
  real_T c17_t365;
  real_T c17_t366;
  real_T c17_t367;
  real_T c17_t368;
  real_T c17_t369;
  real_T c17_t370;
  real_T c17_t371;
  real_T c17_t372;
  real_T c17_t373;
  real_T c17_t374;
  real_T c17_t375;
  real_T c17_t386;
  real_T c17_t376;
  real_T c17_t387;
  real_T c17_t377;
  real_T c17_t378;
  real_T c17_t379;
  real_T c17_t380;
  real_T c17_t382;
  real_T c17_t383;
  real_T c17_t384;
  real_T c17_t385;
  real_T c17_t395;
  real_T c17_t388;
  real_T c17_t389;
  real_T c17_t390;
  real_T c17_t391;
  real_T c17_t400;
  real_T c17_t392;
  real_T c17_t393;
  real_T c17_t394;
  real_T c17_t396;
  real_T c17_t397;
  real_T c17_t398;
  real_T c17_t399;
  real_T c17_t401;
  real_T c17_t402;
  real_T c17_t403;
  real_T c17_t404;
  real_T c17_t405;
  real_T c17_t406;
  real_T c17_t407;
  real_T c17_t408;
  real_T c17_t409;
  real_T c17_t410;
  real_T c17_t411;
  real_T c17_t412;
  real_T c17_t413;
  real_T c17_t414;
  real_T c17_t415;
  real_T c17_t435;
  real_T c17_t416;
  real_T c17_t417;
  real_T c17_t418;
  real_T c17_t419;
  real_T c17_t420;
  real_T c17_t421;
  real_T c17_t422;
  real_T c17_t423;
  real_T c17_t424;
  real_T c17_t425;
  real_T c17_t426;
  real_T c17_t427;
  real_T c17_t428;
  real_T c17_t429;
  real_T c17_t430;
  real_T c17_t438;
  real_T c17_t431;
  real_T c17_t432;
  real_T c17_t433;
  real_T c17_t434;
  real_T c17_t436;
  real_T c17_t437;
  real_T c17_t439;
  real_T c17_t440;
  real_T c17_t446;
  real_T c17_t441;
  real_T c17_t442;
  real_T c17_t447;
  real_T c17_t443;
  real_T c17_t444;
  real_T c17_t452;
  real_T c17_t453;
  real_T c17_t445;
  real_T c17_t451;
  real_T c17_t454;
  real_T c17_t448;
  real_T c17_t449;
  real_T c17_t450;
  real_T c17_t455;
  real_T c17_nargin = 10.0;
  real_T c17_nargout = 1.0;
  real_T c17_x;
  real_T c17_b_x;
  real_T c17_c_x;
  real_T c17_d_x;
  real_T c17_e_x;
  real_T c17_f_x;
  real_T c17_g_x;
  real_T c17_h_x;
  real_T c17_i_x;
  real_T c17_j_x;
  real_T c17_k_x;
  real_T c17_l_x;
  real_T c17_m_x;
  real_T c17_n_x;
  real_T c17_o_x;
  real_T c17_p_x;
  real_T c17_q_x;
  real_T c17_r_x;
  real_T c17_s_x;
  real_T c17_t_x;
  real_T c17_u_x;
  real_T c17_v_x;
  real_T c17_w_x;
  real_T c17_x_x;
  real_T c17_d0;
  real_T c17_d1;
  real_T c17_d2;
  real_T c17_d3;
  real_T c17_y_x[36];
  int32_T c17_k;
  int32_T c17_b_k;
  sf_debug_symbol_scope_push_eml(0U, 548U, 548U, c17_b_debug_family_names,
    c17_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c17_Cx1, c17_c_sf_marshall, 0U);
  sf_debug_symbol_scope_add_eml(&c17_Cx2, c17_c_sf_marshall, 1U);
  sf_debug_symbol_scope_add_eml(&c17_Cx3, c17_c_sf_marshall, 2U);
  sf_debug_symbol_scope_add_eml(&c17_Cx4, c17_c_sf_marshall, 3U);
  sf_debug_symbol_scope_add_eml(&c17_Cx5, c17_c_sf_marshall, 4U);
  sf_debug_symbol_scope_add_eml(&c17_Cx6, c17_c_sf_marshall, 5U);
  sf_debug_symbol_scope_add_eml(&c17_Cy1, c17_c_sf_marshall, 6U);
  sf_debug_symbol_scope_add_eml(&c17_Cy2, c17_c_sf_marshall, 7U);
  sf_debug_symbol_scope_add_eml(&c17_Cy3, c17_c_sf_marshall, 8U);
  sf_debug_symbol_scope_add_eml(&c17_Cy4, c17_c_sf_marshall, 9U);
  sf_debug_symbol_scope_add_eml(&c17_Cy5, c17_c_sf_marshall, 10U);
  sf_debug_symbol_scope_add_eml(&c17_Cy6, c17_c_sf_marshall, 11U);
  sf_debug_symbol_scope_add_eml(&c17_Cz2, c17_c_sf_marshall, 12U);
  sf_debug_symbol_scope_add_eml(&c17_Cz3, c17_c_sf_marshall, 13U);
  sf_debug_symbol_scope_add_eml(&c17_Cz4, c17_c_sf_marshall, 14U);
  sf_debug_symbol_scope_add_eml(&c17_Cz5, c17_c_sf_marshall, 15U);
  sf_debug_symbol_scope_add_eml(&c17_Cz6, c17_c_sf_marshall, 16U);
  sf_debug_symbol_scope_add_eml(&c17_I1_33, c17_c_sf_marshall, 17U);
  sf_debug_symbol_scope_add_eml(&c17_I2_11, c17_c_sf_marshall, 18U);
  sf_debug_symbol_scope_add_eml(&c17_I2_12, c17_c_sf_marshall, 19U);
  sf_debug_symbol_scope_add_eml(&c17_I2_21, c17_c_sf_marshall, 20U);
  sf_debug_symbol_scope_add_eml(&c17_I2_13, c17_c_sf_marshall, 21U);
  sf_debug_symbol_scope_add_eml(&c17_I2_22, c17_c_sf_marshall, 22U);
  sf_debug_symbol_scope_add_eml(&c17_I2_31, c17_c_sf_marshall, 23U);
  sf_debug_symbol_scope_add_eml(&c17_I2_23, c17_c_sf_marshall, 24U);
  sf_debug_symbol_scope_add_eml(&c17_I2_32, c17_c_sf_marshall, 25U);
  sf_debug_symbol_scope_add_eml(&c17_I2_33, c17_c_sf_marshall, 26U);
  sf_debug_symbol_scope_add_eml(&c17_I3_11, c17_c_sf_marshall, 27U);
  sf_debug_symbol_scope_add_eml(&c17_I3_12, c17_c_sf_marshall, 28U);
  sf_debug_symbol_scope_add_eml(&c17_I3_21, c17_c_sf_marshall, 29U);
  sf_debug_symbol_scope_add_eml(&c17_I3_13, c17_c_sf_marshall, 30U);
  sf_debug_symbol_scope_add_eml(&c17_I3_22, c17_c_sf_marshall, 31U);
  sf_debug_symbol_scope_add_eml(&c17_I3_31, c17_c_sf_marshall, 32U);
  sf_debug_symbol_scope_add_eml(&c17_I3_23, c17_c_sf_marshall, 33U);
  sf_debug_symbol_scope_add_eml(&c17_I3_32, c17_c_sf_marshall, 34U);
  sf_debug_symbol_scope_add_eml(&c17_I3_33, c17_c_sf_marshall, 35U);
  sf_debug_symbol_scope_add_eml(&c17_I4_11, c17_c_sf_marshall, 36U);
  sf_debug_symbol_scope_add_eml(&c17_I4_12, c17_c_sf_marshall, 37U);
  sf_debug_symbol_scope_add_eml(&c17_I4_21, c17_c_sf_marshall, 38U);
  sf_debug_symbol_scope_add_eml(&c17_I4_13, c17_c_sf_marshall, 39U);
  sf_debug_symbol_scope_add_eml(&c17_I4_22, c17_c_sf_marshall, 40U);
  sf_debug_symbol_scope_add_eml(&c17_I4_31, c17_c_sf_marshall, 41U);
  sf_debug_symbol_scope_add_eml(&c17_I4_23, c17_c_sf_marshall, 42U);
  sf_debug_symbol_scope_add_eml(&c17_I4_32, c17_c_sf_marshall, 43U);
  sf_debug_symbol_scope_add_eml(&c17_I4_33, c17_c_sf_marshall, 44U);
  sf_debug_symbol_scope_add_eml(&c17_I5_11, c17_c_sf_marshall, 45U);
  sf_debug_symbol_scope_add_eml(&c17_I5_12, c17_c_sf_marshall, 46U);
  sf_debug_symbol_scope_add_eml(&c17_I5_21, c17_c_sf_marshall, 47U);
  sf_debug_symbol_scope_add_eml(&c17_I5_13, c17_c_sf_marshall, 48U);
  sf_debug_symbol_scope_add_eml(&c17_I5_22, c17_c_sf_marshall, 49U);
  sf_debug_symbol_scope_add_eml(&c17_I5_31, c17_c_sf_marshall, 50U);
  sf_debug_symbol_scope_add_eml(&c17_I5_23, c17_c_sf_marshall, 51U);
  sf_debug_symbol_scope_add_eml(&c17_I5_32, c17_c_sf_marshall, 52U);
  sf_debug_symbol_scope_add_eml(&c17_I5_33, c17_c_sf_marshall, 53U);
  sf_debug_symbol_scope_add_eml(&c17_I6_11, c17_c_sf_marshall, 54U);
  sf_debug_symbol_scope_add_eml(&c17_I6_12, c17_c_sf_marshall, 55U);
  sf_debug_symbol_scope_add_eml(&c17_I6_21, c17_c_sf_marshall, 56U);
  sf_debug_symbol_scope_add_eml(&c17_I6_13, c17_c_sf_marshall, 57U);
  sf_debug_symbol_scope_add_eml(&c17_I6_22, c17_c_sf_marshall, 58U);
  sf_debug_symbol_scope_add_eml(&c17_I6_31, c17_c_sf_marshall, 59U);
  sf_debug_symbol_scope_add_eml(&c17_I6_23, c17_c_sf_marshall, 60U);
  sf_debug_symbol_scope_add_eml(&c17_I6_32, c17_c_sf_marshall, 61U);
  sf_debug_symbol_scope_add_eml(&c17_I6_33, c17_c_sf_marshall, 62U);
  sf_debug_symbol_scope_add_eml(&c17_Ld1, c17_c_sf_marshall, 63U);
  sf_debug_symbol_scope_add_eml(&c17_Ld2, c17_c_sf_marshall, 64U);
  sf_debug_symbol_scope_add_eml(&c17_Ld3, c17_c_sf_marshall, 65U);
  sf_debug_symbol_scope_add_eml(&c17_Ld4, c17_c_sf_marshall, 66U);
  sf_debug_symbol_scope_add_eml(&c17_Ld5, c17_c_sf_marshall, 67U);
  sf_debug_symbol_scope_add_eml(&c17_Ld6, c17_c_sf_marshall, 68U);
  sf_debug_symbol_scope_add_eml(&c17_Ld7, c17_c_sf_marshall, 69U);
  sf_debug_symbol_scope_add_eml(&c17_Ma1, c17_c_sf_marshall, 70U);
  sf_debug_symbol_scope_add_eml(&c17_Ma2, c17_c_sf_marshall, 71U);
  sf_debug_symbol_scope_add_eml(&c17_Ma3, c17_c_sf_marshall, 72U);
  sf_debug_symbol_scope_add_eml(&c17_Ma4, c17_c_sf_marshall, 73U);
  sf_debug_symbol_scope_add_eml(&c17_Ma5, c17_c_sf_marshall, 74U);
  sf_debug_symbol_scope_add_eml(&c17_Ma6, c17_c_sf_marshall, 75U);
  sf_debug_symbol_scope_add_eml(&c17_pos2, c17_c_sf_marshall, 76U);
  sf_debug_symbol_scope_add_eml(&c17_pos3, c17_c_sf_marshall, 77U);
  sf_debug_symbol_scope_add_eml(&c17_pos4, c17_c_sf_marshall, 78U);
  sf_debug_symbol_scope_add_eml(&c17_pos5, c17_c_sf_marshall, 79U);
  sf_debug_symbol_scope_add_eml(&c17_pos6, c17_c_sf_marshall, 80U);
  sf_debug_symbol_scope_add_eml(&c17_t2, c17_c_sf_marshall, 81U);
  sf_debug_symbol_scope_add_eml(&c17_t3, c17_c_sf_marshall, 82U);
  sf_debug_symbol_scope_add_eml(&c17_t4, c17_c_sf_marshall, 83U);
  sf_debug_symbol_scope_add_eml(&c17_t5, c17_c_sf_marshall, 84U);
  sf_debug_symbol_scope_add_eml(&c17_t6, c17_c_sf_marshall, 85U);
  sf_debug_symbol_scope_add_eml(&c17_t7, c17_c_sf_marshall, 86U);
  sf_debug_symbol_scope_add_eml(&c17_t8, c17_c_sf_marshall, 87U);
  sf_debug_symbol_scope_add_eml(&c17_t22, c17_c_sf_marshall, 88U);
  sf_debug_symbol_scope_add_eml(&c17_t9, c17_c_sf_marshall, 89U);
  sf_debug_symbol_scope_add_eml(&c17_t10, c17_c_sf_marshall, 90U);
  sf_debug_symbol_scope_add_eml(&c17_t11, c17_c_sf_marshall, 91U);
  sf_debug_symbol_scope_add_eml(&c17_t12, c17_c_sf_marshall, 92U);
  sf_debug_symbol_scope_add_eml(&c17_t13, c17_c_sf_marshall, 93U);
  sf_debug_symbol_scope_add_eml(&c17_t14, c17_c_sf_marshall, 94U);
  sf_debug_symbol_scope_add_eml(&c17_t15, c17_c_sf_marshall, 95U);
  sf_debug_symbol_scope_add_eml(&c17_t16, c17_c_sf_marshall, 96U);
  sf_debug_symbol_scope_add_eml(&c17_t17, c17_c_sf_marshall, 97U);
  sf_debug_symbol_scope_add_eml(&c17_t18, c17_c_sf_marshall, 98U);
  sf_debug_symbol_scope_add_eml(&c17_t19, c17_c_sf_marshall, 99U);
  sf_debug_symbol_scope_add_eml(&c17_t20, c17_c_sf_marshall, 100U);
  sf_debug_symbol_scope_add_eml(&c17_t21, c17_c_sf_marshall, 101U);
  sf_debug_symbol_scope_add_eml(&c17_t23, c17_c_sf_marshall, 102U);
  sf_debug_symbol_scope_add_eml(&c17_t24, c17_c_sf_marshall, 103U);
  sf_debug_symbol_scope_add_eml(&c17_t25, c17_c_sf_marshall, 104U);
  sf_debug_symbol_scope_add_eml(&c17_t26, c17_c_sf_marshall, 105U);
  sf_debug_symbol_scope_add_eml(&c17_t27, c17_c_sf_marshall, 106U);
  sf_debug_symbol_scope_add_eml(&c17_t28, c17_c_sf_marshall, 107U);
  sf_debug_symbol_scope_add_eml(&c17_t29, c17_c_sf_marshall, 108U);
  sf_debug_symbol_scope_add_eml(&c17_t30, c17_c_sf_marshall, 109U);
  sf_debug_symbol_scope_add_eml(&c17_t31, c17_c_sf_marshall, 110U);
  sf_debug_symbol_scope_add_eml(&c17_t32, c17_c_sf_marshall, 111U);
  sf_debug_symbol_scope_add_eml(&c17_t33, c17_c_sf_marshall, 112U);
  sf_debug_symbol_scope_add_eml(&c17_t41, c17_c_sf_marshall, 113U);
  sf_debug_symbol_scope_add_eml(&c17_t34, c17_c_sf_marshall, 114U);
  sf_debug_symbol_scope_add_eml(&c17_t35, c17_c_sf_marshall, 115U);
  sf_debug_symbol_scope_add_eml(&c17_t42, c17_c_sf_marshall, 116U);
  sf_debug_symbol_scope_add_eml(&c17_t36, c17_c_sf_marshall, 117U);
  sf_debug_symbol_scope_add_eml(&c17_t37, c17_c_sf_marshall, 118U);
  sf_debug_symbol_scope_add_eml(&c17_t38, c17_c_sf_marshall, 119U);
  sf_debug_symbol_scope_add_eml(&c17_t39, c17_c_sf_marshall, 120U);
  sf_debug_symbol_scope_add_eml(&c17_t40, c17_c_sf_marshall, 121U);
  sf_debug_symbol_scope_add_eml(&c17_t43, c17_c_sf_marshall, 122U);
  sf_debug_symbol_scope_add_eml(&c17_t44, c17_c_sf_marshall, 123U);
  sf_debug_symbol_scope_add_eml(&c17_t45, c17_c_sf_marshall, 124U);
  sf_debug_symbol_scope_add_eml(&c17_t47, c17_c_sf_marshall, 125U);
  sf_debug_symbol_scope_add_eml(&c17_t46, c17_c_sf_marshall, 126U);
  sf_debug_symbol_scope_add_eml(&c17_t48, c17_c_sf_marshall, 127U);
  sf_debug_symbol_scope_add_eml(&c17_t49, c17_c_sf_marshall, 128U);
  sf_debug_symbol_scope_add_eml(&c17_t51, c17_c_sf_marshall, 129U);
  sf_debug_symbol_scope_add_eml(&c17_t50, c17_c_sf_marshall, 130U);
  sf_debug_symbol_scope_add_eml(&c17_t52, c17_c_sf_marshall, 131U);
  sf_debug_symbol_scope_add_eml(&c17_t53, c17_c_sf_marshall, 132U);
  sf_debug_symbol_scope_add_eml(&c17_t54, c17_c_sf_marshall, 133U);
  sf_debug_symbol_scope_add_eml(&c17_t55, c17_c_sf_marshall, 134U);
  sf_debug_symbol_scope_add_eml(&c17_t56, c17_c_sf_marshall, 135U);
  sf_debug_symbol_scope_add_eml(&c17_t57, c17_c_sf_marshall, 136U);
  sf_debug_symbol_scope_add_eml(&c17_t58, c17_c_sf_marshall, 137U);
  sf_debug_symbol_scope_add_eml(&c17_t59, c17_c_sf_marshall, 138U);
  sf_debug_symbol_scope_add_eml(&c17_t60, c17_c_sf_marshall, 139U);
  sf_debug_symbol_scope_add_eml(&c17_t61, c17_c_sf_marshall, 140U);
  sf_debug_symbol_scope_add_eml(&c17_t62, c17_c_sf_marshall, 141U);
  sf_debug_symbol_scope_add_eml(&c17_t63, c17_c_sf_marshall, 142U);
  sf_debug_symbol_scope_add_eml(&c17_t64, c17_c_sf_marshall, 143U);
  sf_debug_symbol_scope_add_eml(&c17_t65, c17_c_sf_marshall, 144U);
  sf_debug_symbol_scope_add_eml(&c17_t66, c17_c_sf_marshall, 145U);
  sf_debug_symbol_scope_add_eml(&c17_t67, c17_c_sf_marshall, 146U);
  sf_debug_symbol_scope_add_eml(&c17_t68, c17_c_sf_marshall, 147U);
  sf_debug_symbol_scope_add_eml(&c17_t69, c17_c_sf_marshall, 148U);
  sf_debug_symbol_scope_add_eml(&c17_t70, c17_c_sf_marshall, 149U);
  sf_debug_symbol_scope_add_eml(&c17_t71, c17_c_sf_marshall, 150U);
  sf_debug_symbol_scope_add_eml(&c17_t72, c17_c_sf_marshall, 151U);
  sf_debug_symbol_scope_add_eml(&c17_t73, c17_c_sf_marshall, 152U);
  sf_debug_symbol_scope_add_eml(&c17_t74, c17_c_sf_marshall, 153U);
  sf_debug_symbol_scope_add_eml(&c17_t75, c17_c_sf_marshall, 154U);
  sf_debug_symbol_scope_add_eml(&c17_t76, c17_c_sf_marshall, 155U);
  sf_debug_symbol_scope_add_eml(&c17_t77, c17_c_sf_marshall, 156U);
  sf_debug_symbol_scope_add_eml(&c17_t78, c17_c_sf_marshall, 157U);
  sf_debug_symbol_scope_add_eml(&c17_t79, c17_c_sf_marshall, 158U);
  sf_debug_symbol_scope_add_eml(&c17_t80, c17_c_sf_marshall, 159U);
  sf_debug_symbol_scope_add_eml(&c17_t81, c17_c_sf_marshall, 160U);
  sf_debug_symbol_scope_add_eml(&c17_t82, c17_c_sf_marshall, 161U);
  sf_debug_symbol_scope_add_eml(&c17_t83, c17_c_sf_marshall, 162U);
  sf_debug_symbol_scope_add_eml(&c17_t84, c17_c_sf_marshall, 163U);
  sf_debug_symbol_scope_add_eml(&c17_t85, c17_c_sf_marshall, 164U);
  sf_debug_symbol_scope_add_eml(&c17_t86, c17_c_sf_marshall, 165U);
  sf_debug_symbol_scope_add_eml(&c17_t87, c17_c_sf_marshall, 166U);
  sf_debug_symbol_scope_add_eml(&c17_t88, c17_c_sf_marshall, 167U);
  sf_debug_symbol_scope_add_eml(&c17_t89, c17_c_sf_marshall, 168U);
  sf_debug_symbol_scope_add_eml(&c17_t90, c17_c_sf_marshall, 169U);
  sf_debug_symbol_scope_add_eml(&c17_t91, c17_c_sf_marshall, 170U);
  sf_debug_symbol_scope_add_eml(&c17_t92, c17_c_sf_marshall, 171U);
  sf_debug_symbol_scope_add_eml(&c17_t93, c17_c_sf_marshall, 172U);
  sf_debug_symbol_scope_add_eml(&c17_t94, c17_c_sf_marshall, 173U);
  sf_debug_symbol_scope_add_eml(&c17_t95, c17_c_sf_marshall, 174U);
  sf_debug_symbol_scope_add_eml(&c17_t96, c17_c_sf_marshall, 175U);
  sf_debug_symbol_scope_add_eml(&c17_t97, c17_c_sf_marshall, 176U);
  sf_debug_symbol_scope_add_eml(&c17_t98, c17_c_sf_marshall, 177U);
  sf_debug_symbol_scope_add_eml(&c17_t99, c17_c_sf_marshall, 178U);
  sf_debug_symbol_scope_add_eml(&c17_t100, c17_c_sf_marshall, 179U);
  sf_debug_symbol_scope_add_eml(&c17_t101, c17_c_sf_marshall, 180U);
  sf_debug_symbol_scope_add_eml(&c17_t102, c17_c_sf_marshall, 181U);
  sf_debug_symbol_scope_add_eml(&c17_t103, c17_c_sf_marshall, 182U);
  sf_debug_symbol_scope_add_eml(&c17_t104, c17_c_sf_marshall, 183U);
  sf_debug_symbol_scope_add_eml(&c17_t105, c17_c_sf_marshall, 184U);
  sf_debug_symbol_scope_add_eml(&c17_t106, c17_c_sf_marshall, 185U);
  sf_debug_symbol_scope_add_eml(&c17_t107, c17_c_sf_marshall, 186U);
  sf_debug_symbol_scope_add_eml(&c17_t108, c17_c_sf_marshall, 187U);
  sf_debug_symbol_scope_add_eml(&c17_t202, c17_c_sf_marshall, 188U);
  sf_debug_symbol_scope_add_eml(&c17_t109, c17_c_sf_marshall, 189U);
  sf_debug_symbol_scope_add_eml(&c17_t110, c17_c_sf_marshall, 190U);
  sf_debug_symbol_scope_add_eml(&c17_t111, c17_c_sf_marshall, 191U);
  sf_debug_symbol_scope_add_eml(&c17_t112, c17_c_sf_marshall, 192U);
  sf_debug_symbol_scope_add_eml(&c17_t113, c17_c_sf_marshall, 193U);
  sf_debug_symbol_scope_add_eml(&c17_t114, c17_c_sf_marshall, 194U);
  sf_debug_symbol_scope_add_eml(&c17_t201, c17_c_sf_marshall, 195U);
  sf_debug_symbol_scope_add_eml(&c17_t115, c17_c_sf_marshall, 196U);
  sf_debug_symbol_scope_add_eml(&c17_t116, c17_c_sf_marshall, 197U);
  sf_debug_symbol_scope_add_eml(&c17_t117, c17_c_sf_marshall, 198U);
  sf_debug_symbol_scope_add_eml(&c17_t118, c17_c_sf_marshall, 199U);
  sf_debug_symbol_scope_add_eml(&c17_t119, c17_c_sf_marshall, 200U);
  sf_debug_symbol_scope_add_eml(&c17_t120, c17_c_sf_marshall, 201U);
  sf_debug_symbol_scope_add_eml(&c17_t121, c17_c_sf_marshall, 202U);
  sf_debug_symbol_scope_add_eml(&c17_t122, c17_c_sf_marshall, 203U);
  sf_debug_symbol_scope_add_eml(&c17_t123, c17_c_sf_marshall, 204U);
  sf_debug_symbol_scope_add_eml(&c17_t124, c17_c_sf_marshall, 205U);
  sf_debug_symbol_scope_add_eml(&c17_t125, c17_c_sf_marshall, 206U);
  sf_debug_symbol_scope_add_eml(&c17_t126, c17_c_sf_marshall, 207U);
  sf_debug_symbol_scope_add_eml(&c17_t190, c17_c_sf_marshall, 208U);
  sf_debug_symbol_scope_add_eml(&c17_t127, c17_c_sf_marshall, 209U);
  sf_debug_symbol_scope_add_eml(&c17_t128, c17_c_sf_marshall, 210U);
  sf_debug_symbol_scope_add_eml(&c17_t129, c17_c_sf_marshall, 211U);
  sf_debug_symbol_scope_add_eml(&c17_t130, c17_c_sf_marshall, 212U);
  sf_debug_symbol_scope_add_eml(&c17_t131, c17_c_sf_marshall, 213U);
  sf_debug_symbol_scope_add_eml(&c17_t215, c17_c_sf_marshall, 214U);
  sf_debug_symbol_scope_add_eml(&c17_t132, c17_c_sf_marshall, 215U);
  sf_debug_symbol_scope_add_eml(&c17_t133, c17_c_sf_marshall, 216U);
  sf_debug_symbol_scope_add_eml(&c17_t134, c17_c_sf_marshall, 217U);
  sf_debug_symbol_scope_add_eml(&c17_t135, c17_c_sf_marshall, 218U);
  sf_debug_symbol_scope_add_eml(&c17_t136, c17_c_sf_marshall, 219U);
  sf_debug_symbol_scope_add_eml(&c17_t137, c17_c_sf_marshall, 220U);
  sf_debug_symbol_scope_add_eml(&c17_t138, c17_c_sf_marshall, 221U);
  sf_debug_symbol_scope_add_eml(&c17_t216, c17_c_sf_marshall, 222U);
  sf_debug_symbol_scope_add_eml(&c17_t139, c17_c_sf_marshall, 223U);
  sf_debug_symbol_scope_add_eml(&c17_t140, c17_c_sf_marshall, 224U);
  sf_debug_symbol_scope_add_eml(&c17_t141, c17_c_sf_marshall, 225U);
  sf_debug_symbol_scope_add_eml(&c17_t142, c17_c_sf_marshall, 226U);
  sf_debug_symbol_scope_add_eml(&c17_t243, c17_c_sf_marshall, 227U);
  sf_debug_symbol_scope_add_eml(&c17_t143, c17_c_sf_marshall, 228U);
  sf_debug_symbol_scope_add_eml(&c17_t144, c17_c_sf_marshall, 229U);
  sf_debug_symbol_scope_add_eml(&c17_t145, c17_c_sf_marshall, 230U);
  sf_debug_symbol_scope_add_eml(&c17_t146, c17_c_sf_marshall, 231U);
  sf_debug_symbol_scope_add_eml(&c17_t147, c17_c_sf_marshall, 232U);
  sf_debug_symbol_scope_add_eml(&c17_t148, c17_c_sf_marshall, 233U);
  sf_debug_symbol_scope_add_eml(&c17_t149, c17_c_sf_marshall, 234U);
  sf_debug_symbol_scope_add_eml(&c17_t150, c17_c_sf_marshall, 235U);
  sf_debug_symbol_scope_add_eml(&c17_t151, c17_c_sf_marshall, 236U);
  sf_debug_symbol_scope_add_eml(&c17_t152, c17_c_sf_marshall, 237U);
  sf_debug_symbol_scope_add_eml(&c17_t153, c17_c_sf_marshall, 238U);
  sf_debug_symbol_scope_add_eml(&c17_t154, c17_c_sf_marshall, 239U);
  sf_debug_symbol_scope_add_eml(&c17_t221, c17_c_sf_marshall, 240U);
  sf_debug_symbol_scope_add_eml(&c17_t155, c17_c_sf_marshall, 241U);
  sf_debug_symbol_scope_add_eml(&c17_t156, c17_c_sf_marshall, 242U);
  sf_debug_symbol_scope_add_eml(&c17_t157, c17_c_sf_marshall, 243U);
  sf_debug_symbol_scope_add_eml(&c17_t220, c17_c_sf_marshall, 244U);
  sf_debug_symbol_scope_add_eml(&c17_t158, c17_c_sf_marshall, 245U);
  sf_debug_symbol_scope_add_eml(&c17_t159, c17_c_sf_marshall, 246U);
  sf_debug_symbol_scope_add_eml(&c17_t160, c17_c_sf_marshall, 247U);
  sf_debug_symbol_scope_add_eml(&c17_t218, c17_c_sf_marshall, 248U);
  sf_debug_symbol_scope_add_eml(&c17_t161, c17_c_sf_marshall, 249U);
  sf_debug_symbol_scope_add_eml(&c17_t162, c17_c_sf_marshall, 250U);
  sf_debug_symbol_scope_add_eml(&c17_t163, c17_c_sf_marshall, 251U);
  sf_debug_symbol_scope_add_eml(&c17_t165, c17_c_sf_marshall, 252U);
  sf_debug_symbol_scope_add_eml(&c17_t164, c17_c_sf_marshall, 253U);
  sf_debug_symbol_scope_add_eml(&c17_t171, c17_c_sf_marshall, 254U);
  sf_debug_symbol_scope_add_eml(&c17_t166, c17_c_sf_marshall, 255U);
  sf_debug_symbol_scope_add_eml(&c17_t167, c17_c_sf_marshall, 256U);
  sf_debug_symbol_scope_add_eml(&c17_t168, c17_c_sf_marshall, 257U);
  sf_debug_symbol_scope_add_eml(&c17_t169, c17_c_sf_marshall, 258U);
  sf_debug_symbol_scope_add_eml(&c17_t170, c17_c_sf_marshall, 259U);
  sf_debug_symbol_scope_add_eml(&c17_t172, c17_c_sf_marshall, 260U);
  sf_debug_symbol_scope_add_eml(&c17_t173, c17_c_sf_marshall, 261U);
  sf_debug_symbol_scope_add_eml(&c17_t224, c17_c_sf_marshall, 262U);
  sf_debug_symbol_scope_add_eml(&c17_t174, c17_c_sf_marshall, 263U);
  sf_debug_symbol_scope_add_eml(&c17_t184, c17_c_sf_marshall, 264U);
  sf_debug_symbol_scope_add_eml(&c17_t175, c17_c_sf_marshall, 265U);
  sf_debug_symbol_scope_add_eml(&c17_t176, c17_c_sf_marshall, 266U);
  sf_debug_symbol_scope_add_eml(&c17_t177, c17_c_sf_marshall, 267U);
  sf_debug_symbol_scope_add_eml(&c17_t178, c17_c_sf_marshall, 268U);
  sf_debug_symbol_scope_add_eml(&c17_t179, c17_c_sf_marshall, 269U);
  sf_debug_symbol_scope_add_eml(&c17_t180, c17_c_sf_marshall, 270U);
  sf_debug_symbol_scope_add_eml(&c17_t225, c17_c_sf_marshall, 271U);
  sf_debug_symbol_scope_add_eml(&c17_t226, c17_c_sf_marshall, 272U);
  sf_debug_symbol_scope_add_eml(&c17_t181, c17_c_sf_marshall, 273U);
  sf_debug_symbol_scope_add_eml(&c17_t182, c17_c_sf_marshall, 274U);
  sf_debug_symbol_scope_add_eml(&c17_t183, c17_c_sf_marshall, 275U);
  sf_debug_symbol_scope_add_eml(&c17_t185, c17_c_sf_marshall, 276U);
  sf_debug_symbol_scope_add_eml(&c17_t186, c17_c_sf_marshall, 277U);
  sf_debug_symbol_scope_add_eml(&c17_t187, c17_c_sf_marshall, 278U);
  sf_debug_symbol_scope_add_eml(&c17_t188, c17_c_sf_marshall, 279U);
  sf_debug_symbol_scope_add_eml(&c17_t189, c17_c_sf_marshall, 280U);
  sf_debug_symbol_scope_add_eml(&c17_t191, c17_c_sf_marshall, 281U);
  sf_debug_symbol_scope_add_eml(&c17_t192, c17_c_sf_marshall, 282U);
  sf_debug_symbol_scope_add_eml(&c17_t193, c17_c_sf_marshall, 283U);
  sf_debug_symbol_scope_add_eml(&c17_t194, c17_c_sf_marshall, 284U);
  sf_debug_symbol_scope_add_eml(&c17_t195, c17_c_sf_marshall, 285U);
  sf_debug_symbol_scope_add_eml(&c17_t196, c17_c_sf_marshall, 286U);
  sf_debug_symbol_scope_add_eml(&c17_t197, c17_c_sf_marshall, 287U);
  sf_debug_symbol_scope_add_eml(&c17_t198, c17_c_sf_marshall, 288U);
  sf_debug_symbol_scope_add_eml(&c17_t199, c17_c_sf_marshall, 289U);
  sf_debug_symbol_scope_add_eml(&c17_t200, c17_c_sf_marshall, 290U);
  sf_debug_symbol_scope_add_eml(&c17_t203, c17_c_sf_marshall, 291U);
  sf_debug_symbol_scope_add_eml(&c17_t242, c17_c_sf_marshall, 292U);
  sf_debug_symbol_scope_add_eml(&c17_t204, c17_c_sf_marshall, 293U);
  sf_debug_symbol_scope_add_eml(&c17_t205, c17_c_sf_marshall, 294U);
  sf_debug_symbol_scope_add_eml(&c17_t206, c17_c_sf_marshall, 295U);
  sf_debug_symbol_scope_add_eml(&c17_t207, c17_c_sf_marshall, 296U);
  sf_debug_symbol_scope_add_eml(&c17_t208, c17_c_sf_marshall, 297U);
  sf_debug_symbol_scope_add_eml(&c17_t209, c17_c_sf_marshall, 298U);
  sf_debug_symbol_scope_add_eml(&c17_t210, c17_c_sf_marshall, 299U);
  sf_debug_symbol_scope_add_eml(&c17_t211, c17_c_sf_marshall, 300U);
  sf_debug_symbol_scope_add_eml(&c17_t212, c17_c_sf_marshall, 301U);
  sf_debug_symbol_scope_add_eml(&c17_t240, c17_c_sf_marshall, 302U);
  sf_debug_symbol_scope_add_eml(&c17_t213, c17_c_sf_marshall, 303U);
  sf_debug_symbol_scope_add_eml(&c17_t214, c17_c_sf_marshall, 304U);
  sf_debug_symbol_scope_add_eml(&c17_t217, c17_c_sf_marshall, 305U);
  sf_debug_symbol_scope_add_eml(&c17_t222, c17_c_sf_marshall, 306U);
  sf_debug_symbol_scope_add_eml(&c17_t219, c17_c_sf_marshall, 307U);
  sf_debug_symbol_scope_add_eml(&c17_t241, c17_c_sf_marshall, 308U);
  sf_debug_symbol_scope_add_eml(&c17_t223, c17_c_sf_marshall, 309U);
  sf_debug_symbol_scope_add_eml(&c17_t227, c17_c_sf_marshall, 310U);
  sf_debug_symbol_scope_add_eml(&c17_t228, c17_c_sf_marshall, 311U);
  sf_debug_symbol_scope_add_eml(&c17_t236, c17_c_sf_marshall, 312U);
  sf_debug_symbol_scope_add_eml(&c17_t229, c17_c_sf_marshall, 313U);
  sf_debug_symbol_scope_add_eml(&c17_t230, c17_c_sf_marshall, 314U);
  sf_debug_symbol_scope_add_eml(&c17_t231, c17_c_sf_marshall, 315U);
  sf_debug_symbol_scope_add_eml(&c17_t232, c17_c_sf_marshall, 316U);
  sf_debug_symbol_scope_add_eml(&c17_t233, c17_c_sf_marshall, 317U);
  sf_debug_symbol_scope_add_eml(&c17_t234, c17_c_sf_marshall, 318U);
  sf_debug_symbol_scope_add_eml(&c17_t235, c17_c_sf_marshall, 319U);
  sf_debug_symbol_scope_add_eml(&c17_t237, c17_c_sf_marshall, 320U);
  sf_debug_symbol_scope_add_eml(&c17_t238, c17_c_sf_marshall, 321U);
  sf_debug_symbol_scope_add_eml(&c17_t239, c17_c_sf_marshall, 322U);
  sf_debug_symbol_scope_add_eml(&c17_t244, c17_c_sf_marshall, 323U);
  sf_debug_symbol_scope_add_eml(&c17_t245, c17_c_sf_marshall, 324U);
  sf_debug_symbol_scope_add_eml(&c17_t246, c17_c_sf_marshall, 325U);
  sf_debug_symbol_scope_add_eml(&c17_t247, c17_c_sf_marshall, 326U);
  sf_debug_symbol_scope_add_eml(&c17_t248, c17_c_sf_marshall, 327U);
  sf_debug_symbol_scope_add_eml(&c17_t250, c17_c_sf_marshall, 328U);
  sf_debug_symbol_scope_add_eml(&c17_t249, c17_c_sf_marshall, 329U);
  sf_debug_symbol_scope_add_eml(&c17_t251, c17_c_sf_marshall, 330U);
  sf_debug_symbol_scope_add_eml(&c17_t252, c17_c_sf_marshall, 331U);
  sf_debug_symbol_scope_add_eml(&c17_t253, c17_c_sf_marshall, 332U);
  sf_debug_symbol_scope_add_eml(&c17_t254, c17_c_sf_marshall, 333U);
  sf_debug_symbol_scope_add_eml(&c17_t319, c17_c_sf_marshall, 334U);
  sf_debug_symbol_scope_add_eml(&c17_t255, c17_c_sf_marshall, 335U);
  sf_debug_symbol_scope_add_eml(&c17_t256, c17_c_sf_marshall, 336U);
  sf_debug_symbol_scope_add_eml(&c17_t257, c17_c_sf_marshall, 337U);
  sf_debug_symbol_scope_add_eml(&c17_t258, c17_c_sf_marshall, 338U);
  sf_debug_symbol_scope_add_eml(&c17_t320, c17_c_sf_marshall, 339U);
  sf_debug_symbol_scope_add_eml(&c17_t321, c17_c_sf_marshall, 340U);
  sf_debug_symbol_scope_add_eml(&c17_t259, c17_c_sf_marshall, 341U);
  sf_debug_symbol_scope_add_eml(&c17_t260, c17_c_sf_marshall, 342U);
  sf_debug_symbol_scope_add_eml(&c17_t261, c17_c_sf_marshall, 343U);
  sf_debug_symbol_scope_add_eml(&c17_t331, c17_c_sf_marshall, 344U);
  sf_debug_symbol_scope_add_eml(&c17_t262, c17_c_sf_marshall, 345U);
  sf_debug_symbol_scope_add_eml(&c17_t263, c17_c_sf_marshall, 346U);
  sf_debug_symbol_scope_add_eml(&c17_t264, c17_c_sf_marshall, 347U);
  sf_debug_symbol_scope_add_eml(&c17_t265, c17_c_sf_marshall, 348U);
  sf_debug_symbol_scope_add_eml(&c17_t266, c17_c_sf_marshall, 349U);
  sf_debug_symbol_scope_add_eml(&c17_t267, c17_c_sf_marshall, 350U);
  sf_debug_symbol_scope_add_eml(&c17_t268, c17_c_sf_marshall, 351U);
  sf_debug_symbol_scope_add_eml(&c17_t269, c17_c_sf_marshall, 352U);
  sf_debug_symbol_scope_add_eml(&c17_t270, c17_c_sf_marshall, 353U);
  sf_debug_symbol_scope_add_eml(&c17_t271, c17_c_sf_marshall, 354U);
  sf_debug_symbol_scope_add_eml(&c17_t272, c17_c_sf_marshall, 355U);
  sf_debug_symbol_scope_add_eml(&c17_t273, c17_c_sf_marshall, 356U);
  sf_debug_symbol_scope_add_eml(&c17_t326, c17_c_sf_marshall, 357U);
  sf_debug_symbol_scope_add_eml(&c17_t327, c17_c_sf_marshall, 358U);
  sf_debug_symbol_scope_add_eml(&c17_t274, c17_c_sf_marshall, 359U);
  sf_debug_symbol_scope_add_eml(&c17_t275, c17_c_sf_marshall, 360U);
  sf_debug_symbol_scope_add_eml(&c17_t276, c17_c_sf_marshall, 361U);
  sf_debug_symbol_scope_add_eml(&c17_t277, c17_c_sf_marshall, 362U);
  sf_debug_symbol_scope_add_eml(&c17_t278, c17_c_sf_marshall, 363U);
  sf_debug_symbol_scope_add_eml(&c17_t279, c17_c_sf_marshall, 364U);
  sf_debug_symbol_scope_add_eml(&c17_t280, c17_c_sf_marshall, 365U);
  sf_debug_symbol_scope_add_eml(&c17_t281, c17_c_sf_marshall, 366U);
  sf_debug_symbol_scope_add_eml(&c17_t282, c17_c_sf_marshall, 367U);
  sf_debug_symbol_scope_add_eml(&c17_t283, c17_c_sf_marshall, 368U);
  sf_debug_symbol_scope_add_eml(&c17_t334, c17_c_sf_marshall, 369U);
  sf_debug_symbol_scope_add_eml(&c17_t335, c17_c_sf_marshall, 370U);
  sf_debug_symbol_scope_add_eml(&c17_t284, c17_c_sf_marshall, 371U);
  sf_debug_symbol_scope_add_eml(&c17_t285, c17_c_sf_marshall, 372U);
  sf_debug_symbol_scope_add_eml(&c17_t286, c17_c_sf_marshall, 373U);
  sf_debug_symbol_scope_add_eml(&c17_t332, c17_c_sf_marshall, 374U);
  sf_debug_symbol_scope_add_eml(&c17_t287, c17_c_sf_marshall, 375U);
  sf_debug_symbol_scope_add_eml(&c17_t288, c17_c_sf_marshall, 376U);
  sf_debug_symbol_scope_add_eml(&c17_t289, c17_c_sf_marshall, 377U);
  sf_debug_symbol_scope_add_eml(&c17_t290, c17_c_sf_marshall, 378U);
  sf_debug_symbol_scope_add_eml(&c17_t291, c17_c_sf_marshall, 379U);
  sf_debug_symbol_scope_add_eml(&c17_t337, c17_c_sf_marshall, 380U);
  sf_debug_symbol_scope_add_eml(&c17_t292, c17_c_sf_marshall, 381U);
  sf_debug_symbol_scope_add_eml(&c17_t293, c17_c_sf_marshall, 382U);
  sf_debug_symbol_scope_add_eml(&c17_t294, c17_c_sf_marshall, 383U);
  sf_debug_symbol_scope_add_eml(&c17_t295, c17_c_sf_marshall, 384U);
  sf_debug_symbol_scope_add_eml(&c17_t296, c17_c_sf_marshall, 385U);
  sf_debug_symbol_scope_add_eml(&c17_t297, c17_c_sf_marshall, 386U);
  sf_debug_symbol_scope_add_eml(&c17_t298, c17_c_sf_marshall, 387U);
  sf_debug_symbol_scope_add_eml(&c17_t299, c17_c_sf_marshall, 388U);
  sf_debug_symbol_scope_add_eml(&c17_t300, c17_c_sf_marshall, 389U);
  sf_debug_symbol_scope_add_eml(&c17_t301, c17_c_sf_marshall, 390U);
  sf_debug_symbol_scope_add_eml(&c17_t302, c17_c_sf_marshall, 391U);
  sf_debug_symbol_scope_add_eml(&c17_t338, c17_c_sf_marshall, 392U);
  sf_debug_symbol_scope_add_eml(&c17_t303, c17_c_sf_marshall, 393U);
  sf_debug_symbol_scope_add_eml(&c17_t304, c17_c_sf_marshall, 394U);
  sf_debug_symbol_scope_add_eml(&c17_t305, c17_c_sf_marshall, 395U);
  sf_debug_symbol_scope_add_eml(&c17_t342, c17_c_sf_marshall, 396U);
  sf_debug_symbol_scope_add_eml(&c17_t306, c17_c_sf_marshall, 397U);
  sf_debug_symbol_scope_add_eml(&c17_t307, c17_c_sf_marshall, 398U);
  sf_debug_symbol_scope_add_eml(&c17_t308, c17_c_sf_marshall, 399U);
  sf_debug_symbol_scope_add_eml(&c17_t309, c17_c_sf_marshall, 400U);
  sf_debug_symbol_scope_add_eml(&c17_t340, c17_c_sf_marshall, 401U);
  sf_debug_symbol_scope_add_eml(&c17_t341, c17_c_sf_marshall, 402U);
  sf_debug_symbol_scope_add_eml(&c17_t310, c17_c_sf_marshall, 403U);
  sf_debug_symbol_scope_add_eml(&c17_t311, c17_c_sf_marshall, 404U);
  sf_debug_symbol_scope_add_eml(&c17_t312, c17_c_sf_marshall, 405U);
  sf_debug_symbol_scope_add_eml(&c17_t313, c17_c_sf_marshall, 406U);
  sf_debug_symbol_scope_add_eml(&c17_t343, c17_c_sf_marshall, 407U);
  sf_debug_symbol_scope_add_eml(&c17_t344, c17_c_sf_marshall, 408U);
  sf_debug_symbol_scope_add_eml(&c17_t314, c17_c_sf_marshall, 409U);
  sf_debug_symbol_scope_add_eml(&c17_t315, c17_c_sf_marshall, 410U);
  sf_debug_symbol_scope_add_eml(&c17_t316, c17_c_sf_marshall, 411U);
  sf_debug_symbol_scope_add_eml(&c17_t317, c17_c_sf_marshall, 412U);
  sf_debug_symbol_scope_add_eml(&c17_t318, c17_c_sf_marshall, 413U);
  sf_debug_symbol_scope_add_eml(&c17_t322, c17_c_sf_marshall, 414U);
  sf_debug_symbol_scope_add_eml(&c17_t323, c17_c_sf_marshall, 415U);
  sf_debug_symbol_scope_add_eml(&c17_t324, c17_c_sf_marshall, 416U);
  sf_debug_symbol_scope_add_eml(&c17_t325, c17_c_sf_marshall, 417U);
  sf_debug_symbol_scope_add_eml(&c17_t328, c17_c_sf_marshall, 418U);
  sf_debug_symbol_scope_add_eml(&c17_t329, c17_c_sf_marshall, 419U);
  sf_debug_symbol_scope_add_eml(&c17_t349, c17_c_sf_marshall, 420U);
  sf_debug_symbol_scope_add_eml(&c17_t330, c17_c_sf_marshall, 421U);
  sf_debug_symbol_scope_add_eml(&c17_t350, c17_c_sf_marshall, 422U);
  sf_debug_symbol_scope_add_eml(&c17_t333, c17_c_sf_marshall, 423U);
  sf_debug_symbol_scope_add_eml(&c17_t336, c17_c_sf_marshall, 424U);
  sf_debug_symbol_scope_add_eml(&c17_t339, c17_c_sf_marshall, 425U);
  sf_debug_symbol_scope_add_eml(&c17_t345, c17_c_sf_marshall, 426U);
  sf_debug_symbol_scope_add_eml(&c17_t346, c17_c_sf_marshall, 427U);
  sf_debug_symbol_scope_add_eml(&c17_t347, c17_c_sf_marshall, 428U);
  sf_debug_symbol_scope_add_eml(&c17_t348, c17_c_sf_marshall, 429U);
  sf_debug_symbol_scope_add_eml(&c17_t351, c17_c_sf_marshall, 430U);
  sf_debug_symbol_scope_add_eml(&c17_t352, c17_c_sf_marshall, 431U);
  sf_debug_symbol_scope_add_eml(&c17_t353, c17_c_sf_marshall, 432U);
  sf_debug_symbol_scope_add_eml(&c17_t354, c17_c_sf_marshall, 433U);
  sf_debug_symbol_scope_add_eml(&c17_t381, c17_c_sf_marshall, 434U);
  sf_debug_symbol_scope_add_eml(&c17_t355, c17_c_sf_marshall, 435U);
  sf_debug_symbol_scope_add_eml(&c17_t356, c17_c_sf_marshall, 436U);
  sf_debug_symbol_scope_add_eml(&c17_t357, c17_c_sf_marshall, 437U);
  sf_debug_symbol_scope_add_eml(&c17_t358, c17_c_sf_marshall, 438U);
  sf_debug_symbol_scope_add_eml(&c17_t359, c17_c_sf_marshall, 439U);
  sf_debug_symbol_scope_add_eml(&c17_t360, c17_c_sf_marshall, 440U);
  sf_debug_symbol_scope_add_eml(&c17_t361, c17_c_sf_marshall, 441U);
  sf_debug_symbol_scope_add_eml(&c17_t362, c17_c_sf_marshall, 442U);
  sf_debug_symbol_scope_add_eml(&c17_t363, c17_c_sf_marshall, 443U);
  sf_debug_symbol_scope_add_eml(&c17_t364, c17_c_sf_marshall, 444U);
  sf_debug_symbol_scope_add_eml(&c17_t365, c17_c_sf_marshall, 445U);
  sf_debug_symbol_scope_add_eml(&c17_t366, c17_c_sf_marshall, 446U);
  sf_debug_symbol_scope_add_eml(&c17_t367, c17_c_sf_marshall, 447U);
  sf_debug_symbol_scope_add_eml(&c17_t368, c17_c_sf_marshall, 448U);
  sf_debug_symbol_scope_add_eml(&c17_t369, c17_c_sf_marshall, 449U);
  sf_debug_symbol_scope_add_eml(&c17_t370, c17_c_sf_marshall, 450U);
  sf_debug_symbol_scope_add_eml(&c17_t371, c17_c_sf_marshall, 451U);
  sf_debug_symbol_scope_add_eml(&c17_t372, c17_c_sf_marshall, 452U);
  sf_debug_symbol_scope_add_eml(&c17_t373, c17_c_sf_marshall, 453U);
  sf_debug_symbol_scope_add_eml(&c17_t374, c17_c_sf_marshall, 454U);
  sf_debug_symbol_scope_add_eml(&c17_t375, c17_c_sf_marshall, 455U);
  sf_debug_symbol_scope_add_eml(&c17_t386, c17_c_sf_marshall, 456U);
  sf_debug_symbol_scope_add_eml(&c17_t376, c17_c_sf_marshall, 457U);
  sf_debug_symbol_scope_add_eml(&c17_t387, c17_c_sf_marshall, 458U);
  sf_debug_symbol_scope_add_eml(&c17_t377, c17_c_sf_marshall, 459U);
  sf_debug_symbol_scope_add_eml(&c17_t378, c17_c_sf_marshall, 460U);
  sf_debug_symbol_scope_add_eml(&c17_t379, c17_c_sf_marshall, 461U);
  sf_debug_symbol_scope_add_eml(&c17_t380, c17_c_sf_marshall, 462U);
  sf_debug_symbol_scope_add_eml(&c17_t382, c17_c_sf_marshall, 463U);
  sf_debug_symbol_scope_add_eml(&c17_t383, c17_c_sf_marshall, 464U);
  sf_debug_symbol_scope_add_eml(&c17_t384, c17_c_sf_marshall, 465U);
  sf_debug_symbol_scope_add_eml(&c17_t385, c17_c_sf_marshall, 466U);
  sf_debug_symbol_scope_add_eml(&c17_t395, c17_c_sf_marshall, 467U);
  sf_debug_symbol_scope_add_eml(&c17_t388, c17_c_sf_marshall, 468U);
  sf_debug_symbol_scope_add_eml(&c17_t389, c17_c_sf_marshall, 469U);
  sf_debug_symbol_scope_add_eml(&c17_t390, c17_c_sf_marshall, 470U);
  sf_debug_symbol_scope_add_eml(&c17_t391, c17_c_sf_marshall, 471U);
  sf_debug_symbol_scope_add_eml(&c17_t400, c17_c_sf_marshall, 472U);
  sf_debug_symbol_scope_add_eml(&c17_t392, c17_c_sf_marshall, 473U);
  sf_debug_symbol_scope_add_eml(&c17_t393, c17_c_sf_marshall, 474U);
  sf_debug_symbol_scope_add_eml(&c17_t394, c17_c_sf_marshall, 475U);
  sf_debug_symbol_scope_add_eml(&c17_t396, c17_c_sf_marshall, 476U);
  sf_debug_symbol_scope_add_eml(&c17_t397, c17_c_sf_marshall, 477U);
  sf_debug_symbol_scope_add_eml(&c17_t398, c17_c_sf_marshall, 478U);
  sf_debug_symbol_scope_add_eml(&c17_t399, c17_c_sf_marshall, 479U);
  sf_debug_symbol_scope_add_eml(&c17_t401, c17_c_sf_marshall, 480U);
  sf_debug_symbol_scope_add_eml(&c17_t402, c17_c_sf_marshall, 481U);
  sf_debug_symbol_scope_add_eml(&c17_t403, c17_c_sf_marshall, 482U);
  sf_debug_symbol_scope_add_eml(&c17_t404, c17_c_sf_marshall, 483U);
  sf_debug_symbol_scope_add_eml(&c17_t405, c17_c_sf_marshall, 484U);
  sf_debug_symbol_scope_add_eml(&c17_t406, c17_c_sf_marshall, 485U);
  sf_debug_symbol_scope_add_eml(&c17_t407, c17_c_sf_marshall, 486U);
  sf_debug_symbol_scope_add_eml(&c17_t408, c17_c_sf_marshall, 487U);
  sf_debug_symbol_scope_add_eml(&c17_t409, c17_c_sf_marshall, 488U);
  sf_debug_symbol_scope_add_eml(&c17_t410, c17_c_sf_marshall, 489U);
  sf_debug_symbol_scope_add_eml(&c17_t411, c17_c_sf_marshall, 490U);
  sf_debug_symbol_scope_add_eml(&c17_t412, c17_c_sf_marshall, 491U);
  sf_debug_symbol_scope_add_eml(&c17_t413, c17_c_sf_marshall, 492U);
  sf_debug_symbol_scope_add_eml(&c17_t414, c17_c_sf_marshall, 493U);
  sf_debug_symbol_scope_add_eml(&c17_t415, c17_c_sf_marshall, 494U);
  sf_debug_symbol_scope_add_eml(&c17_t435, c17_c_sf_marshall, 495U);
  sf_debug_symbol_scope_add_eml(&c17_t416, c17_c_sf_marshall, 496U);
  sf_debug_symbol_scope_add_eml(&c17_t417, c17_c_sf_marshall, 497U);
  sf_debug_symbol_scope_add_eml(&c17_t418, c17_c_sf_marshall, 498U);
  sf_debug_symbol_scope_add_eml(&c17_t419, c17_c_sf_marshall, 499U);
  sf_debug_symbol_scope_add_eml(&c17_t420, c17_c_sf_marshall, 500U);
  sf_debug_symbol_scope_add_eml(&c17_t421, c17_c_sf_marshall, 501U);
  sf_debug_symbol_scope_add_eml(&c17_t422, c17_c_sf_marshall, 502U);
  sf_debug_symbol_scope_add_eml(&c17_t423, c17_c_sf_marshall, 503U);
  sf_debug_symbol_scope_add_eml(&c17_t424, c17_c_sf_marshall, 504U);
  sf_debug_symbol_scope_add_eml(&c17_t425, c17_c_sf_marshall, 505U);
  sf_debug_symbol_scope_add_eml(&c17_t426, c17_c_sf_marshall, 506U);
  sf_debug_symbol_scope_add_eml(&c17_t427, c17_c_sf_marshall, 507U);
  sf_debug_symbol_scope_add_eml(&c17_t428, c17_c_sf_marshall, 508U);
  sf_debug_symbol_scope_add_eml(&c17_t429, c17_c_sf_marshall, 509U);
  sf_debug_symbol_scope_add_eml(&c17_t430, c17_c_sf_marshall, 510U);
  sf_debug_symbol_scope_add_eml(&c17_t438, c17_c_sf_marshall, 511U);
  sf_debug_symbol_scope_add_eml(&c17_t431, c17_c_sf_marshall, 512U);
  sf_debug_symbol_scope_add_eml(&c17_t432, c17_c_sf_marshall, 513U);
  sf_debug_symbol_scope_add_eml(&c17_t433, c17_c_sf_marshall, 514U);
  sf_debug_symbol_scope_add_eml(&c17_t434, c17_c_sf_marshall, 515U);
  sf_debug_symbol_scope_add_eml(&c17_t436, c17_c_sf_marshall, 516U);
  sf_debug_symbol_scope_add_eml(&c17_t437, c17_c_sf_marshall, 517U);
  sf_debug_symbol_scope_add_eml(&c17_t439, c17_c_sf_marshall, 518U);
  sf_debug_symbol_scope_add_eml(&c17_t440, c17_c_sf_marshall, 519U);
  sf_debug_symbol_scope_add_eml(&c17_t446, c17_c_sf_marshall, 520U);
  sf_debug_symbol_scope_add_eml(&c17_t441, c17_c_sf_marshall, 521U);
  sf_debug_symbol_scope_add_eml(&c17_t442, c17_c_sf_marshall, 522U);
  sf_debug_symbol_scope_add_eml(&c17_t447, c17_c_sf_marshall, 523U);
  sf_debug_symbol_scope_add_eml(&c17_t443, c17_c_sf_marshall, 524U);
  sf_debug_symbol_scope_add_eml(&c17_t444, c17_c_sf_marshall, 525U);
  sf_debug_symbol_scope_add_eml(&c17_t452, c17_c_sf_marshall, 526U);
  sf_debug_symbol_scope_add_eml(&c17_t453, c17_c_sf_marshall, 527U);
  sf_debug_symbol_scope_add_eml(&c17_t445, c17_c_sf_marshall, 528U);
  sf_debug_symbol_scope_add_eml(&c17_t451, c17_c_sf_marshall, 529U);
  sf_debug_symbol_scope_add_eml(&c17_t454, c17_c_sf_marshall, 530U);
  sf_debug_symbol_scope_add_eml(&c17_t448, c17_c_sf_marshall, 531U);
  sf_debug_symbol_scope_add_eml(&c17_t449, c17_c_sf_marshall, 532U);
  sf_debug_symbol_scope_add_eml(&c17_t450, c17_c_sf_marshall, 533U);
  sf_debug_symbol_scope_add_eml(&c17_t455, c17_c_sf_marshall, 534U);
  sf_debug_symbol_scope_add_eml(&c17_nargin, c17_c_sf_marshall, 535U);
  sf_debug_symbol_scope_add_eml(&c17_nargout, c17_c_sf_marshall, 536U);
  sf_debug_symbol_scope_add_eml(c17_in1, c17_f_sf_marshall, 537U);
  sf_debug_symbol_scope_add_eml(c17_in2, c17_d_sf_marshall, 538U);
  sf_debug_symbol_scope_add_eml(c17_in3, c17_e_sf_marshall, 539U);
  sf_debug_symbol_scope_add_eml(c17_in4, c17_b_sf_marshall, 540U);
  sf_debug_symbol_scope_add_eml(c17_in5, c17_b_sf_marshall, 541U);
  sf_debug_symbol_scope_add_eml(c17_in6, c17_b_sf_marshall, 542U);
  sf_debug_symbol_scope_add_eml(c17_in7, c17_b_sf_marshall, 543U);
  sf_debug_symbol_scope_add_eml(c17_in8, c17_b_sf_marshall, 544U);
  sf_debug_symbol_scope_add_eml(c17_in9, c17_b_sf_marshall, 545U);
  sf_debug_symbol_scope_add_eml(c17_in10, c17_d_sf_marshall, 546U);
  sf_debug_symbol_scope_add_eml(c17_EulerMd_, c17_g_sf_marshall, 547U);
  CV_SCRIPT_FCN(0, 0);

  /* EULERMD */
  /*     EULERMD_ = EULERMD(IN1,IN2,IN3,IN4,IN5,IN6,IN7,IN8,IN9,IN10) */
  /*     This function was generated by the Symbolic Math Toolbox version 5.5. */
  /*     15-Aug-2014 16:04:03 */
  _SFD_SCRIPT_CALL(0, 8);
  c17_Cx1 = c17_in3[0];
  _SFD_SCRIPT_CALL(0, 9);
  c17_Cx2 = c17_in3[1];
  _SFD_SCRIPT_CALL(0, 10);
  c17_Cx3 = c17_in3[2];
  _SFD_SCRIPT_CALL(0, 11);
  c17_Cx4 = c17_in3[3];
  _SFD_SCRIPT_CALL(0, 12);
  c17_Cx5 = c17_in3[4];
  _SFD_SCRIPT_CALL(0, 13);
  c17_Cx6 = c17_in3[5];
  _SFD_SCRIPT_CALL(0, 14);
  c17_Cy1 = c17_in3[6];
  _SFD_SCRIPT_CALL(0, 15);
  c17_Cy2 = c17_in3[7];
  _SFD_SCRIPT_CALL(0, 16);
  c17_Cy3 = c17_in3[8];
  _SFD_SCRIPT_CALL(0, 17);
  c17_Cy4 = c17_in3[9];
  _SFD_SCRIPT_CALL(0, 18);
  c17_Cy5 = c17_in3[10];
  _SFD_SCRIPT_CALL(0, 19);
  c17_Cy6 = c17_in3[11];
  _SFD_SCRIPT_CALL(0, 20);
  c17_Cz2 = c17_in3[13];
  _SFD_SCRIPT_CALL(0, 21);
  c17_Cz3 = c17_in3[14];
  _SFD_SCRIPT_CALL(0, 22);
  c17_Cz4 = c17_in3[15];
  _SFD_SCRIPT_CALL(0, 23);
  c17_Cz5 = c17_in3[16];
  _SFD_SCRIPT_CALL(0, 24);
  c17_Cz6 = c17_in3[17];
  _SFD_SCRIPT_CALL(0, 25);
  c17_I1_33 = c17_in4[8];
  _SFD_SCRIPT_CALL(0, 26);
  c17_I2_11 = c17_in5[0];
  _SFD_SCRIPT_CALL(0, 27);
  c17_I2_12 = c17_in5[3];
  _SFD_SCRIPT_CALL(0, 28);
  c17_I2_21 = c17_in5[1];
  _SFD_SCRIPT_CALL(0, 29);
  c17_I2_13 = c17_in5[6];
  _SFD_SCRIPT_CALL(0, 30);
  c17_I2_22 = c17_in5[4];
  _SFD_SCRIPT_CALL(0, 31);
  c17_I2_31 = c17_in5[2];
  _SFD_SCRIPT_CALL(0, 32);
  c17_I2_23 = c17_in5[7];
  _SFD_SCRIPT_CALL(0, 33);
  c17_I2_32 = c17_in5[5];
  _SFD_SCRIPT_CALL(0, 34);
  c17_I2_33 = c17_in5[8];
  _SFD_SCRIPT_CALL(0, 35);
  c17_I3_11 = c17_in6[0];
  _SFD_SCRIPT_CALL(0, 36);
  c17_I3_12 = c17_in6[3];
  _SFD_SCRIPT_CALL(0, 37);
  c17_I3_21 = c17_in6[1];
  _SFD_SCRIPT_CALL(0, 38);
  c17_I3_13 = c17_in6[6];
  _SFD_SCRIPT_CALL(0, 39);
  c17_I3_22 = c17_in6[4];
  _SFD_SCRIPT_CALL(0, 40);
  c17_I3_31 = c17_in6[2];
  _SFD_SCRIPT_CALL(0, 41);
  c17_I3_23 = c17_in6[7];
  _SFD_SCRIPT_CALL(0, 42);
  c17_I3_32 = c17_in6[5];
  _SFD_SCRIPT_CALL(0, 43);
  c17_I3_33 = c17_in6[8];
  _SFD_SCRIPT_CALL(0, 44);
  c17_I4_11 = c17_in7[0];
  _SFD_SCRIPT_CALL(0, 45);
  c17_I4_12 = c17_in7[3];
  _SFD_SCRIPT_CALL(0, 46);
  c17_I4_21 = c17_in7[1];
  _SFD_SCRIPT_CALL(0, 47);
  c17_I4_13 = c17_in7[6];
  _SFD_SCRIPT_CALL(0, 48);
  c17_I4_22 = c17_in7[4];
  _SFD_SCRIPT_CALL(0, 49);
  c17_I4_31 = c17_in7[2];
  _SFD_SCRIPT_CALL(0, 50);
  c17_I4_23 = c17_in7[7];
  _SFD_SCRIPT_CALL(0, 51);
  c17_I4_32 = c17_in7[5];
  _SFD_SCRIPT_CALL(0, 52);
  c17_I4_33 = c17_in7[8];
  _SFD_SCRIPT_CALL(0, 53);
  c17_I5_11 = c17_in8[0];
  _SFD_SCRIPT_CALL(0, 54);
  c17_I5_12 = c17_in8[3];
  _SFD_SCRIPT_CALL(0, 55);
  c17_I5_21 = c17_in8[1];
  _SFD_SCRIPT_CALL(0, 56);
  c17_I5_13 = c17_in8[6];
  _SFD_SCRIPT_CALL(0, 57);
  c17_I5_22 = c17_in8[4];
  _SFD_SCRIPT_CALL(0, 58);
  c17_I5_31 = c17_in8[2];
  _SFD_SCRIPT_CALL(0, 59);
  c17_I5_23 = c17_in8[7];
  _SFD_SCRIPT_CALL(0, 60);
  c17_I5_32 = c17_in8[5];
  _SFD_SCRIPT_CALL(0, 61);
  c17_I5_33 = c17_in8[8];
  _SFD_SCRIPT_CALL(0, 62);
  c17_I6_11 = c17_in9[0];
  _SFD_SCRIPT_CALL(0, 63);
  c17_I6_12 = c17_in9[3];
  _SFD_SCRIPT_CALL(0, 64);
  c17_I6_21 = c17_in9[1];
  _SFD_SCRIPT_CALL(0, 65);
  c17_I6_13 = c17_in9[6];
  _SFD_SCRIPT_CALL(0, 66);
  c17_I6_22 = c17_in9[4];
  _SFD_SCRIPT_CALL(0, 67);
  c17_I6_31 = c17_in9[2];
  _SFD_SCRIPT_CALL(0, 68);
  c17_I6_23 = c17_in9[7];
  _SFD_SCRIPT_CALL(0, 69);
  c17_I6_32 = c17_in9[5];
  _SFD_SCRIPT_CALL(0, 70);
  c17_I6_33 = c17_in9[8];
  _SFD_SCRIPT_CALL(0, 71);
  c17_Ld1 = c17_in1[0];
  _SFD_SCRIPT_CALL(0, 72);
  c17_Ld2 = c17_in1[1];
  _SFD_SCRIPT_CALL(0, 73);
  c17_Ld3 = c17_in1[2];
  _SFD_SCRIPT_CALL(0, 74);
  c17_Ld4 = c17_in1[3];
  _SFD_SCRIPT_CALL(0, 75);
  c17_Ld5 = c17_in1[4];
  _SFD_SCRIPT_CALL(0, 76);
  c17_Ld6 = c17_in1[5];
  _SFD_SCRIPT_CALL(0, 77);
  c17_Ld7 = c17_in1[6];
  _SFD_SCRIPT_CALL(0, 78);
  c17_Ma1 = c17_in2[0];
  _SFD_SCRIPT_CALL(0, 79);
  c17_Ma2 = c17_in2[1];
  _SFD_SCRIPT_CALL(0, 80);
  c17_Ma3 = c17_in2[2];
  _SFD_SCRIPT_CALL(0, 81);
  c17_Ma4 = c17_in2[3];
  _SFD_SCRIPT_CALL(0, 82);
  c17_Ma5 = c17_in2[4];
  _SFD_SCRIPT_CALL(0, 83);
  c17_Ma6 = c17_in2[5];
  _SFD_SCRIPT_CALL(0, 84);
  c17_pos2 = c17_in10[1];
  _SFD_SCRIPT_CALL(0, 85);
  c17_pos3 = c17_in10[2];
  _SFD_SCRIPT_CALL(0, 86);
  c17_pos4 = c17_in10[3];
  _SFD_SCRIPT_CALL(0, 87);
  c17_pos5 = c17_in10[4];
  _SFD_SCRIPT_CALL(0, 88);
  c17_pos6 = c17_in10[5];
  _SFD_SCRIPT_CALL(0, 89);
  c17_t2 = c17_pos2 + c17_pos3;
  _SFD_SCRIPT_CALL(0, 90);
  c17_x = c17_t2;
  c17_t3 = c17_x;
  c17_b_x = c17_t3;
  c17_t3 = c17_b_x;
  c17_t3 = muDoubleScalarSin(c17_t3);
  _SFD_SCRIPT_CALL(0, 91);
  c17_c_x = c17_pos5;
  c17_t4 = c17_c_x;
  c17_d_x = c17_t4;
  c17_t4 = c17_d_x;
  c17_t4 = muDoubleScalarSin(c17_t4);
  _SFD_SCRIPT_CALL(0, 92);
  c17_t5 = c17_t3 * c17_t4;
  _SFD_SCRIPT_CALL(0, 93);
  c17_e_x = c17_t2;
  c17_t6 = c17_e_x;
  c17_f_x = c17_t6;
  c17_t6 = c17_f_x;
  c17_t6 = muDoubleScalarCos(c17_t6);
  _SFD_SCRIPT_CALL(0, 94);
  c17_g_x = c17_pos4;
  c17_t7 = c17_g_x;
  c17_h_x = c17_t7;
  c17_t7 = c17_h_x;
  c17_t7 = muDoubleScalarCos(c17_t7);
  _SFD_SCRIPT_CALL(0, 95);
  c17_i_x = c17_pos5;
  c17_t8 = c17_i_x;
  c17_j_x = c17_t8;
  c17_t8 = c17_j_x;
  c17_t8 = muDoubleScalarCos(c17_t8);
  _SFD_SCRIPT_CALL(0, 96);
  c17_t22 = c17_t6 * c17_t7 * c17_t8;
  _SFD_SCRIPT_CALL(0, 97);
  c17_t9 = (-c17_t22) + c17_t5;
  _SFD_SCRIPT_CALL(0, 98);
  c17_t10 = c17_Cy5 - c17_Ld5;
  _SFD_SCRIPT_CALL(0, 99);
  c17_t11 = ((-c17_Cx5) + c17_Ld3) + c17_Ld7;
  _SFD_SCRIPT_CALL(0, 100);
  c17_k_x = c17_pos4;
  c17_t12 = c17_k_x;
  c17_l_x = c17_t12;
  c17_t12 = c17_l_x;
  c17_t12 = muDoubleScalarSin(c17_t12);
  _SFD_SCRIPT_CALL(0, 101);
  c17_m_x = c17_pos2;
  c17_t13 = c17_m_x;
  c17_n_x = c17_t13;
  c17_t13 = c17_n_x;
  c17_t13 = muDoubleScalarSin(c17_t13);
  _SFD_SCRIPT_CALL(0, 102);
  c17_t14 = c17_Ld4 * c17_t13;
  _SFD_SCRIPT_CALL(0, 103);
  c17_t15 = c17_Ld3 + c17_t14;
  _SFD_SCRIPT_CALL(0, 104);
  c17_t16 = ((((-c17_Cz5) + c17_Ld1) + c17_Ld2) + c17_Ld4) + c17_Ld6;
  _SFD_SCRIPT_CALL(0, 105);
  c17_t17 = c17_t3 * c17_t8;
  _SFD_SCRIPT_CALL(0, 106);
  c17_t18 = c17_t4 * c17_t6 * c17_t7;
  _SFD_SCRIPT_CALL(0, 107);
  c17_t19 = c17_t17 + c17_t18;
  _SFD_SCRIPT_CALL(0, 108);
  c17_t20 = ((((-c17_Cz6) + c17_Ld1) + c17_Ld2) + c17_Ld4) + c17_Ld6;
  _SFD_SCRIPT_CALL(0, 109);
  c17_t21 = c17_Cy6 - c17_Ld5;
  _SFD_SCRIPT_CALL(0, 110);
  c17_t23 = ((-c17_Cx6) + c17_Ld3) + c17_Ld7;
  _SFD_SCRIPT_CALL(0, 111);
  c17_o_x = c17_pos6;
  c17_t24 = c17_o_x;
  c17_p_x = c17_t24;
  c17_t24 = c17_p_x;
  c17_t24 = muDoubleScalarSin(c17_t24);
  _SFD_SCRIPT_CALL(0, 112);
  c17_q_x = c17_pos6;
  c17_t25 = c17_q_x;
  c17_r_x = c17_t25;
  c17_t25 = c17_r_x;
  c17_t25 = muDoubleScalarCos(c17_t25);
  _SFD_SCRIPT_CALL(0, 113);
  c17_t26 = c17_t12 * c17_t15;
  _SFD_SCRIPT_CALL(0, 114);
  c17_t27 = c17_Ld5 * c17_t7;
  _SFD_SCRIPT_CALL(0, 115);
  c17_t28 = c17_Ld6 * c17_t12;
  _SFD_SCRIPT_CALL(0, 116);
  c17_t29 = c17_t27 + c17_t28;
  _SFD_SCRIPT_CALL(0, 117);
  c17_t30 = c17_t29 * c17_t3;
  _SFD_SCRIPT_CALL(0, 118);
  c17_t31 = c17_t26 + c17_t30;
  _SFD_SCRIPT_CALL(0, 119);
  c17_t32 = c17_t15 * c17_t7;
  _SFD_SCRIPT_CALL(0, 120);
  c17_t33 = c17_Ld5 * c17_t12;
  _SFD_SCRIPT_CALL(0, 121);
  c17_t41 = c17_Ld6 * c17_t7;
  _SFD_SCRIPT_CALL(0, 122);
  c17_t34 = c17_t33 - c17_t41;
  _SFD_SCRIPT_CALL(0, 123);
  c17_t35 = c17_Ld7 * c17_t6 * c17_t7;
  _SFD_SCRIPT_CALL(0, 124);
  c17_t42 = c17_t3 * c17_t34;
  _SFD_SCRIPT_CALL(0, 125);
  c17_t36 = (c17_t32 + c17_t35) - c17_t42;
  _SFD_SCRIPT_CALL(0, 126);
  c17_t37 = c17_t31 * c17_t8;
  _SFD_SCRIPT_CALL(0, 127);
  c17_t38 = c17_Ld5 * c17_t4 * c17_t6;
  _SFD_SCRIPT_CALL(0, 128);
  c17_t39 = c17_Ld7 * c17_t12 * c17_t6 * c17_t8;
  _SFD_SCRIPT_CALL(0, 129);
  c17_t40 = (c17_t37 + c17_t38) + c17_t39;
  _SFD_SCRIPT_CALL(0, 130);
  c17_t43 = c17_t32 - c17_t42;
  _SFD_SCRIPT_CALL(0, 131);
  c17_t44 = c17_t31 * c17_t4;
  _SFD_SCRIPT_CALL(0, 132);
  c17_t45 = c17_Ld7 * c17_t12 * c17_t4 * c17_t6;
  _SFD_SCRIPT_CALL(0, 133);
  c17_t47 = c17_Ld5 * c17_t6 * c17_t8;
  _SFD_SCRIPT_CALL(0, 134);
  c17_t46 = (c17_t44 + c17_t45) - c17_t47;
  _SFD_SCRIPT_CALL(0, 135);
  c17_t48 = c17_Cx4 - c17_Ld3;
  _SFD_SCRIPT_CALL(0, 136);
  c17_t49 = c17_t24 * c17_t9;
  _SFD_SCRIPT_CALL(0, 137);
  c17_t51 = c17_t12 * c17_t25 * c17_t6;
  _SFD_SCRIPT_CALL(0, 138);
  c17_t50 = c17_t49 - c17_t51;
  _SFD_SCRIPT_CALL(0, 139);
  c17_t52 = c17_power(chartInstance, c17_t20, 2.0);
  _SFD_SCRIPT_CALL(0, 140);
  c17_t53 = c17_Ma6 * c17_t52;
  _SFD_SCRIPT_CALL(0, 141);
  c17_t54 = c17_t25 * c17_t9;
  _SFD_SCRIPT_CALL(0, 142);
  c17_t55 = c17_t12 * c17_t24 * c17_t6;
  _SFD_SCRIPT_CALL(0, 143);
  c17_t56 = c17_t54 + c17_t55;
  _SFD_SCRIPT_CALL(0, 144);
  c17_t57 = c17_Ma6 * c17_t21 * c17_t23;
  _SFD_SCRIPT_CALL(0, 145);
  c17_t58 = c17_t25 * c17_t40;
  _SFD_SCRIPT_CALL(0, 146);
  c17_t59 = c17_t24 * c17_t36;
  _SFD_SCRIPT_CALL(0, 147);
  c17_t60 = c17_t58 + c17_t59;
  _SFD_SCRIPT_CALL(0, 148);
  c17_t61 = ((-c17_Cz2) + c17_Ld1) + c17_Ld2;
  _SFD_SCRIPT_CALL(0, 149);
  c17_t62 = c17_power(chartInstance, c17_t10, 2.0);
  _SFD_SCRIPT_CALL(0, 150);
  c17_t63 = c17_Ma5 * c17_t62;
  _SFD_SCRIPT_CALL(0, 151);
  c17_t64 = c17_Cx3 - c17_Ld3;
  _SFD_SCRIPT_CALL(0, 152);
  c17_t65 = c17_power(chartInstance, c17_t21, 2.0);
  _SFD_SCRIPT_CALL(0, 153);
  c17_t66 = c17_Ma6 * c17_t65;
  _SFD_SCRIPT_CALL(0, 154);
  c17_t67 = c17_power(chartInstance, c17_t23, 2.0);
  _SFD_SCRIPT_CALL(0, 155);
  c17_t68 = c17_Ma6 * c17_t67;
  _SFD_SCRIPT_CALL(0, 156);
  c17_t69 = c17_Ma6 * c17_t20 * c17_t21;
  _SFD_SCRIPT_CALL(0, 157);
  c17_t70 = c17_t25 * c17_t36;
  _SFD_SCRIPT_CALL(0, 158);
  c17_t71 = (((-c17_Cz3) + c17_Ld1) + c17_Ld2) + c17_Ld4;
  _SFD_SCRIPT_CALL(0, 159);
  c17_t72 = c17_Ma3 * c17_t64 * c17_t71;
  _SFD_SCRIPT_CALL(0, 160);
  c17_t73 = c17_power(chartInstance, c17_Cy3, 2.0);
  _SFD_SCRIPT_CALL(0, 161);
  c17_t74 = c17_Ma3 * c17_t73;
  _SFD_SCRIPT_CALL(0, 162);
  c17_t75 = ((((-c17_Cz4) + c17_Ld1) + c17_Ld2) + c17_Ld4) + c17_Ld6;
  _SFD_SCRIPT_CALL(0, 163);
  c17_t76 = c17_Cy4 - c17_Ld5;
  _SFD_SCRIPT_CALL(0, 164);
  c17_t77 = c17_t24 * c17_t40;
  _SFD_SCRIPT_CALL(0, 165);
  c17_t78 = (-c17_t70) + c17_t77;
  _SFD_SCRIPT_CALL(0, 166);
  c17_s_x = c17_pos2;
  c17_t79 = c17_s_x;
  c17_t_x = c17_t79;
  c17_t79 = c17_t_x;
  c17_t79 = muDoubleScalarCos(c17_t79);
  _SFD_SCRIPT_CALL(0, 167);
  c17_t80 = c17_Cx2 - c17_Ld3;
  _SFD_SCRIPT_CALL(0, 168);
  c17_t81 = c17_Ma2 * c17_t61 * c17_t80;
  _SFD_SCRIPT_CALL(0, 169);
  c17_t82 = c17_power(chartInstance, c17_Cy2, 2.0);
  _SFD_SCRIPT_CALL(0, 170);
  c17_t83 = c17_Ma2 * c17_t82;
  _SFD_SCRIPT_CALL(0, 171);
  c17_t84 = c17_Ma5 * c17_t10 * c17_t16;
  _SFD_SCRIPT_CALL(0, 172);
  c17_t85 = c17_Ma5 * c17_t10 * c17_t11;
  _SFD_SCRIPT_CALL(0, 173);
  c17_t86 = c17_power(chartInstance, c17_t16, 2.0);
  _SFD_SCRIPT_CALL(0, 174);
  c17_t87 = c17_Ma5 * c17_t86;
  _SFD_SCRIPT_CALL(0, 175);
  c17_t88 = c17_power(chartInstance, c17_t11, 2.0);
  _SFD_SCRIPT_CALL(0, 176);
  c17_t89 = c17_Ma5 * c17_t88;
  _SFD_SCRIPT_CALL(0, 177);
  c17_t90 = c17_Ma4 * c17_t48 * c17_t75;
  _SFD_SCRIPT_CALL(0, 178);
  c17_t91 = c17_power(chartInstance, c17_t76, 2.0);
  _SFD_SCRIPT_CALL(0, 179);
  c17_t92 = c17_Ma4 * c17_t91;
  _SFD_SCRIPT_CALL(0, 180);
  c17_t93 = c17_power(chartInstance, c17_t75, 2.0);
  _SFD_SCRIPT_CALL(0, 181);
  c17_t94 = c17_Ma4 * c17_t93;
  _SFD_SCRIPT_CALL(0, 182);
  c17_t95 = c17_power(chartInstance, c17_t48, 2.0);
  _SFD_SCRIPT_CALL(0, 183);
  c17_t96 = c17_Ma4 * c17_t95;
  _SFD_SCRIPT_CALL(0, 184);
  c17_t97 = c17_Ma4 * c17_t75 * c17_t76;
  _SFD_SCRIPT_CALL(0, 185);
  c17_t98 = c17_Ld5 * c17_Ma4 * c17_t6;
  _SFD_SCRIPT_CALL(0, 186);
  c17_t99 = c17_Ma4 * c17_t12 * c17_t6 * c17_t75;
  _SFD_SCRIPT_CALL(0, 187);
  c17_t100 = c17_Ma4 * c17_t6 * c17_t7 * c17_t76;
  _SFD_SCRIPT_CALL(0, 188);
  c17_t101 = (c17_t100 + c17_t98) + c17_t99;
  _SFD_SCRIPT_CALL(0, 189);
  c17_t102 = c17_I5_32 + c17_t84;
  _SFD_SCRIPT_CALL(0, 190);
  c17_t103 = c17_t102 * c17_t9;
  _SFD_SCRIPT_CALL(0, 191);
  c17_t104 = c17_I5_12 + c17_t85;
  _SFD_SCRIPT_CALL(0, 192);
  c17_t105 = c17_t104 * c17_t19;
  _SFD_SCRIPT_CALL(0, 193);
  c17_t106 = c17_Ma5 * c17_t16 * c17_t46;
  _SFD_SCRIPT_CALL(0, 194);
  c17_t107 = c17_Ma5 * c17_t11 * c17_t40;
  _SFD_SCRIPT_CALL(0, 195);
  c17_t108 = (c17_I5_22 + c17_t87) + c17_t89;
  _SFD_SCRIPT_CALL(0, 196);
  c17_t202 = c17_t108 * c17_t12 * c17_t6;
  _SFD_SCRIPT_CALL(0, 197);
  c17_t109 = (((c17_t103 + c17_t105) + c17_t106) + c17_t107) - c17_t202;
  _SFD_SCRIPT_CALL(0, 198);
  c17_u_x = c17_pos3;
  c17_t110 = c17_u_x;
  c17_v_x = c17_t110;
  c17_t110 = c17_v_x;
  c17_t110 = muDoubleScalarCos(c17_t110);
  _SFD_SCRIPT_CALL(0, 199);
  c17_t111 = c17_Ld4 * c17_t110;
  _SFD_SCRIPT_CALL(0, 200);
  c17_t112 = c17_Ld6 + c17_t111;
  _SFD_SCRIPT_CALL(0, 201);
  c17_t113 = c17_Ma5 * c17_t46;
  _SFD_SCRIPT_CALL(0, 202);
  c17_t114 = c17_Ma5 * c17_t10 * c17_t9;
  _SFD_SCRIPT_CALL(0, 203);
  c17_t201 = c17_Ma5 * c17_t12 * c17_t16 * c17_t6;
  _SFD_SCRIPT_CALL(0, 204);
  c17_t115 = (c17_t113 + c17_t114) - c17_t201;
  _SFD_SCRIPT_CALL(0, 205);
  c17_t116 = (c17_I6_22 + c17_t53) + c17_t68;
  _SFD_SCRIPT_CALL(0, 206);
  c17_t117 = c17_t116 * c17_t50;
  _SFD_SCRIPT_CALL(0, 207);
  c17_t118 = c17_I6_32 + c17_t69;
  _SFD_SCRIPT_CALL(0, 208);
  c17_t119 = c17_t118 * c17_t56;
  _SFD_SCRIPT_CALL(0, 209);
  c17_t120 = c17_I6_12 + c17_t57;
  _SFD_SCRIPT_CALL(0, 210);
  c17_t121 = c17_t120 * c17_t19;
  _SFD_SCRIPT_CALL(0, 211);
  c17_t122 = c17_Ma6 * c17_t20 * c17_t46;
  _SFD_SCRIPT_CALL(0, 212);
  c17_t123 = c17_Ma6 * c17_t23 * c17_t60;
  _SFD_SCRIPT_CALL(0, 213);
  c17_t124 = (((c17_t117 + c17_t119) + c17_t121) + c17_t122) + c17_t123;
  _SFD_SCRIPT_CALL(0, 214);
  c17_t125 = (c17_I6_33 + c17_t66) + c17_t68;
  _SFD_SCRIPT_CALL(0, 215);
  c17_t126 = c17_t125 * c17_t56;
  _SFD_SCRIPT_CALL(0, 216);
  c17_t190 = c17_Ma6 * c17_t20 * c17_t23;
  _SFD_SCRIPT_CALL(0, 217);
  c17_t127 = c17_I6_13 - c17_t190;
  _SFD_SCRIPT_CALL(0, 218);
  c17_t128 = c17_t127 * c17_t19;
  _SFD_SCRIPT_CALL(0, 219);
  c17_t129 = c17_I6_23 + c17_t69;
  _SFD_SCRIPT_CALL(0, 220);
  c17_t130 = c17_t129 * c17_t50;
  _SFD_SCRIPT_CALL(0, 221);
  c17_t131 = c17_Ma6 * c17_t21 * c17_t46;
  _SFD_SCRIPT_CALL(0, 222);
  c17_t215 = c17_Ma4 * c17_t48 * c17_t76;
  _SFD_SCRIPT_CALL(0, 223);
  c17_t132 = c17_I4_12 - c17_t215;
  _SFD_SCRIPT_CALL(0, 224);
  c17_t133 = (c17_I4_22 + c17_t94) + c17_t96;
  _SFD_SCRIPT_CALL(0, 225);
  c17_t134 = c17_t12 * c17_t133 * c17_t6;
  _SFD_SCRIPT_CALL(0, 226);
  c17_t135 = c17_Ma4 * c17_t31 * c17_t48;
  _SFD_SCRIPT_CALL(0, 227);
  c17_t136 = c17_I4_32 + c17_t97;
  _SFD_SCRIPT_CALL(0, 228);
  c17_t137 = c17_t136 * c17_t6 * c17_t7;
  _SFD_SCRIPT_CALL(0, 229);
  c17_t138 = c17_Ld5 * c17_Ma4 * c17_t6 * c17_t75;
  _SFD_SCRIPT_CALL(0, 230);
  c17_t216 = c17_t132 * c17_t3;
  _SFD_SCRIPT_CALL(0, 231);
  c17_t139 = (((c17_t134 + c17_t135) + c17_t137) + c17_t138) - c17_t216;
  _SFD_SCRIPT_CALL(0, 232);
  c17_t140 = c17_t112 * c17_t8;
  _SFD_SCRIPT_CALL(0, 233);
  c17_t141 = c17_Ld7 * c17_t4 * c17_t7;
  _SFD_SCRIPT_CALL(0, 234);
  c17_w_x = c17_pos3;
  c17_t142 = c17_w_x;
  c17_x_x = c17_t142;
  c17_t142 = c17_x_x;
  c17_t142 = muDoubleScalarSin(c17_t142);
  _SFD_SCRIPT_CALL(0, 235);
  c17_t243 = c17_Ld4 * c17_t142 * c17_t4 * c17_t7;
  _SFD_SCRIPT_CALL(0, 236);
  c17_t143 = (c17_t140 + c17_t141) - c17_t243;
  _SFD_SCRIPT_CALL(0, 237);
  c17_t144 = c17_Ma6 * c17_t46;
  _SFD_SCRIPT_CALL(0, 238);
  c17_t145 = c17_Ma6 * c17_t20 * c17_t50;
  _SFD_SCRIPT_CALL(0, 239);
  c17_t146 = c17_Ma6 * c17_t21 * c17_t56;
  _SFD_SCRIPT_CALL(0, 240);
  c17_t147 = (c17_t144 + c17_t145) + c17_t146;
  _SFD_SCRIPT_CALL(0, 241);
  c17_t148 = c17_I4_13 + c17_t90;
  _SFD_SCRIPT_CALL(0, 242);
  c17_t149 = (c17_I4_33 + c17_t92) + c17_t96;
  _SFD_SCRIPT_CALL(0, 243);
  c17_t150 = c17_t149 * c17_t6 * c17_t7;
  _SFD_SCRIPT_CALL(0, 244);
  c17_t151 = c17_Ma4 * c17_t43 * c17_t48;
  _SFD_SCRIPT_CALL(0, 245);
  c17_t152 = c17_I4_23 + c17_t97;
  _SFD_SCRIPT_CALL(0, 246);
  c17_t153 = c17_t12 * c17_t152 * c17_t6;
  _SFD_SCRIPT_CALL(0, 247);
  c17_t154 = c17_Ld5 * c17_Ma4 * c17_t6 * c17_t76;
  _SFD_SCRIPT_CALL(0, 248);
  c17_t221 = c17_t148 * c17_t3;
  _SFD_SCRIPT_CALL(0, 249);
  c17_t155 = (((c17_t150 + c17_t151) + c17_t153) + c17_t154) - c17_t221;
  _SFD_SCRIPT_CALL(0, 250);
  c17_t156 = c17_Ma6 * c17_t78;
  _SFD_SCRIPT_CALL(0, 251);
  c17_t157 = c17_Ma6 * c17_t19 * c17_t20;
  _SFD_SCRIPT_CALL(0, 252);
  c17_t220 = c17_Ma6 * c17_t23 * c17_t56;
  _SFD_SCRIPT_CALL(0, 253);
  c17_t158 = (c17_t156 + c17_t157) - c17_t220;
  _SFD_SCRIPT_CALL(0, 254);
  c17_t159 = c17_Ma5 * c17_t40;
  _SFD_SCRIPT_CALL(0, 255);
  c17_t160 = c17_Ma5 * c17_t10 * c17_t19;
  _SFD_SCRIPT_CALL(0, 256);
  c17_t218 = c17_Ma5 * c17_t11 * c17_t12 * c17_t6;
  _SFD_SCRIPT_CALL(0, 257);
  c17_t161 = (c17_t159 + c17_t160) - c17_t218;
  _SFD_SCRIPT_CALL(0, 258);
  c17_t162 = c17_t112 * c17_t4;
  _SFD_SCRIPT_CALL(0, 259);
  c17_t163 = c17_Ld4 * c17_t142 * c17_t7 * c17_t8;
  _SFD_SCRIPT_CALL(0, 260);
  c17_t165 = c17_Ld7 * c17_t7 * c17_t8;
  _SFD_SCRIPT_CALL(0, 261);
  c17_t164 = (c17_t162 + c17_t163) - c17_t165;
  _SFD_SCRIPT_CALL(0, 262);
  c17_t171 = c17_Ld4 * c17_t142;
  _SFD_SCRIPT_CALL(0, 263);
  c17_t166 = c17_Ld7 - c17_t171;
  _SFD_SCRIPT_CALL(0, 264);
  c17_t167 = c17_Ma6 * c17_t60;
  _SFD_SCRIPT_CALL(0, 265);
  c17_t168 = c17_Ma6 * c17_t23 * c17_t50;
  _SFD_SCRIPT_CALL(0, 266);
  c17_t169 = c17_Ma6 * c17_t19 * c17_t21;
  _SFD_SCRIPT_CALL(0, 267);
  c17_t170 = (c17_t167 + c17_t168) + c17_t169;
  _SFD_SCRIPT_CALL(0, 268);
  c17_t172 = c17_Ma5 * c17_t36;
  _SFD_SCRIPT_CALL(0, 269);
  c17_t173 = c17_Ma5 * c17_t11 * c17_t9;
  _SFD_SCRIPT_CALL(0, 270);
  c17_t224 = c17_Ma5 * c17_t16 * c17_t19;
  _SFD_SCRIPT_CALL(0, 271);
  c17_t174 = (c17_t172 + c17_t173) - c17_t224;
  _SFD_SCRIPT_CALL(0, 272);
  c17_t184 = c17_Ma5 * c17_t11 * c17_t16;
  _SFD_SCRIPT_CALL(0, 273);
  c17_t175 = c17_I5_31 - c17_t184;
  _SFD_SCRIPT_CALL(0, 274);
  c17_t176 = c17_t175 * c17_t9;
  _SFD_SCRIPT_CALL(0, 275);
  c17_t177 = (c17_I5_11 + c17_t63) + c17_t87;
  _SFD_SCRIPT_CALL(0, 276);
  c17_t178 = c17_t177 * c17_t19;
  _SFD_SCRIPT_CALL(0, 277);
  c17_t179 = c17_I5_21 + c17_t85;
  _SFD_SCRIPT_CALL(0, 278);
  c17_t180 = c17_Ma5 * c17_t10 * c17_t40;
  _SFD_SCRIPT_CALL(0, 279);
  c17_t225 = c17_t12 * c17_t179 * c17_t6;
  _SFD_SCRIPT_CALL(0, 280);
  c17_t226 = c17_Ma5 * c17_t16 * c17_t36;
  _SFD_SCRIPT_CALL(0, 281);
  c17_t181 = (((c17_t176 + c17_t178) + c17_t180) - c17_t225) - c17_t226;
  _SFD_SCRIPT_CALL(0, 282);
  c17_t182 = (c17_I5_33 + c17_t63) + c17_t89;
  _SFD_SCRIPT_CALL(0, 283);
  c17_t183 = c17_t182 * c17_t9;
  _SFD_SCRIPT_CALL(0, 284);
  c17_t185 = c17_Ma5 * c17_t10 * c17_t46;
  _SFD_SCRIPT_CALL(0, 285);
  c17_t186 = c17_Ma5 * c17_t11 * c17_t36;
  _SFD_SCRIPT_CALL(0, 286);
  c17_t187 = c17_I5_23 + c17_t84;
  _SFD_SCRIPT_CALL(0, 287);
  c17_t188 = (c17_I6_11 + c17_t53) + c17_t66;
  _SFD_SCRIPT_CALL(0, 288);
  c17_t189 = c17_t188 * c17_t19;
  _SFD_SCRIPT_CALL(0, 289);
  c17_t191 = c17_I6_21 + c17_t57;
  _SFD_SCRIPT_CALL(0, 290);
  c17_t192 = c17_t191 * c17_t50;
  _SFD_SCRIPT_CALL(0, 291);
  c17_t193 = c17_Ma6 * c17_t21 * c17_t60;
  _SFD_SCRIPT_CALL(0, 292);
  c17_t194 = c17_Ma4 * c17_t31;
  _SFD_SCRIPT_CALL(0, 293);
  c17_t195 = c17_Ma4 * c17_t3 * c17_t76;
  _SFD_SCRIPT_CALL(0, 294);
  c17_t196 = c17_Ma4 * c17_t12 * c17_t48 * c17_t6;
  _SFD_SCRIPT_CALL(0, 295);
  c17_t197 = (c17_t194 + c17_t195) + c17_t196;
  _SFD_SCRIPT_CALL(0, 296);
  c17_t198 = c17_Ma4 * c17_t43;
  _SFD_SCRIPT_CALL(0, 297);
  c17_t199 = c17_Ma4 * c17_t48 * c17_t6 * c17_t7;
  _SFD_SCRIPT_CALL(0, 298);
  c17_t200 = (c17_t198 + c17_t199) - c17_Ma4 * c17_t3 * c17_t75;
  _SFD_SCRIPT_CALL(0, 299);
  c17_t203 = c17_t25 * c17_t7;
  _SFD_SCRIPT_CALL(0, 300);
  c17_t242 = c17_t12 * c17_t24 * c17_t8;
  _SFD_SCRIPT_CALL(0, 301);
  c17_t204 = c17_t203 - c17_t242;
  _SFD_SCRIPT_CALL(0, 302);
  c17_t205 = c17_Cy3 * c17_Ma3 * c17_t71;
  _SFD_SCRIPT_CALL(0, 303);
  c17_t206 = c17_I3_32 + c17_t205;
  _SFD_SCRIPT_CALL(0, 304);
  c17_t207 = c17_t206 * c17_t6;
  _SFD_SCRIPT_CALL(0, 305);
  c17_t208 = c17_Ld6 * c17_t8;
  _SFD_SCRIPT_CALL(0, 306);
  c17_t209 = c17_t141 + c17_t208;
  _SFD_SCRIPT_CALL(0, 307);
  c17_t210 = c17_t24 * c17_t7;
  _SFD_SCRIPT_CALL(0, 308);
  c17_t211 = c17_t12 * c17_t25 * c17_t8;
  _SFD_SCRIPT_CALL(0, 309);
  c17_t212 = c17_t210 + c17_t211;
  _SFD_SCRIPT_CALL(0, 310);
  c17_t240 = c17_Ma6 * c17_t23 * c17_t78;
  _SFD_SCRIPT_CALL(0, 311);
  c17_t213 = (((c17_t126 + c17_t128) + c17_t130) + c17_t131) - c17_t240;
  _SFD_SCRIPT_CALL(0, 312);
  c17_t214 = c17_t212 * c17_t213;
  _SFD_SCRIPT_CALL(0, 313);
  c17_t217 = c17_t139 * c17_t7;
  _SFD_SCRIPT_CALL(0, 314);
  c17_t222 = c17_Ld6 * c17_t4;
  _SFD_SCRIPT_CALL(0, 315);
  c17_t219 = c17_t165 - c17_t222;
  _SFD_SCRIPT_CALL(0, 316);
  c17_t241 = c17_Cy3 * c17_Ma3 * c17_t64;
  _SFD_SCRIPT_CALL(0, 317);
  c17_t223 = c17_I3_12 - c17_t241;
  _SFD_SCRIPT_CALL(0, 318);
  c17_t227 = c17_I5_13 - c17_t184;
  _SFD_SCRIPT_CALL(0, 319);
  c17_t228 = c17_t19 * c17_t227;
  _SFD_SCRIPT_CALL(0, 320);
  c17_t236 = c17_t12 * c17_t187 * c17_t6;
  _SFD_SCRIPT_CALL(0, 321);
  c17_t229 = (((c17_t183 + c17_t185) + c17_t186) + c17_t228) - c17_t236;
  _SFD_SCRIPT_CALL(0, 322);
  c17_t230 = c17_t12 * c17_t229 * c17_t8;
  _SFD_SCRIPT_CALL(0, 323);
  c17_t231 = c17_I6_31 - c17_t190;
  _SFD_SCRIPT_CALL(0, 324);
  c17_t232 = c17_t231 * c17_t56;
  _SFD_SCRIPT_CALL(0, 325);
  c17_t233 = c17_Ma6 * c17_t20 * c17_t78;
  _SFD_SCRIPT_CALL(0, 326);
  c17_t234 = (((c17_t189 + c17_t192) + c17_t193) + c17_t232) + c17_t233;
  _SFD_SCRIPT_CALL(0, 327);
  c17_t235 = (c17_I4_11 + c17_t92) + c17_t94;
  _SFD_SCRIPT_CALL(0, 328);
  c17_t237 = c17_Ma4 * c17_t43 * c17_t75;
  _SFD_SCRIPT_CALL(0, 329);
  c17_t238 = c17_I4_31 + c17_t90;
  _SFD_SCRIPT_CALL(0, 330);
  c17_t239 = c17_t238 * c17_t6 * c17_t7;
  _SFD_SCRIPT_CALL(0, 331);
  c17_t244 = c17_t164 * c17_t25;
  _SFD_SCRIPT_CALL(0, 332);
  c17_t245 = c17_t12 * c17_t166 * c17_t24;
  _SFD_SCRIPT_CALL(0, 333);
  c17_t246 = c17_t244 + c17_t245;
  _SFD_SCRIPT_CALL(0, 334);
  c17_t247 = c17_Cy2 * c17_Ma2 * c17_t61;
  _SFD_SCRIPT_CALL(0, 335);
  c17_t248 = c17_t164 * c17_t24;
  _SFD_SCRIPT_CALL(0, 336);
  c17_t250 = c17_t12 * c17_t166 * c17_t25;
  _SFD_SCRIPT_CALL(0, 337);
  c17_t249 = c17_t248 - c17_t250;
  _SFD_SCRIPT_CALL(0, 338);
  c17_t251 = c17_I4_21 - c17_t215;
  _SFD_SCRIPT_CALL(0, 339);
  c17_t252 = c17_t12 * c17_t136;
  _SFD_SCRIPT_CALL(0, 340);
  c17_t253 = c17_Ma4 * c17_t112 * c17_t75;
  _SFD_SCRIPT_CALL(0, 341);
  c17_t254 = c17_Ld4 * c17_Ma4 * c17_t142 * c17_t48 * c17_t7;
  _SFD_SCRIPT_CALL(0, 342);
  c17_t319 = c17_t133 * c17_t7;
  _SFD_SCRIPT_CALL(0, 343);
  c17_t255 = ((c17_t252 + c17_t253) + c17_t254) - c17_t319;
  _SFD_SCRIPT_CALL(0, 344);
  c17_t256 = c17_t116 * c17_t204;
  _SFD_SCRIPT_CALL(0, 345);
  c17_t257 = c17_t12 * c17_t120 * c17_t4;
  _SFD_SCRIPT_CALL(0, 346);
  c17_t258 = c17_Ma6 * c17_t23 * c17_t246;
  _SFD_SCRIPT_CALL(0, 347);
  c17_t320 = c17_t118 * c17_t212;
  _SFD_SCRIPT_CALL(0, 348);
  c17_t321 = c17_Ma6 * c17_t143 * c17_t20;
  _SFD_SCRIPT_CALL(0, 349);
  c17_t259 = (((c17_t256 + c17_t257) + c17_t258) - c17_t320) - c17_t321;
  _SFD_SCRIPT_CALL(0, 350);
  c17_t260 = c17_Ma4 * c17_t112;
  _SFD_SCRIPT_CALL(0, 351);
  c17_t261 = c17_Ma4 * c17_t12 * c17_t76;
  _SFD_SCRIPT_CALL(0, 352);
  c17_t331 = c17_Ma4 * c17_t7 * c17_t75;
  _SFD_SCRIPT_CALL(0, 353);
  c17_t262 = (c17_t260 + c17_t261) - c17_t331;
  _SFD_SCRIPT_CALL(0, 354);
  c17_t263 = c17_Ma6 * c17_t249;
  _SFD_SCRIPT_CALL(0, 355);
  c17_t264 = c17_Ma6 * c17_t212 * c17_t23;
  _SFD_SCRIPT_CALL(0, 356);
  c17_t265 = c17_Ma6 * c17_t12 * c17_t20 * c17_t4;
  _SFD_SCRIPT_CALL(0, 357);
  c17_t266 = (c17_t263 + c17_t264) + c17_t265;
  _SFD_SCRIPT_CALL(0, 358);
  c17_t267 = c17_power(chartInstance, c17_t80, 2.0);
  _SFD_SCRIPT_CALL(0, 359);
  c17_t268 = c17_Ma2 * c17_t267;
  _SFD_SCRIPT_CALL(0, 360);
  c17_t269 = c17_power(chartInstance, c17_t64, 2.0);
  _SFD_SCRIPT_CALL(0, 361);
  c17_t270 = c17_Ma3 * c17_t269;
  _SFD_SCRIPT_CALL(0, 362);
  c17_t271 = c17_t125 * c17_t212;
  _SFD_SCRIPT_CALL(0, 363);
  c17_t272 = c17_Ma6 * c17_t143 * c17_t21;
  _SFD_SCRIPT_CALL(0, 364);
  c17_t273 = c17_Ma6 * c17_t23 * c17_t249;
  _SFD_SCRIPT_CALL(0, 365);
  c17_t326 = c17_t129 * c17_t204;
  _SFD_SCRIPT_CALL(0, 366);
  c17_t327 = c17_t12 * c17_t127 * c17_t4;
  _SFD_SCRIPT_CALL(0, 367);
  c17_t274 = (((c17_t271 + c17_t272) + c17_t273) - c17_t326) - c17_t327;
  _SFD_SCRIPT_CALL(0, 368);
  c17_t275 = c17_Ma6 * c17_t246;
  _SFD_SCRIPT_CALL(0, 369);
  c17_t276 = c17_Ma6 * c17_t204 * c17_t23;
  _SFD_SCRIPT_CALL(0, 370);
  c17_t277 = c17_Ma6 * c17_t12 * c17_t21 * c17_t4;
  _SFD_SCRIPT_CALL(0, 371);
  c17_t278 = (c17_t275 + c17_t276) + c17_t277;
  _SFD_SCRIPT_CALL(0, 372);
  c17_t279 = c17_t12 * c17_t149;
  _SFD_SCRIPT_CALL(0, 373);
  c17_t280 = c17_Ma4 * c17_t112 * c17_t76;
  _SFD_SCRIPT_CALL(0, 374);
  c17_t281 = c17_t108 * c17_t7;
  _SFD_SCRIPT_CALL(0, 375);
  c17_t282 = c17_t104 * c17_t12 * c17_t4;
  _SFD_SCRIPT_CALL(0, 376);
  c17_t283 = c17_Ma5 * c17_t11 * c17_t164;
  _SFD_SCRIPT_CALL(0, 377);
  c17_t334 = c17_Ma5 * c17_t143 * c17_t16;
  _SFD_SCRIPT_CALL(0, 378);
  c17_t335 = c17_t102 * c17_t12 * c17_t8;
  _SFD_SCRIPT_CALL(0, 379);
  c17_t284 = (((c17_t281 + c17_t282) + c17_t283) - c17_t334) - c17_t335;
  _SFD_SCRIPT_CALL(0, 380);
  c17_t285 = c17_Ma5 * c17_t143;
  _SFD_SCRIPT_CALL(0, 381);
  c17_t286 = c17_Ma5 * c17_t10 * c17_t12 * c17_t8;
  _SFD_SCRIPT_CALL(0, 382);
  c17_t332 = c17_Ma5 * c17_t16 * c17_t7;
  _SFD_SCRIPT_CALL(0, 383);
  c17_t287 = (c17_t285 + c17_t286) - c17_t332;
  _SFD_SCRIPT_CALL(0, 384);
  c17_t288 = c17_power(chartInstance, c17_t61, 2.0);
  _SFD_SCRIPT_CALL(0, 385);
  c17_t289 = c17_Ma2 * c17_t288;
  _SFD_SCRIPT_CALL(0, 386);
  c17_t290 = c17_Ma6 * c17_t143;
  _SFD_SCRIPT_CALL(0, 387);
  c17_t291 = c17_Ma6 * c17_t21 * c17_t212;
  _SFD_SCRIPT_CALL(0, 388);
  c17_t337 = c17_Ma6 * c17_t20 * c17_t204;
  _SFD_SCRIPT_CALL(0, 389);
  c17_t292 = (c17_t290 + c17_t291) - c17_t337;
  _SFD_SCRIPT_CALL(0, 390);
  c17_t293 = c17_power(chartInstance, c17_t71, 2.0);
  _SFD_SCRIPT_CALL(0, 391);
  c17_t294 = c17_Ma3 * c17_t293;
  _SFD_SCRIPT_CALL(0, 392);
  c17_t295 = c17_Ma5 * c17_t164;
  _SFD_SCRIPT_CALL(0, 393);
  c17_t296 = c17_Ma5 * c17_t11 * c17_t7;
  _SFD_SCRIPT_CALL(0, 394);
  c17_t297 = c17_Ma5 * c17_t10 * c17_t12 * c17_t4;
  _SFD_SCRIPT_CALL(0, 395);
  c17_t298 = (c17_t295 + c17_t296) + c17_t297;
  _SFD_SCRIPT_CALL(0, 396);
  c17_t299 = c17_t191 * c17_t204;
  _SFD_SCRIPT_CALL(0, 397);
  c17_t300 = c17_Ma6 * c17_t20 * c17_t249;
  _SFD_SCRIPT_CALL(0, 398);
  c17_t301 = c17_Ma6 * c17_t21 * c17_t246;
  _SFD_SCRIPT_CALL(0, 399);
  c17_t302 = c17_t12 * c17_t188 * c17_t4;
  _SFD_SCRIPT_CALL(0, 400);
  c17_t338 = c17_t212 * c17_t231;
  _SFD_SCRIPT_CALL(0, 401);
  c17_t303 = (((c17_t299 + c17_t300) + c17_t301) + c17_t302) - c17_t338;
  _SFD_SCRIPT_CALL(0, 402);
  c17_t304 = c17_Ma5 * c17_t12 * c17_t16 * c17_t4;
  _SFD_SCRIPT_CALL(0, 403);
  c17_t305 = c17_Ma5 * c17_t11 * c17_t12 * c17_t8;
  _SFD_SCRIPT_CALL(0, 404);
  c17_t342 = c17_Ma5 * c17_t12 * c17_t166;
  _SFD_SCRIPT_CALL(0, 405);
  c17_t306 = (c17_t304 + c17_t305) - c17_t342;
  _SFD_SCRIPT_CALL(0, 406);
  c17_t307 = c17_t187 * c17_t7;
  _SFD_SCRIPT_CALL(0, 407);
  c17_t308 = c17_t12 * c17_t227 * c17_t4;
  _SFD_SCRIPT_CALL(0, 408);
  c17_t309 = c17_Ma5 * c17_t11 * c17_t12 * c17_t166;
  _SFD_SCRIPT_CALL(0, 409);
  c17_t340 = c17_Ma5 * c17_t10 * c17_t143;
  _SFD_SCRIPT_CALL(0, 410);
  c17_t341 = c17_t12 * c17_t182 * c17_t8;
  _SFD_SCRIPT_CALL(0, 411);
  c17_t310 = (((c17_t307 + c17_t308) + c17_t309) - c17_t340) - c17_t341;
  _SFD_SCRIPT_CALL(0, 412);
  c17_t311 = c17_t179 * c17_t7;
  _SFD_SCRIPT_CALL(0, 413);
  c17_t312 = c17_Ma5 * c17_t10 * c17_t164;
  _SFD_SCRIPT_CALL(0, 414);
  c17_t313 = c17_t12 * c17_t177 * c17_t4;
  _SFD_SCRIPT_CALL(0, 415);
  c17_t343 = c17_t12 * c17_t175 * c17_t8;
  _SFD_SCRIPT_CALL(0, 416);
  c17_t344 = c17_Ma5 * c17_t12 * c17_t16 * c17_t166;
  _SFD_SCRIPT_CALL(0, 417);
  c17_t314 = (((c17_t311 + c17_t312) + c17_t313) - c17_t343) - c17_t344;
  _SFD_SCRIPT_CALL(0, 418);
  c17_t315 = c17_Ma4 * c17_t48 * c17_t7;
  _SFD_SCRIPT_CALL(0, 419);
  c17_t316 = c17_t315 - c17_Ld4 * c17_Ma4 * c17_t142 * c17_t7;
  _SFD_SCRIPT_CALL(0, 420);
  c17_t317 = c17_Ma4 * c17_t12 * c17_t48;
  _SFD_SCRIPT_CALL(0, 421);
  c17_t318 = c17_t317 - c17_Ld4 * c17_Ma4 * c17_t12 * c17_t142;
  _SFD_SCRIPT_CALL(0, 422);
  c17_t322 = c17_t204 * c17_t259;
  _SFD_SCRIPT_CALL(0, 423);
  c17_t323 = c17_t219 * c17_t24;
  _SFD_SCRIPT_CALL(0, 424);
  c17_t324 = c17_Ld7 * c17_t12 * c17_t25;
  _SFD_SCRIPT_CALL(0, 425);
  c17_t325 = c17_t323 + c17_t324;
  _SFD_SCRIPT_CALL(0, 426);
  c17_t328 = c17_t212 * c17_t274;
  _SFD_SCRIPT_CALL(0, 427);
  c17_t329 = c17_t219 * c17_t25;
  _SFD_SCRIPT_CALL(0, 428);
  c17_t349 = c17_Ld7 * c17_t12 * c17_t24;
  _SFD_SCRIPT_CALL(0, 429);
  c17_t330 = c17_t329 - c17_t349;
  _SFD_SCRIPT_CALL(0, 430);
  c17_t350 = c17_t152 * c17_t7;
  _SFD_SCRIPT_CALL(0, 431);
  c17_t333 = c17_t12 * (((c17_t279 + c17_t280) - c17_t350) - c17_Ld4 * c17_Ma4 *
                        c17_t12 * c17_t142 * c17_t48);
  _SFD_SCRIPT_CALL(0, 432);
  c17_t336 = c17_t284 * c17_t7;
  _SFD_SCRIPT_CALL(0, 433);
  c17_t339 = c17_t12 * c17_t303 * c17_t4;
  _SFD_SCRIPT_CALL(0, 434);
  c17_t345 = c17_t12 * c17_t314 * c17_t4;
  _SFD_SCRIPT_CALL(0, 435);
  c17_t346 = c17_t251 * c17_t7;
  _SFD_SCRIPT_CALL(0, 436);
  c17_t347 = c17_Ld4 * c17_Ma4 * c17_t12 * c17_t142 * c17_t75;
  _SFD_SCRIPT_CALL(0, 437);
  c17_t348 = c17_Ld4 * c17_Ma4 * c17_t142 * c17_t7 * c17_t76;
  _SFD_SCRIPT_CALL(0, 438);
  c17_t351 = c17_Ma6 * c17_t20 * c17_t209;
  _SFD_SCRIPT_CALL(0, 439);
  c17_t352 = c17_Ma6 * c17_t23 * c17_t330;
  _SFD_SCRIPT_CALL(0, 440);
  c17_t353 = ((((-c17_t256) - c17_t257) + c17_t320) + c17_t351) + c17_t352;
  _SFD_SCRIPT_CALL(0, 441);
  c17_t354 = c17_Ma6 * c17_t23 * c17_t325;
  _SFD_SCRIPT_CALL(0, 442);
  c17_t381 = c17_Ma6 * c17_t209 * c17_t21;
  _SFD_SCRIPT_CALL(0, 443);
  c17_t355 = ((((-c17_t271) + c17_t326) + c17_t327) + c17_t354) - c17_t381;
  _SFD_SCRIPT_CALL(0, 444);
  c17_t356 = c17_Ld6 * c17_Ma4 * c17_t75;
  _SFD_SCRIPT_CALL(0, 445);
  c17_t357 = (c17_t252 - c17_t319) + c17_t356;
  _SFD_SCRIPT_CALL(0, 446);
  c17_t358 = (c17_t264 + c17_t265) - c17_Ma6 * c17_t325;
  _SFD_SCRIPT_CALL(0, 447);
  c17_t359 = c17_Ma5 * c17_t16 * c17_t209;
  _SFD_SCRIPT_CALL(0, 448);
  c17_t360 = c17_Ma5 * c17_t11 * c17_t219;
  _SFD_SCRIPT_CALL(0, 449);
  c17_t361 = ((((-c17_t281) - c17_t282) + c17_t335) + c17_t359) + c17_t360;
  _SFD_SCRIPT_CALL(0, 450);
  c17_t362 = (c17_t276 + c17_t277) - c17_Ma6 * c17_t330;
  _SFD_SCRIPT_CALL(0, 451);
  c17_t363 = c17_Ld6 * c17_Ma4;
  _SFD_SCRIPT_CALL(0, 452);
  c17_t364 = (c17_t261 - c17_t331) + c17_t363;
  _SFD_SCRIPT_CALL(0, 453);
  c17_t365 = c17_Ma5 * c17_t209;
  _SFD_SCRIPT_CALL(0, 454);
  c17_t366 = (c17_t286 - c17_t332) + c17_t365;
  _SFD_SCRIPT_CALL(0, 455);
  c17_t367 = c17_Ld6 * c17_Ma4 * c17_t76;
  _SFD_SCRIPT_CALL(0, 456);
  c17_t368 = (c17_t279 - c17_t350) + c17_t367;
  _SFD_SCRIPT_CALL(0, 457);
  c17_t369 = c17_Ma6 * c17_t209;
  _SFD_SCRIPT_CALL(0, 458);
  c17_t370 = (c17_t291 - c17_t337) + c17_t369;
  _SFD_SCRIPT_CALL(0, 459);
  c17_t371 = (c17_t296 + c17_t297) - c17_Ma5 * c17_t219;
  _SFD_SCRIPT_CALL(0, 460);
  c17_t372 = c17_Ma6 * c17_t20 * c17_t325;
  _SFD_SCRIPT_CALL(0, 461);
  c17_t373 = c17_Ma6 * c17_t21 * c17_t330;
  _SFD_SCRIPT_CALL(0, 462);
  c17_t374 = ((((-c17_t299) - c17_t302) + c17_t338) + c17_t372) + c17_t373;
  _SFD_SCRIPT_CALL(0, 463);
  c17_t375 = c17_Ld7 * c17_Ma5 * c17_t11 * c17_t12;
  _SFD_SCRIPT_CALL(0, 464);
  c17_t386 = c17_Ma5 * c17_t10 * c17_t209;
  _SFD_SCRIPT_CALL(0, 465);
  c17_t376 = (((c17_t307 + c17_t308) - c17_t341) + c17_t375) - c17_t386;
  _SFD_SCRIPT_CALL(0, 466);
  c17_t387 = c17_Ld7 * c17_Ma5 * c17_t12;
  _SFD_SCRIPT_CALL(0, 467);
  c17_t377 = (c17_t304 + c17_t305) - c17_t387;
  _SFD_SCRIPT_CALL(0, 468);
  c17_t378 = c17_Ma5 * c17_t10 * c17_t219;
  _SFD_SCRIPT_CALL(0, 469);
  c17_t379 = c17_Ld7 * c17_Ma5 * c17_t12 * c17_t16;
  _SFD_SCRIPT_CALL(0, 470);
  c17_t380 = ((((-c17_t311) - c17_t313) + c17_t343) + c17_t378) + c17_t379;
  _SFD_SCRIPT_CALL(0, 471);
  c17_t382 = (-c17_t323) - c17_t324;
  _SFD_SCRIPT_CALL(0, 472);
  c17_t383 = (-c17_t329) + c17_t349;
  _SFD_SCRIPT_CALL(0, 473);
  c17_t384 = c17_t12 * c17_t368;
  _SFD_SCRIPT_CALL(0, 474);
  c17_t385 = (-c17_t165) + c17_t222;
  _SFD_SCRIPT_CALL(0, 475);
  c17_t395 = c17_t24 * c17_t385;
  _SFD_SCRIPT_CALL(0, 476);
  c17_t388 = c17_t324 - c17_t395;
  _SFD_SCRIPT_CALL(0, 477);
  c17_t389 = c17_t25 * c17_t385;
  _SFD_SCRIPT_CALL(0, 478);
  c17_t390 = c17_t349 + c17_t389;
  _SFD_SCRIPT_CALL(0, 479);
  c17_t391 = c17_Ma6 * c17_t21 * c17_t390;
  _SFD_SCRIPT_CALL(0, 480);
  c17_t400 = c17_Ma6 * c17_t20 * c17_t388;
  _SFD_SCRIPT_CALL(0, 481);
  c17_t392 = (((c17_t299 + c17_t302) - c17_t338) + c17_t391) - c17_t400;
  _SFD_SCRIPT_CALL(0, 482);
  c17_t393 = c17_Ma5 * c17_t10 * c17_t385;
  _SFD_SCRIPT_CALL(0, 483);
  c17_t394 = (((c17_t311 + c17_t313) - c17_t343) - c17_t379) + c17_t393;
  _SFD_SCRIPT_CALL(0, 484);
  c17_t396 = c17_Ma6 * c17_t23 * c17_t390;
  _SFD_SCRIPT_CALL(0, 485);
  c17_t397 = (((c17_t256 + c17_t257) - c17_t320) - c17_t351) + c17_t396;
  _SFD_SCRIPT_CALL(0, 486);
  c17_t398 = c17_Ma6 * c17_t23 * c17_t388;
  _SFD_SCRIPT_CALL(0, 487);
  c17_t399 = ((((-c17_t271) + c17_t326) + c17_t327) - c17_t381) + c17_t398;
  _SFD_SCRIPT_CALL(0, 488);
  c17_t401 = c17_t102 * c17_t4;
  _SFD_SCRIPT_CALL(0, 489);
  c17_t402 = c17_t104 * c17_t8;
  _SFD_SCRIPT_CALL(0, 490);
  c17_t403 = c17_t401 + c17_t402;
  _SFD_SCRIPT_CALL(0, 491);
  c17_t404 = c17_t120 * c17_t8;
  _SFD_SCRIPT_CALL(0, 492);
  c17_t405 = c17_t116 * c17_t24 * c17_t4;
  _SFD_SCRIPT_CALL(0, 493);
  c17_t406 = c17_t118 * c17_t25 * c17_t4;
  _SFD_SCRIPT_CALL(0, 494);
  c17_t407 = (c17_t404 + c17_t405) + c17_t406;
  _SFD_SCRIPT_CALL(0, 495);
  c17_t408 = c17_t127 * c17_t8;
  _SFD_SCRIPT_CALL(0, 496);
  c17_t409 = c17_t125 * c17_t25 * c17_t4;
  _SFD_SCRIPT_CALL(0, 497);
  c17_t410 = c17_t129 * c17_t24 * c17_t4;
  _SFD_SCRIPT_CALL(0, 498);
  c17_t411 = (c17_t408 + c17_t409) + c17_t410;
  _SFD_SCRIPT_CALL(0, 499);
  c17_t412 = c17_Ma6 * c17_t20 * c17_t24 * c17_t4;
  _SFD_SCRIPT_CALL(0, 500);
  c17_t413 = c17_Ma6 * c17_t21 * c17_t25 * c17_t4;
  _SFD_SCRIPT_CALL(0, 501);
  c17_t414 = c17_t412 + c17_t413;
  _SFD_SCRIPT_CALL(0, 502);
  c17_t415 = c17_Ma6 * c17_t20 * c17_t8;
  _SFD_SCRIPT_CALL(0, 503);
  c17_t435 = c17_Ma6 * c17_t23 * c17_t25 * c17_t4;
  _SFD_SCRIPT_CALL(0, 504);
  c17_t416 = c17_t415 - c17_t435;
  _SFD_SCRIPT_CALL(0, 505);
  c17_t417 = c17_Ma6 * c17_t21 * c17_t8;
  _SFD_SCRIPT_CALL(0, 506);
  c17_t418 = c17_Ma6 * c17_t23 * c17_t24 * c17_t4;
  _SFD_SCRIPT_CALL(0, 507);
  c17_t419 = c17_t417 + c17_t418;
  _SFD_SCRIPT_CALL(0, 508);
  c17_t420 = c17_t175 * c17_t4;
  _SFD_SCRIPT_CALL(0, 509);
  c17_t421 = c17_t177 * c17_t8;
  _SFD_SCRIPT_CALL(0, 510);
  c17_t422 = c17_t420 + c17_t421;
  _SFD_SCRIPT_CALL(0, 511);
  c17_t423 = c17_t188 * c17_t8;
  _SFD_SCRIPT_CALL(0, 512);
  c17_t424 = c17_t231 * c17_t25 * c17_t4;
  _SFD_SCRIPT_CALL(0, 513);
  c17_t425 = c17_t191 * c17_t24 * c17_t4;
  _SFD_SCRIPT_CALL(0, 514);
  c17_t426 = (c17_t423 + c17_t424) + c17_t425;
  _SFD_SCRIPT_CALL(0, 515);
  c17_t427 = c17_t227 * c17_t8;
  _SFD_SCRIPT_CALL(0, 516);
  c17_t428 = c17_t182 * c17_t4;
  _SFD_SCRIPT_CALL(0, 517);
  c17_t429 = c17_t427 + c17_t428;
  _SFD_SCRIPT_CALL(0, 518);
  c17_t430 = c17_Ma5 * c17_t11 * c17_t4;
  _SFD_SCRIPT_CALL(0, 519);
  c17_t438 = c17_Ma5 * c17_t16 * c17_t8;
  _SFD_SCRIPT_CALL(0, 520);
  c17_t431 = c17_t430 - c17_t438;
  _SFD_SCRIPT_CALL(0, 521);
  c17_t432 = c17_t403 * c17_t7;
  _SFD_SCRIPT_CALL(0, 522);
  c17_t433 = c17_t132 * c17_t7;
  _SFD_SCRIPT_CALL(0, 523);
  c17_t434 = c17_t204 * c17_t407;
  _SFD_SCRIPT_CALL(0, 524);
  c17_t436 = c17_t12 * c17_t4 * c17_t422;
  _SFD_SCRIPT_CALL(0, 525);
  c17_t437 = c17_t12 * c17_t4 * c17_t426;
  _SFD_SCRIPT_CALL(0, 526);
  c17_t439 = c17_t125 * c17_t24;
  _SFD_SCRIPT_CALL(0, 527);
  c17_t440 = c17_Ma6 * c17_t20 * c17_t25;
  _SFD_SCRIPT_CALL(0, 528);
  c17_t446 = c17_Ma6 * c17_t21 * c17_t24;
  _SFD_SCRIPT_CALL(0, 529);
  c17_t441 = c17_t440 - c17_t446;
  _SFD_SCRIPT_CALL(0, 530);
  c17_t442 = c17_t118 * c17_t24;
  _SFD_SCRIPT_CALL(0, 531);
  c17_t447 = c17_t116 * c17_t25;
  _SFD_SCRIPT_CALL(0, 532);
  c17_t443 = c17_t442 - c17_t447;
  _SFD_SCRIPT_CALL(0, 533);
  c17_t444 = c17_t191 * c17_t25;
  _SFD_SCRIPT_CALL(0, 534);
  c17_t452 = c17_t129 * c17_t25;
  _SFD_SCRIPT_CALL(0, 535);
  c17_t453 = c17_t439 - c17_t452;
  _SFD_SCRIPT_CALL(0, 536);
  c17_t445 = c17_t212 * c17_t453;
  _SFD_SCRIPT_CALL(0, 537);
  c17_t451 = c17_t231 * c17_t24;
  _SFD_SCRIPT_CALL(0, 538);
  c17_t454 = c17_t444 - c17_t451;
  _SFD_SCRIPT_CALL(0, 539);
  c17_t448 = c17_t12 * c17_t4 * c17_t454;
  _SFD_SCRIPT_CALL(0, 540);
  c17_t449 = c17_t12 * c17_t179 * c17_t4;
  _SFD_SCRIPT_CALL(0, 541);
  c17_t450 = c17_Ma5 * c17_t11 * c17_t385;
  _SFD_SCRIPT_CALL(0, 542);
  c17_t455 = c17_t120 * c17_t204;
  _SFD_SCRIPT_CALL(0, 543);
  c17_d0 = c17_power(chartInstance, c17_Cx1, 2.0);
  c17_d1 = c17_power(chartInstance, c17_Cy1, 2.0);
  c17_d2 = c17_power(chartInstance, c17_t12, 2.0);
  c17_d3 = c17_power(chartInstance, c17_t7, 2.0);
  c17_y_x[0] = (((((((((((((((((((((((((c17_I1_33 - c17_t3 * (((-c17_t3) *
    ((c17_I3_11 + c17_t294) + c17_t74) + c17_t6 * (c17_I3_31 +
    c17_t72)) + c17_Ma3 * c17_t15 * c17_t71)) + c17_t6 * ((c17_t6 * ((c17_I3_33
    + c17_t270) + c17_t74) - c17_t3 * (c17_I3_13 + c17_t72))
    + c17_Ma3 * c17_t15 * c17_t64)) + c17_Ld3 * ((c17_Ld3 * c17_Ma2 - c17_Ma2 *
    c17_t13 * c17_t61) + c17_Ma2 * c17_t79 * c17_t80)) +
    c17_t56 * ((((c17_t126 + c17_t128) + c17_t130) + c17_t131) + c17_Ma6 *
    c17_t23 * (c17_t70 - c17_t24 * c17_t40))) + c17_t181 *
    c17_t19) + c17_t197 * c17_t31) + c17_t174 * c17_t36) + c17_t161 * c17_t40) +
    c17_t115 * c17_t46) + c17_t147 * c17_t46) + c17_t124 *
    c17_t50) + c17_t200 * c17_t43) + c17_t170 * c17_t60) + c17_t158 * c17_t78) +
    c17_d0 * c17_Ma1) + c17_d1 * c17_Ma1) + c17_t9 * ((((
    c17_t183 + c17_t185) + c17_t186) + c17_t19 * (c17_I5_13 - c17_Ma5 * c17_t11 *
    c17_t16)) - c17_t12 * c17_t187 * c17_t6)) - c17_t3 * (
                        (((c17_t237 + c17_t239) - c17_t235 * c17_t3) + c17_t12 *
    c17_t6 * (c17_I4_21 - c17_Ma4 * c17_t48 * c17_t76)) - c17_Ma4 * c17_t31 *
    c17_t76)) + c17_t15 * ((c17_Ma3 * c17_t15 - c17_Ma3 * c17_t3 * c17_t71) +
    c17_Ma3 * c17_t6 * c17_t64)) + c17_t19 * ((((c17_t189 +
    c17_t192) + c17_t193) + c17_t56 * (c17_I6_31 - c17_Ma6 * c17_t20 * c17_t23))
    - c17_Ma6 * c17_t20 * (c17_t70 - c17_t24 * c17_t40)))
                    - c17_t13 * (((-c17_t13) * ((c17_I2_11 + c17_t289) + c17_t83)
    + c17_t79 * (c17_I2_31 + c17_t81)) + c17_Ld3 * c17_Ma2 * c17_t61)) +
                   c17_t79 * ((c17_t79 * ((c17_I2_33 + c17_t268) + c17_t83) -
    c17_t13 * (c17_I2_13 + c17_t81)) + c17_Ld3 * c17_Ma2 * c17_t80)) +
                  c17_Ld5 * c17_t101 * c17_t6) - c17_t109 * c17_t12 * c17_t6) +
                c17_t12 * c17_t139 * c17_t6) + c17_t155 * c17_t6 * c17_t7;
  c17_y_x[1] = (((((((((((((((((((((-c17_t3) * ((c17_I3_21 - c17_t241) + c17_Cy3
    * c17_Ld4 * c17_Ma3 * c17_t142) - c17_t19 * c17_t303)
    - c17_t19 * c17_t314) + c17_t31 * c17_t316) + c17_t306 * c17_t36) - c17_t298
    * c17_t40) + c17_t287 * c17_t46) + c17_t292 * c17_t46)
    - c17_t318 * c17_t43) - c17_t259 * c17_t50) + c17_t274 * c17_t56) - c17_t278
    * c17_t60) - c17_t266 * c17_t78) - c17_t310 * c17_t9)
                      + c17_t6 * ((c17_I3_23 + c17_t205) - c17_Cy3 * c17_Ld4 *
    c17_Ma3 * c17_t110)) - c17_t3 * (((c17_t346 + c17_t347) + c17_t348) -
    c17_t12 * c17_t238)) - c17_t13 * (c17_I2_21 - c17_Cy2 * c17_Ma2 * c17_t80))
                   + c17_t79 * (c17_I2_23 + c17_t247)) - c17_t6 * c17_t7 *
                  (((c17_t279 + c17_t280) - c17_t152 * c17_t7) - c17_Ld4 *
                   c17_Ma4 * c17_t12 * c17_t142 * c17_t48)) - c17_Ld5 * c17_t262
                 * c17_t6) -
                c17_t12 * c17_t255 * c17_t6) + c17_t12 * c17_t284 * c17_t6;
  c17_y_x[2] = ((((((((((((((((((c17_t19 * c17_t374 + c17_t19 * c17_t380) +
    c17_t36 * c17_t377) - c17_t371 * c17_t40) + c17_t366 *
    c17_t46) + c17_t370 * c17_t46) + c17_t353 * c17_t50) - c17_t355 * c17_t56) -
    c17_t362 * c17_t60) - c17_t358 * c17_t78) - c17_t376 *
                        c17_t9) - c17_t3 * (c17_I3_21 - c17_t241)) - c17_t3 *
                      (c17_t346 - c17_t12 * c17_t238)) + c17_t6 * (c17_I3_23 +
    c17_t205)) - c17_Ld5
                    * c17_t364 * c17_t6) - c17_t12 * c17_t357 * c17_t6) -
                  c17_t12 * c17_t361 * c17_t6) - c17_t368 * c17_t6 * c17_t7) -
                c17_Ma4 *
                c17_t12 * c17_t43 * c17_t48) + c17_Ma4 * c17_t31 * c17_t48 *
    c17_t7;
  c17_y_x[3] = (((((((((((((((c17_t237 - c17_t235 * c17_t3) - c17_t19 * c17_t422)
    - c17_t19 * c17_t426) - c17_t36 * c17_t431) -
    c17_t414 * c17_t46) - c17_t407 * c17_t50) - c17_t411 * c17_t56) - c17_t419 *
                       c17_t60) - c17_t416 * c17_t78) - c17_t429 * c17_t9) -
                    c17_Ma4 * c17_t31 * c17_t76) + c17_t12 * c17_t132 * c17_t6)
                  + c17_t12 * c17_t403 * c17_t6) + c17_t148 * c17_t6 * c17_t7) -
                c17_Ma5
                * c17_t10 * c17_t4 * c17_t46) - c17_Ma5 * c17_t10 * c17_t40 *
    c17_t8;
  c17_y_x[4] = ((((((((((-c17_t106) - c17_t107) + c17_t202) - c17_t179 * c17_t19)
                     - c17_t441 * c17_t46) + c17_t443 * c17_t50) -
                   c17_t187 * c17_t9) - c17_t19 * (c17_t444 - c17_t231 * c17_t24))
                 + c17_t56 * (c17_t439 - c17_t129 * c17_t25)) - c17_Ma6 *
                c17_t23 *
                c17_t25 * c17_t60) - c17_Ma6 * c17_t23 * c17_t24 * c17_t78;
  c17_y_x[5] = ((((-c17_t189) - c17_t193) - c17_t233) - c17_t120 * c17_t50) -
    c17_t127 * c17_t56;
  c17_y_x[6] = (((((((((((((((((((((c17_t207 + c17_t214) + c17_t217) + c17_t230)
    - c17_t101 * c17_t112) + c17_t115 * c17_t143) -
    c17_t12 * c17_t155) + c17_t143 * c17_t147) - c17_t161 * c17_t164) - c17_t124
    * c17_t204) - c17_t158 * c17_t249) - c17_t170 *
    c17_t246) - c17_t223 * c17_t3) - c17_t109 * c17_t7) - c17_t13 * (c17_I2_12 -
    c17_Cy2 * c17_Ma2 * c17_t80)) + c17_t79 * (c17_I2_32 +
    c17_t247)) - c17_t12 * c17_t166 * c17_t174) - c17_t12 * c17_t181 * c17_t4) -
                   c17_t12 * c17_t234 * c17_t4) + c17_Ld4 * c17_t12 *
                  c17_t142 * c17_t200) - c17_Ld4 * c17_t142 * c17_t197 * c17_t7)
                - c17_Cy3 * c17_Ld4 * c17_Ma3 * c17_t142 * c17_t3) - c17_Cy3 *
    c17_Ld4 * c17_Ma3 * c17_t110 * c17_t6;
  c17_y_x[7] = (((((((((((((((((((((((((c17_I2_22 + c17_I3_22) + c17_t268) +
    c17_t270) + c17_t289) + c17_t294) + c17_t322) + c17_t328)
    + c17_t333) + c17_t336) + c17_t339) + c17_t345) + c17_t112 * c17_t262) +
    c17_t143 * c17_t287) + c17_t143 * c17_t292) + c17_t164 *
    c17_t298) + c17_t249 * c17_t266) + c17_t246 * c17_t278) - c17_t255 * c17_t7)
                      - c17_Ld4 * c17_t142 * (c17_Ma3 * c17_t64 - c17_Ld4 *
    c17_Ma3 * c17_t142)) - c17_Ld4 * c17_t110 * (c17_Ma3 * c17_t71 - c17_Ld4 *
    c17_Ma3 * c17_t110)) - c17_t12 * c17_t166 * c17_t306) -
                   c17_t12 * c17_t310 * c17_t8) - c17_Ld4 * c17_t12 * c17_t142 *
                  c17_t318) - c17_Ld4 * c17_t142 * c17_t316 * c17_t7) - c17_Ld4 *
                c17_Ma3 * c17_t142 * c17_t64) - c17_Ld4 * c17_Ma3 * c17_t110 *
    c17_t71;
  c17_y_x[8] = ((((((((((((((((((((c17_I3_22 + c17_t270) + c17_t294) + c17_t384)
    + c17_t112 * c17_t364) + c17_t143 * c17_t366) +
    c17_t143 * c17_t370) + c17_t164 * c17_t371) - c17_t204 * c17_t353) -
    c17_t212 * c17_t355) + c17_t249 * c17_t358) + c17_t246 *
    c17_t362) - c17_t357 * c17_t7) - c17_t361 * c17_t7) - c17_t12 * c17_t166 *
                      c17_t377) - c17_t12 * c17_t374 * c17_t4) - c17_t12 *
                    c17_t380 * c17_t4) - c17_t12 * c17_t376 * c17_t8) - c17_Ld4 *
                  c17_Ma3 * c17_t142 * c17_t64) - c17_Ld4 * c17_Ma3 * c17_t110 *
                 c17_t71
                 ) - c17_Ld4 * c17_Ma4 * c17_d2 * c17_t142 * c17_t48) - c17_Ld4 *
    c17_Ma4 * c17_t142 * c17_t48 * c17_d3;
  c17_y_x[9] = ((((((((((((((c17_t347 + c17_t348) + c17_t432) + c17_t433) +
    c17_t434) + c17_t436) + c17_t437) - c17_t12 * c17_t148) -
                      c17_t143 * c17_t414) - c17_t212 * c17_t411) + c17_t246 *
                    c17_t419) + c17_t249 * c17_t416) + c17_t12 * c17_t166 *
                  c17_t431) - c17_t12
                 * c17_t429 * c17_t8) - c17_Ma5 * c17_t10 * c17_t143 * c17_t4) +
    c17_Ma5 * c17_t10 * c17_t164 * c17_t8;
  c17_y_x[10] = (((((((((c17_t281 + c17_t283) - c17_t334) + c17_t445) + c17_t448)
                     + c17_t449) - c17_t143 * c17_t441) - c17_t204 *
                   c17_t443) - c17_t12 * c17_t187 * c17_t8) + c17_Ma6 * c17_t23 *
                 c17_t24 * c17_t249) + c17_Ma6 * c17_t23 * c17_t246 * c17_t25;
  c17_y_x[11] = (((c17_t300 + c17_t301) + c17_t302) + c17_t455) - c17_t127 *
    c17_t212;
  c17_y_x[12] = (((((((((((((((c17_t207 + c17_t214) + c17_t217) + c17_t230) -
    c17_Ld6 * c17_t101) - c17_t12 * c17_t155) + c17_t115 *
    c17_t209) - c17_t124 * c17_t204) + c17_t147 * c17_t209) + c17_t161 *
                       c17_t219) + c17_t158 * c17_t325) + c17_t170 * c17_t330) -
                    c17_t223 * c17_t3) - c17_t109 * c17_t7) - c17_Ld7 * c17_t12 *
                  c17_t174) - c17_t12 * c17_t181 * c17_t4) - c17_t12 * c17_t234 *
    c17_t4;
  c17_y_x[13] = ((((((((((((((((((c17_I3_22 + c17_t270) + c17_t294) + c17_t322)
    + c17_t328) + c17_t333) + c17_t336) + c17_t339) +
    c17_t345) + c17_Ld6 * c17_t262) + c17_t209 * c17_t287) + c17_t209 * c17_t292)
                       - c17_t219 * c17_t298) - c17_t266 * c17_t325) -
                     c17_t278 * c17_t330) - c17_t255 * c17_t7) - c17_Ld7 *
                   c17_t12 * c17_t306) - c17_t12 * c17_t310 * c17_t8) - c17_Ld4 *
                 c17_Ma3 *
                 c17_t142 * c17_t64) - c17_Ld4 * c17_Ma3 * c17_t110 * c17_t71;
  c17_y_x[14] = ((((((((((((((((c17_I3_22 + c17_t270) + c17_t294) + c17_t384) +
    c17_Ld6 * c17_t364) + c17_t382 * ((c17_t264 + c17_t265
    ) + c17_Ma6 * c17_t382)) + c17_t383 * ((c17_t276 + c17_t277) + c17_Ma6 *
    c17_t383)) + c17_t385 * ((c17_t296 + c17_t297) + c17_Ma5 *
    c17_t385)) - c17_t204 * c17_t353) - c17_t212 * c17_t355) + c17_t209 *
                       c17_t366) + c17_t209 * c17_t370) - c17_t357 * c17_t7) -
                    c17_t361 * c17_t7) - c17_Ld7 * c17_t12 * c17_t377) + c17_t12
                  * c17_t392 * c17_t4) + c17_t12 * c17_t394 * c17_t4) - c17_t12 *
    c17_t376 * c17_t8;
  c17_y_x[15] = ((((((((((((c17_t432 + c17_t433) + c17_t434) + c17_t436) +
    c17_t437) - c17_t12 * c17_t148) - c17_t209 * c17_t414) -
                      c17_t212 * c17_t411) - c17_t388 * c17_t416) + c17_t390 *
                    c17_t419) + c17_Ld7 * c17_t12 * c17_t431) - c17_t12 *
                  c17_t429 * c17_t8) -
                 c17_Ma5 * c17_t10 * c17_t209 * c17_t4) + c17_Ma5 * c17_t10 *
    c17_t385 * c17_t8;
  c17_y_x[16] = (((((((((c17_t281 - c17_t359) + c17_t445) + c17_t448) + c17_t449)
                     + c17_t450) - c17_t204 * c17_t443) - c17_t209 *
                   c17_t441) - c17_t12 * c17_t187 * c17_t8) - c17_Ma6 * c17_t23 *
                 c17_t24 * c17_t388) + c17_Ma6 * c17_t23 * c17_t25 * c17_t390;
  c17_y_x[17] = (((c17_t302 + c17_t391) - c17_t400) + c17_t455) - c17_t127 *
    c17_t212;
  c17_y_x[18] = ((((((((c17_t237 + c17_t239) - c17_t235 * c17_t3) - c17_t229 *
                      c17_t4) - c17_t181 * c17_t8) - c17_t234 * c17_t8) -
                   c17_Ma4 * c17_t31 * c17_t76) - c17_t124 * c17_t24 * c17_t4) -
                 c17_t213 * c17_t25 * c17_t4) + c17_t12 * c17_t251 * c17_t6;
  c17_y_x[19] = (((((((c17_t346 + c17_t347) + c17_t348) - c17_t12 * c17_t238) +
                    c17_t310 * c17_t4) + c17_t303 * c17_t8) + c17_t314 *
                  c17_t8) + c17_t24 * c17_t259 * c17_t4) - c17_t25 * c17_t274 *
    c17_t4;
  c17_y_x[20] = (((((c17_t346 - c17_t12 * c17_t238) + c17_t376 * c17_t4) +
                   c17_t392 * c17_t8) + c17_t394 * c17_t8) + c17_t24 *
                 c17_t397 * c17_t4) + c17_t25 * c17_t399 * c17_t4;
  c17_y_x[21] = ((((((c17_I4_11 + c17_t92) + c17_t94) + c17_t4 * c17_t429) +
                   c17_t422 * c17_t8) + c17_t426 * c17_t8) + c17_t24 *
                 c17_t4 * c17_t407) + c17_t25 * c17_t4 * c17_t411;
  c17_y_x[22] = (((c17_t187 * c17_t4 + c17_t179 * c17_t8) + c17_t8 * (c17_t444 -
    c17_t451)) - c17_t24 * c17_t4 * c17_t443) - c17_t25
    * c17_t4 * c17_t453;
  c17_y_x[23] = (c17_t423 + c17_t120 * c17_t24 * c17_t4) + c17_t127 * c17_t25 *
    c17_t4;
  c17_y_x[24] = ((((((-c17_t103) - c17_t105) - c17_t106) - c17_t107) + c17_t202)
                 - c17_t124 * c17_t25) + c17_t213 * c17_t24;
  c17_y_x[25] = (((((c17_t281 + c17_t282) + c17_t283) - c17_t334) - c17_t335) +
                 c17_t25 * c17_t259) + c17_t24 * c17_t274;
  c17_y_x[26] = (((((c17_t281 + c17_t282) - c17_t335) - c17_t359) + c17_t450) -
                 c17_t24 * c17_t399) + c17_t25 * c17_t397;
  c17_y_x[27] = ((c17_t401 + c17_t402) - c17_t24 * c17_t411) + c17_t25 *
    c17_t407;
  c17_y_x[28] = (((c17_I5_22 + c17_t87) + c17_t89) - c17_t25 * c17_t443) +
    c17_t24 * (c17_t439 - c17_t452);
  c17_y_x[29] = (-c17_t127) * c17_t24 + c17_t120 * c17_t25;
  c17_y_x[30] = ((((-c17_t189) - c17_t192) - c17_t193) - c17_t232) - c17_t233;
  c17_y_x[31] = c17_t303;
  c17_y_x[32] = c17_t392;
  c17_y_x[33] = c17_t426;
  c17_y_x[34] = c17_t454;
  c17_y_x[35] = c17_t188;
  for (c17_k = 1; c17_k < 37; c17_k = c17_k + 1) {
    c17_b_k = c17_k;
    c17_EulerMd_[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c17_b_k), 1, 36, 1, 0) - 1] = c17_y_x[
      _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c17_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0, -543);
  sf_debug_symbol_scope_pop();
}

static real_T c17_power(SFc17_DynJointVerifyInstanceStruct *chartInstance,
  real_T c17_a, real_T c17_b)
{
  real_T c17_ak;
  real_T c17_bk;
  real_T c17_x;
  real_T c17_b_x;
  c17_eml_scalar_eg(chartInstance);
  c17_ak = c17_a;
  c17_bk = c17_b;
  if (c17_ak < 0.0) {
    c17_x = c17_bk;
    c17_b_x = c17_x;
    c17_b_x = muDoubleScalarFloor(c17_b_x);
    if (c17_b_x != c17_bk) {
      c17_eml_error(chartInstance);
      goto label_1;
    }
  }

 label_1:
  ;
  return muDoubleScalarPower(c17_ak, c17_bk);
}

static void c17_eml_scalar_eg(SFc17_DynJointVerifyInstanceStruct *chartInstance)
{
}

static void c17_eml_error(SFc17_DynJointVerifyInstanceStruct *chartInstance)
{
  int32_T c17_i63;
  static char_T c17_cv0[32] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'p', 'o', 'w', 'e', 'r',
    ':', 'd', 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c17_u[32];
  const mxArray *c17_y = NULL;
  int32_T c17_i64;
  static char_T c17_cv1[102] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r',
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

  char_T c17_b_u[102];
  const mxArray *c17_b_y = NULL;
  for (c17_i63 = 0; c17_i63 < 32; c17_i63 = c17_i63 + 1) {
    c17_u[c17_i63] = c17_cv0[c17_i63];
  }

  c17_y = NULL;
  sf_mex_assign(&c17_y, sf_mex_create("y", c17_u, 10, 0U, 1U, 0U, 2, 1, 32));
  for (c17_i64 = 0; c17_i64 < 102; c17_i64 = c17_i64 + 1) {
    c17_b_u[c17_i64] = c17_cv1[c17_i64];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_b_u, 10, 0U, 1U, 0U, 2, 1, 102));
  sf_mex_call_debug("error", 0U, 2U, 14, c17_y, 14, c17_b_y);
}

static void c17_b_eml_scalar_eg(SFc17_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

static const mxArray *c17_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  int32_T c17_i65;
  real_T c17_b_u[6];
  int32_T c17_i66;
  real_T c17_c_u[6];
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  for (c17_i65 = 0; c17_i65 < 6; c17_i65 = c17_i65 + 1) {
    c17_b_u[c17_i65] = (*((real_T (*)[6])c17_u))[c17_i65];
  }

  for (c17_i66 = 0; c17_i66 < 6; c17_i66 = c17_i66 + 1) {
    c17_c_u[c17_i66] = c17_b_u[c17_i66];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_c_u, 0, 0U, 1U, 0U, 1, 6));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

static const mxArray *c17_b_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  int32_T c17_i67;
  real_T c17_b_u[9];
  int32_T c17_i68;
  real_T c17_c_u[9];
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  for (c17_i67 = 0; c17_i67 < 9; c17_i67 = c17_i67 + 1) {
    c17_b_u[c17_i67] = (*((real_T (*)[9])c17_u))[c17_i67];
  }

  for (c17_i68 = 0; c17_i68 < 9; c17_i68 = c17_i68 + 1) {
    c17_c_u[c17_i68] = c17_b_u[c17_i68];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_c_u, 0, 0U, 1U, 0U, 2, 1, 9));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

static const mxArray *c17_c_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  real_T c17_b_u;
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  c17_b_u = *((real_T *)c17_u);
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

static const mxArray *c17_d_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  int32_T c17_i69;
  real_T c17_b_u[6];
  int32_T c17_i70;
  real_T c17_c_u[6];
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  for (c17_i69 = 0; c17_i69 < 6; c17_i69 = c17_i69 + 1) {
    c17_b_u[c17_i69] = (*((real_T (*)[6])c17_u))[c17_i69];
  }

  for (c17_i70 = 0; c17_i70 < 6; c17_i70 = c17_i70 + 1) {
    c17_c_u[c17_i70] = c17_b_u[c17_i70];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_c_u, 0, 0U, 1U, 0U, 2, 1, 6));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

static const mxArray *c17_e_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  int32_T c17_i71;
  real_T c17_b_u[18];
  int32_T c17_i72;
  real_T c17_c_u[18];
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  for (c17_i71 = 0; c17_i71 < 18; c17_i71 = c17_i71 + 1) {
    c17_b_u[c17_i71] = (*((real_T (*)[18])c17_u))[c17_i71];
  }

  for (c17_i72 = 0; c17_i72 < 18; c17_i72 = c17_i72 + 1) {
    c17_c_u[c17_i72] = c17_b_u[c17_i72];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_c_u, 0, 0U, 1U, 0U, 2, 1, 18));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

static const mxArray *c17_f_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  int32_T c17_i73;
  real_T c17_b_u[8];
  int32_T c17_i74;
  real_T c17_c_u[8];
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  for (c17_i73 = 0; c17_i73 < 8; c17_i73 = c17_i73 + 1) {
    c17_b_u[c17_i73] = (*((real_T (*)[8])c17_u))[c17_i73];
  }

  for (c17_i74 = 0; c17_i74 < 8; c17_i74 = c17_i74 + 1) {
    c17_c_u[c17_i74] = c17_b_u[c17_i74];
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_c_u, 0, 0U, 1U, 0U, 2, 1, 8));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

static const mxArray *c17_g_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  int32_T c17_i75;
  int32_T c17_i76;
  int32_T c17_i77;
  real_T c17_b_u[36];
  int32_T c17_i78;
  int32_T c17_i79;
  int32_T c17_i80;
  real_T c17_c_u[36];
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  c17_i75 = 0;
  for (c17_i76 = 0; c17_i76 < 6; c17_i76 = c17_i76 + 1) {
    for (c17_i77 = 0; c17_i77 < 6; c17_i77 = c17_i77 + 1) {
      c17_b_u[c17_i77 + c17_i75] = (*((real_T (*)[36])c17_u))[c17_i77 + c17_i75];
    }

    c17_i75 = c17_i75 + 6;
  }

  c17_i78 = 0;
  for (c17_i79 = 0; c17_i79 < 6; c17_i79 = c17_i79 + 1) {
    for (c17_i80 = 0; c17_i80 < 6; c17_i80 = c17_i80 + 1) {
      c17_c_u[c17_i80 + c17_i78] = c17_b_u[c17_i80 + c17_i78];
    }

    c17_i78 = c17_i78 + 6;
  }

  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", c17_c_u, 0, 0U, 1U, 0U, 2, 6, 6));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

const mxArray *sf_c17_DynJointVerify_get_eml_resolved_functions_info(void)
{
  const mxArray *c17_nameCaptureInfo = NULL;
  c17_ResolvedFunctionInfo c17_info[58];
  const mxArray *c17_m0 = NULL;
  int32_T c17_i81;
  c17_ResolvedFunctionInfo *c17_r0;
  c17_nameCaptureInfo = NULL;
  c17_info_helper(c17_info);
  sf_mex_assign(&c17_m0, sf_mex_createstruct("nameCaptureInfo", 1, 58));
  for (c17_i81 = 0; c17_i81 < 58; c17_i81 = c17_i81 + 1) {
    c17_r0 = &c17_info[c17_i81];
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", c17_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c17_r0->context)), "context"
                    , "nameCaptureInfo", c17_i81);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", c17_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c17_r0->name)), "name",
                    "nameCaptureInfo", c17_i81);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo",
      c17_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c17_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c17_i81);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", c17_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c17_r0->resolved)),
                    "resolved", "nameCaptureInfo", c17_i81);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c17_i81);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileTime1,
      7, 0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo",
                    c17_i81);
    sf_mex_addfield(c17_m0, sf_mex_create("nameCaptureInfo", &c17_r0->fileTime2,
      7, 0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo",
                    c17_i81);
  }

  sf_mex_assign(&c17_nameCaptureInfo, c17_m0);
  return c17_nameCaptureInfo;
}

static void c17_info_helper(c17_ResolvedFunctionInfo c17_info[58])
{
  c17_info[0].context = "";
  c17_info[0].name = "zeros";
  c17_info[0].dominantType = "double";
  c17_info[0].resolved = "[B]zeros";
  c17_info[0].fileLength = 0U;
  c17_info[0].fileTime1 = 0U;
  c17_info[0].fileTime2 = 0U;
  c17_info[1].context = "";
  c17_info[1].name = "ctranspose";
  c17_info[1].dominantType = "double";
  c17_info[1].resolved = "[B]ctranspose";
  c17_info[1].fileLength = 0U;
  c17_info[1].fileTime1 = 0U;
  c17_info[1].fileTime2 = 0U;
  c17_info[2].context = "";
  c17_info[2].name = "EulerMd";
  c17_info[2].dominantType = "double";
  c17_info[2].resolved = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[2].fileLength = 16169U;
  c17_info[2].fileTime1 = 1408089848U;
  c17_info[2].fileTime2 = 0U;
  c17_info[3].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[3].name = "plus";
  c17_info[3].dominantType = "double";
  c17_info[3].resolved = "[B]plus";
  c17_info[3].fileLength = 0U;
  c17_info[3].fileTime1 = 0U;
  c17_info[3].fileTime2 = 0U;
  c17_info[4].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[4].name = "sin";
  c17_info[4].dominantType = "double";
  c17_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c17_info[4].fileLength = 324U;
  c17_info[4].fileTime1 = 1203422842U;
  c17_info[4].fileTime2 = 0U;
  c17_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c17_info[5].name = "nargin";
  c17_info[5].dominantType = "";
  c17_info[5].resolved = "[B]nargin";
  c17_info[5].fileLength = 0U;
  c17_info[5].fileTime1 = 0U;
  c17_info[5].fileTime2 = 0U;
  c17_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c17_info[6].name = "gt";
  c17_info[6].dominantType = "double";
  c17_info[6].resolved = "[B]gt";
  c17_info[6].fileLength = 0U;
  c17_info[6].fileTime1 = 0U;
  c17_info[6].fileTime2 = 0U;
  c17_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c17_info[7].name = "isa";
  c17_info[7].dominantType = "double";
  c17_info[7].resolved = "[B]isa";
  c17_info[7].fileLength = 0U;
  c17_info[7].fileTime1 = 0U;
  c17_info[7].fileTime2 = 0U;
  c17_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c17_info[8].name = "eml_scalar_sin";
  c17_info[8].dominantType = "double";
  c17_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c17_info[8].fileLength = 601U;
  c17_info[8].fileTime1 = 1209309190U;
  c17_info[8].fileTime2 = 0U;
  c17_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c17_info[9].name = "isreal";
  c17_info[9].dominantType = "double";
  c17_info[9].resolved = "[B]isreal";
  c17_info[9].fileLength = 0U;
  c17_info[9].fileTime1 = 0U;
  c17_info[9].fileTime2 = 0U;
  c17_info[10].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[10].name = "times";
  c17_info[10].dominantType = "double";
  c17_info[10].resolved = "[B]times";
  c17_info[10].fileLength = 0U;
  c17_info[10].fileTime1 = 0U;
  c17_info[10].fileTime2 = 0U;
  c17_info[11].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[11].name = "cos";
  c17_info[11].dominantType = "double";
  c17_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c17_info[11].fileLength = 324U;
  c17_info[11].fileTime1 = 1203422750U;
  c17_info[11].fileTime2 = 0U;
  c17_info[12].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c17_info[12].name = "eml_scalar_cos";
  c17_info[12].dominantType = "double";
  c17_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c17_info[12].fileLength = 602U;
  c17_info[12].fileTime1 = 1209309186U;
  c17_info[12].fileTime2 = 0U;
  c17_info[13].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[13].name = "uminus";
  c17_info[13].dominantType = "double";
  c17_info[13].resolved = "[B]uminus";
  c17_info[13].fileLength = 0U;
  c17_info[13].fileTime1 = 0U;
  c17_info[13].fileTime2 = 0U;
  c17_info[14].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[14].name = "minus";
  c17_info[14].dominantType = "double";
  c17_info[14].resolved = "[B]minus";
  c17_info[14].fileLength = 0U;
  c17_info[14].fileTime1 = 0U;
  c17_info[14].fileTime2 = 0U;
  c17_info[15].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[15].name = "power";
  c17_info[15].dominantType = "double";
  c17_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[15].fileLength = 5380U;
  c17_info[15].fileTime1 = 1228068698U;
  c17_info[15].fileTime2 = 0U;
  c17_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[16].name = "isinteger";
  c17_info[16].dominantType = "double";
  c17_info[16].resolved = "[B]isinteger";
  c17_info[16].fileLength = 0U;
  c17_info[16].fileTime1 = 0U;
  c17_info[16].fileTime2 = 0U;
  c17_info[17].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[17].name = "eml_scalar_eg";
  c17_info[17].dominantType = "double";
  c17_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c17_info[17].fileLength = 3068U;
  c17_info[17].fileTime1 = 1240240410U;
  c17_info[17].fileTime2 = 0U;
  c17_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!any_enums";
  c17_info[18].name = "false";
  c17_info[18].dominantType = "";
  c17_info[18].resolved = "[B]false";
  c17_info[18].fileLength = 0U;
  c17_info[18].fileTime1 = 0U;
  c17_info[18].fileTime2 = 0U;
  c17_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c17_info[19].name = "isstruct";
  c17_info[19].dominantType = "double";
  c17_info[19].resolved = "[B]isstruct";
  c17_info[19].fileLength = 0U;
  c17_info[19].fileTime1 = 0U;
  c17_info[19].fileTime2 = 0U;
  c17_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c17_info[20].name = "eq";
  c17_info[20].dominantType = "double";
  c17_info[20].resolved = "[B]eq";
  c17_info[20].fileLength = 0U;
  c17_info[20].fileTime1 = 0U;
  c17_info[20].fileTime2 = 0U;
  c17_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c17_info[21].name = "class";
  c17_info[21].dominantType = "double";
  c17_info[21].resolved = "[B]class";
  c17_info[21].fileLength = 0U;
  c17_info[21].fileTime1 = 0U;
  c17_info[21].fileTime2 = 0U;
  c17_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m!zerosum";
  c17_info[22].name = "cast";
  c17_info[22].dominantType = "double";
  c17_info[22].resolved = "[B]cast";
  c17_info[22].fileLength = 0U;
  c17_info[22].fileTime1 = 0U;
  c17_info[22].fileTime2 = 0U;
  c17_info[23].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[23].name = "eml_scalexp_alloc";
  c17_info[23].dominantType = "double";
  c17_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c17_info[23].fileLength = 932U;
  c17_info[23].fileTime1 = 1261926670U;
  c17_info[23].fileTime2 = 0U;
  c17_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c17_info[24].name = "isscalar";
  c17_info[24].dominantType = "double";
  c17_info[24].resolved = "[B]isscalar";
  c17_info[24].fileLength = 0U;
  c17_info[24].fileTime1 = 0U;
  c17_info[24].fileTime2 = 0U;
  c17_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c17_info[25].name = "not";
  c17_info[25].dominantType = "logical";
  c17_info[25].resolved = "[B]not";
  c17_info[25].fileLength = 0U;
  c17_info[25].fileTime1 = 0U;
  c17_info[25].fileTime2 = 0U;
  c17_info[26].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[26].name = "lt";
  c17_info[26].dominantType = "double";
  c17_info[26].resolved = "[B]lt";
  c17_info[26].fileLength = 0U;
  c17_info[26].fileTime1 = 0U;
  c17_info[26].fileTime2 = 0U;
  c17_info[27].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[27].name = "eml_scalar_floor";
  c17_info[27].dominantType = "double";
  c17_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c17_info[27].fileLength = 260U;
  c17_info[27].fileTime1 = 1209309190U;
  c17_info[27].fileTime2 = 0U;
  c17_info[28].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[28].name = "ne";
  c17_info[28].dominantType = "double";
  c17_info[28].resolved = "[B]ne";
  c17_info[28].fileLength = 0U;
  c17_info[28].fileTime1 = 0U;
  c17_info[28].fileTime2 = 0U;
  c17_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c17_info[29].name = "eml_error";
  c17_info[29].dominantType = "char";
  c17_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c17_info[29].fileLength = 315U;
  c17_info[29].fileTime1 = 1213905144U;
  c17_info[29].fileTime2 = 0U;
  c17_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c17_info[30].name = "strcmp";
  c17_info[30].dominantType = "char";
  c17_info[30].resolved = "[B]strcmp";
  c17_info[30].fileLength = 0U;
  c17_info[30].fileTime1 = 0U;
  c17_info[30].fileTime2 = 0U;
  c17_info[31].context = "[E]D:/Learn/Project_Matlab/Fanuc/EulerMd.m";
  c17_info[31].name = "reshape";
  c17_info[31].dominantType = "double";
  c17_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c17_info[31].fileLength = 4857U;
  c17_info[31].fileTime1 = 1242276774U;
  c17_info[31].fileTime2 = 0U;
  c17_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c17_info[32].name = "eml_index_class";
  c17_info[32].dominantType = "";
  c17_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c17_info[32].fileLength = 909U;
  c17_info[32].fileTime1 = 1192445182U;
  c17_info[32].fileTime2 = 0U;
  c17_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c17_info[33].name = "size";
  c17_info[33].dominantType = "double";
  c17_info[33].resolved = "[B]size";
  c17_info[33].fileLength = 0U;
  c17_info[33].fileTime1 = 0U;
  c17_info[33].fileTime2 = 0U;
  c17_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  c17_info[34].name = "eml_assert_valid_size_arg";
  c17_info[34].dominantType = "double";
  c17_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c17_info[34].fileLength = 3315U;
  c17_info[34].fileTime1 = 1256367816U;
  c17_info[34].fileTime2 = 0U;
  c17_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c17_info[35].name = "isvector";
  c17_info[35].dominantType = "double";
  c17_info[35].resolved = "[B]isvector";
  c17_info[35].fileLength = 0U;
  c17_info[35].fileTime1 = 0U;
  c17_info[35].fileTime2 = 0U;
  c17_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c17_info[36].name = "isinf";
  c17_info[36].dominantType = "double";
  c17_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c17_info[36].fileLength = 541U;
  c17_info[36].fileTime1 = 1271383988U;
  c17_info[36].fileTime2 = 0U;
  c17_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c17_info[37].name = "true";
  c17_info[37].dominantType = "";
  c17_info[37].resolved = "[B]true";
  c17_info[37].fileLength = 0U;
  c17_info[37].fileTime1 = 0U;
  c17_info[37].fileTime2 = 0U;
  c17_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c17_info[38].name = "le";
  c17_info[38].dominantType = "double";
  c17_info[38].resolved = "[B]le";
  c17_info[38].fileLength = 0U;
  c17_info[38].fileTime1 = 0U;
  c17_info[38].fileTime2 = 0U;
  c17_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c17_info[39].name = "double";
  c17_info[39].dominantType = "double";
  c17_info[39].resolved = "[B]double";
  c17_info[39].fileLength = 0U;
  c17_info[39].fileTime1 = 0U;
  c17_info[39].fileTime2 = 0U;
  c17_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c17_info[40].name = "mtimes";
  c17_info[40].dominantType = "double";
  c17_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[40].fileLength = 3425U;
  c17_info[40].fileTime1 = 1251010272U;
  c17_info[40].fileTime2 = 0U;
  c17_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c17_info[41].name = "intmax";
  c17_info[41].dominantType = "char";
  c17_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c17_info[41].fileLength = 1535U;
  c17_info[41].fileTime1 = 1192445128U;
  c17_info[41].fileTime2 = 0U;
  c17_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c17_info[42].name = "ischar";
  c17_info[42].dominantType = "char";
  c17_info[42].resolved = "[B]ischar";
  c17_info[42].fileLength = 0U;
  c17_info[42].fileTime1 = 0U;
  c17_info[42].fileTime2 = 0U;
  c17_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c17_info[43].name = "int32";
  c17_info[43].dominantType = "double";
  c17_info[43].resolved = "[B]int32";
  c17_info[43].fileLength = 0U;
  c17_info[43].fileTime1 = 0U;
  c17_info[43].fileTime2 = 0U;
  c17_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  c17_info[44].name = "ones";
  c17_info[44].dominantType = "char";
  c17_info[44].resolved = "[B]ones";
  c17_info[44].fileLength = 0U;
  c17_info[44].fileTime1 = 0U;
  c17_info[44].fileTime2 = 0U;
  c17_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[45].name = "ndims";
  c17_info[45].dominantType = "double";
  c17_info[45].resolved = "[B]ndims";
  c17_info[45].fileLength = 0U;
  c17_info[45].fileTime1 = 0U;
  c17_info[45].fileTime2 = 0U;
  c17_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[46].name = "isempty";
  c17_info[46].dominantType = "double";
  c17_info[46].resolved = "[B]isempty";
  c17_info[46].fileLength = 0U;
  c17_info[46].fileTime1 = 0U;
  c17_info[46].fileTime2 = 0U;
  c17_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c17_info[47].name = "eml_xgemm";
  c17_info[47].dominantType = "int32";
  c17_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c17_info[47].fileLength = 3184U;
  c17_info[47].fileTime1 = 1209309252U;
  c17_info[47].fileTime2 = 0U;
  c17_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c17_info[48].name = "length";
  c17_info[48].dominantType = "double";
  c17_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c17_info[48].fileLength = 326U;
  c17_info[48].fileTime1 = 1226552074U;
  c17_info[48].fileTime2 = 0U;
  c17_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!itcount";
  c17_info[49].name = "min";
  c17_info[49].dominantType = "double";
  c17_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c17_info[49].fileLength = 362U;
  c17_info[49].fileTime1 = 1245080764U;
  c17_info[49].fileTime2 = 0U;
  c17_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c17_info[50].name = "nargout";
  c17_info[50].dominantType = "";
  c17_info[50].resolved = "[B]nargout";
  c17_info[50].fileLength = 0U;
  c17_info[50].fileTime1 = 0U;
  c17_info[50].fileTime2 = 0U;
  c17_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c17_info[51].name = "eml_min_or_max";
  c17_info[51].dominantType = "char";
  c17_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c17_info[51].fileLength = 9967U;
  c17_info[51].fileTime1 = 1261926670U;
  c17_info[51].fileTime2 = 0U;
  c17_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c17_info[52].name = "isnumeric";
  c17_info[52].dominantType = "double";
  c17_info[52].resolved = "[B]isnumeric";
  c17_info[52].fileLength = 0U;
  c17_info[52].fileTime1 = 0U;
  c17_info[52].fileTime2 = 0U;
  c17_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c17_info[53].name = "islogical";
  c17_info[53].dominantType = "double";
  c17_info[53].resolved = "[B]islogical";
  c17_info[53].fileLength = 0U;
  c17_info[53].fileTime1 = 0U;
  c17_info[53].fileTime2 = 0U;
  c17_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c17_info[54].name = "eml_refblas_xgemm";
  c17_info[54].dominantType = "int32";
  c17_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c17_info[54].fileLength = 5748U;
  c17_info[54].fileTime1 = 1228068672U;
  c17_info[54].fileTime2 = 0U;
  c17_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c17_info[55].name = "eml_index_minus";
  c17_info[55].dominantType = "int32";
  c17_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c17_info[55].fileLength = 277U;
  c17_info[55].fileTime1 = 1192445184U;
  c17_info[55].fileTime2 = 0U;
  c17_info[56].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c17_info[56].name = "eml_index_times";
  c17_info[56].dominantType = "int32";
  c17_info[56].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c17_info[56].fileLength = 280U;
  c17_info[56].fileTime1 = 1192445186U;
  c17_info[56].fileTime2 = 0U;
  c17_info[57].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c17_info[57].name = "eml_index_plus";
  c17_info[57].dominantType = "int32";
  c17_info[57].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c17_info[57].fileLength = 272U;
  c17_info[57].fileTime1 = 1192445184U;
  c17_info[57].fileTime2 = 0U;
}

static const mxArray *c17_h_sf_marshall(void *chartInstanceVoid, void *c17_u)
{
  const mxArray *c17_y = NULL;
  boolean_T c17_b_u;
  const mxArray *c17_b_y = NULL;
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)chartInstanceVoid;
  c17_y = NULL;
  c17_b_u = *((boolean_T *)c17_u);
  c17_b_y = NULL;
  sf_mex_assign(&c17_b_y, sf_mex_create("y", &c17_b_u, 11, 0U, 0U, 0U, 0));
  sf_mex_assign(&c17_y, c17_b_y);
  return c17_y;
}

static void c17_emlrt_marshallIn(SFc17_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *c17_M_Acc, const char_T *c17_name
  , real_T c17_y[6])
{
  real_T c17_dv16[6];
  int32_T c17_i82;
  sf_mex_import(c17_name, sf_mex_dup(c17_M_Acc), c17_dv16, 1, 0, 0U, 1, 0U, 1, 6);
  for (c17_i82 = 0; c17_i82 < 6; c17_i82 = c17_i82 + 1) {
    c17_y[c17_i82] = c17_dv16[c17_i82];
  }

  sf_mex_destroy(&c17_M_Acc);
}

static uint8_T c17_b_emlrt_marshallIn(SFc17_DynJointVerifyInstanceStruct
  *chartInstance, const mxArray *
  c17_b_is_active_c17_DynJointVerify, const char_T *c17_name)
{
  uint8_T c17_y;
  uint8_T c17_u0;
  sf_mex_import(c17_name, sf_mex_dup(c17_b_is_active_c17_DynJointVerify),
                &c17_u0, 1, 3, 0U, 0, 0U, 0);
  c17_y = c17_u0;
  sf_mex_destroy(&c17_b_is_active_c17_DynJointVerify);
  return c17_y;
}

static void init_dsm_address_info(SFc17_DynJointVerifyInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c17_DynJointVerify_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4233562422U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3539130194U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4284080937U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1401835521U);
}

mxArray *sf_c17_DynJointVerify_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(88187887U);
    pr[1] = (double)(3154154592U);
    pr[2] = (double)(1200350320U);
    pr[3] = (double)(4247990174U);
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

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(9);
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
      pr[1] = (double)(9);
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
      pr[1] = (double)(9);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(9);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(9);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(8);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(6);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
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

static mxArray *sf_get_sim_state_info_c17_DynJointVerify(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"M_Acc\",},{M[8],M[0],T\"is_active_c17_DynJointVerify\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c17_DynJointVerify_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc17_DynJointVerifyInstanceStruct *chartInstance;
    chartInstance = (SFc17_DynJointVerifyInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_DynJointVerifyMachineNumber_,
           17,
           1,
           1,
           12,
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
          init_script_number_translation(_DynJointVerifyMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_DynJointVerifyMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_DynJointVerifyMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"RefAcc");
          _SFD_SET_DATA_PROPS(1,1,1,0,"EnTheta");
          _SFD_SET_DATA_PROPS(2,2,0,1,"M_Acc");
          _SFD_SET_DATA_PROPS(3,10,0,0,"L_EU");
          _SFD_SET_DATA_PROPS(4,10,0,0,"Cen");
          _SFD_SET_DATA_PROPS(5,10,0,0,"Ma");
          _SFD_SET_DATA_PROPS(6,10,0,0,"Ie1");
          _SFD_SET_DATA_PROPS(7,10,0,0,"Ie2");
          _SFD_SET_DATA_PROPS(8,10,0,0,"Ie3");
          _SFD_SET_DATA_PROPS(9,10,0,0,"Ie4");
          _SFD_SET_DATA_PROPS(10,10,0,0,"Ie5");
          _SFD_SET_DATA_PROPS(11,10,0,0,"Ie6");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,169);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"EulerMd",0,-1,15626);
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
            1.0,0,0,(MexFcnForType)c17_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshall);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_f_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 18;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_e_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_d_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshall);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 1;
          dimVector[1]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c17_b_sf_marshall);
        }

        {
          real_T (*c17_RefAcc)[6];
          real_T (*c17_EnTheta)[6];
          real_T (*c17_M_Acc)[6];
          c17_M_Acc = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 1);
          c17_EnTheta = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c17_RefAcc = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c17_RefAcc);
          _SFD_SET_DATA_VALUE_PTR(1U, *c17_EnTheta);
          _SFD_SET_DATA_VALUE_PTR(2U, *c17_M_Acc);
          _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c17_L_EU);
          _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c17_Cen);
          _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c17_Ma);
          _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c17_Ie1);
          _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c17_Ie2);
          _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c17_Ie3);
          _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c17_Ie4);
          _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c17_Ie5);
          _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c17_Ie6);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_DynJointVerifyMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c17_DynJointVerify(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc17_DynJointVerifyInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
  initialize_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c17_DynJointVerify(void *chartInstanceVar)
{
  enable_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c17_DynJointVerify(void *chartInstanceVar)
{
  disable_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c17_DynJointVerify(void *chartInstanceVar)
{
  sf_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

static mxArray* sf_internal_get_sim_state_c17_DynJointVerify(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c17_DynJointVerify
    ((SFc17_DynJointVerifyInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = sf_get_sim_state_info_c17_DynJointVerify();/* state var info */
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

static void sf_internal_set_sim_state_c17_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c17_DynJointVerify();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static mxArray* sf_opaque_get_sim_state_c17_DynJointVerify(SimStruct* S)
{
  return sf_internal_get_sim_state_c17_DynJointVerify(S);
}

static void sf_opaque_set_sim_state_c17_DynJointVerify(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c17_DynJointVerify(S, st);
}

static void sf_opaque_terminate_c17_DynJointVerify(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc17_DynJointVerifyInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  compInitSubchartSimstructsFcn_c17_DynJointVerify
    ((SFc17_DynJointVerifyInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c17_DynJointVerify(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c17_DynJointVerify((SFc17_DynJointVerifyInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c17_DynJointVerify(SimStruct *S)
{
  /* Actual parameters from chart:
     Cen Ie1 Ie2 Ie3 Ie4 Ie5 Ie6 L_EU Ma
   */
  const char_T *rtParamNames[] = { "p1", "p2", "p3", "p4", "p5", "p6", "p7",
    "p8", "p9" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Cen*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for Ie1*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for Ie2*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for Ie3*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for Ie4*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);

  /* registration for Ie5*/
  ssRegDlgParamAsRunTimeParam(S, 5, 5, rtParamNames[5], SS_DOUBLE);

  /* registration for Ie6*/
  ssRegDlgParamAsRunTimeParam(S, 6, 6, rtParamNames[6], SS_DOUBLE);

  /* registration for L_EU*/
  ssRegDlgParamAsRunTimeParam(S, 7, 7, rtParamNames[7], SS_DOUBLE);

  /* registration for Ma*/
  ssRegDlgParamAsRunTimeParam(S, 8, 8, rtParamNames[8], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"DynJointVerify","DynJointVerify",17);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"DynJointVerify","DynJointVerify",17,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"DynJointVerify",
      "DynJointVerify",17,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"DynJointVerify","DynJointVerify",17,
        2);
      sf_mark_chart_reusable_outputs(S,"DynJointVerify","DynJointVerify",17,1);
    }

    sf_set_rtw_dwork_info(S,"DynJointVerify","DynJointVerify",17);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3947355369U));
  ssSetChecksum1(S,(544780767U));
  ssSetChecksum2(S,(3776545130U));
  ssSetChecksum3(S,(3787193682U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c17_DynJointVerify(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "DynJointVerify", "DynJointVerify",17);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c17_DynJointVerify(SimStruct *S)
{
  SFc17_DynJointVerifyInstanceStruct *chartInstance;
  chartInstance = (SFc17_DynJointVerifyInstanceStruct *)malloc(sizeof
    (SFc17_DynJointVerifyInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc17_DynJointVerifyInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c17_DynJointVerify;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c17_DynJointVerify;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c17_DynJointVerify;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c17_DynJointVerify;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c17_DynJointVerify;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c17_DynJointVerify;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c17_DynJointVerify;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c17_DynJointVerify;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c17_DynJointVerify;
  chartInstance->chartInfo.mdlStart = mdlStart_c17_DynJointVerify;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c17_DynJointVerify;
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

void c17_DynJointVerify_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c17_DynJointVerify(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c17_DynJointVerify(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c17_DynJointVerify(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c17_DynJointVerify_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
