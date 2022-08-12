#pragma once

#include "Vector2.h"
#include "Matrix3x3.h"
#include "Math/MathUtils.h"

namespace crae
{
	struct Transform
	{
		Vector2 postition; //x y
		float rotation{0}; //angle
		Vector2 scale{1,1};

		Matrix3x3 matrix;

		void Update()
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRoation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(postition);

			matrix = { mxTranslation * mxRotation * mxScale }; //ORDER MATTERS (Right to Left is order)

		}

		void Update(const Matrix3x3& parent)
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRoation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(postition);

			matrix = { mxTranslation * mxRotation * mxScale }; //ORDER MATTERS (Right to Left is order)
			matrix = parent * matrix;

		}

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRoation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(postition);

			return { mxTranslation * mxRotation * mxScale };
		}

	};
}