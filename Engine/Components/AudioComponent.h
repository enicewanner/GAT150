#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"
#include "Engine.h"
#include <string>

namespace nae
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)


		void Initialize() override;
		void Update() override;
		
		void Play();
		void Stop();

		std::string m_soundname;
		bool m_playonawake = false;
		bool m_loop = false;
		float m_volume = 1;
		float m_pitch = 1;
		
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	private:
		AudioChannel m_channel;

		std::string sound_name;
		float volume = 1;
		float pitch = 1;
		bool play_on_start = false;
		bool loop = false;
	
	};
}
