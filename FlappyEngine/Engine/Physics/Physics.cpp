#include "Physics.h"

Physics* Physics::_Instance = nullptr;

Physics* Physics::GetInstance()
{
	if (!_Instance)
		_Instance = new Physics();

	return _Instance;
}

void Physics::Update()
{
	while (!queue.empty())
	{
		ApplyPhysics(queue.front());
		queue.pop();
	}
}

void Physics::AddToQueue(RigidBody* rigidBody)
{
	queue.push(rigidBody);
}

void Physics::ApplyPhysics(RigidBody* object)
{
	if (!object->IsStatic())
	{
		if (object->isGravityOn())
		{
			object->AddForce(0,-(object->GetGravity()));
		}

		// http://www.rodedev.com/tutorials/gamephysics/

		// if object is intersecting any other object, don't add acceleration
		/*if (movingObject.y - velocity_y > ground.y)
		{
		movingObject.y = movingObject.y + velocity_y;
		}*/

		object->GetEntity()->GetTransform()->MoveRelative(
			object->GetVelocityX(),
			object->GetVelocityY(),
			0);
	}
}