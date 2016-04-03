#include "Input.h"
#include <iostream>

Input* Input::_Instance = nullptr;

Input::Input()
{
	// Module can be switched out
	this->Input_BlackBox = new InputBlackbox();

	// doesn't count the number of rows, but the highest enum value, thus +1
	size_t x = sizeof(KeyCode) + 1;
	for (size_t i = 0; i <= x; i++)
	{
		InputStateMap.insert(std::pair<KeyCode, KeyState>((KeyCode) i, KeyState::Up));
	}
}

Input* Input::GetInstance()
{
	if (!_Instance)
		_Instance = new Input();

	return _Instance;
}

void Input::Update()
{
	Input_BlackBox->Update();
	for each (auto var in InputStateMap)
	{
		KeyState oldState = var.second;
		KeyState newState = Input_BlackBox->GetInputState(var.first);

		// Pressed
		if (oldState == KeyState::Up && newState == KeyState::Down)
		{
			InputStateMap.find(var.first)->second = KeyState::Pressed;
		}
		else if (oldState == KeyState::Pressed && newState == KeyState::Down)
		{
			InputStateMap.find(var.first)->second = KeyState::Down;
		}
		else if (oldState == KeyState::Pressed && newState == KeyState::Up)
		{
			InputStateMap.find(var.first)->second = KeyState::Down;
		}
		else if (oldState == KeyState::Down && newState == KeyState::Up)
		{
			InputStateMap.find(var.first)->second = KeyState::Released;
		}
		else if (oldState == KeyState::Released && newState == KeyState::Up)
		{
			InputStateMap.find(var.first)->second = KeyState::Up;
		}
		/*else
		{
			InputStateMap.find(var.first)->second = KeyState::Up;
		}*/
	}
}

bool Input::IsKeyDown(KeyCode keycode)
{
	std::map<KeyCode, KeyState>::iterator iter = InputStateMap.find(keycode);
	if (iter == InputStateMap.end())
		return false;

	if (iter->second == KeyState::Down)
		return true;

	return false;
}

bool Input::QuitReceived()
{
	if (Input_BlackBox->QuitReceived())
		return true;

	return false;
}

bool Input::IsKeyPressed(KeyCode keycode)
{
	std::map<KeyCode, KeyState>::iterator iter = InputStateMap.find(keycode);
	if (iter == InputStateMap.end())
		return false;

	if (iter->second == KeyState::Pressed)
		return true;

	return false;
}

bool Input::IsKeyReleased(KeyCode keycode)
{
	std::map<KeyCode, KeyState>::iterator iter = InputStateMap.find(keycode);
	if (iter == InputStateMap.end())
		return false;

	if (iter->second == KeyState::Released)
		return true;

	return false;
}

int Input::GetMousePositionX()
{
	return this->Input_BlackBox->GetMousePositionX();
}

int Input::GetMousePositionY()
{
	return this->Input_BlackBox->GetMousePositionY();
}