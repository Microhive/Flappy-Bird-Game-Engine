#pragma once

#include <SDL.h>

class Timer
{
public:
	static unsigned __int32 GetTime();
};

unsigned __int32 Timer::GetTime()
{
	return SDL_GetTicks();
}