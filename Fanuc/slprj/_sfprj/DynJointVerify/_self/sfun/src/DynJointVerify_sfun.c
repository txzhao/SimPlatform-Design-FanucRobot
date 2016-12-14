/* Include files */

#include "DynJointVerify_sfun.h"
#include "c1_DynJointVerify.h"
#include "c2_DynJointVerify.h"
#include "c3_DynJointVerify.h"
#include "c4_DynJointVerify.h"
#include "c5_DynJointVerify.h"
#include "c6_DynJointVerify.h"
#include "c7_DynJointVerify.h"
#include "c8_DynJointVerify.h"
#include "c9_DynJointVerify.h"
#include "c10_DynJointVerify.h"
#include "c11_DynJointVerify.h"
#include "c12_DynJointVerify.h"
#include "c13_DynJointVerify.h"
#include "c14_DynJointVerify.h"
#include "c15_DynJointVerify.h"
#include "c16_DynJointVerify.h"
#include "c17_DynJointVerify.h"
#include "c18_DynJointVerify.h"
#include "c19_DynJointVerify.h"
#include "c20_DynJointVerify.h"
#include "c21_DynJointVerify.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
int32_T _sfEvent_;
uint32_T _DynJointVerifyMachineNumber_;
real_T _sfTime_;

/* Function Declarations */

/* Function Definitions */
void DynJointVerify_initializer(void)
{
  _sfEvent_ = CALL_EVENT;
}

void DynJointVerify_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DynJointVerify_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==14) {
    c14_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_DynJointVerify_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_DynJointVerify_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1392508326U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(266834953U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(978746667U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3815907208U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1890923931U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2654031051U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3989870665U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(541013555U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c1_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c2_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c3_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c4_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c5_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c6_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c7_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c8_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c9_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c10_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c11_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c12_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 13:
        {
          extern void sf_c13_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c13_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 14:
        {
          extern void sf_c14_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c14_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c15_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c16_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c17_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c18_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c19_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c20_DynJointVerify_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_DynJointVerify_get_check_sum(mxArray *plhs[]);
          sf_c21_DynJointVerify_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(968491599U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(417368020U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4226607974U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3155452071U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DynJointVerify_autoinheritance_info( int nlhs, mxArray * plhs[],
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
        extern mxArray *sf_c1_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c1_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 2:
      {
        extern mxArray *sf_c2_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c2_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 3:
      {
        extern mxArray *sf_c3_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c3_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 4:
      {
        extern mxArray *sf_c4_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c4_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 5:
      {
        extern mxArray *sf_c5_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c5_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 6:
      {
        extern mxArray *sf_c6_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c6_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 7:
      {
        extern mxArray *sf_c7_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c7_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 8:
      {
        extern mxArray *sf_c8_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c8_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c9_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 10:
      {
        extern mxArray *sf_c10_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c10_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 11:
      {
        extern mxArray *sf_c11_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c11_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 12:
      {
        extern mxArray *sf_c12_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c12_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 13:
      {
        extern mxArray *sf_c13_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c13_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 14:
      {
        extern mxArray *sf_c14_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c14_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 15:
      {
        extern mxArray *sf_c15_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c15_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 16:
      {
        extern mxArray *sf_c16_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c16_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 17:
      {
        extern mxArray *sf_c17_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c17_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 18:
      {
        extern mxArray *sf_c18_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c18_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 19:
      {
        extern mxArray *sf_c19_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c19_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 20:
      {
        extern mxArray *sf_c20_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c20_DynJointVerify_get_autoinheritance_info();
        break;
      }

     case 21:
      {
        extern mxArray *sf_c21_DynJointVerify_get_autoinheritance_info(void);
        plhs[0] = sf_c21_DynJointVerify_get_autoinheritance_info();
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

unsigned int sf_DynJointVerify_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray
          *sf_c12_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray
          *sf_c13_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 14:
      {
        extern const mxArray
          *sf_c14_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c14_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_DynJointVerify_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_DynJointVerify_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_DynJointVerify_get_eml_resolved_functions_info();
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

void DynJointVerify_debug_initialize(void)
{
  _DynJointVerifyMachineNumber_ = sf_debug_initialize_machine("DynJointVerify",
    "sfun",0,21,0,0,0);
  sf_debug_set_machine_event_thresholds(_DynJointVerifyMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_DynJointVerifyMachineNumber_,0);
}

void DynJointVerify_register_exported_symbols(SimStruct* S)
{
}
