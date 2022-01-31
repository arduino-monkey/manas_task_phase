#include <Servo.h>
#include "DbButton.h"

//buttons
DbButton modeBtn(0);
DbButton motorDirBtn(1);

//motors pins
#define in1 2
#define in2 4
#define enA 5

//servo
Servo servo;
int pos = 0;
int dir = 1;
unsigned long int lastTime;

int mapped;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  servo.attach(3);
  servo.write(0);
}

void sweep(Servo servo, int waitTime){
  if (millis() - lastTime > waitTime){
    lastTime = millis();
    servo.write(pos);
    if (dir)
      pos++;
    else
      pos--;
    if (pos == 0 || pos == 180)
      dir = !dir;
  }
}

void motorControl(int i1, int i2, int s){
  analogWrite(enA, s);
  digitalWrite(in1, i1);
  digitalWrite(in2, i2);
}

void loop() {
  modeBtn.btnLoop();
  motorDirBtn.btnLoop();
  
  int val = analogRead(A0);
  int mode = modeBtn.getState();
  int motorDir = motorDirBtn.getState();
  
  if (mode){
    //motor mode
    servo.detach();
    mapped = map(val, 0, 1023, 0, 255);
    if (motorDir){
      motorControl(1, 0, mapped);
    }else{
      motorControl(0, 1, mapped);
    }
  }else{
    servo.attach(3);
    motorControl(0, 0, 0);
    //stopping the motor
    mapped = map(val, 0, 1023, 1, 15);
    sweep(servo, mapped);
    }
}
