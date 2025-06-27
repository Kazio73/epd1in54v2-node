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

#include "epd.h"
#include "DEV_Config.h"
#include "EPD_1in54_V2.h"  // from Waveshare source

// Full initialization (including full RAM wipe)
void EPD_Init(void) {
    EPD_1IN54_V2_Init();
}

// Partial init (for updates without full RAM clearing or display reset)
void EPD_Init_Partial(void) {
    EPD_1IN54_V2_Init_Partial();
}

// Clears entire display to white
void EPD_Clear(void) {
    EPD_1IN54_V2_Clear();
}

// Render full framebuffer (monochrome: black & white)
void EPD_Display(uint8_t *image) {
    EPD_1IN54_V2_Display(image);
}

// Set the baseline buffer used during subsequent partial updates
void EPD_DisplayBase(uint8_t *image) {
    EPD_1IN54_V2_DisplayPartBaseImage(image);
}

// Partial update – without RAM buffer reset
void EPD_DisplayPartial(uint8_t *image) {
    EPD_1IN54_V2_DisplayPart(image);
}

// Enter sleep mode
void EPD_Sleep(void) {
    EPD_1IN54_V2_Sleep();
}

