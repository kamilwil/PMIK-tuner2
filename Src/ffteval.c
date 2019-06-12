/**
  ******************************************************************************
  * @file           : ffteval.c
  * @brief          : Encapsulated function for FFT evaluation.
  ******************************************************************************
  */

#include "ffteval.h"
#include "FFT_test2.inc"

/**
 * Function evaluating FFT based on input from test file. CMSIS DSP CFFT Q15 algotrithm is used.
 */
q15_t* FFT_Test(FFT_HandleTypeDef* handle)
{
	uint16_t index = 0;
	for (index = 0; index < FFT_SIZE*2; ++index)
	{
		handle->fft_output[index] = 0;
	}
	handle->fft_input = (q15_t*) FFT_test2_raw;

	handle->fft_status = arm_rfft_init_q15(&(handle->fft_instance), FFT_SIZE, 0, 1);
	arm_rfft_q15(&(handle->fft_instance), handle->fft_input, handle->fft_output);
	arm_abs_q15(handle->fft_output, handle->fft_output, FFT_SIZE);

	return handle->fft_output;
}

/**
 * Function evaluating FFT based on input vector of FFT_SIZE*2 samples. CMSIS DSP CFFT Q15 algotrithm is used.
 */
q15_t* FFT_Eval(FFT_HandleTypeDef *handle, uint16_t* val)
{
	uint16_t index = 0;
	for (index = 0; index < FFT_SIZE*2; ++index)
	{
		handle->fft_output[index] = 0;
	}
	handle->fft_input = (q15_t*) val;

	handle->fft_status = arm_rfft_init_q15(&(handle->fft_instance), FFT_SIZE, 0, 1);
	arm_rfft_q15(&(handle->fft_instance), handle->fft_input, handle->fft_output);
	arm_abs_q15(handle->fft_output, handle->fft_output, FFT_SIZE);

	return handle->fft_output;
}
