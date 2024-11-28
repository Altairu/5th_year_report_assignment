/*
 * da_conv_count.c
 *
 * Code generation for model "da_conv_count".
 *
 * Model version              : 1.19
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Sep 20 11:24:12 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "da_conv_count.h"
#include "da_conv_count_private.h"
#include "da_conv_count_dt.h"

/* Block signals (auto storage) */
B_da_conv_count_T da_conv_count_B;

/* Continuous states */
X_da_conv_count_T da_conv_count_X;

/* Block states (auto storage) */
DW_da_conv_count_T da_conv_count_DW;

/* Real-time model */
RT_MODEL_da_conv_count_T da_conv_count_M_;
RT_MODEL_da_conv_count_T *const da_conv_count_M = &da_conv_count_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  da_conv_count_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void da_conv_count_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder;
  if (rtmIsMajorTimeStep(da_conv_count_M)) {
    /* set solver stop time */
    if (!(da_conv_count_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&da_conv_count_M->solverInfo,
                            ((da_conv_count_M->Timing.clockTickH0 + 1) *
        da_conv_count_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&da_conv_count_M->solverInfo,
                            ((da_conv_count_M->Timing.clockTick0 + 1) *
        da_conv_count_M->Timing.stepSize0 + da_conv_count_M->Timing.clockTickH0 *
        da_conv_count_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(da_conv_count_M)) {
    da_conv_count_M->Timing.t[0] = rtsiGetT(&da_conv_count_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(da_conv_count_M)) {
  }

  /* Clock: '<Root>/Clock' */
  da_conv_count_B.Clock = da_conv_count_M->Timing.t[0];
  if (rtmIsMajorTimeStep(da_conv_count_M)) {
    /* Gain: '<Root>/Gain (polarity)' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_HILReadEncoder = da_conv_count_P.Gainpolarity_Gain *
      da_conv_count_P.Constant_Value;

    /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

    /* S-Function Block: da_conv_count/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(da_conv_count_DW.HILInitialize_Card,
        &da_conv_count_P.HILWriteAnalog_Channels, 1, &rtb_HILReadEncoder);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
      }
    }

    /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

    /* S-Function Block: da_conv_count/HIL Read Encoder (hil_read_encoder_block) */
    {
      t_error result = hil_read_encoder(da_conv_count_DW.HILInitialize_Card,
        &da_conv_count_P.HILReadEncoder_Channels, 1,
        &da_conv_count_DW.HILReadEncoder_Buffer);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
      } else {
        rtb_HILReadEncoder = da_conv_count_DW.HILReadEncoder_Buffer;
      }
    }

    /* Gain: '<Root>/Gain (count to meter)' */
    da_conv_count_B.Gaincounttometer = da_conv_count_P.Gaincounttometer_Gain *
      rtb_HILReadEncoder;
  }

  /* Derivative: '<Root>/Derivative' */
  {
    real_T t = da_conv_count_M->Timing.t[0];
    real_T timeStampA = da_conv_count_DW.Derivative_RWORK.TimeStampA;
    real_T timeStampB = da_conv_count_DW.Derivative_RWORK.TimeStampB;
    real_T *lastU = &da_conv_count_DW.Derivative_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      da_conv_count_B.Derivative = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &da_conv_count_DW.Derivative_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &da_conv_count_DW.Derivative_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      da_conv_count_B.Derivative = (da_conv_count_B.Gaincounttometer - *lastU++)
        / deltaT;
    }
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  da_conv_count_B.TransferFcn = da_conv_count_P.TransferFcn_C*
    da_conv_count_X.TransferFcn_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  da_conv_count_B.TransferFcn1 = da_conv_count_P.TransferFcn1_C*
    da_conv_count_X.TransferFcn1_CSTATE;

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  da_conv_count_B.TransferFcn2 = da_conv_count_P.TransferFcn2_C*
    da_conv_count_X.TransferFcn2_CSTATE;
  if (rtmIsMajorTimeStep(da_conv_count_M)) {
  }

  if (rtmIsMajorTimeStep(da_conv_count_M)) {
    /* Update for Derivative: '<Root>/Derivative' */
    {
      real_T timeStampA = da_conv_count_DW.Derivative_RWORK.TimeStampA;
      real_T timeStampB = da_conv_count_DW.Derivative_RWORK.TimeStampB;
      real_T* lastTime = &da_conv_count_DW.Derivative_RWORK.TimeStampA;
      real_T* lastU = &da_conv_count_DW.Derivative_RWORK.LastUAtTimeA;
      if (timeStampA != rtInf) {
        if (timeStampB == rtInf) {
          lastTime = &da_conv_count_DW.Derivative_RWORK.TimeStampB;
          lastU = &da_conv_count_DW.Derivative_RWORK.LastUAtTimeB;
        } else if (timeStampA >= timeStampB) {
          lastTime = &da_conv_count_DW.Derivative_RWORK.TimeStampB;
          lastU = &da_conv_count_DW.Derivative_RWORK.LastUAtTimeB;
        }
      }

      *lastTime = da_conv_count_M->Timing.t[0];
      *lastU++ = da_conv_count_B.Gaincounttometer;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, da_conv_count_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(da_conv_count_M)) {/* Sample time: [0.001s, 0.0s] */
      rtExtModeUpload(1, (((da_conv_count_M->Timing.clockTick1+
                            da_conv_count_M->Timing.clockTickH1* 4294967296.0)) *
                          0.001));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(da_conv_count_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(da_conv_count_M)!=-1) &&
          !((rtmGetTFinal(da_conv_count_M)-(((da_conv_count_M->Timing.clockTick1
               +da_conv_count_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((da_conv_count_M->Timing.clockTick1+
               da_conv_count_M->Timing.clockTickH1* 4294967296.0)) * 0.001) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(da_conv_count_M, "Simulation finished");
      }

      if (rtmGetStopRequested(da_conv_count_M)) {
        rtmSetErrorStatus(da_conv_count_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&da_conv_count_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++da_conv_count_M->Timing.clockTick0)) {
      ++da_conv_count_M->Timing.clockTickH0;
    }

    da_conv_count_M->Timing.t[0] = rtsiGetSolverStopTime
      (&da_conv_count_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      da_conv_count_M->Timing.clockTick1++;
      if (!da_conv_count_M->Timing.clockTick1) {
        da_conv_count_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void da_conv_count_derivatives(void)
{
  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  {
    ((XDot_da_conv_count_T *) da_conv_count_M->ModelData.derivs)
      ->TransferFcn_CSTATE = da_conv_count_B.Derivative;
    ((XDot_da_conv_count_T *) da_conv_count_M->ModelData.derivs)
      ->TransferFcn_CSTATE += (da_conv_count_P.TransferFcn_A)*
      da_conv_count_X.TransferFcn_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  {
    ((XDot_da_conv_count_T *) da_conv_count_M->ModelData.derivs)
      ->TransferFcn1_CSTATE = da_conv_count_B.Derivative;
    ((XDot_da_conv_count_T *) da_conv_count_M->ModelData.derivs)
      ->TransferFcn1_CSTATE += (da_conv_count_P.TransferFcn1_A)*
      da_conv_count_X.TransferFcn1_CSTATE;
  }

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  {
    ((XDot_da_conv_count_T *) da_conv_count_M->ModelData.derivs)
      ->TransferFcn2_CSTATE = da_conv_count_B.Derivative;
    ((XDot_da_conv_count_T *) da_conv_count_M->ModelData.derivs)
      ->TransferFcn2_CSTATE += (da_conv_count_P.TransferFcn2_A)*
      da_conv_count_X.TransferFcn2_CSTATE;
  }
}

/* Model initialize function */
void da_conv_count_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)da_conv_count_M, 0,
                sizeof(RT_MODEL_da_conv_count_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&da_conv_count_M->solverInfo,
                          &da_conv_count_M->Timing.simTimeStep);
    rtsiSetTPtr(&da_conv_count_M->solverInfo, &rtmGetTPtr(da_conv_count_M));
    rtsiSetStepSizePtr(&da_conv_count_M->solverInfo,
                       &da_conv_count_M->Timing.stepSize0);
    rtsiSetdXPtr(&da_conv_count_M->solverInfo,
                 &da_conv_count_M->ModelData.derivs);
    rtsiSetContStatesPtr(&da_conv_count_M->solverInfo,
                         &da_conv_count_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&da_conv_count_M->solverInfo,
      &da_conv_count_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&da_conv_count_M->solverInfo, (&rtmGetErrorStatus
      (da_conv_count_M)));
    rtsiSetRTModelPtr(&da_conv_count_M->solverInfo, da_conv_count_M);
  }

  rtsiSetSimTimeStep(&da_conv_count_M->solverInfo, MAJOR_TIME_STEP);
  da_conv_count_M->ModelData.intgData.f[0] = da_conv_count_M->ModelData.odeF[0];
  da_conv_count_M->ModelData.contStates = ((real_T *) &da_conv_count_X);
  rtsiSetSolverData(&da_conv_count_M->solverInfo, (void *)
                    &da_conv_count_M->ModelData.intgData);
  rtsiSetSolverName(&da_conv_count_M->solverInfo,"ode1");
  rtmSetTPtr(da_conv_count_M, &da_conv_count_M->Timing.tArray[0]);
  rtmSetTFinal(da_conv_count_M, 1.0);
  da_conv_count_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  da_conv_count_M->Sizes.checksums[0] = (4231678583U);
  da_conv_count_M->Sizes.checksums[1] = (2414743524U);
  da_conv_count_M->Sizes.checksums[2] = (2405664882U);
  da_conv_count_M->Sizes.checksums[3] = (1568591061U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    da_conv_count_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(da_conv_count_M->extModeInfo,
      &da_conv_count_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(da_conv_count_M->extModeInfo,
                        da_conv_count_M->Sizes.checksums);
    rteiSetTPtr(da_conv_count_M->extModeInfo, rtmGetTPtr(da_conv_count_M));
  }

  /* block I/O */
  (void) memset(((void *) &da_conv_count_B), 0,
                sizeof(B_da_conv_count_T));

  /* states (continuous) */
  {
    (void) memset((void *)&da_conv_count_X, 0,
                  sizeof(X_da_conv_count_T));
  }

  /* states (dwork) */
  (void) memset((void *)&da_conv_count_DW, 0,
                sizeof(DW_da_conv_count_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    da_conv_count_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: da_conv_count/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &da_conv_count_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(da_conv_count_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(da_conv_count_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
      return;
    }

    if ((da_conv_count_P.HILInitialize_AIPStart && !is_switching) ||
        (da_conv_count_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &da_conv_count_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = da_conv_count_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &da_conv_count_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = da_conv_count_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_AIChannels, 8U,
        &da_conv_count_DW.HILInitialize_AIMinimums[0],
        &da_conv_count_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if ((da_conv_count_P.HILInitialize_AOPStart && !is_switching) ||
        (da_conv_count_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &da_conv_count_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = da_conv_count_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &da_conv_count_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = da_conv_count_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_AOChannels, 8U,
        &da_conv_count_DW.HILInitialize_AOMinimums[0],
        &da_conv_count_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if ((da_conv_count_P.HILInitialize_AOStart && !is_switching) ||
        (da_conv_count_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &da_conv_count_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = da_conv_count_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_AOChannels, 8U,
        &da_conv_count_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if (da_conv_count_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &da_conv_count_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = da_conv_count_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (da_conv_count_DW.HILInitialize_Card,
         da_conv_count_P.HILInitialize_AOChannels, 8U,
         &da_conv_count_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if ((da_conv_count_P.HILInitialize_EIPStart && !is_switching) ||
        (da_conv_count_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &da_conv_count_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = da_conv_count_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (da_conv_count_DW.HILInitialize_Card,
         da_conv_count_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &da_conv_count_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if ((da_conv_count_P.HILInitialize_EIStart && !is_switching) ||
        (da_conv_count_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &da_conv_count_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = da_conv_count_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_EIChannels, 8U,
        &da_conv_count_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if ((da_conv_count_P.HILInitialize_POPStart && !is_switching) ||
        (da_conv_count_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &da_conv_count_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = da_conv_count_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &da_conv_count_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          da_conv_count_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &da_conv_count_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            da_conv_count_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            da_conv_count_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              da_conv_count_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            da_conv_count_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            da_conv_count_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = da_conv_count_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(da_conv_count_DW.HILInitialize_Card,
          &da_conv_count_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &da_conv_count_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(da_conv_count_DW.HILInitialize_Card,
          &da_conv_count_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &da_conv_count_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &da_conv_count_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = da_conv_count_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &da_conv_count_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = da_conv_count_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &da_conv_count_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = da_conv_count_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &da_conv_count_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &da_conv_count_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &da_conv_count_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &da_conv_count_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = da_conv_count_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &da_conv_count_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = da_conv_count_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_POChannels, 8U,
        &da_conv_count_DW.HILInitialize_POSortedFreqs[0],
        &da_conv_count_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if ((da_conv_count_P.HILInitialize_POStart && !is_switching) ||
        (da_conv_count_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &da_conv_count_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = da_conv_count_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(da_conv_count_DW.HILInitialize_Card,
        da_conv_count_P.HILInitialize_POChannels, 8U,
        &da_conv_count_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }

    if (da_conv_count_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &da_conv_count_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = da_conv_count_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (da_conv_count_DW.HILInitialize_Card,
         da_conv_count_P.HILInitialize_POChannels, 8U,
         &da_conv_count_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  da_conv_count_DW.Derivative_RWORK.TimeStampA = rtInf;
  da_conv_count_DW.Derivative_RWORK.TimeStampB = rtInf;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  da_conv_count_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  da_conv_count_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  da_conv_count_X.TransferFcn2_CSTATE = 0.0;
}

/* Model terminate function */
void da_conv_count_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: da_conv_count/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(da_conv_count_DW.HILInitialize_Card);
    hil_monitor_stop_all(da_conv_count_DW.HILInitialize_Card);
    is_switching = false;
    if ((da_conv_count_P.HILInitialize_AOTerminate && !is_switching) ||
        (da_conv_count_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &da_conv_count_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = da_conv_count_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((da_conv_count_P.HILInitialize_POTerminate && !is_switching) ||
        (da_conv_count_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &da_conv_count_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = da_conv_count_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(da_conv_count_DW.HILInitialize_Card
                         , da_conv_count_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , da_conv_count_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &da_conv_count_DW.HILInitialize_AOVoltages[0]
                         , &da_conv_count_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(da_conv_count_DW.HILInitialize_Card,
            da_conv_count_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &da_conv_count_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(da_conv_count_DW.HILInitialize_Card,
            da_conv_count_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &da_conv_count_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(da_conv_count_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(da_conv_count_DW.HILInitialize_Card);
    hil_monitor_delete_all(da_conv_count_DW.HILInitialize_Card);
    hil_close(da_conv_count_DW.HILInitialize_Card);
    da_conv_count_DW.HILInitialize_Card = NULL;
  }
}
