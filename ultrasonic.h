#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

#define DEBUG 0

#include "services.h"

#include <Arduino.h>
class MeasureDistance
{
  private:
    short echoPin;
    short trigPin;
    unsigned long duration{};
    int distance{};
    void initDistance();

  public:
    static const uint32_t _maxDistance = 15;
    Identifier serviceIdentity;
    MeasureDistance() = delete;
    MeasureDistance(const short echo, const short trig, const Identifier identify) : echoPin{echo}, trigPin{trig}, serviceIdentity{identify} {}
    int getDistance();
};

#endif
