/*
  SuperRainbow.cpp - Versión 1.0 - Librería que extiende Rainbowduino para una matriz led RGB.
  Creado por Michiru Nakamura

  SuperRainbow.cpp - Version 1.0 - This library extends Rainbowduino for use with a RGB Led matrix.
  Created by Michiru Nakamura
*/
#include "SuperRainbow.h"
#include <math.h>
#include <string.h>
#include <Rainbowduino.h>
uint32_t SuperRainbow::get_color_RGB(unsigned char R, unsigned char G, unsigned char B){
  uint32_t c;
  c = R;
  c <<= 8;
  c |= G;
  c <<= 8;
  c |= B;
  return c;
}
uint32_t SuperRainbow::get_color_HSV(double H, double S, double V) {
  double r = 0, g = 0, b = 0;
  if (S == 0)
  {
    r = V;
    g = V;
    b = V;
  } else {
    int i;
    double f, p, q, t;
    if (H == 360)
      H = 0;
    else
      H = H / 60;
    i = (int)trunc(H);
    f = H - i;
    p = V * (1.0 - S);
    q = V * (1.0 - (S * f));
    t = V * (1.0 - (S * (1.0 - f)));
    switch (i) {
      case 0:
        r = V;
        g = t;
        b = p;
      break;
      case 1:
        r = q;
        g = V;
        b = p;
        break;
      case 2:
        r = p;
        g = V;
        b = t;
      break;
      case 3:
        r = p;
        g = q;
        b = V;
      break;
      case 4:
        r = t;
        g = p;
        b = V;
      break;
      default:
        r = V;
        g = p;
        b = q;
      break;
    }
  }
  return get_color_RGB(r * 255, g * 255, b * 255);
}
void SuperRainbow::draw_string(char *str, float delay_time, uint32_t col){
  int pos = 0;
  //Inicio
  for (int i = 0; i != 8; ++i) {
    blankDisplay();
    drawChar(str[pos], 8 - i, 0, col);
    drawChar(str[pos + 1], 14 - i, 0, col);
    delay(delay_time);
  }
  for (; pos != strlen(str) - 1; ++pos) {
    for (int i = 0; i != 6; ++i) {
      blankDisplay();
      drawChar(str[pos],- i, 0, col);
      drawChar(str[pos + 1],6 - i, 0, col);
      delay(delay_time);
    }
  }
  for (int i = 0; i != 8; ++i) {
    blankDisplay();
    drawChar(str[pos],- i, 0, col);
    delay(delay_time);
  }
}
void SuperRainbow::drawLine(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, uint32_t col){
  int length = round(sqrt(pow((int)(x1 - x0), 2) + pow((int)(y1 - y0), 2)));
  for (int i = 0; i != length + 1; ++i){
    double factor = (double)i / (length);
    setPixelXY(round(x0 + (int)(x1 - x0) * factor), round(y0 + (int)(y1 - y0) * factor), col);
  }
}

SuperRainbow SRb;
