#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"
#include "Input/InputSystem.h"

namespace nae
{
	class PlayerComponent : public Component, public ICollision
	{
	public:
		PlayerComponent() = default;
		
		CLASS_DECLARATION(PlayerComponent)

		void Initialize() override;
		void Update() override;

		// Inherited via ICollision
		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;


		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		float speed = 0;

	};
}
