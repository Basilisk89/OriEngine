#ifndef HDAPP_H
#define HDAPP_H
#pragma once
#include <memory>
#include "DebugLogger.h"
#include "Clock.h"
namespace OriEngine {
	class AbstractEngine {
	public:
		void getInstance();
	    virtual void onCreate() const;
		void startRender();
	    virtual void preRender(double time) ;
	    virtual void postRender() ;
		void endRender();
	     void render() const;
		 void cleanUp() const;
		 static void log(DebugLogger::MsgType msgType,int line, std::string, std::string& msg);
		~AbstractEngine();
		AbstractEngine();
	private:
		std::string ApplicationName = "Ori Engine";
		std::unique_ptr<AbstractEngine*>	appInstance;
	protected:
	};
}
#endif 
