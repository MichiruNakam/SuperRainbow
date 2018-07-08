# SuperRainbow
A library that extends Rainbowduino (only with RGB led matrix) adding extra functionality.
# Requisites
You need to have the Rainbowduino library installed.
# Instalation
Install within the Arduino IDE using the zip file in this repository.
# Usage
The usage of SuperRainbow is near the same as RainbowDuino, but you have to initialize and refer to SuperRainbow as SRb instead of Rb.
# Example Sketch
//This sketch draws a green line that rotates counter-clockwise in the center of the RGB matrix.
#include <SuperRainbow.h>
void setup() {
  SRb.init();
}
void loop() {
  double a = 0;
  while (1) {
    SRb.blankDisplay();
    int cx = round(3.5 + 0.5 * cos(a));
    int cy = round(3.5 + 0.5 * sin(a));
    SRb.drawLine(cx, cy, cx + round(3 * cos(a)), cy + round(3 * sin(a)), SRb.get_color_HSV(128, 1, 1));
    a += PI / 32;
    if (a > 2 * PI) a = 0;
    delay(50);
  }
}
# Documentation
uint32_t get_color_HSV(double H, double S, double V)
Returns a color made with the HSV model, in uint32_t format (you simply pass this data to all the drawing functions of SuperRainbow or Rainbowduino).

uint32_t get_color_RGB(unsigned char R, unsigned char G, unsigned char B)
Returns a color made with the RGB model, in uint32_t format.

void blankPixel(unsigned int x, unsigned int y)
Turns off a pixel in (x, y).

void draw_string(char *str, float delay_time, uint32_t col)
Draw the string str moving from left to right. Each step of 1 pixel takes delay_time milliseconds. The whole message draws with the col color.

void drawLine(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, uint32_t col)
Draw a line from (x0, y0) to (x1, y1) with col color. This function override Rainbowduino's drawLine, allowing you to draw lines correcly even if (x1, y1) is more near to origin than (x0, y0).
