#include "math.h"
#include "LedControl.h"
#include "Position.h"


const int SW_pin =2;
const int X_pin=0;
const int Y_pin=1;

LedControl lc=LedControl(12,10,11,1);

Position pos(0,0);


typedef enum {
  RIGHT, LEFT, UP, DOWN, STOP
} Dir;

void setup() {
  // put your setup code here, to run once:
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin,HIGH),
  Serial.begin(9600);

  lc.shutdown(0,false); //wakeup call
  lc.setIntensity(0,8); // brightnes to medium value
  lc.clearDisplay(0); // clear display

  countDown();
  lc.clearDisplay(0);
  lc.setLed(0,pos.getR(),pos.getC(),true);
 

}

void countDown(){
  byte zero[3]={B01111100,B01000100,B01111100};
  byte one[3]={B00000000,B01111100,B00000000};
  byte two[3]={B01110100,B01010100,B01011100};
  byte three[3]={B01111100,B01010100,B01010100};
  
  lc.setColumn(0,2,three[2]);
  lc.setColumn(0,3,three[1]);
  lc.setColumn(0,4,three[0]);

  delay(500);

  lc.setColumn(0,2,two[2]);
  lc.setColumn(0,3,two[1]);
  lc.setColumn(0,4,two[0]);

  delay(500);
  
  lc.setColumn(0,2,one[2]);
  lc.setColumn(0,3,one[1]);
  lc.setColumn(0,4,one[0]);
  
  delay(500);

  lc.setColumn(0,2,zero[2]);
  lc.setColumn(0,3,zero[1]);
  lc.setColumn(0,4,zero[0]);

  delay(500);
   
}

Dir control(){
  int x =analogRead(X_pin)-512;
  int y =-(analogRead(Y_pin)-512);
  int r=30;

  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);
  Serial.print(" -> ");
  if(square(x)+square(y)<=square(r)){
    Serial.print("stop");
    Serial.print("\n");
    return STOP;
  }
  else if(y>0&&y>=fabs(x)){
    Serial.print("up");
    Serial.print("\n");
    return UP;
  }
  else if(y<0&&fabs(y)>=fabs(x)){
    Serial.print("down");
    Serial.print("\n");
    return DOWN;
  }
  else if(x>0&&x>=fabs(y)){
    Serial.print("right");
    Serial.print("\n");
    return RIGHT;
  }
  else{
    Serial.print("left");
    Serial.print("\n");
    return LEFT;
  }
}

void movement(Dir dir){
switch(dir){
    case UP:
     if(pos.getR()==0){
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setR(7);
      lc.setLed(0,pos.getR(),pos.getC(),true);
    }else{
      lc.setLed(0,pos.getR()-1,pos.getC(),true);
      delay(100);
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setR(pos.getR()%8-1);
    }
       
         
    break;

    case DOWN:
    if(pos.getR()==7){
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setR(0);
      lc.setLed(0,pos.getR(),pos.getC(),true);
    }else{
      lc.setLed(0,pos.getR()+1,pos.getC(),true);
      delay(100);
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setR(pos.getR()%8+1);
    }

    break;

    case LEFT:
     if(pos.getC()==0){
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setC(7);
      lc.setLed(0,pos.getR(),pos.getC(),true);
    }else{
      lc.setLed(0,pos.getR(),pos.getC()-1,true);
      delay(100);
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setC(pos.getC()%8-1);
    }

    break;

    case RIGHT:
        if(pos.getC()==7){
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setC(0);
      lc.setLed(0,pos.getR(),pos.getC(),true);
    }else{
      lc.setLed(0,pos.getR(),pos.getC()+1,true);
      delay(100);
      lc.setLed(0,pos.getR(),pos.getC(),false);
      pos.setC(pos.getC()%8+1);
    }

    break;

    case STOP:
    break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Dir dir = control();
  movement(dir);
  delay(100);
  

}
