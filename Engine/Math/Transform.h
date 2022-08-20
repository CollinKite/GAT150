#pragma once

#include "Vector2.h"
#include "Matrix3x3.h"
#include "Math/MathUtils.h"
#include "Serialization/Serializable.h"

namespace crae
{
	struct Transform : public ISerializable
	{
		Vector2 position; //x y
		float rotation{0}; //angle
		Vector2 scale{1,1};

		Matrix3x3 matrix;
		Transform() = default;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Update()
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRoation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale }; //ORDER MATTERS (Right to Left is order)

		}

		void Update(const Matrix3x3& parent)
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRoation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale }; //ORDER MATTERS (Right to Left is order)
			matrix = parent * matrix;

		}

		operator Matrix3x3 () const
		{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRoation(math::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			return { mxTranslation * mxRotation * mxScale };
		}


		// Inherited via ISerializable



	};
}