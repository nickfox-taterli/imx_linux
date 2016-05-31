/*
 * Copyright (C) 2009-2010 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/delay.h>

#include <mach/pinctrl.h>

#include "mx28_pins.h"

static struct pin_desc mx28evk_fixed_pins[] = {
/*	{
//	 .name = "DUART.RX",
	 .name = "I2C1_SCL",
	 .id = PINID_PWM0,
//	 .fun = PIN_FUN3,
	 .fun = PIN_FUN2,
	 },
	{
//	 .name = "DUART.TX",
	 .name = "I2C1_SDA",
	 .id = PINID_PWM1,
//	 .fun = PIN_FUN3,
	 .fun = PIN_FUN2,
	 },*/
#ifdef CONFIG_MXS_AUART0_DEVICE_ENABLE
	{
	 .name  = "AUART0.RX",
	 .id    = PINID_AUART0_RX,
	 .fun   = PIN_FUN1,
	 },
	{
	 .name  = "AUART0.TX",
	 .id    = PINID_AUART0_TX,
	 .fun   = PIN_FUN1,
	 },
#endif
	{
	 .name  = "DUART.RX",
	 .id    = PINID_AUART0_CTS,
	 .fun   = PIN_FUN3,
	 },
	{
	 .name  = "DUART.TX",
	 .id    = PINID_AUART0_RTS,
	 .fun   = PIN_FUN3,
	 },
#if defined(CONFIG_MXS_AUART1_DEVICE_ENABLE)
        {
         .name = "AUART1.RX",
         .id = PINID_AUART1_RX,
         .fun           = PIN_FUN1,
         },
        {
         .name = "AUART1.TX",
         .id = PINID_AUART1_TX,
         .fun           = PIN_FUN1,
         },
#endif
/*
//RS485方向应由应用层控制,否则通用性不强，容易丢数据
//modify by hak
        {
         .name  = "RS485_DIR",
         .id    = PINID_LCD_D17,
         .fun   = PIN_GPIO,
         .strength = PAD_8MA,
         .voltage       = PAD_3_3V,
         .drive = 1,
         },
        {
         .name  = "RS485_DIR",
         .id    = PINID_LCD_D18,
         .fun   = PIN_GPIO,
         .strength = PAD_8MA,
         .voltage       = PAD_3_3V,
         .drive = 1,
         },
*/
#ifdef CONFIG_MXS_AUART3_DEVICE_ENABLE  //I.MX283 has no UART3
	{
	 .name  = "AUART3.RX",
	 .id    = PINID_AUART3_RX,
	 .fun   = PIN_FUN1,
	 },
	{
	 .name  = "AUART3.TX",
	 .id    = PINID_AUART3_TX,
	 .fun   = PIN_FUN1,
	 },
	{
	 .name  = "AUART3.CTS",
	 .id    = PINID_AUART3_CTS,
	 .fun   = PIN_FUN1,
	 },
	{
	 .name  = "AUART3.RTS",
	 .id    = PINID_AUART3_RTS,
	 .fun   = PIN_FUN1,
	 },
#endif
#if defined(CONFIG_MXS_AUART4_DEVICE_ENABLE)
        {
         .name = "AUART4.RX",
         .id = PINID_SAIF0_BITCLK,
         .fun           = PIN_FUN3,
         },
        {
         .name = "AUART4.TX",
         .id = PINID_SAIF0_SDATA0,
         .fun           = PIN_FUN3,
         },
#endif

#if defined(CONFIG_MXS_AUART2_DEVICE_ENABLE)
	{
	 .name = "AUART2.TX",
	 .id = PINID_AUART2_TX, /* Power enable pin*/
	 .fun = PIN_FUN1,
	 },
	 {
	 .name  = "AUART2.RX",
	 .id    = PINID_AUART2_RX,
	 .fun   = PIN_FUN1,
	 },
#endif

#if defined(CONFIG_USB_OTG)
	 {
	 .name 	= "usb0_id",
	 .id 	= PINID_PWM2,
	 .fun	= PIN_FUN2,
	 .data 	= 1,
	 .pull 	= 1,
	 .pullup = 1,
	 },
