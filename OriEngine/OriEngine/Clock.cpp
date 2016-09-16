#include "Clock.h"
using namespace OriEngine;
Clock::Clock(){
}
Clock::~Clock(){
}

void Clock::init(){
	QueryPerformanceFrequency(&freq);
	startTime = getTicks(time);
	endTime = getTicks(time);
	
}

inline LARGE_INTEGER Clock::getTicks(LARGE_INTEGER li)
{
	QueryPerformanceCounter(&li);
	return LARGE_INTEGER(li);
}

inline LARGE_INTEGER Clock::getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e)
{
	LARGE_INTEGER result;
	result.QuadPart = s.QuadPart - e.QuadPart;
	return result;
}

inline double Clock::getSeconds(LARGE_INTEGER li)
{
	double result;
	result = li.QuadPart;
	return result;
}

 double Clock::getDeltaTime()
{
	deltaTime = (float)getCounterDifference(startTime, endTime).QuadPart/(float)freq.QuadPart;

	return deltaTime;
}
