#include "Window.h"
#include "../ResourceManager/ResourceManager.h"


Window::Window(const char* path, Box box): path(path), box(box)
{
	ResourceManager* res = ResourceManager::GetInstance();
	res->LoadRender(path, box.GetX(), box.GetY(), box.GetWidth(), box.GetHeight());
}


Window::~Window()
{
	ResourceManager* res = ResourceManager::GetInstance();
	res->Unload(path);
}

const char* Window::GetPath() const
{
	return this->path;
}

Box Window::GetBox() const
{
	return this->box;
}