#endif
    {
       .name = "usb0",
       .id = PINID_PWM4, // Power enable pin
       .fun = PIN_GPIO,
       .data = 0,
       .output = 1,
    },


#if defined(CONFIG_USB_OTG)
	 {
	 .name 	= "usb0_id",
	 .id 	= PINID_PWM2,
	 .fun	= PIN_FUN2,
	 .data 	= 1,
	 .pull 	= 1,
	 .pullup = 1,
	 },
#endif
//283 has no flexcan 
#if defined(CONFIG_CAN_FLEXCAN) || defined(CONFIG_CAN_FLEXCAN_MODULE)
	{
	 .name	= "CAN1_TX",
	 .id	= PINID_GPMI_CE2N,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 1,
	 .pull 		= 0,
	 },
	{
	 .name	= "CAN1_RX",
	 .id	= PINID_GPMI_CE3N,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 1,
	 .pull 		= 0,
	 },
	{
	 .name	= "CAN0_TX",
	 .id	= PINID_GPMI_RDY2,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 1,
	 .pull 		= 0,
	 },
	{
	 .name	= "CAN0_RX",
	 .id	= PINID_GPMI_RDY3,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 1,
	 .pull 		= 0,
	 },
	{
	 .name	= "CAN_PWDN",
	 .id	= PINID_SSP1_CMD,
	 .fun	= PIN_GPIO,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 1,
	 .pull 		= 0,
	 .data		= 0,
	 .output	= 1,
	 },

#endif

