#include "Arduino_LED_Matrix.h"

#include "config.h"
#include "digit_bitmaps.h"
#include "screen.h"
#include "metric_time.h"

const int BUTTON1 = 1;
const int BUTTON2 = 2;
int BUTTONstate1 = 0;
int BUTTONstate2 = 0;

ArduinoLEDMatrix matrix;

byte frame[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

void setup() {
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  MetricTime.begin();
  MetricTime.setTime(0);
  matrix.begin();
}

void loop() {
  BUTTONstate1 = digitalRead(BUTTON1);
  BUTTONstate2 = digitalRead(BUTTON2);

  if (BUTTONstate1 == HIGH) {
    // still klokka ned
    MetricTime.decrementTime();
  }
  if (BUTTONstate2 == HIGH) {
    // still klokka opp
    MetricTime.incrementTime();
  }


  int metric = MetricTime.getTime();

  clearFrame(frame);
  // setComma(frame);
  drawTime(frame, metric);
  matrix.renderBitmap(frame, SCREEN_HEIGHT, SCREEN_WIDTH);
  delay(100);
}
