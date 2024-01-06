/*
 * UART mini project.c
 *
 * Created: 9/30/2022 1:41:18 AM
 * Author : Ahmed Wael
 */ 

#define F_CPU 8000000
#include <util/delay.h>


#include "DIO_Interface.h"
#include "UART.h"
#include "LCD.h"


u8 str[20];
u8 s[20];
u16 num;
u8 flag = 0;
u8 flag2 = 0;


void LCD_WriteNumber2(u16 num)
{
	LCD_SetCursor(0,0);
	u8 i, str[20];
	s8 j;
	if (num == 0)
	{
		LCD_WriteChar('0');
		LCD_WriteString("           ");
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
		LCD_WriteString("           ");
	}
}

void ledon(u16 num)
{
	if(num>=0 && num<=7)
	{
		SET_BIT(PORTB,num);
	}
}
void ledoff(u16 num)
{
	if(num>=0 && num<=7)
	{
		CLR_BIT(PORTB,num);
	}
}


void relayon(u16 num)
{
	if (num == 1)
	{
		SET_BIT(PORTC,4);
	}
	else if(num == 2)
	{
		SET_BIT(PORTC,3);
	}
	
}


void relayoff(u16 num)
{
	if (num == 1)
	{
		CLR_BIT(PORTC,4);
	}
	else if(num == 2)
	{
		CLR_BIT(PORTC,3);
	}
	
}
 void buzzon(u16 num)
 {
	 SET_BIT(PORTC,5);
 }
 void buzzoff(u16 num)
 {
	 CLR_BIT(PORTC,5);
 }


void STR_Divide(u8* str,u8* s, u16*x)
{
	u8 j = 0;
	u8 i = 0;
	*x = 0;
	for(j; str[j];j++)
	{
		if(str[j] == ' ')
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		return;
	}
	while(str[i] != ' ')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	i++;
	while(str[i])
	{
		*x = (*x) * 10;
		*x = (str[i] - '0')+ (*x);
		i++;
	}
}



u8 Str_Compare(u8* str1, u8* str2)
{
	u8 i;
	for (i = 0 ; str1[i] || str2[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return 0;
		}
	}
	return 1;
}

typedef struct{
	u8 taskname[20];
	void (*Fptr)(u16 num);
	
	}task_type;

task_type tasks[] = {{"LedOn",ledon},
					 {"LedOff",ledoff},
					 {"BuzzerOn",buzzon},
					 {"BuzzerOff",buzzoff},
					 {"RelayOn",relayon},
					 {"RelayOff",relayoff},
					 {"LCDwrite",LCD_WriteNumber2}
					 };

int main(void)
{
	DIO_Init();
	UART_Init();
	LCD_Init();
	LCD_SetCursor(0,0);

	u8 i;
    while (1) 
    {
		UART_ReceiveStr(str);
		STR_Divide(str,s,&num);
		if(flag == 0)
		{
			LCD_SetCursor(1,0);
			LCD_WriteString("Wrong Input");
			LCD_WriteString("        ");
			continue;
		}
		LCD_SetCursor(1,0);
		LCD_WriteString(s);
		LCD_WriteString("       ");
		for (i=0 ; i < 7 ;i++)
		{
			if(Str_Compare(s,tasks[i].taskname))
			{
				tasks[i].Fptr(num);
				flag2 = 1;
			}
		}
		if(flag2 == 0)
		{
			LCD_SetCursor(1,0);
			LCD_WriteString("Wrong Input");
			LCD_WriteString("        ");
		}
		flag2 = 0;
		flag = 0;
    }
}

