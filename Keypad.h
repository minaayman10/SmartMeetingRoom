//#ifndef KEYPAD_H_
//#define KEYPAD_H_
//
///*********************************************
// * B00 * B01 * B02 * B03 * ROW1
// * B04 * B05 * B06 * B07 * ROW2
// * B08 * B09 * B10 * B11 * ROW3
// * B12 * B13 * B14 * B15 * ROW4
// * cl1 * cl2 * cl3 * cl4 *
// */
//
///************ Keypad Rows Connections ************/
//#define KEYPAD_PIN_R1 DIO_PORTD,DIO_PIN0
//#define KEYPAD_PIN_R2 DIO_PORTD,DIO_PIN1
//#define KEYPAD_PIN_R3 DIO_PORTD,DIO_PIN2
//#define KEYPAD_PIN_R4 DIO_PORTD,DIO_PIN3
//
///************ Keypad Columns Connections ************/
//#define KEYPAD_PIN_C1 DIO_PORTD,DIO_PIN4
//#define KEYPAD_PIN_C2 DIO_PORTD,DIO_PIN5
//#define KEYPAD_PIN_C3 DIO_PORTD,DIO_PIN6
//#define KEYPAD_PIN_C4 DIO_PORTD,DIO_PIN7
//
//
//typedef enum {
//	KEYPAD_B00,
//	KEYPAD_B01,
//	KEYPAD_B02,
//	KEYPAD_B03,
//	KEYPAD_B04,
//	KEYPAD_B05,
//	KEYPAD_B06,
//	KEYPAD_B07,
//	KEYPAD_B08,
//	KEYPAD_B09,
//	KEYPAD_B10,
//	KEYPAD_B11,
//	KEYPAD_B12,
//	KEYPAD_B13,
//	KEYPAD_B14,
//	KEYPAD_B15,
//	KEYPAD_INVALID,
//} Keypad_ButtonType;
//
//typedef enum{
//	KEYPAD_NOT_PRESSED,
//	KEYPAD_PRESSED,
//} Keypad_ButtonStateType;
//
//
//void Keypad_Init(void);
//Keypad_ButtonStateType Keypad_GetButtonState(Keypad_ButtonType button);
//Keypad_ButtonType Keypad_GetPressedButton (void);
//#endif
//


/*
 * KEYPAD.h
 *
 *  Created on: Aug 15, 2023
 *      Author: NOBEL
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
/***********************************/
#define KEYPAD_PIN_R1 DIO_PORTB,DIO_PIN0
#define KEYPAD_PIN_R2 DIO_PORTB,DIO_PIN1
#define KEYPAD_PIN_R3 DIO_PORTB,DIO_PIN2
#define KEYPAD_PIN_R4 DIO_PORTB,DIO_PIN3
/**********************************/

#define KEYPAD_PIN_C1 DIO_PORTB,DIO_PIN4
#define KEYPAD_PIN_C2 DIO_PORTB,DIO_PIN5
#define KEYPAD_PIN_C3 DIO_PORTB,DIO_PIN6
#define KEYPAD_PIN_C4 DIO_PORTB,DIO_PIN7

typedef enum
{
	KEYPAD_B00,
	KEYPAD_B01,
	KEYPAD_B02,
	KEYPAD_B03,
	KEYPAD_B04,
	KEYPAD_B05,
	KEYPAD_B06,
	KEYPAD_B07,
	KEYPAD_B08,
	KEYPAD_B09,
	KEYPAD_B10,
	KEYPAD_B11,
	KEYPAD_B12,
	KEYPAD_B13,
	KEYPAD_B14,
	KEYPAD_B15,
	KEYPAD_INVALID

}Keypad_ButtonType;

typedef enum
{
	KEYPAD_NOT_PRESSED,
	KEYPAD_PRESSED
}Keypad_ButtonStateType;

void Keypad_Init(void);

Keypad_ButtonStateType Keypad_GetButtonState(Keypad_ButtonType button);

Keypad_ButtonType Keypad_GetPressedButton(void);



#endif /* KEYPAD_H_ */
