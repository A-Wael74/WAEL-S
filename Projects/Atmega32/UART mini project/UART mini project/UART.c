/*
 * UART.c
 *
 * Created: 9/26/2022 9:46:32 PM
 *  Author: Ahmed Wael
 */ 

#include "UART.h"

 void UART_Init()
 {
	 /*baud rate 9600*/
	 UBRRL = 51;
	 /*Normal Speed*/
	 CLR_BIT(UCSRA,U2X);
	 /*Frame*/
	   /*Default*/
	 /*ENABLE*/
	 SET_BIT(UCSRB,TXEN);
	 SET_BIT(UCSRB,RXEN);
 }
 
 void UART_Send(u8 data)
 {
	 while(! GET_BIT(UCSRA,UDRE));
		UDR = data;
 }
 
 
  u8 UART_Receive()
  {
	  while(! GET_BIT(UCSRA,RXC));
	  return UDR;
  }


u8 UART_ReceivePeriodic(u8 *pdata)
{
	 if(GET_BIT(UCSRA,RXC))
	 {
		 *pdata = UDR;
		 return 1;
	 }
	return 0;
}
