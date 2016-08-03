#include <iostream>
#include <sstream>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "Consts.h"
#include "CommandParser.h"
#include "TileFactory.h"

using namespace std;

TileFactory::TileFactory() {
}

Tile TileFactory::newTile(SDL_Renderer *renderer, string texture_name) {

    this->filePath = "../files/Tiles/" + texture_name + ".txt";
    this->imagePath = "../resources/Tiles/" + texture_name + ".png";
    this->renderer = renderer;

    SDL_Surface *picture;
    picture = IMG_Load(this->imagePath.c_str());
    if (!picture) {
        cout << "ERROR: Can not load image: " << this->imagePath << endl;
    }
    if (picture->w!=PIXELS_PER_TILE && picture->h!=PIXELS_PER_TILE) {
        std::
        cout << "ERROR: Picture wrong size: " << this->imagePath << endl;
    }

    Tile tileOb = parseTileProperties();
    tileOb.initGameObject(renderer, picture);

    return tileOb;
}

Tile TileFactory::parseTileProperties(){
    Tile tileOb;
    CommandParser commandParserOb;
    commandParserOb.initParser(filePath);

    while(commandParserOb.getNextCommand()[0] != ""){

        if(commandParserOb.getCommand()[0]=="solid"){
            if(commandParserOb.getCommand()[1] == "true"){
                tileOb.setSolid(true);
            }
            else if(commandParserOb.getCommand()[1] == "false"){
                tileOb.setSolid(false);
            }
            else{
                tileOb.setSolid(false);
                cout << "ERROR: No such property of variable ";
                cout << commandParserOb.getCommand()[0] << endl;
            }
        }

        else if(commandParserOb.getCommand()[0] == "upper"){
            if(commandParserOb.getCommand()[1] == "true"){
                tileOb.setUpper_layer(true);
            }
            else if(commandParserOb.getCommand()[1] == "false"){
                tileOb.setUpper_layer(false);
            }
            else{
                tileOb.setUpper_layer(false);
                cout << "ERROR: No such property of variable ";
                cout << commandParserOb.getCommand()[0] << endl;
            }
        }

    }

    return tileOb;
}

string TileFactory::stringToLower(string line){
    string result;
    for(int i = 0; i < line.size(); i ++){
        result.push_back((char)tolower(line[i]));
    }

    return result;
}