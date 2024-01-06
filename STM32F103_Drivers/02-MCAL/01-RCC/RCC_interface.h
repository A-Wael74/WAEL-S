/************************************************************************/
/*     Author: Ahmed Wael									         	*/
/*     Date: 2 October 2023									         	*/
/*     Version: V01											         	*/
/************************************************************************/


#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2


/* APB2 Clock Enable */
#define MRCC_APB2_AFIO		0
#define MRCC_APB2_PORTA		2
#define MRCC_APB2_PORTB		3
#define MRCC_APB2_PORTC		4
#define MRCC_APB2_SPI1		12
#define MRCC_APB2_USART1	14
/* AHB Clock Enable */
#define MRCC_AHB_DMA1		0



void RCC_voidInitSysClock(void); 
void RCC_voidEnableClock(u8 Copy_u8Bus, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8Bus, u8 Copy_u8PerId);


#endif