#include "AbstractEngine.h"
using namespace OriEngine;
AbstractEngine *AbstractEngine::appInstance = nullptr;
AbstractEngine::AbstractEngine(){
	init();

}
AbstractEngine::~AbstractEngine(){
	cleanUp();
}
AbstractEngine* AbstractEngine::getInstance() {
	//DebugLogger::getInstance().log(DebugLogger::INFO, "AbstractEngine", "getInstance", __FILE__, __LINE__, "Engine Started");
	return appInstance;
}
void AbstractEngine::onCreate() {
	
}
	void AbstractEngine::init() {
		appInstance = this;
		Clock::init();
		lastFrameStartTime = Clock::getTime();
		lastFrameFinishTime = Clock::getTime();
		renderer = new OpenGlRenderer();
		renderer->init();
			
	}
void AbstractEngine::startRender(){
	double timeSinceLastFrame = 0.0;


		double now = Clock::getTime();
		timeSinceLastFrame = now - lastFrameStartTime;
		lastFrameStartTime = now;


	
		preRender(timeSinceLastFrame);
		
}
void AbstractEngine::preRender(double time) {

}
void AbstractEngine::render() const {
		
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
