#include "osKernel.h"
#include "osCfg.h"
#include "stm32f4xx.h"                  

#define __RED (1<<8)

volatile uint32_t c0 = 0;
volatile uint32_t c1 = 0;
volatile uint32_t c2 = 0;

volatile uint32_t Global = 0;
void LED_INIT()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER8_0;
}
void LED_ON()
{
	GPIOC->ODR |= __RED;
}
void LED_OFF()
{
	GPIOC->ODR =0;
}
volatile void LED_TOG()
{
	GPIOC->ODR ^= __RED;
}


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


void task3 (void)
{
	while(1)
	{
		LED_TOG();
		osTaskYield();
	}
}


int main(void)
{
	
	LED_INIT();
	
	
	osKernelAddTask(task0);
	osKernelAddTask(task1);
	osKernelAddTask(task2);
	osKernelAddTask(task3);

	osKernelLaunch();

	return 0;
}


