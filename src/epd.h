/*
 * MIT License
 *
 * Copyright (c) 2025 Kazik Karczewski
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _EPD_DRIVER_H_
#define _EPD_DRIVER_H_

#include <stdint.h>
#include <stddef.h>
#include "DEV_Config.h"

#ifdef __cplusplus
extern "C" {
#endif

void EPD_1IN54_V2_Init(void);
void EPD_1IN54_V2_Init_Partial(void);
void EPD_1IN54_V2_Clear(void);
void EPD_1IN54_V2_Display(UBYTE *Image);
void EPD_1IN54_V2_DisplayPartBaseImage(UBYTE *Image);
void EPD_1IN54_V2_DisplayPart(UBYTE *Image);
void EPD_1IN54_V2_Sleep(void);

void EPD_Init(void);
void EPD_Init_Partial(void);
void EPD_Clear(void);
void EPD_Display(uint8_t *image);
void EPD_DisplayBase(uint8_t *image);
void EPD_DisplayPartial(uint8_t *image);
void EPD_Sleep(void);

#ifdef __cplusplus
}
#endif

#endif
