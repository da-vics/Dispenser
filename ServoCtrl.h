#ifndef _SERVOCTRL_H
#define _SERVOCTRL_H

#include <Servo.h>
#include <Arduino.h>

class ServoCtrl
{
private:
  short _ledPin{};
  short servoPin{};
  Servo myservo;

public:
  ServoCtrl() = delete;

  ServoCtrl(const short servo, const short ledPin)
  {
    this->servoPin = servo;
    this->_ledPin = ledPin;
  }

  void attachServo() const;

  void activateServo(const short) const;

  void resetServo(const short) const;
};

#endif
