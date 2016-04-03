#pragma once

#include <vector>
#include <map>
#include <string>
#include "../../Core/Box.h"


class Animation
{
public:
	Animation(std::vector<std::map<std::string, std::vector<Box>>>* animation) : animation(animation) { };
	void PlayAnimate(std::string animation, double speed);
private:
	std::vector<std::map<std::string, std::vector<Box>>>* animation;
	double counter;
	int currentFrame;
};