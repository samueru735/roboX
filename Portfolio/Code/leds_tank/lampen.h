#ifndef lampen_h
#define lampen_h
#include "Arduino.h"

class Lampen{
private:
int led_50 = 50;  //led voor links
int led_51 = 51;  //led voor rechts
int led_52 = 52;  //led achter links
int led_53 = 53;  //led achter rechts
public:
void ledLeft(void);
void ledRight(void);
void ledStop(void);
Lampen();
};

#endif;

