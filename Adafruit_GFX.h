#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif
#include "gfxfont.h"

class Adafruit_GFX : public Print {

 public:
  Adafruit_GFX(int16_t w, int16_t h); // Constructor

  // Subclass must implement
  virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

  // Transaction API
  virtual void startWrite(void);
  virtual void writePixel(int16_t x, int16_t y, uint16_t color);
  virtual void writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  virtual void writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
  virtual void writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
  virtual void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
  virtual void endWrite(void);

  // Control
  virtual void setRotation(uint8_t r);
  virtual void invertDisplay(boolean i);

  // Basic draw
  virtual void
    drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
    drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
    fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color),
    fillScreen(uint16_t color),
    drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color),
    drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

  // Existing shapes
  void
    drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color),
    fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color),

    // ✅ 新增：五角星（来自队友）
    drawPentagram(int16_t x0, int16_t y0, int16_t r, uint16_t color),

    // ✅ 新增：椭圆（你的）
    drawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint16_t color),

    drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
                 int16_t x2, int16_t y2, uint16_t color),
    fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
                 int16_t x2, int16_t y2, uint16_t color);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void write(uint8_t);
#endif

  int16_t width(void) const;
  int16_t height(void) const;
  uint8_t getRotation(void) const;

 protected:
  const int16_t WIDTH, HEIGHT;
  int16_t _width, _height;
  int16_t cursor_x, cursor_y;
  uint16_t textcolor, textbgcolor;
  uint8_t textsize, rotation;
  boolean wrap, _cp437;
  GFXfont *gfxFont;
};

#endif // _ADAFRUIT_GFX_H

