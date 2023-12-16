#include <iostream>
#include <math.h>
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

Fixed::Fixed(const int & src) : _value(src * (1 << _FRAC_BITS))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float & src) : _value((int)roundf(src * (1 << _FRAC_BITS)))
{
    std::cout << "Float constructor called" << std::endl;
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

std::ostream & operator<<(std::ostream & o, Fixed const & f)
{
    std::cout << f.toFloat();
    return o;
}

int Fixed::getRawBits(void) const
{
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float   Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _FRAC_BITS));
}

int     Fixed::toInt(void) const
{
    return _value / (1 << _FRAC_BITS);
}