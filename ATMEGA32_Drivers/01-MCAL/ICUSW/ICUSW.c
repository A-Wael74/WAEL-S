/*
 * ICUSW.c
 *
 * Created: 10/27/2023 12:40:33 PM
 *  Author: Ahmed Wael
 */
#include "Std_types.h"
#include "Bit_utils.h"
#include "EXTI.h"
#include "Timers.h"
#include "ICUSW.h"



#define OV_TIMEus 1024

volatile u16 Global_u16OvCounter = 0;

volatile u8 Global_EXTIFlag =0;

volatile u16 Global_Periodtime=0;
volatile u16 Global_ONtime=0;

void Timer_OVINT()
{
	Global_u16OvCounter++;
}

void EXTI_INT()
{
	static u8 static_u8Enterance = 0;

	if(static_u8Enterance == 0) //FIRST RISING EDGE
	{
		Timer0_voidSetTCNT(0);
		static_u8Enterance++;
	}

	else if(static_u8Enterance == 1) //SECOND RISING EDGE
	{
		Global_Periodtime = Timer0_u8GetTCNT();
		EXTI_voidSetPinMode(EXTI_INT0,EXTI_FALLING);
		static_u8Enterance++;
		Timer0_voidSetTCNT(0);
	}

	else if(static_u8Enterance == 2) //THIRD RISING EDGE
	{
		Global_ONtime = Timer0_u8GetTCNT();
		static_u8Enterance=0;
		Global_EXTIFlag = 1;

	}
}
void ICUSW_voidEnable()
{
	Timer0_voidInit(Timer0_NormalMode,Timer0_SCALER_64,OC0_DISCONNECTED);  //Tick Time: 4us
	Timer0_voidOVF_SetCallBack(Timer_OVINT);
	EXTI_voidSetPinMode(EXTI_INT0,EXTI_RISING);
	EXTI_voidSetCallBack(EXTI_INT0,EXTI_INT);
}

void ICUSW_voidGetICUSW(u32* Add_u8PeriodTimeus, u16* Add_u8OnTimeus, u8*Add_u16DutyCucle)
{
	//Timer0_voidSetTCNT(0);
	Timer0_voidOVF_InterruptEnable();
	EXTI_voidEnable(EXTI_INT0);
	while(Global_EXTIFlag == 0);
	*Add_u8PeriodTimeus = (Global_Periodtime*4) +((u32)Global_u16OvCounter*OV_TIMEus);
	*Add_u8OnTimeus = Global_ONtime*4;
	if(*Add_u8PeriodTimeus == 0)
	{
		Add_u16DutyCucle=0;
	} 
	else
	{
		*Add_u16DutyCucle = ((u32)*Add_u8OnTimeus*100/ *Add_u8PeriodTimeus);
	}
	
	Global_u16OvCounter = 0;
	Global_EXTIFlag =0;
	Timer0_voidOC_InterruptDisable();
	EXTI_voidDisable(EXTI_INT0);
}
