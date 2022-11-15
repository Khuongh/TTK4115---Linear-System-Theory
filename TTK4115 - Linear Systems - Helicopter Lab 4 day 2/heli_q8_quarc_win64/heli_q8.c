/*
 * heli_q8.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8".
 *
 * Model version              : 11.43
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Nov 15 17:31:30 2022
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8.h"
#include "heli_q8_private.h"
#include "heli_q8_dt.h"

t_stream heli_q8_rtZt_stream = NULL;

/* Block signals (default storage) */
B_heli_q8_T heli_q8_B;

/* Continuous states */
X_heli_q8_T heli_q8_X;

/* Block states (default storage) */
DW_heli_q8_T heli_q8_DW;

/* Real-time model */
static RT_MODEL_heli_q8_T heli_q8_M_;
RT_MODEL_heli_q8_T *const heli_q8_M = &heli_q8_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_M->Timing.perTaskSampleHits[5] =
      heli_q8_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_M->Timing.TaskCounters.TID[2] = 0;
  }
}

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
  int_T nXc = 7;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void heli_q8_output0(void)             /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall1_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_TmpSignalConversionAtToFile[14];
  real_T rtb_TmpSignalConversionAtToFi_b[6];
  real_T rtb_DeadZoney;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  int32_T rtb_StreamRead1_o5;
  boolean_T rtb_StreamRead1_o3;
  static const real_T a_0[36] = { 1.0, 0.0, 0.0, 0.0, 1.22347805752592E-6,
    0.0012234780575259199, 0.002, 1.0, 0.0, 0.0, 1.22347805752592E-9,
    1.22347805752592E-6, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002, 1.0 };

  static const real_T b[36] = { 1.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.002, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    1.22347805752592E-6, 1.22347805752592E-9, 0.0, 0.0, 1.0, 0.002,
    0.0012234780575259199, 1.22347805752592E-6, 0.0, 0.0, 0.0, 1.0 };

  real_T A[36];
  real_T A_0[36];
  real_T A_tmp[36];
  real_T X[36];
  real_T X_0[36];
  real_T b_I_0[36];
  real_T tmp_2[9];
  real_T a[6];
  real_T tmp_0[6];
  real_T tmp_1[6];
  real_T tmp_4[5];
  real_T tmp_3[3];
  real_T rtb_Sum6[2];
  real_T tmp_5[2];
  real_T tmp_6[2];
  real_T Sum3_tmp;
  real_T Sum3_tmp_0;
  real_T a_y;
  real_T a_z;
  int32_T c_ix;
  int32_T d_j;
  int32_T i;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T jBcol;
  int32_T kBcol;
  int8_T b_I[36];
  int8_T ipiv[6];
  int8_T ipiv_0;
  boolean_T tmp;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* set solver stop time */
    if (!(heli_q8_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_M->solverInfo,
                            ((heli_q8_M->Timing.clockTickH0 + 1) *
        heli_q8_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_M->solverInfo,
                            ((heli_q8_M->Timing.clockTick0 + 1) *
        heli_q8_M->Timing.stepSize0 + heli_q8_M->Timing.clockTickH0 *
        heli_q8_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_M)) {
    heli_q8_M->Timing.t[0] = rtsiGetT(&heli_q8_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(heli_q8_DW.HILReadEncoderTimebase_Task, 1,
        &heli_q8_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_HILReadEncoderTimebase_o2 =
          heli_q8_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_DeadZoney = heli_q8_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* S-Function (stream_call_block): '<S5>/Stream Call1' incorporates:
     *  Constant: '<S5>/Constant'
     *  S-Function (string_constant_block): '<S5>/String Constant'
     */

    /* S-Function Block: heli_q8/IMU/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_P.StringConstant_Value, 255) ==
                255) {
              rtmSetErrorStatus(heli_q8_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *) heli_q8_P.StringConstant_Value,
                heli_q8_P.StreamCall1_NonBlocking != 0,
                heli_q8_P.StreamCall1_SendBufferSize,
                heli_q8_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(heli_q8_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall1_o1 = &heli_q8_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close(heli_q8_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_B.StreamCall1_o2 = heli_q8_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S5>/Stream Formatted Write' incorporates:
     *  Constant: '<S5>/Constant1'
     */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_P.StreamFormattedWrite_MaxUnits, &rtb_StreamFormattedWrite_o2,
          "%c\n"
          , (char) heli_q8_P.Constant1_Value_n
          );
        if (result > 0) {
          result = stream_flush(*rtb_StreamCall1_o1);
        }

        if (result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      }
    }

    /* S-Function (stream_read_block): '<S5>/Stream Read1' incorporates:
     *  Constant: '<S5>/Constant1'
     *  S-Function (stream_call_block): '<S5>/Stream Call1'
     *  S-Function (stream_formatted_write_block): '<S5>/Stream Formatted Write'
     */

    /* S-Function Block: heli_q8/IMU/Stream Read1 (stream_read_block) */
    {
      t_error result;
      memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
      if (((t_stream_ptr)rtb_StreamCall1_o1) != NULL) {
        result = stream_receive_unit_array(*((t_stream_ptr)rtb_StreamCall1_o1),
          &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
        rtb_StreamRead1_o3 = (result > 0);
        if (result > 0 || result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      } else {
        rtb_StreamRead1_o3 = false;
        result = 0;
      }

      rtb_StreamRead1_o5 = (int32_T) result;
    }

    for (i = 0; i < 10; i++) {
      /* Switch: '<S5>/Switch' */
      if (rtb_StreamRead1_o3) {
        /* Switch: '<S5>/Switch' incorporates:
         *  DataTypeConversion: '<S5>/Data Type Conversion'
         */
        heli_q8_B.Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        /* Switch: '<S5>/Switch' incorporates:
         *  Memory: '<S5>/Memory'
         */
        heli_q8_B.Switch[i] = heli_q8_DW.Memory_PreviousInput[i];
      }

      /* End of Switch: '<S5>/Switch' */
    }

    for (d_j = 0; d_j < 3; d_j++) {
      /* Gain: '<S5>/Gain2' */
      heli_q8_B.Gain2[d_j] = 0.0;
      heli_q8_B.Gain2[d_j] += heli_q8_P.Gain2_Gain[d_j] * heli_q8_B.Switch[0];
      heli_q8_B.Gain2[d_j] += heli_q8_P.Gain2_Gain[d_j + 3] * heli_q8_B.Switch[1];
      heli_q8_B.Gain2[d_j] += heli_q8_P.Gain2_Gain[d_j + 6] * heli_q8_B.Switch[2];
    }

    /* Gain: '<S4>/Elevation: Count to rad' */
    heli_q8_B.ElevationCounttorad = heli_q8_P.ElevationCounttorad_Gain *
      rtb_DeadZoney;

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     */
    heli_q8_B.Sum = heli_q8_B.ElevationCounttorad - heli_q8_P.Constant_Value_f;

    /* MATLAB Function: '<Root>/[a_x, a_y, a_z]  to [pitch, elevation]' */
    /* MATLAB Function '[a_x, a_y, a_z]  to [pitch, elevation]': '<S11>:1' */
    /* '<S11>:1:3' */
    /* '<S11>:1:4' */
    a_y = heli_q8_B.Gain2[1];

    /* '<S11>:1:5' */
    a_z = heli_q8_B.Gain2[2];
    if (heli_q8_B.Gain2[1] == 0.0) {
      /* '<S11>:1:7' */
      /* '<S11>:1:8' */
      a_y = 0.0001;
    }

    if (heli_q8_B.Gain2[2] == 0.0) {
      /* '<S11>:1:11' */
      /* '<S11>:1:12' */
      a_z = 0.0001;
    }

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Deviations pitch & elev'
     *  MATLAB Function: '<Root>/[a_x, a_y, a_z]  to [pitch, elevation]'
     */
    /* '<S11>:1:15' */
    /* '<S11>:1:16' */
    /* '<S11>:1:17' */
    heli_q8_B.Sum1[0] = atan(a_y / a_z) + heli_q8_P.dev_states_IMU[0];
    heli_q8_B.Sum1[1] = atan(heli_q8_B.Gain2[0] / sqrt(a_y * a_y + a_z * a_z)) +
      heli_q8_P.dev_states_IMU[1];

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]' incorporates:
     *  Sum: '<Root>/Sum1'
     */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travle rate]': '<S3>:1' */
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    /* '<S3>:1:8' */
    /* '<S3>:1:11' */
    a_y = tan(heli_q8_B.Sum1[1]);
    a_z = sin(heli_q8_B.Sum1[0]);
    Sum3_tmp = cos(heli_q8_B.Sum1[0]);
    Sum3_tmp_0 = cos(heli_q8_B.Sum1[1]);
    tmp_2[0] = 1.0;
    tmp_2[3] = a_z * a_y;
    tmp_2[6] = Sum3_tmp * a_y;
    tmp_2[1] = 0.0;
    tmp_2[4] = Sum3_tmp;
    tmp_2[7] = -a_z;
    tmp_2[2] = 0.0;
    tmp_2[5] = a_z / Sum3_tmp_0;
    tmp_2[8] = Sum3_tmp / Sum3_tmp_0;

    /* Gain: '<S5>/Gain1' */
    for (d_j = 0; d_j < 3; d_j++) {
      tmp_3[d_j] = heli_q8_P.Gain1_Gain[d_j + 6] * heli_q8_B.Switch[5] +
        (heli_q8_P.Gain1_Gain[d_j + 3] * heli_q8_B.Switch[4] +
         heli_q8_P.Gain1_Gain[d_j] * heli_q8_B.Switch[3]);
    }

    /* End of Gain: '<S5>/Gain1' */
    for (d_j = 0; d_j < 3; d_j++) {
      /* Sum: '<Root>/Sum3' incorporates:
       *  Constant: '<Root>/Deviations rates'
       *  MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travle rate]'
       */
      heli_q8_B.Sum3[d_j] = (tmp_2[d_j + 6] * tmp_3[2] + (tmp_2[d_j + 3] *
        tmp_3[1] + tmp_2[d_j] * tmp_3[0])) + heli_q8_P.dev_rates_IMU[d_j];
    }

    for (i = 0; i < 6; i++) {
      /* Memory: '<Root>/Memory1' */
      heli_q8_B.Memory1[i] = heli_q8_DW.Memory1_PreviousInput[i];
    }

    /* Memory: '<Root>/Memory' */
    memcpy(&heli_q8_B.Memory[0], &heli_q8_DW.Memory_PreviousInput_b[0], 36U *
           sizeof(real_T));
  }

  /* Integrator: '<Root>/Integrator' */
  heli_q8_B.Integrator = heli_q8_X.Integrator_CSTATE;

  /* MATLAB Function: '<Root>/Kalman estimator' incorporates:
   *  Memory: '<Root>/Memory'
   */
  /* MATLAB Function 'Kalman estimator': '<S8>:1' */
  /* '<S8>:1:4' */
  for (d_j = 0; d_j < 6; d_j++) {
    for (iy = 0; iy < 6; iy++) {
      i = 6 * iy + d_j;
      A_tmp[iy + 6 * d_j] = heli_q8_P.SYSD_C[i];
      X[i] = 0.0;
      for (ix = 0; ix < 6; ix++) {
        X[i] += heli_q8_P.SYSD_C[6 * ix + d_j] * heli_q8_B.Memory[6 * iy + ix];
      }
    }
  }

  for (d_j = 0; d_j < 6; d_j++) {
    for (iy = 0; iy < 6; iy++) {
      a_y = 0.0;
      for (ix = 0; ix < 6; ix++) {
        a_y += X[6 * ix + d_j] * A_tmp[6 * iy + ix];
      }

      i = 6 * iy + d_j;
      A[i] = heli_q8_P.R_d[i] + a_y;
    }

    ipiv[d_j] = (int8_T)(d_j + 1);
  }

  for (d_j = 0; d_j < 5; d_j++) {
    jBcol = d_j * 7;
    iy = 0;
    ix = jBcol;
    a_y = fabs(A[jBcol]);
    for (kBcol = 2; kBcol <= 6 - d_j; kBcol++) {
      ix++;
      a_z = fabs(A[ix]);
      if (a_z > a_y) {
        iy = kBcol - 1;
        a_y = a_z;
      }
    }

    if (A[jBcol + iy] != 0.0) {
      if (iy != 0) {
        iy += d_j;
        ipiv[d_j] = (int8_T)(iy + 1);
        ix = d_j;
        for (kBcol = 0; kBcol < 6; kBcol++) {
          a_y = A[ix];
          A[ix] = A[iy];
          A[iy] = a_y;
          ix += 6;
          iy += 6;
        }
      }

      iy = (jBcol - d_j) + 6;
      for (ix = jBcol + 1; ix < iy; ix++) {
        A[ix] /= A[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 6;
    for (kBcol = 0; kBcol <= 4 - d_j; kBcol++) {
      if (A[ix] != 0.0) {
        a_y = -A[ix];
        c_ix = jBcol + 1;
        i = (iy - d_j) + 12;
        for (ijA = iy + 7; ijA < i; ijA++) {
          A[ijA] += A[c_ix] * a_y;
          c_ix++;
        }
      }

      ix += 6;
      iy += 6;
    }
  }

  for (d_j = 0; d_j < 6; d_j++) {
    for (iy = 0; iy < 6; iy++) {
      i = iy + 6 * d_j;
      X[i] = 0.0;
      for (ix = 0; ix < 6; ix++) {
        X[i] += heli_q8_B.Memory[6 * ix + iy] * A_tmp[6 * d_j + ix];
      }
    }
  }

  for (d_j = 0; d_j < 6; d_j++) {
    jBcol = 6 * d_j;
    for (ix = 0; ix < d_j; ix++) {
      kBcol = 6 * ix;
      if (A[ix + jBcol] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          i = c_ix + jBcol;
          X[i] -= A[ix + jBcol] * X[c_ix + kBcol];
        }
      }
    }

    a_y = 1.0 / A[d_j + jBcol];
    for (iy = 0; iy < 6; iy++) {
      i = iy + jBcol;
      X[i] *= a_y;
    }
  }

  for (d_j = 5; d_j >= 0; d_j--) {
    jBcol = 6 * d_j;
    iy = 6 * d_j - 1;
    for (ix = d_j + 2; ix < 7; ix++) {
      kBcol = (ix - 1) * 6;
      if (A[ix + iy] != 0.0) {
        for (c_ix = 0; c_ix < 6; c_ix++) {
          i = c_ix + jBcol;
          X[i] -= A[ix + iy] * X[c_ix + kBcol];
        }
      }
    }
  }

  for (d_j = 4; d_j >= 0; d_j--) {
    ipiv_0 = ipiv[d_j];
    if (d_j + 1 != ipiv_0) {
      for (iy = 0; iy < 6; iy++) {
        ix = 6 * d_j + iy;
        a_y = X[ix];
        i = (ipiv_0 - 1) * 6 + iy;
        X[ix] = X[i];
        X[i] = a_y;
      }
    }
  }

  /* '<S8>:1:7' */
  for (d_j = 0; d_j < 36; d_j++) {
    A[d_j] = 0.0;
  }

  for (d_j = 0; d_j < 6; d_j++) {
    A[d_j + 6 * d_j] = 1.0;
  }

  /* '<S8>:1:10' */
  for (d_j = 0; d_j < 36; d_j++) {
    b_I[d_j] = 0;
  }

  for (d_j = 0; d_j < 6; d_j++) {
    b_I[d_j + 6 * d_j] = 1;
  }

  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* ManualSwitch: '<Root>/Manual Switch' */
    if (heli_q8_P.ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch' */
      heli_q8_B.ManualSwitch = rtb_StreamRead1_o3;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Constant1'
       */
      heli_q8_B.ManualSwitch = heli_q8_P.Constant1_Value;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch' */
    for (i = 0; i < 6; i++) {
      /* Memory: '<Root>/Memory2' */
      heli_q8_B.Memory2[i] = heli_q8_DW.Memory2_PreviousInput[i];
    }
  }

  /* Switch: '<Root>/Switch' */
  tmp = (heli_q8_B.ManualSwitch > heli_q8_P.Switch_Threshold);

  /* SignalConversion generated from: '<S8>/ SFunction ' incorporates:
   *  MATLAB Function: '<Root>/Kalman estimator'
   */
  a[0] = heli_q8_B.Sum1[0];
  a[1] = heli_q8_B.Sum3[0];
  a[2] = heli_q8_B.Sum1[1];
  a[3] = heli_q8_B.Sum3[1];
  a[4] = heli_q8_B.Integrator;
  a[5] = heli_q8_B.Sum3[2];

  /* MATLAB Function: '<Root>/Kalman estimator' */
  for (d_j = 0; d_j < 6; d_j++) {
    tmp_0[d_j] = 0.0;
    for (iy = 0; iy < 6; iy++) {
      tmp_0[d_j] += heli_q8_P.SYSD_C[6 * iy + d_j] * heli_q8_B.Memory1[iy];
    }

    tmp_1[d_j] = a[d_j] - tmp_0[d_j];
  }

  for (d_j = 0; d_j < 6; d_j++) {
    /* Switch: '<Root>/Switch' incorporates:
     *  MATLAB Function: '<Root>/Kalman estimator'
     */
    a_y = 0.0;
    for (iy = 0; iy < 6; iy++) {
      a_y += X[6 * iy + d_j] * tmp_1[iy];
    }

    /* Switch: '<Root>/Switch' */
    if (tmp) {
      /* Switch: '<Root>/Switch' incorporates:
       *  MATLAB Function: '<Root>/Kalman estimator'
       */
      heli_q8_B.Switch_a[d_j] = heli_q8_B.Memory1[d_j] + a_y;
    } else {
      /* Switch: '<Root>/Switch' incorporates:
       *  MATLAB Function: '<Root>/Kalman estimator'
       */
      heli_q8_B.Switch_a[d_j] = heli_q8_B.Memory2[d_j];
    }
  }

  /* Sum: '<Root>/Sum7' */
  heli_q8_B.Sum7 = heli_q8_B.Sum - heli_q8_B.Switch_a[2];
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  heli_q8_B.ElevationTransferFcn = 0.0;
  heli_q8_B.ElevationTransferFcn += heli_q8_P.ElevationTransferFcn_C *
    heli_q8_X.ElevationTransferFcn_CSTATE;
  heli_q8_B.ElevationTransferFcn += heli_q8_P.ElevationTransferFcn_D *
    heli_q8_B.ElevationCounttorad;

  /* Sum: '<Root>/Sum8' */
  heli_q8_B.Sum8 = heli_q8_B.ElevationTransferFcn - heli_q8_B.Switch_a[3];
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Gain: '<S4>/Pitch: Count to rad' */
    heli_q8_B.PitchCounttorad = heli_q8_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;
  }

  /* Sum: '<Root>/Sum5' */
  heli_q8_B.Sum5 = heli_q8_B.PitchCounttorad - heli_q8_B.Switch_a[0];
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  heli_q8_B.PitchTransferFcn = 0.0;
  heli_q8_B.PitchTransferFcn += heli_q8_P.PitchTransferFcn_C *
    heli_q8_X.PitchTransferFcn_CSTATE;
  heli_q8_B.PitchTransferFcn += heli_q8_P.PitchTransferFcn_D *
    heli_q8_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* Sum: '<Root>/Sum6' */
  heli_q8_B.Sum6 = heli_q8_B.PitchTransferFcn - heli_q8_B.Switch_a[1];
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Gain: '<S4>/Travel: Count to rad' */
    heli_q8_B.TravelCounttorad = heli_q8_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S4>/Travel: Transfer Fcn' */
  heli_q8_B.TravelTransferFcn = 0.0;
  heli_q8_B.TravelTransferFcn += heli_q8_P.TravelTransferFcn_C *
    heli_q8_X.TravelTransferFcn_CSTATE;
  heli_q8_B.TravelTransferFcn += heli_q8_P.TravelTransferFcn_D *
    heli_q8_B.TravelCounttorad;

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<Root>/Step'
   *  Step: '<Root>/Step2'
   *  Step: '<Root>/Step3'
   */
  a_y = heli_q8_M->Timing.t[0];
  if (a_y < heli_q8_P.Step1_Time) {
    a_z = heli_q8_P.Step1_Y0;
  } else {
    a_z = heli_q8_P.Step1_YFinal;
  }

  /* End of Step: '<Root>/Step1' */

  /* Step: '<Root>/Step3' */
  if (a_y < heli_q8_P.Step3_Time) {
    Sum3_tmp = heli_q8_P.Step3_Y0;
  } else {
    Sum3_tmp = heli_q8_P.Step3_YFinal;
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum4'
   */
  heli_q8_B.Gain = (a_z + Sum3_tmp) * heli_q8_P.Gain_Gain;

  /* Step: '<Root>/Step' */
  if (a_y < heli_q8_P.Step_Time) {
    a_z = heli_q8_P.Step_Y0;
  } else {
    a_z = heli_q8_P.Step_YFinal;
  }

  /* Step: '<Root>/Step2' */
  if (a_y < heli_q8_P.Step2_Time) {
    a_y = heli_q8_P.Step2_Y0;
  } else {
    a_y = heli_q8_P.Step2_YFinal;
  }

  /* Gain: '<Root>/Gain1' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  heli_q8_B.Gain1 = (a_z + a_y) * heli_q8_P.Gain1_Gain_h;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* SignalConversion generated from: '<Root>/To File1' */
    rtb_TmpSignalConversionAtToFile[0] = heli_q8_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[1] = heli_q8_B.Switch_a[0];
    rtb_TmpSignalConversionAtToFile[2] = heli_q8_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[3] = heli_q8_B.Switch_a[1];
    rtb_TmpSignalConversionAtToFile[4] = heli_q8_B.Sum;
    rtb_TmpSignalConversionAtToFile[5] = heli_q8_B.Switch_a[2];
    rtb_TmpSignalConversionAtToFile[6] = heli_q8_B.ElevationTransferFcn;
    rtb_TmpSignalConversionAtToFile[7] = heli_q8_B.Switch_a[3];
    rtb_TmpSignalConversionAtToFile[8] = heli_q8_B.TravelCounttorad;
    rtb_TmpSignalConversionAtToFile[9] = heli_q8_B.Switch_a[4];
    rtb_TmpSignalConversionAtToFile[10] = heli_q8_B.TravelTransferFcn;
    rtb_TmpSignalConversionAtToFile[11] = heli_q8_B.Switch_a[5];
    rtb_TmpSignalConversionAtToFile[12] = heli_q8_B.Gain;
    rtb_TmpSignalConversionAtToFile[13] = heli_q8_B.Gain1;

    /* ToFile: '<Root>/To File1' */
    if (rtmIsMajorTimeStep(heli_q8_M)) {
      if (rtmIsMajorTimeStep(heli_q8_M) ) {
        {
          if (!(++heli_q8_DW.ToFile1_IWORK.Decimation % 1) &&
              (heli_q8_DW.ToFile1_IWORK.Count * (14 + 1)) + 1 < 100000000 ) {
            FILE *fp = (FILE *) heli_q8_DW.ToFile1_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[14 + 1];
              heli_q8_DW.ToFile1_IWORK.Decimation = 0;
              u[0] = heli_q8_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFile[0];
              u[2] = rtb_TmpSignalConversionAtToFile[1];
              u[3] = rtb_TmpSignalConversionAtToFile[2];
              u[4] = rtb_TmpSignalConversionAtToFile[3];
              u[5] = rtb_TmpSignalConversionAtToFile[4];
              u[6] = rtb_TmpSignalConversionAtToFile[5];
              u[7] = rtb_TmpSignalConversionAtToFile[6];
              u[8] = rtb_TmpSignalConversionAtToFile[7];
              u[9] = rtb_TmpSignalConversionAtToFile[8];
              u[10] = rtb_TmpSignalConversionAtToFile[9];
              u[11] = rtb_TmpSignalConversionAtToFile[10];
              u[12] = rtb_TmpSignalConversionAtToFile[11];
              u[13] = rtb_TmpSignalConversionAtToFile[12];
              u[14] = rtb_TmpSignalConversionAtToFile[13];
              if (fwrite(u, sizeof(real_T), 14 + 1, fp) != 14 + 1) {
                rtmSetErrorStatus(heli_q8_M,
                                  "Error writing to MAT-file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat");
                return;
              }

              if (((++heli_q8_DW.ToFile1_IWORK.Count) * (14 + 1))+1 >= 100000000)
              {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat.\n");
              }
            }
          }
        }
      }
    }
  }

  /* Sum: '<Root>/Sum9' */
  heli_q8_B.Sum9 = heli_q8_B.TravelCounttorad - heli_q8_B.Switch_a[4];

  /* Sum: '<Root>/Sum10' */
  heli_q8_B.Sum10 = heli_q8_B.TravelTransferFcn - heli_q8_B.Switch_a[5];
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* SignalConversion generated from: '<Root>/To File2' */
    rtb_TmpSignalConversionAtToFi_b[0] = heli_q8_B.Sum5;
    rtb_TmpSignalConversionAtToFi_b[1] = heli_q8_B.Sum6;
    rtb_TmpSignalConversionAtToFi_b[2] = heli_q8_B.Sum7;
    rtb_TmpSignalConversionAtToFi_b[3] = heli_q8_B.Sum8;
    rtb_TmpSignalConversionAtToFi_b[4] = heli_q8_B.Sum9;
    rtb_TmpSignalConversionAtToFi_b[5] = heli_q8_B.Sum10;

    /* ToFile: '<Root>/To File2' */
    if (rtmIsMajorTimeStep(heli_q8_M)) {
      if (rtmIsMajorTimeStep(heli_q8_M) ) {
        {
          if (!(++heli_q8_DW.ToFile2_IWORK.Decimation % 1) &&
              (heli_q8_DW.ToFile2_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
            FILE *fp = (FILE *) heli_q8_DW.ToFile2_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[6 + 1];
              heli_q8_DW.ToFile2_IWORK.Decimation = 0;
              u[0] = heli_q8_M->Timing.t[1];
              u[1] = rtb_TmpSignalConversionAtToFi_b[0];
              u[2] = rtb_TmpSignalConversionAtToFi_b[1];
              u[3] = rtb_TmpSignalConversionAtToFi_b[2];
              u[4] = rtb_TmpSignalConversionAtToFi_b[3];
              u[5] = rtb_TmpSignalConversionAtToFi_b[4];
              u[6] = rtb_TmpSignalConversionAtToFi_b[5];
              if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
                rtmSetErrorStatus(heli_q8_M,
                                  "Error writing to MAT-file Lab_4_case_files\\Error_data\\case_1.12.mat");
                return;
              }

              if (((++heli_q8_DW.ToFile2_IWORK.Count) * (6 + 1))+1 >= 100000000)
              {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file Lab_4_case_files\\Error_data\\case_1.12.mat.\n");
              }
            }
          }
        }
      }
    }

    /* SignalConversion generated from: '<Root>/To File3' */
    heli_q8_B.TmpSignalConversionAtToFile3Inp[0] = heli_q8_B.Sum1[0];
    heli_q8_B.TmpSignalConversionAtToFile3Inp[1] = heli_q8_B.Sum3[0];
    heli_q8_B.TmpSignalConversionAtToFile3Inp[2] = heli_q8_B.Sum1[1];
    heli_q8_B.TmpSignalConversionAtToFile3Inp[3] = heli_q8_B.Sum3[1];
    heli_q8_B.TmpSignalConversionAtToFile3Inp[4] = heli_q8_B.Integrator;
    heli_q8_B.TmpSignalConversionAtToFile3Inp[5] = heli_q8_B.Sum3[2];

    /* ToFile: '<Root>/To File3' */
    if (rtmIsMajorTimeStep(heli_q8_M)) {
      if (rtmIsMajorTimeStep(heli_q8_M) ) {
        {
          if (!(++heli_q8_DW.ToFile3_IWORK.Decimation % 1) &&
              (heli_q8_DW.ToFile3_IWORK.Count * (6 + 1)) + 1 < 100000000 ) {
            FILE *fp = (FILE *) heli_q8_DW.ToFile3_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[6 + 1];
              heli_q8_DW.ToFile3_IWORK.Decimation = 0;
              u[0] = heli_q8_M->Timing.t[1];
              u[1] = heli_q8_B.TmpSignalConversionAtToFile3Inp[0];
              u[2] = heli_q8_B.TmpSignalConversionAtToFile3Inp[1];
              u[3] = heli_q8_B.TmpSignalConversionAtToFile3Inp[2];
              u[4] = heli_q8_B.TmpSignalConversionAtToFile3Inp[3];
              u[5] = heli_q8_B.TmpSignalConversionAtToFile3Inp[4];
              u[6] = heli_q8_B.TmpSignalConversionAtToFile3Inp[5];
              if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
                rtmSetErrorStatus(heli_q8_M,
                                  "Error writing to MAT-file Lab_4_case_files\\Measurements_data\\case_1.12.mat");
                return;
              }

              if (((++heli_q8_DW.ToFile3_IWORK.Count) * (6 + 1))+1 >= 100000000)
              {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file Lab_4_case_files\\Measurements_data\\case_1.12.mat.\n");
              }
            }
          }
        }
      }
    }
  }

  /* SignalConversion generated from: '<S9>/Gain11' incorporates:
   *  Integrator: '<S9>/Integrator'
   *  Integrator: '<S9>/Integrator1'
   */
  tmp_4[2] = heli_q8_B.Switch_a[3];
  tmp_4[3] = heli_q8_X.Integrator_CSTATE_m;
  tmp_4[4] = heli_q8_X.Integrator1_CSTATE;
  tmp_4[0] = heli_q8_B.Switch_a[0];

  /* Gain: '<S9>/Gain10' incorporates:
   *  SignalConversion generated from: '<S9>/Gain10'
   */
  tmp_5[0] = heli_q8_P.F[0] * heli_q8_B.Gain + heli_q8_P.F[2] * heli_q8_B.Gain1;

  /* SignalConversion generated from: '<S9>/Gain11' */
  tmp_4[1] = heli_q8_B.Switch_a[1];

  /* Gain: '<S9>/Gain10' incorporates:
   *  SignalConversion generated from: '<S9>/Gain10'
   */
  tmp_5[1] = heli_q8_P.F[1] * heli_q8_B.Gain;
  tmp_5[1] += heli_q8_P.F[3] * heli_q8_B.Gain1;
  for (d_j = 0; d_j < 2; d_j++) {
    /* Gain: '<S9>/Gain11' */
    tmp_6[d_j] = 0.0;
    for (iy = 0; iy < 5; iy++) {
      tmp_6[d_j] += heli_q8_P.K[(iy << 1) + d_j] * tmp_4[iy];
    }

    /* End of Gain: '<S9>/Gain11' */

    /* Sum: '<S9>/Sum6' */
    rtb_Sum6[d_j] = tmp_5[d_j] - tmp_6[d_j];
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  a_y = rtb_Sum6[0] + heli_q8_P.V_s0;

  /* Sum: '<S1>/Add' */
  a_z = a_y - rtb_Sum6[1];

  /* Sum: '<S1>/Subtract' */
  a_y += rtb_Sum6[1];

  /* Gain: '<S1>/Back gain' */
  a_y *= heli_q8_P.Backgain_Gain;

  /* Gain: '<S1>/Front gain' */
  a_z *= heli_q8_P.Frontgain_Gain;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
  }

  /* Saturate: '<S4>/Front motor: Saturation' */
  if (a_z > heli_q8_P.FrontmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    heli_q8_B.FrontmotorSaturation = heli_q8_P.FrontmotorSaturation_UpperSat;
  } else if (a_z < heli_q8_P.FrontmotorSaturation_LowerSat) {
    /* Saturate: '<S4>/Front motor: Saturation' */
    heli_q8_B.FrontmotorSaturation = heli_q8_P.FrontmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Front motor: Saturation' */
    heli_q8_B.FrontmotorSaturation = a_z;
  }

  /* End of Saturate: '<S4>/Front motor: Saturation' */

  /* Saturate: '<S4>/Back motor: Saturation' */
  if (a_y > heli_q8_P.BackmotorSaturation_UpperSat) {
    /* Saturate: '<S4>/Back motor: Saturation' */
    heli_q8_B.BackmotorSaturation = heli_q8_P.BackmotorSaturation_UpperSat;
  } else if (a_y < heli_q8_P.BackmotorSaturation_LowerSat) {
    /* Saturate: '<S4>/Back motor: Saturation' */
    heli_q8_B.BackmotorSaturation = heli_q8_P.BackmotorSaturation_LowerSat;
  } else {
    /* Saturate: '<S4>/Back motor: Saturation' */
    heli_q8_B.BackmotorSaturation = a_y;
  }

  /* End of Saturate: '<S4>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* S-Function (hil_write_analog_block): '<S4>/HIL Write Analog' */

    /* S-Function Block: heli_q8/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_DW.HILWriteAnalog_Buffer[0] = heli_q8_B.FrontmotorSaturation;
      heli_q8_DW.HILWriteAnalog_Buffer[1] = heli_q8_B.BackmotorSaturation;
      result = hil_write_analog(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILWriteAnalog_channels, 2, &heli_q8_DW.HILWriteAnalog_Buffer
        [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Call Error' */

    /* S-Function Block: heli_q8/IMU/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    /* S-Function (stop_with_error_block): '<S5>/Stop with Read Error' */

    /* S-Function Block: heli_q8/IMU/Stop with Read Error (stop_with_error_block) */
    {
      if (rtb_StreamRead1_o5 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamRead1_o5, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    /* Memory: '<Root>/Memory3' */
    memcpy(&heli_q8_B.Memory3[0], &heli_q8_DW.Memory3_PreviousInput[0], 36U *
           sizeof(real_T));
  }

  /* Switch: '<Root>/Switch1' */
  tmp = (heli_q8_B.ManualSwitch > heli_q8_P.Switch1_Threshold);

  /* MATLAB Function: '<Root>/Kalman estimator' incorporates:
   *  Memory: '<Root>/Memory'
   */
  for (d_j = 0; d_j < 6; d_j++) {
    for (iy = 0; iy < 6; iy++) {
      a_y = 0.0;
      for (ix = 0; ix < 6; ix++) {
        a_y += X[6 * ix + d_j] * heli_q8_P.SYSD_C[6 * iy + ix];
      }

      i = 6 * iy + d_j;
      A_tmp[i] = (real_T)b_I[i] - a_y;
    }

    for (iy = 0; iy < 6; iy++) {
      i = d_j + 6 * iy;
      b_I_0[i] = 0.0;
      for (ix = 0; ix < 6; ix++) {
        b_I_0[i] += A_tmp[6 * ix + d_j] * heli_q8_B.Memory[6 * iy + ix];
      }
    }
  }

  for (d_j = 0; d_j < 6; d_j++) {
    for (iy = 0; iy < 6; iy++) {
      a_y = 0.0;
      i = d_j + 6 * iy;
      X_0[i] = 0.0;
      for (ix = 0; ix < 6; ix++) {
        a_y += X[6 * ix + iy] * heli_q8_P.SYSD_C[6 * d_j + ix];
        X_0[i] += X[6 * ix + d_j] * heli_q8_P.R_d[6 * iy + ix];
      }

      A_0[i] = A[6 * d_j + iy] - a_y;
    }
  }

  for (d_j = 0; d_j < 6; d_j++) {
    for (iy = 0; iy < 6; iy++) {
      i = d_j + 6 * iy;
      A_tmp[i] = 0.0;
      A[i] = 0.0;
      for (ix = 0; ix < 6; ix++) {
        kBcol = 6 * ix + d_j;
        A_tmp[i] += b_I_0[kBcol] * A_0[6 * iy + ix];
        A[i] += X_0[kBcol] * X[6 * ix + iy];
      }
    }
  }

  for (d_j = 0; d_j < 36; d_j++) {
    /* Switch: '<Root>/Switch1' */
    if (tmp) {
      /* Switch: '<Root>/Switch1' incorporates:
       *  MATLAB Function: '<Root>/Kalman estimator'
       */
      heli_q8_B.Switch1[d_j] = A_tmp[d_j] + A[d_j];
    } else {
      /* Switch: '<Root>/Switch1' incorporates:
       *  MATLAB Function: '<Root>/Kalman estimator'
       *  Memory: '<Root>/Memory3'
       */
      heli_q8_B.Switch1[d_j] = heli_q8_B.Memory3[d_j];
    }
  }

  /* SignalConversion generated from: '<S7>/ SFunction ' incorporates:
   *  MATLAB Function: '<Root>/Kalman calculator'
   */
  /* MATLAB Function 'Kalman calculator': '<S7>:1' */
  /* '<S7>:1:5' */
  a_z = rtb_Sum6[1];
  Sum3_tmp = rtb_Sum6[0];

  /* MATLAB Function: '<Root>/Kalman calculator' incorporates:
   *  Switch: '<Root>/Switch1'
   */
  /* '<S7>:1:6' */
  for (d_j = 0; d_j < 6; d_j++) {
    a[d_j] = 0.0;
    for (iy = 0; iy < 6; iy++) {
      i = 6 * iy + d_j;
      A[i] = 0.0;
      for (ix = 0; ix < 6; ix++) {
        A[i] += a_0[6 * ix + d_j] * heli_q8_B.Switch1[6 * iy + ix];
      }

      a[d_j] += a_0[i] * heli_q8_B.Switch_a[iy];
    }

    heli_q8_B.x_pri[d_j] = a[d_j] + (heli_q8_P.SYSD_B[d_j + 6] * Sum3_tmp +
      heli_q8_P.SYSD_B[d_j] * a_z);
    for (iy = 0; iy < 6; iy++) {
      a_y = 0.0;
      for (ix = 0; ix < 6; ix++) {
        a_y += A[6 * ix + d_j] * b[6 * iy + ix];
      }

      i = 6 * iy + d_j;
      heli_q8_B.P_pri[i] = heli_q8_P.Q_d[i] + a_y;
    }
  }

  /* Sum: '<S9>/Sum7' */
  heli_q8_B.Sum7_h = heli_q8_B.Gain - heli_q8_B.Switch_a[0];

  /* Sum: '<S9>/Sum8' */
  heli_q8_B.Sum8_p = heli_q8_B.Gain1 - heli_q8_B.Switch_a[3];

  /* Integrator: '<S12>/Integrator' */
  /* Limited  Integrator  */
  if (heli_q8_X.Integrator_CSTATE_n >= heli_q8_P.Integrator_UpperSat) {
    heli_q8_X.Integrator_CSTATE_n = heli_q8_P.Integrator_UpperSat;
  } else {
    if (heli_q8_X.Integrator_CSTATE_n <= heli_q8_P.Integrator_LowerSat) {
      heli_q8_X.Integrator_CSTATE_n = heli_q8_P.Integrator_LowerSat;
    }
  }

  /* End of Integrator: '<S12>/Integrator' */
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* DeadZone: '<S6>/Dead Zone: y' incorporates:
     *  Sum: '<S2>/Sum'
     */
    rtb_DeadZoney = 0.0;

    /* Gain: '<S12>/K_ei' */
    heli_q8_B.K_ei = heli_q8_P.K_ei_Gain * rtb_DeadZoney;

    /* RateTransition: '<S6>/Rate Transition: x' */
    if (heli_q8_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: x' */
      heli_q8_B.RateTransitionx = heli_q8_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: x' */

    /* DeadZone: '<S6>/Dead Zone: x' */
    if (heli_q8_B.RateTransitionx > heli_q8_P.DeadZonex_End) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitionx - heli_q8_P.DeadZonex_End;
    } else if (heli_q8_B.RateTransitionx >= heli_q8_P.DeadZonex_Start) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitionx - heli_q8_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: x' */

    /* Gain: '<S6>/Joystick_gain_x' incorporates:
     *  Gain: '<S6>/Gain: x'
     */
    heli_q8_B.Joystick_gain_x = heli_q8_P.Gainx_Gain * rtb_DeadZoney *
      heli_q8_P.Joystick_gain_x;

    /* RateTransition: '<S6>/Rate Transition: y' */
    if (heli_q8_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S6>/Rate Transition: y' */
      heli_q8_B.RateTransitiony = heli_q8_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S6>/Rate Transition: y' */

    /* DeadZone: '<S6>/Dead Zone: y' */
    if (heli_q8_B.RateTransitiony > heli_q8_P.DeadZoney_End) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitiony - heli_q8_P.DeadZoney_End;
    } else if (heli_q8_B.RateTransitiony >= heli_q8_P.DeadZoney_Start) {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = 0.0;
    } else {
      /* DeadZone: '<S6>/Dead Zone: y' */
      rtb_DeadZoney = heli_q8_B.RateTransitiony - heli_q8_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S6>/Dead Zone: y' */

    /* Gain: '<S6>/Joystick_gain_y' incorporates:
     *  Gain: '<S6>/Gain: y'
     */
    heli_q8_B.Joystick_gain_y = heli_q8_P.Gainy_Gain * rtb_DeadZoney *
      heli_q8_P.Joystick_gain_y;
  }
}

