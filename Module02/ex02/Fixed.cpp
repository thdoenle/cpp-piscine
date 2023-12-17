#include <iostream>
#include <math.h>
#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(Fixed const & src) : _value(src.getRawBits()) {}

Fixed::Fixed(const int & src) : _value(src * (1 << _FRAC_BITS)) {}

Fixed::Fixed(const float & src) : _value((int)roundf(src * (1 << _FRAC_BITS)))
{}

Fixed::~Fixed(void) {}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    _value = rhs.getRawBits();
    return *this;
}

bool Fixed::operator>(Fixed const & rhs) const
{
    return _value > rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const
{
    return _value >= rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const
{
    return _value < rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const
{
    return _value <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const
{
    return _value == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const
{
    return _value != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
    Fixed x = *this;

    x.setRawBits(_value + rhs.getRawBits());
    return x;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
    Fixed x = *this;

    x.setRawBits(_value - rhs.getRawBits());
    return x;
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
    return this->toFloat() * rhs.toFloat();
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
    return this->toFloat() / rhs.toFloat();
}

Fixed & Fixed::operator++(void)
{
    _value++;
    return *this;
}

Fixed & Fixed::operator--(void)
{
    _value--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed pre = Fixed(*this);

    _value++;
    return pre;
}

Fixed Fixed::operator--(int)
{
    Fixed pre = Fixed(*this);

    _value--;
    return pre;
}

Fixed & Fixed::min(Fixed & lhs, Fixed & rhs)
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    else
        return rhs;
}

Fixed const & Fixed::min(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs.getRawBits() < rhs.getRawBits())
        return lhs;
    else
        return rhs;
}

Fixed & Fixed::max(Fixed & lhs, Fixed & rhs)
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    else
        return rhs;
}

Fixed const & Fixed::max(Fixed const & lhs, Fixed const & rhs)
{
    if (lhs.getRawBits() > rhs.getRawBits())
        return lhs;
    else
        return rhs;
}

std::ostream & operator<<(std::ostream & o, Fixed const & f)
{
    o << f.toFloat();
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

float Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _FRAC_BITS));
}

int Fixed::toInt(void) const
{
    return _value >> _FRAC_BITS;
}