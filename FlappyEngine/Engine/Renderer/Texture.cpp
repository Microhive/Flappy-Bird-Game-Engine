#include "Texture.h"
#include "../ResourceManager/ResourceManager.h"


Texture::Texture(const char* path/*, SDL_Renderer* renderer*/) : path(path)
{
	ResourceManager* res = ResourceManager::GetInstance();
	res->LoadTexture(path/*, renderer*/);
}

Texture::~Texture()
{
	ResourceManager* res = ResourceManager::GetInstance();
	res->Unload(path);
}

const char* Texture::GetPath()
{
	return path;
}
