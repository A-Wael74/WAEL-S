/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 7 October 2023				Palestine is happy <3         	*/
/*     Version: V01											         	*/
/************************************************************************/


#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


typedef struct 
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
	
}MSTK_t;

#define MSTK ((MSTK_t*)0xE000E010)

#define MSTK_AHB 0
#define MSTK_AHB_DIV8 1

#endif