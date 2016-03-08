#include "lampen.h"

Lampen::Lampen(){
  pinMode(led_50, OUTPUT);
  pinMode(led_51, OUTPUT);
  pinMode(led_52, OUTPUT);
  pinMode(led_53, OUTPUT);
}

void Lampen::ledLeft()
{ delay(250);
  digitalWrite(led_50, HIGH);
  digitalWrite(led_52, HIGH);
}
void Lampen::ledRight()
{ delay(250);
  digitalWrite(led_51, HIGH);
  digitalWrite(led_53, HIGH);
}
void Lampen::ledStop()
{ delay(250);
  digitalWrite(led_52, HIGH);
  digitalWrite(led_53, HIGH);
}
