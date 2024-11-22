/*
 * ad_da_conv.c
 *
 * Code generation for model "ad_da_conv".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Oct 11 10:38:25 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ad_da_conv.h"
#include "ad_da_conv_private.h"
#include "ad_da_conv_dt.h"

/* Block signals (auto storage) */
B_ad_da_conv_T ad_da_conv_B;

/* Block states (auto storage) */
DW_ad_da_conv_T ad_da_conv_DW;

/* Real-time model */
RT_MODEL_ad_da_conv_T ad_da_conv_M_;
RT_MODEL_ad_da_conv_T *const ad_da_conv_M = &ad_da_conv_M_;

/* Model step function */
void ad_da_conv_step(void)
{
  /* local block i/o variables */
  real_T rtb_Saturation;

  /* Clock: '<Root>/Clock' */
  ad_da_conv_B.Clock = ad_da_conv_M->Timing.t[0];

  /* S-Function (hil_read_analog_block): '<S1>/HIL Read Analog' */

  /* S-Function Block: ad_da_conv/Subsystem/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(ad_da_conv_DW.HILInitialize_Card,
                                     &ad_da_conv_P.HILReadAnalog_Channels, 1,
                                     &ad_da_conv_DW.HILReadAnalog_Buffer);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
    }

    rtb_Saturation = ad_da_conv_DW.HILReadAnalog_Buffer;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Gain: '<S1>/Gain1'
   */
  ad_da_conv_B.Gain = ad_da_conv_P.Gain1_Gain * rtb_Saturation *
                      ad_da_conv_P.Gain_Gain;

  /* Gain: '<S1>/Gain' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Saturation = ad_da_conv_P.Gain_Gain_j * ad_da_conv_P.Constant_Value;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Saturation >= ad_da_conv_P.Saturation_UpperSat)
  {
    rtb_Saturation = ad_da_conv_P.Saturation_UpperSat;
  }
  else
  {
    if (rtb_Saturation <= ad_da_conv_P.Saturation_LowerSat)
    {
      rtb_Saturation = ad_da_conv_P.Saturation_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* S-Function (hil_write_analog_block): '<S1>/HIL Write Analog' */

  /* S-Function Block: ad_da_conv/Subsystem/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(ad_da_conv_DW.HILInitialize_Card,
                              &ad_da_conv_P.HILWriteAnalog_Channels, 1, &rtb_Saturation);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
    }
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  { /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, ad_da_conv_M->Timing.t[0]);
  }

  { /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(1, (((ad_da_conv_M->Timing.clockTick1 +
                          ad_da_conv_M->Timing.clockTickH1 * 4294967296.0)) *
                        0.001));
  }

  /* signal main to stop simulation */
  { /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(ad_da_conv_M) != -1) &&
        !((rtmGetTFinal(ad_da_conv_M) - ad_da_conv_M->Timing.t[0]) >
          ad_da_conv_M->Timing.t[0] * (DBL_EPSILON)))
    {
      rtmSetErrorStatus(ad_da_conv_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ad_da_conv_M))
    {
      rtmSetErrorStatus(ad_da_conv_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ad_da_conv_M->Timing.clockTick0))
  {
    ++ad_da_conv_M->Timing.clockTickH0;
  }

  ad_da_conv_M->Timing.t[0] = ad_da_conv_M->Timing.clockTick0 *
                                  ad_da_conv_M->Timing.stepSize0 +
                              ad_da_conv_M->Timing.clockTickH0 *
                                  ad_da_conv_M->Timing.stepSize0 * 4294967296.0;

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
    ad_da_conv_M->Timing.clockTick1++;
    if (!ad_da_conv_M->Timing.clockTick1)
    {
      ad_da_conv_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void ad_da_conv_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void)memset((void *)ad_da_conv_M, 0,
               sizeof(RT_MODEL_ad_da_conv_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ad_da_conv_M->solverInfo,
                          &ad_da_conv_M->Timing.simTimeStep);
    rtsiSetTPtr(&ad_da_conv_M->solverInfo, &rtmGetTPtr(ad_da_conv_M));
    rtsiSetStepSizePtr(&ad_da_conv_M->solverInfo,
                       &ad_da_conv_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&ad_da_conv_M->solverInfo, (&rtmGetErrorStatus(ad_da_conv_M)));
    rtsiSetRTModelPtr(&ad_da_conv_M->solverInfo, ad_da_conv_M);
  }

  rtsiSetSimTimeStep(&ad_da_conv_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&ad_da_conv_M->solverInfo, "FixedStepDiscrete");
  rtmSetTPtr(ad_da_conv_M, &ad_da_conv_M->Timing.tArray[0]);
  rtmSetTFinal(ad_da_conv_M, 8.0);
  ad_da_conv_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  ad_da_conv_M->Sizes.checksums[0] = (449219553U);
  ad_da_conv_M->Sizes.checksums[1] = (2069692735U);
  ad_da_conv_M->Sizes.checksums[2] = (1033786977U);
  ad_da_conv_M->Sizes.checksums[3] = (295933886U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ad_da_conv_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ad_da_conv_M->extModeInfo,
                               &ad_da_conv_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ad_da_conv_M->extModeInfo, ad_da_conv_M->Sizes.checksums);
    rteiSetTPtr(ad_da_conv_M->extModeInfo, rtmGetTPtr(ad_da_conv_M));
  }

  /* block I/O */
  (void)memset(((void *)&ad_da_conv_B), 0,
               sizeof(B_ad_da_conv_T));

  /* states (dwork) */
  (void)memset((void *)&ad_da_conv_DW, 0,
               sizeof(DW_ad_da_conv_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void)memset((char_T *)&dtInfo, 0,
                 sizeof(dtInfo));
    ad_da_conv_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: ad_da_conv/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &ad_da_conv_DW.HILInitialize_Card);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(ad_da_conv_DW.HILInitialize_Card,
                                           "update_rate=normal;decimation=1", 32);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(ad_da_conv_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
      return;
    }

    if ((ad_da_conv_P.HILInitialize_AIPStart && !is_switching) ||
        (ad_da_conv_P.HILInitialize_AIPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AIMinimums = &ad_da_conv_DW.HILInitialize_AIMinimums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AIMinimums[i1] = ad_da_conv_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &ad_da_conv_DW.HILInitialize_AIMaximums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AIMaximums[i1] = ad_da_conv_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(ad_da_conv_DW.HILInitialize_Card,
                                           ad_da_conv_P.HILInitialize_AIChannels, 8U,
                                           &ad_da_conv_DW.HILInitialize_AIMinimums[0],
                                           &ad_da_conv_DW.HILInitialize_AIMaximums[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_da_conv_P.HILInitialize_AOPStart && !is_switching) ||
        (ad_da_conv_P.HILInitialize_AOPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOMinimums = &ad_da_conv_DW.HILInitialize_AOMinimums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOMinimums[i1] = ad_da_conv_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &ad_da_conv_DW.HILInitialize_AOMaximums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOMaximums[i1] = ad_da_conv_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(ad_da_conv_DW.HILInitialize_Card,
                                            ad_da_conv_P.HILInitialize_AOChannels, 8U,
                                            &ad_da_conv_DW.HILInitialize_AOMinimums[0],
                                            &ad_da_conv_DW.HILInitialize_AOMaximums[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_da_conv_P.HILInitialize_AOStart && !is_switching) ||
        (ad_da_conv_P.HILInitialize_AOEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ad_da_conv_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ad_da_conv_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(ad_da_conv_DW.HILInitialize_Card,
                                ad_da_conv_P.HILInitialize_AOChannels, 8U,
                                &ad_da_conv_DW.HILInitialize_AOVoltages[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if (ad_da_conv_P.HILInitialize_AOReset)
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ad_da_conv_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ad_da_conv_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state(ad_da_conv_DW.HILInitialize_Card, ad_da_conv_P.HILInitialize_AOChannels,
                                                        8U, &ad_da_conv_DW.HILInitialize_AOVoltages[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_da_conv_P.HILInitialize_EIPStart && !is_switching) ||
        (ad_da_conv_P.HILInitialize_EIPEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
            &ad_da_conv_DW.HILInitialize_QuadratureModes[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_QuadratureModes[i1] = ad_da_conv_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(ad_da_conv_DW.HILInitialize_Card,
                                               ad_da_conv_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)&ad_da_conv_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_da_conv_P.HILInitialize_EIStart && !is_switching) ||
        (ad_da_conv_P.HILInitialize_EIEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
            &ad_da_conv_DW.HILInitialize_InitialEICounts[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_InitialEICounts[i1] = ad_da_conv_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(ad_da_conv_DW.HILInitialize_Card,
                                      ad_da_conv_P.HILInitialize_EIChannels, 8U,
                                      &ad_da_conv_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_da_conv_P.HILInitialize_POPStart && !is_switching) ||
        (ad_da_conv_P.HILInitialize_POPEnter && is_switching))
    {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &ad_da_conv_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POModeValues[i1] = ad_da_conv_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(ad_da_conv_DW.HILInitialize_Card,
                                ad_da_conv_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)&ad_da_conv_DW.HILInitialize_POModeValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
            ad_da_conv_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &ad_da_conv_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] == PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE)
          {
            ad_da_conv_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
                (p_HILInitialize_POChannels[i1]);
            ad_da_conv_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
                ad_da_conv_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          }
          else
          {
            ad_da_conv_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
                (p_HILInitialize_POChannels[i1]);
            ad_da_conv_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
                ad_da_conv_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0)
      {
        result = hil_set_pwm_frequency(ad_da_conv_DW.HILInitialize_Card,
                                       &ad_da_conv_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
                                       &ad_da_conv_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0)
      {
        result = hil_set_pwm_duty_cycle(ad_da_conv_DW.HILInitialize_Card,
                                        &ad_da_conv_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
                                        num_frequency_modes,
                                        &ad_da_conv_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &ad_da_conv_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POModeValues[i1] = ad_da_conv_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &ad_da_conv_DW.HILInitialize_POAlignValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POAlignValues[i1] = ad_da_conv_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
            &ad_da_conv_DW.HILInitialize_POPolarityVals[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POPolarityVals[i1] = ad_da_conv_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(ad_da_conv_DW.HILInitialize_Card,
                                         ad_da_conv_P.HILInitialize_POChannels, 8U,
                                         (t_pwm_configuration *)&ad_da_conv_DW.HILInitialize_POModeValues[0],
                                         (t_pwm_alignment *)&ad_da_conv_DW.HILInitialize_POAlignValues[0],
                                         (t_pwm_polarity *)&ad_da_conv_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &ad_da_conv_DW.HILInitialize_POSortedFreqs[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POSortedFreqs[i1] = ad_da_conv_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &ad_da_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_da_conv_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(ad_da_conv_DW.HILInitialize_Card,
                                    ad_da_conv_P.HILInitialize_POChannels, 8U,
                                    &ad_da_conv_DW.HILInitialize_POSortedFreqs[0],
                                    &ad_da_conv_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_da_conv_P.HILInitialize_POStart && !is_switching) ||
        (ad_da_conv_P.HILInitialize_POEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_POValues = &ad_da_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_da_conv_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(ad_da_conv_DW.HILInitialize_Card,
                             ad_da_conv_P.HILInitialize_POChannels, 8U,
                             &ad_da_conv_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }

    if (ad_da_conv_P.HILInitialize_POReset)
    {
      {
        int_T i1;
        real_T *dw_POValues = &ad_da_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_da_conv_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state(ad_da_conv_DW.HILInitialize_Card, ad_da_conv_P.HILInitialize_POChannels,
                                                     8U, &ad_da_conv_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void ad_da_conv_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: ad_da_conv/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(ad_da_conv_DW.HILInitialize_Card);
    hil_monitor_stop_all(ad_da_conv_DW.HILInitialize_Card);
    is_switching = false;
    if ((ad_da_conv_P.HILInitialize_AOTerminate && !is_switching) ||
        (ad_da_conv_P.HILInitialize_AOExit && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ad_da_conv_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ad_da_conv_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((ad_da_conv_P.HILInitialize_POTerminate && !is_switching) ||
        (ad_da_conv_P.HILInitialize_POExit && is_switching))
    {
      {
        int_T i1;
        real_T *dw_POValues = &ad_da_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_da_conv_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0 || num_final_analog_outputs > 0 || num_final_pwm_outputs > 0)
    {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(ad_da_conv_DW.HILInitialize_Card, ad_da_conv_P.HILInitialize_AOChannels,
                         num_final_analog_outputs, ad_da_conv_P.HILInitialize_POChannels,
                         num_final_pwm_outputs, NULL, 0, NULL, 0, &ad_da_conv_DW.HILInitialize_AOVoltages[0], &ad_da_conv_DW.HILInitialize_POValues[0], (t_boolean *)NULL, NULL);
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED)
      {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0)
        {
          local_result = hil_write_analog(ad_da_conv_DW.HILInitialize_Card,
                                          ad_da_conv_P.HILInitialize_AOChannels, num_final_analog_outputs,
                                          &ad_da_conv_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0)
          {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0)
        {
          local_result = hil_write_pwm(ad_da_conv_DW.HILInitialize_Card,
                                       ad_da_conv_P.HILInitialize_POChannels, num_final_pwm_outputs,
                                       &ad_da_conv_DW.HILInitialize_POValues[0]);
          if (local_result < 0)
          {
            result = local_result;
          }
        }

        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ad_da_conv_M, _rt_error_message);
        }
      }
    }

    hil_task_
    {
      \mathrm { d }
    }
    elete_all(ad_da_conv_DW.HILInitialize_Card);
    hil_monitor_delete_all(ad_da_conv_DW.HILInitialize_Card);
    hil_close(ad_da_conv_DW.HILInitialize_Card);
    ad_da_conv_DW.HILInitialize_Card = NULL;
  }
}
