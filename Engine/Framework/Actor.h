#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>
#include <memory>


namespace nae
{
	class Scene;
	class Renderer;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{ transform } {}
		
		virtual void Update() override;
		virtual void Draw(Renderer& renderer);
	
		void AddComponent(std::unique_ptr<Component> component);


		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; } //m_model.GetRadius()* std::max(m_transform.scale.x, m_transform.scale.y); }
		std::string& GetTag() { return m_tag; }


		friend class Scene;


		Transform m_transform;
	protected:
		std::string m_tag;
		bool m_destroy = false;
		Vector2 m_velocity;
		float m_damping = 1;

		Scene* m_scene = nullptr;
		std::vector<std::unique_ptr<Component>> m_components;
	};
	template<typename T>
	inline T* Actor::GetComponent()
	{
		for (auto& component : m_components)
		{
			T* result = dynamic_cast<T*>(component.get());
			if (result) return result;
		}

		return nullptr;
	}
}