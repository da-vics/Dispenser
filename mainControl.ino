/*
   Contactless Water Dispenser by Mealimeter

*/
#include "ControlFlow.h"
#define DEBUG 0

#define ledPinCold 11  /// cold 
#define ledPinHot 12 /// hot

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

/**
   @Brief ultra sonic instance
*/
MeasureDistance ultraDistanceCold(echoPinCold, trigPinCold);
MeasureDistance ultraDistanceHot(echoPinHot, trigPinHot);

/**
   @Brief  servo instance
*/
ServoCtrl servoctrlCold(servoCold, ledPinCold);
ServoCtrl servoctrlHot(servoHot, ledPinHot);

/**
   @Brief Control flow instance
*/
FlowCtrl ctrlFlowCold(&servoctrlCold, &ultraDistanceCold);
FlowCtrl ctrlFlowHot(&servoctrlHot, &ultraDistanceHot);

void setup()
{

  pinMode(trigPinCold, OUTPUT);
  pinMode(echoPinCold, INPUT);

  pinMode(trigPinHot, OUTPUT);
  pinMode(echoPinHot, INPUT);

  pinMode(ledPinCold, OUTPUT);
  pinMode(ledPinHot, OUTPUT);

  Serial.begin(9600);

  /**
    @Brief attach Servo
  */
  servoctrlCold.attachServo();
  servoctrlHot.attachServo();

  /**
    @Brief Reset servo
  */
  servoctrlCold.resetServo(80);
  servoctrlHot.resetServo(0);
}

void loop()
{

  ctrlFlowCold.controlService(0, 80);
  ctrlFlowHot.controlService(80, 0);


#if DEBUG
  Serial.print("Cold: ");
  Serial.println(ultraDistanceCold.getDistance());

  Serial.print("Hot: ");
  Serial.println(ultraDistanceHot.getDistance());
#endif

}
