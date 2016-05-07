#include "tank_movement.h"

Movement::Movement(){
  pinMode(motorRightF, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorLeftF, OUTPUT);  
  pinMode(motorLeftB, OUTPUT);  
}
/*void Movement::input(input){
	switch (input){
	  case 'w': drive(FORWARD); break;
      case 's': drive(BACKWARDS); break;
      case 'a': turn(LEFT); break;
      case 'd': turn(RIGHT); break;
      case 'm': uTurn(RIGHT);break;
      case 'n': uTurn(LEFT);break;
      case 'p': increaseSpeed(); break;
      case 'o': decreaseSpeed(); break;
      case 'x': brake(); break;
	}
}*/
void Movement::drive(){
	analogWrite(speedPinR, speedR);  // output speed as PWM value  
	analogWrite(speedPinL, speedL);  // output speed as PWM value  
	if(	digitalRead(motorRightF) == HIGH && digitalRead(motorRightB) == LOW && digitalRead(motorLeftB) == LOW 
	&& digitalRead(motorLeftF) == HIGH) {
		Serial.println("Driving forward");
	}
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
void Movement::turnNinetyDegrees(int direction){
	if(direction == LEFT){
		digitalWrite(motorRightF, HIGH);
		digitalWrite(motorRightB, LOW);        
		digitalWrite(motorLeftF, LOW);
		digitalWrite(motorLeftB, HIGH);		
		Serial.println("Turning 90 degrees to the left");
	}
	else{
		digitalWrite(motorRightB, HIGH);
		digitalWrite(motorRightF, LOW);        
		digitalWrite(motorLeftF, HIGH);
		digitalWrite(motorLeftB, LOW);
		Serial.println("Turning 90 degrees to the right");
	}
	delay(1000);
	brake();
}

void Movement::brake(){
	resetSpeed();
	digitalWrite(motorRightF, LOW);
	digitalWrite(motorRightB, LOW);         
	digitalWrite(motorLeftB, LOW);
	digitalWrite(motorLeftF, LOW);
	Serial.println("Braking..");
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
