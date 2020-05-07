#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <model/vect.hpp>
#include <model/wave.hpp>
#include <vector>

class GUI {
public:
  GUI(const int WIDTH, const int HEIGHT, const int RESOLUTION):
    WIDTH(WIDTH),
    HEIGHT(HEIGHT),
    RESOLUTION(RESOLUTION)
  { }
  void initWindow();
  std::vector<wave> waveList;
  bool closed;
private:
  const int HEIGHT;
  const int WIDTH;
  const int RESOLUTION;
  SDL_Renderer* rend;
  void drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha);
  void drawWaves();
};

#endif
