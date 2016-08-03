#ifndef RUNGAME_H
#define RUNGAME_H
#include <vector>
#include <fstream>

class RunGame
{
public:
	RunGame();
	void update();
private:
	std::vector<int> screen;
	
};

#endif