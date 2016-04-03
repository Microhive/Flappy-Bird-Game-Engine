#pragma once
#include "BaseResource.h"
#include "SDL_image.h"
#include "SDL.h"

class TextureResource : public BaseResource
{
private:
	SDL_Window* window;
	SDL_Texture* image;
	SDL_Renderer* renderer;
	const char* path;
public:
	TextureResource(const char*/*, SDL_Renderer**/);
	~TextureResource();

	SDL_Texture* GetTexture();
	/*SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();*/
};

