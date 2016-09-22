#ifndef ABSTRACTRENDERER_H
#define ABSTRACTRENDERER_H
#include "glew-2.0.0\include\GL\glew.h"
#include "DebugLogger.h"
#include <cstdio>
namespace OriEngine {
	class AbstractRenderer{
	public:
		AbstractRenderer() {
			DebugLogger::getInstance().log(DebugLogger::TRACE, "AbstractEngine", "getInstance", __FILE__, __LINE__, "Engine Started");
		}
		virtual void drawPrimative() = 0;
		virtual void init() = 0;
		
		virtual void versionInfo() = 0;

	};
	class AbstractRendererBuilder {

	public:
		virtual AbstractRenderer* createRenderer() = 0;
	};
}
#endif 
