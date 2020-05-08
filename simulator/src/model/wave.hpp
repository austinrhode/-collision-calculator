#ifndef WAVE_H
#define WAVE_H

class wave {
public:
  //this class assumes the wave follows the following equations
  //y=(A*sin(x/omega+time)*(decayBase)^(-decay))+phi
  //ex: y=(10sin((x/2)+4)*2^-3)+100
  wave(float headPosition, float velocity, float amplitude, float omega, float decayBase, float decayRate):
    velocity(velocity),
    amplitude(amplitude),
    omega(omega),
    decayRate(decayRate),
    decayBase(decayBase),
    headPosition(headPosition)
    { }
  float velocity;
  float decayBase;
  float decayRate;
  float headPosition;
  float amplitude;
  float omega;
  float calculate_height(float);
};

#endif
