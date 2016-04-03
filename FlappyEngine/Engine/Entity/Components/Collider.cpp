#include "Collider.h"
#include <iostream>

void Collider::Update()
{
	this->otherEntities.clear();
}

double Collider::GetTop() const
{
	double val = entity->GetTransform()->GetPoint().GetY() + (height / 2);
	return val;
}

double Collider::GetLeft() const
{
	double val = entity->GetTransform()->GetPoint().GetX() - (width / 2);
	return val;
}

double Collider::GetRight() const
{
	double val = entity->GetTransform()->GetPoint().GetX() + (width / 2);
	return val;
}

double Collider::GetBottom() const
{
	double val = entity->GetTransform()->GetPoint().GetY() - (height / 2);
	return val;
}

double Collider::GetWidth() const
{
	return this->width;
}

double Collider::GetHeight() const
{
	return this->height;
}

void Collider::SetOtherCollidingEntity(Collider* otherCollider)
{
	otherEntities.push_back(otherCollider->GetEntity());
}

Entity* Collider::IsColliding(std::string identifier)
{
	// If object is set, then returns other colliding entity.
	// Otherwise nullptr
	for each (auto var in otherEntities)
	{
		if (var->GetIdentifier() == identifier)
		{
			return var;
		}
	}
	return nullptr;
}

bool sortCollidersByZValue(Entity* a, Entity* b)
{
	return (a->GetTransform()->GetPoint().GetZ() < b->GetTransform()->GetPoint().GetZ());
}