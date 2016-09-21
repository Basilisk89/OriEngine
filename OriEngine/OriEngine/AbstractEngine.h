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
		void startRender();
	    virtual void preRender(double time) ;
	    virtual void postRender() ;
		void endRender();
	     void render() const;
		 void cleanUp() const;
		~AbstractEngine();
		AbstractEngine();
	private:
		std::string ApplicationName = "Ori Engine";
		std::unique_ptr<AbstractEngine>*	appInstance;
	protected:
	};
}
#endif 
