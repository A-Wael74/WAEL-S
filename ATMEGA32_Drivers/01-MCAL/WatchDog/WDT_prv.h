/*
 * WDT_prv.h
 *
 * Created: 10/27/2023 3:06:27 PM
 *  Author: Ahmed Wael
 */


#ifndef WDT_PRV_H_
#define WDT_PRV_H_

#define WDTCR (*(volatile unsigned char*)0x41)

#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0



#endif /* WDT_PRV_H_ */