#include "GameObject.h"
#include "Consts.h"

GameObject::GameObject(){
	this->init = false;
	this->pixel_x = 0;
	this->pixel_y = 0;
}

void GameObject::initGameObject(SDL_Renderer *renderer, SDL_Surface* picture){
	this->renderer = renderer;
	this->picture = picture;
	this->pictureTexture = SDL_CreateTextureFromSurface(renderer, picture);

	this->init = true;
}

void GameObject::renderPicture(){
	if(init){
		SDL_Rect WrectRect;
		WrectRect.x = this->pixel_x * PIXEL_SIZE;
		WrectRect.y = this->pixel_y * PIXEL_SIZE;
		WrectRect.w = picture->w * PIXEL_SIZE;
		WrectRect.h = picture->h * PIXEL_SIZE;
		SDL_RenderCopy(this->renderer, this->pictureTexture, NULL, &WrectRect);
	}
	else{
		std::cout << "ERROR: GameObject not initialized." << std::endl;
	}
}

void GameObject::setPosition(int x, int y){
	this->pixel_x = x;
	this->pixel_y = y;
}

int GameObject::getPositionX(){
	return this->pixel_x;
}

int GameObject::getPositionY(){
	return this->pixel_y;
}

int GameObject::getWidthInPixels() {
    return picture->w;
}

int GameObject::getHeightInPixels() {
    return picture->h;
}
