#include <stdio.h>
#include <cmath>
#include "rigid_body.hpp"

static const pbVector grav_vect = pbVector(0, -9.81);

rigid_body(double mass){
  this->mass = mass;
  this->position_vect = pbVector(0, 0);
  this->velocity_vect = pbVector(0, 0);
  this->acceleration_vect = pbVector(0, 0);
  start_time = std::chrono::high_resolution_clock::now();
}

void free_fall_pos(){
  auto current_time = std::chrono::high_resolution_clock::now();
  auto difference = std::chrono::duration_cast<std::chrono::microseconds>(current_time - start_time);
  float diff_sec =  difference.count()/float(1000000);
  position_vect.y = position_vect.y + (.5*grav_vect.y*(pow(diff_sec, 2)));
}
