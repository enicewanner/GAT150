#include "CollisionComponents.h"
#include "Engine.h"
#include <iostream>

namespace nae
{

	void CollisionComponent::Initialize()
	{
		auto component = m_owner->GetComponent<RBPhysicsComponent>();
		if (component)
		{
			// if data was not set, get size from render component source rect 
			if (data.size.x == 0 && data.size.y == 0)// !! check data.size.x == 0 and data.size.y == 0) 
			{
				auto renderComponent = m_owner->GetComponent<RenderComponent>();// !! check render component from the owner 
					if (renderComponent)
					{
						data.size = Vector2{m_owner->GetComponent<RenderComponent>()->GetSource().w, m_owner->GetComponent<RenderComponent>()->GetSource().h}; // !! render component source.w, render component source.h };
					}
			}

			g_physicsSystem.SetCollisionBox(component->m_body, data, m_owner);
		}
	}

	void CollisionComponent::Update()
	{
		
	}

	void CollisionComponent::OnCollisionEnter(Actor* other)
	{
		if (m_enterFunction) m_enterFunction(other);

		std::cout << other->GetName() << std::endl;
	}

	void CollisionComponent::OnCollisionExit(Actor* other)
	{
		if (m_exitFunction) m_exitFunction(other);

		std::cout << other->GetName() << std::endl;
	}

	bool CollisionComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool CollisionComponent::Read(const rapidjson::Value& value)
	{

		READ_DATA(value, data.size);
		READ_DATA(value, data.density);
		READ_DATA(value, data.friction);
		READ_DATA(value, data.restitution);
		READ_DATA(value, data.is_trigger);

		return true;
	}
}
