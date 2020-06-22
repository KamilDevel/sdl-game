/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * GameObject.cpp
 */

#include "GameObject.h"
#include "TextureManager.h"

/**
 * Default constructor.
 *
 * @param const char* Texture file.
 * @param int x X position.
 * @param int y Y position.
 */
GameObject::GameObject(const char* texturefile, int x, int y)
{
    _texture = TextureManager::LoadTexture(texturefile);
    _x = x;
    _y = y;
}

/**
 * Default destructor.
 */
GameObject::~GameObject()
{

}

/**
 * Update.
 *
 * @return void
 */
void GameObject::update(void)
{
    _srcRect.h = 32;
    _srcRect.w = 32;
    _srcRect.x = 0;
    _srcRect.y = 0;

    _dstRect.h = _srcRect.h * 2;
    _dstRect.w = _srcRect.w * 2;
    _dstRect.x = _x;
    _dstRect.y = _y;
}

/**
 * Render.
 *
 * @return void
 */
void GameObject::render(void)
{
    SDL_RenderCopy(Game::_renderer, _texture, &_srcRect, &_dstRect);
}
