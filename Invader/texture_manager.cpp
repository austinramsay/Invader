//
//  TextureManager.cpp
//  Invader
//
//  Created by Austin on 5/20/22.
//

#include <stdio.h>
#include "texture_manager.h"

SDL_Texture* TextureManager::load_texture(const char *file_name, SDL_Renderer *renderer) {
    SDL_Surface *temp_surface = IMG_Load(file_name);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
    SDL_FreeSurface(temp_surface);
    
    return texture;
}
