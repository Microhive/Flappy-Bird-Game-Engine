#pragma once

#include <string>
#include "Cache_Interface.h"
#include "CacheBlackBox.h"

class Cache
{
public:
	static Cache* GetInstance();
	void Save(std::string key, std::string value);
	std::string Load(std::string key) const;
private:
	Cache();
	Cache_Interface* blackBox;
	static Cache* _Instance;

};