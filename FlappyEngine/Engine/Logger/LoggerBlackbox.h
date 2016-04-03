#pragma once

#include "Logger_Interface.h"
#include <fstream>

class LoggerBlackbox : public Logger_Interface
{
public:
	LoggerBlackbox();
	~LoggerBlackbox();
	void Log(const std::string& message);
	std::string GetTimestamp();
private:
	const std::string filename;
	std::ofstream file;
};