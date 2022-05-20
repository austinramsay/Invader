//
//  game_object.cpp
//  Invader
//
//  Created by Austin on 5/20/22.
//

#include "game_object.h"

GameObject::GameObject(const char *texture_sheet, SDL_Renderer *provided_ren, int x, int y) {
    renderer = provided_ren;
    obj_texture = TextureManager::load_texture(texture_sheet, renderer);
    
    x_pos = 0;
    y_pos = 0;
}

void GameObject::update() {
    x_pos++;
    y_pos++;
    
    src_rect.h = 32;
    src_rect.w = 32;
    src_rect.x = 0;
    src_rect.y = 0;
    
    dst_rect.w = src_rect.w * 2;
    dst_rect.h = src_rect.h * 2;
    dst_rect.x = x_pos;
    dst_rect.y = y_pos;
}

void GameObject::render() {
    SDL_RenderCopy(renderer, obj_texture, &src_rect, &dst_rect);
}
