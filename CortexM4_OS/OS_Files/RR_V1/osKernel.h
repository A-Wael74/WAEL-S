/************************************************************************/
/*     Author: Ahmed Wael									         											*/
/*     Date: 20 December 2023								       											*/
/*     Version: V01											       	  											*/
/************************************************************************/
#ifndef OS_KERNEL_H
#define OS_KERNEL_H

#include <stdint.h>
#include "osCfg.h"

typedef struct 
{
	uint8_t State;
}Semaphor_t;


uint8_t osKernelAddTask (void(*task)(void));
												 
void osKernelLaunch();
												 
void osTaskYield(void);

												 
uint8_t Semaphore_Take(Semaphor_t* S);
void Semaphore_Release(Semaphor_t* S);
void SemaphoreWait(Semaphor_t* S);




#endif