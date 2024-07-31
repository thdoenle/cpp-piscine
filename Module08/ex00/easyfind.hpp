#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template<typename T>
typename T::const_iterator easyfind(T const & t1, T const & t2)
{
	return search(t1.begin(), t1.end(), t2.begin(), t2.end());
}

#endif