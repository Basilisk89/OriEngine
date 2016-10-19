#include "ImgManager.h"


using namespace OriEngine;
ImgManager* ImgManager::imgManagerInstance = nullptr;
std::map<std::string, Image*> ImgManager::imgMap;
ImgManager::ImgManager(){
}

ImgManager::~ImgManager(){
}

ImgManager* ImgManager::getinstance() {
	if (!imgManagerInstance) {
		imgManagerInstance = new ImgManager();
	}else {
		return imgManagerInstance;
	}
}
void ImgManager::storeImage(Image* image, std::string name) {
	if (!image)
		imgMap[name] = image;
}
Image* ImgManager::getImage(std::string name) {
	return imgMap.at(name);
}
void ImgManager::deleteImage(std::string name) {
	if (imgMap.at(name)) {
		imgMap[name] = nullptr;
		delete imgMap[name];
	}else {
	
	}
}
void ImgManager::clear() {
	imgMap.clear();
}