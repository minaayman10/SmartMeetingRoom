#ifndef WDT_H_
#define WDT_H_

#define WDT_DISABLE 0b00011000

typedef enum {
	WDT_SLEEP_TIME_16_3_MS,
	WDT_SLEEP_TIME_32_5_MS,
	WDT_SLEEP_TIME_65_MS,
	WDT_SLEEP_TIME_0_13_S,
	WDT_SLEEP_TIME_0_26_S,
	WDT_SLEEP_TIME_0_52_S,
	WDT_SLEEP_TIME_1_S,
	WDT_SLEEP_TIME_2_1_S,
}Wdt_SleepTimeType;

void Wdt_Enable(void);
void Wdt_Disable(void);
void Wdt_Sleep (Wdt_SleepTimeType time);


#endif
