/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * SpriteComponent.h
 */

#pragma once

#include <SDL2/SDL.h>
#include "TextureManager.h"
#include "Components.h"

class SpriteComponent : public Component
{
private:
    TransformComponent* _transform;
    SDL_Texture* _texture;
    SDL_Rect _srcRec, _dstRec;
public:
    SpriteComponent() = default;
    SpriteComponent(const char* texture)
    {
        this->texture(texture);
    }
    void texture(const char* texture)
    {
        _texture = TextureManager::LoadTexture(texture);
    }

    void init(void) override
    {
        _transform = &_entity->getComponent<TransformComponent>();

        _srcRec.x = _srcRec.y = 0;
        _srcRec.w = _srcRec.h = 64;
        _dstRec.w = _dstRec.h = 64;
    }
    void update() override
    {
        _dstRec.x = (int)_transform->_position._x;
        _dstRec.y = (int)_transform->_position._y;

    }
    void draw() override
    {
        TextureManager::DrawTexture(_texture, _srcRec, _dstRec);
    }

};
