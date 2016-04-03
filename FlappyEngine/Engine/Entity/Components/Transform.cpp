#pragma once

#include "Transform.h"
#include <string>

void Transform::MoveRelative(double X, double Y, double Z = 0)
{
	point.SetX(point.GetX() + X);
	point.SetY(point.GetY() + Y);
	point.SetZ(point.GetZ() + Z);
}

void Transform::MoveToPoint(double X, double Y, double Z = 0)
{
	point.SetX(X);
	point.SetY(Y);
	point.SetZ(Z);
}

void Transform::MoveToPoint(Point point)
{
	MoveToPoint(point.GetX(), point.GetY(), point.GetZ());
}

void Transform::RotateRelatively(double rotate)
{
	//double mod = 360;
	double change = (rotation + rotate);
	//rotation = std::modf(change, &mod);
	rotation = change;
}

void Transform::RotateTo(double rotate)
{
	double mod = 360;
	rotation = rotate;
 	//rotation = std::modf(mod, &rotate);
}

void Transform::Scale(double scale)
{
	this->scale = scale;
}

void Transform::ScaleRelatively(double scale)
{
	this->scale = this->scale + scale;
}

double Transform::GetRotation() const
{
	return this->rotation;
}

Point Transform::GetPoint() const
{
	return this->point;
}

double Transform::GetScale() const
{
	return this->scale;
}