#include "STD_TYPES.h"
#include "avr/delay.h"
#include "BIT_MATH.h"

#include "Dio.h"
#include "Lcd.h"

void Lcd_SendCommand (u8 command)
{
	/*Set RS ping to low for command*/
	Dio_SetPinLevel(LCD_PIN_RS , STD_LOW);
	/*Set RW ping to low for Write*/
	Dio_SetPinLevel(LCD_PIN_RW , STD_LOW);

	/*Set command to data pins*/
	Dio_SetPinLevel(LCD_PIN_D0 , GET_BIT(command, 0));
	Dio_SetPinLevel(LCD_PIN_D1 , GET_BIT(command, 1));
	Dio_SetPinLevel(LCD_PIN_D2 , GET_BIT(command, 2));
	Dio_SetPinLevel(LCD_PIN_D3 , GET_BIT(command, 3));
	Dio_SetPinLevel(LCD_PIN_D4 , GET_BIT(command, 4));
	Dio_SetPinLevel(LCD_PIN_D5 , GET_BIT(command, 5));
	Dio_SetPinLevel(LCD_PIN_D6 , GET_BIT(command, 6));
	Dio_SetPinLevel(LCD_PIN_D7 , GET_BIT(command, 7));

	/*Send enable pulse*/
	Dio_SetPinLevel(LCD_PIN_EN , STD_HIGH);
	_delay_ms(2);
	Dio_SetPinLevel(LCD_PIN_EN , STD_LOW);
}

void Lcd_SendData (u8 command)
{
	/*Set RS ping to High for Data*/
	Dio_SetPinLevel(LCD_PIN_RS , STD_HIGH);
	/*Set RW ping to low for Write*/
	Dio_SetPinLevel(LCD_PIN_RW , STD_LOW);

	/*Set command to data pins*/
	Dio_SetPinLevel(LCD_PIN_D0 , GET_BIT(command, 0));
	Dio_SetPinLevel(LCD_PIN_D1 , GET_BIT(command, 1));
	Dio_SetPinLevel(LCD_PIN_D2 , GET_BIT(command, 2));
	Dio_SetPinLevel(LCD_PIN_D3 , GET_BIT(command, 3));
	Dio_SetPinLevel(LCD_PIN_D4 , GET_BIT(command, 4));
	Dio_SetPinLevel(LCD_PIN_D5 , GET_BIT(command, 5));
	Dio_SetPinLevel(LCD_PIN_D6 , GET_BIT(command, 6));
	Dio_SetPinLevel(LCD_PIN_D7 , GET_BIT(command, 7));

	/*Send enable pulse*/
	Dio_SetPinLevel(LCD_PIN_EN , STD_HIGH);
	_delay_ms(2);
	Dio_SetPinLevel(LCD_PIN_EN , STD_LOW);
}

void Lcd_InitPins(void)
{
	Dio_SetPinMode(LCD_PIN_RS, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_RW, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_EN, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D0, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D1, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D2, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D3, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D4, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D5, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D6, DIO_PIN_OUTPUT);
	Dio_SetPinMode(LCD_PIN_D7, DIO_PIN_OUTPUT);
}

void Lcd_Init(void)
{
	_delay_ms(30);

	/*Function set command : 2lines, 5*8 Font size*/
	Lcd_SendCommand (0b00111000);

	/*Display on off control : DISPLAY enable, disable cursor, no blink cursor*/
	Lcd_SendCommand (0b00001100);

	/* Clear display */
	Lcd_SendCommand (0b00000001);

}

void Lcd_DisplayString(const u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
	 Lcd_SendData(str[i]);
	 i++;
	}
}

void Lcd_DisplayNumber(u32 Number)
{
	u32 Local_Number = 1;
	if (Number == 0)
	{
		Lcd_SendData('0');
	}
	while(Number != 0)
	{
		Local_Number = ((Local_Number * 10) + (Number % 10));
		Number = Number/10;
	}
	while(Local_Number != 1)
	{
		Lcd_SendData((Local_Number % 10) + 48 );
		Local_Number = Local_Number / 10;
	}
}

void GotoXY(u8 X,u8 Y)
{
	u8 LocalAddress;

	if (X == 1)
	{
		LocalAddress = Y;
	}
	else if (X == 2)
	{
		LocalAddress = Y + 0x40;
	}

	Lcd_SendCommand(LocalAddress |= 0b10000000);
}

void Lcd_Clear(void)
{
	Lcd_SendCommand (0b00000001);
}



