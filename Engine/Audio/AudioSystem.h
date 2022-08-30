#pragma once

// !! include the necessary includes (do not include fmod here) !! 
#include "AudioChannel.h"
#include <iostream>
#include <map>


// forward declaration to classes in the FMOD namespace 
namespace FMOD
{
	class System;
	class Sound;
}

namespace nae
{
	class AudioSystem
	{
	public:
		AudioSystem() = default;
		~AudioSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		void AddAudio(const std::string& name, const std::string& filename);
		AudioChannel PlayAudio(const std::string& name, float volume = 1, float pitch = 1, bool loop = false);

	private:
		FMOD::System* m_fmodSystem;
		std::map<std::string, FMOD::Sound*> m_sounds;

	};
}
