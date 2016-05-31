/*
 * Freescale PXP Register Definitions
 *
 * Copyright 2008-2010 Freescale Semiconductor, Inc. All Rights Reserved.
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 * This file is created by xml file. Don't Edit it.
 *
 * Xml Revision: 1.57
 * Template revision: 26195
 */

#ifndef __ARCH_ARM___PXP_H
#define __ARCH_ARM___PXP_H


#define HW_PXP_CTRL	(0x00000000)
#define HW_PXP_CTRL_SET	(0x00000004)
#define HW_PXP_CTRL_CLR	(0x00000008)
#define HW_PXP_CTRL_TOG	(0x0000000c)

#define BM_PXP_CTRL_SFTRST	0x80000000
#define BM_PXP_CTRL_CLKGATE	0x40000000
#define BP_PXP_CTRL_RSVD2	28
#define BM_PXP_CTRL_RSVD2	0x30000000
#define BF_PXP_CTRL_RSVD2(v)  \
		(((v) << 28) & BM_PXP_CTRL_RSVD2)
#define BP_PXP_CTRL_INTERLACED_OUTPUT	26
#define BM_PXP_CTRL_INTERLACED_OUTPUT	0x0C000000
#define BF_PXP_CTRL_INTERLACED_OUTPUT(v)  \
		(((v) << 26) & BM_PXP_CTRL_INTERLACED_OUTPUT)
#define BV_PXP_CTRL_INTERLACED_OUTPUT__PROGRESSIVE 0x0
#define BV_PXP_CTRL_INTERLACED_OUTPUT__FIELD0      0x1
#define BV_PXP_CTRL_INTERLACED_OUTPUT__FIELD1      0x2
#define BV_PXP_CTRL_INTERLACED_OUTPUT__INTERLACED  0x3
#define BP_PXP_CTRL_INTERLACED_INPUT	24
#define BM_PXP_CTRL_INTERLACED_INPUT	0x03000000
#define BF_PXP_CTRL_INTERLACED_INPUT(v)  \
		(((v) << 24) & BM_PXP_CTRL_INTERLACED_INPUT)
#define BV_PXP_CTRL_INTERLACED_INPUT__PROGRESSIVE 0x0
#define BV_PXP_CTRL_INTERLACED_INPUT__FIELD0      0x2
#define BV_PXP_CTRL_INTERLACED_INPUT__FIELD1      0x3
#define BM_PXP_CTRL_BLOCK_SIZE	0x00800000
#define BV_PXP_CTRL_BLOCK_SIZE__8X8   0x0
#define BV_PXP_CTRL_BLOCK_SIZE__16X16 0x1
#define BM_PXP_CTRL_ALPHA_OUTPUT	0x00400000
#define BM_PXP_CTRL_IN_PLACE	0x00200000
#define BM_PXP_CTRL_DELTA	0x00100000
#define BM_PXP_CTRL_CROP	0x00080000
#define BM_PXP_CTRL_SCALE	0x00040000
#define BM_PXP_CTRL_UPSAMPLE	0x00020000
#define BM_PXP_CTRL_SUBSAMPLE	0x00010000
#define BP_PXP_CTRL_S0_FORMAT	12
#define BM_PXP_CTRL_S0_FORMAT	0x0000F000
#define BF_PXP_CTRL_S0_FORMAT(v)  \
		(((v) << 12) & BM_PXP_CTRL_S0_FORMAT)
