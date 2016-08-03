#include "Interactable.h"


Interactable::Interactable() {

}

void Interactable::interInit(SDL_Renderer *renderer, SDL_Surface *picture){
    initGameObject(renderer, picture);
}

void Interactable::setUpper_layer(bool x){
    upper_layer = x;
}

bool Interactable::getUpper_layer(){
    return upper_layer;
}

void Interactable::setSolid(bool x){
    solid = x;
}

bool Interactable::getSolid(){
    return solid;
}