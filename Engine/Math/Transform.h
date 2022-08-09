#pragma once
#include "Vector2.h"
#include "Matrix2x2.h"
#include "MathUtils.h"

namespace nae
{
	struct Transform
	{

		Vector2 position;
		float rotation;
		Vector2 scale{1,1};

		operator Matrix2x2 () const
		{
			Matrix2x2 mxs = Matrix2x2::CreateScale(scale);
			Matrix2x2 mxr = Matrix2x2::CreateRotation(Math::DegToRad(rotation));

			return { mxs * mxr };
		}


	};
}