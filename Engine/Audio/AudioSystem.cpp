#include "AudioSystem.h" 
#include "Core/Logger.h"
#include <fmod.hpp> 
#include <memory>

namespace nae
{
	void AudioSystem::Initialize(){
		FMOD::System_Create(&m_fmodSystem);

		void* extradriverdata = nullptr;
		m_fmodSystem->init(32, FMOD_INIT_NORMAL, extradriverdata);
	}

	void AudioSystem::Shutdown(){
		// !! use range based for-loop to iterate through m_sounds, call release on each element 
		for (auto sound : m_sounds){
			sound.second->release();
		}
		
		m_sounds.clear();
		m_fmodSystem->close();
		m_fmodSystem->release();
	}

	void AudioSystem::Update(){
		 
		m_fmodSystem->update();
	}

	void AudioSystem::AddAudio(const std::string& name, const std::string& filename){
		if (m_sounds.find(name) == m_sounds.end()){
			FMOD::Sound* sound = nullptr;
			m_fmodSystem->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);

			if (sound == nullptr){
				LOG("Error creating sound %s.", filename.c_str());
			}

			m_sounds[name] = sound;
		}
	}

	void AudioSystem::PlayAudio(const std::string& name, bool loop){
		auto iter = m_sounds.find(name);

		if (iter == m_sounds.end()){
			LOG("Error sound not found: %s.", name.c_str());
		}

		if (iter != m_sounds.end()) {
			FMOD::Sound* sound = iter->second;
			if (loop) sound->setMode(FMOD_LOOP_NORMAL);
			else sound->setMode(FMOD_LOOP_OFF);

			FMOD::Channel* channel;
			m_fmodSystem->playSound(sound, 0, false, &channel);
		}

	}

	AudioChannel AudioSystem::PlayAudio(const std::string& name, float volume, float pitch, bool loop)
	{
		
		auto iter = m_sounds.find(name);
		
		if (iter == m_sounds.end()){
			LOG("Error could not find sound %s.", name.c_str());
			return AudioChannel{};
		}

		FMOD::Sound* sound = iter->second;
		FMOD_MODE mode = (loop) ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF;
		sound->setMode(mode);

		FMOD::Channel* channel;
		m_fmodSystem->playSound(sound, 0, false, &channel);
		channel->setVolume(volume);
		channel->setPitch(pitch);
		channel->setPaused(false);

		return AudioChannel{ channel };
	}
}