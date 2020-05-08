#ifndef WAVE_CONTROLLER_H
#define WAVE_CONTROLLER_H

#include <vector>
#include <thread>
#include <model/wave.hpp>
#include <model/boat.hpp>

class GUI;

class waveController {
public:
GUI *gui;
std::vector<wave> waveList;
std::vector<boat> boatList;
void updateWaves();
void updateBoats();
void updateWorld();
bool running = true;
float phi = 200;
};

#endif
