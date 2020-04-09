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
#include "stdafx.h"
/* Includes ------------------------------------------------------------------*/
#include "fos.h"
#include "osc.h"
#include "osc_ui.h"
#include "gui.h"
#include "hz_out.h"
#include "string.h"
#include "math.h"
#include "display_dev.h"
#include "main.h"
#include "myiic.h"

int sce_cof(void);
void low_level_gpio_config(void);
void TIM_PWM_Init(void);
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim);

TIM_HandleTypeDef TIM_Handle; 
TIM_OC_InitTypeDef TIM_OC_Handle; 
void DAC1_Init(void);
void EXTI_Init(void);
void DAC_Update(unsigned short volA,unsigned short B,unsigned short C,unsigned short D);
void set_scan_time(unsigned int index);
void osc_create_ch1_a(void);

/* Private includes ----------------------------------------------------------*/
FOS_INODE_REGISTER("osc_ui",osc_create_ui,sce_cof,0,1);
/* define win */
window_def win_main;
window_def win_group0;
window_def win_group1;
window_def win_group2;
window_def win_group3;
window_def win_group4;
window_def win_group5;
window_def win_menu;
/* btn */
widget_def btn[6];

/* ch1 and ch2 icon */
widget_def ch1_icon;
widget_def ch2_icon;
widget_def ch3_icon;

widget_def ch4_icon;
widget_def ch5_icon;
widget_def ch6_icon;

widget_def ch7_icon;
widget_def ch8_icon;
/* gui dev */
gui_dev_def * dev;

static unsigned short oac[4] = {1870,2000,0,270};
#if 0
void draw_hz(const char * hzd,unsigned short x,unsigned short y);
const char * find_hz(char * da);
#endif

/* osc create ui */
int osc_create_ui(void)
{
	/* gui dev get */
  dev = get_gui_dev();
	/* calculate main size */
  osc_calculate_main_size(dev,&win_main,osc_main_draw,0);
	/* create the group */
	osc_calculate_sg_size(dev,&win_group0,&win_group1,&win_group2,&win_group3,osc_group_draw);	
	/* 480 * 272 do not create the follow mesure group */
	if( dev->width > 480 && dev->width > 272 )
	{
		/* create the group */
		win_group4.msg.x = 1;
		win_group4.msg.y = dev->height - 62 - 6 - 22*2 - 4 - 1;
		win_group4.msg.x_size = win_group1.msg.x_size;
		win_group4.msg.y_size = 62;
		win_group4.dev = dev;
		win_group4.msg.wflags = GUI_HIDE;
		/* set callback */
		win_group4.draw = osc_group_draw;
		/* create */
		gui_win_creater(&win_group4);		
		/* create the group */
		win_group5.msg.x = win_group2.msg.x;
		win_group5.msg.y = dev->height - 62 - 6 - 22*2 - 4 - 1;
		win_group5.msg.x_size = win_group1.msg.x_size;
		win_group5.msg.y_size = 62;
		win_group5.dev = dev;
		win_group5.msg.wflags = GUI_HIDE;
		/* set callback */
		win_group5.draw = osc_group_draw;
		/* create */
		gui_win_creater(&win_group5);			
	}
	/* create the menu win ui */
  osc_calculate_menu_size(dev,&win_menu,osc_menu_win_draw,GUI_HIDE);
	/* btn */
  osc_calculate_btn_size(dev,&win_menu,btn,sizeof(btn) / sizeof(btn[0]));
	/* create icon ch1 */
	ch1_icon.msg.x = 6;
	ch1_icon.msg.y = 3;
  ch1_icon.dev = dev;
	ch1_icon.draw = osc_create_ch1_micon;
	ch1_icon.parent = &win_group4;

	gui_widget_creater(&ch1_icon);

	ch2_icon.msg.x = 6;
	ch2_icon.msg.y = 3 + 16 + 4;
    ch2_icon.dev = dev;
	ch2_icon.draw = osc_create_ch1_micon;
	ch2_icon.parent = &win_group4;

	gui_widget_creater(&ch2_icon);
	
	ch3_icon.msg.x = 6;
	ch3_icon.msg.y = 3 + 32 + 8;
    ch3_icon.dev = dev;
	ch3_icon.draw = osc_create_ch1_micon;
	ch3_icon.parent = &win_group4;

	gui_widget_creater(&ch3_icon);

	memcpy(&ch4_icon,&ch1_icon,sizeof(ch1_icon));
	memcpy(&ch5_icon,&ch2_icon,sizeof(ch2_icon));
	memcpy(&ch6_icon,&ch3_icon,sizeof(ch3_icon));

	ch4_icon.draw = osc_create_ch2_micon;
	ch5_icon.draw = osc_create_ch2_micon;
	ch6_icon.draw = osc_create_ch2_micon;
	ch4_icon.parent = &win_group5;
	ch5_icon.parent = &win_group5;
	ch6_icon.parent = &win_group5;
	ch4_icon.peer_linker = 0;
	ch5_icon.peer_linker = 0;
	ch6_icon.peer_linker = 0;
	/* create */
	gui_widget_creater(&ch4_icon);
	gui_widget_creater(&ch5_icon);
	gui_widget_creater(&ch6_icon);
	/* create */
	ch7_icon.msg.x = 8;
	ch7_icon.msg.y = 3;
	ch7_icon.dev = dev;
	ch7_icon.draw = osc_create_ch1_micon;
	ch7_icon.parent = &win_group1;
	gui_widget_creater(&ch7_icon);

	ch8_icon.msg.x = 8 + 160;
	ch8_icon.msg.y = 3;
	ch8_icon.dev = dev;
	ch8_icon.draw = osc_create_ch2_micon;
	ch8_icon.parent = &win_group1;
	gui_widget_creater(&ch8_icon);
	
	low_level_gpio_config();
	TIM_PWM_Init();
	HAL_TIM_PWM_MspInit(&TIM_Handle);	
	DAC1_Init();
	
	IIC_Init();
	
	DAC_Update(oac[0],oac[1],oac[2],oac[3]);
	
	EXTI_Init();
	osc_create_ch1_a();
	/* return */
	return FS_OK;
}
/* draw function */
static void osc_main_draw(window_def * win)
{
	/* create lisn */
	create_grid_data(win->dev);
	osc_create_ch1_a();
	/* end if data */
}
/* draw group */
static void osc_group_draw(window_def * win)
{
	draw_group_win(win->dev,&win->msg);
}
/* static draw menu win */
static void osc_menu_win_draw(window_def * win)
{
	draw_menu_win(win->dev,&win->msg);
}
#if 0
void draw_hz(const char * hzd,unsigned short x,unsigned short y)
{
	int ti = 0;
   for( int i = 0 ; i < 32 ; i ++ )
	{
		for( int j = 0 ; j < 8 ; j ++ )
		{
			if( ( hzd[i] << j ) & 0x80 )
			{
				dev->set_point(x+ti/16,y+ti%16,0xFFFF);
			}
			ti++;
		}
	}
}
#endif

