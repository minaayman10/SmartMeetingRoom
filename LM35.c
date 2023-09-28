#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Adc.h"
#include "LM35.h"

u8 LM35_TempRead(u8 channel)
{
	u8 value = ADC_Read(channel);

	// Convert ADC value to millivolts
	u16 millivolt = (u16)(((u32)value*5000) / 255);

	// Round millivolts to the nearest integer
	u8 Temp = (u8)round(millivolt / 10);

	return Temp;
}
