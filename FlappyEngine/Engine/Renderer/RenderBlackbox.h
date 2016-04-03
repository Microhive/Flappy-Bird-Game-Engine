#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Render_Interface.h"

class RenderBlackbox : public Render_Interface
{
public:
	RenderBlackbox();
	~RenderBlackbox();

	void ClearScreen();
	void UpdateScreen();
	void DrawTextureToScreen(Texture* texture, Window* window, int x, int y, int w, int h, int xT, int yT, int wT, int hT, double angle);

private:
	

	SDL_Window* window;
	SDL_Texture* image;
	SDL_Rect rect;
	SDL_Rect textureCrop;

	SDL_Renderer* renderer;
	SDL_Point* center;
	SDL_RendererFlip flip;
};

