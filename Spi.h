#ifndef SPI_H_
#define SPI_H_

/********************************************
 --> Options
		SPI_MASTER
		SPI_SLAVE
*/
#define SPI_MODE SPI_MASTER
/********************************************
 --> Options
 	 	 PRESCALLER_2
 	 	 PRESCALLER_4
 	 	 PRESCALLER_8
 	 	 PRESCALLER_16
 	 	 PRESCALLER_32
 	 	 PRESCALLER_64
 	 	 PRESCALLER_128
*/
#define SPI_CLOCK_RATE PRESCALLER_16
/*******************************************/

void SPI_Init(void);

void SPI_MasterSendData(u8 data);
u8 SPI_SlaveReceiveData(void);

void SPI_MasterSendString(u8 *str);
void SPI_SlaveReceiveString(u8 str[]);

#endif
