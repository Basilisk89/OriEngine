#include "AbstractEngine.h"
using namespace OriEngine;
std::unique_ptr<AbstractEngine> *appInstance = nullptr;
AbstractEngine::AbstractEngine(){
}
AbstractEngine::~AbstractEngine(){
	cleanUp();
}
AbstractEngine* AbstractEngine::getInstance() {
	if (appInstance->get() == nullptr) {
		appInstance->reset(new AbstractEngine());
	}
	return appInstance->get();
}
void AbstractEngine::onCreate() const{
}
void AbstractEngine::startRender(){
}
void AbstractEngine::preRender(double time) {
}
void AbstractEngine::render() const {
}
void AbstractEngine::postRender()  {
}
void AbstractEngine::endRender(){
}
void AbstractEngine::cleanUp() const {
}
