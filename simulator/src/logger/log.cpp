#include "log.hpp"
#include <iostream>

namespace LOG{
  void LOG::log_message(const std::string& message){
    std::cout << message << std::endl;
  }
}
