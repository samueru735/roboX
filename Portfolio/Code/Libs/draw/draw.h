#ifndef Draw_h
#define Draw_h
#define ANGLE 10
#define DOT 1
#define DASH 2
#define LINE 3
#define STOP 4
#define UP 50
#define DOWN 20


#include "Arduino.h"
#include "Servo.h"

class Draw{
private:
//variables
int tekenStyle;
int val;
Servo myservo;
// methods


public:
int getVal();
void setStyle(int);
void chose();
void drawing(bool);
void setServo(Servo);
Draw();
};

#endif;