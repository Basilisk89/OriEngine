#include "MusicSystem.h"


using namespace OriEngine;

OriEngine::MusicSystem::MusicSystem(){
	FMOD_RESULT result;
	sounds = new Sound();
	result = FMOD::System_Create(&soundSystem);
	if (result != FMOD_OK) {
	
	}else {
		result = soundSystem->init(32, FMOD_INIT_NORMAL, 0);
	}
	
}

OriEngine::MusicSystem::~MusicSystem(){
}
bool MusicSystem::createSounds(char *fileName, int index) {
	FMOD_RESULT result = soundSystem->createSound(fileName, FMOD_DEFAULT, 0, &sounds->sound);
	if (result != FMOD_OK) {	return false;}
	else {	return true;}
}
bool MusicSystem::playSounds(int index) {
	FMOD_RESULT result = soundSystem->playSound(sounds->sound, 0, false, &channel);
	if (result != FMOD_OK) {return false;}
	else { return true; }
}
bool MusicSystem::updateSounds() {
	FMOD_RESULT result = soundSystem->update();
	return true;
}