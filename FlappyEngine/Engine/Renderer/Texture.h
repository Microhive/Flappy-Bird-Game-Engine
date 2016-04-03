#pragma once
#include "SDL_image.h"
class Texture
{
public:
	Texture(const char* path/*, SDL_Renderer* renderer*/);
	~Texture();
	const char* GetPath();

private:
	const char* path;
};

