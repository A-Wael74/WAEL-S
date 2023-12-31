/*
 * Dio.h
 *
 *  Created on: Mar 4, 2022
 *      Author: MahmoudElImbabi
 */

#ifndef MCAL_DIO_DRIVER_DIO_H_
#define MCAL_DIO_DRIVER_DIO_H_

/*ENUM*/
typedef enum {
Dio_enuOk,
Dio_enuChannelError,
Dio_enuLevelError,
Dio_enuDirectionError,
Dio_enuNullPointerError,
Dio_enuPortRangeError
}Dio_tenuErrorStatus;

/*MACROS*/
#define DIO_u8LEVEL_HIGH 	1
#define DIO_u8LEVEL_LOW 	0

#define DIO_u8OUTPUT				1
#define DIO_u8INPUT					0


/*PORT ID OPTIONS */
#define	DIO_u8PORTA 				0
#define	DIO_u8PORTB 				1
#define	DIO_u8PORTC 				2
#define	DIO_u8PORTD 				3



/*PORTA*/
#define DIO_u8CHANNEL00            0	//PA0
#define DIO_u8CHANNEL01            1	//PA1
#define DIO_u8CHANNEL02            2	//PA2
#define DIO_u8CHANNEL03            3	//PA3
#define DIO_u8CHANNEL04            4	//PA4
#define DIO_u8CHANNEL05            5	//PA5
#define DIO_u8CHANNEL06            6	//PA6
#define DIO_u8CHANNEL07            7	//PA7
/*PORTB*/
#define DIO_u8CHANNEL08            8    //PB0
#define DIO_u8CHANNEL09            9	//PB1
#define DIO_u8CHANNEL10            10	//PB2
#define DIO_u8CHANNEL11            11	//PB3
#define DIO_u8CHANNEL12            12	//PB4
#define DIO_u8CHANNEL13            13	//PB5
#define DIO_u8CHANNEL14            14	//PB6
#define DIO_u8CHANNEL15            15	//PB7

/*PORTC*/
#define DIO_u8CHANNEL16            16	//PC0
#define DIO_u8CHANNEL17            17	//PC1
#define DIO_u8CHANNEL18            18	//PC2
#define DIO_u8CHANNEL19            19	//PC3
#define DIO_u8CHANNEL20            20	//PC4
#define DIO_u8CHANNEL21            21	//PC5
#define DIO_u8CHANNEL22            22	//PC6
#define DIO_u8CHANNEL23            23	//PC7

/*PORTD*/
#define DIO_u8CHANNEL24            24	//PD0
#define DIO_u8CHANNEL25            25	//PD1
#define DIO_u8CHANNEL26            26	//PD2
#define DIO_u8CHANNEL27            27	//PD3
#define DIO_u8CHANNEL28            28	//PD4
#define DIO_u8CHANNEL29            29	//PD5
#define DIO_u8CHANNEL30            30	//PD6
#define DIO_u8CHANNEL31            31	//PD7



/*PROTOTYPES*/
Dio_tenuErrorStatus  Dio_enuWriteChannel(u8 Copy_u8ChannelId , u8 Copy_u8Level);
Dio_tenuErrorStatus  Dio_enuReadChannel(u8 Copy_u8ChannelId , pu8 Add_pu8ChannelLevel);
Dio_tenuErrorStatus  Dio_enuWritePort(u8 Copy_u8PortId , u8 Copy_u8Value);
Dio_tenuErrorStatus  Dio_enuReadPort(u8 Copy_u8PortId , pu8 Add_pu8PortValue);
Dio_tenuErrorStatus  Dio_enuFlipChannel(u8 Copy_u8ChannelId );


#endif /* MCAL_DIO_DRIVER_DIO_H_ */
