#ifndef CLOCK_H
#define CLOCK_H
#include <Windows.h>
#include "DebugLogger.h"
namespace OriEngine {
	class Clock	{
	public:
		 static LARGE_INTEGER startTime, endTime, time, freq,counter;
		 static double start, end, deltaTime;
		 static bool highResClock;
		 static inline LARGE_INTEGER getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e);
		 static inline double lastFrame(double now, double last);
		 static inline double getSeconds(LARGE_INTEGER li);	
		 static inline LARGE_INTEGER getTicks();
		 static double getDeltaTime() ;
		 static void elapsedTime();
		 static void init(); 
		 ~Clock();
	private:
		Clock();
	
	};
}
#endif
