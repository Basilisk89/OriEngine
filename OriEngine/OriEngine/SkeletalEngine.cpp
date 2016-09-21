#pragma once
#include "AbstractEngine.h"
namespace OriEngine {
	class SkeletalEngine : public AbstractEngine {
		virtual void onCreate() {
			
		}
		void onClean() {
		}
		virtual void preRender(double time) {
		}
		virtual void postRender() {
		}
	    void startRender() {
			
		}
		void render() {
		}
		void endRender() {
		}
	};
}