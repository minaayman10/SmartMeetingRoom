#ifndef EXINTERRUPT_H_
#define EXINTERRUPT_H_


/****************** ExtInterrupt Configration ******************/

/***************************************************************
* OPTIONS
* -> EXTERNAL_INTERRUPT_RISING
* -> EXTERNAL_INTERRUPT_FALLING
* -> EXTERNAL_INTERRUPT_ONCHANGE
* -> EXTERNAL_INTERRUPT_LOW_LEVEL
* -> EXTERNAL_INTERRUPT_OFF
*/
#define EXTERNAL_INTERRUPT_INT0_STATUS EXTERNAL_INTERRUPT_RISING

/***************************************************************
* OPTIONS
* -> EXTERNAL_INTERRUPT_RISING
* -> EXTERNAL_INTERRUPT_FALLING
* -> EXTERNAL_INTERRUPT_ONCHANGE
* -> EXTERNAL_INTERRUPT_LOW_LEVEL
* -> EXTERNAL_INTERRUPT_OFF
*/
#define EXTERNAL_INTERRUPT_INT1_STATUS EXTERNAL_INTERRUPT_RISING

/***************************************************************
* OPTIONS
* -> EXTERNAL_INTERRUPT_RISING
* -> EXTERNAL_INTERRUPT_FALLING
* -> EXTERNAL_INTERRUPT_ONCHANGE
* -> EXTERNAL_INTERRUPT_LOW_LEVEL
* -> EXTERNAL_INTERRUPT_OFF
*/
#define EXTERNAL_INTERRUPT_INT2_STATUS EXTERNAL_INTERRUPT_OFF

/***************************************************************/

typedef enum{
	EXT_INTERRUPT_INT0,
	EXT_INTERRUPT_INT1,
	EXT_INTERRUPT_INT2,
	EXT_INTERRUPT_ADC1
}ExtInterrupt_ChannelType;

typedef enum{
	EXT_INTERRUPT_DETECT_FALLING,
	EXT_INTERRUPT_DETECT_RISING,
	EXT_INTERRUPT_DETECT_ONCHANGE,
	EXT_INTERRUPT_DETECT_LOW,
}ExtInterrupt_EdgeType;

void ExtInerrupt_Init(void);
void ExtInerrupt_EnableNotification (ExtInterrupt_ChannelType channel);
void ExtInerrupt_DisableNotification (ExtInterrupt_ChannelType channel);
void ExtInerrupt_SetDetectEdge (ExtInterrupt_ChannelType channel, ExtInterrupt_EdgeType edge);

#endif EXINTERRUPT_H_
