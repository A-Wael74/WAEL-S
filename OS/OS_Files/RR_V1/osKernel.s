; Author: Ahmed Wael			
; Date: 11 December 2023	
; Version: V01						
			AREA |.text|, CODE, READONLY, ALIGN=2
			THUMB
			EXTERN currentPt
			EXPORT SysTick_Handler
			EXPORT osSchedulerLaunch
SysTick_Handler
	CPSID 	I
	;Save the context of the current task
	PUSH	{R4-R11} ;Push remaining regs to stack
	LDR		R0, =currentPt   ;r0 points to the currentPt 
	LDR 	R1, [R0]  ;load current ptr in r1
	STR		SP, [R1]	  ; store the stack pointer to r1
	;Load context of next task
	LDR 	R1,[R1,#4]  ;r1 = currentPt->next
	STR		R1, [R0]	;currentPt = r1
	LDR 	SP, [R1]	; [R1] means currentPt.sp , load into sp, the sp of the next thread
	POP 	{R4-R11}
	CPSIE	I
	BX		LR

osSchedulerLaunch
	LDR		R0,=currentPt
	LDR		R2,[R0]
	LDR		SP,[R2] ;Stack Pointer points to the stack frame of first task
	POP		{R4-R11}; load contents of the task's stack frame into processor
	POP		{R0-R3}
	POP		{R12}
	ADD		SP,SP,#4 ;get rid of LR
	POP		{LR}
	ADD 	SP,SP,#4
	CPSIE	I
	BX		LR
	
	ALIGN
	END


