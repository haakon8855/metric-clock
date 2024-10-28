#include "Arduino_LED_Matrix.h"
#include "digit_bitmaps.h"
#include "screen.h"

ArduinoLEDMatrix matrix;

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