#define BV_PXP_CTRL_S0_FORMAT__ARGB8888  0x0
#define BV_PXP_CTRL_S0_FORMAT__RGB888    0x1
#define BV_PXP_CTRL_S0_FORMAT__RGB565    0x4
#define BV_PXP_CTRL_S0_FORMAT__RGB555    0x5
#define BV_PXP_CTRL_S0_FORMAT__YUV422    0x8
#define BV_PXP_CTRL_S0_FORMAT__YUV420    0x9
#define BV_PXP_CTRL_S0_FORMAT__UYVY1P422 0xA
#define BV_PXP_CTRL_S0_FORMAT__VYUY1P422 0xB
#define BV_PXP_CTRL_S0_FORMAT__YUV2P422  0xC
#define BV_PXP_CTRL_S0_FORMAT__YUV2P420  0xD
#define BV_PXP_CTRL_S0_FORMAT__YVU2P422  0xE
#define BV_PXP_CTRL_S0_FORMAT__YVU2P420  0xF
#define BM_PXP_CTRL_VFLIP	0x00000800
#define BM_PXP_CTRL_HFLIP	0x00000400
#define BP_PXP_CTRL_ROTATE	8
#define BM_PXP_CTRL_ROTATE	0x00000300
#define BF_PXP_CTRL_ROTATE(v)  \
		(((v) << 8) & BM_PXP_CTRL_ROTATE)
#define BV_PXP_CTRL_ROTATE__ROT_0   0x0
#define BV_PXP_CTRL_ROTATE__ROT_90  0x1
#define BV_PXP_CTRL_ROTATE__ROT_180 0x2
#define BV_PXP_CTRL_ROTATE__ROT_270 0x3
#define BP_PXP_CTRL_OUTBUF_FORMAT	4
#define BM_PXP_CTRL_OUTBUF_FORMAT	0x000000F0
#define BF_PXP_CTRL_OUTBUF_FORMAT(v)  \
		(((v) << 4) & BM_PXP_CTRL_OUTBUF_FORMAT)
#define BV_PXP_CTRL_OUTBUF_FORMAT__ARGB8888  0x0
#define BV_PXP_CTRL_OUTBUF_FORMAT__RGB888    0x1
#define BV_PXP_CTRL_OUTBUF_FORMAT__RGB888P   0x2
#define BV_PXP_CTRL_OUTBUF_FORMAT__ARGB1555  0x3
#define BV_PXP_CTRL_OUTBUF_FORMAT__RGB565    0x4
#define BV_PXP_CTRL_OUTBUF_FORMAT__RGB555    0x5
#define BV_PXP_CTRL_OUTBUF_FORMAT__YUV444    0x7
#define BV_PXP_CTRL_OUTBUF_FORMAT__UYVY1P422 0xA
#define BV_PXP_CTRL_OUTBUF_FORMAT__VYUY1P422 0xB
#define BV_PXP_CTRL_OUTBUF_FORMAT__YUV2P422  0xC
#define BV_PXP_CTRL_OUTBUF_FORMAT__YUV2P420  0xD
#define BV_PXP_CTRL_OUTBUF_FORMAT__YVU2P422  0xE
#define BV_PXP_CTRL_OUTBUF_FORMAT__YVU2P420  0xF
#define BM_PXP_CTRL_ENABLE_LCD_HANDSHAKE	0x00000008
#define BM_PXP_CTRL_NEXT_IRQ_ENABLE	0x00000004
#define BM_PXP_CTRL_IRQ_ENABLE	0x00000002
#define BM_PXP_CTRL_ENABLE	0x00000001

#define HW_PXP_STAT	(0x00000010)
#define HW_PXP_STAT_SET	(0x00000014)
#define HW_PXP_STAT_CLR	(0x00000018)
#define HW_PXP_STAT_TOG	(0x0000001c)

#define BP_PXP_STAT_BLOCKX	24
#define BM_PXP_STAT_BLOCKX	0xFF000000
#define BF_PXP_STAT_BLOCKX(v) \
		(((v) << 24) & BM_PXP_STAT_BLOCKX)
#define BP_PXP_STAT_BLOCKY	16
#define BM_PXP_STAT_BLOCKY	0x00FF0000
#define BF_PXP_STAT_BLOCKY(v)  \
		(((v) << 16) & BM_PXP_STAT_BLOCKY)
#define BP_PXP_STAT_RSVD2	8
#define BM_PXP_STAT_RSVD2	0x0000FF00
#define BF_PXP_STAT_RSVD2(v)  \
		(((v) << 8) & BM_PXP_STAT_RSVD2)
