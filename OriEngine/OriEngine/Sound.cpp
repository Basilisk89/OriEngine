#include "Sound.h"


using namespace OriEngine;
Sound::Sound(){
}
Sound::~Sound(){
}
void Sound::loadSound(const std::string& filename) {
	msystem->createSound(filename.c_str(),FMOD_LOOP_NORMAL, NULL, &sound);
}
void Sound::init() {
	if (FMOD::System_Create(&msystem) != FMOD_OK) {
	}
	else {
	
		
		msystem->setOutput(FMOD_OUTPUTTYPE::FMOD_OUTPUTTYPE_DSOUND);

		
		//msystem->setSoftwareFormat(48000, speakermode,  FMOD_DSP_RESAMPLER_LINEAR);
		msystem->init(36, FMOD_INIT_NORMAL, 0);
	
	}
	}
void Sound::playSound( ) {
	sound->setMode(FMOD_LOOP_OFF);
	msystem->playSound(sound, NULL, false, 0);
	
}