#if defined(CONFIG_I2C_MXS) || \
	defined(CONFIG_I2C_MXS_MODULE)
	{
	 .name = "I2C0_SCL",
	 .id = PINID_I2C0_SCL,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "I2C0_SDA",
	 .id = PINID_I2C0_SDA,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
        //I2C1
	{
         .name = "I2C1_SCL",
         .id = PINID_PWM0,
         .fun = PIN_FUN2,
         },
        {
         .name = "I2C1_SDA",
         .id = PINID_PWM1,
         .fun = PIN_FUN2,
         },
#endif
#if defined(CONFIG_FB_MXS) || defined(CONFIG_FB_MXS_MODULE)
	{
	 .name  = "LCD_D00",
	 .id	= PINID_LCD_D00,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D01",
	 .id	= PINID_LCD_D01,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D02",
	 .id	= PINID_LCD_D02,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D03",
	 .id	= PINID_LCD_D03,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D04",
	 .id	= PINID_LCD_D04,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D05",
	 .id	= PINID_LCD_D05,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D06",
	 .id	= PINID_LCD_D06,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D07",
	 .id	= PINID_LCD_D07,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D08",
	 .id	= PINID_LCD_D08,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D09",
	 .id	= PINID_LCD_D09,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D10",
	 .id	= PINID_LCD_D10,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D11",
	 .id	= PINID_LCD_D11,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D12",
	 .id	= PINID_LCD_D12,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D13",
	 .id	= PINID_LCD_D13,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D14",
	 .id	= PINID_LCD_D14,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D15",
	 .id	= PINID_LCD_D15,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
/*
	{
	 .name  = "LCD_D16",
	 .id	= PINID_LCD_D16,
	 .fun	= PIN_GPIO,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D17",
	 .id	= PINID_LCD_D17,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D18",
	 .id	= PINID_LCD_D18,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D19",
	 .id	= PINID_LCD_D19,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D20",
	 .id	= PINID_LCD_D20,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D21",
	 .id	= PINID_LCD_D21,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D22",
	 .id	= PINID_LCD_D22,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name  = "LCD_D23",
	 .id	= PINID_LCD_D23,
	 .fun	= PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive	= 1,
	 },
*/
	{
	 .name = "LCD_RESET",
	 .id = PINID_LCD_RESET,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "LCD_VSYNC",
	 .id   = PINID_LCD_RD_E,
	 .fun  = PIN_FUN2,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "LCD_HSYNC",
	 .id = PINID_LCD_WR_RWN,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "LCD_ENABLE",
	 .id = PINID_LCD_CS,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "LCD_DOTCLK",
	 .id = PINID_LCD_RS,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "LCD_BACKLIGHT",
	 .id = PINID_PWM3,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
#endif
#if defined(CONFIG_MMC_MXS) || defined(CONFIG_MMC_MXS_MODULE)
	/* Configurations of SSP0 SD/MMC port pins */
	{
	 .name	= "SSP0_DATA0",
	 .id	= PINID_SSP0_DATA0,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP0_DATA1",
	 .id	= PINID_SSP0_DATA1,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP0_DATA2",
	 .id	= PINID_SSP0_DATA2,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP0_DATA3",
	 .id	= PINID_SSP0_DATA3,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
#if 0		// modefy by zhuguojun
	{
	 .name	= "SSP0_DATA4",
	 .id	= PINID_SSP0_DATA4,
	 //.fun	= PIN_FUN1,		//modefy by zhuguojun
	 .fun   = PIN_GPIO,		// modefy by zhuguojun
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP0_DATA5",
	 .id	= PINID_SSP0_DATA5,
	 //.fun	= PIN_FUN1,		// modefy by zhuuguojun
	 .fun   = PIN_GPIO,		// modefy by zhuguojun
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP0_DATA6",
	 .id	= PINID_SSP0_DATA6,
	 //.fun	= PIN_FUN1,
	 .fun   = PIN_GPIO,		// modefy by zhuguojun
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP0_DATA7",
	 .id	= PINID_SSP0_DATA7,
	 //.fun	= PIN_FUN1,
	 .fun   = PIN_GPIO,		// modefy by zhuguojun
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
#endif
	{
	 .name	= "SSP0_CMD",
	 .id	= PINID_SSP0_CMD,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP0_DETECT",
	 .id	= PINID_SSP0_DETECT,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 1,
	 .pull 		= 0,
	 },
	{
	 .name	= "SSP0_SCK",
	 .id	= PINID_SSP0_SCK,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 2,
	 .pull 		= 0,
	 },
#endif
#if defined(CONFIG_LEDS_MXS) || defined(CONFIG_LEDS_MXS_MODULE)
        {
         .name = "LEDS_RUN",
         .id = PINID_LCD_D22,
         .fun           = PIN_GPIO,
         .strength      = PAD_8MA,
         .voltage       = PAD_3_3V,
         .pullup        = 1,
         .drive         = 1,
         .pull          = 1,
         },
        {
         .name = "LEDS_ERR",
         .id = PINID_LCD_D23,
         .fun           = PIN_GPIO,
         .strength      = PAD_8MA,
         .voltage       = PAD_3_3V,
         .pullup        = 1,
         .drive         = 1,
         .pull          = 1,
         },
/*
	{
	 .name = "LEDS_PWM0",
	 .id = PINID_AUART1_RX,
	 .fun           = PIN_FUN3,
	 .strength      = PAD_8MA,
	 .voltage       = PAD_3_3V,
	 .pullup        = 1,
	 .drive         = 1,
	 .pull          = 1,
	 },
	{
	 .name = "LEDS_PWM1",
	 .id = PINID_AUART1_TX,
	 .fun           = PIN_FUN3,
	 .strength      = PAD_8MA,
	 .voltage       = PAD_3_3V,
	 .pullup        = 1,
	 .drive         = 1,
	 .pull          = 1,
	 },
*/
#endif

        {
         .name  = "BEEP",
         .id    = PINID_LCD_D21,
         .fun   = PIN_GPIO,
         .strength = PAD_8MA,
         .voltage       = PAD_3_3V,
         .drive = 1,
         },

/*
#if defined(CONFIG_SND_MXS_SOC_DAI) || defined(CONFIG_SND_MXS_SOC_DAI_MODULE)
	// Configurations of SAIF0 port pins 
	{
	 .name	= "SAIF0_MCLK",
	 .id	= PINID_SAIF0_MCLK,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SAIF0_LRCLK",
	 .id	= PINID_SAIF0_LRCLK,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SAIF0_BITCLK",
	 .id	= PINID_SAIF0_BITCLK,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SAIF0_SDATA0",
	 .id	= PINID_SAIF0_SDATA0,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SAIF1_SDATA0",
	 .id	= PINID_SAIF1_SDATA0,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
#endif
*/

#if defined(CONFIG_EASY283_PWM) || \
        defined(CONFIG_EASY283_PWM_MODULE)
	{
	 .name	= "PWM_4",
	 .id	= PINID_SAIF0_LRCLK,
	 .fun	= PIN_FUN2,//PWM_4
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "PWM_7",
	 .id	= PINID_SAIF1_SDATA0,
	 .fun	= PIN_FUN2,//PWM_7
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
#endif
#if defined(CONFIG_EASYARM_IMX283_GPIO)        
	{
         .name  = "GPIO3_20",
         .id    = PINID_SAIF0_MCLK,
         .fun   = PIN_GPIO,//PWM_3
         .strength      = PAD_12MA,
         .voltage       = PAD_3_3V,
         .pullup        = 1,
         .drive         = 1,
         .pull          = 1,
         },
#endif

#if defined(CONFIG_SND_SOC_MXS_SPDIF) || \
       defined(CONFIG_SND_SOC_MXS_SPDIF_MODULE)
	{
	 .name	= "SPDIF",
	 .id	= PINID_SPDIF,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	},
#endif
};

#if defined(CONFIG_FEC) || defined(CONFIG_FEC_MODULE)\
	|| defined(CONFIG_FEC_L2SWITCH)
static struct pin_desc mx28evk_eth_pins[] = {
	{
	 .name = "ENET0_MDC",
	 .id = PINID_ENET0_MDC,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET0_MDIO",
	 .id = PINID_ENET0_MDIO,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET0_RX_EN",
	 .id = PINID_ENET0_RX_EN,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET0_RXD0",
	 .id = PINID_ENET0_RXD0,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET0_RXD1",
	 .id = PINID_ENET0_RXD1,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET0_TX_EN",
	 .id = PINID_ENET0_TX_EN,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET0_TXD0",
	 .id = PINID_ENET0_TXD0,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET0_TXD1",
	 .id = PINID_ENET0_TXD1,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },
	{
	 .name = "ENET1_RX_EN",
	 .id = PINID_ENET0_CRS,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive = 1,
	 },
	{
	 .name = "ENET1_RXD0",
	 .id = PINID_ENET0_RXD2,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive = 1,
	 },
	{
	 .name = "ENET1_RXD1",
	 .id = PINID_ENET0_RXD3,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive = 1,
	 },
	{
	 .name = "ENET1_TX_EN",
	 .id = PINID_ENET0_COL,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive = 1,
	 },
	{
	 .name = "ENET1_TXD0",
	 .id = PINID_ENET0_TXD2,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive = 1,
	 },
	{
	 .name = "ENET1_TXD1",
	 .id = PINID_ENET0_TXD3,
	 .fun = PIN_FUN2,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive = 1,
	 },
	{
	 .name = "ENET_CLK",
	 .id = PINID_ENET_CLK,
	 .fun = PIN_FUN1,
	 .strength = PAD_8MA,
	 .pull = 1,
	 .pullup = 1,
	 .voltage = PAD_3_3V,
	 .drive	= 1,
	 },

	#if 0	//modefy by hak
        {
         .name = "PINID_SSP1_DATA3",
         .id = PINID_SSP1_DATA3,//公板将其用作Phy电源控制引脚
         .fun = PIN_GPIO,
         .strength = PAD_8MA,
         .pull = 1,
         .pullup = 1,
         .voltage = PAD_3_3V,
         .drive = 1,
         },

        {
         .name = "PINID_ENET0_RX_CLK",
         .id = PINID_ENET0_RX_CLK,//公板将其用作Phy中断信号
         .fun = PIN_GPIO,
         .strength = PAD_8MA,
         .pull = 1,
         .pullup = 1,
         .voltage = PAD_3_3V,
         .drive = 1,
         },
	#endif

};
#endif

static int __initdata enable_ssp1 = { 0 };
static int __init ssp1_setup(char *__unused)
{
	enable_ssp1 = 1;
	return 1;
}

__setup("ssp1", ssp1_setup);

static struct pin_desc mx28evk_ssp1_pins[] = {
	{
	 .name	= "SSP1_DATA0",
	 .id	= PINID_GPMI_D00,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DATA1",
	 .id	= PINID_GPMI_D01,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DATA2",
	 .id	= PINID_GPMI_D02,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DATA3",
	 .id	= PINID_GPMI_D03,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DATA4",
	 .id	= PINID_GPMI_D04,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DATA5",
	 .id	= PINID_GPMI_D05,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DATA6",
	 .id	= PINID_GPMI_D06,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DATA7",
	 .id	= PINID_GPMI_D07,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_CMD",
	 .id	= PINID_GPMI_RDY1,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 1,
	 .drive 	= 1,
	 .pull 		= 1,
	 },
	{
	 .name	= "SSP1_DETECT",
	 .id	= PINID_GPMI_RDY0,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 1,
	 .pull 		= 0,
	 },
	{
	 .name	= "SSP1_SCK",
	 .id	= PINID_GPMI_WRN,
	 .fun	= PIN_FUN2,
	 .strength	= PAD_12MA,
	 .voltage	= PAD_3_3V,
	 .pullup	= 0,
	 .drive 	= 2,
	 .pull 		= 0,
	 },
};


int enable_gpmi = { 0 };
static int __init gpmi_setup(char *__unused)
{
	enable_gpmi = 1;
	return 1;
}

__setup("gpmi", gpmi_setup);

static struct pin_desc mx28evk_gpmi_pins[] = {
	{
	 .name     = "GPMI D0",
	 .id       = PINID_GPMI_D00,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	.name     = "GPMI D1",
	.id       = PINID_GPMI_D01,
	.fun      = PIN_FUN1,
	.strength = PAD_4MA,
	.voltage  = PAD_3_3V,
	.pullup   = 0,
	.drive    = !0
	 },
	{
	 .name     = "GPMI D2",
	 .id       = PINID_GPMI_D02,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI D3",
	 .id       = PINID_GPMI_D03,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI D4",
	 .id       = PINID_GPMI_D04,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI D5",
	 .id       = PINID_GPMI_D05,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI D6",
	 .id       = PINID_GPMI_D06,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI D7",
	 .id       = PINID_GPMI_D07,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI CE0-",
	 .id       = PINID_GPMI_CE0N,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI CE1-",
	 .id       = PINID_GPMI_CE1N,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI RDY0",
	 .id       = PINID_GPMI_RDY0,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI RDY1",
	 .id       = PINID_GPMI_RDY1,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI RD-",
	 .id       = PINID_GPMI_RDN,
	 .fun      = PIN_FUN1,
	 .strength = PAD_12MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI WR-",
	 .id       = PINID_GPMI_WRN,
	 .fun      = PIN_FUN1,
	 .strength = PAD_12MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI ALE",
	 .id       = PINID_GPMI_ALE,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI CLE",
	 .id       = PINID_GPMI_CLE,
	 .fun      = PIN_FUN1,
	 .strength = PAD_4MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
	{
	 .name     = "GPMI RST-",
	 .id       = PINID_GPMI_RESETN,
	 .fun      = PIN_FUN1,
	 .strength = PAD_12MA,
	 .voltage  = PAD_3_3V,
	 .pullup   = 0,
	 .drive    = !0
	 },
};

#if defined(CONFIG_SPI_MXS) || defined(CONFIG_SPI_MXS_MODULE)
static struct pin_desc mx28evk_spi_pins[] = {
	{
	 .name	= "SSP2 MOSI",
	 .id	= PINID_SSP2_MOSI,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .drive 	= 1,
	 },
	{
	 .name	= "SSP2 MISO",
	 .id	= PINID_SSP2_MISO,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .drive 	= 1,
	 },
	{
	 .name	= "SSP2 SCK",
	 .id	= PINID_SSP2_SCK,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_4MA,
	 .voltage	= PAD_3_3V,
	 .drive 	= 1,
	 },
	{
	 .name	= "SSP2 SS0",
	 .id	= PINID_SSP2_SS0,
	 .fun	= PIN_FUN1,
	 .strength	= PAD_8MA,
	 .voltage	= PAD_3_3V,
	 .drive 	= 1,
	 },
};
#endif

#if defined(CONFIG_FEC) || defined(CONFIG_FEC_MODULE)\
	|| defined(CONFIG_FEC_L2SWITCH)
int mx28evk_enet_gpio_init(void)
{
#define EASY283  1 
#if EASY283
#define	 PIN_FEC_PHY_RESET    PINID_LCD_D16	    //ZLG EasyARM-i.MX28x系列开发板
#define	 PIN_FEC_PHY1_RXER    PINID_SPDIF	    //测试i.MX287系列开发板
#else
#define	 PIN_FEC_PHY_RESET    PINID_ENET0_RX_CLK  //公板适用
#endif
	/* pwr */
	//gpio_request(MXS_PIN_TO_GPIO(PINID_SSP1_DATA3), "ENET_PWR");
	//gpio_direction_output(MXS_PIN_TO_GPIO(PINID_SSP1_DATA3), 0);

        /* reset phy */
	gpio_request(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), "PHY_RESET"); //注册为GPIO
	gpio_request(MXS_PIN_TO_GPIO(PIN_FEC_PHY1_RXER), "PHY1_RXER"); //注册为GPIO
        gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), 1);  //输出1
        gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), 0);  //输出0
        gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY1_RXER), 0);  //输出0

        /*
         * Before timer bug fix(set wrong match value of timer),
         * mdelay(10) delay 50ms actually.
         * So change delay to 50ms after timer issue fix.
         */
        mdelay(50);
        gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), 1);
	/* modefy by zhuguojun 延时500毫秒后再一次复位， 以解决在直接从内核启动时，phy不能被探测的问题 */
        mdelay(500);
        gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), 0);
        mdelay(50);
        gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), 1);

     	return 0;
}

