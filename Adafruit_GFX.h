#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#include "gfxfont.h"

#define swap(a, b) { int16_t t = a; a = b; b = t; }

class Adafruit_GFX : public Print {

 public:

  Adafruit_GFX(int16_t w, int16_t h); // Constructor

  // 核心抽象方法（子类必须实现）
  virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

  // 可被子类重写的绘制方法
  virtual void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
  virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
  virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
  virtual void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
  virtual void fillScreen(uint16_t color);
  virtual void invertDisplay(boolean i);

  // 通用绘制方法（无需重写）
  void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
  void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
  void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
  void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
  void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
  void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
  void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
  void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
  void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg);
  void drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
  void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
  void setCursor(int16_t x, int16_t y);
  void setTextColor(uint16_t c);
  void setTextColor(uint16_t c, uint16_t bg);
  void setTextSize(uint8_t s);
  void setTextWrap(boolean w);
  void setRotation(uint8_t r);
  void cp437(boolean x=true);
  uint8_t getRotation(void) const;

  void setFont(const GFXfont *f = NULL);
  void drawCentreString(const char *buf, int16_t x, int16_t y, uint8_t size);
  void drawRightString(const char *buf, int16_t x, int16_t y, uint8_t size);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void write(uint8_t);
#endif

  int16_t height(void) const;
  int16_t width(void) const;

  uint8_t getTextSize(void) const;
  uint16_t getTextColor(void) const;
  uint16_t getTextBgColor(void) const;
  boolean getTextWrap(void) const;
  int16_t getCursorX(void) const;
  int16_t getCursorY(void) const;

  // ========== 新增：五角星+椭圆方法声明 ==========
  // 五角星：x0/y0=中心坐标，radius=半径，color=颜色
  void drawPentagram(int16_t x0, int16_t y0, int16_t radius, uint16_t color);
  // 椭圆：x0/y0=中心坐标，rx=横轴半径，ry=纵轴半径，color=颜色
  void drawEllipse(int16_t x0, int16_t y0, int16_t rx, int16_t ry, uint16_t color);

 protected:
  const GFXfont *gfxFont;
  int16_t  _width, _height;   // 屏幕分辨率（旋转后）
  int16_t  cursor_x, cursor_y; // 文本光标位置
  uint16_t textcolor, textbgcolor; // 文本颜色/背景色
  uint8_t  textsize; // 文本大小
  boolean  textwrap, _cp437; // 自动换行/CP437字符集
  uint8_t  rotation; // 屏幕旋转角度（0-3）
};

#endif // _ADAFRUIT_GFX_H

