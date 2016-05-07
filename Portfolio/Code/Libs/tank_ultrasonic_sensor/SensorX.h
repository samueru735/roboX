/*
  SensorX.h - Descripción de la librería 
*/
#ifndef SensorX_h
#define SensorX_h
#include "arduino.h"
class SensorX {
  public:
   SensorX(int trigerPin,int echoPin, int maxAfstand);
   // methods
   bool Result();
   
  private:  
   int _trigerPin;
   int _echoPin;
   int _maxAfstand;
   
   
};
#endif
