//
//  Game.cpp
//  Invader
//
//  Created by Austin on 5/16/22.
//

#include <stdio.h>
#include "Game.h"

Game::Game() {
    // Constructor
}

Game::~Game() {
    // Deconstructor
}

void Game::init(const char *title, int pos_x, int pos_y, int width, int height, bool fullscreen) {
    int flags = 0;
    
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        
        isRunning = true;
    } else {
        std::cout << "Initialization failed." << std::endl;
        isRunning = false;
    }
    
    SDL_Surface *tmp_surface = IMG_Load("assets/player.png");
    player_tex = SDL_CreateTextureFromSurface(renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
}

void Game::handleEvents() {
    SDL_Event e;
    
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            
            // Check for window events such as 'X' button to close window
            case SDL_WINDOWEVENT:
                switch (e.window.event) {
                    case SDL_WINDOWEVENT_CLOSE:
                        isRunning = false;
                        break;
                        
                    default:
                        break;
                }
                break;
                
            // Default event type case
            default:
                break;
        }
    }
}

void Game::update() {
    count++;
    dst_r.h = 16;
    dst_r.w = 16;
    dst_r.x = count;
    
    std::cout << count << std::endl;
}

void Game::render() {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, player_tex, NULL, &dst_r);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
