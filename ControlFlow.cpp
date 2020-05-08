#include "ControlFlow.h"

void FlowCtrl::controlService(const short activeDegree, const short resetDegree) const
{

  if (this->_sonicDistance->serviceIdentity == (Identifier)this->controlFlowPriority || this->controlFlowPriority == ServicePriority::Null)
  {
    if (_sonicDistance->getDistance() <= MeasureDistance::_maxDistance)
    {
      _servoCtrl->activateServo(activeDegree);
      this->controlFlowPriority = (ServicePriority)this->_sonicDistance->serviceIdentity;
    }

    else
    {
      this->controlFlowPriority = ServicePriority::Null;
      _servoCtrl->resetServo(resetDegree);
    } ///

  } ///

} ///
