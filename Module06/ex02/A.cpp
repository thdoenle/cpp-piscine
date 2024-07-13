#include "A.hpp"
#include <iostream>

A::A(void)
{
	std::cout << "A created" << std::endl;
}

A::~A(void)
{
	std::cout << "A destroyed" << std::endl;
}