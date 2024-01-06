/*
 * StopWatch.c
 *
 * Created: 7/31/2022 3:28:15 PM
 * Author : Ahmed Wael
 */ 

#define F_CPU 8000000
#include "StdTypes.h"
#include "Utils.h"
#include "MemMap.h"
#include "util/delay.h"
#define SEGMENT_PORT PORTA
#define SEGMENT_EN_PORT PORTC
#define SEGMENT_EN1 6
#define SEGMENT_EN2 7
s8 start_num = 30;
 void Segment_Display_MUL(u8 num)
{
	const u8 arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	u8 d1,d2;
	d1 = num%10;
	d2 = num/10;
	CLR_BIT(SEGMENT_EN_PORT,SEGMENT_EN2);
	SET_BIT(SEGMENT_EN_PORT,SEGMENT_EN1);
	SEGMENT_PORT = arr[d1]<<1;
	_delay_ms(1);
	CLR_BIT(SEGMENT_EN_PORT,SEGMENT_EN1);
	SET_BIT(SEGMENT_EN_PORT,SEGMENT_EN2);
	SEGMENT_PORT = arr[d2]<<1;
	_delay_ms(1);
}

void Stop_Watch (s8 num)
{
	s8 i;
	u16 j;
	for(i = num; i >= 0;i--)
	{
		for (j = 0; j < 500; j++)
		{
			Segment_Display_MUL(i);
		}
	}
}

void BUZZER_ON()
{
	u8 flag = 1;
	while(flag)  //BUZZER When 0
	{
		Segment_Display_MUL(0);
		SET_BIT(PORTC,5);
		if(!GET_BIT(PIND,3))
		{
			while(!GET_BIT(PIND,3));
			flag = 0;
			CLR_BIT(PORTC,5);
		}
		if(!GET_BIT(PIND,4))
		{
			while(!GET_BIT(PIND,4));
			flag = 0;
			CLR_BIT(PORTC,5);
		}
	}
}

void RESET (s8* i)
{
	u8 flag;
	if(!GET_BIT(PIND,3)) //RESET
	{
		while(!GET_BIT(PIND,3));
		flag = 1;
		*i = start_num;
		while(flag)
		{
			Segment_Display_MUL((*i));
			if(!GET_BIT(PIND,2))
			{
				while(!GET_BIT(PIND,2));
				flag = 0;
			}
		}
	}
}

void PAUSE_CONTINUE (s8* i)
{
	u8 flag;
	if (!GET_BIT(PIND,2)) //PAUSE AND CONTINUE
	{
		while(!GET_BIT(PIND,2));
		flag = 1;
		while(flag)
		{
			Segment_Display_MUL(*i);
			
			if(!GET_BIT(PIND,2))
			{
				while(!GET_BIT(PIND,2));
				flag = 0;
			}
			if(!GET_BIT(PIND,3))  //If Reset After Pause
			{
				while(!GET_BIT(PIND,3));
				*i = start_num;
			}
		}
	}
}
void INC_DEC (s8* start_num)
{
	Segment_Display_MUL(*start_num);
	if(!GET_BIT(PIND,2))
	{
		while(!GET_BIT(PIND,2))
		{
			(*start_num) ++;
			_delay_ms(200);
			Segment_Display_MUL(*start_num);
			if ((*start_num) == 99)
			{
				*start_num = 1;
			}
		}
	}
	else if (!GET_BIT(PIND,3))
	{
		while(!GET_BIT(PIND,3))
		{
			(*start_num) --;
			_delay_ms(200);
			Segment_Display_MUL(*start_num);
			if ((*start_num) == 0)
			{
				*start_num = 99;
			}
		}
	}
	
}

int main(void)
{
	DDRA = 0xff;
	DDRC = 0xff;
	DDRD = 0;
	s8 i;
	u16 j;
	u8 flag = 0;   //To Start with mode 2(choose the time)
	u8 flag2;
    while (1) 
    {
		if (!GET_BIT(PIND,4)) // To start the timer
		{
			while(!GET_BIT(PIND,4))
			flag = 1;
		}
		if (flag == 1)
		{
			for(i = start_num; i >= 0;i--)
			{
				for (j = 0; j < 500; j++)
				{
					Segment_Display_MUL(i);
					RESET(&i);
					PAUSE_CONTINUE(&i);
				}
			}
			flag2 = 1;
			while(flag2) // when timer finishes, user can either reset and start again or change the time
			{
				Segment_Display_MUL(0);
				SET_BIT(PORTC,5);
				if(!GET_BIT(PIND,4))
				{
					while(!GET_BIT(PIND,4));
					flag = 0;
					flag2 = 0;
					CLR_BIT(PORTC,5);
				}
				if(!GET_BIT(PIND,3))
				{
					while (!GET_BIT(PIND,3));
					RESET(&i);
					flag = 1;
					flag2 = 0;
					CLR_BIT(PORTC,5);
				}
				
			}
		}
		else if (flag == 0) //choose the time
		{
			INC_DEC(&start_num);
		}
		
    }
}

