#ifndef tank_movement_h
#define tank_movement_h
#define LEFT 0
#define RIGHT 1
#define NONE 3
#define BACKWARDS 0
#define FORWARD 1
#define MIN 0
#define MAX 255
#define STANDARD_SPEED 255
#define TURNING_SPEED 55

#include "Arduino.h"

class Movement{
private:
// variables
int motorRightF = 22;  //motor rechts vooruit
int motorRightB = 23;  //motor rechts achteruit
int motorLeftF = 24;  //motor links vooruit
int motorLeftB = 25; //motor links achteruit
int speedPinR = 7;
int speedPinL = 6;
int speedR = MAX; //snelheid rechter motor
int speedL = MAX; //snelheid linker motor
// methods
void resetSpeed(void);

public:
void input(char);
void driveDirection(int);
void drive(void);
void turn(int);
void uTurn(int);
void brake(void);
void increaseSpeed(void);
void decreaseSpeed(void);
void turnNinetyDegrees(int);
int isDriving(void);
int isTurning(void);
int showSpeed(int);
Movement();
};

#endif;