#define BP_PXP_STAT_AXI_ERROR_ID	4
#define BM_PXP_STAT_AXI_ERROR_ID	0x000000F0
#define BF_PXP_STAT_AXI_ERROR_ID(v)  \
		(((v) << 4) & BM_PXP_STAT_AXI_ERROR_ID)
#define BM_PXP_STAT_NEXT_IRQ	0x00000008
#define BM_PXP_STAT_AXI_READ_ERROR	0x00000004
#define BM_PXP_STAT_AXI_WRITE_ERROR	0x00000002
#define BM_PXP_STAT_IRQ	0x00000001

#define HW_PXP_OUTBUF	(0x00000020)

#define BP_PXP_OUTBUF_ADDR	0
#define BM_PXP_OUTBUF_ADDR	0xFFFFFFFF
#define BF_PXP_OUTBUF_ADDR(v)	(v)

#define HW_PXP_OUTBUF2	(0x00000030)

#define BP_PXP_OUTBUF2_ADDR	0
#define BM_PXP_OUTBUF2_ADDR	0xFFFFFFFF
#define BF_PXP_OUTBUF2_ADDR(v)	(v)

#define HW_PXP_OUTSIZE	(0x00000040)

#define BP_PXP_OUTSIZE_ALPHA	24
#define BM_PXP_OUTSIZE_ALPHA	0xFF000000
#define BF_PXP_OUTSIZE_ALPHA(v) \
		(((v) << 24) & BM_PXP_OUTSIZE_ALPHA)
#define BP_PXP_OUTSIZE_WIDTH	12
#define BM_PXP_OUTSIZE_WIDTH	0x00FFF000
#define BF_PXP_OUTSIZE_WIDTH(v)  \
		(((v) << 12) & BM_PXP_OUTSIZE_WIDTH)
#define BP_PXP_OUTSIZE_HEIGHT	0
#define BM_PXP_OUTSIZE_HEIGHT	0x00000FFF
#define BF_PXP_OUTSIZE_HEIGHT(v)  \
		(((v) << 0) & BM_PXP_OUTSIZE_HEIGHT)

#define HW_PXP_S0BUF	(0x00000050)

#define BP_PXP_S0BUF_ADDR	0
#define BM_PXP_S0BUF_ADDR	0xFFFFFFFF
#define BF_PXP_S0BUF_ADDR(v)	(v)

#define HW_PXP_S0UBUF	(0x00000060)

#define BP_PXP_S0UBUF_ADDR	0
#define BM_PXP_S0UBUF_ADDR	0xFFFFFFFF
#define BF_PXP_S0UBUF_ADDR(v)	(v)

#define HW_PXP_S0VBUF	(0x00000070)

#define BP_PXP_S0VBUF_ADDR	0
#define BM_PXP_S0VBUF_ADDR	0xFFFFFFFF
#define BF_PXP_S0VBUF_ADDR(v)	(v)

#define HW_PXP_S0PARAM	(0x00000080)

#define BP_PXP_S0PARAM_XBASE	24
#define BM_PXP_S0PARAM_XBASE	0xFF000000
#define BF_PXP_S0PARAM_XBASE(v) \
		(((v) << 24) & BM_PXP_S0PARAM_XBASE)
#define BP_PXP_S0PARAM_YBASE	16
#define BM_PXP_S0PARAM_YBASE	0x00FF0000
#define BF_PXP_S0PARAM_YBASE(v)  \
		(((v) << 16) & BM_PXP_S0PARAM_YBASE)
#define BP_PXP_S0PARAM_WIDTH	8
#define BM_PXP_S0PARAM_WIDTH	0x0000FF00
#define BF_PXP_S0PARAM_WIDTH(v)  \
		(((v) << 8) & BM_PXP_S0PARAM_WIDTH)
#define BP_PXP_S0PARAM_HEIGHT	0
#define BM_PXP_S0PARAM_HEIGHT	0x000000FF
#define BF_PXP_S0PARAM_HEIGHT(v)  \
		(((v) << 0) & BM_PXP_S0PARAM_HEIGHT)

