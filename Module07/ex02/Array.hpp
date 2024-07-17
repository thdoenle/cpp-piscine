#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
private:

	T * _array;
	unsigned int _size;

	class OutOfBoundsException : public std::exception {
	public:
		virtual const char * what(void) const throw()
		{
			return "Error: Out of bounds";
		}
	};

public:

	Array(void)
	{
		_array = new T[0];
		_size = 0;
		std::cout << "Empty array created" << std::endl;
	}

	Array(unsigned int n)
	{
		_array = new T[n];
		_size = n;
		std::cout << "Array size " << n << " created" << std::endl;
	}

	Array(Array const & src)
	{
		_size = src.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = src[i];
		}
		std::cout << "Array size " << _size << " copied" << std::endl;
	}

	~Array(void)
	{
		delete _array;
		std::cout << "Array size " << _size << " deleted" << std::endl;
	}

	Array & operator=(Array const & rhs)
	{
		delete _array;
		_size = rhs.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = rhs[i];
		}
		std::cout << "Array size " << _size << " assigned" << std::endl;
		return *this;
	}

	T & operator[](unsigned int num) const
	{
		if (num >= _size)
			throw OutOfBoundsException();
		return _array[num];
	}

	unsigned int size(void) const
	{
		return _size;
	}
};

#endif