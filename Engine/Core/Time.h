#pragma once

#include <chrono>

namespace crae
{

	class Time
	{
	private:
		using clock = std::chrono::high_resolution_clock; //shorten typing down to 'clock' to call library functions
		using clock_duration = clock::duration;
		using clock_rep = clock::rep; //64 bit int - long long

	public:
		Time() : 
			m_startTimePoint{ clock::now() },
			m_frameTimePoint{ clock::now() }
		{}

		void Tick();
		void Reset() { m_startTimePoint = clock::now(); }

	public:
		float deltaTime = 0;
		float time = 0;


	private:

		clock::time_point m_startTimePoint; // time at start of game
		clock::time_point m_frameTimePoint; // time at Start of frame
		
	};
}