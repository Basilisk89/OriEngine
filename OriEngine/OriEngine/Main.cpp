
#include <Assimp\include\assimp\Importer.hpp>
#include<glm\glm\vec3.hpp>
#include "DebugLogger.h"
#include "Clock.h"
#include "OpenGlRenderer.h"
#include <iostream>
#include "Sound.h"
using namespace OriEngine;

Sound sound;
int main(int args, char* argv[]) {
	
    AbstractRenderer* ogl = new OpenGlRenderer();
	DebugLogger::getInstance().log(DebugLogger::MsgType::INFO, "Main", "Main", __FILE__, __LINE__, "Main Started");
	DebugLogger::getInstance().log(DebugLogger::MsgType::FATAL_ERROR, "Main", "Main", __FILE__, __LINE__, "Test of Error");
    ogl->init();
	sound.init();
	sound.loadSound("$(ProjectDir)/../OriEngineResources/03-terran-1.mp3");
	sound.playSound();
	ogl->drawPrimative();
	while (float loop = 1.0f > 0.0f) {
	//	std::cout << clock.getDeltaTime() << std::endl;
		sound.msystem->update();
	}
	return 0;

}