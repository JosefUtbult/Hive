#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <sstream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <vector>

class GameObject
{
	public:
		GameObject();
		void initGameObject(SDL_Renderer *renderer, SDL_Surface* picture);
		void renderPicture();
        void setPosition(int x, int y);
		int getPositionX();
		int getPositionY();
        int getWidthInPixels();
        int getHeightInPixels();
	protected:
		int pixel_x, pixel_y;
		bool init;
		SDL_Renderer* renderer;
		SDL_Surface* picture;
		SDL_Texture* pictureTexture;

};

#endif