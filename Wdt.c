#include "avr/io.h"
#include "avr/interrupt.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Wdt.h"

void Wdt_Enable(void)
{
	SET_BIT(WDTCR, WDE);
}

void Wdt_Disable(void)
{
	/* Set WDE and WDTDE in the same line */
	WDTCR = WDT_DISABLE;

	WDTCR = 0;
}

void Wdt_Sleep (Wdt_SleepTimeType time)
{
	switch (time)
	{
	case WDT_SLEEP_TIME_16_3_MS:
		CLR_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
		break;

	case WDT_SLEEP_TIME_32_5_MS:
		SET_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
		break;

	case WDT_SLEEP_TIME_65_MS:
		CLR_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
		break;

	case WDT_SLEEP_TIME_0_13_S:
		SET_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
		break;

	case WDT_SLEEP_TIME_0_26_S:
		SET_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
		break;

	case WDT_SLEEP_TIME_0_52_S:
		SET_BIT(WDTCR, WDP0);
		CLR_BIT(WDTCR, WDP1);
		SET_BIT(WDTCR, WDP2);
		break;

	case WDT_SLEEP_TIME_1_S:
		SET_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		CLR_BIT(WDTCR, WDP2);
		break;

	case WDT_SLEEP_TIME_2_1_S:
		SET_BIT(WDTCR, WDP0);
		SET_BIT(WDTCR, WDP1);
		SET_BIT(WDTCR, WDP2);
		break;

	}
}
