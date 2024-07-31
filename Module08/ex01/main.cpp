#include "Span.hpp"
#include <iostream>

int main(void)
{
	Span sp = Span(5);
	int tab[5] = {6, 3, 17, 9, 11};
	std::vector<int> content(tab, tab + 5);

	sp.addRange(content.begin(), content.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span bigSp(100000);
	std::vector<int> bigContent(99999, 10);

	bigSp.addRange(bigContent.begin(), bigContent.end());
	bigSp.addNumber(-10);
	try
	{
		bigSp.addNumber(0);
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << bigSp.shortestSpan() << std::endl;
	std::cout << bigSp.longestSpan() << std::endl;

	Span emptySp;

	try
	{
		emptySp.shortestSpan();
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}