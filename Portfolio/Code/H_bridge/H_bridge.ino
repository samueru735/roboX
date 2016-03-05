#define MIN 0
#define MAX 255

int speedPinR = 3;       // H-bridge enable pin for speed control 
int motor1APin = 22;     // H-bridge leg 1  
int motor2APin = 23;     // H-bridge leg 2  
int motor3APin = 24;
int motor4APin = 25;
int ledPin = 13;        // status LED 
int speedPinL = 2;
int speed_value_motor1; // value for motor speed  
int speed_value_motor2; 

void setup() {     // set digital i/o pins as outputs:  
  Serial.begin(9600); 
pinMode(speedPinR, OUTPUT);   
pinMode(speedPinL, OUTPUT);  
pinMode(motor1APin, OUTPUT);    
pinMode(motor2APin, OUTPUT);    
pinMode(motor3APin, OUTPUT);    
pinMode(motor4APin, OUTPUT);  
pinMode(ledPin, OUTPUT); 

speed_value_motor1 = 150;
speed_value_motor2 = 150;
} 

void loop() {   
  if(Serial.available()){
    switch(Serial.read()){
      case 'w': forward(); break;
      case 's': backward(); break;
      case 'a': turnLeft(); break;
      case 'd': turnRight(); break;
      case 'p': increaseSpeed(); break;
      case 'o': decreaseSpeed(); break;
      case 'x': brake(); break;
    }
  }
digitalWrite(ledPin, HIGH);  // status LED is always on         

// just invert the above values for reverse motion,     
// i.e. motor1APin = HIGH and motor2APin = LOW            
// control the speed 0- 255           
analogWrite(speedPinR, speed_value_motor1);  // output speed as PWM value  
analogWrite(speedPinL, speed_value_motor2);  // output speed as PWM value  
}

void forward(){
  // put motor in forward motion     
digitalWrite(motor1APin, LOW);   // set leg 1 of the H-bridge low     
digitalWrite(motor2APin, HIGH);  // set leg 2 of the H-bridge high         

digitalWrite(motor3APin, LOW);
digitalWrite(motor4APin, HIGH);
}

void backward(){
  // put motor in backward motion     
digitalWrite(motor2APin, LOW);   // set leg 1 of the H-bridge low     
digitalWrite(motor1APin, HIGH);  // set leg 2 of the H-bridge high         

digitalWrite(motor4APin, LOW);
digitalWrite(motor3APin, HIGH);
}
void brake(){
  digitalWrite(motor1APin, LOW);   // set leg 1 of the H-bridge low     
digitalWrite(motor2APin, LOW);  // set leg 2 of the H-bridge high         

digitalWrite(motor3APin, LOW);
digitalWrite(motor4APin, LOW);
}

void increaseSpeed(){
  if(speed_value_motor1 < MAX-50){
    speed_value_motor1 += 50;
  }  
  if(speed_value_motor2 < MAX-50){
    speed_value_motor2 += 50;
  }
}
void decreaseSpeed(){
  if(speed_value_motor1 > MIN+50){
    speed_value_motor1 -= 50;
  }  
  if(speed_value_motor2 > MIN+50){
    speed_value_motor2 -= 50;
  }
}

void uTturnLeft(){
         
digitalWrite(motor2APin, LOW);   // set leg 1 of the H-bridge low     
digitalWrite(motor1APin, HIGH);  // set leg 2 of the H-bridge high         

digitalWrite(motor4APin, HIGH);
digitalWrite(motor3APin, LOW);
}
void uTurnRight(){
 digitalWrite(motor1APin, LOW);   // set leg 1 of the H-bridge low     
digitalWrite(motor2APin, HIGH);  // set leg 2 of the H-bridge high         

digitalWrite(motor3APin, HIGH);
digitalWrite(motor4APin, LOW); 
}
void turnLeft(){
  if(speed_value_motor1 > MIN + 100){
    speed_value_motor1 = speed_value_motor2 - 100;
  }
  else
  {
    speed_value_motor1 = 0;
  }
}
void turnRight(){
  if(speed_value_motor2 > MIN + 100){
    speed_value_motor2 = speed_value_motor1 - 100;
  }
  else{
    speed_value_motor2 = 0;
  }
}

