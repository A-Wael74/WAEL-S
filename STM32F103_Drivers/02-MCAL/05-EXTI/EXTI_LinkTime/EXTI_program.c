/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 6 Octoper 2023									         	*/
/*     Version: V01											         	*/
/************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


void MEXTI_voidInit()
{
	for(u8 i = 0; i <=15;i++)
	{
		if (EXTI_InitArr[i][0] == Disabled)
		{
			 MEXTI_voidDisableEXTI(i);
		}
		else if (EXTI_InitArr[i][0] == Enabled)
		{
			MEXTI_voidEnableEXTI(i,EXTI_InitArr[i][1])
		}
	}
}

static void MEXTI_voidEnableEXTI(u8 Copy_u8line, EXTI_mode Copy_mode)
{
	switch(Copy_mode)
	{
		case Rising 	:	SET_BIT(EXTI -> RTSR , Copy_u8Line); 	break;
		case Falling	:	SET_BIT(EXTI -> FTSR , Copy_u8Line); 	break;
		case On_Change 	:	SET_BIT(EXTI -> RTSR , Copy_u8Line); 
							SET_BIT(EXTI -> FTSR , Copy_u8Line); 	break;
	}
	
	SET_BIT(EXTI->IMR , Copy_u8Line);
	
}
static void MEXTI_voidDisableEXTI(u8 Copy_u8line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}

void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> SWIER , Copy_u8Line);
	
}



/*
if(EXTI_InitArr[Copy_u8Line][1] == Rising)
	{
		EXTI_InitArr[Copy_u8Line][1] = Falling;
	}
	else if (EXTI_InitArr[Copy_u8Line][1] == Falling)
	{
		EXTI_InitArr[Copy_u8Line][1] = Rising;
	}
*/
