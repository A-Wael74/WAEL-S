/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 6 Octoper 2023									         	*/
/*     Version: V02											         	*/
/************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInit(void)
{
    #define SCB_AIRCR  *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}


void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*ERROR*/
	}
}

void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*ERROR*/
	}
}

void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*ERROR*/
	}
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = (1<<Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR0 = (1<<Copy_u8IntNumber);
	}
	else
	{
		/*ERROR*/
	}
}

u8 MNVIC_GetActiveFlag(u8 Copy_u8IntNumber)
{
	if (Copy_u8IntNumber <= 31)
	{
		return ((NVIC_IABR0>>Copy_u8IntNumber)&1);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		return ((NVIC_IABR1>>Copy_u8IntNumber)&1);
	}
	else
	{
		/*ERROR*/
	}
}

void MNVIC_voidSetPriority(u8 Copy_u8PeripheralId ,u8 Copy_u8Priority)
{
	if(Copy_u8PeripheralId <60)
	{
		NVIC_IPR[Copy_u8PeripheralId] = Copy_u8Priority;
	}
	else
	{
		/*return error*/
	}

}