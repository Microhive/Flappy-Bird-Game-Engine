#pragma once

class Point
{
public:
	Point(double X = 0, double Y = 0, double Z = 0) { SetX(X); SetY(Y); SetZ(Z); };
	double GetX() const { return this->X; };
	double GetY() const { return this->Y; };
	double GetZ() const { return this->Z; };
	void SetX(double X) { this->X = X; };
	void SetY(double Y) { this->Y = Y; };
	void SetZ(double Z) { this->Z = Z; };

private:
	double X;
	double Y;
	double Z;
};