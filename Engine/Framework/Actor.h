#pragma once
#include "GameObject.h"
#include "Component.h"
#include <vector>
#include <memory>


namespace nae
{
	class Scene;
	class Renderer;

	class Actor : public GameObject, public ISerializable
	{
	public:
		Actor() = default;
		Actor(const Actor& other);
		Actor(const Transform& transform) : m_transform{ transform } {}

		CLASS_DECLARATION(Actor)

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Draw(Renderer& renderer);
	
		void AddChild(std::unique_ptr<Actor> child);


		//components
		void AddComponent(std::unique_ptr<Component> component);


		template<typename T>
		T* GetComponent();

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return 0; } //m_model.GetRadius()* std::max(m_transform.scale.x, m_transform.scale.y); }

		void SetTag(const std::string& tag) { this->tag = tag; }
		const std::string& GetTag() { return tag; }

		void SetName(const std::string& name) { this->name = name; }
		const std::string& GetName() { return name; }

		void SetDestroy() { m_destroy = true; }
		bool IsDestroyed() { return m_destroy; }

		void SetActive(bool active = true) { this->active = active; }
		bool IsActive() { return active; }

		Scene* GetScene() { return m_scene; }

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		friend class Scene;


		Transform m_transform;
	protected:
		std::string name;
		std::string tag;

		bool active = true;
		bool m_destroy = false;

		Scene* m_scene = nullptr;
		Actor* m_parent = nullptr;
		std::vector<std::unique_ptr<Component>> m_components;
		std::vector<std::unique_ptr<Actor>> m_children;

		// Inherited via ISerializable
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