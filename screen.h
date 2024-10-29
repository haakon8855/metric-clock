#ifndef SCREEN
#define SCREEN

#include "Arduino.h"
#include "config.h"
#include "digit_bitmaps.h"
#include "digit_position.h"

void insertNumber(byte arr[][SCREEN_WIDTH], int digit, DigitPosition position);
void setComma(byte arr[][SCREEN_WIDTH]);
void drawTime(byte arr[][SCREEN_WIDTH], int time);
void clearFrame(byte arr[][SCREEN_WIDTH]);

#endif