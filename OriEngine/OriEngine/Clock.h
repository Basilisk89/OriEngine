#ifndef CLOCK_H
#define CLOCK_H
#include <Windows.h>
#include "DebugLogger.h"
namespace OriEngine {
	class Clock	{
	public:
		Clock();
		~Clock();
		 void init();
		 void elapsedTime();
		 inline LARGE_INTEGER getTicks(LARGE_INTEGER li);
		inline LARGE_INTEGER getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e);
		 inline double getSeconds(LARGE_INTEGER li);
		 double getDeltaTime() ;
	private:
		LARGE_INTEGER startTime, endTime, time, freq;
		double start, end, deltaTime;
		bool highResClock;
	};
}
#endif
