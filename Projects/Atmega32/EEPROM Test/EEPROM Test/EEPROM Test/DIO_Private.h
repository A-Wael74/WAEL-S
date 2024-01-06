/*
 * DIO_Private.h
 *
 * Created: 7/29/2022 4:42:20 PM
 *  Author: Ahmed Wael
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_type PinStatusArray[TOTAL_PINS];
static void DIO_InitPin(DIO_Pins_type pin, DIO_PinStatus_type status);

#endif /* DIO_PRIVATE_H_ */