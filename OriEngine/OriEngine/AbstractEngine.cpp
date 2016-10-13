#include "AbstractEngine.h"

#include <iostream>
using namespace OriEngine;
AbstractEngine *AbstractEngine::appInstance = nullptr;
AbstractEngine::AbstractEngine(){
	init();
}
AbstractEngine::~AbstractEngine(){
	cleanUp();
}
AbstractEngine* AbstractEngine::getInstance() {
	if (!appInstance) {
		return nullptr;
	}else {
		return appInstance;
	}
}
void AbstractEngine::onCreate() {

	
}
	void AbstractEngine::init() {
		appInstance = this;
		Clock::init();
		lastFrameStartTime = Clock::getTime();
		lastFrameFinishTime = Clock::getTime();
		
	

	
			
	}
void AbstractEngine::startRender(){
	double timeSinceLastFrame = 0.0;


		double now = Clock::getTime();
		timeSinceLastFrame = now - lastFrameStartTime;
		lastFrameStartTime = now;


	
		preRender(timeSinceLastFrame);
		
}
void AbstractEngine::preRender(double time) {
	std::cout << time << std::endl;
}
void AbstractEngine::render()  {
	renderer.drawPrimative();
}
void AbstractEngine::postRender()  {

}
void AbstractEngine::endRender(){
	double now = Clock::getTime();
	lastFrameFinishTime = now;
	double renderTime = now - lastFrameStartTime;
	frameAvgTotal += renderTime;
	frameAvgNumber++;
	if (frameAvgNumber >= frameAvgMaxNumber)
	{
		frameAvgTotal = renderTime;// frameAvgTotal / frameAvgNumber;
		frameAvgNumber = 1;
	}

}
void AbstractEngine::cleanUp()  {
	delete appInstance;
	appInstance = nullptr;
	
	
}

void OriEngine::AbstractEngine::handleEvents()
{
	
	
}
