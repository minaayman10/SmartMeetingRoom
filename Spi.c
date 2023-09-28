#include "avr/io.h"
#define F_CPU 8000000UL

#include "avr/delay.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio.h"
#include "Spi.h"


void SPI_Init(void)
{
#if SPI_MODE == SPI_MASTER

	/* Set SS pin as output for master */
	Dio_SetPinMode(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);

	/* Set MOSI pin as output for master */
	Dio_SetPinMode(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);

	/* Set SCK pin as output for master */
	Dio_SetPinMode(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);

	/* Enable Master Mode */
	SET_BIT(SPCR, MSTR);

	/* Set clock to Master */
	/* Set for PRESCALLER_16 */
	SET_BIT(SPCR, SPR0);
	CLR_BIT(SPCR, SPR1);
	CLR_BIT(SPCR, SPI2X);

	/* Enable SPI */
	SET_BIT(SPCR, SPE);

	/* Set SS pin to high */
	Dio_SetPinLevel(DIO_PORTB,DIO_PIN4,STD_HIGH);

	/* Wait until other peripherals to initialized */
	_delay_ms(300);


#elif SPI_MODE == SPI_SLAVE

	/* Enable SPI */
	SET_BIT(SPCR, SPE);

	/* Set MISO pin as output for master */
	Dio_SetPinMode(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);

	/* Wait until other peripherals to initialized */
	_delay_ms(300);

#else
#error "Select correct Option for SPI_MODE"
#endif
}

void SPI_MasterSendData(u8 data)
{
	/* Clear SS Pin to send data to slave */
	Dio_SetPinLevel(DIO_PORTB,DIO_PIN4,STD_LOW);

	/* Put Data on SPDR */
	SPDR = data;

	/* Wait until data is received in SPI Register */
	while(GET_BIT(SPSR,SPIF) == 0);


}

u8 SPI_SlaveReceiveData(void)
{
	/* Wait until data is received in SPI Register */
	while(GET_BIT(SPSR,SPIF) == 0);

	/* Read to reveived data */
	return SPDR;
}

void SPI_MasterSendString(u8 *str)
{
	while(*str != '\0')
	{
		SPI_MasterSendString(* str);
		str++;
	}
	SPI_MasterSendData('\n');
}

void SPI_SlaveReceiveString(u8 str[])
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

