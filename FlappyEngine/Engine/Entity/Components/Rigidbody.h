#pragma once

class Entity;

#include "../Entity.h"

class RigidBody
{
public:
	RigidBody();
	RigidBody(bool gravity);

	void SetEntity(Entity* entity) { this->entity = entity; }
	Entity* GetEntity() { return this->entity; }

	void Update();
	
	void SetStatic(bool arg);
	void AddForce(double velocityX, double velocityY);
	bool isGravityOn() const;
	void SetGravity(bool arg);
	
	void SetForce(double velocityX, double velocityY);
	void SetGravity(double gravity);

	double GetGravity() const;
	bool IsStatic() const;

	double GetVelocityX() const;
	double GetVelocityY() const;

	void GetVelocityX(double velocity);
	void GetVelocityY(double velocity);

private:
	Entity* entity;
	double velocityX = 0;
	double velocityY = 0;
	double gravityForce = 0.2;
	bool isStatic = false;
	bool GravityOn = true;
	/*
	double Mass = 0;
	double LinearDrag = 0;
	double AngularDrag = 0
	*/
};