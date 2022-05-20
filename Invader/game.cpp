//
//  Game.cpp
//  Invader
//
//  Created by Austin on 5/16/22.
//

#include "game.h"

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
        
        player = new GameObject(PLAYER_PATH, renderer, 0, 0);
        
    } else {
        std::cout << "Initialization failed." << std::endl;
        isRunning = false;
    }
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
    player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    
    player->render();
    
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
