#pragma once
#include "GameObject.h"

namespace nae
{
	class Actor;

	class Component : public GameObject, public ISerializable
	{
	friend class Actor;
	public:
		Component() = default;

		virtual void Initialize() override {}
		virtual void Update() = 0;


	protected:
		Actor* m_owner = nullptr;


	};
}