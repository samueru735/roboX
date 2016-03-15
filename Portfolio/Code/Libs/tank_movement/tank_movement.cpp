#include "tank_movement.h"

Movement::Movement(){
  pinMode(motorRightF, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorLeftF, OUTPUT);  
  pinMode(motorLeftB, OUTPUT);  
}

void Movement::drive(){
	analogWrite(speedPinR, speedR);  // output speed as PWM value  
	analogWrite(speedPinL, speedL);  // output speed as PWM value  
}
void Movement::driveDirection(int direction){
	resetSpeed();
	if(direction == FORWARD){
		digitalWrite(motorRightF, HIGH);
		digitalWrite(motorRightB, LOW);        
		digitalWrite(motorLeftF, HIGH);
		digitalWrite(motorLeftB, LOW);
	}
	else if (direction == BACKWARDS){
		digitalWrite(motorRightB, HIGH);
		digitalWrite(motorRightF, LOW);        
		digitalWrite(motorLeftB, HIGH);
		digitalWrite(motorLeftF, LOW);
	}
}
void Movement::resetSpeed(){
	speedR = STANDARD_SPEED;
	speedL = STANDARD_SPEED;
}
void Movement::turn(int direction)
{ 
	resetSpeed();
	if(direction == LEFT){
		speedL = TURNING_SPEED;
	}
	else{	// direction is RIGHT
		speedR = TURNING_SPEED;
	}  
}
void Movement::uTurn(int direction)
{ 
	resetSpeed();
	if(direction == LEFT){
		digitalWrite(motorRightF, HIGH);
		digitalWrite(motorRightB, LOW);        
		digitalWrite(motorLeftF, LOW);
		digitalWrite(motorLeftB, HIGH);
	}
	else{ // direction is RIGHT
		digitalWrite(motorRightB, HIGH);
		digitalWrite(motorRightF, LOW);        
		digitalWrite(motorLeftF, HIGH);
		digitalWrite(motorLeftB, LOW);
	}  
}

void Movement::brake(){
	resetSpeed();
	digitalWrite(motorRightF, LOW);
	digitalWrite(motorRightB, LOW);         
	digitalWrite(motorLeftB, LOW);
	digitalWrite(motorLeftF, LOW);
}
void Movement::increaseSpeed(){
	if(speedR < MAX-50){
		speedR += 50;
	}  
	else{
		speedR = MAX;
	}
	if(speedL < MAX-50){
		speedL += 50;
	}
	else{
		speedL = MAX;
	}  
}
void Movement::decreaseSpeed(){
	if(speedR > MIN+50){
		speedR -= 50;
	}  
	else{
		speedR = MIN;
	}
	if(speedL > MIN+50){
		speedL -= 50;
	}
	else{
		speedL = MIN;
	} 
}
int Movement::showSpeed(int side){
	if (side == LEFT){
		return speedL;
	}
	else if(side == RIGHT){
		return speedR;
	}
}

int Movement::isDriving(){
	if(digitalRead(motorRightF) == HIGH && digitalRead(motorRightB)== LOW) //tank is moving forward
	{
		return FORWARD;
	}
	else if(digitalRead(motorRightF) == LOW && digitalRead(motorRightB)== HIGH) {	//tank is moving backwards 
		return BACKWARDS;
	}
	else {
		return NONE;
	}
}
int Movement::isTurning(){
	if(speedL != speedR){
		if(speedL < speedR){
			return LEFT;
		}
		else {	// speedL > speedR
			return RIGHT;
		}
	}
	return NONE;
}
