#pragma once
//#include "Sound.h"
//#include "Music.h"
#include "Audio.h"

class Audio_Interface
{
public:


	virtual void Update() = 0;
	virtual void PlaySound(Sound* sound) = 0;
	virtual void PlayMusic(Music* music) = 0;
	virtual void StopSound(Sound* sound) = 0;
	virtual void StopMusic(Music* music) = 0;

};

