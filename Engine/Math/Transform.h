#pragma once
#include "Serialization/Serializable.h"

#include "Vector2.h"
#include "Matrix2x2.h"
#include "Matrix3x3.h"
#include "MathUtils.h"

namespace nae
{
	struct Transform : public ISerializable
	{

		Vector2 position;
		float rotation;
		Vector2 scale{1,1};

		Matrix3x3 matrix;


		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;
		
		void Update()
		{
			Matrix3x3 mxs = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxr = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxt = Matrix3x3::CreateTranslation(position);

			matrix = { mxt * mxr * mxs };
		}

		void Update(const Matrix3x3& parent)
		{
			Matrix3x3 mxs = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxr = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxt = Matrix3x3::CreateTranslation(position);

			matrix = { mxt * mxr * mxs };
			matrix = parent * matrix;
		}

		operator Matrix3x3 () const
		{
			Matrix3x3 mxs = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxr = Matrix3x3::CreateRotation(Math::DegToRad(rotation));
			Matrix3x3 mxt = Matrix3x3::CreateTranslation(position);

			return { mxt * mxr * mxs};
		}



	};
}