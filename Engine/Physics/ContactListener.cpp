#include "ContactListener.h"
#include "Framework/Actor.h"
#include "Components/CollisionComponents.h"
#include <iostream>

namespace nae
{
	void ContactListener::BeginContact(b2Contact* contact)
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if (fixtureA->GetUserData().pointer && fixtureB->GetUserData().pointer)
		{
			Actor* actorA = (Actor*)(fixtureA->GetUserData().pointer);
			Actor* actorB = (Actor*)(fixtureB->GetUserData().pointer);

			if (!actorA->IsDestroyed() && actorA->GetComponent<CollisionComponent>())
			{
				actorA->GetComponent<CollisionComponent>()->OnCollisionEnter(actorB);
			}
			if (!actorB->IsDestroyed() && actorB->GetComponent<CollisionComponent>())
			{
				actorB->GetComponent<CollisionComponent>()->OnCollisionEnter(actorA);
			}
		}
	}

	void ContactListener::EndContact(b2Contact* contact)
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if (fixtureA->GetUserData().pointer && fixtureB->GetUserData().pointer)
		{
			Actor* actorA = (Actor*)(fixtureA->GetUserData().pointer);
			Actor* actorB = (Actor*)(fixtureB->GetUserData().pointer);

			std::cout << "End A:" << actorA->GetName() << std::endl;
			std::cout << "End B:" << actorB->GetName() << std::endl;

			if (!actorA->IsDestroyed() && actorA->GetComponent<CollisionComponent>())
			{
				actorA->GetComponent<CollisionComponent>()->OnCollisionExit(actorB);
			}
			if (!actorB->IsDestroyed() && actorB->GetComponent<CollisionComponent>())
			{
				actorB->GetComponent<CollisionComponent>()->OnCollisionExit(actorA);
			}
		}
	}
}
