#include "TFT_eSPI.h"
#include "Arduino.h"
#include <stdint.h>
#include "common.h"
#include "images.h

TFT_eSPI tft = TFT_eSPI();

typedef uint16_t pixel_t; // Assuming 16-bit color depth

extern pixel_t menu_page[430*320];

void setup() {
  tft.begin();
  tft.setRotation(1);
  // Fill buffer with color
  
  // Blit to screen
  tft.pushImage(50, 50, 100, 100, menu_page);
}