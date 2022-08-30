#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace nae
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

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
			//m_owner->m_transform.rotation -= 90 * g_time.deltaTime;
			direction = Vector2::left;
		}
		if (g_inputSystem.GetKeyState(key_right) == InputSystem::State::Held)
		{
			//m_owner->m_transform.rotation += 90 * g_time.deltaTime;
			direction = Vector2::right;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{

			//Vector2 force = Vector2::Rotate({ 1, 0 }, Math::DegToRad(m_owner->m_transform.rotation)) * thrust;

			component->ApplyForce(direction * speed);

			//gravitational force
			/*force = (Vector2{ 400,400 } - m_owner->m_transform.position).Normalized() * 100.0f;
			component->ApplyForce(force);*/
		}

		
		//jump
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::State::Pressed)
		{
			if (component)
			{
				component->ApplyForce(Vector2::up * 20);

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

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			Event _event;
			_event.name = "EVENT_ADD_POINTS";
			_event.data = 100;

			g_eventManager.Notify(_event);
			other->SetDestroy();
		}

		std::cout << "Player enter\n";
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player exit\n";
	}



}
