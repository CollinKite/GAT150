#pragma once

namespace math
{
    constexpr float Pi = (float)3.14159265359;
    constexpr float DoublePi = (float)6.28318530718;
    constexpr float HalfPi = (float)1.57079632679;

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