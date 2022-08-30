#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace nae
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;

		CLASS_DECLARATION(PhysicsComponent)

		void Update() override;
		virtual void ApplyForce(const Vector2& force) { m_acceleration += force; }

		
		virtual bool Read(const rapidjson::Value& value) override;
		virtual bool Write(const rapidjson::Value& value) const override;


	public:
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float damping = 0.99f;
	private:
		
	};
}

