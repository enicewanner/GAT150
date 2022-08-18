#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

#define REGISTER_CLASS(class) Factory::Instace().Register<class(#class)


namespace nae
{
	class GameObject
	{
	public:
		GameObject() = default;


		virtual void Update() = 0;
	};
}