#include "Timer.h"

Timer::Timer(void)
{
	counter = 0;
}

Timer::~Timer(void)
{
}

bool Timer::elasped(clock_t ms)
{
	clock_t tick = std::clock();

	if(tick - counter >= ms)
	{
		counter = tick;
		return true;
	}

	return false;
}
