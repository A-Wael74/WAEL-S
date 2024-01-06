/*
 * UART_Services.h
 *
 * Created: 9/27/2022 10:01:26 PM
 *  Author: Ahmed Wael
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"


void UART_SendStr(u8 *str);

void UART_ReceiveStr(u8 *str);




#endif /* UART SERVICES_H_ */