/*
   Contactless Water Dispenser by Mealimeter

*/

#include "ControlFlow.h"
#define DEBUG true
/**
   @Brief pinOuts for ultraSonic Sensors
*/
const short echoPinCold = 2,
            trigPinCold = 3,
            echoPinHot = 4,
            trigPinHot = 5;

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
ServoCtrl servoctrlCold(servoCold);
ServoCtrl servoctrlHot(servoHot);

/**
   @Brief Control flow instance
*/
FlowCtrl ctrlFlowCold(&servoctrlCold, &ultraDistanceCold);
FlowCtrl ctrlFlowHot(&servoctrlHot, &ultraDistanceHot);

void setup() {

  pinMode(trigPinCold, OUTPUT);
  pinMode(echoPinCold, INPUT);

  pinMode(trigPinHot, OUTPUT);
  pinMode(echoPinHot, INPUT);

  Serial.begin(9600);

  /**
     @Brief attach Servo
  */
  servoctrlCold.attachServo();
  servoctrlHot.attachServo();

  /**
     @Brief Reset servo
  */
  servoctrlCold.resetServo();
  servoctrlHot.resetServo();
}

void loop() {

  ctrlFlowCold.controlService();
  ctrlFlowHot.controlService();

#ifdef DEBUG == true
  Serial.print("Cold: ");
  Serial.println( ultraDistanceCold.getDistance());

  Serial.print("Hot: ");
  Serial.println( ultraDistanceHot.getDistance());
#endif

}
