#ifndef GUI_H
#define GUI_H

// for initializing and sutdown functions
#include <SDL2/SDL.h>

// for rendering images and graphics on screen
#include <SDL2/SDL_image.h>

// for using SDL_Delay() functions
#include <SDL2/SDL_timer.h>

#include <model/vect.hpp>

namespace GUI {
  void initWindow();
}

#endif
