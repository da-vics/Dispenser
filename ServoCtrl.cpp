#include "ServoCtrl.h"

void ServoCtrl::activateServo(const short servoDegree) const {
  digitalWrite(this->_ledPin, HIGH);
  this->myservo.write(servoDegree);
}

void ServoCtrl::resetServo(const short resetServoDegree) const {
  digitalWrite(this->_ledPin, LOW);
  this->myservo.write(resetServoDegree);
}

void ServoCtrl::attachServo() const {

  myservo.attach(this->servoPin);
}
