# SmartMeetingRoom
it's smart meeting room includes fire alarm system & air condition system || using atmega32 
at first the instructor set the Bassword if it's true the door opened , if the password isn't true you can try three times then the microcontroller reject the operation and enable watch dog timer to reset the MC atmega32
when the door opened the lights and windos opened by motors 
if the temperature higher than 23 the air conditioners start to work ( operation done by the LM35 sensor ,  ADC and interrupts )
same operation with the fire alarm system but the deferece that when it's start the doors opened and Air extractor opened to reduces the fire  ( operation done by the LM35 sensor ,  ADC and interrupts )

at these project we use alot of peripherals like ADC , WDT , Interrupts and Timers .
Component : DC Motors , Servo Motor , H Bridge , LM35 and ATMEGA32 .
