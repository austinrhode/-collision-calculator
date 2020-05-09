#ifndef RIGID_H
#define RIGID_H
#include <iostream>
#include <model/vect.hpp>
#include <chrono>

class rigid_body {
public:
  double mass;
  static const pbVector grav_vect;
  pbVector velocity_vect;
  pbVector position_vect;
  pbVector acceleration_vect;
  //Needed????
  pbVector momentum;
  std::chrono::time_point<std::chrono::system_clock> start_time;
  rigid_body(double mass);
  void free_fall_pos();
  virtual void collide();

};
#endif