/* Model update function for TID0 */
void heli_q8_update0(void)             /* Sample time: [0.0s, 0.0s] */
{
  int32_T i;
  if (rtmIsMajorTimeStep(heli_q8_M)) {
    /* Update for Memory: '<S5>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput[0], &heli_q8_B.Switch[0], 10U *
           sizeof(real_T));

    /* Update for Memory: '<Root>/Memory1' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.Memory1_PreviousInput[i] = heli_q8_B.x_pri[i];
    }

    /* End of Update for Memory: '<Root>/Memory1' */

    /* Update for Memory: '<Root>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput_b[0], &heli_q8_B.P_pri[0], 36U *
           sizeof(real_T));

    /* Update for Memory: '<Root>/Memory2' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.Memory2_PreviousInput[i] = heli_q8_B.Switch_a[i];
    }

    /* End of Update for Memory: '<Root>/Memory2' */

    /* Update for Memory: '<Root>/Memory3' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    memcpy(&heli_q8_DW.Memory3_PreviousInput[0], &heli_q8_B.Switch1[0], 36U *
           sizeof(real_T));
  }

  if (rtmIsMajorTimeStep(heli_q8_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_M->Timing.clockTick0)) {
    ++heli_q8_M->Timing.clockTickH0;
  }

  heli_q8_M->Timing.t[0] = rtsiGetSolverStopTime(&heli_q8_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_M->Timing.clockTick1)) {
    ++heli_q8_M->Timing.clockTickH1;
  }

  heli_q8_M->Timing.t[1] = heli_q8_M->Timing.clockTick1 *
    heli_q8_M->Timing.stepSize1 + heli_q8_M->Timing.clockTickH1 *
    heli_q8_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_derivatives(void)
{
  XDot_heli_q8_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_heli_q8_T *) heli_q8_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = heli_q8_B.Sum3[2];

  /* Derivatives for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_P.ElevationTransferFcn_A *
    heli_q8_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_P.PitchTransferFcn_A *
    heli_q8_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S4>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_P.TravelTransferFcn_A *
    heli_q8_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_B.TravelCounttorad;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE_m = heli_q8_B.Sum7_h;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_B.Sum8_p;

  /* Derivatives for Integrator: '<S12>/Integrator' */
  lsat = (heli_q8_X.Integrator_CSTATE_n <= heli_q8_P.Integrator_LowerSat);
  usat = (heli_q8_X.Integrator_CSTATE_n >= heli_q8_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (heli_q8_B.K_ei > 0.0)) || (usat &&
       (heli_q8_B.K_ei < 0.0))) {
    _rtXdot->Integrator_CSTATE_n = heli_q8_B.K_ei;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_n = 0.0;
  }

  /* End of Derivatives for Integrator: '<S12>/Integrator' */
}

