/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 7 Octoper 2023				Palestine is happy <3         	*/
/*     Version: V01											         	*/
/************************************************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit();  /*Choose Systick clk*/

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks); /*Synch Call*/

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void(*Fptr)(void));  /*Asynch call with one interrupt*/

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void(*Fptr)(void)); /*Asynch call with periodic interrupt*/

void MSTK_voidStopTimer();

u32 MSTK_u32GetElapsedTime();

u32 MSTK_u32GetRemainingTime();



#endif