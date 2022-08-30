#pragma once
#include "Framework/Component.h"
#include "rapidjson/rapidjson.h"
#include "Math/Rect.h"

namespace nae
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;

		virtual Rect& GetSource() { return source; }
		
	protected:
		Rect source;

	};
}