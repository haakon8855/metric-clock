#ifndef METRIC_TIME
#define METRIC_TIME

#include "RTC.h"

class MetricTimeClass {
  public:
    void begin();
    void setTime(int hours, int minutes, int seconds);
    int getTime();
};

extern MetricTimeClass MetricTime;

#endif