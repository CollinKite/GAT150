#pragma once

#include "Framework/Component.h"

namespace crae
{
	class AudioComponent : public Component
	{
	public:
		std::string m_soundName;
		bool m_playOnAwake = false;
		float m_volume = 1.0f; //0-1
		float m_pitch = 1.0f;
		bool m_loop = false;
	public:
		AudioComponent() = default;

		void Update() override;

		void Play();

		void Stop();

	};
}