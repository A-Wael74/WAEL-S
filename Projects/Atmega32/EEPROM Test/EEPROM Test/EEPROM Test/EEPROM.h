/*
 * EEPROM.h
 *
 * Created: 9/27/2023 10:13:58 PM
 *  Author: Wael
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"


void EEPROM_Write(u8 data,u16 addr);

void EEPROM_Read (u8* data, u16 addr);


#endif /* EEPROM_H_ */