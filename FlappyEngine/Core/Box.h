#pragma once

class Box
{
public:
	Box(double X = 0, double Y = 0, double Width = 0, double Height = 0) { SetX(X); SetY(Y); SetWidth(Width); SetHeight(Height); };
	double GetX() const { return this->X; };
	double GetY() const { return this->Y; };
	double GetWidth() const { return this->Width; };
	double GetHeight() const { return this->Height; };
	void SetX(double X) { this->X = X; };
	void SetY(double Y) { this->Y = Y; };
	void SetWidth(double Width) { this->Width = Width; };
	void SetHeight(double Height) { this->Height = Height; };

private:
	double X;
	double Y;
	double Width;
	double Height;
};