extern const unsigned char CH1_ARROW[480];

/* create icon */
void osc_create_ch1_a(void)
{
	/* color tmp */
	unsigned short * color = (unsigned short *)CH1_ARROW;
	/* widget pos */
	unsigned short pos_x = 0;
	unsigned short pos_y = 266 - 6;
	/* create */
	for( int i = 0 ; i < 12 ; i ++ )
	{
		for( int j = 0 ; j < 20 ; j ++ )
		{
#ifndef _VC_SIMULATOR_
			dev->set_point(pos_x + j , pos_y + i , color[i*20+j]);
#else
			unsigned short tm = color[i*32+j];

			widget->dev->set_point(parent_x + pos_x + j , parent_y + pos_y + i , RGB((tm&0xF100) >> 8 ,(tm&0x7E0) >> 3 , (tm&0x1F) << 3 ));
#endif
		}
	}
}

draw_area_def * get_draw_area_msg(void);
void gui_test(void);
	
FOS_TSK_REGISTER(gui_test,PRIORITY_1,100);

volatile unsigned int cnt_p = 0;

extern unsigned short gram[800*480*3];

unsigned short * osc_arr = &gram[800*480];

int LCD_DrawLine_ili(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2,unsigned int color,gui_dev_def * dev,unsigned int got)
{
 unsigned short t;
 static int len_pixel = 0;
 int xerr=0,yerr=0,delta_x,delta_y,distance;
 int incx,incy,uRow,uCol;
 delta_x=x2-x1;
 delta_y=y2-y1;
 uRow=x1;
 uCol=y1;
 if(delta_x>0)incx=1;
 else if(delta_x==0)incx=0;
 else {incx=-1;delta_x=-delta_x;}
 if(delta_y>0)incy=1;
 else if(delta_y==0)incy=0;
 else{incy=-1;delta_y=-delta_y;} 
 if( delta_x>delta_y)distance=delta_x;
 else distance=delta_y; 

 len_pixel = 0;

 /*------------------*/
 unsigned char to = got % 5;
 /*------------------*/
 
 for(t=0;t<=distance+1;t++ )
 {  
   
	volatile unsigned short dtes = osc_arr[uRow + uCol*dev->width];
	 
	if( osc_arr[uRow + uCol*dev->width] & 0x8000 )
	{
		continue;
	}
	 
	if( osc_arr[uRow + uCol*dev->width] & 0x001f )
	{
		osc_arr[uRow + uCol*dev->width] |= (1<<to);
		
		if( osc_arr[uRow + uCol*dev->width] & (1<<to) )
		{
			
		}
	}
	else
	{
		if( 1)//got == 0 )
		{
       dev->set_point(uRow,uCol,RGB(255,255,7));
		}else
		{
			 dev->set_point(uRow,uCol,RGB(7,227,231));
		}
		osc_arr[uRow + uCol*dev->width] |= (1<<to);
		
		dtes = osc_arr[uRow + uCol*dev->width];
  }
	
  len_pixel++;

  xerr+=delta_x ; 
  yerr+=delta_y ; 
  if(xerr>distance) 
  { 
   xerr-=distance; 
   uRow+=incx; 
  } 
  if(yerr>distance) 
  { 
   yerr-=distance; 
   uCol+=incy; 
  } 
 }  

 return len_pixel;
}


