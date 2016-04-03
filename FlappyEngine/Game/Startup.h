#pragma once

#include "Scenes/Scene_1.hpp"
#include "Scenes/Scene_2.hpp"
#include <list>

class Startup
{
public:
	std::list<Scene*> GetScenes()
	{
		// Starting scene is always the first item in the list
		// Example:	
		std::list<Scene*> scenes;
		scenes.push_back(new Scene_1());
		//scenes.push_back(new Scene_2());

		//AddScene(new Scene_2());
		//AddScene(new Scene_3());

		return scenes;
	}
};