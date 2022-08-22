#include "PhysicsComponent.h"
#include "Engine.h"

namespace nae
{
	void PhysicsComponent::Update()
	{
		m_velocity += m_acceleration * g_time.deltaTime;
		m_owner->m_transform.position += m_velocity * g_time.deltaTime;
		m_velocity *= damping;

		m_acceleration = Vector2::zero;
	}

	bool PhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool PhysicsComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, damping);
		READ_DATA(value, m_velocity);
		READ_DATA(value, m_acceleration);


		return true;
	}

}
