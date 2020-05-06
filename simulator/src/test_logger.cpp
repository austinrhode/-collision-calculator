#include "logger/log.hpp"
#include "model/vect.hpp"
#include <iostream>

int main(){
  log logger;
  pbVector v1 = pbVector(1.0, 2.0);
  pbVector v2 = pbVector(2.0, 3.0);
  logger.log_message("hello world");
  logger.log_vector(v1);
  logger.log_vector_pair(v1, v2);
  pbVector result_add = v1 + v2;
  pbVector result_sub = v1 - v2;
  logger.log_vector_operation(v1, v2, "+", result_add);
  logger.log_vector_operation(v1, v2, "-", result_sub);
}
