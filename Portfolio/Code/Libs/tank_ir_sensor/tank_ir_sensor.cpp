/*
tank_ir_sensor.cpp -Description cpp
*/

#include "arduino.h"
#include "tank_ir_sensor.h"

SensorIR::SensorIR(int IRpin,int distance)
{
  _IRpin = IRpin;
  _distance = distance;  
  pinMode(_IRpin, INPUT);
}
bool SensorIR::Result()
{
	if(analogRead(_IRpin) >= _distance){
		return true;	
	}
    else{
		return false;
	}
}
int SensorIR::getValue()
{
	return analogRead(_IRpin);
}