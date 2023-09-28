/*
 * ADC.h
 *
 *  Created on: Aug 21, 2023
 *      Author: MUTASEM ELSHAZLY
 */

#ifndef ADC_H_
#define ADC_H_

#define ADC_CHANNEL0  0
#define ADC_CHANNEL1  1
#define ADC_CHANNEL2  2
#define ADC_CHANNEL3  3
#define ADC_CHANNEL4  4
#define ADC_CHANNEL5  5
#define ADC_CHANNEL6  6
#define ADC_CHANNEL7  7

void ADC_Init(void);
u8 ADC_Read(u8 channel);

#endif /* ADC_H_ */
