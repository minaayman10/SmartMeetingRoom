/*
 * ADC.c
 *
 *  Created on: Aug 21, 2023
 *      Author: MUTASEM ELSHAZLY
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC.h"





void ADC_Init(void)
{
	//prescaler config as 128 from rsg ADCSRA PINS ADPS0,1,2
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);

	//REFERANC VOLTAGE s AVCC reg  ADMUX pins(7,6) REFS1,0
	SET_BIT(ADMUX,REFS0);
	CLR_BIT(ADMUX,REFS1);

	//ADC DATA Right adjeustem PIN(5)
	SET_BIT(ADMUX,ADLAR);

	//Enable ADC
	SET_BIT(ADCSRA,ADEN);

}

u8 ADC_Read(u8 channel)
{
	//ADC channal selection
	channel &=0b00000111;
	ADMUX &=  0b11100000;
	ADMUX|=channel;

	//Start single conversion by reg ADCSRA
	SET_BIT(ADCSRA,ADSC);

	//wait for conversion UNTIL FLAGE =0
	while(GET_BIT(ADCSRA,ADIF)!=1);
	//set flage =1 agine
	SET_BIT(ADCSRA,ADIF);

	return ADCH;
}

