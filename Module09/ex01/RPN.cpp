#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const & src) : _s(src.getS()) {}

RPN::~RPN(void) {}

RPN & RPN::operator=(RPN const & rhs)
{
	_s = rhs.getS();
	return *this;
}

void error(void)
{
	std::cout << "Error" << std::endl;
}

void RPN::compute(std::string calc)
{
	std::size_t i = 0;
	int a;
	int b;

	if (calc.size() % 2 == 0)
		return error();
	while (i < calc.size())
	{
		if (std::isdigit(calc[i]))
		{
			_s.push(calc[i] - '0');
		}
		else
		{
			if (_s.size() < 2)
				return error();
			a = _s.top();
			_s.pop();
			b = _s.top();
			_s.pop();
			switch (calc[i])
			{
			case '+':
				_s.push(a + b);
				break;
			case '-':
				_s.push(b - a);
				break;
			case '*':
				_s.push(a * b);
				break;
			case '/':
				if (!a)
					return error();
				_s.push(b / a);
				break;
			default:
				return error();
			}
		}
		if (i && calc[i - 1] != ' ')
			return error();
		i += 2;
	}
	if (_s.size() != 1)
		return error();
	std::cout << _s.top() << std::endl;
}

std::stack<int> RPN::getS(void) const
{
	return _s;
}