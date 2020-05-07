#ifndef WAVE_H
#define WAVE_H

class wave {
public:
  //this class assumes the wave follows the following equations
  //y=(A*sin(x/omega+time)*(decayBase)^(-decay))+phi
  //ex: y=(10sin((x/2)+4)*2^-3)+100
  wave(float headPosition, float velocity, float amplitude, float omega, float phi, float decayBase, float decayRate, uint32_t color, int alpha):
    velocity(velocity),
    amplitude(amplitude),
    omega(omega),
    phi(phi),
    color(color),
    alpha(alpha),
    decayRate(decayRate),
    decayBase(decayBase),
    headPosition(headPosition)
    { }
  const float velocity;
  const float decayBase;
  const float decayRate;
  float headPosition;
  const float amplitude;
  const float omega;
  const float phi;
  const uint32_t color;
  const int alpha;
};

#endif
