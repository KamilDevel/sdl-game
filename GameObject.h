/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * GameObject.h
 */

#pragma once

#include "Game.h"

class GameObject
{
private:
    // X position.
    int _x;

    // Y position.
    int _y;

    // Texture.
    SDL_Texture* _texture;

    // Source and destination rectangles.
    SDL_Rect _srcRect, _dstRect;
public:
    /**
     * Default constructor.
     *
     * @param const char* Texture file.
     * @param int x X position.
     * @param int y Y position.
     */
    GameObject(const char* texturefile, int x, int y);

    /**
     * Default destructor.
     */
    ~GameObject();

    /**
     * Update.
     *
     * @return void
     */
    void update(void);

    /**
     * Render.
     *
     * @return void
     */
    void render(void);
};
