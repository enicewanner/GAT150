#pragma once
#include "Framework/Component.h"
namespace nae
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value);
		virtual bool Read(const rapidjson::Value& value);
		virtual void Update() override;
	};
}