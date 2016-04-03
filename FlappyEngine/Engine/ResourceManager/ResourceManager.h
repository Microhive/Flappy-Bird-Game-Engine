#pragma once
#include <map>

// Forward declaration
class BaseResource;

class ResourceManager
{
private:
	typedef std::map<const char*, BaseResource*> ResourceList;
	typedef std::pair<const char*, BaseResource*> ResourcePair;
	ResourceList Resources;

	~ResourceManager();
	static ResourceManager* pResourceManager;


public:
	ResourceManager();

	static ResourceManager* GetInstance();

	BaseResource* GetResource(const char*);
	void LoadSound(const char*);   // Loads wav files
	void LoadMusic(const char*);   // Loads music files
	void LoadTexture(const char*/*, SDL_Renderer* renderer*/); // Loads image files
	void LoadRender(const char*, int, int, int, int);
	void Unload(const char*);      // Unloads the resource
	void UnloadAll();              // Unloads every resource

};

