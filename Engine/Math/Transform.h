#pragma once
#include "Vector2.h"

namespace nae
{
	struct Transform
	{

		Vector2 position;
		float rotation;
		Vector2 scale{1,1};

	};
}