#include "SoundManager.h"

using namespace OriEngine;

SoundManager::SoundManager(){
	
}
SoundManager::~SoundManager(){
}
void SoundManager::loadSoundbyIndex(char *filename, int index) {
	sounds.at(index).loadSound(filename);
}
void SoundManager::playSoundbyIndex(int index) {
	sounds.at(index).playSound();
}
void SoundManager::stopSoundbyIndex(int index) {

}
void SoundManager::updateSound(int index) {
	sounds.at(index).update();
}
void init() {
	
}