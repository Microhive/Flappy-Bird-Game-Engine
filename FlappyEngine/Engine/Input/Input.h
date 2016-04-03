#pragma once

static enum class KeyCode;
static enum class KeyState;

#include <map>
#include "Input_Interface.h"
#include "InputBlackbox.h"

class Input {
public:
	static Input* GetInstance();
	bool IsKeyPressed(KeyCode);
	bool IsKeyReleased(KeyCode);
	bool IsKeyDown(KeyCode);
	int GetMousePositionX();
	int GetMousePositionY();
	bool QuitReceived();
	void Update();

private:
	Input();
	static Input* _Instance;
	Input_Interface* Input_BlackBox;
	std::map<KeyCode, KeyState> InputStateMap;
	bool Quit = false;
};

