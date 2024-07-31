#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(void) : _max(0)
{
	std::cout << "Span default construction" << std::endl;
}

Span::Span(unsigned int const & N) : _max(N)
{
	std::cout << "Span parameter construction" << std::endl;
}

Span::Span(Span const & src) : _nums(src.getVector()), _max(src.getMax())
{
	std::cout << "Span copy construction" << std::endl;
}

Span::~Span(void)
{
	std::cout << "Span destruction" << std::endl;
}

Span & Span::operator=(Span const & rhs)
{
	_nums = rhs.getVector();
	_max = rhs.getMax();
	return *this;
}

void Span::addNumber(int const & num)
{
	if (_nums.size() == _max)
		throw CannotAddNumber();
	_nums.push_back(num);
}

void Span::addRange(std::vector<int>::const_iterator first,
	std::vector<int>::const_iterator last)
{
	std::vector<int> v(first, last);
	if (v.size() + _nums.size() > static_cast<size_t>(_max))
		throw CannotAddRange();
	_nums.insert(_nums.end(), first, last);
}

int Span::shortestSpan(void) const
{
	if (_nums.size() <= 1)
		throw NoSpanAvailable();
	std::vector<int> v = _nums;
	std::sort(v.begin(), v.end());
	int span = std::abs(v[0] - v[1]);
	int temp;
	for (unsigned int i = 1; i < v.size() - 1; i++)
	{
		temp = std::abs(v[i] - v[i + 1]);
		if (temp < span)
			span = temp;
	}
	return span;
}

int Span::longestSpan(void) const
{
	if (_nums.size() <= 1)
		throw NoSpanAvailable();
	return *std::max_element(_nums.begin(), _nums.end())
		- *std::min_element(_nums.begin(), _nums.end());
}

std::vector<int> const & Span::getVector(void) const
{
	return _nums;
}

unsigned int const & Span::getMax(void) const
{
	return _max;
}

const char * Span::CannotAddNumber::what(void) const throw()
{
	return "error: maximum number reached";
}

const char * Span::CannotAddRange::what(void) const throw()
{
	return "error: range is too big";
}

const char * Span::NoSpanAvailable::what(void) const throw()
{
	return "error: cannot compute span (not enough numbers)";
}