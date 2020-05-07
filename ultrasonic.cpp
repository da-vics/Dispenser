#include "ultrasonic.h"

void MeasureDistance::initDistance()
{
  delay(100);

  int count = 1;
  while (count <= 5)
  {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(this->trigPin, LOW);

    this->duration = pulseIn(this->echoPin, HIGH);

    this->distance += (duration * 0.034) / 2;
    count++;
  }

  this->distance /= 5;
}

int MeasureDistance::getDistance()
{
  this->initDistance();
  return this->distance;
}
