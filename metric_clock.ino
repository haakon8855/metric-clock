#include "Arduino_LED_Matrix.h"
#include "RTC.h"
#include "digit_bitmaps.h"
#include "screen.h"

ArduinoLEDMatrix matrix;

volatile bool irqFlag = false;

byte frame[8][12] = { 0 };
int currentTime = 0;

void setup() {
  Serial.begin(9600);
  matrix.begin();

  RTC.begin();
  RTCTime mytime(1, Month::OCTOBER, 1998, 13, 37, 0, DayOfWeek::THURSDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);

  if (!RTC.setPeriodicCallback(periodicCallback, Period::N16_TIMES_EVERY_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }
}

void loop() {
  clearFrame(frame);
  // setComma(frame);
  drawTime(frame, currentTime);
  matrix.renderBitmap(frame, 8, 12);
  delay(50);
}

void periodicCallback() {
  currentTime += 1;
  if (currentTime >= 1000) {
    currentTime = 0;
  }
}
