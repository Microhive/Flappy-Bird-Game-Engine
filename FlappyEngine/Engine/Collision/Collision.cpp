#include "Collision.h"
#include <cstdlib>

Collision* Collision::_Instance = nullptr;

Collision* Collision::GetInstance()
{
	if (!_Instance)
		_Instance = new Collision();

	return _Instance;
}

void Collision::AddToCollisionCheckList(Collider* collider)
{
	list.push_back(collider);
}

void Collision::PerformCollisonCheck()
{
	std::list<Collider*>::iterator it = list.begin();
	while (it != list.end())
	{
		std::list<Collider*>::iterator it2 = it;
		it2++;
		while (it2 != list.end())
		{
			Collider* collider = *it;
			Collider* OtherCollider = *it2;
			CheckCollisioneBetween(collider, OtherCollider);
			it2++;
		}
		it++;
	}
	list.clear();
}

void Collision::ApplyCollisionChecksFor(Collider* collider)
{
	for (auto it = list.begin(); it != list.end(); ++it)
	{
		Collider* OtherCollider = (*it);
		CheckCollisioneBetween(collider, OtherCollider);
	}
}

bool Collision::CheckCollisioneBetween(Collider* a, Collider* b)
{
	//Calculate the sides of rect A 
	double leftA = b->GetLeft();
	double rightA = b->GetRight();
	double topA = b->GetTop();
	double bottomA = b->GetBottom();
	
	//Calculate the sides of rect B 
	double leftB = a->GetLeft();
	double rightB = a->GetRight();
	double topB = a->GetTop();
	double bottomB = a->GetBottom();

	if (rightA < leftB || leftA > rightB) 
		return false;
	if (topA < bottomB || bottomA > topB) 
		return false;

	//If none of the sides from A are outside B 
	a->SetOtherCollidingEntity(b);
	b->SetOtherCollidingEntity(a);
	return true; 
}
