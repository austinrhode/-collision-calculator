#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <model/wave.hpp>

class waveController;

class GUI {
public:
  GUI(const int WIDTH, const int HEIGHT, const int RESOLUTION, waveController* WAVE_CONT):
    WIDTH(WIDTH),
    HEIGHT(HEIGHT),
    RESOLUTION(RESOLUTION),
    WAVE_CONT(WAVE_CONT)
  { }
  void initWindow();
  waveController* WAVE_CONT;
  const int HEIGHT;
  const int WIDTH;
private:
  const int RESOLUTION;
  SDL_Renderer* rend;
  void drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha);
  void drawWaves();
};

#endif
