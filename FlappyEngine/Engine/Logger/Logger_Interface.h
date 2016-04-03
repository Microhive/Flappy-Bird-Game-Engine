#pragma once

#include <string>

class Logger_Interface
{
public:
	virtual void Log(const std::string&) = 0;
};