void mx28evk_enet_io_lowerpower_enter(void)
{
	int i;
	//gpio_direction_output(MXS_PIN_TO_GPIO(PINID_SSP1_DATA3), 1);//关断phy电源
	gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), 0);//复位Phy以降低功耗
	//gpio_request(MXS_PIN_TO_GPIO(PINID_ENET0_TX_CLK), "ETH_INT"); //用作GPIO
	//gpio_direction_output(MXS_PIN_TO_GPIO(PINID_ENET0_TX_CLK), 0);//将引脚输出0以降低功耗

	for (i = 0; i < ARRAY_SIZE(mx28evk_eth_pins); i++) {
		mxs_release_pin(mx28evk_eth_pins[i].id,
			mx28evk_eth_pins[i].name);                    //释放功能引脚
		gpio_request(MXS_PIN_TO_GPIO(mx28evk_eth_pins[i].id),
			mx28evk_eth_pins[i].name);                    //将引脚用作GPIO
		gpio_direction_output(
			MXS_PIN_TO_GPIO(mx28evk_eth_pins[i].id), 0);  //将引脚输出0以降低功耗
	}

}

void mx28evk_enet_io_lowerpower_exit(void)
{
	int i;
	//gpio_direction_output(MXS_PIN_TO_GPIO(PINID_SSP1_DATA3), 0);  //使能Phy电源供应
	gpio_direction_output(MXS_PIN_TO_GPIO(PIN_FEC_PHY_RESET), 1);//输出高电平，释放复位
	//gpio_free(MXS_PIN_TO_GPIO(PINID_ENET0_TX_CLK));               //释放GPIO资源
	for (i = 0; i < ARRAY_SIZE(mx28evk_eth_pins); i++) {
		gpio_free(MXS_PIN_TO_GPIO(mx28evk_eth_pins[i].id));     //释放GPIO资源
		mxs_request_pin(mx28evk_eth_pins[i].id,
			mx28evk_eth_pins[i].fun,
			mx28evk_eth_pins[i].name);                      //使用功能引脚
	}
}

