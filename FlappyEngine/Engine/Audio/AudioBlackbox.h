#pragma once
#include "SDL_mixer.h"
#include "Audio_Interface.h"

class AudioBlackbox : public Audio_Interface
{
private:


public:

	AudioBlackbox();
	~AudioBlackbox();

	void Update();
	void PlaySound(Sound* sound);
	void PlayMusic(Music* music);
	void StopSound(Sound* sound);
	void StopMusic(Music* music);
	int GetRandomInt();
};

