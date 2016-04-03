#include "AudioEngine.h"
#include "AudioBlackbox.h"
#include "Audio.h"

AudioEngine* AudioEngine::pAudioEngine = nullptr;

AudioEngine::AudioEngine()
{
	// can be switched out
	this->Blackbox = new AudioBlackbox();
}

AudioEngine::~AudioEngine() 
{
	delete this->music;
	delete this->Blackbox;
	delete this->pAudioEngine;
}

AudioEngine* AudioEngine::GetInstance()
{
	if (pAudioEngine == nullptr) {
		pAudioEngine = new AudioEngine();
	};

	return pAudioEngine;
}

void AudioEngine::PlaySound(Sound* sound)
{
	this->Blackbox->PlaySound(sound);
}

void AudioEngine::SetMusic(Music* music) 
{
	this->music = music;
}

void AudioEngine::PlayMusic() 
{
	this->Blackbox->PlayMusic(this->music);
}

void AudioEngine::StopMusic()
{
	//this->Blackbox->StopMusic();
}