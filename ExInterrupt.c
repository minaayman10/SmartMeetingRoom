#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"
#include "avr/interrupt.h"
#include "ExInterrupt.h"

void ExtInerrupt_Init(void)
{
	#if (EXTERNAL_INTERRUPT_INT0_STATUS == EXTERNAL_INTERRUPT_FALLING)
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
	#elif (EXTERNAL_INTERRUPT_INT0_STATUS == EXTERNAL_INTERRUPT_RISING)
		SET_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
	#elif (EXTERNAL_INTERRUPT_INT0_STATUS == EXTERNAL_INTERRUPT_ONCHANGE)
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
	#elif (EXTERNAL_INTERRUPT_INT0_STATUS == EXTERNAL_INTERRUPT_LOW_LEVEL)
		CLR_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
	#elif (EXTERNAL_INTERRUPT_INT0_STATUS == EXTERNAL_INTERRUPT_OFF)

	#else
	#error "Invalid Sense Control for INT0 "
	#endif

	#if (EXTERNAL_INTERRUPT_INT1_STATUS == EXTERNAL_INTERRUPT_FALLING)
		CLR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
	#elif (EXTERNAL_INTERRUPT_INT1_STATUS == EXTERNAL_INTERRUPT_RISING)
		SET_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
	#elif (EXTERNAL_INTERRUPT_INT1_STATUS == EXTERNAL_INTERRUPT_ONCHANGE)
		SET_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
	#elif (EXTERNAL_INTERRUPT_INT1_STATUS == EXTERNAL_INTERRUPT_LOW_LEVEL)
		CLR_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
	#elif (EXTERNAL_INTERRUPT_INT1_STATUS == EXTERNAL_INTERRUPT_OFF)

	#else
	#error "Invalid Sense Control for INT1 "
	#endif

	#if (EXTERNAL_INTERRUPT_INT2_STATUS == EXTERNAL_INTERRUPT_FALLING)
		//todo
	#elif (EXTERNAL_INTERRUPT_INT2_STATUS == EXTERNAL_INTERRUPT_RISING)
		//todo
	#elif (EXTERNAL_INTERRUPT_INT2_STATUS == EXTERNAL_INTERRUPT_OFF)

	#else
	#error "Invalid Sense Control for INT2 "
	#endif
}

void ExtInerrupt_EnableNotification(ExtInterrupt_ChannelType channel)
{
	switch(channel)
	{
	case EXT_INTERRUPT_INT0:
		SET_BIT(GICR, INT0);
		break;
	case EXT_INTERRUPT_INT1:
		SET_BIT(GICR, INT1);
		break;
	case EXT_INTERRUPT_INT2:
		SET_BIT(GICR, INT2);
		break;
	case EXT_INTERRUPT_ADC1:
		SET_BIT(ADCSRA, ADIE);


	default:
		break;
	}
}

void ExtInerrupt_DisableNotification(ExtInterrupt_ChannelType channel)
{
	switch(channel)
	{
	case EXT_INTERRUPT_INT0:
		CLR_BIT(GICR, INT0);
		break;
	case EXT_INTERRUPT_INT1:
		CLR_BIT(GICR, INT1);
		break;
	case EXT_INTERRUPT_INT2:
		CLR_BIT(GICR, INT2);

		break;
	default:
		break;
	}
}

void ExtInerrupt_SetDetectEdge (ExtInterrupt_ChannelType channel, ExtInterrupt_EdgeType edge)
{
	switch(channel)
	{
	case EXT_INTERRUPT_INT0:
		switch(edge)
		{
		case EXT_INTERRUPT_DETECT_FALLING:
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXT_INTERRUPT_DETECT_RISING:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXT_INTERRUPT_DETECT_ONCHANGE:
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		case EXT_INTERRUPT_DETECT_LOW:
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;

		default:
			break;
		}
		break;
	case EXT_INTERRUPT_INT1:
		switch(edge)
		{
		case EXT_INTERRUPT_DETECT_FALLING:
			CLR_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXT_INTERRUPT_DETECT_RISING:
			SET_BIT(MCUCR, ISC00);
			SET_BIT(MCUCR, ISC01);
			break;
		case EXT_INTERRUPT_DETECT_ONCHANGE:
			SET_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;
		case EXT_INTERRUPT_DETECT_LOW:
			CLR_BIT(MCUCR, ISC00);
			CLR_BIT(MCUCR, ISC01);
			break;

		default:
			break;
		}
		break;
	case EXT_INTERRUPT_INT2:
		switch(edge)
		{
		case EXT_INTERRUPT_DETECT_FALLING:
			//todo
			break;
		case EXT_INTERRUPT_DETECT_RISING:
			//todo
			break;

		default:
			break;
		}
		break;

	default:
		break;
	}
}









