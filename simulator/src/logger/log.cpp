#include "log.hpp"
#include "model/vect.hpp"
#include <iostream>

log::log(){
  this->file.open("vectorOut.txt");
}

void log::log_message(const std::string& message){
  file << message << "\n";
}
void log::log_vector(pbVector v1){
  file << "Vector Value is " << v1 << "\n";
}
void log::log_vector_pair(pbVector v1, pbVector v2){
  file << "Vector 1 Value is " << v1  << ", Vector 2 Value is " << v2 << "\n";
}
void log::log_vector_operation(pbVector v1, pbVector v2, std::string operation, pbVector result){
  file << v1 << " " << operation << " " << v2 << " = " << result << "\n";
}
void log::log_vector_product(pbVector v1, pbVector v2, std::string operation, double result){
  file << v1 << " " << operation << " " << v2 << " = " << result << "\n";
}
