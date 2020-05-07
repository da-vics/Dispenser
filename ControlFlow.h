#ifndef _CONTROLFLOW_H
#define _CONTROLFLOW_H

#include "ultrasonic.h"
#include "ServoCtrl.h"

class FlowCtrl
{
private:
  int _maxDistance{10};
  ServoCtrl *_servoCtrl{nullptr};
  MeasureDistance *_sonicDistance{nullptr};
  ServicePriority &controlFlowPriority;

public:
  FlowCtrl(ServoCtrl *servoctrl, MeasureDistance *sonictrl, ServicePriority ctrlPriority)
  {
    this->_servoCtrl = servoctrl;
    this->_sonicDistance = sonictrl;
    this->controlFlowPriority = ctrlPriority;
  }

  void controlService(const short, const short) const;
};

#endif
