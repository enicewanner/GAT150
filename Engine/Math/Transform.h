#pragma once
#include "Vector2.h"
#include "Matrix3x3.h"
#include "MathUtils.h"
#include "Serialization/Serializable.h"

namespace nae{
	struct Transform : public ISerializable{

		Vector2 position;
		float rotation = 0.0f;
		Vector2 scale = { 1, 1 };


		//Transform = default;
		//Transform(const Vector2& position, float rotation, const Vector2& scale) :
		//	position{ position },
		//	rotation{ rotation },
		//	scale{ scale }
		//{}


		Matrix3x3 matrix;

		void Update(){
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(nae::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale };
		}

		void Update(const Matrix3x3& parent){
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(nae::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			matrix = { mxTranslation * mxRotation * mxScale };
			matrix = parent * matrix;
		}

		operator Matrix3x3 () const{
			Matrix3x3 mxScale = Matrix3x3::CreateScale(scale);
			Matrix3x3 mxRotation = Matrix3x3::CreateRotation(nae::DegToRad(rotation));
			Matrix3x3 mxTranslation = Matrix3x3::CreateTranslation(position);

			return { mxTranslation * mxRotation * mxScale };
		}

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	};
}