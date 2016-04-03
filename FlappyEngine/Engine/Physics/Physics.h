#pragma once

#include "../Entity/Components/Rigidbody.h"
#include <queue>

class Physics
{
public:
	static Physics* GetInstance();
	void Update();
	void AddToQueue(RigidBody* rigidBody);

private:
	void ApplyPhysics(RigidBody* object);
	std::queue<RigidBody*> queue;
	static Physics* _Instance;
};