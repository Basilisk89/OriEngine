#include "Clock.h"
using namespace OriEngine;
Clock::Clock(){
}
Clock::~Clock(){
}

void Clock::init(){
	startTime = getTicks(time);
	endTime = getTicks(time);
}

inline LARGE_INTEGER Clock::getTicks(LARGE_INTEGER li)
{
	QueryPerformanceCounter(&li);
	return LARGE_INTEGER(li);
}

inline double Clock::getSeconds(LARGE_INTEGER li)
{

	return 0.0;
}

inline double Clock::getDeltaTime(double seconds)
{
	return 0.0;
}
