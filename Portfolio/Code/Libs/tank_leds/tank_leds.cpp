#include "tank_leds.h"

Lights::Lights(){
  pinMode(led_50, OUTPUT);
  pinMode(led_51, OUTPUT);
  pinMode(led_52, OUTPUT);
  pinMode(led_1, OUTPUT);
}

void Lights::connection(int connectStatus)
{
	
	if(connectStatus == TRUE)
	{
		if(kracht < 255)
		{
			kracht+=5;
		}
		analogWrite(led_1, kracht);
		delay(50);
	}
	if(connectStatus == FALSE)
	{
		if(kracht >= 5)
		{
			kracht-=5;
		}
		analogWrite(led_1, kracht);
		delay(50);
	}
	
}
void Lights::ledLeft(int state)
{ 
	if(state == ON){
		digitalWrite(led_50, HIGH);  
	}
	else{
		digitalWrite(led_50, LOW);  
	}  
}
void Lights::ledRight(int state)
{ 
  if(state == ON){
		digitalWrite(led_51, HIGH);  
	}
	else{
		digitalWrite(led_51, LOW);  
	}  
}
void Lights::blink(int side){
	if(side == LEFT ){
		ledLeft(ON);
		delay(BLINK_DELAY);
		ledLeft(OFF);
		delay(BLINK_DELAY);
	}
	else if(side == RIGHT){
		ledRight(ON); 
		delay(BLINK_DELAY);
		ledRight(OFF);
		delay(BLINK_DELAY);
	}	
	if(side == REAR){	
		brake(ON);
		delay(BLINK_DELAY);
		brake(OFF);
		delay(BLINK_DELAY);
	}
}
void Lights::brake(int state)
{ 
  if(state == ON){
		digitalWrite(led_52, HIGH);  
	}
	else{	// state == OFF
		digitalWrite(led_52, LOW);  
	}  
}
void Lights::lightsOn(int state)
{
	if(state == ON){
		ledLeft(ON);ledRight(ON);  
	}
	else{	// state == OFF
		ledLeft(OFF);ledRight(OFF);  
	}  
	
}
