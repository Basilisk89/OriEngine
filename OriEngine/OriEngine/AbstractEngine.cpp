#include "AbstractEngine.h"
using namespace OriEngine;
std::unique_ptr<AbstractEngine*> appInstance = nullptr;
AbstractEngine::AbstractEngine(){
}
AbstractEngine::~AbstractEngine(){
}
void AbstractEngine::getInstance() {
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

void OriEngine::AbstractEngine::log(DebugLogger::MsgType msgType, int line, std::string file, std::string & msg){
//	DebugLogger::log(msg, "Engine", "Class", file,line, msg);
}
