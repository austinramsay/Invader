//
//  main.cpp
//  Invader
//
//  Created by Austin on 5/16/22.
//

#include <stdio.h>
#include "Game.h"

int main(int argc, char* args[]) {
    
    // Frame rate stats
    Uint32 frame_start;
    int frame_time;
    
    // Initialize new game and begin main loop
    Game *game = new Game();
    game->init("Invader", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    while (game->running()) {
        frame_start = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();
        
        // Frame complete, if frame time was faster than the specified FPS limit, delay to match FPS limit
        frame_time = SDL_GetTicks() - frame_start;
        if (Game().frame_delay > frame_time) {
            SDL_Delay(Game().frame_delay - frame_time);
        }
    }
    
    game->clean();
    
    return 0;
}
