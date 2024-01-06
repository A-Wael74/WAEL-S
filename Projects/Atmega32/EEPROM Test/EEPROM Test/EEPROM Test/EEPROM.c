/*
 * EEPROM.c
 *
 * Created: 9/27/2023 10:13:45 PM
 *  Author: Wael
 */


#include "EEPROM.h"

void EEPROM_Write(u8 data,u16 addr)
{
	while(GET_BIT(EECR,EEWE));
	EEAR = addr;
	EEDR = data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
}

void EEPROM_Read (u8* data, u16 addr)
{
	while(GET_BIT(EECR,EEWE));
	EEAR = addr;
	SET_BIT(EECR,EERE);
	*data = EEDR;
}
