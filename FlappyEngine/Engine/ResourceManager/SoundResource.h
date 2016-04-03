#pragma once
#include "BaseResource.h"
#include "SDL_mixer.h"

class SoundResource : public BaseResource
{

private:

	Mix_Chunk* chunk;
	const char* path;

public:

	SoundResource(const char*);
	~SoundResource();

	Mix_Chunk* GetChunk();

};

