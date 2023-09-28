#include "avr/io.h"
#define F_CPU 8000000UL
#include "avr/delay.h"
#include<stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Usart.h"

void UART_Init(void)
{
	u16 UBRR;

	/* Choose baud rate that will be used by sender and reciver by writing to UBRRL & UBRRH*/
	#if USART_BAUD_RATE == 2400   || USART_BAUD_RATE == 4800   || USART_BAUD_RATE == 9600   || USART_BAUD_RATE == 14400  || \
		USART_BAUD_RATE == 19200  || USART_BAUD_RATE == 28800  || USART_BAUD_RATE == 38400  || USART_BAUD_RATE == 57600  || \
		USART_BAUD_RATE == 76800  || USART_BAUD_RATE == 115200 || USART_BAUD_RATE == 230400 || USART_BAUD_RATE == 250000 || \
		USART_BAUD_RATE == 500000 || USART_BAUD_RATE == 1000000

		UBRR = (F_CPU /16 * (u32)USART_BAUD_RATE) - 1;
		UBRRH = (u8)(UBRR >> 8);
		UBRRL = (u8)(UBRR);
	#else
	#error "Select correct option for baud rate"

	#endif

	/* Enable USART Sender */
	SET_BIT(UCSRB, TXEN);

	/* Enable USART Reciever */
	SET_BIT(UCSRB, RXEN);

	/* Chose number of data bits be sent */

	#if   USART_CHAR_SIZE == USART_CHAR_SIZE_5_BIT

	#elif USART_CHAR_SIZE == USART_CHAR_SIZE_6_BIT

	#elif USART_CHAR_SIZE == USART_CHAR_SIZE_7_BIT

	#elif USART_CHAR_SIZE == USART_CHAR_SIZE_8_BIT
			UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1)
				/* 0b10000110 */
//			SET_BIT(UCSRC, URSEL);
//			SET_BIT(UCSRC, UCSZ0);
//			SET_BIT(UCSRC, UCSZ1);
//			CLR_BIT(UCSRC, UCSZ2);

	#elif USART_CHAR_SIZE == USART_CHAR_SIZE_9_BIT

	#endif

	/* Wait until all other peripherals be initalized */
	_delay_ms(300);
}
void UART_SendData(u8 data)
{
	/* Wait for UDR transmit buffer to be empty */
	while(GET_BIT(UCSRA, UDRE) == 0);

	/* Put data to UDR transmit buffer */
	UDR = data;
}

u8 UART_ReceiveData(void)
{
	/* Wait for UDR Recieve buffer to be filled with data */
	while(GET_BIT(UCSRA, RXC) == 0);

	/* Recieve data from UDR receive buffer */
	return UDR;
}

void UART_SendString(u8 *str)
{
	while(*str != '\0')
	{
		UART_SendData(*str);
		str++;
	}
	UART_SendData('\n');
}

void UART_ReceiveString(u8 str[])
{
	u32 index = 0;

	while(1)
	{
		str[index] = UART_ReceiveData();

		if(str[index]=='\n' || str[index]=='\r')
		{
			str[index]='\0';
			break;
		}
		index++;
	}
}

void UART_SendNumber(u32 number)
{
	/* Array to stored conversion characters */
	s8* str[16] ={0};

	/* Convert interger to string */
	ltoa(number, (u8*)str, 10);

	/* Display number after conversion */
	UART_SendString((u8*)str);
}

u32 UART_ReceiveNumber(void)
{
	u32 index = 0;
	u32 number;
	u8 str[100];

	while(1)
	{
		str[index] = UART_ReceiveData();

		if(str[index]=='\n' || str[index]=='\r')
		{
			str[index]='\0';
			break;
		}
		index++;
	}
	number = atol(str);
	return number;
}
