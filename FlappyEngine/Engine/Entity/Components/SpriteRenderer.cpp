#pragma once

#include "SpriteRenderer.h"
#include "../../Renderer/Render.h"

void SpriteRenderer::SetWidth(int width)
{
	this->width = width;
}
void SpriteRenderer::SetHeight(int height)
{
	this->height = height;
}
int SpriteRenderer::GetWidth() const
{
	return this->width;
}
int SpriteRenderer::GetHeight() const
{
	return this->height;
}
Box SpriteRenderer::GetBox() const
{
	return this->imageCrop;
}
void SpriteRenderer::RenderOnScreen()
{
	Render* render = Render::getInstance();
	int drawX = static_cast<int>(entity->GetTransform()->GetPoint().GetX()) - (width / 2);
	int drawY = static_cast<int>(window->GetBox().GetHeight()) - (static_cast<int>(entity->GetTransform()->GetPoint().GetY()) + (height / 2));
	render->DrawTextureToScreen(image, window, drawX, drawY, width, height, imageCrop.GetX(), imageCrop.GetY(), imageCrop.GetWidth(), imageCrop.GetHeight(), entity->GetTransform()->GetRotation());
}