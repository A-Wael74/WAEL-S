/*
 * LCD.c
 *
 * Created: 8/9/2022 8:35:18 PM
 *  Author: Ahmed Wael
 */ 

#include "LCD.h"
//////////////////////////////////////////////
#if LCD_MODE == _8_BIT

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init() 
{
	_delay_ms(35);
	LCD_WriteCommand(0x38);  //2-Lines
	LCD_WriteCommand(0x0C);
	LCD_WriteCommand(0x01);
	_delay_ms(1);
	LCD_WriteCommand(0x06); // INC ddram address
	                                        
}

//////////////////////////////////////////////
#elif LCD_MODE == _4_BIT
 void LCD_WriteCommand(u8 command) ////////////////statttiicccc
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,GET_BIT(command,7));
	DIO_WritePin(D6,GET_BIT(command,6));
	DIO_WritePin(D5,GET_BIT(command,5));
	DIO_WritePin(D4,GET_BIT(command,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,GET_BIT(command,3));
	DIO_WritePin(D6,GET_BIT(command,2));
	DIO_WritePin(D5,GET_BIT(command,1));
	DIO_WritePin(D4,GET_BIT(command,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,GET_BIT(data,7));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
	DIO_WritePin(D7,GET_BIT(data,3));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init()
{
		_delay_ms(35);
		LCD_WriteCommand(0x02); 
		LCD_WriteCommand(0x28);  //2-Lines
		LCD_WriteCommand(0x0C);
		LCD_WriteCommand(0x01);
		_delay_ms(1);
		LCD_WriteCommand(0x06); // INC ddram address
	
}

#endif
//////////////////////////////////////////////

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}


void LCD_WriteNumber(s32 num) 
{
	u8 i, str[20];
	s8 j;
	if (num == 0)
	{
		LCD_WriteChar('0');
	}
	else
	{
		if (num < 0)
		{
			num = num*-1;
			LCD_WriteChar('-');
		}
		for (i = 0; num>0 ;i++ )
		{
			str[i] = ((num%10)+'0');
			num = num/10;
		}
		for (j = i-1; j>= 0;j--)
		{
			LCD_WriteChar(str[j]);
		}
	}
}

void LCD_WriteString(c8* str)
{
	u8 i;
	for(i = 0 ;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
}

void LCD_WriteHex(u16 num)
{
	u8 i = 0, str[16],rem;
	s8 j;
	while (num)
	{
		rem = num%16;
		if (rem <= 9)
		{
			str[i] = rem + '0';
		}
		else
		{
			str[i] = rem +'A'-10;
		}
		num = num / 16;
		i++;
	}
	for(j = i-1; j>= 0;j--)
	{
		LCD_WriteChar(str[j]);
	}
}

void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i = 7; i >= 0; i--)
	{
		if (num & (1<<i))
		{
			LCD_WriteChar('1');
		}
		else
		{
			LCD_WriteChar('0');
		}
	}
}

void LCD_SetCursor(u8 line, u8 cell)
{
	if (line == 0)
	{
		LCD_WriteCommand(0x80+cell);
	}
	else if(line == 1)
	{
		LCD_WriteCommand(0x80+0x40+cell);
	}
}

void LCD_Clear()
{
	LCD_WriteCommand(0x01);
}

void LCD_WriteNumber_4D(u16 num)
{
	u16 rem;
	num = num%10000;
	rem = num/1000;
	LCD_WriteNumber(rem);
	num = num %1000;
	rem = num/100;
	LCD_WriteNumber(rem);
	num = num%100;
	rem = num/10;
	LCD_WriteNumber(rem);
	num = num%10;
	LCD_WriteNumber(num);
}
	
void LCD_MovingChar(u8 startcell, u8 movingChar, u8 endChar)
{
	u8 i;
	for( i = startcell; i<= 15; i++)
	{
		LCD_WriteChar(movingChar);
		_delay_ms(500);
		LCD_SetCursor(0,i);
		LCD_WriteString(" ");
		if (i == 14)
		{
			LCD_WriteChar(endChar);
			break;
		}
	}
}

void LCD_SetLine(u8 line)
{
	if (line == 0)
	{
		LCD_WriteCommand(0x80);
	}
	else if(line == 1)
	{
		LCD_WriteCommand(0x80+0x40);
	}
}
	
	
// void LCD_WriteNumber_4D(u16 num)
// {
// 	u8 rem;
// 	LCD_WriteCommand(0x83);
// 	rem = num%10;
// 	LCD_WriteNumber(rem);
// 	num = num/10;
// 	//
// 	LCD_WriteCommand(0x82);
// 	rem = num%10;
// 	LCD_WriteNumber(rem);
// 	num = num/10;
// 	//
// 	LCD_WriteCommand(0x81);
// 	rem = num%10;
// 	LCD_WriteNumber(rem);
// 	num = num/10;
// 	//
// 	LCD_WriteCommand(0x80);
// 	rem = num%10;
// 	LCD_WriteNumber(rem);
// 	
// }
