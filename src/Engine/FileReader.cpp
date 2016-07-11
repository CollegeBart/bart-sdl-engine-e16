#include "FileReader.h"



FileReader::FileReader()
{
}

FileReader::FileReader(std::string path)
	: path(path)
{
}


FileReader::~FileReader()
{
}

std::vector<std::string> FileReader::Split(std::string & data, char * token, std::vector<std::string>& elems)
{
	const char * cString = data.c_str();
	int lenght = strlen(cString);
	char * usable = new char[lenght];

	usable = strcpy(usable, cString);

	char * pch;
	pch = strtok(usable, token);

	while (pch != nullptr)
	{
		std::string data(pch);
		elems.push_back(data);
		pch = strtok(nullptr, token);
	}

	return elems;
}

void FileReader::Read(std::string& fileContent) const
{
	std::ifstream file(path);
	std::string line;

	while (std::getline(file, line))
	{
		fileContent += line;
		fileContent.push_back('\n');
	}
}
