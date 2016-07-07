#pragma once
#include <iostream>
#include <fstream>
#include <string>


class FileReader
{
public:
	FileReader();
	FileReader(std::string path);
	~FileReader();
	std::string Read(std::string& fileContent) const;
private:
	std::string path;
};

