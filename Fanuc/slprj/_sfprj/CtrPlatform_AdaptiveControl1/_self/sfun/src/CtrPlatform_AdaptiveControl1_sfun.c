/* Include files */

#include "CtrPlatform_AdaptiveControl1_sfun.h"
#include "c1_CtrPlatform_AdaptiveControl1.h"
#include "c2_CtrPlatform_AdaptiveControl1.h"
#include "c3_CtrPlatform_AdaptiveControl1.h"
#include "c4_CtrPlatform_AdaptiveControl1.h"
#include "c5_CtrPlatform_AdaptiveControl1.h"
#include "c6_CtrPlatform_AdaptiveControl1.h"
#include "c7_CtrPlatform_AdaptiveControl1.h"
#include "c8_CtrPlatform_AdaptiveControl1.h"
#include "c9_CtrPlatform_AdaptiveControl1.h"
#include "c10_CtrPlatform_AdaptiveControl1.h"
#include "c12_CtrPlatform_AdaptiveControl1.h"
#include "c13_CtrPlatform_AdaptiveControl1.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CtrPlatform_AdaptiveControl1MachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void CtrPlatform_AdaptiveControl1_initializer(void)
{
}

void CtrPlatform_AdaptiveControl1_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CtrPlatform_AdaptiveControl1_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_CtrPlatform_AdaptiveControl1_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_CtrPlatform_AdaptiveControl1_process_check_sum_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(202126258U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2768345928U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1009332054U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1862470422U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(166247482U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(926620948U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3912344938U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1607649345U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c1_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c2_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c3_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c4_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c5_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c6_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c7_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c8_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray
            *plhs[]);
          sf_c9_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray *
            plhs[]);
          sf_c10_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray *
            plhs[]);
          sf_c12_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_CtrPlatform_AdaptiveControl1_get_check_sum(mxArray *
            plhs[]);
          sf_c13_CtrPlatform_AdaptiveControl1_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3564696471U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(678668628U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1090454852U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3896867807U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1992201530U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2544367102U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2725822822U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3797843660U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CtrPlatform_AdaptiveControl1_autoinheritance_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "Fr9gPROTYEiqXEjKtPaUOG") == 0) {
          extern mxArray
            *sf_c1_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c1_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ot4U1nCk49DNl7WZ9fJkKB") == 0) {
          extern mxArray
            *sf_c2_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c2_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "X2jQw722RpRQNpGwqWhBWE") == 0) {
          extern mxArray
            *sf_c3_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c3_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "yn5jSlwEJzOxLC6FfpO5AE") == 0) {
          extern mxArray
            *sf_c4_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c4_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "O5G5Vq8ctoyPmxehF46mJ") == 0) {
          extern mxArray
            *sf_c5_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c5_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "Fr9gPROTYEiqXEjKtPaUOG") == 0) {
          extern mxArray
            *sf_c6_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c6_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "ot4U1nCk49DNl7WZ9fJkKB") == 0) {
          extern mxArray
            *sf_c7_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c7_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "X2jQw722RpRQNpGwqWhBWE") == 0) {
          extern mxArray
            *sf_c8_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c8_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "O5G5Vq8ctoyPmxehF46mJ") == 0) {
          extern mxArray
            *sf_c9_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c9_CtrPlatform_AdaptiveControl1_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "yn5jSlwEJzOxLC6FfpO5AE") == 0) {
          extern mxArray
            *sf_c10_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c10_CtrPlatform_AdaptiveControl1_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "vbrrXpunyQmJEzoNDHbAOH") == 0) {
          extern mxArray
            *sf_c12_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c12_CtrPlatform_AdaptiveControl1_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "H4TB6i7X12dUdqLTZuJJLD") == 0) {
          extern mxArray
            *sf_c13_CtrPlatform_AdaptiveControl1_get_autoinheritance_info(void);
          plhs[0] = sf_c13_CtrPlatform_AdaptiveControl1_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_CtrPlatform_AdaptiveControl1_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void CtrPlatform_AdaptiveControl1_debug_initialize(void)
{
  _CtrPlatform_AdaptiveControl1MachineNumber_ = sf_debug_initialize_machine(
    "CtrPlatform_AdaptiveControl1","sfun",0,12,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_CtrPlatform_AdaptiveControl1MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_CtrPlatform_AdaptiveControl1MachineNumber_,0);
}

void CtrPlatform_AdaptiveControl1_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_CtrPlatform_AdaptiveControl1_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "CtrPlatform_AdaptiveControl1", "CtrPlatform_AdaptiveControl1");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CtrPlatform_AdaptiveControl1_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
