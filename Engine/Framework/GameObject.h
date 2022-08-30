#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"
#include "Factory.h"
	
#define CLASS_DECLARATION(class)  \
std::unique_ptr<GameObject> Clone() override {return std::make_unique<class>(*this);}
#define REGISTER_CLASS(class) nae::Factory::Instance().Register<class>(#class);


namespace nae
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual std::unique_ptr<GameObject> Clone() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;


	};
}