#define HW_PXP_S0BACKGROUND	(0x00000090)

#define BP_PXP_S0BACKGROUND_COLOR	0
#define BM_PXP_S0BACKGROUND_COLOR	0xFFFFFFFF
#define BF_PXP_S0BACKGROUND_COLOR(v)	(v)

#define HW_PXP_S0CROP	(0x000000a0)

#define BP_PXP_S0CROP_XBASE	24
#define BM_PXP_S0CROP_XBASE	0xFF000000
#define BF_PXP_S0CROP_XBASE(v) \
		(((v) << 24) & BM_PXP_S0CROP_XBASE)
#define BP_PXP_S0CROP_YBASE	16
#define BM_PXP_S0CROP_YBASE	0x00FF0000
#define BF_PXP_S0CROP_YBASE(v)  \
		(((v) << 16) & BM_PXP_S0CROP_YBASE)
#define BP_PXP_S0CROP_WIDTH	8
#define BM_PXP_S0CROP_WIDTH	0x0000FF00
#define BF_PXP_S0CROP_WIDTH(v)  \
		(((v) << 8) & BM_PXP_S0CROP_WIDTH)
#define BP_PXP_S0CROP_HEIGHT	0
#define BM_PXP_S0CROP_HEIGHT	0x000000FF
#define BF_PXP_S0CROP_HEIGHT(v)  \
		(((v) << 0) & BM_PXP_S0CROP_HEIGHT)

#define HW_PXP_S0SCALE	(0x000000b0)

#define BM_PXP_S0SCALE_RSVD2	0x80000000
#define BP_PXP_S0SCALE_YSCALE	16
#define BM_PXP_S0SCALE_YSCALE	0x7FFF0000
#define BF_PXP_S0SCALE_YSCALE(v)  \
		(((v) << 16) & BM_PXP_S0SCALE_YSCALE)
#define BM_PXP_S0SCALE_RSVD1	0x00008000
#define BP_PXP_S0SCALE_XSCALE	0
#define BM_PXP_S0SCALE_XSCALE	0x00007FFF
#define BF_PXP_S0SCALE_XSCALE(v)  \
		(((v) << 0) & BM_PXP_S0SCALE_XSCALE)

#define HW_PXP_S0OFFSET	(0x000000c0)

#define BP_PXP_S0OFFSET_RSVD2	28
#define BM_PXP_S0OFFSET_RSVD2	0xF0000000
#define BF_PXP_S0OFFSET_RSVD2(v) \
		(((v) << 28) & BM_PXP_S0OFFSET_RSVD2)
#define BP_PXP_S0OFFSET_YOFFSET	16
#define BM_PXP_S0OFFSET_YOFFSET	0x0FFF0000
#define BF_PXP_S0OFFSET_YOFFSET(v)  \
		(((v) << 16) & BM_PXP_S0OFFSET_YOFFSET)
#define BP_PXP_S0OFFSET_RSVD1	12
#define BM_PXP_S0OFFSET_RSVD1	0x0000F000
#define BF_PXP_S0OFFSET_RSVD1(v)  \
		(((v) << 12) & BM_PXP_S0OFFSET_RSVD1)
#define BP_PXP_S0OFFSET_XOFFSET	0
#define BM_PXP_S0OFFSET_XOFFSET	0x00000FFF
#define BF_PXP_S0OFFSET_XOFFSET(v)  \
		(((v) << 0) & BM_PXP_S0OFFSET_XOFFSET)

#define HW_PXP_CSCCOEFF0	(0x000000d0)

#define BM_PXP_CSCCOEFF0_YCBCR_MODE	0x80000000
#define BP_PXP_CSCCOEFF0_RSVD1	29
#define BM_PXP_CSCCOEFF0_RSVD1	0x60000000
#define BF_PXP_CSCCOEFF0_RSVD1(v)  \
		(((v) << 29) & BM_PXP_CSCCOEFF0_RSVD1)
