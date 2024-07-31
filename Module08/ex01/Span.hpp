#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
private:

	std::vector<int> _nums;
	unsigned int _max;

public:

	Span(void);
	Span(unsigned int const & N);
	Span(Span const & src);
	~Span(void);
	Span & operator=(Span const & rhs);

	void addNumber(int const & num);
	void addRange(std::vector<int>::const_iterator first,
		std::vector<int>::const_iterator last);

	int shortestSpan(void) const;
	int longestSpan(void) const;

	std::vector<int> const & getVector(void) const;
	unsigned int const & getMax(void) const;

	class CannotAddNumber : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class CannotAddRange : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class NoSpanAvailable : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};
};

#endif