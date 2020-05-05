#ifndef VECT_H
#define VECT_H
#include <iostream>
#include <ostream>

class vect {
public:
  int xVal, yVal;
  vect(int xVal, int yVal);
  vect();
  vect operator + (vect const &obj);
  vect operator - (vect const &obj);
  void setVector(int x, int y);
  friend std::ostream& operator<<(std::ostream& os, const vect& obj);
};

#endif
