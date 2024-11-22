/*
 * ex_cart_ident_dt.h
 *
 * Code generation for model "ex_cart_ident".
 *
 * Model version              : 1.32
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Fri Sep 27 10:06:41 2024
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(t_card)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "t_card"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&ex_cart_ident_B.Clock), 0, 0, 4 }
  ,

  { (char_T *)(&ex_cart_ident_DW.HILInitialize_AIMinimums[0]), 0, 0, 64 },

  { (char_T *)(&ex_cart_ident_DW.HILInitialize_Card), 14, 0, 1 },

  { (char_T *)(&ex_cart_ident_DW.ToWorkspace1_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&ex_cart_ident_DW.HILInitialize_ClockModes[0]), 6, 0, 45 },

  { (char_T *)(&ex_cart_ident_DW.HILInitialize_POSortedChans[0]), 7, 0, 8 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  6U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ex_cart_ident_P.HILInitialize_OOStart), 0, 0, 25 },

  { (char_T *)(&ex_cart_ident_P.HILInitialize_CKChannels[0]), 6, 0, 9 },

  { (char_T *)(&ex_cart_ident_P.HILInitialize_AIChannels[0]), 7, 0, 36 },

  { (char_T *)(&ex_cart_ident_P.HILInitialize_Active), 8, 0, 38 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] ex_cart_ident_dt.h */
