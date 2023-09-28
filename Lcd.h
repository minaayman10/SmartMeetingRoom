#ifndef LCD_H_
#define LCD_H_

/********** CONFG.*********/
/**** LCD Control Pins ****/
#define LCD_PIN_RS DIO_PORTC,DIO_PIN7
#define LCD_PIN_RW DIO_PORTC,DIO_PIN6
#define LCD_PIN_EN DIO_PORTC,DIO_PIN5

/****** LCD DATA Pins ****/
#define LCD_PIN_D0 DIO_PORTD,DIO_PIN0
#define LCD_PIN_D1 DIO_PORTD,DIO_PIN1
#define LCD_PIN_D2 DIO_PORTC,DIO_PIN4
#define LCD_PIN_D3 DIO_PORTD,DIO_PIN3
#define LCD_PIN_D4 DIO_PORTD,DIO_PIN4
#define LCD_PIN_D5 DIO_PORTD,DIO_PIN5
#define LCD_PIN_D6 DIO_PORTD,DIO_PIN6
#define LCD_PIN_D7 DIO_PORTD,DIO_PIN7
/**************************/

void Lcd_SendCommand (u8 command);
void Lcd_SendData (u8 command);

void Lcd_InitPins(void);
void Lcd_Init(void);

void Lcd_DisplayString(const u8 *str);
void Lcd_DisplayNumber(const u32 Number);

void GotoXY(u8 X,u8 Y);
void Lcd_Clear(void);

#endif
