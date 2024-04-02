#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

// #define sclk 13
// #define mosi 11
#define cs   10
#define rst  9
#define dc   8

// Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);
Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);


// 'New Project', 96x64px
const unsigned char epd_bitmap_New_Project [] PROGMEM = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xff, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0x78, 0x70, 
	0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 
	0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xff, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0xf8, 0x70, 
	0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 
	0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xff, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0x78, 0x70, 
	0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 
	0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xf5, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf5, 0x78, 0x70, 
	0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 
	0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xf4, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf7, 0x78, 0x70, 
	0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 
	0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xf1, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf4, 0xf8, 0x70, 
	0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 
	0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xf0, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf5, 0xf8, 0x70, 
	0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xf0, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 
	0x1c, 0x38, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 
	0xff, 0xf0, 0x78, 0x70, 0xe1, 0xc3, 0x87, 0x0e, 0x1c, 0x38, 0x00, 0xff, 0xff, 0xfd, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xf7, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x7f, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xef, 0x7b, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x77, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xfb, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x7f, 0x7b, 
	0x6f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0xff, 0xbf, 0xfe, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xdc, 0x1d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfb, 0xf0, 0x07, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7d, 0xe1, 
	0xc3, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xfe, 0x67, 0xf3, 0x3f, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xcf, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xcf, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x78, 0x4f, 
	0xf9, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xcf, 0xf9, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xcf, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xfe, 0x67, 0xf3, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7d, 0xe1, 
	0xc3, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0x7b, 0xf0, 0x07, 0xef, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x7f, 0xdc, 0x1d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xbf, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0x7f, 0x7b, 
	0x6f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x7f, 0xfb, 0x6f, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf1, 0x7f, 0xf7, 0x77, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xef, 0x7b, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};
const unsigned int bitmapWidth = 96;
const unsigned int bitmapHeight = 64;
const unsigned int bitmapSize = bitmapWidth * bitmapHeight / 8; // Calculate bitmap size in bytes

void setup() {
    // Initialize OLED display with SPI
    display.begin();
    display.setRotation(0); // Adjust rotation if needed
    display.fillRect(0, 0, display.width(), display.height(), 0); // Fill with black

    // Draw bitmap
    for (unsigned int y = 0; y < bitmapHeight; y++) {
        for (unsigned int x = 0; x < bitmapWidth; x++) {
            unsigned int index = y * (bitmapWidth / 8) + (x / 8);
            unsigned int bit = 7 - (x % 8);
            unsigned char pixel = pgm_read_byte(&epd_bitmap_New_Project[index]);
            if (!(pixel & (1 << bit))) {
                display.drawPixel(x, y, 0XFFE0); // Draw yellow pixel
            }
        }
    }
}

void loop() {
    // Leave empty if no looping behavior is needed
}
