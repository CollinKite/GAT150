#include "Time.h"

namespace crae
{
	void Time::Tick()
	{
		//auto duration = clock::now() - m_startTimePoint; //Could set auto datatype
		clock_duration duration = clock::now() - m_startTimePoint;
		time = duration.count() / (float)clock_duration::period::den; //denominator for nano seconds in seconds. Gives us seconds of runtime, need to cast either value to float.

		duration = clock::now() - m_frameTimePoint;
		deltaTime = duration.count() / (float)clock_duration::period::den;

		m_frameTimePoint = clock::now();
	}
}

