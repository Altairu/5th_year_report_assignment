/*
 * ex_stable_data.c
 *
 * Code generation for model "ex_stable".
 *
 * Model version              : 1.46
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Sep 27 11:32:31 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "ex_stable.h"
#include "ex_stable_private.h"

/* Block parameters (auto storage) */
P_ex_stable_T ex_stable_P = {
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/Constant1'
                                        */
  3.1415926535897931,                  /* Expression: pi
                                        * Referenced by: '<S1>/Constant'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_start
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_in
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_terminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: set_other_outputs_at_switch_out
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_input_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_input_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  10.0,                                /* Expression: analog_output_maximums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* Expression: analog_output_minimums
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: watchdog_analog_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  24305.934065934067,                  /* Expression: pwm_frequency
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: pwm_leading_deadband
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: pwm_trailing_deadband
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: initial_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: final_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* Expression: watchdog_pwm_outputs
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  -0.0015339807878856412,              /* Expression: -2*pi/4096
                                        * Referenced by: '<S1>/Gain (count to rad)'
                                        */
  0.3,                                 /* Expression: 0.3
                                        * Referenced by: '<Root>/Constant1'
                                        */
  2.2677183210380481E-5,               /* Expression: -0.8/-35277.75
                                        * Referenced by: '<S1>/Gain (count to meter)'
                                        */
  -28.571428571428569,                 /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  28.571428571428569,                  /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  -28.571428571428569,                 /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */
  28.571428571428569,                  /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<Root>/Transfer Fcn1'
                                        */

  /*  Expression: K
   * Referenced by: '<Root>/Gain'
   */
  { 92.90925299870743, 44.160191086788082, 122.44988681963939,
    23.725498310256139 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain (polarity)'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S1>/Saturation'
                                        */

  /*  Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },
  1,                                   /* Computed Parameter: HILInitialize_DOWatchdog
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIInitial
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POModes
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POConfiguration
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POAlignment
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POPolarity
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* Computed Parameter: HILInitialize_EIQuadrature
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */

  /*  Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  1U,                                  /* Computed Parameter: HILReadEncoder1_Channels
                                        * Referenced by: '<S1>/HIL Read Encoder1'
                                        */
  0U,                                  /* Computed Parameter: HILReadEncoder_Channels
                                        * Referenced by: '<S1>/HIL Read Encoder'
                                        */
  0U,                                  /* Computed Parameter: HILWriteAnalog_Channels
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
  1U,                                  /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_Active
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_CKEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AIPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AIPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_AOTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_AOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_DOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_EIStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_EIEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POPStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POPEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POStart
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POEnter
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_POTerminate
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POExit
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_POReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  0,                                   /* Computed Parameter: HILInitialize_OOReset
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOInitial
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILInitialize_DOFinal
                                        * Referenced by: '<Root>/HIL Initialize'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoder1_Active
                                        * Referenced by: '<S1>/HIL Read Encoder1'
                                        */
  1,                                   /* Computed Parameter: HILReadEncoder_Active
                                        * Referenced by: '<S1>/HIL Read Encoder'
                                        */
  0                                    /* Computed Parameter: HILWriteAnalog_Active
                                        * Referenced by: '<S1>/HIL Write Analog'
                                        */
};
