#include "SceneManager.h"
#include "../../Game/Startup.h"

void SceneManager::Initialize()
{
	// Starting scene is always the first item in the list
	Startup startup;

	for each (auto var in startup.GetScenes())
		this->Scenes.push_back(var);

	// Start Game
	StartScene(this->Scenes.front());
}

void SceneManager::StartScene(Scene* scene)
{
	SelectedScene = scene;
	SelectedScene->Initialize();
}

void SceneManager::Update()
{
	SelectedScene->Update();
}

void SceneManager::FixedUpdate()
{
	SelectedScene->FixedUpdate();
}

void SceneManager::UpdatePhysics()
{
	SelectedScene->UpdateScenePhysics();
}

void SceneManager::UpdateCollisions()
{
	SelectedScene->UpdateSceneCollision();
}

void SceneManager::UpdateRender(double interpolation = 1)
{
	SelectedScene->UpdateSceneRender();
}

bool SceneManager::ExitSignal()
{
	return this->SelectedScene->ExitSignal();
}

void SceneManager::Reset()
{
	/*delete this->SelectedScene;
	this->StartScene(new static_cast<Scene*>typeid(SelectedScene)());*/
}