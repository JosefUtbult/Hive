#include <iostream>
#include <SDL.h>

#include "Consts.h"
#include "GameObject.h"
#include "Tile.h"

using namespace std;

Tile::Tile(){
}

void Tile::tileInit(SDL_Renderer *renderer, SDL_Surface* picture){
    if(this->picture->w != PIXELS_PER_TILE && this->picture->h != PIXELS_PER_TILE){
    cout << "ERROR: Picture wrong size: " << picture << endl;
    }
    initGameObject(renderer, picture);
}

void Tile::setUpper_layer(bool x){
    upper_layer = x;
}
bool Tile::getUpper_layer(){
    return upper_layer;
}
void Tile::setSolid(bool x){
    solid = x;
}
bool Tile::getSolid(){
    return solid;
}