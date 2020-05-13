#ifndef _IRDISTANCE_H
#define _IRDISTANCE_H

#include "services.h"

#include <Arduino.h>

class MeasureDistance
{
private:
  short IRPin;

public:
  Identifier serviceIdentity;
  MeasureDistance() = delete;
  MeasureDistance(const short &irPin, const Identifier identify) : IRPin{irPin}, serviceIdentity{identify} {}

  bool initDistance();
};

#endif
