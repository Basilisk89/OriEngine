#ifndef CLOCK_H
#define CLOCK_H
#include <Windows.h>
#include "DebugLogger.h"
namespace OriEngine {
	class Clock	{
	public:
		 static LARGE_INTEGER counter,time,freq;
		 static double start, end, deltaTime;
		 static bool highResClock;
		 static inline LARGE_INTEGER getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e);
		 static inline double lastFrame(double now, double last);
		 static inline LARGE_INTEGER getCurrentTicks() {
			 LARGE_INTEGER result;
			 result.QuadPart = getTicks().QuadPart;
			 return result;
		 }
		 static inline void getFrequency(LARGE_INTEGER frequency) {
			 QueryPerformanceFrequency(&frequency);
		}
		 static inline double getTime() {
			 return ticksToSeconds(getCurrentTicks());
		 }
		 static inline LARGE_INTEGER getTicks() {
			 LARGE_INTEGER li;
			 QueryPerformanceCounter(&li);
			 return LARGE_INTEGER(li);
		 }
	
		 static void elapsedTime();
		 static void init(); 
		 static inline double ticksToSeconds(LARGE_INTEGER ticks)
		 {
			 return ((double)ticks.QuadPart) / ((double)time.QuadPart);
		 }
		 ~Clock();
	private:
		Clock();
	
	};
}
#endif
