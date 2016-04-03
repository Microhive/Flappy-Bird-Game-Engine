#include "InputBlackbox.h"
#include <iostream>

InputBlackbox::InputBlackbox()
{
	this->InitializeInputTranslation();

	// doesn't count the number of rows, but the highest enum value, thus +1
	size_t x = sizeof(KeyCode) + 1;
	for (size_t i = 0; i <= x; i++)
	{
		InputStateMap.insert(std::pair<KeyCode, KeyState>((KeyCode) i, KeyState::Up));
	}
}

// Add new records for desired input keys
void InputBlackbox::InitializeInputTranslation()
{
	InputTranslationMap.insert(std::pair<SDL_Keycode, KeyCode>((SDL_Keycode) SDLK_DOWN, KeyCode::Down));
	InputTranslationMap.insert(std::pair<SDL_Keycode, KeyCode>((SDL_Keycode) SDLK_UP, KeyCode::Up));
	InputTranslationMap.insert(std::pair<SDL_Keycode, KeyCode>((SDL_Keycode) SDLK_LEFT, KeyCode::Left));
	InputTranslationMap.insert(std::pair<SDL_Keycode, KeyCode>((SDL_Keycode) SDLK_RIGHT, KeyCode::Right));
	InputTranslationMap.insert(std::pair<SDL_Keycode, KeyCode>((SDL_Keycode) SDLK_SPACE, KeyCode::Space));
	InputTranslationMap.insert(std::pair<SDL_Keycode, KeyCode>((SDL_Keycode) SDLK_ESCAPE, KeyCode::Escape));
}

void InputBlackbox::Update()
{
	//Handle events on queue
	while (SDL_PollEvent(&e) != 0)
	{
		if (quitReceived)
			quitReceived = false;

		switch (e.type)
		{
		//case SDL_MOUSEBUTTONDOWN:
		//case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
		{
			SDL_GetMouseState(&x, &y);
		} break;

		case SDL_KEYDOWN:
		{
			std::map<SDL_Keycode, KeyCode>::iterator iter = InputTranslationMap.find(e.key.keysym.sym);
			if (iter != InputTranslationMap.end())
			{
				std::map<KeyCode, KeyState>::iterator iter2 = InputStateMap.find(iter->second);
				if (iter2 != InputStateMap.end())
				{
					iter2->second = KeyState::Down;
				}
			}
		} break;
		case SDL_KEYUP:
		{
			std::map<SDL_Keycode, KeyCode>::iterator iter = InputTranslationMap.find(e.key.keysym.sym);
			if (iter != InputTranslationMap.end())
			{
				std::map<KeyCode, KeyState>::iterator iter2 = InputStateMap.find(iter->second);
				if (iter2 != InputStateMap.end())
				{
					iter2->second = KeyState::Up;
				}
			}
		} break;
		case SDL_QUIT:
		{
			quitReceived = true;
		} break;
		}
	}
}

KeyState InputBlackbox::GetInputState(KeyCode key) const
{
	return InputStateMap.find(key)->second;
}

int InputBlackbox::GetMousePositionX()
{
	return x;
}

int InputBlackbox::GetMousePositionY()
{
	return y;
}

bool InputBlackbox::QuitReceived()
{
	if (quitReceived)
		return true;

	return false;
}

