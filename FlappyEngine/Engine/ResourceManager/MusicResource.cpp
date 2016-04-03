#include "MusicResource.h"
#include <iostream>
#include <string>
#include "../Logger/Logger.h"


MusicResource::MusicResource(const char* path) : BaseResource(ResourceType::Music), path(path)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) < 0) {
		std::string error = "Music Error : ";
		error += Mix_GetError();
		std::cout << error << std::endl;
		Logger* log = Logger::GetInstance();
		log->Log(error, true);
	}
	this->music = Mix_LoadMUS(path);
}


MusicResource::~MusicResource()
{
	Mix_FreeMusic(music);
}

Mix_Music* MusicResource::GetMusic()
{
	return this->music;
}