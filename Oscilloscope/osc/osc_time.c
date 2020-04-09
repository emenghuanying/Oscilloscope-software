/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
#include "fos.h"
#include "main.h"
#include "font.h"
#include "gui.h"
#include "display_dev.h"
/* Private includes ----------------------------------------------------------*/

#define UNIT_NS  (0)
#define UNIT_US  (1)
#define UNIT_MS  (2)
#define UNIT_SS  (3)

void LCD_ShowString(unsigned short x,unsigned short y,unsigned short width,unsigned short height,unsigned char size,unsigned char *p);
	
typedef struct 
{
	unsigned int unit;
	float time;
}SCAN_TIME_DEF;
/* scan time */
const SCAN_TIME_DEF csd[] = 
{
	/* 0 */
	{
		.unit = UNIT_US,
		.time = 2.5f,
	},
	/* 1 */
	{
		.unit = UNIT_US,
		.time = 5,
	},
	/* 2 */
	{
		.unit = UNIT_US,
		.time = 10,
	},
	/* 3 */
	{
		.unit = UNIT_US,
		.time = 25,
	},	
	/* 4 */
	{
		.unit = UNIT_US,
		.time = 50,
	},	
	/* 5 */
	{
		.unit = UNIT_US,
		.time = 100,
	},	
	/* 6 */
	{
		.unit = UNIT_US,
		.time = 250,
	},
	/* 7 */
	{
		.unit = UNIT_US,
		.time = 500,
	},	
	/* 8 */
	{
		.unit = UNIT_MS,
		.time = 1,
	},		
	/* 9 */
	{
		.unit = UNIT_MS,
		.time = 2.5f,
	},		
	/* 10 */
	{
		.unit = UNIT_MS,
		.time = 5,
	},		
};
/* set */
void set_scan_time(unsigned int index)
{
	if( index < sizeof(csd) / sizeof(csd[0]) )
	{
		/* psc */
		unsigned short psc = 0;
		unsigned char buffer[20];
		/* calbrate */
		if( csd[index].unit == UNIT_US )
		{
			psc = (unsigned short)((float)180 * csd[index].time / (float)75) / 2;
			
			if( index == 0 || index == 9 )
			{
			  sprintf(buffer,"M = %0.1fus   ",csd[index].time);
			}
			else
			{
				sprintf(buffer,"M = %dus   ",(unsigned short)csd[index].time);
			}
			
		}
		else if( csd[index].unit == UNIT_MS )
		{
			psc = (unsigned short)((float)180000 * csd[index].time / (float)75) / 2;
			
			if( index == 0 || index == 9 )
			{
			  sprintf(buffer,"M = %0.1fms   ",csd[index].time);
			}
			else
			{
				sprintf(buffer,"M = %dms   ",(unsigned short)csd[index].time);
			}
		}
		/* set time */
		TIM1->PSC = psc - 1;
		
		
		LCD_ShowString(360,433,200,16,16,buffer);
	}
}

extern gui_dev_def * dev;

void LCD_ShowChar(unsigned short x,unsigned short y,unsigned char num,unsigned char size,unsigned char mode)
{  							  
  unsigned char temp,t1,t;
	unsigned short y0=y;
	unsigned char csize=(size/8+((size%8)?1:0))*(size/2);
 	num=num-' ';
	for(t=0;t<csize;t++)
	{   
		
		temp=asc2_1608[num][t];

		for(t1=0;t1<8;t1++)
		{			    
			if(temp&0x80)dev->set_point(x,y,RGB(199, 195, 199));
			else if(mode==0)dev->set_point(x,y,RGB(7, 3, 7));
			temp<<=1;
			y++;
			if(y>=dev->height)return;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				if(x>=dev->width)return;
				break;
			}
		}  	 
	}  	    	   	 	  
} 

void LCD_ShowString(unsigned short x,unsigned short y,unsigned short width,unsigned short height,unsigned char size,unsigned char *p)
{         
	unsigned char x0=x;
	width+=x;
	height+=y;
    while((*p<='~')&&(*p>=' '))//判断是不是非法字符!
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//退出
        LCD_ShowChar(x,y,*p,size,0);
        x+=size/2;
        p++;
    }  
}
















