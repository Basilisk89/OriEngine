#ifndef HDAPP_H
#define HDAPP_H
#pragma once
#include <memory>
#include "DebugLogger.h"
#include "Clock.h"
namespace OriEngine {
	class HdApp {
	public:
		void getInstance();
		void onCreate() const;
		void preRender(double time) ;
		void postRender() ;
		void render() const;
		void cleanUp() const;
		~HdApp();
	private:
		HdApp();
		std::unique_ptr<HdApp>	appInstance;
	protected:
	};
}
#endif 
