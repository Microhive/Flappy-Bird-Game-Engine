#pragma once

#include "../Entity/Entity.h"
#include "../Input/Input.h"
#include <string>

class GUI : public Entity
{
public:
	GUI(std::string newIdentifier, Transform* transform, SpriteRenderer* spriteRenderer, Collider* collider, RigidBody* rigidBody);
	bool IsClicked();
private:
	Input* input;
};