/*
 * WDT.h
 *
 * Created: 10/27/2023 3:05:41 PM
 *  Author: Ahmed Wael
 */


#ifndef WDT_H_
#define WDT_H_

#include "Std_types.h"

/*SLEEP_TIME*/
#define WDT_16_3ms 0
#define WDT_32_5ms 1
#define WDT_65ms   2
#define WDT_0_13s  3
#define WDT_0_26s  4
#define WDT_0_52s  5
#define WDT_1s     6
#define WDT_2_1s   7




void WDT_voidEnable();
void WDT_voidSetSleepTime(u8 Copy_u8Sleep);
void WDT_voidDisable();




#endif /* WDT_H_ */