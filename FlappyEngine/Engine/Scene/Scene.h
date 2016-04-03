#pragma once

#include "../Input/Input.h"
#include "../Audio/AudioEngine.h"
#include "../Cache/Cache.h"
#include <vector>
#include "../Entity/Entity.h"
#include "../GUI/GUI.h"
#include "../Renderer/Render.h"


class Scene
{
public:
	Scene();
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	void UpdateScenePhysics();
	void UpdateSceneCollision();
	void UpdateSceneRender();
	bool ExitSignal();
private:
	std::vector<Entity*> Entities;
	bool exitSignal = false;
protected:
	Input* input;
	AudioEngine* audio;
	Cache* cache;
	Render* render;
	Entity* AddEntity(Entity* entity);
	Entity* RemoveEntity(Entity* entity);
	void ExitScene();
	/*void RestartScene();
	void SwitchScene();*/
};