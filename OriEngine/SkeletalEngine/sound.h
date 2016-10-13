#ifndef SOUND_H
#define SOUND_H
#pragma once
#include <string>

#include <al.h>
#include <AL\alut.h>

namespace OriEngine {
	class WavFile {
	public: 
	};
	class Sound{
	public:
		Sound();
		~Sound();
		void loadSound(const std::string& fileName);
		void playSound();
		void init();
		void update();
		void genSoundBuffer();
		void bindBuffer();
		void setPosVelLoop();
		void setListenerOriPosVel();
		ALuint buffer,source;
		ALenum format;
		ALsizei size, freq;
		ALboolean loop;
		ALvoid* data;
		ALCdevice *device;
		ALCcontext *context;
		ALint state;
		FILE *f;
	};
}
#endif