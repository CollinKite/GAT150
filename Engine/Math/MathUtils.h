#pragma once

namespace math
{
    constexpr float Pi = 3.14159265359f;
    constexpr float DoublePi = 6.28318530718f;
    constexpr float HalfPi = 1.57079632679f;

    constexpr float DegToRad(float degrees)
    {
        return degrees * (Pi/180);
    }

    constexpr float RadToDeg(float radians)
    {
        return radians * (180 / Pi);
    }

    int sqr(int v);
}