#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <string>

namespace nae
{
	struct Vector3
	{
		float x, y, z;

		Vector3() : x{ 0 }, y{ 0 }, z{ 0 }{}
		Vector3(float x, float y, float z) : x{ x }, y{ y }, z{ z } {}
		Vector3(float v) : x{ v }, y{ v }, z{ v } {}
		Vector3(int x, int y, int z) : x{ (float)x }, y{ (float)y }, z{ (float)z } {}

		//arithmetic operators

		void Set(float x, float y, float z) { this->x = x, this->y = y, this->z = z; }
		float operator []  (size_t index) const { return (&x)[index]; }
		float& operator [] (size_t index) { return (&x)[index]; }



		Vector3 operator + (const Vector3& v) const { return Vector3{ this->x + v.x, this->y + v.y, this->z + v.z }; }
		Vector3 operator - (const Vector3& v) const { return Vector3{ this->x - v.x, this->y - v.y, this->z - v.z }; }
		Vector3 operator * (const Vector3& v) const { return Vector3{ this->x * v.x, this->y * v.y, this->z * v.z }; }
		Vector3 operator / (const Vector3& v) const { return Vector3{ this->x / v.x, this->y / v.y, this->z / v.z }; }


		Vector3 operator + (float s) const { return Vector3{ this->x + s, this->y + s, this->z + s }; }
		Vector3 operator - (float s) const { return Vector3{ this->x - s, this->y - s, this->z - s }; }
		Vector3 operator * (float s) const { return Vector3{ this->x * s, this->y * s, this->z * s }; }
		Vector3 operator / (float s) const { return Vector3{ this->x / s, this->y / s, this->z / s }; }


		Vector3& operator += (const Vector3& v) { this->x += v.x, this->y += v.y, this->z += v.z; return *this; }
		Vector3& operator -= (const Vector3& v) { this->x -= v.x, this->y -= v.y, this->z -= v.z; return *this; }
		Vector3& operator *= (const Vector3& v) { this->x *= v.x, this->y *= v.y, this->z *= v.z; return *this; }
		Vector3& operator /= (const Vector3& v) { this->x /= v.x, this->y /= v.y, this->z /= v.z ; return *this; }

		Vector3 operator += (float s) { return Vector3{ this->x += s, this->y += s, this->z += s }; }
		Vector3 operator -= (float s) { return Vector3{ this->x -= s, this->y -= s, this->z -= s }; }
		Vector3 operator *= (float s) { return Vector3{ this->x *= s, this->y *= s, this->z *= s }; }
		Vector3 operator /= (float s) { return Vector3{ this->x /= s, this->y /= s, this->z /= s }; }

		// unary
		Vector3 operator - () { return Vector3{ -x, -y, -z }; }

		//comparison
		bool operator == (const Vector3& v) const { return (this->x == v.x && this->y == v.y && this->z == v.z); }
		bool operator != (const Vector3& v) const { return !(*this == v); }//this->x != v.x || this->y != v.y || this->z != v.z ); }

		//functions
		float LengthSqr();
		float Length();

		float DistanceSqr(const Vector3& v);
		float Distance(const Vector3& v);

		Vector3 Normalized();
		void Normalize();

		float GetAngle();

		static Vector3 Rotate(const Vector3& v, float angle);

		static const Vector3 one;
		static const Vector3 zero;
		static const Vector3 up;
		static const Vector3 down;
		static const Vector3 left;
		static const Vector3 right;

	};

	std::istream& operator >> (std::istream& stream, Vector3& v);

	inline float Vector3::LengthSqr()
	{
		return x * x + y * y + z * z;
	}
	inline float Vector3::Length()
	{
		return std::sqrt(x * x + y * y + z * z);
	}
	inline float Vector3::DistanceSqr(const Vector3& v)
	{
		return ((*this) - v).LengthSqr();
	}
	inline float Vector3::Distance(const Vector3& v)
	{
		return ((*this) - v).Length();
	}
	inline Vector3 Vector3::Normalized()
	{
		float length = Length();

		return (length == 0) ? Vector3{ 0, 0, 0 } : Vector3{ x / length, y / length, z / length };
	}
	inline void Vector3::Normalize()
	{
		(*this /= Length());
	}
};
