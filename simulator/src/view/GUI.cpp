#include "GUI.hpp"
#include <model/wave.hpp>
#include <model/wave.cpp>
#include <chrono>
#include <iostream>
#include <cmath>

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

  int dx = RESOLUTION;
  for(int i = 0; i < WIDTH/dx; i++) {
    float height = 0;
    for(wave w : waveList) {
      float dist = (w.headPosition-i);
      float decay = dist > 0 ? -pow(w.decayBase, -dist/w.decayRate) : -pow(w.decayBase, dist/w.decayRate);
      height += decay*w.amplitude*sin((i/w.omega*dx)+w.headPosition);
    };
    drawRect(float(i*dx),HEIGHT-height-phi,dx,HEIGHT-height, color, alpha);
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
      SDL_Texture* boat_texture = SDL_CreateTextureFromSurface(rend, boat_surface);
      //SDL_Surface* surface = IMG_Load("./img/bg.png");
      //SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

      SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);

      auto deltaTime = std::chrono::high_resolution_clock::now();

      // annimation loop
      while (!closed) {

          SDL_Event event;

          // Events mangement
          while (SDL_PollEvent(&event)) {
              switch (event.type) {

              case SDL_QUIT:
                  // handling of close button
                  closed = true;
                  break;
              }

          }

          // Events mangement
          while (SDL_PollEvent(&event)) {
              switch (event.type) {

              case SDL_QUIT:
                  // handling of close button
                  closed = true;
                  break;
              }

          }

          // clears the screen
          SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
          SDL_RenderClear(rend);

          SDL_Rect boat_rect;

          float height = 0;
          float height_front = 0;
          float height_back = 0;
          for (int i = 0; i < waveList.size(); i++){
            height += waveList[i].calculate_height(320 / 3);
            height_front += waveList[i].calculate_height((320 + 16) / 3);
            height_back += waveList[i].calculate_height((320 - 16) / 3);
          }

          boat_rect.x = 320;
          boat_rect.y = height + 250;

          boat_rect.w = 32;
          boat_rect.h = 32;

          const SDL_Rect* p_boat_rect = &boat_rect;
          const SDL_Point center = {32,16};
          const SDL_RendererFlip flip = SDL_FLIP_NONE;
          double angle = asin((height_front - height_back) / boat_rect.w) * (180 / acos(-1));

          SDL_RenderCopyEx(rend, boat_texture, NULL, p_boat_rect, angle, &center, flip);

          drawWaves();

          // triggers the double buffers
          // for multiple rendering
          SDL_RenderPresent(rend);

          // calculates to 60 fps
          //SDL_Delay(1000 / 60);
          SDL_Delay(1000 / 60);
      }

      std::cout << this->closed << std::endl;

      //SDL_DestroyTexture(tex);
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
}
