#include "GUI.hpp"
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
          //SDL_RenderCopy(rend, tex, NULL, 0);

          drawWaves();

          // triggers the double buffers
          // for multiple rendering
          SDL_RenderPresent(rend);

          // calculates to 60 fps
          //SDL_Delay(1000 / 60);
          SDL_Delay(1000 / 10);
      }

      std::cout << this->closed << std::endl;

      //SDL_DestroyTexture(tex);
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
}
