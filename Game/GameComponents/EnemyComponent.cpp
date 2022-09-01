#include "EnemyComponent.h"
#include "Engine.h"
#include <iostream>

void EnemyComponent::Initialize()
{
    CharacterComponent::Initialize();
}

void EnemyComponent::Update()
{
    auto actor = m_owner->GetScene()->GetActorFromName("Player");
    if (actor)
    {
        nae::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
        nae::Vector2 force = direction.Normalized() * speed;

        auto component = m_owner->GetComponent<nae::PhysicsComponent>();
        if (component) component->ApplyForce(force);
    }
}

void EnemyComponent::OnCollisionEnter(nae::Actor* other)
{
    if (other->GetTag() == "Player")
    {
        nae::Event event;
        event.name = "EVENT_DAMAGE";
        event.data = damage;
        event.receiver = other;
        nae::g_eventManager.Notify(event);
    }
}

void EnemyComponent::OnCollisionExit(nae::Actor* other)
{
}

void EnemyComponent::OnNotify(const nae::Event& event)
{
    if (event.name == "EVENT_DAMAGE")
    {
 /*       health -= std::get<float>(event.data);
        if (health <= 0)
        {
            m_owner->SetDestroy();
        }*/
    }
    if (event.name == "EVENT_PLAYER_DEAD")
    {
        m_owner->SetDestroy();
    }

}

bool EnemyComponent::Write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::Read(const rapidjson::Value& value)
{
    CharacterComponent::Read(value);

    return true;
}