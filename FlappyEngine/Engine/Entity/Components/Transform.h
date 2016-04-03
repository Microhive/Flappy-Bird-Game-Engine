#pragma once

class Entity;

#include "../Entity.h"
#include "../../../Core/Point.h"

class Transform
{
public:
	Transform(Point point, double rotation, double scale) : point(point), rotation(rotation), scale(scale) {};
	void SetEntity(Entity* entity) { this->entity = entity; }
	void MoveRelative(double X, double Y, double Z);
	void MoveToPoint(double X, double Y, double Z);
	void MoveToPoint(Point point);
	void RotateRelatively(double rotate);
	void RotateTo(double rotate);
	void Scale(double scale);
	void ScaleRelatively(double scale);
	double GetRotation() const;
	Point GetPoint() const;
	double GetScale() const;
private:
	Entity* entity;
	double rotation;
	Point point;
	double scale;
};