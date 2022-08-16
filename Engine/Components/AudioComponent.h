#pragma once
#include "Framework/Component.h"
#include "Engine.h"
#include <string>

namespace nae
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;
		void Play();
		void Stop();

		std::string m_soundname;
		bool m_playonawake = false;
		bool m_loop = false;
		float m_volume = 1;
		float m_pitch = 1;
	private:
	};
}
