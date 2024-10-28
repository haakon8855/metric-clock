#ifndef SCREEN
#define SCREEN

#include "Arduino.h"
#include "digit_bitmaps.h"
#include "digit_position.h"

void insertNumber(byte arr[][12], int digit, DigitPosition position);
void setComma(byte arr[][12]);
void drawTime(byte arr[][12], float time);
void clearFrame(byte arr[][12]);

#endif