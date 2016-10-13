#pragma once
#include "Sound.h"
#include <vector>
#include <FMOD Studio API Windows\api\lowlevel\inc\fmod.hpp>
namespace OriEngine {
	class MusicSystem {
	public:
		MusicSystem();
		~MusicSystem();
	
		Sound *sounds;
		FMOD::System* soundSystem;
		bool createSounds(char *fileName, int index);
		bool playSounds(int index);
		bool updateSounds();
		bool stopSounds();
		FMOD::Channel *channel = 0;
	};
}
