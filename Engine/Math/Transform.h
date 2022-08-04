#pragma once

#include "Vector2.h"

namespace crae
{
	struct Transform
	{
		Vector2 postition; //x y
		float rotation; //angle
		Vector2 scale{1,1};
	};
}