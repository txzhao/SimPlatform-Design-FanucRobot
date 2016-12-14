/* Include files */

#include "DynTaskCon_sfun.h"
#include "c1_DynTaskCon.h"
#include "c2_DynTaskCon.h"
#include "c3_DynTaskCon.h"
#include "c4_DynTaskCon.h"
#include "c5_DynTaskCon.h"
#include "c6_DynTaskCon.h"
#include "c7_DynTaskCon.h"
#include "c8_DynTaskCon.h"
#include "c9_DynTaskCon.h"
#include "c10_DynTaskCon.h"
#include "c11_DynTaskCon.h"
#include "c12_DynTaskCon.h"
#include "c13_DynTaskCon.h"
#include "c14_DynTaskCon.h"
#include "c15_DynTaskCon.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _DynTaskConMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void DynTaskCon_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void DynTaskCon_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DynTaskCon_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_DynTaskCon_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DynTaskCon_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3026516125U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3574084581U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2693526930U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3739382653U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1754363581U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(519225520U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2720355308U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1472083823U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c1_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c2_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c3_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c4_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c5_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c6_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c7_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c8_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c9_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c10_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c11_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c12_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c13_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c14_DynTaskCon_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_DynTaskCon_get_check_sum(mxArray *plhs[]);
          sf_c15_DynTaskCon_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(367718652U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3862702068U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(786455893U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1592822807U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DynTaskCon_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
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
        extern mxArray *sf_c1_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c1_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c2_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c3_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c4_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c5_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c6_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c7_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c8_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c9_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray *sf_c10_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c10_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c11_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray *sf_c12_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c12_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray *sf_c13_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c13_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray *sf_c14_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c14_DynTaskCon_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray *sf_c15_DynTaskCon_get_autoinheritance_info(void);
        plhs[0] = sf_c15_DynTaskCon_get_autoinheritance_info();
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

unsigned int sf_DynTaskCon_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        extern const mxArray *sf_c1_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray *sf_c8_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray *sf_c9_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray *sf_c10_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray *sf_c11_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray *sf_c14_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_DynTaskCon_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray *sf_c15_DynTaskCon_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_DynTaskCon_get_eml_resolved_functions_info();
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

void DynTaskCon_debug_initialize(void)
{
  _DynTaskConMachineNumber_ = sf_debug_initialize_machine("DynTaskCon","sfun",0,
    15,0,0,0);
  sf_debug_set_machine_event_thresholds(_DynTaskConMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_DynTaskConMachineNumber_,0);
}

void DynTaskCon_register_exported_symbols(SimStruct* S)
{
}
