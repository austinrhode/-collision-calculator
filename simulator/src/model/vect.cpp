#include "vect.hpp"


using namespace std;

  vect::vect(int xVal, int yVal){
    this->xVal = xVal;
    this->yVal = yVal;
  }

  vect::vect(){
    this->xVal = 0;
    this->yVal = 0;
  }

  vect vect::operator + (vect const &obj) {
      vect result = vect(this->xVal + obj.xVal, this->yVal + obj.yVal);
      return result;
  }

  ostream& operator<<(ostream& os, const vect& obj)
{
    // print in terms of public interface of S
    // (else, deckare this a friend function inside S)
    os << "<" << obj.xVal << ", " << obj.yVal << ">";
    return os;
}

  void vect::setVector(int x, int y){
    this->xVal = x;
    this->yVal = y;
  }
