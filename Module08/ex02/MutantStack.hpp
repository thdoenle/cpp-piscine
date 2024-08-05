#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <deque>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
public:

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

	MutantStack(void)
	{
		std::cout << "Default MutantStack made" << std::endl;
	}

	MutantStack(MutantStack const & src) : std::stack<T>(src)
	{
		std::cout << "Copy MutantStack made" << std::endl;
	}

	~MutantStack(void)
	{
		std::cout << "MutantStack destroyed" << std::endl;
	}

	MutantStack & operator=(MutantStack const & rhs)
	{
		std::stack<T>::operator=(rhs);
		return *this;
	}

	iterator begin(void)
	{
		return std::stack<T>::c.begin();
	}

	const_iterator begin(void) const
	{
		return std::stack<T>::c.begin();
	}

	iterator end(void)
	{
		return std::stack<T>::c.end();
	}

	const_iterator end(void) const
	{
		return std::stack<T>::c.end();
	}

	reverse_iterator rbegin(void)
	{
		return std::stack<T>::c.rbegin();
	}

	const_reverse_iterator rbegin(void) const
	{
		return std::stack<T>::c.rbegin();
	}

	reverse_iterator rend(void)
	{
		return std::stack<T>::c.rend();
	}

	const_reverse_iterator rend(void) const
	{
		return std::stack<T>::c.rend();
	}
};

#endif