#include <tank_movement.h>
#include <tank_leds.h>

//init
int ledPin = 13;        // status LED 
Lights leds;
Movement movement;

void setup() {     // set digital i/o pins as outputs:  
  Serial.begin(9600); 
  leds.lightsOn(ON);  // call lightsOn() method from Lights library
} 

void loop() {   
  if(Serial.available()){   
    //  read input and use Movent library to drive in the right direction
    switch(Serial.read()){      
      case 'w': movement.driveDirection(FORWARD); break;
      case 's': movement.driveDirection(BACKWARDS); break;
      case 'a': movement.turn(LEFT); 
                //leds.blink(LEFT);
                break;      
      case 'd': movement.turn(RIGHT); 
                //leds.blink(RIGHT);
                break;
      case 'm': movement.uTurn(RIGHT);break;
      case 'n': movement.uTurn(LEFT);break;
      case 'p': movement.increaseSpeed(); break;
      case 'o': movement.decreaseSpeed(); break;
      case 'x': movement.brake(); 
                leds.brake(ON);
                break;
    }
    Serial.print("speed L: ");    
    Serial.println(movement.showSpeed(LEFT)); // monitor speed (0-255) left motor
    Serial.print("speed R: ");
    Serial.println(movement.showSpeed(RIGHT)); // monitor speed (0-255) right motor
  }
  switch(movement.isDriving()){   
    case FORWARD: leds.brake(OFF); break;     // normal lighting when moving forward
    case BACKWARDS: leds.blink(REAR); break;  // flashing light when going backwards
    case NONE: leds.brake(ON); break; // brake light
  }
  switch(movement.isTurning()){
    case RIGHT: leds.blink(RIGHT); break;   // blink right
    case LEFT: leds.blink(LEFT); break;     // blink left
    case NONE: leds.lightsOn(ON); break;    // reset lights to normal
  }
  digitalWrite(ledPin, HIGH);  // status LED is always on        
  movement.drive();  // drive it
}

