#include <SensorX.h>
SensorX SensorFront(2,3,4);
SensorX SensorRight(4,5,4);
SensorX SensorLeft(6,7,4);
SensorX SensorBack(8,9,4);

bool Voor;
bool Rechts;
bool Links;
bool Achter;



void setup() {
  Serial.begin(9600);
  

}

void loop() {
  Sensor_Status();
  Sensors_Result();
  
}
void Sensor_Status(){
  Voor=SensorFront.Result();
  Rechts=SensorRight.Result();
  Links=SensorLeft.Result();
  Achter=SensorBack.Result(); 
}

void Sensors_Result(){
  if(Voor&&Rechts==false&&Links==false&&Achter==false){
    Serial.println("Allen Voor");
  }
  if(Voor&&Rechts&&Links==false&&Achter==false){
    Serial.println("Voor en Links");
  }
  if(Voor&&Rechts==false&&Links&&Achter==false){
    Serial.println("Voor en Links");
  }
  if(Voor==false&&Rechts==false&&Links&&Achter==false){
    Serial.println("Allen Links");
  }
  if(Voor==false&&Rechts&&Links==false&&Achter==false){
    Serial.println("Allen Rechts");
  }
  if(Voor==false&&Rechts==false&&Links==false&&Achter){
    Serial.println("Allen Achter");
  }
  else{
    Serial.println("");
  }
  
}

