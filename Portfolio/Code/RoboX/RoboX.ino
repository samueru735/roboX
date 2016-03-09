#include <tank_movement.h>
#include <tank_leds.h>

int ledPin = 13;        // status LED 

Lights leds;
Movement movement;

void setup() {     // set digital i/o pins as outputs:  
  Serial.begin(9600); 

  leds.lightsOn(ON);
} 

void loop() {   
  if(Serial.available()){   
    //movement.input(Serial.read()); 
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
    Serial.println(movement.showSpeed(LEFT));
    Serial.print("speed R: ");
    Serial.println(movement.showSpeed(RIGHT));
  }

  switch(movement.isDriving()){
    case FORWARD: leds.brake(OFF); break;
    case BACKWARDS: leds.blink(REAR); break;
    case NONE: leds.brake(ON); break;
  }
  switch(movement.isTurning()){
    case RIGHT: leds.blink(RIGHT); break;
    case LEFT: leds.blink(LEFT); break;
    case NONE: leds.lightsOn(ON); break;
  }

  digitalWrite(ledPin, HIGH);  // status LED is always on  
         
  movement.drive();  // drive it
}

