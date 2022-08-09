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

	private:
	};
}
