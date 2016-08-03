#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

#include "GameObject.h"
#include "RunGame.h"

RunGame::RunGame(){
	std::ofstream terrain("../files/chunks.txt");
	terrain << "Bluppfisk";
}

void RunGame::update(){

}