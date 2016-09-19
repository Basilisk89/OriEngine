#ifndef ABSTRACTRENDERER_H
#define ABSTRACTRENDERER_H
#include "glew-2.0.0\include\GL\glew.h"
#include "DebugLogger.h"
#include <cstdio>
namespace OriEngine {
	class AbstractRenderer{
	public:
		explicit AbstractRenderer();
		virtual void drawPrimative() = 0;
		virtual void init() = 0;
		virtual ~AbstractRenderer();
		virtual void versionInfo() = 0;
	};
}
#endif 
