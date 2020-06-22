/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * SpriteComponent.h
 */

#pragma once

#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:
    Vector2D _position;
    Vector2D _velocity;

    int _speed = 2;

    TransformComponent()
    {
        _position._x = 0.0f;
        _position._y = 0.0f;
    }

    TransformComponent(float x, float y)
    {
        _position._x = x;
        _position._y = y;
    }

    void init() override
    {
        _velocity._x = 0.0f;
        _velocity._y = 0.0f;
    }

    void update() override
    {
        _position._x += _velocity._x * _speed;
        _position._y += _velocity._y * _speed;
    }
};
