#include "Cache.h"

Cache* Cache::_Instance = nullptr;

Cache::Cache()
{
	// Module can be switched out
	this->blackBox = new CacheBlackBox();
}

Cache* Cache::GetInstance()
{
	if (!_Instance)
		_Instance = new Cache();

	return _Instance;
}

void Cache::Save(std::string key, std::string value)
{
	return this->blackBox->performSave(key, value);
}

std::string Cache::Load(std::string key) const
{
	return this->blackBox->performLoad(key);
}