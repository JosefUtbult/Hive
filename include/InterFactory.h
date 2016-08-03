#ifndef HIVE_OBJECTFACTORY_H
#define HIVE_OBJECTFACTORY_H

#include <string.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include "CommandParser.h"
#include "Interactable.h"

using namespace std;

class InterFactory {
public:
    InterFactory();
    Interactable newInter(SDL_Renderer *renderer, string texture_name);
protected:
    Interactable parseInterProperties();

    SDL_Renderer *renderer;
    string texture_name;
    string filePath;
    string imagePath;
};


#endif //HIVE_OBJECTFACTORY_H
