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

		float m_damping = 0.99;

	private:
	};
}

