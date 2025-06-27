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

