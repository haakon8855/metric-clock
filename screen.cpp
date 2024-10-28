#include "screen.h"

void insertNumber(byte arr[][12], int digit, DigitPosition position) {
  int yOffset = 3;
  int xOffset = 4 * position;
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 3; col++) {
      arr[row + yOffset][col + xOffset] = DigitBitmaps[digit][row][col];
    }
  }
}

void setComma(byte arr[][12]) {
  arr[7][3] = 1;
}

void drawTime(byte arr[][12], float time) {
  int firstDigit = (int)time;
  int secondDigit = (int)((time - (int)time)*10);
  int thirdDigit = (int)((time*10 - (int)(time*10))*10);
  insertNumber(arr, firstDigit, LEFT);
  insertNumber(arr, secondDigit, CENTER);
  insertNumber(arr, thirdDigit, RIGHT);
}

void clearFrame(byte arr[][12]) {
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 3; col++) {
      arr[row][col] = 0;
    }
  }
}