/*
   Contactless Water Dispenser by Mealimeter
*/
#include "ControlFlow.h"

#define ledPinCold 11 /// cold
#define ledPinHot 12  /// hot

const short IRPinCold = 3,
            IRPinHot = 4;

/**
   @Brief pinOuts for Servo
*/
const short servoCold = 9,
            servoHot = 10;

MeasureDistance IRDistanceCold(IRPinCold, Identifier::ServiceCold);
MeasureDistance IRDistanceHot(IRPinHot, Identifier::ServiceHot);

ServoCtrl servoctrlCold(servoCold, ledPinCold);
ServoCtrl servoctrlHot(servoHot, ledPinHot);

ServicePriority controlServicePriority = ServicePriority::Null; /// @services.h

FlowCtrl ctrlFlowCold(&servoctrlCold, &IRDistanceCold, controlServicePriority);
FlowCtrl ctrlFlowHot(&servoctrlHot, &IRDistanceHot, controlServicePriority);

void setup()
{

  pinMode(IRPinHot, INPUT);
  pinMode(IRPinCold, INPUT);

  pinMode(ledPinCold, OUTPUT);
  pinMode(ledPinHot, OUTPUT);

#if DEBUG
  Serial.begin(9600);
#endif

 /* cli();
  PCICR |= 0b00000100;
  PCMSK2 |= 0b00011000;
  sei();
*/
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
/*
ISR(PCINT2_vect)
{
  
  if(digitalRead(7) == HIGH)
  {

    Serial.println("HIGH");
    digitalWrite(13,HIGH);
    
  }
  */
  
