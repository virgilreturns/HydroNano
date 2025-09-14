
#include <stdint.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <Wire.h>


TFT_eSPI tft = TFT_eSPI(); // Create TFT object

#define WIDTH 100
#define HEIGHT 100

uint16_t buffer[WIDTH * HEIGHT]; // Pixel buffer (RGB565 format)

void setup() {
  tft.begin();
  tft.setRotation(1);

  // Fill buffer with some color pattern
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    buffer[i] = tft.color565(255, 0, 0); // Red
  }

  // Blit buffer to screen at (x=50, y=50)
  tft.pushImage(50, 50, WIDTH, HEIGHT, buffer);
}

void loop() {
  // ...existing code...
}