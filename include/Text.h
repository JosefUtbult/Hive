#ifndef TEXT_H
#define TEXT_H
#include <sstream>
#include <string>
#include <stdlib.h>

class Text
{
public:
	Text(SDL_Renderer *renderer, TTF_Font *font, std::string text);
	void render_text(int x, int y);
	int get_w();
	int get_h();
protected:
	SDL_Renderer *renderer;
	TTF_Font *font;
	SDL_Texture *textTexture;
	int text_w;
	int text_h;
	SDL_Color textColor;

};

#endif