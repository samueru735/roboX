#include <SensorX.h>

SensorX SensorFront(2,3,4);
SensorX SensorRight(4,5,4);
SensorX SensorLeft(6,7,4);




void setup() {
  Serial.begin(9600);
  

}

void loop() {
  if(SensorFront.Result()&&SensorRight.Result()==false&&SensorLeft.Result()==false){
    Serial.println("Voor");
  }
  if(SensorRight.Result()&&SensorFront.Result()==false&&SensorLeft.Result()==false){
    Serial.println("Rechts");
  }
  if(SensorLeft.Result()&&SensorRight.Result()==false&&SensorFront.Result()==false){
    Serial.println("Links");
  }

}