#define BP_PXP_CSCCOEFF0_C0	18
#define BM_PXP_CSCCOEFF0_C0	0x1FFC0000
#define BF_PXP_CSCCOEFF0_C0(v)  \
		(((v) << 18) & BM_PXP_CSCCOEFF0_C0)
#define BP_PXP_CSCCOEFF0_UV_OFFSET	9
#define BM_PXP_CSCCOEFF0_UV_OFFSET	0x0003FE00
#define BF_PXP_CSCCOEFF0_UV_OFFSET(v)  \
		(((v) << 9) & BM_PXP_CSCCOEFF0_UV_OFFSET)
#define BP_PXP_CSCCOEFF0_Y_OFFSET	0
#define BM_PXP_CSCCOEFF0_Y_OFFSET	0x000001FF
#define BF_PXP_CSCCOEFF0_Y_OFFSET(v)  \
		(((v) << 0) & BM_PXP_CSCCOEFF0_Y_OFFSET)

#define HW_PXP_CSCCOEFF1	(0x000000e0)

#define BP_PXP_CSCCOEFF1_RSVD1	27
#define BM_PXP_CSCCOEFF1_RSVD1	0xF8000000
#define BF_PXP_CSCCOEFF1_RSVD1(v) \
		(((v) << 27) & BM_PXP_CSCCOEFF1_RSVD1)
#define BP_PXP_CSCCOEFF1_C1	16
#define BM_PXP_CSCCOEFF1_C1	0x07FF0000
#define BF_PXP_CSCCOEFF1_C1(v)  \
		(((v) << 16) & BM_PXP_CSCCOEFF1_C1)
#define BP_PXP_CSCCOEFF1_RSVD0	11
#define BM_PXP_CSCCOEFF1_RSVD0	0x0000F800
#define BF_PXP_CSCCOEFF1_RSVD0(v)  \
		(((v) << 11) & BM_PXP_CSCCOEFF1_RSVD0)
#define BP_PXP_CSCCOEFF1_C4	0
#define BM_PXP_CSCCOEFF1_C4	0x000007FF
#define BF_PXP_CSCCOEFF1_C4(v)  \
		(((v) << 0) & BM_PXP_CSCCOEFF1_C4)

#define HW_PXP_CSCCOEFF2	(0x000000f0)

#define BP_PXP_CSCCOEFF2_RSVD1	27
#define BM_PXP_CSCCOEFF2_RSVD1	0xF8000000
#define BF_PXP_CSCCOEFF2_RSVD1(v) \
		(((v) << 27) & BM_PXP_CSCCOEFF2_RSVD1)
#define BP_PXP_CSCCOEFF2_C2	16
#define BM_PXP_CSCCOEFF2_C2	0x07FF0000
#define BF_PXP_CSCCOEFF2_C2(v)  \
		(((v) << 16) & BM_PXP_CSCCOEFF2_C2)
#define BP_PXP_CSCCOEFF2_RSVD0	11
#define BM_PXP_CSCCOEFF2_RSVD0	0x0000F800
#define BF_PXP_CSCCOEFF2_RSVD0(v)  \
		(((v) << 11) & BM_PXP_CSCCOEFF2_RSVD0)
#define BP_PXP_CSCCOEFF2_C3	0
#define BM_PXP_CSCCOEFF2_C3	0x000007FF
#define BF_PXP_CSCCOEFF2_C3(v)  \
		(((v) << 0) & BM_PXP_CSCCOEFF2_C3)

#define HW_PXP_NEXT	(0x00000100)
#define HW_PXP_NEXT_SET	(0x00000104)
#define HW_PXP_NEXT_CLR	(0x00000108)
#define HW_PXP_NEXT_TOG	(0x0000010c)

#define BP_PXP_NEXT_POINTER	2
#define BM_PXP_NEXT_POINTER	0xFFFFFFFC
#define BF_PXP_NEXT_POINTER(v) \
		(((v) << 2) & BM_PXP_NEXT_POINTER)
#define BM_PXP_NEXT_RSVD	0x00000002
#define BM_PXP_NEXT_ENABLED	0x00000001

#define HW_PXP_S0COLORKEYLOW	(0x00000180)

