/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 6 Octoper 2023									         	*/
/*     Version: V01											         	*/
/************************************************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidInit();

void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);

u8 MNVIC_GetActiveFlag(u8 Copy_u8IntNumber);

void MNVIC_voidSetPriority(u8 Copy_u8PeripheralId ,u8 Copy_u8Priority);



/* Interrupt Vector table */
#define MNVIC_INT_EXTI0					6
#define MNVIC_INT_EXTI1					7
#define MNVIC_INT_EXTI2					8
#define MNVIC_INT_EXTI3					9
#define MNVIC_INT_EXTI4					10
#define MNVIC_INT_EXTI9_5				23
#define MNVIC_INT_EXTI15_10				40
#define MNVIC_INT_DMA1_Channel1			11
#define MNVIC_INT_DMA1_Channel2			12
#define MNVIC_INT_DMA1_Channel3			13
#define MNVIC_INT_DMA1_Channel4			14
#define MNVIC_INT_DMA1_Channel5			15
#define MNVIC_INT_DMA1_Channel6			16
#define MNVIC_INT_DMA1_Channel7			17


#endif