#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

void nae::PlayerComponent::Initialize(){
	
	CharacterComponent::Initialize();

	
}

void nae::PlayerComponent::Update(){
	Vector2 direction = Vector2::zero;
	
	auto camera = m_owner->GetScene()->GetActorFromName("Camera");
	if (camera)
	{
		camera->m_transform.position = nae::Lerp(camera -> m_transform.position, m_owner->m_transform.position, 2 * g_time.deltaTime);
	}

	if (g_inputSystem.GetKeyState(key_a) == InputSystem::State::Held){

		direction = Vector2::left;
	}

	if (g_inputSystem.GetKeyState(key_d) == InputSystem::State::Held){
		direction = Vector2::right;
	}

	float  thrust = 0;
	if (g_inputSystem.GetKeyState(key_w) == InputSystem::State::Held){

		thrust = speed;
	}

	Vector2 velocity;
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component){
		
		component->ApplyForce(direction * speed);
		velocity = component->velocity;

	}

	m_owner->m_transform.position += direction * 300 * g_time.deltaTime;

	if (m_groundCount > 0 && g_inputSystem.GetKeyState(key_space) == InputSystem::State::Press){

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component) {
			Vector2 force = Vector2::Rotate({ 1, 0 }, nae::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->ApplyForce(Vector2::up * jump);

		}
	}

	auto animComponent = m_owner->GetComponent<SpriteAnimComponent>();
	if (animComponent)
	{
		if (velocity.x != 0) animComponent->SetFlipHorizontal(velocity.x < 0);
		if (std::fabs(velocity.x) > 0)
		{
			animComponent->SetSequence("run");
		}
		else
		{
			animComponent->SetSequence("idle");
		}
	}
}

bool nae::PlayerComponent::Write(const rapidjson::Value& value) const{

	return true;
}

bool nae::PlayerComponent::Read(const rapidjson::Value& value){

	CharacterComponent::Read(value);
	READ_DATA(value, jump);

	return true;
}

void nae::PlayerComponent::OnNotify(const Event& event){

	if (event.name == "EVENT_DAMAGE") {
		health -= std::get<float>(event.data);
		std::cout << health << std::endl;
		if (health <= 0) {
			//Player dead
		}
	}
}

void nae::PlayerComponent::OnCollisionEnter(Actor* other){

	if (other->GetTag() == "Ground")
	{
		m_groundCount++;
	}

	if (other->GetName() == "Coin") {

		Event event;
		event.name = "EVENT_ADD_POINTS";
		event.data = 100;

		g_eventManager.Notify(event);

		other->SetDestroy();
	}

	if (other->GetTag() == "Enemy") {

		Event event;
		event.name = "EVENT_DAMAGE";
		event.data = damage;
		event.receiver = other;

		g_eventManager.Notify(event);

		other->SetDestroy();

	}
}

void nae::PlayerComponent::OnCollisionExit(Actor* other){
	if (other->GetTag() == "Ground")
	{
		m_groundCount--;
	}
}
