#include <glew-2.0.0\include\GL\glew.h>
#include <Assimp\include\assimp\Importer.hpp>
#include<glm\glm\vec3.hpp>
#include "DebugLogger.h"
#include "Clock.h"
#include <iostream>
using namespace OriEngine;
Clock clock;
int main(int args, char* argv[]) {
	clock.init();
	
	DebugLogger::getInstance().log(DebugLogger::MsgType::INFO, "Main", "Main", __FILE__, __LINE__, "Main Started");
	DebugLogger::getInstance().log(DebugLogger::MsgType::FATAL_ERROR, "Main", "Main", __FILE__, __LINE__, "Test of Error");
	
	while (clock.getDeltaTime() != 0.0) {
		std::cout << clock.getDeltaTime() << std::endl;
	}
	return 0;

}