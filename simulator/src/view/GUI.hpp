#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <model/vect.hpp>

class GUI {
public:
  void initWindow(const int WIDTH, const int HEIGHT);
private:
  float liveTime = 0;
  SDL_Renderer* rend;
  void drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha);
  void drawWave();
};

#endif
