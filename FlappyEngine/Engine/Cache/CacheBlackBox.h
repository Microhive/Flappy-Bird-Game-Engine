#pragma once

#include "Cache_Interface.h"

class CacheBlackBox : public Cache_Interface
{
public:
	void performSave(std::string key, std::string value);
	std::string performLoad(std::string key);
private:
	//Number of data integers
	const int TOTAL_DATA = 10;
};