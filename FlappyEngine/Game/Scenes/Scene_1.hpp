#pragma once

#include "../../Engine/Scene/Scene.h"
#include <iostream>
#include "../Logger/Logger.h"

class Scene_1 : public Scene
{
private:
	Entity* tube1Bottom;
	Entity* tube2Bottom;
	Entity* tube1Top;
	Entity* tube2Top;
	Entity* flappyBird;
	Entity* bottomBorder;
	Entity* bottomBorder2;
	Entity* topBorder;
	Entity* background;
	Entity* background2;
	Entity* scoreHitBox;
	Sound* flySound;
	Sound* dieSound;
	Sound* hitSound;
	Sound* pointSound;
	Sound* swooshSound;
	Texture* image1;
	Window* window1;

	int tubeRandPlasement1, tubeRandPlasement2;
	bool doJump = false;
	bool lost = false;
	bool start = false;
	int points = 0;

public:
	void Initialize()
	{
		tubeRandPlasement1 = rand() % 195 + 5;   // in the range 5-200 
		tubeRandPlasement2 = rand() % 195 + 5;   // in the range 5-200 

		Logger* log = Logger::GetInstance();
		log->Log("Initialising scene!", true);
		window1 = new Window("Flappy Bird", Box(100, 100, 288, 512));
		image1 = new Texture("Assets/Textures/spritesheet.png");

		// Setup Tube
		tube1Bottom = AddEntity(
			new Entity(
			"tube1Bottom",
			new Transform(Point(350, tubeRandPlasement1, 9), 0, 1),	
			new SpriteRenderer(image1, window1, Box(168, 646, 53, 321), 53, 321),
			new Collider(53, 321),
			new RigidBody(false))
			);
		tube1Bottom->GetRigidBody()->SetForce(-1, 0);
		tube1Bottom->GetRigidBody()->SetStatic(true);

		// Setup Tube
		tube2Bottom = AddEntity(
			new Entity(
			"tube2Bottom",
			new Transform(Point(550, tubeRandPlasement2, 8), 0, 1),
			new SpriteRenderer(image1, window1, Box(168, 646, 53, 321), 53, 321),
			new Collider(53, 321),
			new RigidBody(false))
			);
		tube2Bottom->GetRigidBody()->SetForce(-1, 0);
		tube2Bottom->GetRigidBody()->SetStatic(true);

		// Setup Tube
		tube1Top = AddEntity(
			new Entity(
			"tube1Top",
			new Transform(Point(350, tube1Bottom->GetTransform()->GetPoint().GetY()+420, 9), 180, 1),
			new SpriteRenderer(image1, window1, Box(168, 646, 53, 321), 53, 321),
			new Collider(53, 321),
			new RigidBody(false))
			);
		tube1Top->GetRigidBody()->SetForce(-1, 0);
		tube1Top->GetRigidBody()->SetStatic(true);

		// Setup Tube
		tube2Top = AddEntity(
			new Entity(
			"tube2Top",
			new Transform(Point(550, tube2Bottom->GetTransform()->GetPoint().GetY() + 420, 9), 180, 1),
			new SpriteRenderer(image1, window1, Box(168, 646, 53, 321), 53, 321),
			new Collider(53, 321),
			new RigidBody(false))
			);
		tube2Top->GetRigidBody()->SetForce(-1, 0);
		tube2Top->GetRigidBody()->SetStatic(true);

		// ScoreHitBox
		scoreHitBox = AddEntity(
			new Entity(
			"ScoreHitBox",
			new Transform(Point(450, 300, 8), 0, 1),
			new SpriteRenderer(image1, window1, Box(168, 646, 0, 0), 53, 1000),
			new Collider(53, 1000),
			new RigidBody(false))
			);
		scoreHitBox->GetRigidBody()->SetForce(-1, 0);
		scoreHitBox->GetRigidBody()->SetStatic(true);

		// Setup FlappyBird
		flappyBird = AddEntity(
			new Entity(
			"flappybird",
			new Transform(Point(90, 250, 0), 0, 1),
			new SpriteRenderer(image1, window1, Box(6, 982, 35, 26), 35, 26),
			new Collider(32, 22),
			new RigidBody())
			);
		flappyBird->GetRigidBody()->SetStatic(true);

		// Setup Border
		bottomBorder = AddEntity(
			new Entity(
			"bottomBorder",
			new Transform(Point(100, 25, 5), 0, 1),
			new SpriteRenderer(image1, window1, Box(585, 0, 335, 114), 335, 114),
			new Collider(1000, 114),
			new RigidBody(false))
			);
		bottomBorder->GetRigidBody()->SetStatic(true);
		bottomBorder->GetRigidBody()->SetForce(-1, 0);

		bottomBorder2 = AddEntity(
			new Entity(
			"bottomBorder2",
			new Transform(Point(435, 25, 5), 0, 1),
			new SpriteRenderer(image1, window1, Box(585, 0, 335, 114), 335, 114),
			new Collider(1000, 114),
			new RigidBody(false))
			);
		bottomBorder2->GetRigidBody()->SetStatic(true);
		bottomBorder2->GetRigidBody()->SetForce(-1, 0);

		topBorder = AddEntity(
		new Entity(
		"topBorder",
			new Transform(Point(144, 545, 5), 0, 1),
			new SpriteRenderer(image1, window1, Box(585, 0, 288, 114), 288, 50),
			new Collider(1000, 50),
		new RigidBody(false))
		);
		topBorder->GetRigidBody()->SetStatic(true);
		bottomBorder2->GetRigidBody()->SetForce(-1, 0);

		// Setup Background
		background = AddEntity(
			new Entity(
			"background",
			new Transform(Point(0, 256, 10), 0, 1),
			new SpriteRenderer(image1, window1, Box(0, 0, 288, 512), 288, 512),
			new Collider(288, 512),
			new RigidBody(false))
			);
		background->GetRigidBody()->SetStatic(true);
		background->GetRigidBody()->SetForce(-0.2, 0);

		background2 = AddEntity(
			new Entity(
			"background2",
			new Transform(Point(288, 256, 10), 0, 1),
			new SpriteRenderer(image1, window1, Box(0, 0, 288, 512), 288, 512),
			new Collider(288, 512),
			new RigidBody(false))
			);
		background2->GetRigidBody()->SetStatic(true);
		background2->GetRigidBody()->SetForce(-0.2, 0);

		// Load Resources
		flySound = new Sound("Assets/Audio/Fly.wav");
		dieSound = new Sound("Assets/Audio/Die.wav");
		hitSound = new Sound("Assets/Audio/Hit.wav");
		swooshSound = new Sound("Assets/Audio/Swoosh.wav");
		pointSound = new Sound("Assets/Audio/Point.wav");

		// Increment score each time game is started! :D
		std::string points = this->cache->Load("score");
		if (points != "")
		{
			int val = atoi(points.c_str());
			std::string value = std::to_string(val + 1);
			cache->Save("score", value);
		}
		else
		{
			std::string value = std::to_string(1);
			cache->Save("score", value);
		}
		audio->PlaySound(swooshSound);
	}

