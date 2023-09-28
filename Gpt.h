#ifndef GPT_H_
#define GPT_H_

/************************************************
 *  GPT Configuration Options
 ***********************************************/
#define GPT_OFF 0
#define GPT_ON  1

#define GPT_WAVEFORM_MODE_NORMAL 1
#define GPT_WAVEFORM_MODE_CTC    2

#define GPT_COMPARE_OUTPUT_MODE_DISCONNECTED 1
#define GPT_COMPARE_OUTPUT_MODE_TOGGLE       2
#define GPT_COMPARE_OUTPUT_MODE_CLR          3
#define GPT_COMPARE_OUTPUT_MODE_GET          4

#define GPT_CLK_OFF 				  1
#define GPT_CLK_PRESCALER_1 		  2
#define GPT_CLK_PRESCALER_8 		  3
#define GPT_CLK_PRESCALER_32 		  4
#define GPT_CLK_PRESCALER_64 		  5
#define GPT_CLK_PRESCALER_128 		  6
#define GPT_CLK_PRESCALER_256 		  7
#define GPT_CLK_PRESCALER_1024 		  8
#define GPT_CLK_PRESCALER_EXT_FALLING 9
#define GPT_CLK_PRESCALER_EXT_RISING  10

/*************************************************
 * Options
 *************************************************
 *
 *--> Options For WAVEFORM_MODE:
 *		GPT_WAVEFORM_MODE_NORMAL
 *		GPT_WAVEFORM_MODE_CTC
 *
 *--> Options For COMPARE_OUTPUT_MODE:
 *		GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
 *		GPT_COMPARE_OUTPUT_MODE_TOGGLE
 *		GPT_COMPARE_OUTPUT_MODE_CLR
 *		GPT_COMPARE_OUTPUT_MODE_GET
 *
 *	--> Options For CLK:
 *		GPT_CLK_OFF
 *		GPT_CLK_PRESCALER_1
 *		GPT_CLK_PRESCALER_8
 *		GPT_CLK_PRESCALER_32
 *		GPT_CLK_PRESCALER_64
 *		GPT_CLK_PRESCALER_128
 *		GPT_CLK_PRESCALER_256
 *		GPT_CLK_PRESCALER_1024
 *		GPT_CLK_PRESCALER_EXT_FALLING
 *		GPT_CLK_PRESCALER_EXT_RISING
 */

/************************************************
 *  Configuration
 ***********************************************/

#define GPT_TIM0_STATUS GPT_ON
#if GPT_TIM0_STATUS == GPT_ON
#define GPT_TIM0_WAVEMODE_MODE 		 GPT_WAVEFORM_MODE_CTC
#define GPT_TIM0_COMPARE_OUTPUT_MODE GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
#define GPT_TIM0_CLK				 GPT_CLK_PRESCALER_1024
#endif

#define GPT_TIM1_STATUS GPT_OFF
#if GPT_TIM1_STATUS == GPT_ON
#define GPT_TIM1_WAVEMODE_MODE 		 GPT_WAVEFORM_MODE_CTC
#define GPT_TIM1_COMPARE_OUTPUT_MODE GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
#define GPT_TIM1_CLK				 GPT_CLK_PRESCALER_64
#endif

#define GPT_TIM2_STATUS GPT_OFF
#if GPT_TIM2_STATUS == GPT_ON
#define GPT_TIM2_WAVEMODE_MODE 		 GPT_WAVEFORM_MODE_CTC
#define GPT_TIM2_COMPARE_OUTPUT_MODE GPT_COMPARE_OUTPUT_MODE_DISCONNECTED
#define GPT_TIM2_CLK				 GPT_CLK_PRESCALER_64
#endif

/************************************************/

typedef enum
{
	GPT_INT_SOURCE_TIM0_OV,
	GPT_INT_SOURCE_TIM0_COMP,
	GPT_INT_SOURCE_TIM1_ON,
	GPT_INT_SOURCE_TIM1A_COMP,
	GPT_INT_SOURCE_TIM1B_COMP,
	GPT_INT_SOURCE_TIM2_OV,
	GPT_INT_SOURCE_TIM2_COMP,
}Gpt_InterruptSourceType;

void Gpt_Init(void);
void Gpt_EnableNotification (Gpt_InterruptSourceType channel);
void Gpt_DisableNotification (Gpt_InterruptSourceType channel);

#endif

