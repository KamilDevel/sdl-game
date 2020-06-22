/**
 * Created by Kamil Badura on 20/06/2020
 * Copyright (c) 2020 Kamil Badura <kamil.devel@gmail.com>
 * All rights reserved.
 *
 * Vector2D.h
 */

#pragma once

class Vector2D
{
public:
    float _x;
    float _y;

    Vector2D();
    Vector2D(float x, float y);

    Vector2D& add(const Vector2D& v);
    Vector2D& subtract(const Vector2D& v);
    Vector2D& multiply(const Vector2D& v);
    Vector2D& divide(const Vector2D& v);

    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);

    Vector2D& operator+=(const Vector2D& v);
    Vector2D& operator-=(const Vector2D& v);
    Vector2D& operator*=(const Vector2D& v);
    Vector2D& operator/=(const Vector2D& v);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
};
