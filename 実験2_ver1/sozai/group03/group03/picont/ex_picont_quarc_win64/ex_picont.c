/*
 * ex_picont.c
 *
 * Code generation for model "ex_picont".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Oct 11 11:33:18 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ex_picont.h"
#include "ex_picont_private.h"
#include "ex_picont_dt.h"

/* Block signals (auto storage) */
B_ex_picont_T ex_picont_B;

/* Continuous states */
X_ex_picont_T ex_picont_X;

/* Block states (auto storage) */
DW_ex_picont_T ex_picont_DW;

/* Real-time model */
RT_MODEL_ex_picont_T ex_picont_M_;
RT_MODEL_ex_picont_T *const ex_picont_M = &ex_picont_M_;

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si)
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si, MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  ex_picont_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++)
  {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si, MAJOR_TIME_STEP);
}

/* Model step function */
void ex_picont_step(void)
{
  /* local block i/o variables */
  real_T rtb_HILReadAnalog;
  real_T currentTime;
  if (rtmIsMajorTimeStep(ex_picont_M))
  {
    /* set solver stop time */
    if (!(ex_picont_M->Timing.clockTick0 + 1))
    {
      rtsiSetSolverStopTime(&ex_picont_M->solverInfo,
                            ((ex_picont_M->Timing.clockTickH0 + 1) *
                             ex_picont_M->Timing.stepSize0 * 4294967296.0));
    }
    else
    {
      rtsiSetSolverStopTime(&ex_picont_M->solverInfo,
                            ((ex_picont_M->Timing.clockTick0 + 1) *
                                 ex_picont_M->Timing.stepSize0 +
                             ex_picont_M->Timing.clockTickH0 *
                                 ex_picont_M->Timing.stepSize0 * 4294967296.0));
    }
  } /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ex_picont_M))
  {
    ex_picont_M->Timing.t[0] = rtsiGetT(&ex_picont_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(ex_picont_M))
  {
  }

  /* Clock: '<Root>/Clock' */
  ex_picont_B.Clock = ex_picont_M->Timing.t[0];
  if (rtmIsMajorTimeStep(ex_picont_M))
  {
    /* S-Function (hil_read_analog_block): '<S1>/HIL Read Analog' */

    /* S-Function Block: ex_picont/Subsystem/HIL Read Analog (hil_read_analog_block) */
    {
      t_error result = hil_read_analog(ex_picont_DW.HILInitialize_Card,
                                       &ex_picont_P.HILReadAnalog_Channels, 1,
                                       &ex_picont_DW.HILReadAnalog_Buffer);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
      }

      rtb_HILReadAnalog = ex_picont_DW.HILReadAnalog_Buffer;
    }

    /* Gain: '<S1>/Gain1' */
    ex_picont_B.Gain1 = ex_picont_P.Gain1_Gain * rtb_HILReadAnalog;
  }

  /* Step: '<Root>/Step' */
  currentTime = ex_picont_M->Timing.t[0];
  if (currentTime < ex_picont_P.Step_Time)
  {
    currentTime = ex_picont_P.Step_Y0;
  }
  else
  {
    currentTime = ex_picont_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Sum: '<S2>/Sum1' */
  ex_picont_B.Sum1 = currentTime - ex_picont_B.Gain1;

  /* Sum: '<S2>/Sum2' incorporates:
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Integrator: '<S2>/Integrator'
   */
  ex_picont_B.Sum2 = ex_picont_P.Gain1_Gain_p * ex_picont_X.Integrator_CSTATE +
                     ex_picont_P.Gain_Gain * ex_picont_B.Sum1;
  if (rtmIsMajorTimeStep(ex_picont_M))
  {
  }

  /* Gain: '<S1>/Gain' */
  currentTime = ex_picont_P.Gain_Gain_j * ex_picont_B.Sum2;

  /* Saturate: '<S1>/Saturation' */
  if (currentTime >= ex_picont_P.Saturation_UpperSat)
  {
    ex_picont_B.Saturation = ex_picont_P.Saturation_UpperSat;
  }
  else if (currentTime <= ex_picont_P.Saturation_LowerSat)
  {
    ex_picont_B.Saturation = ex_picont_P.Saturation_LowerSat;
  }
  else
  {
    ex_picont_B.Saturation = currentTime;
  }

  /* End of Saturate: '<S1>/Saturation' */
  if (rtmIsMajorTimeStep(ex_picont_M))
  {
    /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

    /* S-Function Block: ex_picont/Subsystem/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      result = hil_write_analog(ex_picont_DW.HILInitialize_Card,
                                &ex_picont_P.HILWriteAnalog_Channels, 1, &ex_picont_B.Saturation);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
      }
    }
  }

  if (rtmIsMajorTimeStep(ex_picont_M))
  {
    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    { /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, ex_picont_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(ex_picont_M))
    { /* Sample time: [0.001s, 0.0s] */
      rtExtModeUpload(1, (((ex_picont_M->Timing.clockTick1 +
                            ex_picont_M->Timing.clockTickH1 * 4294967296.0)) *
                          0.001));
    }
  } /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ex_picont_M))
  {
    /* signal main to stop simulation */
    { /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(ex_picont_M) != -1) &&
          !((rtmGetTFinal(ex_picont_M) - (((ex_picont_M->Timing.clockTick1 +
                                            ex_picont_M->Timing.clockTickH1 * 4294967296.0)) *
                                          0.001)) >
            (((ex_picont_M->Timing.clockTick1 + ex_picont_M->Timing.clockTickH1 *
                                                    4294967296.0)) *
             0.001) *
                (DBL_EPSILON)))
      {
        rtmSetErrorStatus(ex_picont_M, "Simulation finished");
      }

      if (rtmGetStopRequested(ex_picont_M))
      {
        rtmSetErrorStatus(ex_picont_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&ex_picont_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ex_picont_M->Timing.clockTick0))
    {
      ++ex_picont_M->Timing.clockTickH0;
    }

    ex_picont_M->Timing.t[0] = rtsiGetSolverStopTime(&ex_picont_M->solverInfo);

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
      ex_picont_M->Timing.clockTick1++;
      if (!ex_picont_M->Timing.clockTick1)
      {
        ex_picont_M->Timing.clockTickH1++;
      }
    }
  } /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ex_picont_derivatives(void)
{
  /* Derivatives for Integrator: '<S2>/Integrator' */
  ((XDot_ex_picont_T *)ex_picont_M->ModelData.derivs)->Integrator_CSTATE =
      ex_picont_B.Sum1;
}

