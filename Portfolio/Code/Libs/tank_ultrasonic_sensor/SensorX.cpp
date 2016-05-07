/*
SensorX.cpp -Descripción cpp
*/

#include "arduino.h"
#include "SensorX.h"

SensorX::SensorX(int trigerPin,int echoPin, int maxAfstand)
{
  _trigerPin = trigerPin;
  _echoPin = echoPin;
  _maxAfstand = maxAfstand;
  pinMode(_trigerPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}
bool SensorX::Result()
{
	long duration;
    long distance;
	// Clears the trigPin
	digitalWrite(_trigerPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(_trigerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trigerPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(_echoPin, HIGH);
	// Calculating the distance
	distance= duration*0.034/2;
	Serial.print(distance);
	Serial.println(" cm");
	if(distance<=_maxAfstand){
		return true;	
	}
	if(distance>_maxAfstand){
		return false;	
	}	
}
