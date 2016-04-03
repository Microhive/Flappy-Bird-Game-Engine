#pragma once
#include "BaseResource.h"
#include "SDL_image.h"

class RenderResource : public BaseResource
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	const char* path;
public:
	RenderResource(const char*, int x, int y, int w, int h);
	~RenderResource();

	const char* getPath();
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
};

