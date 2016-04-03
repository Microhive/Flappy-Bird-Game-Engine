#include "Audio.h"
#include "Audio_Interface.h"
//#include "Music.h"
#include "AudioBlackbox.h"

#pragma once
class AudioEngine
{

public:	
	static AudioEngine* GetInstance();
	void PlaySound(Sound* sound);
	void PlayMusic();
	void StopMusic();
	void SetMusic(Music* music);

private:
	AudioEngine();
	static AudioEngine* pAudioEngine;

	~AudioEngine();

	Music* music;
	Audio_Interface* Blackbox;

};

