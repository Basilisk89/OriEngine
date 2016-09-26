#ifndef SOUND_H
#define SOUND_H
#pragma once
#include <string>
#include "DebugLogger.h"
#include <FMOD Studio API Windows\api\lowlevel\inc\fmod.hpp>
#include "Vector.h"
namespace OriEngine {
	class Sound{
	public:
		Sound();
		~Sound();
		void loadSound(const std::string& fileName);
		void playSound();
		void init();
		void update();
		bool getChannelplaying();
		FMOD::Sound *currentsound = 0;
		int channelsplaying = 0;

		FMOD::System     *system;
		FMOD::Sound      *sound1;
		FMOD::Channel    *channel = 0;
		FMOD_RESULT       result;
		unsigned int      version;
		void             *extradriverdata = 0;
	};
}
#endif