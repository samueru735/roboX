/*
  SensorIR.h - Descripción de la librería 
*/
#ifndef tank_ir_sensor_h
#define tank_ir_sensor_h
#include "arduino.h"
class SensorIR {
  public:
   SensorIR(int IRpin, int distance);
   // methods
   bool Result();
   int getValue();
   
  private:  
   int _IRpin;
   int _distance;
   
   
};
#endif
