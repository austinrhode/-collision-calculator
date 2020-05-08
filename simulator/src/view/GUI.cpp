#include "GUI.hpp"
#include <model/wave.hpp>
#include <chrono>
#include <iostream>
#include <cmath>
#include <model/waveController.hpp>

void GUI::drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha) {
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = width;
  rect.h = height;

  int r = ((color & 0xFF0000) >> 16);
  int g = ((color & 0x00FF00) >>  8);
  int b = ((color & 0x0000FF) >>  0);

  SDL_SetRenderDrawColor(rend, r, g, b, alpha);
  SDL_RenderFillRect(rend, &rect);
}

void GUI::drawWaves() {
  uint32_t color = 0x36ffe7;
  int alpha = 150;
  int phi = 200;

  for(int i = 0; i < WIDTH/RESOLUTION; i++) {
    float height = 0;
    for(wave w : WAVE_CONT->waveList) {
      height += w.calculate_height(i);
    };
    drawRect(float(i*RESOLUTION),HEIGHT-height-phi,RESOLUTION,HEIGHT-height, color, alpha);
  }
}

void GUI::drawBoats() {
  for(boat b : WAVE_CONT->boatList) {
    SDL_Rect boat_rect;
    boat_rect.x = b.xPos;
    boat_rect.y = b.yPos;
    boat_rect.w = b.width;
    boat_rect.h = b.height;
    SDL_Rect* p_boat_rect = &boat_rect;
    SDL_Point center = {32,16};
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_RenderCopyEx(rend, boat_texture, NULL, p_boat_rect, b.angle, &center, flip);
  }
}


void GUI::initWindow() {

      // retutns zero on success else non-zero
      if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
          printf("error initializing SDL: %s\n", SDL_GetError());
      }
      SDL_Window* win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

      Uint32 render_flags = SDL_RENDERER_ACCELERATED;
      this->rend = SDL_CreateRenderer(win, -1, render_flags);

      SDL_Surface* boat_surface = IMG_Load("./img/boats.png");
      boat_texture = SDL_CreateTextureFromSurface(rend, boat_surface);

      SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
      // annimation loop
      while (WAVE_CONT->running) {
          SDL_Event event;
          // Events mangement
          while (SDL_PollEvent(&event)) {
              switch (event.type) {
              case SDL_QUIT:
                  // handling of close button
                  WAVE_CONT->running = false;
                  break;
              }
          }

          // Events mangement
          while (SDL_PollEvent(&event)) {
              switch (event.type) {
              case SDL_QUIT:
                  // handling of close button
                  WAVE_CONT->running = false;
                  break;
              }
          }

          // clears the screen
          SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
          SDL_RenderClear(rend);
          drawWaves();
          drawBoats();

          // triggers the double buffers
          // for multiple rendering
          SDL_RenderPresent(rend);
          // calculates to 60 fps
          //SDL_Delay(1000 / 60);
          SDL_Delay(1000 / 60);
      }

      //SDL_DestroyTexture(tex);
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);

}
