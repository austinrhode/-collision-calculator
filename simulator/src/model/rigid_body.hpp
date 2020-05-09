#ifndef RIGID_H
#define RIGID_H
#include <iostream>
#include <model/vect.hpp>

class rigid_body {
public:
  double mass;
  const pbVector grav_vect = pbVector(0, -9.81);
  pbVector velocity_vect;
  pbVector position_vect;
  //Needed????
  pbVector momentum;
}
