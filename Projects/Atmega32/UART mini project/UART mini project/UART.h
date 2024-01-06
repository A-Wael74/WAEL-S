/*
 * UART.h
 *
 * Created: 9/26/2022 9:46:44 PM
 *  Author: Ahmed Wael
 */ 


#ifndef UART_H_
#define UART_H_

 #include "MemMap.h"
 #include "Utils.h"
 #include "StdTypes.h"
 
 void UART_Init();
 
 void UART_Send(u8 data);
 
 u8 UART_Receive();

u8 UART_ReceivePeriodic(u8 *pdata);



#endif /* UART_H_ */