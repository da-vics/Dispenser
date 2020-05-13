#include "ControlFlow.h"

void FlowCtrl::controlService(const short activeDegree, const short resetDegree) const
{

  if (this->_IRDistace->serviceIdentity == (Identifier)this->controlFlowPriority || this->controlFlowPriority == ServicePriority::Null)
  {
  if (_IRDistace->initDistance())
  {
    _servoCtrl->activateServo(activeDegree);
    ///Serial.print((int)_IRDistace->serviceIdentity);
    this->controlFlowPriority = (ServicePriority)this->_IRDistace->serviceIdentity;
  }

  else
  {
     this->controlFlowPriority = ServicePriority::Null;
    _servoCtrl->resetServo(resetDegree);
  } ///

  } ///

} ///
