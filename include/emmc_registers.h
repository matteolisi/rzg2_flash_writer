/*
 * Copyright (c) 2015-2019, Renesas Electronics Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Renesas nor the names of its contributors may be
 *     used to endorse or promote products derived from this software without
 *     specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/** 
 * @file  emmc_registers.h
 * @brief emmc boot driver is expecting this header file. HS-MMC module header file.
 *
 */

#ifndef __EMMC_REGISTERS_H__
#define __EMMC_REGISTERS_H__

/* ************************ HEADER (INCLUDE) SECTION *********************** */

/* ***************** MACROS, CONSTANTS, COMPILATION FLAGS ****************** */
/* MMC channel select */
#define MMC_CH0		(0U)		/* SDHI2/MMC0 */
#define MMC_CH1		(1U)		/* SDHI3/MMC1 */

#define USE_MMC_CH	(MMC_CH1)	/* RZ/G2E, RZ/G2M, RZ/G2N	*/

/** @brief eMMC registers
 */
#define	MMC0_SD_BASE		(0xEE140000U)
#define MMC1_SD_BASE		(0xEE160000U)

#if USE_MMC_CH == MMC_CH0
#define	MMC_SD_BASE		(MMC0_SD_BASE)
#else  /* USE_MMC_CH == MMC_CH0 */
#define	MMC_SD_BASE		(MMC1_SD_BASE)
#endif /* USE_MMC_CH == MMC_CH0 */

#define SD_CMD					(MMC_SD_BASE + 0x0000)
#define SD_PORTSEL				(MMC_SD_BASE + 0x0008)
#define SD_ARG					(MMC_SD_BASE + 0x0010)
#define SD_ARG1					(MMC_SD_BASE + 0x0018)
#define SD_STOP					(MMC_SD_BASE + 0x0020)
#define SD_SECCNT				(MMC_SD_BASE + 0x0028)
#define SD_RSP10				(MMC_SD_BASE + 0x0030)
#define SD_RSP1					(MMC_SD_BASE + 0x0038)
#define SD_RSP32				(MMC_SD_BASE + 0x0040)
#define SD_RSP3					(MMC_SD_BASE + 0x0048)
#define SD_RSP54				(MMC_SD_BASE + 0x0050)
#define SD_RSP5					(MMC_SD_BASE + 0x0058)
#define SD_RSP76				(MMC_SD_BASE + 0x0060)
#define SD_RSP7					(MMC_SD_BASE + 0x0068)
#define SD_INFO1				(MMC_SD_BASE + 0x0070)
#define SD_INFO2				(MMC_SD_BASE + 0x0078)
#define SD_INFO1_MASK				(MMC_SD_BASE + 0x0080)
#define SD_INFO2_MASK				(MMC_SD_BASE + 0x0088)
#define SD_CLK_CTRL				(MMC_SD_BASE + 0x0090)
#define SD_SIZE					(MMC_SD_BASE + 0x0098)
#define SD_OPTION				(MMC_SD_BASE + 0x00A0)
#define SD_ERR_STS1				(MMC_SD_BASE + 0x00B0)
#define SD_ERR_STS2				(MMC_SD_BASE + 0x00B8)
#define SD_BUF0					(MMC_SD_BASE + 0x00C0)
#define SDIO_MODE				(MMC_SD_BASE + 0x00D0)
#define SDIO_INFO1				(MMC_SD_BASE + 0x00D8)
#define SDIO_INFO1_MASK				(MMC_SD_BASE + 0x00E0)
#define CC_EXT_MODE				(MMC_SD_BASE + 0x0360)
#define SOFT_RST				(MMC_SD_BASE + 0x0380)
#define VERSION					(MMC_SD_BASE + 0x0388)
#define HOST_MODE				(MMC_SD_BASE + 0x0390)
#define DM_CM_DTRAN_MODE			(MMC_SD_BASE + 0x0820)
#define DM_CM_DTRAN_CTRL			(MMC_SD_BASE + 0x0828)
#define DM_CM_RST				(MMC_SD_BASE + 0x0830)
#define DM_CM_INFO1				(MMC_SD_BASE + 0x0840)
#define DM_CM_INFO1_MASK			(MMC_SD_BASE + 0x0848)
#define DM_CM_INFO2				(MMC_SD_BASE + 0x0850)
#define DM_CM_INFO2_MASK			(MMC_SD_BASE + 0x0858)
#define DM_DTRAN_ADDR				(MMC_SD_BASE + 0x0880)