int LCD_DrawLine_cleat(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2,unsigned int color,gui_dev_def * dev,unsigned int got)
{
 unsigned short t;
 static int len_pixel = 0;
 int xerr=0,yerr=0,delta_x,delta_y,distance;
 int incx,incy,uRow,uCol;
 delta_x=x2-x1;
 delta_y=y2-y1;
 uRow=x1;
 uCol=y1;
 if(delta_x>0)incx=1;
 else if(delta_x==0)incx=0;
 else {incx=-1;delta_x=-delta_x;}
 if(delta_y>0)incy=1;
 else if(delta_y==0)incy=0;
 else{incy=-1;delta_y=-delta_y;} 
 if( delta_x>delta_y)distance=delta_x;
 else distance=delta_y; 

 len_pixel = 0;

 /*------------------*/
 unsigned char to = got % 5;
 /*------------------*/
 
 for(t=0;t<=distance+1;t++ )
 {  

	 
	 volatile unsigned short dtes = osc_arr[uRow + uCol*dev->width];

	if( osc_arr[uRow + uCol*dev->width] & 0x8000 )
	{
		continue;
	}	 
	 
	if( osc_arr[uRow + uCol*dev->width] & 0x001f )
	{
		osc_arr[uRow + uCol*dev->width] &=~ (1<<to);
		
		if( !(osc_arr[uRow + uCol*dev->width] & 0x1F) )
		{
			if( osc_arr[uRow + uCol*dev->width] & 0x0400 )
			{
				dev->set_point(uRow,uCol,RGB(7,3,7));
			}
			else
			{
				dev->set_point(uRow,uCol,RGB(199, 195, 199));
			}
		}
		else
		{
			//dev->set_point(uRow,uCol,RGB(0, 255, 0));
		}
	}
	else
	{
//    dev->set_point(uRow,uCol,color);
//		osc_arr[uRow + uCol*dev->width] |= (1<<to);
		//dev->set_point(uRow,uCol,RGB(0, 0, 255));
  }
	
	osc_arr[uRow + uCol*dev->width] &=~ (1<<to);
	
  len_pixel++;

  xerr+=delta_x ; 
  yerr+=delta_y ; 
  if(xerr>distance) 
  { 
   xerr-=distance; 
   uRow+=incx; 
  } 
  if(yerr>distance) 
  { 
   yerr-=distance; 
   uCol+=incy; 
  } 
 }  

 return len_pixel;
}

static unsigned short color_cnt = 10000;

draw_area_def * msg_area;


double parse = 0.0;
void create_osc_grid_status(void);

int sce_cof(void)
{
	create_osc_grid_status();
	return 0;
}

unsigned short line_show[5][800];

int create_sin_lines(unsigned short * dft,const signed char * dil,signed short zk)
{

	#if 0
	
	msg_area = get_draw_area_msg();
	
  /* draw other grid data */
	double sin_x = 0;
	unsigned short line_t = 0xffff;
	/* sinx */
	for( int i = 0 ; i < msg_area->pixel_horizontal * msg_area->num_horizontal ; i ++ )
	{
	
	 double te = sin( sin_x + parse );
		
   short tm = (short)( te * msg_area->pixel_vertiacl * msg_area->num_vertical / 1 ) + msg_area->pixel_vertiacl * msg_area->num_vertical / 2;
		
		
		tm += (i%2)?10:(-10);
//	 double tce = cos( sin_x );
//		
//   short tcm = (short)( tce * EM * (VERTICAL_GRID_TOTAL / 4) ) + EM * (VERTICAL_GRID_TOTAL / 2) + TOP_REMAIN_PIXEL + 1 + EM*LITTLE_GRIG_NUM;	 
		
//		dev->set_point( msg_area->start_pos_x + i , msg_area->start_pos_y + tm , RGB(255,255,7));
 
		if( line_t != 0xffff )
		{
			LCD_DrawLine_ili(msg_area->start_pos_x + i,msg_area->start_pos_y + tm , msg_area->start_pos_x + i - 1 ,msg_area->start_pos_y + line_t,color_cnt++,dev,gor);
		}
    
		line_t = tm;
//		dev->set_point( LEFT_REMAIN_PIXEL + 1 + i , tcm , RGB(7,227,231));
		
		sin_x += (6.28) / (double)(msg_area->pixel_horizontal * msg_area->num_horizontal) * 3;
		parse -= 0.0001;
	}
	
	return 0;
#else
	msg_area = get_draw_area_msg();
//	double sin_x = 0;
//	/* sinx */
//	for( int i = 0 ; i < msg_area->pixel_horizontal * msg_area->num_horizontal ; i ++ )
//	{
//		 double te = sin( sin_x + parse );
//		
//     short tm = (short)( te * msg_area->pixel_vertiacl * msg_area->num_vertical / 2 ) + msg_area->pixel_vertiacl * msg_area->num_vertical / 2;

//     tm += (i%2)?5:(-5);	
//		
//		  dft[i] = tm;
//		
//		  sin_x += (6.28) / (double)(msg_area->pixel_horizontal * msg_area->num_horizontal) * 3;
//	}
//	
//	parse -= 0.6;

  for( int i = 0 ; i < msg_area->pixel_horizontal * msg_area->num_horizontal ; i ++ )
	{
		 
		unsigned short tm = msg_area->pixel_vertiacl * msg_area->num_vertical - (float)(dil[i] + 128) / (255.0f) * msg_area->pixel_vertiacl * msg_area->num_vertical;
		
		dft[i] = tm + zk;
		
		if( dft[i] > msg_area->pixel_vertiacl * msg_area->num_vertical )
		{
			dft[i] = msg_area->pixel_vertiacl * msg_area->num_vertical;
		}
		
		if( dft[i] < 0 )
		{
			dft[i] = 0;
		}
	}

#endif
	
	return 0;
}


