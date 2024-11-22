/*
 * ad_conv.c
 *
 * Code generation for model "ad_conv".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Oct 11 10:06:06 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ad_conv.h"
#include "ad_conv_private.h"
#include "ad_conv_dt.h"

/* Block signals (auto storage) */
B_ad_conv_T ad_conv_B;

/* Block states (auto storage) */
DW_ad_conv_T ad_conv_DW;

/* Real-time model */
RT_MODEL_ad_conv_T ad_conv_M_;
RT_MODEL_ad_conv_T *const ad_conv_M = &ad_conv_M_;

/* Model step function */
void ad_conv_step(void)
{
  /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

  /* S-Function Block: ad_conv/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog(ad_conv_DW.HILInitialize_Card,
                                     &ad_conv_P.HILReadAnalog_Channels, 1, &ad_conv_DW.HILReadAnalog_Buffer);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_conv_M, _rt_error_message);
    }

    ad_conv_B.HILReadAnalog = ad_conv_DW.HILReadAnalog_Buffer;
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  { /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, ad_conv_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  { /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(ad_conv_M) != -1) &&
        !((rtmGetTFinal(ad_conv_M) - ad_conv_M->Timing.taskTime0) >
          ad_conv_M->Timing.taskTime0 * (DBL_EPSILON)))
    {
      rtmSetErrorStatus(ad_conv_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ad_conv_M))
    {
      rtmSetErrorStatus(ad_conv_M, "Simulation finished");
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
  if (!(++ad_conv_M->Timing.clockTick0))
  {
    ++ad_conv_M->Timing.clockTickH0;
  }

  ad_conv_M->Timing.taskTime0 = ad_conv_M->Timing.clockTick0 *
                                    ad_conv_M->Timing.stepSize0 +
                                ad_conv_M->Timing.clockTickH0 *
                                    ad_conv_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void ad_conv_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void)memset((void *)ad_conv_M, 0,
               sizeof(RT_MODEL_ad_conv_T));
  rtmSetTFinal(ad_conv_M, -1);
  ad_conv_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  ad_conv_M->Sizes.checksums[0] = (2057187266U);
  ad_conv_M->Sizes.checksums[1] = (1642042524U);
  ad_conv_M->Sizes.checksums[2] = (2954182742U);
  ad_conv_M->Sizes.checksums[3] = (1529370920U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ad_conv_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ad_conv_M->extModeInfo,
                               &ad_conv_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ad_conv_M->extModeInfo, ad_conv_M->Sizes.checksums);
    rteiSetTPtr(ad_conv_M->extModeInfo, rtmGetTPtr(ad_conv_M));
  }

  /* block I/O */
  (void)memset(((void *)&ad_conv_B), 0,
               sizeof(B_ad_conv_T));

  /* states (dwork) */
  (void)memset((void *)&ad_conv_DW, 0,
               sizeof(DW_ad_conv_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void)memset((char_T *)&dtInfo, 0,
                 sizeof(dtInfo));
    ad_conv_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: ad_conv/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &ad_conv_DW.HILInitialize_Card);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_conv_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(ad_conv_DW.HILInitialize_Card,
                                           "update_rate=normal;decimation=1", 32);
    if (result < 0)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_conv_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(ad_conv_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR)
    {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
      rtmSetErrorStatus(ad_conv_M, _rt_error_message);
      return;
    }

    if ((ad_conv_P.HILInitialize_AIPStart && !is_switching) ||
        (ad_conv_P.HILInitialize_AIPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AIMinimums = &ad_conv_DW.HILInitialize_AIMinimums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AIMinimums[i1] = ad_conv_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &ad_conv_DW.HILInitialize_AIMaximums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AIMaximums[i1] = ad_conv_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(ad_conv_DW.HILInitialize_Card,
                                           ad_conv_P.HILInitialize_AIChannels, 8U,
                                           &ad_conv_DW.HILInitialize_AIMinimums[0],
                                           &ad_conv_DW.HILInitialize_AIMaximums[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_conv_P.HILInitialize_AOPStart && !is_switching) ||
        (ad_conv_P.HILInitialize_AOPEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOMinimums = &ad_conv_DW.HILInitialize_AOMinimums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOMinimums[i1] = ad_conv_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &ad_conv_DW.HILInitialize_AOMaximums[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOMaximums[i1] = ad_conv_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(ad_conv_DW.HILInitialize_Card,
                                            ad_conv_P.HILInitialize_AOChannels, 8U,
                                            &ad_conv_DW.HILInitialize_AOMinimums[0],
                                            &ad_conv_DW.HILInitialize_AOMaximums[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_conv_P.HILInitialize_AOStart && !is_switching) ||
        (ad_conv_P.HILInitialize_AOEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ad_conv_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ad_conv_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(ad_conv_DW.HILInitialize_Card,
                                ad_conv_P.HILInitialize_AOChannels, 8U,
                                &ad_conv_DW.HILInitialize_AOVoltages[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if (ad_conv_P.HILInitialize_AOReset)
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ad_conv_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ad_conv_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state(ad_conv_DW.HILInitialize_Card, ad_conv_P.HILInitialize_AOChannels, 8U,
                                                        &ad_conv_DW.HILInitialize_AOVoltages[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_conv_P.HILInitialize_EIPStart && !is_switching) ||
        (ad_conv_P.HILInitialize_EIPEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &ad_conv_DW.HILInitialize_QuadratureModes
                                           [0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_QuadratureModes[i1] = ad_conv_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(ad_conv_DW.HILInitialize_Card,
                                               ad_conv_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)&ad_conv_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_conv_P.HILInitialize_EIStart && !is_switching) ||
        (ad_conv_P.HILInitialize_EIEnter && is_switching))
    {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &ad_conv_DW.HILInitialize_InitialEICounts
                                           [0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_InitialEICounts[i1] = ad_conv_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(ad_conv_DW.HILInitialize_Card,
                                      ad_conv_P.HILInitialize_EIChannels, 8U,
                                      &ad_conv_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_conv_P.HILInitialize_POPStart && !is_switching) ||
        (ad_conv_P.HILInitialize_POPEnter && is_switching))
    {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &ad_conv_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POModeValues[i1] = ad_conv_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(ad_conv_DW.HILInitialize_Card,
                                ad_conv_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)&ad_conv_DW.HILInitialize_POModeValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
            ad_conv_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &ad_conv_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] == PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE)
          {
            ad_conv_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
                (p_HILInitialize_POChannels[i1]);
            ad_conv_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
                ad_conv_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          }
          else
          {
            ad_conv_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
                (p_HILInitialize_POChannels[i1]);
            ad_conv_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
                ad_conv_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0)
      {
        result = hil_set_pwm_frequency(ad_conv_DW.HILInitialize_Card,
                                       &ad_conv_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
                                       &ad_conv_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ad_conv_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0)
      {
        result = hil_set_pwm_duty_cycle(ad_conv_DW.HILInitialize_Card,
                                        &ad_conv_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
                                        num_frequency_modes,
                                        &ad_conv_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ad_conv_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &ad_conv_DW.HILInitialize_POModeValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POModeValues[i1] = ad_conv_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &ad_conv_DW.HILInitialize_POAlignValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POAlignValues[i1] = ad_conv_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &ad_conv_DW.HILInitialize_POPolarityVals[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POPolarityVals[i1] = ad_conv_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(ad_conv_DW.HILInitialize_Card,
                                         ad_conv_P.HILInitialize_POChannels, 8U,
                                         (t_pwm_configuration *)&ad_conv_DW.HILInitialize_POModeValues[0],
                                         (t_pwm_alignment *)&ad_conv_DW.HILInitialize_POAlignValues[0],
                                         (t_pwm_polarity *)&ad_conv_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &ad_conv_DW.HILInitialize_POSortedFreqs[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POSortedFreqs[i1] = ad_conv_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &ad_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_conv_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(ad_conv_DW.HILInitialize_Card,
                                    ad_conv_P.HILInitialize_POChannels, 8U,
                                    &ad_conv_DW.HILInitialize_POSortedFreqs[0],
                                    &ad_conv_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if ((ad_conv_P.HILInitialize_POStart && !is_switching) ||
        (ad_conv_P.HILInitialize_POEnter && is_switching))
    {
      {
        int_T i1;
        real_T *dw_POValues = &ad_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_conv_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(ad_conv_DW.HILInitialize_Card,
                             ad_conv_P.HILInitialize_POChannels, 8U,
                             &ad_conv_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }

    if (ad_conv_P.HILInitialize_POReset)
    {
      {
        int_T i1;
        real_T *dw_POValues = &ad_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_conv_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state(ad_conv_DW.HILInitialize_Card, ad_conv_P.HILInitialize_POChannels, 8U,
                                                     &ad_conv_DW.HILInitialize_POValues[0]);
      if (result < 0)
      {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
        rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void ad_conv_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: ad_conv/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(ad_conv_DW.HILInitialize_Card);
    hil_monitor_stop_all(ad_conv_DW.HILInitialize_Card);
    is_switching = false;
    if ((ad_conv_P.HILInitialize_AOTerminate && !is_switching) ||
        (ad_conv_P.HILInitialize_AOExit && is_switching))
    {
      {
        int_T i1;
        real_T *dw_AOVoltages = &ad_conv_DW.HILInitialize_AOVoltages[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_AOVoltages[i1] = ad_conv_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((ad_conv_P.HILInitialize_POTerminate && !is_switching) ||
        (ad_conv_P.HILInitialize_POExit && is_switching))
    {
      {
        int_T i1;
        real_T *dw_POValues = &ad_conv_DW.HILInitialize_POValues[0];
        for (i1 = 0; i1 < 8; i1++)
        {
          dw_POValues[i1] = ad_conv_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0 || num_final_analog_outputs > 0 || num_final_pwm_outputs > 0)
    {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(ad_conv_DW.HILInitialize_Card, ad_conv_P.HILInitialize_AOChannels,
                         num_final_analog_outputs, ad_conv_P.HILInitialize_POChannels,
                         num_final_pwm_outputs, NULL, 0, NULL, 0, &ad_conv_DW.HILInitialize_AOVoltages[0], &ad_conv_DW.HILInitialize_POValues[0], (t_boolean *)NULL, NULL);
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED)
      {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0)
        {
          local_result = hil_write_analog(ad_conv_DW.HILInitialize_Card,
                                          ad_conv_P.HILInitialize_AOChannels, num_final_analog_outputs,
                                          &ad_conv_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0)
          {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0)
        {
          local_result = hil_write_pwm(ad_conv_DW.HILInitialize_Card,
                                       ad_conv_P.HILInitialize_POChannels, num_final_pwm_outputs,
                                       &ad_conv_DW.HILInitialize_POValues[0]);
          if (local_result < 0)
          {
            result = local_result;
          }
        }

        if (result < 0)
        {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof(_rt_error_message));
          rtmSetErrorStatus(ad_conv_M, _rt_error_message);
        }
      }
    }

    hil_task_
    {
      \mathrm { d }
    }
    elete_all(ad_conv_DW.HILInitialize_Card);
    hil_monitor_delete_all(ad_conv_DW.HILInitialize_Card);
    hil_close(ad_conv_DW.HILInitialize_Card);
    ad_conv_DW.HILInitialize_Card = NULL;
  }
}
