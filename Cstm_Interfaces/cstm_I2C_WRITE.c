/*
 * File: cstm_I2C_WRITE.c
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
 * Created: Thu May 28 01:53:15 2020
 */

#define S_FUNCTION_LEVEL 2
#define S_FUNCTION_NAME cstm_I2C_WRITE
/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
/* %%%-SFUNWIZ_defines_Changes_BEGIN --- EDIT HERE TO _END */
#define NUM_INPUTS            1
/* Input Port  0 */
#define IN_PORT_0_NAME        InputMessage
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

#define NUM_OUTPUTS           1
/* Output Port  0 */
#define OUT_PORT_0_NAME       ErrorStatus
#define OUTPUT_0_WIDTH        1
#define OUTPUT_DIMS_0_COL     1
#define OUTPUT_0_DTYPE        int32_T
#define OUTPUT_0_COMPLEX      COMPLEX_NO
#define OUT_0_FRAME_BASED     FRAME_NO
#define OUT_0_BUS_BASED       0
#define OUT_0_BUS_NAME        
#define OUT_0_DIMS            1-D
#define OUT_0_ISSIGNED        1
#define OUT_0_WORDLENGTH      8
#define OUT_0_FIXPOINTSCALING 1
#define OUT_0_FRACTIONLENGTH  3
#define OUT_0_BIAS            0
#define OUT_0_SLOPE           0.125

#define NPARAMS               7
/* Parameter 0 */
#define PARAMETER_0_NAME      addr
#define PARAMETER_0_DTYPE     uint8_T
#define PARAMETER_0_COMPLEX   COMPLEX_NO
/* Parameter 1 */
#define PARAMETER_1_NAME      adapter_nr
#define PARAMETER_1_DTYPE     uint8_T
#define PARAMETER_1_COMPLEX   COMPLEX_NO
/* Parameter 2 */
#define PARAMETER_2_NAME      byte_order
#define PARAMETER_2_DTYPE     uint8_T
#define PARAMETER_2_COMPLEX   COMPLEX_NO
/* Parameter 3 */
#define PARAMETER_3_NAME      send_register
#define PARAMETER_3_DTYPE     uint8_T
#define PARAMETER_3_COMPLEX   COMPLEX_NO
/* Parameter 4 */
#define PARAMETER_4_NAME      slave_register
#define PARAMETER_4_DTYPE     uint8_T
#define PARAMETER_4_COMPLEX   COMPLEX_NO
/* Parameter 5 */
#define PARAMETER_5_NAME      send_nack
#define PARAMETER_5_DTYPE     uint8_T
#define PARAMETER_5_COMPLEX   COMPLEX_NO
/* Parameter 6 */
#define PARAMETER_6_NAME      remove_stop
#define PARAMETER_6_DTYPE     uint8_T
#define PARAMETER_6_COMPLEX   COMPLEX_NO

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
#define PARAM_DEF4(S) ssGetSFcnParam(S, 4)
#define PARAM_DEF5(S) ssGetSFcnParam(S, 5)
#define PARAM_DEF6(S) ssGetSFcnParam(S, 6)

#define IS_PARAM_UINT8(pVal) (mxIsNumeric(pVal) && !mxIsLogical(pVal) &&\
!mxIsEmpty(pVal) && !mxIsSparse(pVal) && !mxIsComplex(pVal) && mxIsUint8(pVal))

