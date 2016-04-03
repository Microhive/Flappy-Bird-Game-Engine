#pragma once

#include <windows.h>
#include "CacheBlackBox.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../Logger/Logger.h"

void CacheBlackBox::performSave(std::string key, std::string value)
{
	//Open file for reading in binary
	std::string path = "Assets/Cache/";
	std::fstream fs;
	CreateDirectory(path.c_str(), NULL);
	fs.open(path + key + ".txt", std::fstream::out | std::ofstream::trunc);
	fs << value;
	fs.close();
}

std::string CacheBlackBox::performLoad(std::string key)
{
	std::string value = "";
	std::string line;
	std::string path = "Assets/Cache/" + key + ".txt";

	std::ifstream myfile(path);
	if (myfile.is_open())
	{
		while (std::getline(myfile, line))
		{
			value = line;
			std::cout << line << '\n';
		}
		myfile.close();
	}
	else
	{
		//Logger* log = Logger::GetInstance();
		//log->Log("ERROR: Unable to open cache file " + key, true);
	}

	return value;
}
