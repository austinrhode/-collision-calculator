#include "wave.hpp"
#include <cmath>
#include <iostream>

float wave::calculate_height(float x){
  float poly = pow(x-headPosition,2);
  float decay = pow(decayBase,-decayRate*poly);
  return decay*amplitude*sin(-x/omega);
  //note - to add time, simply set the sin to sin(-(x-headPosition)/omega+liveTime)
}
