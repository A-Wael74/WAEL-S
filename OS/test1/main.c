#include "osKernel.h"
#include "stm32f4xx.h"                  

#define quanta 10
#define __RED (1<<8)

volatile uint32_t c0 = 0;
volatile uint32_t c1 = 0;
volatile uint32_t c2 = 0;

volatile uint32_t Global = 0;
void LED_ON()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER8_0;
	GPIOC->ODR |= __RED;
}
void LED_OFF()
{
	GPIOC->ODR =0;
}

Semaphor_t S1;

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
	LED_ON();
	
	osKernelAddTask(task0);
	osKernelAddTask(task1);
	osKernelAddTask(task2);

	osKernelLaunch(quanta);

	return 0;
}


