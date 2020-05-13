#ifndef _CONTROLFLOW_H
#define _CONTROLFLOW_H

#define DEBUG true

#include "IRClass.h"
#include "ServoCtrl.h"

class FlowCtrl
{
private:
  ServoCtrl *_servoCtrl{nullptr};
  MeasureDistance *_IRDistace{nullptr};
  ServicePriority &controlFlowPriority;

public:
  FlowCtrl() = delete;

  FlowCtrl(ServoCtrl *servoctrl, MeasureDistance *irctrl, ServicePriority ctrlPriority)
  {
    this->_servoCtrl = servoctrl;
    this->_IRDistace = irctrl;
    this->controlFlowPriority = ctrlPriority;
  }

  void controlService(const short, const short) const;
};

#endif
