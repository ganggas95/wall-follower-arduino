#include <HCSR04.h>

#include <L298N.h>

const int MAX_DISTANCE = 300;

unsigned int motorA = 10; // IN1
unsigned int motorB = 9;  // IN2
unsigned int motorC = 6; // IN3
unsigned int motorD = 5; // IN4
const byte  SENSOR_C = 13;
const byte  sensorCTrigger = 4;

const byte  SENSOR_R = 2;
const byte  sensorRTrigger = 3;

const byte  SENSOR_L = 12;
const byte  sensorLTrigger = 8;

L298N motorRight (motorB, motorA);
L298N motorLeft (motorC, motorD);
UltraSonicDistanceSensor sensorR(sensorRTrigger, SENSOR_R);
UltraSonicDistanceSensor sensorC(sensorCTrigger, SENSOR_C);
UltraSonicDistanceSensor sensorL(sensorLTrigger, SENSOR_L);

void setup() {
  // put your setup code here, to run once:
  motorLeft.setSpeed(700);
  motorRight.setSpeed(700);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  // motorLeft.forward();
  // motorRight.forward();
  // int sensorRValue = digitalRead(SENSOR_R);
  // int sensorLValue = digitalRead(SENSOR_L);
  // int sensorCValue = digitalRead(SENSOR_C);
  float distanceR = sensorR.measureDistanceCm();
  float distanceC = sensorC.measureDistanceCm();
  float distanceL = sensorL.measureDistanceCm();
  // if(distanceR <= 2 && distanceR > -1){
  //   motorLeft.forward();
  //   motorRight.stop();
  // }
  Serial.print("Right = ");
  Serial.println(distanceR);
  // Serial.print("Center = ");
  // Serial.println(distanceC);
  // Serial.print("Left = ");
  // Serial.println(distanceL);
  delay(500);
  // Serial.println(sensorLValue);
  // Serial.println(sensorCValue);

}
