#ifndef HIVE_COMMANDPARSER_H
#define HIVE_COMMANDPARSER_H
#include <vector>
#include <string>

using namespace std;

class CommandParser {
public:
    CommandParser();
    void initParser(string path);
    vector <string> getNextCommand();
    vector <string> getCommand();
protected:
    string stringToLower(string line);
    void generateFile();

    vector <vector <string> > commands;
    string path;
    int commandsToReturn;

};


#endif //HIVE_COMMANDPARSER_H
