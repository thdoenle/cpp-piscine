#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

template<typename IntContainer>
void displayIntContainer(IntContainer const & c)
{
	std::cout << "[";
	typename IntContainer::const_iterator it = c.begin();
	while (it != c.end())
	{
		std::cout << *it;
		it++;
		if (it != c.end())
			std::cout << " ; ";
		else
			std::cout << "]";
	}
	std::cout << std::endl;
}

int main(void)
{
	std::vector<int> v1;
	std::vector<int> v2;

	for (int i = 1; i <= 5; i++)
		v1.push_back(i);
	for (int i = 1; i <= 5; i++)
		v1.push_back(i);
	for (int i = 3; i <= 4; i++)
		v2.push_back(i);
	
	displayIntContainer(v1);
	displayIntContainer(v2);

	std::vector<int>::const_iterator vSub = easyfind(v1, v2);

	if (vSub == v1.end())
		std::cout << "Not found" << std::endl;
	else
	{
		for (std::vector<int>::const_iterator it = vSub; it != v1.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	std::list<int> l1;
	std::list<int> l2;

	for (int i = 1; i <= 5; i++)
		l1.push_back(i);
	for (int i = 1; i <= 5; i++)
		l1.push_back(i);
	for (int i = 2; i <= 4; i++)
		l2.push_back(i);
	
	displayIntContainer(l1);
	displayIntContainer(l2);

	std::list<int>::const_iterator lSub = easyfind(l1, l2);

	if (lSub == l1.end())
		std::cout << "Not found" << std::endl;
	else
	{
		for (std::list<int>::const_iterator it = lSub; it != l1.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}