void show_line(unsigned short * line_d,unsigned short index)
{
	msg_area = get_draw_area_msg();
	
	for( int i = 0 ; i < msg_area->pixel_horizontal * msg_area->num_horizontal - 1 ; i ++ )
	{
		LCD_DrawLine_ili(msg_area->start_pos_x + i,msg_area->start_pos_y + line_d[i] , msg_area->start_pos_x + i + 1 ,msg_area->start_pos_y + line_d[i+1],color_cnt,dev,index);
	}
	
	color_cnt += 700;
}

void hide_line(unsigned short * line_d,unsigned short index)
{
	msg_area = get_draw_area_msg();
	
	for( int i = 0 ; i < msg_area->pixel_horizontal * msg_area->num_horizontal - 1 ; i ++ )
	{
		LCD_DrawLine_cleat(msg_area->start_pos_x + i,msg_area->start_pos_y + line_d[i] , msg_area->start_pos_x + i + 1 ,msg_area->start_pos_y + line_d[i+1],color_cnt++,dev,index);
	}
}

unsigned short dfefef;

void create_osc_grid_status(void)
{
	
	memset(osc_arr,0,800*480*2);
	
	for( int i = 0 ; i < dev->height ; i ++ )
	{
		for( int j = 0 ; j < dev->width ; j ++ )
		{
			if( gui_find_connect(&win_main,j,i) == 1)
			{
				osc_arr[i*dev->width + j] |= 0x8000;
			}
			else
			{
				osc_arr[i*dev->width + j] &=~ 0x8000;
			}
			
			if( gram[i*dev->width + j] == RGB(7,3,7) )
			{
				osc_arr[i*dev->width + j] |= 0x0400;
			}
			else if( gram[i*dev->width + j] == RGB(199, 195, 199) )
			{
				osc_arr[i*dev->width + j] &=~ 0x0400;
			}
			else
			{
				osc_arr[i*dev->width + j] |= 0x8000;
			}
		}
	}
}

void low_level_gpio_config(void)
{
		GPIO_InitTypeDef GPIO_Initure;

		__HAL_RCC_LTDC_CLK_ENABLE();                //使能LTDC时钟
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();               //使能GPIOB时钟
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();
		__HAL_RCC_GPIOF_CLK_ENABLE();               //使能GPIOF时钟
		__HAL_RCC_GPIOG_CLK_ENABLE();               //使能GPIOG时钟
		__HAL_RCC_GPIOH_CLK_ENABLE();               //使能GPIOH时钟
		__HAL_RCC_GPIOI_CLK_ENABLE();               //使能GPIOI时钟

		/* DIO-D0~D7 */
		GPIO_Initure.Pin=GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13;               
		GPIO_Initure.Mode=GPIO_MODE_INPUT;     
		GPIO_Initure.Pull=GPIO_PULLUP;                  
		GPIO_Initure.Speed=GPIO_SPEED_HIGH;         
		HAL_GPIO_Init(GPIOC,&GPIO_Initure);	
		/* full0 */
		GPIO_Initure.Pin=GPIO_PIN_9;
		HAL_GPIO_Init(GPIOF,&GPIO_Initure);	
		
		GPIO_Initure.Pin=GPIO_PIN_0;
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);	

		GPIO_Initure.Pin=GPIO_PIN_8;
		HAL_GPIO_Init(GPIOH,&GPIO_Initure);

		GPIO_Initure.Pin=GPIO_PIN_12;
		HAL_GPIO_Init(GPIOB,&GPIO_Initure);	
		
		/* KEY RUN and AUTO */
		GPIO_Initure.Pin=GPIO_PIN_7;
		HAL_GPIO_Init(GPIOF,&GPIO_Initure);	
		
		GPIO_Initure.Pin=GPIO_PIN_2;
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);	
		
		HAL_GPIO_WritePin(GPIOF,GPIO_PIN_7,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET);
		
		GPIO_Initure.Pin=GPIO_PIN_1;
		HAL_GPIO_Init(GPIOC,&GPIO_Initure);			
		/* output */		
    /*--------------------------------------------------------------*/		
		/* OE0 */
