#ifndef TILE_H
#define TILE_H
#include "GameObject.h"

class Tile: public GameObject
{
public:
	Tile();
	void tileInit(SDL_Renderer *renderer, SDL_Surface* picture);
	void setUpper_layer(bool x);
    bool getUpper_layer();
    void setSolid(bool x);
    bool getSolid();

protected:
    bool upper_layer;
    bool solid;
};

#endif