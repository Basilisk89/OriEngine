#ifndef CLOCK_H
#define CLOCK_H
#include <Windows.h>
#include "DebugLogger.h"
namespace OriEngine {
	class Clock	{
	public:
		Clock();
		~Clock();
		 static void init();
		static void elapsedTime();
		 static inline LARGE_INTEGER getTicks();
		static inline LARGE_INTEGER getCounterDifference(LARGE_INTEGER s, LARGE_INTEGER e);
		static inline double lastFrame(double now, double last);
		static inline double getSeconds(LARGE_INTEGER li);
		 static double getDeltaTime() ;
	private:
		static LARGE_INTEGER startTime, endTime, time, freq,counter;
		static double start, end, deltaTime;
		static bool highResClock;
	};
}
#endif
