#pragma once

class Collider;
class RigidBody;
class Transform;
class SpriteRenderer;

#include "Components/Collider.h"
#include "Components/Rigidbody.h"
#include "Components/Transform.h"
#include "Components/SpriteRenderer.h"
#include <string>

class Entity
{
public:
	Entity(std::string newIdentifier, Transform*, SpriteRenderer*, Collider*, RigidBody*);
	Transform* GetTransform();
	Collider* GetCollider();
	RigidBody* GetRigidBody();
	SpriteRenderer* GetSpriteRenderer();
	virtual void Create() { };
	virtual void Destroy() { };
	std::string GetIdentifier() const;
	void SetIdentifier(std::string newIdentifier);

private:
	std::string identifier;
	Transform* transform;
	Collider* collider;
	RigidBody* rigidBody;
	SpriteRenderer* spriteRenderer;
};