/* Model output function for TID2 */
void heli_q8_output2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_DW.GameController_Controller, &state,
        &new_data);
      if (result < 0) {
        new_data = false;
      }

      rtb_GameController_o4 = state.x;
      rtb_GameController_o5 = state.y;
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
    }
  }

  /* RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void heli_q8_update2(void)             /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_M->Timing.clockTick2)) {
    ++heli_q8_M->Timing.clockTickH2;
  }

  heli_q8_M->Timing.t[2] = heli_q8_M->Timing.clockTick2 *
    heli_q8_M->Timing.stepSize2 + heli_q8_M->Timing.clockTickH2 *
    heli_q8_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_output0();
    break;

   case 2 :
    heli_q8_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_update0();
    break;

   case 2 :
    heli_q8_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      return;
    }

    if ((heli_q8_P.HILInitialize_AIPStart && !is_switching) ||
        (heli_q8_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_q8_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_AIChannels, 8U,
        &heli_q8_DW.HILInitialize_AIMinimums[0],
        &heli_q8_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_AOPStart && !is_switching) ||
        (heli_q8_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_q8_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_AOChannels, 8U,
        &heli_q8_DW.HILInitialize_AOMinimums[0],
        &heli_q8_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_AOStart && !is_switching) ||
        (heli_q8_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_AOChannels, 8U,
        &heli_q8_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_DW.HILInitialize_Card, heli_q8_P.HILInitialize_AOChannels, 8U,
         &heli_q8_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_EIPStart && !is_switching) ||
        (heli_q8_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &heli_q8_DW.HILInitialize_QuadratureModes
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_EIChannels, 8U, (t_encoder_quadrature_mode *)
        &heli_q8_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_EIStart && !is_switching) ||
        (heli_q8_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &heli_q8_DW.HILInitialize_InitialEICounts
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_EIChannels, 8U,
        &heli_q8_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_POPStart && !is_switching) ||
        (heli_q8_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &heli_q8_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          heli_q8_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_q8_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            heli_q8_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              (p_HILInitialize_POChannels[i1]);
            heli_q8_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              heli_q8_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_DW.HILInitialize_Card,
          &heli_q8_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_DW.HILInitialize_Card,
          &heli_q8_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &heli_q8_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &heli_q8_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &heli_q8_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &heli_q8_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_POChannels, 8U,
        &heli_q8_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_P.HILInitialize_POStart && !is_switching) ||
        (heli_q8_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(heli_q8_DW.HILInitialize_Card,
        heli_q8_P.HILInitialize_POChannels, 8U,
        &heli_q8_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_DW.HILInitialize_Card, heli_q8_P.HILInitialize_POChannels, 8U,
         &heli_q8_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S4>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_DW.HILInitialize_Card,
      heli_q8_P.HILReadEncoderTimebase_SamplesI,
      heli_q8_P.HILReadEncoderTimebase_Channels, 3,
      &heli_q8_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_q8_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (heli_q8_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S5>/Stream Call1' incorporates:
   *  Constant: '<S5>/Constant'
   *  S-Function (string_constant_block): '<S5>/String Constant'
   */

  /* S-Function Block: heli_q8/IMU/Stream Call1 (stream_call_block) */
  {
    heli_q8_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_DW.StreamCall1_Stream = NULL;
  }

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] =
      "Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error creating .mat file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 14 + 1, 0, "data_p")) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error writing mat file header to file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat");
      return;
    }

    heli_q8_DW.ToFile1_IWORK.Count = 0;
    heli_q8_DW.ToFile1_IWORK.Decimation = -1;
    heli_q8_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Lab_4_case_files\\Error_data\\case_1.12.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error creating .mat file Lab_4_case_files\\Error_data\\case_1.12.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "data_e")) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error writing mat file header to file Lab_4_case_files\\Error_data\\case_1.12.mat");
      return;
    }

    heli_q8_DW.ToFile2_IWORK.Count = 0;
    heli_q8_DW.ToFile2_IWORK.Decimation = -1;
    heli_q8_DW.ToFile2_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "Lab_4_case_files\\Measurements_data\\case_1.12.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error creating .mat file Lab_4_case_files\\Measurements_data\\case_1.12.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "data_y")) {
      rtmSetErrorStatus(heli_q8_M,
                        "Error writing mat file header to file Lab_4_case_files\\Measurements_data\\case_1.12.mat");
      return;
    }

    heli_q8_DW.ToFile3_IWORK.Count = 0;
    heli_q8_DW.ToFile3_IWORK.Decimation = -1;
    heli_q8_DW.ToFile3_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S6>/Rate Transition: x' */
  heli_q8_B.RateTransitionx = heli_q8_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S6>/Rate Transition: y' */
  heli_q8_B.RateTransitiony = heli_q8_P.RateTransitiony_InitialConditio;

  /* Start for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open(heli_q8_P.GameController_ControllerNumber,
        heli_q8_P.GameController_BufferSize, deadzone, saturation,
        heli_q8_P.GameController_AutoCenter, 0, 1.0,
        &heli_q8_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for Memory: '<S5>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput[0],
           &heli_q8_P.Memory_InitialCondition[0], 10U * sizeof(real_T));

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    heli_q8_X.Integrator_CSTATE = heli_q8_P.Integrator_IC;

    /* InitializeConditions for Memory: '<Root>/Memory1' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.Memory1_PreviousInput[i] = heli_q8_P.x0[i];
    }

    /* End of InitializeConditions for Memory: '<Root>/Memory1' */

    /* InitializeConditions for Memory: '<Root>/Memory' */
    memcpy(&heli_q8_DW.Memory_PreviousInput_b[0], &heli_q8_P.P0[0], 36U * sizeof
           (real_T));

    /* InitializeConditions for Memory: '<Root>/Memory2' */
    for (i = 0; i < 6; i++) {
      heli_q8_DW.Memory2_PreviousInput[i] = heli_q8_P.Memory2_InitialCondition[i];
    }

    /* End of InitializeConditions for Memory: '<Root>/Memory2' */

    /* InitializeConditions for TransferFcn: '<S4>/Elevation: Transfer Fcn' */
    heli_q8_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Pitch: Transfer Fcn' */
    heli_q8_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S4>/Travel: Transfer Fcn' */
    heli_q8_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S9>/Integrator' */
    heli_q8_X.Integrator_CSTATE_m = heli_q8_P.Integrator_IC_f;

    /* InitializeConditions for Integrator: '<S9>/Integrator1' */
    heli_q8_X.Integrator1_CSTATE = heli_q8_P.Integrator1_IC;

    /* InitializeConditions for Memory: '<Root>/Memory3' */
    memcpy(&heli_q8_DW.Memory3_PreviousInput[0],
           &heli_q8_P.Memory3_InitialCondition[0], 36U * sizeof(real_T));

    /* InitializeConditions for Integrator: '<S12>/Integrator' */
    heli_q8_X.Integrator_CSTATE_n = heli_q8_P.Integrator_IC_k;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: x' */
    heli_q8_DW.RateTransitionx_Buffer0 =
      heli_q8_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S6>/Rate Transition: y' */
    heli_q8_DW.RateTransitiony_Buffer0 =
      heli_q8_P.RateTransitiony_InitialConditio;
  }
}

