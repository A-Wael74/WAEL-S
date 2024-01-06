/*
 * EEPROM Test.c
 *
 * Created: 9/27/2023 4:14:16 PM
 * Author : Wael
 */ 

#include "LCD.h"
#include "EEPROM.h"

#define STACK_Start (( u8*)0x8f)
#define STACK_End (( u8*)0x85f)


u8* stack_test()
{
	u8* ptr = STACK_Start;
	while (ptr<=STACK_End)
	{
		if(*ptr == 0x55)
		{
			ptr++;
			LCD_SetCursor(1,2);
			LCD_WriteNumber(ptr);
			LCD_SetCursor(1,9);
			LCD_WriteNumber(*ptr);
			_delay_ms(1);
		}
		else
		{
			return ptr;
		}
	}
}
int main(void)
{
	u8* ptr = STACK_Start;
	for(;ptr<=STACK_End;ptr++)
	{
		*ptr = 0x55;
	}
	
	DIO_Init();
    LCD_Init();
	
	
	
	LCD_WriteString("EEPROM TEST:");
	//_delay_ms(10000);
	LCD_SetCursor(1,0);
	EEPROM_Write(52,0);
	u8 x;
	volatile u8 x2=5;
	EEPROM_Read(&x,0);
	LCD_WriteNumber(x);
	
	DIO_WritePin(PINC2,HIGH);
	_delay_ms(5000);
	//LCD_Clear();
	//LCD_WriteString("STACK TEST");
	u8* ptr2 = stack_test();
	/*LCD_SetCursor(1,6);
	LCD_WriteNumber(*ptr2);*/
    while (1) 
    {
		
    }
	

}