	void Update()
	{
		// Exit on escape
		if (this->input->IsKeyDown(KeyCode::Escape))
			this->ExitScene();

		// Start Game
		if (!start && input->IsKeyPressed(KeyCode::Space))
		{
			flappyBird->GetRigidBody()->SetStatic(false);
			tube1Bottom->GetRigidBody()->SetStatic(false);
			tube2Bottom->GetRigidBody()->SetStatic(false);
			tube1Top->GetRigidBody()->SetStatic(false);
			tube2Top->GetRigidBody()->SetStatic(false);
			scoreHitBox->GetRigidBody()->SetStatic(false);
			bottomBorder->GetRigidBody()->SetStatic(false);
			bottomBorder2->GetRigidBody()->SetStatic(false);
			background->GetRigidBody()->SetStatic(false);
			background2->GetRigidBody()->SetStatic(false);
			start = true;
		}
		
		// Jump
		if (!lost && input->IsKeyPressed(KeyCode::Space))
		{
			doJump = true;
			audio->PlaySound(flySound);
		}

		//std::cout << input->GetMousePositionX() << ", " << input->GetMousePositionY() << std::endl;
		/*if (static_cast<GUI*>(background)->IsClicked())
		std::cout << "Hello World!" << std::endl;*/
	}

	void FixedUpdate()
	{
		if (start)
		{
			// Apply Rotation
			if (flappyBird->GetRigidBody()->GetVelocityY() > 0)
				if (flappyBird->GetTransform()->GetRotation() >= -35)
					flappyBird->GetTransform()->RotateRelatively(0);
				else;
			else if (flappyBird->GetTransform()->GetPoint().GetY() > 0)
				if (flappyBird->GetTransform()->GetRotation() <= 35)
					flappyBird->GetTransform()->RotateRelatively(2);

			if (!lost)
			{
				// Jump based on bottom Collision
				if (Entity* otherEntity = bottomBorder->GetCollider()->IsColliding("flappybird"))
					lost = true;
				if (Entity* otherEntity = bottomBorder2->GetCollider()->IsColliding("flappybird"))
					lost = true;
				if (Entity* otherEntity = tube1Top->GetCollider()->IsColliding("flappybird"))
					lost = true;
				if (Entity* otherEntity = tube1Bottom->GetCollider()->IsColliding("flappybird"))
					lost = true;
				if (Entity* otherEntity = tube2Top->GetCollider()->IsColliding("flappybird"))
					lost = true;
				if (Entity* otherEntity = tube2Bottom->GetCollider()->IsColliding("flappybird"))
					lost = true;

				if (Entity* otherEntity = scoreHitBox->GetCollider()->IsColliding("flappybird"))
				{
					audio->PlaySound(pointSound);
					scoreHitBox->GetTransform()->MoveToPoint(scoreHitBox->GetTransform()->GetPoint().GetX() + 200, 480, 9);
					points++;
					Logger* log = Logger::GetInstance();
					log->Log("Points: " + std::to_string(points), true);
				}

				// Limit height on top Collision
				if (Entity* otherEntity = topBorder->GetCollider()->IsColliding("flappybird"))
				{
					Point loc = otherEntity->GetTransform()->GetPoint();
					otherEntity->GetTransform()->MoveToPoint(
						loc.GetX(),
						loc.GetY() - otherEntity->GetRigidBody()->GetVelocityY(),
						loc.GetZ());
				}

				// Move Tubes
				if (tube1Bottom->GetTransform()->GetPoint().GetX() <= -53) 
				{
					tubeRandPlasement1 = rand() % 195 + 5;   // in the range 5-200 
					tube1Bottom->GetTransform()->MoveToPoint(tube2Bottom->GetTransform()->GetPoint().GetX() + 200, tubeRandPlasement1, 9);
				}
				if (tube2Bottom->GetTransform()->GetPoint().GetX() <= -53)
				{
					tubeRandPlasement1 = rand() % 195 + 5;   // in the range 5-200 
					tube2Bottom->GetTransform()->MoveToPoint(tube1Bottom->GetTransform()->GetPoint().GetX() + 200, tubeRandPlasement1, 9);
				}
				if (tube1Top->GetTransform()->GetPoint().GetX() <= -53)
					tube1Top->GetTransform()->MoveToPoint(tube2Bottom->GetTransform()->GetPoint().GetX() + 200, tube1Bottom->GetTransform()->GetPoint().GetY() + 420, 9);
				if (tube2Top->GetTransform()->GetPoint().GetX() <= -53)
					tube2Top->GetTransform()->MoveToPoint(tube1Bottom->GetTransform()->GetPoint().GetX() + 200, tube2Bottom->GetTransform()->GetPoint().GetY() + 420, 9);
				
				if (bottomBorder->GetTransform()->GetPoint().GetX() <= (-335 / 2))
					bottomBorder->GetTransform()->MoveRelative(bottomBorder->GetSpriteRenderer()->GetWidth() * 2, 0, 0);
				if (bottomBorder2->GetTransform()->GetPoint().GetX() <= (-335 / 2))
					bottomBorder2->GetTransform()->MoveRelative(bottomBorder2->GetSpriteRenderer()->GetWidth() * 2, 0, 0);
				if (background->GetTransform()->GetPoint().GetX() <= (-288 / 2))
					background->GetTransform()->MoveRelative(background->GetSpriteRenderer()->GetWidth() * 2, 0, 0);
				if (background2->GetTransform()->GetPoint().GetX() <= (-288 / 2))
					background2->GetTransform()->MoveRelative(background2->GetSpriteRenderer()->GetWidth() * 2, 0, 0);

				// Jump based on Input
				if (doJump)
				{
					flappyBird->GetRigidBody()->SetStatic(false);
					flappyBird->GetRigidBody()->SetForce(0, 4.5);
					if (flappyBird->GetTransform()->GetRotation() >= -5)
						flappyBird->GetTransform()->RotateTo(-25);
					doJump = false;
				}

				if (lost)
				{
					audio->PlaySound(hitSound);
					audio->PlaySound(dieSound);
					audio->PlaySound(swooshSound);

					// Save scorepoints if higher than saved value
					std::string score = this->cache->Load("highscore");
					if (score != "")
					{
						if (atoi(score.c_str()) < points)
							cache->Save("highscore", std::to_string(points));
					}
					else
						cache->Save("highscore", std::to_string(points));
						
				}
			}
			// Loss condition
			else
			{
				// Stop bird on ground
				if (Entity* otherEntity = bottomBorder->GetCollider()->IsColliding("flappybird"))
					flappyBird->GetRigidBody()->SetStatic(true);
				if (Entity* otherEntity = bottomBorder2->GetCollider()->IsColliding("flappybird"))
					flappyBird->GetRigidBody()->SetStatic(true);

				//Rotate bird 90degrees down
				flappyBird->GetTransform()->RotateTo(90);
				// Freeze scene
				tube1Bottom->GetRigidBody()->SetStatic(true);
				tube2Bottom->GetRigidBody()->SetStatic(true);
				tube1Top->GetRigidBody()->SetStatic(true);
				tube2Top->GetRigidBody()->SetStatic(true);
				scoreHitBox->GetRigidBody()->SetStatic(true);
				bottomBorder->GetRigidBody()->SetStatic(true);
				bottomBorder2->GetRigidBody()->SetStatic(true);
				background->GetRigidBody()->SetStatic(true);
				background2->GetRigidBody()->SetStatic(true);
			}
		}
	}
};