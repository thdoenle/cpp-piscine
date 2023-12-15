#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = src.getRawBits();
}

Fixed::Fixed(const int & src) : _value(0)
{
    unsigned char       exp = 0;
    unsigned int        usrc = src;

    std::cout << "Int constructor called" << std::endl;
    if (!src)
        return;
    if (src < 0)
        usrc = ~usrc + 1;
    for (unsigned char i = 0; i < 32; i++)
    {
        if ((1 << i) & usrc)
            exp = i;
    }
    usrc &= ~(1 << exp);
    _value = (exp < 23 ? (usrc << (23 - exp)) : (usrc >> (exp - 23)));
    exp += 127;
    _value |= (exp << 23);
    if (src < 0)
        _value |= 1 << 31;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _value = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}