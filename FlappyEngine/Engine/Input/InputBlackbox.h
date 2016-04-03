#pragma once

#include "Input.h"
#include <SDL.h>

static enum class SDL_Map;

class InputBlackbox : public Input_Interface
{
public:
	InputBlackbox();
	void Update();
	KeyState GetInputState(KeyCode key) const;
	int GetMousePositionX();
	int GetMousePositionY();
	bool QuitReceived();
private:
	void InitializeInputTranslation();
	SDL_Event e;
	std::map<KeyCode, KeyState> InputStateMap;
	std::map<SDL_Keycode, KeyCode> InputTranslationMap;
	bool quitReceived = false;
	int x = 0;
	int y = 0;
};