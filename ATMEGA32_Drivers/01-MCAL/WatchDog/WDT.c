/*
 * WDT.c
 *
 * Created: 10/27/2023 3:07:10 PM
 *  Author: Ahmed Wael
 */

#include "Std_types.h"
#include "Bit_utils.h"
#include "WDT_prv.h"
#include "WDT_cfg.h"
#include "WDT.h"


void WDT_voidEnable()
{
	SET_BIT(WDTCR,WDE);
}

void WDT_voidSetSleepTime(u8 Copy_u8Sleep)
{
	WDTCR &= 0xF8;
	WDTCR|= Copy_u8Sleep;
}

void WDT_voidDisable()
{
	WDTCR = 0b00011000;
	WDTCR = 0;
}