#include "iter.hpp"
#include <iostream>

template<typename T>
void iter(T array[], size_t size, void (*f)(T & elem))
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
}

template<typename T> void print(T & t)
{
	std::cout << t << std::endl;
}

template<typename T> void addOne(T & t)
{
	t = t + 1;
}

int main(void)
{
	int nums[3] = {34, 2, -1};
	double decs[4] = {3.4, 0.2, -0.1, 42.42};

	iter<int>(nums, 3, &addOne<int>);
	iter<double>(decs, 4, &addOne<double>);
	iter<int>(nums, 3, &print<int>);
	iter<double>(decs, 4, &print<double>);
}