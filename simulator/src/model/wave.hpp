#ifndef WAVE_H
#define WAVE_H

class wave {
public:
  wave(float a, float o, float p, uint32_t c, int al):
    amplitude(a),
    omega(o),
    phi(p),
    color(c),
    alpha(al)
    { }
  const float amplitude;
  const float omega;
  const float phi;
  const uint32_t color;
  const int alpha;
};

#endif
