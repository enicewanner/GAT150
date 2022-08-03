#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <string>

namespace nae
{
	struct Vector2
	{
		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		Vector2(float v) : x{ v }, y{ v } {}
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		//arithmetic operators

		void Set(float x, float y) { this->x = x, this->y = y; }
	
		Vector2 operator + (const Vector2& v) const { return Vector2{ this->x + v.x, this->y + v.y }; }
		Vector2 operator - (const Vector2& v) const { return Vector2{ this->x - v.x, this->y - v.y }; }
		Vector2 operator * (const Vector2& v) const { return Vector2{ this->x * v.x, this->y * v.y }; }
		Vector2 operator / (const Vector2& v) const{ return Vector2{ this->x / v.x, this->y / v.y }; }


		Vector2 operator + (float s) const { return Vector2{ this->x + s, this->y + s }; }
		Vector2 operator - (float s) const { return Vector2{ this->x - s, this->y - s }; }
		Vector2 operator * (float s) const { return Vector2{ this->x * s, this->y * s }; }
		Vector2 operator / (float s) const { return Vector2{ this->x / s, this->y / s }; }


		Vector2& operator += (const Vector2& v)  { this->x += v.x, this->y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v)  { this->x -= v.x, this->y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v)  { this->x *= v.x, this->y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v)  { this->x /= v.x, this->y /= v.y; return *this; }

		Vector2 operator += (float s) { return Vector2{ this->x += s, this->y += s }; }
		Vector2 operator -= (float s) { return Vector2{ this->x -= s, this->y -= s }; }
		Vector2 operator *= (float s) { return Vector2{ this->x *= s, this->y *= s }; }
		Vector2 operator /= (float s) { return Vector2{ this->x /= s, this->y /= s }; }
	
		// unary
		Vector2 operator - () { return Vector2{-x, -y}; }

		//comparison
		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

		//functions
		float LengthSqr();
		float Length();

		float DistanceSqr(const Vector2& v);
		float Distance(const Vector2& v);

		Vector2 Normalized();
		void Normalize();

		float GetAngle();

		static Vector2 Rotate(const Vector2& v, float angle);

	};

	inline std::istream& operator >> (std::istream& stream, Vector2& v) 
	{
		std::string line;
		std::getline(stream, line);
		
		//{ ##, ##}

		std::string xs = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
		v.x = std::stof(xs);
		std::string ys = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
		v.y = std::stof(ys);

		return stream;
	}

	inline float Vector2::LengthSqr() 
	{ 
		return x * x + y * y; 
	}
	inline float Vector2::Length() 
	{ 
		return std::sqrt(x * x + y * y); 
	}
	inline float Vector2::DistanceSqr(const Vector2& v)
	{
		return ((*this) - v).LengthSqr();
	}
	inline float Vector2::Distance(const Vector2& v)
	{
		return ((*this) - v).Length();
	}
	inline Vector2 Vector2::Normalized()
	{
		float length = Length();

		return Vector2{x / length, y / length};
	}
	inline void Vector2::Normalize()
	{
		(*this /= Length());
	}

	inline float Vector2::GetAngle()
	{
		return std::atan2(y, x);
	}

	inline Vector2 Vector2::Rotate(const Vector2& v, float angle)
	{
		float x = v.x * std::cos(angle) - v.y * std::sin(angle);
		float y = v.x * std::sin(angle) + v.y * std::cos(angle);

		return Vector2(x, y);
	}

}