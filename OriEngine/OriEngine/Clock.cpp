#include "Clock.h"
using namespace OriEngine;
Clock::Clock(){
	
}
Clock::~Clock(){
}

 void Clock::init() {
	highResClock = QueryPerformanceFrequency(&freq);
	counter = Clock::getTicks();
}
void Clock::elapsedTime() {
	QueryPerformanceCounter(&endTime);
}
inline LARGE_INTEGER Clock::getTicks()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return LARGE_INTEGER(li);
}

inline LARGE_INTEGER Clock::getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e)
{
	
	LARGE_INTEGER result;
	result.QuadPart = e.QuadPart - s.QuadPart;
	return result;
}

inline double OriEngine::Clock::lastFrame(double now, double last)
{
	return 0.0;
}

inline double Clock::getSeconds(LARGE_INTEGER li)
{
	double result;
	result = (double)li.QuadPart;
	return result;
}

 double Clock::getDeltaTime()
{
		
	deltaTime = (double)getCounterDifference(startTime, endTime).QuadPart/(double)freq.QuadPart;

	return deltaTime;
}
