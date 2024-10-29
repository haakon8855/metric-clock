#include "Arduino_LED_Matrix.h"
#include "RTC.h"

#include "config.h"
#include "digit_bitmaps.h"
#include "screen.h"
#include "metric_time.h"

ArduinoLEDMatrix matrix;

byte frame[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

void setup() {
  MetricTime.begin();
  MetricTime.setTime(20, 47, 10);
  matrix.begin();
}

void loop() {
  int metric = MetricTime.getTime();

  clearFrame(frame);
  // setComma(frame);
  drawTime(frame, metric);
  matrix.renderBitmap(frame, SCREEN_HEIGHT, SCREEN_WIDTH);
  delay(100);
}
