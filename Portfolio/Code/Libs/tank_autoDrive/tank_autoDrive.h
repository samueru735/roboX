#ifndef tank_autoDrive_h
#define tank_autoDrive_h
#define TO_LEFT 0
#define TO_RIGHT 1
#define NONE 4
#define REVERSE 5
#define STOP 6
#define NORMAL 2
#define IR_F 0
#define IR_R 1
#define IR_L 2
#define IR_B 3 
#define DISTANCE 200
#define DISTANCE_SIDES 50

#define MIN 0
#define MAX_PANIC 50
#define STANDARD_SPEED 255
#define TURNING_SPEED 55

#include "Arduino.h"
#include "tank_movement.h"
#include "tank_ir_sensor.h"

class AutoDrive{
private:
// variables
Movement movement;
SensorIR sensorFront = SensorIR(IR_F,DISTANCE);
SensorIR sensorRight = SensorIR(IR_R,DISTANCE_SIDES);
SensorIR sensorLeft = SensorIR(IR_L,DISTANCE_SIDES);
SensorIR sensorBack = SensorIR(IR_B,DISTANCE);
bool status;
int panic; // emergency counter

// methods

public:
void setStatus(bool);
bool getStatus();
int testF();
int testR();
int testL();
int testB();
int getValF();
int getValR();
int getValL();
int getValB();
void checkSensors();
void drive(int);

AutoDrive();
};

#endif;

