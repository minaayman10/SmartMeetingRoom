#ifndef USART_H_
#define USART_H_

/********************************************
 --> Options
 	 	 2400
 	 	 4800
 	 	 9600
 	 	 14400
 	 	 19200
 	 	 28800
 	 	 38400
 	 	 57600
 	 	 76800
 	 	 115200
 	 	 230400
 	 	 250000
 	 	 500000
 	 	 1000000
*/
#define USART_BAUD_RATE 9600
/********************************************
 --> Options
 	 	 USART_CHAR_SIZE_5_BIT
 	 	 USART_CHAR_SIZE_6_BIT
 	 	 USART_CHAR_SIZE_7_BIT
 	 	 USART_CHAR_SIZE_8_BIT
 	 	 USART_CHAR_SIZE_9_BIT
*/
#define USART_CHAR_SIZE USART_CHAR_SIZE_8_BIT
/*******************************************/
void UART_Init(void);

void UART_SendData(u8 data);
u8 UART_ReceiveData(void);

void UART_SendString(u8 *str);
void UART_ReceiveString(u8 str[]);

void UART_SendNumber(u32 number);
u32 UART_ReceiveNumber(void);

#endif
