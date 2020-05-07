#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <model/vect.hpp>
#include <model/wave.hpp>

class GUI {
public:
  GUI(const int WIDTH, const int HEIGHT, const int RESOLUTION):
    WIDTH(WIDTH),
    HEIGHT(HEIGHT),
    RESOLUTION(RESOLUTION)
  { }
  void initWindow();
private:
  const int HEIGHT;
  const int WIDTH;
  const int RESOLUTION;
  float liveTime = 0;
  SDL_Renderer* rend;
  void drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha);
  void drawWave(wave& w);
};

#endif
