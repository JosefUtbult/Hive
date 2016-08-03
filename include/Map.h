#ifndef MAP_H
#define MAP_H
#include "Tile.h"
#include <string>

class Map
{
public:
	Map(SDL_Renderer* renderer, std::string nr_of_screen);
	void renderMap();
protected:
	void createTiles();

	SDL_Renderer* renderer;
	std::string path;
	
	std::string line;
	std::string temp_val;
	std::vector<Tile> tile;

};

#endif