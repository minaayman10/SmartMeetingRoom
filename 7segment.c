#include "avr/io.h"
#include "avr/delay.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Dio.h"
#include "7segment.h"

void Segment_InitPins(void)
{
	DDR_7_SEGMENT = 0xFF;
}

void Segment_SetNumber (u8 Number)
{
	switch(Number){
    	case 0:
    		PORT_7_SEGMENT=0b0111111;
    		break;

    	case 1:
    		PORT_7_SEGMENT=0b0000110;
    		break;

    	case 2:
    		PORT_7_SEGMENT=0b1011011;
    		break;

    	case 3:
    		PORT_7_SEGMENT=0b1001111;
    		break;

    	case 4:
    		PORT_7_SEGMENT=0b1100110;
    		break;

    	case 5:
    		PORT_7_SEGMENT=0b1101101;
    		break;

    	case 6:
    		PORT_7_SEGMENT=0b1111101;
    		break;

    	case 7:
    		PORT_7_SEGMENT=0b0000111;
    		break;

    	case 8:
    		PORT_7_SEGMENT=0b1111111;
    		break;

    	case 9:
    		PORT_7_SEGMENT=0b1101111;
    		break;

    	default:
    		break;
	}
}

void Segment_Clear(void)
{
	PORT_7_SEGMENT=0;
}
