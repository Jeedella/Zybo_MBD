/*
 * File: cstm_Serial_16550_Write___.c
 *
 *
 *   --- THIS FILE GENERATED BY S-FUNCTION BUILDER: 3.0 ---
 *
 *   This file is an S-function produced by the S-Function
 *   Builder which only recognizes certain fields.  Changes made
 *   outside these fields will be lost the next time the block is
 *   used to load, edit, and resave this file. This file will be overwritten
 *   by the S-function Builder block. If you want to edit this file by hand, 
 *   you must change it only in the area defined as:  
 *
 *        %%%-SFUNWIZ_defines_Changes_BEGIN
 *        #define NAME 'replacement text' 
 *        %%% SFUNWIZ_defines_Changes_END
 *
 *   DO NOT change NAME--Change the 'replacement text' only.
 *
 *   For better compatibility with the Simulink Coder, the
 *   "wrapper" S-function technique is used.  This is discussed
 *   in the Simulink Coder's Manual in the Chapter titled,
 *   "Wrapper S-functions".
 *
 *  -------------------------------------------------------------------------
 * | See matlabroot/simulink/src/sfuntmpl_doc.c for a more detailed template |
 *  ------------------------------------------------------------------------- 
 *
 * Created: Thu Jun 04 19:20:17 2020
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME cstm_Serial_16550_Write___
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS            1
/* Input Port  0 */
#define IN_PORT_0_NAME        Data
#define INPUT_0_WIDTH         DYNAMICALLY_SIZED
#define INPUT_DIMS_0_COL      1
#define INPUT_0_DTYPE         uint8_T
#define INPUT_0_COMPLEX       COMPLEX_NO
#define IN_0_FRAME_BASED      FRAME_NO
#define IN_0_BUS_BASED        0
#define IN_0_BUS_NAME         
#define IN_0_DIMS             1-D
#define INPUT_0_FEEDTHROUGH   1
#define IN_0_ISSIGNED         0
#define IN_0_WORDLENGTH       8
#define IN_0_FIXPOINTSCALING  1
#define IN_0_FRACTIONLENGTH   9
#define IN_0_BIAS             0
#define IN_0_SLOPE            0.125

#define NUM_OUTPUTS           0

#define NPARAMS               4
/* Parameter 0 */
#define PARAMETER_0_NAME      Port
#define PARAMETER_0_DTYPE     uint32_T
#define PARAMETER_0_COMPLEX   COMPLEX_NO
/* Parameter 1 */
#define PARAMETER_1_NAME      BaudRate
#define PARAMETER_1_DTYPE     uint32_T
#define PARAMETER_1_COMPLEX   COMPLEX_NO
/* Parameter 2 */
#define PARAMETER_2_NAME      Parity
#define PARAMETER_2_DTYPE     uint32_T
#define PARAMETER_2_COMPLEX   COMPLEX_NO
/* Parameter 3 */
#define PARAMETER_3_NAME      StopBits
#define PARAMETER_3_DTYPE     uint32_T
#define PARAMETER_3_COMPLEX   COMPLEX_NO

#define SAMPLE_TIME_0         INHERITED_SAMPLE_TIME
#define NUM_DISC_STATES       0
#define DISC_STATES_IC        [0]
#define NUM_CONT_STATES       0
#define CONT_STATES_IC        [0]

#define SFUNWIZ_GENERATE_TLC  1
#define SOURCEFILES           "__SFB__"
#define PANELINDEX            8
#define USE_SIMSTRUCT         0
#define SHOW_COMPILE_STEPS    0
#define CREATE_DEBUG_MEXFILE  0
#define SAVE_CODE_ONLY        0
#define SFUNWIZ_REVISION      3.0
/* %%%-SFUNWIZ_defines_Changes_END --- EDIT HERE TO _BEGIN */
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
#include "simstruc.h"

#define PARAM_DEF0(S) ssGetSFcnParam(S, 0)
#define PARAM_DEF1(S) ssGetSFcnParam(S, 1)
#define PARAM_DEF2(S) ssGetSFcnParam(S, 2)
#define PARAM_DEF3(S) ssGetSFcnParam(S, 3)

#define IS_PARAM_UINT32(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsUint32(pVal))

extern void cstm_Serial_16550_Write____Outputs_wrapper(const uint8_T *Data,
			const uint32_T *Port, const int_T p_width0,
			const uint32_T *BaudRate, const int_T p_width1,
			const uint32_T *Parity, const int_T p_width2,
			const uint32_T *StopBits, const int_T p_width3,
			const int_T u_width);
/*====================*
 * S-function methods *
 *====================*/
#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)
/* Function: mdlCheckParameters =============================================
 * Abstract:
 *     Verify parameter definitions and types.
 */
