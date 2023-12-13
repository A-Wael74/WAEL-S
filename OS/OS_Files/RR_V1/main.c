#include "osKernel.h"
#include "stm32f4xx.h"                  

#define quanta 10
#define RED (1<<8)

uint32_t c0 = 0;
uint32_t c1 = 0;
uint32_t c2 = 0;

 void task0 (void)
{
	while(1)
	{
		c0++;
	}
}
 void task1 (void)
{
	while(1)
	{
		c1++;
	}
}
 void task2 (void)
{
	while(1)
	{
		c2++;
	}
}
int main(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER8_0;
	GPIOC->ODR |= RED;
	osKernelInit();

	osKernelAddTask(task0,task1,task2);
	osKernelLaunch(quanta);
	
	return 0;
}