/*
  SuperRainbow.h - Versión 1.0 - Librería que extiende Rainbowduino para una matriz led RGB.
  Creado por Michiru Nakamura

  SuperRainbow.h - Version 1.0 - This library extends Rainbowduino for use with a RGB Led matrix.
  Created by Michiru Nakamura
*/
#ifndef SuperRainbow_h
#define SuperRainbow_h
#include <Rainbowduino.h>

class SuperRainbow: public Rainbowduino {
	public:
		uint32_t get_color_RGB(unsigned char R, unsigned char G, unsigned char B);
		uint32_t get_color_HSV(double, double, double);
		void blankPixel(unsigned int x, unsigned int y);
		void draw_string(char *str, float delay_time, uint32_t col);
		void drawLine(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, uint32_t col);
};
extern SuperRainbow SRb;
#endif