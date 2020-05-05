#include "logger/log.hpp"
#include "model/vect.hpp"
#include <iostream>


int main(){
  pbVector v1 = pbVector(1.0, 2.0);
  pbVector v2 = pbVector(2.0, 3.0);
  LOG::log_message("hello world");
  LOG::log_vector(v1);
  LOG::log_vector_pair(v1, v2);
  pbVector result_add = v1 + v2;
  pbVector result_sub = v1 - v2;
  LOG::log_vector_operation(v1, v2, "+", result_add);
  LOG::log_vector_operation(v1, v2, "-", result_sub);
}
