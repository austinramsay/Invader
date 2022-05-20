//
//  TextureManager.h
//  Invader
//
//  Created by Austin on 5/20/22.
//

#ifndef texture_manager_h
#define texture_manager_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class TextureManager {
    
public:
    static SDL_Texture* load_texture(const char*, SDL_Renderer*);
};

#endif
