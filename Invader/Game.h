//
//  Game.h
//  Invader
//
//  Created by Austin on 5/16/22.
//

#ifndef base_h
#define base_h

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "constants.h"

class Game {
    
private:
    bool isRunning = false;
    int count = 0;
    
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Texture *player_tex = nullptr;
    SDL_Rect src_r, dst_r;
    
public:
    static const int frame_delay = 1000 / FRAME_LIMIT;
    
    Game();
    ~Game();
    
    void init(const char*, int, int, int, int, bool);
    void handleEvents();
    void update();
    void render();
    void clean();
    
    bool running() { return isRunning; }
};

#endif
