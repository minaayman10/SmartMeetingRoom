#include "avr/io.h"
#include "avr/interrupt.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Gpt.h"

void Gpt_Init(void)
{
/**************************************************
 * Timer 0 Init
 **************************************************/
#if GPT_TIM0_STATUS == GPT_ON

/* Waveform Generation Mode */
#if GPT_TIM0_WAVEMODE_MODE == GPT_WAVEFORM_MODE_NORMAL
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
#elif GPT_TIM0_WAVEMODE_MODE == GPT_WAVEFORM_MODE_CTC
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
#else
#error "Invalid WAVEFORM_MODE for TIM0"
#endif

/* Compare Match Output Mode */
#if GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
	CLR_BIT(TCCR0, COM00);
	CLR_BIT(TCCR0, COM01);
#elif GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_TOGGLE
	//TODO
#elif GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_CLR
	//TODO
#elif GPT_TIM0_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_GET
	//TODO
#else
#error "Invalid COMPARE_OUTPUT_MODE for TIM0"
#endif

/* Clock Select */
#if GPT_TIM0_CLK == GPT_CLK_OFF

#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_1

#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_8
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_64
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_256
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_1024

#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_EXT_FALLING

#elif GPT_TIM0_CLK == GPT_CLK_PRESCALER_EXT_RISING

#else
#error "Invalid Configuration for TIM0_CLK in TIM0"
#endif

#endif
/**************************************************
 * Timer 1 Init
 **************************************************/
#if GPT_TIM1_STATUS == GPT_ON

/* Waveform Generation Mode */
#if GPT_TIM1_WAVEMODE_MODE == GPT_WAVEFORM_MODE_NORMAL

#elif GPT_TIM1_WAVEMODE_MODE == GPT_WAVEFORM_MODE_CTC

#else
#error "Invalid WAVEFORM_MODE for TIM1"
#endif

/* Compare Match Output Mode */
#if GPT_TIM1_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_DISCONNECTED

#elif GPT_TIM1_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_TOGGLE
	//TODO
#elif GPT_TIM1_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_CLR
	//TODO
#elif GPT_TIM1_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_GET
	//TODO
#else
#error "Invalid COMPARE_OUTPUT_MODE for TIM1"
#endif

/* Clock Select */
#if GPT_TIM1_CLK == GPT_CLK_OFF

#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_1

#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_8

#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_64

#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_256

#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_1024

#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_EXT_FALLING

#elif GPT_TIM1_CLK == GPT_CLK_PRESCALER_EXT_RISING

#else
#error "Invalid Configuration for TIM1_CLK in TIM1"
#endif

#endif

/**************************************************
 * Timer 2 Init
 **************************************************/
#if GPT_TIM2_STATUS == GPT_ON

/* Waveform Generation Mode */
#if GPT_TIM2_WAVEMODE_MODE == GPT_WAVEFORM_MODE_NORMAL

#elif GPT_TIM2_WAVEMODE_MODE == GPT_WAVEFORM_MODE_CTC

#else
#error "Invalid WAVEFORM_MODE for TIM2"
#endif

/* Compare Match Output Mode */
#if GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_DISCONNECTED

#elif GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_TOGGLE
	//TODO
#elif GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_CLR
	//TODO
#elif GPT_TIM2_COMPARE_OUTPUT_MODE == GPT_COMPARE_OUTPUT_MODE_GET
	//TODO
#else
#error "Invalid COMPARE_OUTPUT_MODE for TIM2"
#endif

/* Clock Select */
#if GPT_TIM2_CLK == GPT_CLK_OFF

#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_1

#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_8

#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_64

#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_256

#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_1024

#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_EXT_FALLING

#elif GPT_TIM2_CLK == GPT_CLK_PRESCALER_EXT_RISING

#else
#error "Invalid Configuration for TIM1_CLK in TIM1"
#endif

#endif
}

void Gpt_EnableNotification (Gpt_InterruptSourceType channel)
{
	switch (channel)
	{
	case GPT_INT_SOURCE_TIM0_OV:
		SET_BIT(TIMSK, TOIE0);
		break;

	case GPT_INT_SOURCE_TIM0_COMP:
		SET_BIT(TIMSK, OCIE0);
		break;

	case GPT_INT_SOURCE_TIM1_ON:

		break;

	case GPT_INT_SOURCE_TIM1A_COMP:

		break;

	case GPT_INT_SOURCE_TIM1B_COMP:

		break;

	case GPT_INT_SOURCE_TIM2_OV:

		break;

	case GPT_INT_SOURCE_TIM2_COMP:

		break;

	default:
		break;
	}
}

void Gpt_DisableNotification (Gpt_InterruptSourceType channel)
{
	switch (channel)
	{
	case GPT_INT_SOURCE_TIM0_OV:
		CLR_BIT(TIMSK, TOIE0);
		break;

	case GPT_INT_SOURCE_TIM0_COMP:
		CLR_BIT(TIMSK, OCIE0);
		break;

	case GPT_INT_SOURCE_TIM1_ON:

		break;

	case GPT_INT_SOURCE_TIM1A_COMP:

		break;

	case GPT_INT_SOURCE_TIM1B_COMP:

		break;

	case GPT_INT_SOURCE_TIM2_OV:

		break;

	case GPT_INT_SOURCE_TIM2_COMP:

		break;

	default:
		break;
	}
}

