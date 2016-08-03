#ifndef TILEFACTORY_H
#define TILEFACTORY_H

#include <string.h>
#include <vector>
#include "Tile.h"

class TileFactory{
public:
    TileFactory();
    Tile newTile(SDL_Renderer *renderer, std::string texture_name);
protected:
    std::vector <std::string> readCommand(std::string line);
    std::string stringToLower(std::string line);

    SDL_Renderer *renderer;
    std::string texture_name;
    std::string filePath;
    std::string imagePath;
    Tile parseTileProperties();
    std::vector <Tile> *tiles;

};

#endif
