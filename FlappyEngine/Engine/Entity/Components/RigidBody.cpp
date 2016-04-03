#include "Rigidbody.h"
#include "../../Physics/Physics.h"

RigidBody::RigidBody() {}

RigidBody::RigidBody(bool gravity)
{
	this->SetGravity(gravity);
}

void RigidBody::Update()
{
	
}

bool RigidBody::isGravityOn() const
{
	return this->GravityOn;
}

void RigidBody::SetGravity(bool arg)
{
	this->GravityOn = arg;
}


void RigidBody::SetStatic(bool arg)
{
	this->isStatic = arg;
}

bool RigidBody::IsStatic() const
{
	return this->isStatic;
}

void RigidBody::AddForce(double velocityX, double velocityY)
{
	this->velocityX += velocityX;
	this->velocityY += velocityY;
}

void RigidBody::SetForce(double velocityX, double velocityY) 
{ 
	this->velocityX = velocityX; 
	this->velocityY = velocityY; 
}

void RigidBody::SetGravity(double gravity) 
{ 
	this->gravityForce = gravity;
}

double RigidBody::GetGravity() const 
{ 
	return this->gravityForce; 
}

double RigidBody::GetVelocityX() const
{
	return this->velocityX;
}

double RigidBody::GetVelocityY() const
{
	return this->velocityY;
}

void RigidBody::GetVelocityX(double velocity)
{
	this->velocityX = velocity;
}

void RigidBody::GetVelocityY(double velocity)
{
	this->velocityY = velocity;
}