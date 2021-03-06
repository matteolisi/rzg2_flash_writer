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

#include "common.h"
#include "reg_rzg2.h"
#include "boot_init_gpio.h"

static void InitPOSNEG(void);
static void InitIOINTSEL(void);
static void InitOUTDT(void);
static void InitINOUTSEL(void);

void InitGPIO(void)
{
	InitPOSNEG();
	InitIOINTSEL();
	InitOUTDT();
	InitINOUTSEL();
}

static void InitPOSNEG(void)
{
	*((volatile uint32_t*)GPIO_POSNEG0)=0x00000000;
	*((volatile uint32_t*)GPIO_POSNEG1)=0x00000000;
	*((volatile uint32_t*)GPIO_POSNEG2)=0x00000000;
	*((volatile uint32_t*)GPIO_POSNEG3)=0x00000000;
	*((volatile uint32_t*)GPIO_POSNEG4)=0x00000000;
	*((volatile uint32_t*)GPIO_POSNEG5)=0x00000000;
	*((volatile uint32_t*)GPIO_POSNEG6)=0x00000000;
}

static void InitIOINTSEL(void)
{
	*((volatile uint32_t*)GPIO_IOINTSEL0)=0x00000000;
	*((volatile uint32_t*)GPIO_IOINTSEL1)=0x00000000;
	*((volatile uint32_t*)GPIO_IOINTSEL2)=0x00000000;
	*((volatile uint32_t*)GPIO_IOINTSEL3)=0x00000000;
	*((volatile uint32_t*)GPIO_IOINTSEL4)=0x00000000;
	*((volatile uint32_t*)GPIO_IOINTSEL5)=0x00000000;
	*((volatile uint32_t*)GPIO_IOINTSEL6)=0x00000000;
}

static void InitOUTDT(void)
{
	uint32_t product;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	switch (product)
	{
#ifdef RZG2_HIHOPE
		case PRR_PRODUCT_G2M:
		case PRR_PRODUCT_G2N:
			*((volatile uint32_t*)GPIO_OUTDT1)=0x00000000;
			*((volatile uint32_t*)GPIO_OUTDT2)=0x00000400;
			*((volatile uint32_t*)GPIO_OUTDT3)=0x0000C000;
			*((volatile uint32_t*)GPIO_OUTDT5)=0x00000006;
			*((volatile uint32_t*)GPIO_OUTDT6)=0x00003880;
		break;
#endif /* RZG2_HIHOPE */
#ifdef RZG2_EK874
		case PRR_PRODUCT_G2E:
		break;
#endif /* RZG2_EK874 */
		default:
		break;
	}
}

static void InitINOUTSEL(void)
{
	uint32_t product;

	product = *((volatile uint32_t*)PRR) & PRR_PRODUCT_MASK;
	switch (product)
	{
#ifdef RZG2_HIHOPE
		case PRR_PRODUCT_G2M:
		case PRR_PRODUCT_G2N:
			*((volatile uint32_t*)GPIO_INOUTSEL0)=0x00000000;
			*((volatile uint32_t*)GPIO_INOUTSEL1)=0x01000A00;
			*((volatile uint32_t*)GPIO_INOUTSEL2)=0x00000400;
			*((volatile uint32_t*)GPIO_INOUTSEL3)=0x0000C000;
			*((volatile uint32_t*)GPIO_INOUTSEL4)=0x00000000;
			*((volatile uint32_t*)GPIO_INOUTSEL5)=0x0000020E;
			*((volatile uint32_t*)GPIO_INOUTSEL6)=0x00013880;
		break;
#endif /* RZG2_HIHOPE */
#ifdef RZG2_EK874
		case PRR_PRODUCT_G2E:
		break;
#endif /* RZG2_EK874*/
		default:
		break;
	}
}
