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
  void drawPixel(SDL_Renderer* m_window_renderer, int x, int y, int size, uint32_t color);
};

#endif
