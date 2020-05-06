#include "vect.hpp"
#include "logger/log.hpp"
#include <string>


using namespace std;

  pbVector::pbVector(double x, double y){
    this->x = x;
    this->y = y;
  }

  pbVector::pbVector(){
    this->x = 0;
    this->y = 0;
  }

  pbVector pbVector::operator +(pbVector &obj) {
    return pbVector(this->x + obj.x, this->y + obj.y);
}

pbVector pbVector::operator -(pbVector &obj) {
  return pbVector(this->x - obj.x, this->y - obj.y);
}

double pbVector::dot_product(pbVector &obj){
  return this->x * obj.x + this->y * obj.y;
}

double pbVector::cross_product(pbVector &obj){
  ;
}

  ostream& operator<<(ostream& os, const pbVector& obj)
{
    // print in terms of public interface of S
    // (else, deckare this a friend function inside S)
    os << "<" << obj.x << ", " << obj.y << ">";
    return os;
}

  void pbVector::setVector(double x, double y){
    this->x = x;
    this->y = y;
  }
