#ifndef ABSTRACTENGINE_H
#define ABSTRACTENGINE_H
#pragma once
#include <memory>
#include <Windows.h>
#include "MusicSystem.h"
#include "DebugLogger.h"
#include "Clock.h"
#include "OpenGlRenderer.h"
#include "ShaderManager.h"
namespace OriEngine {
	class AbstractEngine {
	public:
		Shader *shader;
		OpenGlRenderer renderer;
		MusicSystem musicSystem;
		static AbstractEngine* getInstance();
	    virtual void onCreate() = 0;
		void init();
	    virtual void preRender(double time) ;
	    virtual void postRender() ;
		void endRender();
		void startRender();
	     void render();
		 void cleanUp() ;
		 void handleEvents();

		 bool stillRendering() {
			 return true;
		 }
		 std::string getName() {
			 return ApplicationName;
		 }
		~AbstractEngine();
		AbstractEngine();
		static void log(DebugLogger::MsgType msgType, std::string method, std::string _class, std::string file, int line, std::string msg) {
			DebugLogger::getInstance().log(msgType, method, _class, file, line, msg);
		}
	private:
		std::string ApplicationName = "Ori Engine";
		static AbstractEngine*	appInstance;
		double						gameStartTime;
		/** The time the last frame rendering was complete */
		double						lastFrameFinishTime;
		/** The time the last frame started rendering */
		double						lastFrameStartTime;
		/** An accumulator used to add time for last few avg frames to calc frame rate */
		double						frameAvgTotal;
		/** A count of the number of frames in the current total */
		int							frameAvgNumber;
		/** The maximum number of frames used to calculate the frame rate */
		int							frameAvgMaxNumber;
		
	protected:
	};
}
#endif 
