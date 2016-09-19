
#include <Assimp\include\assimp\Importer.hpp>
#include<glm\glm\vec3.hpp>
#include "DebugLogger.h"
#include "Clock.h"
#include "OpenGlRenderer.h"
#include <iostream>
#include "Sound.h"
using namespace OriEngine;
Clock clock;
Sound sound;
int main(int args, char* argv[]) {
	clock.init();
    AbstractRenderer* ogl = new OpenGlRenderer();
	DebugLogger::getInstance().log(DebugLogger::MsgType::INFO, "Main", "Main", __FILE__, __LINE__, "Main Started");
	DebugLogger::getInstance().log(DebugLogger::MsgType::FATAL_ERROR, "Main", "Main", __FILE__, __LINE__, "Test of Error");
    ogl->init();
	sound.init();
	sound.loadSound("$(ProjectDir)/../OriEngineResources/03-terran-1.mp3");
	sound.playSound();
	ogl->drawPrimative();
	while (clock.getDeltaTime() > 0.0) {
	//	std::cout << clock.getDeltaTime() << std::endl;
		sound.msystem->update();
	}
	return 0;

}