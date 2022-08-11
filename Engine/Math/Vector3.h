#pragma once

namespace crae
{
	struct Vector3 //default public
	{
		float x, y, z;

		Vector3() : x{ 0 }, y{ 0 }, z{ 0 }{}
		Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z }{}
		Vector3(float v) : x{ v }, y{ v }, z{ v }{}
		Vector3(int x, int y, int z) : x{ (float)x }, y{ (float)y }, z{ (float)z }{}

		void Set(float x, float y, float z) { this->x = x; this->y = y, this->z = z; }

		float operator [] (size_t index) const { return (&x)[index]; }
		float& operator [] (size_t index) { return (&x)[index]; }


		//Vec2 = Vec2 + Vec2
		Vector3 operator + (const Vector3& v) const { return Vector3{ this->x + v.x, this->y + v.y, this->z + v.z }; } //add 2 vectors together and return a new vector
		Vector3 operator - (const Vector3& v) const { return Vector3{ this->x - v.x, this->y - v.y, this->z - v.z }; }
		Vector3 operator * (const Vector3& v) const { return Vector3{ this->x * v.x, this->y * v.y, this->z * v.z }; }
		Vector3 operator / (const Vector3& v) const { return Vector3{ this->x / v.x, this->y / v.y, this->z / v.z }; }

		//Vector 2 = Vec2 + float
		Vector3 operator + (float s) const { return Vector3{ this->x + s, this->y + s, this->z + s }; }
		Vector3 operator - (float s) const { return Vector3{ this->x - s, this->y - s, this->z - s }; }
		Vector3 operator * (float s) const { return Vector3{ this->x * s, this->y * s, this->z * s }; }
		Vector3 operator / (float s) const { return Vector3{ this->x / s, this->y / s, this->z / s }; }

		//Assignment Operators
		Vector3 operator += (const Vector3& v) { this->x += v.x; this->y += v.y; this->z += v.z; return *this; }
		Vector3 operator -= (const Vector3& v) { this->x -= v.x; this->y -= v.y; this->z -= v.z; return *this; }
		Vector3 operator *= (const Vector3& v) { this->x *= v.x; this->y *= v.y; this->z *= v.z; return *this; }
		Vector3 operator /= (const Vector3& v) { this->x /= v.x; this->y /= v.y; this->z /= v.z; return *this; }

		//Assignment Operators w/ float
		Vector3 operator += (float s) { this->x += s; this->y += s; this->z += s; return *this; }
		Vector3 operator -= (float s) { this->x -= s; this->y -= s; this->z -= s; return *this; }
		Vector3 operator *= (float s) { this->x *= s; this->y *= s; this->z *= s; return *this; }
		Vector3 operator /= (float s) { this->x /= s; this->y /= s; this->z /= s; return *this; }

		//unary
		//Vector3 = -Vector3
		Vector3 operator - () const { return Vector3{ -x, -y, -z }; }

		//Comparison
		//Vector3 == Vector3
		bool operator == (const Vector3& v) const { return (this->x == v.x && this->y == v.y && this->z == v.z); }
		bool operator != (const Vector3& v) const { return this->x != v.x || this->y != v.y || this->z != v.z; }

		//Functions
		float LengthSqr();
		float Length();


		float DistanceSqr(const Vector3& v);
		float Distance(const Vector3& v);

		Vector3 Normalized();
		void Normalize();
	};

	inline float Vector3::LengthSqr()
	{
		return x * x + y * y + z * z;
	}
	inline float Vector3::Length()
	{
		return 0.0f;
	}
	inline float Vector3::DistanceSqr(const Vector3& v)
	{
		return 0.0f;
	}
	inline float Vector3::Distance(const Vector3& v)
	{
		return 0.0f;
	}
	inline Vector3 Vector3::Normalized()
	{
		return Vector3();
	}
	inline void Vector3::Normalize()
	{
	}
}