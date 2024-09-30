#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>

class RPN
{
private:

	std::stack<int> _s;

public:

	RPN(void);
	RPN(RPN const & src);
	~RPN(void);
	RPN & operator=(RPN const & rhs);

	void compute(std::string calc);

	std::stack<int> getS(void) const;
};

#endif