static void mdlCheckParameters(SimStruct *S)
{
    int paramIndex  = 0;
    bool invalidParam = false;
    /* All parameters must match the S-function Builder Dialog */

    {
        const mxArray *pVal0 = ssGetSFcnParam(S, 0);
        if (!IS_PARAM_UINT32(pVal0)) {
            invalidParam = true;
            paramIndex = 0;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal1 = ssGetSFcnParam(S, 1);
        if (!IS_PARAM_UINT32(pVal1)) {
            invalidParam = true;
            paramIndex = 1;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal2 = ssGetSFcnParam(S, 2);
        if (!IS_PARAM_UINT32(pVal2)) {
            invalidParam = true;
            paramIndex = 2;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal3 = ssGetSFcnParam(S, 3);
        if (!IS_PARAM_UINT32(pVal3)) {
            invalidParam = true;
            paramIndex = 3;
            goto EXIT_POINT;
        }
    }


    EXIT_POINT:
    if (invalidParam) {
        char parameterErrorMsg[1024];
        sprintf(parameterErrorMsg, "The data type and or complexity of parameter %d does not match the "
                "information specified in the S-function Builder dialog. "
                "For non-double parameters you will need to cast them using int8, int16, "
                "int32, uint8, uint16, uint32 or boolean.", paramIndex + 1);
        ssSetErrorStatus(S, parameterErrorMsg);
    }
    return;
}
#endif /* MDL_CHECK_PARAMETERS */
/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{

    DECL_AND_INIT_DIMSINFO(inputDimsInfo);
    DECL_AND_INIT_DIMSINFO(outputDimsInfo);
    ssSetNumSFcnParams(S, NPARAMS); /* Number of expected parameters */
    #if defined(MATLAB_MEX_FILE)
    if (ssGetNumSFcnParams(S) == ssGetSFcnParamsCount(S)) {
        mdlCheckParameters(S);
        if (ssGetErrorStatus(S) != NULL) {
            return;
        }
    } else {
        return; /* Parameter mismatch will be reported by Simulink */
    }
    #endif

    ssSetArrayLayoutForCodeGen(S, SS_COLUMN_MAJOR);

    ssSetOperatingPointCompliance(S, USE_DEFAULT_OPERATING_POINT);

    ssSetNumContStates(S, NUM_CONT_STATES);
    ssSetNumDiscStates(S, NUM_DISC_STATES);


    if (!ssSetNumInputPorts(S, NUM_INPUTS)) return;
    /* Input Port 0 */
    ssSetInputPortWidth(S, 0, INPUT_0_WIDTH);
    ssSetInputPortDataType(S, 0, SS_UINT8);
    ssSetInputPortComplexSignal(S, 0, INPUT_0_COMPLEX);
    ssSetInputPortDirectFeedThrough(S, 0, INPUT_0_FEEDTHROUGH);
    ssSetInputPortRequiredContiguous(S, 0, 1); /*direct input signal access*/


    if (!ssSetNumOutputPorts(S, NUM_OUTPUTS)) return;
    ssSetNumPWork(S, 0);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    ssSetSimulinkVersionGeneratedIn(S, "10.1");

    /* Take care when specifying exception free code - see sfuntmpl_doc.c */
    ssSetOptions(S, (SS_OPTION_EXCEPTION_FREE_CODE |
                     SS_OPTION_USE_TLC_WITH_ACCELERATOR |
                     SS_OPTION_WORKS_WITH_CODE_REUSE));
}

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specifiy  the sample time.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLE_TIME_0);
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_SET_INPUT_PORT_DATA_TYPE
static void mdlSetInputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetInputPortDataType(S, 0, dType);
}

#define MDL_SET_OUTPUT_PORT_DATA_TYPE
static void mdlSetOutputPortDataType(SimStruct *S, int port, DTypeId dType)
{
    ssSetOutputPortDataType(S, 0, dType);
}

#define MDL_SET_DEFAULT_PORT_DATA_TYPES
static void mdlSetDefaultPortDataTypes(SimStruct *S)
{
    ssSetInputPortDataType(S, 0, SS_DOUBLE);
    ssSetOutputPortDataType(S, 0, SS_DOUBLE);
}

#define MDL_SET_WORK_WIDTHS
#if defined(MDL_SET_WORK_WIDTHS) && defined(MATLAB_MEX_FILE)

static void mdlSetWorkWidths(SimStruct *S)
{

    const char_T *rtParamNames[] = {"P1","P2","P3","P4"};
    ssRegAllTunableParamsAsRunTimeParams(S, rtParamNames);

}

#endif

#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START)
/* Function: mdlStart =======================================================
 * Abstract:
 *    This function is called once at start of model execution. If you
 *    have states that should be initialized once, this is the place
 *    to do it.
 */
static void mdlStart(SimStruct *S)
{
}
#endif /*  MDL_START */

/* Function: mdlOutputs =======================================================
 *
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const uint8_T *Data = (uint8_T *) ssGetInputPortRealSignal(S, 0);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const int_T   p_width2  = mxGetNumberOfElements(PARAM_DEF2(S));
    const int_T   p_width3  = mxGetNumberOfElements(PARAM_DEF3(S));
    const uint32_T *Port = (const uint32_T *) mxGetData(PARAM_DEF0(S));
    const uint32_T *BaudRate = (const uint32_T *) mxGetData(PARAM_DEF1(S));
    const uint32_T *Parity = (const uint32_T *) mxGetData(PARAM_DEF2(S));
    const uint32_T *StopBits = (const uint32_T *) mxGetData(PARAM_DEF3(S));
        const int_T u_width = ssGetInputPortWidth(S, 0);

    cstm_Serial_16550_Write____Outputs_wrapper(Data, Port, p_width0, BaudRate, p_width1, Parity, p_width2, StopBits, p_width3, u_width);

}

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{

}


#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif


