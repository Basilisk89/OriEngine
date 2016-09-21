#ifndef ABSTRACTENGINE_H
#define ABSTRACTENGINE_H
#pragma once
#include <memory>
#include "DebugLogger.h"
#include "Clock.h"
#include "OpenGlRenderer.h"
namespace OriEngine {
	class AbstractEngine {
	public:
		
		AbstractEngine* getInstance();
	    virtual void onCreate() const;
	    virtual void preRender(double time) ;
	    virtual void postRender() ;
		void endRender();
		void startRender();
	     void render() const;
		 void cleanUp() const;
		~AbstractEngine();
		AbstractEngine();
		static void log(DebugLogger::MsgType msgType, std::string method, std::string _class, std::string file, int line, std::string msg) {
			DebugLogger::getInstance().log(msgType, method, _class, file, line, msg);
		}
	private:
		std::string ApplicationName = "Ori Engine";
		std::unique_ptr<AbstractEngine>*	appInstance;
	protected:
	};
}
#endif 
