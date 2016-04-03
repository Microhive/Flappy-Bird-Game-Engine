#pragma once

class Entity;

#include "../Entity.h"
#include "../../Renderer/Texture.h"
#include "../../../Core/Box.h"
#include "../../Renderer/Window.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Texture* image, Window* window, Box imageCrop, int width, int height) : image(image), window(window), imageCrop(imageCrop), width(width), height(height) {};
	void SetEntity(Entity* entity) { this->entity = entity; }
	void SetWidth(int width);
	void SetHeight(int height);
	int GetWidth() const;
	int GetHeight() const;
	Box GetBox() const;
	void RenderOnScreen();
private:
	Entity* entity;
	Texture* image;
	Window* window;
	Box imageCrop;
	int width;
	int height;
};