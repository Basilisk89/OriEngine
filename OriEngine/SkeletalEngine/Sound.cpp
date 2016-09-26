#include "Sound.h"


using namespace OriEngine;
Sound::Sound(){
	init();
}
Sound::~Sound(){
}
void Sound::loadSound(const std::string& filename) {
	
	buffer = alutCreateBufferFromFile(filename.c_str());
	alBufferData(buffer, format, data, size, freq);


}
void Sound::init() {
	alutInit(NULL, NULL);
	}
void Sound::playSound( ) {
	alSourcePlay(source);
}
void Sound::update() {

}

void OriEngine::Sound::genSoundBuffer(){
	alGenBuffers(1, &buffer);
	
}
void OriEngine::Sound::bindBuffer()
{
	alGenSources(1, &source);
	alSourcei(source, AL_BUFFER, buffer);
}
void OriEngine::Sound::setPosVelLoop()
{
	alSourcef(source, AL_PITCH, 1);
	alSourcef(source, AL_GAIN, 1);
	alSource3f(source, AL_POSITION, 0, 0, 0);
	alSourcei(source, AL_LOOPING, false);
	alSource3f(source, AL_VELOCITY, 0,0,0);
}

void OriEngine::Sound::setListenerOriPosVel()
{
	
	alListener3f(AL_POSITION, 0,0,0);
	alListenerfv(AL_ORIENTATION, 0);
}
