/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 7 Octoper 2023				Palestine is happy <3         	*/
/*     Version: V01											         	*/
/************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

static u8 Global_u8Single_Mode=0;
static void(*MSTK_CallBack)(void);

void MSTK_voidInit()
{
	#if MSTK_ClockInput==MSTK_AHB
	SET_BIT(MSTK->CTRL,2);
	#elif MSTK_ClockInput==MSTK_AHB_DIV8
	CLR_BIT(MSTK->CTRL,2);
	#endif
}
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	if(Copy_u32Ticks <= 0xFFFFFF)
	{
		MSTK->LOAD = Copy_u32Ticks;
		
		SET_BIT(MSTK->CTRL,0);
		
		while(GET_BIT(MSTK->CTRL,16) == 0);
		
		CLR_BIT(MSTK->CTRL, 0);
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}
	else
	{
		/*return  error*/
	}
}


void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void(*Fptr)(void))
{
	if(Copy_u32Ticks <= 0xFFFFFF)
	{
		MSTK_CallBack = Fptr;
		MSTK->LOAD = Copy_u32Ticks;
		Global_u8Single_Mode = 1;
		SET_BIT(MSTK->CTRL,0); /*Start Timer*/
		SET_BIT(MSTK->CTRL,1); /*Enable interrupt*/
		
	}
	else
	{
		/*return  error*/
	}
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void(*Fptr)(void))
{
	if(Copy_u32Ticks <= 0xFFFFFF)
	{
		MSTK_CallBack = Fptr;
		MSTK->LOAD = Copy_u32Ticks;
		Global_u8Single_Mode = 0;
		SET_BIT(MSTK->CTRL,0); /*Start Timer*/
		SET_BIT(MSTK->CTRL,1); /*Enable interrupt*/
		
	}
	else
	{
		/*return  error*/
	}
}

void MSTK_voidStopTimer()
{
		CLR_BIT(MSTK->CTRL, 1); /*Disable Interrupt*/
	    /*Stop Timer*/
		CLR_BIT(MSTK->CTRL, 0); 
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
}



u32 MSTK_u32GetElapsedTime()
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = (MSTK->LOAD) - (MSTK->VAL);
	return Local_u32ElapsedTime;
}

u32 MSTK_u32GetRemainingTime()
{
	u32 Local_u32RemainingTime;
	Local_u32RemainingTime = (MSTK->VAL);
	return Local_u32RemainingTime;
}



void SysTick_Handler()
{
	u8 Local_u8temp; /*read flag to clear it*/
	if(Global_u8Single_Mode == 1)
	{
		MSTK_CallBack();
		/*Stop Timer*/
		CLR_BIT(MSTK->CTRL, 0); 
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}
	else if (Global_u8Single_Mode == 0)
	{
		MSTK_CallBack();
	}
	Local_u8temp = GET_BIT(MSTK->CTRL,16);
}
