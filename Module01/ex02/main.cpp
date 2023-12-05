#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout.width(32);
	std::cout << "Address of string: " << &str << std::endl;
	std::cout.width(32);
	std::cout << "Address held by pointer: " << stringPTR << std::endl;
	std::cout.width(32);
	std::cout << "Address held by reference: " << &stringREF << std::endl;

	std::cout.width(32);
	std::cout << "Value of string: " << str << std::endl;
	std::cout.width(32);
	std::cout << "Value pointed by pointer: " << *stringPTR << std::endl;
	std::cout.width(32);
	std::cout << "Value pointed by reference: " << stringREF << std::endl;
}