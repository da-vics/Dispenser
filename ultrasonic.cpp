#include "ultrasonic.h"

void MeasureDistance::initDistance()
{
#define avg 10
  int count = 0;
  this->distance = 0;

  while (count < avg)
  {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(this->trigPin, LOW);

    this->duration = pulseIn(this->echoPin, HIGH);

    this->distance += (int) (duration * 0.034) / 2;
    count++;
  }

  this->distance /= avg;

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
