#pragma once
#include "Render_Interface.h"
#include "RenderBlackbox.h"
#include "Texture.h"
#include <iostream>

class Render
{
public:
	static Render* getInstance();
	void CleareScreen();
	void UpdateScreen();
	void DrawTextureToScreen(Texture* texture, Window* window, int x, int y, int w, int h, int xT, int yT, int wT, int hT, double angle);
private:
	Render();
	static Render* _Instance;
	Render_Interface* Blackbox;
};

