#include "RenderBlackbox.h"
#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/TextureResource.h"
#include "../ResourceManager/RenderResource.h"

RenderBlackbox::RenderBlackbox(/*SDL_Renderer* passed_renderer, */)
{
	SDL_Init(SDL_INIT_VIDEO);

	center = nullptr;
	flip = SDL_FLIP_NONE;
}
RenderBlackbox::~RenderBlackbox()
{
}
void RenderBlackbox::ClearScreen()
{
	SDL_RenderClear(renderer);
}
void RenderBlackbox::UpdateScreen()
{
	SDL_RenderPresent(renderer);
}
void RenderBlackbox::DrawTextureToScreen(Texture* texture, Window* _window, int x, int y, int w, int h, int xT, int yT, int wT, int hT, double angle)
{
	ResourceManager* res = ResourceManager::GetInstance();
	
	window = static_cast<RenderResource*>(res->GetResource(_window->GetPath()))->GetWindow();
	renderer = static_cast<RenderResource*>(res->GetResource(_window->GetPath()))->GetRenderer();
	image = static_cast<TextureResource*>(res->GetResource(texture->GetPath()))->GetTexture();

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	textureCrop.x = xT;
	textureCrop.y = yT;
	textureCrop.h = hT;
	textureCrop.w = wT;

	//center->x = x + (w / 2);
	//center->y = y + (h / 2);

 	SDL_RenderCopyEx(renderer, image, &textureCrop, &rect, angle, center, flip);
}
