#include "Sound.h"


using namespace OriEngine;
Sound::Sound(){
	init();
}
Sound::~Sound(){
}
void Sound::loadSound(const std::string& filename) {
	
	result = system->createSound("C:/03-terran-1.mp3", FMOD_DEFAULT, 0, &sound1);
	if (result != FMOD_OK) {}

}
void Sound::init() {
	result = FMOD::System_Create(&system);
	if (result != FMOD_OK)
	
	result = system->getVersion(&version);

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);






	result = sound1->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */

	
	}
bool Sound::getChannelplaying() {
	if (channel) {

		system->getChannelsPlaying(&channelsplaying, 0);
		return true;
	}
	else {
		return false;
	}
}
void Sound::playSound( ) {
	result = system->playSound(sound1, 0, false, &channel);
}
void Sound::update() {
	result = system->update();
	getChannelplaying();
}