#define BP_PXP_S0COLORKEYLOW_RSVD1	24
#define BM_PXP_S0COLORKEYLOW_RSVD1	0xFF000000
#define BF_PXP_S0COLORKEYLOW_RSVD1(v) \
		(((v) << 24) & BM_PXP_S0COLORKEYLOW_RSVD1)
#define BP_PXP_S0COLORKEYLOW_PIXEL	0
#define BM_PXP_S0COLORKEYLOW_PIXEL	0x00FFFFFF
#define BF_PXP_S0COLORKEYLOW_PIXEL(v)  \
		(((v) << 0) & BM_PXP_S0COLORKEYLOW_PIXEL)

#define HW_PXP_S0COLORKEYHIGH	(0x00000190)

#define BP_PXP_S0COLORKEYHIGH_RSVD1	24
#define BM_PXP_S0COLORKEYHIGH_RSVD1	0xFF000000
#define BF_PXP_S0COLORKEYHIGH_RSVD1(v) \
		(((v) << 24) & BM_PXP_S0COLORKEYHIGH_RSVD1)
#define BP_PXP_S0COLORKEYHIGH_PIXEL	0
#define BM_PXP_S0COLORKEYHIGH_PIXEL	0x00FFFFFF
#define BF_PXP_S0COLORKEYHIGH_PIXEL(v)  \
		(((v) << 0) & BM_PXP_S0COLORKEYHIGH_PIXEL)

#define HW_PXP_OLCOLORKEYLOW	(0x000001a0)

#define BP_PXP_OLCOLORKEYLOW_RSVD1	24
#define BM_PXP_OLCOLORKEYLOW_RSVD1	0xFF000000
#define BF_PXP_OLCOLORKEYLOW_RSVD1(v) \
		(((v) << 24) & BM_PXP_OLCOLORKEYLOW_RSVD1)
#define BP_PXP_OLCOLORKEYLOW_PIXEL	0
#define BM_PXP_OLCOLORKEYLOW_PIXEL	0x00FFFFFF
#define BF_PXP_OLCOLORKEYLOW_PIXEL(v)  \
		(((v) << 0) & BM_PXP_OLCOLORKEYLOW_PIXEL)

#define HW_PXP_OLCOLORKEYHIGH	(0x000001b0)

#define BP_PXP_OLCOLORKEYHIGH_RSVD1	24
#define BM_PXP_OLCOLORKEYHIGH_RSVD1	0xFF000000
#define BF_PXP_OLCOLORKEYHIGH_RSVD1(v) \
		(((v) << 24) & BM_PXP_OLCOLORKEYHIGH_RSVD1)
#define BP_PXP_OLCOLORKEYHIGH_PIXEL	0
#define BM_PXP_OLCOLORKEYHIGH_PIXEL	0x00FFFFFF
#define BF_PXP_OLCOLORKEYHIGH_PIXEL(v)  \
		(((v) << 0) & BM_PXP_OLCOLORKEYHIGH_PIXEL)

#define HW_PXP_DEBUGCTRL	(0x000001d0)

#define BP_PXP_DEBUGCTRL_RSVD	9
#define BM_PXP_DEBUGCTRL_RSVD	0xFFFFFE00
#define BF_PXP_DEBUGCTRL_RSVD(v) \
		(((v) << 9) & BM_PXP_DEBUGCTRL_RSVD)
#define BM_PXP_DEBUGCTRL_RESET_TLB_STATS	0x00000100
#define BP_PXP_DEBUGCTRL_SELECT	0
#define BM_PXP_DEBUGCTRL_SELECT	0x000000FF
#define BF_PXP_DEBUGCTRL_SELECT(v)  \
		(((v) << 0) & BM_PXP_DEBUGCTRL_SELECT)
