#include "AudioChannel.h"
#include "fmod.hpp"


namespace nae
{
	bool AudioChannel::IsPlaying()
	{
		// !! if channel is null, return false 
		if (m_channel == nullptr)
		{
			return false;
		}

		bool isPlaying;
		m_channel->isPlaying(&isPlaying);

		return isPlaying;
	}

	void AudioChannel::Stop()
	{
		if (IsPlaying()) m_channel->stop();
	}

	void AudioChannel::SetPitch(float pitch)
	{
		if (IsPlaying())
		{
			// !! call setPitch on channel (pass pitch)
			m_channel->setPitch(pitch);
		} 
	}

	float AudioChannel::GetPitch()
	{
		float pitch = 0;
		if (IsPlaying()) // !! call getPitch (pass pointer to pitch &) 
		{
			m_channel->getPitch(&pitch);
		}
			return pitch;
	}

	void AudioChannel::SetVolume(float volume)
	{
		if (IsPlaying()) // !! call setVolume on channel (pass volume) 
		{
			m_channel->setVolume(volume);
		}
	}

	float AudioChannel::GetVolume()
	{
		float volume = 0;
		if (IsPlaying()) // !! call getVolume (pass pointer to volume &) 
		{
			m_channel->getVolume(&volume);
		}
			return volume;
	}
}