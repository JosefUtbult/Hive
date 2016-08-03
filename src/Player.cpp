#include "Player.h"

Player::Player(){
    x = 100;
    y = 100;
    w = 100;
    h = 100;
    speed = 0.05;
    z = 0;
}

void Player::initPlayer(SDL_Renderer* renderer) {
    this->renderer = renderer;

    InterFactory interFactoryOb;
    this->interactableOb = interFactoryOb.newInter(renderer, "Enemy1");

    w = interactableOb.getWidthInPixels();
    h = interactableOb.getHeightInPixels();

    cout << w << "  " << h << endl;

}

void Player::updatePlayerPosition(){
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_RIGHT]){
        x += speed;
    }
    if(state[SDL_SCANCODE_LEFT]){
        x -= speed;
    }
    if(state[SDL_SCANCODE_UP]){
        y -= speed;
    }
    if(state[SDL_SCANCODE_DOWN]){
        y += speed;
    }

    if(x < 0){
        x = 0;
    }
    else if(x > ((WINDOW_WIDTH / PIXEL_SIZE) - w)){
        x = (WINDOW_WIDTH / PIXEL_SIZE) - w;
    }
    if(y < 0){
        y = 0;
    }
    else if(y > ((WINDOW_HEIGHT / PIXEL_SIZE) - h)){
        y = (WINDOW_HEIGHT / PIXEL_SIZE) - h;
    }
    if(z >= 100){
        cout << "x: " << (int) x << "   y: " << (int) y << endl;
        z = 0;
    }
    else{
        z ++;
    }
    interactableOb.setPosition((int) x, (int) y);
}

void Player::renderPlayer() {
    interactableOb.renderPicture();
}