/* Model terminate function */
void heli_q8_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_P.HILInitialize_AOTerminate && !is_switching) ||
        (heli_q8_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_q8_P.HILInitialize_POTerminate && !is_switching) ||
        (heli_q8_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_DW.HILInitialize_Card
                         , heli_q8_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , heli_q8_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_DW.HILInitialize_Card,
            heli_q8_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &heli_q8_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_DW.HILInitialize_Card,
            heli_q8_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &heli_q8_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_DW.HILInitialize_Card);
    hil_close(heli_q8_DW.HILInitialize_Card);
    heli_q8_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S5>/Stream Call1' incorporates:
   *  Constant: '<S5>/Constant'
   *  S-Function (string_constant_block): '<S5>/String Constant'
   */

  /* S-Function Block: heli_q8/IMU/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_DW.StreamCall1_Stream);
      heli_q8_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) heli_q8_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] =
        "Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error reopening MAT-file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 14 + 1, heli_q8_DW.ToFile1_IWORK.Count,
           "data_p")) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error writing header for data_p to MAT-file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file Lab_4_case_files\\Encoder_and_estimate_data\\case_1.11.mat");
        return;
      }

      heli_q8_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File2' */
  {
    FILE *fp = (FILE *) heli_q8_DW.ToFile2_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Lab_4_case_files\\Error_data\\case_1.12.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file Lab_4_case_files\\Error_data\\case_1.12.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error reopening MAT-file Lab_4_case_files\\Error_data\\case_1.12.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, heli_q8_DW.ToFile2_IWORK.Count,
           "data_e")) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error writing header for data_e to MAT-file Lab_4_case_files\\Error_data\\case_1.12.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file Lab_4_case_files\\Error_data\\case_1.12.mat");
        return;
      }

      heli_q8_DW.ToFile2_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File3' */
  {
    FILE *fp = (FILE *) heli_q8_DW.ToFile3_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "Lab_4_case_files\\Measurements_data\\case_1.12.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file Lab_4_case_files\\Measurements_data\\case_1.12.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error reopening MAT-file Lab_4_case_files\\Measurements_data\\case_1.12.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1, heli_q8_DW.ToFile3_IWORK.Count,
           "data_y")) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error writing header for data_y to MAT-file Lab_4_case_files\\Measurements_data\\case_1.12.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_M,
                          "Error closing MAT-file Lab_4_case_files\\Measurements_data\\case_1.12.mat");
        return;
      }

      heli_q8_DW.ToFile3_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S6>/Game Controller' */

  /* S-Function Block: heli_q8/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_P.GameController_Enabled) {
      game_controller_close(heli_q8_DW.GameController_Controller);
      heli_q8_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_initialize();
}

void MdlTerminate(void)
{
  heli_q8_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_T *heli_q8(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_q8_P.Integrator_UpperSat = rtInf;
  heli_q8_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)heli_q8_M, 0,
                sizeof(RT_MODEL_heli_q8_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_M->solverInfo, &heli_q8_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_M->solverInfo, &rtmGetTPtr(heli_q8_M));
    rtsiSetStepSizePtr(&heli_q8_M->solverInfo, &heli_q8_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_M->solverInfo, &heli_q8_M->derivs);
    rtsiSetContStatesPtr(&heli_q8_M->solverInfo, (real_T **)
                         &heli_q8_M->contStates);
    rtsiSetNumContStatesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_M->solverInfo,
      &heli_q8_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_M->solverInfo, (&rtmGetErrorStatus(heli_q8_M)));
    rtsiSetRTModelPtr(&heli_q8_M->solverInfo, heli_q8_M);
  }

  rtsiSetSimTimeStep(&heli_q8_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_M->intgData.f[0] = heli_q8_M->odeF[0];
  heli_q8_M->contStates = ((real_T *) &heli_q8_X);
  rtsiSetSolverData(&heli_q8_M->solverInfo, (void *)&heli_q8_M->intgData);
  rtsiSetSolverName(&heli_q8_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_M->Timing.sampleTimes = (&heli_q8_M->Timing.sampleTimesArray[0]);
    heli_q8_M->Timing.offsetTimes = (&heli_q8_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_M, &heli_q8_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_M->Timing.perTaskSampleHitsArray;
    heli_q8_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_M, 50.0);
  heli_q8_M->Timing.stepSize0 = 0.002;
  heli_q8_M->Timing.stepSize1 = 0.002;
  heli_q8_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_M->Sizes.checksums[0] = (3598684260U);
  heli_q8_M->Sizes.checksums[1] = (3215875958U);
  heli_q8_M->Sizes.checksums[2] = (2381142082U);
  heli_q8_M->Sizes.checksums[3] = (3933999560U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    heli_q8_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_M->extModeInfo,
      &heli_q8_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_M->extModeInfo, heli_q8_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_M->extModeInfo, rtmGetTPtr(heli_q8_M));
  }

  heli_q8_M->solverInfoPtr = (&heli_q8_M->solverInfo);
  heli_q8_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_M->blockIO = ((void *) &heli_q8_B);
  (void) memset(((void *) &heli_q8_B), 0,
                sizeof(B_heli_q8_T));

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.Memory1[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.Memory[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.Memory2[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.Switch_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.TmpSignalConversionAtToFile3Inp[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.Memory3[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.Switch1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      heli_q8_B.x_pri[i] = 0.0;
    }

    for (i = 0; i < 36; i++) {
      heli_q8_B.P_pri[i] = 0.0;
    }

    heli_q8_B.Gain2[0] = 0.0;
    heli_q8_B.Gain2[1] = 0.0;
    heli_q8_B.Gain2[2] = 0.0;
    heli_q8_B.ElevationCounttorad = 0.0;
    heli_q8_B.Sum = 0.0;
    heli_q8_B.Sum1[0] = 0.0;
    heli_q8_B.Sum1[1] = 0.0;
    heli_q8_B.Sum3[0] = 0.0;
    heli_q8_B.Sum3[1] = 0.0;
    heli_q8_B.Sum3[2] = 0.0;
    heli_q8_B.Integrator = 0.0;
    heli_q8_B.ManualSwitch = 0.0;
    heli_q8_B.Sum7 = 0.0;
    heli_q8_B.ElevationTransferFcn = 0.0;
    heli_q8_B.Sum8 = 0.0;
    heli_q8_B.PitchCounttorad = 0.0;
    heli_q8_B.Sum5 = 0.0;
    heli_q8_B.PitchTransferFcn = 0.0;
    heli_q8_B.Sum6 = 0.0;
    heli_q8_B.TravelCounttorad = 0.0;
    heli_q8_B.TravelTransferFcn = 0.0;
    heli_q8_B.Gain = 0.0;
    heli_q8_B.Gain1 = 0.0;
    heli_q8_B.Sum9 = 0.0;
    heli_q8_B.Sum10 = 0.0;
    heli_q8_B.FrontmotorSaturation = 0.0;
    heli_q8_B.BackmotorSaturation = 0.0;
    heli_q8_B.Sum7_h = 0.0;
    heli_q8_B.Sum8_p = 0.0;
    heli_q8_B.K_ei = 0.0;
    heli_q8_B.RateTransitionx = 0.0;
    heli_q8_B.Joystick_gain_x = 0.0;
    heli_q8_B.RateTransitiony = 0.0;
    heli_q8_B.Joystick_gain_y = 0.0;
  }

  /* parameters */
  heli_q8_M->defaultParam = ((real_T *)&heli_q8_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_X;
    heli_q8_M->contStates = (x);
    (void) memset((void *)&heli_q8_X, 0,
                  sizeof(X_heli_q8_T));
  }

  /* states (dwork) */
  heli_q8_M->dwork = ((void *) &heli_q8_DW);
  (void) memset((void *)&heli_q8_DW, 0,
                sizeof(DW_heli_q8_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_DW.Memory1_PreviousInput[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_DW.Memory_PreviousInput_b[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++) {
      heli_q8_DW.Memory2_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_DW.HILWriteAnalog_Buffer[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 36; i++) {
      heli_q8_DW.Memory3_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_DW.RateTransitiony_Buffer0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_M->Sizes.numContStates = (7);/* Number of continuous states */
  heli_q8_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_q8_M->Sizes.numY = (0);         /* Number of model outputs */
  heli_q8_M->Sizes.numU = (0);         /* Number of model inputs */
  heli_q8_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_M->Sizes.numSampTimes = (3); /* Number of sample times */
  heli_q8_M->Sizes.numBlocks = (127);  /* Number of blocks */
  heli_q8_M->Sizes.numBlockIO = (40);  /* Number of block outputs */
  heli_q8_M->Sizes.numBlockPrms = (678);/* Sum of parameter "widths" */
  return heli_q8_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
