/************************************************************************/
/*     Author: Ahmed Wael									         											*/
/*     Date: 21 December 2023								       											*/
/*     Version: V01											       	  											*/
/************************************************************************/

#include "STK.h"
#include "bitmath.h"

typedef struct
{
volatile uint32_t _CTRL;
volatile uint32_t _LOAD;
volatile uint32_t _VAL;
volatile uint32_t _CALIB;	 	 
}SysTick_t;

#define STK ((SysTick_t*)0xE000E010)

void STK_Init()
{
	SET_BIT(STK->_CTRL,2);    //SET CLKSRC TO AHB
}

void STK_TICKINTEnable()
{
	SET_BIT(STK->_CTRL,1);
}

void STK_SetVal(uint32_t val)
{
		STK->_LOAD = val;
		SET_BIT(STK->_CTRL,0);
}


























