/* Include files */

#include "DynEulerJointVerify_sfun.h"
#include "c1_DynEulerJointVerify.h"
#include "c2_DynEulerJointVerify.h"
#include "c3_DynEulerJointVerify.h"
#include "c6_DynEulerJointVerify.h"
#include "c7_DynEulerJointVerify.h"
#include "c8_DynEulerJointVerify.h"
#include "c9_DynEulerJointVerify.h"
#include "c10_DynEulerJointVerify.h"
#include "c11_DynEulerJointVerify.h"
#include "c12_DynEulerJointVerify.h"
#include "c13_DynEulerJointVerify.h"
#include "c14_DynEulerJointVerify.h"
#include "c15_DynEulerJointVerify.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _DynEulerJointVerifyMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void DynEulerJointVerify_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void DynEulerJointVerify_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DynEulerJointVerify_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_DynEulerJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DynEulerJointVerify_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(138180154U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2381085514U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(748372990U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3286682087U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3304572048U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3926979268U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3158226833U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3826950399U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c1_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c2_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c3_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c6_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c7_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c8_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c9_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c10_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c11_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c12_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c13_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c14_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_DynEulerJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c15_DynEulerJointVerify_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3176360410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1862911626U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(659157607U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884031890U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1355121895U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3534658792U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(687054702U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2191967096U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DynEulerJointVerify_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  if (nrhs<2 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern mxArray *sf_c1_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c1_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c2_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c3_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c6_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c7_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c8_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c9_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray *sf_c10_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c10_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c11_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray *sf_c12_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c12_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray *sf_c13_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c13_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray *sf_c14_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c14_DynEulerJointVerify_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray *sf_c15_DynEulerJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c15_DynEulerJointVerify_get_autoinheritance_info();
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

unsigned int sf_DynEulerJointVerify_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
          *sf_c1_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_DynEulerJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_DynEulerJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_DynEulerJointVerify_get_eml_resolved_functions_info();
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

void DynEulerJointVerify_debug_initialize(void)
{
  _DynEulerJointVerifyMachineNumber_ = sf_debug_initialize_machine(
    "DynEulerJointVerify","sfun",0,13,0,0,0);
  sf_debug_set_machine_event_thresholds(_DynEulerJointVerifyMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_DynEulerJointVerifyMachineNumber_,0);
}

void DynEulerJointVerify_register_exported_symbols(SimStruct* S)
{
}
