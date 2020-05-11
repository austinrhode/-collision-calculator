#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string.h>

#define HEIGHT 320
#define WIDTH 480

SDL_Renderer* rend;

typedef struct _block {
	enum btype { AIR, WATER, GROUND };
	int type=AIR;
	float mass=0;
	float new_mass=0;

	constexpr static float maxMass = 30;
	constexpr static float maxCompress = 0.02;
	constexpr static float minMass = 0.1;
} block;

typedef struct _world {
	static constexpr int width = 100;
	static constexpr int height = 100;
	block *blocks = (block *) malloc((width+2) * (height+2) * sizeof(block));
	_world() {
		for(int col = 0; col < width+2; col++) {
			*(blocks + col) = { .type=block::GROUND };
			*(blocks + width*(height-1) + col) = { .type=block::GROUND };
		}
		for(int row = 0; row < height+2; row++) {
			*(blocks + row*width) = { .type=block::GROUND };
			*(blocks + (width-1) + row*width) = { .type=block::GROUND };
		}
	}
} world;


void autoStep(world& w) {
	for(int row = 1; row < w.height-1; row++)  {
		for(int col = 1; col < w.width-1; col++) {
			block* b  = &w.blocks[row*w.width + col];
			block* bN = &w.blocks[(row+1)*w.width + col];
			block* bS = &w.blocks[(row-1)*w.width + col];
			block* bW = &w.blocks[(row)*w.width + (col-1)];
			block* bE = &w.blocks[(row)*w.width + (col+1)];

			if(b->mass <= 0 || b->type == block::GROUND) continue;

			//DOWN
			if(b->mass > bS->mass && bS->mass < bS->maxMass && bS->type != block::GROUND) {
				float missingAmount = (bS->maxMass-bS->mass);
				bS->type = block::WATER;
				if(b->mass >= missingAmount) {
					bS->mass += missingAmount;
					b->mass -= missingAmount;
				} else {
					bS->mass += b->mass;
					b->mass = 0;
				}
			}

			//RIGHT
			if(bE->mass < b->mass && bE->type != block::GROUND) {
				float avg = (bE->mass+b->mass)/2;
				b->mass = avg;
				bE->mass = avg;
			}

			//LEFT
			if(bW->mass < b->mass && bW->type != block::GROUND) {
				float avg = (bW->mass+b->mass)/2;
				b->mass = avg;
				bW->mass = avg;
			}

		}
	}

	//set correct ground type
	for(int row = 1; row < w.height-1; row++)  {
		for(int col = 1; col < w.width-1; col++) {
			if(w.blocks[row*w.width + col].type == block::GROUND) continue;
			if(w.blocks[row*w.width + col].mass > block::minMass) w.blocks[row*w.width + col].type = block::WATER;
			else w.blocks[row*w.width + col].type = block::AIR;
		}
	}

	//remove any water that has left the map
	for(int col = 0; col < w.width+2; col++) {
		w.blocks[0 + col].type=block::GROUND;
		w.blocks[0 + col].mass=0;
		w.blocks[(w.height-1)*w.width + col].type=block::GROUND;
		w.blocks[(w.height-1)*w.width + col].mass=0;
	}
	for(int row = 0; row < w.height+2; row++) {
		w.blocks[row*w.width].type=block::GROUND;
		w.blocks[row*w.width].mass=0;
		w.blocks[row*w.width + w.width].type=block::GROUND;
		w.blocks[row*w.width + w.width].mass=0;
	}
}

void drawRect(float x, float y, float width, float height, uint32_t color, uint8_t alpha) {
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

void drawWorld(world& w, int scale) {
	for(int row = 0; row < w.height; row++)  {
		for(int col = 0; col < w.width; col++) {
			uint32_t color;
			float alpha = 255;

			if(w.blocks[row*w.width + col].type == block::WATER) {
				color = 0x0000FF;
				float massInc = (w.blocks[row*w.width + col].mass/block::maxMass);
				float massOffset = 0.2;

				alpha = ((massInc+massOffset)/(massOffset+1))*255;
				//printf("%f ", alpha);
			}
			else if(w.blocks[row*w.width + col].type == block::AIR) {
				color = 0xFFFFFF;
				alpha = 0;
			}
			else color = 0x00FF00;

			drawRect((col)*scale,(w.height-row-1)*scale,scale,scale,color,alpha);
		}
	}
	//printf("\n");
}

/*void buildMap() {
	int W=-1;
	int H=-1;
	char c;
	FILE *fptr;
	if((fptr = fopen("tileMap.txt", "r")) == NULL) {
		printf("Error: FNFE\n");
		return;
	} else {
		while((c = fgetc(fptr)) != EOF) {
			if(W == -1) {
				char line[16];
				fscanf(fptr, "%[^\n]", line);
				W=atoi(strtok(line, "x"));
				H=atoi(strtok(NULL, "x"));
			}
			//else
				//printf("%c",c);
		}
		fclose(fptr);
	}
}*/

int main() {

	int scale = 3;
	world w;

	// retutns zero on success else non-zero
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        	printf("error initializing SDL: %s\n", SDL_GetError());
	}
      SDL_Window* win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

      Uint32 render_flags = SDL_RENDERER_ACCELERATED;
      rend = SDL_CreateRenderer(win, -1, render_flags);

			bool running = true;
			bool mousedown = false;
     	SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
      	// annimation loop
      	while (running) {
        	SDL_Event event;
          // Events mangement

          int dir = 0;

          while (SDL_PollEvent(&event)) {
              switch (event.type) {
              case SDL_QUIT:
                  running = false;
                  break;
							case SDL_MOUSEBUTTONDOWN:
								switch(event.button.button) {
									case SDL_BUTTON_LEFT:
										mousedown = true;
										break;
									default:
										break;
									}
									break;
							case SDL_MOUSEBUTTONUP:
								switch(event.button.button) {
									case SDL_BUTTON_LEFT:
										mousedown = false;
										break;
									default:
										break;
								}
								break;
              case SDL_KEYDOWN:
		  					// keyboard API for key pressed
                switch (event.key.keysym.scancode) {
                  case SDL_SCANCODE_A:
                  case SDL_SCANCODE_LEFT:
                    dir = -1;
                    break;
                  case SDL_SCANCODE_D:
                  case SDL_SCANCODE_RIGHT:
                    dir = 1;
                    break;
						  default:
						    break;
				    	}
					  default:
							break;
				  	}
					}

					int my = w.height-((event.motion.y)/scale);
					int mx = event.motion.x/scale;
					if(mousedown) w.blocks[my*w.width + mx] = { .type=block::WATER, .mass=9 };

          // clears the screen
          SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
          SDL_RenderClear(rend);
          //SDL_RenderCopy(rend, bg_texture, NULL, 0);

					autoStep(w);
					drawWorld(w,scale);

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
