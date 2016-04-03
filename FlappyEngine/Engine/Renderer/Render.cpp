#include "Render.h"

using namespace std;

Render* Render::_Instance = nullptr;

Render::Render()
{
	this->Blackbox = new RenderBlackbox();
}
Render* Render::getInstance()
{
	if (!_Instance)
		_Instance = new Render();

	return _Instance;
}
void Render::CleareScreen()
{
	this->Blackbox->ClearScreen();
}
void Render::UpdateScreen()
{
	this->Blackbox->UpdateScreen();
}
void Render::DrawTextureToScreen(Texture* texture, Window* window, int x, int y, int w, int h, int xT, int yT, int wT, int hT, double angle)
{
	this->Blackbox->DrawTextureToScreen(texture, window, x, y, w, h, xT, yT, wT, hT, angle);
}
