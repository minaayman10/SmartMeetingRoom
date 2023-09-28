#include "avr/io.h"
#include "avr/delay.h"
#define F_CPU 8000000

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio.h"

#include "Lcd.h"
#include "Keypad.h"
#include "Functions.h"
#include "Wdt.h"

char *Pass = "8520";
char Local_Pass[4];
u8 Pass_Counter = 0;
u8 attempts_Counter=3;
u8 y=0;




void Welcome(void)
{
		GotoXY(1,0);
		_delay_ms(100);
		Lcd_DisplayString("Welcome <3");
}

void StartUpPassword(void)
{
	Lcd_Clear();
	GotoXY(1,0);
	_delay_ms(100);
	Lcd_DisplayString("Enter Password ");
	u8 Button_pressed = 255 ;

	while(Pass_Counter<4)
	{
		Button_pressed = Keypad_GetPressedButton();
		switch(Button_pressed)
		{
			case 0:
			Local_Pass[Pass_Counter]= '7' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(7);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 1:
			Local_Pass[Pass_Counter]= '8' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(8);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 2:
			Local_Pass[Pass_Counter]= '9' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(9);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 4:
			Local_Pass[Pass_Counter]= '4' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(4);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 5:
			Local_Pass[Pass_Counter]= '5' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(5);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 6:
			Local_Pass[Pass_Counter]= '6' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(6);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 8:
			Local_Pass[Pass_Counter]= '1' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(1);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 9:
			Local_Pass[Pass_Counter]= '2' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(2);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 10:
			Local_Pass[Pass_Counter]= '3' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(3);
			Pass_Counter++;
			_delay_ms(500);
			break;

			case 13:
			Local_Pass[Pass_Counter]= '0' ;
			GotoXY(2,y++);
			Lcd_DisplayNumber(0);
			Pass_Counter++;
			_delay_ms(500);
			break;

			default:
			break;
		}
	}
	CheckPassword();
}

u8 CheckPassword(void)
{
	u8 Flag = 0;

	for(u8 i=0;i<4;i++)
	{
		if(Pass[i]!=Local_Pass[i])
		{
			Flag=1;
		}
		else;
	}
	if (Flag == 0) AccessUser();
	else
	{
		if(attempts_Counter>0)
		{
		Pass_Counter=0; y=0;
		GotoXY(1,0);
		_delay_ms(100);
		Lcd_DisplayString("Wrong Password");
		GotoXY(2,0);
		Lcd_DisplayNumber(attempts_Counter);
		Lcd_DisplayString(" attempts left");
		_delay_ms(1000);
		attempts_Counter--;
		StartUpPassword();
		}
		else
		{
			Lcd_Clear();
			GotoXY(1,0);
			_delay_ms(100);
			Lcd_DisplayString("Wrong Password");
			_delay_ms(1000);
			Lcd_Clear();
			_delay_ms(100);

			Lcd_DisplayString("Access Denied");
			 Wdt_Enable();
			 Wdt_Sleep (WDT_SLEEP_TIME_2_1_S);
			while(1){}
		}
	}
}

void AccessUser()
{
	Lcd_Clear();
	_delay_ms(100);
	GotoXY(1,0);
	Lcd_DisplayString("hello");
}


