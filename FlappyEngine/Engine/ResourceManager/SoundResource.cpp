#include "SoundResource.h"
#include <iostream>
#include <string>
#include "../Logger/Logger.h"


SoundResource::SoundResource(const char* path) : BaseResource(ResourceType::Sound), path(path)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
		std::string error = "Sound Error : ";
		error += Mix_GetError();
		std::cout << error << std::endl;
		Logger* log = Logger::GetInstance();
		log->Log(error, true);
	}
	this->chunk = Mix_LoadWAV(path);
}


SoundResource::~SoundResource()
{
	Mix_FreeChunk(chunk);
}

Mix_Chunk* SoundResource::GetChunk()
{
	return this->chunk;
}