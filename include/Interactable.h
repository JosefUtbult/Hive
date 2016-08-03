#ifndef HIVE_OBJECTS_H
#define HIVE_OBJECTS_H

#include "GameObject.h"
#include <iostream>
#include <SDL.h>
#include "Consts.h"

class Interactable: public GameObject {
public:
    Interactable();
    void interInit(SDL_Renderer *renderer, SDL_Surface *picture);

    void setUpper_layer(bool x);
    bool getUpper_layer();
    void setSolid(bool x);
    bool getSolid();

protected:
    bool upper_layer;
    bool solid;
};

#endif //HIVE_OBJECTS_H
