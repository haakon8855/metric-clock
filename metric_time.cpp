#include "RTC.h"
#include "metric_time.h"


void MetricTimeClass::begin() {
  RTC.begin();
}

void MetricTimeClass::setTime(int offset) {
  RTCTime mytime(baseTime + offset);
  RTC.setTime(mytime);
}

void MetricTimeClass::incrementTime() {
  timeOffset += 86;//.4
  setTime(timeOffset);
}

void MetricTimeClass::decrementTime() {
  timeOffset -= 86;//.4
  setTime(timeOffset);
}

int MetricTimeClass::getTime() {
  RTCTime currentTime;
  RTC.getTime(currentTime);
  int hours = currentTime.getHour();
  int minutes = currentTime.getMinutes();
  int seconds = currentTime.getSeconds() + minutes * 60 + hours * 3600;
  seconds *= 1000;

  return seconds / (60 * 60 * 24);
}

MetricTimeClass MetricTime;
