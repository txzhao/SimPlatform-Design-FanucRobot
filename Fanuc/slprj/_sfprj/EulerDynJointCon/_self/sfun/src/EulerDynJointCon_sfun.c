/* Include files */

#include "EulerDynJointCon_sfun.h"
#include "c1_EulerDynJointCon.h"
#include "c2_EulerDynJointCon.h"
#include "c3_EulerDynJointCon.h"
#include "c6_EulerDynJointCon.h"
#include "c7_EulerDynJointCon.h"
#include "c8_EulerDynJointCon.h"
#include "c9_EulerDynJointCon.h"
#include "c10_EulerDynJointCon.h"
#include "c11_EulerDynJointCon.h"
#include "c12_EulerDynJointCon.h"
#include "c13_EulerDynJointCon.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _EulerDynJointConMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void EulerDynJointCon_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void EulerDynJointCon_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_EulerDynJointCon_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_EulerDynJointCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_EulerDynJointCon_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2499024455U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3393759751U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2053299107U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1884736019U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1311989357U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1677830615U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(190248972U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2862346448U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c1_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c2_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c3_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c6_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c7_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c8_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c9_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c10_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c11_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c12_EulerDynJointCon_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_EulerDynJointCon_get_check_sum(mxArray *plhs[]);
          sf_c13_EulerDynJointCon_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4197106722U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2446113287U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2407076917U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2631226960U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_EulerDynJointCon_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
        extern mxArray *sf_c1_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c1_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c2_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c3_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c6_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c7_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c8_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c9_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray *sf_c10_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c10_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c11_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray *sf_c12_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c12_EulerDynJointCon_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray *sf_c13_EulerDynJointCon_get_autoinheritance_info(void);
        plhs[0] = sf_c13_EulerDynJointCon_get_autoinheritance_info();
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

unsigned int sf_EulerDynJointCon_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_EulerDynJointCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_EulerDynJointCon_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_EulerDynJointCon_get_eml_resolved_functions_info();
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

void EulerDynJointCon_debug_initialize(void)
{
  _EulerDynJointConMachineNumber_ = sf_debug_initialize_machine(
    "EulerDynJointCon","sfun",0,11,0,0,0);
  sf_debug_set_machine_event_thresholds(_EulerDynJointConMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_EulerDynJointConMachineNumber_,0);
}

void EulerDynJointCon_register_exported_symbols(SimStruct* S)
{
}
