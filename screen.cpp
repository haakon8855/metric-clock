#include "screen.h"

void insertNumber(byte arr[][SCREEN_WIDTH], int digit, DigitPosition position) {
  int yOffset = 3;
  int xOffset = 4 * position;
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 3; col++) {
      arr[row + yOffset][col + xOffset] = DigitBitmaps[digit][row][col];
    }
  }
}

void setComma(byte arr[][SCREEN_WIDTH]) {
  arr[7][3] = 1;
}

void drawTime(byte arr[][SCREEN_WIDTH], int time) {
  int firstDigit = time / 100;
  int secondDigit = (time - firstDigit * 100) / 10;
  int thirdDigit = time - firstDigit * 100 - secondDigit * 10;
  insertNumber(arr, firstDigit, LEFT);
  insertNumber(arr, secondDigit, CENTER);
  insertNumber(arr, thirdDigit, RIGHT);
}

void clearFrame(byte arr[][SCREEN_WIDTH]) {
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 3; col++) {
      arr[row][col] = 0;
    }
  }
}