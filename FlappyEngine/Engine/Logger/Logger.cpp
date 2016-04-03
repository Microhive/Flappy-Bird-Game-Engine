#pragma once

#include "Logger.h"
#include "LoggerBlackbox.h"
#include <iostream>

Logger* Logger::pLogger = nullptr;

Logger::Logger()
{
	logger = new LoggerBlackbox();
}

Logger::~Logger()
{
	delete logger;
}

Logger* Logger::GetInstance()
{
	if (pLogger == nullptr) {
		pLogger = new Logger();
	};

	return pLogger;
}

void Logger::Log(const std::string& message, bool printToConsole)
{
	logger->Log(message);
	if (printToConsole)
	{
		std::cout << message << std::endl;
	}
}