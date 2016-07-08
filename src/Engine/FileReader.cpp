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
