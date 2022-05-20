//
//  game_object.hpp
//  Invader
//
//  Created by Austin on 5/20/22.
//

#ifndef game_object_h
#define game_object_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include "texture_manager.h"

class GameObject {
    
public:
    GameObject(const char*, SDL_Renderer*, int, int);
    ~GameObject();
    
    void update();
    void render();
    
private:
    int x_pos;
    int y_pos;
    
    SDL_Texture *obj_texture;
    SDL_Rect src_rect, dst_rect;
    SDL_Renderer *renderer;
};

#endif
