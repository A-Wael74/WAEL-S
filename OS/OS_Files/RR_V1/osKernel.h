/************************************************************************/
/*     Author: Ahmed Wael									         											*/
/*     Date: 11 December 2023								       											*/
/*     Version: V01											       	  											*/
/************************************************************************/



#ifndef OS_KERNEL_H
#define OS_KERNEL_H

#include <stdint.h>                 // Device header


#define NUM_OF_TASK 3
#define TASK_STACKSIZE 100
#define BUS_FREQ 16000000

uint8_t osKernelAddTask (void(*task0)(void),
												 void(*task1)(void),
												 void(*task2)(void));

void osKernelInit(void);		
												 
void osKernelLaunch(uint32_t quanta);




#endif