#include "Clock.h"
using namespace OriEngine;
LARGE_INTEGER Clock::counter;
LARGE_INTEGER Clock::time, Clock::freq;
bool Clock::highResClock = false;
Clock::Clock(){
	
}
Clock::~Clock(){
}

 void Clock::init() {
	highResClock = QueryPerformanceFrequency(&freq);
	counter = Clock::getTicks();
}
void Clock::elapsedTime() {
//	QueryPerformanceCounter(&endTime);
}

 LARGE_INTEGER Clock::getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e)
{
	
	LARGE_INTEGER result;
	result.QuadPart = e.QuadPart - s.QuadPart;
	return result;
}

 double OriEngine::Clock::lastFrame(double now, double last)
{
	return 0.0;
}



