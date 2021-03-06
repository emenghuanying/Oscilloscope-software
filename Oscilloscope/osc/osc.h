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

#ifndef __OSC_H__
#define __OSC_H__
/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

#include "gui_dev.h"
#include "gui.h"
/* Define the area information occupied by the drawing area of the current screen */
typedef struct
{
	unsigned short start_pos_x;
	unsigned short start_pos_y;
	unsigned short stop_pos_x;
	unsigned short stop_pos_y;  
	unsigned short num_vertical;
	unsigned short num_horizontal;
	unsigned short pixel_vertiacl;
	unsigned short pixel_horizontal;
	unsigned short little_grid;
	unsigned short rev0;
	unsigned short rev1;
}draw_area_def;


/* create grid data */
int create_grid_data(gui_dev_def * dev);
int draw_group_win(gui_dev_def * dev,gui_info_def * info);
int draw_menu_win( gui_dev_def * dev,gui_info_def * info );
void osc_calculate_main_size(gui_dev_def * dev,window_def * win,void * draw,unsigned short wf);
void osc_calculate_sg_size(gui_dev_def * dev,window_def * win0,window_def * win1,window_def * win2,window_def * win3,void * draw);
void osc_calculate_menu_size(gui_dev_def * dev,window_def * win,void * draw,unsigned short wf);
void osc_calculate_btn_size(gui_dev_def * dev,window_def * win,widget_def *wd,unsigned short btn_num);

#endif
































