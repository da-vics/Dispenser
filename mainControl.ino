/*
   Contactless Water Dispenser by Mealimeter

*/
#include "ControlFlow.h"

#define ledPinCold 11 /// cold
#define ledPinHot 12  /// hot

/**
   @Brief pinOuts for ultraSonic Sensors
*/
const short echoPinCold = 3,
            trigPinCold = 2,
            echoPinHot = 5,
            trigPinHot = 4;

/**
   @Brief pinOuts for Servo
*/
const short servoCold = 9,
            servoHot = 10;

MeasureDistance ultraDistanceCold(echoPinCold, trigPinCold, Identifier::ServiceCold);
MeasureDistance ultraDistanceHot(echoPinHot, trigPinHot, Identifier::ServiceHot);

ServoCtrl servoctrlCold(servoCold, ledPinCold);
ServoCtrl servoctrlHot(servoHot, ledPinHot);

ServicePriority controlServicePriority = ServicePriority::Null; /// @services.h

FlowCtrl ctrlFlowCold(&servoctrlCold, &ultraDistanceCold, controlServicePriority);
FlowCtrl ctrlFlowHot(&servoctrlHot, &ultraDistanceHot, controlServicePriority);

void setup()
{

  pinMode(trigPinCold, OUTPUT);
  pinMode(echoPinCold, INPUT);

  pinMode(trigPinHot, OUTPUT);
  pinMode(echoPinHot, INPUT);

  pinMode(ledPinCold, OUTPUT);
  pinMode(ledPinHot, OUTPUT);

#if DEBUG
  Serial.begin(9600);
#endif

  servoctrlCold.attachServo();
  servoctrlHot.attachServo();

  servoctrlCold.resetServo(80);
  servoctrlHot.resetServo(0);
}

void loop()
{
  ctrlFlowCold.controlService(0, 80);
  ctrlFlowHot.controlService(80, 0);
}
