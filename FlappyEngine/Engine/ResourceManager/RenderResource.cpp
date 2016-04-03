#include "RenderResource.h"


RenderResource::RenderResource(const char* path, int x, int y, int w, int h) : BaseResource(ResourceType::Render), path(path)
{
	window = SDL_CreateWindow(path, x, y, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


RenderResource::~RenderResource()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

const char* RenderResource::getPath()
{
	return this->path;
}

SDL_Renderer* RenderResource::GetRenderer()
{
	return this->renderer;
}

SDL_Window* RenderResource::GetWindow()
{
	return this->window;
}
