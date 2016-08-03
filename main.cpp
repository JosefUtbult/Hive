#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "Consts.h"
#include "Text.h"
#include "RunGame.h"
#include "Map.h"
#include "Player.h"
#include "Interactable.h"
#include "InterFactory.h"

using namespace std;

int main(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "ERROR: Can not open window" << endl;
		return -1;
	}
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags)){
		cout << "ERROR: Can not start SDL_image." << endl;
		return -5;
	}
	if(TTF_Init() < 0) {
		cout << "ERROR: Can not start TTF" << endl;
		return -2;
	}

	TTF_Font *font1 = TTF_OpenFont("../resources/Candarai.ttf", 30);
	TTF_Font *font2 = TTF_OpenFont("../resources/malgunbd.ttf", 100);

	if(font1 == 0 || font2 == 0){
		cout << "ERROR: Can not open fonts" << endl;
		return -3;
	}

	SDL_Window *window = NULL;
	window = SDL_CreateWindow("Hive", 100, 100, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if(window == NULL){
		cout << "ERROR: Unable to open window" << endl;
		return -4;
	}

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_RenderClear(renderer);

	Text title(renderer, font1, "Hive");
	RunGame runGameOb;
	Map mapOb(renderer, "waterWorld");
    Player playerOb;
    playerOb.initPlayer(renderer);

    Uint32 last_time = SDL_GetTicks();
    Uint32 current_time;
    Uint32 delta;

	bool quit = false;
	while(!quit){
		SDL_Event e;
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT) {
				quit = true;
			}
		}

        current_time = SDL_GetTicks();
        delta = current_time - last_time;
        last_time = current_time;

        playerOb.updatePlayerPosition();

		mapOb.renderMap();
        playerOb.renderPlayer();
		title.render_text((WINDOW_WIDTH / 2) - (title.get_w() * PIXEL_SIZE / 2), 100);
		SDL_RenderPresent(renderer);

	}

}