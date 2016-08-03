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

<<<<<<< HEAD
//test

=======
>>>>>>> 938de802b0b5658964b3b1876bb6f45c4a9fc705
#endif //HIVE_OBJECTS_H
