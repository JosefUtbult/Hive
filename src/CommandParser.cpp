//
// Created by josef on 2016-07-31.
//

#include "CommandParser.h"
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <fstream>

#include "Consts.h"

using namespace std;

vector <string> readCommand(string line);
string stringToLower(string line);

CommandParser::CommandParser(){
    string filePath;
    vector<string> words;
    this->commandsToReturn = 0;

}

void CommandParser::initParser(string path) {
    this->path = path;

    ifstream file(path.c_str());
    if(!file.is_open()){
        cout << "No file " << path << endl;
        generateFile();
        ifstream file(path.c_str());
    }

    string line;

    while(getline(file, line)) {
        commands.push_back(readCommand(line));
    }

}

vector <string> CommandParser::getNextCommand(){
    if(commandsToReturn < commands.size()){
        vector <string> temp = commands[commandsToReturn];
        commandsToReturn ++;
        return temp;
    }
    else{
        vector <string> vectorNull;
        vectorNull.push_back("");
        return vectorNull;
    }
}

vector <string> CommandParser::getCommand(){
    if(commands.size() > commandsToReturn){
        return commands[commandsToReturn];
    }
    else{
        vector <string> vectorNull;
        vectorNull.push_back("");
        return vectorNull;
    }
}

vector <string> readCommand(string line){
    vector <string> words;
    string temp_line;
    for(int i = 0; i < line.size(); i ++){
        if(!isspace(line[i])) {
            temp_line += line[i];
        }
        else {
            temp_line = stringToLower(temp_line);
            words.push_back(temp_line);
            temp_line = "";
        }
    }

    if(words[0][words[0].size()] == (char) ':'){
        string newWord;
        for(int i = 0; i < (words[0].size()) - 1; i ++){
            newWord += words[0][i];
        }
        words[0] = newWord;
    }

    return words;
}

string stringToLower(string line) {
    string result;
    for(int i = 0; i < line.size(); i ++){
        result.push_back((char)tolower(line[i]));
    }

    return result;
}


void CommandParser::generateFile() {
    string line;
    ifstream readFile("../files/allProperties.txt");
    ofstream openFile(this->path.c_str());

    while(getline(readFile, line)){
        openFile << line << " " << '\n';
    }

    readFile.close();
    openFile.close();
}
