#include "Camera.h"
using namespace OriEngine;
Camera* Camera::instance = NULL;

void Camera::getStack() {}
Camera* Camera::getInstance() {
	if (instance == nullptr) 
		instance = new Camera();
	return instance;
}
Camera::Camera():aspectRatio(0.0f),mngr(StackMngr::getInstance()){
}
Camera::~Camera() {   }

Matrix Camera::NormalizedDeviceCoord(int w, int h) {
	Matrix ndc = MMath::viewportNDC(w, h);
	return ndc;
}
Matrix Camera::ScreenToWorld(Matrix ndc, float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
	Matrix othro = MMath::orthographic(minX, maxX, minY, maxY, minZ, maxZ);
	Matrix projection = othro * ndc;
	return projection;
}

void Camera::viewPort(int width, int height) {
	glViewport(0, 0, width, height);
	aspectRatio = (float)width / (float)height;
}

void Camera::push(){
	mngr->pushMatrix();
}

void Camera::pop(){
	mngr->popMatrix();
}

void Camera::scale(float x, float y, float z){
	mngr->scale(x, y, z);
}

void Camera::translate(float x, float y, float z){
	mngr->translate(x, y, z);
}

void Camera::rotate(float radians, float x, float y, float z){
	mngr->rotate(radians, x, y, z);
}

void Camera::loadPerspective(const float fovy, const float aspect, const float zNear, const float zFar,StdMatricies whichMatrix){
	mngr->matrixMode(whichMatrix);
	mngr->loadIdentity();
	mngr->perspective(fovy, aspect, zNear, zFar);
}

void Camera::loadLookAt(const Vec3 & eye, const Vec3 & at, const Vec3 & up,StdMatricies whichMatrix){
	mngr->matrixMode(whichMatrix);
	mngr->loadIdentity();
	mngr->lookAt(eye, at, up);
}

const float * Camera::getMatrixfv(StdMatricies whichMatrix){
	return mngr->getMatrixfv(whichMatrix);
}

const float * Camera::getMatrixfv(){
	return mngr->getMatrixfv();
}

void Camera::loadMatrix(const Matrix m){
	mngr->loadMatrix(m);
}

void Camera::multMatrix(const Matrix m){
	mngr->multMatrix(m);
}

void Camera::matrixMode(StdMatricies whichMatrix){
	mngr->matrixMode(whichMatrix);
}

void Camera::loadIndentity(){
	mngr->loadIdentity();
}
