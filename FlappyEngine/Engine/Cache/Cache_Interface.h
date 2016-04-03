#pragma once

#include <string>

class Cache_Interface
{
public:
	virtual void performSave(std::string key, std::string value) = 0;
	virtual std::string performLoad(std::string key) = 0;
};