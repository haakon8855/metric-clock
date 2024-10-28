#include "Arduino_LED_Matrix.h"
#include "RTC.h"
#include "digit_bitmaps.h"
#include "screen.h"

ArduinoLEDMatrix matrix;

volatile bool irqFlag = false;

byte frame[8][12] = { 0 };
float currentTime = 0.0;

void setup() {
  Serial.begin(9600);
  matrix.begin();

  RTC.begin();
  RTCTime mytime(1, Month::OCTOBER, 1998, 13, 37, 0, DayOfWeek::THURSDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);

  if (!RTC.setPeriodicCallback(periodicCallback, Period::ONCE_EVERY_1_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }
}

void loop() {
  if (irqFlag) {
    irqFlag = false;
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
}

void periodicCallback() {
  irqFlag = true;
}
