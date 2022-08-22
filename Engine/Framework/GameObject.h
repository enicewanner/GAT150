#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"
#include "Factory.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);


namespace nae
{
	class GameObject
	{
	public:
		GameObject() = default;


		virtual void Update() = 0;
	};
}