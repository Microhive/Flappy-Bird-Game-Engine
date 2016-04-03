#pragma once

#include <list>
#include "Scene.h"
#include <string>

class SceneManager
{
public:
	void Initialize();
	void StartScene(Scene* scene);
	void Update();
	void FixedUpdate();
	void UpdateCollisions();
	void UpdatePhysics();
	void UpdateRender(double interpolation);
	void Reset();
	bool ExitSignal();
private:
	std::list<Scene*> Scenes;
	Scene* SelectedScene;
};