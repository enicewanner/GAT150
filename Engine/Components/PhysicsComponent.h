#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace nae
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;

		void Update() override;
		void ApplyForce(const Vector2& force) { m_acceleration += force; }

	public:
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float damping = 0.99f;

		// Inherited via Component
		virtual bool Read(const rapidjson::Value& value) override;
		virtual bool Write(const rapidjson::Value& value) const override;

	private:
		
	};
}

