#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H

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
  Identifier serviceIdentity;
  MeasureDistance() = delete;
  MeasureDistance(const short echo, const short trig, const Identifier identify) : echoPin{echo}, trigPin{trig}, serviceIdentity{identify} {}
  int getDistance();
};

#endif