/** @brief SD_INFO1 Registers
 */
#define SD_INFO1_HPIRES				0x00010000UL		/* Response Reception Completion	*/
#define SD_INFO1_INFO10				0x00000400UL		/* Indicates the SDDAT3 state		*/
#define SD_INFO1_INFO9				0x00000200UL		/* SDDAT3 Card Insertion		*/
#define SD_INFO1_INFO8				0x00000100UL		/* SDDAT3 Card Removal			*/
#define SD_INFO1_INFO7				0x00000080UL		/* Write Protect			*/
#define SD_INFO1_INFO5				0x00000020UL		/* Indicates the ISDCD state		*/
#define SD_INFO1_INFO4				0x00000010UL		/* ISDCD Card Insertion			*/
#define SD_INFO1_INFO3				0x00000008UL		/* ISDCD Card Removal			*/
#define SD_INFO1_INFO2				0x00000004UL		/* Access end				*/
#define SD_INFO1_INFO0				0x00000001UL		/* Response end				*/

/** @brief SD_INFO2 Registers
 */
#define SD_INFO2_ILA				0x00008000UL		/* Illegal Access Error			*/
#define SD_INFO2_CBSY				0x00004000UL		/* Command Type Register Busy		*/
#define SD_INFO2_SCLKDIVEN			0x00002000UL
#define SD_INFO2_BWE				0x00000200UL		/* SD_BUF Write Enable			*/
#define SD_INFO2_BRE				0x00000100UL		/* SD_BUF Read Enable			*/
#define SD_INFO2_DAT0				0x00000080UL		/* SDDAT0				*/
#define SD_INFO2_ERR6				0x00000040UL		/* Response Timeout			*/
#define SD_INFO2_ERR5				0x00000020UL		/* SD_BUF Illegal Read Access		*/
#define SD_INFO2_ERR4				0x00000010UL		/* SD_BUF Illegal Write Access		*/
#define SD_INFO2_ERR3				0x00000008UL		/* Data Timeout				*/
#define SD_INFO2_ERR2				0x00000004UL		/* END Error				*/
#define SD_INFO2_ERR1				0x00000002UL		/* CRC Error				*/
#define SD_INFO2_ERR0				0x00000001UL		/* CMD Error				*/
#define SD_INFO2_ALL_ERR			0x0000807FUL
#define SD_INFO2_CLEAR				0x00000800UL		/* BIT11 The write value should always be 1. HWM_0003 */

/** @brief SOFT_RST
 */
#define SOFT_RST_SDRST				0x00000001UL

/** @brief SD_CLK_CTRL
 */
#define SD_CLK_CTRL_SDCLKOFFEN			0x00000200UL
#define SD_CLK_CTRL_SCLKEN			0x00000100UL
#define SD_CLK_CTRL_CLKDIV_MASK			0x000000FFUL
#define SD_CLOCK_ENABLE				0x00000100UL
#define SD_CLOCK_DISABLE			0x00000000UL
#define SD_CLK_WRITE_MASK			0x000003FFUL
#define SD_CLK_CLKDIV_CLEAR_MASK		0xFFFFFF0FUL

/** @brief SD_OPTION
 */
#define SD_OPTION_TIMEOUT_CNT_MASK	0x000000F0UL