#else
int mx28evk_enet_gpio_init(void)
{
	return 0;
}
void mx28evk_enet_io_lowerpower_enter(void)
{}
void mx28evk_enet_io_lowerpower_exit(void)
{}
#endif


#if defined(CONFIG_LEDS_MXS) || defined(CONFIG_LEDS_MXS_MODULE)
static unsigned mxs_leds[]= {PINID_LCD_D22,PINID_LCD_D23,PINID_LCD_D21};
enum led_type {   
        LED_RUN        = 0,    
        LED_USER        = 1,  
        LED_BEEP       = 2,
}; 
int mxs_led_set(unsigned index, int value)
{
        gpio_request(MXS_PIN_TO_GPIO(mxs_leds[index]), "LED");
	if (index == LED_BEEP) {
        	gpio_direction_output(MXS_PIN_TO_GPIO(mxs_leds[index]), value);
	} else {
        	gpio_direction_output(MXS_PIN_TO_GPIO(mxs_leds[index]), !value);
	}
	return 0;
}
#else
int mxs_led_set(unsigned pinid, int value)
{
	return 0;
}

#endif

#if 0  //RS485 方向控制函数 modify by hak
#include <linux/delay.h>
#define DIRDELAY  5
int dirpin[] = {PINID_LCD_D17,PINID_LCD_D18};
int mxs_dir_set(unsigned index, int value)
{
        if (!value) {
                udelay(DIRDELAY);
        }
        gpio_request(MXS_PIN_TO_GPIO(dirpin[index]), "RS485DIR");
        gpio_direction_output(MXS_PIN_TO_GPIO(dirpin[index]), value);
        if (value) {
                udelay(DIRDELAY);
        }
        return 0;
}
#endif

