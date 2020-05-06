#ifndef VECT_H
#define VECT_H
#include <iostream>
#include <ostream>


class pbVector {
public:
  double x;
  double y;
  pbVector(double x, double y);
  pbVector();
  pbVector operator +(pbVector &obj);
  pbVector operator -(pbVector &obj);
  double dot_product(pbVector&);
  double cross_product(pbVector&);
  void setVector(double x, double y);
  friend std::ostream& operator<<(std::ostream& os, const pbVector& obj);
};

#endif
