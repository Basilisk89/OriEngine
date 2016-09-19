
#include <Assimp\include\assimp\Importer.hpp>
#include<glm\glm\vec3.hpp>
#include "DebugLogger.h"
#include "Clock.h"
#include "OpenGlRenderer.h"
#include <iostream>

using namespace OriEngine;
Clock clock;
int main(int args, char* argv[]) {
	clock.init();
    AbstractRenderer* ogl = new OpenGlRenderer();
	DebugLogger::getInstance().log(DebugLogger::MsgType::INFO, "Main", "Main", __FILE__, __LINE__, "Main Started");
	DebugLogger::getInstance().log(DebugLogger::MsgType::FATAL_ERROR, "Main", "Main", __FILE__, __LINE__, "Test of Error");
    ogl->init();

	ogl->drawPrimative();
	while (clock.getDeltaTime() > 0.0) {
	//	std::cout << clock.getDeltaTime() << std::endl;
	}
	return 0;

}