/* Model initialize function */
void ex_picont_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void)memset((void *)ex_picont_M, 0,
               sizeof(RT_MODEL_ex_picont_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ex_picont_M->solverInfo,
                          &ex_picont_M->Timing.simTimeStep);
    rtsiSetTPtr(&ex_picont_M->solverInfo, &rtmGetTPtr(ex_picont_M));
    rtsiSetStepSizePtr(&ex_picont_M->solverInfo, &ex_picont_M->Timing.stepSize0);
    rtsiSetdXPtr(&ex_picont_M->solverInfo, &ex_picont_M->ModelData.derivs);
    rtsiSetContStatesPtr(&ex_picont_M->solverInfo,
                         &ex_picont_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&ex_picont_M->solverInfo,
                            &ex_picont_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&ex_picont_M->solverInfo, (&rtmGetErrorStatus(ex_picont_M)));
    rtsiSetRTModelPtr(&ex_picont_M->solverInfo, ex_picont_M);
  }

  rtsiSetSimTimeStep(&ex_picont_M->solverInfo, MAJOR_TIME_STEP);
  ex_picont_M->ModelData.intgData.f[0] = ex_picont_M->ModelData.odeF[0];
  ex_picont_M->ModelData.contStates = ((real_T *)&ex_picont_X);
  rtsiSetSolverData(&ex_picont_M->solverInfo, (void *)&ex_picont_M->ModelData.intgData);
  rtsiSetSolverName(&ex_picont_M->solverInfo, "ode1");
  rtmSetTPtr(ex_picont_M, &ex_picont_M->Timing.tArray[0]);
  rtmSetTFinal(ex_picont_M, -1);
  ex_picont_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  ex_picont_M->Sizes.checksums[0] = (443387493U);
  ex_picont_M->Sizes.checksums[1] = (1520896688U);
  ex_picont_M->Sizes.checksums[2] = (4282165356U);
  ex_picont_M->Sizes.checksums[3] = (3996140474U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ex_picont_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ex_picont_M->extModeInfo,
                               &ex_picont_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ex_picont_M->extModeInfo, ex_picont_M->Sizes.checksums);
    rteiSetTPtr(ex_picont_M->extModeInfo, rtmGetTPtr(ex_picont_M));
  }

  /* block I/O */
  (void)memset(((void *)&ex_picont_B), 0,
               sizeof(B_ex_picont_T));

  /* states (continuous) */
  {
    (void)memset((void *)&ex_picont_X, 0,
                 sizeof(X_ex_picont_T));
  }

  /* states (dwork) */
  (void)memset((void *)&ex_picont_DW, 0,
               sizeof(DW_ex_picont_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void)memset((char_T *)&dtInfo, 0,
                 sizeof(dtInfo));
    ex_picont_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: ex_picont/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &ex_picont_DW.HILInitialize_Card);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ex_picont_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(ex_picont_DW.HILInitialize_Card,
                                           "update_rate=normal;decimation=1", 32);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ex_picont_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(ex_picont_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ex_picont_M, _rt_error_message);
      return;
    }

    if ((ex_picont_P.HILInitialize_AIPStart && !is_switching) ||
        (ex_picont_P.HILInitialize_AIPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AIMinimums = &ex_picont_DW.HILInitialize_AIMinimums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AIMinimums[i1] = ex_picont_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &ex_picont_DW.HILInitialize_AIMaximums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AIMaximums[i1] = ex_picont_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(ex_picont_DW.HILInitialize_Card,
                                           ex_picont_P.HILInitialize_AIChannels, 8U,
                                           &ex_picont_DW.HILInitialize_AIMinimums[0],
                                           &ex_picont_DW.HILInitialize_AIMaximums[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if ((ex_picont_P.HILInitialize_AOPStart && !is_switching) ||
        (ex_picont_P.HILInitialize_AOPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOMinimums = &ex_picont_DW.HILInitialize_AOMinimums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOMinimums[i1] = ex_picont_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &ex_picont_DW.HILInitialize_AOMaximums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOMaximums[i1] = ex_picont_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(ex_picont_DW.HILInitialize_Card,
                                            ex_picont_P.HILInitialize_AOChannels, 8U,
                                            &ex_picont_DW.HILInitialize_AOMinimums[0],
                                            &ex_picont_DW.HILInitialize_AOMaximums[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if ((ex_picont_P.HILInitialize_AOStart && !is_switching) ||
        (ex_picont_P.HILInitialize_AOEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ex_picont_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ex_picont_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(ex_picont_DW.HILInitialize_Card,
                                ex_picont_P.HILInitialize_AOChannels, 8U,
                                &ex_picont_DW.HILInitialize_AOVoltages[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if (ex_picont_P.HILInitialize_AOReset)
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ex_picont_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ex_picont_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state(ex_picont_DW.HILInitialize_Card, ex_picont_P.HILInitialize_AOChannels,
                                                        8U, &ex_picont_DW.HILInitialize_AOVoltages[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if ((ex_picont_P.HILInitialize_EIPStart && !is_switching) ||
        (ex_picont_P.HILInitialize_EIPEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
            &ex_picont_DW.HILInitialize_QuadratureModes[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_QuadratureModes[i1] = ex_picont_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(ex_picont_DW.HILInitialize_Card,
                                               ex_picont_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)&ex_picont_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if ((ex_picont_P.HILInitialize_EIStart && !is_switching) ||
        (ex_picont_P.HILInitialize_EIEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
            &ex_picont_DW.HILInitialize_InitialEICounts[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_InitialEICounts[i1] = ex_picont_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(ex_picont_DW.HILInitialize_Card,
                                      ex_picont_P.HILInitialize_EIChannels, 8U,
                                      &ex_picont_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if ((ex_picont_P.HILInitialize_POPStart && !is_switching) ||
        (ex_picont_P.HILInitialize_POPEnter && is_switching))
    {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &ex_picont_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POModeValues[i1] = ex_picont_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(ex_picont_DW.HILInitialize_Card,
                                ex_picont_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)&ex_picont_DW.HILInitialize_POModeValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
            ex_picont_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &ex_picont_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] == PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE)
          {
            ex_picont_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
                (p_HILInitialize_POChannels[i1]);
            ex_picont_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
                ex_picont_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          }
          else
          {
            ex_picont_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
                (p_HILInitialize_POChannels[i1]);
            ex_picont_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
                ex_picont_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0)
      {
        result = hil_set_pwm_frequency(ex_picont_DW.HILInitialize_Card,
                                       &ex_picont_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
                                       &ex_picont_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ex_picont_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0)
      {
        result = hil_set_pwm_duty_cycle(ex_picont_DW.HILInitialize_Card,
                                        &ex_picont_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
                                        num_frequency_modes,
                                        &ex_picont_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ex_picont_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &ex_picont_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POModeValues[i1] = ex_picont_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &ex_picont_DW.HILInitialize_POAlignValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POAlignValues[i1] = ex_picont_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &ex_picont_DW.HILInitialize_POPolarityVals
                                          [0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POPolarityVals[i1] = ex_picont_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(ex_picont_DW.HILInitialize_Card,
                                         ex_picont_P.HILInitialize_POChannels, 8U,
                                         (t_pwm_configuration *)&ex_picont_DW.HILInitialize_POModeValues[0],
                                         (t_pwm_alignment *)&ex_picont_DW.HILInitialize_POAlignValues[0],
                                         (t_pwm_polarity *)&ex_picont_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &ex_picont_DW.HILInitialize_POSortedFreqs[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POSortedFreqs[i1] = ex_picont_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &ex_picont_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ex_picont_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(ex_picont_DW.HILInitialize_Card,
                                    ex_picont_P.HILInitialize_POChannels, 8U,
                                    &ex_picont_DW.HILInitialize_POSortedFreqs[0],
                                    &ex_picont_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if ((ex_picont_P.HILInitialize_POStart && !is_switching) ||
        (ex_picont_P.HILInitialize_POEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_POValues = &ex_picont_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ex_picont_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(ex_picont_DW.HILInitialize_Card,
                             ex_picont_P.HILInitialize_POChannels, 8U,
                             &ex_picont_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }

    if (ex_picont_P.HILInitialize_POReset)
    {
      {
        int_T i1;
        real_T *dw_POValues = &ex_picont_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ex_picont_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state(ex_picont_DW.HILInitialize_Card, ex_picont_P.HILInitialize_POChannels,
                                                     8U, &ex_picont_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        return;
      }
    }
  }

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  ex_picont_X.Integrator_CSTATE = ex_picont_P.Integrator_IC;
}

/* Model terminate function */
void ex_picont_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: ex_picont/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(ex_picont_DW.HILInitialize_Card);
    hil_monitor_stop_all(ex_picont_DW.HILInitialize_Card);
    is_switching = false;
    if ((ex_picont_P.HILInitialize_AOTerminate && !is_switching) ||
        (ex_picont_P.HILInitialize_AOExit && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ex_picont_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ex_picont_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((ex_picont_P.HILInitialize_POTerminate && !is_switching) ||
        (ex_picont_P.HILInitialize_POExit && is_switching))
    {
      {
        int_T i1;
        real_T *dw_POValues = &ex_picont_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ex_picont_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0 || num_final_analog_outputs > 0 || num_final_pwm_outputs > 0)
    {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(ex_picont_DW.HILInitialize_Card, ex_picont_P.HILInitialize_AOChannels,
                         num_final_analog_outputs, ex_picont_P.HILInitialize_POChannels,
                         num_final_pwm_outputs, NULL, 0, NULL, 0, &ex_picont_DW.HILInitialize_AOVoltages[0], &ex_picont_DW.HILInitialize_POValues[0], (t_boolean *)NULL, NULL);
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED)
      {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0)
        {
          local_result = hil_write_analog(ex_picont_DW.HILInitialize_Card,
                                          ex_picont_P.HILInitialize_AOChannels, num_final_analog_outputs,
                                          &ex_picont_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0)
          {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0)
        {
          local_result = hil_write_pwm(ex_picont_DW.HILInitialize_Card,
                                       ex_picont_P.HILInitialize_POChannels, num_final_pwm_outputs,
                                       &ex_picont_DW.HILInitialize_POValues[0]);
          if (local_result < 0)
          {
            result = local_result;
          }
        }

        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ex_picont_M, _rt_error_message);
        }
      }
    }

    hil_task_
    {
      \mathrm { d }
    }
    elete_all(ex_picont_DW.HILInitialize_Card);
    hil_monitor_delete_all(ex_picont_DW.HILInitialize_Card);
    hil_close(ex_picont_DW.HILInitialize_Card);
    ex_picont_DW.HILInitialize_Card = NULL;
  }
}
