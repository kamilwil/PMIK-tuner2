/**
  ******************************************************************************
  * @file           : ffteval.h
  * @brief          : Header file for FFT evaluation
  ******************************************************************************
  */

#ifndef FFTEVAL_H_
#define FFTEVAL_H_

#define FFT_SIZE 256

#include "stm32f3xx_hal.h"
#include "arm_math.h"

/**
 * Structure containing all necessary data for FFT evaluation
 */
typedef struct{
	q15_t* fft_input; /*!< Input vector (either from testfile or from DMA output buffer */
	arm_rfft_instance_q15 fft_instance; /*!< Data block necessary for computations */
	q15_t fft_output[FFT_SIZE*2]; /*!< Output vector which is later researched for maximum value */
	arm_status fft_status; /*!< Operation status */
}FFT_HandleTypeDef;

q15_t* FFT_Test(FFT_HandleTypeDef*);
q15_t* FFT_Eval(FFT_HandleTypeDef*, uint16_t*);

#endif // FFTEVAL_H_
