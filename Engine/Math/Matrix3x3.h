#pragma once
#include "Math/Vector2.h"
#include "Math/Vector3.h"

namespace crae
{
	struct Matrix3x3
	{
		Vector3 rows[3]; //[3][2]

		Matrix3x3() = default;
		Matrix3x3(const Vector3& row1, const Vector3& row2, const Vector3& row3);

		Vector3 operator [] (size_t index) const { return rows[index]; }
		Vector3& operator [] (size_t index) { return rows[index]; }

		Vector3 operator * (const Vector3& v); //v2 = mx33 * v2
		Matrix3x3 operator * (const Matrix3x3& mx); //mx33 = mx33 * mx33

		static Matrix3x3 CreateScale(const Vector2& scale);
		static Matrix3x3 CreateScale(float scale);
		static Matrix3x3 CreateRoation(float radians);

		static const Matrix3x3 identity;
		static const Matrix3x3 zero;

	};



	inline Matrix3x3::Matrix3x3(const Vector3& row1, const Vector3& row2, const Vector3& row3)
	{
		rows[0] = row1;
		rows[1] = row2;
		rows[2] = row3;
	}

	inline Vector3 Matrix3x3::operator*(const Vector3& v)
	{
		Vector3 result;

		result.x = v.x * rows[0][0] + v.y * rows[0][1];
		result.y = v.x * rows[1][0] + v.y * rows[1][1];

		return result;
	}

	inline Matrix3x3 Matrix3x3::operator*(const Matrix3x3& mx)
	{
		Matrix3x3 mx2;

		mx2[0][0] = mx2[0][0] * mx[0][0] + mx2[0][1] * mx[1][0];
		mx2[0][1] = mx2[0][0] * mx[0][1] + mx2[0][1] * mx[1][1];
		mx2[1][0] = mx2[1][0] * mx[0][0] + mx2[1][1] * mx[1][0];
		mx2[1][1] = mx2[1][0] * mx[0][1] + mx2[1][1] * mx[1][1];

		return mx2;
	}

	inline Matrix3x3 Matrix3x3::CreateScale(const Vector2& scale)
	{
		Matrix3x3 mx;
		// non-uniform scale
		//sX 0
		//0 sY

		mx[0] = Vector3{ scale.x, 0.0f };
		mx[1] = Vector3{ 0.0f, scale.y };

		return mx;
	}

	inline Matrix3x3 Matrix3x3::CreateScale(float scale)
	{
		Matrix3x3 mx;
		//uniform scale
		//s 0
		//0 s

		mx[0] = Vector3{ scale, 0.0f };
		mx[1] = Vector3{ 0.0f, scale };

		return mx;
	}

	inline Matrix3x3 Matrix3x3::CreateRoation(float radians)
	{
		Matrix3x3 mx;

		float c = std::cos(radians);
		float s = std::sin(radians);

		mx[0] = Vector3{ c, -s };
		mx[1] = Vector3{ s, c };

		return mx;
	}

}