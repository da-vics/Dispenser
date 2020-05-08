#include "ultrasonic.h"

void MeasureDistance::initDistance()
{

#define avg 3
  int count = 0;
  bool once = true;
  bool contin = true;

  this->distance = 0;

  while (count < avg && contin == true)
  {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(this->trigPin, LOW);

    this->duration = pulseIn(this->echoPin, HIGH);

    this->distance += (int) (duration * 0.034) / 2;
    count++;

    if (once)
    {
      once = false;
      if (this->distance > MeasureDistance::_maxDistance) contin = false;
    }///

  }

  this->distance /= count;

#if DEBUG
  Serial.print((int)this->serviceIdentity);
  Serial.print(" distance: ");
  Serial.println(distance);
#endif


}

int MeasureDistance::getDistance()
{
  this->initDistance();
  return this->distance;
}
