#include "ServoCtrl.h"

void ServoCtrl::activateServo(const short servoDegree) const {
  
  this->myservo.write(servoDegree);
}

void ServoCtrl::resetServo() const{
  
  this->myservo.write(0);
}

void ServoCtrl::attachServo() const{
  
  myservo.attach(this->servoPin);
}
