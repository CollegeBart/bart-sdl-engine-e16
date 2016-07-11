#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class FileReader
{
public:
	FileReader();
	FileReader(std::string path);
	~FileReader();
	void Read(std::string& fileContent) const;
	std::vector<std::string> Split(std::string & data, char * token, std::vector<std::string>& elems);
private:
	std::string path;
};

