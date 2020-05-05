#include <iostream>
#include <model/vect.hpp>
using namespace std;
int main(){
  vect x;
  x.setVector(2, 6);
  vect y;
  y.setVector(2, 7);
  vect sumRes;
  sumRes = x + y;
  cout << "The resultant sum vector is: " << sumRes <<endl;
  return 0;
}
