#include "HdApp.h"
using namespace OriEngine;
std::unique_ptr<HdApp> appInstance = nullptr;
HdApp::HdApp(){
}
HdApp::~HdApp(){
}
void HdApp::getInstance() {
}
void HdApp::onCreate() const{
}
void HdApp::preRender(double time) {
}
void HdApp::render() const {
}
void HdApp::postRender()  {
}
void HdApp::cleanUp() const {
}