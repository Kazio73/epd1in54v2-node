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
