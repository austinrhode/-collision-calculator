#ifndef WAVE_CONTROLLER_H
#define WAVE_CONTROLLER_H

#include <vector>
#include <thread>
#include <model/wave.hpp>

class GUI;

class waveController {
public:
GUI *gui;
std::vector<wave> waveList;
void updateWaves();
bool running = true;
};

#endif
