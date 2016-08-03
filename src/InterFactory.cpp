#include "InterFactory.h"

InterFactory::InterFactory() {

}

Interactable InterFactory::newInter(SDL_Renderer *renderer, string texture_name) {
    this->renderer = renderer;
    this->filePath = "../files/Interactable/" + texture_name + ".txt";
    this->imagePath = "../resources/Interactable/" + texture_name + ".png";

    SDL_Surface *picture;
    picture = IMG_Load(this->imagePath.c_str());
    if (!picture) {
        cout << "ERROR: Can not load image: " << this->imagePath << endl;
    }

    Interactable interOb = parseInterProperties();
    interOb.initGameObject(renderer, picture);

    return interOb;
}


Interactable InterFactory::parseInterProperties(){
    Interactable objectOb;

    CommandParser commandParserOb;
    commandParserOb.initParser(this->filePath);

    while(commandParserOb.getNextCommand()[0] != ""){

        if(commandParserOb.getCommand()[0]=="solid"){
            if(commandParserOb.getCommand()[1] == "true"){
                objectOb.setSolid(true);
            }
            else if(commandParserOb.getCommand()[1] == "false"){
                objectOb.setSolid(false);
            }
            else{
                objectOb.setSolid(false);
                cout << "ERROR: No such property of variable ";
                cout << commandParserOb.getCommand()[0] << endl;
            }
        }

        else if(commandParserOb.getCommand()[0] == "upper"){
            if(commandParserOb.getCommand()[1] == "true"){
                objectOb.setUpper_layer(true);
            }
            else if(commandParserOb.getCommand()[1] == "false"){
                objectOb.setUpper_layer(false);
            }
            else{
                objectOb.setUpper_layer(false);
                cout << "ERROR: No such property of variable ";
                cout << commandParserOb.getCommand()[0] << endl;
            }
        }

    }

    return objectOb;
}

