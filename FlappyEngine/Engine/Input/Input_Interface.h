#pragma once

//#include <SDL.h>
#include "Input.h"

class Input_Interface
{
public:
	virtual void Update() = 0;
	virtual KeyState GetInputState(KeyCode key) const = 0;
	virtual int GetMousePositionX() = 0;
	virtual int GetMousePositionY() = 0;
	virtual bool QuitReceived() = 0;
};

static enum class KeyCode
{
	Left,
	Right,
	Up,
	Down,
	Space,
	Escape
};

static enum class KeyState
{
	Down,
	Pressed,
	Released,
	Up
};