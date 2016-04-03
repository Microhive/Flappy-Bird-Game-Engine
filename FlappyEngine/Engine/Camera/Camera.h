#pragma once

class Camera
{
public:
	void SetCameraSize(int width, int height);
	void SetCameraCenter(int centerX, int centerY);
	int GetCameraCenterX() const;
	int GetCameraCenterY() const;
private:
	int width;
	int height;
	int centerX;
	int centerY;
};