/** @brief MMC Clock Frequency
 * 200MHz * 1/x = output clock
 */
#define MMC_CLK_OFF			0UL			/* Clock output is disabled				*/
#define MMC_400KHZ			512UL			/* 200MHz * 1/512 = 390 KHz 				*/
#define MMC_20MHZ			16UL			/* 200MHz * 1/16   = 12.5 MHz Normal speed mode		*/
#define MMC_26MHZ			8UL			/* 200MHz * 1/8   = 25 MHz High speed mode 26Mhz	*/
#define MMC_52MHZ			4UL			/* 200MHz * 1/4   = 50 MHz High speed mode 52Mhz	*/
#define MMC_100MHZ			2UL			/* 200MHz * 1/2   = 100 MHz				*/
#define MMC_200MHZ			1UL			/* 200MHz * 1/1   = 200 MHz				*/


#define MMC_FREQ_52MHZ		52000000UL
#define MMC_FREQ_26MHZ		26000000UL
#define MMC_FREQ_20MHZ		20000000UL


/** @brief MMC Clock DIV
 */
#define MMC_SD_CLK_START	0x00000100UL	/* CLOCK On	*/
#define MMC_SD_CLK_STOP		(~0x00000100UL)	/* CLOCK stop   */
#define MMC_SD_CLK_DIV1		0x000000FFUL	/* 1/1          */
#define MMC_SD_CLK_DIV2		0x00000000UL	/* 1/2          */
#define MMC_SD_CLK_DIV4		0x00000001UL	/* 1/4          */
#define MMC_SD_CLK_DIV8		0x00000002UL	/* 1/8          */
#define MMC_SD_CLK_DIV16	0x00000004UL	/* 1/16         */
#define MMC_SD_CLK_DIV32	0x00000008UL	/* 1/32         */
#define MMC_SD_CLK_DIV64	0x00000010UL	/* 1/64         */
#define MMC_SD_CLK_DIV128	0x00000020UL	/* 1/128        */
#define MMC_SD_CLK_DIV256	0x00000040UL	/* 1/256        */
#define MMC_SD_CLK_DIV512	0x00000080UL	/* 1/512        */

/** @brief DM_CM_DTRAN_MODE
 */
#define DM_CM_DTRAN_MODE_CH0		0x00000000UL		/* CH0(downstream)	*/
#define DM_CM_DTRAN_MODE_CH1		0x00010000UL		/* CH1(upstream)	*/
#define DM_CM_DTRAN_MODE_BIT_WIDTH	0x00000030UL

/** @brief CC_EXT_MODE
 */
#define CC_EXT_MODE_DMASDRW_ENABLE	0x00000002UL		/* SD_BUF Read/Write DMA Transfer */
#define CC_EXT_MODE_CLEAR		0x00001010UL		/* BIT 12 & 4 always 1. */

/** @brief DM_CM_INFO_MASK
 */
#define DM_CM_INFO_MASK_CLEAR		0xFFFCFFFEUL
#define DM_CM_INFO_CH0_ENABLE		0x00010001UL
#define DM_CM_INFO_CH1_ENABLE		0x00020001UL

/** @brief DM_DTRAN_ADDR
 */
#define DM_DTRAN_ADDR_WRITE_MASK	0xFFFFFFF8UL

/** @brief DM_CM_DTRAN_CTRL
 */
#define DM_CM_DTRAN_CTRL_START		0x00000001UL

/** @brief SYSC Registers
 */
#define CPG_MSTP_MMC		        0x00001000UL	//MMC0:0x00001000 MMC1:0x00000800


/* ********************** STRUCTURES, TYPE DEFINITIONS ********************* */

/* ********************** DECLARATION OF EXTERNAL DATA ********************* */

/* ************************** FUNCTION PROTOTYPES ************************** */

/* ********************************* CODE ********************************** */

#endif /* __EMMC_REGISTERS_H__ */
/* ******************************** END ************************************ */

