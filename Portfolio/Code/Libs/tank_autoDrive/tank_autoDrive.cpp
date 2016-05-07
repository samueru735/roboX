#include "tank_autoDrive.h"

AutoDrive::AutoDrive(){
  pinMode(IR_F, INPUT);
  pinMode(IR_R, INPUT);    
  pinMode(IR_L, INPUT);    
  pinMode(IR_B, INPUT);    
  status = false;
  }
  
  void AutoDrive::setStatus(bool automatic){
	  status = automatic;
  }
  bool AutoDrive::getStatus(){
	  return status;
  }
  
  void AutoDrive::drive(int direction){
	switch(direction){
		case NORMAL: movement.driveDirection(FORWARD); panic = 0; break;
		case TO_RIGHT: movement.turnNinetyDegrees(RIGHT);  break;
		case TO_LEFT: movement.turnNinetyDegrees(LEFT);  break;
		case REVERSE: movement.turnNinetyDegrees(RIGHT);movement.turnNinetyDegrees(RIGHT); break;
		case STOP: movement.brake(); panic++; break;
	}
	if(panic >= MAX_PANIC){
		panic = 0;
		drive(REVERSE);
		
	}
  }

int AutoDrive::testF(){	
	if(sensorFront.Result() == true){ // object detected
		return true;
	}
	else
	{
		return false;
	}
}
int AutoDrive::getValF(){
	return sensorFront.getValue();
}
int AutoDrive::testR(){
	if(sensorRight.Result() == true){
		return true;
	}
	else
	{
		return false;
	}
}
int AutoDrive::getValR(){
	return sensorRight.getValue();
}
int AutoDrive::testL(){
	if(sensorLeft.Result() == true){
		return true;
	}
	else
	{
		return false;
	}
}
int AutoDrive::getValL(){
	return sensorLeft.getValue();
}
int AutoDrive::testB(){
	if(sensorBack.Result() == true){
		return true;
	}
	else
	{
		return false;
	}
}
int AutoDrive::getValB(){
	return sensorBack.getValue();
}

void AutoDrive::checkSensors(){
	if (testF() == true){
		if(testR() == true){
			if(testL() == true){
				drive(REVERSE); 
			}
			else{
				drive(TO_LEFT);
			}
		}
		else{
			if(testL() == true){
				drive(TO_RIGHT);
			}
			else{
				drive(STOP);
			}
		}
	}
	else{
		drive(NORMAL); return;
	} 
	
}