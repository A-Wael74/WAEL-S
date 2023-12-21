/************************************************************************/
/*     Author: Ahmed Wael									         											*/
/*     Date: 20 December 2023								        										*/
/*     Version: V01											       	  											*/
/************************************************************************/
#include "osKernel.h"
#include "osCfg.h"
#include "stm32f4xx.h"  
#include "STK.h"

uint32_t  MILLIS;

#define SYSPRI3 	 (*((volatile uint32_t *)0xE000ED20))
#define INTCTRL 	 (*((volatile uint32_t *)0xE000ED04))

#define MAX_QUANTA 1000	
uint32_t Global_TaskIndex = 0;

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

static void Task_StackInit(uint32_t task_index, void(*task)(void))
{
	tcbs[task_index].sp = &_STACK[task_index][TASK_STACKSIZE-16];
	_STACK[task_index][TASK_STACKSIZE-1] = 0x01000000;  //xPSR register to indicate processor we are in thumb mode
	_STACK[task_index][TASK_STACKSIZE-2] = (int32_t)task;	 //PC
}

uint8_t osKernelAddTask (void(*task)(void))
{
	if(Global_TaskIndex == NUM_OF_TASK)
	{
	  return 0;
	}
	__disable_irq();
	if (Global_TaskIndex == 0)
	{
		Task_StackInit(Global_TaskIndex,task);
		tcbs[Global_TaskIndex].next = &tcbs[Global_TaskIndex];
		currentPt = &tcbs[Global_TaskIndex];
	}
	else
	{
		Task_StackInit(Global_TaskIndex,task);
		tcbs[Global_TaskIndex-1].next = &tcbs[Global_TaskIndex];
		tcbs[Global_TaskIndex].next = &tcbs[0];
	}	
	Global_TaskIndex++;
	__enable_irq();
	return 1;
}													 


void osKernelLaunch()
{
	if(Global_TaskIndex == 0)
	{
		
	}
	else
	{
			#if QUANTA>MAX_QUANTA
					#error "QANTA CAN'T EXCEED 1000ms"
			#else
					__disable_irq();
						MILLIS = AHBBUS_FREQ/1000;  //Value of 1 ms
						SYSPRI3 =(SYSPRI3&0x00FFFFFF)|0xE0000000; // priority 7 lowest
						STK_Init();
						STK_TICKINTEnable();
						STK_SetVal((QUANTA*MILLIS)-1);
						osSchedulerLaunch();
			#endif
	}

}

void osSchedulerRR()
{
	currentPt = currentPt->next;
}

void osTaskYield()
{
	SysTick->VAL = 0;
	INTCTRL = 0x04000000;
}


uint8_t Semaphore_Take(Semaphor_t* S)
{
	__disable_irq();
	if(S->State == 1)
	{
		return 0;
	}
	else
	{
		S->State = 1;
		return 1;
	}
	__enable_irq();
}

void Semaphore_Release(Semaphor_t* S)
{
	__disable_irq();
	S->State = 0;
	__enable_irq();
}

void SemaphoreWait(Semaphor_t* S)
{
	while(S->State == 1)
	{
			__disable_irq();
			osTaskYield();
			__enable_irq();
	}
}














//void osSemaphoreCreate(int32_t* semaphore, int32_t* value)
//{
//	*semaphore = *value;
//}

//void osSignalSet(int32_t* semaphore)
//{
//	__disable_irq();
//	*semaphore+=1;
//	__enable_irq();
//}

//void osSignalWait(int32_t* semaphore)
//{
//	__disable_irq();
//	while(*semaphore <= 0)
//	{
//		__disable_irq();
//		osTaskYield();
//		__enable_irq();
//	}
//		*semaphore-=1;
//	__enable_irq();
//}

/*
//	MILLIS_PRESCALER = (BUS_FREQ/1000); 
//	SysTick->CTRL = 0;
//	SysTick->VAL  = 0;
//	SysTick->LOAD = (quanta*MILLIS_PRESCALER)-1;  //set quanta in millis
//SysTick->CTRL = 0x00000007; //Init Systick

*/
