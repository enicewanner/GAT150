#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace nae
{


	void PlayerComponent::Update()
	{

		Vector2 direction = Vector2::zero;
		if (g_inputSystem.GetKeyState(key_down) == InputSystem::State::Held)
		{
			//direction = Vector2::down;
		}

		float thrust = 0;
		if (g_inputSystem.GetKeyState(key_up) == InputSystem::State::Held)
		{
			thrust = 500;
		}



		if (g_inputSystem.GetKeyState(key_left) == InputSystem::State::Held)
		{
			m_owner->m_transform.rotation -= 90 * g_time.deltaTime;
		}
		if (g_inputSystem.GetKeyState(key_right) == InputSystem::State::Held)
		{
			m_owner->m_transform.rotation += 90 * g_time.deltaTime;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{

			Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(m_owner->m_transform.rotation)) * thrust;

			component->ApplyForce(force);

			//gravitational force
			/*force = (Vector2{ 400,400 } - m_owner->m_transform.position).Normalized() * 100.0f;
			component->ApplyForce(force);*/
		}

		m_owner->m_transform.position += direction * 300 * g_time.deltaTime;
		
		//missle fire
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component)
			{
				component->Play();
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}



}
