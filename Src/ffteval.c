/* ffteval.c
	
	Encapsulated function for fft evaluation
*/

#include "ffteval.h"
#include "FFT_test1.inc"

/*
const uint32_t FFT_SIZE = 256;
unsigned char *fft_input = FFT_test1_raw;
arm_rfft_instance_q15 fft_instance;
q15_t *fft_output;
arm_status fft_status;
*/

//extern uint32_t FFT_SIZE;

q15_t* FFT_Test(FFT_HandleTypeDef *handle)
{
	//handle->FFT_SIZE = 256;
	handle->fft_input = FFT_test1_raw;
	
	handle->fft_status = arm_rfft_init_q15(&(handle->fft_instance), FFT_SIZE, 0, 1);
	arm_rfft_q15(&(handle->fft_instance), (q15_t*)handle->fft_input, handle->fft_output);
	arm_abs_q15(handle->fft_output, handle->fft_output, FFT_SIZE);

	return handle->fft_output;
}
