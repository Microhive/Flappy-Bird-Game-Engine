#pragma once
#include <iostream>
#include "Texture.h"
#include "Window.h"

class Render_Interface
{
public:
	virtual void ClearScreen() = 0;
	virtual void UpdateScreen() = 0;
	virtual void DrawTextureToScreen(Texture* texture, Window* window, int x, int y, int w, int h, int xT, int yT, int wT, int hT, double angle) = 0;
};