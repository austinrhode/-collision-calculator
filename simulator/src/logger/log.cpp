#include "log.hpp"
#include "model/vect.hpp"
#include <iostream>

namespace LOG{
  void LOG::log_message(const std::string& message){
    std::cout << message << std::endl;
  }
  void LOG::log_vector(pbVector v1){
    std::cout << "Vector Value is " << v1 << std::endl;
  }
  void LOG::log_vector_pair(pbVector v1, pbVector v2){
    std::cout << "Vector 1 Value is " << v1  << ", Vector 2 Value is " << v2 << std::endl;
  }
  void LOG::log_vector_operation(pbVector v1, pbVector v2, std::string operation, pbVector result){
    std::cout << v1 << " " << operation << " " << v2 << " = " << result << std::endl;
  }
  void LOG::log_vector_product(pbVector v1, pbVector v2, std::string operation, double result){
    std::cout << v1 << " " << operation << " " << v2 << " = " << result << std::endl;
  }
}
