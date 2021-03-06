/* Include files */

#include "CtrPlatform_gravity_compensation_sfun.h"
#include "c1_CtrPlatform_gravity_compensation.h"
#include "c2_CtrPlatform_gravity_compensation.h"
#include "c3_CtrPlatform_gravity_compensation.h"
#include "c4_CtrPlatform_gravity_compensation.h"
#include "c5_CtrPlatform_gravity_compensation.h"
#include "c6_CtrPlatform_gravity_compensation.h"
#include "c7_CtrPlatform_gravity_compensation.h"
#include "c12_CtrPlatform_gravity_compensation.h"
#include "c13_CtrPlatform_gravity_compensation.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _CtrPlatform_gravity_compensationMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void CtrPlatform_gravity_compensation_initializer(void)
{
}

void CtrPlatform_gravity_compensation_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_CtrPlatform_gravity_compensation_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_CtrPlatform_gravity_compensation_method_dispatcher(simstructPtr, method,
      data);
    return 1;
  }

  return 0;
}

unsigned int sf_CtrPlatform_gravity_compensation_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3042827959U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3429127863U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2704451464U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3558718407U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1861392761U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3969265826U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1211562493U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2009192395U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c1_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c2_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c3_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c4_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c5_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c6_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c7_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c12_CtrPlatform_gravity_compensation_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_CtrPlatform_gravity_compensation_get_check_sum
            (mxArray *plhs[]);
          sf_c13_CtrPlatform_gravity_compensation_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1752522422U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(815160264U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4079683761U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(333497245U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_CtrPlatform_gravity_compensation_autoinheritance_info( int nlhs,
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
            *sf_c1_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ot4U1nCk49DNl7WZ9fJkKB") == 0) {
          extern mxArray
            *sf_c2_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "X2jQw722RpRQNpGwqWhBWE") == 0) {
          extern mxArray
            *sf_c3_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c3_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "yn5jSlwEJzOxLC6FfpO5AE") == 0) {
          extern mxArray
            *sf_c4_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c4_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "O5G5Vq8ctoyPmxehF46mJ") == 0) {
          extern mxArray
            *sf_c5_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c5_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "Fr9gPROTYEiqXEjKtPaUOG") == 0) {
          extern mxArray
            *sf_c6_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c6_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "ot4U1nCk49DNl7WZ9fJkKB") == 0) {
          extern mxArray
            *sf_c7_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c7_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "vbrrXpunyQmJEzoNDHbAOH") == 0) {
          extern mxArray
            *sf_c12_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c12_CtrPlatform_gravity_compensation_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "H4TB6i7X12dUdqLTZuJJLD") == 0) {
          extern mxArray
            *sf_c13_CtrPlatform_gravity_compensation_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c13_CtrPlatform_gravity_compensation_get_autoinheritance_info();
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

unsigned int sf_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
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
          *sf_c1_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_CtrPlatform_gravity_compensation_get_eml_resolved_functions_info
          ();
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

void CtrPlatform_gravity_compensation_debug_initialize(void)
{
  _CtrPlatform_gravity_compensationMachineNumber_ = sf_debug_initialize_machine(
    "CtrPlatform_gravity_compensation","sfun",0,9,0,0,0);
  sf_debug_set_machine_event_thresholds
    (_CtrPlatform_gravity_compensationMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds
    (_CtrPlatform_gravity_compensationMachineNumber_,0);
}

void CtrPlatform_gravity_compensation_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_CtrPlatform_gravity_compensation_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "CtrPlatform_gravity_compensation", "CtrPlatform_gravity_compensation");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_CtrPlatform_gravity_compensation_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