void __init mx28evk_init_pin_group(struct pin_desc *pins, unsigned count)
{
	int i;
	struct pin_desc *pin;
	for (i = 0; i < count; i++) {
		pin = pins + i;
		if (pin->fun == PIN_GPIO)
			gpio_request(MXS_PIN_TO_GPIO(pin->id), pin->name);
		else
			mxs_request_pin(pin->id, pin->fun, pin->name);
		if (pin->drive) {
			mxs_set_strength(pin->id, pin->strength, pin->name);
			mxs_set_voltage(pin->id, pin->voltage, pin->name);
		}
		if (pin->pull)
			mxs_set_pullup(pin->id, pin->pullup, pin->name);
		if (pin->fun == PIN_GPIO) {
			if (pin->output)
				gpio_direction_output(MXS_PIN_TO_GPIO(pin->id),
							pin->data);
			else
				gpio_direction_input(MXS_PIN_TO_GPIO(pin->id));
		}
	}
}

void __init mx28evk_pins_init(void)
{

	mx28evk_init_pin_group(mx28evk_fixed_pins,
						ARRAY_SIZE(mx28evk_fixed_pins));

	if (enable_ssp1) {
		pr_info("Initializing SSP1 pins\n");
		mx28evk_init_pin_group(mx28evk_ssp1_pins,
						ARRAY_SIZE(mx28evk_ssp1_pins));
	} else if (enable_gpmi) {
		pr_info("Initializing GPMI pins\n");
		mx28evk_init_pin_group(mx28evk_gpmi_pins,
						ARRAY_SIZE(mx28evk_gpmi_pins));
	}

#if defined(CONFIG_SPI_MXS) || defined(CONFIG_SPI_MXS_MODULE)
	mx28evk_init_pin_group(mx28evk_spi_pins,
					ARRAY_SIZE(mx28evk_spi_pins));
#endif

#if defined(CONFIG_FEC) || defined(CONFIG_FEC_MODULE)\
	|| defined(CONFIG_FEC_L2SWITCH)
		mx28evk_init_pin_group(mx28evk_eth_pins,
						ARRAY_SIZE(mx28evk_eth_pins));
#endif
}
