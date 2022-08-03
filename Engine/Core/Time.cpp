#include "Time.h"

namespace nae
{
	void Time::Tick()
	{
		clock::duration duration = clock::now() - m_startTimePoint;
		time = duration.count() / (float)clock_duration::period::den;

		duration = clock::now() - m_frameTimePoint;
		deltaTime = duration.count() / (float)clock_duration::period::den;

		m_frameTimePoint = clock::now();
	}
}

