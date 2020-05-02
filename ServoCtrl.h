#ifndef _SERVOCTRL_H
#define _SERVOCTRL_H

#include <Servo.h>

class ServoCtrl
{
  private:
    short servoPin{};
    Servo myservo;

  public:
    ServoCtrl(const short servo) {
      this->servoPin = servo;
    }

    void attachServo() const;
    
    void activateServo(const short servoDegree) const;

    void resetServo() const;
};

#endif