//		GPIO_Initure.Pin=GPIO_PIN_7;
//		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
//		HAL_GPIO_Init(GPIOB,&GPIO_Initure);
//		/* OE1 */
//		GPIO_Initure.Pin=GPIO_PIN_1;
//		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;
//		HAL_GPIO_Init(GPIOC,&GPIO_Initure);		
//		/* OE2 OE3 */
//		GPIO_Initure.Pin=GPIO_PIN_7|GPIO_PIN_13;
//		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;
//		HAL_GPIO_Init(GPIOD,&GPIO_Initure);

//		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
//		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_7|GPIO_PIN_13,GPIO_PIN_SET);
		/*---------------------------------------------------------------*/
		/* RST */
		GPIO_Initure.Pin=GPIO_PIN_1;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOB,&GPIO_Initure);	

		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);
		/*--------------------------------------------------------------*/
		/* TR */
    GPIO_Initure.Pin=GPIO_PIN_7;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);	

		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
		/* R0 R1 */
    GPIO_Initure.Pin=GPIO_PIN_11|GPIO_PIN_8;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOI,&GPIO_Initure);	
		
		/* R2 */
    GPIO_Initure.Pin=GPIO_PIN_15;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOB,&GPIO_Initure);		
    
		/* R3 */
    GPIO_Initure.Pin=GPIO_PIN_3;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOG,&GPIO_Initure);	 
		
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11|GPIO_PIN_8,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_SET);
		
		/*------------------------------------------------------------*/
		/*DCACA B offset */
		GPIO_Initure.Pin=GPIO_PIN_4;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOB,&GPIO_Initure);
    
    GPIO_Initure.Pin=GPIO_PIN_3;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOI,&GPIO_Initure);	 		
		
		
		GPIO_Initure.Pin=GPIO_PIN_3;
		HAL_GPIO_Init(GPIOA,&GPIO_Initure);

		GPIO_Initure.Pin=GPIO_PIN_5;
		HAL_GPIO_Init(GPIOB,&GPIO_Initure);
		
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_3,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4 ,GPIO_PIN_RESET);
		
		/* CPC */
    GPIO_Initure.Pin=GPIO_PIN_0;
		GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP; 
		HAL_GPIO_Init(GPIOB,&GPIO_Initure);		
		
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);//select PWM
		/* */
}

void delay_us(unsigned int t)
{
	t *=100;
	
	while(t--);
}

unsigned char r0_com[4096];
unsigned char r0n_com[4096];

void read_R0(signed char *data,signed char * data_n,signed char * data_2,signed char * data_2n)
{
	unsigned char bit_q[8];
	
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_RESET);//TR
	
	//oe_select(0);
	
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11,GPIO_PIN_SET);
	
	for( int i = 0 ; i < 4096 ; i ++ )
	{
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11,GPIO_PIN_RESET);
		delay_us(1);
		unsigned char temp = ( GPIOC->IDR & ( 0xFF << 6 ) ) >> 6;
		/* */
		bit_q[7] = ( temp & ( 1 << 3 )) >> 3;
		bit_q[6] = ( temp & ( 1 << 7 )) >> 7;
		bit_q[5] = ( temp & ( 1 << 2 )) >> 2;
		bit_q[4] = ( temp & ( 1 << 6 )) >> 6;
		bit_q[3] = ( temp & ( 1 << 1 )) >> 1;
		bit_q[2] = ( temp & ( 1 << 5 )) >> 5;
		bit_q[1] = ( temp & ( 1 << 0 )) >> 0;
		bit_q[0] = ( temp & ( 1 << 4 )) >> 4;
		/*  */
		unsigned char temp2 = ( bit_q[7] << 7 ) | 
			                    ( bit_q[6] << 6 ) |
													( bit_q[5] << 5 ) |
													( bit_q[4] << 4 ) |
													( bit_q[3] << 3 ) |
													( bit_q[2] << 2 ) |
													( bit_q[1] << 1 ) |
													( bit_q[0] << 0 );
		/* set */
		data[i] = (signed char)temp2;
		
		r0_com[i] = (GPIOC->IDR & (1<<5)) ? 92:0;
		
		/* ------ */
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_11,GPIO_PIN_SET);
		delay_us(1);
	}

	/* read channel a nes */
//	oe_select(1);
	
  HAL_GPIO_WritePin(GPIOI,GPIO_PIN_8,GPIO_PIN_SET);
	
	for( int i = 0 ; i < 4096 ; i ++ )
	{
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_8,GPIO_PIN_RESET);
		delay_us(1);
		unsigned char temp = ( GPIOC->IDR & ( 0xFF << 6 ) ) >> 6;
		
		unsigned char tem2 = ((temp & 0xf0) >> 4 ) | ((temp & 0x0f) << 4 );
			
		data_n[i] = (signed char)(tem2);
		
		r0n_com[i] = (GPIOC->IDR & (1<<5)) ? 92:0;
		
		/* ------ */
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_8,GPIO_PIN_SET);
		delay_us(1);
	}
#if 1		
	/* read oe2 */
//	oe_select(2);
	
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
	
	for( int i = 0 ; i < 4096 ; i ++ )
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_RESET);
		delay_us(1);
		unsigned char temp = ( GPIOC->IDR & ( 0xFF << 6 ) ) >> 6;
		/* set */
		data_2[i] =(signed char)( ( temp & 0xF ) << 4 ) | ( temp >> 4 );
		/* ------ */
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);
		delay_us(1);
	}	
	
	/* read oe4 */
