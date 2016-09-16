#include <glew-2.0.0\include\GL\glew.h>
#include <Assimp\include\assimp\Importer.hpp>
#include<glm\glm\vec3.hpp>
#include "DebugLogger.h"
using namespace OriEngine;
int main(int args, char* argv[]) {
	DebugLogger::getInstance().log(DebugLogger::MsgType::INFO, "Main", "Main", __FILE__, __LINE__, "Main Started");
	DebugLogger::getInstance().log(DebugLogger::MsgType::ERROR, "Main", "Main", __FILE__, __LINE__, "Test of Error");
	return 0;
}