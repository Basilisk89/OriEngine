#pragma once
#include "AbstractEngine.h"
#include "OpenGlRenderer.h"
#include "MusicSystem.h"
using namespace OriEngine;
	long windowWidth = 1024;
	long windowHeight = 768;
	long windowBits = 32;
	bool fullscreen = false;
	AbstractEngine *Engine;
	HDC hDC;
	MusicSystem *musicSystem;

	class SkeletalEngine : public AbstractEngine
	{
	private:
		
		double lastFpsPrint = 0.0;

	public:
		SkeletalEngine()	{
		}


		virtual void postRender(){

		}

		virtual void initializeWindowingSystem()
		{
		}

		virtual void onCreate(){
		
		}

		virtual void preRender(double timeSinceLastFrame){
		
		}

	};

	int main(int argc, char **argv) {
		Engine = new SkeletalEngine();
		Engine->onCreate();
		musicSystem = new MusicSystem();
		musicSystem->createSounds("C:/03-terran-1.mp3", 1);
		
		
		musicSystem->playSounds(1);
			
		
		bool loop = true;
		while (loop) {
			
			AbstractEngine::getInstance()->postRender();
			AbstractEngine::getInstance()->handleEvents();
			musicSystem->updateSounds();
			AbstractEngine::getInstance()->endRender();
			
		}
		return 0;
	}