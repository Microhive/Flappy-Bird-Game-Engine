#pragma once
#include "BaseResource.h"
#include "SDL_mixer.h"

class MusicResource : public BaseResource
{

private:

	Mix_Music* music;
	const char* path;

public:

	MusicResource(const char*);
	~MusicResource();

	Mix_Music* GetMusic();

};

