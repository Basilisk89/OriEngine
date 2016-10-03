#pragma once
#include <vector>
#include "Sound.h"
namespace OriEngine {
	class SoundManager {
	public:
		SoundManager();
		~SoundManager();
		void loadSoundbyIndex(char *filename, int index);
		void playSoundbyIndex(int index);
		void stopSoundbyIndex(int index);
		void init();
		void updateSound(int index);
		std::vector<Sound> sounds;
		System system;
	};
}
