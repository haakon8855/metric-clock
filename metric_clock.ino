#include "Arduino_LED_Matrix.h"
#include "DigitPosition.h"
#include "DigitBitmaps.h"

ArduinoLEDMatrix matrix;

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

byte frame[8][12] = {0};
float currentTime = 0.0;

void setup() {
  Serial.begin(9600);
  matrix.begin();
}

void loop() {
  clearFrame(frame);

  currentTime += 0.01;
  if (currentTime >= 10.0) {
    currentTime = 0.0;
  }

  // setComma(frame);
  drawTime(frame, currentTime);
  matrix.renderBitmap(frame, 8, 12);
  delay(200);
}