//	oe_select(3);
	
	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_SET);
	
	for( int i = 0 ; i < 4096 ; i ++ )
	{
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_RESET);
		delay_us(1);
		unsigned char temp = ( GPIOC->IDR & ( 0xFF << 6 ) ) >> 6;
		/* */
		bit_q[7] = ( temp & ( 1 << 3 )) >> 3;
		bit_q[6] = ( temp & ( 1 << 7 )) >> 7;
		bit_q[5] = ( temp & ( 1 << 2 )) >> 2;
		bit_q[4] = ( temp & ( 1 << 6 )) >> 6;
		bit_q[3] = ( temp & ( 1 << 1 )) >> 1;
		bit_q[2] = ( temp & ( 1 << 5 )) >> 5;
		bit_q[1] = ( temp & ( 1 << 0 )) >> 0;
		bit_q[0] = ( temp & ( 1 << 4 )) >> 4;
		/*  */
		unsigned char temp2 = ( bit_q[7] << 7 ) | 
			                    ( bit_q[6] << 6 ) |
													( bit_q[5] << 5 ) |
													( bit_q[4] << 4 ) |
													( bit_q[3] << 3 ) |
													( bit_q[2] << 2 ) |
													( bit_q[1] << 1 ) |
													( bit_q[0] << 0 );
		/* set */
		data_2n[i] = (signed char)temp2;
		/* ------ */
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_SET);
		delay_us(1);
	}	
#endif
}


void TIM_PWM_Init(void)
{
	    TIM_Handle.Channel = HAL_TIM_ACTIVE_CHANNEL_1;
	    TIM_Handle.Instance = TIM1; 
	    TIM_Handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; 
	    TIM_Handle.Init.CounterMode = TIM_COUNTERMODE_UP; 
	    TIM_Handle.Init.Period = 1; 
	    TIM_Handle.Init.Prescaler = 600-1;//5; //500us
    	HAL_TIM_PWM_Init(&TIM_Handle);
	
	   
	    TIM_OC_Handle.OCMode = TIM_OCMODE_PWM1; 
	    TIM_OC_Handle.OCPolarity = TIM_OCPOLARITY_HIGH; 
	    TIM_OC_Handle.Pulse = 1;
	    HAL_TIM_PWM_ConfigChannel(&TIM_Handle, &TIM_OC_Handle, TIM_CHANNEL_1); 
	
	    HAL_TIM_PWM_Start(&TIM_Handle, TIM_CHANNEL_1);
	
//	   TIM_HandleTypeDef TIM_Handle_TIM2;
//	
//	    TIM_Handle_TIM2.Channel = HAL_TIM_ACTIVE_CHANNEL_2;
//	    TIM_Handle_TIM2.Instance = TIM2; 
//	    TIM_Handle_TIM2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; 
//	    TIM_Handle_TIM2.Init.CounterMode = TIM_COUNTERMODE_UP; 
//	    TIM_Handle_TIM2.Init.Period = 999; 
//	    TIM_Handle_TIM2.Init.Prescaler = 89; 
//    	HAL_TIM_PWM_Init(&TIM_Handle_TIM2);
//	
//	   
//	    TIM_OC_Handle.OCMode = TIM_OCMODE_PWM1; 
//	    TIM_OC_Handle.OCPolarity = TIM_OCPOLARITY_HIGH; 
//	    TIM_OC_Handle.Pulse = 499;
//	    HAL_TIM_PWM_ConfigChannel(&TIM_Handle_TIM2, &TIM_OC_Handle, TIM_CHANNEL_2); 
//	
//	    HAL_TIM_PWM_Start(&TIM_Handle_TIM2, TIM_CHANNEL_2);	   
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
	    GPIO_InitTypeDef GPIO_Handle;
	
	    if(htim->Instance == TIM1)
	    {
		    __HAL_RCC_GPIOF_CLK_ENABLE();
		    __HAL_RCC_TIM1_CLK_ENABLE();
		
		    GPIO_Handle.Pin = GPIO_PIN_8; // PF9
		    GPIO_Handle.Mode = GPIO_MODE_AF_PP;
		    GPIO_Handle.Pull = GPIO_PULLUP;
		    GPIO_Handle.Speed = GPIO_SPEED_HIGH;
		    GPIO_Handle.Alternate = GPIO_AF1_TIM1;
		    HAL_GPIO_Init(GPIOA, &GPIO_Handle);
	    }else if(htim->Instance == TIM2)
			{
		    __HAL_RCC_GPIOA_CLK_ENABLE();
		    __HAL_RCC_TIM2_CLK_ENABLE();
		
		    GPIO_Handle.Pin = GPIO_PIN_1; // PF9
		    GPIO_Handle.Mode = GPIO_MODE_AF_PP;
		    GPIO_Handle.Pull = GPIO_PULLUP;
		    GPIO_Handle.Speed = GPIO_SPEED_HIGH;
		    GPIO_Handle.Alternate = GPIO_AF1_TIM1;
		    HAL_GPIO_Init(GPIOA, &GPIO_Handle);				
			}
}
signed char read_r0_data[4096];
signed char read_r0n_data[4096];
signed char read_r1_data[4096];
signed char read_r1n_data[4096];

