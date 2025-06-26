#include "epd.h"
#include "DEV_Config.h"
#include "EPD_1in54_V2.h"  // z Waveshare

// Pełna inicjalizacja (z pełnym czyszczeniem RAM)
void EPD_Init(void) {
    EPD_1IN54_V2_Init();
}

// Inicjalizacja częściowa (do późniejszych update’ów bez pełnego resetu)
void EPD_Init_Partial(void) {
    EPD_1IN54_V2_Init_Partial();
}

// Pełne czyszczenie ekranu (białe tło)
void EPD_Clear(void) {
    EPD_1IN54_V2_Clear();
}

// Wyświetlenie pełnego bufora obrazu (czarno-biały)
void EPD_Display(uint8_t *image) {
    EPD_1IN54_V2_Display(image);
}

// Ustawienie bufora bazowego do późniejszych częściowych aktualizacji
void EPD_DisplayBase(uint8_t *image) {
    EPD_1IN54_V2_DisplayPartBaseImage(image);
}

// Częściowa aktualizacja – bez resetu bufora RAM
void EPD_DisplayPartial(uint8_t *image) {
    EPD_1IN54_V2_DisplayPart(image);
}

// Przejście w tryb uśpienia
void EPD_Sleep(void) {
    EPD_1IN54_V2_Sleep();
}

