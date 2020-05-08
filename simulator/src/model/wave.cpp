#include "wave.hpp"
#include <cmath>

float wave::calculate_height(float x){
  float dist = (headPosition-x);
  float decay = dist > 0 ? -pow(decayBase, -dist/decayRate) : -pow(decayBase, dist/decayRate);
  return decay*amplitude*sin((x/omega*3)+headPosition);
}
