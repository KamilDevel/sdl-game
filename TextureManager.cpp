/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * TextureManager.cpp
 */

#include <SDL2/SDL.h>
#include "TextureManager.h"
#include "Game.h"

/**
 * Load a texture from file.
 *
 * @param const char* Texture file.
 * @return SDL_Texture*
 * @static
 */
SDL_Texture* TextureManager::LoadTexture(const char* file)
{
    SDL_Surface* tmpSurface = IMG_Load(file);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::_renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return texture;
}

/**
 * Draw a texture.
 *
 * @param SDL_Texture* Texture.
 * @param SDL_Rect srcRect Source rectangle.
 * @param SDL_Rect dstRect Destination rectangle.
 * @return void
 * @static
 */
void TextureManager::DrawTexture(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect)
{
    SDL_RenderCopy(Game::_renderer, texture, &srcRect, &dstRect);
}
