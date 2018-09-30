
#include "LedControl.h"

LedControl lc=LedControl(12,10,11,1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lc.shutdown(0,false); //wakeup call
  lc.setIntensity(0,8); // brightnes to medium value
  lc.clearDisplay(0); // clear display

}

void loop() {
  int r = random(0,8);
  int c = random(0,8);
  lc.setLed(0,r,c,true);
  delay(500);
  lc.setLed(0,r,c,false);
  delay(500);
  // put your main code here, to run repeatedly:

}