signed char red_r0[8192];
signed char red_r1[8192];

signed char red_tr0[8192];
signed char red_tr1[8192];

unsigned char red_r_com[8192];


unsigned char fls = 0;

DAC_HandleTypeDef DAC1_Handler;


void DAC1_Init(void)
{
    DAC_ChannelConfTypeDef DACCH1_Config;
    
    DAC1_Handler.Instance=DAC;
    HAL_DAC_Init(&DAC1_Handler);  
    
    DACCH1_Config.DAC_Trigger=DAC_TRIGGER_NONE;   
    DACCH1_Config.DAC_OutputBuffer=DAC_OUTPUTBUFFER_DISABLE;
    HAL_DAC_ConfigChannel(&DAC1_Handler,&DACCH1_Config,DAC_CHANNEL_1);
    
    HAL_DAC_Start(&DAC1_Handler,DAC_CHANNEL_1);
}

void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac)
{      
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_DAC_CLK_ENABLE(); 
    __HAL_RCC_GPIOA_CLK_ENABLE();
	
    GPIO_Initure.Pin=GPIO_PIN_4;
    GPIO_Initure.Mode=GPIO_MODE_ANALOG;
    GPIO_Initure.Pull=GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
}

void DAC1_Set_Vol(unsigned short vol)
{
	double temp=vol;
	temp/=1000;
	temp=temp*4096/3.3;
    HAL_DAC_SetValue(&DAC1_Handler,DAC_CHANNEL_1,DAC_ALIGN_12B_R,temp);
}

void dac_out(void)
{
	//double te = sin( sin_x + parse );
	static unsigned short dac_o = 0;
	
	DAC1_Set_Vol(dac_o);
	
	dac_o += 330;
	
	if( dac_o >= 3300 )
	{
		dac_o = 0;
	}
}


void DAC_Update(unsigned short volA,unsigned short B,unsigned short C,unsigned short D)
{
	unsigned short outA = volA,outB = B,outC = C,outD = D;
	
	IIC_Start();
	
	IIC_Send_Byte(0xC0);
	
	IIC_Wait_Ack();
	
	IIC_Send_Byte(0x40);

	IIC_Wait_Ack();
	
	IIC_Send_Byte(0x80 | (outA&0x0f00) >>8);
	
	IIC_Wait_Ack();
	
	IIC_Send_Byte( outA & 0xff );	

	IIC_Wait_Ack();	
	
	/* out B */
  IIC_Send_Byte(0x42);

	IIC_Wait_Ack();
	
	IIC_Send_Byte(0x80 | (outB&0x0f00) >>8);
	
	IIC_Wait_Ack();
	
	IIC_Send_Byte( outB & 0xff );	

	IIC_Wait_Ack();		
	
	/* outC */
  IIC_Send_Byte(0x44);

	IIC_Wait_Ack();
	
	IIC_Send_Byte(0x80 | (outC&0x0f00) >>8);
	
	IIC_Wait_Ack();
	
	IIC_Send_Byte( outC & 0xff );	

	IIC_Wait_Ack();	
	/* outD */
  IIC_Send_Byte(0x46);

	IIC_Wait_Ack();
	
	IIC_Send_Byte(0x80 | (outD&0x0f00) >>8);
	
	IIC_Wait_Ack();
	
	IIC_Send_Byte( outD & 0xff );	

	IIC_Wait_Ack();		
/* stop */	
	IIC_Stop();
}

void EXTI_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOA_CLK_ENABLE();             
    __HAL_RCC_GPIOF_CLK_ENABLE();             
  
    
    GPIO_Initure.Pin=GPIO_PIN_1;                
    GPIO_Initure.Mode=GPIO_MODE_IT_RISING;     
    GPIO_Initure.Pull=GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOA,&GPIO_Initure);
    
    GPIO_Initure.Pin=GPIO_PIN_6;                
    GPIO_Initure.Mode=GPIO_MODE_IT_RISING;      
    GPIO_Initure.Pull=GPIO_PULLDOWN;
    HAL_GPIO_Init(GPIOF,&GPIO_Initure);
   
//	  GPIO_Initure.Pin=GPIO_PIN_2;  
//	  HAL_GPIO_Init(GPIOD,&GPIO_Initure);
	
	  
    HAL_NVIC_SetPriority(EXTI1_IRQn,0,0);       
    HAL_NVIC_EnableIRQ(EXTI1_IRQn);            
  
//    HAL_NVIC_SetPriority(EXTI2_IRQn,0,0);       
//    HAL_NVIC_EnableIRQ(EXTI2_IRQn); 

    HAL_NVIC_SetPriority(EXTI9_5_IRQn,0,0);       
    HAL_NVIC_EnableIRQ(EXTI9_5_IRQn); 

//    HAL_NVIC_SetPriority(EXTI15_10_IRQn,0,0);  
//    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);        
}


FOS_TSK_REGISTER(dac_out,PRIORITY_0,1);

