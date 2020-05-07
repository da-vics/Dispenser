#include "ControlFlow.h"

void FlowCtrl::controlService(const short activeDegree, const short resetDegree) const
{
  if (_sonicDistance->getDistance() <= _maxDistance)
  {
    _servoCtrl->activateServo(activeDegree);
  }

  else {
    _servoCtrl->resetServo(resetDegree);
  }

}///
