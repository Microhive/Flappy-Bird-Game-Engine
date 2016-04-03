#pragma once
#include "../../Core/Box.h"
class Window
{
public:
	Window(const char* path, Box box);
	~Window();
	const char* GetPath() const;
	Box GetBox() const;

private:
	const char* path;
	Box box;
};

