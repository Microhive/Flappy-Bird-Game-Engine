#include "AudioBlackbox.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
#include "../ResourceManager/ResourceManager.h"
#include "../ResourceManager/SoundResource.h"
#include "../ResourceManager/MusicResource.h"
#include <cstdlib>
#include <stdlib.h> 
#include <time.h> 
#include <stdio.h> 


AudioBlackbox::AudioBlackbox()
{
	srand(time(NULL));
	SDL_Init(SDL_INIT_AUDIO);
	
}


AudioBlackbox::~AudioBlackbox()
{
}


void AudioBlackbox::Update() 
{

}

void AudioBlackbox::PlaySound(Sound* sound) 
{
	ResourceManager* res = ResourceManager::GetInstance();
	Mix_Chunk* chunk = static_cast<SoundResource*>(res->GetResource(sound->GetPath()))->GetChunk();
	Mix_PlayChannel(-1, chunk, 0);
}

void AudioBlackbox::PlayMusic(Music* music)
{
	ResourceManager* res = ResourceManager::GetInstance();
	Mix_Music* mixmusic = static_cast<MusicResource*>(res->GetResource(music->GetPath()))->GetMusic();
	Mix_PlayMusic(mixmusic, -1);
}

void AudioBlackbox::StopSound(Sound* sound)
{

}

void AudioBlackbox::StopMusic(Music* music)
{

}

int AudioBlackbox::GetRandomInt() 
{
	int a = rand() % 16 + 1;
	return a;
}