#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
	srand(time(NULL));
	int ran = rand() % 3;
	switch (ran)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
	return NULL;
}

void identify(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base & p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		(void)e;
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		(void)e;
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		(void)e;
	}
}

int main(void)
{
	Base * ran;
	try
	{
		ran = generate();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	identify(ran);
	identify(*ran);
	delete ran;
}