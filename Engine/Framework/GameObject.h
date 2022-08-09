#pragma once
#include "../Math/Transform.h"

namespace nae
{
	class GameObject
	{
	public:
		GameObject() = default;


		virtual void Update() = 0;
	};
}