extern void cstm_I2C_WRITE_Outputs_wrapper(const uint8_T *InputMessage,
			int32_T *ErrorStatus,
			const uint8_T *addr, const int_T p_width0,
			const uint8_T *adapter_nr, const int_T p_width1,
			const uint8_T *byte_order, const int_T p_width2,
			const uint8_T *send_register, const int_T p_width3,
			const uint8_T *slave_register, const int_T p_width4,
			const uint8_T *send_nack, const int_T p_width5,
			const uint8_T *remove_stop, const int_T p_width6,
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
        if (!IS_PARAM_UINT8(pVal0)) {
            invalidParam = true;
            paramIndex = 0;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal1 = ssGetSFcnParam(S, 1);
        if (!IS_PARAM_UINT8(pVal1)) {
            invalidParam = true;
            paramIndex = 1;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal2 = ssGetSFcnParam(S, 2);
        if (!IS_PARAM_UINT8(pVal2)) {
            invalidParam = true;
            paramIndex = 2;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal3 = ssGetSFcnParam(S, 3);
        if (!IS_PARAM_UINT8(pVal3)) {
            invalidParam = true;
            paramIndex = 3;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal4 = ssGetSFcnParam(S, 4);
        if (!IS_PARAM_UINT8(pVal4)) {
            invalidParam = true;
            paramIndex = 4;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal5 = ssGetSFcnParam(S, 5);
        if (!IS_PARAM_UINT8(pVal5)) {
            invalidParam = true;
            paramIndex = 5;
            goto EXIT_POINT;
        }
    }

    {
        const mxArray *pVal6 = ssGetSFcnParam(S, 6);
        if (!IS_PARAM_UINT8(pVal6)) {
            invalidParam = true;
            paramIndex = 6;
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
    /* Output Port 0 */
    ssSetOutputPortWidth(S, 0, OUTPUT_0_WIDTH);
    ssSetOutputPortDataType(S, 0, SS_INT32);
    ssSetOutputPortComplexSignal(S, 0, OUTPUT_0_COMPLEX);
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


#define MDL_SET_INPUT_PORT_DIMENSION_INFO
void mdlSetInputPortDimensionInfo(SimStruct        *S, 
                                  int              portIndex, 
                                  const DimsInfo_T *dimsInfo)
{
    DECL_AND_INIT_DIMSINFO(portDimsInfo);
    int_T dims[2] = { OUTPUT_0_WIDTH, 1 };
    bool  frameIn = (ssGetInputPortFrameData(S, 0) == FRAME_YES);

    ssSetInputPortDimensionInfo(S, 0, dimsInfo);

    if (ssGetOutputPortNumDimensions(S, 0) == (-1)) {
        /* the output port has not been set */

        portDimsInfo.width   = 1;
        portDimsInfo.numDims = frameIn ? 2 : 1;
        portDimsInfo.dims    = frameIn ? dims : &portDimsInfo.width;

        ssSetOutputPortDimensionInfo(S, 0, &portDimsInfo);
    }
}


#define MDL_SET_OUTPUT_PORT_DIMENSION_INFO
void mdlSetOutputPortDimensionInfo(SimStruct        *S,         
                                   int_T            portIndex,
                                   const DimsInfo_T *dimsInfo)
{
    DECL_AND_INIT_DIMSINFO(portDimsInfo);
    int_T dims[2] = { OUTPUT_0_WIDTH, 1 };
    bool  frameOut = (ssGetOutputPortFrameData(S, 0) == FRAME_YES);

    ssSetOutputPortDimensionInfo(S, 0, dimsInfo);

    if (ssGetInputPortNumDimensions(S, 0) == (-1)) {
      /* the input port has not been set */

        portDimsInfo.width   = 1;
        portDimsInfo.numDims = frameOut ? 2 : 1;
        portDimsInfo.dims    = frameOut ? dims : &portDimsInfo.width;

        ssSetInputPortDimensionInfo(S, 0, &portDimsInfo);
    }
}


#define MDL_SET_DEFAULT_PORT_DIMENSION_INFO
static void mdlSetDefaultPortDimensionInfo(SimStruct *S)
{
    DECL_AND_INIT_DIMSINFO(portDimsInfo);
    int_T dims[2] = { 1, 1 };
    bool  frame = (ssGetInputPortFrameData(S, 0) == FRAME_YES) ||
                  (ssGetOutputPortFrameData(S, 0) == FRAME_YES);

    /* Neither the input nor the output ports have been set */

    portDimsInfo.width   = 1;
    portDimsInfo.numDims = frame ? 2 : 1;
    portDimsInfo.dims    = frame ? dims : &portDimsInfo.width;

    if (ssGetInputPortNumDimensions(S, 0) == (-1)) {  
        ssSetInputPortDimensionInfo(S, 0, &portDimsInfo);
    }

    if (ssGetOutputPortNumDimensions(S, 0) == (-1)) {
        ssSetInputPortDimensionInfo(S, 0, &portDimsInfo);
    }
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

    const char_T *rtParamNames[] = {"P1","P2","P3","P4","P5","P6","P7"};
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
    const uint8_T *InputMessage = (uint8_T *) ssGetInputPortRealSignal(S, 0);
    int32_T *ErrorStatus = (int32_T *) ssGetOutputPortRealSignal(S, 0);
    const int_T   p_width0  = mxGetNumberOfElements(PARAM_DEF0(S));
    const int_T   p_width1  = mxGetNumberOfElements(PARAM_DEF1(S));
    const int_T   p_width2  = mxGetNumberOfElements(PARAM_DEF2(S));
    const int_T   p_width3  = mxGetNumberOfElements(PARAM_DEF3(S));
    const int_T   p_width4  = mxGetNumberOfElements(PARAM_DEF4(S));
    const int_T   p_width5  = mxGetNumberOfElements(PARAM_DEF5(S));
    const int_T   p_width6  = mxGetNumberOfElements(PARAM_DEF6(S));
    const uint8_T *addr = (const uint8_T *) mxGetData(PARAM_DEF0(S));
    const uint8_T *adapter_nr = (const uint8_T *) mxGetData(PARAM_DEF1(S));
    const uint8_T *byte_order = (const uint8_T *) mxGetData(PARAM_DEF2(S));
    const uint8_T *send_register = (const uint8_T *) mxGetData(PARAM_DEF3(S));
    const uint8_T *slave_register = (const uint8_T *) mxGetData(PARAM_DEF4(S));
    const uint8_T *send_nack = (const uint8_T *) mxGetData(PARAM_DEF5(S));
    const uint8_T *remove_stop = (const uint8_T *) mxGetData(PARAM_DEF6(S));
        const int_T u_width = ssGetInputPortWidth(S, 0);

    cstm_I2C_WRITE_Outputs_wrapper(InputMessage, ErrorStatus, addr, p_width0, adapter_nr, p_width1, byte_order, p_width2, send_register, p_width3, slave_register, p_width4, send_nack, p_width5, remove_stop, p_width6, u_width);

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


