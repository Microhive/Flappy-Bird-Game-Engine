#include "TextureResource.h"
#include "ResourceManager.h"
#include "RenderResource.h"
#include <iostream>



TextureResource::TextureResource(const char* path/*, SDL_Renderer* renderer*/) : BaseResource(ResourceType::Texture), path(path)
{
	ResourceManager* res = ResourceManager::GetInstance();
	
	//window = static_cast<TextureResource*>(res->GetResource("Window1"))->GetWindow();
	renderer = static_cast<RenderResource*>(res->GetResource("Flappy Bird"))->GetRenderer();

	this->image = IMG_LoadTexture(renderer, path);
}


TextureResource::~TextureResource()
{
	SDL_DestroyTexture(image);
}

SDL_Texture* TextureResource::GetTexture()
{
	return this->image;
}

//SDL_Window* TextureResource::GetWindow()
//{
//	return this->window;
//}
//
//SDL_Renderer* TextureResource::GetRenderer()
//{
//	return this->renderer;
//}