#ifndef METRIC_TIME
#define METRIC_TIME

#include "RTC.h"

class MetricTimeClass {
  private:
    int timeOffset;
    int baseTime = 2592000;
  public:
    void begin();
    void setTime(int offset);
    int getTime();
    void incrementTime();
    void decrementTime();
};

extern MetricTimeClass MetricTime;

#endif