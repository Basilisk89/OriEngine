#ifndef SOUND_H
#define SOUND_H
#include <string>
#include <FMOD Studio API Windows\api\lowlevel\inc\fmod.hpp>
#include <FMOD Studio API Windows\api\lowlevel\inc\fmod_errors.h>
#include <FMOD Studio API Windows\\api\lowlevel\inc\fmod.h>
namespace OriEngine {
	class Sound{
	public:
		Sound();
		~Sound();
		void loadSound(const std::string& fileName);
		void playSound();
		void init();
		FMOD::Sound* sound;
		FMOD::System* msystem;
		FMOD_SPEAKERMODE speakermode;
	};
}
#endif