unsigned char t_flag = 0;

volatile unsigned int int_cnt0 = 7;//500us
volatile unsigned int rota_0_time_cnt = 100;

unsigned char rota_flag = 0;

unsigned int cnt_rodd = 0;

unsigned char flg = 0;

void gui_test(void)
{
	//dev->clear_display_dev(0);
	//create_sin_lines(cnt_p);
	
	//memset(&gram[800*480],color_cnt++,800*480*2);
	
	//dev->fill_color(msg_area->start_pos_x,msg_area->start_pos_y,msg_area->stop_pos_x,msg_area->stop_pos_y,&gram[800*480]);
	
	if( (!(GPIOF->IDR & (1<<6))) && (!(GPIOA->IDR & (1<<1))) )
	{
		rota_flag = 0;
		
		if( flg == 0 )
		{
		  set_scan_time(int_cnt0);
			flg = 1;
		}
		
	}
			
  static unsigned short la[4];
	
	if( la[0] !=  oac[0] || la[1] !=  oac[1] || la[2] !=  oac[2] || la[3] !=  oac[3] )
	{
		DAC_Update(oac[0],oac[1],oac[2],oac[3]);
	}
		
	la[0] = oac[0];
	la[1] = oac[1];
	la[2] = oac[2];
	la[3] = oac[3];
	
//  DAC1_Set_Vol(3300/2);	
	
 if( !(GPIOF->IDR & (1<<9) ))
 {
	
  HAL_TIM_PWM_Stop(&TIM_Handle, TIM_CHANNEL_1);
	 
	read_R0(read_r0_data ,read_r0n_data, read_r1_data , read_r1n_data );	
	
	unsigned short td = 0; 
	
//	unsigned int trig_index_1 = 0, trig_index_0 = 0;

//	for( int i = 0 ; i < 3000 ; i ++ )
//	{
//		if( (r0_com[i] == 0 ) && ( r0_com[i+1] == 1 ) )
//		{
//			td = i;
//			break;
//		}
//	}	 
	 
	 
	if( fls == 0 )
	{
		for( int i = 0 ; i < 1600 ; i ++  )
		{
			if( (i % 2) == 1 )
			{			
				red_r0[i] = read_r0_data[td];
				red_r1[i] = read_r1_data[td];
				red_r_com[i] = r0_com[td];
				td ++;
			}
			else
			{
				red_r0[i] = read_r0n_data[td];
				red_r1[i] = read_r1n_data[td];
				red_r_com[i] = r0n_com[td];
			}
		}		
 }
 else
 {
	
	td = 0;
	
  for( int i = 0 ; i < 8190 ; i ++  )
  {
		if( (i % 2) == 0 )
		{			
		  red_r0[i] = read_r0_data[td];
			red_r1[i] = read_r1_data[td];
			red_r_com[i] = r0_com[td];
		}
		else
		{
			red_r0[i] = read_r0n_data[td];
			red_r1[i] = read_r1n_data[td];
			red_r_com[i] = r0n_com[td];
			td ++;
		}
	}	
 }
 
// for( int i = 0 ; i < 750/15 ; i ++)
// {
//	 for( int j = 0 ; j < 15 ; j ++ )
//	 {
//		 red_tr0[i*15+j] = red_r0[i];
//		 red_tr1[i*15+j] = red_r1[i];
//	 }
// }
 
 unsigned int pos_r = 375;
 
 	for( int i = 375 ; i < 8192-375 ; i ++ )
	{
		if( (red_r_com[i] == 0 ) && ( red_r_com[i+1] == 92 ) )
		{
			pos_r = i;
			break;
		}
	}	
 
	if( cnt_p >= 2  )
	{
		hide_line(line_show[cnt_p%2],cnt_p%2);
		//hide_line(line_show[1],1);
		//hide_line(line_show[2],2);
	}
	
	create_sin_lines(line_show[cnt_p%2],&red_r0[pos_r-375+5],cnt_p%2);
	
	show_line(line_show[cnt_p%2],cnt_p%2);

	cnt_p++;
	
//	create_sin_lines(line_show[1],&red_r1[pos_r-375+5],100);

//	show_line(line_show[1],1);

	if( GPIOC->IDR & (1<<1))
	{
		fls = 1;
	}
	else
	{
		fls = 0;
	}
	
	/*-------------------------------*/
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,GPIO_PIN_SET);
	/*-------------------------------*/
	//delay_us(1000);
  /* ------------------------------- */
	HAL_TIM_PWM_Start(&TIM_Handle, TIM_CHANNEL_1);
  }
}

void EXTI1_IRQHandler(void)
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);

	if( rota_flag == 0 )
	{
		if( int_cnt0 < 10 )
		{
		  int_cnt0++;
			flg = 0;
		}
		
		rota_flag  = 1;
	}
}

void EXTI9_5_IRQHandler(void)
{
	 HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);//调用中断处理公用函数
	
	 if( rota_flag == 0 )
	 {  
		  if( int_cnt0 > 0 )
			{
			  int_cnt0--;
				flg = 0;
			}
			
		  rota_flag = 1;
	 }
}





































