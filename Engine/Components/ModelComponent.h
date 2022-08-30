#pragma once
#include "RenderComponent.h"
#include "Renderer/Model.h"

namespace nae
{
	class Texture;

	class ModelComponent : public RenderComponent
	{
	public:
		CLASS_DECLARATION(ModelComponent)

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		std::shared_ptr<Texture> m_texture;
		std::shared_ptr<Model> m_model;
	};
}