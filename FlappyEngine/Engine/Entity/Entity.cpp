#include "Entity.h"

Entity::Entity(std::string newIdentifier, Transform* transform, SpriteRenderer* spriteRenderer, Collider* collider, RigidBody* rigidBody) : identifier(newIdentifier)
{
	// Save
	this->transform = transform;
	this->spriteRenderer = spriteRenderer;
	this->collider = collider;
	this->rigidBody = rigidBody;
	this->identifier = newIdentifier;

	// Reference
	this->transform->SetEntity(this);
	this->spriteRenderer->SetEntity(this);
	this->collider->SetEntity(this);
	this->rigidBody->SetEntity(this);
}

Transform* Entity::GetTransform()
{
	return this->transform;
}

Collider* Entity::GetCollider()
{
	return this->collider;
}

RigidBody* Entity::GetRigidBody()
{
	return this->rigidBody;
}

SpriteRenderer* Entity::GetSpriteRenderer()
{
	return this->spriteRenderer;
}

std::string Entity::GetIdentifier() const
{
	return this->identifier;
}

void Entity::SetIdentifier(std::string newIdentifier)
{
	this->identifier = newIdentifier;
}