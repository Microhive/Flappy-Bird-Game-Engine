#pragma once

class Entity;

#include "../Entity.h"
#include <vector>

class Collider
{
public:
	Collider(double width, double height) : width(width), height(height) {};
	void SetEntity(Entity* entity) { this->entity = entity; }
	Entity* GetEntity() { return this->entity; }
	void Update();
	Entity* IsColliding(std::string identifier);
	void SetOtherCollidingEntity(Collider* otherCollider);

	double GetTop() const;
	double GetRight() const;
	double GetBottom() const;
	double GetLeft() const;
	double GetWidth() const;
	double GetHeight() const;

	bool comparePtrToNode(Collider* a, Collider* b);
	//bool operator < (Collider& collider);
private:
	Entity* entity;
	std::vector<Entity*> otherEntities;
	double width;
	double height;
};

bool sortCollidersByZValue(Entity* a, Entity* b);