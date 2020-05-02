#include "ControlFlow.h"

void FlowCtrl::controlService() const
{
  if (_sonicDistance->getDistance() <= _maxDistance)
  {
    _servoCtrl->activateServo(80);
  }

  else {
    _servoCtrl->resetServo();
  }

}///
