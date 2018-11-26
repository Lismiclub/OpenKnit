  //stepper
#define speedRotation 500  //speed of the motor rotation
int steps = A1;
int dir = A2;
int reset = A0;
boolean dirRotation = LOW;  //direction of rotation
boolean endStopActive = false;

//encoder
const byte encoderPin1 = 0;
const byte encoderPin2 = 1;
const byte endStopPin = 3;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;
int increment = 1;

//servo
#include <Servo.h>
Servo servoFB;
Servo servoFT;
Servo servoBB;
Servo servoBT;
Servo servoSelection; //not used with Wally120 since it has only one Yarn Carrier

int servoFB_in = 48;
int servoFB_mid = 80;
int servoFB_out = 112; 
int servoFT_in = 85; 
int servoFT_out = 160; 

int servoBB_in = 55;
int servoBB_mid = 80;
int servoBB_out = 105;
int servoBT_in = 60;
int servoBT_out = 130;

int servoYarn_in = 65;
int servoYarn_out = 100;


void setup() {
  Serial.begin (9600);

  //stepper
  pinMode(steps, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(reset, OUTPUT);

  //encoder
  pinMode(encoderPin1, INPUT);
  pinMode(encoderPin2, INPUT);
  digitalWrite(encoderPin1, HIGH);
  digitalWrite(encoderPin2, HIGH);
  attachInterrupt(digitalPinToInterrupt(encoderPin1), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin2), updateEncoder, CHANGE);

  //end stop
  attachInterrupt(digitalPinToInterrupt(endStopInterrupt), endStopReleased, CHANGE);

  //servo
  servoFB.attach(7);   // servo in the front needle bed selecting needles
  servoFT.attach(8);   // servo in the front needle bed stopping the loops rising up
  servoBB.attach(9);   // servo in the back needle bed selecting needles
  servoBT.attach(10);   // servo in the back needle bed stopping the loops rising up

  homing();  //carriage goes home before anything else to get coordinatee zero
}

void loop(){
  tube(350, 100);
  doNothingAnymore();
}

void doNothingAnymore() {
  while(true) {
    delay(10000);
  }
}
