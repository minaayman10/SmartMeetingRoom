#ifndef SEGMENT_H_
#define SEGMENT_H_

/* define LED Direction */
#define DDR_7_SEGMENT DDRC

/* define LED port */
#define PORT_7_SEGMENT PORTC

void Segment_InitPins(void);
void Segment_SetNumber (u8 Number);
void Segment_Clear(void);


#endif
