#include "Arduino.h"
#ifndef Position_h
#define Position_h

class Position{
  private:
  int r_pos;
  int c_pos;

  public:
  Position();
  Position(int row, int col);

  void setPosition(int row, int col);
  int getR();
  void setR(int r);
  int getC();
  void setC(int c);
};
#endif
