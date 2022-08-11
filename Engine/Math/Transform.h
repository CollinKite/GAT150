#pragma once

#include "Vector2.h"
#include "Matrix3x3.h"
#include "Math/MathUtils.h"

namespace crae
{
	struct Transform
	{
		Vector2 postition; //x y
		float rotation; //angle
		Vector2 scale{1,1};

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRoation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(postition);

			return { mxScale * mxRotation * mxTranslation };
		}

	};
}