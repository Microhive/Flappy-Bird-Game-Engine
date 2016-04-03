#include "LoggerBlackbox.h"
#include <Windows.h>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>


LoggerBlackbox::LoggerBlackbox() : filename("Log (" + GetTimestamp() + ").txt" )
{
	//Create folder 'Logs' at root if it does not already exist
	if (CreateDirectory("Logs", NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	{
		//Folder existed or was created succesfully
		file.open(".\\Logs\\" + filename);
		if (!file.is_open())
		{
			std::cout << "ERROR: Unable to create logfile" << std::endl;
		}
	}
}


LoggerBlackbox::~LoggerBlackbox()
{
	file.close();
}

void LoggerBlackbox::Log(const std::string &message)
{
	file << GetTimestamp() << ": " << message << std::endl;
}

std::string LoggerBlackbox::GetTimestamp()
{
	time_t t = time(0);   // Get time now
	
	/* Microsoft has marked the ctime function localtime as 
	   unsafe, as it is not thread safe. To get around 
	   this, I disabled the warning */
	#pragma warning( push )
	#pragma warning( disable : 4996)
	struct tm * now = localtime(&t);
	#pragma warning( pop )

	std::stringstream ss;
	ss  << std::setfill('0')   << (now->tm_year + 1900) 
		<< '-' << std::setw(2) << (now->tm_mon + 1)
		<< '-' << std::setw(2) << (now->tm_mday)
		<< ' ' << std::setw(2) << (now->tm_hour)
		<< '-' << std::setw(2) << (now->tm_min)
		<< '-' << std::setw(2) << (now->tm_sec);

	// Timestamp format is "YYYY-MM-DD HH-mm-ss"
	return ss.str();
}