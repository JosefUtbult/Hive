#include <iostream>
#include <sstream>
#include <fstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <vector>

#include "GameObject.h"
#include "Consts.h"
#include "RunGame.h"
#include "Map.h"
#include "Tile.h"
#include "TileFactory.h"

using namespace std;

Map::Map(SDL_Renderer* renderer, std::string nr_of_screen){


	this->renderer = renderer;
	this->path = "../files/Map/" + nr_of_screen + ".txt";

	createTiles();

}

void Map::createTiles(){

	TileFactory tileFactoryOb;

	ifstream file(this->path.c_str());

	while(true){
		if(!getline(file, this->line)){
			break;
		}
		else{
			for(int i = 0; i < this->line.size(); i ++){
				if(this->line[i] != ' '){
					temp_val += this->line[i];
				}
				else{
					tile.push_back(tileFactoryOb.newTile(renderer, temp_val));
					temp_val = "";
				}
			}
		}
	}

	cout << "Tiles: " << tile.size() << endl;
}

void Map::renderMap(){
	int x = 0;
	int y = 0;
	for(int i = 0; i < tile.size(); i ++){
			if(x >= TILES_X){
				x = 0;
				y ++;
			}
            tile[i].setPosition((x * PIXELS_PER_TILE), (y * PIXELS_PER_TILE));
			tile[i].renderPicture();
			x ++;
	}
}