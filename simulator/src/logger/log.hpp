#ifndef LOG_H
#define LOG_H
#include "model/vect.hpp"
#include <string>

namespace LOG{
    void log_message(const std::string&);
    void log_vector(pbVector);
    void log_vector_pair(pbVector, pbVector);
    void log_vector_operation(pbVector, pbVector, std::string, pbVector);
    void log_vector_product(pbVector, pbVector, std::string, double);
}

#endif
