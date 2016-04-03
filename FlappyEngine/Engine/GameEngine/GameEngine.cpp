#include "GameEngine.h"
#include "../Input/Input.h"
#include "../Audio/AudioEngine.h"
#include "../Renderer/Render.h"
#include "../../Core/Timer.h"

GameEngine::GameEngine()
{
	quit = false;	
}

void GameEngine::Start()
{
	this->Loop();
}

void GameEngine::Loop()
{
	// Initialize Components
	this->sceneManager.Initialize();
	Input* input = Input::GetInstance();
	//AudioEngine* audio = AudioEngine::GetInstance();
	//Render* render = Render::getInstance();

	// Regulating updates / fixed updates
	// http://www.koonsolo.com/news/dewitters-gameloop/
	const int TICKS_PER_SECOND = 60;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;
	Uint32 next_game_tick = Timer::GetTime();
	int loops;
	float interpolation;

	while (true)
	{
		if (this->sceneManager.ExitSignal() || input->QuitReceived())
		{
			this->Exit();
			break;
		}

		loops = 0;
		while (Timer::GetTime() > next_game_tick && loops < MAX_FRAMESKIP) {

			// Game Update
			this->sceneManager.UpdatePhysics();
			this->sceneManager.UpdateCollisions();
			this->sceneManager.FixedUpdate();
				
			next_game_tick += SKIP_TICKS;
			loops++;
		}

		// Add your component updates here!
		input->Update();
		
		//render->DrawTextureToScreen( 0, 0, 640, 480);

		interpolation = float(Timer::GetTime() + SKIP_TICKS - next_game_tick) / float(SKIP_TICKS);
		this->sceneManager.Update();
		this->sceneManager.UpdateRender(interpolation);

		
	}
}

void GameEngine::Exit()
{
	quit = true;
}