/************************************************************************/
/*     Author: Ahmed Wael									         											*/
/*     Date: 11 December 2023								        										*/
/*     Version: V01											       	  											*/
/************************************************************************/
#include "osKernel.h"
#include "stm32f4xx.h"                  



uint32_t  MILLIS_PRESCALER;

#define SYSPRI3 	 (*((volatile uint32_t *)0xE000ED20))
	
void osSchedulerLaunch();

struct tcb
{
	int32_t* sp;
	struct tcb* next;
};

typedef struct tcb tcb_t;

tcb_t tcbs[NUM_OF_TASK];
tcb_t* currentPt;

int32_t _STACK[NUM_OF_TASK][TASK_STACKSIZE];


void Task_StackInit(int32_t task_index)
{
	tcbs[task_index].sp = &_STACK[task_index][TASK_STACKSIZE-16];
	_STACK[task_index][TASK_STACKSIZE-1] = 0x01000000;   //xPSR register to indicate processor we are in thumb mode
}

uint8_t osKernelAddTask (void(*task0)(void),void(*task1)(void),void(*task2)(void))
{
	__disable_irq();
	tcbs[0].next = &tcbs[1];
	tcbs[1].next = &tcbs[2];
	tcbs[2].next = &tcbs[0];
	
	Task_StackInit(0);
	_STACK[0][TASK_STACKSIZE-2] = (int32_t)(task0);
	
	Task_StackInit(1);
	_STACK[1][TASK_STACKSIZE-2] = (int32_t)(task1);

	Task_StackInit(2);
	_STACK[2][TASK_STACKSIZE-2] = (int32_t)(task2);
	
	currentPt = &tcbs[1];
	
	__enable_irq();

	return 1;
}													 

void osKernelInit(void)
{
	__disable_irq();
	MILLIS_PRESCALER = (BUS_FREQ/1000);   //Init the quanta for systick
}


void osKernelLaunch(uint32_t quanta)
{
	SysTick->CTRL = 0;
	SysTick->VAL  = 0;
	SysTick->LOAD = (quanta*MILLIS_PRESCALER)-1;  //set quanta in millis
	SYSPRI3 =(SYSPRI3&0x00FFFFFF)|0xE0000000; // priority 7 lowest
	
	SysTick->CTRL = 0x00000007; //Init Systick
	osSchedulerLaunch();
}

