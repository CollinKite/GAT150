#pragma once

#include "Vector2.h"
#include "Matrix2x2.h"

namespace crae
{
	struct Transform
	{
		Vector2 postition; //x y
		float rotation; //angle
		Vector2 scale{1,1};

		operator Matrix2x2 () const
		{
			Matrix2x2 mxScale = Matrix2x2::CreateScale(scale);
			Matrix2x2 mxRotation = Matrix2x2::CreateRoation(math::DegToRad(rotation));

			return { mxScale * mxRotation };
		}
	};
}