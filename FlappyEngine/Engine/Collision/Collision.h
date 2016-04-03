#pragma once

#include "../Entity/Components/Collider.h"
#include <list>

class Collision
{
public:
	static Collision* GetInstance();
	void AddToCollisionCheckList(Collider* collider);
	void PerformCollisonCheck();
private:
	void ApplyCollisionChecksFor(Collider* collider);
	bool CheckCollisioneBetween(Collider* a, Collider* b);
	std::list<Collider*> list;
	static Collision* _Instance;
};