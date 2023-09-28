
#include "avr/io.h"
#include "avr/delay.h"
#include "avr/interrupt.h"
#define F_CPU 8000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio.h"
#include "Functions.h"

#include "Lcd.h"
#include "Keypad.h"
#include "LM35.h"
#include "ADC.h"
#include "LM35.h"
#include "ExInterrupt.h"
#include "Wdt.h"
/******************************************************************************/
/*     Admin can set the password of the meeting room     */

/* GO TO Functions.c  */

/******************************************************************************/
void main(void)
{

	/* Drivers Initialization */


	Keypad_Init();
	Lcd_InitPins();
	Lcd_Init();
    ADC_Init();
    ExtInerrupt_Init();
    ExtInerrupt_EnableNotification(EXT_INTERRUPT_INT0);
 	sei();

    /*******************************************/

    /* Setting Pins as an output for  the Door , Lights , AC , Fire system  */

    /* DOOR Pins C0:C4 */
    Dio_SetPinMode(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
    Dio_SetPinMode(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
    Dio_SetPinMode(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
    Dio_SetPinMode(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);

    /* Lights Pin A2 */
    Dio_SetPinMode(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);

    /* AC Pin A3 */
    Dio_SetPinMode(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);

    /* Fire System Pin A7 */
    Dio_SetPinMode(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);



    /*****************************************************/

    /* Define the Variables */

    u8 AC_TEMP = 0 ;
    u8 FS_TEMP = 0 ;


    /*********************************************************/


	/* Start the Program*/

    Welcome();
   _delay_ms(1000);
   StartUpPassword();
    _delay_ms(1000);
    Lcd_Clear();

    while(1)
    {
	  /* Opening The Door, Lights and AC */

	 /* DOOR is Open */
    Dio_SetPinLevel(DIO_PORTC,DIO_PIN0,STD_HIGH);


    /* Lights are Open */
    Dio_SetPinLevel(DIO_PORTA,DIO_PIN2,STD_HIGH);


    /* Read the AC_temp from the sensor1 */
    AC_TEMP=LM35_TempRead(0);
    Lcd_DisplayString("the temp is ");
    Lcd_DisplayNumber(AC_TEMP);
    _delay_ms(200);
    Lcd_Clear();

    /* Check if the temp. is above 24 to ON the AC or if the temp. is below 20 to off the AC */

    if (AC_TEMP >= 20)
    {
        Dio_SetPinLevel(DIO_PORTA,DIO_PIN3,STD_HIGH);
    }
    else
    { Dio_SetPinLevel(DIO_PORTA,DIO_PIN3,STD_LOW);}

     /* Read the FS_temp from Sensor2  */
    FS_TEMP = LM35_TempRead(1);


    /* Check if there is fire to on the fire system*/
    if (FS_TEMP >= 80)
    {
    	// start fire alrm
    	Dio_SetPinLevel(DIO_PORTA,DIO_PIN7,STD_HIGH);


    	//turn off air conditioner
    	Dio_TogglePinLevel(DIO_PORTA,DIO_PIN3);

    }
    else {Dio_SetPinLevel(DIO_PORTA,DIO_PIN7,STD_LOW);}


    }

}
/********************************************************************************/
/*ISR(INT0_vect)
{

}


/******************************************************************************/










