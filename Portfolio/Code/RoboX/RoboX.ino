#include <tank_ir_sensor.h>

#include <tank_autoDrive.h>

#include <Servo.h>
#include <draw.h>
#include <tank_movement.h>
#include <tank_leds.h>

//init
int ledPin = 13;        // status LED 
int irSensorPin = 4;
bool btConnection = false;
Lights leds;
Movement movement;
Draw draw;
AutoDrive autoDrive;

Servo myservo; //servo motor voor de pen

void setup() {     // set digital i/o pins as outputs:  
  pinMode(irSensorPin, INPUT);
  Serial.begin(9600); 
  leds.lightsOn(ON);  // call lightsOn() method from Lights library
  myservo.attach(9);
  draw.setServo(myservo);
} 

void loop() {   
  if(Serial.available()){   
    //  read input and use Movent library to drive in the right direction
    switch(Serial.read()){      
      case 'w': movement.driveDirection(FORWARD);
                autoDrive.setStatus(false); break;
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
      case 'x': movement.brake();autoDrive.setStatus(false); 
                leds.brake(ON); break;
      case 'y': movement.turnNinetyDegrees(LEFT); break;
      case 'u': movement.turnNinetyDegrees(RIGHT); break;
     //draw methode
      case'c': autoDrive.setStatus(true);
      //testIRSensors();
      break;
      case'f': draw.setStyle(DOT);break;
      case'g': draw.setStyle(DASH);break;
      case'h': draw.setStyle(LINE);break;
      case't': draw.setStyle(STOP);break;
      case'b': btConnection =true;break;
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

   switch(autoDrive.getStatus()){
    case true: autoDrive.checkSensors();
    //testIRSensors();
    break;
    default:break;
  }

  if(btConnection == true)
  {
    leds.connection(true);
  }
  if(btConnection == false)
  {
    leds.connection(false);
  }  
  
  movement.drive();  // drive it

  draw.chose();
  
 
  
 // myservo.write(draw.getVal());
  //delay(15);
}

void testIRSensors(){
  Serial.print("Sensor front: ");
  Serial.println(autoDrive.testF());
  Serial.println(autoDrive.getValF());
  Serial.print("Sensor right: ");
  Serial.println(autoDrive.testR());
  Serial.println(autoDrive.getValR());
  Serial.print("Sensor left: ");
  Serial.println(autoDrive.testL());
  Serial.println(autoDrive.getValL());
  Serial.print("Sensor back: ");
  Serial.println(autoDrive.testB());
  Serial.println(autoDrive.getValB());
}

