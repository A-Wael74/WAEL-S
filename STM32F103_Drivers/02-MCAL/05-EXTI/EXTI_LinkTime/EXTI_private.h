/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 6 Octoper 2023									         	*/
/*     Version: V01											         	*/
/************************************************************************/


#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_t;
#define EXTI ((volatile EXTI_t*) 0x40010400)       //EXTI->IMR


typedef enum {
	Disabled,
	Enabled,
	Rising,
	Falling,
	On_Change
}EXTI_mode;


static void MEXTI_voidEnableEXTI(u8 Copy_u8line, EXTI_mode Copy_mode);
static void MEXTI_voidDisableEXTI(u8 Copy_u8line);
extern EXTI_mode EXTI_InitArr[15][2];


#endif