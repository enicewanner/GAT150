#pragma once
#include "Framework/Component.h"
#include "Input/InputSystem.h"

namespace nae
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;
		
		void Update() override;
		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	private:
		float speed = 0;
	};
}
