#ifndef HIVE_PLAYER_H
#define HIVE_PLAYER_H

#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include "Consts.h"
#include "Text.h"
#include "RunGame.h"
#include "Map.h"
#include "Interactable.h"
#include "InterFactory.h"


class Player {
public:
    Player();
    void initPlayer(SDL_Renderer* renderer);
    void updatePlayerPosition();
    void renderPlayer();
protected:
    Interactable interactableOb;
    SDL_Renderer* renderer;

    float x;
    float y;
    float speed;
    int w;
    int h;
    int z;
};


#endif //HIVE_PLAYER_H