#define BV_PXP_DEBUGCTRL_SELECT__NONE     0x0
#define BV_PXP_DEBUGCTRL_SELECT__CTRL     0x1
#define BV_PXP_DEBUGCTRL_SELECT__S0REGS   0x2
#define BV_PXP_DEBUGCTRL_SELECT__S0BAX    0x3
#define BV_PXP_DEBUGCTRL_SELECT__S0BAY    0x4
#define BV_PXP_DEBUGCTRL_SELECT__PXBUF    0x5
#define BV_PXP_DEBUGCTRL_SELECT__ROTATION 0x6
#define BV_PXP_DEBUGCTRL_SELECT__ROTBUF0  0x7
#define BV_PXP_DEBUGCTRL_SELECT__ROTBUF1  0x8
#define BV_PXP_DEBUGCTRL_SELECT__TLBCOUNT 0xF0
#define BV_PXP_DEBUGCTRL_SELECT__TLBHIT   0xF1
#define BV_PXP_DEBUGCTRL_SELECT__TLBMISS  0xF2
#define BV_PXP_DEBUGCTRL_SELECT__TLBLAT   0xF3
#define BV_PXP_DEBUGCTRL_SELECT__TLBSTATE 0xF8

#define HW_PXP_DEBUG	(0x000001e0)

#define BP_PXP_DEBUG_DATA	0
#define BM_PXP_DEBUG_DATA	0xFFFFFFFF
#define BF_PXP_DEBUG_DATA(v)	(v)

#define HW_PXP_VERSION	(0x000001f0)

#define BP_PXP_VERSION_MAJOR	24
#define BM_PXP_VERSION_MAJOR	0xFF000000
#define BF_PXP_VERSION_MAJOR(v) \
		(((v) << 24) & BM_PXP_VERSION_MAJOR)
#define BP_PXP_VERSION_MINOR	16
#define BM_PXP_VERSION_MINOR	0x00FF0000
#define BF_PXP_VERSION_MINOR(v)  \
		(((v) << 16) & BM_PXP_VERSION_MINOR)
#define BP_PXP_VERSION_STEP	0
#define BM_PXP_VERSION_STEP	0x0000FFFF
#define BF_PXP_VERSION_STEP(v)  \
		(((v) << 0) & BM_PXP_VERSION_STEP)

/*
 *  multi-register-define name HW_PXP_OLn
 *              base 0x00000200
 *              count 8
 *              offset 0x40
 */
#define HW_PXP_OLn(n)	(0x00000200 + (n) * 0x40)
#define BP_PXP_OLn_ADDR	0
#define BM_PXP_OLn_ADDR	0xFFFFFFFF
#define BF_PXP_OLn_ADDR(v)	(v)

/*
 *  multi-register-define name HW_PXP_OLnSIZE
 *              base 0x00000210
 *              count 8
 *              offset 0x40
 */
#define HW_PXP_OLnSIZE(n)	(0x00000210 + (n) * 0x40)
#define BP_PXP_OLnSIZE_XBASE	24
#define BM_PXP_OLnSIZE_XBASE	0xFF000000
#define BF_PXP_OLnSIZE_XBASE(v) \
		(((v) << 24) & BM_PXP_OLnSIZE_XBASE)
#define BP_PXP_OLnSIZE_YBASE	16
#define BM_PXP_OLnSIZE_YBASE	0x00FF0000
#define BF_PXP_OLnSIZE_YBASE(v)  \
		(((v) << 16) & BM_PXP_OLnSIZE_YBASE)
#define BP_PXP_OLnSIZE_WIDTH	8
#define BM_PXP_OLnSIZE_WIDTH	0x0000FF00
#define BF_PXP_OLnSIZE_WIDTH(v)  \
		(((v) << 8) & BM_PXP_OLnSIZE_WIDTH)
#define BP_PXP_OLnSIZE_HEIGHT	0
#define BM_PXP_OLnSIZE_HEIGHT	0x000000FF
#define BF_PXP_OLnSIZE_HEIGHT(v)  \
		(((v) << 0) & BM_PXP_OLnSIZE_HEIGHT)

/*
 *  multi-register-define name HW_PXP_OLnPARAM
 *              base 0x00000220
 *              count 8
 *              offset 0x40
 */
