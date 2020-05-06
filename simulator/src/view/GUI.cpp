#include "GUI.hpp"
#include <chrono>
#include <iostream>

void GUI::drawPixel(SDL_Renderer* m_window_renderer, int x, int y, int size, uint32_t color) {
  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = size;

  int r = ((color & 0xFF0000) >> 16);
  int g = ((color & 0x00FF00) >>  8);
  int b = ((color & 0x0000FF) >>  0);

  SDL_SetRenderDrawColor(m_window_renderer, r, g, b, 255);
  SDL_RenderFillRect(m_window_renderer, &rect);
  SDL_RenderDrawRect(m_window_renderer, &rect);
}

void GUI::initWindow(const int WIDTH, const int HEIGHT) {

      // retutns zero on success else non-zero
      if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
          printf("error initializing SDL: %s\n", SDL_GetError());
      }
      SDL_Window* win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

      Uint32 render_flags = SDL_RENDERER_ACCELERATED;
      SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);
      SDL_Surface* surface = IMG_Load("./img/bg.png");
      SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);

      // controls annimation loop
      bool close = false;

      auto deltaTime = std::chrono::high_resolution_clock::now();

      // annimation loop
      while (!close) {

          auto newDelta = std::chrono::high_resolution_clock::now();
          auto difference = std::chrono::duration_cast<std::chrono::microseconds>(newDelta - deltaTime);
          deltaTime = newDelta;
          liveTime += difference.count()/float(1000000);

          SDL_Event event;

          // Events mangement
          while (SDL_PollEvent(&event)) {
              switch (event.type) {

              case SDL_QUIT:
                  // handling of close button
                  close = true;
                  break;
              }

          }

          // clears the screen
          SDL_RenderClear(rend);
          SDL_RenderCopy(rend, tex, NULL, 0);

          int particleSize = 10;
          /*for(int i = 0; i < (WIDTH*HEIGHT*(liveTime/25))/particleSize; i++) {
            drawPixel(rend,(i/HEIGHT)*particleSize,(i%WIDTH)*particleSize,particleSize,0x223355);
          };*/
          drawPixel(rend,int(liveTime)%WIDTH,200,particleSize,0x223355);

          // triggers the double buffers
          // for multiple rendering
          SDL_RenderPresent(rend);

          // calculates to 60 fps
          //SDL_Delay(1000 / 60);
          SDL_Delay(1000 / 10);
      }

      SDL_DestroyTexture(tex);
      SDL_DestroyRenderer(rend);
      SDL_DestroyWindow(win);
}
