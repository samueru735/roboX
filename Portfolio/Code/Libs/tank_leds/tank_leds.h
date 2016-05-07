#ifndef tank_leds_h
#define tank_leds_h
#define LEFT 0
#define RIGHT 1
#define REAR 3 
#define OFF 0
#define ON 1
#define BLINK_DELAY 250

#include "Arduino.h"

class Lights{
private:
int kracht = 0;
int led_50 = 50;  //leds links
int led_51 = 51;  //leds rechts
int led_52 = 52;  //stoplicht
int led_1 = 1;	  //connectlicht
public:
void ledLeft(int);
void ledRight(int);
void lightsOn(int);
void brake(int);
void blink(int);
void connection(int);
Lights();
};

#endif;

