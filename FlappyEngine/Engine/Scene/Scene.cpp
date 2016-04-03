#include "Scene.h"
#include "../Physics/Physics.h"
#include "../Collision/Collision.h"
#include "../Renderer/Render.h"

Scene::Scene()
{
	this->input = Input::GetInstance();
	this->audio = AudioEngine::GetInstance();
	this->render = Render::getInstance();
	this->cache = Cache::GetInstance();
}

void Scene::UpdateScenePhysics()
{
	Physics* physics = Physics::GetInstance();
	for each (auto entity in Entities)
	{
		physics->AddToQueue(entity->GetRigidBody());
	}
	
	physics->Update();
}

void Scene::UpdateSceneCollision()
{
	Collision* collision = Collision::GetInstance();
	for each (auto entity in Entities)
	{
		entity->GetCollider()->Update(); // reset otherCollider
		collision->AddToCollisionCheckList(entity->GetCollider());
	}

	collision->PerformCollisonCheck();
}

void Scene::UpdateSceneRender()
{
	Render* render = Render::getInstance();
	render->CleareScreen();

	// Make sure that entities are drawn on screen in order based on their z value
	std::sort(Entities.rbegin(), Entities.rend(), sortCollidersByZValue);
	for each (auto var in Entities)
	{
		var->GetSpriteRenderer()->RenderOnScreen();
	}
	render->UpdateScreen();
}

Entity* Scene::AddEntity(Entity* entity)
{
	entity->Create();
	this->Entities.push_back(entity);
	return entity;
}

Entity* Scene::RemoveEntity(Entity* entity)
{
	entity->Destroy();
	//this->Entities.erase(entity);
	return entity;
}

void Scene::ExitScene()
{
	this->exitSignal = true;
}

bool Scene::ExitSignal()
{
	return exitSignal;
}
