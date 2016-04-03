#pragma once

#include <string>

class LoggerBlackbox; // Forward declaration

class Logger
{
public:
	//Logger needs a folder named 'Logs' at root
	static Logger* GetInstance();
	~Logger();
	void Log(const std::string& message, bool printToConsole);
private:	
	Logger();

	static Logger* pLogger;
	LoggerBlackbox *logger;
};