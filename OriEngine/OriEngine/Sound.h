#ifndef SOUND_H
#define SOUND_H
#pragma once
#include <string>
#include "DebugLogger.h"
#include <FMOD Studio API Windows\api\lowlevel\inc\fmod.hpp>
#include <FMOD Studio API Windows\api\lowlevel\inc\fmod.h>
#include "Vector.h"
namespace OriEngine {
	class Sound{
	public:
		Sound();
		~Sound();
		FMOD::Sound      *sound;
		FMOD::Sound* getSound() {
			return sound;
		}
		void setSound(FMOD::Sound *s) {
			sound = s;
		}
	private:
	
	};
	
}
#endif