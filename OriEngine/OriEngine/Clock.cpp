#include "Clock.h"

using namespace OriEngine;
LARGE_INTEGER Clock::counter,Clock::time, Clock::freq, Clock::start,Clock::end;
double Clock::deltaTime;
bool Clock::highResClock = false;
Clock::Clock(){
	

}
Clock::~Clock(){
}
void Clock::init() {
	highResClock = QueryPerformanceFrequency(&freq);
	counter = Clock::getTicks();
	start = Clock::getTicks();
}
double Clock::elapsedTime() {
	return deltaTime = (double)getCounterDifference(end,start) / (double)freq.QuadPart;
}
double Clock::getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e){
	double result;
	result = e.QuadPart - s.QuadPart;
	return result;
}
double OriEngine::Clock::lastFrame(double now, double last){
	return 0.0;
}
 void Clock::getEnd() {
	 end = Clock::getTicks();
 }

