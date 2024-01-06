/*
 * LCD.h
 *
 * Created: 8/9/2022 8:35:40 PM
 *  Author: Ahmed Wael
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO_Interface.h"
#define  F_CPU 8000000
#include <util/delay.h>

#define _8_BIT 1
#define _4_BIT 0

/********************MODE CFG**************************/
#define LCD_MODE _4_BIT

/********************PIN CFG**************************/
#define RS PINA1
#define EN PINA2

//IF MODE 8
#define LCD_PORT PA  
      
// IF MODE 4
#define D7 PINA6		
#define D6 PINA5
#define D5 PINA4
#define D4 PINA3
/*******************END OF CFG**********************/


void LCD_Init();

void LCD_WriteNumber(s32 num); 
void LCD_WriteNumber_4D(u16 num);
void LCD_WriteBinary(u8 num);
void LCD_WriteHex(u16 num);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(c8* str);
void LCD_Clear();
void LCD_SetCursor(u8 line, u8 cell);
void LCD_SetLine(u8 line);

void LCD_MovingChar(u8 startcell, u8 movingChar, u8 endChar);
void AddChar();






#endif /* LCD_H_ */