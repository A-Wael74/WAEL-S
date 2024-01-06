/*
 * UART_Services.c
 *
 * Created: 9/27/2022 10:01:17 PM
 *  Author: Ahmed Wael
 */ 

#include "UART_Services.h"

void UART_SendStr(u8 *str)
{
	u8 i;
	for (i = 0; str[i];i++)
	{
		UART_Send(str[i]);
	}
}


void UART_ReceiveStr(u8 *str)  /*the end of string is #*/
{
	u8 i = 0;
    str[i] = UART_Receive();
	while(str[i] != 0x0A)
	{
		i++;
		str[i] = UART_Receive();
	}
	str[i-1] = 0;
}
