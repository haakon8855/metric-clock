#include "metric_time.h"


void MetricTimeClass::begin() {
  RTC.begin();
}

void MetricTimeClass::setTime(int hours, int minutes, int seconds) {
  RTCTime mytime(1, Month::JANUARY, 1970, hours, minutes, seconds, DayOfWeek::THURSDAY, SaveLight::SAVING_TIME_INACTIVE);
  RTC.setTime(mytime);
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
