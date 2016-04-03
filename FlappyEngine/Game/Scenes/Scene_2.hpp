#pragma once

#include "../../Engine/Scene/Scene.h"
#include <iostream>
#include "../Logger/Logger.h"

class Scene_2 : public Scene
{
private:
	Entity* background;
	Entity* sheep;
	std::vector<Entity*> axes;
	Texture* backgroundTexture;
	Texture* sheepTexture;
	Texture* axeTexture;
	Window* window;

	bool stop = false;
	bool up = false;
	bool down = false;

public:
	void Initialize()
	{
		Logger* log = Logger::GetInstance();
		log->Log("Initialising scene!", true);

		window = new Window("Avoid the axe game!", Box(10, 40, 960, 640));
		backgroundTexture = new Texture("Assets/Textures/farm.png");
		sheepTexture = new Texture("Assets/Textures/sheep.png");
		axeTexture = new Texture("Assets/Textures/axe.png");

		// Setup Background
		background = AddEntity(
			new Entity(
			"farm",
			new Transform(Point(480, 320, 10), 0, 1),
			new SpriteRenderer(backgroundTexture, window, Box(0, 100, 960, 540), 960, 540),
			new Collider(960, 540),
			new RigidBody(false))
			);
		sheep = AddEntity(
			new Entity(
			"sheep",
			new Transform(Point(860, 300, 2), 0, 1),
			new SpriteRenderer(sheepTexture, window, Box(0, 0, 279, 299), 66, 60),
			new Collider(66, 60),
			new RigidBody(false))
			);
		axes.push_back(AddEntity(
			new Entity(
			"axe",
			new Transform(Point(5, rand() % 350 + 80, 1), 0, 1),
			new SpriteRenderer(axeTexture, window, Box(0, 0, 640, 480), 66, 50),
			new Collider(66, 50),
			new RigidBody(false))
			));
		axes.back()->GetRigidBody()->SetForce(2, 0);
		axes.push_back(AddEntity(
			new Entity(
			"axe",
			new Transform(Point(-100, rand() % 350 + 80, 1), 0, 1),
			new SpriteRenderer(axeTexture, window, Box(0, 0, 640, 480), 66, 50),
			new Collider(66, 50),
			new RigidBody(false))
			));
		axes.back()->GetRigidBody()->SetForce(2, 0);
		axes.push_back(AddEntity(
			new Entity(
			"axe",
			new Transform(Point(-300, rand() % 350 + 80, 1), 0, 1),
			new SpriteRenderer(axeTexture, window, Box(0, 0, 640, 480), 66, 50),
			new Collider(66, 50),
			new RigidBody(false))
			));
		axes.back()->GetRigidBody()->SetForce(2, 0);
		axes.push_back(AddEntity(
			new Entity(
			"axe",
			new Transform(Point(-600, rand() % 350 + 80, 1), 0, 1),
			new SpriteRenderer(axeTexture, window, Box(0, 0, 640, 480), 66, 50),
			new Collider(66, 50),
			new RigidBody(false))
			));
		axes.back()->GetRigidBody()->SetForce(2, 0);
		axes.push_back(AddEntity(
			new Entity(
			"axe",
			new Transform(Point(-600, rand() % 350 + 80, 1), 0, 1),
			new SpriteRenderer(axeTexture, window, Box(0, 0, 640, 480), 66, 50),
			new Collider(66, 50),
			new RigidBody(false))
			));
		axes.back()->GetRigidBody()->SetForce(2, 0);
		axes.push_back(AddEntity(
			new Entity(
			"axe",
			new Transform(Point(-800, rand() % 350 + 80, 1), 0, 1),
			new SpriteRenderer(axeTexture, window, Box(0, 0, 640, 480), 66, 50),
			new Collider(66, 50),
			new RigidBody(false))
			));
		axes.back()->GetRigidBody()->SetForce(2, 0);
	}

	void Update()
	{
		if (stop)
		{
			// do nothing!
		}
		else
		{
			if (input->IsKeyDown(KeyCode::Up))
			{
				up = true;
			}
			if (input->IsKeyDown(KeyCode::Down))
			{
				down = true;
			}
		}
	}

	void FixedUpdate()
	{
		if (stop)
		{
			// do nothing!
		}
		else
		{
			for each (auto axe in axes)
			{
				axe->GetTransform()->RotateRelatively(2);
				if (axe->GetTransform()->GetPoint().GetX() - axe->GetSpriteRenderer()->GetWidth() > background->GetSpriteRenderer()->GetWidth())
				{
					axe->GetTransform()->MoveToPoint(-50, rand() % 350 + 80, 1);
				}
			}
			if (up && sheep->GetTransform()->GetPoint().GetY() < 430)
			{
				sheep->GetTransform()->MoveRelative(0, 2, 0);
				up = false;
			}
			if (down && sheep->GetTransform()->GetPoint().GetY() > 100)
			{
				sheep->GetTransform()->MoveRelative(0, -2, 0);
				down = false;
			}

			if (Entity* otherEntity = sheep->GetCollider()->IsColliding("axe"))
			{
				otherEntity->GetTransform()->RotateTo(0);
				Point sheepPos = sheep->GetTransform()->GetPoint();
				otherEntity->GetTransform()->MoveToPoint(sheepPos.GetX() - 40, sheepPos.GetY() + 20, 1);
				for each (auto axe in axes)
				{
					axe->GetRigidBody()->SetStatic(true);
				}
				stop = true;
			}
		}
	}
};