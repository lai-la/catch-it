#include "Arduino.h"
#include "Position.h"

Position::Position(){
  
};

Position::Position(int r, int c){
  if(r>=0&&r<=7 && c>=0 && c<=7){
    r_pos =r;
    c_pos =c;
  }else{
    printf("Please check values: must be between 0 and 7");
  }
};

void Position::setPosition(int r, int c){
  r_pos=r;
  c_pos=c;
}

int Position::getR(){
  return r_pos;
}
  
void Position::setR(int r){
  r_pos=r;
}

int Position::getC(){
  return c_pos;
}

void Position::setC(int c){
  c_pos=c;
}
