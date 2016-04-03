#pragma once

#include "../Scene/SceneManager.h"

class GameEngine
{
public:
	void Start();
	GameEngine();
private:
	void Loop();
	void Exit();
	bool quit;
	SceneManager sceneManager;
};