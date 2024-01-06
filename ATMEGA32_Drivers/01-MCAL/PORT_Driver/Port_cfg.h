/*
 * Port_cfg.h
 *
 *  Created on: Mar 4, 2022
 *      Author: MahmoudElImbabi
 */

#ifndef MCAL_PORT_DRIVER_PORT_CFG_H_
#define MCAL_PORT_DRIVER_PORT_CFG_H_

/*

	PORT_u8MODEPINS OPTIONS:-
  	1-PORT_u8OUTPUT_LOW
	2-PORT_u8OUTPUT_HIGH
	3-PORT_u8INPUT_FLOATING
	4-PORT_u8INPUT_PULLUP
	
*/




	/*PORTA*/
#define PORT_u8MODEPIN00            PORT_u8OUTPUT_LOW	  //PA0
#define PORT_u8MODEPIN01            PORT_u8OUTPUT_LOW	  //PA1
#define PORT_u8MODEPIN02            PORT_u8OUTPUT_LOW	  //PA2
#define PORT_u8MODEPIN03            PORT_u8OUTPUT_LOW	  //PA3
#define PORT_u8MODEPIN04            PORT_u8OUTPUT_LOW	  //PA4
#define PORT_u8MODEPIN05            PORT_u8OUTPUT_LOW	  //PA5
#define PORT_u8MODEPIN06            PORT_u8OUTPUT_LOW	  //PA6
#define PORT_u8MODEPIN07            PORT_u8OUTPUT_LOW	  //PA7

	/*PORTB*/
#define PORT_u8MODEPIN08            PORT_u8OUTPUT_LOW	  //PB0
#define PORT_u8MODEPIN09            PORT_u8OUTPUT_LOW	  //PB1
#define PORT_u8MODEPIN10            PORT_u8OUTPUT_LOW	  //PB2
#define PORT_u8MODEPIN11            PORT_u8OUTPUT_LOW	  //PB3
#define PORT_u8MODEPIN12            PORT_u8OUTPUT_LOW	  //PB4
#define PORT_u8MODEPIN13            PORT_u8OUTPUT_LOW	  //PB5
#define PORT_u8MODEPIN14            PORT_u8OUTPUT_LOW	  //PB6
#define PORT_u8MODEPIN15            PORT_u8OUTPUT_LOW	  //PB7

	/*PORTC*/
#define PORT_u8MODEPIN16            PORT_u8OUTPUT_LOW     //PC0
#define PORT_u8MODEPIN17            PORT_u8OUTPUT_LOW  	  //PC1
#define PORT_u8MODEPIN18            PORT_u8OUTPUT_LOW 	  //PC2
#define PORT_u8MODEPIN19            PORT_u8OUTPUT_LOW 	  //PC3
#define PORT_u8MODEPIN20            PORT_u8OUTPUT_LOW 	  //PC4
#define PORT_u8MODEPIN21            PORT_u8OUTPUT_LOW 	  //PC5
#define PORT_u8MODEPIN22            PORT_u8INPUT_PULLUP	  //PC6
#define PORT_u8MODEPIN23            PORT_u8INPUT_FLOATING //PC7

	/*PORTD*/
#define PORT_u8MODEPIN24            PORT_u8OUTPUT_HIGH    //PD0
#define PORT_u8MODEPIN25            PORT_u8OUTPUT_HIGH	  //PD1
#define PORT_u8MODEPIN26            PORT_u8OUTPUT_HIGH	  //PD2
#define PORT_u8MODEPIN27            PORT_u8INPUT_PULLUP	  //PD3
#define PORT_u8MODEPIN28            PORT_u8OUTPUT_LOW 	  //PD4
#define PORT_u8MODEPIN29            PORT_u8INPUT_PULLUP	  //PD5
#define PORT_u8MODEPIN30            PORT_u8INPUT_PULLUP	  //PD6
#define PORT_u8MODEPIN31            PORT_u8INPUT_PULLUP	  //PD7




























#endif /* MCAL_PORT_DRIVER_PORT_CFG_H_ */
