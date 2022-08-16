#pragma once
#include "RenderComponent.h"

namespace nae
{
	class Texture;

	class ModelComponent : public RenderComponent
	{
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;


	public:
		std::shared_ptr<Texture> m_texture;
	};
}