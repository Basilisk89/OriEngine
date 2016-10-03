#include "AbstractEngine.h"
#include "Window.h"
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
	
		window.SetWindowSize(800, 600);
		bool winError = window.Initialize();
		if (winError != true) {
		
		}else {
		
		}
	
			
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
	window.Shutdown();
	
}

void OriEngine::AbstractEngine::handleEvents()
{
	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		switch (e.type) {
		case SDL_EventType::SDL_QUIT:
			exit(1);
			return;
		case SDL_EventType::SDL_MOUSEBUTTONDOWN:


		case SDL_EventType::SDL_MOUSEBUTTONUP:


		case SDL_EventType::SDL_MOUSEMOTION:


			break;
		default:
			break;
		}
	}
}
