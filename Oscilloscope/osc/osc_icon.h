/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : notify.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
	* BEEP TIM3 CHANNEL1 PWM Gerente
	* LED is TIM4 CH3 and CH4
  */
#ifndef __OSC_ICON_H__
#define __OSC_ICON_H__	

/* Includes ------------------------------------------------------------------*/

/* Private includes ----------------------------------------------------------*/

/* 32 * 16 RGB565 */
const unsigned char CH1_ICON_M[1024] = { /* 0X00,0X10,0X20,0X00,0X10,0X00,0X01,0X1B, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X83,0X31,0X07,0XC6,
0XE4,0XE6,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0XE4,0XE6,
0X07,0XC6,0X83,0X31,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC7,0X9C,0X42,0XEF,0XB5,0XF7,
0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,
0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,
0XB5,0XF7,0X42,0XEF,0XC7,0X9C,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XA8,0XBD,0X62,0XF7,0XD8,0XF7,0XDB,0XF7,
0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,
0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,0XDB,0XF7,
0XDB,0XF7,0XD8,0XF7,0X62,0XF7,0XA8,0XBD,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XA6,0X73,0X22,0XEF,0XB1,0XF7,0XB3,0XF7,0XB3,0XF7,
0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0X32,0XE7,
0XE1,0X18,0X8B,0X94,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,0XB3,0XF7,
0XB3,0XF7,0XB3,0XF7,0XB1,0XF7,0X22,0XEF,0XA6,0X73,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XE4,0XE6,0X88,0XF7,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,
0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0X8C,0XD6,0X62,0X29,
0X00,0X00,0X07,0X7C,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,
0XAE,0XF7,0XAE,0XF7,0XAE,0XF7,0X88,0XF7,0XE4,0XE6,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X05,0X63,0X22,0XEF,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,
0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X87,0XD6,0X00,0X00,0X01,0X42,
0X00,0X00,0XE4,0X7B,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,
0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X22,0XEF,0X05,0X63,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X47,0XAD,0X42,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,
0X84,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,0X04,0XE7,0X02,0XA5,0X63,0XCE,
0X00,0X00,0XE1,0X7B,0X84,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,
0X84,0XF7,0X84,0XF7,0X84,0XF7,0X84,0XF7,0X42,0XF7,0X47,0XAD,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X47,0XAD,0X42,0XEF,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,
0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X02,0XE7,0X62,0XF7,
0X00,0X00,0XE1,0X7B,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,
0X62,0XF7,0X62,0XF7,0X62,0XF7,0X62,0XF7,0X42,0XF7,0X47,0XAD,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X48,0XAD,0X22,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,
0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,
0X00,0X00,0XC0,0X7B,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,
0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X22,0XEF,0X48,0XAD,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X68,0XB5,0X22,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,
0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,
0X00,0X00,0XC0,0X7B,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,
0X21,0XEF,0X21,0XEF,0X21,0XEF,0X21,0XEF,0X22,0XEF,0X68,0XB5,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X26,0X6B,0X42,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X00,0X00,0XA0,0X73,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X42,0XEF,0X26,0X6B,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X45,0XEF,0X21,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X00,0X00,0XA0,0X73,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X21,0XEF,0X45,0XEF,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X08,0X84,0X63,0XF7,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X21,0XC6,0X41,0XCE,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X63,0XF7,0X08,0X84,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X4B,0XCE,0X85,0XF7,0X21,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X21,0XEF,0X85,0XF7,0X4B,0XCE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XAC,0XB5,0X8D,0XF7,0X63,0XF7,
0X22,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X22,0XEF,
0X63,0XF7,0X8D,0XF7,0XAC,0XB5,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X25,0X42,0XF0,0XE6,
0XB4,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,
0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB6,0XF7,0XB4,0XF7,
0XF0,0XE6,0X25,0X42,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};
/* 32 * 16 RGB565 */
const unsigned char CH2_ICON_M[1024] = { /* 0X00,0X10,0X20,0X00,0X10,0X00,0X01,0X1B, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X86,0X21,0XD8,0X95,
0XDC,0X9E,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0XDC,0X9E,
0XD8,0X95,0X86,0X21,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X93,0X74,0X5E,0X9F,0XBE,0XDF,
0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,
0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,
0XBE,0XDF,0X5E,0X9F,0X93,0X74,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X76,0X85,0X7E,0XA7,0XDE,0XE7,0XDE,0XEF,
0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,
0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,0XDE,0XEF,
0XDE,0XEF,0XDE,0XE7,0X7E,0XA7,0X76,0X85,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X6E,0X5B,0X3D,0X9F,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,
0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0X38,0XAE,0X65,0X21,0X00,0X00,
0X00,0X00,0X65,0X21,0X3C,0XC7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,
0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0X3D,0X9F,0X6E,0X5B,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XDC,0X9E,0X9E,0XB7,0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,
0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,0X65,0X21,0X28,0X32,0X39,0X9E,
0XD7,0X95,0X24,0X19,0XCB,0X42,0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,
0X9E,0XC7,0X9E,0XC7,0X9E,0XC7,0X9E,0XB7,0XDC,0X9E,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0XEB,0X4A,0X3D,0X9F,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,
0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0XDC,0XA6,0X5A,0X96,0X7E,0XB7,
0X9E,0XB7,0X8E,0X53,0XC2,0X08,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,
0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X3D,0X9F,0XEB,0X4A,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X15,0X7D,0X5E,0X9F,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,
0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,
0X7E,0XAF,0XCB,0X3A,0XE7,0X29,0X5E,0XA7,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,
0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X7E,0XAF,0X5E,0X9F,0X15,0X7D,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X15,0X7D,0X5E,0X9F,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,
0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,
0XF4,0X6C,0X00,0X00,0XD4,0X64,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,
0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X5E,0X9F,0X15,0X7D,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X35,0X7D,0X3D,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,
0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0XD7,0X7D,
0X41,0X00,0XF0,0X53,0XBB,0X8E,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,
0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X3D,0X9F,0X35,0X7D,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X35,0X7D,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,
0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X31,0X5C,0X41,0X00,
0X8E,0X4B,0X7A,0X8E,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,
0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X3D,0X9F,0X35,0X7D,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X0C,0X53,0X5E,0X9F,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0XAF,0X4B,0X00,0X00,0X72,0X5C,
0X5A,0X86,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X5E,0X9F,0X0C,0X53,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X3D,0XA7,0X3D,0X9F,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X41,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X3D,0X9F,0X3D,0XA7,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XF0,0X6B,0X7E,0XA7,0X1D,0X9F,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X39,0X86,0XD8,0X7D,0XD8,0X7D,
0XD8,0X7D,0XD8,0X7D,0XD8,0X7D,0XBB,0X8E,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X9F,0X7E,0XA7,0XF0,0X6B,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X38,0X9E,0X9E,0XAF,0X3D,0X9F,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X3D,0X9F,0X9E,0XAF,0X38,0X9E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X76,0X95,0X9E,0XC7,0X7E,0XA7,
0X3D,0X9F,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X3D,0X9F,
0X7E,0XA7,0X9E,0XC7,0X76,0X95,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X28,0X3A,0XFB,0XC6,
0XBE,0XD7,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,
0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XDF,0XBE,0XD7,
0XFB,0XC6,0X28,0X3A,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
};
/* ch1 arrow 20 * 12 RGB565 */
const unsigned char CH1_ARROW[480] = { /* 0X00,0X10,0X14,0X00,0X0C,0X00,0X01,0X1B, */
0X6D,0XD6,0X89,0XF7,0X89,0XF7,0X89,0XF7,0X89,0XF7,0X89,0XF7,0X89,0XF7,0X89,0XF7,
0X89,0XF7,0X89,0XF7,0X89,0XF7,0X89,0XF7,0X04,0XE7,0XCC,0XB5,0X50,0X5B,0X52,0X3A,
0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X99,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,
0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,0X31,0X84,0X04,0X21,0XDE,0XF7,0XDE,0XF7,
0XDE,0XF7,0XB4,0XF7,0X03,0XE7,0XCF,0X73,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,
0X32,0XE7,0XD8,0XF7,0XD8,0XF7,0XD8,0XF7,0XD8,0XF7,0XD8,0XF7,0XD8,0XF7,0X0D,0X84,
0X00,0X00,0XE2,0X18,0X97,0XF7,0XD8,0XF7,0XD8,0XF7,0XD8,0XF7,0XAD,0XF7,0X03,0XE7,
0XCF,0X73,0X52,0X3A,0X52,0X3A,0X52,0X3A,0XCF,0XDE,0XAF,0XF7,0XAF,0XF7,0XAF,0XF7,
0XAF,0XF7,0XAF,0XF7,0X06,0X5B,0X02,0X21,0XA3,0X31,0XC1,0X18,0X6F,0XF7,0XAF,0XF7,
0XAF,0XF7,0XAF,0XF7,0XAF,0XF7,0X86,0XF7,0X03,0XE7,0XCF,0X73,0X52,0X3A,0X52,0X3A,
0XAD,0XD6,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X25,0XA5,0X26,0XC6,
0X83,0X6B,0XC0,0X18,0X68,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,0X88,0XF7,
0X63,0XF7,0X03,0XEF,0X70,0X63,0X52,0X3A,0X8D,0XD6,0X63,0XF7,0X63,0XF7,0X63,0XF7,
0X63,0XF7,0X63,0XF7,0X23,0XEF,0X63,0XF7,0XA1,0X73,0XC0,0X18,0X43,0XEF,0X63,0XF7,
0X63,0XF7,0X63,0XF7,0X63,0XF7,0X63,0XF7,0X63,0XF7,0X42,0XF7,0X2D,0X9D,0X52,0X3A,
0X6C,0XCE,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,
0X81,0X73,0XC0,0X18,0X02,0XE7,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,0X42,0XEF,
0X42,0XEF,0X22,0XEF,0X2D,0X9D,0X52,0X3A,0X6C,0XCE,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X80,0X73,0XC0,0X18,0XE1,0XE6,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X22,0XEF,0X06,0XEF,0XB1,0X4A,0X52,0X3A,
0X6C,0XCE,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X80,0X73,0XC0,0X18,0XE1,0XE6,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X42,0XEF,
0X26,0XEF,0XF1,0X4A,0X52,0X3A,0X52,0X3A,0X6D,0XD6,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X80,0X73,0XC0,0X18,0XE1,0XE6,0X01,0XEF,
0X01,0XEF,0X01,0XEF,0X63,0XF7,0X48,0XF7,0XF1,0X52,0X52,0X3A,0X52,0X3A,0X52,0X3A,
0XAD,0XD6,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,0X01,0XEF,
0XC1,0XDE,0XC1,0XBD,0XE1,0XE6,0X01,0XEF,0X42,0XEF,0X87,0XF7,0X6D,0XF7,0XF1,0X52,
0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0XB1,0XD6,0XB4,0XF7,0XB4,0XF7,0XB4,0XF7,
0XB4,0XF7,0XB4,0XF7,0XB4,0XF7,0XB4,0XF7,0XB4,0XF7,0XB4,0XF7,0XB4,0XF7,0XB4,0XF7,
0X52,0XEF,0X92,0XAD,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,
};
/* ch2 arrow 20 * 12 RGB565 */
const unsigned char CH2_ARROW[480] = { /* 0X00,0X10,0X14,0X00,0X0C,0X00,0X01,0X1B, */
0X5B,0XA6,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,
0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0XFC,0X9E,0XB9,0X8D,0XD3,0X42,0X52,0X3A,
0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X9E,0XE7,0XDE,0XF7,0XDE,0XF7,0XDE,0XF7,
0XDE,0XF7,0XDE,0XF7,0X8E,0X6B,0X00,0X00,0X00,0X00,0X00,0X00,0XB2,0X94,0XDE,0XF7,
0XDE,0XF7,0XBE,0XDF,0XDC,0X9E,0XD3,0X42,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,
0X1D,0XC7,0XDE,0XE7,0XDE,0XE7,0XDE,0XE7,0XDE,0XE7,0X34,0X95,0X00,0X00,0X55,0X9D,
0X59,0XB6,0XD0,0X6B,0X00,0X00,0XBA,0XC6,0XDE,0XE7,0XDE,0XE7,0X9E,0XC7,0XDC,0X9E,
0XD3,0X42,0X52,0X3A,0X52,0X3A,0X52,0X3A,0XDC,0XB6,0XBE,0XCF,0XBE,0XCF,0XBE,0XCF,
0XBE,0XCF,0XBE,0XCF,0X9A,0XAE,0XBB,0XAE,0XBE,0XCF,0X9E,0XC7,0X00,0X00,0X11,0X64,
0XBE,0XCF,0XBE,0XCF,0XBE,0XCF,0X9E,0XAF,0XDC,0X9E,0XD3,0X42,0X52,0X3A,0X52,0X3A,
0XBB,0XAE,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,
0X9E,0XB7,0X9A,0X9E,0X00,0X00,0X14,0X75,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,0X9E,0XB7,
0X7E,0XA7,0XDC,0X9E,0XB2,0X42,0X52,0X3A,0X7B,0XAE,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,
0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X86,0X21,0X49,0X32,0X9B,0X8E,
0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X7E,0XA7,0X5E,0X9F,0X17,0X7D,0X52,0X3A,
0X5A,0XA6,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,
0XCC,0X3A,0X65,0X19,0XF8,0X7D,0X1D,0X97,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,0X5E,0X9F,
0X5E,0X9F,0X3D,0X9F,0X18,0X7D,0X52,0X3A,0X5A,0XA6,0X1D,0X9F,0X1D,0X9F,0X1D,0X9F,
0X1D,0X9F,0X1D,0X9F,0XBB,0X8E,0XE8,0X29,0X65,0X19,0X76,0X75,0XBB,0X8E,0X1D,0X9F,
0X1D,0X9F,0X1D,0X9F,0X1D,0X9F,0X1D,0X9F,0X3D,0X9F,0XFC,0XA6,0XB2,0X42,0X52,0X3A,
0X5A,0XA6,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X9B,0X8E,0XE4,0X10,0XC7,0X21,
0XD8,0X7D,0X9B,0X8E,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X3D,0X9F,
0X1D,0XA7,0XD3,0X42,0X52,0X3A,0X52,0X3A,0X7A,0XA6,0X1D,0X97,0X1D,0X97,0X1D,0X97,
0X1D,0X97,0XB0,0X4B,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XB0,0X4B,
0X1D,0X97,0X1D,0X97,0X5E,0X9F,0X3D,0XAF,0XF3,0X4A,0X52,0X3A,0X52,0X3A,0X52,0X3A,
0X9B,0XAE,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0X1D,0X97,0XD8,0X7D,0XD8,0X7D,
0XD8,0X7D,0XD8,0X7D,0XD8,0X7D,0XD8,0X7D,0X3D,0X9F,0X7E,0XA7,0X7E,0XBF,0XF3,0X4A,
0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X7C,0XB6,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,
0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,0XBE,0XD7,
0X9E,0XD7,0X7C,0XB6,0XF3,0X4A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,0X52,0X3A,
};

#endif



