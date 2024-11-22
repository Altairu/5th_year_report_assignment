/*
 * cart_count2.c
 *
 * Code generation for model "cart_count2".
 *
 * Model version              : 1.18
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Sep 20 10:59:47 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "cart_count2.h"
#include "cart_count2_private.h"
#include "cart_count2_dt.h"

/* Block signals (auto storage) */
B_cart_count2_T cart_count2_B;

/* Block states (auto storage) */
DW_cart_count2_T cart_count2_DW;

/* Real-time model */
RT_MODEL_cart_count2_T cart_count2_M_;
RT_MODEL_cart_count2_T *const cart_count2_M = &cart_count2_M_;

/* Model step function */
void cart_count2_step(void)
{
  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: cart_count2/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder(cart_count2_DW.HILInitialize_Card,
      &cart_count2_P.HILReadEncoder_Channels, 1,
      &cart_count2_DW.HILReadEncoder_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_count2_M, _rt_error_message);
    } else {
      cart_count2_B.HILReadEncoder = cart_count2_DW.HILReadEncoder_Buffer;
    }
  }

  /* Gain: '<Root>/Gain' */
  cart_count2_B.Gain = cart_count2_P.Gain_Gain * cart_count2_B.HILReadEncoder;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.001s, 0.0s] */
    rtExtModeUpload(0, cart_count2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(cart_count2_M)!=-1) &&
        !((rtmGetTFinal(cart_count2_M)-cart_count2_M->Timing.taskTime0) >
          cart_count2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(cart_count2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(cart_count2_M)) {
      rtmSetErrorStatus(cart_count2_M, "Simulation finished");
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
  if (!(++cart_count2_M->Timing.clockTick0)) {
    ++cart_count2_M->Timing.clockTickH0;
  }

  cart_count2_M->Timing.taskTime0 = cart_count2_M->Timing.clockTick0 *
    cart_count2_M->Timing.stepSize0 + cart_count2_M->Timing.clockTickH0 *
    cart_count2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void cart_count2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)cart_count2_M, 0,
                sizeof(RT_MODEL_cart_count2_T));
  rtmSetTFinal(cart_count2_M, -1);
  cart_count2_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  cart_count2_M->Sizes.checksums[0] = (2996383204U);
  cart_count2_M->Sizes.checksums[1] = (1483993917U);
  cart_count2_M->Sizes.checksums[2] = (3784709693U);
  cart_count2_M->Sizes.checksums[3] = (3935663850U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    cart_count2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(cart_count2_M->extModeInfo,
      &cart_count2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(cart_count2_M->extModeInfo,
                        cart_count2_M->Sizes.checksums);
    rteiSetTPtr(cart_count2_M->extModeInfo, rtmGetTPtr(cart_count2_M));
  }

  /* block I/O */
  (void) memset(((void *) &cart_count2_B), 0,
                sizeof(B_cart_count2_T));

  /* states (dwork) */
  (void) memset((void *)&cart_count2_DW, 0,
                sizeof(DW_cart_count2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    cart_count2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: cart_count2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &cart_count2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_count2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(cart_count2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_count2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(cart_count2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(cart_count2_M, _rt_error_message);
      return;
    }

    if ((cart_count2_P.HILInitialize_AIPStart && !is_switching) ||
        (cart_count2_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &cart_count2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = cart_count2_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &cart_count2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = cart_count2_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_AIChannels, 8U,
        &cart_count2_DW.HILInitialize_AIMinimums[0],
        &cart_count2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if ((cart_count2_P.HILInitialize_AOPStart && !is_switching) ||
        (cart_count2_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &cart_count2_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = cart_count2_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &cart_count2_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = cart_count2_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_AOChannels, 8U,
        &cart_count2_DW.HILInitialize_AOMinimums[0],
        &cart_count2_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if ((cart_count2_P.HILInitialize_AOStart && !is_switching) ||
        (cart_count2_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &cart_count2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = cart_count2_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_AOChannels, 8U,
        &cart_count2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if (cart_count2_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &cart_count2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = cart_count2_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (cart_count2_DW.HILInitialize_Card,
         cart_count2_P.HILInitialize_AOChannels, 8U,
         &cart_count2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if ((cart_count2_P.HILInitialize_EIPStart && !is_switching) ||
        (cart_count2_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &cart_count2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = cart_count2_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &cart_count2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if ((cart_count2_P.HILInitialize_EIStart && !is_switching) ||
        (cart_count2_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &cart_count2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = cart_count2_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_EIChannels, 8U,
        &cart_count2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if ((cart_count2_P.HILInitialize_POPStart && !is_switching) ||
        (cart_count2_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &cart_count2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = cart_count2_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &cart_count2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          cart_count2_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &cart_count2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            cart_count2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            cart_count2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              cart_count2_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            cart_count2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes]
              = (p_HILInitialize_POChannels[i1]);
            cart_count2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes]
              = cart_count2_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(cart_count2_DW.HILInitialize_Card,
          &cart_count2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &cart_count2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(cart_count2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(cart_count2_DW.HILInitialize_Card,
          &cart_count2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &cart_count2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(cart_count2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &cart_count2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = cart_count2_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &cart_count2_DW.HILInitialize_POAlignValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = cart_count2_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &cart_count2_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = cart_count2_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &cart_count2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &cart_count2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &cart_count2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &cart_count2_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = cart_count2_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &cart_count2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = cart_count2_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_POChannels, 8U,
        &cart_count2_DW.HILInitialize_POSortedFreqs[0],
        &cart_count2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if ((cart_count2_P.HILInitialize_POStart && !is_switching) ||
        (cart_count2_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &cart_count2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = cart_count2_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(cart_count2_DW.HILInitialize_Card,
        cart_count2_P.HILInitialize_POChannels, 8U,
        &cart_count2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }

    if (cart_count2_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &cart_count2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = cart_count2_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (cart_count2_DW.HILInitialize_Card,
         cart_count2_P.HILInitialize_POChannels, 8U,
         &cart_count2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        return;
      }
    }
  }
}

/* Model terminate function */
void cart_count2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: cart_count2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(cart_count2_DW.HILInitialize_Card);
    hil_monitor_stop_all(cart_count2_DW.HILInitialize_Card);
    is_switching = false;
    if ((cart_count2_P.HILInitialize_AOTerminate && !is_switching) ||
        (cart_count2_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &cart_count2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = cart_count2_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((cart_count2_P.HILInitialize_POTerminate && !is_switching) ||
        (cart_count2_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &cart_count2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = cart_count2_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(cart_count2_DW.HILInitialize_Card
                         , cart_count2_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , cart_count2_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &cart_count2_DW.HILInitialize_AOVoltages[0]
                         , &cart_count2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(cart_count2_DW.HILInitialize_Card,
            cart_count2_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &cart_count2_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(cart_count2_DW.HILInitialize_Card,
            cart_count2_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &cart_count2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(cart_count2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(cart_count2_DW.HILInitialize_Card);
    hil_monitor_delete_all(cart_count2_DW.HILInitialize_Card);
    hil_close(cart_count2_DW.HILInitialize_Card);
    cart_count2_DW.HILInitialize_Card = NULL;
  }
}
