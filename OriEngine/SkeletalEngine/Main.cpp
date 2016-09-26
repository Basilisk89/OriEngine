#include "fmod.hpp"


int main(int args, char** argv)
{
	FMOD::System     *system;
	FMOD::Sound      *sound1, *sound2, *sound3;
	FMOD::Channel    *channel = 0;
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata = 0;


	/*
	Create a System object and initialize
	*/
	result = FMOD::System_Create(&system);
	if (result != FMOD_OK)
		return 0;
	result = system->getVersion(&version);

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);


	result = system->createSound("C:/03-terran-1.mp3", FMOD_DEFAULT, 0, &sound1);
	if (result != FMOD_OK)
		
		return 0;

	result = sound1->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
	bool loop = false;
	result = system->playSound(sound1, 0, false, &channel);
	/*
	Main loop
	*/
	do
	{



		


		
			unsigned int ms = 0;
			unsigned int lenms = 0;
			bool         playing = 0;
			bool         paused = 0;
			int          channelsplaying = 0;

			if (channel)
			{
			



			}


		} while (!loop);

		/*
		Shut down
		*/


		return 0;
	}
