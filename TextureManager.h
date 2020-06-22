/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * TextureManager.h
 */

#pragma once

#include "Game.h"

class TextureManager
{
public:
    /**
     * Load a texture from file.
     *
     * @param const char* Texture file.
     * @return SDL_Texture*
     * @static
     */
    static SDL_Texture* LoadTexture(const char* file);

    /**
     * Draw a texture.
     *
     * @param SDL_Texture* Texture.
     * @param SDL_Rect srcRect Source rectangle.
     * @param SDL_Rect dstRect Destination rectangle.
     * @return void
     * @static
     */
     static void DrawTexture(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect);
};
