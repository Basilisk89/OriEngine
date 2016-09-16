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
		static inline LARGE_INTEGER getTicks(LARGE_INTEGER li);
		static inline double getSeconds(LARGE_INTEGER li);
		static inline double getDeltaTime(double seconds) ;
	private:
		LARGE_INTEGER startTime, endTime, time, freq;
		double start, end, deltaTime;
	};
}
#endif
