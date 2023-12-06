#include <iostream>
#include <fstream>
#include <sstream>
#include <limits.h>

bool printError(char const msg[])
{
	std::cout << "Error" << std::endl << msg << std::endl;
	return false;
}

bool getFileContent(char const fileName[], std::string& dest)
{
	std::ifstream		file(fileName);
	std::stringstream	content;

	if (!file.is_open())
		return printError("Failed to read file.");
	content << file.rdbuf();
	dest = content.str();
	file.close();
	return true;
}

void replace(std::string& str, std::string s1, std::string s2)
{
	std::string::size_type	i = str.find(s1);

	while (i < ULONG_MAX)
	{
		str.erase(i, s1.length());
		str.insert(i, s2);
		i += s2.length();
		i = str.find(s1, i);
	}
}

bool putInOutputFile(std::string fileName, std::string const & str)
{
	fileName += ".replace";

	std::ofstream file(fileName.c_str());

	if (!file.is_open())
		return printError("Failed to write file.");
	file.clear();
	file << str;
	return true;
}

int main(int ac, char *av[])
{
	if (ac != 4)
	{
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return 0;
	}

	std::string fileContent;

	if (getFileContent(av[1], fileContent) == false)
		return 1;
	replace(fileContent, av[2], av[3]);
	if (putInOutputFile(av[1], fileContent) == false)
		return 1;
	return 0;
}