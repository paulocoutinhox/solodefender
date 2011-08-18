#pragma once

#include <ctime>

class Timer
{
	public:
		Timer(void);
		~Timer(void);
		
		bool elasped(clock_t ms);
	private:
		clock_t counter;
};
