#pragma once
#include <iostream>
#include <math.h>

class Vector2
{
public:
    float x;
    float y;

    Vector2() : x(0), y(0) {}

    Vector2(float v) : x(v), y(v) {}

    Vector2(float x, float y) : x(x), y(y) {}

    static Vector2 right()
    {
        return Vector2(1, 0);
    }

    static Vector2 left()
    {
        return Vector2(-1, 0);
    }

    static Vector2 up()
    {
        return Vector2(0, 1);
    }

    static Vector2 down()
    {
        return Vector2(0, -1);
    }

    static Vector2 one()
    {
        return Vector2(1, 1);
    }

    static Vector2 positiveInfinity()
    {
        return Vector2(INFINITY, INFINITY);
    }

    static Vector2 negativeInfinity()
    {
        return Vector2(-INFINITY, -INFINITY);
    }

    // Swaps the x and y values of the vector
    void swapAxis()
    {
        float temp = x;
        x = y;
        y = temp;
    }

    Vector2 Int() const
    {
        return Vector2((int)x, (int)y);
    }

    Vector2 operator+(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator-(const Vector2 &other) const
    {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2 operator-() const
    {
        return Vector2(-x, -y);
    }

    Vector2 operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 operator/(float scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }

    Vector2 operator+=(const Vector2 &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2 operator-=(const Vector2 &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2 operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2 operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    bool operator==(const Vector2 &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2 &other) const
    {
        return !(*this == other);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector2 &vec)
    {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Vector2 &vec)
    {
        is >> vec.x >> vec.y;
        return is;
    }

    float distance(const Vector2 &other) const
    {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }

    float magnitude() const
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }

    float sqrMagnitude() const
    {
        return pow(x, 2) + pow(y, 2);
    }

    Vector2 normalize() const
    {
        return *this / magnitude();
    }

    float dot(const Vector2 &other) const
    {
        return x * other.x + y * other.y;
    }

    // Returns the angle in radians between this vector and the other vector
    float signedAngle(const Vector2 &other) const
    {
        return atan2(x * other.y - y * other.x, x * other.x + y * other.y);
    }

    // Returns the angle in degrees between this vector and the other vector
    float signedAngleDeg(const Vector2 &other) const
    {
        return signedAngle(other) * 180 / M_PI;
    }

    // Rotate the vector by the given angle in radians
    Vector2 rotate(float angle) const
    {
        Vector2 rotatedVector;
        float cosAngle = cos(angle);
        float sinAngle = sin(angle);

        rotatedVector.x = x * cosAngle - y * sinAngle;
        rotatedVector.y = x * sinAngle + y * cosAngle;

        if (fabs(rotatedVector.x) < 0.0001)
            rotatedVector.x = 0;
        if (fabs(rotatedVector.y) < 0.0001)
            rotatedVector.y = 0;

        return rotatedVector;
    }

    // Rotate the vector by the given angle in degrees
    Vector2 rotateDeg(float angle) const
    {
        return rotate(angle * M_PI / 180);
    }

    // Rotate around pivot by the given angle in radians
    Vector2 rotateAround(const Vector2 &pivot, float angle) const
    {
        Vector2 rotatedVector = *this - pivot;
        rotatedVector = rotatedVector.rotate(angle);
        rotatedVector += pivot;
        return rotatedVector;
    }

    // Rotate around pivot by the given angle in degrees
    Vector2 rotateAroundDeg(const Vector2 &pivot, float angle) const
    {
        return rotateAround(pivot, angle * M_PI / 180);
    }

    // Linearly interpolates between this vector and the other vector by t
    void Lerp(const Vector2 &to, float t)
    {
        if (distance(to) < 0.0001)
        {
            x = to.x;
            y = to.y;
        }
        else
        {
            x = x + (to.x - x) * t;
            y = y + (to.y - y) * t;
        }
    }
};