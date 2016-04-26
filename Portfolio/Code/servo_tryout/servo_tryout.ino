#include <Servo.h>
#define ANGLE 10
Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val = 20;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);  
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){      
      case 'w': moveUp(); break;
      case 's': moveDown(); break;
      case 'a': val = 20; break;
      case 'd': val = 130; break;
      //default: val = (int)Serial.read(); break;
    }
  }
  //val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  //val = map(val, 0, 1023, 0, 160);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
void moveUp(){
  if(val <= 180 - ANGLE){
      val += ANGLE;  
    }
    Serial.print("Angle = ");
    Serial.println(val);
}
void moveDown(){
  if(val >= 20 + ANGLE){
      val -= ANGLE;  
    }
    Serial.print("Angle = ");
    Serial.println(val);
}
    
    
  
  