#define HW_PXP_OLnPARAM(n)	(0x00000220 + (n) * 0x40)
#define BP_PXP_OLnPARAM_RSVD1	20
#define BM_PXP_OLnPARAM_RSVD1	0xFFF00000
#define BF_PXP_OLnPARAM_RSVD1(v) \
		(((v) << 20) & BM_PXP_OLnPARAM_RSVD1)
#define BP_PXP_OLnPARAM_ROP	16
#define BM_PXP_OLnPARAM_ROP	0x000F0000
#define BF_PXP_OLnPARAM_ROP(v)  \
		(((v) << 16) & BM_PXP_OLnPARAM_ROP)
#define BV_PXP_OLnPARAM_ROP__MASKOL     0x0
#define BV_PXP_OLnPARAM_ROP__MASKNOTOL  0x1
#define BV_PXP_OLnPARAM_ROP__MASKOLNOT  0x2
#define BV_PXP_OLnPARAM_ROP__MERGEOL    0x3
#define BV_PXP_OLnPARAM_ROP__MERGENOTOL 0x4
#define BV_PXP_OLnPARAM_ROP__MERGEOLNOT 0x5
#define BV_PXP_OLnPARAM_ROP__NOTCOPYOL  0x6
#define BV_PXP_OLnPARAM_ROP__NOT        0x7
#define BV_PXP_OLnPARAM_ROP__NOTMASKOL  0x8
#define BV_PXP_OLnPARAM_ROP__NOTMERGEOL 0x9
#define BV_PXP_OLnPARAM_ROP__XOROL      0xA
#define BV_PXP_OLnPARAM_ROP__NOTXOROL   0xB
#define BP_PXP_OLnPARAM_ALPHA	8
#define BM_PXP_OLnPARAM_ALPHA	0x0000FF00
#define BF_PXP_OLnPARAM_ALPHA(v)  \
		(((v) << 8) & BM_PXP_OLnPARAM_ALPHA)
#define BP_PXP_OLnPARAM_FORMAT	4
#define BM_PXP_OLnPARAM_FORMAT	0x000000F0
#define BF_PXP_OLnPARAM_FORMAT(v)  \
		(((v) << 4) & BM_PXP_OLnPARAM_FORMAT)
#define BV_PXP_OLnPARAM_FORMAT__ARGB8888 0x0
#define BV_PXP_OLnPARAM_FORMAT__RGB888   0x1
#define BV_PXP_OLnPARAM_FORMAT__ARGB1555 0x3
#define BV_PXP_OLnPARAM_FORMAT__RGB565   0x4
#define BV_PXP_OLnPARAM_FORMAT__RGB555   0x5
#define BM_PXP_OLnPARAM_ENABLE_COLORKEY	0x00000008
#define BP_PXP_OLnPARAM_ALPHA_CNTL	1
#define BM_PXP_OLnPARAM_ALPHA_CNTL	0x00000006
#define BF_PXP_OLnPARAM_ALPHA_CNTL(v)  \
		(((v) << 1) & BM_PXP_OLnPARAM_ALPHA_CNTL)
#define BV_PXP_OLnPARAM_ALPHA_CNTL__Embedded 0x0
#define BV_PXP_OLnPARAM_ALPHA_CNTL__Override 0x1
#define BV_PXP_OLnPARAM_ALPHA_CNTL__Multiply 0x2
#define BV_PXP_OLnPARAM_ALPHA_CNTL__ROPs     0x3
#define BM_PXP_OLnPARAM_ENABLE	0x00000001

/*
 *  multi-register-define name HW_PXP_OLnPARAM2
 *              base 0x00000230
 *              count 8
 *              offset 0x40
 */
#define HW_PXP_OLnPARAM2(n)	(0x00000230 + (n) * 0x40)
#define BP_PXP_OLnPARAM2_RSVD	0
#define BM_PXP_OLnPARAM2_RSVD	0xFFFFFFFF
#define BF_PXP_OLnPARAM2_RSVD(v)	(v)
#endif /* __ARCH_ARM___PXP_H */
