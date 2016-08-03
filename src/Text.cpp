#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <stdlib.h>
#include <vector>
#include "Consts.h"
#include "Text.h"

Text::Text(SDL_Renderer *renderer, TTF_Font *font, std::string text){
	this->renderer = renderer;
	this->font = font;
	textColor.r = 255;
	textColor.g = 255;
	textColor.b = 255;
	textColor.a = 255;

	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
	text_w = textSurface->w;
	text_h = textSurface->h;

	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
}

void Text::render_text(int x, int y){
	SDL_Rect WrectRect;
	WrectRect.x = x;
	WrectRect.y = y;
	WrectRect.w = text_w * PIXEL_SIZE;
	WrectRect.h = text_h * PIXEL_SIZE;
	SDL_RenderCopy(renderer, textTexture, NULL, &WrectRect);
}

int Text::get_w(){
	return text_w;
}
int Text::get_h(){
	return text_h;
}