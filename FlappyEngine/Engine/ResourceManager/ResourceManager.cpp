#include "ResourceManager.h"
#include "BaseResource.h"
#include "SoundResource.h"
#include "MusicResource.h"
#include "TextureResource.h"
#include "RenderResource.h"
#include "SDL_image.h"

ResourceManager* ResourceManager::pResourceManager = nullptr;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
	UnloadAll();
}

BaseResource* ResourceManager::GetResource(const char* path)
{
	ResourceList::iterator itr;
	// If the resource is loaded
	if ((itr = Resources.find(path)) != Resources.end())
		// ...  return a pointer to the corresponding resource
		return itr->second;
	// ... else return nullptr
	return nullptr;
}

void ResourceManager::LoadSound(const char* path)
{
	// Only load the sound if it is not already loaded
	if (Resources.find(path) == Resources.end())
	{
		// Allocate the resource
		SoundResource* sound = new SoundResource(path);
		// Add the resource and it's path to the manager's list
		Resources.insert(ResourcePair(path, sound));
	}
}

void ResourceManager::LoadMusic(const char* path)
{
	// Only load music if it is not already loaded
	if (Resources.find(path) == Resources.end())
	{
		// Allocate the resource
		MusicResource* music = new MusicResource(path);
		// Add the resource and it's path to the manager's list
		Resources.insert(ResourcePair(path, music));
	}
}
void ResourceManager::LoadTexture(const char* path/*, SDL_Renderer* renderer*/)
{
	// Only load texture if it is not already loaded
	if (Resources.find(path) == Resources.end())
	{
		// Allocate the resource
		TextureResource* texture = new TextureResource(path/*, renderer*/);
		// Add the resource and it's path to the manager's list
		Resources.insert(ResourcePair(path, texture));
	}
}
void ResourceManager::LoadRender(const char* path, int x, int y, int w, int h)
{
	// Only load renderer if it is not already loaded
	if (Resources.find(path) == Resources.end())
	{
		// Allocate the resource
		RenderResource* render = new RenderResource(path, x, y, w, h);
		// Add the resource and it's path to the manager's list
		Resources.insert(ResourcePair(path, render));
	}
}

void ResourceManager::Unload(const char* path)
{
	// Try to find the specified path in the list
	ResourceList::iterator itr = Resources.find(path);
	// If it is found...
	if (itr != Resources.end())
	{
		// ... deallocate it
		delete itr->second;
		// then remove it from the list
		Resources.erase(path);
	}
}

void ResourceManager::UnloadAll()
{
	// Iterate through every element of the resource list
	ResourceList::iterator itr;
	for (itr = Resources.begin(); itr != Resources.end(); itr++)
	{
		// Delete each resource
		delete itr->second;
	}
	// Finally, clear the list
	Resources.clear();
}


ResourceManager* ResourceManager::GetInstance()
{
	if (pResourceManager == nullptr) {
		pResourceManager = new ResourceManager();
	};

	return pResourceManager;
}