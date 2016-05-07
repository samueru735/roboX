#include "draw.h"

Draw::Draw(){
  
  tekenStyle = STOP;
  
}


void Draw::chose(){
	if(tekenStyle == DOT){
		
		drawing(true);
		delay(100);
		drawing(false);
		delay(100);
	}
	if(tekenStyle == DASH){
		
		drawing(true);
		delay(300);
		drawing(false);
		delay(300);
	}
	if(tekenStyle == LINE)
	{
		drawing(true);
	}
	if(tekenStyle == STOP)
	{
		drawing(false);
	}
}

void Draw::drawing(bool signal){
	
	if(signal == true)
	{
		
		myservo.write(UP);
		//Serial.print("Angle = ");
		//Serial.println(UP);
	}
	if(signal == false)
	{
		myservo.write(DOWN);
		//Serial.print("Angle = ");
		//Serial.println(DOWN);
	}    	
}

void Draw::setStyle(int style){
	if(style == DOT)
	{
		tekenStyle = DOT;
	}
	if(style == DASH)
	{
		tekenStyle = DASH;
	}
	if(style == LINE)
	{
		tekenStyle = LINE;
	}
	if(style == STOP)
	{
		tekenStyle = STOP;
	}
}
 int Draw::getVal(){
	 return val;
 }
 void Draw::setServo(Servo servo){
	 myservo = servo;
	 
	 
 }


