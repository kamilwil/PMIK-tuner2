/*
	ffteval.h
	
	Header file for FFT evaluation
*/

#ifndef FFTEVAL_H_
#define FFTEVAL_H_

#define FFT_SIZE 256

#include "stm32f3xx_hal.h"
#include "arm_math.h"

//uint32_t FFT_SIZE = 256;

typedef struct{
	//FFT_SIZE was here
	unsigned char *fft_input;
	arm_rfft_instance_q15 fft_instance;
	q15_t fft_output[FFT_SIZE*2];
	arm_status fft_status;
}FFT_HandleTypeDef;

q15_t* FFT_Test(FFT_HandleTypeDef*);


#endif // FFTEVAL_H_
