#pragma once 

namespace FMOD
{
	class Channel;
}

namespace crae
{
	class AudioChannel
	{
	public:
		AudioChannel() {}
		AudioChannel(FMOD::Channel* channel) { m_channel = channel; } // !! set m_channel 

		bool IsPlaying();
		void Stop();
		void SetPitch(float pitch);
		float GetPitch();

		void SetVolume(float volume);
		float GetVolume();


		// !! create SetPitch/GetPitch (takes float, returns float) 
		// !! create SetVolume/GetVolume (takes float, returns float) 

	private:
		FMOD::Channel* m_channel = nullptr;
	};
}