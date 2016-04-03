#include "../ResourceManager/ResourceManager.h"

#pragma once
class Audio
{
public:
	Audio(const char* path) : path(path) {}

	~Audio()
	{
		ResourceManager* res = ResourceManager::GetInstance();
		res->Unload(path);
	}

	const char* GetPath() { return path; }

private:

	const char* path;
};


class Sound : public Audio 
{
public:

	Sound(const char* path) : Audio(path) 
	{
		ResourceManager* res = ResourceManager::GetInstance();
		res->LoadSound(path);
	}
};

class Music : public Audio
{
public:

	Music(const char* path) : Audio(path) 
	{
		ResourceManager* res = ResourceManager::GetInstance();
		res->LoadMusic(path);
	}
};

